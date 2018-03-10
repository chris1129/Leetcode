//
//  main.cpp
//  PlaceIQ_coin_change
//
//  Created by Sheng-Yung Cheng on 3/9/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int coinchange(vector<int>&coins,int amount){
    vector<int>table(amount+1,0);
    for(int i=0; i<amount; i++)
        for(int j=coins[i]; j<=n; j++)
            table[j] += table[j-coins[i]];
    
    return table[n];
}
int main(int argc, const char * argv[]) {
    
    int am=11;
    vector<int>coins={1,3};
    unordered_map<int,int>hash;
    cout<<coinchange(coins,am,0,hash)<<endl;
}



