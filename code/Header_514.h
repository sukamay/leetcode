//
//  Header_514.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/18.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_514_h
#define Header_514_h


    int findRotateSteps(string ring, string key) {
        vector<vector<int>> rings(26,vector<int>{});
        for(int i = 0; i < ring.size(); i++){
            rings[ring[i]-'a'].push_back(i);
        }
        int max = 0,len = ring.length();
        for(int i = 0; i < 26; i++){
            if(rings[i].size() > max){
                max = rings[i].size();
            }
        }
        vector<int> dp = rings[key[0]-'a'];
        while(dp.size() < max){
            dp.push_back(-1);
        }
        int dur = INT_MAX, temp = 0, j = 0, k = 0 ,index = 0;
        for(int i = 1; i < key.size(); i++){
            vector<int> pre(max,-1);
            j = 0;
            for(int &a:rings[key[i]-'a']){
                dur = INT_MAX;
                k = 0;
                for(int &b:rings[key[i-1]-'a']){
                    temp = min(abs(b-a),len-abs(b-a));
                    if(temp < dur){
                        dur = temp;
                        index = k;
                    }
                    k++;
                }
                pre[j] = dp[index] + dur;
                j++;
            }
            dp = pre;
        }
        int res = dp[0];
        for(int i = 1;i < max; i++){
            if(dp[i] < 0){break;}
            if(dp[i] < res){res = dp[i];}
        }
        return res+key.length();
    }

#endif /* Header_514_h */
