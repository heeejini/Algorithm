def main():
    import sys

    # 입력을 빠르게 받기 위해 sys.stdin 사용
    input = sys.stdin.readline

    n, m = map(int, input().split())
    data = list(map(int, input().split()))

    # 가장 빠른 기계의 시간으로 hi 초기화
    lo, hi = 1, min(data) * m

    while lo < hi:
        mid = (lo + hi) // 2
        balloon = 0

        for time in data:
            balloon += mid // time
            if balloon >= m:  # 목표 달성 시 더 이상 계산할 필요 없음
                break

        if balloon >= m:
            hi = mid  # 최소 시간을 찾기 위해 hi를 줄임
        else:
            lo = mid + 1  # 시간을 늘려야 함

    print(lo)

if __name__ == "__main__":
    main()
