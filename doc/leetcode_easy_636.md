---
title: leetcode_easy_636

date: 2019/08/11 00:24:37
categories:
-leetcode
---

>636. 平方数之和
>
>给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
>
>示例1:
>
>输入: 5
>输出: True
>解释: 1 * 1 + 2 * 2 = 5
>
>
>示例2:
>
>输入: 3
>输出: False
>

## 尝试1:

永远只会暴力解的我。。就一个个试呗，用个set存一下之前的结果，跟两数之和用hashmap的解法差不多

```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        set<long> sum;
        long i = 0,count = 0;
        while(i <= c){
            if(sum.find(i) != sum.end()){
                return true;
            }else if(i<<1 == c){
                return true;
            }
            else{
                sum.insert(c-i);
            }
            count++;
            i = count*count;
        }
        return false;
    }
};
```

效率感人啊...

>执行用时 :4 ms, 在所有 C++ 提交中击败了5.31%的用户
>
>内存消耗 :8.1 MB, 在所有 C++ 提交中击败了10.75%的用户

## 尝试2:

看了别人的解法，原来还能二分解，见识了，应该跟两数之和的双指针法差异不大，而且本体只需要判断是否存在，不需要找出全部的

```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0;
        long long int j=sqrt(c)+1;
        while(i<=j)
        {
           long long int temp=i*i+j*j;
            if(temp==c)
            {
                return 1;
            }
            else if(temp>c){
                j--;
            }
            else{
                i++;
            }
        }
        return 0;
        
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :4 ms, 在所有 C++ 提交中击败了94.31%的用户
>
>内存消耗 :8.1 MB, 在所有 C++ 提交中击败了78.75%的用户