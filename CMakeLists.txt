project				(Algebra)
cmake_minimum_required		(VERSION 2.6)

#				Path Variable
set				(SRCS_PATH "src/")
set				(OBJS_PATH "obj/")
set				(MATRIX_PATH "${SRCS_PATH}matrix/")
set				(PROBO_PATH "${SRCS_PATH}probo/")

#				Compilator Settings (Flags, ...)
set				(CMAKE_CXX_COMPILER g++)
set				(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")
set				(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
include_directories		("${MATRIX_PATH}" "${PROBO_PATH}")

#				Sources
set				(SRCS
					"${SRCS_PATH}main.cpp"
					"${MATRIX_PATH}Matrix.cpp"
					"${PROBO_PATH}Chronos.cpp")

#				Executable properties
add_executable			(algebra ${SRCS})