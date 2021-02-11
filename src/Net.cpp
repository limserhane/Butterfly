#include <Butterfly/Net.hpp>

#include <algorithm>

namespace Butterfly
{

Net::Net():
	Logger()
{}

Net::~Net()
{}

void Net::Log(Level::Value pLevel, std::string pMessage)
{
	for (std::shared_ptr<Logger> logger : mLoggers)
	{
		logger->Log(pLevel, pMessage);
	}
}

void Net::Add(std::shared_ptr<Logger> pLogger)
{
	if(!pLogger)
	{
		ThrowException(BFLY_SOURCE, "Invalid argument, pLogger is nullptr");
		return ;
	}

	mLoggers.push_back(pLogger);
}

void Net::Remove(std::shared_ptr<Logger> pLogger)
{
	if(pLogger == nullptr)
	{
		ThrowException(BFLY_SOURCE, "Invalid argument, pLogger is nullptr");
		return ;
	}

	std::vector<std::shared_ptr<Logger>>::iterator vLoggerIterator = std::find(mLoggers.begin(), mLoggers.end(), pLogger);

	if(vLoggerIterator == mLoggers.end())
	{
		ThrowException(BFLY_SOURCE, "pLogger not found");
		return ;
	}

	mLoggers.erase(vLoggerIterator);
}

} 