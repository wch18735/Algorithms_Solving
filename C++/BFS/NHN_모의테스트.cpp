#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 전역변수
int chk[10][10];
int map[10][10];
int msize;

// 타입
typedef pair<int, int> Point;

// 방향
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

bool compare(int a, int b)
{
    return a < b;
}

void solution(int sizeOfMatrix, int** matrix) {
    msize = sizeOfMatrix;

    vector<int> numvec;

    // chk 복사
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            map[i][j] = matrix[i][j];
            chk[i][j] = 0;
        }
    }


    // 탐색
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for(int j = 0; j < sizeOfMatrix; j++)
        {
            // 개수
            int cnt = 0;

            if (matrix[i][j] != 1 || chk[i][j] != 0) continue;
            else
            {
                // 해당 위치부터 bfs
                deque<Point> que;
                que.push_back({ i,j });
                chk[i][j] = 1;

                cnt += 1;

                while (!que.empty())
                {
                    Point p = que.front();
                    que.pop_front();

                    int x = p.second;
                    int y = p.first;

                    for (int idx = 0; idx < 4; idx++)
                    {
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if (nx < 0 || nx >= sizeOfMatrix || ny < 0 || ny >= sizeOfMatrix || matrix[ny][nx] == 0 || chk[ny][nx] == 1) continue;

                        que.push_back({ ny, nx });
                        chk[ny][nx] = 1;
                        cnt += 1;
                    }
                }
            }
            if (cnt != 0) numvec.push_back(cnt);
        }
    }

    // 정렬
    sort(numvec.begin(), numvec.end(), compare);

    cout << (int)numvec.size() << '\n';
    for (int i = 0; i < (int)numvec.size(); i++) cout << numvec[i] << ' ';
}

struct input_data {
    int sizeOfMatrix;
    int** matrix;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.sizeOfMatrix;

    inputData.matrix = new int* [inputData.sizeOfMatrix];
    for (int i = 0; i < inputData.sizeOfMatrix; i++) {
        getline(cin, line);
        iss.clear();
        iss.str(line);
        inputData.matrix[i] = new int[inputData.sizeOfMatrix];
        for (int j = 0; j < inputData.sizeOfMatrix; j++) {
            iss >> inputData.matrix[i][j];
        }
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.sizeOfMatrix, inputData.matrix);
    return 0;
}