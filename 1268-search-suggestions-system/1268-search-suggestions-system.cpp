class Trie {
    struct Node {
        bool isWord = false;
        vector<Node*> children{vector<Node*>(26,NULL)};
    } *Root, *curr;

    void dfsWithPrefix(Node* curr, string& word, vector<string>& res) {
        if (res.size() == 3) return;
        if (curr->isWord) res.push_back(word);
        for (char c = 'a'; c <= 'z'; c++) {
            if (curr->children[c-'a']) {
                word += c;
                dfsWithPrefix(curr->children[c-'a'], word, res);
                word.pop_back();
            }
        }
    }

public:
    Trie() {
        Root = new Node();
    } 
    void insert(string& s) {
        curr = Root;
        for (char& c: s) {
            if (!curr->children[c-'a']) curr->children[c-'a'] = new Node();
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }
    vector<string> getWordStartingWith(string& prefix) {
        curr = Root;
        vector<string> res;
        for (char& c : prefix) {
            if (!curr->children[c-'a']) return res;
            curr = curr->children[c-'a'];
        }
        dfsWithPrefix(curr, prefix, res);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        vector<vector<string>> ans;

        for (string& w : products) {
            trie.insert(w);
        }
        string prefix;
        for (char& c: searchWord) {
            prefix += c;
            ans.push_back(trie.getWordStartingWith(prefix));
        }
        return ans; 
    }
};