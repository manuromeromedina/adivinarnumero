#include<iostream>
#include "juego.h"
using namespace std;


int main(){

    srand(time(0));
    int numero_random=rand()%100+1;
    adivinar Juego(numero_random);
    Juego.jugar();
    return 0;

}


void adivinar::mostrar_intentos(){
    cout<<"Tienes "<<intentos<<" intentos restantes."<<endl;

}

void adivinar::pista(){
    cout<<"El numero a adivinar esta entre "<<rangoNumeros.menor<<" y "<<rangoNumeros.mayor<<endl;

}

bool adivinar::chequear(int guess){
    if(guess==numberToGuess){
        cout<<"¡Felicitaciones! El numero era "<<numberToGuess<<endl;
        return true;
    } else {
        intentos--;
        if(guess<numberToGuess){
            rangoNumeros.menor=guess+1;
        } else {
            rangoNumeros.mayor=guess-1;
        }
        if(intentos==0){
            cout<<"Lo siento no adivinaste. El numero era "<<numberToGuess<<endl;
        } else{
            pista();
        }
        return false;
        
    }
}


void adivinar::jugar(){
    int guess;
    while(intentos>0){
        mostrar_intentos();
        cout<<"Adivina el numero: ";
        cin>>guess;
        if(chequear(guess)){
            break;
        }
    }
}