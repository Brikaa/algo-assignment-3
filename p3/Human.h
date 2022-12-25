#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human {
public:
  bool isActive;
  std::string type;
  Human(){isActive = true;}
  ~Human(){;};
};

#endif
