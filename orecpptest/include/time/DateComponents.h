#ifndef _DATE_COMPONENTS_H_
#define _DATE_COMPONENTS_H_

#include <stdint.h>

/** Class representing a date broken up as year, month and day components.
 * <p>This class uses the astronomical convention for calendars,
 * which is also the convention used by <code>java.util.Date</code>:
 * a year zero is present between years -1 and +1, and 10 days are
 * missing in 1582. The calendar used around these special dates are:</p>
 * <ul>
 *   <li>up to 0000-12-31 : proleptic julian calendar</li>
 *   <li>from 0001-01-01 to 1582-10-04: julian calendar</li>
 *   <li>from 1582-10-15: gregorian calendar</li>
 * </ul>
 * <p>Instances of this class are guaranteed to be immutable.</p>
 * @see TimeComponents
 * @see DateTimeComponents
 * @author Luc Maisonobe
 */

class YearFactory;
class MonthDayFactory;

class DateComponents 
{
public:
    DateComponents() = default;
    /** Build a date from its components.
     * @param year year number (may be 0 or negative for BC years)
     * @param month month number from 1 to 12
     * @param day day number from 1 to 31
     * @exception IllegalArgumentException if inconsistent arguments
     * are given (parameters out of range, february 29 for non-leap years,
     * dates during the gregorian leap in 1582 ...)
     */
    DateComponents(int year, int month, int day);

     /** Build a date from a year and day number.
      * @param year year number (may be 0 or negative for BC years)
      * @param dayNumber day number in the year from 1 to 366
      * @exception IllegalArgumentException if dayNumber is out of range
      * with respect to year
      */
    DateComponents(int year, int dayNumber);

    /** Build a date from its offset with respect to a {@link #J2000_EPOCH}.
     * @param offset offset with respect to a {@link #J2000_EPOCH}
     * @see #getJ2000Day()
     */
    DateComponents(int offset);

    /** Build a date from its offset with respect to a reference epoch.
     * <p>This constructor is mainly useful to build a date from a modified
     * julian day (using {@link #MODIFIED_JULIAN_EPOCH}) or a GPS week number
     * (using {@link #GPS_EPOCH}).</p>
     * @param epoch reference epoch
     * @param offset offset with respect to a reference epoch
     * @see #DateComponents(int)
     * @see #getMJD()
     */
    DateComponents(const DateComponents& epoch, int offset);

    /** Get the year number.
     * @return year number (may be 0 or negative for BC years)
     */
    int getYear() const;

    /** Get the month.
     * @return month number from 1 to 12
     */
    int getMonth() const;

     /** Get the day.
      * @return day number from 1 to 31
      */
    int getDay() const;

     /** Get the day number with respect to J2000 epoch.
      * @return day number with respect to J2000 epoch
      */
    int getJ2000Day() const;

    /** Get the modified julian day.
     * @return modified julian day
     */
    int getMJD() const;

    /** Get the calendar week number.
     * <p>The calendar week number is a number between 1 and 52 or 53 depending
     * on the year. Week 1 is defined by ISO as the one that includes the first
     * Thursday of a year. Week 1 may therefore start the previous year and week
     * 52 or 53 may end in the next year. As an example calendar date 1995-01-01
     * corresponds to week date 1994-W52-7 (i.e. Sunday in the last week of 1994
     * is in fact the first day of year 1995). Another example is calendar date
     * 1996-12-31 which corresponds to week date 1997-W01-2 (i.e. Tuesday in the
     * first week of 1997 is in fact the last day of year 1996).</p>
     * @return calendar week number
     */
    int getCalendarWeek() const;

    /** Get the day of week.
     * <p>Day of week is a number between 1 (Monday) and 7 (Sunday).</p>
     * @return day of week
     */
    int getDayOfWeek() const;

    /** Get the day number in year.
     * <p>Day number in year is between 1 (January 1st) and either 365 or
     * 366 inclusive depending on year.</p>
     * @return day number in year
     */
    int getDayOfYear() const;

    /** Get a string representation (ISO-8601) of the date.
     * @return string representation of the date.
     */
     //public String toString() {
     //    return new StringBuffer().
     //        append(FOUR_DIGITS.format(year)).append('-').
     //        append(TWO_DIGITS.format(month)).append('-').
     //        append(TWO_DIGITS.format(day)).
     //        toString();
     //}

    /** {@inheritDoc} */
    bool operator < (const DateComponents& other) const;

    /** {@inheritDoc} */
    bool operator == (const DateComponents& other) const;

    /** {@inheritDoc} */
    int hashCode() const;

private:
    /** Year number. */
    int year;

    /** Month number. */
    int month;

    /** Day number. */
    int day;

public:
    /** Build a date from week components.
    * <p>The calendar week number is a number between 1 and 52 or 53 depending
    * on the year. Week 1 is defined by ISO as the one that includes the first
    * Thursday of a year. Week 1 may therefore start the previous year and week
    * 52 or 53 may end in the next year. As an example calendar date 1995-01-01
    * corresponds to week date 1994-W52-7 (i.e. Sunday in the last week of 1994
    * is in fact the first day of year 1995). This date would beAnother example is calendar date
    * 1996-12-31 which corresponds to week date 1997-W01-2 (i.e. Tuesday in the
    * first week of 1997 is in fact the last day of year 1996).</p>
    * @param wYear year associated to week numbering
    * @param week week number in year, from 1 to 52 or 53
    * @param dayOfWeek day of week, from 1 (Monday) to 7 (Sunday)
    * @return a builded date
    * @exception IllegalArgumentException if inconsistent arguments
    * are given (parameters out of range, week 53 on a 52 weeks year ...)
    */
    static DateComponents createFromWeekComponents(int wYear, int week, int dayOfWeek);

    /** Reference epoch for julian dates: -4712-01-01.
     * <p>Both <code>java.util.Date</code> and {@link DateComponents} classes
     * follow the astronomical conventions and consider a year 0 between
     * years -1 and +1, hence this reference date lies in year -4712 and not
     * in year -4713 as can be seen in other documents or programs that obey
     * a different convention (for example the <code>convcal</code> utility).</p>
     */
    static const DateComponents JULIAN_EPOCH;

    /** Reference epoch for modified julian dates: 1858-11-17. */
    static const DateComponents MODIFIED_JULIAN_EPOCH;

    /** Reference epoch for 1950 dates: 1950-01-01. */
    static const DateComponents FIFTIES_EPOCH;

    /** Reference epoch for CCSDS Time Code Format (CCSDS 301.0-B-4): 1958-01-01. */
    static const DateComponents CCSDS_EPOCH;

    /** Reference epoch for Galileo System Time: 1999-08-22. */
    static const DateComponents GALILEO_EPOCH;

    /** Reference epoch for GPS weeks: 1980-01-06. */
    static const DateComponents GPS_EPOCH;

    /** Reference epoch for QZSS weeks: 1980-01-06. */
    static const DateComponents QZSS_EPOCH;

    /** Reference epoch for IRNSS weeks: 1999-08-22. */
    static const DateComponents IRNSS_EPOCH;

    /** Reference epoch for BeiDou weeks: 2006-01-01. */
    static const DateComponents BEIDOU_EPOCH;

    /** Reference epoch for GLONASS four-year interval number: 1996-01-01. */
    static const DateComponents GLONASS_EPOCH;

    /** J2000.0 Reference epoch: 2000-01-01. */
    static const DateComponents J2000_EPOCH;

    /** Java Reference epoch: 1970-01-01. */
    static const DateComponents JAVA_EPOCH;

    /** Maximum supported date.
     * <p>
     * This is date 5881610-07-11 which corresponds to {@code Integer.MAX_VALUE}
     * days after {@link #J2000_EPOCH}.
     * </p>
     * @since 9.0
     */
    static const DateComponents MAX_EPOCH;

    /** Maximum supported date.
     * <p>
     * This is date -5877490-03-03, which corresponds to {@code Integer.MIN_VALUE}
     * days before {@link #J2000_EPOCH}.
     * </p>
     * @since 9.0
     */
    static const DateComponents MIN_EPOCH;

    /** Serializable UID. */
    static const int64_t serialVersionUID = -2462694707837970938L;

private:
    /** Get the monday of a year first week.
     * @param year year to consider
     * @return day of the monday of the first weak of year
     */
    static int getFirstWeekMonday(const int year);

    /** Factory for proleptic julian calendar (up to 0000-12-31). */
    static const YearFactory* PROLEPTIC_JULIAN_FACTORY;

    /** Factory for julian calendar (from 0001-01-01 to 1582-10-04). */
    static const YearFactory* JULIAN_FACTORY;

    /** Factory for gregorian calendar (from 1582-10-15). */
    static const YearFactory* GREGORIAN_FACTORY;

    /** Factory for leap years. */
    static const MonthDayFactory* LEAP_YEAR_FACTORY;

    /** Factory for non-leap years. */
    static const MonthDayFactory* COMMON_YEAR_FACTORY;

    /** Offset between J2000 epoch and modified julian day epoch. */
    static const int MJD_TO_J2000 = 51544;
};

#endif // !_DATA_COMPONENTS_H
