/***********************************************/ 
/* �rvores Bin�rias                            */
/* objetivo: registro de c�digos               */
/* programador: Daniela Bagatini               */
/* criado em: 08/11/2017                       */
/* data da �ltima altera��o: 06/06/2018        */
/***********************************************/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>    // setlocale


#define FALSE   0      // constante falsa
#define TRUE   !FALSE  // constante verdadeira


/***********************************************/ 
/* Defini��o dos Registros                     */
/***********************************************/ 
typedef struct {          // registro 
       int  codigo;       
	   int  altura;
	   int  fatbal;
	   char nome[500]; //mudar nome dessa vari�vel depois
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   // dados do registro
       struct arv* subd;  // ponteiro para o nodo da direita
       struct arv* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 


//#include "GDPerfilInvestidor.h"


/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/
void    cria_ARVORE     ( ARVORE** r );  // inicializa �rvore com NULL
void    entrada_dados   ( ARVORE* aux ); // leitura dos dados de entrada
void gera_dados(ARVORE **r); 
void    imprime_ARVORE  ( ARVORE* aux ); // visualiza��o da �rvore em tela, todos os registros
void    insere          ( ARVORE** r );  // inclui um novo registro na �rvore, sempre na folha
void    insere_recursivo( ARVORE** r, int cod ); // inclui um novo registro na �rvore
ARVORE* busca_recursivo ( ARVORE *p, int cod ); 
ARVORE* inicia_questionario( ARVORE *p,char opt); //rotina responsavel por realizar as perguntas a fim de tra�ar o perfil do investidor
int     busca           ( int matricula, ARVORE** a, ARVORE** p ); // procura na �rvore um c�digo
ARVORE* remove_recursivo( ARVORE *p, int cod );

       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;       // op��o do menu                               
    ARVORE* r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros
    int cod, fatbal= 0, altura_esq=0, altura_dir=0;
    
    setlocale(LC_ALL, "Portuguese");
    cria_ARVORE( &r );
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registros - Menu                         " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [4] Imprime                                          " );         
		 printf( "\n [9] Gera Arvore Bin�ria - Popular �rvore             " ); 
		 printf( "\n [5] Inicia Question�rio                             " );         
		 printf( "\n [7] Para sair do programa                           " );         
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de op��o do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;
                                
           case '2':   // rotina inclui nodo no final da ARVORE (folha)
                   insere( &r );    
                   break;
           
           case '4':   // rotina imprime nodos da ARVORE
                   imprime_ARVORE( r );
                   break;                   
                   
           case '6':  // rotina recursiva que busca um registro da ARVORE                                                
                   printf("\n Buscar o codigo: ");
                   scanf("%d", &cod);
                   p= busca_recursivo( r, cod );
                   if( p != NULL )
                       printf("\n Codigo: %d", p->info.codigo);   
                   break; 
                   
           case '8':  // rotina recursiva que busca um registro da ARVORE                                                
                   //p= menor_valor( r );
                   if( p != NULL )
                       printf("\n Codigo: %d", p->info.codigo);
                   break;
                   
           case '9': // rotina gera dados de forma autom�tica para povoar a Arvore
           
                    gera_dados(&r);
                    break;
            
            case '5':  // inicia o questionario para determinar o perfil de investidor                                               
                  
                   inicia_questionario(r,op);
                   //if( p != NULL )
                     //  printf("\n Codigo: %d", p->info.codigo);   
                   break;
				                      
           case '7':  // t�rmino do programa                                                 
                   exit( 1 ); 
                   break;                
                   
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
        system("cls");
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal

/***************************************************
 * iniciar questionario                            *
 * objetivo: rotina para buscar registro por c�digo*
 * entrada : ARVORE e cod                          *
 * sa�da   : ARVORE com mais um registro           *
 ***************************************************/ 
ARVORE* inicia_questionario( ARVORE *p, char opt)
{
   char resposta[3];
   //p = (*r);
   while(p->subd != NULL || p->sube != NULL)
   { 	
      	printf("%s\n",p->info.nome);
   		printf("Resposta: ");
   		gets(resposta); 
   		if( strcmp(resposta,"sim")==0)
   		inicia_questionario(p->subd,opt);
   	else
       	inicia_questionario( p->sube,opt); // anda com o ponteiro p para a direita, pois o c�digo procurada � maior 
   } // fim if( *p == NULL || (*p)->info.codigo == cod )
  getch();
}
  
/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * sa�da   : nodo com dados                      *
 ************************************************/
void entrada_dados( ARVORE* aux )
{ 
/*  printf( "\n\n C�digo: %d", aux->info.codigo ); */  
    aux->subd = NULL;    // n�o aponta
    aux->sube = NULL;    // n�o aponta

}

/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * sa�da   : dados em tela                       *
 *************************************************/ 
void imprime_ARVORE( ARVORE* aux ){    
     
    if( aux != NULL ){              // verifica se a raiz � diferente de vazio
        printf( "\n C�digo.....: %d", aux->info.codigo );
        printf( "\n Altura.....: %d", aux->info.altura );
        printf( "\n Fatbal.....: %s", aux->info.nome );        
		getchar();
        printf( "\n >> sube" );
        imprime_ARVORE( aux->sube ); // recursivo, segue pelo caminho da esquerda
        printf( "\n >> subd" );
        imprime_ARVORE( aux->subd ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\n �rvore vazia!");
}

/************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * sa�da   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta
}

/************************************************* 
 * insere no Fim                                 *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE                              *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/ 
void insere( ARVORE** r ){ 
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p
    int cod, achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura

    printf("\n Digite o novo c�digo: ");
    scanf("%d", &cod);
    
    p = *r;                            // posiciona ponteiro auxiliar
    achou = busca( cod, &a, &p );      // verifica se c�digo a ser inserido j� existe na �rvore
    if( !achou ){                      // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria

         if( no != NULL ){             // se conseguiu alocar mem�ria, insere
                 no->info.codigo = cod;// preenche o novo registro com o c�digo j� informado
                 entrada_dados( no );  // entrada do usu�rio
                 if( *r == NULL )      // verifica se a �rvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
    } // fim if( !achou )
    else
        printf( "\n Registro j� existe!" );
}

/************************************************ 
 * busca                                        *
 * objetivo: achar nodo                         *
 * entrada : ARVORE e c�digo a ser exclu�do     *
 * sa�da   : posicao ou NULL (n�o encontrou)    *
 ************************************************/ 
int busca( int cod, ARVORE** a, ARVORE** p ){
   int achou = FALSE;                // achou = indica se encontrou o c�digo na estrutura
   
   *a = NULL;                        // ponteiro auxiliar para o anterior
   while( ( *p != NULL ) && ( !achou ) )
           if ( (*p)->info.codigo == cod ) // veririfica se encontrou o c�digo
                achou = TRUE;        // encontrou a matricula na estrutura
           else {
                *a = *p;             // posiciona ponteiro auxiliar no anterior de p
                if( (*p)->info.codigo > cod )
                    *p = (*p)->sube; // anda com o ponteiro p para a esquerda, pois o c�digo procurada e menor
                else
                    *p = (*p)->subd; // anda com o ponteiro p para a direita, pois o c�digo procurada e maior 
           } // fim if ((*p)->info.codigo == cod)
    
   return achou; 
}

/***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por c�digo*
 * entrada : ARVORE e cod                          *
 * sa�da   : ARVORE com mais um registro           *
 ***************************************************/ 
ARVORE* busca_recursivo( ARVORE *p, int cod ){
   if( p == NULL || p->info.codigo == cod )
       return p; 
   else{
       if( p->info.codigo > cod )
            return busca_recursivo( p->sube, cod ); // anda com o ponteiro p para a esquerda, pois o c�digo procurada � menor
       else
            return busca_recursivo( p->subd, cod ); // anda com o ponteiro p para a direita, pois o c�digo procurada � maior 
   } // fim if( *p == NULL || (*p)->info.codigo == cod )
}

/************************************************
 * gera_dados                                   *
 * objetivo: rotina para ler dados dos registros*
 * entrada : lista                              *
 * sa�da   : lista atualizado com dados         *
 ***********************************************/
 
 //void SetPessoa(Pessoa *P, int idade, float peso, float altura)

void gera_dados(ARVORE **r){
		 
	int   i, x;                                 // variaveis auxiliares para percorrer o vetor
	for(i = 0 ; i < 10 ; i ++) //la�o para percorrer o vetor
	{
		for(x = 0 ; x < 10 ; x++) //la�o para popular com a quantidade X de registros
		{	
			ARVORE* a;      // ponteiro auxiliar
		    ARVORE* p;      // ponteiro auxiliar para anterior de p
		    int cod = i,achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura
			//printf("\n valor do i apos 1� laco %i",i);
			//getch();
			//Vetor de perguntas a serem respondidas pelo usuario/
			char *perguntas[] = {
		"Voc� realizou alguma aplica��o nos �ltimos 12 meses?", //cod 0
		"Pergunta02", //cod 1
		"Pergunta03", //cod 2
		"Pergunta04", //cod 3
		"Pergunta05", //cod 4
		"Pergunta06", //cod 5 //primeiro registro
		"Pergunta07", //cod 6
		"Perfil01",   //cod 7
		"Perfil02",   //cod 8
		"Perfil03"    //cod 9
		};
		  		
				 //printf("\n teste: %s",nomes[i]);
				 //getchar();
				 p = *r;
				 achou = busca( cod, &a, &p );      // verifica se c�digo a ser inserido j� existe na �rvore
				if(!achou)
				{
				     ARVORE *no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
				     
					 if(no != NULL)
					 {
				     	no->info.codigo = cod;
				     	strcpy(no->info.nome,(perguntas[i]));
				     	
				     	entrada_dados(no);  
					     if(*r == NULL)
						 {
						 		no->info.codigo = 5;
						 		strcpy(no->info.nome,(perguntas[5]));
						 		*r = no;
						 }
					 else		 	
					 		if(no->info.codigo > (*r)->info.codigo) 
					 			a->subd = no;
							else							 
					 			a->sube = no;
					}
			     	
				}
		}
	}
}
	
		
	


