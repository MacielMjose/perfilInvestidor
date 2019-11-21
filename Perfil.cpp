/***************************************************************************************/ 
/* �rvores Bin�rias                                                                    */
/* objetivo: registro de c�digos                                                       */
/* programador: Jos� Maciel, Gabriel Brittes, Nicolas Lima, Luciano Rocha              */
/* criado em: 21/11/2019                                                               */
/* data da �ltima altera��o: 21/11/2019                                                */
/***************************************************************************************/ 

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
	   char nome[1000]; //mudar nome dessa vari�vel depois
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
int inicia_questionario( ARVORE *p); //rotina responsavel por realizar as perguntas a fim de tra�ar o perfil do investidor
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
		 printf( "\n [5] Inicia Question�rio                              " );         
		 printf( "\n [7] Para sair do programa                            " );         
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
int inicia_questionario( ARVORE *p)
{
   char resposta[3]; //armazena a resposta do usuario  para determinar o caminho
    	
			printf("\n %s",p->info.nome); //inicializa o qestioranio com a pergunta raiz
	   		printf("\n Resposta: "); //pergunta ao usu�rio
	   		gets(resposta); //get string da resposta do usu�rio
	   		strupr(resposta);//string uppercase, transforma o string digitado em Uppercase
	   		//printf("\n %s",resposta);//teste de tela
	   		
	   		if( strcmp(resposta,"SIM")==0) //se a string contida em resposta for igual a SIM, retorna 0
	   			inicia_questionario(p->subd);//ent�o, eu sigo pelo caminho da direita
	   		
			if( strcmp(resposta,"NAO")==0) //se a string contida em resposta for igual a NAO, retorna 0
	   			inicia_questionario(p->sube);//ent�o, eu sigo pelo caminho da esquerda
				   	   		
	   		return 0;//se o usu�rio digitar qualquer coisa que n�o seja SIM ou N�O, o programa � e ncerrado e retorna para o menu.

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
        printf( "\n Pergunta...: %s", aux->info.nome );        
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
		"Voc� realizou alguma aplica��o nos �ltimos 12 meses?", //pos 1 - cod 41
		"Faria investimentos para longo prazo, sem poder resgatar o seu dinheiro nos pr�ximos 5 anos ?", //pos 2 - cod 20
		"Prioriza seguran�a para que n�o perca dinheiro ? ", //pos 3 - cod 65
		"Investiria seu dinheiro para recuperar o mesmo no mesmo dia ou semana, independente de resultados positivos ou negativos ?",//pos 4 - cod 11
		"Investiria mais de 1000 reais por m�s sem liquidez di�ria/mensal ? ", //pos 5 - cod 30
		"Supondo o caso de que voc� investisse 1000 em 1 m�s. Voc� teria grandes problemas se investisse e perdesse os 1000 reais ? ", // pos 6 - cod 48
		"Investiria mais de 1000 reais mensalmente caso tenha renda para isso?", //pos 7 - cod 91 
		"Voc� sabe a diferen�a entre LCI, LCA A��es e Deb�ntures ? ", //pos8 - cod8
		"Ao Montar sua carteira de investimentos voc� procuraria um especialista para lhe auxiliar ? ", //pos9 - cod17
		"Ja investiu em a��es ?", //pos10-28 
		"Considerando seus investimentos de 1000 do m�s passado,voc� se depara com uma queda, resgata o seu dinheiro?",//pos11 - cod35
		"Em rela��o ao seu planejamento financeiro, voc� se considera organizado ?",//pos12 - cod46
		"Se a perda de uma quantia em dinheiro te traria problemas, certamente necessita mais conhecimento, quando falamos em investimento, voc� acha os assuntos abordados interessantes? ", //pos13 -cod 50
		"E ao comprar produtos de investimento voc� considera uma tarefa f�cil para conseguir realiza-l� sozinho ?", //pos 14  - cod  72
		"Voc� gostaria de investir estes 1000 reais ou mais por m�s, para criar um patrim�nio a longo prazo ?", //pos 15  - cod  99
		"O seu perfil �: Conservador, voc� anseia em ganhar dinheiro, desejando fazer o seu dinheiro trabalhar para voc�, mas n�o gosta de correr riscos, deixar o dinheiro na poupan�a n�o � investimento, logo recomendamos investimentos em renda fixa: Tesouro Selic, Tesouro Direto, LCI, LCA, CDB.",// //pos 16  - cod 6
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//pos17  - cod  9
		"Seu perfil �: Agressivo, N�o tem medo de se arriscar, necessita de conhecimento sobre economia e outras �reas que afetam a economia,para saber no que esta se metendo, podendo ganhar dinheiro diariamente e ao longo prazo, logo recomendamos os seguintes investimentos: Fundos Multimercados, Fundos Imobili�rios. a��es, Fracionadas ou por lote.", //pos18 - cod 15
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//
		"O seu perfil �: Conservador, voc� anseia em ganhar dinheiro, desejando fazer o seu dinheiro trabalhar para voc�, mas n�o gosta de correr riscos, deixar o dinheiro na poupan�a n�o � investimento, logo recomendamos investimentos em renda fixa: Tesouro Selic, Tesouro Direto, LCI, LCA, CDB.", //pos20 - cod 26
		"Seu perfil �: Agressivo, N�o tem medo de se arriscar, necessita de conhecimento sobre economia e outras �reas que afetam a economia,para saber no que esta se metendo, podendo ganhar dinheiro diariamente e ao longo prazo, logo recomendamos os seguintes investimentos: Fundos Multimercados, Fundos Imobili�rios. a��es, Fracionadas ou por lote.", //pos 21 - cod 29
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//pos17  - cod  9,
		"O seu perfil �: Conservador, voc� anseia em ganhar dinheiro, desejando fazer o seu dinheiro trabalhar para voc�, mas n�o gosta de correr riscos, deixar o dinheiro na poupan�a n�o � investimento, logo recomendamos investimentos em renda fixa: Tesouro Selic, Tesouro Direto, LCI, LCA, CDB.", //pos 23 - cod 36
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//pos24  - cod  45
		"Seu perfil �: Agressivo, N�o tem medo de se arriscar, necessita de conhecimento sobre economia e outras �reas que afetam a economia,para saber no que esta se metendo, podendo ganhar dinheiro diariamente e ao longo prazo, logo recomendamos os seguintes investimentos: Fundos Multimercados, Fundos Imobili�rios. a��es, Fracionadas ou por lote.", //pos 25 - cod 47
		"O seu perfil �: Conservador, voc� anseia em ganhar dinheiro, desejando fazer o seu dinheiro trabalhar para voc�, mas n�o gosta de correr riscos, deixar o dinheiro na poupan�a n�o � investimento, logo recomendamos investimentos em renda fixa: Tesouro Selic, Tesouro Direto, LCI, LCA, CDB.", //pos26 - cod 49
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//pos17  - cod  9
		"O seu perfil �: Conservador, voc� anseia em ganhar dinheiro, desejando fazer o seu dinheiro trabalhar para voc�, mas n�o gosta de correr riscos, deixar o dinheiro na poupan�a n�o � investimento, logo recomendamos investimentos em renda fixa: Tesouro Selic, Tesouro Direto, LCI, LCA, CDB.", //pos 27 - cod 52
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas.",//pos29  - cod  76
		"Seu perfil �: Agressivo, N�o tem medo de se arriscar, necessita de conhecimento sobre economia e outras �reas que afetam a economia,para saber no que esta se metendo, podendo ganhar dinheiro diariamente e ao longo prazo, logo recomendamos os seguintes investimentos: Fundos Multimercados, Fundos Imobili�rios. a��es, Fracionadas ou por lote.", //pos 30 - cod 98
		"Ningu�m quer correr o risco de perder dinheiro n�o � verdade? mas, como diz o ditado, 'quem n�o arrisca, n�o petisca', este ditado se encaixa muito bem ao seu perfil, Moderado, que tem d�vidas se deve se arriscar ou n�o, logo recomendamos: Fundos de a��es, fundos imobili�rio, fundos multimercado e at� mesmo algumas a��es fracionadas." //pos31  - cod 100
		
		};
		
		int vetPosicoes[]= {41,20,65,11,30,48,91,8,17,28,35,46,50,72,99,6,9,15,19,26,29,32,36,45,47,49,52,70,76,98,100};
		int   i;                                // variaveis auxiliares para percorrer o vetor
for(i = 0 ; i < 32 ; i ++) //la�o para percorrer o vetor
{

				ARVORE *no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
			     
				 if(no != NULL) //validar se conseguiu alocar memoria
				 {
			     	no->info.codigo = vetPosicoes[i]; //no info codigo recebe o valor contido na posi��o i do vetor
			     	strcpy(no->info.nome,perguntas[i]);//copia o valor da string2 para a variavel 1
			     	no->sube= NULL;  //inicializar as subarvores sube
			     	no->subd= NULL;  //inicializar as subarvores subde
			     	
				     if(*r == NULL) //verifica se a raiz � null, popular o primeiro registro
				     {		
					 		*r = no; //raiz recebe a informa��o contida em no
					 }		    		
					else { 				//caso a raiz n�o esteja vazia, verificar onde o registro dever� ser inserido
							ARVORE* atual = *r;          // ponteiro auxiliar
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
		}
		
	}


