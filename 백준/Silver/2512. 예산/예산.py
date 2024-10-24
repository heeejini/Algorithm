import sys
input = sys.stdin.readline

def is_possible(mid):
    # 국가별로 mid 값 이상을 사용하지 않도록 제한하여 전체 예산을 계산
    money = 0
    for c in country:
        money += min(c, mid)
    return money

def solve():
    lo, hi = 0, max(country)  # 최대 예산 제한은 각 국가별 최대값 중 가장 큰 값이어야 함
    answer = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if is_possible(mid) <= m:  # 현재 mid에서의 총 예산이 m 이하인지 확인
            answer = mid  # 조건을 만족하므로 정답 후보를 갱신
            lo = mid + 1
        else:
            hi = mid - 1
    print(answer)
    return 

def main():
    global n, m, country
    n = int(input())  # 국가의 수
    country = list(map(int, input().split()))  # 각 국가의 최대 예산
    m = int(input())  # 전체 예산 제한

    solve()

if __name__ == "__main__":
    main()
