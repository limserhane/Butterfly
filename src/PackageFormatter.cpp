#include <Butterfly/Details/PackageFormatter.hpp>

namespace Butterfly
{

std::string PackageFormatter::Format(Package pPackage) const
{
	char vBuffer[512];
	
	char vDateTimeBuffer[19+1];
	GetDateTime(vDateTimeBuffer, 19+1);

	snprintf(
		vBuffer, 512,
		"[%s][%s][%s] %s\n",
		vDateTimeBuffer,
		pPackage.Name.c_str(),
		Level::GetName(pPackage.Level).c_str(),
		pPackage.Message.c_str()
	);

	return vBuffer;
}

void PackageFormatter::GetDateTime(char* pBuffer, size_t pBufferSize) const
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(pBuffer, pBufferSize, "%Y-%m-%d %H:%M:%S", timeinfo);
}

} 