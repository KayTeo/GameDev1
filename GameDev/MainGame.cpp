using namespace std;
#include "MainGame.h"
#include<iostream>
#include<string>
#include<glew.h>
#include<gl/GL.h>

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void fatalError(string errorString) {
		cout << "SDL Window could not be created:" << errorString << endl;
		cout << "Enter any key to quit...";
		int tmp;
		cin >> tmp;
		SDL_Quit();
}
void MainGame::run() {
	initSystems();

	gameLoop();
}

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	//Create GL context that holds all GL - VBO et cetera
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialise glew!");
	}

	//Tell GL to double buffer - have 2 windows instead of 1
	//When clear window - it switches between to prevent flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	//Set background color when screen is cleared - RGB alpha - range 0 - 1
	glClearColor(0, 0, 1, 1.0);
}

void MainGame::gameLoop() {
	while (_gameState != GameState::EXIT) {
		processInput();
		drawGame();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << evnt.motion.x << " " << evnt.motion.y << "" << endl;
		}
	}
}

void MainGame::drawGame() {

}