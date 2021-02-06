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
		return;
	}
	mLoggers.push_back(pLogger);
}

void Net::Remove(size_t pPosition)
{
	mLoggers.erase(mLoggers.begin() + pPosition);
}

} // namespace Butterfly