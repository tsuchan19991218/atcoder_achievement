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
    string s; cin >> s;
    ll a_seq = 0;
    ll bc_seq = 0;
    ll ans = 0;
    bool a_cnt_flag = true;
    bool b, c;
    b = c = false;
    for(int i = 0; i < s.size(); i ++){

        if(a_cnt_flag){
            if(a_seq == 0 && s.at(i) == 'A'){
                a_seq = 1;
                continue;
            }
            
            if(a_seq > 0 && s.at(i) == 'A'){
                a_seq ++;
                continue;
            }

            if(a_seq > 0 && s.at(i) == 'B'){
                b = true;
                a_cnt_flag = false;
            }

            if(s.at(i) == 'C') a_seq = 0;
        }
        else{
            if(b && !c && s.at(i) == 'C'){
                c = true;
                b = false;
                bc_seq ++;
                continue;
            }
            if(!b && c && s.at(i) == 'B'){
                b = true;
                c = false;
                continue;
            }

            // if(bc_seq == 0){
            //     b = false;
            //     c = false;
            //     a_cnt_flag = true;
            //     a_seq = 0;
            //     if(s.at(i) == 'A') a_seq ++;
            //     continue;
            // }

            ans += a_seq * bc_seq;
            bc_seq = 0;
            if(!(!b && c && s.at(i) == 'A')) a_seq = 0;
            if(s.at(i) == 'A') a_seq ++;
            a_cnt_flag = true;
            b = false;
            c = false;
            //cout << i << endl;
        }
    }

    ans += a_seq * bc_seq;
    cout << ans << endl;
}