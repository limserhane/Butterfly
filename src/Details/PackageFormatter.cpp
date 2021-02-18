#include <Butterfly/Details/PackageFormatter.hpp>

#include <Butterfly/Common.hpp>

#include <regex>

namespace Butterfly
{

template<Pattern P>
std::string Formatter<P>::FormatTime(time_t pRawTime) const
{
	char lTimeBuffer[21];

	strftime(lTimeBuffer, 21, "%F %T", localtime(&pRawTime));

	return lTimeBuffer;
}


template <> std::string Formatter<Pattern::none>::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 512;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,
		"%s\n",
		pPackage.Message.c_str()
	);

	return lBuffer;
}

template <> std::string Formatter<Pattern::minimal>::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 512;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,
		"[%s] %s\n",
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return lBuffer;
}

template <> std::string Formatter<Pattern::report>::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 512;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,
		"[%s] %s\n",
		ToString(pPackage.Level).c_str(),
		pPackage.Message.c_str()
	);

	return lBuffer;
}

template <> std::string Formatter<Pattern::simple>::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 512;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,
		"[%s] [%s] %s\n",
		FormatLevel(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return lBuffer;
}

template <> std::string Formatter<Pattern::complete>::Format(Package pPackage) const
{
	constexpr size_t lBufferSize = 512;
	char lBuffer[lBufferSize];

	snprintf(
		lBuffer, lBufferSize,
		"[%s] [%s] [%s] %s\n",
		FormatTime(pPackage.Time).c_str(),
		FormatLevel(pPackage.Level).c_str(),
		pPackage.Tag.c_str(),
		pPackage.Message.c_str()
	);

	return lBuffer;
}

std::unique_ptr<PackageFormatter> CompilePackageFormatter(Pattern pPattern)
{
	switch(pPattern)
	{
		case Pattern::none : return std::make_unique<Formatter<Pattern::none>>();
		case Pattern::minimal : return std::make_unique<Formatter<Pattern::minimal>>();
		case Pattern::report : return std::make_unique<Formatter<Pattern::report>>();
		case Pattern::simple : return std::make_unique<Formatter<Pattern::simple>>();
		case Pattern::complete : return std::make_unique<Formatter<Pattern::complete>>();
		default : ThrowException(BFLY_SOURCE, "invalid argument, pPattern is no valid pattern"); return nullptr;
	}
}

} 