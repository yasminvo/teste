#include <iostream>
using namespace std;
using std::string;


struct node {
    int info;
    struct node *dir;
    struct node *esq;
};
typedef struct node *ArvoreBinaria;


// esta na arvore, vazia, cria, insere, retira, + 2 operações nao primitivas

ArvoreBinaria Cria() {
    ArvoreBinaria R;
    R = NULL;
    cout << "A raiz foi criada com sucesso!" << endl;
    return R;
    
}

int Vazia(ArvoreBinaria X) {
    if (X == NULL) {
        cout << "A ávore está vazia" << endl;
        return 1; 
    }
    cout << "A árvore não está vazia" << endl;
    return 0;
}

int EstaNaArvore(ArvoreBinaria X, int ch) {
    if (X == NULL) {
        cout << "O valor " << ch << " não está na árvore." << endl;
        return 0;
    }
    else {
        if (X->info == ch) {
        cout << "O valor " << ch << " está na árvore." << endl;            
            return 1;
        }
        else {
            if (ch>X->info) {
                return EstaNaArvore(X->dir, ch);
            }
            else {
                return EstaNaArvore(X->esq, ch);
            }
        }
    }
}

void Insere(ArvoreBinaria &X, int ch) {
    if (X==NULL) {
        ArvoreBinaria N;
        N = new node;
        N->info = ch;
        N->dir = NULL;
        N->esq = NULL;
        X = N;
        cout << "O elemento foi inserido com sucesso" << endl;
    }
    else {
        if (ch>(X->info)) {
            Insere((*X).dir,ch);
        }
        else {
            Insere((*X).esq,ch);
        }
    }
}

int Retira(ArvoreBinaria &X, int ch) {
    if (X == NULL) {
        cout << "O elemento não está na árvore e, portanto, não pode ser retirado." << endl;
        return 0;
    }
    else {
        if (ch > X->info) {
            Retira(X->dir, ch);
        }
        else {
            if (ch < X-> info) {
                Retira(X->esq, ch);
            }
        }
        cout << "O elemento está na árvore e, portanto, pode ser retirado." << endl;
        ArvoreBinaria Aux;
        Aux = X;
        // SE TIVER ZERO NÓS:
        if (X->dir == NULL && X->esq == NULL) {
            X = NULL;
            // delete Aux;
        }
        else {
        // SE TIVER DOIS FILHOS
            if (X->dir !=NULL && X->esq != NULL) {
                Aux = X->esq;
                while (Aux->dir != NULL) {
                    Aux = Aux->dir;
                }
                X->info = Aux->info;
        // TIRAR ELEMENTO REPETIDO
            Retira(X->esq, X->info);
            }
            else {
        // SE TIVER SÓ UM FILHO
                if (X->esq = NULL) {
                    X = X->dir;
                }
                else {
                    X = X->esq;
                }
                // delete Aux;
            }
            
        }


    }
    return 1;
}

void Imprime(ArvoreBinaria X) {
    if (X!=NULL) {
        cout << X->info << endl;
        Imprime(X->esq);
        Imprime(X->dir);
    }

}