#include <Butterfly/Butterfly.hpp>

#include <iostream>

namespace Butterfly
{

void Print() {
	std::cout << "Butterflies all havin' fun !" << std::endl;
}

NetPointer CreateNet(std::string pName)
{
	NetPointer logger = std::make_shared<Net>(pName);
	return logger;
}

} // namespace Butterfly

