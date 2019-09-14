//
//  main.cpp
//  leetcode_week
//
//  Created by 罗媚 on 2019/3/17.
//  Copyright © 2019 罗媚. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

#include "Header_3_1013.h"
#include "Header_3_1015.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    //    Q1015:
    vector<int> num = {20,100,1000};
    for(int n : num){
        cout<<"num: "<<n<<" res : "<<numDupDigitsAtMostN(n)<<endl;
    }
    //    Q1013:
//    vector<int> vec = {418,204,77,278,239,457,284,263,372,279,476,416,360,18};
//    vector<int> vec= {174,188,377,437,54,498,455,239,183,347,59,199,52,488,147,82};
//    cout<<"num : "<<numPairsDivisibleBy60(vec)<<endl;
    return 0;
}
