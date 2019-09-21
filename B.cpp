#include <iostream>

using namespace std;

int main(){
    int n, m, k;
    bool cond = true;
    cin >> n >> m;
    for(int i=1; i<n; i++){
        cin >> k;
        if(k > m){
            cond = false;
        }
    }
    if(cond) cout << 'S' << endl;
    else cout << 'N' << endl;
    return 0;
}