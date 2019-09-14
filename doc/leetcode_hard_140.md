---
title: leetcode_hard_140

date: 2019/08/18 00:24:37
categories:
-leetcode
---



>给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
>
>说明：
>
>分隔时可以重复使用字典中的单词。
>你可以假设字典中没有重复的单词。
>示例 1：
>
>输入:
>s = "catsanddog"
>wordDict = ["cat", "cats", "and", "sand", "dog"]
>输出:
>[
>  "cats and dog",
>  "cat sand dog"
>]
>示例 2：
>
>输入:
>s = "pineapplepenapple"
>wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
>输出:
>[
>  "pine apple pen apple",
>  "pineapple pen apple",
>  "pine applepen apple"
>]

## 尝试1:

1. 字典树存单词
2. 对于给定的单词，startsWith会给出所有在字典树中存在的单词的序号，即寻找当前单词在字典树中的前缀
3. dfs

超时了。。。，卡在了一个用例，存在很多重复的非常相似的单词，因此有很多重复计算的部分

```c++
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```



```c++
class Node{
public:
    Node* child[26];
    bool isWord;
    // vector<int> vec;
    Node():isWord(false){
        for(auto& c: child){c = nullptr;}
        // vec.clear();
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    vector<int> startsWith(string prefix) {
        Node *temp = root;
        vector<int> res;
        int i = 0;
        for(char& ch: prefix){
            temp = temp->child[ch-'a'];
            if(!temp){return res;}
            if(temp->isWord){res.push_back(i);}
            i++;
        }
        return res;
    }
};

class Solution {
    vector<string> res;
    Trie trie;
public:
    void print(vector<int>& vec){
        for(int& a:vec){cout<<a<<"\t";}
        cout<<endl;
    }
    void sub(string& s,int cur,string words){
        // cout<<cur<<"\t"<<words<<endl;
        if(cur == s.length()){
            words.pop_back();
            res.push_back(words);
            return;
        }
        auto pos = trie.startsWith(s.substr(cur));
        if(pos.empty()){return;}
        // cout<<"\t pos: ";
        // print(pos);
        for(int&p: pos){
            sub(s,cur+p+1,words+s.substr(cur,p+1)+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word: wordDict){trie.insert(word);}
        sub(s,0,"");
        return res;
    }
};
```



## 尝试2:

看了别人的思路，先dp求出是否有解，如果有解再dfs求，过了

```c++
class Node{
public:
    Node* child[26];
    bool isWord;
    // vector<int> vec;
    Node():isWord(false){
        for(auto& c: child){c = nullptr;}
        // vec.clear();
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    vector<int> startsWith(string prefix) {
        Node *temp = root;
        vector<int> res;
        int i = 0;
        for(char& ch: prefix){
            temp = temp->child[ch-'a'];
            if(!temp){return res;}
            if(temp->isWord){res.push_back(i);}
            i++;
        }
        return res;
    }
    
    bool search(string word){
        Node *temp = root;
        for(char& ch: word){
            temp = temp->child[ch-'a'];
            if(!temp){return false;}
        }
        return temp->isWord;
    }
};

class Solution {
    vector<string> res;
    Trie trie;
public:
    void print(vector<int>& vec){
        for(int& a:vec){cout<<a<<"\t";}
        cout<<endl;
    }
    void sub(string& s,int cur,string words){
        // cout<<cur<<"\t"<<words<<endl;
        if(cur == s.length()){
            words.pop_back();
            res.push_back(words);
            return;
        }
        auto pos = trie.startsWith(s.substr(cur));
        if(pos.empty()){return;}
        // cout<<"\t pos: ";
        // print(pos);
        for(int&p: pos){
            sub(s,cur+p+1,words+s.substr(cur,p+1)+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word: wordDict){trie.insert(word);}
        int len = s.length();
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for(int i = 1;i <= len;i++){
            for(int j = 0;j < i;j++){
                if(dp[j] && trie.search(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        if(dp[len] == false){return {};}
        sub(s,0,"");
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :20 ms, 在所有 C++ 提交中击败了85.70%的用户
>
>内存消耗 :24 MB, 在所有 C++ 提交中击败了5.33%的用户