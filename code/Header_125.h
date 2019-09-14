//
//  Header_125.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_125_h
#define Header_125_h
bool isPalindrome(string s) {
    if(s == "")
        return true;
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    int i = 0,j = s.length()-1;
    while(i < j){
        if(s[i] > 'z' || s[i] < 'a'){
            i++;
            continue;
        }
        if(s[j] > 'z' || s[j] < 'a'){
            j--;
            continue;
        }
        if(s[i] != s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}

#endif /* Header_125_h */
