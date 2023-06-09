#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define MAX_USUARIOS 50

typedef struct {
	
	char nome[50];
	char cpf[15];
    char vacina[50];
    char data[30];
    int lote;
	int cadastrado;	
	
}usuario;

usuario usuarios[MAX_USUARIOS];

void menu();
void cadastrar();
void listar();
void consultar();

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	menu();	
}

void menu(){
	
	int teclamenu;
	
		do{
	
			system("CLS");
	
				printf("1-Cadastrar Vacina\n");
				printf("2-Listar Aplicações\n");
				printf("3-Consultar Por CPF\n");
				printf("4-Sair\n");
	
				scanf("%d", &teclamenu);
				fflush(stdin);
		
					switch(teclamenu){
						case 1:
							cadastrar();
						break;
		
						case 2:
							listar();
						break;
			
						case 3:
							consultar();
						break;
					}
		}while(teclamenu!=4);
}

void cadastrar(){
	
	char nome[50];
	char cpf[15];
    char vacina[50];
    char data[30];
    int lote;
    int cadastrado;
    int op;
    int i;
    
    	system("CLS");
    
    		do{
    			printf("Nome:");
    			fgets(nome,sizeof(nome),stdin);
    	
    			printf("Cpf:");
    			fgets(cpf,sizeof(cpf),stdin);
    	
    			printf("Vacina:");
    			fgets(vacina,sizeof(vacina),stdin);
    	
    			printf("Data:");
    			fgets(data,sizeof(data),stdin);
    	
    			printf("Lote:");
   			 	scanf("%d", &lote);
    			fflush(stdin);
    	
    	
    				for(i=0; i<MAX_USUARIOS; i++){
    		
						if(usuarios[i].cadastrado==0){
			
							strcpy(usuarios[i].nome,nome);
    						strcpy(usuarios[i].cpf,cpf);
    						strcpy(usuarios[i].vacina,vacina);
    						strcpy(usuarios[i].data,data);
    						usuarios[i].lote = lote;
    						usuarios[i].cadastrado = 1;
			
							break;
    					}	
    				}
    	
    			printf("\n1- Continuar\n0- Sair\n");
    			scanf("%d",&op);
			}while(op!=0);
}

void listar(){

	int i=0;
	
		system("CLS");
	
			printf("Lista de Usuários\n");

				for(i=0;i<MAX_USUARIOS;i++){
					if(usuarios[i].cadastrado == 1){
			
						printf("Código: %d\n", i);
						printf("Nome: %s", usuarios[i].nome);
						printf("Cpf: %s", usuarios[i].cpf);
						printf("Vacina: %s", usuarios[i].vacina);
						printf("Data: %s", usuarios[i].data);
						printf("Lote: %d", usuarios[i].lote);
						printf("\n======================\n");
						
						i++;
					}
				}
	
	system("pause");
}

void consultar(){

	int i, op;
	char cpf[15];
	
		do{
			system("CLS");
		
				printf("Digite o Cpf a ser buscado:\n");
				fgets(cpf,sizeof(cpf),stdin);
		
					for(i=0;i<MAX_USUARIOS;i++){
						if(strstr(usuarios[i].cpf,cpf)!= NULL){
							printf("Código: %d\n", i);
							printf("Nome: %s", usuarios[i].nome);
							printf("Cpf: %s", usuarios[i].cpf);
							printf("Vacina: %s", usuarios[i].vacina);
							printf("Data: %s", usuarios[i].data);
							printf("Lote: %d", usuarios[i].lote);
							printf("\n======================\n");
							break;
						}
							if(strstr(usuarios[i].cpf,cpf)== NULL){
								printf("Cpf não encontrado, realize uma nova pesquisa!\n");
								break;
							}	
					}
	
				printf("\n1- Fazer nova pesquisa?\n0- Sair\n");
    			scanf("%d",&op);
    			fflush(stdin);
		}while(op!=0);
			
	system("pause");
}
