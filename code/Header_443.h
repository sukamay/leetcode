//
//  Header_443.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/10.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_443_h
#define Header_443_h

int compress(vector<char>& chars) {
    if(chars.size() <= 1)
        return chars.size();
    char temp = chars[0];
    int count = 0,start = 0,len = 0,i = 0;
    string s = "";
    for(i = 0;i < chars.size();i++){
        if(chars[i] == temp){
            count++;
        }else{
            temp = chars[i];
            if(count > 1){
                len = 0;
                chars.erase(chars.begin()+start+1,chars.begin()+i);
                while(count > 0){
                    chars.insert(chars.begin()+start+1,char((count%10)+'0'));
                    count /= 10;
                    len++;
                }
            }
            start += len+1;
            i = start-1;
            count = 0;
        }
    }
    if(count > 1){
        len = 0;
        chars.erase(chars.begin()+start+1,chars.begin()+i);
        while(count > 0){
            chars.insert(chars.begin()+start+1,char((count%10)+'0'));
            count /= 10;
            len++;
    }
    return chars.size();
}


#endif /* Header_443_h */
