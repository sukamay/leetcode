//
//  Header_429.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/8.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_429_h
#define Header_429_h

//  Definition for a Node.
 class Node {
 public:
     int val;
     vector<Node*> children;
     
     Node() {}
     
     Node(int _val, vector<Node*> _children) {
         val = _val;
         children = _children;
     }
 };
 

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> vec;
    if(!root)
        return vec;
    queue<Node*> q;
    vector<int> in_vec;
    q.push(root);
    int len = root->children.size(),next = 0;
    while(!q.empty()){
        root = q.front();
        q.pop();
        len--;
        if(len == 0){
            vec.push_back(in_vec);
            len = next;
            next = 0;
        }
        for(auto iter = root->children.begin();iter != root->children.end();iter++){
            q.push(*iter);
            in_vec.push_back((*iter)->val);
            next++;
        }
    }
    return vec;
}


#endif /* Header_429_h */
