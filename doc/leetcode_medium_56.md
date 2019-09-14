---
title: leetcode_medium_56

date: 2019/08/11 00:24:37
categories:
-leetcode
---



>56. 合并区间
>
>给出一个区间的集合，请合并所有重叠的区间。
>
>示例 1:
>
>输入: [[1,3],[2,6],[8,10],[15,18]]
>输出: [[1,6],[8,10],[15,18]]
>解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
>示例 2:
>
>输入: [[1,4],[4,5]]
>输出: [[1,5]]
>解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

先排列，再合并，比较边界值，需要注意的是 $[[1,4],[2,3]]$ 这种情况。

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len < 2){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int bs = intervals[0][0],be = intervals[0][1];
        bool flag = false;
        for(int i = 1;i < len;i++){
            if(intervals[i][0] > be){
                res.push_back(vector<int>{bs,be});
                bs = intervals[i][0];
                be = intervals[i][1];
            }else{
                be = max(be,intervals[i][1]);
            }
        }
        res.push_back(vector<int>{bs,be});
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
>执行用时 :24 ms, 在所有 C++ 提交中击败了91.04%的用户
>
>内存消耗 :12.3 MB, 在所有 C++ 提交中击败了5.08%的用户