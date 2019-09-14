---
title: leetcode_medium_43

date: 2019/08/11 00:24:37
categories:
-leetcode
---
# leetcode_medium_43

>定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
>
>示例 1:
>
>输入: num1 = "2", num2 = "3"
>输出: "6"
>示例 2:
>
>输入: num1 = "123", num2 = "456"
>输出: "56088"
>说明：
>
>num1 和 num2 的长度小于110。
>num1 和 num2 只包含数字 0-9。
>num1 和 num2 均不以零开头，除非是数字 0 本身。
>不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

非常朴实的方法，先分别实现了高精度单位乘和高精度加

```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        string temp = "",res = "",temp_res = "";
        int l1 = num1.length() - 1;
        for(int i = l1;i >= 0;i--){
            mul(num2,num1[i],temp);
            temp.append(l1-i,'0');
            add(temp,res,temp_res);
            res = temp_res;
        }
        return res;
    }
    void mul(string& s1,char c,string& res){
        int com = 0;
        int temp = 0;
        res = s1;
        for(int i = s1.length()-1;i >= 0;i--){
            temp = (c-'0')*(s1[i]-'0') + com;
            res[i] = temp%10 + '0';
            com = temp/10;
        }
        if(com > 0){
            res.insert(res.begin(),char(com+'0'));
        }
        // cout << s1<<" mul "<<c<<" = "<<res<<endl;
    }
    void add(string& s1,string& s2,string& res){
        int i = s1.length()-1,j = s2.length()-1,flag = 0,temp = 0;
        res.clear();
        for(;i >= 0 && j >= 0;i--,j--){
            temp = (s1[i]-'0') + (s2[j]-'0') + flag;
            res.insert(res.begin(),char(temp%10 +'0'));
            flag = temp/10;
        }
        while(i >= 0){
            temp = (s1[i]-'0') + flag;
            res.insert(res.begin(),char(temp%10 + '0'));
            flag = temp/10;
            i--;
        }
        while(j >= 0){
            temp = (s2[j]-'0') + flag;
            res.insert(res.begin(),char(temp%10 + '0'));
            flag = temp/10;
            j--;
        }
        if(flag){
            res.insert(res.begin(),'1');
        }
        // cout<<s1<<" add "<<s2<<" = "<<res<<endl;
    }
};
```

>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :80 ms, 在所有 C++ 提交中击败了13.81%的用户
>
>内存消耗 :8.9 MB, 在所有 C++ 提交中击败了84.50%的用户

## 尝试2:

看到一个把两个放一起的解法（我之前是用的函数

话不多收，收下我的膝盖

```c++
class Solution {
public:
    string multiply(string num1, string num2) {
    //大神的解法---------------------------------------------------------------------------
        if (num2 == "0" || num1 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        string result (n1+n2,'0');
        int carry = 0;//进位
        for (int i = n1 - 1;i >= 0;i--) {
            for (int j = n2 - 1;j >= 0;j--) {
                int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = (temp % 10) + '0';
                result[i + j ] += (temp / 10) ;
            }
        }
        //去除开头的0
        while(result[0] == '0')
            result.erase(result.begin());
    //---------------------------------------------------------------------------------------      
        /*话不多说，请收下我的膝盖*/
        return result;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :16 ms, 在所有 C++ 提交中击败了48.23%的用户
>
>内存消耗 :8.7 MB, 在所有 C++ 提交中击败了89.11%的用户