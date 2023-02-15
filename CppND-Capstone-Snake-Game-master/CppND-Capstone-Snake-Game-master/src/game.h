#ifndef GAME_H
#define GAME_H

#include <memory>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "text.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  
  int GetScore() const;
  int GetSize() const;
  std::unique_ptr<int> GetHighestScore(Controller &controller);

 private:
  Snake snake;
  SDL_Point food;
  Text text;
  Controller controller;
  std::unique_ptr<int> prev_score;
  std::unique_ptr<int> current_score;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
    
  void PlaceFood();
  void Update();
  void UpdateNew(Controller &controller);
};

#endif