//
//  Header_111.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/2.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_111_h
#define Header_111_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "Header_101.h"
void minDepth(TreeNode* root,int& depth,int cur){
    if(cur >= depth || !root){
        return;
    }
    if(!root->left && !root->right){
        if(cur < depth){
            depth = cur;
        }
        return;
    }
    minDepth(root->left,depth,++cur);
    minDepth(root->right,depth,cur);
}
int minDepth(TreeNode* root) {
    int depth = 0;
    TreeNode* temp = root;
    while(temp){
        temp = temp->left == NULL? temp->right:temp->left;
        depth++;
    }
    minDepth(root,depth,1);
    return depth;
}

#endif /* Header_111_h */
