//
//  Header_112.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_112_h
#define Header_112_h
#include "Header_101.h"
//version 0
/*
bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    stack<TreeNode*> s;
    int cur = root->val;
    bool flag = true; // true means next direction is right
    s.push_back(root);
    while(!s.empty()){
        s.push_back(root);
    }
    return hasPath(root,sum,0);
}
 */
//version 1
bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    stack<TreeNode*> s;
    int cur = root->val;
    bool flag = false; // true means next direction is right
    s.push(root);
    if(root->left){
        cur += root->left->val;
        s.push(root->left);
    }else if(root->right){
        cur += root->right->val;
        s.push(root->right);
    }
    while(!s.empty()){
        root = s.top();
        if(flag){
            root = root->right;
        }else{
            root = root->left;
        }
        while(root){
            cur += root->val;
            s.push(root);
            root = root->left;
        }
        if(cur == sum && !s.top()->left && !s.top()->right){
            return true;
        }else{
            cur -= s.top()->val;
            s.pop();
        }
            
//        if(flag){
//            cur -= s.top()->val;
//            s.pop();
//            if(s.empty()){
//                break;
//            }
//        }
//        flag = !flag;
//        cur -= s.top()->val;
//        s.pop();
    }
    return false;
}

#endif /* Header_112_h */
