n, m = 0, 0
money = []

def is_possible(mid) :
    sum = mid 
    cnt = 1

    for temp in money :
        if temp > sum : 
            cnt+=1
            sum = mid 
       # print(sum)
        #if sum <= temp :
        sum -=temp
            
            
    
    return cnt 

            
def solve():
    lo, hi = max(money), 1e9
    answer = -1 
    while lo<=hi :
        mid = (lo+hi)//2
      #  print(mid)
        if is_possible(mid) <=  m:
            answer = mid 
            hi = mid - 1
        else :
            lo = mid+1

    print(int(answer))



def main():
    global n,m, money 
    
    n, m = map(int, input().split())

    for _ in range(n):
        money.append(int(input()))

    solve()

if __name__=="__main__":
    main()