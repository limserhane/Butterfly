#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>

#include <mutex>

namespace Butterfly
{

/**
 * @brief A decorator for a logger used to ensure the thread-safety log operations on the decorated logger.
 */
class SafeLogger : public Logger
{
public :
	SafeLogger(std::shared_ptr<Logger> pWing);

	~SafeLogger();

	/**
	 * @brief Safely (from concurrent accesses) logs a record using the decorated logger
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage) override
	{
		std::unique_lock<std::mutex> lLock(mMutex);

		mLogger->Log(pLevel, pTag, pMessage);	
	}

private :
	std::shared_ptr<Logger> mLogger;
	std::mutex mMutex;

};

} 