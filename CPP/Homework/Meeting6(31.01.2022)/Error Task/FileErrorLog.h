#ifndef FILE_LOG
#define FILE_LOG

#include "IErrorLog.h"
#include <fstream>

class FileErrorLog : public IErrorLog
{
  private:
    std::fstream file;
    std::string name;

  private:
    virtual bool openLog(const char *filename);
    virtual bool closeLog();

  public:
    FileErrorLog(const char *filename = "LOG.txt");
    virtual ~FileErrorLog();

  public:
    virtual bool writeError(const char *filename);
};

#endif //FILE_LOG