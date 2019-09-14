---
title: leetcode_medium_48

date: 2019/08/11 00:24:37
categories:
-leetcode
---



>48. ​	旋转图像
>
>给定一个 n × n 的二维矩阵表示一个图像。
>
>将图像顺时针旋转 90 度。
>
>说明：
>
>你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
>
>示例 1:
>
>给定 matrix = 
>[
>  [1,2,3],
>  [4,5,6],
>  [7,8,9]
>],
>
>原地旋转输入矩阵，使其变为:
>[
>  [7,4,1],
>  [8,5,2],
>  [9,6,3]
>]



## 尝试1：

就不听题目劝告，开了新数组，准备超内存了，结果没有。。。。

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        vector<vector<int>> res;
        vector<int> line(len);
        for(int i = 0;i < len;i++){
            for(int j = 0;j < len;j++){
                line[len-j-1] = matrix[j][i];
            }
            res.push_back(line);
        }
        matrix = res;
    }
};
```



>
>
>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :12 ms, 在所有 C++ 提交中击败了36.94%的用户
>
>内存消耗 :9.1 MB, 在所有 C++ 提交中击败了55.22%的用户

## 尝试2:

算了，还是试试就地改改吧

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size(),hl = len>>1,temp,hl2 = hl;
        if(len % 2 != 0){
            hl2++;
        }
        for(int i = 0;i < hl;i++){
            for(int j = 0;j < hl2;j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[len-1-j][i];
                matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
                matrix[j][len-1-i] = temp;
            }
        }
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :8 ms, 在所有 C++ 提交中击败了76.90%的用户
>
>内存消耗 :8.8 MB, 在所有 C++ 提交中击败了95.86%的用户