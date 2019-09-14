//
//  Header_236.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/10.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_236_h
#define Header_236_h
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        stack<TreeNode*> pst,st;
        st.push(root);
        int flag = 0;
        map<int,int> map;
        while(flag < 2){
            root = st.top();
            if(root == p || root == q){
                flag++;
                if(pst.empty()){
                    pst = st;
                }
            }
            if(root->left && map[root->val] == 0){
                st.push(root->left);
                map[root->val] = 1;
            }else if(root->right && map[root->val] == 1){
                st.push(root->right);
                map[root->val] = 2;
            }else{
                st.pop();
            }
        }
        while(pst.top() != st.top()){
            if(pst.size() > st.size()){
                pst.pop();
            }else if(pst.size() < st.size()){
                st.pop();
            }else{
                pst.pop();
                st.pop();
            }
        }
        return pst.top();
    }
    void dfs(TreeNode* root,TreeNode* p,stack<TreeNode*>& st){
        st.push(root);
        bool flag = true;
        map<int,int> map;
        while(flag){
            root = st.top();
            if(root == p){
                break;
            }
            if(root->left && map[root->val] == 0){
                st.push(root->left);
                map[root->val] = 1;
            }else if(root->right && map[root->val] == 1){
                st.push(root->right);
                map[root->val] = 2;
            }else{
                st.pop();
            }
        }
        // print(st);
    }
    void print(stack<TreeNode*> st){
        while(!st.empty()){
            cout<<st.top()->val<<"\t";
            st.pop();
        }
        cout<<endl;
    }
    
*/
#endif /* Header_236_h */
