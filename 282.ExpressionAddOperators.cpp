class Solution {
public:
    vector<string> addOperators(string num, int target) {
        string temp=string(1,num[0]);
        this->target=target;
        this->num=num;
        vector<string> ans;
        for(int i=0;i<num.size();i++){
            //initial state:cur_sum=0, cur_val=val, pre='+'(The fist value must be positive) 
            string val_s=num.substr(0,i+1);
            long val=stol(val_s);
            string temp=val_s;
            if(to_string(val).size()!=val_s.size())break;
            dfs(i+1,temp,0,val,'+',ans);
        }
        return ans;
    }
    
    void dfs(int start,string temp,long cur_sum,long cur_val,char pre,vector<string>&ans){
        if(start==num.size()){
            if(pre=='+'&&(cur_sum+=cur_val)==target){
                ans.push_back(temp);
                
            }else if(pre=='-'&&(cur_sum-=cur_val)==target){
                ans.push_back(temp);
            }
            return ;
        }
        
        for(int i=start;i<num.size();i++){
            string val_s=num.substr(start,i-start+1);
            long val=stol(val_s);
            if(to_string(val).size()!=val_s.size())break;//avoid val_s=050 but val=stol(050)=50
            //we don't need * as pre ,because we always complete '*' operand everytime (先乘除後加減)
            //ex: 1+2*3:i=4, cur_sum=1,cur_val=2,pre='+' val=3
            // next dfs:cur_sum=1,cur_val=2*3,pre='+'
            if(pre=='+'){
                //'*'
                dfs(i+1,temp+'*'+val_s,cur_sum,cur_val*val,'+',ans);
                //'+'
                dfs(i+1,temp+'+'+val_s,cur_sum+cur_val,val,'+',ans);
                //'-'
                dfs(i+1,temp+'-'+val_s,cur_sum+cur_val,val,'-',ans);
            }
            if(pre=='-'){
                //'*'
                dfs(i+1,temp+'*'+val_s,cur_sum,cur_val*val,'-',ans);
                //'+'
                dfs(i+1,temp+'+'+val_s,cur_sum-cur_val,val,'+',ans);
                //'-'
                dfs(i+1,temp+'-'+val_s,cur_sum-cur_val,val,'-',ans);
            }
        }
        
        
    }
    int target;
    string num;

};

                