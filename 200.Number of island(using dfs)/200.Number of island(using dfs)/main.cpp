//
//  main.cpp
//  200.Number of island(using dfs)
//
//  Created by Sheng-Yung Cheng on 10/19/17.
//  Copyright © 2017 Sheng-Yung Cheng. All rights reserved.
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'&&visited[i][j]==0){
                    dfs(visited,grid,i,j);
                    count++;
                    
                }
            }
            
            
        }
        
        return count;
        
    }
    
    
    void dfs(vector<vector<bool>>&visited,vector<vector<char>>& grid,int i,int j){
        if(visited[i][j]==true)return;
        visited[i][j]=true;
        if(i+1<grid.size()&&grid[i+1][j]=='1')dfs(visited,grid,i+1,j);
        if(i-1>=0&&grid[i-1][j]=='1')dfs(visited,grid,i-1,j);
        if(j+1<grid[i].size()&&grid[i][j+1]=='1')dfs(visited,grid,i,j+1);
        if(j-1>=0&&grid[i][j-1]=='1')dfs(visited,grid,i,j-1);
        
        
        
    }
};
