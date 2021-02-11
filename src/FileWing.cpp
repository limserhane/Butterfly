#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pName, std::string pFilename):
	Wing(pName),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "Runtime error, cannot open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename):
	FileWing("", pFilename)
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