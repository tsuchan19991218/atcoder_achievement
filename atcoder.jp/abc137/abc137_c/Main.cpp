#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <string> s;
    for (int i = 0; i < n; i ++){
        string _s; cin >> _s;
        sort(_s.begin(), _s.end());
        s.push_back(_s);
    }
    sort(s.begin(), s.end());
    //for (auto c: s) cout << c << endl;

    int b = 0;
    int e = b + 1;
    long long ans = 0;
    long long cnt = 1;
    while(1){
        if (s[b] != s[e]){
            b = e;
            e = b + 1;
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            if (e >= n){
                break;
            }    
        }
        else{
            cnt += 1;
            e += 1;
            //cout << cnt << endl;
            if (e >= n) {
                ans += cnt * (cnt - 1) / 2;
                break;
            }
        }
    }
    cout << ans << endl;
}