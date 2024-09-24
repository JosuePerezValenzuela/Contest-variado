#include <bits/stdc++.h>

using namespace std;
//unsigned long admite 2^64 positivo
map <unsigned long long, unsigned long long> dp;

unsigned long long aux(unsigned long long a){
    //Caso base
    if(a < 2){
        return 0;
    }
    //Ya calculamos alguna vez?
    if(dp[a]){
        return dp[a];
    }else{
        //Si es impar tenemos el de arriba y abajo son distintos
        if(a % 2){
            return dp[a] += a + aux (a/2) + aux(a/2 + 1);
        }else{
        //Si es impar basta con multiplicar por 2 ya que son iguales arriba y abajo
            return dp[a] += a + 2 * aux (a/2);
        }
    }
}

int main(){
    unsigned long long n;
    cin >> n;
    cout << aux(n);
    return 0;
}