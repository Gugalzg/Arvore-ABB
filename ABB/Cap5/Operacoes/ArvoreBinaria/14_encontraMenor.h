#ifndef ENCONTRAMENOR_H
#define ENCONTRAMENOR_H

pNohArvore encontrarMenor(pNohArvore raiz)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->esquerda == NULL)
    {
        return raiz;
    }

    return encontrarMenor(raiz->esquerda);
}

#endif
