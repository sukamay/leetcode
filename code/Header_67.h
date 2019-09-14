//
//  Header_67.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_67_h
#define Header_67_h
string addBinary(string a,string b){
    if(a.length() < b.length())
        swap(a,b);
    int flag = 0;
    int i = a.length()-1,j = b.length()-1;
    char temp;
    for(;j>=0;i--,j--){
        temp = ((b[j] - '0') ^ (a[i] - '0')^ flag) + '0';
        flag = ((b[j] - '0') & (a[i] - '0')) | ((b[j] -'0') & flag) | (flag & (a[i] - '0'));
        a[i] = temp;
    }
    for(;i>=0;i--){
        temp = ((a[i]-'0')^flag) + '0';
        flag = a[i] & flag;
        a[i] = temp;
    }
    if(flag){
        a.insert(a.begin(),'1');
    }
    return a;
}

#endif /* Header_67_h */
