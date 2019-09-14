//
//  Header_82.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/3/18.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_82_h
#define Header_82_h
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int v,ListNode* n = nullptr):val(v),next(n){}
};

class LinkList{
public:
    LinkList(){}
    LinkList(std::vector<int>& vec);
    ListNode* getRoot(){return root;}
    ~LinkList();
    void print();
private:
    ListNode *root;
};

LinkList::LinkList(std::vector<int>& vec){
    if(!vec.empty()){
        root = new ListNode(vec[0]);
        ListNode *next,*front = root;
        for(auto iter = vec.begin()+1;iter != vec.end();iter++){
            next = new ListNode(*iter);
            front->next = next;
            front = next;
        }
    }
}

LinkList::~LinkList(){
    ListNode *del;
    while(root){
        del = root;
        root = root->next;
        delete del;
    }
}

void LinkList::print(){
    ListNode *temp = root;
    while(temp){
        std::cout<<temp->val<<"\t";
    }
    std::cout<<std::endl;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next)
        return head;
    int temp = head->val,count = 0;
    ListNode *first = head,*second = head;
    while(second->next){
        if(second->val == temp){
            count++;
        }else{
            if(count == 1){
                first->val = temp;
                first = first->next;
            }
            count = 1;
            temp = second->val;
        }
        second = second->next;
    }
    if(second->val != temp){
        first->val = second->val;
        first->next = nullptr;
    }else{
        first = nullptr;
    }
    return head;
}

#endif /* Header_82_h */
