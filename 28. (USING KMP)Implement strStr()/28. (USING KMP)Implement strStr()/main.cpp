//
//  main.cpp
//  28. (USING KMP)Implement strStr()
//
//  Created by Sheng-Yung Cheng on 11/30/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    
    vector<int> KMPpreprocessing(string pattern) {
        
        int index=0;
        vector<int>next(pattern.size(),0);
        for(int i=1;i<pattern.size();){
            if(pattern[i]==pattern[index]){
                next[i]=index+1;
                i++;
                index++;
                
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
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        vector<int>next=KMPpreprocessing(needle);
        //for(auto e:next)cout<<e<<",";
        int j=0;
        int i=0;
        while(i<haystack.size()&&j<needle.size()){
            if(haystack[i]==needle[j]){
                j++;
                i++;
                
            }else{
                if(j!=0)
                    j=next[j-1];
                else
                    i++;
            }
            if(j==needle.size())return i-needle.size();
            
        }
        
        
        return -1;
        
        
    }
};
