from collections import deque
import sys

# 길이
N = int(input())

# 수식
soosik = input()

# number list
number_list = list(map(int, soosik[0:N:2]))

# operation list
oper_list = list(soosik[1:N:2])

# list length
length = len(oper_list)

# operation chk list
opchk = deque([False for i in range(len(oper_list))])

answer = -999999999

def operation(a, b, ch):
    if ch == '+':
        return a + b
    if ch == '-':
        return a - b
    if ch == '*':
        return a * b

def dfs(idx):
    # 괄호 결정 완료
    # Killing Part2 (함수로 만들어도 됐을 듯)
    if idx == length:
        copied_number_list = deque(number_list)
        copied_oper_list = deque(oper_list)

        for idx, flag in enumerate(opchk):
            if flag == True:
                # 괄호 연산
                result = operation(number_list[idx], number_list[idx+1], oper_list[idx])

                # 연산 결과 적용
                copied_number_list[idx] = result
                copied_number_list[idx + 1] = result
        
        # 순서대로 계산하기 때문에 왼쪽에 값을 저장
        left_term = copied_number_list.popleft()

        for flag in opchk:
            if not bool(copied_number_list):
                break

            if flag:
                # 괄호 연산: 연산자, 해당위치 값 모두 제거
                copied_oper_list.popleft()
                copied_number_list.popleft()
            else:
                # 괄호 연산 없을 때: 연산 시행
                left_term = operation(left_term, copied_number_list.popleft(), copied_oper_list.popleft())

        global answer
        answer = max(left_term, answer)
        return

    # 우선 계산할 노드 탐색
    # Killing Part1
    if idx > 0 and opchk[idx - 1] == True:
        dfs(idx + 1)
    else:
        opchk[idx] = True
        dfs(idx + 1)
        opchk[idx] = False
        dfs(idx + 1)

def main():
    dfs(0)
    print(answer)

if __name__=="__main__":
    main()
