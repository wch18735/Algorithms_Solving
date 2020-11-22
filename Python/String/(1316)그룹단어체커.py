N = int(input())

cnt = 0

for _ in range(N):
    prev_ch = None
    word = str(input())
    group_set = set()
    word_flag = True

    for ch in word:
        if ch != prev_ch:
            if ch in group_set:
                word_flag = False
            else:
                prev_ch = ch
                group_set.add(ch)
        elif ch == prev_ch:
            continue

    if word_flag: cnt += 1

print(cnt)