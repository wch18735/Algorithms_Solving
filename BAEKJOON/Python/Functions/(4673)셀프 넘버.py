def self_number(num):
    result = num

    while num != 0:
        result += (num % 10)
        num //= 10

    return result

def main():
    flag_list = [True for _ in range(10001)]
    num_list = list(range(1, 10001))

    for n in num_list:
        if flag_list[n] is False:
            continue

        print(n)

        while self_number(n) <= 10000:
            t = self_number(n)
            flag_list[t] = False
            n = t

if __name__=="__main__":
    main()