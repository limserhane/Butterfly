#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(Level::Value pLevel, std::string pTag, std::string pMessage):
	Level(pLevel),
	Tag(pTag),
	Message(pMessage)
{}

} 