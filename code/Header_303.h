//
//  Header_303.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/6.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_303_h
#define Header_303_h
class NumArray {
private:
    vector<int> num;
    int gap = 2;
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        num = nums;
        for(int i = 0;i+gap <= nums.size();i++){
            sum.push_back(nums[i]+nums[i+1]);
        }
    }
    
    int sumRange(int i, int j) {
        int s = 0;
        for(int k = i;k < j && k < sum.size();k+=2){
            s += sum[k];
        }
        if((j-i)%2 == 0){
            s += num[j];
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

#endif /* Header_303_h */
