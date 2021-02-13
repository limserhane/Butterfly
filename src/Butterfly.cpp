#include <Butterfly/Butterfly.hpp>

#include <iostream>

namespace Butterfly
{

std::shared_ptr<Net> CreateNet(std::string pIdentifier)
{
	std::shared_ptr<Net> vLogger = std::make_shared<Net>();

	if(!pIdentifier.empty())
	{
		Registry::Instance().Add(pIdentifier, vLogger);
	}

	return vLogger;
}

std::shared_ptr<Logger> GetDefaultLogger()
{
	return Registry::Instance().GetDefaultLogger();
}

void SetDefaultLogger(std::shared_ptr<Logger> pLogger)
{
	return Registry::Instance().SetDefaultLogger(pLogger);
}

std::shared_ptr<Logger> Get(std::string pIdentifier)
{
	return Registry::Instance().Get(pIdentifier);
}

void Trace(std::string pTag, std::string pMessage)
{
	Registry::Instance().GetDefaultLogger()->Trace(pTag, pMessage);
}

void Error(std::string pTag, std::string pMessage)
{
	Registry::Instance().GetDefaultLogger()->Error(pTag, pMessage);
}

}