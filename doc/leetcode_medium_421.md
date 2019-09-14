---
title: leetcode_medium_421

date: 2019/08/24 00:24:37
categories:
-leetcode
---

>421 . 数组中两个数的最大异或值
>
>给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。
>
>找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
>
>你能在O(n)的时间解决这个问题吗？
>
>示例:
>
>输入: [3, 10, 5, 25, 2, 8]
>
>输出: 28
>
>解释: 最大的结果是 5 ^ 25 = 28.
>



## 尝试1:

第一种永远尝试暴力解，TLE了

```c++
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for(int i = nums.size()-1;i >= 0;i--){
            for(int j = i;j >= 0;j--){
                res = max(res,nums[i]^nums[j]);
            }
        }
        return res;
    }
};
```

## 尝试2:

参考的是别人说的解法，先将数字用字典树来表示，然后寻找异或值大的时候就是尽量找不一样的分支，从最高位开始找，最后得到的最大的结果就是所求结果。

```c++
class Node{
public:
    Node* child[2];
    int val;
    Node():val(-1){
        for(auto& c: child){c = nullptr;}
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    Trie(vector<int>& nums){
        root = new Node();
        for(int& num: nums){
            insert(num);
        }
    }
    void insert(int& a){
        bitset<sizeof(int)*8> count(a);
        auto temp = root;
        for(int i = 31;i >= 0;i--){
            if(temp->child[count[i]] == nullptr){
                temp->child[count[i]] = new Node();
            }
            temp = temp->child[count[i]];
        }
    }
    int search(int& a){
        bitset<sizeof(int)*8> count(a);
        // cout<<a<<":\t"<<count.to_string()<<"\t";
        auto temp = root;
        for(int i = 31;i >= 0;i--){
            if(temp->child[1-count[i]] == nullptr){
                temp = temp->child[count[i]];
                count[i] = 0;
            }else{
                temp = temp->child[1-count[i]];
                count[i] = 1;
            }
        }
        // cout<<"\t"<<count.to_ulong()<<"\t"<<count.to_string()<<endl;
        return count.to_ulong();
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie(nums);
        int res = 0;
        for(int& num:nums){
            res = max(res,trie.search(num));
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :140 ms, 在所有 C++ 提交中击败了50.00%的用户
>
>内存消耗 :30.2 MB, 在所有 C++ 提交中击败了59.09%的用户



## 尝试3:

大佬的解法！！！没看懂，先mark一下

```c++
/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n-1, 0, n-1, 0, 30);
    }
private:
    // (ls, le) and (rs, re) are two ranges of nums, which gives max xor value to current bit;
    // bit decreases from 30 to 0, i.e., working from most significant bit on the left towards right;
    // Similar to quicksort, partition (ls, le) to two ranges (ls, j-1) and (j, le) by swapping elements
    // the range on the left with current bit = 1, and the range on right is 0; We do the same to (rs, re)
    // In order to set the current bit in the answer, i.e. val, to be 1, the left (ls, le) and right (rs,re) ranges must have subranges with opposite bit. If so, val = (val << 1) + 1; otherwise, val = val << 1.
    int helper(vector<int>& nums, int ls, int le, int rs, int re, int val, int bit) {
        if (bit == -1) return val;
        int mask = 1<<bit, j = ls, k = rs;
        for (int i = ls; i <= le; i++) 
            if (nums[i]&mask) swap(nums[i], nums[j++]);
        for (int i = rs; i <= re; i++) 
            if (nums[i]&mask) swap(nums[i], nums[k++]);
        // the left range has two subranges, the answer is max of (bit 1 subrange on the left and bit 0 subrange on the right) or (bit 0 subrange on the left and bit 1 subrange on the right)
        if (j > ls && j <= le) {
            int ans = 0;
            if (k > rs) 
                ans = helper(nums, j, le, rs, k-1, val*2+1, bit-1);
            if (k <= re) 
                ans = max(ans, helper(nums, ls, j-1, k, re, val*2+1, bit-1));
            return ans;
        }
        // the left range has only bit 0 subrange
        else if (j <= ls) {
            // check whether the right range has bit 1 subrange
            if (k > rs) 
                return helper(nums, ls, le, rs, k-1, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
        // the left range has only bit 1 subrange
        else {
            // check whether the right range has bit 0 subrange
            if (k <= re) 
                return helper(nums, ls, le, k, re, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
    }
};
```

