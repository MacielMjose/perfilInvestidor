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
void    imprime_ARVORE  ( ARVORE* aux ); // visualiza��o da �rvore em tela, todos os registros
void    insere          ( ARVORE** r );  // inclui um novo registro na �rvore, sempre na folha
void    insere_recursivo( ARVORE** r, int cod ); // inclui um novo registro na �rvore
ARVORE* busca_recursivo ( ARVORE *p, int cod ); 
int     busca           ( int matricula, ARVORE** a, ARVORE** p ); // procura na �rvore um c�digo
ARVORE* remove_recursivo( ARVORE *p, int cod );
void    calcula_altura  ( ARVORE **r );
int     altura_arvore   ( ARVORE *p );     // informa a altura da �rvore
void verifica_balanceamento( ARVORE **r ); // verifica balanceamento da �rvore
void rotacao_direita ( ARVORE **p );
void rotacao_esquerda( ARVORE **p );
ARVORE* inicia_questionario( ARVORE *p); //rotina responsavel por realizar as perguntas a fim de tra�ar o perfil do investidor
void gera_dados(ARVORE **r); 

      
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
                  
                   inicia_questionario(r);
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
ARVORE* inicia_questionario( ARVORE *p)
{
   char resposta[3];
   //p = (*r);
    	
      	printf("\n %s",p->info.nome);
   		printf("\n Resposta: ");
   		gets(resposta); 
   		
   		if( strcmp(resposta,"sim")==0)
   			inicia_questionario(p->subd);
   		
		if( strcmp(resposta,"nao")==0)
   			if(p->sube == NULL)
   			{
				printf("\n nao foi possivel tra�ar seu perfil");
				
			}
			else
			{
				inicia_questionario( p->sube); // anda com o ponteiro p para a direita, pois o c�digo procurada � maior 
			}

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
        printf( "\n Pergunta.....: %s", aux->info.nome );        
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
	
		char *perguntas[] = {
		"Voc� realizou alguma aplica��o nos �ltimos 12 meses?", //cod 0
		"Fez investimentos nos ultimos 12 meses ?", //cod 1
		"Prioriza seguran�a para que n�o perca dinheiro ? ", //cod 2
		"Investiria mais de 1000 reais mensalmente caso tenha renda para isso? sem liquidez.", //cod 3
		"Conservador", //cod 4
		"Pergunta06", //cod 5 //primeiro registro
		"Pergunta07", //cod 6
		"Perfil01",   //cod 7
		"Perfil02",   //cod 8
		"Perfil03",   //cod 9
		"Perfil04",   //cod 10
		"Perfil05",   //cod 11
		"Perfil06",   //cod 12
		"Perfil07",   //cod 13
		"Perfil08",   //cod 14
		"Perfil09"   //cod 15
		};	
		
		int vetPosicoes[] = {
		 41,   //cod 0
		 20,   //cod 1 //primeiro registro: Fez investimentos nos ultimos 12 meses ?
		 29,   //cod 2 //Prioriza seguran�a para que n�o perca dinheiro ? 
		 28,   //cod 3 //Investiria mais de 1000 reais mensalmente caso tenha renda para isso? sem liquidez.
		 32,   //cod 4
		 11,   //cod 5 //
		 12,   //cod 6
		 10,   //cod 7
		 65,   //cod 8
		 50,   //cod 9
		 51,   //cod 10
		 49,   //cod 11
		 91,   //cod 12
		 72,   //cod 13
		 99,   //cod 14
		 100  //cod 15
		};	  
	int   i, x;                                 // variaveis auxiliares para percorrer o vetor
for(i = 0 ; i < 16 ; i ++) //la�o para percorrer o vetor
{

	    int cod = i,achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estruturas
		//p = *r;
				ARVORE *no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
			     
				 if(no != NULL)
				 {
			     	no->info.codigo = vetPosicoes[i]; //no info codigo recebe o valor contido na posi��o i do vetor
			     	strcpy(no->info.nome,perguntas[i]);//copia o valor da string2 para a variavel 1
			     	
				     if(*r == NULL) //verifica se a raiz � null, popular o primeiro registro
				     {		
					 		*r = no; //raiz recebe a informa��o contida em no
					 }		    		
					else { 				//caso a raiz n�o esteja vazia, verificar onde o registro dever� ser inserido
							ARVORE* atual = *r;      // ponteiro auxiliar
		    				ARVORE* anterior = NULL;     // ponteiro auxiliar para anterior de atual	
						while(atual != NULL) //se o atual for diferente de NULL
						{
							anterior = atual; //o anterior recebe o endere�o do atual
								if(no->info.codigo > atual->info.codigo) //se o codigo que quero inserir � maior que o atual
									atual = atual->subd; //ent�o dever� ser inserido � direita
								else
									atual = atual->sube; //do contr�rio, dever� ser inserido na subarvore a esquerda
						}if(no->info.codigo > anterior->info.codigo) //se o codigo que quero inserir � maior que o anterior
							anterior->subd = no; //insere na subarvore direita
						else
							anterior->sube = no; //insere na subarvore esquerda
					}
	                     
			     }
		}//verifica_balanceamento(r); //fun��o colocada para auxiliar no balanceamento
	}

	
/****************************************************
 * verifica_balanceamento                           *
 * objetivo: rotina para calcular o balancemaneto   *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE balanceada                      *
 ****************************************************/ 
void verifica_balanceamento( ARVORE **r ){
	ARVORE *aux= *r;                                // cria ponteiro auxiliar para percorrer a �rvore
    printf("\n chama");
    if( aux != NULL ){                              // verifica se ponteiro � diferente de NULL
		if( aux->info.fatbal >= 2 && ( aux->subd->info.fatbal != 2 && aux->subd->info.fatbal != -2 ) ){ // verifica fator de balanceamento no n� pai e filho, se n� pai for maior do que 1, a rota��o ser� � esquerda 
	        if( aux->subd->info.fatbal < 0 ){       // se sinal do fatbal do n� filho for negativo, realiza rota��o dupla				
	            rotacao_direita( &aux->subd );	    // rota��o esquerda - dupla
		        rotacao_esquerda( &aux );
			}else                                   // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
    			rotacao_esquerda( &aux );
	    }else
            if( aux->info.fatbal <= -2 && ( aux->sube->info.fatbal != 2 && aux->sube->info.fatbal != -2 ) ){ // verifica fator de balanceamento no n� pai e filho, se n� pai for menor do que 1, a rota��o ser� � direita
		        if( aux->sube->info.fatbal > 0 ){   // se sinal do fatbal do n� filho for positvo, realiza rota��o dupla  
		            rotacao_esquerda( &aux->sube ); // rota��o direita - dupla	  
			        rotacao_direita( &aux );
				}else 
	    			rotacao_direita( &aux );        // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
			}else{
					verifica_balanceamento( &aux->sube ); // continua verificando balanceamento � esquerda
					verifica_balanceamento( &aux->subd ); // continua verificando balanceamento � direita 	
			}
		calcula_altura( &aux );	                    // atualiza a altura dos n�s da �rvore ap�s rota��o
   }
   *r= aux;                                         // atualiza a raiz ap�s rota��o
}

/****************************************************
 * rotacao_direita                                  *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_direita( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso at� NULL
	 	  aux= (*p)->sube;                        // aponta � esquerda
		  (*p)->sube= aux->subd;                  // n� filho � direita  
		  aux->subd= *p;                          // raiz passa a ser n� filho
		  *p= aux;                                // aux passa ser a nova raiz
     }
}


/****************************************************
 * rotacao_esquerda                                 *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/ 
void rotacao_esquerda( ARVORE **p ){
	 ARVORE *aux;
	 if( *p != NULL ){                            // percurso at� NULL
	 	  aux= (*p)->subd;                        // ponteiro auxiliar � posicionado no n� filho da direita
		  (*p)->subd= aux->sube;                  // ajusta apontamento, ponteiro direito pai aponta para ponteiro esquerdo do filho
		  aux->sube= *p;                          // ponteiro � esquerda no filho aponta para n� pai
		  *p= aux;                                // reposiciona p
     }
}


/****************************************************
 * calcula_altura                                   *
 * objetivo: rotina para calcular a altura da �rvore*
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE com campo altura atualizado     *
 ****************************************************/ 
void calcula_altura( ARVORE **r ){
	ARVORE *aux= *r;                            // ponteiro auxiliar para percorrer a �rvore
    
    if( aux != NULL ){                          // verifica se a raiz � diferente de NULL
        aux->info.altura= altura_arvore( aux ); // verifica a altura do n�
        aux->info.fatbal= ( altura_arvore( aux->subd ) + 1 ) - ( altura_arvore( aux->sube ) + 1 ); // calcula fator de balanceamento (fatbal) do n�
        //printf("\n Cod:%i  A:%i  Fatbal:%i  \n", aux->info.codigo, aux->info.altura, fatbal);
   	    calcula_altura( &aux->subd );          // recursivo, segue pelo caminho da direita do n�
        calcula_altura( &aux->sube );          // recursivo, segue pelo caminho da esquerda do n�
    }
}


/****************************************************
 * altura_arvore                                    *
 * objetivo: rotina para calcular a altura da �rvore*
 * entrada : ARVORE                                 *
 * sa�da   : altura                                 *
 ****************************************************/ 
int altura_arvore( ARVORE *p ){
	 int altura_esq, altura_dir;
	 if( p == NULL  )                           // finaliza o percurso
	     return -1;
     else{
          altura_dir= altura_arvore( p->subd ); // percorre � direita
	 	  altura_esq= altura_arvore( p->sube ); // percorre � esquerda
          if( altura_dir > altura_esq )         // se altura da direita maior, soma mais um n�vel � direita
              return altura_dir + 1;
          else                                  // se altura da esquerda maior, soma mais um n�vel � esquerda
              return altura_esq + 1;		      
     }
}
