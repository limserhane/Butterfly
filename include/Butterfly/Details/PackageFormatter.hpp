#pragma once

#include <Butterfly/Details/Package.hpp>

#include <string>
#include <time.h>

namespace Butterfly
{

class PackageFormatter
{
public :
	PackageFormatter(const char* pPattern = "");

	PackageFormatter(const PackageFormatter& pOther);

	virtual std::string Format(Package pPackage) const;

protected :
	static std::string Compile(std::string pPattern);

	std::string mFormat;
}; 

} 