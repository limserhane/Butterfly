#pragma once

#include <Butterfly/Details/Package.hpp>

#include <string>
#include <time.h>

namespace Butterfly
{

/**
 * @brief An abstract class used convert a log record into a string representation.
 */
class PackageFormatter
{
public :
	virtual std::string Format(Package pPackage) const = 0;

}; 

template<Pattern P>
class Formatter : public PackageFormatter
{
public :
	Formatter<P>() = default;
	Formatter<P>(const Formatter<P>& pOther) = default;

	virtual std::string Format(Package pPackage) const override;

protected :
	inline virtual std::string FormatLevel(Level::Value pLevel) const
	{
		return ToString(pLevel);
	}

	virtual std::string FormatTime(time_t pRawTime) const;

};

template <> std::string Formatter<Pattern::none>::Format(Package pPackage) const;

template <> std::string Formatter<Pattern::minimal>::Format(Package pPackage) const;

template <> std::string Formatter<Pattern::report>::Format(Package pPackage) const;

template <> std::string Formatter<Pattern::simple>::Format(Package pPackage) const;

template <> std::string Formatter<Pattern::complete>::Format(Package pPackage) const;

std::unique_ptr<PackageFormatter> CompilePackageFormatter(Pattern pPattern);

}