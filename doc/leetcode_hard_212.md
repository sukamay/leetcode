---
title: leetcode_hard_212

date: 2019/08/25 00:24:37
categories:
-leetcode
---



>212 . 单词搜索II
>
>给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
>
>单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
>
>示例:
>
>输入: 
>words = ["oath","pea","eat","rain"] and board =
>[
>  ['o','a','a','n'],
>  ['e','t','a','e'],
>  ['i','h','k','r'],
>  ['i','f','l','v']
>]
>
>输出: ["eat","oath"]
>说明:
>你可以假设所有输入都由小写字母 a-z 组成。
>
>提示:
>
>你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
>如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
>



## 尝试1:

照着提示的思路走的，先用前缀树把所有单词都存下来，然后深搜整个board，如果当前的路径不形成任何前缀，则停止往下搜。过了就是速度太感人了。

```c++
class Node{
public:
    Node* child[26];
    bool isWord;
    Node():isWord(false){
        for(auto& c: child){c = nullptr;}
    }
};
class Trie {
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(char& ch: word){
            if(temp->child[ch-'a'] == nullptr){
                temp->child[ch-'a'] = new Node();
            }
            temp = temp->child[ch-'a'];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(char& ch: word){
            temp = temp->child[ch-'a'];
            if(!temp){return false;}
        }
        if(temp){
            if(temp->isWord){
                temp->isWord = false;
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for(char& ch: prefix){
            temp = temp->child[ch-'a'];
            if(!temp){return false;}
        }
        if(temp){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    Trie trie;
    vector<string> res;
    void dfs(vector<vector<char>>& board,set<pair<int,int>>& path,pair<int,int>& last,string& cur){
        if(trie.startsWith(cur) == false){
            return;
        }
        if(trie.search(cur)){
            res.push_back(cur);
        }
        int cx,cy,w = board.size(),h = board[0].size();
        for(int i = -1;i <= 1;i+=2){
            // plus (i,0)
            auto next = make_pair(last.first+i,last.second);
            if(next.first >= 0 && next.second >= 0 
               && next.first < w && next.second < h){
                if(path.find(next) == path.end()){
                    path.insert(next);
                    cur.push_back(board[next.first][next.second]);
                    dfs(board,path,next,cur);
                    cur.pop_back();
                    path.erase(next);
                }
            }
            // plus (0,i)
            next = make_pair(last.first,last.second+i);
            if(next.first >= 0 && next.second >= 0 && next.first < w && next.second < h){
                if(path.find(next) == path.end()){
                    path.insert(next);
                    cur.push_back(board[next.first][next.second]);
                    dfs(board,path,next,cur);
                    cur.pop_back();
                    path.erase(next);
                }
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string& word: words){
            trie.insert(word);
        }
        int w = board.size();
        if(w == 0){
            return {};
        }
        int h = board[0].size();
        set<pair<int,int>> path;
        pair<int,int> last;
        string cur;
        for(int i = 0;i < w;i++){
            for(int j = 0;j < h;j++){
                cur.push_back(board[i][j]);
                if(!trie.startsWith(cur)){
                    cur.pop_back();
                    continue;
                }
                last = make_pair(i,j);
                path.clear();
                path.insert(last);
                dfs(board,path,last,cur);
                cur.pop_back();
            }
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :592 ms, 在所有 C++ 提交中击败了14.43%的用户
>
>内存消耗 :85.5 MB, 在所有 C++ 提交中击败了19.68%的用户