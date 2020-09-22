#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    vector <string> A(10);
    pair <int, int> land = make_pair(-1, -1);

    rep(i, 10){
        cin >> A.at(i);
    }
    
    rep(y, 10)rep(x, 10){
        if(A.at(y).at(x) != 'x') continue;
        vector <vector<int>> can_move(10, vector<int>(10, -1));
        can_move.at(y).at(x) = 1;
        pair <int, int> s_pos = make_pair(y, x);
        deque <pair<int, int>> d;
        d.push_back(s_pos);
        while(!d.empty()){
            auto v = d.front();
            d.pop_front();
            rep(i, 4){
                int ny, nx;
                ny = v.first + dy.at(i);
                nx = v.second + dx.at(i);
                if(ny < 0 || ny >= 10 || nx < 0 || nx >= 10) continue;
                if(A.at(ny).at(nx) == 'x') continue;
                if(can_move.at(ny).at(nx) != -1) continue;
                can_move.at(ny).at(nx) = 1;
                d.push_back(make_pair(ny, nx));
            }
        }

        bool ok = true;
        rep(i, 10)rep(j, 10){
            if(A.at(i).at(j) == 'o' && can_move.at(i).at(j) == -1) ok = false;
        }
        if(ok){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}