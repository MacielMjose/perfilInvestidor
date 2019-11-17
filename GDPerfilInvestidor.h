/***********************************************/ 
/* Biblioteca para Lista Encadeada             */
/* Profa Daniela Bagatini                      */
/***********************************************/ 
#include <string.h>
#include <time.h>


/************************************************
 * gera_dados                                   *
 * objetivo: rotina para ler dados dos registros*
 * entrada : lista                              *
 * saída   : lista atualizado com dados         *
 ***********************************************/
 
 //void SetPessoa(Pessoa *P, int idade, float peso, float altura)

void gera_dados(ARVORE **r){
	 
	char  nomeTemp[50];                        // armazena nome e sobrenome temporariamente
	int   i, x;                                 // i= índice da lista; x= armazena número sorteado 
	
	//Fonte dos nomes: https://petitebox.com.br/blog/100-nomes-mais-comuns-no-brasil-em-2016/
	char *nomes[] = {
"Pergunta01", //cod 0
"Pergunta02", //cod 1
"Pergunta03", //cod 2
"Pergunta04", //cod 3
"Pergunta05", //cod 4
"Pergunta06", //cod 5
"Pergunta07", //cod 6
"Perfil01",   //cod 7
"Perfil02",   //cod 8
"Perfil03"    //cod 9
};

 ////codigo arvore binaria
  		
   	ARVORE* anterior;      // ponteiro auxiliar
    ARVORE* atual;      // ponteiro auxiliar para anterior de p
    int cod;
   // p = r;

 
for(i = 0 ; i < 10; i++) 
	{
	
		 printf("\n teste: %s",nomes[i]);
		 getchar();
		 //p = *r;
		 cod = i; 
	     //ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória
	     //no->info.codigo = cod;
	     
	     //strcpy(no->info.nome,nomes[i]); 
	     ARVORE *no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória
	     
	     if(*r == NULL)
		 {
		 		no->subd = NULL;
		 		no->sube = NULL;
		 		*r = no;
		 }
		 else
		 	atual = *r;
		 	anterior = NULL;
		 	
		 	while(atual != NULL)
		 	{
		 		anterior = atual;
		 		if(cod > no->info.codigo)
				 {
		 			no = no->subd;
		 			printf("perispecio ");

				 }
		 			else
			 			no = no->sube;		
			}
			if(cod >no->info.codigo)
			{
				no->subd = no;
				
			}else
				no->sube = no;
	}

}
