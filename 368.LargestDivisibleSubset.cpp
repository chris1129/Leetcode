// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

//nums={1,2,3,4,6,8}
//result={1,2,4,8}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //dp[n]:the longest subset with largest number nums[n];
        //ex:123468
        //123468
        //000000
        //01    parent[2]=>pos at 0
        //011   parent[3]=>pos at 0
        //0112  parent[4]=>pos at 1
        //01122 parent[6]=>pos at 1 or 2
        //011225parent[8]=>pos at 3
        if(nums.size()<2)return nums;
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),0);
        int max_len=0;
        int max_i=0;
        vector<int>parent;
        for(int i=0;i<nums.size();i++)parent.push_back(i);
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                    if(dp[i]>max_len){
                        max_len=dp[i];
                        max_i=i;
                    }
                }
            }
        }
        int pos=max_i;
        vector<int>ret;
        //use parent to trace back
        while(parent[pos]!=pos){
            ret.push_back(nums[pos]);
            pos=parent[pos];
        }
        ret.push_back(nums[pos]);
        reverse(ret.begin(),ret.end());
        
        return ret;
    }
    
};