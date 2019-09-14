---
title: leetcode_hard_239

date: 2019/08/18 00:24:37
categories:
-leetcode
---



>给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
>
>返回滑动窗口中的最大值。
>
> 
>
>示例:
>
>输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
>输出: [3,3,5,5,6,7] 
>解释: 
>
>  滑动窗口的位置                最大值
>---------------               -----
>[1  3  -1] -3  5  3  6  7       3
> 1 [3  -1  -3] 5  3  6  7       3
> 1  3 [-1  -3  5] 3  6  7       5
> 1  3  -1 [-3  5  3] 6  7       5
> 1  3  -1  -3 [5  3  6] 7       6
> 1  3  -1  -3  5 [3  6  7]      7
>
>
>提示：
>
>你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
>
> 
>
>进阶：
>
>你能在线性时间复杂度内解决此题吗？

## 尝试1:

暴力解

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()){return {};}
        int len = nums.size();
        vector<int> res;
        int a;
        for(int i = 0;i+k <= len;i++){
            a = nums[i];
            for(int j = 1;j < k;j++){
                a = max(a,nums[i+j]);
            }
            res.push_back(a);
        }
        return res;
    }
};
```



>执行结果： 通过  显示详情 
>
>执行用时 :348 ms, 在所有 C++ 提交中击败了5.11%的用户
>
>内存消耗 :12.6 MB, 在所有 C++ 提交中击败了98.93%的用户