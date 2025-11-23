
# Compila e executa o programa principal
all:
#	Compila o arquivo listaSeq.c e gera o objeto listaSeq.o
	g++ -c listaSeq.cpp
# Compila o objeto e o arquivo principal, gerando o executável main
	g++ listaSeq.o listaSeq_main.cpp -o main
# Executa o programa
	./main


# Remove arquivos objeto e executável gerados
clean:
	rm -f *.o main