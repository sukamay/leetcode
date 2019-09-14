//
//  main_35.cpp
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
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
        return s;
    }
};
