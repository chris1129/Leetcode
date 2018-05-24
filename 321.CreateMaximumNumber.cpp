class Solution {
public:
	//STEP 1 : Choose k1 nums from nums1 and k2 nums from nums2 that makes nums1 and nums2 be the max sequence of number, k1+k2=k
	//STEP 2 : Merge two sequence and make the combined sequence to be the max sequence
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int k1=0;k1<=k;k1++){
            int k2=k-k1;
            if(k1>n1||k2>n2)continue;
            ans = max(ans, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k2)));

        }
            
        return ans;
        
    }
    
    vector<int>maxNumber(vector<int>&nums,int k){
        //6758706 k=4 topop=7-4=3
        //return a vector of size k that is biggest  
        int topop=nums.size()-k;
        //3465 k=2 topop=2
        //6         topop=0
        //6 5       topop=0
        vector<int>ret;
        for(int i=0;i<nums.size();i++){
            while(ret.size()!=0&&ret.back()<nums[i]&&topop>0){
                ret.pop_back();
                topop--;
            }
            ret.push_back(nums[i]);  
        }
        
        return vector<int>(ret.begin(),ret.begin()+k);
    }
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        //get the max merge set from nums1 & nums2
        vector<int> ans;
        auto s1 = nums1.begin();
        auto e1 = nums1.end();
        auto s2 = nums2.begin();
        auto e2 = nums2.end();        
        while (s1 != e1 || s2 != e2)
            ans.push_back( lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
        //lexicographical_compare: true if the first range compares lexicographically less than than the second.
        return ans;
    }
    
    
};