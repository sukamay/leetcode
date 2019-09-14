---
title: leetcode_medium_179

date: 2019/08/17 00:24:37
categories:
-leetcode
---



>179. 最大数
>
>给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
>
>示例 1:
>
>输入: [10,2]
>输出: 210
>示例 2:
>
>输入: [3,30,34,5,9]
>输出: 9534330
>说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

更新一下比较方法就好了，中途遇到了一个非常、非常傻逼的错误，我把返回值写错了，整得我贼懵逼，愣是没找出来错，哭了，报的string的length_error的错，看来我的debug能力还不太行啊。

```c++
class Solution {
public:
    static bool comp(int a,int b){
        string i = to_string(a),j = to_string(b);
        return i+j > j+i;
    }
    string largestNumber(vector<int>& nums) {
        bool flag = true;
        int i = 0;
        for(;i < nums.size();i++){
            if(nums[i] > 0){
                flag = false;
                break;
            }
        }
        if(flag){return "0";}
        sort(nums.begin(),nums.end(),comp);
        string res;
        for(int& num: nums){
            // cout<<num<<"\t";
            res += to_string(num);
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :12 ms, 在所有 C++ 提交中击败了85.65%的用户
>
>内存消耗 :8.6 MB, 在所有 C++ 提交中击败了92.92%的用户