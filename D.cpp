#include <bits/stdc++.h>

using namespace std;


int n, k, pai[100001], Dist[100001], folha[100001], Marcacao[100001];
vector<int> filhos[100001];

//define parametro de comparacao para o construtor da priority queue
bool comp(int a, int b){
    return Dist[a] < Dist[b];
}

priority_queue<int,vector<int>, decltype(&comp)> Q(&comp);

//guarda para cada vertice a folha mais distante e sua distancia
void DP(int n){
    for(vector<int>::iterator it = filhos[n].begin(); it != filhos[n].end(); it++){
        DP(*it);
    }
    if(filhos[n].empty()){
        Dist[n] = 0; folha[n] = n;
    }
    else{
        for(vector<int>::iterator it = filhos[n].begin(); it != filhos[n].end(); it++){
            if(Dist[*it]+1 > Dist[n]){
                Dist[n] = Dist[*it]+1;
                folha[n] = folha[*it];
            }
        }
    }
}

//Marca cada folha removida e todos os seus pais, assim como coloca os novos ramos 
//gerados na fila de prioridade
void Remove(int n){
    Marcacao[n] = 1;
    for(vector<int>::iterator it = filhos[n].begin(); it != filhos[n].end(); it++){
        if(!Marcacao[*it]){
            Q.push(*it);
        }
    }
    if(!Marcacao[pai[n]]) Remove(pai[n]);
}

int main(void){
    int num, count=0;
    cin >> n >> k;
    for(int i = 2; i <= n; i++){
        cin >> num;
        pai[i] = num;
        filhos[num].push_back(i);
    }
    DP(1);
    Q.push(1);
    for(int i=0; i<k; i++){
        if(!Q.empty()){
            count += Dist[Q.top()] +1;
            Remove(folha[Q.top()]);
            Q.pop();
        }
    }
    cout << count << endl;
    return 0;
}