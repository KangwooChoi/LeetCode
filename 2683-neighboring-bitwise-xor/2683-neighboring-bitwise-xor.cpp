class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> origin0(1,0);
        vector<int> origin1(1,1);
        //return DFS(derived, 0, origin0) || DFS(derived, 0, origin1);
        return DFS(derived, 0, 0, 0) || DFS(derived, 0, 1, 1);
    }
private:
    //bool DFS(vector<int>& derived, int index, vector<int> origin) {
    bool DFS(vector<int>& derived, int index, int start, int now) {
        if (derived.size() == index) {
            if (start == now) {
                return true;
            } else {
                return false;
            }
        }
        now = derived[index]^now;
        return DFS(derived, index+1, start, now);
    }
};