//
//  Header_449.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/13.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_449_h
#define Header_449_h

void sub(TreeNode* root,string& res){
    if(!root){
        return;
    }
    res.append(to_string(root->val)+",");
    sub(root->left,res);
    sub(root->right,res);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    //preorder
    string res = "";
    sub(root,res);
    cout<<"encode : "<<res<<endl;
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty()){return nullptr;}
    int i = 0,val = 0;
    TreeNode *root,*cur;
    string valStr;
    stack<TreeNode*> st;
    while(i < data.length()-1){
        auto pos = data.find(',',i);
        valStr = data.substr(i,pos-i);
        val = atoi(valStr.c_str());
        i = pos+1;
        if(!root){
            root = new TreeNode(val);
            st.push(root);
        }else{
            if(val < st.top()->val){
                cur = st.top();
                cur->left = new TreeNode(val);
                st.push(cur->left);
            }else{
                while(!st.empty() && val > st.top()->val){
                    cur = st.top();
                    st.pop();
                }
                cur->right = new TreeNode(val);
                st.push(cur->right);
            }
        }
    }
    return root;
}

#endif /* Header_449_h */
