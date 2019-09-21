#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long num;
    cin >> num;
    bitset<64> b (num);
    cout << (1LL << b.count()) << endl;

    return 0;
}