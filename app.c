#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLIENTES 100
#define MAX_NOME 50

typedef struct {
    int codigo_cli;
    char nome_cli[MAX_NOME];
    char genero_cli;
    int idade_cli;
    float valor_ultima_compra;
    int total_compras;
    float ticket_medio;
    int cliente_potencial;
    int cupom_10;
    int cupom_5;
} Cliente;

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para verificar se o cliente tem potencial de compra
int verificaPotencial(Cliente cliente) {
    return (cliente.idade_cli >= 30 && cliente.idade_cli <= 45 &&
            cliente.total_compras > 10 && cliente.ticket_medio > 50.0);
}

// Função para exibir informações de um cliente
void exibirCliente(Cliente cliente) {
    printf("Codigo: %d, Nome: %s, Genero: %c, Idade: %d\n", 
           cliente.codigo_cli, cliente.nome_cli, cliente.genero_cli, cliente.idade_cli);
    printf("Ultima Compra: %.2f, Total Compras: %d, Ticket Medio: %.2f\n", 
           cliente.valor_ultima_compra, cliente.total_compras, cliente.ticket_medio);
    printf("Potencial: %s, Cupom 10%%: %s, Cupom 5%%: %s\n\n",
           cliente.cliente_potencial ? "Sim" : "Não",
           cliente.cupom_10 ? "Sim" : "Não",
           cliente.cupom_5 ? "Sim" : "Não");
}

// Função para exibir todos os clientes
void mostrarClientes(Cliente clientes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        exibirCliente(clientes[i]);
    }
}

// Função para exibir clientes em potencial
void mostrarClientesPotencial(Cliente clientes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (clientes[i].cliente_potencial) {
            exibirCliente(clientes[i]);
        }
    }
}

// Função para adicionar um novo cliente
void adicionarCliente(Cliente clientes[], int *tamanho) {
    if (*tamanho >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novoCliente;
    
    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.codigo_cli);

    printf("Digite o nome do cliente: ");
    limparBuffer();
    fgets(novoCliente.nome_cli, MAX_NOME, stdin);
    novoCliente.nome_cli[strcspn(novoCliente.nome_cli, "\n")] = '\0'; // Remove o '\n'

    printf("Digite o gênero do cliente (M/F): ");
    scanf(" %c", &novoCliente.genero_cli);

    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente.idade_cli);

    printf("Digite o valor da última compra: ");
    scanf("%f", &novoCliente.valor_ultima_compra);

    printf("Digite o total de compras: ");
    scanf("%d", &novoCliente.total_compras);

    printf("Digite o ticket médio: ");
    scanf("%f", &novoCliente.ticket_medio);

    // Determina se o cliente tem potencial e atribui os cupons adequados
    novoCliente.cliente_potencial = verificaPotencial(novoCliente);
    novoCliente.cupom_10 = novoCliente.cliente_potencial ? 1 : 0;
    novoCliente.cupom_5 = !novoCliente.cliente_potencial ? 1 : 0;

    clientes[*tamanho] = novoCliente;
    (*tamanho)++;
    printf("Cliente adicionado com sucesso!\n");
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int tamanho = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir novas linhas\n");
        printf("2. Mostrar todos os clientes em potencial\n");
        printf("3. Mostrar todos os clientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(clientes, &tamanho);
                break;
            case 2:
                mostrarClientesPotencial(clientes, tamanho);
                break;
            case 3:
                mostrarClientes(clientes, tamanho);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}


    return 0;
}
//Lkzam
