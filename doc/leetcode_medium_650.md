---
title: leetcode_medium_650

date: 2019/08/24 00:24:37
categories:
-leetcode
---



>650. 只有两个键的键盘
>
>最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
>
>Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
>Paste (粘贴) : 你可以粘贴你上一次复制的字符。
>给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。
>
>示例 1:
>
>输入: 3
>输出: 3
>解释:
>最初, 我们只有一个字符 'A'。
>第 1 步, 我们使用 Copy All 操作。
>第 2 步, 我们使用 Paste 操作来获得 'AA'。
>第 3 步, 我们使用 Paste 操作来获得 'AAA'。
>说明:
>
>n 的取值范围是 [1, 1000] 。
>



看看人家大佬的解法，我还是太菜了

```c++
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0 ;
        int count = 1 ,ant = 1,fuzhi = 1; // 依次代表 当前 A 串长度，复制粘贴总次数，复制串的长度 
        int flag = 1 ; // 复制之后就得粘贴，否则会死循环
        while(n!=count){
            if((n-count)%count==0 && flag == 0){
                fuzhi = count ; 
                flag = 1 ;
            }else {
                count += fuzhi ;
                flag = 0 ;
            }
            ant++ ;
           // printf("%d %d %d\n",ant,fuzhi,count) ;
        }
        return ant ; 
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
>
>内存消耗 :8.1 MB, 在所有 C++ 提交中击败了89.38%的用户