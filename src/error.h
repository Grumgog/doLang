#ifndef ERROR_H
#define ERROR_H

class Error{
 public:
  std::string getMessage() = 0;
  void raise(std::string message, int code);
};

#endif
