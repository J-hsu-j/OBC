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
 * @file  IGRF_pc_test.c
 * @brief Test the IGRF algorithm on the PC
 *
 * @}
 */
#include "../inc/igrf.h"

#if (IGRF_TEST_ON_PC == 1)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define char_line_length        106
#define order_of_calculation    13
#define number_of_lines_in_file 14401

#define deg_to_rad M_PI / 180
#define rad_to_deg 180 / M_PI
#define R_e        6378.137
#define f_par      0.00335281066
#define mu         3.986004418 * 100000 // km^3/s^2
#define f          1 / 298.257223563    // flattening of elipsoud
#define E_pow_2    f * (2 - f)          // eccentricity of ellipsoid e^2 = f(2-f)
#define a_elipsoid 6378137              // semim-major axis of ellipsoid in meters

int                         one_time = 0;
volatile igrf_mag_field_t   mag;
char                        fin[300];
volatile double             height = 0;
volatile double             norm   = 0;
double                      LLA[4];

FILE *sourceFile;
FILE *destinationFile;
char  read_buff_igrf[1024];

size_t bytes_written = 0;
size_t bytes_read    = 0;
size_t size_igrf_len = 0;

igrf_t wgs_84(double phi, double labmda, double h);

int main()
{
    igrf_init(); // important to init the igrf
    sourceFile      = fopen("IFT.txt", "r");
    destinationFile = fopen("dest.txt", "w");

    char *ptr;
    memset(read_buff_igrf, 0, sizeof(read_buff_igrf));
    memset(fin, 0, sizeof(fin));
    fseek(sourceFile, 0, SEEK_SET);
    fseek(destinationFile, 0, SEEK_SET);
    for (int j = 0; j < number_of_lines_in_file; j++)
    {
        size_t bytesRead = fread(&read_buff_igrf[0], char_line_length, 1, sourceFile);

        //        printf(read_buff_igrf);
        //        printf("\r\n");
        char *token = strtok(&read_buff_igrf[0], ",");
        for (int i = 0; i < 4; i++)
        {
            double value = atof(token); // Convert the token to a double.
                                        //            printf("%.20f\r\n", value);
            LLA[i] = value;
            token  = strtok(NULL, ",");
        }

        mag  = igrf_compute_magnetic_field(LLA[0], LLA[1], LLA[2], order_of_calculation, LLA[3]);
        norm = sqrt(mag.b_fixed.x * mag.b_fixed.x + mag.b_fixed.y * mag.b_fixed.y + mag.b_fixed.z * mag.b_fixed.z);
        //        printf("%.20f\r\n", mag.b_fixed.x);
        //        printf("%.20f\r\n", mag.b_fixed.y);
        //        printf("%.20f\r\n", mag.b_fixed.z);
        //        printf("%.20f\r\n", norm);
        sprintf(&fin[0], " %.20f, %.20f, %.20f, %.20f, %.20f, %.20f, %.20f\r",
                LLA[0],
                LLA[1],
                LLA[2],
                mag.b_fixed.x,
                mag.b_fixed.y,
                mag.b_fixed.z,
                norm);

        size_igrf_len = strlen(fin);

        size_t bytesWritten = fwrite(&fin[0], size_igrf_len, 1, destinationFile);
        memset(read_buff_igrf, 0, sizeof(read_buff_igrf));
        memset(fin, 0, sizeof(fin));
    }
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}
igrf_t wgs_84(double phi, double labmda, double h)
{
    igrf_t X = 0, Y = 0, Z = 0, temp = 0;
    igrf_t v       = a_elipsoid;
    igrf_t rad_phi = 0, rad_lambda = 0;
    igrf_t cos_rad_phi    = 0;
    igrf_t sin_rad_phi    = 0;
    igrf_t sin_rad_lambda = 0;
    igrf_t cos_rad_lambda = 0;

    rad_phi        = phi * 3.14 / 180;
    rad_lambda     = labmda * 3.14 / 180;
    cos_rad_phi    = cos(rad_phi);
    sin_rad_phi    = sin(rad_phi);
    sin_rad_lambda = sin(rad_lambda);
    cos_rad_lambda = cos(rad_lambda);

    temp = sqrt(1 - (E_pow_2 * sin_rad_phi * sin_rad_phi));
    v    = v / temp;
    X    = (v + h) * cos_rad_phi * cos_rad_lambda;
    Y    = (v + h) * cos_rad_phi * sin_rad_lambda;
    Z    = (v * (1 - E_pow_2) + h) * sin_rad_phi;

    return sqrt((X * X) + (Y * Y) + (Z * Z));
}
#endif /*IGRF_TEST_ON_PC*/
