#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector <int> p;
    int same_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i ++){
        int _p;
        cin >> _p;
        p.push_back(_p);
    }
    for (int i = 0; i < n; i ++){
        if (i + 1 == p[i]) {
            same_cnt += 1;
            i += 1;
        }
    }
    int ans = same_cnt;
    cout << ans << endl;
}