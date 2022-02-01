#ifndef ERROR_LOG
#define ERROR_LOG

class IErrorLog{
  public:
    virtual bool openLog(const char *filename) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeError(const char *errorMessage) = 0;
    virtual ~IErrorLog() {}
};

#endif //ERROR_LOG