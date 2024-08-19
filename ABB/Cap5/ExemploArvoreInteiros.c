#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Arvore.h"
#include "Utils.h"
#include "ArvoreBinaria.h"

int main() {
    int opcao, valor, raizarvore;
    pDArvore pArvoreInt;

    printf("Informe valor para a raiz da arvore: ");
    scanf("%d", &raizarvore);
    pArvoreInt = criarArvore(sizeof(int));
    incluirInfo(pArvoreInt, alocaInt(raizarvore), comparaInt);

    do {
        printf("\n----- Menu -----");
        printf("\n1 - Inserir valor");
        printf("\n2 - Mostrar árvore");
        printf("\n3 - Buscar valor");
        printf("\n4 - Excluir valor");
        printf("\n5 - Medir desempenho de inserção");
        printf("\n0 - Sair");

        printf("\n\nInforme opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                incluirInfo(pArvoreInt, alocaInt(valor), comparaInt);
                break;

            case 2:
                desenhaArvore(pArvoreInt, imprimeInt);
                break;

            case 3:
                printf("Digite valor para busca: ");
                scanf("%d", &valor);
                if (buscarInfo(pArvoreInt, alocaInt(valor), comparaInt)) {
                    printf("\nValor %d foi encontrado!", valor);
                } else {
                    printf("\nValor nao encontrado!");
                }
                break;

            case 4:
                printf("Digite valor para ser excluido: ");
                scanf("%d", &valor);
                if (excluirInfo(pArvoreInt, alocaInt(valor), comparaInt)) {
                    printf("\nValor %d excluido!", valor);
                } else {
                    printf("\nValor nao encontrado para exclusao!");
                }
                break;

            case 5:
                performanceAbb();
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    // Aqui você deve liberar a memória da árvore principal
    // Por exemplo: liberarArvore(pArvoreInt);

    return 0;
}
