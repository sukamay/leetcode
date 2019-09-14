//
//  Header_64.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/19.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_64_h
#define Header_64_h
int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty())
        return 0;
    // cout<<"grid size"<<grid.size()<<"grid 0: "<<grid[0].size();
    int m = grid.size(),n = grid[0].size();
    int count = 1,up = 0;
    up = m+n;
    while(count <= up){
        int j = 0;
        for(int i = 0;i <= count && i < m;i++){
            j = count - i;
            if(j < n){
                if(i > 0 && j > 0){
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                }else if(i > 0){
                    grid[i][j] += grid[i-1][j];
                }else{
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        count++;
    }
    return grid.back().back();
}

#endif /* Header_64_h */
