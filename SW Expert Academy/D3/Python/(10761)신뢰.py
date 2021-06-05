if __name__=="__main__":
    N = int(input())

    for tc in range(1, N+1):
        inputs = input().split(' ')

        test_case = inputs[0]

        # robots
        robots = inputs[1::2]

        # button positions
        buttons = list(map(int, inputs[2::2]))

        # initial orange and blue position
        orange = blue = 1

        # orange_time, blue_time: previous robot time
        total_time = orange_time = blue_time = 0

        for robot, btn in zip(robots, buttons):
            if robot == 'B':
                save_time = total_time - blue_time
                if save_time == 0:
                    total_time += abs(btn - blue) + 1
                else:
                    if abs(btn - blue) - save_time <= 0:
                        total_time += 1
                    else:
                        total_time += abs(btn - blue) - save_time + 1

                blue_time = total_time
                blue = btn
            else:
                save_time = total_time - orange_time
                if save_time == 0:
                    total_time += abs(btn - orange) + 1
                else:
                    if abs(btn - orange) - save_time <= 0:
                        total_time += 1
                    else:
                        total_time += abs(btn - orange) - save_time + 1

                orange_time = total_time
                orange = btn

        print("#{} {}".format(tc, total_time))