class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int to_right = 0;
        for (int i = 0; i < shift.size(); i++) {
            if (shift[i][0] == 0) to_right -= shift[i][1];
            if (shift[i][0] == 1) to_right += shift[i][1];
        }
        cout << to_right << endl;
        if (to_right >= 0) {
            to_right %= s.size(); 
            return s.substr(s.size() - to_right) + s.substr(0, s.size() - to_right);
        } else {
            int to_left = -to_right;
            to_left %= s.size();
            return s.substr(to_left) + s.substr(0, to_left);
        }
    }
};