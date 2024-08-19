#ifndef PERFORMANCE_FUNCTIONS_ARVORE_BINARIA_H
#define PERFORMANCE_FUNCTIONS_ARVORE_BINARIA_H

#include <stdlib.h>
#include <time.h>

int* gerarDadoAleatorio(int size) {
    int* data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % (size * 10); // Gera números entre 0 e size*10-1
    }
    return data;
}

double medirTempoInsercao(pDArvore arvore, int* data, int size) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (int i = 0; i < size; i++) {
        int* pdata = alocaInt(data[i]);
        incluirInfo(arvore, pdata, comparaInt);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double medirTempoBusca(pDArvore arvore, int* data, int size) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (int i = 0; i < size; i++) {
        int* pdata = alocaInt(data[i]);
        buscarInfo(arvore, pdata, comparaInt);
        free(pdata);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double medirTempoExclusao(pDArvore arvore, int* data, int size) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (int i = 0; i < size; i++) {
        int* pdata = alocaInt(data[i]);
        excluirInfo(arvore, pdata, comparaInt);
        free(pdata);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void performanceAbb() {
    int sizes[] = {1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    printf("\nTamanho do conjunto | Tempo Insercao (s) | Tempo Busca (s) | Tempo Exclusao (s)\n");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int* data = gerarDadoAleatorio(size);
        pDArvore testArvore = criarArvore(sizeof(int));

        // Medição do tempo de inserção
        double insertionTime = medirTempoInsercao(testArvore, data, size);

        // Medição do tempo de busca
        double searchTime = medirTempoBusca(testArvore, data, size);

        // Medição do tempo de exclusão
        double deletionTime = medirTempoExclusao(testArvore, data, size);

        printf("%18d | %18.6f | %15.6f | %18.6f\n", size, insertionTime, searchTime, deletionTime);

        // Liberar memória
        free(data);
    }
}

#endif
