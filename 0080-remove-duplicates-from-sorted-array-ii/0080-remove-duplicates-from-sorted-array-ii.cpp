class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 1;     // Pointer for current index in the array
        int count = 1; // Count of the current element occurrences

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j - 1]) {
                count++; // Increment count for the current element
            } else {
                count = 1; // Reset count for new element
            }

            if (count <= 2) {
                nums[i++] = nums[j]; // Update the array in place
            }
        }

        return i; // Return the new array length
    }
};
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int n = nums.size();
//        if (n <= 2) return n;
//        int prev = nums[0];
//        int cnt = 1;
//        int p = 1; 
//        for (int i = 1; i < n; i++) {
//            if (nums[i] != nums[i-1]) {
//                nums[p++] = nums[i];
//                cnt = 1;
//            } else {
//                if(++cnt <= 2) {
//                    nums[p++] = nums[i];
//                } 
//            }
//        }
//        return p;
//    }
//};