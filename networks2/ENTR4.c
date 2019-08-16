/*********************************************************
  TMPENTROP4_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:19:00 2004
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
-0.605250, 0.703280, 0.431640, -0.725800, 0.719320, -0.149060, -0.996450, -0.563630, 0.615280, 0.153990,
0.241840, 0.050060, 0.609100, -0.471950, -0.464830, -0.713770, -0.375600, 0.607420, -0.290880, -0.161230,
1.090050, -0.728790, 0.458950, -0.788270, 0.184030, -1.002850, 0.748690, -0.142280, -0.361900, 0.444730,
0.173530, -0.185650, -0.532110, 0.078200, -0.605180, 1.463700, -0.783240, -0.568760, 0.015260, 0.427390,
-0.673540, -0.802590, -0.753310, -0.459630, -0.709330, -1.583630, 0.506280, 4.135050, 0.076350, 0.013570,
0.485750, 1.574270, -0.731960, -0.229640, -0.029710, 0.641850, -0.118200, 0.183310, 0.506840, 0.012660,
0.113680, 0.640330, -0.776800, 0.437490, -0.512450, 0.828470, -0.700710, 0.415720, 0.480430, 1.086860,
0.359200, 0.774270, -0.839180, -0.689400, 0.303040, -0.157500, -0.431060, -0.737130, -0.372400, -1.185520,
-0.429180, -0.833640, 0.118220, -0.329040, -0.902740, -0.832620, -0.739260, 0.008010, -0.880020, -0.803170,
0.595790, 0.185470, 0.942790, -0.614380, 0.921170, -0.206220, 0.530110, -0.057170, 0.342430, -1.083480,
0.556600, 0.561660, 0.040850, 0.209070, 0.230320, -0.034770, 0.545260, -0.739280, 0.164980, 1.811170,
0.915820, 0.985520, 0.657470, 0.196090, 0.788110, -2.925750, -0.150440, -0.737610, 0.118550, -0.626290,
-0.441730, -0.932880, 0.457840, 0.678420, 0.298120, 0.902820, -0.775170, -1.524870, -0.465010,
0.208160, 0.317240, 0.737330, -0.874720, 0.316540, 0.367600, -0.798770, -0.230470, -0.471990, 0.456650,
0.140610, -0.288060, -0.692150, -0.192680, 0.071980, 0.439870, 0.310500, 1.121240, -0.550160, -0.389710,
0.030940, 0.642040, 0.059150, -0.644370, -0.036900, -0.768330, -0.443350, 0.145200, 0.252600, -0.206620,
-0.596570, -0.310580, 0.603480, -0.736380, -0.000530, 1.306130, -0.084490, 0.404110, 0.125270, -0.158410,
-0.412230, -0.266960, 0.366900, -0.699320, 1.831850, 0.424710, 0.610360, -0.321260, -0.187920, 0.261950,
-0.122880, -1.205620, -0.419520, 4.734300, 0.502140, -0.726070, 2.809220, -0.994200, -0.451120, 0.589600,
0.389970, 0.328520, 1.146080, -0.846780, -0.902440, 1.452990, 0.254300, -0.804250, 0.536140, 0.374090,
0.611770, -0.156550, 0.732270, -0.021910, 0.477720, -0.980920, -0.238030, -0.606600, 0.814580, -0.390660,
0.857930, -0.761240, -0.422250, -0.788430, 0.850520, 0.014830, 0.626900, 1.140730, -0.274160, 0.914080,
-0.557000, 0.968010, 0.274650, 0.153490, 0.632400, 0.784220, 0.839500, -0.651640, -0.968920, 0.089130,
1.346440, -0.457660, -0.146040, -0.162610, 0.289520, 0.136270, -0.716540, -0.672520, -0.736470, -3.369290,
0.281980, 0.614010, 0.137330, -1.037530, 0.060420, -2.083030, 0.604430, 0.484040, 0.253060, -1.073050,
0.597480, 0.858160, -0.999520, 0.563770, -0.432110, 0.802530, 0.236730, -3.530730, -0.525630,
-0.498520, 0.245700, 0.292150, 0.982230, -0.073710, -0.029680, 0.279470, -0.774570, -0.532070, -0.851810,
0.598690, -1.273490, -0.189140, 0.283990, 0.544150, -0.978940, -0.047260, -0.589500, -0.332460, -0.837070,
-0.472380, 0.371270, 1.056280, -0.688710, -0.280450, 0.546550, -0.970020, 0.399210, -0.379600, -0.391570,
-0.553340, -1.721310, 0.452520, 0.042380, 0.996560, -0.780650, -0.614210, -4.817650, -0.406660, -3.513470,
0.146330, -0.915220, -0.116030, 3.391690, -0.080440, 5.022180, 0.785710, -0.120660, -0.455220, 0.544770,
-0.553610, 0.623430, 0.212980, 3.019340, -0.458230, 4.618250, -0.213420, 0.862320, -0.610830, 0.407890,
-0.399870, 0.433160, -1.331510, 0.307330, 0.658430, 8.931640, 0.633410, -0.512800, 0.064350, 0.151340,
0.509620, -2.868040, 0.222640, -0.812560, 1.661210, -0.666620, 0.384730, 0.974160, -0.337260, 0.517300,
0.746750, 0.600870, -0.338290, 5.268660, 0.090100, -0.501520, 0.957160, 0.121370, -0.484420, -3.354550,
-0.815810, 0.448760, 2.473700, 0.811350, 0.960830, 1.092240, -0.272790, 2.106850, 1.736410, 0.805050,
-0.133450, 0.041390, 0.607190, -0.326690, -1.656020, -0.433190, 0.539880, 0.508700, 0.223860, -0.593690,
-0.725440, 0.132210, -0.538130, 1.361030, 0.421740, 0.383450, 0.852200, 0.576490, 0.617960, -0.445610,
-1.760390, 0.569990, -0.937620, -0.143070, -0.196620, -0.926960, -0.578440, 0.682570, 0.031080,
0.837830, -0.758080, -1.121260, 0.035090, 0.746050, 0.805830, -0.492570, 0.005110, -0.474420, 0.309450,
-0.051680, -0.322580, -0.097290, -0.044100, -0.564580, -0.590790, -0.214990, -0.542930, -0.394250, 1.031080,
-0.889320, -0.581600, -0.105470, 0.329470, 0.721980, -0.099440, -0.835880, -0.022980, -0.332690, 0.859090,
-0.460390, -0.020710, 0.533630, 0.193690, -1.314950, 1.030990, -0.101090, -1.043680, 0.335060, -0.600690,
0.413540, -0.252930, -0.715190, -0.015870, -0.181290, 0.782900, -1.472500, -0.156500, -0.737950, -0.586580,
-0.140380, -0.226700, 3.260490, 0.062200, -0.288890, -0.718040, -0.251870, -0.650070, 0.630270, -0.843560,
-1.120700, 0.452830, 0.338720, 2.241950, -0.804270, 0.099400, 0.579530, 0.547090, -0.440340, -1.840290,
0.615710, -0.361170, -0.153490, -0.770930, -0.687970, -0.152520, 0.045550, 0.139180, -0.000410, 0.510730,
-0.314230, 0.669850, -0.476480, -0.143410, -0.929170, -0.840270, -0.530750, -0.742330, -0.992650, -0.399980,
0.519780, 0.245720, 0.201910, 0.770580, -0.705000, -0.492070, 0.653360, -0.592540, -0.895090, 1.377940,
0.738260, -0.658800, -0.255940, 0.616460, 1.347710, -0.820990, 0.329720, -4.317740, 0.741350, 0.235940,
0.522460, 0.860070, 0.000070, 8.003030, 2.933400, 7.392720, 0.546800, -0.274690, 0.028210, 0.727050,
-0.936870, -0.135410, -0.694720, -0.014670, 2.310100, -0.109400, 0.101120, 0.205300, -0.255820,
0.130950, -0.438890, 0.646040, -0.124640, -0.571880, 0.621910, -0.221110, 1.060000, 0.954180, -0.202280,
0.756000, -0.893530, 0.589210, 0.228820, -0.904840, -0.485430, -1.455740, -0.792660, 0.048450, 0.189360,
0.620320, -1.039530, -0.820690, -0.076150, -0.720660, -0.144210, 0.101050, -0.659560, -0.436750, -0.491120,
-0.517130, 1.036990, -0.569490, 0.091640, -1.912310, -0.438880, -0.098150, -0.129460, 0.328100, -0.608770,
1.083050, 0.451060, 0.530580, 1.234620, 0.621110, 0.059770, 0.896390, -0.884610, -0.188470, 2.895780,
0.719080, 0.568110, 0.139650, -0.591390, 0.339680, 2.754320, -0.984030, 0.621710, -0.251770, -0.487430,
-0.253230, -0.672800, 0.059210, 0.321470, -1.280780, -1.253890, -0.232380, -0.438190, 0.299470, 0.183150,
2.367400, 0.284470, -0.610600, -0.231950, 0.508150, 0.245240, -0.472460, 0.267420, -0.098300, 0.724050,
0.809130, 0.320540, -0.845000, 0.265400, 0.474950, 0.721960, -0.288530, -0.418780, 0.451970, 0.217320,
0.925490, 0.424280, 0.412770, 0.059940, -1.056790, 0.137480, -0.207860, 0.663550, -0.133140, -0.456990,
0.848610, 0.195780, 0.763710, -0.484020, -0.578330, -1.064520, 0.966280, -0.673500, 0.063870, 0.394330,
1.107030, 0.274960, -0.859540, 0.882510, 5.221050, -0.898230, -0.446430, 0.961090, 0.699020, 0.409570,
-0.055370, 0.275500, -0.273020, 0.299470, 0.627410, 0.172580, 0.580170, -0.054440, -1.824950,
-0.378350, 0.155900, 0.400330, -0.026560, -0.321000, 0.512300, -0.026360, -0.582390, -0.153760, -0.043640,
1.063790, 0.729650, -0.147000, -0.211770, -0.252540, 0.699790, -0.766830, -0.688380, -0.412040, -0.348530,
-0.172180, 0.210200, -0.088520, -0.325990, 0.127070, -0.780480, 0.539540, 1.184960, 0.891590, 0.995510,
0.737310, 0.059100, -0.314140, 0.566090, 1.867880, 1.058340, 0.822010, -0.721650, -0.298580, -0.685000,
0.210760, 0.278800, -0.102370, 0.437560, 0.840750, -0.396520, 0.842890, -0.381080, 0.820500, -0.099600,
-0.174380, -0.738280, -2.169560, 0.459060, 0.304640, -0.786980, 1.035980, -0.730090, -2.012450, 0.688300,
0.901030, -0.334450, -0.076100, -2.004410, -4.608880, 0.829670, -0.858880, -0.651510, 0.264940, 1.336910,
0.131570, 0.138540, -0.567170, -0.050510, -0.328620, -0.404210, -0.229260, -0.412480, 0.926120, 0.565820,
0.530130, -1.486360, 0.215280, -0.697960, -0.748810, -0.699870, -0.889340, 0.004570, 0.560400, -0.478340,
-1.195710, -0.565430, -0.608480, -0.858510, 0.436300, 0.352340, 0.306450, 0.106970, 0.225780, 0.193060,
0.542060, -0.640700, -0.024220, -0.042540, -0.492820, -0.297000, 0.899230, -0.308170, -0.298600, -1.368690,
-0.332080, 0.842890, 0.649050, -0.834230, 1.637040, 2.223310, -0.067650, -0.796140, -0.333120, -0.027930,
0.091910, 0.465390, -0.908650, -0.759170, 0.184620, -0.603590, -0.369660, 0.073230, -0.145120,
0.355580, 0.122750, -0.877800, 0.722360, 0.324740, -0.442160, -0.990020, 0.438960, -0.006380, 0.211690,
0.037990, -0.830020, 0.710990, -0.325060, -0.798510, -0.780950, 0.347020, 0.306780, -0.589470, -0.927900,
-0.778820, 0.336970, 0.131130, 0.437090, -0.020760, 0.847240, 0.527310, -0.298740, -0.356760, 0.438620,
-0.111330, -0.512900, 0.380930, 0.422830, -0.800370, -0.038580, -0.503840, 0.443870, -0.590510, -0.157420,
-0.342340, 0.833940, -0.308150, 0.308490, -0.652670, 0.962990, 0.857600, 1.069220, -0.584750, 0.140620,
-0.319280, 0.642880, 1.856850, 0.141880, 1.221470, 0.722870, -0.257650, 0.511410, 1.891600, 0.403770,
-0.141880, 0.515260, -0.160190, 0.930760, 1.811260, -3.048780, 0.014670, 0.790000, -0.478110, 0.867000,
0.867330, -0.616180, -0.101780, -0.316850, -0.153960, 0.325360, -0.722920, 0.606390, 0.781430, 0.282250,
-0.157670, 0.592590, 0.384250, -0.019880, -0.752370, 0.242390, 0.508230, 0.767260, -0.271040, 0.801310,
0.082810, -0.352310, 0.900660, 0.500640, -0.406670, 0.007920, 0.628360, -0.228600, -0.274020, 0.280220,
-0.597430, -0.411070, -0.871980, 0.946260, 1.057920, -1.031600, -1.028890, 0.127670, -0.809690, -2.509950,
-0.724840, -0.001490, -0.395290, -0.737420, -1.119170, 0.613700, -0.539120, 0.282210, -0.955120, 0.659730,
-1.290230, -0.516440, -0.276180, -0.391510, 0.432770, 0.630950, -0.027800, 1.080180, -0.266670,
-0.360750, -0.422730, -0.317870, 0.228040, 0.823890, 0.277070, -0.374110, -0.548640, -0.481620, -0.306420,
0.481590, 0.087450, 0.332690, -0.497530, -0.794000, -0.299440, 0.617590, -0.168150, 0.247850, -0.211020,
-1.075010, -0.963470, 0.855860, 0.611010, 0.009630, -0.286500, -0.659050, 0.092740, -0.583570, -0.153380,
-0.458380, -0.452070, 0.775870, 0.272370, -0.405510, -0.927140, -0.133790, 1.098830, 0.360080, -0.187470,
0.439870, -0.169570, 0.504460, -0.771390, 0.653870, 0.030110, -0.642340, -0.493770, -0.376000, 0.446920,
0.195940, -0.401360, -0.144280, -0.535580, -1.479290, 0.681090, 0.867900, -0.379650, 0.341540, -0.485500,
2.348960, 0.176070, 0.922680, -1.135270, 0.427360, 0.287350, -0.411050, 0.039230, 0.452220, 1.298800,
0.150820, -0.777760, -1.516240, 0.508420, -0.272770, -0.800250, -0.091920, 0.528120, 2.164960, 0.151670,
0.894760, -0.084830, -0.740270, 0.584190, 0.622310, 0.532920, 0.289960, -0.702580, -0.886270, 0.657940,
0.885840, 0.951360, 0.479800, -0.548360, 0.048830, 0.226270, -0.354700, -0.496970, -0.626550, -0.359780,
-0.367120, 0.149690, 0.715060, -0.883230, -0.531930, 0.702820, -0.607020, 1.312560, 0.148350, -0.023890,
0.583840, -1.059270, -0.790200, -0.549970, -1.763160, 0.067000, -0.515620, 0.995810, -0.509910, -0.005970,
0.160900, 0.408110, 0.433110, 0.282360, 0.214090, -0.098480, 0.845220, -0.236500, 0.341940,
-0.830520, -0.320120, -1.001820, -0.198360, 0.165080, -1.063150, -0.546500, -0.604510, 0.095340, 0.602280,
0.231680, -0.180770, -0.653440, 0.062350, -0.860740, 0.762780, 0.056350, 0.185300, -0.638820, 0.816660,
-0.763190, -0.510260, -0.268460, 0.707190, 1.518090, 0.101980, 0.253450, 0.612060, 0.699290, 0.158390,
0.312450, 0.968830, 0.468140, -1.626390, 0.523450, -0.491390, -0.384060, 0.364150, 0.855700, -0.711750,
-0.975780, 0.406220, -0.127480, 0.977280, -0.197570, -0.684430, -0.401670, -0.715160, 0.424740, -0.383530,
0.351400, 0.592850, 0.938130, 0.477080, -1.734350, 0.037170, -1.339870, -0.461590, 0.716910, -1.212550,
-0.390310, 0.079870, -0.509850, -2.082740, 0.319760, 0.623930, -1.755010, -0.278590, -0.308050, 0.813450,
-0.766710, -0.515370, -19.602289, 0.361820, -0.785810, -1.205840, 0.172970, 0.443130, 2.327840, -0.825090,
0.130060, -13.463010, -0.633220, -0.510700, -0.540020, -0.291930, -0.091760, 1.799550, -0.174100, -0.108950,
-0.960330, 0.304590, -0.797070, 0.400800, 0.619190, 0.294490, -0.550350, 0.011360, 0.757690, -0.025330,
0.159490, -0.515860, -0.088680, -0.796650, 1.068550, -0.578500, 0.796950, -1.073710, 0.641660, 4.328310,
0.532800, 0.492270, -0.659740, 2.015830, -0.626920, 7.302570, -0.395200, 0.473490, -0.894730, -0.417820,
-1.084700, -1.366790, -0.800720, 0.448890, 1.653540, 0.771700, 0.084580, 0.250070, 0.837950,
0.553030, -0.270050, 0.433110, 0.103470, 0.747510, 0.733900, -0.853570, -0.523390, -0.240050, -0.715660,
0.546560, -0.408870, -0.040210, 0.696660, 0.664510, 0.416890, -0.385740, -0.864670, -0.891980, -0.305980,
0.682870, -0.478310, -0.547760, 0.300500, 0.158240, 0.898760, 0.606980, 0.135950, -0.249120, -0.921750,
-0.290420, -0.988220, -0.064600, 0.404750, -0.663730, 0.231900, 0.072090, 0.460990, -0.266560, 0.617500,
-0.808280, -0.610200, -0.747010, 0.523570, -0.896060, -0.414860, -2.435980, -0.665950, 3.401000, -0.516070,
0.381400, -1.037420, 0.862580, 0.631940, 7.290940, 3.047650, -1.471450, -0.100990, 0.653340, 0.882150,
-0.558140, -0.076450, -0.640120, 0.574170, -0.488630, 1.248530, 0.205690, 0.282730, 0.697950, 0.145090,
-0.890490, -0.150320, -0.226540, -0.087970, -0.563000, -0.315990, -0.536300, -0.449100, 0.042800, 0.004670,
-0.860430, 0.192340, 0.307670, 0.491780, -0.899510, 0.294510, 0.608330, 0.065110, -0.607600, 0.314170,
-0.486030, 0.894710, 0.413060, 0.871790, 1.046010, 0.503540, 0.084470, -0.406160, 0.415950, 0.616740,
-0.637650, -0.340830, 0.667180, -0.957030, -2.012430, 0.537950, 0.405000, -0.865540, 0.815330, 0.523160,
0.770750, -0.094120, 0.232090, 1.354660, 1.606200, -5.659310, -0.520810, 0.758310, 0.244210, 0.095350,
0.145420, -0.304310, -0.319800, 0.661200, -0.135160, -0.037300, 0.486140, -1.486050, -0.698430,
0.124990, 0.226740, -0.887400, 0.280960, -0.192800, -0.814500, 0.771930, 0.224060, 0.647800, -0.330530,
-0.212750, -0.759160, 0.664780, -0.589070, 0.472300, 0.034860, 0.444040, -0.111420, -0.298200, 0.210740,
-0.121700, -0.248610, 0.010610, 0.969460, 0.696170, 0.994120, 0.266760, 0.665410, -0.605530, 0.126270,
0.671090, 0.248260, -0.493620, -0.078900, 1.054760, 0.751680, -0.509530, 0.527110, -0.802480, 0.766340,
1.011700, 0.631520, -0.828840, -0.544090, -0.485110, -0.129040, 1.264810, -0.966230, -1.045760, 0.356320,
0.569800, 0.444450, -0.301450, -2.081190, -4.183410, -0.504540, 1.279440, 1.063470, -0.405940, -1.155200,
-0.265360, -1.260270, -0.193570, 0.955550, 0.779440, -0.515840, 0.756950, 0.337600, -0.821410, 0.271140,
-1.032150, 0.437890, -0.538550, 0.061960, 0.134810, -0.162060, -0.758160, -0.568870, -0.331510, -0.879670,
-0.572170, -0.491960, -0.382710, 0.251550, -0.666450, 0.331640, -0.868970, -0.294950, -0.481770, 0.451470,
-0.255360, 0.554250, 0.026930, 1.076900, -0.722740, -0.131090, 0.008330, -0.911520, -0.661930, 0.215870,
0.367530, -0.383440, -0.153870, -0.244640, 1.226440, -0.596890, -0.822560, -5.456480, -1.002740, -1.736630,
0.435160, -0.231500, -0.386360, -0.124840, 4.988380, 8.214040, -0.886520, -0.527290, 0.518830, -0.377560,
0.430340, 0.713160, -0.120730, 1.029650, -0.136830, -0.831940, 1.015740, -0.383660, -0.043330,
-0.000200, 0.277810, 0.646600, 0.228860, -0.422230, -0.621150, 0.211850, -0.346360, 0.247500, -0.517500,
0.259640, 0.256890, 0.626140, -0.780420, 0.538130, -0.208430, 0.372530, 0.962450, -0.887080, 0.050100,
-0.534500, 1.006940, -0.802750, -0.987550, -0.494500, -0.657180, -0.201590, 0.374310, -0.380040, -0.457680,
0.121410, 0.721110, 0.062740, 0.972450, 0.814780, -0.208950, 0.368710, 0.630710, -0.318620, -0.568700,
1.060160, 0.387930, 0.625870, -0.252870, 0.739110, -0.687470, -0.667400, -0.705750, -0.403520, -0.748440,
0.275670, 0.693500, -0.544570, -0.077090, -0.458850, -2.649100, -0.132330, 0.307770, 0.805070, -0.046620,
0.589140, -0.129450, -0.513640, 1.095290, 0.273150, -0.514120, -0.339080, 0.283330, 0.458650, -0.288140,
0.461780, 0.054290, 0.435860, 0.359230, -0.692520, 0.698060, 0.587010, -0.520960, 0.187950, 0.273680,
0.020330, 0.833110, 0.893980, 0.693430, 0.315530, 0.469490, 0.977800, 0.583430, 0.765110, 0.219180,
0.374620, -0.345310, 0.298610, 0.150490, 0.788660, -0.168280, 0.019600, 0.322780, 0.830110, 0.299440,
0.645330, 0.661250, 0.213360, -0.509830, 0.878980, -0.456450, -0.767350, -0.562260, 0.060220, -0.029230,
0.023060, 0.897920, 0.363450, -0.379490, 2.791070, 0.775790, -0.690700, 1.559140, -0.982130, -0.865590,
0.880010, -0.813280, 0.272220, -0.812390, 0.518820, -0.449250, 0.237200, -0.630180, -0.494200,
0.015120, -0.941470, -0.022600, 0.055540, 0.675550, -0.772290, 0.869750, 0.285540, 0.462700, 0.957190,
0.229450, -0.248520, -0.291280, 0.836330, 0.606010, -0.112000, 0.509460, -0.221070, -0.234090, -0.583570,
0.740890, -0.380990, 1.002580, 0.180020, 0.692620, -0.318810, 0.308720, -0.231510, -0.637040, 0.038170,
-0.730140, -0.158440, -0.502230, -0.191700, -0.378480, -0.324960, -0.246980, -0.051900, -0.367300, -1.007260,
0.470430, -0.134260, 0.041450, -1.959290, -0.507630, -0.103940, -0.340110, -0.744780, -0.367240, -1.675470,
0.474560, 0.280140, -2.194930, -0.828190, -0.989440, -1.957920, 0.013210, 0.356420, -2.061160, -0.380560,
-0.551360, -0.180240, 0.623610, 1.567470, -2.457320, 0.428620, 0.846820, -1.246550, 0.631660, 0.650360,
0.853210, 0.201590, 0.411890, -1.299950, -0.317020, -0.998300, 1.008480, -0.855340, 0.920650, 1.057580,
-0.163630, -0.512630, -0.697940, 0.832070, 0.064100, -0.566000, 0.859630, -0.732510, -0.007820, 0.090070,
0.795470, -0.718490, -0.640920, 0.505080, 0.698780, 0.636890, 1.502120, -0.406600, 0.340860, -0.800340,
-0.067490, -0.117170, -0.587480, 0.096340, 0.067740, 0.327580, 0.833730, -2.173490, 0.813150, 0.321970,
0.557850, -0.535500, -0.585580, 0.565070, -1.671780, 0.427770, -0.610120, -0.074350, 0.291560, 0.450340,
-0.008040, 0.292000, 0.295960, 0.526890, -0.696160, -0.301950, -0.182770, 0.582010, 0.352920,
0.064150, -0.445150, 0.264450, -0.545110, -0.108380, -0.740210, -0.585210, 0.568350, 0.732530, -0.772670,
0.756860, 0.826050, -1.129700, 0.015200, 0.203190, 0.817240, -0.171710, -0.604060, 0.508200, 0.098620,
-1.049570, -1.182570, 0.194340, 0.036060, 0.042190, -0.122100, -0.128210, -1.249560, 0.340160, 0.877040,
0.877430, 0.408960, 0.112180, 0.253450, 0.005240, -0.815000, 0.531370, -0.363880, -0.628990, 0.955350,
0.450190, -0.828950, -0.700250, 1.128430, -1.263760, -0.409410, -0.491160, 0.142550, -0.479880, 0.130210,
-0.930010, -0.120130, -0.363300, -0.720000, -0.242960, 0.529120, -1.127780, 1.093340, 0.711620, 0.273860,
-0.390170, 0.974630, 0.459870, 2.911360, 0.490200, 0.435690, -0.496320, 0.604800, -0.101900, -2.525470,
0.267530, -0.347710, 1.013100, -0.562340, -0.886430, 0.079250, -0.548520, -0.822310, 0.274530, -0.078680,
0.023210, 0.643550, -0.603090, 0.123540, -0.925980, -0.057780, 0.055090, 0.202190, -0.193420, -0.075030,
0.983020, 0.706250, 0.124730, -0.067120, 0.623470, 0.595710, 1.022080, -0.007640, 0.367640, -0.177220,
0.002950, 0.272590, 0.316370, -0.833720, -1.646160, 0.721930, 0.393520, -0.453930, -0.046450, -0.256500,
-0.686770, 0.639740, 0.571760, -0.770730, 1.146470, -0.385060, 0.853340, -0.168430, 0.288630, -0.201270,
-0.933870, 0.664620, -0.765390, 0.370300, 0.146540, -0.683590, 0.736880, 3.581570, -1.390810,
-0.299400, 0.705110, 0.343980, -0.877590, -0.141850, -0.286810, -0.044020, -0.691070, 0.721970, -0.399210,
-0.729470, -0.292100, -0.075250, 0.510860, 0.609910, -0.517710, -0.553220, 0.655650, -0.270990, 0.605530,
-1.086430, 0.928280, -0.211330, -0.321040, -0.783280, -1.386680, 0.111030, -0.588870, -0.054580, 0.508930,
0.646980, -0.320300, -0.949880, 0.691530, -4.919400, 0.972800, -0.913280, 1.446380, -0.191240, -0.247950,
-1.707270, 1.406500, 1.302840, -5.761840, -0.217650, -1.438990, -4.334760, 0.637900, 0.848490, -2.276140,
-0.621920, 0.010070, -0.309340, -0.295120, -0.123180, -2.683300, 0.614790, 0.230270, -0.656690, -0.177470,
-0.687450, 0.333580, 0.408880, 0.678000, -1.405350, 0.851620, 0.344170, -0.169950, -0.738290, -0.930850,
0.155960, -0.369120, -0.440100, -0.633220, -0.409990, 0.175890, 0.210390, 0.710590, 0.708640, 0.791380,
-0.045410, 0.147130, 0.156180, 0.576250, 0.093870, -0.949470, -0.383650, -0.501690, -0.287200, 0.385870,
-1.069000, -1.284180, -0.131700, 0.585870, 0.306370, -1.021620, -0.551680, -0.172640, -0.290770, -0.894060,
-0.310670, -0.472330, 0.392640, 0.017880, -0.100730, 0.308270, 0.193160, 4.959980, -0.854970, 1.075430,
0.445340, -0.447430, 0.469110, -1.886200, -3.617460, 3.019200, 0.202310, -1.158980, -0.040480, -0.264880,
1.267760, 0.569910, -0.177970, 0.281690, 0.724160, 0.754440, -1.087290, -0.075690, 1.571230,
-0.737230, -0.113120, 1.117410, 0.671420, 0.024450, -0.910340, 0.582420, -0.672990, 0.338960, 0.019680,
0.538770, -0.920050, 0.591590, -0.168670, 0.518300, -0.772150, -0.237260, -0.616320, 0.329000, 0.234070,
0.555530, -0.183050, -0.832620, -0.980660, -1.003050, 0.600340, 0.444660, 0.686210, 0.011510, -0.183230,
-0.331710, -0.653740, 0.558260, -0.105160, 0.546340, -0.715380, -0.689120, -0.423560, 0.256930, -0.401460,
0.332260, -0.603960, -0.072740, -0.315850, -0.139120, -0.827500, -0.149650, -0.708260, -1.110910, -0.194840,
0.791420, -0.897760, 0.304850, -0.879740, 0.027000, 0.358110, 2.895710, -2.733540, 0.261900, -1.160660,
-0.953330, 0.597020, 0.593190, -3.389400, 0.410380, -0.797710, -2.024860, 0.758260, 0.323980, -1.186520,
-0.510810, -0.905070, -10.487620, 0.801000, 0.004080, -2.459950, -0.556890, -0.575040, 2.254790, -0.070240,
-0.302040, -6.915520, -0.790860, 0.463470, -0.625100, 0.050860, -0.667810, 2.333390, -0.320520, 0.661290,
-1.767710, 0.849580, -0.100110, -0.760280, -0.346040, 0.736830, 0.167160, -0.265890, -0.549900, -0.426540,
0.474790, -0.278510, -1.115580, 0.191760, 2.877730, 0.550530, 0.231950, 0.545540, 0.617650, 0.674750,
-0.523410, 0.290810, 0.083570, 0.934600, -2.771410, 8.383400, -1.237380, -0.074420, 0.266070, 0.361300,
0.158990, -0.844440, -0.279140, -0.684210, -0.494990, -1.081390, -0.324180, 2.068380, 0.985780,
0.498450, -1.119420, -0.705210, 0.214090, -0.662760, -1.035580, 0.772810, -0.040270, 0.595980, 0.387790,
-1.175950, -0.540530, -0.945290, 0.696430, 0.584120, -0.635440, 4.042270, -1.054840, -1.050690, 0.290100,
-1.068700, -0.871140, 0.052600, -0.886760, 0.770500, -4.876390, 0.255480, -0.564880, 0.589150, 0.209370,
-0.175230, -1.163780, 0.127960, 0.225180, -3.044720, 0.092320, -0.803940, -5.861600, 0.587340, 1.736260,
-0.617040, -0.455770, 0.466360, -0.636010, 0.694260, -0.162890, -4.137820, 0.135880, -0.471990, -1.288220,
-0.372380, 0.136160, 0.638270, -0.805080, 0.878840, 0.171820, 0.104810, -0.524950, 0.144520, -0.365720,
-0.221150, -0.289700, 0.912740, 1.633800, 0.204580, -0.758030, 0.328640, -0.157530, -0.718990, -1.702940,
1.817540, 1.078450, 0.576380, 0.331740, -0.483560, 0.391310, 0.867410, 1.378330, -1.242130, -0.742770,
-0.440410, -0.581970, 0.889110, 0.757000, 0.587020, -0.429180, -0.266710, -0.544650, 0.755880, 0.015460,
-0.859670, -0.395310, 0.926130, -0.704790, 0.826330, 1.180640, 0.317780, 0.464420, -0.342860, 0.615510,
0.939170, -0.883830, -0.925050, -0.860840, -0.124210, -0.170480, -0.065550, -0.362810, 0.322810, 0.513030,
-0.175370, 0.422810, -0.108620, 0.454730, 1.279060, 0.192760, -1.055160, -1.248060, -0.904720, 0.382760,
-0.476970, 0.047670, 1.158920, -0.897190, 0.519270, -0.150590, 0.540950, 0.074560, -1.190050,
0.210500, 0.312260, -0.397810, -0.265700, 0.891450, 0.820880, 0.081710, 0.030250, -0.137480, 0.836810,
0.405960, -0.227290, 0.403750, -0.386130, 0.684490, 0.684780, 0.100650, -0.502200, -0.707730, -0.036930,
-0.704950, 0.429840, -0.570190, 0.014300, -0.868640, 0.475300, 0.609520, -0.680960, -0.923930, -0.834320,
0.275310, -1.127780, -0.279220, -0.389980, -0.134510, 1.542860, -0.256760, -0.427300, -0.071570, 0.640750,
-0.230260, 0.010220, 0.654060, -1.001070, 0.800700, -0.020990, -1.160590, 1.016900, -0.312200, 0.386570,
0.527290, -0.181000, 2.828140, 0.743820, 0.887540, 0.416000, 1.645790, -0.311210, -0.918490, -0.173810,
0.076560, 1.742030, -0.529570, 0.370190, -0.165730, -0.654930, 1.427170, -1.147780, -0.430860, -0.402060,
0.086370, 0.585410, 1.387330, -0.997390, 0.519730, -0.435800, 0.494760, -0.076420, -0.695860, -1.288580,
-0.099370, 0.362570, -0.261920, -0.348840, -0.659050, 0.160500, -0.083600, 0.720760, -0.319610, 0.025510,
-0.525750, -0.895350, -0.900310, 0.814420, -0.464590, 0.957570, 0.294630, 0.662330, -0.434340, 0.482080,
0.458190, 0.698670, 0.822320, -0.244430, -0.024100, 0.335650, -0.330220, -0.565760, -0.848110, -1.447190,
0.853800, -1.020380, -0.450530, -0.224290, -5.974050, -0.691980, 0.286060, 0.826710, 0.312670, 0.209990,
1.569100, -0.590830, -3.629630, 0.363510, -0.478020, 0.239720, -0.699600, -2.159810, 0.761510,
-0.604670, -0.596830, -0.001580, -0.822880, 0.370300, 0.867270, -0.032040, 0.634910, -0.322110, -0.339600,
-0.425710, 0.300390, 1.023940, -0.111630, -0.498120, -0.633530, -0.196270, -0.676120, 0.411880, 0.649240,
0.231440, -0.070330, -0.999450, -0.896180, 0.492160, 0.565080, -0.609920, -0.561480, -1.043210, -0.188230,
-0.191460, -0.904430, 0.151020, 1.089160, 0.459610, 0.416490, 0.294210, -0.363330, 0.767780, -0.788130,
-0.115800, -0.542870, 0.895880, 1.747020, 0.420620, -0.104910, 0.164950, -0.680790, -0.897490, 0.434650,
-0.051290, 0.451480, -0.942920, -0.403620, 0.155110, 1.380790, -0.089710, -1.403120, 0.878860, -0.635020,
1.416810, -0.724620, -0.451050, -0.599310, 1.322720, -0.903460, -2.989540, -0.394820, -0.609890, 2.408220,
0.374440, 0.704540, -1.160530, -0.761030, 0.870490, -1.065240, 0.531760, -0.119640, 3.615690, 0.029390,
0.713220, -1.751290, 0.375410, -0.092240, -0.352040, 0.779100, 0.392350, -0.328020, 0.343650, 0.126320,
-0.941610, -0.863310, -0.111810, -0.028010, 0.026200, 0.449590, -2.839170, 0.816580, 0.201460, 0.481690,
-1.161760, 0.468840, -0.382510, -0.865190, -1.062960, -0.837440, 0.792470, 0.107100, 0.086130, 5.316580,
-0.835620, -2.079360, -0.119610, -4.133890, -0.506950, 4.411060, 0.981100, -0.868700, -0.257320, 1.204510,
0.777260, -0.025160, 0.950050, 0.694790, -1.182850, 0.318690, -0.622560, -0.479880, 0.690770,
1.425820, 1.325180, -0.706530, -1.033630, -0.621690, 1.110840, -0.917970, 0.835470, -0.384550, 0.026250,
-0.741950, -0.465900, 0.348510, 0.293880, -0.018170, 0.216500, 0.964630, 0.778470, 0.406280, 1.157840,
0.967180, -0.870960, -0.457600, 0.885750, 0.148250, 0.624580, 0.120200, 0.934480, 0.783060, -0.652280,
-0.273140, -1.652770, -0.195830, -0.959400, 0.014480, 0.359770, 0.956250, 1.319510, 0.627750, -0.155210,
0.919280, 0.034170, -0.890010, -0.885130, 0.716690, 0.946320, 0.053780, -0.107340, 1.159570, -0.144040,
-0.843450, -0.727980, -0.152660, 1.413720, -0.066040, 0.840800, 1.053510, -0.226000, -0.346170, -0.488740,
-0.398680, 0.060710, 0.942910, -0.229580, -0.422470, -0.008750, -0.384290, 0.148830, 0.543040, 0.201080,
-1.213130, -0.065610, -0.428920, -0.011240, -0.732320, -0.289590, -0.197370, 0.477840, 0.831900, 0.690860,
0.800950, -1.742180, 0.122180, -0.242070, 0.203440, 1.227790, -0.238840, 1.045380, -0.274920, -0.154720,
-0.403920, -0.202330, 0.460700, 0.745860, 0.111250, 0.491060, -0.317150, 0.652950, 0.428890, -0.898830,
-0.082930, 0.005070, -0.063640, 0.171920, -0.776090, 0.383990, -0.100200, 1.837800, -0.429860, -0.645470,
-0.605960, -0.505140, -0.555340, 1.916590, 0.135510, 0.623950, -0.232790, -0.279570, -0.092830, -0.334010,
-1.032330, 0.683430, -1.555760, -0.756750, 1.223370, 0.970660, -0.475400, 1.910030, 0.543060,
-0.026160, 0.078580, 0.731140, 0.172620, 0.875680, -0.519250, -1.938530, 0.826480, -0.172680, -0.667780,
-0.622570, -0.209260, 0.307540, -0.052810, 0.952570, -2.005510, 0.422670, 0.395230, 0.731460, 0.339470,
0.373940, -0.101540, 0.458920, -0.039390, -4.117060, 0.292510, -0.452950, 1.148860, 0.164050, -0.146230,
1.347260, 0.926460, 1.048380, -3.357330, -0.048850, 0.770860, -0.099770, 0.346480, 0.302040, -1.472160,
1.194590, 0.098570, 0.205000, 1.117280, 0.744700, -3.306090, 0.249690, -0.659580, -0.843030, 0.214500,
0.710140, 1.408950, -0.334310, -1.256120, -3.203110, -0.365020, 1.015350, -1.168300, -0.758100, -0.964320,
0.572360, -0.657650, -0.648630, -0.864980, -0.085340, 0.113850, -0.886850, -0.263690, 0.141190, 1.294150,
-2.055660, 0.008950, -1.396000, -0.616620, -0.093750, -0.022780, -0.403630, 0.238270, 0.359080, -0.158850,
0.391490, -0.123260, 0.311670, 0.215960, -0.691470, 0.322160, -0.354370, 0.331980, -0.159980, -0.525340,
-1.340810, -0.144400, -0.108900, 0.516550, -0.567650, -0.006880, -1.298730, 0.635610, -0.549260, 0.409490,
-0.546370, -0.588820, 0.945730, -0.811330, 0.535790, 0.733710, -0.388310, 5.323720, 0.272040, 1.670350,
-0.967320, -0.016360, 0.352810, -1.088380, 12.238390, -1.646680, 0.108920, -0.483850, 0.203590, -0.750390,
1.097610, -0.116110, 0.727920, 1.069760, 1.683240, 0.055170, -0.351320, 4.116620, -1.010780,
0.583890, -0.134070, -0.679300, -0.806010, 0.570220, 0.142950, -0.010480, -0.056370, 0.462260, 1.030710,
-0.963350, 0.053020, 0.689590, -0.849140, 0.316720, -0.759220, 0.940240, -0.009040, -0.724080, 0.017040,
0.041900, 0.584300, 0.318000, 0.514860, 0.539090, -0.602770, -0.499800, -0.269040, 0.498820, -0.967890,
0.597100, -0.165830, 0.741490, -0.342460, 0.761800, 0.619630, 0.106470, 1.076500, -0.295120, 0.267320,
0.777270, 0.224530, -1.231580, -0.322000, -0.150830, -0.971500, 0.636700, -0.820630, -0.340570, 0.741730,
0.496030, 0.141120, -0.956780, 0.066310, -2.668320, 0.534190, 0.766620, -4.732310, -1.259300, 0.105120,
1.964590, -0.918480, 0.426400, -5.139460, 0.233780, 0.300020, 0.718360, -1.183660, -0.407190, 0.422770,
-1.027880, -1.060120, -0.515120, -0.268810, 0.521500, 0.071840, 0.265560, 0.676310, 0.699130, 0.141630,
0.195830, -0.144960, 1.120850, 0.680690, -1.013330, 0.606540, -0.384470, 0.642670, -1.036380, -0.156710,
-0.265850, 0.192370, -0.916240, 0.234040, -0.689310, -0.376470, 0.140240, 0.534810, -0.690320, -0.679350,
-0.059490, 0.728140, -0.488930, 0.337630, -0.238130, -0.064350, 0.258950, -3.060000, -0.250830, -0.153870,
0.650230, -0.106310, -0.982450, 0.370100, 3.209620, 0.901130, -0.507680, -0.184790, 0.570410, -0.476070,
-1.017590, -0.647150, 0.604110, -0.393020, 2.056130, 0.408760, -0.872410, 0.385360, 0.190180,
1.206710, 0.185810, 0.255090, 0.751380, 0.665830, 0.340680, 1.126680, -0.337370, -1.003410, 0.126490,
-0.246770, -0.053130, 0.352460, 0.419570, 0.421130, -0.310530, -0.828330, 0.309040, 0.000990, -0.352860,
-0.099010, 0.971760, 0.795340, 0.071330, -0.442440, -0.079230, -0.617250, -0.450850, 0.799850, 0.217480,
-0.891880, -0.927100, -0.812120, -0.312460, -1.011160, 0.284390, 0.199030, 0.746790, 0.321430, 0.047450,
-0.561270, 0.605930, 1.116330, -0.623290, -0.387690, -0.016510, 0.543620, -0.174880, -0.429550, -0.291260,
-0.371150, -1.117290, -0.906170, 0.443350, 2.890950, -0.703160, -0.501920, 0.217920, -0.696260, 0.510720,
-1.826040, 0.572650, -0.194640, 0.147250, -2.719270, 0.334990, 0.288270, -0.416790, 0.572700, 0.598160,
0.757240, 0.577350, -0.141130, -1.376100, -0.394690, -0.220410, 0.478420, -0.431030, 0.674850, 0.937140,
-0.457910, 1.033580, -0.236540, 0.248930, 0.913200, -0.711870, 0.307760, -0.524170, 0.740980, -1.057390,
-0.360670, -0.975130, -0.401830, 0.020990, -0.540310, 0.717020, 1.006010, -0.675130, 0.477810, -0.868480,
-0.249580, -0.475730, 0.051930, 0.769110, -0.494460, 0.285090, -0.658290, -2.666470, 0.740450, 0.513890,
0.051300, 0.186310, -0.347350, -0.555300, 2.664010, 20.244370, -1.062850, 0.222680, -1.023710, 0.146760,
0.208070, -1.410570, 0.000540, 0.576500, 0.406340, -0.387210, -0.270470, 0.443800, -1.314580,
-0.176660, -0.398640, 0.065540, -0.103780, -0.909850, -0.019510, 0.557510, -0.213160, -0.692370, 0.064220,
-0.769610, -1.296660, -0.607410, -0.715880, 0.222700, -0.185050, 0.592280, 1.019640, 0.160560, 0.462480,
-0.139150, 0.129430, 0.112830, 0.370290, -1.264880, 0.052160, -0.551980, 0.606400, 0.417100, -0.054950,
-0.153640, -0.609980, 0.376800, -1.171700, -3.383720, 0.716130, 0.172300, -1.108990, -0.548490, 0.611660,
-0.956010, 0.093470, -1.683860, -0.926010, -0.671150, -1.080740, -3.752900, 0.854350, -0.950300, -0.426090,
0.438780, -1.823230, -0.830860, 0.371410, -4.220250, 0.259700, 0.502730, -3.115610, -1.076260, 0.588750,
1.880030, 1.717160, 0.695110, -9.651500, 0.961140, 0.549480, 1.811870, -0.615050, 0.305990, 1.122120,
-0.816600, 0.262110, -1.744570, 0.492470, 0.112690, -0.045720, 0.146100, -1.759340, 0.619810, -0.771200,
-0.894250, -1.424860, -0.341550, 0.066610, -0.780970, 0.311980, 0.193840, -0.377410, -0.194950, -0.393550,
-0.864880, 0.850990, -0.187980, -0.456890, -0.755200, -0.846990, -0.518910, -0.252000, 0.382820, 0.533600,
-0.177590, 0.454900, -0.128020, -0.106330, -0.171490, 1.327480, -0.446550, -1.229390, 0.361950, 5.158340,
0.415230, 0.899570, 1.822800, 1.311250, 8.937980, -12.363950, 0.322840, -0.119150, -0.621450, 0.154020,
-0.081450, -0.305790, -0.630370, 0.500710, 1.681770, -0.078730, 0.170250, -1.597700, -0.247240,
1.976080, 1.641550, 0.011630, -0.068640, 0.876380, -0.321210, -0.031800, 0.368490, 0.199510, 0.136670,
-0.435990, 0.666980, -0.334890, 0.658760, -0.975860, -0.966200, -0.522420, 0.440450, 0.474700, -0.960210,
0.256150, 0.768200, -0.430700, 0.879960, -0.223090, -0.662710, 0.118460, 0.790370, -1.316760, 0.902540,
1.667300, -0.897640, 0.450580, -1.017740, -1.043170, -0.137390, -0.296640, 0.195090, -0.153800, -0.345210,
-0.116570, -0.321800, 0.049590, -0.579030, 0.763500, -0.264660, 0.389170, 0.713350, -1.006500, -0.873620,
-1.527720, 0.418070, -5.290720, 0.609910, -1.203450, 4.502500, 0.150350, -0.503010, -0.346740, 0.475660,
-1.133930, -5.593770, 0.184720, -1.368120, 2.936100, 0.478190, 0.127230, 0.546560, -0.088470, 0.382100,
-6.575700, -0.893180, 0.292240, 2.160200, 4.353080, 0.240310, -0.359270, 0.382030, 0.880550, -7.600250,
0.172130, -1.343360, 5.449610, 0.310900, -0.471430, -0.525490, 0.318260, 0.025970, -5.369650, 0.238200,
-0.029350, 10.965980, -0.881190, -0.141210, 0.788470, 1.286280, -0.727860, -0.570120, -0.574200, -0.783230,
0.016080, 1.027610, -1.280940, 1.073430, -2.634730, -0.462570, 0.040940, -0.766190, -0.067960, 1.870070,
1.031640, 0.795230, 0.034890, -0.696070, 54.838360, 1.901420, 0.246200, -1.555190, 0.218420, 3.002730,
0.892400, 1.180530, 0.966690, -0.414280, -0.737750, 1.474870, -0.536800, -2.251310, 1.344670,
0.174050, 0.051340, -0.091260, 0.560000, 1.180020, 0.111550, 0.886210, 0.010460, 0.516690, 0.397350,
-0.891560, 0.570070, -0.036500, 0.510470, -0.229020, -0.990340, -0.076110, 0.288830, -0.496260, 1.135180,
0.639080, 0.153590, -0.243110, -0.527850, 0.583290, -0.752250, -0.959040, 0.431320, 1.055050, -0.178330,
1.191950, -0.975490, 1.140410, -0.222240, 0.417530, -0.358990, 0.196870, -0.809710, -0.747540, 0.876750,
0.296230, -1.058410, -0.463490, 0.994490, 0.295690, 0.876600, 0.009580, -0.847530, -0.518820, 0.221380,
-0.351750, -1.011000, 0.379760, 0.726670, -0.400000, -1.032440, 0.191390, 0.162500, -1.960840, -1.007160,
-0.416910, 1.643630, 0.002060, 0.344710, -4.167330, -0.320500, 0.565860, -1.294570, -1.007070, 0.174350,
5.370570, 0.839380, 0.766150, -3.649580, 0.143340, -0.066270, -0.478330, -0.971880, 0.094470, 1.276540,
0.276980, 0.109440, -4.335120, 0.406930, -0.577090, 0.559020, -1.054430, 0.710300, 0.257990, 0.720330,
0.320340, -0.274420, 0.549940, 0.117130, -1.050660, -0.594540, -0.287410, -0.415980, -0.757260, 0.008750,
-0.302490, -0.732880, -0.098560, -0.067880, 0.993970, 0.847900, -1.096430, 3.486100, -0.479390, -1.809660,
-0.384200, 0.855300, -0.498840, 0.797970, 2.237760, 6.919490, -0.089110, -0.313560, 0.631800, -0.669820,
-1.046750, -0.980160, 1.544570, 0.124190, 0.679130, 0.252380, -0.104210, -0.003570, -0.769890,
0.640660, -1.121470, 0.040480, -0.565390, -0.451290, 1.182240, 0.531800, -0.093920, 0.140760, -0.030370,
-0.521700, 0.022890, 1.055470, 0.634800, -0.554190, 0.331580, 0.686540, 0.023080, 0.530180, -0.760470,
1.127990, 0.497120, 0.137970, -0.857560, -0.050060, 0.369610, -0.765830, -0.298650, -0.117810, -0.070150,
0.860990, 0.437760, 0.223030, 0.759810, 0.543870, 0.611020, 0.687110, 0.295370, 0.717110, -0.522760,
0.707820, -0.932180, -0.875420, -0.667840, -1.322280, 2.875910, 0.297310, -0.913780, -0.699670, -0.222660,
-0.364880, -0.825920, 0.195170, -1.119610, 0.244360, -0.842650, -0.033420, -0.852770, -0.336270, -1.387230,
-0.057320, -0.592050, 0.340740, 0.763390, -0.676240, -1.031700, 1.002610, -0.259400, 0.711110, -0.058230,
-0.517180, -0.494710, 0.330010, -0.005870, 0.628750, -0.027730, -0.021300, -0.517130, 0.241360, 0.908720,
0.107380, 0.577300, 0.650260, 0.919040, -0.597670, -0.628560, -0.806210, -0.123360, -0.071010, -0.428140,
0.011270, 0.728800, -0.882290, 0.742780, -0.485170, 0.351000, 0.345500, 0.930010, 0.265300, -0.163440,
-0.439920, 0.950050, 0.033210, -0.740580, 0.010190, -0.586160, 0.887460, 1.218500, 0.814040, -0.676420,
-0.721940, -1.024120, 0.357330, 1.001130, 0.335200, 7.668420, 0.343290, 0.851970, -0.094600, -0.973520,
-0.262510, 1.501540, -0.324560, 0.286940, -0.625000, -1.024050, 0.444460, -0.652350, -0.692240,
-0.923900, -0.826190, 0.724750, 0.231120, 1.219230, -0.037910, -0.370900, -0.657340, 0.621270, 0.836410,
0.904900, -0.624240, -0.027890, 1.955230, 0.144080, 0.334310, -0.690030, 0.079910, 0.447940, 0.719270,
0.834710, -0.789840, -0.388080, 0.607700, -0.090370, 0.180540, 0.233510, -0.945060, -0.482730, -0.895310,
0.390860, 0.174390, -0.913770, -0.260320, -0.290620, -0.453600, 0.622840, -3.380470, -0.947070, 0.592470,
-0.947710, 0.271140, -0.551730, 0.935360, -0.921060, -0.681860, -1.309130, 0.733190, 0.376410, 0.352470,
-0.450080, -0.374940, -0.428980, -0.665130, 0.057430, -1.128180, -1.965110, 0.907310, -1.278630, 0.976130,
-0.751650, -0.967820, -0.154830, 0.763510, 1.274280, -0.623300, -0.934130, -0.562000, 0.947400, 0.311430,
0.284860, 0.670850, -0.225490, -0.156430, -0.397340, -0.397310, 0.811960, -0.284860, -0.817180, -1.297860,
-0.526910, 0.588480, 1.063000, 0.128730, 0.127380, 0.422230, -0.171200, 0.103790, 0.223090, 0.570650,
-0.607530, 0.441960, 0.916190, 0.491320, 0.376950, -0.517260, -0.229700, -0.461740, -0.361680, -0.012490,
-0.352430, -0.305800, 0.560210, -0.571910, -1.101860, 1.801670, -0.304490, -4.005740, 0.497530, -0.845080,
0.725590, -0.553230, 0.617650, -0.425320, -1.234230, 4.089060, 0.606950, -1.365680, 0.028040, -0.380600,
-0.606630, 0.585350, 0.514250, -0.552140, -0.599320, -0.630250, -0.630530, -0.144000, 0.152140,
-0.666690, 1.450670, -0.665410, 0.665620, -0.015620, 0.555830, -1.014850, -0.719770, 0.105860, 0.844640,
0.312530, 0.808400, 0.178020, -0.616470, 0.930300, 0.087000, 0.565130, 0.489180, -0.562200, 0.521660,
1.346220, 0.389980, -0.578310, -0.127200, -0.562920, -1.184090, -0.088170, 0.858070, 0.966720, -1.009270,
-0.374850, -0.770530, -0.255350, 0.723420, 0.395410, 0.367440, -0.693260, -0.672830, -1.110370, -0.255240,
0.763520, 1.098060, 0.132640, 0.291500, -0.860480, 0.623920, -0.092710, 0.012830, 0.802240, 0.266450,
-0.809750, 0.355270, 0.443800, -0.513270, -0.232670, -0.653250, -3.805830, -0.086050, 0.377160, 0.231540,
0.411040, 0.917650, -0.701650, 1.041450, 0.911580, -1.469740, 0.059250, -0.464000, -0.996020, 0.335910,
-0.146530, -0.055390, 0.946250, -0.669310, 0.485680, -0.790770, 0.960340, -0.161280, 0.088350, 1.679000,
0.600500, -0.296900, -0.649470, 0.292730, -0.284400, -1.409200, -0.690070, 0.265290, -0.591120, -0.038020,
1.366790, -2.344840, 0.537340, -0.519010, -2.401340, 0.519280, -0.714200, -0.221580, -0.833340, -0.378060,
-0.426130, -0.682890, -0.530530, 0.363600, 0.863340, 0.061180, -0.575520, -0.043450, -0.289140, 3.221910,
0.940410, 0.044260, -0.663110, -1.212480, 1.140430, -1.155360, -0.572660, 1.191220, 0.305510, -0.426920,
1.836810, 0.480990, -0.570890, -0.858640, -0.789910, -0.102310, 0.464410, -0.011680, -0.310820,
0.113160, 0.351750, -0.350180, -0.321850, 0.625260, 0.909860, 0.221210, -0.536750, 0.345950, 0.014110,
-0.061030, 0.790200, -0.447540, -0.275010, 0.946140, -0.364470, 0.111910, -0.730480, 0.097340, -0.218180,
0.722100, -0.987550, -0.106100, -0.924280, 0.209060, -0.104260, 0.686790, -0.952240, 0.466860, -0.094760,
0.784140, -0.389500, 0.266720, -0.322430, 0.061490, 0.685280, 0.450790, 0.589540, -0.509480, 0.429200,
-0.235390, 0.376780, -0.776540, -0.580010, -1.087010, 0.067970, 1.015010, -0.460740, -0.744320, 0.858670,
-0.924370, 0.092720, 0.311420, -2.388040, 0.511600, 0.702670, -0.476890, -1.140960, 0.404190, -0.757860,
1.040330, -0.674020, 0.071880, -0.983800, -0.703060, -1.264220, 0.041620, -0.694840, -0.621410, 1.508230,
0.373000, 0.246010, -0.969430, 0.914270, -0.646190, -1.122560, 0.029270, -0.405970, 3.451450, -0.163280,
0.051910, -3.414520, 1.082670, -0.542660, -0.213650, -0.467350, -0.745810, 4.984520, 0.836770, 0.617220,
-5.180820, 0.596390, -0.699150, -1.198190, -0.823300, 0.298020, -0.923200, 1.146120, 0.589290, 0.820940,
-0.928600, -0.402970, 0.852540, 0.421700, 0.871390, -0.346690, -0.140840, -0.709660, -0.404480, 6.730140,
0.596370, -1.917420, -0.484130, -1.470660, 1.643040, -6.548930, -0.308950, -0.436710, 0.311380, -0.244630,
-0.840350, 0.785440, -0.365630, 0.699430, 0.396950, -0.287800, 0.614420, 0.581000, 0.140670,
-1.047910, -0.693830, 0.657270, 0.831370, -0.211800, 0.568540, 0.024750, -0.209500, -1.488140, 0.158900,
-0.594270, -0.720140, 0.133480, 0.415790, -0.646130, -3.978200, 2.298850, -0.101040, -0.504830, 0.004840,
-2.315180, -0.786580, -0.199930, 0.060860, -0.657220, 1.173580, 0.953640, 0.501960, 0.371670, -0.795780,

-0.771340, 0.729090, -0.526800, -1.158370, 0.787200, -0.012280, -0.015650, 0.128170, 0.293440, -0.874150,
-1.264260, -0.240730, 0.480700, 0.631490, -6.150810, 0.637440, -12.634220, -1.125570, 0.655650, -0.048730,
0.080040, 0.429280, -0.473150, -0.868050, 0.292370, -2.843870, 0.205640, -0.570140, 0.161090, 0.527590,

0.683340, 0.443540, -0.248190, 0.508600, 0.436570, -0.259550, -0.189830, -0.817080, 0.626110, -0.128850,
0.724330, -0.589290, 0.000410, -0.892360, 1.429660, -0.425030, -0.643270, 0.266380, -0.433650, -0.821070,
0.266580, -0.341220, -0.235710, 0.986360, 0.772990, -0.526640, -0.823820, -0.350890, -0.251710, 0.337970,

-0.781830, -0.451480, -0.377320, 0.425680, 0.446190, -0.322840, 0.480680, -0.851570, -1.432840, 0.173770,
-2.061900, 0.302040, 0.042460, 0.496220, 0.567640, -9.222570, 2.140590, 0.172900, -0.421150, 0.440430,
-1.429820, -0.867740, 0.777430, -0.462170, -1.325690, -0.144970, 0.034220, 0.340480, 0.694650, -0.616800,

0.118980, -0.488340, 0.753940, -1.022060, -0.270980, -0.692030, 0.298610, 0.468090, 1.316840, 0.425820,
0.024520, -0.846220, -0.805020, 0.026880, -4.954290, -0.493030, -1.481140, -0.630260, 0.495740, -0.698930,
0.257070, 0.378990, -0.162280, -0.144860, 0.820160, -1.942690, 0.573560, 0.116840, 0.156110, 0.794460,

0.016320, 0.619960, -0.541220, 0.670730, -0.378940, 0.837200, -0.830920, 0.459680, -0.887480, -0.736170,
1.503040, 0.811190, 0.359360, -0.296580, -0.641760, 1.099480, -1.366670, 0.871850, -0.711970, 0.440030,
0.358460, 0.313640, -0.705830, 0.469290, 0.210390, -0.272900, -0.824030, -0.456170, -1.369090, -0.005340,

0.213700, -0.869010, -0.264760, -0.080200, 1.098280, -0.907650, 0.889970, -0.980850, -1.276950, -0.835620,
0.402300, 0.830140, 0.675960, 0.639370, 0.258160, -18.807461, 3.765340, 0.534230, -0.647820, -0.168570,
-0.222040, -1.340610, 0.458510, -1.110320, -1.020130, 0.188400, 0.251500, -0.343670, 0.979680, -0.796860,

0.417210, -0.752460, 0.061290, -0.213560, -0.490590, -1.514290, 0.568550, 0.946020, 1.525110, -0.464280,
-0.060210, 0.440210, -1.881000, -0.338260, -1.609110, 0.463320, 1.157900, -0.211740, 0.413620, 0.384720,
0.357420, -0.606130, -0.345400, 0.359750, 0.379520, -2.914470, 0.539140, 0.663640, -0.581600, 0.843160,

0.248730, 0.544050, 0.781670, -0.448840, 0.027490, 1.963900, -1.085230, 0.391230, -0.990600, -0.054250,
-0.699910, -0.630380, 0.093570, -0.346030, 0.056490, 0.397650, -1.929090, -0.019410, -0.614100, 0.124350,
-0.058200, 0.822270, 0.045400, 0.523700, 0.336030, 0.325710, -0.547470, 0.049380, -1.187870, -0.320410,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.745770, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.257800, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.008540, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.043880, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.516670, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.275780, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.776090, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.441050, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.195620, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.881740, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.553640, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.461360, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.453400, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.130460, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.324320, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.058730, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.752730, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.653500, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.352620, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.813610, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, -0.088210, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.027690, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, -0.053270, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, 0.082350, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 1.026070, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.613430, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, 0.076740, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.888110, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.378270, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.302120, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.267190, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.704560, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.353010, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.525520, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.894910, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.684650, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.209880, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.832100, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.871860, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.06178, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.04946, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
1.23196, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.37918, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
1.19919, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.02670, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.17674, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.22943, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.42850, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
0.02338, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.36961, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.15389, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.42785, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
0.22468, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
0.00256, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.88735, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00001, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
1.23996, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.00001, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.00011, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.39834, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.00000, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.91769, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
1.39714, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
1.42456, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
1.06424, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.09992, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.02729, 0.500000, 2,
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
