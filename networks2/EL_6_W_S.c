/*********************************************************
  EL_6+W.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:15:33 2004
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
-0.120060, 0.777530, -0.505130, 0.623760, 0.113550, 0.321670, 0.539740, 1.092930, 0.469930, -1.633040,
-0.436900, -2.176690, 1.341470, -0.629400, -0.600410, -0.252840, -0.301620, 1.626900, 0.021810, 0.153130,
0.561090, -1.048070, -0.505470, -0.294850, -0.585810, 1.012610, -0.730330, 1.334770, -1.559520, -0.427060,
-3.162380, -0.362890, -1.321990, 1.045300, -0.798780, -0.645850, -0.176610, 0.114640, 0.883960, -0.294460,
-0.343130, -0.770340, 2.235520, -0.088790, 0.304060, 0.277950, 0.913430, 1.479790, -6.205740, -0.535620,
-0.795920, 6.794000, 0.383890, 0.281350, 2.589220, 0.001840, -0.104460, 1.335190, -0.842110, -0.764830,
-2.913650, 0.097230, -0.217050, 11.398820, 0.115210, 0.353860, 1.944440, -0.734000, 0.753210, -2.411970,
-0.143250, -0.349760, 11.941630, -0.089360, -1.255400, -0.445110, -0.464500, 0.675420, 0.325070, 0.190870,
-0.866740, -1.660060, 0.329630, -0.465160, -0.417860, -1.279280, -1.073070, -0.901130, 1.211400, -0.261870,
0.069610, 0.574010, 1.256510, -0.598540, -2.346800, -0.008130, 1.469330, 2.034270, 1.137980, 2.500270,
0.786030, -0.243990, -2.511600, -1.830880, -2.182870, 2.283390, 3.211990, -1.820740, -1.119600, -2.738180,
0.703500, 0.021280, -0.740960, -0.156400, 7.971730, 1.349060, 0.449350, 0.121490, -7.134110, 0.790070,
-4.489110, 0.295920, 0.383890, 1.769660, -0.444990, -0.094750, 0.725120, -0.649350, -3.078990, -0.362830,
0.215020, -0.062060, -0.526720, 0.237100, -0.805130, -0.843960, 0.035100, 0.746110, 0.797350, 0.804170,

-1.618890, 0.180810, 1.001060, 2.196040, -1.076540, -0.186420, -0.199660, 0.040960, -0.549690, 0.491360,
0.415500, -0.902260, 1.796850, -0.060050, -0.579250, -1.080570, -0.413080, 0.375460, -0.617140, 0.620570,
-0.379600, 0.385110, 1.085150, 0.779570, 1.537940, 0.654730, -1.096390, -2.241950, -0.157120, -0.025580,
-1.169720, 1.209390, 0.161520, 2.501460, 0.822300, 0.511550, -0.979370, -3.804110, 1.392910, -0.788350,
-2.457110, 0.298150, -4.228760, 0.667870, -1.304300, 1.914660, 1.192220, 0.405910, -0.833640, 1.077470,
-0.358880, -1.006160, -1.919480, 1.755460, 0.092610, 3.232490, -1.555650, -2.726400, -0.106350, -1.633450,
1.895140, -1.227530, -0.425410, -7.010430, 3.452450, -0.750370, -2.766310, 0.497440, -1.182550, 5.242870,
-0.391060, -0.648630, -0.849110, 0.291540, -0.000510, -5.336960, 0.299520, 0.184580, 5.013810, -0.983810,
1.787710, -2.820900, -0.390380, 0.866660, 2.529350, -0.372550, 0.906590, -1.591870, -0.789850, 1.863400,
-1.283030, 1.696130, 0.014670, -0.677450, 1.445040, 0.547200, -0.191490, 2.554250, 0.490400, -0.338490,
-0.361270, 0.913950, 3.633060, 2.895270, -1.252600, 0.114970, -6.598610, -0.700880, -1.150610, 3.764620,
-0.568040, 0.479410, 0.006380, 0.164550, 3.351370, 1.659130, -0.587110, -0.161540, 2.204260, -0.465060,
8.061820, -1.915900, 2.206720, -0.433110, 0.241390, -0.516850, -0.563470, -0.672270, -0.755450, 0.287730,
0.696590, -0.761750, -0.083670, 0.545000, 0.714440, 0.262410, -0.346160, -0.125090, 1.271890, -0.514380,

-0.680170, -1.333350, 4.476370, -0.376170, -2.998860, -1.763350, -2.426880, 0.382040, -4.876850, 0.425340,
2.848490, -0.803400, 0.425640, 0.621970, -2.439050, 0.702060, -4.190490, 0.284720, -0.744780, -0.481060,
-0.241420, -0.426520, 0.445840, 0.008110, 0.640990, -0.153390, -1.187360, 0.385090, 0.457640, -3.418600,
-0.780240, 1.105980, 2.346320, -1.828490, -4.113030, 3.070390, -0.400760, 0.480770, 0.542840, 0.042900,
0.650990, -4.833320, -1.436590, 3.845380, 3.624060, 0.639070, -0.263200, -0.335020, 0.317380, 1.549510,
0.822030, 7.122450, -3.640180, -1.486130, -1.058880, -0.859040, 3.312330, -0.360060, -4.770220, -0.025360,
-6.148680, 8.324450, -1.077190, 1.750460, 0.556600, -2.235870, -0.573680, -7.371160, 0.865000, 1.706150,
10.529170, -0.725600, -0.647750, 0.445090, 0.043010, 4.886810, -2.284850, 0.282100, -0.221510, 0.963550,
-0.854610, -0.510540, 0.289710, -0.056670, 0.270930, -4.921090, -0.944220, -3.341730, 7.830090, 0.880500,
-0.278140, -1.569700, 1.473800, 1.271860, -2.436460, 0.954380, 1.864900, 2.262430, -2.238540, -3.651080,
-0.970000, 20.132780, -1.561750, -3.786620, -3.468870, 41.668751, -4.126420, -5.568010, -4.511180, 7.325450,
-0.308470, 1.055810, -0.852480, 1.539890, 18.597401, -6.259560, -0.860320, -0.576470, -17.872410, 0.545620,
-1.597110, 5.444370, -0.054630, -0.067800, -0.773040, 0.234090, -1.987470, 0.843010, -2.294030, 0.396410,
0.648070, -0.429940, 1.136790, -0.615480, -1.479320, 0.136460, 0.922280, 0.164620, 0.385920, 0.660650,

-1.053130, -0.471900, 0.732170, 0.060050, -1.946590, -0.380520, 0.153550, 1.277210, 0.049750, -0.548550,
-0.903510, -0.129020, 0.574490, 0.451430, -0.274530, 0.904550, 0.027440, -0.256800, 0.322630, 0.948040,
0.057450, 1.166650, -0.403910, 1.443550, 0.268410, 0.678520, -0.319770, -0.192560, 2.934150, 0.121260,
0.915770, -1.209510, -0.300070, -1.994600, 0.807290, 0.577760, -0.139490, 0.411850, -0.506700, 0.635150,
-0.503770, 0.039770, -0.026290, 0.830690, 1.609060, -2.793160, 0.996920, 0.062910, 0.411850, -4.988480,
0.605900, 0.965210, 2.598420, 0.331220, -2.443890, 0.165620, 0.106350, 1.209740, -4.590420, -0.944550,
-1.892620, 4.555450, -0.020860, -2.527150, -0.822550, 0.061610, 0.470070, -6.917900, 0.111680, 0.820380,
6.887200, 1.032420, -0.500840, 0.853480, -0.873810, -0.484720, -0.517280, 0.664970, 0.303770, 0.683900,
0.171210, -0.798770, 0.928430, -1.096640, -0.316130, -3.408320, 0.174350, 0.209470, 4.571440, 1.521280,
-0.297880, 2.475090, -0.727340, 2.329480, -2.352570, 1.123680, 0.802500, 1.583550, 0.664330, -1.191330,
-0.698060, -3.048420, 0.006720, 1.129320, 0.076210, -0.205360, 0.931610, -7.680580, 0.137830, -0.252020,
-0.300240, -0.853600, 0.855960, 1.609710, -1.229350, 1.539860, 0.284850, -0.265910, -6.561640, -0.421910,
3.336080, -0.571460, 1.003040, 0.382770, 0.792870, -0.799620, -0.554950, -1.283850, -0.932430, -0.613670,
-0.225200, 0.474430, -0.186120, 0.108620, -0.068950, -0.157410, 0.967460, 0.904240, 3.303250, -0.641850,

-1.112810, -0.944090, -1.054950, -0.009000, -0.653910, -0.122400, -0.882980, 0.108000, -0.225380, 0.011880,
-0.558480, -0.231520, 1.017940, 1.196490, -0.763830, -0.806180, 0.371090, 0.828890, -0.829200, -0.660330,
0.641600, 0.026960, -0.953790, 0.507290, -1.357180, 0.302960, -1.026580, 0.448740, 0.707710, -0.867970,
1.059660, -2.756180, -0.605010, 0.245580, 0.349770, 0.876720, 0.452520, -0.638060, -0.512350, -1.017050,
4.835580, 1.011870, 0.154460, -4.912720, -2.642840, -3.889400, 2.873990, 0.897510, 1.356700, -6.315480,
-1.072150, -0.781130, 0.039560, -0.337860, 1.029400, -1.037910, -0.610710, -0.531680, -0.086560, -0.781100,
0.627700, 4.217630, -1.001180, -1.250190, 1.320710, 0.429250, 0.722120, -4.753610, 0.537440, -0.375360,
0.331350, 0.836380, 0.582360, -2.310570, -1.536980, 0.823830, 0.511620, -0.358270, -0.422470, 0.741330,
1.774850, -0.102660, -0.812830, -0.629840, 0.766940, 0.450960, 1.026240, -0.324350, 1.571050, 0.267730,
0.976360, -1.698210, -0.543310, -0.954380, -0.068960, -0.517460, 1.062030, 0.769440, 0.334360, 0.735150,
0.378340, -1.141600, -4.135570, 5.084290, -1.426200, 3.557890, -1.159620, -4.349890, 1.095220, 1.624960,
0.788890, 0.004100, -0.196660, 0.225950, 0.735320, -0.245590, 0.317230, 0.890870, -7.731600, -0.310220,
0.355600, 0.955280, 0.187200, 0.284520, -0.289770, -1.055490, 0.456510, -0.670800, -0.480620, 0.046660,
-0.016320, -0.302840, 0.001970, 0.283970, -0.311090, 0.901080, -0.354950, -0.617430, -0.331870, -0.340970,

-0.211880, -1.568170, -0.813160, 0.192900, 0.206750, 0.109940, -0.702330, -1.859720, 0.417620, -0.642720,
2.373550, 0.046930, 0.784380, 0.251470, 0.336080, 0.465860, 0.524860, 0.644490, -0.396750, 0.664030,
-1.743780, 0.674310, -2.033060, -0.018430, -1.645930, -0.426570, 0.786950, -0.100420, 0.677330, -0.240360,
1.420680, -0.173000, -0.606060, 0.457210, 0.551770, 0.575020, 2.788860, 0.629190, -2.650400, -0.386180,
-0.198230, 0.299240, -0.804090, 1.121340, -0.390030, 0.337240, 2.883720, -2.188860, -0.369220, -0.219900,
3.263110, -1.937350, 0.051990, -6.343580, -0.506500, -1.566210, 4.564690, 1.104140, -0.504130, -3.081120,
0.575250, 0.508610, 0.260030, 0.603790, 0.026700, -0.961790, -0.979280, -0.305570, 0.363340, 0.984220,
0.822380, -3.173980, -0.790670, -0.498240, 0.171540, -0.012310, -2.445410, 1.201160, 1.030800, -0.526540,
-5.090620, 0.207990, -0.942540, -2.595890, 0.450690, -0.931320, 0.542740, -0.190550, 0.816650, 1.692870,
-0.408540, 1.261600, -1.587620, -0.927050, -0.755830, 0.214470, 0.199890, 1.882030, -0.096100, 2.248010,
0.055330, -1.771170, 4.633290, -4.906640, 0.937810, -5.521160, -5.218950, 0.654710, -2.948460, 0.146990,
0.219280, 0.611690, 0.342070, 0.391600, 1.400000, 0.073190, -0.727800, 0.423980, 2.826160, -0.541330,
1.478660, 0.848360, 0.558920, 0.935500, 0.818480, 0.768950, -0.386320, 0.292590, 0.461740, 0.029370,
0.459230, 0.069790, 0.611370, -0.868780, 0.370940, -0.697320, -0.584170, -0.353390, -0.844380, -0.493650,

0.402990, -0.478300, 2.906500, 1.918520, -0.615100, -0.894680, 0.326860, 0.624570, -0.352410, -0.776420,
0.930160, 1.277310, -1.755430, 0.251490, 0.169030, -0.016350, -2.139230, -0.379220, 0.259270, -0.212270,
-0.738100, -1.702030, -0.307470, -1.194300, 1.235300, -0.682540, -1.481020, 1.078300, 0.500490, -1.986050,
-0.503720, 0.055830, -1.045330, 2.297190, -1.838170, -1.184770, 1.051170, 3.482760, 3.710680, -0.697320,
-0.297850, 1.030730, 1.617410, 0.855240, 0.480440, -4.038710, -0.565810, -2.060750, 0.712470, 1.855790,
-1.950850, 1.849910, 1.670960, 1.569650, 0.524630, 0.723830, -1.016100, 0.184630, 2.767230, 0.107100,
0.665700, -1.178380, 0.860110, 0.414560, -0.128760, -0.553690, 0.234340, -0.875990, -0.745210, -1.197110,
0.714620, -0.604290, -0.602250, -1.239640, 0.974820, 0.554900, 0.635140, 0.477540, -0.105700, -1.500850,
-1.034490, 2.450450, -1.584570, -2.776790, -0.621100, 0.016880, 1.448030, 0.786800, -0.257250, 0.316560,
1.232710, -1.276100, 0.951550, -0.715200, 0.953160, -0.436610, 0.610240, 3.501420, 1.557890, -3.189520,
-2.454330, 1.552450, 1.380330, 10.068680, -6.176250, -1.029220, -3.144720, -1.629910, 0.963390, -0.376750,
0.458870, -1.717790, 0.537420, -0.441540, -14.707930, -0.914460, 2.119330, 0.584370, 4.582670, 0.776850,
2.334070, 1.395700, -4.552060, -0.140630, -0.389480, -1.135370, 0.370730, -0.038830, 0.643580, -1.127670,
-0.789460, -1.084680, 0.575370, 1.727260, 0.468630, -0.554750, -0.966540, 0.408250, -0.932850, 0.440030,

-0.190640, 2.672770, 0.592480, 0.333380, -2.773030, -0.569290, 1.135480, 0.662610, -0.608140, -0.407920,
0.814210, -0.085650, 1.505920, -1.871990, 0.680460, 0.805030, 1.433800, -0.215360, 0.566920, 0.456570,
1.060040, -0.436940, -5.968370, 0.060270, -1.258870, 1.161680, -0.710380, 0.021190, -1.842360, 0.993770,
-0.188970, 0.194680, 0.158290, -0.463100, 3.362640, 0.572770, 1.034910, -0.553970, -0.269400, -0.031000,
3.727400, 0.381280, -1.150050, 5.155600, 0.363580, 0.710470, -4.160990, -4.746720, -0.150650, -1.458340,
0.975140, -0.980840, 6.811330, 0.213560, 0.253560, -7.355530, -0.750220, 0.144430, 0.499350, 0.317680,
-1.692430, 2.636260, 0.193360, -0.119600, 0.305100, -0.816320, -0.304610, 0.844520, -0.227360, -0.298640,
-2.178190, 1.120340, -1.462260, 1.347120, 0.142690, 0.362310, -2.375510, 0.090500, -0.394440, -0.784380,
-0.457980, 0.579870, 0.189880, 1.255860, -0.240870, 0.006620, 0.396990, 0.563890, 0.030710, 0.406380,
-0.531210, 1.786770, 0.301650, -0.904810, 0.710760, -1.178470, 0.801930, 1.756500, 0.806850, -0.657770,
0.581200, -0.299050, 1.421700, 3.765960, 0.910890, -6.139720, -5.115630, -3.197760, 1.893840, 0.138480,
-0.169830, 1.261220, 0.564380, 0.703070, 2.664710, -1.653060, -0.320630, -1.224330, -2.201070, 0.953320,
2.276920, 0.345330, -0.347260, -0.992310, 0.619750, 0.276970, -0.751700, 0.165950, -2.405210, 0.131040,
-0.815900, 0.625630, 0.382620, 0.225230, 0.532150, 0.147160, 0.210730, -0.137020, -0.483040, 0.993240,

0.483760, 0.358960, -2.544060, -4.440430, -0.534590, 0.809510, 1.309720, 2.510260, -1.174490, -1.725620,
1.126940, -0.186370, 0.661780, 0.957960, 0.642310, -2.647910, -0.613880, -0.666260, 1.753680, -0.910920,
0.796630, 5.090120, 1.422290, 0.691100, -3.601630, 1.965200, 0.210370, -2.565990, -0.948650, 0.323690,
5.109910, -1.532340, 0.399520, -4.807000, -2.041750, 0.114610, 0.141650, 1.477620, 0.920660, 3.800020,
1.140910, 0.100880, -8.673690, 0.365280, -1.116020, -9.626790, 0.680500, -3.056370, 3.163380, -0.027840,
-0.648410, 5.015580, 0.201160, 0.793700, -2.798640, 1.118350, -2.302680, -5.239360, 0.299510, 0.990410,
5.493300, 0.638300, 0.806990, -15.812960, 0.834400, 1.348260, 4.489440, -0.710790, -0.781520, 1.262050,
1.444680, 1.072500, 3.213530, 0.067840, -0.278950, 0.530890, 1.233770, 0.924140, 0.594600, -0.413030,
-0.897820, -3.983570, 0.267710, 0.614720, 0.636330, 2.050480, 0.083940, -0.099510, -2.763680, 0.548730,
-3.190270, 0.930380, -0.259980, 0.296990, -3.932010, 1.270730, 0.776880, 0.794280, -0.609210, 1.170810,
2.180300, 2.304810, -0.136950, 2.366790, -3.131410, 3.672150, -2.031350, 1.488760, 2.256880, -3.848710,
0.181030, -2.872040, 0.389600, 0.669190, 2.696150, -3.908470, 0.173870, -0.430010, -3.135400, -0.269400,
3.900080, 0.051170, -1.991210, -0.817090, -0.047500, -0.117610, 0.024510, -3.041760, 0.209800, -0.787100,
-0.299620, -0.313410, -0.444050, 1.648260, 1.147760, 0.436070, 0.219240, -0.786230, 1.060390, -2.566540,

0.259500, -1.651890, -0.112460, 0.742950, -0.626320, 0.237990, -0.411300, 1.666190, 0.689890, 0.463790,
0.347370, 0.145750, 0.627010, 0.311290, -0.207700, -1.127510, 1.432350, 0.002410, -0.308580, 0.542150,
-0.580230, 0.372840, 0.616330, -0.171830, 0.581690, 1.205730, -0.587250, -0.436640, 2.563830, 0.216530,
-0.072200, -0.003770, 0.186760, -0.781340, 0.041620, -0.952680, -0.106790, -0.092760, 1.695430, 0.425260,
-1.654620, 0.823920, -0.413680, 1.563520, 0.297280, 0.124110, -1.033190, -0.292580, -0.868730, -3.207260,
-0.232810, -0.475290, 1.583880, -0.992610, 0.066090, -0.428050, -0.326540, 0.087970, 1.406750, 0.397150,
-1.355410, 3.697670, 0.336220, -0.717420, 5.913630, -1.579300, -0.385670, 2.133360, 0.457960, 0.977950,
-0.765820, 1.350140, -0.306440, 2.127750, 0.247350, -0.294230, 0.983770, -0.497170, 0.762540, 1.508830,
-0.646240, -0.752050, 0.170430, 0.461440, 0.511850, -0.998130, -0.075140, 0.962180, -0.927110, 0.628290,
-1.163410, 0.364570, -1.079590, -0.512790, -0.185020, -0.111170, 0.016030, 1.553660, 0.339850, 1.849420,
1.000020, 0.387240, -0.126890, -5.855450, -1.686860, 1.908660, 0.601820, -2.685030, 1.548630, -0.833570,
0.674370, -0.138600, 0.222980, 0.015870, -3.433540, 1.903840, 1.192600, -0.470050, -3.803790, 0.112580,
0.399750, -0.855150, 2.816570, 0.459200, -0.145460, -0.442420, -0.647800, 0.177430, -1.330090, 0.081370,
-0.626540, 0.521420, -1.896760, -0.836650, 0.456060, -0.247280, 0.532290, 0.509300, 0.202890, 0.350280,

-0.954250, 1.474720, -0.149210, 0.551390, -1.811830, -1.136910, -1.645040, 1.230560, -0.782550, -0.101880,
0.426750, -0.582450, -0.457440, -4.317220, 0.224340, -0.822240, 2.052190, 0.360710, 0.233190, -1.279710,
0.151020, 0.768260, 1.377310, 0.333470, -0.393640, -0.104990, 0.522750, -0.462630, -2.347500, -0.643840,
-0.832220, -2.052070, 0.366720, 0.040820, 0.574630, 0.539380, -1.834210, -0.641620, -1.925190, 0.456770,
-1.064820, -0.972910, -1.534090, -0.909060, 0.032560, -0.547180, 1.270330, -0.225800, 0.616960, -0.241680,
0.495720, 0.408060, -0.495280, -0.445920, 0.982620, 2.699600, 2.375330, -0.241460, -2.455770, -2.086730,
-0.475010, 2.233780, 0.602440, 2.756980, -1.018110, -4.171230, 0.951570, -2.044040, 3.807170, 0.269450,
7.358680, 0.735230, 1.114350, -2.994450, -5.908540, -0.012270, 0.345810, 0.115830, 1.015490, 7.163150,
1.440280, -0.646790, -12.622110, -5.840710, 0.835810, 7.395460, 1.821110, 0.384310, 3.473680, 1.993540,
0.139620, -5.643890, -1.065490, -0.094910, -25.882721, 0.849150, 0.490570, 0.053830, -2.097080, 1.212170,
0.713690, 0.740130, -2.428100, 0.299060, -0.017940, 3.775410, 2.214150, -3.814350, -5.282060, 1.162430,
0.350460, 0.718080, -0.760760, 0.736590, 0.491130, -0.522800, -0.247680, 0.129310, 2.531120, 0.156330,
1.490820, 0.177680, -1.021450, 0.523320, 0.177720, -0.511180, 0.433200, 0.258270, 3.227130, -1.249980,
-0.171710, -0.079870, 0.621970, -0.093950, -0.167270, 0.858750, -1.331030, -0.573430, 0.942110, 0.253670,

-0.508340, 0.152160, -1.289510, -2.497660, 0.729440, 0.061020, 1.689270, -1.943260, -0.035580, -1.812010,
0.717050, 0.405350, 1.874930, -0.293790, -0.497220, 0.263710, 0.386940, 0.270240, 2.337960, 0.134190,
0.464450, -0.318490, 0.393680, -0.178200, -4.452820, 0.564220, 1.034370, 2.577520, -0.976610, -0.104230,
-3.183770, -0.021850, -0.280960, -7.349770, -1.810260, 1.599780, -9.018650, 0.123880, -1.660640, -5.582350,
-1.086940, -0.662960, -0.938610, 0.419090, 0.405310, -0.251850, -2.324950, 4.577730, -1.063760, 0.127420,
0.645710, -0.769650, 0.794510, -0.597890, 4.144140, -0.753240, 0.757360, -0.786060, -1.487350, -0.428400,
-1.325620, 0.529720, 0.031820, -1.216760, 0.125570, -2.781980, -0.232290, -0.986150, -0.945450, -0.316200,
0.162170, -0.319290, -3.125250, -0.748600, -0.474170, -0.444260, 2.648510, 0.107110, 1.448420, 0.074240,
-0.087880, -2.557580, -0.429060, -0.698450, 0.794930, -1.696520, 0.542050, 0.542230, -0.858400, 0.312150,
-0.679320, 0.889760, -0.454340, -0.184590, 0.792850, -0.175590, 1.027540, -0.103540, -2.911520, 0.607960,
-1.154450, 1.186290, -1.331780, -2.875330, 2.624150, 4.211290, -1.851640, 1.245010, 0.091450, -0.479280,
-0.542140, 0.310050, 0.930940, 0.194070, -13.033520, 0.437780, 1.746410, 1.692020, 0.973550, -0.219290,
0.727090, 0.069650, -0.397590, 0.108030, 0.351550, 0.972160, 0.415140, -1.007270, 1.131980, -0.085200,
0.391800, 0.375890, -0.473260, 2.222550, -0.145300, 0.174380, 0.343020, -0.159510, -1.405960, -0.670090,

-0.302110, 0.864990, -0.585090, 0.019490, 0.725500, -0.640990, 0.305420, 1.798780, -0.032940, -0.161030,
-0.482100, 1.129090, 0.489790, -1.230370, 0.287220, 0.430130, 3.032050, 0.906270, -0.327350, -1.202230,
0.593830, 0.570260, 0.648740, 0.240400, -1.207350, -3.489310, -0.547950, -0.437260, -1.593330, -0.147010,
-0.150850, -6.897060, -0.521150, -0.049330, -0.845140, 0.596560, 0.592880, 4.234050, 0.884090, 0.418530,
-0.973270, 0.102040, 1.102670, 0.863130, -0.274560, -0.095450, -3.568200, -0.604630, 0.886790, 2.724520,
-0.878400, -1.996500, 1.484170, -0.042040, 0.163900, -2.992850, -1.166370, -0.670890, -0.678820, 0.267550,
-1.308510, -2.742990, -0.487170, 0.786880, -1.738300, 0.274540, 0.938880, 0.654850, -0.539550, -0.806540,
-1.357530, 0.085900, -0.095280, -2.202530, -0.434840, 0.613220, -0.767440, 1.390130, -0.758100, 0.890730,
0.366290, -0.809690, -0.861590, -0.615490, 0.782830, 0.552020, 0.542120, -0.605720, 0.169280, -0.272680,
-0.723340, 1.007770, -1.614990, -0.398790, -0.768680, -1.000610, 0.292390, -0.444630, 0.558400, -0.929700,
1.069350, 0.171560, -0.659420, 1.847990, 4.197630, -2.992880, -1.466130, 4.992210, 0.803130, -1.938230,
-0.574870, 1.910610, -0.792920, 0.303150, -0.355760, 0.022260, -0.929670, -0.348220, 0.050090, 0.403790,
-2.965560, 0.812290, -1.429790, -0.356360, 0.542140, 0.357800, 0.809050, 0.458320, 1.968880, -0.321370,
0.330750, -0.097250, -1.083800, -0.383710, 0.511780, 0.149020, -0.439220, -0.380110, -1.410230, -0.875680,

-2.155600, -1.296800, -0.008080, 0.513530, 0.175680, -0.425690, 0.151830, -1.379700, -1.505020, -1.339230,
-0.889120, 0.962220, -2.740980, 0.649000, -0.603480, -0.655380, -1.051060, -0.197760, 0.306350, 0.093270,
0.417570, 0.420700, -0.433220, 0.565440, -0.034170, 2.365430, -0.211080, 5.455310, 0.705910, -0.552410,
-1.808630, -0.009100, 1.110110, 0.299410, -0.600390, 0.847270, -0.383020, 0.567650, 0.316640, -1.301110,
0.980500, -1.118300, 0.807250, -0.666950, 0.944950, -0.411100, -0.870460, -0.225380, -4.090700, 0.211890,
-0.872610, 3.416020, -0.302510, -2.185440, 1.318150, -0.639230, 4.637020, -3.405660, -1.173280, -5.635620,
-1.012360, -1.892680, 0.115630, 0.234800, 0.269350, -2.200450, -2.408470, 0.453860, 0.505720, 0.289820,
-1.060850, -5.058770, 0.954250, -1.020380, -1.214800, 0.854270, 0.686970, 0.957670, -2.794490, 0.458790,
-1.407330, -2.160800, -0.370710, 5.131220, 2.742710, 0.455070, 0.001290, -0.957470, 0.165160, 0.460580,
2.527270, 0.186310, 0.893310, -0.296390, -0.606330, 1.229790, 0.542740, 1.526640, -1.232560, -1.592010,
-1.125960, -0.478240, -0.877480, 5.641330, -10.284510, 66.595093, -16.119989, 15.495240, -5.633690, 0.392710,
0.690600, -0.170140, 0.320400, 0.788440, -3.541490, -0.523080, -0.106780, 0.486620, 4.549200, 0.183040,
-2.528010, -0.818230, 0.695940, 1.898060, -0.593690, -0.833210, -0.496830, 0.287860, 2.981330, 1.233240,
-0.582610, 0.506260, 0.062170, -0.471240, -1.152650, 0.710160, 0.170000, 0.521560, -0.270290, -0.217790,

1.648120, 0.767610, -3.077410, -0.701720, -1.002580, 0.073580, -0.159960, 0.726540, -0.415150, 0.416930,
-0.645600, -1.136060, -0.635320, -0.750760, 1.728700, 6.808290, 0.903450, 0.533390, -3.989450, -0.442970,
-1.179760, -2.054130, -0.661540, 0.057160, 3.391010, -2.477220, 2.194330, 4.399200, 0.689160, 2.092010,
-5.204160, -0.047510, 0.969360, 5.289100, 4.764820, -1.278910, 0.652890, 0.018910, 3.907930, -3.741530,
-0.988490, 0.484700, -1.773350, 1.457950, -4.236560, -2.853290, 0.465400, -0.940930, 6.024420, -0.473580,
-0.872130, 0.482800, 0.234190, 0.492120, 3.408440, 2.174140, -0.770940, 8.204750, -1.064740, -0.325420,
3.191730, -4.105970, -1.064010, 10.412280, -0.354050, -1.019930, -0.415550, 2.949180, -1.069060, 6.530310,
0.644760, 0.012260, -4.785610, 0.245360, -0.503930, -2.061460, 5.393960, -0.567360, -0.707640, -3.922440,
-0.816180, 6.213930, 3.205820, -0.493380, -10.907810, -0.507810, -0.875270, 7.149790, -1.056680, 0.538890,
1.841600, -0.830350, -0.529990, 0.884020, -5.064750, -1.058400, 1.667060, 5.118170, -0.932770, -0.538760,
-1.692580, -3.645900, -5.266440, 8.792640, -0.311330, 2.079890, -0.452080, 1.782160, -2.780810, 6.658030,
-1.595270, 0.639960, -1.239830, -0.564300, 2.397070, -6.256430, -0.703530, -0.091010, -9.237090, 1.154300,
-12.718490, 0.940030, -3.069000, 0.716050, 1.976450, -0.413620, 1.402670, 2.440130, 3.677100, -1.212530,
-0.492920, 0.800270, 1.511000, 2.383690, 0.261500, -0.283790, -1.076020, -0.994770, -3.296650, 1.600600,

125.764374, 361.148468, -0.387030, 126.180206, 360.683777, 125.612244, 125.507538, 125.045174, 125.841904, 125.655472,
361.481476, 125.171432, 125.842323, 42.712410, 126.210602, 125.718483, 125.085617, 360.271057, 125.897812, 124.455040,
125.515503, 124.595413, 126.055412, 360.499451, 125.676193, 126.334312, 361.396667, 125.060913, 44.213821, 361.945526,
126.129440, 126.432732, 361.001465, 125.846527, 124.481323, 362.155426, 125.915627, 125.674919, 361.905609, 124.788040,
125.906822, 126.481056, 124.723228, 124.696899, 361.778259, 125.466019, 125.288422, 125.976196, 124.468437, 126.118637,
124.842072, 124.434357, 125.651062, 360.281830, 124.536873, 125.465134, 124.729439, 124.255478, 125.068932, 361.740814,
126.024696, 125.285469, 361.955109, 125.999672, 125.896263, 362.187073, 125.930191, 126.273300, 360.251221, 125.608627,
362.090881, 125.270882, 124.266510, 124.766769, 361.122253, 124.384537, 126.257637, 125.390877, 124.344223, 362.066193,
125.167938, 124.406227, 361.033386, 124.879707, 126.027847, 360.330261, 125.018188, 124.728523, 360.483124, 125.877373,
124.704567, 360.788727, 125.916252, 125.839119, 362.006165, 125.491180, 125.800819, 360.242188, 126.018806, 125.451302,
125.263977, 124.446213, 124.960564, 124.882004, 125.884361, 125.808533, 124.933777, 126.019073, 124.656487, 126.053673,
1.796330, 124.548378, 125.937477, 125.959869, -125.647522, 0.087260, -124.383614, 361.892181, 125.279556, -1.084170,
-124.540192, 125.081367, 0.142540, -124.442459, -125.568573, 124.463654, 360.915558, -124.678436, 125.935631, 125.484642,
124.547859, 0.399940, 124.831833, -124.117088, 360.912964, 361.513885, 124.693420, 124.788322, -123.956253, -0.242310,

2.766410, 1.369180, -0.387810, -0.296870, -0.275780, -0.735630, -1.509890, -1.110740, 0.299000, 1.753910,
-0.738620, -0.127490, -2.548430, -0.299590, -0.143330, 1.144810, -0.454120, 0.691530, -2.483280, 0.991300,
0.360500, -0.824990, -0.471730, -1.198100, 0.768380, -1.458860, -0.711900, 0.319620, 0.741940, -0.577650,
-0.023540, 0.785810, -3.839390, -0.348460, -0.404770, -0.437060, -2.003470, -0.892200, -0.894660, 1.547380,
-0.331330, 0.117110, 0.564490, -1.064980, 1.475840, 0.018290, 0.406930, 1.783380, 2.143410, 0.165520,
1.654990, -2.554120, 0.365130, 0.319790, -0.463790, 0.355450, 1.935720, 2.133680, -0.319960, 0.072180,
-1.086110, -1.230790, -0.199660, 0.152830, 0.578410, 0.734340, 0.470980, -0.251710, -0.630050, -2.008220,
-0.731710, 0.308530, -0.083210, -0.656220, 0.548810, -1.414150, 0.937930, -0.682590, 1.783690, -0.305690,
0.083440, -0.487300, -0.516450, 0.265950, 0.809660, -0.209760, 0.100270, -1.263110, 1.609780, -0.577490,
0.548500, 0.181330, 0.914700, 0.932610, 0.059820, 0.222100, 0.876430, -0.191450, 0.754330, 2.312130,
1.811490, -0.644960, -2.370940, 5.088330, 3.940390, -3.202910, 1.147400, 0.138990, -0.099440, -2.302630,
-1.268200, -0.485030, 0.203360, -0.794970, -6.792500, 1.659370, 0.258920, -0.578640, 6.489660, -0.158130,
18.126490, -2.798490, 0.921660, 2.098900, -0.709920, 0.596550, 0.324380, 0.518160, 2.532930, -0.294950,
-0.482520, -1.188010, 1.657960, -1.973090, -0.086080, 0.443750, -0.088340, 0.651820, -1.194960, 0.647590,

-1.376430, -0.037180, 0.023800, -1.347660, 0.291750, -0.932980, -0.194850, -0.676670, -0.596730, 1.064460,
-0.954920, -0.414800, -0.162110, -0.064380, -0.514510, -1.027650, -0.566710, 0.157940, -0.325760, -0.417350,
-0.077960, -0.227900, -0.438850, 0.540370, 0.221990, 0.033930, 0.654450, -0.041700, 0.945190, -0.176050,
-0.749700, 0.064580, 0.097410, -0.351440, 0.506670, -0.378440, 0.523450, 0.697650, -0.117260, 0.389030,
-0.520930, -0.950290, -1.082410, -0.443760, -0.046400, 0.194110, 0.703030, -2.643560, -0.836090, -0.875560,
0.532200, 0.151180, 0.206450, 1.444810, -1.306780, 0.324850, 1.354850, -0.975050, -0.961000, -0.369800,
1.668650, 0.148440, -0.064130, -1.175040, -0.513850, 0.968450, 0.010250, -0.496330, -0.522110, -0.329040,
-0.461040, 0.016590, -0.104060, -0.928590, -1.444400, 0.943370, 0.183860, 0.442290, -1.634930, 0.591860,
-0.674820, -0.517950, 0.694900, -0.226740, 0.537180, -0.226210, -0.225860, -0.871980, 0.622700, -0.287610,
0.275910, -0.388060, 0.163940, 1.423730, 0.570810, 0.886290, 0.536190, -1.086430, 0.750600, 0.557020,
2.197680, -0.317590, -2.061080, -2.561530, 2.157010, -0.079820, 4.535920, -0.281710, 0.188500, -0.303160,
-0.225680, 0.356160, -0.978070, 1.014770, 1.223530, 0.307710, 0.169300, 0.750860, -0.943110, 0.735390,
0.902270, -0.041850, -0.424170, 0.585990, 0.400260, 0.743180, 0.361140, 0.524900, -0.345500, 0.177650,
-0.388430, -0.715650, 1.167670, -0.608800, 0.513610, -0.832700, -0.206240, 0.513030, -0.596870, -0.272790,

-3.167920, 0.055350, 0.106590, -0.421300, -1.319360, 0.548650, 2.059450, 0.262900, -0.658350, -0.772920,
-0.460530, -1.660050, 1.247740, 0.315490, -0.324430, 0.196970, 0.643730, 0.819020, -1.483780, 1.005340,
-0.054660, 0.516280, 0.521210, 0.007540, 0.416140, 0.553230, 0.762580, 0.854300, -0.406080, -0.327800,
-0.690810, -0.248110, 0.512680, -0.284550, 0.408680, 0.601790, -0.096770, 0.705890, -0.826010, 0.455340,
-0.602230, -0.663400, -2.320400, -0.623630, -0.789950, -0.593960, -0.226640, 0.727130, -0.559000, -0.543770,
-2.075230, 1.680070, 1.016010, -0.252580, -0.197890, 0.872060, -1.137350, -0.310900, 0.218770, -2.041130,
3.455800, -0.837460, -0.769560, 0.171010, -0.814500, 0.187020, 2.895190, 0.358910, -0.167260, 1.706450,
0.875650, 0.730240, -3.681200, 0.090760, 4.224150, 0.259720, 0.736390, -0.640170, 4.828750, 0.467410,
-1.874550, -8.371650, -0.508010, -0.097590, 11.946520, 0.905700, 1.019870, -0.506470, 0.135770, -0.837160,
-24.290430, 0.162900, -0.236440, -8.425500, -0.287720, -1.375140, -12.753130, 0.710400, 1.815550, -0.593560,
-0.243100, 0.560620, 1.324370, -1.010480, 1.389050, -1.998980, 3.668940, 3.287560, 1.432050, -1.463170,
-0.058180, 0.244440, 0.091360, -0.908790, -6.030150, -0.953020, -0.656310, -0.643200, -16.274860, 1.297540,
-27.458450, 0.805380, -0.453380, -0.509900, 0.244020, 0.724030, -0.479320, -0.177610, 0.654270, -0.102130,
-0.018630, -1.444000, 0.695600, -0.720830, 0.776560, 0.478200, -0.870640, -0.830960, -0.599390, -1.155530,

-2.104120, -1.094880, 2.128670, -1.420140, -1.671170, 0.016200, 2.552610, 1.522850, -0.532500, 0.224270,
1.413510, -1.710600, 0.534060, 0.308270, -2.381410, -2.314890, -0.869220, 3.689480, -0.344720, -0.119620,
4.468500, 1.076940, 2.295640, 0.419750, 0.680730, 0.090990, 2.245760, 1.391330, 0.707360, -0.754880,
-0.509380, 0.054200, 0.922270, -2.339940, -0.881790, 1.771480, -0.679320, 0.950760, -1.468150, 0.209250,
0.003490, -3.011890, 1.358070, 0.760560, 5.369440, -3.250790, -2.245330, -4.561080, 0.293040, 0.679680,
2.468370, -0.427410, -1.538600, -0.572880, -2.638550, 0.162490, -0.134710, 4.270720, -5.351210, 2.799320,
-5.046370, 1.064700, 0.276030, 4.385560, 0.971170, -2.638940, -0.124210, -0.011470, 1.576980, 0.542970,
4.998460, -0.163960, 1.375150, 0.585120, -0.257900, 0.477930, -1.381900, 1.827950, -0.600270, -0.631430,
1.143490, -0.098300, -1.070160, 0.804440, -0.489360, -4.437200, -3.340280, -1.939430, 0.342770, 1.441870,
0.080590, 1.516660, 0.104380, -0.052940, -0.655830, -0.035190, -5.040820, -1.517280, -0.173010, -3.415930,
3.300400, -3.020440, 0.859620, 0.717800, 6.900860, -4.057740, 3.606520, -4.271320, -4.801650, 4.057030,
1.220990, -2.375840, 0.476090, 0.092990, -8.742200, -2.904630, 0.360290, -2.338900, -1.866300, -0.640720,
11.074060, -0.789220, -1.744640, -0.565310, 0.310110, 0.729710, 0.218590, -2.465660, 4.575150, 1.063280,
-0.842510, -0.684960, -2.465680, 0.098200, -0.689600, -0.195820, 3.505280, 0.481160, 2.035460, 0.599300,

-1.118510, -2.293990, 0.471970, -1.060480, 0.068880, -1.500600, 2.755690, 0.873210, -0.258760, -0.001590,
-1.070900, 0.288100, 0.577940, 2.067140, -2.202760, 2.014000, 1.846410, -2.427290, -2.958150, -3.208100,
0.614390, -1.422250, 0.233000, -0.010550, -0.899970, 0.516870, 1.378400, 0.321610, -2.153790, 2.505170,
-0.308430, -0.358130, -1.751530, -2.080380, -0.615980, 18.327971, -1.568550, -0.341860, 10.509590, -0.742680,
-0.682460, -6.412640, -0.620350, -0.205440, 11.275230, 0.351340, 0.811760, 6.715290, 0.549020, 0.620540,
-2.729250, 1.039150, -3.444680, 2.553160, -2.909910, -0.910410, 4.455170, 0.071710, -0.557020, -3.391150,
-4.131980, -2.803340, 0.920160, -1.864400, 0.129540, 5.208680, 1.023420, 2.040540, 3.756940, 0.221140,
0.856560, -1.634790, -1.982940, 0.432370, -1.369310, 1.716280, -0.032120, -0.322790, 2.121990, -0.602110,
-2.973060, -0.444220, -0.888550, -4.739760, 0.956780, 0.427610, -0.834050, 0.843100, 2.543100, 1.602810,
-2.108800, 0.176130, 7.494250, -2.524340, 1.957000, 1.941050, 1.353650, 3.474660, -0.747860, -2.308800,
-5.833160, 3.729250, 7.100000, -13.963530, 1.387800, -12.758820, 1.074870, 0.692070, -0.768800, 2.847470,
-0.527010, 0.967980, -0.485110, -0.846260, 0.310690, 0.216520, -0.279540, 0.219670, -1.991280, 0.372110,
-6.729040, -1.695160, -4.205910, 0.560870, 0.287950, -0.487120, 0.558980, -0.810940, -0.996140, 0.015370,
4.201600, 0.550340, -2.579110, 2.513640, -0.903780, 0.307120, -0.848300, 0.700990, 4.180520, -0.490380,

-0.117470, -0.558010, -0.244760, -0.322640, 0.598240, -0.022100, 0.109900, -0.550730, -0.045810, 0.953580,
-0.001840, -0.324300, -0.082260, 0.410620, -0.169790, -0.419370, -0.565630, -0.494260, -0.606170, 0.332050,
0.342490, 0.418840, -0.487300, 0.328160, -0.465520, -0.300800, -0.483250, -1.099770, -0.021710, -0.716170,
0.230280, 0.375040, 0.690420, 0.044480, -0.517690, -0.770090, -0.344430, 0.513330, 0.993990, 0.760600,
-1.009190, -0.677380, -0.478760, -0.737850, -1.186560, 0.240530, -0.543010, 0.752620, 0.048570, -0.145430,
1.145970, 0.305460, 0.067900, -1.539030, 0.043150, -0.602830, 1.006150, 0.080940, 0.033670, -1.326360,
-0.293640, 0.225040, -0.140010, -0.091240, 0.809610, -3.592800, -0.162260, -0.115730, -0.522060, -1.987150,
-0.959890, -0.156110, 0.457600, -1.052410, -1.882090, -0.677530, 0.728800, -0.680320, -0.101470, -0.099230,
0.663310, -0.686660, -1.102550, -0.746390, -0.239970, 0.605960, 0.237650, -0.631190, -0.677310, -0.283540,
-0.048090, -1.343140, -0.928210, 0.132340, 0.359820, 0.540520, -0.088490, 0.091260, 0.046720, 0.290600,
0.731870, 1.663370, 0.207140, 1.536440, 0.713910, 0.562100, -0.491090, 0.000860, 0.683220, 0.330310,
0.629020, -0.000430, -0.428890, -0.520940, 0.596160, 1.218490, -0.313030, 0.701800, 0.254410, 0.935360,
-0.295440, -0.142390, 0.656460, 0.901730, -0.107020, 0.288850, 0.114330, 0.994200, -0.256440, 0.212090,
0.093430, -1.121130, 0.422160, 0.284020, -0.325290, -0.064210, 0.355240, 0.567320, 0.430010, 0.458250,

-0.903950, 0.143290, -0.419740, 0.999870, -0.856800, -0.440470, -0.817840, -0.576030, -0.114010, 0.771830,
0.216680, 0.318720, -0.434220, -0.391570, 0.706060, 0.914060, 0.346890, -1.071170, 1.022380, 0.593070,
-1.297780, -0.440110, 0.932830, 0.620530, -1.691800, -0.085340, -0.466840, -0.302440, -0.373680, -0.678910,
-0.432120, -0.482280, 0.355830, -0.618200, 0.880260, 0.345740, 0.517220, 0.711600, 0.447680, 0.572840,
2.825170, -0.349880, 0.227260, -5.106740, -0.701610, -0.993470, -0.504170, -0.312740, 2.058480, -0.397550,
0.737830, 0.353840, -5.385230, 1.348890, 0.084240, 0.518520, -0.609990, 0.098810, -0.356780, 0.896730,
3.093380, -0.503080, 0.366200, -5.769990, -0.339500, 1.872590, 1.999170, 0.874570, -0.113900, 0.791040,
0.016260, 0.375190, 0.366140, 0.826720, 1.040590, -0.004000, -0.151710, 0.882080, 0.353210, 0.617150,
0.309380, -1.361320, 0.994160, 0.866350, 2.593580, -0.767010, 0.652290, -2.004470, -0.819320, -0.243920,
0.268370, -0.066270, 0.753500, -0.714090, 1.179960, -0.220060, -0.413330, 0.998770, -1.046650, 0.496740,
-0.825090, -2.185390, -6.421810, 2.940530, 6.082120, -0.093850, 1.359190, -7.340760, -0.054960, -0.754460,
-1.107710, 1.686600, -0.153040, -0.298050, -1.025440, 0.570770, -0.320120, -0.603420, -7.578480, 0.139790,
-3.469730, 0.634910, 0.697590, -0.451640, -0.618480, -0.177430, 0.078190, -0.407440, -2.173040, -1.659130,
0.381440, 0.367040, -0.565790, -0.627180, -0.301830, 0.322100, 0.897490, 0.396870, 1.121660, 0.377910,

0.928700, -1.990800, -1.879990, -2.236280, 0.873210, 0.975590, 2.634330, 0.690230, -0.138940, 0.404120,
0.536680, -0.803970, -1.653390, 0.939270, -0.685870, 1.287720, -0.277320, -0.474490, 2.368040, -0.565060,
0.793010, -1.856170, 1.002860, -0.073250, 0.115250, -0.560240, -0.950560, -1.596360, -1.294840, -1.087340,
-0.726130, -3.611540, 1.126750, 0.646660, 2.474700, -0.744460, 1.120940, -1.285080, 1.074530, -0.539680,
-1.972190, -0.417580, -0.864790, -1.372220, 1.305080, -1.652870, 3.305280, -0.509090, -0.627480, -1.935860,
-1.718870, -0.164660, -5.731130, -0.030750, 0.675490, -3.650330, 0.672910, -0.877920, 5.083480, 0.201750,
1.034930, -2.520240, 0.639040, 0.972160, -3.134740, 1.483730, 0.931100, -0.656740, 0.846710, 1.130760,
2.140480, 0.961270, 0.133680, -0.435820, -0.551540, -0.376060, 0.808360, -1.263710, -0.175370, -1.032290,
0.467510, -0.074820, 0.424350, -0.678530, 0.981960, -0.500350, 1.723080, -0.347680, 1.860980, 1.578130,
0.493190, -0.096930, -0.192080, 0.398410, -0.476120, -0.399370, 0.325520, 1.607460, 0.760940, -1.295350,
0.736110, -0.341280, 0.944110, -1.905580, -1.283400, 3.734510, 3.665480, -1.955140, -2.667130, -2.190190,
-0.142850, -0.040010, -0.290680, -0.379520, 1.826450, 0.200750, 0.107900, -0.339150, -3.783330, -0.684810,
2.679780, -0.627680, 0.544940, 1.714940, -0.054770, -0.018360, -1.705600, -0.596860, 0.718650, -0.679580,
-0.647130, -2.290520, -0.108760, 1.138810, -0.370670, -0.319160, 0.780040, 0.258040, 0.049130, 2.247610,

-0.248450, -0.315180, -0.848410, -0.035060, 0.073690, 0.577600, -1.971920, 4.285440, 0.261580, 2.231910,
-0.073150, -2.584360, 0.001660, -0.496350, 0.856890, -2.059810, -0.425490, 2.173150, 0.592060, -1.238770,
0.238260, -1.052810, -0.234320, 0.078870, -0.413090, 1.189220, 0.672920, 2.260910, 0.636640, -1.388040,
0.150510, -0.393900, 0.962000, -1.252930, -5.241220, 0.344150, 0.495070, 3.660580, -0.826700, -0.709830,
-0.451850, 1.152210, -1.087370, -0.484470, 2.596520, 0.231460, 0.082960, -0.818460, 1.110210, 1.101620,
-2.013590, -0.678490, -1.775040, 1.633180, 3.690550, 2.058420, -0.162440, -0.231680, -1.615450, 3.458750,
1.910250, 1.257210, 1.210250, -0.644150, -1.162780, 1.679220, -0.253600, -1.509190, 1.920530, -0.473830,
-0.197990, 0.412700, 0.425580, -1.532000, 1.968120, -0.380650, -2.442010, 3.620290, -0.967760, 1.940100,
-0.654350, -2.507310, 0.759530, -5.180870, -1.080890, -1.725600, 3.073140, 0.402010, 0.182260, 0.484340,
2.680680, -2.611330, -0.868970, 1.383500, 0.474130, 0.598160, -0.288590, 4.394750, 0.664500, 1.074830,
-1.557080, 1.169030, 1.899530, 2.697050, -0.805220, -1.346340, -0.263780, -0.552020, 1.087530, -4.433610,
0.998210, -1.112470, -0.444110, 0.613990, 4.860100, -1.250440, -1.457430, -0.901330, 0.604370, 0.198390,
-8.181510, 0.795890, 3.122710, -1.144510, -0.946850, 0.722350, -0.841500, -3.903810, 0.027530, 1.718690,
-1.645150, 0.590980, 0.577780, 0.133070, 1.259700, -0.261360, -0.096670, -0.637020, -2.318490, 0.226840,

0.593730, -0.651910, -0.372850, 0.009710, -0.578040, -0.483750, -1.859690, -1.226260, 0.615630, 0.841240,
1.629460, 0.396450, 0.003910, -2.019080, 0.001670, -0.025620, 1.419080, 0.607840, -0.472860, 0.318430,
0.969430, -0.198150, 0.539280, 0.036870, -0.492690, -0.036220, 1.424110, -0.523860, 1.260680, -0.991540,
0.446300, -0.520620, 0.045660, 0.673780, -0.964700, -0.908710, -0.130320, 0.655500, -0.476840, -0.312400,
0.630850, 0.641500, -0.727560, -0.648370, 4.857790, -0.061170, -0.415770, -5.602830, -0.450200, 0.850840,
2.833170, -0.819600, -4.111810, 1.326170, -0.804060, -0.147890, 20.202240, -0.021870, 1.029040, 2.123970,
-0.868100, -0.135850, 1.671680, -0.516150, 1.179000, 9.751220, 0.963330, 0.259680, 0.811760, -0.745470,
-5.211690, 0.010520, 0.039730, 2.126480, -4.307210, -0.253220, -1.220380, 2.505080, 1.596260, -0.343260,
-0.134090, 0.170480, 2.312970, -0.051770, 1.015890, 1.309370, 2.065710, 0.370440, 0.527770, 1.165460,
0.710310, 3.796960, -0.957020, 0.054600, 1.391930, 0.791720, 0.001370, -2.088120, -1.992620, 1.434930,
-0.101590, 0.862500, -0.216370, -0.632190, 2.163830, 0.453280, -2.559320, -0.381990, 3.059230, -0.219480,
0.125720, -3.434000, 0.499060, -0.980110, -2.744880, 1.999520, -0.441180, 0.319120, 1.829690, 1.086160,
-0.004310, -0.835620, -0.404980, 0.587900, -0.564030, 1.105860, -0.144420, -0.656950, -1.283970, -1.035830,
-0.748700, -0.223460, -0.613720, -0.071590, -1.520110, -0.186340, 0.166020, -0.402340, 0.268070, -0.334130,

-0.058780, 0.746270, -0.161500, -0.874120, 15.693720, -3.506240, -0.181420, -8.075630, -0.288850, -0.313730,
-0.140620, -0.697650, 0.694580, 6.664500, -0.507630, 0.097050, 15.585090, -0.215940, -0.057490, -7.684510,
1.587930, -0.663840, -1.027580, 0.841660, 0.110130, 3.600070, -4.912680, -0.735550, -12.085420, 2.301150,
-0.081980, 0.153270, -2.614880, -0.637960, 0.465900, 2.278270, -0.901100, 18.553391, 0.830480, 0.857410,
-22.253920, 0.209060, 0.244110, -16.061590, -0.052850, -0.336650, 12.943330, 4.371690, -0.156860, 2.084580,
-0.182560, 2.184960, -1.814520, -2.727990, -0.471530, 23.778761, 0.894940, -1.173550, -7.338140, -0.503220,
3.370160, 1.833380, -0.005560, 0.666310, 6.894560, -0.943540, 1.190850, -8.864050, 0.777780, 2.818160,
-0.058550, 0.534540, 0.990800, 2.815400, 0.777230, 2.881350, -1.808320, 1.579050, -4.322550, 1.514440,
-0.028120, 2.082570, -3.713470, -0.955960, 0.708090, -0.910540, -0.849190, -0.041020, 1.736850, -0.570910,
-0.213180, -1.986590, 0.492730, -0.507640, -0.790490, 3.837710, 1.704260, 1.425280, -0.829910, -6.950390,
0.821260, -1.661060, -1.850230, 0.765510, -1.781000, -8.931430, -3.034590, 9.928270, -1.730670, -5.247930,
0.736300, -4.078470, 3.253820, -0.151220, -9.649110, 6.683960, -0.491100, 1.944560, 10.731630, -0.055900,
-4.771870, 3.324610, -1.618980, 0.689760, -0.330600, -0.544720, 0.690070, 2.657740, -0.904360, -0.804750,
1.824410, -2.209510, 4.557060, 0.183210, -1.964340, -0.276460, 0.597040, 0.679800, -6.072470, -1.393100,

418.760071, 417.661133, 417.496643, 418.679169, 418.911133, 417.098816, 418.676819, 417.407410, 418.894867, 418.678070,
418.871887, 417.828857, 419.009552, 417.360748, 417.809448, 418.201324, 418.552551, 417.711182, 418.352722, 417.300842,
418.195923, 417.583191, 146.015747, 418.931946, 417.555908, 417.312317, 418.953857, 417.100311, 145.860672, 418.008545,
417.590393, 145.293716, 417.343689, 417.345856, 417.496155, 417.748596, 418.419891, 145.164017, 418.794708, 417.564453,
144.530197, 145.585785, 418.685089, 418.423065, 146.104156, 418.256989, 145.219635, 144.763062, 145.543564, 146.151382,
145.634064, 144.349136, 417.865967, 144.811005, 144.490662, 145.953918, 145.479034, 145.541763, 417.974487, 144.793411,
144.945465, 417.729156, 417.052307, 145.891846, 418.858978, 145.598755, 145.668869, 417.075470, 417.163971, 418.787903,
417.615326, 418.915344, 144.630936, 418.284454, 417.137665, 144.026474, 418.455109, 418.332916, 417.401825, 145.011032,
418.385529, 145.161118, 417.638123, 417.989777, 419.009949, 418.638428, 417.528107, 417.047058, 417.479462, 417.318756,
418.044434, 417.326263, 417.909882, 418.662811, 417.264160, 418.722656, 418.774353, 418.683777, 417.535614, 417.306519,
417.758575, 418.222687, 417.935852, 418.207092, 417.132782, 417.401276, 417.910248, 418.342224, 417.544769, 417.149170,
418.697479, 145.849884, 417.918610, 417.163361, 417.049255, 417.239624, 417.410004, 417.959106, 146.110886, 145.560333,
419.014008, 145.703796, 418.065094, 145.731110, 417.189362, 418.759735, 418.922272, 144.727631, 145.050491, 417.416931,
418.950104, 145.245682, 418.017426, 417.727020, 418.537476, 418.238647, 418.510162, 418.739502, 417.538361, 418.330292,

-1.757300, -0.604260, 0.754440, 0.569230, 3.626610, -1.326500, 0.691260, -2.896050, 1.112150, -0.347220,
-2.284660, 2.157710, -0.909960, -0.283930, -1.107930, 2.646310, 0.212700, 1.668850, 2.823340, 2.152190,
0.078600, -1.248190, 0.487770, 0.610290, -1.225740, 1.380400, 2.516760, -0.738740, -0.696290, 0.272480,
-0.570820, 0.572400, -5.032680, 0.424930, -0.512350, 0.285800, -0.536120, 0.063500, -0.564540, -0.302870,
0.637440, 0.289810, 1.597980, 4.828760, 0.118950, -0.845060, 0.811300, 3.247010, 0.620340, 0.183600,
0.517110, 1.262380, 1.589260, -0.057780, -0.022470, -2.710190, 0.068100, 0.505720, 0.374240, 0.122900,
-1.341790, 2.934660, 0.011560, 0.258150, -1.222720, -2.402010, 0.615230, 2.237750, 0.877850, 0.591150,
4.875450, 0.712350, -0.236380, -4.954490, 0.287040, 0.764100, -0.133810, 1.633250, 0.445900, 6.760430,
1.322200, 0.035150, -1.478680, -2.635800, -0.052260, -1.936170, 1.002340, 0.033160, 12.483590, 1.999610,
-0.692090, -10.189190, -3.754520, 0.948890, -5.857740, 2.586960, 0.216570, 1.768780, -2.995660, -3.160480,
2.333980, -2.654140, -13.553360, -3.465180, 11.231120, -0.798380, -34.940990, -7.476490, 8.462210, 0.081930,
0.728930, 0.083680, 0.385670, -1.724430, 0.986470, -0.171430, 1.195820, -1.143970, -8.741420, 0.789500,
-0.524530, -0.417690, 0.665710, -0.211170, -0.388640, -0.567720, -0.720450, 0.277290, -6.170680, 0.671790,
0.771710, 0.483920, -0.009670, 0.914560, 0.615340, 1.023920, -0.819040, -0.803930, -0.467440, -1.515380,

0.323730, -0.893530, -0.297300, -0.612310, -1.267150, -0.688750, 0.352350, -0.044000, 1.088680, 0.288770,
0.604360, 0.374760, -0.180740, -0.239280, -0.412650, 0.377910, 0.076130, -0.533850, -0.533640, -0.571800,
-0.242190, -0.643890, 1.400610, 0.076570, -0.135110, 2.088880, 1.063290, -0.955840, -0.583680, 0.071070,
-0.184120, -0.711250, -0.151780, -1.098960, 1.724590, -0.910760, -0.729030, 1.681450, 0.222850, 0.233050,
-1.277570, -0.888850, -0.138740, 0.642990, 0.539380, -0.065140, 3.038620, -0.731130, -0.377580, -0.590020,
0.047020, 0.273410, -1.092610, -0.228720, -0.506370, 0.753580, 0.488270, 1.114220, 0.186510, -0.788480,
-0.369010, -0.365210, 0.313010, 0.486420, 0.770760, -0.116230, 0.765070, 0.118750, 0.741040, -0.940370,
0.019910, -0.529100, 0.544710, -0.698460, 1.009460, -0.255070, -0.121130, -0.274170, -0.463760, -0.818340,
-0.505480, 0.892750, -1.546170, 0.623480, -1.362050, -0.365320, -0.170580, -1.112970, 0.626490, -1.078650,
-0.633050, 0.472540, -0.275990, 0.151330, -0.432040, 0.037270, 0.685300, 1.138290, -0.336730, 0.131820,
-0.549200, 2.910030, -0.748150, -3.362650, -1.092970, 0.324730, -0.050160, 0.242470, -0.007800, 1.693150,
0.356890, -0.984520, 1.109750, -0.364720, 9.735530, -0.263920, -0.669630, 0.137110, 11.106110, -0.019530,
-1.436650, -0.087630, 1.678430, -0.726200, 0.785050, -0.695910, -0.247690, 0.446440, 0.257500, 1.008760,
0.830280, 0.087610, -0.081200, -0.928940, 0.523480, -0.400180, 0.885320, 0.924840, 0.493220, -0.527290,

0.164810, -0.334490, -0.135780, 0.036440, 0.096950, 1.323640, 0.254190, 0.172700, 3.456600, 0.702710,
2.121430, -0.669110, -1.728880, 0.203190, -0.074570, -0.895060, 0.232850, 0.099790, 0.679400, 0.261620,
0.285310, 0.919870, -0.451120, -0.061630, -0.269520, 0.234010, 0.813140, 0.212780, 0.648510, 0.111220,
0.306070, -0.787490, -0.041900, 1.062930, 3.883660, -0.818570, -2.973920, 0.115240, -0.633550, -0.002470,
0.452020, -0.919420, -0.160740, 0.956670, -0.267960, 0.387230, 0.053050, 0.682480, 0.376840, -1.347190,
2.641460, 0.344170, -0.435600, -0.696950, -0.604020, -0.709090, 0.704070, -0.265950, -1.312520, -0.859100,

0.574320, 1.485560, -0.632880, -0.620820, -5.422490, 3.274630, 2.083340, -0.553380, 4.196140, -0.738520,
-1.065410, -5.970290, 0.537870, -0.238250, 0.963290, 0.529190, 0.072770, 0.159920, 1.751170, -0.080380,
-0.517330, 2.106930, 0.346540, 0.150600, 1.333220, 0.056950, -0.724310, 0.045410, -0.583660, -0.631360,
0.036330, 0.406360, -0.906390, -0.462710, 0.319810, -0.723790, -1.195240, -0.849390, -0.438490, 0.804470,
0.488320, -0.519400, 0.663110, 0.868090, -1.033290, -1.673560, -0.137810, 0.157630, 1.389530, 0.218860,
0.092300, -1.000630, 0.701520, 1.446770, -0.886700, 1.562490, -0.610780, -0.772990, -1.583270, 0.257000,

-0.112880, -0.050140, -0.224030, -0.653010, 2.679700, -0.111170, 0.337650, 0.853050, 2.545960, -0.121590,
-0.945200, 0.137300, -0.597920, 0.425310, -1.226300, -0.914870, 0.116880, 0.387940, 1.041390, -0.342560,
0.476350, -1.124950, 0.617410, 0.888190, -0.417540, 0.240600, 0.925500, -1.036170, -0.634530, 1.274390,
-0.398120, -0.010290, -0.386980, 0.418190, 1.483350, 0.894250, -0.328020, 0.161610, 0.531770, 1.009320,
0.425810, -0.323180, -0.506100, -0.416170, -0.068540, -1.089620, 0.064450, 0.598930, -0.696950, 1.510680,
-0.235320, -0.451280, 0.037830, 0.713560, 0.051080, -0.377810, 0.352960, -1.437660, 0.715730, -0.047320,

-1.053430, -0.891070, -0.558600, -0.495450, 3.558990, 1.210980, 2.386650, 1.550380, -9.424480, -0.680020,
-6.781360, -0.491770, -2.803080, -0.452470, -0.103820, 0.228720, 0.207970, -1.917250, 2.210240, 0.816730,
0.802510, 0.796590, -0.143150, -2.161540, -0.023040, -0.750780, -0.438520, 0.022630, -0.227280, 0.196430,
0.884550, -0.641940, 0.044870, 0.210270, -0.041060, -0.876470, 0.322430, 0.465180, 0.260700, -0.154700,
-0.930170, 0.466790, 0.019290, -0.042800, 0.853910, -2.634100, 0.362590, -0.081090, -0.020850, -0.892690,
1.437740, 0.831340, 0.265260, -1.311050, -1.713180, -0.784310, 0.109730, 0.520810, 0.565530, -1.800860,

3.969960, 2.599660, -1.035380, 0.267770, -1.912850, 4.334540, -0.546810, 0.475520, -376.077454, 0.760970,
-1.153940, 1.231150, 10.212770, 1.288280, 0.488880, 0.103220, 0.872680, -4.341070, -88.939217, -4.776190,
-3.390490, 2.791920, 4.755600, 1.526060, -6.368170, -4.097030, -0.890790, -0.296100, 2.568020, 0.636770,
-1.257430, -0.757410, -1.105900, -0.881810, 4.434960, 0.336730, -0.149400, -0.541490, -1.204200, 0.052880,
-0.003700, -1.144200, -0.341980, 1.574160, 0.071630, 1.901560, 1.390700, -0.485100, -1.665160, -1.628270,
-2.530790, -0.348310, -0.222540, -2.302070, -0.399520, -0.468980, 0.554940, -1.629240, -0.528720, 0.866800,

-0.852790, -0.659860, -0.054460, -1.013640, -2.569530, -1.827360, -0.046980, 0.611000, -0.693410, 0.382050,
-1.866590, -0.406340, -0.715320, 0.203110, -0.467730, 0.887690, -0.447060, 0.040350, 1.431220, -0.747540,
0.268620, -0.604030, -0.272620, 0.420360, -0.025850, 0.400480, -0.392460, 0.911400, -0.607810, -0.309330,
0.450410, 0.036120, -0.255100, -0.391840, -3.164760, -0.678330, -1.028330, 0.300140, 0.062510, -0.137010,
0.672400, 0.656540, 0.825240, 0.246740, -0.545750, -1.368850, 0.173880, 0.519930, 1.171030, -0.078000,
-0.203480, -1.476470, 0.333880, 0.344410, 0.820480, 0.946900, 0.509480, 0.223250, -0.438510, 0.408010,

-0.110500, -0.460040, -0.053360, -0.782670, -9.984370, 0.939440, 0.108570, -0.611660, -1.742760, -0.064600,
0.612320, 0.616780, -14.221460, -0.379380, 0.183290, -0.250880, -0.656940, -0.773610, -0.211870, 0.362940,
-0.811140, -0.938060, 0.170550, 4.098410, 0.450210, 0.552310, -1.104030, 0.478470, -0.601850, 0.094540,
-0.326540, 0.159760, 0.205600, -0.751180, -10.012010, -0.107640, 0.223220, -1.257700, 0.499540, 0.036460,
-0.272290, -0.525340, -0.314290, 0.365320, -1.692490, -0.481590, -0.343840, -2.481770, -7.646990, 0.932820,
-0.595890, 0.058020, 1.067700, 0.776560, 0.567630, 1.457580, 0.589160, -0.317020, -18.656330, 1.233950,

1.579320, -0.823530, 0.071480, 0.902880, 8.348780, 2.690480, -0.944160, -0.997220, -5.049030, 0.137730,
70.734863, -1.301540, 2.144040, 0.536040, 0.299430, -0.311780, 0.156290, 1.018850, -1.447980, 0.918240,
0.354430, -0.547770, -0.300850, 5.957160, -1.700390, -1.321350, 0.325040, 0.002180, 3.173940, 0.930740,
-0.399820, -0.318390, -0.889890, 0.371960, 10.964790, -0.743570, -0.872870, 0.873690, -1.054020, -0.394290,
0.214720, -0.171180, -0.423820, 0.707280, -0.375820, 0.074640, -0.017850, 1.890060, 2.533510, -0.367270,
-2.078510, 0.559530, 0.306700, -1.953080, -0.482930, -1.239080, 0.870540, 0.443170, -1.769040, -0.562700,

0.293470, -1.346310, 0.976970, -0.451310, 9.526450, 1.685540, -0.283720, 0.252050, 115.781487, -0.704060,
-1.934430, 0.122740, -1.644300, -0.794010, -0.547790, -0.352280, -0.405490, 0.079170, 1.089880, 1.025980,
0.720320, -0.645290, 0.010270, -0.464420, -0.486810, 1.137860, 1.193840, 0.162040, -0.997590, -0.455910,
0.340710, -0.276070, 0.203060, 1.027610, -41.070938, -0.386290, 2.792030, -1.098310, 0.170090, 1.424590,
0.333580, -0.574650, 0.516580, 0.974880, 0.138200, 1.807880, -0.037600, -0.718970, -0.388600, 7.409480,
4.252020, 0.025270, -0.630250, 4.223930, -2.130100, -2.880290, -0.144900, 1.142040, -1.329990, -0.865990,

0.379310, 0.266500, 0.363430, -0.801860, -1.959920, -0.276250, 0.196910, 1.002710, 2.593150, 0.696150,
2.208530, 0.313040, 0.322470, -0.728380, -0.560480, -0.134270, -0.392130, -0.462910, -0.214980, 0.838910,
-1.172540, 0.625090, -0.429790, 0.502600, -0.934530, -0.721570, 0.096350, 0.728380, -0.731810, 0.515510,
-0.770510, 0.107440, 1.071290, -0.093690, -42.814220, 0.372170, 1.257890, -1.080840, 0.756290, -0.292650,
-0.282180, 0.937310, 0.904940, -0.557950, -0.349030, 0.867260, -0.114440, -1.784180, -1.855720, 1.498780,
1.219620, 0.697210, 0.838590, 3.772480, 0.377880, -1.454770, -0.599070, 0.710110, -0.265090, -0.547710,

0.857760, 2.005470, 0.054660, 2.473390, 0.247610, -2.680880, -0.269580, 3.101160, 22.928160, -0.838450,
-1.184450, 0.023960, 1.422160, -0.866120, 0.612050, 0.749220, -0.526870, 2.600440, 1.150530, 1.447430,
-0.202890, 1.160400, 0.495850, 0.432750, 0.251090, 0.007330, -0.436810, 0.198400, 0.388120, -0.809900,
-0.911480, -0.210350, -0.426070, -1.009230, 38.551971, 0.375810, -1.596150, 0.348680, -0.027840, -1.000740,
0.886640, 0.919650, -0.145680, -0.427820, -1.181060, 0.218080, 0.023650, 0.129680, 1.719340, 1.321110,
-2.747080, -0.537160, -0.508410, 0.287480, -0.944730, -0.408330, 0.349770, -1.391550, 0.406170, -1.077470,

-1.572030, -1.051160, -0.405590, 0.519980, 21.101330, -3.713470, -2.030540, 0.605520, 3.545790, 0.612010,
-5.378280, -3.037380, -11.895310, -0.843720, 0.317320, -0.215490, 3.438860, 3.554480, 0.427970, -1.624740,
0.248140, 1.291670, 77.077332, 23310.960938, 151.345627, -2.467080, -0.228950, 0.477150, -1.799990, 0.363060,
-0.524920, -0.708880, 3.018790, 0.552650, 14.945430, -0.329340, -4.236250, 1.048500, 0.575980, -0.477990,
0.897400, -1.405700, 3.225990, 1.056900, -0.103330, -5.415010, 2.930120, 1.300170, -2.784030, -2.431770,
-0.545730, -0.573440, 0.791280, 1.736410, -1.149050, -1.660160, 2.344990, 0.706510, -18.198839, -2.830090,

-0.882720, -0.195420, -0.849960, -0.675930, -1.781680, -1.327630, -0.173170, 0.547000, -2.904070, 1.007580,
-0.357790, -0.225900, -0.760660, 0.714350, -0.352250, 0.772760, -0.650010, 0.902180, 1.718920, -0.676490,
0.136450, -0.038960, 0.184940, -0.144880, -0.363490, 0.528730, 0.555060, 0.026900, -0.221180, -0.870030,
0.723520, 0.719740, 0.212330, -0.009310, 10.162710, -0.029300, 1.107400, 0.424020, 0.466220, -0.171540,
-0.631990, 0.062020, -0.738950, 0.293580, 0.210550, 0.524040, -0.624910, 0.886650, 0.172240, -0.190780,
-1.436440, 0.460620, 0.085840, -0.989510, 0.920160, 0.673790, -0.983010, -1.264770, -0.004240, 0.689700,

0.284430, -0.334390, 0.139520, -0.028490, -0.180620, -1.180090, -0.096790, 0.282080, 2.550530, -0.233160,
-4.543070, -0.782160, 0.287510, -0.005530, 0.320740, -0.672010, 0.551620, 0.889910, 1.371570, 0.215060,
0.444910, -1.764330, -0.115400, 1.115770, -0.314860, 1.022500, -1.307350, 0.652140, 0.419190, 0.909400,
-0.327980, 0.519960, 0.512560, -0.958900, 19.940310, -0.215590, -0.829270, -0.082890, -0.158760, -0.392990,
-0.554870, -0.183810, 0.377040, 0.085430, 0.276990, -0.207810, 0.153550, 0.408980, 2.650590, -0.329670,
-1.268360, 0.561010, -0.245770, 1.586480, 0.260870, 0.668600, -1.164930, -0.501890, 0.613050, 0.433570,

0.089700, -1.206740, 1.386680, -1.025970, -5.025970, -0.222880, 0.053560, -0.385060, 8.762980, -1.117120,
4.414640, 0.147880, -3.412350, 0.256890, -1.062170, -0.198160, 0.532340, 0.873040, 0.340270, -1.282260,
-0.570230, -1.658320, 0.141960, 0.883580, 0.443660, 0.779170, 0.702700, 0.609140, -1.208980, -0.521860,
0.790970, 0.233310, 0.690340, 0.523930, 8.331160, 0.043160, -0.463780, -0.751730, 0.288760, -0.089690,
-0.080250, -0.993030, 0.496900, 0.515500, 0.836450, 3.013460, 0.646180, -1.135810, 0.127400, -2.023130,
1.173420, -0.675430, 0.610370, -0.562790, -0.023540, -1.022040, -0.774940, -0.218850, 0.373290, -0.365780,

-1.307210, 0.509720, -0.252720, 0.020410, -21.126089, -0.616480, -0.026210, -0.778780, 1.666330, -1.435140,
-8.749070, -0.174400, 0.614160, 0.093430, -0.067280, 0.136290, -0.186060, 1.219930, -0.483600, -0.299040,
0.403190, -10.029780, 0.431110, 1.250420, 0.352690, 1.501170, 0.092630, -0.856990, -0.368510, -0.433170,
-0.171210, 0.035160, 0.519520, 0.545690, -19.285770, 0.637190, 0.296760, 0.317180, -0.689460, -0.041160,
-0.871120, -0.297990, -0.993340, -0.276570, -0.287670, 1.511860, -0.395480, 0.544790, -0.077530, 0.991260,
-0.733120, -0.380820, 0.778550, 1.088520, 0.705460, -0.390650, -0.099600, -0.983750, 1.260770, 1.130500,

-0.431340, -1.526190, -0.933760, -2.708990, -0.065710, -11.636240, 4.522530, -1.297040, -0.495160, 0.500270,
4.224400, 2.028960, -3.596930, 0.735530, -1.064010, 0.676500, 0.884630, 0.873910, 0.039280, 0.345810,
-0.488510, 0.724430, 0.279130, 1.818260, -0.960760, 0.647820, -0.917030, -0.633550, 1.202620, -0.081430,
-0.034300, -1.745900, 0.200580, 0.387380, -38.589050, 0.658260, 2.027230, 0.864440, 1.299340, -0.623420,
-0.417950, -1.015280, 0.848850, 0.022890, 0.480580, 1.632470, 0.308240, -0.810230, -3.271430, -1.928200,
2.289650, -0.077160, 0.668180, -0.232370, -1.619180, -0.960360, -0.288760, 1.080780, -1.993530, -2.971820,

1.190130, -1.085700, -0.679180, 0.882720, 8.797070, 0.906640, -0.684270, -1.716770, -38.514309, -0.274060,
85.492577, -0.259450, 0.980000, 1.050980, 0.304310, -0.645840, -1.330050, 0.076370, -1.986920, 0.878770,
0.357830, 0.216640, -0.644340, 0.168910, 0.391580, -0.795040, 0.631670, 0.577070, 1.066180, -0.155250,
0.130730, -0.238900, -0.384620, -1.382530, 22.608080, -0.981680, -0.242800, -0.531950, 0.058950, -1.500170,
-0.967830, 0.420090, -0.360650, -0.454090, -0.273300, 1.879560, -0.269690, 0.365690, 0.271140, -0.606390,
0.257050, 0.220280, 0.894030, -0.538140, -0.994580, 1.626840, -0.110860, -0.826220, -1.266040, 0.397030,

1.031600, 0.957820, -0.795380, 1.177910, -2.545850, -1.532970, -0.660010, -1.037830, -93.472672, -0.708710,
3.952820, 0.220050, 2.583960, 0.449210, -0.073010, -0.807690, 0.508540, -0.201890, -2.547190, 0.269930,
0.374850, -0.024630, -0.812690, 0.227550, 1.094260, -0.902790, -0.790240, -0.270360, 1.595570, -0.003360,
0.008550, 0.637790, -1.287010, -0.871840, -20.177490, -1.122390, -0.522460, 0.691700, -0.516530, -0.818870,
-0.752130, 0.375010, 0.200240, 0.008110, 0.404320, -2.026960, 0.080120, 0.004670, 0.534070, 1.283570,
-2.911420, 0.219370, -0.989630, -2.898920, 0.606870, 1.836020, 0.622990, 0.606380, 3.099520, 1.170910,

-4.391710, 0.527780, -0.420860, -0.867640, 3.148000, -1.756960, -1.996600, 0.506640, 10.175110, 0.919640,
-38.585960, 0.808050, -0.887820, -1.252970, -0.319230, -0.259250, -0.049030, -0.279290, 2.349260, 0.155480,
0.211200, 1.028650, -0.617640, -27.427401, -2.145820, -0.549610, -0.010820, 0.859940, 1.388980, 0.447540,
-0.265890, 0.330950, -0.256810, -0.564320, -1.619480, -0.734360, 0.906310, 0.263290, -0.141590, -0.828650,
-0.367280, -0.600940, 1.093040, -0.372460, -0.512730, 0.564950, -0.780850, -3.906570, -4.128090, 1.315570,
0.749640, 0.708080, 0.608720, 0.711610, 1.105160, -0.276650, -0.391130, -0.537650, 5.781070, 0.481120,

-1.043040, 0.497860, 1.060690, 0.404900, 4.946300, 2.445960, -0.045220, 1.441030, -0.254890, -1.479100,
-0.565990, 0.151080, -1.839280, -0.691300, -0.769350, 0.549110, 0.230210, -0.312350, -0.389680, -0.375600,
-0.072010, 0.719900, -0.738970, -0.444890, 0.532260, 0.856930, -0.767190, 0.140730, -1.133390, -0.932230,
-1.059020, -0.193730, 0.841310, -0.242140, -17.238911, 0.801630, 0.521100, -0.391230, -0.464390, -1.420070,
0.085240, 0.853530, -0.924940, -0.967120, -0.386080, 1.932910, -0.707730, -0.396840, 0.899510, 0.962100,
-0.758740, -0.345470, 1.210160, -0.080830, -1.197650, -1.303420, -0.932910, 0.152230, 0.447860, -0.767050,

-0.423180, -0.078230, -0.896820, -0.697960, -2.815730, 0.077860, 0.053790, 0.829570, 7.430060, -1.955590,
-0.925740, 1.107740, -2.668260, -0.631840, -0.782530, -0.476150, -0.024840, 1.752470, -0.131050, -0.264670,
0.978380, -1.899330, 0.743160, -1.025900, -1.056560, 2.076440, -0.105370, -0.070070, 2.393240, -0.704610,
-0.082000, -0.420520, 0.100570, 0.625160, -2.847670, 0.409330, -0.369700, 0.185340, 0.951120, -0.822320,
0.920470, -0.365450, -0.777310, 0.388040, 0.126310, 1.845460, 1.657030, -0.589850, 1.046440, -0.966650,
-0.812410, 0.803280, 0.671990, 3.086720, 0.347870, -0.937380, 0.360310, -0.098930, 0.851960, 0.656230,

-0.302110, 8.942690, 0.265870, 0.186050, -2.466280, -0.172560, -1.093490, 1.039830, 3250.596924, 1.051450,
-2.143950, 1.090370, -2.826530, -0.123710, -0.138300, 0.078170, 0.358870, -0.884640, 0.961450, -1.609580,
-0.239910, -0.081370, 2.069360, -1.337040, 0.410270, 0.369740, 0.348490, 0.912120, 0.234450, -1.339410,
0.565550, 0.031230, 0.159700, 0.152500, 8.717910, -0.572600, 0.532570, 0.383420, 0.292450, 0.824640,
0.877290, -0.630710, 0.617540, -0.108070, 0.794380, -3.132770, 0.329890, 1.196360, 0.759660, 0.527170,
-0.442700, 1.177210, -2.247110, 1.490310, 0.636870, 1.253440, 0.650150, 0.850950, -2.207090, 0.038240,

0.082260, 0.472430, 0.499660, 0.403840, 2.501300, 2.271500, -0.641110, -0.666390, 4.499410, 0.576440,
-4.409510, -0.738900, 0.331350, -1.573030, -1.189560, -0.682640, -0.369880, -2.202150, 1.737950, -0.150850,
-1.027650, 0.008730, -1.663140, -13.792140, -0.265040, 0.464800, 0.339070, -0.831620, 0.606010, -0.472940,
0.176580, 0.442100, -0.001810, 0.421950, -3.392230, -0.884250, -1.584120, -0.744020, 1.263620, -0.003560,
0.908810, 0.009860, 0.715870, 0.533880, -0.077900, 0.141370, -0.328250, -0.060600, -0.789020, -0.231080,
-0.147560, -0.410810, -0.631110, 1.717550, 0.361580, -0.252960, 0.203220, 0.440470, 0.520100, 0.561820,

1.057800, 1.643790, 0.392540, -0.067450, -1.158270, 1.404190, -0.547810, -0.944240, -3.465100, -0.686550,
-1.858650, 1.038880, 1.799430, -0.414650, 0.445060, -0.052290, 1.253550, -3.521300, -1.095560, -0.045500,
0.280810, 0.867930, -33.993839, 2.407800, -1.146310, -2.926490, -0.591730, 0.316790, -0.430900, 0.452790,
-0.047940, -0.606340, -0.258410, 0.095590, -1.967200, 0.656980, 1.413550, 0.216690, -0.066350, -1.397230,
-0.194360, -0.346490, -1.171310, 0.569230, 0.536880, 0.535640, -0.671680, 0.430540, 0.009350, 0.924220,
1.030290, 0.452530, -0.704770, 1.548620, 2.400150, 1.700080, -0.121880, 0.555730, -0.149210, 1.348490,

-0.327900, -0.194410, -0.380060, 0.276160, 11.198010, -0.617010, -1.371780, 0.510300, -9.365870, 0.813110,
-4.649420, 0.155080, -1.808520, 0.195470, -0.994860, 0.141340, -1.046130, -0.786800, 0.713530, -1.424810,
0.624200, 0.066460, -0.402360, 1.922600, -1.034800, 0.569960, -0.392550, 0.650270, -2.277530, 0.116120,
-0.814940, 0.155060, -0.618260, -0.385060, -0.591990, -0.997450, -0.648880, 0.129300, -0.674730, 0.705320,
0.785510, 0.825380, 0.079020, -0.552360, 1.446110, -0.579700, 1.047070, -0.529950, -1.679610, 0.223790,
-1.487860, -0.715070, 0.548330, 0.971190, -0.768190, -0.377980, 0.637990, -0.673090, -1.929480, 0.611150,

0.020010, -0.638240, -0.187760, 0.618580, -2.623900, 0.807370, 0.435910, 0.157890, 1.452860, -0.094820,
0.772480, 0.284390, -0.576540, 0.436950, 0.355780, 0.449070, -0.092360, -0.574430, -0.964930, 0.282000,
-0.308520, 1.261770, 0.098080, -0.043720, 0.172030, 0.213760, 0.031900, 0.722880, -0.199900, 0.810170,
-0.103840, 0.441430, 0.034410, -0.300080, -2.193750, 0.725720, 1.028690, 0.064150, -1.065790, 0.003970,
0.596970, -0.291630, -0.118930, -0.000360, -0.562920, 1.204820, -0.106190, -0.175850, 0.729810, 0.659030,
-0.157160, -0.828260, 0.492550, 0.378550, -0.057980, 0.454390, -1.128960, -1.318880, -0.971570, -0.050240,

0.096280, -0.298640, 0.902010, -0.000930, -27.242710, 2.034730, -0.369210, -0.456980, 1.803710, -0.209630,
1.290600, 0.179230, 2.516840, -0.252530, -0.817430, -0.259110, 0.246340, -1.036150, 0.335890, -0.567850,
0.569400, -0.439230, 0.977600, 0.599310, -0.547350, 0.571660, 0.619060, 0.382470, -0.048360, -1.597270,
-0.483800, 0.280920, 0.577100, 0.405480, -1.659140, -0.103290, 0.598470, -0.278560, 0.865170, -0.697810,
-0.911340, -0.585210, -0.026600, 0.483580, 0.294430, 0.692470, 1.341650, 0.314260, -0.640310, -0.209090,
0.695520, -0.389460, -0.469990, -0.220590, 0.650160, -0.252250, 0.422560, 0.252520, 1.747380, 0.000710,

-0.001980, -16.766850, 0.826880, -0.131880, 0.023560, 0.043850, 1.402370, -0.291820, -1851.255371, 0.527860,
1.168230, -44.296841, 3.731440, -0.401920, -0.272780, 0.216820, 0.602410, 0.326210, 1.505460, 0.379240,
-0.465230, -0.797580, 1.307520, -1.149300, -0.248770, -0.250970, -0.034780, -0.750700, -0.014040, 0.890280,
-0.966820, -0.536290, 0.706570, -0.843860, 36.097179, -0.099010, -1.470360, 0.091960, -0.243920, -1.370420,
-0.714970, -1.283780, -0.234780, -0.061690, -2.276930, 1.823720, -0.689300, 0.564670, 0.399590, -2.850970,
1.486770, -0.327100, -0.225500, -2.995390, 0.811990, 0.810280, 0.484510, -0.337050, 1.349540, 0.770550,

0.235910, -1.906830, -0.491000, -0.436370, -4.450700, 0.811620, 2.013510, 0.653230, 0.557730, 1.329150,
3.762290, -0.029800, -1.125760, -0.492890, -0.108460, -0.931880, -0.658480, 0.081890, 0.633990, 0.352190,
-0.311920, 0.875100, 0.156430, -1.950110, 0.052960, -1.175350, 0.290530, -0.214900, 1.551470, 1.371100,
1.145750, 0.683820, -0.009080, -0.154560, 1.438390, 0.591570, 0.625800, -0.217160, 0.304360, -0.386080,
0.372000, -0.764350, -0.857110, -0.881060, -0.140200, 1.329180, -0.517610, 0.110840, -0.300340, 0.629550,
-0.888060, 0.265210, -0.045630, -0.692150, 0.184310, 0.800200, -0.957670, 0.191730, -0.067720, 0.478560,

0.094900, 0.539830, -0.612480, -1.013320, 17.737700, 0.685860, -3.501510, 0.508030, -1.309800, -1.042760,
0.541400, -0.690520, 0.475290, 0.002410, -0.480080, 0.706020, -0.891790, 0.075750, 0.349690, -1.197520,
0.483730, -0.204630, -0.553300, -1.342160, 0.239820, 0.162180, 0.205400, -0.818210, 2.129340, 0.666620,

-0.816680, 0.628980, 0.922150, -1.074150, -11.765580, -0.987840, 1.337990, -0.143990, 0.601300, 1.122230,
-0.390270, -0.806540, 0.694090, 0.667720, -0.256770, 0.617770, -0.629780, -0.379090, -1.771350, 0.481980,
-0.565670, -0.794750, -0.858750, 1.239600, -0.401600, 0.661480, 0.258630, -1.544330, -2.745920, 0.908140,

0.597560, -0.841450, -0.257610, 1.099390, -12.640550, 0.154540, -1.369170, 0.080460, 0.911540, -0.411650,
-0.055420, 0.674870, -0.997680, -0.936370, 0.327870, -0.622660, 0.730570, -0.238840, -0.626410, -0.515060,
-0.458640, 0.297170, -0.107080, -0.707950, -0.187450, -0.594510, -0.989040, 1.014190, -2.268220, -0.844030,

-0.403280, 0.408730, -0.557070, -0.905950, 21.065901, -0.790400, -3.466730, 1.161840, -0.733500, -1.210770,
0.008200, -0.366600, 0.425540, 0.100510, -0.984770, 0.199010, -0.633200, 0.408140, 0.906390, -1.691710,
-1.190490, -0.715070, 0.445140, -2.398370, 0.847570, 1.570420, 0.051820, -1.205290, 1.316070, 1.031270,

-0.703640, 0.944570, 0.181150, -0.553750, -14.509350, 0.870480, 1.235550, -0.247660, 0.338930, 0.933160,
0.042800, -0.106400, -0.914150, -0.850240, -0.361500, 0.316120, -0.886920, -0.468370, -2.539710, 1.118510,
-1.563730, 0.608240, -0.183610, 1.624940, 0.241670, 0.531380, -0.846230, -1.513800, -2.508740, 0.935310,

0.290960, -0.860500, -0.028680, 1.033900, -16.039970, -0.284820, -0.942250, 0.361700, 0.339870, 0.201150,
-0.196300, -0.548230, 0.348080, 0.174770, 0.808080, -0.291690, 0.738670, -0.341570, -1.018160, -1.094000,
1.386110, 0.859850, -0.728530, -1.425540, -0.895010, -1.199310, 0.783960, 1.394870, -1.402280, -1.292920,

0.510420, 0.252010, -0.755370, -1.086020, 18.650709, -1.153150, 0.040220, 0.880460, -0.764250, -0.446290,
-0.216430, 0.024170, -0.583530, 0.123180, -0.507620, -1.961310, -0.681630, 1.053070, 0.586370, -2.602600,
-1.997400, -0.234660, -1.073740, -3.078640, 1.028780, 1.697270, 0.571630, -0.381220, 0.483440, 1.253990,

-0.114740, 0.583230, -1.084700, -0.067300, -15.946950, -0.006090, 0.026500, -0.636440, 0.591360, 0.597100,
0.838920, -0.969820, 0.154770, -0.745280, -0.852550, -1.501240, -0.509010, -1.198000, -2.337330, 1.425370,
-0.559020, -0.327610, 0.902390, 2.293340, 0.422080, 0.821560, 0.006710, -0.087540, -4.545790, 0.810140,

-0.673390, -0.679420, 0.860420, 0.685820, -12.591150, 0.906500, -0.223660, 0.469770, 0.050390, -0.525210,
-0.980940, -0.240910, -0.457390, 0.590110, 0.679630, 1.877390, 0.591550, -0.897400, -0.705990, -1.495040,
1.089630, 0.373790, 0.651320, -1.766440, -1.328080, -1.481850, 0.026620, 0.080100, -0.559750, -1.209200,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.079020, 140,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (hid12) */
      0.0, -0.590880, 140,
       &Sources[140] ,
       &Weights[140] ,
      },
    { /* unit 113 (hid13) */
      0.0, 1.103290, 140,
       &Sources[280] ,
       &Weights[280] ,
      },
    { /* unit 114 (hid14) */
      0.0, 0.264440, 140,
       &Sources[420] ,
       &Weights[420] ,
      },
    { /* unit 115 (hid15) */
      0.0, 0.777820, 140,
       &Sources[560] ,
       &Weights[560] ,
      },
    { /* unit 116 (hid16) */
      0.0, 0.541860, 140,
       &Sources[700] ,
       &Weights[700] ,
      },
    { /* unit 117 (hid17) */
      0.0, -0.828610, 140,
       &Sources[840] ,
       &Weights[840] ,
      },
    { /* unit 118 (hid18) */
      0.0, 0.741550, 140,
       &Sources[980] ,
       &Weights[980] ,
      },
    { /* unit 119 (hid19) */
      0.0, -0.860890, 140,
       &Sources[1120] ,
       &Weights[1120] ,
      },
    { /* unit 120 (hid110) */
      0.0, -0.676010, 140,
       &Sources[1260] ,
       &Weights[1260] ,
      },
    { /* unit 121 (hid111) */
      0.0, -0.691430, 140,
       &Sources[1400] ,
       &Weights[1400] ,
      },
    { /* unit 122 (hid112) */
      0.0, 0.238790, 140,
       &Sources[1540] ,
       &Weights[1540] ,
      },
    { /* unit 123 (hid113) */
      0.0, 0.156450, 140,
       &Sources[1680] ,
       &Weights[1680] ,
      },
    { /* unit 124 (hid114) */
      0.0, 0.458700, 140,
       &Sources[1820] ,
       &Weights[1820] ,
      },
    { /* unit 125 (hid115) */
      0.0, -0.158900, 140,
       &Sources[1960] ,
       &Weights[1960] ,
      },
    { /* unit 126 (hid116) */
      0.0, 125.300217, 140,
       &Sources[2100] ,
       &Weights[2100] ,
      },
    { /* unit 127 (hid117) */
      0.0, 0.159520, 140,
       &Sources[2240] ,
       &Weights[2240] ,
      },
    { /* unit 128 (hid118) */
      0.0, -0.029140, 140,
       &Sources[2380] ,
       &Weights[2380] ,
      },
    { /* unit 129 (hid119) */
      0.0, 0.313570, 140,
       &Sources[2520] ,
       &Weights[2520] ,
      },
    { /* unit 130 (hid120) */
      0.0, 0.734560, 140,
       &Sources[2660] ,
       &Weights[2660] ,
      },
    { /* unit 131 (hid121) */
      0.0, 0.646330, 140,
       &Sources[2800] ,
       &Weights[2800] ,
      },
    { /* unit 132 (hid122) */
      0.0, -0.148580, 140,
       &Sources[2940] ,
       &Weights[2940] ,
      },
    { /* unit 133 (hid123) */
      0.0, 0.159300, 140,
       &Sources[3080] ,
       &Weights[3080] ,
      },
    { /* unit 134 (hid124) */
      0.0, -0.624890, 140,
       &Sources[3220] ,
       &Weights[3220] ,
      },
    { /* unit 135 (hid125) */
      0.0, -0.522480, 140,
       &Sources[3360] ,
       &Weights[3360] ,
      },
    { /* unit 136 (hid126) */
      0.0, 0.350540, 140,
       &Sources[3500] ,
       &Weights[3500] ,
      },
    { /* unit 137 (hid127) */
      0.0, 0.033900, 140,
       &Sources[3640] ,
       &Weights[3640] ,
      },
    { /* unit 138 (hid128) */
      0.0, 417.091339, 140,
       &Sources[3780] ,
       &Weights[3780] ,
      },
    { /* unit 139 (hid129) */
      0.0, -0.307190, 140,
       &Sources[3920] ,
       &Weights[3920] ,
      },
    { /* unit 140 (hid130) */
      0.0, -0.714040, 140,
       &Sources[4060] ,
       &Weights[4060] ,
      },
    { /* unit 141 (hid21) */
      0.0, 0.298430, 60,
       &Sources[4200] ,
       &Weights[4200] ,
      },
    { /* unit 142 (hid22) */
      0.0, 0.636160, 60,
       &Sources[4260] ,
       &Weights[4260] ,
      },
    { /* unit 143 (hid23) */
      0.0, 0.051110, 60,
       &Sources[4320] ,
       &Weights[4320] ,
      },
    { /* unit 144 (hid24) */
      0.0, -0.649240, 60,
       &Sources[4380] ,
       &Weights[4380] ,
      },
    { /* unit 145 (hid25) */
      0.0, 0.380370, 60,
       &Sources[4440] ,
       &Weights[4440] ,
      },
    { /* unit 146 (hid26) */
      0.0, 0.174930, 60,
       &Sources[4500] ,
       &Weights[4500] ,
      },
    { /* unit 147 (hid27) */
      0.0, -0.770980, 60,
       &Sources[4560] ,
       &Weights[4560] ,
      },
    { /* unit 148 (hid28) */
      0.0, 0.476100, 60,
       &Sources[4620] ,
       &Weights[4620] ,
      },
    { /* unit 149 (hid29) */
      0.0, 0.607600, 60,
       &Sources[4680] ,
       &Weights[4680] ,
      },
    { /* unit 150 (hid210) */
      0.0, -0.693530, 60,
       &Sources[4740] ,
       &Weights[4740] ,
      },
    { /* unit 151 (hid211) */
      0.0, -0.697890, 60,
       &Sources[4800] ,
       &Weights[4800] ,
      },
    { /* unit 152 (hid212) */
      0.0, 0.235410, 60,
       &Sources[4860] ,
       &Weights[4860] ,
      },
    { /* unit 153 (hid213) */
      0.0, 1.022090, 60,
       &Sources[4920] ,
       &Weights[4920] ,
      },
    { /* unit 154 (hid214) */
      0.0, 0.903280, 60,
       &Sources[4980] ,
       &Weights[4980] ,
      },
    { /* unit 155 (hid215) */
      0.0, -0.058870, 60,
       &Sources[5040] ,
       &Weights[5040] ,
      },
    { /* unit 156 (hid216) */
      0.0, 0.443760, 60,
       &Sources[5100] ,
       &Weights[5100] ,
      },
    { /* unit 157 (hid217) */
      0.0, -0.018820, 60,
       &Sources[5160] ,
       &Weights[5160] ,
      },
    { /* unit 158 (hid218) */
      0.0, 0.975220, 60,
       &Sources[5220] ,
       &Weights[5220] ,
      },
    { /* unit 159 (hid219) */
      0.0, 0.298550, 60,
       &Sources[5280] ,
       &Weights[5280] ,
      },
    { /* unit 160 (hid220) */
      0.0, 0.459540, 60,
       &Sources[5340] ,
       &Weights[5340] ,
      },
    { /* unit 161 (hid221) */
      0.0, 0.534020, 60,
       &Sources[5400] ,
       &Weights[5400] ,
      },
    { /* unit 162 (hid222) */
      0.0, 1.174190, 60,
       &Sources[5460] ,
       &Weights[5460] ,
      },
    { /* unit 163 (hid223) */
      0.0, -0.419510, 60,
       &Sources[5520] ,
       &Weights[5520] ,
      },
    { /* unit 164 (hid224) */
      0.0, 0.449760, 60,
       &Sources[5580] ,
       &Weights[5580] ,
      },
    { /* unit 165 (hid225) */
      0.0, 0.388700, 60,
       &Sources[5640] ,
       &Weights[5640] ,
      },
    { /* unit 166 (hid226) */
      0.0, -0.880810, 60,
       &Sources[5700] ,
       &Weights[5700] ,
      },
    { /* unit 167 (hid227) */
      0.0, -0.094640, 60,
       &Sources[5760] ,
       &Weights[5760] ,
      },
    { /* unit 168 (hid228) */
      0.0, -0.130750, 60,
       &Sources[5820] ,
       &Weights[5820] ,
      },
    { /* unit 169 (hid229) */
      0.0, 0.384940, 60,
       &Sources[5880] ,
       &Weights[5880] ,
      },
    { /* unit 170 (hid230) */
      0.0, 0.606710, 60,
       &Sources[5940] ,
       &Weights[5940] ,
      },
    { /* unit 171 (out1) */
      0.0, -0.084030, 30,
       &Sources[6000] ,
       &Weights[6000] ,
      },
    { /* unit 172 (out2) */
      0.0, 0.017030, 30,
       &Sources[6030] ,
       &Weights[6030] ,
      },
    { /* unit 173 (out3) */
      0.0, 0.963140, 30,
       &Sources[6060] ,
       &Weights[6060] ,
      },
    { /* unit 174 (out4) */
      0.0, 0.203840, 30,
       &Sources[6090] ,
       &Weights[6090] ,
      },
    { /* unit 175 (out5) */
      0.0, -0.548120, 30,
       &Sources[6120] ,
       &Weights[6120] ,
      },
    { /* unit 176 (out6) */
      0.0, -0.453480, 30,
       &Sources[6150] ,
       &Weights[6150] ,
      },
    { /* unit 177 (out7) */
      0.0, 0.869730, 30,
       &Sources[6180] ,
       &Weights[6180] ,
      },
    { /* unit 178 (out8) */
      0.0, -0.847120, 30,
       &Sources[6210] ,
       &Weights[6210] ,
      },
    { /* unit 179 (out9) */
      0.0, 0.086980, 30,
       &Sources[6240] ,
       &Weights[6240] ,
      },
    { /* unit 180 (con11) */
1.41728, 0.500000, 2,
       &Sources[6270] ,
       &Weights[6270] ,
      },
    { /* unit 181 (con12) */
0.00137, 0.500000, 2,
       &Sources[6272] ,
       &Weights[6272] ,
      },
    { /* unit 182 (con13) */
0.39753, 0.500000, 2,
       &Sources[6274] ,
       &Weights[6274] ,
      },
    { /* unit 183 (con14) */
0.86201, 0.500000, 2,
       &Sources[6276] ,
       &Weights[6276] ,
      },
    { /* unit 184 (con15) */
0.02001, 0.500000, 2,
       &Sources[6278] ,
       &Weights[6278] ,
      },
    { /* unit 185 (con16) */
0.02542, 0.500000, 2,
       &Sources[6280] ,
       &Weights[6280] ,
      },
    { /* unit 186 (con17) */
0.88051, 0.500000, 2,
       &Sources[6282] ,
       &Weights[6282] ,
      },
    { /* unit 187 (con18) */
1.29745, 0.500000, 2,
       &Sources[6284] ,
       &Weights[6284] ,
      },
    { /* unit 188 (con19) */
0.00000, 0.500000, 2,
       &Sources[6286] ,
       &Weights[6286] ,
      },
    { /* unit 189 (con110) */
1.26902, 0.500000, 2,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 190 (con111) */
0.00014, 0.500000, 2,
       &Sources[6290] ,
       &Weights[6290] ,
      },
    { /* unit 191 (con112) */
0.00000, 0.500000, 2,
       &Sources[6292] ,
       &Weights[6292] ,
      },
    { /* unit 192 (con113) */
0.17682, 0.500000, 2,
       &Sources[6294] ,
       &Weights[6294] ,
      },
    { /* unit 193 (con114) */
1.42507, 0.500000, 2,
       &Sources[6296] ,
       &Weights[6296] ,
      },
    { /* unit 194 (con115) */
1.42857, 0.500000, 2,
       &Sources[6298] ,
       &Weights[6298] ,
      },
    { /* unit 195 (con116) */
1.42857, 0.500000, 2,
       &Sources[6300] ,
       &Weights[6300] ,
      },
    { /* unit 196 (con117) */
1.29757, 0.500000, 2,
       &Sources[6302] ,
       &Weights[6302] ,
      },
    { /* unit 197 (con118) */
0.10960, 0.500000, 2,
       &Sources[6304] ,
       &Weights[6304] ,
      },
    { /* unit 198 (con119) */
0.03849, 0.500000, 2,
       &Sources[6306] ,
       &Weights[6306] ,
      },
    { /* unit 199 (con120) */
0.42117, 0.500000, 2,
       &Sources[6308] ,
       &Weights[6308] ,
      },
    { /* unit 200 (con121) */
0.07867, 0.500000, 2,
       &Sources[6310] ,
       &Weights[6310] ,
      },
    { /* unit 201 (con122) */
0.46506, 0.500000, 2,
       &Sources[6312] ,
       &Weights[6312] ,
      },
    { /* unit 202 (con123) */
0.07644, 0.500000, 2,
       &Sources[6314] ,
       &Weights[6314] ,
      },
    { /* unit 203 (con124) */
0.12867, 0.500000, 2,
       &Sources[6316] ,
       &Weights[6316] ,
      },
    { /* unit 204 (con125) */
1.02385, 0.500000, 2,
       &Sources[6318] ,
       &Weights[6318] ,
      },
    { /* unit 205 (con126) */
1.36873, 0.500000, 2,
       &Sources[6320] ,
       &Weights[6320] ,
      },
    { /* unit 206 (con127) */
0.09756, 0.500000, 2,
       &Sources[6322] ,
       &Weights[6322] ,
      },
    { /* unit 207 (con128) */
1.42857, 0.500000, 2,
       &Sources[6324] ,
       &Weights[6324] ,
      },
    { /* unit 208 (con129) */
0.00852, 0.500000, 2,
       &Sources[6326] ,
       &Weights[6326] ,
      },
    { /* unit 209 (con130) */
0.25225, 0.500000, 2,
       &Sources[6328] ,
       &Weights[6328] ,
      },
    { /* unit 210 (con21) */
0.81093, 0.500000, 2,
       &Sources[6330] ,
       &Weights[6330] ,
      },
    { /* unit 211 (con22) */
1.38948, 0.500000, 2,
       &Sources[6332] ,
       &Weights[6332] ,
      },
    { /* unit 212 (con23) */
0.15152, 0.500000, 2,
       &Sources[6334] ,
       &Weights[6334] ,
      },
    { /* unit 213 (con24) */
0.12485, 0.500000, 2,
       &Sources[6336] ,
       &Weights[6336] ,
      },
    { /* unit 214 (con25) */
0.00615, 0.500000, 2,
       &Sources[6338] ,
       &Weights[6338] ,
      },
    { /* unit 215 (con26) */
1.42262, 0.500000, 2,
       &Sources[6340] ,
       &Weights[6340] ,
      },
    { /* unit 216 (con27) */
0.00000, 0.500000, 2,
       &Sources[6342] ,
       &Weights[6342] ,
      },
    { /* unit 217 (con28) */
1.36079, 0.500000, 2,
       &Sources[6344] ,
       &Weights[6344] ,
      },
    { /* unit 218 (con29) */
0.03934, 0.500000, 2,
       &Sources[6346] ,
       &Weights[6346] ,
      },
    { /* unit 219 (con210) */
0.08762, 0.500000, 2,
       &Sources[6348] ,
       &Weights[6348] ,
      },
    { /* unit 220 (con211) */
1.42428, 0.500000, 2,
       &Sources[6350] ,
       &Weights[6350] ,
      },
    { /* unit 221 (con212) */
1.42857, 0.500000, 2,
       &Sources[6352] ,
       &Weights[6352] ,
      },
    { /* unit 222 (con213) */
1.29960, 0.500000, 2,
       &Sources[6354] ,
       &Weights[6354] ,
      },
    { /* unit 223 (con214) */
1.36446, 0.500000, 2,
       &Sources[6356] ,
       &Weights[6356] ,
      },
    { /* unit 224 (con215) */
0.11475, 0.500000, 2,
       &Sources[6358] ,
       &Weights[6358] ,
      },
    { /* unit 225 (con216) */
0.01407, 0.500000, 2,
       &Sources[6360] ,
       &Weights[6360] ,
      },
    { /* unit 226 (con217) */
0.00333, 0.500000, 2,
       &Sources[6362] ,
       &Weights[6362] ,
      },
    { /* unit 227 (con218) */
0.09335, 0.500000, 2,
       &Sources[6364] ,
       &Weights[6364] ,
      },
    { /* unit 228 (con219) */
1.02678, 0.500000, 2,
       &Sources[6366] ,
       &Weights[6366] ,
      },
    { /* unit 229 (con220) */
0.00006, 0.500000, 2,
       &Sources[6368] ,
       &Weights[6368] ,
      },
    { /* unit 230 (con221) */
0.20556, 0.500000, 2,
       &Sources[6370] ,
       &Weights[6370] ,
      },
    { /* unit 231 (con222) */
0.98430, 0.500000, 2,
       &Sources[6372] ,
       &Weights[6372] ,
      },
    { /* unit 232 (con223) */
1.29696, 0.500000, 2,
       &Sources[6374] ,
       &Weights[6374] ,
      },
    { /* unit 233 (con224) */
0.03165, 0.500000, 2,
       &Sources[6376] ,
       &Weights[6376] ,
      },
    { /* unit 234 (con225) */
0.11806, 0.500000, 2,
       &Sources[6378] ,
       &Weights[6378] ,
      },
    { /* unit 235 (con226) */
0.05481, 0.500000, 2,
       &Sources[6380] ,
       &Weights[6380] ,
      },
    { /* unit 236 (con227) */
1.39087, 0.500000, 2,
       &Sources[6382] ,
       &Weights[6382] ,
      },
    { /* unit 237 (con228) */
0.04673, 0.500000, 2,
       &Sources[6384] ,
       &Weights[6384] ,
      },
    { /* unit 238 (con229) */
0.17616, 0.500000, 2,
       &Sources[6386] ,
       &Weights[6386] ,
      },
    { /* unit 239 (con230) */
0.36503, 0.500000, 2,
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
