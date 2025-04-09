class SparseVector {
public:
    vector<int> nums; 

    SparseVector(vector<int> &nums) {
        this->nums = nums;     
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ret = 0;
        vector<int> compare = vec.nums;
        for (int i = 0; i < compare.size(); i++) {
            ret += nums[i] * compare[i];
        } 
        return ret;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);