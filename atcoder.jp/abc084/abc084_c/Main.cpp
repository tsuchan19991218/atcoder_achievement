#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> C(n - 1), S(n - 1), F(n - 1);

    for (int i = 0; i < n - 1; i ++){
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }


    for (int start = 0; start < n - 1; start ++){
        int now_t = S.at(start) + C.at(start);

        for (int station = start + 1; station < n - 1; station ++){
            //　始発よりも早く到着した場合
            if (now_t <= S.at(station)){
                now_t = S.at(station) + C.at(station);
                continue;
            }

            //　次に向かう電車がまだきていないとき
            if ((now_t - S.at(station)) % F.at(station)){
                now_t += F.at(station) - ((now_t - S.at(station)) % F.at(station));
            }

            now_t += C.at(station);
        }

        cout << now_t << endl;

    }

    cout << 0 << endl;
}