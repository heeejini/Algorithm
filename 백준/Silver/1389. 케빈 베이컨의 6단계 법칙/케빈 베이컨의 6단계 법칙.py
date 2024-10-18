def main():
    n, m= map(int, input().split())

  #  arr = [list(map(int, input().split())) for _ in range(n)]
    arr = [[1e9] * (n+1) for _ in range(n+1)]

    for _ in range(m):
        a, b = map(int, input().split())
        arr[a][b]=1
        arr[b][a]=1
    
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if arr[i][j] > arr[i][k] + arr[k][j] :
                    arr[i][j] = arr[i][k] + arr[k][j]

    row_sums = [sum(row[1:]) for row in arr[1:]]  # arr의 첫 번째 인덱스는 무시

    min_idx = row_sums.index(min(row_sums))+1
    print(min_idx)

if __name__ == "__main__":
    main()