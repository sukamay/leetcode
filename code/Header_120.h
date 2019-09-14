//
//  Header_120.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_120_h
#define Header_120_h
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size() == 0){
        return 0;
    }
    vector<int> vec(triangle.size(),0);
    vec[0] = 0;
//    vec[0] = triangle[0][0];
    for(int i = 0;i < triangle.size();i++){
        if(i > 0){
            vec[i] = vec[i-1] + triangle[i][i];
        }
        for(int j = i-1;j > 0;j--){
            vec[j] = min(vec[j-1],vec[j]) + triangle[i][j];
        }
        vec[0] += triangle[i][0];
    }
    int sum = INT_MAX;
    for(auto iter = vec.begin();iter != vec.end();iter++){
        if(*iter < sum){
            sum = *iter;
        }
    }
    return sum;
}
#endif /* Header_120_h */
