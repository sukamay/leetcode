---
title: leetcode_medium_15-16-18-454-40

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_medium_15_16_18_454_40

## 15 三数之和

>15. 三数之和
>
>给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
>
>注意：答案中不可以包含重复的三元组。
>
>例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
>
>满足要求的三元组集合为：
>[
>  [-1, 0, 1],
>  [-1, -1, 2]
>]

### 尝试1:

固定一个+用map解双指针，这里为了避免重复我先用hashmap过了一边数组，得到了一个不含重复数字的数组，超时了，扎心了，卡在倒数第二个测试例子了

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> hash,hash_in;
        vector<vector<int>> res;
        int len = 0;
        for(int& num: nums){
            hash[num]++;
        }
        for(auto iter = hash.begin();iter != hash.end();iter++,len++){
            nums[len] = iter->first;
        }
        long target = 0;
        int temp;
        // for(int i = 0;i < len;i++){
        //     cout << nums[i] << "\t";
        // }
        // cout << endl;
        for(int i = 0;i < len;i++){
            target = -nums[i];
            hash_in.clear();
            for(int j = i+1;j < len;j++){
                temp = target - nums[j];
                if(hash_in[temp] > 0){
                    res.push_back(vector<int>{nums[i],nums[j],temp});
                    // cout<<i<<"\t"<<j<<"\t"<<nums[i]<<"\t"<<nums[j]<<"\t"<<temp<<endl;
                }else{
                    hash_in[nums[j]] = 1;
                }
            }
            temp = -(nums[i]>>1);
            if(nums[i] != 0 && nums[i]%2 == 0 && hash[temp] > 1){
                res.push_back(vector<int>{nums[i],temp,temp});
                // cout<<i<<"\t"<<nums[i]<<"\t"<<temp<<"\t"<<temp<<endl;
            }
        }
        if(hash[0] > 2){
            res.push_back(vector<int>{0,0,0});
        }
        return res;
    }
};
```

### 尝试2:

原来是把map先过一遍放在数组里，这次是直接遍历map，感觉应该会快一点，但是还是超时了，哭了

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> hash,hash_in;
        vector<vector<int>> res;
        int len = 0;
        for(int& num: nums){
            hash[num]++;
        }
        // for(auto iter = hash.begin();iter != hash.end();iter++,len++){
        //     // nums[len] = iter->first;
        //     cout<<iter->first<<"\t";
        // }
        // auto i1 = hash.begin(),i2 = i1;
        // cout << i1->first << "\t";
        // i2++;
        // cout << i1->first << "\t" << i2->first;
        long target = 0;
        int temp;
        // for(int i = 0;i < len;i++){
        //     cout << nums[i] << "\t";
        // }
        // cout << endl;
        for(auto i = hash.begin();i != hash.end();i++){
            target = -(i->first);
            hash_in.clear();
            // cout<<endl<<i->first<<"\t";
            auto j = i;
            j++;
            for(;j != hash.end();j++){
                // cout << "\t j : "<<j->first;
                temp = target - (j->first);
                if(hash_in[temp] > 0){
                    res.push_back(vector<int>{i->first,j->first,temp});
                    // cout<<endl<<"res1: "<<"\t"<<i->first<<"\t"<<j->first<<"\t"<<temp<<endl;
                }else{
                    hash_in[j->first] = 1;
                }
            }
            temp = target>>1;
            // cout << "\t temp: "<<temp <<"\t" << hash[temp];
            // cout << hash[temp];
            if(hash.find(temp) == hash.end()){
                // cout<<"\t temp yes: "<<temp;
            }else{
                // cout<<"\t temp no: "<<temp;
                if(i->first != 0 && i->first%2 == 0 && hash[temp] > 1){
                    res.push_back(vector<int>{i->first,temp,temp});
                    // cout<<endl<<"res2: \t"<<i->first<<"\t"<<temp<<"\t"<<temp<<endl;
                }
            }
           
        }
        if(hash[0] > 2){
            res.push_back(vector<int>{0,0,0});
        }
        return res;
    }
};
```

### 尝试3:

我太难了呜呜，看的别人的思路，固定一个+双指针，终于成功了，我爆哭

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        int target,l,r,temp,before;
        for(int i = 0;i < len;i++){
            if(nums[i] > 0){
                break;
            }
            if((i>0 && nums[i] == nums[i-1])){
                continue;
            }
            // cout<<i<<"\t"<<nums[i];
            // target = -nums[i];
            l = i + 1;
            r = len-1;
            while(l < r){
                temp = nums[l]+nums[r]+nums[i];
                if(temp == 0){
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    before = nums[l];
                    while(l < r && nums[l] == before){
                        l++;
                    }
                    before = nums[r];
                    while(l < r && nums[r] == before){
                        r--;
                    }
                }else if(temp < 0){
                    before = nums[l];
                    while(l < r && nums[l] == before){
                        l++;
                    }
                }else{
                    before = nums[r];
                    while(l < r && nums[r] == before){
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :148 ms, 在所有 C++ 提交中击败了75.51%的用户
>
>内存消耗 :14.6 MB, 在所有 C++ 提交中击败了86.70%的用户

## 16 最接近的三数之和

>给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
>
>例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
>
>与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

沿袭上题思路，修改一下，和target比较，尽量让和向target靠近，排序+固定一个+双指针

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int l,r,before;
        long res = nums[0]+nums[1]+nums[2],temp;
        for(int i = 0;i < len;i++){
            if((i>0 && nums[i] == nums[i-1])){
                continue;
            }
            // cout<<"\n i: "<<i<<"\t"<<nums[i]<<endl<<"temp: ";
            // target = -nums[i];
            l = i + 1;
            r = len-1;
            while(l < r){
                temp = nums[l]+nums[r]+nums[i];
                if(abs(temp-target) < abs(res-target)){
                    res = temp;
                    // cout << "\t res: "<<res<<"\t";
                }
                // cout<<temp<<"\t";
                // res = min(res,temp);
                if(temp == target){
                    return temp;
                }else if(temp < target){
                    before = nums[l];
                    while(l < r && nums[l] == before){
                        l++;
                    }
                }else{
                    before = nums[r];
                    while(l < r && nums[r] == before){
                        r--;
                    }
                }
            }
        }
        return res;

    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :12 ms, 在所有 C++ 提交中击败了81.82%的用户
>
>内存消耗 :8.5 MB, 在所有 C++ 提交中击败了98.12%的用户

## 18 四数之和

>给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
>
>注意：
>
>答案中不可以包含重复的四元组。
>
>示例：
>
>给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
>
>满足要求的四元组集合为：
>[
>  [-1,  0, 0, 1],
>  [-2, -1, 1, 2],
>  [-2,  0, 0, 2]
>]

### 尝试 1:

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        int l,r,temp,before;
        for(int i = 0;i < len;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1;j < len;j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                l = j+1;
                r = len - 1;
                while(l < r){
                    temp = nums[l]+nums[r]+nums[i]+nums[j];
                    if(temp == target){
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        before = nums[l];
                        while(l < r && nums[l] == before){
                            l++;
                        }
                        before = nums[r];
                        while(l < r && nums[r] == before){
                            r--;
                        }
                    }else if(temp < target){
                        before = nums[l];
                        while(l < r && nums[l] == before){
                            l++;
                        }
                    }else{
                        before = nums[r];
                        while(l < r && nums[r] == before){
                            r--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
```

空间复杂度为 O（1），这个时间我不服啊，打算减一下枝

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :128 ms, 在所有 C++ 提交中击败了11.84%的用户
>
>内存消耗 :9 MB, 在所有 C++ 提交中击败了92.85%的用户

### 尝试2:

效果显著！从当前可预判的最大值和最小值来判断是否继续往下运算。

```c++
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > res;
        int size = nums.size();
        if (size<4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-3; i++)
        {
            if (i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
          //!!!
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            {
                break;
            }
            if (nums[i] + nums[size-3] + nums[size-2] + nums[size-1] < target)
            {
                continue;
            }
          //!!!
            for (int j=i+1; j<size-2; j++)
            {
                if (j>i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }
              // !!!
                if (nums[i] + nums[j] + nums[size-2] + nums[size-1] < target)
                {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                {
                    break;
                }
              //!!!
                int k = j+1;
                int m = size-1;
                while(k<m)
                {
                    int sum = nums[i] + nums[j] +nums[k] + nums[m];
                    if (sum<target)
                    {
                        k++;
                    }
                    else if (sum>target)
                    {
                        m--;
                    }
                    else
                    {
                        res.push_back(vector<int> {nums[i], nums[j], nums[k], nums[m]});
                        do{k++;} while(nums[k] == nums[k-1] && k<m);
                        do{m--;} while(nums[m] == nums[m+1] && k<m);
                    }
                }
            }
        }
        return res;
    }
};
```

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :16 ms, 在所有 C++ 提交中击败了97.57%的用户
>
>内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户

## 454 四数相加2

>给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
>
>为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
>
>例如:
>
>输入:
>A = [ 1, 2]
>B = [-2,-1]
>C = [-1, 2]
>D = [ 0, 2]
>
>输出:
>2
>
>解释:
>两个元组如下:
>1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
>2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
>

先用哈希表存两个数组任意和的个数，剩余两个数组循环遍历，结果加和

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res =0 ,len = A.size();
        unordered_map<int,int> hash;
        for(int i = 0;i < len;i++){
            for(int j = 0;j < len;j++){
                hash[A[i]+B[j]]++;
            }
        }
        long target;
        for(int i =0;i < len;i++){
            for(int j = 0;j < len;j++){
                target = -(C[i] + D[j]);
                res += hash[target];
            }
        }
        return res;
    }
};
```

>执行用时 :368 ms, 在所有 C++ 提交中击败了67.08%的用户
>
>内存消耗 :47.6 MB, 在所有 C++ 提交中击败了30.84%的用户

## 40 组合总和2

>给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
>
>candidates 中的每个数字在每个组合中只能使用一次。
>
>说明：
>
>所有数字（包括目标数）都是正整数。
>解集不能包含重复的组合。 
>示例 1:
>
>输入: candidates = [10,1,2,7,6,1,5], target = 8,
>所求解集为:
>[
>  [1, 7],
>  [1, 2, 5],
>  [2, 6],
>  [1, 1, 6]
>]
>示例 2:
>
>输入: candidates = [2,5,2,1,2], target = 5,
>所求解集为:
>[
>  [1,2,2],
>  [5]
>]
>

先数组用hash存，之后对每个数组取 0 - 它的次数 ，递归

```c++
class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int,int> hash;
public:
    void sub(vector<int> path,unordered_map<int,int>::iterator iter,int cur,int& target){
        if(cur == target){
            res.push_back(path);
            return;
        }else if(cur > target){
            return;
        }
        if(iter == hash.end()){
            return;
        }
        // cout<<"in";
        int len = iter->second,now = iter->first;
        iter++;
        for(int i = 0;i <= len;i++){
          //!!!
            if(cur > target){
                break;
            }
          //!!!
            sub(path,iter,cur,target);
            cur += now;
            path.push_back(now);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // unordered_map<int,int> hash;
        for(int& candi: candidates){
            hash[candi]++;
        }
        vector<int> path;
        sub(path,hash.begin(),0,target);
        return res;
    }
};
```

原先：

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :140 ms, 在所有 C++ 提交中击败了10.93%的用户
>
>内存消耗 :22.4 MB, 在所有 C++ 提交中击败了12.72%的用户

减了一下枝，在sub的循环部分加了比较条件之后

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :48 ms, 在所有 C++ 提交中击败了28.93%的用户
>
>内存消耗 :14.9 MB, 在所有 C++ 提交中击败了36.78%的用户