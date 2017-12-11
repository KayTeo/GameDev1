#pragma once
#include<SDL.h>
#include<glew.h>
#include<gl\GL.h>
#include<Windows.h>

#pragma comment(lib, "glew32.lib")
enum class GameState {PLAY, EXIT};

class MainGame
{
public:

	MainGame();
	~MainGame();

	void run();
private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;
};

