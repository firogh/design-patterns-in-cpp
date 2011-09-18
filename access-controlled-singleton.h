/*
 * access-controlled-singleton.h
 *
 *  Created on: Sep 17, 2011
 *      Author: firo
 */

#ifndef ACCESS_CONTROLLED_SINGLETON_H_
#define ACCESS_CONTROLLED_SINGLETON_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
class ACSLogger
{
public:
	static const std::string kLoggerLevelDebug;
	static const std::string kLoggerLevelInfo;
	static const std::string kLoggerLevelError;

	static ACSLogger& get_instance();
	void log(const std::string & kInLoggerLevel,const std::string& kInMessage);
	void log(const std::vector<std::string >& kInMessage,const std::string & kInLoggerLevel);
private:
	ACSLogger();
	~ACSLogger();
	static const char * const kLogFileName;
	std::ofstream out_put_file;
	static ACSLogger acslogger;
};

#endif /* ACCESS_CONTROLED_SINGLETON_H_ */
