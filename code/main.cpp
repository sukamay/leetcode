////
////  main.cpp
////  leetcode
////
////  Created by 罗媚 on 2019/2/25.
////  Copyright © 2019 罗媚. All rights reserved.
////
//
#include <iostream>
#include <vector>
#include <stack>

#include "Header_35.h"
#include "Header_58.h"
#include "Header_66.h"
#include "Header_67.h"
#include "Header_69.h"
#include "Header_82.h"
#include "Header_83.h"
#include "Header_88.h"
#include "Header_101.h"
#include "Header_111.h"
#include "Header_112.h"
#include "Header_120.h"
#include "Header_123.h"
#include "Header_125.h"
#include "Header_142.h"
#include "Header_155.h"
#include "Header_169.h"
#include "Header_190.h"
#include "Header_202.h"
#include "Header_203.h"
#include "Header_204.h"
#include "Header_219.h"
#include "Header_237.h"
#include "Header_242.h"
#include "Header_257.h"
#include "Header_263.h"
#include "Header_264.h"
#include "Header_303.h"
#include "Header_400.h"
#include "Header_405.h"
#include "Header_414.h"
#include "Header_415.h"
#include "Header_429.h"
#include "Header_434.h"
#include "Header_443.h"

using namespace std;

template<class T>
void print(vector<T> vec){
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<"\t";
        cout<<endl;
    }
}

void print(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
}
int main(int argc, const char * argv[]) {
    //    Q443:
    vector<char> vec = {'a','a','b','b','c','c','c'};
    compress(vec);
    print(vec);     
    //    Q434:
/*
    string s = "hello, my name id   may";
    cout<<s<<" has "<<countSegments(s)<<" segments"<<endl;
*/
    //    Q400:
/*
    cout<< pow(10, 2)<<endl;
    cout<<findNthDigit(30)<<endl;
*/
    //    Q429:
/*
    vector<Node*> vec;
    auto iter = vec.begin();
    auto a = (*iter)->val;
*/
    //    Q415:
/*
    cout<<char('0'+3)<<endl;
    cout<<addStrings("10", "0");
*/
    //    Q414:
/*
    vector<int> a = {1,1,3};
    cout<<thirdMax(a)<<endl;
 */
    //    Q409:
//    cout<<'A'-'a'<<endl;
    //    Q405:
/*
    long a = 1;
//    cout<<(a<<32)<<endl;
    cout<<toHex(-1)<<endl;
 */
    //    Q82:
/*
    vector<int> a = {1,1,2,3,3,4,4,5,6,6};
    ListNode* root = create(a);
    root = deleteDuplicatesMedium(root);
    print(root);
*/
    //    Q303:
/*
    vector<int> a = {-2,0,3,-5,2,-1};
    NumArray num(a);
    num.sumRange(0, 2);
*/
    //    Q290:
/*
    string s = "He lo";
    cout<<s.find(" ")<<endl;
    transform(s.begin()+1, s.end(), s.begin()+1, ::tolower);
    cout<<s<<endl;
 */
    //    Q263:
//    isUgly(6);
//    cout<<nthUglyNumber(3);
    //    Q257:
/*
    vector<int> a = {1,2,3,-1,5};
    TreeNode* root = createTree(a);
    auto path = binaryTreePaths(root);
    print(path);
*/
    //    Q242;
/*
    string s = "anagram",t = "nagaram";
    if(isAnagram(s, t)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    vector<int> a = {1};
    vector<int> b = {2};
    if(a == b){
        cout<<"yes";
    }
 */
    //    Q237:
/*
    vector<int> a = {4,5,1,9};
    ListNode* b = create(a);
    deleteNode(b->next);
    print(b);
 */
    //    Q219:
/*
    vector<int> a = {1,2};
    int k = 3;
    if(containsNearbyDuplicate(a, k)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
 */
    //    Q204:
/*
    int num = 10;
    cout<<num<<" \t:\t"<<countPrimes(num)<<endl;
 */
    //    Q203:
/*
    vector<int> a = {1,2,6,3,4,5,6};
    ListNode* b = create(a);
    int val = 6;
    b = removeElements(b, val);
    print(b);
*/
    //    Q202:
/*
    int num = 19;
    cout<<num<<" \t:";
    if(isHappy(num)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
 */
    //    Q190:
/*
    cout<<reverseBits(4294967293)<<endl;
 */
    //    Q169:
/*
    vector<int>  a= {3,2,3};
    cout<<majorityElement(a)<<endl;
 */
    //    Q155:
/*
    MinStack a;
    for(int i = 0;i < 6;i++){
        a.push(i+1);
        cout<<i<<" : "<<a.getMin();
        a.print();
        cout<<endl;
    }
 */
    //    Q142:
    
    //    Q125:
/*
    string s = "OP";
    if(isPalindrome(s)){
        cout<<s<<" : yes"<<endl;
    }else{
        cout<<s<<" : no"<<endl;
    }
 */
    //    Q123: to solve
/*
    vector<int> a = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(a)<<endl;
 */
    //    Q120:
/*
//    vector<vector<int>> a = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> a = {{-1},{2,3},{1,-1,-3}};
    cout<<minimumTotal(a)<<endl;
 */
    //    Q112:
/*
    std::stack<TreeNode*> s;
//    vector<int> a = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
//    vector<int> a = {1,2};
//    vector<int> a = {-2,-1,-3};
    vector<int> a = {1,2,-1,3,-1,4,-1,5};
    TreeNode* root = createTree(a);
    int sum = 6;
    if(hasPathSum(root, sum)){
        cout<<" sum : "<<sum<<"  true"<<endl;
    }else{
        cout<<"sum : "<<sum<<"  false"<<endl;
    }
*/
    //    Q111:
/*
    vector<int> a = {1,2,3,4,5};
    TreeNode* root = createTree(a);
    cout<<minDepth(root)<<endl;
    vector<int> b = {3,9,20,-1,-1,1,7};
    root = createTree(b);
    cout<<minDepth(root)<<endl;
    vector<int> c = {1,2,3,4,-1,-1,5};
    root = createTree(c);
    cout<<minDepth(root)<<endl;
*/
    //    Q101:
/*
    vector<int> a = {2,97,97,-1,47,80,-1,-7,-1,-1,-7};
    TreeNode* root = createTree(a);
    isSymmetric(root);
*/
    //    Q88:
/*
    vector<int> a = {0,0,3,0,0,0,0,0,0};
    vector<int> b = {-1,1,1,1,2,3};
    merge(a,3,b,6);
    print(a);
*/
    //    Q83:
/*
    vector<int> a = {1,1,1,2};
    ListNode* head = create(a);
    head = deleteDuplicates(head);
    print(head);
    //    Q69:
 */
/*
    cout<<"1: "<<mySqrt(1)<<endl;
    cout<<"2: "<<mySqrt(2)<<endl;
    cout<<"4: "<<mySqrt(4)<<endl;
    cout<<"8: "<<mySqrt(8)<<endl;
    cout<<"9: "<<mySqrt(9)<<endl;
    cout<<"int max: "<<mySqrt(INT_MAX)<<endl;
 */
    //    Q67:
/*
    cout<<(0^0^1)<<"  "<<(1^0^1)<<endl;
    cout<<addBinary("110010", "10111")<<endl;
    cout<<addBinary("1010", "1011")<<endl;
    string a = "h";
*/
    //    Q66:
    //    test: 1239,1939,1999,9999,1234
/*
    vector<int> nums = {9};
    print(plusOne(nums));
*/
    //    Q58:
    //    test instance: "hello world" , "","  ","heelo  ",
/*
    cout<<"hello world : "<<lengthOfLastWord("hello world")<<endl;
    cout<<lengthOfLastWord("")<<endl;
    cout<<"   "<<lengthOfLastWord("   ")<<endl;
    cout<<"hell "<<lengthOfLastWord("hell ")<<endl;
 */
    // Q35:
/*    vector<int> nums = {1,3,5,6};
    cout<<searchInsert(nums, 2)<<endl;
    cout<<searchInsert(nums, 7)<<endl;
    cout<<searchInsert(nums, 0)<<endl;
    cout<<searchInsert(nums, 4)<<endl;
 */
    return 0;
}

