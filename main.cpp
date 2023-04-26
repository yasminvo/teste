#include <iostream>
using namespace std;
using std::string;
#include "arvore_tad.h"

int main() {
    ArvoreBinaria R;
    R = Cria();
    Vazia(R);
    Imprime(R);
    Insere(R,40);
    EstaNaArvore(R,80);
    EstaNaArvore(R,40);
    Imprime(R);
    Retira(R,40);
    Insere(R,11);
    Insere(R,70);
    Insere(R,7);
    Insere(R,3);
    Insere(R,9);
    Insere(R,90);
    Imprime(R);
    

}