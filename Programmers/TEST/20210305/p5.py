def main():
    N = int(input())

    arr = list(map(int, input().split()))

    left = 0
    right = len(arr)

    res = 0
    while right != left:
        max_p = arr.index(max(arr[left:right]))
        if max_p < (right + left)/2:
            left = int((right + left)/2)
            res += arr[max_p]
        else:
            right = int((right + left)/2)
            res += arr[max_p]

        if left + 1 == right:
            break
    print(res)



if __name__=="__main__":
    main()