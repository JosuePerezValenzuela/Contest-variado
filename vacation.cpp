#include <bits/stdc++.h> 
using namespace std;

//Para los dias del problema, que tanta felicidad da hacer una actividad
struct actividad{
    long long a,b,c;
};

int main(){
    long long dias;
    cin >> dias;
    //Guardaremos la felicidad que da en un vector 
    vector<actividad> v(dias+1);

    for(int i = 1; i <= dias; i++){
        cin >> v[i].a;
        cin >> v[i].b;
        cin >> v[i].c;
    }
    long long dp[dias + 1][3];
    //Caso base dp buttomUp
    dp[1][0] = v[1].a;
    dp[1][1] = v[1].b;
    dp[1][2] = v[1].c;
    //Se quiere maximizar lo que se consigue desde el dia 2 hasta el ultimo
    for(int i = 2; i <= dias; i++){
        //La felicidad que da a + el maximo entre haber hecho la actividad 1 o 2 en el dia i - 1
        dp[i][0] = v[i].a + max(dp[i-1][1], dp[i-1][2]);
        //La felicidad que da a + el maximo entre haber hecho la actividad 0 o 2 en el dia i - 1
        dp[i][1] = v[i].b + max(dp[i-1][0], dp[i-1][2]);
        //La felicidad que da a + el maximo entre haber hecho la actividad 0 o 1 en el dia i - 1
        dp[i][2] = v[i].c + max(dp[i-1][0], dp[i-1][1]);
    }
    //La mejor resp en el dia dado
    cout<< max(dp[dias][0], max(dp[dias][1], dp[dias][2])) << endl;
    return 0;
}