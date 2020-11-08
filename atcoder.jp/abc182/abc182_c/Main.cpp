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
    string n; cin >> n;
    int ans = INF;
    int size = n.size();

    int all_pat = pow(2, size);

    for(int pat = 1; pat < all_pat; pat ++){
        int tmp = 0;
        int cnt = 0;
        for(int i = 0; i < size; i ++){
            if((pat >> i) & 1){
                cnt ++;
                tmp += n.at(i) - '0';
            }
        }
        if(tmp % 3 == 0 && cnt != 0){
            ans = min(ans, size - cnt);
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}