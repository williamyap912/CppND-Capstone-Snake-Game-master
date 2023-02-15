#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <memory>
#include <vector>
#include "SDL.h"
#include "snake.h"
#include "text.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(std::unique_ptr<int> &highest_score , int score , Snake const snake , SDL_Point const &food , Text &text);
  void RenderPause(std::unique_ptr<int> &highest_score , int score , Snake const snake , SDL_Point const &food , Text &text);
  void UpdateWindowTitle(int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture *texture;
  SDL_Rect position;
  TTF_Font *font;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif