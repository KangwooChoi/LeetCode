class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            } 
            s.push(i);
        }
        return res;
    }
};
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        vector<int> ans;
//        int n = temperatures.size();
//        for (int i = 0; i < n; i++) {
//            for (int j = i+1; j < n; j++) {
//                if (temperatures[i] < temperatures[j]) {
//                    ans.push_back(j-i);
//                    break;
//                } 
//            }
//            if (ans.size() != i+1) ans.push_back(0);
//        }
//        return ans;
//    }
//};