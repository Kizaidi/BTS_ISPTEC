#include "arvore.h"
#include <stdlib.h>

Nodo* criarNodo(int chave) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->chave = chave;
    novoNodo->esquerda = novoNodo->direita = NULL;
    return novoNodo;
}

Nodo* inserir(Nodo* raiz, int chave) {
    if (raiz == NULL)
        return criarNodo(chave);

    if (chave < raiz->chave)
        raiz->esquerda = inserir(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = inserir(raiz->direita, chave);

    return raiz;
}

Nodo* procurar(Nodo* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave)
        return raiz;

    if (chave < raiz->chave)
        return procurar(raiz->esquerda, chave);
    
    return procurar(raiz->direita, chave);
}

void imprimirEmOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->direita);
    }
}

Nodo* encontrarAntecessor(Nodo* raiz, Nodo* nodo) {
    Nodo* antecessor = NULL;
    while (raiz != NULL) {
        if (nodo->chave > raiz->chave) {
            antecessor = raiz;
            raiz = raiz->direita;
        } else if (nodo->chave < raiz->chave) {
            raiz = raiz->esquerda;
        } else {
            if (raiz->esquerda != NULL) {
                raiz = raiz->esquerda;
                while (raiz->direita != NULL)
                    raiz = raiz->direita;
                antecessor = raiz;
            }
            break;
        }
    }
    return antecessor;
}

Nodo* encontrarFolha(Nodo* raiz) {
    if (raiz == NULL)
        return NULL;
    
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return raiz;

    Nodo* folhaEsquerda = encontrarFolha(raiz->esquerda);
    Nodo* folhaDireita = encontrarFolha(raiz->direita);

    return (folhaEsquerda != NULL) ? folhaEsquerda : folhaDireita;
}

void liberarArvore(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

Nodo* encontrarBecoSemSaida(Nodo* raiz) {
    if (raiz == NULL)
        return NULL;

    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return raiz;

    Nodo* becoEsquerda = encontrarBecoSemSaida(raiz->esquerda);
    Nodo* becoDireita = encontrarBecoSemSaida(raiz->direita);

    return (becoEsquerda != NULL) ? becoEsquerda : becoDireita;
}