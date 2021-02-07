#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Net.hpp>
#include <Butterfly/Wing.hpp>

namespace Butterfly
{

NetPointer CreateNet(std::string pName = "");

template<typename WingType, typename... Args>
LoggerPointer CreateWing(Args... args)
{
	static_assert(std::is_base_of<Wing, WingType>::value, "Must create a Wing");
	LoggerPointer logger = std::make_shared<WingType>(args...);
	return logger;
} 
	
} 