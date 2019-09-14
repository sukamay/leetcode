//
//  Header_203.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/4.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_203_h
#define Header_203_h
ListNode* removeElements(ListNode* head, int val) {
    if(!head)
        return head;
    while(head && head->val == val){
        head = head->next;
    }
    ListNode *front = head,*cur = head;
    while(cur){
        if(cur->val == val){
            front->next = cur->next;
        }
        front = cur;
        cur = cur->next;
    }
    return head;
}

#endif /* Header_203_h */
