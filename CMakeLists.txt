
cmake_minimum_required(VERSION 3.12)

project(butterfly LANGUAGES CXX)

set(SRC_DIR "src")
set(INC_DIR "include/${PROJECT_NAME}")

# Static library 

# set(CMAKE_BUILD_TYPE Release)

add_library(butterfly STATIC
	# src/
	"${SRC_DIR}/butterfly.cpp"		"${INC_DIR}/butterfly.hpp"
	"${SRC_DIR}/common.cpp"			"${INC_DIR}/common.hpp"
	"${SRC_DIR}/logger.cpp"			"${INC_DIR}/logger.hpp"
	"${SRC_DIR}/net.cpp"			"${INC_DIR}/net.hpp"
	"${SRC_DIR}/wing.cpp"			"${INC_DIR}/wing.hpp"
	"${SRC_DIR}/registry.cpp"		"${INC_DIR}/registry.hpp"
	"${SRC_DIR}/safe_logger.cpp"	"${INC_DIR}/safe_logger.hpp"

	# src/wings/
	"${SRC_DIR}/wings/console_wing.cpp"			"${INC_DIR}/wings/console_wing.hpp"
	"${SRC_DIR}/wings/colored_console_wing.cpp"	"${INC_DIR}/wings/colored_console_wing.hpp"
	"${SRC_DIR}/wings/file_wing.cpp"			"${INC_DIR}/wings/file_wing.hpp"

	# src/details/
	"${SRC_DIR}/details/package.cpp"			"${INC_DIR}/details/package.hpp"
	"${SRC_DIR}/details/package_formatter.cpp"	"${INC_DIR}/details/package_formatter.hpp"

	# src/details/package_formatters
	"${SRC_DIR}/details/package_formatters/colored_package_formatter.cpp"	"${INC_DIR}/details/package_formatters/colored_package_formatter.hpp"
)
add_library(butterfly::lib ALIAS butterfly)

target_compile_features(butterfly PUBLIC cxx_std_17)

# set_target_properties(butterfly PROPERTIES
# 	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/"
# )

target_include_directories(butterfly PUBLIC "include/")

#Examples

add_subdirectory("examples/")