//
//  Header_263.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/5.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_263_h
#define Header_263_h
bool isUgly(int num) {
    if(num <= 0)
        return false;
    if(num%2 && num%3 && num%5){
        return false;
    }
    while(num > 1 && num%2 == 0){
        num = num>>1;
    }
    while(num > 1 && num%3 == 0){
        num /= 3;
    }
    while(num > 1 && num%5 == 0){
        num /= 5;
    }
    return num==1;
}

#endif /* Header_263_h */
