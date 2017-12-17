//
//  main.cpp
//  315. Count of Smaller Numbers After Self
//
//  Created by Sheng-Yung Cheng on 12/16/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class node{
public:
    int smaller_cnt;//number of smaller nodes which are on its left
    int val;// the value of this node
    int dup;// duplicate number of this node
    node* left;
    node* right;
    node(int v){
        this->val=v;
        this->smaller_cnt=0;
        this->right=NULL;
        this->left=NULL;
        this->dup=1;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        node* root=NULL;
        vector<int>ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            root=insert(nums[i],ans,root,i,0);
        }
        return ans;
    }
    node* insert(int num,vector<int>& ans,node* n,int i,int pre_smaller){
        if(n==NULL){
            n=new node(num);
            ans[i]=pre_smaller;
        }else if(n->val>num){// if going through the node larger than self
            n->smaller_cnt++;
            n->left=insert(num,ans,n->left,i,pre_smaller);
        }else if(n->val==num){
            
            n->dup++;
            ans[i]=pre_smaller+n->smaller_cnt;
        }else {
            //if going through the node smaller than self, add the node's smaller count and number of duplicate to pre_smaller
            n->right=insert(num,ans,n->right,i,n->smaller_cnt+n->dup+pre_smaller);
            
        }
        return n;
        
    }
};
