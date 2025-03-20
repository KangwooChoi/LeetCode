class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0, right = 0, up = 0, down = 0;
        for (char move : moves) {
            if (move == 'U') up++;
            else if (move == 'D') down++;
            else if (move == 'L') left++;
            else if (move == 'R') right++;
        } 
        return left == right && up == down;
    }
};