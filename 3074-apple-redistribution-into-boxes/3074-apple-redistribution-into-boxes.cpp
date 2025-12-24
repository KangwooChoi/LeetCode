class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (auto num : apple) {
            total += num;
        }
        sort(capacity.begin(), capacity.end(), greater<>());
        int ans = 0;
        for (auto cap : capacity) {
            total -= cap; 
            ans++;
            if (total <= 0) return ans;
        }
        return -1;
    }
};