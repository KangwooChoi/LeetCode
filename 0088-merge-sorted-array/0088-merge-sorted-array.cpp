class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
        for (int i = m+n-1; i >= 0; i--) {
            if (p1 >= 0 && p2 >= 0) {
                if (nums1[p1] <= nums2[p2]) {
                    nums1[p3--] = nums2[p2--];
                } else {
                    nums1[p3--] = nums1[p1--];
                }
            } else if (p1 >= 0) {
                nums1[p3--] = nums1[p1--];
            } else if (p2 >= 0) {
                nums1[p3--] = nums2[p2--];
            }
        }
    }
};