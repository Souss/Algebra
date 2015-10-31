#include		<iostream>

#include		"Matrix.hpp"
#include		"Chronos.hpp"

int			main(int argc, char *argv[])
{
  Algebra::Matrix	matrix(3, 4);
  Faculta::Chronos	chrono;

  std::cout << "[" << argv[0] + 2 << "]"
	    << " Test functionalities"<< std::endl;

  return 0;
}
