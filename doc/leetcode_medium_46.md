---
title: leetcode_medium_46-47

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# 46. 全排列

>46. 全排列
>
>给定一个没有重复数字的序列，返回其所有可能的全排列。
>
>示例:
>
>输入: [1,2,3]
>输出:
>[
>  [1,2,3],
>  [1,3,2],
>  [2,1,3],
>  [2,3,1],
>  [3,1,2],
>  [3,2,1]
>]

照着组数书上写的思路，保持原有相对顺序，每次将一对数字转换位置。

## 尝试1:

```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> vec;
        vector<int> temp = nums;
        sub(nums,0,vec);
        return vec;
    }
    void sub(vector<int>& nums,int k ,vector<vector<int>>& vec){
        if(k == nums.size() - 1){
            vec.push_back(nums);
            return;
        }
        for(int i = k;i < nums.size();i++){
            swap(nums[k],nums[i]);
            // vec.push_back(nums);
            sub(nums,k+1,vec);
            swap(nums[k],nums[i]);
        }
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :32 ms, 在所有 C++ 提交中击败了17.68%的用户
>
>内存消耗 :9 MB, 在所有 C++ 提交中击败了95.47%的用户

## 尝试2:

把第三个参数设成的全局变量，哦豁

```c++
class Solution {
private:
    vector<vector<int>> vec;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        // vector<int> temp = nums;
        sub(nums,0);
        return vec;
    }
    void sub(vector<int>& nums,int k){
        if(k == nums.size() - 1){
            vec.push_back(nums);
            return;
        }
        for(int i = k;i < nums.size();i++){
            swap(nums[k],nums[i]);
            // vec.push_back(nums);
            sub(nums,k+1);
            swap(nums[k],nums[i]);
        }
    }
};
```

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :16 ms, 在所有 C++ 提交中击败了87.17%的用户
>
>内存消耗 :9.4 MB, 在所有 C++ 提交中击败了54.59%的用户



# 47. 全排列2

>47. 全排列2
>
>给定一个可包含重复数字的序列，返回所有不重复的全排列。
>
>示例:
>
>输入: [1,1,2]
>输出:
>[
>  [1,1,2],
>  [1,2,1],
>  [2,1,1]
>]

```c++
class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0, nums.size() - 1);
        return ans;
    }
    
    void perm(vector<int> nums, int left, int right) {
        if (left == right)
            ans.push_back(nums);
        else {
            for (int i = left; i <= right; i++) {
                if (i != left && nums[left] == nums[i]) continue; 
                swap(nums[left], nums[i]);
                perm(nums, left + 1, right);
            }
        }
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :68 ms, 在所有 C++ 提交中击败了28.27%的用户
>
>内存消耗 :10.7 MB, 在所有 C++ 提交中击败了54.31%的用户