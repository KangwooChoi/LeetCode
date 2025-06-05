class Solution {
public:
    vector<int> parents;
    int find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }
    void perfUnion(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;
        if (x < y) {
            parents[y] = x;
        } else {
            parents[x] = y;
        }

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) {
            parents.push_back(i);
        }
        for (int i = 0; i < s1.size(); i++) {
            perfUnion(s1[i]-'a', s2[i]-'a');
        } 
        string ans;
        for (char c : baseStr) {
            ans += (char)(find(c-'a') + 'a');
        }
        return ans;
    }
};