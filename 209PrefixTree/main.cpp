//
//  main.cpp
//  208. Implement Trie (Prefix Tree)
//
//  Created by Sheng-Yung Cheng on 10/11/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include<map>
using namespace std;
class TrieNode{
public:
    TrieNode(){
        endofword=false;
    }
    map<char,TrieNode*>hash;
    bool endofword;
    
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            
            if(curr->hash.find(word[i])==curr->hash.end()){
                TrieNode* node=new TrieNode();
                curr->hash.insert({word[i],node});
                curr=curr->hash[word[i]];
                
            }else{
                curr=curr->hash[word[i]];
            }
            if(i==word.size()-1){curr->endofword=true;}
            
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr=root;
        for(auto e:word){
            if(curr->hash.find(e)==curr->hash.end()){
                return false;
            }else{
                curr=curr->hash[e];
            }
            
        }
        if(curr->endofword==false)return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(auto e:prefix){
            if(curr->hash.find(e)==curr->hash.end()){
                return false;
            }else{
                curr=curr->hash[e];
            }
            
        }
        
        return true;
    }
private:
    TrieNode* root=new TrieNode();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
