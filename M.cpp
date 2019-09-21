#include <bits/stdc++.h>

using namespace std;

int n, c, a, b, t, media, maior = 0, vet[100010], soma[100010];

int contagem(){
    int p1 = 0, p2 = 1, cnt = 0, sum;
    while(p2 <= n){
        sum = soma[p2]-soma[p1];
        if((sum+t-1)/t > media){
            cnt++; p1 = p2-1;
        }
        else{
            p2++;
        }
    }
    if(soma[n]-soma[p1] > 0) cnt++;
    return cnt;
}

int main(void){
    int k;
    cin >> n >> c >> t;
    for(int i = 1; i <= n; i++){
        cin >> vet[i];
        soma[i] = soma[i - 1] + vet[i];
        maior = max(maior, vet[i]);
    }
    //busca binaria na solucao
    a = (maior + t - 1)/t;
    b = (soma[n] + t - 1)/t;
    while(a != b){
        media = (a + b)/2;
        k = contagem();
        if(k > c){
            a = media+1;
        }
        else{
            b = media;
        }
    }
    cout << a << endl;

    return 0;
}