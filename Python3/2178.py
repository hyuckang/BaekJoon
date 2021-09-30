#!/usr/bin/pyhton3

import queue

class _2178:
    def __init__(self):
        self.N, self.M = map(int, input().split(' '))
        self.maps_check = [[0]*self.M for _ in range(self.N)]
        self.maps = [list(map(int, input())) for _ in range(self.N)]
        return
    
    def bfs(self):
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        Q = queue.Queue()
        Q.put((0,0))
        self.maps_check[0][0] = 1
        while(not Q.empty()):
            cur_x, cur_y = Q.get()
            for i in range(4):
                nx = cur_x + dx[i]
                ny = cur_y + dy[i]
                if nx<0 or ny<0 or nx>=self.N or ny>=self.M:
                    continue
                if self.maps[nx][ny] == 0 or self.maps_check[nx][ny] > 0:
                    continue
                Q.put((nx,ny))
                self.maps_check[nx][ny] = self.maps_check[cur_x][cur_y] + 1
        
        return self.maps_check[self.N-1][self.M-1]
        
    def solve(self):
        return self.bfs()

def main():
    boj = _2178()
    print(boj.solve())
    return


if __name__ == '__main__':
    main()
