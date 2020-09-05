#include <bits/stdc++.h>
using namespace std;



int main(){
    string sa, sb, sc;
    vector <string> s;
    cin >> sa >> sb >> sc;
    s.push_back(sa);
    s.push_back(sb);
    s.push_back(sc);
    vector <vector<int>> int_s(3);
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < s[i].size(); j ++){
            int_s[i].push_back(s[i][j] - 'a');
        }
        int_s[i].push_back(-1);
    }

    vector <int> trash_cnt(3, 0);
    int turn = 0;

    while(1){

        int next_turn = int_s[turn][trash_cnt[turn]];
        if (next_turn == -1) break;
        trash_cnt[turn] += 1;
        turn = next_turn;
    }

    char ans = turn + 'A';
    cout << ans << endl;
}