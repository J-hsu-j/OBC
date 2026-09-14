/*
 * Copyright (c) 2020-2022 EnduroSat AD. All rights reserved.
 *
 * Contents and presentations are protected world-wide.
 * Any kind of using, copying etc. is prohibited without prior permission.
 */
/*
 * @addtogroup igrf
 * @{
 *
 * @file  igrf.h
 * @brief IGRF magnetic field model types and function declarations.
 *
 * @}
 */

#ifndef IGRF_IGRF_H
#define IGRF_IGRF_H


#include <stdint.h>


#if IGRF_USE_TYPE_FLOAT
typedef float igrf_t;
#else
typedef double igrf_t;
#endif

typedef struct
{
    union
    {
        struct
        {
            igrf_t x;
            igrf_t y;
            igrf_t z;
        };
        igrf_t vec[3];
    };
} igrf_vec_t;

typedef struct igrf_mag_field
{
    // Spherical coordinates in Earth-Centered-Earth-Fixed ECEF
    igrf_t b_radius;
    igrf_t b_theta;
    igrf_t b_phi;
    // Cartesian coordinates in Earth-Centered_Earth-Fixed ECEF
    igrf_vec_t b_fixed;
    // Earth-Centered-Inertial Frame ECI
    igrf_vec_t b_inertial;
} igrf_mag_field_t;

/**
* @brief Function is used to initialize the Schmidt normalization coefficients
* @return            igrf_mag_field_t fp_sMag with the updated B field components.
* @note              Must be called only once to initialize before calling the
*                    @ref igrf_compute_magnetic_field() function.
*/
void igrf_init(void);

/**
* @brief Function that calculated the magnetic field strength using the IGRF model.
* @param[input]      igrf_t fp_dradius Geocentric radius in m
*                    igrf_t fp_dtheta latitude in degrees
*                    igrf_t fp_dphi longitude in degrees
*                    uint16_t fp_u16n Number of iterations for calculating B field
*                    igrf_t fp_djd JDN for calculating inertial frame vectors.
* @return            igrf_mag_field_t  containing the Magnetic field strength in Spherical, ECF, and ECI frames (T).
* @note              N = 1-13, lower numbers can be used for lower accuracy.
*                    references: https://hanspeterschaub.info/Papers/UnderGradStudents/MagneticField.pdf
*/
igrf_mag_field_t igrf_compute_magnetic_field(double fp_dradius, double fp_dtheta, double fp_dphi, uint16_t fp_u16n, double fp_djd);

#endif /* IGRF_IGRF_H */
