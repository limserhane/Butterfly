#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <sstream>

namespace Butterfly
{

class Logger;
// using LoggerPointer = std::shared_ptr<Logger>;
class Net;
// using NetPointer = std::shared_ptr<Net>;

namespace Level 
{

enum Value
{
	off		= -1,
	minimal = 0,
	trace	= 0,
	info	= 1,
	warning	= 2,
	error	= 3,
	fatal	= 4,
	debug	= 5,
	all	
};

}

std::string ToString(Level::Value pLevel);

struct Source
{
	Source(std::string pFile, int pLine, std::string pFunction, std::string pPrettyFunction);
	Source(const Source& other);

	std::string File;
	int Line;
	std::string Function;
	std::string PrettyFunction;

}; 

#define BFLY_SOURCE Source(__FILE__, __LINE__, __func__, __PRETTY_FUNCTION__)

class Exception : public std::exception
{
public :
	Exception(Source pSource, std::string pDetails);

	const char* what() const throw();

protected :
	static std::string Format(Source pSource, std::string pDetails);

private :
	std::string mDescription;

}; 

void ThrowException(Source pSource, std::string pDetails);
void PrintException(Source pSource, std::string pDetails);

} 