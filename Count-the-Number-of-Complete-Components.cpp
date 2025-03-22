class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n); // Graph adjacency list

        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // DFS function to traverse a connected component
        function<void(int, unordered_set<int>&)> dfs = [&](int node, unordered_set<int>& component) {
            visited[node] = true;
            component.insert(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };

        // Iterate over all nodes to find all connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_set<int> component;
                dfs(i, component); // Find component

                // Check if the component is a complete graph
                int size = component.size();
                int expectedEdges = (size * (size - 1)) / 2;
                int actualEdges = 0;

                for (int node : component) {
                    actualEdges += adj[node].size();
                }
                actualEdges /= 2; // Each edge counted twice

                if (actualEdges == expectedEdges) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};