#pragma once

#include <Butterfly/Details/Package.hpp>

#include <string>

namespace Butterfly
{

class PackageFormatter
{
public :
	std::string Format(Package pPackage) const;

}; 

} 