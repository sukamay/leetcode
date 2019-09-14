//
//  Header_414.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/8.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_414_h
#define Header_414_h
int thirdMax(vector<int>& nums) {
    int max[3]={INT_MIN,INT_MIN,INT_MIN};
    bool flag = false;
    for(auto iter = nums.begin();iter != nums.end();iter++){
        if(*iter == max[2])
            continue;
        if(*iter > max[2]){
            max[0] = max[1];
            max[1] = max[2];
            max[2] = *iter;
        }else if(*iter > max[1] && *iter != max[2]){
            max[0] = max[1];
            max[1] = *iter;
        }else if(*iter > max[0] && *iter != max[1]){
            max[0] = *iter;
            flag = true;
        }
    }
    return nums.size() < 3 || flag == false ?max[2]:max[0];
}

#endif /* Header_414_h */
