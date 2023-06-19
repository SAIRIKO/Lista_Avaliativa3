/*
Neste código tem algumas funções que não funcionam no Visual Studio Code
Ex. system('cls'), e a biblioteca <locale.h>

Por isso separei esse arquivo só pro VS code
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MARCAS 5
#define MAX_PRODUTOS 50

typedef struct {
    char nome[100];
    char site[100];
    char telefone[20];
    char UF[3];
} Marca;

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char fabricante[100];
    Marca marca;
} Produto;

Marca cadastrarMarca();
Produto cadastrarProduto(Marca *marcas, int numMarcas, int i);
void listarMarcas(Marca *marcas, int numMarcas, int i);
void listarProdutos(Produto *produtos, int numProdutos, int ordem, int i);
void listarProdutosMarca(Produto *produtos, int numProdutos, Marca marca, int i);
int compararProdutosCrescente(const void *a, const void *b);
int compararProdutosDecrescente(const void *a, const void *b);

void le_valida_peso(float *peso);
void le_valida_valor(float *valor, float min, float max);
void le_valida_uf(char *uf);

int main() {    
    Marca marcas[MAX_MARCAS];
    Produto produtos[MAX_PRODUTOS];
    int numMarcas = 0;
    int numProdutos = 0;
    int opcao;
    int i, j;
    Produto temp;
    
    do {int i, j;
    int marcaSelecionada;

        printf("------------------ Menu ------------------\n\n");
        printf("1 - Cadastrar nova marca\n");
        printf("2 - Cadastrar novo produto\n");
        printf("3 - Listar todas as marcas\n");
        printf("4 - Listar todos os produtos\n");
        printf("5 - Listar produtos de uma determinada marca\n");
        printf("6 - Listar produtos em ordem crescente (Alfabetica)\n");
        printf("7 - Listar produtos em ordem decrescente (Alfabetica)\n");
        printf("8 - Encerrar o programa\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numMarcas >= MAX_MARCAS) {
                    printf("Numero maximo de marcas atingido!\n");
                } else {
                    marcas[numMarcas] = cadastrarMarca();
                    numMarcas++;
                    printf("Marca cadastrada com sucesso!\n");
                }
                break;
            case 2:
                if (numMarcas < 2) {
                    printf("Eh necessario ter pelo menos 2 marcas cadastradas para adicionar produtos!\n");
                } else if (numProdutos >= MAX_PRODUTOS) {
                    printf("Numero maximo de produtos atingido!\n");
                } else {
                    produtos[numProdutos] = cadastrarProduto(marcas, numMarcas, i);
                    numProdutos++;
                    printf("Produto cadastrado com sucesso!\n");
                }
                break;
            case 3:
                if (numMarcas == 0) {
                    printf("Nao ha marcas cadastradas!\n");
                } else {
                    listarMarcas(marcas, numMarcas, i);
                }
                break;
            case 4:
                if (numProdutos == 0) {
                    printf("Nao ha produtos cadastrados!\n");
                } else {
                    listarProdutos(produtos, numProdutos, 0, i);
                }
                break;
            case 5:
			    if (numProdutos == 0) {
			        printf("Nao ha produtos cadastrados!\n");
			    } else {
			        printf("Selecione a marca do produto: \n");
			        for (i = 0; i < numMarcas; i++) {
			            printf("%d - %s\n", i + 1, marcas[i].nome);
			        }
			        scanf("%d", &marcaSelecionada);
			        if (marcaSelecionada >= 1 && marcaSelecionada <= numMarcas) {
			            listarProdutosMarca(produtos, numProdutos, marcas[marcaSelecionada - 1], i); // Use a variável marcaSelecionada ao invés de i
			        } else {
			            printf("Marca invalida!\n");
			        }
			    }
			    break;

            case 6:
                if (numProdutos == 0) {
                    printf("Nao ha produtos cadastrados!\n");
                } else {
                    qsort(produtos, numProdutos, sizeof(Produto), compararProdutosCrescente);
                    listarProdutos(produtos, numProdutos, 0, i);
                }
                break;
            case 7:
                if (numProdutos == 0) {
                    printf("Nao ha produtos cadastrados!\n");
                } else {
                    qsort(produtos, numProdutos, sizeof(Produto), compararProdutosDecrescente);
                    listarProdutos(produtos, numProdutos, 0, i);
                }
                break;
            case 8:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}

int compararProdutosCrescente(const void *a, const void *b) {
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return strcmp(produtoA->descricao, produtoB->descricao);
}

int compararProdutosDecrescente(const void *a, const void *b) {
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return strcmp(produtoB->descricao, produtoA->descricao);
}

Marca cadastrarMarca() {
    Marca marca;
    printf("Digite o nome da marca: ");
    scanf(" %[^\n]", marca.nome);
    printf("Digite o site da marca: ");
    scanf(" %[^\n]", marca.site);
    printf("Digite o telefone da marca: ");
    scanf(" %[^\n]", marca.telefone);
    printf("Digite o UF da marca: ");
    le_valida_uf(marca.UF);
    return marca;
}

Produto cadastrarProduto(Marca *marcas, int numMarcas, int i) {
    Produto produto;
    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", produto.descricao);
    printf("Digite o peso do produto: ");
    le_valida_peso(&produto.peso);
    printf("Digite o valor de compra do produto: ");
    le_valida_valor(&produto.valorCompra, 0, 999999);
    printf("Digite o valor de venda do produto: ");
    le_valida_valor(&produto.valorVenda, produto.valorCompra, 999999);
    produto.valorLucro = produto.valorVenda - produto.valorCompra;
    produto.percentualLucro = (produto.valorLucro / produto.valorCompra) * 100;

    printf("Digite o fabricante do produto: ");
    scanf(" %[^\n]", produto.fabricante);

    printf("Selecione a marca do produto: \n");
    for (i = 0; i < numMarcas; i++) {
        printf("%d - %s\n", i+1, marcas[i].nome);
    }
    scanf("%d", &i);
    produto.marca = marcas[i-1];

    return produto;
}

void listarMarcas(Marca *marcas, int numMarcas, int i) {
    printf("------------ Marcas cadastradas ------------\n");
    for (i = 0; i < numMarcas; i++) {
        printf("Marca %d:\n", i+1);
        printf("Nome: %s\n", marcas[i].nome);
        printf("Site: %s\n", marcas[i].site);
        printf("Telefone: %s\n", marcas[i].telefone);
        printf("UF: %s\n", marcas[i].UF);
        printf("--------------------------------------------\n");
    }
}

void listarProdutos(Produto *produtos, int numProdutos, int ordem, int i) {
    if (ordem == 0) {
        printf("------------ Produtos cadastrados (ordem crescente) ------------\n");
    } else {
        printf("------------ Produtos cadastrados (ordem decrescente) ------------\n");
    }
    for (i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i+1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor de lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual de lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante);
        printf("Marca: %s\n", produtos[i].marca.nome);
        printf("--------------------------------------------\n");
    }
}

void listarProdutosMarca(Produto *produtos, int numProdutos, Marca marca, int i) {
    printf("------------ Produtos da marca %s ------------\n", marca.nome);
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].marca.nome, marca.nome) == 0) {
            printf("Produto %d:\n", i+1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor de lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual de lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante);
            printf("--------------------------------------------\n");
        }
    }
}

void le_valida_peso(float *peso) {
    do {
        scanf("%f", peso);
        if (*peso <= 0) {
            printf("O peso deve ser um valor positivo! Digite novamente: ");
        }
    } while (*peso <= 0);
}

void le_valida_valor(float *valor, float min, float max) {
    do {
        scanf("%f", valor);
        if (*valor < min || *valor > max) {
            printf("O valor deve estar entre %.2f e %.2f! Digite novamente: ", min, max);
        }
    } while (*valor < min || *valor > max);
}

void le_valida_uf(char *uf) {
    do {
        scanf("%s", uf);
        if (strlen(uf) != 2) {
            printf("UF invalido! Digite novamente: ");
        }
    } while (strlen(uf) != 2);
}