//
//  Header_130.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/15.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_130_h
#define Header_130_h
void dfs(int a,int j,vector<vector<char>>& board){
    board[a][j] = 'a';
    if(a < board.size()-1 && board[a+1][j] == 'O'){
        dfs(a+1,j,board);
    }
    if(j < board[0].size()-1 && board[a][j+1] == 'O'){
        dfs(a,j+1,board);
    }
    if(a > 0 && board[a-1][j] == 'O'){
        dfs(a-1,j,board);
    }
    if(j > 0 && board[a][j-1] == 'O'){
        dfs(a,j-1,board);
    }
}

void test(int a){
    std::cout<<"a "<<a<<std::endl;
}

void solve(vector<vector<char>>& board) {
    test(0);
    if(board.size() < 3){return;}
    int len = board[0].size()-1,temp = board.size()-1,i = 0,j =0 ;
    for(i = 0;i < board.size();i++){
        if(board[i][0] == 'O'){
            dfs(i,0,board);
        }
        if(board[i][len] == 'O'){
            dfs(i,len,board);
        }
    }
    for(j = 1;j < len;j++){
        if(board[0][j] == 'O'){
            dfs(0,j,board);
        }
        if(board[temp][j] == 'O'){
            dfs(temp,j,board);
        }
    }
}



#endif /* Header_130_h */
