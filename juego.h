#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

struct rango{
    int menor;
    int mayor;
};

class Juego{
    public:
        Juego():intentos(5){};
        virtual void jugar()=0;
    protected:
        int intentos;
};

class adivinar:public Juego{
    public:
        adivinar(int num):Juego(),numberToGuess(num){
            rangoNumeros.menor=1;
            rangoNumeros.mayor=100;
        }

    void jugar() override;

    private:
        int numberToGuess;
        rango rangoNumeros;

        void mostrar_intentos();
        void pista();
        bool chequear(int guess);
};
