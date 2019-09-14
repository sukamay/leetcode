//
//  Header_82.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/7.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_82_h
#define Header_82_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "Header_83.h"
ListNode* deleteDuplicatesMedium(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *first = head,*second = head->next;
    while(second && (first->val == second->val ||(second->next && second->val == second->next->val))){
        first = first->next;
        second = second->next;
    }
    head = second;
    first = second;
    second = second->next;
    int temp = first->val;
    while(second){
        if((second->next && second->val == second->next->val) || second->val == temp){
//            record duplicate num
            temp = second->val;
            first->next = second->next;
        }else if(second->next && second->val != second->next->val){
            first = second;
        }
        second = second->next;
    }
//    int temp = second->val;
//    ListNode* front = head,*end = head;
////    bool flag = false;
//    temp = head->val;
//    while(end && end->next){
//        end = end->next;
//        if(end->val != temp){
//            temp = end->val;
//            if(end->next && end->next->val != end->val){
//                front = front->next;
//            }
//        }else{
//            front->next = end->next;
//        }
//    }
    return head;
}


#endif /* Header_82_h */
