def solution(s):
    answer = []

    # 맨 끝 괄호 제거
    elem_string = s[1:-1]

    # 좌측 {, 우측 }
    left_flag = False
    right_flag = False
    start_idx = 0
    end_idx = 0

    # elements
    elements = []

    for idx, ch in enumerate(elem_string):
        if ch == '{':
            left_flag = True
            start_idx = idx
        elif ch == '}':
            right_flag = True
            end_idx = idx

        if left_flag == True and right_flag == True:
            # elements with string
            elements.append(elem_string[start_idx + 1: end_idx])

            # 초기화
            left_flag = False
            right_flag = False

    # string -> integer array
    for idx, s in enumerate(elements):
        elements[idx] = list(map(int, s.split(',')))

    # 길이 오름차순 sort
    elements.sort(key=lambda x: len(x))

    # answer 에 순서대로 넣기
    for elem in elements:
        if len(answer) == 0:
            answer += elem
        else:
            # 부분 집합 제거
            for integer in answer:
                # answer에 이미 존재하는 것 위치 찾기
                idx = elem.index(integer)

                # 지우기
                del elem[idx]

            # 남은 부분 저장
            answer += elem

    print(answer)
    return answer