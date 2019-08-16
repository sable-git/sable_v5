/*********************************************************
  test_newN.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:27:51 2004
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
-0.899040, -0.155880, 0.461620, -0.663210, -0.693610, -0.358860, 0.999090, -0.381190, 0.347960, 0.721820,
0.513970, 0.269850, 0.807590, -0.501500, 0.755900, 0.954840, 0.924670, 0.392400, 0.304840, 2.086190,
-0.271110, 1.614840, 0.030120, -0.353170, -0.263550, 0.094730, 0.584390, 0.176100, -0.287990, 1.551630,
0.697480, 0.469280, 0.803970, -2.804410, -1.637960, -0.824890, 0.278100, 0.564050, 0.157200, -0.351060,
-0.745280, 0.041170, 4.735830, -1.657370, -0.715050, 0.825150, 0.836690, 0.636190, -2.304790, 0.701830,
-0.542670, -4.148280, -2.806190, -2.094780, 2.503480, 0.386320, -2.148960, -3.571040, 0.790830, -1.011750,
3.037320, -0.589350, -0.102420, 6.984680, 1.734350, -1.692750, 0.843870, -0.154940, -0.772760, 1.672550,
-0.537640, 0.913820, 6.030030, -0.606810, -0.858200, 1.188430, 0.821270, 0.440720, -1.972500, 0.461790,
-0.199050, 0.607900, 0.427000, 0.488890, -1.330240, -0.412320, -0.909080, 1.492810, -0.369790, -0.052010,
-0.521560, -0.640280, -0.440660, 0.084100, 0.033910, -0.065780, -0.770920, -0.360010, 0.171430, 2.016750,
0.424660, -0.300870, 2.065560, 1.308830, -0.803780, -2.810060, -4.024700, 1.666550, -0.258490, 3.470000,
0.716730, -0.542340, -0.764720, -0.617900, 0.992310, 0.999220, -3.233460, -0.142580, -0.465400, 0.061230,
1.081050, -1.647890, 0.520530, 0.619870, -1.171830, 2.465260, 1.640600, 0.798890, -0.157080, 1.042440,
1.000660, -3.961470, 0.352510, -0.304530, 0.238780, -1.060620, -0.277250, 0.018140, 0.049760, 0.093470,

-0.553490, 0.848160, 1.460680, 0.328920, 0.749590, 0.073750, 0.657040, 0.152420, -0.907820, -1.194570,
1.393550, -0.488910, 0.002960, -0.737120, 0.178510, -0.429250, -0.189450, 0.075010, 0.743740, 2.156270,
0.589580, 0.670660, -0.484470, 0.863610, 0.626790, -0.189780, 1.381310, 0.553470, 1.255570, 0.469460,
-0.233350, -0.605960, -0.053160, -0.343550, -0.648830, -1.064720, -0.301940, 1.824260, -0.663300, 0.352090,
-0.886540, 0.163190, -0.229450, 0.234310, -0.592700, 0.452840, -0.032020, -2.197950, -0.658630, -0.251160,
-0.624700, 0.239350, 0.063220, 0.443730, -0.074410, 0.079420, -1.127320, 0.059290, -0.809680, -0.527310,
-3.100220, -0.037080, 0.411960, -0.365110, 1.746680, -0.565970, -1.566440, -4.321630, 1.056450, 0.209020,
0.366010, 0.417910, -0.076300, -0.040730, -0.468080, -1.094300, -1.698910, -0.357170, -1.172920, -0.931940,
0.762560, -0.057300, 1.559600, 0.670180, 0.904520, -1.003960, -0.600050, 1.148420, 1.022260, 0.856290,
-0.145620, -0.016310, 0.242140, -0.438350, 0.607130, -0.300410, -0.803950, -0.167870, 0.651480, -0.578130,
0.866880, 2.768180, 0.994460, -0.111560, 2.567860, -0.034660, 0.607100, -1.971620, 2.750030, -0.065890,
-0.161580, -0.133780, -2.646060, -0.576080, 2.252680, -0.775170, 0.655910, 0.589620, 0.549270, 0.129080,
-0.504060, 0.676830, -0.296930, -0.377010, -0.404870, 0.980060, 0.483730, -5.801840, -0.244120, -0.375240,
0.927980, 2.889730, -0.197820, -0.993150, -1.296480, -0.312830, -1.673970, -0.828130, 0.166010, -1.071840,

-0.361170, -0.319970, -1.156790, 0.400150, 0.677180, 0.754970, -0.057330, 0.502220, 0.043540, -0.066790,
-1.270550, -0.527410, -0.566210, 1.160850, -0.259390, -0.339680, -1.419720, -0.843000, 1.715730, 0.442620,
0.407250, -0.336100, 0.499790, -0.529570, 0.328780, -0.937520, 0.553280, 0.133320, 1.218100, 1.367540,
1.048430, 0.284060, -0.184030, -0.419300, -4.845230, 0.471360, 0.762290, 3.500400, -0.037520, 0.337990,
1.534940, -0.848610, 0.400140, -3.075900, 0.940210, -0.140690, 3.595020, -0.838120, 0.340170, 0.085040,
-0.744880, 0.895190, -0.573020, 0.565340, 0.417470, 0.583940, 1.113250, -1.053510, 0.983530, -2.404600,
-0.845830, -1.348240, 0.559860, 0.661780, 0.492700, -1.666410, -1.193170, -0.228180, -0.978110, 0.714540,
-0.708350, 0.103260, -0.679000, -0.953290, -0.806810, -0.405800, -0.260910, 0.113930, 2.599780, -0.040400,
0.292860, -1.136170, 0.662030, -0.433790, 0.159330, 0.664250, 0.103960, 0.435060, -1.183910, -0.784270,
-1.420140, -0.703640, -0.838310, -0.960660, 1.011710, 0.537960, -0.991050, -0.112860, -1.054060, -0.027740,
-0.804520, 0.964070, 7.620000, 4.024040, -0.073120, -4.136010, -6.956990, -2.219850, 0.909060, 1.930830,
-0.698430, -0.963720, 0.064070, 0.336140, -2.283460, 0.603780, 1.491950, 0.035910, 0.252600, 0.300860,
-0.149620, -0.763560, 0.664650, -0.915230, 0.833120, 1.816080, 1.713090, -0.051940, 0.962150, -0.522430,
-0.122840, -0.789090, -0.205940, -0.638430, -0.518900, 1.152270, 0.304170, 0.931370, -0.345930, -2.906010,

-2.089160, -4.519810, -3.437520, 1.340580, -0.652570, -1.665440, 0.322800, 4.431610, -3.034300, -2.366450,
-2.026730, 0.201660, 0.405500, 0.733330, -2.141460, -0.884530, 3.906450, -0.250130, 0.549030, 0.736100,
3.205120, 0.695320, -1.299250, -0.318500, -0.740420, 12.095360, -0.300990, -0.112470, -16.404261, 1.882080,
-0.862290, 0.483100, -0.053430, -0.246490, -7.277230, 9.791560, -0.666680, -3.665190, -1.581430, 0.407260,
43.031059, 6.494470, 0.506600, -11.442340, -1.166790, 0.875750, -62.694118, 7.101190, -0.318450, 42.403870,
0.655350, 0.645250, 36.291130, 8.437060, -1.036500, 23.406540, -6.670700, -0.789390, -20.924431, -7.842420,
-0.201660, 65.838989, 16.601641, 0.758780, 13.729910, -2.959260, -0.963950, -12.366250, 1.091900, -0.730540,
-0.994230, 10.159580, 0.504650, -2.901440, -3.334110, -0.040380, 20.476400, 1.102770, -0.135200, -10.725110,
0.485560, 1.062010, -16.966049, -5.825870, -0.740900, 17.926241, -0.220680, -2.052040, -5.065700, -2.706790,
-0.881780, 1.844570, -2.477170, -1.239180, -6.548600, -0.345850, 0.241170, 3.026410, -2.477160, 1.698730,
6.432210, -4.562020, 5.354050, 7.492890, 4.944930, 2.182600, 1.383940, -1.139750, -8.145800, -0.260980,
0.232100, -3.113250, 2.991600, 0.834180, 2.417040, -1.463520, -0.242920, 1.044190, 1.377710, -0.197380,
0.969930, 0.432850, -2.489420, -0.019390, 0.263290, -0.214820, -3.662530, -3.161210, 1.760580, 1.704740,
-0.905970, -3.939320, -2.715300, 0.439450, 0.502640, 0.985090, 0.993930, -11.877750, -0.372430, -4.717070,

0.365610, 0.214960, 0.783190, 0.695190, 0.075940, 0.220080, -0.096150, 0.241530, -0.220760, -0.742560,
-0.524660, 0.248250, -0.656020, 0.397870, -0.380530, 0.304720, 0.692360, 0.007870, 0.334730, -0.708210,
-0.289230, -0.597660, -0.382530, 0.077640, -0.159950, -0.599980, -0.364830, 0.062020, 0.004920, 0.161320,
-0.784970, -0.179020, 0.116690, 0.426800, -1.199940, 0.155490, -0.564220, -0.113950, -1.290120, -0.866680,
0.606580, 0.137000, 0.446680, 0.157660, 1.193820, -1.225340, 0.991080, -0.373700, -0.608760, 0.573040,
1.929460, 0.966000, -2.232520, -1.687430, -0.068230, 1.805400, 2.437850, 0.538340, -0.142500, -0.318290,
0.387500, -0.213230, -0.220360, 0.985760, -1.112310, -0.572190, -0.251000, -1.296730, 0.546810, 0.166580,
1.831690, -0.107550, -0.197680, -6.490990, -1.994380, 0.635050, 2.989500, 0.465110, -0.343130, 0.772150,
0.413080, 0.549740, -3.130580, -0.080740, -0.207390, -0.425600, 0.240950, -0.416370, -0.097970, -0.004820,
-0.111950, 0.744380, -0.576060, 0.544840, -0.349140, 0.619370, 0.377640, -2.252530, -0.527210, 0.238730,
-0.107640, 0.780840, 0.382230, -0.609420, -3.280170, -0.427830, 3.389630, 3.664310, -0.855670, 0.414060,
-0.993930, -0.094460, -0.647920, -0.358220, -0.434420, -0.136870, -0.010360, 0.059950, -0.451670, 0.173890,
-0.754950, 0.340910, 0.096930, 0.185250, -0.236920, 0.610500, -0.858210, -0.178440, 0.367490, 0.076930,
0.120610, 0.864020, 0.414840, 0.247830, -0.082960, -0.502600, 0.722550, -0.037530, -0.111490, 0.120130,

0.380630, -0.803310, -1.631180, 1.409060, -0.487640, -0.802480, 0.826560, -3.714120, 0.035060, 0.986460,
2.064930, -0.656190, -3.943970, 11.451850, -0.157310, -1.590530, 0.994020, -1.471870, 0.814630, 0.619220,
-0.224440, -0.749430, -15.094120, 3.376560, -0.011120, 15.808080, -0.035360, -0.692610, -4.071760, -0.412630,
0.196100, -7.277600, 2.743210, 0.087350, -3.281380, 0.620850, -0.903630, -0.483780, -4.575000, -0.808800,
4.147360, 1.067590, -0.951350, -0.898960, -1.135570, -0.748530, 6.923890, 2.870940, 0.268960, -0.039710,
2.858820, 0.167290, -2.014410, -6.833770, 0.361470, -1.591320, -7.016520, -0.700020, 1.006930, 5.819090,
0.634130, -7.117090, 1.827330, 0.422500, 3.705380, 4.636430, -0.303750, -1.153350, 8.067370, 0.665640,
3.107070, 2.644420, 0.081610, -0.625420, 2.685220, 3.342250, -2.554920, 1.279960, 0.178430, -1.876630,
-0.836640, 0.501640, 3.915790, -0.975900, -0.781010, 1.788330, 0.726130, 1.114910, 9.777920, 2.620390,
-0.048660, -0.070260, 0.379570, -0.513310, 2.080050, 0.142160, 0.012700, -1.675210, -0.877650, -2.581500,
5.795930, -3.593310, 1.644600, -8.290380, 17.143641, 6.844250, -24.900391, -10.121280, 13.014030, 1.675970,
-0.263490, -3.025040, 2.100350, 0.549910, 0.560210, 1.319950, 1.433670, 0.284250, -0.774590, -0.431790,
-0.199220, -0.766930, -0.052040, -0.400530, -0.452670, -1.105370, 0.535860, -1.634860, 0.589240, -0.075740,
1.044840, -3.474140, 7.204140, -0.551760, -2.451210, -1.108160, -1.204520, -1.469770, 0.758660, -0.269670,

1.045690, 0.512080, -0.206680, -0.469730, -0.383810, 0.884670, -1.525160, -1.155960, -0.241430, -1.089680,
-0.424280, 0.191280, 0.953620, -0.275880, -1.423360, -0.286030, -1.575750, -1.523600, 0.389660, -0.298880,
0.591880, 0.163180, 0.453460, 0.679270, -0.148520, 0.373190, 0.130360, -0.936890, 0.363440, 0.745850,
0.532190, -0.216550, -0.282700, -0.181610, -0.542820, -0.650180, 0.633570, 1.200590, -0.820090, 0.271270,
-0.148710, -1.783030, -1.555980, 1.416320, 0.153530, 0.469390, -0.667080, -0.011860, -1.097770, 0.235910,
-0.468650, 0.749670, -0.341390, 0.796990, 1.225310, -0.529980, 1.518620, 0.141530, 0.629270, -1.576680,
0.764280, 0.933150, 0.851770, 2.155470, 0.709830, 0.025110, -0.725820, -1.224110, 0.548310, 0.363560,
1.152590, 0.855690, -1.416180, 1.091440, 0.310300, 0.176290, 0.457820, -0.140010, 0.350320, -0.794770,
0.641920, 0.729440, 0.020220, -0.780850, 0.589470, 0.096000, -0.132900, 0.111640, 0.570900, 0.616710,
0.656720, -1.128130, -0.135430, -0.635380, 1.794800, -0.532170, 0.915730, -0.892230, 0.643210, -0.727300,
0.414230, 5.931640, -2.414670, -15.653330, 9.558560, -21.210440, 7.349350, -4.255560, 1.766940, -0.225630,
0.314850, 2.188560, -1.004360, -0.678500, 1.120860, 0.393130, 0.273340, -0.089670, -0.063580, 0.767610,
-0.652350, -0.402760, 0.552480, 0.134110, 0.788490, -0.018510, 2.739320, -1.290480, -0.659390, -0.734900,
-0.507120, 1.140170, -0.638540, -0.287490, 1.676050, -0.211690, 0.143790, -0.439870, -0.365020, -0.846870,

-1.460720, -1.533430, 0.462310, 0.606420, -0.413100, -0.309740, 0.522420, -0.548780, -0.894040, 0.181280,
0.666380, 0.263920, 0.576150, -0.186260, 0.797450, -0.019070, -0.148290, -0.567990, 0.287950, 0.905590,
0.116400, -0.642420, -0.141180, 0.310590, 0.536870, -0.155050, -0.252320, 0.318440, -0.167930, 0.360390,
-0.582520, 0.418210, -0.591830, -0.186470, -0.684450, 0.007840, 0.097970, -0.433310, -0.649460, 0.220120,
0.022140, 0.584960, -0.032020, -0.062300, -1.230820, -0.491140, 0.437210, 2.137220, 0.607620, -1.218850,
-0.352550, -0.420900, -0.234240, -1.161360, -0.383540, 1.676190, -0.553640, -0.935450, 0.202770, -1.154790,
0.417900, 0.594890, -0.211510, 0.344530, 0.889000, -0.506650, 0.380570, 0.956360, -0.168120, 0.619440,
0.240470, 0.546150, 0.169730, 0.069390, -0.951520, 0.014090, -0.681490, -0.405290, 0.697000, -0.651240,
0.725400, 0.286770, 0.744200, -0.631280, 0.389800, 0.588940, 0.541770, 0.054520, 0.335380, -0.186680,
0.376570, 0.665430, 0.431060, -0.869700, 0.264480, -0.589570, 1.132350, 0.067000, 0.847210, 0.671840,
-1.460990, 1.193510, 0.768980, -0.737010, -1.094470, 1.003290, -1.127320, 4.058320, 1.615170, 1.159080,
0.232730, 0.881990, -0.036050, -0.298760, -0.504340, -0.837780, -0.678790, 0.051360, 0.063380, 0.804790,
0.082210, 0.530890, 1.186340, 0.868170, -0.465540, -1.710940, -1.407990, 1.111860, -0.252210, -0.335680,
-0.538520, 0.316760, 0.090720, 0.547090, -0.293350, -1.016820, -0.926150, -1.532820, -0.106410, 0.698760,

-0.009080, 1.781070, 0.564510, -0.244500, -0.531750, -0.095010, 0.398340, -1.373220, 1.082530, -0.431350,
-1.262590, -0.674310, -0.049960, -0.389310, 0.388360, -1.965000, 1.464360, 0.193590, -1.199340, -0.375760,
-0.622690, -0.323970, -2.204020, -0.366150, -0.105300, -0.119580, -0.891440, 0.523930, -3.053700, -0.160880,
0.019200, -3.281030, -0.918640, 0.022330, 5.773140, -1.152020, 0.272200, -1.550100, -0.140930, -0.712930,
1.341360, 0.391220, 0.459390, 3.288860, 0.868130, -0.642470, 3.208020, -4.002700, 0.496110, 0.345380,
0.495610, -0.586950, -0.313590, 1.299830, 0.858530, 5.028250, 0.101580, -0.884110, 0.187320, -0.119350,
-1.076140, 0.876880, -0.878420, -0.104920, -3.366650, 0.512170, -0.660080, 0.584670, -0.222020, -0.208880,
-0.854640, 0.846970, -0.857630, -1.795990, -0.605180, 0.284950, 0.217070, 0.390030, 0.656830, 0.243450,
0.148500, 0.464870, 0.770150, 1.553010, -1.046720, 1.821030, 0.214830, 0.326050, -2.600120, -0.627200,
-0.247280, 1.459090, 0.639730, 0.269020, 2.323970, 0.062430, 0.273010, -2.509650, 1.189880, 0.188550,
1.046060, 1.208050, -0.665330, -0.119150, 0.049760, -0.645990, 1.500780, -0.284370, 0.289470, 2.293860,
0.308940, -0.005500, -1.091930, 0.878130, 1.297660, 0.864240, -1.465070, -0.923550, 0.732330, -0.356600,
0.057880, 0.413800, 0.807920, 0.130420, -0.387780, -1.918600, -1.663390, 0.480060, 0.329710, -0.372370,
0.755820, -2.899000, 0.683570, 0.248860, 1.162930, -0.984850, 0.920690, 1.613490, -1.014330, 1.107380,

0.139260, -1.441940, -0.295270, -0.282840, 1.186990, 0.533350, -0.876650, -0.714680, 1.236410, 0.587630,
-0.274750, -0.346870, -0.620810, 0.246770, -0.274610, -0.358860, -0.408360, 0.647270, -0.033620, -0.148720,
-0.707270, 0.744930, 0.044250, -0.028510, -2.322190, -0.520470, -0.030990, -1.805250, 0.112280, 0.666510,
-0.284940, 2.364780, 0.230600, 0.609080, -1.029630, -0.814120, -1.839910, -1.065850, -0.867990, 3.829770,
-0.278320, -0.257370, -3.114410, 0.448370, 0.575830, -2.890000, -1.184960, -1.439630, 0.548070, 0.213630,
-0.066610, 4.806570, -0.192920, 0.223070, -5.110120, -1.441670, -0.439810, 15.657240, -0.761230, 0.238530,
-2.058760, -0.007770, -0.112340, 14.604940, 0.440130, -0.391370, -2.629820, 0.332890, -1.117960, 1.401240,
-0.442730, -0.655760, -1.019740, -0.735740, -1.359460, -2.962950, -2.412320, -0.314870, -0.668670, 0.340600,
-0.169930, 0.761820, -1.852650, 0.198310, -1.126340, 1.396650, -0.056410, -0.234540, -0.066190, 0.171290,
0.370800, -1.067960, -0.383450, 2.483190, 2.777270, -1.016780, -2.248070, -1.056900, 1.480820, 1.533050,
2.078220, 2.976170, -0.833240, -2.627730, -0.942620, 0.616680, 4.166460, -4.377110, 0.414420, 1.356370,
0.519910, 1.323590, 1.505320, -0.571470, 0.700990, 0.619110, -0.424610, 1.232220, -0.046420, -0.247960,
0.551890, 1.582530, -1.088650, -0.118450, -0.615990, 0.062070, -1.439810, 5.860190, 0.200820, 0.880270,
0.478260, -0.037350, -0.746990, 0.906130, 0.595510, 1.896140, -1.015760, -1.188280, 0.796190, -0.082310,

-0.266600, 2.144720, 0.613430, 1.035390, 1.333730, 0.421790, 0.171620, 0.291480, -0.500020, -0.908390,
1.833320, 0.472890, 0.177530, 1.064110, 0.568850, -0.175330, -2.438340, -0.513810, -2.601330, 0.795590,
0.363940, -0.236340, 0.701330, -0.783680, -0.197470, -2.813390, 1.220920, 1.917870, 1.135540, -0.008370,
0.010620, 0.152520, 0.149860, -0.710770, -0.874760, 0.618840, 0.494230, -0.450070, -1.752520, 1.596540,
-0.553690, 0.984070, 1.717550, 4.918320, -1.588290, -2.006090, -2.577460, 0.712170, -0.028170, 0.046320,
-0.245680, -0.561030, 5.380000, 0.446340, 2.993620, -19.094240, -2.652260, -0.399390, 9.825880, 0.504790,
-0.309040, -2.682810, -0.462760, -0.536610, 12.212380, 0.941870, 1.283270, 18.375290, 0.914420, -1.392350,
-3.504260, -0.057450, -0.267320, 8.708370, 0.300880, -1.262230, 2.901730, 0.872820, -0.607900, -5.633620,
0.553880, -0.734150, 1.037420, -0.642420, 0.027570, 3.843060, -0.122480, 0.613330, -2.185640, 0.791230,
-0.002330, 0.362940, -0.530470, -0.934730, -0.149110, -0.144720, 4.283760, -1.605370, 1.151050, -0.795600,
0.009560, -1.161530, -0.353760, -2.013150, 1.630800, 0.835220, -7.859700, -5.612040, 3.566890, -2.780140,
0.429070, 2.183920, 2.581220, 0.000800, -3.005650, -0.354180, 0.841690, -0.012630, 0.754160, -1.294430,
0.515250, -0.854670, 0.168530, 0.703710, 1.351490, 0.999150, -0.128270, 0.179020, 0.492510, 0.225230,
0.558290, -0.802850, 0.775420, 0.040770, -0.484620, 0.399370, 0.683640, 2.004710, 0.601600, -0.239060,

-0.511580, 0.382400, -0.503630, 0.809430, 3.780380, 0.575840, 1.538680, 0.126500, -0.750560, -0.433980,
-0.161830, 0.007270, 0.761220, 0.537500, -0.579260, 3.123610, -1.415920, 0.657290, 0.867260, -0.818600,
-0.998320, 1.791250, 1.342670, 0.677210, 3.573340, 1.155670, 0.888500, -0.146810, -1.388850, 0.713650,
1.572810, 2.086240, -0.055740, 0.039290, 0.297930, 0.651060, 0.272820, -0.496180, -0.977090, 1.215090,
0.369130, -0.552680, 0.386690, -4.443150, 0.368090, 2.024780, 1.603900, -0.395300, -0.585250, 1.289580,
-0.804590, 2.278000, 0.826920, -0.863020, 1.350900, -0.963090, -0.961050, 3.252790, -0.044980, -2.254200,
-0.609800, 0.669940, 0.660980, -1.481580, -1.086450, 0.586150, -0.306970, 0.394610, 0.797960, -1.119150,
0.115880, 0.975110, -0.433550, 0.778760, -0.619960, 0.846060, -1.413580, -0.454560, -1.356040, -0.706210,
-0.459990, -0.587780, 3.187900, -0.996860, 0.285640, -4.221000, 0.163850, -0.999030, 2.388990, -0.355400,
-2.799490, 2.527480, -0.187770, 0.957000, -3.097430, 0.267240, 2.423200, -2.110340, -2.435980, -2.551280,
1.808470, 0.436320, -5.637330, 3.906530, 3.020180, -0.373090, 8.551080, -10.741140, -3.285200, 2.997320,
-0.325780, -0.060560, -7.455540, -1.061620, 2.441200, 0.777520, -0.456810, -0.454540, -0.021110, -0.059450,
-0.676100, -0.377190, 0.482460, -0.809900, 2.496780, 2.437680, 0.033990, 8.246060, 0.007630, -0.870490,
-0.213400, 1.877880, -0.104430, -0.910940, 5.508900, 2.871290, 0.083800, -3.012870, -0.571130, -18.111660,

-0.643920, -0.788570, 0.203040, -0.527060, 0.667840, 0.341530, 0.286590, -0.423530, -0.656980, -0.660440,
0.161250, -0.803190, 0.466950, 0.554430, 0.664870, 0.351420, 0.247320, -0.835100, -1.247300, -0.535910,
-0.928250, -0.191240, -0.570570, -0.789990, -0.936000, -0.486560, -0.588750, 0.078390, 0.268180, -0.286110,
-0.064400, 0.530820, 0.778480, -0.953870, -0.619260, 1.773120, 0.923170, 1.068780, -0.188180, -0.202710,
-0.626410, 0.633160, -0.474200, -0.119260, 4.077280, 0.667940, 0.715160, -1.447150, 0.155470, -0.129480,
2.049660, 0.720210, -1.046720, 1.943020, -0.587720, 0.660700, 0.822920, 0.014420, -0.179830, 0.924260,
-0.195040, -0.116810, -0.022340, -0.508890, 0.103920, 0.174410, 0.212630, 0.471350, 0.656740, 0.640890,
0.629100, 0.891490, -0.701970, -1.131100, -0.605140, -0.340330, -0.328500, -0.823590, -0.542070, 0.093010,
0.051220, -0.653090, -0.007150, -0.710540, -0.346500, -0.265360, 0.316200, 0.393570, 0.043170, -0.586780,
0.058040, -0.100900, -0.800940, -0.409600, -0.334780, 0.899570, -1.090340, -0.952780, -0.309830, 0.304100,
0.346960, 0.415000, 1.006690, 2.937590, 1.058630, 0.281190, 0.262600, 3.091110, 0.144270, -0.743920,
-0.848030, -2.061490, -1.089300, 1.006980, -0.926750, -0.137430, -1.496220, -0.464770, 0.385750, -0.537420,
-0.464350, -0.146740, 0.409770, 0.592380, -0.422870, 2.634350, -5.599460, -0.284360, 0.870980, 0.732680,
0.920240, 1.647130, -0.560120, 0.413280, 0.103780, 0.999690, -0.246900, 0.311800, 0.195400, -1.113840,

418.140747, 418.336060, 417.623230, 418.492828, 417.305450, 417.349060, 418.773163, 418.852173, 418.561523, 417.964600,
417.624390, 418.323303, 417.672119, 418.501495, 417.620972, 418.205902, 417.038086, 417.086395, 418.989899, 417.710968,
417.189850, 418.682343, 418.162292, 417.914276, 417.864441, 417.077087, 417.080414, 417.954132, 418.857178, 418.566376,
418.419739, 418.429413, 418.702759, 418.749420, 417.763794, 417.975403, 417.710632, 418.891785, 417.618042, 418.745117,
417.603790, 418.049927, 418.542023, 417.445007, 418.614349, 417.481781, 417.022797, 418.421204, 418.461609, 144.758911,
418.662567, 418.700531, 145.196777, 418.529358, 418.158478, 145.747635, 417.452667, 417.561401, 144.933502, 418.316040,
418.498291, 145.602844, 418.935974, 418.089325, 144.424133, 417.371613, 418.361359, 144.613846, 418.975739, 418.689972,
145.902420, 417.922119, 417.495422, 145.039734, 418.321075, 418.481476, 144.051743, 418.401794, 417.887939, 418.818512,
417.110931, 417.809967, 144.530090, 418.357666, 417.694672, 417.029266, 417.566772, 417.444183, 417.289459, 418.201508,
418.910583, 418.028046, 417.625397, 418.277313, 418.720947, 418.746063, 418.625671, 418.981079, 418.549042, 417.707672,
417.291687, 417.452972, 418.070587, 417.738251, 417.977570, 418.194275, 417.023987, 417.038269, 417.361511, 417.427582,
417.679596, 418.447052, 417.503265, 417.905945, 417.997833, 418.881287, 418.220673, 418.690704, 418.941803, 417.492920,
418.630707, 417.632507, 417.219879, 418.980896, 417.096619, 417.044281, 417.835144, 418.928009, 417.459778, 417.215637,
417.236298, 417.510071, 417.754303, 418.462860, 418.314972, 417.287323, 417.500824, 418.910004, 417.948059, 418.693695,

0.431260, -0.127920, -0.510400, 0.614140, -0.195480, 0.386490, -0.813480, -0.524780, 0.128660, -0.347800,
-0.052330, 0.201480, 0.519900, 0.094660, -0.559890, -0.591310, -0.618710, 0.623460, -0.685940, 0.750280,
-0.144550, 0.230120, 2.815100, 0.923930, 0.921680, -0.571380, -0.580170, -0.254050, 0.055580, 1.154970,
-0.538910, -1.276100, -0.117100, 0.720270, -0.871100, 0.865450, 0.712420, 1.634910, 0.312990, -0.417060,
-0.328860, 3.313450, 0.027230, 2.373070, -0.175600, 0.495790, 2.087690, -0.463010, -0.761140, -4.135440,
1.496290, 0.466090, 4.306020, -0.360190, 0.897860, 0.842720, -0.125490, 0.492240, -0.658800, -0.345900,
-1.305190, 0.135540, 0.753490, 3.462310, 4.056250, -0.203390, -1.191290, -4.146940, -0.418270, -0.822770,
1.122460, -0.371410, -0.005700, -0.229860, -0.175200, 0.456680, -2.016840, 0.117370, -0.848740, 0.295460,
-0.718880, -0.985930, -0.461670, 0.485550, -0.705000, -0.038380, -0.369990, -1.131190, 0.272630, 0.384330,
1.053370, -0.897920, -0.878450, 0.164350, -1.184540, 0.261650, -0.669440, -1.061480, -1.068990, 0.014510,
-0.196600, 0.747570, 0.901430, -1.788200, -1.252130, -4.775540, -1.958640, -1.701290, 1.232520, -0.173840,
0.490300, -0.233190, -0.252670, 0.037540, -0.711160, -0.161110, -1.062190, 0.526290, 0.640880, 0.800440,
-0.509630, 0.389800, 1.115350, -0.703010, 0.226800, 1.273670, 0.225270, 1.835080, 0.323010, -0.627890,
-0.332790, 0.017210, 0.322250, 0.442730, 0.887280, -0.899650, 0.604150, 1.215930, -0.468030, -1.591160,

-0.995880, -0.558390, 0.106060, -0.487450, 1.163880, -0.251670, 0.956300, -1.245480, 0.279610, 0.393100,
-0.489540, -0.481120, -1.328780, -1.133640, -0.943530, 0.150350, 0.358480, -0.386930, -1.651240, -0.396690,
-0.987320, -1.434550, -0.059660, -0.275890, 0.821010, 0.192670, -0.388570, -0.360420, -0.658430, 0.164850,
0.172360, 0.280650, 0.270530, 0.151600, 0.651460, 0.533460, -0.500750, -0.512330, -0.486370, 1.259680,
1.616340, 1.177130, 1.072290, -4.357640, 0.009120, -0.858970, -1.289440, -0.203990, 1.135990, 3.527250,
-0.381900, -1.714950, -5.980620, 0.256000, 0.097300, -1.513150, 0.728670, -0.853210, 3.114080, -0.211200,
0.375000, -0.790660, -0.518370, 0.054110, -3.466420, 2.898540, 0.898630, -0.839190, 0.579230, 0.406600,
-0.508880, 0.747410, -0.214650, -1.704490, -0.238470, 0.220530, 0.518930, 0.209470, -0.402510, -0.002520,
0.306060, 0.564740, 0.179740, 0.432140, 0.343260, 0.609300, 0.980480, -0.598800, 0.877950, 0.533820,
1.509750, 0.548060, 0.610880, -0.449930, 0.479450, -0.302590, 1.108330, 0.222160, 0.276710, 1.660860,
0.753770, -0.782390, 0.334470, -1.782640, 2.161260, 1.363560, 0.593850, -0.244940, -0.071780, -0.413400,
-0.094140, -0.813290, -0.394700, -1.207520, 2.933310, -0.753210, -0.174740, 0.224040, -1.001680, 0.207470,
0.202420, -0.136380, -0.525510, -0.868560, -0.587920, 0.544670, 0.965680, 2.986940, -0.049360, 0.844340,
-0.454570, 1.316430, -0.314180, -0.270910, 0.394770, 0.648200, -0.532430, -0.916780, -0.711670, -0.330470,

0.278220, -0.407840, -0.309040, 0.256110, -0.512670, 1.037140, -0.643300, 0.243510, -0.508800, -1.219970,
-0.551080, 0.003860, 0.713040, -0.743190, 0.951570, 0.790090, 1.386180, -0.134530, -1.091990, 0.433670,
-0.633250, -0.818100, -0.226480, 0.710470, 0.692220, -1.074320, 0.418480, -0.184720, -1.258980, -0.505100,
-0.873900, -1.408080, 0.145650, 0.255870, -1.089350, 0.062320, 1.248800, -1.320120, -1.137960, -0.135530,
1.129560, -0.125010, -0.489910, -3.584110, -0.279940, 1.190290, -3.781500, -0.492090, 1.033390, 2.082790,
0.469980, -0.973790, -0.846300, 0.556700, 0.060430, -0.743360, 1.092190, -2.166960, 0.009210, 0.609560,
0.767710, -2.822020, -0.298970, 1.513380, -1.407630, 0.069690, -0.476550, 0.284060, -0.456180, 0.060990,
-1.181070, -1.007010, -0.790670, -0.408030, 0.546610, -0.529410, -0.450470, -0.653640, 0.651730, -0.651950,
-0.546590, -2.715360, 0.387110, -0.184980, 0.534830, 0.237920, -0.520880, -0.066010, -0.753650, -0.814250,
-1.941450, -1.535440, -0.415550, 0.881300, 1.598480, 1.209640, 0.695200, -1.810070, 0.194390, -1.419740,
0.324250, 0.727100, 0.870370, 4.801940, 3.286020, 0.028290, -3.213840, -0.329890, 1.542920, 1.475930,
0.076320, 1.007390, 0.730220, -0.487330, -3.665200, 0.450970, -1.741510, 0.517380, 0.752350, -0.818580,
0.648910, -0.382760, -0.740300, -0.344500, -0.042580, 0.236820, 2.351420, -9.171850, -1.340890, -0.716490,
-0.435310, -0.153610, 0.222310, 0.445060, 2.408570, 1.211910, -0.467850, 0.193840, 0.429070, -0.190000,

-0.206290, 1.094240, 0.622140, -0.695130, 1.231650, -1.021130, 1.234080, -0.026700, 0.457900, -0.760730,
1.037680, 0.641690, 0.100500, -0.785270, -0.174950, 0.410130, -0.461790, -0.620980, 0.799260, -0.257400,
-0.452930, 0.328140, 0.055130, 0.718210, -0.817230, 0.200760, -0.308010, 0.042820, -1.209300, 0.302570,
0.407860, -0.323970, -0.645920, 0.775420, -0.440330, -0.321120, -0.333470, 0.009990, 0.557860, 0.609520,
0.187950, -1.183290, -0.052340, 0.169340, 1.285080, 0.569590, 0.059800, -0.619290, 0.244930, 0.104270,
0.282570, 0.298410, -0.346040, -0.410530, -0.387680, 0.291310, -1.163640, 0.404710, 0.715170, -0.266280,
0.009120, -0.192080, 0.593240, -0.099810, 1.551660, -0.825730, 0.384900, -1.548130, 2.582910, 0.922470,
3.626680, 2.098640, 1.018420, -2.036370, -1.466000, -0.064990, -0.380830, -2.422560, 0.500160, 5.348320,
2.979230, -0.523670, -1.966360, -0.459570, 0.063150, 1.007180, -4.870820, 0.554180, 6.949500, 0.719900,
0.761080, -3.795720, 0.362250, 0.151340, -7.749610, 2.492180, 0.066510, 3.541780, -6.147110, 1.406940,
1.173230, 2.782330, -1.402270, -6.562540, -2.279170, -0.963400, -7.720960, -14.172000, -3.158260, 0.256730,
-0.463310, -3.550120, -1.972630, -0.918810, -0.149030, 0.002230, -0.311310, 0.487820, 0.439360, -0.590250,
-0.756430, -0.189960, 0.169920, 0.559630, -0.234380, -1.924960, 2.323750, -1.946580, 1.463450, -0.552550,
0.092150, -0.443570, -0.172680, 0.408180, 0.457340, -2.501500, 0.604010, 0.405690, -0.342400, -2.881980,

0.202630, 0.450260, -0.484810, -0.173490, -0.403610, -0.131170, -0.442320, -0.945940, 0.041780, 0.561220,
0.407950, 0.327270, 0.487110, 1.998440, 1.095720, 0.445250, -0.190180, 0.014320, -0.516810, -0.787180,
-0.201870, -0.397710, -0.812230, -0.297570, 0.728240, -0.594450, -0.259740, 0.383050, 0.529600, 0.451870,
0.032790, -0.275460, 0.710970, 1.024390, -0.866270, -0.305680, -0.653450, 0.456440, -0.912220, 0.126010,
0.040950, -0.166840, -0.467820, -0.190170, -0.058370, 0.319290, 0.993170, -1.092590, 0.318650, -0.531690,
-0.837480, -1.920810, 0.216750, 1.430820, 1.779780, 0.335350, -2.094290, -0.941010, 0.919860, 0.390450,
-0.256600, -1.672040, -0.938520, -0.034200, -0.865120, 0.487100, -0.674330, 0.061410, 0.835480, 1.331340,
0.184710, -0.334570, -0.806470, -1.386040, -0.301410, 0.269300, 0.838750, 0.043870, -1.054720, -0.330790,
-0.716200, -0.003260, -0.965880, 0.629070, 0.383350, 0.377360, 0.204710, -0.192420, -0.220870, -0.563740,
0.211290, 0.125770, -0.534580, -0.867670, -0.787530, -0.001780, 0.797020, -0.056980, -1.465930, 0.151720,
-2.538960, 0.332550, -1.231770, 1.729470, 1.509700, -2.179980, 0.198500, 2.701080, -0.381630, -0.054810,
-0.211420, 1.734210, -1.049270, -1.083680, 0.510680, 0.107960, -2.671350, 0.900630, 0.358450, 0.243860,
0.204640, -0.229740, 0.206070, -0.795620, 0.762400, 0.564040, 4.977640, -5.611510, 0.387300, 0.070230,
0.446490, 1.677650, 0.030690, 0.611330, 0.044620, -0.384410, 0.440420, 0.139920, 0.578000, 0.811820,

-1.420630, -4.393310, -0.395360, -0.942210, -0.621360, 0.648230, -2.928240, 3.978270, 0.668050, -1.418680,
0.791990, -1.098290, 2.447130, -2.171500, 0.170770, 0.901080, 1.060290, -0.363850, -0.119260, -2.087090,
-0.488870, -0.402060, -0.349320, 0.558330, 0.980440, -1.409680, 0.696780, -1.893660, 3.017400, 0.771160,
-0.177980, -1.612780, -0.678560, 0.361560, -0.555580, 0.611900, -0.002570, 2.225390, 0.919380, 0.583980,
4.764670, -1.127010, -1.012890, -2.403650, 2.410970, -0.911270, 3.221380, -2.169820, -0.686500, -0.198920,
1.979060, -1.053470, 1.063670, -2.769610, -1.008780, -6.033500, -0.737250, -0.215540, 0.512490, 6.233070,
0.264380, 1.321530, -8.003480, 0.106340, -1.187290, 2.122990, -0.443060, -3.203620, 28.687599, -0.305130,
0.352640, -12.250460, -0.442400, -0.365850, 31.210699, 0.003370, 0.539280, 5.075100, 0.487860, 5.627410,
0.585510, -0.674170, -3.968970, 24.004930, 0.130490, -0.353450, -5.042480, 0.170700, -0.400210, 2.112630,
-0.837550, -6.843780, -4.383180, 0.615730, 5.410200, 8.463840, -0.219340, 6.509960, 1.380560, 1.362830,
2.640790, -3.075040, 3.244880, -7.863900, -1.604070, 2.140710, 0.846620, 4.820660, -4.928760, 2.006860,
0.054090, 0.392010, 0.948900, 0.736950, 0.078780, -0.478060, 1.223410, 1.545440, -0.870090, 0.396880,
-0.871010, 0.513120, -0.859240, 0.391480, -0.210970, 1.272850, -2.259420, 1.508460, 0.393690, 0.327430,
-0.177010, -0.557860, 0.346010, 1.010460, -3.205990, -0.937820, -1.035910, 1.194640, 0.416990, -3.079490,

2.300400, 0.451800, 0.418520, 1.281790, -6.960810, -1.060320, 0.084220, -1.153990, 0.153930, -5.070630,
-0.827110, -2.617880, -0.459780, -0.228080, -1.553320, 2.507430, -2.098140, 3.961170, -5.058110, 5.329170,
1.416990, -2.317230, -2.162940, -4.909650, -1.115330, -5.605100, -2.312120, 7.051270, -0.296690, 1.056540,
-0.478240, 6.755500, -0.492520, -5.114720, 9.810530, 0.904510, -1.714940, -3.200320, 0.778330, -2.197080,
-4.950480, -0.025030, 1.644160, -4.055170, -1.557510, 0.401610, 1.107160, -0.294090, -6.862730, 4.814210,
-3.254950, 4.595090, -0.307600, 4.016170, 4.911670, -0.378000, -1.240900, -2.643050, -1.491590, 0.696190,
0.215100, 1.216130, -3.247790, 1.428410, -2.836010, 0.731560, 1.815840, -0.354570, 0.862930, -0.708110,
0.147370, 3.664600, -1.610860, -0.550070, -1.623050, 0.677260, -1.765580, 2.418720, -0.375200, 0.686920,
-0.100800, 0.252000, 6.573580, 0.242820, 0.099660, 0.186220, -1.331390, -0.059780, 0.557190, -4.075250,
4.041480, -1.995500, 2.727350, -0.330810, -1.319400, 3.068960, -0.837960, 2.706240, 0.853230, -1.120120,
-1.272440, 1.891570, -2.581040, 4.133240, -4.275720, 11.324230, 8.571600, -10.303550, 26.968000, 3.252480,
2.332800, 5.212810, -1.595090, 1.023710, -1.283590, 0.022410, 1.613260, -2.256850, 0.992150, 0.158070,
-0.476490, 0.477880, 0.863390, 0.500180, -0.525930, -0.979310, -4.419720, 2.768250, 0.402320, 0.371770,
-0.043960, -0.295330, 0.493200, 0.610670, -0.896080, 1.523590, -1.028190, 5.357590, -1.886910, -0.163680,

-0.416460, -0.043290, -0.091880, 0.827410, -1.059760, 0.930720, 0.939350, 1.645870, 0.894830, 1.067340,
1.283540, 0.063720, 1.613520, -2.515150, 0.971880, 0.364310, 0.947950, 0.152590, -0.963890, 1.233180,
-0.459720, 0.592620, 0.570590, 0.456620, 0.648770, -1.324900, 0.461490, -0.591820, 0.693520, -0.277430,
0.928060, -1.704940, 0.122220, 0.644660, -0.352520, -0.469160, 0.193810, 3.136000, -0.611680, 0.642120,
0.584510, -0.807000, 0.852630, 3.114680, 0.739120, 0.813510, -4.409470, -1.084170, -0.746910, -0.534440,
-0.337660, 0.179730, -0.403490, 0.488130, 0.657350, -1.160000, 1.029970, -0.027320, 0.147520, 0.163260,
-2.802430, -0.249640, -2.353520, 0.259550, -1.230680, -0.692440, 0.020330, -0.644770, -2.337590, -2.261210,
0.480420, -0.278120, -0.178350, -0.496650, -0.424380, -0.591780, -1.088780, -1.057650, -0.153320, -0.222760,
-0.826740, -0.755010, -0.551080, -0.529600, 0.952310, 0.452380, -0.572260, -0.610680, -0.826110, 0.138160,
-0.213310, 0.206920, 0.120430, -0.680450, 0.046340, 0.539650, 0.361110, 0.246350, -0.379630, 1.680960,
-0.943600, -1.662570, 2.388030, 4.288130, 2.343840, 2.048020, -2.719690, -0.219460, -3.258220, 0.021020,
-0.516360, -0.803850, 0.521330, -0.375910, -0.245920, 0.351970, 1.105950, -0.809110, 0.619690, -0.682120,
-0.417290, -0.833020, 0.826760, -0.210650, 0.558730, -0.396940, 1.974920, 0.140780, 0.196470, -0.578820,
0.043810, 0.260250, 0.553610, 0.134560, -0.764000, -0.119560, -0.786460, 0.200610, 0.498230, 1.444850,

-0.529060, 0.220930, 1.610130, -0.332100, -1.780720, -0.691040, -0.767860, -0.433940, -0.382130, 1.512890,
-0.953860, 0.788880, 0.071040, 3.153570, 0.283400, -1.285730, -3.218020, 0.093530, -0.582650, 0.521250,
0.469460, 0.598210, 1.457700, -0.791140, -0.835640, -1.458920, -0.771480, 1.010010, 1.138290, 1.290110,
-0.294650, 0.859660, -0.283960, -0.458960, -2.424380, -0.655860, -1.022110, 2.085850, 0.817020, 0.647400,
1.088100, 0.691920, -0.346450, -1.951430, 0.191910, 0.100150, 2.908340, 0.210090, 0.158360, -0.673810,
-0.063660, 1.032720, -2.999290, 0.333870, -0.018390, 3.521750, -1.451900, -0.635300, 0.563350, 1.793090,
1.888550, -3.313540, 0.677310, -4.756080, 0.399650, -0.410350, 1.509100, 0.342020, -0.402880, 2.078520,
0.321640, -0.455170, -4.424220, 1.588600, -3.080750, 0.279040, 0.173100, -0.100540, 3.271210, -1.971150,
-2.094260, -1.249300, -1.017990, -0.448040, -0.720500, -0.305790, -0.040560, 0.640360, 0.675740, -0.271070,
-0.881310, 0.666800, -1.103690, 0.683980, -0.644240, 1.432160, -1.269330, 0.862210, 0.569510, 0.442990,
-0.297920, 1.242870, -0.280980, -3.551080, -11.414700, 1.652630, 1.634230, 7.391220, 0.856900, -1.798910,
-0.098470, 0.768320, 0.531070, 0.437150, -1.981780, 0.457450, -1.219570, -0.335580, -0.320830, 0.236410,
-0.283060, 0.923020, -0.087110, 0.450980, -1.067090, -0.634440, -1.696650, 0.237450, 0.209870, 0.926380,
0.086230, 0.634620, 0.853420, 1.081240, -1.549460, -1.581090, 0.445660, 1.526680, -0.699670, 0.663860,

0.023800, 2.449980, -0.752970, 4.872790, 2.845510, 0.691820, 0.536940, 1.177770, 0.374190, -0.320530,
-5.128660, 0.456350, 1.656950, -0.892260, 0.545010, -7.533980, 0.906400, -1.100410, -1.111750, -0.989930,
0.224170, 11.116160, 0.625650, -0.120700, -0.470250, 1.716630, -2.370410, -6.551480, -0.706620, 0.650070,
-0.774000, 0.370580, -0.534660, 4.918890, 0.242090, -2.823460, 1.783770, -1.035910, -0.004270, 2.915270,
-0.663590, -1.179400, 3.477770, 0.174430, -1.237590, -13.006140, -0.567120, 2.114920, -1.352770, -0.312910,
1.051310, 5.092490, -1.701690, 1.306440, 0.449470, -2.150530, -0.441770, -4.227620, -1.070220, 1.591920,
0.110340, -1.856650, -3.282900, -9.620110, -1.400450, 1.077930, -1.928970, -1.279930, -1.907940, -11.933940,
-0.556210, 0.676000, 29.802010, -0.380730, 2.285410, 23.792770, 0.434260, 1.086530, -8.409820, 0.133600,
5.024220, 72.768959, -0.236050, -2.382420, -6.274360, 0.166740, -0.234170, -15.236500, -0.291730, -2.488780,
-5.382650, 0.736380, -2.874170, 31.863569, -0.364330, -0.533130, 4.682910, -1.703750, -0.166790, 1.027970,
0.245170, 5.155850, 5.567950, 8.414350, 13.693790, -9.659810, 8.725240, -14.230050, -2.146900, 3.667740,
0.372670, 0.747500, -1.862570, 0.093840, -6.431620, 0.495040, -0.073340, -0.780780, 0.354860, -2.844830,
0.863310, -2.249850, -0.301840, 0.185280, 1.398120, 2.464600, -0.930330, 1.883020, -1.730610, 0.098580,
2.566550, -5.619480, -0.604720, 0.280550, 1.991090, -1.431760, -1.772100, 1.339650, 2.518230, -1.194210,

-1.078130, -2.238650, -1.433700, -0.371780, 0.481630, 0.723330, 0.392830, 1.861300, 0.655640, -0.366630,
-1.121150, -0.523900, 0.693600, -0.090430, -0.348860, 0.216840, 0.394480, -0.892820, 0.482150, -0.345240,
0.964220, 0.262570, -0.140430, -0.340730, -0.703670, 0.711060, 0.089000, -1.728460, -2.090970, -0.502590,
-0.614740, 0.440050, 0.078480, -0.760940, -1.125530, -0.430570, 0.609880, -0.254980, -0.435020, -0.622570,
0.280170, 0.690150, 0.489030, 2.074810, -0.991510, -0.804820, 3.048370, 0.058240, 0.073460, 1.058740,
-1.002290, 0.425950, -2.528000, -0.067230, -0.054460, 1.461630, -0.134110, -0.014440, -1.104870, 0.260070,
-0.716880, -1.756570, 0.157070, 0.178660, 0.664960, -0.666110, 0.703470, 0.151800, 0.017170, 0.295580,
-1.278390, 0.861100, 0.175400, 4.671310, -0.978600, -0.377110, 0.304320, -0.645110, -0.233990, 0.818820,
0.329010, 0.774910, 0.270860, 0.208260, -0.221970, -2.229510, 1.084530, 0.194120, 0.804300, -0.566950,
0.256580, -1.056910, 1.021000, 0.119460, -0.032850, -0.953480, -0.804670, -0.233510, -0.718800, 0.399360,
1.646960, -2.362930, -3.836000, 1.352550, 12.502090, -3.655030, -12.834780, 4.101410, 3.718400, -1.376970,
0.131500, -0.336930, 1.156100, -1.053470, 0.687040, -0.306170, -0.867740, -0.883230, -0.303370, -0.159340,
0.248610, 0.413760, -0.273890, -0.555950, 1.956230, 0.167390, -0.973970, -0.269920, 0.017770, -0.037520,
0.576100, -1.262690, -0.496560, -0.926790, -0.057270, -0.897460, -0.184410, -2.407580, 0.639170, 3.523660,

-0.818790, 0.081580, -0.512910, 0.200520, 0.176020, -0.538140, 1.258690, 0.844020, 0.891380, -2.552340,
-0.860960, 0.899340, -0.985680, -0.553700, -0.597150, -0.787590, -0.438620, -0.035410, 0.063810, 0.419630,
0.292980, -1.508230, 0.012680, 0.776080, 1.001230, 0.088130, 0.619720, -0.324240, 0.265790, -0.274470,
2.693200, 0.848320, 1.101480, -1.607910, -0.165890, -0.739700, -1.791200, 0.059680, -0.616350, 0.245810,
0.233060, 0.771270, -0.777570, -0.526610, -1.111390, -0.103730, 0.808730, 0.595380, -0.321660, -0.724530,
1.355000, 0.243350, -0.093960, -0.308390, -0.648380, 0.607660, 0.220560, 0.970110, 0.805950, 0.651050,
-0.624980, 0.346320, 0.055950, 0.663400, -0.447780, -1.120420, 0.170320, -0.648720, -0.257670, -2.215910,
0.046710, -0.551020, -0.007990, -0.385720, -0.661070, -0.442680, -0.156030, 0.283730, -0.525190, -0.887490,
-0.921330, 1.278290, -0.021950, 0.065690, 0.301100, 0.710880, 0.426770, -1.621980, 0.458140, 0.638910,
1.207040, -0.877020, -0.666450, 1.020480, -0.682390, 0.287550, 1.220340, -0.509370, -0.189200, -0.656420,
-2.104540, -2.186630, -2.208380, -5.731930, 1.712660, 3.833720, 1.734170, -1.013520, -0.077880, -2.314630,
-0.716730, -0.899310, 1.164090, 0.504760, -0.963690, 0.078710, -0.686800, -0.116760, -0.792430, 0.708720,
0.649400, -0.032750, 0.912950, -0.383730, 0.368730, -0.470230, 0.131340, -0.350780, 0.035930, -0.839030,
-0.121890, 1.010920, 0.455900, 0.927380, 0.344450, -0.526220, 0.012050, 0.767490, -0.038160, -0.170560,

0.391920, 0.000060, 0.588060, -1.137550, -0.482330, 0.035720, 0.216330, -0.597320, 0.843860, -0.254490,
-0.265690, 0.151890, -0.865780, -0.468330, 0.056130, -0.142940, -0.926380, 0.751710, -0.842780, 0.047130,
0.153750, 0.246540, -0.022930, -0.126580, 0.063890, -1.267000, -0.474460, -1.294310, 0.191830, -0.312420,
0.282240, -0.520580, 0.348770, -0.431880, -0.446720, -1.074860, 0.716010, -0.280370, -0.349640, -1.276870,
-0.721420, -0.291370, -0.175580, 0.012970, -0.533670, 1.068740, 0.655110, 0.669500, -1.756760, -0.940270,
-0.062810, 1.228230, 1.024170, -0.475570, 0.579490, -0.247060, 1.292370, -0.568390, 0.368720, -1.211250,
1.899470, 0.038280, 0.516410, -0.366250, 0.343610, -0.224460, -0.484070, 0.309800, -1.101740, 1.169140,
0.385710, 0.342670, 0.151830, 0.093470, 0.235300, -1.243930, -1.569520, -0.775150, 1.286760, 0.218630,
-0.046500, -0.644080, 0.699500, 0.358040, -1.591800, -0.927480, -0.878640, 1.528150, 0.061760, 0.758290,
0.465870, 1.719820, -1.136850, -1.489820, -1.494530, -0.021890, 0.797970, 0.024740, -0.002850, 0.422170,
-0.076250, 0.599230, 1.835760, -0.448420, -2.604690, 0.200980, 0.019880, -2.686650, -0.516530, 0.013310,
0.286740, 1.679820, -1.260980, -0.413130, 0.728070, -0.288620, 0.900400, 0.812180, -0.381170, -0.387280,
1.052950, 0.169220, 0.495860, 0.096550, 1.137330, -0.592950, 2.733090, 1.890630, 0.731560, -0.691740,
-0.688500, -2.387340, 0.651330, -0.017850, 0.340670, -0.227520, -0.470800, 2.272530, 0.575390, -0.489990,

-0.891430, 0.281770, 1.157130, 0.096970, -1.022590, -0.286990, -0.258370, 1.552950, -0.381640, 0.677580,
-0.185610, -0.092340, 0.671340, -0.370930, 0.642540, -0.581600, 1.542910, -0.145000, 2.456890, 0.694370,
0.697740, 0.113940, 0.235180, -0.678300, -0.062820, 0.238480, 0.306690, -0.112540, -0.719490, 0.761530,
-0.447280, 0.792670, 0.277410, -0.504200, -0.549070, -0.082820, -0.137410, -0.592980, -0.132440, -1.195280,
-0.208400, 0.057250, -1.162160, -0.244880, 0.484720, -0.708360, -2.453510, 1.095520, 0.544660, -1.919050,
-0.006220, -1.051480, 0.119880, -1.238440, -0.969660, 0.835730, 1.312010, 0.390430, 0.429400, -0.627510,
-0.457110, 0.167190, 0.291080, 0.158130, -0.962710, -4.128220, 0.085550, 0.276250, -0.268840, -1.295550,
-0.144200, -0.292620, -0.996910, 0.621010, -2.356070, -0.112530, -0.219490, 0.393700, -0.006970, -1.526480,
0.679950, -1.685470, 0.494520, -0.008080, 0.177140, -0.897710, -0.531050, 0.928220, 0.421520, 0.821070,
-0.545430, 0.660860, -0.180170, -0.192730, 0.004770, 1.403000, 0.557630, 2.297330, 0.400950, -1.106070,
-1.746640, 0.284660, 0.563370, 6.954750, 3.679980, -2.489280, -2.787140, -3.533300, 0.968480, 1.313990,
-0.353730, 1.275450, 1.652660, -0.157670, 2.266190, -0.024900, 0.131360, 0.172950, 0.000650, 0.411620,
0.563760, -0.012610, -0.430270, -1.050000, 0.044780, 0.624130, 1.206920, 2.365000, -0.123950, 0.381460,
-0.680690, -1.832220, -0.826430, -0.371540, 0.099740, 0.498100, 0.036990, -1.930970, -0.492020, 1.968230,

-0.077210, -1.793180, 1.019350, 0.160270, 0.030870, 0.930880, 0.358610, 0.555580, 0.670600, -0.065830,
0.550060, -0.377740, -0.346240, 0.405570, -0.632190, 0.555920, -0.076670, 0.215660, 0.508270, -1.903070,
-0.356000, 1.440010, 0.369910, -0.660550, -0.317730, 1.302060, 0.502410, -0.655860, -1.006920, -0.389690,
-0.233890, 0.526520, 0.119600, 1.113320, -2.247700, -0.472670, 0.412610, 3.635600, 0.543960, -1.047480,
-0.297330, -0.956440, -0.829180, -3.210260, 1.684000, 2.457940, 0.486320, -0.775890, 0.915570, 3.083540,
-1.222900, -1.346970, -6.821250, 1.601710, -0.503680, 10.943610, -2.056970, -0.181320, -0.755480, -0.449840,
0.038860, 13.359890, -0.385240, 0.921140, -1.429910, 0.365660, -1.141880, 6.995460, -0.643280, -0.171970,
9.905960, 0.848920, -0.530680, 22.439289, 0.598650, 0.250330, -13.170470, 0.453490, -0.808820, -2.681370,
-0.300600, -0.744090, 6.190470, -0.966450, -0.646590, -6.709810, -0.276810, 0.500160, -0.447840, 1.439660,
0.843570, 6.684980, -3.156970, 0.830190, -3.341490, -1.030980, -0.556930, 5.111490, 4.873020, 0.127560,
-1.031090, 0.542200, 10.906060, 4.068500, -1.705050, -7.158120, -6.005520, 3.520040, 2.026040, 4.407940,
-0.549400, 6.393420, -0.476810, 0.858490, 1.127890, 0.537550, -2.393710, -0.607610, -0.230600, -0.833340,
-1.056700, 0.337130, -0.795670, -0.844680, -0.712330, 1.853050, -1.041290, -3.637290, -1.279580, 1.104720,
0.962920, 1.991220, 0.819370, -0.701240, -2.911450, 0.968610, -0.089190, -4.200140, 0.385730, 5.075840,

-5.812300, -6.015330, -0.058880, -3.579290, 4.195720, 0.353190, 0.665410, 0.006320, -0.342480, -1.036510,
1.130540, -0.067380, -0.605880, -0.340020, -0.441540, -6.557170, -0.813060, -0.281100, 1.447770, -2.743390,
1.377230, -1.259920, 0.389590, 0.139160, -8.653070, -1.956010, 1.007230, 17.134109, 0.717120, 0.090650,
-14.622490, -0.387480, 0.363530, -6.591890, 2.256210, -0.503420, -8.148570, 2.237180, 0.619850, 4.919730,
1.473320, -0.002700, -12.683890, 1.220530, 0.949330, -10.258790, 0.618380, 0.326560, -6.001580, 0.788300,
0.248430, 1.750200, -0.723060, 3.186000, -8.111200, -0.839930, -0.634770, 3.267820, 0.778040, -0.433920,
1.258480, -1.012330, 2.158980, -21.071970, 0.311830, -0.311710, 10.477120, 0.743370, -0.698980, -1.804600,
-5.854850, 1.590080, -0.250270, 4.263530, -0.249540, -2.783250, 2.068060, -0.510480, 3.035100, 3.406650,
0.010620, -4.265680, -1.239350, 1.512480, 0.234480, -7.392880, 0.646530, 1.951070, -4.171030, 0.682390,
-2.436630, 2.585060, 2.011860, -0.402580, -0.525380, -3.265040, 0.910170, 3.123290, -1.001370, 1.591050,
6.442880, 2.614370, 2.705680, -3.769400, -2.868360, -4.164740, -6.579710, -1.791260, 1.720680, -0.306370,
0.007840, 1.534260, 1.661630, -0.986770, 2.388530, 0.533020, 1.757340, 1.964430, -3.681490, 0.582050,
-0.783290, 4.169240, 0.531930, 0.409590, 2.418450, 0.178110, -0.693810, -1.885310, 0.701100, -0.229290,
0.220250, 6.182730, -2.856210, -1.108730, 0.599060, -2.749100, -2.507200, -2.687430, 0.056980, 2.790380,

0.527800, 0.202490, -0.531790, -1.913520, 0.445900, -3.031630, 0.419530, -0.053660, -0.299270, 0.772250,
-0.501710, 1.094710, -0.382680, 0.620880, 0.522500, -2.043040, -2.086930, 0.874330, -0.907500, -0.786560,
-0.206310, 3.759770, -2.528080, -0.909340, 1.285980, -0.776830, 0.782820, -5.119360, -0.057840, -0.035740,
0.346150, 2.261420, 0.232700, -1.053890, 0.212830, 0.218840, 0.073050, 0.384680, 1.448090, 0.154860,
0.796270, -1.164720, 0.392840, 0.646230, -0.937150, 0.447230, 0.761990, 0.243120, 0.334840, -0.321160,
-0.749170, -0.364070, -0.952300, 0.948540, 9.386240, -0.489300, -0.666660, -0.329940, -0.706890, 0.063320,

-0.241460, -0.633370, 0.447650, -0.171560, 0.081850, 0.303880, -0.699270, -1.126670, -0.317380, 0.450230,
-0.804200, 0.231210, -0.950030, -0.072830, -0.277410, 1.660830, -23.117571, -3.442160, 0.271670, -0.132920,
0.617460, 4.212840, -0.429030, 0.317320, -1.069500, 0.307110, -0.633410, -4.897690, 0.634210, -0.189000,
-1.923290, -0.243330, -0.745840, 2.789630, -1.221650, 1.008570, -0.568370, 1.252410, 1.628880, 0.206930,
-3.261810, -1.466660, -0.699680, 1.056050, 0.926570, -0.401520, -0.831330, -2.583850, -0.180170, 0.098220,
0.080970, -0.553590, 1.535880, -0.586970, 2.597410, 1.615880, 1.439660, 0.375960, 0.415570, -0.160770,

-1.050770, -0.238720, -2.249670, -0.693290, 0.810470, 0.187700, 0.229830, -1.267550, -0.535940, 0.923620,
-0.072550, -0.261680, -0.251540, -0.814850, -0.374260, 2.063390, -1.770810, 2.716250, 0.807980, -0.333890,
0.965100, 1.990240, -0.441870, -0.225530, 3.825550, -0.822380, -0.297270, 0.148870, -0.073480, -14.790340,
1.667080, -0.976900, 1.813830, -1.300400, -1.616840, -3.340540, -0.112090, -0.893660, -0.982340, -0.402520,
0.927950, -0.367950, 2.395530, 0.299270, 0.354020, 0.822380, -0.518120, 1.821360, 0.524040, 0.912790,
-0.162550, -1.996370, 0.108970, 0.022050, 7.784520, -8.027930, 0.583810, 0.359630, -0.224470, -0.384600,

0.216070, -10.703280, 5.483550, 0.063060, -40.553329, -0.726240, 9.528580, 1.421580, 2.208930, 2.325730,
-0.431480, -0.975890, 2.427800, -0.209140, -2.241410, -127.216820, -6.176860, -7.437340, -15.738730, -2.032190,
1.306030, 1.539840, 2.070190, -0.499490, -0.883550, 0.273670, -3.586980, 1.350930, 0.781560, -1.538140,
10.713120, 0.861290, -57.724560, 0.341750, -1.127700, -2.169850, -5.869450, -0.050570, 1.455060, 0.666160,
0.092980, -2.247390, -45.813850, -0.050480, -1.603990, -1.000880, -0.977660, -7.720200, -0.261350, -0.237480,
0.571540, 1.186920, 0.171770, 0.385270, -35.633461, 1.247060, -0.832770, 0.143360, -2.915700, -0.374870,

-1.501560, -1.476890, 2.522080, -0.258310, -2.428700, -0.656050, -1.392800, 0.035990, 0.378600, -0.435080,
0.679730, 0.664540, -0.105150, 0.610810, -0.175340, 2.508440, 3.071740, -7.241990, 0.153720, -0.569530,
0.088570, 4.083390, -0.761260, -0.652740, 0.147080, 0.428300, -1.319720, -0.088940, 0.492900, -0.736620,
-5.706280, -0.562060, -0.568880, -3.529650, -0.481860, 0.964220, 0.125500, 0.785930, 0.735500, -0.008030,
0.681110, 0.380380, -0.467680, 0.622910, -4.451590, 0.918820, -0.035570, -0.658120, 0.361680, 2.657950,
0.487570, 0.493730, 0.458270, -0.912050, -8.173240, 1.460520, 0.403910, -0.074270, 0.477230, 0.319970,

-0.601730, -0.050680, -1.287730, -0.632680, -1.448180, 0.716150, 0.395140, 0.495300, 0.178400, -0.680580,
-0.049730, -1.686980, 0.777940, -1.007320, -0.211440, -4.221270, -2.238940, -1.211880, 0.200720, 0.170790,
0.522270, 0.436720, 0.475480, -0.834330, 0.274750, -1.795510, 0.914610, 0.348200, 0.230580, 1.917080,
-1.467890, 0.248640, -0.250450, -0.200760, -0.220070, -0.019950, 0.115840, -0.089480, -0.089420, 0.959880,
0.173950, -1.494020, 5.158870, -0.849670, -0.086110, 0.018000, 0.900810, -0.763780, 0.164270, 0.325230,
-0.644570, -0.175150, -0.064330, -0.053870, -0.185560, 1.723860, 0.606550, -0.514490, -0.522710, 0.784900,

-0.074180, 0.445400, 1.263070, -0.385230, 1.959680, -0.483100, -0.451620, -0.449180, 0.164210, 0.419980,
0.570580, -0.069720, 0.469430, -0.539620, -0.646130, 2.433590, 1.241120, 0.382100, 0.466690, 0.350310,
-0.013850, -0.957750, 0.411600, 0.148540, -0.171040, 1.579680, -0.480080, 0.572990, 0.569350, 1.504700,
-0.311800, -2.589180, 1.521130, -0.720580, -0.174840, 0.346650, -0.345560, 0.362340, -0.833850, -0.632830,
1.069830, 1.711040, -0.701130, -0.806290, -0.378410, 0.620430, -0.984300, -1.308580, -0.088890, 0.540490,
0.134540, 0.288640, -2.800160, -1.674990, 6.616380, -1.906540, 0.767090, -0.823820, -0.884990, -1.246020,

-0.917440, -0.233330, 1.561600, 0.837130, -0.914260, -0.287480, 2.111100, 0.115210, 0.756980, -0.853130,
0.168150, -0.206880, 0.179690, -0.938330, 0.452830, -0.243330, -6.088140, -4.422260, 0.737540, -0.297080,
0.018590, -0.931230, 0.330630, 0.328410, -0.001050, -2.182290, -0.491660, 1.225550, 0.601120, -1.852790,
-2.712080, -1.368360, -1.884480, -1.068550, 0.216380, -0.506570, -0.417140, -0.412540, 0.894390, 0.010170,
0.748930, -0.671260, 0.513680, -0.435570, -1.520410, 0.104050, -0.269590, -1.462560, 1.267280, 2.378060,
-0.166660, 1.074200, -0.141250, 0.108480, 11.217900, 0.798850, -0.120530, 1.084650, 0.362470, -1.099320,

0.654210, -0.354580, 0.847020, 0.190350, -4.951410, -0.953740, 0.836030, 0.343770, -0.443960, -1.212360,
-0.297440, -0.741560, -0.205620, -1.004150, -0.089570, -1.824840, -0.296800, 0.669070, -0.261890, -0.938340,
-0.590260, -0.973140, 0.486840, -0.275970, -0.345440, 0.075530, 0.034480, 0.630270, 0.276270, 0.622890,
1.141530, -0.769410, 0.399940, 0.693450, 0.707040, -0.628620, 0.933920, 0.213770, -0.882610, -0.616170,
0.370850, -0.329120, -0.323910, 0.083470, -0.682340, 0.272520, -0.489950, -0.849460, -0.187090, 0.375880,
0.055930, -0.121610, 0.066260, 0.644280, -2.535980, -0.258230, 0.942650, 0.506490, 1.064730, 0.180260,

-0.023100, -0.521790, 0.325760, 0.085270, 0.791020, -0.803680, -0.364160, 0.060900, 0.062530, -0.572210,
-0.197630, 0.057910, -0.626270, 0.798360, 0.293540, 0.345490, 1.843520, 0.204010, 0.532680, -0.204920,
0.743670, -0.418870, 0.053660, -0.299030, -0.628930, -0.361960, -0.353660, -0.070830, -0.012700, -0.176490,
-0.935300, -0.789850, 0.952560, 0.735130, 0.928280, 0.172430, 0.030900, -0.071200, 1.316370, -0.025890,
-0.156870, -0.222130, -0.320780, 0.687370, -0.451710, 0.603050, 0.606260, 0.757070, 0.353980, 0.343640,
-0.973980, 1.183330, -0.236700, -0.252630, -3.209790, -0.355440, -0.586440, -0.207130, -0.073680, 0.257600,

-1.052800, -0.732310, -0.385350, -0.196850, -0.702670, 0.131670, -0.230610, -2.201920, 0.289910, -0.480510,
-0.665830, -0.879660, 0.636190, 0.010510, -0.076810, 0.632020, 1.648260, -0.689050, 0.667230, 0.880140,
-0.219240, 2.288140, -0.019020, 0.360370, -0.582870, -0.796450, 0.027660, 0.597270, -0.263270, -1.736100,
-1.192870, -1.392970, -0.011840, 1.186250, 0.615800, 0.914420, 0.370840, -0.008130, 0.520980, 0.100880,
0.044310, -0.467460, 1.423600, 0.129390, -0.960500, 0.124400, 0.587220, -0.518980, -0.147100, -1.794910,
-0.048650, 0.138740, 0.350390, 1.082360, -3.678220, -0.464840, 0.518020, 0.013760, 0.403550, 0.620050,

-0.539990, 0.262240, 1.465580, -0.407070, 0.978760, 0.293360, 1.275840, -0.232050, -0.581660, -0.744380,
0.798540, -0.035850, 1.673690, -0.705740, -1.246840, 1.603320, 1.312710, -0.850190, -0.354810, -0.323090,
0.798670, 1.540230, 0.875150, 0.819050, -0.204900, -0.338960, 0.436110, 0.662230, -0.868020, 0.450850,
0.934090, 0.489360, 0.012650, -0.015800, 0.103230, -0.137820, 0.875020, 0.228260, -0.486390, 0.182000,
-0.558050, -0.461620, -0.752660, 0.850300, 0.091670, -0.736300, -0.639950, 1.316740, 0.068630, 3.495420,
-0.802400, 0.548990, 1.057070, -0.103900, -6.897640, 0.166790, -0.245800, -0.643730, 0.210750, 0.143990,

-0.219580, 0.597570, -0.641180, -1.705530, 0.794560, -0.119110, -0.238540, 0.204760, -0.718370, 0.683080,
-0.125600, -0.066050, -0.325930, 0.978850, 0.520710, 0.219330, 1.786420, 1.831650, -0.182560, -0.946490,
-0.044180, 2.335730, -1.321610, 0.659030, 0.880410, 1.284070, 0.023250, -0.708730, 0.232830, -4.747610,
0.293280, -0.655580, -0.684220, 0.190330, -0.162590, -0.111430, 0.499560, 0.859430, 0.642870, -0.281340,
-0.335540, -0.223230, 0.946850, -1.176510, 0.441180, -0.045140, 0.015800, 0.038400, -0.641600, 0.080930,
-0.450670, 0.471860, 0.122440, -0.012760, 0.191210, -0.086040, 0.238600, 0.041780, 0.311440, 0.207370,

0.198870, -0.727450, 1.541440, 1.252050, -2.281010, 0.894990, 0.957900, -0.943410, -0.162840, -0.664440,
-0.192090, -1.067700, 1.384270, 0.214180, -1.950270, -0.473800, 0.485220, -8.892550, 0.202230, 0.740460,
0.577340, 0.466340, -2.256430, 0.839210, -2.144880, -1.058580, 1.407800, 2.227110, 0.689710, 180.929199,
-1.388300, 1.001610, -0.325400, 3.580900, -0.085530, 2.188190, -0.274990, 0.965820, -0.470360, 0.468690,
0.747630, 1.084790, 0.156800, -0.890540, -0.905680, -0.491660, -1.592400, -0.956050, 0.252140, -0.052990,
-0.143100, 0.769710, 0.083980, -0.116560, -1.147890, 5.659070, 0.063370, -0.126450, 0.067560, -0.491840,

0.885420, -0.370160, 0.174750, -0.774470, 0.671620, 0.228300, 0.883720, 0.206810, -1.326150, -0.350170,
0.605750, -0.048090, -1.089580, 0.828870, 0.481050, -0.418010, 0.524940, 0.100700, -0.440920, -1.354400,
-0.478270, -0.180070, -0.706180, -0.424150, 0.497670, 0.728740, 0.142610, -0.356780, 0.589210, -0.836700,
-0.104140, -0.391780, 0.709900, -1.265880, 0.503520, 0.230060, 0.249520, 0.413590, 0.750200, -0.216090,
0.449620, 0.217770, -0.459470, -0.187970, -0.797690, 0.769790, 0.130820, 0.017920, -0.109950, 0.857010,
-0.400360, 0.622870, -1.151360, -0.925830, 1.554380, 0.703840, 0.601390, -0.048250, -0.394740, -0.010210,

-0.898200, -1.018720, -3.121600, 0.681520, 0.188030, 0.600720, -2.659820, -0.020750, -0.964240, 0.987030,
0.647850, 0.462120, 0.184350, 0.932520, -0.210310, 1.747460, 5.390880, 3.141940, 1.069930, 0.981860,
-0.457030, 5.561520, -0.395730, -0.605070, 0.769330, 1.917260, 0.629000, -0.548720, 0.857590, -2.509510,
5.053590, -0.744240, 2.146160, 0.494110, -0.624010, -1.034640, -0.269300, 0.026080, 0.886380, -1.078020,
0.586850, 0.624700, -3.041240, -0.963890, 1.336990, 0.376920, 0.735890, 2.612870, 0.137950, 3.652430,
-0.917300, -0.930430, -0.985970, -0.058380, 4.169450, -0.362210, -0.675810, -0.980600, 0.434220, -0.137510,

-1.023440, 0.723330, 2.570410, -0.319520, 3.074610, -0.723440, 3.557570, -0.382970, -0.054620, -0.275000,
0.452720, -0.277440, 0.588380, 0.725680, -0.388710, -0.295840, -0.081970, 5.225550, 0.006790, 2.242380,
-0.490300, -2.293360, 0.304060, -1.402550, 0.087220, 0.985650, -1.326720, -1.513630, -0.155120, -1.664750,
-1.860080, 1.085980, 0.367260, 0.207860, 0.708230, 0.338370, 0.477690, 0.547570, -0.703700, 0.799000,
-0.473990, 1.353140, -4.233190, 0.987520, -0.180940, -0.932700, -0.628300, -0.668200, -0.247560, 1.172690,
0.973210, -0.181340, 0.600360, -1.063540, -1.797460, -1.741990, -0.598130, 0.363440, 1.294700, -1.616670,

-0.213680, -0.099950, -0.101550, -0.376530, 0.673500, -0.371150, -2.032930, -1.112420, -0.750710, -0.436600,
0.386200, 2.334600, 0.234500, -0.171530, 1.424610, 3.091820, 2.532920, 0.016480, -0.759110, -0.604610,
0.569880, -4.311970, 2.409170, -0.060590, 0.772260, -0.402050, 0.197170, -2.034730, 1.291540, -420.994720,
1.729940, -2.719240, 0.161880, -1.616380, 0.376860, -2.251350, -0.680560, -1.832320, 1.751750, -0.315660,
-0.802780, -1.077540, 1.320120, -0.850200, 2.309900, -0.807920, -1.771220, 0.921170, 0.016800, -3.861370,
-0.420560, -1.559180, -0.684090, 1.179580, -10.655620, -2.475160, -0.547530, 0.475930, -0.604780, 0.107230,

0.324640, -0.817440, -1.771740, 0.127060, -0.094050, -0.149700, -0.537030, -0.418880, -1.058770, -0.137460,
0.870380, -0.843960, 0.747990, 0.082900, -0.309530, 2.295420, 1.917070, 1.298780, -0.724420, -0.928530,
-0.033750, -0.064640, 0.445680, -0.530170, -0.416100, -0.354950, 0.564160, -0.358530, -1.067090, 2.993990,
-1.742990, 0.494870, -0.322820, -0.314310, 0.342890, 0.597720, -0.314830, -0.606550, 0.363250, -0.323040,
0.348600, 0.240290, 0.038120, 0.648180, -0.374360, 0.108410, 2.656660, -0.136530, -0.826560, 1.140680,
0.007800, 0.451770, -0.464050, -0.370910, 2.903700, 0.012700, 0.189930, -0.249210, -1.027700, 0.649070,

-0.234190, -2.524870, 3.815060, -0.856600, 0.462970, 0.042120, -3.113840, 2.452260, 0.224330, -0.614790,
1.194220, 2.100360, -0.989320, -0.928310, 1.002960, -1.699530, -1.319120, -3.969300, 1.978510, 0.076380,
0.513080, -2.607280, 2.232720, -0.618800, 1.118700, 1.557300, -2.479070, -0.655660, -2.972290, -4.977030,
0.348220, -1.378970, 0.215570, -0.721370, 1.318300, 1.452330, 0.209910, -0.041740, -0.386310, 0.880290,
-1.032510, -0.040550, 0.173960, 0.126030, -0.474280, 0.578940, 2.448630, 0.486280, -0.714210, 0.505690,
-2.597540, -0.645940, -3.169590, -0.109610, 4.763150, -0.668820, -0.104300, -0.374320, -0.462260, -0.568050,

0.058620, 2.835490, -10.623950, -0.379770, -1.954230, -0.082810, 6.192390, -1.519380, 0.258980, -4.708470,
-1.685770, -2.307180, -1.375500, 0.739380, 0.190710, 0.653510, -5.707530, 250.369370, 1.330360, 0.445130,
0.881470, 10.457410, -0.255460, -0.870950, 1.294800, 3.973680, 5.726210, 14.921940, -1.098680, -5.115520,
-5.441460, 0.307050, 2.441830, 0.722260, 0.286700, 1.350750, 0.642250, -1.422550, 1.624160, -3.770250,
-0.121310, 0.919080, 88.551643, 1.155970, 4.105760, 0.384570, 2.452210, 10.671140, 0.156480, 36.621368,
2.528590, -0.527420, -1.487260, 0.074280, 60.641750, 0.865310, -0.781450, -1.861410, 2.374530, 0.974630,

-0.337130, -1.696780, 1.110420, -0.453820, -1.461300, -1.043520, 2.778890, 1.097480, -0.013140, -1.299040,
-0.344760, -0.095590, 0.077080, -1.040500, 0.123120, -0.458120, -0.875760, 7.102270, -0.271900, 0.341160,
-0.153450, -2.532870, -1.210880, 0.374760, -14.375230, -0.031270, 0.670700, 2.764450, -0.184310, 6.315040,
-1.492510, -0.614500, 0.663820, 4.230840, 0.876410, -1.096550, -0.861460, 0.307390, -5.619330, -0.509890,
-0.641310, 3.166700, -1.640550, -0.334000, -0.776480, 0.802770, -0.242910, -1.663440, 0.422720, 0.236680,
0.866350, 1.072410, -0.252750, 0.911910, -2.719360, -1.526180, 0.068300, -0.510950, -0.497720, -0.266990,

0.883860, 0.290680, 0.506280, 0.673370, -1.924830, -0.220020, 0.284530, -0.623540, 0.662860, -1.296120,
0.006920, -0.240010, -0.938880, 0.424850, -1.032420, 0.182770, 0.358070, -0.183850, 1.023340, -0.653280,
0.016890, 2.867930, 0.890400, -0.448990, -0.709500, -1.329510, -0.388580, -1.790580, 0.020560, 0.938510,
1.436670, 0.574320, -0.042270, -0.298870, -0.116630, 0.489220, 0.635100, 0.026180, 0.762600, -0.406980,
-0.305040, -1.766920, 0.671040, -0.531130, 0.396830, -0.143940, 1.038730, 0.627430, -0.684180, -1.366800,
0.496800, -0.207980, -0.314950, 0.029700, -9.151390, 0.395880, -0.970660, 0.060620, -0.841880, 1.099210,

-0.136000, 3.260360, 0.658730, -0.291480, 1.451460, -0.779750, 1.836750, 0.198950, -0.264740, -0.026580,
-0.596110, -0.683220, -0.869680, -0.427640, -0.528000, -5.796850, 11.084240, 25.270660, -0.147500, -0.949050,
-1.353780, -5.795670, 4.139060, 0.591390, -1.060060, 2.741630, 0.282120, 2.663060, -1.008600, 0.251130,
-0.154210, -1.146500, 1.312600, -2.895650, -0.078230, 0.253590, -0.376090, 3.193220, 0.253200, -0.267030,
0.520900, -2.334050, -3.851490, -0.246220, 0.717290, 0.005540, 4.262360, 6.157880, -0.192280, 8.800750,
1.120620, 4.053030, 2.910590, 1.619650, 19.397909, 5.791970, 0.073780, 1.492070, 0.309570, 0.008730,

0.498300, 0.078400, 1.077030, -0.096480, 2.472540, 0.102830, 0.169570, -0.447750, -0.037890, 1.449870,
-1.947320, 0.224140, -0.230570, 0.274570, -0.938790, -0.087800, 1.168590, -0.393370, -0.603190, -0.925530,
-2.224270, -1.453210, -1.938700, 0.869670, -0.946870, 1.885590, 1.624110, 0.381990, -0.120530, -0.340630,
0.885250, -0.895240, -0.021500, -0.899280, 0.781550, 0.930360, -0.487690, -0.600980, -0.844580, 0.540720,
-0.730930, 0.333190, -2.130330, 0.444340, -1.667140, -0.702170, -0.383460, -0.537160, -0.161610, 0.938310,
-1.055040, 1.408880, 0.633520, 0.304290, -1.496490, 0.384880, -0.561870, -0.569530, 0.455980, -0.034360,

0.506040, 2.635960, 1.263530, 1.041140, -3.527610, -0.526720, 1.140030, 0.997890, -0.351200, -0.220170,
0.705480, 1.327330, -0.375740, -0.463150, -0.430330, -12.179950, -8.738190, -1.271910, -1.082790, -1.286640,
-1.112650, -0.267420, -0.825050, -2.125130, -1.046320, -2.295670, 1.677170, -0.120570, -0.788040, -0.167200,
-0.361210, 0.330720, -1.001770, 0.412520, 0.584440, -0.305270, 0.176470, 0.523890, 0.457450, 0.138150,
0.037270, 1.080060, -0.267470, 0.396600, 0.993430, -0.062390, -0.570730, -0.314280, 0.391050, -2.208550,
0.304060, 0.350020, 0.554600, -0.364370, -0.538630, 0.572390, 0.425730, -0.429750, 0.576420, 0.492060,

0.319940, -0.564700, 2.294100, 1.024410, 0.665590, -0.104960, -0.222290, -0.382290, 0.767230, -0.718090,
-0.693500, -0.090200, -0.085010, 0.435050, -0.686020, -1.029450, 1.382910, -3.035960, 0.008710, 0.579210,
-0.683530, -0.523490, -0.080180, -1.043420, -0.668300, -1.481470, 0.204260, 0.491050, -0.204610, 2.124510,
-1.682140, 0.989740, -0.085910, 3.058120, 0.854420, 2.348000, 0.450480, 0.877090, -0.289460, 1.386880,
0.599080, 0.608320, -1.097650, -0.183920, -0.234730, 0.276230, -0.001060, 0.154590, 0.596670, 0.188080,
-0.674470, 0.239480, 0.622290, -0.265010, -5.377710, 0.695980, -0.645160, -0.598040, 0.212310, 1.516820,

0.551570, 0.552950, 2.201200, -0.049590, -0.481810, -0.547330, 1.891170, 2.157720, 0.088230, -0.311070,
0.048990, -0.207690, -0.928680, 0.008880, 0.321660, -10.061490, 1.859880, -0.501600, -0.685400, 0.912820,
-0.747620, 5.218570, 0.552330, -0.355000, 0.884390, -0.893370, 0.878720, 3.082150, -0.811110, 1.171240,
-5.272650, -0.140130, -0.688090, -1.834910, -0.643980, 0.669670, -0.198650, 0.550930, 0.441030, -0.151030,
0.826010, 0.534670, 3.348800, -0.249870, 2.142210, -1.118750, -0.725000, -0.720850, 0.206070, -2.057390,
0.596200, 0.150320, -0.131110, -0.005950, -1.957850, 0.290600, -0.937440, 0.163220, -0.280320, -0.175590,

-2.141790, -1.588790, 3.043470, 0.370720, 1.276660, 0.866120, 2.585590, -2.462380, -0.248060, -1.161570,
0.927860, -0.992530, 0.796850, 0.468120, -1.353730, 3.778550, 4.267940, -8.419450, 1.222330, 1.490380,
0.109750, 0.797440, 2.028050, 0.844780, -1.795990, 0.196590, -2.170600, -4.598820, -0.816760, 5.678920,
-4.957040, 1.367980, 0.420490, -2.458270, -1.957610, 0.443000, -0.079080, 0.748460, 1.289740, 0.030540,
0.723470, -0.751850, 2.347710, -0.021740, 0.803230, -0.359150, 0.598060, 0.135450, -1.354970, -0.910510,
0.240380, -1.689770, -1.388230, -1.961350, 2.074790, 2.113560, -0.752070, 0.490300, -0.530070, 0.026750,

0.209410, -0.394510, -0.663460, 0.756120, 0.924360, 0.637990, -0.235300, -0.305700, 0.172100, 0.174330,
-0.640120, 0.368690, -0.583280, -0.456640, 0.557820, 0.910000, -0.004410, 3.191520, 0.415670, -1.109740,
0.667500, -1.648110, -0.065040, 0.440430, 1.011400, 0.135980, 0.646490, 0.754830, -1.059540, -0.125580,
1.904600, 1.556580, 0.296110, 2.170010, -0.321640, 0.730500, 0.019100, 0.160310, 0.804270, -1.115150,
-0.473490, -0.434840, 0.014810, 0.512880, 1.776410, -0.389700, -0.068360, 1.642600, 0.100540, -1.351960,
0.387380, -0.793580, 0.390220, 0.109400, 1.942820, 2.568690, -0.212860, 0.699220, -0.173350, 1.004770,

0.981130, -1.847620, 0.697380, -1.007590, -0.633940, -1.326510, -0.619590, -1.087260, 1.553120, 0.368950,
0.818990, 0.548360, 2.361780, -0.950660, -0.175740, 0.318340, -0.901700, 1.101550, -2.020210, -1.664400,
-0.082250, -0.445970, 0.589860, 0.842230, -1.135520, -1.070500, -0.693300, 0.218820, 0.560180, -0.265060,

0.279860, 1.559480, -1.469030, 0.541460, -0.142090, 0.380420, -0.464310, -0.235430, -0.621810, -1.157690,
-0.509090, -0.213520, -2.031950, -0.552230, -1.425230, -0.899690, 0.313790, -2.445510, -0.182370, -0.804190,
0.481210, -0.603040, 0.887110, -0.582770, -0.299660, 0.656050, 0.181510, 0.010160, 0.171720, 0.859220,

-0.906200, -1.403270, -0.307420, -0.549570, 0.247980, -0.460160, 0.692360, 1.222480, -0.325320, 0.319880,
0.510450, -0.192840, -2.454980, 0.407460, 1.078160, 0.957290, 0.035250, -1.067290, 1.178790, 1.667750,
-0.851070, 0.590050, -1.084040, -0.380600, 1.265530, -0.050380, 0.023860, -0.075730, -0.377300, -0.536020,

1.836450, -0.784580, 0.717160, -0.981890, -0.875380, -2.848390, -0.152410, -0.051430, 0.784440, -0.613290,
-0.039830, -1.116400, 2.552130, -0.967180, 0.931220, 0.907780, -1.258570, 1.185190, -0.724180, -1.407590,
-0.651930, -0.560210, 0.609380, 0.980530, -2.170940, -2.623120, -0.257370, 0.417470, 0.771380, -0.528350,

-0.849100, 1.289610, -1.831470, 0.712120, -0.705360, 0.703440, -0.474780, 0.087840, -0.107040, 0.393590,
-0.770320, -0.978520, -2.900490, -0.240470, 0.696840, -0.868210, -0.153290, -2.330230, -0.543240, -1.670820,
0.659210, -0.634220, 1.066450, -1.353960, -0.961410, 1.072480, 0.210620, 0.350750, 0.129170, 0.670590,

-1.494220, -1.484580, 0.038780, -0.714190, 0.609440, -0.426320, -0.133230, 0.017800, -0.363260, -0.511300,
0.848460, 1.082930, -2.071170, 0.207820, -0.514260, 0.790000, 0.583010, -1.083010, 0.480200, 1.388200,
-0.835330, 0.780460, -1.037770, -0.217690, 2.042960, -0.701550, 0.806430, -0.354270, -0.272450, -0.878770,

2.204600, -0.520040, 0.566730, -1.547510, -0.905520, -2.308540, -0.170380, -0.496790, -0.598510, -0.940960,
-0.435400, -1.470340, 3.069870, -0.982350, 1.433590, 0.158400, -0.561870, 1.174750, -0.156930, -1.603080,
0.612240, -0.727520, -0.733440, 0.688900, 4.246790, -3.191140, 0.351240, 0.460480, -0.277380, -0.235490,

-1.161500, 0.475600, -0.995610, 0.903080, -0.457670, 0.453930, -0.599630, 0.008450, 1.191490, -0.288270,
-1.159980, -1.391290, -3.239600, 0.699020, 1.700990, -0.253680, -0.222980, -1.668770, -0.264350, -1.693870,
0.434080, -0.008560, 0.691620, -0.840910, -3.524090, 1.790520, 0.639330, 0.827080, -0.595400, 0.210570,

-1.589340, -0.632620, 0.079590, -0.828050, 0.609830, -0.505560, -0.116370, -0.168560, -1.576790, 0.483120,
1.034360, 1.468550, -2.743860, 0.728090, -1.681600, 0.076220, 0.451910, -1.018840, 0.031470, 2.077820,
-0.478650, 0.422930, 0.131250, 0.344870, -3.270300, -1.542420, -0.488170, -0.704210, 0.550020, -0.712300,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.168720, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.341680, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, -0.008000, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 0.707150, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.164140, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.612030, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.620570, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, -0.713090, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.490690, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.605350, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, 0.247390, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, -0.147410, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, -0.539530, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 418.054413, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.088680, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 0.809890, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.747690, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, 0.822010, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.404780, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, -0.146500, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.018350, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, -0.371590, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.309700, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, 0.187090, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, 0.209080, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, -0.134410, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.029090, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, -0.241670, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, 0.096770, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, 0.222810, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.057310, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.269390, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, -0.599240, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, 0.452720, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, -0.942310, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, -0.808490, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, 0.461170, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, -0.382000, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, -0.740930, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, 0.135250, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, 0.843150, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, -1.014480, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, -0.627760, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.383400, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.874150, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, -0.094900, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, 0.269060, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, -0.476540, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.100710, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, -0.429120, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.113730, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, -0.021490, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, 0.148020, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, -0.617110, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.561760, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.029720, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, 0.165800, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, 0.450040, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.721780, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, -1.041470, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.532640, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.819970, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, -0.587380, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.027770, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, 0.855200, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.156700, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, -0.458100, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.451330, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, -0.341710, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
1.42854, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.37458, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.27238, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
1.41206, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
0.11891, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.98611, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.04719, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.10810, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
1.27394, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
1.42857, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
1.38807, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
1.42855, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
1.06274, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.42857, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
1.10088, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
0.12773, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
0.21716, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.00046, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
1.34775, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
1.42818, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
1.42851, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
0.43309, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.02063, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
1.42857, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
0.21292, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
0.00257, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.66071, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
0.06215, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
1.41801, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.00000, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.15660, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
0.00020, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
1.38533, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.00000, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.40140, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
0.08638, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.20493, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
0.00096, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.01247, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
1.03161, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
1.07827, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
0.34190, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
0.25296, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
0.82694, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.08615, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
1.42843, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.00453, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.71308, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
0.02406, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.01030, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
1.42857, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.03950, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.03769, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
1.42798, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.00610, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.01059, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.12459, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
0.76693, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.03366, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
1.30324, 0.500000, 2,
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
