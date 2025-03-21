class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        for (int i = 0; i < recipes.size(); i++) {
            for (const string& ingredient : ingredients[i]) {
                if (available.find(ingredient) == available.end()) {
                    graph[ingredient].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (const string& recipe : recipes) {
            if (indegree[recipe] == 0) {
                q.push(recipe);
            }
        }

        vector<string> result;
        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            result.push_back(recipe);
            available.insert(recipe);
            
            for (const string& next : graph[recipe]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }
};

