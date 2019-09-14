//
//  Header_415.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/8.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_415_h
#define Header_415_h
string addStrings(string num1, string num2) {
    int flag = 0,temp = 0,i = num1.length(),j = num2.length();
    if(i < j){
        num1.insert(num1.begin(),j-i,'0');
    }else if(i > j){
        num2.insert(num2.begin(),i-j,'0');
    }
    i = num1.length()-1;
    for(;i>=0;i--){
        temp = num1[i]-'0';
        num1[i] = char(((temp + (num2[i]-'0') + flag)%10)+'0');
        flag = (temp+(num2[i]-'0')+flag)/10;
    }
    if(flag){
        num1.insert(num1.begin(),'0');
    }
    return num1;
}

#endif /* Header_415_h */
