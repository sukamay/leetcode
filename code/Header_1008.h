//
//  Header_1008.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/13.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_1008_h
#define Header_1008_h

#include <vector>
#include <queue>
#include <stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void levelPrint(TreeNode* root){
    if(!root){return;}
    cout<<"traverse tree in level: "<<endl;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        for(int i = q.size();i > 0;i--){
            root = q.front();
            cout<<root->val<<"\t";
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
            q.pop();
        }
        cout<<endl;
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.empty()){
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]),*cur;
    cur = root;
    stack<TreeNode*> st;
    st.push(root);
    int i = 1;
    while( i < preorder.size()){
        if(preorder[i] < st.top()->val){
            cur = st.top();
            cur->left = new TreeNode(preorder[i++]);
            st.push(cur->left);
        }else{
            while(!st.empty() && preorder[i] > st.top()->val){
                cur = st.top();
                st.pop();
            }
            if(i < preorder.size()){
                cur->right = new TreeNode(preorder[i++]);
                st.push(cur->right);
            }
        }
    }
    return root;
}
#endif /* Header_1008_h */
