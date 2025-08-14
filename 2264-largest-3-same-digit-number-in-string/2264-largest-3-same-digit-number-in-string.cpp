class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> candidates;
        candidates.push_back("999");     
        candidates.push_back("888");     
        candidates.push_back("777");     
        candidates.push_back("666");     
        candidates.push_back("555");     
        candidates.push_back("444");     
        candidates.push_back("333");     
        candidates.push_back("222");     
        candidates.push_back("111");     
        candidates.push_back("000");     
        for (auto cand : candidates) {
            for (int i = 0; i < num.length()-2; i++) {
                if (cand == num.substr(i,3)) return cand;
            }
        }
        return "";
    }
};