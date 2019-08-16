/*********************************************************
  TMPENTROP2+weight_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:17:31 2004
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
0.636660, -0.136010, 0.724140, 0.635580, -0.102470, -0.084610, -0.778810, 0.764740, 1.106220, 0.824860,
0.221520, 0.536810, 0.670090, -0.017470, -0.510660, -0.791640, -0.032040, 0.478190, -0.550550, 0.139290,
1.194360, -0.685900, 0.666090, -0.455570, 1.212640, -1.661800, -0.253010, -0.226510, -0.146800, 0.406100,
-0.352260, -0.092310, -0.313250, 1.141590, -0.538200, 0.992550, -0.927460, -0.540250, 0.432650, 0.520850,
-0.787320, 0.687120, -0.044120, -0.562880, -1.951250, -1.808890, 0.548130, 3.464970, -0.037270, -0.011330,
-2.631680, 0.478140, -1.202610, 0.644180, -0.203330, 0.667020, 0.385000, 0.230620, 0.045430, 0.438820,
-0.633580, -1.391910, -0.522070, 0.479670, -0.506810, 1.128440, -0.634650, 0.351990, 0.667930, 1.508280,
0.220080, 0.844370, -0.675220, -0.249760, 0.338780, -0.257030, -0.124400, -0.337480, -0.368110, -0.272750,
-0.510140, -0.892000, 0.833050, 0.109230, -0.964000, -0.112120, -0.749960, -0.013430, -0.637680, -0.910950,
0.535620, 0.510540, 0.943290, -0.676080, 0.568980, -0.286860, 0.716160, -0.699160, 0.633710, -1.225250,
0.588130, 0.584870, 0.092340, 0.264600, 0.748500, -0.347590, 0.501120, -2.049030, 0.220350, -0.834900,
0.957900, 0.531570, 0.679250, -1.932510, -0.864320, -0.315260, -0.106400, -0.122870, 0.206090, -0.083390,
0.166070, -0.965390, 0.555750, 0.562910, -0.550500, -2.758380, 0.591590, 0.547400, -0.113140,
0.258790, 0.128200, 0.409920, -0.889250, -0.550760, 0.389510, -0.796800, -0.950590, -0.433040, 0.301000,
-0.075230, -0.305390, -0.701300, 0.514480, 0.447860, 0.397320, -0.077220, 0.906880, -0.640450, 0.047180,
0.062290, 0.806430, 0.106440, -0.711870, -1.623840, -0.388390, -0.681300, 1.002550, 0.723410, -0.328370,
-0.937080, -0.240590, 0.589790, -1.042490, 1.185740, 0.910640, -0.362250, 0.587860, 0.237800, -6.857540,
-0.083210, -1.239470, 0.135800, -0.472120, 0.046590, -5.500250, 1.152990, -0.519560, -3.438550, 0.300780,
-0.577180, -1.044990, -0.515390, 0.968730, -3.857010, -0.500740, 0.322140, -1.669930, -0.507600, -0.755060,
-0.929360, 0.427520, 0.897650, -6.564190, -0.565550, 0.602450, 2.357220, -0.856670, 0.330450, 0.417280,
1.084170, -0.103020, 1.299640, 0.005120, 0.204820, 0.005820, -0.206850, -0.553030, -0.236070, -0.589310,
0.725480, -0.560220, -0.390120, -0.798080, 0.729870, 0.223400, 0.599400, 0.269530, -0.012760, 0.781270,
-0.519700, 0.805840, 0.245920, 0.129830, 0.569620, 0.790460, -0.050290, -0.603260, -1.471840, -0.032150,
0.299460, -0.629020, -0.394290, -0.322180, 0.260510, -0.405060, -0.726420, 0.139020, -0.773330, -1.318790,
0.646040, 0.616740, 0.089610, 0.802270, -0.054460, 1.581380, 0.518030, 0.489670, 1.091040, -0.397230,
0.363520, 1.371300, 0.056140, 0.395970, 0.123680, 12.694010, 1.978300, -0.679150, -0.018860,
0.149040, 0.220110, 1.042760, 0.951320, -0.079440, 0.005690, -0.586560, 0.617410, 0.568340, -0.653510,
0.632340, -0.660940, -0.161790, 0.174020, 0.361550, -0.176040, 0.043280, -0.843350, -0.330080, -0.812200,
-0.495320, 0.285160, -0.146180, -0.913700, -0.559240, -0.113330, -0.958360, -0.302780, -0.715320, -0.728700,
0.186020, -0.826000, 0.508780, 0.785570, 0.742810, -0.836500, -0.632010, -0.977820, -0.206930, 0.098870,
0.029190, -0.966020, 0.418910, 0.147060, -1.074260, 4.800280, -1.078380, 0.461070, -0.478960, -0.061740,
-1.498560, 0.117940, 3.978850, 0.839080, -0.506780, 1.708540, 0.003890, 0.818600, 1.489350, -0.581960,
-0.610700, 0.376390, 0.400810, -1.951480, 2.633600, 6.905700, 0.501150, -0.540050, -4.434320, 0.148450,
-3.852810, 0.738290, -0.023420, -0.660040, -2.015610, -0.676360, 0.235870, -0.471340, -0.330590, -1.068430,
1.000730, 0.550730, 0.825700, 5.719720, 0.060780, -0.412620, 1.790730, 0.123330, -1.211660, -0.093820,
-0.844880, 2.060190, 1.953660, 0.743200, 2.003450, 2.612370, -0.557620, 4.402570, 0.735320, 0.740130,
-0.453740, 0.028990, 0.601090, -0.306040, -0.076520, -0.533810, 0.671880, 18.418671, 0.246880, 0.052110,
-0.979630, 0.153370, 0.378020, -0.232370, -3.331120, 0.131830, 1.356250, -1.538840, 0.623490, 0.624520,
-0.106870, 0.577190, 0.674360, -0.138110, 0.551780, -4.061320, -1.238130, -0.209840, 1.070680,
0.927210, -0.773790, -0.795720, 0.119140, 0.744370, 1.152000, -0.316460, -0.122840, -0.402400, 0.483070,
-0.053140, 0.267300, -0.298460, -0.248740, -0.523060, -0.632890, -0.290540, -0.538390, 0.392110, 0.843650,
-0.855040, -1.629030, -0.101860, 0.338220, 0.839570, -0.161990, -0.865740, -0.136650, 0.523280, 0.813450,
-0.427440, 1.618160, 0.488940, 4.030990, -1.330630, 1.326780, 0.323820, -0.853480, 0.292290, -0.429460,
-0.644450, 0.037400, 0.363450, -0.469800, -0.263110, 1.343910, -1.982500, 0.216180, 0.192590, -0.679540,
-0.241380, -1.013830, 2.015980, 0.206350, -0.207050, -1.985300, 0.016260, -1.666510, 0.742550, -0.815990,
-0.972530, -0.212640, 0.263750, 0.368660, -0.883910, -0.129100, 1.032870, 0.513860, -0.458720, -0.533120,
0.551120, -0.434760, 0.083620, -0.753030, -0.689430, -1.975160, -0.019860, 0.060270, -0.300760, 0.416660,
-0.213980, 0.571910, -0.591300, -0.436000, -0.978730, -0.586900, -0.580740, -1.012760, -0.753330, -0.215180,
0.774930, 0.583530, -0.483460, 0.804180, -0.408880, -0.417140, 0.845440, -0.457940, -0.748800, 0.794630,
0.354480, -0.453120, -0.440590, 0.774170, 0.306250, 2.413510, 0.544460, -2.141300, 0.725820, 0.846960,
0.529440, 1.172440, 0.080030, 1.636970, -1.219840, -1.721950, 0.727600, -0.446950, 0.003060, -0.799900,
-0.834870, 0.277180, -0.722080, -0.030360, 0.765140, -2.698770, 1.168710, -0.123800, -0.114200,
0.492770, -0.104750, 0.322050, 0.147980, -0.628580, 0.461920, 0.105280, 0.981760, 0.804700, -0.064680,
0.671760, 1.020480, 0.218520, 0.180640, -0.348950, -0.492290, -0.275870, -0.853620, 0.158920, 0.143120,
0.502410, -0.917770, -0.936650, -0.202160, -0.685470, 0.601420, 0.027520, -0.566830, -0.546370, -0.559500,
-0.507500, 0.839040, -0.606230, 0.194250, -0.732570, -0.296750, -0.006570, -0.751930, 0.196000, -0.408050,
-0.602750, 0.539500, 0.615620, 0.551920, 0.912480, 0.118040, 0.178550, -0.638750, -0.158620, -0.154490,
1.007760, 0.599150, 0.227700, -0.064620, 0.375920, 0.501490, -0.829540, 0.607690, -0.753490, -0.162170,
-1.278190, 0.160980, 0.397050, 0.458300, -1.161010, -0.795280, -0.159160, -0.758890, 1.124040, 0.485960,
1.852270, 0.681060, -0.693930, -0.481620, 1.075620, 0.291140, -1.096590, 0.340360, 0.130410, 0.011470,
0.795660, -0.706140, -0.890970, 0.461680, 0.521390, 0.664890, -0.331210, -0.249840, 0.252820, 0.111690,
0.929760, 0.439320, 0.425590, 0.124010, -1.133290, -0.009130, -0.141320, 0.038510, -0.199830, -0.574250,
0.619900, 0.239330, 0.787520, -0.490910, 0.882480, -0.040180, 0.955910, 0.305700, 0.047950, -0.485200,
1.035320, 0.272610, -0.687890, -0.889080, -0.749730, -0.381090, -0.784570, -0.204810, 0.814130, -0.270140,
0.054030, 0.028900, 0.751860, 0.259680, 0.598690, 0.262780, -0.942110, -0.622800, 0.002600,
-0.115340, 0.370790, 0.279570, -0.154800, -0.066820, 0.262030, -0.054720, -0.286880, -0.386630, 0.195870,
0.531870, 0.199640, -0.376620, -0.644270, -0.481130, -0.441680, -0.432620, -0.971590, -0.590750, -0.696170,
-0.312240, -0.248530, -0.280170, -0.628920, -0.261330, -0.679870, 0.422740, 0.203450, 1.080500, 1.098690,
0.074450, 0.189760, -0.387600, 0.465420, -0.124690, 0.646110, 0.728060, -0.807320, -0.532330, -0.312200,
0.222730, 0.231320, -1.099490, -0.203000, 0.953970, 0.273390, 0.890460, -0.565350, 0.540550, -0.292170,
0.323730, 0.351550, -0.278710, 0.335010, 0.347330, -0.334700, 2.617000, 0.148290, -0.757460, 1.266560,
0.175070, 0.826630, -0.080880, 1.125250, -2.458120, 0.929720, -0.895500, 0.235520, 0.287770, -0.126220,
0.100630, 0.081860, 0.582480, 0.006610, -0.284660, -0.231730, -0.273750, -0.457970, -0.176620, 0.889800,
0.529850, -0.325870, 0.201020, -0.601580, -0.829030, -0.835830, -0.899910, -0.050760, 0.152810, -0.326490,
0.312130, -1.407150, -0.632470, -0.481670, 0.299220, 0.502590, 0.330700, -0.342420, -0.341230, 0.283700,
-0.323000, -0.394700, -0.581250, 0.194550, -0.532320, -0.101170, 0.777330, 1.871730, -0.175870, -0.512040,
-0.186910, 1.102680, 0.849090, -0.339680, 0.010520, 1.624160, -0.250200, -0.856280, -0.439450, -0.199950,
0.209500, 0.668500, -0.753280, -0.844290, -0.535930, 0.169560, 0.040100, 0.915880, -0.388890,
0.678120, 0.546210, -0.859120, 0.714480, 0.203620, -0.371370, -0.835790, -0.230360, 0.168880, 0.211730,
0.026770, -0.748030, 0.854710, 0.334080, -0.625270, 0.047640, 0.285810, -0.209950, -0.577930, -0.952130,
-0.646840, 0.572880, 0.273570, 0.394330, 0.016290, 0.977870, -0.677530, -0.053990, 0.212980, 0.466340,
0.174110, -0.335020, 0.084050, 0.466250, -0.517920, -0.534020, -0.426090, 0.482210, -0.400420, -0.148250,
-0.183750, 0.348470, -0.184390, 0.216200, -3.000260, 0.944600, 0.883920, 4.178350, -0.581790, 0.043560,
-0.856450, 0.630420, 1.542000, -4.353060, 0.859120, 0.569930, -0.876700, 0.549720, 1.795700, -0.924150,
-0.080780, 1.207530, -0.318600, 0.728650, 0.969090, -5.255290, 0.053570, 0.775850, -0.578590, 0.702180,
1.703140, -0.559250, -0.064170, -0.333390, -5.118950, 0.410780, -0.609960, 0.351580, 0.522890, 1.867890,
0.846050, 0.647550, 0.605270, -2.528980, -0.802890, -0.024140, 0.248270, 0.846270, -0.007520, 0.509790,
0.145350, -0.081400, 0.831420, 0.580480, -0.334070, -0.157010, 0.773620, -0.395940, -0.437730, 0.383960,
-1.435920, -0.520300, -0.858260, 0.917560, 0.446100, -0.847310, -1.551980, -0.105990, -0.898570, 0.232630,
-0.827740, -0.198050, -0.386760, 0.764670, 2.614370, -0.027850, -1.633910, -2.446550, -0.991160, -0.808500,
0.305720, -0.633700, -2.116920, -0.292890, 0.472660, 1.004150, -0.265250, 0.672970, 0.264920,
-0.275070, 0.419230, 0.473990, 0.211260, 0.534410, 0.375250, -0.399270, -0.676030, -0.391500, -0.322330,
0.363360, 0.176000, 0.375260, -0.630390, -0.710250, -0.389910, 0.480610, -0.098210, 0.198550, -0.606490,
-0.844430, -0.923440, 0.749210, 0.683080, -0.297120, -0.388570, -0.623540, 0.095940, -0.688900, -0.078070,
-0.487940, -0.544910, 0.733250, -0.023150, -0.460850, -1.082050, -0.110310, 0.978160, 0.353790, -0.127390,
0.296320, -0.423840, 0.538790, -0.823150, 0.540870, -0.585140, -0.789340, -0.854480, -0.024290, 0.283610,
0.042440, 0.057520, -0.007380, -0.905830, -1.360580, 0.543260, 0.631190, 0.092640, 0.387090, -0.824530,
0.549400, 0.233900, 0.755260, -3.280390, 0.482190, -0.050400, -1.110210, 0.174250, 0.203600, 0.619160,
-0.140960, -0.785390, -1.349070, 0.656250, -0.234760, -0.835050, -0.039290, 0.558800, 2.499940, 0.130280,
0.976630, 0.876800, -0.669290, 0.597190, 0.840460, 0.569810, 0.362810, -0.497840, -0.799480, -0.446630,
0.932520, 0.804370, 0.567720, -0.509770, 0.070120, 0.879570, -0.281840, -0.419980, -0.469290, -0.414210,
-0.530120, 0.286740, 0.590240, -0.722170, -0.519560, -1.507070, -0.642130, 1.905930, 0.183820, -0.320680,
0.740650, -0.860290, -0.791250, 0.066670, 0.924930, 1.210880, -0.889600, 0.860350, -0.716970, -0.025770,
0.432250, 1.540310, 0.483170, 0.074720, 0.288920, -1.995040, 1.264650, 0.811760, -0.423570,
-1.878860, -0.409800, 0.018700, 0.971170, 0.322700, -0.967670, -0.184580, -0.723970, 0.119470, 1.586940,
0.520660, -0.185150, -0.400940, -0.210480, -0.877910, 0.047730, -0.171810, 0.180100, -0.348460, 0.542280,
-0.779460, -0.780970, -0.483450, 0.678550, 0.361420, -0.391940, 0.310930, 0.616760, 0.510110, 0.181630,
0.312710, 0.985020, 0.244300, 0.784810, 0.776200, -0.797290, 0.511720, 0.158050, 0.783800, -0.027480,
-0.767320, 0.384380, 0.597050, 0.869540, -0.597300, -0.427880, -0.575280, 0.026020, 1.631850, -0.398130,
0.196480, 0.986120, 1.043670, 0.196780, -1.598780, -0.234760, -1.466720, -0.233970, 0.815870, -1.621810,
1.755500, 0.107340, -0.311290, -4.574280, 0.386780, -1.149210, -2.064480, -0.248680, -0.122220, 2.749160,
-0.778000, -0.385730, -5.492610, 0.398590, -0.793740, -1.602480, 0.171380, -0.363800, 0.182440, -0.792200,
0.256860, -19.442961, -0.629990, -1.500540, -0.637090, -0.261920, -0.044290, 3.966760, 0.228250, -0.136510,
-5.614620, 0.353600, -0.627500, 0.300600, 0.774830, 0.402350, -0.597690, 0.263550, 0.723910, -0.061520,
-0.014020, -0.548980, 0.579260, -0.854420, 1.272490, -0.903570, 0.807800, -0.895570, 0.629500, -0.149740,
0.500490, 0.268550, -0.776780, 0.590780, 2.564060, -2.883860, 0.959340, 0.523720, -0.757070, 0.390610,
-1.116490, -0.867690, -0.873750, 0.409420, 0.237900, -15.544070, 2.085130, 0.299010, 0.892550,
1.278530, -0.024570, 0.732080, 0.110230, 1.008640, 0.630220, -0.675500, 0.285730, -0.260210, -0.439820,
0.704510, -0.745470, 0.672460, 1.054820, 0.179880, 0.623700, -0.404040, -1.540840, 0.100350, -0.082840,
0.072170, -0.069470, -0.777170, 0.130900, 0.172030, 0.665500, 0.791910, 0.141010, -0.272440, -1.083680,
-1.177500, -1.157000, 0.111290, -0.996980, -0.811870, 0.298230, -0.328410, 0.226930, 1.172440, -2.854060,
-0.948080, -0.540000, 0.504130, 0.169150, -0.938260, 4.671200, -1.003250, -0.665590, -0.185990, 0.013940,
0.409060, -1.998050, 0.634780, -0.447050, 3.037680, 0.331050, -1.938360, -0.707500, 0.714980, 0.536570,
-0.633920, -1.887940, -0.269350, -1.299180, 1.630640, 1.156140, -0.191770, 0.185740, 0.653880, -0.108770,
-1.223890, -0.105060, -0.254280, -0.350880, -0.551040, -0.408430, -0.663140, -0.548480, 0.263690, -0.177910,
0.316620, 0.198480, 0.396990, -0.183390, -0.602260, 0.144310, -0.041210, 0.070410, -1.071740, -0.212530,
-0.211300, 0.658000, -0.882180, 0.863120, 0.609810, 0.450670, 0.599230, -0.796830, -0.327230, 0.516370,
-0.643320, -0.376560, 0.642840, -0.962650, -0.702630, 1.039990, 0.457620, 1.034830, 0.770440, 0.595970,
0.849670, -0.121860, 0.320710, 0.517480, -0.923600, -0.349900, 0.535080, -0.001530, 0.196890, 0.021550,
0.164000, -0.362610, 0.294900, 0.642470, -0.387050, -1.675040, -1.133030, -0.061560, -0.095320,
0.074340, -1.519720, -0.653060, 0.170770, 0.096180, -0.701890, 0.244480, -0.681790, 1.141480, -0.508180,
0.099380, -0.624820, -0.656110, -0.306510, 0.718690, 0.019700, 0.388880, -0.031360, -0.526150, 0.667440,
0.033800, -0.005480, 0.362320, 1.098020, 0.718970, 0.916210, 0.306430, 0.655790, -1.027310, 0.193440,
0.676700, 0.174690, -0.377270, -0.048260, 0.518250, 0.770500, -0.456790, 0.122710, -0.770450, 0.802860,
-0.701240, 0.652830, -0.900670, -0.586880, -0.500930, -0.165670, 1.139710, -0.567680, -1.072970, 0.416990,
0.559280, 0.900110, -0.270580, -1.246900, -0.309910, 1.718920, -0.308220, 0.472570, -0.014710, -1.400410,
-2.462500, -0.186110, -0.493930, 0.536870, 1.604730, -2.590110, 0.378090, 0.617380, -1.302320, -0.323470,
-0.604900, 0.517630, -0.797920, 0.509830, -0.276740, 1.106090, -0.772980, -0.471970, -0.318730, -0.928370,
-0.246140, 0.994410, -0.354890, 0.463570, 0.611400, 0.168910, -0.523830, -0.706600, -0.252990, 0.424010,
-0.305950, 0.423510, 0.369120, 0.758180, -0.750410, -0.023170, -0.662870, 0.896400, 0.603050, 0.343020,
0.389440, -0.021480, -0.165850, -0.214870, 0.193850, 0.619270, -0.890760, -2.715180, -0.586790, 0.581870,
0.587440, -0.210710, -0.521030, 0.464170, 0.458650, -0.504500, -0.586100, -0.225600, 0.810010, 1.201040,
-0.362730, 0.987290, 0.180670, 1.051000, 0.656000, -0.695550, -0.186770, 0.314520, 0.452910,
-0.176090, 0.404010, 1.183100, 0.219320, -0.124530, -0.679950, -0.877780, -0.368420, 0.227320, -0.477860,
0.372770, 0.202460, 0.667350, -0.419250, 0.272530, -1.008340, 0.728430, 0.950480, -0.815860, -0.025200,
-1.157260, 1.069600, -0.815440, -1.111490, -0.416250, -0.826550, -0.219300, 0.401640, -0.574760, -0.676980,
0.165210, -0.638240, 0.079730, 1.027780, 0.461320, 0.151410, 0.410810, 0.149440, -0.341200, -0.525370,
0.853210, 0.673930, 0.915090, 0.544720, 1.085590, -0.642720, -0.685930, -0.062870, -0.322410, 0.042630,
1.369670, 0.399760, -0.113440, -0.320070, -0.219710, 0.386540, -0.820260, 1.994610, 0.914030, -0.255380,
0.892440, 0.907740, -0.751660, 1.654870, 0.308610, -1.483460, -0.062670, 0.104370, 0.348120, -0.264320,
-1.312800, 0.070630, 0.651730, 0.914180, -0.807240, 0.404380, 0.337060, -0.568000, -0.866000, -0.412580,
0.342910, 0.485890, 0.341230, 0.854820, -0.707830, -0.471470, 1.111980, 0.198970, 0.909310, 0.314450,
0.545750, 0.094630, 0.433880, 0.831500, 0.993750, -0.144940, 1.021640, 0.614670, 0.732950, 0.407750,
0.983830, 0.817210, 0.161420, -0.391220, 0.078370, -0.625130, -1.012350, 0.105100, 0.229550, -0.015140,
0.856410, 1.048600, 0.508880, -0.458720, -0.914570, 0.135520, -0.556170, 0.512890, -0.913900, -1.317840,
0.049830, -0.797810, -0.024390, -0.747710, 0.640420, -3.216450, 0.468280, -0.594270, -0.614410,
0.109390, 0.433300, -0.226000, 0.155780, 0.632830, -0.861670, 1.002120, -0.339990, 0.412600, 1.052980,
0.152340, -0.337580, -0.238260, 0.825710, 0.615250, -0.048210, 0.176510, -0.265330, -0.151770, -0.570650,
0.759810, -0.284190, 0.968940, 0.201940, 0.794530, -0.390030, 0.261960, -0.125400, -0.653710, 0.053430,
-0.631030, -0.174740, -0.547060, 0.223640, -0.232940, -0.359090, 0.068550, 0.845780, -0.284180, -0.743880,
0.799840, -0.216400, 1.011080, -1.015840, -0.457290, 0.247150, 0.758850, -0.814680, -2.540350, -0.780480,
0.532330, 1.000710, -0.540030, -0.410890, -0.613150, 0.593940, 0.117170, 0.502390, -0.448910, -0.252150,
-0.041190, -0.082380, 0.556630, 0.967810, 0.300730, 1.816640, 1.027100, -1.249200, 0.421340, -2.590900,
1.124770, 0.233850, 2.673130, -0.585760, -0.392400, -0.978100, 0.301010, -0.800620, 0.084090, 1.193390,
-0.346150, 0.090760, -0.632260, 0.797760, -0.085780, -0.585860, 0.668430, -0.855780, 0.022170, 0.437750,
0.780510, -0.542880, -0.928590, 0.458480, 0.903790, 0.486520, 1.134840, 0.471250, 0.474530, -0.787130,
-0.184740, -0.079810, -0.420410, 0.054610, -1.250160, 0.189240, 0.944360, -1.386910, 0.765500, 0.838140,
0.489350, -0.078870, -0.510530, -0.656050, 1.474620, 0.242270, -0.674990, -0.089910, 0.295060, 0.134840,
0.392710, 0.052850, 0.394840, 0.545430, -0.425060, -0.394450, 0.074230, 0.522650, -0.506880,
0.508530, 0.212650, 0.571950, -0.267790, -0.075970, -0.788020, -0.315000, 0.422390, 0.860600, 0.117520,
0.765870, 0.824590, -0.634430, -0.213900, 0.330950, 0.852740, -0.343280, -0.498140, 0.760410, -1.059670,
-0.933960, -0.508680, 0.189200, 0.136000, 0.164670, 1.661160, 0.054330, -1.044870, 0.242040, 0.877970,
0.834470, 0.465220, -0.159360, 0.703000, -0.908000, -0.601860, 1.267580, -0.196370, -0.943780, 0.819970,
-0.492160, -0.821290, -1.685510, 0.545820, -1.196580, 4.942550, 4.449370, -0.123530, -0.904550, -0.024520,
-0.781320, -0.694710, -1.165560, -0.503100, -0.476220, 0.430440, -1.285550, 0.872710, -0.133380, 0.467950,
-0.620730, -0.557360, 0.708670, 0.967480, -0.251490, 0.705190, -0.683930, 0.555850, 0.164040, -0.381950,
0.896500, -0.169520, 0.952040, -0.519840, -0.609770, 0.033360, -0.475730, -0.642840, 0.199040, 0.801960,
0.193720, 0.592160, -0.550120, 0.288830, -1.003780, -0.217670, 0.235980, 0.121720, -0.533540, 0.088480,
0.682690, 0.673120, 0.287170, -0.343170, 0.505310, 0.716710, 1.221460, -0.114890, 0.155220, -0.122610,
0.088840, 0.217470, 0.264310, -0.889250, 0.537450, -0.987050, -2.755800, -1.519640, 0.049040, -0.296160,
-0.691160, 0.650780, 0.807050, 0.569570, 2.518310, -2.971100, 0.825310, 0.786180, 0.262540, -1.070010,
-0.848940, 0.398140, -0.891790, 0.566480, 1.291410, -3.152610, -0.487940, -0.676830, -0.059860,
-0.191620, -1.111730, 0.195600, -0.303210, 0.035640, -0.283650, -0.019450, -0.861590, 0.509610, -0.045170,
-0.662090, -0.479910, -0.890410, 0.410650, 0.672830, -0.742860, -1.073510, 0.507070, -0.452670, 0.519440,
-1.111220, 1.020350, -0.464970, -0.394560, -0.658560, -2.281820, 0.055210, 0.913880, 1.919190, 0.516390,
0.764420, -0.762820, -0.258450, 0.415530, -2.500170, 0.302980, -0.689370, 0.684950, -0.149050, -0.809260,
-1.541050, 0.645150, 0.807260, -0.831640, -0.039710, 0.100010, -1.574810, -0.318630, 1.135540, -1.504380,
-0.635780, 0.068990, 0.204200, -0.510030, -0.120090, -1.484580, 0.713330, 0.268470, -0.559940, -0.333090,
-0.774330, 2.054730, 0.627680, 0.773920, -1.936840, 1.055980, 0.652660, -0.528900, -0.647100, -0.865680,
0.485350, -0.099390, 0.535500, -1.105030, -0.086540, 0.236420, -0.541140, 0.920680, 0.398320, 0.865490,
0.082620, 0.226980, -0.177360, 0.605610, 0.072690, -0.655090, -0.206640, -0.546560, -0.216450, 0.551910,
-1.080780, -0.595650, 0.067580, 0.594300, 0.643780, -0.884550, -0.541880, -1.205580, 0.149860, -0.660060,
-0.350340, -0.411970, 0.531260, 0.096390, -0.100130, 0.769920, -1.138410, 4.057560, -0.456720, -0.019270,
0.523060, -0.522940, -0.233740, -0.352300, 1.061050, 0.151750, 0.265970, -2.282120, 0.191430, -0.661090,
1.281170, 1.362580, 0.684000, 0.089720, 0.538080, 0.797370, -0.889440, -0.238800, -1.714240,
-0.711700, -0.218690, 0.499510, 0.427430, -0.167230, -0.810020, 0.590240, -0.648890, 0.457280, -0.425790,
0.343300, -0.823760, -0.119660, -0.626160, 0.748110, -0.371840, 0.024490, -0.448690, 0.988920, 0.625610,
0.729970, 1.574940, -0.599630, -0.380280, -0.846530, 0.163090, -0.178900, 0.436320, 0.188850, 0.283850,
-0.341970, -0.789290, 0.582830, -0.181010, 0.713520, -1.916540, -0.565560, -0.567720, 0.716820, 2.597760,
0.408120, 0.825980, 1.178530, -0.212480, -1.957860, 0.914090, -0.141400, -4.237750, 0.407440, -0.016450,
-8.008310, -0.747110, 0.546950, -2.927690, 0.877860, 0.313290, -15.948060, -1.479380, 0.214900, -1.781120,
-3.952070, 0.511350, 1.010230, -1.317910, 0.359980, -0.670270, -4.456150, 0.704870, 0.359680, -1.288920,
-1.161200, -0.508140, -24.914829, 0.750540, 0.606460, 3.189070, -0.669610, -0.247970, -0.434470, -0.387770,
-0.657630, -1.516100, -0.902040, 0.932030, 0.647670, -0.632420, -0.836630, 0.912740, -0.266130, 0.718860,
-0.070500, 0.852330, -0.269350, 0.559950, -0.598020, 0.813670, 0.006190, -0.595100, -0.474680, -0.426230,
0.482650, -0.182500, 0.754680, -0.226920, 11.479170, 0.784730, 0.241200, -0.346370, 0.710360, -1.031230,
-0.461890, 0.826920, 0.135700, -1.529500, -1.261390, 0.157940, 3.086970, -0.120700, 0.356510, 1.191470,
0.291220, -0.615920, -0.839040, -0.673390, 0.577960, -2.232050, -6.409730, 0.325470, 0.295650,
0.199350, -0.469100, -0.845960, -0.486230, -0.747450, -0.796330, 0.588340, -0.010960, 0.806890, 0.152590,
-0.692940, -0.390060, -0.896670, 0.563850, 0.778910, -0.000190, 0.455820, -0.537420, -0.784340, 0.773690,
-1.013200, -0.636590, -0.575030, -0.754780, 1.194850, 0.361950, 0.790710, 0.106530, 0.876150, 0.443380,
-0.047800, 1.590600, 0.870240, -0.106220, -0.208710, 0.207290, -0.567150, -0.953450, 0.684930, 1.169260,
-0.493300, -0.546790, -0.203750, 0.659810, -1.120810, 0.503440, -1.463010, 0.221580, 0.063620, -1.313580,
-0.304840, -0.877130, 2.143350, -0.377100, 1.570700, 0.007170, 0.384980, -0.409290, 0.272090, -0.318010,
-1.665090, 0.412650, 0.885300, 0.877430, 0.121250, -1.623900, 0.154930, -0.020930, -0.885970, 0.071230,
2.942880, 0.583660, 0.071780, -0.054250, -0.568930, 0.482690, -0.928430, 0.872180, -0.248720, 0.959020,
-0.566150, -0.249430, -0.627020, 0.653740, 0.909220, -0.468310, -0.418210, -0.221360, 1.624440, -0.296830,
0.037850, -0.097130, -0.035640, 0.674190, -0.043340, 0.123290, 0.969470, -0.132880, -1.539260, 0.960850,
-1.915580, -1.156930, -0.342100, -0.046300, -0.710990, 0.418680, -0.384650, -3.367620, 0.610570, -0.626730,
0.369200, 0.855830, 0.162090, 0.590120, -0.896350, 0.413860, -0.358170, -0.711240, -1.032340, -4.502970,
-1.355440, -0.599730, -0.499190, -0.758820, 0.685480, 2.630780, 0.294710, -0.464470, -0.026490,
0.154640, -0.922710, -0.894560, -0.703600, 0.728190, 0.439730, -0.343730, 0.160230, -0.508350, 0.229810,
-0.312640, -0.078230, 0.465130, -0.066380, 0.419570, 0.878740, 0.271160, -0.881730, -0.532260, -0.360680,
-0.465900, 0.638930, -0.402240, -0.440670, -0.733950, 0.511310, 0.113500, -0.293760, -0.720740, -1.291460,
0.391460, -0.408790, -0.626400, -0.207610, -0.125720, 0.388940, -0.088390, -0.453190, -0.520590, 1.235720,
-0.085520, 0.430070, 0.903200, -1.718260, 0.239270, 0.128830, -1.195140, 2.409430, -0.096530, -0.021160,
0.391110, 0.017650, -0.495870, -0.508950, 0.646090, -0.944290, 2.742880, -0.641390, -0.840180, -0.438990,
0.036450, 0.757860, -0.794850, 0.072820, -0.111320, -0.931220, 0.867160, -0.580310, -0.618080, -1.088870,
0.246620, 0.362320, 0.860570, -0.768760, 0.300620, -0.660110, 0.630410, -0.309140, -0.803720, -1.081810,
-0.214450, -0.138190, -0.272110, -0.575830, -0.954200, 0.320410, -0.211250, 0.743150, -0.214090, -0.016580,
-0.312670, -0.646570, -1.019650, 0.219120, -0.992680, 0.700190, -0.351650, 0.502540, -0.871530, 0.442960,
0.817630, 0.509690, 0.974970, -0.395340, 0.407640, 0.589040, -0.215230, 4.643620, -1.152660, -0.289310,
0.619790, -0.887790, -0.671770, -0.466730, 2.170440, 0.392710, 0.381520, 0.224230, -0.040710, 1.391690,
0.875970, -0.455680, 0.656130, 0.059840, -0.295410, 0.815150, 1.668980, -0.449660, -1.797070,
-0.508560, -0.638960, 0.220950, -0.956200, 0.453810, 0.987480, 0.374950, 0.679720, -0.283420, -0.546070,
-0.300760, 0.420040, 0.798320, 0.624930, -0.448440, -0.586670, 0.235800, -0.659470, 0.573540, -0.438150,
0.352430, 2.251840, -1.002730, -0.879460, -0.429710, 0.566330, -0.561810, -0.595880, -1.009730, -0.160780,
0.100720, -0.751510, 0.129030, 1.233710, 0.284680, 0.455650, -0.218140, -0.404180, 0.678520, 0.815140,
0.668190, -0.661350, -0.171360, 1.140350, 0.856990, -0.097420, -0.011750, -2.042920, -0.634900, 0.335700,
0.338300, 0.391760, -0.173940, -0.086400, 0.221830, 0.389590, 0.307360, 0.023090, 0.736890, -0.584060,
-0.637040, -2.888790, -0.405330, -1.258930, 0.881220, -0.813760, -1.406620, -0.403000, -0.633580, 1.222020,
0.361810, 0.406880, -0.398750, -0.734780, 0.883340, -0.319800, 0.789360, -0.251700, 2.657190, 0.398300,
0.760670, -0.465820, 0.532190, -0.080880, -0.063530, 0.944220, 0.454610, -0.403070, 0.456330, 0.184990,
-0.413230, -0.749320, -0.041020, 0.185110, 0.115450, 0.518030, -1.792980, 0.642020, 0.287630, 0.517090,
-1.073850, 0.482490, -0.966930, -0.833040, 0.123800, -3.078570, 0.773520, 0.059930, 0.105150, -1.213360,
-0.554030, 0.278760, 0.840160, -2.029280, 1.881310, -0.622550, 0.425900, -0.369650, -0.063760, 3.160880,
-0.614490, -1.703980, -0.101540, 0.725220, 0.022030, -2.102860, -6.221660, 0.164940, 0.213200,
0.105950, 0.508750, -0.074440, -0.187110, -0.557360, 1.249930, -0.432950, 0.000630, -0.258450, 0.114810,
-0.539050, -0.294430, 0.648650, 0.120710, 0.444070, 0.276090, 0.743150, 0.729350, 0.705780, 0.797930,
1.210050, -0.738500, -0.721180, 0.820700, 0.301090, 0.155040, 0.069270, 1.005860, 0.870200, -0.624720,
-0.171510, 0.815470, -0.226090, -0.227910, -0.350690, 0.329970, 0.931490, 1.021040, 0.649840, -0.142820,
0.523050, -0.036840, 0.130530, -0.985550, -0.996140, 0.867200, 0.049250, -0.104430, 0.785900, 0.180410,
-0.843090, -0.596930, 0.685060, 1.142710, 1.229120, 0.900700, 0.070970, -0.293080, -0.365710, -0.814920,
-0.252550, 0.199280, 0.732500, -0.292750, -0.380020, 1.168490, -0.318690, -0.001650, 0.700670, -0.324870,
-0.503440, -1.417760, 0.105880, -0.258170, -0.610340, -0.180010, -0.194750, 0.183520, -0.422320, -0.125100,
0.454590, -1.033360, -0.312930, -0.184810, -0.052540, 1.094020, 0.267880, 0.729290, -0.128520, 0.212630,
-0.667550, -0.171810, 0.194310, 0.401380, -0.196190, 0.581320, -0.996530, 1.856070, 0.471170, -0.606090,
-0.379530, 0.162550, -0.100610, 0.156150, 0.018800, -0.474850, 0.440070, -0.399600, -0.433720, -0.702350,
0.762640, -0.517110, -0.071340, -0.855330, 4.878630, -0.169990, 0.630690, -0.544750, 0.114410, -0.167530,
0.635550, 0.576600, 0.967650, -0.779700, 1.032400, -0.222850, -0.051560, 0.646540, -0.087670,
-0.493550, 0.012550, 0.996390, 1.613340, 0.733620, -0.637130, 0.698230, 1.054620, -0.305260, -1.100680,
-0.853600, -0.221130, -0.103540, -0.155330, 0.813860, 0.409580, 0.542900, 0.102610, 0.923080, 0.488620,
0.355970, -0.333510, 0.534310, -0.193870, -1.536000, 0.100500, -0.534200, -0.590310, 0.372170, -0.290550,
-1.192550, 0.813890, 1.072460, -1.337920, -0.196730, 0.674420, -0.805130, -0.094910, 0.737930, -0.157820,
0.953150, 0.242610, -2.156790, 0.850880, 0.582290, -4.913580, -0.281940, 0.336920, -1.289570, -0.194550,
0.535560, -3.242480, 0.223630, -1.708540, 0.085860, -0.897770, 0.842310, -1.492930, -0.526500, -1.653890,
-0.063580, 0.123000, -1.158090, -4.384940, -0.146970, -2.580920, 0.757600, 0.256110, 0.013040, -0.305910,
-0.781500, 0.309810, -1.974000, -0.665570, -0.199330, 0.058090, 0.388250, 0.283010, 2.035490, 0.310000,
0.770110, -0.526510, 0.555650, 0.257210, -0.561740, 0.544070, 0.039190, 1.277970, 0.067070, -0.114490,
-1.005630, 0.087820, 0.264060, 1.533600, 0.146370, 0.441260, -1.665700, 0.306950, 0.304390, 0.149410,
-0.757560, -0.288080, 0.307070, -0.990800, 0.187210, 0.149450, 1.555790, -0.167830, 0.686930, -1.190590,
-0.616520, -0.705750, 0.578920, -0.851040, -0.436480, -3.695470, -0.082850, -0.805010, 0.206490, -0.269210,
0.680420, -1.166940, 0.669330, 0.978700, -0.567390, 14.456410, -1.618300, -0.411340, -0.012400,
0.575730, -0.253330, -0.814480, -0.493470, 1.670450, 0.098620, 0.064870, 0.186410, 0.167610, 0.873700,
-0.835380, -0.032270, 0.678750, -0.652940, 0.202340, -0.089000, 0.999390, -0.764660, -0.555820, -0.171340,
-0.067530, 0.553830, -0.270640, 0.166750, -0.142970, -0.706790, -0.526950, 0.876980, -0.403580, -1.008130,
0.427590, -0.058360, 0.720670, -0.399040, 0.667810, 0.602350, -0.067750, 1.008890, -0.315330, -0.412300,
0.682610, 0.219320, -1.229800, -0.414580, -0.037410, -1.004840, 0.499590, -0.836760, -0.978190, -0.510290,
0.621150, 0.293680, -1.615110, 0.232400, -5.189900, 0.451070, 0.875020, -0.319930, -0.785530, 0.241860,
2.585860, -0.215950, 0.565490, 0.120590, 0.470520, 0.434200, 0.603550, -1.001570, -0.268900, 0.332450,
-1.368530, -0.945440, -0.568830, -0.015320, 0.659250, 0.075150, 0.441240, 0.815110, 0.728500, -0.025810,
0.106260, 0.212670, -0.171020, 0.811240, -1.047820, 0.942310, -0.485040, 0.385110, -1.855310, -0.453090,
-0.431920, 0.452950, -0.642220, 0.036490, -0.425550, -0.754580, 0.007520, 0.589610, -0.333410, -0.571300,
0.075060, 0.826690, -0.916300, 0.374830, -0.595380, -1.636360, 0.145180, -0.649600, -0.153440, -0.104710,
0.652870, -0.019530, -1.205530, 1.197820, 4.356210, 0.160130, -0.495400, -0.402590, 0.670480, 1.033050,
-0.343980, -0.573170, 0.809540, -0.292320, -0.835150, 2.655810, 1.096550, 0.417420, 0.495570,
0.455340, -0.052930, -1.098360, -0.278350, 0.665420, 0.155860, 0.773540, 0.238680, -0.945920, -0.175960,
-0.249310, -0.540960, -0.029560, 0.739660, 0.591590, -0.671400, -0.557600, 0.251290, -0.296030, -0.114740,
-0.003750, 0.724140, 0.750860, 0.254230, -0.548990, -0.283340, -0.594390, -0.546200, 1.164110, 0.400230,
-0.676680, 0.809240, -0.960410, -0.107330, -2.966530, 0.162370, 0.533980, 1.317580, 0.332870, -1.810920,
-0.677070, 0.516350, 0.790320, -0.662950, -0.352240, 0.211240, -0.891590, -0.327760, -0.692690, -0.309330,
-0.454010, -0.902620, -0.958810, 0.384190, 1.697810, -2.283040, -2.096390, 0.109090, -0.574610, 0.456970,
-0.748160, 0.441640, -0.235460, 0.109310, 0.575200, 0.376970, 0.531450, -0.920030, 0.556480, 0.390210,
0.598850, 0.503050, 0.089790, 0.441030, -0.353500, -0.090070, 0.544930, -0.489980, -0.654620, 0.471610,
-0.444900, 1.027960, -0.201330, -0.591020, 0.920940, -1.031050, 0.232890, -0.530390, 0.240660, -1.054930,
-0.108990, -0.972450, -0.752120, 0.218690, -0.624230, -0.395490, 1.169860, -0.032810, 0.199920, -0.833870,
0.045930, -0.283280, -0.797950, 0.968160, -0.031390, 0.208600, -0.659400, 2.723540, 0.894910, -0.511650,
0.262050, 0.339190, -0.421620, 1.017320, -5.578860, 3.053180, -0.463930, -2.122400, -1.011710, 1.318640,
0.369250, -0.645750, 0.460000, 0.582110, 0.731240, 2.571050, 1.257370, -0.649240, 1.420690,
-0.650460, 0.442480, 0.298900, -0.205870, -0.939600, 0.426750, 0.683960, -0.617690, -0.689150, -0.078340,
-0.379110, -0.933310, -1.423850, -1.191750, 0.193310, -0.234250, -0.598740, 0.660600, 0.008350, 0.247140,
-0.123870, 0.058220, 0.100440, 0.195990, -0.820020, -0.854620, -0.641400, 0.611550, 0.442740, -0.218300,
-0.059360, -0.036260, 0.162550, -0.931490, -0.315100, 0.560290, 0.266810, -0.772370, -0.782560, -0.859840,
0.642140, 0.335100, 0.112750, -0.413500, -0.195080, -0.661780, 0.131290, 1.957770, 0.631160, -0.116490,
0.440220, 0.471170, -0.625470, 0.712720, -0.952120, 0.507410, 1.601620, 0.077690, -1.120860, 0.726640,
1.349640, 0.369210, 0.692400, -2.208990, 0.580100, 1.353820, -0.109060, -1.101480, 0.535010, 0.538600,
0.529780, 0.602050, -0.976020, -0.042770, 0.328530, 0.491180, 0.918920, -0.751710, 0.598500, -0.851450,
-0.329280, -0.674480, 0.302230, 0.889340, -0.114640, 0.241570, 0.716110, -0.422790, -0.069860, -0.270300,
-0.446160, 0.762190, 0.341880, -0.214330, -0.448160, -0.717270, -0.584500, 0.395240, 0.392840, 0.110510,
-0.057240, 0.017630, -0.015950, -0.540120, -0.503340, -3.455490, -0.827060, 0.107620, -0.066600, 0.664630,
0.430710, 0.469270, -0.131950, 0.378770, -3.244980, -0.154350, 0.047810, 0.067630, -0.883390, -0.027180,
-1.029440, -0.427410, -0.930040, 0.441520, -0.319310, -1.021410, 1.429900, -0.150120, -0.030320,
2.690730, 0.338900, -0.178680, -0.057450, 1.446140, -0.295180, -0.010260, -0.515740, 0.294280, 0.067430,
-1.435790, 0.597630, -0.331310, 0.766660, -0.901400, -0.810170, 1.451290, 0.380000, 0.002630, -0.199830,
0.352530, -0.582380, 0.202400, 1.051320, -0.064600, -0.421440, 0.161480, -0.247700, 0.276040, 0.447460,
0.957080, -0.628440, 0.395330, -1.109510, -0.590330, 0.699180, -0.146210, 0.271840, -0.323950, -0.318780,
0.955820, -0.225120, 2.147520, 0.534160, 2.915620, -0.306290, 0.333050, 2.266460, -0.992780, -1.250930,
-4.276650, -0.369910, -2.403860, -0.661030, -1.354310, 0.854430, 1.407140, -0.622170, -2.438290, 1.102230,
-1.522160, -2.623490, 3.086650, -1.519260, 0.385570, 3.056370, -0.054070, -0.047130, 1.893740, 0.100920,
-1.326510, -0.069770, 0.067600, 1.469000, 9.921110, 0.251950, -0.582250, 0.769300, 0.586550, -2.270960,
0.066350, -1.261440, 0.483150, 2.743640, -0.397030, -0.212920, 0.659910, 1.785150, -2.828870, 0.415150,
0.087770, 5.895410, -0.545780, -0.024310, 3.662700, 1.517310, -0.615580, -2.615510, 0.068810, -0.507960,
-2.674400, 1.475760, -1.475670, 0.784960, -1.620180, -0.623690, 2.060930, -0.561590, -0.341590, -0.338790,
0.736580, 0.730460, 0.055030, -0.718990, -1.557700, -0.923350, 2.560450, -1.213090, -0.734150, 0.108250,
3.990420, 1.155150, -0.136980, -0.367630, 1.988150, -1.175460, 1.615560, 0.415600, -0.726790,
0.481710, -0.137060, -0.411960, 0.537680, 0.484680, 0.128680, 0.809460, 0.245830, 0.524240, 0.364730,
-0.792510, 0.582920, -0.099180, 0.498070, -0.283920, -1.058720, 0.500080, 0.228140, -0.556080, 0.720550,
0.552460, -0.256380, -0.180950, -0.436300, 0.533220, -0.200300, -1.048640, 0.389990, -0.454420, -0.762630,
1.146810, -0.546130, 0.343540, -0.267800, -0.274200, -0.422440, 0.148160, -0.576970, -1.105080, 0.898110,
0.624120, -1.127640, -0.108320, 1.191320, -0.119470, 0.859280, 0.681560, -3.622800, -0.339170, 0.708710,
-0.492050, -0.963170, -0.839020, 0.725230, -0.216880, 0.896630, 0.133800, 0.432480, -0.545830, -1.049110,
-0.543690, -0.765620, 0.070860, 0.168560, 0.398650, 0.409720, 0.337620, -0.730210, -0.832210, -0.472290,
-1.110100, 0.786840, 0.605540, -0.965300, 0.340240, -0.170100, -0.831610, -1.016480, 0.048820, 0.299040,
0.283310, 0.067510, 0.783000, 0.377680, -0.738030, 0.475920, -1.045560, 0.556210, 0.425650, 0.730430,
-0.199680, 0.346550, 0.557500, -0.415170, -0.138770, -0.487890, -0.621650, -0.067030, -0.209350, -0.342840,
-0.802180, -0.775380, -0.170650, -0.123030, -0.042800, 0.868430, -0.720310, 0.747010, -0.515130, 0.588010,
-0.447500, 0.848420, -0.527980, 0.564360, 0.297050, -0.552890, -0.887320, -0.397180, 0.612300, -0.210560,
-0.920280, -1.048440, 0.863330, 0.696660, 0.648950, 1.073140, -0.539030, -0.065600, 0.851400,
0.185490, 0.050540, -0.281480, -0.877670, -0.231540, 0.814020, 0.497500, 0.342180, -0.456520, -0.375670,
-0.470660, -0.466500, 0.890840, 0.823450, -1.098380, -0.807220, 0.347500, -0.224130, -0.073680, -0.541630,
0.795180, 0.470610, 7.054180, -0.562960, -0.283550, 0.773690, -0.796820, 0.545250, -0.093510, 2.791880,
1.159500, 0.399720, 0.522440, 1.647020, -2.179800, -0.937250, 0.492370, -0.620580, 7.585370, -0.094790,
-1.143520, -1.547110, 0.106710, -1.039960, -3.788560, 0.694780, -16.959650, -6.784300, -0.248980, -0.909790,
-5.489680, 0.825970, 2.710690, -1.317180, -0.154560, -1.360620, -29.639370, -0.286690, -2.573760, -2.523390,
0.185230, -8.575030, 0.384250, 0.489510, -0.282400, -1.568840, 1.311620, 4.623370, 0.711410, -0.537080,
-0.732070, -0.365310, 0.635620, 3.923290, 0.554920, -0.234120, 1.362010, -0.506780, 0.223910, -4.230940,
0.386790, 0.046590, -0.937030, 1.007740, -0.940230, -4.317910, -0.478160, 0.207110, -0.705070, 0.180570,
-0.302140, 0.391580, 0.473200, 0.565930, 0.453630, 0.936460, -1.504090, -1.103700, 0.256670, -1.042220,
-4.094120, 0.842060, -0.104520, -0.864010, 0.180220, -0.445660, -0.704910, 0.935780, 0.676120, -0.442380,
-1.054950, -1.080590, 0.711340, -0.831630, 0.887940, -0.217320, 0.417660, -0.639750, 0.240220, 8.755920,
4.630370, -0.919050, 0.368950, -1.068940, 0.320480, -0.709990, 1.089190, 0.906840, -0.921420,
-0.881750, -0.720420, 0.031480, 0.271760, 0.593870, -0.198130, -0.290060, -0.794220, 0.532100, 0.960780,
2.080830, -0.768420, 0.055740, -0.505310, 0.109560, 0.408630, -9.662260, -1.441330, 0.524400, 3.941880,
0.802040, -0.716290, -3.057360, 0.442850, -0.027170, -12.071640, -2.140300, -0.871700, 5.359690, -1.088880,
0.437810, -7.299270, -1.032410, -0.231540, -7.207970, -1.317490, 0.692720, 7.275730, -2.968650, 0.639720,
0.804100, 0.152330, -0.569280, -3.382600, -0.872720, -0.320280, -1.181010, -0.993910, 0.384850, 0.601250,
-0.443820, -4.306600, -2.698360, -0.766490, 0.006080, -1.073720, 0.502720, 0.912410, -2.723640, 1.008450,
0.170960, 0.764760, 0.064650, 0.210360, 0.484380, 1.534210, -1.368150, -0.818520, 1.169530, 1.919240,
1.554820, 0.697340, -0.411110, -0.456980, -0.143490, -0.321810, 0.821320, -0.177440, -1.255630, -1.049850,
-0.323070, 0.490310, 2.685110, 0.183030, 0.031130, 0.336440, -0.148980, 0.024170, -0.501410, 0.561810,
-0.957560, 0.352920, 1.064790, 0.659760, 0.782070, -0.521890, 0.858500, -1.203780, -0.378610, -0.101690,
-4.824370, -0.307720, 0.549120, -0.557520, 0.669130, 0.674050, 3.420390, -1.704700, 0.490580, -0.768560,
0.714740, -0.538680, 0.649110, -0.166760, -1.257050, 0.001520, 0.532130, -4.933890, -0.369640, 5.021440,
-0.161720, 0.570840, -0.261510, -0.589280, -0.577220, 2.008910, -0.190640, -0.890620, -0.226100,
-0.606080, 0.313380, -0.542650, 0.989500, -0.344190, 0.553880, -0.722370, -0.294930, -0.283800, 1.164700,
-0.071050, 0.915040, 0.503900, -0.560010, 0.656480, 0.322320, 0.644550, 0.712550, -0.310890, 0.409220,
0.435190, 0.724950, -0.292170, 0.100000, -0.519820, -1.191240, -0.117410, 0.910770, -0.026580, -0.755550,
-0.276160, -0.567970, -0.413530, 0.649470, 0.746540, 0.155720, 0.367270, -0.948550, -1.244330, -0.284640,
1.096080, 0.107360, -0.221820, 0.732870, -0.865300, -0.108530, 0.274730, 0.435490, 0.448300, 0.724960,
-0.923410, 0.155780, 0.543510, -0.934400, -0.622600, 0.579650, -2.245780, 0.146810, 0.682360, 0.129480,
0.252320, -0.745200, -0.160490, 0.923810, 1.737980, -1.550910, -0.299900, -0.406850, -0.777410, 0.083090,
-0.463780, 0.123080, 0.956070, -0.542760, 0.770610, -0.669880, 0.940730, -0.352170, -0.002380, -0.311860,
0.544700, -0.477620, -0.486470, 0.485340, -0.425680, -0.316540, -0.917430, 0.446600, -1.436660, -0.154260,
0.236190, -0.024230, 0.374330, -0.822180, 0.103520, 0.380230, -1.234270, -0.011650, -0.504710, -0.127960,
-0.097490, -0.763190, -0.497730, 0.489870, 1.423820, -0.073810, -0.118890, 0.921190, -0.365780, -0.005650,
0.910470, 0.125450, -0.831970, -0.091030, -0.349950, -0.112460, -0.292210, 1.511190, 0.535480, 0.773330,
0.499320, 1.019830, 0.836970, -0.641550, -0.827550, 0.256320, 0.015880, -0.102520, -0.287770,
0.248910, -1.638640, -0.321610, -0.281090, -0.117470, 0.793780, 0.507680, -0.830750, 0.060220, 1.158510,
-0.350200, 0.679420, -0.881450, -0.444220, 0.792550, -0.637660, -0.002850, -1.023300, -0.506500, -0.429740,
0.330710, -0.951760, -0.191320, -1.226600, 0.144370, -0.654300, -2.624130, -1.196930, 0.286840, -0.302220,
0.510800, -0.518690, 0.258490, -0.311990, 0.814830, 0.581840, 0.462880, 0.198810, -0.507620, 3.116510,
0.513130, 0.319900, -0.053790, 0.140640, -1.222650, 0.251850, 0.923830, -0.521720, -0.304160, 1.510490,
-0.847450, 2.713720, 0.883610, -1.380520, 0.733340, 1.403070, -1.294510, -0.907320, 0.991000, 0.248090,
1.520510, -0.983870, 0.105870, -0.196010, -0.009980, -0.414630, 1.396940, -1.211170, -0.516080, 2.187370,
0.214650, 0.165540, -2.417190, 0.609080, -0.546880, -0.484560, -0.297170, -0.488510, 1.446720, -0.378630,
-0.151220, -0.854150, 0.744520, -0.619090, -0.213200, -0.669540, -1.021700, 0.820380, 0.899060, -1.077810,
-1.801380, 0.432630, -0.740300, -1.425600, -0.804570, 0.288550, -1.903870, -0.031480, 0.106950, 0.715370,
-1.107390, -0.508460, 0.394740, 0.430970, -0.537330, -0.564340, -0.297680, 1.038160, -0.516390, 0.766240,
0.485800, -0.406370, -1.005630, -4.618750, 4.182530, 2.108220, 0.496720, -0.512510, 0.140870, -1.021750,
-0.796690, 0.329160, -0.588900, 0.585070, -0.602050, 0.981930, -2.955330, -0.643290, -0.605050,
-1.096770, -1.857140, 0.645290, 0.826020, -0.247940, 0.821920, -0.336340, 0.074640, -1.503300, 0.152680,
-0.181360, -0.846560, 0.279950, 0.262210, 0.284690, -1.859890, 1.204210, -0.160380, -0.707770, -0.486040,
-1.039380, -0.951710, -0.262910, 0.467750, -0.679380, 0.873450, 1.604250, 0.900720, 0.180420, -0.418600,

-0.875930, 0.617790, -0.473830, -0.595190, 0.633930, -0.830930, -0.304360, 0.500330, 0.696170, -0.820630,
-0.060410, -0.191470, 0.916550, 0.379920, -1.610110, 0.824200, -1.209740, -1.385090, 0.552700, -0.138100,
-0.013050, 0.690730, -0.788070, -0.827870, 0.178540, 0.213390, -2.079410, -2.574250, -0.148670, 0.765010,

0.715660, 0.317380, -0.274860, 0.610640, 0.381120, -0.683540, 0.149140, -0.577660, 0.764950, -0.089480,
-0.235020, -0.657160, 0.151510, -0.863450, 0.435500, -0.887240, -0.739640, 1.010930, -0.260590, -0.777020,
0.145680, -0.521450, -0.019640, 0.890050, 0.808530, -1.170420, -1.243180, -0.245350, -0.225900, 0.109730,

-0.528460, -1.287230, -0.416220, 0.197870, 0.384840, -0.863620, 0.569110, -0.796290, -1.547810, 0.133370,
-0.509880, 0.256390, 0.297070, 0.356390, 0.717260, -1.442070, 0.829350, -0.311590, -0.430930, 0.636300,
-1.437070, -1.215950, 0.711210, -0.637860, -1.189920, -0.152010, 1.496610, 0.333180, -0.142310, -0.610840,

0.292850, -0.220780, 0.947670, -0.472890, -0.425160, -0.290680, -0.112320, 0.435880, 0.754170, 0.599740,
0.731730, -1.034190, -0.890700, 0.074490, -1.686740, 1.931600, -1.072300, -1.269470, 0.174750, -0.509240,
0.253810, 0.507150, -0.648740, -0.387830, 0.648940, 0.563240, -1.540110, -2.236670, 0.438730, 0.660600,

0.011450, 0.313240, -0.533540, 0.615660, -0.539260, 0.711620, -0.799300, 0.333240, -0.356550, -0.896190,
-0.138160, 0.999570, 0.257840, -0.221240, -0.046190, -1.735830, -0.631200, 0.674120, -0.366840, 0.486140,
0.300830, 0.556240, -0.499500, 0.580760, 0.557230, -0.676690, -1.514680, -0.107230, -0.781270, -0.358180,

0.178240, -1.142030, -0.593970, -0.663460, 1.025910, -0.353460, 1.191230, -0.956960, -1.515670, -0.855000,
0.243330, 0.982820, 0.640240, 0.896950, 0.816220, -1.369360, 0.357870, 0.850850, -1.237780, -0.178270,
-1.085910, -0.710510, 0.388140, -1.344000, -1.267550, -0.219160, 1.214360, -0.818080, -0.083240, -0.428020,

0.624250, -0.489470, 0.340380, 0.196030, -0.714580, -1.516380, 0.104550, 0.994690, 0.517710, -0.178870,
0.151450, 0.567460, -0.911560, -0.294140, -1.347250, 1.096860, -0.922120, -0.269370, 0.316250, 0.485010,
1.120580, -0.486070, -0.698680, -0.366160, -0.496620, 0.205940, -1.179450, -1.014450, 0.162930, 0.856160,

0.458650, 0.745670, 0.792530, -0.477810, 0.036760, 0.163830, -0.977530, 0.423620, -0.445210, -0.045450,
-0.637660, -0.628920, 0.107710, 0.134900, 0.191080, -0.763880, -0.392000, -0.283390, -0.420920, 0.174260,
-0.366020, 0.622150, 0.167880, 0.897920, 0.484180, 0.264010, -0.897680, 0.765670, -0.935810, -0.722580,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.696970, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.305860, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, 0.003570, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.060030, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.525330, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.157230, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.701850, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.475160, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.158890, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.864180, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.957380, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.298250, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.501430, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.072910, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.401880, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.151340, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, 0.065020, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.440660, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.331420, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.802840, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.273750, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, 0.071170, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, 0.146100, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.316400, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.728430, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.566840, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, -0.047540, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.877030, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.301450, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.415740, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.246780, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.773380, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.318650, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.472750, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.897270, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.845000, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.235650, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.547710, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.864630, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.00930, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.00000, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
0.72999, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42833, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
0.31863, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
1.04375, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.32614, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.01651, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.36574, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
1.33626, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.40157, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.32850, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.37720, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
1.38423, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
1.40166, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
1.17796, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.70190, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.00000, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.01555, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.42810, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.00004, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.86185, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
1.10698, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
0.80834, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
0.94287, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.23978, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.00291, 0.500000, 2,
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
