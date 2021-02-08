#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

int num_arr[26];
char player[26];

void solution(int numOfAllPlayers, int numOfQuickPlayers, char* namesOfQuickPlayers, int numOfGames, int* numOfMovesPerGame) {
    // �ʱ� ����
    for (int idx = 1; idx < numOfAllPlayers; idx++)
    {
        player[idx - 1] = (char)('A' + idx);
    }
    
    // ���� ���� ��ġ
    int now = 0;
    
    // ���� ����
    char sool = 'A';
    num_arr[(int)(sool - 'A')] += 1;

    for (int i = 0; i < numOfGames; i++)
    {
        now = now + numOfMovesPerGame[i];

        // �̵� ��ġ ������
        if (now >= numOfAllPlayers - 1) {
            now = now % (numOfAllPlayers - 1);
        }
        else if (now < 0)
        {
            while (now < 0)
            {
                now += (numOfAllPlayers - 1);
            }
        }

        // ���� ����
        char tmp = player[now];

        // ���� �÷��̾����� Ȯ��
        bool pflag = false;
        for (int idx = 0; idx < numOfQuickPlayers; idx++)
        {
            if (namesOfQuickPlayers[idx] == tmp) pflag = true;
        }

        // ���� �ٲ��� �ʰ� �״�� ����
        if (pflag == true)
        {
            num_arr[(int)(sool - 'A')] += 1;
        }
        else
        {
            player[now] = sool;
            sool = tmp;
            num_arr[(int)(sool - 'A')] += 1;
        }
    }

    for (int i = 0; i < numOfAllPlayers - 1; i++)
    {
        cout << player[i] << ' ' << num_arr[(int)(player[i] - 'A')] << '\n';
    }
    cout << sool << ' ' << num_arr[(int)(sool - 'A')] << '\n';

    return;
}

struct input_data {
    int numOfAllPlayers;
    int numOfQuickPlayers;
    char* namesOfQuickPlayers;
    int numOfGames;
    int* numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.numOfAllPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfQuickPlayers;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
    for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
        iss >> inputData.namesOfQuickPlayers[i];
    }

    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.numOfGames;

    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.numOfMovesPerGame = new int[inputData.numOfGames];
    for (int i = 0; i < inputData.numOfGames; i++) {
        iss >> inputData.numOfMovesPerGame[i];
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
    return 0;
}