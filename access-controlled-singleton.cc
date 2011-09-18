/*
 * access-controlled-singleton.cc
 *
 *  Created on: Sep 17, 2011
 *      Author: firo
 */
#include "access-controlled-singleton.h"
#include <fstream>
const std::string ACSLogger::kLoggerLevelDebug = "DEBUG";
const std::string ACSLogger::kLoggerLevelInfo = "INFO";
const std::string ACSLogger::kLoggerLevelError = "ERROR";
const char * const ACSLogger::kLogFileName = "ACS-log.out";
ACSLogger ACSLogger::acslogger;
ACSLogger & ACSLogger::get_instance()
{
	return acslogger;
}

ACSLogger::ACSLogger()
{
	out_put_file.open(kLogFileName,std::ios_base::app);
	if(!out_put_file.good())
	{
		std::cerr<<"Unable to open log file"<<std::endl;
		//exit(1);
	}
}
ACSLogger::~ACSLogger()
{
	out_put_file.close();
}
void ACSLogger::log(const std::vector<std::string> &kInMessages,const std::string& kInLoggerLevel)
{
	for(int i=0;i<kInMessages.size();i++)
	{
		out_put_file<<kInMessages[i]<<":"<<kInLoggerLevel<<std::endl;
	}
}
void ACSLogger::log(const std::string& kInLoggerLevel,const std::string& kInMessage)
{
	out_put_file<<kInLoggerLevel<<":"<<kInMessage<<std::endl;
}
