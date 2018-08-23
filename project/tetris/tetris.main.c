#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define UP 72 // spin
#define LEFT 75 // move toward left
#define RIGHT 77 // move toward right
#define DOWN 80 // softdrop
#define SPACE 32 // hard drop
#define p 112 // pause
#define P 80 // pause
#define ESC 27 // stop game

#define flase 0
#define ture 1

#define ACTIVE_BLOCK -2 // on borad of block 
#define CELLING -1 // if block can move it's 0 or postive number
#define WALL 1
#define INACTIVE_BLOCK 2 // value of completed moved block
#define EMPTY 0 // if block can move it's negative number

#define MAIN_X 11 // width of game board
#define MAIN_Y 23 // length of game board
#define MAIN_X_ADJ 3 // set of width
#define MAIN_Y_ADJ 1 // set of length

#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 // 

int STATUS_Y_LEVEL; // location Y of LEVEL
int STATUS_Y_SCORE; // location Y of SCORE
int STATUS_Y_GOAL; // location Y of GOAL

int blocks[7][4][4][4]={
	{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
		 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
	{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
		 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},
		 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
	{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},
		 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},
		 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
	{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},
		 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
	{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
		 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
	}; // shape of block 4x4, blocks[b_type][b_rotation][i][j] 

int b_type; //
