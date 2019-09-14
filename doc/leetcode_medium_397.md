---
title: leetcode_medium_397

date: 2019/08/24 00:24:37
categories:
-leetcode
---

>397. 整数替换
>
>给定一个正整数 n，你可以做如下操作：
>
>1. 如果 n 是偶数，则用 n / 2替换 n。
>2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
>n 变为 1 所需的最小替换次数是多少？
>
>示例 1:
>
>输入:
>8
>
>输出:
>3
>
>解释:
>8 -> 4 -> 2 -> 1
>示例 2:
>
>输入:
>7
>
>输出:
>4
>
>解释:
>7 -> 8 -> 4 -> 2 -> 1
>或
>7 -> 6 -> 3 -> 2 -> 1
>



## 尝试1:

暴力解。。。

```c++
class Solution {
public:
    long integerReplacement(long n) {
        if(n == 1){return 0;}
        if(n%2 == 0){
            return integerReplacement(n>>1)+1;
        }else{
            return min(integerReplacement(n+1),integerReplacement(n-1))+1;
        }
    }
};
```



>执行结果： 通过  显示详情 
>
>执行用时 :24 ms, 在所有 C++ 提交中击败了5.64%的用户
>
>内存消耗 :8.2 MB, 在所有 C++ 提交中击败了93.26%的用户