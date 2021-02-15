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

	static std::string Format(PackageFormatter* pFormatter, Package pPackage);

protected :
	void Compile(std::string pPattern);

	inline virtual std::string FormatSourceFile(std::string pFile) const
	{
		return pFile;
	}

	inline virtual std::string FormatSourceLine(int pLine) const
	{
		return std::to_string(pLine);
	}

	inline virtual std::string FormatSourceFunction(std::string pFunction) const
	{
		return pFunction;
	}

	inline virtual std::string FormatSourcePrettyFunction(std::string pPrettyFunction) const
	{
		return pPrettyFunction;
	}

	virtual std::string FormatTime(time_t pRawTime) const;

	inline virtual std::string FormatLevel(Level::Value pLevel) const
	{
		return ToString(pLevel);
	}

	inline virtual std::string FormatTag(std::string pTag) const
	{
		return pTag;
	}

	inline virtual std::string FormatMessage(std::string pMessage) const
	{
		return pMessage;
	}

	std::string mFormat;
	std::string mTimeFormat;

public :
	static constexpr const char* MinimalPattern = "{message:}\n";
	static constexpr const char* SimplePattern = "[{level:}] [{tag:}] {message:}\n";
	static constexpr const char* CompletePattern = "{time:%F %T} [{level:}] [{tag:}] {message:}\n";
	static constexpr const char* DebugPattern = "[{pfunc:}] [{level:}] [{tag:}] {message:}\n";
}; 

} 