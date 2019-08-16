/*********************************************************
  EL_2.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:13:52 2004
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
-0.508200, 1.044520, 0.725660, 0.496300, 0.260360, 0.440760, 1.012270, 0.379210, 0.422490, -0.738320,
-3.449060, 0.528900, -0.108580, 2.034910, -1.064890, -2.581120, 2.223720, 0.695830, 0.640310, -0.135530,
0.455050, 0.718470, -5.940170, 0.731110, -0.075900, -0.529860, 0.010770, 1.911080, 4.231990, -0.578100,
0.317740, 1.840150, 0.367960, -0.568270, -0.056630, 1.302730, 1.770770, -3.121430, 0.121140, 0.278580,
-2.786050, -1.937250, 0.249960, 0.831580, -0.137670, -0.020580, -0.031210, -1.214180, -0.018510, 2.445100,
0.103890, -0.460420, 1.268880, -1.982950, 1.029060, 1.593200, 1.796720, -0.635070, 0.568930, -8.036350,
0.452460, 0.291600, 3.031070, 0.630030, -1.976420, -9.740260, 0.478870, -1.379550, -2.361400, 0.263200,
-0.213160, 3.569530, -0.538020, -0.497050, -1.961280, -0.476110, 0.771090, -0.827510, 0.260630, -1.962200,
0.567210, -2.010510, 2.177110, -5.178960, 0.631900, -1.167140, -0.094130, -0.208350, 0.239590, -2.330500,
-0.284870, 1.171760, -0.841000, 0.085570, -3.049080, 1.457960, -0.184020, -0.754430, -1.840630, -2.267330,
-2.131280, 2.592310, 2.803160, -1.581400, -0.961420, -5.307690, -0.494900, -0.716590, 0.555500, 1.203420,
1.147190, -0.092910, 0.843080, 1.157930, 0.982010, 0.684040, 0.468940, 0.090770, -0.613990, 2.687020,
-1.870580, -0.086440, 0.334510, 0.101020, 0.186830, -0.126800, 1.287570, -1.500920, -0.392600, 0.803490,
1.709450, -0.691650, 1.855540, 0.099980, -0.251520, -0.678100, -0.840270, -0.020240, 5.815710, 1.230700,

-1.079760, -2.289680, -0.688950, -2.384870, -0.465170, -0.150870, -0.055360, -1.270120, -1.117830, 0.189680,
1.490550, 0.531540, -1.532850, 0.932010, -0.053280, 0.283610, 0.629940, 0.194390, -0.204200, 0.805120,
-0.587520, 2.765990, -3.507830, -0.996490, -1.412170, -1.583740, 0.695510, -0.206520, -0.637040, -0.790980,
-0.912200, -1.466730, -0.080150, 0.369200, 1.535490, -0.458940, 0.774200, -0.151550, 0.237130, -0.309010,
0.239470, 0.282060, -0.382930, 1.108300, -0.367690, -6.457210, -0.127160, -0.096940, 9.422550, 0.117530,
0.007060, -4.472910, 1.027090, 0.848800, -1.820360, -0.567640, -0.984460, -0.743920, 0.481950, -1.048600,
1.735530, 0.065230, 0.431670, -5.665950, -1.640110, -1.329630, 3.075910, -0.422110, -1.767470, 0.853340,
0.297020, 0.950740, 0.182070, -0.958820, 0.371520, -2.357500, 0.854490, 1.589570, -0.395640, 0.344720,
-0.764910, -0.976600, 1.233570, 0.174510, 0.411910, 1.491270, -0.214180, 1.407040, 1.616650, 0.420330,
0.050940, -1.108960, -1.997440, 0.437800, 0.664050, 0.127260, -0.130750, -1.077270, 1.328710, 1.299460,
0.020040, -1.112130, 3.532310, 7.568070, -24.713360, 12.438740, -20.839809, 13.176730, -1.912590, -1.245880,
0.241450, -0.036770, -0.959630, -0.527170, 1.188910, 0.983210, -0.426470, 0.549990, 0.399960, 0.541400,
-0.197690, -0.171610, -0.793900, -0.626730, 0.651680, -1.513010, -0.233500, 0.068670, -1.250610, 0.492840,
2.041190, 0.323920, 0.295010, -0.445150, 0.252490, -0.721990, -1.256100, 0.373190, -1.919060, 5.531430,

-0.949360, -0.071700, -0.344670, -1.802400, -3.704400, -0.969340, 0.025630, 4.234150, -0.114550, 0.706280,
-1.020190, -0.160080, -0.173540, -2.488930, 0.415400, 0.471960, 1.796850, -0.525370, 0.732590, 0.278740,
-0.829510, 1.116560, -2.538890, -0.716830, -0.722020, 0.171230, 0.010250, -0.078760, 0.060240, 0.472320,
1.795380, -0.287960, -0.076930, -0.910120, 2.375720, -0.296060, 0.249470, -0.482850, 0.873730, -1.930460,
-0.045520, -0.488400, 1.061660, 0.479040, 0.598570, -1.671630, -0.521150, 0.227790, -0.012080, -0.086010,
-0.437780, -0.401030, -0.223490, 0.552600, 0.556070, -0.130040, 0.027510, -0.980800, 0.237010, -0.363550,
3.689470, 0.712030, -0.079700, 2.606980, -1.129340, 0.536970, -7.084440, -0.319010, 0.262460, 4.823540,
1.844650, 0.487680, -5.730430, 0.698820, 0.247020, -2.816570, -0.880680, -0.443830, -1.260450, -0.461560,
-1.115010, -7.836570, -2.721840, 0.084610, -1.059030, -0.012410, -0.960310, 0.765790, -0.764590, -0.647340,
0.737960, -0.319300, 0.826540, -1.402050, 0.596400, -0.252740, -2.418700, -1.313320, -0.185340, -2.658170,
-0.739510, 4.392130, 5.922500, 3.386280, -1.244070, -4.968240, -2.158370, -2.082710, 3.644470, 3.995340,
-4.562690, 1.228180, 1.427310, -10.697680, -0.715350, -0.970140, 0.157120, 0.232280, -0.303470, 0.700120,
0.539830, -0.906070, 0.167910, -0.089690, -0.668390, 0.509090, -0.251060, -0.639660, -0.090970, 0.519000,
1.130580, -0.675180, 0.474320, -0.248370, 0.428250, -0.158120, 0.332530, 0.272230, -0.561970, -2.432290,

-1.443570, 1.570990, -0.440190, 0.572060, -0.989980, 0.244030, 1.522640, 0.341800, -0.053480, -1.028480,
-0.813490, -0.756320, 0.001700, -0.103990, -0.660010, 0.254050, -0.049370, 0.277880, 0.826210, -1.517040,
-0.736890, 0.475230, 0.506370, -1.121070, 0.256970, 0.517900, 0.752320, 0.296900, 0.756320, -0.202760,
-0.687650, 1.294190, 0.110350, -0.176020, 1.309280, -0.355390, 0.214570, -4.139390, -0.833560, -1.580150,
-0.834130, 0.145730, -0.951590, 0.461450, -0.717130, -1.131270, -2.820130, -1.522090, -0.774120, 0.320180,
-2.044020, -0.317020, 1.805610, -1.976000, -0.464860, -0.777480, -1.700330, -1.058650, -1.425220, 0.038220,
0.644820, 0.774630, -1.295050, -0.562900, -2.866480, -2.656550, 0.272150, -2.842150, 1.120300, -0.571490,
1.246720, -3.038180, 0.158530, -0.712990, -2.184040, 0.558300, -1.078460, 0.153520, -0.481200, 7.413610,
1.861120, 0.138390, -1.050080, -6.409390, 1.008620, 3.751960, 2.975170, -0.565230, 6.428990, 0.297250,
0.791980, -7.882250, -1.756570, 0.467470, -7.532790, 0.219750, 0.833160, 2.397150, -3.926550, 2.083700,
-0.796990, 0.864360, -1.174200, -1.992470, 0.612550, 3.555710, -2.303650, -11.628250, -2.754180, -1.252480,
-0.439620, 0.060710, 1.095420, 0.301100, -0.429790, -0.336290, 0.838510, 0.197700, 0.912670, 1.056400,
0.289610, 1.328170, 0.310860, 0.624990, -0.423870, -0.907010, -0.826870, -1.651970, -0.656250, 0.604630,
-0.082360, 0.524960, -0.788510, -0.177580, 0.787820, 0.354140, 0.854800, 1.170560, 3.318600, 6.244450,

-0.419400, -2.020930, -0.189670, 0.174490, -0.265410, 0.975470, -1.487570, 0.667560, -0.292240, -0.247940,
0.103600, -0.129930, 0.024340, -2.699710, 0.216560, -0.136550, -0.928210, -0.666960, 0.621840, 2.577600,
-0.049410, 0.830810, 1.832620, 1.040880, 0.456800, -0.068500, -0.761870, 0.569940, 3.806760, -0.145330,
0.818150, 2.702540, 1.888770, -0.375460, -1.289650, -0.061540, -0.702560, -2.405780, 0.465990, -0.178640,
-2.492380, 0.303720, 1.091590, -5.509150, -0.352340, -0.326900, -7.502270, 0.207680, 0.816610, 0.571030,
-0.006390, -0.639740, -6.425590, 0.662000, 0.373510, 1.101630, 0.332470, 0.259510, -5.844220, -0.248650,
0.258080, -2.462270, 0.870560, 0.634880, -11.424840, 2.090120, 1.284340, -1.071910, 0.369040, -0.126600,
1.316820, 0.152800, 1.091020, -4.750710, -0.177000, -0.125200, 0.689800, -0.495040, -0.901720, 1.048370,
-0.858280, -0.549500, -3.912880, 0.797920, -0.004390, 0.767560, -0.950950, -0.134830, -0.752770, -0.390650,
-1.368260, 2.150910, 0.990230, -0.477160, -0.169100, -0.211710, 1.143770, -1.808780, -0.258340, 0.011600,
0.358150, -0.395430, -0.593630, -2.546020, 2.867870, 3.813850, -0.059130, 1.162370, 1.306500, 1.470920,
0.039350, -1.556070, -1.985360, 0.124570, 1.243630, 0.604330, -0.632620, -0.615450, -1.326510, -0.815670,
-0.012900, 0.335540, -0.542220, -0.649290, 0.704090, -0.197510, -1.275270, 0.307940, -1.328590, -0.957480,
0.088540, 0.563010, 0.508650, -0.817780, 0.771430, 0.707070, 1.462390, -0.975850, -1.290010, -6.904940,

-1.645740, 1.442430, -0.374580, 0.597300, -0.297030, 0.117810, 3.049030, 0.245560, -0.243910, 0.573410,
-0.551110, 0.336180, -0.146470, -0.113520, 1.075320, -0.862720, 0.446860, -0.618210, 1.926480, 0.180390,
-0.753300, 0.197370, 0.366970, -1.670080, -0.207060, -0.920660, 0.631170, -1.027810, 1.156900, -0.245140,
2.310500, 0.356170, 0.491570, -1.014550, -1.093450, 0.808740, -0.690030, -0.209330, -0.210900, -2.576650,
2.322380, -0.122850, -1.170060, -1.403040, -0.683890, -7.679110, -1.056590, 0.570440, -1.295990, -1.961150,
-0.414260, 2.149070, 0.456430, -2.188940, -0.478100, -1.210810, -0.239780, -1.225360, -0.819350, -2.119400,
0.792780, -0.681510, -0.833540, 3.691740, 0.346240, 0.136360, -0.598570, -0.909180, 0.321900, -1.528220,
0.593300, -0.283540, -0.102950, 0.717470, 1.099740, 0.540060, -0.923480, -0.533050, 0.825060, 2.763510,
-0.249750, 2.366690, -0.907190, 0.204010, -0.247860, -2.804850, -0.772920, 0.906460, -0.474010, 1.131770,
-1.817260, -0.917130, -0.284870, 0.323210, -1.408640, -0.415010, -2.028860, 0.404510, 0.317700, 1.208590,
-2.594670, 0.289870, -0.038200, 6.006420, -0.978600, 2.471460, -0.588710, -1.626650, 0.293320, 0.010590,
0.415330, 0.672120, 1.159030, 0.618450, 0.870650, 0.882540, -0.866510, 0.484560, 0.373490, -0.542770,
-0.798740, -0.674810, 0.892470, 0.935900, -0.378380, 0.097020, 1.563700, -0.422440, -0.407610, 0.708740,
-0.085650, 1.007320, 0.072350, 0.052860, 0.635390, 0.267800, -0.480740, 0.626080, 4.361920, 1.232020,

-0.699350, -0.624740, 0.096940, -0.394450, -0.185210, 0.393820, 2.824610, -1.386380, -0.774170, -0.066790,
0.400100, -0.076140, -0.045600, 0.619010, 0.818720, -0.435230, 0.452210, -0.190970, 1.136670, 0.431270,
0.009430, -1.033230, 0.235040, 0.051160, 0.513020, 0.970170, 0.893630, 0.474010, 0.892730, 0.512550,
0.486440, -2.589350, -0.783580, -0.565260, 0.483780, 1.358490, -1.406930, -0.962870, -0.110580, 0.065380,
0.876320, -0.762220, 0.072820, -0.044430, 1.947400, -3.688090, -0.614490, 1.130330, 0.438260, -1.909170,
-2.900860, -0.632760, -2.047830, 1.660830, 0.422090, 1.098000, -5.047130, -0.139770, 0.551790, 1.620060,
0.544390, -6.211760, 0.204530, -1.943420, 2.935780, -0.129170, 0.132960, 0.778500, -0.834060, 2.041630,
-1.153110, 0.513350, -0.110940, 0.194140, 0.325350, -0.714080, 7.338420, -0.485560, 1.985900, 2.690550,
0.982720, -0.857260, 5.332960, -0.367820, -0.477180, -0.503990, 0.497980, 0.058860, 0.287700, 0.340650,
4.290690, -1.690900, 0.676880, -1.045160, -3.647530, 1.695250, -0.734860, 4.156110, 0.015610, -1.158840,
1.247740, 0.986090, -5.450440, 1.917580, -3.151230, 0.120520, 3.497960, -2.148960, -3.743650, -0.860920,
-1.813480, 1.704270, 0.636710, -8.152120, 0.614780, -0.788160, -0.054680, 0.186360, -0.536500, 0.199340,
-0.289470, -1.686370, -0.253070, -0.442450, 0.667380, 22.120211, 1.208460, -0.731560, -1.399710, 1.815260,
0.773880, -0.181990, -1.324990, 1.628240, -0.807590, 0.281430, 0.204570, 0.203160, -0.153490, -2.465250,

-0.476240, 0.935280, 0.069700, 1.409710, -0.027250, -1.090740, 3.954600, 0.762940, 0.827040, -1.435860,
0.403580, -0.297600, -2.239720, -0.132130, -0.576400, 1.229910, -0.166280, 0.623990, 2.701270, -1.185010,
-1.000040, -2.502510, 0.199750, -0.091390, 1.417350, -0.142920, -0.809010, 3.102210, 0.205770, 0.125940,
2.024680, -0.169610, -0.484510, 1.011230, -0.192010, 0.240120, 3.406470, -2.248010, -0.525690, 0.476770,
-0.174320, 0.240470, 0.858030, 1.960790, 0.610810, -0.192930, 0.921640, 0.140130, 0.240690, -0.647920,
-1.165670, 1.167260, -0.462620, 0.518510, 2.855180, 0.327970, -0.694500, 1.034350, -0.130910, 0.564480,
1.823020, 0.198830, 0.655980, -0.185810, 0.993900, -0.725350, -0.904690, 0.167280, 0.614060, 1.587330,
-1.288770, 0.015390, 0.564310, 0.117170, -0.252160, 0.486300, -0.503880, 1.007410, 1.335930, 0.635750,
-0.470780, -0.099040, 0.116370, -0.216110, -0.084290, 0.674160, -0.113430, 0.996990, -1.147130, 0.934600,
-0.031940, 0.047950, -0.195580, -0.671540, 0.160730, 0.500630, -2.526380, 1.255990, 0.592670, 2.598780,
0.943930, 0.320060, 0.210610, 0.592140, -2.192650, -3.222090, -3.676790, -1.707900, -0.930080, 0.876590,
-4.460290, -0.699840, 6.000290, 5.066760, -1.100230, 0.539070, -0.168040, -0.583940, 1.007040, 0.942770,
-1.357040, -0.769870, -0.289600, -0.779430, -0.313040, 7.357600, -1.193520, 2.442110, -0.538010, 0.365070,
-1.149170, -1.697390, 1.064620, 0.557570, -0.449960, -0.942980, -2.879720, 1.066390, -0.247980, -4.405690,

1.363200, 0.896610, 0.678770, 0.936130, -0.358640, 0.983830, 0.916800, 1.504680, -0.563300, -0.185580,
-0.024310, -0.076920, 0.728850, -0.340940, 0.123160, -0.692530, -0.070070, -0.477150, 0.763550, 0.607100,
0.827430, 0.656490, -0.487020, -0.249120, -0.875960, -0.164520, -0.074870, -0.787700, -0.442070, -0.698660,
0.498770, 0.766040, -0.195100, 0.271810, -0.212320, -0.567420, -0.492690, 0.791050, -0.537800, 0.254330,
0.851220, -0.272120, -1.370690, 1.943460, -0.197460, 1.383710, 2.775660, -0.119860, 0.827370, 1.206480,
0.028880, 0.718010, -0.469990, 0.667460, -0.608040, 3.594750, -1.506230, 0.735220, -0.189650, -0.909290,
0.652830, -0.357730, -0.514600, -1.727550, 0.631230, 0.890370, 0.971580, 0.575100, 0.925460, -0.209390,
-0.019940, -1.008310, -0.291780, 0.746840, 0.410130, 1.150990, -1.879550, 0.433240, 0.177910, 0.663110,
-0.627480, 0.658370, -0.618570, -0.278290, 0.063000, -0.061610, 0.137880, -0.692630, 1.607540, -0.676980,
0.128530, 0.897600, 0.432360, 0.625080, 1.534260, 0.128810, 1.140790, 0.132440, 0.644980, -0.296970,
1.431790, -0.483800, 0.712130, -2.301260, -4.140930, 0.772470, 2.063100, 2.413830, 3.160360, 0.802060,
1.889140, 0.134360, 2.240190, -6.451820, -0.828850, -0.124940, 0.174990, 0.379590, -0.800240, -0.087000,
-2.440560, -0.083250, -0.099770, 0.133650, 0.218770, 2.045560, -0.986660, -2.230280, -0.117110, -0.115770,
-0.468980, -0.435220, -1.079950, 0.767830, 0.833750, 0.111420, 0.129820, -0.791230, -3.155770, -2.581590,

-0.005050, 0.799210, -0.893410, 0.381300, -0.231810, 1.297330, 0.412880, -1.247960, 0.498630, -0.733100,
0.826810, -1.079090, 0.524850, 0.572560, 0.703990, 0.166440, -2.525340, 0.304600, 0.541340, 2.255090,
-0.469900, 0.325590, 0.106080, -0.005130, 1.293950, 1.331830, -0.751660, 0.177660, 1.594980, 0.383900,
0.412570, 0.189550, 0.157190, 0.565240, 0.963280, 1.122480, -0.918930, -0.221580, -0.601660, 0.584200,
-1.417220, 0.721720, -1.188350, -0.620040, -0.483360, -0.672890, -1.233030, 0.451950, 0.465520, 0.237700,
0.394190, -1.376220, -2.900970, -0.970350, -1.371190, -0.103840, 1.850790, 0.238140, -0.230550, -0.114290,
-0.204490, 0.314220, -0.404200, -0.018790, -3.264940, 1.260380, -0.368190, 1.029890, -0.530750, -0.870760,
-3.028860, -0.545770, -1.019270, -0.523590, 1.063500, -0.206300, 0.704610, 0.171730, -0.898340, -1.124400,
-1.667570, 0.188480, 0.359450, 0.544190, 0.436740, 1.316040, 0.209230, -0.425610, -0.615710, -0.897390,
-1.039850, -0.129310, -0.224400, -0.728980, -0.934600, -1.117360, -0.490720, 2.113790, -0.171490, -0.433900,
-0.989540, -1.611910, 2.797350, -0.247720, -0.123290, -2.139550, 1.343180, 1.510480, 1.482960, 0.346110,
-0.025020, 0.202530, -1.946450, -0.144000, 0.132690, 0.062330, 1.336150, -0.240860, 0.074800, -0.418340,
-0.894890, 0.485650, 0.484670, 0.685540, -0.575840, 0.865730, -1.047980, 0.644980, 0.490980, 0.486480,
-0.407880, -0.729380, 0.126050, 0.681020, 0.197590, 0.962370, 0.732940, -1.021840, 1.612130, -5.373160,

-1.700880, -0.495190, -0.062730, -0.291440, -0.018500, -1.117990, -0.118260, -0.602060, -0.346570, -0.391830,
-0.474680, 0.118790, -0.590690, -0.310500, -0.632620, 0.679350, -1.057380, 0.160610, -0.300250, -0.667870,
0.682940, 0.219770, 1.186910, -1.112810, -0.437410, -0.222440, 0.923080, 1.726190, 1.932300, 0.125470,
-1.823560, -0.814660, -0.975620, 0.384500, -0.167720, 0.188200, 1.442680, 0.371190, 0.657250, 0.991460,
0.090140, -1.029740, -1.392790, 1.107190, -0.180640, 1.443650, -2.916200, 0.518230, 0.392250, -0.285680,
0.278090, -0.516450, 3.528220, -0.947450, 1.587310, -3.429450, 0.527390, -0.226730, 0.996090, -1.326550,
-0.743280, 0.820850, 0.516070, -0.138740, 0.666240, -0.913890, -0.138070, 0.789900, -0.477710, 1.109570,
-0.556170, -0.677580, 0.053030, 0.435900, -1.407850, -0.727290, -0.283200, 0.205000, 0.752600, -0.104980,
0.222310, -1.252600, 0.698640, -0.523730, -0.568220, -0.713900, -0.653940, 0.267140, -0.799560, -0.296430,
-1.539010, -0.654390, -0.408560, -0.406950, 0.234870, 0.469110, -0.331930, 1.327560, -0.375140, -0.117360,
-0.994110, 0.273370, 0.721880, 1.214080, -0.572890, -1.271100, -0.814900, 2.823470, 1.601570, 1.141710,
0.761710, -0.340340, 2.439910, -0.819070, -0.779120, -0.108420, 1.044470, -0.396330, -0.439850, 0.114900,
0.517520, 0.362160, -0.274560, 0.156630, -0.763090, 0.230880, 0.371780, 0.170510, 0.251250, 0.466340,
-0.062240, -0.173920, 0.152120, -0.015930, 0.116930, 0.373390, -0.956790, -0.131840, 0.085660, -1.061500,

-0.494620, 0.086330, -0.391640, 0.015680, 0.484520, 0.196870, 0.452850, 2.515340, -0.170090, -0.804090,
-2.097850, 0.061990, 0.627220, 0.458820, -0.798180, -0.543470, 0.949660, 0.761390, -0.123670, -1.403770,
0.628940, 0.671500, -0.478220, 0.017150, 2.297360, 0.276070, -0.085320, -0.630250, 1.377270, -0.373060,
-3.206120, 0.590920, 0.809950, 3.055510, -1.011400, -0.165260, 0.014270, 0.588190, -0.025160, -1.511070,
0.605160, -1.010810, 3.447330, 0.573610, 2.040940, -0.361470, -0.161300, 0.097020, 0.747200, -1.285660,
1.103760, -4.086530, -1.122240, -4.535950, 0.851340, -0.239390, 1.794880, 0.859850, 0.288000, -2.042240,
-1.320660, 0.136970, 0.786690, 0.350650, 0.355240, 2.354750, 0.266360, -0.690990, 0.019460, 1.990630,
0.289680, 0.295850, 0.807170, -1.071620, -0.575270, 0.160680, 0.281020, -0.460990, -2.360200, -2.852900,
-0.525580, -0.484870, 4.100590, -0.604200, 1.037340, 0.026210, 0.550700, -1.004120, 0.152360, -1.530850,
1.160610, -1.371380, 0.921470, -1.243260, -1.873400, 0.784290, 0.356670, 3.244940, -0.902050, 0.239120,
-2.959350, -2.452890, 4.176430, -2.693250, -4.135610, 19.959999, -10.011200, 20.324770, -5.905910, 0.861670,
0.042550, -0.858020, 2.706660, -0.829770, -1.265570, 0.310230, 0.172660, -0.374600, 0.423310, -0.110920,
-1.122890, 1.563770, 0.415710, 0.020200, -0.401770, 1.126900, -0.346980, 2.630120, 0.419290, -0.572940,
-0.621980, 0.789400, 0.065300, 0.434090, -0.566810, -0.264790, -2.370390, -1.136860, -1.750200, -0.943000,

-0.543630, 0.852720, -0.925730, 2.389900, 0.226360, -0.089110, -0.588240, -1.033230, -0.536330, 0.089850,
-0.633040, 0.962350, -0.910100, 0.087800, 0.397460, -0.907830, -0.473090, 0.878800, 0.691970, 0.542830,
0.778600, 1.282700, -0.501490, 0.275510, 0.510350, 0.622060, -0.057850, 0.961570, 0.083990, 0.080060,
-0.397590, -1.034540, 0.186480, 1.350210, 0.438750, 0.087630, -1.931820, 0.662480, -0.797780, -2.069280,
-0.105540, -0.704790, -1.283530, 0.444670, -0.025100, -2.824020, -0.129000, 0.071620, 1.316270, -0.785400,
1.066530, 8.445300, 2.010470, 0.706970, -2.405010, -0.291870, 0.853580, 3.556320, 0.784850, -0.705320,
-1.111970, -0.632940, -0.331320, -2.781200, -0.277940, -0.880630, 7.394900, -0.264510, 0.487190, -5.781660,
-0.030580, -1.007640, 4.099350, -0.105510, -0.589800, 4.582170, 0.702400, -0.845090, -3.229410, 1.448380,
-1.014100, 2.040090, -0.510560, -0.097810, 4.580190, 0.833940, 0.819500, -2.130800, -0.481120, -0.180560,
0.098620, 0.348630, 0.184460, -4.109230, -0.155750, -0.878640, 3.713200, -0.137360, -0.484160, 0.337200,
0.424240, -1.253980, -0.191120, -2.801560, -4.489000, 3.583360, -0.226120, -1.012300, -0.004330, -1.568900,
10.650700, -2.214170, -0.097030, -8.861560, -1.771650, -0.134110, 0.464190, 0.616320, 0.304980, -1.187830,
0.769170, 0.612040, 1.057410, -0.071510, 0.626620, -0.265630, -0.782960, 0.166650, -0.151090, 0.334420,
-1.391700, -0.992150, 0.280650, 0.048860, 0.056440, -0.313450, -3.366550, -0.140650, -0.926090, -5.456700,

-4.322300, -0.056390, 0.605210, 4.918910, 3.994280, -0.955380, 1.443680, 0.120790, -0.449490, -2.716790,
-2.087110, 0.520480, -0.145310, -0.525510, 3.835730, 0.671370, -0.490000, 1.392350, -0.329410, 0.077820,
-1.027640, 0.622930, 0.268050, -1.961140, -0.418150, -2.522370, 0.131180, 0.022080, 0.300260, 0.441460,
3.076390, -2.679380, -0.292080, -2.267550, -0.997940, -0.745680, -6.390790, 0.690790, 0.455760, -4.878950,
-1.576720, 1.872720, 2.429790, -1.073090, -0.922460, -0.652960, 1.604550, -2.954330, 8.086210, -0.682970,
-4.705290, -3.480180, 0.735130, 4.853870, -9.340720, -0.542420, -2.522630, 0.795170, -1.180030, 1.999250,
2.017290, -1.189900, 1.120600, -3.233090, -0.106940, 4.803650, -4.175910, -0.105000, -0.776120, -1.004250,
-0.213490, -1.502680, 5.460930, -0.493420, 0.779820, 16.078831, -0.005130, 0.890780, -2.433460, 0.270500,
-0.898950, 17.556290, 0.628870, 1.201100, -0.972460, 0.759950, -0.625430, 3.013370, -0.596250, -0.863880,
11.266130, 0.934240, 0.732160, 4.624940, -1.746530, 0.418300, -6.787700, -0.194520, -1.666090, -0.427600,
-1.841090, -3.069190, 2.213520, -0.901960, -2.710970, -1.072340, 11.610550, -5.512800, -1.927080, 3.100780,
-4.963070, 1.419830, -2.643270, -0.533190, 3.081920, 0.483980, 0.332520, 0.481150, -0.739480, 0.984350,
-0.809270, -0.469950, 0.697180, 1.917240, -0.447450, 0.301920, -0.946060, 0.207350, 0.363040, 0.775460,
2.143630, 1.439800, 1.568980, -0.109670, 0.695770, -1.984170, -1.496570, 0.369780, -2.193200, -6.057910,

-0.214170, -2.982000, 2.005130, 3.356120, 6.626290, 0.379340, 1.017540, 0.345720, -0.170530, -0.704430,
0.726780, -0.327630, -0.230160, -1.280940, 0.647180, 1.605520, 8.719520, -0.594790, -0.536350, -2.144060,
0.709780, -1.926040, 1.078320, -0.415560, -2.006820, -4.216160, 0.930040, 1.597490, -10.807390, 0.431650,
0.462140, 8.307050, 1.587510, -1.514790, 0.049250, 0.324250, 2.757500, -0.314030, -0.395490, 1.801530,
0.366850, 0.679130, -0.321970, 0.568260, 1.634250, -0.924350, 3.573840, 2.842560, -0.193330, 0.878120,
-8.008370, 0.069590, -9.305740, 6.602070, -0.241910, 2.710210, 4.116710, -0.844540, -1.033830, -1.463640,
-0.266700, 1.903480, -0.443280, -0.409930, 5.975850, 10.833730, 0.489020, 1.203700, 0.846370, -1.045450,
-4.375930, -3.255240, -0.319270, 1.936210, 10.669570, 0.062980, 11.004610, 0.509960, -0.991170, -2.372770,
-4.664780, -0.671170, 5.462510, 7.721440, -1.125390, 15.225520, 1.786760, 0.680410, -26.864269, -6.300030,
0.700470, 5.850160, -0.154760, -1.047520, 20.565929, 1.175470, -0.557770, 43.990509, -2.614170, -7.681980,
-5.372230, 1.223880, -11.165530, -1.324680, -2.044540, 1.250510, -9.944170, -0.751490, -6.488320, -4.054890,
2.547180, 1.761510, 0.470660, -15.877630, -4.326660, -1.586560, -2.463430, 2.196690, 0.355750, 3.734490,
1.684040, -0.810100, 0.220660, 0.695860, 3.455230, -4.425180, 4.058740, -6.482080, 0.318510, 1.629730,
-0.746980, 4.056140, 0.004160, 0.237690, -5.032710, 0.794060, -0.477980, -0.342130, 5.275680, 5.194830,

-1.746400, 1.579760, -0.355730, 2.635000, -0.114370, 0.918840, -0.160410, 0.225100, -0.405460, 1.902780,
-0.497940, 0.669670, -2.034000, 0.422830, -0.522420, -0.826090, 0.162540, -0.954220, 0.648350, 0.735020,
0.326690, 0.131550, -0.944280, 0.263900, -0.344890, -1.396850, 0.262140, -0.208560, 1.014240, 0.363810,
0.258470, -0.878780, 0.069570, 0.857070, 2.300980, 0.690210, -0.758150, -1.400280, -0.746970, -0.517000,
0.836320, -0.176650, -3.530570, 1.733280, 1.184780, 4.126480, 4.684830, -0.677810, -2.584880, -0.326290,
0.486340, 3.058380, -6.035960, 0.849770, -0.584350, 1.057700, 0.984210, -18.451071, -1.648340, -0.238570,
1.972930, -0.197320, -0.512200, -5.595490, -11.936780, 0.223940, -2.915150, 6.809700, 2.230890, -0.070230,
-2.715610, -0.418040, 0.992600, -6.325470, 1.187280, 0.358410, 4.542180, -0.932120, -0.174910, -2.485690,
-0.826100, 0.920290, -0.035810, 0.414980, 0.910300, 0.029730, -0.311490, -1.125120, -0.546650, 0.048440,
-1.047710, -0.004630, 0.644760, -0.127500, 1.302110, 0.111240, 0.492710, -0.876670, -0.715560, -0.238360,
-1.605150, -1.023410, -0.319660, 0.746790, 0.424200, 2.088620, 2.730230, -0.427360, -1.003750, -2.521870,
1.122480, 2.155430, -0.245680, -1.457870, 0.613420, -0.401960, -0.666620, 0.202190, 0.259220, 0.002560,
0.332570, -0.599460, -0.154450, 0.044900, -0.151120, 0.165670, 1.284180, 0.250170, -0.380550, -1.301580,
-0.907200, 0.168410, -0.892780, -0.708320, 0.285830, 0.028560, 0.228640, -0.680010, 2.281170, 2.810410,

0.398930, 0.202130, 1.037290, -0.433580, -0.719930, 0.640600, -0.955040, 0.272710, -1.918840, -0.112670,
1.697940, -1.658380, -0.061460, -2.769930, -0.705760, 0.809210, 0.044440, 0.947060, 0.818800, 2.970370,
-0.528580, 0.223510, 0.944500, 0.427200, 0.883750, 0.446880, 0.083290, 0.388890, -1.082180, 0.745760,
0.189520, 0.322490, 0.753020, 1.312010, 2.223160, -0.123570, 1.032240, 1.739530, -0.277800, 0.100740,
3.665950, 0.371790, -0.257140, -19.608900, -0.182420, 0.600870, -4.885800, 1.954350, 0.111030, 2.871120,
2.121310, -0.004920, -2.172870, -0.520160, 0.241250, -11.801840, 1.027130, 2.243370, 5.241680, 0.607840,
-1.002370, -0.035570, 1.549840, 1.900780, -4.661170, -0.263140, 0.009310, 0.805410, -0.702670, 0.669590,
-2.160950, -0.195430, -0.610630, 6.108660, 0.080380, -0.818360, 0.276330, 0.328680, 0.477170, -0.599210,
-0.284270, -0.744640, -3.830680, -1.979020, -0.874840, 1.124520, -0.343230, -0.183440, 3.579930, -0.341350,
-0.401400, -1.139380, -0.947740, 0.041500, 0.652930, 0.331210, 0.778740, 0.028930, -2.466040, 3.372210,
2.406560, -5.396950, -8.262590, 3.106300, -0.441930, 7.055110, 4.203220, -6.260720, 1.639490, -0.565960,
-2.461660, 4.711230, 1.387070, 1.580150, -0.311060, 0.308540, 0.656800, -0.670730, -1.598160, -0.822760,
0.961500, -0.431250, 0.297820, -0.876090, -0.496180, 1.402660, -0.923190, -0.096460, -0.101400, -0.044620,
0.486460, -1.359860, 0.106470, -0.155360, -0.606790, -0.964650, 0.088330, 0.528050, -0.789940, -5.542890,

2.482120, -0.525410, 0.269920, 0.425010, 1.015240, 2.200330, 1.503280, 1.134640, -0.739720, -0.471780,
-0.322130, 0.173730, 0.019110, 0.291810, -0.523230, 1.409280, 0.916780, 0.361390, -0.774970, -0.510660,
1.545230, -0.466070, 1.263980, -1.301640, 0.116130, 0.512210, -1.297630, 1.195770, -0.103940, 0.672670,
0.071820, -0.303160, 1.144390, -0.035540, -0.751920, -9.083120, -0.380640, -0.850410, -0.325090, 0.660680,
-0.090160, -1.629610, 0.340930, 1.305010, -4.004800, -0.221860, -0.196420, -4.707690, 1.231670, 1.202200,
0.861410, -3.699620, 0.514890, 0.493740, 0.774280, 1.259400, -3.075910, -1.129230, 0.935830, -1.525360,
-0.534260, -1.923090, -0.323190, -0.401920, 1.247430, 0.134850, 0.923790, -1.018620, 1.106730, -1.199660,
0.746640, -0.621540, -0.442020, -2.545360, -0.083960, -0.834740, -0.892650, -0.821490, 0.955890, -1.004070,
0.343210, -2.038060, -1.149670, -0.930890, 0.214030, -0.190720, -0.643060, 3.067720, -0.353940, -0.075580,
-3.440930, 0.691020, 0.391130, 0.201500, 0.512300, -2.128150, -0.231140, -2.430000, 0.233440, -0.127530,
-1.264870, -3.910970, -1.403490, 1.012350, 0.447760, 1.268330, 0.946450, 0.876720, -3.149490, -0.906980,
1.787570, 1.498980, -1.823180, 2.791040, -0.285130, -0.604110, 0.029970, 1.494640, 0.379830, 4.080380,
0.577190, -0.272280, -1.056300, -0.145030, -0.372790, 2.285100, -2.220720, -0.042570, -1.573890, -0.298900,
-0.072450, 0.447360, 0.052300, -0.309470, 0.479650, 1.133020, -0.544780, 0.229180, 5.947070, -1.044640,

-0.156950, -0.590930, -0.215350, 0.025520, 1.003400, 0.770160, -1.218060, -0.866380, 0.086940, 0.399190,
0.155550, 0.729550, 0.768190, 0.873430, 0.501630, -0.566290, -2.573560, -0.110490, 0.891460, 0.447140,
-0.640190, 1.093370, 0.782560, 0.207340, 0.395260, -3.741060, 0.765690, -0.564560, -0.746710, 0.791110,
1.166790, 1.643180, 0.719240, -0.768500, 0.622240, -0.235510, 0.096540, 0.547760, -0.039550, -0.664060,
0.269940, -0.379530, 0.347420, -0.864510, 1.610930, -0.595710, 0.799470, -2.257680, 1.413560, -0.089340,
0.693460, -0.015060, -0.598820, 1.606700, 0.562330, 0.283170, -2.992850, 0.715880, -0.024710, 2.029900,
-0.901640, 0.304920, -0.332410, -0.709680, -0.610600, -0.991420, -0.225800, -1.555060, 0.229720, -0.520060,
-1.102690, -0.922780, -0.712650, -0.683070, -0.230350, 0.959120, -0.429850, -0.392290, -0.180800, -0.732090,
0.217630, 0.336310, -0.936760, -0.823450, 0.450880, -0.824050, 1.060620, -0.755780, -2.221500, -0.754950,
-0.468570, 2.874250, 0.476910, -1.185460, 1.316790, -0.090800, 0.138240, 2.640000, 0.405930, -3.947440,
0.415280, -1.468770, 7.049300, -2.528940, 5.935170, 13.279730, -1.421000, -1.301850, 1.413780, 0.940840,
0.076890, 0.776630, 2.574430, 6.005670, -0.551280, -0.716220, -0.093030, -0.513550, 0.051050, 0.912030,
-1.296970, -0.499420, -0.642640, 0.932660, -0.806350, 0.073980, 1.612020, -1.708150, 0.024720, 0.598050,
-0.078030, -0.812800, -0.959090, 0.206110, 0.890130, 0.163450, -0.444590, 0.100310, 4.749930, 7.513910,

-2.265150, -0.176500, 0.157630, 0.661960, -0.900430, -0.638890, 0.831300, 1.458400, -0.906650, -0.260640,
-2.358600, -0.481480, -0.571660, -0.970420, -0.645750, 0.543060, 1.320540, 0.388010, -0.889240, -0.515330,
0.990350, 0.789300, -0.932870, -0.795460, 2.349660, 9.827980, 0.485220, -0.077770, -0.872290, -0.544330,
-0.238170, -1.460300, -0.183620, 0.779400, -1.356250, 2.111510, 0.584540, -5.870020, 0.276130, 0.011920,
0.163650, 0.969080, -0.909810, 2.133670, -0.183840, -0.708950, -2.816450, 0.758140, 1.964460, 1.925790,
-0.325390, 1.185660, 4.310830, -0.145560, 0.336760, 0.285560, -0.549060, 0.043550, 6.212440, 3.770600,
0.020400, -10.162920, -0.983420, -0.017860, -3.227500, 1.136200, -0.369140, 2.893280, 0.538230, 1.686900,
1.077570, -0.368960, 0.286050, 0.766500, 6.228940, 0.550690, 5.499710, 0.233280, 3.315170, -0.856400,
-1.301750, 0.799980, 1.209840, 2.062350, -0.871410, 3.609470, 0.083530, -0.925750, 1.550740, -3.008220,
-0.088560, -1.591060, 0.652180, -0.162990, -4.850500, -0.187140, -1.713230, -0.818380, -1.334580, 1.561610,
-1.348940, -0.472190, 4.606330, -6.277090, -11.758330, 17.495230, 5.596570, -11.591060, -1.299570, 6.788560,
-0.982050, -0.738660, -1.576060, -5.902140, -0.140690, 1.312210, 0.519510, -0.817280, 0.112630, -1.201520,
-0.760190, -0.536600, 0.316560, -0.716490, -0.127320, 4.433100, 1.242110, 1.875480, 0.427040, -0.129340,
-0.213830, 0.981060, -0.290190, 0.279280, 0.200240, -0.433590, -0.096150, -0.480680, 2.377160, 22.045429,

-0.316780, -0.283790, -1.141290, 0.658390, 0.971380, 0.253970, 0.609310, -0.132520, 0.141420, -0.938420,
-0.561490, 0.214290, -0.105310, 1.016280, 0.564610, 0.752760, 1.156560, -1.693200, 0.823840, 0.238570,
-0.032150, 0.083790, 0.456390, 0.660230, -0.741720, -0.860370, -0.075470, 0.644930, -0.226440, -0.545750,
0.469060, -0.129100, -0.010370, 0.780160, 1.177240, 0.288290, -0.475720, -2.960160, -4.249780, -0.862860,
2.524220, -0.892080, 0.414790, -0.403950, 1.284350, -0.413140, -2.399680, -1.526420, 1.857180, 4.444010,
0.278270, -1.180370, -0.086340, 0.270330, 0.920020, -2.842290, -2.520100, -0.156780, 1.456990, 1.169750,
0.025280, 0.582900, -1.141890, -1.892900, -1.074970, 0.462690, -0.585980, 0.884460, -0.621540, 0.821560,
-1.040550, -0.801770, -0.973170, 0.556500, 0.590410, -0.069000, 0.759510, -0.251080, 0.670320, -0.250240,
-0.365230, 0.260430, -0.657730, -0.328660, 0.500030, -0.067330, 0.680320, -0.227390, -0.129700, 0.493630,
-1.022280, 0.575820, 0.401550, 0.658480, 0.071320, -0.053200, 1.003450, -0.075650, 0.327320, 0.091870,
-0.580960, -1.228860, -0.064950, 1.881330, 0.688360, -0.759950, 1.915920, 0.757710, 0.303530, -2.094110,
-0.265930, 0.310580, 1.911290, -0.953080, -0.081370, 0.054670, 0.243020, -0.695440, 0.158570, 0.388460,
-1.400470, 0.521140, 0.209200, -0.920980, -0.167230, 0.605680, 0.456800, -0.374340, 0.740880, 0.759970,
-0.598300, -0.568880, -0.893930, -0.199660, 0.130640, 0.751770, -0.426390, 0.169010, -0.093440, -3.990690,

-1.184410, -0.843870, 0.495880, 0.286750, -0.032740, -0.123970, -1.658450, -0.176090, -1.134320, 0.280030,
0.091850, 0.644090, 0.766220, 0.430950, 0.355300, -0.702780, -0.576720, -0.190310, -0.038970, 0.924870,
0.634780, 0.384780, 0.712950, 0.524170, -1.064530, -1.194880, -0.834740, 0.336550, 0.699590, 0.022170,
-0.668890, -0.925940, -0.014950, 1.502130, 1.414380, 0.640280, 1.467730, 0.667950, 0.094050, -0.649480,
-2.596260, 0.440020, 0.405910, -0.304160, 0.008400, 2.558470, -0.900840, 0.701970, -0.581850, -2.593180,
-0.524270, 1.607320, 0.711250, -0.165460, 0.905940, 0.707430, -0.041180, -0.560560, -0.952890, -0.621660,
-3.728770, 2.270300, 0.100370, 1.603840, -0.557120, -0.553600, -0.151920, -1.159990, 0.065800, -0.201490,
0.572500, 0.471580, 0.581440, 1.010440, -0.819750, 0.173700, -0.033480, -0.935510, -1.174350, 0.043230,
-0.045380, 0.616920, 1.088490, -0.661800, 0.097640, -0.112150, -0.466120, 0.007440, 0.949010, 0.544150,
0.960600, 0.578060, -0.760200, 0.325800, -1.035540, 0.239770, -0.265880, 0.244170, 0.732200, 0.278620,
0.943170, -0.466010, -0.976420, -0.056330, -1.490610, 0.229050, -1.285690, -0.115990, -1.728620, 0.041430,
-2.665290, 1.205270, -2.312460, 5.237500, 0.393370, 0.825570, -0.034000, 0.329720, 0.476210, 0.781310,
0.213860, 0.535480, -0.569330, 0.158880, 0.016540, 0.293910, -0.722240, 1.112980, 0.090600, 0.235050,
-0.889010, -0.045870, -0.040080, -1.058550, 0.299450, -0.850600, -0.032270, 0.104110, -0.168820, -3.718140,

2.403610, -1.480780, 0.754170, -0.236140, -1.188580, -0.354050, -1.714930, 0.265460, 0.628380, -0.666950,
0.405070, -0.117020, -0.620390, -0.372600, 1.253210, 0.444920, 0.650700, -0.721110, 0.974270, 0.127870,
-0.549280, 0.236320, 0.011110, 0.122250, 1.019980, 1.878860, -0.226740, 0.325700, -1.528180, 0.749740,
-0.104040, -0.193450, 0.255470, -0.483260, 3.504100, -1.153570, -1.002690, -2.295380, -0.675340, -0.390150,
-0.596340, -0.524890, 0.296650, 1.995130, -0.500450, 0.267320, 1.364850, -0.725700, -1.142590, 1.669110,
0.064800, -0.005140, -0.714890, -0.882650, -1.446960, 0.945970, -0.287890, 0.743320, 0.674640, -0.702790,
2.065280, -0.257250, -0.136700, -0.950740, 0.198140, 0.220300, -0.280600, -0.077380, -0.298980, 0.541480,
0.704290, 1.240960, -0.230310, 0.937570, -0.317660, 0.022480, 0.114030, -0.244500, 0.691160, 0.633310,
1.248720, 0.407610, -1.649930, -0.468300, 0.135770, -2.332490, -1.015650, 1.514960, 1.127530, -0.001870,
0.420360, -0.646330, 0.286240, -0.343810, -0.678170, 0.406090, -3.303110, 1.417200, -0.068340, 0.162440,
-0.332650, -0.508770, 0.647320, -4.073200, -0.687450, 1.624130, 4.062200, -1.287310, -3.247520, -1.039090,
1.976100, 0.030830, 4.504180, 1.481830, -0.664930, 0.602290, -0.619280, 0.083560, 0.087090, -0.043490,
-0.857450, -0.887330, 0.746300, -0.739360, 1.309130, 0.041700, 0.144890, 0.527510, -0.274790, -0.072180,
-0.839090, -0.377950, 0.256360, -0.327980, 0.520350, -0.839600, 0.153960, 0.080650, -9.427740, 1.881900,

1.405200, 2.221600, 0.729040, -1.222390, -1.024560, -0.238040, 0.500210, -0.471560, 0.141350, 0.103070,
-1.300300, -0.016500, -0.114020, 0.677600, 0.075210, 2.304320, -0.286160, 0.342020, -1.328640, -1.279700,
0.241620, -0.561620, 0.032700, -0.505360, -0.396010, 3.058060, -0.429320, 0.185680, -0.185140, -0.344520,
-0.267850, 0.019080, 0.924650, -0.428360, 1.002260, 1.075410, 0.030000, 0.433450, -0.698270, 0.165060,
-1.004450, 2.209180, -0.390080, 0.546080, 0.734600, -0.935050, -1.200510, -0.658820, -1.394950, -0.051590,
0.374830, 0.692280, -0.178920, 1.164630, -3.239680, -0.525210, -1.036640, -0.311470, 0.676650, -0.016610,
2.394420, 0.968830, 0.244270, 0.243420, -0.218730, -0.914200, -0.186570, 3.199650, 0.728490, 0.890240,
-0.532920, 0.624190, -2.927090, -3.314880, -0.085510, 0.239060, -0.437180, 0.510860, 0.442450, 2.091400,
-0.133070, -0.723280, -1.698700, -0.796430, -0.109070, 0.825170, -0.789110, 1.520200, 0.017050, -0.784390,
-1.922550, -2.327890, 1.436780, -1.197360, 0.579580, -0.431230, -0.689860, 2.087500, -1.023160, 0.518140,
-2.171520, 0.080640, 1.882130, -1.166510, 0.516800, -8.952860, 0.870110, 4.173170, -0.944900, -3.901170,
1.826400, -0.587510, -1.415800, 1.200620, -0.167880, 0.295690, -0.331150, -0.149260, 0.846420, 0.311980,
-0.306280, -0.510360, 0.715140, 0.254160, 0.742620, -0.381730, 0.964540, -0.880950, 0.340570, 1.278670,
0.561650, 0.029320, -2.520430, -0.107160, -0.336570, -0.743650, 1.516840, 1.066240, -23.362770, 7.599220,

0.442830, 1.218550, -0.514730, -0.591360, -1.046940, -0.169720, 0.926770, 1.119300, -0.060250, 0.158420,
0.081360, -0.870410, 0.154410, 0.195190, -0.184470, 0.833980, 0.885020, 0.999500, 1.439520, -1.069160,
1.189460, 0.420240, 0.635220, 0.179980, 1.207770, 0.975140, 0.509650, -0.732350, -0.897540, -0.347580,
0.779380, 0.003170, 0.069970, 1.075940, 1.164860, 0.135260, -1.238300, -0.097270, -0.314940, -1.993500,
-0.656980, -0.416250, 2.942080, 0.194440, 0.466830, 1.035160, -0.323200, 0.365440, -0.643900, -0.737730,
-1.574600, -2.880010, -0.681290, -0.292210, 3.806180, 0.261310, -2.357360, -1.806000, -0.590820, -0.921950,
-1.373070, 0.236400, 0.295200, -0.177670, 3.617890, -1.092030, -1.371110, -0.736130, -0.082570, -0.941820,
-0.335560, -0.489890, -1.024270, -1.037090, -0.850860, 0.864570, -0.689790, -0.094910, 0.292690, 1.657060,
1.309360, 1.187020, 5.279730, -0.010740, 0.074980, -3.349650, 0.194780, -0.444080, -2.480560, -0.552290,
-0.544180, 3.454670, 0.191750, 1.282830, 0.163710, 0.079570, -0.813190, 5.656140, -0.009840, 0.060140,
-3.212310, -1.432020, 8.905650, 6.204250, 1.867660, -0.110660, -5.728190, -1.216010, 5.274270, 0.761640,
-1.677270, -1.382830, 1.204220, 1.346570, 1.327020, -0.370290, 0.522970, -0.752380, -0.362740, 0.987180,
-1.189620, -0.262650, 1.082440, 0.665530, 0.711840, -1.859600, -0.255930, -1.779530, 0.093840, -0.132160,
-0.841180, -1.175720, -0.182640, 0.196680, -0.482940, 0.518490, -0.141480, -0.077100, -0.851990, 0.018690,

0.828850, -0.353940, -0.889640, 0.609850, -0.185710, -0.622350, -0.063180, -0.779260, 0.487080, 0.049610,
0.510320, 0.051810, 0.062550, 0.623960, -0.078270, 2.477480, -1.350430, 1.258360, -2.284850, 0.901410,
0.659490, -3.463680, -0.400850, -0.048010, 7.242130, -0.358350, 0.732570, -2.173720, 0.532180, -0.531700,
-4.890770, 1.150800, 0.281490, 12.959660, -0.672320, -0.316650, 1.348250, 0.871900, 0.682620, 4.278410,
-0.201470, -0.719030, 0.939000, -1.485970, -0.848360, 1.138560, 3.443560, -0.880110, 4.120000, 0.024510,
0.065490, 2.665970, 1.751240, 0.953220, 4.413290, -1.995130, -0.824510, -0.713400, -0.575620, 0.223020,
0.956220, 1.923600, -0.721140, 8.261940, 1.232260, 0.259310, 5.923660, 0.976430, -0.601280, -0.220880,
3.097440, 0.480100, 7.481190, -2.215820, -0.622480, -0.170070, 0.316080, 0.311340, -1.261930, 1.545340,
-0.297770, 0.694240, -0.822810, -0.225640, -0.044940, -0.133230, -0.626920, -0.012120, -0.012660, 0.227400,
-0.429690, -3.203390, 0.875960, -0.174910, -0.907120, -0.765880, -0.706550, 0.955640, 0.178240, 2.330420,
-1.728430, -2.005390, -1.042430, 0.496400, 2.699650, -0.691160, 0.132440, -3.316530, 1.163720, 3.023930,
2.916460, 0.511980, -1.914570, -0.309670, 0.722560, 0.296190, -0.714780, -1.259330, 0.359110, 1.252430,
-2.762780, 0.461690, -0.633220, -0.303410, -0.358900, 2.071010, -0.154110, 1.801240, -1.503960, 0.114130,
-0.739810, -0.922670, -0.318860, 0.005750, -0.218900, -0.153950, -0.635240, 0.767640, -4.296110, -10.058480,

-0.272140, -0.392780, 0.646700, -1.099920, 0.222300, -1.006130, 0.585140, -1.563560, 0.300880, -0.546190,
-0.178730, 0.242500, 1.027740, -0.808750, -0.846120, 0.786300, -0.045970, 1.252780, -0.805850, 0.363730,
-0.237790, -0.348300, 3.699760, -1.618150, -0.419920, -2.512440, 1.185890, 0.394060, 3.337210, -0.587040,
1.054790, -4.107980, 0.378990, -0.292900, -2.495470, 0.216570, -0.568500, -0.026360, -0.407540, -0.321610,
-7.253710, -0.469340, 0.332580, -6.153940, 0.985370, -0.142930, -11.583910, -0.517600, -1.708260, -27.333441,
0.215850, 1.027950, 3.174470, -0.958420, -0.051260, -4.332970, 1.188150, 0.712750, -8.021690, -0.122330,
-0.300740, -0.024640, -3.144500, 5.328640, -0.177530, -0.317650, -0.407010, -2.292310, -1.229080, -0.361320,
4.524660, -0.234570, 0.563240, -0.644250, 0.157030, 0.821910, -0.925440, 1.152820, -0.483290, 4.467770,
0.793050, 1.102080, -0.901960, -0.735240, -0.228880, 0.149130, 0.340550, -0.615510, 1.768500, -0.795140,
0.462600, -3.051530, 0.082770, 1.065290, -6.619530, 0.050190, -0.821880, 2.272240, 0.697110, -1.754750,
-2.217380, -0.732580, 1.190870, 1.509570, -3.543700, -3.226360, 6.133970, 1.738160, -2.369940, -3.347610,
-1.153360, -0.313440, 8.769960, 1.776460, -0.162650, -0.384320, 0.520230, -0.370570, 0.770690, 2.469730,
-1.354090, -0.296450, -1.315210, 0.616710, 0.517930, -1.633110, -0.981930, 0.922450, 0.044820, -1.353660,
1.407320, -0.561190, -0.254770, 0.903210, -0.065710, -0.528850, -1.049730, 0.052490, 2.280650, 0.582960,

0.524780, 2.157910, 0.891470, -0.309670, -8.767300, 1.731570, -0.700060, 1.858490, -0.954980, 0.513900,
3.911550, -0.779190, -0.458140, 0.177320, 0.404210, 1.171200, -3.903850, -1.282400, 0.067510, 4.146500,
-0.254210, -1.618030, 2.809390, -0.823610, -0.470940, 0.995800, 0.859160, -1.197030, -4.478810, 0.448370,
-0.658720, 3.962060, -0.402440, -1.055410, 1.149910, 0.840720, 0.690090, -0.006790, -0.373670, 1.157910,
0.063560, 1.104200, 0.244790, 1.278830, -0.202780, 0.557860, -3.961590, -3.082760, 1.021020, -0.410330,
0.915380, 0.064230, 0.927490, -0.074560, 0.420390, -0.062870, -1.086460, -1.371200, 0.421730, -0.307370,
-1.725660, 0.412230, -0.579750, 1.047730, -1.532190, -0.350900, 1.112720, -0.178910, -0.233810, 0.754270,
2.164950, 0.409440, 3.720070, -1.042540, 0.786610, 0.067280, 1.645760, -0.136600, -1.270090, 1.694860,
1.038330, 2.526220, -1.547520, -0.693540, 2.396930, 0.883190, 1.048080, 0.790570, -0.422890, -0.319500,
-1.369100, -0.705970, -0.670090, -0.513640, 2.314600, 0.238360, -1.689290, -2.266350, 0.559390, 0.499000,
-2.148870, 1.249830, -5.030020, 3.003410, 2.489890, -1.100180, 1.312290, -1.121980, 0.875210, 1.578410,
0.089750, -0.363960, 1.557240, -1.902510, 1.066280, 0.105240, -0.352130, -0.939230, -0.180000, -0.314790,
-3.749530, 0.955060, -0.403970, 0.605920, 0.714170, 3.719190, -0.327110, 0.058830, -0.388940, 0.653050,
1.105910, -0.122660, 0.859740, -0.735690, -0.595950, -0.049510, -0.515370, 0.181240, 7.655430, 2.104070,

0.598310, -1.428220, 0.756500, 0.303940, 3.681520, -0.041400, -0.492010, 1.001480, -0.632700, 0.833430,
-4.795580, 2.905250, -0.340520, 1.531100, -2.050310, 0.061480, 2.975260, 1.574860, 0.851830, -0.131890,
-0.048940, -0.779920, 0.094140, -2.251120, 0.498660, 1.459360, 0.782960, -0.932100, -1.795460, -0.632010,
-0.325990, -1.750290, 1.894290, 0.627790, 2.980120, 2.014170, 0.267860, -3.694900, -4.374990, -1.036630,
-2.405560, 0.868900, 0.511220, -4.834390, 1.041770, -0.049470, -1.652160, 0.664510, 0.922070, 0.400860,
-0.221680, 1.024340, 5.557340, 0.519330, 0.296400, -1.745360, -3.941440, 0.400490, -7.626090, 0.950820,
-1.206420, -2.439070, 0.254870, 0.384560, -8.343680, -0.215900, 0.917920, -7.673800, -0.718270, -1.476740,
0.127790, -0.468020, -1.062850, -2.011510, 0.409800, -1.326440, 1.586110, -0.142310, -2.494680, 2.240730,
0.225330, 2.529990, -1.776430, -0.616020, -0.968220, -0.094400, 0.704890, 0.909090, 1.136570, 0.633390,
2.505960, 0.947340, 0.746140, -1.543980, -1.334610, -0.928320, -0.327900, -1.515570, 0.145840, 0.187370,
1.142170, 1.202310, -4.390440, -2.099000, 0.073660, 1.754310, 3.550390, -0.720890, 2.546990, -1.717440,
1.408590, -2.526830, 1.976900, -15.931280, -0.771540, 0.632720, 0.274370, 0.442280, 0.813070, 0.417590,
-0.305080, -0.619360, 0.110200, -0.620070, 0.182250, -2.794790, 0.866520, 0.465240, 0.364230, -1.005120,
-1.086670, 0.372830, -0.119140, -3.074730, -0.108400, -0.235160, -0.970910, -0.190290, -1.375500, 2.081640,

0.533130, -3.881930, -1.187920, -4.565970, 0.780180, 1.099950, 0.503880, 1.229560, -3.303520, 1.079900,
-1.027550, 1.749680, -2.586300, -0.139670, -0.808870, -3.846030, -0.533290, -1.167300, -0.501130, -3.023290,
0.497090, 2.697920, -0.494370, -0.574960, -2.196370, 0.097930, -0.954300, 1.089090, -0.300700, 1.385240,
4.801610, 1.064930, -1.074800, -1.066250, 0.308480, 1.060520, -6.938210, 1.136350, -0.849860, 2.805720,
1.273580, 3.964600, -1.503290, -0.651720, 0.513940, -5.169090, 1.716430, -0.745580, 5.517120, 0.237040,
-0.515220, 5.000760, 0.892440, 0.719400, -1.802580, 2.378680, 0.692420, -4.893860, 0.626110, 0.179550,
2.567490, -1.436390, 0.636290, -17.440571, 0.510930, -0.467970, 0.915000, 1.149000, 0.309640, -1.065900,
-1.442730, 0.254880, 3.612190, 3.267080, -0.613910, 0.488240, 0.196870, 0.667220, 1.639550, -1.556590,
1.185740, 3.052000, 0.233560, 0.341470, -0.176470, 0.262980, -0.419650, -0.267430, 2.620610, -0.966100,
-2.232580, -8.260040, -0.278410, -2.664270, 3.154190, -0.074660, 0.629350, 0.269540, -1.277550, 0.107360,
0.785570, -0.005000, -6.061900, -8.750430, -3.281630, 1.735840, 4.658540, 5.048610, -0.693960, 0.051840,
1.747170, 1.304720, -1.058640, -3.979670, 1.861250, 2.412660, -1.470040, 1.616350, -0.225800, -0.885040,
-0.314930, 0.184520, 0.390990, -0.862060, -1.104030, -6.534220, 3.662660, -1.325430, 0.160740, 0.436080,
-2.599080, 1.865670, -2.349200, -0.237940, -0.806290, -0.172860, 0.495420, 0.832000, 1.065510, -1.431020,

-0.096600, -0.880420, -3.024570, -0.375900, 0.481450, -0.252790, -0.487130, -0.429750, 0.055500, -0.909660,
-1.648280, 0.473110, 0.547830, -0.448230, -0.269870, -0.369480, 0.940270, -0.921130, -0.339590, 0.791020,
-0.263080, 0.447700, -0.717550, -0.261310, -0.410370, 0.459220, 4.594540, 0.144630, -2.749490, -5.590790,
-0.222540, -1.733140, 1.474750, 0.471310, 0.147060, -0.354390, 0.069300, -2.117030, 0.625870, -0.242420,
0.133580, 0.116510, 1.426110, -0.586790, -0.669130, -0.753530, -2.176920, 0.129130, -0.901740, 0.290450,
0.359040, -0.756750, 0.625740, 0.309520, 1.845960, 0.138160, 0.469560, -0.098070, 0.808800, 0.402720,

1.400510, 0.162190, -0.482710, 1.127950, -1.095460, 0.981910, 0.137890, -0.194310, -1.069440, 1.578800,
0.796920, -0.783400, -0.675730, -2.371650, -0.106840, -0.364950, 0.812840, -8.356050, 0.195600, 0.681480,
-0.650460, 0.563660, 0.276090, -0.107480, 0.686930, -0.071770, -0.806020, -1.576390, -1644.108276, 1.267230,
0.555000, 0.662460, 0.330150, -2.833100, 0.036670, 0.244670, 0.054160, 2.798230, -0.585580, -0.968310,
0.278750, 0.026940, 0.138510, 0.233210, -0.804020, -0.530290, 1.551940, -0.172540, -1.220900, 0.541570,
0.313150, -0.419810, 0.018690, 0.082740, 1.119310, 0.083780, -1.041490, 0.554200, -0.132950, -0.552710,

-55.758652, 3.550060, 3.473310, -32.736061, -0.498620, -0.853880, 0.814350, -0.431530, -1.275000, 0.116560,
-0.363330, -0.175570, 1.120710, 0.287120, 0.320350, 2.595240, -0.144600, -0.489450, 0.901900, 0.221550,
1.254430, -0.941720, -0.864150, -0.056380, 0.318170, -0.420050, -0.298090, 0.313800, -19.141590, -2.490480,
-0.445310, 1.332270, -0.037210, -1.618190, 0.192730, -1.031590, 0.317420, -0.266550, -0.603930, 0.341380,
-0.116640, -0.664640, -0.136140, 0.643720, -0.105290, 0.125170, 0.534320, 1.332720, -0.595690, -0.330640,
-0.237870, -0.002730, 0.108510, -0.249470, 1.689550, -0.728070, -0.836000, 0.109590, 0.120470, -0.481870,

1.360550, -0.598860, 1.594840, 0.372940, -0.274960, 1.408080, 0.607280, -0.815060, 0.295850, 0.570770,
-5.288900, 0.327460, 0.717230, -0.276550, -0.299540, -0.042830, 1.505300, -4.818430, -0.126650, -0.138830,
-1.741480, -0.691090, -0.028630, -1.453130, -0.729730, 0.983140, -1.161670, -0.276770, 2.462720, 1.823850,
0.872330, 0.864700, -0.535080, -1.242160, -0.580470, -0.423040, 0.482080, 1.027350, -0.397020, -0.957050,
0.479980, 0.564730, -0.332670, -0.783360, -0.869120, 0.476390, 2.603310, -0.203550, -0.498850, -0.088560,
-1.006450, 0.280670, -0.081770, 1.219050, 7.267810, 0.659360, 0.224660, -0.556640, 0.595850, -0.562730,

-2.318930, 0.239000, 0.440300, -6.188580, -0.100380, 1.429490, 0.289760, -1.069100, -0.259030, 1.483710,
-2.156040, 0.018150, 0.038800, -0.895830, -1.113680, -0.794020, -0.360620, -0.699740, -0.466500, 0.468390,
0.293500, 0.900700, -0.129550, 0.283640, -0.204540, 1.785330, -0.606330, -0.608950, -1.917290, 0.231170,
-0.997340, -0.093720, -1.037820, 2.730640, 0.843340, -0.571390, 1.327350, 0.495020, 0.107100, -0.199780,
0.001210, -0.896060, 0.222200, -0.399610, 0.559490, -0.181110, 6.062080, 0.913280, 0.355490, 0.674730,
0.646950, 1.610670, 0.871430, -0.703900, 1.773590, 0.723810, 0.379480, 0.772000, -1.084260, -0.692840,

-1.282150, -2.341460, -1.294770, 3.152050, -2.228620, 0.043650, -0.545070, 0.048380, 1.288640, -1.150290,
0.672300, 0.333340, -0.248530, -0.405790, -1.153500, -0.558140, -2.920030, 2.767660, -0.707790, -0.689920,
-0.700120, 1.509390, 1.412900, -0.897260, 0.290590, -0.486720, 0.070360, -0.847840, -0.011510, -5.029280,
-0.055730, -1.852020, 0.008490, 0.711600, 0.524610, 0.067050, 2.427520, -0.676410, 0.436960, 0.148190,
0.271170, 0.117430, 0.023720, 0.653410, -1.174380, 0.004190, -5.206500, -0.009990, -0.045380, 0.247260,
0.776260, -0.297370, 0.871300, 0.267710, 1.301410, 1.275970, 0.008090, -0.163230, -0.009200, -0.473040,

0.237910, 0.812960, -0.210160, -2.778860, 0.330980, 0.332550, -0.407260, 0.440540, 0.684050, -0.166320,
0.519920, -0.942600, -0.349360, 0.926060, -0.700190, 0.218630, 0.032030, 0.298640, 0.573950, 0.773910,
-1.223830, -0.015380, 1.026540, 0.453840, -0.373950, -1.104960, -0.360660, -0.289740, -1.053710, 7.095920,
-0.496650, 4.012990, -0.289630, -2.568710, -0.613080, 0.907720, 0.287260, 0.413670, 0.398540, -0.241120,
-0.770760, 0.394440, -0.582770, -0.669830, -1.943420, 0.756350, -0.751520, 0.055490, -0.784680, -0.708060,
-0.098370, 3.203270, -0.010650, 0.709690, -4.048420, 1.568150, -0.529910, 0.220530, 0.325370, 0.134020,

-1.232450, -370.742615, -342.243134, 0.174980, 0.176510, 1.627780, -34.358349, -0.832670, 0.745510, 2.686340,
-3.075720, 0.160040, -0.155460, -1.685950, 2.054460, -166.898560, 2.511000, -1.624780, 0.633580, -0.304850,
-2.908430, 0.295670, 1.357270, -5.149770, -0.790990, -0.356960, 4.220220, 0.509150, 1.554140, -4.806670,
0.179720, 9.413730, 2.444090, -10.421100, -0.328700, 0.381720, -2.147940, -0.775260, -0.316430, 0.487660,
1.278850, -0.294830, -0.353100, 1.027590, -0.018080, 0.251050, 3.023560, -1.689570, -0.776390, 0.686150,
0.158280, 0.185420, -0.921230, -0.052320, 3.001180, 5.186000, 0.260390, -0.955300, 0.223100, 0.838900,

-1.416660, -1.341430, 0.318330, -1.197910, 0.606660, 0.543570, -0.114100, 0.133990, -0.353330, 0.750380,
-0.358280, 0.247500, -0.384850, -0.289910, 0.080830, 0.249330, -0.750770, -1.699470, -0.453070, 0.702080,
0.135050, 0.245010, -0.229010, 0.201340, -1.000210, -0.436590, -0.050920, 1.048600, 0.972210, -0.650200,
0.851040, 2.297220, -1.020940, 0.609510, 0.148890, -0.672250, -0.526410, -0.301170, 0.057990, -0.850080,
0.700620, -0.440920, 0.681600, -1.127730, -0.297150, 0.158030, -0.966890, -0.650160, 0.111180, -0.410170,
0.456940, -0.410280, 0.247240, 0.670850, 0.740080, 0.192250, -0.603330, 0.862120, -0.412280, 0.686930,

1.385870, -0.337860, -1.076220, 11.295290, 0.570320, 0.554060, 0.237810, 0.028710, 0.155490, -0.730540,
-0.052710, 0.792910, 0.413970, -0.096030, -0.152320, -1.201280, -0.393240, -0.216740, -0.099350, -0.569440,
-0.460830, -0.588350, 0.096460, -0.065920, 0.105310, -0.557800, 0.293280, 0.400300, -1.407500, 1.272100,
-0.067450, 1.311020, 0.630100, -0.778430, -0.303860, -0.011210, 0.202490, -0.293860, 0.147530, -0.110300,
0.076810, 0.388910, 0.048140, -0.356220, 0.291790, 0.108930, 0.464540, 0.665810, -0.210480, -0.031220,
0.861120, 1.724710, 0.082510, -0.710240, 1.645390, 0.620320, -0.387680, 0.033820, -0.245560, -0.162530,

0.082020, -0.762000, 2.504060, -8.426040, 0.993850, 0.017460, -1.057680, 0.918040, -2.213560, -0.670780,
0.878040, 0.047820, 0.739280, 0.489540, -0.094770, 0.330300, -0.527900, -37.935558, -0.358140, 0.577390,
0.932720, -0.271700, -0.183050, 0.687960, -0.609310, -0.652820, 0.251790, -0.935400, -0.682340, 4.013970,
0.674020, -1.762120, 1.308190, -0.827220, -0.709950, -0.754320, 0.242100, -1.228170, 0.406130, 0.716530,
0.547390, 0.775290, 0.429650, 0.595580, 1.882150, -0.090350, 5.686410, -0.078260, -1.191570, 0.106360,
-0.829750, -0.774280, -0.585400, 0.497550, 0.660470, 0.127920, -0.873210, -0.428080, 1.008470, 0.716990,

1.510470, 0.771480, 5.772110, -1.632320, -0.540120, 1.130700, 0.668460, 0.052930, 0.101230, -0.110920,
0.831380, -0.143840, -0.091960, 0.151410, 0.046500, -1.255500, 3.268600, -0.874570, 0.931240, 0.867250,
-0.436480, 0.069830, -0.649790, 0.775830, -0.527340, -0.519460, -0.772280, 0.347500, 0.669350, 19.022301,
-0.975830, 16.967340, 0.764130, -3.167110, -0.038590, -1.175480, 0.874020, -3.868700, -0.827820, 0.336030,
0.891120, 0.236470, 1.259130, -0.567050, -0.143950, 0.100170, -4.654500, 2.591220, -0.045900, 0.150630,
-0.583320, 1.307540, -0.623800, 0.752870, 0.504740, 3.192210, -0.755970, 0.170030, -0.384800, -0.493200,

3.294240, -0.787490, 0.158530, -30.550360, -0.337570, -1.005810, -1.189780, 0.843320, 0.767800, 0.229520,
-1.526610, 0.202670, -0.557100, 0.024980, 0.639380, 3.056800, -0.370090, -0.194490, 0.814980, 0.145890,
1.546950, -0.882850, -0.912870, -0.465930, -0.867350, -0.341280, -1.998210, 0.872970, -5.838210, 1.909640,
0.000230, -1.176820, -0.557200, 0.316740, -0.637090, 0.840830, 0.040270, -1.255180, 0.729730, 0.740640,
-0.008600, -0.170060, 0.377130, -0.502420, 0.864790, -0.751370, -3.292680, 0.762880, -0.303880, -0.630990,
-0.013090, 0.133250, 0.480490, 0.299660, -2.228530, -0.255570, -0.906340, 0.281680, -0.545050, 0.300430,

-1.658290, -1.870290, -2.409170, 1.674560, 5.036790, -0.761000, -0.826390, -0.546620, 0.773170, -0.289480,
-1.437240, 0.308560, -0.058730, 0.030460, -1.062290, 2.670260, -0.191300, 0.583720, 0.192760, -0.868500,
-0.635510, -0.336460, -0.490750, -0.162540, -0.753290, 0.696850, 2.158230, -0.308370, -3.520400, 0.441130,
-0.222940, 0.307510, -0.261060, -0.030510, 0.042190, 0.128360, 0.286550, -0.400740, -0.081770, 0.343090,
0.535240, -0.379140, 0.304870, 0.056750, 0.638120, 0.479340, -1.491300, 0.363650, -0.941380, -0.321860,
0.640850, -0.456910, 0.576270, 0.633310, 3.645100, -0.041500, -0.002310, 0.351280, 0.732860, 0.127800,

-1.706250, -0.500190, 0.886390, 1.840400, 0.633190, -0.247430, 0.681710, -0.311070, 0.167140, 0.664770,
-2.378810, 0.594740, 0.089620, -0.219740, -1.196730, 0.771140, 0.386720, 0.614880, -0.858350, -0.875970,
0.141410, -0.002390, -0.112780, 0.153480, 0.478580, 0.564680, 0.697220, -0.379450, -1.945340, -11.410300,
-0.078280, -8.000840, -1.419670, 4.345920, -0.129740, 0.592820, -1.226900, 1.968020, 0.032970, -0.200690,
-0.739480, -0.158310, -0.494180, -0.700600, 0.166200, 0.574890, 8.277710, -1.436370, 0.140660, -0.134640,
0.996200, -1.175810, 0.374370, -0.327520, 1.131710, -0.295810, 0.883610, -0.000690, 0.215350, -1.200040,

1.013630, -2.294400, -1.904030, 22.182961, 2.458530, -0.100550, 0.319580, 0.335320, 0.834610, 1.656440,
-1.211920, 1.472330, 2.886520, -4.453770, 1.357050, 5.510940, -1.266470, -1.943230, 1.315830, -0.451630,
-0.597420, 0.347350, -3.870030, 1.340010, 2.575060, 1.902060, 1.424410, 1.395900, 1.045020, 7.109030,
-0.852730, -17.443680, 3.111580, 26.316460, -0.046870, 0.395240, 3.608540, -3.163180, 1.548810, 2.091990,
-1.686130, 8.850990, -0.388140, -0.130200, -1.197280, 0.873920, -7.893900, -1.314310, -2.381340, -1.060280,
-0.078240, -2.190980, -0.331220, -0.086040, 6.344600, -6.382060, -1.779760, -0.072110, -0.971180, -0.720360,

2.521700, -5.290760, -2153.060547, -1.384200, -1.407540, -0.418560, 2.657610, -1.117770, 1.059820, -18.758600,
1.142720, 0.710190, 0.397420, 0.569560, -2.478740, -11068.291016, -1.023160, 1.179670, -0.068690, -1.659610,
-0.555550, 0.592380, -0.363030, -0.872590, 0.970710, -0.525480, 0.578810, -0.271840, -0.027140, -313.799072,
0.061590, -0.317420, 3.960830, 0.909500, 0.809300, 1.168570, 0.792260, 1.123860, -0.025570, 0.016170,
-0.668430, -0.057410, -0.600200, 0.249380, -0.157780, -0.294110, -0.517680, 1.591230, 0.232580, -0.666390,
0.622120, -2.119570, 0.134860, -0.345820, -3.093650, -0.242770, -0.498720, -0.253920, -1.033570, -0.759450,

-4.807330, -0.582240, 1.260370, -1.265410, 0.875280, -0.626210, 0.710770, 0.643980, 0.479670, -0.519620,
0.596840, 0.327750, -0.267760, 0.735280, 0.586920, 1.494530, 0.311840, 1.441950, -0.288910, 0.359340,
-0.173690, -1.175680, -0.041080, 0.705490, -0.617490, -0.410780, 0.317750, 0.797230, 9.171850, 0.568930,
-0.118000, -0.682660, -0.681480, -1.061670, 0.292510, -0.482760, -0.440290, 1.012470, 0.504040, -0.352600,
0.295070, 0.301100, 0.563590, -1.269150, -2.244600, -0.051450, -3.816910, -1.409590, -0.267390, 0.044060,
-0.243520, 1.054550, -0.704490, 0.152610, 15.584980, 0.583240, 0.408910, -0.904130, -0.669980, 0.703500,

1.434240, 1.122260, -1.123360, -0.811570, 0.058030, -0.831260, 0.354310, 0.370480, 0.264320, 0.039690,
-0.623830, 0.097240, -0.938800, 1.721360, -0.464020, -0.383710, -0.339470, 1.179780, -0.040550, -0.562840,
0.615490, -0.717600, -0.492740, -0.903980, 0.460300, 0.290220, 0.190470, -0.139400, -2.837690, -1.177710,
0.318500, 2.195000, -0.147640, 5.186830, -0.345200, 0.718960, -1.366990, -0.257670, -1.081700, 0.229530,
1.778590, 0.300010, -0.334830, -0.223700, 0.477340, 0.115170, -2.326490, -0.784100, -0.606000, -1.139740,
0.788180, -1.267000, 0.277050, 0.257410, -3.191950, -0.868500, 0.999070, 0.842210, -0.309790, 0.682320,

-0.060980, 1.656460, 0.159600, 5.491210, -0.821960, -1.959580, 1.299170, -0.045960, -0.890160, -0.251590,
-1.013950, -1.120960, 0.802190, -0.245500, 0.249940, 2.134790, -0.664230, -1.176940, -0.667470, 0.099500,
1.969870, -0.817080, 3.309580, -0.131670, 0.846220, -0.224700, -1.401070, 0.066540, -0.394560, -4.765590,
-0.346660, 3.590420, -1.414540, -0.714230, 1.119040, 0.760280, 1.516660, 2.284950, -0.607510, 0.645580,
-0.038960, 0.163160, -1.203990, -0.028260, -0.125680, 1.300670, -1.640110, -2.022350, -0.019170, 0.162030,
-0.382160, 2.787980, -0.996650, 0.638340, 2.053810, -0.222640, -0.283150, -0.379120, 0.057830, 0.809280,

-8.193000, -0.502680, -1.452350, 2.141720, 5.274510, -0.460640, -0.184760, 0.023220, -0.371270, 1.130040,
4.651010, -0.802460, -3.088920, 0.383990, 0.377200, -0.873340, -4.761820, -2.970750, -0.934630, -0.926500,
0.829180, 1.182410, -1.500670, 0.099740, -1.078670, -1.294060, 11.534500, 0.274680, -7.379430, 8.247090,
0.564010, -1.078690, 0.013450, 8.832880, 1.128580, 0.849170, -0.372660, 4.766300, 0.015340, 0.439510,
-1.289500, 0.790950, -0.577650, -0.936060, 78.510422, 0.470560, 3.743410, 0.386240, 0.462840, -0.142550,
2.527260, 0.018890, 0.244610, 2.625930, -4.083900, -2.070480, -2.766970, -0.118980, -1.475060, 0.688010,

5.072820, 0.894640, -1.045460, -9.419520, -17.389120, 0.641820, -1.097970, 0.665590, 0.163240, 1.356240,
0.084120, -1.537080, -0.148510, -0.775020, 0.529090, 0.882480, -0.082620, 2.955990, 0.904560, -0.080870,
0.902680, 1.142690, 0.366220, -0.724820, 0.516640, -0.222040, -6.829150, -0.048890, 13.175250, 2.041990,
0.629400, -1.044320, -0.606310, -1.262800, -0.519090, 0.724690, 0.968620, -0.151360, -0.596800, -0.623120,
-0.380730, -0.222930, -0.185030, -0.700700, -1.401460, -0.352960, -3.785210, 0.015910, 0.092800, -0.458450,
-0.488640, 1.403640, -0.707160, 0.870380, -8.594710, 0.148440, -1.778870, -0.802300, -0.810910, 0.752910,

0.257540, 0.347610, 1.492770, 1.138750, 0.570300, -1.009590, 0.586810, 0.629590, 2.232690, -1.130520,
0.517490, 0.318810, -0.195550, -0.879370, 0.593740, 2.917480, -0.044150, 1.137650, -0.202600, -0.912230,
-0.615460, -0.719680, 0.083720, -0.858580, 0.278260, -0.041460, 2.181850, -0.504580, -0.669950, 0.905860,
-0.305550, -1.362140, -1.425420, -0.106540, -0.507810, 0.670360, -0.210070, 3.058590, 0.154600, -0.036980,
-1.700190, -0.602870, 0.334810, -0.167680, 0.013210, 0.077930, 0.187110, 0.358280, 0.072010, 0.988270,
0.587180, 0.193220, 0.743110, -0.047600, 0.356980, -0.976460, -0.128180, 0.641720, -0.476380, -0.567220,

-0.025050, 1.996340, 0.798990, 4.031720, -0.264580, -1.258710, -0.411980, 0.269500, 0.561970, -0.412280,
1.362520, -0.571480, -0.000510, 0.760890, -0.316470, 0.339170, 1.150590, 2.135380, 1.041890, -0.217310,
0.376040, 0.329690, -0.797280, -0.225230, -0.016460, -0.756240, 0.420020, -0.342460, -1.328730, 1.389750,
-0.573870, -2.896110, 0.508360, -0.418120, 0.473150, 0.411830, 0.691460, 0.039350, -0.034950, 0.854370,
-0.364190, -0.476400, 0.319270, -0.014430, -0.460580, -0.263540, -2.774630, 1.306030, -0.609400, 0.370610,
-0.631030, -1.832460, -0.088870, 0.390880, -9.605990, -1.119940, 1.255840, 0.766510, 0.630280, 0.711100,

1.007900, -107.538841, 1.736490, 0.292540, 0.220360, 0.130030, -0.331670, -0.650330, 1.334860, -0.872070,
-4.145020, 1.343220, 0.526350, 0.256440, -0.479470, 0.787680, 0.801420, -0.456580, -0.249990, -1.361160,
-1.362020, -0.277370, 1.020580, -0.477270, -1.238460, 1.804120, 0.558020, -0.380090, 2.095460, -82.852448,
0.122580, -2.147130, 0.511230, -0.655790, 0.270060, -0.314440, 0.398870, 0.413860, -0.220450, -1.573220,
0.640340, 0.351760, 0.337330, -0.804610, -0.158830, -1.352660, -1.394880, 0.287570, 0.303410, -0.051010,
-0.761380, -0.540010, -0.140870, -0.257000, -2.501950, -0.010800, -0.211140, 0.494850, 1.096990, 0.057320,

-7.679430, 0.774910, -3.168390, 1.489620, -28.762239, 0.314880, 0.021300, 0.862340, -0.864160, -1.320010,
0.431050, -1.752770, -2.061730, -0.803410, 0.077140, 0.155070, -46.770119, -3.509800, -0.098660, 0.340070,
-0.655240, 0.126530, 0.161680, -0.416480, 0.667630, -0.475310, -1.611120, 0.357480, -2411.525146, 14.370760,
-0.448630, 9.333630, -0.542880, -5.424200, 1.003630, 0.367870, 2.431580, -2.298760, 0.171990, -0.976120,
-0.465270, -0.332630, -0.103090, -0.744710, 0.404250, -0.048320, 0.212110, -0.427820, 0.049600, 0.972100,
0.046340, 0.043300, 0.297370, -0.268910, -19.191170, 1.676230, 0.240490, 0.004060, -0.256710, 0.657280,

-1.548230, -31.393881, -14.529330, 12.754680, 1.661090, -0.022640, -0.515490, -0.337130, 0.396080, -0.206860,
-0.521560, 0.862580, 0.583630, 0.906100, -0.808720, -2.200770, 2.992630, -1.416810, -1.401540, -1.073160,
-1.331480, -0.430910, 1.248640, -0.900480, 0.229640, 0.654070, 3.031020, 0.347950, -0.754390, -16.718250,
0.061530, -4.779800, 0.680980, 4.007820, -0.700440, 0.800620, -0.626800, 5.011810, -0.830280, -0.178130,
-1.668570, -0.437690, -0.051280, 0.877460, -0.126860, 0.876540, 4.851450, -0.378390, 0.099570, -0.599580,
0.476330, -0.661990, -0.859520, -0.615860, 8.216730, -5.652970, -0.756400, 0.904070, 0.344230, -0.513680,

1.210570, 0.587390, -0.445610, -0.403630, -1.268260, -0.767840, 0.567170, 0.535940, -0.413700, -0.110000,
-0.318720, 0.418920, -0.543960, 0.265320, 0.166150, -0.657330, 0.222100, 0.120990, -0.267530, 0.083340,
0.504430, -0.371370, 0.437000, -1.339630, 0.418710, -0.123330, 0.253360, 0.593080, 0.025730, -2.285500,
0.089510, -1.338950, 0.222600, 1.868480, -0.259040, -0.250160, 0.416020, -1.765660, -0.279620, 0.581110,
0.243660, -0.351620, -0.652320, 0.837010, 0.671100, 0.131200, -3.304780, -0.381670, 0.737300, -0.265680,
0.228590, 1.312560, 0.125130, -0.543530, 3.998730, 0.400780, 0.924910, -0.093470, 0.091170, 0.541400,

-2.769460, -0.632290, -2.704250, -0.599390, 1.435960, 0.221440, 1.199780, 0.026820, -1.099790, 0.878020,
-2.286630, 0.872330, 0.190170, -0.060590, -0.568130, 37.477680, 1.906870, -0.290430, 0.514010, 0.808030,
1.387080, -0.841820, -0.705000, 0.751250, -0.550700, 0.261800, -0.773330, 1.093330, 0.920570, 0.280590,
-0.024070, -0.077990, -0.182330, 0.344370, -0.451540, 0.442670, 0.240850, -0.106740, 0.064730, -0.451390,
0.144430, -0.132700, 0.186120, -0.564850, -0.627000, 0.405000, -0.683550, 0.110210, 0.824690, -0.079640,
-0.995080, 0.092470, 0.025290, 0.395760, -7.015310, -0.644770, 0.204050, -0.112260, -0.838430, -0.553720,

1.254950, 0.444150, -2.258210, -1.777470, -0.067300, 0.047880, 0.008250, 0.181130, -0.739780, -0.212020,
-0.538360, -0.325330, -0.011570, -0.351470, 0.962540, -0.038650, -0.613010, 0.173480, 0.686880, 1.206590,
0.330590, 0.056180, -1.144280, 0.607450, 0.123000, -0.525910, -1.132420, 0.523980, -0.030210, 17.476070,
0.178350, 9.573400, 0.244400, -2.473300, -0.149190, -0.118530, 1.584700, -3.136660, 0.167570, 0.982800,
1.284670, 1.027260, 0.230360, -0.332270, -1.470210, -0.373820, -5.791070, -0.778860, 0.549070, -0.812460,
0.159170, 1.159340, -0.126550, 0.902460, 6.401330, -1.271900, -0.954370, -0.592710, -0.571820, -1.066730,

-0.850320, -3.212660, -0.060230, -2.043400, 0.757620, 0.256570, -0.830570, 1.697700, -0.623940, -0.757160,
-1.003850, -0.653660, -0.436680, 0.329110, 0.116990, 0.418800, 2.306330, -0.463400, 0.442900, 0.211710,
0.660250, -2.157780, 0.783430, -0.049410, -1.144880, -2.044290, 0.555660, -0.904910, -0.049670, -0.918610,

0.139030, -3.320430, -0.499290, -0.792700, 0.764780, 0.558440, 0.883710, -1.456850, -1.028250, 0.149610,
-1.194340, 0.407960, 0.585850, -0.379450, -3.801300, -0.705420, -2.940440, 0.641380, -0.965080, 0.346240,
-0.452480, 1.158220, 0.498600, -0.464630, 0.857900, 0.754970, 0.105590, -0.516390, 0.050560, -0.238050,

0.887560, 2.974370, 0.351480, 1.698840, -1.255470, 0.014020, -0.485860, -1.322560, 0.449790, -0.257900,
0.926000, 0.836240, 0.038180, -0.745200, 0.030900, 0.689580, -1.521360, -0.199590, 0.821180, -0.543350,
0.787510, -0.846790, -0.720130, -0.496860, 0.178750, -0.607550, -0.352760, -1.056010, 0.226550, 0.741480,

-0.665220, -5.567420, -0.707510, 1.245340, 0.613340, 0.573970, -0.850770, 2.014730, -0.270920, -0.061130,
-0.984480, -0.943100, -0.694290, 0.685640, 0.800640, 0.313990, 3.489470, -0.228270, 0.337200, 0.475480,
-0.336630, -2.472600, 0.482030, -0.505850, -4.176680, -2.143130, 0.757060, 0.546230, -0.548520, 0.341100,

-0.693220, -1.705500, -0.790990, -2.103290, 0.616430, 0.099930, 1.248510, -0.995160, 0.487120, 0.666960,
-1.352760, -0.623840, -0.060400, -0.596480, -2.896470, -0.644670, -3.287000, 0.109440, 0.249210, 0.610870,
-0.893390, 1.683780, 0.418930, -0.342500, 0.743540, 0.905020, -0.710410, -1.111880, -0.538270, 1.045950,

0.788830, 1.499890, 0.682500, -0.637230, -0.624950, -0.592720, -0.660060, -1.746600, 0.229430, -0.375850,
1.214710, 0.909270, 0.457430, -0.319510, -0.734710, -0.561340, -2.207880, -0.369570, -0.729400, -0.427740,
-0.216190, -1.663080, -0.476360, 0.703760, 3.297010, -0.765170, -0.619190, 0.626270, 0.749670, 0.019130,

0.138510, -7.087420, -1.629380, 1.919600, 0.118320, 1.030670, -0.755260, 1.805180, -0.974630, 0.540600,
-0.771660, -0.881180, -0.883860, 0.863050, 0.026920, 0.736680, 3.834550, -1.066180, -0.119310, 0.106870,
0.577620, -2.144900, -0.017030, -1.245070, 4.755770, -1.859590, 0.525040, -0.218610, -0.366140, -0.589310,

-0.004450, 1.737090, -1.397230, -1.737180, 0.146530, 0.484730, 0.762270, -0.812220, -0.216270, -0.833590,
-0.454980, 0.500260, -0.305320, -1.529870, -2.370300, -0.652450, -3.380730, -0.810970, 0.011600, -0.178410,
0.709430, 1.871260, 0.295540, -0.720710, -6.779350, 0.731960, -0.714510, 0.536920, -0.960870, 0.432960,

0.188660, -1.266410, 1.223150, -1.305010, -0.363580, -0.774030, -0.288440, -1.791300, -0.275720, -0.680660,
0.667340, 0.624930, 1.030810, 0.754070, -0.716730, -0.757610, -3.226000, 0.836480, -0.494980, 0.185770,
-0.437060, -1.776960, -0.459340, 0.135960, -3.267250, -0.595000, -0.728000, 0.191830, 1.179510, -0.508070,

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
      0.0, -0.140420, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, 0.199430, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, -0.269640, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, -0.738900, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.710250, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, -0.291160, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, 0.529010, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, -0.389620, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, 0.297030, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.537860, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, 1.030330, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.586790, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.942130, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.837670, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.735480, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 0.731940, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.622010, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.676940, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, -0.921010, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 0.668500, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.336540, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, 0.373460, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.792130, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, 0.572980, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.698980, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, -0.420940, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.552350, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 0.619450, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.628430, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -1.186330, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, -0.192800, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.374320, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, 0.362980, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.183110, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, -0.004810, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.514910, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.447260, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.232660, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.871010, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, 0.943350, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -1.076990, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.606960, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, -0.313780, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.936590, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.596840, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, -0.100820, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, -0.911230, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, -0.594480, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.319100, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.521520, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.898460, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 0.298820, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -1.102190, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, -0.424750, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, -0.496350, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -1.015810, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.729580, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, 0.757550, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.488190, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.299060, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, 0.660220, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.509550, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, -0.791220, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, -0.934590, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, 0.290090, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, 0.265100, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.154790, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, 0.564340, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.963340, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.02679, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.01089, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.00207, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
0.00158, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
1.12164, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.16023, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.04029, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.42517, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.79714, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
0.28468, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.47903, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
1.34761, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.59026, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.38962, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
1.31119, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.00008, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.04214, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.58901, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
1.40763, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
1.13033, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
0.77345, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
1.38594, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.03578, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.01487, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.41582, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.42857, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.04808, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
1.42523, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.17837, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.00000, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.17846, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.00000, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.02434, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.00118, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.98615, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
0.82620, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.02042, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.13176, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.71149, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.59994, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
0.01438, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
0.02320, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
0.52455, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.42102, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
1.16100, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
0.92814, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.02091, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.03450, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
1.39317, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.62908, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
1.42857, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.00000, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.33120, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
1.36046, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.00293, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.00000, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.09486, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
1.40303, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.97099, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.13175, 0.500000, 2,
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
