#include <Butterfly/Net.hpp>

#include <algorithm>

namespace Butterfly
{

Net::Net():
	Logger()
{}

Net::~Net()
{}

void Net::Log(Level::Value pLevel, std::string pTag, std::string pMessage)
{
	for (std::shared_ptr<Logger> logger : mLoggers)
	{
		logger->Log(pLevel, pTag, pMessage);
	}
}

void Net::Add(std::shared_ptr<Logger> pLogger)
{
	if(!pLogger)
	{
		PrintException(BFLY_SOURCE, "inval argument, pLogger is nullptr");
		return ;
	}

	mLoggers.push_back(pLogger);
}

void Net::Remove(std::shared_ptr<Logger> pLogger)
{
	if(!pLogger)
	{
		PrintException(BFLY_SOURCE, "invalid argument, pLogger is nullptr");
		return ;
	}

	std::vector<std::shared_ptr<Logger>>::iterator vLoggerIterator = std::find(mLoggers.begin(), mLoggers.end(), pLogger);

	if(vLoggerIterator == mLoggers.end())
	{
		PrintException(BFLY_SOURCE, "invalid argument, pLogger not found");
		return ;
	}

	mLoggers.erase(vLoggerIterator);
}

} 