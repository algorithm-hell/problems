from collections import deque

def solution(queue1, queue2):
    sum1 = sum(queue1)
    sum2 = sum(queue2)
    total_length = len(queue1) + len(queue2)
    target_num = (sum1+sum2) // 2
    q1 = deque(queue1)
    q2 = deque(queue2)
    
    stage = 0
    while q1 and q2 and stage < total_length * 2:
        if sum1 > sum2:
            pop_num = q1.popleft()
            sum1 -= pop_num
            sum2 += pop_num
            q2.append(pop_num)
        elif sum1 < sum2:
            pop_num = q2.popleft()
            sum1 += pop_num
            sum2 -= pop_num
            q1.append(pop_num)
        else:
            return stage
        stage += 1
    
    return -1