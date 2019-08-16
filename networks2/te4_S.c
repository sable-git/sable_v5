/*********************************************************
  test_newN4.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:34:15 2004
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
1.014620, 0.206280, 0.167110, 1.292710, 0.963670, 0.555870, -0.690830, 0.549310, 0.504410, 1.392150,
-0.403360, 0.354440, 0.642510, 0.700490, 0.119350, 1.356510, 0.270330, 0.448760, -0.904890, -0.326620,
0.514990, 1.076890, -0.958040, 0.805180, 0.494850, 0.814770, -0.014600, 0.769210, -1.652990, -0.804910,
0.356210, 0.932430, -0.651840, -0.412690, 0.044220, 2.360200, -0.807560, -0.547990, -0.776320, -0.105550,
-0.278720, -0.484210, 0.380390, 0.526340, -1.189430, 1.245440, 1.112320, 0.034950, 0.086280, 0.987840,
-0.071440, 2.122890, 0.111300, -0.999600, -0.012720, 0.008610, 0.173100, -0.754610, 0.309240, 0.049410,
-0.211240, -0.348250, 0.376230, -0.940680, 0.378590, 1.353100, 0.255630, 0.587290, 0.254300, -0.119140,
-0.096640, -0.233500, -0.339140, -0.686040, -1.061620, -1.115790, 0.678780, -0.846900, 0.005960, -2.708140,
-0.784250, -1.042460, -0.007200, -0.145290, 0.493170, -0.642620, -0.220830, -0.894660, 0.737940, -0.511920,
-1.313800, -1.002360, -0.726910, 0.826270, -0.516670, -0.543500, -0.414720, 0.647420, -0.236400, 2.066890,
0.988710, -2.351230, -0.972560, 2.942730, 6.679760, -41.919529, 10.543110, -3.388240, 3.083050, -5.422410,
-0.045470, -1.851520, -0.471540, 0.639840, -0.022200, 0.664450, 0.268710, -0.352700, 0.266320, 0.420890,
-0.541800, -0.415860, 0.400500, 0.225070, 0.133850, 0.340100, -0.052970, 0.006520, -0.780350, 0.062070,
0.314670, -4.317710, -2.548860, -0.013080, -0.742510, 0.137590, -0.464820, -0.297410, -2.890800, 0.638220,

0.563930, -0.894020, -0.849350, -0.576470, -0.195680, -0.716640, -0.013410, -0.832260, -0.632950, 0.037460,
0.733890, 0.997040, -0.329500, -0.216520, -0.096580, 0.089180, 0.014840, 0.904170, -0.652390, -0.370120,
0.578740, -0.130710, 1.097020, -0.680150, 0.023190, -1.413120, 1.021170, -0.415630, -0.649260, -0.888580,
0.338430, -2.001640, -0.277540, -0.109790, 1.494340, -0.244440, 0.873200, -0.475030, -0.012840, 3.540680,
0.113350, 0.194860, -2.067820, 1.496200, -0.192810, 0.154610, 0.995620, -1.035980, 2.254530, 0.433640,
-0.487460, -2.699460, 0.088260, 0.741110, -2.407290, -1.799070, -0.155550, 0.939590, -0.333280, -0.724830,
0.728060, 0.265730, -0.200540, -1.701640, 0.136130, 0.902180, 1.275960, -1.225510, 0.013870, -1.075880,
0.257350, 0.881900, 1.115530, -0.617220, 0.097760, -0.666310, -0.345170, -0.500620, 0.330810, -0.373500,
-1.006840, -1.596440, -0.406780, -1.044840, 0.044270, 0.236610, -0.443610, 0.880290, -1.016610, 0.582750,
-0.293450, -0.086120, -0.209240, -0.153890, -0.821230, -0.541130, 0.005170, 1.822400, -0.142260, 0.962340,
-1.489980, 1.411520, -1.192530, 2.452870, -9.250660, 3.916710, -6.876820, 5.717490, 0.268740, -1.279320,
1.512240, -0.952950, 1.249270, -0.348350, -0.575190, 0.382210, 0.484630, 0.586110, 0.028320, 0.368090,
0.848140, 0.456000, -0.777560, -0.774600, -0.015600, 0.641220, -1.187640, -0.656210, -0.086500, 1.096550,
0.487980, -2.807750, -1.146300, 0.136110, 0.386470, 0.010540, -1.474890, 0.113900, 2.837580, 2.803930,

-0.124080, -0.243320, 0.558690, -3.540080, -1.688380, -0.774200, 0.420080, 5.364100, 0.035590, 0.283110,
-0.479590, 0.087900, -0.203110, -0.096830, -0.178350, 0.377490, 0.542890, -0.460730, 0.399600, -2.971920,
-0.501820, -1.443540, -1.218250, 0.146850, -2.936850, 0.327690, 0.065980, 4.549800, 0.719380, -0.330830,
1.825830, 0.247160, 0.450360, -4.195090, 3.474710, -0.041120, 1.541320, -0.023450, 0.801580, 6.657780,
-1.340910, -1.473560, -14.676870, -0.581420, 0.858130, -13.458280, 0.214730, -0.442850, 5.745110, 0.335280,
-0.404510, -4.620940, -2.336080, 0.853550, -10.024290, 1.740820, 0.076830, -1.782190, 0.633980, -0.202340,
-0.270780, -1.548970, 0.514150, 4.314090, -3.821900, 0.706320, -0.005300, 1.870850, 0.152270, -2.131620,
-0.763650, -0.307140, -1.821260, 3.700540, 0.432120, 0.425350, 2.775070, -0.649110, -0.915650, -0.213940,
-1.220230, 0.749300, -4.274110, -0.013730, -0.654370, -1.410200, -0.690610, 0.781210, 0.522750, -1.772670,
-0.950100, 1.204940, 0.048930, -0.227710, -0.284940, -0.335100, -0.319860, 0.554010, -0.255140, 1.381420,
4.671450, -0.777490, 0.171440, -6.043660, -3.298850, -2.431380, 4.436230, 2.522780, 1.148510, -0.613280,
1.304060, 2.835100, 0.620100, -0.188370, 1.555100, 0.394450, 0.228690, 1.088020, 1.560340, 0.145990,
-0.957720, 0.623650, -1.000330, -0.053410, -1.388370, -1.214180, 0.550710, -0.058110, -1.210140, 2.065140,
-1.584640, -7.918110, 1.865900, -0.529240, 0.462200, 0.568140, 2.508950, -0.242870, 8.519440, -0.145210,

-1.043300, -1.280140, 0.043650, 0.674690, 0.215260, 0.497420, -0.067870, 0.235170, 0.787320, -0.094490,
-0.724100, -0.476830, -0.583200, 0.818310, 0.663720, 0.060550, -0.660030, 0.212510, 0.620940, 1.810050,
-1.141540, 0.336050, 2.176630, -1.493940, 0.861530, 1.208280, 0.651930, -1.027640, -0.204550, 1.009190,
-1.101780, 0.379730, 0.352570, 0.629770, -0.231120, 0.435650, -0.208820, -0.001220, -0.404780, 0.580520,
-0.065620, 1.262500, -0.010870, -0.924560, -1.174290, -1.354420, 0.289640, -0.634490, -0.343780, 0.007100,
-0.668140, 0.751520, -1.003820, -0.317920, -0.600680, 0.654400, -0.488810, -0.220480, -1.110310, 0.362140,
0.601220, -0.677560, 0.788430, -1.563720, -1.087300, 1.476440, -0.092230, -0.704850, 0.138970, -4.992320,
-1.078500, 0.357040, 2.047970, -0.397820, -0.748020, 0.368360, -0.636580, 0.170670, -3.402620, 0.875280,
-0.115870, 0.814250, -1.359310, -0.317130, -0.630050, -0.548080, 0.310550, -0.811460, 0.067210, -0.880210,
8.418620, -0.409190, 2.133050, -0.127860, 0.406380, -0.445780, -0.505040, -1.913540, 0.370600, -1.775770,
0.589120, 2.677880, 0.987680, -5.088210, -6.527610, 3.846430, -0.640190, 13.079220, 2.589220, -1.032120,
3.035280, 2.297710, -0.817810, 1.894150, 1.092830, -0.606240, -0.566950, -0.569430, -1.487750, -0.071950,
0.152490, -1.787840, 0.167560, -0.035690, 0.827480, 0.119820, 0.774210, 0.005580, 3.583100, 1.309080,
0.480050, -1.458990, 3.490080, 0.543370, 0.090950, -1.213090, -1.409540, 0.230520, -1.361510, 0.038920,

3.463700, 0.926400, -0.093770, -0.064720, 0.681370, 0.089760, -2.063080, 1.716920, -0.870090, -0.398100,
-4.339620, 0.195920, -0.763020, -0.471300, -0.290060, -0.237550, 1.020110, -0.711540, 0.263180, 0.779960,
-0.171550, -1.989640, 1.496590, 0.997130, -3.668310, 1.986030, -0.128820, 0.463070, -7.422080, 0.937270,
-0.883360, -0.948700, 1.330530, 0.990400, -19.215570, 0.924230, -0.794070, 2.854030, -0.354020, 1.584480,
5.170970, -0.280940, 3.262460, -14.883970, -0.496850, 3.365420, -6.512820, 0.346140, 0.885230, -20.430321,
0.044970, -0.229120, -9.936370, 0.595710, -2.668910, -6.405830, 1.164370, 1.585660, 4.241600, -0.241380,
0.472430, -0.701220, 0.808630, 3.303390, -1.383790, 0.863570, -0.737370, -1.110260, 0.380070, 0.868280,
0.606420, 0.938060, 0.127070, 6.284560, -0.224080, 1.865320, 1.236350, -0.476780, -0.060120, 1.738960,
-1.138400, -0.133590, -1.538980, 0.831740, -1.763570, -0.247250, -1.040180, 0.568810, 2.688980, 0.295710,
-2.378520, -3.762580, 0.977760, -0.202200, -2.126180, 0.127830, 2.414980, -0.003750, -1.334790, -0.906050,
1.766230, 2.086960, -0.768610, 4.965950, 4.833620, 6.430750, 3.012390, -0.044730, 2.401180, -0.312050,
1.929090, 5.977420, -1.169520, 0.006890, -0.744710, 0.463110, -0.863470, -4.206200, 0.992130, -0.902680,
-2.347220, -0.350250, 0.679850, 0.459800, -0.217170, -0.930360, -0.259290, 0.427510, 1.056400, -0.371380,
-0.418630, 1.630090, -2.931490, -0.757130, 0.029360, -1.147740, 2.814630, -1.823670, -4.202300, 6.973310,

208.781693, 207.970901, 208.967621, 209.499695, 208.295044, 601.640747, 209.875046, 208.654526, 601.938049, 209.007629,
208.905594, 601.818420, 208.672226, 208.778931, 602.372864, 208.481949, 209.813507, 601.025635, 209.687210, 209.463760,
601.494934, 209.139465, 209.133881, 600.838562, 208.613968, 208.099487, 602.327820, 209.916779, 208.714493, 602.127441,
208.225296, 209.024109, 602.244629, 209.883774, 209.800003, 209.605362, 208.831528, 208.167084, 601.513123, 207.989029,
208.431656, 208.694138, 72.485260, 208.073380, 208.212097, 207.625793, 208.146927, 209.338470, 72.412102, 208.046432,
208.478775, 209.796463, 602.057495, 208.842712, 72.511040, 208.384720, 208.627090, 209.597733, 601.459839, 208.814529,
209.440887, 602.226562, 208.347931, 209.709442, 601.446533, 209.485184, 208.921371, 602.322876, 209.376968, 208.621658,
601.393555, 208.347260, 208.238434, 602.425720, 208.058578, 209.282776, 601.118225, 208.331390, 208.624466, 209.722595,
208.553741, 208.745331, 600.824402, 209.085327, 208.135590, 208.546600, 207.956863, 207.950531, 209.111969, 209.874893,
208.049194, 208.514053, 208.417282, 209.299118, 208.614395, 208.427048, 209.587616, 208.946594, 208.477097, 602.205505,
602.671082, 601.463196, 209.021820, 209.739807, 208.705322, 209.726242, 209.518295, 208.917755, 208.188904, 208.994919,
209.418289, 602.276245, 208.851883, 209.090714, 209.738831, 209.548492, 208.032761, 209.281357, 209.413391, 208.482651,
-0.008690, 208.375763, 602.431519, 209.830368, 208.535812, 0.939410, 209.030441, 71.702957, 209.775177, 209.606110,
208.859192, 209.406204, 208.456772, 209.514771, 209.880356, 0.774010, 208.792786, 209.455154, 0.328510, 72.982437,

2.890840, 5.811070, 0.280530, -0.556620, -0.801890, -0.274790, 0.809850, -0.554040, 0.196150, -0.232770,
2.496700, 0.361980, -0.115620, 0.044840, 0.640410, -0.429060, -1.961050, 0.014330, 0.463140, 2.003320,
-0.318700, -0.210110, -1.873410, -0.408880, -0.319280, 1.862470, -0.119360, -0.720370, 0.320610, -1.213390,
0.282850, -2.447480, -0.865660, -0.663370, 2.877840, 1.788790, -0.894080, -2.508440, 0.162630, -0.107090,
-0.818950, -6.144290, -0.485100, 2.089110, 1.198210, -1.087580, -0.822970, 0.307500, 0.692650, -0.160410,
-3.784510, -0.147780, 5.056560, 0.169650, 0.821840, 0.940360, 0.093010, 0.763090, -1.134000, 1.147830,
1.858590, 3.434130, -0.504890, 0.035750, -2.393270, 0.429430, 0.777870, 0.730870, -1.036090, -0.478830,
6.703760, 0.814490, 1.878370, -6.296960, 0.355900, -0.780380, 0.578600, -0.455360, -0.682100, 1.146120,
0.486210, -1.307450, 2.255830, -0.328480, -0.589090, -0.676750, 0.616000, 0.049060, 0.080240, 0.860960,
0.610410, -0.371390, 0.510220, -0.798430, -1.120210, -0.710750, 0.211110, -3.882130, 3.366380, -1.855420,
-2.013430, -0.451690, 0.342630, 4.401980, -1.004980, -5.975680, -0.848120, 1.305890, 0.968440, -0.796750,
-1.044860, 0.846750, 8.990190, 1.036430, -0.268020, -0.757820, -0.088620, 0.416680, 0.066990, 0.673960,
1.219270, 2.071710, -0.795330, 0.548040, -1.204760, 0.288420, 0.686670, -0.868140, 0.120150, 1.784650,
0.543880, -0.841300, -2.962230, 0.371860, -0.792340, 1.713630, -0.935200, 0.848210, -9.591180, 1.242080,

-0.829600, 0.271180, 0.427080, 1.046510, -0.389160, -1.013300, -0.001560, -0.099600, 0.877300, 0.194100,
-1.198390, 0.127560, -0.680310, -0.328990, -0.518720, -0.409770, -0.634870, 0.865620, 0.764500, -0.396530,
-0.911670, -0.366710, 0.247850, -0.087360, 0.085970, 0.121800, -1.759800, -0.873410, 0.392990, 0.560010,
1.142120, -0.924560, -0.662350, -0.685380, -2.282960, -0.392870, 1.045800, -0.385560, -0.519230, 0.739060,
0.329290, -0.283570, -1.025520, 0.872520, -0.445370, -0.695100, 1.055550, 0.399890, -0.663090, -0.947290,
-1.108220, -1.314720, -1.400830, 0.810450, -0.231510, -0.543860, 2.300880, 0.645050, -0.576210, 0.108490,
0.572850, 0.407660, 1.304660, 1.180960, 1.047870, -0.674780, -0.910920, -0.717840, 0.752460, -0.584160,
0.531510, 0.276770, 0.802410, 0.051020, -0.028370, 1.382230, 0.116010, 1.818530, 1.600040, 0.271310,
-0.390870, -0.639040, 0.590660, 1.467640, 0.165230, -0.088490, -0.409560, 0.160970, -0.462810, 0.788720,
0.297200, -0.387590, -0.444510, 0.045780, 0.346500, -2.951840, -1.907890, -0.298000, 0.923370, 0.212830,
0.885960, -1.570300, 9.117500, -1.331600, -5.882260, 2.112460, 12.511580, -6.415300, -3.820980, 7.112950,
4.170950, 0.217500, 0.902290, 0.130340, -1.188900, -0.083160, -0.378360, 0.697840, 0.183950, 0.533920,
0.165580, -0.161860, 0.570280, -0.553230, -0.318440, 0.762480, 0.225230, 0.129080, -1.181820, 0.469050,
-1.018380, -1.184580, 1.213380, 0.406830, -0.304030, -0.612320, 0.074770, 0.730830, 2.155560, -0.672590,

0.251810, 0.605700, -0.106400, 0.901660, -0.369010, 1.033220, 0.617610, 1.520370, -0.558650, -0.620910,
0.517220, -0.235530, 0.349490, -0.294660, 0.104060, -0.721230, -0.251560, -0.817320, -0.061430, 0.340740,
0.812460, 0.227940, -0.593360, -0.405270, -0.856720, 0.701460, -0.132960, -0.785640, 0.180990, -0.477140,
0.706770, 0.317700, 0.091940, 0.248910, 0.428190, -0.134250, 0.809700, 0.754380, -0.665350, 0.323180,
0.331210, -0.213320, 0.256430, -1.630900, -0.108850, 0.168470, 0.343960, -0.460210, -0.027630, 1.193030,
0.266990, 0.119320, -1.486060, 0.561400, 0.262450, 1.217380, -1.336620, 0.714550, -0.654870, -0.496740,
0.634420, -0.371090, -0.414420, -1.519610, 0.511360, 0.338760, 0.700410, 0.261800, 0.845870, -0.428980,
0.134680, -0.887310, 1.741390, 0.340520, 0.286130, -0.916390, 0.340060, 0.554860, 0.952180, 0.158510,
-0.377650, -0.293330, -0.257050, -0.352560, -0.322000, -0.101960, -0.113630, 0.193570, -0.075060, -0.623190,
0.212260, 0.453260, 0.696770, -1.055380, 0.660600, 0.110250, 0.682550, -0.588920, 0.956180, 1.809540,
1.712850, 3.161680, -3.267910, -2.558440, -0.030880, 0.760160, 3.719740, 0.515230, 0.917980, 0.162380,
-2.160960, -1.889640, 1.880410, 0.330670, -0.650910, -0.726380, 0.038790, -0.605080, -0.482060, -0.696120,
1.088230, -0.752240, 0.568070, 0.076660, -0.209620, 0.256410, -0.612010, 0.069640, -0.172130, 0.699740,
-0.776450, 3.367230, -2.071730, -0.104700, 1.005940, -0.258880, -0.289300, -0.374970, -2.646760, 3.109700,

-0.435300, -0.613340, 0.161130, 0.484310, 1.422730, 0.493450, 0.737460, -1.231110, 0.377800, -0.473480,
-0.006700, -0.651870, -0.575770, 0.829000, 0.469420, 0.093810, 0.381880, 0.241330, 0.665320, 0.229560,
-0.070820, 0.443020, 0.792520, -0.428890, -0.284080, 0.711100, 0.721110, 0.540450, -0.732810, 0.381720,
0.551070, -0.428810, -0.460320, 0.853450, 0.562760, 1.123390, -0.764090, 0.007030, -0.674480, 1.070490,
-1.459660, 0.285250, -1.035370, -0.625950, 0.137590, -0.437860, -0.748380, 0.077850, 0.900250, -0.048720,
1.315490, -1.083340, -1.077910, 1.250910, -0.991410, 0.427620, -0.912570, 0.242480, -0.569570, 0.714340,
-0.304130, -0.118710, -0.269820, 0.897890, -0.995730, 1.146540, -0.626980, -0.226980, 0.052280, -1.003030,
-0.971560, -0.605070, -1.003010, -0.315470, -0.189680, -0.058410, -0.504730, 0.338690, -0.759040, 0.203460,
-1.074880, 0.211290, -0.217840, 0.565220, 0.482710, -0.429740, -0.278610, -0.150130, -0.236640, -1.582830,
-0.242380, -0.181560, 0.761040, -0.639310, -1.112220, 0.420770, -0.531210, 1.096100, 0.492280, 0.848430,
-1.322270, -0.230320, -0.620450, 2.833970, -0.355580, -6.392110, 2.472600, 13.262780, -1.488030, -1.660160,
0.514990, 0.464350, -1.850270, 0.166640, 0.716980, 0.104990, -0.598360, -0.764430, 0.963490, 0.609580,
-0.875440, -0.044930, 0.084320, 0.737030, 1.121620, 1.087000, 0.218240, -0.120090, 7.478290, 0.313080,
-0.572920, 1.301010, -2.987010, -0.196850, 0.503250, -0.148720, -0.056510, -0.040550, 4.457310, -2.298670,

-1.228820, 1.142100, 0.689750, -0.045720, 0.814640, -0.668490, -0.192780, -0.133920, -0.883240, -0.438250,
-0.664960, 0.317760, -0.288110, 0.600450, -0.738880, 0.853110, 1.311780, -2.428650, 0.907520, -0.719910,
0.718780, -0.566170, 1.073690, -2.898710, -0.531740, -0.337810, -1.141880, 0.880380, -0.092060, 0.108780,
-0.715690, -0.884220, -0.736540, -0.128320, -0.477470, -0.506490, 1.074070, -1.423220, 0.228480, 0.846780,
-3.507500, -1.195130, -0.268300, 1.420740, -0.187760, 0.170860, -2.920450, 1.337680, 0.108600, 2.200340,
0.840110, 0.937320, 0.640770, -0.222060, 0.588820, 2.703800, 0.755910, 0.221650, 1.110550, -0.292190,
-0.679050, 1.988150, -0.318750, -1.560610, 7.869530, -0.100300, 0.037100, -4.561160, -0.340470, 0.448110,
1.648400, -0.556450, -0.433050, -0.360850, -0.668480, -0.038910, -1.967040, 0.486760, 0.544220, 1.312790,
0.389790, 0.972660, 0.700040, -0.402200, -0.043470, -0.766420, -0.488390, -0.370100, 0.029650, -0.038400,
-1.498070, -0.266300, -0.212970, 0.629980, -0.239680, 1.047650, -0.633940, 2.831660, -2.224800, 0.086390,
0.029370, 3.595170, 1.609530, -2.042100, 0.074790, -2.254410, -0.038620, 2.203580, 0.543160, 1.673550,
0.064560, -0.654080, -0.893470, -0.422960, -1.165430, -0.948180, 1.026430, 0.312180, -0.926370, -0.396580,
0.478330, -0.213280, -0.335670, 0.615760, 0.194050, 0.726620, 0.189280, -0.981060, 1.776420, 0.854920,
-0.414610, 1.538470, 5.031660, -0.198090, 0.167870, 0.179370, -0.631910, -0.080890, -0.349970, -6.980790,

-1.525610, -2.312340, 0.125850, 0.297420, 0.294860, -0.193050, 0.973480, 0.184400, 0.020630, -0.909550,
0.229470, -0.543280, -0.753190, -0.233660, -0.947850, 0.870340, 0.199720, 2.594810, -0.136220, 1.563630,
-0.332250, -0.529260, -0.815090, -0.545390, -0.202780, -0.827530, 0.151150, -3.096930, 1.189660, -0.359960,
1.336580, 0.387910, 0.876130, -1.084750, -1.171630, 0.572040, 0.657090, -1.705870, 0.200420, -0.541800,
0.532920, -0.714300, 0.419800, 0.695990, 0.182710, -1.011270, -0.982940, 0.949800, 1.243910, 4.286490,
1.066720, 0.681030, -4.041390, -0.018190, 0.744250, -2.324570, 0.557390, 0.966570, -0.851240, -0.647920,
1.215890, -2.328560, 0.913980, 0.650190, -4.274360, 1.242700, 0.213910, 0.650430, 0.200350, -0.149040,
0.265960, 0.587860, -0.563360, -1.119090, 0.037240, 0.199970, 0.030830, -0.465030, -2.494220, -0.757000,
-1.438900, 0.397440, -0.930420, -0.709020, 0.091200, -0.454230, -0.884530, -2.238990, -0.943020, 0.551740,
-0.143020, -0.116840, -1.297480, -0.245370, -1.327930, -0.585130, 0.561900, -2.326430, -2.416640, -0.296770,
0.280180, -1.600190, -3.888280, -8.321580, 2.430910, 6.652380, 3.744420, 1.013810, -0.070710, 1.371390,
1.284070, -0.118570, -0.683640, 0.860640, 0.903520, -0.341000, 0.036300, 0.136610, 0.259700, 0.574090,
1.084350, -0.918670, 0.175700, 0.095700, -0.800960, 0.400470, 0.345150, 0.054460, -0.815050, -0.545490,
0.124920, -5.484870, -6.247920, 0.344020, -0.968360, 0.725910, -1.322400, 0.024680, -1.719950, 0.906540,

1.048970, 0.739200, -1.166990, 1.101780, 0.476390, 1.124740, -0.167620, -0.355730, -0.654330, 1.516770,
0.366350, 0.884830, -0.587230, 0.017310, 0.204380, -1.121150, -0.392240, 0.579970, 0.087720, 0.629380,
0.556200, 1.318280, -0.397960, 0.247980, 1.750370, 0.246540, 0.107240, -0.349550, 0.018020, -0.345340,
0.047290, -0.850060, 0.286190, 0.945100, 0.319730, 0.178060, -0.150180, -0.491730, -0.663780, 0.477760,
1.542390, -0.594230, 2.187710, 0.779750, -0.224250, -4.525010, -0.184920, 0.463100, -5.748980, -0.889700,
0.860270, 1.469840, -0.911350, 0.605470, 6.117560, -0.807300, -0.291230, -4.531420, 0.776510, -0.141530,
-2.754440, -0.669500, -0.433880, 10.278290, -0.517390, -1.771530, 0.735590, -0.802040, 0.387950, -3.880740,
-2.851600, -1.099000, 22.318621, -1.007170, -0.697430, -3.299020, 0.536390, -0.954000, 1.084680, 0.469470,
-0.616790, 0.374110, 0.219360, -0.201230, -0.821750, 0.632280, 0.846080, 0.367910, -1.034120, -0.022700,
-0.318770, -0.123180, 0.122430, 0.065890, 2.833880, -0.951200, -0.921890, -0.583720, -0.478940, 1.155080,
0.222000, 0.270940, -0.616530, -1.866220, -1.860450, 2.909090, 4.730870, -1.590900, -4.144820, -0.413710,
-0.571630, 0.178520, -0.310300, 0.005820, -0.776710, 1.093690, 0.913370, 0.079250, 0.496600, -0.621420,
0.590080, 0.358240, -0.039250, 0.240170, 0.577460, -0.047750, -0.689140, -0.163460, -0.633480, -0.007610,
-0.878550, -2.794770, -1.946670, 0.086630, -0.106760, 0.882870, 0.113010, -0.765520, -2.031960, 0.245470,

-0.084760, 0.334770, 3.974630, -2.039850, 4.314160, -1.587520, 4.261330, -0.763130, -0.751250, -0.876470,
-1.670130, 4.569820, 1.075220, 1.960030, -0.892440, 5.401170, -8.417500, 0.234890, 1.493640, 2.962680,
-0.044340, 1.068730, 7.008780, -0.636170, -3.113000, 2.840980, 0.492530, 3.415280, -11.680440, 2.164490,
-1.666820, 10.361860, -0.079270, -0.016760, 1.451430, -1.221690, -0.859530, -3.623870, -3.475180, 1.543040,
2.227570, -0.098460, 0.625980, 3.349610, -0.927890, -4.126930, -0.615390, -0.091550, 1.893230, -3.589560,
-3.447960, -0.596820, 2.359400, 9.912550, -2.354920, -4.117400, 1.374870, 0.444940, 1.196450, -6.153760,
0.817300, -0.329110, 9.160290, 1.537030, -1.246900, 7.650970, -1.006780, 0.588670, -9.211500, -7.343160,
1.332480, 9.666490, 1.491150, -1.311350, 4.861370, 9.453590, -0.118630, -3.003910, 0.473980, 1.479640,
0.605060, -0.868890, -0.351230, 4.229880, 0.224190, -0.320490, 0.903590, 0.709580, -2.020740, 2.640840,
-5.304390, 1.208330, -8.749910, 0.504030, -1.816670, -3.227310, -1.657330, -1.158630, 3.604310, 7.174100,
7.775200, -0.742810, -4.890260, -2.421160, -9.736980, 9.676970, -8.063130, 2.564070, 4.877370, 2.174900,
-3.595320, 3.545540, 1.118390, 0.409820, -1.169460, 0.390960, 1.064310, -0.160190, 2.618920, 1.926380,
-1.657810, -6.176890, -2.440270, 0.391270, -3.250260, 1.167730, 0.342330, -2.857460, 2.101530, 2.310890,
-0.038640, 0.879820, 0.387390, -1.208310, 0.694360, 1.059250, 2.529280, -0.280240, -5.810100, -7.565010,

0.588470, 0.377720, 1.372650, -0.108770, 2.292980, 0.089520, -0.926040, -3.489540, 0.059320, 0.098100,
0.873400, -0.604150, -0.060010, -0.206060, 0.017280, -0.702100, -2.241920, -0.299510, -0.593600, 2.411130,
0.047230, -0.964230, -0.439390, -0.506960, -1.473210, -0.900190, 0.780050, -0.570050, -0.117710, 0.178930,
0.818910, 2.371000, 0.309300, -1.211530, -2.590140, 0.489640, 0.314240, 4.607870, -4.163700, 0.047340,
-0.692820, 1.307450, -0.542680, 2.214590, -0.035680, -0.952470, -8.574840, -1.386030, -0.727320, -3.353250,
-0.394430, -0.920860, 12.942570, 0.854850, -0.514760, -6.829800, -1.530030, -0.733650, 1.236970, 0.484150,
0.001080, 6.991550, -0.873990, -0.749060, 4.894660, 0.196260, 0.450200, 2.481980, 0.621270, -0.716110,
-2.185620, -0.635760, -0.550990, 17.174801, 1.596920, -0.066580, 0.620740, 0.558760, -0.874760, -1.209120,
-0.027710, -0.211490, -0.583020, 0.662500, -0.803130, 1.908610, -0.030010, 0.245780, -1.800790, -0.516220,
0.572290, 4.310010, -1.362430, -1.208620, 2.637140, -0.436980, -1.992120, -2.695330, 1.034070, 1.725930,
1.326880, 1.019400, 1.157300, -4.572040, -2.435560, -2.039960, -2.915970, -1.431920, 5.203210, 0.156020,
0.046370, 3.864000, -1.372770, -0.038050, -0.404820, 0.733860, 0.785250, 0.411600, -0.209750, -0.360690,
-0.838710, -0.530140, -0.294550, 0.910570, -0.181070, 0.849980, 0.047050, 0.464120, -2.579640, 1.757870,
0.287000, 4.092760, 2.395560, 0.894040, -0.171990, -1.205730, 0.166660, 0.297580, -2.865810, 6.296740,

-0.482570, -1.430670, -2.733410, -0.800060, 0.704540, -0.265580, -0.535810, 3.558740, -0.420610, 0.162790,
0.327450, 0.833350, 0.131880, 0.502450, -0.365850, 0.073590, 1.961380, -0.554690, 0.427310, -3.980670,
1.657000, 0.107810, 2.770820, 0.093840, 0.397980, -0.156380, -0.623840, 0.325330, -0.591490, 1.066690,
0.681600, -6.631880, 0.723270, -0.120270, 8.307600, -1.710090, -1.019150, -2.953080, -0.331960, -0.312340,
-0.807560, -0.835060, -0.671780, 2.554730, -1.125100, -0.987730, 0.844210, -0.620070, 0.015410, 0.788500,
-3.784930, -1.025640, 2.476140, 0.275430, -0.399160, 2.015630, 2.037420, 0.187660, 0.362110, 0.566390,
-0.607420, -2.366220, 0.176660, 0.543140, 2.070370, 0.695130, 0.298880, 3.164960, 1.280910, 1.032540,
-7.133000, 0.424090, -0.504290, 3.715590, 2.881880, 0.833560, -0.447030, -0.627460, 0.150480, 0.098870,
-0.650970, -0.705470, 1.474960, 0.798410, 0.464960, 0.005120, -0.566390, 1.230320, -2.055220, 0.136010,
1.054320, 1.399310, -0.410270, 0.164630, -0.449800, 0.269060, -0.630740, 2.021380, 0.909670, -2.689470,
2.804800, 5.379860, -2.371730, -5.083070, -1.295310, -1.425350, 6.693350, 2.820250, -1.310230, -0.026520,
0.483240, 2.173690, -0.421080, 0.227770, 0.230510, 0.713160, -0.537990, 1.116890, -0.212240, -0.490820,
0.958670, 0.403400, -0.656130, -0.126660, -0.743180, -0.113510, -0.252420, 0.520490, -1.534630, -0.608490,
-0.776070, 0.774420, 1.206600, 0.077760, -0.923610, -1.085340, 0.482060, -0.616480, -0.200960, 1.523610,

-2.454570, -0.468800, -0.719370, -0.604690, 0.976940, 0.644150, -0.917280, 0.277000, -0.117310, -2.345430,
0.829560, -0.131130, -2.432190, -0.362660, -0.852680, 3.942990, 1.161790, 0.630070, 1.529620, 0.937590,
-1.579700, 0.889870, 0.827300, -0.546830, 4.510560, -0.695210, 0.436990, 4.010220, -0.429370, -0.258080,
-0.858530, 0.184040, 0.671370, -1.830610, -0.200540, -0.119020, 1.544130, -0.182860, -0.936340, -0.500900,
-0.870870, 0.492140, -0.089060, -0.585500, -0.175860, -0.045980, 0.815380, -1.585350, 3.987390, -0.465020,
-0.558950, 5.796960, -0.618510, -0.182060, -3.916430, -0.005020, 1.051950, 1.558710, -1.003290, 1.052710,
3.924390, 0.086580, 1.051270, 0.357720, -0.819960, 0.480180, -0.487470, 0.315840, -0.757510, -1.413240,
-0.552200, 0.085170, -0.976750, 0.815270, 0.140950, 0.155690, 1.986120, 0.401880, 1.136770, -0.102920,
-1.079110, -3.733860, -0.052750, 0.005860, -1.329550, 0.661300, -0.769820, -0.092270, 0.582470, 0.543990,
2.317250, -0.938060, -0.872220, 0.320110, -0.395410, 0.567550, 2.297810, -0.687880, -0.947340, 1.669490,
0.301820, -0.082110, 3.927420, 4.835260, -0.111370, -0.260780, 0.399920, -6.430190, 0.064640, 0.118100,
-1.026230, 3.349890, -1.740770, -1.569300, -1.765450, 0.364970, 0.992700, 0.345880, 0.324360, 0.234630,
-0.304540, 0.955910, -0.708800, -0.902100, -0.347930, 1.123160, -0.188890, 0.788060, 0.509240, 3.732270,
0.337830, -16.900419, 4.408190, 0.144680, -0.335690, -0.474300, -2.193590, 0.344870, 14.149770, -0.075680,

0.701020, -0.439080, 0.465700, 0.529080, 0.780800, 0.302880, 0.649050, -0.649530, -0.324390, 0.101060,
-0.043170, 0.595440, -1.849200, -0.870520, -0.301890, 2.939400, 0.024850, 0.738050, 0.087040, -1.553480,
0.345740, 2.214560, 0.328230, -0.562610, 2.482260, -0.834890, 0.617730, -1.643440, -0.265030, -1.218250,
-4.934720, -0.545220, -1.173470, 4.990830, -0.683810, 0.332310, -0.706900, -1.221360, -1.139100, 0.530630,
0.050760, 0.773210, 3.115300, -0.554640, -0.058460, -0.362910, -0.586920, 0.653700, 5.263570, 0.275390,
-0.468080, -0.403560, 2.096660, 0.734210, 1.268060, 0.282510, -0.638370, 1.679980, 0.171980, -0.715590,
1.612960, 3.245910, 0.262480, -0.636360, -0.623070, 0.983060, -0.689150, -1.009590, 1.005870, -1.747310,
0.810950, -0.230150, 0.643520, -0.819120, -0.162540, 1.035010, 0.429980, -1.173640, -0.008130, -0.601700,
0.313150, -2.443940, -1.098020, -0.875890, -0.128200, 0.221260, -0.580690, 0.016540, -0.322150, -0.081000,
4.505890, -0.979410, 0.377770, -0.042590, -0.126930, 0.503060, -0.901080, 0.148590, 0.418010, -0.648250,
-0.483540, -0.676590, 4.227470, -0.420370, 0.156720, -0.937560, 1.216270, -0.404770, -0.206380, -1.847460,
1.623360, -4.382580, 1.311780, 0.721580, -0.147930, -0.059460, -0.882010, -0.197970, 0.730500, -0.191890,
-0.022540, -0.856200, 0.277930, 0.617550, -0.580720, 0.060570, -0.173020, 0.414530, -0.888410, -1.915000,
-0.111780, -6.335180, 4.540920, -0.220390, 0.710670, 0.127210, 1.317030, -0.661010, -25.819420, 1.797540,

1.125660, 0.249550, -0.470700, 0.617470, -0.038240, 0.668920, -1.495410, -0.295610, 0.923260, 0.564810,
-1.299270, 0.691300, 0.641110, 0.690600, -0.283940, -0.847610, -1.425140, -0.844550, 0.413730, -1.348060,
-0.369830, 0.630940, 2.123170, 0.166320, -0.427120, -0.033420, 0.277960, -0.000380, -0.818360, 0.321480,
0.398770, 0.699320, 0.511680, -0.898130, -0.903260, -1.106550, -0.321450, 0.218480, -0.750480, -1.258980,
-2.407430, -0.311320, 0.837460, 0.011360, 0.664310, 0.365260, 2.176040, -0.582340, 2.650960, -3.188990,
-0.784740, -5.223630, -5.654360, 1.946750, 4.861980, 4.562840, 0.787580, -0.219340, 0.241430, 1.680820,
-0.327070, -3.609620, -0.879830, -3.735200, -3.211530, 1.892100, -1.872720, 1.452380, 0.894720, 5.510520,
-0.470710, 0.671840, 1.152410, -3.825590, 0.717680, 0.637840, 1.862500, 0.613280, 0.340570, 1.635530,
-0.736300, -1.495270, 0.723530, -1.054040, -1.999300, -1.057790, 0.855430, -0.232180, -1.490030, -0.512380,
-1.089150, 0.098940, 0.236810, -0.206220, 0.713320, -0.310080, 0.379260, -0.632050, -0.947900, -0.672370,
-1.544500, -0.739180, -1.504850, 1.561540, 3.210630, 0.991210, 2.149270, -0.530580, -1.134010, -2.493620,
0.818480, -1.863660, -0.144280, -0.658650, -1.519680, -0.425190, -0.125550, -0.754040, 0.764190, 0.535830,
0.188800, 0.332410, -1.207220, 0.842080, 0.777820, -0.505440, -0.411710, -0.706350, 0.180360, -0.041700,
-0.334550, 2.572240, 4.252230, -0.280990, 0.810000, -0.058520, -0.002880, -0.864960, 3.660880, 2.268600,

-1.132970, -0.280180, 1.185240, 0.510570, -0.538100, -0.686750, 1.396470, 0.507300, -0.687200, -0.447030,
-0.949570, -0.005650, -0.765790, -0.169390, -1.028810, -0.278940, 0.474830, -0.025290, 0.668930, 0.629110,
0.603210, 0.723010, -0.847300, -1.305520, 0.665930, -0.684320, 0.867760, -0.159530, -0.019050, -0.929990,
0.753610, 0.645490, 0.206410, -0.712280, -1.505490, 1.699730, 0.601240, 1.217670, 0.731270, 0.877280,
0.073800, 1.356210, 0.185030, 1.599110, -0.800820, 2.408380, -1.058080, 0.682610, 0.119430, -0.818810,
1.629390, -0.101470, 0.374700, -1.068150, 0.116870, -0.339190, 0.223210, 0.137070, 0.915690, 0.037310,
0.630760, -0.751490, 0.348290, 2.768580, -2.596300, 1.235630, -0.039120, 0.725040, 0.169400, -0.305170,
0.420400, 0.484600, 1.187270, -0.604930, -0.129920, 0.546670, -0.826390, 0.534410, -0.374050, -0.549020,
-0.835200, 0.153500, -1.911020, 0.626740, -0.661740, 0.537790, -0.565910, 0.523680, -0.150770, 0.514490,
0.750870, -0.344700, 0.221940, 0.337160, 0.577510, 0.067300, -1.475710, -0.360560, -0.397210, 0.272000,
-0.063500, 2.183850, 3.101140, 2.310000, -1.130230, -1.981220, 6.680410, -0.991570, -2.280190, -1.856150,
-6.560680, 2.004300, -0.665980, -0.004670, -0.274780, -0.051090, 0.399650, 0.140890, -1.348840, -0.648150,
0.930420, -0.587820, 0.332710, -1.121120, 0.363180, -0.569430, -0.884880, 0.412500, 1.781790, -1.384510,
-0.616920, 2.676200, 0.999240, 0.618310, 0.198970, 0.120470, -0.056210, -0.533300, -8.552680, 1.806430,

-0.296720, -0.334180, 0.629490, 0.625220, 1.079970, 0.068720, 0.040580, -2.862580, 0.621400, -0.713120,
1.150720, -1.164310, -0.019500, 0.814030, -0.660510, 0.504140, 1.189600, -0.887170, 0.841250, -4.248610,
0.010870, 0.045240, 2.269950, 0.620430, -0.727630, 3.436330, -0.735160, -0.172720, 2.037750, -1.586310,
0.418760, -5.284640, -0.009460, 0.733860, 2.580060, 0.732080, -0.519120, 6.388470, -3.664500, -0.980760,
0.705910, 2.110140, 0.202910, 0.099290, -1.632940, -0.484570, 0.609480, 2.888190, -0.451650, 0.181330,
0.245320, -0.579290, -2.021690, 0.623180, 0.856650, 2.901900, -0.010280, -0.091440, -0.781390, -0.159270,
3.494490, 0.878820, -0.358810, -0.966310, 1.530000, 10.514570, -0.586580, -0.550770, -0.694030, 1.592430,
-0.739830, -0.150380, -0.958630, -0.977620, 0.171050, -0.046590, -4.053900, 0.226840, 0.682240, 2.006580,
-0.231170, -0.168620, -0.319690, -0.273230, 0.230870, -0.797540, 0.552980, -0.277440, 3.668190, 0.433710,
-0.728180, 0.148060, 0.269100, 0.662520, -0.205830, 1.582680, 1.197330, -0.876390, -0.038320, 0.757050,
-1.528260, 0.228670, -6.072120, 3.252660, -0.320180, -3.559700, -3.184250, -6.863570, 4.787070, -1.212910,
1.052940, -2.952830, -3.152320, -0.292050, -0.270190, 0.391040, 0.577740, 0.578900, 0.721070, 0.517020,
-1.641970, 0.797090, 0.255910, -0.904410, 1.547720, -0.923160, -0.849910, -0.868930, 0.390980, 0.699700,
-0.638530, -1.166980, 2.882550, -0.231130, 0.150430, 0.849260, 0.433570, 0.087870, 0.715350, -1.930040,

-1.039530, 0.217620, 0.006850, 0.279240, -0.759710, -0.107150, -0.488380, -0.080520, -0.975820, 0.261440,
-0.379470, 0.242190, 0.788730, 0.590800, 0.302890, -0.112790, 0.082480, -0.173800, 0.394170, 0.739630,
0.401730, 0.766780, -0.168020, 0.560200, -1.198270, -0.883540, -0.819520, 0.012100, -0.516360, -0.003440,
0.112440, -0.706560, 0.005090, 0.012690, 1.346700, 0.636430, 0.529620, 1.225880, 0.087630, -0.054660,
-0.641000, -0.320890, -0.677630, 0.251400, -0.345730, -0.347410, -2.759850, 0.690500, -0.986930, 0.882990,
-0.417710, -0.104960, -0.399100, -1.638030, -1.078050, 0.626810, 3.226800, -0.047190, -1.310880, -0.513990,
0.195450, -0.468640, -0.518390, 0.605560, -0.176940, -3.591590, -0.275080, -0.822480, 1.301700, -1.052410,
1.140620, -1.401930, -0.080370, -1.382350, -0.494080, 0.417610, 1.057440, 0.117510, 0.437350, 1.752730,
-0.972890, 0.367360, -0.826150, -0.937580, 0.849540, 1.296230, 1.456780, 0.414750, 3.001650, 0.553620,
0.342670, -2.764280, -2.589460, 0.200600, -1.158670, 2.342890, 0.362440, -1.638990, -1.168030, 1.358240,
-0.411860, 0.929700, -0.846580, -1.836720, -2.781350, -1.008260, 3.006170, 1.174900, -4.050630, -0.564090,
-0.374690, 0.343530, -0.520910, -0.951640, 0.186420, -0.358680, 0.082760, 0.017050, 0.891010, 0.646460,
0.136640, -0.152780, -0.030980, -0.206530, 0.109320, 0.217000, -0.425730, -0.207950, 0.108120, 0.359930,
-0.878030, -0.305140, -0.660980, 0.071180, 0.088290, 0.240240, -0.191270, 0.101040, -0.784870, -0.100520,

0.388970, 0.013380, 0.686180, -1.851100, 0.132070, -1.033120, 0.302550, -0.063450, -0.287900, -0.334190,
0.256110, -0.954260, -0.581550, -0.747190, 1.265430, 0.389380, 0.585840, -0.283580, 0.981490, -0.710620,
-0.676570, 0.366220, 0.752600, 0.069570, 0.262560, 0.514240, 0.342640, 1.199160, -0.311170, 1.075950,
-0.138850, -0.323460, 0.564560, -1.335360, 1.224110, -0.923250, -0.520620, -2.052160, -0.443070, -0.338220,
2.613600, -0.775400, 0.129880, -0.272300, -0.578240, 1.647170, -2.020280, 1.544830, 0.635440, 0.719280,
-0.363980, -1.856990, 0.367170, -1.049190, -0.524030, -0.435150, 0.942390, 0.828720, 1.037150, -1.782390,
-0.657070, 0.377190, -0.963580, 0.117910, -0.156580, 0.280270, -0.026000, 0.236810, -0.038190, -0.928850,
-0.511810, 0.826390, 0.333800, -0.432680, -0.258260, 0.185250, 0.149790, -0.169950, 1.627810, 1.098390,
0.794570, -1.104310, 0.613210, -0.318550, 0.300350, 0.278620, -0.245310, 0.822620, -0.745360, 0.545100,
-1.338180, 0.750920, 0.439250, 0.238190, -0.666600, -0.719870, -0.820020, -1.133810, -0.004040, 0.567030,
0.218580, -0.010270, 0.769260, -0.235030, -3.315300, 1.086740, -7.940250, 4.854260, -1.829810, 0.081090,
-0.140950, 2.153150, 0.004390, -0.301740, 0.685270, 0.101490, -0.859610, -0.179770, -0.056390, -0.365030,
0.051990, -0.046460, 0.529670, -0.556600, 0.657130, -0.901250, -0.122250, 0.370530, 0.712800, 0.596370,
-0.668150, -2.767550, -2.038900, -0.511840, 0.451140, -0.409970, 0.173480, 0.103960, -1.593580, -0.611820,

-0.054550, -0.553020, 1.840630, -1.817270, 1.433320, 0.003420, 0.680330, 3.355210, -0.302090, 4.328290,
-2.592600, 0.139350, 0.373340, 0.226590, -1.162400, -4.538550, -0.123630, 0.445760, 0.703580, 0.757270,
-3.111780, -3.642370, 0.248760, 0.125830, 3.260790, -2.204860, -0.090090, 0.955390, 0.408260, -2.203310,
1.090270, 0.117350, 0.997450, -0.888790, -1.304670, 1.798530, -2.635490, 0.319430, -0.582700, -0.063390,
-6.682160, 0.947380, 1.270760, 0.012030, 0.490600, -7.197670, -0.654830, 1.338590, 0.032410, -0.499370,
-0.267780, 5.544130, -0.273700, 0.088240, -7.808940, 1.019340, 0.713400, -0.789280, 0.545740, -0.025820,
-0.089080, -0.467130, 0.429730, 4.800230, 0.592710, 3.338060, -0.005800, 0.165180, -0.531630, -3.828490,
0.279600, 0.554590, -3.315420, -0.303860, 1.208360, 0.911120, -0.671340, -1.442120, -0.620340, 1.353880,
-0.882250, 2.213090, -0.018410, 2.067680, 1.028750, -0.518800, 1.976140, 3.482800, -0.507320, -2.716660,
-2.108820, -0.163550, 0.772420, -1.035450, 0.803160, 1.419950, 0.178150, 0.992580, -0.275760, 2.309130,
-0.752310, 10.843810, 2.695270, -4.557150, 2.303860, -0.879710, 1.913650, 3.566220, 4.060980, -1.618720,
-3.065950, 6.313370, -1.699340, -1.987550, 1.061870, 0.476440, 0.833150, -2.620660, 1.896130, -1.097480,
1.533350, 3.236490, -0.967400, 0.147900, -0.266940, 0.835650, -1.172320, 0.463870, -1.579650, -0.532100,
-0.445340, -8.546770, 3.015690, 2.133060, -0.843190, -1.252190, -0.924430, -2.011160, 3.674550, -0.857330,

35.247890, 297.803925, 102.365608, 102.546463, 102.760139, 104.155380, 298.242920, 855.812317, 102.938202, 103.322807,
296.398438, 103.204224, 104.419487, 854.856201, 102.936638, 103.804749, 298.130951, 36.773441, 37.050400, 296.736969,
104.138611, 36.409920, 298.165741, 35.937420, 35.925430, 854.935120, 36.544628, 35.456631, 102.885178, 35.348999,
5.691170, 296.989685, 36.220371, 4.846670, 297.853485, 12.700440, 4.247370, 296.854248, 12.202440, 5.402610,
296.216217, 12.519560, 4.259000, 296.439880, 5.426370, 5.479730, 296.495361, 13.268420, 4.208670, 102.250633,
1.256580, 5.131410, 102.038048, 4.513460, 3.835990, 102.294289, 0.479700, 5.232760, 102.298042, 3.838240,
-0.268480, 103.056953, 36.475971, 4.882490, 102.720154, 3.783590, 4.351000, 103.447197, 36.210030, 3.929140,
102.296341, 35.617210, 4.319120, 103.858032, 35.469109, 5.432740, 103.504807, 36.056049, 104.163689, 36.460369,
104.257896, 4.938780, 103.622276, 36.724079, 4.524100, 35.823238, 103.227707, 35.560520, 103.605499, 102.395737,
12.058370, 103.332474, 103.152832, 13.920110, 102.493248, 103.269997, 36.225750, 103.976402, 102.512894, 102.633476,
104.378151, 104.344559, 12.583840, 12.494670, 4.317820, 5.036190, 12.835850, 297.599976, 104.287003, 102.549431,
296.230011, 103.186157, 36.498119, 36.346409, 5.160820, 103.371094, 102.469757, 35.032970, 35.696819, 35.541142,
102.935989, 35.603512, 36.817120, 103.957779, 35.993000, 103.076118, 35.760872, 36.707890, 36.167870, 103.691269,
102.583672, 855.542053, 1.524630, 104.091728, 102.608147, 5.199880, 297.469727, 103.348228, 37.014111, 1.280930,

-0.757020, 0.002380, -0.615210, 0.296550, -0.259910, -0.704990, 0.636970, -0.387690, -0.101090, 0.066890,
-0.215270, 0.188640, -0.773110, 0.425470, -0.196650, 1.081450, -0.045130, 0.226040, -0.368430, 0.295150,
0.569310, 0.741000, -0.331090, -0.281040, 1.496530, -0.432930, -0.124830, 0.149290, -0.221340, -0.682740,
-0.048670, 0.136810, 0.458400, -0.294090, -0.534790, -0.347250, -0.700930, 2.054720, 0.919750, 0.825430,
-0.763510, -0.761780, -0.526320, 0.294630, -1.245430, 0.722080, 7.118070, -0.952220, 0.131900, -0.353480,
0.054040, 4.739900, -1.433420, 0.578120, -1.696860, 2.612300, -0.904670, -2.786790, -1.870650, 0.268580,
1.028250, 0.028730, -0.340610, 0.797070, 0.468260, 0.535550, -1.554080, -0.129570, 0.027020, -0.717760,
1.126440, 0.421380, 0.505840, -1.875950, 0.599420, -0.845610, 0.097860, 0.519370, -0.438730, 1.347310,
-0.231610, 0.530090, -1.291280, 0.048240, 0.385000, -1.513770, -0.536710, -0.948330, 1.219900, -0.067390,
1.271590, -0.560000, 0.945690, 0.524720, 0.635340, -0.952830, 0.509990, -0.634000, 0.280200, -0.133740,
-0.037190, 0.265120, 1.004290, -0.421890, 1.159350, -2.595920, -0.945120, 2.330750, -1.524220, -0.831920,
-1.112250, 0.623320, 0.359400, -0.576590, 0.552470, 1.216780, -0.485230, -0.310810, -0.667580, 0.155360,
-1.464030, -0.515740, 0.571190, 0.338210, -0.074110, 0.020670, -0.657130, -0.241070, 0.349700, 0.331850,
0.095490, -7.892580, -1.363840, 0.663490, -0.451150, 0.362250, -0.587240, 0.857050, 2.619690, -1.259160,

-0.453290, 1.001660, 2.380400, -0.209930, 1.138590, -1.050780, 0.290950, 0.201870, 0.207330, -0.797980,
0.185870, 0.308230, 0.909800, 0.069280, -0.859260, 2.087390, -1.164660, 0.422730, -1.147170, 0.401370,
-0.525490, 0.155780, -0.071590, -2.626110, 2.124490, -0.519770, -0.859920, -1.630110, 1.293890, -0.950540,
-0.916800, 0.264340, 0.497150, 0.759500, -1.667740, -0.588830, -0.465350, -0.790750, 0.236230, -2.457720,
-0.430100, -1.250790, -4.262790, -0.330480, 1.014530, 2.388620, 0.103720, -1.693410, 4.425180, -0.164640,
-0.853970, 0.615610, 1.672850, -0.139490, -1.457260, -0.897460, -2.029600, 1.049730, 0.683370, -0.092140,
-0.678490, 4.688280, -0.744000, -0.932370, 0.259240, -0.297070, -0.459750, -2.999310, 0.123350, 0.063970,
1.028980, 0.982650, 0.386240, -4.814320, 0.726980, -0.508270, -3.123080, 0.803750, 0.299290, 10.083400,
0.754480, -0.045240, -0.934400, -0.294440, -0.557310, -2.647120, 0.218490, -0.249980, -2.498170, -0.824920,
0.448510, -3.832790, -0.547940, 1.662680, 1.036600, 0.484960, -1.233270, -1.434680, 0.213600, -0.827740,
1.399080, -5.093110, 2.275850, -1.743150, -1.144050, -0.033780, -4.504650, 2.158180, 1.212160, 1.372430,
1.941380, -0.506670, -3.859820, 0.783730, -1.271070, -0.074100, -1.409630, 1.200310, 0.114650, 1.313720,
-1.418720, -0.320750, 1.119240, 1.139450, -0.796730, -0.543740, 0.719290, -1.229270, -0.425000, -0.441510,
0.069780, 2.303670, 3.077300, 0.901990, -0.697510, -0.555790, -0.322850, -0.435160, 1.594200, -1.561260,

0.108360, -0.159090, 0.804290, -1.727610, -0.050600, -1.043570, 0.043760, 1.255190, -0.371500, 0.708890,
-2.756740, -0.980920, -0.416620, -0.568960, 0.339700, -0.327610, -0.856330, -1.808030, 0.121010, -1.173490,
-0.106630, 0.258510, 0.575600, -0.928150, -0.205970, 1.825270, 0.849330, 1.269220, 0.106560, 0.219370,
-0.670770, 1.733020, -0.570130, -0.455900, 0.900900, 0.674210, 0.974950, 0.535000, -1.247150, 0.402800,
-0.138380, 1.043690, -0.495980, -0.357460, 1.591450, 0.696880, 0.212040, 0.007080, 0.292100, -0.274950,
0.928220, 2.166490, 0.812250, -0.785650, 1.779970, 0.128890, 1.650230, -0.859500, -0.095180, -0.771540,
1.781880, 1.211420, -0.710170, -0.713380, 0.096120, -0.335200, 1.352290, -0.416250, -0.010520, 0.817030,
0.216840, 0.604420, 0.687890, 0.937860, 0.764390, 1.151570, 0.372940, -0.190100, -0.121470, 0.652170,
0.264030, 0.362450, -4.768780, -1.348600, 1.303710, 0.870740, 1.423780, -0.279540, 0.685080, -0.260400,
-1.813500, -1.575280, -0.717510, 0.409800, 2.445610, 0.163680, 0.187940, -1.383180, 0.156170, 0.669450,
2.876780, 3.533270, 0.331060, -4.170550, -7.734900, -0.972900, 2.267970, 2.021990, 1.040100, -1.479460,
-0.976290, -0.170710, -0.354510, -0.297800, -1.007470, -0.830660, 0.230550, -0.228180, -0.071380, -0.795990,
-0.905610, 0.318330, -0.234150, -0.113520, 0.414060, -0.196130, 0.475700, -0.336420, 2.815010, -0.492720,
1.225710, -7.329520, -3.722390, 0.048920, 0.081710, -0.327010, -0.298390, -0.169150, 0.952340, -4.324230,

-0.115630, -2.081490, 0.744600, 0.248570, 1.501660, -0.639210, 0.010870, 0.963740, 1.029240, 0.241630,
1.353790, -0.441660, -0.304480, -1.643080, 0.489000, 0.660370, -0.360560, -0.763880, 0.841760, -0.136060,
0.227260, -0.713620, -1.467210, -1.164480, 0.890360, 2.201990, -1.068040, -1.399180, 0.213450, 1.496380,
-0.292070, -1.794340, -0.817460, 0.782860, 2.127510, -0.481760, -1.058960, -0.127240, -1.647190, -0.903700,
-6.080560, 0.144720, 0.687410, 1.146230, -2.381380, 0.197190, -1.374050, 6.472660, 1.097420, 0.991390,
2.483580, 0.264340, 0.684330, -0.950190, 0.468520, -1.631690, -8.440080, 0.233440, 3.993370, 0.955230,
0.294590, -0.013310, 0.288770, -0.780420, -5.916990, -0.556690, 0.339360, 6.146180, -0.288350, 0.527790,
5.390530, -0.291020, 0.037150, -8.034300, -1.549550, -0.452340, 10.002700, -0.073400, -0.321460, -5.048640,
-0.346880, 0.065030, -21.066210, 0.159600, 0.826310, 12.194150, 0.901810, -0.150070, -1.408760, 2.901850,
0.050780, -16.284220, -0.132950, 0.025510, 2.230180, -0.521680, -0.040260, 0.673750, -0.296540, -0.374480,
-1.973650, 1.648660, -5.754260, 2.597160, 1.664900, 6.568620, 0.548050, -1.380660, -0.066660, -2.044990,
1.910150, 0.890660, 2.116800, 0.223870, -0.370930, -0.282340, -0.944890, -1.419060, 0.660670, -1.055000,
0.206170, -0.901250, 0.639660, -0.656230, 1.173730, -0.580930, -0.918140, -0.272970, 5.387830, 0.316240,
-0.848090, 2.714410, -2.064000, -1.277480, 0.280590, -0.501770, -0.469760, 0.259830, -0.063570, -0.214290,

-1.093960, 0.825000, -0.966550, 0.500490, -1.094160, 0.201640, -1.311840, -2.015190, -1.269430, 0.086060,
1.076080, 0.533240, -1.807320, -1.279610, -1.142100, 0.237040, -0.612530, 0.123300, -0.581990, 1.887010,
0.103360, 0.127060, -0.595160, -0.197310, 0.504680, 0.109560, 0.431460, 0.509020, 0.483740, -0.370710,
0.393080, 1.675930, -0.519900, -0.238830, 0.105970, -2.200840, 0.027890, 0.421620, -1.470710, 1.759560,
0.760390, 2.177800, -0.029010, 1.067020, -2.783540, -0.256710, 0.706490, -2.559450, -0.989640, -0.256660,
3.120830, 1.902410, 0.950440, -4.498040, 1.083000, 1.240320, -3.138100, 0.306180, 0.592570, -0.304890,
-0.246870, 0.141570, -1.626350, 1.060690, 0.997600, -0.427120, 1.315060, -0.282650, -0.733010, -0.794080,
0.891140, -0.753360, 0.533360, 0.362590, -0.831670, 1.145630, 0.599610, -0.160260, 0.238980, 1.549970,
0.951200, 0.800150, -0.463500, 0.535610, -0.023930, -0.094220, -0.895980, 0.460240, 0.481250, -1.126270,
-1.314300, -0.459790, 0.047130, -0.680340, 1.189840, -0.083580, 1.537620, -1.078680, 2.752680, 0.565390,
-0.998050, 0.729310, -1.629140, -2.365670, -2.193000, -5.327590, -3.604000, -0.681910, 2.378030, -0.304270,
0.340630, 0.265200, 0.396350, 0.242410, -0.246460, 0.199980, -1.296790, 0.156410, -1.110790, 1.092510,
-0.472080, 0.158050, -0.579640, -0.030790, 0.986880, 0.537290, -0.819980, -0.786510, 3.748000, 1.470190,
0.003660, -3.264410, 1.355110, 0.578360, -0.564060, 0.304370, 0.014510, 0.701160, 1.021380, -1.474600,

0.661610, -2.268950, 0.021760, 0.387510, 0.116740, 0.325740, 0.008070, -0.158670, -0.174880, -1.075670,
-1.281370, 0.014560, 0.920630, -0.348840, -0.539060, 0.238620, 0.871730, -0.911280, -0.682120, -0.001210,
-0.626710, 1.689700, 1.079680, -0.308620, -0.607240, -0.335160, 0.251930, 0.670940, 1.627910, -1.647860,
-0.374540, -0.814420, 0.533870, 0.825960, 0.019720, -0.588790, 0.036120, -0.483390, 0.577090, -0.334890,
0.325180, 0.133540, -0.052470, -0.781790, 0.211240, -0.796130, 0.355490, 0.020470, -0.422320, -0.335560,
-0.241000, -0.503990, 0.394540, 0.486720, -0.058700, 0.371870, -0.387720, -0.192510, 0.297950, -0.278590,

0.650290, 1.704740, -0.290200, -0.630100, 0.461760, -0.283210, -0.732000, 0.605700, 0.800620, -0.663600,
0.329050, -30.308590, -1.208390, -1.223540, 0.127230, -1.153390, 0.239870, -0.661290, -1.313800, 1.329870,
-0.130490, -0.994030, 1.026940, -0.235850, 0.381010, -1.972440, 1.768230, -0.365710, 0.512620, 1.718720,
1.027720, 1.098700, 1.338770, -2.331330, -1.042670, 0.348350, -0.251400, -0.325560, 0.886320, -0.660710,
0.093070, 0.177460, 0.177390, -1.062370, -0.892720, -0.557330, -9.992810, 0.378130, -1.207660, 0.324500,
0.081870, -3.944970, -0.181600, 0.049360, 0.309900, 0.951040, -0.805190, 0.653260, -0.194760, -0.409570,

0.498300, -0.543100, -1.265460, -0.497930, 1.232740, -0.663790, 0.911410, -0.153880, -0.341770, -0.083120,
-0.091680, -0.274250, 0.472270, 0.186930, 0.431630, 0.776370, 0.664590, 0.660630, 0.407960, -0.736050,
0.582020, -3.239170, 0.870460, 0.025780, 0.406120, -0.171120, 0.603870, 0.216460, 0.576530, -3.051420,
-0.430570, -1.093100, -0.474660, 3.605870, 0.585030, -1.099670, 0.412700, 0.120280, -0.500050, 0.232040,
-1.090130, -0.224360, -0.252720, 0.160850, 0.391480, 0.491450, 8.566340, 0.225630, -0.597230, -0.199520,
-0.136210, -1.466220, 0.062460, -0.053770, 0.055640, -0.892690, -0.043180, 0.195980, -0.035460, -0.246510,

-0.011010, 2.189160, 8.537770, -3.787440, 0.768770, 0.656750, -5.441390, 0.229860, -0.208050, 6.023850,
-6.115360, 4.924250, 0.172700, 0.146700, 0.655210, 0.073610, -0.472700, 2.064870, -0.419480, 3.040820,
0.095870, -0.658710, 6.300710, 1.465760, 0.596580, -9.895240, -38.624199, -0.755200, 2.777970, -244.481735,
-4.987860, 3.379670, -0.872030, -13.642800, -0.396530, 2.982340, -3.114370, -0.759480, -0.496800, -1.460590,
1.473000, 2.832330, 3.044710, 1.515390, -1.373110, 0.409550, -16.188271, -2.035030, 3.836580, -0.542080,
-1.102160, 6.339570, 1.085110, -0.598060, -2.898070, -0.885100, 3.603440, -1.047850, -4.216060, -0.126180,

1.052450, 1.206030, 0.220820, 0.716730, 2.714770, 0.037420, 0.485640, -0.717730, -1.092780, 0.079150,
0.531230, 0.573150, 0.841470, -0.701050, -0.495180, -1.303570, -0.501290, -0.139620, -0.581280, 0.637230,
1.227160, 0.543300, -0.180530, 0.339960, 0.009420, -1.395840, 1.635150, -1.794650, 31.731131, -4.641060,
-4.885350, 3.435840, 0.262640, 18.935579, 1.016020, -0.684790, 1.281800, -0.976310, 0.329310, 0.241790,
-0.980630, 1.366770, -0.938090, 0.873600, -2.394880, 0.071030, 8.342280, 0.959990, -0.826850, 0.786920,
0.603810, -5.371610, 1.589740, -0.491380, -0.320620, 22.804640, 0.639550, 0.984060, -0.863150, -0.450630,

1.813180, 0.747420, -2.853670, 0.919030, -2.582790, -0.050790, -0.491350, 0.287520, 1.940370, -1.644170,
0.591090, 0.496290, 0.139350, -0.508020, -1.167850, -0.701350, -1.060070, -1.191730, -6.863870, 0.449050,
-0.376130, -1.232290, 2.553510, 0.996770, 0.187320, -0.802000, -0.413320, -0.482840, 2.547680, 3.826680,
-2.764300, 1.496090, 1.012460, 1.722180, 0.481680, -1.080110, -0.139400, 0.758300, 0.337790, 0.264640,
-1.309800, -0.584690, 0.223900, 0.977720, -0.053830, -0.429020, 4.720540, -0.055990, 0.287950, -0.746850,
0.486070, 1.658170, 0.979640, 0.165770, 0.876020, 0.614600, 0.362570, -0.440990, -0.671840, -0.245350,

1.470710, 3.109310, -0.202950, 1.066810, -4694.728027, -0.386000, -0.402710, 0.310090, 0.691270, -0.399730,
0.044120, -0.644330, 0.676650, 0.945510, -0.656030, 0.404020, -0.372530, -1.782790, 0.184260, 1.603410,
-0.728360, -0.424620, 0.725680, 0.456410, -0.297950, -0.874630, 0.824220, -1.031520, -21.955530, -0.664140,
6.238820, 0.659010, -1.003590, -4.847350, -0.751040, 1.049540, 0.393130, 0.356690, 0.419210, -0.072050,
-0.019890, -0.329890, -0.344430, -4.338400, 0.055270, 0.779650, 210.542160, -0.131490, 2.302950, -0.654750,
-0.077290, -4.778170, 0.123560, 0.466050, -0.115900, -0.155290, -4.407740, 0.240130, -1.163020, 0.153450,

-0.492300, -0.867520, -5.772370, 0.945050, -0.464450, 0.813280, -1.010350, -0.506270, 0.419540, -0.687180,
-0.820740, -2.201080, -0.183440, -0.415770, -0.840860, -2.483340, 0.844050, 0.577030, 1.423650, -0.462190,
-0.791110, -6.010070, -3.599980, -0.678000, -0.707960, -0.177190, 0.056250, -0.753520, -4.264710, -4.282590,
13.201230, -1.324520, 0.020130, -1.133320, -0.215370, 1.394950, 0.130150, 0.885730, -0.424510, -0.018490,
-0.013230, 1.161880, 0.565790, 0.566830, -0.260000, 0.840040, 16.740669, -0.036740, -0.665810, 1.096700,
0.546170, 4.818620, -0.717070, 0.438280, 0.582310, -3.048810, 0.480600, -0.783040, -0.113930, 0.619640,

0.483750, -2.284150, -1.384580, -0.635110, -0.089340, 1.001010, -0.492410, 0.019920, -0.704840, 1.013820,
-0.335220, 0.670170, -0.282470, -0.674570, 0.679510, 0.788820, -0.197110, -0.734200, -0.297280, -1.712640,
-0.660610, -0.556100, -0.762760, -1.205110, -0.883560, 1.026200, -0.083050, 0.586930, 12.585790, 15.341030,
0.630500, 4.850950, 0.966930, 0.488090, 0.964280, -0.442030, -0.714320, -0.596420, 0.187100, -1.016770,
-0.107540, 2.886400, 0.229950, -0.408400, -0.367930, 0.293970, -2.416130, -0.505770, -0.233510, -0.208130,
0.584390, 8.172000, 1.071240, 0.807490, -0.702950, 0.182090, -0.200130, 0.994160, 0.653100, -0.945270,

-1.770600, -2.075720, -2.518710, 1.225240, 0.360100, -0.211760, 0.115080, 0.680910, 1.468370, -1.615830,
1.742250, -0.963270, 0.963150, -0.099220, -1.616810, -1.092320, -0.177410, 1.422890, -0.785630, -1.420060,
-0.521880, -1.024230, -1.775540, -0.013610, 0.046730, 0.673070, -0.446360, 1.165570, -0.089680, 27.896690,
-0.980010, 4.951650, 0.795590, 5.559830, -0.906960, -0.601670, 0.775900, -0.991870, 0.150060, 0.187730,
1.140580, 1.729090, 1.178930, 0.393660, -0.166410, 0.120080, -1.651310, -0.140640, -0.467790, -0.396000,
0.873810, -0.928770, -0.742490, -0.699510, 0.119630, 1.330020, 0.195790, -0.139350, 0.269920, 0.579770,

-0.489240, 2.393700, -0.230480, 0.071080, 0.295540, 0.120250, -0.931770, 0.873470, -3.056970, -0.708070,
-0.588640, -1.091010, -0.449380, 0.671790, -0.287930, -2.717050, 0.229380, -0.330900, 0.138800, -0.075740,
-0.729240, 0.470950, 2.815970, 0.396770, -0.503590, 0.174350, -0.246180, -0.929240, -93.803551, 0.656390,
0.740700, -2.876970, 0.895140, 0.082900, -0.585930, 0.184410, -2.252380, -0.270470, 0.653820, -0.558400,
1.194090, -0.472230, 0.459490, -0.046980, -0.135990, 0.083560, -1.917140, -0.203270, -1.007460, 0.240210,
-0.572060, -3.577950, 0.527040, 0.680250, 2.203100, -0.546550, -0.036380, -0.277760, 1.043270, 0.852900,

-0.610080, 0.987970, 0.570000, -0.514850, -0.418280, 0.771070, 0.682790, -0.178330, 1.057210, -0.191960,
1.393470, 0.336790, -0.253630, 0.099860, -0.589810, -0.502450, 0.141930, -0.616330, -0.330940, 0.380300,
-0.305740, -1.977040, 0.112500, -0.076500, -0.580750, 0.091420, -2.140360, -0.175650, 12.280120, -1.400150,
-0.113510, 1.281770, -0.583430, 1.960580, -0.103020, -0.435160, -0.526170, -0.075870, -0.878000, 0.280550,
2.116670, 0.165740, 0.681420, -1.923800, 1.601450, 0.085670, -1.364970, 0.191170, -2.401370, -0.063520,
-0.633230, -1.975400, -0.911110, 0.704860, -0.443110, 1.678730, -0.459320, 0.277320, 0.182290, -0.567750,

-0.370640, -0.245930, -0.230400, -0.060660, 0.120140, -0.589160, -0.435300, 0.717990, 0.965260, 0.481500,
0.452710, 0.477850, -0.346750, 0.122240, 0.379750, -0.362210, -0.476040, -0.433660, 0.977360, 0.029970,
0.173750, 1.080120, -0.021950, -0.220880, -1.036470, 0.176230, -0.521020, 1.177330, 0.140970, 1.678100,
-0.132670, 0.105920, -0.627230, -0.754150, -0.686370, -0.424900, 1.412610, -0.648880, 1.055730, 0.827050,
-2.043490, -0.446360, -0.124540, -0.752520, 0.094820, -0.411430, -6.577850, 0.788730, -1.976070, -0.553710,
0.073710, -3.423780, 0.301170, 0.388360, -0.610350, 1.876290, -0.988210, 0.369170, -0.075200, 0.569420,

0.589890, -0.796380, -24.462540, -0.630950, 0.418960, -0.446970, -1.007480, -1.271660, 0.298830, -0.888030,
-2.585920, -1.325190, 0.525220, 0.002130, -0.055540, -1.093290, 0.302510, 0.893200, 0.233140, -2.051270,
-0.644310, -2.945800, -0.410850, 1.817710, -0.744250, 0.250880, -0.809010, 0.473920, 17.530100, -7.396250,
1.268870, -8.971300, -0.283480, -5.477740, 0.296740, 2.497250, -0.543820, 0.272720, -0.085340, 0.355830,
-0.141990, 0.288880, -1.398910, 0.167800, 0.512360, 0.484040, 16.937929, -0.506540, 0.139830, -0.459440,
0.645880, 3.513610, 1.243070, 0.365630, -1.273340, -11.314350, 0.073030, 0.262800, -0.786910, 0.031220,

-1.166760, -1.589160, -2.357800, 0.424410, 0.326800, -0.815640, 0.036550, -0.476190, 1.763490, 0.090810,
0.662680, 0.467500, 0.167980, -0.084670, -0.818340, -0.177910, 0.673980, 0.488300, 0.493130, -0.662490,
1.018050, 0.516480, -2.606690, -0.129330, 0.469760, 0.649830, 0.195530, 0.094640, -0.906330, -0.418020,
0.998600, 0.784580, 0.319130, 1.246780, -0.322830, -1.065500, -0.137810, -0.046890, 0.053480, -0.610760,
-0.430100, 1.054420, 0.133410, 0.446800, 1.159890, -0.587370, 9.552720, -0.152900, 0.541480, -0.651220,
0.994270, 4.953250, -0.378220, -0.328650, -0.536440, -1.103600, 0.360520, -0.002930, 0.248150, -1.152610,

-1.063400, 5.631430, 0.967340, 0.596030, 0.814870, 0.823570, 0.444270, -0.842780, -0.018340, 0.757010,
-0.115560, 0.071660, 0.851650, 0.046610, -0.194210, -0.716960, 1.169890, 0.328260, 1.443050, 1.158530,
-1.379830, 6.073790, -0.575850, 1.428550, -0.761350, -1.677350, 1.582970, -0.806080, -0.872280, -4.408690,
-2.166160, 35.615120, 0.709310, -1.086310, -0.361700, 0.294620, -1.977600, 0.991360, -0.371550, 0.629810,
1.361310, -1.520870, 0.520200, 1.026000, 0.471070, 0.544620, -0.200540, 0.617760, 0.068680, 0.270660,
-0.147170, -2.706220, -0.825770, -0.427880, -2.149360, 1.629430, 0.055470, -0.135500, -0.214950, -0.387370,

-0.828410, -9.835940, -17781.669922, -1.324470, -0.131010, 0.459380, -0.185350, -1.758320, 0.746960, -1.223410,
-2.648800, -1.098850, 1.366640, 0.944840, -20.114180, -2.653140, -0.949570, -0.058990, 6.231130, 1.780550,
-6.111660, -9.181240, -33.102009, 4.077050, 0.669880, 0.450140, 1.692070, 0.827220, -0.379160, 17.122530,
1.569380, 11.501670, -1.038910, -2.687540, 0.000050, 0.255800, 7.507760, 1.043910, -0.506150, 0.001380,
-0.228800, -1.225970, -1.843760, 0.723450, -0.787590, 0.391590, -17.281191, -0.120140, 0.514330, -0.541450,
0.617200, -1.274180, 0.979060, -0.358290, -0.550940, -0.809120, -0.436650, -0.274440, 0.495640, 1.425030,

-0.062260, 2.305510, -0.331380, -0.598590, -0.517290, 0.236900, 0.412770, 0.822440, 0.721980, 0.071190,
-1.346230, 1.314850, -0.396300, 0.778950, -0.231200, 0.619370, 0.840900, -0.403060, 2.107290, 0.175500,
0.467370, -4.252460, -0.825690, -0.200370, 0.687380, 1.685400, 0.170480, -0.351360, -0.278580, -1.192540,
3.309640, 2.040530, 0.863150, -0.060590, -0.958500, -0.274480, 0.166980, 0.439110, 0.484120, -0.431070,
-0.317890, 0.150600, -0.162930, -0.348920, -1.158740, -0.114460, -4.739750, -0.512570, -0.612060, -0.277240,
0.376000, 0.659440, 0.199460, 0.692720, -0.096890, -0.802130, 0.084880, -0.866860, -0.789280, 0.454840,

-0.218070, -2.666010, -8.559930, 0.836790, 0.672590, -0.797540, 0.179590, -0.394820, -0.199900, -0.097120,
-1.411990, 0.579980, -0.477240, 0.671890, -0.601450, -0.653110, -0.870160, -0.251890, 0.903410, 0.273290,
0.461890, 1.248490, -2.412520, -0.287850, 0.270330, -0.012550, 0.440640, 0.001880, -1.848690, 0.570300,
6.588060, -1.478050, -0.212620, -0.008520, 0.843590, 0.675860, 0.532720, 0.716070, -1.061710, 0.559440,
-0.532840, -0.559060, -0.293850, -0.035580, -0.194680, -0.027210, 8.353020, -1.742100, -0.268270, -0.287740,
0.791140, 2.779230, -0.752240, 0.258930, -0.634720, -1.166640, 0.557140, -0.529380, 0.204720, -1.283360,

-1.968420, -2.931890, -3.176460, 0.346190, -0.538160, -0.267660, -0.031980, 0.152840, 1.709300, 0.339850,
-2.141680, -2.563290, 0.736350, 0.972270, -1.262750, -0.974290, 0.420880, -0.636880, 0.232420, -0.783500,
0.304710, -8.606710, -1.170840, -1.571190, 0.825120, 0.363950, 0.866590, 0.117060, 2.196910, -2.067260,
-0.632580, 1.534920, -0.396810, -5.811040, 0.060010, 1.345200, -1.198740, 1.140710, -0.650680, 2.798390,
0.467130, 0.777070, -0.404290, -0.819070, 2.101520, -0.748170, -1.573590, -0.163200, 1.985770, 0.849710,
-0.372160, 0.044270, -0.604740, -0.763440, 1.415900, 1.311540, -0.396090, -0.198810, 0.284200, 0.778730,

-0.261200, -1.046100, -0.896950, -0.058910, -0.374640, -0.092750, -0.140130, 0.388460, 0.229860, 0.341160,
-0.448590, -1.088980, -0.574160, 0.155230, 0.412010, 0.270980, -0.207150, -0.182620, -0.859870, -0.895820,
-0.311900, -3.132370, 2.018230, -0.392030, 0.367940, 0.529740, 0.225410, 0.605310, -4.124070, 1.525730,
-0.969760, -1.370440, -0.845950, 1.204150, -0.580760, -0.000320, -0.845750, 0.423760, -1.090060, 0.432950,
-0.207030, 0.812510, 0.149380, -0.959060, 1.818220, 0.346780, -14.119000, -0.203440, 2.249250, -0.471280,
-0.152480, 1.775120, -0.046790, 0.746570, -0.442720, -1.426810, 0.543080, 1.367190, 0.826880, 0.293540,

1.138090, 0.315830, -4.394880, 1.531970, -0.648390, -0.149520, -0.694180, -2.845880, 0.202220, -0.682770,
1.558800, -1.758620, 0.729680, -2.369060, 0.384140, 0.010680, 0.257510, -0.257910, -0.005620, -0.928790,
0.465990, 5.513850, 0.043650, -17.619631, 0.841170, 0.518480, -0.622030, 0.279660, 2.725470, 0.829400,
-0.601520, -1.849400, -0.984400, -2.957200, -0.056050, 1.174560, -0.457290, 0.031170, -0.592880, -0.273000,
-1.138010, -0.343520, -1.056030, -0.099140, 0.505660, 0.107420, 3.095680, -0.570150, 0.391880, -0.080860,
-0.467730, 0.550220, -0.565580, 0.944090, 1.120000, -4.881030, 0.132200, -0.471480, -0.606840, 0.851030,

-0.500060, 0.672160, 1.178370, 0.409100, 0.812670, -0.714190, 0.122470, 0.759820, 1.349970, -1.473280,
0.148810, -0.719340, -0.167530, -0.859020, 0.008380, -0.033630, 0.808190, 0.366790, 0.772500, -0.184180,
-0.817610, 3.350870, 0.942350, -0.222600, 0.253940, -0.188170, -0.083860, -0.682960, -4.261000, -5.422730,
0.043960, 3.189530, 0.067600, -6.000590, -0.684330, 0.570820, 3.259590, 0.533780, -0.126040, 0.828610,
-1.307750, -1.527090, -0.348530, 0.329220, 0.534070, -0.759170, 4.375910, 0.600200, 2.037750, 0.903810,
0.602250, 1.699940, -0.414420, -0.036420, -0.467880, 3.336670, -0.229770, 0.657390, -2.093500, -0.113910,

0.034060, 0.642900, -0.670130, -0.491540, -0.175750, 0.093230, 0.355750, 0.087730, 0.499480, -0.290180,
-0.247780, -0.926860, 0.137520, 0.925660, -0.367880, 0.229950, 0.423680, 0.029600, 0.378080, -0.615230,
-0.739170, -2.243860, 2.146850, 0.194870, 0.426840, -0.402870, -0.335500, 1.041690, -3.050110, -3.277200,
-4.031290, -1.685200, 0.286610, 0.848990, 0.621030, -0.403040, 0.508890, 0.517490, -0.218410, 0.861320,
-1.012480, -0.543300, -0.180560, 0.475830, 0.687850, -0.444580, 94.600502, 1.609790, 3.443950, 0.000340,
-0.769260, 0.273860, -0.672820, 0.414540, -0.099230, -0.670910, -0.184980, 0.053570, -0.781610, -0.264270,

-0.035970, 0.946880, 1.264490, -0.063430, -0.938450, -0.723260, -0.817080, -0.329240, 0.578020, -0.165960,
0.558380, 0.645970, -0.591390, 0.630620, -0.210280, 0.282260, 0.223150, -0.019650, 1.430420, 0.932880,
0.250590, -4.370120, 0.458140, -1.207180, -0.978820, 0.131060, 0.848540, -0.645250, 5.669460, 1.887140,
-8.791540, 1.796280, 0.144520, -4.484950, -0.146970, 0.731710, -0.470200, 0.969630, -0.156110, -0.737090,
-0.110040, -0.109250, 1.025970, 0.724690, -0.359790, -0.620550, 13.177020, -0.072680, 1.881700, 0.195250,
-0.882180, -0.276450, 0.516940, -0.562760, 0.034380, 0.833250, 0.807680, 0.111860, 0.144040, 0.734480,

0.170840, -1.218570, 1.059450, 0.604220, -22.293020, -0.583800, -0.240600, 0.581970, -0.930670, -0.110700,
1.573900, -0.298770, -2.078730, 0.360620, 0.409160, 0.618690, -2.290930, -1.681240, -0.533430, -0.738570,
-0.564370, -7.371480, 0.845820, -0.418180, 0.789420, 0.865360, -0.786840, 0.530790, -50.159149, 2.102720,
-1.325490, 0.579650, -0.360400, 2.363500, 0.512660, 0.242530, 1.687590, -0.439790, -0.755800, -0.526800,
0.649330, -0.681130, -0.215130, 0.130120, 1.117400, 0.064650, -10.272030, -0.220490, 4.233590, 1.179460,
-0.492690, 0.855030, 0.043650, -0.825880, -0.001290, -0.096030, 0.123270, -0.033480, 0.414730, 0.761660,

-1.550880, -5.353280, -1.057300, 1.211260, 0.784090, 0.098240, -0.515140, -0.840230, -0.166300, -0.007560,
-0.340990, 2.841400, 1.091210, 1.082700, -0.577290, 0.402980, 0.416200, -0.816400, -3.759630, -0.598340,
-0.475070, 28.363310, -6.454540, -0.229540, 0.402600, 0.338460, -1.115370, 1.045420, 9.750270, -0.924500,
2.947990, -3.773110, -0.664070, -10.583150, -0.378620, 0.497090, 0.211720, 0.126350, -0.747770, -0.488920,
-0.604580, -1.042630, -0.022270, 0.455250, -0.410730, 1.045580, 0.218120, 0.284510, -0.335950, -0.789870,
0.506490, 2.628260, -0.566220, -0.452760, -0.228600, -0.171650, -0.270030, 1.067660, -0.431600, -0.608580,

0.255300, -1.109830, -1.168900, -0.132530, -0.021250, -0.006100, 0.025520, -0.008720, -0.216770, -0.306780,
-0.493690, -0.831000, 0.007710, 0.501010, 0.523620, 0.330690, 0.030200, -0.046040, -0.955860, -0.295580,
-0.586420, -2.573020, 0.841950, -0.280090, 0.429390, -0.445310, 0.167150, 0.173760, -3.790480, -0.739670,
-1.793870, -0.526260, 0.026020, 1.509630, 0.541810, -0.369880, 0.834490, -0.419230, 0.049050, 0.205450,
0.008940, -0.193710, 0.009000, 0.724820, 0.224000, -0.065680, -6.665550, 0.761450, 2.384320, 0.200110,
-0.353560, 1.163500, 0.269610, -0.377780, 0.683820, -0.971560, 0.480750, -0.504680, 0.613280, 0.401600,

-0.329100, 1.226890, -0.454660, -1.096760, 0.081660, -0.131830, 1.311320, -0.137000, -0.147810, 0.693100,
-0.320590, 0.944040, 0.185160, -0.071250, -0.606090, -0.027700, -0.692890, -0.447480, 0.546300, 0.668970,
0.602380, -0.722690, -6.643640, 0.725630, -0.065620, 1.023560, -0.390780, 1.196490, -0.544890, -0.923600,
-3.779470, 0.824440, 0.531430, 1.302770, -0.755030, -0.212000, 0.115130, 0.649130, 0.122540, -1.150960,
0.987900, 0.350530, 0.868040, -1.295970, 1.450620, 0.605200, 3.800310, -0.979170, 0.455520, 0.028150,
-0.950870, 1.353960, -0.187090, 0.445450, 0.029040, -1.186680, -0.687270, -0.079930, -0.177840, -0.516880,

0.947550, 1.214520, -2.496580, -0.500210, -0.244380, 0.414860, 0.244860, 0.530370, -0.248150, 0.122230,
-0.173220, -0.195940, -0.010250, -0.336620, 0.518560, 0.427770, -0.959310, -0.056480, 0.211800, 0.433160,
0.011290, -1.175460, 2.455810, 0.555540, 0.142160, -0.315100, 0.006230, 0.020330, 1.421380, -0.407740,
2.673110, 1.962190, -0.736800, 3.639530, -0.175800, 0.336560, 0.042560, -0.510050, -0.834090, 1.042770,
0.878180, -0.521210, 0.127590, -1.051440, 0.080510, -0.345790, -5.288640, -0.699710, -0.644630, 0.383380,
0.192890, -5.766980, -0.460890, 1.886450, -0.310690, -2.257250, -0.758960, 0.506390, 0.471380, -0.237380,

-3.226250, -1.302770, 0.891670, -3.571390, -0.203790, 0.759150, -1.346610, 0.350520, -0.696080, -0.723720,
-0.335960, -1.735440, -1.091280, 0.771410, 0.230560, 0.468070, 5.485570, -0.656310, -0.046000, -0.220610,
0.609440, 2.649160, 0.657950, 0.003780, 0.853040, -3.429880, 0.660810, -0.957870, -0.129460, -0.980050,

1.112980, 0.376250, 0.450460, -3.171360, -0.893450, 0.279280, 0.543310, -0.328340, -0.930490, 0.484950,
-0.905860, -0.585590, 1.225950, -0.771170, -2.218500, -0.639230, -6.077770, 0.876530, -1.247760, 1.013860,
-0.854490, -2.015470, 0.697430, -0.411860, 0.825670, 1.494500, -0.060480, -0.517340, -0.627860, -0.148400,

1.956680, 0.144540, 1.316740, 3.641700, -1.021530, -0.520130, -0.577290, 0.454090, 0.464910, 0.012800,
0.478110, 1.466660, -0.098030, -1.012840, 0.395290, 0.735670, -3.453770, -0.131930, -0.088730, -0.724650,
0.829410, -1.685510, -0.910450, -0.371540, -1.266670, -0.328890, -0.296960, -1.011530, 0.185670, 0.797910,

-1.376970, -2.793390, -0.381990, -3.382600, 0.646930, 0.853310, -1.529220, 0.792820, -0.176700, -0.357700,
-0.968170, -0.959510, -0.971630, 1.002790, 0.680190, -0.372200, 6.179790, 0.094140, 1.195030, 0.090230,
-0.394560, 3.149670, 0.415730, -0.587430, 0.418630, -3.302770, 0.987640, 0.331170, -0.960560, 0.516680,

-0.952110, 1.378900, -0.772400, -2.854560, 0.092870, 0.389250, 1.095540, -0.223740, 0.535380, 0.830940,
-1.048190, -1.089480, -0.329030, -0.739120, -1.509710, -0.633850, -6.362230, 0.216900, -2.692630, 0.656190,
-0.458770, -3.538300, 0.516310, -0.282370, 0.277240, 1.554200, -0.432990, -1.157550, -0.797790, 0.718730,

1.323480, -0.686010, 0.207540, 3.175070, -0.254200, -0.836040, -1.212890, -0.086840, 0.227660, -0.384720,
1.109630, 1.037710, 0.483560, -1.087180, 0.690090, -0.557240, -5.183540, -0.242810, -1.651300, -0.425240,
-0.282810, -1.798310, -0.657140, 0.773270, -0.775370, -1.135040, -0.463260, 0.633650, 0.871820, 0.005090,

4.397630, -3.912210, -0.670590, -1.923900, 0.381380, 0.882710, -0.808730, 0.617690, -1.039310, 0.710230,
-1.326450, -1.167290, -0.795290, 0.981200, -0.453570, 0.595020, 5.968210, -0.873210, 0.933370, 0.370860,
0.718070, 3.330360, 0.138700, -1.207700, -0.327960, -3.224090, 1.068060, -0.169760, -0.677180, -0.509950,

-0.986890, 2.505240, 0.184370, -1.239310, -0.859020, 0.672230, 0.973730, 0.221270, -0.382220, 0.573470,
-0.639580, -0.224470, -0.267040, -0.527520, -1.687730, -0.621460, -5.712940, -0.804910, -2.487440, -0.087670,
0.741330, -4.095330, 0.324750, -0.658360, 0.050630, 1.130260, -1.028950, 0.509500, -1.088460, 0.593870,

-2.836160, -2.214550, 1.092460, 1.603790, -0.167910, -1.064310, -0.770830, -0.373940, -0.639350, -0.889030,
0.980190, 0.824360, 0.943790, -0.783440, 0.816460, -0.717220, -5.281030, 1.030130, -1.334730, -0.002680,
-0.396710, -1.914960, -0.440710, -0.181360, 0.145550, -0.987800, -0.762870, 0.225590, 1.071270, -0.424480,

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
      0.0, 0.207070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.680970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.293330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.106830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.362610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.772860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.968830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.168180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.681260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.232570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.382010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.882280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.799710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.672910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.681860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.066130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.208290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.165400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.460060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.219040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.413200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.484750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.402950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.848920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.190030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.714760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.883940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.325660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.692950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.994490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.075240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.065190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.575750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.468780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.965500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.386430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.201710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.217430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.575120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.771790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.390690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.696280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.324680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.225050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.287220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.507110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.207230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.063260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.081280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.304980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.345640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.892740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.263920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.887780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.985140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.033200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.454460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.951400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.183910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.590070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.755390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.881260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.478310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.394340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.782990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.003600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.420050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.427170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.729850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.351080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.083020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.919270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.549350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.246900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.542720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.290930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.399360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.339530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.437930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.131910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.648930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.218780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.637530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.688020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.639060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.886790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.150230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.041330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.868710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.827020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.765170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.522730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.202150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.376510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.523100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.189980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.749500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.030730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.555070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.746240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.057640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.997170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.721030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.962610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.629780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.514230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.370860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.931470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.871120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.618860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (hid11) */
      0.0, -0.081570, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, 0.125940, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, -0.235190, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, -0.564560, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.592660, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 208.606216, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, 0.794400, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, -0.171480, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, 0.243780, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.491380, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, 1.019980, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.520580, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.880190, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.866350, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.522470, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 0.567850, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.586930, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.280270, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, -1.003810, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 0.270530, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.343500, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, 0.298730, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.722300, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, 0.320690, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, 102.402657, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, -0.321120, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.657880, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 0.514960, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.590320, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -0.928100, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, -0.253010, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.340930, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, 0.442230, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.232530, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.208360, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.414530, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.429990, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.708090, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.999190, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, 0.957440, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.941610, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.557320, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, -0.227600, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.939850, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.600830, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, -0.190460, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, -0.931350, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, -0.686810, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.324810, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.507060, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.894340, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 0.633190, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -1.082600, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, -0.315080, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, -0.306540, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.900130, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.559950, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, 0.650580, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.518700, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.326210, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, 0.709570, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.575370, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, -0.746570, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, -0.990380, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, 0.318150, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, 0.266980, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.184680, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, 0.597030, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.999300, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.27590, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.02146, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.00000, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
0.84944, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
1.34301, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
1.42857, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
1.42562, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.29395, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.52605, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
1.37891, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.18333, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.10995, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
1.42849, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.42284, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
0.37393, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.06773, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
1.42316, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
1.42857, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.02507, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
0.53062, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
1.18463, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
0.00785, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.17272, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.00033, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.42857, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.19763, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.81876, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
0.16513, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.00060, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.00312, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.04111, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.00560, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
1.41014, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.00080, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
1.42391, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
0.26439, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.00000, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
1.32986, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
1.33865, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.67462, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
0.36243, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
0.00543, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
0.01906, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.22900, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
1.16116, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
1.41899, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.00347, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.98429, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
0.30889, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
1.42748, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
1.40671, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.00829, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.24268, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
1.42556, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.28309, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.00000, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
0.23203, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
1.40195, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.38991, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.38323, 0.500000, 2,
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
