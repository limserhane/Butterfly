#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing(Level::Value pLevel, std::string pPattern):
	Logger(),
	mLevel(pLevel),
	mFormatter(pPattern)
{}

Wing::Wing(std::string pPattern):
	Wing(Level::minimal, pPattern)
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource)
{
	if(pLevel < mLevel)
	{
		return ;
	}
	
	Write(mFormatter.Format(Package(pSource, pLevel, pTag, pMessage)));
}

} 