#pragma once

#include <butterfly/common.hpp>
#include <butterfly/details/package_formatter.hpp>

namespace butterfly
{

/**
 * @brief An class used to decorate the string representation of a log record with ansi color escape codes
 */
class colored_package_formatter : public package_formatter
{
public :
	colored_package_formatter(std::unique_ptr<package_formatter> p_formatter);
	
	/**
	 * @brief format a log record into a string.
	 * @param p_package A package providing informations about the log record;
	 * @return The colored string representation of the log record
	 */
	virtual std::string format(package p_package) const override;

protected :

	/**
	 * @brief Gets the ansi color mark corresponding to the level.
	 * @param p_level The level of the record;
	 * @return The ansi color mark corresponding to the level
	 */
	static std::string start_color_flag(level::value p_level);

	/**
	 * @brief Gets the ansi color mark corresponding to the console default color.
	 * @return The ansi color mark corresponding to the console default color
	 */
	inline static std::string end_color_flag()
	{
		return "\033[0m";
	}

private :
	std::unique_ptr<package_formatter> m_formatter;

};

}