---
sage: true
hidden: true

notshow: true
mathjax: true
title:  Leetcode_medium

date: 2019/05/11 00:24:37
categories:
- Master
---
# Leetcode_medium

## Warning

## Time recording

| order | start | end   | time |
| ----- | ----- | ----- | ---- |
| 33    | 20:27 | 21:00 |      |
| 34    | 21:01 | 21:07 |      |
|       |       |       |      |



## Question solving

### Q503：下一个最大元素 Ⅱ

>给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
>
>**示例 1:**
>
>```
>输入: [1,2,1]
>输出: [2,-1,2]
>解释: 第一个 1 的下一个更大的数是 2；
>数字 2 找不到下一个更大的数； 
>第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
>```
>
>**注意:** 输入数组的长度不会超过 10000。

解法一：

暴力解，对于每个解都循环一遍数组长度直到找到下一个大的数

解法二：

参考 ” 下一个最大元素 Ⅰ “，按数组遍历顺序，使用栈，第一个元素入栈，若之后的元素比它小，则入栈，若比它大，则栈顶元素的下一个最大的数就是当前遍历到的数，同时开个队列，存一个递增序列，遍历完毕，栈中元素为找不到的，继续处理，栈顶元素与队列元素对比，栈顶小，队列头为栈顶下一个最大的数，队列小，出队列

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty())
            return {};
        int i = 1;
        vector<int> vec(nums.size(),-1);
        stack<pair<int,int>> s;
        queue<int> q;
        s.push(pair<int,int>{nums[0],0});
        q.push(nums[0]);
        for(;i < nums.size();i++){
           while(!s.empty() && nums[i] > s.top().first){
               vec[s.top().second] = nums[i];
               s.pop();
           }
            s.push(pair<int,int>{nums[i],i});
            if(nums[i] > q.back()){
                q.push(nums[i]);
            }
        }
        while(!s.empty()){
            i = s.top().second;
            while(!q.empty() && nums[i] >= q.front()){
                q.pop();
            }
            if(!q.empty() && i >= 0 && nums[i] < q.front()){
                vec[i] = q.front();
            }
            s.pop();
        }
        return vec;
    }
};
```

