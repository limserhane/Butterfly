#pragma once

#include <Butterfly/Common.hpp>

#include <string>
#include <string_view>

namespace Butterfly
{

/**
 * @brief An abstract class used to represent a logger used by Butterfly.
 */
class Logger
{
public :
	Logger() = default;

	virtual ~ Logger() = default;

	/**
	 * @brief Logs a record using this logger.
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Log(Level::Value pLevel, std::string_view pTag, std::string_view pMessage) = 0;

	/**
	 * @brief Logs a trace using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Trace(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::trace, pTag, pMessage);
	}

	/**
	 * @brief Logs an information using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Info(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::info, pTag, pMessage);
	}

	/**
	 * @brief Logs a warning using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Warning(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::warning, pTag, pMessage);
	}

	/**
	 * @brief Logs an error using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Error(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::error, pTag, pMessage);
	}

	/**
	 * @brief Logs a fatal error using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Fatal(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::fatal, pTag, pMessage);
	}

	/**
	 * @brief Logs a debug information using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Debug(std::string_view pTag, std::string_view pMessage) final
	{
		Log(Level::debug, pTag, pMessage);
	}

}; 

} 