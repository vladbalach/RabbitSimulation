#include "header.h"
int main(int argc, char *argv[]) {
	bool running = true;
	int xGraph = 0;
	Uint32 drawColor = COLOR_GRASS;
	int countOffRabbits = 0;
	int countOffRabbitsWM = 0;
	bool mouseLeftDown = false;
	int prevXDraw;
	int prevYDraw;
	float summSpeed =0;
	float summMaxAge =0;
	float summVisibility =0;
	float summMaxEnergy = 0;
	float summProcentToSearch = 0;
	float scale = 1;
	int tick = 0;
	bool aPressed = false;
	bool fPressed = false;
	srand(time(0));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error Init!");
		exit(1);
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	t_rabbit* rabbits = 0;
	t_rabbit* rabbitsNoMutaion = 0;
	SDL_Window* window = SDL_CreateWindow("Ecosystem", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTHPIX_WINDOW, HEIGHTPIX_WINDOW, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	TTF_Font* font = TTF_OpenFont("fonts/OpenSans-Bold.ttf", 36);
	if (font == 0) {
		printf("%s", TTF_GetError());
		exit(1);
	}
	Uint32* pixels_Info = (Uint32*)malloc(sizeof(Uint32) * WIDTHPIX_INFO * HEIGHTPIX_INFO);
	for (int i = 0; i < WIDTHPIX_INFO * HEIGHTPIX_INFO; i++) 
		* (pixels_Info + i) = COLOR_INFO_WINDOW;


	Uint32* pixels_Game = (Uint32*)malloc(sizeof(Uint32) * WIDTHPIX_GAME * HEIGHTPIX_GAME);
	for (int i = 0; i < WIDTHPIX_GAME * HEIGHTPIX_GAME; i++) 
		* (pixels_Game + i) = COLOR_GAME_WINDOW;

	float* grass = (float*)malloc(sizeof(float) * WIDTHPIX_GAME * HEIGHTPIX_GAME);
	for (int i = 0; i < WIDTHPIX_GAME * HEIGHTPIX_GAME; i++)
		* (grass + i) = 255;

	Uint32* pixels_GameTerrain = (Uint32*)malloc(sizeof(Uint32) * WIDTHPIX_GAME * HEIGHTPIX_GAME);
	for (int i = 0; i < WIDTHPIX_GAME * HEIGHTPIX_GAME; i++)
		* (pixels_GameTerrain + i) = COLOR_GAME_WINDOW;

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, WIDTHPIX_WINDOW, HEIGHTPIX_WINDOW);
	SDL_Rect rectGame = { WIDTHPIX_INFO , 0, WIDTHPIX_GAME , HEIGHTPIX_GAME };
	SDL_Rect rectInfo = { 0 , 0, WIDTHPIX_INFO , HEIGHTPIX_INFO };
	SDL_Color color = { 0,255,0,0 };
	
	for (int i = 0; i < 720; i++) {
		addNewRabbit(&rabbits, rand() % 700, rand() % 700, 0.7, 700, 8000, 0.7, 16);
			//addNewRabbitNoMutation(&rabbitsNoMutation, rand() % 500  , rand() % 500, 0.7, 700, 8000, 0.7, 16);
			countOffRabbits++;
			//countOffRabbitsWM++;
	}
	generateTerrain(pixels_GameTerrain);
	//addNewRabbit(&rabbits, 100, 100, 20, 20);
	while (running) {
		
		clock_t startCycle = clock();
		clearMass(pixels_Game, pixels_GameTerrain,  WIDTHPIX_GAME * HEIGHTPIX_GAME, COLOR_GAME_WINDOW, grass);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (aPressed) {
					addNewRabbit(&rabbits, event.button.x + WIDTHPIX_INFO, event.button.y, summSpeed / countOffRabbits, summMaxEnergy / countOffRabbits, summMaxAge / countOffRabbits, summProcentToSearch / countOffRabbits, 15);
					countOffRabbits++;
				} else
				if (event.button.button == SDL_BUTTON_LEFT) {
					mouseLeftDown = true;
					prevXDraw = event.button.x - WIDTHPIX_INFO;
					prevYDraw = event.button.y;
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					mouseLeftDown = false;
				}
			}
			if (event.type == SDL_MOUSEMOTION) {
				//printf("%d\n", (event.motion.x - WIDTHPIX_INFO));
				if (mouseLeftDown)
				{
					if (drawColor == COLOR_GAME_WINDOW) {
						fillCircle((event.motion.x - WIDTHPIX_INFO), event.motion.y, 10, WIDTHPIX_GAME, HEIGHTPIX_GAME, 0, (Uint32*)grass);
						fillCircle((event.motion.x - WIDTHPIX_INFO), event.motion.y, 10, WIDTHPIX_GAME, HEIGHTPIX_GAME, drawColor, pixels_GameTerrain);
					}
					else
					{
						drawLine((event.motion.x - WIDTHPIX_INFO), event.motion.y, prevXDraw, prevYDraw, WIDTHPIX_GAME, HEIGHTPIX_GAME, drawColor, pixels_GameTerrain);
						//*(pixels_Game + event.motion.y * WIDTHPIX_GAME + (event.motion.x - WIDTHPIX_INFO)) = drawColor;
					}
					prevXDraw = (event.motion.x - WIDTHPIX_INFO);
					prevYDraw = event.motion.y;

				}
			}
			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				if (event.key.keysym.sym == SDLK_r) {
					drawColor = COLOR_RIVER;
				}
				if (event.key.keysym.sym == SDLK_g) {
					drawColor = COLOR_GRASS;
				}
				if (event.key.keysym.sym == SDLK_c) {
					drawColor =COLOR_GAME_WINDOW;
				}
				if (event.key.keysym.sym == SDLK_a) {
					aPressed = !aPressed;
	
					
				}
				if (event.key.keysym.sym == SDLK_n) {
					for (int i = 0; i < 100; i++) {
						addNewRabbitNoMutation(&rabbitsNoMutaion, rand() % 500, rand() % 500, 0.7, 700, 8000, 0.7, 16);
						countOffRabbitsWM++;
					}
				}
				if (event.key.keysym.sym == SDLK_f) {
					for (int i = 0; i < HEIGHTPIX_GAME * WIDTHPIX_GAME; i++) {
						*(pixels_GameTerrain + i) = COLOR_GAME_WINDOW;
						*(grass + i) = 0;
					}
				}
			}
		}

		summSpeed = 0;
		summMaxAge = 0;
		summVisibility = 0;
		summMaxEnergy = 0;
		summProcentToSearch = 0;
		//UPDATE RABBITS NO MUTATION
		t_rabbit* tmp2 = rabbitsNoMutaion;
		while (tmp2) {
			tmp2->energy -= 0.1;
			tmp2->age++;
			tmp2->timeAfterDividing++;
			//tmp->thirst--;
			checkForChangeDirection(tmp2);
			moveRabbit(tmp2);
			doAllInsideRabbit(tmp2, pixels_Game, pixels_GameTerrain, grass);
			//SEEK FOR COUPLE and divide
			if (tmp2->status == SEEK_FOR_COUPLE) {
				changeRabbitStatus(tmp2);
				if (tmp2->status == SEEK_FOR_COUPLE) {
					seekForCoupleWithoutMutation(tmp2, &rabbitsNoMutaion, &countOffRabbitsWM);
				}
			}
			if (tmp2->status == CHOSE_PATH_TO_WALK) {
				changeDirection(tmp2);
				tmp2->status = WALKING;
			}
			if (tmp2->status == WALKING) {
				changeRabbitStatus(tmp2);
			}
			if (tmp2->status == SEEK_FOR_WATER) {
				seekForWater(tmp2, pixels_Game, pixels_GameTerrain);
			}
			else if (tmp2->status == SEEK_FOR_EAT) {
				seekForEat(tmp2, pixels_Game);
			}
			tmp2 = tmp2->next;
		}
		///UPDATE RABBIT
		t_rabbit* tmp = rabbits;
		while (tmp) {
			tmp->energy -= 0.1;
			tmp->age++;
			tmp->timeAfterDividing++;
			//tmp->thirst--;
			checkForChangeDirection(tmp);
			moveRabbit(tmp);
			doAllInsideRabbit(tmp, pixels_Game, pixels_GameTerrain, grass);
			//SEEK FOR COUPLE and divide
			if (tmp->status == SEEK_FOR_COUPLE) {
				changeRabbitStatus(tmp);
				if (tmp->status == SEEK_FOR_COUPLE) {
					seekForCouple(tmp, &rabbits, &countOffRabbits);
				}
			}
			if (tmp->status == CHOSE_PATH_TO_WALK) {
				changeDirection(tmp);
				tmp->status = WALKING;
			}
			if (tmp->status == WALKING) {
				changeRabbitStatus(tmp);
			}
			if (tmp->status == SEEK_FOR_WATER) {
				seekForWater(tmp, pixels_Game, pixels_GameTerrain);
			}
			else if (tmp->status == SEEK_FOR_EAT) {
				seekForEat(tmp, pixels_Game);
			}

			
			//DRAW RABBIT
				
			summSpeed += tmp->speed;
			summMaxAge += tmp->maxAge;
			summMaxEnergy += tmp->maxEnergy;
			summVisibility += tmp->visibility;
			summProcentToSearch += tmp->procentToSearch;
			tmp = tmp->next;

	}


		/////////////////
		
		////Draw graph
		if (countOffRabbits > scale * HEIGHTPIX_INFO) {
			scale *= 1.5;
		}
		if (xGraph < WIDTHPIX_INFO)
		{
			*(pixels_Info + countOffRabbits * WIDTHPIX_INFO + xGraph) = -1;
			xGraph++;
		}
		else {

			for (int i = 0; i < HEIGHTPIX_INFO; i++) {
				for (int j = 0; j < WIDTHPIX_INFO - 1; j++) {
					*(pixels_Info + i * WIDTHPIX_INFO + j) = *(pixels_Info + i * WIDTHPIX_INFO + j + 1);
				}
				*(pixels_Info + i * WIDTHPIX_INFO + WIDTHPIX_INFO - 1) = COLOR_INFO_WINDOW;
			} 
			if (countOffRabbits > scale * HEIGHTPIX_INFO) {
				scale *= 1.5;
				if (countOffRabbits > scale * HEIGHTPIX_INFO) {
					scale *= 1.5;
					if (countOffRabbits > scale * HEIGHTPIX_INFO) {
						scale *= 1.5;
					}
				}
			}
			*(pixels_Info + (int)((float)countOffRabbits / scale) * WIDTHPIX_INFO + xGraph - 1) = -1;
		}
		
		////
		checkForDeleteRabbit(&rabbits, &countOffRabbits);
		checkForDeleteRabbit(&rabbitsNoMutaion, &countOffRabbitsWM);
		SDL_UpdateTexture(texture, &rectInfo, pixels_Info, WIDTHPIX_INFO * sizeof(Uint32));
		SDL_UpdateTexture(texture, &rectGame, pixels_Game, WIDTHPIX_GAME * sizeof(Uint32));
		SDL_RenderCopy(renderer, texture, NULL, NULL);

		/*(char* str = intToStrint((int)(summSpeed * 100 / countOffRabbits));
		drawText({ 0,255,0,0 }, 100, 200, str, renderer, font);
		free(str);
		str = intToStrint((int)(summVisibility * 100 / countOffRabbits));
		drawText({ 0,255,0,0 }, 100, 280, str, renderer, font);
		free(str);
		str = intToStrint((int)(summMaxAge / countOffRabbits));
		drawText({ 0,255,0,0 }, 100, 360, str, renderer, font);
		free(str);
		str = intToStrint((int)(summMaxEnergy / countOffRabbits));
		drawText({ 0,255,0,0 }, 100, 440, str, renderer, font);
		free(str);
		str = intToStrint((int)(summProcentToSearch * 100 / countOffRabbits));
		drawText({ 0,255,0,0 }, 100, 520, str, renderer, font);
		free(str);
		//str = intToStrint((int)rabbits->energy);
		//drawText({255,255,0,0}, 100, 550, str, renderer, font);
		//free(str);*/
		printf("%d | %d | %d | %d | %0.2f | %0.2f | %0.2f | %0.2f | %0.2f\n", (clock() - startCycle), tick++, countOffRabbits, countOffRabbitsWM, summSpeed/countOffRabbits, summVisibility/countOffRabbits, summMaxAge/countOffRabbits, summMaxEnergy/countOffRabbits, summProcentToSearch/countOffRabbits);
		SDL_RenderPresent(renderer);
		//SDL_Delay(20);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}