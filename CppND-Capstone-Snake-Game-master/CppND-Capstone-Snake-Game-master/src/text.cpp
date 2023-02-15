#include "text.h"
#include <iostream>
#include <string>

using std::string;

void Text::TextSetup(SDL_Renderer* renderer , TTF_Font* font , string text , int x , int y , SDL_Color color) {
  
  if (font == nullptr){
    std::cerr << "TTF Font could not be loaded.\n";
    std::cerr << "TTF_Error: " << SDL_GetError() << "\n";
  }
        
  this->color = color;
  this->font = font;
  this->renderer = renderer;
  this->text = text;
  
  SDL_DestroyTexture(texture);
  
  surface = TTF_RenderText_Solid(font, text.c_str(), color);
  
  if (surface==NULL) {
    printf("Failed to create surface from text: %s", SDL_GetError());            
  }
  
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  
  SDL_FreeSurface(surface);
  
  //Setup the destination rectangle
  position.x = x;
  position.y = y;
  
  //Query the texture to get its width and height to use
  SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
  SDL_RenderCopy(renderer, texture, NULL, &position);
  
}

void Text::TextDest() {
  SDL_DestroyTexture(texture);
}