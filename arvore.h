#include <stdio.h>
#ifndef ARVORE_H
#define ARVORE_H

typedef struct Nodo {
    int chave;
    struct Nodo *esquerda;
    struct Nodo *direita;
} Nodo;

Nodo* criarNodo(int chave);
Nodo* inserir(Nodo* raiz, int chave);
Nodo* procurar(Nodo* raiz, int chave);
void imprimirEmOrdem(Nodo* raiz);
Nodo* encontrarAntecessor(Nodo* raiz, Nodo* nodo);
Nodo* encontrarFolha(Nodo* raiz);
Nodo* encontrarBecoSemSaida(Nodo* raiz);
void liberarArvore(Nodo* raiz);

#endif /* ARVORE_H */
