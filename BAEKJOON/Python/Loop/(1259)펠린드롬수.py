if __name__=="__main__":
    while True:
        num = input()

        if num == '0':
            break

        left_p = 0
        right_p = len(num) - 1

        p_flag = True

        while left_p <= right_p:
            if num[left_p] == num[right_p]:
                left_p += 1
                right_p -= 1
                continue
            else:
                p_flag = False
                break

        if p_flag:
            print('yes')
        else:
            print('no')