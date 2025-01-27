class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        for (auto edge : prerequisites) {
            isPrerequisite[edge[0]][edge[1]] = true;
        }

        for (int intermediate = 0; intermediate < numCourses; intermediate++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    // If src -> intermediate & intermediate -> target exists
                    // then src -> target will also exist.
                    isPrerequisite[src][target] =
                        isPrerequisite[src][target] ||
                        (isPrerequisite[src][intermediate] &&
                         isPrerequisite[intermediate][target]);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};
//class Solution {
//public:
//    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//        vector<vector<bool>> pre_map(numCourses, vector<bool>(numCourses,false));
//        for (int i = 0; i < prerequisites.size(); i++) {
//            int pre = prerequisites[i][0], post = prerequisites[i][1];
//            pre_map[post][pre] = true;
//            /* BFS */
//            queue<int> q;
//            vector<bool> visited(numCourses, false);
//            q.push(pre);
//            while(!q.empty()) {
//                int q_size = q.size();
//                for (int j = 0; j < q_size; j++) {
//                    visited[pre] = true;
//                    int curr = q.front();
//                    q.pop();
//                    if (visited[curr] == false) {
//                        pre_map[post][curr] = true;
//                        for (int k = 0; k < numCourses; k++) {
//                            if (visited[k] == false && pre_map[curr][k] == true)
//                            pre_map[post][k] = true;
//                            q.push(k);
//                            visited[k] = true;
//                        }
//                        visited[curr] = true; 
//                    }
//                }
//            }
//            //for (int j = 0; j < numCourses; j++) {
//            //    if (pre_map[pre][j] == true) pre_map[post][j] = true;
//            //    q.push(j);
//            //}
//            //for (int j = 0; j < numCourses; j++) {
//            //    if (pre_map[j][post] == true) {
//            //        pre_map[j][pre] = true;
//            //    }
//            //}
//        }
//        vector<bool> ans(queries.size(), false);
//        for (int k = 0; k < queries.size(); k++) {
//            int p = queries[k][0], q = queries[k][1];
//            if (pre_map[q][p] == true) ans[k] = true;
//        }
//        return ans; 
//    }
//};