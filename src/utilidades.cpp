#include <iostream>
#include <vector>
#include <string>
using namespace std;
void menu(vector<string> opcoes){
    cout<<"==============================| "<<opcoes[0]<<" |=============================="<<endl;
    for(int i=1; i<opcoes.size(); i++){
        cout<<i<<" - "<<opcoes[i]<<endl;
    }
    for(int i=0; i<64+opcoes[0].size(); i++){
        cout<<"=";
    }
    cout<<endl;
};

