---
title: leetcode_medium_78-90

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_medium_78_90

>78. 子集
>
>给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
>
>说明：解集不能包含重复的子集。
>
>示例:
>
>输入: nums = [1,2,3]
>输出:
>[
>  [3],
>  [1],
>  [2],
>  [1,2,3],
>  [1,3],
>  [2,3],
>  [1,2],
>  []
>]

```c++
// 数组不含重复元素，包含幂集为2的长度次方个， 可用数字的二进制表示，一一对应
vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.empty())
      return {};
    vector<vector<int>> vec;
    vector<int> in_vec;
    long max = 1<<nums.size();
    long count = 0;
    int len = nums.size();
    // cout << "max " << max<<endl;
    const int bsize = len;
    while(count < max){
      in_vec.clear();
      bitset<sizeof(int)*8> s(count);
      // cout << count <<"\t"<< s.to_string() <<"\t" << s.size() << "\t" << len << "\t";
      for(int i = len - 1;i >= 0;i--){
        if(s.test(i)){
          in_vec.push_back(nums[len-1-i]);
        }
      }
      vec.push_back(in_vec);
      count++;
    }
    return vec;
}

```



>90. 子集Ⅱ
>
>给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
>
>说明：解集不能包含重复的子集。
>
>示例:
>
>输入: [1,2,2]
>输出:
>[
>  [2],
>  [1],
>  [1,2,2],
>  [2,2],
>  [1,2],
>  []
>]

 

先map找出每个数字及其个数，所求结果就是每个数字的组合

例如 [1,2,2] -> [(1,1),(2,2)] -> [[1->(0,1), 2->(0,1,2)]] (这里表示数字出现次数)

```c++
class Solution {
public:
    void sub(map<int,int>& nmap,int cur,vector<vector<int>>& res,vector<int> vec){
        auto iter = nmap.begin();
        int temp = cur;
        while(temp > 0){
            iter++;
            temp--;
        }
        if(iter == nmap.end()){
            res.push_back(vec);
            return;
        }
        for(int i = iter->second; i >= 0;i--){
            sub(nmap,cur+1,res,vec);
            vec.push_back(iter->first);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> nmap;
        int len = nums.size();
        for(int i = 0;i < len;i++){
            nmap[nums[i]]++;
        }
        vector<vector<int>> res;
        sub(nmap,0,res,vector<int>{});
        return res;
    }
};
```

