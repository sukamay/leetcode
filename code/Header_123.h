//
//  Header_123.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_123_h
#define Header_123_h
int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    int min=0,f=0,s=0,tmp=0;
    min = prices[0];
    for(auto iter=prices.begin()+1;iter!=prices.end();iter++){
        if(*iter < min){
            if(tmp >= f && tmp > s){
                s = f;
                f = tmp;
            }else if(tmp > s){
                s = tmp;
            }
            tmp = 0;
        }else{
            tmp += *iter - min;
        }
        min = *iter;
    }
    s = max(tmp,s);
    return f+s;
}

#endif /* Header_123_h */
