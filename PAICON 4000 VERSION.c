//Projeto desenvolvido por Talles Pellense

//Declaração de bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
#include <windows.h>

#define quant_valores 200 //Definição de quantos novos valores o usuário pode inserir na função que escolher

//Estrutura contém as variáveis de decisão que usuário ira utilizar
struct Decisao{

    int periodo_analise; //Usuário define período da análise
    int tipo_analise; //Usuário define tipo da análise

}Decisao;

//Estrutura para acumular os valores digitados pelo usuário
struct Empresa{

    float valor[quant_valores]; //Variável referente aos valores que o usuário insere de acordo com o período e tipo de análise

}Empresa;

//Estrutura que contém os dados totais de cada função
struct Totais{

    float total_custo;
    float total_perdas;
    float total_vendas;
    float total_lucro;

}Totais[quant_valores];

int rep = 0; //Variável utilizada por todo o sistema para controlar onde serão armazenados os dados que o Usuário digitar

//Declaração das Funções
void extrato_total();
void vendas();
void lucro();
void perdas();
void custos();
void textcolor();

//Função principal
int main (void){ 
setlocale(LC_ALL, "Portuguese_Brazil"); //Define a linguagem do programa para PT-BR

int retorno = -1; //Variável utilizada pra validar se o scanf esta recebendo uma letra ou um numero

    for (int i = 0; i < quant_valores; i++){
        //Interface
        printf("\t\t\t\t\t\t        PAICON\n");
        printf("\t\t\t\tSistema de Gerenciamento Financeiro para Painéis Solares\n\n");

        textcolor(8);
        printf(" Olá, seja bem-vindo(a)! A seguir, confira nossas opções de análise:\n\n");

        textcolor(3);
        printf(" (1) Análise de Vendas;\n");
        printf(" (2) Análise de Lucro;\n");
        printf(" (3) Análise de Custos;\n");
        printf(" (4) Análise de Perdas;\n");
        printf(" (5) Extrato Total.\n\n");

        do{
            textcolor(8);
            printf(" Digite o número da função que deseja realizar: ");
            retorno = scanf(" %d", &Decisao.tipo_analise); //Usuário escolhe a função que deseja rodar
            getchar();

                if (Decisao.tipo_analise == 1){ //Caso Usuário escolha '1', puxa função 'vendas'
                    vendas();
                }

                else if (Decisao.tipo_analise == 2){ //Caso Usuário escolha '2', puxa função 'lucro'
                    lucro();
                }

                else if (Decisao.tipo_analise == 3){ //Caso Usuário escolha '3', puxa função 'custos'
                    custos();
                }

                else if (Decisao.tipo_analise == 4){ //Caso Usuário escolha '4', puxa função 'perdas'
                    perdas();
                }

                else if (Decisao.tipo_analise == 5){ //Caso Usuário escolha '5', puxa função 'extrato_total'
                    extrato_total();
                }

        }while(Decisao.tipo_analise < 1 || Decisao.tipo_analise > 5 || retorno == 0); //Validação

        int continua; //Variável armazena escolha do usuário

        do {
            printf("\n\n Gostaria de continuar a análise ?\n");
            textcolor(2);
            printf(" (1) para SIM (volta para o menu)\n");

            textcolor(4);
            printf(" (2) para NÃO (fecha o sistema): ");

            textcolor(7);
            retorno = scanf("%d", &continua); //Usuário escolhe se continua ou não a análise

                if (continua == 1){
                    system("cls");
                    textcolor(2);
                    printf("Programa reiniciando em ");
                        for (int i = 1; i < 4; i++){ //A cada 1 segundo aparecem 3 pontinhos
                            printf("%d...", i);
                            sleep(1);
                        }
                    system("cls");
                }
                    else if (continua == 2){
                        printf("\n Agradecemos por usar nosso sistema, nos vemos mais tarde!\n\n");
                        return 0;
                    }
        }while (continua < 1 || continua > 2 || retorno == 0); //Validação
    }//Fim for
}//Fim função main

//Função possibilita o usuário escolher o período que deseja realizar a analise financeira (semanal, mensal ou anual)
void periodo(){

int retorno1 = -1; //Variável utilizada pra validar se o scanf esta recebendo uma letra ou um numero

do {
    printf("\n Qual o período da análise ?\n");
    textcolor(3);
    printf(" (1) para SEMANAL (insere 7 valores referentes aos 7 dias da semana);");

    textcolor(9);
    printf("\n (2) para MENSAL (insere 4 valores referentes as 4 semanas do mês);");

    textcolor(6);
    printf("\n (3) para ANUAL (insere 12 valores referentes a cada mês do ano).\n");

    textcolor(7);
    retorno1 = scanf(" %d", &Decisao.periodo_analise);

    system("cls");
}while (Decisao.periodo_analise < 1 || Decisao.periodo_analise > 3 || retorno1 == 0); //Validação

        if (Decisao.periodo_analise == 1){
            textcolor(3);
            printf(" Insira um valor para cada dia da semana.\n");

                    for (int i = 0; i <= 6; i++){ //for repete 7 vezes, referente aos 7 dias da semana
                        printf(" %d° Dia: ", i+1);
                            do{
                                scanf("%f", &Empresa.valor[i]); //Armazena o valor que o Usuário digitar na posição 'i' do vetor 'valor' da struct 'Empresa'
                            }while (Empresa.valor[i] < 0); //Validação
                    }//Fim for
            textcolor(7);
        }//if
            else if (Decisao.periodo_analise == 2){
                textcolor(9);
                printf("Insira um valor para cada semana do mês.\n");

                    for (int i = 0; i <= 3; i++){ //for repete 4 vezes, referente às 4 semanas do mês
                        printf(" %dº Semana: ", i+1);
                            do{
                                scanf("%f", &Empresa.valor[i]);
                            }while (Empresa.valor[i] < 0); //Validação
                    }//Fim for
                textcolor(7);
            }//else if
                else if (Decisao.periodo_analise == 3){
                    textcolor(6);
                    printf("Insira um valor para cada mês do ano.\n");
                        
                        for (int i = 0; i <= 11; i++){ //for repete 12 vezes, referente aos 12 meses do ano
                            printf(" %d° Mês: ", i+1);
                                do{
                                    scanf("%f", &Empresa.valor[i]);
                                }while (Empresa.valor[i] < 0); //Validação
                        }//Fim for
                    textcolor(7);
                }//else if
                rep++; //Ao final da inserção dos valores, a variável rep acumula mais uma vez
}//Fim função período

//Função mostra lucro, vendas, perdas e custos, todos juntos (dependendo do período de análise)
void extrato_total(){

  float cust_perdas;

    vendas();
    custos();
    perdas();
    system("cls");

        cust_perdas = Totais[1].total_custo + Totais[2].total_perdas; //Conta para juntar o total de custos com o total de perdas, ja que os dois são débitos
        Totais[3].total_lucro = Totais[0].total_vendas - cust_perdas; //Conta que define o lucro total, subtraindo das vendas o total de débitos
    
        printf("\n-----EXTRATO TOTAL------\n");
        textcolor(2); printf("\n Vendas Totais: %.2f", Totais[0].total_vendas);

        textcolor(3); printf("\n Custos Totais: %.2f", Totais[1].total_custo);

        textcolor(4); printf("\n Perdas Totais: %.2f", Totais[2].total_perdas);

        textcolor(6); printf("\n Lucro Total: %.2f\n\n", Totais[3].total_lucro);

        textcolor(7);
}//Fim função extrato_total

//Função mostra as vendas que o usuário digitou e o total de vendas (dependendo do período de análise)
void vendas(){

    textcolor(15); printf("\n A seguir, escolha o periodo e digite os valores se referindo as "); textcolor(2); printf("vendas.\n");
    
    textcolor(7);
    periodo();

        if (Decisao.periodo_analise == 1){ //Se usuário escolher '1', o for se repete o tanto de dias da semana
            
            for(int j=0; j<7; j++){
                Totais[rep-1].total_vendas += Empresa.valor[j];
            }

            textcolor(2); printf(" O total de vendas no período de uma semana foi de: R$%.2f\n", Totais[rep-1].total_vendas);
            textcolor(7);
        }
            else if (Decisao.periodo_analise == 2){ //Se usuário escolher '2', o for se repete o tanto de semanas de um mês
                    
                    for(int j=0; j<4; j++){
                        Totais[rep-1].total_vendas += Empresa.valor[j];
                    }

                    textcolor(2); printf(" O total de vendas no período de um mês foi de: R$%.2f\n", Totais[rep-1].total_vendas);
                    textcolor(7);
            }
                else if (Decisao.periodo_analise == 3){ //Se o usuário escolher '3', o for se repete o tanto de meses de um ano
                    
                    for(int j=0; j<12; j++){
                        Totais[rep-1].total_vendas += Empresa.valor[j];
                    }

                    textcolor(2); printf(" O total de vendas no período de um ano foi de: R$%.2f\n", Totais[rep-1].total_vendas);
                    textcolor(7);
                }

}//Fim função vendas

//Função mostra apenas o lucro (dependendo do período de análise)
void lucro(){

    float cust_perd;

    perdas();
    vendas();
    custos();

    cust_perd = Totais[0].total_perdas + Totais[2].total_custo; //Conta que pega o total de perdas e soma com o total de custos
    Totais[0].total_lucro = Totais[1].total_vendas - cust_perd; //Conta que pega o total de vendas e diminui pela soma do total de perdas e custos

     
    textcolor(2); printf("\n Total de vendas: %.2f\n", Totais[1].total_vendas);

    textcolor(4); printf(" Total de custos: %.2f\n", cust_perd);

    textcolor(6); printf(" Lucro total: %.2f\n", Totais[0].total_lucro);
    textcolor(7);

}//Fim função lucro

//Função mostra as perdas (dependendo do período de análise)
void perdas(){
    
    textcolor(15); printf("\n A seguir, escolha o periodo e digite os valores se referindo as "); textcolor(4); printf("perdas.\n");
    textcolor(7);

        periodo();

        if (Decisao.periodo_analise == 1){ //Se usuário escolher '1', o for se repete o tanto de dias da semana
            
            for(int j=0; j<7; j++){
                Totais[rep-1].total_perdas += Empresa.valor[j];
            }
            textcolor(4); printf(" O total de perdas no período de uma semana foi de: R$%.2f\n", Totais[rep-1].total_perdas); textcolor(7);
        }
            else if (Decisao.periodo_analise == 2){ //Se usuário escolher '2', o for se repete o tanto de semanas de um mês
                
                for(int j=0; j<4; j++){
                    Totais[rep-1].total_perdas += Empresa.valor[j];
                }
                textcolor(4); printf(" O total de perdas no período de um mês foi de: R$%.2f\n", Totais[rep-1].total_perdas); textcolor(7);
            }
                else if (Decisao.periodo_analise == 3){ //Se o usuário escolher '3', o for se repete o tanto de meses de um ano
                    
                    for(int j=0; j<12; j++){
                        Totais[rep-1].total_perdas += Empresa.valor[j];
                    }
                    textcolor(4); printf(" O total de perdas no período de um ano foi de: R$%.2f\n", Totais[rep-1].total_perdas); textcolor(7);
                }

}//Fim função perdas

//Função para armazenar e calcular os custos totais
void custos(){
    
    textcolor(15); printf("\n A seguir, escolha o periodo e digite os valores se referindo aos "); textcolor(6); printf("custos.\n");
    textcolor(7);

        periodo();

            if (Decisao.periodo_analise == 1){ //Se usuário escolher '1', o for se repete o tanto de dias da semana
            
                for(int j=0; j<7; j++){
                    Totais[rep-1].total_custo += Empresa.valor[j];
                }
            textcolor(6); printf(" O total de custos no período de uma semana foi de: R$%.2f\n", Totais[rep-1].total_custo);
        }
            else if (Decisao.periodo_analise == 2){ //Se usuário escolher '2', o for se repete o tanto de semanas de um mês
                
                for(int j=0; j<4; j++){
                    Totais[rep-1].total_custo += Empresa.valor[j];
                }
                textcolor(6); printf(" O total de custos no período de um mês foi de: R$%.2f\n", Totais[rep-1].total_custo);
            }
                else if (Decisao.periodo_analise == 3){ //Se o usuário escolher '3', o for se repete o tanto de meses de um ano
                    
                    for(int j=0; j<12; j++){
                        Totais[rep-1].total_custo += Empresa.valor[j];
                    }
                    textcolor(6); printf(" O total de custos no período de um ano foi de: R$%.2f\n", Totais[rep-1].total_custo);
                }
}//Fim função custos

//Função para troca de cor dos textos
void textcolor(int color_name){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);

}//Fim função textcolor