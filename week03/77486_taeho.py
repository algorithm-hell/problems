def dadan(sales, dadan_tree, sell, profit):
    distribution = profit//10
    if distribution == 0:
        return 

    higher_person = dadan_tree[sell] 

    if higher_person is None:
        sales[sell] -= distribution
        return
    
    sales[sell] -= distribution
    sales[higher_person] += distribution
    dadan(sales, dadan_tree, higher_person, distribution)

    
def solution(enroll, referral, seller, amount):
    answer = []
    dadan_tree = {person:None for person in enroll}
    sales = {person:0 for person in enroll}
    
    for enr,ref in zip(enroll, referral):
        if ref != '-':
            dadan_tree[enr] = ref
    
    for sell,count in zip(seller, amount):
        profit = 100*count
        sales[sell] += profit
        dadan(sales, dadan_tree, sell, profit)
    
    return list(sales.values())