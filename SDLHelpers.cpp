#include "SDLHelpers.hpp"
#include <iostream>
#include <string>

using std::string;

SDL_Renderer *renderer = nullptr;
SDL_Window *window = nullptr;
vector<SDL_Texture *> textures;

bool initializeSDL(const int SCREEN_WIDTH, const int SCREEN_HEIGHT) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Magic: The Gathering", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    for (auto texture : textures) {
        SDL_DestroyTexture(texture);
    }

    SDL_Quit();
}

SDL_Texture* loadTexture(string pathToFile) {

    SDL_Surface* surface = SDL_LoadBMP(pathToFile.c_str());
    if (!surface) {
        throw std::runtime_error("Failed to load BMP file: " + std::string(SDL_GetError()));
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        throw std::runtime_error("Failed to create texture from surface: " + std::string(SDL_GetError()));
    }

    textures.push_back(texture); // Add to the textures vector for later management
    return texture;
}