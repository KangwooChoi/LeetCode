class Solution {
public:
    bool hasMatch(string s, string p) {
        int loc = p.find('*');
        string pre = p.substr(0, loc);
        string post = p.substr(loc+1);
        int begin = s.find(pre);
        int end = s.rfind(post);
        return begin != -1 && end != -1 && begin+pre.length() <= end; 
    }
};