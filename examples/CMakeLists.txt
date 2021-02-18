
project(vscmake-examples)

link_libraries(butterfly::lib)

add_executable(basicusage "BasicUsage.cpp")

add_executable(advancedusage "AdvancedUsage.cpp")

add_executable(threadsafeusage "ThreadSafeUsage.cpp")
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	# no need to link pthread in VS ?
else()
	target_link_libraries(threadsafeusage pthread)
endif()

add_executable(coloredconsoleusage "ColoredConsoleUsage.cpp")

add_executable(speedtest "SpeedTest.cpp")

set_target_properties(
	basicusage 
	advancedusage
	threadsafeusage
	coloredconsoleusage
	speedtest
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/"
)