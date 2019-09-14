//
//  Header_494.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/18.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_494_h
#define Header_494_h

#include <vector>

//int findTargetSumWays(vector<int>& nums, int S) {
//    int sum = std::accumulate(nums.begin(),nums.end(),0);
//    if(sum<S||(sum-S)%2==1)return 0;
//    sum=(sum-S)/2;
//    vector<int> dp(sum+1,0);
//    dp[0]=1;
//    for(auto it:nums){
//        for(int i=sum;i>=it;i--){
//            dp[i]+=dp[i-it];
//        }
//    }
//    return dp[sum];
//}

#endif /* Header_494_h */
