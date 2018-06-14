//Thinking:
//We try to find the max 3 non-overlapping subarray. 
//Let's say the 2nd subarray starts at index i. 
//If we know the leading index of maximun subarray from 0~i-1 and the leading index of maximun subarray from i+1~n, we can calculate the sum.
//posLeft[i]:The leading index of subarray such that the sum of the subarray is max in interval 0~i 
//posright[i]:The leading index of subarray such that the sum of the subarray is max in interval i~n
//ex:arr=   [1,2,1,2,6,7,5,1] k=2
//postLeft: [0,0,0,0,3,4,4,4]  explain: in interval [0,4], the maxsubarray is [2,6] so the leading index is at 3
//postright:[4,4,4,4,4,5,6,0]  explain: in interval [3,7], the maxsubarray is [6,7] so the leading index is at 4
//Try every combination of 3 subarray:
//  for i=k to i=n-2*k
//  when i=2: The index from postLeft[i-1] which is 0 and index from postRight[i+k] which is 4
//            The sum of left should be 1+2, the sum of mid should be 1+2, the sum of right should be 6+7  Total=19
//  when i=3: The index from postLeft[i-1] which is 0 and index from postRight[i+k] which is 5
//            The sum of left should be 1+2, the sum of mid should be 2+6, the sum of right should be 7+5   Total=23
//  when i=4  The index from postLeft[i-1] which is 0 and index from postRight[i+k] which is 6
//            The sum of left should be 1+2, the sum of mid should be 6+7, the sum of right should be 5+1   Total=22
//  i=3 gives us the max total sum, so the ans={0,3,5}

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>posLeft(n,0);
        vector<int>posRight(n,0);
        
        vector<int>sum;
        int cur=0;
        for(auto num:nums){
            cur+=num;
            sum.push_back(cur);
        }
        
        //build posleft
        for(int i=k-1, Max=INT_MIN;i<posLeft.size();i++){
            int curSum=(i-k)>=0?(sum[i]-sum[i-k]):sum[i];
            if(curSum>Max){
                posLeft[i]=i-k+1;
                Max=curSum;
            }else{
                posLeft[i]=posLeft[i-1];
            }
            
        }
        // for(auto l:posLeft)cout<<l<<",";
        // cout<<endl;
        
        //build posRight
        for(int i=n-k,Max=INT_MIN;i>=0;i--){
            int curSum=(i-1)>=0?sum[i+k-1]-sum[i-1]:sum[i+k-1];
            if(curSum>=Max){
                posRight[i]=i;
                Max=curSum;
            }else{
                posRight[i]=posRight[i+1];
            }
            
        }
        // for(auto l:posRight)cout<<l<<",";
        // cout<<endl;
        //find max
        vector<int>ret;
        int Max=INT_MIN;
        for(int i=k;i<=n-2*k;i++){
            int l=posLeft[i-1];
            int r=posRight[i+k];
            int sumL=sum[l+k-1]-(l-1>=0?sum[l-1]:0);
            int sumR=sum[r+k-1]-sum[r-1];
            int sumMid=sum[i+k-1]-sum[i-1];
            //cout<<"l="<<l<<" val="<<sumL<<",mid="<<i<<" val="<<sumMid<<",r="<<r<<" val="<<sumR<<endl;
            if((sumL+sumR+sumMid)>Max){
                ret={l,i,r};
                Max=(sumL+sumR+sumMid);
            }
        }
        return ret;
    }
};