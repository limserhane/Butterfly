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

}