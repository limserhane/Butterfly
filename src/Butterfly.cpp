#include <Butterfly/Butterfly.hpp>

#include <iostream>

namespace Butterfly
{

std::shared_ptr<Net> CreateNet(std::string pIdentifier, std::initializer_list<std::shared_ptr<Logger>> pLoggers)
{
	std::shared_ptr<Net> lLogger = std::make_shared<Net>(pLoggers);

	Registry::Instance().Add(pIdentifier, lLogger);

	return lLogger;
}

std::shared_ptr<SafeLogger> CreateSafeLogger(std::string pIdentifier, std::shared_ptr<Logger> pLogger)
{
	if(!pLogger)
	{
		ThrowException(BFLY_SOURCE, "invalid argument, pLogger is nullptr");
		return nullptr;
	}

	std::shared_ptr<SafeLogger> lSafeLogger = std::make_shared<SafeLogger>(pLogger);

	Registry::Instance().Add(pIdentifier, lSafeLogger);

	return lSafeLogger;
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

void Trace(std::string pTag, std::string pMessage, Source pSource)
{
	Registry::Instance().GetDefaultLogger()->Trace(pTag, pMessage, pSource);
}

void Error(std::string pTag, std::string pMessage, Source pSource)
{
	Registry::Instance().GetDefaultLogger()->Error(pTag, pMessage, pSource);
}

}