#include <iostream>
#include <fstream>
#include <vector>
class Logger
{
public:
     static const std::string kLogLevelDebug;
     static const std::string kLogLevelInfo;
     static const std::string kLogLevelError;
     static void Log(const std::string & kInMessage, const std::string& KInLevel);
     static void Log(const std::vector< std::string >& KInMessages,const std::string& KInLevel);
     static void TearDown();
protected:
     static void Init();
     static const char* const KLogFileName;
     static bool  initialized_;
     static std::ofstream out_put_stream;
private:
     Logger(){}
};
     
