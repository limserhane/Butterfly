#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(std::string pName, Level::Value pLevel, std::string pMessage):
	Name(pName),
	Level(pLevel),
	Message(pMessage)
{}

} 