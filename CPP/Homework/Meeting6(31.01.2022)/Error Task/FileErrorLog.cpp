#include "FileErrorLog.h"
#include <iostream>
#include <fstream>
#include <ios>

bool FileErrorLog::openLog(const char *filename)
{
  name = filename;

  file.open(filename, std::ios::out);

  return true;
}

bool FileErrorLog::closeLog()
{ 
  file.close();

  return true;
}

bool FileErrorLog::writeError(const char *errorMessage)
{
  if(file.is_open())
  {
    file << errorMessage;
    return true;
  }

  return false;
}

FileErrorLog::FileErrorLog(const char *filename)
{
  std::cout << "File constructor" << std::endl;
  openLog(filename);
}

FileErrorLog::~FileErrorLog() 
{
  std::cout << "File destructor" << std::endl;
  closeLog();
}