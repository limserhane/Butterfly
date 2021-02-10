#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(Level::Value pLevel):
	
{

}
FileWing::FileWing(std::string pName = "", Level::Value pLevel = Level::trace);
FileWing::FileWing(std::string pFilename, std::string pName = "", Level::Value pLevel = Level::trace);

FileWing::FileWing(std::string pFilename):
	mFile(pFilename, std::ios_base::out | std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "Runtime error, cannot open file pFIlename");
	}
}

FileWing::~FileWing()
{
	mFile.close();
}

void FileWing::Write(std::string record)
{
	mFile << record;
}

}