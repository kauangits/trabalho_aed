#include <stdio.h>
#include <stdlib.h>
#include <time.h>


   typedef struct lava_rapido{
   int n;
   int *binario;

   }lava;


  typedef struct no{
    int k,valor;
    struct no *prox;
    int ativo;
  }no;

 typedef struct{
   no *inicio;
   no *fim;

  }fila;

  lava criar_binario(){
   lava l;
   l.n = 17;
   l.binario = (int *)malloc(l.n * sizeof(int));
   int valores[] = {0,0,1,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1};
   for (int i = 0; i < l.n; i++) {
        l.binario[i] = valores[i];
    }


   return l;

  }

   fila* criar_fila(){
   fila *f;
   f = (fila*)malloc(sizeof(fila));
   if(f == NULL){
    printf("erro ao alocar a fila");
    exit(1);
  }
    f->inicio = NULL;
    f->fim = NULL;
    printf("fila criada");
   return f;
   }


   void inserir_na_fila(fila *f,int val){
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(novo==NULL){
        printf("erro na fila");
        exit(1);

    }
    novo->valor = val;
    novo->prox = NULL;
    if(f->fim!=NULL){
      f->fim->prox = novo;

    }else{
        f->inicio = novo;
    }
    f->fim = novo;



   }

  void remocao_na_fila(fila*f){
    if(f->inicio!=NULL){
      no *remocao;
      remocao = f->inicio;
      f->inicio = f->inicio->prox;
      if(f->inicio==NULL){
        f->fim =NULL;

      }
      remocao->ativo = 0;

        free(remocao);
    }
   else{
    printf("nao tem nada para remover");

   }
  }

  /* int consultar_fila(fila *f){
       no *novo;
       novo = f->inicio;
       int tam=0;
      while(novo != NULL){
        printf("valores na fila: %d \n",novo->valor);
        novo = novo->prox;
         tam++;
       }
       return tam;



   } */

 int consultar_fila(fila *f){
       no *novo;
       novo = f->inicio;
       int tam=0;
      while(novo != NULL){
        if(novo->ativo!=0){
        printf("valores na fila: %d \n",novo->valor);
         tam++;
        }
        novo = novo->prox;

       }
       return tam;



   }


  int main(){
  int k=5,a=0;
  fila *fi;
  fi = criar_fila();
  lava l = criar_binario();
  for (int i = 0; i < l.n; i++) {
        printf("%d ", l.binario[i]);
    }
    printf("\n");
  int t=0,lavados=0,tamanho=0;


  a = consultar_fila(fi);

     for(int i=0;i<l.n;i++){

        if(l.binario[i]==0){

            if(fi->inicio!=0){
                if(t==3){
                    remocao_na_fila(fi);
                    tamanho--;
                    t=0;
                    lavados = lavados+1;

                }else{

                  t++;
                }
            }
        }else{

            if(t==3){
                remocao_na_fila(fi);
                tamanho--;
                lavados++;
                t=0;
               if(l.binario[i]==1){

                inserir_na_fila(fi,1);
                tamanho++;
               }
            }else if(tamanho!=k){

             inserir_na_fila(fi,1);


             t++;
            }

        }



     }
     a = consultar_fila(fi);
     printf("\n");
     printf("%d\n", t);
   printf("lavados: %d", lavados);
  printf("\na %d",a);

    free(fi);
    free(l.binario);




 return 0;}

