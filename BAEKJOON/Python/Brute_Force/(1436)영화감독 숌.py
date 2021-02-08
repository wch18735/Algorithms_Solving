# 1 <= N <= 10,000
N = int(input())

def make_right(total_right_len, right_num):
    # return total_len, next_right_num, right_str
    middle_str = "666"

    # 자리수가 바뀌면 total_len+1 해주고 해당 자리 수 만큼 0 출력 (이때, right_num은 0)
    # 다음 수는 1 부터 다시
    if total_right_len < len(str(right_num)):
        total_right_len += 1
        right_num = 1
        zero_str = ''

        for i in range(total_right_len):
            zero_str += '0'

        return total_right_len, right_num, middle_str+zero_str

    zero_num = total_right_len - len(str(right_num))
    zero_str = ''
    for i in range(zero_num):
        zero_str += '0'

    return total_right_len, right_num+1, middle_str+zero_str+str(right_num)

def make_left(left_num):
    middle_str ='666'

    return left_num+1, str(left_num)+middle_str

# initial state
total_right_len = 1
total_left_len = 1
right_num = 0
left_num = 0
right_part = ''
left_part = ''

# num_list
num_list = []

for i in range(N):
    if i == 0:
        # initial step
        total_right_len, right_num, right_part = make_right(total_right_len, right_num)
        left_num, left_part = make_left(left_num)
        num_list.append(min(int(right_part), int(left_part)))
    else:
        if int(left_part) > int(right_part):
            total_right_len, right_num, right_part = make_right(total_right_len, right_num)
            num_list.append(min(int(right_part), int(left_part)))
        elif int(left_part) < int(right_part):
            left_num, left_part = make_left(left_num)
            num_list.append(min(int(right_part), int(left_part)))
        else:
            total_right_len, right_num, right_part = make_right(total_right_len, right_num)
            left_num, left_part = make_left(left_num)
            num_list.append(min(int(right_part), int(left_part)))

# print(num_list[-1])

for i in range(N):
    print(num_list[i])