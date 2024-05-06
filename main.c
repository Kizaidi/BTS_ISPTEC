#include <stdio.h>
#include "arvore.h"
#include "menu.h"
#include "util.h"

int main()
{
    Nodo *raiz = NULL;
    char opcao;
    int chave, chaveEncontrada;
    Nodo *nodoEncontrado;
    Nodo *antecessor;
    Nodo *folha;
    Nodo *becoSemSaida;

    do
    {
        mostrarMenu();
        scanf(" %c", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 'a':
            printf("Digite a chave a ser inserida: ");
            scanf("%d", &chave);
            raiz = inserir(raiz, chave);
            break;
        case 'b':
            printf("Opção de remoção ainda não implementada.\n");
            break;
        case 'c':
            printf("Digite a chave a ser procurada: ");
            scanf("%d", &chave);
            nodoEncontrado = procurar(raiz, chave);
            if (nodoEncontrado != NULL)
                printf("Nó com chave %d encontrado.\n", chave);
            else
                printf("Nó com chave %d não encontrado.\n", chave);
            break;
        case 'd':
            printf("Travessia em ordem: ");
            imprimirEmOrdem(raiz);
            printf("\n");
            break;
        case 'e':
            printf("Digite a chave para encontrar o antecessor: ");
            scanf("%d", &chaveEncontrada);
            nodoEncontrado = procurar(raiz, chaveEncontrada);
            if (nodoEncontrado != NULL)
            {
                antecessor = encontrarAntecessor(raiz, nodoEncontrado);
                if (antecessor != NULL)
                    printf("Antecessor de %d é %d.\n", nodoEncontrado->chave, antecessor->chave);
                else
                    printf("Nenhum antecessor encontrado para %d.\n", nodoEncontrado->chave);
            }
            else
            {
                printf("Nó com chave %d não encontrado.\n", chaveEncontrada);
            }
            break;

        case 'f':
            folha = encontrarFolha(raiz);
            if (folha != NULL)
                printf("Nó folha encontrado com chave %d.\n", folha->chave);
            else
                printf("Nenhum nó folha encontrado.\n");
            break;
        case 'g': // Caso para encontrar becos sem saída
            becoSemSaida = encontrarBecoSemSaida(raiz);
            if (becoSemSaida != NULL)
                printf("Beco sem saída encontrado com chave %d.\n", becoSemSaida->chave);
            else
                printf("Nenhum beco sem saída encontrado.\n");
            break;
        case 'x':
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida. Por favor, escolha novamente.\n");
        }
    } while (opcao != 'x');

    liberarArvore(raiz); // Liberando a memória alocada para a árvore

    return 0;
}
