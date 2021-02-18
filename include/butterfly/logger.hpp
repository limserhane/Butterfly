#pragma once

#include <butterfly/common.hpp>

#include <string>
#include <string_view>

namespace butterfly
{

/**
 * @brief An abstract class used to represent a logger used by butterfly.
 */
class logger
{
public :
	logger() = default;

	virtual ~logger() = default;

	/**
	 * @brief Logs a record using this logger.
	 * @param p_level The level to be logged;
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	virtual void log(level::value p_level, std::string_view p_tag, std::string_view p_message) = 0;

	/**
	 * @brief Logs a trace using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void trace(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::trace, p_tag, p_message);
	}

	/**
	 * @brief Logs an information using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void info(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::info, p_tag, p_message);
	}

	/**
	 * @brief Logs a warning using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void warning(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::warning, p_tag, p_message);
	}

	/**
	 * @brief Logs an error using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void error(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::error, p_tag, p_message);
	}

	/**
	 * @brief Logs a fatal error using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void fatal(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::fatal, p_tag, p_message);
	}

	/**
	 * @brief Logs a debug information using this logger.
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 */
	inline virtual void debug(std::string_view p_tag, std::string_view p_message) final
	{
		log(level::debug, p_tag, p_message);
	}

}; 

} 