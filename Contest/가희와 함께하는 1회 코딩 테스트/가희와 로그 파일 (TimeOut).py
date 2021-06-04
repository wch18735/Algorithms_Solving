from heapq import heapify, heappush
from bisect import bisect_left, bisect_right


def log_split(LOG):
    time, level = LOG.split('#')

    yyyy_mm_dd, hh_mm_ss = time.split(' ')

    years, month, days = map(int, yyyy_mm_dd.split('-'))
    hours, minutes, seconds = map(int, hh_mm_ss.split(':'))

    timestamp = seconds + minutes * 60 + hours * 3600 + days * 86400 + month * 2628000 + years * 31540000

    return timestamp, int(level)


def query_split(QUERY):
    FROM, TO, LEVEL = QUERY.split('#')

    # from time stamp
    yyyy_mm_dd, hh_mm_ss = FROM.split(' ')
    years, month, days = map(int, yyyy_mm_dd.split('-'))
    hours, minutes, seconds = map(int, hh_mm_ss.split(':'))
    FROM_STAMP = seconds + minutes * 60 + hours * 3600 + days * 86400 + month * 2628000 + years * 31540000

    # to time stamp
    yyyy_mm_dd, hh_mm_ss = TO.split(' ')
    years, month, days = map(int, yyyy_mm_dd.split('-'))
    hours, minutes, seconds = map(int, hh_mm_ss.split(':'))
    TO_STAMP = seconds + minutes * 60 + hours * 3600 + days * 86400 + month * 2628000 + years * 31540000

    LEVEL = int(LEVEL)

    return FROM_STAMP, TO_STAMP, LEVEL


if __name__ == "__main__":
    N, Q = map(int, input().split(' '))

    logs = []
    heapify(logs)

    for i in range(N):
        LOG = input()

        # timestamp 반환
        timestamp, level = log_split(LOG)

        heappush(logs, [timestamp, level])

    stamps = list(zip(*logs))[0]

    for i in range(Q):
        QUERY = input()

        f_timestamp, t_timestamp, level = query_split(QUERY)

        # left to right
        # bisect_left: possible place to insert left most index (result would exceed max index)
        # bisect_right: possible place to insert right most index (result would exceed max index)
        left_idx = bisect_left(stamps, f_timestamp)
        right_idx = bisect_right(stamps, t_timestamp)

        if left_idx == len(stamps):
            print(0)
            continue

        if right_idx == 0 and t_timestamp < stamps[right_idx]:
            print(0)
            continue

        answer = 0
        for i in range(left_idx, right_idx):
            if level <= logs[i][1]:
                answer += 1

        print(answer)