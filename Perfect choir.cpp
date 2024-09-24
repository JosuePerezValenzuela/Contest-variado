#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, sum;
    int nums[10000];
    
    //Leemos cuantos cantantes
    while(cin >> N){
        //Guardamos cada cantante
        sum = 0;
        for(int i = 0;i < N; ++i){
            cin >> nums[i];
            sum += nums[i];
        }
        //Caso en el q no se pueden igualar
        int resp = -1;
        
        //Es posible coordinar a los cantantes?
        if(sum % N == 0){
            int x = sum / N;
            resp = 1;
            //Calcular movimientos
            for(int i = 0;i < N && nums[i] < x;++i){
                resp += x - nums[i];
            }
        }   
        cout << resp << endl;
    }   
    return 0;
}