class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(capacity==0)return -1;
        if(data_map.find(key)==data_map.end())return -1;
        feq_map[data_map[key].second].erase(iter_map[key]);
        data_map[key].second++;
        feq_map[data_map[key].second].push_back(key);
        iter_map[key]=--feq_map[data_map[key].second].end();
        
        while(feq_map[min_feq].size()==0)min_feq++;
        
        // print("Operation: get:"+to_string(key));
        return data_map[key].first;
    }
    
    void put(int key, int value) {
        if(capacity==0)return ;
        int storage=get(key);
        if(storage!=-1){//exist in map, update it
            data_map[key].first=value;
            return ;
        }
        if(size>=capacity){
            //erase min feq from feq_map
            auto temp=feq_map[min_feq].front();
            
            iter_map.erase(temp);
            data_map.erase(temp);
            feq_map[min_feq].pop_front();
            //size--
            size--;
        }
        //add new data
        data_map.insert({key,{value,1}});
        feq_map[1].push_back(key);
        min_feq=1;
        iter_map[key]=--feq_map[1].end();
        size++;
        //print("Operation: put"+to_string(key)+","+to_string(value));
    }
    void print(string s){
        cout<<s<<endl;
        for(auto h:data_map){cout<<"k="<<h.first<<" ,val="<<h.second.first<<" ,feq="<<h.second.second<<endl;};
        for(auto fm:feq_map){
            cout<<"feq "<<fm.first<<"'s list:";
            for(auto l:fm.second)cout<<l<<"->";
            cout<<endl;
        }
        cout<<"min_feq="<<min_feq<<endl;
        cout<<"min_feq.size()=="<<feq_map[min_feq].size()<<endl;
        
    }
private:
    unordered_map<int,pair<int,int>>data_map;//key,{val,feq}
    unordered_map<int,list<int>>feq_map;
    unordered_map<int,list<int>::iterator>iter_map;
    int size=0;
    int capacity=0;
    int min_feq=0;
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
