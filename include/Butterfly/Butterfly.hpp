#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Net.hpp>
#include <Butterfly/Wings/Wing.hpp>
#include <Butterfly/Registry.hpp>

namespace Butterfly
{

std::shared_ptr<Net> CreateNet(std::string pName = "");

template<typename W = Wing, typename... Args>
std::shared_ptr<Logger> CreateWing(std::string pName, Args... args)
{
	static_assert(std::is_base_of<Wing, W>::value, "W must be derived from Wing");
	std::shared_ptr<Logger> logger = std::make_shared<W>(args...);
	return logger;
}


std::shared_ptr<Logger> GetDefaultLogger();
void SetDefaultLogger(std::shared_ptr<Logger> pLogger);

void Trace(std::string pMessage);
void Error(std::string pMessage);
	
} 