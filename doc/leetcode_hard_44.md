---
title: leetcode_hard_44

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_hard_44

>给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
>
>'?' 可以匹配任何单个字符。
>'*' 可以匹配任意字符串（包括空字符串）。
>两个字符串完全匹配才算匹配成功。
>
>说明:
>
>s 可能为空，且只包含从 a-z 的小写字母。
>p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
>示例 1:
>
>输入:
>s = "aa"
>p = "a"
>输出: false
>解释: "a" 无法匹配 "aa" 整个字符串。
>示例 2:
>
>输入:
>s = "aa"
>p = "*"
>输出: true
>解释: '*' 可以匹配任意字符串。

## Method 1:

需要注意的地方是：

1. $dp[0][\dots], dp[\dots][0]$  的初始化
2. $p[i] == '*'$ 时的递归条件

```C++
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length(),pl = p.length();
        bool dp[pl+1][sl+1];
        int i =0,j =0;
        for(i = 1; i <= pl;i++){
            dp[i][0] = false;
        }
      // 这里注意一下！！！
        for(i = 1;i <= pl;i++){
            if(p[i-1] == '*'){
                dp[i][0] = true;
            }else{
                break;
            }
        }
        for(j = 0;j <= sl;j++){
            dp[0][j] = false;
        }
        dp[0][0] = true;
        for(i = 1;i <= pl;i++){
            for(j = 1;j <= sl;j++){
                if(p[i-1] == '?' || p[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1] == '*'){
                  // 递归条件注意一下！！！
                    if(dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    dp[i][j] = false;
                }
                // cout << "(" << i << "," << j << "):" << dp[i][j] << endl;
            }
        }
        return dp[pl][sl];
    }
};
```





>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :44 ms, 在所有 C++ 提交中击败了70.61%的用户
>
>内存消耗 :9.8 MB, 在所有 C++ 提交中击败了88.11%的用户