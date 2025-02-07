class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballToCol;
        unordered_map<int,int> colToFreq;
        set<int> colors;
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballToCol[ball] != 0) {
                int prev = ballToCol[ball];
                if (--colToFreq[prev] == 0) colors.erase(prev);
            }
            ballToCol[ball] = color;
            if (++colToFreq[color] == 1) colors.insert(color);
            ans.push_back(colors.size());
        } 
        return ans;
    }
};