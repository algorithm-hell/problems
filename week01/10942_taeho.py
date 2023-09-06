from sys import stdin

n = int(stdin.readline())
DP = [[False]*n for _ in range(n)]
board = list(map(int, stdin.readline().split()))
m = int(stdin.readline())
questions = []

for i in range(n):
    DP[i][i] = True

for i in range(n-1):
    if board[i] == board[i+1]:
        DP[i][i+1] = True

for i in range(2, n):
    for j in range(n-i):
        DP[j][j+i] = (board[j] == board[j+i]) and DP[j+1][j+i-1]

for _ in range(m):
    s, e = map(int, stdin.readline().split())
    print(1 if DP[s-1][e-1] else 0 )