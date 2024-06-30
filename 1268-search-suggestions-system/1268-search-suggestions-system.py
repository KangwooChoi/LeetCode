class Trie:
    def __init__(self):
        self.children = {}
        self.cached = set()
        self.end = False
    
    def insert(self, word: str) -> None:
        now = self
        now.cached.add(word)
        for c in word:
            if c not in now.children:
                now.children[c] = Trie()
            now = now.children[c]
            now.cached.add(word)
        now.end = True
    
    def search(self, prefix: str) -> List[str]:
        now = self
        for c in prefix:
            if c not in now.children:
                return []
            else:
                now = now.children[c]
        if now.cached:
            ans = sorted(list(now.cached))
            return ans[:3]
        else:
            return []
        

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie = Trie()
        for p in products:
            trie.insert(p)
        ans = [] 
        for i in range(len(searchWord)):
            ans.append(trie.search(searchWord[:i+1]))
        return ans
