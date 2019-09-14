//
//  Header_204.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/4.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_204_h
#define Header_204_h

int countPrimes(int n) {
    vector<bool> nums(n-1,true);
    for(int i = 2;i < n;i++){
        for(int j = n/i; j > 1;j--){
            nums[j*i-1] = false;
        }
    }
    int sum = 0;
    for(int k = 0;k < n-1;k++){
        if(nums[k])
            sum++;
    }
    return sum-1;
}
#endif /* Header_204_h */
