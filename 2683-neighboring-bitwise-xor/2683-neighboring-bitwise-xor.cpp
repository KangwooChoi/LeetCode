class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return DFS(derived, 0, 0, 0) || DFS(derived, 0, 1, 1);  
    }
    bool DFS(vector<int>& derived, int index, int start, int current) {
        if (index == derived.size() - 1) {
            if (start == current^derived[index]) return true;
            else return false;
        } 
        return DFS(derived, index+1, start, current^derived[index]);
    }
};