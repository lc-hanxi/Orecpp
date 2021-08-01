#include "time/DateComponents.h"
#include <memory>

/** Interface for dealing with months sequences according to leap/common years. */
class MonthDayFactory
{
public:
    /** Get the month number for a given day number within year.
     * @param dayInYear day number within year
     * @return month number
     */
    virtual int getMonth(int dayInYear) const = 0;

    /** Get the day number for given month and day number within year.
     * @param dayInYear day number within year
     * @param month month number
     * @return day number
     */
    virtual int getDay(int dayInYear, int month) const = 0;

    /** Get the day number within year for given month and day numbers.
     * @param month month number
     * @param day day number
     * @return day number within year
     */
    virtual int getDayInYear(int month, int day) const = 0;
};

/** Class providing the months sequence for leap years. */
class LeapYearFactory : virtual public MonthDayFactory {

public:
    /** {@inheritDoc} */
    int getMonth(int dayInYear) const override
    {
        return (dayInYear < 32) ? 1 : (10 * dayInYear + 313) / 306;
    }

    /** {@inheritDoc} */
    int getDay(int dayInYear, int month) const override
    {
        return dayInYear - PREVIOUS_MONTH_END_DAY[month];
    }

    /** {@inheritDoc} */
    int getDayInYear(int month, int day) const override
    {
        return day + PREVIOUS_MONTH_END_DAY[month];
    }

private:
    /** Months succession definition. */
    static const int PREVIOUS_MONTH_END_DAY[13];
};

const int LeapYearFactory::PREVIOUS_MONTH_END_DAY[13] = {
    0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335
};

/** Class providing the months sequence for common years. */
class CommonYearFactory : virtual public MonthDayFactory 
{
public:
    /** {@inheritDoc} */
    int getMonth(int dayInYear) const override
    {
        return (dayInYear < 32) ? 1 : (10 * dayInYear + 323) / 306;
    }

    /** {@inheritDoc} */
    int getDay(int dayInYear, int month) const override
    {
        return dayInYear - PREVIOUS_MONTH_END_DAY[month];
    }

    /** {@inheritDoc} */
    int getDayInYear(int month, int day) const override
    {
        return day + PREVIOUS_MONTH_END_DAY[month];
    }
private:
    static const int PREVIOUS_MONTH_END_DAY[13];
};

/** Months succession definition. */
const int CommonYearFactory::PREVIOUS_MONTH_END_DAY[13] = {
    0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};



/** Interface for dealing with years sequences according to some calendar. */
class YearFactory 
{
public:
    /** Get the year number for a given day number with respect to J2000 epoch.
     * @param j2000Day day number with respect to J2000 epoch
     * @return year number
     */
    virtual int getYear(int j2000Day) const = 0;

    /** Get the day number with respect to J2000 epoch for new year's Eve.
     * @param year year number
     * @return day number with respect to J2000 epoch for new year's Eve
     */
    virtual int getLastJ2000DayOfYear(int year) const = 0;

    /** Check if a year is a leap or common year.
     * @param year year number
     * @return true if year is a leap year
     */
    virtual bool isLeap(int year) const = 0;
};

/** Class providing a years sequence compliant with the proleptic Julian calendar. */
class ProlepticJulianFactory : virtual public YearFactory
{
public:
    /** {@inheritDoc} */
    int getYear(int j2000Day) const override
    {
        return  (int)-((-4l * j2000Day - 2920488l) / 1461l);
    }

    /** {@inheritDoc} */
    int getLastJ2000DayOfYear(int year) const override
    {
        return 365 * year + (year + 1) / 4 - 730123;
    }

    bool isLeap(int year) const override
    {
        return (year % 4) == 0;
    }
};

/** Class providing a years sequence compliant with the Julian calendar. */
class JulianFactory : virtual public YearFactory
{
public:
    /** {@inheritDoc} */
    int getYear(int j2000Day) const override
    {
        return  (int)((4l * j2000Day + 2921948l) / 1461l);
    }

    /** {@inheritDoc} */
    int getLastJ2000DayOfYear(int year) const override
    {
        return 365 * year + year / 4 - 730122;
    }

    bool isLeap(int year) const override
    {
        return (year % 4) == 0;
    }
};

/** Class providing a years sequence compliant with the Gregorian calendar. */
class GregorianFactory : virtual public YearFactory
{
public:
    /** {@inheritDoc} */
    int getYear(int j2000Day) const override
    {
        // year estimate
        int year = (int)((400l * j2000Day + 292194288l) / 146097l);

        // the previous estimate is one unit too high in some rare cases
        // (240 days in the 400 years gregorian cycle, about 0.16%)
        if (j2000Day <= getLastJ2000DayOfYear(year - 1))
        {
            --year;
        }

        // exact year
        return year;
    }

    /** {@inheritDoc} */
    int getLastJ2000DayOfYear(int year) const override
    {
        return 365 * year + year / 4 - year / 100 + year / 400 - 730120;
    }

    /** {@inheritDoc} */
    bool isLeap(int year) const override
    {
        return ((year % 4) == 0) && (((year % 400) == 0) || ((year % 100) != 0));
    }
};


const DateComponents* DateComponents::JULIAN_EPOCH = new DateComponents(-4712, 1, 1);
const DateComponents* DateComponents::MODIFIED_JULIAN_EPOCH = new DateComponents(1858, 11, 17);
const DateComponents* DateComponents::FIFTIES_EPOCH = new DateComponents(1950, 1, 1);
const DateComponents* DateComponents::CCSDS_EPOCH = new DateComponents(1958, 1, 1);
const DateComponents* DateComponents::GALILEO_EPOCH = new DateComponents(1999, 8, 22);
const DateComponents* DateComponents::GPS_EPOCH = new DateComponents(1980, 1, 6);
const DateComponents* DateComponents::QZSS_EPOCH = new DateComponents(1980, 1, 6);
const DateComponents* DateComponents::IRNSS_EPOCH = new DateComponents(1999, 8, 22);
const DateComponents* DateComponents::BEIDOU_EPOCH = new DateComponents(2006, 1, 1);
const DateComponents* DateComponents::GLONASS_EPOCH = new DateComponents(1996, 1, 1);
const DateComponents* DateComponents::J2000_EPOCH = new DateComponents(2000, 1, 1);
const DateComponents* DateComponents::JAVA_EPOCH = new DateComponents(1970, 1, 1);
const DateComponents* DateComponents::MAX_EPOCH = new DateComponents(INT_MAX);
const DateComponents* DateComponents::MIN_EPOCH = new DateComponents(INT_MIN);

const YearFactory* DateComponents::PROLEPTIC_JULIAN_FACTORY = new ProlepticJulianFactory();
const YearFactory* DateComponents::JULIAN_FACTORY = new JulianFactory();
const YearFactory* DateComponents::GREGORIAN_FACTORY = new GregorianFactory();
const MonthDayFactory* DateComponents::LEAP_YEAR_FACTORY = new LeapYearFactory();
const MonthDayFactory* DateComponents::COMMON_YEAR_FACTORY = new CommonYearFactory();

DateComponents::DateComponents(int year, int month, int day)
    : year(year), month(month), day(day)
{

}

DateComponents::DateComponents(int year, int dayNumber)
    : DateComponents(*J2000_EPOCH, DateComponents(year - 1, 12, 31).getJ2000Day() + dayNumber)
{

}

DateComponents::DateComponents(int offset)
{
    // we follow the astronomical convention for calendars:
    // we consider a year zero and 10 days are missing in 1582
    // from 1582-10-15: gregorian calendar
    // from 0001-01-01 to 1582-10-04: julian calendar
    // up to 0000-12-31 : proleptic julian calendar
    auto yFactory = GREGORIAN_FACTORY;
    if (offset < -152384) {
        if (offset > -730122) {
            yFactory = JULIAN_FACTORY;
        }
        else {
            yFactory = PROLEPTIC_JULIAN_FACTORY;
        }
    }
    year = yFactory->getYear(offset);
    int dayInYear = offset - yFactory->getLastJ2000DayOfYear(year - 1);

    // handle month/day according to the year being a common or leap year
    auto mdFactory =
        yFactory->isLeap(year) ? LEAP_YEAR_FACTORY : COMMON_YEAR_FACTORY;
    month = mdFactory->getMonth(dayInYear);
    day = mdFactory->getDay(dayInYear, month);
}

DateComponents::DateComponents(const DateComponents& epoch, int offset)
    : DateComponents(epoch.getJ2000Day() + offset)
{
    
}

int DateComponents::getYear() const
{
    return year;
}

int DateComponents::getMonth() const
{
    return month;
}

int DateComponents::getDay() const
{
    return day;
}

int DateComponents::getJ2000Day() const
{
    auto yFactory = GREGORIAN_FACTORY;
    if (year < 1583) {
        if (year < 1) {
            yFactory = PROLEPTIC_JULIAN_FACTORY;
        }
        else if ((year < 1582) || (month < 10) || ((month < 11) && (day < 5))) {
            yFactory = JULIAN_FACTORY;
        }
    }
    auto mdFactory =
        yFactory->isLeap(year) ? LEAP_YEAR_FACTORY : COMMON_YEAR_FACTORY;
    return yFactory->getLastJ2000DayOfYear(year - 1) +
        mdFactory->getDayInYear(month, day);
}

int DateComponents::getMJD() const
{
    return MJD_TO_J2000 + getJ2000Day();
}

int DateComponents::getCalendarWeek() const
{
    int firstWeekMonday = getFirstWeekMonday(year);
    int daysSincefirstMonday = getJ2000Day() - firstWeekMonday;
    if (daysSincefirstMonday < 0) {
        // we are still in a week from previous year
        daysSincefirstMonday += firstWeekMonday - getFirstWeekMonday(year - 1);
    }
    else if (daysSincefirstMonday > 363) {
        // up to three days at end of year may belong to first week of next year
        // (by chance, there is no need for a specific check in year 1582 ...)
        int weekYearLength = getFirstWeekMonday(year + 1) - firstWeekMonday;
        if (daysSincefirstMonday >= weekYearLength) {
            daysSincefirstMonday -= weekYearLength;
        }
    }
    return 1 + daysSincefirstMonday / 7;
}

int DateComponents::getFirstWeekMonday(int year)
{
    int yearFirst = DateComponents(year, 1, 1).getJ2000Day();
    int offsetToMonday = 4 - (yearFirst + 2) % 7;
    return yearFirst + offsetToMonday + ((offsetToMonday > 3) ? -7 : 0);
}

int DateComponents::getDayOfWeek() const 
{
    int dow = (getJ2000Day() + 6) % 7; // result is between -6 and +6
    return (dow < 1) ? (dow + 7) : dow;
}

int DateComponents::getDayOfYear() const
{
    return getJ2000Day() - DateComponents(year - 1, 12, 31).getJ2000Day();
}

bool DateComponents::operator<(const DateComponents& other) const
{
    int j2000Day = getJ2000Day();
    int otherJ2000Day = other.getJ2000Day();
    return j2000Day < otherJ2000Day;
}

bool DateComponents::operator==(const DateComponents& other) const
{
    return year == other.year && month == other.month && day == other.day;
}

int DateComponents::hashCode() const
{
    return (year << 16) ^ (month << 8) ^ day;
}

DateComponents DateComponents::createFromWeekComponents(int wYear, int week, int dayOfWeek)
{
    DateComponents firstWeekMonday(getFirstWeekMonday(wYear));
    DateComponents d(firstWeekMonday, 7 * week + dayOfWeek - 8);

    return d;
}