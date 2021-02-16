#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing(Level::Value pLevel, std::unique_ptr<PackageFormatter> pFormatter):
	Logger(),
	mLevel(pLevel),
	mFormatter(std::move(pFormatter))
{}

Wing::Wing(std::unique_ptr<PackageFormatter> pFormatter):
	Wing(Level::minimal, std::move(pFormatter))
{}

Wing::~Wing()
{}

} 