//
//  Header_155.h
//  leetcode
//
//  Created by 罗媚 on 2019/3/3.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_155_h
#define Header_155_h
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        mem = new int[max_size];
    }
    
    void push(int x) {
        if(cur >= max_size){
            max_size = max_size<<1;
            int* new_mem = new int[max_size];
            memcpy(new_mem,mem,(max_size>>1)*sizeof(int));
            delete []mem;
            mem = new_mem;
        }
        mem[cur++] = x;
        if(x < min){
            min = x;
        }
    }
    
    void pop() {
        if(cur > 0){
            cur--;
            if(mem[cur] == min){
                min = INT_MAX;
                for(int i = 0;i < cur;i++){
                    if(mem[i] < min){
                        min = mem[i];
                    }
                }
            }
        }
    }
    
    int top() {
        if(cur > 0){
            return mem[cur-1];
        }
        return -1;
    }
    
    int getMin() {
        return min;
    }
    
    void print(){
        cout<<"\t";
        for(int i = 0;i < cur;i++){
            cout<<mem[i]<<"->";
        }
        cout<<"\t";
    }
private:
    int min = INT_MAX;
    int cur = 0;
    int max_size = 4;
    int* mem;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#endif /* Header_155_h */
