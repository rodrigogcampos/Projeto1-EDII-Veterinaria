#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int codexist;
    char confirm[] = "S";
    struct animal c;
    int aux;
    char aux2[10] = "";

    while (strcmp ((strupr(confirm)), "S") == 0)
    {
        AP2 = fopen("AP2.bin", "ab");

        printf("\ncodigo: ");
        fflush(stdin);
        scanf("%d",&dog.cod);
        sprintf(aux2, "%d", dog.cod);
        printf("%s",aux2);

        /*codexist = 0;
        while(!feof(AP2))
        {
            fread(&c,sizeof(dog),1,AP2);
            //printf("%d\n%s\n%s\n", c.cod, c.name, c.raca);
            if (dog.cod == c.cod){
                codexist = 1;
                break;
            }
        }*/
        fclose(AP2);

        if (codexist == 1)
        {
            printf("codigo do dog ja exite!\n");
            printf("Cadastrar novamente?[S/N]");
            gets(confirm);
        }
        else{
            printf("nome: ");
            fflush(stdin);
            gets(dog.name);

            printf("raca: ");
            fflush(stdin);
            gets(dog.raca);

            AP2 = fopen("AP2.bin", "ab");
           // fputc(&aux2,AP2);
            fwrite(&aux2,sizeof(aux2),1,AP2);
            fwrite(&dog.name,sizeof(dog.name),1,AP2);
            fwrite(&dog.raca,sizeof(dog.raca),1,AP2);
            fclose(AP2);

            printf("Deseja cadastrar outro cachorro?[S/N]");
            gets(confirm);
        }

    }
    sair();
}
int opcao2(){ /* não precisa
    FILE *BKP;
    struct animal c[1000];

    AP2 = fopen("AP2.txt", "rb");
    BKP = fopen("BKP.txt", "w");
    int i=1;

    while(!feof(AP2))
    {
        fread(&c[i],sizeof(dog),1,AP2);

        printf("%s\n%s\n%s\n", c[i].cod, c[i].name, c[i].raca);
        printf("\n***%d***\n",i);
        i++;
    }
    fwrite(&c[1],sizeof(dog),i-1,BKP);

    fclose(AP2);
    fclose(BKP);

    sair();*/
}
int opcao3(){
        AP1 = fopen("AP1.txt", "wb");
        char registro[35];

        printf("Nome da vacina: ");
        fflush(stdin);
        gets(vacina.name);

        printf("Data da vacina: ");
        gets(vacina.date);

        printf("Responsavel pela vacina: ");
        gets(vacina.person);

        sprintf(registro,"%s|%s|%s|",vacina.name,vacina.date,vacina.person);
        fwrite(registro,sizeof(registro),1,AP1);

        fclose(AP1);

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
    printf("6666666666666666666666666666666\n");
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

    AP2 = fopen("AP2.bin", "a");
    if (AP2 == NULL){
        fopen("AP2.bin", "w");
    }
    fclose(AP2);
    menu();
    return 0;
}

