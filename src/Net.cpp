#include <Butterfly/Net.hpp>

namespace Butterfly
{

Net::Net():
	Logger{}
{}

Net::Net(std::string pName):
	Logger{pName}
{}

Net::~Net()
{}

void Net::Log(Level::Value pLevel, std::string pMessage) const
{
	for (LoggerPointer logger : mLoggers)
	{
		logger->Log(pLevel, pMessage);
	}
}

void Net::Add(LoggerPointer pLogger)
{
	if(!pLogger)
	{
		ThrowException(BFLY_SOURCE, "Invalid argument, LoggerPointer is nullptr");
		return ;
	}

	mLoggers.push_back(pLogger);
}

void Net::Remove(size_t pPosition)
{
	if(pPosition >= mLoggers.size())
	{
		ThrowException(BFLY_SOURCE, "Out of range position, attempted to remove Logger at unavailable position");
		return ;
	}

	mLoggers.erase(mLoggers.begin() + pPosition);
}

} 