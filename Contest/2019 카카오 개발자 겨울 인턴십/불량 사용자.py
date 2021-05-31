from itertools import permutations

def ismatch(candidate, bad_user_id):
    if len(candidate) != len(bad_user_id):
        return False

    # check match string
    for i in range(len(bad_user_id)):
        if bad_user_id[i] == '*':
            continue
        if candidate[i] != bad_user_id[i]:
            return False

    # final result
    return True

def get_indexes(candidate_list):
    li = []

    for _, idx in candidate_list:
        li.append(idx)

    return li

def solution(user_id, banned_id):
    answer = set()

    user_id = list(zip(user_id, range(len(user_id))))
    print(user_id)

    for candidate_list in permutations(user_id, len(banned_id)):
        # check if match with banned_id_list
        match_flag = True
        for candidate_and_idx, bad_user_id in zip(candidate_list, banned_id):
            candidate, idx = candidate_and_idx

            if not ismatch(candidate, bad_user_id):
                match_flag = False
                break

        # all check
        if match_flag:
            # get candidate indexes
            indexes = get_indexes(candidate_list)
            indexes.sort(key=lambda x:x)
            indexes = tuple(indexes)
            answer.add(indexes)

    return len(answer)