#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             
    string buffer;                      

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               
    }

    return result;
}

deque<string> DQ;
vector<string> V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        bool dire = true, print=true;
        string s, s2;
        int size;
        cin >> s>>size>>s2;
        
        V = split(s2.substr(1, s2.size() - 2), ','); //[] 삭제하고 ,으로 split
        for (auto a : V) DQ.push_back(a); //덱에 추가

        for (auto c : s) {
            if (c == 'R') dire = !dire;
            else {
                if (DQ.size()) {
                    if (dire) {//정방향
                        DQ.pop_front();
                    }
                    else DQ.pop_back();
                }
                else {
                    print = false;
                    break;
                }
            }
        }
        if (print) {
            cout << "[";
            while (DQ.size()) {
                if (dire) {
                    cout << DQ.front();
                    DQ.pop_front();
                }
                else {
                    cout << DQ.back();
                    DQ.pop_back();
                }
                if (DQ.size() != 0) cout << ",";
            }
            cout << "]\n";
        }else
            cout << "error\n";
    }
}