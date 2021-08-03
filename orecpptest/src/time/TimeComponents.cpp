#include "time/TimeComponents.h"
#include "utils/Constants.h"
#include <cmath>

const TimeComponents TimeComponents::H00(0, 0, 0);
const TimeComponents TimeComponents::H12(12, 0, 0);

TimeComponents::TimeComponents(int hour, int minute, double second)
	:TimeComponents(hour, minute, second, 0)
{

}

TimeComponents::TimeComponents(int hour, int minute, double second, int minutesFromUTC)
	:hour(hour), minute(minute), second(second), minutesFromUTC(minutesFromUTC)
{

}

TimeComponents::TimeComponents(double secondInDay)
	:TimeComponents(0, secondInDay)
{

}

TimeComponents::TimeComponents(int secondInDayA, double secondInDayB)
	: TimeComponents((Constants::JULIAN_DAY - secondInDayA) - secondInDayB > 0 ? secondInDayA : secondInDayA - 1,
		             secondInDayB,
		             (Constants::JULIAN_DAY - secondInDayA) - secondInDayB > 0 ? 0 : 1,
		             (Constants::JULIAN_DAY - secondInDayA) - secondInDayB > 0 ? 60 : 61)
{

}

TimeComponents::TimeComponents(int secondInDayA, double secondInDayB, double leap, int minuteDuration)
{
    // split the numbers as a whole number of seconds
    // and a fractional part between 0.0 (included) and 1.0 (excluded)
    int carry = static_cast<int>(std::floor(secondInDayB));
    int wholeSeconds = secondInDayA + carry;
    double fractional = secondInDayB - carry;

    //// range check
    //if (wholeSeconds < 0 || wholeSeconds >= Constants::JULIAN_DAY) {
    //    throw new OrekitIllegalArgumentException(
    //        OrekitMessages.OUT_OF_RANGE_SECONDS_NUMBER_DETAIL,
    //        // this can produce some strange messages due to rounding
    //        secondInDayA + secondInDayB,
    //        0,
    //        Constants.JULIAN_DAY);
    //}
    int maxExtraSeconds = minuteDuration - 60;
    //if (leap * maxExtraSeconds < 0 ||
    //    FastMath.abs(leap) > FastMath.abs(maxExtraSeconds)) {
    //    throw new OrekitIllegalArgumentException(
    //        OrekitMessages.OUT_OF_RANGE_SECONDS_NUMBER_DETAIL,
    //        leap, 0, maxExtraSeconds);
    //}

    // extract the time components
    hour = wholeSeconds / 3600;
    wholeSeconds -= 3600 * hour;
    minute = wholeSeconds / 60;
    wholeSeconds -= 60 * minute;
    // at this point ((minuteDuration - wholeSeconds) - leap) - fractional > 0
    // or else one of the preconditions was violated. Even if there is not violation,
    // naiveSecond may round to minuteDuration, creating an invalid time.
    // In that case round down to preserve a valid time at the cost of up to 1 ULP of error.
    // See #676 and #681.
    double naiveSecond = wholeSeconds + (leap + fractional);
    //if (naiveSecond < 0) {
    //    throw new OrekitIllegalArgumentException(
    //        OrekitMessages.OUT_OF_RANGE_SECONDS_NUMBER_DETAIL,
    //        naiveSecond, 0, minuteDuration);
    //}
    if (naiveSecond < minuteDuration || std::isnan(naiveSecond)) {
        second = naiveSecond;
    }
    else {
        second = (double)minuteDuration - 0.0000000001;
    }
    minutesFromUTC = 0;
}

TimeComponents TimeComponents::fromSeconds(int secondInDayA, double secondInDayB, double leap, int minuteDuration)
{
    return TimeComponents(secondInDayA, secondInDayB, leap, minuteDuration);
}

int TimeComponents::getHour() const
{
    return hour;
}

int TimeComponents::getMinute() const
{
    return minute;
}

double TimeComponents::getSecond() const
{
    return second;
}

int TimeComponents::getMinutesFromUTC() const
{
    return minutesFromUTC;
}

double TimeComponents::getSecondsInLocalDay() const
{
   return second + 60. * minute + 3600. * hour;
}

double TimeComponents::getSecondsInUTCDay() const
{
    return second + 60. * (minute - minutesFromUTC) + 3600. * hour;
}

bool TimeComponents::operator<(const TimeComponents& other) const
{
    return getSecondsInUTCDay() < other.getSecondsInUTCDay();
}

bool TimeComponents::operator==(const TimeComponents& other) const
{
    return 
        hour == other.hour &&
        minute == other.minute &&
        fabs(second - other.second) < 1e-8 &&
        minutesFromUTC == other.minutesFromUTC;
}

int TimeComponents::hashCode() const
{
    int64_t bits = static_cast<int64_t>(second);
    return ((hour << 16) ^ ((minute - minutesFromUTC) << 8)) ^ (int)(bits ^ (bits >> 32));
}