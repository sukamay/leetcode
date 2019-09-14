//
//  Header_190.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_190_h
#define Header_190_h
#include <stdlib.h>
#include <bitset>

uint32_t reverseBits(uint32_t n) {
    uint32_t m;
    for(int i = 0; i< 31;i++){
        m |= (n&1);
        m = m<<1;
        n = n>>1;
    }
    m |= (n&1);
    return m;
}


#endif /* Header_190_h */
