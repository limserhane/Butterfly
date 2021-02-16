#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pFilename, Level::Value pLevel, const char* pPattern):
	Wing(pLevel, std::make_unique<PackageFormatter>(pPattern)),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "failed, unable to open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename, const char* pPattern):
	FileWing(pFilename, Level::minimal, pPattern)
{}

FileWing::~FileWing()
{
	mFile.close();
}

void FileWing::Write(std::string pRecord)
{
	mFile << pRecord;
}

}