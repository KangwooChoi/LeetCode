class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> seq;
        vector<bool> used(tiles.length(), false);

        generateSeq(tiles, "", used, seq);
    
        return seq.size() - 1;     
    }

private:
    void generateSeq(string& tiles, string curr, vector<bool> used, unordered_set<string>& seq) {
        seq.insert(curr);
        for (int pos = 0; pos < tiles.length(); pos++) {
            if (!used[pos]) {
                used[pos] = true;
                generateSeq(tiles, curr + tiles[pos], used, seq);
                used[pos] = false;
            }
        }
    }
};