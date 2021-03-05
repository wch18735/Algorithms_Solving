#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main() {
    int pc_num;
    int hour;
    int n;

    cin >> pc_num >> n >> hour;
    vector<vector<int>> pc(101);

    int pn, h;
    for (int i = 0; i < n; i++)
    {
        cin >> pn >> h;
        pc[pn].push_back(h);
    }

    for (int i = 1; i <= pc_num; i++)
    {
        int left_h = hour;
        sort(pc[i].begin(), pc[i].end(), compare);

        for (int j = 0; j < (int)pc[i].size(); j++)
        {
            if (pc[i][j] <= left_h) left_h -= pc[i][j];
            else break;
        }

        cout << i << ' ' << 1000 * (hour - left_h) << '\n';
    }

    return 0;
}