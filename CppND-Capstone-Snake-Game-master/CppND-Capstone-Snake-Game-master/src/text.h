#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SDL.h"

using std::string;

class Text {
  public:
  
  SDL_Texture *texture = NULL;
  SDL_Rect position;
  TTF_Font *font;
  SDL_Renderer *renderer;
  SDL_Color color;
  string text;
  SDL_Surface* surface;
    
  void TextSetup(SDL_Renderer* renderer , TTF_Font* font , string text , int x , int y , SDL_Color color);
  void TextDest();
    
};

#endif