#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define MAX_H 10001;
int MAP[100];

void solution(int day, int width, int** blocks) {
    // 시멘트
    int cmt = 0;
    
    for (int d = 0; d < day; d++)
    {
        // 벽돌 입력
        for (int i = 0; i < width; i++)
        {
            MAP[i] += blocks[d][i];
        }

        // 시멘트 붇기
        int start = 0;
        int now = 1;
        int min_h = MAP[start];

        for (int i = now; i < width; i++)
        {
            if (MAP[start] >= MAP[i])
            {
                if (min_h < MAP[i]) // 가장 왼쪽과 최소값 중간
                {
                    for (int idx = start; idx < i; idx++)
                    {
                        if (MAP[idx] < MAP[i])
                        {
                            // 중간 값인 경우
                            cmt += MAP[i] - MAP[idx];
                            MAP[idx] = MAP[i];
                        }
                    }
                    min_h = MAP[i];
                }
                else { // 가장 작은 값
                    min_h = MAP[i];
                }
            }
            else if (MAP[start] < MAP[i])
            {
                for (int idx = start; idx <= i - 1; idx++)
                {
                    cmt += MAP[start] - MAP[idx];
                    MAP[idx] = MAP[start];
                }
                start = i;
            }
        }
    }

    cout << cmt << '\n';
}

struct input_data {
    int day;
    int width;
    int** blocks;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.day;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.width;

    inputData.blocks = new int* [inputData.day];
    for (int i = 0; i < inputData.day; i++) {
        getline(cin, line);
        iss.clear();
        iss.str(line);
        inputData.blocks[i] = new int[inputData.width];
        for (int j = 0; j < inputData.width; j++) {
            iss >> inputData.blocks[i][j];
        }
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.day, inputData.width, inputData.blocks);
    return 0;
}