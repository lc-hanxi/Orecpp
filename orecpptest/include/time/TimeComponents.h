#ifndef _TIME_COMPONENTS_H_
#define _TIME_COMPONENTS_H_

#include <stdint.h>

/** Class representing a time within the day broken up as hour,
 * minute and second components.
 * <p>Instances of this class are guaranteed to be immutable.</p>
 * @see DateComponents
 * @see DateTimeComponents
 * @author Luc Maisonobe
 */
class TimeComponents 
{
public:
    TimeComponents() = default;
    /** Build a time from its clock elements.
     * <p>Note that seconds between 60.0 (inclusive) and 61.0 (exclusive) are allowed
     * in this method, since they do occur during leap seconds introduction
     * in the {@link UTCScale UTC} time scale.</p>
     * @param hour hour number from 0 to 23
     * @param minute minute number from 0 to 59
     * @param second second number from 0.0 to 61.0 (excluded)
     * @exception IllegalArgumentException if inconsistent arguments
     * are given (parameters out of range)
     */
    TimeComponents(int hour, int minute, double second);

    /** Build a time from its clock elements.
     * <p>Note that seconds between 60.0 (inclusive) and 61.0 (exclusive) are allowed
     * in this method, since they do occur during leap seconds introduction
     * in the {@link UTCScale UTC} time scale.</p>
     * @param hour hour number from 0 to 23
     * @param minute minute number from 0 to 59
     * @param second second number from 0.0 to 61.0 (excluded)
     * @param minutesFromUTC offset between the specified date and UTC, as an
     * integral number of minutes, as per ISO-8601 standard
     * @exception IllegalArgumentException if inconsistent arguments
     * are given (parameters out of range)
     * @since 7.2
     */
    TimeComponents(int hour, int minute, double second, int minutesFromUTC);

    /**
     * Build a time from the second number within the day.
     *
     * <p>If the {@code secondInDay} is less than {@code 60.0} then {@link #getSecond()}
     * will be less than {@code 60.0}, otherwise it will be less than {@code 61.0}. This constructor
     * may produce an invalid value of {@link #getSecond()} during a negative leap second,
     * through there has never been one. For more control over the number of seconds in
     * the final minute use {@link #fromSeconds(int, double, double, int)}.
     *
     * <p>This constructor is always in UTC (i.e. {@link #getMinutesFromUTC() will return
     * 0}).
     *
     * @param secondInDay second number from 0.0 to {@link Constants#JULIAN_DAY} {@code +
     *                    1} (excluded)
     * @throws OrekitIllegalArgumentException if seconds number is out of range
     * @see #fromSeconds(int, double, double, int)
     * @see #TimeComponents(int, double)
     */
    TimeComponents(double secondInDay);

    /**
     * Build a time from the second number within the day.
     *
     * <p>The second number is defined here as the sum
     * {@code secondInDayA + secondInDayB} from 0.0 to {@link Constants#JULIAN_DAY}
     * {@code + 1} (excluded). The two parameters are used for increased accuracy.
     *
     * <p>If the sum is less than {@code 60.0} then {@link #getSecond()} will be less
     * than {@code 60.0}, otherwise it will be less than {@code 61.0}. This constructor
     * may produce an invalid value of {@link #getSecond()} during a negative leap second,
     * through there has never been one. For more control over the number of seconds in
     * the final minute use {@link #fromSeconds(int, double, double, int)}.
     *
     * <p>This constructor is always in UTC (i.e. {@link #getMinutesFromUTC()} will
     * return 0).
     *
     * @param secondInDayA first part of the second number
     * @param secondInDayB last part of the second number
     * @throws OrekitIllegalArgumentException if seconds number is out of range
     * @see #fromSeconds(int, double, double, int)
     */
    TimeComponents(int secondInDayA, double secondInDayB);

    /**
     * Build a time from the second number within the day.
     *
     * <p>The seconds past midnight is the sum {@code secondInDayA + secondInDayB +
     * leap}. The two parameters are used for increased accuracy. Only the first part of
     * the sum ({@code secondInDayA + secondInDayB}) is used to compute the hours and
     * minutes. The third parameter ({@code leap}) is added directly to the second value
     * ({@link #getSecond()}) to implement leap seconds. These three quantities must
     * satisfy the following constraints. This first guarantees the hour and minute are
     * valid, the second guarantees the second is valid.
     *
     * <pre>
     *     {@code 0 <= secondInDayA + secondInDayB < 86400}
     *     {@code 0 <= (secondInDayA + secondInDayB) % 60 + leap < minuteDuration}
     *     {@code 0 <= leap <= minuteDuration - 60                        if minuteDuration >= 60}
     *     {@code 0 >= leap >= minuteDuration - 60                        if minuteDuration <  60}
     * </pre>
     *
     * <p>If the seconds of minute ({@link #getSecond()}) computed from {@code
     * secondInDayA + secondInDayB + leap} is greater than or equal to {@code
     * minuteDuration} then the second of minute will be set to {@code
     * FastMath.nextDown(minuteDuration)}. This prevents rounding to an invalid seconds of
     * minute number when the input values have greater precision than a {@code double}.
     *
     * <p>This constructor is always in UTC (i.e. {@link #getMinutesFromUTC() will return
     * 0}).
     *
     * <p>If {@code secondsInDayB} or {@code leap} is NaN then the hour and minute will
     * be determined from {@code secondInDayA} and the second of minute will be NaN.
     *
     * <p>This constructor is private to avoid confusion with the other constructors that
     * would be caused by overloading. Use {@link #fromSeconds(int, double, double,
     * int)}.
     *
     * @param secondInDayA   first part of the second number.
     * @param secondInDayB   last part of the second number.
     * @param leap           magnitude of the leap second if this point in time is during
     *                       a leap second, otherwise {@code 0.0}. This value is not used
     *                       to compute hours and minutes, but it is added to the computed
     *                       second of minute.
     * @param minuteDuration number of seconds in the current minute, normally {@code 60}.
     * @throws OrekitIllegalArgumentException if the inequalities above do not hold.
     * @see #fromSeconds(int, double, double, int)
     * @since 10.2
     */
    static TimeComponents fromSeconds(int secondInDayA, double secondInDayB, double leap, int minuteDuration);

    /** Get the hour number.
     * @return hour number from 0 to 23
     */
    int getHour() const;

    /** Get the minute number.
     * @return minute minute number from 0 to 59
     */
    int getMinute() const;

    /** Get the seconds number.
     * @return second second number from 0.0 to 61.0 (excluded). Note that 60 &le; second
     * &lt; 61 only occurs during a leap second.
     */
    double getSecond() const;

    /** Get the offset between the specified date and UTC.
     * <p>
     * The offset is always an integral number of minutes, as per ISO-8601 standard.
     * </p>
     * @return offset in minutes between the specified date and UTC
     * @since 7.2
     */
    int getMinutesFromUTC() const;

    /** Get the second number within the local day, <em>without</em> applying the {@link #getMinutesFromUTC() offset from UTC}.
     * @return second number from 0.0 to Constants.JULIAN_DAY
     * @see #getSecondsInUTCDay()
     * @since 7.2
     */
    double getSecondsInLocalDay() const;

    /** Get the second number within the UTC day, applying the {@link #getMinutesFromUTC() offset from UTC}.
     * @return second number from {@link #getMinutesFromUTC() -getMinutesFromUTC()}
     * to Constants.JULIAN_DAY {@link #getMinutesFromUTC() + getMinutesFromUTC()}
     * @see #getSecondsInLocalDay()
     * @since 7.2
     */
    double getSecondsInUTCDay() const;


    /** {@inheritDoc} */
    bool operator<(const TimeComponents& other) const;

    /** {@inheritDoc} */
    bool operator==(const TimeComponents& other) const;

    /** {@inheritDoc} */
    int hashCode() const;

private:
    /**
     * Build a time from the second number within the day.
     *
     * <p>The seconds past midnight is the sum {@code secondInDayA + secondInDayB +
     * leap}. The two parameters are used for increased accuracy. Only the first part of
     * the sum ({@code secondInDayA + secondInDayB}) is used to compute the hours and
     * minutes. The third parameter ({@code leap}) is added directly to the second value
     * ({@link #getSecond()}) to implement leap seconds. These three quantities must
     * satisfy the following constraints. This first guarantees the hour and minute are
     * valid, the second guarantees the second is valid.
     *
     * <pre>
     *     {@code 0 <= secondInDayA + secondInDayB < 86400}
     *     {@code 0 <= (secondInDayA + secondInDayB) % 60 + leap <= minuteDuration}
     *     {@code 0 <= leap <= minuteDuration - 60                        if minuteDuration >= 60}
     *     {@code 0 >= leap >= minuteDuration - 60                        if minuteDuration <  60}
     * </pre>
     *
     * <p>If the seconds of minute ({@link #getSecond()}) computed from {@code
     * secondInDayA + secondInDayB + leap} is greater than or equal to {@code 60 + leap}
     * then the second of minute will be set to {@code FastMath.nextDown(60 + leap)}. This
     * prevents rounding to an invalid seconds of minute number when the input values have
     * greater precision than a {@code double}.
     *
     * <p>This constructor is always in UTC (i.e. {@link #getMinutesFromUTC() will return
     * 0}).
     *
     * <p>If {@code secondsInDayB} or {@code leap} is NaN then the hour and minute will
     * be determined from {@code secondInDayA} and the second of minute will be NaN.
     *
     * @param secondInDayA   first part of the second number.
     * @param secondInDayB   last part of the second number.
     * @param leap           magnitude of the leap second if this point in time is during
     *                       a leap second, otherwise {@code 0.0}. This value is not used
     *                       to compute hours and minutes, but it is added to the computed
     *                       second of minute.
     * @param minuteDuration number of seconds in the current minute, normally {@code 60}.
     * @return new time components for the specified time.
     * @throws OrekitIllegalArgumentException if the inequalities above do not hold.
     * @since 10.2
     */
     TimeComponents(int secondInDayA, double secondInDayB, double leap, int minuteDuration);

public:
    /** Constant for commonly used hour 00:00:00. */
    static const TimeComponents H00;

    /** Constant for commonly used hour 12:00:00. */
    static const TimeComponents H12;

private:

    /** Serializable UID. */
    static const int64_t serialVersionUID = 20160331L;

    /** Hour number. */
    int hour;

    /** Minute number. */
    int minute;

    /** Second number. */
    double second;

    /** Offset between the specified date and UTC.
     * <p>
     * Always an integral number of minutes, as per ISO-8601 standard.
     * </p>
     * @since 7.2
     */
    int minutesFromUTC;
};

#endif