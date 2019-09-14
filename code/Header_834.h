//
//  Header_834.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/13.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_834_h
#define Header_834_h

#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<vector<int>> link(N);
    vector<int> res;
    for(auto &edge:edges){
        link[edge[0]].push_back(edge[1]);
        link[edge[1]].push_back(edge[0]);
    }
    int sum = 0,level = 0,cur = 0;
    queue<int> q;
    set<int> pass;
    for(int i = 0;i < N;i++){
        sum = 0;
        level = 0;
        q.push(i);
        pass.clear();
        pass.insert(i);
        cout<<"node "<<i<<endl;
        while(!q.empty()){
            level++;
            cout<<"level "<<level<<":\t";
            for(int j = q.size();j > 0;j--){
                cur = q.front();
                cout<<cur<<"\t";
                for(int k = link[cur].size()-1;k >= 0;k--){
                    if(pass.find(link[cur][k]) == pass.end()){
                        pass.insert(link[cur][k]);
                        q.push(link[cur][k]);
                        sum += level;
                    }
                }
                q.pop();
            }
            cout<<endl;
        }
        res.push_back(sum);
    }
    return res;
}

#endif /* Header_834_h */
