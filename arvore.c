#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    //...
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

void in_ordem(NO* pt){
    if(pt->esq != NULL){
         in_ordem(pt->esq);
    }
    printf("\n%d ", pt->chave);
    //qualquer processamento! Ex: imprimindo
    if(pt->dir != NULL){
       in_ordem(pt->dir);
    }
}


NO* busca_arvore (int x, NO* pt){
    if(pt == NULL){
        return NULL; //vazia :D
    }else if(x == pt->chave){
        return pt; // encontrei :D
    }else if(x < pt->chave){ //lado esq
        if(pt->esq == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else { //lado dir
        if(pt->dir == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

void insercao_arvore(int x){
    NO* pt = busca_arvore(x, raiz); // usa a busca para encontrar
                                // a posicao do no novo
    if(pt == NULL || pt->chave != x){
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;

        if(pt == NULL){ //vazia - raiz
            raiz = novo;
        }else if(x < pt->chave){ //elemento x <pt-> chave - esq
            pt->esq = novo;
        }else{                  //elemento x >pt-> chave - dir
            pt->dir = novo;
        }
    }else{
         printf("insercao invalida! :/");
    }
}
NO*remove_no(NO*pont, int valor){
    if(pont==NULL){//conferindo se a arvore esta vazia ou n
        printf("\nA arvore esta vazia!!! %d");
        return pont;
    }else if(valor < pont->chave){
        pont->esq = remove_no(pont->esq, valor);
    }else if(valor > pont->chave){
        pont->dir = remove_no(pont->dir,valor);
    }else{
        if(pont->dir == NULL && pont->esq == NULL){//remo de no a ser removido eh uma folha
            free(pont);
            pont=NULL;
            printf("\nRemovendo folha %d",valor);
        }else if(pont->esq == NULL){//os dois proximos casos servem para remover o no quando ele tem apenas um filho
            NO*aux = pont;
            pont = pont->dir;
            free(aux);
            printf("\nEncontramos apenas o filho %d, removemos o no da esquerda.",valor);
        }else if(pont->dir == NULL){
            NO*aux = pont;
            pont = pont->esq;
            free(aux);
            printf("\nEncontramos apenas o filho %d, removemos o no da direita.",valor);
        }
        else{// quando ele tem filhos para os dois lados, fazemos com que ele pegue o sucessor
            NO*aux = pont->dir;
            pont->chave=aux->chave;
            pont->dir = remove_no(pont->dir,aux->chave);
            printf("\nRemovendo no com dois filhos %d",valor);
            }
        }
    return pont;
}



int main(){


    insercao_arvore(10);
    insercao_arvore(2);
    insercao_arvore(6);
    insercao_arvore(9);
    insercao_arvore(15);
    insercao_arvore(18);
    insercao_arvore(29);
    insercao_arvore(11);
    insercao_arvore(21);
    insercao_arvore(23);
    insercao_arvore(34);
    insercao_arvore(55);
    insercao_arvore(31);
    insercao_arvore(22);
    insercao_arvore(17);
    insercao_arvore(1);
    insercao_arvore(30);
    insercao_arvore(44);
    insercao_arvore(42);
    insercao_arvore(12);
    insercao_arvore(5);
    insercao_arvore(36);
    insercao_arvore(50);
    insercao_arvore(46);
    insercao_arvore(20);

    remove_no(raiz,1);
    remove_no(raiz,5);
    remove_no(raiz,9);
    remove_no(raiz,12);
    remove_no(raiz,29);
    remove_no(raiz,44);
    remove_no(raiz,55);
    remove_no(raiz,18);
    remove_no(raiz,50);
    remove_no(raiz,15);
    remove_no(raiz,6);
    remove_no(raiz,11);
    remove_no(raiz,10);
    remove_no(raiz,2);


    in_ordem(raiz);


    return 0;
}
