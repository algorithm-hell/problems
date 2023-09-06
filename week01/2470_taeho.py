from sys import stdin, maxsize

n = int(stdin.readline())
solutions = map(int, stdin.readline().split())
solutions = sorted(solutions)
diff = maxsize
s = 0
e = n-1
answer = []
while s < e:
    sum_solution = solutions[s] + solutions[e]
    if diff > abs(sum_solution):
        diff = abs(sum_solution)
        answer = [solutions[s], solutions[e]]
        if diff == 0:
            break
            
    if sum_solution > 0:
        e -= 1
    else:
        s += 1
        
print(answer[0], answer[1])
