//
//  Header_434.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/9.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_434_h
#define Header_434_h
int countSegments(string s) {
    if(s.empty())
        return 0;
    bool flag = false;
    auto iter = s.begin();
    for(;iter != s.end();iter++){
        if(*iter != ' '){
            break;
        }
    }
    int count = 0;
    s.append(" ");
    for(;iter != s.end();iter++){
        if(*iter != ' '){
            flag = true;
        }else if(flag){
            count++;
            flag = false;
        }
    }
    return count;
}

#endif /* Header_434_h */
