class Trie:

    def __init__(self):
        self.level = 0         # root
        self.char = None
        self.children = defaultdict(str)
        self.cached = []

    def insert(self, word: str) -> None:
        now = self
        for i, c in enumerate(word):
            if now.children[c]:
                now = now.children[c] 
                if now.level == len(word):
                    now.cached.append(word)
            else:
                next = Trie()
                next.char = c
                next.level = i+1
                if next.level == len(word):
                    next.cached.append(word)
                now.children[c] = next
                now = next
        #now.cached.append(word)
        #print("insert: ", now.level, now.cached, now.char)

    def search(self, word: str) -> bool:
        now = self
        for i, c in enumerate(word):
            if not now.children[c]:
                return False
            else:
                now = now.children[c]
                #print("search: ", now.level, now.cached, now.char)
        if word in now.cached:
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        now = self
        for i, c in enumerate(prefix):
            if not now.children[c]:
                return False
            else:
                now = now.children[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)