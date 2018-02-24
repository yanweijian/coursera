cmake_minimum_required(VERSION 2.6)
project(opt_reload)

set(opt_reload_VERSION_MAJOR 1)
set(opt_reload_VERSION_MINOR 0)

configure_file(
	"${PROJECT_SOURCE_DIR}/opt_reloadConfig.h.in"
	"${PROJECT_BINARY_DIR}/opt_reloadConfig.h"
	)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(opt_reload operator_reload.cpp)
