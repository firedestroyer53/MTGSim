#ifndef SDLHELPERS_HPP
#define SDLHELPERS_HPP


#include <SDL2/SDL.h>
#include <vector>
#include <string>


using std::vector;
using std::string;

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;
vector<SDL_Texture*> textures;

bool initializeSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
void closeSDL();
SDL_Texture *loadTexture(string pathToFile);

#endif // SDLHELPERS_HPP