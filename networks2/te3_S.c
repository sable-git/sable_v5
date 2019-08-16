/*********************************************************
  test_newN3.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:33:26 2004
  by snns2c ( Bernward Kett 1995 )
*********************************************************/

#include <math.h>

#define Act_Logistic(sum, bias)  ( (sum+bias>-500.0) ? ( 1.0/(1.0 + exp(-sum-bias) ) ) : 0.0 )
#define Act_Identity(sum, bias)     ( sum )
#ifndef NULL
#define NULL (void *)0
#endif

typedef struct UT {
          float act;         /* Activation       */
          float Bias;        /* Bias of the Unit */
          int   NoOfSources; /* Number of predecessor units */
   struct UT   **sources; /* predecessor units */
          float *weights; /* weights from predecessor units */
        } UnitType, *pUnit;

  /* Forward Declaration for all unit types */
  static UnitType Units[240];
  /* Sources definition section */
  static pUnit Sources[] =  {
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189,
Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199,
Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219,
Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229,
Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,

Units + 111, Units + 180,
Units + 112, Units + 181,
Units + 113, Units + 182,
Units + 114, Units + 183,
Units + 115, Units + 184,
Units + 116, Units + 185,
Units + 117, Units + 186,
Units + 118, Units + 187,
Units + 119, Units + 188,
Units + 120, Units + 189,
Units + 121, Units + 190,
Units + 122, Units + 191,
Units + 123, Units + 192,
Units + 124, Units + 193,
Units + 125, Units + 194,
Units + 126, Units + 195,
Units + 127, Units + 196,
Units + 128, Units + 197,
Units + 129, Units + 198,
Units + 130, Units + 199,
Units + 131, Units + 200,
Units + 132, Units + 201,
Units + 133, Units + 202,
Units + 134, Units + 203,
Units + 135, Units + 204,
Units + 136, Units + 205,
Units + 137, Units + 206,
Units + 138, Units + 207,
Units + 139, Units + 208,
Units + 140, Units + 209,
Units + 141, Units + 210,
Units + 142, Units + 211,
Units + 143, Units + 212,
Units + 144, Units + 213,
Units + 145, Units + 214,
Units + 146, Units + 215,
Units + 147, Units + 216,
Units + 148, Units + 217,
Units + 149, Units + 218,
Units + 150, Units + 219,
Units + 151, Units + 220,
Units + 152, Units + 221,
Units + 153, Units + 222,
Units + 154, Units + 223,
Units + 155, Units + 224,
Units + 156, Units + 225,
Units + 157, Units + 226,
Units + 158, Units + 227,
Units + 159, Units + 228,
Units + 160, Units + 229,
Units + 161, Units + 230,
Units + 162, Units + 231,
Units + 163, Units + 232,
Units + 164, Units + 233,
Units + 165, Units + 234,
Units + 166, Units + 235,
Units + 167, Units + 236,
Units + 168, Units + 237,
Units + 169, Units + 238,
Units + 170, Units + 239,

  };

  /* Weigths definition section */
  static float Weights[] =  {
-1.358700, -1.553410, -1.114770, -0.880550, 0.713110, -0.344380, 0.742820, -1.650690, 2.104820, 0.687620,
0.161930, 0.278480, 2.147600, -0.187570, 0.639090, 1.134480, 0.383040, 1.304650, -0.656630, -0.915250,
-0.893390, -0.195210, 0.413880, -0.211850, 0.984280, 1.125140, 0.589990, -0.267360, 0.322510, -0.445120,
0.475860, 1.368910, 0.874810, -0.821610, -0.811020, -1.051440, -1.180200, -0.112200, -0.609290, -0.211920,
-0.874630, 0.336710, -0.049180, 0.404110, -0.076300, -0.609230, -0.583630, -1.001750, 0.631470, 0.595480,
-0.111080, -0.485290, -1.367870, -1.751760, 0.150110, -0.990310, -0.287420, -0.320540, 0.655520, -0.262070,
-2.420640, 0.340960, -0.046220, -0.508950, -0.778070, 2.182020, -0.155250, -0.014820, -0.696690, 1.854160,
0.259070, 0.816500, -0.168530, -0.044800, 0.334730, -0.511910, 0.662740, -0.592720, -0.934240, -1.908200,
-0.046040, 1.286750, 0.437030, 0.208010, -0.219900, -0.300610, 0.078180, -2.257100, 1.770850, 0.391470,
0.761950, -2.568360, -0.148540, 0.904870, -0.316700, -0.253040, -0.379100, 3.430180, -0.624570, -3.004630,
-1.064580, -0.471000, -2.639990, -7.733880, 9.720170, 6.864940, -27.241280, -6.309740, 8.227020, 1.805910,
0.676730, 0.582430, -0.086160, -0.592990, 0.096460, 0.324540, -0.600610, -0.394640, -0.305880, 0.160620,
1.167990, 0.025210, 0.403200, 0.603720, -0.519060, -0.631290, 0.842590, 1.985370, 0.018780, 0.674400,
0.980360, 0.868620, -1.088730, -0.350470, -0.551700, 0.082430, -0.129270, 0.359280, 0.042950, -0.350240,

0.383480, 0.576910, 2.645830, -0.074160, 6.932950, 0.647710, 0.548870, -1.610580, -0.047410, -0.903650,
-5.532920, -0.975540, -0.045750, -7.606580, 0.715420, -0.442450, -5.855050, 0.704260, 0.873650, 4.854250,
0.545970, 0.638220, -3.021990, 0.456740, 0.676320, 10.889240, 0.560930, 0.544240, 7.262980, -1.757930,
-0.228130, -30.637621, -1.529490, -0.346580, -2.534050, -0.931400, 0.135010, -17.164730, -0.825950, 0.396040,
-9.767880, -0.115120, -0.020210, 10.518700, -2.262030, 0.468040, -11.074140, -0.792700, -0.499780, -0.883700,
-0.466330, -0.377240, -5.996850, -2.468460, 0.258090, 4.329280, -1.465680, -0.013970, -0.357530, -0.296780,
0.660640, -13.953010, 0.210050, -0.910550, 2.249040, 0.378940, -0.834850, -27.111891, 0.832170, 0.654550,
10.637690, 0.214120, -0.114950, -1.423490, -0.250450, -1.045510, -7.006750, -0.554440, 1.212140, 3.338990,
0.523450, -0.079280, -5.284220, 0.538280, 0.394880, -1.938160, -0.802390, 0.468280, 1.584080, 0.830520,
-0.305470, 1.768460, 0.099490, -0.579380, 1.821590, -0.454520, -0.355850, -1.751530, 0.652380, 0.731510,
-1.512460, -0.009120, -0.388940, 0.507880, 0.340270, 2.147220, -0.254770, -0.660490, -0.476620, 1.954960,
2.091480, 2.976290, 0.044410, 1.913760, 0.094220, -0.327060, -2.119160, 2.838590, -0.042190, -0.293920,
0.155700, -0.015620, -0.487390, -0.415620, 0.622130, 0.522650, 1.397150, 3.615880, -0.155000, -0.812110,
0.892350, 0.592690, -0.029560, 0.390880, -0.111080, -0.056190, -0.833200, -2.431200, 0.126490, 1.092320,

-1.164000, 0.321630, -0.478400, 0.451350, 0.070550, 1.180060, 0.568670, 0.379030, 0.199330, 0.097290,
-0.194620, -0.110150, -0.260220, 0.602790, 0.105460, -0.253150, -0.503070, -0.645440, 1.161250, 0.390580,
-0.542040, -0.322520, 0.099810, 0.771940, 0.347530, 0.336780, 0.721960, 0.170180, -0.082830, 0.097570,
0.433300, 0.506380, -0.080350, -0.979690, -0.347320, 0.770620, 0.355010, -0.628690, -0.082360, 0.176810,
-0.416390, -0.917590, -0.016450, 0.106170, 0.690040, -0.661630, -0.451700, -0.507060, -0.164440, 0.095400,
-0.746170, 0.341810, 0.816650, -1.251250, -0.368780, 0.112980, 0.243160, -0.392820, -0.169490, -1.797330,
-1.048190, -0.747160, -0.383040, 0.516890, 1.024120, -1.845010, -1.347270, -0.632080, -0.410460, 1.533510,
0.312910, 0.281430, -0.530990, 0.118150, -0.766870, 0.077380, -0.267360, 0.917430, 4.774730, -0.196990,
0.618110, -0.698540, 0.366650, 0.321110, -0.339080, 0.702110, 0.411230, 1.568110, 0.073100, -0.284210,
-1.102920, -0.349690, -0.538040, -0.860290, 1.082440, 1.056320, -0.963590, -0.309860, -0.192010, -1.888110,
-0.184490, 0.732280, 0.066020, -0.007780, 0.635030, -3.416490, -0.819990, -0.648240, 1.817340, 1.099830,
-0.744700, 1.115900, 0.800430, 0.005950, -0.507280, -0.365650, 0.068990, -1.871950, 0.099940, 0.953220,
-0.549510, 0.048940, 0.065170, -0.939850, 0.289830, 0.757860, -1.745890, -0.859820, 0.579710, -0.173310,
-0.145060, -0.561520, 0.890810, -0.635700, -0.169630, 0.175500, 0.249690, 0.447440, 0.197170, -0.022070,

-0.548520, -1.782050, -0.443330, 0.334140, 0.866400, -0.499650, 0.590280, 0.182260, -0.098980, -1.384330,
-1.805680, -0.238140, -0.383770, 0.226690, -0.506080, 0.609380, 0.367520, 0.051540, -1.275060, 0.408790,
0.010680, 0.164470, -1.135400, 0.420100, 0.451260, 0.383750, -0.832290, 0.133700, 0.135470, 0.918230,
-1.023950, -0.696420, 0.323270, -0.007930, 1.102630, 0.612830, -0.779320, 0.940820, 0.806330, -0.950640,
1.148790, 0.213620, 0.255510, -0.988340, 0.244540, -0.284320, 0.152050, 0.573680, -0.572030, 0.244620,
1.216410, -1.959830, -0.373980, 0.118610, -1.118350, 0.440170, 1.026500, 1.221560, -0.156320, 0.400160,
-0.493870, 1.774260, 0.741040, 0.667040, 1.260780, 0.940700, -1.209050, 0.189380, 0.471160, -1.074190,
0.535090, 1.147100, -0.304710, 0.158600, 0.105630, 0.149800, 0.461090, -0.285770, 0.102190, 0.612320,
0.808810, -0.024990, 0.799340, 0.666900, 0.686890, -0.408530, 0.499490, -0.589760, 0.412690, 0.358920,
-0.034920, -1.292440, 0.059070, -0.023700, 2.783170, -0.704340, -0.007290, -1.204150, 0.153720, 0.779760,
-2.278780, -2.161050, 0.297680, 0.488970, 0.977940, -0.974910, -3.786100, 2.275420, -0.338290, 1.520340,
-0.805520, 1.468540, 0.609390, -0.305490, -1.469810, 0.112820, -0.517190, 0.556380, -0.416610, -0.319790,
-0.028700, 0.258650, -0.886450, -0.237300, 0.213710, 0.184250, -0.608530, -0.589350, 0.130300, 0.030860,
-0.981130, 0.030510, -0.394360, 0.226290, -0.662160, 0.113460, -0.607440, 0.327350, -0.124330, -1.179550,

0.712430, 0.540180, 0.275270, 0.857970, 0.311660, 0.174420, 0.233660, 0.621310, -1.859700, -0.492430,
-0.838260, 0.036570, -0.484000, 0.440830, -0.230010, 0.283670, -0.298210, -0.160730, 0.366080, -1.406670,
0.012250, -0.709730, 0.069720, 0.140260, -0.113770, -0.400150, -1.185940, 0.093530, -0.366800, 0.326970,
-0.750920, -0.019770, -0.119440, 0.574540, 0.317690, -1.500010, -0.074160, 1.453680, -0.544470, -0.900900,
-0.582380, 0.556360, 0.767260, 0.097990, -0.785490, -0.985020, 0.890030, -0.083850, -0.393330, 0.276210,
0.537480, 1.012550, -0.109660, -1.414920, 0.384870, 0.338510, -1.503220, 1.006780, -0.478070, -0.303660,
-1.458860, 0.042720, -0.121890, 1.001080, 0.133680, -1.136800, -0.211700, -0.412060, -0.393590, 0.195080,
0.020490, -0.085540, -0.230440, -0.082200, -0.442370, 0.025910, -1.547390, 0.496550, 0.424230, 0.557800,
0.251550, 0.286860, -0.377970, -0.026590, -0.587030, -0.979560, 0.359980, 0.179690, 0.735840, -0.125130,
-0.133080, -1.582110, -0.194770, 0.419060, -0.000750, 0.709680, -2.495510, 1.189380, -0.849590, 1.248270,
0.587420, -1.031060, -1.122640, 0.100340, -1.369970, -1.732510, 0.306090, 1.312960, -0.498490, 0.003220,
0.694450, 0.412490, -0.129920, -0.089890, -0.418320, 0.447210, -0.260010, -0.570700, -0.329130, 0.363040,
-0.645290, 0.000340, -0.373920, 0.216480, 0.157460, -0.842520, 1.400240, -0.609690, -0.357310, 0.114840,
0.156940, 0.360460, 0.739040, 0.236320, 0.591230, 0.200630, -0.023690, -0.127760, 0.331160, 1.004100,

0.271770, -0.157070, -1.413260, 0.879460, -0.592180, -0.195170, 0.788730, 1.198280, 0.939010, -0.373180,
-0.056280, 0.371970, -0.355130, -0.001570, 0.498080, -0.360850, 0.421560, -0.639900, 0.449660, 0.190650,
0.118260, -0.076280, 0.198690, -1.125980, -1.506440, 0.474310, -0.274490, -1.166910, 0.578930, -0.802640,
0.295470, -2.394980, -0.201740, 0.555440, 0.771880, -0.469060, 2.778660, 0.240970, -0.936420, 1.118440,
1.742920, 0.671870, 0.331090, 0.599580, -0.522820, -0.176150, 6.501140, -0.853850, 0.763530, -0.216840,
0.645850, 0.063930, -4.358330, -0.183960, -0.436730, 1.078530, 0.166800, -6.358640, -1.827910, 0.606370,
5.144460, 2.875330, 1.013180, -1.377830, -2.818400, 2.337480, 0.222930, -0.315130, 0.409280, 0.271510,
-0.022890, 0.781440, -0.274310, 1.907880, 0.210200, 0.877040, 0.124640, 0.473830, 0.275620, -1.130550,
-1.001710, -0.606030, -0.471370, -0.919960, -0.863420, 0.696110, 0.622990, 0.323760, -0.932610, 0.516250,
-0.130890, -0.427550, -1.261480, -0.856690, -0.960290, -0.215240, -0.455160, 0.053910, 0.709840, -0.485650,
0.765430, 0.416100, -1.311670, -3.557050, -0.271850, 0.237380, 1.253820, 3.495930, -1.137190, -3.446960,
-2.637390, -3.218570, 0.738950, 0.014600, -0.457210, 0.310010, -1.376150, 0.171370, 0.274850, -0.624490,
-0.044700, -0.503360, -0.095440, -0.592450, -0.483070, -0.514600, 1.590510, -0.247910, 0.859710, -0.338640,
0.833880, -0.628780, 1.214360, -0.740480, 0.932070, 1.245890, -0.303850, -0.974080, 0.559390, 0.618920,

0.600910, -2.166560, -0.695950, 0.351890, 0.446580, 0.357400, -0.004030, 0.479170, -0.777480, -3.150770,
-1.780540, -0.065640, -1.443790, -1.948870, -0.484440, -0.261550, 1.930380, 0.182880, -1.159390, -0.638530,
0.031620, 3.178240, -0.356100, -0.177690, -2.415090, -1.840380, -0.994230, -1.759700, -0.428880, 0.574850,
1.609680, -1.196520, -2.394830, -3.717680, 1.247700, -1.899890, 0.602390, 0.037600, -1.044950, 4.347770,
-0.652800, -1.097360, -3.317090, -0.933490, 1.282570, 0.268220, 5.655410, -1.131110, 1.041970, 1.890010,
-3.285830, 2.187190, -0.198300, 2.208160, 1.991260, 1.164580, -4.784190, 0.461620, 0.921070, 1.444530,
0.397300, -0.547130, 1.415360, 0.593080, 0.564900, -1.608940, -0.573180, 0.441410, -0.652340, 2.038510,
0.384960, 1.095300, 0.920300, -1.092590, -0.173430, 0.969230, -3.396770, -0.219570, 0.968770, 1.086070,
0.700770, 1.320160, -1.319760, -1.646780, 1.151210, -0.515820, -0.497760, -1.054170, 0.627100, 3.119550,
2.173870, -1.290700, 0.805530, -3.638310, 0.275350, -0.455620, 5.879650, 4.859140, -1.685070, 0.810630,
-0.715290, 3.912830, -1.261090, 0.961230, -4.328690, -12.078020, -12.252440, 0.203930, -0.200380, 0.762190,
-0.237900, -3.309030, 0.382310, 2.010660, 1.588540, -1.255220, -1.459340, -1.725420, -1.194610, 0.106960,
3.320010, -0.396450, -0.436870, 0.043050, -0.213620, -1.303360, -1.387430, -5.752400, -0.215250, -0.004910,
-0.133800, -0.043920, -0.451830, -0.400250, 0.987360, 1.851960, -1.086680, 4.702720, 0.686100, 2.098610,

1.046500, 1.168110, 0.908960, 0.131140, -0.311620, -0.245200, 2.553510, -0.301320, -2.332090, 0.184820,
0.734290, 0.737110, -2.924240, 0.659960, 1.163950, -0.224440, 0.965600, -0.570180, -0.026500, 0.761860,
1.159130, -0.970680, -0.280140, 0.340700, -2.630650, -0.263530, -0.761960, 0.412740, -0.106940, 0.515430,
-0.402720, 0.492300, -0.682410, -0.691160, -1.170210, 0.411010, 0.251260, -0.836660, 1.211750, 0.729630,
0.100220, 0.576250, -0.627230, 0.085550, -0.357330, -0.543140, -1.910050, 0.502820, -2.482450, -0.325750,
-0.663670, 1.647790, 1.809570, -1.126880, -1.189970, 0.282050, -1.501520, -2.112750, -0.790450, -0.534830,
1.787320, -0.472860, -0.327200, 0.055990, 2.843920, -0.277790, -0.111390, 0.225740, 0.050160, 2.036510,
-0.076800, 0.213330, -0.074260, 0.644300, -0.751170, -1.114780, 0.202330, -0.687620, 1.608960, 0.762570,
0.204390, -1.180890, 0.529250, -0.738940, -2.133330, -1.382340, 0.912520, 1.638410, 0.211830, 0.818460,
-0.042980, -0.038320, 0.311570, -1.116310, -0.494770, 0.487720, 0.088270, 0.187530, 0.688050, -1.043300,
-0.912860, -1.579750, 0.657560, -1.095040, 1.767730, -0.897190, -1.032850, 3.881480, 3.909750, -0.309100,
0.257600, 1.449120, 0.997390, -0.792730, -0.434180, 0.331850, -0.058300, -0.895130, 0.317390, 0.354350,
0.069090, -0.070990, 0.192000, 0.991460, -0.847670, -0.255130, -4.608850, 3.525640, -0.585220, -0.209220,
-0.387620, -0.710600, -0.663990, 0.670040, -1.027620, 0.006110, -0.121100, -1.031220, 0.516550, -0.312750,

-0.099500, -0.591410, 0.093420, -0.493400, 0.464630, -0.378640, 0.479390, 1.049180, 0.614170, -0.640490,
-0.441930, -1.112870, -0.131320, -4.832200, -0.027660, -0.459690, -0.827620, -0.378100, -0.403790, 1.464300,
-0.178980, -0.268180, -1.309410, 0.965050, 0.478730, -3.478250, -0.741100, 0.821900, 1.913910, -0.169850,
-0.867470, 0.565270, -0.425530, 0.099730, -1.180100, -2.560110, 0.354460, 0.678340, 0.358260, -0.731260,
1.661530, 0.638990, 0.977080, -0.794000, -2.184780, 3.237370, 1.042530, -0.851930, 0.362670, 2.070220,
-2.019450, -1.507170, -1.477900, 0.992000, 0.845330, 4.373410, -1.045910, -1.527590, 0.162030, -0.303930,
-1.151490, -2.024880, 1.568190, -0.886580, -3.300570, 0.086230, -0.637090, 3.364850, 0.752620, 1.717710,
-0.433040, 0.837580, -2.132770, -2.180690, 0.900930, 0.352770, 2.553310, 0.455960, 0.862380, -0.842190,
-0.304710, 0.923670, 0.071520, 1.529690, -0.548810, 8.209860, -0.344090, 0.532540, -8.533820, -0.663000,
-0.612810, -0.727130, 0.425720, 0.744940, 5.532700, 0.195140, 0.345640, 0.700280, 0.673150, -0.047880,
-2.069280, 1.431330, 0.994500, 4.426670, 1.277550, -3.836340, -4.065900, -5.007530, -0.365450, 2.802840,
-0.587410, -0.735680, 0.509130, 0.235740, -0.308110, -0.238450, -0.652870, -0.934150, -1.073970, -0.398670,
0.202510, 0.245760, 1.047130, 0.315740, -0.687590, 0.168090, -2.959970, 0.488200, 0.215090, -0.359720,
0.314310, -0.633390, 1.131140, 0.443310, -0.643190, -0.311780, 1.069430, 1.855400, -0.560250, 1.805860,

-0.296380, 0.270780, 0.442600, 0.601320, 1.631270, 0.503020, -1.990900, -0.499420, 0.003320, 0.769730,
0.641990, -0.235250, -0.125130, 0.733960, -0.212350, 0.037420, -0.404860, -0.968550, 1.741060, 0.168840,
-0.280200, 0.834720, 0.841430, 0.112010, 2.045800, 0.466400, 0.257360, -0.060580, 0.440490, 0.791450,
-3.667780, -0.017400, 0.395550, 7.016970, 1.195690, -0.455380, 3.050870, -1.398650, -0.771270, 0.418410,
-1.291770, -0.425900, -0.153460, 0.532830, -1.660250, 4.404220, -1.159850, -1.529760, -0.619260, -2.326910,
-0.220770, -0.374570, -2.167590, 0.237820, 0.689080, -0.909710, -0.829190, -0.954800, -0.542480, 0.149990,
0.177940, 1.107910, 0.193140, 1.268740, 3.451370, -0.093750, -0.732550, 0.400900, -0.839450, -0.015720,
0.388420, 0.366120, 1.124330, 2.771400, -1.131240, 0.529890, 6.831840, 0.284580, -0.270250, -2.316890,
0.882070, 0.106100, 0.385690, 0.596660, 0.187230, 4.884010, 0.549250, 0.490960, 0.083700, 0.321600,
0.622730, -4.774890, 0.690980, 1.789940, 4.255430, -0.215000, 0.574410, 3.965320, 1.100770, 0.280630,
1.488210, -1.032350, -1.401660, 1.250500, 0.786230, -4.300690, 0.259590, 0.522670, 1.532110, -0.797620,
-2.191890, -1.529350, -0.631810, 0.496910, 0.765020, 0.294130, -1.399380, -0.558520, 0.153480, -0.390510,
0.417950, 0.574470, 0.083390, -0.270330, 0.257230, -0.387790, -1.434910, -6.951720, -0.708750, 0.786270,
0.302050, -0.457020, -0.794650, 0.776160, -0.424130, 0.044850, 0.460060, -1.539840, 0.642370, 0.046790,

-0.177930, -0.534110, 0.921940, -1.900950, 1.355950, -0.105880, -0.627070, -2.566260, 0.240790, -1.097800,
0.048040, 0.137770, 0.032770, 0.912960, -1.104400, -0.578570, -0.339740, -0.531150, -1.223980, 1.476720,
-1.380440, 0.891430, -2.583740, -0.637190, -0.177380, 0.708140, -0.002160, 2.333220, 0.494740, -0.260190,
-0.146850, 0.655910, 1.924620, -1.176950, 0.597540, 2.214530, -0.668250, 1.337840, 0.176920, -0.706500,
-0.102530, 0.961760, 0.166730, 0.506920, -1.907550, 0.326070, -0.463460, -0.090390, 0.629120, 1.035450,
3.580980, 1.388170, -1.096460, 2.295820, -0.186430, 1.860390, -0.583600, -2.371640, -0.091470, 1.436520,
1.147890, -1.107400, -2.969210, -0.264540, -0.197680, -0.737340, 2.246640, -0.185680, 0.796270, -0.218440,
-0.153660, 0.294070, 0.527320, -0.278080, 3.576000, -0.061340, -0.842570, 0.303200, -2.843210, -0.170970,
0.728830, 1.624980, 2.598260, -3.792290, -0.682780, 0.019830, 1.273170, -0.882460, 0.740750, -0.747180,
0.404100, -3.027400, 1.346140, -1.859790, -1.695490, -0.947330, 0.279440, 1.473420, -1.398420, -3.419140,
2.676220, -3.288320, -8.947400, -0.125700, 26.537331, -12.374280, 47.453220, -13.888100, 3.853760, -1.585350,
1.435280, -4.626440, 0.826950, -0.943060, -0.104560, -1.251460, 0.288390, -0.606860, -0.387880, -0.261830,
1.323280, 0.807830, -0.482520, 0.766980, -1.509030, -0.168190, -13.392850, 0.397810, -0.120940, 0.252930,
0.367460, 0.695820, -1.911870, 0.110890, 0.115290, -0.917380, -0.039290, 0.716780, 0.299000, -0.592200,

-1.251160, -1.299280, -0.816120, -0.093550, -0.933320, 0.764500, 0.367670, -1.070180, -0.150510, 0.616330,
1.114060, 0.257080, -0.497260, -0.211870, -0.336400, 1.992620, -0.796040, 0.824860, 0.188250, -0.022720,
-1.006380, 0.235700, 0.103270, 0.858970, 3.376780, 0.457730, 1.057250, 1.045060, 0.114920, 0.865920,
-1.376120, 0.584550, 0.111690, 1.282810, -0.296990, -2.200210, 1.608860, 1.005330, -0.762070, -6.305030,
0.434380, -0.349980, 5.078120, 0.401970, 0.340600, 5.103630, 2.969400, 0.284360, -0.406000, -0.205630,
-0.827300, 1.212770, 0.444110, -0.918660, 2.224480, -1.747450, 0.502420, 2.939240, 0.843780, -0.360900,
1.965330, 1.551520, 0.309040, 1.511340, -3.490580, 0.606320, -3.347860, 0.469870, 0.784630, 3.013320,
0.977350, 0.992850, -0.667620, -0.644840, -0.530270, -1.113170, 0.086580, -0.469200, -0.117630, 0.614260,
-1.510500, -1.060530, -2.098180, -0.727530, -0.035020, 0.149890, -0.548680, 0.033430, 0.257870, -0.716530,
0.355930, -0.645670, 0.721590, 0.268370, 3.050940, 0.178770, 1.564000, -2.442470, 0.730880, -1.985450,
0.239180, 0.756640, 3.006040, -0.189540, -1.465900, -5.073770, -0.608850, -1.575000, 4.789870, 7.649010,
-0.977870, -1.377600, -2.826490, 1.071810, -3.741170, 0.371920, -0.481160, 0.043310, -0.235530, -0.727420,
-0.508040, -0.168460, 0.356520, -0.633730, 0.629030, 0.632950, 0.029720, -13.080920, 0.335910, -0.733750,
-0.036250, 1.028970, 1.041200, -0.745820, 0.537780, -0.527780, -0.548510, 0.566110, -0.383710, 0.713990,

-1.076980, -1.810960, 0.143430, 0.621450, -0.511830, 0.068920, 0.211860, 4.351960, -0.433440, 0.688430,
-1.174540, -0.903710, 0.352900, -0.760280, 0.898970, -2.645640, 0.797400, -0.038030, 0.201420, -0.585980,
-0.421340, 0.876790, 0.749520, -0.795620, -0.406860, -0.442530, 1.251050, 0.192560, 1.056740, 0.435280,
-1.411800, 0.178510, 0.686310, -1.512550, -1.354360, 0.995480, 0.996370, -0.080940, 1.089970, -0.917090,
-0.914440, 1.146890, 0.198080, 2.792910, 1.632160, 1.728510, 3.318130, 3.088800, 0.123410, -0.147590,
1.155730, 0.074500, -0.946380, -0.246380, 1.150070, 1.131520, 0.579040, -0.055790, 3.370000, -0.069350,
-0.697120, -0.104440, 1.662400, -0.238050, 0.215140, 0.149000, 0.198350, 0.479200, 0.734180, 1.054660,
1.420770, 0.729270, -0.711770, -1.356480, -1.507060, -0.374680, -1.625790, -0.828130, -0.061430, 1.560830,
-0.265160, -0.143980, -5.085960, -1.365690, -0.210450, -0.352000, 0.344780, 0.691700, -4.381870, -1.034840,
0.049400, 2.386630, -0.591670, -0.016370, 0.951760, 1.257180, -1.700320, 0.656520, -0.624970, 0.956340,
0.566680, -1.138360, -3.354750, -1.888300, -0.911700, -0.057360, 1.262540, -3.853950, 0.325160, -1.771000,
-0.881200, 1.708820, -0.249920, 0.451220, -0.059150, -1.028010, 0.689280, 0.400300, -0.455010, -0.712000,
-2.019450, 0.719500, 0.756760, 0.576570, 0.016670, -0.122770, -3.733330, -0.679510, 1.096750, 0.647190,
0.751790, -0.299180, 0.181920, 0.801110, -0.513580, -0.058550, -0.564730, 0.002750, -1.652310, -1.490690,

418.140747, 418.336060, 417.623230, 418.492828, 417.305450, 417.349060, 418.773163, 418.852173, 418.561523, 417.964600,
417.624390, 418.323303, 417.672119, 418.501495, 417.620972, 418.205902, 417.038086, 417.086395, 418.989899, 417.710968,
417.189850, 418.682343, 418.162292, 417.914276, 417.864441, 417.077087, 417.080414, 417.954132, 418.857178, 418.566376,
418.419739, 418.429413, 418.702759, 418.749420, 417.763794, 417.975403, 417.710632, 418.891785, 417.618042, 418.745117,
417.603790, 418.049927, 418.542023, 417.445007, 418.614349, 417.481781, 417.022797, 418.421204, 418.461609, 417.807556,
418.662567, 418.700531, 145.196777, 418.529358, 418.158478, 145.747635, 417.452667, 417.561401, 144.933502, 418.316040,
418.498291, 145.602844, 418.935974, 418.089325, 144.424133, 417.371613, 418.361359, 144.613846, 418.975739, 418.689972,
145.902420, 417.922119, 417.495422, 145.039734, 418.321075, 418.481476, 144.051743, 418.401794, 417.887939, 418.818512,
417.110931, 417.809967, 144.530090, 418.357666, 417.694672, 417.029266, 417.566772, 417.444183, 417.289459, 418.201508,
418.910583, 418.028046, 417.625397, 418.277313, 418.720947, 418.746063, 418.625671, 418.981079, 418.549042, 417.707672,
417.291687, 417.452972, 418.070587, 417.738251, 417.977570, 418.194275, 417.023987, 417.038269, 417.361511, 417.427582,
417.679596, 418.447052, 417.503265, 417.905945, 417.997833, 418.881287, 418.220673, 418.690704, 418.941803, 417.492920,
418.630707, 417.632507, 417.219879, 418.980896, 417.096619, 417.044281, 417.835144, 418.928009, 417.459778, 417.215637,
417.236298, 417.510071, 417.754303, 418.462860, 418.314972, 417.287323, 417.500824, 418.910004, 417.948059, 418.693695,

1.194340, -0.348370, -0.919540, 0.897250, 1.303960, 0.458250, -1.080270, 0.496600, -0.293350, 0.295670,
-0.272670, -0.120120, 0.703990, -0.060780, -0.576750, -0.488420, 0.552660, 0.963930, -1.669270, 0.935590,
-0.198010, 1.063460, 0.739140, 0.814300, 1.502820, -1.390540, -0.565230, -0.346790, 0.098920, 0.797410,
0.281620, 0.420410, -0.243250, 0.112710, -0.868390, 1.456060, 1.492570, 0.622770, 0.111720, -4.021250,
0.288300, -0.094740, 0.107570, -0.750900, -0.494600, 1.794850, -0.241240, -0.933370, -3.794310, 0.503490,
0.592730, 1.718940, -0.869670, -0.355400, 2.560670, -0.032470, 0.432520, 6.737160, -1.057650, -0.897030,
-1.896400, -0.577770, -1.099570, 7.702450, 0.020320, -0.305950, 0.332580, -1.071540, -1.069810, -0.173620,
-0.898640, -0.382560, 12.982510, -0.263910, -0.206800, -1.730010, 0.663390, 0.077090, 3.634530, -0.994340,
0.004130, -0.262050, -0.548530, 0.489240, -2.481960, 0.713380, -0.300640, 1.500460, -0.877610, 0.529190,
0.516530, -0.672230, -0.490210, -0.154330, -0.957310, 0.333100, -2.433740, -0.531970, -0.166400, -0.839070,
0.861990, -0.929760, -0.225430, 0.098330, 3.979290, 2.015110, 1.149100, -3.568710, -4.464610, -4.141190,
0.582810, -2.158450, 0.500490, 0.055670, -0.997360, -1.029420, 0.187350, -1.521640, 0.741410, 0.744280,
1.166090, 0.126710, -0.515790, -0.288740, 0.082980, 0.452780, 4.437790, 0.770820, 0.447840, -0.349380,
-0.280270, -0.533870, 0.533100, -0.124190, 0.038770, 0.381260, 0.812880, 0.858830, -0.623300, 1.477710,

1.259870, 0.222890, 0.381220, 0.220070, -0.061050, -0.118830, 1.087010, -0.063760, 0.864300, 0.115560,
0.187220, -0.146870, -0.615320, -1.024890, -0.734340, 1.181650, -0.493160, -0.151670, -2.070350, 0.050490,
-0.761300, -1.834140, -0.953100, -0.066220, 0.218800, 0.380690, 0.703880, -0.105140, 0.871110, 0.854970,
0.478260, 0.281670, 0.639800, 0.142520, -0.954370, 1.873370, 1.089030, 1.706240, -0.336430, 1.156310,
-0.801870, 1.232830, 0.730670, 1.559250, 0.255330, 0.316940, -0.421440, -0.023470, 0.734050, 0.590650,
-0.685960, -1.143810, 2.260160, 0.199570, 1.720170, -1.422740, -1.190440, -0.640670, -0.672690, 0.569280,
-0.143560, 1.026890, 0.481460, 1.240610, -1.257690, 1.313830, 0.286760, -0.051070, 0.665600, 0.445470,
-1.282660, -0.085470, 0.525220, -1.196760, -0.153890, -0.408980, 0.617650, -0.115570, -0.514560, -0.727570,
1.161690, -0.224940, -0.395170, 1.826500, -0.731370, 0.303070, 0.510900, -0.210670, 0.395160, 0.655570,
0.696790, -0.243400, 1.023010, -0.734150, 2.682190, 0.587150, 0.678820, 0.761170, 0.476180, -2.319180,
0.358150, 1.980850, -1.960040, 1.728660, 2.709150, 1.172380, 0.790050, 3.493540, 4.467220, -0.676690,
-1.435890, 1.605130, -1.507780, -1.200280, 0.467370, -1.425790, 0.481970, 2.132450, -0.839680, 0.105300,
0.621820, 0.420950, -0.158010, -0.667030, -0.735430, -0.663380, 1.251970, -0.411250, -0.113150, 0.385860,
-0.252470, 0.029990, -0.446570, -0.000300, -1.092880, 0.227110, -0.701150, 0.145860, -0.499010, -0.552240,

-0.380940, -1.830460, -0.275760, -0.182810, -0.113730, 1.077810, -0.523650, 0.500470, 0.071180, -0.808990,
0.223280, -0.742170, 0.471430, 1.044490, 1.027720, 0.352850, -0.880370, 0.364430, 0.522470, 0.414250,
-0.509160, 0.504620, -0.362160, 1.534130, 0.174980, 1.237250, 0.617860, 0.531120, 0.062200, -0.508200,
0.017820, -0.886660, 0.173210, -0.200510, 2.088060, -0.086530, -2.867050, 2.198870, -0.251270, -0.293360,
-4.274140, -0.030050, -1.041950, -0.922160, -0.863960, -1.031750, -0.359970, -0.514080, -0.078380, -0.887910,
0.502800, -0.350540, -0.928790, 0.679440, -0.158650, 0.895290, 0.999550, -0.356870, -1.301920, 0.486690,
0.929700, -0.014290, -0.140770, -1.031610, 0.024580, 0.400070, -0.656490, -3.351520, -0.232100, 0.609020,
0.976470, -1.005570, -0.444990, -5.066990, 0.576840, -0.535740, -0.908670, -0.779390, 0.420630, -5.374270,
-0.097690, 0.809300, -1.002490, -0.609060, -0.484350, 1.467820, -1.266100, -0.931590, -1.040870, -0.638450,
0.314430, 0.297280, -0.656150, 0.012670, 2.744260, 1.208670, 0.470110, -1.508920, -0.553800, 1.119240,
1.321060, 0.810590, -0.092940, -1.772330, -6.798490, 0.603930, 1.494860, 4.548590, 2.167650, -0.983800,
-0.387940, 0.153610, 1.116800, -0.039980, 0.373200, -0.569420, -0.142950, 1.426360, 0.193930, -0.172550,
0.439630, -0.007150, -0.406290, -0.554490, 0.212330, -0.389210, -1.463380, -2.133730, -0.015650, -0.847180,
-0.299770, -0.020040, -0.559680, 0.238530, 0.262820, -0.350510, -0.617870, 1.620720, 0.156570, -0.384090,

1.828400, -0.128380, 2.798080, 1.076890, 2.994680, -0.530680, 0.246130, 4.387550, -0.741090, 1.465760,
0.060110, 0.579440, -0.202520, -0.731830, 0.298910, -1.009360, -5.473680, 0.760370, 1.220990, -1.513820,
0.960180, 2.880260, 4.591000, 0.876890, -5.142110, -2.109690, -3.769130, -0.735390, 1.032210, 3.021740,
1.100390, 0.551980, -0.396790, 1.286610, 0.729430, 1.210220, 0.152300, 1.825100, -0.812270, 2.138730,
0.926250, 0.006460, 1.276510, -0.247870, 2.460230, 0.788620, -0.827640, 3.164520, 3.062380, -2.392630,
1.185440, -0.998630, 2.324300, -5.699710, -5.618430, -0.071470, 2.134180, 1.012160, 1.815090, -9.879320,
1.309350, -1.595800, 1.486670, -0.143680, 0.389020, -15.069470, 0.186830, 0.108730, -10.618980, -0.529220,
-1.305440, 6.292390, 1.019690, -0.568240, -24.901409, 0.019620, -0.388810, -6.638090, 0.257100, -0.823680,
-3.911870, -1.594540, 0.091860, -11.327770, -1.219620, 0.203430, 1.732940, 0.317960, -1.892890, -2.573450,
0.628450, -0.253480, -6.266840, -0.223150, -5.198400, -0.645070, -0.301460, 0.323850, -5.859540, 2.367780,
-3.032140, 0.525910, -3.351950, -2.178410, -3.360140, 5.235720, -8.206410, -16.225620, -3.584270, 2.353210,
-1.894270, -2.754650, 1.242210, 1.155870, 0.808030, 3.642650, -0.831190, -1.032720, 1.576460, -0.561430,
-0.309600, 0.030490, -0.571770, 0.520340, 0.130450, 1.452210, -4.884280, -4.701810, -0.674270, -1.010370,
2.347970, -0.340830, -0.546970, -1.147480, 0.336680, 0.878000, -0.357910, 1.383820, -0.610860, 1.841780,

-18.231670, -5.198510, -2.448520, 1.426350, 0.155000, 2.167630, -0.494920, -2.360690, 0.798290, -4.893970,
0.048150, 0.197720, 0.241670, -7.321620, 0.867290, 6.627860, 0.018620, -1.527770, 24.933941, -4.507820,
-0.486060, -12.383960, -1.841780, -2.054070, 19.087950, 2.500070, -0.466030, 0.769520, 17.933840, -0.255060,
-9.084060, 3.205940, 0.328970, 0.901050, 1.105470, 2.918570, 0.576000, 5.850450, 2.628730, -3.439290,
0.647740, 1.825460, 13.719120, 1.078080, 9.116370, 3.522230, 2.021670, 1.219320, 2.821630, -0.669750,
-1.697570, 6.654700, 0.267080, 10.356990, -2.377150, -1.107530, 4.080020, 9.397250, 0.075190, -4.157570,
-6.514800, 0.511560, 6.979760, 12.952390, 3.754690, 0.797670, 4.497030, 1.767850, 1.261120, -4.270610,
4.661500, -0.180230, 2.352460, 0.540140, -4.079980, 2.219580, -1.984110, 0.089320, 7.610860, 0.452040,
-0.728230, -5.484400, 0.108020, 1.016200, -3.887820, -0.012790, 0.571170, -5.890690, -2.183040, -1.051600,
3.182620, 1.232200, -0.356610, 2.001090, -0.872450, 1.695130, 2.554140, 5.587630, -0.141040, -8.822640,
-2.013210, -2.237440, -2.582070, 4.547530, -1.582880, -2.835220, 5.802220, -7.293930, -9.462910, 1.302380,
1.664330, -16.766661, -1.241350, -0.455690, -2.581210, -2.818080, 0.456690, -0.233870, 0.216410, 0.288230,
-1.752660, 1.379620, -1.121260, -0.567710, -1.766450, -1.158660, 14.769120, -5.762440, 2.239470, 0.577720,
0.580220, -0.955190, 0.594300, -4.530920, 0.444190, 2.004680, 0.142600, -0.270750, 0.801980, -5.119640,

2.011790, 0.186960, -0.304100, 0.219010, -0.972570, 0.451500, 3.559800, 2.552690, 0.521880, -3.067490,
-1.852760, 0.344970, -2.022010, 0.721760, 0.235460, 1.008640, -0.564950, 1.348050, 1.105620, 0.626170,
-0.466580, -0.036100, -0.572410, 0.479330, -0.714900, -1.043440, 0.869470, 0.518900, 0.911420, 0.654350,
-0.529690, -0.764370, -1.551730, 0.729320, -0.006940, 0.094240, 2.636030, 3.838830, 0.312920, 0.058970,
-0.272610, 0.203320, -1.324410, -0.658010, 5.206330, -0.299890, -0.644770, -0.750600, -1.051220, -0.387440,
2.982410, -2.805770, -0.554300, -3.614010, 0.965390, -1.506680, 6.035840, 5.365650, -1.343220, 1.056510,
-2.043220, -1.912020, 1.542940, -7.175400, -1.053950, 0.146280, -1.130550, -1.535830, 0.093470, -1.423660,
0.029700, -0.136880, -0.199880, -0.041590, -2.042730, 0.279390, 0.442620, 0.325540, -0.160660, -0.050260,
0.863210, 0.092840, -0.411560, 1.127470, 1.683200, -0.103800, 0.478260, -0.397540, -2.054360, 0.025440,
-0.696950, -1.375230, 0.375100, 0.773070, 2.656310, -0.671900, 0.403470, 0.461710, -1.021460, -1.900140,
-1.722030, -1.259370, 0.821770, 2.873200, 1.702050, 7.033150, -3.653490, 11.257640, -2.527820, -1.648210,
-0.787680, -0.766700, 0.064610, 1.273460, 3.165490, -2.577130, 1.453980, 0.926860, 0.414310, 0.767640,
1.470280, 0.071150, 0.486980, 0.448390, -0.333190, -2.044820, 4.095650, -3.631620, 0.611280, -0.210500,
0.372700, -0.506900, 0.698500, -1.310010, 0.780710, 0.110030, 0.024280, -0.681500, -0.532030, -0.704180,

-0.722520, -0.414120, 0.346150, 1.119890, 2.618700, 0.257310, -0.953940, 0.097220, 0.483450, 0.388160,
0.009130, 0.107000, 0.622260, 1.539990, -0.984720, 0.910120, -1.419640, 0.432400, -0.361850, -0.417500,
0.683090, -0.262200, -0.332340, -1.001430, -0.499130, -0.958270, 0.734790, -0.235000, -2.848150, -0.084210,
-0.349270, 2.126460, 0.703110, -0.132870, -1.711240, 0.908690, -0.011440, 0.944710, 0.915120, 1.694390,
-0.512540, 0.526290, 0.914260, 1.906480, 0.457830, 0.128340, 3.831910, -0.000240, 2.583200, 0.158870,
0.423180, -1.957380, 1.310400, 0.863980, -0.391290, 0.107700, -0.002220, -1.010650, -0.356930, -0.258670,
-0.285440, 0.074890, 0.832230, -0.057620, -1.585360, 0.865760, -1.016670, -1.359680, -1.662440, -1.174520,
-0.399800, -1.223260, 0.883060, -2.995190, -0.207920, 1.103690, 0.546800, 0.492270, -0.503970, 0.091690,
-1.728200, 0.325020, 2.518400, -0.532800, -1.044360, 0.072780, 2.533020, -0.828550, 1.993530, -0.323860,
0.320670, -0.544650, 0.290830, -0.493190, 0.379110, -0.688440, 0.486330, -1.930290, -0.335390, -0.769360,
1.110940, 0.654200, -0.883740, 0.208950, -20.931170, 11.746970, 1.902280, 21.551359, 6.953240, -4.133540,
-1.439620, 1.506900, -1.391180, -1.880310, 0.524190, -0.946010, 0.018390, 1.963490, 0.783750, 0.203640,
0.013110, -0.603780, -0.918520, 0.128690, 0.211260, -0.419290, 2.391760, -2.503110, -0.383920, 0.421680,
0.459250, 0.567860, 1.155100, 0.310000, -0.451990, 0.484550, -0.420440, 0.456240, 0.108510, -0.493590,

4.160510, -1.701380, -1.158660, 0.178270, 1.136370, 0.620500, -1.751620, 0.051770, 0.062640, 2.328380,
-0.617110, -0.444520, -0.402980, 1.158750, 0.360120, -1.289140, -0.052150, -0.644290, -0.668170, 0.933940,
-0.547110, -1.309210, -0.826930, 0.676360, 0.449250, -1.361650, -0.635590, -0.496970, 1.248910, -0.502660,
-3.688360, -0.744400, -0.340300, 5.397770, -1.909490, 0.150030, 0.717960, 0.130030, 1.243070, -0.045640,
-1.237990, 2.435780, 1.453320, 0.817630, 0.643550, 1.694400, 0.142800, -0.728020, -0.468990, -3.472330,
-0.366480, -0.244100, -0.654640, -1.325120, 0.422250, -0.271090, 0.183090, -0.968410, 1.153790, 0.682770,
-0.299290, 1.444650, 0.104620, 0.169000, 1.364800, -0.373800, 0.488110, 0.723010, 0.836580, -3.205230,
-3.503900, 1.013940, -0.352350, 0.354860, 0.814940, -1.706510, -1.353680, -0.684860, -0.219960, -0.103470,
-0.511100, -0.419180, -0.371110, -0.872400, 1.365700, 0.119360, -0.314290, -0.600880, -1.223150, -0.412570,
0.759980, 1.888820, -1.188120, 2.898020, -0.784130, -0.189910, 0.418370, 0.130710, 0.002190, 3.620620,
-3.052570, -1.195460, 3.216360, -3.557810, 0.525010, -2.344100, -5.899870, -0.659790, -0.268550, -0.047270,
0.556080, -2.053100, 0.724080, 3.068400, -0.233300, -0.468950, 0.792610, 2.290750, 0.322660, -0.623080,
-0.264880, -0.314840, -0.440340, 0.030830, 0.407410, -0.238480, -1.874570, 2.370700, 1.131140, -0.822440,
0.293100, 0.503540, 0.402920, 0.374660, -0.348540, -0.619040, -0.900920, 0.153500, 2.851240, 1.296250,

-1.338930, -1.094720, -0.262490, -0.955660, -0.257540, -1.187810, -0.549770, 0.170660, -0.814290, -1.194010,
-1.174750, -0.957480, -0.528170, 0.328630, 0.694030, -0.119560, -0.048700, 0.880440, 0.204440, -0.938480,
0.012620, 0.826130, -2.297410, -0.363720, -0.755470, -0.593180, 0.633130, 2.595180, 0.625180, -0.449910,
0.726470, 1.688050, 0.109610, -0.088220, -0.383000, -0.040690, -0.759520, 3.511770, 0.513720, -0.592740,
-0.431770, 0.111870, 0.492590, 0.486700, 0.508070, 2.254650, 2.962970, 0.508720, -0.867140, -0.505010,
0.040550, 0.034500, -0.755860, 3.289450, -1.721630, 0.252470, -0.013630, -1.094150, 1.439750, -0.126500,
0.985460, -3.557340, -0.745440, -0.219460, -0.154960, -0.713220, -0.791400, 0.781000, -0.688690, 0.433810,
-1.818020, 0.169250, -0.941190, -0.523170, 1.129830, -0.796420, 0.131090, 1.153430, 0.381940, -1.780510,
0.508070, 0.303090, -2.731150, -0.499730, -0.057120, 0.230030, -0.153190, 1.045030, 0.198170, 0.940130,
-0.738640, 0.944600, -0.437990, 0.778000, 3.410400, 0.602410, -0.537590, -0.658040, 1.810950, -0.458300,
1.002130, -2.177320, -1.475910, -2.211840, 0.965270, 6.845870, 2.477670, -3.247100, 10.231690, 4.917980,
0.761990, 4.393180, -1.023440, -1.116560, -1.227800, 0.348870, -0.172140, -2.117760, -0.203480, 0.660700,
-0.068170, -0.288410, 0.156760, 0.430030, -0.433180, 0.070410, 0.485920, 2.002480, 0.218820, -0.137350,
0.066050, 0.458530, -0.503000, 1.071430, 0.708780, -0.209070, -0.556830, -1.166010, -0.090500, -0.326580,

-1.249020, -3.009150, -3.927610, -0.530800, -6.487600, 0.755820, 0.769140, 1.116500, -1.822960, 0.865840,
-2.305220, 0.536720, -0.013520, 22.483089, -1.529240, -1.176210, 7.400100, -0.057960, -0.475960, 20.767481,
0.319780, -0.909500, -9.660840, 0.557870, 1.398640, -3.065300, -0.907030, -2.122420, 0.107030, 0.822250,
-0.406280, 13.325240, -0.618270, -1.651390, -0.691580, 0.789490, 0.362600, -2.829170, 0.055440, -0.975020,
-2.497760, -1.018520, 3.067240, 10.349940, 0.270600, -1.429300, -15.896130, 0.551150, -0.096200, 9.680090,
-0.266820, -1.231300, -5.381160, -0.532700, 0.942220, 9.877820, -0.599080, 1.914960, -3.302640, 0.309600,
0.169280, -5.974000, -0.285960, 1.122450, 6.847300, -0.742480, -5.702800, 3.689670, -0.156790, 0.661430,
0.393470, 0.855460, 2.108590, -0.081120, 3.921940, 3.408880, 0.516830, 0.911690, -0.518920, -0.258900,
-0.348700, 9.442910, -3.296730, 0.513800, -0.837260, 0.050660, -0.103190, -5.629220, 1.015930, -0.146550,
0.123570, 5.690810, -0.562530, 1.595590, -1.367740, 0.907670, 2.710030, -1.233460, 0.315800, -4.078260,
3.985600, 1.666950, -15.520740, -16.971239, 15.573340, -9.978770, 28.884300, -4.023240, 0.674450, -2.751310,
3.333330, 0.617110, 0.418550, -1.698520, -3.112440, -0.349400, 0.765640, -6.442070, -0.565140, -0.922880,
0.129580, 0.831700, -0.190070, 0.098830, 0.027620, 0.629320, -6.396570, 29.250271, 0.579300, 0.084320,
0.739050, 0.316090, -0.638980, 1.230520, -0.359880, 1.243120, 0.432410, 1.013490, 0.377930, -2.426110,

0.372530, -4.111400, -1.096960, 0.409610, 5.615070, 0.379830, 0.093230, 0.454770, 0.677080, -0.317660,
-3.598600, 1.355040, 0.703660, -0.126370, 0.758210, -0.430060, 0.555820, -0.265580, 0.885420, 0.175710,
0.780950, 0.679570, -0.534570, -0.218780, -0.310230, 3.200970, 1.577230, -0.827150, -0.730650, -1.476860,
-0.594260, -0.163580, 0.317930, -0.811270, -2.525700, -0.594010, 0.595320, 0.919720, -0.524660, -0.611600,
1.585390, 0.763060, -1.811060, 13.338620, -0.803870, -0.777720, -4.941490, 1.555500, 0.427090, -1.788820,
-1.004510, 0.519090, 12.873080, -0.527360, 0.584090, -7.085560, -0.854540, -1.454850, 15.383830, -0.107710,
-1.056040, -4.634300, -0.945710, 2.327360, 14.751070, -0.445880, -1.667570, 6.312350, -0.094350, 1.073210,
-6.626790, 0.167140, 1.138930, -3.404780, -0.312740, -1.321700, 0.455140, -0.329710, 0.771540, 1.720090,
0.930470, 2.050980, 1.481360, 0.211700, -0.133560, -0.940270, 1.040780, -0.212530, -0.467990, -0.474650,
-0.087540, 2.127730, 1.021040, 0.278680, 0.493820, -0.781570, -0.992680, -1.936600, 0.028960, 2.219600,
-0.861130, 3.267420, -0.240120, -1.178710, -4.890850, -1.001570, -2.226790, 2.852280, 0.028220, -0.018600,
-1.145940, -0.267710, 0.689740, -1.362180, -0.021570, -0.400330, 0.028520, 2.998400, 0.170550, -0.041960,
0.927330, -1.854900, -0.097230, -0.519460, 0.530840, -1.019700, -4.077850, 4.063770, -0.147140, 0.029090,
2.821010, -0.248190, 0.222430, -0.141080, 0.507560, 0.186230, 0.083580, 0.586790, 0.673290, -1.741820,

-1.283310, -1.150980, -0.644300, 0.119420, 0.029720, -0.457560, 0.305180, 0.862440, 0.811760, -0.912460,
-1.336480, 0.760760, -0.936650, -0.914100, -0.722420, -0.671610, -1.645040, -0.835550, 0.291490, -0.488760,
0.058880, -0.829140, 0.001610, 0.407860, 0.557140, -0.299670, 0.357870, -0.437310, 0.941400, -0.296870,
0.483350, 0.577830, 0.894170, 0.587110, -0.368280, -0.831380, -0.641930, 0.054320, -0.771480, 0.181470,
-0.876840, 0.806630, -0.376590, -1.339620, -1.192270, -0.603370, 0.570370, 0.552570, -0.018730, 0.012600,
0.338000, 0.395640, -0.156990, -0.674000, -2.867210, -0.260540, 0.682790, 0.766110, 0.745270, 0.599210,
0.585020, 0.390820, -0.148930, 0.344710, -0.665540, -1.491990, 0.556020, -0.953500, -0.921220, -0.419250,
0.593050, -0.904240, -0.542200, -0.112790, -0.586190, -0.447310, 0.061790, 0.078950, 0.748820, -0.557260,
-0.856290, 0.831990, 0.244030, -0.132370, -0.213230, -0.110730, 0.333990, -0.706500, 0.054890, 0.748980,
0.579760, -0.613060, -0.706300, -0.277930, -1.716640, 0.516970, 0.625730, 0.018890, 0.390400, 1.634690,
-0.162350, 1.277370, 0.178310, -0.886900, -0.727900, 1.131400, 2.863790, 0.431090, -1.213120, 1.392410,
-0.023860, -0.488740, -0.218410, 1.253040, 0.073890, 0.496310, 0.106610, 0.696270, -0.495360, 0.651520,
0.654440, -0.666600, 0.295810, -0.373200, 0.596230, 0.851520, -0.409900, 2.358800, 0.829140, -0.845570,
-0.100620, -0.884610, 0.270190, 0.911680, -0.049830, -0.772580, -0.427800, 0.539630, -0.024740, 0.395510,

0.082820, 0.732560, 1.210710, -0.724570, -0.897510, -0.276620, 0.007310, 2.584630, -0.441400, 0.111950,
-2.910230, -0.541270, 0.174990, 0.533690, 0.086770, -0.296750, 0.414670, 0.721290, -0.433450, -0.243980,
0.131340, 0.268040, 0.375380, -0.162470, -0.020400, -1.060220, -0.715970, -0.277820, 1.198150, -0.381830,
-0.559760, -0.975330, 0.097120, -2.305250, -0.644130, -1.052230, 0.570390, 0.195900, -0.190490, -0.475710,
-0.083620, -0.207030, -0.352650, 1.100900, -1.855750, 0.567300, 0.512660, 1.184000, -0.874550, -0.251350,
-0.132760, 0.633970, 6.077890, -0.294240, 0.817520, -0.687230, -0.145110, -0.666990, 1.771100, -1.351040,
-0.263020, 1.007110, -0.039380, -0.909240, -3.730670, -0.193230, -0.622070, 0.064610, -1.239430, 0.676800,
1.440490, 0.470900, 0.474080, -2.080360, -0.936920, -0.748890, 0.386090, -0.639750, 2.375020, 1.668870,
-0.030660, 0.085160, 1.022810, -0.029410, -1.606400, -0.035800, -0.771190, 1.101000, 0.921410, 0.796820,
1.077240, -0.280630, -0.178060, -1.179090, -1.317460, 0.589670, -0.899830, -0.424520, 0.247250, 2.425550,
3.299300, 5.465960, 2.466500, -5.159680, -4.667390, 0.150520, 0.972760, -1.919800, 1.165560, 0.337120,
-0.141010, -1.944290, 0.523930, 0.876980, 0.139930, 0.476460, 0.141790, 5.865880, 0.206620, -0.616570,
0.814120, -0.378280, 0.564750, 0.181600, 1.293110, 0.168060, -1.502050, 1.542040, 0.844610, -0.741760,
-0.003830, -0.685750, 0.863090, -0.062650, -0.583490, -1.719560, 0.103800, 0.716730, 0.652150, 0.741290,

0.168710, -0.174140, -0.745460, -0.477930, -1.435040, -0.170300, 2.163580, 0.777790, -0.357060, -0.970190,
0.943780, -0.802420, 1.671980, 0.191200, 0.313170, -0.547090, -1.027560, -0.590150, -0.309510, 1.241640,
0.414570, 1.421720, 0.825410, -1.248870, -0.824210, -0.189340, -0.049680, -3.184560, -0.360760, -0.267530,
1.305250, 1.424140, -0.001010, 0.810060, 0.612500, -0.216080, 1.004770, -1.091880, -1.751480, -2.192200,
0.210310, -0.231300, 3.106440, -0.647430, 0.562140, -2.426950, -1.430060, 5.209140, 4.104120, 1.293820,
-0.701040, 0.404750, 0.787510, -1.217790, -0.328650, 0.151210, 0.603460, 0.655480, 0.419360, -1.253160,
0.901040, 0.755110, -0.017710, 1.492530, -0.151440, -1.093850, -0.575630, 0.442070, -0.529210, -0.840010,
0.764910, 0.038910, -0.826710, 0.689370, -0.614080, 3.092770, 0.787830, -1.093970, -0.619740, 2.911550,
-0.302820, 0.661350, 0.216310, 0.403680, 0.540830, 0.388410, 0.697270, -1.792820, -0.453080, -0.417980,
-0.243450, -0.416410, 0.756780, 0.963890, 0.186790, 0.656810, 1.527460, 0.626380, 0.559730, 0.542920,
0.539440, 0.228640, -0.483020, 1.856550, 1.676990, 0.369530, -2.441680, -0.572220, 2.196560, 1.590500,
-1.041430, 0.092280, -1.006020, -0.106800, -0.949010, 0.849960, 0.428570, -0.423280, 0.730060, -0.143530,
0.464860, 0.205960, 0.272370, -1.364680, -0.676740, 0.352660, 2.560970, -1.678430, 0.574430, -0.183770,
-0.818300, 0.767020, 0.502190, -0.662940, 0.028810, -1.293910, -0.368180, -1.524590, -0.696110, 1.246360,

-6.269220, -4.508020, 1.209600, 0.258650, 0.967880, 0.480710, 0.427290, 4.668980, -1.170110, 0.782130,
-1.187780, -0.636850, -0.245840, 0.865670, -0.802840, 3.572950, -1.746120, 0.331890, -1.244520, -1.362670,
0.176290, -1.304890, -0.897200, 0.973670, -2.696440, -1.403980, 0.752490, 7.291410, -0.972930, -1.426470,
0.194410, 5.632840, -1.019820, -0.350240, -2.376920, 1.529880, 0.407160, -7.483380, 1.458480, 1.857200,
-0.428980, 1.463440, -1.423370, 9.314420, 5.805910, 0.963310, 0.554820, -2.443380, 1.114260, 1.232550,
-4.542480, -1.993960, -0.906810, 7.545040, -0.275150, 1.247600, -3.593650, -0.458730, 4.212940, 2.069460,
0.614020, -2.913960, 0.300410, 0.832050, 4.784950, -0.890770, -0.806540, 5.375930, -1.033990, -0.199500,
-5.386620, 5.485160, -0.401050, -2.442370, 1.103610, 0.549520, 4.604310, -1.180770, -0.744520, -0.706850,
1.164280, -0.654870, -4.207030, -0.549090, -0.697790, 0.310040, 4.243350, 0.523250, 3.057740, -0.777160,
-0.239760, -1.722610, 0.545750, 0.837580, -0.780170, 0.858070, 1.134880, -4.215790, 2.545090, -5.966230,
5.370580, -0.198100, -5.867960, 32.994911, -5.490920, -10.260350, -7.797210, -19.180700, 14.372700, 2.506860,
-0.458120, -1.817440, -2.461990, 2.720480, 10.172270, -0.222340, -0.004750, -3.049080, -2.617880, 0.308010,
0.455050, 1.329710, -0.973200, -0.582660, 0.624610, -0.894910, 5.835560, 14.372330, -0.257790, 1.028460,
1.253210, 0.072860, -0.642280, -0.465190, -0.544260, -1.597640, -0.399830, 0.053060, 0.653430, -0.526470,

-0.085260, -0.046540, -0.281410, -0.822230, 1.529480, 0.160270, 1.248480, -1.545250, -0.069410, 0.710190,
0.562260, 0.170110, 2.591080, -0.556920, -0.170310, -1.029030, -0.389400, -0.128530, 0.478520, 0.713170,
0.329510, 0.434440, 0.473770, 0.340120, 0.162690, 1.487020, 0.792090, 0.196090, 1.088260, 0.191450,
0.889610, -0.888380, -0.158230, -0.007170, 0.929830, -0.935920, -0.416960, 0.305190, 0.471380, 1.593460,
-4.554730, 0.555440, -0.416930, 1.650280, -0.300690, 0.283780, 0.903470, 0.478730, -0.505330, -1.190660,
0.520290, -2.094330, 4.692740, -0.424880, -0.035190, 3.854410, -0.777400, 0.008860, 2.893270, -0.829850,
-1.556040, -0.181140, -0.995960, 1.460300, 3.839410, -0.250190, -1.010760, 0.946850, -1.009010, -0.941000,
-2.750400, -0.578250, 0.872860, 2.587930, 0.192410, -0.427960, 2.043470, -0.559150, -1.795100, -1.303280,
-0.639800, 0.132540, 0.399610, 0.888260, 0.970290, -0.649090, 0.578010, -0.428050, -1.057870, -0.514480,
1.483670, -0.367460, 0.330000, -1.934050, 1.008430, -1.704310, -1.340410, 0.337130, 0.016450, 0.537760,
0.186250, 0.184370, 2.123340, 4.129200, -0.857140, -4.084770, -4.309220, 0.187820, 1.872940, 0.920130,
-0.682490, -1.324670, -0.322310, -0.525440, -0.525270, 0.890070, -0.421710, -1.294190, 0.258690, -0.336420,
-1.035250, 0.240710, 0.154320, 0.429490, -0.169580, -0.488850, -0.126490, -5.314600, 0.279060, -0.535990,
0.236290, 0.183120, -0.848590, 0.660090, 0.703590, 1.739490, -0.130980, -0.558400, 0.107290, 0.915400,

0.712930, 4.251470, -0.299550, -0.764240, 1.194100, -0.189270, 0.149430, 1.411040, 0.092040, 0.824780,
-0.496310, 1.211310, 0.379790, 0.716150, 0.368230, -1.696470, -0.957110, -0.337120, -0.601380, -0.666590,
0.332700, 0.521830, -1.735160, -0.668080, 0.265740, -0.629520, 0.573670, -0.816590, 0.033630, 0.516980,
-0.863730, 0.832350, 0.253670, 0.585260, -0.032530, 0.783710, 0.531730, -0.203270, -0.055140, 0.292550,
1.412870, -0.047910, 1.082180, 0.344710, 1.693810, 0.555090, -0.926440, 0.575190, 0.391350, -4.795470,
-0.123770, -0.835480, 0.677750, -0.211110, -0.143140, -0.282000, -0.009900, -3.104110, 0.882230, 0.399710,

0.373940, 1.697550, 0.361830, -0.277650, 0.658340, 4.040170, -0.737320, 0.402970, -0.716490, 0.454530,
-1.154640, 0.222560, 0.558330, -0.636040, 0.069260, -0.849960, 0.473850, -1.534160, -0.037180, 0.853090,
0.044610, -0.592580, 0.094960, -0.439320, 0.172630, -3.301370, -0.669710, -0.437500, 0.085670, 1.775720,
-0.226360, 1.089240, -0.886810, -0.941310, 0.726540, 1.077360, -0.078830, 2.207180, -0.885000, -0.240430,
-2.122980, -1.695420, -2.235890, 0.672790, 0.839020, -0.662050, -2.876160, 1.988720, 0.437450, -14.670630,
-0.758020, 0.772900, 1.093160, 0.760780, 1.751950, 0.368490, -5.507540, -5.455400, -0.938190, -0.375700,

2.348540, 0.996890, -1.066220, -1.148000, 1.043030, 0.414100, -0.014870, -3.479400, -0.585920, 0.542970,
0.989010, -0.297850, -0.827830, -0.838350, -0.293660, 0.415400, -3.398210, 5.797840, 0.724860, -0.342620,
0.951080, 0.845750, -1.080330, -0.266090, -0.308260, 1.285290, -0.790170, 0.182520, -0.858410, -0.410240,
0.822040, 1.286970, 0.926640, -0.746030, -0.861510, -1.057440, 0.114660, -0.534640, -0.082680, -0.309910,
3.252600, 1.668490, -1.108390, 0.214740, -0.702890, 0.784810, 1.450910, 0.597820, -0.368010, 10.664430,
-0.094060, 0.060140, 0.182140, -0.020000, 1.143050, -2.081940, -1.663660, 2.181940, 0.280590, -0.387760,

0.243690, -0.838380, 0.276280, -0.996730, -1.423800, -0.693560, -0.191500, -0.323820, -0.187980, 0.453690,
0.009700, 0.030300, -0.707400, -0.214580, 0.135950, -0.960770, -2.851450, -3.170360, -1.132770, -0.537510,
0.506590, 0.115460, 0.329550, -0.150590, -0.628670, -0.422510, 1.037040, 0.460770, 0.778040, -0.009520,
0.874840, -0.726990, 0.215150, -0.216000, -0.787510, -0.162280, -0.077580, 0.056990, -0.484850, 0.673580,
-0.597410, -0.588340, 3.004670, -0.204620, -0.151250, -0.296330, 0.475370, -0.334620, -0.616240, -0.226260,
0.290690, -0.367610, 0.080710, -0.475630, 0.723160, 0.794530, -3.214010, -3.658060, -0.082370, -0.581430,

0.081220, -0.513240, 0.162420, -0.038800, -0.245210, -1.344720, 0.153890, -0.550490, -0.181100, 0.211720,
0.563410, 0.338240, -0.140840, 0.644530, -0.555870, 0.848680, 0.550950, -0.112940, 0.076610, -0.558970,
0.124260, -0.417390, 0.357920, -0.634990, -0.918960, 0.123990, -0.715940, 0.836960, 0.514190, -0.307120,
-0.821460, -0.875090, -0.006290, -0.389130, -1.037490, 0.755910, 0.127650, 0.156840, -0.440760, -0.025210,
1.179900, 0.383750, -1.555690, 0.640580, -1.564840, 0.963230, 1.642050, -1.271440, 0.184010, -4.597520,
0.501130, -0.403820, 1.642840, -0.822180, 0.276240, -0.486900, -0.826920, 6.716320, 0.215450, -0.161750,

-0.579600, -27.427441, 0.431660, -0.927400, 0.576150, -0.612520, -0.740800, -3.437620, -0.193380, 0.443710,
-0.123810, -1.098790, 1.072670, -1.046900, -0.386270, 0.922240, 0.608840, -4.894910, -2.023420, -0.065100,
0.498150, 0.293040, 0.532740, -0.827100, 0.610430, 1.277180, -0.238120, 0.899620, 0.234790, -0.807720,
0.257000, 1.129530, -1.435990, 1.976380, -0.189370, -0.231600, 0.130630, 0.634580, -0.029250, 0.962620,
-0.707580, 1.183530, -6.176840, -0.818520, -1.395010, -0.028460, -7.399080, -2.373160, 0.369450, -21.666710,
-0.401960, 0.603180, 0.239580, -0.479430, 2.620960, 5.569620, 0.167170, -14.106880, 0.705850, 0.867120,

-0.163580, -0.401820, 0.529470, -0.241770, -1.517130, -0.759870, 0.409970, -0.147280, 0.246370, -0.761180,
0.374810, -0.803380, 0.487120, -0.464150, 0.799450, 0.935000, 0.291390, -4.831290, 0.200490, 0.332670,
0.060780, 1.154100, -0.539080, 0.145160, -0.728700, -0.376420, -1.189750, 0.071440, 0.713360, -0.097190,
-0.643740, -0.112760, 0.539080, -0.703330, 0.179040, 0.476630, -0.472960, 1.042040, 0.458820, -0.267750,
-1.606470, 0.129770, 1.075800, -0.746800, -0.534570, 0.654620, 0.276210, -0.519730, 0.344500, 5.672460,
0.132150, 0.918050, -0.607750, -0.239070, -0.275110, 0.208240, 1.044630, 10.756440, 0.372330, -0.950150,

-1.295730, -33.533360, 0.451840, -0.623570, 0.455490, 1.316890, 1.688130, 1.564630, 1.159380, -0.882830,
-0.637770, -0.933300, 0.000300, -0.751710, -2.032180, 0.634120, 0.069740, 2.616990, 0.987720, -0.224900,
0.200980, -1.529150, 0.124790, 0.448780, 0.932960, 0.389430, 0.884760, 1.227340, 0.033790, 0.801370,
-0.644730, -4.743360, -1.022500, -3.402480, 0.922270, -4.341110, -0.344500, 0.172750, 0.460920, 0.228920,
0.708610, 0.655250, 3.751420, -0.502110, -2.530800, 0.307910, 1.746040, -0.229530, 2.088270, -2.445260,
-0.495710, -0.080800, -0.322460, 0.501000, -2.471760, 0.747410, 10.055100, 27.712151, 0.246730, -0.872760,

-0.867580, -4.121000, 1.105540, 0.414110, -0.658480, -0.264020, -0.187570, 0.087430, -0.255090, -0.049610,
-0.166420, -0.944240, -0.409260, -0.883700, -0.338750, -0.582840, 0.195370, -0.531460, 0.535150, -0.638430,
-0.478790, 0.861830, 0.257440, -0.091040, 0.199230, -0.369140, -0.273830, -0.057320, 0.358980, 1.636890,
-0.120870, 0.157760, -0.786020, 0.295970, 1.425460, -1.052980, 0.765150, -0.148400, -0.046450, -0.390830,
1.509410, 0.937080, -3.087070, 0.186120, -2.949670, -0.074700, 1.226980, -0.703960, 0.820220, -2.178530,
0.058970, -1.473820, 0.599430, 0.243290, -0.731740, -1.330230, 1.927570, 9.335800, 0.792040, -0.088120,

0.316190, 33.041531, -0.059420, -0.797290, 0.447270, -0.427700, -0.099880, 0.901770, -0.168980, 0.562160,
0.143510, 0.654550, -0.807310, 0.783350, -0.337000, 0.360030, -0.649610, -0.647450, 0.331280, -0.274830,
0.509930, 0.276940, -0.748110, -0.519160, 0.956430, 0.589130, -0.716320, -0.318830, -0.336020, 0.045470,
-0.526660, 0.247120, 0.868410, 0.259670, -0.435480, -0.636460, 0.097980, -0.628620, 0.552350, -0.834730,
0.124360, -0.704610, -1.815410, 0.568290, -0.224480, 1.362270, 1.118470, -0.799050, -0.318440, -2.790570,
-0.110960, 0.855970, 0.372300, -0.025440, 0.084140, 0.143930, -0.038750, 5.160580, 0.147870, -0.499170,

-0.253160, 0.622130, -0.420290, 0.145530, -0.380940, 0.530130, -0.019710, -1.540630, 0.284220, -0.594140,
-0.679070, -0.243210, 0.621600, -0.059440, 0.195260, -0.141370, 2.384740, -1883.085083, 0.443680, 0.907230,
-0.331700, 0.053650, -0.404170, -0.355460, -1.371180, -1.012520, -0.193070, 0.141250, -0.559270, -0.676250,
-0.617540, 0.243220, -0.053590, 0.499490, -0.227850, 0.141880, -0.151420, 0.368920, -0.949260, 0.282010,
-0.194810, 0.307560, 1.016660, -0.468870, -0.192450, 0.054750, -0.259360, -0.477430, 0.192740, 0.575580,
0.092350, -0.827450, 0.900720, 0.149910, -0.276870, -0.177190, 0.668000, -1.083870, 0.883280, 0.274250,

1.311930, 0.066840, 0.865410, -1.370640, -3.657840, 3.720390, -0.361500, 0.084200, -0.907580, -0.578220,
0.162930, -0.699890, 0.546710, -0.632200, -1.205360, 0.359740, -5.541390, -1271.200317, -0.437210, 0.035400,
0.867430, 0.104760, 1.193980, 1.361780, -0.684020, 0.834250, 0.337020, -2.101700, -0.806370, -0.911810,
-0.765320, 0.999700, 0.203950, 2.244220, -0.707180, -1.095300, 0.904860, -0.044480, 0.671520, -0.775080,
0.039050, 0.474350, -6.025200, 0.887060, -2.468440, -0.835860, 0.444330, -0.658580, -0.380860, -0.367200,
-0.136250, 1.018150, 0.684970, -0.131240, 0.454790, 0.976570, -1.629760, 5.113050, -0.132570, 0.463740,

0.738660, 0.237730, -0.838180, -1.831020, 0.735620, -0.211180, 0.964470, 0.373360, -0.634340, 0.573750,
0.546740, -0.342010, -1.543130, 0.842520, -0.131630, -0.771510, -1.511060, 1.043780, -0.526070, -0.176110,
-0.115350, 0.935290, -0.085520, 0.497050, 0.393750, 0.547370, 0.005080, -0.091470, 0.120670, 0.280550,
-0.983820, -1.926770, -0.335370, 0.816930, -1.315330, -1.158980, 0.117110, -0.654100, -0.768930, -0.313160,
-0.413310, 0.139190, 0.305860, -0.796460, 0.642680, -0.116410, -0.851120, 0.376960, 0.619010, -0.266980,
0.029950, 1.177240, -0.065800, 0.071510, 0.198170, -1.754400, -0.719190, -10.777380, 0.637920, -0.254570,

-3.173910, -6.135010, 3.282240, 19.569559, -1.614540, 0.438980, -3.069950, -4.319480, 0.579030, -0.837760,
-0.303230, 1.387760, 11.913230, 0.472090, -1.257060, 1.052890, 21.119341, -3.992790, 0.480590, 0.605770,
0.426570, -0.120650, 1.944300, 1.158850, -0.477760, -2.405100, -1.089490, -1.929720, -2.015740, -2.812850,
-0.642580, -0.847890, 0.979950, 0.855260, -1.334080, -0.154670, 0.799960, 0.927710, -3.832170, 0.462230,
-0.190520, -3.540440, 0.796710, 4.159520, 1.557990, -0.194820, 3.375300, -0.164070, 0.981190, 0.431910,
0.243750, 2.679880, -4.650280, -1.451390, -0.214690, 4.834300, -0.169110, 3.443020, 0.061460, 2.928860,

1.717900, -0.388360, 0.079540, -2.468000, 1.185070, -5.555070, -0.510680, -0.605770, -2.717930, -0.932900,
0.668890, -0.538140, -0.036200, 0.791010, -0.374030, -1.184800, -0.352120, 1.422070, 0.479750, -0.767640,
1.322930, 0.298090, -1.350040, -0.380900, -0.561220, 1.359540, -0.441620, 0.061190, 1.241290, -0.839730,
0.643600, -2.499160, 0.775790, -0.624830, 0.452880, 1.540120, 0.144350, 0.031280, -0.726480, 0.343650,
-0.578970, -0.952780, -0.657130, -0.408060, 1.107320, 0.729850, -0.021710, 0.099380, -0.315760, 3.310840,
-0.050290, -0.697930, 0.688400, -0.499100, 0.676980, 0.816250, 0.983130, -10.445190, 0.061350, -1.435400,

0.070960, 7559.987305, 0.907510, -0.094510, -2.170470, -1.101280, -1.239640, -3.058500, -1.169400, 0.831250,
0.680220, 1.092070, -1.689180, 1.131160, 1.072720, 2.378020, 1.419040, -0.313370, -1.678970, 0.177440,
-0.296160, 2.796880, -1.722570, -1.726630, 0.060510, -1.674830, 0.879630, 2.315760, 0.893780, -0.734390,
0.261320, 0.013120, 0.451010, -0.408200, -0.364490, 0.507600, -1.027410, -0.629570, 1.235290, -0.814410,
-2.716760, 1.112130, 0.055690, -0.813660, -0.906600, 1.980390, 0.974370, -1.453630, -3.017750, 11.476940,
0.420400, 0.570080, -1.041550, -2.165120, 0.982450, -1.221100, 2.830960, 27.399349, 2.322110, 0.222360,

0.916600, 0.925550, -0.024530, -2.596100, -0.701570, -0.145360, 0.125090, -2.968950, -0.009470, 0.320750,
0.176810, -1.126050, 0.877870, -0.234140, -0.127180, -0.059000, -2.014750, 0.006690, 0.266280, 4.857850,
-1.341250, -0.188450, -0.416360, -1.709920, -1.020500, 1.938650, -1.601210, 0.324610, -0.499680, -1.594890,
0.438410, -0.367150, 1.497780, 0.183310, -0.264870, 1.015860, -0.034420, 0.035490, -0.058650, 0.110170,
1.535470, -1.227270, -0.200940, -0.441720, -0.254780, -1.067720, -0.454590, 0.667590, -0.185220, 0.901760,
0.239220, -0.253510, 1.117850, -0.289440, -0.375540, 1.254140, -6.905050, -92.694969, -0.215540, -2.688600,

1.617580, 3.584860, -2.213720, -1.300830, 0.242110, -0.193470, -0.140730, 2.076710, -0.572470, -0.379580,
0.524660, 1.541410, 0.854500, -0.169070, 1.476120, -0.161180, -3.296960, 6.457580, -0.528210, -0.523700,
0.581320, -0.468620, -0.713780, -0.040150, 0.704310, -0.296560, 0.306320, 1.181300, 2.216940, -1.719310,
0.131540, -1.269360, -0.607830, -0.660300, -0.466220, 0.061370, -0.693900, -0.981990, -0.163580, -0.142280,
-0.343500, 0.881800, 1.602890, -0.412490, 0.577370, -0.822600, -1.003740, 0.480310, 0.194820, 3.478740,
0.069310, 0.950480, -1.004390, 0.709360, -0.000960, -0.626210, -2.087510, 1.801190, -1.015780, -0.399360,

0.213740, 0.018630, -0.956520, -0.960290, 0.443370, 0.123020, 0.387410, -4.831230, -0.896850, -1.311080,
0.939360, -0.781330, -0.316290, 0.254540, 0.433700, 0.835820, 0.125570, -0.740120, -0.487170, -0.684570,
0.145740, -0.235690, 0.527970, -0.303320, 0.469820, -0.019250, 0.268170, 0.561120, -0.895000, -0.463320,
-0.579380, 1.755590, 0.710610, 0.035300, 0.796250, -0.750060, -0.126390, -0.142200, 1.019180, -0.017760,
1.816720, 1.733240, -0.908060, 0.605360, -0.062690, 0.273600, 1.318290, -0.629060, -0.663330, 1.078290,
0.299660, 0.132980, 0.654610, -0.098840, 0.623480, -3.504880, -1.406840, -15.761730, -0.616060, 0.098130,

-0.941750, -2.874750, 0.198860, -0.791390, 0.634660, -0.269280, 0.179530, -4.766550, -1.566080, -1.533020,
0.312630, 0.453790, 0.288840, -0.898890, 0.417630, -1.415200, -2.895800, 1.572250, 0.358520, 0.030330,
1.785280, -0.439590, -1.039790, 0.267080, -0.988230, 2.175770, -0.592360, -0.014940, -0.466980, -1.074150,
-0.018740, 0.261850, 0.066940, 0.186470, -0.022900, -0.255990, 0.220420, 0.463090, 0.199450, -0.726770,
0.346290, 0.501510, -0.206090, -0.362090, -0.744830, 0.233470, 1.019200, -0.681370, -0.479790, -2.124300,
-0.075320, -0.444300, 0.704590, 0.587270, 0.598120, -0.498230, -0.079460, -0.409670, 0.576080, 0.213910,

-4.065320, 7.929700, -0.906000, -4.191450, 1.606300, -0.099810, -0.650060, 9.321360, 1.152210, 0.322290,
-2.745150, 2.603690, -0.306070, 0.816230, -0.213640, -5.721930, -11.007840, -8.561690, 0.520800, -3.421880,
0.984350, 1.250390, -0.665570, 1.844390, -4.468930, -2.732700, -1.446450, 2.209240, 4.926640, 3.170310,
-0.755360, 1.052990, 1.175900, -5.268260, 0.367650, -0.249660, 0.202680, 0.170540, 1.647590, 0.022850,
0.042550, -1.783360, -1.252020, -0.183030, -1.016940, 0.096650, -3.169430, -0.965220, -0.135770, 11.735730,
12.451260, -5.333250, 3.395000, 0.397430, -1.495900, 2.161440, 2.107650, -0.214620, -0.380920, -4.644010,

0.544580, 1.433100, -0.549870, -0.634350, -0.675110, -0.467280, 0.165590, 1.327250, 0.375510, -0.754050,
-0.187680, 0.284280, 0.192490, -1.114190, 1.061050, -0.500760, -1.807360, 1.340560, 0.529010, 0.443610,
1.020880, 0.284640, -0.297820, 0.425170, 0.149580, -0.572410, 0.017620, 0.397780, -0.054270, -1.079320,
-0.687300, 0.760820, 0.639090, 0.276010, 0.380110, 0.409290, -1.037880, 0.036540, 0.493950, -0.814570,
-0.160030, 0.592700, 0.156990, -0.434530, -1.152370, 0.641980, 2.126720, -1.716870, 0.767190, 3.165730,
0.104790, -0.451840, 1.318220, -0.608420, -1.708460, -2.027930, 3.216030, 13.906610, -0.783400, -0.905670,

-0.831960, -0.316640, -0.489590, 1.053680, 0.969930, -0.151960, -0.034200, -0.608540, 0.859410, -0.470780,
0.101780, 0.031370, -1.115900, 0.370050, -1.267590, 0.057810, 2.545150, -1.988360, 0.596810, -0.734700,
-0.043160, -0.275540, 0.986130, -0.582420, -0.728200, -2.211120, 0.243300, -0.404810, 0.056780, 0.754970,
0.085340, 0.440270, 0.662350, -0.538090, 0.516140, 0.035370, 0.121600, -0.791320, 0.815650, -0.408370,
-0.039270, 0.296580, 0.896390, 0.056620, 0.043110, -0.303640, 0.440340, 0.248850, 0.266530, -5.069920,
0.283620, -0.427280, -0.049930, -0.037880, -0.536070, 0.649040, 3.857490, -2.233310, -0.559160, 0.444720,

-1.598210, 30.032351, 0.466480, 0.772700, -0.593090, -0.131610, -1.044500, 1.277650, 0.018500, 0.663820,
-0.490310, 0.731840, -0.833790, -0.469350, -0.533110, 1.592150, 1.268330, -2.048890, 0.134920, -0.942540,
-1.051220, -0.097340, -0.993210, 0.628990, -0.051180, -0.470050, 0.751470, 0.268100, -0.631080, 0.223120,
0.021320, -2.385450, 1.401740, -0.046720, 0.809260, -3.432620, 0.664780, -0.268390, -0.430650, -0.286230,
2.805030, -0.024040, -0.431240, -0.388450, -0.464450, -0.039670, 0.319620, 1.995160, -1.005630, 1.578120,
0.263440, 0.247910, -1.524940, 0.985690, -0.145440, -0.663380, -0.576410, -7.770630, -0.494910, 0.857030,

0.246030, -1.330120, 1.117000, -0.654650, 0.756710, -0.669750, -0.350350, -0.302150, -0.237030, 1.162070,
-1.109300, -0.349110, 0.182450, 0.255110, -1.175690, -0.371080, -12.250760, 3.140830, -1.103610, -0.774380,
-0.228900, -0.274970, -0.066570, 0.837120, -0.631890, 0.174860, 1.114480, 0.128410, -0.415720, 1.014790,
0.218640, -0.446790, -0.484680, 0.730700, 0.408430, -0.065060, -0.194260, 0.205830, 0.457730, 0.369760,
-2.464750, -0.584930, -0.371410, -0.088830, -0.740690, 0.190820, -1.139390, -0.740090, 0.673390, 2.383140,
-0.335380, 0.512900, -0.242700, 0.634390, -0.232650, 0.182370, 0.775700, -2.711710, -0.172110, -0.224880,

-0.267250, -125.728241, 1.098610, 0.777260, -0.089160, -0.863780, -0.855700, 0.376620, -0.352010, -0.436330,
-1.437350, 0.298840, 0.223340, -0.525880, -2.139220, 0.936390, -0.123390, -1.537260, 0.326740, -1.813090,
-1.179610, -0.256670, -0.739940, 0.368750, 0.286270, -0.307920, 1.042860, 0.034630, -0.848960, 1.257430,
0.383720, -0.105530, -0.216190, 0.728320, 0.544650, 0.399170, -0.310460, 0.149910, 0.811780, 0.072130,
0.319160, -0.262350, 0.639670, 0.377160, 0.909720, -0.664560, -0.944600, -0.486910, 0.492040, -2.246650,
0.069140, -0.264390, 0.194610, 0.035210, 0.690500, 0.696040, -0.415860, -3.159880, -0.565850, 1.425630,

0.069340, -113.002274, 1.412720, 0.945570, -2.859680, -0.530990, -10.923680, -0.918900, -0.252850, -1.475610,
-1.119210, -0.609410, -0.081290, 0.339930, -0.322870, -0.896050, 2.356710, 6.737040, -0.714440, 0.457390,
-0.609160, -1.005290, -0.701140, -1.046510, 0.336960, 0.046200, -0.231740, 0.640100, 0.036050, -1.164180,
-0.366540, 0.030160, 0.673650, 1.392690, 0.910170, 0.033000, 0.563110, 0.086020, 0.610920, -0.085810,
1.827290, 1.072510, 2.850370, -0.299770, 4.306140, 0.518600, -0.797030, -2.563580, -0.295770, -9.345690,
-0.246450, 0.032840, -0.391820, 0.122470, 0.887570, 0.825110, -0.788280, 4.105560, 0.098070, 0.919280,

-8.642870, -14380.291016, 1.726390, 0.728620, -2.772960, -0.241030, 4.640630, -5.991000, -0.353820, 0.108840,
2.930900, -1.108590, -4.202500, -0.638720, -0.347900, 0.860770, -5.526000, 5.046330, -5.423140, 1.143410,
-0.813670, -1.442960, 4.832610, -1.280560, 0.491270, -3.384530, -0.031720, 7.948120, -0.696750, 0.746520,
-1.065910, -0.623640, -1.769570, 1.724760, 0.077210, -0.620310, 0.034150, 0.639580, -0.062420, -0.257020,
-1.784330, -0.751140, -7.024860, -0.460790, -2.436640, -1.907230, 0.637390, 0.908990, 0.140010, -18.414721,
-0.320730, 0.749700, 0.371290, -0.938270, -4.928140, -1.407820, -0.868760, 0.007270, -0.646890, -0.340550,

0.491020, 314.011322, -6.109700, 0.520090, -1.907200, 9.246820, 1.335890, -0.168950, 2.764220, -0.686250,
-1.000770, 2.036640, 2.474810, 0.873610, 0.316070, -2.258660, -10.558250, -0.502560, 0.964490, 1.781110,
5.223750, -1.177830, 4.857220, -0.281510, -0.830990, 2.734700, 0.550760, -0.877400, -1.108810, -0.434940,
0.679810, -5.124330, -0.892020, 2.232720, -0.023640, 12.518570, -0.163730, 0.637440, -1.251720, -0.788270,
-0.824900, -5.626880, -6.664220, 0.581210, -3.055840, 0.283320, 2.813600, 2.243110, -0.220200, 21.807131,
-0.099420, -3.256330, 2.432330, -1.850810, -0.628370, -3.632180, -0.539330, 16.152639, 1.352040, -5.174580,

-1.322120, 2.704350, 0.574960, 0.422140, 1.189980, 0.765810, 0.623520, -0.562310, 0.068770, 0.783690,
-0.885150, 0.499920, -0.704630, -0.504560, 0.121070, 0.410650, -0.328400, -0.779680, 0.566960, -1.175810,
0.441930, -0.444950, -0.222140, 0.514610, 0.123180, -0.149070, -0.353040, -0.581180, -1.090720, 0.253120,
1.061720, 1.129560, 0.299450, 0.484100, -0.589170, -0.015350, 0.077340, -0.541430, -0.583940, -1.153220,
0.138060, -0.239410, -4.551420, 0.422980, -1.399620, -0.384120, -2.338420, -2.040350, 1.053850, 4.973330,
0.148590, -1.910510, 0.289220, -1.602270, 0.690270, -0.243880, -2.162660, -7.019190, 0.614430, 0.462820,

0.206530, -1.067900, 0.966780, 0.671650, -0.204860, -1.314130, -0.641570, -0.614190, -0.504630, 0.579500,
1.055230, -0.386970, 2.050370, -1.438170, 0.492620, 0.407190, -0.128940, 0.469860, -1.331270, -0.110330,
0.511750, -1.523420, -0.123910, 0.575850, -0.383670, -2.941190, -0.792450, -4.466910, 0.194840, -0.629310,

0.593070, 0.656480, -0.946300, 0.964770, 0.342960, 0.272580, -0.797580, -0.360670, -0.534250, -0.746130,
0.186100, 0.192540, -3.769890, 0.070930, -0.414940, -1.411480, -2.298810, -0.248850, 0.463710, 0.303740,
0.160700, -0.815760, -0.106050, -1.173340, 0.802570, 0.403250, -1.202090, -6.696090, -0.029760, 1.333190,

-0.368700, -0.436770, -0.228380, -0.954440, 0.117330, -0.541350, 0.666010, 0.601910, 0.623480, 0.186220,
-0.877200, 0.120490, -2.288950, 0.287320, -0.244400, 0.946310, 0.115440, -0.384830, 0.900210, -0.003450,
-0.458020, 1.207840, -0.097270, -0.211190, 0.254920, -0.275120, 1.591970, 6.657470, -0.563470, -0.959240,

-0.173420, -1.342150, 0.966480, 0.449580, -0.809220, -1.093660, 0.183960, -0.538170, -1.240690, -0.709570,
0.009820, -0.624890, 1.529770, -1.609810, 1.369730, 0.950590, -1.365870, 1.126610, -1.134310, -0.755810,
0.480890, -0.083520, -0.121530, 0.531930, 0.286070, -3.671760, -2.038940, -7.119120, 0.586620, -0.120200,

0.360810, 0.435720, -0.936910, 1.015110, -0.503040, 0.577950, -0.407160, 0.091550, -0.479530, 0.258850,
-0.459210, -0.250320, -4.089830, 0.077030, -0.800730, -1.012700, -2.938700, -1.566210, 0.297930, -0.148290,
0.144070, -0.579620, 0.256220, -0.793310, 1.008540, 0.997580, -1.985090, -9.312480, -0.814950, 0.787890,

0.360880, -0.268190, 0.241860, -0.890620, 1.005470, -0.750810, -0.259570, 0.383350, 0.936380, -1.000260,
0.097720, 0.468000, -1.554110, 0.066500, -1.161790, 0.720830, 1.231660, -1.250900, 0.490490, 0.786100,
-0.433970, 0.430570, -0.460160, -0.072360, -0.732360, -0.777510, 2.191820, 9.682180, 0.001730, -0.869330,

1.335240, -1.006460, 0.606720, 0.187500, -0.631420, -0.455160, -0.129800, -0.425990, -0.968300, -0.597270,
-1.642270, -0.654370, 2.103580, -0.649460, 1.692980, 0.008200, -1.522990, 0.973230, -0.343310, 5.077180,
0.444950, 0.888200, -1.615210, 0.399520, 0.239410, -4.598420, -1.443910, -5.870770, -0.173770, -0.054240,

0.897920, 0.403950, -0.496400, 0.787950, -0.207690, 0.375570, -0.686240, 0.285640, 0.245320, -0.510480,
-2.356500, -0.857170, -3.441480, 0.798740, -0.975850, -0.140910, -1.238240, -2.141050, 0.162830, -7.138870,
0.060540, 0.163760, -0.428960, -0.266640, 1.296790, 1.745050, 0.096160, -9.070650, -1.059480, 0.484120,

-1.199830, -0.232020, 0.072320, -0.464240, 0.733890, -0.257710, 0.129660, 0.134590, 0.212370, 0.451790,
2.350170, 0.840720, -1.749810, 0.593270, -1.478660, -0.302680, 1.084590, -1.027030, 0.244960, -4.029630,
-0.335010, -0.328560, 0.557950, -0.112330, -1.035790, -1.952770, 0.553440, 8.112230, 0.637320, -0.443320,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,

  };

  /* unit definition section (see also UnitType) */
  static UnitType Units[240] =
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (inp1) */
      0.0, -0.319720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.235980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.248060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.659390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.790550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.344830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.870710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.613690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.804500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.746210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.339440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.270880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.778100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.715570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.429300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.177850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.711740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.751400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.498210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.035390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.138560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.357770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.188740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.669910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.762180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.067710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.805080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.962870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.793030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.444980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.547940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.898740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.626200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.694440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.940400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.140840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.500210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.508440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.325650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.848570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.608920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.322540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.925840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.059720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.771710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.034710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.037350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.121560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.410140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.183020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.763400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.725140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.176670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.496480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.534750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.640640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.719990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.261940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.737000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.392480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.137230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.550680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.542270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.099710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.853960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.645730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.475750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.290210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.624270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.934360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.723640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.250350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.237290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.483590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.095970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.839620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.975840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.052180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.685730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.836630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.590760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.542660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.762620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.464150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, -0.351590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.481310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.007300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.964990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.428300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.333270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.414420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.960260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.559780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.499280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.148250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.804820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.653020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.280500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.022460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.396200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.627350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.722100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.000850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.062860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.119690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.960540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.429550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.114630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.530310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.015730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (hid11) */
      0.0, 0.152570, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.380300, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, -0.032620, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 0.489240, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.195380, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.420110, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.711600, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, -0.589780, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.305390, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.757240, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, 0.310680, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.028770, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, -0.555340, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 418.054413, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.034860, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 1.011400, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.537690, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.782730, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.632680, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, -0.089610, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, -0.353160, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, -0.130100, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.288730, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, 0.100640, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, 0.245570, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, -0.123880, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.114140, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, -0.556340, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, 0.358800, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, 0.242720, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.152580, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, -0.293820, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, -0.622740, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, 0.447280, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, -0.908590, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, -0.825040, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, 0.536640, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, -0.195380, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, -0.620500, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, 0.120250, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, 0.773200, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, -0.940940, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, -0.764090, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.641320, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.912000, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, -0.026180, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, -0.690750, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, -0.474080, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.272350, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, -0.399700, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.190580, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, -0.095190, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, 0.093210, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, -0.658820, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.542300, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.092450, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, 0.070680, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, 0.233750, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 1.127280, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, -1.089370, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.451910, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.929880, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, -0.617550, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.041350, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, 0.912460, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.176300, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, -0.566590, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.356640, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, -0.297390, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.13535, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.00044, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.97609, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
0.43448, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
0.44719, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.07203, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.96650, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
0.07978, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
1.40146, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
1.42849, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
1.42125, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
1.38546, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.00146, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.42857, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
1.40824, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.71777, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.00369, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.00001, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.46947, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
1.30248, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
1.26433, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
1.41928, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
1.29769, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.42590, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.42549, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
0.82208, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
1.12818, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
0.94556, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
1.40506, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
1.40643, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
1.39416, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.02522, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.98453, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
1.15291, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.38366, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
0.20352, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.56071, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.06134, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.34467, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
1.38520, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
0.04509, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
0.00239, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
0.33209, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.42343, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.05326, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
1.42375, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.03825, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.05741, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
0.37462, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.01703, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
0.00520, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.03712, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
0.18393, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
0.33808, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.71032, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.01213, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
0.00772, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
0.24411, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
1.38256, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.04050, 0.500000, 2,
       &Sources[6388] ,
       &Weights[6388] ,
      }

  };



int net(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[110] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110}; /* members */

  static pUnit Hidden1[30] = {Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130, Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140}; /* members */

  static pUnit Hidden2[30] = {Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170}; /* members */

  static pUnit Output1[9] = {Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179}; /* members */

  static pUnit Special1[1] = {Units + 180}; /* members */

  static pUnit Special2[1] = {Units + 181}; /* members */

  static pUnit Special3[1] = {Units + 182}; /* members */

  static pUnit Special4[1] = {Units + 183}; /* members */

  static pUnit Special5[1] = {Units + 184}; /* members */

  static pUnit Special6[1] = {Units + 185}; /* members */

  static pUnit Special7[1] = {Units + 186}; /* members */

  static pUnit Special8[1] = {Units + 187}; /* members */

  static pUnit Special9[1] = {Units + 188}; /* members */

  static pUnit Special10[1] = {Units + 189}; /* members */

  static pUnit Special11[1] = {Units + 190}; /* members */

  static pUnit Special12[1] = {Units + 191}; /* members */

  static pUnit Special13[1] = {Units + 192}; /* members */

  static pUnit Special14[1] = {Units + 193}; /* members */

  static pUnit Special15[1] = {Units + 194}; /* members */

  static pUnit Special16[1] = {Units + 195}; /* members */

  static pUnit Special17[1] = {Units + 196}; /* members */

  static pUnit Special18[1] = {Units + 197}; /* members */

  static pUnit Special19[1] = {Units + 198}; /* members */

  static pUnit Special20[1] = {Units + 199}; /* members */

  static pUnit Special21[1] = {Units + 200}; /* members */

  static pUnit Special22[1] = {Units + 201}; /* members */

  static pUnit Special23[1] = {Units + 202}; /* members */

  static pUnit Special24[1] = {Units + 203}; /* members */

  static pUnit Special25[1] = {Units + 204}; /* members */

  static pUnit Special26[1] = {Units + 205}; /* members */

  static pUnit Special27[1] = {Units + 206}; /* members */

  static pUnit Special28[1] = {Units + 207}; /* members */

  static pUnit Special29[1] = {Units + 208}; /* members */

  static pUnit Special30[1] = {Units + 209}; /* members */

  static pUnit Special31[1] = {Units + 210}; /* members */

  static pUnit Special32[1] = {Units + 211}; /* members */

  static pUnit Special33[1] = {Units + 212}; /* members */

  static pUnit Special34[1] = {Units + 213}; /* members */

  static pUnit Special35[1] = {Units + 214}; /* members */

  static pUnit Special36[1] = {Units + 215}; /* members */

  static pUnit Special37[1] = {Units + 216}; /* members */

  static pUnit Special38[1] = {Units + 217}; /* members */

  static pUnit Special39[1] = {Units + 218}; /* members */

  static pUnit Special40[1] = {Units + 219}; /* members */

  static pUnit Special41[1] = {Units + 220}; /* members */

  static pUnit Special42[1] = {Units + 221}; /* members */

  static pUnit Special43[1] = {Units + 222}; /* members */

  static pUnit Special44[1] = {Units + 223}; /* members */

  static pUnit Special45[1] = {Units + 224}; /* members */

  static pUnit Special46[1] = {Units + 225}; /* members */

  static pUnit Special47[1] = {Units + 226}; /* members */

  static pUnit Special48[1] = {Units + 227}; /* members */

  static pUnit Special49[1] = {Units + 228}; /* members */

  static pUnit Special50[1] = {Units + 229}; /* members */

  static pUnit Special51[1] = {Units + 230}; /* members */

  static pUnit Special52[1] = {Units + 231}; /* members */

  static pUnit Special53[1] = {Units + 232}; /* members */

  static pUnit Special54[1] = {Units + 233}; /* members */

  static pUnit Special55[1] = {Units + 234}; /* members */

  static pUnit Special56[1] = {Units + 235}; /* members */

  static pUnit Special57[1] = {Units + 236}; /* members */

  static pUnit Special58[1] = {Units + 237}; /* members */

  static pUnit Special59[1] = {Units + 238}; /* members */

  static pUnit Special60[1] = {Units + 239}; /* members */

  static int Output[9] = {171, 172, 173, 174, 175, 176, 177, 178, 179};

  for(member = 0; member < 110; member++) {
    Input[member]->act = in[member];
  }

  for (member = 0; member < 30; member++) {
    unit = Hidden1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 30; member++) {
    unit = Hidden2[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 9; member++) {
    unit = Output1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special2[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special3[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special4[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special5[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special6[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special7[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special8[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special9[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special10[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special11[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special12[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special13[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special14[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special15[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special16[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special17[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special18[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special19[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special20[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special21[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special22[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special23[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special24[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special25[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special26[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special27[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special28[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special29[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special30[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special31[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special32[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special33[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special34[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special35[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special36[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special37[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special38[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special39[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special40[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special41[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special42[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special43[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special44[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special45[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special46[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special47[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special48[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special49[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special50[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special51[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special52[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special53[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special54[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special55[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special56[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special57[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special58[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special59[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Special60[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Identity(sum, unit->Bias);
  };

  for(member = 0; member < 9; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}
