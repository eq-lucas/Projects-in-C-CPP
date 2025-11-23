#include <iostream>
#include <string>

using namespace std;

const bool DEBUG = false;
const int ERRO = -999999;
const int TAMANHO = 10;

class Lista {
private:
  int* dados;
  int qtde;
  int tam;


  bool verificaAumenta(){
    if (this->qtde < this->tam) return false;
    
    int novoTamanho = this->tam * 2;

    // int* novo = (int*) calloc(novoTamanho, sizeof(int));
    int* novo = new int[novoTamanho];

    // copia
    for (int i=0; i < this->qtde; i++) {
        novo[i] = this->dados[i];
    }

    // free(this->dados);
    delete[] this->dados;

    this->dados = novo;
    this->tam = novoTamanho;
    return true;    
  }

  bool verificaDiminui(){
     if ((double)this->qtde / this->tam > 0.25) return false;
    
    int novoTamanho = this->tam / 2;

    // int* novo = (int*) calloc(novoTamanho, sizeof(int));
    int* novo = new int[novoTamanho];

    // copia
    for (int i=0; i < this->qtde; i++) {
        novo[i] = this->dados[i];
    }

    // free(this->dados);
    delete[] this->dados;

    this->dados = novo;
    this->tam = novoTamanho;
    return true;
  }

public:
  Lista(){
    this->dados = new int[TAMANHO];
    this->qtde = 0;
    this->tam = TAMANHO;
  }

  ~Lista(){
    delete[] this->dados;
  }

  bool anexar(int elemento){
    verificaAumenta();
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", this->qtde, this->tam, (double)this->qtde / this->tam );

    this->dados[this->qtde] = elemento;
    this->qtde++;
    return true;
  }

  bool inserir(int elemento, int pos){
    if (pos < 0) return false;
    if (pos > this->qtde) return false;
    

    verificaAumenta();
    
    // Deslocamento
    for (int i=this->qtde; i > pos; i-- ){
        this->dados[i] = this->dados[i-1];
    }

    // memcpy(enderecoDestino, enderecoOrigem, qtdeBytesCopiados)    
    // memcpy(this->dados+pos+1, this->dados+pos, (this->qtde-pos)*sizeof(int));

    this->dados[pos] = elemento;
    this->qtde++;
    return true;    
  }
  bool substituir(int elemento, int pos){
    if (pos < 0) return false;
    if (pos >= this->qtde) return false;

    this->dados[pos] = elemento;
    return true;
  }

  int removerPorPosicao(int pos){
    if (pos < 0) return ERRO;
    if (pos >= this->qtde) return ERRO;

    int elementoRemovido = this->dados[pos];
    // deslocamento
    for (int i = pos; i < this->qtde-1; i++) {
        this->dados[i] = this->dados[i+1];
    }
    this->qtde--;

    verificaDiminui();
    if (DEBUG) printf("Ocupacao %d/%d (%.2f)\n", this->qtde, this->tam, (double)this->qtde / this->tam );    

    return elementoRemovido;

  }

  bool removerPorPosicao(int pos, int* endereco){
    if (pos < 0) return false;
    if (pos >= this->qtde) return false;

    int elementoRemovido = this->dados[pos];
    // deslocamento
    for (int i = pos; i < this->qtde-1; i++) {
        this->dados[i] = this->dados[i+1];
    }
    this->qtde--;

    verificaDiminui();

    *endereco = elementoRemovido;
    return true;  
  }

  int removerPorElemento(int elemento){
    int pos = -1;
    for (int i=0; i < this->qtde; i++) {
        if (elemento == this->dados[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return -1;

    this->removerPorPosicao(pos);
    return pos;
  }

  int getPosicao(int elemento){
    for (int i=0; i < this->qtde; i++) {
        if (elemento == this->dados[i]) {
            return i;
        }
    }
    return -1;
  }

  int getElemento(int pos){
    if (pos < 0) return ERRO;
    if (pos >= this->qtde) return ERRO;

    return this->dados[pos];
  }

  int tamanho(){
    return this->qtde;
  }

  string toString(){
    string resultado = "[";
    for (int i=0; i < this->qtde; i++) {
        resultado += to_string(this->dados[i]);
        if (i < this->qtde - 1) {
            resultado += ", ";
        }
    }
    resultado += "]";
    return resultado;
  }

  void print(){
    cout << this->toString() << endl;
  }

};


