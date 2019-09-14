---
title: leetcode_medium_49

date: 2019/08/11 00:24:37
categories:
-leetcode
---



>给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
>
>示例:
>
>输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
>输出:
>[
>  ["ate","eat","tea"],
>  ["nat","tan"],
>  ["bat"]
>]
>说明：
>
>所有输入均为小写字母。
>不考虑答案输出的顺序。

## 尝试1:

先按照长度排序，开一个vector存已有的单词的hash_map，对每一个单词计算它的hash_map，再在已有的vector寻找是否有匹配的hash_map

超时了。。。

```c++
class Solution {
public:
    static bool comp(string a,string b){
        return a.length() < b.length();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()){
            return {};
        }
      // 存已有的hash_map
        vector<unordered_map<char,int>> vec;
      // 存结果
        vector<vector<string>> res;
      // 存单个单词的hash_map
        unordered_map<char,int> hash,sub_hash;
      // 存vec中hash_map和res中下标的对应关系
        unordered_map<int,int> pos_hash;
        sort(strs.begin(),strs.end(),comp);
        int len = strs.size(),bl = 0,i,j;
        string str;
        auto iter = hash.end();
        for(i = 0;i < len;i++){
            if(bl != strs[i].length()){
                vec.clear();
                pos_hash.clear();
                bl = strs[i].length();
            }
            // 计算单个string对应的hash
            hash.clear();
            str = strs[i];
            for(char& ch: str){
                hash[ch]++;
            }
            // 寻找是否有同等的hash
            for(j = vec.size()-1;j >= 0;j--){
                sub_hash = vec[j];
                for(iter = sub_hash.begin();iter != sub_hash.end();iter++){
                    if(hash[iter->first] != iter->second){
                        break;
                    }
                }
                if(iter == sub_hash.end()){
                    break;
                }
            }
            if(j >= 0){
                res[pos_hash[j]].push_back(str);
            }else{
                pos_hash.insert(make_pair(vec.size(),res.size()));
                vec.push_back(hash);
                res.push_back(vector<string>{str});
            }
        }
        return res;
    }
};
```

## 尝试2:

加了一个判定条件，还是超时了

## 尝试3:

看到一个思路，真的🐂🍺，把字母映射成一个质数，由欧拉定理一个数能分解且唯一分解为一组质数的幂之和，有个哥们用js实现了，太骚了

```js
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let map = {
        'a':2,'b':3,'c':5,'d':7,'e':11,'f':13,'g':17,'h':19,'i':23,'j':29,'k':31,'l':37,'m':41,
        'n':43,'o':47,'p':53,'q':59,'r':61,'s':67,'t':71,'u':73,'v':79,'w':83,'x':89,'y':97,'z':101
    }
    let resMap = {};
    let resList = [];
    for(let str of strs) {
        let m = 1;
        for(let i=0;i<str.length;i++) {
            m*=map[str[i]];
        }
        if(!resMap[m]) {resMap[m]=[];}
        resMap[m].push(str);
    }
    for(let key in resMap) {
        resList.push(resMap[key]);
    }
    return resList;
};
```

## 尝试4:

用C++实现了一下，怕溢出先用double试一下，不行了，骚断了我的腰

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> wm{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        // cout<<wm.size();
        double sum = 1.0;
        unordered_map<double,int> hash;
        vector<vector<string>> res;
        for(string& str:strs){
            sum = 1.0;
            for(char& ch:str){
                sum *= wm[ch-'a'];
            }
            if(hash.find(sum) == hash.end()){
                hash.insert(make_pair(sum,res.size()));
                res.push_back(vector<string>{str});
            }else{
                res[hash[sum]].push_back(str);
            }
        }
        return res;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :36 ms, 在所有 C++ 提交中击败了99.93%的用户
>
>内存消耗 :16.6 MB, 在所有 C++ 提交中击败了99.04%的用户



## 尝试5:

傻子给了我一种更普适性的解法，先把每个字符串都排序，然后再哈希

效果在短文本时没有质数乘积方法高，但是处理长文本感觉还是这个比较方便

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> new_strs = strs;
        for(string& str: new_strs){
            sort(str.begin(),str.end());
        }
        // for(string& str: new_strs){
        //     cout<<str<<"\t";
        // }
        unordered_map<string,int> hash;
        vector<vector<string>> res;
        string str;
        int len = strs.size();
        for(int i = 0;i < len;i++){
            str = new_strs[i];
            if(hash.find(str) != hash.end()){
                res[hash[str]].push_back(strs[i]);
            }else{
                hash.insert(make_pair(str,res.size()));
                res.push_back(vector<string>{strs[i]});
            }
        }
        return res;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :36 ms, 在所有 C++ 提交中击败了50.32%的用户
>
>内存消耗 :16.6 MB, 在所有 C++ 提交中击败了70.04%的用户