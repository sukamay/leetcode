//
//  Header_405.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/8.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_405_h
#define Header_405_h
string toHex(int num) {
    char ch[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string s;
    long lnum = 1;
//    cout<<bits<<endl<<bits.flip()<<endl;
    if(num < 0){
//        num = int(long(lnum<<32) - long(abs(num)) + 1);
//        num = abs(num)^1;
//        cout<<"num: "<<num<<endl;
//        num++;
        bitset<sizeof(int)*8> bits(num);
        lnum = bits.to_ulong();
        cout<<lnum<<endl;
    }else{
        lnum = num;
    }
    if(lnum > 0){
        while(lnum > 0){
//            int temp = num%16;
//            num = num >> 4;
            s = ch[lnum%16] + s;
            lnum = lnum >> 4;
        }
    }else{
        return "0";
    }
    return s;
}

#endif /* Header_405_h */
