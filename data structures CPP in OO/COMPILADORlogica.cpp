#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class No
{
public:
    char dado;
    No *prox;
    No *ant;

    No(char elemento)
    {
        this->dado = elemento;
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

    ~Pilha()
    {
        No *aux;
        while (this->topo != nullptr)
        {
            aux = this->topo;
            this->topo = this->topo->prox;
            delete aux;
        }
    }

    bool push(char elemento)
    {
        No *novo = new No(elemento);

        if (this->topo != nullptr)
        {
            novo->prox = this->topo;
            this->topo->ant = novo;
        }

        this->topo = novo;
        this->qtde++;
        return true;
    }

    char pop()
    {
        if (this->topo == nullptr)
        {
            return '\0';
        }

        No *aux = this->topo;
        char valor = aux->dado;

        this->topo = this->topo->prox;
        if (this->topo != nullptr)
            this->topo->ant = nullptr;

        delete aux;
        this->qtde--;

        return valor;
    }

    char top()
    {
        if (this->topo == nullptr)
        {
            return '\0';
        }
        return this->topo->dado;
    }

    bool vazia()
    {
        return this->topo == nullptr;
    }
};

bool delimitadoresBalanceados(const string &nomeArquivo)
{
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        cout << "[ERRO] Não foi possível abrir o arquivo!" << endl;
        return false;
    }

    Pilha p;
    char c;

    while (arquivo.get(c))
    {
        if (c == '(' || c == '{' || c == '[')
        {
            p.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {

            if (p.vazia())
                return false;

            char topo = p.pop();

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{'))
            {
                return false;
            }
        }
    }
    return p.vazia();
}

int main()
{
    string arquivo;

    cout << "Digite o nome do arquivo: ";
    cin >> arquivo;

    if (delimitadoresBalanceados(arquivo))
        cout << "[SUCESSO] O arquivo está com os delimitadores balanceados!" << endl;
    else
        cout << "[ERRO] Delimitadores não balanceados!" << endl;

    return 0;
}
