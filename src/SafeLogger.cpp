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

} 