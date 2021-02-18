
project(butterfly-examples)

link_libraries(butterfly::lib)

add_executable(basicusage "basic_usage.cpp")

add_executable(advancedusage "advanced_usage.cpp")

add_executable(threadsafeusage "thread_safe_usage.cpp")
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	# no need to link pthread in VS ?
else()
	target_link_libraries(threadsafeusage pthread)
endif()

add_executable(coloredconsoleusage "colored_console_usage.cpp")

add_executable(speedtest "speedtest.cpp")

# set_target_properties(
# 	basicusage 
# 	advancedusage
# 	threadsafeusage
# 	coloredconsoleusage
# 	speedtest
# 	PROPERTIES
# 	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/"
# )