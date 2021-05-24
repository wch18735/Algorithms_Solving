from heapq import heapify, heappush, heappop

class Process:
    def __init__(self, p_id, p_time, p_prior):
        self.p_id = p_id
        self.p_time = p_time
        self.p_prior = p_prior

    def __repr__(self):
        return 'p_id: {}, p_time: {}, p_priority: {}'.format(self.p_id, self.p_time, self.p_prior)

    def __lt__(self, other):
        if self.p_prior == other.p_prior:
            # 앞으로 오게 하고 싶은 것
            return self.p_id < other.p_id
        else:
            # 앞으로 오게하고 싶은 것
            return self.p_prior > other.p_prior


if __name__=="__main__":
    HEAP = []

    T, n = map(int, input().split(' '))
    for i in range(n):
        a, b, c = map(int, input().split(' '))

        # append Process instance to HEAP
        HEAP.append(Process(a, b, c))

    heapify(HEAP)

    t = 1
    while t <= T and HEAP:
        process = heappop(HEAP)

        # print current process p_id
        print(process.p_id)

        # execute 1 work
        process.p_time -= 1

        if process.p_time == 0:
            t += 1
            continue

        # change priority
        process.p_prior -= 1

        heappush(HEAP, process)
        t += 1
