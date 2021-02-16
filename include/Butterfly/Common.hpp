#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <string_view>

namespace Butterfly
{

class Logger;
// using LoggerPointer = std::shared_ptr<Logger>;
class Net;
// using NetPointer = std::shared_ptr<Net>;

namespace Level 
{

/**
 * @brief The severity levels of the logs.
 */
enum Value
{
	all		= -1, // The level used to specify that a logger must not log anything;
	minimal = 0, // The minimal level that logs can have;
	trace	= 0, // The level of a trace;
	info	= 1, // The level of an info;
	warning	= 2, // The level of a warning;
	error	= 3, // The level of an error;
	fatal	= 4, // The level of a fatal error;
	debug	= 5, // The level of a debug log;
	off			 // The level used to specify that a logger must log everything;
};

static constexpr const char* Names[] = { "trace", "info", "warning", "error", "fatal", "debug" };

}
/**
 * @brief Converts a Level value into its string representation.
 * @param pLevel The level value to be converted;
 * @return The string representation of \p pLevel
 */
inline std::string ToString(Level::Value pLevel)
{
	if(Level::minimal <= pLevel && pLevel < Level::off)
		return Level::Names[pLevel];
	return "";
}

/**
 * @brief A structure containing informations about a location in the source code.
 */
struct Source
{
	Source();
	Source(std::string pFile, int pLine, std::string pFunction, std::string pPrettyFunction);
	Source(const Source& other);

	std::string File;
	int Line;
	std::string Function;
	std::string PrettyFunction;

}; 

/**
 * @brief A basic exception used by Butterfly.
 */
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

/**
 * @brief Throws an exception.
 * @param pSource The location of the exception;
 * @param pDetails Details about the exception;
 */
void ThrowException(Source pSource, std::string pDetails);

/**
 * @brief Writes an exception on the standard output for errors.
 * @param pSource The location of the exception;
 * @param pDetails Details about the exception;
 */
void PrintException(Source pSource, std::string pDetails);

} 

#define BFLY_SOURCE Butterfly::Source(__FILE__, __LINE__, __func__, __PRETTY_FUNCTION__)