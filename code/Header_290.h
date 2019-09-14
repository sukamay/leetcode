//
//  Header_290.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/6.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_290_h
#define Header_290_h
#include <string>

bool wordPattern(string pattern, string str) {
    vector<string> vec(26);
    int cur = 0;
//    for(int i = 0;i < pattern.length();i++){
//        cur = str.find(" ");
//    }
    string s = "";
    for(int i = 0;i < str.length();i++){
        if(str[i] == ' '){
            if(vec[pattern[cur]-'a'] == ""){
                vec[pattern[cur]-'a'] = s;
            }else if(vec[pattern[cur]-'a'] != s){
                return false;
            }else if(find(vec, s) != vec.end()){
                return false;
            }
            s.clear();
            cur++;
        }else{
            s.append(str[i]);
        }
    }
    return true;
}

#endif /* Header_290_h */
