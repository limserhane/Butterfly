#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

/**
 * @brief An abstract class used to represent a logger used by Butterfly.
 */
class Logger
{
public :
	Logger();

	virtual ~ Logger();

	/**
	 * @brief Logs a record using this logger.
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource = Source()) = 0;

	/**
	 * @brief Logs a trace using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Trace(std::string pTag, std::string pMessage, Source pSource = Source()) final;

	/**
	 * @brief Logs an information using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Info(std::string pTag, std::string pMessage, Source pSource = Source()) final;

	/**
	 * @brief Logs a warning using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Warning(std::string pTag, std::string pMessage, Source pSource = Source()) final;

	/**
	 * @brief Logs an error using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Error(std::string pTag, std::string pMessage, Source pSource = Source()) final;

	/**
	 * @brief Logs a fatal error using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Fatal(std::string pTag, std::string pMessage, Source pSource = Source()) final;

	/**
	 * @brief Logs a debug information using this logger.
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Debug(std::string pTag, std::string pMessage, Source pSource = Source()) final;

}; 

} 