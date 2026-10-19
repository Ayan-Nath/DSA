class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &t : times){
            int u = t[0]-1;
            int v = t[1]-1;
            int w = t[2];
            adj[u].push_back({v,w});
        }
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        
        dist[k-1] = 0;
        pq.push({0, k-1});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &[v, w] : adj[node]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int ans = *max_element(dist.begin(), dist.end());
        
        return ans == INT_MAX ? -1 : ans;
    }
};