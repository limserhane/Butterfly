#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pFilename, Level::Value pLevel, std::string pPattern):
	Wing(pLevel, pPattern),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "failed, unable to open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename, std::string pPattern):
	FileWing(pFilename, Level::minimal, pPattern)
{}

FileWing::~FileWing()
{
	mFile.close();
}

void FileWing::Write(std::string record)
{
	mFile << record;
}

}