#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 100000000;

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

pair <int, int> range;

int main(){
    int n; cin >> n;
    vector <int> d(n);
    rep(i, n) cin >> d.at(i);
    int M = 0; int m = 0;
    rep(i, n){
        M += d.at(i);
        if(i == 0){
            range = make_pair(d.at(i), d.at(i));
            m = d.at(i);
            continue;
        }
        int l = range.first;
        int r = range.second;

        if(l <= d.at(i) && r >= d.at(i)){
            l = 0;
        }
        else l = min(abs(l - d.at(i)), abs(r - d.at(i)));
        r = r + d.at(i);
        range = make_pair(l, r);
        m = l;
    }

    cout << M << endl;
    cout << m << endl;

}