
cmake_minimum_required(VERSION 3.12)

option(BUILD_EXAMPLES "Build examples" OFF)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin" CACHE PATH "Path to install directory" FORCE)

project(butterfly LANGUAGES CXX)

set(SRC_DIR "src")
set(INC_DIR "include/${PROJECT_NAME}")

# Static library 

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

target_include_directories(butterfly PUBLIC "include/")

# Install

install(
	TARGETS butterfly
	EXPORT butterfly
	ARCHIVE DESTINATION "lib/"
)
install(DIRECTORY "include/" DESTINATION "${CMAKE_INSTALL_PREFIX}/include/")


#Examples
if(BUILD_EXAMPLES)
	add_subdirectory("examples/")
endif()