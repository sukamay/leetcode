//
//  Header_3_1013.h
//  leetcode_week
//
//  Created by 罗媚 on 2019/3/17.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_3_1013_h
#define Header_3_1013_h
#include <vector>
 #include <map>

using std::map;
using std::pair;
using std::vector;
using std::cout;

int numPairsDivisibleBy60(vector<int>& time) {
    int sum = 0,temp = 0;
    map<int,int> map;
    auto iter = map.end();
    for(int t:time){
        temp = t%60;
        iter = map.find(temp);
        if(iter == map.end()){
            map.insert(pair<int,int>{temp,1});
        }else{
            iter->second++;
        }
    }
    for(auto map_iter = map.begin();map_iter != map.end();map_iter++){
        temp = map_iter->first;
        if(temp != 0){
            temp = 60 - temp;
        }
        iter = map.find(temp);
        if(iter != map.end()){
            if(temp == 0 || temp == 30){
                sum += (iter->second*(iter->second-1)/2);
            }else{
                sum += iter->second*map_iter->second;
            }
        }
        map_iter->second = 0;
    }
    return sum;
}


#endif /* Header_3_1013_h */
