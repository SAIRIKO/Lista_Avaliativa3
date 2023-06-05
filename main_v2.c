#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define TOT_FAB 5
#define TOT_PRODUT 50

struct Fabricante{
    char marca[16];
    char site[31];
    char telefone[16];
    char uf[3];

} ;
struct Produto{
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    int fabricante;
    int indice;
};

void cabecalho();
int cadastro_fab(struct Fabricante fabricantes[]);
  void val_marca_fab(struct Fabricante fabricantes[], int quant_fab, int i);
  void val_site_fab(struct Fabricante fabricantes[], int quant_fab, int i);
  void val_tel_fab(struct Fabricante fabricantes[], int quant_fab, int i);
  void val_uf_fab(struct Fabricante fabricantes[], int quant_fab, int i);
int cadastro_prod(struct Fabricante fabricantes[], struct Produto produtos[], int quant_fab);
  void val_descricao(struct Produto produtos[], int quant_prot, int i);
    void descricao_limite_20_chars(struct Produto produtos[], int i);
  void val_peso(struct Produto produtos[], int quant_prot, int i);
  void val_valor_compra(struct Produto produtos[], int quant_prod, int i);
  void val_valor_venda(struct Produto produtos[], int quant_prod, int i);
  void selecionar_fab(struct Fabricante fabricantes[], struct Produto produtos[], int quant_fab, int quant_prod, int i);
    void menu_fab(struct Fabricante fabricantes[], int quant_fab, int selecao);

void imprime_produto(struct Produto produtos[], int i,struct Fabricante fabricantes[]);

void menu();
void linha();
void lista_marcas(struct Fabricante fabricantes[], int quant_fab);
void lista_produtos(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[]);
void lista_produtos_estado(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[]);
void lista_produtos_marca(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab);
void lista_estados_produto_caro(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab);
void lista_estados_produto_barato(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab);
void lista_ordem_crescente(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab);
void lista_lucro(struct Produto produtos[], int quant_produt, struct Fabricante fabricantes[], int quant_fab);
void lista_percentual_lucro(struct Produto produtos[], int quant_produt, struct Fabricante fabricantes[], int quant_fab);

int main() {
  struct Fabricante fabricantes[TOT_FAB];
  struct Produto produtos[TOT_PRODUT];
  int quant_fab = 0, quant_prod = 0;
  int tecla = 0;
  
  system("chcp 1252");
  quant_fab = cadastro_fab(fabricantes);
  quant_prod = cadastro_prod(fabricantes, produtos, quant_fab);

    int escolhamenu;
    getchar();
    printf("\e[1;1H\e[2J");

  while(1){
    menu();
    do{
      printf("escolha um numero valido(entre 1 e 9):\n");
    scanf("%d",&escolhamenu);
    }while(escolhamenu<0||escolhamenu>9);
    getchar();
    printf("\e[1;1H\e[2J");

    if(escolhamenu==0){
      break;
    }

    
    if(escolhamenu==1){
      
      linha();

      printf("| Relatorio 1                                                             |\n");
      linha();

      lista_marcas(fabricantes,quant_fab);
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

    if(escolhamenu==2){
      linha();

      printf("| Relatorio 2                                                             |\n");
      linha();

      lista_produtos(produtos,quant_prod,fabricantes);
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

        if(escolhamenu==3){
      linha();
      printf("| Relatorio 3                                                             |\n");
      linha();

      lista_produtos_estado(produtos, quant_prod,fabricantes);
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

        if(escolhamenu==4){
      linha();
      printf("| Relatorio 4                                                             |\n");
      linha();

      lista_produtos_marca(produtos, quant_prod,fabricantes,quant_fab);
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

        if(escolhamenu==5){
      linha();
      printf("| Relatorio 5                                                             |\n");
      linha();

    lista_estados_produto_caro(produtos,quant_prod,fabricantes,quant_fab);
      
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

        if(escolhamenu==6){
      linha();
      printf("| Relatorio 6                                                             |\n");
      linha();

    lista_estados_produto_barato(produtos,quant_prod,fabricantes,quant_fab);
      
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

          if(escolhamenu==7){
      linha();
      printf("| Relatorio 7                                                             |\n");
      linha();

    lista_ordem_crescente(produtos,quant_prod,fabricantes,quant_fab);
      
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

             if(escolhamenu==8){
      linha();
      printf("| Relatorio 8                                                             |\n");
      linha();

    lista_lucro(produtos,quant_prod,fabricantes,quant_fab);
      
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

    if(escolhamenu==9){
      linha();
      printf("| Relatorio 9                                                             |\n");
      linha();

    lista_percentual_lucro(produtos,quant_prod,fabricantes,quant_fab);
      
      printf("\n[0] Voltar ao menu\n[9] Encerrar programa\n");
      scanf("%d",&escolhamenu);
      
      if(escolhamenu==9){
        break;
      }
      if(escolhamenu==0){
        printf("\e[1;1H\e[2J");
      }
    }

  }

  return 0;
}



void cabecalho(){
  system("cls");
  printf("CADASTRO DE FABRICANTES E PRODUTOS\n\n");
}

int cadastro_fab(struct Fabricante fabricantes[]) {
  int quant_fab = 0, i = 0;

  do{
    cabecalho();
    printf("Quantos fabricantes deseja cadastrar? (2 a 5) ");
    scanf("%d", &quant_fab);
    fflush(stdin);

    if (quant_fab < 2 || quant_fab > 5) {
      printf("\n\n\t\tQUANTIDADE INVALIDA!!!");
      getch();
    }
    
  } while (quant_fab < 2 || quant_fab > 5);

  for(i = 0; i < quant_fab; i++){
    val_marca_fab(fabricantes, quant_fab, i);
    val_site_fab(fabricantes, quant_fab, i); 
    val_tel_fab(fabricantes, quant_fab, i); 
    val_uf_fab(fabricantes, quant_fab, i);

    cabecalho();
    printf("                                   %d FABRICANTES\n\n", quant_fab);
    printf("    %do fabricante\n\n", i+1);
    printf("        MARCA: %s\n", fabricantes[i].marca);
    printf("         Site: %s\n", fabricantes[i].site);
    printf("     Telefone: %s\n", fabricantes[i].telefone);  
    printf("   UF (sigla): %s\n", fabricantes[i].uf);
    printf("\n\t\t\tFabricante cadastrado com sucesso!", i+1);
    system("timeout 7 >nul");    
    }

  return quant_fab;
  }

void val_marca_fab(struct Fabricante fabricantes[], int quant_fab, int i) {
    do {
      cabecalho();
      printf("                                   %d FABRICANTES\n\n", quant_fab);
      printf("    %do fabricante\n\n", i+1);
      printf("        MARCA: ");
      scanf("%[^\n]s", &fabricantes[i].marca);
      fflush(stdin);

      if (strlen(fabricantes[i].marca) > 15) {
        printf("\n\t\tMARCA INVALIDA! Ela deve ter no maximo 15 caracteres.");
        getch();
      }
    } while (strlen(fabricantes[i].marca) > 15);
}

void val_site_fab(struct Fabricante fabricantes[], int quant_fab, int i) {
  do {
    cabecalho();
    printf("                                   %d FABRICANTES\n\n", quant_fab);
    printf("    %do fabricante\n\n", i+1);
    printf("        MARCA: %s\n", fabricantes[i].marca);
    printf("         Site: ");
    scanf("%[^\n]s", &fabricantes[i].site);
    fflush(stdin);

    if (strlen(fabricantes[i].marca) > 30) {
      printf("\n\t\tSITE INVALIDO! Ele deve ter no maximo 30 caracteres.");
      getch();
    }    
  } while (strlen(fabricantes[i].site) > 30);
}

void val_tel_fab(struct Fabricante fabricantes[], int quant_fab, int i) {
  do {
    cabecalho();
    printf("                                   %d FABRICANTES\n\n", quant_fab);
    printf("    %do fabricante\n\n", i+1);
    printf("        MARCA: %s\n", fabricantes[i].marca);
    printf("         Site: %s\n", fabricantes[i].site);
    printf("     Telefone: ");
    scanf("%[^\n]s", &fabricantes[i].telefone);
    fflush(stdin);

    if (strlen(fabricantes[i].telefone) > 11) {
      printf("\n\t\tTELEFONE INVALIDO! Maximo de 15 digitos, ok?");
      getch();
    }
  } while (strlen(fabricantes[i].telefone) > 11);
}

void val_uf_fab(struct Fabricante fabricantes[], int quant_fab, int i) {
  const char siglas[27][3] = { "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO",
                               "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
                               "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO" };
  int igual = 1, j = 0;

  do {
    cabecalho();
    printf("                                   %d FABRICANTES\n\n", quant_fab);
    printf("    %do fabricante\n\n", i+1);
    printf("        MARCA: %s\n", fabricantes[i].marca);
    printf("         Site: %s\n", fabricantes[i].site);
    printf("     Telefone: %s\n", fabricantes[i].telefone);  
    printf("   UF (sigla): ");
    scanf("%[^\n]s", &fabricantes[i].uf);
    fflush(stdin);

    for (j = 0; j < 27; j++) {
      if (stricmp(siglas[j], fabricantes[i].uf) == 0) {
        igual = 0;
      }
    }  
    if (igual != 0) {
      printf("\n\t\tUF INVALIDA! Verifique se a sigla foi digitada corretamente.");
      getch();
    }
  } while (igual != 0);
}

int cadastro_prod(struct Fabricante fabricantes[], struct Produto produtos[], int quant_fab) {
  int quant_prod = 0, i = 0;
  
  do {
    cabecalho();
    printf("Quantos produtos deseja cadastrar? (5 a 50) ");
    scanf("%d", &quant_prod);
    fflush(stdin);

    if (quant_prod < 5 || quant_prod > 50) {
      printf("\n\t\tQUANTIDADE INVALIDA!!! Digite um numero entre 5 e 50 de produtos");
      getch();
    }
  } while (quant_prod < 5 || quant_prod > 50);

  for(i = 0; i < quant_prod; i++) {
    produtos[i].indice=i;

    val_descricao(produtos, quant_prod, i);
    val_peso(produtos, quant_prod, i);
    val_valor_compra(produtos, quant_prod, i);
    val_valor_venda(produtos, quant_prod, i); 
    selecionar_fab(fabricantes, produtos, quant_fab, quant_prod, i); 

    produtos[i].valorLucro=produtos[i].valorVenda-produtos[i].valorCompra;
    produtos[i].percentualLucro=(produtos[i].valorLucro/produtos[i].valorCompra)*100;

    cabecalho();
    printf("                                   %d PRODUTOS\n\n", quant_prod);
    printf("      %do produto\n\n", i+1);
    printf("      Descricao: ");
    descricao_limite_20_chars(produtos, i);
    printf("           Peso: %.1f kg\n", produtos[i].peso);
    printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
    printf("    ||    venda: R$ %.2f\n", produtos[i].valorVenda);
    printf("     Fabricante: %s\n", fabricantes[produtos[i].fabricante].marca);
    printf("\n\t\t\tProduto cadastrado com sucesso!", i+1);
    system("timeout 7 >nul");
  }

  return quant_prod;
}

void val_descricao(struct Produto produtos[], int quant_prod, int i) {
  cabecalho();
  printf("                                   %d PRODUTOS\n\n", quant_prod);
  printf("      %do produto\n\n", i+1);

  printf("      Descricao: ");
  
  fgets(produtos[i].descricao, sizeof(produtos[i].descricao), stdin); 
  produtos[i].descricao[strcspn(produtos[i].descricao, "\n")] = '\0'; 
}

void descricao_limite_20_chars(struct Produto produtos[], int i) {
  int j = 0;

  if (strlen(produtos[i].descricao) > 20) {
    for (j = 0; j < 20; j++) {
      printf("%c", produtos[i].descricao[j]);
    }
    printf("...\n");
  } else {
    printf("%s\n", produtos[i].descricao);
  }  
}

void val_peso(struct Produto produtos[], int quant_prod, int i) {
  do {
    cabecalho();
    printf("                                   %d PRODUTOS\n\n", quant_prod);
    printf("      %do produto\n\n", i+1);
    printf("      Descricao: ");
    descricao_limite_20_chars(produtos, i);

    printf("      Peso (kg): ");
    scanf("%f", &produtos[i].peso);
    fflush(stdin);

    if (produtos[i].peso <= 0 || produtos[i].peso > 10000000) {
      printf("\n\t\tPESO INVALIDO! Peso nao pode ser negativo e nem passar de 10000000 kg (10 t)");
      getch();
    }
  } while (produtos[i].peso <= 0 || produtos[i].peso > 10000000);
}

void val_valor_compra (struct Produto produtos[], int quant_prod, int i) {
  do {
    cabecalho();
    printf("                                   %d PRODUTOS\n\n", quant_prod);
    printf("      %do produto\n\n", i+1);
    printf("      Descricao: ");
    descricao_limite_20_chars(produtos, i);
    printf("           Peso: %.1f kg\n", produtos[i].peso);

    printf("Valor de compra: R$ ");
    scanf("%f",&produtos[i].valorCompra);
    fflush(stdin);

    if (produtos[i].valorCompra < 0 || produtos[i].valorCompra > 10000000) {
      printf("\n\t\tVALOR DE COMPRA INVALIDO! Valor nao pode ser negativo e nem maior que que R$ 10000000");
      getch();
    }
  } while (produtos[i].valorCompra < 0 || produtos[i].valorCompra > 10000000);
}

void val_valor_venda (struct Produto produtos[], int quant_prod, int i) {
  do {
    cabecalho();
    printf("                                   %d PRODUTOS\n\n", quant_prod);
    printf("      %do produto\n\n", i+1);
    printf("      Descricao: ");
    descricao_limite_20_chars(produtos, i);
    printf("           Peso: %.1f kg\n", produtos[i].peso);
    printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
    
    printf("    ||    venda: R$ ");
    scanf("%f", &produtos[i].valorVenda);
    fflush(stdin);

    if (produtos[i].valorVenda < 0 || produtos[i].valorVenda > 100000000) {
      printf("\n\t\tVALOR DE VENDA INVALIDO! Valor nao pode ser negativo e nem maior que que R$ 100000000");
      getch();
    }
  } while (produtos[i].valorVenda < 0 || produtos[i].valorVenda > 100000000);
}

void selecionar_fab(struct Fabricante fabricantes[], struct Produto produtos[], int quant_fab, int quant_prod, int i) {

  int selecao = 0, tecla = 0, j = 0;

  do {
    cabecalho();
    printf("                                   %d PRODUTOS\n\n", quant_prod);
    printf("      %do produto\n\n", i+1);
    printf("      Descricao: ");
    descricao_limite_20_chars(produtos, i);
    printf("           Peso: %.1f kg\n", produtos[i].peso);
    printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
    printf("    ||    venda: R$ %.2f\n", produtos[i].valorVenda);

    switch (selecao) {
      case 0:
        menu_fab(fabricantes, quant_fab, selecao);

        tecla = getch();
      
        if (tecla == 0 || tecla == 224){
          tecla = getch();
        }
        if (tecla == 80) {
          selecao = 1;
        }
        break;

      case 1:
        menu_fab(fabricantes, quant_fab, selecao);

        tecla = getch();
        if (tecla == 0 || tecla == 224){
          tecla = getch();
        }
        if (tecla == 72) {
          selecao = 0;
        } else if (tecla == 80 && quant_fab > 2) {
          selecao = 2;
        }
        break;

        case 2:
          menu_fab(fabricantes, quant_fab, selecao);

          tecla = getch();
          if (tecla == 0 || tecla == 224){
            tecla = getch();
          }
          if (tecla == 72) {
            selecao = 1;
          } else if (tecla == 80 && quant_fab > 3) {
            selecao = 3;
          }
          break;

        case 3:
          menu_fab(fabricantes, quant_fab, selecao);

          tecla = getch();
          if (tecla == 0 || tecla == 224){
            tecla = getch();
          }
          if (tecla == 72) {
            selecao = 2;
          } else if (tecla == 80 && quant_fab > 4) {
            selecao = 4;
          }
          break;

        case 4:
            menu_fab(fabricantes, quant_fab, selecao);

            tecla = getch();
            if (tecla == 0 || tecla == 224){
              tecla = getch();
            }
            if (tecla == 72) {
              selecao = 3;
            }
          break;

        default:
          break;
    }
  } while (tecla != 13);

  produtos[i].fabricante = selecao;
}

void menu_fab(struct Fabricante fabricantes[], int quant_fab, int selecao) {
  if (quant_fab < 3) {
    switch (selecao) {
      case 0:
        printf("     Fabricante -> %s\n", fabricantes[0].marca);
        printf("                   %s", fabricantes[1].marca);
        break;
      case 1:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                -> %s", fabricantes[1].marca);
        break;
      default:
        break;
    }
  } else if (quant_fab == 3) {
    switch (selecao) {
      case 0:
        printf("     Fabricante -> %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s", fabricantes[2].marca);
        break;
      case 1:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                -> %s\n", fabricantes[1].marca);
        printf("                   %s", fabricantes[2].marca);
        break;
      case 2:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                -> %s", fabricantes[2].marca);
        break;
      default:
        break;
    }
  } else if (quant_fab == 4) {
    switch (selecao) {
      case 0:
        printf("     Fabricante -> %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                   %s", fabricantes[3].marca);        
        break;
      case 1:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                -> %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                   %s", fabricantes[3].marca);
        break;
      case 2:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                -> %s\n", fabricantes[2].marca);
        printf("                   %s", fabricantes[3].marca);
        break;
      case 3:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                -> %s", fabricantes[3].marca);
        break;        
      default:
        break;
    }
  } else if (quant_fab == 5) {
    switch (selecao) {
      case 0:
        printf("     Fabricante -> %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                   %s\n", fabricantes[3].marca);
        printf("                   %s", fabricantes[4].marca);
        break;
      case 1:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                -> %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                   %s\n", fabricantes[3].marca);
        printf("                   %s", fabricantes[4].marca);
        break;
      case 2:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                -> %s\n", fabricantes[2].marca);
        printf("                   %s\n", fabricantes[3].marca);
        printf("                   %s", fabricantes[4].marca);
        break;
      case 3:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                -> %s\n", fabricantes[3].marca);
        printf("                   %s", fabricantes[4].marca);
        break;
      case 4:
        printf("     Fabricante    %s\n", fabricantes[0].marca);
        printf("                   %s\n", fabricantes[1].marca);
        printf("                   %s\n", fabricantes[2].marca);
        printf("                   %s\n", fabricantes[3].marca);
        printf("                -> %s", fabricantes[4].marca);
        break;                
      default:
        break;
    }
  }
}

void menu(){
  linha();
  printf("[1] Listar todas as marcas\n");
  printf("[2] Listar todas os produtos\n");
  printf("[3] Listar os produtos de um determinado estado\n");
  printf("[4] Listar os produtos de uma determinada marca\n");
  printf("[5] Apresentar o(s) estado(s) com o produto mais caro\n");
  printf("[6] Apresentar o(s) fabricantes(s) com o produto mais barato\n");
  printf("[7] Listar todos produtos em ordem crescente de valor\n");
  printf("[8] Listar todos produtos em ordem crescente de maior valor de lucro\n");
  printf("[9] Listar todos produtos em ordem crescente de maior percentual de lucro\n");
  printf("[0] Sair\n");
linha();
}

void lista_marcas(struct Fabricante fabricantes[], int quant_fab){
  int i=0;
  for(i=0;i<quant_fab;i++){

    printf("|Nome:%s|",fabricantes[i].marca);
    printf("|Site:%s|",fabricantes[i].site);
    printf("|Telefone:%s|",fabricantes[i].telefone);
    printf("|UF:%s|\n",fabricantes[i].uf);
    linha();
  }
}

void lista_produtos(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[]){
  int i=0;
  for(i=0;i<quant_produt;i++){
    
    imprime_produto(produtos, i, fabricantes);

    linha();
  }
}

void lista_produtos_estado(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[]){
  char siglas[27][3] = {
  "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO",
  "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
  "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"
  },uf[3];
  printf("Estados disponiveis:\n");
  int i = 0, j = 0, escolhaestado, valida_se_tem=0;
  for(i=0;i<27;i++){
    printf("[%d]%s\n",i,siglas[i]);
  }
  do{
  scanf("%d",&escolhaestado);}while(escolhaestado<0||escolhaestado>26);

  getchar();
  printf("\e[1;1H\e[2J");
  linha();
  printf("Produtos do estado %s                                                     |        \n",siglas[escolhaestado]);
  linha();
  for(i=0;i<quant_produt;i++){
    strcpy(uf,fabricantes[produtos[i].fabricante].uf);
    for(j=0;j<=1;j++){
      uf[j]=toupper(uf[j]);
    }
    if(strcmp(siglas[escolhaestado],uf)==0){
    imprime_produto(produtos, i, fabricantes);

      valida_se_tem=1;
    }

  }
  if(valida_se_tem==0){
    printf("Nao ha nenhum produto desse estado\n");
  }
}
void lista_produtos_marca(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab){
    int escolhe_marca,tem_marca=0, i = 0;
    for(i=0;i<quant_fab;i++){
      printf("[%d]%s\n",i,fabricantes[i].marca);
    }
    do{
      printf("Digite uma das opcoes acima:\n");
      scanf("%d",&escolhe_marca);
    }while(escolhe_marca>quant_fab-1||escolhe_marca<0);
  for(i=0;i<quant_produt;i++){
    if(produtos[i].fabricante==escolhe_marca){
    imprime_produto(produtos, i, fabricantes);
    tem_marca=1;
    }

    
  }
    if(tem_marca==0){
      printf("Nao ha produtos registrados dessa marca\n");
      linha();
    }
}
void lista_estados_produto_caro(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab){
  int produt_maior=0, i = 0;

  for(i=0;i<quant_produt;i++){
    if(produtos[i].valorCompra>=produt_maior){
    produt_maior=produtos[i].valorCompra;
    }
  }
  printf("O(s) produto(s) mais caro(s)\n");
  for(i=0;i<quant_produt;i++){
      if(produt_maior==produtos[i].valorCompra){
        imprime_produto(produtos, i, fabricantes);
      }
  }
  
  printf("Estados com preco maior:\n");
    linha();
  for(i=0;i<quant_produt;i++){
    if(produtos[i].valorCompra==produt_maior){
printf("%s\n",fabricantes[produtos[i].fabricante].uf);
      linha();
    }
  }
  
}

void lista_estados_produto_barato(struct Produto produtos[], int quant_produt,struct Fabricante fabricantes[],int quant_fab){
  int produt_menor=2147483647, i = 0;

  for(i=0;i<quant_produt;i++){
    if(produtos[i].valorCompra<=produt_menor){
    produt_menor=produtos[i].valorCompra;
    }
  }
  printf("O(s) produto(s) mais caro(s)\n");
  for(i=0;i<quant_produt;i++){
      if(produt_menor==produtos[i].valorCompra){
        imprime_produto(produtos, i, fabricantes);
      }
  }
  
  printf("Estados com preco menor:\n");
    linha();
  for(i=0;i<quant_produt;i++){
    if(produtos[i].valorCompra==produt_menor){
printf("%s\n",fabricantes[produtos[i].fabricante].uf);
      linha();
    }
  }
  
}

void lista_ordem_crescente(struct Produto produtos[], int quant_produt, struct Fabricante fabricantes[], int quant_fab) {
    int ind_ord_cresc[100], val_ord_cresc[100], val_mais_alto, i, j, indice_anterior;

    for (i = 0; i < quant_produt; i++) {
        val_ord_cresc[i] = produtos[i].valorCompra;
        ind_ord_cresc[i] = i;
    }

    for (i = 0; i < quant_produt - 1; i++) {
        for (j = 0; j < quant_produt - 1; j++) {
            if (val_ord_cresc[j] > val_ord_cresc[j + 1]) {
                indice_anterior = ind_ord_cresc[j+1];
                ind_ord_cresc[j+1] = ind_ord_cresc[j];
                ind_ord_cresc[j] = indice_anterior;
                val_mais_alto = val_ord_cresc[j + 1];
                val_ord_cresc[j + 1] = val_ord_cresc[j];
                val_ord_cresc[j] = val_mais_alto;
            }
        }
    }

    for (j = 0; j < quant_produt; j++) {
        i=ind_ord_cresc[j];
        imprime_produto(produtos, i, fabricantes);
    }
}

void lista_lucro(struct Produto produtos[], int quant_produt, struct Fabricante fabricantes[], int quant_fab) {
    int ind_ord_cresc[100], i, j, indice_anterior;
  float val_ord_cresc[100], val_mais_alto;

    for (i = 0; i < quant_produt; i++) {
        val_ord_cresc[i] = produtos[i].valorLucro;
        ind_ord_cresc[i] = i;
    }

    for (i = 0; i < quant_produt - 1; i++) {
        for (j = 0; j < quant_produt - 1; j++) {
            if (val_ord_cresc[j] > val_ord_cresc[j + 1]) {
                indice_anterior = ind_ord_cresc[j+1];
                ind_ord_cresc[j+1] = ind_ord_cresc[j];
                ind_ord_cresc[j] = indice_anterior;
                val_mais_alto = val_ord_cresc[j + 1];
                val_ord_cresc[j + 1] = val_ord_cresc[j];
                val_ord_cresc[j] = val_mais_alto;
            }
        }
    }

    for (j = 0; j < quant_produt; j++) {
        i=ind_ord_cresc[j];
        imprime_produto(produtos, i, fabricantes);
    }
}

void lista_percentual_lucro(struct Produto produtos[], int quant_produt, struct Fabricante fabricantes[], int quant_fab) {
    int ind_ord_cresc[100], i, j, indice_anterior;
  float val_ord_cresc[100], val_mais_alto;

    for (i = 0; i < quant_produt; i++) {
        val_ord_cresc[i] = produtos[i].percentualLucro;
        ind_ord_cresc[i] = i;
    }

    for (i = 0; i < quant_produt - 1; i++) {
        for (j = 0; j < quant_produt - 1; j++) {
            if (val_ord_cresc[j] > val_ord_cresc[j + 1]) {
                indice_anterior = ind_ord_cresc[j+1];
                ind_ord_cresc[j+1] = ind_ord_cresc[j];
                ind_ord_cresc[j] = indice_anterior;
                val_mais_alto = val_ord_cresc[j + 1];
                val_ord_cresc[j + 1] = val_ord_cresc[j];
                val_ord_cresc[j] = val_mais_alto;
            }
        }
    }

    for (j = 0; j < quant_produt; j++) {
        i=ind_ord_cresc[j];
        imprime_produto(produtos, i, fabricantes);
    }
}


void imprime_produto(struct Produto produtos[], int i,struct Fabricante fabricantes[]){

    printf("|Descricao:%s|",produtos[i].descricao);
    printf("|Peso:%.2f|",produtos[i].peso);
    printf("|Valor de compra:R$%.2f|",produtos[i].valorCompra);
    printf("|Valor de venda:R$%.2f|",produtos[i].valorVenda);
    printf("|Lucro:R$%.2f|",produtos[i].valorLucro);
    printf("|Percentual de lucro:%.2f%%|\n",produtos[i].percentualLucro);
    printf("|Fabricante: %s|\n",fabricantes[produtos[i].fabricante].marca);
    linha();

}

void linha(){
  printf("----------------------------------------------------------------------------------------------------------------------------\n");
}
