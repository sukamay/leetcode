//
//  Header_1020.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/15.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_1020_h
#define Header_1020_h

void dfs(int i ,int j,vector<vector<int>>& A){
    A[i][j] = 2;
    if(i > 0 && A[i-1][j] == 1){
        dfs(i-1,j,A);
    }
    if(i < A.size()-1 && A[i+1][j] == 1){
        dfs(i+1,j,A);
    }
    if(j > 0 && A[i][j-1] == 1){
        dfs(i,j-1,A);
    }
    if(j < A[0].size() && A[i][j+1] == 1){
        dfs(i,j+1,A);
    }
}
    int numEnclaves(vector<vector<int>>& A) {
        if(A.size() < 3 || A[0].size() < 3){return 0;}
        int i = 0,j = 0,m = A.size()-1,n = A[0].size()-1;
        for(i = 0;i <= m;i++){
            if(A[i][0] == 1){
                dfs(i,0,A);
            }
            if(A[i][n] == 1){
                dfs(i,n,A);
            }
        }
        for(j = 1;j < n;j++){
            if(A[0][j] == 1){
                dfs(0,j,A);
            }
            if(A[m][j] == 1){
                dfs(m,j,A);
            }
        }
        for(i = 0;i < A.size();i++){
            for(j = 0;j < A[0].size();j++){
                cout<<"\t"<<A[i][j];
            }
            cout<<endl;
        }
        int count = 0;
        for(i = 1;i <= m;i++){
            for(j = 1;j <= n;j++){
                if(A[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }



#endif /* Header_1020_h */
