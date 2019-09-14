//
//  Header_65.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/19.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_65_h
#define Header_65_h

// ..1 , 0e ,1e , "  2e3 ","2e 3"

    bool isNumber(string s) {
        int i = 0, j = s.length();
        bool count = false;
        while(i < j && s[i] == ' '){i++;}
        if(i == j){return false;}
        j--;
        while(j >= 0 && s[j] == ' '){j--;}
        j++;
        if(s[i] == '+' || s[i] == '-'){i++;}
        while(i < j && isdigit(s[i])){
            i++;
            count = true;
        }
        if(i >= j && count){return true;}
        if(s[i] == '.'){
            i++;
            while(i < j && isdigit(s[i])){i++;count = true;}
            if(i >= j && count){return true;}
        }
        if(s[i] == 'e'){
            i++;
            if(!count){return false;}
            count = false;
            if(i < j && (s[i] == '+' || s[i] == '-')){i++;}
            while(i < j && isdigit(s[i])){i++;count = true;}
            if(i >= j && count){return true;}
        }
        return false;
    }

#endif /* Header_65_h */
