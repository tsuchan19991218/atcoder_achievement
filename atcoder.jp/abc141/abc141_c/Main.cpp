#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, q; cin >> n >> k >> q;
    vector <long long> A(q);
    for (int i = 0; i < q; i ++){
        cin >> A.at(i);
    }

    vector <long long> point(n, k);

    for (auto a: A){
        point.at(a - 1) += 1;
    }

    for (auto person: point){
        person -= q;
        if (person < 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}