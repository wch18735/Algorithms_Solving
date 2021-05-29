from itertools import permutations
from itertools import combinations

def solution(user_id, banned_id):
    answer = 0

    for candidates in combinations(user_id, len(banned_id)):
        for banned_ids in set(permutations(banned_id, len(banned_id))):
            # if candidate match banned: answer += 1
            match_flag = True
            for candidate, banned in zip(candidates, banned_ids):
                # not match with length
                if len(candidate) != len(banned):
                    match_flag = False
                    break

                # check candidate match with banned in order
                for idx in range(len(banned)):
                    if banned[idx] == '*':
                        continue
                    if banned[idx] != candidate[idx]:
                        match_flag = False
                        break

                # match perfect
                if not match_flag:
                    break

            if match_flag:
                answer += 1

    return answer