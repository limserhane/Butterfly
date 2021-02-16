#pragma once

#include <Butterfly/Details/Package.hpp>

#include <string>
#include <time.h>

namespace Butterfly
{

/**
 * @brief A class used convert a log record into a string representation using a given pattern.
 */
class PackageFormatter
{
public :
	PackageFormatter(const char* pPattern = "");

	PackageFormatter(const PackageFormatter& pOther);

	virtual ~PackageFormatter();

	/**
	 * @brief Format a log record into a string.
	 * @param pFormatter A formatter providing the needed format for the log record and for the log informations;
	 * @param pPackage A package providing informations about the log record;
	 * @return The string representation of the log record
	 */
	virtual std::string Format(Package pPackage) const;

protected :
	/**
	 * @brief Converts a pattern into a usable format string for the class and save it as a state of the instance.
	 * @param pPattern The pattern followed to format the log records.
	 */
	void Compile(std::string pPattern);

	/**
	 * @brief Formats the flag in a certain way using the format using the format given in the pattern.
	 * @param pRawTime The time to be formatted;
	 * @return The string representation of the time
	 */
	virtual std::string FormatTime(time_t pRawTime) const;

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pLevel The level to be formatted;
	 * @return The string represnetation of the level itself
	 */
	inline virtual std::string FormatLevel(Level::Value pLevel) const
	{
		return ToString(pLevel);
	}

	std::string mFormat;
	std::string mTimeFormat;

public :
	/// A pattern representing only the message to be logged : "Network service unavailable"
	static constexpr const char* MinimalPattern = "{message:}\n";

	/// A simple pattern representing basic informations about the log record : "[error] [network] Network service unavailable"
	static constexpr const char* SimplePattern = "[{level:}] [{tag:}] {message:}\n";

	/// A complete pattern representing the main informations about the log record : "2021-02-15 14:25:31 [error] [network] Network service unavailable"
	static constexpr const char* CompletePattern = "{time:%F %T} [{level:}] [{tag:}] {message:}\n";

}; 

} 