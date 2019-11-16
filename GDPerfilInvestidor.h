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
 * sa�da   : lista atualizado com dados         *
 ***********************************************/
 
 //void SetPessoa(Pessoa *P, int idade, float peso, float altura)

void gera_dados(ARVORE **r){
	 
	char  nomeTemp[50];                        // armazena nome e sobrenome temporariamente
	int   i, x;                                 // i= �ndice da lista; x= armazena n�mero sorteado 
	
	//Fonte dos nomes: https://petitebox.com.br/blog/100-nomes-mais-comuns-no-brasil-em-2016/
	char *nomes[] = {"Miguel",
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
  		
   	ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p
    int achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura
    int cod[9];

   // printf("\n Digite o novo c�digo: ");
    //scanf("%d", &cod);
    
for(i = 0 ; i <= 9; i++) {
	
	 printf("\n teste: %s",nomes[i]);
	 getchar();
     printf("\n teste: %s",nomes[i]);
	 p = *r;
     printf("\n teste: %s",nomes[i]);
                            // posiciona ponteiro auxiliar
    //achou = busca( cod, &a, &p );      // verifica se c�digo a ser inserido j� existe na �rvore
   //	if( !achou ){                      // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
	 printf("\n teste: %s",nomes[i]);

         if( no != NULL ){             // se conseguiu alocar mem�ria, insere
         	 printf("\n teste: %s",nomes[i]);

                 no->info.codigo = cod[i];// preenche o novo registro com o c�digo j� informado
                 	 printf("\n teste: %s",nomes[i]);

                 strcpy(no->info.nome,nomes[i]); //Copia o valor de uma string para outra
                 
				// entrada_dados( no );  // *desnecessario pois usuario nao vai informar dados -- entrada do usu�rio
                 if( *r == NULL )      // verifica se a �rvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
   // } // fim if( !achou )
    else
        printf( "\n Registro j� existe!" );
}
 
/* 
//// Fim Do Codigo codigo arvore binaria
   	
	for(i = 0 ; i > 9; i++) {
		
			 NODO *no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espa�o em mem�ria
			 if( no != NULL ){                                 // verifica se conseguiu alocar mem�ria para o novo registro
			     strcpy( no->info.nome, nomes[i] );       // registra nome completo na lista
			     no->info.codigo = i;  // gerar c�digo autom�tico
			     no->prox = *l;                           // novo aponta para o primeiro existente ou para NULL (se lista vazia)
	             *l = no;                                 // in�cio aponta para o novo registro
	        }else // fim if ( no != NULL )
	             printf( "\n Lista cheia!" );		
		} 
		
	} // fim for ( i= 0; i < massa; i++ )
	printf( "\n Gerados %d registros. ", i );         // informa n�mero de registros gerados
	*/
	
//	return 0;
}
