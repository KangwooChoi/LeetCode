class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            // Update max_so_far after updates to min_so_far to avoid
            // overwriting it
            max_so_far = temp_max;
            // Update the result with the maximum product found so far
            result = max(max_so_far, result);
        }

        return result;
    }
};
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int min_so_far = nums[0];
//        int max_so_far = nums[0];
//        int result = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            max_so_far = max({nums[i], min_so_far*nums[i], max_so_far*nums[i]});
//            min_so_far = min({nums[i], min_so_far*nums[i], max_so_far*nums[i]});
//            result = max(result, max_so_far);
//        }
//        return result; 
//    }
//};