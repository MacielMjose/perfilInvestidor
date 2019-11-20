/***********************************************/ 
/* Árvores Binárias                            */
/* objetivo: registro de códigos               */
/* programador: Daniela Bagatini               */
/* criado em: 08/11/2017                       */
/* data da última alteração: 06/06/2018        */
/***********************************************/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>    // setlocale
#include <ctype.h>//biblioteca p/ as funções isalpha isdigit toupper tolower

#define FALSE   0      // constante falsa
#define TRUE   !FALSE  // constante verdadeira


/***********************************************/ 
/* Definição dos Registros                     */
/***********************************************/ 
typedef struct {          // registro 
       int  codigo;       
	   int  altura;
	   int  fatbal;
	   char pergunta[]; //mudar nome dessa variável depois
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   // dados do registro
       struct arv* subd;  // ponteiro para o nodo da direita
       struct arv* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 

/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/
void    cria_ARVORE     ( ARVORE** r );  // inicializa árvore com NULL
void    imprime_ARVORE  ( ARVORE* aux ); // visualização da árvore em tela, todos os registros
ARVORE* remove_recursivo( ARVORE *p, int cod );
ARVORE* inicia_questionario( ARVORE *p); //rotina responsavel por realizar as perguntas a fim de traçar o perfil do investidor
void gera_dados(ARVORE **r); 
 
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;       // opção do menu                               
    ARVORE* r, *p; // declaração da ARVORE, variável do tipo ARVORE = ARVORE de ponteiros
    int cod, fatbal= 0, altura_esq=0, altura_dir=0;
    
    setlocale(LC_ALL, "Portuguese");
    cria_ARVORE( &r );
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Perfil de Investidor  - Menu                         " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [4] Imprime                                          " );         
		 printf( "\n [9] Gera Arvore Binária - Popular Árvore             " ); 
		 printf( "\n [5] Inicia Questionário                              " );         
		 printf( "\n [7] Para sair do programa                            " );         
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de opção do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;
           
           case '4':   // rotina imprime nodos da ARVORE
                   imprime_ARVORE( r );
                   break;                   
                   
           case '8':  // rotina recursiva que busca um registro da ARVORE                                                
                   //p= menor_valor( r );
                   if( p != NULL )
                       printf("\n Codigo: %d", p->info.codigo);
                   break;
                   
            case '9': // rotina gera dados de forma automática para povoar a Arvore
           
                    gera_dados(&r);
                    break;
            
            case '5':  // inicia o questionario para determinar o perfil de investidor                                               
                  
                   inicia_questionario(r);
                   //if( p != NULL )
                     //  printf("\n Codigo: %d", p->info.codigo);   
                   break;
				                      
           case '7':  // término do programa                                                 
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
 * objetivo: determinar caminho a seguir           *
 * entrada : ARVORE *p                             *
 * saída   : perfil de investidor                  *
 ***************************************************/ 
ARVORE* inicia_questionario( ARVORE *p)
{
   char resposta[3]; //armazena a resposta do usuario  para determinar o caminho
    	
    	do
		{
			printf("\n %s",p->info.pergunta); //inicializa o qestioranio com a pergunta raiz
	   		printf("\n Resposta: "); //pergunta ao usuário
	   		gets(resposta); //get string da resposta do usuário
	   		strupr(resposta);//string uppercase, transforma o string digitado em Uppercase
	   		printf("\n %s",resposta);//teste de tela
	   		
	   		if( strcmp(resposta,"SIM")==0) //se a string contida em resposta for igual a SIM, retorna 0
	   			inicia_questionario(p->subd);//então, eu sigo pelo caminho da direita
	   		
			if( strcmp(resposta,"NAO")==0) //se a string contida em resposta for igual a NAO, retorna 0
	   			inicia_questionario(p->sube);//então, eu sigo pelo caminho da
	   		else
	   			printf("\n Resposta inválida");
				   	   		
	   		return 0;//se o usuário digitar qualquer coisa que não seja SIM ou NÃO, o programa é e ncerrado e retorna para o menu.
		}while(p->subd == NULL && p->sube == NULL);
      	  					
  getch();
}

/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * saída   : dados em tela                       *
 *************************************************/ 
void imprime_ARVORE( ARVORE* aux ){    
     
    if( aux != NULL ){              // verifica se a raiz é diferente de vazio
        printf( "\n Código.....: %d", aux->info.codigo );
        printf( "\n Altura.....: %d", aux->info.altura );
        printf( "\n Pergunta.....: %s", aux->info.pergunta );        
		getchar();
        printf( "\n >> sube" );
        imprime_ARVORE( aux->sube ); // recursivo, segue pelo caminho da esquerda
        printf( "\n >> subd" );
        imprime_ARVORE( aux->subd ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\n Árvore vazia!");
}

/************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * saída   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta
}

/************************************************
 * gera_dados                                   *
 * objetivo: rotina para ler dados dos registros*
 * entrada : lista                              *
 * saída   : lista atualizado com dados         *
 ***********************************************/
 
 //void SetPessoa(Pessoa *P, int idade, float peso, float altura)

void gera_dados(ARVORE **r)
{
	
		char *perguntas[] = {
		"Você realizou alguma aplicação nos últimos 12 meses?",
		"Faria investimentos para longo prazo, sem poder resgatar o seu dinheiro nos próximos 5 anos ?",
		"sss" ,
		"Investiria seu dinheiro para recuperar o mesmo no mesmo dia ou semana, independente de resultados positivos ou negativos ?.",
		"Você sabe a diferença entre LCI, LCA Ações e Debêntures ? ",
		"Conservador",
		"Pergunta07", 
		"Perfil01",   
		"Perfil02",   
		"Perfil03",   
		"Você sabe a diferença entre LCI, LCA Ações e Debêntures ? ", 
		"Perfil05",   
		"Perfil06",   
		"Perfil07",  
		"Perfil08",   
		"Perfil09"   
		"Pergunta07", 
		"Perfil01",   
		"Perfil02",   
		"Perfil03",   
		"Você sabe a diferença entre LCI, LCA Ações e Debêntures ? ", 
		"Perfil05",   
		"Perfil06",   
		"Perfil07",   
		"Perfil08",   
		"Perfil09",   
		"Perfil09",  
		"Perfil09", 
		"Perfil09",
		"Perfil09",
		"Perfil09"   
		};
		
		int vetPosicoes[] = {
		 41,    
		 20,    
		 11,    
		 8,      
		 6,     
		 9,      
		 17,    
		 15,    
		 19,    
		 30,    
		 28,    
		 26,    
		 29,    
		 35,    
		 32,    
		 36,    
		 65,    
		 48,   
		 46,	
		 45,
		 47,	
		 50,	
		 49,	
		 52,	
		 91,	
		 72,	
		 70,	
		 76,	
		 99,	
		 98,	
		 100	
		};	  
	
	int   i; //variavel auxiliar, apenas para dar indice aos vetores e percorrer o laço FOR
	
	for(i = 0 ; i < 32 ; i ++) //laço para percorrer o vetor
	{
					ARVORE *no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória
				     
					 if(no != NULL)
					 {
				     	no->info.codigo = vetPosicoes[i]; //no info codigo recebe o valor contido na posição i do vetor
				     	strcpy(no->info.pergunta,perguntas[i]);//copia o valor da string2 para a variavel 1
				     	
					     if(*r == NULL) //verifica se a raiz é null, popular o primeiro registro
					     {		
						 		*r = no; //raiz recebe a informação contida em no
						 }		    		
						else { 				//caso a raiz não esteja vazia, verificar onde o registro deverá ser inserido
								ARVORE* atual = *r;      // ponteiro auxiliar
			    				ARVORE* anterior = NULL;     // ponteiro auxiliar para anterior de atual	
							while(atual != NULL) //se o atual for diferente de NULL
							{
								anterior = atual; //o anterior recebe o endereço do atual
									if(no->info.codigo > atual->info.codigo) //se o codigo que quero inserir é maior que o atual
										atual = atual->subd; //então deverá ser inserido à direita
									else
										atual = atual->sube; //do contrário, deverá ser inserido na subarvore a esquerda
							}if(no->info.codigo > anterior->info.codigo) //se o codigo que quero inserir é maior que o anterior
								anterior->subd = no; //insere na subarvore direita
							else
								anterior->sube = no; //insere na subarvore esquerda
						}
		                     
				     }//fim do IF no != NULL
			} //fim do laço de repetição
} // fim da função principal


