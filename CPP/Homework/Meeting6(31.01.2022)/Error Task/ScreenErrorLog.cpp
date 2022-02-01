#include "ScreenErrorLog.h"
#include <fstream>
#include <iostream>
#include <string>

bool ScreenErrorLog::writeError(const char *message)
{
  std::cout << message << std::endl;

  return true;
}

ScreenErrorLog::ScreenErrorLog() : FileErrorLog() 
{
  std::cout << "Screen constructor" << std::endl;
}

ScreenErrorLog::~ScreenErrorLog() 
{
  std::cout << "Screen destructor" << std::endl;
}