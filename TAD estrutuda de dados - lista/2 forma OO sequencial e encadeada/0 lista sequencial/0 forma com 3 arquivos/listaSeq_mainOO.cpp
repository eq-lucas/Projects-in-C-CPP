#include <iostream>
#include <string>
#include "listaOO.hpp"

using namespace std;

string passFail(bool cond) {
    return cond ? "PASS" : "FAIL";
}

void testeRemoverPorPosicao1() {
    cout << "\n--- Teste Remover Por Posicao 1 ---\n";
    Lista l1;
    l1.anexar(10);
    l1.anexar(20);
    l1.anexar(30);
    l1.anexar(40);

    cout << "Excecoes \n";
    cout << "[" << passFail(-999 == l1.removerPorPosicao(-1)) << "] Remocao de uma posicao inexistente (negativa) \n";
    cout << "[" << passFail(-999 == l1.removerPorPosicao(19)) << "] Remocao de uma posicao inexistente (maior) \n";
    cout << "[" << passFail(4 == l1.tamanho()) << "] Tamanho da lista nao deve ser alterado \n";

    cout << "Casos de teste \n";
    cout << "[" << passFail(20 == l1.removerPorPosicao(1)) << "] Remocao no Meio \n";
    cout << "[" << passFail(10 == l1.removerPorPosicao(0)) << "] Remocao do primeira \n";
    cout << "[" << passFail(40 == l1.removerPorPosicao(1)) << "] Remocao do Ultimo \n";
    cout << "[" << passFail(30 == l1.removerPorPosicao(0)) << "] Remocao do unico \n";
    cout << "[" << passFail(0 == l1.tamanho()) << "] Tamanho da lista apos remocoes \n";
}

void testeRemoverPorPosicao2() {
    cout << "\n--- Teste Remover Por Posicao 2 ---\n";
    Lista l1;
    l1.anexar(10);
    l1.anexar(20);
    l1.anexar(30);
    l1.anexar(40);

    int elementoRemovido;

    auto removerComRetorno = [&](int pos, int &elem) -> bool {
        int res = l1.removerPorPosicao(pos);
        if (res == -999) return false;
        elem = res;
        return true;
    };

    cout << "Excecoes \n";
    cout << "[" << passFail(false == removerComRetorno(-1, elementoRemovido)) << "] Remocao de uma posicao inexistente (negativa) \n";
    cout << "[" << passFail(false == removerComRetorno(19, elementoRemovido)) << "] Remocao de uma posicao inexistente (maior) \n";
    cout << "[" << passFail(4 == l1.tamanho()) << "] Tamanho da lista nao deve ser alterado \n";

    cout << "Casos de teste \n";
    cout << "[" << passFail(true == removerComRetorno(1, elementoRemovido)) << "] Remocao no Meio (retorno) \n";
    cout << "[" << passFail(20 == elementoRemovido) << "] Remocao no Meio (valor) \n";

    cout << "[" << passFail(true == removerComRetorno(0, elementoRemovido)) << "] Remocao do primeira (retorno) \n";
    cout << "[" << passFail(10 == elementoRemovido) << "] Remocao do primeira (valor) \n";

    cout << "[" << passFail(true == removerComRetorno(1, elementoRemovido)) << "] Remocao do Ultimo (retorno) \n";
    cout << "[" << passFail(40 == elementoRemovido) << "] Remocao do Ultimo (valor) \n";

    cout << "[" << passFail(true == removerComRetorno(0, elementoRemovido)) << "] Remocao do unico (retorno) \n";
    cout << "[" << passFail(30 == elementoRemovido) << "] Remocao do unico (valor) \n";

    cout << "[" << passFail(0 == l1.tamanho()) << "] Tamanho da lista apos remocoes \n";
}

void teste_substituir() {
    cout << "\n--- Teste Substituir ---\n";
    Lista l1;
    l1.anexar(10);
    l1.anexar(20);
    l1.anexar(30);

    cout << "Casos de teste \n";
    cout << "[" << passFail(true == l1.substituir(25, 1)) << "] Substituir no meio \n";
    cout << "[" << passFail(25 == l1.getElemento(1)) << "] Valor substituido \n";
    cout << "[" << passFail(3 == l1.tamanho()) << "] Tamanho da lista inalterado \n";

    cout << "Excecoes \n";
    cout << "[" << passFail(false == l1.substituir(99, -1)) << "] Substituir em posicao negativa \n";
    cout << "[" << passFail(false == l1.substituir(99, 3)) << "] Substituir em posicao invalida \n";
}

void teste_getPosicao_e_getElemento() {
    cout << "\n--- Teste GetPosicao e GetElemento ---\n";
    Lista l1;
    l1.anexar(10);
    l1.anexar(20);
    l1.anexar(30);

    cout << "Casos de teste - getElemento\n";
    cout << "[" << passFail(20 == l1.getElemento(1)) << "] Get elemento no meio \n";
    cout << "[" << passFail(10 == l1.getElemento(0)) << "] Get primeiro elemento \n";
    cout << "[" << passFail(30 == l1.getElemento(2)) << "] Get ultimo elemento \n";

    cout << "Excecoes - getElemento\n";
    cout << "[" << passFail(-999 == l1.getElemento(-1)) << "] Get elemento em posicao negativa \n";
    cout << "[" << passFail(-999 == l1.getElemento(3)) << "] Get elemento em posicao invalida \n";

    cout << "Casos de teste - getPosicao\n";
    cout << "[" << passFail(1 == l1.getPosicao(20)) << "] Get posicao do meio \n";
    cout << "[" << passFail(0 == l1.getPosicao(10)) << "] Get posicao do primeiro \n";
    cout << "[" << passFail(2 == l1.getPosicao(30)) << "] Get posicao do ultimo \n";

    cout << "Excecoes - getPosicao\n";
    cout << "[" << passFail(-1 == l1.getPosicao(99)) << "] Get posicao de elemento inexistente \n";
}

void teste_redimensionamento() {
    cout << "\n--- Teste Redimensionamento (Aumenta/Diminui) ---\n";
    Lista l1;

    cout << "Teste de aumento de capacidade\n";
    for (int i = 0; i < 10; i++) {
        l1.anexar(i * 10);
    }
    cout << "[" << passFail(10 == l1.tamanho()) << "] Tamanho da lista antes de estourar \n";

    l1.anexar(100);
    cout << "[" << passFail(11 == l1.tamanho()) << "] Tamanho da lista apos estourar \n";
    cout << "[" << passFail(100 == l1.getElemento(10)) << "] Elemento inserido apos aumento \n";

    cout << "\nTeste de diminuicao de capacidade\n";
    while (l1.tamanho() > 5) {
        l1.removerPorPosicao(0);
    }
    cout << "[" << passFail(5 == l1.tamanho()) << "] Tamanho da lista antes de diminuir \n";

    l1.removerPorPosicao(0);
    cout << "[" << passFail(4 == l1.tamanho()) << "] Tamanho da lista apos diminuir \n";

    while (l1.tamanho() > 0) {
        l1.removerPorPosicao(0);
    }
    cout << "[" << passFail(0 == l1.tamanho()) << "] Tamanho final da lista \n";
}

int main() {
    cout << "INICIO DOS TESTES\n";

    testeRemoverPorPosicao1();
    testeRemoverPorPosicao2();
    teste_substituir();
    teste_getPosicao_e_getElemento();
    teste_redimensionamento();

    cout << "\nFIM DOS TESTES\n";
    return 0;
}
