#include <Butterfly/Details/PackageFormatter.hpp>

#include <Butterfly/Common.hpp>

#include <regex>

namespace Butterfly
{

PackageFormatter::PackageFormatter(const char* pPattern):
	mFormat(),
	mTimeFormat()
{
	Compile(pPattern);
}

PackageFormatter::PackageFormatter(const PackageFormatter& pOther):
	mFormat(pOther.mFormat),
	mTimeFormat(pOther.mTimeFormat)
{}

std::string PackageFormatter::Format(PackageFormatter* pFormatter, Package pPackage)
{
	constexpr size_t lBufferSize = 256;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,

		pFormatter->mFormat.c_str(), 

		pFormatter->FormatSourceFile(pPackage.Location.File).c_str(),
		pFormatter->FormatSourceLine(pPackage.Location.Line).c_str(),
		pFormatter->FormatSourceFunction(pPackage.Location.Function).c_str(),
		pFormatter->FormatSourcePrettyFunction(pPackage.Location.PrettyFunction).c_str(),
		pFormatter->FormatTime(pPackage.Time).c_str(),
		pFormatter->FormatLevel(pPackage.Level).c_str(),
		pFormatter->FormatTag(pPackage.Tag).c_str(),
		pFormatter->FormatMessage(pPackage.Message).c_str()
	);

	return lBuffer;
}

void PackageFormatter::Compile(std::string pPattern)
{
	if(pPattern.empty())
	{
		pPattern = SimplePattern;
	}

	std::regex flag("\\{(\\w+):([^\\{\\}]*)\\}");

	auto lFlagsBegin = std::sregex_iterator(pPattern.begin(), pPattern.end(), flag);
	auto lFlagEnd = std::sregex_iterator();

	std::string lFormat = pPattern;

	for (std::sregex_iterator lMatchIt = lFlagsBegin; lMatchIt != lFlagEnd; lMatchIt ++)
	{
		std::smatch lMatch = *lMatchIt; 

		std::string lMatchString = lMatch.str(); 
		std::string lFlagIdentifier = lMatch[1].str();

		std::string lReplacement;
		if(lFlagIdentifier == "message")
		{
			lReplacement = "%8$$s";
		}
		else if(lFlagIdentifier == "file")
		{
			lReplacement = "%1$$s";
		}
		else if(lFlagIdentifier == "line")
		{
			lReplacement = "%2$$s";
		}
		else if(lFlagIdentifier == "func")
		{
			lReplacement = "%3$$s";
		}
		else if(lFlagIdentifier == "pfunc")
		{
			lReplacement = "%4$$s";
		}
		else if(lFlagIdentifier == "time")
		{
			lReplacement = "%5$$s";
			mTimeFormat = lMatch[2].str();
		}
		else if(lFlagIdentifier == "level")
		{
			lReplacement = "%6$$s";
		}
		else if(lFlagIdentifier == "tag")
		{
			lReplacement = "%7$$s";
		}
		else
		{
			lReplacement = lFlagIdentifier;
		}

		lFormat = std::regex_replace(lFormat, flag, lReplacement, std::regex_constants::format_first_only);
	}

	mFormat = lFormat;
}

std::string PackageFormatter::FormatTime(time_t pRawTime) const
{
	constexpr size_t lBufferSize = 32;
	char lBuffer[lBufferSize];

	strftime(lBuffer, lBufferSize, mTimeFormat.c_str(), localtime(&pRawTime));
	
	return lBuffer;
}
} 