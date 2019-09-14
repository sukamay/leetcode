---
title: leetcode_medium_227

date: 2019/08/18 00:24:37
categories:
-leetcode
---



>
>
>实现一个基本的计算器来计算一个简单的字符串表达式的值。
>
>字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
>
>示例 1:
>
>输入: "3+2*2"
>输出: 7
>示例 2:
>
>输入: " 3/2 "
>输出: 1
>示例 3:
>
>输入: " 3+5 / 2 "
>输出: 5
>说明：
>
>你可以假设所给定的表达式都是有效的。
>请不要使用内置的库函数 eval。

## 尝试1:

思路：

1. 中缀转后缀表达式
2. 计算后缀表达式

太久了。。。

```c++
class Solution {
    unordered_map<char,int> isp,icp;
public:
    Solution(){
        isp.insert(make_pair('#',0));
        isp.insert(make_pair('+',3));
        isp.insert(make_pair('-',3));
        isp.insert(make_pair('*',5));
        isp.insert(make_pair('/',5));
        icp.insert(make_pair('#',0));
        icp.insert(make_pair('+',2));
        icp.insert(make_pair('-',2));
        icp.insert(make_pair('*',4));
        icp.insert(make_pair('/',4));
    }
    int calculate(string s) {
        int res = 0;
        s.push_back('#');
        stack<char> st;
        st.push('#');
        string suffix;
        int i = 0;
        bool flag = true;
        while(!(s[i] == '#' && st.top() == '#')){
            // cout<<i<<"\t"<<s[i]<<"\t"<<st.top()<<"\t";
            switch(s[i]){
                case '+':
                case '-':
                case '*':
                case '/':
                    if(icp[s[i]] > isp[st.top()]){ 
                        // suffix.push_back('!');
                        st.push(s[i]);
                        i++;
                    }else{
                        suffix.push_back('!');
                        suffix.push_back(st.top());
                        st.pop();
                    }
                    flag = true;
                    break;
                case '#':
                    suffix.push_back('!');
                    suffix.push_back(st.top());
                    st.pop();
                    break;
                case ' ':
                    i++;
                    break;
                default:
                    if(flag){
                        suffix.push_back('!');
                        flag = false;
                    }
                    suffix.push_back(s[i]);
                    i++;
                    break;
            }
            // cout<<suffix<<endl;
            // i++;
        }
        suffix.push_back('!');
        // cout<< suffix<<endl;
        stack<int> su;
        int s = 1,len = suffix.length(),a,b;
        i = 1;
        while(i < len){
            i = suffix.find('!',s);
            string temp = suffix.substr(s,i-s);
            // cout<<s<<"\t"<<i<<"\t"<<temp<<"\t";
            i++;
            s = i;
            switch(temp[0]){
                case '+':
                    b = su.top();
                    su.pop();
                    a = su.top();
                    su.pop();
                    su.push(a+b);
                    break;
                case '-':
                    b = su.top();
                    su.pop();
                    a = su.top();
                    su.pop();
                    su.push(a-b);
                    break;
                case '*':
                    b = su.top();
                    su.pop();
                    a = su.top();
                    su.pop();
                    su.push(a*b);
                    break;
                case '/':
                    b = su.top();
                    su.pop();
                    a = su.top();
                    su.pop();
                    su.push(a/b);
                    break;
                default:
                    su.push(atoi(temp.c_str()));
                    break;
            }
            // cout<<su.top()<<endl;
        }
        return su.top();
    }
};


```



>执行结果： 通过 显示详情 
>
>执行用时 :92 ms, 在所有 C++ 提交中击败了5.29%的用户
>
>内存消耗 :12 MB, 在所有 C++ 提交中击败了14.55%的用户



## 尝试2:

修改了一下，整合了两步，快了一倍，然后还是这么慢吗？

```c++
class Solution {
    unordered_map<char,int> isp,icp;
public:
    Solution(){
        isp.insert(make_pair('#',0));
        isp.insert(make_pair('+',3));
        isp.insert(make_pair('-',3));
        isp.insert(make_pair('*',5));
        isp.insert(make_pair('/',5));
        icp.insert(make_pair('#',0));
        icp.insert(make_pair('+',2));
        icp.insert(make_pair('-',2));
        icp.insert(make_pair('*',4));
        icp.insert(make_pair('/',4));
    }
    int calculate(string s) {
        int res = 0;
        s.push_back('#');
        stack<char> st;
        stack<int> si;
        st.push('#');
        // string suffix;
        int i = 0,begin = 0,temp,a,b;
        bool flag = true;
        while(!(s[i] == '#' && st.top() == '#')){
            switch(s[i]){
                case '+':
                case '-':
                case '*':
                case '/':
                    if(begin < i){
                        temp = atoi(s.substr(begin,i-begin).c_str());
                        si.push(temp);
                        begin = i;
                    }
                   
                    if(icp[s[i]] > isp[st.top()]){
                        st.push(s[i]);
                        i++;
                    }else{
                        b = si.top();si.pop();a = si.top();si.pop();
                        if(st.top() == '+'){si.push(a+b);}
                        else if(st.top() == '-'){si.push(a-b);}
                        else if(st.top() == '*'){si.push(a*b);}
                        else{si.push(a/b);}
                        st.pop();
                    }
                    flag = true;
                    break;
                case '#':
                    if(begin < i){
                        temp = atoi(s.substr(begin,i-begin).c_str());
                        si.push(temp);
                        begin = i;
                    }
                    b = si.top();si.pop();a = si.top();si.pop();
                    if(st.top() == '+'){si.push(a+b);}
                    else if(st.top() == '-'){si.push(a-b);}
                    else if(st.top() == '*'){si.push(a*b);}
                    else{si.push(a/b);}
                    st.pop();
                    break;
                case ' ':
                    i++;
                    break;
                default:
                    if(flag){
                        begin = i;
                        flag = false;
                    }
                    i++;
                    break;
            }
        }
        if(si.empty()){
            return atoi(s.c_str());
        }
        return si.top();
    }
};
```



>执行结果： 通过   显示详情 
>
>执行用时 :48 ms, 在所有 C++ 提交中击败了10.82%的用户
>
>内存消耗 :10.6 MB, 在所有 C++ 提交中击败了50.46%的用户