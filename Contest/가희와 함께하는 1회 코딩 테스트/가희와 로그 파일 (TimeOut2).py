from bisect import bisect_left, bisect_right
from sys import stdin
from heapq import heappush
from datetime import datetime

if __name__=="__main__":
    N, Q = map(int, input().split(' '))

    logs = []

    for i in range(N):
        LOG = stdin.readline().strip()
        times, level = LOG.split('#')

        time_stamp = datetime.strptime(times, "%Y-%m-%d %H:%M:%S").timestamp()
        heappush(logs, [time_stamp, int(level)])

    stamps, levels = list(zip(*logs))
    len_stamps = len(stamps)

    for i in range(Q):
        QUERY = stdin.readline().strip()

        from_time, to_time, level = QUERY.split('#')

        level = int(level)
        from_time = datetime.strptime(from_time, "%Y-%m-%d %H:%M:%S").timestamp()
        to_time = datetime.strptime(to_time, "%Y-%m-%d %H:%M:%S").timestamp()

        if int(to_time) < int(stamps[0]):
            print(0)
            continue

        left_idx = bisect_left(stamps, from_time)
        right_idx = bisect_right(stamps, to_time)

        if left_idx == len_stamps:
            print(0)
            continue

        answer = 0
        for log_level in levels[left_idx:right_idx]:
            if level <= log_level:
                answer += 1

        print(answer)