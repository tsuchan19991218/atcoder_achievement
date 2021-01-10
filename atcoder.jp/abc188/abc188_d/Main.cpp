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
    ll n, c; cin >> n >> c;
    vector <pair <ll, int>> a(n), b(n); //日付と値段
    rep(i, n){
        ll _a, _b;
        ll _c;
        cin >> _a >> _b >> _c;
        a.at(i) = make_pair(_a, _c);
        b.at(i) = make_pair(_b, _c);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx_a = 0;
    int idx_b = 0;

    ll ans = 0;
    ll now_price = 0;
    int now_day = 1;
    while(idx_b < b.size()){
        ll next_price = 0;
        int next_day;
        if(idx_a >= a.size()){ //aがもうない
            next_price -= b.at(idx_b).second;
            next_day = b.at(idx_b).first + 1;
            idx_b ++;
            // while(idx_b + 1 < b.size()){
            //     next_price -= b.at(idx_b).second;
            //     next_day = b.at(idx_b).first + 1;
            //     if(b.at(idx_b) != b.at(idx_b + 1)) break;
            //     idx_b ++;
            // }
            // idx_b ++;
        }
        else if(a.at(idx_a).first < b.at(idx_b).first + 1){
            next_price += a.at(idx_a).second;
            next_day = a.at(idx_a).first;
            idx_a ++;
        }
        else if(b.at(idx_b).first + 1 < a.at(idx_a).first){
            next_price -= b.at(idx_b).second;
            next_day = b.at(idx_b).first + 1;
            idx_b ++;
            // while(idx_b + 1 < b.size()){
            //     next_price -= b.at(idx_b).second;
            //     next_day = b.at(idx_b).first + 1;
            //     if(b.at(idx_b) != b.at(idx_b + 1)) break;
            //     idx_b ++;
            // }
            // idx_b ++;
        }
        else{
            next_price += (a.at(idx_a).second - b.at(idx_b).second);
            next_day = a.at(idx_a).first;
            idx_a ++; idx_b ++;
        }


        ans += min(c, now_price) * (next_day - now_day);
        //cout << now_price << " " << ans << now_day << "-" << next_day << endl;
        now_price += next_price;
        now_day = next_day;
    }

    cout << ans << endl;
}