//
//  Header_726.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/15.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_726_h
#define Header_726_h


string countOfAtoms(string formula) {
    string res,temp;
    vector<pair<string,int>> li;
    auto iter = li.end();
    int i = 0,count = 0;
    while(i < formula.length()){
        if(isupper(formula[i])){
            li.push_back(make_pair(string(1,formula[i]),0));
        }else if(islower(formula[i])){
            li.back().first.append(1,formula[i]);
        }else if(isdigit(formula[i])){
            li.back().second = li.back().second*10 + int(formula[i]-'0');
        }else if(formula[i] == '('){
            li.push_back(make_pair("(",-1));
        }else{
            i++;
            count = 0;
            while(i < formula.length() && isdigit(formula[i])){
                count *= 10;
                count += int(formula[i]-'0');
                i++;
            }
            i--;
            for(iter = li.end() - 1;iter->first != "(";iter--){
                if(iter->second == 0){
                    iter->second = 1;
                }
                iter->second *= count;
            }
            li.erase(iter);
        }
        i++;
    }
    sort(li.begin(),li.end());
    int m = 0,n = 1;
    while(n < li.size()){
        if(li[n].first != li[m].first){
            res.append(li[m].first);
            if(li[m].second > 0){
                res.append(to_string(li[m].second));
            }
            m = n;
        }else{
            li[m].second = max(li[m].second,1);
            li[m].second += max(li[n].second,1);
        }
        n++;
    }
    if(m < li.size()){
        res.append(li[m].first);
        if(li[m].second > 0){
            res.append(to_string(li[m].second));
        }
    }
    return res;
}

#endif /* Header_726_h */
