class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> idxStack;

        // Calculate left boundaries
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            left[currIdx] = idxStack.empty() ? -1 : idxStack.top();
            idxStack.push(currIdx);
        }

        // Clear the stack for reuse
        while (!idxStack.empty()) idxStack.pop();

        // Calculate right boundaries
        for (int currIdx = n - 1; currIdx >= 0; --currIdx) {
            while (!idxStack.empty() && nums[idxStack.top()] < nums[currIdx]) {
                idxStack.pop();
            }
            right[currIdx] = idxStack.empty() ? n : idxStack.top();
            idxStack.push(currIdx);
        }

        // Calculate the maximal range for each element
        vector<int> maxRanges(n);
        for (int currIdx = 0; currIdx < n; ++currIdx) {
            maxRanges[currIdx] = right[currIdx] - left[currIdx] - 1;
        }

        return maxRanges;
    }
};
//class Solution {
//public:
//    vector<int> maximumLengthOfRanges(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> left(n, 0); 
//        vector<int> right(n, 0); 
//        left[0] = nums[0];
//        right[n-1] = nums[n-1];
//        for (int i = 1; i < n; i++) {
//            left[i] = max(left[i-1], nums[i]);
//            right[n-1-i] = max(right[n-2-i], nums[n-1-i]);
//        }
//        int l = 0;
//        int r = n - 1;
//        vector<int> ans(n, 1);
//        for (int i = 0; i < n; i++) {
//            int curr = nums[i];
//            while (l <= i) {
//                int mid = (l + i) / 2;
//                if (left[mid] <= curr) {
//                    
//                }
//
//            }
//
//        }
//        return ans;
//    }
//};