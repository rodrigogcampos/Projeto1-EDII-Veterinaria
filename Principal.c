#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct key1{
	int cod;
	int position;
}ind1;

struct key2{
	char vacine[15];
	int position;
}ind2;

struct animal{
    int cod;
    char raca[15];
    char name[15];
}dog;

struct veterinaria{
    int codcontrol;
    int coddog;
    char name[15];
    char date[5];
    char person[15];
}vacina;
char opcao;

FILE *AP2, *AP1;

int menu(){
    printf("Escolha uma opcao:\n\n");
    printf("1 - Cadastro de cachorros\n");
    printf("2 - Remoção de cachorros\n");
    printf("3 - Cadastro de novas vacinacoes\n");
    printf("4 - Alteracao dos dados de uma vacinacao\n");
    printf("5 - Remocao de uma vacinacao\n");
    printf("6 - Compactacao do arquivo\n");
    printf("7 - Pesquisa por chave primária\n");
    printf("8 - Pesquisa por chave secundaria\n");
    printf("0 - Sair\n\n");

    do {
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opcao);
    switch(opcao){
        case 1:
            system("cls");
            opcao1();
        break;
        case 2:
            system("cls");
            opcao2();
        break;
        case 3:
            system("cls");
            opcao3();
        break;
        case 4:
            system("cls");
            opcao4();
        break;
        case 5:
            system("cls");
            opcao5();
        break;
        case 6:
            system("cls");
            opcao6();
        break;
        case 7:
            system("cls");
            opcao7();
        break;
        case 8:
            system("cls");
            opcao8();
        break;
        case 0:
            system("exit");
        break;
        default:
            printf("Erro! Insira uma opcao valida!\n");
    }
    } while(opcao < 0 || opcao > 8 );
}

void sair(){
    printf("\npressione uma tecla para sair...");
    getch();
    system("cls");
    menu();
}

int opcao1(){

    int cod;
    char name[15];
    char raca[15];
    
    char confirm[] = "S";
    

    while (strcmp ((strupr(confirm)), "S") == 0)
    {
        AP2 = fopen("AP2.bin", "ab");

        printf("\ncodigo: ");
        fflush(stdin);
        scanf("%d",&dog.cod);
       
        printf("nome: ");
       	fflush(stdin);
        scanf("%s",dog.name);

        printf("raca: ");
        fflush(stdin);
        scanf("%s",dog.raca);
        
        fwrite(&dog.cod,sizeof(dog.cod),1,AP2);
        fwrite(dog.name,sizeof(dog.name),1,AP2);
        fwrite(dog.raca,sizeof(dog.raca),1,AP2);
        
        fclose(AP2);
        
        printf("Deseja cadastrar outro cachorro?[S/N]");
        scanf("%s",confirm);
    }
    sair();
}
int opcao2(){ 
   
}

void inivec(FILE *AP1){
	
	AP1 = fopen("AP1.bin","rb");
	
	//char (*vetor[2])[20];
	char c[1];
	int i;
	
//	while(!feof){
		fread(c,sizeof(c),1,AP1);
		//c = getc(AP1);
		//i++;
		printf("%x",c);
	//}
//	i = 0;
//	while(!feof){
		//printf("%s", vetor[i]);
		//i++;
	//}
	
}

int opcao3(){
        AP1 = fopen("AP1.bin", "ab");
        char buffer[100];
        char aux[100];
        int size;
        
        strcat(buffer,"!");
        
		printf("Codigo de controle: ");
        fflush(stdin);
        scanf("%d",&vacina.codcontrol);
        itoa(vacina.codcontrol,aux,10);
        strcat(buffer,aux);
        strcat(buffer,"|");
        
        printf("Codigo do cachorro: ");
        fflush(stdin);
        scanf("%d",&vacina.coddog);
        itoa(vacina.coddog,aux,10);
        strcat(buffer,aux);
        strcat(buffer,"|");
        		
		printf("Nome da vacina: ");
        fflush(stdin);
        scanf("%s",vacina.name);
        strcat(buffer,vacina.name);
        strcat(buffer,"|");

        printf("Data da vacina: ");
        scanf("%s",vacina.date);
        strcat(buffer,vacina.date);
        strcat(buffer,"|");

        printf("Responsavel pela vacina: ");
        scanf("%s",vacina.person);
        strcat(buffer,vacina.person);
        strcat(buffer,"|");
        
        printf("%s", buffer);
        
        size = strlen(buffer);
    	
		fprintf(AP1,"%d",size);
        fprintf(AP1,"%s",buffer);
       
        fclose(AP1);
        
        printf("\n*********************************\n");
        inivec(AP1);
        printf("\n*********************************\n");

    sair();
}


int opcao4(){
    printf("4444444444444444444444444444444\n");
    sair();
}
int opcao5(){
    printf("5555555555555555555555555555555\n");
    sair();
}
int opcao6(){
    printf("6666666666666666666666666666666\n");
    sair();
}
int opcao7(){
   	
    sair();
}
int opcao8(){
    printf("6666666666666666666666666666666\n");
    sair();
}

int main() {

    AP1 = fopen("AP1.bin", "a");
    if (AP2 == NULL){
        fopen("AP1.bin", "w");
    }
	fclose(AP1);

   	AP2 = fopen("AP2.bin", "a");
    if (AP2 == NULL){
        fopen("AP2.bin", "w");
    }
    fclose(AP2);
    
    menu();
    return 0;
}

