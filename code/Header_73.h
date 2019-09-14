//
//  Header_73.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/19.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_73_h
#define Header_73_h
//void setZeroes(vector<vector<int>>& matrix) {
//    if(matrix.empty())
//        return;
//    int m = matrix.size(),n = matrix[0].size(),i = 0;
//    for(;i < n;i++){
//        if(matrix[0][i] == 0)
//            break;
//    }
//    if(i != n){
//        for(i = 0;i < n;i++)
//            matrix[0][i] = 0;
//    }
//    int j = 0;
//    for(i = 1;i < m;i++){
//        for(j = 0;j < n;j++){
//            if(matrix[i][j] == 0){
//                break;
//            }
//        }
//        if(j != n){
//            for(int k = 0;k < n;k++)
//                matrix[i][k] = 0;
//            if(matrix[i-1][j] != 0){
//                for(int t = 0; t < m;t++){
//                    matrix[t][j] = 0;
//                }
//            }
//        }
//    }
//}

void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty())
        return;
    int m = matrix.size(),n = matrix[0].size(),i = 0,j = 0,temp= matrix[0][0];
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(i = 1;i < m;i++){
        if(matrix[i][0] == 0){
            for(j = 0;j < n ;j++)
                matrix[i][j] = 0;
        }
    }
    for(j = 1;j < n;j++){
        if(matrix[0][j] == 0){
            for(i = 0;i < m;i++)
                matrix[i][j] = 0;
        }
    }
    if(temp == 0){
        for(j = 1;j < n;j++)
            matrix[0][j] = 0;
        for(i = 1;i < m;i++)
            matrix[i][0] = 0;
    }
}
#endif /* Header_73_h */
