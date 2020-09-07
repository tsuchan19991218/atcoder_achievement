#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string S; cin >> S;
    vector <int> seen_cnt_from_l(n, 0);
    vector <int> seen_cnt_from_r(n, 0);
    vector <int> seen_cnt(n, 0);

    for (int i = 1; i < n; i ++){
        seen_cnt_from_l[i] = seen_cnt_from_l[i - 1];
        if (S[i - 1] == 'E'){
            seen_cnt_from_l[i] += 1;
        }
    }
    for (int i = n - 2; i >= 0; i --){
        seen_cnt_from_r[i] = seen_cnt_from_r[i + 1];
        if (S[i + 1] == 'W'){
            seen_cnt_from_r[i] += 1;
        }
    }

    for (int i = 0; i < n; i ++){
        seen_cnt.at(i) = seen_cnt_from_r.at(i) + seen_cnt_from_l.at(i);
    }

    // for (auto cnt : seen_cnt) cout << cnt << " ";

    int seen_max = *max_element(seen_cnt.begin(), seen_cnt.end());
    cout << (n - 1) - seen_max << endl;
}