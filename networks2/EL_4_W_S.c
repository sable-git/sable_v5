/*********************************************************
  EL_4+W.c
  --------------------------------------------------------
  generated at Sat Aug 14 18:11:18 2004
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
-1.197840, 1.155040, -1.476470, -0.528980, -2.029820, 0.262630, 1.378920, -1.009720, 0.127300, -0.909300,
-1.866190, -1.699850, 0.447240, 0.082390, -0.716810, -0.268900, 1.691030, 0.933270, 0.788780, -0.583710,
-0.304680, -0.669040, -0.859200, -0.312390, 0.645000, 0.138860, 0.408370, -0.299830, -1.307460, -0.516980,
0.352860, -0.605430, 0.558110, -0.487160, 1.035650, -1.000180, -0.290930, 0.336290, 0.496520, 0.543450,
-0.454990, -1.230090, -1.299730, 0.209900, -0.921210, 0.348990, -1.159350, -0.247750, -0.316310, -0.984380,
-0.845170, 0.034740, 2.607720, 0.443930, 0.282410, -0.678060, -0.414560, 0.760580, -1.265410, -0.873870,
0.247260, 0.723630, -0.182790, -0.971190, -0.703250, 0.126460, 1.157130, -1.182250, 0.777760, 1.068430,
3.966880, -0.156480, -0.784520, -2.191130, 0.096820, -0.366900, -1.801630, 0.722960, -0.588570, -0.324290,
0.061650, 0.505000, -2.113420, -0.665320, 0.289060, 0.590190, -0.257240, -0.652510, -0.238680, -0.231320,
-0.148840, 0.338050, -0.589410, -0.516020, -0.147830, 0.578500, 0.149270, -0.201130, 0.473990, 1.897820,
3.312460, -5.288060, -3.495980, 3.596450, -5.053390, 7.681470, -1.097900, -1.460310, 0.119130, -0.059760,
-0.194350, 0.872000, 0.020780, 0.109510, 0.512840, 1.519690, 0.140090, -0.156660, -8.770360, 0.805020,
1.196790, -0.144660, 1.989100, 0.809540, 0.830020, -0.520980, -0.280160, -0.188870, 0.252590, 0.222050,
-2.027020, -0.396500, 0.812350, 1.328310, 0.108690, -0.905290, -0.041030, 0.717320, -0.427980, 0.378950,

-0.618360, 0.410580, -0.105210, 0.644710, 1.143810, -0.118730, -0.462180, -1.711010, -0.431470, 0.390230,
0.220500, 0.780490, 0.695130, -1.465770, -0.632170, -0.319920, -0.645860, 0.388470, -0.250280, -0.688910,
-0.789080, -0.374320, -0.786160, 0.762350, -0.374960, 2.894250, -0.742990, -0.525120, 0.691620, -0.152630,
1.539980, 1.014330, 0.625050, 1.053650, 0.635600, 0.715500, -0.504590, -0.811390, 0.183380, 0.149360,
-1.895090, 0.236890, -0.804230, 0.602160, -1.167790, -0.348700, -1.134400, -0.071010, 1.262180, 0.745060,
-0.421130, 0.233360, -0.468940, 1.601270, -1.499860, -0.865550, -1.422470, 0.407580, -0.412230, 0.055320,
-0.217890, 1.459320, 1.177320, -1.572800, 0.601790, -0.710930, 0.248090, -0.572430, -0.112420, 2.291100,
0.507820, -0.358270, -1.110510, 0.093250, -0.086950, 0.063210, 0.111590, -0.241530, 2.996940, -0.347230,
1.246790, -0.734460, 0.209930, 0.421520, 0.527800, -0.444750, 1.029610, 0.905830, -0.994960, 0.781680,
-1.014400, 0.517640, -1.364810, -0.704480, 1.000250, 0.327990, -0.258730, -0.013010, 1.154860, -2.466500,
1.707900, 4.371250, -1.058630, -11.225020, 9.098840, -15.271830, 12.117740, -5.946640, -0.179590, -0.014340,
-0.290250, -0.398850, 0.142290, 0.170900, 0.257100, -0.720740, 0.261120, -0.443680, 1.136980, -0.437590,
1.256910, -0.014990, -0.416000, -0.171140, 0.508900, -0.537640, -0.704620, 2.021460, 1.971990, 0.052920,
1.602350, -0.857170, -0.981000, -0.420700, -0.196080, 0.277100, 0.074100, -0.111590, 0.220780, 0.158950,

0.572350, -0.567710, -0.486450, -0.540180, 0.368270, -0.835140, -1.067830, -0.710510, -1.997060, 0.321720,
-1.788630, -0.596870, -0.764890, -0.798670, -0.305830, 0.396270, 2.231810, 0.483620, -0.906960, -1.011380,
-0.246400, -0.245950, -0.638360, -0.210290, 0.146220, -0.267600, -0.251010, 1.151040, 0.165080, 0.445410,
0.474700, -0.364760, 1.166700, 0.487500, 2.973060, 1.435380, -0.832090, -0.430860, -1.013360, -0.451600,
0.621080, -0.050910, -0.871310, 1.346280, 0.538680, -3.857220, -0.308170, 1.027070, 0.125120, 1.321290,
0.219580, 0.452740, -0.521580, -1.867240, 0.335590, -0.539100, 3.781160, -0.394610, 1.364330, -0.825890,
-1.163620, -0.999570, -1.101450, 0.628510, 0.145240, -2.275750, -1.328090, 0.780950, -0.421870, 0.422360,
-1.253120, 0.257750, 0.341730, 0.592340, -0.602520, 1.082540, 0.352360, 0.496690, -0.182550, 0.075600,
-0.408320, 0.514950, -0.370790, 0.178270, 0.610170, -1.566010, -0.316530, 0.684820, 3.588450, 1.366820,
-0.014600, -0.421870, 0.440490, 0.602970, -0.152980, 1.913270, -0.307000, 2.022170, 0.421800, -0.135750,
3.920160, 3.465440, 2.106450, -2.551640, -3.470780, -2.835940, 0.104150, -2.555020, 1.418860, 0.139720,
0.280520, 0.638250, -0.784970, 0.247190, -0.518570, 0.423180, 0.259500, -0.428750, 0.480620, 0.096240,
1.307850, -0.910500, 3.705200, -0.282440, 0.145340, 0.406680, 0.363220, -1.378160, 1.387050, 0.953130,
-1.094160, -0.611600, -0.347760, 0.374300, 0.364700, 0.056250, -0.095010, -0.045180, 1.369070, 0.503430,

174.685516, 173.626144, 174.907639, 173.919250, 174.165955, 174.559753, 174.149170, 173.313324, 175.145721, 174.893768,
173.342880, 174.680527, 174.430161, 174.478027, 174.672989, 174.079605, 175.080536, 174.279510, 174.319931, 175.023560,
174.459335, 175.087341, 173.586777, 174.620026, 174.680893, 174.074829, 174.735413, 174.277405, 175.036591, 174.185791,
174.404541, 173.679489, 174.032013, 174.267731, 174.967056, 174.687485, 173.892303, 173.293427, 173.853287, 175.028015,
173.481216, 174.152847, 174.182663, 174.410522, 502.390808, 174.623856, 174.016098, 174.120331, 174.411407, 174.955353,
501.625092, 174.429321, 173.785538, 501.994324, 174.099869, 174.329056, 501.366394, 175.162003, 173.575333, 500.622681,
174.285919, 174.285492, 501.447723, 173.264771, 173.876648, 501.642517, 175.007278, 174.496872, 501.478912, 174.419983,
174.639923, 175.063828, 173.590652, 174.799988, 501.327942, 173.959793, 173.841583, 174.727997, 175.118011, 173.809784,
173.863342, 173.257660, 174.368729, 173.432068, 173.763702, 173.255737, 174.136536, 174.497665, 175.040314, 173.393188,
173.550385, 174.791702, 173.377594, 174.343246, 173.265289, 175.107544, 174.593826, 173.621964, 174.606888, 174.436020,
174.240997, 174.907425, 174.408127, 174.473557, 173.279434, 501.310028, 502.369324, 173.373993, 174.161987, 173.748184,
173.645477, 173.671356, 175.003769, 174.838165, 173.568039, 175.149445, 174.500122, 175.171600, 501.858246, 173.631729,
59.692280, 173.426376, 501.325684, 174.896393, 174.830322, 173.348419, 173.421494, 501.905762, 173.985016, 173.611435,
174.172638, 502.265076, 173.270432, 173.392441, 500.962982, 173.990692, 175.117981, 175.052429, 173.966873, 173.654739,

0.633190, 0.636800, -0.616810, 0.622320, 0.736090, -0.137900, -0.491600, 0.481230, -0.487550, 0.473690,
-1.469720, -0.029150, 0.399610, 0.361810, 0.409510, -0.794890, -0.272540, 0.921690, -0.554150, -1.479680,
-0.954080, 0.168320, -1.517870, -0.431970, -0.898300, -3.772960, 0.370370, -0.680650, 2.001750, -0.125440,
0.821830, -2.140020, -0.608090, 0.247640, -4.099380, -1.041160, 0.576580, 4.540380, 0.401980, -1.760680,
-4.846220, -0.175450, 0.009170, -9.531790, -0.623670, -0.164540, 1.601240, -0.743630, -0.136600, -2.586870,
-1.054380, -0.389560, -2.512670, 0.249740, 1.444140, -0.553270, 0.084170, -0.910030, -1.825030, 0.257710,
0.550660, 3.746020, -0.518380, 0.763010, -0.134580, 2.956580, 0.359310, 0.032520, 0.415610, 0.386020,
-0.355330, -0.849880, 1.843240, -0.772590, 1.256110, 0.315650, 1.966580, 1.630850, 0.361720, 0.408460,
-1.045050, -0.367690, -0.640920, 0.461900, 0.394370, 0.422990, -0.193410, -0.392610, -0.758190, -0.620980,
0.884830, -1.569820, -0.082540, -0.909610, 0.715270, 0.355570, -1.586990, -0.707400, -0.766870, -0.836180,
0.110510, -1.483680, -0.057060, 1.679430, 3.364380, 2.308780, 1.922660, -2.441170, 1.361540, -0.616970,
-0.855010, 0.177250, 1.009680, 0.723550, 0.475600, 0.981460, 0.062870, -0.269630, -0.336190, 0.507750,
1.607710, -0.207930, 4.608870, -0.368260, -0.431930, -0.617370, -0.861200, -2.070830, 0.687480, 0.277750,
0.543080, -1.055980, 0.193550, -0.575380, -0.461300, 1.036260, 0.364030, -0.535390, -0.814420, 0.474330,

-0.771370, -1.968760, 0.405370, 0.670680, 1.486770, -0.232330, -0.324830, 0.270790, 0.421370, -0.650450,
0.063850, -1.519760, 0.475600, -1.015990, 0.487650, -0.131340, -0.499260, 0.837450, -0.441000, -0.558160,
-1.573810, 0.328670, -0.354320, -0.012790, -0.514800, 0.026660, -0.625410, 0.129780, 0.238550, 0.435970,
-0.730590, -0.525540, -0.450160, 0.247880, 1.161150, -0.011530, 0.259770, 0.839030, -1.498830, 0.571670,
-1.079270, -0.134630, -0.485050, 1.199500, 0.048460, -0.067020, -0.601820, -1.121760, 0.088110, -0.161650,
1.992980, 0.226220, 0.038700, -2.217590, -0.503940, -2.147200, 2.139620, 1.057700, 0.965810, 0.819610,
0.932270, 1.160570, -2.954360, 0.243850, 1.547510, -2.633800, -0.916410, -0.144260, -0.590760, 0.011920,
1.365620, -0.478380, -0.751330, -0.322650, -2.045310, 0.019710, -0.427800, -0.731380, 0.857550, 0.774690,
2.347230, 0.252440, -0.269170, -1.635690, 0.237360, 1.534520, -0.827580, -0.651440, -1.567990, 0.959680,
0.011530, 0.033290, 0.486820, -0.995220, -0.500110, -0.497280, 0.437190, -0.468670, 0.354980, -0.188320,
-0.540820, -1.004740, 2.965700, -0.398170, 0.851520, -6.372790, 1.895850, 3.276920, -4.122150, -0.796510,
-1.325790, -0.002460, 0.214760, 0.338990, 1.314560, 0.356220, -0.444960, -0.270050, 1.520260, 0.116060,
0.338750, -0.118380, 0.771710, 0.495870, 0.476960, 0.613790, -0.380240, -0.182230, 0.579560, -0.348060,
-0.714200, 0.186020, 0.269460, -0.273600, 0.884540, -0.685760, -0.179180, -0.466170, -0.028930, 0.221520,

0.318600, 0.950150, -0.100310, 1.026880, -0.764550, 0.312960, 0.255870, 0.263590, 0.430580, -0.599380,
1.608710, 1.445590, 1.732100, -0.196460, -1.577470, -0.321250, -0.203670, 0.701800, -0.450800, -0.309420,
1.300200, -0.594910, -0.076170, -0.524800, 0.263790, -1.050790, 0.736990, -3.319970, 0.267230, 0.610320,
0.436480, -0.514260, -1.124550, -1.032920, -1.093790, -2.739020, 0.895460, -1.093520, 0.079540, -1.868340,
0.619270, 0.022630, 2.132820, 0.846210, -2.524550, -0.520340, -1.082690, 0.160890, 1.471810, 0.086410,
-0.518440, -1.051500, 0.098930, 0.028730, 6.962860, -0.867070, -4.930890, -0.747850, 0.201280, 0.563700,
-3.928710, 0.151310, -0.673950, 2.399810, 0.259260, -0.599920, 0.367360, -0.388620, -0.763840, -2.718900,
2.099830, 0.159750, 4.611910, 0.248220, 1.243890, 1.769840, 0.632730, 0.100780, -1.201880, 1.181360,
0.454270, 1.485100, -1.192990, 1.878580, -0.351710, 0.511150, 0.268950, 0.027900, 0.015170, -1.352480,
-2.318140, -0.098420, 0.424420, 0.519690, -0.418670, -0.463860, 0.310500, 2.523550, -0.809930, 1.470580,
1.188270, 2.667320, 0.552630, -2.535200, 2.239640, -4.911180, 3.448000, -0.318560, 4.751800, 0.282680,
-2.971240, 2.231110, 0.447770, 0.295130, -1.127190, 1.593190, -0.088000, -0.579850, -0.605420, 0.081100,
-3.000730, 0.153220, -0.028930, 0.093110, -1.638020, -0.517390, -0.007100, -1.524540, -0.414800, -1.165100,
-0.665460, 0.951110, -0.157630, 1.283270, -0.031640, -0.531170, -0.053050, 0.373820, -2.516310, 0.164250,

0.462240, 22.889280, -5.302970, 0.927210, 3.133260, -0.527620, -0.147960, 7.914290, -1.571090, 0.077980,
1.276670, -6.637480, 1.191990, 17.629919, 0.388560, 0.692410, 24.435699, -10.807110, 0.686500, -46.283180,
2.177240, -1.352040, -2.795230, 10.806100, -0.886740, 6.214800, -0.251210, -0.639720, 8.058220, 17.071329,
-0.912650, 13.498570, 0.111910, -1.057150, -22.447330, 1.964080, 0.195790, 13.084510, 8.759980, -1.221460,
11.548120, -3.125580, -0.691110, -10.555670, -2.678300, -0.851310, 0.181360, -3.989730, -0.580570, 2.453870,
-1.138130, -0.016100, -12.010690, -0.297780, -1.253120, -15.747550, 3.494660, -2.138900, 19.440371, 0.197920,
4.163910, 9.485440, -1.435870, -1.610910, -1.552490, 9.158630, -1.219510, -3.448770, -0.478600, 3.117930,
7.785180, 0.998680, -1.896450, -0.711130, 0.108020, 1.568100, 4.859200, -0.142930, -3.681540, -9.657680,
0.441260, 0.857700, -5.536910, -0.962650, -2.475590, 4.193330, -1.614130, -5.982300, -0.448800, 0.461760,
5.785810, -8.558780, -0.597220, -1.128490, 0.314500, 0.553060, 0.672860, 6.750670, 0.269650, -4.341680,
-2.264770, -1.312730, 9.755640, 18.021740, -5.612620, -5.578770, -9.770180, -2.763760, 2.152110, -3.431510,
-2.449560, -2.276440, 1.238220, -0.251910, -0.584560, 3.928620, 1.256060, 3.712670, -24.603001, 8.517180,
-2.721320, -4.536280, -4.851990, 0.035600, -11.468990, 1.413360, -0.809190, -1.251400, 8.232190, 0.010740,
3.424040, -0.214770, -0.898130, 9.410580, -2.544620, 0.316060, 6.052970, -0.181070, 0.970910, 1.051400,

-4.037040, 0.154480, 0.460420, -1.283290, 0.285910, 0.527000, 1.491830, -0.299600, -2.125030, -0.245750,
1.113530, -0.208400, 0.412610, 0.952600, 0.962740, -2.595300, -1.006820, -1.106850, 1.228400, -0.678750,
0.161670, 0.142520, 0.504320, -0.959900, -2.664520, 0.764610, -0.035830, 0.292930, -1.027840, -0.349640,
-0.870570, -0.465320, 1.076300, -1.850130, 0.358240, -0.979960, 2.489120, 0.253210, -2.063010, 3.202940,
0.878940, -0.201360, -5.563700, 0.168710, -0.142000, -4.648470, 0.075160, -2.119090, -1.168060, -0.864660,
-0.378880, 0.974120, 0.861300, -0.126770, -0.110870, 0.983830, -2.424360, -4.013690, 0.514420, 0.364670,
-1.351760, 0.228200, 0.003500, -0.429580, 0.636200, -0.756210, 0.467940, -1.084620, 0.691450, 0.449900,
2.374280, 0.545360, -1.293920, -0.390760, -0.229610, -1.708950, 0.352580, 1.425540, 0.545520, -1.225710,
-0.064010, -0.543200, -0.592540, 1.210380, 3.132180, 0.377220, -0.081590, 1.033660, -2.257120, -0.434090,
-2.324320, -0.030640, 0.934510, -3.357720, 0.968710, -0.895430, -1.496160, 2.001680, 1.047920, 1.217420,
2.324130, 4.071090, 0.407100, -1.439030, -1.786210, -1.095340, -1.090100, 2.828330, 1.267380, 2.838850,
2.415110, 1.115080, -2.476050, 0.689680, 0.661230, 0.811750, -0.196660, -0.790830, 2.801780, -0.862320,
1.659800, 0.290870, 3.243530, 0.146360, -0.665520, 0.061340, -0.483000, 4.131290, -5.452420, -0.469310,
0.283070, 0.524320, -0.485770, -1.707620, 1.623150, 0.381060, -2.436480, -0.766770, 3.146980, -1.244940,

0.007530, -0.035770, -0.342520, 0.186450, -0.184790, -0.397260, -0.355590, 0.800910, 0.206710, 0.046200,
0.256220, 0.087280, 0.488530, 0.673420, 0.019130, -0.664700, 0.212810, 0.081910, -1.173650, 0.090270,
0.001500, 0.373170, 0.990550, 0.352730, 0.995650, 0.482930, 0.319990, 0.263410, -0.576670, -0.370280,
0.151450, -0.712980, -0.193430, -0.040820, 0.630400, -0.545520, 0.214370, -0.782380, 1.045500, 1.040050,
-0.581500, -0.538460, 0.682680, 0.775110, -0.749860, 0.885510, -0.347970, -0.373960, 0.136660, 0.631530,
-1.032850, -0.964920, -0.127390, -0.370640, -0.572260, -0.319690, -1.882370, -0.292250, 0.164030, 0.843130,
0.951890, 0.543140, -1.240130, -0.725770, 0.366420, 0.526000, 0.888220, -0.448320, 0.319260, -0.077940,
-0.658880, 0.405510, -0.232320, 0.808480, 0.602160, 0.610920, 0.923550, 0.607380, 0.035710, -0.193580,
-0.897880, -1.075580, 0.092010, -1.482850, 0.602700, -1.007220, -0.149880, 0.873190, 0.546380, -0.697640,
-0.433110, -0.356650, 0.937300, 1.102460, 0.626520, 0.374390, 0.981580, 1.701890, 0.883250, -0.110280,
0.800040, 0.923650, 0.225190, 0.510230, -5.075910, 3.604600, -0.700700, 5.784520, 0.001210, -0.973630,
0.620250, 0.229900, -0.687150, -0.087040, -0.316850, 0.156580, -0.273840, -0.727460, -1.063110, -1.613390,
-1.250410, 0.580560, 0.010840, -0.859680, 0.014560, -0.540090, -0.420870, 0.605500, 0.669220, -0.002030,
0.176560, 0.339700, 0.179970, -0.113200, -0.063480, -0.316670, -0.256420, 0.452860, -1.676630, 0.392720,

-1.494220, -0.890660, -0.419590, -0.770470, -1.941430, -0.660570, -1.393440, -0.192170, -0.981130, 0.123860,
0.741650, -0.767510, 0.713140, -0.712300, 0.364160, -1.330660, -0.124490, 0.195360, -0.682740, 2.427130,
-0.270700, 0.833470, -0.591650, 0.373500, 0.112310, 0.933040, 0.309770, 0.649440, -0.095700, 0.112830,
-0.439980, -1.364570, 0.510860, 0.184930, 0.335980, 0.297760, -1.043620, 0.296430, -1.512950, -0.431600,
-0.690770, -0.108640, -1.293670, 0.033620, -0.063290, -0.709040, -0.279640, 0.730840, -0.077580, -0.173760,
0.156840, 0.496330, 0.629540, -0.204580, -0.117730, -0.118500, 0.382110, -0.198760, -0.461190, -0.826920,
-0.284890, 1.206580, -2.372930, -0.414660, -1.623750, -2.155190, 0.696500, 0.563240, 0.717030, 0.279280,
1.609920, 1.416930, 1.570030, -2.358300, -0.058520, -0.017320, 0.135940, -0.914170, 1.049320, 5.032110,
1.694690, -0.670040, -1.699850, 0.495920, 0.766780, -0.773280, -0.220300, 0.335440, 4.864960, 2.904310,
-0.291920, -1.605950, -2.485540, -0.272980, -4.772790, 1.117880, 0.116530, 1.332600, -3.487580, 0.945520,
0.645610, -0.613440, 0.890460, -0.415240, -1.507650, 3.224640, 6.525330, -5.793940, -6.376860, 2.739590,
1.435100, 2.490460, -1.059150, 0.265550, 0.577460, 1.352500, -0.235950, 0.126160, -11.070730, -0.460970,
-1.610260, -0.378240, -3.558700, 0.538290, -0.639580, -0.353760, 0.937210, 1.529220, 0.287740, -0.844460,
-0.468530, -0.420360, 0.184860, -0.804610, 0.553540, 0.701580, 0.558180, -0.459250, 0.137600, 0.286120,

-0.050980, 0.245850, 0.129740, -0.399000, 1.751650, 0.945130, -3.865260, -0.821070, -0.960490, 2.566920,
-0.126540, -0.092500, 0.328590, 0.797500, -0.737560, -2.749710, 0.045250, -1.001580, 4.405600, 0.239540,
0.765000, 4.915370, 0.138170, -0.688180, -8.956000, 0.600630, 0.665700, 0.156790, -0.925320, -1.200950,
-1.399480, 0.139030, -0.306770, -3.390480, -0.280770, 0.899010, -1.359200, 0.269240, -1.792930, 4.095720,
-0.782840, -3.521780, -0.799660, 0.606660, 0.149700, 3.092950, -0.625000, 5.148480, -6.026700, 1.010250,
1.237400, -2.161400, -0.031420, -1.081900, 2.522370, -0.636860, 4.113860, -3.338000, -0.597480, -0.322840,
-1.227220, 0.605980, -2.307270, -1.249980, -0.047590, 0.454480, -1.220220, -0.843810, -0.700040, -0.378470,
-0.009910, -0.370240, 0.268840, -0.293490, -0.457950, -0.838760, 1.522330, -0.476890, -3.294340, 0.467160,
-0.290110, 5.188570, 0.630100, -3.594580, -0.442160, -0.949280, 0.278400, -1.047190, -0.105440, -0.169330,
1.087300, 0.696890, 0.971620, 1.279460, 0.481010, -0.089490, 3.803370, -1.772400, -2.162720, -3.141560,
-4.941580, 5.465120, 8.510840, -5.134100, 2.349610, -0.686310, -0.522700, 0.307300, -3.308070, 1.085600,
-3.484330, -1.264840, 0.758310, 0.417890, 3.908660, -1.676730, 1.266070, -0.594800, 2.215860, -2.788750,
-6.111520, 1.358530, -7.587490, 1.027430, -1.417010, 0.801430, 0.483540, 2.579680, 2.171860, 0.047230,
5.697410, -1.035720, -0.203260, -0.389290, 0.646100, 0.226470, 0.656660, -0.329220, 0.809940, -0.216740,

-0.965050, -0.683750, 0.897180, 0.689510, 1.650410, -0.242980, 1.573870, 0.320000, 0.122800, -0.012350,
0.441310, 2.008340, 0.650920, 0.153010, -0.117990, 0.654310, 3.433460, 0.816970, -0.192530, -0.667350,
0.105710, 0.786870, -0.052960, 0.388420, -1.611320, -2.264120, -0.374730, -0.656570, -1.661280, 1.019590,
0.858310, 2.598480, -1.665970, -0.484890, -7.804100, -1.668200, 0.962160, 2.238010, 1.417320, 0.494780,
1.915060, -0.020580, 0.132560, -4.571170, -1.524790, 0.652300, -5.748350, 0.956180, -0.381320, 6.239280,
0.412560, -0.287940, 0.728590, 1.386610, 0.608210, 0.233570, -1.197130, -0.635330, -4.834670, 0.995060,
0.594200, 0.902490, -0.435740, 0.725790, -1.322510, -2.544080, 0.865540, -0.520180, -0.621820, -0.791730,
1.510060, -0.306040, -0.325770, -0.582910, -2.249040, 0.528480, 1.875100, 1.013780, -0.328290, 3.058210,
0.045370, -1.049890, -1.134820, 2.334960, 0.740300, -0.244600, 0.690820, -0.610070, -0.917370, -0.511630,
0.077360, 0.095430, -0.706040, -0.638890, -0.679520, -2.234140, -0.603110, -3.311560, 0.239130, -1.365260,
-2.135740, -2.454760, -1.377870, 5.370930, 6.131320, -11.458590, 1.272010, 9.068920, -1.298960, -5.575320,
-1.883930, 0.180920, -1.023850, 0.413740, -1.391430, -1.331720, -1.273500, -0.699570, -41.693562, -4.846200,
0.589950, 0.779400, -2.831160, -0.302860, -0.685360, 0.359690, 0.329410, -2.035620, -2.449160, -0.325510,
-1.216960, 0.051470, -0.919510, 0.162660, 0.595160, 0.156410, 0.330540, -0.377020, -0.668140, 0.356490,

-0.095570, -0.191960, -1.818510, -1.368890, 0.507670, 0.114790, 0.793810, -1.080330, 0.327910, -1.108850,
0.096310, 0.978990, 1.357300, 0.302230, 0.004150, -0.145910, -1.231330, -0.891210, 0.582860, -0.394820,
-0.502630, 0.548140, -0.821270, 0.560970, 0.449450, 0.742590, -0.180060, 0.850780, -0.397610, -0.588200,
0.957170, -2.382050, 0.933880, -1.261030, -0.716820, 0.285620, -0.367360, 2.122830, 1.294470, -0.228860,
1.384410, -0.690040, 1.990450, -1.982080, -2.082970, -1.267220, 4.691780, -1.409890, -0.831940, 0.237580,
0.573270, 0.072170, -2.713930, 0.947890, 0.498540, 0.089590, -0.701540, -1.617730, 1.105380, 0.929310,
-0.913580, -0.210720, -1.205200, -0.131980, -1.282020, 2.645670, -1.800830, 0.679340, 1.029160, -0.094160,
-0.592820, -0.796530, -0.788580, -0.930860, 2.129600, -1.021870, 0.862060, 2.149030, -0.040000, -0.010550,
-0.245680, 0.422560, -0.412040, -2.725970, 1.385130, -0.903850, 0.452790, -0.538200, 0.406850, 1.595870,
2.472870, -0.266580, -0.874730, 1.001450, -0.514490, -0.674640, -0.462430, 1.873550, 0.346430, -0.399250,
2.516050, -2.180390, 10.777950, -7.289050, -0.406130, -6.473980, 13.703890, -6.187200, 5.496950, -1.068840,
2.653460, 1.182290, 0.478700, 0.520390, -0.978550, -1.926310, -0.256740, 0.042380, -3.364510, -1.510800,
1.114900, 0.351010, 1.253720, 0.395700, 1.157470, -0.845060, -0.486210, -0.125150, 0.256430, -0.071440,
-2.980960, 0.292400, 0.622930, 0.317240, 0.604900, 0.597670, -2.188910, 0.498500, -0.660600, 0.103440,

-0.058850, 0.083750, 0.855110, -0.712510, -0.751110, -1.825990, -0.380620, 0.851440, -0.316480, -0.060530,
-0.487960, -0.539390, 0.812980, 0.127680, 0.428340, 3.062340, 6.196540, 0.485260, -0.797260, -0.787830,
0.453460, -0.937900, 0.519290, -0.025850, -0.527100, 1.515510, 0.793460, -0.307900, 0.737350, 0.314570,
-2.143050, -5.821790, 0.912270, -1.593900, -1.914120, -1.217300, -0.346370, -2.753940, -0.116680, 0.896560,
-1.756560, 0.607030, -0.605840, 2.219180, -0.839250, -0.498420, -1.437280, 3.385180, -0.478100, 0.531000,
-1.088620, 1.198120, 0.217550, -0.871590, 1.712440, 2.070850, 1.471400, -0.556040, 0.070230, -0.264470,
-2.727450, 0.533230, -1.039720, 0.386810, 0.184150, -1.802610, 0.403580, -0.707890, -1.244710, -0.666600,
-0.752850, -0.022930, -1.054670, 0.464880, -0.509190, 0.667900, -1.313230, -0.385500, -1.988200, -2.420910,
-0.826730, -0.750200, -0.512950, 0.349660, -0.335260, -1.599210, -0.771070, -2.053840, 0.612860, 0.514160,
-0.772470, -0.053440, -0.267210, -0.683440, -1.857230, -0.877410, -1.219730, 2.119430, -0.589510, -1.242130,
-0.072370, 1.063160, 0.866700, -4.659840, 6.555860, 0.112720, -4.749940, -1.558070, 4.834420, -0.025860,
0.498860, 1.692330, 0.487680, 0.428010, 0.568480, 0.725060, -1.675040, 0.882770, 1.393790, 1.190400,
-0.304010, -0.000920, 1.625440, 0.604990, 1.420330, -0.439070, -0.329790, -2.988340, 1.723210, 0.835670,
0.003900, 1.188280, -2.098450, 0.963610, -1.015820, -0.773010, 2.566860, -1.025940, 0.298290, 0.845060,

1.040700, -0.924080, -2.921660, 1.054810, 5.097280, -0.235260, 7.281120, -0.130980, 0.332280, 0.259640,
3.398010, 1.372440, 0.447630, 0.015280, 0.359870, 0.501850, -0.307750, 0.345400, 1.348320, 0.259360,
-3.385280, -0.620060, 0.275050, 1.582240, 0.381320, 2.536650, 3.672820, -0.357950, 1.890550, 6.425730,
0.777830, 0.982070, -0.286230, 0.522840, -3.028520, -6.135520, 0.528010, 0.155060, 4.465820, -0.378330,
-0.089470, 2.362800, 0.414030, -1.475150, 1.055510, 0.066100, -1.060800, 18.762369, -1.358900, 0.705970,
-1.605140, 4.291250, -1.290740, -0.640470, -1.166270, -0.057780, -2.994870, -5.768140, -0.071790, 0.815020,
2.712970, -4.055400, -1.274090, 0.775920, 0.743980, 5.787760, 0.518390, -0.874730, -1.623070, -0.966960,
-2.301020, 0.703670, -1.483800, -0.551050, -2.795150, -0.963040, 1.310180, -0.295080, -0.229540, -0.604530,
-0.376050, -0.669850, 5.510250, -6.158450, -1.972400, -6.235650, 2.056150, -0.182740, -3.613070, 0.456590,
-3.131720, -2.470270, -0.510160, -0.275720, 4.701500, -0.198470, 3.598050, -4.741620, -1.549260, -3.741910,
1.690640, 3.264970, -6.429030, -3.229090, 12.724950, -3.297100, -13.886030, -4.166130, 8.517560, 3.784860,
0.315420, 0.237530, 1.849190, 0.569980, -2.770610, -3.047500, 1.850780, 1.153290, -1.396480, 1.695140,
5.375560, -3.400080, -2.582980, -1.539990, 4.031830, 1.893600, 1.993720, -4.511910, -2.108470, 0.094770,
1.703710, -0.291770, 4.040370, 0.161130, -2.714390, 0.148430, 0.227610, -0.601530, 1.359490, -0.373010,

-0.446800, 0.543500, 0.023580, 0.513170, -0.594340, 0.703940, -0.656060, -0.159200, 0.203290, -0.200250,
-0.827350, -1.019660, 0.535440, -1.307250, -0.012360, 0.016950, 0.842870, 0.850190, -0.482130, 0.558750,
0.070390, -0.141000, -0.583240, 0.150210, 1.494360, -0.732040, -0.292690, 0.920390, -0.463180, -3.548250,
-0.045050, 0.105780, -0.115680, 0.009560, -1.299280, 2.917810, -0.814670, -0.974520, 0.296480, 0.514930,
-0.384960, -0.938880, -0.221150, -1.773380, 3.703670, -1.254690, 0.570760, 16.357651, 0.141300, -0.630480,
2.465130, -0.445570, -2.980350, 0.482090, 0.080200, 0.159960, -13.456940, -0.196160, 0.621890, 3.709040,
0.141050, -0.746580, -0.332130, -1.605550, 0.515500, 2.937090, -0.563880, 1.589880, -2.069040, 0.305810,
1.547740, 0.515900, -0.999430, -0.695680, 1.094320, 0.903050, 2.694430, -0.715670, -0.318070, 0.352900,
-0.153960, -1.864920, -0.357490, 0.528730, 2.335460, -0.582950, 0.296290, -0.676300, -0.130710, -0.444150,
-0.770850, 0.648890, 0.770620, 0.902890, -0.385790, -0.188060, 1.111770, 1.901840, 1.026200, 1.442370,
-2.672380, -0.087570, 4.249290, 4.344300, -0.233510, 1.953020, 4.425620, -0.758410, -1.325430, 0.804840,
1.226280, -3.301670, 0.200680, -0.770410, -3.020250, -0.826880, 1.347970, -0.621390, 0.964130, 0.184830,
0.192440, 1.000180, 10.522560, 0.289150, -1.323720, 0.538520, 0.317430, -1.801100, -2.678860, -0.667860,
3.430460, -0.962050, 0.898040, 1.353880, 0.131130, 0.268580, -0.167640, 0.682760, -0.123020, 0.312770,

-0.371860, -0.644620, -0.383350, -1.283530, 0.537370, 0.207050, -0.697090, -1.749580, -0.597600, -0.005690,
-0.899130, -0.603580, 0.199770, 1.208840, -0.328570, -0.407760, -0.000170, 0.113210, -0.221780, -0.966730,
-0.418120, 0.338560, 1.309720, 0.533220, 0.680400, 0.482800, 0.537830, -0.235380, -1.406820, -0.194920,
0.555560, -0.010070, 0.048380, -0.634230, 0.456790, -0.240330, 0.228130, 0.430790, -0.160480, 0.126520,
-0.938610, 0.172920, 0.428690, 1.919590, -0.154030, -2.960300, -0.130780, -0.647380, 0.708300, -1.394890,
1.684510, 1.180730, 3.506200, 0.780150, -0.404330, 0.099800, 1.403800, -0.204370, -0.425270, 0.862360,
0.975030, -0.020480, -0.247170, -0.851340, -3.555050, -0.457460, -0.004870, 2.300810, -0.709990, 0.041100,
-3.230850, 0.216190, 0.149840, -1.327800, -1.047360, 0.074250, -1.812710, -0.290720, 0.484520, 1.846290,
0.608970, -0.040340, -0.289510, -0.112710, 0.290240, 0.516680, -0.663830, -0.742620, 0.181180, 0.654360,
0.064990, -0.921350, -0.205990, -0.245220, 0.498710, 0.399020, 0.791140, 0.735930, -0.394520, 1.107300,
0.336750, 0.022760, -2.078920, -7.171750, 0.502490, 1.530670, 4.793510, 3.202620, -2.000420, -2.141370,
0.559030, -1.128700, -1.126070, 0.280620, -0.153590, -0.077110, -0.310200, 0.769430, 0.154210, -0.462790,
-0.193880, -0.176280, 0.642580, 0.404820, -1.324320, 0.517970, 1.074130, 0.416440, 1.740340, -0.712360,
-0.245740, -0.785630, -0.653070, -0.641970, 0.253890, -0.964400, -0.524190, 0.283140, 0.059970, -0.437140,

-1.557240, 0.059030, 0.474970, -0.833080, 0.220770, 0.231100, 0.523560, -0.694080, -0.017540, 1.313690,
2.048830, -0.815290, -0.549100, 0.576900, -0.332820, 1.731220, 0.245220, 1.794620, 2.090530, 0.144800,
1.685780, 0.235660, 0.125770, 1.106810, -0.378660, 0.083880, 0.290760, -0.847100, 0.869390, -0.232720,
2.710570, 4.006900, 0.576280, 0.971290, 0.554420, 0.183980, 2.087410, 0.852820, 0.335060, 0.847570,
-0.720590, -0.598140, -0.713820, -2.636270, -1.192830, -3.262510, -0.197450, -0.655550, 1.349540, -0.506450,
-1.013110, -0.713180, 1.697910, -0.047960, -6.391940, 0.292800, -1.109320, 2.304300, 0.249550, 1.231810,
1.611110, -0.743180, -0.565480, -4.596920, -1.939100, -1.990140, 1.427750, 0.212470, 0.626240, 1.931230,
0.957280, 1.393930, -1.603570, -0.058440, 1.410840, 14.465490, 0.743290, -4.480250, -7.471570, 0.529570,
-5.466110, 4.157040, -0.491590, 2.200080, -10.170830, 0.903190, -1.807670, 3.125740, 0.036910, -0.134570,
-31.973700, 0.180750, 4.972430, -9.148590, -0.304550, -5.355790, 5.867120, 1.040290, 0.449570, -1.068990,
0.267190, 1.352050, 4.505480, -1.652530, -2.460670, 0.916910, -1.652700, -3.790570, -5.674910, 4.349690,
1.431840, 2.456260, -2.314940, -0.961590, 1.020440, -0.790290, -0.276400, -1.123220, 0.139650, -0.288810,
-0.647420, -1.422890, -1.683990, 1.160790, 1.475380, 0.633910, 0.469670, -0.589750, 0.457820, 0.323610,
1.717560, -0.115300, 1.349760, 0.363160, 0.023920, 0.424550, -1.741250, -0.885610, -3.268400, -0.807620,

145.410583, 1.026270, 0.028390, 144.335953, 0.103790, 0.985750, 146.059052, -0.823180, -0.485150, 145.449219,
-0.193120, 0.384290, 145.778961, 0.390680, -0.502920, 145.435318, 0.214450, -0.789330, 144.666824, 0.276130,
0.905380, 145.935745, 0.789890, 0.283420, 145.949371, 0.030880, -0.105430, 144.334686, 0.260540, 0.902470,
145.529785, -0.061710, 0.794210, 144.289597, 0.865400, 0.730140, 145.876221, -0.430200, 0.522070, 145.272049,
0.731080, -0.141160, 145.414337, 0.872380, 0.393510, 144.447250, 0.538150, 0.152670, 145.900787, 0.868120,
-0.097710, 145.126968, -0.214420, 0.432710, 145.463440, 0.169130, 0.036180, 145.110336, 0.845780, -0.351700,
145.837540, 0.843000, -0.253620, 144.681946, 0.870760, 0.382860, 144.802109, 0.076920, 0.377280, 145.639862,
-0.528530, 0.988170, 145.092514, 0.901960, 0.885810, 145.742477, 0.871840, 0.166170, 145.483429, 1.002800,
145.735870, 145.213669, 0.490970, 1.018210, 144.811630, 0.957200, 145.142517, 144.406311, 0.559050, 146.106598,
145.677551, 0.240640, 145.659286, 145.883484, 0.271170, 145.058121, 144.535843, 0.692730, 144.616486, 145.314697,
145.012817, 144.369690, 144.264862, 144.588181, 144.989471, 144.662552, 144.434662, 146.127838, 145.746887, 144.687851,
146.063461, 0.998850, 144.410660, 145.627365, 144.498413, 146.167252, 145.571991, 145.073532, -0.161900, -0.161230,
146.158020, -0.453930, 144.922256, 144.997971, 145.504364, 0.780220, 145.228256, 145.238876, 0.504560, 145.896896,
145.726608, 418.610779, 145.043686, 145.876572, 0.814250, 0.265150, 146.076538, 145.718979, 145.446320, 146.124512,

-2.105400, -0.758280, -2.204890, -1.453280, -2.018930, -0.487410, 0.979200, -0.339530, -1.339620, -2.724900,
0.162680, 0.306200, 0.029230, 1.062530, 0.651930, 2.574280, 0.422360, -0.309820, 2.095900, -1.071520,
-0.419310, -0.327930, -0.971190, -0.144620, -3.785280, 0.795660, 1.001940, -15.397360, 0.686000, -0.138730,
7.951830, -3.932370, 3.232470, -0.242190, 0.934820, -0.700560, -1.589610, -0.487210, 0.202800, 0.326060,
-1.047200, 0.126970, -7.382860, 1.741220, -1.270360, -9.845070, 2.362540, 2.377220, 1.882760, -0.685090,
0.377590, 5.230750, 4.898240, 1.164130, 5.422750, -0.726310, -0.154740, -1.034790, -3.632780, 0.348300,
-1.714680, 3.632740, -0.541990, 0.144040, -0.475190, 0.269750, -1.726730, -1.990840, -0.180470, -0.301060,
0.066220, -0.100440, -1.237530, -0.609550, 0.845910, -1.332880, -1.892330, -0.314240, -1.367250, -3.689820,
-0.951210, -1.397310, -0.153900, 0.769390, 0.522320, -0.166080, -0.838190, 0.965040, -1.692080, -0.143010,
-1.229820, 2.516060, -1.710000, 0.295670, 0.914540, -1.138380, -2.031570, -1.673840, 0.321290, 0.166180,
1.526260, 3.202810, 0.006230, 1.879160, -2.475690, 2.774750, 2.324810, -2.683600, 6.786620, -2.634540,
5.721260, 1.057180, 0.336200, -1.136150, 0.243870, 2.562280, 2.213960, -0.007510, 2.568070, 1.854510,
-3.088880, -0.048410, -2.443510, 0.655340, 1.368700, -0.722980, -0.125930, -2.744630, 2.025060, 0.145850,
-2.345380, 0.854860, -0.337230, 0.474330, 0.190950, -0.910260, -1.416050, 0.417160, 1.910020, -1.311690,

-0.148230, 0.022370, -0.442090, 0.059770, -0.119570, 0.761580, 0.495980, -0.594250, 1.075560, 0.353050,
0.095410, 0.307760, 0.227690, 1.585410, -0.389120, 0.383630, -1.465990, -0.326120, 0.001510, 0.579500,
-0.002210, -0.020430, -0.341350, 0.345770, 0.002060, -0.048440, -0.603280, -1.389230, -0.018880, 0.209300,
-0.882290, 2.139970, 0.709290, 3.050900, -0.432650, -0.729450, 3.342940, 1.231370, 0.761360, -1.588040,
-0.822870, -0.953610, 1.424110, -0.072080, -1.190570, 5.227640, -0.594960, 0.240520, -6.645210, -0.571300,
0.474230, 3.166700, 0.153470, -1.027050, 8.495570, -0.746260, 0.445310, 2.324260, -0.220290, -1.689020,
0.307930, -0.463780, -0.834650, 12.524860, 0.769660, 0.412700, -2.511760, -0.748600, -0.898620, -0.576440,
-1.761420, -0.783590, -0.564160, -0.752310, -0.951330, -2.016570, 0.042320, -1.078180, 0.759690, -0.508740,
0.909730, -0.845300, -0.663920, -0.483350, -0.381150, 0.507050, 0.158190, -0.420030, 0.221250, -0.566820,
-1.329090, 0.331510, -1.522070, -0.306320, 0.082260, 0.664800, 0.966330, -0.439700, 0.267780, 1.209170,
-2.284970, -1.871410, 0.793230, 1.716210, 2.204320, 0.198630, 0.070220, -3.308780, 0.176560, 0.092980,
-2.766340, -1.850230, -0.235570, -0.637870, 0.111790, -1.817700, 0.402210, 0.425090, 0.780860, 1.072760,
1.882480, -0.224690, 0.877570, 0.957620, 0.559520, 0.499570, 0.345320, -0.732920, -1.166720, 0.630650,
-0.274660, 0.177630, 0.555080, 0.742790, -0.104750, 0.107490, 0.317410, 0.779350, -4.967000, 0.225780,

-1.269710, 0.188750, -0.914090, 0.765260, -1.602330, -0.751810, -0.751280, 0.909060, 0.173070, -0.526540,
-0.078230, -0.694750, -0.259080, -0.248910, -0.852920, 0.105700, 0.873590, -0.254590, -0.186640, -1.525790,
0.093310, -0.675940, -0.395290, 0.514930, -0.240400, -0.639280, -0.204250, -0.276400, -0.916480, -0.775570,
0.445170, -1.645430, 0.466040, -0.667170, 1.478580, 0.162370, 1.274460, 0.059930, -1.000960, 1.430500,
0.415970, -0.471600, -3.001170, -1.656460, -0.344880, -1.955810, -0.071780, -1.427430, 1.840560, -0.542660,
1.046320, -0.894600, 3.181250, 1.863360, -1.629410, 0.585400, 0.097750, 0.710470, -0.287870, 2.091710,
1.368720, 0.973800, 0.659320, -2.272520, 0.306060, 1.460580, -1.499020, 1.903180, 0.355360, 0.879290,
-0.063630, 0.323400, -3.276200, 0.893580, 0.542200, 2.548400, 1.042760, 0.424080, 0.257220, 0.083240,
-0.349510, -1.319330, 0.930960, 2.374670, 0.772690, -0.533320, 0.426770, -0.834170, 0.846150, -0.712920,
0.030490, 0.345170, 0.189760, -0.353910, -1.577970, -0.928570, 0.295350, 1.195970, 0.351170, 0.672140,
-0.830890, -0.689530, 1.746650, 1.908650, 1.079550, -1.758180, -1.269390, -1.910680, 0.554650, -0.345430,
-0.884730, 0.279130, 0.029870, -0.051730, -0.732340, -0.304500, -0.608500, -0.717780, 2.416800, -0.953520,
-0.873240, -0.457930, 1.055790, -0.388980, -0.681070, 0.505720, 0.225830, -0.217250, 0.354510, -0.906200,
1.474460, 0.326740, -0.409780, -0.341070, -0.134390, 0.351950, 0.223030, 0.445590, -1.104470, -0.615200,

-0.883530, -0.205550, -0.827110, 1.213190, -0.687010, 0.711180, -0.427770, 0.803260, 0.459310, 0.516120,
0.994550, -0.134900, 0.883010, -0.703560, -0.342230, -0.030310, 0.659910, 0.656440, -0.496980, 1.021030,
0.785930, -0.199010, 0.247700, 0.102810, 0.276500, 0.207440, 0.128750, -1.096460, 1.161960, -0.827620,
-1.407200, 1.102490, 0.628590, 0.901050, 0.262780, -1.045380, 0.941840, -0.768140, -0.234530, -0.783030,
0.494050, -0.671890, -0.403620, -0.262630, 0.087940, -0.662390, -0.143970, -4.525830, -1.096410, -0.334250,
0.061540, 1.449900, -0.478870, 0.570000, -2.780470, -0.132050, 0.540600, 0.227660, -0.632000, 0.561330,
2.291100, 1.068480, -0.245130, -1.670290, -1.727450, 4.539170, 0.162220, -0.288840, 0.549600, 0.711910,
-0.514340, 0.895350, -0.122370, -1.525350, 0.482180, -0.688920, 0.795610, -0.992110, -0.474810, -1.329410,
0.043220, -0.092330, 0.765670, -0.593010, 0.279330, -0.054850, 0.975760, -0.989140, 0.485910, -0.414670,
0.896750, 1.111150, 0.342920, -0.235100, -2.399620, -0.459120, 0.963060, 0.381570, 0.091730, -0.664920,
0.085720, 1.805690, 0.978030, -1.686360, -0.576120, -1.732350, 1.298420, 1.087260, -2.414540, -1.269960,
-1.727370, -0.231520, -0.796870, -0.081450, -0.999820, 1.643250, -0.497320, -0.314910, -1.152560, 0.246310,
1.952800, 0.043700, -1.157910, 1.017810, 1.243700, -0.051750, -0.585690, 4.314300, -0.030180, 0.248780,
-0.457500, 0.826260, 0.148310, -0.310600, -0.420700, -0.245450, -0.178290, 0.223250, -0.376130, 0.714010,

-0.384000, 0.219320, 1.586830, -0.353410, 1.368090, -0.979970, 2.715950, -1.329610, -0.789970, -0.705540,
3.761100, -0.768040, 0.842270, 0.246070, -0.539620, -0.658090, -1.976160, -0.512670, -0.962470, -0.045040,
-0.019220, -1.518280, 0.838390, -0.731420, -2.915310, -1.102720, 0.652540, 11.497430, -0.053580, -0.671650,
-0.492480, 0.619110, -0.588240, -6.417070, 1.784610, -0.252130, 0.127640, -0.529830, -0.474830, -0.220620,
0.839760, -0.164130, -5.523680, -0.658050, 0.583740, 1.040230, -0.312040, -1.726520, 1.687210, 0.465930,
1.422990, -1.534250, -1.916100, 2.985100, 4.429660, -0.370350, -3.958390, -0.256220, -0.610050, 2.694960,
3.914180, -1.729470, 1.863790, 0.638030, 0.113220, 0.431970, 1.250080, 1.147500, 1.049200, 0.069860,
-2.437050, 1.788340, 0.753130, 0.112960, 1.448990, 0.107230, -0.435160, 0.542590, 4.153280, 0.264530,
1.227660, -2.915820, -0.211500, 0.858870, 1.051320, 0.162840, -0.523640, 0.037240, 0.388080, -1.753020,
0.516840, -1.304150, 0.279800, -0.795990, -1.444200, 0.772420, -1.447670, 4.024440, -0.684780, 1.365670,
2.978790, -0.171510, -5.282140, 2.371850, -0.284060, -0.130090, 0.549650, 10.132290, -1.970990, -3.831610,
-2.448650, -0.496300, -0.597870, 0.054040, -1.862900, 2.914120, -1.160110, 0.912490, 1.340050, -0.744940,
-4.850480, 0.072500, -5.853800, -0.522250, 0.662320, 0.982080, -0.030680, -7.442980, 5.700540, 0.570070,
-4.367280, -0.895960, -0.474200, -0.366740, 0.085810, -0.275010, -0.210610, -0.757790, -5.581060, -1.351980,

0.127380, 0.247720, 0.816790, 0.193110, 0.282220, -0.967830, -0.001830, 1.887410, -0.692320, 0.243970,
0.619670, 0.980470, -0.801290, -1.045920, -0.121000, -1.301570, -1.158000, 0.164800, -0.716560, 0.696430,
-0.584590, -0.112730, 0.905150, -0.143320, -0.751430, -0.939470, 1.293080, -0.092080, -2.891030, -2.194220,
0.160460, 0.490210, 0.798920, 1.209080, 1.182480, 0.451750, 0.291420, 2.989300, -0.640700, -0.026380,
6.781340, 0.508410, -0.117110, -10.614380, -0.775940, 0.311860, 5.873290, -2.542420, -0.738790, -10.434710,
-0.570390, -0.734420, 0.232050, -0.417940, -0.843020, 11.454670, -0.958860, -0.206760, -12.507640, 1.060470,
-0.733290, 1.015770, -4.711790, -0.727630, 21.987431, 17.225229, 0.693670, 10.221040, 7.066030, -0.836720,
-20.406719, 0.616940, 0.166790, -1.037280, 10.268760, -0.567730, -17.921829, 0.216640, 0.952460, 25.253151,
-1.948100, 0.148050, 34.293758, 2.803870, 0.251860, 0.352280, 0.446890, -0.423230, -16.068911, 3.286010,
0.673780, -7.465360, -3.065610, 0.265330, 18.256399, -2.197510, 0.830940, 10.780960, 0.066400, -3.053090,
0.580940, 3.049960, -0.400520, -1.012770, -0.584950, -3.396830, 5.805030, 6.603980, -1.643590, 1.026700,
-1.940550, 1.253810, -1.027130, 0.405870, 1.256370, 0.562960, -0.082920, -0.255890, -14.102520, -0.776470,
-0.651710, 0.763860, -1.529270, 0.156140, -0.589480, 0.626230, -0.060090, -2.468810, -2.633020, -0.544860,
-3.274310, 1.361950, -11.249790, -0.898170, 0.401110, 0.681300, -0.109120, -0.330320, -0.036250, -0.669360,

-0.332700, 3.426290, 0.156070, 0.733450, -0.628620, 0.164060, -0.699640, 1.492310, -0.552330, -1.136460,
1.239470, 1.450580, 2.287150, -1.030600, 0.442850, -0.354840, 1.006230, 0.462140, -0.265380, 0.272070,
0.587620, 2.265610, -3.397310, 0.863350, -3.142820, 2.075330, -0.572010, 0.783020, 0.225310, 1.607370,
-0.168730, -1.374210, 0.407250, 4.900600, 1.933770, -0.447840, -0.659260, -1.356760, 1.506690, -0.277040,
-0.855380, 2.060820, 2.939270, -0.253410, 0.546190, 0.017170, 1.030030, -1.097050, -2.054840, 0.432450,
0.134620, 0.101490, 1.791920, -1.113840, 0.590390, -0.117270, -2.411290, 0.685180, -0.209770, -0.753850,
-0.936580, -0.277600, 0.177980, 1.088950, 2.190020, -0.345210, -1.623230, -0.510870, 0.562870, -0.683080,
0.322110, 1.277820, -0.646970, 2.228110, -0.730970, 0.246960, 0.745420, -0.543530, 2.106350, 1.224470,
-1.274230, -0.186630, 0.506520, 6.159770, -0.254270, 0.202930, -3.173880, 0.466240, -0.969120, -2.594760,
2.771930, 0.835190, 4.297670, 0.561200, -0.773560, -7.071950, 1.101270, -1.973860, -4.497070, -0.052630,
0.538130, -1.977600, 3.428690, -8.162870, 6.171230, -8.641420, -11.390960, -1.791410, -10.080550, -16.444710,
-2.369390, -2.757910, -0.893660, -0.216970, -0.502190, 5.436730, 1.222420, 0.222920, 5.547800, -1.102700,
-0.441540, -0.482990, -9.639250, -0.099930, -0.581570, -0.532400, 2.752460, -11.042430, -1.894030, -0.323460,
0.257860, -0.358730, -1.118990, -0.569670, 1.097440, -0.382990, -0.585620, 0.624030, -2.494730, -1.855040,

418.760071, 417.661133, 417.496643, 418.679169, 418.911133, 417.098816, 418.676819, 417.407410, 418.894867, 418.678070,
418.871887, 417.828857, 419.009552, 417.360748, 417.809448, 418.201324, 418.552551, 417.711182, 418.352722, 417.300842,
418.195923, 417.583191, 146.015747, 418.931946, 417.555908, 144.533661, 418.953857, 417.100311, 145.860672, 418.008545,
417.590393, 145.293716, 417.343689, 417.345856, 144.717499, 144.969955, 418.419891, 145.164017, 418.794708, 417.564453,
144.530197, 145.585785, 418.685089, 145.644409, 146.104156, 418.256989, 145.219635, 144.763062, 145.543564, 146.151382,
145.634064, 144.349136, 417.865967, 144.811005, 144.490662, 145.953918, 145.479034, 145.541763, 145.195847, 144.793411,
144.945465, 417.729156, 417.052307, 145.891846, 146.080322, 145.598755, 145.668869, 417.075470, 144.385284, 418.787903,
144.836685, 418.915344, 144.630936, 418.284454, 417.137665, 417.075134, 145.676468, 418.332916, 417.401825, 145.011032,
418.385529, 418.209747, 417.638123, 417.989777, 419.009949, 145.859772, 417.528107, 417.047058, 144.700790, 417.318756,
418.044434, 417.326263, 417.909882, 418.662811, 417.264160, 418.722656, 418.774353, 418.683777, 417.535614, 417.306519,
417.758575, 418.222687, 417.935852, 418.207092, 417.132782, 417.401276, 417.910248, 418.342224, 417.544769, 417.149170,
418.697479, 145.849884, 417.918610, 417.163361, 417.049255, 417.239624, 417.410004, 417.959106, 146.110886, 145.560333,
419.014008, 145.703796, 418.065094, 145.731110, 417.189362, 418.759735, 418.922272, 144.727631, 145.050491, 417.416931,
418.950104, 145.245682, 418.017426, 417.727020, 145.758835, 418.238647, 418.510162, 418.739502, 417.538361, 418.330292,

-1.894040, -0.898180, -1.148540, -0.011180, 0.430880, -0.737890, 1.139010, -0.180740, -0.358180, -2.007420,
-0.214200, 2.277220, -1.202940, -1.222820, -1.202720, -0.322630, -0.196700, 0.761020, 0.124100, 0.484080,
0.032450, 0.388720, 0.327720, -1.041610, 0.544480, 0.051370, -0.992930, -0.540090, -0.608920, 1.440740,
-0.811430, 0.575470, 0.492020, 0.068310, 2.498560, 0.202250, -0.335210, -0.073200, 0.347630, -0.066100,
2.270890, 0.313800, 1.805990, -5.101800, 0.047660, 1.453750, 2.014280, -0.569020, -0.093870, 0.474630,
0.289380, 1.522210, -0.984870, -2.678320, 0.135950, 0.342010, 1.045350, 0.922520, -0.387080, -1.275490,
-1.932530, -1.668970, -0.938480, 1.748050, -2.083230, -0.607850, 0.080640, -0.155360, 0.222210, 0.252060,
3.558170, 0.736340, 0.162090, -3.728500, -0.796570, 1.422060, 0.242390, 0.868810, -0.038180, 0.444230,
-0.641420, 0.309320, -1.228900, -0.341500, -0.584220, 2.030000, 0.084710, -0.210450, -4.013280, 0.940460,
-0.211950, -0.872660, -1.382970, 0.106290, 1.429420, -0.748020, 0.143390, -5.801780, -1.909740, -1.005470,
0.456670, 0.807610, -3.937380, -0.819720, 3.723160, 1.552440, 2.634720, 3.092170, -3.199680, 2.999360,
-0.852640, -1.387760, 0.268300, 0.782030, 0.472710, -2.009160, 0.139330, -1.081630, -0.486410, -0.179090,
0.520110, 0.321720, 0.560880, 1.230240, -1.489360, -0.217560, -0.720280, -2.904740, 3.723430, 0.412600,
1.323350, -0.062780, 0.688880, -1.440450, 0.318520, 0.183610, -0.710570, -0.803050, 1.141180, -0.255920,

0.459250, -0.233160, -0.408150, -1.018740, 0.449140, -0.486050, 0.983310, -0.423420, 1.029750, 0.534060,
1.234230, 0.698950, -0.081000, 1.070270, -0.311710, -0.028210, -3.328770, -0.645620, -0.184760, -0.272510,
-0.027720, 0.156360, 1.982160, 0.403930, 0.667190, 1.068630, 0.909870, -0.696310, -0.830680, -0.427110,
-0.181610, 0.211430, -0.431960, 0.101640, 0.155370, -0.952870, -0.616160, 0.594390, -0.519050, 0.191330,
-0.171290, -0.834710, 1.172890, -0.015310, 0.888720, -0.000090, 3.459050, 0.667090, -1.170060, -0.253510,
0.377660, 0.637990, -0.862800, 0.116880, -0.841650, 0.551880, -1.264790, -0.669740, -1.072170, -0.412160,
1.625600, -0.491280, 0.201290, -0.020410, 0.843040, 3.585320, 0.776270, 0.259550, 1.004460, 0.468340,
1.159110, -0.737670, 0.636020, -0.042200, 1.065950, -0.166040, 0.687710, 0.095570, 0.242090, 1.243130,
-0.320810, 1.121310, -0.241880, 0.116330, 0.351860, -0.311170, 0.227260, -1.477780, 1.786630, -1.444900,
-0.313330, 0.537860, 0.342520, 0.661610, -0.405240, 0.565250, 0.951870, -0.530630, -1.240770, 0.905970,
-0.358230, 2.404720, -5.538560, -10.141220, -2.852500, 5.218440, 8.614410, 6.994690, 2.099240, -2.318480,
-0.335010, 0.273730, 1.149920, -0.855230, 0.165580, 0.771360, 0.924860, 0.344850, 15.126340, -2.367930,
-0.897560, -0.266500, 1.393990, -0.768540, -0.625000, -0.826100, -0.401350, -0.095650, -2.919960, 0.926750,
-0.268040, 0.900780, 0.004040, -0.721980, -0.502340, -0.429640, -0.877430, 0.842760, -0.993350, -0.145020,

-0.251490, -0.086160, -0.147590, -0.258410, 0.437620, -0.034160, -0.566370, 0.600680, -47.786129, -0.352910,
-0.510530, -0.010880, 0.696510, -0.611210, 0.424450, -1.085960, 0.478520, -0.791020, 0.575950, -0.015220,
-1.036730, 1.868110, 1.152700, 0.016540, 0.099720, -0.045540, 0.212030, 0.024530, 0.281040, -0.278900,
-0.313430, 0.335170, 2.137220, -0.075330, 0.340260, -0.914300, -2.234910, 0.337290, -1.306470, 0.164130,
0.239590, -1.107180, -0.054070, 0.558830, -0.662260, 0.257380, -0.314490, -0.061720, 1.598970, -0.129620,
2.721730, 0.015400, -4.895220, -0.916610, -1.619200, -2.707690, 0.569450, -1.126320, -0.817210, -0.187510,

1.231800, 0.389100, 0.640980, -0.593910, 0.109510, -0.291110, 0.921850, -0.865070, 5.519470, -0.866610,
-1.977710, -0.209160, -1.713540, -0.520610, 0.756110, 0.483920, -0.421610, 4.309180, -0.144790, -0.042530,
-7.895400, -0.260920, 1.547980, 0.034190, -0.562460, 0.019140, -0.492080, 0.076460, -2.953090, -0.649110,
1.074420, -0.104850, -3.212800, 0.002280, 0.497670, -0.709080, -0.564770, 1.228340, -0.505860, 0.112320,
0.505580, -0.488490, 0.698250, 0.932160, 0.097520, -2.500030, -0.468780, 0.851920, 0.218910, 0.962110,
-3.836380, -0.079230, 0.700030, 0.894100, 3.768530, -0.940920, -0.607730, -1.924330, 2.693740, 2.899510,

0.463040, 0.982340, -1.081380, -0.517200, 0.547490, -0.106060, -0.309580, -0.729190, -0.537230, 0.668010,
-0.275870, -0.258290, 1.907540, 0.578770, -0.701100, -0.993420, -0.183360, 1.921730, 0.512730, 0.255060,
-0.692330, -0.602370, 1.609940, 0.888500, -0.355020, 0.088050, -0.152610, -1.091750, 0.519270, -0.298200,
0.438330, 0.737880, 0.711940, -0.935000, 0.496480, 0.837610, 0.341780, -0.340130, 0.469920, 0.239080,
0.102910, -0.379470, -0.740620, -0.432630, 0.097140, 1.618430, -1.057370, 0.382300, 0.074390, -0.483420,
-10.749950, -0.490080, 0.377620, 0.185310, -0.538800, 0.208590, 0.296000, -0.697980, -1.929150, 0.665500,

-1.622160, 0.469500, -0.360520, -0.189790, -0.360210, -0.029500, 0.529070, 0.881980, 1.388720, 1.224760,
0.576540, 0.192680, 0.559940, -0.416170, 0.109300, 0.358460, 0.542910, 0.084960, 0.752320, 0.849920,
1.308360, -0.804280, 0.381340, -0.743040, 0.014210, -0.713540, -0.002200, 0.052540, -1.508420, 0.164800,
0.424250, -1.179790, -1.059910, -0.507800, -0.285770, -0.252960, 0.685080, 0.323860, 0.461720, -0.640010,
-0.901190, 0.501090, 0.063710, -0.112740, 1.347710, 0.993290, -0.394000, -0.662760, 0.483140, 0.676800,
11.998460, 0.911380, -1.103060, -0.270710, 3.883240, -0.701230, -0.133830, 2.761200, 1.951240, -1.566530,

-0.535540, -0.451980, 0.582680, 0.302140, 0.483380, 0.716970, -2.585300, 0.487900, -48.795528, -3.642310,
1.250390, 0.056400, 1.800340, 0.384600, -1.206980, 0.209390, -0.098960, -0.684190, -1.322460, -0.380690,
-1.132070, 0.037150, -1.199700, 0.209960, 0.677450, -0.793990, 0.745370, -0.104150, 2.314420, 1.443330,
0.731990, -0.259300, -0.493040, 0.545580, 0.460040, -1.322440, -0.628460, 1.271500, -0.265860, 0.833180,
0.314130, -0.744500, -0.059280, -0.747470, -0.601830, -0.053560, 0.542130, -0.647060, 1.622010, -1.204400,
-9.597260, -0.037330, 1.065790, 0.713740, -1.327300, 1.241700, -0.116080, 0.374460, 0.483080, -3.095550,

-1.897650, -0.671770, -0.519690, -0.576250, -0.195790, -0.061070, -0.452870, 0.447610, -2.649670, 2.423150,
-0.342990, -0.147900, -0.762030, 0.410100, 0.785620, 1.013820, -0.578230, -1.315610, -1.018330, -1.081100,
-0.446810, -0.818220, 0.919980, -0.334260, 0.689890, 0.437440, -1.116140, 0.907530, -0.145040, -0.056490,
0.697030, 0.383070, -0.696320, 0.700350, 0.650940, -1.006470, -0.358950, 0.743020, 0.133850, -0.602850,
0.711410, 0.652240, 0.800090, 0.269760, -0.662340, 0.111160, -0.224830, 0.666570, 1.045250, 1.434510,
-6.760140, -0.672710, 1.678140, 0.424640, -0.804040, -0.082840, -0.740880, 0.551880, -1.281540, 1.176860,

0.190370, 0.788780, 0.369230, -0.194810, 0.966680, -1.472190, 1.005910, -0.547610, 25.721870, -0.334510,
1.120840, 0.568350, -2.565000, -0.895590, 0.184140, -0.258570, -1.007690, 1.226760, 0.353010, 0.355870,
0.402290, -1.254210, 0.118170, 0.174760, 0.320480, 0.560070, -0.547160, 0.485180, 0.356190, 0.946040,
-0.826100, 0.055280, -0.461280, -0.554410, 0.914270, -0.092410, 0.557430, -0.437040, 0.097650, -0.172350,
0.344560, -0.517190, -0.714230, 0.550870, 0.055900, -0.546240, -0.198860, -0.848380, -5.191490, 0.302170,
-0.020800, 0.024870, 2.411600, 1.951700, -14.739050, 2.889870, 0.645140, -4.580010, -2.178580, 2.336950,

-1.448460, -3.096810, 0.869270, -0.648260, 1.242240, 3.008030, 0.533880, -0.547770, -55.546761, -1.282730,
2.670880, 0.222070, 2.119820, 0.265220, 1.771820, -0.067540, -1.176380, 0.331580, -4.281910, 0.806320,
-4.490030, -0.460440, -3.763150, 1.105650, -0.221120, -1.198060, 1.823710, -0.149450, 0.566580, 2.477710,
-0.266260, 0.709530, 0.918320, 0.200800, 0.016030, -0.828120, -0.634960, 0.585300, -0.356160, -0.767170,
0.142550, -0.323930, -0.502440, -0.224670, -0.569470, 0.333600, -0.851060, 0.224930, 0.005430, -0.420850,
-5.595770, 0.043070, -0.948080, -0.410980, 3.031570, -5.354010, 0.634960, -2.322300, 1.237080, -0.246430,

0.888280, 0.918100, -0.509230, -0.453360, -1.132430, -0.238310, -0.149840, -0.343660, 47.728310, -0.360780,
-1.386810, 0.909510, -1.677480, -0.153170, -1.121050, -0.420360, -0.444180, -0.814850, 0.090510, 0.955360,
-0.461830, -0.772480, 1.185040, -0.689830, 0.052920, 1.189380, 0.188370, 0.091520, -3.899760, -0.330160,
-0.063770, -0.410430, -0.149710, -0.091710, -0.188300, -0.478400, 0.186040, -1.224260, 0.645720, -0.406000,
0.259720, -0.645050, 0.427900, 0.922080, -0.212360, 0.168030, 0.390520, -0.619100, -2.249920, 1.240370,
2.374000, -0.051970, 1.126340, 0.129030, -5.748650, 3.368260, -0.203580, -0.269600, 0.605480, -0.067930,

1.552160, 0.894730, 0.094490, -0.942970, -9.516030, 0.422080, -1.957370, 0.900990, -0.345540, 0.369940,
-2.191830, -0.570570, 1.139090, -0.171040, -1.971950, -0.595960, -0.548360, 4.726580, 0.834770, 0.715640,
1.190250, -0.096060, -0.672660, -0.418040, -0.584440, -0.795050, 1.339710, 0.505880, -0.330720, 0.622210,
-1.280980, 0.313640, -0.452290, -0.112590, 3.240600, 0.503070, 0.841860, -2.483170, -0.267500, 1.691010,
-0.258840, 0.923220, 0.013620, -0.096440, -2.450850, -0.410260, -0.488970, -1.088440, -1.200050, 2.411280,
-6.917410, -0.226750, 1.016670, 1.121050, -9.548500, 3.074570, -0.905290, -3.448420, -2.310170, 0.967340,

-4.180460, -2.121490, 0.228250, 1.093930, 1.688430, 7.842570, -2.064430, 0.128860, 2.106190, 1.121160,
0.004190, -1.291770, 0.098770, 0.064440, 3.384440, 1.656860, 0.216790, 6.085290, -1.552390, 0.603860,
-2.656420, 2.692500, 1.722250, -0.776510, -0.619040, 0.315290, 0.711110, 0.192510, 3.072470, -1.352140,
-1.744980, 0.867020, -1.888350, -0.251420, -4.237990, -0.071150, -0.611330, 4.735020, -0.189440, -0.840450,
-0.801740, 0.888280, 0.230520, -0.359780, -0.145190, 0.294740, 0.161480, 0.269180, 21.081341, 0.032160,
-20.267330, -0.143750, -0.413740, -0.216430, 3.266280, -1.994960, 0.126010, -2.333650, -0.412640, -0.791000,

157.854523, -2.902380, -1.719640, 0.976910, -5.152710, 1.923980, 155.322250, 0.788610, 32.531441, -15.778200,
-25.892860, -9.360870, 1550.784790, 0.629750, 6.277730, 3.598930, 0.569770, 4.163390, 11.174670, 0.493160,
66.499924, -5.101210, 1.501770, -6.796270, 2.845830, 0.906080, -7.553860, 0.664820, 1259.850220, 4.767140,
2.076840, -2.163170, -10.670380, 0.890510, -1.860390, -0.126630, 1.489380, 7.132880, 1.284720, -12.978230,
2.219230, 3.334480, 0.846450, 0.347740, 4.096770, -14.439030, 1.013500, 1.635640, -2.015500, 28.453131,
-28.182659, 2.806960, -7.841920, 4.687820, -53.309551, 10.733250, -0.256280, 35.542721, 5.209990, 8.014170,

-0.995810, -0.388880, 0.263220, -0.203170, 0.429850, 0.422870, -0.561170, 0.837040, 0.309600, 0.295690,
-0.228180, 0.139990, -0.534280, 0.514770, 0.230810, 0.747250, -0.374050, -0.711370, 0.373100, -0.686850,
1.259700, -0.315550, 0.766120, -0.387980, -0.127720, 0.491400, -0.959690, 0.011770, -0.726130, 0.123470,
0.042070, 0.532400, 0.998600, -0.910190, 0.518090, -0.052450, -0.057630, 0.906390, -0.234210, 0.299260,
-0.651010, 0.042130, -0.732650, -0.001440, -0.948730, -0.270100, -0.089450, 0.895610, 1.454150, -0.628290,
-5.119720, -0.236390, -0.865170, 0.084830, -0.945320, -0.472780, -0.714030, -0.041790, -1.322120, 0.876040,

1.036220, 0.171490, -0.742850, -0.156780, -0.440620, -0.712090, 0.233910, -0.128140, 1.568680, -0.862380,
-1.803060, -0.176510, -0.471830, 0.335000, -1.375790, -0.666290, 0.402730, -0.790970, -0.679580, -0.711770,
-1.863150, 0.183750, 0.677700, -0.025110, 0.313540, 0.933070, 0.797220, 0.670720, -1.795940, -0.295000,
0.002450, 0.149890, -0.284920, -0.314010, 0.408900, -0.910960, 1.003920, 1.224780, 0.446890, 0.337640,
-0.545910, -0.197220, 0.000050, 0.005840, 0.296020, 2.079940, 0.017150, 0.325800, 1.827400, 0.162210,
-5.328910, -0.264480, 0.372690, 0.653170, -1.568970, -0.556240, -0.089480, -3.747160, -0.532580, -1.125120,

1.178320, -1.035830, 0.740880, -1.001230, -0.245160, -2.169350, -1.391240, -0.302550, 1.926910, -1.226830,
1.155200, -0.880360, 1.071860, 0.255700, -8.270300, -0.175620, 0.601150, 2.766940, -0.018780, -0.933080,
1.856460, -1.308120, -0.620340, 0.974830, 0.984930, 0.828230, 0.309210, 0.616070, 2.437440, -0.781070,
0.102880, 0.267430, 1.214360, -0.240610, -0.427730, -0.062970, -0.254460, 0.297550, 0.448060, 0.657080,
-0.066080, -0.984850, 0.498850, 0.510310, 1.462810, 2.211590, -0.102060, -0.495650, 0.625040, 1.383080,
-17.555590, 0.384620, -0.218640, -0.580390, 1.713280, -0.283660, -0.766830, 2.804760, -3.868530, 1.172560,

-0.048610, 0.960430, -1.207860, 0.432610, 0.499310, -1.791960, -0.475500, 0.810760, 3.071970, 0.332480,
-0.166410, 0.111210, -0.289430, 0.222450, -0.622070, 0.820460, 0.818580, 0.836350, 1.321120, 0.214300,
1.907290, -1.646010, 0.939400, 0.469140, 0.268850, 1.428670, -0.195660, -0.780110, -0.206380, -0.334700,
0.186690, 0.001380, -0.323540, -0.415220, 0.107440, 0.646070, -0.019940, -0.067150, -1.257720, -0.508950,
-0.871940, -0.222870, -0.861030, -0.148880, -0.556960, -0.221700, 0.089110, -0.624520, 0.879390, -0.629100,
3.360940, 0.218810, -0.889300, -0.167370, 2.007200, -0.352380, 0.018140, -0.042580, 1.038880, -1.340260,

2.188230, 2.018800, -1.491680, -0.996140, -0.521910, 0.753010, -1.195080, -2.482980, 24.372330, -0.222100,
-5.191970, -0.555210, -1.976510, 0.681060, -0.720350, 0.828560, 0.995100, 10.221180, 3.451870, 0.771090,
6.060240, 0.430300, 2.320060, -2.908350, 1.243400, 0.686360, 0.942530, -0.378680, -0.413560, -1.529970,
-0.614950, -0.709240, 1.408500, 1.499760, -0.266640, 0.059460, -0.085450, -0.621170, 2.136190, 4.264860,
-0.153110, -0.760180, 0.879420, -0.167790, 0.603000, 1.324770, 1.494610, 0.526420, 0.982240, 5.695190,
-6.501590, 1.155980, 2.842480, -0.014930, 0.687970, 1.058540, -0.057300, -1.082480, -0.786840, -3.319310,

-1.967450, -1.611540, -0.640580, 0.903650, 2.319950, -0.680690, -1.371700, -0.896030, 79.258041, -0.255290,
-0.346630, 1.283740, -0.425350, 2.170130, 0.853680, -0.600920, -0.819350, 4.530270, 0.586790, 0.922210,
12.229330, -0.025020, 0.444020, -0.028320, -0.056540, -0.895720, -1.650260, 0.622580, 5.529910, 1.847060,
-0.025510, 0.232380, -2.695530, 0.053360, -0.324540, -0.701630, -1.189590, 2.636730, 0.750580, -0.144910,
-0.906850, 0.467900, -0.267840, -0.509210, -0.989110, -0.296460, 0.470750, 0.385180, 0.348580, -1.755540,
-1.752700, -0.227240, 1.300560, 0.324210, -1.427830, 2.482910, -0.011480, -0.622120, 1.571350, -0.568880,

0.500150, -1.071180, -0.848610, 0.318350, 0.891660, -0.817130, 0.239470, -0.962300, -91.134270, -2.738520,
-0.854830, 0.747890, 0.683030, 0.299780, -0.477970, -0.816390, 0.559550, -1.268600, 0.450850, 0.192870,
-0.891250, 0.688990, -0.173650, 0.079600, 0.965100, -0.739210, -0.717920, -0.335940, 1.819040, 0.146430,
0.171100, 0.723570, -0.984370, 0.413890, 1.193330, -0.796010, -0.301860, 0.580490, -0.565420, 0.075160,
-0.844540, 0.308960, 0.117300, -0.174890, 0.627950, -1.517650, 0.073910, -0.843940, -0.208370, -1.001830,
2.923150, 0.124690, -0.666700, -1.156830, 15.057540, -0.586250, 0.488560, -1.165560, 2.157370, 2.396640,

0.380320, -0.957350, -0.450660, -0.897290, 1.778960, -0.631500, 1.008160, 0.498980, -729.766907, 0.491110,
-0.055450, -1.191910, -4.271470, -1.611620, -0.224280, -0.363150, -0.022310, 1.467540, -0.992380, -0.049240,
-2.739740, 0.639920, 0.728580, 0.513210, 0.307610, -0.582220, -0.120210, 0.845430, -0.056620, 0.442720,
0.624130, -0.861090, -0.578090, -0.430130, -0.689840, -0.690710, -0.000380, -0.236450, -0.359740, -1.136060,
-0.384370, -0.636540, 1.003460, -0.396200, 0.808110, -0.371700, 0.815620, -0.001700, -1.538720, 0.101780,
2.232040, 0.303080, -3.943340, 0.386720, -6.884620, -1.051640, -0.608060, 0.936010, 3.195150, -0.947390,

-36.189548, -9.430280, 0.141730, 0.074850, 1.506100, -0.246550, 8.008520, 0.340450, 2.903900, -2.444130,
-12.924160, 6.427560, -12.118670, 0.647490, -99.047668, -0.239060, 0.524810, 0.493860, 0.618930, -0.530020,
-3.771750, -0.468090, -1.757760, -1.773550, 0.823540, 0.820900, -19.239620, 0.109410, -4.465260, -1.496420,
0.755940, -0.012030, 3.692970, 2.162410, 0.009710, 0.763160, -1.886740, -4.747080, -0.176350, 3.720220,
-1.269060, 0.821430, -2.472950, -1.007510, -2.392830, -3.354440, -0.525230, -0.740440, 3.109950, -4.689220,
1.138630, -0.285810, -1.241460, -1.782520, 15.426530, -0.259470, -0.941830, -2.209140, 0.478690, -6.566010,

5.834260, -0.539660, -0.024230, -0.765780, 0.566020, 1.227680, -1.504530, 0.858440, -3.951400, -6.959820,
-1.056140, 1.752430, -2.888530, -0.057250, -1.425810, -0.533650, -0.556320, 7.609950, 3.904110, -0.177520,
-1.717070, -0.335220, -0.400170, 1.843950, 0.013300, 1.526730, 0.575430, -0.137300, -0.035270, -1.234040,
-0.161620, -0.936330, -0.345800, -0.174910, -1.445470, 0.357860, -0.146220, -0.407180, 1.125820, -0.517020,
0.833980, -0.431570, -0.840120, -0.179010, -0.407990, 2.008660, -0.506520, -0.689410, 0.079120, 1.954660,
19.339979, 0.344110, 0.429740, -0.614440, 0.605520, 2.133850, 0.320870, 1.765300, -2.096760, -3.444950,

4.288920, 2.338920, -0.350070, -0.487570, -3.243440, -0.225000, 1.145040, -0.403790, 0.163900, 0.167440,
-3.567840, -0.672950, 1.559190, -1.025340, -0.451160, 0.243270, -0.365380, 2.271760, 0.404440, -0.526790,
-2.042360, -1.554800, 0.625890, -1.448260, 0.616830, 0.246760, -0.004130, 0.807520, -19.856371, -1.630320,
-0.059860, -0.496530, 0.495340, 0.535410, 1.649790, 0.390120, 0.177470, -0.276490, 0.663600, 0.247440,
0.681500, -0.735660, 0.518510, 0.384980, 0.156900, -0.873180, 0.219870, -1.021660, -3.649200, 0.452910,
-2.347060, 0.373930, 1.054830, 0.850050, -6.434490, 0.575380, 0.517000, 1.917330, -0.762760, -1.191900,

-0.108680, 0.628660, 1.123040, 0.578760, -0.748670, 0.547580, 0.840240, -0.585810, 11.605770, 1.642650,
-3.038650, 0.446940, -2.189460, -1.159940, -1.266360, -0.526780, -0.320820, -3.526780, 2.103340, -0.111070,
0.066080, -0.941000, 1.392260, -0.587290, 0.637930, 0.610550, -0.238250, -0.692330, 1.599030, -1.061630,
-0.847450, 0.508580, 0.291470, 0.712120, -0.202150, -1.140100, 0.241150, -0.651480, -0.431050, -0.680280,
1.204990, 0.149580, 0.844080, 0.664480, -0.908680, 0.729500, 0.630520, -1.106090, -2.334490, 0.091590,
10.843250, -0.263930, 0.600690, -0.281890, -0.136300, 1.313390, 0.067160, 1.284770, -1.617090, 1.544340,

-0.763000, 0.083590, 0.333930, -1.158660, 0.273380, 1.875110, 0.644490, -0.438870, -2862.825195, 2.651270,
1.473810, -1.168970, 0.084780, -0.660500, 1.255390, -1.212980, -0.905100, -4.001590, -4.246720, -1.094780,
-8.211660, 1.202080, 2.416470, 0.451380, 0.229210, -3.346490, 1.602530, 0.267170, 0.391470, 0.381070,
-0.204480, -0.418430, 0.494170, -1.039880, -0.527870, 0.698930, -0.317240, 0.034160, 0.334370, 0.038620,
-0.263690, -0.394380, -0.993600, 0.489250, 0.203130, 1.132540, -0.488440, 0.738860, 0.240350, -0.053820,
-0.905700, -0.081940, -0.112650, 0.260710, 2.331080, 0.578620, -0.322700, 0.603260, -1.044790, -0.013420,

0.500770, 0.464270, -0.519530, 0.266350, -6.631900, 1.265080, -2.180060, -0.267900, 3.015180, 1.638090,
-0.507740, 0.831930, -206.870529, -0.766150, 0.137890, -0.150910, -1.850800, -1.233430, 2.042660, -0.144630,
-1.165680, -1.036100, -1.836690, -2.427270, -2.352700, 0.563800, -0.086910, 0.646550, 1.113660, -0.119280,
-0.518050, 0.514240, 0.021840, 0.412590, 0.558750, -0.887120, -0.668820, 0.761160, 0.578630, 0.514540,
0.776280, 0.821500, 0.357190, -0.480290, 0.506680, 0.712910, 0.392900, -0.558610, -0.343130, 0.381180,
1.169460, -0.957030, 0.206960, -0.038710, -2.055020, 1.175280, 0.715240, -1.259250, -0.045380, 1.452540,

-0.110470, 3.121620, -0.961250, 0.688120, -1.493690, -0.293060, -1.470320, 0.320500, -1.233710, 1.227960,
0.296690, -0.186160, 0.861950, 0.087410, 1.668320, 0.420750, 0.572460, 1.531400, -1.079700, 0.363360,
6.608730, 0.207630, 2.930440, -1.033370, 1.184310, 0.013820, -0.169300, 0.688670, 1.328730, -0.124500,
-0.242820, 0.649380, 2.238400, 1.271760, 0.318440, 0.417290, 0.192760, -0.301540, -0.446520, 0.476040,
0.632580, -0.328690, -0.122290, -0.608650, -1.593820, 1.259700, 0.397040, -0.199190, 0.797710, 0.444970,
5.456630, -0.849390, 3.689760, -0.720860, 3.861350, 0.893640, -0.503870, 1.703480, -2.465630, -1.178290,

-79.832230, -0.189610, 0.305480, 0.119270, 4.093020, 1.225770, -0.896760, -0.460880, -1.682800, -4.155920,
3.851220, -2.377730, 1.179060, -0.263110, -0.136120, -0.086100, 1.288120, -4.129370, -2.263250, -0.626300,
1.782190, -0.247820, 0.870920, 0.864200, -0.928380, 0.561790, -7.047350, 0.373820, 0.950520, -0.894310,
0.066410, 0.688710, 0.673770, -0.529110, -0.923800, -0.606530, -0.421990, -0.224450, -0.853170, -0.418200,
-0.921150, -0.579570, -0.038600, 0.245180, 0.484760, 0.403960, -0.595020, 0.441980, -0.883220, -1.317090,
3.365400, 0.000040, 1.830410, -0.325640, 0.195650, 0.495350, 0.428640, -3.276880, -1.247560, 1.902380,

1.187820, 2.504450, 0.367990, -1.103710, -0.519450, 0.858370, -0.596690, -0.138450, -0.473270, -0.398870,
1.340570, 0.803150, 0.995310, -1.883410, -1.602780, 0.645060, -0.213360, 2.949760, -0.253080, -0.629310,
-0.483520, -0.608390, 0.421270, -0.729890, 0.313610, 0.015700, 1.166220, -0.626840, 1.560090, 0.038530,
-0.244580, -0.265330, 0.977240, -0.212280, -0.165210, 0.039880, 0.489520, -0.781930, -0.173410, -0.601300,
-0.844750, -1.158430, -0.108720, -0.162810, 0.207780, 2.220900, -0.134880, 0.406220, -0.359540, 1.233650,
-0.635620, -1.099660, -0.176510, 0.737900, -2.679760, -0.856890, 0.679600, 0.888640, -0.167160, -1.646450,

-0.291010, 0.957980, -0.563590, -0.717590, -0.757500, 0.850420, 1.276720, 0.536310, -0.222390, 1.075530,
1.751090, 0.160280, 1.666020, 0.450010, 0.804030, -1.108600, -1.088180, -17.657120, -0.071130, 0.284480,
4.200830, 0.943540, -0.252130, 0.013400, -0.633740, -1.197090, 0.441480, -0.284310, -0.274710, 0.713660,
0.056770, 0.603220, 0.583640, -0.573520, -0.024010, 0.516220, 0.036950, -0.006920, 0.220600, -0.152860,
0.305300, -0.833880, -0.880260, -0.781920, 0.548870, 0.211770, 0.109290, -0.282530, -0.223920, -0.806690,
-0.149200, 0.269980, 0.524810, 0.583070, 1.174840, 0.002890, -0.914870, 0.655250, 0.315550, 0.198620,

0.957370, 0.753530, 1.124830, -1.835860, -0.272720, 0.529510, -1.288240, 1.008080, -0.809240, -1.151630,
0.537370, -0.768160, 0.358830, 0.035310, -0.559060, 0.698160, -0.584060, -0.527940, 0.927890, -2.497050,
-4.069090, -0.368610, -1.296350, -0.057370, 5.791410, -1.548340, 0.096220, -1.849430, -0.196950, 0.141600,

-3.571320, 0.291880, 1.601030, -1.639950, 1.097810, -1.005320, 1.193250, -0.460000, -0.014540, 1.241740,
-0.405830, -0.577190, 0.606070, 0.533670, -0.080050, -0.232780, 0.246260, -0.396680, -1.776720, 0.677930,
-3.711300, -0.519330, -0.277700, 0.642210, -6.706840, 1.087500, -0.098270, -1.600050, -1.140210, 0.803730,

-0.344860, -0.687550, -1.543990, 1.554110, -0.019750, 0.193290, -0.836540, -0.876860, 0.799110, -1.272150,
0.259920, 0.691200, -0.984640, -0.925800, 0.353050, 0.016410, 0.585270, -0.291500, -0.729500, 1.807150,
4.153060, 0.470790, 0.169490, -0.391370, -2.955450, -0.825650, -0.967010, 1.572020, 0.595130, -1.024870,

0.085440, 0.834260, 0.676520, -0.471450, 0.754060, -0.758020, -0.935210, 0.861520, -0.966100, -0.908590,
0.110630, -0.272550, 0.349910, 0.187850, -1.147330, -0.260850, -0.675370, 0.211930, 1.387700, -0.946150,
-7.213870, -0.589700, -1.503230, -0.364610, 8.254060, -2.816780, 0.203130, -2.386660, -2.304450, 0.589320,

-1.962130, 0.991780, 0.845620, -0.975980, 1.303590, 0.859990, 0.665040, -0.746290, 0.264720, 1.297090,
0.161310, -0.140690, -0.862720, -0.675690, -0.594530, -0.154720, 0.590570, -0.646100, -2.760840, -0.749040,
-5.915290, -0.533050, 0.296470, 0.927330, -9.421820, 1.022460, -0.853880, -2.437650, -1.403790, 1.539610,

-0.151850, -1.180280, -0.923940, 0.857250, -0.999530, -0.287950, -0.380030, -0.753060, 0.056890, -0.983940,
-0.176440, -0.006710, 0.361850, 0.141930, 0.909420, 0.206040, 0.632180, -0.294260, -1.118520, 1.265680,
7.158030, 0.763680, -0.620490, -0.358650, -2.619520, -0.992410, 0.808360, 2.433520, 1.627040, -1.881640,

0.392310, 0.616860, -1.139490, -0.274030, 1.191240, -0.748130, -0.570520, 0.968110, -1.405870, -0.096440,
-0.744500, 0.013740, -0.521670, 0.104700, -0.658810, -2.257050, -0.820000, 0.968980, 1.004500, -1.020200,
-5.843290, -0.305680, -1.727230, -0.619790, 9.106030, -3.153610, 0.588320, -2.016600, 1.019400, 0.429220,

0.065240, 0.719210, -1.017030, 0.104430, 0.858430, -0.196360, 0.011750, -1.419050, 0.577320, 0.799000,
1.011170, -0.508200, 0.035760, -0.459050, -0.903870, -1.415270, 0.170210, -1.093240, -3.013130, 0.122910,
-5.780170, -0.440280, 1.189770, 1.149940, -9.434480, 1.705660, 0.033450, -0.923270, -0.521440, 2.078780,

-0.476570, -0.852010, 1.176040, 0.056950, -1.378540, 1.016110, 0.013740, -1.291920, 0.008210, -0.561880,
-0.979950, -0.233720, -0.382700, 0.610570, 0.591630, 1.790670, 0.367560, 0.175980, -0.676700, 1.111500,
6.171700, 0.520810, -1.362820, -0.726540, -3.479880, -1.415620, 0.023860, 1.584700, -0.406410, -2.321390,

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
      0.0, -0.107780, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.577390, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, 0.893530, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 174.412567, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.859820, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.429160, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.863030, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, 0.697500, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.841430, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.732430, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, -0.576740, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.069080, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.159540, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.435640, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.190080, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, -0.089670, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.190460, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, -0.259080, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.258920, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 145.972366, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.362490, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, 0.063440, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.208040, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, -0.659670, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.643260, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, 0.422570, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, -0.021870, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 417.091339, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.306310, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -0.796120, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.110180, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.667220, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, -0.004470, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.619330, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.572320, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.172900, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.764270, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.324470, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.537080, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, -0.916030, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.703780, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.423090, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, 1.006960, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.921870, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.051940, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, 0.520640, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, 0.236050, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, 1.020740, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.232970, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.445020, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.502700, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 1.106970, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -0.524100, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, 0.589050, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.339080, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.884530, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.128840, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, -0.139400, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.508810, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.537290, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.059530, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.016660, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, 0.974020, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.288270, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, -0.550950, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.438480, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.867560, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.768540, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.101020, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.59099, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.11985, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.19480, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
1.42857, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
1.21660, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.12665, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.78340, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
0.09477, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.00000, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
0.90219, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.02854, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.00102, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.01089, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.16526, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
0.03919, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.91348, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
1.14631, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.00844, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.00975, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
1.42857, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
0.00003, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
1.42857, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.00388, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.00963, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
0.01233, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.42784, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.00006, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
1.42857, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.10615, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
1.09619, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.97697, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
1.17332, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.42905, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.05130, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.09298, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
1.40910, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.00168, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.42386, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.02853, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.00000, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
1.42857, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
1.42857, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
1.22924, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.32075, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.09837, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
0.41994, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
1.35973, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
1.41894, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
0.39873, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.15275, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
0.00000, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.01358, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
0.00076, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
0.17547, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.02100, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.00244, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.32960, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
0.00023, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.00452, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.05580, 0.500000, 2,
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
