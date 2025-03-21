class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // Store available supplies
        unordered_set<string> availableSupplies;
        // Map recipe to its index
        unordered_map<string, int> recipeToIndex;
        // Map ingredient to recipes that need it
        unordered_map<string, vector<string>> dependencyGraph;

        // Initialize available supplies
        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        // Count of non-supply ingredients needed for each recipe
        vector<int> inDegree(recipes.size(), 0);

        // Build dependency graph
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            for (string& ingredient : ingredients[recipeIdx]) {
                if (!availableSupplies.count(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Start with recipes that only need supplies
        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

        // Process recipes in topological order
        vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            // Skip if no recipes depend on this one
            if (!dependencyGraph.count(recipe)) continue;

            // Update recipes that depend on current recipe
            for (string& dependentRecipe : dependencyGraph[recipe]) {
                if (--inDegree[recipeToIndex[dependentRecipe]] == 0) {
                    queue.push(recipeToIndex[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};
//class Solution {
//public:
//    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//        unordered_map<string,vector<string>> ingreToRecipe;
//        unordered_map<string,unordered_map<string,bool>> recipeToIngre;
//        for (int i = 0; i < recipes.size(); i++) {
//            string r = recipes[i];
//            vector<string> ingre = ingredients[i];
//            for (auto ing : ingre) {
//                ingreToRecipe[ing].push_back(r);
//                recipeToIngre[r][ing] = false;
//            }
//        }
//        for (int i = 0; i < supplies.size(); i++) {
//            auto s = supplies[i];
//            auto rs = ingreToRecipe[s];
//            for (auto r : rs) {
//                recipeToIngre[r][s] = true;
//            }
//        }
//        vector<string> ans;
//        for (int i = 0; i < recipes.size(); i++) {
//            auto r = recipes[i];
//            auto is = recipeToIngre[r];
//            bool isComplete = true;
//            for (auto ingre : is) {
//                if (ingre.first == "") continue;
//                if (recipeToIngre[r].find(ingre) != recipToIngre[r].end() && recipeToIngre[r][ingre] == false) {
//                    isComplete = false;
//                    break;
//                } 
//            }
//            if (isComplete == true) ans.push_back(r);
//        }
//        return ans;
//    }
//};