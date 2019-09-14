//
//  Header_332.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/16.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_332_h
#define Header_332_h
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string,int> head;

void print(vector<string>& vec){
    for(auto &str:vec){
        cout<<"\t"<<str;
    }
    cout<<endl;
}
void hierholzer(string node,vector<string>& vec,vector<pair<string,string>>& t){
    int i = head[node];
    while(i < t.size() && t[i].first == ""){i++;}
    for(;i < t.size() && t[i].first == node;i++){
        t[i].first = "";
        hierholzer(t[i].second,vec,t);
    }
    vec.push_back(node);
}

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        sort(tickets.begin(),tickets.end());
        map<string,int> counts;
        int i = 0,j = 1;
        counts[tickets[0].first]++;
        counts[tickets[0].second]++;
        while(j < tickets.size()){
            counts[tickets[j].first]++;
            counts[tickets[j].second]++;
            if(tickets[j].first != tickets[i].first){
                head.insert(make_pair(tickets[i].first,i));
                i = j;
            }
            j++;
        }
        head.insert(make_pair(tickets[i].first, i));
        vector<string> vec;
        auto iter = counts.begin();
        for(;iter != counts.end();iter++){
            if(iter->second%2 != 0){
                break;
            }
        }
        hierholzer(iter->first,vec,tickets);
        reverse(vec.begin(),vec.end());
        return vec;
    }


#endif /* Header_332_h */
