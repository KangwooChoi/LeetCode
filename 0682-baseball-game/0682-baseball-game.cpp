class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;    
        for (auto op : operations) { 
            if (op == "+") {
                int size = result.size();
                result.push_back(result[size-1] + result[size-2]);
            } else if (op == "D") {
                result.push_back(result.back()*2);
            } else if (op == "C") {
                result.pop_back();
            } else {
                result.push_back(stoi(op));
            }
        }
        int ans = 0;
        for (auto r : result) {
            ans += r;
        }
        return ans;
    }
};