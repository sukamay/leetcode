//
//  Header_66.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_66_h
#define Header_66_h
#include <vector>

/*
vector<int> plusOne(vector<int>& digits) {
    if(!digits.empty()){
        int k = digits.size()-1;
        for(;k>=0;k--){
            if(digits[k] != 9){
                break;
            }else{
                digits[k] = 0;
            }
        }
        if(k >=0 ){
            digits[k] += 1;
        }else{
            digits.insert(digits.begin(), 1);
        }
    }
    return digits;
}
*/
vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(digits[i]==9)   digits[i]=0; //+1（得到进位）时，如果该位为9，则变为0并向前进位
        else{
            digits[i]++;               //得到进位，如果该位不是9，则+1，并return
            return digits;
        }
    }
    digits[0]=1;
    digits.push_back(0);      //如果遇到所有位都是9，则最后将第一位变成1，末尾加0
    //vector中只有末尾加数的push_back(),没法直接头部插数
    //push_back(val)将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素，
    //新的元素的值是val的拷贝（或者是移动拷贝，即&val）
    return digits;
}

#endif /* Header_66_h */
