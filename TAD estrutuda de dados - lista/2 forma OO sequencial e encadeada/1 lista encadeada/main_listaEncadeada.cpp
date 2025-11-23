
#include "listaEncadeada.hpp"

void testeConstrutorDestrutor1() {
  Lista* l1 = new Lista();  

  l1->anexar(10);
  l1->anexar(20);
  l1->anexar(30);
  
  
  delete l1;
 
}
void testeConstrutorDestrutor2() {
  cout << "função TESTE - inicio" << endl;
  Lista l1;  
  Lista* l2 = new Lista();  

  l1.anexar(10);
  l1.anexar(20);
  l1.anexar(30);  
 
  cout << "função TESTE - fim" << endl;
}

void testeInserir(){
  Lista* l1 = new Lista();
  l1->inserir(10, 0);
  l1->anexar(20);
  l1->anexar(30);

  l1->inserir(5, 0);    // [5,10,20,30]
  l1->print();
  l1->inserir(25, 3);   // [5,10,20,25,30]
  l1->print();
  l1->inserir(40, 5);   // [5,10,20,25,30,40]
  
  l1->print();
  l1->printInverso();

  delete l1;
}

int main() {
  cout << "função MAIN - inicio" << endl;

  // testeConstrutorDestrutor1();
  // testeConstrutorDestrutor2();

  testeInserir();






  cout << "função MAIN - fim" << endl;
  return 0;
}