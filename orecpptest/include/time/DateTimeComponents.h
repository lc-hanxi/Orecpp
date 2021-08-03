#ifndef _DATE_TIME_COMPONENTS_H_
#define _DATE_TIME_COMPONENTS_H_

#include <stdint.h>
#include "time/DateComponents.h"
#include "time/TimeComponents.h"

/** Holder for date and time components.
 * <p>This class is a simple holder with no processing methods.</p>
 * <p>Instance of this class are guaranteed to be immutable.</p>
 * @see AbsoluteDate
 * @see DateComponents
 * @see TimeComponents
 * @author Luc Maisonobe
 */
class DateTimeComponents
{
public:
    /**
     * The Julian Epoch.
     *
     * @see TimeScales#getJulianEpoch()
     */
    static const DateTimeComponents* JULIAN_EPOCH;

private:
    /** Serializable UID. */
    static const int64_t serialVersionUID = 5061129505488924484L;

    /** Date component. */
    DateComponents date;

    /** Time component. */
    TimeComponents time;

public:
    /** Build a new instance from its components.
     * @param date date component
     * @param time time component
     */
    DateTimeComponents(DateComponents date, TimeComponents time);

    /** Build an instance from raw level components.
     * @param year year number (may be 0 or negative for BC years)
     * @param month month number from 1 to 12
     * @param day day number from 1 to 31
     * @param hour hour number from 0 to 23
     * @param minute minute number from 0 to 59
     * @param second second number from 0.0 to 60.0 (excluded)
     * @exception IllegalArgumentException if inconsistent arguments
     * are given (parameters out of range, february 29 for non-leap years,
     * dates during the gregorian leap in 1582 ...)
     */
    DateTimeComponents(int year, int month, int day, int hour, int minute, double second);

    /** Build an instance from raw level components.
     * <p>The hour is set to 00:00:00.000.</p>
     * @param year year number (may be 0 or negative for BC years)
     * @param month month number from 1 to 12
     * @param day day number from 1 to 31
     * @exception IllegalArgumentException if inconsistent arguments
     * are given (parameters out of range, february 29 for non-leap years,
     * dates during the gregorian leap in 1582 ...)
     */
    DateTimeComponents(int year, int month, int day);

    /** Build an instance from a seconds offset with respect to another one.
     * @param reference reference date/time
     * @param offset offset from the reference in seconds
     * @see #offsetFrom(DateTimeComponents)
     */
    DateTimeComponents(const DateTimeComponents& reference, double offset);

    /** Compute the seconds offset between two instances.
     * @param dateTime dateTime to subtract from the instance
     * @return offset in seconds between the two instants
     * (positive if the instance is posterior to the argument)
     * @see #DateTimeComponents(DateTimeComponents, double)
     */
    double offsetFrom(const DateTimeComponents& dateTime) const;

    /** Get the date component.
     * @return date component
     */
    DateComponents getDate() const;

    /** Get the time component.
     * @return time component
     */
    TimeComponents getTime() const;

    /** {@inheritDoc} */
    bool operator<(const DateTimeComponents& other) const;

    /** {@inheritDoc} */
    bool operator==(const DateTimeComponents& other) const;


    /** {@inheritDoc} */
    int hashCode() const;

};

#endif