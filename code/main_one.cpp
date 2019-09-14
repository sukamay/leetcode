//
//  main_one.cpp
//  leetcode
//
//  Created by 罗媚 on 2019/2/26.
//  Copyright © 2019 罗媚. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int,int> map;
    for(int i = 0;i < nums.size();i++){
        int com = target - nums[i];
        auto iter = map.find(com);
        if(iter != map.end()){
            result.push_back(iter->second);
            result.push_back(i);
            return result;
        }else{
            map[nums[i]] = i;
        }
    }
    return result;
}

template<class T>
void print(vector<T>& vec){
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<endl;
    }
}
//
//
//int main(){
////    vector<int> n = {1,2,7,3};
////    auto a = twoSum(n, 9);
////    print(a);
//    string s = "heelo";
//    vector<int> b;
//    cout<<b.size()<<endl;
//    stack<int> sa;
//    cout<<sa.top()<<endl;
//    s.push_back(c)
//    return 0;
//}
