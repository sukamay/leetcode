---
title: leetcode_hard_32

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_hard_32

>给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
>
>示例 1:
>
>输入: "(()"
>输出: 2
>解释: 最长有效括号子串为 "()"
>示例 2:
>
>输入: ")()())"
>输出: 4
>解释: 最长有效括号子串为 "()()"

测试用例：

```
"((()))())"，"(()"，")(())))(())())"
```

# Method 1: 

思路：先用栈判断匹配的括号对，括号对所在的index存入vector，排列这个vector，合并区间，获取最长的区间

```C++
class Solution {
    static bool compare(pair<int,int> a ,pair<int,int> b){
        return a.first < b.first;
    }
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0){return 0;}
        int left = 0;
        int max = 0,temp = 0,before = 0;
        stack<int> st;
        vector<pair<int,int>> vec;
        for(int i = 0; i < len;i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty()){
                    continue;
                }else{
                    temp = st.top();
                    st.pop();
                    vec.push_back(make_pair(temp,i));
                    cout << "pair: " << temp << " , " << i << endl;
                    
                }
            }
        }
        if(vec.empty()){
            return 0;
        }
        sort(vec.begin(),vec.end(),compare);
        left = vec[0].second;
        temp = left - vec[0].first + 1;
        max = temp;
        for(int j = 1;j < vec.size();j++){
            cout << vec[j].first << "," << vec[j].second << "," << left << "\t";
            if(vec[j].first == left + 1){
                left = vec[j].second;
                temp += left - vec[j].first + 1; 
            }else if(vec[j].second < left){
                continue;
            }else{
                temp = vec[j].second - vec[j].first + 1; 
                left = vec[j].second;
            }
            if(temp > max){
                max = temp;
            }
        }
        return max;
    }
};
```

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :12 ms, 在所有 C++ 提交中击败了59.38%的用户
>
>内存消耗 :10.2 MB, 在所有 C++ 提交中击败了70.66%的用户

## Method 2:

看leetcode排行上给出的，有点厉害，之前想过这个解法，在某个点出了偏差以为不可行，啊我恨，就差一点点，之前应该是情况考虑不够周全

思路：一遍过，start记录一串新的字符串的开始，每次栈为空都记录最长的子串

```c++
class Solution {
public:
    stack<int> p;
    int longestValidParentheses(string s) {
        if(s.size()==0)
            return 0;
        int len=s.size();
        int ans=0;
        int start=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(') 
                p.push(i);
            else
            {
                if(p.size()==0)
                    start=i+1;
                 else
                 {
                     p.pop();
                     if(p.size()==0)
                         ans=max(ans,i-start+1);
                     else
                         ans=max(ans,i-p.top());
                 }
                     
            }

        }
        return ans;
    }
};
```



###### COOL!

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :4 ms, 在所有 C++ 提交中击败了98.79%的用户
>
>内存消耗 :9.3 MB, 在所有 C++ 提交中击败了92.52%的用户