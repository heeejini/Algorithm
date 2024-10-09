import sys 

f = []


def fibo():
    global f 
  #  f.append(0)
    f.append(1)
    f.append(2)
    i=2
    while True:
        next_fibo = f[i-1] + f[i-2]

        if len(str(next_fibo)) >= 101 :
            break

        f.append(next_fibo)
        i+=1
    
def fibo_cnt(start, end):
    cnt = 0
    for i in f:
        if start <= i <= end :
            cnt +=1
    print(cnt)


def main():

    fibo()

    while True:
        a,b = map(int, input().split())

        if a == 0 and b == 0:
            break

        fibo_cnt(a,b) # 해당 범위 안에 피보나치에 해당하는 수가 몇개 있는지 세는 함수 
     #   print(a, b)


if __name__ == "__main__":
    main()