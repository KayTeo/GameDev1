using namespace std;
#include <SDL.h>
#include <glew.h>
#include "MainGame.h"
#include<iostream>
#include<gl/GL.h>

int main(int argc, char* args[]){
	MainGame mainGame;
	mainGame.run();

	return 0;
}