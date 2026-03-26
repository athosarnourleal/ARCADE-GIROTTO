#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setCaps(char *c) {
    if (*c >= 97 && *c <= 122) {
        *c -= 32;
    }
}

int isValid(char r) {
    if (r >= 65 && r <= 68) {

    }
    return false;
}

void perguntasERespostas() {
    char r = 0;
    int acertos = 0;
    printf("###### Perguntas e Respostas ######\n");
    printf("selecione as alternativas corretas e veja seu resultado! \n\n");

    while(!isValid(r)) {
        printf("##Pergunta 1!\n");//--------------------------------1

        printf("quantos digitos existem de pi?\n");

        printf("a) 3.14 \n");
        printf("b) 3 \n");
        printf("c) infinitos \n");
        printf("d) 109.267.901 \n");
        printf("escolha uma alternativa: ");
        scanf(" %c",&r);
        setCaps(&r);

        if (!isValid(r)) {
            printf("resposta invalida...\n");
            system("pause");
            system("cls");
            continue;
        }

        if (r == 'C') {
            printf("ACERTOU! \n");
            acertos++;
        } else {
            printf("ERROU! \n");
            printf("a alternativa certa era C), não %c) \n",r);
        }

        system("cls");
    }
    r = 0;

    while (!isValid(r)) {
        printf("##Pergunta 2!\n");//--------------------------------2

        printf("Qual é a capital do uruguai? \n");

        printf("a) havanna \n");
        printf("b) montevidéu \n");
        printf("c) tenochtlan \n");
        printf("d) el salvador \n");
        scanf(" %c",&r);
        setCaps(&r);

        if (!isValid(r)) {
            printf("resposta invalida...\n");
            system("pause");
            system("cls");
            continue;
        }

        if (r == 'B') {
            printf("ACERTOU! \n");
            acertos++;
        } else {
            printf("ERROU! \n");
            printf("a alternativa certa era B), não %c) \n",r);
        }

        system("cls");
    }
    r = 0;

    while (!isValid(r)) {
        printf("##Pergunta 3 \n");//--------------------------------3

        printf("que ano foi decretada a lei aurea? \n");

        printf("a) 1888 \n");
        printf("b) 1980 \n");
        printf("c) 1790 \n");
        printf("d) 1816 \n");
        scanf(" %c",&r);
        setCaps(&r);

        if (!isValid(r)) {
            printf("resposta invalida...\n");
            system("pause");
            system("cls");
            continue;
        }

        if (r == 'A') {
            printf("ACERTOU! \n");
            acertos++;
        } else {
            printf("ERROU! \n");
            printf("a alternativa certa era A), não %c) \n",r);
        }

        system("cls");
    }
    r = 0;

    while (!isValid(r)) {
        printf("##Pergunta 4 \n");//--------------------------------4

        printf("qual a soma dos angulos internos de um triangulo obtusangulo? \n");

        printf("a) 135 \n");
        printf("b) 270 \n");
        printf("c) 360 \n");
        printf("d) 180 \n");
        scanf(" %c",&r);
        setCaps(&r);

        if (!isValid(r)) {
            printf("resposta invalida...\n");
            system("pause");
            system("cls");
            continue;
        }

        if (r == 'D') {
            printf("ACERTOU! \n");
            acertos++;
        } else {
            printf("ERROU! \n");
            printf("a alternativa certa era D), não %c) \n",r);
        }

        system("cls");
    }
    r = 0;

    while(!isValid(r)) {
        printf("##Pergunta 5 \n");//--------------------------------5

        printf("de quantos digitos é formado o CPF brasileiro? \n");
        printf("a) 10 \n");
        printf("b) 11 \n");
        printf("c) 12 \n");
        printf("d) 9 \n");
        scanf(" %c",&r);
        setCaps(&r);

        if (!isValid(r)) {
            printf("resposta invalida...\n");
            system("pause");
            system("cls");
            continue;
        }

        if (r == 'B') {
            printf("ACERTOU! \n");
            acertos++;
        } else {
            printf("ERROU! \n");
            printf("a alternativa certa era B), não %c) \n",r);
        }

        system("cls");
    }

    printf("Fim do jogo! \n você acertou um total de %d / 5\n\n",acertos);
}

void cobraNaCaixa() {
    printf("###### Cobra Na Caixa ######\n\n");

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
        if (ganhador == 0) {
            system("cls");
        }
    }

    if (ganhador != 0) {
        printf("o jogador %s ganhou!!!!!",jog[ganhador-1]);
    }
}

void drawGousmas(int g[2]) {
    // desenhar as gousmas vivas na tela

    int dlarg = 8;// a largura do desenho de uma gousma é: 8 caracteres
    int larg = dlarg+3; // largura do desenho + espaço(1) + numero de furia(1) + espaço(1)
    int linelen = larg*2+1; // largura total das 2 gousmas

    char gousma[3][8] =
    {
        "  _____ ",
        " /     |",
        "|______|"
    };

    char linhas[3][linelen];// linhas que vão ser printadas

    int i,j,k;
    for (i = 0;i < 3;i++) {
        for (j = 0;j < linelen;j++) {
            linhas[i][j] = ' '; // clear da linha
        }

        linhas[i][linelen-1] = '\0'; // clear da linha
    }
    for(i = 0; i < 2;i++) {
        if (g[i] == -1) {
            // esta morta -> nao desenhe
            continue;
        }

        for(j = 0; j < 3;j++) {
            for(k = 0; k < dlarg;k++) {
                // escolhi esse metodo ao inves de strcat() pois as gousmas iam ficar na posição certa mesmo quando uma morria
                linhas[j][larg*i + k] = gousma[j][k];// passar o desenho da gousma para a linha
            }
            if (j == 2) { // na terceira linha
                char furia = g[i] + '0';
                linhas[j][larg*i + dlarg  ] = ' '; // espaço
                linhas[j][larg*i + dlarg+1] = furia;// desenhar o nivel de furia
                linhas[j][larg*i + dlarg+2] = ' '; // espaço
            }
        }

    }

    // printar as linhas formadas
    char tab[] = "     ";
    printf("%sgousma 1     gousma 2\n",tab);
    for(i = 0; i < 3;i++) {
        printf("%s%s \n",tab, linhas[i]);
    }
}

void gousmasWar() {
    printf("###### Gousmas War ###### \n\n");

    char jog[2][10];//jogadores

    printf("escreva o nome do jogador 1: ");
    scanf("%s",jog[0]);
    printf("escreva o nome do jogador 2: ");
    scanf("%s",jog[1]);

    printf("nomes dos jogadores são: %s e %s!\n",jog[0],jog[1]);

    int ganhador = 0; // ganhador = 0 -> nao sei quem ganhou ainda
    int vez = rand()%2; // vez aleatoria
    int action = 0; // 0 = distribuir furia //  1 = atacar // 2 = ataque obrigatorio //
    int alvo,quant,atacante, atacado;

    int gousmas[2][2] = { // furia das gosmas
        {1,1}, // gousmas do jogador 1
        {1,1}  // gousmas do jogador 2
    };
    // furia == -1 -> gousma morre


    while(ganhador == 0) { // ganhador = nenhum
        printf("\n------ vez de %s! ------\n\n", jog[vez]);

        // desenhar as gousmas no jogo //

        // gousmas do jogador 1
        printf("gosmas de %s: ", jog[0]);
        if (vez == 0) {// printar indicador de vez
            printf("<<< ");
        }
        printf("\n\n");
        drawGousmas(gousmas[0]);
        printf("\n");

        // gousmas do jogador 2
        printf("gosmas de %s: ", jog[1]); // do jogador 2
        if (vez == 1) {// printar indicador de vez
            printf("<<< ");
        }
        printf("\n\n");
        drawGousmas(gousmas[1]);
        printf("\n");

        // checar se alguem ganhou //

        if (gousmas[0][0] + gousmas[0][1] == -2) {
            // se ambas do jogador 1 morrerem -> jogador 2 ganha
            ganhador = 2;
            break;
        }
        if (gousmas[1][0] + gousmas[1][1] == -2) {
            // se ambas do jogador 2 morrerem -> jogador 1 ganha
            ganhador = 1;
            break;
        }

        // ver a ação que deve ser executada //

        if (gousmas[vez][0] >= 0 && gousmas[vez][1] >= 0) {
            // ambos estão vivos
            printf("0: distribuir furia\n");
            printf("1: atacar\n");
            printf("---> %s, escolha sua ação: ",jog[vez]);
            scanf("%d",&action);
            if (action != 0 && action != 1) {
                // se for inserido um valor invalido -> vai atacar
                printf("nenhum valor valido inserido -> vai atacar");
                action = 1;
            }
        } else {
            // se um dos dois está morto, entao não é possivel transferir

            printf("%s apenas pode atacar! \n",jog[vez]);
            action = 2;
        }

        // executar a ação dita //

        switch(action) {
        case 0: // distribuir
            printf("DISTRIBUIR \n");
            printf("indique qual gousma vai receber da outra: ");
            scanf("%d",&alvo);
            printf("indique o quanto de furia sera transferido: ");
            scanf("%d",&quant);

            alvo --;// fiz isso pois a ID das gousmas é no array 0 - 1, ao inves de 1 - 2

            if (quant > gousmas[vez][(alvo+1)%2]) {// quant é maior que a furia da gousma que vai entregar
                quant = gousmas[vez][(alvo+1)%2];
            } else if (quant < 0) {// quant é negativa
                quant = 0;
            }

            //transferir
            gousmas[vez][alvo] += quant;
            gousmas[vez][(alvo+1)%2] -= quant;

            printf("gosmas de %s após a transferencia \n", jog[vez]); // desse jogador
            drawGousmas(gousmas[vez]);// desenhar as gousmas desse jogador

        break;
        case 1: // atacar
            printf("ATAQUE \n");
            printf("indique que gousma vai atacar o inimigo: ");
            scanf("%d",&atacante);

            if (gousmas[(vez+1)%2][0] == -1 ||gousmas[(vez+1)%2][1] == -1) {
                //se uma estiver morta -> mire na outra

                if (gousmas[(vez+1)%2][0] != -1) {
                    // se 0 for vivo
                    atacado = 0;
                } else {
                    // se 1 for vivo
                    atacado = 1;
                }

            } else {
                // se ambas do inimigo estao vivas -> escolha qual atacar
                printf("indique qual gousma do inimigo vai ser atacada: ");
                scanf("%d",&atacado);

                if (atacado < 1 || atacado > 2) {
                    // input invalido
                    atacado = 1;
                }
            }

            atacante--;// fiz isso pois a ID das gousmas é no array 0 - 1, ao inves de 1 - 2
            atacado--;

            // atacar
            gousmas[(vez+1)%2][atacado] += gousmas[vez][atacante]; // furia da gosma atacada += furia da gosma atacante;

            // ver se a gousma atacada morreu
            if (gousmas[(vez+1)%2][atacado] > 5) {
                gousmas[(vez+1)%2][atacado] = -1; // morta
            }

        break;
        case 2:// ataque obrigatorio -> não ha como distribuir pois uma das gousmas esta morta
            printf("ATAQUE \n");

            // atacante é a gosma viva(só uma das duas pode estar viva ao mesmo tempo)
            if (gousmas[vez][0] != -1) {
                atacante = 0;
            } else {
                atacante = 1;
            }
            printf("gousma %d vai atacar \n",atacante+1);

            printf("indique qual gousma do inimigo vai ser atacada: ");
            scanf("%d",&atacado);

            atacado--;

            if (gousmas[(vez+1)%2][atacado] == -1) {
                atacado = (atacado+1)%2;
            }

            // atacar
            gousmas[(vez+1)%2][atacado] += gousmas[vez][atacante]; // furia da gosma atacada += furia da gosma atacante;

            // ver se a gousma atacada morreu
            if (gousmas[(vez+1)%2][atacado] > 5) {
                gousmas[(vez+1)%2][atacado] = -1; // morta
            }
        break;
        default:
            printf("ação invalida, turno pulado... (%d)\n",action);
        break;
        }
        system("cls");
        vez = (vez+1) % 2; // trocar a vez
    }

    printf("\n JOGO ACABOU! \n");
    printf("%s ganhou!!!! \n", jog[ganhador-1]);

}
int main() {

    srand(time(NULL));

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

        system("cls");

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
            printf("numero invalido inserido \n");
            break;
        }
        restart = 'n';
        printf("\n voltar ao menu?(S/N) ");
        scanf("%c",&restart);
        scanf("%c",&restart);
        if (restart == 's' || restart == 'S') {
            printf("reiniciando... \n \n");
            system("cls");
        } else {
            ended = 1;
            printf("finalizando... ('%c')\n\n\n",restart);
        }
    }

    return 0;
}
