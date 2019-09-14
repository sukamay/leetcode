//
//  Header_264.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/5.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_264_h
#define Header_264_h
#include <queue>


int nthUglyNumber(int n){
    if(n <= 0)
        return 0;
    vector<queue<int>> vec;
    int num[3] = {2,3,5};
    for(int i = 0;i < 3;i++){
        queue<int> a;
        a.push(1);
        vec.push_back(a);
    }
    int min = 1;
    n--;
    while(n > 0){
        min = vec[0].front()*2;
        int pos = 0;
        for(int j = 1;j < 3;j++){
            if(vec[j].front()*num[j] < min){
                pos = j;
                min = vec[j].front()*num[j];
            }
        }
        vec[pos].pop();
        for(int k = 0;k < 3;k++){
            vec[k].push(min);
        }
        n--;
    }
    return min;
}

#endif /* Header_264_h */
