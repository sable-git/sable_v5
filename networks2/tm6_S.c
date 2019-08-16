/*********************************************************
  tmp6_snnsN3.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:37:43 2004
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
-0.526310, 1.278710, -1.952470, -0.590920, -0.755320, -0.326360, 0.412520, -1.522380, 0.010200, -0.986120,
0.568830, 1.582370, 0.928810, -1.122540, -4.986150, -0.332920, -1.496060, -1.651500, 0.689960, 1.641370,
2.216880, -0.765910, -1.426590, -0.316560, 0.603610, -9.336890, -1.400820, 0.320410, 5.537610, 7.183180,
0.327690, -2.098310, -1.426330, -0.011420, -2.260140, -3.459210, -0.291830, 9.487160, 0.644690, 0.362800,
0.555840, -0.370910, 0.193380, 3.644520, -0.920730, 0.097760, -34.477692, 0.240320, -0.348590, -6.924050,
-1.130450, -0.553250, 2.755110, 0.231370, 0.519690, 0.717590, 0.149640, 1.632590, -7.110150, -0.299470,
-2.827130, 1.734360, -0.238760, -0.494430, -4.098030, 0.560330, -2.805120, -12.317790, 0.971790, -0.394720,
1.265610, 0.337790, -3.622600, 2.035770, 0.290950, 5.787010, -3.954240, 0.853500, 0.845280, 2.709520,
0.199960, -0.654030, 2.039780, -0.295980, -0.413490, -3.359280, -0.349450, 0.547420, 0.323160, -1.429570,
-6.900080, 2.412350, -0.621720, -0.459530, -0.784830, -0.522410, 2.234350, 0.391160, 0.558600, 2.114630,
0.024010, -1.215340, 0.390280, 5.076680, 2.930660, 4.111400, -5.076730, -3.430770, 0.635940, 1.278840,
-1.372550, 0.020040, 1.715080, -0.035430, 0.584250, 1.175940, 1.390000, 1.064760, 1.242440, 2.587460,
-5.112580, 0.935550, -1.707990, -0.118070, -0.787200, -0.258560, -0.917880, -0.692600, -1.028410, -0.166500,
-2.143300, 7.995990, -0.163300, -1.067550, 0.397710, -0.798220, -1.039540, 0.324750, -7.269690, 1.140060,

-0.752270, 1.047980, -0.619570, 0.789560, -0.340300, 0.079850, -0.590430, 0.658630, -0.568630, 0.534570,
-0.590280, 0.613200, 0.328350, 0.768690, -1.505590, -1.591370, -0.139390, -1.093450, 1.193100, -1.118430,
0.569380, -0.238940, 0.717430, 0.719420, -0.609020, -0.683480, -1.175340, 1.990440, -1.817750, 0.318970,
0.771200, 0.651680, 0.127370, -0.120180, 1.622940, 0.174600, 0.616590, -1.124130, 0.243920, -0.445030,
0.466610, 0.372200, -0.379090, 1.302320, -0.844920, 0.468470, -1.904930, -0.125500, -0.084460, 2.617440,
0.027360, -0.338150, 0.886400, 0.582260, -0.824420, -2.318240, -0.447880, -1.233390, 1.109800, -1.730070,
-2.038300, -0.521760, -0.611100, 0.145840, 0.874130, -0.815570, -0.916850, -0.371240, -0.663270, -0.672680,
-1.374890, -0.787930, -0.959730, 2.622790, -0.213910, -0.499900, 1.039030, 0.125410, 1.204720, -0.538150,
1.014790, -1.750590, 1.459730, 0.819520, 2.217320, 0.230030, 0.782460, 0.668760, -0.855940, 0.483860,
-0.349390, 0.165130, 0.250390, -0.012570, 0.845700, -0.078260, -2.309800, 2.371700, 0.251050, 0.250040,
-0.074490, -0.523500, 1.383060, 1.688370, 0.556780, 0.422670, -2.241140, -2.651150, -0.251260, -2.226840,
5.472770, -1.024350, 0.368300, 0.094780, -0.440540, 0.679660, 1.277050, -0.384530, 0.384210, 1.191470,
-0.694020, -0.572840, 0.558820, 0.139880, 0.263590, 0.717150, -1.057790, 0.290980, 1.201680, 1.280190,
0.590060, -0.324140, 2.050450, -0.577600, -1.284750, 0.199400, 0.619690, -0.176820, 0.681780, 0.876480,

0.213290, 0.595480, 0.744790, 0.283430, -1.571860, -0.123770, -1.120310, 0.313530, -0.779850, 1.909100,
0.422860, -0.310720, 0.446180, -2.425510, -0.357960, 0.801430, 2.846850, 2.208210, -0.152480, 4.306850,
-0.427790, -0.326670, -1.378790, 2.274670, -1.068060, 0.475540, -0.614440, 1.233530, -0.508840, -0.064790,
-0.563720, -0.130990, 1.115860, -2.803530, 1.393620, 1.148060, 0.946310, 3.851390, -2.743620, 0.095560,
-6.950250, 0.424920, 1.122160, -3.404150, -0.361090, -3.944060, 16.137529, 1.452900, 0.233880, -14.656270,
1.179250, 2.137530, 3.974800, -0.004140, -1.639960, 4.037760, 0.611250, -0.355700, -1.035240, -0.814630,
-1.222500, 2.678880, -1.494040, 0.645940, -3.229880, -1.470380, -0.450300, -0.939430, -1.468150, -1.652130,
4.910200, 1.946280, -0.232940, 6.429250, 0.018470, -0.672380, -3.784120, 0.130700, -1.417140, -2.165830,
-0.432190, -0.362400, 1.053610, -0.615470, -0.203850, -1.733520, -2.163930, -0.751820, -4.926840, 0.243410,
-0.809300, 0.106400, -0.806370, -0.355780, 1.381390, 0.004610, -0.454140, 2.045480, -0.448230, 3.081490,
2.880160, -0.664910, 1.375430, -7.527950, -1.394890, 4.998490, -8.007380, -2.741690, 1.243680, -3.156370,
-10.107600, -1.014250, 0.149650, 0.392070, 1.258780, 3.069190, -0.077290, -0.846640, 1.651950, -3.716880,
2.716210, 2.260830, 0.121840, -0.416350, 0.910570, 0.727130, 0.228170, 1.090030, 0.463170, -0.144770,
0.038020, -1.591210, 0.943240, 1.284250, -0.731690, -0.053290, 0.864060, -0.050890, 0.156630, 0.151370,

418.467255, 417.408020, 418.689362, 417.701111, 417.947754, 418.341522, 417.930969, 417.095245, 418.927399, 418.675476,
417.124817, 418.462250, 418.211945, 418.259796, 418.454712, 417.861450, 418.862213, 418.061310, 418.101715, 418.805237,
418.241119, 418.869019, 417.368683, 418.401764, 418.462616, 417.856659, 418.517120, 418.059204, 418.818268, 417.967590,
418.186340, 417.461365, 417.813843, 418.049530, 418.748749, 418.469208, 417.674164, 417.075348, 417.635132, 418.809692,
417.263123, 417.934662, 417.964478, 418.192291, 418.876038, 418.405609, 417.797943, 417.902161, 418.193176, 418.737061,
418.110352, 418.211090, 417.567413, 418.479584, 417.881683, 418.110840, 417.851685, 418.943665, 417.357239, 417.108063,
418.067719, 418.067291, 417.933014, 417.046692, 417.658508, 418.127808, 418.788971, 418.278625, 417.964203, 418.201752,
418.421661, 418.845520, 417.372528, 418.581726, 417.813263, 417.741608, 417.623444, 418.509735, 418.899689, 417.591644,
417.645203, 417.039612, 418.150513, 417.213959, 417.545593, 417.037689, 417.918335, 418.279419, 418.821991, 417.175110,
417.332275, 418.573425, 417.159515, 418.125031, 417.047211, 418.889221, 418.375580, 417.403839, 418.388641, 418.217804,
418.022797, 418.689117, 418.189911, 418.255310, 417.061371, 417.795319, 418.854523, 417.155914, 417.943787, 417.530060,
417.427338, 417.453247, 418.785461, 418.619873, 417.349945, 418.931122, 418.281891, 418.953278, 418.343506, 417.413605,
-0.709060, 417.208313, 417.811005, 418.678101, 418.612030, 417.130341, 417.203430, 418.391022, 417.766846, 417.393311,
417.954437, 418.750305, 417.052368, 417.174347, 417.448334, 417.772522, 418.899658, 418.834106, 417.748718, 144.657959,

-0.344770, 0.186320, -0.389140, -2.169650, -0.201910, 0.106890, -1.680540, -0.312060, -0.191800, 0.295980,
-0.943820, 0.038970, -0.437470, 0.344450, 0.571780, 0.437960, -0.144020, 0.822420, 4.414340, 0.001120,
-0.703470, -4.602020, -1.058360, -0.470330, 0.790710, -0.734800, 0.386640, 10.857800, 1.284160, -0.332150,
-2.648090, -0.746730, -0.939780, -2.649490, -0.555980, -0.990570, 2.973030, 0.249580, -0.674190, 3.793160,
0.361050, -1.456900, 1.134390, -0.423910, -0.332110, 2.768690, -0.590500, 0.656760, 4.066070, -0.402590,
-0.358170, -1.839430, 0.492450, 0.329560, -0.161950, -0.033380, 0.406840, 0.446250, -1.895970, 0.192680,
-1.985640, 1.919510, -0.389410, -0.496180, -0.443750, 0.727250, 0.641360, -0.014710, 0.605080, -1.362520,
0.620100, -0.588240, -0.430660, -0.954800, -0.381110, 0.747730, 0.296570, -0.815610, -0.466560, -0.257500,
-0.896520, -0.666370, -0.021500, -0.942420, 0.605890, 0.865230, -0.053550, -0.426870, -1.592140, -0.385900,
0.710390, 1.919880, 0.290570, -1.243590, 1.164880, 1.217690, 1.336580, -1.701930, -0.352760, 1.671090,
-1.015420, 1.069200, 1.528850, 4.151210, 0.412870, 2.915110, 1.165970, -0.606240, 1.322120, 1.224010,
-0.580390, 0.471370, 0.659390, 0.735460, 0.450480, 2.364290, -1.582390, 0.346240, -0.137680, 0.530760,
-2.037440, -3.252940, 0.543960, -0.271150, 0.197990, -0.213110, -0.232280, 2.383850, 0.319680, 0.291970,
0.049040, 1.082160, -0.348430, 1.198500, -3.042660, 1.098620, -0.740980, -0.523160, 0.344750, -1.476670,

-0.114630, -0.284840, 0.357260, 0.655580, -1.108630, -0.109170, 0.387140, -0.164700, 0.110050, -1.592630,
0.409700, 0.153740, 0.613620, -0.964160, 0.227070, 1.867380, -0.017860, 0.183090, -0.851980, -0.703970,
-1.083490, 0.305930, -1.382240, 0.006070, -0.056210, 0.550880, -1.017990, -0.378160, -0.196090, 1.135490,
-0.258260, -1.220750, -0.559390, -0.385750, 0.568050, 0.139670, -0.813300, -2.379090, -0.581880, 1.361300,
-0.372950, 0.443450, -0.729820, 0.891320, -0.292450, 0.292190, 0.733430, 1.550300, 0.436680, 0.262110,
0.280440, -0.197820, 0.302640, -0.898930, -1.538420, -1.793710, -0.203630, 0.934370, 1.052210, -1.206220,
-0.273000, -0.932770, 1.046900, 0.405830, 1.441650, -1.177530, -1.098510, -0.070110, -0.417800, -0.268720,
-2.388020, -0.051370, -0.892580, -0.028460, -0.993090, -0.056000, 0.768950, -0.759630, 0.086480, -0.507940,
0.477370, 0.612360, 0.259780, -0.121930, 2.032760, -0.212380, -0.697070, -0.261530, 1.523010, 0.749080,
0.128830, -0.414340, 0.701820, -1.049880, -0.256550, -1.376930, -0.230700, 0.475110, -0.191950, -1.230940,
-1.927440, 0.373670, 5.515550, -2.639050, 1.104620, -4.419930, -1.999920, 0.140170, 0.358760, 0.541750,
-0.892210, 1.043950, -0.028980, 0.303390, -0.257700, -0.085490, -0.427890, -0.439830, 0.338990, 0.378710,
-0.410720, 0.856500, 0.222280, 0.731490, 0.684560, 0.598940, -0.587670, 0.500770, -0.881550, 0.404740,
0.742200, 0.448130, 0.496130, -0.554720, -0.678530, -0.580000, -0.257640, -1.093130, 1.315750, -0.054980,

0.623150, 4.498450, 0.911200, -0.839160, 8.890160, 0.234270, 0.253510, -2.415040, 0.279070, -0.283730,
-9.407370, 1.411410, -0.464380, 5.043090, -0.094010, 0.146210, 2.949650, -4.464570, -0.355830, 3.671710,
3.253500, -0.297760, 2.687770, -0.817510, -0.826410, 0.979050, 0.898610, 0.895950, -11.658850, 0.648000,
1.470620, 3.859400, -1.408300, 0.771200, 4.425860, -1.244110, 0.680040, -2.308130, 5.286910, -0.155590,
-0.934490, -32.097229, 0.799860, -0.406140, -20.795679, -0.430440, -2.981450, 5.333790, 0.067310, 0.448150,
-15.239900, 0.432580, -1.375520, -9.696090, 0.503870, 0.558990, -0.789020, 0.077030, 1.471680, 0.260870,
2.830270, 2.858380, -0.754140, 0.135900, 1.078630, 0.274510, -0.189070, 2.594570, 1.173400, -0.391900,
-0.797510, -0.275360, -0.484170, 2.604310, -1.804470, 0.554570, 1.443370, -2.254120, 0.322200, 0.642020,
-0.106420, 0.913870, 0.945160, -3.187860, -0.545900, -4.818530, 0.235320, 0.493770, 13.991250, 0.641500,
3.505570, -2.662430, 1.691580, 0.875260, -4.482150, -0.795240, -2.055750, -4.072610, 0.079390, 2.276650,
-0.035020, 3.966050, -0.116470, -9.717300, -4.946480, -10.588970, -5.455600, -1.730930, 3.721130, 1.727980,
3.279840, 1.082720, -0.367360, 0.232120, -0.520930, 1.581000, 1.372180, 3.353840, 0.320790, 0.262030,
-1.884590, -6.117330, 0.450010, 0.816340, -0.598850, -0.673250, 0.221640, 0.137590, -3.008670, 0.677170,
0.009150, -6.178370, 0.289660, 0.727840, 0.312540, -0.056180, -0.283510, -0.380000, 0.558020, -1.702100,

0.319340, 0.779110, -0.348900, 0.577080, 0.474100, -0.473950, -0.144630, -1.556150, -0.825150, -1.053730,
1.240010, -0.271150, 1.272140, 1.085390, -0.495650, 0.841550, 2.137660, 0.006200, 0.447300, -3.065190,
-0.012150, -0.595810, -0.250380, 0.290550, -0.351080, 0.597630, 0.005890, -0.310590, 1.133530, 0.865520,
0.034620, 0.188120, 0.543500, -0.042440, 0.839680, -0.375970, 0.602130, -1.506690, 0.259390, -0.565310,
-0.319790, -2.038330, -0.528660, 5.881310, 1.747750, -0.961830, 0.861420, -1.463560, -0.199420, -1.903000,
1.166120, -0.877020, -0.522430, -0.407530, 0.470550, -0.430720, 1.400720, 0.306620, 0.892380, -0.159160,
-0.427340, -3.652260, 0.438210, 0.024000, 2.110880, -0.286980, 0.033830, 1.282430, -0.263280, 1.210630,
-3.220220, 1.650720, -0.281230, 0.624990, 0.218610, 0.611560, 3.850440, -0.224110, -0.771920, -2.804230,
-0.573500, 0.694760, 2.848020, 1.585330, -0.739910, 0.740340, 0.197390, 0.598950, 2.499710, 0.342330,
-0.825400, -2.006510, 1.157930, -0.560770, -0.734490, -1.185750, 0.944120, -0.803100, 0.812800, 0.623960,
-0.317270, -2.259810, 29.668150, -6.613850, -0.771680, -4.015520, -12.933470, 7.652510, 0.247860, -3.365850,
-5.205470, -1.366900, -0.242240, -0.446130, -0.197330, -0.121370, -0.052980, 1.718690, 2.677140, 1.987540,
1.709240, 0.425570, 0.940880, -0.144810, 0.471920, -0.039170, 0.089180, -0.793010, 0.964230, -0.624130,
0.274470, -0.950450, -0.342750, 0.381300, 0.230690, -0.197720, 0.022790, -0.988390, 0.858630, 0.471130,

-0.318660, 0.512820, 0.314010, 0.108660, 0.574410, 0.708350, 0.575050, 1.577420, 0.233390, -0.109070,
0.973650, 0.362870, -1.157330, 0.704390, 0.532170, -1.197300, -0.707860, -0.912760, 0.760900, -0.483830,
0.072050, 0.016770, 0.866960, 0.781240, 0.757750, 1.238750, 0.285230, 0.489340, -0.710790, -0.519260,
-0.241730, -0.356430, -0.935450, 1.160610, 0.325090, -1.059920, -0.302100, -2.086660, 0.393750, -2.999050,
0.117190, -0.710250, 0.779530, -0.297800, -0.828020, -0.588680, -0.282010, -0.472290, -3.273770, -0.401970,
-0.521660, -3.566250, 0.258830, 0.123300, -0.439260, 1.143720, -0.173110, -18.044340, 0.348620, 0.458420,
2.503690, -1.146830, -0.123970, -16.371441, 0.020570, -0.613360, 4.896420, -0.760630, 1.337960, 2.234270,
0.799240, 1.435780, -2.022890, -0.168010, -0.047220, 2.620280, 1.032700, 0.803460, 0.060370, -0.385390,
-0.342450, -0.410280, -0.413660, 0.569070, 0.909300, 0.261110, 0.050460, -0.060270, -0.801870, -0.417100,
-0.818630, 0.026680, 0.353910, -0.394100, 0.478010, -0.900250, -0.827710, -0.515830, -0.773100, 1.300510,
2.840680, 1.457730, -0.764480, -2.114220, -5.449170, 1.373500, 2.535890, 4.607820, 1.587390, -0.887090,
-4.393250, 0.075530, -0.944440, 0.722440, 0.016570, 0.979660, -1.036590, -0.266460, -0.505290, 1.573040,
-0.183300, 1.245900, 0.311710, 0.182740, 0.007260, -0.428610, -0.531800, 0.869000, 0.292880, -0.227420,
0.846800, -0.463140, -0.344350, 0.200300, 0.449750, 0.412590, 0.696210, -0.734070, 0.571520, -1.223300,

-1.841670, 0.579320, -1.496990, 0.532940, -1.485380, 0.001720, -0.186070, 0.609550, 0.765310, 1.042510,
0.310390, 0.109300, 1.707410, 0.298210, 0.434460, -0.678480, 1.220840, 0.019200, -0.304840, 0.560450,
0.196680, 0.348130, -1.877930, -0.240450, -1.830700, -0.793490, -0.785900, 0.059210, 0.416610, 0.033260,
-0.429920, -0.542320, -0.162620, -1.730720, -1.580200, -0.887110, 1.150990, 4.986670, 0.903040, 0.336640,
-1.510870, -0.831860, -0.171350, 2.493380, 0.553630, 2.468750, 0.204970, -0.078050, 0.741210, -1.913340,
-0.184610, -2.241750, 0.607690, -0.435250, -1.437640, -0.044930, 0.980770, -1.829920, -0.451090, 0.369450,
1.648180, 0.988220, -0.341770, 0.302060, 0.813760, -0.314500, -0.398040, 0.123070, 0.552110, -1.769210,
-0.530180, 0.162080, 1.489700, 1.517150, 0.410080, 0.116310, 0.926060, 0.496350, -0.146060, -2.303100,
-0.594350, -3.746130, 3.515580, -0.284700, 2.150880, -0.841600, 0.515220, 1.587210, 0.797540, 0.548040,
-0.537140, 1.653940, -0.524200, 0.490270, -0.061550, 0.053810, 0.089530, 0.547530, 0.713810, 0.282070,
-3.182520, -2.091750, 2.342110, 6.860040, -4.624250, 5.463000, -9.822290, 1.179400, -1.951970, 1.096980,
0.215280, -0.231550, -0.690410, -0.132080, -0.557260, 0.413620, 0.309720, -0.937900, 1.657750, 3.016630,
0.358370, 1.662030, 0.055290, -0.258760, 0.187590, -0.836500, -0.743370, -0.445750, 1.449860, -0.042280,
0.127080, -2.627840, -0.343650, 0.048170, 0.240800, -0.184960, 0.625410, 0.107210, -1.200420, -0.136320,

-1.353450, 0.173050, 1.240110, -1.316540, 0.333070, -0.461250, -1.502430, 8.521280, -1.566890, 0.229620,
1.415970, -0.776490, -0.724760, 0.567720, 0.691510, 3.461880, -2.565290, 0.533080, 1.482210, -2.093950,
-0.208230, 0.603340, 3.583940, 0.554460, -1.804510, -11.234870, 0.528110, 1.827880, -2.140690, 1.344020,
-0.131040, -0.798790, 0.492250, -1.467030, 0.422210, 0.247540, 1.123590, -5.202240, -1.428590, 0.238990,
0.864610, -0.033910, -0.323920, 5.995310, -1.885720, -2.626660, 2.853540, 0.051080, -2.852030, -0.098590,
0.459450, 1.039600, 1.992340, -6.003240, 1.118760, -2.982550, 0.450470, -0.149790, -2.183950, -2.289040,
-0.340990, 14.394590, -4.244670, -0.354130, -17.204269, -4.497980, 1.067770, -12.038280, 4.833580, 0.431640,
15.728670, 6.178140, 1.233710, 2.931620, -9.178520, 0.148480, 2.699490, 2.587310, 1.178120, 4.174920,
-8.079390, -0.550700, 10.240160, -10.843540, 0.984710, 2.332430, 14.801330, 0.417020, 0.326200, -20.777370,
0.180660, -24.678591, -23.189310, -0.553720, 45.362019, 9.973970, -0.055680, -157.707474, -10.450810, 4.389440,
1.797530, 2.451770, 1.307770, 9.989560, 3.500660, -0.234490, -4.811750, -10.091990, -0.910460, -12.330790,
5.411290, 0.853780, 0.716700, 0.395570, 0.511080, -0.212010, -0.205760, -0.579100, 3.451480, 4.567570,
3.814910, -1.682840, -1.611860, 0.666900, 0.688160, 0.047650, 0.605590, -2.749640, 1.543240, 0.867210,
-0.440670, 2.598800, -1.643400, -1.608120, 1.054770, 0.768530, -0.687130, 0.581750, -2.056240, 0.226200,

-0.312080, -0.982990, -0.714280, -0.575980, -0.100950, 0.107310, -0.745230, -0.646190, -0.830360, 0.392630,
1.377860, 0.257590, -0.553190, -1.006710, -0.788100, -0.380320, 0.720830, -0.112320, 0.237000, 0.159210,
0.582640, 0.680550, -0.133290, 0.890000, 0.558170, 0.630320, 0.837430, 0.761270, 0.713830, 0.309400,
-0.227190, -0.262060, -0.200750, -0.001190, -0.341380, 0.710910, -0.236980, 1.231320, -0.590200, 0.703720,
-2.357510, -1.033760, -0.980010, 0.318960, 0.456720, 0.279050, -3.540010, 0.893910, 0.180230, -1.120620,
1.175410, -0.448570, 3.242830, -1.739580, -2.691300, -1.411960, -0.018000, 2.082200, -0.483750, -0.815370,
-0.645460, 0.733170, -0.161660, 1.601190, 0.410960, -0.848280, -0.693440, -0.783720, -0.648500, -0.765760,
-0.158150, -0.471730, -0.012860, -0.564970, -0.652070, -0.190220, -0.007500, -0.072640, 0.715960, 0.312470,
0.303820, -0.648740, -0.254030, -0.700400, 0.743050, -0.231380, 0.555310, -0.794440, 0.394710, 0.744840,
-0.193720, 0.475620, -0.011240, 0.291210, 0.236700, -0.037440, -0.682870, -0.396380, -0.533930, 0.537310,
0.545420, -0.418560, -0.503570, -0.169870, 2.562090, 3.032270, -0.686000, 3.236170, -0.697860, 0.795720,
1.269050, -0.764800, -0.005600, 0.441000, -0.216120, -0.261910, 1.065590, -0.333170, -1.109450, 0.666340,
0.336080, -0.509920, 0.506490, 0.137120, -0.414840, 0.242300, -0.411630, -1.019860, 0.034570, 0.041260,
-0.496760, 1.138660, 0.432670, -0.256950, 0.117070, 0.015920, -0.652720, 0.059160, 0.600060, 0.817230,

0.179150, 0.363530, -0.352930, 0.706940, 0.575430, 0.174000, -0.538790, 0.624490, 0.552350, 0.013340,
-0.256170, 1.302020, 0.580220, -1.017920, 0.267810, 0.669400, -0.513630, 0.882170, -0.108890, 2.372110,
0.428310, 0.749160, 0.633010, 0.206980, -1.408350, -2.825550, -0.744330, 0.618270, 4.115310, -0.578250,
0.991960, -0.115220, -0.699170, 0.448550, -3.782390, 1.527520, -0.642860, -0.565540, 0.227290, 0.674180,
-0.599100, 0.799540, 0.743130, -0.787880, -0.135910, -0.165580, -1.387310, -0.231180, 0.893150, 0.692810,
-0.099850, -0.314140, -0.169760, -0.059240, 0.407300, 0.065910, -1.027660, 0.600460, -0.542140, 0.374380,
0.836990, 0.177110, -1.649440, -0.028440, -0.043170, -1.456300, 0.986010, 0.588850, -0.719050, -0.856560,
-0.599970, -0.395320, -0.124440, 1.559160, -0.508110, 0.773860, 0.689450, 0.905230, 1.378790, -0.524030,
-0.066260, -1.344990, 0.636290, 0.769540, 0.724150, 0.349530, 0.450170, -0.277920, -0.805270, -0.458090,
-0.693200, 0.377170, 0.384100, -0.586780, -0.835760, -0.809590, 0.286290, 0.241770, -0.489970, -0.293100,
-1.875220, -1.500200, -1.070060, 7.604270, 0.401240, -6.422950, -0.072210, -0.801760, -2.423280, -4.601130,
1.264940, 0.353150, -0.530410, 0.463990, 0.315540, -0.060420, 5.304040, -0.068080, 0.253740, -1.776670,
-2.050720, 0.385680, -0.576770, -0.767830, 0.569450, 0.006790, 0.381470, -1.975420, -1.516570, -0.335440,
-0.287610, 1.038640, -0.619770, 0.168330, 2.826380, 0.097980, 0.523230, -0.442880, 0.533840, -1.166330,

3.742580, -1.143040, 0.962800, -2.253690, 0.085000, -0.332430, 1.252460, 2.157540, -0.142070, -0.938500,
-2.621360, 0.259090, 1.254740, 1.308550, -0.758680, -0.097560, 2.322380, -0.161560, -4.271290, -4.755960,
0.746170, 0.499950, -2.377080, 0.566450, -0.716830, 0.834840, -1.029670, 2.066520, 0.571430, -0.533730,
0.907040, -0.849530, 0.990770, -2.452750, -0.409020, -0.158880, 2.279230, 0.236130, 0.171080, -1.164550,
0.371190, -0.749610, -0.225160, -3.198420, -0.126840, -2.106940, 0.742960, -1.292770, -0.287700, 0.433180,
-1.712460, 1.746630, 0.523410, 3.311230, 0.492790, 0.075210, 0.494970, 5.319760, -0.049260, 0.919170,
-5.399630, 0.181990, -0.809170, -5.837470, -2.311010, -4.355340, -4.585410, 0.930180, 1.053610, 4.597360,
-0.225140, -0.332400, -3.736540, -1.012410, 0.346330, -8.429000, 0.772910, 0.791380, 15.935010, 0.407710,
-0.447110, -0.475300, -0.403390, 0.567880, -18.001141, 0.092710, 0.592030, 8.865270, -1.727800, -0.315170,
30.822479, 0.252200, -0.135420, -19.138611, -0.857580, -1.620860, 2.386070, -0.596010, -1.448370, -2.913100,
-0.233440, -2.743020, -4.131790, 8.572730, -6.221380, 46.338268, -10.803910, 15.613790, -2.043790, 3.860520,
-7.510630, 0.622030, 0.424700, 0.482420, -0.695840, -2.343850, -1.000740, 0.100140, 0.064280, 1.504620,
-2.060640, 1.780470, 1.176210, 0.605730, 0.565190, -0.912320, 0.251220, 1.996610, -2.625860, 1.238760,
0.473860, 2.208090, -0.854100, -0.191210, -4.010210, 0.658760, -0.025700, 0.461100, 1.385850, -1.850630,

-0.053980, 3.210590, -0.192330, 0.157180, 1.088720, -0.123490, -2.147950, -0.994300, -0.131720, 0.436000,
-0.561600, -0.716280, 0.985390, 0.385170, 0.171070, -0.419300, 1.768510, 0.435380, -0.814730, -1.814870,
0.454920, 2.555030, 0.447220, -0.081250, 0.495290, -1.142890, 0.697990, -4.062900, 0.645050, 0.121700,
4.237150, -1.066140, 0.797540, 4.805290, -3.301760, -0.958590, -4.186460, -0.500220, -0.611590, -3.555860,
-0.000060, 0.835290, 2.472890, 0.770600, -0.394560, -3.650170, 0.315350, -0.892590, -2.715670, 0.212200,
-0.518620, 1.563080, 0.546990, 0.756620, -5.476230, -4.052580, -0.325450, 7.883760, -0.807530, 0.024000,
-2.799450, 0.716650, -0.971840, 16.205580, -3.322800, -0.179490, -3.948880, -0.273210, -0.969850, 2.521620,
-0.188240, 0.020920, 8.638560, -3.293760, -0.303000, -6.995150, 0.339940, -0.409730, -0.183110, -0.219980,
-0.691930, 1.950210, 0.436360, -0.349450, -0.132840, -0.359610, -1.737030, -0.316270, 0.442290, 0.600700,
-0.198170, 0.220300, -0.553140, -0.836360, -0.316000, -0.583480, -1.205320, -2.122750, 1.258180, 3.070910,
4.398580, 1.227260, 0.170640, 0.025960, 0.606050, 4.820400, -5.798270, -0.787470, 2.938700, 0.970560,
-23.145420, 0.615820, 0.023800, 0.556370, -0.092650, -1.311270, 2.659660, 1.009060, -0.778690, -0.133140,
-14.011520, 1.513470, 0.979180, 0.813020, 0.572020, -0.299570, -0.308370, 1.284650, -0.896520, 0.616100,
-0.155070, 0.789440, -0.548650, 1.210980, -0.426560, -0.667340, 0.237170, -0.413070, 0.538690, 0.229150,

0.491510, 4.225090, -0.762380, 0.354670, -2.216870, -0.621230, -0.350460, -0.057660, -1.260570, 0.299150,
-0.160280, 0.854180, -0.215270, 2.522920, 0.501680, 2.985600, 0.068010, -1.104900, -2.399470, -1.332610,
0.673950, -1.395940, 0.414070, -0.940360, -3.911230, -2.261760, 0.840650, -1.486410, -2.343890, 0.969660,
1.095260, 1.352350, -0.496390, 3.336990, -4.527860, -0.765760, 1.101310, -0.460390, -1.413190, -1.309590,
-2.652480, 0.132120, -0.325050, 4.165040, 0.134410, 1.388140, -7.214310, 2.072620, -0.802640, 0.683880,
-3.242900, -0.996250, 7.789130, -1.846660, -1.962410, 2.038390, -3.945400, -2.300170, -2.354380, 0.977160,
0.950000, 3.797350, 0.171130, -0.322600, -5.761420, 1.449030, 2.734730, 13.593170, -1.110110, 0.783090,
-11.611210, -2.820880, -1.167750, 5.906100, 0.165170, -0.923630, 0.911900, 0.116760, -0.969240, 3.092860,
-0.367880, -1.084650, 5.366760, 0.873280, 0.635770, -5.669340, 3.598790, -0.629680, 12.475030, -2.128570,
-1.491900, -3.120180, 2.522360, 0.508220, -13.602970, 0.883260, -0.016920, 19.359541, -4.792200, -2.500450,
-2.949650, 5.955830, -4.024790, 3.020210, -18.018530, 19.611349, -3.997330, 18.141380, 14.616390, -7.502100,
1.521110, 2.942550, 0.310560, 0.640060, -0.797280, -1.417220, -1.694740, -1.908260, 0.629130, 3.140260,
-5.134690, -2.760460, 1.489370, 0.306290, -1.881300, 2.055990, -1.330270, -0.235050, 0.704390, 0.174340,
-0.702800, 1.327800, 0.424200, 3.625220, 1.242540, 0.272170, -0.627880, 0.428000, 1.287410, 2.274810,

-1.076360, 3.058380, -1.320200, 0.156810, -0.247360, 0.384050, -0.740360, 0.170190, 0.405800, -0.224410,
-1.515000, -0.037660, 0.217620, -0.032260, -1.139900, -0.101610, 0.419320, 0.495760, -0.484400, 0.904640,
0.456360, -0.221990, -0.348640, 0.179210, 0.654880, -1.018390, -0.123570, 0.202750, -1.328920, -0.371250,
0.065810, 0.568480, -0.038450, -0.799180, 0.107410, 0.124700, -0.725240, -0.067530, -2.523450, 0.013200,
-0.711390, 0.397130, -0.208880, -0.997030, 0.984700, -0.184800, 1.210650, 1.873060, 0.190830, 0.017500,
-0.006410, -0.278940, -0.955160, 0.381170, -0.050990, 0.262370, 0.949270, -0.062530, 0.177590, -0.032560,
-0.112690, -0.442620, 0.054020, -0.592160, 0.129110, 1.113260, -0.305530, -0.161700, -0.028840, -0.141340,
0.889680, 0.589410, -0.254740, -0.735010, 0.347840, 0.786380, 0.902720, -0.467260, 0.760930, -0.383390,
0.593530, 0.006570, -0.421120, 0.001400, 0.378900, -0.486630, 0.160990, -1.470550, -0.295060, -0.640670,
-0.581630, 0.484680, 0.674250, 0.632190, -0.021460, -0.126110, 0.370980, 1.086780, -0.616680, -0.123550,
0.166250, 0.486770, 1.098140, -0.743510, 4.605420, -3.352280, 4.404530, -0.707310, 2.425420, -0.017720,
-0.723120, -1.030770, -0.321870, -0.715950, 0.365870, 1.842290, 0.590240, -0.446480, -0.067350, 1.595820,
0.324430, -0.373070, -0.809230, 0.287090, -0.537930, 0.685130, 0.599330, 0.728830, 1.884770, -0.614750,
-0.574030, -1.049690, 0.106560, -0.286330, -1.356130, 0.450310, -0.081450, 0.700640, -0.565330, 1.012410,

0.012800, 0.553620, 0.688780, -1.458520, -0.114810, -0.321750, -1.085690, -0.609230, -0.182150, -0.983960,
-1.070720, -0.623450, -1.313240, 0.653950, -0.662420, -2.431400, -0.188830, 0.424870, 1.246560, -0.033680,
-0.466850, 0.800340, 0.246720, 0.569820, -0.337720, -0.489210, 0.773730, 2.596700, 0.998190, -0.468740,
1.405230, -0.159330, 0.048980, -7.862480, 0.276860, -0.266710, 0.058050, 0.305830, 0.291800, -4.452660,
-0.706770, -0.044000, -10.353330, -1.341810, -0.490400, -13.308240, 1.829110, -0.778080, -4.102640, -2.017070,
1.088160, 0.367170, -0.176760, 0.450700, -10.206940, 0.079300, 0.842770, 2.396490, -1.130070, 0.699430,
0.705640, 0.725820, -0.349420, -0.683900, -2.767530, 0.587820, 0.955830, -1.436990, -0.566520, -0.300010,
0.402370, 0.251040, -0.602880, 0.003770, -1.105030, -0.327350, 0.013190, -0.268360, -0.075840, 0.547530,
-0.082840, 0.057810, 0.004500, 0.724020, 1.925580, -1.404900, -0.220070, -0.930030, 1.224970, -0.431570,
0.222250, -0.527760, 0.036730, -0.338120, 0.043990, 0.960460, 0.079160, -0.484420, 0.262840, 0.058950,
-0.212900, -1.077350, -2.446300, -3.429130, 0.138240, 1.996280, 0.008450, -1.032000, 0.203260, -4.436760,
0.452160, 0.339580, -0.426340, 0.495350, 0.666290, 2.784590, 9.386670, 0.008320, -0.776270, 2.093800,
2.567430, 0.540980, 0.534970, 0.513210, 0.487490, 0.457250, -0.215890, 0.449810, 2.956070, -0.972290,
0.465270, -0.943360, 0.842010, -0.005890, 0.643680, -0.862210, -0.401480, 0.495810, -0.769580, 0.592460,

-0.183920, -0.013950, -1.005390, -0.713480, -0.052850, -0.315810, 0.607540, 0.308810, -0.334210, -0.322490,
-0.454140, 0.184350, -0.174580, 0.582820, -0.247040, 0.593660, 0.607040, 0.842440, 1.681110, 0.241950,
0.423150, -0.533550, 0.654150, 0.072920, -0.572940, -0.820650, 0.337840, 0.378460, -0.900500, -0.272830,
-0.911130, 0.392800, 0.567560, -0.787950, -0.811500, 0.193840, 2.958640, 1.489070, 0.765980, 0.511350,
0.747960, 0.088920, -0.146150, 0.763590, -1.183810, 0.318840, -0.080740, 0.115530, -0.571980, -0.579120,
-0.831550, 0.780000, -0.653490, 0.325250, -0.938090, 1.018540, -1.402220, -0.383300, 0.149380, -0.349140,
0.407240, -1.989250, 0.076690, 0.569090, -1.264050, 0.505200, -0.031260, 0.343050, -0.490370, 0.180040,
1.098230, 0.323140, 0.262730, -0.482390, 0.681830, 0.684180, 1.109140, -0.367700, 3.121520, 1.710220,
0.531080, -0.885680, -2.542570, -3.779910, -0.802690, -0.544940, -0.417570, -0.028650, -0.421730, -0.877880,
-0.717870, 1.129960, -0.836490, -0.383890, -0.571910, 0.061610, -0.232080, 3.032110, 0.237990, 0.223770,
1.222670, 1.837310, 0.038890, -2.769270, -7.189660, 3.369430, -6.028160, 6.149680, 1.125030, 1.146630,
-11.829830, -1.391120, -0.545050, -0.917290, -1.151170, 0.410380, -2.327550, -1.330840, -2.419690, -2.121100,
-0.962710, -0.165430, -0.078890, 0.920480, 0.271660, 0.848750, 0.539800, 0.597870, -0.290830, 0.356560,
0.133010, -0.260630, 1.061940, -1.922180, -3.129650, 0.468350, -0.030240, 0.041790, -0.433080, 0.356120,

1.277560, -2.300790, -1.484690, -0.563110, -4.266910, 0.876790, 0.917110, 0.414980, -1.993050, 0.283450,
0.110180, -0.482050, 0.636210, 9.633650, -0.512740, -1.409890, -1.652690, -0.240270, -0.484170, 1.539260,
0.928930, 0.701190, 2.695840, 0.503550, -0.116340, -3.847860, 2.186710, -1.020540, -3.014360, 0.741700,
0.220700, 0.170460, 1.321570, -1.832360, 10.526460, 1.646760, 0.562060, -2.013150, 1.786260, -0.030420,
-1.547050, -0.100880, -0.142240, 32.715439, 0.348670, -0.850050, -19.452551, 0.852420, 0.370750, -15.723140,
-0.202120, -0.106590, 38.663910, 0.157280, 0.120890, -3.355840, -0.768360, -1.373570, 25.953310, -1.206160,
-0.928840, 26.699341, 6.272680, -0.546100, 30.773491, -2.482130, -3.272890, 3.174110, 0.595290, -0.028560,
7.502080, 1.288380, -2.741950, 19.041590, -0.829230, -2.585590, -14.662380, -2.297360, -0.173470, -1.078280,
1.206210, -4.171240, 11.061250, -1.575640, -0.761240, -0.856100, -3.288190, 0.388380, -6.382640, 1.399370,
0.386240, -2.937310, 0.412240, 0.616780, 5.805430, -0.947340, -0.640900, -1.551080, 1.115480, -1.004440,
3.397340, 0.249420, -0.400090, 2.099510, 0.377230, -0.716500, -0.953980, 0.170250, 2.493120, -4.695020,
-4.776920, 1.435790, -0.358800, 0.248840, -1.123520, 3.476080, 17.693100, -0.014040, -1.086340, -13.892260,
-0.239830, -0.124550, 0.296710, -0.263580, 1.226160, -2.708460, 0.031710, 2.676350, -1.652980, -2.458430,
0.340850, -0.971600, -2.878640, 3.257750, -1.732610, -0.176350, 1.928730, 0.477450, 3.465840, 8.232330,

-0.528560, -0.736490, 0.246920, -0.838820, 0.644790, -0.526610, 0.507440, -0.302960, 0.549030, -0.056450,
0.056550, 0.086200, 0.102250, 0.467420, 0.798700, -0.422090, 1.093650, -0.289110, 0.076370, 0.995580,
0.648770, -0.657000, 0.137350, -0.100220, -0.122600, 0.785270, 0.876200, 0.132520, -0.025680, 0.477970,
0.287300, -1.340720, 0.815730, -1.079840, -3.968220, 0.494290, -0.070440, 2.386850, 0.027230, -0.868100,
-1.187350, -0.076520, -0.541470, -0.526570, 0.882200, 0.735140, -0.376520, -0.666450, 0.203850, 0.120060,
0.400420, -0.557720, 0.573840, 0.790730, 3.592030, 1.912390, -0.629830, -0.613960, -0.819230, 0.069330,
-0.327340, -0.363910, -0.494110, -1.416910, -0.473990, 0.469820, 1.005280, -3.690810, 0.134300, 0.899740,
-0.175490, -0.163160, -0.404290, -0.691800, 0.270370, -0.736750, 0.048340, 0.273340, -0.569630, 0.534260,
-0.666460, 0.174660, -0.959730, 0.990800, 0.004190, -0.873700, -0.273370, 0.599630, 1.670130, 0.562390,
-0.861090, -0.125960, 0.419450, -0.639540, -0.509930, -0.664530, 0.973050, -0.598420, 0.540440, 0.546020,
0.839240, -0.761100, -0.980970, 0.464540, -0.187440, 0.767120, -3.159200, -3.940700, 0.684310, -0.722900,
-11.811000, 0.679480, 0.490440, -1.012050, -0.456730, -0.134800, 0.933450, -0.303530, -0.261510, -2.610670,
-0.190900, 0.020170, -0.078260, 0.609710, 0.581400, -0.768240, 0.134610, -1.560210, 0.650720, 0.147180,
-0.077840, 2.156180, 0.739280, 1.128600, 0.811240, -0.846630, -0.618610, 0.369280, -0.142010, 0.440670,

-0.382800, -0.100140, -0.065670, -0.223020, 0.503920, 0.736680, 0.243970, -0.511440, -0.299220, 0.528370,
0.552240, 0.356070, 0.103580, 0.564070, -0.033820, -0.192760, -0.510010, -1.298910, -0.321470, 0.384190,
0.435440, 0.638350, -0.043330, 0.358720, 0.146510, -0.034630, -0.906710, -0.915790, -0.168220, -0.358490,
0.089910, 0.439150, 0.553350, -0.632280, -0.528700, -1.010910, 0.039230, 0.390880, 0.832430, 1.304150,
-0.782480, -1.159990, -0.563910, 0.178480, -1.370370, -2.609340, -1.450550, 1.956650, 0.589900, 0.367330,
0.316460, 0.228220, 1.619130, -1.151830, -0.383800, -1.368450, 0.538540, -0.032970, 1.535560, -0.315610,
0.125100, -1.301560, -0.878260, -0.907230, 1.659630, 0.379290, -0.201470, -0.237560, -1.018270, 0.458110,
-1.171430, 0.415760, 0.278680, -0.797400, -0.945110, -0.863590, 0.740820, -0.643630, 0.465210, 0.607210,
0.994280, -0.723640, -0.264540, 0.002890, 0.138790, 0.710660, 0.413380, -0.266930, 0.398590, -0.227790,
0.169650, -1.685460, -0.589600, 0.078070, 0.517900, 0.723610, 0.132160, -0.354000, 0.109520, 0.391700,
0.400830, -0.187540, -2.160940, 0.302500, -0.951630, -0.958800, -1.006630, 0.381580, 0.382680, -0.395080,
2.065980, 0.302810, 0.451870, -1.006840, -0.604800, 0.157300, 0.710400, 0.554530, -0.755090, 0.787890,
-0.409780, 0.717520, 0.449820, 0.741140, -0.641380, 0.149410, 0.192540, 1.165870, -0.767810, 0.412080,
0.148660, -0.084020, 0.023400, 0.437630, -0.815540, -0.324060, 0.432020, 0.410330, -0.808630, 0.211810,

-1.070400, 0.408420, -0.614290, -0.013130, 2.128040, -0.823430, -0.769130, -1.408950, -1.631510, 0.102150,
-1.367620, 0.334760, -0.297240, -1.256020, 0.826470, 0.995400, -0.385670, 0.675640, 0.898090, -0.138100,
0.550870, -0.458920, 2.006430, 0.487750, 0.165890, -0.321740, -0.480830, 0.022060, -0.903290, -0.978500,
0.299810, 1.321940, 0.380300, 1.231030, 5.683860, 0.064410, 0.378060, -1.101710, 0.293070, 0.448700,
-1.076790, -0.437930, -0.775760, 1.959160, -0.883300, -1.412990, -0.992780, -2.079560, -0.540420, -2.212680,
0.995350, -0.539280, 0.374950, 0.652720, 0.929170, -3.915150, -0.201560, 0.518970, 1.255710, -1.368790,
0.483000, 0.441750, 0.396670, -0.360550, 1.691720, 1.252720, 0.694310, -2.046860, 0.174210, 0.487350,
2.428690, 0.517450, 0.504370, 1.009480, 0.280620, -0.177250, -3.091620, 0.732950, 0.251640, 1.872590,
-0.045080, -0.617700, -1.212010, 0.877150, 0.416080, 3.302050, 1.331410, 0.144260, -6.631890, -1.026730,
0.309190, 7.108390, 1.403230, -0.690650, 0.564760, -1.350920, 0.313010, -1.304120, 0.351720, 0.535580,
-1.139740, -1.011080, -0.458230, 5.259190, 9.929730, -17.789829, -3.343880, 12.715410, 5.681390, -8.811400,
-0.341650, -0.836830, 0.506280, 0.119630, 0.004390, 1.510290, 0.137130, -0.520360, 0.010750, -1.649400,
0.081990, -0.135500, -0.307510, -0.332180, 0.363790, 0.566530, 0.491620, 1.220850, -0.877100, -0.515400,
0.019110, -0.879230, 1.389990, -0.580210, 0.606780, 0.461860, 0.661210, 0.638930, -0.505570, -1.012850,

-1.429470, -0.395390, -0.376720, 0.843850, -0.008350, 0.768130, -0.247590, 0.389320, 0.278030, 0.579770,
0.630250, -0.273700, 0.043640, -0.160060, -0.698190, -0.913670, -0.180590, -0.352000, 1.200800, -0.289380,
0.611910, -0.706210, -0.414930, 0.049790, 0.025830, -0.080310, 1.061390, -0.574930, 0.820950, -0.813460,
-1.055330, -0.589500, 0.965850, 1.426000, -0.793300, 1.393950, 0.410900, -0.238630, -0.343910, -0.385580,
0.284510, -0.786860, 0.052020, 0.606770, 1.001530, -0.185630, 1.102900, -0.517680, 0.279160, 0.418670,
-0.806440, 1.047100, 0.234740, 0.546920, -2.090290, 1.100210, 0.913000, 2.219560, -0.761630, 0.647070,
0.255660, -0.264830, 0.450560, -0.116340, -1.601660, 0.728680, 0.643460, -0.948280, 0.645730, 1.443240,
1.763940, 0.344500, -1.207770, -1.219890, -0.656020, -0.219840, 0.570120, -0.477000, -0.360730, -0.746880,
-0.013670, 0.091270, -0.170340, 1.025020, 0.133880, 0.311930, 1.024320, 0.066930, 0.497560, -0.781510,
1.223850, 0.404380, 0.365980, -0.185470, -0.325010, -0.224140, 0.955040, -0.162690, 0.421160, -1.414640,
-0.133920, 0.887380, -1.924390, -5.529340, -5.992330, -1.956790, 6.739850, 5.229660, -6.819170, -6.557890,
0.130400, 0.331330, -0.323910, -0.134700, -0.418610, 0.148530, -0.115310, -0.806880, 0.315900, 0.055310,
-0.961580, 0.691940, 0.160080, 0.825430, 0.370310, 0.165010, -0.628690, -1.125880, -0.919190, 0.264640,
-0.409480, 1.578960, 0.091200, -0.068690, 1.820670, -0.285760, 0.808780, -1.130680, 0.168820, 1.019450,

-0.775220, -2.313060, -0.185610, -0.068550, -1.225340, -0.468790, -0.558850, -2.751140, 0.064330, -1.045170,
2.813980, -1.608380, 0.235540, -0.790310, -0.615120, 1.933490, -0.109150, 0.830720, -2.048400, 0.502260,
-0.527420, -0.361030, 1.569670, -0.350300, 0.496960, 0.694300, 1.114540, 0.489910, -1.578930, -0.577020,
0.039890, 0.339590, -0.736980, -1.302170, -0.763510, 1.721050, 0.350970, -0.527290, -0.455490, -1.308510,
5.966980, 0.082420, 0.163990, -8.874750, -0.183280, 1.531440, -1.224210, 1.113150, -0.757490, 7.477090,
1.085170, 1.070340, -22.790091, 0.640690, -0.063500, 5.819110, 0.498900, -2.545140, -8.901030, 1.247290,
2.819560, -0.190610, -0.165590, 0.536470, -10.600380, 0.120850, 1.774400, -5.882260, 0.954550, -1.420010,
1.810700, 0.457170, -0.885790, 5.059000, 0.536690, -0.421940, -5.720760, 0.382870, 0.718700, -0.603250,
-0.516080, -0.903240, 5.917900, 0.937980, -1.373890, -0.589830, -1.928310, 0.856250, -1.070640, 0.258740,
0.812920, 0.505910, 0.253210, -1.866020, -2.161070, 0.361350, -0.486520, 3.548170, -0.687140, -0.266640,
-0.888120, -0.561220, -2.483870, -4.340780, 4.897280, 2.163020, -0.133720, 3.158220, 0.642720, -0.272810,
7.733370, -0.578710, 0.139160, 0.005550, 0.113890, -1.814630, 1.598520, 0.402190, -1.227600, 0.024830,
-27.289370, 0.762880, 0.819030, -0.255860, 0.770340, 0.273670, -0.174430, -0.539850, -1.496940, 1.458450,
-0.657400, 0.447870, 0.725760, 0.320860, -0.331950, -2.129830, -0.664630, -0.480180, 1.345960, 1.225330,

-1.190310, -2.945210, 0.945370, 0.816420, -0.133040, -1.964310, 1.013960, 8.209340, -3.077490, 2.499680,
0.603670, 0.355730, -0.097530, 0.118310, -0.004280, -2.590570, 6.821220, -0.211190, 0.492340, -2.072210,
-0.373160, 0.064110, 1.939430, -0.055670, 0.050960, -2.297170, 0.370420, -0.741580, -6.813390, -0.405190,
0.104160, -5.978700, 0.784520, 0.444660, -1.508720, -4.899840, 1.907640, 0.687510, 0.738960, -0.368510,
-1.963480, -2.879300, -0.596230, -2.207240, -1.751780, -0.025170, 28.145679, 5.045960, -1.097030, 0.000360,
9.971610, -0.697530, -8.422680, -7.875050, -1.299190, -3.338440, 4.493160, 0.094360, -6.677170, 18.631590,
-0.704040, 18.661039, -0.414730, -0.436350, 4.978370, 19.883480, 0.706920, 9.471260, 15.736880, -0.788990,
23.944031, -9.173790, 0.171900, -1.657280, -8.765330, -0.358200, 4.506110, 4.393270, 1.161640, 35.910061,
-0.007930, 0.348210, -29.036909, 2.539100, 0.378860, 1.601120, 3.662670, -0.367120, -9.573400, 0.943370,
0.825980, 33.287689, 2.058530, 0.183580, 11.438980, 1.726450, 1.152320, -3.941800, -8.324740, 5.003240,
0.259750, -3.487970, -0.047980, -1.275850, -2.183580, 0.035500, -1.772210, -4.754950, -5.543040, -0.889810,
-35.523010, 3.638160, 3.674800, 0.264590, 1.015290, 1.673200, -1.284200, -0.548910, -15.379230, -4.875710,
1.697160, -1.604920, -0.343570, 0.207350, 0.852140, -0.007590, 0.487670, 7.843330, 0.777110, -3.146610,
1.232050, -11.755960, 0.371170, 0.471170, -4.497730, -0.072310, 0.752580, -0.808480, -1.834780, 1.161430,

0.780050, 46.309132, -1.669690, -0.804420, -17.272430, 0.538170, -0.358970, 9.390640, 1.839370, 0.424370,
13.604780, -0.985220, 0.709210, 26.563391, 0.748320, 0.161020, -0.246440, 0.806590, -0.122210, -17.191031,
-0.368360, -0.814730, 31.942869, 1.778830, -0.009240, -12.834170, -3.530540, 2.101110, -8.574140, -1.273950,
-0.120580, 10.646460, 0.448570, -2.773780, 4.418540, -0.114220, -0.567640, -9.520520, -1.477400, -0.724600,
-15.659400, -0.064780, 1.084460, -0.518450, 0.385790, -1.487080, 0.408950, -0.558900, -0.220750, -2.856370,
-0.221140, 0.494900, 0.721730, -0.438350, -0.884350, 6.347210, 1.337670, 0.082070, -1.491370, -0.239510,
2.540570, -1.200500, -0.883370, 0.807240, 0.293390, -0.545250, 1.371130, -1.985930, 0.477570, -3.465510,
-0.337600, 1.567720, 3.409560, 1.298930, 1.833800, -0.738480, 0.446870, 0.914870, 0.432140, -0.324010,
0.028240, -1.838280, 0.474670, 0.246000, 4.035010, -0.629390, -6.822050, 1.259810, -1.977290, 0.371740,
-0.173780, -0.912210, 1.116350, -0.468800, 0.676700, 2.005820, 0.735940, 1.195030, 0.960520, 1.082760,
0.606670, 4.212880, -1.192700, -10.507080, -9.494790, -1.368850, 2.150600, 8.736470, 5.487620, 1.518470,
-3.340640, 1.692540, 1.300310, -0.116100, -0.330410, 1.269780, 0.394780, 0.193770, 3.418670, 1.746770,
-5.891170, -5.154660, -2.802240, 2.106750, -1.574550, 1.015020, 0.086410, -0.279190, 4.865130, 0.477870,
-0.440230, 3.570460, 0.438580, -1.079410, 1.010620, -0.299960, 0.093300, 1.718700, -2.771670, -1.011600,

0.803500, -4.655200, -0.750550, -2.116820, 4.556360, -0.741390, 1.457500, -0.954060, -0.118860, 0.513230,
1.253980, -0.045460, 1.139020, 0.053410, -0.065320, 0.227160, -2.165290, 3.037760, 0.497600, -0.963690,
-0.251660, -0.192270, 3.493180, 0.989760, -0.117170, 3.059010, 1.055090, 0.179720, -0.236080, 1.530570,
-0.157120, -1.802670, -0.474590, 1.110110, 10.013470, -0.919250, 0.621130, -2.514280, 0.507530, -0.541920,
-4.701290, 0.601210, 2.591600, 7.631100, -0.106760, -0.075290, 8.797290, -0.956520, -0.177260, -2.523030,
0.602040, -0.685710, 18.702999, -0.263390, -0.559820, -2.057140, 0.950990, 0.106190, -13.338440, -0.238160,
-0.753530, 15.294490, -1.069890, 0.366810, 2.055580, 1.120090, 0.428530, 2.207890, -0.771860, 0.592900,
-0.350480, 0.162310, -0.657360, -2.551420, -0.759480, -1.153740, 0.194610, 0.347060, -0.962900, 0.970480,
0.234680, 3.470250, 5.894240, -0.146620, 0.794640, -6.911480, -0.561870, -0.991940, -1.598570, -0.398860,
-3.087900, 4.522070, -0.303900, 0.200490, -3.630270, 1.523640, 0.039040, 0.229030, -0.093520, 1.836780,
4.774100, 3.344410, -1.819750, -13.414630, -1.018410, -3.497650, -6.228380, -10.365190, -2.241880, -1.545430,
0.496240, 1.649030, -1.761250, -0.688030, -0.797640, 2.132960, 4.450450, 0.090010, 4.477440, -2.005350,
35.890549, -1.328250, 0.343970, 0.929000, 0.563000, 0.486440, 0.963740, 4.147990, -0.419070, -0.439970,
0.914760, -2.815460, 1.677500, -0.182180, 1.498580, 0.403520, 0.200010, 1.227080, -0.192120, -0.641270,

-0.510490, 0.167440, 0.667160, 0.610210, 1.453020, -0.670310, 0.152770, -0.276720, 0.081190, -0.586840,
0.418470, 0.764230, -0.733610, 0.489500, -0.876920, 0.389680, 0.681830, 0.763240, 0.631780, -0.677640,
0.474380, 0.420890, 0.172150, -0.505560, 0.484780, 2.410250, -1.923170, 0.082950, -3.444460, -0.675790,
-0.600080, 0.141330, 0.479530, 0.355470, -0.821830, -0.071720, -0.049650, 0.648290, -1.199010, -0.238320,
-0.831460, 0.220330, 0.944940, -0.294730, 0.290300, -0.452600, 0.276940, -0.823730, 0.535540, 0.660130,
0.083690, 0.382580, -0.976640, 3.181410, -1.187500, -1.052580, -1.001230, -0.693670, 0.163860, -0.450420,
-0.390720, 2.233470, -1.099550, -0.367680, -3.087680, -0.231810, 0.532090, 1.919180, -0.292210, -0.497790,
5.228230, -0.793870, -0.194710, -1.137260, -0.784150, 0.220890, 0.202260, 0.499210, 0.615620, 7.094100,
-0.888210, 0.063820, -3.664900, 0.211560, -0.001500, -0.060160, -1.649410, 0.729470, 3.200630, -0.495650,
-0.668770, -5.065120, -0.675360, 0.287530, -1.063500, -0.380790, 0.238870, 0.929640, 0.341490, -0.515320,
-0.825500, -0.919740, -6.046100, -0.869590, 0.203070, 0.829310, -5.720610, -0.275790, 9.066000, -1.602130,
-32.146912, 0.094540, 0.469610, 0.854770, -0.187570, 1.398800, -1.342860, -0.628200, -3.679240, -2.988570,
-2.268160, -2.495290, 0.828060, 1.140390, 0.095850, -0.464290, -0.607880, -0.739200, 1.685340, 1.106490,
0.162990, 1.563220, -0.033210, -0.728410, -2.676190, 0.012880, -0.118640, -0.733180, -0.069610, -1.274970,

0.907210, -1.195470, 0.197820, -0.399610, -0.029570, -0.478530, 1.073340, 0.927930, 1.334410, 0.669120,
0.456390, 1.815350, 0.005740, 0.676710, 0.576100, 0.149680, 0.858060, 1.662670, -0.075340, 1.350050,
0.166400, -0.461090, 0.178760, 0.782310, -0.001450, 0.422240, 0.042030, -0.474820, -0.635730, -0.409280,
-0.052100, -0.106910, 0.261420, 0.274570, 0.732250, -1.084140, -0.594620, 0.781820, -1.127900, 0.312400,
0.615090, 0.278290, -0.077290, -0.410360, 0.568840, -0.334810, -0.752630, -1.931510, -0.308870, 0.341380,
-0.180110, 0.338950, -1.070890, -1.578920, -1.136490, 0.819070, -1.416180, 1.227760, 0.234220, -1.498540,
-0.023650, -0.121230, 0.062440, 0.528760, -0.881950, 0.019020, 1.158930, -0.615820, 0.673690, -0.107840,
0.200700, -0.567400, 0.629990, 0.324110, 0.703880, 1.022020, 0.267630, 0.238290, -0.340940, -0.297940,
-0.026540, 1.256250, 1.357480, 0.295790, 0.022180, -0.889290, -0.441540, -1.975870, -0.014000, -0.835910,
0.559050, -0.288630, 0.269100, 0.366260, -1.397340, -0.247720, -0.778000, 1.750760, -1.995020, 1.210900,
-0.725770, 0.682140, -1.008210, -3.533830, -4.344910, -0.062620, 1.980500, 2.341550, -2.868720, 0.886530,
-6.020760, 0.548830, 0.591010, -1.087120, 0.728730, 1.117570, 0.492290, 0.121990, -0.825070, 0.627350,
2.787050, -0.184260, -0.686420, -0.640780, 0.873400, -1.011880, 0.214660, 0.438740, 0.542860, 0.610810,
-0.448390, 0.523130, -0.338000, -0.819470, -1.370650, -0.416650, 1.044690, 0.624360, -0.334530, -0.558840,

-10.265720, 0.291140, -0.082530, -0.101660, 0.521920, -0.225420, 0.545490, 0.877010, 1.442810, 2.328310,
-1.420510, 0.116520, 0.045170, -0.367360, -0.271740, -0.654440, 0.492810, 0.815000, -0.505240, 0.132950,
0.045500, 1.564410, -0.038660, 0.876910, -0.361660, 0.206110, 0.444070, 0.187070, -0.090050, -0.274570,
0.535520, 0.107540, -2.124540, -0.266620, 6.490210, -0.771710, -0.431920, 0.836930, -1.583870, 0.262220,
0.185540, -0.951280, -0.448000, 0.992820, 0.403510, 1.289810, -0.557440, 0.097350, 2.138180, -0.360570,
1.537000, -0.043400, -0.686880, -0.791070, 0.284620, -0.995380, 0.794890, -0.273490, 1.481410, -1.170950,

16.378050, -0.884930, 1.040560, -0.690100, 0.459800, 0.678990, -1.484740, -0.876710, -0.388430, -1.791010,
-2.064230, 0.497720, -0.477380, -0.459980, 1.407370, 0.456270, 0.585650, 0.387800, 1.380000, -0.134300,
-1.481660, -0.057080, 0.283850, -2.033610, 0.226740, -0.092750, -0.786060, -0.166710, 0.007840, -0.016170,
0.142820, 0.862980, -1.755070, -0.582100, 2.673080, -3.013830, 0.174780, 0.046460, -0.849550, 1.693120,
0.385720, -0.579650, 0.598630, 0.811130, -1.654400, -4.108510, 0.321730, 0.741140, -0.796910, -0.393760,
-0.295290, 0.275910, 0.525110, 1.169570, 0.067390, 0.790960, -0.695190, -0.095800, -1.866900, 2.052350,

2.099260, 0.395580, -0.559850, -0.560250, -0.208120, 0.219080, 1.224770, -1.947030, 0.679970, 1.339230,
-1.271580, -33.825230, -0.612580, 0.178980, -0.347370, -1.367500, -0.395670, 1.325750, 1.338360, -0.155730,
0.966040, -1.203680, 0.810990, 0.909800, 1.104510, -0.039170, 0.738580, -1.127900, 0.420780, 0.019910,
0.214960, -0.318100, -1.320590, -1.290130, 0.196620, 0.737390, -0.013500, -0.185790, 0.598910, -0.444500,
0.441600, -0.415830, -0.646940, -0.617280, -0.618330, 1.469720, -0.110910, 0.515970, 0.723910, 0.654730,
0.171420, -0.727330, -0.058260, 1.310880, -0.552000, -0.041600, 0.075740, 0.524390, 0.019920, 1.069450,

4.687440, -0.341250, -0.632550, -0.210650, 0.272890, 2.111260, -12.661240, 0.847850, 0.030280, -0.022170,
1.929430, 0.000720, 0.239050, -0.459340, -0.249530, 0.221430, 0.440370, -3.369150, 0.875570, 0.655430,
0.330040, -0.714170, 0.636860, -0.987440, 0.018820, -0.737270, -0.630180, 0.065760, 0.106470, 0.967660,
0.881370, -1.334820, -2.069450, -0.187250, -7.565060, -0.567040, 0.667970, 0.009350, 0.143780, -0.987200,
-1.017470, 0.476860, 0.026900, -0.118840, 1.088680, 2.845260, -0.824300, -0.718720, 1.737250, 0.509620,
0.787440, 1.960650, 0.278740, -0.905640, -1.643200, 0.525520, -0.189670, 0.686730, -0.406880, 0.044960,

-0.526350, -1.303460, 1.780930, 0.253800, -0.711520, 1.039740, -7.839530, -1.126840, -0.488980, -0.464310,
0.221620, -0.954460, -0.128300, 0.450020, 0.771570, 0.968710, 0.300670, 0.195730, 0.043980, -0.608220,
0.100620, -0.027740, -0.480840, -0.879820, -0.774850, -0.217580, -0.725980, -0.470870, -0.210140, -0.184500,
-0.215390, -0.342550, -0.891550, 0.485880, -0.340880, -0.033960, 0.277860, 0.336730, -0.517610, 0.365680,
0.353440, -1.068760, -0.286670, -0.730010, 0.979270, 0.244540, 0.316270, -0.175410, 0.491790, 1.518940,
0.222710, 0.731870, -1.125140, -0.380780, 0.233370, 0.629720, -0.713250, -0.155000, 0.377120, 0.529690,

10.316260, 0.363130, -0.900030, -0.603780, -0.015930, -1.047190, 0.734860, 0.024480, 0.848690, 0.785500,
-0.466420, 0.379280, 0.094890, 0.351290, -0.865620, 0.593860, -0.704140, 0.536060, 0.086370, -0.689880,
1.007670, -0.533830, 0.313280, -0.778670, 0.382780, 0.363240, -0.885750, 0.838220, 0.126380, -0.273440,
0.531960, 0.458130, -0.631060, -0.182880, 3.424600, -0.712110, -0.490380, 0.160660, 0.113490, 0.329170,
0.687280, 0.574370, 0.721930, 0.174430, 0.242710, -0.235280, -0.383550, 0.876760, 0.446140, 0.776570,
-0.230620, 0.268840, 0.311000, -0.417070, 0.477780, 0.164750, -0.563540, -1.239910, -0.566410, 0.100660,

-599.307495, 1.860800, -0.051930, -0.523970, -4.128920, -0.630590, -4.103570, -0.694310, 0.742030, 1.045680,
-0.349100, -1.004190, -1.997950, -0.029090, 1.660240, -0.605710, -0.699730, 0.583710, 0.355520, 0.243010,
-0.137870, -1.606630, 0.433560, 0.153940, 0.148130, 0.278950, -0.640400, 0.193360, -1.107800, -0.283640,
-0.047690, 0.630390, 1.540340, -0.822750, -7.937540, -0.138560, 1.131270, -0.791940, 1.117360, 1.105930,
-0.028710, -0.627330, -0.232490, 0.432790, 0.314670, 0.989600, -0.352720, 0.312210, -5.346730, -0.109210,
-6.116860, 0.210380, 0.923040, 4.819840, 0.782500, 0.683380, -0.325210, 0.845780, -1.763180, 1.164240,

10.829160, -1.889870, 0.384190, -0.506090, 1.173320, -1.420870, 5.276020, -0.233980, -1.045470, -10.700850,
0.421510, 0.022900, 0.661560, 0.027900, 0.228350, 0.066720, -0.454000, -2.378400, -2.007180, 1.108160,
0.098360, 1.365460, -0.726860, 0.585460, -0.233200, -0.938870, 0.290090, -0.800630, 1.189170, 0.408710,
0.457490, 0.831200, 1.022890, 0.383470, 3.135600, -0.774800, -0.659350, 0.233130, -0.699330, 0.370980,
0.277980, -0.180540, -0.470170, -0.097060, -0.608740, -0.493490, -0.107380, 0.326300, -0.878510, -2.216510,
-1.445090, 0.070760, 0.265980, -2.112600, 0.881220, -0.604180, 0.782030, -0.367710, 0.100320, 0.911950,

-0.352280, 1.772360, -0.852610, -0.563970, -1.302820, 0.415570, -1.322880, -0.458890, 2.263630, 2.191030,
-0.309890, 0.506770, -0.480190, -0.451320, -0.646650, -0.215860, -0.662190, 1.142920, 1.993300, 0.874910,
0.208940, -0.591870, 1.001170, -1.530940, 0.174500, 1.312580, 0.917940, 0.014140, -0.951000, -0.224130,
-0.024980, -0.325760, -2.136100, 0.456980, -6.322180, -0.970890, 0.460130, -1.301750, 0.963100, -0.233880,
0.108990, -0.727730, 0.360040, 0.602880, 0.115760, -0.247980, 0.264740, -0.849350, 0.020430, -0.508180,
-1.022230, -0.101320, -0.886150, 1.855400, -0.372890, 1.160230, -0.540460, 0.217700, 0.458160, 1.213450,

-0.883990, 1.126550, -0.589370, -0.950530, 0.000030, 1.358210, -1.720990, 0.891230, 2.489520, -0.064490,
2.126930, -1.265800, 0.606890, -0.065150, -1.165420, 0.206420, -0.483030, -3.769760, 0.865840, 1.115970,
-1.110580, 0.558910, -0.619890, -0.433880, 0.805490, -0.661450, 0.164430, 0.495980, -0.304630, 3.451460,
-0.558500, 0.268780, 1.170950, -0.295130, -2.914560, 0.456520, 0.264950, 0.447530, 0.185330, -0.472450,
-0.028270, 0.684750, 0.668440, -0.643040, 0.470290, 0.758170, -1.191740, -1.240650, 0.053110, -0.938280,
2.536980, 0.407030, 1.010860, 2.404880, -2.335560, 0.477790, -0.040740, -0.141280, 1.865330, 0.350250,

-7.667630, 0.369940, 0.195440, 0.700080, -0.546750, 39.258480, 1.395010, -1.132750, -1.057510, -1.995350,
3.917130, 4.329530, 0.909340, 0.480120, 0.864030, 0.478960, 0.190870, -0.284300, -4.899430, 0.659470,
0.123590, 2.825550, 0.177060, -1.033000, -1.594940, -0.286320, 0.243290, 0.355950, -0.290870, -2.650050,
0.583900, 2.404910, -0.718790, -0.153700, 0.509050, 0.020350, -0.928740, 3.141330, 0.148740, 1.422650,
0.343940, 0.505720, -0.398160, -0.563630, -0.011260, -2.907580, -0.149160, 0.246980, -4.034090, -0.080730,
-7.720550, -0.663380, -0.491980, -1.207850, -1.613460, 1.214110, -0.492050, 0.746190, 7.256600, -1.533020,

-13.684970, 3.574520, 2.916320, 0.845810, 0.735840, 3.304430, 1.765570, 0.397280, -4.953990, -8.373880,
6.778770, -3.616400, 3.731090, -1.072630, 2.843030, 0.481390, 1.906950, 369.131714, 4.408580, -1.743900,
0.149040, -4.874050, 0.075840, -1.505770, -6.383890, 0.923670, -0.384890, -5.236710, 0.702540, 0.229370,
0.198420, -3.132750, -2.703020, 2.357330, -13.216770, -0.456530, -0.177340, 0.677080, 5.389350, 1.074960,
1.001360, -1.173240, 0.570810, -0.266140, 1.554630, 10.319300, 1.652390, 0.800660, -3.646940, 18.849739,
-3.244420, 3.943810, 0.901740, -4.971770, 8.931850, -2.732000, -0.509890, 0.273780, -2.268210, -4.311640,

-1.459950, 0.884180, 0.048050, -0.220070, 0.386670, -0.515110, 0.137680, 0.855220, 0.416400, 1.972040,
-1.101350, -0.305860, -0.084920, 0.150610, -0.882430, 0.704550, -0.828460, -1.003090, -0.818350, -0.247710,
0.294580, -0.443460, 0.532550, -0.468000, 0.480420, 0.189690, 0.488160, -0.006090, -0.874600, -0.485000,
0.505830, 0.444560, 0.300430, -0.985660, 1.463720, -0.037760, 0.407510, 0.649400, -0.084410, 0.285230,
-0.611350, 0.026020, -0.368580, 0.273110, -0.390160, -1.360220, 0.081900, 0.880350, -0.349260, 0.422020,
-0.567440, 0.025540, -0.890340, -0.796720, 0.295860, -0.504910, -0.211920, -0.026200, 0.788110, 0.004750,

3.446530, -0.185160, -0.804050, -0.205210, 1.044680, 0.602840, 0.923080, -0.138080, 0.034060, -0.419840,
-1.261440, -0.666030, -1.587850, 0.455960, -0.001140, -0.416330, 1.122760, -0.058630, -0.751510, -0.757710,
0.070140, 0.469440, 0.575910, 0.838260, 6.939980, 0.493910, -1.187430, 0.616530, 1.156390, 0.553900,
-0.253600, 0.152070, 0.849790, -0.611770, 4.809240, -0.400420, 0.079140, 1.873450, 0.522080, 0.496020,
0.331250, -0.217580, 0.463360, 0.359490, -0.061430, -0.015870, 0.086520, 0.076490, 0.409220, -0.523300,
-2.367910, -0.363020, -0.288880, 2.212330, -0.160580, -2.190360, -0.066930, 0.387960, -0.761430, -0.357060,

0.022300, -1.360320, 0.770100, -0.908850, -0.043370, -0.905350, -5.934140, -0.916170, 0.048160, -0.333040,
-1.835930, -0.641370, -0.213800, 0.396740, -0.881190, -0.286500, 0.621760, 4.957690, 0.853430, -0.937620,
-0.463090, -1.893810, 0.819680, 1.264530, 1.219390, 0.725820, 0.704200, 0.894240, -0.156380, 0.024660,
0.841250, 0.061130, -1.843750, -0.049020, -2.297080, -0.067280, 0.151380, -1.051010, 0.282500, 0.002610,
-0.041250, -0.954160, 0.533080, 0.509990, 0.684250, 1.144360, -0.157330, -0.549510, -0.781010, 1.846000,
1.331210, 0.456660, 0.159320, -0.325820, -0.234040, -0.130960, -0.711280, -0.121880, -0.371530, 0.688560,

0.584500, -0.392500, -0.666530, 0.130780, 0.370390, 1.053410, -23.559080, -0.426840, 0.253680, 2.031090,
-1.941950, -2.230170, -0.385380, -0.074760, 0.146510, -0.039710, 0.813100, -2.058650, 1.795750, -0.010220,
-0.056660, -2.913900, 0.402800, 0.300640, 0.393740, -0.056680, -0.609710, -0.033230, -0.122960, -0.144540,
0.011990, -0.091720, 2.390740, 0.165810, -2.671290, 0.812820, 0.035480, 0.648430, -1.017630, 0.541730,
-0.801010, -0.525390, -0.791840, -0.451260, -0.598270, 1.147420, -0.048000, -0.717470, 0.534950, -0.841630,
-2.551200, -0.039890, 0.562520, -0.773930, -0.412370, -0.965720, 0.065310, 0.624890, 0.197000, -0.125330,

9.503330, -0.026540, -1.266760, -1.244780, -0.535660, -0.301640, -1.450610, -0.878850, 0.177390, 1.263900,
-0.594170, 0.941360, -0.345790, 0.581960, -0.572430, 0.425000, 0.847070, -0.905910, -0.333970, 0.949030,
-0.542270, 0.038670, 1.282090, 2.445090, 7.286470, 0.245460, -0.837800, -0.106050, -0.570790, 1.255980,
0.842770, -0.516070, 1.833140, 2.418210, -10.049470, 0.312150, 0.215950, 0.570720, 0.917640, -1.773030,
-0.101410, -0.639500, 1.008770, -0.051980, -0.106390, 1.824790, -0.020380, 0.426630, 3.094620, -0.835500,
-0.819890, 2.379030, 0.999170, 0.053140, -0.230060, -0.430360, -0.027860, 0.817310, -1.542800, -1.226680,

4551.361816, -0.846990, -0.125600, 0.881420, -0.900690, -1.709120, -2.711640, 2.008230, 6.177830, 4.208940,
-3.056270, -2.012740, 1.339170, 3.331660, -1.551730, 1.815320, -1.629640, -1.030920, 1.931950, 0.005470,
0.105730, -1.622830, 0.397100, -0.165580, 20.495110, -0.899770, 0.279340, -0.271740, -3.067780, 2.438460,
-1.197480, -1.552740, 0.311320, 0.165550, 3.231170, -0.959710, -2.190030, 2.009760, 1.873090, 0.306110,
-0.911230, 0.445770, -0.292050, -0.411030, 0.920760, 0.160650, -0.384020, 0.612970, 4.156460, 0.021850,
4.005470, 3.008070, 0.825260, 0.339260, -0.378320, 0.796430, 1.032610, 0.178800, 0.706990, -2.291280,

-3.511180, 0.578490, -1.141690, 0.370390, 0.898460, -1.313770, -0.568660, -0.996780, -0.676640, 0.052650,
0.711190, 1.317970, 1.094930, -0.124000, -0.168250, -0.548340, 0.791180, -0.971020, 1.217540, -0.222540,
0.287710, -1.314540, 0.163410, -1.042010, 0.889100, -0.854180, -1.062580, -0.278380, 1.053770, -0.475390,
-0.046130, -0.279310, -0.085620, 0.474350, 0.840270, -0.421610, -0.983900, 0.846980, 0.898100, 0.512110,
-0.857190, 0.359040, 0.161810, -0.017290, 1.046680, -1.641820, 0.279410, -0.811380, 0.130080, -0.788000,
-0.336880, -0.248130, -0.906500, -2.395650, -0.818560, 0.151100, -0.124790, 0.752040, 0.922640, -0.844060,

-169.017578, 0.015960, -0.429950, -0.863860, -0.955020, 1.312510, 1.762940, 0.436660, -0.123250, -0.451420,
-1.606480, 1.696570, -0.782980, -0.647320, -0.146900, -0.542880, 0.206660, 0.334610, 0.581720, -0.006480,
-0.173870, -0.149420, 0.595330, 0.299840, 0.996330, -0.536480, 0.066820, 0.884470, 0.310780, 0.428950,
-0.838210, -0.089490, 0.306610, -0.439540, -4.259710, -0.716180, -0.189520, -0.367350, 0.254960, -0.464390,
-0.311110, -0.540670, 0.503030, -0.358710, -0.943860, -0.370690, 0.644000, -0.002260, -1.364580, 0.807000,
4.450590, -1.372150, 0.632680, 2.783090, -2.376980, -0.357980, -0.376720, 0.358570, -4.840130, 0.156330,

-14058.770508, -2.055670, 0.670380, -0.154840, 0.153070, 0.935630, -5.272710, -2.089540, -2.236480, 4.300830,
1.457410, 5.270020, -2.011360, -2.371580, -0.514370, -0.311100, 0.101550, 1.040920, -2.760580, -1.980520,
-1.648740, 0.003240, -1.196540, 3.601770, -6.350560, -0.295730, 0.910140, -0.472270, 0.494970, 1.308320,
0.408330, 0.365850, 0.936170, -0.339860, -2.745820, 1.789340, 1.534380, 1.962210, -0.334870, 0.118170,
-0.212700, 0.637410, -1.039700, -0.394400, 0.772260, 0.047100, -0.248680, -0.945040, -1.429170, -1.259680,
-0.218890, 0.983970, -0.270800, 0.052120, -1.372010, -1.318090, -0.226910, 0.453410, -0.926450, 0.133550,

10.133730, -0.638370, 1.091120, -0.610490, 0.438780, 0.110840, -380.084656, 0.955650, 0.031660, -2.128240,
-8.935040, 0.553400, 0.057170, 0.813070, -1.251520, -0.796990, -0.485680, 17.466610, -15.544880, -0.362860,
1.435330, -6.482560, -0.536940, 0.932220, -0.884750, 0.389360, -0.025980, -0.119470, -0.726860, -9.645780,
-0.303760, -0.673860, -0.528420, -2.982600, 6.454690, 0.159920, -1.163350, -0.401610, 0.219030, -0.517230,
0.585660, -0.646650, -0.693890, -0.091160, -0.379120, 5.555410, -0.696850, -0.598020, 2.432050, 1.559960,
2.585090, -0.296720, 0.812300, 0.405210, 0.852850, 0.854910, -0.039020, -0.947380, -1.396120, -1.667630,

-3.661810, 0.806280, 0.944400, -0.164070, 0.211640, -1.065580, 0.552800, 0.473690, 2.052830, 1.660710,
-1.000700, -1.761090, 0.220970, -0.015600, -0.786860, 0.772370, 0.188160, 0.184390, -0.219960, 0.058670,
0.730420, 1.519750, 1.827100, -0.296140, -0.571930, 0.810180, -0.269400, 0.874890, -0.922150, -0.893100,
0.258590, 0.259380, -1.971510, -0.377070, 2.505100, -1.547790, 1.162390, 0.110990, -1.270410, -0.607010,
0.647630, 0.367890, -0.216930, 0.139670, -1.112280, -0.825800, -0.662950, 0.930740, 0.305540, -0.635250,
-0.021470, 0.350020, -1.037520, 3.992630, 2.754180, 2.036840, 0.406600, 0.303940, 1.974700, 0.418260,

-460.000366, 1.326090, 0.771510, 0.218180, -0.956310, 0.752600, 1.920850, -0.947260, 2.348710, 1.608130,
-0.192200, -0.266370, -0.920740, -2.182230, -0.086210, -0.903320, -0.633330, -1.043470, 1.775480, -0.470480,
0.134460, -0.154060, 0.707170, -1.574800, -14.150480, 0.550330, 0.496490, -1.049030, 0.394310, -1.359260,
-0.065550, 0.653830, -0.125610, 1.781880, -1.816720, -1.155710, 0.190400, 0.420000, -0.362990, -0.581970,
0.704050, -0.208910, 0.498950, 0.208610, 0.677890, -1.807050, 0.127900, -0.975180, -2.152350, 1.017920,
0.511820, 0.029140, -0.572730, 1.446180, -0.624780, 1.384500, -0.186280, -0.171410, 0.751440, 1.810440,

-4.189860, -1.935570, 0.024300, -0.992020, 0.732260, 0.232790, 0.095870, 0.163730, -19.296749, -1.437510,
2.091550, 1.635300, -0.143810, -0.702340, 0.155750, -1.747280, 0.061380, 0.088120, -0.113090, -1.229730,
-0.632840, 2.180740, -2.033670, 2.632910, -3.055780, -1.702750, 0.057450, -0.135400, 2.904600, 0.240060,
0.025890, -0.316000, 0.287710, -0.503040, -2.820230, 0.867660, -0.820150, -0.191210, -0.133730, -0.137560,
-0.129060, -0.227280, -1.040640, 0.594820, 0.580390, -0.916970, -0.211460, 0.853480, -1.020650, 0.677570,
0.085770, 0.124120, 0.690090, 1.045870, 1.552730, 0.797870, 0.343960, 0.012830, -0.419050, -1.104930,

-1.656050, 0.601080, -0.222980, 0.205190, 0.471750, 0.219110, -0.095270, -1.295210, 0.271340, 0.124000,
0.369500, 1.673960, 0.596040, -0.575280, -0.103530, -0.034230, -1.118740, 0.064720, 1.158940, -0.227270,
-0.049500, 0.071580, 0.181620, -1.343780, -1.834600, 0.780650, 0.320710, 0.590510, 0.525270, 0.246380,
-0.943840, -0.264490, 1.022460, -0.392330, 1.391540, -0.907870, -0.753010, -0.491040, -0.091820, 0.749970,
0.625920, 0.761490, 0.014020, -0.632880, 0.918320, 1.879170, 0.326440, -0.213320, 1.380570, -0.503240,
-1.096310, -0.242960, 0.589370, -0.500590, -1.128690, -1.384840, 0.180780, -0.442420, -0.817690, 0.008010,

-4.752390, 0.646730, -0.239530, 0.643070, -0.373380, -0.788710, -0.414220, 0.709160, 0.698090, 0.440600,
2.969950, 0.080460, -0.344740, 0.175910, 0.729860, -0.262960, 0.352550, 1.292520, -0.611640, 0.350220,
0.098390, -1.077260, 0.587980, -0.436960, -0.089020, -0.270430, -0.718450, -0.158110, -0.419240, -1.151360,
0.317680, 1.709950, 4.150580, -0.760350, 2.808880, 0.344460, 0.439520, 0.525920, -1.332450, 0.923700,
0.874220, -0.373640, -0.162130, -0.662450, -0.756500, 0.369350, 0.676890, -0.170280, 0.358100, -0.130120,
-3.958040, -2.511550, -0.319900, 1.761990, 0.665690, -1.449540, -0.522580, -0.788380, 0.496480, 0.853980,

-6.703620, 0.094540, 0.851060, 0.234300, 0.380180, 1.366580, 1.139300, -1.045340, 2.252400, 0.819310,
-1.117720, -0.328050, -0.476680, -0.266840, -0.659520, 0.038120, 0.438510, 129.112656, 0.674120, -0.708000,
0.793530, -1.469220, 2.185920, 0.493610, -1.194960, 0.508290, -0.088220, 0.837050, -1.283080, -0.002740,
-0.474520, -0.264510, -4.724960, 0.141120, 0.474630, -0.383660, 1.379610, -1.241390, 1.921020, -1.593390,
-0.839230, -0.479590, 0.074970, 0.570420, 1.067510, 2.498550, -0.362510, 0.555050, -0.087530, 4.212860,
6.378230, -0.794370, -0.523710, 3.943230, -0.527500, 0.221090, 0.467650, 0.299720, -0.011750, -0.769240,

4.869290, -0.651980, 0.089670, -0.965410, 0.990190, -0.446660, 0.724660, 1.179860, -2.993640, -6.417710,
1.513000, -0.243630, 0.091010, -0.677260, -0.258640, 0.321290, -1.091210, 0.188110, -1.595700, -0.199360,
-1.331690, 2.702740, -1.002310, -0.770940, 0.789040, -0.366340, 0.376890, -0.485480, 1.399850, 1.520700,
-0.532020, -0.234400, 0.412410, -0.977600, 5.261950, 0.191030, -0.739440, 0.750320, -1.277640, -0.028500,
-0.467930, -0.609080, 0.034600, -0.052740, -0.053050, 1.154220, -0.584180, 0.522590, 0.385220, -2.155300,
-2.143320, -1.527190, -0.010350, 0.148320, 0.276950, -0.069450, 0.745070, -0.710000, 1.039200, 0.425710,

-63.976452, 0.414100, -0.412760, -0.551310, -0.823450, -0.225420, 1.935070, 0.691510, -1.809260, 0.303180,
-0.507190, 1.261790, 0.700850, -0.315590, -0.844850, -1.427390, -0.757880, 1.924180, -0.017480, 0.402160,
-1.006710, 0.886470, -0.027690, 1.226560, -1.255250, -0.770420, 0.458180, -0.196460, -0.358790, 0.832240,
0.950800, 0.341780, -0.652790, -0.892040, 4.165040, 0.599370, 0.523960, 0.194260, 0.420000, 0.267200,
0.469130, -0.716610, -0.753260, -0.806970, -0.245210, -0.567000, 0.241190, 0.369890, 1.046560, 0.369390,
-0.150850, 0.161340, 0.072550, -0.246180, 0.195850, -0.872460, -0.501750, 0.379130, -0.084780, -0.338960,

0.503910, 0.777390, 1.187410, -1.073970, -2.658030, 0.624110, -1.155420, 0.756840, -0.972840, 0.651240,
0.538530, -0.661360, 0.381350, 0.052640, -0.912480, 0.824300, -0.306590, -0.514070, -0.313640, -1.799440,
-1.569310, -0.436800, -0.603420, -2.695840, 0.752150, -0.361970, 0.659280, -0.454730, 1.031660, 0.690700,

-1.378250, 0.089340, 1.671680, -1.337370, 0.431640, -0.917320, 0.699120, -0.368940, 0.528880, 0.390490,
-0.396560, -0.311540, 0.515210, 0.758840, 0.251230, -1.097310, -0.779270, -0.239640, -2.511060, 0.307320,
-0.893080, -0.609690, -0.776780, 1.184470, -0.357250, 0.583070, 0.833610, 0.710130, -4.420610, 0.706870,

0.637540, -0.625980, -1.900420, 1.026670, 1.115010, 0.374160, -0.871930, -0.694770, 0.407520, -0.709640,
0.054800, 0.627780, -1.035180, -1.075600, 0.341010, -0.353800, 0.405630, -0.307770, 0.396750, -0.081200,
1.061220, 0.472090, -0.108840, -0.673490, -0.668440, -0.180670, -1.076640, 0.635180, -1.009680, -0.978440,

0.314500, 0.934000, 1.886430, -0.678540, 3.400250, -0.499090, -0.982890, 1.048940, -1.389110, 0.702310,
0.098460, -0.291250, 0.520840, 0.185880, -1.092180, -1.058100, -0.617690, 0.149830, -0.248230, -2.417020,
-2.729810, -1.043760, -0.207250, -2.316660, 1.272790, -0.769280, 0.282600, -0.443160, 0.857280, 0.817980,

-0.903500, 0.615010, 1.346940, -0.833750, -2.737740, 0.614820, 0.637030, -0.883660, 0.590360, 0.464640,
0.181910, -0.051760, -0.836430, -0.801350, -0.414590, -1.076620, 0.692070, -0.675650, -2.541240, 0.229360,
-1.383810, -0.900000, -0.159280, 2.111780, -0.907170, -0.351430, 0.116640, 0.751150, -3.440850, 0.974390,

0.245070, -0.881310, -1.812100, 0.942710, -2.554900, -0.167900, -0.467610, -0.890500, -0.092570, -0.749900,
-0.275120, 0.069910, 0.362090, 0.191610, 0.868440, 1.271940, 0.592130, -0.292580, 0.494310, -0.067500,
1.801150, 0.873770, -0.714860, -1.805600, -0.808800, 0.985850, -0.131530, 0.848550, -0.662310, -1.103430,

0.339960, 0.763100, 0.241780, -0.372530, 3.344060, -1.106800, -0.261580, 0.751630, -1.985430, 0.405760,
0.259550, 0.169660, -0.618530, 0.520350, -0.804560, -3.289400, -0.748280, 0.930820, -0.834850, -1.547340,
-0.182420, -0.312690, -0.838460, -2.004080, 1.703590, -0.239750, 0.228250, -0.661670, 1.169760, 1.209540,

-0.249170, 0.530870, -0.175860, 0.201870, -2.782270, -0.095560, 0.512510, -1.010620, 0.766420, 0.183040,
0.865320, -0.880190, -0.023030, -0.695600, -0.614590, -2.410650, 0.253200, -0.945910, -1.650260, 0.545680,
-0.105510, -0.472400, 0.942710, 2.187640, -1.854580, 1.095600, -0.233610, 0.007670, -3.984470, 1.073320,

-0.345600, -0.867540, 0.047470, 0.233130, -2.618290, 0.859670, -0.285090, -0.886010, -0.167550, -0.474900,
-0.910970, -0.282120, -0.470250, 0.561880, 0.870500, 2.953930, -0.021810, 0.027110, 1.101440, -0.262560,
0.248450, 0.317160, 0.605730, -2.011780, -1.898920, -0.395340, 0.147000, 0.347180, -1.100990, -1.370060,

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
      0.0, -0.343370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.892850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.441130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.167680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.418430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.584160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.459090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.768220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.899640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.897680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.908650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.825000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.168620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.888540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.369560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.095550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.800060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.046990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.735840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.205600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.235660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.525990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.885390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.821910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.248630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.529840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.758340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.636360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.054220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.601380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.996010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.529750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.398720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.836110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.393470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.439200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.793480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.638270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.586020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.926870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.641580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.877120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.602970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.152110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.183370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.156910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.538070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.750070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.194940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.294230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.286140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.130240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.300670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.366790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.332010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.768960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.479050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.601070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.821920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.691360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.043660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.537870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.289920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.742050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.416010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.287660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.784280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.035310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.351900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.756580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.245350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.660250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.223240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.357760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.759830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.013190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.047770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.290510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.857690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.679100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.272210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.620990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.984090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.636990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, -0.534400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.064640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.683150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.647480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.482070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.640670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.330830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.775110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.799810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.453460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.825750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.615970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.265550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.206780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.778850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.660400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.096780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.715470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.926820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.434360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.070590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, -0.273940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.606700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.549620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.853570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.454610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (hid11) */
      0.0, -0.252740, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.653520, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, 1.038380, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 418.194336, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.871710, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.393500, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.840960, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, 0.503300, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.808660, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.777480, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, -0.557060, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.092170, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.209790, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.397680, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.061720, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, -0.019570, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.244930, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, -0.044280, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.303210, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 0.593860, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.486600, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, -0.305490, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.379380, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, -0.712930, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.691750, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, 0.281290, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.079010, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, -0.760030, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.233580, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -1.027990, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.266930, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.571020, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, -0.047520, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.640190, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.436900, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.145370, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.878250, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.466640, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.453980, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, -0.923590, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.772350, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.291990, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, 0.990060, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.873440, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.019270, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, 0.218810, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, 0.357420, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, 0.998510, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.285010, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.478450, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.273010, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 0.892250, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -0.570610, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, 0.228470, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.505710, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.945690, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.173890, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, -0.024370, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.647120, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.703570, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.031970, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.066030, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, 0.914050, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.282680, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, -0.498860, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.433120, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.824040, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.786120, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.054790, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.09413, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
1.02911, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.11211, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
1.42857, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
1.42843, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.18839, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.00002, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.20023, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.00001, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
0.40529, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.00000, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.36241, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
1.20329, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.42536, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
0.51141, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.13997, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.52541, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.00000, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.03677, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
0.35647, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
0.19587, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
0.04661, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
1.32251, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.10562, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
0.66227, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.40846, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.39143, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
0.06256, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.00377, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.10624, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
1.31039, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.32301, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.00788, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.04236, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.01088, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
1.40532, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.00004, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.42403, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.03967, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.69708, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
1.42834, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
1.39069, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
1.37356, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.41315, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.05089, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
0.34993, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
1.42471, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
1.42849, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
0.58804, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.00002, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
0.00038, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.12008, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.40673, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
0.00005, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.04570, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.11177, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.35827, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
0.08901, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.33590, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.21604, 0.500000, 2,
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
