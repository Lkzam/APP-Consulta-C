// Codigo por Luca Mazieiro - Lkzam
#include <stdio.h>
#include <string.h>


//Estruturar os dados dos clientes: Utilizar uma struct para armazenar as informações de cada cliente.
//Criar funções para validação: Implementar funções que verificam se o cliente tem potencial de compra com base nas regras fornecidas.
//Interatividade: Criar um menu interativo para que o usuário possa adicionar novos registros, visualizar clientes em potencial e visualizar todos os clientes.
typedef struct {
    int codigo_cli;
    char nome_cli[50];
    char genero_cli;
    int idade_cli;
    float valor_ultima_compra;
    int total_compras;
    float ticket_medio;
    int cliente_potencial;
    int cupom_10;
    int cupom_5;
} Cliente;

// Função para verificar se o cliente tem potencial de compra
int verificaPotencial(Cliente cliente) {
    if (cliente.idade_cli >= 30 && cliente.idade_cli <= 45 &&
        cliente.total_compras > 10 && cliente.ticket_medio > 50.0) {
        return 1;
    }
    return 0;
}

// Função para exibir todos os clientes
void mostrarClientes(Cliente clientes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Cliente: %s, Potencial: %s\n", clientes[i].nome_cli, clientes[i].cliente_potencial ? "Sim" : "Não");
    }
}

// Função para exibir clientes em potencial
void mostrarClientesPotencial(Cliente clientes[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (clientes[i].cliente_potencial) {
            printf("Cliente: %s, Potencial: Sim\n", clientes[i].nome_cli);
        }
    }
}

// Função para adicionar um novo cliente
void adicionarCliente(Cliente clientes[], int *tamanho) {
    Cliente novoCliente;
    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.codigo_cli);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]%*c", novoCliente.nome_cli);
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

    novoCliente.cliente_potencial = verificaPotencial(novoCliente);
    novoCliente.cupom_10 = novoCliente.cliente_potencial ? 1 : 0;
    novoCliente.cupom_5 = !novoCliente.cliente_potencial ? 1 : 0;

    clientes[*tamanho] = novoCliente;
    (*tamanho)++;
}

int main() {
    Cliente clientes[100];
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
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}
//Lkzam