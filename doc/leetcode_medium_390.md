---
title: leetcode_medium_390

date: 2019/08/24 00:24:37
categories:
-leetcode
---



>390. 消除游戏
>
>给定一个从1 到 n 排序的整数列表。
>首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。
>第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。
>我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
>返回长度为 n 的列表中，最后剩下的数字。
>
>示例：
>
>输入:
>n = 9,
>1 2 3 4 5 6 7 8 9
>2 4 6 8
>2 6
>6
>
>输出:
>6
>



参考约瑟夫环解法，每轮形成一个新的连续的映射，记录映射规则

```c++
class Solution {
public:
    int lastRemaining(int n) {
        stack<bool> st;
        bool left = true;
        while(n > 1){
            if(left || n%2 == 1){
                st.push(true);
            }else{
                st.push(false);
            }
            left = !left;
            n >>= 1;
        }
        int res = 1;
        while(!st.empty()){
            res <<= 1;
            if(st.top() == false){
                res--;
            }
            st.pop();
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :8 ms, 在所有 C++ 提交中击败了83.78%的用户
>
>内存消耗 :11 MB, 在所有 C++ 提交中击败了64.10%的用户