class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurence = findBound(nums, target, true);
        if (firstOccurence == -1) return {-1,-1};
        int lastOccurence = findBound(nums, target, false);  
        return {firstOccurence, lastOccurence};
    }
private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int n = nums.size(); 
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (isFirst) {
                    if (left == mid || nums[mid-1] != target) return mid;
                    right = mid - 1;
                } else {
                    if (right == mid || nums[mid+1] != target) return mid;
                    left = mid + 1;
                }

            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }
};