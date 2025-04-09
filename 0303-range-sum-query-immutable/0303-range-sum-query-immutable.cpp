class NumArray {
public:
    vector<int> partsum;
    NumArray(vector<int>& nums) {
        partsum.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            partsum.push_back(partsum.back()+nums[i]);
        } 
    }
    
    int sumRange(int left, int right) {
        int sumRight = partsum[right+1]; 
        int sumLeft = partsum[left]; 
        return sumRight-sumLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */