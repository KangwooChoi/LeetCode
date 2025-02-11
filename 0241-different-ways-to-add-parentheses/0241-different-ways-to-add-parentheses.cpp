class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if (expression.length() == 0) return ans;
        if (expression.length() == 1) {
            ans.push_back(stoi(expression));
            return ans;
        }
        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }
        for (int i = 0; i < expression.length(); i++) {
            char currChar = expression[i];
            if (isdigit(currChar)) continue;
            vector<int> leftResults = diffWaysToCompute(expression.substr(0,i));
            vector<int> rightResults = diffWaysToCompute(expression.substr(i+1));
            for (int leftVal : leftResults) {
                for (int rightVal : rightResults) {
                    int computeResult = 0;
                    switch (currChar) {
                        case '+':
                            computeResult = leftVal + rightVal;
                            break;
                        case '-':
                            computeResult = leftVal - rightVal;
                            break;
                        case '*':
                            computeResult = leftVal * rightVal;
                            break;
                    }
                    ans.push_back(computeResult);
                }
            }

        }
        return ans;
    }
};