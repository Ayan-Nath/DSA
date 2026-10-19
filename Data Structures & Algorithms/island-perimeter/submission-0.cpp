class Solution {
public:
int m,n;


    bool isPossible(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int &c){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) c++;
        return (i>=0&&i<m&&j>=0&&j<n&&grid[i][j]==1&&!visited[i][j]);
    }

    void DFS(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int &c){
        //marks this cell 
        visited[i][j]=true;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            if(isPossible(grid,visited,i+dx[k],j+dy[k],c)){
                DFS(grid,visited,i+dx[k],j+dy[k],c);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
     m=grid.size(),n=grid[0].size();
     int c=0;
     vector<vector<bool>> visited(m,vector<bool>(n,false));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&!visited[i][j]){
                DFS(grid,visited,i,j,c);
            }
        }
     }
     return c;
    }
};