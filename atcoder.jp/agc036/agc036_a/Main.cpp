#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll s; cin >> s;
    ll y1, y2;

    y1 = (s / 1000000000) + 1;
    y2 = 1000000000 - (s % 1000000000);

    if (s == 1000000000000000000){
        cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 1000000000 << " " << 1000000000 << endl;
        return 0;
    }

    cout << 0 << " " << 0 << " " << 1 << " " << y1 << " " << 1000000000 << " " << y2 << endl;
}