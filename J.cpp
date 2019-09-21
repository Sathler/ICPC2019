#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define NMAX 15

using namespace std;

struct player{
    int cards[14];
    bool wildcard;

    int passarCarta(){
        int q=1000, c;
        if(wildcard || cards[0] == 0){
            for(int i=13; i>=1; i--){
                if(cards[i] <= q && cards[i] > 0){
                    q = cards[i]; c = i;
                }
            }
            cards[c]--;
            this->wildcard = false;
            return c;
        }
        else{
            cards[0]--;
            return 0;
        }
    }

    void receberCarta(int c){
        cards[c]++;
        if(c == 0){
            this->wildcard = true;
        }
    }

    //verifica se o jogador venceu
    bool vencer(){
        for(int i=0; i<=13; i++){
            if(cards[i] == 4){
                return true;
            }
            if(cards[i] > 0 && cards[i] < 4){
                 return false;
            }
        }
        return false;
    }
};

player Jogador[NMAX];
map<char, int> card_map;

//Map para converter a carta lida para seu valor numerico, wildcard=0
void initMap(){
    card_map['W'] = 0; card_map['A'] = 1; card_map['2'] = 2; card_map['3'] = 3; 
    card_map['4'] = 4; card_map['5'] = 5; card_map['6'] = 6; card_map['7'] = 7; 
    card_map['8'] = 8; card_map['9'] = 9; card_map['D'] = 10; card_map['Q'] = 11; 
    card_map['J'] = 12; card_map['K'] = 13;
}

int main(){
    int n, k, winner, atual, prox;
    char c;
    initMap(); //inicializa o map
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=0; j<4; j++){
            cin >> c;
            Jogador[i].receberCarta(card_map[c]);
        }
    }
    Jogador[k].receberCarta(0); //entrega a wildcard para o jogador inicial
    atual = k; prox = (k%n)+1; 

    //verifica se alguem vence ja na primeira rodada <<IMPORTANTE>>
    for(int i=1; i<=n; i++){ 
        if(Jogador[i].vencer()){
            cout << i << endl;
            return 0;
        }
    }

    //inicio da simulacao
    while(true){
        Jogador[prox].receberCarta(Jogador[atual].passarCarta());
        if(Jogador[atual].vencer()){
            cout << atual << endl;
            return 0;
        }
        atual = prox; prox = (atual%n)+1;
    }
}