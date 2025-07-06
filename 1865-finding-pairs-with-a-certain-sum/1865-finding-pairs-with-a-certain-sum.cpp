class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int,int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            cnt[num]++;
        }
    }
    
    void add(int index, int val) {
        cnt[nums2[index]]--;
        nums2[index] += val;
        cnt[nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            int remain = tot - num;
            if (cnt.count(remain)) ans += cnt[remain];
        }
        return ans;
    }
};
//class FindSumPairs {
//private:
//    vector<int> nums1;
//    vector<int> nums2;
//    int n1;
//    int n2;
//
//public:
//    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
//        this->nums1 = nums1;
//        this->nums2 = nums2;
//        n1 = nums1.size();     
//        n2 = nums2.size();
//    }
//    
//    void add(int index, int val) {
//        if (0 <= index && index < n2) {
//            nums2[index] += val;
//        } 
//    }
//    
//    int count(int tot) {
//        int ans = 0;
//        for (int i = 0; i < n1; i++) {
//            for (int j = 0; j < n2; j++) {
//                if (nums1[i] + nums2[j] == tot) ans++;
//            }
//        } 
//        return ans;
//    }
//};
//
///**
// * Your FindSumPairs object will be instantiated and called as such:
// * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
// * obj->add(index,val);
// * int param_2 = obj->count(tot);
// */