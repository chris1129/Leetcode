//
//  main.cpp
//  471. Encode String with Shortest Length
//
//  Created by Sheng-Yung Cheng on 12/1/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
private:
    vector<vector<string>> dp;
public:
    string collapse(string& s, int i, int j) {
        
        string sub=s.substr(i,j-i+1);
        string temp=sub+sub;
        int pos=temp.find(sub,1);
        if(pos>=sub.size())return sub;
        
        return to_string(sub.size()/pos)+"["+dp[i][i+pos-1]+"]";
        
    }
    
    string encode(string s) {
        int n=s.size();
        dp=vector<vector<string>>(n,vector<string>(n,""));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                dp[i][j]=s.substr(i,j-i+1);
                for(int k=i;k<j;k++){
                    string left=dp[i][k];
                    string right=dp[k+1][j];
                    if(left.size()+right.size()<dp[i][j].size())
                        dp[i][j]=left+right;
                    
                    
                }
                string replace=collapse(s,i,j);
                if(replace.size()<dp[i][j].size()){
                    dp[i][j]=replace;
                }
                
            }
            
            
        }
        
        
        return dp[0][n-1];
    }
};
