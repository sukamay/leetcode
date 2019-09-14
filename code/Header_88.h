//
//  Header_88.h
//  leetcode
//
//  Created by 罗媚 on 2019/2/28.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_88_h
#define Header_88_h
//version0
/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0,j =0,len = 0;
    nums1.erase(nums1.begin()+m,nums1.begin()+m+n);
    while(i < m+n && j< n && len < m){
        if(nums1[i] < nums2[j]){
            i++;
            len++;
        }else{
            nums1.insert(nums1.begin()+i+j,nums2[j]);
            i++;
            j++;
        }
    }
    while(j<n){
        nums1.push_back(nums2[j]);
        j++;
    }
}
*/
//version1
void merge(vector<int>& nums1, int m ,vector<int>& nums2,int n){
    for(auto iter = nums1.begin()+m,iter2 = nums2.begin();iter != nums1.begin()+m+n && iter2 != nums2.end();iter++,iter2++){
        (*iter) = (*iter2);
    }
    int cur =0,len =m;
    while(len < n+m && cur < m+n && cur < len){
        if(nums1[cur] >= nums1[len]){
            nums1.insert(nums1.begin()+cur, nums1[len]);
            nums1.erase(nums1.begin()+len+1);
            len++;
        }
        cur++;
    }
}

#endif /* Header_88_h */
