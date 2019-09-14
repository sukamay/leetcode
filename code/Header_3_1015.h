//
//  Header_3_105.h
//  leetcode_week
//
//  Created by 罗媚 on 2019/3/17.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_3_105_h
#define Header_3_105_h
//#include <algorithm>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int dul(int index, int num){
    if(num == 0)
        return 0;
    int res = 1;
    while(num){
        res *= index;
        index--;
        num--;
    }
//    cout<<"res: "<<res<<endl;
    return res;
}
int numDupDigitsAtMostN(int N) {
    int temp = N;
    vector<int> vec;
    set<int> set;
    while(temp){
        vec.push_back(temp%10);
        temp /= 10;
    }
    int sum = 0;
    for(int i = vec.size()-1;i > 0;i--){
        if(i == 1){
            sum += 9;
        }else{
            sum += 9*dul(9,i-1);
        }
    }
    sum += (vec.back()-1)*dul(9,vec.size()-1);
    for(int i = vec.size()-2;i >= 0;i--){
        set.insert(vec[i]);
        for(int j = 0;j < vec[i];j++){
            if(set.find(j) != set.end()){
                sum += int(pow(10,i));
            }else{
                sum += dul(10-(vec.size()-i),i);
            }
        }
//        sum += (vec[i] * dul(10-(vec.size()-i),i));
    }
    return N-sum;
}

#endif /* Header_3_105_h */
