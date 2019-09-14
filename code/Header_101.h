//
//  Header_101.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/1.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_101_h
#define Header_101_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& vec){
    TreeNode* root = new TreeNode(vec[0]);
    TreeNode* temp = root;
    vector<TreeNode*> temp_vec;
    bool left = true;
    for(auto iter = vec.begin()+1;iter!=vec.end();iter++){
        if(*iter != -1){
            auto newNode = new TreeNode(*iter);
            if(left){
                temp->left = newNode;
            }else{
                temp->right = newNode;
            }
            temp_vec.push_back(newNode);
        }
        if(!left){
            temp = temp_vec[0];
            temp_vec.erase(temp_vec.begin());
        }
        left = !left;
    }
    return root;
}

bool sub(TreeNode* l,TreeNode* r){
    if(!l && !r) return true;
    if(!l || !r || l->val != r->val) return false;
//    if(!l->left && !l->right && !r->left &&!r->right){
//        if(l->val == r->val)
//            return true;
//        else
//            return false;
//    }
    return sub(l->left,r->right) && sub(l->right,r->left);
}
void traverse(TreeNode* root,string& s,bool flag){
    if(!root){
        s.append("null");
        return;
    }
    s.append(to_string(root->val));
    if(flag){
        traverse(root->left,s,flag);
        traverse(root->right,s,flag);
    }else{
        traverse(root->right,s,flag);
        traverse(root->left,s,flag);
    }
}
bool isSymmetric(TreeNode* root) {
    if(!root || (!root->left && !root->right)) return true;
    if(!root->left || !root->right) return false;
//    string l,s;
//    traverse(root->left,l,true);
//    traverse(root->right,s,false);
//    if(l == s){
//        return true;
//    }else{
//        return false;
//    }
    return sub(root->left, root->right);
}

#endif /* Header_101_h */
