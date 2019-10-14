#pragma once
#ifndef HEADER_ECOSYSTEM
#define HEADER_ECOSYSTEM
//MAP
#define WIDTHPIX_WINDOW 1300
#define HEIGHTPIX_WINDOW 700
#define WIDTHPIX_INFO 600
#define HEIGHTPIX_INFO HEIGHTPIX_WINDOW
#define WIDTHPIX_GAME (WIDTHPIX_WINDOW - WIDTHPIX_INFO)
#define HEIGHTPIX_GAME HEIGHTPIX_WINDOW
#define MAX_ENERGY 4000
#define COLOR_GAME_WINDOW (255) + (255 << 8) + (255 << 16)
#define COLOR_INFO_WINDOW 0
#define COLOR_GRASS (0) + (0 << 8) + (19 << 16)
#define COLOR_RIVER (30) + (144 << 8) + (255 << 16)
//RABBIT
#define MAX_THIRST 1000
#define COLOR_RABBIT_MALE (139) + (69 << 8) + (19 << 16)
#define COLOR_RABBIT_FEMALE (244) + (164 << 8) + (96 << 16) 
#define COLOR_RABBITNoMut_MALE (255) + (0 << 8) + (0 << 16)
#define COLOR_RABBITNoMut_FEMALE (255) + (0 << 8) + (0 << 16) 
#define RABBIT_RADIUS 5
#define ENERGY_FROM_GRASS 40
#define ENERGY_FROM_WATER 20
#define TIME_AFTER_COUPLE_TO_COUPLE 50

#include <SDL.h>
#include <stdio.h>
#include <thread>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string.h>
typedef struct s_fox {
	float x;
	float y;

}t_fox;
typedef struct s_rabbit {
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	float thirst;
	float energy;
	float maxEnergy;
	float visibility;
	int timeAfterDividing;
	int age;
	int maxAge;
	int status;
	float procentToSearch;
	Uint32 color;
	int gender;//1 - male;0 - fenale
	s_rabbit* next;
}t_rabbit;

enum {
	MALE,
	FEMALE
};
enum {
	SEEK_FOR_WATER,
	SEEK_FOR_EAT,
	GOING_FOR_WATER,
	GOING_FOR_EAT,
	SEEK_FOR_COUPLE,
	GOING_FOR_COUPLE,
	WALKING,
	CHOSE_PATH_TO_WALK
};
//GENERAL
void drawLine(float x1, float y1, float x2, float y2, int w, int h, Uint32 color, Uint32* pixels);
void drawText(SDL_Color color, int x, int y, char* text, SDL_Renderer* renderer, TTF_Font* font);
char* intToStrint(int number);

//MAP
void generateTerrain(Uint32* terrain);
void clearMass(Uint32* pixels, Uint32* mask, int size, Uint32 color, float *grass);
void DrawCircle(int x, int y, int r, int w, int h, Uint32 color, Uint32* pixels);
void fillCircle(int x, int y, int r, int w, int h, Uint32 color, Uint32* pixels);
//RABBIT LIST
	//no mutation
void seekForCoupleWithoutMutation(t_rabbit* rabbit, t_rabbit** rabbits, int* count);
t_rabbit* createRabbitNoMutation(float x, float y, float speed, float thirst, float energy, float maxEnergy, float visibility, int maxAge, float procentToSearch, int gender);
void addNewRabbitNoMutation(t_rabbit** list, float x, float y, float speed, float maxEnergy, int maxAge, float procentToSearch, float visibility);
	//
void checkForDeleteRabbit(t_rabbit** rabbits, int* count);
void changeRabbitStatus(t_rabbit* rabbit);
void seekForWater(t_rabbit* rabbit, Uint32* pixels, Uint32* terrain);

void doAllInsideRabbit(t_rabbit* rabbit, Uint32* pixels, Uint32* terrain, float* grass);
void seekForCouple(t_rabbit* rabbit, t_rabbit** rabbits, int* count);

t_rabbit* createRabbit(float x, float y, float speed, float thirst, float energy, float maxEnergy, float visibility, int maxAge, float procentToSearch, int gender);
void addNewRabbit(t_rabbit** list, float x, float y, float speed, float maxEnergy, int maxAge, float procentToSearch, float visibility);
void deleteRabbitWithIndex(t_rabbit** list, int index);
void drawRabbits(t_rabbit* rabbit, Uint32* pixels, Uint32* terrain);
void forEachRabbit(t_rabbit** rabbits, void (*f)(t_rabbit*));
void changeDirection(t_rabbit* rabbit);
void checkForChangeDirection(t_rabbit* rabbit);
void moveRabbit(t_rabbit* rabbit);
void updateRabbit(t_rabbit* tmp, Uint32* pixels);
void moveRabbitTo(t_rabbit* rabbit, int x, int y); 
void seekForEat(t_rabbit* rabbit, Uint32* pixels);
#endif 
