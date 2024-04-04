class BrowserHistory:
    from collections import deque

    def __init__(self, homepage: str):
        self.stack = []
        self.queue = deque()
        self.now = homepage
        

    def visit(self, url: str) -> None:
        self.stack.append(self.now)
        self.now = url
        self.queue = deque()

    def back(self, steps: int) -> str:
        while steps > 0 and self.stack:
            self.queue.appendleft(self.now)
            self.now = self.stack.pop()
            steps -= 1
        return self.now

    def forward(self, steps: int) -> str:
        while steps > 0 and self.queue:
            self.stack.append(self.now)
            self.now = self.queue.popleft()
            steps -= 1
        return self.now
        
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)