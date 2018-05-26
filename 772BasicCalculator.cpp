class Solution {
public:
    int calculate(string s) {
        //priority +or-   *or/  false
        stack<char>ops;
        stack<int>nums;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(!isdigit(s[i])){
                if(s[i]=='('){
                    ops.push(s[i]);       
                }else if(s[i]==')'){
                    while(ops.top()!='('){
                        char op=ops.top();ops.pop();
                        int right=nums.top();nums.pop();
                        int left=nums.top();nums.pop();
                        nums.push(cal(left,right,op));
                    }
                    ops.pop();//pop '('
                }else{//+ - * /
                    if(ops.empty()){
                        ops.push(s[i]);
                        continue;
                    }
                    while(!ops.empty()&&priority(ops.top(),s[i])){
                        char op=ops.top();ops.pop();
                        int right=nums.top();nums.pop();
                        int left=nums.top();nums.pop();
                        nums.push(cal(left,right,op));
                    }
                    ops.push(s[i]);
                }
            }else{
                int temp=0;
                while(isdigit(s[i])){
                    temp=temp*10+(s[i]-'0');
                    i++;
                }
                i--;
                nums.push(temp);
            }
        }
        while(!ops.empty()){
            char op=ops.top();ops.pop();
            int right=nums.top();nums.pop();
            int left=nums.top();nums.pop();
            nums.push(cal(left,right,op));
        }
        
        
        return nums.top();
    }
    int cal(int l,int r,int op){
        if(op=='+'){
            return l+r;
        }else if(op=='-'){
            return l-r;
        }else if(op=='*'){
            return l*r;
        }else{
            return l/r;
        }
    }
    bool priority(char op1,char op2){
        if(op1=='(')return false;
        if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/'))return false;
        return true;
    }
    
    
};