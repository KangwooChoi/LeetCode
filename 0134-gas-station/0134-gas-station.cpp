class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGain = 0, totalGain = 0, ans = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];
            if (currGain < 0) {
                ans = i + 1;
                currGain = 0;
            }
        }
        return totalGain >= 0 ? ans : -1;
    }
};
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int n = cost.size();
//        int i = 0; 
//        while (i < n) {
//            int remain = 0;
//            bool flag = true;
//            for (int j = i; j < n + i; j++) {
//                remain = gas[j%n] - cost[j%n];
//                if (remain < 0) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == true) return i;
//            i++;
//        } 
//        return -1; 
//    }
//};