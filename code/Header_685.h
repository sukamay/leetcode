//
//  Header_685.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/13.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_685_h
#define Header_685_h

#include <vector>

using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> before(edges.size()+1,0);
    vector<int> candi1,candi2;
    for(auto edge:edges){
        if(before[edge[1]] == 0){
            before[edge[1]] = edge[0];
        }else{
            candi1 = edge;
            candi2.push_back(before[edge[1]]);
            candi2.push_back(edge[1]);
        }
    }
    vector<int> circle(edges.size()+1,0);
    int root1,root2;
    for(auto edge:edges){
        if(edge == candi1){
            continue;
        }
        root1 = edge[0];
        root2 = edge[1];
        while(circle[root1] > 0){
            root1 = circle[root1];
        }
        while(circle[root2] > 0){
            root2 = circle[root2];
        }
        if(root1 == root2){
            if(candi2.empty()){
                return edge;
            }else{
                return candi2;
            }
        }else{
            circle[root2] = root1;
        }
    }
    return candi1;
}

#endif /* Header_685_h */
