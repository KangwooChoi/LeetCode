class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = nums[0];
        int loc = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > counter) {
                nums[loc] = nums[i];
                counter = nums[i];
                loc++;
            }
        }
        //for (int i = 0; i< nums.size(); i++) cout << nums[i] << endl;

        return loc;
    }
};