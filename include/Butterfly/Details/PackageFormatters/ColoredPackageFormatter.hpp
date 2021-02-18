#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Details/PackageFormatter.hpp>

namespace Butterfly
{

class ColoredPackageFormatter : public PackageFormatter
{
public :
	ColoredPackageFormatter(std::unique_ptr<PackageFormatter> pFormatter);
	
	/**
	 * @brief Format a log record into a string.
	 * @param pFormatter A formatter providing the needed format for the log record and for the log informations;
	 * @param pPackage A package providing informations about the log record;
	 * @return The string representation of the log record
	 */
	virtual std::string Format(Package pPackage) const override;

protected :

	/**
	 * @brief Gets the ansi color mark corresponding to the level.
	 * @param pLevel The level of the record;
	 * @return The ansi color mark corresponding to the level
	 */
	static std::string StartColorFlag(Level::Value pLevel);

	/**
	 * @brief Gets the ansi color mark corresponding to the console default color.
	 * @return The ansi color mark corresponding to the console default color
	 */
	inline static std::string EndColorFlag()
	{
		return "\033[0m";
	}

private :
	std::unique_ptr<PackageFormatter> mFormatter;

};

}