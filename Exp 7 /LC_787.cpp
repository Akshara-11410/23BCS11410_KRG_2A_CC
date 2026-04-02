class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ;i<flights.size();i++ ){
            int f = flights[i][0];
            int s = flights[i][1];
            int price = flights[i][2];
            adj[f].push_back({s,price});
        }
       queue<tuple<int,int,int>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,src,0});
        while(!pq.empty()){
            
                auto [stops,node,price] = pq.front();
                pq.pop();
                if(stops>k) continue;
                for(auto s : adj[node] ){
                    if(price + s.second < dist[s.first] ){
                        pq.push({stops + 1, s.first, price + s.second});
                        dist[s.first] = price + s.second;
                    }
                }
            
         
        }
        if(dist[dst] != INT_MAX)return dist[dst];
        return -1;


    }
};
