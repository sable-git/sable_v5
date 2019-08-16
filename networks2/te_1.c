/*********************************************************
  TMPtest_new_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:22:58 2004
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
-0.732570, 0.036580, -0.090280, -0.358700, -0.114150, -0.180170, 0.019170, 0.341890, 0.780240, 0.227180,
0.681940, -0.018110, 0.557010, -0.148650, -0.462290, -0.231110, -0.378020, 0.607990, -0.429260, 0.137740,
1.000020, -0.720090, 0.783730, -0.819700, 0.266010, -1.687980, -0.377160, -0.159770, -0.453420, 0.228960,
-1.202780, -0.202370, -0.623130, 0.296660, -0.591640, 2.341020, -1.153080, -0.665290, -1.325570, -0.222490,
-0.728990, 0.504660, -0.721680, 0.220770, -0.279540, -1.421490, 0.480450, 3.740590, -0.295230, 0.006930,
0.839460, 1.761330, -0.677680, 0.568180, 0.011400, 0.606560, 0.339410, 0.203490, 0.582680, 0.359820,
-0.455130, -0.955540, -1.095600, 0.470230, -0.454140, 1.015360, -0.662870, 0.467110, 0.471070, 1.335790,
-0.399380, 0.556600, -0.699420, -0.561380, 0.026170, -0.099490, -0.130900, -0.533470, -0.023150, -0.718610,
-0.441060, -0.753940, 0.383710, -0.206210, -0.824230, -0.350180, -0.797280, 0.148770, -1.461690, -0.902240,
0.614070, 0.074610, 0.899410, -0.603890, 0.966030, -0.302780, 0.548820, -0.232360, 0.275560, -0.933300,
-0.290110, 0.546400, 0.093890, 0.215250, 0.909630, -0.035050, 0.488620, -0.705740, 0.221120, -1.226320,
0.911530, 1.059660, 0.612880, -1.233890, -0.176430, -0.866750, -0.104890, 0.115500, 0.204070, -0.594210,
-0.212840, -0.883960, 0.401190, 0.731830, -0.398980, 0.914690, -0.729900, 0.199370, 0.572360,
0.405240, 0.086770, 0.563090, -1.068390, -0.126590, 0.246280, -0.836650, -0.427080, -0.551780, 0.262820,
0.816010, -0.420150, -0.743730, 0.002390, -0.018350, 0.190360, -0.410810, 0.912830, -0.884380, 0.605330,
-0.056560, 0.550120, -0.173540, -0.818560, 0.032950, -0.507520, -0.584030, -0.111890, 0.441400, -0.447700,
-0.945100, -0.391690, 0.738220, 0.175290, -0.039850, 1.204830, -0.220230, 0.390940, -0.285190, -0.350600,
-0.355320, -0.365270, 0.484280, -0.552980, 0.783490, 0.251730, 0.821670, -1.768080, -0.344500, 0.230120,
0.149630, 0.737020, -0.071810, 1.542150, 0.190040, -0.410950, 0.531250, -1.142830, -0.233480, -0.146600,
0.744670, 0.302080, 1.044230, -0.964480, -0.661300, 1.205180, 0.341540, -0.731460, 0.473200, 1.772300,
0.882080, -0.330930, 0.721630, -0.003490, 0.324110, -1.041610, -0.216430, -0.791590, 0.640450, -0.401250,
0.647040, -0.919200, -0.303040, -1.036450, 0.699400, 0.019850, 0.621450, 0.544320, -0.011570, 1.025890,
-0.577340, 0.943170, 0.240570, 0.080740, 0.765020, 0.797780, 0.112680, -0.482910, -0.810390, 0.112850,
0.359730, -0.624330, -0.305330, -0.391360, 0.315770, 0.069710, -0.670890, 0.010020, -0.839810, -0.929990,
0.227850, 0.633850, 0.096850, -3.328390, 1.292300, -1.186250, 0.447150, 0.406150, 0.941290, -0.618250,
0.503680, 0.977730, 0.185310, 0.340060, -0.043560, 0.670180, 0.519560, -0.802250, 0.609420,
-0.203640, 0.293050, 0.785520, 1.400350, -0.139130, 0.369860, -0.203130, -0.751920, 0.770890, -0.852160,
0.597940, -0.231260, -0.317010, 1.093780, 1.061160, -1.410060, -0.081770, -0.753030, -0.461260, -0.514030,
-0.262940, 0.365720, -0.376040, -0.856940, 0.692120, 0.764280, -0.919800, 0.228710, -0.719870, -0.358730,
0.209930, -1.520600, 0.727910, -0.394020, -0.206960, -0.781970, -2.068340, -0.081630, 0.591870, 0.627430,
-1.054780, -0.853120, 0.489060, 0.308120, -0.099320, 4.588480, 0.209360, -0.177960, -0.102090, -0.254480,
-0.597460, -1.709960, 0.197300, 1.996520, 1.521400, 3.264640, -1.511200, 0.357950, -0.623410, -0.256500,
-0.433690, 0.429910, -1.031430, -2.566980, 0.530060, 2.007450, 1.219340, -0.472580, -0.705940, 0.409040,
0.602450, -0.356910, 0.213170, -0.805910, 0.622560, -0.674800, 0.440820, 0.523890, -0.574380, 0.588260,
-0.383400, 0.585000, -0.317220, 0.222200, 0.078210, -0.510740, 0.825730, 0.110370, -0.850030, 0.727530,
-0.828320, 0.439060, 0.480290, 0.840760, 1.185050, -0.565440, -0.511510, 1.108820, 1.392800, 1.024550,
-0.122650, 0.042900, 0.677300, -0.292840, -0.367380, -0.244250, 0.267970, 7.957370, 0.225050, -1.398680,
-0.763390, 0.060870, -0.095760, -1.362540, -0.776540, 1.349220, 0.869740, 0.561030, 0.532200, -0.062990,
0.720810, -0.375680, 0.976330, -0.132680, -0.879760, -0.587310, -0.350680, -0.489770, -0.751130,
0.859140, -0.543400, -1.255060, 0.282220, 0.504880, 0.968680, -0.290720, -0.504410, -0.353370, 0.802250,
-0.250810, 0.188940, 0.125280, 0.073700, 0.013590, -0.587050, -0.317630, -0.554030, 0.418090, 0.638430,
-1.025850, -0.598840, 0.172850, 0.337720, 0.896620, 0.062390, -0.857300, -0.090080, -0.010540, 0.857370,
-0.299950, -0.255780, 0.521520, 0.266980, -1.406940, 1.084850, 0.063860, 1.283430, 0.317130, -0.640660,
-0.132250, -0.183440, -0.108770, 0.385750, -0.358040, 0.728450, -1.993690, -0.102060, 0.145180, -0.350880,
-0.306100, 0.650960, 1.677140, 0.001150, -0.529470, -0.407610, -0.286700, 2.470480, 1.084230, -0.758160,
-2.964190, 0.543480, 0.304830, 2.777320, -0.767780, 0.073980, 0.306140, 0.600540, -0.385080, -0.583120,
0.452790, -0.401660, -0.128070, -1.267680, -0.682530, -0.958760, -0.209590, 0.329320, 0.160820, 0.397050,
-0.399020, -0.455450, -0.631170, -0.203340, -0.621700, -0.941750, -0.625490, -0.665860, -0.991240, -0.160030,
0.215380, -0.265690, -0.568740, 1.046330, -0.622480, -0.311000, 1.148670, -0.294120, -1.090180, 1.234340,
0.596770, -0.694540, -0.319330, 0.560340, -0.005050, -0.823830, 0.389820, -0.637320, 0.667150, 0.416070,
0.433340, 0.274710, -0.341120, 9.811680, -0.446150, 1.982090, 0.589780, -0.024480, -0.381640, 0.701770,
-0.859730, 1.649330, -0.822990, -0.251880, -0.597630, 0.739410, 0.890900, -1.116050, -0.414350,
0.399240, -1.202880, 0.450230, -0.029370, -0.504440, 0.513070, -0.122460, 1.031480, 0.806860, -0.120690,
0.729420, 1.034280, 0.204010, 0.226960, -0.851630, -0.487260, 0.038690, -0.819960, 0.154150, 0.155320,
0.329810, -0.909920, -0.973620, -0.162590, -0.688910, 0.564620, -0.116320, -0.532500, -0.546060, -0.624120,
-0.542160, 1.332310, -0.424220, 0.098040, -0.577800, -0.431140, -0.059640, 0.117230, 1.375700, -0.453660,
-0.330040, 0.593120, 0.524180, 0.711160, 0.800280, 0.073630, 1.114340, -0.186790, -0.179950, 2.229730,
0.911870, 0.539610, 2.853570, -0.959390, 0.337350, 1.311490, -0.774400, 0.594550, 0.447110, 0.244090,
0.077110, 6.270770, 0.032690, 0.299290, -0.436580, -1.923020, -0.158290, 1.742100, 0.235630, -0.687980,
3.872100, 0.191380, -0.810220, -0.994900, 0.608980, 0.252480, -0.458370, -0.217270, -0.358180, 0.616950,
0.734890, -0.876530, -2.743290, -0.176900, 0.505360, 0.470850, -0.451930, -0.286180, -0.258450, 0.140040,
0.905060, 0.026460, 0.271920, 0.101220, -1.296100, -0.058510, -0.150100, 0.600470, 1.550400, -0.533700,
0.448420, 0.233360, 0.753380, -0.449770, 0.867090, 0.006770, 1.070740, 0.762980, 0.092610, 0.948050,
1.095200, 0.248270, -0.800810, -2.013090, 6.576700, 1.407690, -0.426800, -0.470890, 0.764370, -0.225760,
-0.171360, 0.349500, 0.669970, 0.311950, 0.700790, 0.310340, 1.029480, -0.429450, -2.623410,
-0.423310, 0.587590, 0.353540, 0.229270, -0.149760, 0.638570, -0.225880, -0.394120, -0.021420, -0.024470,
0.454550, 0.847120, -0.538060, -0.579010, -0.072800, 0.363780, -0.594060, -0.699690, -0.164940, -0.664800,
-0.021090, 0.175150, -0.307450, -0.337710, -0.018060, -0.705210, 0.516520, 1.233780, 1.015070, 0.961920,
0.509250, 0.147870, -0.300420, 0.457790, -0.163800, 1.030820, 0.773370, -0.778580, -0.289250, -0.827120,
0.255820, 0.250730, -0.632010, -1.890780, 0.823960, -0.492690, 0.935390, -0.638200, 0.243760, -0.327560,
-0.194780, -2.135230, -1.025620, 0.203030, -0.190300, -0.549500, 1.006540, -3.768510, -0.805890, 0.635300,
-0.182440, -1.043950, -0.094300, -3.033790, -0.063210, 0.335950, 0.385620, -0.546740, 0.246660, -0.242840,
0.127600, 0.146140, 0.126480, -0.081190, -0.345290, -0.479630, -0.232470, -0.393100, -0.114360, 0.948220,
0.577620, -1.429520, -0.076350, -0.694670, -1.059300, -0.749950, -0.849110, 0.954110, 0.461820, -0.277890,
-0.158150, -0.806990, -0.581090, -0.810390, 0.953440, 0.554520, 1.069000, -0.034480, 0.275120, 0.367130,
0.512260, -0.454350, -0.298490, 0.146960, -0.519380, -0.400710, 0.902080, -0.076860, -0.104130, 1.627440,
-0.458020, 0.050780, 0.633330, -1.268000, 1.324900, -0.623240, 0.125780, -0.860290, -0.335810, -0.017580,
0.989970, 0.709620, -0.761360, -0.781270, -0.256870, -0.478260, -0.484170, 1.869310, -0.374640,
0.372140, -0.908950, -0.808400, 0.618680, 0.226090, -0.440300, -1.012140, 0.471850, 0.064180, 0.199480,
0.043420, -0.774970, 0.723270, 0.529340, -0.733510, -0.741750, 0.342280, 0.338060, -0.588140, -0.940030,
-0.712590, 0.651120, 0.165270, 0.485560, -0.535990, 0.914310, -0.426640, -0.270170, -0.329860, 0.502630,
-0.027160, -0.502140, 0.431530, 0.466990, -0.571100, -0.098140, -0.077100, 0.455890, -0.466560, 0.706760,
-0.109330, 0.319560, -0.183410, 0.411130, -2.849940, 1.130690, 1.065310, 0.245310, -0.384440, 0.277530,
-0.405900, 0.551310, 2.414080, 0.186720, 0.816470, 0.738460, -0.281210, 0.539300, 1.634440, 0.443390,
-0.205440, 0.313170, -0.206620, 0.638230, 1.525930, -0.957420, -0.114580, 0.674510, -0.500320, 0.755330,
0.836030, -0.622680, -0.234790, -0.380650, 0.347730, 0.207260, -0.817600, 0.558560, 0.664660, 1.280800,
-0.019850, 0.459920, 0.582200, 0.017260, -0.881220, 0.097580, 0.508790, 0.649880, 0.068190, 0.872970,
-0.044530, 0.145600, 0.828870, 0.384700, -0.517270, 0.074140, -0.089110, 0.513600, -0.226530, 0.323750,
-0.586060, -0.358070, -0.868900, 1.002300, 0.238470, -0.924160, -0.839020, -6.550860, -0.738250, 4.396150,
-0.784580, -0.239990, -0.271580, 0.405720, 0.317710, 0.558570, -0.704800, 0.292210, -1.184180, 0.677010,
-0.612580, -0.763920, -0.222740, -0.381020, 0.297100, 0.604760, -0.091730, 2.622470, -0.209790,
-0.110730, -0.464480, -0.385320, 0.255740, 0.604720, 0.155740, -0.280330, -0.403380, -0.467180, -0.344740,
0.340700, 0.150680, 0.381970, -0.370120, -0.742890, -0.308520, 0.552330, -0.143870, 0.208840, -0.216470,
-1.011800, -0.959940, 0.770860, 0.634150, 0.016500, -0.113220, -0.627690, 0.131870, -0.697480, -0.125570,
-0.412890, -0.501850, 0.811710, 0.258030, -0.222630, -0.985160, -0.041430, 0.916400, 0.398850, -0.080430,
0.632390, -0.353440, 0.905130, -0.452650, 0.461790, -0.474910, -0.532930, -0.586960, -0.137990, 0.474170,
-0.014010, 0.147720, -0.153660, -0.699820, -1.038120, -0.511860, 0.662530, 0.084850, 0.423620, -0.657280,
1.686620, 0.065180, 0.888700, -0.825280, 0.523360, 0.127160, -0.926580, -0.105430, 0.316670, 0.238980,
-0.019090, -0.899820, -1.265350, 0.394760, -0.398680, -0.775980, 0.045470, 0.465120, 2.266080, 0.235200,
0.911660, 0.614420, 0.433050, 0.514450, 0.626340, 0.725080, 0.289610, 0.033360, -0.850230, 0.791860,
0.813410, 1.228890, 0.504190, -0.628680, 0.908240, 0.721540, -0.435990, -0.360980, -0.543180, -0.375840,
-0.395420, 0.211090, 0.678270, -0.822590, -0.634110, 0.842280, -0.977400, -0.908210, 0.107200, 1.300170,
0.649480, -0.970510, -0.457940, -2.988100, -1.864910, -0.144910, -0.570190, 1.008020, -0.142680, -0.080030,
0.126730, 0.403950, 0.025260, 0.371200, 0.199810, 0.003710, 0.775680, 0.861140, -0.379240,
-1.474720, -0.397840, -0.987960, 0.092780, 0.368040, -1.063060, -0.472360, -0.798100, 0.078810, 1.000110,
0.039680, -0.276950, -0.278800, -0.088610, -0.921060, 0.221320, -0.019360, 0.189480, 0.033000, 0.667200,
-0.811800, -0.693490, -0.419410, 0.666760, 1.295060, 0.969120, 0.768480, 0.772560, 0.624290, 0.144050,
0.486940, 1.084040, 0.339370, 1.235610, 0.540760, -0.691240, 0.690030, -0.832980, 2.131380, -0.432320,
-0.850550, 0.294150, -0.244800, 0.957300, -1.583440, -0.492870, -1.931360, -0.666110, 0.687050, -0.353000,
0.378520, 0.421230, 0.883410, 0.669940, -0.216920, -0.158380, -1.041440, -0.015080, 0.737820, -0.900710,
-0.220880, 0.103500, 0.399110, -1.312090, 0.317260, 0.902240, -1.043350, -0.255230, -0.139550, 0.412490,
-0.771910, -0.520630, -0.540350, 0.391770, -0.790370, 0.131080, 0.167690, -0.475250, -0.580630, -0.822910,
0.122660, 0.547780, -0.638160, -0.677620, -0.736740, -0.306850, -0.104400, -0.358700, -0.161930, 0.147200,
-1.180150, 0.336750, -0.800490, 0.231900, 0.728180, 0.449880, -0.189640, 0.019460, 0.756650, -0.065540,
0.328470, -0.460630, 0.547370, -0.836420, -1.039550, -0.806200, 0.743930, -1.392290, 0.618180, 1.787340,
0.584260, -0.295670, -0.569430, -1.467630, 0.669980, 0.915740, -0.350320, 0.639400, -0.746380, -0.648270,
-1.120560, -1.048230, -0.639850, 0.399570, -3.583270, -0.972880, 0.451430, 2.901170, 0.817910,
-0.443720, -0.240280, 0.377330, 0.341360, 1.189370, 0.602460, -0.636780, -0.480510, -0.232380, -0.449710,
1.812740, -0.528080, 0.557200, 0.724220, 0.676940, 0.448230, -0.600050, -0.845950, 0.059550, -0.369710,
0.531650, 0.254250, -0.915920, 0.330610, 0.238250, 0.844600, 0.662620, 0.706970, -0.095670, -0.900200,
-0.416270, -1.050170, 0.000060, -0.099620, -0.905660, 0.301250, -0.021010, 0.366930, -0.138880, 0.801950,
-0.874180, -0.544700, -0.764000, -0.060790, -0.845650, -0.368150, -0.959360, -0.746360, 0.210120, -0.298460,
0.308900, -0.925740, 0.346860, 1.335230, 6.950200, 0.283560, -2.802840, -1.408240, 0.630080, 0.736130,
-0.599990, -1.679530, -0.692000, -1.392020, 0.115560, 1.078700, -0.138060, 0.574450, 0.270400, -0.048720,
-0.663920, -0.225450, 0.193480, -0.223100, -0.658040, -0.258620, -0.383510, -0.689890, 0.262280, 0.031070,
0.697730, 0.154520, 0.370310, 0.406680, -0.869800, 0.259640, 0.537530, 0.032520, -0.601740, 0.394750,
-0.485040, 0.771830, -1.677990, 0.812330, 1.110080, 0.587690, 0.336280, -0.406620, 1.160770, 0.627380,
-0.646650, -0.295430, 0.617640, -0.890960, -1.274590, 0.682120, 0.438640, -0.359440, 0.822520, 1.225460,
0.897090, -0.004710, 0.170730, -0.437280, -0.438170, 1.362290, -0.427150, 0.207770, 0.217740, 0.157020,
0.723030, -0.419100, 0.855190, 0.673730, 0.134340, -0.006580, 0.452240, -1.143490, 0.191950,
0.249890, -0.492770, -0.779070, 0.239820, -0.254450, -0.747430, 0.262880, -0.482450, 0.676690, 0.118060,
-0.362350, -0.673940, 0.503700, -0.193710, 0.537510, 0.095170, 1.099160, -0.047200, -0.740220, 0.486760,
-0.016720, -0.145730, 0.590110, 1.054040, 0.779110, 1.145740, 0.242160, 0.658320, -0.359340, 0.240470,
0.653710, 0.384860, -0.428420, -0.096740, 1.225680, 0.175780, -0.504560, 0.566010, -0.709770, 0.760530,
1.071180, 0.229340, -0.819590, -0.432000, -0.895540, -0.130780, 1.320780, -1.258450, -1.068520, 0.570110,
0.894290, 0.192460, -0.247220, -1.046390, -1.347620, -0.271880, 2.107680, 0.979660, -0.049850, -1.121710,
-0.018840, -0.122550, -0.145040, 0.766060, 0.780860, -0.303480, 0.710470, 0.479660, -0.939550, 0.147060,
-0.677380, 0.251910, -0.693670, 0.072020, 0.080160, -0.269900, -0.776000, -0.735110, -0.233460, -1.488650,
-0.513390, -0.693620, -0.368270, 0.310690, -0.458570, -0.535800, -0.845060, 0.338270, -2.302140, 0.362580,
-0.399190, 0.494250, 0.106070, 0.938510, -0.963010, -0.108200, -0.600030, 1.357610, 0.121160, 0.500590,
0.365920, -0.335880, -0.123470, -0.226030, 0.959280, -0.510150, -0.597540, 1.745150, -0.975270, 0.016280,
0.512410, -0.264040, -0.562540, -4.278300, 2.186370, -0.458540, -0.938220, -0.483720, 0.502180, -0.233470,
0.583100, -0.297610, 0.097170, 1.064370, 1.363600, -0.893130, 1.103740, 0.384980, 0.109740,
-0.211350, 0.196040, 0.704670, 0.173870, -0.367160, -0.859690, -0.276220, -0.410110, 0.123410, -0.371780,
0.321580, 0.074780, 0.632820, -0.788580, 0.283750, -0.216660, 0.434280, 0.957930, -0.880270, -0.043250,
-0.526410, 0.993410, -0.397650, -0.965480, -0.513290, -0.164780, -0.100430, 0.368810, -0.416580, -0.452840,
0.110280, -0.433310, 0.092770, 0.937390, 0.441260, -0.138480, 0.355870, 0.338600, -0.339960, -0.611220,
0.865100, 0.379980, 0.573320, 0.411680, 0.740570, -0.728740, -0.718470, -0.627020, -0.461730, -1.084380,
0.262610, 0.094170, -0.648930, 0.012940, -0.512370, -0.860090, -0.360920, 0.049810, 0.707120, 0.004140,
0.543390, 0.398420, -0.578630, -0.344360, 0.175980, -0.403870, -0.523960, 0.239640, 0.483040, -0.267120,
0.533020, 0.000460, 0.390410, 0.277810, -0.667060, 0.718940, 0.443650, -0.683470, 0.299330, 0.575910,
0.297290, 0.844680, 0.334730, 0.700760, 0.271890, 0.645230, 1.030230, 0.634770, 0.669140, 0.316900,
0.505300, 0.011170, 0.407280, 0.179590, 0.730870, -0.080910, -0.490110, 0.435080, 1.039320, 0.390760,
0.677080, 0.668590, 0.111310, -0.436470, 0.017770, -0.558070, -0.857940, 0.000110, 0.146190, 0.381750,
0.079110, 0.897250, 0.359170, 1.666320, 0.232890, 0.226930, -0.682960, 0.544690, -0.824540, -0.760970,
0.213950, 0.070590, 0.690470, -0.808320, 1.255420, -0.476600, -0.541730, -0.646310, -0.567710,
-1.057870, -0.270950, -0.181990, 0.146440, 0.752700, -0.336120, 0.970680, 0.272080, 0.426190, 1.032530,
0.079630, -0.316540, -0.190070, 0.820420, 0.617350, -0.095090, 0.466880, -0.267890, -0.116620, -0.596790,
0.733640, -0.368830, 0.962620, 0.217960, 0.566170, -0.352580, 0.300130, -0.214710, -0.678190, 0.060800,
-0.719470, -0.193290, -0.520490, -0.194660, -0.357000, -0.345250, -0.250640, -0.086510, -0.395980, -1.082410,
1.030130, -0.150760, 0.719970, -3.604150, -0.534160, -0.584940, -0.531090, -0.761480, -0.234760, -2.675810,
0.462010, 0.231130, -1.728020, -0.811700, -1.701760, -1.171260, 0.001450, 0.374400, -1.584000, -0.431580,
0.654430, -0.902870, 0.556950, 0.357300, -1.120700, 0.381850, 0.867110, -1.340720, 0.565950, 0.690030,
0.538930, 0.164830, 0.417260, -0.499970, -0.380930, -0.963040, 0.419850, -0.888700, 0.841980, 0.977030,
-0.197550, -0.624480, -0.470310, 0.853750, -0.056400, -0.234260, 0.940930, -0.795360, -0.050570, 0.522140,
0.525520, -0.446140, -0.644470, 0.501250, 0.968350, 0.727010, 0.858160, -0.361430, -0.056720, -0.781500,
-0.045390, -0.108840, -0.551030, 0.050480, 0.367900, 0.178930, 0.768430, 1.154440, 0.767460, 1.184530,
0.490940, -0.022830, -0.578460, -0.704410, -0.961090, -0.043570, -0.666600, -0.107810, 0.571290, 0.547190,
0.424230, 0.341310, 0.372080, 0.560490, -2.174170, -0.269310, -0.290270, 0.501650, 0.177070,
0.562890, -0.859520, 0.392920, -0.046480, 0.000590, -0.676730, -0.243200, 0.504730, 0.868860, -0.514050,
0.527110, 0.976090, -0.734860, -0.100790, 0.357100, 0.876410, -0.209860, -0.714830, 0.962040, -0.033910,
-0.855240, -0.494520, 0.073510, -0.075480, 0.169290, 0.001160, -0.145970, -0.905600, 0.206090, 0.742940,
0.487590, 0.302510, -0.368590, 0.952410, -0.133730, -0.835690, 0.115720, -0.389460, -1.097060, 2.957380,
0.396100, -0.835580, 0.163550, 1.026620, -0.355560, 1.205180, -0.541740, 0.224580, -0.307850, -0.368450,
0.076000, -0.081990, -1.239540, -0.414280, -0.108780, 0.293180, -0.785130, 1.146870, -0.079470, 0.508590,
-0.569530, -0.588330, 0.525880, 1.077930, 0.011530, 0.732320, -0.616040, 0.527720, -0.021250, -0.308510,
2.015930, -0.297450, 0.957610, -0.590120, -0.798990, 0.152930, -0.493940, -0.766430, 0.326180, 1.757860,
0.073740, 0.809620, -0.598980, 0.149770, -0.805440, -0.154240, 0.104600, 0.272300, -0.201460, -0.082750,
0.893400, 0.593570, 0.119010, -0.177770, 0.410200, 0.603360, 0.894850, -0.700170, 0.448010, -0.257230,
0.078040, 0.258920, 0.310020, -0.848090, 0.526050, 0.752280, 0.102440, -0.629200, 0.087840, 1.535060,
-0.608760, 0.751090, 0.737410, -0.457800, -1.333130, -1.085320, 0.874200, -0.279240, -1.054710, -0.700170,
-1.021920, -0.389390, -0.647980, 0.436890, -2.638530, -0.929230, 0.820180, 0.123680, 0.229010,
0.385990, 0.222490, 0.417950, 0.031730, 0.429000, 0.388970, -0.542100, -0.833720, 0.714990, 0.564410,
-0.525940, -0.301650, -0.326510, 0.480880, 0.786840, 0.380280, -0.771540, 0.630980, -0.490280, 0.636820,
-1.118590, 0.653020, 0.600970, -0.359790, -1.237060, -0.936890, 0.100750, 0.590190, 0.148730, 0.459810,
-2.394160, -0.344980, -0.977860, -0.383000, -0.955410, 0.389250, -1.240580, 0.774970, -0.224190, -0.206960,
0.586120, 0.790260, 0.670620, -2.237250, 0.149760, -11.330900, -1.103060, -0.138650, 1.937210, -0.636910,
-0.448530, 0.033860, -0.387670, 0.176210, 0.747680, -0.637300, 0.537900, 1.105570, -0.535820, 0.202890,
-0.343090, 0.466450, 0.430000, 1.136500, -1.073180, 1.302520, 0.428790, -0.226170, -0.806180, -0.877980,
0.586930, -0.594020, -0.380320, -0.356120, -0.298190, 0.182780, 0.291250, 0.726110, 0.717290, 0.716480,
-0.100150, 0.128870, 0.323080, 0.600910, 0.411340, -0.949680, -0.286690, -0.398300, -0.408450, 0.432590,
-0.783900, -0.783300, -0.092600, 0.659660, 0.209980, -0.966520, -0.379490, -0.647860, 0.061160, -0.884880,
-0.206980, -0.400330, 0.411870, -0.007690, 0.105090, 0.960770, -0.974840, -1.247410, -0.510980, 0.313950,
0.477030, -0.225000, -0.294980, -4.848610, 1.121260, -0.200770, 0.160270, -0.164210, 0.630490, -0.951640,
0.307690, -0.030000, -0.274930, 0.387970, -1.887320, -0.133900, 1.223850, 1.513230, -0.015760,
-0.586190, -0.091090, 1.306860, 1.447820, 0.185330, -0.852890, 1.531480, -0.437670, 0.402380, -0.501000,
0.666920, -0.864770, 0.210670, 0.174510, 0.563440, -0.011500, 0.384600, -0.523120, 1.022760, 0.652520,
0.512090, 0.230930, -0.204470, -0.982820, -0.620490, 1.403620, 0.435800, 2.000680, 0.323820, -0.193780,
-0.352150, -0.563630, 0.644260, -0.245740, 0.506750, -0.676610, -0.688690, -0.505460, 0.340200, -0.390260,
0.293320, -0.568450, -0.029170, -0.431570, -0.407310, -0.654340, -2.823750, -0.636830, -0.891070, -0.267600,
0.838520, -0.290380, 0.404930, -0.910040, 0.013390, -0.128930, 1.344360, 2.447000, 0.250470, -1.010460,
-0.828940, 0.602390, 0.496630, -1.051030, 0.410100, -0.638260, -0.945900, 0.774240, -0.906300, -1.320800,
-0.498810, -0.967120, 0.036050, 0.804170, -0.645670, -3.516260, -0.545030, -0.657560, 2.543710, -0.014200,
-0.493010, -6.865820, -0.779260, 0.497570, -1.629280, 0.108030, -0.792230, 2.587760, -0.167550, 0.699560,
-1.419690, 0.892150, -0.297350, -0.081210, -0.080390, 0.734280, 0.089210, 0.205240, -0.467520, -0.448550,
0.523520, -0.205870, 0.291410, 0.199830, 0.884920, 0.582480, 0.173440, -0.326790, 0.641300, -0.907450,
-0.429670, 2.100930, 0.002770, -1.357090, -0.720850, 2.549570, -1.097700, -0.134030, 0.337950, 0.251670,
0.306870, -0.005260, -0.363180, -0.659330, -1.355390, -1.103770, 0.969270, -2.084920, 0.573610,
-0.019860, -0.461950, -0.899190, -0.536950, -0.945150, -0.985280, 0.420250, 0.123970, 0.653370, 0.099570,
-1.979610, -0.474090, -1.008910, 0.757280, 0.648610, -0.321740, 0.604300, -0.495010, -1.007630, 0.702950,
-1.010380, 0.891580, -0.508880, -0.675150, 0.669530, 0.816260, 0.736030, -0.314520, 0.199420, 0.691020,
-0.230680, 0.016580, 0.607750, -0.428650, 0.129300, 0.105640, -0.783480, 2.203730, 1.067200, 1.017000,
-0.282210, -0.824920, 0.183930, -0.132900, 0.504240, -0.249200, -0.336970, 0.010400, -0.306630, -1.219920,
-0.461540, -0.670450, 1.128430, -0.543090, 1.086500, 0.220200, -0.260130, -0.311880, 0.559590, -0.510290,
-0.039730, 2.348350, 0.696180, 0.952380, -3.822580, -3.790230, 0.429300, 0.331990, -1.082360, 0.514790,
6.601780, 2.320310, 0.269260, -4.548850, -2.119590, 0.685260, 0.723560, 0.705780, -0.079450, 7.047620,
-1.134320, 0.058880, -1.017730, -2.741430, 1.102600, -0.321780, 0.731390, -0.063460, 10.381220, -0.637450,
-0.158000, -11.557700, -7.148690, 0.670380, -3.182960, -0.037140, 0.961710, 0.913450, -1.039140, 0.669920,
0.953080, -0.861760, -0.531160, -0.381940, -0.297920, 0.255650, -0.999160, 5.748350, 0.800700, -4.294700,
0.252600, 0.018190, 0.042460, 3.315260, -4.886130, 0.051840, -0.722580, -1.211730, -1.288620, 0.038640,
-0.190990, -0.400340, -1.010870, -0.855310, 0.462310, 0.382640, 2.407080, 0.135240, -0.711790,
0.062020, 0.953690, -0.794830, -0.780400, 0.941540, 0.678900, -0.375250, -0.189190, -0.200650, 0.779410,
0.561310, -0.619690, 0.484270, -0.564820, 0.633570, 0.822320, 0.332910, -0.559130, -0.607080, -0.205050,
-0.781350, 0.035490, -0.332520, -0.043360, -0.832710, 0.374970, 3.226410, -0.374420, -0.327430, -0.885710,
0.288150, -1.278310, -0.305630, -0.364750, -0.066680, 4.090010, -0.196600, -0.547720, -3.350180, 0.691650,
-0.245620, 0.531560, 0.139990, -0.933850, 0.714350, 0.009660, -1.121380, -2.453480, -0.288990, 0.388150,
0.294870, -0.078100, -0.805470, 0.012270, 0.887260, 0.434750, 0.880540, 0.946550, -0.837190, -0.181570,
0.191780, 1.462900, -0.934840, 0.694230, -0.264000, -0.571770, 13.796270, -1.013600, -0.426560, -0.857850,
-0.028440, 0.412780, 1.069530, -0.761900, 0.445470, -0.459290, 0.538230, -0.126580, -0.531230, -1.258140,
-0.161850, -1.639660, -0.263590, -0.646190, -0.492070, 0.225680, -0.108540, 0.777750, -0.160700, -0.037870,
-0.362800, 0.222720, -0.996150, 1.435950, -0.108450, 0.869030, -0.064310, 0.463660, 0.642400, 0.475920,
0.485510, 0.733710, 0.877250, -0.233050, -1.252560, 0.314730, -0.411390, -0.571130, -0.814170, -0.324040,
0.797630, -1.915640, -0.454910, -3.698860, 0.222060, 1.208050, 0.339900, 0.401150, 0.320790, 0.574390,
0.922940, -0.290950, 0.817500, 0.444070, -2.430260, 0.373460, 0.589280, 0.010900, -0.220120,
-0.481800, -0.655420, 0.102660, -0.785550, 0.513120, 0.894010, -0.375200, 0.644680, -0.404480, -0.401870,
-0.425360, 0.328660, 1.082250, 0.038560, -0.572260, -0.440050, 0.153490, -0.765660, 0.562870, 0.334120,
0.144570, -0.236540, -0.991550, -1.157930, -1.030750, 0.590980, -1.034620, -0.861950, -1.046800, -0.251420,
-0.398030, -0.978240, -0.600340, 0.528580, 0.432490, 0.552650, 1.456910, -0.592870, 0.683380, -0.923650,
0.717310, -0.420060, 0.054510, 1.512790, 0.821950, 1.143130, 0.105370, -0.548780, -0.847860, 0.546230,
0.325830, 0.169450, 0.120240, -0.090990, 0.061750, 0.628320, 0.326720, -1.692080, 1.011390, -0.600840,
-0.759340, 0.493010, -0.487540, -0.740270, 0.999280, -0.804950, -1.665100, -0.288690, -0.725830, 2.474250,
0.733870, 0.325120, -0.677520, -0.749930, 0.812170, -1.486740, 0.711530, -0.340820, 2.284370, 0.191600,
0.675400, -0.880230, 0.501550, -0.162770, -0.691770, 0.665650, 0.361370, -0.779300, 0.124660, 0.096070,
-0.674670, -0.982340, -0.133390, -0.263080, -0.079510, 0.418440, -2.963220, 0.361050, 0.170520, 0.425290,
-1.319300, 0.390260, -0.772800, -0.936090, -0.087540, 0.206960, 0.691670, -5.112390, 0.012120, 2.672600,
-0.418460, 0.524830, -0.908240, -2.464270, 2.491730, -10.914220, 0.858170, -0.645640, -0.425470, -0.090200,
-0.771450, -5.175850, 1.393330, 0.623690, 0.615650, 0.295810, -0.962550, 3.176720, 0.883290,
-0.638350, 0.494730, 0.077670, -0.851950, -0.350130, 1.018040, -0.259690, 0.713270, -0.336490, 0.129300,
-0.442670, -0.534400, 0.274130, 0.020440, -0.099710, 0.113380, 0.485490, 0.778960, 0.394140, 0.789940,
0.918140, -1.282400, -1.042200, 0.870750, -0.376050, 0.448060, 0.154760, 0.889200, 0.644610, -0.400700,
-0.647930, 1.211420, -0.119040, -1.349890, -0.279750, 0.652640, 1.158610, 1.228860, 0.742420, -0.684940,
0.705590, 0.084250, -0.332970, -0.657370, 0.776090, 0.891230, 0.138970, -0.043940, -0.941900, 0.104690,
-0.788660, -0.654870, -0.077000, 1.156740, 2.942880, 0.915430, 1.117280, -1.152550, -0.248090, -0.787150,
-0.382150, 0.148270, 0.826270, -1.493090, -0.276300, -0.278080, 0.063050, 0.198070, 0.809130, -0.682350,
-0.472630, -0.087190, 1.027980, 0.026220, -0.401550, -0.148750, -0.231170, 0.372030, 0.926480, 0.660150,
0.886480, -1.064750, -0.407120, -0.372440, -0.125980, 0.885090, -0.150270, 0.678290, -0.262280, -0.122610,
-0.674010, -0.650300, 0.326170, 0.168890, -0.271950, 0.491170, -1.016720, 0.212340, -0.748560, -1.031780,
-0.308260, -0.129730, -0.180300, 0.139170, 1.807760, 0.006460, 0.019600, 4.829840, -0.635090, -2.426510,
-0.752770, -0.630550, -0.116940, 0.179820, 1.300770, -2.011740, -0.176760, -0.178270, 0.159510, -0.782640,
0.238120, -1.244690, 0.628670, -0.733550, -0.675300, 0.974400, -0.700690, 1.426790, 0.239100,
0.106780, 0.068390, 0.859220, 0.610760, 0.741480, -0.264470, -0.317420, 0.777050, 0.053220, -0.674760,
-0.941920, -0.101580, 0.297140, -0.275490, 1.025530, -1.079480, 0.669740, 0.383750, 0.796290, 0.409080,
0.463540, 0.046710, 0.424720, 0.119840, -0.978370, 0.451310, -0.440000, -0.113640, -0.168030, -0.296450,
-0.441210, 0.475740, 0.364330, 0.057590, 0.704010, 0.821570, -0.186420, -0.150980, 0.278340, -0.363530,
0.404900, 0.171750, -0.149140, 3.459160, -1.687840, -1.529680, 2.187420, -0.449490, -0.583140, 0.222870,
-1.724010, -0.213710, -0.907550, 0.137090, 0.519190, 5.797350, 1.084150, -0.973290, 0.114470, 0.175300,
0.447010, -2.077100, -0.468560, -1.236030, 2.488640, 0.270070, -0.824670, 0.700000, 0.320020, 0.207130,
-2.370540, 0.166220, -1.247280, 0.495690, 0.084100, 0.041650, 0.548200, 0.391230, 0.257090, -0.854540,
0.281940, 0.049260, 1.920180, 0.384790, -0.504890, 0.609610, -0.423600, 0.546870, -0.116440, -0.338610,
-1.153010, -0.072930, -0.230780, 0.727800, -0.756200, 0.109090, -0.720310, 0.406770, 0.326300, 0.491780,
-0.691970, -0.431850, 1.059910, -0.688250, 0.087910, 0.219730, 0.355210, 4.888510, 0.533080, 3.270160,
-0.328190, -0.095230, 0.470470, -1.995550, 12.081490, -0.061740, 0.209650, 0.124680, 0.274610, -0.549130,
-1.584190, -0.218440, 0.640600, 1.106230, -1.774450, 0.865520, 1.028000, 0.446430, 2.529470,
0.895300, -0.213640, -0.642230, -0.547940, 0.525130, 0.229140, 0.011350, 0.421690, 0.459280, 1.049870,
-0.685410, 0.139290, 0.661700, -0.692820, 0.350360, -0.063150, 0.883940, 0.010070, -0.587590, 0.169270,
0.079920, 0.492350, 0.259650, 0.348670, 0.543390, -0.692010, -0.341020, -0.167970, 0.533570, -0.836570,
0.466260, -0.339290, 0.706270, -0.272500, 0.708080, 0.558420, -0.020130, 0.242820, -0.353630, -0.302940,
0.860660, 0.169880, -1.067620, -0.215330, -0.205630, -0.903940, 0.651400, -0.875380, -0.445820, -0.481250,
0.460790, 0.366760, -0.728230, 0.216350, -1.674820, 0.490020, 0.808460, -0.469100, -1.013820, 0.250770,
-0.485290, -1.066970, 0.540890, -1.498690, 0.471730, 0.447380, 0.604900, -1.013830, -0.289130, 0.279540,
-0.627490, -0.943400, -0.533270, -0.282150, 0.639350, 0.111350, 0.277960, 0.794270, 0.804590, 0.259430,
0.164720, 0.245920, -0.309990, 0.781300, -1.050310, 0.603140, -0.483600, 0.688770, -1.094380, -0.222490,
-0.503210, 0.157470, -0.858910, 0.275750, -0.649270, -0.778500, 0.178940, 0.208240, -0.625360, -0.724150,
-0.086540, 0.675430, -0.546620, 0.294260, -0.121320, 0.065330, 0.195800, 0.106020, -0.135430, 0.118320,
0.734940, -0.192090, -0.829660, 1.432150, 0.645700, -0.468000, -0.566950, -0.296940, 0.537750, -1.216400,
-0.242810, -0.452330, 0.677730, -0.437250, 1.014770, 0.987860, -0.922480, 0.763360, -0.116740,
0.790920, 0.789100, 0.287250, 0.668620, 0.459240, 0.370000, 0.924620, 0.269500, -0.660620, -0.078590,
-0.459950, -0.094250, 0.274540, 0.419250, 0.447020, -0.407000, -0.919420, 0.329420, 0.004590, -0.449840,
-0.049630, 1.032330, 0.711190, 0.086420, -0.463620, -1.027470, -0.628000, -0.285390, 0.654600, 0.232690,
-0.718020, -1.014890, -0.989110, 1.113460, -2.849300, 0.272010, 0.732060, 1.508360, 0.349290, -0.073230,
-1.306130, 0.616810, 0.985230, -3.451470, -0.365320, -0.229480, 0.020060, -0.168240, -0.309390, -0.802180,
-0.348590, 0.572310, -1.347180, 0.586370, 1.500630, -1.784480, -0.477260, 0.388810, -1.505190, 0.641250,
-1.639030, 0.453150, 0.153810, 0.170500, -5.568430, 0.757200, 0.474210, 1.075460, 0.839760, 0.596670,
0.708210, 0.594300, -0.218040, -0.159550, -0.217890, -0.154510, 0.558420, -0.411210, 1.066270, 1.385090,
-0.448960, 1.043800, -1.289020, 0.263820, 0.962200, -1.028920, 0.307260, -0.680390, 1.268610, -0.900710,
-0.358050, -0.955850, -0.378220, -0.139450, -0.593730, 0.864850, 0.842470, 0.931390, 0.179810, -0.858650,
-0.134100, -0.451360, -0.799190, 0.787670, -0.466430, -1.467550, -0.675500, 2.249210, 0.765530, 2.523270,
0.079040, 0.169180, -0.795840, 0.624580, 1.455360, 0.542840, -1.105680, -1.411350, -1.692150, -1.101910,
0.186560, -0.494900, 0.572850, 0.582790, 0.923790, -0.080480, -0.242870, -0.061500, -0.824620,
-0.786630, 0.260410, 0.349790, -0.202220, -1.094850, 0.420600, 0.741670, -0.747430, -0.656880, -0.021130,
-0.460980, -0.950650, -0.521800, -0.835110, 0.222470, -0.196350, -0.390210, 1.152330, 0.081640, 0.569420,
-0.189410, 0.195690, 0.060610, 0.500900, -0.832500, -3.241800, -0.440220, 0.661060, 0.370470, -0.298120,
-0.096510, -1.154570, 0.459290, 1.598410, -1.990480, 0.751060, 0.230140, -1.353800, -1.084790, -0.681150,
-0.897640, 0.162960, -0.557340, -0.821850, -0.510630, -0.449270, -1.396920, 0.692740, 0.569070, -0.605790,
0.553960, 0.147690, -1.162790, 0.393740, -1.151910, 0.044690, -0.405050, 0.121740, -1.208570, 0.628360,
0.476000, 0.049110, -1.538260, -1.116110, 0.598630, 0.592140, -0.054580, -1.189860, 0.251710, 0.335590,
0.365770, -0.070560, -0.828510, 0.144600, 0.018860, 0.495610, 0.808250, -1.294610, 0.672840, -1.204060,
-0.575040, -0.267450, 0.272930, 0.486200, 0.118330, 0.527610, 0.537860, -0.300830, -0.485920, 0.019570,
-0.333780, 0.983450, 0.187230, -0.175250, -0.204290, -0.424950, -0.577400, 0.522700, 0.804240, 0.450220,
-0.336060, 0.295180, -0.012370, -0.043640, -0.652110, -0.306840, -0.416410, -0.562680, 0.303180, 4.352460,
0.525250, 0.506480, -0.111060, 0.193320, 4.618580, -0.781470, 0.376440, -0.205770, -0.542490, 0.184440,
-0.404020, -0.088050, -0.768880, 0.403590, -0.251120, -0.092930, 0.402190, 0.031980, 0.737480,
1.759870, 1.850110, -0.755420, 0.202120, 0.618970, -0.133710, 0.058490, 2.196280, 0.481570, 0.334680,
-0.527620, 0.828590, -0.285010, 0.679250, -0.744440, -0.901290, 0.803440, 0.439980, -0.050450, -0.605660,
0.504070, -0.550400, 0.053260, 0.998990, -0.361170, 0.671240, -2.492640, -0.099130, -1.941920, 1.004150,
0.346310, -0.832890, 0.317170, -1.084660, -0.369280, -0.114120, -0.610360, 0.032850, -0.405960, -0.416470,
0.587060, 0.273320, 0.013520, 4.587600, -1.224620, -0.328070, -0.099780, 3.173210, -1.090110, -1.153410,
2.783970, -0.563660, -1.198890, 0.458840, -1.343450, 0.384370, 28.416679, -0.826910, -0.458310, 1.135460,
-1.123360, -3.927290, 0.120100, -1.436720, 0.645530, 24.904819, -0.092630, 2.912090, -0.108430, -0.062090,
-6.904720, -0.818030, 0.227470, 4.352180, 14.219880, 0.252620, 7.990390, 0.532240, 0.609790, 0.172950,
0.208850, -1.400910, 13.375070, -0.000990, -0.398510, -0.356100, 0.560910, 0.170290, -1.976020, -0.331150,
0.032970, 27.971661, -0.632080, 0.025010, 0.126700, 1.036560, 1.941520, -5.105950, -1.287570, -0.761570,
-1.257610, 0.979960, -1.248950, 0.838660, 0.337810, -0.588870, 0.070500, -1.859460, -0.304390, 2.913720,
0.766600, 1.805950, 0.052410, -0.007400, -12.699360, -1.301800, 0.253110, -3.302110, -5.526890, 1.017970,
1.725830, 1.232610, -0.471960, -0.390960, -0.967640, 1.449900, -0.724750, 0.034800, -2.128840,
-0.178670, 0.948350, 0.073140, 0.625270, 0.431630, 0.139810, 0.893330, 0.133140, 0.559380, 0.441260,
-0.037510, 0.701430, 0.009050, 0.383470, -0.276980, -0.955910, -0.151920, 0.261710, -0.437130, 1.751620,
0.608060, -0.153770, -0.744620, -0.584140, 0.259810, -1.353360, -1.073440, 0.121060, 1.461530, -0.612400,
1.251450, -0.305870, -0.586480, -0.174910, -0.640840, 2.063220, 0.234400, -0.035050, 0.207920, 0.988790,
0.864500, -0.748420, -0.400930, 1.341160, -0.162200, 0.890790, 0.163110, 1.866300, -0.867800, 0.303900,
-1.462370, -0.994110, -0.601880, -2.537310, -0.742270, -2.282270, 2.270120, 0.189000, -0.028580, 0.321670,
-0.376640, 0.969480, 0.440010, 0.371220, -7.781910, -3.396970, 0.604080, -0.244080, -1.062050, 0.895380,
11.326030, 1.166150, 0.786000, -5.882770, -0.062960, -0.046420, -1.579270, -0.937260, 0.097990, 3.785180,
0.539700, 0.128090, -10.029530, 0.193940, -0.693500, -0.624930, -1.062250, 0.026980, 5.697890, 0.755850,
-0.676530, -4.343960, 0.534980, -0.174980, -4.129630, -0.503470, -2.057350, -0.602320, -0.049220, -0.208980,
-0.414680, -0.705380, -0.079630, -0.052150, -3.288100, 0.770480, -0.471690, -3.158030, -0.448270, -1.599900,
0.516160, -0.057310, -0.468310, 3.048530, 2.559300, -0.063080, -0.038930, -1.631140, -1.150820, -0.386610,
-6.869660, -0.911400, 0.637880, 0.301320, 0.781810, 0.291970, 0.191900, 1.046020, 0.050600,
0.625940, 0.292090, -0.386200, 0.364800, -0.602840, 1.080620, 0.462290, 0.160120, 0.441020, -0.075430,
0.092310, 0.036880, 1.056070, 0.848420, -0.542930, -0.863250, 0.854950, 0.144560, -0.127280, -0.458170,
1.335820, 0.728880, 0.259580, -0.699270, 0.302750, 0.688290, -0.724770, 0.566620, 0.021450, 0.333960,
1.601940, 0.797700, 0.173160, 7.895000, 0.905240, 0.140860, 0.934150, 0.629140, 0.667180, 5.790070,
0.654440, -0.931520, 1.755860, -2.540840, -1.200220, 4.737720, 0.689280, -0.778070, 3.252520, -0.240560,
-0.243810, 0.422590, 0.539130, -1.080480, 4.846000, -0.447840, 0.103530, -0.686190, -0.235680, -1.287420,
-1.714400, -0.177350, 0.207060, 0.119410, 0.004860, -0.914940, 0.908810, -0.164620, 0.486210, -0.996910,
-0.403270, -0.705750, 0.310020, -0.386400, 0.409390, -0.240520, -0.132470, -0.802540, 0.251930, 2.048790,
0.258600, 0.079700, -0.052260, 0.980770, -0.809260, -0.781900, -0.614910, 0.379100, 0.358110, -0.113990,
-0.067210, 0.730690, -0.683040, 0.674830, -0.587780, 1.005050, 0.590100, 0.909870, 0.478720, -0.014900,
-0.146740, 1.112990, 0.305910, -0.581250, 0.052320, -0.172050, 1.036190, 1.698070, 0.957910, -0.416600,
-0.536610, -0.608090, 0.597350, -2.149020, 3.562340, -3.076810, 0.176340, 0.754690, 0.074110, -1.016760,
0.017000, -1.067460, -0.204150, 0.229140, 1.498260, -1.177690, -4.401540, -1.775430, -0.367920,
-0.894220, -0.831080, 0.317220, 0.242880, 0.604360, -0.068060, -0.412420, -0.778070, 0.597160, 0.838490,
0.873330, -0.653500, -1.390550, -1.450080, 0.305860, -0.046840, -0.805190, 0.063670, -0.696670, -0.830370,
0.813930, -0.780400, -0.420380, 0.591510, -0.068910, -8.575120, 0.014340, -0.960940, -0.517520, -0.911370,
0.413700, 0.093160, -0.880280, -0.243120, -0.621970, -0.469570, 0.685640, -0.116520, -0.925000, 0.628060,
-0.704950, 0.266790, -0.553320, 0.036630, -0.889890, 0.987480, -1.098120, 0.653040, 0.404040, 0.644900,
-0.428940, -0.607830, -1.725600, -0.435660, 0.162800, -1.112600, 0.450650, -0.406380, -1.714920, 1.005940,
-1.181210, -1.258110, -0.119460, -0.349390, -0.044550, -0.643560, -1.148650, -0.919690, 0.977770, 0.105210,
0.275230, 0.709180, -0.323920, -1.672590, -0.366490, -0.430170, 0.402920, -0.246400, -0.819390, 0.045780,
-0.502660, 0.531980, 0.215410, 0.177520, 0.183850, 0.315500, -0.140990, 0.200990, 0.068790, 0.444530,
-0.546330, 0.534760, 0.939170, 0.547070, 0.119220, -0.783940, -0.167160, -0.476760, -0.786590, 0.023720,
-0.333280, -0.300170, 0.571190, -0.548460, 1.556370, 2.286480, -0.375240, 0.196760, 0.517360, -8.278850,
0.484990, -0.545030, 0.653560, 3.135030, 2.828370, -0.743740, 0.627950, -1.922710, -0.442750, 0.285570,
-1.306420, 0.567560, -0.630820, -0.546840, 1.064250, -0.593500, -0.652050, -0.050100, -0.593120,
-0.803440, 1.496240, 0.224340, 0.595110, 0.906690, 0.540300, -1.056340, -0.259790, -0.180000, 0.785600,
0.543460, 0.914870, 0.477040, -0.500110, 0.657450, 0.061190, 0.674860, 0.693400, -0.433040, 0.568310,
1.095830, 0.465070, -0.525080, 0.064950, -0.477320, -0.803850, -0.085240, 1.007200, 0.055450, 0.211080,
-0.191870, -0.787190, -0.105610, 0.749700, 0.463760, 0.439770, -0.496730, -0.725440, -0.716330, -0.173740,
0.662050, -0.151410, -0.191180, 0.923850, -1.802480, 0.704750, -0.260860, 0.073890, 0.513950, 0.366460,
-1.854340, 0.188000, 0.335330, 1.574690, -0.551160, -1.319850, -1.805710, 0.298630, 0.421990, -0.980360,
0.293950, 1.031170, -0.740500, 1.054410, 0.919080, -2.851300, 0.160030, -0.507100, -1.159100, 0.365410,
-0.346080, -0.162530, 1.045810, -0.712400, 0.206480, -0.611070, 1.052520, -0.657570, -0.067560, 0.455360,
0.336900, -0.117070, -0.452630, 0.183180, -0.595810, 0.299340, -0.974010, 0.245830, -0.396680, 0.191400,
0.204070, -0.291990, 0.355640, -0.510930, 0.312020, 0.125830, -0.725360, -0.811380, -0.808620, -0.200990,
-0.309340, -0.749500, -0.680600, 0.270290, -0.321580, -0.101900, -0.626100, 1.612720, -0.392740, -0.075600,
0.880060, -0.759020, 1.068780, -2.734700, 1.356240, 0.225820, -0.504460, 1.130860, -0.021220, -0.642750,
2.666260, 0.525310, 0.891980, -0.768170, -0.709580, -0.018970, 0.532610, -0.504990, -0.270160,
0.176880, -0.020050, -0.201870, -0.401830, 0.705180, 0.901420, 0.678320, -0.683630, 0.364550, 0.374310,
-0.090450, 0.787030, -0.813990, -0.404630, 0.900840, -0.198770, 0.080670, -0.768060, -0.713950, -0.348140,
0.696070, -0.445540, -0.039310, -0.989690, -0.071730, -0.674170, 0.832650, -0.946090, 1.121470, -0.132360,
0.824250, -0.337090, 0.362600, -0.829820, 0.036380, 0.640840, 0.808770, 0.509000, -0.358380, 0.644780,
-0.223770, 0.328970, -0.758290, -0.545130, 0.103850, 0.098720, -2.327570, -0.488650, -1.012950, 0.833030,
-1.064670, 0.865520, 0.264330, -1.180670, -0.049010, 0.654390, -0.584150, -0.985430, 0.362090, 0.007700,
0.950260, -0.159030, 0.309280, -1.065670, -0.661730, -0.464820, -0.072280, -0.798720, -0.379660, 2.038130,
0.709780, 0.286030, -1.130470, 0.797840, -0.435500, -1.243040, -0.072090, -0.404250, 0.843950, -0.199530,
0.073050, -0.232510, 1.003210, -0.506540, -0.263650, -0.475810, -0.730620, 3.885570, 0.790260, 0.634680,
-1.199430, 0.943800, -0.522080, -1.172680, 0.210630, 0.556950, -1.279430, -0.225990, 0.625290, 0.745970,
-0.911510, -0.381900, 0.476140, 0.621830, -0.359350, -0.466300, -0.181940, -0.777430, -0.386700, 1.316940,
0.608990, -0.250480, -0.802750, -3.069030, 1.927320, -0.730870, -0.335900, 0.270650, 0.280350, -0.228250,
-0.820320, -0.049160, -0.422080, 0.714460, 1.318110, -0.956950, -0.897960, 0.221910, 0.581360,
-1.013690, -0.648050, 0.660360, 0.838840, -0.218360, 0.579090, -0.398210, 0.304310, -2.446990, 0.171100,
-2.565460, -0.839510, -0.707610, 0.524050, -1.886600, -1.381670, 0.799610, -0.117970, -0.462760, -0.867430,
-0.997150, -0.604940, -0.362840, 0.321920, -0.744680, 1.082700, 1.140200, 0.622630, 0.337240, -0.855150,

-0.761160, 0.350720, -0.565720, -0.993600, 0.790000, -0.406440, -0.076560, 0.591850, 0.194940, -0.884570,
0.530970, -0.254690, 0.087670, 0.384650, -2.519230, -0.592300, -1.390310, -0.830520, 0.721690, -0.075750,
-0.132890, 0.812020, -2.904240, -0.829560, 0.297910, -0.925710, 0.188800, -0.967400, 0.367050, 0.147000,

0.727750, 0.509810, -0.555470, 0.435140, 0.464330, 0.000860, -0.153090, -0.776790, 0.305390, -0.100580,
-0.552900, -0.262700, 0.180070, -0.857030, 2.286520, 1.183870, -0.473420, 0.197190, -0.113140, -0.542690,
-0.225830, -0.310710, -0.128330, 0.941870, 0.799980, -0.786690, -0.684850, -0.710970, -0.133540, 0.454760,

-1.091490, -0.533380, -0.347090, 0.227010, 0.414790, -0.669740, 0.287690, -0.834020, -2.307720, 0.155190,
-3.581940, 0.226750, -0.323870, 0.194820, 1.398810, -2.074500, 0.579310, 0.183570, -0.870800, -0.965040,
0.618720, -1.177270, 0.781760, -0.883940, -1.183170, 0.948950, 0.706360, 0.484210, 0.594700, -0.802050,

0.098880, -0.256500, 0.742940, -0.984780, -0.292510, -0.696450, 0.383530, 0.675140, 1.176550, 0.397960,
0.842200, -0.732190, -0.991450, -0.372780, -4.489920, -0.187330, -1.685980, -0.616900, 0.263290, -0.439870,
0.440110, 0.386940, -1.838250, 0.003100, 0.734740, -0.688050, -0.688050, -0.936780, 0.823160, 0.522230,

0.004730, 0.961760, -0.505040, 0.712290, -0.341350, 0.889250, -0.761460, 0.703870, -1.011400, -0.697800,
-0.070090, 1.062330, 0.522630, -0.137610, -1.091370, 1.209860, -0.470890, 0.908480, -0.213180, 0.289950,
0.348820, 0.438100, -0.486910, 0.056130, 0.238990, -1.038750, -0.995160, -0.355890, -0.790920, 0.085190,

0.432890, -1.002490, -0.211570, -0.017500, 1.132960, -1.479250, 0.244720, -0.724300, -2.504830, -0.802120,
-0.214850, 0.153010, 0.678930, 0.996160, 1.012740, -1.873550, 0.920350, 0.544980, -0.969700, -0.735510,
-0.297320, -1.135740, 0.452630, -0.747120, -1.012480, 0.873490, 0.227780, -0.032340, 0.633590, -0.848520,

0.432020, -0.650120, 0.048360, -0.013040, -0.505530, -0.641360, 0.317620, 1.256300, 0.950590, -0.471820,
0.580720, 0.323770, -1.309560, -0.293250, -1.875950, 0.907570, -1.718260, -0.177520, 0.413320, 0.577770,
0.501380, -0.772940, -2.175650, 0.390690, -0.413050, -1.527030, 0.000980, -0.502920, 0.889640, 0.633660,

0.300870, 0.806350, 0.789410, -0.602210, 0.021440, 1.377520, -0.408630, 0.334120, -0.925120, 0.248120,
-0.707080, -0.546990, 0.132160, -0.130390, -0.682480, -0.045280, -0.816100, 0.081510, -0.624350, 0.039010,
-0.086630, 1.067330, 0.262050, 0.763970, 0.321160, -0.922960, -0.760110, 0.460580, -1.107980, -0.399670,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.698640, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.364800, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, 0.008870, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.096740, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.480470, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.081450, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.836390, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.398540, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.148690, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.943050, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.572320, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.383560, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.499290, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.111650, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.302620, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.084440, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.273360, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.670990, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.423480, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -1.017400, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.121840, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.071320, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, -0.035050, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, 0.029150, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.790710, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.631370, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, 0.233960, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.910180, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.277380, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.287010, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.259350, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.708960, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.327910, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.494620, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.913880, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.646270, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.175220, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.839400, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.865140, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.07549, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.05947, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
1.25899, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42804, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
1.19572, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.00018, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.33181, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
1.02341, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.05193, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.42646, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
0.00905, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
0.82775, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
0.58936, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.42828, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
0.00012, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00033, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
1.01837, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
1.42857, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.00006, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.02470, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.06106, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.38297, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.10740, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.44790, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
0.42655, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
1.42857, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
0.31612, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
0.97433, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.00295, 0.500000, 2,
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
