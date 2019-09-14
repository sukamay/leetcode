//
//  Header_237.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/4.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_237_h
#define Header_237_h
void deleteNode(ListNode* node){
    ListNode* front = node;
    while(node && node->next){
        node->val = node->next->val;
        front = node;
        node = node->next;
    }
    front->next = nullptr;
    delete node;
    node = nullptr;
}

#endif /* Header_237_h */
