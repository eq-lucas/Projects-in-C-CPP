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

class ListaEncadeada
{

private:
    No *prim;
    No *fim;
    int qtde;

public:
    ListaEncadeada()
    {

        this->prim = nullptr;
        this->fim = nullptr;
        this->qtde = 0;
    }

    bool insereNoFim(int e)
    {

        No *novo = new No(e);

        if (this->fim == nullptr)
        {

            this->prim = novo;
            this->fim = novo;
            this->qtde++;

            return true;
        }

        this->fim->prox = novo;

        novo->ant = this->fim;

        novo->prox = nullptr;

        this->fim = novo;
        this->qtde++;

        return true;
    }

    int at(int pos)
    {

        if (pos < 0 || pos >= this->qtde || this->qtde == 0)
            return -999;

        No *aux;

        if (pos < this->qtde / 2)
        {

            aux = this->prim;

            for (int i = 0; i < pos; i++)
                aux = aux->prox;

            return aux->dado;
        }

        aux = this->fim;

        for (int i = this->qtde - 1; i > pos; i--)
            aux = aux->ant;

        return aux->dado;
    }

    bool insereOrdenado(int e)
    {

        if (this->fim == nullptr)
        {
            insereNoFim(e);
            return true;
        }
        No *novo = new No(e);

        this->qtde++;

        if (e <= this->prim->dado)
        {

            this->prim->ant = novo;
            novo->prox = this->prim;
            this->prim = novo;
            return true;
        }
        if (e >= this->fim->dado)
        {

            this->fim->prox = novo;
            novo->ant = this->fim;
            this->fim = novo;
            return true;
        }

        No *aux = this->prim;

        while (e >= aux->dado)
            aux = aux->prox;

        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        return true;
    }

    int removeInferiores(int valor)
    {

        No *aux = this->prim;
        No *deletar;
        int removido = 0;

        if (this->qtde == 1)

            if (valor > aux->dado)
            {

                delete aux;
                this->prim = nullptr;
                this->fim = nullptr;
                this->qtde--;
                removido++;
                return removido;
            }

        while (aux != nullptr)
        {
            if (aux->dado < valor)
            {

                if (aux == this->prim)          // como aux eh diferente de null,SE for  o primeiro ou o ultimo NO logo:
                    this->prim = aux->prox;    // as extremidades devem ser atualizadas.
                if (aux == this->fim)          // como o construtor ja faz o campos prox e ant == nullptr, logo se n foi setado
                    this->fim = aux->ant;      // eh pq nao existe estes campos, e logo eh nullptr, logo da certo...

                deletar = aux;              
                
                if(aux->ant!=nullptr) // se existir um anterior ( pq inicialmente eh setado como nullptr, logo existe um anterior)
                aux->ant->prox = aux->prox; // logo se existe um anterior, ele esta com seu prox sendo vc.

                if(aux->prox != nullptr) // o msm aqui, logo SE existe um prox, ele tem um campo chamado "anterior" q eh vc.
                aux->prox->ant = aux->ant;

                aux = aux->prox;
                delete deletar;

                this->qtde--;
                removido++;

                continue;
            }
            aux = aux->prox;
        }

        return removido;
    }

};
