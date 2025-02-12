class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);    
        vector<bool> visited(numCourses,false);    
        vector<vector<int>> presubj_subj(numCourses,vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            int subj = prerequisites[i][0], presubj = prerequisites[i][1];
            presubj_subj[presubj].push_back(subj);
            indegree[subj]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            vector<int> curr_presubj = presubj_subj[curr]; 
            for (int i = 0; i < curr_presubj.size(); i++) {
                int subj = curr_presubj[i];
                indegree[subj]--;
                if (indegree[subj] == 0) q.push(subj);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};