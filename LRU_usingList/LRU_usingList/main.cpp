//
//  main.cpp
//  LRU_usingList
//
//  Created by Sheng-Yung Cheng on 10/18/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        
        auto it=mp.find(key);
        if(it==mp.end())return -1;
        cache.splice(cache.begin(),cache,it->second);
        
        return it->second->second;
        
    }
    
    void put(int key, int value) {
        
        //cout<<"capacity="<<capacity<<endl;
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second->second=value;
            cache.splice(cache.begin(),cache,it->second);
            
            return ;
        }
        
        if(cache.size()<capacity){
            cache.push_front({key,value});
            mp[key]=cache.begin();
            //capacity++;
            
            return;
            
            
        }else{
            auto it=cache.back();
            cache.pop_back();
            cache.push_front({key,value});
            mp[key]=cache.begin();
            mp.erase(it.first);
            
            return;
            
        }
        
        
    }
private:
    int capacity;
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
