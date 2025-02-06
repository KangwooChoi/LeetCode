class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size(); 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int index = nums[i] * nums[j];
                freq[index]++;
            }
        }
        for (auto num_f : freq) {
            int index = num_f.first, f = num_f.second;
            if (f >= 2) {
                int temp = 4 * f * (f - 1);
                ans += temp;
            }
        }
        return ans;
    }
};