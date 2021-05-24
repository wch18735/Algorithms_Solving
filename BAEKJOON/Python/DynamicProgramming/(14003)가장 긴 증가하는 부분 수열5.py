if __name__=="__main__":
    N = int(input())

    # integer sequence
    num_arr = list(map(int, input()))

    # 기존 배열의 끝에서 원소 수정 -> 그대로 둬도 OK
    # 기존 배열의 중간에서 원소 수정 -> prevent
    # 기존 배열의 처음에서 원소 수정 -> 현재 길이를 max_len 저장, 부분 수열을 저장
