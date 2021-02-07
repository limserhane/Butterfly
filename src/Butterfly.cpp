#include <Butterfly/Butterfly.hpp>

#include <iostream>

namespace Butterfly
{

NetPointer CreateNet(std::string pName)
{
	NetPointer logger = std::make_shared<Net>(pName);
	return logger;
}

} 

