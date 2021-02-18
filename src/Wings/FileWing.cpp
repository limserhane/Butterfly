#include <Butterfly/Wings/FileWing.hpp>


namespace Butterfly
{

FileWing::FileWing(std::string pFilename, Level::Value pLevel, Pattern pPattern):
	Wing(pLevel, CompilePackageFormatter(pPattern)),
	mFile(pFilename, std::ios_base::app)
{
	if(!mFile.is_open())
	{
		ThrowException(BFLY_SOURCE, "failed, unable to open file pFilename");
	}
}

FileWing::FileWing(std::string pFilename, Pattern pPattern):
	FileWing(pFilename, Level::minimal, pPattern)
{}

FileWing::~FileWing()
{
	mFile.close();
}

}