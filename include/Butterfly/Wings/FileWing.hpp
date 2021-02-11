#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wings/Wing.hpp>

#include <iostream>
#include <string>
#include <fstream>

namespace Butterfly
{

class FileWing : public Wing
{
public :
	FileWing(std::string pName, std::string pFilename);

	~FileWing();

private :
	virtual void Write(std::string record) override;

	std::ofstream mFile;

};

}