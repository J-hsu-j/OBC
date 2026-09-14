# libIGRF

This is a library for calculating the magnetic field for use in AOCS algorithms.
Reference for the implementation is https://hanspeterschaub.info/Papers/UnderGradStudents/MagneticField.pdf

# USE
When using the library it is verry important to init it with the 'IGRF_init()' and after that you can use
 sBField_t IGRF_computeMagneticField(igrf_t fp_dRadius, igrf_t fp_dTheta, igrf_t fp_dPhi, uint16_t fp_u16N, igrf_t fp_dJD)
 to calculate the magnetic field 

# config 
`IGRF_TEST_ON_PC` define for using the pc test 
    // 0 when in OBC application
    // 1 when testing on PC     
`IGRF_USE_TYPE_FLOAT` define for using double or float 
    // 0 for double
    // 1 for float 


# PC test 
You can use the PC test file as you want, but the simplest ways is put a file with data in the form of 
Altitude                 , Latitude               , longitude               , JD   
6921.02919266406388487667,-38.71324303709152303554,  24.35002085609636068853,2459945.50000000000000000000\r\n
after that change the `number_of_lines_in_file` to how many lines you have in the this is in the IGRF_pc_test.c 
after that change the `IGRF_TEST_ON_PC` to 1 and then open a command prompt in the source folder andcompile with GCC 
``` gcc -o igrf IGRF_pc_test.c IGRF.c Legendre.c datetime.c ``` 
and after that just run the igrf.exe it will generate a file with the LLA coordinates and the 3 parts of the magnetic
field and the norm last.
