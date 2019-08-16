/*********************************************************
  EL_4.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:14:17 2004
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
0.362860, 0.394700, 0.241880, 0.233950, 1.344700, 0.506200, 0.786850, -0.338220, -0.001820, 0.067500,
-0.289900, -0.675300, -0.108380, 0.584000, 0.083030, 0.283460, -0.222150, 0.407070, -0.945830, 0.144780,
0.485450, 0.858800, -0.057640, 0.765380, -0.328330, -0.157350, -0.005980, 0.892790, 1.098010, -0.500490,
0.288700, -1.459500, -0.285890, -0.550450, 0.001490, 0.077950, -0.469840, -2.086760, -0.019680, 0.065090,
-0.432340, -0.702790, 0.133650, 0.297190, -0.638510, 0.750800, 1.947560, 0.443980, -0.338570, 1.300680,
-0.032460, 0.714350, 0.889640, -1.247530, 0.264080, -0.298410, 2.703020, -0.509670, 0.931020, 0.256290,
0.815660, -0.357540, 0.365570, 0.580570, 2.421080, -1.166140, 0.059450, 1.101570, -0.162790, -0.230090,
-1.459060, 0.291350, -1.517680, -0.527840, -0.825570, -0.113150, 0.752990, -1.094430, -0.178070, -0.326180,
-0.036110, -0.843330, 0.159740, -0.639180, 0.296150, -0.223120, -0.175610, -1.455940, 0.375660, -0.074450,
-0.174300, -1.346480, -1.023750, 1.018870, -1.244150, 0.564500, -0.582400, 1.039610, 0.073630, 1.529090,
1.536330, 0.715670, -1.147860, -7.704820, 2.787800, 3.804270, -11.718050, -8.910150, 3.324310, 0.071770,
0.662620, -1.439950, -1.517230, 0.434080, 0.617160, -1.255220, 0.456500, 1.839760, -0.549220, -0.685220,
-0.526060, 0.431270, 0.409100, 0.184910, 0.485320, -0.461520, -0.403510, 0.505050, -0.863560, -0.146980,
0.171290, -0.548540, 0.054020, 0.253570, 0.301600, -0.075490, 0.711970, -0.477730, -2.118300, -5.712610,

0.013280, -1.186910, 0.330540, -0.312670, -0.674430, -0.897450, -0.377680, -0.094720, -0.485100, -0.923560,
0.989280, 0.620410, 0.381590, -0.064460, -0.022300, -0.120580, -0.523090, 0.640600, -0.157140, 0.342100,
0.356440, -0.073830, -0.259400, -1.166470, -0.842730, -0.669980, 0.547910, -0.531320, -0.249390, -0.783940,
-0.408590, -1.259300, -0.061670, -3.359830, 0.822270, -0.284930, 1.713250, -1.496930, 0.096950, -2.846980,
0.159720, 0.286110, -4.822250, -0.234890, 0.764800, -1.561350, -0.499110, -1.049020, -2.733940, -1.658250,
0.031630, -6.273630, 0.758330, 0.649520, 5.978390, -0.993330, -0.852190, -15.137140, -0.089340, -0.597850,
1.736290, -0.295050, -0.032220, -10.024420, 0.443070, -0.500530, 0.213670, 0.044470, -0.051720, 1.273030,
-0.397990, 0.854530, 0.866320, -0.577360, 0.426030, -2.408900, -0.747370, -0.620450, 0.262080, 0.148750,
-0.811120, 0.352670, -0.104090, -1.067470, -0.731650, 0.809430, 1.341300, 0.766860, 0.800570, 0.640230,
1.028460, 0.390110, -0.231070, -0.590050, -0.775320, -0.198550, 1.132000, 0.079450, -0.110160, -0.668710,
0.699140, -2.293470, 1.672320, 1.392960, 1.806940, 4.620480, -1.059160, 3.157480, 1.392390, -1.049600,
0.876610, -1.272740, -1.169700, -1.195280, -1.860120, -0.051810, 0.348010, -1.138940, 0.488990, 0.451300,
-0.306970, 0.167330, 0.865860, -0.306550, 0.304180, -0.223040, 0.626100, -0.755810, 0.101920, 0.774020,
0.448440, -0.208340, 0.074380, -0.431540, 0.454820, -0.062420, 0.886910, -1.436690, 4.859340, 1.009230,

-0.440490, 0.321300, 0.355230, 0.305760, -0.673490, -0.860640, -0.689740, -2.118410, 0.043970, 0.622740,
-1.424570, 0.046250, -0.018750, -3.452800, 0.560000, -0.110540, -0.037740, -0.324710, 0.693510, 2.370710,
-0.719090, 0.765470, -1.173300, 0.234490, -0.373140, 2.999960, 0.158770, -0.235020, -0.267220, 0.634650,
0.578100, 0.461530, 0.398740, -1.138810, -2.272920, -0.133760, 0.592560, 2.379970, 0.871400, 2.186970,
-1.946510, -0.328650, -0.021290, -0.223780, 1.132550, -2.218460, -2.075400, -0.301120, -0.164020, 0.693440,
-0.749450, 0.926520, -0.287880, -0.192670, -0.263430, -0.002500, 0.186430, -0.993260, 0.234600, -0.633090,
1.278920, 1.401230, 1.649650, -0.015380, 0.225810, 0.455860, -0.653170, -0.914360, -0.101220, 1.176550,
-1.029960, 0.667300, -1.747080, -0.559670, 0.195840, -0.599340, -1.057930, -0.496120, -0.536420, 0.833380,
-0.912010, 0.845560, -0.613290, -0.366380, -0.597510, 0.172030, -0.763690, 0.416130, 0.051280, 0.441650,
0.782180, -0.058270, 0.205740, -0.589260, -1.077590, -0.430430, -0.124310, -0.607250, 0.261880, -2.812180,
-1.016700, 6.113420, 4.669740, -5.815470, 3.995790, -10.605220, 1.673550, -0.447380, 1.150160, -0.249570,
0.513130, -0.033540, -0.634990, 0.906760, 0.247630, 0.823010, 0.250250, -0.887540, -0.661460, 0.126910,
4.608700, -0.154150, 0.230050, 0.039320, -0.499620, 0.481810, 0.870950, 1.278140, 0.027080, 0.379210,
-0.198000, 0.310060, -0.107980, -0.567800, -0.084240, -0.613960, -0.312430, -0.861320, 1.745820, -10.361400,

-0.151770, -3.015700, -0.154100, -0.316780, 1.124620, 0.447240, -0.023220, -0.857740, -0.006220, -2.144890,
0.266330, -0.966110, -0.379740, -1.655980, 0.477520, -0.217200, -1.449460, 0.285320, -0.021990, 0.255050,
-0.934810, 0.958690, 0.738240, -0.376080, 0.033540, -2.036140, 0.369740, -0.889980, 0.132490, -0.189030,
-0.544180, 0.527870, 0.327400, 0.140530, 0.476010, 0.186300, 0.226660, 0.055510, -0.996400, 0.006880,
-0.837800, 0.819460, 1.415410, 0.039340, 0.467550, 1.816810, 0.054420, -0.788240, -0.285360, 0.748390,
-0.165160, 0.098800, 0.835700, -0.526510, -0.398760, -2.481330, 0.577210, -0.147930, -1.216440, 1.692470,
-0.329630, 2.918740, -1.167660, 0.256360, -3.050310, -1.868780, 0.505910, -1.253190, 2.369920, -0.603930,
7.163850, -4.301510, 0.511940, -1.178670, -1.927480, 0.628290, -0.723900, 1.743350, -0.721150, 9.405220,
-1.180190, 0.065330, -5.332220, -5.518190, 0.941070, 1.707890, 0.615960, -0.561530, 9.939740, -0.111130,
0.807770, -13.456730, 1.802330, 0.719330, -0.176130, 6.970790, 0.897440, -4.263530, -13.775730, 1.921870,
2.948080, 1.093440, -2.908430, -2.094540, 0.099300, 0.876660, -4.286280, -7.732430, -9.185240, -14.016790,
1.107140, -2.082510, -2.141040, 0.728390, -1.394380, 0.732440, 0.544500, 0.753590, -0.330170, 1.412520,
-0.589010, -0.168240, -0.927940, 1.976510, 0.605680, 0.363880, 1.074080, -1.528100, -0.296060, -0.078930,
0.564060, 0.308580, 0.241980, -0.907210, -0.190590, 0.626550, -0.328230, -4.016170, -0.906560, 2.262540,

0.266390, -3.126810, 0.177440, 0.297980, 0.552640, -0.068790, -0.270680, -0.109170, -0.848700, -0.762880,
0.216310, -0.046020, -0.253960, -1.328190, -0.460390, -0.493260, -1.863480, -0.704120, -1.104400, -0.669630,
0.019060, 0.825260, -0.662270, 0.993160, -0.009650, -1.087150, -0.231610, -1.025910, 2.559530, 0.921240,
0.447360, -0.041600, 0.534150, -0.339650, -1.472000, 0.150040, -0.310210, 0.284950, -0.272030, -0.413990,
1.759530, -0.605150, 1.091460, -1.070970, -0.682090, -0.736450, -1.967210, 0.363090, 0.810350, -0.921820,
-0.204200, -2.170820, -1.759080, 0.476980, 1.263680, -2.014220, -0.892970, 0.556550, -2.578080, -0.376700,
1.324170, 0.025780, 0.866360, -2.188420, -1.276290, 0.636270, 0.171180, -2.225060, 0.285420, 1.146170,
1.922680, 0.275290, -1.132490, -0.917440, -0.204130, 2.548460, -1.016250, -0.262050, -0.249580, 0.015320,
-0.860850, -3.237230, 0.220010, 0.833110, -0.004260, 0.723220, -0.962440, -0.061900, -0.599770, -0.430280,
-1.069390, -0.790250, 0.971260, 0.101790, -0.203240, -0.208490, 1.700020, -2.429040, -0.641030, -1.109280,
-0.322730, 1.735340, -0.591800, 0.236640, 6.124490, 3.503300, 0.784910, -2.436750, 1.186340, -0.124830,
0.394450, -2.058310, -2.867110, 0.646600, -0.161870, 0.990050, -0.094310, 1.719870, -1.063790, -0.281620,
3.851860, 0.317230, 0.909180, 0.163180, -0.407060, -2.894300, -0.646760, 2.287490, -0.175580, 0.091110,
-0.334440, 1.165330, 1.140860, 0.245230, 0.914820, 0.078910, -0.826660, -0.531840, 10.869890, -1.609460,

-1.929010, 1.224320, 0.369730, 2.557870, -2.018770, 0.314090, 0.750550, -2.357310, 0.743010, -0.037360,
0.155340, 0.462270, 0.816210, -0.061510, 0.363720, -0.083420, 0.970710, -0.347040, -4.627450, 0.583880,
-1.301610, -3.412600, 0.341090, -0.551050, -0.516610, 0.011270, 0.881440, 0.460550, 0.033500, 0.465020,
-2.096260, 1.338510, 0.122680, -4.033940, -0.161440, 1.471990, -1.531170, 0.074270, -0.130210, -3.513080,
-0.258540, -0.001430, -2.037410, -0.681400, -0.643760, -6.464240, -0.685710, 0.978760, -3.936790, -0.918580,
-0.302450, 2.119140, 0.399230, -0.139750, -1.685360, 0.422150, -0.166880, 0.285960, 0.093140, -0.419360,
0.314120, -1.044630, 0.024970, -2.895880, 2.420870, 0.030950, -0.145480, 1.039680, 0.191430, -0.174020,
-2.175820, -0.811970, -0.391710, 1.669130, -0.740130, 0.669010, -1.321860, 0.246900, -0.026810, 0.411430,
-0.265750, -0.631540, -0.272020, 0.031160, -1.088490, -0.853700, -0.881320, -0.524360, -0.278680, 1.320240,
-2.115160, -0.399180, -1.995590, 0.624300, 0.445390, -0.554190, 1.220090, -2.511580, 0.603200, 1.057710,
-3.252100, 1.265660, -2.988030, 4.607790, -2.359450, 1.817540, -2.793750, 1.563860, -2.050690, 1.145400,
-0.665880, 0.138140, -1.479210, -1.787720, -3.589510, 1.413410, 0.909790, -0.234420, 0.639430, -0.297650,
7.294680, -0.367200, -0.500200, 1.081100, -0.721310, -0.934080, 0.523780, 8.120260, 0.610850, 1.081420,
0.103950, 0.779060, -0.510490, 0.450430, 1.177560, -0.104070, 0.245040, -2.591630, 18.797550, 2.270310,

0.775010, -2.966880, -0.231560, 0.260510, 2.511940, 0.905920, 1.320670, -1.557650, -0.132230, -0.227700,
2.857770, -0.563190, 0.837430, 1.282170, 0.266530, 0.272980, 0.695580, -0.945230, 0.838900, 0.910010,
-0.694880, 0.281130, 0.547470, -0.504880, 0.773470, 0.464880, 1.184560, 0.050040, 2.824920, -0.106890,
0.727390, -0.813360, -1.067340, -0.780710, -1.044440, 1.074690, -0.378380, -0.541740, -0.026610, 0.502720,
-1.043890, 0.075430, -0.224960, -0.116810, 0.793790, -1.143630, -1.913400, -0.537390, 1.013610, -0.966190,
-0.578770, 0.334490, 0.900510, -0.056380, 1.172070, 0.483820, 0.164980, 0.003530, -0.104590, 0.470730,
-0.585490, -0.515540, 0.234800, -1.667400, 0.559950, -0.155640, 0.052580, 0.698610, -0.596520, -0.710040,
-1.268390, 1.056890, -0.673510, -0.242270, 0.349630, -0.697810, 0.506670, -0.241770, -0.063320, 0.618000,
-0.138490, -0.484350, 0.028270, -0.152450, -0.511090, -0.118160, 0.711870, -0.038490, -1.211730, -0.338720,
0.849760, 0.946060, 0.976000, -1.014360, -0.612600, 0.375540, 0.593860, -1.504910, 0.350630, 1.303550,
0.771370, 0.547900, -1.251390, 0.414600, 1.414010, 0.348480, -1.880740, -2.299960, 1.517060, -0.799290,
1.425560, 0.750780, 0.464790, -0.451440, 0.437930, -0.509760, -0.099060, 0.432260, -0.461330, 0.587760,
1.581500, 0.366920, 0.287590, 0.382930, 0.696910, -2.830870, -0.207840, -2.561540, -0.580440, 0.699890,
0.107780, -0.327350, 0.372300, -0.183480, -0.857300, -0.509140, -0.275930, -0.202640, -3.856990, 1.637810,

-0.259870, 3.024230, 0.458730, 0.899510, 0.002490, -1.612720, -1.022010, 0.175750, -0.440270, 0.127400,
1.143200, 0.093030, 0.770760, -0.438750, -1.029130, 0.092850, 0.408400, -0.957980, 0.787380, -2.970770,
-0.578050, 0.041060, 1.259950, -1.245880, 0.606340, -0.606930, -1.693770, -1.212370, -1.839160, 2.320380,
0.395130, 0.035920, -0.721270, -2.426970, 1.526000, -1.278960, 0.763180, -0.012350, -0.135740, 0.344740,
0.599580, 3.476680, 0.887200, 0.065950, -3.186690, -0.635070, 0.751560, -1.221930, -0.511910, -0.650040,
-1.024170, 2.171640, -2.300790, 0.916720, 0.853470, -0.205620, 0.445340, 0.478410, 2.720880, 0.722700,
0.531970, 3.073390, 0.931370, -1.401520, 0.484050, -0.444790, 0.563220, -0.109460, 0.554980, 1.357060,
1.526450, 0.172490, 0.610000, 0.498190, -0.207130, 1.020320, 2.197070, 0.564790, 2.063810, 2.691040,
-0.833550, -0.111880, -1.384140, 0.222430, -0.735940, -6.885940, -0.288110, 0.388120, 4.730510, 0.900190,
-1.480330, -4.195660, 0.222850, -0.388470, 0.565420, -0.091150, 0.001730, -0.075970, 0.524330, 8.261030,
-2.359760, -8.270960, -3.734640, 0.220640, -4.707790, -30.641069, 9.891630, -4.594830, 6.106480, -0.356370,
-3.403320, 2.718530, -0.506610, -0.332400, 0.336480, -1.013600, -0.030050, 0.090080, 1.103320, 0.568790,
-4.112360, -0.424660, -1.315300, -0.098180, -0.414350, -8.209400, -1.459270, 2.706410, 0.276900, -0.040710,
-0.924700, 0.196860, 0.822680, 0.466450, -0.325330, -0.736100, 0.845910, 0.262160, -20.148300, -22.580589,

-0.474920, -4.825330, 0.992090, 0.843030, -2.284870, 1.012300, 0.798660, 7.401450, -0.579160, -0.679490,
5.439530, -1.283190, 0.401960, -2.689840, 0.647180, -0.828430, -1.682630, -0.494780, -0.382100, 1.951050,
0.832950, 0.207950, -5.898630, -0.035260, -0.948980, 9.293490, -0.459550, -0.841520, -0.762840, -0.111920,
1.261030, -5.487730, 0.005800, 1.568800, 17.752640, -0.607780, 0.681710, -7.202100, -0.468660, 0.190990,
-2.551020, -0.321620, 0.397700, 9.058770, -0.948850, -0.851930, -8.134450, -0.198130, -1.313380, -1.696270,
0.260820, 2.433360, 5.303620, -0.737880, -0.228590, -0.613760, 2.239260, -1.327140, -7.181100, -0.097270,
-0.787260, 3.750650, -0.738210, 0.621340, -3.051950, 0.817530, 0.601410, -1.746020, 0.724510, -0.551010,
0.343410, -2.454660, 0.020100, 1.228910, 0.559940, -0.971450, -1.973110, 1.253990, -0.309020, 1.504370,
0.230060, -0.017330, -0.309830, -1.043010, -0.395630, -0.846330, 0.733850, -0.201670, -0.238830, -0.250250,
1.726470, -0.686670, -0.362370, -0.069080, 0.333500, 0.151680, -0.187250, 3.090360, 3.165540, -0.746630,
0.930200, 0.631490, 0.341900, 3.840050, -0.672710, 0.740960, 1.299650, -1.789000, -1.640770, -1.667260,
4.557330, 13.588350, -2.497690, 0.645410, -0.035620, -0.369730, 0.015040, 1.149920, 2.364260, -0.704020,
2.054720, -0.974110, 3.876360, -2.988520, -1.029850, 2.259150, 2.642440, 2.848670, -0.922460, -1.667060,
-0.763960, 3.407460, 2.248080, 0.723670, 1.499230, 0.251990, 1.210760, 0.596550, 55.774052, 1243.716064,

-1.468840, 0.152420, -0.499530, -0.296940, 0.214950, 0.603230, -0.200080, -3.168130, 0.543800, -1.039900,
1.004000, -0.033420, -0.337510, 0.148300, 0.791010, 1.158520, 0.813980, 0.390770, 3.401760, 3.458960,
-0.036450, 0.180670, -0.075370, -0.268720, 0.655920, 2.293520, 1.248620, 0.900900, 1.164400, 0.447340,
-0.962300, -0.411660, -0.222490, 1.259380, 0.464040, -0.620980, -3.319560, 0.000390, -3.539010, 0.732950,
-0.449920, 0.545620, -1.604950, 0.168520, 2.301700, 2.217020, -2.153210, 0.510170, 0.536290, 0.249090,
-2.529420, -0.988840, 0.336360, -1.408190, -0.969970, 0.345170, 8.429580, 0.140330, -0.618490, 0.537520,
-0.934350, 1.146610, -0.637390, -0.690970, -1.008050, 3.220570, -0.633180, -1.146100, 0.026610, -1.968410,
-0.923080, -3.602350, 0.148110, -0.532530, -0.107830, 1.208220, -2.061750, 0.143680, -2.178340, 1.759970,
-2.484170, 0.399250, 0.224150, -0.197950, 0.570100, -0.850520, 0.301360, -2.519740, -1.460580, -0.864640,
-0.342590, -0.911270, 0.713670, -0.738840, 0.176480, 0.525990, 2.262220, 2.537340, 0.387310, -2.021640,
0.881680, -2.799300, 1.193170, -4.264260, 19.623091, -15.952730, 58.241329, -13.024130, 6.519230, -1.273900,
0.290410, -0.012760, 0.980350, -0.538140, -2.554660, -1.313180, -0.716410, 0.843570, 0.721220, 0.334240,
2.072490, -0.456560, -0.393330, 0.532360, 1.346310, -1.878810, 2.524170, -5.767510, -0.664780, -0.843210,
-0.673710, 1.855300, 0.603300, 0.045850, 0.372150, -1.917170, 0.770510, -0.282100, -11.000690, 2.466870,

-1.160240, 0.701760, 0.830220, -0.072670, -0.001720, -0.464460, -0.033410, 1.521520, -0.323680, -0.377990,
-0.627960, 0.419240, -0.406420, 0.156600, -0.774860, 0.771700, 0.816340, -0.017150, -0.690390, -2.151260,
1.138990, -0.720750, -1.064810, -0.948280, 0.412680, 0.165570, 0.357630, 0.754530, 0.413790, 0.464370,
-0.384290, -1.062450, -0.721250, -0.875270, 1.547480, -0.717660, 0.356190, -0.298410, 0.220320, 0.711390,
-0.297490, 0.531960, 0.549790, 2.584150, -0.102040, 0.097810, -0.253620, 0.477890, -0.221840, -0.677280,
1.707460, 1.451480, 0.973140, -0.456990, -1.750920, 0.726150, 1.347710, -0.051890, -0.003060, -0.388450,
2.436440, 0.598960, 0.472380, 1.171130, 0.125200, -0.454690, -1.737030, 0.750350, -0.434240, 0.847760,
0.286310, -0.420440, -2.363000, 0.434220, -0.814290, -0.350600, -0.139070, 0.663110, -0.347870, 0.483590,
-0.063990, -0.341500, 0.503720, -0.210230, -3.661450, -0.646010, -0.631190, 1.586570, 0.443930, -0.146970,
-12.439500, -0.743850, -0.730690, -2.264740, 0.465580, 0.918890, 0.897370, 0.701330, 0.026910, -1.287540,
-1.011070, -0.161110, 1.646840, 0.709180, -0.343210, -3.816870, -0.011030, -2.722170, 2.714480, 2.060950,
-1.040960, 0.308880, 1.794970, -1.277790, 0.069820, -0.443940, 0.455260, -2.152870, -0.437990, -0.923470,
0.559810, 0.356260, -0.093160, -0.052520, -0.722890, -0.085420, -0.254090, 0.594180, -0.407720, 0.268570,
-0.444970, -0.216840, -0.272820, -0.491750, -0.969030, 0.466380, 0.385110, 0.433160, -3.347690, 0.474930,

-1.109500, 1.121310, -0.291770, 0.256910, 1.916730, -0.263810, 0.085120, 0.581410, 0.098980, -0.754910,
0.163950, -0.274380, 1.143760, -0.986100, -0.946720, -0.236940, -1.568640, 0.863100, -1.324710, -0.498130,
0.202240, 0.681570, -0.914280, -0.087490, 1.901740, -0.497820, -0.089630, -0.818160, 0.868570, -0.381280,
-1.349290, 0.627230, 0.653470, -1.664740, -1.029850, 0.930040, 1.331730, 3.103610, -0.148080, -0.556930,
3.912920, -0.101300, -0.608230, -1.570410, 0.359550, -1.325940, 1.858030, 1.478350, -0.565740, 8.690970,
1.193260, -0.039590, -5.152470, 0.459930, 0.820760, -4.243580, 0.562840, 1.526920, -0.281820, -2.351830,
-2.323230, 1.891120, 0.295030, 4.593490, -4.860340, 0.480720, -0.383150, -0.689380, -0.065500, 1.376240,
4.240990, 0.994590, 0.122100, -2.362240, -0.155750, -2.447910, 1.144680, -0.400160, -0.077620, -0.522510,
-0.772010, -0.180190, -2.572650, -0.599010, 1.010480, 1.072330, 0.251840, -1.074190, 0.552870, -0.633070,
1.837710, -1.744200, -0.238110, -2.812450, 1.921530, 1.149390, 3.231310, -1.684400, -0.735010, -0.450050,
-1.325470, 2.547480, -2.719760, -1.046110, -5.283950, -0.485650, 4.107910, -1.614200, -4.064370, -2.773930,
-0.645590, -0.620260, 2.079890, -10.876540, 3.043890, -0.840680, -0.031880, -1.865450, 0.184710, 0.584660,
-2.826490, -0.928210, 0.296140, 0.125190, -0.529110, 2.330650, 0.469550, 8.192520, 0.726960, -0.138720,
0.540420, -1.024730, -0.744300, 0.694570, -0.841020, 1.417340, -1.105280, 1.933820, -2.913570, -4.309870,

-0.791700, 1.862990, 1.501190, 1.064720, 0.703950, 0.355610, -3.154890, 0.272140, -0.662560, -2.364930,
-0.965550, 0.722260, 5.427130, 0.203030, 0.236260, -2.260460, 0.255020, 0.303460, 0.440150, -0.289860,
0.754210, 2.457440, -0.158790, 0.150150, 0.626180, 0.459260, -0.026440, -0.802920, 0.140860, 0.093040,
-1.242840, -0.461360, -1.001600, 0.349250, 1.865390, -0.046290, -8.949980, 0.214440, -1.044520, 4.184010,
-0.131530, -0.708010, -2.822390, 0.575880, -0.192910, -4.447170, 1.411710, 0.037580, 0.974640, -0.764670,
-0.907410, 2.192650, -0.173440, -0.097990, -2.755160, 1.619710, 0.610340, 1.437260, -2.437300, -0.763200,
-1.031110, -0.305470, -1.480190, 3.713720, -1.628230, -0.296360, -0.194680, -0.946560, 0.496050, -4.557410,
0.935460, -1.010710, 0.010320, -0.140010, -0.577190, 2.411940, 0.618160, -0.955730, -2.905270, -2.098070,
0.376030, 2.841320, 1.116410, -0.158610, 0.776950, 6.789960, 0.800700, -1.202900, -1.272630, 0.140250,
1.800100, -0.036030, 0.134170, 0.872900, -1.026610, -0.923010, 1.301460, -2.177820, -0.079050, -0.556920,
2.194880, -1.825850, 1.120570, -7.724760, -2.643820, 6.751490, 2.251250, -5.084380, -0.926430, -2.712980,
0.512390, 0.404160, -2.696230, 0.034830, 1.158960, 1.480510, 0.432290, -1.326790, 0.310230, -0.710230,
-1.563840, 0.157900, -0.727300, -0.209940, 0.590450, 0.963340, 0.293840, 1.652930, -0.851090, -0.506520,
-0.546510, -0.697570, 0.455530, -0.163120, -0.038410, 0.955970, 0.660660, 3.103640, 2.287980, 1.616560,

4.023220, -1.154650, -0.120950, -3.911500, 21.627661, -1.102150, 0.086650, -9.379810, -0.464810, 1.748430,
-20.306240, 2.358550, 0.870530, -5.119010, -2.058610, 1.623910, 9.578930, -1.220920, -5.333950, 6.372520,
0.225660, -2.338630, 8.812710, 0.234020, 1.617930, -15.551530, 0.847550, 1.972820, 6.959090, 0.170910,
-4.666560, 0.394210, 0.155760, 2.914230, 3.969580, -0.747770, 1.019450, -2.379180, -1.068500, -1.334890,
-1.162940, 1.289110, -1.224220, 5.313070, -0.166820, 0.291240, -1.592420, -7.797100, 3.706120, 2.926380,
-1.856100, -2.438200, 4.432760, 2.421120, -3.357720, -2.864320, 0.957870, 0.709650, 0.080170, 3.745220,
1.433570, 2.315230, -0.992260, 1.027450, -1.889530, 0.958430, 1.533170, 0.804500, -5.137970, -2.334470,
-1.354890, -0.384640, -0.262980, -0.428460, 2.920470, -0.197270, -0.459090, 1.031750, -4.090920, -9.439950,
-0.603090, 1.208250, 9.456360, -1.196840, 1.771960, 0.422490, 0.565610, 3.048830, 0.753130, -0.545710,
-0.350400, -1.013000, -1.343320, -0.878680, -0.434850, -0.104290, 0.425080, -0.622680, -1.032900, 0.222380,
-1.872790, -0.511980, -3.920940, 6.826600, 1.075770, 59.385181, -8.083170, -16.161051, 15.047920, 16.850250,
-2.529810, -0.871900, -3.279550, 2.416620, -1.092100, 2.695190, 0.417190, 11.850460, -0.970090, -1.414350,
-1.038660, 0.727820, 0.182300, 0.261560, -2.346930, 3.326430, -0.021180, 13.632750, 0.286540, -2.084640,
0.157770, 1.342060, 2.545820, -0.137630, 3.443320, -3.348760, -0.449790, -1.880630, 25.617029, 37.281029,

0.148820, -1.555940, 0.729140, -0.205310, 2.584280, 1.302470, 0.355560, 2.548450, 0.076380, -0.078840,
0.961820, -0.509290, 0.105560, 2.977440, -0.061070, -0.263800, 2.943340, -0.289910, -1.322380, -3.143230,
0.739810, -2.248660, 0.528450, 0.324310, -0.208960, 8.278670, 0.630580, -0.404750, -10.302050, 0.155680,
0.439140, -8.257300, 0.414790, -0.282890, 21.654970, -0.012450, -0.280580, -1.891390, 0.049990, -0.115000,
-9.022150, -0.016720, -0.429370, 1.151410, -0.438700, -1.685870, 0.682270, -0.719640, -0.864170, -4.130300,
-0.693400, -1.364790, -8.756820, 0.061080, -2.037960, 34.073311, -0.903680, -1.014680, 0.901780, 0.288190,
1.300480, -5.270710, -0.651080, -0.583580, 33.641109, 0.042000, 0.388680, 1.867330, 0.263060, 3.411540,
0.922190, -0.310730, -0.495000, 25.905190, -0.094470, -0.053460, 2.971970, 0.886030, 0.497470, -1.639260,
0.567100, -0.845530, 4.412750, 1.873420, -1.606710, -4.010040, 0.090920, 0.792900, -2.238430, 0.615840,
0.131360, 3.792890, 1.552220, -1.177330, 3.196550, -0.172380, 1.853370, -1.261310, 0.698450, -2.242140,
-0.005720, -2.786390, -1.765860, -1.480960, -0.151410, -5.727520, 0.625730, -4.173080, 0.285480, 0.473730,
-2.077110, -2.985900, 4.243860, -5.309020, -1.050530, -1.422580, -0.028840, -3.535320, -0.106090, -0.959280,
-11.391470, -0.713230, 1.376740, 0.830270, -0.298990, 0.489100, 0.897030, -8.705680, 0.362970, 0.777720,
0.779680, 1.171850, 0.582430, -0.015030, -0.071260, 2.347590, 0.214250, -0.855020, 15.753690, 1.078750,

-0.351250, 1.086030, -0.874920, 0.340110, -0.513030, 0.700500, -0.655920, 0.196120, -0.266660, 0.408940,
-0.487390, 0.750640, -0.115140, 0.268000, -0.468980, -0.321430, 0.275570, -0.627200, 0.526750, 0.318210,
1.012930, 0.255930, -0.082350, -0.162230, -0.662010, 0.077740, -0.128750, 0.546230, 1.082120, -0.289300,
0.295440, -0.592280, -0.398770, -1.195400, -0.772440, 0.129040, -0.846920, -0.679570, -1.538730, -0.542920,
0.766070, -2.386790, -0.135250, 1.191610, 0.994110, 0.700360, -0.170720, -0.838770, 1.294370, 0.092210,
0.522320, -0.816720, -0.657010, 2.106880, 0.478250, 1.728260, -0.838640, 0.009240, -0.165100, 3.113840,
0.345750, -0.987960, -0.472400, -3.248160, -1.108270, 4.494010, 0.305310, -1.310330, 1.211290, 1.142150,
0.524440, -0.026930, 0.397410, 0.319700, 1.235610, 0.344200, 0.421830, -0.844160, -0.259550, -2.678480,
-0.902410, -1.603640, 1.971460, 0.511910, -0.388530, 0.015810, -0.331950, 0.213190, -0.369390, 0.654720,
1.225810, 1.254880, 0.473600, 0.044420, 0.294730, 0.229280, -0.071720, -0.214220, -0.145510, -0.061700,
-3.073340, -1.736430, 0.071840, 2.613080, -3.488250, 0.296660, -2.022670, 1.192050, -1.609010, -0.673390,
0.113410, 0.988810, -0.001870, 1.369760, 0.268220, 0.617890, -0.489780, 1.097600, 0.344170, -0.199120,
-0.548840, -0.378440, -1.470940, -0.102210, 0.194160, -1.184280, 0.377630, 0.306620, -0.930750, -0.480650,
-0.151780, -0.425270, -0.120360, -1.198570, -0.081660, -0.881720, 0.036220, -1.432700, -0.384450, -1.016080,

1.030130, -0.437990, -0.582550, -0.334960, -0.437470, 0.546830, 0.160100, 0.310040, -0.480300, -0.535010,
-0.099930, 0.022850, -0.183570, -0.519120, -0.900730, 0.809730, 1.751350, 0.602620, -0.613830, -0.920430,
-0.239010, -0.345190, 0.903520, -0.067130, -0.283330, -0.591050, -0.014950, 0.354120, -0.604970, 0.707610,
0.107880, 0.315850, 0.681520, 0.147520, 0.678600, -0.268020, 0.956030, 0.513020, -0.505730, 0.492160,
-0.659730, 0.153890, -2.815970, -1.737140, 0.982260, 1.044020, 0.999060, -0.944680, -0.019720, -0.437390,
1.059080, -0.480640, -1.286490, -4.666220, -1.375560, 0.777960, 4.370250, 0.146150, -1.312880, 0.183330,
0.410100, 0.588190, 0.620990, 2.629490, 1.278290, -2.789530, -0.270950, 0.351430, -0.331000, -0.281470,
-0.524700, -0.425150, 0.018960, 0.215350, 0.504330, -0.987180, 0.288440, 0.210450, -0.602570, 0.306440,
-0.726940, 1.204610, -0.314200, -0.333330, -0.683380, 0.207100, -1.235720, -0.463230, -1.449740, 0.942730,
0.929380, -0.686910, -0.998340, -0.065060, 0.001330, 0.893490, 0.489250, 1.033770, -0.446860, 0.841220,
0.325600, 1.403310, 0.543990, -0.826490, -0.101490, 0.456580, 2.216370, 0.446550, -2.258330, 2.808140,
-1.818510, -0.160400, 0.259560, -0.260010, -0.021290, 0.144080, 0.525590, -0.876070, 0.168200, 0.421390,
0.540930, -0.617030, 0.112780, -0.496060, -0.208690, 1.103380, -0.646280, 1.109060, -0.699110, 0.133540,
-0.189380, 0.029070, 0.317150, -0.470110, -0.293480, -0.071770, -0.081170, -0.906490, -0.204570, -0.136730,

0.149340, -1.658190, 0.114630, 0.691110, 2.676900, -0.175150, 0.983120, -0.197880, -0.382750, 1.010980,
0.341370, -0.173790, -0.133010, -0.771580, -0.428270, 0.171760, 1.631520, 0.874820, 0.335320, -0.464430,
-2.140840, -1.954350, 0.971390, 0.784670, -0.279780, 0.982270, 0.757940, 1.099570, -0.067780, -0.047470,
0.004420, -0.181760, -1.051880, -0.445820, 1.022700, -0.843600, -0.267520, -2.820220, 0.763800, 0.596880,
0.136520, 0.602030, 1.071780, 2.134020, -0.151640, -2.120070, -0.586540, -0.621600, 1.285190, 0.008850,
-0.819670, 0.144770, -2.553990, -0.147390, 0.845570, 0.584990, 0.745770, -0.531390, 0.605870, -0.874760,
-0.954540, 0.670010, 0.234210, 0.908700, -1.214320, 0.034150, 0.918270, -0.128130, 0.365270, -1.539510,
1.632020, 0.192780, 0.119300, 0.688930, -0.292590, -0.662050, -0.235490, -0.281910, -0.617380, -0.812140,
1.889170, -0.476370, -3.265400, -1.216110, 0.313020, 2.578020, -0.599140, -0.449720, 0.578280, -0.044420,
1.031510, -3.056910, 0.387830, 0.228450, 0.170640, 0.468580, 0.246260, -0.142840, 0.122000, -2.191170,
0.561770, 1.183680, -5.485080, 2.079930, 4.577430, -6.123340, -10.854120, 7.963720, -1.228830, -2.225830,
0.535150, -1.396470, -1.666130, 0.720190, -0.427700, 0.096120, -1.051130, -0.936630, 0.242200, -0.275590,
0.678210, -0.093070, 0.503080, 0.398130, -0.697320, 0.675230, -0.388980, -0.356660, 0.108120, -1.334190,
-0.117570, -0.403370, 0.145600, -0.124650, -0.643280, 1.054970, -0.450370, -0.853700, 0.930810, -11.335390,

-1.488490, 4.138080, -0.290060, 1.831510, 2.326940, 0.463650, -0.744120, 0.062980, -0.041320, 0.368840,
-2.369990, 0.130250, 0.852430, 2.512280, 0.321630, -0.477330, 1.029730, -0.302060, 0.267450, -0.809280,
-0.525310, 0.766210, 0.998450, 0.180810, -1.919500, -2.106240, 0.806050, -0.979820, 0.380230, 0.772550,
0.629230, -0.422930, -0.125950, 0.272430, -6.553940, -0.179100, -2.643580, 0.343640, -2.579060, -0.593540,
-1.524280, -0.957720, 0.736600, -1.738630, 3.113560, -0.603080, 2.856870, -6.653960, 0.820910, 3.341510,
-2.298960, 0.857810, -2.829090, 8.043630, 0.732040, 0.270570, 11.363760, 0.413530, -2.335750, -7.001430,
-0.281770, 0.852770, 8.394980, -0.091620, -0.610200, 21.094090, -0.355170, 0.503070, -14.918670, -0.316110,
9.529340, 0.417530, -0.757440, -0.795070, 20.275860, 0.023290, -5.138560, -6.612230, -0.187170, -2.448740,
0.764040, 0.458210, 0.152810, 0.774000, 0.494700, -0.857750, 3.138390, 0.029740, -3.460820, 0.709230,
-0.101910, 1.260430, 3.620360, -0.276610, 0.076360, -0.233770, 0.354450, 2.933360, 1.114200, 1.154760,
3.561500, -0.092100, 0.842400, -1.400030, 0.667410, 0.966750, -1.090400, 1.691750, -0.790920, -3.312490,
-1.222600, -2.815880, -2.355400, 1.811590, -3.017530, -1.323440, -0.216410, -0.043710, 0.051150, 0.319350,
-4.026310, 0.369100, -0.379060, -0.697670, 2.043510, -10.259240, -0.729940, -2.840680, 0.584630, 1.340980,
0.519150, -0.925500, -1.602750, 0.585900, -2.483260, 0.518990, -0.328920, 1.755210, -3.211270, 0.848620,

0.192160, 1.614370, 0.238040, 0.447110, -3.081190, -0.164830, 0.893770, 0.564710, -0.596630, -0.410330,
1.436670, -0.165230, -0.593880, -0.826080, -1.144120, -0.240460, 0.250150, 0.725050, 0.457210, -0.172560,
0.596750, 0.266870, 0.001780, -0.972610, 0.721610, 1.387120, 0.382580, -0.192980, -4.502860, -0.647480,
-0.307350, 1.754060, -0.402650, -0.961560, 3.807020, 0.578760, 1.189780, 0.959430, -1.200440, 0.005320,
-1.307590, -0.167070, -1.299250, -0.558130, -0.957400, 1.769060, 5.960990, -0.624350, 1.048370, -1.724090,
0.363110, -0.321840, -0.011120, -0.403970, -0.926700, -2.016360, -0.481190, -0.208030, 2.192250, -0.072170,
-1.243010, 1.351430, 0.195440, -0.206810, -1.517410, 0.475540, -0.309640, 1.256900, 0.072740, 1.081340,
-0.233380, 0.677090, 0.172870, -0.855990, -0.256380, -0.618500, -0.752330, 0.456060, 1.448610, 0.566670,
-0.689300, 0.021660, -0.336810, 0.699790, -1.670140, -0.005730, 0.173960, 0.252500, 0.839000, 0.420420,
1.506770, 0.423500, 0.304750, -2.701100, -0.478110, -0.227510, -0.550210, 0.080960, -1.313330, 1.231040,
-0.816160, -2.048420, 0.633630, 0.108720, 2.917150, -0.579490, -3.236940, -1.067100, -0.313650, -0.300940,
1.009090, -1.641650, 1.827990, 3.137340, 0.085920, 1.103730, 0.340750, -0.376470, 0.460680, -0.845090,
-4.079020, -0.620310, 0.259110, -0.979060, 0.693300, -2.116330, -0.638000, 4.952090, 0.328890, -0.570060,
-0.290560, 0.771320, 0.971210, 0.602220, 0.270440, -0.731170, 1.352590, -0.019870, 4.459950, 4.487300,

6.738090, -20.304991, 1.657000, 0.718990, 0.501610, -2.325690, 1.010890, 1.671030, 2.353030, -0.253690,
8.348680, -10.310720, -0.290690, 1.483110, -2.202730, 1.788450, -6.416070, -0.248470, -1.431060, 4.230390,
0.527700, -0.161190, 0.394720, -9.689350, -0.673110, -4.488060, 3.981600, 0.267040, -0.644290, 0.927030,
-0.336470, -4.493200, 8.424370, 9.290770, -0.583660, -0.035250, -0.452180, -10.966090, 15.821570, -0.726470,
0.549830, -5.667330, -1.539490, 2.080790, -3.225500, -1.090650, 0.322730, 14.968340, -0.316640, -6.246080,
-0.072810, -1.897130, -4.091110, 0.577950, 3.315510, 15.553620, -8.866530, 8.097530, -1.714000, 0.811510,
-1.499060, -5.522290, 10.572720, 0.939110, -0.551700, -2.164930, -13.638700, 4.907780, -1.829400, 0.965220,
3.242880, 0.112160, -0.556870, -7.063190, 2.346870, -0.226430, -3.152210, -0.424440, -0.053700, 34.008308,
-0.682850, -4.438070, -24.271521, 2.081290, 11.734780, 10.342380, 0.689410, 11.175980, 11.273290, 0.656610,
4.336600, -16.778469, -3.272330, 5.145230, 0.110060, -0.301220, -7.182310, 4.653260, -1.208130, -10.727240,
-6.402330, -8.038440, -15.691930, 4.126990, 17.915220, -5.723310, -34.738258, -1.111240, 7.939200, -9.815850,
6.808350, 7.303790, 9.079650, -24.313259, -4.883000, 0.754320, -3.734850, 9.569620, 0.262160, 0.241470,
55.851398, -0.018330, -3.405390, -0.797650, 13.152100, 19.590450, -2.389640, -5.949630, 0.971720, -5.485060,
4.581860, -0.385890, 5.456030, -0.587960, 1.508920, 2.489260, -1.132120, 0.432550, 206.288879, 14.468980,

-0.600930, -0.340600, 0.426670, 0.268420, 0.014810, -0.151050, -0.145830, 0.957180, -1.133680, 0.088380,
0.622420, -0.019730, 1.064390, 0.442510, 0.090020, -0.706260, 1.150910, -0.707740, 0.959520, -0.031270,
0.339030, 0.208600, -0.190820, 0.534790, -0.462870, -0.601760, -0.892230, 0.296400, 1.351770, -0.299370,
-0.898260, -0.545500, -0.061200, 0.326040, -3.051580, 1.187430, 0.067850, 0.898590, 0.274410, -2.756470,
-0.191440, 0.466580, -0.116770, -1.761080, -0.071610, -0.345910, -0.803270, 1.456860, -0.298770, 0.585680,
-0.607940, 0.653440, -0.541470, -0.452840, 1.558220, 0.089290, -0.081310, 0.622730, 0.228900, -0.409180,
-3.174910, -0.373670, -0.533110, 3.823750, 1.162730, -0.348210, 0.006270, -1.301930, 0.538240, -3.781050,
0.758260, 0.261070, 0.577570, 0.073200, -0.870120, 0.515660, -2.516130, -0.875170, -1.125410, -1.103400,
-0.111080, 0.537300, 1.521520, -0.644550, 0.600260, -1.194100, -0.498990, 0.118580, 0.253300, 0.493510,
-0.215550, 1.253580, -0.855720, -0.044930, -0.431670, 0.167980, 0.118740, 0.068860, 1.066750, 0.198550,
-2.192690, -0.888840, -0.469430, 2.010060, -1.944540, 0.378210, 0.647670, -0.240620, 2.242810, 0.147070,
1.228070, 0.121260, 2.241780, 2.204750, -0.926910, -0.927760, -0.066020, 1.151780, 0.575170, 0.515050,
0.887530, 0.491430, -0.751960, 0.013860, 0.622930, -0.818260, 1.385910, 1.425940, 0.068620, 0.298810,
-0.024240, 0.071180, 0.397010, -1.074830, -0.074190, -0.812650, 0.011860, 0.404520, 14.651620, 2.458420,

-0.001760, -0.804690, -0.032820, -0.459780, 0.133990, -0.436960, 0.451780, -0.029020, 0.713620, -0.700050,
1.209640, -0.886180, -0.625410, -0.217160, 0.965230, 2.647460, 0.775180, -0.667190, 0.304000, 0.086170,
-0.297500, 0.227580, -0.266740, 0.362650, 1.954860, 0.664760, -0.220840, -0.580470, -0.333850, 1.055160,
-0.098420, 0.606740, 0.530650, -0.012350, 0.885090, -1.096050, -1.812030, 0.841970, -0.641320, -0.420690,
1.297870, 0.071690, -0.100360, 1.183620, -0.508550, 0.375440, 0.684930, -0.735070, 0.383170, 0.765140,
0.053880, -0.172510, 1.107880, -0.905110, -1.900940, 0.506840, -0.585630, 1.111370, 0.619170, -0.641090,
0.655450, -0.262510, 0.110930, -1.136270, 0.676020, 0.200960, 0.025350, 0.491680, 0.642980, -0.800460,
-0.989930, 0.492590, -1.096910, 0.777710, -0.358940, -0.759350, -0.811460, 0.067050, 0.709520, 0.557940,
0.789850, -0.843650, 0.359420, -0.492380, 0.205290, -0.055350, -0.924020, -0.653600, -0.431140, 0.362100,
0.203960, 0.152280, 0.342190, 2.698530, -1.014740, 0.736390, -0.892970, 1.268100, 0.396150, -0.068990,
-1.096520, 0.816400, 1.735690, -0.974360, -0.774650, -0.929770, 0.834160, -4.075890, -0.334380, -0.063200,
-1.490790, -0.009930, -0.562170, -0.731280, -0.437460, 0.571370, -0.874750, 0.082740, 0.123500, -0.327010,
-2.367190, -0.294780, -0.545340, -0.420700, 1.263460, -1.874900, -0.086870, -1.571910, -0.440540, -0.341910,
-0.520780, 1.215850, 0.450430, -0.242180, 0.512100, 0.251010, 0.911660, 0.505710, 13.161610, 1.961260,

-0.103390, -2.074240, 0.119530, -1.025020, 2.630890, -0.295090, 1.465070, 0.495320, 0.072580, -0.611950,
-0.670680, 0.836650, -0.206000, 1.766360, -0.127180, 0.692480, -1.080130, 0.410750, -2.056360, 1.327320,
0.294210, -0.004040, -1.027600, -0.453950, 0.083720, -1.044070, -0.572080, 0.230610, 1.513280, -0.285240,
-0.228550, -0.423700, 0.858730, 0.125780, -0.577930, 1.154800, 0.231780, -0.636260, -0.692220, 0.252330,
-0.819520, 0.766560, -0.015970, 0.313170, 1.701490, -0.778360, 0.092590, 0.320750, -0.198870, 0.222320,
-1.556320, -1.036070, 0.623720, 0.931630, -1.352450, -1.319560, -0.535800, -0.077180, -1.795020, 0.085720,
0.390820, -2.153990, -0.637400, -0.079140, -0.147750, 0.888770, -0.604670, -0.176200, -1.239430, 0.834860,
1.136880, -0.810320, -1.610120, 3.989020, 2.492180, 0.357490, -4.828740, 0.609860, 1.182300, 0.426970,
-1.848180, 0.592490, 16.864740, 4.920050, 0.266360, -11.567690, -0.827700, -0.111730, 6.022230, -1.807340,
-0.970960, 4.268530, 0.511960, -0.742610, 23.276899, -0.339550, -0.431760, -5.905480, -1.728600, 0.431720,
0.449500, 1.036870, -1.501060, -1.529980, -2.719870, 2.105760, 3.167360, 1.109690, 1.032400, -5.339550,
-1.280810, 0.579050, -0.047850, 0.277560, 1.841710, 0.320430, 0.246570, 1.096980, 0.768640, -0.080500,
6.638620, 0.519510, -0.549560, 0.223680, -1.180670, 0.583120, -1.528530, -0.384920, -0.126560, -0.138250,
0.532200, 1.883830, -0.436010, 0.584660, -0.235180, -0.934770, 0.612840, 2.999260, 0.223130, 0.849630,

0.196600, 0.357930, -1.404540, -0.863420, -2.591460, 1.223390, 0.707510, -0.313590, 1.341990, -0.493810,
0.293980, 0.126720, 1.040510, -1.905220, -0.242180, -0.600000, 1.893760, 0.474650, 1.049180, 1.900870,
1.180620, 0.185180, 1.265720, 0.211080, 0.071770, 1.285190, 0.817940, -1.135800, 2.548650, 0.007850,
0.404870, 0.088580, 0.501070, 0.005980, 0.194390, 0.400050, -0.451420, 1.732650, 0.239360, 0.887880,
-0.390000, -0.364340, -0.050650, 3.937130, 0.352580, 1.277790, -0.744110, 0.322970, -0.089300, 0.173100,
-0.324060, 1.067900, 0.677450, 2.948580, 0.444360, -0.660880, -2.527610, -2.423480, -2.724120, -0.798900,
-3.930800, -7.949400, 0.408230, -1.078130, -0.683750, -0.417710, -0.678910, -1.863320, 0.066530, -1.315830,
-4.214430, -0.120970, -2.372900, -0.019290, -1.007450, 0.372100, 0.320410, 0.338510, 0.270960, 5.080030,
1.318430, 1.990020, 4.043050, 0.927980, -0.551300, 2.517830, -0.763200, -1.575580, 1.411550, -0.452200,
0.373220, 0.893080, -0.139690, 1.121960, -2.987540, 0.299920, -0.279730, 1.514690, 0.158690, -5.842130,
-2.019590, 4.494370, 2.393500, 0.105850, 0.213630, 0.270440, 2.415280, 3.516880, -0.286420, 0.031270,
3.264910, 0.358500, 5.040540, -0.674780, 2.559250, 2.566040, -0.479540, -2.919310, -0.204840, 0.047780,
4.462900, -0.882160, -1.262540, 0.838360, 0.237790, 5.439860, 1.419070, 0.090050, -0.165650, -0.029390,
-0.366990, -1.406230, -2.319400, 1.136560, -0.078270, -0.204430, -2.539120, 1.313200, -5.209190, 4.042760,

-1.114880, -1.104680, -0.940850, 0.632980, -0.242800, -0.681310, 0.619690, 0.716400, -0.191340, 0.551010,
0.577560, 0.306320, -0.100300, 1.388140, -0.136950, 1.306570, 0.322090, 0.381580, 0.159450, 0.302050,
0.389100, 0.651710, 0.550070, 0.175240, -0.855250, -0.283780, 0.956920, -0.893270, -0.188160, -0.299250,
-0.774430, 0.328220, 0.500270, -0.970600, -2.253640, -0.249320, -2.484820, -0.011400, 0.986100, 0.923270,
-0.191730, -0.646540, -0.423160, -2.135750, 0.638460, -0.218100, 6.443570, -0.801590, -0.795540, -1.335750,
0.091600, 1.288350, -2.860330, 0.968830, -0.024150, 4.287570, -1.530230, -1.037900, -1.578820, 0.216410,
-0.583040, -1.041320, -0.413020, 0.709070, 0.181990, 0.249460, 0.757550, -1.715670, 0.602730, -0.738540,
-0.429250, 0.610000, 1.510160, -1.066150, -0.254720, -0.578380, 0.322960, 0.483890, -0.573560, 1.722700,
-0.207160, -0.445800, -2.289000, 0.253780, 0.256690, 0.212810, -0.798460, -2.905470, 0.686840, 0.454220,
3.082910, -1.354320, 0.949620, 1.073590, 0.922640, -0.702380, -0.153890, -1.014430, 0.606010, -2.171100,
0.507400, -0.986710, -0.297870, -4.745320, 0.626050, -2.665900, 5.280320, 3.567030, -0.545930, 0.188960,
0.998920, -0.046050, 2.018510, 2.952000, 0.376460, -0.453290, -0.618810, -1.632410, 0.547480, 1.429290,
-0.050350, 0.101110, -0.974620, 0.036670, -0.093680, -3.166830, 0.908360, -0.086690, 0.838960, 0.279850,
-0.452080, -1.114280, 0.384940, 0.335710, -0.500430, -0.053570, 0.370430, 0.047300, 9.155090, -2.878010,

0.336400, -0.346660, -0.796640, 0.378020, -0.202430, -1.116610, 0.805700, 0.175460, 0.303580, -2.577820,
-0.856650, 0.241920, 0.012730, -0.185530, -0.488960, 1.486060, -0.948680, 0.571290, -1.796620, 0.510110,
-0.053680, 0.291400, -0.221910, -1.177630, 0.863350, -1.270120, -0.977220, 0.542110, -0.341020, -0.719830,
-1.101430, -0.248940, 0.370520, -1.820050, -0.654070, -0.828630, 1.107600, -0.938140, -0.381790, 0.365500,
-0.419530, -0.016360, 0.391910, 0.785130, 0.032570, -0.180510, 0.183900, -0.482420, 0.076900, -0.552560,
-0.006190, -0.512460, 2.580180, 0.441500, -0.517660, -0.841010, 0.565360, 0.469930, 1.179080, -0.000790,
-0.735450, 2.413370, -0.729540, -0.783630, 0.920890, 0.183750, 1.368350, -0.824930, 0.157920, -0.161770,
0.324600, 1.550070, 0.503560, -0.945430, 0.786130, 0.788380, -0.423460, 0.603090, -0.743210, 0.270090,
0.865410, -0.022970, 1.832180, -0.254590, -0.322340, 0.489620, 0.481200, -1.872700, 1.131890, -0.618980,
2.059660, -0.913580, -0.184570, 1.544110, 0.913290, 0.627710, -0.417380, -0.799170, 0.637540, 0.391200,
-2.682700, -1.821890, 3.379060, 2.895650, -0.201730, 0.267670, -3.451730, 0.500180, 1.237840, -0.242720,
-0.263270, -1.363400, -5.762200, -1.262830, 3.269470, 0.021740, -0.344040, 1.297120, 0.732810, 0.971330,
-5.251750, -0.759660, 0.502520, -0.545880, -0.904590, -1.249660, 0.398780, 4.047730, -0.753660, -0.595630,
0.665490, -0.284820, 0.752000, 0.905710, -0.637260, -0.160940, -0.319730, 1.740070, 22.130360, -6.077680,

-0.090460, 1.913640, 0.877220, -0.238840, -2.638610, -0.600450, -0.528710, -2.575950, -0.552230, 0.247320,
1.120240, -0.814220, -0.455270, -0.654980, 0.278630, -0.326050, -0.712800, -0.462980, 0.652980, 0.371220,
0.035840, 0.292910, 0.420110, -0.985370, -0.199190, -0.698010, 0.879120, -0.756950, 0.429360, 0.343330,
2.255190, -4.875850, -0.740840, -0.021540, 3.049760, 0.789250, -0.229840, 1.662330, -0.742700, 0.419460,
2.004130, 1.193750, -0.081250, -0.887620, -0.168930, 0.590750, 0.537210, 0.346800, 2.380290, 1.449910,
1.026340, -0.118850, -5.181480, -1.128090, -1.332000, -3.918830, 0.637620, -0.850360, -10.964650, -1.490270,
-0.782790, -7.735820, -0.598580, -0.904760, -11.319840, -0.261420, -0.752810, -15.147570, -0.653750, -0.480120,
3.358650, 0.462460, 0.133330, -10.413030, 0.877400, 0.998900, -3.024700, -0.080970, -0.758340, 2.896710,
1.004300, 0.313840, 1.214010, -0.700050, 0.604120, 2.016900, 0.539040, -0.548550, 0.302780, -0.472320,
-0.947330, -1.256470, -0.415130, -0.361450, -0.887010, 0.257450, 0.785210, 0.011120, 0.439060, -0.851850,
-0.175990, -0.445670, -3.870830, -1.050460, 2.493890, 3.501370, 6.015660, -1.263610, -1.321850, 0.195760,
2.485270, -0.044170, 1.432540, 0.413650, -0.170150, -0.002450, 0.174270, -0.431790, -0.614360, -0.752200,
1.488480, 0.442060, 0.761730, 0.735260, 0.232200, -0.078200, 1.176460, -0.487680, 0.092360, -0.305410,
0.768550, -1.473120, 0.120360, -0.493540, 0.059870, 0.061900, -0.235560, -0.236460, -2.756710, 4.003030,

-0.510220, -5.256060, 1.582770, 0.262040, 2.009370, -0.400290, 0.584470, 0.564250, 0.801040, 0.037170,
1.041900, 2.224690, -0.426950, 1.170070, 0.277460, 0.139340, 0.883870, -0.880400, -0.456540, -1.509950,
0.590070, -0.926740, 6.409710, -0.109300, 0.746230, -8.145760, 0.936130, -0.912620, -2.037420, -1.511090,
-0.377470, 1.586370, 0.479520, 0.789330, -4.290510, -3.063770, 0.216660, -0.950830, -1.947300, -0.964650,
-2.341160, 0.393970, 0.713970, -2.505020, -2.858520, 0.031420, -4.018640, 0.534570, 0.988840, -1.361130,
0.225800, 0.015820, 5.478700, -0.942030, 0.582030, -0.775650, -2.405830, 0.442220, -2.987780, 1.138010,
0.325920, 3.797990, -0.260020, -0.656380, -4.327060, -0.916370, 0.408430, 6.601560, -0.752980, -0.180990,
-6.897110, -0.396220, -0.142200, -2.687060, -0.082710, -0.648870, -1.374500, -0.174800, -1.811810, -1.179140,
-0.322990, -1.057440, 0.010460, -0.796040, 1.793250, 7.044380, 0.723660, -0.393840, -1.559260, 0.513540,
-0.319750, -11.668880, 0.845960, -1.477640, -0.980740, -1.598030, -0.467610, 1.891360, -1.117550, 0.285420,
-1.095780, 1.209020, -2.162980, -4.105210, -0.939390, 1.485040, 0.495670, -1.309290, -1.901150, -2.319720,
-1.343960, 3.184730, 1.963110, 1.490410, 0.806730, -0.200210, 1.229130, -0.240070, 0.981560, 0.857800,
4.108750, 0.220750, -1.177130, -0.549760, 0.111160, 0.588070, -1.999630, 1.777480, -0.299100, 0.973150,
-0.361490, -1.027460, -0.463480, -0.203830, 2.629310, 0.063390, 0.458980, -0.777720, 0.473930, 0.369610,

0.783810, -2.154640, 0.764840, -1.510990, 0.998170, 0.507050, -2.980670, 1.763220, -1.003960, -1.946260,
-1.617370, 0.825950, 2.384510, -0.429110, -0.777470, -3.618350, 0.187790, 0.643200, 0.133920, -0.987360,
0.308450, -2.087490, 0.107640, 0.169680, -1.626650, -0.262180, -0.263540, 4.168050, 0.433130, -0.314650,
4.774620, -0.023220, -0.050190, -12.078180, -0.253910, -0.227430, -2.744090, 0.091210, 0.282810, 7.240960,
1.915170, -1.447160, -3.363780, 0.357200, 1.296910, -18.766109, 1.766470, -3.980120, 0.173020, 1.264710,
0.131330, 1.804000, 1.088230, 0.829100, -14.393700, 0.955790, 0.664250, 6.825080, -1.003640, 0.135350,
0.827690, 0.335900, 0.816150, -7.233630, -3.101910, 0.693410, 1.323810, -0.044010, 0.594060, -0.699120,
-4.480270, 0.010950, -0.564470, 1.045590, -0.767330, 0.088760, 5.128110, 0.029290, 0.353000, 0.398360,
1.013520, -0.461010, 0.323020, 0.719510, 0.511300, 0.446280, -1.465000, -0.324680, -0.107500, -0.633570,
0.728710, -3.151840, -0.710690, -0.874060, 1.258110, 0.370590, -0.165970, -0.043290, 1.313090, 0.613720,
1.904960, 6.103740, -3.284450, 2.137820, -15.405770, -0.943420, 3.263860, 3.358350, -1.212900, 0.307050,
-0.017430, 1.523690, 0.409070, 0.796570, 1.750860, -0.371030, 1.540970, 1.130970, -0.041480, -1.232760,
-4.468610, 2.383500, -1.406260, -0.348520, -1.782210, -1.216990, 3.062820, 4.648830, 0.243380, -1.198020,
-0.161720, 3.631460, -0.645260, -0.066210, -0.992290, -0.364590, -1.635410, 2.277760, 14.919810, -2.262290,

0.656180, -0.176530, -0.924680, 0.525970, 0.287010, -0.058460, 0.122530, -0.131210, -0.515330, -0.332180,
-0.223430, 0.666100, 0.430600, -0.408460, -0.489550, -0.459370, 0.359480, -0.416380, -0.398440, 0.446010,
0.125370, 0.037660, 0.070370, -0.325030, -0.085530, 0.195630, -0.277310, -0.211070, -3.084010, -4.280970,
-0.417180, -0.611250, 0.827350, 3.052820, 0.263970, -0.443730, -0.858200, -0.320900, 0.696950, -0.231840,
0.727890, -0.597860, 0.893450, -0.383620, -0.008540, -0.669560, -0.833540, 0.038170, -1.477100, 0.041630,
0.395400, 2.916460, -0.062990, 0.509940, 1.275020, 0.625250, 0.116630, -0.053600, 0.434120, 0.411210,

0.803770, 1.639220, 1.708590, -0.685360, -2.073590, -0.189330, -0.658810, -0.482560, -0.558200, -1.824480,
0.625100, -0.685930, -0.887720, -0.956260, -0.137360, 0.359130, 0.141160, 1.052540, 0.055650, 0.373560,
0.600730, 1.254080, 0.049840, 0.707890, -0.051310, -1.416810, -1.083110, -53.589111, 3.754690, 0.410380,
1.069290, 0.036190, -0.038520, -0.699080, -1.132610, -0.268890, -0.046910, 0.132470, 0.781590, -0.520110,
0.760540, 0.304080, 0.137690, -0.123980, -0.453190, -0.647130, 0.439970, 0.518040, -0.522160, 0.664280,
-0.015790, -0.159910, 0.110320, -0.042440, 1.742800, 0.190840, -0.281560, 0.555280, -0.154560, -0.494250,

-1.924270, 1.597510, 1.379620, -1.625460, 0.513500, -2.083230, 0.864440, -0.174540, -2.604160, -0.859090,
1.750090, -0.000520, 0.674730, -0.085240, 0.185980, 1.061940, 0.314890, -1.154290, 0.819020, 0.340150,
0.781190, -1.596970, 0.114560, -0.023020, -0.426560, -0.581820, -0.561030, 0.949300, -1.044860, 7.090660,
-0.687960, -0.890440, 0.693530, -0.452730, 0.566040, -0.337830, -0.283940, 0.205880, -0.557510, 0.303570,
-0.475240, -0.285740, -0.060650, 0.619080, 0.442630, 0.476860, 0.679080, 0.261530, -0.703860, 0.150190,
-0.176300, -0.566320, -0.419650, -0.178290, -0.492900, 0.274440, 0.445350, 0.159700, 0.212790, -0.399040,

-5.215820, 2.856680, 11.140410, -37.675220, 4.751810, 3.147150, 1.641870, -157.093048, 0.094580, -0.824780,
7.322810, -5.949890, -0.177020, -0.301100, 0.295980, 3.380370, -2.348210, -333.297516, 0.690120, 5.333340,
-5.644050, 1.265480, -48.457291, -0.070270, 0.563250, 3.801700, -4.043760, 0.273090, 17.525230, 25.910589,
1.060260, 3.958650, -0.225380, -1.711300, -0.376710, -3.914930, 1.274560, 1.932010, -0.380390, -1.769150,
-0.180710, 1.284920, -0.545140, 1.751260, -2.868470, 0.442360, 9.144170, 0.283210, -0.472860, -0.697910,
-1.069400, -17.872610, 1.867740, 0.021510, -4.114670, -8.079450, 5.233030, -0.638280, 0.559620, -0.766130,

-0.042760, 2.613820, 1.565980, -0.411790, -0.382060, 0.210290, -0.044270, -1.280480, -0.176360, 0.843500,
15.056280, 0.064430, 0.266330, -0.963820, -1.066560, -1.615660, 0.450050, -1.955710, -0.474560, 1.923480,
0.864890, -0.015970, -0.085390, -0.010390, 0.185150, 0.934030, -0.799220, -2.811160, -9.985310, 176.938599,
0.444360, 0.180860, 3.556920, -2.414240, 0.797390, -0.604930, -1.607620, -0.094450, 0.145710, -0.643040,
0.064950, -0.824170, 0.239270, -0.311110, 0.114330, -0.149990, 0.294370, 0.226990, 0.368110, 0.656010,
0.657480, 1.041870, 0.705540, -0.683480, 17.270350, -4.193360, 0.596480, 1.034920, -0.807720, -0.642370,

0.213660, -1.791310, -0.377400, -0.113880, -0.235620, -0.291720, -0.626240, -1.293350, 2.113770, -1.534780,
-0.265080, 0.195990, 0.397650, -0.701450, -0.938050, -0.924250, -2.011630, -4.060620, -0.374930, -0.630960,
-0.583700, -0.078280, 1.679850, -1.003530, 0.141520, -0.260060, 0.086170, -1.244440, -42.956322, 2.267120,
-0.300640, -0.200850, -2.511120, -3.295250, 0.413340, -0.212330, 0.357790, 2.077540, 0.284650, -0.007070,
0.176060, 0.380180, 1.228590, 0.703610, 0.705410, -0.353490, 2.954410, -0.967730, 0.548190, -0.763930,
0.807470, 4.112330, 1.444530, 0.102110, 1.207860, 2.467810, 0.590150, -0.492170, -0.265310, -0.456370,

-0.300060, 0.461340, 0.523530, -8.345970, -3.021520, -0.279600, -0.412220, 0.189060, 0.715820, -0.602450,
1.059240, -0.751190, -1.184040, 0.953020, -0.619810, -0.060230, -2.200810, -3.089220, 0.423530, 0.280080,
-0.713250, -0.128370, 0.400780, 0.472040, -0.114760, -0.934740, -0.958250, -0.119160, -4.054920, 9.255770,
-0.599610, 1.048680, -1.071240, 0.552310, -0.721820, 1.173870, 0.775010, 0.057230, 0.421050, -0.207230,
-0.606570, 0.770070, -0.775750, -0.216390, -0.938360, 0.790450, 0.600890, 0.430080, -0.778600, -0.593200,
-0.075240, -2.905650, 0.388250, 0.701160, -1.203920, 3.190950, -3.009670, 0.252050, -0.291600, 0.162560,

-0.220040, -2.144310, 1.063460, 2.114640, 2.115010, 1.665470, -1.557120, -4.822570, 0.966090, 0.724640,
0.999530, -1.047250, -4.307060, -1.508730, -2.218660, -289.371674, 6.437410, -2.077630, 0.588510, 0.463820,
-0.981840, -0.737170, -1.047380, -1.293170, 0.056200, 0.533350, 1.786730, -5.748090, 10.717990, -6.763330,
1.249040, -0.334120, -0.550100, 12.802390, 0.149670, 0.820240, 2.367430, 1.488880, -1.039240, -0.481940,
1.346680, 0.760230, 0.045610, 0.611070, -0.412260, 0.499260, 5.994100, -0.657970, -0.848810, 0.217780,
0.152270, -0.556540, 0.929230, -0.249380, -1.547070, -22.727240, 0.479680, -1.060470, 0.012420, 0.665890,

0.205640, -0.342460, -1.368620, -0.332580, 0.885690, 0.798750, 0.377090, 0.170150, -0.141400, 0.696250,
-0.750850, -0.174440, -0.259540, -0.314590, 0.168460, 0.459340, -0.723590, -0.447490, 0.249730, 0.530350,
0.017510, 0.107430, -0.517000, 0.305260, -1.521380, 0.348690, 0.316500, 0.169450, -1.441710, -0.657380,
-0.062190, 0.108510, -0.570340, 2.577490, 0.388640, -0.126090, -1.107050, -0.415200, -0.114200, -0.645660,
0.764950, -0.635280, 0.858150, -0.562660, -0.599810, 0.154710, -0.515680, -0.611920, -0.592120, -0.409120,
-0.217860, -1.197270, 0.271240, 1.546810, -0.988950, -1.884570, -0.798520, 0.871190, 0.010420, 0.358050,

-0.010230, 0.191840, 1.538410, -0.692320, 1.246770, -0.265140, 0.043820, -0.364600, 0.226350, 0.078100,
-0.019030, 0.040900, 0.528190, 0.193400, -0.743860, -0.998420, -0.368510, 1.350600, -0.511840, -0.634320,
-0.389810, -0.649310, -0.254370, -0.234280, -0.187620, -0.141480, 0.389180, 0.434990, 25.019220, 15.808990,
0.462440, 2.324080, 0.023580, -7.917980, -0.655740, 0.678150, 2.499970, 0.096370, 0.175370, 0.104450,
-0.003580, 0.441110, 0.206370, -0.249460, -0.256360, 0.140150, 0.647210, 0.035570, 0.322920, 0.120780,
0.894220, -1.348600, 0.485510, -0.681000, -0.703250, -0.487580, -1.570110, 0.064610, -0.142860, 0.095740,

-0.742450, 1.352680, 1.634060, -1.528000, -0.113590, 0.142730, -0.921640, -0.219710, -1.631740, -0.635400,
3.395800, 0.161310, -0.627380, 0.891230, -0.402670, -0.879210, -0.119520, -2.432490, -0.306930, -0.708070,
-0.801900, -0.594130, 0.370330, 0.793500, -0.556010, -0.590760, -0.494960, -0.696610, -3.052610, 7.064960,
0.889730, -0.872910, 1.485000, 3.310820, -0.576700, -0.612080, -1.065660, -0.050060, 0.616000, 0.572710,
0.097810, 0.537170, 0.541560, 1.006750, 0.265100, 0.060750, 0.246480, -0.148490, -0.516880, -0.005580,
-0.685180, -2.526320, 0.400290, 0.768930, -0.782980, 0.164640, -0.085940, -0.046980, 1.151700, 0.832600,

-1.505200, 1.093890, 2.596310, -0.164650, -0.846670, -0.397840, 0.873480, -0.781570, 0.212060, -0.065380,
4.837640, -0.301280, -0.665060, 0.066240, 0.047200, -0.581280, 0.568220, -0.995130, 0.958840, 0.536640,
-0.196100, -0.547210, -0.329630, 0.687760, -0.616670, -0.471670, -0.705210, 0.403220, -18.395800, 24.071199,
-0.997800, 3.457180, 0.830780, 5.822700, 0.019330, -0.835770, 0.565900, -0.207600, -0.911550, 0.297900,
0.942510, 0.840340, 0.666420, -0.560610, 0.196340, -0.034370, -1.128180, 0.678810, -0.125570, 0.217790,
-0.667550, 3.682730, -0.755130, 0.671190, 7.445720, 13.247390, 0.472670, 0.236150, -0.375870, -0.574550,

0.853020, -0.085360, -1.357980, -0.385290, -0.319500, -0.481040, -0.131660, 2.020740, -0.167050, -0.302370,
0.784500, 0.273180, 0.286180, 0.157220, 0.177040, 1.290850, -0.408920, 0.401370, 1.166380, -0.709130,
0.366820, -0.196180, 1.086610, -0.363440, -0.665450, -0.476760, 0.132370, 0.838060, -12.840560, 1.819940,
0.071540, -0.855980, -0.599550, -2.433590, -0.656720, 1.324820, 0.288180, -0.179100, 1.066160, 0.836340,
-0.824310, -0.277520, -0.147170, -0.484170, 0.757570, -1.344330, -0.313300, 2.113540, -0.338440, -0.305990,
0.097240, -2.240710, -0.008920, 0.412650, -0.774280, 0.920880, -0.538340, 0.390080, -0.644640, 0.400990,

1.018900, -0.319810, -2.028760, -0.250160, 2.179590, 0.538080, -1.183740, 0.008850, 0.794110, -0.553030,
-4.271740, -0.163010, 0.440170, -0.425950, -0.861490, 0.406170, 0.513190, 0.788800, -0.249270, -0.708430,
-0.647160, -0.100460, -0.392720, -0.077050, -0.713620, 0.714800, -0.342120, 0.592950, 4.160130, -6.067800,
-0.444630, -1.180700, -0.814640, 2.682820, 0.002650, 0.086490, -0.838200, -0.057440, -0.079650, 0.344750,
0.092920, -0.676430, -0.127330, 0.037300, -0.564640, 0.630460, 0.338010, -0.105620, -0.539120, 0.131920,
0.649250, 12.052070, 0.711540, 0.629890, 1.855390, 1.432790, 0.479530, 0.358060, 0.430930, 0.173890,

0.106890, -0.854240, -1.792330, 0.508590, -0.502210, -0.338100, 0.158430, 1.071170, -0.901980, 0.129380,
0.051580, 0.711630, -0.142950, -0.067960, -0.628960, 1.654120, 0.427560, 2.030670, 0.322490, -1.136700,
0.869730, -0.622740, 1.294390, 0.303620, 0.109470, -0.382220, 0.327420, -0.462920, -2.367980, -67.785347,
1.042340, -3.340810, 0.381360, 3.499650, -0.270070, -0.169550, -0.197290, 0.426180, 0.070940, -0.458800,
0.378480, -0.431670, -0.034780, -0.362490, 0.418850, -0.568000, 0.103040, 0.159980, 0.166430, -0.331490,
1.006440, -0.029660, -0.098110, -0.311860, -2.964170, -6.466120, 4.089640, 0.012930, -0.040720, -1.119060,

0.868100, 0.436710, 0.544350, 10.690610, -0.275570, 1.143760, 0.522590, 3.398790, 0.150830, 2.200200,
2.592470, -0.622550, -0.153200, -0.195130, 0.514900, -0.914700, -0.505640, 2.765170, -0.387480, 0.299890,
-0.563270, -0.038080, -0.457430, -0.026420, -0.075120, 1.132890, -1.039270, 2.164320, -1.330370, 2.694280,
-0.203460, 2.358290, -2.081040, 16.981689, -0.030630, -0.454880, -0.039210, 0.321450, -0.059770, 0.775880,
0.400830, -0.509120, 0.423970, 0.496920, -0.542630, 0.534980, -0.423310, -0.865240, -0.926960, 0.659800,
-0.140940, 3.559180, -0.236120, -0.112170, -1.388960, 5.933160, 0.136270, -0.151300, 0.583460, -0.010390,

0.788190, -7.513700, 0.462860, 1.232800, -2.991430, -1.024060, 1.428990, 2.007020, 1.701300, -1.884590,
2.108380, 1.672940, 3.349620, 0.689990, -0.188110, -19.493790, -4.763680, -0.116470, -5.640210, -0.021590,
-0.568430, 0.606780, -0.864360, 0.218340, -0.552550, -0.053610, 1.545130, 2.687380, 3.792560, 10.633770,
1.972330, -0.205130, -0.796010, 0.983680, 0.114190, 0.879290, -0.134080, 1.027150, -0.758020, -0.133880,
-0.405620, -0.800700, 0.084600, -0.013480, -0.346250, -1.240040, -0.146890, 1.337230, 1.353370, -0.934780,
0.693940, -3.020190, 1.208020, -0.694590, 1.109410, 5.985260, 0.038500, -0.382220, -1.858480, 1.348310,

-1.329080, 0.320680, -0.137250, -0.290400, 0.198930, 0.099750, 0.786810, 1.223570, 0.577170, -0.104410,
1.895290, 0.446590, -0.750100, 0.850550, 0.550260, 1.732850, -0.359230, -1.205270, -0.034510, 0.950450,
0.193610, -0.642580, -0.237770, 0.352650, 0.384030, 0.789810, -0.462280, 1.664960, 1.340900, 1.300720,
-0.484700, 2.217820, -1.075210, 0.779240, -0.955270, -0.487920, 0.701360, 0.556960, 0.469680, -0.448950,
0.501080, -0.320010, 0.200810, -1.195850, -0.302940, -0.106710, -0.713140, -0.465910, -0.443660, -0.353700,
0.351650, 1.967980, 0.419110, 0.644710, 2.984160, 3.878000, 0.340900, -0.858490, -0.543770, 0.621910,

-0.221190, -0.641140, -0.251310, -0.730750, 0.866200, 0.005040, 0.254910, 1.472740, 0.363760, 0.021360,
-1.141410, -0.285480, 0.169190, 0.444830, -0.381480, 0.176320, -0.974040, 0.348430, 0.694680, -0.307360,
0.126800, 0.495110, 0.273870, -1.110120, 0.561610, 0.109710, 0.813870, -1.014780, 13.594070, -0.173730,
1.316310, 2.079870, -0.756570, -6.788810, 0.879040, 0.168140, -0.630220, -0.250870, -0.949440, 0.224770,
0.021300, -0.662510, -0.404320, -0.126440, -0.008510, 0.308470, 0.597020, -1.429060, -0.284390, -0.284610,
0.772870, 3.136310, -0.435650, 0.249470, -2.564230, -3.932180, -0.527490, -0.516160, 0.480390, 0.744210,

0.006230, -0.713900, 1.119850, 1.698490, -0.287550, -0.294240, -0.499450, 6.559540, -0.443140, -0.090810,
-4.641580, -0.803920, -0.729940, 0.810830, 0.327940, -1.058370, 1.693400, -0.639340, -0.204750, -0.909950,
0.289150, 0.446610, 0.281120, -0.635960, 0.826560, -0.417140, -2.183800, -1.229800, 12.390770, 0.730370,
-0.360780, -0.022290, -2.472750, -0.978760, 0.091950, 0.778780, 0.053880, 2.548110, -0.599060, 0.950450,
-1.641320, 0.774580, 0.654970, 0.542670, -1.225250, -0.802930, 3.304150, -0.713590, 1.080640, 0.917490,
-0.387090, -5.612770, 0.470070, 0.572300, -0.284940, -1.341810, 0.308120, -0.294420, 0.310450, 0.789420,

-0.034700, -0.455360, -0.823410, -0.670730, 2.529950, 2.026160, 0.698340, 1.138340, -0.288890, 0.053570,
-0.780270, -1.280110, -0.879220, 0.194010, 0.067580, -0.652560, -0.050620, -1.573100, 0.720620, 0.205940,
0.035240, -0.293250, -0.339720, 0.036790, 0.545960, 1.064010, 0.672240, -0.987040, 13.759440, 0.105570,
1.601730, 0.072210, 0.251340, -0.184090, -0.569680, 0.251910, 0.333240, -0.442130, -1.155850, 0.397110,
0.238170, 0.419590, -0.452220, -0.234110, 0.982720, 0.323990, -2.587120, -0.433470, 1.439120, -0.517990,
-1.022040, -1.968760, -0.541180, 0.710550, -2.039620, -2.568990, 4.069070, 0.741510, 0.325140, 0.615330,

-2.367350, -1.479610, -0.307060, 1.307860, -0.942360, 0.924500, -0.718890, 0.849630, 0.540980, -1.049430,
-7.827780, 0.143120, 0.458560, -0.977750, -0.287640, -0.578600, 2.268600, -0.562440, -0.997630, -0.378660,
0.827130, 0.562040, 0.658730, -0.358560, -0.413650, 1.397990, -0.319870, 1.649140, -8.528350, -0.996190,
-0.068240, 0.133050, 1.777640, 0.364850, -0.756790, -0.000680, -0.679190, -0.014790, -0.937330, -0.287560,
0.428020, -0.370350, -0.032170, -0.319370, 0.332020, -0.366080, -0.492460, 1.017480, 0.411420, -0.104880,
-0.832130, -2.178410, -0.893410, 0.889670, -0.025990, -0.328280, 0.217710, -0.813640, -0.116620, -0.101010,

1.784050, 0.388650, -1.439150, 1.433570, 0.721080, -0.580640, 0.222990, 1.041740, 1.339110, -1.168790,
2.386580, 0.584820, 0.065280, -0.805160, -0.086030, -0.123240, 1.863380, 0.471550, -0.304130, -0.385240,
-0.767210, -0.501350, 0.672980, -0.926370, 0.337290, -0.424860, 0.668270, -0.745460, 8.036330, -32.017559,
-0.247080, -1.506780, 0.571050, 0.153290, -0.600500, 0.404520, 0.909770, 0.688580, 0.088730, 0.011460,
0.004400, -0.854760, 0.654130, -0.204840, 0.037800, -0.693110, -1.355590, 0.414860, 0.663820, 1.011570,
0.664160, -4.288070, 0.659890, 0.032370, 1.831220, -3.234540, -0.486670, 0.717780, -0.204680, -0.313940,

6.944110, -3.749340, -14.152700, 0.070090, -0.894450, -11.227560, 1.607130, 11.910230, 1.157380, -0.640560,
8.351160, -1.984150, -1.475910, 6.113030, -1.672050, 20.145439, 9.045670, 3.203710, 4.782110, 9.588580,
-1.397280, -3.269790, 7.184860, 0.623470, 3.142880, -2.756120, -3.067400, -4.897680, -8.146950, -13.921300,
-0.008810, -1.228260, 0.854550, -3.158100, 0.834550, 3.660490, -2.217450, 4.373780, 0.190940, 1.024800,
-1.634080, -2.034510, 1.889440, 0.411680, -5.026200, 0.128240, -7.393660, 3.589990, 1.084370, -3.978520,
-2.149650, -12.605690, 0.583620, 1.284790, -1.437520, 3.026220, 2.897810, 1.031850, 2.232510, 0.940680,

-1.163130, 0.943170, 1.330230, 0.997160, -5.129000, -0.889130, -0.245490, -0.390570, 0.689780, -0.407160,
-0.991040, 0.202080, -0.514720, -0.143720, 0.113330, 1.126260, 0.490100, -0.220910, -0.003170, 0.265420,
-0.129130, 0.260260, 1.099450, -1.181880, -1.106130, 0.434760, -0.516310, 2.836490, -10.857430, 0.507460,
0.597090, 3.816530, -0.690770, -4.380670, -0.669070, 0.165860, 0.120500, -0.223980, -0.476660, -0.953280,
0.402800, -0.360640, 0.684750, -0.029150, -2.157380, -0.703410, 1.217300, 0.380960, 0.111790, 0.545860,
0.820980, -21.502119, -0.509170, -0.635310, 0.846290, 3.364010, -2.997310, 0.434580, -1.134950, 0.655140,

1.306020, 0.104260, 0.145010, -3.033940, -14.586700, -0.864910, 0.808560, 1.960870, -0.416630, -1.989780,
2.123140, 0.089130, 1.162030, -1.171620, 0.604100, -0.050050, -3.366900, -9.697690, 0.260760, 0.495530,
-1.582440, -0.181660, 0.907320, -0.580090, 0.947510, 0.448280, -0.109000, -3.840130, 1.823530, 5.025740,
2.896920, -0.558700, 0.101260, -45.119389, 0.244300, 0.203970, 2.026480, 0.854390, -0.836370, -1.113360,
-0.445380, 0.257070, -0.301390, -0.792730, 1.068780, -0.214940, 1.123730, 0.161940, -0.619870, 0.938350,
-0.535530, -4.036840, -0.661310, -0.439600, -2.193840, -0.918770, -0.652670, -0.010220, 0.081520, 0.600850,

2.187100, -2.350740, -1.652910, 1.777550, 0.852780, 0.784670, -0.577640, -0.562760, 0.159870, 0.792990,
-3.983380, 0.733580, 0.441350, 0.942070, -0.899910, -0.904530, 0.185860, 2.162460, -1.402000, -0.879970,
-0.584950, 0.770700, -0.152120, -0.416770, 0.541100, 0.455100, 0.264590, 1.067860, 4.105100, -10.012370,
0.036700, -1.290360, -0.600780, 0.777110, -0.678120, 0.323250, -0.906040, 0.376760, -0.919480, -0.622260,
-1.215700, -0.136570, 0.234330, 0.616140, -0.215150, 0.929680, 0.829260, -0.150770, 0.159390, -0.546900,
0.531510, 6.898110, -0.374570, -0.573580, 0.005940, -3.137900, -0.703990, 0.955790, 0.387470, -0.529620,

-0.003340, -0.283790, 0.812260, -0.476090, 0.335910, 0.512500, 0.513280, 0.638010, 0.122240, -0.029160,
3.249660, -0.264950, 0.058760, 0.402310, 0.354180, -1.330730, -1.276720, -0.111070, 0.690670, 0.087030,
-0.919340, 0.111700, -0.043510, -0.706670, -0.026150, -0.363610, 0.689750, -0.331300, 1.918470, 4.310590,
-0.423710, 0.516260, 0.476720, -3.332060, 0.557820, 0.250300, 0.807570, 0.060880, -0.051000, 0.457030,
0.116980, -0.657440, 0.035870, 0.832100, -0.003640, 0.146670, 0.523890, 0.021750, -0.096610, -0.404790,
0.087190, -1.732220, -0.515660, -0.515250, -0.310080, 1.107910, 0.569660, -0.570560, 0.728430, 0.580190,

0.796780, -0.522930, 2.071810, 0.171960, 1.004620, -0.519090, 1.174640, -1.521940, -1.102990, 0.162200,
-0.008640, 0.880190, 0.029190, -0.100460, -0.718210, 1.402140, -1.598150, -0.831740, 0.781820, 0.653980,
0.556190, -0.281260, -1.225950, 0.713740, -0.158370, 0.723640, -0.034310, 0.821010, 3.393610, -0.034110,
0.043070, -1.194330, 0.542450, 1.389080, -0.473420, 0.465370, 0.022140, 0.776320, 0.072890, -0.946670,
0.776500, -0.177680, 0.823660, -0.686020, -0.450700, 0.605280, -0.861230, 0.241860, 0.830940, -0.364290,
-0.980980, -3.005290, 0.136510, 0.418120, 0.594920, -1.367120, -1.053450, -0.266140, -0.104880, -0.675510,

-0.276130, -0.387440, 0.308200, -0.453050, -0.806970, 0.029990, 0.382560, -0.277970, -0.778440, -0.335120,
-0.813940, -0.424540, 0.141250, -0.450740, 0.880170, 0.838490, -0.063180, 0.168650, 0.721480, 0.032660,
0.626900, 0.115760, -0.575620, 1.056010, -0.583260, -0.243170, -0.348590, 0.644620, -5.551600, 6.163760,
1.083460, 0.969010, -1.287930, 1.358230, -0.826610, 0.043760, -0.774700, -0.560120, -0.796090, 1.038000,
0.712340, 2.048630, -0.472410, -0.303200, 0.412560, -0.341910, -0.927290, 0.397370, 0.581210, 0.086670,
0.185270, 3.122380, -1.049450, 1.029970, 1.277760, 10.734450, -0.838010, -0.538220, -0.593470, -0.954620,

-2.951180, -1.877740, 1.050390, -2.032760, 0.565490, 0.252530, -1.067360, 0.306700, -0.635260, -0.677300,
-0.705630, -1.123640, 0.353360, 0.134840, 0.329340, 0.460400, 0.298850, -0.990480, 0.535600, 0.010460,
0.650160, -1.361630, 1.041690, 0.263660, -2.756600, -5.840410, 0.808840, -0.916080, 0.019930, -0.864520,

-0.144330, -0.682060, -0.390220, -2.844310, -0.780550, 0.560910, 1.218460, 0.298630, -0.950280, 0.260190,
-1.046780, 0.478110, 1.246960, 0.164750, -3.298580, -0.641900, 0.158930, 0.832130, -0.654230, 0.736340,
-0.615020, -0.596530, 0.309280, -0.422440, 1.057530, 1.924170, -1.368050, -0.539000, -0.264670, -0.185180,

2.078170, 0.944070, -0.301890, 2.381400, -0.990680, -0.248950, -1.079130, -0.335260, 0.650440, -0.248010,
1.358180, 0.993360, -0.164940, -0.925740, -0.308460, 0.649860, -0.281090, -0.076130, 0.842170, -0.553200,
0.785810, 1.176540, -0.625150, -0.496700, -1.113970, -1.774470, -0.359820, -0.942630, 0.222900, 0.733320,

-0.630340, -3.096200, 0.149960, -2.623580, 0.668670, 0.729070, -0.870000, 0.587380, -0.160330, -0.369410,
-0.981640, -1.247010, -0.672440, 0.805260, 0.363890, 0.613970, 0.745400, -0.202400, 1.143470, 0.361210,
-0.393970, -2.534290, 0.896200, -0.887080, -3.788100, -9.825110, 1.257830, 0.332420, -0.468780, 0.367580,

-1.024680, 0.482410, -1.549150, -2.554530, -0.079540, 0.939410, 1.135090, 0.346720, 0.494060, 0.857540,
-0.824990, -0.264010, -0.285780, -0.572890, -1.310470, -0.655370, 0.755690, 0.641810, -0.090960, 0.487090,
-0.870990, -1.103890, 0.431850, -0.297150, 1.094680, 2.459260, -3.757500, -1.147870, -0.684020, 1.037630,

0.996800, -0.105510, 0.385450, 2.869080, -0.372090, -0.960150, -1.653760, -0.639610, 0.230200, -0.380810,
1.162700, 0.805530, 0.477770, -0.500830, -0.235370, -0.560800, -1.065000, -0.218770, -0.822140, -0.271280,
-0.616840, 2.512190, -0.644990, 0.824170, -1.103760, -0.774760, -0.803370, 0.627990, 0.759390, 0.137530,

0.857310, -3.458880, -2.271070, -2.082840, 0.187040, 0.509320, -0.985470, 0.699580, -1.033080, 0.612020,
-0.944560, -0.946750, -0.348420, 1.065890, 0.167400, 0.714500, 0.939130, -1.323410, 0.500580, 0.416660,
0.767130, 3.417640, 0.094110, -1.166500, -1.037270, -9.557220, 0.707790, -0.142690, -0.550880, -0.534540,

-0.141670, 2.017030, -2.626200, -1.863160, -0.868180, 0.686230, 1.165080, 0.640600, -0.377970, -0.726840,
-0.587030, 0.968810, -0.261670, -0.855240, -1.131480, -0.620190, 0.982220, -0.391760, 0.305590, 0.189320,
0.736780, -9.074930, 0.754860, -0.659000, 0.308740, 2.012010, -4.641780, 0.546440, -1.053950, 0.470680,

-0.220610, -1.687440, 1.800810, 1.870860, -0.262030, -0.779660, -1.310770, -0.824900, -0.718650, -0.894920,
0.659200, 0.801140, 0.915150, 0.332120, -0.201560, -0.760560, -1.276940, 0.840710, -0.464710, -0.262610,
-0.296470, -2.937930, -0.780750, 0.428990, -0.152410, -1.354280, -1.113080, 0.026630, 1.256600, -0.278240,

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
      0.0, -0.109900, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, 0.233930, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, -0.142070, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, -0.481720, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.702170, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, -0.154270, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, 0.594100, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, -0.224600, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, 0.270570, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.550180, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, 1.016940, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.521020, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.902050, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.847440, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.602290, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 0.599630, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.570940, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.674310, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, -0.918680, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 0.394520, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.399630, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, 0.316280, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.782130, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, 0.537240, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.548380, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, -0.369420, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.669040, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 0.518830, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.681440, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -0.992200, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, -0.154200, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.242290, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, 0.413880, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.214860, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.025620, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.362720, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.417650, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.298570, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.870730, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, 0.976020, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.964350, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.523320, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, -0.204550, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.938590, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.599850, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, -0.173750, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, -1.095550, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, -0.677030, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.302940, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.507360, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.863540, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 0.287240, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -1.025400, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, -0.082950, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, -0.525790, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -1.178410, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.677160, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, 0.788440, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.489270, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.331600, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, 0.745690, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.571860, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, -0.789350, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, -0.995070, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, 0.279810, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, 0.266360, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.229470, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, 0.594110, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.965160, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.01815, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.00000, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.00951, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
0.00000, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
0.19250, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.00000, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
1.12030, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
0.20974, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
1.42422, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
1.42779, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.01588, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.91568, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.00028, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.41968, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
0.57988, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.26503, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.06729, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.12208, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
1.42616, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
0.93290, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
0.48369, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
0.11746, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.11618, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
1.42809, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.29189, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
0.35938, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
1.36684, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
0.29873, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.00913, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.00000, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.18024, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.00067, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.37904, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.00000, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
1.00247, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
1.05515, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.01843, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.12073, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.97044, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.99475, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
0.68622, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
0.93321, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
1.18248, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.05885, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
1.27788, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
1.16409, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.02176, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.57125, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
1.11013, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
1.24669, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
1.42803, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.00786, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.05100, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
1.42848, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.00004, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.00247, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
0.47157, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
1.37196, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.98411, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.60981, 0.500000, 2,
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
