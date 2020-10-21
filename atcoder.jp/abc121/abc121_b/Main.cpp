#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, c; cin >> n >> m >> c;
    vector <int> b(m);
    vector <vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < m; i ++) cin >> b.at(i);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++) cin >> a.at(i).at(j);
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        int tmp = 0;
        for(int j = 0; j < m; j ++){
            tmp += b.at(j) * a.at(i).at(j);
        }
        //cout << tmp << endl;
        tmp += c;
        if(tmp > 0) cnt ++;
    }

    cout << cnt << endl;
}