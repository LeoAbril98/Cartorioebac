#include <stdio.h> // bliblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro(){ // Função responsavel por cadastrar os usuários no sistema
	
	char arquivo[40]; //Definindo variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu o registro de nomes!\n\n");
	printf("Digite o CPF a ser cadastrado:  "); // Coletando informação do usuário
	scanf("%s",cpf); // refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,", Nome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
		
	file = fopen(arquivo, "a"); 
	fprintf(file, ", Sobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
		
	system("pause");
}

int consulta(){
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	printf("Você escolheu consultar os nomes!\n\n");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	while(fgets(conteudo, 200, file) != NULL){
		
		printf ("\n Essas são as informações do usuário: CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
    fclose(file);
	system("pause");
}

int deletar(){
	
	char cpf[40]; // declaração de variavel
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);  // Deletar o ususario
	
	FILE *file;   
	file = fopen(cpf,"r");
	
	if (file == NULL){
		printf("O usuário não se encontra no sistema!.\n");
	    system("pause");

	}

}

int main(){
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;){ // Inicio do laço de repetição
			
		system("cls");
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n");//Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os  nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: ");//Fim do menu
	
	    scanf("%d", &opcao);//Armazenando a escolha do usuário
	
    	system("cls");
    	
    	switch(opcao){
    		case 1:
    	    registro(); //chamada de funções
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
			    
		    default:
		    printf("Essa opção não esta disponivel!\n");
	    	system("pause");
	    	break;
		}

    } //Fim do laço de repetição

}
	
