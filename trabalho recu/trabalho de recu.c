#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct {
    char proprietario[50];
    char combustivel[10];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[8];
} Veiculo;
typedef struct Node {
    Veiculo veiculo;
    struct Node* next;
} Node;
void listarProprietariosAnoDiesel(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->veiculo.ano >= 2010 && strcmp(current->veiculo.combustivel, "diesel") == 0) {
            printf("Proprietario: %s\n", current->veiculo.proprietario);
        }
        current = current->next;
    }
}
void listarPlacasJ(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->veiculo.placa[0] == 'J' &&
            (current->veiculo.placa[6] == '0' || current->veiculo.placa[6] == '2' ||
             current->veiculo.placa[6] == '4' || current->veiculo.placa[6] == '7')) {
            printf("Placa: %s, Proprietario: %s\n", current->veiculo.placa, current->veiculo.proprietario);
        }
        current = current->next;
    }
}
void listarModeloCorVogal(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (strchr("aeiouAEIOU", current->veiculo.placa[1]) != NULL) {
            int somaNumeros = 0;
            for (int i = 0; i < 7; i++) {
                if (isdigit(current->veiculo.placa[i])) {
                    somaNumeros += current->veiculo.placa[i] - '0';
                }
            }
            if (somaNumeros % 2 == 0) {
                printf("Modelo: %s, Cor: %s\n", current->veiculo.modelo, current->veiculo.cor);
            }
        }
        current = current->next;
    }
}

void trocarProprietario(Node** head, const char* chassi, const char* novoProprietario) {
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->veiculo.chassi, chassi) == 0 &&
            strpbrk(current->veiculo.placa, "0") == NULL) {
            strcpy(current->veiculo.proprietario, novoProprietario);
            return;
        }
        current = current->next;
    }
}

void imprimirVeiculo(const Veiculo* veiculo) {
    printf("Proprietario: %s, Combustivel: %s, Modelo: %s, Cor: %s, Ano: %d, Placa: %s\n",
           veiculo->proprietario, veiculo->combustivel, veiculo->modelo, veiculo->cor,
           veiculo->ano, veiculo->placa);
}

void adicionarVeiculo(Node** head, const Veiculo* veiculo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->veiculo = *veiculo;
    newNode->next = *head;
    *head = newNode;
}
void liberarLista(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* listaVeiculos = NULL;

    Veiculo veiculo1 = ("Proprietario1", "gasolina", "ModeloA",)}