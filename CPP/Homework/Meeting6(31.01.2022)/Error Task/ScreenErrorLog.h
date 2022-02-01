#ifndef SCREEN_LOG
#define SCREEN_LOG

#include "FileErrorLog.h"

class ScreenErrorLog : public FileErrorLog
{
  private:
    virtual bool openLog(const char *filename) { return true; }
    virtual bool closeLog() { return true; }

  public:
    ScreenErrorLog();
    virtual ~ScreenErrorLog();

  public:
    virtual bool writeError(const char *message);
};

#endif //SCREEN_LOG