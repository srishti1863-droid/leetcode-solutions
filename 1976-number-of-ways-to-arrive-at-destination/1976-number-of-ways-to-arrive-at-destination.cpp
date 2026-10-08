class Solution { 
public: 
    int countPaths(int n, vector<vector<int>>& roads) { 

        vector<vector<pair<int,int>>> adj(n); 

        // create an adjacency list
        for(int i = 0; i < roads.size(); i++){ 
            int u = roads[i][0]; 
            int v = roads[i][1]; 
            int time = roads[i][2]; 

            adj[u].push_back({v, time}); 
            adj[v].push_back({u, time}); 
        } 

        // {distance, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq; 

        vector<long long> dist(n, 1e18); 
        vector<int> ways(n, 0); 

        dist[0] = 0; 
        ways[0] = 1; 

        pq.push({0, 0}); 

        int mod = 1e9 + 7; 

        while(!pq.empty()){ 

            long long dis = pq.top().first; 
            int node = pq.top().second; 
            pq.pop(); 

            // Ignore old/outdated distance
            if(dis > dist[node])
                continue;

            for(auto it : adj[node]){ 

                int adjNode = it.first; 
                int edW = it.second; 

                // Found a shorter path
                if(dis + edW < dist[adjNode]){ 

                    dist[adjNode] = dis + edW; 

                    pq.push({dist[adjNode], adjNode}); 

                    ways[adjNode] = ways[node]; 
                } 

                // Found another shortest path
                else if(dis + edW == dist[adjNode]){ 

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod; 
                } 
            } 
        } 

        return ways[n - 1] % mod; 
    } 
};