//
//  Header_83.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_83_h
#define Header_83_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* create(vector<int>& vec){
    ListNode* root = NULL;
    ListNode* next = NULL;
    for(int i =0;i< vec.size();i++){
        if(!root){
            root = new ListNode(vec[i]);
            next = root;
        }else{
            next->next = new ListNode(vec[i]);
            next = next->next;
        }
    }
    return root;
}

ListNode* deleteDuplicates(ListNode* head) {
    int temp = head->val;
    ListNode* root = head;
    ListNode* former = head;
    head = head->next;
    while(head){
        if(head->val == temp){
            former->next = head->next;
            delete head;
            head = former->next;
        }else{
            former = head;
            temp = head->val;
            head = head->next;
        }
    }
    return root;
}

#endif /* Header_83_h */
