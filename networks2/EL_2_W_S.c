/*********************************************************
  EL_2+W.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:13:16 2004
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
0.289110, -0.386880, 1.023680, 0.043670, 1.183890, 0.607100, 0.321360, 0.221970, 1.432430, -0.982860,
-0.424690, -1.217940, -0.627400, -1.658980, -0.634760, -1.643470, -1.500510, 0.248260, 2.631460, 1.065700,
-0.148300, 0.662660, 0.819270, -0.633670, -1.682000, -1.232720, 0.661810, -1.290190, -1.677140, -0.868530,
-2.129050, 2.280200, 0.093280, -0.178080, -1.856620, -0.553590, -1.798310, -0.537660, -1.128960, 1.659870,
1.454780, -0.743050, -2.300770, -1.462790, 1.513230, 0.506970, -0.676930, 1.039640, -0.201620, 5.122100,
1.089030, 1.170020, -2.307920, -1.883050, 0.867500, 4.753940, 3.659280, 0.195340, 0.330090, -2.235520,
1.253720, -1.167760, 2.100380, 1.228550, -12.507480, -7.823090, 1.516580, 5.424230, 5.135600, 1.452820,
6.934990, 1.274700, -0.292650, -1.191290, -0.034830, -0.076270, -2.899290, 0.105500, -0.777390, 3.932280,
-0.874120, 0.147870, -7.922020, -3.524960, -0.095210, -2.304220, 5.754350, -0.888050, 3.250060, -2.711760,
-0.624160, -1.030480, -2.828220, -0.555890, 3.687960, 0.694660, 0.995930, -7.539680, -0.524410, 0.239290,
0.637210, 0.729430, -0.387700, -6.334830, 1.963720, -0.347080, 4.632690, 1.580300, -4.604920, -1.010540,
-0.845710, -0.549310, -0.816140, 0.115290, -2.590580, 0.207870, 0.523750, -0.034790, 1.946920, 0.475200,
-1.565130, -2.007660, -0.857660, 0.516770, -0.965320, -0.117750, -0.290990, -0.059140, 5.919560, 0.227830,
0.787380, -1.216230, 0.647150, -0.038310, -0.501150, -0.776020, -0.906210, 0.723110, 0.064910, -0.574580,

-1.207670, -0.063330, -0.339570, 0.841680, -0.093100, 0.233030, 0.999850, -0.292770, -0.512400, -0.571100,
0.784880, 0.711920, 0.327090, 1.524080, -0.565700, 2.215700, -0.786730, 0.390410, -0.315470, -0.655570,
0.102430, -2.005030, 1.998110, 1.020220, 1.036030, 0.269810, -0.928320, 1.032720, -0.471630, 2.018690,
0.927010, -0.659540, 0.363450, -1.917960, 0.179530, 0.653170, 0.037070, 0.611230, 3.537920, 0.439210,
-0.946490, 0.867510, -0.839500, 0.625920, -1.156050, -2.139960, 1.029920, 0.473920, 7.371580, 0.479210,
-0.104480, -5.354410, -0.408710, 1.124290, -1.561500, -0.772410, -1.706200, 0.362220, -0.171810, -1.438490,
1.577330, -1.563010, -0.356880, -5.764150, 0.682510, -0.136690, -0.875050, -0.406760, -0.419600, 2.667640,
-1.036970, -0.511480, -1.710590, 0.035050, 0.048860, -0.038060, -0.028890, 0.389810, 2.393170, -1.237000,
1.173740, -2.648060, 0.166290, -1.159300, -0.807530, -0.880230, 0.699350, 1.187910, 0.764000, 0.325840,
0.576720, 1.240820, 0.476160, 0.593540, 0.744140, -0.100060, 0.125460, 0.366470, 0.385770, 0.787250,
1.417710, 1.790630, -1.455970, 0.354840, -0.112960, -3.173890, 0.308060, -2.614570, -0.252940, -0.261960,
2.657960, 0.483870, 0.124870, 0.148020, -2.407220, -3.179040, 1.439260, -0.223970, -5.580440, 2.608710,
-26.350260, -1.362070, 1.356860, -1.369780, -1.437180, -0.544810, -1.002490, -1.110050, 2.509880, 0.030040,
-0.212570, -0.575720, -1.019500, -0.545730, 0.143950, 0.253550, 0.501110, -0.134470, 0.005330, 0.273290,

0.553920, 8.285000, 1.603090, -0.388260, 2.576290, 1.235320, -0.914500, 2.167210, -0.456460, 0.304990,
-6.822880, 1.239030, 0.461360, -0.729880, 6.048320, 0.401100, -4.776990, 0.949010, -0.229310, -16.782431,
-0.429820, -0.785810, 54.281509, -0.136180, -0.593140, -9.995250, -2.059340, 0.290370, 2.429690, -5.399560,
-0.762030, 8.641780, 0.209950, 0.326110, -8.100430, -1.644250, -0.896700, -12.981990, -3.973720, -0.043940,
18.720421, 0.411360, -1.425650, -6.144190, 1.825300, -0.301020, -8.006770, 8.841060, 0.024010, 5.531770,
2.963330, -1.338620, -3.866550, 0.595150, -0.722820, 6.566190, 1.114580, -0.831680, 3.780020, -0.594350,
0.206250, 6.204300, 0.906550, 0.574870, 7.886230, -3.144880, -0.586500, 0.770340, -0.491160, 0.725920,
-4.981030, -0.668450, -0.179440, 1.546870, 0.198090, 0.807720, -4.929880, 0.304910, -0.393360, 4.024740,
-1.075850, 0.543210, 3.410680, -0.095050, -0.250110, -14.697130, -0.853820, -0.151130, 6.653490, -0.147000,
-0.290210, 7.856220, -0.267290, 0.291420, -6.762030, 1.291170, -0.077070, 2.113590, -0.213620, 0.884080,
-2.383400, -4.591850, -4.858010, 2.200190, -0.362480, 4.539150, 1.973870, 0.939120, 0.679550, 0.571500,
19.379450, -1.827160, -0.241540, 0.488000, -16.698860, 0.686230, -0.730740, -0.369480, 452.084595, -8.008900,
0.985280, 0.285150, 0.668980, -0.347090, -0.465660, 0.245030, -2.062910, 5.548390, 1148.052368, 1.193940,
-0.671690, -0.838910, 0.541680, 0.460820, -1.267630, 0.350820, 0.586870, 0.195630, 1.017350, 0.662830,

174.685516, 173.626144, 174.907639, 173.919250, 174.165955, 174.559753, 174.149170, 173.313324, 175.145721, 174.893768,
173.342880, 174.680527, 174.430161, 174.478027, 174.672989, 174.079605, 502.377014, 174.279510, 174.319931, 175.023560,
174.459335, 175.087341, 173.586777, 174.620026, 174.680893, 501.371338, 174.735413, 174.277405, 175.036591, 174.185791,
174.404541, 173.679489, 174.032013, 174.267731, 174.967056, 174.687485, 173.892303, 173.293427, 173.853287, 175.028015,
173.481216, 174.152847, 174.182663, 174.410522, 502.390808, 174.623856, 174.016098, 174.120331, 174.411407, 174.955353,
501.625092, 174.429321, 173.785538, 501.994324, 174.099869, 174.329056, 501.366394, 175.162003, 173.575333, 500.622681,
174.285919, 174.285492, 501.447723, 173.264771, 173.876648, 501.642517, 175.007278, 174.496872, 501.478912, 174.419983,
174.639923, 175.063828, 173.590652, 174.799988, 501.327942, 173.959793, 173.841583, 174.727997, 175.118011, 173.809784,
173.863342, 173.257660, 174.368729, 173.432068, 173.763702, 173.255737, 174.136536, 174.497665, 175.040314, 173.393188,
173.550385, 174.791702, 173.377594, 174.343246, 173.265289, 175.107544, 174.593826, 173.621964, 174.606888, 174.436020,
174.240997, 174.907425, 174.408127, 174.473557, 500.575989, 501.310028, 502.369324, 173.373993, 174.161987, 173.748184,
173.645477, 173.671356, 175.003769, 174.838165, 173.568039, 175.149445, 174.500122, 175.171600, 501.858246, 173.631729,
59.692280, 173.426376, 174.029160, 174.896393, 174.830322, 173.348419, 173.421494, 501.905762, 173.985016, 173.611435,
174.172638, 502.265076, 173.270432, 173.392441, 500.962982, 173.990692, 175.117981, 175.052429, 173.966873, 173.654739,

-3.049490, -0.189090, -0.617720, 0.535630, -0.103930, -0.394960, -0.982730, -0.234040, -1.053250, -0.655330,
-1.188790, 0.066640, 0.217740, -2.924600, 0.454990, 0.144920, 0.002150, 0.524120, 0.479070, 2.244180,
-0.773610, 0.032670, -0.531730, -1.098430, -1.266960, -0.923710, 0.631010, 1.031340, -0.001480, 2.891830,
0.361270, -0.877830, -1.112500, 1.415910, 1.682990, -1.313730, -0.957360, -0.186500, -0.666530, -0.575050,
0.659540, 0.695670, 0.035440, 0.055720, -1.602680, -1.839960, -0.619250, -0.371590, 0.375930, -1.367820,
-1.008660, -0.078320, 1.799840, -0.520270, -1.151220, -0.779780, 1.144290, 0.513030, -1.054090, 3.661840,
2.475590, 4.176540, 0.766040, 1.865110, -0.455520, -1.272340, -0.143340, 1.780420, 2.120580, -0.254820,
0.010210, -1.829120, -0.140180, -0.584840, -1.667980, -0.439490, -0.304100, -2.133860, -3.409440, 0.037360,
-1.895760, 0.120400, -0.389120, -0.085680, 0.632810, 0.240760, -0.249980, -0.764240, 3.500660, 4.598480,
0.971580, -2.281770, -8.981610, -0.753370, -1.424360, -1.676000, 2.648370, -0.425660, -4.123070, 0.177180,
-1.383870, 3.129060, -2.539250, 2.162650, 2.043470, -15.898560, -1.342430, 2.939190, -3.924230, -9.451640,
-0.300370, -2.476340, 0.728620, 0.610190, 0.093900, 0.797290, 0.856890, 0.253360, 1.534940, 0.282450,
-5.899960, 0.823860, 1.056940, -2.069340, 0.021940, -0.728410, -0.564100, 1.146070, -2.272130, 0.164390,
0.659980, -0.705700, -0.689240, 0.819010, 0.209110, 0.980180, -0.018550, -0.648760, -0.034640, 0.916390,

0.537870, -0.425230, 0.497900, 0.524400, -0.032300, 0.168500, 0.269390, 0.299480, 0.429660, -1.061220,
0.089350, -1.433290, 0.545140, -0.720100, 0.495790, 0.356480, 0.280990, 0.716470, -0.582960, -0.453660,
-1.578520, 0.375110, -0.276100, 0.128360, -1.078200, -0.005530, -1.074130, 0.633850, -0.556880, 1.204820,
0.166880, -1.374000, -0.224220, -0.428110, 1.056430, 0.327590, 1.224070, 0.410860, 2.204830, 0.685100,
-0.684230, 0.118250, -0.168860, 1.012830, -2.758050, -0.507200, 0.285130, -1.098570, -0.180310, -0.349210,
2.023400, 0.058440, 0.177390, -3.232840, -0.995180, -0.582390, -2.696960, 0.599630, 0.958660, -2.197120,
0.778390, -0.220610, -0.354810, 0.730860, 0.977520, -4.121170, -0.905830, -0.208090, -0.763860, -0.383110,
-1.345590, 0.281100, -0.809860, -0.272620, -3.123640, -0.021510, -0.110120, -1.552080, 0.245780, 0.404290,
0.071950, 0.028930, -0.128600, -0.795270, 0.386710, -0.199180, -1.034870, -0.345790, 0.105310, 0.505740,
0.029150, -0.964810, 0.233090, -0.562970, -0.395170, -0.732560, -0.563740, -0.635380, -0.411290, 0.646510,
0.589620, 2.141890, 2.683740, -1.230060, -0.821570, -1.843830, -2.397920, -6.669750, -0.457460, -0.702530,
-1.295040, 1.097700, 0.438060, 0.447680, -1.214260, -0.405460, -0.331180, 0.029990, 1.632510, 0.226930,
0.746680, 0.052400, 0.571440, 0.921910, 0.522130, 0.764860, -0.557630, -2.096160, -0.002790, -0.239370,
0.060030, 0.258530, 0.628700, 1.324590, -0.373440, -0.638570, 0.530770, -0.357480, -0.132580, 0.361000,

1.560570, -0.457890, 0.418970, 0.153440, 0.046790, -0.236480, 0.307820, 1.458600, 0.438930, -0.699400,
0.587120, 1.253290, 0.932320, -0.261130, -1.045220, -0.367370, -1.193860, -0.399960, -0.889260, -0.682360,
-0.572550, -0.652940, -2.381940, 0.707270, 0.659080, -1.150440, -0.627890, 1.052780, 0.176530, -1.136020,
-1.019920, -3.433820, 0.814310, 0.346610, 2.093480, -0.205360, 1.182310, 0.905740, 0.127320, -0.068520,
-1.493340, 0.346590, 0.498900, -0.986010, -0.784660, 0.284020, -0.086970, 0.891360, 0.312280, -0.409540,
2.177520, -0.607030, -0.330380, -0.033990, 1.795910, -2.182280, -0.818030, -0.575810, -1.260860, 1.026500,
-1.591710, 1.832280, -1.054290, 0.607450, -3.145230, 0.404080, -0.262030, -1.246550, -0.378430, -1.454090,
1.788480, -0.723580, 0.455660, -0.674880, 1.366360, 0.717050, 0.475240, 0.451660, -0.644850, 0.304260,
0.492500, 0.749510, -2.750740, 0.233500, -0.015660, -0.201130, 0.048230, -1.685790, 0.276640, 0.450560,
1.967700, -0.809130, -0.025450, 1.405850, 0.195470, 0.064220, -0.122730, 1.490460, -0.050860, -0.948000,
-1.054630, -1.965290, -0.964950, 6.179850, 2.311700, 1.400690, -2.337490, -3.284520, -2.260700, -0.752100,
0.867910, -0.113720, 0.838110, 0.411380, 0.574140, -0.324120, 0.031310, -0.022570, 4.648530, 0.733530,
0.789280, -0.028340, -0.311540, 0.084000, 0.186850, -1.178880, 0.443910, 0.493960, 2.229520, -0.963840,
-0.409570, 0.001060, 0.208750, 0.841580, -0.115040, -0.597570, -0.071000, 0.575070, -0.476350, 1.584090,

0.118500, -0.591620, 0.514440, 0.320500, 0.168910, -0.557760, -0.490160, -0.103070, -1.323460, 0.171660,
0.589210, -0.568400, 1.195890, 0.239170, 1.933810, 0.018190, 1.330030, -0.316820, 0.663230, 0.144430,
-0.046060, -1.360350, -4.935370, 0.022050, 1.100800, 0.507590, -0.976970, -3.344400, -1.118110, -0.049750,
-0.129070, 0.350270, -0.001860, 1.438580, -0.638210, -2.773510, -0.487150, -0.296590, -1.346430, 3.053720,
-0.466380, 0.630630, -1.694050, 0.993700, -0.487080, 0.314870, -4.485900, -0.957950, 2.011850, -0.952630,
-0.431870, -2.105850, -0.307140, 0.504190, 0.501900, -1.357850, -0.165020, 3.886770, 0.610170, 0.239950,
-2.495090, 0.946410, 1.547490, -0.269850, -0.884810, 1.306940, 1.097910, 1.087990, 0.952070, 0.608270,
-0.537420, 1.541980, 0.653870, 0.963040, -0.480180, -0.024450, -0.626060, 1.078430, -0.848790, 0.174820,
-0.317600, 0.608960, 1.072850, -0.220780, 0.950750, 1.216540, 0.769530, 0.372560, -1.468480, -0.498030,
-0.856950, 1.214750, 0.939940, -0.574300, -0.792430, -0.513220, 0.318840, -0.051850, 0.720430, -0.293600,
-1.299950, -0.226990, 3.563050, 2.893920, -0.559580, -2.722380, 2.024650, -0.627010, 0.835150, -1.844480,
-37.107681, -0.634880, 0.514200, -0.396710, 2.396150, 7.814840, -2.748260, 2.083500, 6.567440, 1.771650,
-19.979340, -2.188600, 2.842970, -0.347970, 0.687350, 0.088120, -1.235020, -4.151690, -0.779350, -0.134060,
-0.227750, -0.038470, 1.009060, 0.092640, 0.361330, 0.065950, 0.216730, -0.325870, -2.437930, 1.125990,

-8.248550, -0.409320, 0.349500, 9.685780, -0.944280, 0.707000, -2.705420, -1.053110, 0.722400, -1.196120,
-1.515530, -1.694970, -3.144540, 0.759600, 0.445560, -0.316650, -1.003120, -0.905750, -5.814720, -0.718460,
-2.805400, 0.867300, 0.595410, 0.893750, 2.670050, 0.121710, 2.894640, -2.892450, -0.594850, -2.859380,
6.153240, 0.420610, -0.670980, -6.847560, 0.181640, 1.263450, -3.358040, 3.126770, -0.333450, 3.085680,
1.016000, 1.287010, -8.349310, 0.112380, 0.729770, -12.809930, -0.020040, -0.305080, 6.454120, -0.102350,
-0.649680, 3.723640, 2.411150, 0.999950, -23.277109, 1.078380, -0.526620, 12.947940, 0.403630, 0.231750,
-7.906220, 0.877580, -0.003030, -15.121830, 0.834490, 0.612230, 8.322630, -0.868190, 0.732780, -0.275960,
-0.230950, 0.990590, -10.813790, 0.822220, 0.347340, 1.816230, 0.198320, 1.027770, 0.855480, 4.192260,
-0.227270, -2.510000, -0.314410, 0.703730, 0.888620, -3.881980, -0.250670, -0.884960, 3.090940, 0.546950,
-2.705330, 0.215140, 0.541520, 0.112470, -2.886030, -0.797710, 1.116340, 0.301190, -0.150560, -0.403060,
0.745720, 0.215810, -3.639270, -1.241870, -0.017160, 0.516440, 3.837380, 1.854400, 2.073540, 2.922500,
9.304830, -1.502510, -1.131170, 0.689190, -4.016560, 1.649550, 5.352680, -0.109710, -4.384100, 0.780140,
5.711980, -2.618520, -0.065120, 1.185720, 0.298410, -0.098640, -1.117390, -0.808210, -11.585340, -0.469800,
1.471540, 0.249430, -0.542630, -1.950350, -1.979590, -0.998410, 0.291420, -0.767260, 1.505950, -1.120720,

0.258400, -0.742730, -1.413830, 0.579660, 0.541880, -0.042520, -0.441060, -0.910590, 0.523990, -0.883010,
0.184420, -0.353800, -0.301100, -0.779110, 0.063180, -1.146740, 1.036180, -0.490090, -0.262880, -0.523440,
-0.875680, 0.405170, 0.823870, -0.263160, 0.418120, -1.047030, -0.865230, 0.683650, -1.076020, -0.645880,
0.014120, -0.904040, -0.224450, -0.427130, 0.894900, -0.300490, -0.759590, 0.609970, 0.458830, 0.638310,
-1.434170, -1.467640, 0.783620, 0.480370, 2.545160, 1.693340, -0.588820, -0.275360, -0.953380, 0.716900,
-0.238050, -1.866650, 1.030890, -1.050180, -0.062300, 0.209510, -0.869720, 0.041370, 0.139090, -1.155190,
-0.170080, -2.626330, -0.749380, -0.585200, -0.287630, -0.539730, -0.548110, -0.303970, 0.756200, -0.042520,
0.705380, 1.696580, -0.436410, 1.118410, -3.320380, -0.082070, 0.769390, -0.341930, -1.276330, -0.772580,
-0.934060, -1.097780, 0.594970, 0.894640, 0.382760, -0.133180, 0.721220, 1.986030, -0.313270, 1.330090,
1.572470, -0.515670, -0.495360, -0.195290, 0.875550, -0.649180, -0.640210, 0.668760, 0.938390, 2.832660,
-2.608660, -5.204970, 3.158320, 6.910430, -12.338750, 11.440900, -19.342871, 7.430940, -0.980240, 0.816210,
-12.453990, -0.014850, 0.018150, -0.050610, -0.057300, -1.560240, 1.015500, -0.277010, -3.150420, -0.480740,
0.761200, 1.223970, -0.680240, 0.007550, -0.574190, -0.462420, -0.021300, -0.006140, 0.427290, 0.034400,
0.131810, -0.299720, 0.031850, 0.230020, 0.806050, -0.284030, 0.681350, 0.489300, 0.159520, 0.450210,

-1.759170, -0.215630, -0.380310, -0.790760, -0.763760, -0.696590, -0.856650, -0.887780, -1.085700, -0.003440,
-0.510290, -0.643460, 0.244030, -0.588910, 0.372120, -0.634020, -0.184250, 0.514550, 0.347620, 0.043330,
-0.211290, 1.659170, -0.842790, 0.453020, -0.508360, 0.376500, 0.604460, 0.433510, 0.394530, -1.659730,
-0.598950, 0.055620, 0.499860, -0.030490, 1.005190, 0.565680, -0.125650, 0.882930, 0.365160, -2.032290,
-1.159330, 0.349480, -1.115170, -0.888280, -1.796630, -2.468680, -0.845850, 0.001550, 1.393740, 0.113680,
0.225810, -0.108370, 1.065100, -0.494050, -0.159850, 2.236590, 0.103070, -0.520540, -0.832550, 4.409250,
-0.765790, -0.866940, -5.526970, 0.720320, -0.783470, 0.250510, 0.922490, -0.177260, 3.121510, 0.696160,
2.662980, -0.205420, 1.977750, -2.544960, -1.726150, -1.163860, 0.611730, 5.307150, -0.712300, 1.454990,
-1.475370, -0.557590, -0.573170, -3.886740, -0.180990, -1.147040, -0.861460, -1.082620, 2.094540, 0.384400,
-0.076980, -4.246260, 0.622650, -0.367250, 2.282630, -0.236470, 1.528690, -1.588670, -0.131480, -1.843600,
-1.460650, 0.057690, 0.870670, -2.066090, -2.521540, 9.466490, 0.191590, -9.104450, 0.333120, 4.201860,
3.703560, 0.678100, -1.137740, 0.245680, 0.632580, 0.600750, -1.632160, 0.210980, -4.383900, -1.118420,
1.149400, 0.725210, -1.163810, -0.295850, 1.195070, -0.453710, -0.478920, -0.081770, -0.887310, -0.901170,
0.308560, 1.421040, -0.684880, -1.195080, 0.329170, 0.742430, -0.628540, -0.515960, -0.001270, 0.939150,

-1.600480, -0.995910, -0.105100, -0.244680, 0.144070, -1.028690, -0.265050, 0.568620, -0.800670, 0.720240,
0.245250, 0.758080, -1.180300, -1.944330, -0.168950, -0.625930, 0.645800, -0.106160, -0.587320, -0.073520,
0.655250, 0.091440, -0.678760, 0.866490, -0.405900, 0.529030, 0.636950, -0.945010, -1.488740, 0.025490,
0.263250, 2.460160, -0.382670, -1.212780, -2.617490, 1.132020, -1.155130, 0.126020, -0.753720, 0.762180,
-1.018220, 0.049390, -0.972430, 0.591090, 0.641680, 0.215780, -0.769360, 4.922800, 2.162240, 1.770820,
3.393370, 0.386640, -0.261460, -1.830630, 0.560860, -0.699630, 3.321130, -0.578670, -0.975310, -0.314400,
0.463450, 0.928280, -1.014960, 0.733540, 0.949620, -2.464490, -2.468970, -0.561220, -0.663250, 0.250890,
-0.681790, -0.383900, 0.320000, -0.741890, -1.269650, -0.197420, 0.234160, -0.775950, 0.203930, -1.892660,
-0.485500, -0.320840, -0.971060, 0.188060, 0.691320, -1.151570, -0.201170, -1.822910, -0.385180, 0.296080,
0.321260, 0.746200, 2.116220, 0.369250, 1.091420, -0.681980, -0.935860, -2.094060, -0.922420, 2.434640,
-0.970520, -0.835940, -2.319450, 0.089460, 0.760960, 3.635730, -0.550040, 0.048020, -3.585950, -0.534390,
-0.994680, -1.772110, 0.831910, 0.498520, 0.298030, 0.257240, 0.305410, 0.104700, -3.967750, 1.248670,
4.654850, -3.259840, 1.675310, 0.646870, 0.626680, 0.883080, -0.791750, -2.182400, 2.297960, 0.127860,
0.412160, -1.091910, 0.244520, 0.093540, 0.281730, -0.326210, -0.990230, -0.248590, -0.253390, -0.557000,

-0.677230, -0.072630, -0.189710, 0.749870, 0.761750, -0.017940, 0.597780, 0.723330, -0.209220, -0.078840,
-0.074100, 0.070330, 0.605110, 1.271530, 0.783430, 0.618960, 0.802760, 0.808030, -0.215560, -0.204480,
-0.393270, 0.590030, 0.591840, 0.143150, -0.882890, -0.974800, -0.265900, 0.036110, 0.571580, -0.434700,
0.046080, 0.063350, -0.508720, -0.148690, -1.059350, 0.436550, 0.899480, -0.502400, 0.565550, 0.499950,
-0.612530, 0.178990, 0.447250, -0.015980, -1.297870, 1.128970, -2.678980, -0.465270, 0.810400, -0.219550,
-0.667810, -2.057940, 0.264560, -0.083660, 0.177010, -0.699050, -1.320900, -0.690560, 1.082070, 0.248710,
-2.276540, -0.345680, -0.769770, -1.278550, -1.264620, -0.456750, 0.848660, 0.375400, -0.623690, -0.979730,
0.035010, -0.144610, -0.853760, -0.011790, -0.580250, 0.704880, -0.299370, 1.161870, -0.689200, 0.490360,
0.056260, -1.368970, 1.002880, 0.117840, 0.848600, 0.250930, 0.561340, -1.773620, -1.122660, -0.408320,
-0.128160, 0.137130, 0.405100, -0.499540, -1.304080, -1.200070, 0.129650, 0.145880, 0.163270, -0.371390,
-0.983610, -0.482930, -0.041590, -0.642750, 0.655410, -0.616510, 0.443600, 2.428000, 2.987720, -0.581470,
-6.636030, 1.409130, -0.707700, 0.484790, 1.893990, 1.778180, 0.212860, 0.470880, 0.789160, 0.224230,
2.826510, 0.608210, -0.405500, -0.120730, 0.419560, 0.431940, 0.407940, 0.732270, 0.468510, -0.254460,
-0.069610, 0.254670, -0.344340, -0.479680, 0.500700, 0.199150, 0.619190, -0.305970, 0.028940, -0.439750,

-0.091740, 0.274670, -0.327000, -0.198560, -0.763060, 0.278150, 0.423690, 1.427250, -0.433240, 0.308570,
-0.166570, 1.325530, 0.015760, 0.191810, -0.606250, 0.193040, -0.247680, -0.225100, -0.494640, 0.416300,
1.607660, 0.870340, -3.409860, 0.555210, -0.113830, -0.590710, -0.619800, -0.590080, 2.671640, 0.064000,
0.656680, -1.061580, 0.949940, 0.957200, -2.737790, 0.205600, -0.153240, 2.382870, 0.464900, 0.582680,
2.079120, -0.612200, 0.650060, -3.234410, 0.441510, -0.711910, -1.935670, -0.427120, -0.720710, -4.077070,
-0.174340, 0.646160, -1.397000, 0.240320, 0.804080, -1.679030, -0.324230, 0.350460, -0.073440, 0.888030,
-0.929080, 0.821440, -0.728880, 0.704910, -3.635830, 2.779930, -1.762970, -0.112120, 0.481500, 0.266240,
0.565160, -0.796110, -0.608420, -0.925040, 1.063450, -0.535930, 1.100550, 1.076060, 0.972180, -0.216320,
0.515820, -0.299660, 2.771120, -0.105470, 0.256780, 0.520570, -0.048180, 0.484040, -1.337240, -0.439750,
-1.009590, -0.790800, 0.589840, -0.533790, -0.771350, -0.992550, 0.553210, -0.306730, -0.099970, 0.132090,
-2.001460, -2.269420, -0.056560, -3.049150, 2.530990, 3.381950, 3.033120, -2.732550, -0.285740, -2.296500,
-10.542790, -0.034100, 0.419800, 0.451920, 1.307060, -1.701120, -0.613050, 0.541410, -2.330000, 0.533530,
9.129110, -1.009410, -0.001170, 0.337980, 0.959110, -0.924740, -0.451880, -0.941490, 0.748080, -0.139910,
0.659790, 0.419840, -0.947840, -0.258890, -0.217750, 0.332240, -0.355690, 0.430040, -0.633600, -0.327610,

0.290400, -0.647980, -1.292570, -0.534230, 1.187320, 0.716600, -1.129450, 0.322150, -0.351100, 0.744220,
-0.430980, -0.346210, 0.324700, 0.031370, 0.238310, -0.356410, 0.400170, 0.461220, -0.294680, -0.514240,
0.109430, 1.015830, 0.114630, -0.095240, 0.960800, -0.409500, 0.582230, -1.783890, 0.738110, -0.099010,
-0.019280, 0.111660, 0.655080, 2.737150, -1.239070, -1.047700, -2.824640, 0.531850, -0.109460, -1.713000,
-0.989740, 1.096710, 2.586130, -0.509710, -0.914200, -3.058730, 1.188420, -0.981360, 3.327000, -0.281410,
3.146270, 2.149070, 0.799750, 0.824410, -0.326640, -0.662350, -1.021540, 1.709160, -0.881510, 0.176330,
-2.334600, 0.505570, -1.117040, 11.581620, -0.450710, -2.277670, -1.244480, -0.671210, -0.764590, -0.353750,
-0.943890, 0.033300, 2.583950, -2.351890, -0.336850, -2.188440, -0.467870, -0.548110, -0.054500, 2.236940,
-0.654260, 0.530270, -1.851030, 0.273740, -0.266260, -0.903020, -0.680450, 0.828210, 0.907790, 0.742310,
-2.410900, 0.325920, -0.514830, -0.378430, -0.143420, -0.593090, 0.911460, -1.054170, 0.980350, -0.793920,
1.497710, 1.008950, 0.516980, -0.089540, 2.115630, 2.248600, 2.660900, -2.491430, 1.095220, -1.473650,
-27.652679, 1.244420, 0.014750, 0.548130, 322.288605, 3.520850, 0.118950, 0.742700, -0.036660, 0.267640,
-12.152270, 0.018370, 0.559210, 0.290090, -0.147660, -0.324690, -0.474570, -1.467150, -1.794860, 0.955790,
-0.727840, 1.042600, -0.911710, -0.838100, 0.142020, -0.820150, 0.361300, -0.905830, 0.321230, 1.240920,

250.969635, 721.720032, 249.945740, 251.385468, 721.255310, 250.817520, 250.712799, 250.250443, 251.047165, 250.860748,
722.053040, 250.376709, 251.047592, 249.833893, 251.415878, 250.923752, 250.290894, 720.842590, 251.103088, 249.660309,
250.720779, 249.800674, 251.260681, 721.070984, 250.881470, 251.539581, 721.968262, 250.266190, 251.335220, 722.517090,
251.334702, 251.638000, 721.572998, 251.051804, 249.686584, 722.726990, 251.120911, 250.880188, 722.477173, 249.993301,
251.112091, 722.745972, 249.928497, 249.902161, 722.349854, 250.671295, 250.493683, 722.241150, 249.673706, 251.323914,
721.107117, 249.639633, 250.856339, 720.853394, 249.742142, 250.670410, 720.994507, 249.460739, 250.274200, 722.312378,
251.229965, 250.490738, 722.526672, 251.204941, 251.101532, 722.758606, 251.135468, 251.478561, 720.822754, 250.813904,
722.662415, 250.476151, 249.471771, 249.972031, 721.693848, 249.589798, 722.592590, 250.596146, 249.549484, 722.637756,
250.373199, 249.611496, 721.604919, 250.084976, 251.233109, 720.901855, 250.223465, 249.933792, 721.054688, 251.082642,
249.909836, 721.360291, 251.121521, 251.044388, 722.577698, 250.696442, 251.006088, 720.813721, 251.224075, 250.656570,
250.469238, 249.651474, 250.165817, 250.087265, 251.089630, 251.013794, 250.139053, 251.224335, 249.861755, 251.258942,
722.715393, 86.333107, 251.142746, 251.165146, -0.563190, 250.420044, 0.700670, 722.463745, 250.484833, 85.900017,
87.485229, 250.286636, 250.475327, 0.641820, -0.484240, 249.668915, 721.487122, 87.346970, 251.140900, 250.689911,
721.082947, 0.443140, 250.037109, 0.967190, 250.354782, 722.085449, 249.898682, 249.993591, 1.128020, 86.741959,

-0.228150, 1.764020, -0.067360, -0.361020, 0.214440, 0.649790, 1.689570, 0.225360, 0.461060, 0.938200,
-0.433550, -0.200170, 0.273650, 0.250580, -1.189470, 0.945300, 0.291350, 0.860470, -1.754620, 0.946320,
-1.540750, -1.053910, -0.546950, 0.220340, 0.496670, -0.700360, -1.604290, -2.653830, -0.437320, -2.116070,
0.973320, 0.138420, 0.139380, -0.772120, -0.694100, 3.928620, -1.298300, -0.951380, 2.643910, 0.222950,
-0.707010, 0.395920, 2.189630, -1.187870, 0.933810, -3.755200, 0.380040, 6.065290, 0.100170, -0.112770,
1.126410, -1.091920, -0.978900, 0.905460, 0.090600, -0.024940, -1.993100, -0.060460, -0.504810, -0.164850,
-0.557080, 0.137330, 0.276490, -2.440640, 0.651780, -1.977890, -0.421510, 0.345360, -0.666400, 0.316750,
0.326590, 0.191110, -0.056890, -0.614430, -1.147030, 0.824820, 1.357640, -0.781170, 0.218430, 0.110470,
0.556710, 0.061840, -0.511430, -0.272020, 0.131910, 1.113730, 0.641750, -1.016670, 0.434840, -0.432130,
-0.700390, -0.555080, 1.339090, 0.721780, 0.914200, -0.087950, 2.022780, 0.434150, 0.863240, 0.019290,
1.180140, 2.069640, 1.270210, 0.760050, 2.144060, 0.897310, -2.923860, 0.597850, 3.777240, -0.429480,
27.202250, -0.133630, 0.130470, -0.872460, 1.084630, 0.477420, -1.871160, -0.622380, 0.008180, -1.068870,
-6.227230, 0.977460, -0.341470, -0.765800, 0.483740, 0.525450, 0.641660, 0.064260, -1.208930, -0.769910,
-0.204230, -1.008160, -0.036980, -0.461270, 0.191300, 0.470860, -0.016660, 0.580710, 0.373730, 0.558770,

-0.933320, 0.652030, 0.748420, -1.153400, -2.498850, -0.363860, -0.538190, -0.751430, -0.178860, 0.643510,
1.151070, -1.092400, 0.788320, -0.106520, -0.537130, -0.565680, 0.107450, 0.561090, -0.601550, 0.053310,
-1.552260, -0.122350, -1.025910, 0.246120, 0.221500, 0.626610, 0.730340, -0.630360, 1.182740, -0.700980,
-0.635020, 0.309890, -0.081840, -0.594860, 0.154720, -0.371500, 0.343440, 0.876100, 0.187940, -0.339690,
-0.813990, -1.118060, -0.651010, -0.435750, -0.669470, 0.502930, 0.091860, -0.639290, 0.190490, -1.016550,
0.930170, 0.958510, 3.603300, 1.489310, -0.245120, -0.751260, 2.668560, -0.833530, -0.245950, 0.764840,
1.038600, 0.951150, -0.164520, 2.231320, -0.852680, 0.626730, -0.213240, -2.779920, -0.476670, -0.011820,
-0.405720, 0.322740, -0.146560, -1.280800, -0.713710, -1.147280, -0.703890, -0.467870, 0.319030, 0.791300,
-0.078960, 0.200540, -0.013770, 0.478940, 0.106500, -0.120430, -0.468820, -1.478680, -0.732840, -0.692880,
0.443490, -1.304470, 0.395110, -0.653130, 0.450540, 0.443780, 0.132920, -0.188070, 0.102580, -0.880830,
1.633940, 0.754390, -2.179230, -2.375180, 0.311390, 0.655410, 3.176920, -1.144960, 0.176190, -0.060000,
0.994460, 1.508860, -0.883810, 0.598740, 2.094050, 1.154380, -0.416390, 0.881650, 3.460050, -0.186290,
-14.865260, 0.320230, 0.670730, 0.655650, 0.486580, 0.831410, -0.824850, 0.199230, -21.035950, -0.394240,
-0.017620, -0.739230, 0.674310, -0.991090, -0.093530, -0.748510, -0.287920, 0.601260, -0.653770, -0.404360,

-1.726010, 0.368900, -0.732250, -2.597080, -0.834080, 0.730000, 0.601020, -0.611960, -0.289690, -0.246370,
-2.276360, -0.942500, 2.487760, 1.000370, -0.923690, 0.070490, -1.015650, 1.769370, -0.292820, -0.105520,
0.381150, -0.398670, -0.446340, -0.001210, -0.483430, 0.386070, 0.225170, 0.121370, -0.439910, -1.474560,
-0.358610, -0.420980, 0.492930, -0.235830, 0.395510, 0.284330, 0.486440, 0.803830, -0.918800, 0.884530,
-1.678980, -0.035060, -3.136260, 0.059680, -0.933690, 0.144370, 0.147110, -0.567500, 1.201750, -0.437980,
1.019600, -1.417340, 1.153250, -1.244490, 0.182320, 0.973880, 3.739440, 3.007710, 0.281050, 0.520380,
-0.590790, -0.761390, -1.740090, -1.712710, -0.771460, -5.841070, 0.923520, 0.428770, 2.891370, -0.405560,
0.889830, -4.064340, -11.876760, 0.165660, 1.566510, 19.124201, 0.744370, -0.873830, -8.463840, -0.014390,
-1.064490, -0.543570, -0.453290, -3.668590, 11.757850, 0.968550, -1.046410, -5.780540, 0.364890, -1.384740,
-53.154541, 0.180980, 2.204660, -1.284750, -0.097050, -1.180360, 3.718190, 0.292100, 1.193580, 0.218380,
1.016260, 0.511040, -1.990880, -4.952740, 2.429790, -5.005670, 7.245070, -0.527940, 1.313880, 4.477890,
-16.894960, -0.966790, -0.655050, -0.938900, -2.709840, 0.302570, -1.243390, 0.392390, 1.718130, 1.092530,
-13.858720, -0.423400, -0.594170, 1.112830, 0.288530, 0.692070, 0.504450, 0.849590, 0.975590, 0.346300,
0.472670, 0.888650, 0.411720, 0.110890, -0.611620, 0.446380, -0.150260, -0.862920, 0.794820, -0.508030,

174.407455, 61.427719, 60.429779, 173.332687, 60.505192, 61.387199, 175.056000, 59.578159, 59.916210, 174.446091,
60.208260, 60.785709, 174.775879, 60.792099, 59.898430, 174.432205, 60.615849, 59.612011, 173.663605, 60.677540,
61.306820, 174.932693, 61.191330, 60.684830, 174.946304, 60.432270, 60.295952, 173.331421, 60.661949, 61.303921,
174.526672, 60.339668, 61.195648, 173.286331, 61.266842, 61.131569, 174.873154, 59.971161, 60.923489, 174.268921,
61.132511, 60.260220, 174.411209, 61.273819, 60.794922, 173.444000, 60.939571, 60.554070, 174.897736, 61.269562,
60.303669, 174.123825, 60.186958, 60.834129, 174.460312, 60.570530, 60.437569, 174.107178, 61.247219, 60.049671,
174.834473, 61.244438, 60.147751, 173.678726, 61.272202, 60.784271, 173.798904, 60.478321, 60.778690, 174.636765,
59.872822, 61.389622, 174.089355, 61.303410, 61.287251, 174.739395, 61.273281, 60.567570, 174.480316, 61.404251,
60.949982, 174.210510, 60.892391, 61.419659, 173.808441, 61.358650, 60.356571, 173.403061, 60.960480, 175.103561,
174.674469, 60.642052, 60.873379, 174.880417, 60.672581, 174.054947, 173.532608, 61.094158, 173.613251, 174.311569,
174.009644, 59.583660, 59.478809, 173.584961, 60.203510, 59.876541, 173.431412, 175.124802, 174.743805, 173.684631,
175.060425, 61.400299, 173.407410, 174.624268, 173.495178, 175.164230, 174.568878, 174.070358, 60.239479, 60.240150,
175.154999, 59.947430, 173.919067, 173.994797, 174.501251, 61.181648, 174.225098, 174.235733, 60.905979, 174.893845,
174.723526, 502.125549, 174.040512, 174.873505, 61.215691, 60.666550, 175.073486, 174.715897, 174.443207, 175.121475,

-0.162500, 0.794480, -0.945090, -1.316360, 0.379220, 0.504980, 0.618310, 0.746860, 0.379710, 0.146460,
-0.223530, -0.331050, 0.679170, 0.390760, -0.574660, -0.118470, -2.307430, -0.305110, 0.721670, -0.993850,
0.468450, -0.519230, 3.513820, -0.211960, 0.670000, -0.009550, 0.957230, -0.174350, -1.789500, -0.011650,
-0.573270, 2.218340, 0.373280, -0.502970, -3.240110, 0.089010, -0.700260, -0.330650, -0.725370, -0.811210,
-0.893400, 0.213690, 1.156440, -0.615580, 0.531240, -0.579230, 0.126890, 0.705460, 1.281320, 1.653720,
-2.721320, 0.093510, -2.920610, 1.179370, 0.404220, 2.146230, -0.325850, 0.003150, -5.180940, 0.268990,
-0.289240, -1.694720, 0.936750, -0.218750, 1.859610, 0.315740, 0.985270, 0.666940, -0.087330, 0.742650,
-0.510260, 0.950410, 0.159940, -3.350510, 0.501390, -0.840080, 0.702550, -0.318430, -0.471510, -0.022450,
-0.626130, 2.271460, -1.352640, 0.925260, -0.139400, 1.276730, -0.485790, -0.052200, 0.767440, 0.802870,
0.120460, -2.382930, -0.389190, -0.833390, 0.784080, -0.663090, 0.394510, -0.543360, 0.058370, -0.356350,
-0.406840, -0.768820, -1.242250, 2.073200, 5.791930, 3.333730, -1.514840, 1.004760, 1.460970, -1.354530,
3.022610, 0.030960, 0.481620, -0.985800, -3.143870, 1.388760, 0.502030, 0.292890, 4.724950, -0.518150,
-2.598060, 0.077270, -0.162670, -0.034170, -0.401490, -0.620600, -0.108330, -0.440510, 1.433920, 0.296220,
-0.286340, 0.879600, 0.470510, 0.040690, 0.446620, -0.832490, -0.948830, 0.567520, -0.091290, -0.770270,

-0.641380, -0.037370, -0.347180, 1.357900, 0.904740, 0.706850, 0.596770, -0.071740, 0.393100, 0.478720,
-0.488620, 0.482590, 0.236240, 0.421920, 0.259480, 1.002950, -0.463550, -0.427490, 0.004670, 0.458320,
0.552500, 1.058190, -0.891480, 0.308120, 0.496100, 0.121970, -0.148430, -0.773320, -0.069300, 0.061590,
0.000500, 1.097970, 0.596150, 1.583430, -0.178280, -0.821470, -0.979500, 0.678220, 0.829410, 2.033170,
-0.804250, 0.252400, -1.557570, -0.872990, -1.389100, 0.263760, 0.506850, 0.082350, -0.766560, 0.150490,
0.682220, 2.118480, 0.241760, -1.272970, 4.680080, -0.282580, 0.179550, -1.638450, 0.182860, -0.441330,
-0.640430, -0.865240, -0.870890, 4.262990, 1.028060, -0.737460, -5.847650, -0.208390, -0.765160, 2.368180,
-1.706290, -0.456990, -0.722600, -0.769420, -0.585920, -1.808070, 0.864430, -0.770360, 0.872690, -0.338470,
0.900640, -0.436500, -0.926890, 0.362240, 0.192180, 0.517920, 0.654490, 0.103000, -0.316970, -0.486760,
-0.074440, -0.028510, -0.643570, 0.535660, 1.428390, 0.692010, 0.142900, 0.449910, 0.394100, 0.281080,
0.807520, -0.168330, 0.295930, -0.535260, 3.205580, -2.728500, 0.766340, -3.245850, 0.409250, 2.288810,
6.688360, -1.337690, 0.180700, -0.782250, -2.052090, -0.934580, -0.471730, -0.362950, -1.122340, 0.075300,
-2.190740, -0.021310, -0.393620, 0.214370, -0.859090, 0.356500, 0.338910, 0.238100, -0.398110, 0.486270,
-0.684560, 0.312160, 0.347750, 0.768040, -0.046300, -0.033410, 0.458020, 0.634970, 0.287510, 0.478420,

-0.501390, 0.056040, -0.221130, 1.047900, 0.214520, -0.241110, -0.865790, 0.526380, 0.039690, -0.127190,
-0.692310, 0.323750, -0.467780, -0.795340, 0.833820, 0.875230, -1.352670, 0.261740, 1.026390, 0.165020,
-0.430530, -0.327760, -0.366970, 0.564700, 0.119200, -0.643580, -1.209680, -0.232810, -0.869680, -0.473270,
0.193470, -0.822230, 0.307430, 0.774270, 3.004320, 0.001530, -0.064040, -1.407330, -0.054580, 0.380010,
-2.248830, -0.628930, 0.324250, 6.060870, -0.919420, -0.951010, -0.117050, -1.373770, -0.618420, -2.251010,
-0.423120, -0.721140, 6.418590, 2.904450, -0.833920, 2.005270, -1.648970, 0.559380, -3.096320, 0.715480,
0.587130, 7.912370, 0.409590, -0.603240, 2.733450, 0.719330, 0.512460, -2.486530, -0.263310, 1.099640,
0.933830, 1.079470, -0.795020, 1.578300, 1.439400, -0.258160, -0.725910, 1.686550, 0.186080, -2.093310,
-0.154320, -0.669860, 1.052680, 0.851030, 0.381650, -3.269090, -0.019890, 0.501900, -3.143960, -0.385690,
0.536850, 2.434970, 0.465560, -0.662970, 7.631420, -0.996110, 0.379520, -0.470470, 0.578060, 0.083150,
0.148920, 0.492750, -4.447410, -0.805840, 0.793600, -0.584830, -0.949820, -0.779740, -1.396530, 2.595000,
11.571010, -0.547690, 0.378690, -0.033000, -6.515470, -1.030020, 0.389660, -0.175170, -8.238040, -1.942730,
-2.374670, 0.656400, -0.461490, -0.389040, -0.627060, -0.109980, 0.260650, 1.144730, -1.152070, -0.887470,
0.176830, 0.419640, -0.646400, -0.015520, -0.503970, 0.297480, 0.442460, 0.464320, 0.367880, -0.600130,

0.285510, -1.219510, -1.540860, 0.739230, 2.740960, 0.661740, 0.912420, 0.548130, -0.226430, 0.268620,
1.045340, -0.135530, -0.701190, 0.769210, -0.538410, -0.347050, -0.671840, -0.281850, -0.066420, 0.411260,
1.085460, -0.453670, -0.739890, 0.113120, 0.106360, -0.239970, 0.441880, 0.831950, 0.387480, 1.085420,
-0.291530, -0.585740, 0.623730, 1.117470, 0.912490, -0.878500, 0.968070, 0.091640, -0.500870, -0.383400,
0.121690, -0.784470, 0.514330, -1.261510, 1.161600, 0.685920, 3.072610, -3.625230, 0.321490, 1.945910,
-0.624700, -0.836550, -3.239920, 2.138180, -1.867380, 0.238090, 0.590530, -0.835480, -0.778180, -0.601310,
-0.171580, -0.668670, -1.313200, -3.711620, -2.118120, 2.190460, -0.606920, -0.823950, -1.893730, -0.458080,
-1.327920, 0.360820, 0.239580, -1.116140, -0.586520, 0.103500, 0.709180, -0.197270, -0.564630, -0.263770,
0.090870, -0.848790, 0.828120, 0.654160, 0.460540, -0.690040, 0.973670, -0.204210, 0.703320, -0.623720,
0.669260, 0.900050, 2.826390, -0.385850, 0.113270, -0.595170, 0.998490, 0.369370, 0.873300, -0.798030,
0.079140, -0.462160, 1.328600, 0.614890, 0.667020, -0.329930, 1.500230, -0.394550, 0.989790, 1.661930,
-4.759640, 0.933740, -0.698350, 0.004350, 3.420670, 1.165600, -1.717960, -0.256470, -1.511960, 1.474220,
2.910900, 0.987960, -2.092400, -0.012870, -0.182760, 0.032650, -0.620850, -1.346540, 3.596920, 0.334580,
-0.445310, 0.673680, 0.210750, 0.072650, 0.421110, -0.239060, 0.704130, 0.309050, 0.473580, 0.957030,

0.121360, -0.375070, -0.353260, -0.166270, -0.502810, -0.543900, -0.644740, -0.970140, 0.030540, -0.623270,
0.930090, 1.731030, -0.014360, -1.285770, -0.386960, 0.970950, 0.377790, -0.453540, -0.621810, 0.788580,
-0.140770, -1.074300, 0.635130, 0.020720, 0.948260, -1.076720, 0.853320, -0.101510, -0.849990, -0.291560,
1.687560, -0.011830, -0.312930, 1.010250, -0.756280, -0.283530, 0.519630, -0.576190, -0.335820, -0.563320,
-0.427570, 0.034990, -1.146070, 0.008470, -0.200760, 1.132800, -0.420960, -2.181040, -0.160450, 0.369200,
-0.110390, -2.763600, 0.019050, 0.515810, -0.573950, -0.398420, -1.631060, -3.615710, -0.694520, -0.417280,
1.920350, -0.419410, -0.401690, 0.131200, 1.116030, 2.405710, -0.414100, 0.865120, 1.143980, 1.928770,
1.681630, 0.633150, -0.284760, -0.696100, 1.878570, -0.623740, 0.006660, 0.629320, -1.440550, 3.154370,
0.086680, 0.419290, -0.637270, 1.584910, 0.121510, 2.734570, -0.482460, 0.248550, 1.186140, 1.061140,
1.493980, -0.011660, 1.585750, 0.896470, 0.166450, -0.212810, 1.819180, 0.459490, -0.914630, -0.152830,
-2.714220, 0.876670, 0.632120, 4.861210, -0.531760, -4.504690, 4.143760, -0.070820, 1.103370, -1.388980,
19.239201, -0.125670, -0.507420, 0.082660, -9.861470, 3.257530, 1.112000, -0.288820, 0.481140, -0.419960,
-1.748170, 1.584310, 0.438300, 0.576600, -0.460650, 0.630200, -0.613120, -0.920280, -2.435540, 0.598680,
-0.933810, -0.828130, 0.853260, 1.020150, 0.558550, -0.297020, -0.297210, -0.729170, -1.380760, -1.008690,

-0.091740, -0.425110, -1.180050, -0.284000, 8.191640, -0.681640, -2.009670, 3.416090, -1.909900, -0.497640,
-3.284560, 0.450170, -2.018340, -3.453900, -0.544860, -1.938750, -7.238890, -1.003630, -0.872210, -8.950920,
2.701750, -0.197310, -0.853700, 5.461330, -0.031780, 6.916700, 1.495490, -0.925430, -4.466410, 3.159300,
0.156990, -7.249140, -20.618080, -0.287470, 0.368600, 10.566460, 0.328720, 0.428990, -8.317360, -0.415810,
3.371540, -0.727470, -0.121950, 3.196420, 51.303089, -0.296080, -1.405410, -4.376150, -0.604500, -3.056500,
66.588463, -0.919960, 8.887170, 0.968600, -0.976420, -3.745180, 19.303820, -0.135230, 1.321800, 46.238232,
0.210090, 7.565030, -6.049720, -0.690060, -2.033260, 31.526100, 0.392790, 0.788290, -0.281810, -0.128910,
78.002533, 1.991400, -0.129580, -13.417510, -10.460550, -0.595160, 5.382570, -1.633110, 5.533850, 19.007191,
-1.242620, 0.183590, -12.550900, 0.748220, -4.097910, 7.683760, 0.308100, 1.754960, -12.237310, 1.802890,
-0.885310, 9.977960, 0.343660, 0.066690, -3.300130, -1.536850, 1.242760, -5.720910, -3.108150, 2.319620,
0.881340, -0.807700, -0.205020, 1.110660, 3.193000, -1.935240, -4.760540, -0.019970, 2.081490, 4.101920,
16.846939, 0.760730, 5.131540, 0.327660, -15.960430, -1.203670, -0.239330, 0.453190, -13.834800, -6.791480,
-7.963250, 1.299560, 0.746980, -0.382970, -0.130860, 1.099680, -2.368400, -3.512590, 6.184000, -0.623070,
-0.352780, -0.323510, -2.167750, -2.247840, -2.497990, -0.778360, -1.072590, -0.408530, 2.384400, -0.429280,

0.436200, -1.208250, 0.171520, -0.977480, 1.995420, 2.498940, -0.184970, 1.697750, -0.379130, 0.305710,
-1.342050, -1.578240, 0.695490, 2.028740, -0.738820, -0.263160, 0.466510, 1.013480, 0.080460, -1.234300,
0.090870, -0.731340, -0.810190, -2.026330, 0.170640, -2.921420, -2.073690, -0.705410, 0.929490, 0.605270,
-0.154850, 3.097200, 0.439920, -0.653920, -4.804180, 3.021950, -1.033950, 1.090670, 2.082450, -0.715400,
4.376170, 0.066220, 0.426480, -0.981910, 0.127350, -0.342100, 2.307690, 0.023080, -0.101240, 2.597190,
2.757880, 0.029770, 0.192110, -1.449650, 0.497960, -1.836240, -0.686150, 1.148630, 1.211060, -0.803660,
-1.585630, -2.528030, 0.336300, 2.990430, 0.436830, -1.754080, -0.674230, 2.702100, 0.127970, -0.694700,
-1.864840, 0.844830, 1.262560, 0.173640, 0.618540, -0.766600, 2.295890, 0.655320, -0.057690, 0.417960,
-0.451850, -0.073280, 0.171440, 1.999600, -0.153590, -0.612640, -0.502420, -0.118070, 1.351210, -0.666400,
-0.713860, -0.147970, 0.978440, 0.782010, -2.321170, -0.011950, -0.405390, 1.262850, -0.168790, 2.060190,
3.920790, 4.474760, -1.653810, -0.687330, -3.062280, 0.556810, -3.029710, 0.978610, 0.091260, 0.308690,
4.138460, 1.136840, 0.202860, -0.138250, -2.809310, -1.728490, 0.446680, -0.763580, 519.136108, -4.038690,
-2.285000, 1.355570, -0.668940, 0.705640, 0.518230, -0.521770, -0.401760, -0.960500, 3.734450, -0.244730,
-0.397430, -0.237080, -0.462430, 0.076480, 1.441660, -0.230300, -0.023350, 0.702750, -0.045170, -0.519130,

418.760071, 417.661133, 417.496643, 418.679169, 418.911133, 417.098816, 418.676819, 417.407410, 418.894867, 418.678070,
418.871887, 417.828857, 419.009552, 417.360748, 417.809448, 418.201324, 418.552551, 417.711182, 418.352722, 417.300842,
418.195923, 417.583191, 418.794373, 418.931946, 417.555908, 417.312317, 418.953857, 417.100311, 145.860672, 418.008545,
417.590393, 145.293716, 417.343689, 417.345856, 144.717499, 417.748596, 418.419891, 145.164017, 418.794708, 417.564453,
144.530197, 145.585785, 418.685089, 145.644409, 146.104156, 418.256989, 145.219635, 144.763062, 145.543564, 146.151382,
145.634064, 144.349136, 417.865967, 144.811005, 144.490662, 145.953918, 145.479034, 145.541763, 145.195847, 144.793411,
144.945465, 417.729156, 417.052307, 145.891846, 146.080322, 145.598755, 145.668869, 417.075470, 417.163971, 145.739258,
144.836685, 418.915344, 144.630936, 418.284454, 417.137665, 144.026474, 145.676468, 418.332916, 417.401825, 145.011032,
418.385529, 145.161118, 417.638123, 417.989777, 419.009949, 418.638428, 417.528107, 417.047058, 144.700790, 417.318756,
418.044434, 417.326263, 417.909882, 418.662811, 417.264160, 418.722656, 418.774353, 418.683777, 417.535614, 417.306519,
417.758575, 418.222687, 417.935852, 418.207092, 417.132782, 417.401276, 417.910248, 418.342224, 417.544769, 417.149170,
418.697479, 145.849884, 417.918610, 417.163361, 417.049255, 417.239624, 417.410004, 417.959106, 146.110886, 145.560333,
1.362070, -144.330902, 418.065094, 145.731110, 417.189362, 418.759735, 418.922272, -145.307053, 145.050491, 417.416931,
418.950104, 145.245682, 418.017426, 417.727020, 145.758835, 418.238647, 418.510162, 418.739502, 417.538361, 418.330292,

0.304540, -0.138760, -1.056110, -1.155450, -0.819460, -0.995190, 0.853750, 0.558610, -1.651100, -0.279800,
-0.421440, 1.239350, -0.851140, 0.135550, -0.974640, 0.083140, 0.821870, 0.694580, 0.673430, 0.492870,
1.568410, 0.490190, 0.456430, -0.706540, 0.083410, 2.361910, -0.858750, -3.401470, 0.804440, 1.010080,
-1.039490, -0.155470, 1.557290, 4.541490, -0.743720, 0.416910, 0.744530, 0.439790, -0.017900, -0.031810,
-1.517070, 1.012780, -0.139610, 2.422250, 0.531190, 1.142360, 0.791540, -0.441150, 2.064760, 1.356920,
-0.282550, 1.433780, 2.279160, -0.355420, -0.091600, 0.141610, -2.035330, 0.601830, -3.023060, -0.396150,
-0.630710, -1.520360, -0.951040, 0.039890, -1.077920, -0.606670, 1.074740, 1.254190, 0.234070, -2.402180,
-1.311210, 0.438190, -1.703000, -0.392760, -0.837330, 1.234440, -0.706320, 0.746650, -2.723810, 0.390340,
-0.085110, -0.526140, -0.745980, -2.664990, 0.016200, -0.592280, 0.120580, -1.551400, -0.654620, 0.635660,
1.835680, -0.629990, -1.462810, 1.215000, -0.860270, -0.768090, -0.002270, -5.160610, -0.444580, -6.777120,
0.138600, -2.980200, -2.387290, 5.053280, 4.788680, 8.848790, -4.104130, 2.218260, -3.841230, -1.612510,
-1.564800, 1.883830, 0.539370, 0.931350, 11.486160, -1.833910, 1.178800, 0.495410, -11.493810, -8.549370,
4.416230, -0.872120, -0.991530, 0.772060, 1.224090, -0.417520, -2.366510, 2.568770, -14.947800, 0.561920,
0.052610, 1.281670, 0.729250, -0.058640, -0.516780, 0.261170, 0.637820, -0.653730, 1.811580, -0.786480,

0.650760, -0.059760, -0.485670, -1.062490, 0.286510, -0.714070, 0.933390, -0.564250, 1.204000, 0.910030,
0.743140, 1.213900, 0.398080, 0.470540, -0.573740, 0.495060, -1.749990, 0.036400, 0.586460, -0.483630,
-0.454090, -0.355430, -0.419560, 0.443860, 0.569110, 1.996460, 0.675960, -1.962460, -0.924220, -0.581910,
-0.140840, -1.128340, 0.233270, 0.151840, 2.165540, -1.334770, -0.648420, 0.740810, -0.832740, 0.288150,
-0.780200, -0.946610, 1.032430, -1.767610, 0.573170, -1.764870, 0.019350, -0.887010, -0.541040, -0.776400,
-0.433990, 0.647540, 0.377610, 0.947310, -1.155700, 1.590200, 0.475920, 1.024780, -0.686350, -0.368690,
0.261830, -0.067570, 0.424530, -1.136220, 0.943730, 1.857950, 0.883490, -0.017140, 1.434840, 0.113180,
0.680900, -0.529450, 0.508060, -0.104670, 1.114600, 0.593310, 0.273740, 0.114630, -0.515620, 1.241940,
0.001440, 2.061200, 0.321150, 0.271540, -0.540640, -0.293890, 0.331780, -0.572580, -1.323420, -0.312580,
-0.213190, 2.097630, 0.332150, 0.540900, 0.064620, -0.258280, 0.114960, -0.796930, -0.753840, 2.429880,
-0.203660, 0.438830, -2.492040, -8.078040, -2.351800, 4.613690, 2.936330, 10.345820, -0.624560, -1.075400,
1.512270, 0.537910, 1.022010, -0.884050, 0.289590, -1.155960, 0.302100, 0.364650, -3.823110, -0.285420,
0.903770, -0.210500, 0.478790, -0.789620, 0.451330, -0.806800, -0.420590, 0.361060, -1.134970, 0.897940,
-0.562370, 0.899940, -0.758530, 0.169790, 0.220780, -0.445320, 0.823060, 0.813950, -0.304720, -0.488510,

0.616240, -0.732880, -0.153030, -0.050880, -2.432900, -1.109390, -0.482130, 0.673140, -8.188340, -0.515040,
4.201120, 15.265340, 1.661180, -0.293270, -0.790960, -0.875780, 0.811660, -0.850280, 0.549970, 0.192310,
-1.036120, 0.973300, -0.241840, 0.819220, 0.614310, 0.338220, 0.845610, 0.232070, 1.731790, -0.624730,
0.693480, -1.807690, 0.577770, 0.703500, -0.686090, -0.799700, 0.031240, 0.325420, -1.096460, -0.013490,
0.056470, -0.896350, -0.246380, 2.126900, 0.205790, 1.476560, -0.428930, 0.386970, -0.015420, -0.661600,
-1.090420, 0.354770, 0.367680, -0.441810, 3.180280, -1.067830, -0.448210, -0.187480, 0.798430, -0.674110,

1.288430, 1.051520, 0.067390, -0.603750, 1.786350, 0.865750, 0.501630, -0.290280, 0.027390, -0.138350,
0.607680, -5.106500, 1.755750, -3.037010, 0.182680, 0.550410, -1.515490, -0.225420, 0.615190, -0.052360,
0.699910, -0.246040, 0.324150, -0.636670, -0.647080, -0.036320, -0.742040, 0.066630, -0.301990, -0.668970,
0.323040, -0.744410, -1.007650, -0.261360, -2.825900, -0.709930, 0.141550, -0.405820, -0.775760, 0.037310,
0.475110, -0.497510, 0.686680, 0.889370, 0.324800, -0.469030, -0.767260, 0.789700, 0.199020, 0.572300,
-3.439560, -1.392850, 0.714820, 0.729370, 0.278030, -0.373990, -0.428340, 0.011250, 2.075370, 0.378010,

-0.291610, -0.214020, -0.502180, -0.485880, -4.050540, -0.960630, -0.463840, -0.482260, -8.121840, 0.612970,
-19.108841, -0.427200, 0.329360, 0.666900, -1.143650, -0.985030, 0.088010, 0.108650, -0.684450, 0.286380,
1.823910, -0.633710, 1.733280, 0.842500, -0.051970, 0.193600, 0.685090, -1.060440, 0.076530, 1.383050,
-0.262790, -0.787130, -0.147380, -0.731780, 0.403710, 0.870610, 1.952410, 1.061800, 0.517900, 0.536460,
-0.153560, -0.313620, -1.046360, -0.425440, 0.203530, -0.490500, 0.089960, -0.091550, 0.185330, 0.530410,
-2.539060, -0.030560, -0.098420, 0.297010, 0.083860, 1.437130, -0.264900, 0.173970, 1.095720, -0.485110,

1.773330, -1.018310, -0.884050, -0.219130, 0.661890, 1.529020, 0.272460, 0.600440, -20.633150, 0.280470,
0.582330, -1.208740, 0.244420, -0.399240, -0.033990, 0.229290, 0.223530, -0.133810, 1.824500, 0.820580,
0.816050, -0.605850, 0.463450, -1.059100, -0.024370, -0.750730, -0.632540, 0.023190, 0.109090, 0.186400,
0.882020, -0.699480, 0.215490, -0.647350, -2.817590, -0.861460, 0.352970, 0.007910, 0.315000, 0.155270,
-0.910100, 0.469110, 0.008040, -0.143590, 1.439490, 1.677820, -0.378780, -0.439480, 0.693370, -2.512110,
1.876030, 0.824690, 0.264760, -0.571370, -1.481790, -0.081650, 0.047190, 0.620720, -0.477890, -0.366190,

-1.279170, -2.120640, 0.350780, 0.250140, -2.007400, 1.986620, 0.975890, -0.411610, -317.559631, -1.875360,
-1.636470, -0.198320, 0.616000, -0.021570, 1.079720, 0.147540, -0.214720, -0.465340, -14.338510, -0.528320,
-1.681690, 1.042100, -1.770110, -0.738990, 1.260930, -0.410500, -0.531520, -0.251770, 0.629450, 1.763820,
-0.624720, -1.764130, -0.305930, 1.402040, -1.147970, -1.166240, 1.951250, 1.283990, -0.659480, 0.466830,
0.120960, -1.096870, 0.144800, -0.904450, 0.380140, -0.422860, 0.371730, -0.612990, -0.068650, -0.619850,
-0.494550, 1.150800, -0.697000, 0.139850, -0.079240, 0.246470, 0.239560, 0.118520, -0.482470, 0.428960,

-4.905940, -0.405290, -0.075470, -0.568870, -0.837530, -0.365430, -0.163510, 0.146880, 1.711310, 0.129490,
-3.151410, -0.768920, 0.412500, 0.590340, 0.593890, 0.903190, -0.617630, -0.720340, 0.120680, -1.073730,
0.719540, -1.303380, 0.359100, -0.395240, 0.279790, 0.358500, -0.482990, 0.926890, 0.345280, -0.280530,
0.474700, -0.101860, -0.172000, 0.231190, 0.978470, -1.017130, -1.244160, 0.606060, 0.058850, -0.459540,
0.717480, 0.679440, 0.820780, 0.471740, -0.986790, 0.232410, -0.135120, 0.282970, 0.213170, -0.590080,
0.515410, 0.059670, 0.450770, -0.132920, -0.307170, -0.441650, -0.412160, -0.562610, 0.112620, -0.019700,

4.819250, 1.125020, -0.279550, -0.428560, 1.634340, 0.828930, -0.982630, -0.047050, 8.319740, 0.427850,
3.039960, -1.185920, 0.385680, -0.064060, 0.332070, -0.410090, -1.255040, 2.148160, 0.714190, 0.274950,
0.328940, -1.153280, 0.783240, -0.705520, -1.040270, 0.549790, -0.621640, 0.404260, -1.100470, 0.504460,
-0.570830, 0.291210, 0.015100, -0.364270, 1.446870, 0.006030, 0.420250, -1.054960, 0.700260, 0.154700,
0.152970, -0.597360, -0.388870, 0.140240, -0.435690, -0.511610, -0.222300, -0.493960, -0.312580, -0.058890,
-1.224670, -0.347540, 0.392510, 0.676860, -3.418330, 0.485640, 0.326890, 1.017600, 0.317060, -0.031220,

12.744880, 1.888010, 0.668420, -0.570400, 5.785810, 1.419490, -0.259090, -0.589090, -1660.616333, -1.630440,
8.966320, 1.101980, -0.228720, 0.261070, 0.328800, 0.012690, -0.562070, -0.969190, -10.535740, 0.884190,
-0.555230, -0.123810, -0.572190, 1.264620, -0.289840, -1.415360, 1.903530, -0.071580, 0.412260, 0.737230,
-0.891660, 0.340200, -0.983640, 0.132870, 2.133910, -0.826880, -1.781360, 0.487490, -0.235540, -0.763770,
0.202400, -0.319930, -0.533060, -0.136540, -1.327570, -1.021190, -0.463890, 0.440700, -0.905090, -1.104260,
-0.127680, 0.148660, -0.853220, -0.470510, 0.439830, -4.416950, 0.754810, 0.437260, 0.808210, 0.548750,

3.238740, 4.083320, -1.375760, -0.405130, -1.161380, -4.867050, -3.302110, -0.122830, 1046.680908, -0.022040,
13.547600, 4.293640, -2.674550, 2.548970, -0.500060, -0.286920, 0.198950, 6.881930, 5.590240, 1.091240,
-0.762800, -0.645310, 2.298330, 2.292990, -0.509400, 3.886680, -0.387250, 0.227400, 0.966450, -0.677040,
-0.146400, 0.810250, -2.139120, -0.011940, -0.865280, -0.383460, -1.379540, 0.172320, 0.362070, -0.405590,
1.219380, -0.500140, -1.254230, 0.983440, -0.811670, 0.453460, 0.194580, -0.568040, 0.377080, 1.697340,
-3.165570, 1.367580, -2.079830, -0.228720, 1.647900, 4.249180, 0.145510, 0.560960, -0.481600, 0.114520,

0.861890, 2.491800, 0.249260, -0.830550, -5.632250, 2.003720, 2.955920, 1.839340, -7.374720, 1.609140,
-0.042920, 0.078880, -0.841840, -0.949850, 0.098370, -0.244350, -0.206700, -0.312660, 4.243660, 0.828060,
1.033950, 0.327600, 0.820140, -1.161850, -0.873460, -0.755350, -0.498790, 0.618300, -0.596400, 0.849780,
-0.358610, 1.152860, 0.706340, -1.311890, -2.062670, 0.339460, -0.716690, -0.667430, -0.142850, -0.347290,
-0.429180, 0.926210, 0.661010, -0.578280, 0.180860, 0.136560, -0.740160, -1.622770, -0.671960, 0.369100,
1.639780, 1.205750, 1.083010, 0.797780, -2.789060, 5.156890, -0.488040, -0.325610, -1.216820, 0.141760,

-0.149340, -1.177300, -0.044560, 1.105170, -0.834290, 2.301470, -1.600470, 0.091360, -3.585290, 1.100040,
-4.187700, -0.035370, 2.592930, -0.585880, -1.252930, 0.745110, 0.379620, -1.376820, 0.905890, 0.605640,
0.325050, 1.047120, 0.285270, 0.399430, 0.674600, -0.935650, 0.073650, 0.194280, 0.066950, 0.141030,
-0.811730, -0.072130, -0.765530, -1.059380, 2.181400, -0.196690, -1.990450, 0.157130, -0.006020, 0.277930,
-0.308720, 0.829000, -0.489800, -0.399730, 0.066230, -0.119240, -0.181430, 0.355600, 0.979770, 0.441170,
0.770120, -0.349480, -0.229650, -0.226180, 4.458630, -1.108210, -0.493460, 0.828760, 0.400000, -0.260430,

0.367050, -2.415910, -1.033550, 0.695290, -1.008730, -0.734830, -0.940270, -1.240860, -4.931450, 1.350900,
-6.205450, -9.693250, -2.216410, -0.039390, 0.279380, -0.309440, 19.417330, -0.586100, -7.783130, 0.211540,
-1.506370, -0.778640, -0.305010, -0.021170, 3.654830, 2.772830, -1.554940, 0.383200, 0.662550, -0.719470,
-0.976580, 0.030250, -0.085460, 1.326770, 4.297690, -0.413890, 0.091320, 0.691860, 0.843520, 0.035180,
0.862830, 1.826290, 0.485550, 0.112110, -8.580470, 3.943080, -1.417340, 0.811100, -0.098950, 2.161160,
2.890360, 0.373110, -0.466420, -0.572870, -3.538640, -4.975210, -0.803290, -0.083340, -0.628070, 0.583430,

-18.281750, 3.733040, -1.575060, -0.199830, -1.377860, -0.614170, -0.102470, 0.251220, 4.934650, 0.623240,
-3.375060, 3.468290, 4.690020, 0.574310, 0.360280, 0.760970, -1.240600, 4.626520, 1.278030, -0.683500,
0.644560, -1.053950, 1.305240, -0.893340, -0.667420, 0.787440, 0.529470, 0.015110, -0.547500, -0.219860,
0.442150, 1.062020, 0.271960, -1.239350, 2.742580, 0.033960, -0.935530, -0.356970, 0.453570, 1.566500,
-0.655740, 0.046040, 1.146410, 0.288440, -1.720900, 2.567700, -0.823580, 0.966310, 0.862910, 2.087010,
-1.638450, 0.335770, -1.803430, -0.185340, -0.683130, 2.112690, -0.851180, -1.199830, -0.635600, 0.748600,

-6.271250, -1.659540, -0.272250, -0.159100, -1.721650, 2.147790, 0.944890, 0.065620, 2.526560, 1.342120,
-4.000710, -0.652300, -1.381610, 0.224320, -0.075650, -0.655740, 0.636150, 0.156150, 0.589740, -0.714090,
-0.691250, 0.223350, -0.756480, 0.658920, 0.405810, 0.961690, -0.710050, 0.668410, 0.568850, 1.396330,
-0.122640, 0.315140, 0.889640, -1.443690, 0.419610, -0.913170, -1.850370, 2.327580, 1.026430, 0.479610,
-0.874850, -0.168250, 0.514460, 0.078390, -0.973870, -1.157930, -0.029520, 1.182310, -0.513530, 0.278660,
0.205520, 0.483800, 1.659350, -0.033580, -0.930070, -1.788980, -1.040850, -0.324320, 0.355620, -0.010160,

31.571070, -1.054310, 0.694460, -1.086910, -0.788810, -5.383830, -1.754010, -1.259450, 2.909670, -2.235430,
-10.750520, 1.539340, -1.794690, 0.562570, -0.669300, -0.220360, 0.574950, 1.640250, -0.946800, -0.962210,
-0.766320, -1.369140, -0.527270, 1.722520, 1.393730, 0.692030, 0.661450, 0.586940, -0.279220, -1.001360,
0.872000, 0.017860, 0.754690, -0.087460, -2.162050, -0.124000, -0.405670, -2.641600, 0.674750, -0.779400,
-0.039150, -1.017100, 0.253170, 0.466630, 0.682490, 1.802310, -0.196970, -0.536420, 0.254070, 1.132460,
7.809160, -0.415600, 0.555000, -0.616130, 0.149370, -0.908300, -0.797390, -0.086260, 0.326770, -0.222550,

-1.222860, -0.151630, -0.544090, 0.252420, 0.189460, -2.280080, 0.158300, 0.548040, 0.818040, -0.165850,
3.389740, -1.107970, -0.517380, 1.068920, -1.257500, 0.100970, 0.371640, 0.169400, 2.218400, 0.034110,
0.511660, -2.477240, 0.592690, 1.334900, 0.777380, 0.413650, -0.468660, -0.960300, -0.087500, 0.867130,
-0.004850, -0.224320, 0.740800, -0.522350, 1.146760, 0.638410, 0.088060, 0.749410, -1.062240, -0.048590,
0.046580, -0.322630, -1.043420, -0.331020, 0.752290, -0.234030, -0.352460, -0.718110, 0.681610, -0.018210,
-0.194380, -0.174090, 0.542250, 0.042610, 0.665890, 1.327360, -0.060830, 0.890180, 0.120250, -0.514150,

16.639750, 2.019050, -0.779320, -0.980100, 2.592110, -0.778710, -0.106520, -1.080570, -2.086330, 0.204400,
-0.605110, 5.061280, 2.131530, 0.116080, -0.911320, 0.743420, 1.495120, -0.944940, 1.877190, 0.787130,
-0.406980, 0.387690, 0.873160, 0.671000, 0.510040, 0.611380, -0.842570, -0.362640, -0.331980, -0.102240,
-0.454360, -1.710190, -0.118140, 1.817620, -1.313690, 0.080370, 0.580050, -0.171380, 1.157080, -2.026620,
-0.131180, -0.848970, 0.846460, -0.179190, -1.315520, 1.026750, 0.511900, 0.509520, 0.620720, 0.648790,
-0.000520, 0.444480, 0.074080, -1.210640, 0.196240, 0.929140, -0.160640, 1.136070, -1.604480, -0.694140,

136.322632, -0.769690, -0.654560, 0.880730, -0.669430, -1.810240, -0.488420, -1.392280, -6.116810, -1.392940,
57.444618, -0.760860, 0.384300, 0.222250, 0.642820, -0.623250, -0.480310, 0.704250, -1.197830, 0.899290,
1.335330, -0.807120, 0.408530, 1.280270, 0.273500, -0.870710, 0.687240, 0.599660, 0.067420, 3.043710,
-0.430400, 0.149400, -0.252530, 0.049920, 0.581050, -0.731550, -2.664970, -1.900790, 0.122820, -1.088670,
-0.913950, 0.438100, -0.322310, -0.414460, -0.526130, 0.372330, -0.285670, 0.355930, 0.108390, 0.628290,
-2.036480, 0.242740, -1.193500, 0.317950, 4.023190, -0.510120, 0.011080, 0.118390, 0.013230, -0.632820,

28.555990, -0.783950, -0.765200, 0.385970, 0.785400, 0.292620, 1.610850, -0.789700, -4.802580, -0.058230,
6.578490, 2.303790, 0.429450, -0.483100, -0.448100, -0.736990, 0.258940, 2.736090, 0.277270, 0.260490,
-0.356020, 2.145190, 0.364400, -0.265350, 0.335840, -0.447410, -0.790790, -0.268320, 1.147080, -0.154900,
-0.046660, 1.035020, -0.617250, 0.340900, -0.008060, -0.727220, -0.513020, 1.940430, -0.510600, 0.450490,
-0.878340, 0.376530, 0.181330, 0.153540, 0.550990, -1.214780, 0.261320, -0.054270, -0.483900, -0.786060,
1.719530, 0.110280, -0.776180, 0.957090, -1.662700, -0.072510, 1.293590, 0.315980, 0.823660, -0.079380,

-48.687550, 0.204730, -0.424110, -0.868580, -4.959240, 0.033130, -0.180310, 0.794330, 7.847360, 2.639670,
-65.479507, -13.159880, -0.764680, -7.894960, -0.198820, -0.127000, -0.022520, -1.482710, 3.667980, -0.020530,
0.264250, 0.420580, 0.157560, 0.613420, -0.663500, -0.487550, -0.012590, 0.874140, 0.463690, 0.408120,
-0.087320, 0.530880, -0.259690, -0.003620, -0.154720, -0.708820, 1.382570, 2.005250, -0.443330, -0.134930,
0.208340, -0.555230, 1.135770, -0.347110, -0.456450, -2.802020, 0.367120, -1.169460, -0.189400, 0.247620,
-5.205400, 0.265910, 0.029610, -0.043290, -2.562450, 2.596610, -0.096450, 0.405470, -0.075490, -0.836870,

2.305360, 0.416910, 0.299400, 0.133840, -1.333570, -0.169540, -0.303590, -0.065810, -4.038020, 1.982030,
-27.431709, -0.808420, -1.429560, 0.426940, -0.494730, 0.576780, 0.707350, 1.939070, 1.152860, -0.471030,
-0.467470, -0.775510, 0.787900, 0.567800, 1.190840, 0.839110, -1.108560, 0.168400, -0.042130, -1.064400,
0.728420, 0.504710, 0.577000, -0.016620, -0.102660, 0.821010, -2.557200, -0.172850, -0.350750, -1.720750,
0.151090, 0.285180, -0.900610, -0.627220, -0.229730, -0.099800, -0.951710, -0.546110, -0.367750, -0.809960,
1.730220, -0.330850, -1.060220, -0.817510, 0.259880, -0.142300, -0.436500, -0.699180, 0.324540, 0.124520,

6.732150, -0.512080, -0.059260, -0.833660, -1.443060, -0.948650, -0.872620, -0.608790, 4.612380, -0.961920,
-3.107690, 1.727760, -0.590360, 0.142140, 0.769070, -0.611260, -0.764050, 1.969360, -2.585860, -0.245400,
0.883620, -0.258500, -0.741630, 0.516870, -0.551880, 0.930580, -0.244180, -0.205180, 0.675880, -0.726540,
-0.115540, -1.087440, -0.272560, 0.607100, -4.116960, 0.284580, -0.174780, -1.081810, 1.429200, 0.885180,
0.792120, -0.500730, -0.913380, -0.357130, 1.918440, 1.985560, -0.541290, -0.839230, 0.620300, 1.221690,
3.298810, 0.208400, 1.371770, -0.688140, -0.555170, -1.739720, -0.112990, -0.712810, 3.275690, -0.003760,

-63.251888, 0.328860, -0.275940, -0.396980, -0.245600, -0.567900, -1.012620, 0.620140, 1.605580, -0.373400,
-0.770690, -0.399940, -0.130080, 0.393080, -0.323550, 0.064160, -0.168700, -0.927380, 0.421970, -0.436210,
-0.265700, -1.693090, 0.227910, -0.240500, -0.126600, 0.508980, 0.375180, 0.898110, -0.757030, -2.892920,
0.538500, -0.721650, 0.493630, 0.197270, -0.737070, 0.487500, 2.526660, -0.929430, 0.220060, 0.497280,
0.429300, -0.102440, 0.599520, -0.100660, 0.981960, -0.075930, 0.164140, -0.008970, -0.497490, 0.649510,
0.417530, 0.489930, -0.089520, 0.174620, 2.068120, -0.011970, -0.295530, 0.542300, -1.196700, 0.395260,

-2.333140, -0.179500, 0.129620, 0.593190, 3.586370, 1.037150, -3.002830, -0.337310, -3.068900, 0.061990,
-14.779260, -0.623120, -0.202330, -2.755340, -0.640380, -0.528920, -0.307390, 2.643460, -3.674280, -0.096640,
-2.036440, -0.058510, 0.361870, 0.887340, 0.157400, 0.618030, 0.504350, -0.677900, 0.686210, 1.331040,
-0.065100, 2.052960, 0.627760, -0.107840, 0.559160, 0.127310, -0.833330, 0.435760, -0.635160, 0.607020,
1.049510, 0.166820, 0.865500, 0.683080, -0.436700, 0.912290, 0.238050, -0.483160, -0.713430, -1.158800,
0.601440, -0.257290, 0.020110, 0.107210, -2.460290, -2.665840, -0.343550, 1.227550, 0.384370, -0.372030,

-2.162790, -0.257740, 0.851750, -1.103940, 1.778240, 1.919200, 1.611700, -0.275830, -623.485901, -2.653270,
-0.062410, 0.179710, 0.417380, -0.605730, 0.198670, -0.037560, -0.251110, -2.075040, -2.476830, -1.040060,
0.139620, 1.156660, -0.922860, 0.392460, -0.398830, -1.890400, 0.519220, 0.321880, 0.889060, 1.436420,
-0.004510, 0.038770, -1.126570, -0.640240, -0.336490, 0.663000, -0.831260, 1.043590, -0.639070, 0.376490,
-0.205350, -0.372150, -1.135360, 0.592410, -0.118190, 0.287480, -0.395660, 1.016480, -0.357030, 0.412490,
0.087900, -1.117550, 0.790600, -0.701660, 0.267920, -0.990930, -0.040600, 0.198380, 0.963170, -0.516060,

-399.526978, -3.381460, -0.586160, 0.198920, -1.412310, 2.500160, -14.108390, -0.037350, 1.952360, 3.627330,
-915.190002, 2.703390, 3.600820, -0.698810, 1.084600, -0.212980, -1.865270, -1.628580, 2.597550, -0.212050,
0.265040, -0.547310, -0.875700, -2.937970, -1.195370, 0.487430, 0.278380, 0.579120, 0.420290, -2.193550,
-0.853610, 0.386710, 0.104040, 1.727780, 0.746000, -1.022890, 1.283270, -2.247300, 0.520250, 1.103120,
0.708390, 0.747950, 0.007750, -0.971780, 0.340550, 2.025360, 0.672390, 0.033330, -0.780830, 0.081390,
5.218050, 0.485050, 0.461220, 0.060200, 4.228930, 1.280740, -0.973670, -0.344530, -0.047930, -0.272100,

4.714900, -1.154950, -0.190540, 0.716350, -1.105680, -1.803920, -0.945860, -0.165550, -7.820230, -0.370310,
-0.697310, -0.581180, 0.295990, 0.201460, 0.409690, 0.443100, 0.727890, -0.408310, 0.078830, 0.391590,
-0.381170, 0.063130, 0.322380, 0.167590, 0.366360, -0.051700, -0.558650, 0.716900, 0.307210, 0.303420,
0.321800, 0.115630, 0.044840, -1.103160, 1.952100, 0.440940, 0.672230, 0.444880, -1.092830, -0.224220,
0.169500, -0.299880, -0.105890, -0.586450, -1.027250, 2.222240, -0.481300, 0.731460, 0.816280, 0.646120,
1.879510, -0.841930, 0.074350, -0.744660, 1.644140, -0.018050, -1.209200, -0.708610, 0.172790, 0.249620,

0.795170, -1.118950, 0.306150, 0.254090, 0.789790, 0.442780, 0.207180, -0.299330, -2.863240, -0.101870,
2.834510, 0.218800, 1.480360, 0.557240, -0.031980, -0.132940, 0.319030, 1.120240, 2.144590, -0.491480,
0.163710, -0.717110, 0.842090, 0.421690, -0.288760, 0.695810, -0.438820, 0.508640, 0.448390, -1.275020,
-0.001880, 0.522430, 0.307630, 0.166050, 1.382160, -0.557500, -1.810230, 0.787150, 0.883890, -0.357160,
-0.769420, -0.457600, -0.215700, 0.591590, 0.209970, -1.424810, -0.387630, 0.559680, -0.665980, 0.075430,
-2.968610, 0.029330, -0.455620, 0.137660, -0.046310, -0.664160, 0.549230, 0.131440, 2.738750, -1.129800,

-2.290800, -0.281170, 0.513820, -1.061370, 0.544360, -0.771870, -0.083250, 0.041790, -0.833360, -0.467760,
-0.979180, 0.981700, 1.443610, -0.394260, -0.036180, 0.383030, 0.319620, 1.173710, 0.253890, -0.586960,
0.623980, -0.404960, 0.718240, 0.584180, -0.635650, 0.171350, 0.128460, -0.584490, 0.012880, 0.564560,
0.463450, 0.219740, -0.799090, 0.404000, 1.100130, -0.424510, -1.669500, 0.932260, -0.064950, 0.095610,
-0.391780, -1.118320, 0.131930, 0.164640, 1.133570, -1.053270, -0.529350, -0.004200, 0.045080, 1.588490,
-3.407740, -0.218350, -0.357990, -0.654720, 0.596900, 0.885740, 0.583330, 0.882240, 2.495240, -0.538250,

3.413350, -0.225800, 0.184580, -0.685340, 7.056650, -2.719440, -0.479800, 0.151890, -2.805970, -0.382930,
135.520828, 4.343900, 0.897080, 1.043050, -0.257950, -0.969050, -0.489150, 1.243380, 2.285630, 0.316720,
0.238750, 1.534530, -0.010260, -0.716940, -0.788110, -1.123110, 0.300720, -0.252070, -0.387820, 0.979240,
0.870410, 0.526200, -1.530000, -1.068420, 2.272890, 0.578380, -1.504980, 3.579420, 0.192300, 0.996020,
0.346620, -0.803970, -0.875890, -0.939200, 1.557800, -0.108220, -1.217650, 0.239630, 0.766820, 2.818230,
-6.296630, -0.900520, 0.841620, 0.171550, -0.533400, 1.630510, -1.652130, 0.050810, 3.716890, 0.257050,

0.464960, 0.740870, -0.192180, -1.432140, 0.162910, 0.579010, -1.989700, 0.934020, -1.488930, -0.560830,
0.597070, -0.841800, 0.913240, 0.081990, -0.361850, 0.455980, -0.434100, -0.513870, 0.471180, -1.239050,
2.664810, -0.474030, -1.726500, -0.223190, 1.043130, -1.468740, 0.876780, -0.395490, -0.031020, 0.162140,

-0.830250, 0.427880, 0.667320, -0.919510, 0.421450, -1.167110, 0.947230, 0.166020, 0.581250, 0.750100,
-0.487200, -0.371060, 0.452410, 0.477490, -0.465900, 0.451500, -0.675280, -0.384710, -1.527260, 0.551950,
-4.541520, -0.151970, -0.866190, 1.058260, -4.000180, 0.298280, 0.339490, 0.733400, -0.910300, 0.531020,

0.614250, -0.600140, -0.298410, 1.400870, -0.430900, 0.143700, -1.099940, -1.038430, 0.906590, -0.339230,
0.063020, 0.662140, -1.020550, -1.042870, 0.507160, -0.344580, 0.506960, -0.212160, -0.152490, -0.805080,
-2.276210, 0.357040, -0.325160, -0.226390, -1.256600, 0.059240, -1.308520, 0.531800, 0.321570, -0.796810,

-0.208600, 0.690500, -0.194910, -0.784880, 2.030350, -0.783090, -2.747710, 0.926390, -0.637820, -0.771520,
0.076500, -0.447260, 0.385360, 0.178490, -1.529220, -0.051710, -0.587500, 0.428020, 1.164330, -0.935430,
0.663010, -0.853470, -0.314950, -0.144650, 1.409690, -2.170810, 0.101970, 0.153880, -0.343370, 0.415450,

-0.795420, 0.887510, 0.496750, -1.124280, 0.727970, 0.845960, 0.558780, -0.258960, 0.511510, 0.970250,
0.118130, -0.099210, -0.802820, -0.982690, -0.626360, -0.212690, -0.070940, -0.589410, -0.764280, 0.811630,
-3.722760, -0.224020, -0.056030, 1.206950, -3.772770, 0.783470, -0.270850, 0.377810, -0.247330, 0.305840,

0.325120, -0.988570, 0.121980, 1.137640, -2.177300, -0.191650, -0.279570, -1.025460, -0.474080, -0.107840,
-0.215900, 0.309350, 0.116630, 0.161800, 1.232220, -0.071780, 0.556840, -0.311940, -0.084260, -0.929920,
-0.250500, 0.979790, -0.584660, -0.059450, -1.351650, -0.514770, 0.446960, 1.033690, -0.683780, -0.454540,

0.663240, 0.362720, -0.847370, -0.302330, 1.708340, -0.775320, -0.006660, 1.286550, -1.273450, -0.380760,
-0.729890, -0.127840, -0.524380, 0.199400, -0.674680, -1.694210, -0.350110, 1.002230, 0.730220, -0.726210,
-2.235430, -0.504890, -1.179730, 0.158330, 1.673110, -3.047680, 0.747120, -0.869120, 0.236960, 0.469240,

-0.359960, 0.521070, -0.436470, -0.047970, -0.120880, -0.076110, 0.263850, -0.979460, 0.546720, 0.562270,
1.169430, -0.858480, -0.049940, -0.318910, -0.678410, -1.430310, 0.137680, -1.154460, -0.053000, 0.655460,
-2.498310, -0.460030, 0.421800, 0.748530, -3.817320, 1.343100, 0.041070, -0.030630, 0.458680, 0.101770,

-0.628820, -0.778900, 1.058630, -0.028350, -1.871170, 0.937360, -0.897740, -1.479900, -0.085820, -0.336440,
-0.817240, 0.016980, -0.493500, 0.666040, 0.590690, 1.578890, 0.010440, 0.190230, 0.438760, -1.096750,
2.453040, 0.546490, 0.577440, -0.412790, -1.599360, -1.313450, -0.024110, -0.257540, 0.371370, -0.650320,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.102050, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.600260, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, 1.134310, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 174.412567, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.746450, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.537780, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.661800, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, 0.430300, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.841920, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.696010, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, -0.633960, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.149710, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.230590, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.367180, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.069970, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 250.505478, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.088410, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.059110, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.281610, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 174.969330, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.512850, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, -0.080940, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.226760, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, -0.573890, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.614640, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, 0.344360, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.056860, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 417.091339, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.156990, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -0.824930, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.317710, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.657380, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, 0.026850, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.648670, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.424690, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.180280, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.845190, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.402330, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.672960, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, -0.803620, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.702010, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.141470, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, 1.010300, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.919550, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.081070, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, 0.340450, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, 0.252100, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, 0.997820, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.300590, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.473730, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.561690, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 1.039090, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -0.433520, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, 0.603480, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.393790, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.951960, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.100610, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, -0.004580, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.551160, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.569540, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.001780, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.010600, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, 0.948640, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.171950, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, -0.549950, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.471680, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.903580, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.816170, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.123730, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
0.00135, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.00111, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
1.33134, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
1.42857, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
0.00001, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.02411, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
1.26582, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.29230, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.00000, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
0.52298, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.00046, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.01354, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.99393, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.26217, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
1.28784, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
1.42857, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.04884, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.02619, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.00003, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
1.42857, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
1.13173, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
1.42688, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
1.26559, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.59606, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.18851, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.33857, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.32306, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
1.42857, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
1.42454, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
1.27309, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
1.42243, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.43663, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.99930, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.17935, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.09238, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
1.40081, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.00225, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.26691, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
1.37397, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.03571, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
1.42280, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
1.11796, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
1.41631, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.39746, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.00359, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
0.47486, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
1.23634, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
1.32181, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
1.30721, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.00008, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
0.23025, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.80755, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
0.11896, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
0.27365, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.46181, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.00000, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.34812, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
1.40965, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
1.38378, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
1.38671, 0.500000, 2,
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
