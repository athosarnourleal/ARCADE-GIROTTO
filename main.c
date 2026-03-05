#include <stdio.h>
#include <stdlib.h>


void perguntasERespostas() {
    char r;
    int acertos = 0;
    printf("----Perguntas e Respostas----\n");
    printf("selecione as alternativas corretas e veja seu resultado! \n\n");

    printf("##Pergunta 1!\n");//--------------------------------1

    printf("quantos digitos existem de pi?\n");

    printf("a) 3.14 \n");
    printf("b) 3 \n");
    printf("c) infinitos \n");
    printf("d) 109.267.901 \n");
    printf("escolha uma alternativa: ");
    scanf("%c",&r);
    scanf("%c",&r);// botei 2 pois o primeiro não estava funcionando por algum motivo?

    if (r == 'c') {
        printf("ACERTOU! \n");
        acertos++;
    } else {
        printf("ERROU! \n");
        printf("a alternativa certa era c), não %c) \n",r);
    }

    printf("\n");

    printf("##Pergunta 2!\n");//--------------------------------2

    printf("Qual é a capital do uruguai? \n");

    printf("a) havanna \n");
    printf("b) montevidéu \n");
    printf("c) tenochtlan \n");
    printf("d) el salvador \n");
    scanf("%c",&r);
    scanf("%c",&r);

    if (r == 'b') {
        printf("ACERTOU! \n");
        acertos++;
    } else {
        printf("ERROU! \n");
        printf("a alternativa certa era b), não %c) \n",r);
    }

    printf("\n");

    printf("##Pergunta 3 \n");//--------------------------------3

    printf("que ano foi decretada a lei aurea? \n");

    printf("a) 1888 \n");
    printf("b) 1980 \n");
    printf("c) 1790 \n");
    printf("d) 1816 \n");
    scanf("%c",&r);
    scanf("%c",&r);

    if (r == 'a') {
        printf("ACERTOU! \n");
        acertos++;
    } else {
        printf("ERROU! \n");
        printf("a alternativa certa era a), não %c) \n",r);
    }
    printf("\n");
    printf("##Pergunta 4 \n");//--------------------------------4

    printf("qual a soma dos angulos internos de um triangulo obtusangulo? \n");

    printf("a) 135 \n");
    printf("b) 270 \n");
    printf("c) 360 \n");
    printf("d) 180 \n");
    scanf("%c",&r);
    scanf("%c",&r);

    if (r == 'd') {
        printf("ACERTOU! \n");
        acertos++;
    } else {
        printf("ERROU! \n");
        printf("a alternativa certa era d), não %c) \n",r);
    }
    printf("\n");

    printf("##Pergunta 5 \n");//--------------------------------5

    printf("de quantos digitos é formado o CPF brasileiro? \n");
    printf("a) 10 \n");
    printf("b) 11 \n");
    printf("c) 12 \n");
    printf("d) 9 \n");
    scanf("%c",&r);
    scanf("%c",&r);

    if (r == 'b') {
        printf("ACERTOU! \n");
        acertos++;
    } else {
        printf("ERROU! \n");
        printf("a alternativa certa era b), não %c) \n",r);
    }
    printf("\n");

    printf("Fim do jogo! \n você acertou um total de %d / 5",acertos);
}

void cobraNaCaixa() {
    printf("----Cobra Na Caixa----\n\n");

    char jog[2][10];//jogadores
    int vez = 0;
    printf("escreva o nome do jogador 1: ");
    scanf("%s",jog[0]);
    printf("escreva o nome do jogador 2: ");
    scanf("%s",jog[1]);

    printf("nomes jogadores são: %s e %s \n",jog[0],jog[1]);

    int i;
    int numCaixas = 5;
    int caixas[numCaixas];
    // 0 = nada // 1 = cobra // 2 = botão // 3 = aberta e vazia //

    int cobra = rand() % numCaixas,// coloca uma cobra em uma caixa qualquer
        bot = rand() % numCaixas;
    while(bot == cobra) {
        bot = rand() % numCaixas;
        // se botao caiu em cima de uma cobra, entao ele deve escolher outro lugar.
    }

    for(i = 0; i < numCaixas;i++) {
        caixas[i] = 0;
    }

    caixas[cobra] = 1;
    caixas[bot] = 2;

    int ganhador = 0; // 0 = jogando // 1 = jogador um ganhou // 2 = jogador dois ganhou //
    int e; // caixa escolhida

    while (ganhador == 0) {
        printf("vez de %s! \n", jog[vez]);
        for(i = 0; i < numCaixas;i++) {
            if (caixas[i] == 3) {
                // desenhar caixas
                printf("+    +     \n");
                printf("|    | %d (vazia) \n",i);
                printf("+----+     \n\n");

            } else {
                // desenhar caixas fechadas
                printf("+----+     \n");
                printf("| ?? | %d  \n",i);
                printf("+----+     \n\n");
            }
        }
        e = -1;
        printf("jogador %s escolha uma caixa: ",jog[vez]);
        scanf("%d",&e);
        printf("valor da caixa caixa: %d -> e = %d \n",caixas[e],e);

        switch(caixas[e]) {
            case 0://nada
                caixas[e] = 3;
                printf("a caixa %d caixa vazia!!! \n",e);
            break;
            case 1://cobra
                ganhador = ((vez+1) % 2)+1;// ganhador é o que não é da vez
                printf("a caixa %d tinha uma cobra! \n",e);
            break;
            case 2://botao
                ganhador = vez+1;// ganhador é o da vez
                printf("a caixa %d tinha um botão! \n",e);
            break;
        }

        vez = (vez+1)%2; // troca a vez
        printf("\n\n");
    }

    if (ganhador != 0) {
        printf("o jogador %s ganhou!!!!!",jog[ganhador-1]);
    }
}

void drawGousmas(int g[2]) {

    printf("flag0 \n");

    char gousma[3][10] =
    {
        "  _____ \0",
        " /     |\0",
        "|______|\0"
    };

    int dlarg = 10;// a largura do desenho de uma gousma é: 8 caracteres

    char linhas[3][dlarg*2];// dar espaço para a gousma, os espaços, e o lugar para desenhar o nivel de furia dela

    int i,j,k;
    for (i = 0;i < 3;i++) {
        for (j = 0;j < dlarg*2;j++) {
            linhas[i][j] = '@'; // clear da linha
        }

        linhas[i][dlarg*2-1] = '\0'; // clear da linha
        printf("%s \n",gousma[i]);
    }
    printf("1 -> %s \n",gousma[0]);
    printf("2 -> %s \n",gousma[1]);
    printf("3 -> %s \n\n",gousma[2]);

    printf("1 -> %s \n",linhas[0]);
    printf("2 -> %s \n",linhas[1]);
    printf("3 -> %s \n\n",linhas[2]);

    int larg = dlarg+3; // largura do desenho + espaço(1) + numero de furia(1) + espaço(1)
    for(i = 0; i < 2;i++) {

        printf("flag1 -> start(%i) \n",i);
        if (g[i] == -1) {
            // esta morta -> nao desenhe
            continue;
        }

        for(j = 0; j < 3;j++) {
            printf("antes j(%d): %s -> %s \n",j,linhas[j],gousma[j]);
            for(k = 0; k < dlarg;k++) {
                // escolhi esse metodo ao inves de strcat() pois as gousmas iam ficar na posição certa mesmo quando uma morria
                linhas[j][larg*i + k] = (char)((int)(gousma[j][k]));// desenhar gousma
                printf("i:%d j:%d k:%d -> linha(%c) = gousma(%c) ? %i \n",i,j,k,linhas[j][larg*i + k], gousma[j][k],(int)(gousma[j][k]));
            }
            printf("resultado j(%d): %s -> %s \n",j,linhas[j],gousma[j]);
            if (j == 2) { // terceira linha
                printf("final: \n");
                linhas[j][larg*i + dlarg] = ' '; // espaço
                linhas[j][larg*i + dlarg + 1] = (int)(g[i]);// desenhar o nivel de furia
                linhas[j][larg*i + dlarg] = ' '; // espaço
            }
        }

    }

    printf("flag2 \n");

    for(i = 0; i < 3;i++) { // printar as 3 linhas
        printf("%s \n", linhas[i]);
    }
    printf("flag3 \n");
}

void gousmasWar() {
    printf("----Gousmas War----\n\n");

    int ganhador = 0;
    int vez = rand()%2;
    /*
    char jog[2][10];//jogadores

    printf("escreva o nome do jogador 1: ");
    scanf("%s",jog[0]);
    printf("escreva o nome do jogador 2: ");
    scanf("%s",jog[1]);

    // */

    char jog[2][10] = {
    "gugugaga",
    "gagagugu"
    };
    // */
    printf("nomes dos jogadores são: %s e %s \n",jog[0],jog[1]);

    //int action = 0; // 0 = atack //  1= defesa //


    int gousmas[2][2] = {
        {1,1}, // gousmas do jogador 1
        {1,1}  // gousmas do jogador 2
    };

    while(ganhador == 0) { // ganhador = nenhum
        printf("### vez de %s! \n", jog[vez]);

        printf("gosmas de %s: \n", jog[vez]);

        drawGousmas(gousmas[vez]);

        printf("flag4 \n");
        vez = (vez+1) % 2; // trocar a vez
        ganhador++;
    }

}
int main() {

    int ended = 0;
    int escolha;
    char restart;
    while (ended == 0) {
        printf("ARCADE GIROTTO \n\n");

        printf("1: perguntas e respostas \n");
        printf("2: cobra na caixa \n");
        printf("3: gousmas war \n");
        printf("4: sair do arcade... \n");
        printf("escolha o jogo que deseja jogar:");
        scanf("%d",&escolha);

        switch(escolha) {
        case 1:
            perguntasERespostas();
            break;
        case 2:
            cobraNaCaixa();
            break;
        case 3:
            gousmasWar();
            break;
        case 4:
            return 0;// fechar jogo
            break;
        default:
            printf("numero não valido inserido? \n");
            break;
        }
        restart = 'n';
        printf("\n jogar novamente?(S/N) ");
        scanf("%c",&restart);
        scanf("%c",&restart);
        if (restart == 's' || restart == 'S') {
            printf("reiniciando... \n \n");
        } else {
            ended = 1;
            printf("finalizando... ('%c')\n\n\n",restart);
        }
    }

    return 0;
}
