class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;
    unordered_set<string> available(supplies.begin(), supplies.end());
    queue<string> q;
    vector<string> result;

    // Initialize in-degree and build the graph
    for (int i = 0; i < recipes.size(); i++) {
        inDegree[recipes[i]] = ingredients[i].size();
        for (const string& ing : ingredients[i]) {
            graph[ing].push_back(recipes[i]);  // Ingredient points to recipes
        }
    }

    // Add all initial supplies to the queue
    for (const string& supply : supplies) {
        q.push(supply);
    }

    // Process the queue
    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (inDegree.find(curr) != inDegree.end() && inDegree[curr] == 0) {
            result.push_back(curr);  // Add recipe to result
        }

        for (const string& recipe : graph[curr]) {
            if (--inDegree[recipe] == 0) {
                q.push(recipe);
            }
        }
    }

    return result;
    }
};