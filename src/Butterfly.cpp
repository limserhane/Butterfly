#include <Butterfly/Butterfly.hpp>

#include <iostream>

namespace Butterfly
{

std::shared_ptr<Net> CreateNet(std::string pIdentifier)
{
	std::shared_ptr<Net> logger = std::make_shared<Net>();
	return logger;
}

std::shared_ptr<Logger> GetDefaultLogger()
{
	return Registry::Instance().GetDefaultLogger();
}

void SetDefaultLogger(std::shared_ptr<Logger> pLogger)
{
	return Registry::Instance().SetDefaultLogger(pLogger);
}

void Trace(std::string pMessage)
{
	Registry::Instance().GetDefaultLogger()->Trace(pMessage);
}

void Error(std::string pMessage)
{
	Registry::Instance().GetDefaultLogger()->Error(pMessage);
}

}