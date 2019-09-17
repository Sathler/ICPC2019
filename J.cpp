#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define NMAX 14

using namespace std;

struct player{
    int cards[14];
    bool wildcard;

    int passarCarta(){
        int q=10, c;
        //cout << "passei " << endl;
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
        else if(cards[0]> 0){
            cards[0]--;
            return 0;
        }
    }

    void receberCarta(int c){
        //cout << "recebi " << c << endl;
        cards[c]++;
        if(c == 0){
            this->wildcard = true;
        }
    }

    bool vencer(){
        bool cond;
        for(int i=1; i<=13; i++){
            if(cards[i] == 4){
                return true;
            }
            if(cards[i] > 0 && cards[i] < 4){
                return false;
            }
        }
        return false;
    }

    void printCards(){
        for(int i=0; i<14; i++){
            cout << cards[i] << " ";
        }
        cout << endl;
    }
};

player Jogador[NMAX];
map<char, int> card_map;

void initMap(){
    card_map['W'] = 0; card_map['1'] = 1; card_map['2'] = 2; card_map['3'] = 3; 
    card_map['4'] = 4; card_map['5'] = 5; card_map['6'] = 6; card_map['7'] = 7; 
    card_map['8'] = 8; card_map['9'] = 9; card_map['D'] = 10; card_map['Q'] = 11; 
    card_map['J'] = 12; card_map['K'] = 13;
}

int main(){
    int n, k, winner, atual, prox;
    char c;
    initMap();
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=0; j<4; j++){
            cin >> c;
            Jogador[i].receberCarta(card_map[c]);
        }
    }
    Jogador[k].receberCarta(0);
    atual = k; prox = (k%n)+1;
    while(true){
        Jogador[prox].receberCarta(Jogador[atual].passarCarta());
        /*for(int i=1; i<=n; i++){
            Jogador[i].printCards();
        }
        cout << endl << endl;*/
        if(Jogador[atual].vencer()){
            winner = atual;
            break;
        }
        atual = prox; prox = (atual%n)+1;
    }
    cout << winner << endl;
}