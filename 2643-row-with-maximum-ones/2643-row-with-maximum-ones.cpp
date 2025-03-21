class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) cnt++; 
            }
            pq.push({cnt, -i});
        }    
        return {-pq.top().second, pq.top().first};
    }
};