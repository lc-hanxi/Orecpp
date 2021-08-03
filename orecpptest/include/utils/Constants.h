#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

namespace Constants {
    /** Speed of light: 299792458.0 m/s. */
    const double SPEED_OF_LIGHT = 299792458.0;

    /** Astronomical unit as a conventional unit of length since IAU 2012 resolution B2: 149597870700.0 m.
     * @see <a href="http://www.iau.org/static/resolutions/IAU2012_English.pdf">IAU 2012 resolutions</a>
     */
    const double IAU_2012_ASTRONOMICAL_UNIT = 149597870700.0;

    /** Solar radius as defined by IAU 2015 resolution B3: 695700000.0 m.
     * @see <a href="https://www.iau.org/static/resolutions/IAU2015_English.pdf">IAU 2015 resolutions</a>
     */
    const double IAU_2015_NOMINAL_SOLAR_RADIUS = 695700000.0;

    /** Sun attraction coefficient as defined by IAU 2015 resolution B3: 1.3271244e20 (m³/s²). */
    const double IAU_2015_NOMINAL_SUN_GM = 1.3271244e20;

    /** Earth equatorial radius as defined by IAU 2015 resolution B3: 6.3781e6 (m). */
    const double IAU_2015_NOMINAL_EARTH_EQUATORIAL_RADIUS = 6.3781e6;

    /** Earth polar radius as defined by IAU 2015 resolution B3: 6.3568e6 (m). */
    const double IAU_2015_NOMINAL_EARTH_POLAR_RADIUS = 6.3568e6;

    /** Earth attraction coefficient as defined by IAU 2015 resolution B3: 3.986004e14 (m³/s²). */
    const double IAU_2015_NOMINAL_EARTH_GM = 3.986004e14;

    /** Jupiter equatorial radius as defined by IAU 2015 resolution B3: 7.1492e7 (m). */
    const double IAU_2015_NOMINAL_JUPITER_EQUATORIAL_RADIUS = 7.1492e7;

    /** Jupiter polar radius as defined by IAU 2015 resolution B3: 6.6854e7 (m). */
    const double IAU_2015_NOMINAL_JUPITER_POLAR_RADIUS = 6.6854e7;

    /** Jupiter attraction coefficient as defined by IAU 2015 resolution B3: 1.2668653e17 (m³/s²). */
    const double IAU_2015_NOMINAL_JUPITER_GM = 1.2668653e17;

    /** Duration of a mean solar day: 86400.0 s. */
    const double JULIAN_DAY = 86400.0;

    /** Duration of a Julian year: 365.25 {@link #JULIAN_DAY}. */
    const double JULIAN_YEAR = 31557600.0;

    /** Duration of a Julian century: 36525 {@link #JULIAN_DAY}. */
    const double JULIAN_CENTURY = 36525 * JULIAN_DAY;


    /** Duration of a Besselian year: 365.242198781 {@link #JULIAN_DAY}. */
    const double BESSELIAN_YEAR = 365.242198781 * JULIAN_DAY;


    /** Conversion factor from arc seconds to radians: 2*PI/(360*60*60). */
    //double ARC_SECONDS_TO_RADIANS = MathUtils.TWO_PI / 1296000;


    /** Standard gravity constant, used in maneuvers definition: 9.80665 m/s². */
    const double G0_STANDARD_GRAVITY = 9.80665;


    /** Sun radius: 695500000 m. */
    const double SUN_RADIUS = 6.955e8;

    /** Moon equatorial radius: 1737400 m. */
    const double MOON_EQUATORIAL_RADIUS = 1737400.0;


    /** Earth equatorial radius from WGS84 model: 6378137.0 m. */
    const double WGS84_EARTH_EQUATORIAL_RADIUS = 6378137.0;

    /** Earth flattening from WGS84 model: 1.0 / 298.257223563. */
    const double WGS84_EARTH_FLATTENING = 1.0 / 298.257223563;

    /** Earth angular velocity from WGS84 model: 7.292115e-5 rad/s. */
    const double WGS84_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from WGS84 model: 3.986004418e14 m³/s². */
    const double WGS84_EARTH_MU = 3.986004418e14;

    /** Earth un-normalized second zonal coefficient from WGS84 model: . */
    const double WGS84_EARTH_C20 = -1.08262668355315e-3;


    /** Earth equatorial radius from GRS80 model: 6378137.0 m. */
    const double GRS80_EARTH_EQUATORIAL_RADIUS = 6378137.0;

    /** Earth flattening from GRS80 model: 1.0 / 298.257222101. */
    const double GRS80_EARTH_FLATTENING = 1.0 / 298.257222101;

    /** Earth angular velocity from GRS80 model: 7.292115e-5 rad/s. */
    const double GRS80_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from GRS80 model: 3.986005e14 m³/s². */
    const double GRS80_EARTH_MU = 3.986005e14;

    /** Earth un-normalized second zonal coefficient from GRS80 model: -1.08263e-3. */
    const double GRS80_EARTH_C20 = -1.08263e-3;


    /** Earth equatorial radius from EGM96 model: 6378136.3 m. */
    const double EGM96_EARTH_EQUATORIAL_RADIUS = 6378136.3;

    /** Earth gravitational constant from EGM96 model: 3.986004415e14 m³/s². */
    const double EGM96_EARTH_MU = 3.986004415e14;

    /** Earth un-normalized second zonal coefficient from EGM96 model: -1.08262668355315e-3. */
    const double EGM96_EARTH_C20 = -1.08262668355315e-3;

    /** Earth un-normalized third zonal coefficient from EGM96 model: 2.53265648533224e-6. */
    const double EGM96_EARTH_C30 = 2.53265648533224e-6;

    /** Earth un-normalized fourth zonal coefficient from EGM96 model: 1.619621591367e-6. */
    const double EGM96_EARTH_C40 = 1.619621591367e-6;

    /** Earth un-normalized fifth zonal coefficient from EGM96 model: 2.27296082868698e-7. */
    const double EGM96_EARTH_C50 = 2.27296082868698e-7;

    /** Earth un-normalized sixth zonal coefficient from EGM96 model: -5.40681239107085e-7. */
    const double EGM96_EARTH_C60 = -5.40681239107085e-7;


    /** Earth equatorial radius from GRIM5C1 model: 6378136.46 m. */
    const double GRIM5C1_EARTH_EQUATORIAL_RADIUS = 6378136.46;

    /** Earth flattening from GRIM5C1 model: 1.0 / 298.25765. */
    const double GRIM5C1_EARTH_FLATTENING = 1.0 / 298.25765;

    /** Earth angular velocity from GRIM5C1 model: 7.292115e-5 rad/s. */
    const double GRIM5C1_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from GRIM5C1 model: 3.986004415e14 m³/s². */
    const double GRIM5C1_EARTH_MU = 3.986004415e14;

    /** Earth un-normalized second zonal coefficient from GRIM5C1 model: -1.082626110612609e-3. */
    const double GRIM5C1_EARTH_C20 = -1.082626110612609e-3;

    /** Earth un-normalized third zonal coefficient from GRIM5C1 model: 2.536150841690056e-6. */
    const double GRIM5C1_EARTH_C30 = 2.536150841690056e-6;

    /** Earth un-normalized fourth zonal coefficient from GRIM5C1 model: 1.61936352497151e-6. */
    const double GRIM5C1_EARTH_C40 = 1.61936352497151e-6;

    /** Earth un-normalized fifth zonal coefficient from GRIM5C1 model: 2.231013736607540e-7. */
    const double GRIM5C1_EARTH_C50 = 2.231013736607540e-7;

    /** Earth un-normalized sixth zonal coefficient from GRIM5C1 model: -5.402895357302363e-7. */
    const double GRIM5C1_EARTH_C60 = -5.402895357302363e-7;


    /** Earth equatorial radius from EIGEN5C model: 6378136.46 m. */
    const double EIGEN5C_EARTH_EQUATORIAL_RADIUS = 6378136.46;

    /** Earth gravitational constant from EIGEN5C model: 3.986004415e14 m³/s². */
    const double EIGEN5C_EARTH_MU = 3.986004415e14;

    /** Earth un-normalized second zonal coefficient from EIGEN5C model: -1.082626457231767e-3. */
    const double EIGEN5C_EARTH_C20 = -1.082626457231767e-3;

    /** Earth un-normalized third zonal coefficient from EIGEN5C model: 2.532547231862799e-6. */
    const double EIGEN5C_EARTH_C30 = 2.532547231862799e-6;

    /** Earth un-normalized fourth zonal coefficient from EIGEN5C model: 1.619964434136e-6. */
    const double EIGEN5C_EARTH_C40 = 1.619964434136e-6;

    /** Earth un-normalized fifth zonal coefficient from EIGEN5C model: 2.277928487005437e-7. */
    const double EIGEN5C_EARTH_C50 = 2.277928487005437e-7;

    /** Earth un-normalized sixth zonal coefficient from EIGEN5C model: -5.406653715879098e-7. */
    const double EIGEN5C_EARTH_C60 = -5.406653715879098e-7;

    /** Earth equatorial radius from IERS96 model: 6378136.49 m. */
    const double IERS96_EARTH_EQUATORIAL_RADIUS = 6378136.49;

    /** Earth flattening from IERS96 model: 1.0 / 298.25642. */
    const double IERS96_EARTH_FLATTENING = 1.0 / 298.25642;

    /** Earth angular velocity from IERS96 model: 7.292115e-5 rad/s. */
    const double IERS96_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from IERS96 model: 3.986004418e14 m³/s². */
    const double IERS96_EARTH_MU = 3.986004418e14;

    /** Earth un-normalized second zonal coefficient from IERS96 model: -1.0826359e-3. */
    const double IERS96_EARTH_C20 = -1.0826359e-3;

    /** Earth equatorial radius from IERS2003 model: 6378136.6 m. */
    const double IERS2003_EARTH_EQUATORIAL_RADIUS = 6378136.6;

    /** Earth flattening from IERS2003 model: 1.0 / 298.25642. */
    const double IERS2003_EARTH_FLATTENING = 1.0 / 298.25642;

    /** Earth angular velocity from IERS2003 model: 7.292115e-5 rad/s. */
    const double IERS2003_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from IERS2003 model: 3.986004418e14 m³/s². */
    const double IERS2003_EARTH_MU = 3.986004418e14;

    /** Earth un-normalized second zonal coefficient from IERS2003 model: -1.0826359e-3. */
    const double IERS2003_EARTH_C20 = -1.0826359e-3;

    /** Earth equatorial radius from IERS2010 model: 6378136.6 m. */
    const double IERS2010_EARTH_EQUATORIAL_RADIUS = 6378136.6;

    /** Earth flattening from IERS2010 model: 1.0 / 298.25642. */
    const double IERS2010_EARTH_FLATTENING = 1.0 / 298.25642;

    /** Earth angular velocity from IERS2010 model: 7.292115e-5 rad/s. */
    const double IERS2010_EARTH_ANGULAR_VELOCITY = 7.292115e-5;

    /** Earth gravitational constant from IERS2010 model: 3.986004418e14 m³/s². */
    const double IERS2010_EARTH_MU = 3.986004418e14;

    /** Earth un-normalized second zonal coefficient from IERS2010 model: -1.0826359e-3. */
    const double IERS2010_EARTH_C20 = -1.0826359e-3;

    /** Gaussian gravitational constant: 0.01720209895 √(AU³/d²). */
    const double JPL_SSD_GAUSSIAN_GRAVITATIONAL_CONSTANT = 0.01720209895;

    /** Astronomical Unit: 149597870691 m. */
    const double JPL_SSD_ASTRONOMICAL_UNIT = 149597870691.0;

    /** Sun attraction coefficient (m³/s²). */
    const double JPL_SSD_SUN_GM = JPL_SSD_GAUSSIAN_GRAVITATIONAL_CONSTANT * JPL_SSD_GAUSSIAN_GRAVITATIONAL_CONSTANT *
        JPL_SSD_ASTRONOMICAL_UNIT * JPL_SSD_ASTRONOMICAL_UNIT * JPL_SSD_ASTRONOMICAL_UNIT /
        (JULIAN_DAY * JULIAN_DAY);

    /** Sun/Mercury mass ratio: 6023600. */
    const double JPL_SSD_SUN_MERCURY_MASS_RATIO = 6023600;

    /** Sun/Mercury attraction coefficient (m³/s²). */
    const double JPL_SSD_MERCURY_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_MERCURY_MASS_RATIO;

    /** Sun/Venus mass ratio: 408523.71. */
    const double JPL_SSD_SUN_VENUS_MASS_RATIO = 408523.71;

    /** Sun/Venus attraction coefficient (m³/s²). */
    const double JPL_SSD_VENUS_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_VENUS_MASS_RATIO;

    /** Sun/(Earth + Moon) mass ratio: 328900.56. */
    const double JPL_SSD_SUN_EARTH_PLUS_MOON_MASS_RATIO = 328900.56;

    /** Sun/(Earth + Moon) attraction coefficient (m³/s²). */
    const double JPL_SSD_EARTH_PLUS_MOON_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_EARTH_PLUS_MOON_MASS_RATIO;

    /** Earth/Moon mass ratio: 81.30059. */
    const double JPL_SSD_EARTH_MOON_MASS_RATIO = 81.300596;

    /** Moon attraction coefficient (m³/s²). */
    const double JPL_SSD_MOON_GM = JPL_SSD_EARTH_PLUS_MOON_GM / (1.0 + JPL_SSD_EARTH_MOON_MASS_RATIO);

    /** Earth attraction coefficient (m³/s²). */
    const double JPL_SSD_EARTH_GM = JPL_SSD_MOON_GM * JPL_SSD_EARTH_MOON_MASS_RATIO;

    /** Sun/(Mars system) mass ratio: 3098708.0. */
    const double JPL_SSD_SUN_MARS_SYSTEM_MASS_RATIO = 3098708.0;

    /** Sun/(Mars system) attraction coefficient (m³/s²). */
    const double JPL_SSD_MARS_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_MARS_SYSTEM_MASS_RATIO;

    /** Sun/(Jupiter system) mass ratio: 1047.3486. */
    const double JPL_SSD_SUN_JUPITER_SYSTEM_MASS_RATIO = 1047.3486;

    /** Sun/(Jupiter system) ttraction coefficient (m³/s²). */
    const double JPL_SSD_JUPITER_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_JUPITER_SYSTEM_MASS_RATIO;

    /** Sun/(Saturn system) mass ratio: 3497.898. */
    const double JPL_SSD_SUN_SATURN_SYSTEM_MASS_RATIO = 3497.898;

    /** Sun/(Saturn system) attraction coefficient (m³/s²). */
    const double JPL_SSD_SATURN_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_SATURN_SYSTEM_MASS_RATIO;

    /** Sun/(Uranus system) mass ratio: 22902.98. */
    const double JPL_SSD_SUN_URANUS_SYSTEM_MASS_RATIO = 22902.98;

    /** Sun/(Uranus system) attraction coefficient (m³/s²). */
    const double JPL_SSD_URANUS_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_URANUS_SYSTEM_MASS_RATIO;

    /** Sun/(Neptune system) mass ratio: 19412.24. */
    const double JPL_SSD_SUN_NEPTUNE_SYSTEM_MASS_RATIO = 19412.24;

    /** Sun/(Neptune system) attraction coefficient (m³/s²). */
    const double JPL_SSD_NEPTUNE_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_NEPTUNE_SYSTEM_MASS_RATIO;

    /** Sun/(Pluto system) mass ratio: 1.35e8. */
    const double JPL_SSD_SUN_PLUTO_SYSTEM_MASS_RATIO = 1.35e8;

    /** Sun/(Pluto system) ttraction coefficient (m³/s²). */
    const double JPL_SSD_PLUTO_SYSTEM_GM = JPL_SSD_SUN_GM / JPL_SSD_SUN_PLUTO_SYSTEM_MASS_RATIO;

};

#endif