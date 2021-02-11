#include <Butterfly/Net.hpp>

namespace Butterfly
{

Net::Net(std::string pName):
	Logger{pName}
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

void Net::Remove(size_t pPosition)
{
	if(pPosition >= mLoggers.size())
	{
		ThrowException(BFLY_SOURCE, "Out of range, pPosition is invalid position");
		return ;
	}

	mLoggers.erase(mLoggers.begin() + pPosition);
}

} 