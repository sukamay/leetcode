---
title: leetcode_medium_5

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_medium_5

Tag:  **string**, **dynamic programming** 

>给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
>
>示例 1：
>
>输入: "babad"
>输出: "bab"
>注意: "aba" 也是一个有效答案。
>示例 2：
>
>输入: "cbbd"
>输出: "bb"

## Solve

测试用例：



### method 1: 动态规划

按照提示，将字符串分解为
$$
s(i,j) = \begin{matrix} s[i] + s(i+1,j-1) + s[j] \end{matrix}
$$
$f(i,j)$ 值意义为 $s(i,j)$ 子串是否为回文串
$$
f(i,j) = \begin{matrix} 0,s[i] != s[j]  \space || \space f(i+1,j-1) == 0 \\1,else
\end{matrix}
$$


```C++
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        int min=0, len = 0;
        string res = s.substr(0,1);
        vector<int> in(s.length(),0);
        vector<vector<int>> vec(s.length(),in);
        for(int i = s.length()-1;i >= 0; i--){
            for(int j = i; j < s.length();j++){
                if(j == i){
                    vec[i][j] = 1;
                    len = 1;
                }else if(j == i+1){
                    if(s[j] == s[i]){
                        vec[i][j] = 2;
                        len = 2;
                    }else{
                        vec[i][j] = 0;
                        len = 0;
                    }
                }else{
                    if(s[i] == s[j] && vec[i+1][j-1] > 0){
                        len = vec[i+1][j-1] + 2;
                        vec[i][j] = len;
                    }else{
                        len = 0;
                        vec[i][j] = 0;
                    }
                }
                if(len > min){
                    res = s.substr(i,j-i+1);
                    min = len;
                }
                //cout << i << "\t" << j << "\t" << vec[i][j] << endl;
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
>执行用时 :276 ms, 在所有 C++ 提交中击败了28.14%的用户
>
>内存消耗 :194 MB, 在所有 C++ 提交中击败了5.06%的用户



## method 2:  马拉车算法

时间复杂度 O（N）

[参考博客：马拉车算法](https://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Part-II.html)

```C++
class Solution {
public:
    string preProcess(string s){
        int n = s.length();
        if (n == 0)
            return "^$";
        string res = "^";
        for(int i = 0;i < n;i++){
            res += "#" + s.substr(i,1);
        }
        res += "#$";
        // cout << s << " -> " << res << endl;
        return res;
    }
    string longestPalindrome(string s) {
        string t = preProcess(s);
        int len = t.length();
        vector<int> vec(len,0);
        int c =0,r =0;
        for(int i = 1;i < len-1;i++){
            int i_mir = c + c - i;
            int diff = r - i;
            if(diff >= 0){
                if(vec[i_mir] < diff){
                    vec[i] = vec[i_mir];
                    // cout << vec[i];
                }else{
                    vec[i] = diff;
                    while(i+vec[i]+1 < len && t[i+vec[i]+1] == t[i-vec[i]-1]){
                        vec[i]++;
                    }
                    c = i;
                    r = i+vec[i];
                }
            }else{
                vec[i] = 0;
                while(i+vec[i]+1 < len && t[i+vec[i]+1] == t[i-vec[i]-1]){
                    vec[i]++;
                }
                c = i;
                r = i + vec[i];
            }
            //cout << " i: " << i << " c: " << c << " r: " << r << " p: " << vec[i] << endl;
        }
        int max = 0;
        int ind = 0;
        for(int i = 1;i < len-1;i++){
            if(vec[i] > max){
                max = vec[i];
                ind = i;
            }
        }
        return s.substr((ind-max-1)/2,max);
    }
};
```

###### COOL!


> 执行结果：
>
> 通过
>
> 显示详情 
>
> 执行用时 :16 ms, 在所有 C++ 提交中击败了97.79%的用户
>
> 内存消耗 :9.9 MB, 在所有 C++ 提交中击败了65.71%的用户