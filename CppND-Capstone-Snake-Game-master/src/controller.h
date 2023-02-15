#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"


class Controller {
 public:
  void HandleInput(bool &NewGame,bool &pause, bool &running, Snake &snake) const;
  bool pause;
  bool NewGame;
  
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif