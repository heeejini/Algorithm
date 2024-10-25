n, m = 0,0
t = []
min_v = int(1e9)


def is_possible(mid):
    cnt = 0 

    for t_data in t:
        cnt += mid // t_data
        if cnt > m : break

    return cnt >= m 


def solve():
    answer = -1 
    lo, hi =  min_v , max(t) * m

    while lo <= hi :
        mid = (lo+hi)//2

        if is_possible(mid):
            answer = mid 
            hi = mid - 1
        else :
            lo = mid + 1

    print(int(answer))


def main():
    global n, m , t , min_v

    n, m = map(int, input().split())

    for _ in range(n):
        t.append(int(input()))
    
    min_v = min(t)

    solve()


if __name__=="__main__":
    main()