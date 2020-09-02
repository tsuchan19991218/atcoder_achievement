#include <bits/stdc++.h>
using namespace std;

int main() {
    int pattern;
    int price, N;
    string txt;
    cin >> pattern;
    if (pattern == 1){
        cin >> price;
        cin >> N;
        cout << N * price << endl;
    }
    else if (pattern == 2){
        cin >> txt;
        cin >> price;
        cin >> N;
        cout << txt << "!" << endl;
        cout << N * price << endl;
    }
        

}