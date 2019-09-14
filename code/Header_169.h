//
//  Header_169.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_169_h
#define Header_169_h

int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int temp = nums[0], cur = nums[0],temp_len = INT_MIN,len = 1;
    for(int i = 1;i < nums.size();i++){
        if(cur == nums[i]){
            len++;
        }else{
            if(len > nums.size()/2){
                return cur;
            }
            if(len > temp_len){
                temp_len = len;
                temp = cur;
            }
            cur = nums[i];
            len = 1;
        }
    }
    if(len > temp_len){
        temp = cur;
    }
    return temp;
}
#endif /* Header_169_h */
