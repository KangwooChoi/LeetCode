class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int na = nums1.size(), nb = nums2.size();
        int n = na + nb;
        if (n % 2) {
            return solve(nums1, nums2, n/2, 0, na-1, 0, nb-1);
        } else {
            return 1.0 * (solve(nums1, nums2, n/2-1, 0, na-1, 0, nb-1) + solve(nums1, nums2, n/2, 0, na-1, 0, nb-1)) / 2;
        } 
    }
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd, int bStart, int bEnd) {
        if (aEnd < aStart) {
            return B[k-aStart];
        }
        if (bEnd < bStart) {
            return A[k-bStart];
        }
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex+1, bEnd);
            } else {
                return solve(A, B, k, aIndex+1, aEnd, bStart, bEnd);
            }
        } else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex-1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex-1);
            }

        }
        return -1;
    }
};