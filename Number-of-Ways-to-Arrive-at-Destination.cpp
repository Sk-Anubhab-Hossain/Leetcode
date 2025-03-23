class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        const int MOD = 1e9 + 7;
    
    // Build the graph (Adjacency List)
    for (const auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].emplace_back(v, time);
        graph[v].emplace_back(u, time);
    }
    
    // Distance and ways arrays
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    
    // Min-heap priority queue {distance, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (current_dist > dist[node]) continue;
        
        for (const auto& neighbor : graph[node]) {
            int next_node = neighbor.first;
            long long travel_time = neighbor.second;
            long long new_dist = current_dist + travel_time;
            
            if (new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                ways[next_node] = ways[node];
                pq.push({new_dist, next_node});
            } else if (new_dist == dist[next_node]) {
                ways[next_node] = (ways[next_node] + ways[node]) % MOD;
            }
        }
    }
    
    return ways[n - 1];
    }
};