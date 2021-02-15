#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pFilename, Level::Value pLevel, PackageFormatter pFormatter):
	Wing(pLevel, pFormatter),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "failed, unable to open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename, PackageFormatter pFormatter):
	FileWing(pFilename, Level::minimal, pFormatter)
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