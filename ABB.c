/*
* Pedro Lucas da Costa Vidal 
* Aluno do curso de Ciência da Computação, pela Universidade Federal do Ceará - Campus Russas
* Semestre 2020.1
*/
// IMPLEMENTAÇÃO DE UMA ÁRVORE BINÁRIA DE BUSCA

#include <stdio.h>        // Bibliotecas necessárias para o código  
#include <stdlib.h>

// ESTRUTURA DA ÁRVORE
typedef struct arvore {
    int ID;
    struct arvore *esquerda_arvore; // Ponteiro para a esquerda
    struct arvore *direita_arvore;  // Ponteiro para a direita
} ABB; // "ABB" é o nome do tipo a variavel

ABB *Raiz_Arvore = NULL;    // Ponteiro RAIZ da árvore
int Quantidade_Nos_Arvore;  // Variável para contar quantos nós a árvore possui

// ASSINATURA DAS FUNÇÕES NO TOPO DO CÓDIGO
////////////////////////////////////////////////////////////
ABB *Buscar_Arvore   (ABB *Pointer_Tree, int ID_Value);   // BUSCA
ABB *Remover_Arvore  (ABB *Pointer_Tree, int ID_Value);   // REMOÇÃO
int Adicionar_Arvore (int ID_Value);                      // ADIÇÃO
////////////////////////////////////////////////////////////

////////////////// FUNÇÕES DE PERCURSO ///////////////////
void InOrdem_Arvore  (ABB *Pointer_Tree);               // IN-ORDEM 
void PreOrdem_Arvore (ABB *Pointer_Tree);               // PRÉ-ORDEM
void PosOrdem_Arvore (ABB *Pointer_Tree);               // PÓS-ORDEM
//////////////////////////////////////////////////////////

int main () {   // FUNÇÃO PRINCIPAL
    int opcao_menu;
    int valor_id;
    char opcao_confirmacao;
    ABB *P_AUX;
    Quantidade_Nos_Arvore = 0; // Quantidade começa inicialmente em zero

    while (1) {     // LAÇO "INFINITO" (SEMPRE VERDADE, ATÉ O USUÁRIO DECIDIR SAIR)
        opcao_menu = 0;
        // MENU DO PROGRAMA
        puts ("  ________________________________  ");
        puts (" /                                \\");
        puts (" |        MENU DE ESCOLHAS        | ");
        puts (" :                                : ");
        puts (" |          [1] INSERIR           | ");
        puts (" |          [2] REMOVER           | ");
        puts (" |          [3] MOSTRAR           | ");
        puts (" |          [4] SAIR              | ");
        puts (" :                                : ");
        puts (" |                                | ");
        puts (" \\________________________________/");
        printf ("\nESCOLHA: ");
        scanf ("%d", &opcao_menu);
        fflush (stdin);
        switch (opcao_menu) {
        case 1:
            printf ("\nDigite o ID do no que sera adicionado na ABB.\n");
            printf ("ID: ");
            scanf ("%d", &valor_id);
            if (Adicionar_Arvore (valor_id) == 0) {
                printf ("\nRETORNO: O NO COM ID DE NUMERO %d FOI ADICIONADO COM SUCESSO NA ARVORE!", valor_id);
                Quantidade_Nos_Arvore++; // Incrementando a quantidade de nós
            }else printf ("\nRETORNO: OPERACAO DE ADICAO OBTEVE PROBLEMAS!");
            printf ("\n\nPRESSIONE ENTER PARA CONTINUAR . . .");
            fflush (stdin);
            getchar ();
            system ("cls");
            break;
        case 2:
            printf ("\nDigite o ID do no que sera removido da ABB.\n");
            printf ("ID: ");
            scanf ("%d", &valor_id);
            P_AUX = Buscar_Arvore (Raiz_Arvore, valor_id);
            printf ("\nRESULTADO DA BUSCA: ");
            if (P_AUX != NULL && valor_id == P_AUX -> ID) {
                printf ("ID ENCONTRADO NA ARVORE.\n");
            }else {
                if (Raiz_Arvore == NULL) {
                    printf ("\nAVISO: A arvore se encontra vazia! Portanto, remocao impossibilitada!\n");
                }else { 
                    printf ("\nAVISO: ID digitado nao existe na arvore! Tente novamente!\n");
                }
                printf ("\nRETORNO: OPERACAO DE REMOCAO OBTEVE FALHA!\n");
                printf ("\n\nPRESSIONE ENTER PARA CONTINUAR . . .");
                fflush (stdin);
                getchar ();
                system ("cls");
                break;
            }
            printf ("\nCONFIRMACAO: O no com ID de numero %d sera removido da ABB.\n", valor_id);
            printf ("Deseja continuar? O processo e irreversivel. \n(S/N): ");
            fflush (stdin);
            scanf ("%c", &opcao_confirmacao);
            if (opcao_confirmacao == 'S' || opcao_confirmacao == 's') {
                //P_AUX = Buscar_Arvore (Raiz_Arvore, valor_id);
                P_AUX = Remover_Arvore (Raiz_Arvore, valor_id);
                if (P_AUX != NULL || Quantidade_Nos_Arvore == 1) {
                    printf ("\nRETORNO: OPERACAO DE REMOCAO REALIZADA COM SUCESSO!");
                    Quantidade_Nos_Arvore--;    // Decrementando a quantidade de nós após a remoção
                }else {
                    printf ("\nRETORNO: OPERACAO DE REMOCAO OBTEVE FALHA!");
                } 
            }else {
                printf ("\nRETORNO: OPERACAO DE REMOCAO CANCELADA!");
            }
            printf ("\n\nPRESSIONE ENTER PARA CONTINUAR . . .");
            fflush (stdin);
            getchar ();
            system ("cls");
            break;
        case 3:
            if (Quantidade_Nos_Arvore == 0) {
                printf ("\nAVISO: Arvore nao possui elementos! Adicione-os antes!\n");
            }else {
                printf ("\nIN-ORDEM: ");
                InOrdem_Arvore (Raiz_Arvore);
                printf ("\n");
                printf ("\nPRE-ORDEM: ");
                PreOrdem_Arvore (Raiz_Arvore);
                printf ("\n");
                printf ("\nPOS-ORDEM: ");
                PosOrdem_Arvore (Raiz_Arvore);
                printf ("\n");
                printf ("\nQuantidade de nos na ABB: %d.", Quantidade_Nos_Arvore);
            }
            printf ("\n\nPRESSIONE ENTER PARA CONTINUAR . . .");
            fflush (stdin);
            getchar ();
            system ("cls");
            break;
        case 4:
            printf ("Tem certeza que deseja sair do programa? (S/N): ");
            fflush (stdin);
            scanf ("%c", &opcao_confirmacao);
            if (opcao_confirmacao == 'S' || opcao_confirmacao == 's') {
                system ("cls");
                printf ("\nOBRIGADO POR UTILIZAR MEU PROGRAMA! :D\n");
                exit (1); // Encerrando o programa
            }
            system ("cls");
            break;
        default:
            printf ("\nAVISO: OPCAO DE ESCOLHA INVALIDA\n");
            printf ("\n\nPRESSIONE ENTER PARA CONTINUAR . . .");
            fflush (stdin);
            getchar ();
            system ("cls");
            break;
        }
    }
    return 0;
}

// FUNÇÕES DO PROGRAMA
   
    // FUNÇÃO DE BUSCA
ABB *Buscar_Arvore (ABB *Pointer_Tree, int ID_Value) {
    if (Raiz_Arvore == NULL) {      // CASO ONDE A ÁRVORE ESTÁ VAZIA
        return NULL;
    }else if (ID_Value == Pointer_Tree -> ID) { // VALOR ENCONTRADO NA ÁRVORE
        return Pointer_Tree;
    }else if (ID_Value < Pointer_Tree -> ID) { // VALOR ESTÁ NA SUB-ÁRVORE ESQUERDA
       if (Pointer_Tree -> esquerda_arvore == NULL) {
            return Pointer_Tree;
        }else {
            return Buscar_Arvore (Pointer_Tree -> esquerda_arvore, ID_Value);
        }
    }else {
       if (Pointer_Tree -> direita_arvore == NULL) { // VALOR ESTÁ NA SUB-ÁRVORE DIREITA
            return Pointer_Tree;
        }else {
            return Buscar_Arvore (Pointer_Tree -> direita_arvore, ID_Value);
        }
    }
}
    // FIM DA FUNÇÃO DE BUSCA
    
    //FUNÇÃO DE ADICIONAR NOVO NÓ NA ÁRVORE
int Adicionar_Arvore (int ID_Value) {
    ABB *Pointer_Tree = Buscar_Arvore (Raiz_Arvore, ID_Value); //Ponteiro que receberá a posição correta da árvora após a busca
    if (Raiz_Arvore != NULL && ID_Value == Pointer_Tree -> ID) { // Elemento não será adicionado, pois já está na árvore
        printf ("\nAVISO: O ID digitado ja se encontra presente na Arvore. Tente novamente!\n");
        return 1;     // RETORNANDO PARA A MAIN
    }else if (Pointer_Tree == NULL || ID_Value != Pointer_Tree -> ID) { // Caso válido para a adição do novo nó
        ABB *NOVO_NO = (ABB*) malloc (sizeof (ABB));    // Alocando espaço para o novo nó
        // TRATAMENTO DE ERRO NA ALOCAÇÃO DA MEMÓRIA
        if (NOVO_NO == NULL) {
            system ("cls");
            printf ("\nERRO NA ALOCACAO DE MEMORIA. O PROGRAMA SERA ENCERRADO!\n");
            exit (1); // Força encerramento
        }
        
        NOVO_NO -> esquerda_arvore = NULL;  // Definindo seus ponteiros para nulo
        NOVO_NO -> direita_arvore  = NULL;
        NOVO_NO -> ID = ID_Value;   // Nó recebe valor do ID passado por parâmetro

        if (Pointer_Tree == NULL) {     // Caso o ponteiro aponte para nulo, quer dizer que a árvore está vazia
            Raiz_Arvore = NOVO_NO;      // Raiz é definida
        }else if (ID_Value < Pointer_Tree -> ID) {      // Caso seja menor, novo elemento será adicionado na "esquerda"
            Pointer_Tree -> esquerda_arvore = NOVO_NO;      // Inserindo o nó
        }else {                                         // Caso seja maior, será adicionado à direita                                                
            Pointer_Tree -> direita_arvore  = NOVO_NO;      // Inserindo o nó
        }
    }
    return 0;
} 
    // FIM DA FUNÇÃO DE ADIÇÃO

    // FUNÇÃO DE REMOÇÃO DA ÁRVORE
ABB *Remover_Arvore (ABB *Pointer_Tree, int ID_Value) {
    if (Raiz_Arvore == NULL) {      // ÁRVORE VAZIA
        return NULL;     // RETORNANDO NULO
    }else if (ID_Value < Pointer_Tree -> ID) {
        Pointer_Tree -> esquerda_arvore = Remover_Arvore (Pointer_Tree -> esquerda_arvore, ID_Value);
    }else if (ID_Value > Pointer_Tree -> ID) {
        Pointer_Tree -> direita_arvore  = Remover_Arvore (Pointer_Tree -> direita_arvore, ID_Value);
    }else {
        if (Pointer_Tree -> esquerda_arvore == NULL && Pointer_Tree -> direita_arvore == NULL) { //CASO ONDE O NÓ É UMA FOLHA (Sem filhos)
            if (Pointer_Tree == Raiz_Arvore) { // Comparação de ponteiros (se eles apontam para o mesmo endereço)
                Raiz_Arvore = NULL;
            } 
            free (Pointer_Tree);
            return NULL;
        }else if (Pointer_Tree -> esquerda_arvore != NULL && Pointer_Tree -> direita_arvore == NULL) { // SOMENTE FILHO À ESQUERDA
            ABB *NO_AUXILIAR = Pointer_Tree;
            if (Pointer_Tree == Raiz_Arvore) { // TRATAMENTO PARA QUANDO O PONTEIRO É A RAIZ
                Raiz_Arvore = Pointer_Tree -> esquerda_arvore;
            }
            Pointer_Tree = Pointer_Tree -> esquerda_arvore;
            free (NO_AUXILIAR);
        }else if (Pointer_Tree -> esquerda_arvore == NULL && Pointer_Tree -> direita_arvore != NULL) { // SOMENTE FILHO À DIREITA
            ABB *NO_AUXILIAR = Pointer_Tree;
            if (Pointer_Tree == Raiz_Arvore) { // TRATAMENTO PARA QUANDO O PONTEIRO É A RAIZ
                Raiz_Arvore = Pointer_Tree -> direita_arvore;
            }
            Pointer_Tree = Pointer_Tree -> direita_arvore;
            free (NO_AUXILIAR);
        }else {     // CASO ONDE O NÓ POSSUI DOIS FILHOS (TAMBÉM INCLUI A RAIZ DA ÁRVORE)
            // UTILIZANDO O MÉTODO DE BUSCAR O MAIOR ELEMENTO DA SUB-ÁRVORE DA ESQUERDA
            ABB *NO_AUXILIAR = Pointer_Tree -> esquerda_arvore; // "-> esquerda_arvore" porque queremos a sub-árvore localizada à esquerda 
            int ID_Aux; // variável para guardar o valor de NO_AUXLIAR e posteriormente realizar a troca
            while (NO_AUXILIAR -> direita_arvore != NULL) {
                NO_AUXILIAR = NO_AUXILIAR -> direita_arvore; // "CAMINHANDO" ATÉ O MAIOR ELEMENTO
            }
            ID_Aux = NO_AUXILIAR -> ID;
            Pointer_Tree -> esquerda_arvore = Remover_Arvore (Pointer_Tree -> esquerda_arvore, ID_Aux);
            Pointer_Tree -> ID = ID_Aux;
        }
    }
    printf ("\nChegou aqui 2\n");
    return Pointer_Tree;
}
    // FIM DA FUNÇÃO DE REMOÇÃO
    
    // PROCEDIMENTOS DE PERCURSO NA ÁRVORE
        
        //IN-ORDEM
void InOrdem_Arvore (ABB *Pointer_Tree) {
    if (Pointer_Tree -> esquerda_arvore != NULL) {
        InOrdem_Arvore (Pointer_Tree -> esquerda_arvore);
    }
    printf ("|%d| ", Pointer_Tree -> ID);
    if (Pointer_Tree -> direita_arvore != NULL) {
        InOrdem_Arvore (Pointer_Tree -> direita_arvore);
     }
}

        //PRE-ORDEM
void PreOrdem_Arvore (ABB *Pointer_Tree) {
    printf ("|%d| ", Pointer_Tree -> ID);
    if (Pointer_Tree -> esquerda_arvore != NULL) {
         PreOrdem_Arvore (Pointer_Tree -> esquerda_arvore);
    }
    if (Pointer_Tree -> direita_arvore != NULL) {
        PreOrdem_Arvore (Pointer_Tree -> direita_arvore);
    }
}

        //POS-ORDEM
void PosOrdem_Arvore (ABB *Pointer_Tree) {
    if (Pointer_Tree -> esquerda_arvore != NULL) {
        PosOrdem_Arvore (Pointer_Tree -> esquerda_arvore);
    }
    if (Pointer_Tree -> direita_arvore != NULL) {
        PosOrdem_Arvore (Pointer_Tree -> direita_arvore);
    }
    printf ("|%d| ", Pointer_Tree -> ID);
}
    //FIM DA PARTE DOS PROCEDIMENTOS DE PERCURSO

// FIM DA PARTE DAS FUNÇÕES DO CÓDIGO