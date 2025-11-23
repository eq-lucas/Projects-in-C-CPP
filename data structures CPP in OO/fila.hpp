#include <iostream>

class No
{
public:
    int dado;
    No *prox;
    No *ant;

    No(int dado)
    {
        this->dado = dado;
        this->prox = nullptr;
        this->ant = nullptr;
    }

    No()
    {
        this->dado = 0;
        this->prox = nullptr;
        this->ant = nullptr;
    }
};

class Fila
{

private:
    No *inicio;
    No *fim;
    int qtde;

public:
    Fila()
    {
        this->inicio = nullptr;
        this->fim = nullptr;
        this->qtde = 0;
    }

    Fila(int e)
    {
        No *novo = new No(e);
        this->inicio = novo;
        this->fim = novo;
        this->qtde = 1;
    }

    bool inserir(int dado)
    {
        No *novo = new No(dado);
        this->qtde++;

        novo->ant = this->fim;   // liga atrás
        if (this->fim != nullptr)
        {
            this->fim->prox = novo;
        }

        this->fim = novo;

        // se fila estava vazia
        if (this->inicio == nullptr)
        {
            this->inicio = novo;
        }

        return true;
    }

    bool remover()
    {
        if (this->inicio == nullptr)
            return false;

        this->qtde--;

        No *aux = this->inicio;
        this->inicio = aux->prox;

        if (this->inicio != nullptr)
            this->inicio->ant = nullptr;
        else
            this->fim = nullptr; // ficou vazia

        delete aux;

        return true;
    }

    int pegar_do_inicio()
    {
        if (this->inicio == nullptr)
        {
            std::cout << "fila vazia" << std::endl;
            return 0;
        }
        return this->inicio->dado;
    }

    int pegar_do_fim()
    {
        if (this->fim == nullptr)
        {
            std::cout << "fila vazia" << std::endl;
            return 0;
        }
        return this->fim->dado;
    }

    ~Fila()
    {
        No *aux;

        while (this->inicio != nullptr)
        {
            aux = this->inicio->prox;
            delete this->inicio;
            this->inicio = aux;
        }
    }
};
