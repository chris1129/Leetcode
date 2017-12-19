//
//  main.cpp
//  46. Permutation
//
//  Created by Sheng-Yung Cheng on 12/18/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        per(nums,0,ans);
        return ans;
        
    }
    
    
    void per(vector<int>&num,int begin,vector<vector<int>>&ans){
        
        if(begin>=num.size()){
            ans.push_back(num);
            return ;
        }
        for(int i=begin;i<num.size();i++){
            
            swap(num[begin],num[i]);
            per(num,begin+1,ans);
            swap(num[begin],num[i]);
        }
    }
};
