//
//  main.cpp
//  127. Word Ladder
//
//  Created by Sheng-Yung Cheng on 10/19/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset;
        for(auto w:wordList)wordset.insert(w);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int ret=INT_MAX;
        
        while(!q.empty()){
            auto word_pair=q.front();
            string word=word_pair.first;
            if(word==endWord){
                ret=min(ret,word_pair.second);
            }
            q.pop();
            for(int i=0;i<word.size();i++){
                char temp=word[i];
                for(int j=0;j<26;j++){
                    word[i]=j+'a';
                    //cout<<word<<",";
                    if(wordset.find(word)!=wordset.end()){
                        wordset.erase(word);
                        q.push({word,word_pair.second+1});
                    }
                    
                }
                word[i]=temp;
                
                
            }
            
            
        }
        
        return ret==INT_MAX?0:ret;
    }
    
    
};
