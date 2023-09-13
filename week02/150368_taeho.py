from itertools import product

def solution(users, emoticons):
    answer = [0, 0]
    for prod in product([10, 20, 30, 40], repeat = len(emoticons)):
        
        buy_plus = 0
        buy_emoticon = 0
        for user in users:
            sum_emoticons = sum(
                map(lambda x: x[0]*(100-x[1])//100, 
                    filter(lambda x: x[1] >= user[0], zip(emoticons, prod)))
            )
            
            if sum_emoticons >= user[1]:
                buy_plus += 1
            else:
                buy_emoticon += sum_emoticons
        
        if answer[0] < buy_plus:
            answer = [buy_plus, buy_emoticon]
        elif answer[0] == buy_plus:
            answer[1] = max(answer[1], buy_emoticon)
                
    return answer