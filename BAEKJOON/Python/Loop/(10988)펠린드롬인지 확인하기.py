if __name__=="__main__":
    target_s = input()

    p_flag = True
    left_p = 0
    right_p = len(target_s) - 1

    while left_p <= right_p:
        if target_s[left_p] == target_s[right_p]:
            left_p += 1
            right_p -= 1
            continue
        else:
            p_flag = False
            break

    if p_flag:
        print(1)
    else:
        print(0)