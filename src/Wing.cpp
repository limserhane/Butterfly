#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing(Level::Value pLevel, PackageFormatter pFormatter):
	Logger(),
	mLevel(pLevel),
	mFormatter(pFormatter)
{}

Wing::Wing(PackageFormatter pFormatter):
	Wing(Level::minimal, pFormatter)
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource)
{
	if(pLevel < mLevel)
	{
		return ;
	}

	Write(mFormatter.Format(&mFormatter, Package(pSource, time(nullptr), pLevel, pTag, pMessage)));
}

} 