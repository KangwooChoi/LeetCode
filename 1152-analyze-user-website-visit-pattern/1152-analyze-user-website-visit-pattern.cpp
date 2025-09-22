class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, int> pattern_count;
        unordered_map<string, vector<pair<int,string>>> umap;     
        for (int i = 0; i < username.size(); i++) {
            umap[username[i]].push_back({timestamp[i], website[i]});
        }
        for (auto [k, v] : umap) {
            sort(v.begin(), v.end());
            unordered_set<string> patterns;
            triplet(v, patterns);
            for(const auto p : patterns) {
                pattern_count[p]++;
            }
        }
        int maxScore = 0;
        string maxPattern;
        for(auto [k, v] : pattern_count) {
            if (maxScore < v || (maxScore == v && k < maxPattern)) {
                maxScore = v;
                maxPattern = k;
            }
        }
        vector<string> ans;
        string word = "";
        for (char c : maxPattern) {
            if (c == '#') {
                ans.push_back(word);
                word = "";
                continue;
            } 
            word.push_back(c);
        }
        ans.push_back(word);
        return ans;
    }

private:
    void triplet(vector<pair<int,string>> v, auto& patterns) {
        int n = v.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    string p = v[i].second + "#" + v[j].second + "#" + v[k].second;
                    patterns.insert(p);
                }
            }
        }
    }
};