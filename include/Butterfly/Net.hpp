#pragma once

#include <Butterfly/Logger.hpp>
#include <Butterfly/Common.hpp>

#include <string>
#include <vector>

namespace Butterfly
{

/**
 * @brief A logger used as a parent for other loggers.
 */
class Net : public Logger
{
public :
	Net();
	Net(std::initializer_list<std::shared_ptr<Logger>> pLoggers);

	virtual ~Net();

	/**
	 * @brief Logs a record using each one of its children.
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage) override
	{
		for (std::shared_ptr<Logger> logger : mLoggers)
		{
			logger->Log(pLevel, pTag, pMessage);
		}
	}

	/**
	 * @brief Adds a logger as its child.
	 * @param pLogger If not nullptr, the child to be added;
	 */
	void Add(std::shared_ptr<Logger> pLogger);

	/**
	 * @brief Adds a list of loggers as its children.
	 * @param pLogger The list of loggers to be added;
	 */
	void Add(std::initializer_list<std::shared_ptr<Logger>> pLoggers);


	/**
	 * @brief Removes a logger from its children.
	 * @param pLogger The logger to be removed;
	 */
	void Remove(std::shared_ptr<Logger> pLogger);

private :
	std::vector<std::shared_ptr<Logger>> mLoggers;

}; 

} 