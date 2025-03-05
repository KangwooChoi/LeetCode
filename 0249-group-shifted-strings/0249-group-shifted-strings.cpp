class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> hashToVec;
        string hashKey;
        for (string s : strings) {
            hashKey = getHash(s);
            hashToVec[hashKey].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : hashToVec) {
            ans.push_back(it.second);
        }
        return ans; 
    }
private:
    string getHash(string str) {
        string ret = "a";
        for (int i = 1; i < str.length(); i++) {
            ret += (str[i] - str[0] + 26) % 26 + 'a'; 
        }
        return ret;
    }
};