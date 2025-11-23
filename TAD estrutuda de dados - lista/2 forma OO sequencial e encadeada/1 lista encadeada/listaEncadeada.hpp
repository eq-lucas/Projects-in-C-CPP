#include <iostream>

using namespace std;

class No{
public: 
    int dado;
    No* prox;
    No* ant;

    No(){}

    No(int elemento){
        this->dado = elemento;
        this->ant = nullptr;
        this->prox = nullptr;    
    }
};


class Lista {
private:
    No* prim;
    No* fim;
    int qtde;
    
public:
    Lista(){
        // cout << "construtor" << endl;
        this->prim = nullptr;
        this->fim = nullptr;
        this->qtde = 0;
    }

    ~Lista() {
        // cout << "DEStrutor" << endl;
        No* aux;
        while (this->prim != nullptr) {
            aux = this->prim;
            this->prim = this->prim->prox;
            delete aux;
        }
    }

    bool anexar(int elemento){
        No* novo = new No(elemento);

        if (this->fim == nullptr){
            this->prim = novo;
        } else {
            this->fim->prox = novo;
            novo->ant = this->fim;            
        }
        this->fim = novo;
        this->qtde++;
        return true;
    }

    void print() {
        cout << "[";
        No* aux = this->prim;
        while(aux != nullptr){
            cout << aux->dado << " ";
            aux = aux->prox;
        }
        cout << "]"<< endl;
    }
    void printInverso() {
        cout << "[";
        No* aux = this->fim;
        while(aux != nullptr){
            cout << aux->dado << " ";
            aux = aux->ant;
        }
        cout << "]" << endl;
    }    

    bool inserir(int elemento, int pos){
        No* novo = new No(elemento);

        // Inserção na lista vazia
        if (this->prim == nullptr) {
            this->prim = novo;
            this->fim = novo;
            this->qtde++;

        // Inserção na primeira posição
        } else if (pos == 0){
            novo->prox = this->prim;
            novo->ant = nullptr;
            this->prim->ant = novo;
            this->prim = novo;
            this->qtde++;

        // Inserção na última posição
        } else if (pos == this->qtde){
            this->anexar(elemento);

        // Inserção no meio
        } else{
            
            // No* ref = this->getNo(pos-1);
            // this->insereDireita(novo, ref);

            No* ref = this->getNo(pos);
            this->insereEsquerda(novo, ref);

            this->qtde++;
        }
        return true;
    }
    // int lista_removerPorPosicao1(int pos, Lista* lista);

    private:
    
    No* getNo(int pos) {
        No* ref;
        if(pos < this->qtde /2){
            ref = this->prim;
            for (int i=0; i < pos; i++) {
                ref = ref->prox;
            }
        } else {
            ref = this->fim;
            for (int i=this->qtde-1; i > pos; i--) {
                ref = ref->ant;
            }
        }
        return ref;
    }
    void insereDireita(No* novo, No* ref){
        novo->ant = ref;
        novo->prox = ref->prox;
        ref->prox->ant = novo;
        ref->prox = novo;
    }
    void insereEsquerda(No* novo, No* ref){
        novo->prox = ref;
        novo->ant = ref->ant;
        ref->ant->prox = novo;
        ref->ant = novo;
    }


};