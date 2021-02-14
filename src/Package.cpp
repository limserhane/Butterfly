#include <Butterfly/Details/Package.hpp>



namespace Butterfly
{

Package::Package(Source pSource, Level::Value pLevel, std::string pTag, std::string pMessage):
	Location(pSource),
	Level(pLevel),
	Tag(pTag),
	Message(pMessage)
{}

} 