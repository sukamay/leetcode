---
title: leetcode_medium_213

date: 2019/08/18 00:24:37
categories:
-leetcode
---



>你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
>
>给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
>
>示例 1:
>
>输入: [2,3,2]
>输出: 3
>解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
>示例 2:
>
>输入: [1,2,3,1]
>输出: 4
>解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
>     偷窃到的最高金额 = 1 + 3 = 4 。
>

动归，但是由于前后是围成一圈的，分了两种情况，偷/不偷第一家

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }else if(len < 3){
            int res = 0;
            for(int& num: nums){
                res = max(num,res);
            }
            return res;
        }
        vector<int> dp(len,0);
        // [0,len)
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        len--;
        for(int i = 2;i < len;i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        int res = dp[len-1];
        // (0,len]
        dp[1] = nums[1];
        dp[2] = max(dp[1],nums[2]);
        len++;
        for(int i = 3;i < len;i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        res = max(res, dp[len-1]);
        return res;
    }
};
```



>执行结果： 通过   显示详情 
>
>执行用时 :4 ms, 在所有 C++ 提交中击败了80.73%的用户
>
>内存消耗 :8.6 MB, 在所有 C++ 提交中击败了81.34%的用户