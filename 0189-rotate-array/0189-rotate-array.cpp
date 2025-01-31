class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[(i+k)%n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = a[i];
        }
    }
};
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        k %= nums.size();
//        int temp, prev;
//        int n = nums.size();
//        for (int i = 0; i < k; i++) {
//            prev = nums[n-1];
//            for (int j = 0; j < n; j++) {
//                temp = nums[j];
//                nums[j] = prev;
//                prev = temp;
//            }
//        }
//    }
//};