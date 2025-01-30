class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        queue<int> q;
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            int post = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[post]++;
            adj[pre].push_back(post);
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                ans.push_back(curr);
                q.pop();
                for (int j = 0; j < adj[curr].size(); j++) {
                    int temp = adj[curr][j];
                    indegree[temp]--;
                    if (indegree[temp] == 0) {
                        q.push(temp);
                    }
                }
            }
        }
        return ans.size() != numCourses ? vector<int>() : ans; 
    }
};