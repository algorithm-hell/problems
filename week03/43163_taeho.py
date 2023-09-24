from collections import deque

def is_one_diff(s1, s2):
    diff_count = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            diff_count += 1
    
    return True if diff_count==1 else False

def solution(begin, target, words):
    
    def bfs():
        visited = set()
        q = deque()
        q.append([begin, 0])
        visited.add(begin)
        while q:
            cur_s, cur_t = q.popleft()
            
            if cur_s == target:
                return cur_t
            
            for word in words:
                if (word not in visited) and is_one_diff(cur_s, word):
                    visited.add(word)
                    q.append([word, cur_t+1])
        return 0
    
    return bfs()