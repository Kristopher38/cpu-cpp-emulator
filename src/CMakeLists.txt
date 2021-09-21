cmake_minimum_required(VERSION 2.8)

project(riscie)
add_executable(${PROJECT_NAME}
	"main.cpp"
	"modules/port.cpp"
	"modules/memory.cpp"
	"modules/instr_mem.cpp"
	"modules/reg_file.cpp")
