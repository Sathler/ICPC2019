#include <iostream>
#include <cmath>

#define MAXN 1002

using namespace std;

struct sensor{
    int x, y, r;

    //funcao que verifica se a area de deteccao de 2 sensores se encostam
    bool prox(sensor b){
        double ax = this->x, ay = this->y, ar = this->r, bx = b.x, by = b.y, br = b.r;
        if(sqrt(pow(ax-bx,2) + pow(ay-by,2)) > ar+br) return false;
        else return true;
    }
};

int n, a, b, MA[MAXN][MAXN], Marcacao[MAXN];
sensor S[MAXN];

//Busca em profundidade
void DS(int v){
    Marcacao[v] = 1;
    for(int i=0; i<=n+1; i++){
        if(MA[v][i] == 1 && Marcacao[i] == 0){
            DS(i);
        }
    }
}

int main(){
    int x, y, r;
    cin >> a >> b >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> y >> r;
        S[i].x = x; S[i].y = y; S[i].r = r;
        for(int j=1; j<i; j++){
            //criacao da matriz de adjacencia
            if(S[i].prox(S[j])){
                MA[i][j] = MA[j][i] = 1;
            }
        }
        //verifica se a area de deteccao do sensor encosta em uma parede
        if(S[i].x-S[i].r <= 0 || S[i].y+S[i].r >= b){
            MA[0][i] = MA[i][0] = 1;
        }
        if(S[i].x+S[i].r >= a || S[i].y-S[i].r <= 0){
            MA[n+1][i] = MA[i][n+1] = 1;
        }
    }
    DS(0);
    //verifica se existe um caminho de sensores em as 2 paredes
    if(Marcacao[n+1]) cout << "N" << endl;
    else cout << "S" << endl;
    return 0;
}