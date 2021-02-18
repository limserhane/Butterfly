#pragma once

#include <butterfly/details/package.hpp>

#include <string>
#include <time.h>

namespace butterfly
{

/**
 * @brief An abstract class used convert a log record into a string representation.
 */
class package_formatter
{
public :

	/**
	 * @brief format a log record into a string.
	 * @param p_formatter A formatter providing the needed format for the log record and for the log informations;
	 * @param p_package A package providing informations about the log record;
	 * @return The string representation of the log record
	 */
	virtual std::string format(package p_package) const = 0;

}; 

/**
 * @brief An class used convert a log record into a string representation.
 */
template<pattern P>
class Formatter : public package_formatter
{
public :
	Formatter<P>() = default;
	Formatter<P>(const Formatter<P>& pOther) = default;

	/**
	 * @brief format a log record into a string.
	 * @param p_package A package providing informations about the log record;
	 * @return The string representation of the log record
	 */
	virtual std::string format(package p_package) const override;

protected :	
	/**
	 * @brief Formats the level of a log record
	 * @param p_level The level to be formatted;
	 * @return The formatted level of a log record
	 */
	inline virtual std::string FormatLevel(level::value p_level) const
	{
		return to_string(p_level);
	}

	/**
	 * @brief Formats the time of a log record
	 * @param pRawTime The time to be formatted;
	 * @return The formatted time of a log record
	 */
	virtual std::string FormatTime(time_t pRawTime) const;

};

template <> std::string Formatter<pattern::none>::format(package p_package) const;

template <> std::string Formatter<pattern::minimal>::format(package p_package) const;

template <> std::string Formatter<pattern::report>::format(package p_package) const;

template <> std::string Formatter<pattern::simple>::format(package p_package) const;

template <> std::string Formatter<pattern::complete>::format(package p_package) const;

/**
 * @brief Creates a package_formatter for the needed pattern
 * @param p_pattern The pattern of the package_formatter to be created;
 * @return A unique pointer to the created package_formatter
 */
std::unique_ptr<package_formatter> create_package_formatter(pattern p_pattern);

}