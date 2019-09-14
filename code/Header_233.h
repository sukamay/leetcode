//
//  Header_233.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/23.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_233_h
#define Header_233_h


    int countDigitOne(int n) {
        if(n < 1){return 0;}
        int count = 0,temp = 0, root = n;
        long ind = 1;
        while(n){
            temp = n/10;
            if(n%10 > 1){
                temp++;
            }else if(n%10 == 1){
                count += (root%ind+1);
            }
            n /= 10;
            count += temp*ind;
            ind *= 10;
        }
        return count;
    }

#endif /* Header_233_h */
