def main():
    n, m = map(int, input().split())
  #  print(n, m)  # Output: 4 5

    arr = [[0] * (n+1) for _ in range(n+1)]
    dp =[[0] * (n+1) for _ in range(n+1)]
    
    data = [list(map(int, input().split())) for _ in range(n)] 

   # print(data)
   # print(data[1][1])
    for i in range(1, n+1):
        for j in range(1, n+1):
            arr[i][j] = data[i-1][j-1]
            dp[i][j] = arr[i][j] + dp[i-1][j]+dp[i][j-1] -dp[i-1][j-1]
    
   # tc = [list(map(int, input().split())) for _ in range(m)]
    
    for _ in range(m):
        a, b, c, d = map(int, input().split())
        result = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1]
        print(result) 


if __name__ == "__main__":
    main()