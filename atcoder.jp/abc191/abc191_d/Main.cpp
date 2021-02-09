#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int digit4_ceil(double x){
    int X = x * 10000;
    cout << X << endl;
    bool plus = false;
    if(X >= 0) plus = true;
    if(!plus) X *= -1;
    int seisu = X / 10000;
    if(plus){
        if(X % 10000 == 0) return seisu;
        return seisu + 1;
    }
    else{
        if(X % 10000 == 0) return -seisu;
        return -seisu + 1;
    }
}

ll str2int(string s){
    reverse(s.begin(), s.end());
    int cnt = 0;
    int d = 1;
    int tmp = 0;
    bool minus = false;
    bool ten = false;
    for(auto c: s){
        if(c == '-'){
            minus = true;
            continue;
        }
        if(c == '.'){
            ten = true;
            continue;
        }
        if(!ten) cnt ++;
        tmp += d * (c -'0');
        d *= 10;
    }
    if(!ten) tmp *= 10000;
    else{
        rep(i, 4-cnt) tmp *= 10;
    }
    if(minus) tmp *= -1;
    return tmp;
}

ll X;
ll Y;
ll R;
bool inside(ll x, ll y){
    x *= 10000;
    //y *= 1000;
    
    if((x - X)*(x - X) + (y - Y)*(y - Y) <= R * R) return true;
    return false;
}
ll xl, xr;
ll yb, yt;
ll top(ll x){
    ll ue = Y + R + 10;
    ll sita = Y;
    while(abs(ue - sita) > 1){
        ll mid = (ue + sita) / 2;

        if(inside(x, mid)) sita = mid;
        else ue = mid;
    }
    while(sita % 10000 != 0) sita --;
    return sita;
}

ll bottom(ll x){
    ll ue = Y;
    ll sita = Y - R - 10;
    while(abs(ue - sita) > 1){
        ll mid = (ue + sita) / 2;

        if(inside(x, mid)) ue = mid;
        else sita = mid;
    }
    while(ue % 10000 != 0) ue ++;
    return ue;
}

int main(){
    string sx, sy, sr; cin >> sx >> sy >> sr;
    X = str2int(sx);
    Y = str2int(sy);
    R = str2int(sr);

    xl = X - R;
    xr = X + R;
    
    while(xl % 10000 != 0) xl ++;
    while(xr % 10000 != 0) xr --;
    xl /= 10000; xr /= 10000;

    yb = yt = Y;
    while(yb % 10000 != 0) yb ++;
    while(yt % 10000 != 0) yt --;

    ll ans = 0;
    //cout << yb << " " << yt << endl;
    for(ll x = xl; x <= xr; x ++){
        //cout << x << ": ";
        ans += top(x) - yb + 10000;
        ans += yt - bottom(x) + 10000;
        //cout << top(x) << " " << bottom(x) << endl;
        if(yb == yt) ans -= 10000;
    }
    cout << ans/10000 << endl;
}