class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = nums.size();
//        int left = 0, right = n - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] == target) return mid;
//            else if (nums[mid] >= nums[left]) {
//                if (nums[left] <= target && target < nums[mid]) {
//                    right = mid - 1;
//                } else {
//                    left = mid + 1;
//                }
//            } else {
//                if (target <= nums[right] && target > nums[mid]) {
//                    left = mid + 1;
//                } else {
//                    right = mid - 1;
//                }
//            }
//        }
//        return -1;
//    }
//};
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = nums.size();
//        if (n == 1) {
//            if (nums[0] == target) return 0;
//            return -1;
//        }
//        if (nums[0] < nums[n-1]) {
//            // increasing
//            int left = 0, right = n - 1;
//            while (left <= right) {
//                int mid = (left + right) / 2;
//                if (nums[mid] == target) return mid;
//                if (nums[mid] < target) {
//                    left = mid + 1;
//                } else {
//                    right = mid - 1;
//                }
//            } 
//            return -1;
//        } else {
//            int left = 0, right = n - 1;
//            int maxIndex = 0;
//            while (left <= right) {
//                int mid = (left + right) / 2;
//                if (nums[mid] > nums[mid+1]) maxIndex = mid;
//                left = mid + 1;
//            }
//            if (target >= nums[0]) {
//                left = 0, right = maxIndex;
//            } else {
//                left = maxIndex + 1, right = n -1;
//            }
//            while (left <= right) {
//                int mid = (left + right) / 2;
//                if (nums[mid] == target) return mid;
//                if (nums[mid] < target) {
//                    left = mid + 1;
//                } else {
//                    right = mid;
//                }
//            }
//            return -1;
//        }
//    }
//};