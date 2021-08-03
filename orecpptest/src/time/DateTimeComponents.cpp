#include "time/DateTimeComponents.h"
#include "utils/Constants.h"
#include <cmath>

const DateTimeComponents* DateTimeComponents::JULIAN_EPOCH = new DateTimeComponents(*DateComponents::JULIAN_EPOCH, *TimeComponents::H12);

DateTimeComponents::DateTimeComponents(DateComponents date, TimeComponents time)
	:date(date), time(time)
{

}

DateTimeComponents::DateTimeComponents(int year, int month, int day, int hour, int minute, double second)
	:date(year, month, day),
	 time(hour, minute, second)
{

}

DateTimeComponents::DateTimeComponents(int year, int month, int day)
	:date(year, month, day), time(*TimeComponents::H00)
{

}

DateTimeComponents::DateTimeComponents(const DateTimeComponents& reference, double offset)
{
    // extract linear data from reference date/time
    int    day = reference.getDate().getJ2000Day();
    double seconds = reference.getTime().getSecondsInLocalDay();

    // apply offset
    seconds += offset;

    // fix range
    int dayShift = static_cast<int>(std::floor(seconds / Constants::JULIAN_DAY));
    seconds -= Constants::JULIAN_DAY * dayShift;
    day += dayShift;
    TimeComponents tmpTime(seconds);

    // set up components
    date = DateComponents(day);
    time = TimeComponents(tmpTime.getHour(), tmpTime.getMinute(), tmpTime.getSecond(),
        reference.getTime().getMinutesFromUTC());
}

double DateTimeComponents::offsetFrom(const DateTimeComponents& dateTime) const
{
    int dateOffset = date.getJ2000Day() - dateTime.date.getJ2000Day();
    double timeOffset = time.getSecondsInUTCDay() - dateTime.time.getSecondsInUTCDay();
    return Constants::JULIAN_DAY * dateOffset + timeOffset;
}

DateComponents DateTimeComponents::getDate() const
{
    return date;
}

TimeComponents DateTimeComponents::getTime() const
{
    return time;
}

bool DateTimeComponents::operator<(const DateTimeComponents& other) const
{
    if (date == other.date)
    {
        return time < other.time;
    }

    return date < other.date;
}

bool DateTimeComponents::operator==(const DateTimeComponents& other) const
{
    return date == other.date && time == other.time;
}

int DateTimeComponents::hashCode() const
{
    return (date.hashCode() << 16) ^ time.hashCode();
}