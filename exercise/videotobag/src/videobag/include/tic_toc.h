#pragma once

#include <ctime>
#include <cstdlib>
#include <chrono>

class TicToc
{
public:
  TicToc()
  {
    tic();
  }

  void tic()
  {
    start_ = std::chrono::system_clock::now();
  }

  double toc()
  {
    end_ = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> elapsed_seconds = end_ - start_;

    return elapsed_seconds.count();
    // return 1.e-6 * elapsed_seconds.count();
  }

  double secToc()
  {
    end_ = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_ - start_;

    return elapsed_seconds.count();
    // return 1.e-6 * elapsed_seconds.count();
  }

  std::chrono::time_point<std::chrono::system_clock> current()
  {
    return std::chrono::system_clock::now();
  }

private:
  std::chrono::time_point<std::chrono::system_clock> start_, end_;
};
