#ifndef SDLHELPERS_HPP
#define SDLHELPERS_HPP


#include <SDL2/SDL.h>
#include <vector>
#include <string>


using std::vector;
using std::string;

extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern vector<SDL_Texture*> textures;

bool initializeSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
void closeSDL();
SDL_Texture *loadTexture(string pathToFile);

#endif // SDLHELPERS_HPP