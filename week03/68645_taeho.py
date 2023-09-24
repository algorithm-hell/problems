from itertools import chain

def solution(n):
    answer = [[0]*i for i in range(1, n+1)]
    
    row = -1
    col = 0
    count = 1
    for step in range(n):
        for _ in range(n-step):
            if step % 3 == 0:
                row += 1
            elif step % 3 == 1:
                col += 1
            else:
                row -= 1
                col -= 1
            answer[row][col] = count
            count += 1
    
    return list(chain(*answer))