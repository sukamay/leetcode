---
title: leetcode_medium_318

date: 2019/08/17 00:24:37
categories:
-leetcode
---



>318. 最大单词长度乘积
>
>给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
>
>示例 1:
>
>输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
>输出: 16 
>解释: 这两个单词为 "abcw", "xtfn"。
>示例 2:
>
>输入: ["a","ab","abc","d","cd","bcd","abcd"]
>输出: 4 
>解释: 这两个单词为 "ab", "cd"。
>示例 3:
>
>输入: ["a","aa","aaa","aaaa"]
>输出: 0 
>解释: 不存在这样的两个单词。
>



## 尝试1:

只会暴力解的我，第一次超时了，卑微

```c++
class Solution {
public:
    bool hasCommon(string& a,string& b){
        set<char> hash;
        for(char& ch:a){
            hash.insert(ch);
        }
        for(char& ch:b){
            if(hash.find(ch) != hash.end()){
                return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int res = 0,len = words.size(),temp;
        for(int i = 0;i < len;i++){
            for(int j = i+1;j < len;j++){
                temp = words[i].length() * words[j].length();
                if(res >= temp){
                    continue;
                }
                if(hasCommon(words[i],words[j]) == false){
                    res = temp;
                }
            }
        }
        return res;
    }
};
```



## 尝试2:

先排序然后如果内循环加了停止条件，还是超时了，太卑微了😭🤦‍♀️

```c++
class Solution {
public:
    bool hasCommon(string& a,string& b){
        set<char> hash;
        for(char& ch:a){
            hash.insert(ch);
        }
        for(char& ch:b){
            if(hash.find(ch) != hash.end()){
                return true;
            }
        }
        return false;
    }
    static bool comp(string& a,string& b){
        return a.length() < b.length();
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int res = 0,len = words.size(),temp;
        for(int i = len-1;i >= 0;i--){
            for(int j = i-1;j >= 0;j--){
                temp = words[i].length() * words[j].length();
                if(res >= temp){
                    break;
                }
                if(hasCommon(words[i],words[j]) == false){
                    res = temp;
                }
            }
        }
        return res;
    }
};
```



## 尝试3:

先前用函数判断两个字符串是否有公共字母，现在都放在一个函数里了，能共用一个set来判断，终于过了，就是时间太感人了🤪

```c++
class Solution {
public:
    static bool comp(string& a,string& b){
        return a.length() < b.length();
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int res = 0,len = words.size(),temp;
        set<char> counts;
        bool flag = true;
        for(int i = len-1;i >= 0;i--){
            counts.clear();
            for(char& ch: words[i]){
                counts.insert(ch);
            }
            if(counts.size() >= 26){
                continue;
            }
            for(int j = i-1;j >= 0;j--){
                temp = words[i].length() * words[j].length();
                if(res >= temp){
                    break;
                }
                flag = true;
                for(char& ch: words[j]){
                    if(counts.find(ch) != counts.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res = temp;
                }
            }
        }
        return res;
    }
};
```



>执行结果：通过  显示详情 
>
>执行用时 :312 ms, 在所有 C++ 提交中击败了11.44%的用户
>
>内存消耗 :27.5 MB, 在所有 C++ 提交中击败了12.12%的用户



## 尝试5:

把set集合改成了 $vector<int> vec(26,0)$🤭

```c++
class Solution {
public:
    static bool comp(string& a,string& b){
        return a.length() < b.length();
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int res = 0,len = words.size(),temp;
        bool flag = true;
        for(int i = len-1;i >= 0;i--){
            vector<int> vec(26,0);
            for(char& ch: words[i]){
                vec[ch-'a']++;
            }
            for(int j = i-1;j >= 0;j--){
                temp = words[i].length() * words[j].length();
                if(res >= temp){
                    break;
                }
                flag = true;
                for(char& ch: words[j]){
                    if(vec[ch-'a'] > 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res = temp;
                }
            }
        }
        return res;
    }
};
```



>执行结果： 通过  显示详情 
>
>执行用时 :100 ms, 在所有 C++ 提交中击败了24.72%的用户
>
>内存消耗 :17.9 MB, 在所有 C++ 提交中击败了14.14%的用户



## 尝试6:

看一下大佬的解法：

mask是一个数，使用二进制方法存，只需要26位，每个字母对应一位，若单词中存在该字母，则该位设为1，若两个单词不存在相同字母，则或的结果为0，🐂🍺

```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        vector<int> mask(words.size(),0);
        for (int i=0;i<words.size();i++){
            for (char t : words[i]){
                mask[i] |= 1<<(t-'a');
            }
            for(int j=0;j<i;j++){
                if(!(mask[i]&mask[j]))
                    res=max(res,int(words[i].size()*words[j].size()));
            }}
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :52 ms, 在所有 C++ 提交中击败了93.36%的用户
>
>内存消耗 :13 MB, 在所有 C++ 提交中击败了84.85%的用户