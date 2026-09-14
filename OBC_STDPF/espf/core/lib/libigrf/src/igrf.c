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
 * @file  igrf.c
 * @brief IGRF magnetic field model types and function definitions.
 *
 * @}
 */

#include "igrf.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>


#define JD_CONV_COEFF_1 1721013.5f
#define JD_CONV_COEFF_2 367.0f
#define JD_CONV_COEFF_3 7.0f
#define JD_CONV_COEFF_4 4.0f
#define JD_CONV_COEFF_5 9.0f
#define JD_CONV_COEFF_6 12.0f
#define JD_CONV_COEFF_7 275.0f
#define JD_CONV_COEFF_8 9.0f
#define JD_CONV_COEFF_9 60.0f
#define JD_CONV_COEFF_10 1440.0f
#define DEG_TO_RAD (M_PI / 180)
#define RAD_TO_DEG (180 / M_PI)
#define EARTH_RADIUS 6371.2f
#define DAYS_IN_YEAR 365
#define START_JD_OF_MODEL 2458849.499988f


static const igrf_t fs_dg1[]  = { -29404.8, -1450.90 };
static const igrf_t fs_dg2[]  = { -2499.60, 2982.0, 1677.0 };
static const igrf_t fs_dg3[]  = { 1363.20, -2381.20, 1236.20, 525.70 };
static const igrf_t fs_dg4[]  = { 903.0, 809.50, 86.30, -309.40, 48.00 };
static const igrf_t fs_dg5[]  = { -234.30, 363.20, 187.80, -140.70, -151.20, 13.5 };
static const igrf_t fs_dg6[]  = { 66.00, 65.50, 72.90, -121.50, -36.20, 13.50, -64.70 };
static const igrf_t fs_dg7[]  = { 80.60, -76.70, -8.20, 56.50, 15.80, 6.40, -7.20, 9.80 };
static const igrf_t fs_dg8[]  = { 23.70, 9.70, -17.60, -0.50, -21.10, 15.30, 13.70, -16.50, -0.30 };
static const igrf_t fs_dg9[]  = { 5.00, 8.40, 2.90, -1.50, -1.10, -13.20, 1.10, 8.80, -9.30, -11.90 };
static const igrf_t fs_dg10[] = { -1.90, -6.20, -0.10, 1.70, -0.90, 0.7, -0.9, 1.90, 1.40, -2.40, -3.80 };
static const igrf_t fs_dg11[] = { 3, -1.4, -2.5, 2.3, -0.9, 0.3, -0.7, -0.1, 1.4, -0.6, 0.2, 3.1 };
static const igrf_t fs_dg12[] = { -2.0, -0.1, 0.5, 1.3, -1.2, 0.7, 0.3, 0.5, -0.3, -0.5, 0.1, -1.1, -0.3 };
static const igrf_t fs_dg13[] = { 0.1, -0.9, 0.5, 0.7, -0.3, 0.8, 0, 0.8, 0, 0.4, 0.1, 0.5, -0.5, -0.4 };
// hnm gauss coefficients (units of nanoTesla)
static const igrf_t fs_dh1[]  = { 0, 4652.5 };
static const igrf_t fs_dh2[]  = { 0, -2991.60, -734.60 };
static const igrf_t fs_dh3[]  = { 0, -82.10, 241.90, -543.40 };
static const igrf_t fs_dh4[]  = { 0, 281.90, -158.40, 199.70, -349.70 };
static const igrf_t fs_dh5[]  = { 0, 47.70, 208.30, -121.20, 32.30, 98.90 };
static const igrf_t fs_dh6[]  = { 0, -19.10, 25.10, 52.80, -64.50, 8.90, 68.10 };
static const igrf_t fs_dh7[]  = { 0, -51.50, -16.90, 2.20, 23.50, -2.20, -27.20, -1.80 };
static const igrf_t fs_dh8[]  = { 0, 8.40, -15.30, 12.80, -11.70, 14.90, 3.60, -6.90, 2.80 };
static const igrf_t fs_dh9[]  = { 0, -23.40, 11.00, 9.80, -5.10, -6.30, 7.80, 0.40, -1.40, 9.60 };
static const igrf_t fs_dh10[] = { 0, 3.40, -0.20, 3.60, 4.80, -8.60, -0.10, -4.30, -3.40, -0.10, -8.8 };
static const igrf_t fs_dh11[] = { 0, 0, 2.5, -0.6, -0.4, 0.6, -0.2, -1.7, -1.6, -3, -2, -2.6 };
static const igrf_t fs_dh12[] = { 0, -1.2, 0.5, 1.4, -1.8, 0.1, 0.8, -0.2, 0.6, 0.2, -0.9, 0, 0.5 };
static const igrf_t fs_dh13[] = { 0, -0.9, 0.6, 1.4, -0.4, -1.3, -0.1, 0.3, -0.1, 0.5, 0.5, -0.4, -0.4, -0.6 };
// Secular Variation coefficients for g (units of nanoTesla/year)
static const igrf_t fs_dsvg1[]  = { 5.7, 7.4 };
static const igrf_t fs_dsvg2[]  = { -11, -7, -2.1 };
static const igrf_t fs_dsvg3[]  = { 2.2, -5.9, 3.10, -12 };
static const igrf_t fs_dsvg4[]  = { -1.2, -1.6, -5.9, 5.2, -5.1 };
static const igrf_t fs_dsvg5[]  = { -0.3, 0.5, -0.6, 0.2, 1.3, 0.9 };
static const igrf_t fs_dsvg6[]  = { -0.5, -0.3, 0.4, 1.3, -1.4, 0, 0.9 };
static const igrf_t fs_dsvg7[]  = { -0.1, -0.2, 0, 0.7, 0.1, -0.5, -0.8, 0.8 };
static const igrf_t fs_dsvg8[]  = { 0, 0.1, -0.1, 0.4, -0.1, 0.4, 0.3, -0.1, 0.4 };
static const igrf_t fs_dsvg9[]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvg10[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvg11[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvg12[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvg13[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
// Secular Variation coefficients for h (units of nanoTesla/year)
static const igrf_t fs_dsvh1[]  = { 0, -25.9 };
static const igrf_t fs_dsvh2[]  = { 0, -30.2, -22.4 };
static const igrf_t fs_dsvh3[]  = { 0, 6, -1.1, 0.5 };
static const igrf_t fs_dsvh4[]  = { 0, -0.1, 6.5, 3.6, -5 };
static const igrf_t fs_dsvh5[]  = { 0, 0, 2.5, -0.6, 3, 0.3 };
static const igrf_t fs_dsvh6[]  = { 0, 0, -1.6, -1.3, 0.8, 0, 1 };
static const igrf_t fs_dsvh7[]  = { 0, 0.6, 0.6, -0.8, -0.2, -1.1, 0.1, 0.3 };
static const igrf_t fs_dsvh8[]  = { 0, -0.2, 0.6, -0.2, 0.5, -0.3, -0.4, 0.5, 0 };
static const igrf_t fs_dsvh9[]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvh10[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvh11[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvh12[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const igrf_t fs_dsvh13[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static igrf_t fs_adplm[14][14];  // Associated Legendre Polynomials
static igrf_t fs_addplm[14][14]; // Derivatives of Associated Legendre Polynomials
static igrf_t fs_adsnm[14][14];  // Schmidt Quasi_normalization


static igrf_t igrf_gnm(uint16_t fp_u16n, uint16_t fp_u16m);
static igrf_t igrf_hnm(uint16_t fp_u16n, uint16_t fp_u16m);
static igrf_t igrf_sv_g(uint16_t fp_u16n, uint16_t fp_u16m);
static igrf_t igrf_sv_h(uint16_t fp_u16n, uint16_t fp_u16m);
static igrf_t legendre_fact(uint32_t fp_u32n);
static igrf_t legendre_fact2(uint32_t fp_u32n);
static void legendre_polynomials(igrf_t fp_dtheta, uint16_t fp_u16n, igrf_t fp_dplm[14][14], igrf_t fp_ddplm[14][14]);

/**
* @brief getter function for IGRF-13 gnm gauss coefficients.
* @param[input]      uint16_t fp_u16n
*                    uint16_t fp_u16m
* @param[output]     none
* @return            igrf_t gnm gauss coefficient
* @note              none
*/
static igrf_t igrf_gnm(uint16_t fp_u16n, uint16_t fp_u16m)
{
    igrf_t val = 0;
    switch (fp_u16n)
    {
        case 1:
            val = fs_dg1[fp_u16m];
            break;
        case 2:
            val = fs_dg2[fp_u16m];
            break;
        case 3:
            val = fs_dg3[fp_u16m];
            break;
        case 4:
            val = fs_dg4[fp_u16m];
            break;
        case 5:
            val = fs_dg5[fp_u16m];
            break;
        case 6:
            val = fs_dg6[fp_u16m];
            break;
        case 7:
            val = fs_dg7[fp_u16m];
            break;
        case 8:
            val = fs_dg8[fp_u16m];
            break;
        case 9:
            val = fs_dg9[fp_u16m];
            break;
        case 10:
            val = fs_dg10[fp_u16m];
            break;
        case 11:
            val = fs_dg11[fp_u16m];
            break;
        case 12:
            val = fs_dg12[fp_u16m];
            break;
        case 13:
            val = fs_dg13[fp_u16m];
            break;
        default:
        	break;
    }

    return val;
}

/**
* @brief getter function for IGRF-13 hnm gauss coefficients.
* @param[input]      uint16_t fp_u16n
*                    uint16_t fp_u16m
* @param[output]     none
* @return            igrf_t hnm gauss coefficient
* @note              none
*/
static igrf_t igrf_hnm(uint16_t fp_u16n, uint16_t fp_u16m)
{
    igrf_t val = 0;
    switch (fp_u16n)
    {
        case 1:
            val = fs_dh1[fp_u16m];
            break;
        case 2:
            val = fs_dh2[fp_u16m];
            break;
        case 3:
            val = fs_dh3[fp_u16m];
            break;
        case 4:
            val = fs_dh4[fp_u16m];
            break;
        case 5:
            val = fs_dh5[fp_u16m];
            break;
        case 6:
            val = fs_dh6[fp_u16m];
            break;
        case 7:
            val = fs_dh7[fp_u16m];
            break;
        case 8:
            val = fs_dh8[fp_u16m];
            break;
        case 9:
            val = fs_dh9[fp_u16m];
            break;
        case 10:
            val = fs_dh10[fp_u16m];
            break;
        case 11:
            val = fs_dh11[fp_u16m];
            break;
        case 12:
            val = fs_dh12[fp_u16m];
            break;
        case 13:
            val = fs_dh13[fp_u16m];
            break;
        default:
            break;
    }
    return val;
}

/**
* @brief getter function for IGRF-13 gnm Secular Variation coefficients.
* @param[input]      uint16_t fp_u16n
*                    uint16_t fp_u16m
* @param[output]     none
* @return            igrf_t gnm Secular Variation coefficients
* @note              none
*/
static igrf_t igrf_sv_g(uint16_t fp_u16n, uint16_t fp_u16m)
{
    igrf_t val = 0;
    switch (fp_u16n)
    {
        case 1:
            val = fs_dsvg1[fp_u16m];
            break;
        case 2:
            val = fs_dsvg2[fp_u16m];
            break;
        case 3:
            val = fs_dsvg3[fp_u16m];
            break;
        case 4:
            val = fs_dsvg4[fp_u16m];
            break;
        case 5:
            val = fs_dsvg5[fp_u16m];
            break;
        case 6:
            val = fs_dsvg6[fp_u16m];
            break;
        case 7:
            val = fs_dsvg7[fp_u16m];
            break;
        case 8:
            val = fs_dsvg8[fp_u16m];
            break;
        case 9:
            val = fs_dsvg9[fp_u16m];
            break;
        case 10:
            val = fs_dsvg10[fp_u16m];
            break;
        case 11:
            val = fs_dsvg11[fp_u16m];
            break;
        case 12:
            val = fs_dsvg12[fp_u16m];
            break;
        case 13:
            val = fs_dsvg13[fp_u16m];
            break;
        default:
            break;
    }
    return val;
}

/**
* @brief getter function for IGRF-13 hnm Secular Variation coefficients.
* @param[input]      uint16_t fp_u16n
*                    uint16_t fp_u16m
* @param[output]     none
* @return            igrf_t hnm Secular Variation coefficients
* @note              none
*/

static igrf_t igrf_sv_h(uint16_t fp_u16n, uint16_t fp_u16m)
{
    igrf_t val = 0;
    switch (fp_u16n)
    {
        case 1:
            val = fs_dsvh1[fp_u16m];
            break;
        case 2:
            val = fs_dsvh2[fp_u16m];
            break;
        case 3:
            val = fs_dsvh3[fp_u16m];
            break;
        case 4:
            val = fs_dsvh4[fp_u16m];
            break;
        case 5:
            val = fs_dsvh5[fp_u16m];
            break;
        case 6:
            val = fs_dsvh6[fp_u16m];
            break;
        case 7:
            val = fs_dsvh7[fp_u16m];
            break;
        case 8:
            val = fs_dsvh8[fp_u16m];
            break;
        case 9:
            val = fs_dsvh9[fp_u16m];
            break;
        case 10:
            val = fs_dsvh10[fp_u16m];
            break;
        case 11:
            val = fs_dsvh11[fp_u16m];
            break;
        case 12:
            val = fs_dsvh12[fp_u16m];
            break;
        case 13:
            val = fs_dsvh13[fp_u16m];
            break;
        default:
            break;
    }
    return val;
}

/**
* @brief Function to calculate the factorial of a number
* @param[input]      uint32_t fp_u32N
* @param[output]     none
* @return            double factorial of a number
* @note              none
*/
static igrf_t legendre_fact(uint32_t fp_u32n)
{
	igrf_t res = 1;
    if (fp_u32n == 0)
    {
        res = 1;
    }
    else if (fp_u32n > 0)
    {
        for (uint32_t i = fp_u32n; i >= 1; i--)
        {
            res *= i;
        }
    }
    return res;
}

/**
* @brief Function to calculate odd factorial of a number
* @param[input]      uint32_t fp_u32N
* @param[output]     none
* @return            double odd factorials
* @note              none
*/
static igrf_t legendre_fact2(uint32_t fp_u32n)
{
    igrf_t res = 1;
    if (fp_u32n == 0)
    {
        res = 1;
    }
    else if (fp_u32n > 0)
    {
        for (uint32_t i = 1; i <= fp_u32n; i += 2)
        {
            res *= i;
        }
    }
    return res;
}

/**
* @brief  Associated legendre polynomials and its derivatives (w.r.t to theta)
* @param[input]      double fp_dtheta
*                    uint16_t fp_u16n
*                    double fp_dplm[14][14]
*                    double fp_ddplm[14][14]
* @param[output]     none
* @return            void
* @note              Function calculates and stores the polynomial in the
*                    variables fs_adPlm[14][14] and fs_sdDPlm
*/
static void legendre_polynomials(igrf_t fp_dtheta, uint16_t fp_u16n, igrf_t fp_dplm[14][14], igrf_t fp_ddplm[14][14])
{
    igrf_t x = fp_dtheta;
    // Clearing the Arrays.
    for (uint16_t i = 1; i <= 13; i++)
    {
        for (uint16_t j = 0; j <= 13; j++)
        {
            fp_dplm[i][j]  = 0;
            fp_ddplm[i][j] = 0;
        }
    }
    igrf_t sinx = sin(x);
    igrf_t cosx = cos(x);

    // Calculating Legendre Polynomials
    fp_dplm[0][0]  = 1;
    fp_ddplm[0][0] = 0;
    igrf_t knm     = 0;
    for (uint16_t n = 1; n <= fp_u16n; n++)
    {
        for (uint16_t m = 0; m <= n; m++)
        {
            if (n == m)
            {
                fp_dplm[n][n] = sinx * fp_dplm[n - 1][n - 1];
            }
            else
            {
                if (n > 1)
                {
                    knm = (igrf_t)(pow(n - 1, 2) - pow(m, 2)) / ((igrf_t)(2 * n - 1) * (2 * n - 3));
                }
                else if (n == 1)
                {
                    knm = 0;
                }
                if (n <= 1)
                {
                    fp_dplm[n][m] = (cosx * fp_dplm[n - 1][m]);
                }
                else
                {
                    fp_dplm[n][m] = (cosx * fp_dplm[n - 1][m]) - (knm * fp_dplm[n - 2][m]);
                }
            }
        }
    }

    // Calculating the Partial Derivatives.
    for (uint16_t n = 1; n <= fp_u16n; n++)
    {
        for (uint16_t m = 0; m <= n; m++)
        {
            if (n == m)
            {
                fp_ddplm[n][n] = sinx * fp_ddplm[n - 1][n - 1] + cosx * fp_dplm[n - 1][n - 1];
            }
            else
            {
                if (n > 1)
                {
                    knm = (igrf_t)(pow(n - 1, 2) - pow(m, 2)) / ((igrf_t)(2 * n - 1) * (2 * n - 3));
                }
                else if (n == 1)
                {
                    knm = 0;
                }
                if (n <= 1)
                {
                    fp_ddplm[n][m] = (cosx * fp_ddplm[n - 1][m]) - (sinx * fp_dplm[n - 1][m]);
                }
                else
                {
                    fp_ddplm[n][m] = (cosx * fp_ddplm[n - 1][m]) - (sinx * fp_dplm[n - 1][m]) - (knm * fp_ddplm[n - 2][m]);
                }
            }
        }
    }
}


void igrf_init(void)
{
    // Schmidt Normalizing the gauss coefficients instead of the Legendre Polynomials
    // since these coefficients remain the same irrespective of the Legendre Polynomials.
    // This saves a lot of time.
    igrf_t delta = 0;

    for (uint16_t n = 1; n <= 13; n++)
    {
        for (uint16_t m = 0; m <= n; m++)
        {
            if (m == 0)
            {
                delta = 1;
            }
            else
            {
                delta = 0;
            }
            fs_adsnm[n][m] = sqrt((2 - delta) * legendre_fact(n - m) / legendre_fact(n + m)) *
                           legendre_fact2((2 * n) - 1) / legendre_fact(n - m);
        }
    }
}


igrf_mag_field_t igrf_compute_magnetic_field(igrf_t fp_dradius, igrf_t fp_dtheta, igrf_t fp_dphi, uint16_t fp_u16n, igrf_t fp_djd)
{
    igrf_mag_field_t result = { 0.0, 0.0, 0.0 };

    if (((fp_dtheta <= 90) && (fp_dtheta >= -90)) && ((fp_dphi <= 180) && (fp_dphi >= -180)))
    {
        // The co-latitude is used for calculations, it is also converted to radians.
        igrf_t lat = fp_dtheta;
        lat        = lat * DEG_TO_RAD;
        fp_dtheta  = (90 - fp_dtheta) * DEG_TO_RAD;

        // longitude converted to radians
        fp_dphi  = fp_dphi * DEG_TO_RAD;
        igrf_t a = EARTH_RADIUS;

        // Initializing variables for iteration.
        igrf_t b_radius 	= 0;
        igrf_t b_theta 		= 0;
        igrf_t b_phi 		= 0;
        igrf_t inbr 		= 0;
        igrf_t inbt 		= 0;
        igrf_t inbp 		= 0;
        igrf_t cos_fp_dphi 	= 0;
        igrf_t sin_fp_dphi 	= 0;
        legendre_polynomials(fp_dtheta, fp_u16n, fs_adplm, fs_addplm);

        igrf_t days = fabs(fp_djd - START_JD_OF_MODEL);
        igrf_t gnm  = 0;
        igrf_t hnm  = 0;
        // Main set of Summations for Field strength calculations
        for (uint16_t n = 1; n <= fp_u16n; n++)
        {
            for (uint16_t m = 0; m <= n; m++)
            {
                cos_fp_dphi = cos(m * fp_dphi);
                sin_fp_dphi = sin(m * fp_dphi);
                gnm         = igrf_gnm(n, m) + (igrf_sv_g(n, m) * (days / DAYS_IN_YEAR));
                hnm         = igrf_hnm(n, m) + (igrf_sv_h(n, m) * (days / DAYS_IN_YEAR));
                inbr  += ((gnm * cos_fp_dphi + hnm * sin_fp_dphi) * fs_adplm[n][m] * fs_adsnm[n][m]);
                inbt  += ((gnm * cos_fp_dphi + hnm * sin_fp_dphi) * fs_addplm[n][m] * fs_adsnm[n][m]);
                inbp  += (m * (-gnm * sin_fp_dphi + hnm * cos_fp_dphi) * fs_adplm[n][m] * fs_adsnm[n][m]);
            }
            b_radius    = b_radius + pow((a / fp_dradius), n + 2) * (n + 1) * inbr;
            b_theta     = b_theta + pow((a / fp_dradius), n + 2) * inbt;
            b_phi       = b_phi + pow((a / fp_dradius), n + 2) * inbp;
            inbr = 0, inbt = 0, inbp = 0;
        }

        b_theta         = -b_theta;
        b_phi           = -b_phi / sin(fp_dtheta);
        result.b_radius = b_radius;
        result.b_theta  = b_theta;
        result.b_phi    = b_phi;
        fp_dphi         = fp_dphi * RAD_TO_DEG;

        // Field strength in Earth Fixed frame.
        result.b_fixed.x = -b_theta * 1 - b_radius * 0;
        result.b_fixed.y = b_phi;
        result.b_fixed.z = b_theta * 0 - b_radius * 1; // NED
    }

    return result;
}
