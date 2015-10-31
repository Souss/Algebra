#include		<iostream>
#include		<chrono>

#include		"Chronos.hpp"

namespace		Faculta
{

  Chronos::Chronos(std::string const name) :
    name_test(name),
    start_time(std::chrono::high_resolution_clock::now())
  {
  }

  Chronos::~Chronos()
  {
    auto		last_time = std::chrono::high_resolution_clock::now();
    auto		time_span = std::chrono::duration_cast<std::chrono::duration<double> >(last_time - this->start_time);

    std::cout << "Duration time for " << this->name_test << " : "
	      << time_span.count() << " seconds." << std::endl;
  }

}
