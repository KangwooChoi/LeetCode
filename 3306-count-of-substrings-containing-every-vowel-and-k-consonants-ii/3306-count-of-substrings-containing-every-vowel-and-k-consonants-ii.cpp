class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        // Keep track of counts of vowels and consonants.
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        // Start sliding window.
        while (end < word.length()) {
            // Insert new letter.
            char newLetter = word[end];

            // Update counts.
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            // Shrink window while we have a valid substring.
            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
//class Solution {
//public:
//    long long countOfSubstrings(string word, int k) {
//        unordered_map<char,int> umap;
//        long long ans = 0;
//        long long vowCnt = 0;
//        int left = 0, right = 0;
//        while (right < word.length()) {
//            char c = word[right];
//            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//                umap[c]++;
//                vowCnt++; 
//            }
//            while (umap.size() == 5 && right - left + 1 > vowCnt + k) {
//                char c = word[left++];
//                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//                    umap[c]--;
//                    vowCnt--; 
//                    if (umap[c] == 0) umap.erase(c);
//                }
//            }
//            if (umap.size() == 5 && right - left + 1 == vowCnt + k) ans++;
//            right++;
//        } 
//        while (left < word.length()) {
//            char c = word[left++];
//            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
//                umap[c]--;
//                vowCnt--; 
//                if (umap[c] == 0) umap.erase(c);
//            }
//            if (umap.size() == 5 && right - left == vowCnt + k) ans++;
//            else break;
//        }
//        return ans; 
//    }
//};