def solution(answers):
    number1 = [1, 2, 3, 4, 5]
    number2 = [2, 1, 2, 3, 2, 4, 2, 5]
    number3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    len1 = len(number1)
    len2 = len(number2)
    len3 = len(number3)

    answer_count = [0, 0, 0]

    for i in range(len(answers)):
        # check number1
        if answers[i] == number1[i % len1]:
            answer_count[0] += 1

        # check number1
        if answers[i] == number2[i % len2]:
            answer_count[1] += 1

        # check number1
        if answers[i] == number3[i % len3]:
            answer_count[2] += 1

    max_val = max(answer_count)

    answer = []
    for i in range(3):
        if answer_count[i] == max_val:
            answer.append(i + 1)

    return answer