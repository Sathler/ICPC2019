#include <iostream>
#include <vector>
#include <algorithm>

#define NMAX 14

using namespace std;

struct player{
    int cards[14];
    bool wildcard;

    int passarCarta(){
        int q=10, c;
        if(wildcard){
            for(int i=13; i>=1; i++){
                if(cards[i] <= q){
                    q = cards[i]; c = i;
                }
            }
            cards[c]--;
            this->wildcard = false;
            return c;
        }
        else{
            return 0;
        }
    }

    void receberCarta(int c){
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
        }
    }
}

char card_map[14] = {'W', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K'};

int main(){

}