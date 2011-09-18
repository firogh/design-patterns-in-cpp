#include <string>
#include "static-class-singleton.h"

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::KLogFileName = "static-class-singleton-log.out";
bool Logger::initialized_ = false;
ofstream Logger::out_put_stream;
void Logger::Log(const string& KInMessage,const string& KInLogLevel)
{
     if(!initialized_){
          Init();
     }
      out_put_stream <<KInLogLevel<<":"<<KInMessage<<endl;
     
}
void Logger::Log(const vector<string>& KInMessage,const string& KInLogLevel)
{
     for (size_t i=0;i < KInMessage.size();i++)
          Log(KInMessage[i],KInLogLevel);
}
void Logger::TearDown()
{
     if(initialized_){
          out_put_stream.close();
          initialized_ = false;
     }
}
void Logger::Init()
{
     if(!initialized_){
          out_put_stream.open(KLogFileName,ios_base::app);
          if(!out_put_stream.good()){
               cerr << "Unable to initialize the logger!"<<endl;
               return;
          }
          initialized_ = true;
     }
}

