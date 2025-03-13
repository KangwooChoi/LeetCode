class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        // Iterate through nums
        for (int index = 0; index < n; index++) {
            // Iterate through queries while current index of nums cannot equal
            // zero
            while (sum + differenceArray[index] < nums[index]) {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index) {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};
//class Solution {
//public:
//    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//        int n = nums.size();
//        vector<int> dec(n+1,0); 
//        int step = 0;
//        if (helper(nums,dec)) return 0;
//        for (auto q : queries) {
//            int start = q[0], end = q[1], val = q[2];
//            dec[start] += val;
//            dec[end+1] -= val;
//            step++;
//            if (helper(nums, dec)) return step;
//        }
//        return -1;
//    }
//private:
//    bool helper(vector<int>& nums, vector<int>& dec) {
//        int decrease = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            decrease += dec[i];
//            if (nums[i] > decrease) return false; 
//        }
//        return true;
//    } 
//};