#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

const double PI=3.14159265358979323846;

int main(){
    int n; cin >> n;
    double x0, y0; cin >> x0 >> y0;
    double x2, y2; cin >> x2 >> y2;

    double kakudo = 360.0 / (double)(n);
    double rad = kakudo * (PI / 180.0);
    double xc = (x0 + x2) / 2;
    double yc = (y0 + y2) / 2;
    x0 -= xc;
    y0 -= yc;
    double X = x0 * cos(rad) - y0 * sin(rad);
    double Y = x0 * sin(rad) + y0 * cos(rad);
    X += xc;
    Y += yc;
    cout << std::fixed << std::setprecision(15);
    cout << X << " " << Y << endl;
}