#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    double n, k; cin >> n >> k;
    double cnt = 1 + (k - 1) * (n - k) * 6;
    cnt += 3 * (n - 1);
    //cout << cnt << endl;
    //printf("%.10lf\n", (k * (n - k + 1) / (n * n * n)));
    printf("%.20lf\n", cnt / (n * n * n));
}