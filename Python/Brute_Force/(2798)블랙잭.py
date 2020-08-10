N,M = map(int, input().split())

number = list(map(int,input().split()))
sum_list = []

for i in range(N-2):
    a = number[i]
    for j in range(i+1,N-1):
        b = number[j]
        for k in range(j+1,N):
            c = number[k]
            sum_list.append(a + b + c)

sum_list.sort(reverse=True)
if M in sum_list:
    print(M)
else:
    for sum_element in sum_list:
        if sum_element < M: # 가장 작아지는 첫 번째 순간이 그것
            print(sum_element)
            break



