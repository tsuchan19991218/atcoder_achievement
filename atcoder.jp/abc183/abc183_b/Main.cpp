#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000; 

int main(){
    double sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;

    double b = sy + ((gy + sy) / (gx - sx)) * sx;
    cout << fixed << setprecision(20) << b * ((gx - sx) / (gy + sy)) << endl;
}