def solution(S, C):
    # striped string S
    S = [s.strip() for s in S.split(',')]
    C = [c.strip() for c in C.split(',')]

    if len(C) == 1:
        C = C * len(S)

    # for duplicate check
    dup_hash = dict()
    address_list = []

    for name, company in zip(S, C):
        names = name.split(' ')
        company = company.lower()

        # empty middle name
        if len(names) == 2:
            # check hyphen in last name
            names[1] = names[1].replace('-', '')

            # to lower
            names[0] = names[0].lower()
            names[1] = names[1].lower()

            # email address
            address = names[0][0] + names[1][:8] + "@" + company + ".com"

            # duplication check
            dup = 2
            while not dup_hash.get(address) is None:
                address = names[0][0] + names[1][:8] + str(dup) + "@" + company + ".com"
                dup += 1

            # answer
            address_list.append(address)
            dup_hash[address] = True

        # middle name exist
        else:
            # check hyphen in last name
            names[2] = names[2].replace('-', '')

            # to lower
            names[0] = names[0].lower()
            names[1] = names[1].lower()
            names[2] = names[2].lower()

            # email address
            address = names[0][0] + names[1][0] + names[2][:8] + "@" + company + ".com"

            # duplication check
            dup = 2
            while not dup_hash.get(address) is None:
                address = names[0][0] + names[1][0] + names[2][:8] + str(dup) + "@" + company + ".com"
                dup += 1

            # answer
            address_list.append(address)
            dup_hash[address] = True

    answer = []
    for name, email in zip(S, address_list):
        answer.append(name + " <" + email + ">")

    return ', '.join(answer)
