class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        // Initialize the result sequence with size 2*n - 1 filled with 0s
        vector<int> resultSequence(targetNumber * 2 - 1, 0);

        // Keep track of which numbers are already placed in the sequence
        vector<bool> isNumberUsed(targetNumber + 1, false);

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed,
                                             targetNumber);

        return resultSequence;
    }

private:
    // Recursive function to generate the desired sequence
    bool findLexicographicallyLargestSequence(int currentIndex,
                                              vector<int>& resultSequence,
                                              vector<bool>& isNumberUsed,
                                              int targetNumber) {
        // If we have filled all positions, return true indicating success
        if (currentIndex == resultSequence.size()) {
            return true;
        }

        // If the current position is already filled, move to the next index
        if (resultSequence[currentIndex] != 0) {
            return findLexicographicallyLargestSequence(
                currentIndex + 1, resultSequence, isNumberUsed, targetNumber);
        }

        // Attempt to place numbers from targetNumber to 1 for a
        // lexicographically largest result
        for (int numberToPlace = targetNumber; numberToPlace >= 1;
             numberToPlace--) {
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currentIndex] = numberToPlace;

            // If placing number 1, move to the next index directly
            if (numberToPlace == 1) {
                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }
            }
            // Place larger numbers at two positions if valid
            else if (currentIndex + numberToPlace < resultSequence.size() &&
                     resultSequence[currentIndex + numberToPlace] == 0) {
                resultSequence[currentIndex + numberToPlace] = numberToPlace;

                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }

                // Undo the placement for backtracking
                resultSequence[currentIndex + numberToPlace] = 0;
            }

            // Undo current placement and mark the number as unused
            resultSequence[currentIndex] = 0;
            isNumberUsed[numberToPlace] = false;
        }

        return false;
    }
};
//class Solution {
//public:
//    vector<int> constructDistancedSequence(int n) { 
//        vector<int> ans(2*n-1,0);
//        priority_queue<int> pq;
//        for (int i = 1; i <= n; i++) {
//            pq.push(i);
//        }
//        int index = 0;
//        while (!pq.empty()) {
//            int curr = pq.top();
//            if (curr == 1) {
//                ans[index] = 1;
//                pq.pop();
//                continue;
//            }
//            if (index+curr <= 2*n -2 && ans[index] == 0 && ans[index+curr] == 0) {
//                ans[index] = curr, ans[index+curr] = curr;
//            } else {
//                vector<int> temp;
//                temp.push_back(curr);
//                pq.pop();
//                curr = pq.top(); 
//                while (index+curr > 2*n - 2 || (ans[index] != 0 || ans[index+curr] != 0)) {
//                    if (curr == 1) break;
//                    temp.push_back(curr);
//                    pq.pop();
//                    curr = pq.top();
//                }
//                if (curr == 1) {
//                    ans[index] = 1;
//                } else {
//                    ans[index] = curr;
//                    ans[index+curr] = curr;
//                }
//                for (int i = 0; i < temp.size(); i++) {
//                    pq.push(temp[i]);
//                }
//            }
//            index++;
//        }
//        return ans;
//    }
//};