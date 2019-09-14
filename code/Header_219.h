//
//  Header_219.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/4.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_219_h
#define Header_219_h
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.size() <= k ){
        return false;
    }
    for(int i = 0;i < nums.size()- k;i++){
        if(nums[i] == nums[i+k]){
            return true;
        }
    }
    return false;
}

#endif /* Header_219_h */
