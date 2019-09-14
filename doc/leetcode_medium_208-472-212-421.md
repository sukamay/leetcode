---
title: leetcode_medium_208-472-211-421

date: 2019/08/17 00:24:37
categories:
-leetcode
---



# 208. 实现Trie（前缀树）

>
>
>208. 实现Trie（前缀树）
>
>实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
>
>示例:
>
>Trie trie = new Trie();
>
>trie.insert("apple");
>trie.search("apple");   // 返回 true
>trie.search("app");     // 返回 false
>trie.startsWith("app"); // 返回 true
>trie.insert("app");   
>trie.search("app");     // 返回 true
>说明:
>
>你可以假设所有的输入都是由小写字母 a-z 构成的。
>保证所有输入均为非空字符串。

特地去看了一个字典树是什么

[附个链接](https://blog.csdn.net/haolexiao/article/details/69218215)

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
            return temp->isWord;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```



>执行结果： 通过 显示详情 
>
>执行用时 :88 ms, 在所有 C++ 提交中击败了86.73%的用户
>
>内存消耗 :45 MB, 在所有 C++ 提交中击败了34.36%的用户





# 211. 添加与搜索单词-数据结构设计

>
>
>设计一个支持以下两种操作的数据结构：
>
>void addWord(word)
>bool search(word)
>search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
>
>示例:
>
>addWord("bad")
>addWord("dad")
>addWord("mad")
>search("pad") -> false
>search("bad") -> true
>search(".ad") -> true
>search("b..") -> true
>说明:
>
>你可以假设所有单词都是由小写字母 a-z 组成的。

使用字典树存储单词，遇到'.'就深搜看结果

```c++
class Node{
public:
    Node *child[26];
    bool isWord;
    Node():isWord(false){
        for(auto &c: child){c = nullptr;}
    }
};
class WordDictionary {
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *temp = root;
        for(char& ch:word){
            if(temp->child[ch-'a'] == nullptr){
                temp->child[ch-'a'] = new Node();
            }
            temp = temp->child[ch-'a'];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return sub(word,root);
    }
    bool sub(string& word,Node* root){
        Node *temp = root;
        int i = 1;
        for(char& ch: word){
            if(ch == '.'){
                // if(i == word.length()){
                //     return true;
                // }
                string str = word.substr(i);
                for(auto &t: temp->child){
                    if(t != nullptr && sub(str,t)){
                        return true;
                    }
                }
                return false;
            }else{
                if(temp->child[ch-'a'] == nullptr){
                    return false;
                }
                temp = temp->child[ch-'a'];
            }
            i++;
        }
        return temp->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```



>执行结果： 通过  显示详情 
>
>执行用时 :120 ms, 在所有 C++ 提交中击败了85.38%的用户
>
>内存消耗 :44.3 MB, 在所有 C++ 提交中击败了79.31%的用户