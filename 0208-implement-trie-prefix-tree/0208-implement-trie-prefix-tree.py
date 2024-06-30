class Trie:

    def __init__(self):
        self.children = {}
        self.end = {}
        self.count = 1 
        

    def insert(self, word: str) -> None:

        now = self

        for c in word:
            if c in now.children:
                now = now.children[c] 
                now.count += 1
            else:
                now.children[c] = Trie()
                now = now.children[c]
        now.end[c] = True 

    def search(self, word: str) -> bool:
        now = self
        for c in word:
            if c in now.children:
                now = now.children[c]
            else:
                return False 
        return True if c in now.end else False

    def startsWith(self, prefix: str) -> bool:
        now = self
        for c in prefix:
            if c not in now.children:
                return False
            else:
                now = now.children[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)