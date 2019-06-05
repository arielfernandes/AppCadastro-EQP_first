#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CADASTRO{
	char nome[50];
	char matricula[50];
	char descricao[200];
	char codPro[50];
};

struct CADASTRO *fluxo = NULL;
	 int qtdCad = 0;
	 FILE *arq;

void Fluxo(){

	char opc;
	char Devo[12]="Devolução:";
	char Sai[12]="Saída: ";

	system("tput clear");
	setbuf(stdin,NULL);
	printf("\n\nInforme a opcao desejada:\n Devolucao pressione a tecla (d)/ Saída pressione a tecla (s): \n\n If you want to exit, press ENTER.");
	scanf("%c", &opc);
	getchar();
		if(opc == 's')
		{
			system("tput clear");
			qtdCad++;
			fluxo = realloc(fluxo,qtdCad * sizeof(struct CADASTRO));
			if(fluxo == NULL){
				printf("\n\t*** Erro de alocacao de memoria. ***\n");
			}

			puts("Informe o Nome: ");
			setbuf(stdin,NULL);
			fgets(fluxo[qtdCad-1].nome,sizeof(struct CADASTRO),stdin);
			setbuf(stdin,NULL);
			puts("Informe o numero da Matricula: ");
			fgets(fluxo[qtdCad-1].matricula,sizeof(struct CADASTRO),stdin);
			setbuf(stdin,NULL);
			puts("Informe o equipamento/produto: ");
			fgets(fluxo[qtdCad-1].codPro,sizeof(struct CADASTRO),stdin);



		}
		if(opc == 'd')
		{
			system("tput clear");
			setbuf(stdin,NULL);
			printf("varios nada");
			getchar();
			system("tput clear");
		}
	arq = fopen("teste.txt","at");
	fwrite(&qtdCad, sizeof(int),1,arq);
	fwrite(fluxo, sizeof(struct CADASTRO),qtdCad,arq);
	fclose(arq);
	system("tput clear");
}
void CadProdutos(){
}

void ListarProdutos(){
}

void Remover(){
}
void Pesquisar(){
}
void Salvar(){
	
	arq = fopen("teste.txt","at");
	fwrite(&qtdCad, sizeof(int),1,arq);
	fwrite(fluxo, sizeof(struct CADASTRO),qtdCad,arq);
	fclose(arq);
	puts("\n\t>>> SALVANDO <<<\n");
	system("sleep 01");
	system("tput clear");
	puts("\n\t*** SALVO ***\n");
	system("sleep 01");
	system("tput clear");

}
int main(){
	int opcao = -1;
	arq = fopen("teste.txt","rt");
	if(arq == NULL){
		printf("\n\t>>> Arquivo não pode ser aberto <<<\n\n\t     >>>Um novo será criado<<<\n\n Aperte ENTER para continuar." );
		getchar();
		system("tput clear");
	}
	if(arq != NULL){
		fread(&qtdCad, sizeof(int),1,arq);
		fluxo = malloc(qtdCad*sizeof(struct CADASTRO));
		fread(fluxo, sizeof(struct CADASTRO),qtdCad,arq);
	}
	do{
puts("\n\n"
	 "\t\t ██╗      █████╗ ██████╗    ██████╗ ██╗\n"
	 "\t\t ██║     ██╔══██╗██╔══██╗   ██╔══██╗██║\n"
	 "\t\t ██║     ███████║██████╔╝   ██████╔╝██║\n"
	 "\t\t ██║     ██╔══██║██╔══██╗   ██╔═══╝ ██║\n"
	 "\t\t ███████╗██║  ██║██████╔╝██╗██║     ██║\n"
	 "\t\t ╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝     ╚═╝\n");
                                      
	printf("\t####################################################\n");
	printf("\t###           Informe a opcao desejada:          ###\n");
	printf("\t###         [1] - Fluxo Entrada/saída. (Eqp)     ###\n");
	printf("\t###         [2] - Registrar produtos.            ###\n");
	printf("\t###         [3] - Listar produtos.               ###\n");
	printf("\t###         [4] - Remover produtos.              ###\n");
	printf("\t###         [5] - Pesquisar.                     ###\n");
	printf("\t###         [6] - salvar                         ###\n");
	printf("\t###         [0] - Sair                           ###\n");
	printf("\t####################################################\n\n");
	printf(" -------------------------------------------------------------------- \n\n >>> ");
	

	setbuf(stdin,NULL);
	scanf("%d",&opcao);

	switch (opcao)
	{
		case 1: Fluxo();
				break;
		case 2: CadProdutos();
				break;
		case 3: ListarProdutos();
				break;
		case 4: Remover();
				break;
		case 5: Pesquisar();
				break;
		case 6: Salvar();
				break;
	} 
	
		}while(opcao !=0);
	free (fluxo);
	return 0;
}
