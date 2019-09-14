//
//  Header_605.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/22.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_605_h
#define Header_605_h

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sum = 0,count = 0;
    auto iter = flowerbed.begin();
    while(iter != flowerbed.end() && *iter == 0){
        count++;
        iter++;
    }
    if(count > 1){
        sum += (count>>1);
        count = 0;
    }
    for(;iter != flowerbed.end();iter++){
        if(*iter == 1 && count > 2){
            sum += ((count-1)>>1);
            count = 0;
        }else{
            count++;
        }
    }
    if(count > 1){
        sum += (count>>1);
    }
    return sum;
}


#endif /* Header_605_h */
