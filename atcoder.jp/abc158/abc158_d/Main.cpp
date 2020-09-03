#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int q;
    bool revers = false;
    
    cin >> s;
    cin >> q;

    deque <char> str;

    for (auto c : s) str.push_back(c);

    for (int i = 0; i < q; i ++){
        int q_1;
        cin >> q_1;
        if (q_1 == 1){
            revers = !revers;
        }
        else{
            int q_2;
            char q_3;
            cin >> q_2 >> q_3;
            if (!revers){
                if (q_2 == 1) str.push_front(q_3);
                else str.push_back(q_3);
            }
            else{
                if (q_2 == 1) str.push_back(q_3);
                else str.push_front(q_3);
            }
        } 
    }

    //if (revers) reverse(s.begin(), s.end());

    if (revers){
        for (int i = str.size() - 1; i >= 0; i --){
            cout << str[i];
        }
        cout << endl;
    }
    else{
        for (int i = 0; i < str.size(); i ++){
            cout << str[i];
        }
        cout << endl; 
    }
}