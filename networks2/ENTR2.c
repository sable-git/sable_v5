/*********************************************************
  TMPENTROP2_1_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:16:16 2004
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
0.603630, -0.320670, -0.179810, -0.681880, 0.462370, 0.001290, -0.663820, 0.738910, -0.499080, 0.773440,
0.328560, 0.027590, -0.419190, -0.327060, 0.674230, 1.126400, -0.086760, -0.509900, -0.737860, 0.913180,
0.376320, 0.413140, -0.872500, 0.966340, 0.352050, 0.634140, 0.539330, 0.748760, 0.618810, 0.161040,
0.079940, 0.678270, 0.045940, 0.603980, 0.075340, -1.111780, -0.122960, 1.005990, -0.672980, -0.708440,
-0.214120, -1.322690, 1.223940, 2.501100, 0.374590, 0.382350, 2.367440, 0.111110, -0.521020, 0.496600,
-0.753300, -2.092340, 0.154810, 0.392240, 5.804980, 1.353970, 0.506890, -1.439800, 0.917200, -0.387770,
-1.759050, -0.666760, 1.070330, 0.042420, -0.006190, -0.643520, 0.901540, 0.330730, 0.669200, -0.017990,
1.085940, 0.092430, 1.297330, 0.000220, -0.365630, 0.150170, -0.568300, -0.426010, -0.490780, 0.045670,
0.530450, 1.211960, 0.218190, 0.218370, 0.832030, 0.770580, -0.288270, -0.518190, 0.265560, 0.462260,
0.160970, -0.898860, -0.295430, -0.223820, -0.631560, -0.046900, -0.223350, -0.291460, -0.674720, 0.118790,
1.000430, -0.572470, -0.778530, -0.097480, 0.431610, 0.186510, 0.278480, -0.348770, -0.268770, -0.142870,
0.650660, 0.807140, 0.319850, 0.624200, 0.401830, 0.376730, -2.847330, -0.986050, -0.130350, 0.637630,
-0.720810, -1.021200, -2.089120, 0.920260, -0.647090, -0.398350, 0.687200, 0.635910, 0.412430,
0.953910, 1.021200, 0.623310, 0.633080, 0.944510, 0.910340, 0.203450, 0.661560, -0.027260, 0.755260,
-0.687880, -0.071130, -0.515610, 0.342180, -0.121760, 0.685590, -0.381540, 0.666230, 0.667650, 0.227020,
0.259850, -0.863630, -0.114170, -0.728100, -0.124410, -0.608110, 0.162340, -0.107190, 0.303780, 0.983610,
0.904380, 0.835310, 0.624590, -0.396980, -0.069330, -0.705450, -1.090670, -0.978600, -0.751940, -0.621130,
-0.225090, -0.493880, 0.892700, -0.298180, -0.662790, 0.257370, -0.231190, -0.489460, 0.507580, -0.328790,
0.557480, -0.338660, 0.138310, -0.538590, 0.650920, -0.916930, 0.144860, 0.345470, 1.062980, -0.676550,
-1.049790, 0.437820, 0.395010, 2.481550, 0.272150, -1.060480, 0.528590, 0.129440, -0.277880, -1.156960,
0.414150, 0.605770, 0.333540, -1.429170, -0.356330, 0.627510, -0.836620, -0.508740, -0.293750, 0.935540,
-0.642410, 0.639960, 0.562250, 0.324380, -0.573560, -0.215900, 0.708860, 0.724460, 0.658370, 0.299880,
0.011290, -0.716210, -0.585990, 0.336190, -0.516770, -0.381660, 0.107580, -0.908390, 0.078020, -0.017810,
0.117330, -0.372600, 0.913930, 1.736160, 0.266640, 0.636710, -0.294520, 0.503590, -0.457330, -1.002380,
0.503610, 0.342750, -0.083490, -0.128340, -1.104230, -0.200820, 0.226810, -0.060160, -0.771430, 0.779320,
-0.089610, 0.458950, -0.764080, -0.066570, -0.337470, -0.631750, 1.193010, -0.765840, 0.513290,
-0.171100, -0.524160, 0.205040, -2.014650, -1.444600, -0.738120, 0.351240, 0.113860, -0.689020, -0.309410,
-0.958970, -0.875390, -0.042210, -0.519290, 0.359070, -0.558430, 0.134610, -0.579800, 0.133980, -0.359680,
-0.360340, 0.330970, 0.258420, 0.221960, 0.906690, -0.787390, 0.587120, -0.742150, 0.130400, -0.543700,
0.291000, -0.422810, -0.443210, -0.563310, -0.932470, -0.055770, 0.399720, 0.538230, -0.130430, -0.782250,
0.716810, 0.480680, -0.302350, -0.644570, 0.310200, -0.362270, 0.708320, -0.665720, -0.694520, -0.216320,
-0.617110, 0.647570, -1.200620, -0.401640, -0.292960, 0.068070, -0.421220, 0.515860, -0.206820, 0.530790,
-0.484760, -1.375850, 0.435440, -0.293350, -1.048870, 0.985290, 0.582050, -0.841950, 0.647880, 0.205640,
1.632230, -0.570930, 0.380980, -0.277130, -0.901700, -0.257180, -0.204940, 0.964850, 0.869310, 0.597010,
0.418100, 0.173420, 0.252460, 1.029250, 1.054210, -1.057510, 0.620000, -0.050910, 0.786530, 0.062040,
0.652260, 0.470500, 0.141480, -0.746370, -0.074640, -0.742140, 0.916700, -0.503280, 0.353370, 1.179390,
-0.277420, -0.668800, 0.189800, 0.398560, -0.863690, -1.831660, 0.087930, -0.406910, 0.406460, 0.196260,
0.891350, -0.863540, 0.871360, 0.304390, 0.639280, 0.106740, -1.395980, 0.828980, -0.722550, -0.237200,
0.625930, 0.571160, 0.160270, -0.835770, 0.250700, 0.533580, 2.065440, -0.021900, 1.446660,
-0.337060, -0.605720, 0.641110, 0.753110, 0.268990, -0.636290, -1.095760, 1.004680, 0.805000, -0.766820,
0.696350, -0.689220, -0.627730, 0.441100, 0.086740, -0.093820, -0.256190, 0.649620, -0.498060, -0.038980,
-0.507950, 0.164040, -0.069220, -0.391980, -0.998020, 0.548160, -0.768550, 0.051290, -0.725780, 0.201850,
-0.485910, -1.037540, -0.345040, 0.796120, 1.723190, 0.739990, 0.397860, 0.769320, -0.087580, -0.061820,
1.244580, 0.300060, -1.049780, -1.058650, 0.658670, 0.762110, 0.668260, 0.030140, -1.262100, -0.931550,
-0.000450, 0.631320, -2.106270, -0.494300, -0.907620, -0.366210, 0.824700, 0.725930, 2.764750, -0.420350,
0.316260, 0.908530, 0.747810, 0.951730, 1.572450, -1.283080, -0.452980, -0.294310, 0.762000, -0.832590,
0.312470, -0.866460, 0.506830, 0.979290, -1.020770, 0.470940, -0.706920, 0.743610, 0.159540, 0.248890,
-0.542650, 1.072520, -0.035100, 0.685500, -0.252270, 0.456810, 0.340560, -0.068440, 0.619840, -0.224590,
-0.965070, -0.127930, 0.830980, 0.684370, -0.689090, -0.705050, -0.415820, 0.058520, 0.932760, 0.023960,
1.126920, 0.726320, 0.400710, -0.103580, -0.673500, -0.592570, -0.121500, -0.105760, -1.112230, 0.314670,
-0.694660, 0.282430, 0.908410, 0.823690, 3.104290, -0.770320, -2.733400, -0.203240, 0.408030, 0.872390,
0.802510, -0.493960, -0.464050, 0.486360, -5.168180, 0.825060, -1.159640, -0.167000, -0.080190,
-0.155390, 0.021300, -0.308980, -0.090740, 0.541150, 0.045610, 0.428910, -0.097400, 0.530720, 0.854410,
-0.295200, 1.212020, 0.781560, 0.910250, -0.384410, 0.643000, 0.762990, 0.607920, -0.388570, 0.907530,
-0.139300, 0.607320, 0.573920, 0.139770, -0.536810, -0.921270, -0.929480, -0.798570, -0.492390, -1.356210,
0.213360, -0.617860, 1.107430, 0.663060, 0.657970, -0.120240, 0.977940, 0.337490, 0.309180, 1.114780,
-0.513380, -0.027220, 0.542820, 1.249250, -0.331840, 0.650150, 0.019880, 0.315640, -0.678860, -0.655650,
-0.645280, -0.368080, 0.682420, -0.979120, 0.351460, -0.041800, -0.020580, 0.043030, -0.464680, 0.114730,
-0.603480, -0.688910, 0.565810, -0.085300, -0.033770, -0.041960, 0.092500, -1.113990, 0.793010, -0.878700,
-2.835290, 0.022130, 0.058990, -0.585880, 0.824960, 1.951540, -1.023450, -0.151810, -0.087700, -0.057780,
0.816750, -0.508720, -0.525430, -0.905060, 0.183440, -0.404070, 0.655460, -0.305120, 0.982730, 0.539790,
-0.170120, 0.010590, -0.285970, -0.533140, 0.909380, 0.161340, -1.030770, -0.125990, -0.069490, -0.322220,
-0.647370, 0.586650, -0.856220, -0.505130, 1.015710, -0.056960, 0.093160, 0.101750, -0.371970, 1.034970,
0.880750, -1.033230, 0.031880, 0.470060, 1.001100, -0.769190, -0.694240, -0.465790, -0.466310, -0.349250,
-0.399500, 0.131600, -0.224450, -0.297160, 0.874440, -0.799410, -0.380300, -0.939590, 0.937360,
-0.202690, -0.277440, -0.741830, 0.215670, 0.496060, 0.511350, -0.007230, -0.645290, -0.243330, 0.139020,
-0.181020, -0.336330, 0.205480, -0.097060, 0.562810, -0.272860, -0.545730, -0.445580, -0.040020, -0.022550,
-0.563270, 0.233970, 0.164270, 0.943680, 0.298350, -0.842500, 0.180170, -0.597340, 1.042940, -0.541320,
0.282580, 0.473280, 0.145410, -0.031140, -1.541000, -0.400350, 0.591950, 0.431110, -0.382540, 0.994310,
-0.689710, -0.151080, -0.488040, -0.075320, 0.458010, 0.955560, -1.237440, 0.001000, 0.869020, 0.218460,
0.167300, -1.151350, 1.549870, 0.001250, 1.009190, -0.667130, 0.968710, -0.463260, 0.224010, -0.406110,
-0.974130, -0.051440, -0.225660, 0.230470, -0.325130, -0.037090, -0.559910, -0.591570, -0.720670, -0.283470,
-0.091280, -0.043540, 0.069480, -0.069870, -0.071070, 0.287970, 0.513420, -0.453060, -0.835710, -0.432020,
-0.086660, -0.001030, -0.733760, -0.768550, -0.474300, -0.452030, -0.152790, 0.458340, -0.093470, 0.729500,
0.696520, 0.749100, -0.376570, 0.541170, -0.471160, 0.464600, 0.117790, 0.270130, -0.654570, 0.297070,
0.416800, -0.294890, 0.894660, 0.286890, 0.887560, 0.848190, -0.636020, 0.479230, 1.700990, 0.958430,
0.014930, 0.459770, -0.392850, -0.274660, -0.567300, -0.368420, -1.355420, -0.295200, -0.460120, -0.390320,
-0.381620, 0.908050, 1.513470, -0.373050, -0.079250, 0.921890, 0.812870, -0.458500, 0.220200,
0.720350, 0.704520, 0.343860, 0.534370, -0.730360, -0.130310, -0.810940, 0.194410, -0.168410, 0.550280,
0.357540, 0.288990, -0.051440, 0.037340, 0.284770, 0.106610, 0.560320, -0.485420, 0.783970, -1.118650,
-0.065540, 0.827680, -0.171890, 0.182150, 0.108220, 0.937840, -2.376530, 0.662500, 0.448390, 1.580160,
-0.159090, 0.045070, -1.609520, 0.295880, 0.076800, -2.268150, -0.692000, 0.173090, -0.961620, -0.094840,
-0.260700, 0.598610, -0.731310, 0.132110, -0.503450, -0.252760, -0.545100, -0.379090, -0.874140, -0.005220,
-0.867570, 0.680770, -1.074770, -0.090510, 0.603480, -0.112580, 0.181200, -0.067410, -0.253810, 0.482900,
-0.083050, 0.370150, 0.245840, -0.290770, -0.681620, 0.660410, 0.548700, 0.202690, 0.059740, -0.424690,
0.139860, 0.702360, -0.449450, 0.441870, 0.433900, 0.347760, -0.779270, -1.002080, -0.351900, 0.601750,
0.225500, 0.263020, -0.351200, -0.008380, -0.479270, 0.224160, -1.000240, 0.207780, -0.437320, 0.111260,
-0.908000, -0.892840, -0.778020, 0.256050, 0.197300, 0.343320, -0.611630, -0.449650, -1.013960, 0.532110,
0.751560, -0.527360, 0.346540, -0.127090, -0.828690, 0.004960, -0.465750, 0.504640, 0.553130, -1.343860,
0.666410, -0.777220, 0.239100, 0.016400, 0.502250, -0.314760, 0.607950, -0.364910, 0.113000, 0.231400,
0.096580, -0.379990, -0.332420, -0.688340, -0.347540, -0.448930, -0.091780, 0.427120, 2.269670,
0.116260, 0.440070, -0.688730, -1.282130, -1.105740, 0.505710, 0.704290, 0.732580, -0.662280, 0.328690,
0.417470, 0.012350, -0.673260, -0.175440, 0.679130, 0.303190, -0.836680, -0.511320, 0.106210, -0.490670,
-0.675790, 0.296560, 0.172190, -0.834750, 0.433400, -0.058650, -0.882660, 0.399870, -0.476140, -0.282180,
0.636070, 0.841440, 0.586440, 0.314510, -1.093010, -1.038120, 0.616880, 1.599650, -0.221630, -0.424790,
-0.472750, 0.547890, -1.219500, -1.002580, 0.269350, 1.076760, 1.737070, 0.372800, -0.830310, 0.435350,
-0.770910, 0.636660, -0.101110, 0.511020, -0.655220, -1.051390, 0.281150, 0.627860, -0.722410, -1.092770,
-2.431590, -0.265220, 0.712330, 0.273000, 0.568060, 0.072920, -0.337980, -1.340710, -1.178480, -1.438730,
0.415180, -0.347950, 0.301690, 0.343020, -0.675260, 0.419520, -0.722550, -0.762030, 0.266260, -0.375350,
0.330830, 0.675740, -1.035320, -1.071160, -0.892490, -1.100180, 0.640810, -0.165220, 0.095210, -0.750970,
-0.085610, 0.340980, -0.991180, 0.209480, -0.423640, -0.748630, -1.084560, 0.056850, 0.378780, -0.365310,
-0.146650, 0.174620, 0.750070, 0.368880, 0.791270, -0.236940, -0.894640, -0.356750, -0.540690, 0.377350,
0.230600, 0.713850, -0.901660, 0.233660, -2.813900, 0.577080, -0.478400, 0.307380, 0.258390, 0.468870,
0.423920, 0.800840, 2.173840, 0.180930, -0.716890, 0.745240, -0.337000, -0.075630, 0.673360,
0.586850, -0.419700, -0.402900, 0.836610, 2.862520, 1.194270, -0.261990, 0.560700, -0.988050, 0.558270,
0.179400, 0.921440, 0.226360, 0.507270, 0.435070, -0.400040, -0.171680, 0.322390, -0.702820, -0.294630,
-0.773980, -0.267490, -0.474510, -0.405650, -0.151990, -0.574240, 1.105580, -0.124560, -0.866140, -0.172010,
0.571970, -0.216520, 0.940930, 0.996070, 1.117850, -0.635800, 0.422960, 0.479490, -0.414860, 1.928760,
0.815930, -0.250660, -0.786570, -0.041770, -0.509270, 0.891960, -0.612950, 0.478090, 0.814290, 0.883260,
-0.283710, -1.645850, 0.511170, 0.025630, -0.304270, -0.553600, 0.444580, 0.093660, 0.405060, -0.154040,
-0.555700, -0.684140, 0.300560, -3.220840, 2.346800, -0.234330, 0.017400, -0.068540, 0.598750, 0.937640,
-4.405110, -2.332230, -0.506560, 1.327120, 1.256060, -0.686500, 0.542150, 0.789770, 0.671690, -4.773820,
-1.145820, 0.088890, 1.075380, 0.557670, -1.285120, -0.103660, 1.011590, -0.002790, -0.252780, 0.755520,
-0.506010, 4.037450, -0.463280, -0.655740, 1.496810, -0.261590, 0.194030, -0.445540, 0.286370, 0.379700,
0.759790, 0.414570, -0.515360, 0.158030, 0.746440, 0.372500, -0.197930, 0.569160, 0.641720, -1.651270,
-0.897290, -0.538310, 0.100210, 0.453140, 1.071360, 0.958200, -1.019390, 0.446600, 0.581140, -0.294790,
0.038500, -0.398940, -1.195260, 0.140940, -0.504750, -0.542140, 2.539860, -0.380790, -0.315640,
0.355620, 0.474080, 0.013500, 0.680460, -0.822200, -0.141160, 0.100010, -0.396650, 0.349310, -0.438150,
-0.050240, 0.541760, -0.605940, -0.586470, -0.299840, -0.746160, -0.912390, -0.289800, 0.403490, 0.754060,
-0.693100, -0.139970, -1.017200, 0.214000, 0.231200, 0.198480, 0.402160, -0.466370, 0.347440, -0.062870,
0.693270, -0.841300, 0.397200, 0.493470, 0.241640, 0.035900, 0.706270, 0.378390, 0.350570, 0.160430,
-0.778710, -0.453060, -0.159800, -2.527950, 0.119660, -0.566080, -0.043200, 0.020210, -0.823260, -0.376700,
0.096820, 0.221570, -7.657150, 0.163350, 0.334510, -1.447460, 1.060570, 0.245470, -1.812720, -0.544150,
-0.136900, 0.861990, 1.046100, 0.554830, -5.510610, 1.004830, -0.304510, 0.943270, 0.207700, 0.123540,
0.491460, 0.819810, -1.060760, -0.235060, 1.261190, -0.564830, 0.359920, -0.696700, 1.528510, 0.098500,
0.980240, -0.846890, -0.126910, -0.635370, -0.118440, 0.102440, -0.096140, -0.294340, -0.875150, -0.823230,
0.495680, 0.366290, 0.257830, -0.850060, 0.196660, -0.042400, 0.997880, 0.106000, 0.272160, 0.595760,
-0.371170, 0.267200, 0.050960, 0.261060, -1.053680, -0.169890, 0.544840, -0.136550, 0.540890, 0.971290,
-0.308260, -0.372470, -0.128880, -1.155000, 1.605670, -0.153940, -0.279470, 0.536940, 0.395760, 0.410070,
-0.803560, -0.841090, -0.397760, 0.408970, 0.657980, -0.214660, 0.569670, -0.498190, -0.625500,
-0.180080, -1.246630, -0.303300, 0.637040, -0.255150, 0.257420, -0.956760, -0.861090, -0.606780, 0.326220,
0.255730, -1.118550, -0.672070, -0.215040, -1.022680, 0.166840, 0.361780, -0.404160, -0.609720, -0.664980,
-0.297630, -0.993480, 0.179540, 0.674230, 0.091070, -0.613030, 0.217230, 0.708490, 0.324500, 0.023000,
0.333120, -0.870820, 0.168620, -0.353400, -0.621700, -0.604270, -0.080990, -0.865620, 0.231160, 0.514790,
-1.112120, 0.089440, 0.890670, -0.536760, 0.521930, 0.291370, -0.498280, 0.044360, -0.602690, -4.879990,
-0.237890, 0.555900, -2.440600, -0.752280, 0.782650, -1.432370, -0.147760, 0.119250, -1.020530, -0.943700,
0.973870, 2.367060, 0.365500, -0.274210, -4.950520, -0.295980, 0.840780, -2.772280, -0.061820, -0.523290,
3.104100, 0.666410, 0.148480, -7.223930, 0.849590, -0.069510, 0.001670, 0.550540, -0.659990, 0.681760,
-0.179170, 0.755600, -1.327590, 0.942240, 0.044900, -0.238570, 0.522140, -0.816990, -0.163170, -0.425520,
0.847730, -0.281400, -0.633830, -0.187810, -0.279600, -0.333730, -1.302740, -0.048610, -0.390100, 0.335720,
0.604940, 0.273720, -0.843330, -0.675540, -0.813390, 0.704880, 0.568090, 0.698860, 0.392460, 0.583210,
-0.609940, -0.152900, -0.004200, -0.204640, 3.017940, 0.204520, 0.749820, 0.208010, -0.485950, -0.473700,
-0.164380, -1.179010, 0.099620, 0.896560, 0.765180, 0.519690, 1.682250, -0.798380, 0.564180,
0.159810, 0.873260, -0.029810, -0.470170, 0.313240, 1.286000, 0.913910, -0.059520, -0.595890, 0.032310,
-0.581020, 0.431470, 0.030240, 0.412770, -0.554990, -0.379270, -0.161030, 0.047010, 0.158320, -0.644920,
-0.270450, 0.541410, 0.438180, 0.012060, 1.205880, 0.154070, -0.047820, -0.660580, -0.541500, -0.174860,
0.075070, -0.820710, -0.364290, 0.325220, 1.040460, 0.498540, 0.178700, 0.821830, 1.030560, -0.992750,
0.163960, 0.233090, 0.146310, 1.097460, 0.107230, 0.217270, 0.737700, 0.104710, -0.655960, 0.754120,
-0.690320, 0.506140, 1.054310, -0.243440, -0.350330, 0.814920, -1.180080, -0.197930, -0.095320, -1.826220,
-0.918150, -0.084900, 0.555500, 0.216080, 0.540970, -1.732010, -0.735020, 0.177710, -1.423680, -0.470950,
-0.142530, -0.190590, 0.653730, 0.825020, 0.342230, -0.556770, 0.453240, 0.267060, -0.118040, -0.402880,
-0.784400, -0.090550, -0.553320, -0.009310, 0.166840, -0.894410, -0.311560, 0.732950, 0.635150, 0.973420,
0.010210, -0.771750, -0.837010, -0.496430, -0.686510, -0.210410, 0.208390, 1.296280, 0.464120, -0.143430,
0.496760, -0.151860, 0.166020, 1.471430, -0.619080, -1.071360, 0.322500, -0.739390, -1.068910, -0.319350,
-0.059880, 0.407170, -0.031840, 0.268060, 0.021840, 0.694120, -1.255520, 0.268390, 0.374100, 0.313620,
-0.200910, -0.556080, -0.338430, 1.155880, 0.396720, -0.447480, 0.218450, -0.362920, 0.137440,
-0.006840, 0.177750, -0.102480, -0.559110, 0.191760, -0.105980, 1.138510, -0.208580, 0.472940, 0.201880,
-0.372820, 0.656350, 0.118060, 0.714550, -0.719630, -0.021220, -0.215290, -0.059360, 0.756590, 0.885240,
0.494380, 0.852920, -0.758420, 0.873460, -0.599440, -0.569380, 0.766890, 0.064520, 0.321940, -0.995030,
0.405620, -0.573270, -0.599800, 0.194410, -0.577420, 1.011680, -0.499160, -0.514020, -0.604320, 0.442180,
-0.089720, 1.293570, 0.353480, -0.138600, 0.935840, -0.237460, 0.765080, 1.084190, 0.522600, -0.420690,
-0.035300, 0.246120, -0.108990, -0.809980, -0.558440, -1.045390, -0.391290, -0.385370, -1.024040, 0.500960,
0.307090, 0.499060, 0.923850, -0.175380, 0.010000, 0.692220, -0.557950, 0.652470, 0.183100, -0.862050,
-2.039470, -0.142980, 0.235420, 0.042360, 0.618210, -0.188810, -0.809850, -0.152440, 0.265680, -0.278920,
-0.331020, 0.608400, 0.615120, -0.682040, -0.170480, 0.554350, -0.617710, -0.826430, 0.256330, 0.479810,
-0.969510, -0.213360, 0.117820, 0.546440, 0.210790, -0.434480, 0.854770, -0.900120, 0.157600, -0.768290,
-0.757080, -0.931080, 0.292220, 0.147420, 0.830220, -1.133370, -0.881660, -0.743380, 1.104300, -0.577970,
-0.028960, -0.457830, 0.865890, 0.272520, 0.608810, 0.189160, -1.352010, 0.072910, 0.329290, -0.171580,
-0.639690, -0.774380, -0.772690, 0.217160, 0.278780, -0.185510, 3.152180, 0.564300, 0.479330,
0.508210, -0.769400, -0.374140, 0.056020, 0.023450, 0.255680, -0.592220, 0.552420, -0.276130, -0.508570,
0.613680, -0.248140, 0.037790, 0.298620, -0.018470, -0.049710, -0.542410, -0.238620, 0.870560, -0.173400,
0.369950, -0.412560, -0.232280, 0.012370, -0.149780, 0.408470, 0.246050, 0.173500, -0.544470, -1.129870,
-0.597700, -0.448560, -0.708520, 0.881200, -0.137680, 0.963120, 0.146600, 0.813150, 0.260040, -0.485220,
-0.041640, -0.287750, -0.283100, 0.494260, -0.788550, 0.029410, -0.747760, 1.052510, -0.989600, -0.197690,
-0.223280, -0.083030, 4.236440, -1.450410, -0.862300, 0.492840, -1.272530, 1.143450, 0.978500, 0.037990,
-0.434610, 1.195520, -0.119930, 1.056530, 9.221460, 0.150250, 0.641980, 1.240080, 0.284430, 0.401920,
-1.803880, -0.468350, 0.854630, -0.156810, 0.384140, -1.792770, -0.213610, -0.536080, -1.235710, -1.278450,
0.155700, -0.597760, 0.419820, -0.707790, 0.606930, -0.779940, 0.499540, 0.454260, -0.410740, -0.661460,
0.144100, 0.181690, -0.958850, 0.023840, 1.312740, 0.580780, -0.169020, -0.809040, 0.073920, 1.071470,
-0.716780, 0.105000, 0.825260, -0.625370, -0.416850, -0.716500, 0.135960, -0.576060, -0.114320, 2.351700,
0.954370, 0.031010, 0.710350, 0.023650, 0.905620, 0.491240, -0.316300, -0.066370, 0.251970, -0.062690,
0.898030, 0.308950, 0.383130, -0.351170, -0.929840, -0.759180, 1.719200, 0.789590, 1.376940,
-0.356290, 0.773100, 1.187660, -0.372460, -0.758960, -0.660920, 0.612230, -0.589340, -0.211850, -0.006070,
-0.039180, -0.802560, 0.465050, -0.839800, 0.177660, 0.399230, -1.066080, -0.744590, -0.370270, -0.690620,
-0.521570, -0.270940, 0.420250, 0.646710, 1.078850, 0.899960, 0.316610, 0.047550, -0.750650, -0.658370,
0.148590, -0.288730, 0.374490, 0.392220, -0.168370, 0.638010, 0.352400, -0.518250, 0.424630, -0.696880,
0.602250, 0.167010, -0.542120, 0.278310, 0.070600, 0.497130, 0.367850, -0.077750, 0.386040, -0.085390,
-0.392720, -1.274440, 1.076740, -0.176250, -0.303230, -1.513170, 1.003710, 0.319230, 0.870340, 0.528190,
-0.074870, -0.593740, 0.006080, -1.135790, 0.587740, -0.008700, -1.168780, 0.296450, 0.635510, -0.748450,
-0.671580, -0.875100, 0.018940, 1.003660, -0.823990, 0.147800, -0.464550, -0.968240, 0.951630, -2.615220,
-0.862010, -0.016340, 1.035980, 0.017060, -0.009330, 0.538160, 0.581940, -0.709810, 0.011680, -0.928930,
0.501820, 0.963780, 0.273710, 0.759730, -0.673840, -0.519830, 0.072660, 0.186380, 0.287300, 0.079030,
0.715150, -0.250360, 1.086320, 0.621510, -0.061890, 0.417090, -0.587700, 0.965380, 0.561140, 0.070250,
0.216170, -0.431790, 0.960430, 0.690130, -0.582460, 0.328720, -0.949020, -0.626220, -0.057280, -0.316650,
-0.862790, 0.796180, 0.475510, -0.479870, 0.580150, 0.815010, 1.890420, 0.099660, -0.111600,
-0.573510, 0.436560, -0.408770, -0.703290, -0.675500, 0.640070, 0.133730, -0.343680, -0.577600, 0.833450,
0.034310, -0.258970, -0.690840, 0.889960, 0.034690, -0.408410, 0.581880, -0.211700, 0.653990, -0.706700,
0.925690, -0.507540, -0.575390, 0.007070, 0.016320, 1.142420, -0.266640, 1.231450, -0.504010, -0.789870,
-0.620790, 1.134250, -0.016450, -0.457660, 1.154120, 0.734490, 0.955060, -0.201970, 0.811180, 0.565680,
0.373340, 0.524260, -0.089370, 0.762830, 0.970700, -1.043930, -0.875220, 0.686830, 0.270680, 0.569700,
0.211830, 0.690270, 1.140410, -1.220700, -1.516400, 0.262550, -0.121590, -0.654220, 1.136550, -1.501370,
1.751100, 0.809110, 0.458890, -2.299090, 0.077920, -0.371290, -0.189580, 0.515170, -0.041520, 2.860680,
0.028850, 0.365970, -8.637950, 0.785620, -0.750690, 0.352330, -0.516980, -0.700370, 3.688040, 1.239130,
0.753740, -2.158080, -0.139890, 0.278160, 1.891310, 0.028020, 0.979830, 1.460860, 0.262340, -0.452510,
-4.739430, -0.388720, 0.688110, -0.346120, 0.585100, 0.450920, -0.085580, 0.880690, 1.263860, 0.308210,
0.026730, 0.066090, 0.356670, 0.431340, -0.349500, -0.560810, -0.611030, 0.574690, -0.482870, -0.597720,
-1.697480, -0.467110, -1.149270, -0.373240, 0.300180, -0.255550, 0.239990, -0.933000, 0.661360, -0.059450,
0.609140, -0.325450, 1.223160, -0.992630, 0.268950, -1.143340, -1.414290, 0.435160, 1.196570,
0.867320, 0.499780, 0.351280, 0.049670, -0.809690, 0.210480, -0.604290, 0.988140, -0.600090, 1.024240,
1.110770, 0.528890, 0.947950, -0.694600, -0.622400, 0.421070, -0.387960, 0.676670, 0.444170, -0.392340,
-0.114900, -0.384670, -0.173720, -0.720590, 0.742870, 1.429350, -0.748720, 0.114020, 0.117340, 0.713850,
0.981630, 0.675420, 1.059490, -0.021740, 0.017850, 0.507220, -0.572920, 0.809090, -0.320850, -0.205280,
0.347520, -0.358980, -1.011860, -1.176820, -0.418450, -0.862870, -0.854000, 0.776100, 0.096090, 0.385340,
1.058550, -0.254920, -0.381280, -0.136380, -0.715980, 0.817170, -0.218560, -0.843480, -0.832900, -0.470850,
-0.011270, -1.098690, -0.730290, -0.474260, 2.431970, 1.490840, -0.391940, -4.518790, -0.817070, -0.747730,
-1.516010, -1.212700, -0.837730, 2.015460, 0.239800, -0.519510, -5.506460, -0.055690, 0.816020, -3.874760,
-0.493410, -0.925240, 4.189800, 0.689480, 0.378410, 0.556760, -0.014140, -0.478160, -2.630630, -0.155320,
-0.486010, 9.946930, 1.317210, 0.902520, 0.525250, -0.318060, -0.157530, 0.783120, 1.241820, -0.273270,
0.514290, 0.627420, -0.035350, -1.903970, -0.992800, 3.218910, -0.793160, 0.663110, -1.097450, 0.656040,
1.003530, 0.912500, 0.173180, -0.548250, 7.912720, 0.320370, 1.773540, 0.242150, 0.393200, -0.354850,
0.856820, -0.446170, 0.610210, 0.534510, -0.395030, -0.672600, -2.075400, -0.235800, 2.092860,
0.369750, 0.240670, -0.735180, 0.002970, -0.860820, 0.727460, -0.933160, -1.014590, 0.574930, 0.535690,
-0.320310, 0.441440, -0.306300, 0.836550, -0.761000, 0.639490, -0.294050, 0.138370, 0.005680, 0.795850,
-0.261380, -0.540390, -0.291580, -0.503690, -0.626500, 0.861580, 0.647790, 1.206920, -0.094100, 0.591240,
-0.066000, -0.428900, -0.518900, 0.597400, 0.472360, -0.401650, 1.295610, 0.195470, -0.818540, -0.084130,
0.489490, 1.183680, -0.577070, 0.485540, -4.354500, -0.192340, 0.168070, -0.299930, 0.396700, -0.039510,
0.347400, 0.742190, 0.570830, -2.197200, -0.105800, 0.825050, -1.362190, -0.182570, -0.312360, -0.537510,
-0.147070, -0.342180, 0.094160, 0.288610, -0.353630, -0.347600, 0.192040, 0.230670, -0.160290, 0.817420,
-0.826040, -0.351870, 0.188440, 0.644740, 0.542320, 0.888120, 0.208130, -0.186620, -0.896370, 0.425900,
0.782000, -0.518800, -0.132740, -0.251540, -0.072160, 0.971210, -0.297440, 1.454620, -0.223120, 0.103660,
0.015270, -0.474780, -0.820370, -0.457830, 0.641900, 0.230800, -0.916810, 0.357350, 0.508800, -0.229420,
-0.920240, -0.426840, 0.061410, -1.848820, 1.003400, -0.235860, 0.239830, 0.459570, 0.212590, 0.944930,
0.514730, 0.617060, 0.412770, -0.078240, -0.115340, 0.622140, -0.404400, -0.448890, -0.674440, 0.388520,
-0.832790, -0.759900, -0.542080, -0.964660, -2.064700, 0.606220, 0.891050, -0.353860, -0.628990,
0.088560, -0.075220, -0.456070, -0.596500, -0.332330, 0.049670, -0.027060, 0.175710, -0.195150, -0.842460,
-0.000190, -0.060480, -0.856390, -1.019810, 0.657530, 1.038910, -0.422430, -0.106000, -0.061260, 0.791450,
0.579940, 0.777560, -0.469510, 0.350310, 0.084470, -0.545820, -0.208910, 0.685410, 0.355430, -0.261640,
-0.605050, 0.436170, -0.088600, 0.047330, 0.024800, 0.534730, 0.043480, 0.665660, 0.488470, 0.678450,
-0.002120, 1.451910, -0.051560, -0.308350, 0.469860, 0.538970, -0.886870, 1.217480, -0.495580, -0.370400,
0.084350, -0.526080, -0.383300, 0.477410, 0.127790, 0.156750, 1.642810, 0.860430, 0.440140, -0.441560,
-1.114330, 0.727030, 0.445380, -0.503880, 0.897090, 1.068760, 0.663860, -0.859490, -0.567740, 0.265380,
-0.573360, -0.466690, -0.813290, 0.043270, 0.210570, 0.978610, 0.979980, 0.766520, -0.098530, -0.191760,
0.411030, 0.918790, -0.722160, 0.340180, 0.118900, 1.013070, -0.285850, -0.130540, 0.261340, -0.868990,
-0.300910, 0.210800, 0.681100, 0.524210, -0.132110, -0.369780, -0.032580, -1.352970, -0.371740, -0.235220,
0.491610, -0.721020, -0.851780, 0.371760, 0.678050, -0.249840, 0.423020, -0.336610, -0.049240, 0.320550,
-0.854040, -0.591300, -0.342810, 0.423020, -0.390790, -0.190170, -1.692800, -0.885820, 0.252730, 0.985410,
0.022620, 0.723940, 0.977360, -0.259250, 0.839790, -0.049640, 5.446760, 0.933630, -0.405810,
-0.155880, -0.182780, 0.976400, -0.980020, 0.388800, 0.119500, 0.741290, -0.584140, 0.713160, 0.675000,
0.694700, -0.815320, -0.228970, -0.274970, -0.202300, 0.953710, 0.297440, 0.305040, 0.763180, -0.655170,
-0.412570, 0.730400, 0.658320, 0.380150, -0.262330, -0.293860, 0.510330, -0.139920, 0.699340, -0.481440,
0.689530, -0.323270, -1.083470, -0.094860, 0.571260, -1.396650, 0.247590, -0.206600, -0.669560, 1.231180,
0.661640, -0.374700, 0.217850, 1.899510, -1.186110, 0.037550, 0.254340, -0.387880, 1.280130, 0.551370,
-1.068040, 0.453080, 1.209300, -0.991680, 1.952050, -0.347370, -0.746440, 1.494330, -0.638090, 0.009520,
-2.064450, 0.572050, -0.682790, 1.501220, 0.353670, 0.913980, -0.496550, -0.860490, -0.980210, -0.238450,
0.734200, 0.911010, 0.273590, -0.279260, -0.695310, -0.809610, -0.508100, -0.837860, 0.852220, -0.299430,
0.051500, 0.615390, -0.607120, 0.326710, -0.476820, -0.278230, -0.205220, -0.196580, -0.463470, -0.699780,
0.893690, -0.281830, -0.078120, -0.196700, -0.234110, -0.204060, 0.387240, -0.395590, 0.255310, 0.518710,
0.792020, -0.992500, -0.329220, -0.658650, -0.482130, 0.247600, -0.133850, -0.144170, 0.525680, 0.171170,
0.239250, 0.348730, 0.323750, -0.096710, -0.343160, 0.277550, 0.709960, -0.763710, -0.852200, -0.636740,
-0.185270, 0.421440, -1.074850, -0.443330, -1.229300, -0.369570, 0.124210, 0.331030, -0.522380,
0.374230, 1.584540, 0.571410, 0.411920, -0.383710, 0.311910, 0.720550, 0.803240, 0.834980, -0.122780,
0.102820, 0.222780, -0.368420, -0.260940, -0.598260, 1.009440, 0.616140, -0.101360, 0.019880, 0.337280,
0.735290, 0.198130, 0.034990, 0.806900, 1.094780, 0.088870, -0.208240, -0.054370, -0.737430, -0.446590,
0.015920, -0.129430, -0.560630, -0.120260, 0.671800, -0.796650, -0.276560, -1.509370, -0.656720, -0.947520,
0.923350, 0.468800, 0.846800, 1.312120, 0.350200, 0.147380, -0.031560, 0.229920, -0.240810, 0.437320,
-0.536060, 0.264210, -0.064630, 1.368320, -0.980290, 2.141990, 0.307870, -1.166450, 0.736280, 0.925630,
1.235740, -1.278390, 0.697190, -2.020030, 0.212500, -0.471010, -0.767560, 0.668450, -0.062140, 0.006410,
-1.822100, -0.804880, -0.205810, 0.839640, 0.396460, -0.333700, -0.097890, -0.161890, 0.982590, -0.726750,
-0.797940, 0.346090, -0.066730, 0.882710, 0.354270, 0.730620, 0.662220, 0.947790, 0.244620, 0.403490,
-0.880880, 0.178800, -0.325100, -0.922210, 0.742410, -0.161460, 0.072280, -0.186750, 0.214350, -1.162780,
0.248950, -1.086070, 0.531470, 1.904060, 1.097700, 0.042020, -0.138380, 0.206190, -1.585420, -1.826650,
0.864290, -0.067950, -0.574110, 0.170850, -0.624560, -0.396400, 0.043360, -0.063010, -0.406660, 0.084020,
0.308610, -0.783210, -0.186900, 0.197900, -0.443050, -0.888710, -0.470360, 0.093830, -0.164610,
-0.805040, -0.075980, -0.462860, -1.638090, -0.830380, 0.508220, -0.409050, -0.963080, -0.162970, 0.231950,
-0.256250, 0.028080, 0.348460, -1.074480, -0.644930, 1.519910, 1.226840, 0.795440, 0.064940, -4.397400,
0.060110, 0.096460, 0.278360, 0.546580, 0.759780, 1.011510, 0.563560, 0.592720, -0.175530, 0.187030,
0.118000, 1.004570, 1.181550, -0.452920, -0.136050, -0.859930, 0.025580, 3.289870, 0.327170, 0.059630,
-0.282430, -0.258500, -0.525670, -1.538420, 2.092710, -0.306310, 5.746520, -0.718180, 0.272880, -1.953810,
0.898280, 0.022160, 0.569890, 3.669670, -0.520020, 0.304270, 2.550670, 0.356480, -0.163340, 4.295450,
0.791120, 0.742950, 0.695730, 0.916160, -0.886620, 1.961870, -0.695410, -0.799380, 1.255650, -0.162000,
0.567650, 0.810370, 0.001840, -1.008190, 1.918360, -0.173450, -0.157980, -0.707210, -0.462810, 0.399030,
0.643270, 0.793770, -0.926550, 0.859810, 0.491240, -0.013320, -1.419410, 0.221350, -0.347330, 0.648290,
1.234380, -0.752040, -0.335260, -0.380300, 0.309230, 0.457730, 0.258380, 0.363770, -0.135900, 0.317180,
-6.674160, 0.568330, 0.000190, 0.619040, 0.819030, 14.952420, 0.387130, 0.560500, -0.103150, 0.829960,
0.908700, -0.001160, 0.895180, 0.518400, -1.621520, 0.220880, 1.453110, -0.283770, -0.579800, 0.077910,
0.737450, -0.422420, -0.832550, -0.583790, 1.015690, 0.671520, 5.244760, -0.227770, -0.708090,
0.620760, 1.148500, 0.607940, -0.670950, 0.763920, -0.246570, -0.273390, 0.761800, -0.244610, 0.833400,
0.380830, 0.021040, 0.776320, 0.028240, 0.714340, 0.223060, -0.213380, -0.884430, 1.279660, 0.208330,
-1.671100, -0.881450, -2.735850, -1.159550, 0.448100, -0.331190, 1.002410, 0.137560, 0.006620, 0.102630,
0.783660, 0.239320, 0.586230, -0.077650, -0.478680, 0.537220, 0.382410, 0.748050, 0.649150, 0.185990,
0.251290, 1.242730, 0.075780, -2.150100, 4.097290, -0.156080, 0.497330, 14.030470, -0.552660, 0.453320,
3.191140, 0.360430, -1.649390, 1.402900, 0.020400, 1.206500, 11.683440, -0.643310, 0.314160, 0.664870,
0.948700, 0.958640, -0.464510, -0.705680, 1.003010, 0.184440, -0.253650, -0.220260, 0.548340, 1.309720,
-0.168100, 0.110820, -0.632480, 0.800920, -0.489380, 0.258840, 2.029890, -0.066840, -0.886390, 0.561610,
0.481550, -0.750430, 2.458830, 0.832120, -0.542930, -0.104400, -0.414970, -0.360460, -0.089500, -0.100650,
-0.638540, 12.893180, 0.882690, 0.671850, 0.007010, 0.535950, -0.719820, -5.578240, -0.964820, -0.727530,
0.289340, -0.512940, 0.400960, -5.176480, 0.233060, -0.179230, 0.433200, 0.192020, -2.479820, 0.323010,
0.537710, -0.027670, 0.077960, 0.153570, -0.277630, 1.445600, -1.068060, -0.515980, -0.033080, -2.903700,
-1.018050, 0.035840, 1.146480, 0.122530, 2.197130, -0.905390, -2.076270, -0.076240, 12.257080,
0.667620, 0.558340, -0.481610, 0.267220, -0.403010, 0.019560, 0.595230, 0.534520, 0.169420, 0.479090,
0.307070, 0.049200, 0.154870, -0.399080, -0.271770, -0.798090, 0.288400, -0.056830, 0.124560, 0.597910,
0.885430, -0.185530, -0.988830, -0.302280, -0.731470, 0.723050, 0.249210, 0.511900, 0.608800, -0.122040,
0.078030, -0.269320, 0.569410, -0.042420, -0.056790, -1.010430, 1.182000, 0.301040, -0.363890, 1.121850,
0.786890, 1.796990, -0.493250, 2.886330, -0.837750, 1.040640, -1.674080, -1.256040, -0.362090, -1.607430,
-0.288040, -0.726960, 3.410360, 0.229570, 1.286600, -0.725840, -0.366990, -0.720200, -0.676410, -0.546620,
0.518250, 2.148390, 1.255040, 0.524110, -1.088710, -0.879450, 0.014340, -0.325780, 0.412480, -0.979620,
1.918930, -0.608950, 0.659350, -0.910880, -0.427590, -0.623950, -0.950420, 0.245260, 0.019520, 2.148860,
-0.482010, -0.729460, -0.559950, -0.847990, -0.383010, 1.250590, 0.501900, -0.058180, 0.765840, 0.331860,
0.373390, -2.124720, -0.340010, 0.768730, -0.866470, -0.840620, 0.670930, -1.021710, -0.714110, 1.117800,
-0.509380, 0.810370, -0.206290, 0.777220, 0.714640, 1.229460, -0.730090, -0.170350, 1.669920, 0.427600,
0.014020, -0.085150, -0.639690, -0.126230, -2.106520, -1.214840, 0.277130, 0.923910, 0.617560, 0.061180,
-0.865580, -0.465250, -0.866980, -0.713900, -0.791260, 0.749430, 2.803260, -1.100350, -3.225490,
-0.540310, 0.321470, -0.425080, 0.073620, -2.145770, -0.412320, -0.852780, 0.124030, 0.559320, -0.119150,
0.703300, 0.361000, 0.082820, 0.277340, 0.598190, -0.442110, 0.191520, 0.396760, 0.185320, 0.821550,
-0.166720, -0.874790, -0.479360, -0.560110, 1.071610, -0.099620, -0.524980, 0.132630, 0.391510, 0.260570,
-0.490930, 0.831710, 1.095150, 0.565320, -0.595450, -0.196810, 0.731610, 0.544330, 1.143550, 0.021340,
0.118940, -0.577420, -0.721110, -0.008310, -0.406270, 0.681960, 0.024530, -0.257490, 2.907470, -0.728280,
0.412890, -2.039810, -0.171040, 0.373830, 0.511390, -0.025980, 0.553590, -0.908940, -0.819850, 0.554640,
-0.173620, -0.128910, -0.231580, 1.045850, -0.209440, 1.020550, 0.834790, -0.611300, 0.768240, 0.712350,
-0.014230, 0.396900, -0.131380, -0.298460, -0.148170, -0.266730, 0.183660, 0.653190, -2.377770, 1.073820,
-0.569120, 2.364290, -0.214600, -0.348300, 0.516820, 0.936860, 1.088580, -0.288110, -0.530930, 0.365610,
1.117050, -0.635320, 0.053190, -1.149680, 0.947500, -0.767750, -0.292320, 1.070280, 0.324100, 0.668570,
-0.491060, 0.958080, -0.354950, -1.188250, -0.117380, -0.251870, -0.255340, -0.351090, -0.286250, 0.670050,
0.389180, 0.242510, 0.545260, 0.469890, -0.453130, -0.714280, -0.114720, 0.320460, -0.798030, 0.990450,
0.587620, -0.572640, 0.351640, 0.017900, -0.321790, -0.335100, -3.284130, 0.328010, -0.678810,
0.304130, 0.288210, -0.320140, -0.254480, -0.363450, 0.486120, -0.848100, -0.315260, -0.593050, 0.564730,
-0.289510, -0.429590, -0.061330, 0.431780, 0.973810, 0.352870, 0.857310, -0.369250, 0.933060, -0.848100,
0.783240, -0.642450, -1.015480, -0.966940, -1.473120, 1.027330, 0.437150, 0.526880, 0.420260, -0.895700,
0.211100, -0.553620, -0.024630, -1.770710, 0.642250, -0.282890, -1.112950, 0.646500, -0.234730, -0.154240,
-0.114200, 0.500820, -4.710730, 0.865150, 0.342010, 0.698370, 2.102070, -0.397270, -6.723070, -0.704660,
-0.372780, 0.499660, -0.392140, -0.780480, -6.896370, -0.425230, -0.078520, 1.299990, -1.281180, -0.959240,
0.527890, -1.195300, 0.059390, -0.560570, -0.620770, -0.334150, 2.135030, -0.196040, -0.016900, 0.165370,
0.046940, -0.227140, -0.784000, -1.473480, 0.080340, -0.796800, 0.312050, -0.721140, -0.387650, -0.673680,
-0.444510, -0.790160, -0.532030, -0.194360, -0.038490, -0.931960, 0.738840, 0.859710, -0.208600, -0.351050,
0.437370, 0.194830, -0.172360, 0.031660, -0.409260, 0.135790, -0.151920, 0.316710, -1.296590, -0.088810,
-0.511100, 0.933190, 0.285620, 2.482680, -0.162010, -0.434280, -0.068820, -0.315300, -0.411120, 2.017660,
-0.638480, 0.768540, -0.344350, 0.723830, 1.184930, -0.438940, 0.331220, 0.065190, 0.372050, 0.147370,
0.693720, 0.150810, -0.903810, 0.508820, 0.500610, -0.490130, -0.373250, 0.206230, 0.254190,
26.706249, 25.478901, 26.353571, 25.815849, 26.385691, 25.748180, 25.631451, 26.093849, 26.005610, 25.198780,
24.790421, 25.371901, 26.502501, 26.741961, 25.972900, 25.344110, 25.907330, 25.140591, 26.442560, 25.167080,
25.115129, 26.583090, 25.918720, 25.987820, 24.982189, 26.238010, 26.497000, 25.300970, 26.647350, 26.651661,
26.360241, 9.158560, 25.430059, 26.595060, 8.972050, 26.028891, 26.666870, 9.221610, 25.789230, 26.410290,
7.888180, 25.557230, 25.416500, 8.641630, 26.645460, 25.072281, 8.681690, 26.388769, 26.060810, 8.856630,
8.517370, 25.190090, 9.455960, 8.646940, 25.300461, 9.473710, 9.209500, 25.246481, 8.139920, 8.106710,
24.841160, 7.921050, 9.610900, 24.968840, 8.241370, 9.102770, 26.709410, 8.012310, 9.598160, 25.506170,
8.873610, 9.593420, 24.814859, 8.692670, 8.282020, 25.968670, 9.638120, 9.679060, 25.832109, 8.232160,
9.117630, 26.264771, 9.421730, 9.710990, 26.482771, 9.271960, 8.820750, 25.681170, 9.037330, 25.370489,
26.541140, 8.249630, 9.712580, 25.128031, 8.855620, 26.244539, 25.784281, 9.200450, 25.363899, 26.108240,
26.661880, 24.801140, 26.281891, -0.148900, 26.321159, 26.458750, 26.367390, 25.049580, 25.748890, 25.108179,
0.602940, 26.318279, 25.953369, 26.613140, 24.961241, 9.183740, 26.719820, 26.514250, 25.612200, 26.305370,
9.631170, 9.078280, 25.715700, 26.299080, 8.324320, 25.117041, 25.176390, 26.592159, 7.839930,
0.427560, 0.262310, -0.146600, 0.911810, 0.753130, 0.678130, 0.148800, -0.330770, 0.436220, 0.223860,
0.140140, 0.614260, 0.056940, -0.485010, 0.109910, -0.930790, 0.198120, 0.331420, 1.385470, 0.908700,
0.011730, -0.935570, 0.974130, -1.047650, -0.542230, -0.005130, -1.164820, 0.099900, -0.791240, -0.697670,
-0.082730, 0.676190, -1.157750, 0.089970, -0.315230, 0.297320, -1.802960, -0.741120, 0.186870, -1.814770,
-0.614770, 0.647890, 1.549900, 0.711800, 0.445180, -5.652450, -1.314890, 0.577840, 0.659530, 0.036710,
-0.821650, 0.486290, -3.379410, -1.204110, 0.233110, -3.393170, -0.805190, 0.360800, -2.085890, -0.947850,
0.171420, 0.545840, 2.213180, 0.160970, -0.238490, -1.171540, 0.567170, 0.442570, 1.135890, 0.144580,
0.269250, 1.223810, 0.813780, 0.703460, 0.736060, 0.976420, -0.509260, 0.268930, 0.282840, 0.384610,
1.288060, 0.509210, 0.190160, -0.871950, -0.847630, -0.409260, -0.999750, -0.561700, 0.430200, 0.176720,
0.251200, 0.043080, -0.643160, -0.472650, 0.115420, 0.227140, -0.276180, -0.927390, -1.324600, -0.570620,
-0.521490, 0.144790, -0.364340, -1.699220, 0.381510, -1.003600, -0.104580, 0.571640, 1.366910, 0.795420,
-0.174590, 0.879450, -0.664320, -1.066830, 0.054680, 0.248460, 0.246450, -0.754310, 1.881940, -0.330480,
0.563950, 0.595880, -0.294970, 0.215140, 0.549710, 0.157600, -0.729020, -0.793620, 0.781450,
0.737380, -0.844320, -0.277760, -0.109410, 0.507090, 0.660540, 0.723700, 0.725370, -0.436230, 0.926850,
-0.121510, 0.441480, 1.052590, 0.176940, 0.341710, -0.766720, -0.358700, 0.603450, 0.647060, -0.728010,
-0.207210, 0.185780, -0.078580, -0.445120, -0.248680, 0.410340, 1.020720, -0.413320, -0.126590, -0.400630,
0.519730, 0.142610, 0.109620, -0.743380, -0.052000, -0.907240, -0.108050, -0.119530, 0.689600, 0.931210,
0.202440, 0.479100, 0.053760, 0.320160, 0.371880, 0.888880, 0.567150, -0.285320, -0.034390, 0.412590,
0.681070, -0.346550, -0.781580, 1.141890, 0.137200, 1.777490, -1.234730, -0.443500, 1.480520, 1.264860,
0.432840, -1.540550, 0.008140, -0.192900, 2.169880, 8.350280, 0.329950, -0.272040, -9.950700, -0.058250,
-4.193410, 0.267720, 0.536970, -0.838140, 9.311730, -0.993600, -1.352380, -0.178320, -0.831080, -1.188250,
-0.761160, -1.094170, -1.779300, 0.021580, -0.555410, -0.246710, 0.819940, -0.690290, -12.347480, 0.894590,
-0.620980, 6.098350, 4.126950, -0.678250, 8.870860, 2.567100, 0.355140, 1.799600, 0.602390, 0.878900,
-0.627520, -1.093750, 0.449310, -1.917960, -0.340680, -0.873160, 0.147070, -0.580890, 5.638500, -1.026000,
-0.385260, 0.729110, 0.220120, -0.544360, 4.102340, 0.592420, 2.572770, 0.518580, -0.041730, -2.412830,
-0.806700, 0.093440, -0.466530, 0.301350, -0.545340, 0.635670, -0.760180, 0.306400, -2.894060,
-0.770690, -1.393100, 0.229310, 0.746820, 0.160640, -0.207230, -0.646100, -0.850060, -0.258120, 0.561980,
0.799030, -0.286530, 0.778730, -0.763150, -0.889060, -0.194850, -0.582260, 0.862600, 0.357740, 0.482320,
-0.053560, -0.512000, 1.016190, -0.662080, -0.747120, -0.572980, 0.548730, -0.278800, -0.135690, 0.364610,
-0.274280, 0.263350, -0.750830, -0.597570, -3.710580, -0.029110, -0.730960, 0.338940, 1.057470, -1.105350,
0.328430, 0.755880, -0.650520, -1.472740, -0.762110, -4.771920, -2.723840, -0.060770, -0.758210, -0.810330,
1.230270, -4.418200, -0.466290, -0.661560, -1.904520, -0.192860, 1.142150, -3.907520, 0.312130, -0.113020,
-0.649530, -0.037420, 0.841450, -6.683750, 0.761510, 0.950950, 0.473860, -0.468840, 0.601620, 0.452230,
0.309700, -0.672990, 0.061220, 0.855200, -0.762380, -0.543490, -0.306650, -0.821930, 0.194200, -0.468690,
-0.369510, -0.922860, -0.721990, 0.155150, 0.478370, 0.261320, -0.812740, -0.107510, -0.503390, -0.021860,
0.907020, -0.539950, 0.764500, -0.498670, 1.005980, 0.714200, 0.534810, 0.343180, -0.497430, -0.506870,
0.559740, -0.499190, 0.753800, 1.406820, 0.084270, 2.526660, -0.328650, 0.765220, 0.794940, 0.350630,
-0.704810, 0.559590, -0.919470, -0.533380, 0.631660, -0.830230, 4.795250, 0.139370, 0.493990, -0.011730,
0.105790, 0.359790, 1.118480, 0.960070, -0.210700, 0.330430, -0.311510, -0.738380, -0.242670,
0.948260, -0.059380, 0.112540, -0.574720, 0.573250, 1.166520, 0.447280, 0.531610, -0.463860, 0.415840,
0.849170, 0.062990, 0.005490, -0.294770, -0.817280, -2.203350, 0.163670, -0.387110, -0.019290, 0.750560,
-0.070830, -0.261030, -0.283820, 0.741320, -0.135420, -1.865830, 0.396520, -3.231290, -0.047080, -0.830960,

0.713880, -0.225970, -0.407400, -0.998040, 0.307860, -1.838020, 1.060720, -0.104270, -0.139280, -0.302230,
-4.810170, -0.398220, -0.906350, -0.624430, -0.398230, 0.239600, 0.896890, 0.426370, -0.186410, 0.838790,
0.984050, 0.182660, 0.589880, -1.415900, -0.553340, 0.529270, 0.027400, -0.054170, -0.202070, -0.522650,

-0.308960, -0.372000, -0.107010, -0.664480, -0.896160, 0.712350, -1.845520, -0.842230, -0.326470, -0.518820,
-0.414240, 0.274380, 1.053740, -0.046400, -0.799100, 0.053970, 1.349000, -0.237490, 1.045200, -0.409740,
-0.210500, -0.716210, 0.509770, -0.968410, -0.031490, 0.069320, -0.088550, 1.599180, -0.465980, 0.905210,

0.931400, 0.749030, -0.693490, -0.615020, 1.075230, 0.359680, 0.435310, 0.147950, -0.496730, -0.072250,
0.582980, 0.205490, -0.249110, -0.615780, -0.250900, -2.332150, -0.050300, -0.712890, 0.957890, 0.682230,
-0.828300, -0.336550, -0.864440, 0.417630, 0.417940, -2.150860, 0.665320, 0.309010, -0.447540, -0.879600,

-0.337570, 0.043900, 0.012730, 0.058130, 0.258140, -0.452780, 0.376280, -0.588270, 0.777240, -2.210430,
-4.531220, 0.814740, -0.494280, -0.840110, 0.167500, 0.408220, 0.624070, 0.983810, -0.779180, 0.080470,
1.450070, -0.830790, -0.658870, -1.400690, -0.404450, -0.074950, -0.245180, -1.231870, -0.277960, -0.193330,

-0.766090, 0.093470, -0.387140, 0.214470, -0.700550, -0.613560, -0.820230, 0.854790, 0.466160, 0.530940,
0.171350, -0.753700, 0.132360, -0.685420, 0.702110, -0.243210, 0.343390, -1.205950, 0.679770, -0.819510,
-0.557620, 0.321320, 0.319410, -0.821790, -0.190040, 0.963100, -0.695950, -0.481420, -0.012840, 1.131770,

-0.537240, 1.428440, 0.465810, 0.950580, 0.800280, 0.785870, 0.634750, 0.245420, -0.548460, -0.617500,
0.714250, 0.416500, -0.740510, -0.586380, -0.516100, -2.502680, -0.892530, 0.188220, -0.451080, -0.178840,
-1.444020, 0.787570, -0.195160, 0.283620, -0.929820, -0.221200, 0.290380, 0.780470, -0.536760, -1.393400,

-0.499970, -0.691090, -1.025410, -0.548230, 0.012840, 0.353770, -0.478970, -0.713380, 1.071660, -1.784340,
-5.563190, 1.215850, -0.563030, 0.933900, 0.763940, 0.655660, 0.873370, 1.351660, -0.257510, -0.010900,
0.321350, -0.329510, -0.578630, -1.397130, -0.997380, -0.790830, 0.186280, -1.129230, -0.263780, -0.003060,

-0.385170, -0.815970, 1.049720, -0.698210, 0.084480, 0.152820, 0.181830, -0.427700, 0.373130, 0.753080,
-0.450080, -1.212850, -0.230660, -0.462210, -0.470270, -0.765660, 0.680370, -1.262280, 0.591450, -0.310320,
0.939320, 0.396480, 0.127660, 0.115750, 0.049130, 0.331870, -0.414000, -0.684500, 0.405840, 0.719550,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.261480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.307550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.942130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.013700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.003080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.512430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.213520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.016710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.625320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.534540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.820770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.947980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.465510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.614050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.246390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.997700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.595070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.328600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.288270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.261340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.909430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.491230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.887730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.633190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.667920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.534970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.246930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.075900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.335600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.646090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.325510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.740670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.215970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.687850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.867870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.827110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.802260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.557600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.836060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.617770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.154650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.400900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.870530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.369250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.286320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.073500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.963750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.540370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.584370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.581110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.370500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.541490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.080350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.552090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.982800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.441550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.206440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.070800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.886220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.902830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.587410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.459730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.206450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.767390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.226530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.613580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.758200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.412360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.372300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.485750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.593640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.716540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.838040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.801940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.459040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.451810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.463510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.180400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.800220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.903430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.780710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.225710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.866600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.302380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.297350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.763770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.332040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.560680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.004570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.858300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.340000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.067250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.254420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.288970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.778920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.856870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.766150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.212600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.160670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (hid1) */
      0.0, -0.648840, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.091210, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, 0.703940, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, 0.379510, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, 0.439240, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.556510, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, -0.346160, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, -0.217130, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, -0.199360, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.181070, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, -0.030220, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, 0.964260, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, 0.814710, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.583160, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, -0.075090, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, -0.685220, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, 0.910000, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.140170, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, 0.005230, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, 0.898480, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.602580, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, 0.391890, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, 0.163540, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.199120, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, -0.459530, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.936030, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, 25.566441, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, -0.138800, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.679130, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, 0.076780, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, -0.466620, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.481360, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, 0.604260, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.065580, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, 0.644290, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, 0.604230, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, 0.920390, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.555070, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.160480, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
1.33899, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
1.34697, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
1.28403, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.10554, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
0.79799, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
1.39275, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
0.07034, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
1.38175, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.09351, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
0.24555, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
1.19491, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.19302, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
0.27652, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.42611, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
1.28749, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
1.18174, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.79249, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
1.04278, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
1.42506, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.08373, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
1.32104, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
0.14082, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
1.35327, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
1.37414, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
0.00000, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
1.42857, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
0.01155, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.11297, 0.500000, 2,
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
