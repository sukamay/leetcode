//
//  Header_143.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/19.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_143_h
#define Header_143_h
#include <deque>

#include "Header_82.h"

using std::deque;
using std::cout;

void reorderList(ListNode* head) {
    if(!head){
        return;
    }
    deque<ListNode*> de;
    int out = 0,in = 0;
    ListNode *front = head,*temp = head;
    while(front){
        de.push_back(front);
        front = front->next;
        in++;
        if(in > out){
            de.pop_front();
            out++;
            in--;
        }
//        cout<<"in "<<in<<"\t";
    }
    front = head;
    while(!de.empty()){
        temp = de.back();
//        cout<<"temp "<<temp->val<<"\t";
        de.pop_back();
        temp->next = front->next;
        front->next = temp;
        front = temp->next;
    }
    front->next = nullptr;
    cout<<"this is end";
    return;
}

#endif /* Header_143_h */
