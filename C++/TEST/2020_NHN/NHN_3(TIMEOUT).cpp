#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void solution(int numOfOrder, string* orderArr) {
    // °ıÈ£ À§Ä¡ ´ãÀ» ½ºÅÃ
    vector<int> b_stack;

    for (int order_num = 0; order_num < numOfOrder; order_num++)
    {
        string str = orderArr[order_num];

        for (int i = 0; i < (int)str.size(); i++)
        {
            // °ıÈ£ À§Ä¡
            if (str[i] == '(') b_stack.push_back(i);
            else if(str[i] == ')')
            {
                // ´İÈù °ıÈ£ ½Ö
                int pair_idx = b_stack.back();
                b_stack.pop_back();

                // ¼ıÀÚÀÎ °æ¿ì
                if ('1' <= str[pair_idx - 1] && str[pair_idx - 1] <= '9')
                {
                    string sub = str.substr(pair_idx+1, i-1);
                    for (int num = 0; num < (int)(str[pair_idx - 1] - '0'); num++) sub.append(sub);
                    
                    str.erase(pair_idx, i);
                    str.insert(pair_idx - 1, sub);
                }
                else // ¹®ÀÚÀÎ °æ¿ì
                {
                    char ch = str[pair_idx - 1];
                    string tmp = string("");
                    string sub = str.substr(pair_idx + 1, i - 1);
                    for (int num = 0; num < (int)sub.size(); num++)
                    {
                        tmp.push_back(ch);
                        tmp.push_back(sub[num]);

                        str.erase(pair_idx, i);
                        str.insert(pair_idx - 1, tmp);
                    }
                }
            }
        }

        cout << str << '\n';
    }
}

struct input_data {
    int numOfOrder;
    string* orderArr;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.numOfOrder;

    inputData.orderArr = new string[inputData.numOfOrder];
    for (int i = 0; i < inputData.numOfOrder; i++) {
        getline(cin, line);
        iss.clear();
        iss.str(line);
        iss >> inputData.orderArr[i];
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.numOfOrder, inputData.orderArr);
    return 0;
}