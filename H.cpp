#include <iostream>

using namespace std;

int main(){
    int v, n, p;
    cin >> v >> n;
    p = v*n;
    for(int i=1;i<=8; i++) cout << (p*i+10-1)/10 << " ";
    cout << (p*9+10-1)/10 << endl;
}