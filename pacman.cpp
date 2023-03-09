#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<time.h>
#include<dos.h>

#define H 15
#define W 42
char playfield[H][W]={ //count of food = 104
	{"+=======================================+"},
	{"| . . . . | . . . . . . . . . | . . . . |"}, // y=1 x=9,30
	{"| . +== . | . ============= . | . ==+ . |"}, // 2  4,5,6, 10, 14-26, 30, 34,35,36
	{"| . | . . . . . . . . . . . . . . . | . |"}, // 3  4, 36
	{"| . | . === . +==       ==+ . === . | . |"}, // 4  4, 8,9,10, 14,15,16, 24,25,26, 30,31,32, 36
	{"| . . . . . . |           | . . . . . . |"}, // 5  14, 26
	{"| . | . === . +===========+ . === . | . |"}, // 6  4, 8,9,10, 14,15,16, 24,25,26, 30,31,32, 36
	{"| . | . . . . . . . . . . . . . . . | . |"}, // 7  4, 36
	{"| . +== . | . ============= . | . ==+ . |"}, // 8  4,5,6, 10, 14-26, 30, 34,35,36
	{"| . . . . | . . . . . . . . . | . . . . |"}, // 9  10, 30
	{"+=======================================+"}
}; //the playfield

int food_collect=0,game_end=0;
int py=5,px=20;//these variables represent pacman coordinate
int gy1=1,gx1=38; //ghost 1
int gy2=9,gx2=2; //ghost 2
int gy3=1,gx3=2; //ghost 3
int gy4=9,gx4=38; //ghost 4

int move=0, r_move=0; // determine the move
char k='V'; // to change pacman face when move

time_t start=time(NULL); //start time

void move_ghosts(){
	srand(time(0));
	 // x = 2 to 38, y = 1 to 9
	 
	r_move = rand()%4+1;
	switch(r_move){
		case 1: // move down
			if(playfield[gy1+1][gx1]!='|' && playfield[gy1+1][gx1]!='+' && playfield[gy1+1][gx1]!='=' && playfield[gy1+1][gx1]!=' ')
				gy1++; 
			break;
		case 2: // move up
			if(playfield[gy1-1][gx1]!='|' && playfield[gy1-1][gx1]!='+' && playfield[gy1-1][gx1]!='=' && playfield[gy1-1][gx1]!=' ')
				gy1--; 
			break;
		case 3: // move left
			if(playfield[gy1][gx1-2]!='|' && playfield[gy1][gx1-2]!='+' && playfield[gy1][gx1-2]!='=' && playfield[gy1][gx1-2]!=' ')
				gx1-=2; 
			break;
		case 4: // move right
			if(playfield[gy1][gx1+2]!='|' && playfield[gy1][gx1+2]!='+' && playfield[gy1][gx1+2]!='=' && playfield[gy1][gx1+2]!=' ')
				gx1+=2; 
			break;
	}
	
	r_move = rand()%4+1;
	switch(r_move){
		case 1: // move down
			if(playfield[gy2+1][gx2]!='|' && playfield[gy2+1][gx2]!='+' && playfield[gy2+1][gx2]!='=' && playfield[gy2+1][gx2]!=' ')
				gy2++; 
			break;
		case 2: // move up
			if(playfield[gy2-1][gx2]!='|' && playfield[gy2-1][gx2]!='+' && playfield[gy2-1][gx2]!='=' && playfield[gy2-1][gx2]!=' ')
				gy2--; 
			break;
		case 3: // move left
			if(playfield[gy2][gx2-2]!='|' && playfield[gy2][gx2-2]!='+' && playfield[gy2][gx2-2]!='=' && playfield[gy2][gx2-2]!=' ')
				gx2-=2; 
			break;
		case 4: // move right
			if(playfield[gy2][gx2+2]!='|' && playfield[gy2][gx2+2]!='+' && playfield[gy2][gx2+2]!='=' && playfield[gy2][gx2+2]!=' ')
				gx2+=2; 
			break;
	}
	
	r_move = rand()%4+1;
	switch(r_move){
		case 1: // move down
			if(playfield[gy3+1][gx3]!='|' && playfield[gy3+1][gx3]!='+' && playfield[gy3+1][gx3]!='=' && playfield[gy3+1][gx3]!=' ')
				gy3++; 
			break;
		case 2: // move up
			if(playfield[gy3-1][gx3]!='|' && playfield[gy3-1][gx3]!='+' && playfield[gy3-1][gx3]!='=' && playfield[gy3-1][gx3]!=' ')
				gy3--; 
			break;
		case 3: // move left
			if(playfield[gy3][gx3-2]!='|' && playfield[gy3][gx3-2]!='+' && playfield[gy3][gx3-2]!='=' && playfield[gy3][gx3-2]!=' ')
				gx3-=2; 
			break;
		case 4: // move right
			if(playfield[gy3][gx3+2]!='|' && playfield[gy3][gx3+2]!='+' && playfield[gy3][gx3+2]!='=' && playfield[gy3][gx3+2]!=' ')
				gx3+=2; 
			break;
	}
	
	r_move = rand()%4+1;
	switch(r_move){
		case 1: // move down
			if(playfield[gy4+1][gx4]!='|' && playfield[gy4+1][gx4]!='+' && playfield[gy4+1][gx4]!='=' && playfield[gy4+1][gx4]!=' ')
				gy4++; 
			break;
		case 2: // move up
			if(playfield[gy4-1][gx4]!='|' && playfield[gy4-1][gx4]!='+' && playfield[gy4-1][gx4]!='=' && playfield[gy4-1][gx4]!=' ')
				gy4--; 
			break;
		case 3: // move left
			if(playfield[gy4][gx4-2]!='|' && playfield[gy4][gx4-2]!='+' && playfield[gy4][gx4-2]!='=' && playfield[gy4][gx4-2]!=' ')
				gx4-=2; 
			break;
		case 4: // move right
			if(playfield[gy4][gx4+2]!='|' && playfield[gy4][gx4+2]!='+' && playfield[gy4][gx4+2]!='=' && playfield[gy4][gx4+2]!=' ')
				gx4+=2; 
			break;
	}
}
void user_input(){
	//this function use to take user input
	char c1;
	if(kbhit()){
		c1=getch();
		
		switch(c1){
			case 72:
				py-=1;
				k='V';
				move=1;
				break; //cursor up
			case 80:
				py+=1;
				k='^';
				move=2;
				break; //cursor down
			case 75:
				px-=2;
				k='>';
				move=3;
				break; //cursor left
			case 77:
				px+=2;
				k='<';
				move=4;
				break; //cursor right
			case 'w':
				py-=1;
				k='V';
				move=1;
				break; //cursor up
			case 's':
				py+=1;
				k='^';
				move=2;
				break; //cursor down
			case 'a':
				px-=2;
				k='>';
				move=3;
				break; //cursor left
			case 'd':
				px+=2;
				k='<';
				move=4;
				break; //cursor right
			case ' ':
				game_end=3;
				break; //cursor right
		}
	}
}
void setup(){
	int a,i,j;
	for(i=0;i < H;i++){
		for(j=0;j < W;j++){
			if(playfield[i][j]=='V' || playfield[i][j]=='^' || playfield[i][j]=='>' || playfield[i][j]=='<'){
				playfield[i][j]=' ';
			}
			if(playfield[i][j]=='G'){
				playfield[i][j]='.';
			}
		}
	}
	if(playfield[py][px]=='.'){
		food_collect++;
	}
	if(playfield[py][px]=='|' || playfield[py][px]=='+' || playfield[py][px]=='='){
		if(move==1){
			py+=1;	
		}
		else if(move==2){
			py-=1;	
		}
		else if(move==3){
			px+=2;	
		}
		else if(move==4){
			px-=2;	
		}
		else{
			py=5;
			px=20;
		}
	}
	playfield[py][px]=k;
	playfield[gy1][gx1]='G';
	playfield[gy2][gx2]='G';
	playfield[gy3][gx3]='G';
	playfield[gy4][gx4]='G';
	if(food_collect==100)
		game_end=4;
	if(playfield[py][px]=='G')
		game_end=2;
}
void draw_playfield(){
	int i,j;
	for(i=0;i < H;i++){
		for(j=0;j < W;j++){
			printf("%c",playfield[i][j]);
		}
		if (i<H-4)
			printf("\n");
	}
	
	time_t sec=time(NULL)-start;
	printf("%d seconds and %d dots found",sec, food_collect);
	if(sec == 60)
		game_end=1;
}

int main(){
	int i=100;
	while(game_end<1){
		system("cls");
		setup();
		user_input();
		move_ghosts();
		draw_playfield();
		if(i < 1000)
			i=i+100;
		else
			i=100;
		
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	}
	printf("\n\n");
	if(game_end==1)
		printf("TIMEOUT: ran out of time.");
	else if(game_end==2)
		printf("LOST: eaten by ghost");
	else if(game_end==3)
		printf("KEY: exited by keyboard entry");
	else if(game_end==4)
		printf("YOU WON! CONGRATUALIONS!~");
	getch();
}
