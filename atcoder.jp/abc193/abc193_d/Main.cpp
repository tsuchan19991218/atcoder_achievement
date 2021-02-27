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
    int k; cin >> k;
    string s, t; cin >> s >> t;
    vector <int> s_cnt(10), t_cnt(10);
    int s_score = 0; int t_score = 0;
    rep(i, 4){
        int s_tmp = s.at(i) - '0';
        int t_tmp = t.at(i) - '0';
        s_cnt.at(s_tmp) ++;
        t_cnt.at(t_tmp) ++;
    }

    rep(i, 10){
        s_score += i * pow(10, s_cnt.at(i));
        t_score += i * pow(10, t_cnt.at(i));
    }

    

    //cout << s_score << " " << t_score << endl;


    double ans = 0;
    for(int i = 1; i <= 9; i ++){
        for(int j = 1; j <= 9; j ++){
            int s_plus = i * pow(10, s_cnt.at(i) + 1) - i * pow(10, s_cnt.at(i));
            int t_plus = j * pow(10, t_cnt.at(j) + 1) - j * pow(10, t_cnt.at(j));

            if(s_score + s_plus <= t_score + t_plus) continue;

            double _ans = 1;
            int nokori_i = k - (s_cnt.at(i) + t_cnt.at(i));
            if(nokori_i <= 0) continue;
            _ans *= (double)(nokori_i) / (double)(9 * k - 8);

            int nokori_j = k - (s_cnt.at(j) + t_cnt.at(j));
            if(i == j) nokori_j --;
            if(nokori_j <= 0) continue;
            _ans *= (double)(nokori_j) / (double)(9 * k - 9);

            //cout << i << " " << j << " " << _ans << endl;
            ans += _ans;
        }
    }

    cout << std::fixed << std::setprecision(15);

    cout << ans << endl;

}