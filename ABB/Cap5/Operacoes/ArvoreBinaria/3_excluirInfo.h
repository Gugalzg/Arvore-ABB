#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
  if (raiz == NULL)
        return raiz;

   if (pfc(info, raiz->info) > 0){
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    } else if (pfc(info, raiz->info) < 0){
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL){
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerda == NULL) {
            pNohArvore no = raiz->direita;
            free(raiz);
            return no;
        } else if (raiz->direita == NULL) {
            pNohArvore no = raiz->esquerda;
            free(raiz);
            return no;
        } else{
            pNohArvore aux = raiz->direita;
            while(aux->esquerda!=NULL){
                aux = aux->esquerda;
            }
            raiz->info = aux->info;
            raiz->direita = excluirInfoRecursivo(raiz->direita, aux->info, pfc);
        }
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
     pNohArvore check = buscarInfo(arvore, info, pfc);
    if (check != NULL){
        pNohArvore no = excluirInfoRecursivo(arvore->raiz, info, pfc);
        arvore->quantidadeNohs = arvore->quantidadeNohs-1;
        return 1;}
    return 0;
}

#endif
