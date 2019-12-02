#include <boost/date_time/posix_time/posix_time.hpp>
#ifndef GIGASECOND_H
#define GIGASECOND_H
#define EXERCISM_RUN_ALL_TESTS
namespace gigasecond {
using namespace boost::posix_time;
const auto gigasecond = time_duration(seconds(int(1e9)));
ptime advance(ptime time);
} // namespace gigasecond
#endif // GIGASECOND_H