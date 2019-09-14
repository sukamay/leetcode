---
title: leetcode_hard_57

date: 2019/08/15 00:24:37
categories:
-leetcode
---


>给出一个无重叠的 ，按照区间起始端点排序的区间列表。
>
>在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
>
>示例 1:
>
>输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
>输出: [[1,5],[6,9]]
>示例 2:
>
>输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
>输出: [[1,2],[3,10],[12,16]]
>解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
>

思路：

1. 二分查找找到新区间的插入位置
2. 框定合并的左右范围
3. 合并区间

```c++
class Solution {
public:
    void print(vector<vector<int>>& vec){
        for(vector<int>& in:vec){
            cout<<"("<<in[0]<<","<<in[1]<<")"<<",";
        }
        cout<<endl;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0, r = intervals.size() - 1;
        while(l <= r){
            long mid = (l+r)/2;
            if(intervals[mid][0] == newInterval[0]){
                l = mid;
                if(intervals[mid][1] >= newInterval[1]){
                    r = l;
                }
                break;
            }else if(intervals[mid][0] < newInterval[0]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        // cout << l<<"\t"<<r;
        intervals.insert(intervals.begin()+l,newInterval);
        // print(intervals);
        int p = 0, q = intervals.size()-1;
        while(p < q && intervals[p][1] < newInterval[0]){
            p++;
        }
        while(q > p && intervals[q][0] > newInterval[1]){
            q--;
        }
        int start = p,begin = intervals[p][0],end = intervals[p][1];
        // cout<<"\t"<<p<<"\t"<<q;
        // p++;
        while(p <= q){
            if(intervals[p][0] <= end){
                begin = min(begin, intervals[p][0]);
                end = max(end, intervals[p][1]);
            }else{  
                break;
            }
            p++;
        }
        // cout<<"\t"<<p<<"\t"<<q<<endl;
        intervals.erase(intervals.begin()+start,intervals.begin()+(p-1));
        // print(intervals);
        intervals[start][0] = begin;
        intervals[start][1] = end;
        return intervals;
    }
};
```

嘻嘻

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :16 ms, 在所有 C++ 提交中击败了97.91%的用户
>
>内存消耗 :12.3 MB, 在所有 C++ 提交中击败了5.23%的用户