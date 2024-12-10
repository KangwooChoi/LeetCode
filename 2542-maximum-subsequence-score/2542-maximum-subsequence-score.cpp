class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n=nums1.size();
        long long ans=0,sum=0;
        priority_queue<int,vector<int>,greater<>>pq;
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<>());

        int i=0,j=0;
        while(j<n){
            sum+=v[j].second;
            pq.push(v[j].second);

            if(j-i+1<k){
                j++;
            }
            else{
                ans=max(ans,sum*v[j].first);
                sum-=pq.top();
                pq.pop();
                i++;
                j++;
            }
        }

        return ans;

    }
};
//class Solution {
//public:
//    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//        sort(nums1.begin(), nums1.end(), greater<int>());
//        sort(nums2.begin(), nums2.end(), greater<int>());
//        int m = 0;
//        int n = 1'000'000'007;
//        for (int i = 0; i < k; i++) {
//            cout << nums1[i] << endl;
//            m = m + nums1[i];
//            cout << nums2[i] << endl;
//            n = min(n, nums2[i]);
//        }
//        return m*n;
//    }
//};