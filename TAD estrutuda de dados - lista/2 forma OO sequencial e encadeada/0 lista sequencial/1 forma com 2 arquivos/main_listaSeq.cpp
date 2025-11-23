#include <iostream>
#include "listaSeq.hpp"

using namespace std;

void testeConstrutorDestrutor1() {
	Lista* l1 = new Lista();

	l1->anexar(10);
	l1->anexar(20);
	l1->anexar(30);

	cout << "testeConstrutorDestrutor1 - antes de delete: ";
	l1->print();
	delete l1;
	cout << "testeConstrutorDestrutor1 - depois de delete" << endl;
}

void testeConstrutorDestrutor2() {
	cout << "função TESTE - inicio" << endl;
	Lista l1;
	Lista* l2 = new Lista();

	l1.anexar(10);
	l1.anexar(20);
	l1.anexar(30);

	cout << "l1: "; l1.print();

	delete l2;
	cout << "função TESTE - fim" << endl;
}

void testeInserir(){
	Lista l1;
	l1.inserir(10, 0);
	l1.anexar(20);
	l1.anexar(30);

	l1.inserir(5, 0);    // [5,10,20,30]
	cout << "após inserir 5 em 0: "; l1.print();
	l1.inserir(25, 3);   // [5,10,20,25,30]
	cout << "após inserir 25 em 3: "; l1.print();
	l1.inserir(40, 5);   // [5,10,20,25,30,40]

	cout << "após inserir 40 em 5: "; l1.print();
	cout << "toString(): " << l1.toString() << endl;
}

void testeRemover(){
	Lista l;
	l.anexar(1); l.anexar(2); l.anexar(3); l.anexar(4);
	cout << "inicial: "; l.print();

	int r = l.removerPorPosicao(1);
	cout << "removerPorPosicao(1) -> " << r << endl;
	cout << "depois: "; l.print();

	int valor = -1;
	bool ok = l.removerPorPosicao(0, &valor);
	cout << "removerPorPosicao(0, &valor) -> ok=" << ok << " valor=" << valor << endl;
	cout << "depois: "; l.print();

	int pos = l.removerPorElemento(3);
	cout << "removerPorElemento(3) -> pos=" << pos << endl;
	cout << "depois: "; l.print();
}

void testeResize(){
	Lista l;
	for (int i=0;i<50;i++) l.anexar(i);
	cout << "apos anexar 50 elementos: tamanho=" << l.tamanho() << "\n";

	// remover muitos elementos para forçar diminuição
	for (int i=0;i<48;i++) l.removerPorPosicao(0);
	cout << "apos remover 48 elementos: tamanho=" << l.tamanho() << " conteudo=" << l.toString() << "\n";
}

int main() {
	cout << "função MAIN - inicio" << endl;

	testeConstrutorDestrutor1();
	testeConstrutorDestrutor2();
	testeInserir();
	testeRemover();
	testeResize();

	cout << "função MAIN - fim" << endl;
	return 0;
}

