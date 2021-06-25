def solution():
    T = int(input())

    for test_case in range(1, T + 1):
        degree = int(input())

        minutes = int(degree / 0.5)

        hours = minutes // 60
        minutes = minutes % 60

        print("#{} {} {}".format(test_case, hours, minutes))

if __name__=="__main__":
    solution()