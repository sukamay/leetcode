//
//  Header_273.h
//  leetcode_hard
//
//  Created by 罗媚 on 2019/4/19.
//  Copyright © 2019 罗媚. All rights reserved.
//

#ifndef Header_273_h
#define Header_273_h


    string numberToWords(int num) {
        vector<string> en{"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen ","Twenty "};
        vector<string> tens{"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        vector<string> base{"Thousand ","Million ","Billion "};
        string res;
        int count = 0,index = -2;
        if(num == 0){return "Zero";}
        while(num > 0){
            string temp;
            count = num%1000;
            num /= 1000;
            index++;
            if(count == 0){
                continue;
            }
            if(count > 99){
                temp.append(en[count/100-1]);
                temp.append("Hundred ");
            }
            count %= 100;
            if(count == 0){
                if(index >= 0){
                    temp.append(base[index]);
                }
                res = temp + res;
                continue;
            }else if(count < 21){
                temp.append(en[count-1]);
            }else{
                temp.append(tens[count/10-2]);
                count %= 10;
                if(count != 0){
                    temp.append(en[count-1]);
                }
            }
            if(index >= 0){
                temp.append(base[index]);
            }
            res = temp + res;
        }
        res.pop_back();
        return res;
    }

#endif /* Header_273_h */
