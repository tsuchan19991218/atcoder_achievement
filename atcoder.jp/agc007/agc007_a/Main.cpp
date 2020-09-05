#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;

    vector <string> a;
    for (int i = 0; i < h; i ++){
        string _a; cin >> _a;
        a.push_back(_a);
    }

    int right_index = 0;
    string ans = "Possible";
    for (int i = 0; i < h; i ++){
        int now_right = 0;
        bool check = false;
        bool check2 = false;
        bool break_flag = false;
        for (int j = 0; j < w; j ++){
            if (!check && a[i][j] == '#'){
                check = true;
                if (right_index > j) {ans = "Impossible"; break_flag = true; break;}
            }

            if(check && a[i][j] != '#') check2 = true;
            if(check2 && a[i][j] == '#') {ans = "Impossible"; break_flag = true; break;}

            if (a[i][j] == '#') now_right = j;
        }
        right_index = now_right;
        if (break_flag) break;
    }

    cout << ans << endl;
}