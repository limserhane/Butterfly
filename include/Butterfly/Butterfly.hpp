#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Net.hpp>
#include <Butterfly/Wing.hpp>
#include <Butterfly/Registry.hpp>
#include <Butterfly/SafeLogger.hpp>

namespace Butterfly
{

std::shared_ptr<Net> CreateNet(std::string pIdentifier);

template<typename W = Wing, typename... Args>
std::shared_ptr<Wing> CreateWing(std::string pIdentifier, Args... args)
{
static_assert(std::is_base_of<Wing, W>::value, "W must be derived from Wing");
	
	std::shared_ptr<Wing> lWing = std::make_shared<W>(args...);

	Registry::Instance().Add(pIdentifier, lWing);

	return lWing;
}

std::shared_ptr<SafeLogger> CreateSafeLogger(std::string pIdentifier, std::shared_ptr<Logger> pLogger);


std::shared_ptr<Logger> GetDefaultLogger();
void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

std::shared_ptr<Logger> Get(std::string pIdentifier);

void Trace(std::string pTag, std::string pMessage, Source pSource = Source());
void Error(std::string pTag, std::string pMessage, Source pSource = Source());
	
} 