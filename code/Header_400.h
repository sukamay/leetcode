//
//  Header_400.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/9.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_400_h
#define Header_400_h
#include <cmath>

int findNthDigit(int n) {
    int cur = 1,level = 1;
    while(n > level){
        cur++;
        if(cur/pow(10, level) >= 1){
            level++;
        }
        n -= level;
    }
    if(level == n){
        cur++;
        n--;
    }
    string s = to_string(cur);
    return int(s[level%n]-'0');
}
#endif /* Header_400_h */
