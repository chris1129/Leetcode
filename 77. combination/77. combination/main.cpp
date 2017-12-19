//
//  main.cpp
//  77. combination
//
//  Created by Sheng-Yung Cheng on 12/18/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        helper(temp,1,n,k,ans);
        return ans;
        
    }
    void helper(vector<int>&temp,int start,int n,int k,vector<vector<int>>&ans){
        
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            helper(temp,i+1,n,k-1,ans);
            temp.pop_back();
            
        }
        
    }
};
