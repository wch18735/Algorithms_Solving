from collections import deque

class Process:
    def __init__(self, p_id, times, priority):
        self.p_id = p_id
        self.times = times
        self.priority = priority

    def __repr__(self):
        return '({}, {})'.format(self.priority, self.p_id)

if __name__=="__main__":
    T, n = map(int, input().split(' '))

    p_list = deque()
    for i in range(n):
        a, b, c = map(int, input().split(' '))
        p_list.append(Process(a, b, c))

    # sort
    p_list = deque(sorted(p_list, key=lambda x:(-x.priority, x.p_id)))

    t = 1
    while t <= T and bool(p_list):
        p = p_list.popleft()

        # print current process
        print(p.p_id)

        # process finish
        p.times -= 1
        if p.times == 0:
            # time count
            t += 1
            continue

        # increase priority and sort
        for _process in p_list:
            _process.priority += 1

        p_list.append(p)
        p_list = deque(sorted(p_list, key=lambda x: (-x.priority, x.p_id)))

        # time count
        t += 1