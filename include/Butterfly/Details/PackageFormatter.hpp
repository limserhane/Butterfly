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

	/**
	 * @brief Format a log record into a string.
	 * @param pFormatter A formatter providing the needed format for the log record and for the log informations;
	 * @param pPackage A package providing informations about the log record;
	 * @return The string representation of the log record
	 */
	static std::string Format(PackageFormatter* pFormatter, Package pPackage);

protected :
	/**
	 * @brief Converts a pattern into a usable format string for the class and save it as a state of the instance.
	 * @param pPattern The pattern followed to format the log records.
	 */
	void Compile(std::string pPattern);

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pFile The filename to be formatted;
	 * @return The filename itself
	 */
	inline virtual std::string FormatSourceFile(std::string pFile) const
	{
		return pFile;
	}

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pLine The line number to be formatted;
	 * @return The string representation of the line number
	 */
	inline virtual std::string FormatSourceLine(int pLine) const
	{
		return std::to_string(pLine);
	}

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pFunction The function name to be formatted;
	 * @return The function name itself
	 */
	inline virtual std::string FormatSourceFunction(std::string pFunction) const
	{
		return pFunction;
	}

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pPrettyFunction The function signature to be formatted;
	 * @return The function signature itself
	 */
	inline virtual std::string FormatSourcePrettyFunction(std::string pPrettyFunction) const
	{
		return pPrettyFunction;
	}

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

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pTag The tag to be formatted;
	 * @return The tag itself
	 */
	inline virtual std::string FormatTag(std::string pTag) const
	{
		return pTag;
	}

	/**
	 * @brief Formats the flag in a certain way.
	 * @param pMessage The message to be formatted;
	 * @return The message itself
	 */
	inline virtual std::string FormatMessage(std::string pMessage) const
	{
		return pMessage;
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

	/// A pattern representing minimal informations about the log record for debugging : "[int StartServer(const char* pIpAdress, int pPort)] [error] [network] Network service unavailable"
	static constexpr const char* DebugPattern = "[{pfunc:}] [{level:}] [{tag:}] {message:}\n";

}; 

} 