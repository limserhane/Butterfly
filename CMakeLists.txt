
cmake_minimum_required(VERSION 3.12)

project(butterfly LANGUAGES CXX)

set(SRC_DIR "src")
set(INC_DIR "include/${PROJECT_NAME}")

# Static library 

add_library(butterfly STATIC
	# src/
	"${SRC_DIR}/Butterfly.cpp"	"${INC_DIR}/Butterfly.hpp"
	"${SRC_DIR}/Common.cpp"		"${INC_DIR}/Common.hpp"
	"${SRC_DIR}/Logger.cpp"		"${INC_DIR}/Logger.hpp"
	"${SRC_DIR}/Net.cpp"		"${INC_DIR}/Net.hpp"
	"${SRC_DIR}/Wing.cpp"		"${INC_DIR}/Wing.hpp"
	"${SRC_DIR}/Registry.cpp"	"${INC_DIR}/Registry.hpp"
	"${SRC_DIR}/SafeLogger.cpp"	"${INC_DIR}/SafeLogger.hpp"

	# src/Wings/
	"${SRC_DIR}/Wings/ConsoleWing.cpp"			"${INC_DIR}/Wings/ConsoleWing.hpp"
	"${SRC_DIR}/Wings/ColoredConsoleWing.cpp"	"${INC_DIR}/Wings/ColoredConsoleWing.hpp"
	"${SRC_DIR}/Wings/FileWing.cpp"				"${INC_DIR}/Wings/FileWing.hpp"

	# src/Details/
	"${SRC_DIR}/Details/Package.cpp"			"${INC_DIR}/Details/Package.hpp"
	"${SRC_DIR}/Details/PackageFormatter.cpp"	"${INC_DIR}/Details/PackageFormatter.hpp"

	# src/Details/PackageFormatters
	"${SRC_DIR}/Details/PackageFormatters/ColoredPackageFormatter.cpp"	"${INC_DIR}/Details/PackageFormatters/ColoredPackageFormatter.hpp"
)
add_library(butterfly::lib ALIAS butterfly)

target_compile_features(butterfly PUBLIC cxx_std_17)

set_target_properties(butterfly PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/"
)

target_include_directories(butterfly PUBLIC "include/")

#Examples

add_subdirectory("examples/")