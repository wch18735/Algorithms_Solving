from heapq import heapify, heappush, heappop

if __name__=="__main__":
    HEAP = []

    T, n = map(int, input().split(' '))
    for i in range(n):
        p_id, p_time, p_pri = map(int, input().split(' '))

        # append Process instance to HEAP
        HEAP.append([-p_pri, p_id, p_time])

    heapify(HEAP)

    t = 1
    while t <= T and HEAP:
        process = heappop(HEAP)

        # print current process p_id
        print(process[1])

        # execute 1 work
        process[2] -= 1

        if process[2] == 0:
            t += 1
            continue

        # change priority
        process[0] += 1

        heappush(HEAP, process)
        t += 1
