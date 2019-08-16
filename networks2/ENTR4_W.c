/*********************************************************
  TMPENTROP4+weight_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:19:42 2004
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
1.365960, -0.728980, 0.310790, -0.145740, -0.302580, -0.442040, -0.838100, 0.629040, 0.338450, 0.221280,
0.055830, -0.232400, 0.712580, 0.054020, -0.949640, -0.713820, -0.078670, 0.096480, -0.192860, 0.216950,
1.589410, -0.702190, 0.930060, -1.148040, 0.279770, -0.975310, -0.185200, -0.112450, -0.160130, -0.162600,
-1.085380, -0.166090, -0.135110, 1.442360, -0.559530, 1.424540, -1.377130, -0.561110, 0.683190, 0.779860,
-0.832450, 1.076830, 1.488560, -0.571510, 0.081090, -5.471900, 0.514530, 1.541480, 1.573690, 0.010630,
0.273950, 0.910440, -0.782530, 0.419990, -1.220810, 0.607700, 0.210920, 0.073110, 0.464030, 0.526040,
0.928310, -1.061080, -0.508110, 0.316930, -0.569130, 0.562490, -0.431370, 0.798700, 0.667630, 0.906930,
-0.387720, 0.873640, -0.617700, -0.681580, 0.415370, 0.237870, -0.036840, -0.332210, -0.113930, -0.256360,
-0.397080, -0.917870, 1.744720, 0.062940, -0.907200, -0.328690, -0.763420, 0.051740, -0.836750, -0.857080,
0.629420, 0.163550, 1.502680, -0.789900, 0.994560, -0.260690, 0.742890, 0.301850, 0.329070, -1.587500,
-0.290000, 0.613030, 0.077580, 0.249850, -0.493340, -0.433460, 0.501970, -0.643730, 0.218770, -0.279620,
0.947620, 0.325890, 0.635230, -0.221670, -2.004140, -0.147020, -0.100800, -0.375770, 0.229180, 0.916760,
-0.732060, -0.957030, 0.251840, 0.563500, -1.094700, -0.819090, -0.789680, -0.089480, -0.111240,
0.162160, -0.047220, 0.714400, -1.019900, 0.218520, 0.345040, -0.813390, -0.035020, -0.479980, 0.312080,
0.046890, -0.248250, -0.723950, 0.504510, 0.090390, -0.063720, 0.290180, 1.046110, -0.614340, -0.859260,
0.779420, 0.774630, 0.144960, -0.670540, -1.055020, -0.467630, -0.553800, 0.526650, 0.795830, -0.326070,
0.271080, -0.310860, 0.699660, -0.916620, 0.025720, 1.136990, -0.264130, 0.473020, 0.221470, -0.044950,
-0.356300, -0.435910, 0.556770, -0.488250, 0.057120, -0.464940, 0.670350, -0.529900, 0.732570, 0.552280,
-0.588600, -2.359130, -0.437050, 1.016540, -1.961710, -0.383840, -0.969460, -1.835370, 0.135780, -0.707790,
3.464270, 0.539150, 0.860190, -2.642800, -0.593240, 0.868130, 0.297710, -0.903060, 0.367550, 0.133870,
0.987520, -0.117970, 0.546350, 0.054360, 0.868360, -0.339960, -0.139630, -0.517770, -0.322340, -0.314860,
0.881830, -0.661270, -0.319870, -0.379230, 1.118820, 0.116870, 0.654680, 0.199770, 0.318000, 1.111380,
-0.610640, 0.994140, 0.333850, 0.142910, 0.564540, 0.883360, -0.021530, 0.272110, -0.629800, 0.044220,
0.233130, -0.619350, -0.401230, -0.333530, 0.252200, 0.199640, -0.660970, 0.327840, -0.769330, -1.087250,
0.657070, 0.617730, 0.068720, -0.768760, 0.465490, 0.289940, -0.643380, 0.382180, 1.078180, -0.241220,
-0.695740, 0.738580, 0.141810, 0.405690, 0.122010, -2.783610, 1.545230, -0.893970, -0.631860,
-0.393000, 0.538200, 0.055640, 0.980740, -0.103950, 0.019380, -0.555440, 0.278370, 0.273320, -0.817880,
0.451930, -0.560750, -0.134450, -0.114940, 0.457370, -0.706700, -0.131530, -0.893590, -0.318840, -0.884530,
-0.447750, 0.353030, -0.399550, -0.901750, 0.425660, 0.071410, -0.693160, 0.224470, -0.408000, -0.634190,
-0.791430, -1.504670, 0.528600, 0.560790, 1.035390, -0.744690, -0.650610, -1.841060, 0.089760, 0.032270,
-0.191080, -0.767520, -0.232590, 2.764880, -0.045140, 4.331720, -3.301800, -0.457040, -0.469780, 0.156950,
-1.646570, -0.067340, 7.700560, 0.885650, -0.521590, 1.901360, -2.622930, 0.499650, 0.336130, 2.295640,
-0.510180, 0.502530, -2.623330, -1.896320, 3.127510, 5.345430, 0.514630, -0.119420, -0.698860, 0.064730,
-3.669530, -0.598270, 0.096110, 0.428400, 1.407620, -0.702180, 0.701110, 1.981190, -0.364040, -2.963770,
0.929860, 0.548630, 0.915620, 0.367020, 0.055760, 0.863970, 0.869030, 0.094840, 0.514640, -0.296440,
-0.849990, 0.474470, 0.453930, 0.819720, 1.487770, -1.579180, -0.268620, 1.896640, 2.731200, 0.974490,
-0.890720, 0.086110, 0.588710, -0.337510, -0.152550, -0.507750, 0.708350, 136.994553, 0.212640, 0.004060,
-0.991500, 0.134320, 0.365310, -0.671060, 5.925190, 0.504350, 0.759290, -2.303270, 2.209970, -0.401600,
0.564400, 0.480770, 0.902180, -0.190030, 0.565580, -1.304400, -2.356350, 0.234920, -2.286350,
1.154540, -0.783760, -0.893890, 0.044390, 0.752070, 1.040620, -0.248120, -0.125000, -0.469720, -0.078000,
-0.115210, 0.010840, 0.088010, -0.307520, -0.570830, -0.225880, -0.622950, -0.523760, -0.410720, 0.739510,
-0.884700, -0.897760, -0.150020, 0.354730, 1.327140, -0.273150, -0.839850, 0.083810, 2.020040, 0.648870,
-0.288320, -0.047770, 0.525870, 0.456830, -1.262230, 1.013560, 0.030330, -1.185830, 0.219570, 0.015830,
0.020120, -0.109270, -0.212950, -0.010600, -0.308050, 0.527310, -1.945850, 0.279420, -0.860370, -0.943600,
-0.264800, -0.585400, 2.257850, 0.182150, -0.114310, -1.077800, -0.101480, -0.456570, 0.484000, -0.582610,
-0.250740, 0.342610, 0.328510, 0.919240, -0.922370, -0.246340, 0.905600, 0.447230, -0.395860, -1.077580,
0.533080, -0.356560, 0.170470, -0.842960, -0.685940, 0.066170, -0.039640, 0.147220, -0.500600, 0.472860,
-0.195840, 0.587090, -0.545500, -0.350160, -0.696500, -0.563660, -0.460800, -0.759660, -0.912900, -0.311170,
0.697620, 0.568700, -0.259490, 0.759500, -0.423260, -0.538700, 0.423810, -0.179790, -0.827690, 0.670630,
0.653610, -0.675170, -0.684310, 0.577840, 0.037910, 0.028260, 0.757340, -0.651270, 0.708580, 0.872770,
0.512380, 1.143570, -0.050860, 1.926780, 0.319190, -0.453170, 0.757920, -0.890370, -0.026950, -1.218310,
-0.980680, 0.211890, -0.798880, -0.047500, 0.631060, -1.826860, 1.156060, -0.214090, -0.211950,
0.386760, -0.136170, 0.297790, -0.034790, -0.133920, 0.464850, -0.141920, 0.956240, 0.806560, -0.116270,
0.670170, 0.996400, 0.204920, 0.110970, -0.343760, -0.515600, -0.090070, -0.845360, 0.148660, 0.093690,
0.512060, -0.943520, -0.955490, -0.557420, -0.686460, 0.563220, 0.036370, -0.573770, -0.571900, 0.226800,
-0.573380, 0.809420, 0.081170, 0.101250, -0.806840, -0.440420, -0.073310, -0.770150, 0.213450, -0.493220,
-0.918500, 0.171650, 1.226760, 0.238290, 0.627970, -0.064860, 0.896780, -0.891730, -0.025950, 0.060530,
0.727750, 1.482410, 0.219690, -0.117250, 0.356810, 0.756840, -1.483860, 0.616930, -0.744500, -0.279800,
0.152730, -0.160880, -0.028010, 0.775420, -1.192840, -0.900770, -0.095450, -0.688810, 0.120470, 0.284110,
1.743680, 0.310700, -0.766480, -0.483750, 0.609880, 0.264190, -0.993410, 0.244090, 0.129250, 0.054100,
0.744320, -1.217690, -0.883980, 0.367620, 0.506440, 0.685970, -0.371290, -0.270630, 0.424700, 0.227560,
0.907230, 0.489760, 0.333990, 0.108410, -0.841260, 0.105110, -0.149680, 1.145460, 0.072930, -0.543050,
1.005960, 0.232680, 0.770700, -0.491510, 0.916320, 0.379650, 0.950350, 0.444300, 0.052570, -0.503070,
1.040750, 0.269100, -0.723690, 0.447420, 0.708070, -1.229200, -0.677090, 0.488190, 0.794920, -0.344300,
-1.656930, 0.353340, 0.593300, 0.264830, 0.636790, 0.200920, -1.414200, -0.644870, -0.011960,
-0.367260, 0.246240, 0.417590, 0.414640, -0.088910, 0.420030, -0.094080, -0.098640, -0.256590, 0.309100,
0.550140, 0.629680, -0.331850, -0.435760, -0.284810, 0.498770, -0.595840, -0.909830, -0.349300, -0.571040,
-0.439560, -0.142320, -0.308710, -0.597110, -0.460770, -0.710490, 0.475890, 0.740910, 0.889610, 0.858240,
-0.850030, 0.236510, -0.338340, 0.333090, 1.225400, 0.953950, 0.730500, -0.869810, -0.315610, -0.524210,
0.109900, 0.253330, -1.122290, -0.521680, 1.687250, -0.197570, 0.738460, -1.115580, 0.165070, -1.276560,
0.118430, -0.048350, 0.115390, 0.143490, -0.371800, -0.970380, 3.139120, 0.408070, -1.084990, 0.667260,
-0.007080, 1.558020, -0.122090, 0.042000, -1.439820, 1.257180, -1.011770, -0.859520, 0.219740, 0.043050,
0.284760, 0.060800, 0.385840, -0.100760, -0.341040, -0.647750, -0.361120, -0.438950, -0.402950, 0.833980,
0.498200, 0.528900, 0.145630, -0.549450, -0.543340, -1.356990, -0.915030, -0.003260, 0.460640, -0.339530,
0.523740, -1.595300, -0.603270, -0.369970, 0.569610, 0.490370, 0.325410, -0.025300, 0.212740, 0.278500,
0.451520, -0.543290, -0.033630, 0.135990, -0.611550, 0.441080, 0.786710, 0.991960, -0.200940, -0.750700,
-0.213480, 0.962180, 0.866940, -1.064210, 0.287460, 1.014880, 0.493460, -0.499410, -0.459150, 1.042220,
-0.611540, 0.698680, -0.740730, -0.869090, -0.729480, -1.242230, 1.056940, 0.877730, -0.028590,
0.679030, -0.743360, -1.073110, 0.756340, 0.397420, -0.567010, -0.884280, 0.525520, 0.022620, 0.218720,
0.102010, -0.900700, 0.859190, 0.437160, -0.721130, 0.568740, 0.063470, 0.314280, -0.931520, -0.603860,
-0.721370, 0.467130, 0.187920, 0.496470, 2.317550, 0.486920, -0.051950, -0.289280, 0.030360, 0.044280,
-0.017280, -0.241050, 0.339630, 0.444720, 1.349200, -0.044930, -0.461930, 0.424380, -0.547460, -0.148260,
-0.366220, 0.384020, -0.318370, 0.220750, -1.588380, 0.967760, -4.916090, 0.547320, -0.479510, 0.071560,
-1.282750, 0.527460, 2.173640, -4.895650, 1.065430, 0.615470, -0.798180, 0.486020, 2.195190, -0.494770,
-0.178920, 0.652200, -0.105540, 0.658100, 1.101390, -1.450560, -0.045810, 0.917120, -0.595550, 0.789850,
1.008560, -0.375270, -0.079690, -0.188980, -3.582320, 0.379960, -0.655880, 0.671790, 0.837040, 0.934170,
0.050920, 0.628190, 0.704160, 0.014760, -0.689130, 0.845560, 0.654360, -0.256450, 0.012790, 0.867490,
0.142820, -0.075860, 1.060680, 0.555410, -0.354250, 0.074250, 0.641250, -0.346770, -0.278640, 0.204310,
-0.473310, -0.467460, -0.856000, 0.973230, 2.912390, -0.451600, -0.937040, -0.364710, -0.781810, 0.184510,
-0.812780, -0.155460, -0.414770, 0.705650, 0.697350, -1.088140, -1.745380, 0.064070, -0.850190, 0.265500,
-0.603820, -0.574410, -0.525730, -0.519780, 0.462970, 0.625850, -0.462390, 0.460530, -0.049120,
-0.397730, 0.420590, -0.029780, 0.186160, 0.318800, 0.456840, -0.425690, -0.874590, -0.417290, -0.640040,
0.055470, 0.347860, 0.089880, -0.827550, -0.729390, -0.474470, 0.272820, -0.136120, 0.170380, -0.548170,
-1.032930, -0.964930, 0.726240, 0.643170, -0.275710, -0.345030, -0.589260, 0.087440, -0.714440, -0.124370,
-0.399370, -0.563730, 0.781720, 0.057890, -0.363550, -1.025590, -0.207410, 0.960510, 0.495190, -0.035540,
0.110540, -0.350090, 0.811890, -0.806900, 0.322250, -0.707690, -0.863890, -0.702230, -0.063370, 0.278100,
-0.252220, 0.074800, -0.004410, -0.975340, -1.223080, 0.545300, 0.537970, 0.157240, 0.382040, -0.803440,
1.516260, -0.066530, 0.795990, -0.756840, 0.484360, -0.090010, -0.957490, 0.074200, 0.260460, 1.208040,
-0.900020, -0.785460, -1.296190, 0.650110, -0.271320, -0.848230, 0.255400, 0.582280, 2.044630, 0.171050,
0.993250, 0.170660, -0.673470, 0.630570, 0.673700, 0.634950, 0.358010, 0.756110, -0.928300, 0.444170,
0.723840, 0.836580, 0.546380, -0.615190, 1.204460, 0.390220, -0.525900, -0.525710, -0.463410, -0.428210,
-0.406110, 0.253470, 0.534990, -0.279430, -0.805740, 0.819530, -0.669540, 0.193940, 0.172410, -0.325040,
0.729040, -0.892020, -0.749540, 0.319330, 0.880010, -0.094190, -0.866720, 0.841340, -0.728540, -0.122960,
-0.267810, 0.282320, 0.779770, 0.063340, 0.301560, -1.224040, 0.562150, 0.817460, -0.400000,
-0.717450, -0.380050, -0.828020, 0.242490, 0.677770, -0.973660, -0.070380, -0.839160, 0.125140, 0.793750,
0.495320, 0.494270, -0.439170, -0.280100, -0.884590, 0.124350, -0.319850, 0.245640, -0.195350, 0.373940,
-0.766030, -0.482240, -0.560980, 0.614650, 1.119160, 0.681110, 0.673000, 0.875600, 0.639870, 0.188950,
0.537500, 1.301640, 0.289740, 1.082120, 0.657170, -0.756400, -0.384740, 0.110410, 0.665690, -0.615760,
-0.937230, 0.156050, -0.198110, 0.757010, -0.130930, -0.571520, -1.005540, -0.881770, 0.494270, -0.497670,
0.817160, 0.230710, 0.952940, -0.517720, -0.198230, -0.229530, -1.034240, -0.251030, 0.834030, 1.837970,
0.185630, 0.101670, -4.474900, -1.336390, 0.424120, -1.238470, 1.996840, -0.257980, -0.221440, -0.967560,
-0.768770, -0.829460, -0.911060, 0.373140, -0.796000, 1.232030, 0.177400, -0.563390, -0.585140, -0.797060,
-0.570020, -27.232220, -0.638890, -0.496520, 9.863700, -0.252130, 0.106460, 0.693770, -0.047810, -0.332070,
-22.223631, 0.321290, -0.573400, -0.926000, 0.789940, 0.352910, 0.718460, 0.051960, 0.478710, -0.017710,
-0.113920, -0.496260, 1.029910, -0.837910, 2.900880, -1.432840, 0.798330, -0.891270, 0.755880, -0.099380,
0.630770, 0.408990, -0.807790, 1.355880, 1.266000, -1.362960, -0.056440, 0.736610, -0.893390, -0.821890,
-0.084580, -1.038440, -0.892280, 0.462000, 0.228060, 3.151950, -2.737810, 0.327980, 0.903970,
1.073910, 0.162010, 0.690420, -0.163800, 0.939500, 0.419050, -0.847270, -0.536660, -0.348530, -0.915850,
0.531690, -1.004630, 0.291520, 0.624980, 0.257310, 0.544040, -0.646050, -1.322050, -0.456700, -0.555680,
0.426580, 0.144590, -1.034370, 0.276280, 0.108740, 0.702510, 0.670800, -2.061670, -0.492060, -1.053950,
-0.455290, -1.125830, -0.072530, -1.266020, -0.862990, 0.125120, -0.130080, 0.261770, -0.244900, -0.732600,
-1.010420, -0.690970, -0.816790, -0.134800, -1.029370, 4.001670, -1.060200, -0.751370, 0.717010, -0.358510,
0.284840, -1.773900, 0.860290, -0.484560, 5.492730, 0.112750, -1.249450, -0.185220, 0.648600, 0.800830,
-0.290800, 0.299430, -0.464210, 0.736660, 0.160910, 1.142910, -0.029330, 0.540510, 0.936910, -0.067170,
-0.869560, 0.021240, -0.208080, 0.077190, -0.296930, -0.313570, -0.655730, -0.324330, 0.703450, -0.292030,
0.484880, 0.097710, 0.367310, 0.511480, -0.846910, 0.492890, -0.139510, 0.090170, -0.285880, 0.116250,
-0.277360, 0.864550, 0.450440, 0.898240, 1.002480, 0.504650, 0.615740, -0.444640, -0.307090, 0.531810,
-0.635380, -0.345090, 0.643780, -0.953180, -0.746230, 0.746660, 0.416230, 0.476320, 0.710600, 0.565490,
0.813900, -0.092660, 0.290910, -0.846460, -0.821830, -1.053280, 0.123440, 0.182740, 0.216020, 0.185810,
0.230280, -0.361980, 0.423930, 0.584140, -0.239000, -2.960290, 0.662570, -0.034240, 0.102350,
-0.000390, -0.162910, 1.020540, -0.044760, 0.150890, -0.701900, 0.329850, -0.618510, 1.155140, -0.636380,
0.148640, -0.644280, -0.578570, 0.083330, 0.699210, -0.021890, 0.521610, -0.017930, -0.504980, 0.742130,
0.011620, -0.219280, -0.151640, 1.109430, 0.691530, 0.519050, 0.333990, 0.662960, -0.699870, 0.193130,
0.663130, -0.947120, -0.350490, -0.044150, 0.928540, 0.804020, -0.516680, -0.341690, -0.773060, 0.748620,
-0.356900, 0.680400, -0.817900, -0.622780, -0.482400, -0.149570, 1.145830, -0.912670, -1.082520, 0.361710,
0.577910, 2.503770, -0.360270, -0.977190, -0.313540, -0.398340, 0.438640, 0.471620, -0.074250, -1.413430,
-0.556540, -1.488780, -0.228360, 1.193860, 0.774710, -1.127740, 0.493360, 0.465650, -1.020610, -0.016910,
-0.637660, 0.513340, -0.754840, 0.077080, -0.304950, -0.429360, -0.735750, -0.464590, -0.278190, -1.083860,
-0.241920, -0.751370, -0.586810, 0.466370, -0.675590, 0.081080, -0.533540, -0.864310, -0.389130, 0.420050,
-0.506910, 0.287920, 0.363580, 0.483710, -0.914950, 0.007250, -0.714970, -0.375100, 0.599680, 0.312350,
0.381880, -0.017320, -0.174450, -0.203670, 0.199480, -0.333360, -0.740260, 0.947590, -0.583610, 0.578820,
0.586550, -0.200900, -0.527330, 0.574160, -0.031630, -0.558520, -0.822960, -0.236000, 0.800950, 0.148770,
-0.348500, 0.608380, 0.347710, 1.065110, 0.649740, -0.285590, 0.411770, 0.689040, 0.350970,
-0.021680, 0.422360, 0.591900, 0.604740, -0.000490, -1.105700, -0.799560, -0.329320, 0.478510, -0.294740,
0.325410, 0.435080, 0.707770, -0.761340, 0.639230, -0.108380, 0.335960, 1.050800, -0.841300, 0.138960,
-1.002800, 0.929760, -0.795100, -1.000440, -0.543830, -0.737750, -0.244160, 0.270830, -0.571260, -0.403090,
-0.416250, -0.660330, 0.029180, 1.063200, 0.394240, 0.380790, 0.443550, 0.087650, -0.379300, -0.476170,
0.772780, 0.966650, 0.625380, 0.579360, 1.136960, -0.654570, -0.859950, -0.105640, -0.384950, -0.538140,
0.824970, -0.670720, -0.642940, 0.075720, -0.422220, -0.060590, 1.460350, 2.139510, 0.699890, -0.044070,
0.553810, 0.188280, -0.613250, 1.564400, 0.101930, -2.062660, -0.566610, 0.015340, 0.457690, 0.166010,
0.492110, -0.000220, 0.370430, 0.254280, -0.689160, 0.653630, 0.424400, -0.681790, -0.667870, 0.744920,
0.148640, 0.787730, 0.208760, 1.021260, 0.300690, -0.345180, 1.057950, 0.774670, 0.570680, 0.336930,
0.386550, -0.201280, 0.391980, 0.531180, 0.811830, -0.058470, -0.133830, -0.031620, 0.061090, 0.342210,
0.802280, 0.848580, 0.102340, -0.419140, -0.390110, -0.409760, -1.209160, -0.269430, 0.253100, -0.075040,
0.741960, 1.090860, 0.549190, -0.394030, -0.636870, -0.983120, -0.071800, 0.652250, -0.943830, -0.763860,
0.090420, -0.739600, -0.959420, -0.777350, 0.673950, -1.085530, 0.436700, -0.577490, 0.483390,
-0.656080, 0.466490, -0.187140, 0.190400, 0.528880, -0.862690, 0.968690, 0.268660, 0.405540, 1.046590,
-0.696350, -0.229660, 0.994700, 0.819160, 0.610700, -0.067170, 0.487460, -0.286330, 0.246000, -0.640320,
0.741150, -0.206050, 0.982750, 0.197600, 0.868990, -0.329500, 0.277790, -0.106100, -0.651990, 0.043530,
-0.618610, -0.192890, -0.538480, -0.007040, -0.383650, -0.353190, -0.135790, 0.033060, -0.418400, -0.977930,
0.475600, -0.157590, 1.451980, -1.029050, -0.499970, -0.236960, 0.963660, -0.770260, -1.329770, -0.776490,
0.441270, 0.275340, -0.606780, -0.737220, 0.748200, 0.579660, 0.319850, 0.013340, -0.457690, -0.381740,
0.153670, 0.433020, 0.561280, 0.856880, 0.275100, 0.450110, 0.992450, -1.243430, 0.578800, 0.729730,
-0.219300, 0.149020, 0.500910, -0.608840, -0.361180, -3.319190, 0.269180, -0.907000, 0.835870, 0.976870,
-0.204950, -0.541460, -0.649080, 0.882390, -0.019210, -0.607110, 0.831130, -0.792800, 0.870590, 0.428430,
1.417520, -0.548310, -1.797600, 1.142470, 0.995170, 0.600400, 1.086210, -0.234870, 0.445390, -0.788660,
-0.064130, -0.080330, -0.377280, 0.039330, -0.828430, 0.338630, 0.955880, -1.271100, 0.764670, 0.839870,
0.488330, -0.091840, -0.535380, -0.129330, -0.158240, 0.414080, -0.677090, -0.115770, 0.294770, 0.510010,
0.361260, 0.311070, 0.359580, 0.540930, -0.627510, 3.011350, -1.782130, 0.524350, -0.181890,
0.573440, 0.307560, 0.965020, -0.207790, -0.018130, -0.631500, -0.286820, 0.776960, 0.927520, -0.484330,
0.810380, 0.889080, -0.814510, 0.145630, 0.493740, 0.879690, -1.118830, -0.377430, 0.831290, -0.045790,
-0.687050, -1.119320, 0.188110, 0.270650, 0.114790, 0.361520, 0.067660, -0.898990, 0.168380, 1.419490,
0.833680, -0.450540, -0.155790, 0.631950, -1.039940, -0.605410, 0.482320, -0.502630, -0.893170, 0.718380,
0.307730, -0.791910, -0.029850, 0.908010, -1.220330, -0.618030, -0.222280, 0.245720, -0.525800, -0.010020,
-0.808360, -0.790090, -0.729680, -0.560300, 4.165020, 0.429890, -1.332220, 1.042250, 0.507160, 0.428650,
-0.701190, -0.642200, 0.739910, 1.425060, 0.186620, 0.669330, -0.634300, 0.474460, 0.003210, -0.191090,
0.130880, -0.107010, 0.871050, -0.605920, -0.558480, -0.365270, -0.604310, -0.578240, 0.178090, 0.144690,
0.121350, 0.615930, -0.643720, 0.359080, -0.966620, -0.139890, 0.154090, -0.000010, -0.392110, -0.039180,
0.712420, 0.530640, -0.007360, -0.356050, 0.646640, 0.558030, 0.714100, 0.457920, 0.304340, 0.104160,
0.336740, 0.203000, 0.401940, -0.902050, 0.540390, -0.894700, 0.293980, -0.653670, 0.005620, -0.221300,
-0.723370, 0.675290, 0.649760, -0.859970, 1.611830, -0.705200, 1.276800, 1.845930, 0.243580, -1.546980,
-0.816300, 0.793320, -0.921550, 0.639950, 0.425400, 1.534360, -1.041610, -0.579770, 0.129230,
-0.297760, 0.151250, 0.126600, -0.868180, -0.239910, 0.478010, -0.379010, -0.964080, 0.823260, -0.409060,
-0.767490, 0.269940, -0.915120, 0.733170, 0.898970, -0.612220, -0.318270, 0.849520, -0.442380, 0.969090,
-0.875200, 1.050470, 0.185140, -0.207880, -0.629340, -2.247420, 0.141960, 0.961500, 1.037840, 0.577250,
0.811180, -0.259940, -0.924490, 0.491410, -3.054930, 0.326610, -0.645550, 1.390840, -0.105550, -0.769480,
0.578910, 0.488260, 0.939290, 0.058070, 0.009230, 0.166630, -1.061190, -0.141440, 1.109940, -0.422340,
-0.586700, 0.118840, 0.280600, -0.446920, -0.036630, -1.035930, 0.726950, 0.316540, -0.613750, -0.293800,
-0.661560, 0.820440, 0.462170, 0.539740, -1.195390, 1.273160, 0.436540, -0.214460, -0.871510, -0.961940,
0.225130, -0.524150, -0.359760, -0.451700, 1.333240, 0.239120, -0.050310, 0.747780, 0.664870, 1.001230,
0.001830, 0.187400, 0.233870, 0.643270, 0.140050, -1.049490, -0.238980, -0.411370, 0.125030, 0.448600,
-0.966800, -0.816750, 0.001350, 0.688260, 0.418510, -0.997780, -0.443800, -0.103540, 0.138730, -0.941500,
-0.017710, -0.391840, 0.510210, 0.117140, -0.049850, 0.971260, -1.112460, 0.062050, -0.370570, 0.221990,
0.544330, -0.500820, -0.222230, -0.347280, -0.089250, -0.668920, 0.308110, 0.333150, 0.158590, -0.294490,
-0.473990, 0.700060, -0.299560, 0.320250, 0.241890, -1.260410, 1.477610, -0.144470, -1.055930,
-0.434940, 0.061130, 0.086950, -0.228640, -1.198580, -0.831830, 1.096150, -0.653010, 0.396460, -0.797360,
0.577900, -0.826570, -0.112900, 0.017630, 0.880770, 0.273980, 0.039050, -0.357140, -0.869640, -0.512150,
0.818500, 0.279020, -0.600370, 0.442030, -0.413300, 0.079770, 0.415430, 0.594420, 0.162640, 0.341340,
-0.128530, -0.803300, 0.602740, -1.598370, 0.531240, -1.410380, -0.615530, -0.594610, 0.301250, -0.314960,
0.314110, -0.822390, 0.065110, -0.377040, -4.244300, -3.628990, -0.170040, -1.264690, -1.722400, -0.196250,
-3.057170, -0.186520, 0.279510, -4.811890, 2.028010, 0.358750, -9.115900, 1.693240, 0.262070, -7.944010,
-0.697920, 0.591110, 0.480060, 2.484380, 0.408180, -9.289740, 2.336450, 0.781750, -0.910160, -0.870670,
-0.451770, -1.018850, 0.005380, 0.828720, 4.855610, -0.413790, -0.488660, -0.550360, -0.381800, 0.034410,
-0.547700, -5.132230, -0.720230, 1.789530, 0.998700, 0.155220, -0.848540, -0.607250, -0.342440, 0.509110,
-0.944620, 0.911130, 0.211610, 0.094940, -0.483970, 0.412990, -0.373490, -0.210040, -0.566390, -0.373750,
0.498820, -0.274830, 0.548180, -0.080410, 2.405130, 0.739420, 0.213290, -0.078690, 0.622940, -1.060150,
-0.548890, 0.807290, 0.126370, 0.926780, -0.602110, -0.394550, 2.772110, -0.079090, 0.350680, 0.455140,
0.422240, -0.635230, -0.419320, -0.679050, 0.934360, -21.318399, 5.830840, 0.388760, 0.622770,
0.112620, -0.786990, -0.317710, -0.418690, -0.890990, -0.729740, 0.660070, -0.009180, 0.940730, 0.224630,
-0.591330, -0.214910, -0.604900, 0.605020, 0.915320, 0.552090, 0.385270, -0.238210, -0.541470, 0.836970,
-0.754120, -0.248110, 0.005340, -0.577340, 0.949780, 0.459240, 0.563700, -0.149120, 0.775920, 0.518280,
-0.027430, -0.001010, 0.468640, 0.208900, -0.280240, 0.432600, -0.224190, -0.383110, 0.928410, 1.582710,
0.582230, -0.366010, -0.034420, 0.199620, -0.769650, 0.615420, -1.346340, 0.477460, 0.246400, -1.401820,
-0.079230, -0.790350, 1.674330, -0.350490, 1.633030, -0.339850, 0.095860, -0.449730, -0.813580, -0.273030,
-0.135060, 1.975330, 0.890970, 0.675410, -1.949470, -0.714110, 0.268840, -0.487900, -0.870990, 0.229320,
3.086660, 0.594300, 0.344480, -1.732050, -0.557960, 0.515730, -0.804000, 0.879780, -0.320700, 2.524110,
-0.576990, -0.318250, -0.930430, 0.500520, 0.818870, -0.768480, -0.198740, -0.168100, 1.447300, 0.113520,
-0.331110, -0.213970, 0.524220, 0.625170, -0.420460, 0.524870, 0.859990, -0.297610, -0.813590, 0.519120,
0.849750, -0.984690, -0.665910, -0.520970, -0.279890, 0.072300, -0.279580, -1.349750, 0.654950, 0.303490,
-0.108160, 0.378510, -0.004010, 0.058090, -0.254290, 0.161650, 0.483530, -4.472230, -0.978630, -2.457370,
-0.238910, -0.770790, -0.549820, -0.589860, 0.492300, 2.479700, 0.246650, -0.490800, -0.405980,
-0.057170, -0.555560, -0.664490, -0.714730, 0.286210, 0.555710, -0.249120, -0.377200, -0.395760, 0.845400,
0.164110, -0.086830, 0.503870, -0.589470, 0.421470, 0.901360, 0.145270, -0.820720, -0.687620, -0.238240,
-0.404190, 0.583370, -0.644740, -0.113290, -0.741940, 0.499410, 0.153120, -1.674490, -0.383050, -1.174840,
0.423660, -1.040140, -0.593580, -0.100580, -4.811270, 0.344480, -0.078990, -0.035080, -0.409160, 1.104000,
-0.066180, 0.385240, 0.975440, -0.811880, 0.427770, 0.199550, -1.000650, 1.386610, -0.005880, 0.524480,
0.411630, 0.150710, -0.526310, 0.393720, 1.160530, -1.717610, 1.472600, -0.549990, -0.927440, -0.507900,
-0.266300, 0.760650, -0.859850, -0.501990, 0.008530, -0.898800, 0.803680, -0.795540, -0.681090, -0.674640,
0.200720, 0.437910, 0.901680, -0.716380, 0.330870, -0.305270, 0.494410, -0.279480, -1.279720, -1.243580,
-0.302500, -0.032400, -0.657480, -0.506570, -0.779320, 0.012170, -0.317190, 0.629300, -0.355630, -0.199070,
-0.282710, -0.838640, -1.106660, 0.280920, -0.078510, 0.707940, -0.488730, 0.354750, -0.445360, 0.506490,
0.752250, 0.447570, 0.952360, -0.280120, 0.526070, 0.763060, 0.520440, 2.757650, -1.052380, -0.289490,
0.848760, -0.816830, -0.657570, -0.488340, 3.768940, 0.534140, 0.292320, 0.306540, -0.074670, 1.923190,
0.971630, -0.313490, 0.617620, 0.155380, -0.306780, -3.431180, 0.062340, -0.267350, -0.491610,
0.040450, -0.561390, 0.144340, -0.978780, 0.196900, 0.932330, 0.411430, 0.762440, -0.289520, -0.327500,
-0.203600, 0.377220, 0.809040, 0.547430, -0.340990, -0.849170, 0.236310, -0.651000, 0.526390, 0.398980,
0.290480, 0.496610, -0.768230, -0.867450, -0.030540, 0.718210, -0.657890, -0.659640, -0.949540, -0.159640,
0.969850, -0.744630, 0.071650, -0.084700, 0.326440, 0.363050, -0.207930, -0.252490, 0.784380, 0.587050,
0.771950, -0.535940, -0.010330, 1.095430, 0.895290, -0.023810, 0.003750, -0.795940, -0.572170, 0.300270,
0.452610, 0.398730, -0.276730, 0.008290, 0.208040, 0.443770, 0.372150, -0.091140, 0.737140, -0.499490,
-0.326600, -3.132580, -0.450370, -0.871670, 0.865290, -0.711250, -1.159170, -1.739210, -0.624960, 1.019190,
-0.722370, 0.404500, -0.127060, -0.403330, 0.488000, 1.144150, 1.096890, -0.258170, 0.148240, 0.502260,
0.479640, -0.015010, 0.730610, -0.079390, 0.038500, 1.017280, 0.267650, -0.363690, -0.175540, 0.164470,
-0.289210, -0.793720, -0.227230, 0.007290, -0.072690, 0.728430, -1.923380, 0.936390, 0.514470, 0.512450,
-1.356160, 0.472940, -0.867140, -0.836530, 0.069670, -0.708150, 0.774920, 2.438310, 0.100710, -1.240350,
-0.561300, 0.264550, 0.852820, 0.651590, 1.476440, -1.472230, 0.459250, -0.803180, -0.073200, -0.536790,
-0.270040, -0.948770, 0.039370, 0.706700, 0.714970, -0.228220, -8.347790, 0.079210, 0.921370,
0.142850, 0.868180, 0.214070, -0.832300, -0.774180, 1.137450, -0.791630, 0.303890, -0.233850, 0.217380,
-0.630280, -0.509970, 0.532780, -0.179560, 0.006210, 0.099610, 0.497810, 0.735120, 0.722660, 0.686320,
0.987430, -0.691720, -0.691950, 0.811350, 0.330320, -0.193510, 0.073850, 1.056710, 0.857140, -0.625450,
0.050640, -0.052550, -0.208360, -0.918480, -0.507570, 0.110010, 0.969650, 1.035320, 0.639390, -0.193310,
0.796700, -0.168910, -0.136990, -0.526820, 0.706540, 0.882600, -0.342120, -0.076770, 0.775530, 0.058640,
-0.797430, -0.599730, -0.026010, 1.332520, 0.556610, -1.093390, 1.128470, -0.316080, -0.144700, -0.736450,
-0.306680, 0.135930, 0.681360, -0.294250, -0.192880, 0.971930, -0.346280, 0.031980, 0.668850, -0.204410,
-0.027730, -0.065590, 0.086220, -0.874100, -0.594250, -0.255140, -0.063880, 0.335350, -0.487420, -0.145400,
0.190130, -1.058650, 0.032140, -0.174430, -0.078430, 1.190110, -0.124890, 0.700590, 0.384520, -0.022010,
-0.688900, 0.117000, -0.312640, 0.372960, 0.306060, 0.329180, -1.027700, 0.155310, 0.531230, -0.904060,
-0.212680, 0.130710, -0.089980, 0.142520, 0.051340, 0.246390, 0.642660, 0.349180, -0.453210, 0.207430,
0.755890, -0.518120, 0.095830, -0.922670, 1.756630, -1.123740, -0.170000, -0.386730, -0.008850, 0.114420,
-0.187710, 0.642520, 0.991950, -0.740260, 0.921620, -1.015390, -0.100360, 0.779540, 0.199200,
0.703750, -0.252220, 0.698970, 0.423340, 0.773890, -0.625710, -0.481010, 0.717130, -0.112810, -0.685700,
-0.660610, -0.245240, 0.843280, -0.010500, 1.010070, -1.198920, 0.585430, 0.400990, 0.585120, 0.472780,
0.572550, 0.142560, 0.582470, -0.061100, -1.266190, 0.194210, -0.473270, 0.097030, 0.410520, -0.163490,
-1.030450, 0.871970, 0.963030, -2.111920, -0.174180, 0.672660, -2.728430, -0.001100, 0.278470, -1.203020,
1.063140, 0.005410, -2.296110, 0.893570, 0.505210, -3.316600, -0.148630, -0.739990, -1.983190, -0.113770,
0.477980, -1.953740, -0.307990, -1.361900, -9.852270, -0.679290, 0.769790, -2.279960, -0.472260, -1.023680,
1.257910, 0.155180, -0.411920, -10.484540, -0.031420, 0.884180, 0.589900, 0.193640, 0.681900, 0.502890,
-1.118010, -0.107480, -1.770550, -0.728290, -0.084550, -0.116230, 0.037030, 0.212280, 1.318780, -0.032070,
0.628690, -0.300260, 0.322420, 0.230220, -0.853780, -0.081090, -0.026270, 2.208830, -0.079870, -0.021620,
-1.536160, -0.957810, -0.147210, 0.520790, -0.350190, 0.558790, -0.579120, 0.564280, 0.355800, 0.063220,
-0.362410, -0.246230, 0.756610, -1.047050, -0.368900, -0.121340, -0.472880, 1.688000, 0.739400, -1.136580,
-0.538800, -0.623610, 0.623610, -0.647950, -0.035790, 0.912490, 0.054340, -0.021190, 0.248150, -0.582140,
0.689900, -0.413330, 0.569870, 1.021040, -0.263090, 17.020540, -0.168430, -0.630240, 0.490980,
0.537240, -0.401680, -0.595030, -0.795350, 0.793320, 0.114410, -0.014010, 0.179120, 0.309130, 0.821900,
-0.781000, -0.397020, 0.687470, -0.746760, 0.228360, -0.291810, 1.210160, -0.628110, -0.735440, -0.648310,
0.055940, 0.566100, 0.229390, 0.306010, -0.392800, -0.691470, -0.007870, -0.349720, -1.530060, -0.855780,
0.451460, -0.048610, 0.757200, -0.386130, 0.669980, 0.613180, -0.036900, 1.016960, -0.272500, -0.400450,
0.694710, 0.238840, -0.192930, -0.464800, -0.146570, -1.374300, 0.529590, -0.839360, -0.825140, -0.482360,
0.605440, 1.583610, -2.284070, 0.222500, -2.095030, 0.476390, 0.761560, -0.372270, -0.800800, 0.256950,
0.200550, -1.449470, 0.549510, -1.454950, -0.007960, 1.014890, 0.650770, -0.796230, -0.276310, 0.524150,
-0.494150, -0.958560, -0.771920, 0.004370, 0.655820, 0.058050, 0.538510, 0.782310, 0.742590, 0.368380,
0.144000, 0.216340, -0.142280, 0.805400, -0.934020, 0.877590, -0.499560, 0.636240, -0.983410, -0.453770,
-0.254080, 0.534160, -0.999020, 0.210910, -0.619510, -0.461590, 0.137200, 0.028390, -0.578930, -0.546850,
-0.046850, 0.845760, -0.973200, 0.358070, -0.561500, 0.076450, 0.159710, 0.922990, -0.236320, -0.108710,
0.669380, -0.000010, -1.089470, 0.330700, -0.053790, 1.124210, -0.588430, 0.432820, 0.587560, 0.816990,
-0.537160, -0.547610, 0.830450, -0.274010, -1.008260, -0.709500, 0.830930, 0.366580, 0.649990,
0.699820, -0.234140, -0.710060, 0.597230, 0.416080, 0.519120, 0.848570, 0.272210, -0.969820, -0.107460,
-0.502740, -0.333500, 0.068680, 0.491890, 0.303050, -0.426330, -0.861530, -0.237660, -0.179580, -0.434600,
0.041700, 0.783240, 0.653280, 0.071460, -0.454030, -1.102220, -0.630350, -0.496050, 1.571620, 0.210830,
-0.799270, -1.034770, -0.995400, -0.232630, -2.267860, 0.122960, -0.354260, 0.721520, 0.369120, 0.103470,
-0.611390, 0.474050, 0.880030, -0.312470, -0.370240, 0.302160, 0.452240, -0.315440, -0.589400, -0.204280,
-0.359550, -1.625530, -0.845490, 0.410190, 1.075440, -0.698340, -0.482720, -0.360290, -0.715150, 0.495380,
-0.553270, 0.467810, -0.247150, 0.016120, 0.543030, 0.340530, 0.646880, -0.908770, 0.560120, 0.670130,
-0.422530, 0.569770, -0.043740, 0.437890, -0.406700, -0.158030, 0.538930, -0.433010, 0.775200, 0.817650,
-0.453950, 0.956100, -0.196180, 0.239260, 0.474090, -1.049100, 0.303260, -0.511560, 0.498310, -1.048180,
-0.264890, -0.799480, -0.403180, 0.659210, -0.676620, 0.724980, 1.813340, -0.075490, 0.525120, -0.868360,
-0.164740, -0.312080, -0.744730, 0.938840, -0.844850, 1.412310, -0.683470, -36.655331, 0.917400, -0.528810,
0.232960, 0.310050, -0.416980, 0.537720, 4.868820, 0.933040, 0.290380, -0.408870, -0.885360, 0.453980,
0.196010, -0.613300, 0.561980, 0.571700, 0.302020, -0.081400, -0.007010, 0.176430, 0.267720,
-0.451190, 0.667790, 0.086080, -0.135880, -0.681790, 0.386960, -0.045740, -0.483710, -0.707620, 0.106500,
-0.188090, -0.930580, -0.448880, -0.579220, 0.210900, -0.047600, -0.435230, 0.645230, 0.260610, 0.232460,
-0.132290, 0.237600, 0.153320, 0.011410, -0.718360, -0.153770, -0.740230, 0.710080, 0.477460, -0.234890,
0.108770, -0.641210, 0.126520, -0.770370, 0.050630, 0.850510, 0.322630, -0.986470, -0.777730, -0.159410,
0.416750, 0.385290, -0.950230, 0.126700, -0.147310, -0.272540, -0.073780, 1.426690, 0.644850, -0.155010,
1.131950, -0.022160, -0.801350, 0.881480, -0.885480, 0.424110, 0.258130, 0.292970, -1.028860, 1.066530,
1.355900, 0.119080, 0.982700, -0.926710, 0.649850, 1.428290, 0.759150, -0.672650, 0.379490, 0.039720,
0.310570, 0.159600, -0.901230, -0.041330, 0.058150, 0.448110, 0.845460, -0.812890, 0.598780, -0.814710,
-0.421510, -0.325930, 0.141840, 0.557090, 0.093110, 0.301160, 0.670640, -0.382630, -0.087010, -0.303090,
-0.139150, 0.689150, 0.298060, -0.116290, -0.593890, -0.733450, -0.601180, 0.031260, 0.404800, 0.101780,
0.051890, 0.034510, -0.070210, -0.449460, -0.313000, 0.082010, -0.951850, -0.938650, -0.059250, 0.633210,
0.409620, 0.464780, -0.038470, 0.422470, -0.637150, -0.315540, 0.247810, 0.046570, -0.880130, -0.841180,
-0.796830, -0.484280, -1.428930, 0.448700, -0.475570, -1.783460, 1.387310, -0.123420, 0.660000,
1.255970, 0.814630, -0.022930, -0.023410, 0.503890, -0.190660, 0.050990, -0.235540, 0.306480, 0.110090,
-0.563890, 0.761910, -0.259020, 0.955810, -0.860120, -0.670020, -0.084920, 0.380820, 0.677730, -0.576710,
0.327440, -0.017200, -0.046350, 0.943060, -0.157050, -0.516620, 0.014410, 0.200690, -0.559010, 0.033440,
0.783930, -0.709130, 0.249920, -1.116980, -0.572900, 0.117490, -0.159530, 0.310770, -0.473210, -0.373890,
0.981290, -0.216640, 0.485710, -3.051910, 1.987900, -0.406400, 0.303210, 3.673500, -1.104180, -1.534200,
-7.547050, -0.497700, -1.540890, 2.436240, -1.335490, 0.448070, 2.349030, -0.593190, -1.201310, -8.309640,
-0.989100, -4.211620, 0.841660, -1.506660, 0.643340, 10.364660, -0.008500, 0.362300, -4.507780, 0.071830,
-4.912030, -1.732680, 0.128950, 3.855750, 10.389640, 0.076690, -2.588560, 0.212690, 1.145900, -3.046230,
0.071690, -1.495630, 2.830220, 14.017250, -0.080150, 2.117960, 0.681930, 0.215170, -4.947670, 0.324030,
0.357720, 4.798680, -0.229270, 0.066500, 4.082180, 1.603330, -0.596830, -1.810640, 0.103800, -0.448990,
0.719300, 1.553650, -1.466890, 1.148830, -0.286930, -0.629070, 0.681410, 6.611910, -0.366880, -0.346320,
1.046160, 0.742220, 0.033630, -1.287430, -1.009620, -0.455220, 0.364670, -2.476010, 0.248170, 6.200890,
-0.230140, 1.111380, 0.019440, 0.082000, -0.237060, -3.029160, 4.118230, 0.405180, 0.023600,
0.433230, -0.061500, -0.301650, 0.512300, 0.396550, 0.124520, 0.806650, 0.216840, 0.147660, 0.356100,
-0.972280, 0.246240, -0.112630, 0.320040, -0.208790, -1.064300, 0.461820, 0.306790, -0.591960, 0.535410,
0.423500, 0.185620, 0.230670, -0.538370, 0.298090, -0.034340, -0.987890, 0.157520, -0.468110, -0.404940,
-0.012230, -0.716300, -0.514590, -0.207810, -0.256940, -0.339870, -0.089410, -0.840470, -0.930570, 0.963380,
0.459590, -1.038470, -0.390300, 1.272590, -0.072570, 2.761680, 0.893930, 0.217800, -0.385170, 0.912390,
-0.342140, -1.013940, -1.666180, 0.750890, -0.407100, 1.096820, 0.187740, 0.159090, -0.607360, -1.025100,
-0.399370, 0.219530, -0.025870, 0.347310, 0.196630, -0.298090, 0.574100, 0.119460, -1.058730, -0.753610,
-1.133150, 0.814610, 0.625890, -0.831910, 0.068610, -0.104990, -0.826040, -0.992590, 0.070740, -0.648900,
0.179610, 0.087750, 0.779880, 0.396140, -0.714850, 0.444910, -1.072140, 0.612490, 0.426780, 0.728860,
-0.197800, 0.297060, 0.484160, 0.134400, -0.156420, -0.610360, -0.501180, -0.069480, -0.760910, -0.253960,
-0.192880, -0.748930, -0.112380, -0.091810, -0.015210, 0.857500, -0.540830, 0.370930, -0.495680, 0.668170,
-0.416080, 0.878650, -0.508820, 0.583950, 3.127770, -0.797490, -0.028100, -0.322990, 0.639440, -0.472710,
-0.860990, -0.995000, 0.888610, 0.776390, 0.668060, 2.370630, -0.802510, -0.045630, -0.044700,
0.194950, 2.116920, 0.248720, -0.835900, 0.100100, 0.676650, 0.518470, 0.507830, -0.115960, -0.344660,
-0.333120, -0.314970, 0.950600, 0.652450, -0.552340, -0.757230, -0.762260, -0.099720, 0.640560, -0.348140,
1.927640, 0.500650, 0.047990, -0.848790, -0.254750, -1.244010, -0.803100, 0.546560, -0.061130, 1.121780,
1.157940, 1.939740, 0.513270, 1.711800, -1.295430, 1.756980, 0.496150, 0.812310, 0.802560, -0.084590,
1.002960, -1.274410, 0.185860, -0.850830, 0.558740, 0.665150, -8.954310, -13.988910, -0.161060, -0.664490,
4.888560, 0.901770, -0.185080, -1.339280, -0.106080, -12.536050, -29.663620, -0.240860, -0.857110, -1.226620,
0.188980, -0.964420, 0.205900, 0.565890, -0.415190, -0.833980, 1.118740, -0.692990, -0.539340, -0.803360,
-0.674680, -0.269120, 0.751570, -1.180950, 0.482020, -0.944930, -0.612060, -0.612050, 0.051860, 0.516480,
0.127240, 0.037990, -4.982250, 1.076930, -0.881870, -2.687840, -0.736310, 0.216250, 4.011660, -0.303700,
-0.290120, -1.997790, 0.155290, 0.153640, -0.557560, 0.820950, -1.250530, 1.138310, 0.193650, 1.588490,
-1.896080, 0.809510, -0.089060, -0.848370, -0.059200, -0.428840, 0.485560, -1.862290, 0.625520, -0.379910,
-1.049540, -1.071270, 0.753530, -0.858390, 0.444210, 0.090060, -1.169920, 0.050290, 0.116170, 7.636160,
1.835440, -0.904510, -0.285020, -0.270910, 0.122020, -1.045480, 1.201530, 0.918280, -0.669250,
-0.929040, 0.610600, 0.703110, 0.242090, 0.412780, -0.077420, -0.367970, -1.079670, 0.584810, 0.881330,
1.224770, -0.658310, -0.022030, 0.007710, 0.107710, 0.355780, -1.954520, 0.005640, 0.444950, -0.092210,
0.795590, -0.784780, -0.654100, 0.533640, -0.101500, -8.612080, 0.179420, -0.954240, 1.953420, -0.931050,
0.375500, -1.334410, -0.939840, -0.301350, -8.246770, -0.410340, 0.607300, -3.017670, -0.973170, 0.578590,
1.108080, 0.439860, -0.546880, -2.170320, -0.940130, -0.727750, -1.917210, 0.819460, 0.443750, 0.524190,
-0.450340, 0.906520, -4.685200, 1.666060, -0.045650, -0.743630, 0.407430, 1.008520, -1.013550, 1.064930,
-0.660690, -0.360890, -0.136580, 0.528490, 1.171220, 1.591320, -0.846520, -0.778020, 0.963950, 0.726240,
1.406590, 0.679810, -0.163430, -1.012920, -0.039840, -0.230070, -0.866730, -0.140970, -0.937230, 0.070810,
-0.541910, 0.463880, 0.909870, 0.128620, 0.032630, 0.371160, -0.203380, 0.043610, 0.081570, 0.527100,
-0.630270, 0.311140, 0.873420, 0.029320, 0.233810, -0.570930, -0.581320, -0.467160, -0.397580, -0.033760,
-0.384880, -0.326000, 0.526200, -0.597360, 0.645640, 0.377310, -0.379690, 2.368270, 0.479230, -0.811250,
0.691810, -0.587100, 0.620020, -0.812470, 0.024460, 0.327520, 0.558450, -1.309900, -0.389980, -3.318850,
-0.887690, 0.552620, -0.545950, -0.644270, -0.680080, 1.384470, -0.514370, -0.895320, -0.187060,
-0.758540, 0.528500, -0.554370, 0.572800, 0.235690, 0.464850, -1.096140, -0.372850, -0.452700, 0.755580,
-0.006320, 0.898660, 0.092000, -0.663360, 0.426250, 0.796950, 0.845060, 0.823680, -0.721700, 0.456540,
0.988820, 0.829490, -0.149050, 0.203190, 0.119070, -0.274460, 0.231680, 0.780680, 0.053580, -0.681480,
0.057470, -0.262620, -0.218110, 0.666280, 0.822120, 0.340660, -0.720960, 0.100010, -1.064150, -0.270000,
1.166830, 0.010520, -0.271200, 0.700330, -0.664960, 0.597470, 0.322040, -0.212650, 0.224900, 0.680680,
-0.731380, 0.305040, 0.092270, -0.772920, -0.855430, -0.170560, -2.226740, -0.055810, 0.421060, 0.685200,
-0.415670, 0.232150, -0.106120, 0.966430, 1.239700, -1.248960, -0.361440, -0.571280, -0.755090, -1.381950,
-0.721390, 0.207810, 1.057210, -0.169510, 0.996720, -0.478380, 0.925870, -0.420340, 0.356840, -0.315940,
0.334200, 0.650020, -0.506790, 0.420580, -0.274990, 0.294340, -0.946870, 1.293970, -0.156090, -0.193830,
0.448050, 0.127020, 0.381190, -0.631050, 0.658420, 0.374590, -0.653080, 0.155650, -0.393540, -0.050490,
-0.090570, -0.756460, -0.446910, 0.594450, 1.373560, 0.305010, -0.204460, 1.060940, -0.358060, -0.071840,
0.918510, 0.173760, -0.825250, 0.018520, 0.068930, -0.462800, -0.299620, 1.159640, 0.542510, -0.109280,
-0.276510, 1.146140, 0.765470, -0.698590, -0.920970, 0.122990, -0.219550, -0.147950, -0.900250,
0.014520, 0.412570, -1.062490, -1.911760, 0.490890, 0.780890, 0.528250, -0.647550, 0.258350, -0.258690,
-0.237050, 0.583760, -0.838520, -0.516790, 0.848060, -0.237660, 0.069780, -0.923400, -0.930850, -0.341530,
0.550690, -0.496600, -0.132330, -1.120360, -0.074650, -0.330600, 0.659480, -1.148940, 0.382510, -0.289590,
2.838600, -0.451430, 0.254000, -0.204190, 0.859150, 0.656660, 0.485410, 0.489490, -0.522510, 0.636890,
0.240880, 0.351490, -0.626430, -0.028570, -1.084260, 0.566160, 0.946450, -0.513460, -0.309280, 1.434840,
-0.664680, 0.540780, 0.886810, -2.317720, -1.959690, 1.261720, -3.172190, 1.422870, 0.898930, -0.189920,
2.186830, 0.247300, 0.075050, -1.089580, -0.200550, -3.518130, -0.140140, -0.832770, -0.549260, 1.181430,
0.632920, 0.204890, 0.197400, 0.807970, -0.291890, -0.478880, -0.208970, -0.365020, 0.650960, -1.161360,
-0.071850, -1.197340, 0.819230, 0.449190, -0.243010, -0.615600, -0.902000, 0.126700, 0.644640, -0.195420,
-1.281600, 0.445880, -0.643420, -1.588930, -0.535380, -0.120580, -2.052870, -0.788270, 0.000660, 0.666250,
-1.052920, -0.540960, 0.377120, 0.375160, -1.581990, -0.248260, -0.123860, 2.788620, -0.540320, 0.712350,
0.461380, -0.468430, -0.943420, -0.978350, 2.725750, 4.035670, -0.318890, 0.517480, 0.122760, -0.073990,
-0.752980, -0.004960, -0.502020, 0.560920, -0.743240, 1.546290, -0.813600, -0.477770, 0.739320,
-1.003880, -0.616780, 0.671980, 0.896870, -0.196200, 0.798890, 0.233240, -0.218870, -1.592610, 0.157640,
-0.246180, -0.812540, 0.407060, 0.296180, 0.164140, -0.487090, 0.900250, -0.601570, -0.681230, -0.429150,
-2.899770, -0.891500, -0.536610, 0.419750, -0.725380, 0.993390, 1.932270, 0.604410, -0.648300, -0.295320,

-0.566510, 0.478230, -0.487050, -0.685730, 0.459270, -0.460730, -0.552340, 0.373120, 0.420080, -0.785590,
-0.099500, -0.202350, 0.911890, 0.374460, -0.343060, 0.421650, -1.552730, -1.357050, 0.671540, -0.144080,
0.404750, 0.872750, -0.549050, -0.832600, 0.168290, 0.362590, -2.232480, -3.526720, -0.234230, 0.520150,

0.680450, -0.033720, -0.282770, 0.543480, 0.442580, -0.632360, 0.124820, -0.657870, 0.771130, -0.036660,
-0.226320, -0.578300, 0.158370, -0.925280, 0.608130, -0.290840, -0.817760, 1.091860, -0.709990, -0.734140,
-0.012440, -0.467450, -0.079360, 0.875860, 0.848170, -1.196060, -0.923390, -0.298790, -0.043350, 0.006230,

-0.612120, -0.277480, -0.363250, 0.264560, 0.459240, -1.072490, 0.373380, -0.880120, -2.357110, 0.183430,
-0.919190, 0.318150, 0.344090, 0.357780, 0.739190, 0.547230, 0.935800, -0.290190, -0.137840, 0.687290,
-2.813340, -0.952710, 0.767380, -0.898260, -1.179980, -0.769500, 1.966270, 0.453720, -0.271670, -0.593640,

0.205130, -0.276490, 0.954250, -0.442330, -0.272860, -0.734390, -0.126890, 0.698590, 0.299850, 0.272350,
0.671860, -1.019490, -0.878300, 0.243360, -0.668230, 1.126850, -1.856210, -1.122610, 0.383770, -0.593330,
0.227950, 0.406310, -0.021610, 0.099490, 0.689580, 0.570740, -1.814120, -2.750430, 0.596220, 0.712320,

0.080820, 0.402780, -0.471340, 0.742650, -0.475180, 0.680750, -0.635330, -0.011100, 0.624290, -0.834080,
0.008810, 1.059400, 0.342450, -0.221920, 0.264950, -1.413640, -0.748450, 0.698670, -0.640850, 0.665030,
0.196540, 0.538560, -0.591010, -0.288730, 0.683220, -0.533070, -1.020280, -0.071640, -0.933000, -0.449080,

0.176740, -0.916030, -0.409460, -0.690820, 1.033060, 0.298490, 0.563410, -1.053940, -2.444190, -0.880830,
0.335810, 0.970800, 0.606490, 0.934320, 0.567420, -0.178290, 0.544350, 0.682130, -0.971090, -0.155340,
-2.530290, -0.476310, 0.398540, -1.218020, -1.655680, -0.097420, 1.351880, -0.249970, -0.074760, -0.182430,

0.472550, -0.482700, 0.335470, -0.089790, -0.607140, -1.762300, 0.160090, 1.128710, 1.005610, -0.185110,
0.037650, 0.558490, -0.899870, -0.287680, -0.272320, 1.222620, -1.516770, -0.501130, 0.309920, 0.480090,
0.549810, -0.534150, -0.217130, 0.040060, -0.024570, -0.013580, -2.244040, -1.621680, 0.388700, 0.746210,

0.475450, 0.742560, 0.783780, -0.507870, 0.025650, 0.337670, -0.575460, -0.170050, -0.101660, -0.063830,
-0.628660, -0.635620, 0.084530, 0.094490, 0.742200, -1.490830, -0.492820, -0.216100, -0.389040, 0.131900,
0.148970, 0.634580, 0.159640, 0.702600, 0.482330, 0.262450, -1.136330, 0.328890, -0.933420, -0.376910,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.697050, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.296180, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.008080, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.077380, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.520560, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.176100, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.817690, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.463720, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.212060, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.809460, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.961540, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.273640, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.501840, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.054770, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.423180, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.063030, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.412350, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.635160, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.338140, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.822540, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.315600, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.010780, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, 0.117070, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.339830, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.735170, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.597380, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, -0.042180, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.854120, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.308030, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.440170, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.282720, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.763420, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.277220, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.538870, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -1.044040, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.785160, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.243010, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.553290, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.873620, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.00604, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.00018, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
0.29262, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42463, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
1.22716, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.95326, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.42764, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.42390, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.32540, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
0.75307, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.40756, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.42785, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.41797, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
1.05020, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
1.42477, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.11419, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.20293, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.00000, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.00694, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.42772, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.03174, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.28536, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
1.35775, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
0.70837, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
0.83720, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.32135, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.00711, 0.500000, 2,
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
