---
title: leetcode_hard_51_52

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_hard_51_52

>
>
>51. N皇后

就，暴力解

```c++
class Solution {
public:
    void sub(vector<vector<string>>& res,vector<string> vec,int n,vector<bool> col,vector<pair<int,int>> qpos){
        if(vec.size() == n){
            res.push_back(vec);
            return;
        }
        int cy = vec.size(),cx = 0,i;
        string now(n,'.');
        for(;cx < n;cx++){
            for(i = 0;i < cy;i++){
                if(abs(qpos[i].second - cy) == abs(qpos[i].first - cx)){
                    break;
                }
            }
            if(i < cy){
                continue;
            }
            if(col[cx]){
                col[cx] = false;
                now[cx] = 'Q';
                vec.push_back(now);
                qpos.push_back(make_pair(cx,cy));
                sub(res,vec,n,col,qpos);
                qpos.pop_back();
                vec.pop_back();
                now[cx] = '.';
                col[cx] = true;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> col(n,true);
        vector<pair<int,int>> qpos;
        sub(res,vector<string>{},n,col,qpos);
        return res;
    }
};
```

时间不是很理想

>时间： 44ms， 战胜 22.34% 的提交记录

改进1: 去掉冗余的col

>显示详情 
>
>执行用时 :28 ms, 在所有 C++ 提交中击败了29.22%的用户
>
>内存消耗 :19 MB, 在所有 C++ 提交中击败了20.50%的用户

```c++
class Solution {
public:
    void sub(vector<vector<string>>& res,vector<string> vec,int n,vector<pair<int,int>> qpos){
        if(vec.size() == n){
            res.push_back(vec);
            return;
        }
        int cy = vec.size(),cx = 0,i;
        string now(n,'.');
        for(;cx < n;cx++){
            for(i = 0;i < cy;i++){
                if(qpos[i].first == cx || abs(qpos[i].second - cy) == abs(qpos[i].first - cx)){
                    break;
                }
            }
            if(i < cy){
                continue;
            }
            // if(col[cx]){
                // col[cx] = false;
                now[cx] = 'Q';
                vec.push_back(now);
                qpos.push_back(make_pair(cx,cy));
                sub(res,vec,n,qpos);
                qpos.pop_back();
                vec.pop_back();
                now[cx] = '.';
                // col[cx] = true;
            // }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // vector<bool> col(n,true);
        vector<pair<int,int>> qpos;
        sub(res,vector<string>{},n,qpos);
        return res;
    }
};
```

改进2: 找到了一个很高效的解法！

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :8 ms, 在所有 C++ 提交中击败了95.74%的用户
>
>内存消耗 :10 MB, 在所有 C++ 提交中击败了82.22%的用户

[解说](https://www.cnblogs.com/ariel-dreamland/p/9143352.html)

```c++
class Solution {
private:
    vector<vector<string> > res;
    int upperlim;
public:
    vector<vector<string> > solveNQueens(int n) {
        upperlim = (1 << n) - 1;//低n位全部置1
        vector<string> cur(n, string(n, '.'));
        helper(0,0,0,cur,0);
        return res;
    }
     
    void helper(const int row, const int ld, const int rd, vector<string>&cur, const int index)
    {
        int pos, p;
        if ( row != upperlim )
        {
            pos = upperlim & (~(row | ld | rd ));//pos中二进制为1的位，表示可以在当前行的对应列放皇后
            //和upperlim与运算，主要是ld在上一层是通过左移位得到的，它的高位可能有无效的1存在，这样会清除ld高位无效的1
            while ( pos )
            {
                p = pos & (~pos + 1);//获取pos最右边的1,例如pos = 010110，则p = 000010
                pos = pos - p;//pos最右边的1清0
                setQueen(cur, index, p, 'Q');//在当前行，p中1对应的列放置皇后
                helper(row | p, (ld | p) << 1, (rd | p) >> 1, cur, index+1);//设置下一行
                setQueen(cur, index, p, '.');
            }
        }
        else//找到一个解
            res.push_back(cur);
    }
     
    //第row行，第loc1(p)列的位置放置一个queen或者清空queen，loc1(p)表示p中二进制1的位置
    void setQueen(vector<string>&cur, const int row, int p, char val)
    {
        int col = 0;
        while(!(p & 1))
        {
            p >>= 1;
            col++;
        }
        cur[row][col] = val;
    }
};
```

> 52. N皇后
>
> 输出解法个数

代码如上，改一下res

执行用时 0 ms，超过100% 用户