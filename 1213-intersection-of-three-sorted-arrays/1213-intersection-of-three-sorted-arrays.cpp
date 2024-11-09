class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m;
        for(int i: arr1) m[i]++;
        for(int i: arr2) m[i]++;
        for(int i: arr3) m[i]++;
        
        vector<int> ans;
        for (auto& p: m)
            if (p.second == 3)
                ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
};