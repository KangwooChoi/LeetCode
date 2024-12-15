class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain of adding an extra student
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        // Max heap to store (-gain, passes, totalStudents)
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};
//class Solution {
//public:
//    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//        priority_queue<pair<double, pair<int, int>>> pq; 
//        int n = classes.size();
//        double ans = 0;
//        double increase = 0;
//        for (auto pass_stu : classes) {
//            increase = (double)(pass_stu[0] + 1) / (pass_stu[1] + 1) - (double)pass_stu[0] - pass_stu[1];
//            pq.push({increase, {pass_stu[0], pass_stu[1]}});
//        }
//        for (int i = 0; i < extraStudents; i++) {
//            auto [increase, classinfo] = pq.top(); 
//            pq.pop();
//            int passes = classinfo.first;
//            int total = classinfo.second;
//            increase = (double)(passes + 1) / (total + 1) - (double)passes - total;
//            pq.push({increase, {passes + 1, total + 1}});
//        }
//        while(!pq.empty()) {
//            auto [_, classinfo] = pq.top();
//            pq.pop();
//            ans += (double)classinfo.first / classinfo.second;
//        }
//        return ans / n;
//    }
//};