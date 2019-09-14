//
//  Header_35.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_35_h
#define Header_35_h
//
//  main_35.cpp
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int s = 0;
    int end = nums.size();
    while(s < end){
        if(nums[(s+end)/2] < target){
            s = (s+end)/2 + 1;
        }else if(nums[(s+end)/2] > target){
            end = (s+end)/2 -1;
        }else{
            return (s+end)/2;
        }
    }
    cout<<"\ts : "<<s<<"\tend : "<<end<<endl;
    s = (s+end)/2;
    if(s < 0){
        return 0;
    }else if(s >= nums.size()){
        return s;
    }else{
        return nums[s] >= target?s:s+1;
    }
}



#endif /* Header_35_h */
