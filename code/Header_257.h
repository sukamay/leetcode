//
//  Header_257.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/5.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_257_h
#define Header_257_h
#include "Header_101.h"

void sub(TreeNode* root,string s,vector<string>& vec){
    if(!root) return;
    s.append(to_string(root->val));
    if(!root->left && !root->right){
        vec.push_back(s);
        return;
    }
    s.append("->");
    sub(root->left,s,vec);
    sub(root->right,s,vec);
}
//version 0, exclusive
/*
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> vec;
    if(!root){
        return vec;
    }
    string s = "";
    sub(root, s, vec);
    return vec;
}
 */
//version 1
vector<string> binaryTreePaths(TreeNode* root){
    vector<string> vec;
    if(!root)
        return vec;
    stack<TreeNode*> path;
    string s = "";
    path.push(root);
//    bool left = true;
    while(!path.empty()){
        root = path.top();
        s.append(to_string(root->val));
        if(!root->left && !root->right){
            vec.push_back(s);
            TreeNode* temp = root;
            path.pop();
            if(path.empty()) return vec;
            root = path.top();
            int len = 1;
            if(temp == root->left){
                path.push(root->right);
            }else{
                path.pop();
                if(path.empty()) return vec;
                temp = path.top();
                if(root == temp->left){
                    if(temp->right){
                        path.push(temp->right);
                    }else{
                        return vec;
                    }
                }
                len++;
            }
            int i = s.length()-1;
            while(i > 0 && len >= 0){
                if(s[i] == '>'){
                    len--;
                }
                i--;
            }
            s.erase(s.begin()+i, s.end());
        }else{
             s.append("->");
            if(root->left){
                path.push(root->left);
            }else{
                path.push(root->right);
            }
        }
    }
    return vec;
}

#endif /* Header_257_h */
