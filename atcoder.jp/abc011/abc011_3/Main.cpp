#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)


int main(){
    int n; cin >> n;
    vector <int> ng(3);
    rep(i, 3)cin >> ng.at(i);
    if(find(ng.begin(), ng.end(), n) != ng.end()){
        cout << "NO" << endl;
        return 0;
    }
    sort(ng.begin(), ng.end());

    int now = n;
    int cnt = 0;
    while(now > 0){
        int next;
        next = now - 3;

        while(find(ng.begin(), ng.end(), next) != ng.end()){
            next += 1;
            if(next == now){
                cout << "NO" << endl;
                return 0;
            }
        }

        now = next;
        cnt += 1;
    }

    if(cnt > 100){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;

}   