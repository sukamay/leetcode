//
//  Header_142.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_142_h
#define Header_142_h
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head,*slow = head;
    bool flag = false;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            flag = true;
            break;
        }
    }
    if(flag){
        while(fast != head){
            fast = fast->next;
            head = head->next;
        }
        return fast;
    }else{
        return nullptr;
    }
    return fast;
}
#endif /* Header_142_h */
