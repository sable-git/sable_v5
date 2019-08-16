/*********************************************************
  TMPENTROP6+weight_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:20:30 2004
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
  static UnitType Units[169];
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
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 139,
Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149,
Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159,
Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168,
Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109,
Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119,
Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129,

Units + 100, Units + 139,
Units + 101, Units + 140,
Units + 102, Units + 141,
Units + 103, Units + 142,
Units + 104, Units + 143,
Units + 105, Units + 144,
Units + 106, Units + 145,
Units + 107, Units + 146,
Units + 108, Units + 147,
Units + 109, Units + 148,
Units + 110, Units + 149,
Units + 111, Units + 150,
Units + 112, Units + 151,
Units + 113, Units + 152,
Units + 114, Units + 153,
Units + 115, Units + 154,
Units + 116, Units + 155,
Units + 117, Units + 156,
Units + 118, Units + 157,
Units + 119, Units + 158,
Units + 120, Units + 159,
Units + 121, Units + 160,
Units + 122, Units + 161,
Units + 123, Units + 162,
Units + 124, Units + 163,
Units + 125, Units + 164,
Units + 126, Units + 165,
Units + 127, Units + 166,
Units + 128, Units + 167,
Units + 129, Units + 168,

  };

  /* Weigths definition section */
  static float Weights[] =  {
0.283150, -0.408300, 0.683350, -0.229490, -0.581660, 0.367680, -0.988030, 0.630920, 0.659790, 0.414460,
-0.285980, 0.075550, 0.579370, 0.090210, -0.557520, -0.652900, -0.049170, 0.497850, -0.399360, 0.213710,
0.973050, -0.649830, 0.844500, -0.738810, 0.238190, -0.978730, -0.219630, -0.016930, -0.444940, 0.531580,
-0.593020, -0.181990, -0.243090, 0.087340, -0.574240, 1.315000, -0.615370, -0.736570, -0.010450, -0.805460,
-0.841440, 0.746820, 1.313650, -0.546930, -1.347570, -3.086260, 0.501190, 2.034170, -0.400520, -0.009970,
-1.627850, 1.887750, -1.360770, -0.528520, -0.301620, 0.675960, 0.209800, 0.029320, 0.477950, 0.410380,
-0.530410, -2.563730, -0.601660, 0.379100, -0.017190, 0.770580, -0.590280, 0.354670, 0.580510, -0.055110,
0.269070, 0.862330, -0.686100, 0.065030, 0.127100, -0.254710, -0.234310, -0.333250, -0.618850, -0.563800,
-0.387320, -0.926090, 0.383350, -0.008190, -1.034310, -0.203670, -0.907460, -0.124150, -0.765550, -0.982790,
0.372150, 0.249700, 0.996140, -0.723650, 0.935660, 0.074730, 0.699620, 0.355800, 0.367730, -0.776830,
-0.282540, 0.626720, 0.095930, 0.269010, 0.916260, 0.748760, 0.432260, -0.544620, 0.232050, -0.392510,
0.971220, 0.647850, 0.711640, -1.381650, 0.455330, -0.048150, -0.079300, 0.498530, 0.247610, 0.070100,
2.191900, -1.087480, 0.791630, 0.571400, -0.046600, 0.322000, -0.771560, 0.358970, 0.021850,
0.004280, 0.361370, 0.651700, -1.061540, -0.453450, 0.291950, -0.829530, -1.199030, -0.532750, 0.236800,
0.226790, -0.267880, -0.374820, 0.611970, 0.099940, 0.337000, 0.313060, 0.931010, -0.298540, 0.621820,
0.611040, 0.749930, 0.143800, -0.794370, -1.786060, -0.429120, -0.585350, 0.118200, 0.816790, -0.355480,
-0.647250, -0.285080, 0.720340, -0.980320, 0.247880, 1.138940, -0.003320, 0.469630, 0.242320, -3.385700,
-0.055580, -0.439200, 3.083600, -0.455340, -0.062440, -5.809690, 0.626050, -0.510770, 2.702260, 0.307040,
-0.644730, -0.289550, -0.395850, 1.003800, 0.983930, -0.401240, -0.633230, -1.629850, -0.479840, -0.709720,
1.944680, 0.296070, 0.992000, -1.516590, -0.746380, 2.058170, 0.328680, -0.803090, 0.385790, -0.169020,
1.046190, -0.156350, 0.865140, -0.089780, 0.252280, -0.161820, -0.058250, -0.622010, -0.579770, -0.269290,
0.808550, -0.756390, -0.354070, -0.774790, 0.728880, 0.132020, 0.586670, 0.212610, 0.039280, 0.956120,
-0.516830, 1.032410, 0.239560, 0.155450, 0.696420, 0.784470, -0.024540, -0.338450, -0.802890, 0.017640,
-0.335450, -0.653300, -0.436420, -0.334300, 0.242750, -0.038350, -1.016230, 0.051160, -0.808810, -1.056540,
0.622680, 0.510480, 0.062020, -1.722080, 0.186840, 1.097480, 0.189240, 0.486210, 1.053500, 0.782760,
0.347310, 0.663930, 0.059450, 0.373340, 0.134220, 0.398510, 0.525450, -0.781450, -0.539360,
-0.327610, 0.281520, 0.217880, 1.009990, 0.013460, 0.012850, -0.582660, -0.179090, 0.635030, -0.816120,
0.645400, -0.235680, -0.212320, 0.189870, 0.425810, 0.885110, -0.130010, -0.819960, -0.371670, -0.212930,
-1.045260, 0.128720, -0.420540, -0.922370, 0.511630, -0.027150, -0.902500, 0.145570, -0.653150, -0.609990,
-0.147470, -1.789630, 0.502400, -3.206780, 0.878490, -0.935110, -0.979390, -0.738480, -0.347490, 2.244600,
-0.713470, -0.979450, -1.232770, 0.029080, -0.086060, 8.587730, -0.020370, -0.479620, -0.365380, -0.229590,
-0.741060, -0.487880, 2.285940, 4.265710, -0.131990, 0.275300, -3.716450, 0.592630, -0.649260, 0.187660,
0.876750, 0.270270, -1.200700, -0.644720, 0.686730, 4.772070, 0.532470, -0.561820, 1.021470, 0.149060,
0.422860, 0.939180, 0.036380, -0.844940, -1.330320, -0.687390, 0.350180, 1.191400, -0.330010, 0.544550,
1.256980, 0.409420, -0.259370, 4.124030, 0.033530, -0.426560, 1.635840, 0.047350, -0.785100, -3.091050,
-0.922450, 0.655540, 1.583380, 0.739000, 1.086030, 1.480880, -0.173700, 1.444210, 3.187090, 0.741300,
-0.088980, 0.024960, 0.565920, -0.323760, -0.089280, -0.056690, 0.578520, -0.066960, 0.224320, -0.435920,
-1.001240, 0.145650, 0.330180, -0.079120, 3.270270, 0.448470, 0.795120, 0.577810, 0.728610, -0.144680,
0.490680, -0.388270, 0.903010, -0.374080, -1.435140, -0.915210, 0.402820, -0.034510, -0.086910,
0.751730, -0.798410, -0.900000, -0.210980, 0.896190, 1.046310, -0.264130, 0.239020, -0.351540, 0.494410,
-0.048350, -0.082940, -0.339800, -0.222570, -0.571690, -0.617040, 0.406670, -0.528820, 0.206250, 1.052820,
-0.878670, -0.374980, -0.281100, 0.353610, 0.972100, 0.590340, -0.837020, 0.281840, -0.595100, 0.866920,
-0.104760, 1.165760, 0.536850, 0.395620, -1.506660, 0.999790, 0.237120, -1.060500, 0.333210, -0.506570,
0.177140, -0.289980, -0.463570, 0.316270, 0.126560, 1.315200, -3.285730, 0.492630, -0.549570, -0.471840,
-0.282020, 0.084220, 2.230820, 0.021650, -0.169120, -0.470160, -0.215470, -0.642460, 0.587730, -0.744930,
0.320960, 0.240940, 0.332740, 0.938850, -0.990060, 0.133190, 1.008550, 0.583180, -0.391620, -2.090990,
0.608800, -0.372730, 0.034310, -0.801610, -0.682700, -0.379410, 0.062250, 0.206370, -0.191350, 0.527570,
-0.028800, 0.896800, -0.482840, 0.131020, -0.904380, -0.567240, -0.538180, -0.768440, -0.908120, -0.294070,
0.658160, 0.581340, 0.214350, 0.679620, -0.416990, -0.528380, 0.720600, -0.340130, -0.827540, 0.774400,
0.698900, -0.673040, 0.004990, 0.579110, -0.182450, -0.826960, 0.291890, -1.418150, 0.710730, 0.884790,
0.514390, 1.158660, -0.097150, 6.128690, -0.660510, -1.034840, -0.045630, -1.109270, -0.027320, -0.077820,
-0.873950, 1.376080, -0.794280, -0.045290, 0.005240, -0.988740, 0.409450, -0.150180, -0.313210,
0.399510, -0.320000, 0.488460, -0.028470, -0.561440, 0.385120, -0.133230, 2.077040, 0.797430, -0.118940,
0.432700, 0.982800, 0.216550, 0.262190, -0.340590, -0.491320, -0.181420, -0.837910, 0.145840, 0.080140,
0.550250, -0.913360, -1.058020, -0.135440, 0.664910, 0.548730, 0.033000, -0.534550, -0.634000, -0.479270,
-0.269800, 0.795750, -1.002550, 0.526860, -0.719510, -0.515050, -0.073550, -0.750420, 0.204420, -0.484220,
-0.626900, 0.512750, 1.514070, 0.331320, 0.221920, -0.136640, 1.311390, -1.236470, -0.174450, -0.143540,
1.023630, 0.552740, 0.201840, -0.065230, 0.354720, 0.176790, -1.014830, 0.605970, -0.735100, -0.167310,
-1.891080, -0.541510, 0.024180, 0.479760, -1.166300, -0.077720, -0.328320, -0.709060, 0.166750, -1.600570,
0.814170, 0.395110, -0.747500, -0.459360, 0.706740, 0.271920, -0.961420, 0.452110, -0.568020, 0.506130,
0.752160, -0.470710, -0.880730, 0.482040, 0.554590, 0.713050, -0.331470, -0.273140, 0.391880, 0.157540,
1.116690, 0.432130, 0.672640, 0.335920, -1.152280, -0.023230, 2.741050, 0.113180, -0.199760, -0.567080,
0.974200, 0.241780, 1.826800, -0.490100, 0.760940, 0.821280, 0.905910, -0.293720, 0.050890, -0.483650,
1.037690, 0.271130, -0.446830, 3.511490, -0.332650, -0.805090, -1.502540, -0.182330, 0.817840, -0.231640,
-0.625150, 0.349430, 0.748950, 0.262670, 0.744180, -0.175460, -2.235300, -0.622110, 0.015220,
-0.293770, 0.521710, 0.386510, 0.032210, -0.057060, 0.330310, -0.234130, -0.342280, -0.188340, -0.018270,
0.540500, 0.696880, -0.384730, -0.670410, -0.273840, 0.462700, -0.553170, -0.844450, -0.650870, -0.655870,
-0.638420, -0.241680, 0.020840, -0.413490, -0.957160, -0.647910, 0.407730, 0.601490, 0.889420, 0.865810,
-1.566960, 0.241670, -0.489330, 0.334600, -0.142400, 0.887870, 0.718720, -0.812810, -0.486300, 0.965150,
0.135640, 0.004150, -2.030170, 0.377320, 2.258110, 0.263480, 0.895700, -0.836200, 0.699450, -0.295970,
0.130950, 0.013870, -0.335760, 0.246150, -0.037380, -0.420690, 2.049430, 0.076940, -0.682950, 0.796240,
-0.034640, 0.418530, 0.110180, 0.028470, 0.641170, 0.861380, -0.907600, -0.277930, 0.493280, 0.033990,
0.016020, 0.141970, 0.402750, 0.078130, -0.110400, -0.518390, -0.223250, -0.388930, -0.476130, 0.954180,
0.580080, -0.013180, 0.232760, -0.685300, -0.593860, -0.817180, -0.846680, 0.096000, 0.306120, -0.322720,
0.396720, -1.052410, -0.579010, -0.499010, -0.412790, 0.510260, 1.022540, 0.189290, 0.230770, 0.262750,
0.458610, -0.501420, -0.046400, 0.230580, -0.580330, -0.180870, 0.773440, -0.383350, -0.163410, -0.609380,
-0.170040, 1.039170, 0.863810, 0.891720, -0.469200, 1.686220, -0.057370, -0.000660, -0.420970, -0.847070,
0.037470, 0.650950, 0.157960, -0.858080, -0.574940, -0.410460, -0.451860, 0.911850, 0.284420,
0.112090, 0.462500, -0.221790, 0.618220, 0.355810, -0.036020, -0.986610, 0.497360, 0.035420, 0.093970,
0.159790, -0.263290, 0.908800, 0.664560, -0.753110, -0.209130, 0.417110, 0.298620, -0.540560, -0.808890,
-0.591410, 0.545920, 0.237790, 0.429130, 1.139250, 0.927270, -0.551400, -0.139850, -0.264250, 0.427210,
0.005650, -0.425630, 0.311720, 0.451120, -0.660410, -0.103410, -0.349600, -0.546350, -0.505490, -0.454380,
-0.231190, 0.387660, -0.225080, 0.370190, -2.199380, 0.669640, 0.881310, 0.524280, -0.533250, 0.137530,
1.105630, 0.402790, 1.916900, -2.680100, 1.248690, 0.607000, -1.929170, 0.632600, 1.969910, -1.998680,
-0.126580, 0.485500, -0.670310, 0.773770, 1.019480, -5.085740, -0.119690, 0.844880, -2.289700, 0.720270,
1.636040, -0.640940, 0.028710, -0.281120, -6.310040, 0.561210, -0.854120, 0.136120, 0.282710, 0.326710,
-0.116050, 0.976420, 0.467610, -2.390380, -0.273600, 0.146070, 0.504540, 1.068430, 0.043800, 0.725050,
0.347560, -0.118200, 0.917890, 0.693280, -0.206150, 0.624020, 0.653620, -0.171000, -0.222030, 0.338430,
-0.543360, -0.640590, -0.974170, 0.798340, 0.184400, -0.767940, -0.723160, -0.051090, -0.826680, 0.105880,
-0.874030, -0.196790, -0.341390, -0.320760, -1.012930, -0.349120, -0.673980, -0.053540, -0.896260, 0.554490,
-1.712690, -0.139900, -0.618080, -0.332950, 0.474080, 0.632200, -1.011330, 0.440800, -0.227640,
-0.530140, 0.556320, 0.581690, 0.058380, 0.215430, 0.552590, -0.551130, -0.649380, -0.342560, -0.476920,
0.315490, 0.328070, 0.213470, -0.698700, -0.669740, -0.317850, 0.482920, -0.127010, 0.178750, -0.383240,
-0.811010, -0.947380, 0.738170, 0.652170, 0.028860, -0.389830, -0.680700, 0.108670, -0.802100, -0.098630,
-0.443520, -0.574320, 0.745300, 0.184950, -0.412460, -1.073390, -0.120480, 0.560880, 0.794790, -0.137830,
0.348130, -0.425070, 0.781790, -0.670970, 0.457680, -0.815320, -0.712740, -0.701990, -0.216090, 0.303870,
-0.000170, -0.094240, -0.022000, -0.838370, -1.147240, 0.645130, 0.568420, -0.028430, 0.412490, -0.685730,
0.687920, 0.241880, 0.928920, -0.948850, 1.862390, 0.059470, -0.911270, 0.155300, 0.610700, 0.621130,
-0.263200, -0.743060, -1.173130, 1.085810, -0.218240, -0.466010, 0.041960, 0.616220, 1.596810, 0.245860,
0.918610, 0.901370, -0.285430, 0.672760, 0.809110, 0.687140, 0.209550, -0.429040, -0.895730, 0.186870,
1.012730, 1.039750, 0.360540, -0.492600, 0.489280, 0.758250, -1.087720, -0.506470, -0.486650, -0.322160,
-0.532370, 0.282900, 0.565680, -0.786540, -0.656860, 1.080860, -0.861630, -0.024610, 0.362670, -0.228660,
0.739960, -0.892650, -0.710340, -1.739050, 0.500760, 0.330170, -0.789590, 0.994570, -0.632470, 0.492530,
-0.020500, 0.402250, 0.606170, 0.173310, 0.129290, -0.284810, 0.125930, 0.844720, 0.027360,
-1.145910, -0.477050, -0.756680, 0.172500, 0.458710, -0.937080, -0.291010, -0.694990, 0.169140, 0.802850,
0.527870, -0.146330, -0.188310, -0.212180, -0.834260, -0.016810, -0.170700, 0.202360, 1.049980, 0.525780,
-0.741060, -0.076070, -0.509600, 0.614260, -0.505370, 0.315180, 0.384680, 2.273250, 0.466730, -0.419550,
-0.041970, 0.856810, 0.240280, 0.878910, 0.506450, -0.745970, -0.383990, 0.244740, 0.650020, 0.490130,
-1.037290, 0.259770, -0.409100, 0.834090, -0.667110, -1.561370, -0.504240, -0.858110, 0.724160, -0.525780,
2.131910, 1.896140, 0.943550, -0.245830, -3.180340, -0.252240, 2.151570, 1.686120, 0.792270, -1.439480,
2.593940, 0.143010, -0.764360, -0.665320, 0.367110, -6.134510, -1.685790, -0.220670, -3.885270, 2.746250,
-0.722610, -0.540910, -19.431770, 0.419720, -0.970730, -0.801440, 0.214390, -0.554270, -5.250960, -0.834230,
0.199270, -30.021070, -0.591780, -0.533220, -1.069270, -0.317750, -0.012770, 0.443710, -0.035180, -0.002070,
-1.239640, 0.276120, -0.702240, 0.584380, 0.758130, 0.546840, 1.374930, -0.748610, 0.820010, -0.030350,
0.105880, -0.441500, 0.326710, -0.727650, 0.719770, -0.285810, 0.659500, -0.770700, 0.726430, -0.055010,
0.600630, 0.253290, -0.675540, 7.502300, 0.965570, -0.331750, -0.062470, 0.560670, -0.918190, -0.523110,
-1.121090, -3.340560, -0.883710, 0.431720, 0.455530, -0.477130, -1.016130, 0.283580, 0.760250,
0.655270, 0.109340, 0.403910, 0.210860, 1.057240, 0.449500, -0.654320, -0.279340, -0.291780, -0.508480,
0.699090, -0.685510, 0.543560, 0.881340, 0.366600, 0.467390, -0.668580, -1.148260, 0.058190, 0.321970,
0.303880, 0.220380, -1.009550, 0.327750, 0.200470, 0.583180, 0.659050, 0.571100, -0.467130, -0.877830,
-0.257500, -1.233630, -0.016790, -0.679680, -1.174550, 0.282320, -0.004580, 0.141880, -0.186720, 0.207520,
-0.930930, -0.645490, -0.834740, 0.734650, -0.985780, -0.173640, -1.222420, -0.701680, 0.400920, -0.150940,
0.305700, -1.290660, 2.280500, -0.375390, 0.869750, 0.225560, -1.204340, -0.256890, 0.703960, 0.605380,
0.072230, -1.818650, -0.608630, 0.094660, 0.154840, 1.030220, -0.344630, -0.022170, 0.765720, -0.144000,
-1.240890, -0.107780, -0.291410, 0.304510, -0.460890, -0.486920, -0.517380, -0.399060, -0.014760, -0.234770,
0.588410, 0.038400, 0.277610, 0.505880, -1.001350, 0.055000, -0.156370, 0.081200, -1.132450, -0.025550,
-0.375710, 0.630590, -0.676510, 0.876800, 0.605020, 0.364820, 0.309210, -0.897080, -0.338640, 0.494970,
-0.618370, -0.369700, 0.646680, -0.971320, -0.750390, 1.434790, 0.397390, -0.399960, 0.754980, 0.563650,
0.862030, -0.109350, 0.295610, 1.166770, -0.844760, 0.809610, 0.078050, 0.083250, 0.187200, 0.811480,
0.217540, -0.389730, 0.640670, 0.623950, -0.570410, -0.048030, -0.798930, -0.057620, -0.021500,
-0.002670, -0.242850, 0.295900, 0.280420, 0.111950, -0.704560, 0.214230, -0.672900, 1.170760, -0.365610,
0.076470, -0.627650, 0.203550, -0.071890, 0.715610, 0.265600, 0.441520, -0.034970, -0.727950, 0.716020,
0.028270, 0.152840, 0.067600, 1.093360, 0.899230, -0.035450, 0.287730, 0.835860, -0.482150, 0.167770,
0.674450, 0.051300, -0.316550, -0.032460, 0.859110, 0.927300, -0.501710, 0.164470, -0.809300, 0.763420,
0.201290, 0.656520, -0.804670, -0.470930, -0.493020, -0.141840, 1.311110, 0.454380, -1.109550, 0.475760,
0.576860, 1.786870, -0.364770, -1.153970, -0.335040, 1.256820, 0.555300, 0.447850, -1.664900, -1.838020,
-0.612870, -2.356190, -0.215190, 2.853610, 1.629870, -2.611650, 0.487620, 0.521650, -1.017010, -0.006230,
-0.572100, 0.527410, -0.798280, 0.106900, -0.740950, -0.420080, -0.892220, -0.478140, -0.482880, -1.064840,
-0.235500, -0.760010, -0.510280, 0.434080, 0.791950, 0.151680, -0.530670, -0.855670, -0.313920, 0.430930,
-0.540490, 0.357770, -0.241850, 0.460910, -0.651390, 0.006720, -0.693620, 0.674220, 0.510720, 0.198600,
0.388080, -0.034290, -0.174500, -0.223690, 0.184210, -0.640650, -0.617440, -0.667230, -0.603120, 0.582880,
0.569610, -0.220310, -0.528800, -0.638780, -0.950950, -0.564850, -0.697390, -0.043220, 0.804790, -1.324990,
-0.478260, 0.742600, 0.603810, 1.050000, 0.368760, -0.558990, -0.684950, 0.701550, 0.325890,
-0.163370, 0.558000, 1.340250, 0.268770, 0.050620, -0.554740, -0.931110, -0.523650, 0.469150, -0.493360,
0.504260, -0.236180, 0.675030, -0.540050, 0.353220, -0.132220, 0.372170, 1.561060, -0.887140, -0.012470,
-1.111300, 1.041860, -0.607910, -0.790600, -0.892110, -0.894880, -0.060450, 0.378250, -0.576810, 2.866190,
0.188720, -0.692640, -0.604690, 1.058880, 0.343160, -0.038960, 0.212630, 0.310980, -3.097760, -0.489440,
0.842930, 0.176650, 0.614110, -0.008890, 4.912740, -0.665110, -0.746790, -0.774420, -0.417260, -0.082240,
0.504730, 1.873920, 0.518730, -1.288240, -0.416470, 0.087770, 0.577680, 0.157820, 0.778210, 0.155670,
-0.122360, 1.748510, -0.521070, -0.382440, 0.705280, -3.080810, -0.035250, 0.393160, 0.537820, -0.212680,
-1.765150, 0.018710, 0.377780, 0.418370, -0.605620, 0.332980, -0.161280, -0.666190, -0.312100, -0.255540,
0.743450, 0.828230, 0.403040, 0.759960, -0.227740, -0.109190, 1.249840, 1.608070, 0.885640, 0.280950,
0.474050, 0.072670, 0.379990, 0.494510, 0.525070, -0.625020, -0.782790, 0.502480, 0.603950, 0.342030,
1.376510, 0.783230, 0.212840, -0.368730, 0.858220, -0.405750, -0.827630, -1.046880, 0.203150, -0.018480,
0.923850, 1.024370, 0.490120, -0.474350, -0.718270, -1.059240, -0.668170, 0.640760, -0.948320, -0.047450,
0.097010, -0.738710, 0.916410, -0.735900, 0.558380, -0.388360, 0.350870, -0.664720, -0.624050,
0.515760, 0.343060, -0.167620, 1.343900, 0.751770, -0.811170, 1.605370, 0.310380, 0.461570, 1.048250,
0.083290, -0.263520, -0.233170, 0.782700, 0.666970, -0.042380, 0.423460, -0.227630, 0.197840, -0.597160,
0.827230, -0.198450, 0.797650, 0.217040, 0.874550, -0.327040, 0.276310, 0.007470, -0.672570, 0.075650,
-0.643960, -0.161240, -0.547860, 0.888880, -0.110940, -0.356820, -1.522840, 0.006480, -0.407230, -0.893000,
0.611130, -0.165040, 0.713720, -0.979530, -0.551560, -0.135370, -0.411950, -0.793260, -1.499520, -0.734330,
0.415180, 0.250000, -0.583670, -0.692270, -0.484490, 0.603260, 0.061200, -0.213430, -0.432850, -0.410460,
-0.523110, -0.349270, 0.587990, 1.398550, 0.310050, 0.523640, 0.955730, -1.164510, 0.592940, -2.194480,
0.403280, 0.150610, 0.569000, -0.566340, -0.692180, -0.925720, 0.363840, -0.906830, -0.886720, 1.008430,
-0.206360, 1.042400, -0.563770, -0.140660, -0.052220, -0.573300, 0.899970, -1.971270, -0.016220, 0.290140,
3.785340, -0.531980, -0.669890, 0.873010, 0.894900, 0.485690, 1.095670, -0.228810, 0.506970, -0.764150,
-0.050540, -0.066460, 0.864670, 0.050650, -0.873920, 0.241670, 0.973210, -1.222580, 0.778410, 0.841220,
0.502340, -0.101290, -0.392870, 0.468760, 1.811370, 0.730390, -0.640340, -0.077560, 0.308380, 0.482100,
0.396470, 0.377510, 0.361420, 0.558430, -0.215660, 0.040090, 0.652460, 0.537320, -0.316310,
0.356800, 0.081810, 0.290990, -0.180460, -0.094500, -0.699720, -0.301450, 0.950300, 0.893080, 0.837630,
0.802930, 0.861220, -0.689810, -0.091600, 0.364600, 0.928290, -0.964160, -0.464770, 0.917350, -0.108990,
-0.906370, -1.135850, 0.135120, 0.205810, 0.171290, 0.282040, 0.087680, -0.910730, 0.035900, 0.983410,
0.912340, 0.506780, -0.133180, 0.755170, 0.340630, -0.611430, 0.584020, -0.302150, -0.881760, 0.924210,
0.051340, -0.799050, -0.405260, 0.833770, -1.172210, 1.398140, 0.515480, 0.138870, -1.909010, -0.022570,
-0.779720, -0.291770, -1.173610, -0.507720, -0.257920, 0.405520, -1.268790, 1.025970, -0.185590, 0.472790,
-0.180900, -0.733900, 0.971240, 1.433830, -0.754630, 0.711750, -0.658990, 0.498760, 0.121180, -0.056100,
0.228280, -0.046840, 1.067500, -0.560640, -0.662080, 0.106140, -0.409380, -0.603940, 0.277300, 1.054390,
0.189760, 0.933500, -0.488730, 0.019460, -0.967060, -0.146620, 0.244660, 0.157010, -0.521180, 0.110930,
0.776340, 0.769750, 0.279230, -0.368120, 0.599940, 0.779340, 1.424980, 0.327040, 0.471350, -0.079450,
0.212570, 0.291970, 0.461630, -0.841830, 0.578650, -0.087920, -0.427580, -3.337800, 0.070820, -0.465470,
-0.667810, 0.665440, 0.799420, -1.774390, -0.622660, -0.859970, 0.900260, 0.490400, 0.279840, -0.632220,
-0.876690, 0.708340, -0.870850, 0.590000, 0.227170, 0.469780, -2.673770, 0.016010, 0.321960,
-0.159580, 0.174200, 0.496040, -0.578640, 0.117390, 0.388500, -0.015010, -0.892490, 0.695320, -0.101260,
-0.782820, 0.207050, -0.602420, 0.456770, 0.688590, -0.506350, -0.847050, 0.563970, -0.386620, 0.954710,
-1.070840, 1.030070, 0.543400, -0.476020, -0.633210, -2.126940, 0.059950, 0.786440, 0.741190, 0.387700,
0.643310, -0.129490, -0.981280, 0.321790, -0.386820, 0.758740, -0.823420, 0.509090, -0.140890, -0.973460,
2.128020, 0.776630, 0.886690, -3.354200, -0.046580, -0.141030, -1.499750, 0.092940, 1.068940, 2.220590,
-0.634260, 0.104390, -2.969310, -0.436310, -0.459800, -3.775910, 0.700950, 0.282950, -1.157410, -0.277490,
-0.636420, 0.124950, 0.655980, 0.765200, -2.223570, 0.746060, 0.431030, -0.349810, -0.588420, -0.732620,
0.308460, -0.566040, -0.390300, -3.149590, -0.040110, 0.223250, 0.082840, 0.116600, 0.694890, 0.724150,
-0.060000, 0.679710, -0.699300, 0.606570, 0.117570, 0.694360, -0.253940, -0.465890, -0.306640, 0.488340,
-0.962730, -2.030390, 0.030320, 0.606160, 0.851510, -0.947430, 0.181520, -0.441830, 0.056790, -0.989720,
1.198980, -0.449170, 0.494490, 0.058540, -0.174650, 1.274430, -1.087000, 3.264700, -0.479340, -0.692820,
0.486130, -0.559160, -0.282260, -0.645200, 4.571370, -0.722170, 0.301180, 0.940230, 0.227040, -0.907300,
0.544730, 0.689320, 0.018700, 0.239480, 0.468570, -0.012510, 0.415560, -0.258670, 0.679750,
-0.424010, 0.061080, -0.162150, 1.231440, 0.172190, -0.831520, 0.196140, -0.586350, 0.440950, -0.565580,
0.691750, -0.914650, -0.656280, 0.171970, 0.616130, -0.315510, 0.081000, -0.575930, -0.010210, 0.706330,
0.546850, -1.094800, -0.582010, -1.006070, -1.199970, 0.104450, 0.394700, 0.932940, 0.219010, -0.234380,
-0.397900, -0.836900, 0.607500, -3.910840, 0.687940, -0.368780, -1.271330, -0.628120, 0.312630, 1.066890,
0.337680, 0.023960, 1.386790, -0.319540, 0.243590, -2.354050, -0.202930, -4.313670, -1.041620, -0.127740,
-0.513720, 4.621460, 0.326680, -1.899930, -0.567330, 0.366220, -4.967630, -2.344520, 0.281540, -1.050430,
-0.635080, 0.607870, 0.579610, -5.628530, 0.482990, -2.083250, -1.681020, 0.790290, -0.803490, 1.215360,
-0.756840, -0.089980, -8.130890, 0.834400, -0.573130, -1.866110, -0.548100, -0.296450, 0.996070, -0.984220,
-0.414920, -3.496300, -0.773040, 1.095950, -0.151380, 0.103310, -0.801710, 1.399120, -0.289930, 0.680870,
-1.014910, 0.861520, -0.234090, 0.315100, -0.619570, 0.775400, -0.075550, -0.245980, -0.531310, -0.432270,
0.537620, -0.161950, 0.687890, 0.093470, 0.066270, 0.717160, 0.222070, -0.454360, 0.649150, -1.095790,
-0.524580, 0.911120, 0.155300, 2.669470, -0.781830, 1.904650, 1.688500, -0.061870, 0.377850, 0.479300,
0.301620, -1.869320, -0.396760, -0.652980, 0.341150, 0.849670, 0.284460, 0.352100, 0.335640,
0.243260, -0.765570, -0.780430, -0.303970, -0.408330, -0.656880, 0.698370, 0.262580, 0.911330, 0.502880,
-0.338080, -0.142140, -0.811710, 0.934010, 0.920540, -0.080560, 0.693150, -1.098380, -0.699330, 1.012310,
-0.693240, -0.406720, -0.153650, -0.489640, 0.653580, 0.570960, 0.331570, -0.263210, 0.762620, 0.605820,
-0.113460, -0.938960, 0.522820, -0.400990, -0.246230, 0.424110, -0.732010, -0.019660, 0.992620, 0.867210,
-0.614550, -0.302820, 0.257720, -0.775340, -0.847060, 0.323850, -1.268180, 0.181890, -0.278010, -1.367060,
-0.338190, -0.692980, 1.603820, -0.293780, 1.368040, -1.695980, -0.181890, -0.341600, 0.056220, -0.291650,
-0.069150, 0.663380, 0.892510, 0.787630, 0.033150, -1.043630, 0.354620, 0.339360, -0.871250, 0.329830,
3.126780, 0.625260, 0.272840, -0.111530, -0.782910, 0.412450, -0.508780, 0.920100, -0.153240, 1.862560,
-0.509500, -0.004320, -1.101630, 0.661100, 0.910870, -0.254880, -0.338120, -0.141190, 0.946900, -0.407710,
-0.090530, -0.810160, 0.797300, 0.710400, -0.284510, 0.651760, 0.968390, -0.890430, -0.842120, 0.611930,
0.931860, -0.881370, -0.580910, -0.429280, -0.611840, 0.357550, -0.497310, -2.024120, 0.654160, 0.337130,
-0.002060, 0.481200, 0.127800, 2.465900, 0.583900, 0.064110, -0.425470, -1.421720, -0.391240, -1.102490,
-0.240050, -0.539680, -0.922950, -0.473070, 0.367020, 0.684350, 0.506260, -0.416420, 0.571390,
0.178530, -0.516270, -1.521590, -0.664240, 0.591950, 0.344560, -0.249180, -0.593990, -0.553380, 0.871360,
0.071200, -0.281980, 0.604220, -0.733460, 0.295220, 0.897550, 0.592380, -0.981450, -0.534980, -0.314290,
-0.085090, 0.673840, -0.806020, -0.458780, -0.690010, -1.622890, 0.092190, -0.248620, -0.862470, -1.324730,
0.441490, -0.991860, -0.656580, -0.226680, -1.275290, 0.149210, -0.053150, -0.320670, -0.576850, 0.829700,
-0.970870, 0.191390, 0.879380, -1.803250, 0.468400, 0.167630, -1.899540, 1.506370, -0.134400, -0.084080,
0.472580, 0.794160, 1.289660, 0.500410, 1.063200, 0.543720, 1.005080, -0.664340, -0.703640, -0.354220,
0.117760, 1.412510, -0.623650, 0.006470, -0.027250, -0.759350, 0.843510, -0.918220, -0.593790, -0.278790,
0.217990, 0.511210, 0.800180, -0.775760, 0.307240, -0.382750, 0.583480, -0.308440, -1.347120, -1.163620,
-0.192340, -0.073160, -0.184050, -0.580750, -0.795670, 0.370450, -0.184730, 0.474870, -0.045590, -0.018900,
-0.446020, -0.468170, -0.994140, 0.113150, -0.080630, 0.853810, -0.624850, -0.414100, -0.559820, 0.493990,
0.868980, 0.599850, 1.004920, -0.373870, 0.434360, 0.372320, -0.533150, 1.782850, -0.961020, -0.236880,
0.744400, -0.854950, -0.567200, 0.378940, 2.637470, -0.273730, 0.195850, -0.833250, 0.146370, 0.532260,
0.929930, -0.387820, 0.653670, 0.157310, -0.232660, -1.239780, -0.057930, -0.390400, 1.243100,
0.098470, -0.637610, 0.182710, -0.501670, 0.507180, 0.965230, 0.347230, 0.619990, -0.280860, -0.425430,
-0.279200, 0.490210, 1.041000, 0.778680, -0.462110, -0.582940, 0.286640, -0.689300, 0.531520, 0.791260,
0.162260, 0.512860, -0.727640, -0.930970, -0.476770, 0.864850, -0.677730, -0.627770, -0.829270, -0.201120,
0.765550, -0.627430, 0.027700, 0.849480, 0.500890, 0.507750, -0.015490, -0.172140, 0.618470, -0.309180,
0.769500, -0.452720, -0.127770, -1.338210, 0.833690, -0.022100, 0.159430, -0.988200, -0.592780, -1.279510,
0.361060, 0.423080, -1.137600, 0.059160, 0.224630, 0.430520, 0.045930, 0.031830, 0.819250, -0.448390,
0.786210, -1.822320, -0.480030, -0.810780, 0.881880, -0.701410, -1.098540, -0.458320, -0.674410, 1.553950,
0.678510, 0.414360, 0.142380, -0.816800, -0.208910, 0.097220, 0.695030, -0.292190, -0.135970, 0.200100,
0.635550, -0.981970, 0.493330, -0.077290, -0.401850, 0.875450, 0.379860, 1.344560, 0.430170, 0.032300,
-0.408920, -0.773630, -0.114040, -0.137040, 0.196160, 0.381140, -1.165310, 1.005790, 0.177590, 0.484560,
-1.284440, 0.482180, -0.882540, -0.837280, 0.076190, 0.411110, 0.799140, 0.646680, 0.111070, -1.207800,
-0.553150, 0.311270, 0.811680, -10.139130, 2.359490, -0.202470, 0.829930, -0.814900, -0.123320, -1.068740,
-0.178610, -1.372160, -0.113580, 0.715050, 0.170430, 2.142250, -4.311850, 0.263810, -0.081850,
-0.772850, 0.009570, -0.164020, -0.893990, -0.828670, 1.191680, -0.835610, 0.049940, -0.256150, -0.083510,
-0.567840, -0.637360, 0.463670, -0.098000, 0.005660, 0.074800, 0.515640, 0.714100, 0.578140, 0.750120,
0.959340, -0.847630, -0.760460, 0.797910, 0.188070, -0.373470, 0.075100, 0.846450, 0.917020, -0.643580,
-0.302490, 1.108270, -0.206650, -0.872840, -0.421810, 0.375250, 0.773520, 1.080960, 0.643060, -0.391290,
0.750860, 0.058810, 0.287300, -0.655590, 0.742490, 0.655500, -0.293980, -0.072530, 1.076810, 0.122660,
-0.769510, -0.731110, 0.028030, 1.329650, 0.244750, 1.023120, 0.106570, -0.320120, -0.291920, -0.751390,
0.973160, -0.326250, 0.703770, -0.322510, -0.302270, 1.154090, -0.355140, 0.236080, 0.711040, 0.442450,
-0.040480, 0.129370, 0.063810, 0.085940, -0.638540, -0.365710, -0.039180, 0.676620, 0.580030, 0.649620,
1.115760, -1.076840, -0.247770, -0.250740, -0.105810, 1.431330, 0.351270, 0.677420, -0.653460, 0.001760,
-0.704020, 0.273300, -0.541460, 0.357400, 0.397210, 0.621330, -1.044370, 0.164740, 0.414240, -0.810320,
-0.104670, 0.164210, -0.136770, 0.138790, 0.128080, 0.242710, 0.450240, -0.868090, -0.443340, -0.682480,
0.741340, -0.515860, -0.076040, -1.038850, 2.149810, -0.553720, -0.284910, -0.105260, 0.121040, -0.910110,
0.222160, 0.588570, 0.795620, -0.766550, 0.416150, 1.264690, -0.120080, 0.549630, -1.153680,
-1.481680, 0.157920, 0.854750, 0.501050, 0.789500, -0.519110, 0.643660, 0.664310, -0.013390, -0.797440,
-0.567870, -0.202100, 0.460930, 0.025110, 1.109560, -0.148180, 0.504600, 0.328210, 2.010460, 0.546150,
0.470130, -0.315450, 0.478990, -0.168440, -2.204760, 0.055080, -0.451360, 0.224840, 0.330600, -0.273930,
-1.204120, 0.732340, 1.046440, -3.620380, -0.301050, 0.613870, -3.068830, -0.087260, 0.307350, -3.259450,
1.373330, 0.113570, -0.839870, 1.877200, 0.678390, -4.911560, -0.394550, -0.149260, -6.443040, -0.238770,
0.631620, 0.237880, -0.116610, -1.569360, -4.042430, -0.928960, 0.935130, 1.360490, -0.528120, -1.144210,
-0.041420, -0.238850, -0.845590, 0.524070, -0.216360, -0.232910, -0.406570, 0.212580, -0.140040, -0.255290,
-0.825060, -0.114400, -0.412320, -0.713610, -0.346470, 0.822840, 0.324110, 0.259210, 0.921110, 0.363520,
0.816560, -0.261940, 0.510090, 0.293720, -0.518500, 0.626040, 0.067800, 0.457700, 0.009600, 0.055810,
-1.198020, 0.013660, 0.393700, 0.633280, -0.838200, 0.377660, 0.509960, 0.456460, 0.552350, 0.334920,
-0.239870, -0.371280, 0.698880, -0.883250, 0.023160, -0.443600, -0.595970, -0.050300, 0.615410, -1.094000,
-0.604360, -0.567520, 0.507980, -0.555420, -1.445800, -0.602140, -0.788980, -0.741870, 0.203680, -0.898200,
0.660540, 0.002320, 0.669010, 0.976420, -0.731740, -1.851120, 2.952180, -0.824930, 0.092520,
0.553690, -0.214560, -0.900610, -0.829490, 0.845360, -0.062810, -0.023520, 0.278790, 0.177340, 0.884900,
-0.783570, -0.576170, 0.438650, -0.887160, 0.433390, 0.122280, 1.088660, -0.735120, -0.505240, 0.010590,
0.334790, 0.792430, 0.136120, 0.211210, 0.023670, -0.639400, -0.501230, -0.080320, -2.267950, -0.965230,
0.682600, -0.011680, 0.740470, -0.373720, 0.817550, 0.615970, 0.217970, 1.051180, -0.309990, 1.315660,
0.715750, 0.226630, -1.580920, -0.569510, -0.149790, -0.970010, 0.582910, -0.834730, -0.664310, -0.628320,
0.537120, 1.498230, -1.050610, 0.244760, -4.783750, 0.363360, 0.798330, -0.324950, -0.619880, 0.282590,
2.024910, -0.709280, 0.576150, -1.550670, -0.013710, 0.860910, 0.598950, -0.696490, -0.248720, -0.461370,
-0.795920, -0.897830, -0.625050, 0.113990, 0.686070, 0.060330, 0.451130, 0.839990, 0.723840, 0.028920,
0.239170, 0.219310, -0.105350, 0.886680, -0.947620, 0.699300, -0.310280, 0.678320, -1.239540, -0.311620,
-0.234050, 0.581910, -0.561570, 0.201200, -0.453970, -0.485750, 0.103520, -0.236870, -0.538240, -0.660190,
-0.074240, 0.733110, -0.898230, 0.393150, -0.517570, -0.005690, 0.153910, 1.523970, -0.216420, -0.198960,
0.661230, -0.101880, -1.179590, 1.300030, 0.799710, 0.872320, -0.670970, -0.266320, 0.571380, 0.296010,
-0.181490, -0.410990, 0.726650, -0.381740, -0.278830, 0.338570, 0.444120, 0.379260, 0.968500,
0.297710, -0.480680, -1.716700, 0.449500, 1.518260, 0.247400, 0.865160, -0.042900, -1.075780, -0.151420,
-0.484610, -0.509600, 0.041660, 0.449110, 0.019920, -0.648300, -0.867790, 0.294610, -0.136930, -0.377360,
-0.268350, 0.881690, 0.649650, 0.048110, -0.565800, -1.424120, -0.651080, -0.389840, 0.452210, 0.189280,
-0.703320, -0.959460, -1.015730, 0.155470, -2.045800, -0.025500, 0.624310, 0.761100, 0.263840, -0.382280,
-0.372760, 0.437500, 0.798980, -0.681440, -0.398910, 0.023850, 0.514520, -0.401790, -0.698340, -0.325790,
-0.389530, -0.749860, -0.943780, 0.444950, 2.351580, -0.729760, -0.511240, 0.184880, 0.548700, 0.473950,
-1.139160, 0.573830, -0.202910, 0.099570, 0.577890, 0.313460, 0.511330, -0.864160, 0.588010, 0.701110,
-0.331270, 0.566870, -0.184290, 0.421290, -0.344570, -0.095580, 0.480360, -0.431460, 0.974980, 0.410800,
0.668560, 0.991090, -0.315140, 0.241530, 0.871800, -0.972090, 0.309790, -1.153960, 0.586990, -0.836300,
-0.384140, -1.040570, -0.436080, 0.006990, -0.720970, 0.560660, 1.068010, -0.055460, 0.419500, -0.877920,
-0.210360, -0.375630, -0.806460, 0.876920, -0.078100, -0.542100, -0.750650, 2.143840, 0.835080, -0.457790,
0.047340, 0.249940, -0.299900, 2.787260, -0.217580, 1.205020, -0.164820, -1.792540, -0.910950, 1.330840,
-3.852250, -0.800390, 0.531130, 0.550870, 0.870140, 0.030040, -0.599670, -0.027350, 1.045070,
-0.730090, 0.779550, -0.090720, -0.129520, -0.931440, 0.150340, 0.608270, -0.616590, -0.695080, 0.010590,
-0.691700, -1.210630, -1.060190, -1.068820, 0.210350, -0.239580, 0.486150, 0.650880, 0.236710, 0.181390,
-0.136430, 0.169730, 0.110200, 0.206130, -0.837370, 0.313240, -0.736610, 0.735220, 0.432830, -0.258030,
0.027750, -0.464950, 0.479840, -0.972540, 0.004390, 1.259010, 0.352860, -0.802470, -0.777030, -0.735080,
0.613110, 0.376290, -0.999090, -0.601420, -0.279720, -0.196880, 0.109740, 1.752500, 0.792640, -0.166990,
1.259350, -0.133880, -1.088850, 0.809770, -0.651730, 0.499430, 0.687220, -0.873650, -1.163890, 0.913230,
1.378040, 0.225910, 0.110120, -1.891860, 0.566250, 1.604840, 0.095100, -1.092120, 0.058500, 0.960020,
0.415310, 0.306800, -0.876240, 0.020410, 0.558180, 0.444790, 0.919730, -0.617910, 0.561290, -0.779230,
-0.411000, -0.368460, 0.275040, 1.106530, 0.081340, 0.299980, 0.680270, -0.350950, -0.048730, -0.285750,
-0.320550, 0.772220, 0.288940, -0.154190, -0.433970, -0.737650, -0.517900, 0.828730, 0.404470, 0.045020,
-0.009050, 0.045840, -0.052560, -0.426380, -0.434450, -1.706730, -0.803280, 0.107830, -0.053420, 0.605970,
0.429390, 0.457220, -0.133980, 0.939420, -0.587890, 0.209720, -0.087290, 0.052140, -0.885450, -1.197930,
-0.788030, -0.300700, -1.134000, 0.474630, -0.262520, -0.234760, 0.636780, -0.196210, 0.408720,
1.017150, 0.518880, -0.872830, -0.115500, 0.287620, 0.037230, -0.011250, 0.081420, 0.390340, 0.153550,
-0.325100, 0.904490, -0.202610, 1.216700, -0.777800, -0.481250, 0.219990, 0.572990, 0.114780, -0.941150,
0.495350, -0.192430, 0.175490, 1.132790, -0.261840, 0.884170, 0.120570, -0.412660, -0.605780, 1.082360,
0.568660, -0.835990, 0.297450, -1.066020, 0.549110, 0.601260, -0.644520, 0.168690, -0.425460, -0.393920,
0.787010, -0.027790, 1.415950, 0.441580, 1.619600, -0.445180, 0.173470, 4.545850, -1.208350, -5.486550,
-0.194690, -0.603700, -1.063870, 5.445350, -1.414530, 1.101930, 4.029670, -0.728080, -0.595270, 3.347120,
-1.323050, -7.080350, 1.038260, -1.578150, 3.203140, 6.154430, -0.138830, 0.396310, 1.014680, 0.653630,
-7.283180, -0.317440, 0.273460, 10.914550, 0.940890, 1.123200, 0.931800, 1.147550, 1.089020, -9.303100,
0.342200, -1.280400, 3.191150, -1.542250, -0.408350, -0.646820, 0.586480, 0.459010, -3.274400, 0.169930,
-0.011690, 12.571920, -2.575060, -0.076270, 2.731730, 1.250300, -0.851530, -4.362140, -0.332620, -1.073950,
-0.858680, 1.415150, -1.263840, 0.848260, 0.332170, -0.194440, 1.811840, -2.112050, -0.210270, 0.016720,
0.808120, 0.636930, 0.116000, -0.989750, -2.220050, -1.276440, 1.217000, 0.253150, 0.547620, -0.259110,
0.310940, 1.218450, -4.734690, -0.412120, -0.897430, -0.607730, 0.400470, 0.388540, -1.619110,
0.525610, -0.040890, -0.377370, 0.572170, 0.802780, 0.044080, 0.827420, 0.797110, 0.294500, 0.415470,
-0.895640, 0.502970, -0.051920, 0.361790, -0.339690, -1.006390, 0.470700, 0.186850, -0.515050, 0.569310,
0.625020, 0.154290, -0.085350, -0.545430, 0.572800, -0.109560, -1.060870, 0.422690, -0.407480, -0.521400,
1.129380, -0.444200, 1.704450, -0.249570, -0.221830, -0.360090, 0.189510, -0.571320, -0.725550, 0.958290,
0.690660, -1.053390, -0.031000, 1.223490, -0.122120, 1.064420, 0.700100, -3.358660, -0.441460, 0.738910,
-0.442490, -1.033720, -1.131850, 0.744810, -0.427500, 0.879530, 0.177590, 0.125320, -0.444740, -0.934820,
-0.500560, -1.293610, 0.112950, 0.209500, 0.132350, -0.163340, 0.356950, 0.021320, -0.907200, 0.433740,
-0.964460, 0.850430, 0.499510, -1.048180, 0.219840, -0.164350, -0.893200, -0.954370, 0.062790, -0.661500,
0.301120, 0.059340, 0.668640, 0.408030, -0.711460, 0.415860, -1.028300, 0.571900, 0.513010, 0.665560,
-0.695430, 0.311080, 0.575960, -0.378560, -0.110490, -0.676860, -0.509350, -0.462190, -0.638640, -0.437230,
-0.073470, -0.757540, -0.130690, -0.102820, -0.020030, 0.854110, -0.861480, -0.230490, -0.493060, 0.574540,
-0.424640, 0.856400, -0.506030, -0.073230, 0.264050, -0.641130, 0.263650, -0.188470, 0.626140, -0.331140,
-0.802570, -1.004850, 0.791680, 0.601780, 0.681760, 1.946070, -0.144720, -0.137630, 0.590630,
0.275730, 0.624540, 0.521210, -0.888310, -1.033180, 0.832160, 0.504440, -0.960290, -0.012600, -0.408120,
-0.766830, -0.359320, 0.903900, 0.177520, -0.364240, -0.800790, 0.190670, -0.164750, 0.498000, -0.637600,
1.549580, 0.382770, 0.090670, -1.022220, -0.383280, 0.248700, -0.922200, 0.457750, -0.088540, 6.084200,
1.068330, 0.710640, 0.000490, 1.663780, 0.645100, -3.607090, 0.577360, 0.444740, 0.494570, -0.131890,
0.767030, -0.541260, 0.138620, -0.807380, -5.031370, 0.610130, 0.230940, -4.677430, -0.204250, -0.335760,
-2.190430, 0.908750, 1.755460, -3.268310, -0.162260, -0.796540, -2.019430, -0.237460, -0.580710, -1.428270,
-0.120600, -0.650810, 0.135000, 0.539010, -0.724760, -1.098830, 1.157340, -0.147800, 0.484180, -1.963190,
-0.468800, 0.217520, 0.125510, -1.122200, 0.414020, -0.253420, 0.779530, -0.555620, 0.108610, 0.338310,
0.072450, 0.017900, -0.868310, 0.928420, -0.878870, -1.234210, -0.782000, 0.337960, 0.589830, -0.388410,
-0.290020, 0.628900, 0.154740, 0.608370, 0.373060, 0.759580, -0.506610, 0.622160, 0.296790, -0.780850,
-0.152330, 0.752390, -0.121920, -0.903430, -0.166860, 0.412200, 0.810320, 2.695600, 0.603660, -0.598890,
-1.120630, -1.179050, 0.645500, -0.795370, -0.606100, -0.021320, 0.210320, 0.261910, 0.396280, -0.513830,
2.371250, -0.723190, -0.861890, -0.250570, 0.307790, -1.004240, 0.393250, 0.930550, -0.641270,
-0.899960, -1.754780, 0.585950, 0.254660, 0.387190, -0.120930, -0.357210, -2.715030, 0.445580, 0.893710,
0.499800, 0.351600, 0.013530, -3.457420, -0.024560, 0.399440, -5.874040, -0.487170, 0.479320, 10.828450,
0.346980, -0.735610, -5.054440, 0.052890, -0.047230, -16.690121, -0.363860, -0.892400, -0.763140, -1.356860,
0.416970, -0.446830, -1.279330, -0.251560, -0.483940, -0.584590, 0.654100, -6.062300, -1.313340, 0.605710,
7.528920, 0.151040, -0.578270, 0.482700, -0.916370, -0.730960, -7.432910, -2.608800, 0.385450, 4.996800,
-0.454870, 0.475350, 0.210730, 0.610120, 0.016900, -3.046500, 0.448190, 0.918550, 3.602710, 1.787040,
-0.725130, 1.143260, 0.165360, 0.861200, -1.073600, 0.935840, -1.067360, 1.089520, 1.231620, 0.773070,
0.289840, 0.714900, -0.292440, -0.918740, 0.124150, -0.426060, 0.687740, -0.173110, -0.753740, 0.373540,
-0.539900, 0.563550, 0.782340, 0.212440, 0.111680, 0.484110, -0.196950, 0.123720, 0.116870, 0.552700,
-0.924630, 0.263440, 0.888090, -0.009660, 0.133240, -0.533750, -0.214320, -1.166240, -0.392560, -0.008290,
-0.291530, -0.305160, 0.561190, -0.570880, 0.641040, 1.297350, -1.022220, -2.186710, 0.494680, -1.091440,
0.725740, -0.527410, 0.633990, -0.501310, -5.848210, 0.083720, 0.608110, -1.483640, -0.381120, -0.147610,
1.039170, 0.612770, -0.572190, -1.362920, -0.573440, 0.563660, -0.539730, -0.887200, 0.927550,
-0.663350, 0.552170, -0.583500, 0.906060, -0.271660, 0.492190, -0.812470, -0.058640, -0.305290, 1.125040,
0.016310, 0.625390, 1.015500, -0.586090, 0.282800, 0.242760, 1.051910, 0.843760, -0.593580, 0.488040,
0.698720, 0.548910, -0.113680, 0.027760, -0.613400, -0.240630, 0.052030, 0.746100, 0.126450, -0.848600,
-0.452790, -0.308420, -0.237330, 0.638610, 0.497390, 0.287750, -0.909350, 0.102950, -0.840180, -0.479690,
1.245130, -0.305900, -0.034890, 1.721320, -1.011800, 0.365280, 0.363810, 2.087890, 0.527750, 0.825090,
-1.055060, -0.075560, 0.577400, -0.867230, -0.385770, 2.810930, -2.626510, -0.151740, 0.710920, 0.186810,
-0.585340, 1.326470, 0.225360, 0.912770, 1.317650, -1.221410, -0.214500, 0.366750, -0.817230, -0.479080,
-0.308750, 0.065590, 1.185600, -0.414750, 0.915190, 0.040730, 1.152390, -0.398260, 0.697570, 0.060210,
0.310560, 0.539230, -0.265420, 0.429770, -0.054610, 0.111500, -0.972890, 0.906320, -1.170500, -0.110710,
0.522280, -0.026610, 0.357110, -0.530560, -0.229380, 0.407020, -0.591330, -0.019420, -0.506940, -0.006970,
-0.112030, -0.785720, -0.524320, 0.456470, 1.193020, 0.245990, -0.131610, -3.548040, -0.389300, -0.049540,
0.887880, 0.126810, -0.759590, -0.800020, -1.848240, -0.731740, 0.100150, 1.194350, 0.513220, 0.108190,
-0.663420, 0.753780, 0.843010, -0.672230, -0.834600, 0.459570, -0.682220, -0.298350, -0.466680,
0.027510, 0.164200, -0.304370, -0.409330, 0.428440, 0.857890, 0.493040, 0.443530, 0.262740, 0.635240,
-0.265800, 0.708760, -0.806910, -0.373280, 0.819270, -0.591000, 0.092210, -0.856950, -0.976870, -0.340890,
0.636270, -1.113090, -0.138840, -1.047110, -0.631690, -0.710760, 0.670830, -1.211360, 0.368940, -0.285070,
-0.213790, -0.586750, 0.266330, -1.325750, 0.625880, 0.692370, -0.025260, 0.524640, -0.393730, 0.396850,
0.232280, 0.408610, -0.989400, 0.338520, 0.827470, -0.160170, 0.982780, -0.468300, -0.206410, 1.288770,
-0.672100, 0.655530, 0.707490, -0.510920, -1.697820, 1.111430, 0.056460, -1.153970, 0.808650, 0.264430,
2.077910, -1.032640, 0.222380, -7.071710, -0.305980, -0.413770, 0.240730, -1.037810, -0.446380, 0.728140,
-1.616160, 0.222590, -3.588750, 0.790150, -0.551470, -0.307090, -0.474340, -0.465080, 2.654450, -0.399640,
-0.075310, -0.057860, 0.757820, -0.596630, -0.089210, -0.651100, -0.878790, -0.025440, 0.699070, 0.223870,
-2.063160, 0.420930, -0.674130, -1.017330, -1.020380, 0.209250, -0.870440, 0.618150, 0.396620, 0.673220,
-1.045930, -0.381450, 0.608160, 0.406320, -0.465320, -0.443940, -0.168010, -1.146700, -0.522880, 0.746900,
0.465560, -0.465870, -1.044700, -0.422480, 0.874360, 2.909190, 0.608220, -0.459730, 0.126440, 0.265480,
0.341050, 0.829190, -0.428460, 0.577970, -0.675550, 0.391710, 1.362620, -0.508420, 0.763490,
-0.968670, -1.080540, 0.655640, 0.821790, -0.227720, 0.822330, 0.397020, 0.071850, -1.332260, 0.177290,
-0.119580, -0.843120, 0.291160, 0.286250, -0.099610, -1.107080, 0.826930, -0.036570, -0.806830, 0.096460,
-1.626940, -0.730350, -0.287080, -0.277890, -0.776760, 0.679550, 0.511720, 0.674460, -0.739350, -1.212650,

-0.882470, 0.653400, -0.483560, -0.637330, 0.740460, -0.852320, -0.344110, 0.452560, 0.592660, -0.827480,
0.012100, -0.198110, 0.914150, 0.393570, -1.347970, 0.475840, -1.357420, -1.283830, 0.724820, -0.141090,
-0.221220, 0.805520, -1.049220, -0.830720, 0.171570, 0.360520, 0.262940, -2.516830, -0.047590, 0.847620,

0.710780, 0.522910, -0.265090, 0.724100, 0.465520, -0.765630, -0.345750, -0.121170, 0.727470, -0.091210,
-0.158360, -0.654300, 0.236090, -0.864180, 0.575320, -1.267180, -0.426340, 0.591070, -0.763440, -0.789240,
0.361060, -0.478530, -0.194300, 0.926150, 0.811170, -1.300260, -0.673890, -0.175080, 0.034030, -0.084580,

-0.519040, -0.128880, -0.368450, 0.260080, 0.455690, -0.892670, 0.640250, -0.710780, -2.160930, 0.224290,
-0.319070, 0.315620, 0.363730, 0.390840, 0.219050, -1.313610, 0.977760, -0.333710, -0.669850, 0.683090,
-1.351450, -1.371340, 0.632030, -0.622320, -1.158110, -0.606340, 0.377330, 0.386770, -0.153570, -1.203150,

0.354800, -0.310220, 1.008410, -0.384150, -0.355460, -0.391480, 0.239490, 0.544230, 0.480320, 0.290270,
0.666730, -0.998770, -0.971000, 0.229940, -2.934970, 1.169360, -1.207250, -0.786330, -0.008540, -0.449500,
-0.022860, 0.408270, -0.742960, -0.342160, 0.710240, 0.741790, 0.728980, -1.632330, 0.478700, 0.585510,

-0.001250, 0.194320, -0.560880, 0.702930, -0.511470, 0.731650, -0.709900, 0.375440, 0.180870, -0.922790,
-0.052110, 0.966820, 0.258100, -0.186530, -0.120890, -0.718410, -0.357920, 0.528030, -0.330560, 0.404600,
0.689740, 0.809090, -0.372730, 0.220180, 0.446100, -0.569690, -1.141690, -0.105190, -0.819760, -0.537390,

0.395650, -0.490750, -0.860280, -0.391420, 1.099470, -0.354040, 0.715480, -1.072620, -1.824860, -0.811200,
0.329940, 0.964890, 0.673240, 0.940170, 0.647530, -1.331640, 0.518940, 0.559300, -0.934650, -0.129860,
0.405760, -1.038980, 0.425830, -1.421100, -1.597190, -0.246200, 0.257260, -0.121350, -0.019810, -1.508110,

0.703210, -0.849650, 0.354950, 0.089410, -0.614140, -0.825660, 0.227990, 1.260860, 0.772850, -0.157720,
0.001460, 0.570360, -0.881080, -0.274790, -5.476300, 0.783570, -0.419960, 0.044280, 0.296290, 0.489610,
0.408930, -0.498770, -0.309540, -0.205090, -0.473450, 0.022140, 0.737620, -1.040020, 0.166030, 0.476700,

0.466490, 0.646360, 0.805580, -0.273120, 0.038130, 0.451740, -0.912540, 0.156320, -0.262360, -0.039600,
-0.658010, -0.615340, 0.096200, 0.144430, -0.228010, -0.642180, -0.471250, -0.292020, -0.623800, 0.146990,
-0.196470, 0.692030, 0.054490, 0.830270, 0.500360, 0.220910, -1.068110, 0.438510, -0.763040, -0.388580,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
  static UnitType Units[169] =
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
    { /* unit 100 (hid1) */
      0.0, -0.685320, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.330080, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.005070, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.075180, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.522870, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.140490, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.757560, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.574690, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.182210, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.868050, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.944590, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.322140, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.488050, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.096440, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.365640, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.090740, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.306220, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.530860, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.332560, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.846180, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.271680, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.022610, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, 0.057010, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.319300, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.800060, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.588820, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, -0.113240, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.888790, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.278840, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.436780, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.251530, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.766720, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.315350, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.535670, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -1.024420, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.877720, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.195760, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.533500, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.849090, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.01028, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.00021, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
1.40683, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42845, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
1.41401, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.91811, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.30607, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.02581, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.32134, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
0.74967, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.40334, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.42842, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.40437, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
1.02257, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
1.42052, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.95816, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.25600, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.00000, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.14248, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.42684, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.00136, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.12086, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
1.31673, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
0.92908, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
1.18349, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.05805, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.00000, 0.500000, 2,
       &Sources[4198] ,
       &Weights[4198] ,
      }

  };



int net(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[99] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99}; /* members */

  static pUnit Hidden1[30] = {Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129}; /* members */

  static pUnit Output1[9] = {Units + 130, Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138}; /* members */

  static pUnit Special1[1] = {Units + 139}; /* members */

  static pUnit Special2[1] = {Units + 140}; /* members */

  static pUnit Special3[1] = {Units + 141}; /* members */

  static pUnit Special4[1] = {Units + 142}; /* members */

  static pUnit Special5[1] = {Units + 143}; /* members */

  static pUnit Special6[1] = {Units + 144}; /* members */

  static pUnit Special7[1] = {Units + 145}; /* members */

  static pUnit Special8[1] = {Units + 146}; /* members */

  static pUnit Special9[1] = {Units + 147}; /* members */

  static pUnit Special10[1] = {Units + 148}; /* members */

  static pUnit Special11[1] = {Units + 149}; /* members */

  static pUnit Special12[1] = {Units + 150}; /* members */

  static pUnit Special13[1] = {Units + 151}; /* members */

  static pUnit Special14[1] = {Units + 152}; /* members */

  static pUnit Special15[1] = {Units + 153}; /* members */

  static pUnit Special16[1] = {Units + 154}; /* members */

  static pUnit Special17[1] = {Units + 155}; /* members */

  static pUnit Special18[1] = {Units + 156}; /* members */

  static pUnit Special19[1] = {Units + 157}; /* members */

  static pUnit Special20[1] = {Units + 158}; /* members */

  static pUnit Special21[1] = {Units + 159}; /* members */

  static pUnit Special22[1] = {Units + 160}; /* members */

  static pUnit Special23[1] = {Units + 161}; /* members */

  static pUnit Special24[1] = {Units + 162}; /* members */

  static pUnit Special25[1] = {Units + 163}; /* members */

  static pUnit Special26[1] = {Units + 164}; /* members */

  static pUnit Special27[1] = {Units + 165}; /* members */

  static pUnit Special28[1] = {Units + 166}; /* members */

  static pUnit Special29[1] = {Units + 167}; /* members */

  static pUnit Special30[1] = {Units + 168}; /* members */

  static int Output[9] = {130, 131, 132, 133, 134, 135, 136, 137, 138};

  for(member = 0; member < 99; member++) {
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

  for(member = 0; member < 9; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}
