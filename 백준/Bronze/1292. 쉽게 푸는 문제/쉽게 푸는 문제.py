import sys
arr=[]

def main():
    input = sys.stdin.readline
    a,b = map(int, input().split())
    sum = 0
    for i in range(1, 1001):
        cnt = i
        for _ in range(cnt):
            arr.append(cnt)
  #  print(arr)
    for i in range(a-1, b):
        sum += arr[i]
    print(sum)
if __name__=="__main__":
    main() 