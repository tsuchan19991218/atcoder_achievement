#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <pair<int, int>> h_i(n);
    for(int i = 0; i < n; i ++){
        cin >> h_i.at(i).first;
        h_i.at(i).second = i + 1;
    }

    sort(h_i.rbegin(), h_i.rend());

    for(int i = 0; i < n; i ++) cout << h_i.at(i).second << endl;
}