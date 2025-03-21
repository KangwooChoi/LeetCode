class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};    
        if (rowIndex == 1) return {1, 1};    
        vector<int> ans;
        vector<int> temp = {1, 1};
        int p = 1;
        while (p++ < rowIndex) {
            ans = {};
            ans.push_back(1);
            for (int i = 0; i < temp.size() - 1; i++) {
                ans.push_back(temp[i]+temp[i+1]);
            }
            ans.push_back(1);
            temp = ans;
        }
        return ans;
    }
};