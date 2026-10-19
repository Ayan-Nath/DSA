class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> adjList(n);

       for(auto it: flights){
        int u=it[0],v=it[1],w=it[2];
        adjList[u].push_back({v,w});
       } 

       vector<int> dist(n,INT_MAX);
       dist[src]=0;
       queue<tuple<int,int,int>> q;
       q.push({0,0,src});
       while(!q.empty()){
        auto[stops,dis,node]=q.front();
        q.pop();
        for(auto it:adjList[node]){
            int nbrNode=it.first;
            int nbrW=it.second;
            if(stops<=k){
                if(nbrW+dis<dist[nbrNode]){
                    dist[nbrNode]=dis+nbrW;
                    q.push({stops+1,dist[nbrNode],nbrNode});
                }
            }
        }
       }


       return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
