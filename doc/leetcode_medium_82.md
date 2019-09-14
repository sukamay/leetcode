---
title: leetcode_medium_82

date: 2019/08/11 00:24:37
categories:
-leetcode
---


>82. 删除排序链表中的重复元素2
>
>给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
>
>示例 1:
>
>输入: 1->2->3->3->4->4->5
>输出: 1->2->5
>示例 2:
>
>输入: 1->1->1->2->3
>输出: 2->3



## 尝试1:

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode *root = new ListNode(-1),*begin = root,*end = root;
        root->next = head;
        while(end){
            end = end->next;
            // cout<<end->val<<"\t";
            while(end && end->next && end->val == end->next->val){
                // cout<<"\t repeat: "<<end->val<<"\t";
                while(end->next && end->val == end->next->val){
                    end = end->next;
                }
                end = end->next;
                // cout<<"\t after repeat: "<<end->val<<"\t";
            }
            begin->next = end;
            begin = end;
        }
        return root->next;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :20 ms, 在所有 C++ 提交中击败了27.27%的用户
>
>内存消耗 :9.1 MB, 在所有 C++ 提交中击败了44.99%的用户

## 尝试2:



```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = new ListNode(-1),*end = root;
        while(head){
            if(head->next && head->val == head->next->val){
               while(head->next && head->val == head->next->val){
                   head = head->next;
               }
                head = head->next;
            }else{
                end->next = head;
                end = head;
                head = head->next;
            }
        }
        end->next = head;
        return root->next;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :24 ms, 在所有 C++ 提交中击败了14.83%的用户
>
>内存消耗 :9 MB, 在所有 C++ 提交中击败了81.91%的用户



## 尝试3:

思路稍微转转，有个地方不太一样，效率就提高了一倍，我还是too naive了

```c++

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pNode = head;
        ListNode* pPreNode = nullptr;
        int DupNumber;
        while(pNode){
            if(pNode->next != nullptr && pNode->val == pNode->next->val){
                DupNumber = pNode->val;
                while(pNode && pNode->val == DupNumber){
                    //ListNode* pTemp = pNode;
                    pNode = pNode->next;
                    //delete pTemp;
                }
                if(pPreNode == nullptr){
                    head = pNode;   
                }
                else{
                    pPreNode->next = pNode;
                }
            }
            else{
                pPreNode = pNode;
                pNode = pNode->next;
            }
        }
        return head;
    }
};
```



>执行结果：
>
>通过
>
>显示详情 
>
>执行用时 :12 ms, 在所有 C++ 提交中击败了84.94%的用户
>
>内存消耗 :9.2 MB, 在所有 C++ 提交中击败了10.76%的用户