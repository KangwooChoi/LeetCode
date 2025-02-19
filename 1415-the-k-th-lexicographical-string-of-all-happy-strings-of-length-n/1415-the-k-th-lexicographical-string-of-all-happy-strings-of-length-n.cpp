class Solution {
public:
    priority_queue<string, vector<string>, greater<string>> pq;

    string getHappyString(int n, int k) {
        backtrack(n, 0, "");
        while (--k > 0) {
            if (pq.empty()) return "";
            pq.pop();
        }
        return pq.empty() ? "" : pq.top();     
    }

private:  
    void backtrack(int n, int index, string res) {
        if (res.length() == n) {
            pq.push(res);
            return;
        }
        for (int i = 0; i < 3; i++) {
            char c = 'a' + i; 
            if (res.length() == 0) {
                backtrack(n, index+1, res+c);
                continue;
            }
            if (res.length() != 0 && res[res.length()-1] != c) {
                backtrack(n, index+1, res+c); 
            }
        }
        return;
    }
};