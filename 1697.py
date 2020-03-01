#!/usr/bin/python3
# https://www.acmicpc.net/problem/1697
import queue

class _1697:
    def __init__(self):
        self.N, self.K = map(int, input().split(' '))
        self.maps = [-1 for _ in range(100001)]
        
    def bfs(self):
        # 수빈과 동생이 같은 위치에 있을 경우        
        if self.N == self.K:
            return 0

        Q = queue.Queue()
        Q.put(self.N)
        self.maps[self.N] = 0
        while(not Q.empty()):
            cur = Q.get()
            # 수빈이 동생의 위치에 도착했을 경우
            if cur == self.K:
                return self.maps[cur]
            # 수빈이 동생을 아직 찾지 못했을 경우
            if(cur+1<=100000 and self.maps[cur+1] == -1):
                self.maps[cur+1] = self.maps[cur] + 1
                Q.put(cur+1)
                
            if(cur-1>=0 and self.maps[cur-1] == -1):
                self.maps[cur-1] = self.maps[cur] + 1
                Q.put(cur-1)
                
            if(cur*2<=100000 and self.maps[cur*2] == -1):
                self.maps[cur*2] = self.maps[cur] + 1
                Q.put(cur*2)
                

    def solve(self):
        return self.bfs()
        

def main():
    boj=_1697()
    print(boj.solve())
    
if __name__=='__main__':
    main()
