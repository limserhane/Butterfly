#pragma once

#include <Butterfly/Details/Package.hpp>

#include <string>
#include <time.h>

namespace Butterfly
{

class PackageFormatter
{
public :
	std::string Format(Package pPackage) const;

}; 

} 