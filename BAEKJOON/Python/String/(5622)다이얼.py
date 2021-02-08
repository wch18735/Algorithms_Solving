str = input()
str = [ch for ch in str]
dial = ["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]
dial_list = list()
for ch in str:
    for idx, button in enumerate(dial):
        if ch in button:
            dial_list.append(idx + 2)
print(sum(dial_list) + len(dial_list))