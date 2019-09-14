---
title: leetcode_medium_386

date: 2019/08/24 00:24:37
categories:
-leetcode
---

>386. 字典序排数
>
>给定一个整数 n, 返回从 1 到 n 的字典顺序。
>
>例如，
>
>给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
>
>请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
>



## 尝试1:

用栈实现

```c++
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n < 1){return {};}
        stack<pair<int,int>> st;
        vector<int> res;
        st.push(make_pair(1,true));
        res.push_back(1);
        while(!st.empty()){
            if(st.top().second){
                st.top().second = false;
                if(st.top().first*10 <= n){
                    // cout<<st.top().first*10<<"\t";
                    res.push_back(st.top().first*10);
                    st.push(make_pair(st.top().first*10,true));
                    continue;
                }
            }
            if(st.top().first%10 < 9 && st.top().first+1 <= n){
                st.top().first++;
                st.top().second = true;
                res.push_back(st.top().first);
                // cout<<st.top().first<<"\t";
            }else{
                st.pop();
            }
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :184 ms, 在所有 C++ 提交中击败了34.66%的用户
>
>内存消耗 :11.7 MB, 在所有 C++ 提交中击败了68.83%的用户



## 尝试2:

修改了一个小地方，快了一点点

```c++
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n < 1){return {};}
        stack<pair<int,int>> st;
        vector<int> res;
        st.push(make_pair(1,true));
        res.push_back(1);
        while(!st.empty()){
            if(st.top().second){
                st.top().second = false;
                if(st.top().first*10 <= n){
                    // cout<<st.top().first*10<<"\t";
                    res.push_back(st.top().first*10);
                    st.push(make_pair(st.top().first*10,true));
                    // continue;
                }else{
                    int cur = st.top().first+1;
                    while(cur%10 && cur <= n){
                        res.push_back(cur);
                        cur++;
                    }
                    st.pop();
                }
            }else{
                 if(st.top().first%10 < 9 && st.top().first+1 <= n){
                    st.top().first++;
                    st.top().second = true;
                    res.push_back(st.top().first);
                    // cout<<st.top().first<<"\t";
                }else{
                    st.pop();
                }
            }
        }
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :176 ms, 在所有 C++ 提交中击败了38.35%的用户
>
>内存消耗 :11.7 MB, 在所有 C++ 提交中击败了68.83%的用户



## 尝试3:

递归

```c++
class Solution {
public:
    vector<int> res;
    void sub(int& n,int cur){
        res.push_back(cur);
        if(cur*10 <= n){
            sub(n,cur*10);
        }
        cur++;
        if(cur%10 > 0 && cur <= n){
            sub(n,cur);
        }
    }
    vector<int> lexicalOrder(int n) {
        if(n < 1){return {};}
        sub(n,1);
        return res;
    }
};
```



>执行结果： 通过 显示详情 
>
>执行用时 :104 ms, 在所有 C++ 提交中击败了91.48%的用户
>
>内存消耗 :12.9 MB, 在所有 C++ 提交中击败了22.08%的用户