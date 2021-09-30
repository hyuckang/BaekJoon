import sys, queue
N = int(sys.stdin.readline())
Q = queue.Queue()

for _ in range(N):
    cmd = sys.stdin.readline().split()

    if(cmd[0] == 'push'):
        Q.put(cmd[1])
    
    elif(cmd[0] == 'pop'):
        if(Q.empty()):
            print(-1)
        else:
            print(Q.get())
    
    elif(cmd[0] == 'size'):
        print(Q.qsize())
    
    elif(cmd[0] == 'empty'):
        if(Q.empty()):
            print(1)
        else:
            print(0)
    
    elif(cmd[0] == 'front'):
        if(Q.empty()):
            print(-1)
        else:
            print(Q.queue[0])

    elif(cmd[0] == 'back'):
        if(Q.empty()):
            print(-1)
        else:
            print(Q.queue[-1])
