//
//  Header_58.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_58_h
#define Header_58_h

//version 0
/*
int lengthOfLastWord(string s) {
    int i = s.size()-1;
    while(i >= 0){
        if(s[i] == ' '){
            i--;
        }else{
            break;
        }
    }
    int j = s.length()-i;
    for(;i >=0 ;i--){
        if(s[i] == ' '){
            break;
        }
    }
    if(s.length() == 0){
        return 0;
    }
    if(i == s.length()-1){
        return s.length()-1;
    }
    return s.length()-i-j;
}
*/
//version 1
int lengthOfLastWord(string s){
    if(s.length() == 0)return 0;
    int len = 0;
    int first = -1;
    for(int i = s.length()-1;i>=0;i--){
        if(s[i] != ' '){
            first = i;
            break;
        }
    }
    if(first == -1) return 0;
    for(int j = first; j >= 0;j--){
        if(s[j] != ' '){
            len++;
        }else{
            break;
        }
    }
    return len;
}
//version 2
/*
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        while (s[0] == ' ') {
            s.erase(s.begin());
        }
        int pos = s.find(" ");
        if (pos == string::npos) {
            return s.length();
        } else {
            return pos;
        }
    }
};
 */
// 🐂🍺
#endif /* Header_58_h */
