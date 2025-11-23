#ifndef LISTA_OO_HPP
#define LISTA_OO_HPP

#include <string>

class Lista {
private:
    int* dados;                   // Ponteiro para o array dinâmico
    int qtde;                     // Quantidade atual de elementos
    int tam;                      // Capacidade atual do array
    static const int TAMANHO_INICIAL = 10;  // Tamanho inicial do array

    void verificaAumenta();       // Aumenta o array se necessário
    void verificaDiminui();       // Diminui o array se necessário

public:
    Lista();                     // Construtor
    ~Lista();                    // Destrutor

    bool anexar(int elemento);   // Adiciona elemento ao final
    bool inserir(int elemento, int pos);  // Insere elemento na posição
    int removerPorPosicao(int pos);        // Remove elemento pela posição
    int removerPorElemento(int elemento);  // Remove elemento pelo valor
    bool substituir(int elemento, int pos);  // Substitui elemento na posição
    int getPosicao(int elemento) const;    // Retorna a posição do elemento
    int getElemento(int pos) const;         // Retorna o elemento na posição
    int tamanho() const;                    // Retorna o tamanho atual da lista
    void print() const;                     // Imprime a lista
    std::string toString() const;           // Retorna uma string com a lista
};

#endif // LISTA_OO_HPP
