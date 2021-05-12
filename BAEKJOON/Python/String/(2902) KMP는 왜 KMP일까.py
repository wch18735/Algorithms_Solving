if __name__=="__main__":
    target_string = input()

    result = ''

    for name in target_string.split('-'):
        result += name[0]

    print(result)