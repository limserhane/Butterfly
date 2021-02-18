#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <string_view>

namespace butterfly
{

class logger;
// using LoggerPointer = std::shared_ptr<logger>;
class net;
// using NetPointer = std::shared_ptr<net>;

namespace level 
{

/**
 * @brief The severity levels of the logs.
 */
enum value
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

static constexpr const char* names[] = { "trace", "info", "warning", "error", "fatal", "debug" };

}
/**
 * @brief Converts a level value into its string representation.
 * @param p_level The level value to be converted;
 * @return The string representation of \p p_level
 */
inline std::string to_string(level::value p_level)
{
	if(level::minimal <= p_level && p_level < level::off)
		return level::names[p_level];
	return "";
}

/**
 * @brief A structure containing informations about a location in the source code.
 */
struct source
{
	source();
	source(std::string p_file, int p_line, std::string p_function, std::string p_pretty_function);
	source(const source& p_other);

	std::string file;
	int line;
	std::string function;
	std::string pretty_function;

}; 

/**
 * @brief The available patterns for log records.
 */
enum class pattern
{
	none, // MESSAGE
	minimal, // [TAG] MESSAGE
	report, // [LEVEL] MESSAGE
	simple, // [LEVEL] [TAG] MESSAGE
	complete, // [YYYY-mm-dd HH:MM:SS] [LEVEL] [TAG] MESSAGE
};

/**
 * @brief A basic exception used by butterfly.
 */
class exception : public std::exception
{
public :
	exception(source p_source, std::string p_details);

	const char* what() const throw();

protected :
	static std::string format(source p_source, std::string p_details);

private :
	std::string m_description;

}; 

/**
 * @brief Throws an exception.
 * @param p_source The location of the exception;
 * @param pDetails details about the exception;
 */
void throw_exception(source p_source, std::string p_details);

/**
 * @brief Writes an exception on the standard output for errors.
 * @param p_source The location of the exception;
 * @param p_details details about the exception;
 */
void print_exception(source p_source, std::string p_details);

} 

#if _MSC_VER
#define BFLY_SOURCE butterfly::source(__FILE__, __LINE__, __func__, __FUNCSIG__)
#else
#define BFLY_SOURCE butterfly::source(__FILE__, __LINE__, __func__, __PRETTY_FUNCTION__)
#endif