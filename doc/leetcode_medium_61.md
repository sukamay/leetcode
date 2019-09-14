---
title: leetcode_medium_61

date: 2019/08/11 00:24:37
categories:
-leetcode
---



>61. 旋转链表
>
>给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
>
>示例 1:
>
>输入: 1->2->3->4->5->NULL, k = 2
>输出: 4->5->1->2->3->NULL
>解释:
>向右旋转 1 步: 5->1->2->3->4->NULL
>向右旋转 2 步: 4->5->1->2->3->NULL
>示例 2:
>
>输入: 0->1->2->NULL, k = 4
>输出: 2->0->1->NULL
>解释:
>向右旋转 1 步: 2->0->1->NULL
>向右旋转 2 步: 1->2->0->NULL
>向右旋转 3 步: 0->1->2->NULL
>向右旋转 4 步: 2->0->1->NULL
>

原来被题目误导了，老老实实地旋转了很多次，过了一段时间再看，只需要一次就好，直接往前挪很多步是一样的，主要思路就是找到间断的节点，然后把后面那一截顺移到前边就好了

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
    ListNode* rotateRight(ListNode* head, int k) {
      // ！！！注意判空！
        if(head == NULL){
            return head;
        }
        ListNode *end = head,*begin = head,*before;
        int count = 0;
      // 先看整体链表的长度
        while(end){
            before = end;
            end = end->next;
            count++;
        }
        // cout<<count;
      // 此处是为了保证k不超过链表的长度
        k %= count;
        if(k == 0){
            return head;
        }
        k = count - k - 1;
      // 找到间断的节点
        end = head;
        while(k){
            end = end->next;
            k--;
        }
      // 把后面的整段往左挪
        begin = end->next;
        end->next = NULL;
        before->next = head;
        head = begin;
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
>执行用时 :12 ms, 在所有 C++ 提交中击败了85.92%的用户
>
>内存消耗 :8.8 MB, 在所有 C++ 提交中击败了88.70%的用户