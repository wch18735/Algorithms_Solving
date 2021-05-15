T = int(input())

def compare_str(P, Q):
    if abs(len(P) - len(Q)) > 1:
        return 'Y'

    # 길이가 같을 때
    if len(P) == len(Q):
        for a, b in zip(P, Q):
            if a != b:
                return 'Y'
        return 'N'
    elif len(P) < len(Q):
        for a, b in zip(P, Q):
            if a != b:
                return 'Y'
        if Q[len(P)] != 'a':
            return 'Y'
        return 'N'

    elif len(P) > len(Q):
        for a, b in zip(P, Q):
            if a != b:
                return 'Y'
        if P[len(Q)] != 'a':
            return 'Y'
        return 'N'

for test_case in range(1, T + 1):
    P = input().strip()
    Q = input().strip()

    # 문자열 비교
    print('#' + str(test_case) + ' ' + compare_str(P, Q))
