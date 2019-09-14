//
//  Header_202.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_202_h
#define Header_202_h
bool isHappy(int n) {
    int m = n;
    vector<int> vec;
    while(m != 1){
        auto iter = find(vec.begin(),vec.end(),m);
        if(iter == vec.end()){
            vec.push_back(m);
        }else{
            return false;
        }
        n = m;
        m = 0;
        while(n){
            m += (n%10)*(n%10);
            n = n/10;
        }
    }
    return true;
}

#endif /* Header_202_h */
