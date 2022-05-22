//
//

//incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Constante que define os tamanhos (estrutura de dados, processo e PID)
#define TAMANHO_PILHA 5
#define TAMANHO_TEXTO 20
#define PID_MAXSIZE 5

//Declara��o do tipo_pilha: estrutura de dados

struct tipo_pilha {
	
	char pilhaa[TAMANHO_PILHA][TAMANHO_TEXTO];
    int pid[TAMANHO_PILHA];
    int top;
};

//Criando uma vari�vel tipo_pilha
typedef struct tipo_pilha PILHA;
PILHA p;

//Chamando as fun��es
void push();//Empilha
void pop();//Desempilha
void display();//mostra o status da pilha




//Fun��o principal
int main ()
{
	setlocale(LC_ALL,"PORTUGUESE");	 
	p.top = -1;    
	menu();
	return 0;
}

//Fun��o que empilha um novo elemento no topo
void push(){
	
	char value[TAMANHO_TEXTO];
	int i;
	int vpid[PID_MAXSIZE];
	
	//Verificando se existe alguma posi��o dispon�vel para uma inser��o
    if (p.top == (TAMANHO_PILHA - 1))
    {
        printf ("\nA Pilha est� cheia! � imposs�vel empilhar mais elementos.\n");
        system("PAUSE");
        return;
    }
    else
    {
        //Se a pilha n�o estiver cheia:
		//	Adicione o novo elemento no topo
		//	Incremente o topo
		printf ("\nEntre com o nome do processo: ");
        scanf ("%s", value);		
        p.top = p.top + 1;        
        for (i=0; i < TAMANHO_TEXTO; i++) {         
          p.pilhaa[p.top][i] = value[i]; 
		  p.pid[p.top] = p.top + 1000;        
          if(value[i] == '\0') break;          
        }       
    }
}

//Fun��o que desempilha e retorna o elemento do topo

void pop() {
	
	char num[TAMANHO_TEXTO];
		
	//Verificando se existe algum elemento dispon�vel para uma remo��o
	if (p.top == - 1)
    {
        printf ("\nPilha vazia, imposs�vel desempilhar elementos.\n");
        system("PAUSE");
    }
    else
    
	//Se a pilha n�o estiver vazia
	//Decremente o topo
	{
        printf ("\n O PID: %d - NOME: %s foi removido.\n",p.pid[p.top], p.pilhaa[p.top]);
        system("PAUSE");
        p.top = p.top - 1;
    }
}

//Fun��o que limpa a pilha
void esvazia() {
	
	char num[TAMANHO_TEXTO];
	
	//Verificando se existem elementos para remo��o
	if (p.top == - 1)
    {
        printf ("\nPilha vazia, imposs�vel desempilhar elementos.\n");
        system("PAUSE");
    }
    else
    {       
	//Se a pilha n�o estiver vazia
	while(p.top != - 1)
		{  
        p.top = p.top - 1;
     	}	 
        printf ("\nPilha esvaziada com sucesso!.\n\n");
        system("PAUSE");
    }
}

//Fun��o para mostrar o conte�do da Pilha
void display(){

	int i;
    if (p.top == -1)
    {
    	return;
    }
    else
    {
    	printf ("--------------------------------\n");
        printf ("    PID    :      Nome\n");
        printf ("--------------------------------\n");
        for (i = p.top; i >= 0; i--)
        {
        	
         printf ("    %d   :     %s\n",p.pid[i],p.pilhaa[i]);          
        }       
    }
    printf ("\n");
}

//Mostrar o menu de op��es
void menu(){
	char op;
	 do{
       
       	system("cls");
    	display();
       	printf ("\n");
       	printf ("-------------------------------------------\n");
    	printf ("-------------------------------------------\n");
		printf("\nEscolha uma op��o:\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Limpar pilha\n");
		printf("0 - Sair\n\n");
		op=toupper(getche());
       
		switch(op){
                case'1':
				  	push();				  				
                	break;
                case'2':  
					pop();				  
                  	break;
                case'3':
					esvazia();
                  	break;
                case'0': 
					exit(0);
                  	default: printf ("\n\nOpcao invalida, digite novamente.\n\n");
                system("PAUSE");
                }  
   }while (op!='S');	
}


