class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> seen;
        for (auto num : nums1) {
            seen[num] = 1;
        }
        for (auto num : nums2) {
            if (seen[num] == 1) {
                seen[num] = 2;
                ans.push_back(num);
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> ans;
//        sort(nums1.begin(), nums1.end()); 
//        sort(nums2.begin(), nums2.end()); 
//        int p1 = 0, p2 = 0;
//        while (p1 < nums1.size() && p2 < nums2.size()) {
//            if (nums1[p1] == nums2[p2]) {
//                if (ans.empty() || ans.back() != nums1[p1]) ans.push_back(nums1[p1]);
//                p1++;
//                p2++;
//            } else if (nums1[p1] < nums2[p2]) {
//                p1++;
//            } else if (nums1[p1] > nums2[p2]) {
//                p2++;
//            }
//        }
//        return ans;
//    }
//};