//
//  main.cpp
//  LRU
//
//  Created by Sheng-Yung Cheng on 7/2/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//
//
//  main.cpp
//  test
//
//  Created by Sheng-Yung Cheng on 5/22/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//
#include<iostream>
#include<unordered_map>

using namespace std;
class Keyvalue{
public:
    int key;
    int value;
    Keyvalue* next;
    Keyvalue* prev;
    Keyvalue(int key,int value){
        this->key=key;
        this->value=value;
    }
    Keyvalue(){
        this->next=NULL;
        this->key=0;
        this->value=0;
        
    }
    
    
};

class LRUCache {
    
public:
    Keyvalue* head;
    Keyvalue* tail;
    void show_head_tail(){
        
        cout<<"head->next:"<<head->next->key<<endl;
        cout<<"tail->next:"<<tail->next->key<<endl;
    }
    unordered_map<int,Keyvalue*>map;
    LRUCache(int capacity) {
        //cout<<"LRUCache"<<endl;
        this->cpcty=capacity;
        this->head=new Keyvalue();
        //this->tail=new Keyvalue();
        head->prev=NULL;
        //cout<<"LRU_end";
    }
    
    int get(int key) {
        cout<<"get"<<key<<endl;
        if(map.find(key)==map.end()) {cout<<"not found"<<endl;return -1;}
        
        move_to_tail(map[key]);
        cout<< map[key]->value<<endl;
        
        
        return map[key]->value;
    }
    
    void move_to_tail(Keyvalue* node){
        if(head->next==tail)return;
        // cout<<"mtt():"<<node->key<<endl;
        if (tail==node)return;
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->prev=tail;
        tail->next=node;
        tail=node;
        node->next=NULL;
        
        
    }
    
    void put(int key, int value) {
        cout<<"put"<<key<<","<<value<<endl;
        Keyvalue* node=new Keyvalue(key,value);
        
        if(map.find(key)!=map.end()){
            map[key]->value=value;
            move_to_tail(map[key]);
        }else{
            
            if(map.size()==0){
                //cout<<"map size=0"<<endl;
                head->next=node;
                tail=node;
                node->prev=head;
                map[key]=node;
                //cout<<"node->prev:"<<node->prev->key;
            }else{
                map[key]=node;
                //move_to_tail(node);
                tail->next=node;
                node->prev=tail;
                tail=node;
                node->next=NULL;
                
                if(cpcty<map.size()){
                    //cout<<"head->next->key="<<head->next->key<<" tail->next->key="<<tail->next->key<<endl;
                    map.erase(head->next->key);
                    //cout<<"erase"<<"size="<<map.size()<<endl;
                    head->next=head->next->next;
                    head->next->prev=head;
                }
            }
        }
        //cout<<"node->prev:"<<node->prev->key;
    }
    void show_node(int key){
        cout<<"show node():"<<endl;
        cout<<"map["<<key<<"]->key"<<map[key]->key<<endl;
        cout<<"map prev:"<<map[key]->prev->value<<endl;
    }
    void show_list(){
        Keyvalue* temp=head;
        while(temp->next!=NULL){
            cout<<temp->next->value<<",";
            temp=temp->next;
        }
        cout<<endl;
    }
    void show_prev(){
        Keyvalue* temp=tail;
        while(temp->prev!=NULL){
            cout<<temp->value<<",";
            temp=temp->prev;
        }
        cout<<endl;
    }
private:
    int cpcty=0;
};


int main(){
    
    unordered_map<int, string>map;
    LRUCache LRU= LRUCache(2);
    LRU.get(2);
    LRU.put(2, 6);
    //LRU.put(2, 2);
    LRU.get(1);
    
    LRU.put(1, 5);
    LRU.show_list();
    LRU.put(1, 2);
    
    LRU.get(2);
    LRU.get(1);
    //LRU.get(1);
    //LRU.show_head_tail();
    //LRU.show_node(4);
    //LRU.put(5, 5);
    LRU.show_list();
    cout<<endl;
    LRU.show_prev();
    
    
    
    
}
