#include <bits/stdc++.h>

using namespace std;

int maxSoldados;
int maxCaballos;
int soldado, caballo;
int dp[101][101][10][10];
int modulo = 100000000;

int aux(int soldado, int caballo, int soldadosJuntos, int caballosJuntos){
    //Si ya lo calcule
    if(dp[soldado][caballo][soldadosJuntos][caballosJuntos] != -1){
        return dp[soldado][caballo][soldadosJuntos][caballosJuntos];
    }
    //Si ya use todas mis tropas
    if(soldado + caballo == 0){
        return 1;
    }
    dp[soldado][caballo][soldadosJuntos][caballosJuntos] = 0;
    //Mi dp actual sera igual a las formas de poner un soldado + poner un caballo mas
    if(soldadosJuntos < maxSoldados and soldado > 0){
        dp[soldado][caballo][soldadosJuntos][caballosJuntos] += aux(soldado - 1, caballo, soldadosJuntos + 1, 0) % modulo;
    }
    if(caballosJuntos < maxCaballos and caballo > 0){
        dp[soldado][caballo][soldadosJuntos][caballosJuntos] += aux(soldado, caballo - 1, 0, caballosJuntos + 1) % modulo;
    }
    return dp[soldado][caballo][soldadosJuntos][caballosJuntos];
}

int main(){
    cin >> soldado >> caballo >> maxSoldados >> maxCaballos;
    //Llenamos el dp con -1
    memset(dp, -1, sizeof dp);
    cout << aux(soldado, caballo, 0, 0) << endl;
}