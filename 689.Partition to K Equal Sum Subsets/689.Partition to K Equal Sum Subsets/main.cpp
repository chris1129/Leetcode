//
//  main.cpp
//  689.Partition to K Equal Sum Subsets
//
//  Created by Sheng-Yung Cheng on 10/16/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0)return false;
        target/=k;
        unordered_map<int,int>hash;
        
        for(auto e:nums){
            hash[e]++;
            
            
        }
        
        bool is_find=false;
        dfs(nums,hash,target,k,target,is_find,0);
        if(is_find)return true;
        return false;
        
    }
    
    
    void dfs(vector<int>& nums,unordered_map<int,int>& hash,int target,int k,int initial_target,bool& is_find,int start){
        //for(auto it:hash){cout<<"("<<it.first<<","<<it.second<<")";}
        //cout<<"tar="<<target<<"k="<<k;
        //cout<<endl;
        
        if(hash[target]>0){
            hash[target]--;
            k--;
            if(k==0){
                is_find=true;
                return;
            }
            dfs(nums,hash,initial_target,k,initial_target,is_find,0);
            hash[target]++;
            k++;
            
        }
        for(int i=start;i<nums.size();i++){
            if(hash[nums[i]]>0&&nums[i]<target){
                hash[nums[i]]--;
                dfs(nums,hash,target-nums[i],k,initial_target,is_find,i+1);
                if(is_find)break;
                hash[nums[i]]++;
                
            }
            
        }
        
        
    }
};
