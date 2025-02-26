class NumArray {
public:
    vector<int> partsum;
    NumArray(vector<int>& nums) {
        partsum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            partsum.push_back(partsum.back()+nums[i]);
        } 
    }
    
    int sumRange(int left, int right) {
        int sumRight = partsum[right]; 
        int sumLeft = left == 0 ? 0 : partsum[left-1];
        return sumRight-sumLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */