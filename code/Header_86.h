//
//  Header_86.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/18.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_86_h
#define Header_86_h
using namespace std;

ListNode* partition(ListNode* head, int x) {
    if(!head || !head->next)
        return head;
    ListNode *root = new ListNode(-1);
    if(!root){
        cout<<"error to malloc"<<endl;
        return nullptr;
    }
    ListNode *front = root,*end = head;
    root->next = head;
    head = root;
    while(end && end->val < x){
        head = head->next;
        front = end;
        end = end->next;
    }
    while(end){
        cout<<end->val<<" \t";
        if(end->val < x){
            front->next = end->next;
            end->next = head->next;
            head->next = end;
            head = head->next;
            end = front->next;
            cout<<"head : "<<head->val<<endl;
        }else{
            front = end;
            end = end->next;
        }
    }
    return root->next;
}

#endif /* Header_86_h */
