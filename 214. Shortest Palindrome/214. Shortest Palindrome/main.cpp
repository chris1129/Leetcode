//
//  main.cpp
//  214. Shortest Palindrome
//
//  Created by Sheng-Yung Cheng on 11/30/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    
    vector<int> KMPpreprocessing(string pattern) {
        
        vector<int>next(pattern.size(),0);
        int index=0;
        for(int i=1;i<pattern.size();){
            if(pattern[i]==pattern[index]){
                next[i]=index+1;
                index++;
                i++;
                
            }else{
                if(index!=0){
                    index=next[index-1];
                    
                }else{
                    next[i]=0;
                    i++;
                }
                
            }
        }
        
        return next;
    }
    string shortestPalindrome(string s) {
        if(s.size()==0)return "";
        string rev=s;//take s=abab
        reverse(rev.begin(),rev.end());//rev=baba
        
        vector<int>next=KMPpreprocessing(s+"#"+rev);//find the longest prefix equal to suffix  abab#baba
        // put # in the middle to prevent case like s=aaaaa
        //s+rev=>aaaaaaaaaa leads the longest prefix to be 9 which is bigger than rev
        
        return rev.substr(0,rev.size()-next.back())+s;
        
    }
};
