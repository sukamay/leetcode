---
title: leetcode_medium_17

date: 2019/08/11 00:24:37
categories:
-leetcode
---

# leetcode_medium_17

>给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
>
>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
>
>示例:
>
>输入："23"
>输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
>说明:
>尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

妥妥的递归

```c++
class Solution {
private:
    vector<string> res;
public:
    void sub(string str,vector<string>& dict,vector<int>& vec,int cur){
        if(cur == vec.size()){
            res.push_back(str);
            return;
        }
        string cur_dict = dict[vec[cur]];
        for(char& ch: cur_dict){
            str.push_back(ch);
            sub(str,dict,vec,cur+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        vector<string> dict={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<int> vec;
        for(char& ch: digits){
            vec.push_back(ch-'2');
        }
        sub("",dict,vec,0);
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
>执行用时 :4 ms, 在所有 C++ 提交中击败了81.40%的用户
>
>内存消耗 :8.5 MB, 在所有 C++ 提交中击败了82.90%的用户

