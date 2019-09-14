//
//  Header_721.h
//  leetcode_mid
//
//  Created by 罗媚 on 2019/4/20.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_721_h
#define Header_721_h

bool cmp(vector<string>& v1, vector<string>& v2){
    return v1[0] < v2[0];
}
void ins(vector<int>& pra,int root, int i){
    if(root == i){return;}
    int root1 = root;
    while(pra[root1] >= 0){
        root1 = pra[root1];
    }
    int root2 = i;
    while(pra[root2] >= 0){
        root2 = pra[root2];
    }
    pra[root2] = root1;
}

int findpra(vector<int>& pra,int i){
    int root = i;
    while(pra[root] >= 0){
        root = pra[root];
    }
    return root;
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    sort(accounts.begin(), accounts.end(), cmp);
    int len = int(accounts.size());
    string pre = "", name = "",email = "";
    vector<vector<string>> res;
    map<string,int> lock;
    vector<int> pra(len,-1);
    map<int,int> match;
    int root = 0;
    for(int i = 0;i < len;i++){
        name = accounts[i][0];
        if(name != pre){
//            res.push_back(vector<string>{name});
            pre = name;
            for(auto iter = lock.begin(); iter != lock.end();iter++){
                root = findpra(pra, iter->second);
                if(match.find(root) == match.end()){
                    match[root] = res.size();
                    res.push_back(vector<string>{accounts[root][0]});
                }
                res[match[root]].push_back(iter->first);
            }
            lock.clear();
        }
        root = i;
        for(int j = accounts[i].size()-1; j > 0;j--){
            email = accounts[i][j];
            if(lock.find(email) != lock.end()){
                root = lock[email];
                ins(pra, root, i);
            }
            lock.insert(make_pair(email, root));
        }
    }
    for(auto iter = lock.begin(); iter != lock.end();iter++){
        root = findpra(pra, iter->second);
        if(match.find(root) == match.end()){
            match[root] = res.size();
            res.push_back(vector<string>{accounts[root][0]});
        }
        res[match[root]].push_back(iter->first);
    }
    return res;
}

#endif /* Header_721_h */
