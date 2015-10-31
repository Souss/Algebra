project(Algebra)
cmake_minimum_required		(VERSION 2.6)

#				Compilator Settings (Flags, ...)
set				(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")
set				(CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_CXX_COMPILER		g++)

#				Path Variable
set				(SRCS_PATH "src/")
set				(OBJS_PATH "obj/")


#				Sources
set				(SRCS
					"${SRCS_PATH}/main.cpp"
					"${SRCS_PATH}/Matrix.cpp")

#				Executable properties
add_executable			(algebra ${SRCS})