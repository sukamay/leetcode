//
//  main.cpp
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/18.
//  Copyright © 2019 罗媚. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

#include "Header_82.h"
#include "Header_86.h"
#include "Header_143.h"
#include "Header_64.h"
#include "Header_73.h"
#include "Header_605.h"
#include "Header_236.h"
#include "Header_130.h"
#include "Header_1020.h"
#include "Header_332.h"
#include "Header_473.h"
#include "Header_494.h"
#include "Header_721.h"
#include "Header_672.h"

using namespace std;

int main(int argc, const char * argv[]) {
    //    Q672:
    for(int n = 1; n < 7;n++){
        for(int m = 1; m < 6; m++){
            cout << n << " , " << m << " :\t" << flipLights(n, m) << endl;
        }
    }
    //    Q721:
/*
    vector<vector<string>> accounts{{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
//    vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john00@mail.com"},{"John", "johnnybravo@mail.com"},{"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"Mary", "mary@mail.com"}};
    auto res = accountsMerge(accounts);
    for(auto &p: res){
        print(p);
        cout << endl;
    }
*/
    //    Q494:
/*
    vector<int> nums{2,7,9,13,27,31,37,3,2,3,5,7,11,13,17,19,23,29,47,53};
    int S = 37;
    cout<< "res: " << findTargetSumWays(nums, S);
*/
    //    Q473:
/*
//    vector<int> nums{1,1,2,2,2};
//    vector<int> nums{6122053,1031956,460065,3996684,3891947,1839190,6127621,8855952,8835594,3425930,4189081,7596722,876208,7952011,9676846};
    vector<int> nums{7215807,6967211,5551998,6632092,2802439,821366,2465584,9415257,8663937,3976802,2850841,803069,2294462,8242205,9922998};
    cout << makesquare(nums) << endl;
*/
    //    Q332:
/*
    vector<pair<string, string>> vec{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
//    vector<pair<string, string>> vec{{"a","b"},{"b","c"},{"c","d"},{"d","e"},{"e","b"},{"e","f"},{"f","a"},{"a","e"}};
    auto res = findItinerary(vec);
    print(res);
 */
    //    Q1020:
/*
    vector<vector<int>> vec{
        {0,0,0,1,1,1,0,1,0,0},
        {1,1,0,0,0,1,0,1,1,1},
        {0,0,0,1,1,1,0,1,0,0},
        {0,1,1,0,0,0,1,0,1,0},
        {0,1,1,1,1,1,0,0,1,0},
        {0,0,1,0,1,1,1,1,0,1},
        {0,1,1,0,0,0,1,1,1,1},
        {0,0,1,0,0,1,0,1,0,1},
        {1,0,1,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,1}};
    cout<<"result "<<numEnclaves(vec)<<endl;
*/
    //    Q130:
/*
//    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char>> board{{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    solve(board);
*/
    //    Q236:
/*
    lowestCommonAncestor(root, p, q);
*/
    //    Q605:
/*
    vector<int> vec = {1,0,0,1};
    sort(vec.begin(), vec.end());
    cout<<canPlaceFlowers(vec, 2);
*/
    //    Q64:
//    vector<vector<int>> vec = {
//        {1,1,1},
//        {0,1,1},
////        {4,2,1},
//    };
//    cout<<minPathSum(vec);
//    setZeroes(vec);
    // insert code here...
//    std::cout << "Hello, World!\n";
//    vector<int> vec = {1,2,3,4,5};
//    LinkList l(vec);
//    auto root = l.getRoot();
//    reorderList(root);
//    l.print();
//    auto head = partition(root,3);
    return 0;
}
