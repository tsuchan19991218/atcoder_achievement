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

int main(){
    string s; cin >> s;
    bool is_reversed = false;
    string ans(1000000 + 5, '!');
    int start = ans.size() / 2;
    int oshiri = start;
    int atama = start - 1;
    int now = oshiri;
    for(auto c: s){
        if(c == 'R'){
            is_reversed = (!is_reversed);
            // if(now == atama) now = oshiri;
            // else now = atama;
        }
        else{
            if(is_reversed){
                if(ans.size() > 0){
                    if(ans.at(atama + 1) != c){
                        ans.at(atama) = c;
                        atama --;
                    }
                    else{
                        ans.at(atama + 1) = '!';
                        atama ++;
                    }
                }
            }
            else{
                if(ans.size() > 0){
                    if(ans.at(oshiri - 1) != c){
                        ans.at(oshiri) = c;
                        oshiri ++;
                    }
                    else{
                        ans.at(oshiri - 1) = '!';
                        oshiri --;
                    }
                }
            }
        }
        //cout << ans << " " << is_reversed << endl;
    }
    if(is_reversed) reverse(ans.begin(), ans.end());
    for(auto c: ans){
        if(c == '!')continue;
        cout << c;
    }
    // for(int i = atama + 1; i < oshiri; i ++){
    //     cout << ans.at(i);
    // }
    cout << endl;
    //cout << ans << endl;
    //cout << INF << endl;
}