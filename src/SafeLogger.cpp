#include <Butterfly/SafeLogger.hpp>


namespace Butterfly
{
SafeLogger::SafeLogger(std::shared_ptr<Logger> pLogger):
	Logger(),
	mLogger(pLogger),
	mMutex()
{}

SafeLogger::~SafeLogger()
{}

void SafeLogger::Log(Level::Value pLevel, std::string pTag, std::string pMessage)
{
	std::unique_lock<std::mutex> lLock(mMutex);

	mLogger->Log(pLevel, pTag, pMessage);	
}

} 