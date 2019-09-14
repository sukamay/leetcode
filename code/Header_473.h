//
//  Header_473.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/17.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_473_h
#define Header_473_h

bool dfs(vector<int>& nums,int pos,vector<long>& sum){
    if(pos == nums.size()){
        long temp = sum[0];
        for(int i = 1;i < 5;i++){
            if(sum[i] != temp){
                return false;
            }
        }
        return true;
    }
    for(int i = 1;i < 5;i++){
        if(sum[i] + nums[pos] > sum[0]){
            continue;
        }
        sum[i] += nums[pos];
        if(dfs(nums,pos+1,sum)){
            return true;
        }
        sum[i] -= nums[pos];
    }
    return false;
}

bool makesquare(vector<int>& nums) {
    if(nums.size() < 4){return false;}
    long all = 0;
    for(int &i:nums){
        all += i;
    }
    if(all%4 != 0){
        return false;
    }else{
        all >>= 2;
    }
    vector<long> sum(5,0);
    sum[0] = all;
    return dfs(nums,0,sum);
}

#endif /* Header_473_h */
