from operator import itemgetter
def solution(strings, n):
    answer = []
    
    strings.sort()
    answer = sorted(strings, key=itemgetter(n))
    return answer