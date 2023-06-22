#include <stdio.h> // bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro(){ // Fun��o responsavel por cadastrar os usu�rios no sistema
	
	char arquivo[40]; //Definindo vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� escolheu o registro de nomes!\n\n");
	printf("Digite o CPF a ser cadastrado:  "); // Coletando informa��o do usu�rio
	scanf("%s",cpf); // refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
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
	printf("Voc� escolheu consultar os nomes!\n\n");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	while(fgets(conteudo, 200, file) != NULL){
		
		printf ("\n Essas s�o as informa��es do usu�rio: CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
    fclose(file);
	system("pause");
}

int deletar(){
	
	char cpf[40]; // declara��o de variavel
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);  // Deletar o ususario
	
	FILE *file;   
	file = fopen(cpf,"r");
	
	if (file == NULL){
		printf("O usu�rio n�o se encontra no sistema!.\n");
	    system("pause");

	}

}

int main(){
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;){ // Inicio do la�o de repeti��o
			
		system("cls");
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");//Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os  nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: ");//Fim do menu
	
	    scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	switch(opcao){
    		case 1:
    	    registro(); //chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
			    
		    default:
		    printf("Essa op��o n�o esta disponivel!\n");
	    	system("pause");
	    	break;
		}

    } //Fim do la�o de repeti��o

}
	
