class Solution {
public:
    int jump(vector<int>& nums) {
        int maxcurr=0;//當前步數內可打的最遠距離
        int maxNext=0;//下一次可達最遠
        int ret=0;
        for(int i=0;i<nums.size();i++){
            maxNext=max(maxNext,i+nums[i]);
            if(maxcurr>=nums.size()-1)return ret;
            if(i==maxcurr){
                ret++;
                maxcurr=maxNext;
            }
            
        }
        //[2,3,1,1,4]
        //i=0 maxcurr=0 maxNext=2 i==maxcurr=>update maxcurr to 2 && ret++(ret=1)
        //i=1 maxcurr=2 maxNext=4 
        //i=2 maxcurr=2 maxNext=4 i==maxcurr=>update maxcurr to 4 && ret++(ret=2)
        //i=3 maxcurr==nums.size()-1 return ret=2
        return -1;
    }
};