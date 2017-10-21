//
//  main.cpp
//  218 The skyline problem
//
//  Created by Sheng-Yung Cheng on 10/21/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    typedef pair<int,int>Event;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> ret;
        vector<Event>vec;
        for(auto b:buildings){
            Event e={b[0],b[2]};//Represent Entering by positive height
            Event l={b[1],-1*b[2]};//Represent leaving by negative height
            vec.push_back(e);
            vec.push_back(l);
            
        }
        
        
        sort(vec.begin(),vec.end(),[](const Event& l,const Event& r){//deal with special case of equal x 
            if(l.first==r.first)return l.second>r.second;
            return l.first<r.first;
        });
        
        for(auto v:vec){
            //cout<<"("<<v.first<<","<<v.second<<")";
            //cout<<"max height="<<this->max_height()<<endl;
            
            if(v.second>0){
                
                if(v.second>this->max_height())ret.emplace_back(v.first,v.second);
                mset.insert(v.second);
                
                
            }else if(v.second<0){
                v.second=abs(v.second);
                mset.erase(mset.equal_range(v.second).first);//using erase(iterator pos) will only erase single val in multiset
                if(abs(v.second)>this->max_height()){
                    ret.emplace_back(v.first,this->max_height());
                }
                
                
            }
            /*
             cout<<"mset=>";
             for(auto e:mset)cout<<e<<",";
             cout<<endl;
             cout<<"ans=>";
             for(auto a:ret)cout<<"("<<a.first<<","<<a.second<<")";
             cout<<endl;
             */
        }
        return ret;
        
    }
private:
    multiset<int>mset;
    int max_height(){
        if(mset.size()==0)return 0;
        return *mset.rbegin();
    }
};
