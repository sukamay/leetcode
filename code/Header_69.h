//
//  Header_69.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_69_h
#define Header_69_h
int mySqrt(int x) {
    long s = 0;
    long e = x;
    if(x <= 1){
        return x;
    }
    while(e-s >= 1){
        long mid = (s+e)/2;
        if(mid*mid < x){
            s = mid + 1;
            if(s*s > x){
                return s-1;
            }
        }else if(mid*mid == x){
            return mid;
        }else{
            e = mid - 1;
        }
    }
    return s;
}

#endif /* Header_69_h */
