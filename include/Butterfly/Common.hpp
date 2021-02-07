#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <sstream>

namespace Butterfly
{

class Logger;
using LoggerPointer = std::shared_ptr<Logger>;
class Net;
using NetPointer = std::shared_ptr<Net>;

namespace Level
{

enum Value
{
	trace	= 0,
	info	= 1,
	warning	= 2,
	error	= 3,
	fatal	= 4,
	debug	= 5,
	n
}; // enum Value

constexpr const char* Names[] = { "trace", "info", "warning", "error", "fatal", "debug" };

std::string GetName(Level::Value pLevel);

} // namespace Level

namespace Utils
{

struct Source
{
	Source(std::string pFile, int pLine, std::string pFunction):
		File{pFile},
		Line{pLine},
		Function{pFunction}
	{}

	Source(const Source& other):
		File{other.File},
		Line{other.Line},
		Function{other.Function}
	{}

	std::string File;
	int Line;
	std::string Function;
};

} // namespace Utils

#define BFLY_SOURCE Utils::Source(__FILE__, __LINE__, __func__)

namespace Exceptions
{

std::string ExceptionFormat(Utils::Source pSource, std::string pDetails);

class Exception : public std::exception
{

public :
	Exception(Utils::Source pSource, std::string pDetails);
	const char* what() const throw();
protected :
	Exception(Utils::Source pSource, std::string pName, std::string pDetails);
	static const char* Format(Utils::Source pSource, std::string pName, std::string pDetails);
private :
	const char* mDescription;
}; // class Exception

template<class E>
void Throw(Utils::Source pSource, std::string pDetails)
{
	static_assert(std::is_base_of<std::exception, E>(), "E must be an std::exception");

	// throw(E(ExceptionFormat(pSource, pDetails)));
	std::cerr << static_cast<std::exception>(E(ExceptionFormat(pSource, pDetails))).what();
}

} // namespace Exceptions

#define BFLY_THROW(exception_type, pDetails) Exceptions::Throw<exception_type>(Utils::Source(__FILE__, __LINE__, __PRETTY_FUNCTION__), pDetails)

} // namespace Butterfly