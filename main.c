#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
struct modeloData {
	int dia;
	int mes;
	int ano;

};

struct ModeloLivro {

	int codigo_livro;
	char nome_da_obra[30];
	char autor[30];
	char genero[30];
	int status;
	struct modeloData data_emprestimo;
	int codigo_usuario;
};

struct ModeloUsuario {

	int codigo_user;
	char nome_usuario[30];
	char endereco_usuario[50];
	char telefone_usuario[12];
	struct modeloData data_nascimento;
};

void inserirLivro();
void inserirUsuario();
void listarLivros();
void listarUsuarios();
void pesquisarLivroPorGenero();
void emprestarLivro();
void devolverLivro();
void funcao_Menu_e_Escolha_Usuario();
int verificaUsuario(struct ModeloUsuario *Usuarios, int *contador_usuario);

int main()
{
	int opcao = -1;
	int contador_livro = 0;
	int contador_usuario = 0;
	struct ModeloLivro cadastrarLivro[100];
	struct ModeloUsuario cadastrarUsuario[100];


	while (opcao != 0)
	{


		funcao_Menu_e_Escolha_Usuario(&opcao);
		switch (opcao)
		{

		case 1:

			inserirLivro(&cadastrarLivro, &contador_livro);
			contador_livro++;
			system("pause");
			system("cls");
			break;


		case 2:
			inserirUsuario(&cadastrarUsuario, &contador_usuario);
			contador_usuario++;
			system("pause");
			system("cls");
			break;

		case 3:
			listarLivros(cadastrarLivro, &contador_livro);
			system("pause");
			system("cls");

			break;

		case 4:
			listarUsuarios(cadastrarUsuario, &contador_usuario);
			system("pause");
			system("cls");

			break;


		case 5:
			pesquisarLivroPorGenero(cadastrarLivro, &contador_livro);
			system("pause");
			system("cls");
			break;

		case 6:
			emprestarLivro(&cadastrarLivro, &contador_livro, &cadastrarUsuario, &contador_usuario);
			system("pause");
			system("cls");
			break;


		case 7:
			devolverLivro(&cadastrarLivro, &contador_livro, &cadastrarUsuario, &contador_usuario);
			system("pause");
			system("cls");
			break;


		case 0:
			printf("OBRIGADO, VOLTE SEMPRE\n");
			system("pause");
			system("cls");
			break;

		}


	}

	return 0;
}

void inserirLivro(struct ModeloLivro *cadastroLivro, int *contador_livro)
{
	int codigo;
	int avanca = 1;

	printf("INSIRA O CODIGO DO LIVRO.\n");
	scanf("%d", &codigo);

	for (int i = 0; i < *contador_livro; i++)
	{

		if ((cadastroLivro + i)->codigo_livro = codigo)
		{
			printf("JA EXISTE UM LIVRO CADASTRADO COM ESTE CODIGO ESCOLHA OUTRO.\n");
			avanca = 0;
		}


	}

	if (avanca == 0)
		*contador_livro = *contador_livro - 1;


	if (avanca == 1)
	{
		(cadastroLivro + *contador_livro)->codigo_livro = codigo;

		fflush(stdin);
		printf("INSIRA O NOME DA OBRA.\n");
		gets((cadastroLivro + *contador_livro)->nome_da_obra);


		fflush(stdin);
		printf("INSIRA O AUTOR.\n");
		gets((cadastroLivro + *contador_livro)->autor);


		fflush(stdin);
		printf("INSIRA O GENERO.\n");
		gets((cadastroLivro + *contador_livro)->genero);


		do
		{
			printf("INSIRA O STATUS DO LIVRO.  1 PARA DISPONIVEL OU 0 PARA INDISPONIVEL.\n");
			scanf("%d", &(cadastroLivro + *contador_livro)->status);
		} while ((cadastroLivro + *contador_livro)->status != 0 && (cadastroLivro + *contador_livro)->status != 1);



		printf("INSIRA A DATA DO EMPRESTIMO NO FORMATO DIA MES E ANO , SEPARADO POR ESPACO.\n");
		scanf("%d %d %d", &(cadastroLivro + *contador_livro)->data_emprestimo.dia, &(cadastroLivro + *contador_livro)->data_emprestimo.mes, &(cadastroLivro + *contador_livro)->data_emprestimo.ano);


		//CODIGO DO USUARIO
		(cadastroLivro + *contador_livro)->codigo_usuario = 0;
		printf("\n\nLIVRO INSERIDO COM SUCESSO.\n");

	}


}
void inserirUsuario(struct ModeloUsuario *cadastroUsuario, int*contador_usuario)
{
	int codigo;
	int avanca = 1;
	printf("INSIRA O CODIGO DO USUARIO.\n");
	scanf("%d", &codigo);

	for (int i = 0; i < *contador_usuario; i++)
	{
		if ((cadastroUsuario + i)->codigo_user == codigo)
		{
			printf("JA EXISTE UM USUARIO CADASTRADO COM ESTE CODIGO ESCOLHA OUTRO.\n");
			avanca = 0;

		}


	}

	if (avanca == 0)
		*contador_usuario = *contador_usuario - 1;

	if (avanca == 1)
	{
		(cadastroUsuario + *contador_usuario)->codigo_user = codigo;

		fflush(stdin);
		printf("INSIRA O NOME DO USUARIO.\n");
		gets((cadastroUsuario + *contador_usuario)->nome_usuario);


		fflush(stdin);
		printf("INSIRA O ENDERECO DO USUARIO.\n");
		gets((cadastroUsuario + *contador_usuario)->endereco_usuario);



		fflush(stdin);
		printf("INSIRA O TELEFONE DO USUARIO.\n");
		gets((cadastroUsuario + *contador_usuario)->telefone_usuario);


		printf("INSIRA A DATA DE NASCIMENTO NO FORMATO: DIA  MES  ANO , SEPARADOS POR ESPACO.\n");
		scanf("%d %d %d", &(cadastroUsuario + *contador_usuario)->data_nascimento.dia, &(cadastroUsuario + *contador_usuario)->data_nascimento.mes, &(cadastroUsuario + *contador_usuario)->data_nascimento.ano);


		printf("USUARIO INSERIDO COM SUCESSO.\n");

	}



}
void listarLivros(struct ModeloLivro listarLivro[], int *contador_livro)
{

	printf("               LISTA DE LIVROS.\n\n");

	for (int i = 0; i < *contador_livro; i++)
	{

		printf("CODIGO DO LIVRO: %d\n", listarLivro[i].codigo_livro);
		printf("NOME DA OBRA: %s\n", listarLivro[i].nome_da_obra);
		printf("NOME DO AUTOR: %s\n", listarLivro[i].autor);
		printf("GENERO DO LIVRO: %s\n", listarLivro[i].genero);

		if (listarLivro[i].status == 1)
			printf("STATUS DO LIVRO: DISPONIVEL.\n");
		else
			printf("STATUS DO LIVRO: INDISPONIVEL.\n");

		printf("DATA DE EMPRESTIMO DO LIVRO: %d/%d/%d \n", listarLivro[i].data_emprestimo.dia, listarLivro[i].data_emprestimo.mes, listarLivro[i].data_emprestimo.ano);



		printf("CODIGO DO USUARIO: %d\n", listarLivro[i].codigo_usuario);
		printf("-------------");
		printf("\n");
	}


}
void listarUsuarios(struct ModeloUsuario listarUsuario[], int *contador_usuario)
{

	printf("               LISTA DE USUARIOS.\n\n");

	for (int i = 0; i < *contador_usuario; i++)
	{

		printf("CODIGO DO USUARIO: %d\n", listarUsuario[i].codigo_user);
		printf("NOME DO USUARIO: %s\n", listarUsuario[i].nome_usuario);
		printf("ENDERECO DO USUARIO: %s\n", listarUsuario[i].endereco_usuario);
		printf("TELEFONE DO USUARIO: %s\n", listarUsuario[i].telefone_usuario);
		printf("DATA DE NASCIMENTO DO USUARIO: %d/%d/%d \n", listarUsuario[i].data_nascimento.dia, listarUsuario[i].data_nascimento.mes, listarUsuario[i].data_nascimento.ano);
		printf("-------------");
		printf("\n");
	}

}
void pesquisarLivroPorGenero(struct ModeloLivro pesquisaLivro[], int *contador_livro)
{
	char genero[20];
	int k = 0;
	int i = 0;
	printf("INSIRA O GENERO, O QUAL DESEJAR REALIZAR A BUSCA.\n");
	fflush(stdin);
	gets(genero);


	for (i = 0; i < *contador_livro; i++)
	{

		if (!strcmp(pesquisaLivro[i].genero, genero))
		{

			printf("               LISTA DE LIVROS.\n\n");

			printf("CODIGO DO LIVRO: %d\n", pesquisaLivro[i].codigo_livro);
			printf("NOME DA OBRA: %s\n", pesquisaLivro[i].nome_da_obra);
			printf("NOME DO AUTOR: %s\n", pesquisaLivro[i].autor);
			printf("GENERO DO LIVRO: %s\n", pesquisaLivro[i].genero);

			if (pesquisaLivro[i].status == 1)
				printf("STATUS DO LIVRO: DISPONIVEL.\n");
			else
				printf("STATUS DO LIVRO: INDISPONIVEL.\n");

			printf("DATA DE EMPRESTIMO DO LIVRO: %d / %d / %d \n", pesquisaLivro[i].data_emprestimo.dia, pesquisaLivro[i].data_emprestimo.mes, pesquisaLivro[i].data_emprestimo.ano);
			printf("CODIGO DO USUARIO: %d\n", pesquisaLivro[i].codigo_usuario);
			printf("-------------");
			printf("\n");

			k++;
		}

	}

	if (k == 0)
		printf("\nNAO HA LIVROS DESTE GENERO NO ACERVO.\n");


}
void emprestarLivro(struct ModeloLivro *emprestarLivro, int *contador_livro, struct ModeloUsuario *Usuarios, int *contador_usuario)
{
	int codigo = 0, contador = 0, retorno = 0;

	printf("INSIRA O CODIGO DO LIVRO QUE DESEJAR PEGAR EMPRESTADO.\n");
	scanf("%d", &codigo);
	for (int i = 0; i < *contador_livro; i++)
	{
		if ((emprestarLivro + i)->codigo_livro == codigo)
		{

			if ((emprestarLivro + i)->status == 1)
			{

				retorno = verificaUsuario(Usuarios, contador_usuario);

				if (retorno >= 0)
				{
					(emprestarLivro + i)->status = 0;

					fflush(stdin);
					printf("INSIRA A DATA DO EMPRESTIMO DO LIVRO.\n");
					scanf("%d %d %d", &(emprestarLivro + i)->data_emprestimo.dia, &(emprestarLivro + i)->data_emprestimo.mes, &(emprestarLivro + i)->data_emprestimo.ano);

					(emprestarLivro + i)->codigo_usuario = retorno;
					printf("EMPRESTIMO REALIZADO COM SUCESSO.\n");
					break;
				}

				else
				{
					printf("O CODIGO DE USUARIO NAO CORRESPONDE A NENHUM USUARIO CADASTRADO.\n");
					break;
				}
			}
			else
			{
				printf("O LIVRO JA ESTA EMPRESTADO, ESCOLHA OUTRO.\n");
				break;

			}


		}

		else
		{
			contador++;
		}

	}

	if (contador == *contador_livro)
		printf("O CODIGO INSERIDO NAO CORRESPONDE A NENHUM LIVRO DO ACERVO.\n");


}
void devolverLivro(struct ModeloLivro *emprestarLivro, int *contador_livro, struct ModeloUsuario *Usuarios, int *contador_usuario)
{
	int codigo_livro, contador = 0, retorno = 0, i;
	int avanca = 0;

	printf("INSIRA O CODIGO DO LIVRO QUE DESEJA DEVOLVER.\n");
	scanf("%d", &codigo_livro);

	for (i = 0; i < *contador_livro; i++)
	{
		if ((emprestarLivro + i)->codigo_livro == codigo_livro)
			avanca = 1;

		else
		{
			avanca = 2;
		}
	}

	if (avanca == 1)
	{
		avanca = 0;
		retorno = verificaUsuario(Usuarios, contador_usuario);

		if (retorno >= 0)
			avanca = 1;

	}

	if (avanca == 1)
	{
		for (i = 0; i < *contador_livro; i++)
		{
			if ((emprestarLivro + i)->codigo_livro == codigo_livro && (emprestarLivro + i)->codigo_usuario == retorno)
			{

				(emprestarLivro + i)->codigo_usuario = 0;
				(emprestarLivro + i)->status = 1;



				printf("INSIRA A DATA DE DEVOLUCAO NO FORMATO DIA MES E ANO , SEPARADO POR ESPACO.\n");
				scanf("%d %d %d", &(emprestarLivro)->data_emprestimo.dia, &(emprestarLivro)->data_emprestimo.mes, &(emprestarLivro)->data_emprestimo.ano);



				printf("DEVOLUCAO REALIZADA COM SUCESSO.\n");
				break;
			}



			else
			{
				contador++;
			}


		}

		if (contador == *contador_livro)
			printf("O USUARIO INFORMADO NAO PEGOU ESTE LIVRO EMPRESTADO.\n");

	}

	if (*contador_livro == 0)
		avanca = 2;

	if (avanca == 0)
		printf("O USUARIO INFORMANDO NAO EXISTE.\n");

	if (avanca == 2)
		printf("O CODIGO DO LIVRO INFORMANDO NAO EXISTE.\n");





}

void funcao_Menu_e_Escolha_Usuario(int *Popcao)
{
	int opcao = -1;
	printf("                           MENU\n\n");
	printf("1 - PARA INSERIR LIVRO\n");
	printf("2 - PARA INSERIR USUARIO\n");
	printf("3 - PARA LISTAR  LIVROS\n");
	printf("4 - PARA LISTAR  USUARIOS\n");
	printf("5 - PARA PESQUISAR LIVRO POR GENERO\n");
	printf("6 - PARA EMPRESTAR LIVRO\n");  // BUSCAR LIVRO POR CODIGO E VERIFICAR STATUS , TRUE OU FALSE, SE TRUE ALTERAR PARA EMPRESTADO (FALSE) E ARMAZENAR DATA E CODIGO DO USUARIO
	printf("7 - PARA DEVOLVER LIVRO\n"); // BUSCAR LIVRO POR CODIGO E TROCAR  STATUS PARA DISPONIVEL(TRUE) E ZERAR DATA A DATA E USUARIO.
	printf("0 - PARA SAIR DO PROGRAMA.\n");
	printf("\nINSIRA A OPCAO DESEJADA.\n");

	while (opcao < 0 || opcao > 7)
	{
		scanf("%d", &opcao);
	}

	printf("\n\n");
	*Popcao = opcao;
};

int verificaUsuario(struct ModeloUsuario Usuarios[], int *contador_usuario)
{
	int retorno = -1;
	int codigo;


	printf("INSIRA O CODIGO DO USUARIO.\n");
	scanf("%d", &codigo);


	for (int i = 0; i < *contador_usuario; i++)
	{


		if (Usuarios[i].codigo_user == codigo)
		{
			retorno = codigo;

		}


	}


	return retorno;
}

