class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        for (int i = 0; i < nums2.size(); i++) {
            umap[nums2[i]] = -1;
            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[i] < nums2[j]) {
                    umap[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(umap[nums1[i]]);
        }
        return ans; 
    }
};