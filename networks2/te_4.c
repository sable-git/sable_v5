/*********************************************************
  TMPtest_new4_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:25:05 2004
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
-0.751740, 0.327480, 0.641880, -0.574160, -0.403680, -0.396280, 0.186470, 0.521980, 0.544050, 0.207030,
0.328830, 0.025300, 0.568960, 0.235170, -0.441740, -0.596180, 0.268040, 0.628210, -0.405680, 0.434910,
-0.236670, -0.649600, 0.989760, -0.766920, 0.332060, -0.718700, -0.219680, -0.055610, -0.216580, 0.484200,
-1.119950, -0.013650, -0.191790, 0.711720, -0.336190, 1.497390, -1.068920, -0.590350, 0.280480, 0.565780,
-0.703680, -2.063160, -0.673350, 0.912600, -0.213980, -1.208800, 0.499770, 4.764070, 0.090050, 0.030370,
0.775640, 1.884240, -0.740360, 0.601890, 0.137830, 0.708190, 2.351650, 1.047130, 0.484610, 0.055860,
-0.938590, 0.395430, -0.853000, 0.539910, -0.224220, 0.925650, -0.411950, 0.378850, 0.220190, -0.157910,
0.400830, 0.854710, -0.618970, 0.587800, 0.081550, 0.804600, 0.379510, -0.360970, 0.217670, -0.565570,
-0.391500, -0.636290, 1.266330, 0.063650, -0.694590, -0.173770, -0.761150, 0.183960, -1.855110, -0.807260,
0.707310, 0.437270, 0.935350, -0.481130, 0.277890, -0.219060, 0.615690, 0.418770, 0.300910, -0.920610,
-0.446150, 0.549110, 0.077150, 0.239750, -2.560240, 0.018860, 0.703580, -0.537200, 0.196860, -0.741630,
0.894630, 1.095970, -0.114520, 0.454420, -3.110300, 1.371910, -0.110980, -0.218250, 0.294680, -0.189850,
-2.665410, -1.324610, -0.460950, 0.709500, -1.086960, 0.909160, -0.548530, -0.464200, -0.881970,
-0.450020, -0.228100, 0.957980, -0.795730, -0.522290, 0.367650, -0.696520, 0.003020, -0.424740, 0.371490,
-0.646300, -0.268590, -0.758580, 0.283630, 0.111620, 0.173280, 0.147950, 1.095900, -0.552050, 0.252360,
0.074010, 0.651650, -0.083060, -0.610630, -4.046300, -0.405040, -0.593490, 0.562380, 0.716610, -0.222890,
-0.716240, -0.333290, 0.601870, -0.908920, 0.081340, 1.174120, 0.053340, 0.374100, 0.051080, -0.388670,
-0.363660, -0.400650, -2.458090, -0.456290, 0.471300, -0.305580, 0.532790, -0.452890, -0.042230, 0.315830,
-0.156110, -1.374280, -0.168050, 1.354370, 0.172610, -0.487800, 1.029860, -1.093590, -0.349600, -0.471100,
-0.039320, 0.373960, 0.641030, -0.954670, -0.805340, 1.002920, 0.303710, -0.765380, 0.141980, -0.211510,
0.634200, -0.589900, 2.256930, -0.011840, 0.096290, -0.925730, -0.583200, -0.768920, -0.656350, -0.493180,
0.633290, -0.830020, -0.463070, -0.985720, 0.604780, -0.045550, 0.402140, 0.096510, -0.107180, 1.010860,
-0.638720, 0.868490, 0.092400, 0.053130, 0.238950, 0.776870, -0.135850, 0.191970, -0.800200, -0.051250,
0.011710, -0.705430, -0.349840, -0.412880, 0.408300, -0.223200, -0.744880, -0.414480, -0.816440, 1.058780,
0.941450, -0.653250, 0.402760, -0.999670, 1.313160, 0.075130, 0.472570, 0.456900, 1.003020, -0.598760,
0.479900, 0.861120, 0.283980, 0.319350, 1.365710, 0.644700, 1.741050, -1.380170, -0.576740,
0.125910, 0.222130, -0.375140, 0.942040, -0.121220, 0.252480, -0.539390, -0.825150, 0.872710, -0.781570,
0.599280, -0.487020, -0.144840, 0.414980, 0.597870, -0.938950, -0.177590, -0.618950, -0.203360, -0.057240,
-0.389010, 0.379230, -0.474780, -0.717970, 0.161660, -0.052050, -0.889710, 0.315180, -0.936300, -0.416180,
-1.413110, -1.348350, 0.471200, 3.321100, 0.654070, -0.775830, -0.556350, -0.255650, -0.388510, -2.670710,
0.042830, -0.906980, -0.574210, 0.508370, -0.117150, 4.014130, 0.719580, -1.450840, -0.437300, 0.230830,
-0.638060, 0.428310, 0.150930, 2.062810, 0.324740, 2.552560, 0.652430, 0.852680, -0.659110, -0.467360,
-0.440560, 0.443510, -0.020050, -0.153080, 0.634160, 4.150820, 0.704470, -0.544270, 0.221750, 0.149040,
-0.660940, -2.124580, 0.196230, -1.035350, 1.302510, -0.613760, -0.388210, -0.401090, -0.226550, 0.277150,
0.158710, 0.599990, -0.813660, 0.873650, 0.119300, -0.592720, 0.946420, 0.129210, -0.878840, 0.748210,
-0.791630, 0.397740, 0.518510, 0.863150, 0.860160, -0.751730, -0.631450, 3.306470, 1.930630, 0.872490,
-0.298050, 0.046050, 0.635160, -0.330030, -0.327210, -0.369560, 0.490680, -2.584330, 0.233310, -0.692320,
-0.658460, 0.159650, -0.399280, -0.376320, 0.987930, -0.126350, 0.904860, 0.539890, 0.588170, -0.097790,
-1.935870, 0.603730, 1.186990, -0.155480, 0.585080, -0.894490, -0.241350, 2.864120, -0.109030,
1.153960, -0.564960, -0.960060, 0.280670, 0.746520, 0.966240, -0.247350, -0.994270, 0.027780, 0.618060,
-0.058470, -0.182120, -0.165030, -0.216860, -0.444800, -0.386860, -0.510920, 0.194650, -0.476340, 1.115170,
-0.919100, -0.485590, 0.052290, 0.316240, 0.924240, -0.299490, -0.092260, -0.525750, 0.439720, 0.824570,
-0.310130, 1.131830, 0.557490, 1.400710, -1.748770, 1.044500, -0.100460, 1.210270, 0.384650, -0.987530,
-0.002520, -0.246240, 0.104330, -0.138730, -0.429980, 0.074990, -1.893300, -0.143590, -0.746870, -0.691770,
-0.392190, 0.602950, 0.726760, 0.033060, 0.901790, -0.377030, -0.394100, -0.755760, 0.934400, -0.730930,
-0.498510, 0.812730, 0.349640, 0.953330, -0.403340, 0.144810, 0.971310, 0.857660, -0.369570, -2.303900,
0.114810, -0.406340, 0.414200, -0.729470, -0.659270, -0.400930, -0.182860, 0.144100, -0.255150, 0.372510,
-0.399170, 0.847300, -0.617980, -0.193020, -1.084630, -0.861990, -0.565360, -0.524050, -0.968540, -0.306210,
0.593590, 0.210010, -0.346710, 0.669980, -0.349790, -0.251130, 0.491650, -0.248440, -0.949280, 1.168840,
0.527360, -0.721400, 0.053210, 0.537520, 0.172500, -0.848440, 0.592670, -1.768120, 0.661810, -1.098550,
0.443190, 1.204340, 0.317200, 0.645900, -0.682550, 0.985570, 0.640890, -0.091670, -0.075060, 0.069880,
-1.658870, 1.156190, -0.272940, -0.092670, 0.725500, 0.577720, 0.352730, -0.240480, -0.293500,
0.288800, 0.062620, 0.152000, -0.080760, 0.053700, 0.469390, -0.170090, 1.094860, 0.745030, -0.141680,
1.404960, 0.519020, 0.155340, 0.243220, -0.411430, -0.566890, 0.027600, -0.735830, 0.067040, -0.477110,
0.573310, -1.017730, -1.174510, -0.049670, -0.797100, 0.891660, 0.093460, -0.640640, -0.546930, -0.514790,
-0.648060, 1.180800, -0.827380, -0.142960, -2.391300, -0.316600, -0.149190, 0.061830, 0.351650, -0.487740,
1.099700, 0.006240, 0.583120, 1.003450, 0.804780, -0.060530, -1.801940, 0.667170, -0.130730, 1.125670,
0.589110, 1.070430, 0.767850, -0.737580, 0.402560, 5.619940, -1.145330, 0.655910, 0.130620, -0.633460,
-2.914260, 0.151890, 0.152290, 3.877270, -0.101590, -2.182300, -0.073740, 5.551900, 0.061670, 0.052930,
0.441810, 0.434410, -0.475610, 0.578270, -0.218650, 0.149820, -0.330090, 0.356720, -0.309550, 0.331590,
0.870770, -0.422750, -4.120330, -1.108410, 0.445360, 0.890970, -0.283350, -0.353180, 0.571480, 0.170660,
0.845980, 0.418510, 0.437900, -0.050650, -0.921410, 1.094140, -0.303770, 1.577580, 0.469540, -0.325750,
1.035080, 0.166040, 0.748800, -0.614740, 1.595180, 0.012220, 0.554770, -1.439110, 0.025900, -0.304730,
1.089410, 0.254170, -0.717830, 0.165590, 2.153290, 1.653590, -0.497260, 0.972100, 0.730390, 0.453440,
0.119420, -0.214950, 0.493240, 0.176240, 0.764830, 0.258620, 0.926610, -1.877340, -0.727960,
-0.537580, 0.576620, 0.473360, 0.343670, -0.199660, 0.372190, 0.000040, -0.522940, -0.046650, -0.008030,
0.397720, 0.827170, -0.408350, -0.366220, -0.070750, 0.685950, -0.629870, -0.679170, -0.682510, -0.430910,
0.015220, 0.049790, -0.306790, -0.319180, -0.039790, -0.672870, 0.526420, 0.978480, 1.061600, 0.871950,
0.891070, 0.204530, -0.324050, 0.582910, -0.163210, 1.037100, 1.705880, -0.644510, -0.704210, -0.367790,
0.256290, 0.255380, -0.360840, 0.405770, 0.957000, -0.135190, 0.933220, -0.437780, 0.237380, -0.209970,
-0.068950, -0.722940, -0.124560, 0.279810, -1.675360, -0.454730, 1.144700, -0.472980, -0.775760, 0.760820,
-0.270980, -1.009870, 0.040400, -1.128200, 0.794010, 0.461460, -1.200530, -0.536800, 0.381300, -0.412510,
0.251850, 0.135020, 0.087000, 0.068100, -0.210210, -0.551480, -0.830270, -0.394890, -0.064660, 0.797140,
0.489350, -1.267930, 0.206110, -0.697800, -1.193550, -0.760840, -0.940770, -0.168230, 0.055530, -0.365570,
-0.050630, -0.881400, -0.673050, -0.932770, 0.419290, 0.464480, 0.226790, -0.205480, 0.187190, 0.369090,
0.512110, -0.506660, -0.373400, 0.050160, -0.432210, -0.591800, 0.805430, 0.128670, -0.205290, 0.060380,
-0.259980, 0.997870, 0.777180, -0.593620, 0.990070, -13.209670, 0.042370, -0.775980, -0.378960, -0.012060,
1.258620, 0.160240, -0.752760, -0.781130, 0.100020, -0.481870, -0.328570, 0.405080, -0.237750,
0.660910, -0.780460, -0.853820, 0.690070, 0.218630, -0.035420, -1.009930, -0.284390, 0.059950, 0.192810,
0.045010, -0.747000, 0.691990, -0.070100, -0.369250, -0.634930, 0.297110, 0.172790, -0.609800, -1.000690,
-0.728730, 0.335620, 0.075630, 0.486680, 0.075970, 0.857340, 0.457430, -0.316300, -0.408540, 0.493490,
-0.021510, -0.559770, 0.344420, 0.511990, -0.654420, -0.081710, -0.525350, 0.380600, -0.546930, -0.066400,
-0.251010, 0.350920, -0.097300, 0.197860, -0.695710, 0.883340, 0.959450, 0.288960, -0.412800, 0.037930,
-0.376640, 0.604160, 2.185300, 0.067180, 0.983290, 0.629660, -0.257110, 0.520080, 2.396480, 0.450830,
-0.106940, 0.477480, -0.201020, 0.742370, 2.522610, -1.498220, -0.113980, 0.735590, -0.524330, 0.647930,
0.902700, -0.678680, -0.090740, -0.183580, 0.055410, 0.314130, -0.663990, 0.502170, 0.816720, 0.232210,
-0.109160, 0.586410, 0.562090, -0.054650, -0.723590, -0.305130, 0.557990, 0.808710, -0.272070, 0.865220,
0.110550, -0.081090, 0.962800, 0.517330, -0.443880, 0.275390, 0.334690, -0.423600, -0.254080, 0.350440,
-0.499950, -0.420630, -0.808260, 0.939010, 1.203920, -0.348930, -0.831570, -2.608270, -0.804280, -0.052040,
-0.552760, -0.144810, -0.397330, -0.149250, 1.446640, 1.303700, -0.596760, 0.387580, -0.992900, 0.640040,
1.248070, -0.618090, 1.071090, -0.443050, 0.410770, 0.760730, -0.005380, 0.970800, -0.379700,
-0.428050, -0.692230, -0.407460, 0.169650, 0.493560, 0.348890, -0.393700, 0.036260, -0.419320, -0.369980,
0.174990, 0.141680, 0.348970, -0.595710, -0.745650, -0.342510, 0.777060, -0.114260, 0.175850, -0.306100,
-1.021150, -0.974930, 0.978170, 0.665050, -0.016840, 0.448360, -0.616470, 0.084380, -0.536770, -0.099300,
-0.459050, -0.227880, 0.822110, 0.266700, -0.052700, -0.974830, -0.140430, 1.323170, 0.410660, -0.021440,
0.645150, -0.338910, 0.406920, -0.655560, 0.579550, -0.693660, -0.501950, -0.571690, -0.095950, -0.112960,
0.127770, -0.218790, 0.019470, -0.876910, -1.763320, 0.639620, 0.814830, -0.623730, 0.402220, -0.799320,
1.302070, 0.486210, 0.733880, -2.852930, 0.494270, 0.014700, -0.930890, 0.192160, 0.184620, 0.984130,
0.290900, -0.806350, -1.112570, 0.664900, -0.538410, -0.343800, 0.021970, 0.533650, 0.782810, 0.189940,
0.826300, 0.829210, -0.535290, 0.610060, 0.790800, 0.567390, 0.231540, -0.578090, -0.810370, 0.874760,
0.758820, 1.123300, 0.592510, 0.142520, 0.185160, 0.250360, 0.027530, -0.518840, -0.524910, -0.300210,
-0.235770, 0.191770, 0.697850, -0.842510, -0.385220, 0.830120, -0.728180, 0.063130, 0.189660, -0.679180,
0.627560, -0.954570, -1.012400, 0.199740, 0.137430, -1.577750, -0.663150, 0.886700, -0.599090, 0.061150,
0.305240, 0.448560, 0.628240, 0.209110, 0.330450, -0.087130, 0.774300, 1.388520, -0.324060,
-0.948950, -1.274440, -0.706520, 0.119500, -0.161210, -1.020570, -0.483610, -0.738290, 0.110050, 1.041370,
0.067320, -0.226390, -0.701730, -0.063950, -0.882120, 0.202500, -0.049330, 0.182420, -0.399080, 0.697060,
-0.789000, 0.072990, -0.432710, 0.566090, 1.449650, -0.592900, 0.751680, 0.832230, 0.665610, 0.116690,
-0.208520, -0.306190, 0.322330, 0.547150, 0.523440, -0.581140, -0.794240, -0.113000, 0.990510, -0.829470,
-1.092320, 0.420360, -0.582200, 0.896530, 0.193380, -1.155890, -1.605180, -0.688010, 0.346110, -0.375340,
0.445050, -0.509190, 0.863780, -0.054360, -0.670400, -0.143000, -0.997590, -0.674880, 0.721140, -0.894740,
-2.638280, 0.083930, -0.308860, -2.215850, 0.290580, 0.928390, 1.284790, -0.283950, -0.106610, -0.566810,
-0.802760, -0.224190, -6.009770, 0.357730, -0.640060, 0.044980, 0.153590, -0.186550, -0.552630, -0.760680,
0.157500, -0.005960, -0.647210, -0.242850, -0.290200, -0.116130, -0.069100, 0.555730, 0.343290, -0.083010,
0.122920, 0.194610, -0.772830, 0.935850, 0.428800, 0.464320, 0.184010, 0.022260, 0.723770, -0.034710,
1.024080, -0.524910, 0.631010, -0.804320, -0.017610, -0.775970, 0.780370, -1.069320, 0.643900, 0.472670,
0.551410, 0.410090, -1.063250, 0.347910, 0.373400, -7.317170, -0.151910, 0.696680, -0.924330, -0.572970,
0.637330, -1.067520, 0.037660, 0.426450, 2.072420, -0.871520, -0.284200, 1.275500, 0.809670,
0.598890, 0.020880, 0.439630, 0.176980, 0.770390, 0.670860, -0.750030, -0.515610, -0.390930, -0.611140,
0.568280, -0.442020, 0.348200, 0.646240, 0.657000, 0.363730, -0.381870, -0.819260, -0.637130, -0.466860,
0.655980, -0.681770, -0.521170, 0.345460, 0.230700, 0.892880, 0.640990, -0.093510, -0.197840, -0.876630,
-0.334580, -1.028020, -0.027990, -0.662530, -0.617730, 0.258170, 0.027380, 0.444560, -0.227680, 0.872960,
-0.742040, -0.581250, -0.117510, 1.032590, -0.971870, -0.237870, -0.639340, -0.732160, -0.208100, 0.041370,
0.376240, -1.645410, 0.517950, -0.321430, 5.379320, 3.787480, -2.439320, -0.117290, 0.668570, 0.679360,
-0.488200, 0.459510, -0.585270, -0.967650, 0.026500, 1.034420, -0.145920, 0.339000, 0.905700, -0.070010,
-0.824880, -0.145890, -0.192960, -0.723050, -0.576200, -0.377890, -0.392070, -0.426280, 0.105470, 0.073070,
0.615310, 0.130530, 0.111720, 0.541450, -0.676210, 0.340300, 0.381770, 0.014030, -0.978890, 0.316370,
-0.046780, 1.037600, -0.744730, 0.901770, 0.960010, 0.250190, 0.633320, -0.240340, 1.442840, 0.595340,
-0.657600, -0.393730, 0.674250, -0.940870, -0.825890, 0.743300, 0.471040, -2.605920, 0.760730, -0.450360,
1.057940, -0.070380, -0.226510, -0.403760, -0.045980, -1.579750, -0.482520, 0.336490, 0.201330, 0.050440,
0.190760, -0.564100, 0.718220, 0.622640, -0.080470, 0.015460, 0.411380, 0.878650, 0.133370,
0.092480, -0.452100, -0.865950, 0.190580, -0.154940, -0.737800, 0.554520, -0.937600, 0.523160, -0.458410,
-0.130650, -0.660910, -0.619690, -0.201320, 0.675940, 0.125340, 1.035160, -0.119080, -0.515530, 0.328110,
0.001150, -0.164850, 0.388270, 1.026890, 0.821980, 1.063110, 0.143680, 0.666190, -0.583380, 0.148280,
0.673910, 0.011940, -0.542200, -0.036990, 2.625280, 0.325350, -0.504890, 0.518250, -0.857930, 0.757180,
1.029700, 0.222560, -0.810140, -0.479100, -0.604520, -0.138650, 1.245870, -1.004070, 0.096370, 0.436030,
-0.201080, 0.676680, -0.321300, -1.505990, -0.236790, -0.376670, 2.201630, 1.038750, -0.143550, -1.183520,
0.028880, -0.118580, -0.253800, 1.115080, 0.783470, -0.341030, 1.080680, 0.531140, -1.041360, 0.654990,
-0.618320, 0.125030, -0.616700, 0.132990, 0.001230, -0.223190, -0.728220, -0.888330, -0.393400, -0.833260,
-0.678010, -0.565140, -0.347940, 0.057560, -0.570360, -0.752410, -0.975300, -0.079640, -0.478560, 0.249350,
-0.418640, 0.542920, -0.065610, 0.584550, -1.030460, -0.843000, -0.663990, 0.328590, 0.391370, 0.325390,
0.293190, -0.397520, -0.158260, -0.185680, -0.102570, -0.539290, -0.704900, 1.413620, -0.934410, 0.176420,
0.543840, -0.273190, -0.755950, 0.119510, -0.035630, -0.815900, -1.125090, -0.539970, 0.393950, -0.202290,
0.486780, 0.512920, -0.446310, 1.089670, 1.695440, -0.933270, 1.144470, 0.466670, 0.099430,
-0.210820, 0.083930, 0.963110, 0.226950, -0.536990, -0.552540, -0.860500, -0.481690, 0.436200, -0.581090,
0.214040, 0.326480, 0.582000, -0.565060, 0.592320, -0.270750, 0.623850, 1.003400, -0.924260, 0.072220,
-0.482820, 0.962290, -0.811770, -0.946590, -0.579390, -0.706740, -0.186660, 0.342380, 1.088900, -0.416310,
0.088190, -0.639090, 0.077450, 0.974860, 0.362310, -0.203260, 0.216480, 0.171080, -0.303760, -0.511380,
0.850290, 0.391520, 0.674160, 0.032820, 0.801680, -0.624430, -0.778680, -0.681760, -0.360030, -0.439330,
0.328950, -0.755650, -0.614580, 0.068120, -0.462280, -2.141940, 0.052050, 0.025150, 0.601210, 0.088330,
0.409060, -0.363710, -0.533450, 1.695840, 0.069350, -0.385810, -0.486830, 0.126680, 0.526710, -0.608230,
0.433560, 0.029310, 0.428480, 0.156490, -0.617730, 0.631230, 0.329860, -0.628820, 0.360680, 0.728850,
0.106860, 0.825600, 0.219270, 0.716640, 0.118530, 0.618280, 1.052740, 0.726220, 0.168350, 0.565780,
0.363210, -0.241930, 0.372750, 0.260160, 0.725180, -0.140940, -0.416120, 0.583660, 0.955260, 0.341840,
0.690670, 0.671520, 0.129350, -0.499650, 0.660670, -0.559120, -0.871980, 2.845300, 0.076200, -0.106260,
0.043150, 0.895130, 0.297360, -0.212600, 3.758000, -1.578340, -0.674610, 0.617060, -0.973850, -0.825880,
0.125450, -0.741600, 0.776560, -0.804830, 0.552090, -0.476460, 0.127630, -0.856890, -0.074610,
0.138000, -0.002900, -0.132290, 0.183680, 0.737920, -0.775850, 1.008570, -0.073150, 0.514390, 0.996540,
0.188870, -0.253980, -0.267390, 0.806550, 0.706620, -0.177360, 0.277630, -0.184340, -0.239710, -0.613390,
0.836080, -0.408310, 0.982930, 0.298290, 0.628200, -0.336960, 0.335610, -0.234150, -0.656800, 0.145100,
-0.648270, -0.153340, -0.522730, -0.109150, -0.220830, -0.252830, -0.168090, 0.107230, -0.390930, -0.932070,
0.368970, -0.152490, -0.247300, -3.063560, -0.377540, -0.036100, -0.813550, -0.763780, -0.246730, -1.835700,
0.432940, 0.260880, -1.429390, -0.771860, -1.023110, -0.653200, -0.028410, 0.044420, -0.400780, -0.396560,
0.373240, -1.232300, 0.584270, 0.354990, -0.573270, 0.407750, 0.826890, -0.804600, 0.591000, 0.693450,
0.918730, 0.160750, 0.503590, -0.964170, -0.360100, -0.973550, 0.719260, -0.883310, 0.936010, 1.118040,
-0.196250, -0.628420, -0.330870, 0.904040, 0.006820, -0.536480, 0.957250, -0.736560, -0.036200, 0.440580,
0.805330, -0.576240, -0.643160, 0.568930, 0.859880, 0.709200, 2.308870, -0.358940, 0.332380, -0.774220,
-0.216190, -0.099450, -0.494160, 0.038430, -1.266210, 0.150450, 0.854690, -1.256370, 0.762010, -0.623950,
0.476000, -0.065510, -0.546430, -0.647380, -0.875350, 0.351340, -0.665790, -0.092070, 0.289360, 0.531840,
0.145250, 1.992500, -0.285340, 0.556550, -0.624570, -0.370610, 0.017330, 0.466860, 0.396160,
0.211930, -2.281360, 0.091450, -0.594720, -0.136920, -0.844440, -0.563520, 0.369340, -0.203340, -0.641940,
0.765170, 0.720640, -1.174470, -0.069790, 0.261730, 0.818450, -0.287510, -0.886080, 0.497690, -0.025390,
-1.211170, -1.583100, 3.846610, -0.023770, 0.023110, -0.170620, -0.702850, -1.491020, 0.360310, 0.733620,
0.453900, 1.427990, 0.173200, 0.720890, -0.255770, -0.841320, 0.537530, -0.482190, -1.089940, 0.920500,
0.277610, -1.046110, 0.218400, 0.876610, -1.289640, -0.425500, -0.667790, -2.167200, -0.475520, -0.054200,
-0.581320, -0.127490, -0.609990, -0.446040, -0.292290, 0.400900, -1.077320, 1.065530, 0.655960, 0.512660,
-0.459590, -0.175310, 0.516430, -0.522150, 0.314700, 0.731050, -0.535130, 0.988640, -0.007670, -0.384920,
0.386680, -0.344270, 1.016430, -0.472210, -0.848610, 0.095650, -0.169660, -0.807780, -1.602690, -0.307970,
0.038910, 0.774710, -0.673660, 0.090860, -0.819940, -0.188220, 0.078500, 0.297620, -0.544160, -0.068630,
0.869160, -0.105170, 0.138710, -0.202770, 0.616960, 0.611440, 0.905310, 0.620860, 0.517480, -0.088660,
-0.855820, 0.242820, 0.290000, -0.865630, -0.940970, 0.716510, 0.116460, -1.810750, 0.072660, -1.705570,
-0.536440, 0.742830, 1.287870, -0.790240, -2.581380, -0.492150, 0.592620, -0.026110, -0.016950, -0.706140,
-0.285670, 0.202380, -1.305700, 0.579460, 0.127900, -0.946850, 0.194530, 4.047540, 0.166010,
-0.142940, 0.133490, 0.615580, -0.789570, -0.265820, 0.468610, -0.484030, -0.963280, 0.800330, -0.209780,
-0.481480, 0.268770, -0.720830, 0.265230, 0.778570, -0.978390, -0.819700, 0.696620, -0.450190, 0.538200,
-1.043650, 0.845390, 0.157800, -0.331490, -0.862460, -1.104820, 0.141410, 0.781660, 1.190320, 0.496620,
0.615630, -0.354560, -0.939270, 0.234540, -1.807640, 0.560550, -0.832170, 0.779720, -0.182080, -0.867010,
0.488960, 0.919890, 0.713330, -0.250140, 0.145220, -1.291480, -1.030190, 0.164860, 0.803710, -0.694150,
-0.447870, -0.213480, -0.126660, 1.086350, 0.041830, -1.047470, 0.221570, 0.275720, -0.632500, -0.169600,
-0.574600, 0.804080, 0.428450, -0.037060, -1.054200, 1.061350, 0.375960, 0.020860, -0.906320, -0.762760,
0.327020, -0.600580, -0.383230, -0.284880, -0.423250, 0.228970, -0.441290, 0.640590, 0.759090, 0.931630,
-0.116640, 0.179010, 0.376790, 0.548590, 0.118400, -0.872560, -0.320100, -0.516760, -0.216340, 0.500650,
-0.877630, -0.763180, -0.002740, 0.539580, 0.615750, -0.963600, -0.960710, -0.343190, 0.371500, -0.830820,
-0.120570, -0.413440, 0.469830, 0.093740, -0.099530, 0.684950, -0.968640, 4.400020, -0.396150, 0.474790,
0.509430, -0.504110, -0.546320, -0.639510, 4.844220, -1.059160, 0.508670, -0.026030, 0.104480, -0.909370,
-0.309310, 0.544920, -0.217940, 0.415140, 0.224300, 0.313610, 0.185720, -0.309770, 0.464490,
-2.211890, -0.404120, 0.561470, 0.731550, -0.253500, -0.879910, 0.932020, -0.505010, 0.377710, -1.105780,
-0.029630, -0.629410, 0.786600, -0.834680, 0.552090, -0.578790, 0.043300, -0.632860, -0.125620, -0.638880,
0.515920, 0.667340, -0.632770, -1.054910, -0.751520, 1.362770, 0.329550, 0.467830, 0.159690, -0.311760,
-0.408930, -0.650200, 0.539840, -0.310030, 0.753990, -0.732990, -0.880500, -0.482130, 0.298950, -0.465650,
0.404530, -0.062250, -0.163210, -0.324780, 0.226020, 0.113960, -0.105890, 0.420840, 5.975990, -0.137540,
1.597420, -3.126730, 0.154900, -0.904300, -1.431550, 0.420300, 0.449200, 0.025950, 0.164820, -1.007400,
-3.690220, 0.492170, 0.491630, -13.100760, 0.310600, -0.680080, -1.243210, 0.682740, -0.937900, 0.843450,
-0.542800, 0.263030, -7.065400, 0.725870, -0.691960, 0.669900, -0.599820, 0.397720, 0.517680, 0.430460,
-0.172660, -5.814890, -0.754920, 1.374760, 3.639870, 0.037540, -0.468470, -1.322130, -0.210570, 0.656520,
-3.586750, 1.294480, -0.206790, 0.373290, -1.049110, 0.753510, 0.015520, -0.874400, -0.578790, -0.473110,
-0.124170, -0.315770, -0.029630, 0.160100, 0.833210, 0.618960, 0.276730, -0.924450, 0.593170, 0.040250,
-0.581430, 0.174360, -0.201630, -1.772650, -0.100220, 1.344080, -1.205270, -0.166970, 0.314760, 1.905030,
2.411830, 1.059410, -0.385940, -0.716550, 0.135500, -1.193580, 1.005650, 1.465050, 0.675520,
-1.635850, 1.040790, -0.024010, -0.374750, -0.490540, -0.737480, 0.436650, -0.851960, 0.963330, 0.311500,
-1.129740, -0.154220, -1.026640, 0.692690, 0.939590, -0.368830, 0.445120, -0.342640, 1.291340, 0.820190,
-0.736790, -0.562250, -0.957050, -0.690220, 0.591320, 0.362780, 0.778920, 0.284190, -0.210170, 0.730440,
0.501950, 0.194080, 0.650150, 0.359670, -0.086590, 0.298680, -0.713440, 1.424750, 1.106830, 1.404280,
0.296970, -0.507750, -0.461000, -0.662670, -0.194610, 1.192390, -1.101540, 0.189440, -0.601060, -1.150670,
-0.369460, -0.955520, 0.555930, -0.556870, 0.754360, 0.197130, -0.004990, -0.646160, 0.787440, -0.387220,
-0.321380, 0.929200, 0.655840, 0.739500, 0.119790, -1.525960, 0.325830, 1.458020, 0.383900, 0.439150,
3.189680, -2.410490, 0.159660, -0.051740, -2.633800, 0.572300, 4.839920, 1.008120, -0.158910, -1.009090,
-1.208080, -0.251780, -0.935190, -3.252150, 0.985910, -0.883900, 1.888500, -0.136180, 0.625210, -0.612650,
-0.364130, -3.722950, -4.996840, 0.455220, -1.077390, 0.473770, 0.865790, -1.925300, -2.290260, 0.731970,
0.810630, -1.173300, -0.589260, -0.440740, 0.381770, 0.165370, -1.398220, -6.487850, 0.709020, -2.560300,
-0.170390, 0.418170, 0.003570, -0.085850, -62.184662, 0.493090, -0.773270, -1.547150, 0.764530, -0.513540,
-0.606880, -0.796470, 0.220110, -0.736550, -0.085940, 0.187580, -0.245370, 4.546140, -1.235830,
0.176070, -0.182170, -0.499770, -0.599250, 0.869530, 0.406780, -0.353410, -0.214350, -0.145440, 0.777160,
0.744700, -0.242180, 0.512760, -0.186880, 0.257440, 0.835720, 0.145650, -0.577220, -0.580000, 1.832980,
-0.628090, 0.555250, -0.483760, -0.066440, -0.845140, 0.466100, 0.399850, -0.339940, -0.739040, -0.897950,
0.294750, -1.245990, -0.342710, 0.747190, -0.417170, 1.150680, -0.174570, -0.242290, -0.135080, 0.701250,
-0.130190, 0.003530, 0.770320, -1.098240, 1.923250, -0.023140, -1.082990, 0.861130, -0.500980, 0.429870,
0.654500, -0.168980, -0.519220, 0.828260, 0.268460, 0.350270, 1.395920, -0.955140, -0.715830, -0.074950,
0.049110, 0.546260, -0.463570, -0.049980, -0.081390, -0.511580, 0.793940, -0.416760, -0.294810, -0.351720,
-0.056660, 0.631340, 0.751330, -0.851350, 0.607360, -0.473870, 0.521120, -0.014280, -0.699570, -1.330380,
-0.049690, 0.193280, -0.323730, -0.288340, -0.925180, 0.241460, -0.036940, 0.710470, -0.331580, 0.078500,
-0.323330, -0.557440, -0.858330, 0.149580, -0.268190, 0.997000, 0.290010, 0.221370, -0.429620, 0.443720,
0.493720, 0.721270, 0.917550, -0.232090, 0.349510, 0.329090, -0.309890, 0.027940, -0.822280, -0.322320,
-0.586370, -0.927960, -0.490680, -0.726700, -0.627580, 2.823000, 0.325900, 1.458000, 0.300680, 0.546100,
0.750010, 1.204080, 0.237050, 0.405720, 0.121830, 0.317590, -0.265380, -0.398600, 0.317930,
-0.145320, -0.672760, 0.073360, -1.300600, 0.508570, 0.915600, 0.631540, 0.783390, -0.271620, -0.272720,
-0.287820, 0.454850, 0.980620, 0.692080, -0.446950, 0.110600, 0.134170, -0.771940, 0.748630, 0.704120,
0.166150, -0.073420, -1.003400, -0.942940, -0.582390, 0.645770, -0.673020, 0.889950, -1.016030, -0.231480,
0.017730, -0.882960, 0.076900, -0.517350, 0.490810, 0.515630, 0.823570, -1.252400, 0.669320, -0.500780,
-1.169000, -0.432900, -0.202740, 1.318830, 0.829770, -0.244040, 0.166030, -0.568960, -0.067160, 0.507790,
0.342050, 0.092990, 0.238100, -0.140770, 0.061160, 0.638520, 0.305510, 0.773710, 0.416170, -0.636030,
0.310090, 0.098980, -0.501230, -0.735920, 0.914980, -0.803810, -1.568460, -0.813660, -0.724280, 1.497360,
0.413820, 0.347520, -1.423850, -0.677070, 0.837130, -1.167790, 0.600980, -0.362140, 3.899380, 0.197910,
0.657600, -3.120260, 0.522840, -0.171540, -0.505340, -0.348500, 0.343250, 0.826120, 0.067180, 0.070620,
-0.813350, -0.911910, -0.152470, -0.347640, -0.029080, 0.401780, -1.749840, 0.891980, 0.154260, 0.400930,
-1.383780, 0.369910, -1.397480, -0.956440, 0.083490, 0.447700, 0.683170, 2.864160, -0.009020, 1.825750,
1.439400, -0.142110, -0.278460, -1.172260, 1.297140, -5.693540, 0.839170, -0.951910, -0.176070, -0.083530,
-0.476970, -19.463640, 1.923140, 0.603470, -0.689540, 0.186830, -0.787500, -1.352730, 0.787640,
0.009810, 1.150050, -0.172950, -0.880280, -0.470810, 1.204260, 0.418120, 0.717210, -0.202830, 0.051770,
-0.185090, -0.368880, 0.365530, 0.281560, 0.135510, -0.020090, 0.862650, 0.802470, 0.430510, 1.144830,
1.129250, -1.104270, -0.270930, 0.886840, 0.159480, 0.362220, 0.182700, 0.539140, 0.522110, -0.086540,
-0.424230, 0.447320, -0.106340, -1.101810, -0.056350, 0.461910, 0.625950, -1.294600, 1.104890, -0.092070,
0.876330, 0.077300, -0.909040, 0.003640, 0.723090, 0.957490, 1.435410, -0.063300, 0.656900, -0.298570,
-0.811870, -0.527130, 1.560090, 1.368010, -0.347100, 0.886050, 1.132960, -0.449110, -0.163560, -0.578130,
-0.472820, 1.349990, 1.186310, -0.448650, -0.157490, 0.632920, -0.437890, -1.696800, 0.896070, -0.705740,
-0.703990, -0.577830, -0.147530, -0.031260, 0.149650, -0.250930, -0.524450, -0.216290, 0.038880, -0.887650,
0.735190, -1.169060, 0.498330, 0.194330, 0.073490, 0.950130, -0.241170, 0.842170, -0.826630, -0.061210,
-0.940120, 3.655910, 0.476910, 1.048790, 0.301800, 0.518600, -0.204920, -0.247270, 0.409440, -0.858160,
-1.356650, 0.036590, -0.115860, 0.206180, -0.339390, 0.312910, -0.345490, -3.582050, -0.398360, 1.196520,
0.429500, -0.346380, -1.079820, -1.052560, -4.924440, 0.643180, -0.196300, 2.660010, 0.182880, 0.698190,
-0.993400, 0.595350, 0.696110, 0.694870, -0.264210, 0.976150, -0.526280, 0.701220, -0.594290,
-3.058670, 0.169980, 0.827910, 0.115270, -1.465450, -0.517870, -0.756110, 0.970190, -0.175540, -1.334850,
-0.667140, -0.193030, -0.333980, -0.092300, 0.950730, -1.297770, 0.574930, 0.300190, 0.295610, 0.193170,
0.372260, -0.154310, -0.188830, -0.189000, -1.496240, 0.317770, -0.547180, -0.300340, 0.196940, -0.294250,
-0.767720, 0.306480, 0.961800, -0.776620, -0.222470, 0.687570, -0.329660, -0.508950, 0.211210, 0.664830,
0.630790, 0.017280, 0.000510, 1.102330, 0.748910, -0.064760, -0.019120, -0.738340, -0.252310, -0.539710,
0.705500, -0.037820, -0.292720, -1.185640, -0.620020, -0.696620, 1.011530, -0.460010, -2.134510, -0.963170,
0.621690, -0.320090, -0.633670, -0.511210, -0.145300, 0.113720, -0.013210, -0.432860, 0.155890, -0.177640,
-1.212490, 0.027590, -1.352860, -0.797000, -0.077580, 0.714880, -0.227060, 0.268790, 0.136240, 0.000990,
0.108690, -0.214220, 0.563580, 0.267820, -0.906910, 0.221130, -0.536890, 0.303480, 0.160890, -0.445350,
-2.011880, 0.182220, -0.290280, 0.029140, -0.699080, 0.032310, -1.456900, 2.150260, 0.545770, 0.425340,
-0.467280, -0.636170, 0.679330, -0.806510, 0.713670, 0.028470, -0.320530, 10.242010, 0.350240, -0.496210,
-0.416240, -0.342460, 0.090660, -0.935560, 18.326080, 0.613890, 0.075060, -0.280120, 0.322530, -0.568930,
0.522590, -2.354350, 0.576450, 1.074360, 2.539780, 0.886870, 1.076480, -0.622310, 0.116990,
0.813190, -0.200090, -0.637940, -0.536840, 0.711900, 0.213390, 0.249300, 0.123970, 0.495490, 1.080470,
-0.165790, 0.127810, 0.959490, -0.679610, 0.352020, -0.973170, 1.252130, -0.596470, -0.470370, 0.104350,
0.073450, 0.835090, 0.459110, 0.338600, -0.389120, -0.484600, -0.529010, -0.082580, -1.775980, -0.837220,
0.751530, -0.244300, 0.670870, -0.020910, 0.951200, 0.549750, 0.261050, 0.591600, -0.364320, 0.432720,
0.536610, 0.166770, -1.264030, -0.448010, -0.220350, -0.908500, 0.767420, -0.874990, -0.341370, -0.755660,
0.426400, 0.826410, 0.319220, 0.415900, -1.841260, 0.245650, 0.798440, -0.004140, -1.046110, 0.120550,
-0.161320, -0.237780, 0.385230, -0.854670, 0.207850, 0.939800, 0.472740, -1.708800, -0.448290, 0.111700,
-1.265290, -1.114050, -0.664050, -0.356560, 0.483670, -0.015580, -1.062250, 0.618090, 0.640590, -0.534570,
-0.011860, 0.130940, -0.549410, 0.626200, -1.024720, 0.442100, -0.621490, 0.599450, -0.891070, -0.483310,
-0.302970, 0.070450, -1.128790, 0.194440, -0.739490, -0.924180, 0.093560, 0.524380, -0.641350, -0.617460,
0.042220, 0.670990, -0.308420, 0.280660, -0.281010, -0.105280, 0.424590, 2.791920, -0.309110, 1.030520,
0.573810, -0.170440, -0.785820, -0.664970, 1.337210, 1.247850, -0.309730, -0.139980, 0.514810, 0.705310,
-0.371140, -0.586310, 0.236610, -0.447630, -0.602900, 0.396220, -0.686730, -1.662080, 0.724290,
0.544630, 0.162630, 0.107800, 0.632060, 0.774880, 0.337600, 0.969340, -0.110390, -0.382830, -0.087670,
-0.066650, -0.186110, 0.113900, 0.427810, 0.399780, -0.250830, -0.977770, 0.276060, -0.340680, -0.242870,
-0.126300, 0.863280, 0.726250, 0.028590, -0.441920, -0.470290, -0.652800, -0.473650, 0.637800, 0.174050,
-0.725010, -1.071790, -0.906040, -0.156540, -2.525740, 0.703870, 0.733340, 0.606320, 0.566180, 0.451990,
-0.095630, 0.618610, 0.908080, -1.615350, -0.381170, -0.915640, 0.381860, 0.270760, -0.574680, -0.591810,
-0.325350, 0.915030, -6.356230, 0.437610, 1.727520, -1.120270, -0.585370, 0.114460, -1.546290, 0.522370,
-0.733920, -0.040850, -0.289690, -0.096720, -2.320060, 0.334030, 0.386320, 2.321160, 0.500530, 0.634420,
0.417050, 0.601580, -0.193530, -1.588630, -0.383090, -0.465820, 0.130440, -0.335790, 0.681510, 0.601020,
-0.447580, 0.910870, -0.769520, 0.342850, 0.751760, -1.042560, 0.294610, -0.759330, 0.947290, -1.083380,
-0.469060, -0.993700, -0.389850, -0.095500, -0.337000, 0.636330, 0.970960, 0.668300, 0.307380, -0.887330,
0.368790, -0.465040, -0.740510, 0.784850, 0.343400, -0.984550, -0.662660, -0.883450, 0.743880, -0.108630,
0.042650, 0.162720, 0.154720, -0.115050, -0.072480, 1.048690, -1.050200, 0.619890, -0.989960, -0.839080,
0.406830, -0.454890, 0.859990, 0.568730, 0.839550, 0.045660, -0.664250, 0.772290, -0.893070,
-0.924690, -0.302710, -0.063150, -0.320040, -0.583200, 0.122020, 0.303680, -0.231250, -0.738700, -0.137580,
-0.393290, -1.242730, -0.568430, -0.834130, 0.178560, -0.238130, 0.710050, 1.064990, 0.030730, 0.562280,
-0.290550, 0.121150, 0.011440, 0.413870, -0.997040, -1.104040, -0.317980, 0.596000, 0.937250, -0.020140,
-0.124900, -1.577480, 0.593780, -0.786470, -5.359070, 0.883750, 0.120100, -2.114730, -0.365150, -0.805800,
-3.404310, 0.087650, -1.197560, -2.746790, -0.559800, -0.722630, -5.881990, 0.840870, 0.299890, -0.390780,
0.552740, -0.392060, 0.502200, 0.554500, -1.150440, -2.384490, 0.650280, 0.769180, 0.051360, -1.468870,
-0.494850, 1.192310, 0.434550, -0.676840, 1.522650, 0.954410, 0.612400, -1.110110, 0.037350, -0.931710,
0.204940, 0.305390, -0.952310, -0.063930, 0.075700, 0.512280, 0.545890, -3.014410, 0.602830, -1.337940,
-0.412430, -0.317850, 0.193420, 0.331320, 0.075930, 0.444340, 0.068390, -0.365290, -0.009810, 0.050700,
-0.326500, 0.928510, 1.277020, -0.177340, -0.312480, -0.404060, -0.624670, 1.552570, 0.062430, 0.411370,
-0.181310, 0.060830, -0.086010, -0.133520, -0.354090, 0.028930, 0.734350, 0.172130, -0.027790, 1.581230,
0.461870, 0.403670, 0.323130, 0.482330, -0.044520, 0.904750, 0.478270, -0.027750, -0.612030, 0.146120,
0.850260, -0.681220, 0.405180, 0.359640, -0.455750, -0.098460, 0.398290, 2.747890, -0.793820,
-0.086780, 0.758800, 0.017340, 0.000640, 0.459260, -0.194310, 0.034460, 0.305980, 0.308790, 0.092530,
-0.625710, 0.765880, -0.281960, 1.006380, -0.865350, -0.779310, -0.073190, 0.446130, -0.144900, -0.620270,
0.402680, -0.390650, -0.034130, 1.128310, 0.098900, -0.647130, 0.113430, -0.400500, -0.570730, 0.965820,
1.080590, -1.353130, 0.067680, -1.033770, 1.735870, 0.009850, 1.097710, -3.268030, -0.498340, -0.279500,
-1.178390, -1.325940, -0.013440, 3.755490, 1.062180, -0.243330, -0.335490, 0.920610, -1.042360, -1.207350,
-0.951900, -0.648960, -0.751170, 1.213720, -1.231030, 0.751050, 2.742210, -0.538470, -1.264330, 1.383120,
-1.090120, -0.620700, 0.423160, -1.466910, 0.411200, 1.256180, 0.308300, -2.542540, -0.054780, -0.116430,
-0.514570, -0.503820, 0.479220, 0.583510, 0.172720, 0.345510, -1.848200, 0.573720, 0.639220, -0.567060,
0.466550, -1.204900, 2.166000, 0.250160, -0.330940, -7.552290, 0.610180, 0.124670, -0.790810, 0.078410,
0.122650, 12.409560, -0.563250, 0.027270, 0.507910, 1.114010, -0.574600, -2.371750, -0.214760, -0.793640,
0.152430, 1.019560, -1.249970, 0.844630, -2.140080, -0.554500, 2.847080, 2.460290, -0.260070, -0.167110,
0.894710, 0.756810, 0.007180, -0.572810, 0.891060, -0.908420, 0.480100, 0.475780, -0.172410, 2.684060,
1.086720, 1.292420, -0.178890, -0.419770, -0.524950, 1.498300, -0.501260, -0.982360, -0.825030,
0.380890, -0.249280, -0.366270, 0.582980, 0.315130, 0.011810, 0.892570, 0.035240, 0.314100, 0.508070,
-1.734020, 0.465440, 0.197030, 0.606360, -0.482600, -0.698690, 0.692730, -0.246750, -0.305300, 0.732690,
0.404510, -0.116110, 0.011690, -0.736150, 0.283700, -0.447590, -1.092700, 0.125660, 0.032310, -0.848770,
0.796040, -0.392780, 1.973800, -0.212260, -0.546050, -0.391700, -0.143080, -0.471720, 1.112490, 0.816150,
0.432060, 0.150170, -0.464250, 0.857940, -0.099590, 1.615130, 0.367700, -4.479320, -0.854340, 0.255480,
-0.416520, -0.990840, -1.026700, 0.724430, -0.756810, 0.332860, -0.822050, 0.149560, 0.005220, -1.047920,
-0.405840, -0.547450, -0.034990, 0.324990, -0.769900, -0.321350, 0.474860, -0.326550, -0.948970, -0.290120,
0.114640, 0.858890, 0.720780, -3.334160, 0.064660, -0.012960, -0.729850, -0.987550, 0.138920, 0.110470,
0.238820, 0.176320, 0.198310, 0.390470, -0.638040, 0.578020, -1.091490, 0.628370, 0.573680, 0.666250,
-0.618850, 0.076410, 0.490340, -0.272290, -0.141550, -0.671160, -0.833440, -0.533300, -0.544960, -0.432150,
1.465930, -0.691560, -0.057380, -0.033570, -0.024470, 0.858840, -1.543000, 0.485390, -0.427030, -0.878850,
-0.280720, 0.868390, -0.273590, 0.538580, 1.195360, -0.100840, -0.012660, 0.524820, 0.209940, -0.185450,
-1.053250, -0.243490, 0.839830, 0.417560, 0.760270, 0.459320, -0.079470, 1.426490, 1.344610,
-0.038810, 0.206320, -0.100830, -1.173690, -0.881040, 1.117930, 0.199680, -0.113860, 0.050720, -0.707910,
-0.501080, -0.101740, 0.603820, 0.834690, -0.568320, -1.066980, 0.869740, -1.453160, -0.342110, -0.589570,
1.145700, 0.046560, 0.293400, -0.842530, 0.047010, 0.512750, -0.969010, -0.051820, 0.037890, -0.045160,
0.292460, 0.639100, 0.005030, 2.117310, 0.757400, 0.221960, -0.161830, 0.521490, 0.498900, 0.320590,
0.954150, -0.804530, -0.090940, -0.705380, -1.206940, 1.088160, 0.516710, -0.835910, -0.391910, 0.113240,
-0.245000, 0.365980, 0.138980, -1.093160, 0.432080, -0.340810, -0.078730, -0.996910, -0.322380, -1.287500,
-0.099810, -0.631230, 0.141070, 0.035060, -0.437080, -0.929160, 0.983860, 0.489270, 0.489760, 0.305910,
-0.107960, -0.322670, 0.277060, -0.608680, 0.411940, -0.206630, -0.289060, -0.336370, 0.066200, 0.630490,
0.301940, 0.081300, -0.126400, 1.114580, -0.820530, -0.657540, -0.557300, 0.330970, -0.077440, -0.151320,
-0.223020, 0.680690, -0.151580, 0.647580, -0.530670, 0.988150, 0.415330, 1.431410, 0.467700, -0.364900,
-0.528700, 1.105570, -0.010370, -0.563960, -0.114600, -0.396450, 0.827390, 3.841850, 0.963890, -0.965700,
-0.473080, -0.973330, 0.186540, -0.622320, 0.690210, 0.385680, -0.083950, 0.640280, 0.139120, -1.021840,
0.904170, -0.845270, -0.516040, 0.036830, 0.312440, -1.239760, 0.487010, 2.030040, -0.494070,
-0.081040, -0.798390, -0.174820, 0.576720, 0.538730, -0.148180, -0.354290, -0.625380, 0.582860, 0.875750,
0.785350, -0.634460, -0.047200, 0.665610, 0.130260, 0.325530, -0.441360, 0.069330, 0.458540, 0.122070,
0.820120, -0.634330, -0.261250, 0.588910, 0.005950, 0.324040, 0.207440, -1.249140, -0.349330, -0.904320,
-0.603170, 0.462160, -0.458160, -0.190040, -0.472870, -0.458770, 1.064960, 0.156090, -1.003850, 0.694970,
-0.785210, 0.284470, -1.162630, -0.099100, -0.944550, 5.352470, -1.144450, -0.309810, 0.319460, 0.673220,
-0.461230, -2.060750, -0.623330, 1.505640, 1.754970, -1.202620, 0.337530, 0.866900, -1.130440, 1.122010,
-0.796230, -0.391300, 0.133050, 0.810130, -0.263080, -0.327770, -0.752580, -0.665720, 1.262450, 0.410330,
0.984930, 0.707660, -0.229740, -1.020480, -0.107530, 0.940700, 0.640930, -0.305710, -0.702870, -0.142850,
-0.649650, 0.620640, 0.597020, 0.223900, 0.091220, 0.248300, -0.073070, 0.095970, -0.095160, 0.580930,
-0.672130, 0.242720, 0.915880, 0.069900, 0.184550, -0.505650, -0.337390, 0.513180, -0.338520, -0.039630,
-0.546970, -0.318720, 0.550050, -0.578240, -2.360620, 0.674140, -0.379680, -5.255190, 0.487450, -0.256300,
0.714250, -0.354790, 0.660700, -0.615390, 0.129100, 1.898870, 0.597290, 0.364410, -0.413960, 0.147230,
-0.663410, 0.868140, -0.656600, -0.583940, -0.635420, -0.496980, -0.544060, -6.917780, -0.022450,
-0.307510, 0.730600, -0.585220, 1.029250, 0.475410, 0.520500, -0.824540, -0.220670, -0.212860, 1.278480,
0.143650, 0.889110, 0.360940, -0.550180, 0.656590, 0.130940, 0.481800, 0.639430, -0.369270, 0.537740,
1.072840, 0.340130, -0.722320, 0.014580, -0.600650, 0.216050, -0.303280, 0.945370, -0.246160, -0.857210,
-0.313200, -0.904190, 0.304680, 0.651650, 1.398860, 2.004060, -0.622490, -0.947030, -0.977380, -0.162740,
0.699830, 0.618710, -0.177940, 0.494000, -3.947470, 0.716460, -2.649680, 2.212560, 0.523730, 0.199710,
4.255250, -0.016490, 0.443510, -9.449600, -0.541350, -0.455400, -4.816580, -0.381260, 0.696350, -0.076240,
0.135980, 0.947410, -1.086790, 0.726210, 0.907950, -1.428570, -0.167590, -0.487290, -1.426070, 0.150700,
-0.404270, 0.030190, 0.688750, -0.683530, -0.191400, -1.007020, 1.158300, -0.307170, -0.080980, 0.652560,
0.522570, -0.389320, -0.449960, 0.437290, -0.606500, 0.273400, -0.761790, 0.489590, -1.670740, -0.001380,
0.345160, -0.294010, -0.560500, -0.704360, 0.035290, 0.834940, -0.629360, -0.833160, -0.413000, -0.090860,
-0.233130, -0.727430, -0.755200, 0.269840, 0.970880, 0.038190, -0.551810, 2.262690, -0.388930, -1.193060,
0.886340, 0.163350, 0.114760, -0.891050, 2.034530, 0.316630, -0.217740, 1.299100, 0.121680, -0.453520,
2.654690, 0.816080, -0.664760, -0.653690, -0.773070, 0.316090, 0.571610, 0.391370, 0.129970,
0.167770, -0.040120, -0.211520, -0.311030, 0.594140, 0.947520, 0.598700, -0.666510, 0.411160, 0.284870,
-0.091890, 0.832730, -0.939450, -0.351400, 0.978800, -0.551810, 0.135890, -0.719940, -0.879640, -0.296560,
0.748310, -0.995630, -0.442630, -0.902830, 0.287450, -0.666890, 0.884200, -1.176010, 0.427040, -0.052220,
0.557740, -0.479930, 0.473290, -0.140740, 0.049490, 0.679530, 0.458380, -0.377250, -0.273460, 0.378750,
-0.313570, 0.390490, -0.996780, -0.383470, -1.131820, 0.160530, -1.281790, -0.439340, -1.023990, 0.874160,
-0.795730, -0.260400, 0.891980, -2.424660, 0.369770, 0.699560, -0.326780, -0.422310, 0.404360, 0.249760,
0.358380, -0.068520, 0.300420, -1.198100, -0.529200, -0.396170, 0.453480, -0.791550, -0.384500, 0.361130,
0.623670, 0.266030, -1.604960, 0.863380, -0.442180, -0.890930, -1.032920, -0.391810, 2.081210, -0.354740,
0.070550, -3.516160, 0.950650, -0.513840, 1.178840, -1.230870, -0.732970, 2.410480, 0.799080, 0.629480,
-2.352620, 0.554990, -0.523390, -1.117270, -0.871990, 0.596780, -0.730310, 0.721320, 0.526750, 0.836700,
-0.906430, -0.390500, 0.507320, 0.616580, -0.294560, -0.392830, -0.102620, -0.771750, -0.396490, 0.981910,
0.610940, -0.316260, 0.148320, -1.075780, 2.782970, 1.188720, -0.290870, 0.278140, 0.269710, -0.128360,
-0.636400, -3.652640, -0.224670, 0.709210, 2.125530, -0.867180, 0.666050, 0.079690, 0.566670,
-1.028890, -0.938720, 0.720870, 0.882180, -0.188340, 0.750340, -0.584830, -0.116280, -0.905740, 0.172910,
-0.795840, -0.519040, 0.306890, 0.510640, 0.166950, -3.122730, 0.724690, -0.070180, -0.164670, -0.895280,
-1.239570, -1.201570, -0.417410, -0.058130, -0.614000, 0.788620, 0.857420, 0.546210, 0.097030, -0.039840,

-0.878340, 0.720610, -0.530910, -0.885390, 0.769870, -0.616650, -0.193460, 0.357890, -0.484710, -0.765450,
0.364920, -0.274010, -0.322490, 0.457800, -0.323800, 0.475640, -1.059150, -0.612110, 0.612340, -0.036340,
0.211430, 0.632690, -3.292450, -1.355440, 0.190530, -0.459430, 0.571390, 0.160190, -0.134350, 0.484370,

0.696020, 0.569310, -0.267040, 0.515450, 0.437110, 0.143510, -0.009700, -0.611410, 0.860160, -0.126530,
0.141810, -0.666630, 0.094940, -0.692460, 0.522440, -0.233740, -0.814660, 0.182120, -0.079550, -0.823650,
-0.162400, 0.105170, -0.071040, 1.183080, 0.743060, -0.803560, -0.982270, -0.566620, -0.023170, 0.235430,

-1.090610, -0.942530, -0.387460, 0.238930, 0.403730, -0.666420, 0.205450, -0.766970, -2.068090, 0.201320,
-0.988100, 0.128720, 0.218960, 0.434200, 0.178830, -4.041040, 0.579770, 0.252340, -0.389300, 0.419800,
-0.717590, -1.136300, 0.827530, -0.563190, -1.160550, -0.557150, 0.599270, 0.206670, 1.071180, -0.484030,

0.184800, -0.247010, 0.830420, -0.927380, -0.311370, -0.816270, 0.250270, 0.378550, 0.358150, 0.551280,
0.800920, -0.713670, -1.002290, 0.223070, -0.230680, 0.433370, -0.835960, -0.655350, 0.484120, -0.696800,
0.290600, 0.458970, -3.559250, -0.312090, 0.712140, 0.310900, -0.456600, 0.134830, 0.607890, 0.524750,

0.017970, 0.541810, -0.376800, 0.692300, -0.383750, 0.795870, -0.829360, 0.827810, -0.166040, -0.739570,
0.225720, 0.919220, 0.439230, -0.329770, -0.566930, -0.108700, -0.552870, 0.911430, -0.427160, 0.448940,
0.280710, 0.311970, -0.695260, 0.477280, 0.274680, -0.412690, -0.590260, -0.188200, -0.991430, 0.037220,

0.695750, -0.852740, -0.269310, -0.431010, 1.128760, -1.409780, 0.367010, -0.789690, -3.179380, -0.808080,
0.015230, 0.903370, 0.694440, 0.644980, -0.470640, -4.501550, 0.792780, 0.528910, -0.857460, 0.037080,
-0.694730, -0.887480, 0.523400, -1.053680, -1.106610, 0.226740, 0.145480, -0.726350, 0.853160, -0.265000,

0.443520, -0.777750, 0.035450, -0.058330, -0.495140, -1.107130, 0.314290, 1.054180, 0.313170, -0.467800,
0.335070, 0.556770, -1.047990, -0.270880, -0.852560, 0.730580, -1.657560, -0.198760, 0.337020, 0.585520,
0.500720, -0.615670, -4.372920, 0.429680, -0.398090, 0.264580, -0.120130, 0.036160, 0.887650, 0.689790,

0.262100, 0.534840, 0.792310, -0.629930, -0.260540, 1.416200, -0.859310, 0.801860, -0.063060, -0.037910,
-0.497360, -0.639830, 0.098330, -0.107830, 0.640220, 0.107590, -1.169200, 0.167800, -0.587940, 0.139350,
-0.039770, 0.866520, 0.390290, 0.396040, 0.343040, 0.312170, -0.662150, 0.522420, -1.392280, -0.571320,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.719930, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.382310, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.003620, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.122740, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.528940, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.182960, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.774610, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.482980, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.176030, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.844180, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.614290, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.451060, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.504610, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.098370, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.400180, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.026970, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.355290, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.667100, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.443910, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.780430, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, -0.074250, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.084600, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, -0.038540, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.306120, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.804470, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.654880, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, 0.252470, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.878010, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.277760, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.292300, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.291180, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.687840, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.349250, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.483310, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.932800, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.688210, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.184510, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.836460, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.862040, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.05825, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.00011, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
1.42104, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42430, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
0.80105, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.00000, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.41741, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.01428, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.18826, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
1.02808, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
0.81378, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.36258, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.28006, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
0.06118, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
0.37559, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
1.41548, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.03030, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.00000, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.01661, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.37105, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.01296, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.02761, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
1.38091, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
1.17637, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
1.40987, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
0.57695, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.00006, 0.500000, 2,
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
