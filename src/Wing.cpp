#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing(Level::Value pLevel):
	Logger(),
	mLevel(pLevel),
	mFormatter()
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