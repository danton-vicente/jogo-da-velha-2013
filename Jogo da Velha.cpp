#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char tab[5][5];
char escolha,escolhapc,jogarnovamente,zerarjogo;
int x,y,l,c,val,pos,velha=0,fim=0,vitx=0,vitb=0,escolhaok=0,okpos=0,emuso=0,contvelha=0,dificuldade,dificuldadeok=0;
int lok=0,cok=0,jogarnovamenteok=0,zerarok=0;

void limpa(){


for(x=0;x<5;x++){
	for(y=0;y<5;y++){
			if(x==0 && y==1 || x==0 && y==3 || x==2 && y==1 || x==2 && y==3 || x==4 && y==1 || x==4 && y==3){ //limpa o tabuleiro adicionando os caracteres para dividir os espacos
		  	tab[x][y]= '|';
			}
			else if(x==1 || x==3){ //limpa o tabuleiro adicionando cracteres para dividir os espacos horizontais 
					tab[x][y]='-';
			 				}
				else{
					tab[x][y]= ' '; //limpa os espacos para jogar
					}
				}
					}
								
		
}

void valida(){
	if(tab[l][c] == ' '){ //valida a jogada caso esteja livre
		val=1;
	}
	else{ //bloqueia a jogada caso esteja ocupado o espaco
		val=0;
	}
	
}

void jogar(){
	do{
	printf("\n Escolha uma posicao para jogar: ");
	scanf("%i",&pos);
	switch (pos){ //recebe a posicao e adiciona as coordenadas
		case 1:
		l=0;
		c=0;
		okpos=1;
		break;
		case 2:
		l=0;
		c=2;
		okpos=1;
		break;
		case 3:
		l=0;
		c=4;
		okpos=1;
		break;
		case 4:
		l=2;
		c=0;
		okpos=1;
		break;
		case 5:
		l=2;
		c=2;
		okpos=1;
		break;
		case 6:
		l=2;
		c=4;
		okpos=1;
		break;
		case 7:
		l=4;
		c=0;
		okpos=1;
		break;
		case 8:
		l=4;
		c=2;
		okpos=1;
		break;
		case 9:
		l=4;
		c=4;
		okpos=1;
		break;
		default:
		okpos=0;
	}
	}while(okpos==0);
}
	
void mostra_tabuleiro(){
    system("cls"); //limpa a tela
	printf("\n");
	for(x=0;x<5;x++){ //mostra o tabuleiro na ordem certa
		for(y=0;y<5;y++){
			printf("%c",tab[x][y]);
		}
		printf("\n");
	}
	printf("\n Placar do jogo: \n O: %i \n X: %i \n Velha: %i \n",vitb,vitx,velha); //placar do jogo
	printf("\n Voce esta jogando com: %c \n",escolha); //escolha do jogador: X ou Y
	printf("\n Voce esta jogando na dificuldade: %i \n",dificuldade); //escolha do jogador para dificuldade
	printf("\n Voce devera jogar escolhendo as posicoes como no modelo abaixo: \n"); //ensina a jogar
	printf("\n 1|2|3 \n ----- \n 4|5|6 \n ----- \n 7|8|9 \n");
}

void vitoria(){
	 if(tab[0][0] == 'X' && tab[0][2] == 'X' && tab[0][4] == 'X' ){ //primeira linha
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[2][0] == 'X' && tab[2][2] == 'X' && tab[2][4] == 'X' ){ //segunda linha
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[4][0] == 'X' && tab[4][2] == 'X' && tab[4][4] == 'X' ){ //terceira linha
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[0][0] == 'X' && tab[2][0] == 'X' && tab[4][0] == 'X' ){ //primeira coluna
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[0][2] == 'X' && tab[2][2] == 'X' && tab[4][2] == 'X' ){ //segunda coluna
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[0][4] == 'X' && tab[2][4] == 'X' && tab[4][4] == 'X' ){ //terceira coluna
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[0][0] == 'X' && tab[2][2] == 'X' && tab[4][4] == 'X' ){ //diagonal para direita
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		if(tab[0][4] == 'X' && tab[2][2] == 'X' && tab[4][0] == 'X' ){ //digadonal para esquerda
		printf("Vitoria do X! ");
		vitx++;
		fim=1;
	}
	else{
		 if(tab[0][0] == 'O' && tab[0][2] == 'O' && tab[0][4] == 'O' ){ //primeira linha
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[2][0] == 'O' && tab[2][2] == 'O' && tab[2][4] == 'O' ){ //segunda linha
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[4][0] == 'O' && tab[4][2] == 'O' && tab[4][4] == 'O' ){ // terceira linha
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[0][0] == 'O' && tab[2][0] == 'O' && tab[4][0] == 'O' ){ // primeira coluna
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[0][2] == 'O' && tab[2][2] == 'O' && tab[4][2] == 'O' ){ // segunda coluna
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[0][4] == 'O' && tab[2][4] == 'O' && tab[4][4] == 'O' ){ // terceira coluna
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[0][0] == 'O' && tab[2][2] == 'O' && tab[4][4] == 'O' ){ //diagonal pra direita
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(tab[0][4] == 'O' && tab[2][2] == 'O' && tab[4][0] == 'O' ){ //diagonal para esquerda
		printf("Vitoria do O! ");
		vitb++;
		fim=1;
	}
	else{
		if(contvelha==10){
			printf("Deu Velha! ");
			velha++;
			fim=1;
		}
	else{
		fim=0;
	}	
	}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}

void x_ou_o(){
do{
	printf("Escolha entre X ou O: ");
	escolha=getche(); //recebe a escolha entre X ou O
	switch(escolha){
		case 'x': case 'X':
			escolha='X';
			escolhapc='O';
			escolhaok=1;
			break;
		case 'o': case 'O': case '0':
			escolha='O';
			escolhapc='X';
			escolhaok=1;
			break;
		default:
			escolhaok=0;
	}
	}while(escolhaok==0);
	}

void adicionarescolha(){
if(val==1){ //completa a jogada adicionando a opcao do jogador na casa escolhida
	tab[l][c]=escolha;
	emuso=1;
	}
	else{
	printf(" Nao e possivel jogar nesta posicao!");
	emuso=0;
}
}

void nivel(){
	do{
	printf(" \n Escolha a dificuldade do jogo: \n 1 - Facil \n 2 - Medio \n 3 - Dificil \n Dificuldade: "); // recebe a dificuldade do jogo
	scanf("%i",&dificuldade);
	switch(dificuldade){
		case 1:
			escolhaok=1;
			break;
		case 2:
			escolhaok=1;
			break;
		case 3:
			escolhaok=1;
			break;
		default:
			escolhaok=0;
			}
	}while(escolhaok==0);
	
}

void diff(){
	if(contvelha!=8){ //caso o contador esteja em 8 o PC nao ira jogar mais
	do{
	srand(time(NULL));
	do{
	l=rand()%5;
	if(l%2==0){ //otimizando o codigo de posicao aleatoria para nao demorar tanto
		lok=1;
	}
	else{
		lok=0;
	}
	}while(lok==0);
	do{
	c=rand()%5;
	if(c%2==0){ //otimizando o codigo de posicao aleatoria para nao demorar tanto
		cok=1;
	}
	else{
		cok=0;
	}
	}while(cok==0);
	valida();
	}while(val==0);
	tab[l][c]= escolhapc;
}
else{
	tab[0][1]='|';	//adicionando uma posicao nula na ultima jogada do PC
}
}

void difm(){
	//dificuldade media nao bloqueia todas as opcoes de vitoria do usuario
	
	if(tab[0][0] == tab [0][2] && tab[0][4] == ' '){ //fecha o jogo na linha 1
		tab[0][4]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [0][4] && tab[0][2] == ' '){ //fecha o jogo na linha 1
		tab[0][2]=escolhapc;
	}
	else{
		if(tab[0][2] == tab [0][4] && tab[0][0] == ' '){ //fecha o jogo na linha 1
		tab[0][0]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [2][2] && tab[2][4] == ' '){ //fecha o jogo na linha 2
		tab[2][4]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [2][4] && tab[2][2] == ' '){ //fecha o jogo na linha 2
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[4][4] == tab [4][2] && tab[4][0] == ' '){ //fecha o jogo na linha 3
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [2][0] && tab[4][0] == ' '){ //fecha o jogo na coluna 1
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [4][0] && tab[2][0] == ' '){ //fecha o jogo na coluna 1
		tab[2][0]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [4][0] && tab[0][0] == ' '){ //fecha o jogo na coluna 1
		tab[0][0]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [2][2] && tab[4][0] == ' '){ //fecha o jogo na digonal esquerda
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [4][0] && tab[2][2] == ' '){ //fecha o jogo na diagonal esquerda
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][2] == tab [4][0] && tab[0][4] == ' '){ //fecha o jogo na diagonal esquerda
		tab[0][4]=escolhapc;
	}
	else{
	diff();
}
}
}
}
}
}
}
}
}
}
}
}
}

void difd(){
	if(tab[2][2]== ' '){ //bloqueando a posicao central do jogo, fechamos completamente o usuario
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][0]== ' '){
			tab[2][0]=escolhapc;
		}
	else{
	if(tab[0][0] == tab [0][2] && tab[0][4] == ' '){ //fecha o jogo na linha 1
		tab[0][4]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [0][4] && tab[0][2] == ' '){ //fecha o jogo na linha 1
		tab[0][2]=escolhapc;
	}
	else{
		if(tab[0][2] == tab [0][4] && tab[0][0] == ' '){ //fecha o jogo na linha 1
		tab[0][0]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [2][2] && tab[2][4] == ' '){ //fecha o jogo na linha 2
		tab[2][4]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [2][4] && tab[2][2] == ' '){ //fecha o jogo na linha 2
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][2] == tab [2][4] && tab[2][0] == ' '){ //fecha o jogo na linha 2
		tab[2][0]=escolhapc;
	}
	else{
		if(tab[4][0] == tab [4][2] && tab[4][4] == ' '){ //fecha o jogo na linha 3
		tab[4][4]=escolhapc;
	}
	else{
		if(tab[4][0] == tab [4][4] && tab[4][2] == ' '){ //fecha o jogo na linha 3
		tab[4][2]=escolhapc;
	}
	else{
		if(tab[4][4] == tab [4][2] && tab[4][0] == ' '){ //fecha o jogo na linha 3
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [2][0] && tab[4][0] == ' '){ //fecha o jogo na coluna 1
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [4][0] && tab[2][0] == ' '){ //fecha o jogo na coluna 1
		tab[2][0]=escolhapc;
	}
	else{
		if(tab[2][0] == tab [4][0] && tab[0][0] == ' '){ //fecha o jogo na coluna 1
		tab[0][0]=escolhapc;
	}
	else{
		if(tab[0][2] == tab [2][2] && tab[4][2] == ' '){ //fecha o jogo na coluna 2
		tab[4][2]=escolhapc;
	}
	else{
		if(tab[0][2] == tab [4][2] && tab[2][2] == ' '){ //fecha o jogo na coluna 2
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][2] == tab [4][2] && tab[0][2] == ' '){ //fecha o jogo na coluna 2
		tab[0][2]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [2][4] && tab[4][4] == ' '){ //fecha o jogo na coluna 3
		tab[4][4]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [4][4] && tab[2][4] == ' '){ //fecha o jogo na coluna 3
		tab[2][4]=escolhapc;
	}
	else{
		if(tab[2][4] == tab [4][4] && tab[0][4] == ' '){ //fecha o jogo na coluna 3
		tab[0][4]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [2][2] && tab[4][4] == ' '){ //fecha o jogo na digonal direita
		tab[4][4]=escolhapc;
	}
	else{
		if(tab[0][0] == tab [4][4] && tab[2][2] == ' '){ //fecha o jogo na diagonal direita
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][2] == tab [4][4] && tab[0][0] == ' '){ //fecha o jogo na diagonal direita
		tab[0][0]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [2][2] && tab[4][0] == ' '){ //fecha o jogo na digonal esquerda
		tab[4][0]=escolhapc;
	}
	else{
		if(tab[0][4] == tab [4][0] && tab[2][2] == ' '){ //fecha o jogo na diagonal esquerda
		tab[2][2]=escolhapc;
	}
	else{
		if(tab[2][2] == tab [4][0] && tab[0][4] == ' '){ //fecha o jogo na diagonal esquerda
		tab[0][4]=escolhapc;
	}
	else{
	diff();
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}

void pc(){
	if(dificuldade==1){ //configurando as acoes do PC de acordo com a dificuldade
				diff();
					}
	else{
		if(dificuldade==2){
			difm(); }
		else{
			difd();
		}
	}
	}

void jogarnov(){
	do{
	printf("Deseja jogar novamente nas configuracoes atuais? S ou N? "); //jogar novamente
	jogarnovamente=getche();
	switch(jogarnovamente){
		case 's': case 'S':
			jogarnovamente='S';
			jogarnovamenteok=1; //para sair da repeticao
			break;
		case 'n': case 'N':
			jogarnovamente='N';
			jogarnovamenteok=1; //para sair da repeticao
			break;
		default:
			printf("\n Escolha invalida. ");
			jogarnovamenteok=0; //para manter na repeticao
	}
	}while(jogarnovamenteok==0);
}

void zerar_jogo(){
	do{
	printf("Deseja iniciar um jogo com novas configuracoes TOTALMENTE novo? S ou N? "); //jogar novamente com novas configuracoes
	zerarjogo=getche();
	switch(zerarjogo){
		case 's': case 'S':
			zerarjogo='S';
			zerarok=1; //para sair da repeticao
			break;
		case 'n': case 'N':
			zerarjogo='N';
			zerarok=1; //para sair da repeticao
			break;
		default:
			printf("\n Escolha invalida. ");
			zerarok=0; //para manter na repeticao
	}
	}while(zerarok==0);
}

main(){
	do{
	system("cls");
	printf(" BEM VINDO AO JOGO DA VELHA! \n ");
	x_ou_o();
	nivel();
	vitx=0;
	vitb=0;
	velha=0;
	do{
	limpa();
	contvelha=0;
	do{
	mostra_tabuleiro();
	do{
	jogar();
	valida();
	adicionarescolha();
	vitoria();
	}while(emuso==0);
	if(fim==0){
	pc();
	mostra_tabuleiro();
	contvelha++;
	contvelha++;
	vitoria();
	}
	else{
		mostra_tabuleiro();
		vitoria();
	}
	}while(fim==0);
	jogarnov();
}while(jogarnovamente=='S');
printf("\n");
	zerar_jogo();
}while(zerarjogo=='S');
printf("\n Pressione alguma tecla para sair");
system("pause>>null");

}



