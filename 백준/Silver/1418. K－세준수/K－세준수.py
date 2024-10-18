
def prime_factors(n):
    factors = []  # 소인수를 저장할 리스트
    divisor = 2   # 가장 작은 소수부터 시작

    # 2부터 시작해서 나눌 수 있는 모든 소인수를 찾는다.
    while divisor * divisor <= n:  # divisor의 제곱이 n보다 작을 때까지
        while n % divisor == 0:     # divisor가 n을 나누면
            factors.append(divisor) # 소인수로 추가
            n //= divisor           # n을 나눈 값으로 갱신
        divisor += 1                # 다음 수로 이동

    # 나머지 값이 1이 아니라면, 그 값도 소인수이다.
    if n > 1:
        factors.append(n)
    
    return factors

def main():
    n = int(input())
    k = int(input())

    cnt=1
    while True:
        if n <= 1 : break
        primes=prime_factors(n)
       # print(n, primes)
        result = max(primes)
       
        if result <= k :
            cnt +=1 
        n-=1
        
    print(cnt)


if __name__=="__main__":
    main()
