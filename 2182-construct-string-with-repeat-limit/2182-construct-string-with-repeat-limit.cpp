class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};
//class Solution {
//public:
//    string repeatLimitedString(string s, int repeatLimit) {
//        vector<int> freqs(26, 0);
//        for (char c: s) {
//            int loc = c - 'a';
//            freqs[loc]++;
//        }
//        int first = 25, second = 25;
//        string answer = "";
//        bool flag = false;
//        while (first >= 0) {
//            int counter = repeatLimit;
//            while (freqs[first] > 0) {
//                // cout << freqs[first] << endl;
//                answer += 'a' + first;
//                freqs[first]--;
//                counter--;
//                // cout << counter << endl;
//                if (counter == 0) {
//                    second = first - 1;
//                    while (freqs[second] == 0 && second >= 0) second--;
//                    if (second < 0) {
//                        flag = true;
//                        break;
//                    }
//                    cout << second << endl;
//                    answer += 'a' + second;
//                    counter = repeatLimit;
//                    freqs[second]--;
//                }
//            }
//            
//            if (flag) break;
//            first--;
//        }
//        return answer;        
//    }
//};