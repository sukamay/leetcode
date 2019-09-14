//
//  Header_672.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/23.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_672_h
#define Header_672_h

void dfs(int end, int m, int cur, int res, set<int>& s);

vector<vector<int>> base{{1,3,7,15,31,63},{1,2,5,10,21,42},{0,1,2,5,10,21},{1,1,1,9,9,9}};

    int flipLights(int n, int m) {
        set<int> s;
        dfs(n, m, 0, (2<<n)-1, s);
//        for(auto iter = s.begin(); iter != s.end(); iter++){
//            cout << bitset<sizeof(int)*8>(*iter) << "\t";
//        }
//        cout << endl;
        return s.size();
    }
    void dfs(int end, int m, int cur, int res, set<int>& s){
//        cout<<bitset<sizeof(int)*8>(res)<<endl;
        if(cur > m){return;}
        if(cur == m){
            s.insert(res);
            return;
        }
        cur++;
        int temp = end-1;
        dfs(end, m, cur, res^base[0][temp], s);
        dfs(end, m, cur, res^base[1][temp], s);
        dfs(end, m, cur, res^base[2][temp], s);
        dfs(end, m, cur, res^base[3][temp], s);
        
    }

#endif /* Header_672_h */
