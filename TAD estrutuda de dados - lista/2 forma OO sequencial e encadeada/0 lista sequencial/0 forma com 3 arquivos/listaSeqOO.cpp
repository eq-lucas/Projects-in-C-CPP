#include "listaOO.hpp"
#include <iostream>
#include <string>

using namespace std;

// Métodos privados

void Lista::verificaAumenta() {
    if (qtde < tam) return;

    int novoTamanho = tam * 2;
    int* novo = new int[novoTamanho];

    for (int i = 0; i < qtde; i++) {
        novo[i] = dados[i];
    }

    delete[] dados;
    dados = novo;
    tam = novoTamanho;
}

void Lista::verificaDiminui() {
    if ((double)qtde / tam > 0.25) return;

    int novoTamanho = tam / 2;
    if (novoTamanho < TAMANHO_INICIAL) return; // Não diminuir abaixo do inicial

    int* novo = new int[novoTamanho];

    for (int i = 0; i < qtde; i++) {
        novo[i] = dados[i];
    }

    delete[] dados;
    dados = novo;
    tam = novoTamanho;
}

// Construtor
Lista::Lista() {
    dados = new int[TAMANHO_INICIAL];
    qtde = 0;
    tam = TAMANHO_INICIAL;
}

// Destrutor
Lista::~Lista() {
    delete[] dados;
}

// Métodos públicos

bool Lista::anexar(int elemento) {
    verificaAumenta();
    dados[qtde++] = elemento;
    return true;
}

bool Lista::inserir(int elemento, int pos) {
    if (pos < 0 || pos > qtde) return false;

    verificaAumenta();

    for (int i = qtde; i > pos; i--) {
        dados[i] = dados[i - 1];
    }
    dados[pos] = elemento;
    qtde++;
    return true;
}

int Lista::removerPorPosicao(int pos) {
    if (pos < 0 || pos >= qtde) return -999;

    int removido = dados[pos];
    for (int i = pos; i < qtde - 1; i++) {
        dados[i] = dados[i + 1];
    }
    qtde--;

    verificaDiminui();
    return removido;
}

int Lista::removerPorElemento(int elemento) {
    int pos = -1;
    for (int i = 0; i < qtde; i++) {
        if (dados[i] == elemento) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return -1;

    removerPorPosicao(pos);
    return pos;
}

bool Lista::substituir(int elemento, int pos) {
    if (pos < 0 || pos >= qtde) return false;
    dados[pos] = elemento;
    return true;
}

int Lista::getPosicao(int elemento) const {
    for (int i = 0; i < qtde; i++) {
        if (dados[i] == elemento) return i;
    }
    return -1;
}

int Lista::getElemento(int pos) const {
    if (pos < 0 || pos >= qtde) return -999;
    return dados[pos];
}

int Lista::tamanho() const {
    return qtde;
}

void Lista::print() const {
    cout << "[";
    for (int i = 0; i < qtde; i++) {
        cout << dados[i];
        if (i < qtde - 1) cout << ",";
    }
    cout << "]" << endl;
}

string Lista::toString() const {
    string str = "[";
    for (int i = 0; i < qtde; i++) {
        str += to_string(dados[i]);
        if (i < qtde - 1) str += ",";
    }
    str += "]";
    return str;
}
