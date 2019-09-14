//
//  Header_242.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/4.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_242_h
#define Header_242_h
bool isAnagram(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    int i = 0;
    while(i < s.length() && s[i] == t[i]){
        i++;
    }
    string org = s;
    auto c = s[i];
    org.erase(org.begin()+i);
    string temp;
    for(int j = i+1;j < s.length();j++){
        temp = org;
        temp.insert(temp.begin()+j,c);
        if(temp == t){
            return true;
        }
    }
    return false;
}

#endif /* Header_242_h */
