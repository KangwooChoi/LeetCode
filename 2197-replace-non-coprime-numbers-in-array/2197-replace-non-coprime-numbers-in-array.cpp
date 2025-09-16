class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = 1;
        for (int i = 1; i != nums.size(); ++i) {
            nums[n++] = nums[i];
            while (n > 1)
            {
                int& lv = nums[n-2];
                int rv = nums[n-1];
                int gcd = std::gcd(lv, rv);
                if (gcd > 1) {
                    lv = (lv/gcd) * rv;
                    --n;
                } else break;
            }
        }

        nums.resize(n);
        return std::move(nums);
    }
};