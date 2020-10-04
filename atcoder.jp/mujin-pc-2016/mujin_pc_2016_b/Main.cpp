#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 1000000000;
const double PI=3.14159265358979323846;

int main(){
    double oa, ab, bc; cin >> oa >> ab >> bc;
    double m, M;
    m = oa; M = oa;

    if(m <= ab && ab <= M) m = 0;
    else m = min(abs(m - ab), abs(M - ab));
    M += ab;

    if(m <= bc && bc <= M) m = 0;
    else m = min(abs(m - bc), abs(M - bc));
    M += bc;

    printf("%.10lf\n", (M * M - m * m) * PI);
}