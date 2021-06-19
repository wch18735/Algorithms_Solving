def solution(S):
    S = [s.strip() for s in S.split('\n')]

    MONTH_TO_INT = {
        "Jan": "01",
        "Feb": "02",
        "Mar": "03",
        "Apr": "04",
        "May": "05",
        "Jun": "06",
        "Jul": "07",
        "Aug": "08",
        "Sep": "09",
        "Oct": "10",
        "Nov": "11",
        "Dec": "12"
    }

    INT_TO_MONTH = {
        "01": "Jan",
        "02": "Feb",
        "03": "Mar",
        "04": "Apr",
        "05": "May",
        "06": "Jun",
        "07": "Jul",
        "08": "Aug",
        "09": "Sep",
        "10": "Oct",
        "11": "Nov",
        "12": "Dec"
    }

    answer_list = []

    for file_log in S:
        owner = file_log[:6].strip()
        file_log = file_log[7:]

        perm = file_log[:3].strip()
        file_log = file_log[4:]

        dd, mmm, yyyy = file_log[:11].split(' ')
        file_log = file_log[12:]

        byte_size = file_log[:10].strip()
        file_log = file_log[11:]

        # condition check
        # executable
        if perm[2] != "x":
            continue
        # admin
        if owner != "admin":
            continue
        # size
        if 14 * pow(2, 20) <= int(byte_size):
            continue

        answer_list.append(yyyy + MONTH_TO_INT.get(mmm) + dd)

    if len(answer_list) == 0:
        return "NO FILES"
    else:
        answer_list.sort(key=lambda x: x)
        answer = answer_list[0]
        return answer[6:] + ' ' + INT_TO_MONTH.get(answer[4:6]) + ' ' + answer[:4]
