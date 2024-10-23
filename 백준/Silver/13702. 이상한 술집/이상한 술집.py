n, k = 0, 0 
#n이 주전자 k가 사람수 
pot = []

def is_possible(mid):
    sum = 0 

    for litter in pot :
       # print(litter//mid)
        sum += litter//mid
   # print(sum)
    return sum 



def solve():
    lo, hi = 1, max(pot)
    answer = -1 
    while lo <= hi :
        mid= (lo+hi) //2 

        if is_possible(mid) < k: 
            hi = mid -1
         #   lo = mid +1
          #  answer = mid 
        else : 
            answer = mid 
            lo = mid +1
#            print("herer")


    print(int(answer))
    return


def main():

    global n, k ,pot
    n, k = map(int, input().split())
    for _ in range(n):
        pot.append(int(input()))
   # print(pot)
    solve()




if __name__=="__main__":
    main()