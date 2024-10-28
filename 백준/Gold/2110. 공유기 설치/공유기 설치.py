import sys
input = sys.stdin.readline
n, c= 0 , 0
house = []

def is_possible(mid):
    cnt=1 # 첫번째 집에 공유기를 설치한다고 가정
    last = house[0]

    for i in range(1, len(house)):

        if house[i] - last >= mid :
            cnt +=1 
            last = house[i]
        if cnt >= c : return False

    return True

def solve():

    lo, hi = 0, max(house) - min(house)
 
    answer = -1
    while lo <= hi : 
        mid  = (lo+hi)//2 

        if is_possible(mid)  :
            hi = mid -1
        else :
            answer = mid
            lo = mid + 1

    print(answer)


def main():
    global n, c, house

    n,c = map(int, input().split())

    house = [int(input()) for _ in range(n)]

    house.sort()

    solve()

if __name__ == "__main__":
    main()
