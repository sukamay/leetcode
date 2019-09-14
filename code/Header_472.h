//
//  Header_472.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/16.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_472_h
#define Header_472_h
#include <vector>
#include <string>
#include <map>

using namespace std;

//trie tree

struct TrieNode{
    int num;
    map<char,TrieNode*> son;
    bool isEnd;
    char val;
    TrieNode():num(1),isEnd(false){}
    TrieNode(char c):num(1),isEnd(false),val(c){}
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string str);
    bool find(string str);
    int count(string str);
    string longestPrefix(string str);
};

void Trie::insert(string str){
    if(str.empty()){return;}
    TrieNode* node = root;
    auto iter = node->son.begin();
    for(int i = 0;i < str.length();i++){
        iter = node->son.find(str[i]);
        if(iter != node->son.end()){
            iter->second->num++;
        }else{
            node->son.insert(make_pair(str[i],new TrieNode(str[i])));
        }
        node = node->son[str[i]];
    }
    node->isEnd = true;
}

bool Trie::find(string str){
    if(str.empty()){return false;}
    TrieNode* node = root;
    auto iter = node->son.begin();
    for(int i = 0;i < str.length();i++){
        iter = node->son.find(str[i]);
        if(iter != node->son.end()){
            node = iter->second;
        }else{
            return false;
        }
    }
    return node->isEnd;
}

int Trie::count(string str){
    if(str.empty()){return -1;}
    TrieNode *node = root;
    auto iter = node->son.begin();
    for(char &c:str){
        iter = node->son.find(c);
        if(iter != node->son.end()){
            node = iter->second;
        }else{
            return 0;
        }
    }
    return node->num;
}

string Trie::longestPrefix(string str){
    if(str.empty()){return "";}
    TrieNode* node = root;
    string res="";
    auto iter = node->son.begin();
    for(char &c:str){
        iter = node->son.find(c);
        if(iter != node->son.end()){
            node = iter->second;
        }else{
            return res;
        }
        res.append(1,c);
    }
    return res;
}

bool Cmp(string& a,string& b){
    return a.length() < b.length();
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    Trie family;
    sort(words.begin(), words.end(), Cmp);
    vector<string> vec;
    string prefix = "",pre = "";
    bool flag = false;
    for(auto &str: words){
        flag = false;
        pre = "";
        string temp = str;
        prefix = family.longestPrefix(temp);
        while(prefix != "" && temp.length() > prefix.length()){
            if(pre == ""){
                pre = prefix;
            }else if(prefix != pre){
                flag = true;
            }
            temp = temp.substr(prefix.length(),temp.length()-prefix.length());
            prefix = family.longestPrefix(temp);
        }
        if(prefix == ""){
            family.insert(str);
        }else if(flag || prefix != pre){
            vec.push_back(str);
        }
//        prefix = family.longestPrefix(str);
//        if(prefix == ""){
//            family.insert(str);
//        }else{
//            pre = prefix;
//            string temp = str.substr(prefix.length(),str.length()-prefix.length());
//            prefix = family.longestPrefix(temp);
//            while(prefix != "" && temp.length() > prefix.length()){
//                if(prefix != pre){flag = true;}
//                temp = temp.substr(prefix.length(),temp.length()-prefix.length());
//                prefix = family.longestPrefix(temp);
//            }
////            while(temp.length() > prefix.length() && temp.substr(0,prefix.length()) == prefix){
////                temp = temp.substr(prefix.length(),prefix.length());
////            }
////            prefix = family.longestPrefix(temp);
//            if(prefix == ""){
//                family.insert(str);
//            }else if(flag){
//                vec.push_back(str);
//            }
//        }
    }
    return vec;
}

#endif /* Header_472_h */
