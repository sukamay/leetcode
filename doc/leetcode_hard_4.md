---
title: leetcode_hard_

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_hard_4

>给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
>
>请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
>
>你可以假设 nums1 和 nums2 不会同时为空。
>
>示例 1:
>
>nums1 = [1, 3]
>nums2 = [2]
>
>则中位数是 2.0
>示例 2:
>
>nums1 = [1, 2]
>nums2 = [3, 4]
>
>则中位数是 (2 + 3)/2 = 2.5
>

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        double res;
        int len = nums1.size();
        if(len % 2 == 0){
            len >>= 1;
            res = double(nums1[len]+nums1[len-1]) / 2;
        }else{
            len >>= 1;
            res = nums1[len];
        }
        return res;
    }
};
```

这不科学！居然都没有超时

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :32 ms, 在所有 C++ 提交中击败了47.55%的用户
>
>内存消耗 :10.1 MB, 在所有 C++ 提交中击败了78.84%的用户