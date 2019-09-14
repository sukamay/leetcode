---
title: leetcode_medium_90

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_medium_93

>给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
>
>示例:
>
>输入: "25525511135"
>输出: ["255.255.11.135", "255.255.111.35"]

暴力深搜，居然没超时，速度感人

```c++
class Solution {
public:
    void sub(int cur,string org,vector<string>& res,string now,int dots){
        int len = org.length();
        if(cur > len){
            return;
        }else if(cur == len){
            if(dots == 4){
                now.pop_back();
                res.push_back(now);
            }
            return;
        }
        dots++;
        // 1 bit
        sub(cur+1,org,res,now+string(1,org[cur])+".",dots);
        // 2 bit
        if(org[cur] != '0'){
            sub(cur+2,org,res,now+org.substr(cur,2)+".",dots);
        }
        // 3 bit
        if(cur+3 <= len){
            string ip3 = org.substr(cur,3);
            int temp = atoi(ip3.c_str());
            if(temp > 99 && temp < 256){
                sub(cur+3,org,res,now+ip3+".",dots);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4 || s.length() > 16){
            return {};
        }
        vector<string> res;
        sub(0,s,res,"",0);
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
>执行用时 :24 ms, 在所有 C++ 提交中击败了9.76%的用户
>
>内存消耗 :18.8 MB, 在所有 C++ 提交中击败了5.16%的用户

改进1 ： 添加了剪枝的条件

```C++
class Solution {
public:
    void sub(int cur,string org,vector<string>& res,string now,int dots){
        int len = org.length();
        if(cur > len){
            return;
        }else if(cur == len){
            if(dots == 4){
                now.pop_back();
                res.push_back(now);
            }
            return;
        }
      // !!!
        int res_str = len - cur,res_dots = 4 - dots;
        if(res_str < res_dots || res_str > res_dots*3 || dots > 4){
            return;
        }
      // !!!
        dots++;
        ...
    }
    vector<string> restoreIpAddresses(string s) {
        ...
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :8 ms, 在所有 C++ 提交中击败了59.95%的用户
>
>内存消耗 :9.1 MB, 在所有 C++ 提交中击败了14.58%的用户

