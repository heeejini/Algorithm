def solution(today, terms, privacies): 
    answer=[]
    year, month, day = map(int, today.split("."))
    #print(year, month, day)
    
    #
    today = (year*12*28) + (month*28)+day
    
    term_dict = {}
    for term in terms:
        t_type, t_month = term.split()
        term_dict[t_type] = int(t_month) 
    
    for idx, privacy in enumerate(privacies) :
        past_date, past_type = privacy.split()
        p_year, p_month, p_day = map(int, past_date.split("."))
        
        past_days = (p_year*12*28)+ (p_month *28) + p_day
       # print(past_days)
        days = term_dict[past_type] * 28 
        # 몇일동안 보관가능한지
        duration = past_days + days-1 # 개인정보 수집 일자부터 약관 유효기간 
        
        
      #  print(today , duration)
        if duration < today : 
            answer.append(idx+1)
            
        
        
    return answer