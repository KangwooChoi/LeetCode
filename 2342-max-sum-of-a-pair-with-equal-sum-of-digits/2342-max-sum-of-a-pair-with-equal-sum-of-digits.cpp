class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> umap;
        for (int num : nums) {
            int digitSum = convert(num); 
            umap[digitSum].push(num);
        }
        int ans = -1;
        for (auto [key, pq] : umap) {
            int temp = -1; 
            if (!pq.empty() && pq.size() >= 2) {
                temp = pq.top();
                pq.pop();
                temp += pq.top();
            }
            ans = max(ans, temp);
        }
        return ans;
    }
    int convert(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};