#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

pDArvore criarArvore(int valorRaiz)
{
    pDArvore dArvore = malloc(sizeof(DArvore));
    dArvore->raiz = malloc(sizeof(NohArvore));
    dArvore->raiz->info = alocaInt(valorRaiz);
    dArvore->raiz->esquerda = NULL;
    dArvore->raiz->direita = NULL;
    dArvore->quantidadeNohs = 1;
    dArvore->grau = 2; // Supondo que � uma �rvore bin�ria
    return dArvore;
}

#endif
