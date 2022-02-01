#include "IErrorLog.h"
#include "FileErrorLog.h"
#include "ScreenErrorLog.h"
#include <fstream>
#include <string>

int main(void)
{
  FileErrorLog fl;

  fl.writeError("Not enough characters!\n");

  ScreenErrorLog sl;

  sl.writeError("Not enough characters!\n");

  return 0;
}