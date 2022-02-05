#ifndef EXC_H
#define EXC_H

#include <iostream>
#include <exception>

class GenericException : std::exception
{
private:
  std::string msg;

public:
  GenericException(std::string error = "GenericException caught") : msg(error) { }
  virtual ~GenericException() { std::cout << "GenericException destr" << std::endl; }

public:
  const char* what() const noexcept { return msg.c_str(); }
};

class Exception : public GenericException
{
public:
  Exception(std::string error = "Exception caught") : GenericException(error) {  }
  virtual ~Exception() { std::cout << "Exception destr" << std::endl; }
};

#endif // EXC_H