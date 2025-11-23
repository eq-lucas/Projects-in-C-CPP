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

    class Pilha
    {

    private:
        No *topo;
        int qtde;

    public:
        Pilha()
        {

            this->topo = nullptr;
            this->qtde = 0;
        }

        Pilha(int e)
        {
            No *novo = new No(e);
            this->topo = novo;
            this->qtde = 1;
        }

        bool inserir(int dado)
        {
            No *novo = new No(dado);

            this->qtde++;
            novo->ant = this->topo;

            if (this->topo != nullptr)
            {
                this->topo->prox = novo;
            }

            this->topo = novo;

            return true;
        }

        bool remover()
        {

            if (this->topo == nullptr)
                return false;

            this->qtde--;

            No *aux = this->topo;

            this->topo = aux->ant;

            if(this->topo != nullptr)
                this->topo->prox= nullptr;

            delete aux;

            return true;
        }

        ~Pilha(){

            No* aux;

            while(this->topo!=nullptr){
                
                aux=this->topo->ant;
                delete this->topo;
                this->topo= aux;

            }

        }

        int pegar_do_topo() {
    if (this->topo == nullptr) {
        std::cout<<'pilha vazia'<<std::endl;
    }
    return this->topo->dado;
}





    };
