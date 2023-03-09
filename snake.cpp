#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<time.h>

using namespace std;

#define H 22
#define W 52

char playfield[H][W] = { // 14x43 <- playsize
	{"+=================================================+"}, // 0 <- height
	{"|                                                 |"}, // 1
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"}, // 5
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"}, // 8
	{"|                                                 |"},
	{"|                                                 |"}, // 10
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"},
	{"|                                                 |"}, // 15
	{"+=================================================+"}	 // 16
	//0    5    10   15    20    25    30    35    40    45
};

bool game_end=false;
int hy=8, hx=20; //snake head position
int bdy=8, bdx=19; //snake body position
int fdy=8, fdx=29; //food position

void move_snake(){
	if(playfield[hy][hx+1]!='|'){
		hx++; // move right
	}
	else{
		hx=1;
	}
}
void kb_pressed(){
	
	if(kbhit()){
		switch(getch()){
			case 72: break; //up
			case 80: break; //down
			case 75: break; //left
			case 77: break; //right
			case ' ': game_end=true; break;
		}
	}
	
}

void setup(){
	int i,j;
	
	if(playfield[hy][hx-1]=='|')
		playfield[hy][hx-1]='|';
	else if(playfield[hy][hx+1]=='|'){
		playfield[hy][hx-1]=' ';
		}
	else
		playfield[hy][hx-1]=' ';
		
	
	playfield[hy][hx]='0';
	
	if(playfield[hy][hx+1]=='|')
		playfield[hy][hx]=' ';
	//playfield[bdy][bdx]='#';
	//playfield[bdy-1][bdx-1]='#';
	//playfield[fdy][fdx]='*';
}

void draw_field(){
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cout << playfield[i][j];
		}
		cout << endl;
	}
}


int main(){
	while(game_end!=true){
		cout << "\n SNAKE GAME" << endl;
		setup();
		kb_pressed();
		move_snake();
		draw_field();
		
		system("cls");
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
	}
	//getch();
}
