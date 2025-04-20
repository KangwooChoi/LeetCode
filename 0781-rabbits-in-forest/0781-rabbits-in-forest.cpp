class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> umap;
        for (int i : answers) umap[i]++;
        int total = 0;
        for (auto& p : umap) {
            total += ceil((double)p.second / (p.first + 1)) * (p.first + 1); 
        }
        return total;
    }
};
//class Solution {
//public:
//    int numRabbits(vector<int>& answers) {
//        unordered_set<int> uset;
//        int cnt = 0;
//        for (int num : answers) {
//            if (num == 0) cnt++;
//            else uset.insert(num);
//        }
//        int ret = 0;
//        for (int distinct : uset) {
//            ret += distinct + 1;
//        }
//        return ret + cnt; 
//    }
//};