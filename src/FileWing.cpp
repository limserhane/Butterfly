#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pFilename, Level::Value pLevel):
	Wing(pLevel),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "failed, unable to open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename):
	FileWing(pFilename, Level::minimal)
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