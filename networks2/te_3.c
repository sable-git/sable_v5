/*********************************************************
  TMPtest_new3_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:24:33 2004
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
-0.498930, 0.706820, 0.672480, 0.946200, 0.060080, -0.107830, -0.722900, 0.476520, 0.685180, 0.915640,
0.389920, 0.118560, 0.679260, -0.192890, -0.491630, -0.828410, -0.179100, 0.670590, -0.377560, 0.096570,
1.043970, -0.266070, 0.377660, -0.735830, 0.315280, -0.998010, -0.192180, 0.089200, -0.291030, 0.484030,
-0.386460, 0.020350, -0.544380, 0.087480, 0.036990, 1.850170, 0.760290, -0.591740, -0.041830, 0.030430,
-0.701560, -0.973900, -0.869850, -0.180690, -0.426260, -2.910610, 0.537370, 3.453900, 1.585410, 0.023620,
-1.419580, 2.335870, -0.732100, 0.165050, -0.100980, 0.628890, -0.053970, 0.687610, 0.535640, -0.167220,
-0.591470, -0.237350, -0.846860, 0.630350, -0.505450, 0.782540, -0.322460, 0.423830, 0.111950, 0.327680,
-0.173300, 0.812270, -0.772530, -0.687960, 0.066530, 0.060390, -0.170560, -0.384750, -0.464800, -0.703230,
-0.412490, -0.779680, 0.381640, 0.024750, -0.853480, -0.339890, -0.768890, -0.081260, -0.984960, -0.856250,
0.627460, 0.163480, 0.913550, -0.528740, 0.787070, -0.264380, 0.614890, -0.142690, 0.297250, -0.809430,
0.692950, 0.368830, 0.046380, 0.221050, 0.779800, 0.001260, 0.512430, -2.862440, 0.176320, -1.114090,
0.906610, 0.139140, 0.587520, 0.085110, 5.404540, -0.338300, -0.080250, -0.299360, -0.627450, -0.550030,
0.257350, -1.023310, 0.438620, 0.749400, -1.297400, 0.912010, -0.770630, -3.171720, 0.077790,
0.261630, -0.134930, 0.500870, -0.142180, -0.455640, -0.048750, -0.687150, -0.780530, -0.421020, 0.207160,
0.791110, -0.314800, -0.810550, 0.261500, 0.067160, 0.327880, 0.099240, 0.841110, -0.735420, 0.480090,
0.040610, 0.733750, -0.649400, -0.870180, -0.018880, 0.072480, -0.766460, 0.064620, 0.392830, -0.429590,
0.040100, -0.283190, 0.605860, -0.260490, 0.620960, 1.030970, -0.102010, 0.447590, 0.128020, 0.244240,
-0.252400, -0.326870, 0.779930, -0.514160, 0.053160, 0.612960, 0.718030, -0.423820, 0.408240, 0.260340,
-0.414750, -1.188720, -0.052070, 1.474300, 0.579860, -0.139640, -1.203710, -1.006800, -0.195860, -0.282020,
0.349380, 0.369280, 0.950420, -0.881410, -0.499370, 1.686210, 0.369460, -0.766770, 0.272750, 0.236950,
0.909670, 0.094620, 0.598870, 0.044900, 0.435790, -0.953570, -0.210350, -0.531560, -0.539760, -0.472800,
0.702950, -0.927950, -0.409090, -0.599610, 0.586940, 0.113250, 0.130640, 0.081070, -0.028580, 1.084100,
-0.695830, 0.649560, 0.335990, 0.012840, 0.682480, 0.842210, -0.175600, 0.212780, -1.084580, -0.054510,
0.207900, -0.791410, -0.143170, -0.201660, -1.125470, 0.375530, -0.753830, -0.294870, -0.636670, -1.000390,
0.218440, 0.795050, 0.163190, -1.105300, -0.337110, -1.512400, 0.287250, 0.595800, 0.988080, -0.647020,
0.331200, 1.411370, -0.046280, 0.399670, 0.049930, 0.761030, 0.618200, -0.815510, -0.386980,
-0.482990, -0.158400, 0.254050, 0.951650, -0.152590, 0.119410, -0.548070, -0.856360, 0.711300, -0.826170,
0.519800, 0.082320, -0.181650, 0.149310, 0.512080, -0.968540, -0.066760, -0.959140, -0.366600, -0.843150,
-0.462280, 0.377550, -0.331230, -1.054300, 0.087240, 1.009100, -1.072540, 0.399630, -0.719320, -0.663090,
0.237290, -0.951170, 0.713920, 0.774300, 1.026980, -1.067860, -0.640040, 0.481420, -0.240650, 0.005180,
0.164120, -0.090370, 0.411660, -0.002270, -0.256100, 0.738600, 0.804440, -1.267460, -0.497660, -0.266470,
-0.587720, 0.586390, 0.158110, 1.173610, -0.469060, 0.164990, -1.438330, -0.969970, -0.647940, -0.478780,
-0.414740, 0.393160, -0.701130, 0.139340, 0.662490, 1.034180, 0.591940, -0.547480, -0.346150, 0.114750,
0.483830, -0.166510, 0.184130, -0.885620, 0.977050, -0.694050, 0.401130, 0.717110, -0.034370, 0.640860,
0.706420, 0.563620, -0.316700, 0.148140, 0.089140, -0.046350, 0.805900, 0.116160, -0.566460, 0.680190,
-0.800200, 0.611830, 0.466850, 0.851230, 0.907650, -0.794830, 0.130310, -0.024840, 0.429820, 0.788850,
-0.147420, 0.041000, 0.582240, -0.330030, -0.720040, -0.452470, 0.527810, 2.237430, 0.208600, -0.565370,
-0.993940, 0.128300, 0.393980, -0.926580, 4.683140, 0.069070, 0.841380, 0.598140, 0.677620, -0.095230,
0.965490, 0.476320, -2.006550, -0.148450, 1.392710, -0.899990, -0.385110, 1.226470, -0.632560,
0.965890, -1.353390, -1.249540, 0.029700, 0.689030, 0.689530, -0.386210, -1.027720, -0.540520, 0.171160,
-0.311050, -0.441720, -0.941190, -0.374280, -0.630910, -0.452100, -0.019070, -0.560020, 0.408790, 0.750690,
-0.944060, -0.418250, 0.192290, 0.321030, 1.091670, -0.170640, -0.844200, 0.072350, 0.172090, 0.850980,
-0.255470, -0.252280, 0.531180, 1.172730, -1.692490, 0.974710, 0.256320, 1.627520, 0.328000, -0.504710,
0.298100, -0.312870, 0.700140, -0.342640, -0.443100, 0.098140, -1.423130, -0.154470, -0.794220, -0.447370,
-0.449440, 0.735770, 0.928240, -0.009620, -0.706380, -0.447340, -0.430010, 1.290210, 0.467290, -0.776470,
-2.164160, 1.415660, 0.225260, 2.490110, -0.859060, 0.097570, 1.238600, 0.832580, -0.499010, -1.369410,
0.570850, -0.440180, -0.103520, -0.412550, -0.746600, -0.456910, -0.246330, 0.045430, -1.276570, -0.136270,
-0.418770, -0.536430, -0.952210, -0.447200, -1.009630, -0.829950, -0.657830, -0.725350, -0.951220, -0.557400,
0.646770, 0.299330, -0.561070, 0.903590, -0.473990, -0.842950, 1.021780, -0.319350, -1.136980, 1.185880,
0.571330, -0.689400, 0.031440, 0.545520, -0.169610, -0.843310, 0.409600, -0.734940, 0.649930, 0.134400,
0.453760, 1.095360, -0.429720, 4.367010, 2.455420, 2.599070, 0.571210, -0.184060, 1.386510, 0.655160,
-0.785990, 2.350100, -0.738090, -0.086100, 1.324470, 0.625790, 0.366320, 0.082150, -0.125250,
0.105930, -1.015770, 0.297190, -0.167680, -0.369460, 0.375330, -0.259690, 1.230610, 0.958120, -0.121550,
0.738150, 0.725930, 0.214660, 0.348200, -0.390590, -0.321210, 0.025930, -0.741820, 0.159400, 0.206990,
0.597470, -0.898520, -0.897610, -0.054270, -0.523740, 0.647020, 0.142280, -0.534690, -0.463830, -0.573680,
-0.543060, 0.889490, -0.492920, 0.143360, -0.540090, 0.242830, -0.045010, 0.995290, 0.441990, -0.508570,
1.040870, 0.968270, 0.523090, 0.197600, 0.780610, 0.057100, 0.174270, -0.172050, -0.149200, 0.130380,
0.751020, 0.581700, 0.334680, -1.215690, 0.325910, 0.424930, -0.748060, 0.635970, -0.310980, -2.809920,
-0.593060, 0.132270, -0.130560, 0.340180, -0.810950, -2.169510, -0.549540, 3.509750, -0.145550, 0.494250,
1.224930, 0.245430, -0.771170, 0.117790, 0.373710, 0.222120, -0.648530, 0.279880, -0.250640, 0.626960,
0.776730, -0.240330, -3.018910, -0.269760, 0.400210, 0.454710, -0.120140, -0.373960, 0.339800, 0.252140,
0.835350, 0.370930, 0.456910, -0.059510, -1.027330, -0.051180, -0.544880, 0.907500, 0.668570, -0.533880,
0.895800, 0.303890, 0.889820, -0.355750, 0.838240, 0.092780, 0.974770, 4.031770, 0.204140, -0.436460,
1.321500, 0.177650, -0.691870, -0.363880, -7.677140, 1.568540, -0.260030, 0.619060, 0.301570, -0.146780,
-0.161590, 0.359320, -0.534130, 0.312560, -1.206940, 0.322390, 1.148050, -0.644750, -1.488660,
-0.502740, 0.556810, 0.467480, 0.009550, -0.156510, 0.722810, -0.248430, -0.386100, 0.015460, -0.078450,
0.492450, 0.933750, -0.493210, -0.693620, -0.073400, -0.283720, -0.471350, -0.632310, -0.104140, -0.685310,
-0.006100, 0.047750, -0.188170, -0.338130, -1.280330, -0.625000, 0.583440, 0.317540, 0.972910, 0.985440,
0.104350, 0.226390, -0.244920, 0.339890, -0.175160, 1.076770, 0.528180, -0.698210, -0.215500, -0.897370,
0.244100, 0.301930, -1.259960, 0.335310, 1.840930, -0.718730, 1.122510, -0.365140, 0.138500, -0.252190,
-0.153780, -0.324350, -0.139130, 0.251130, -0.190750, -0.370020, 1.049030, -0.359010, -0.687580, 0.649620,
0.078060, -1.055230, -0.049920, -0.777810, 0.863640, 0.371700, -0.743040, -0.592070, 0.288530, -0.238170,
0.090600, 0.227460, 0.113200, 0.040770, -0.301670, -0.402680, -0.263400, -0.317070, 0.020430, 0.930720,
0.668040, 0.314390, 0.182370, -0.619210, -1.015240, -0.841660, -0.759850, 0.666810, 0.383970, -0.202280,
-0.144530, -0.881480, -0.481700, -1.110850, 0.461040, 0.606100, 0.535240, -0.189420, 0.327180, 0.413770,
0.564160, -0.586910, -0.267830, 0.186040, -0.506830, -0.372300, 0.974080, -0.193290, -0.065660, -0.341930,
-0.066190, 0.383150, 0.400290, 1.554270, 2.251170, -3.360370, 0.186630, -0.804140, -0.155050, 0.031900,
1.152850, -0.290040, -0.222530, -0.738880, 0.675050, -0.443990, -0.492640, -0.728270, 0.201250,
0.774520, -0.801850, -1.006140, 0.808720, 0.606250, -0.460700, -0.903500, 0.301950, 0.111980, 0.301150,
-0.513920, -0.814200, 0.805300, -0.246980, -0.692500, -0.621430, 0.136030, -0.031300, -0.491370, -1.429090,
-0.733080, 0.423180, -0.044760, 0.540110, -0.483590, 0.848110, 0.631820, -0.208860, -0.286960, 0.511370,
-0.024330, -0.508050, 0.478650, 0.510290, -0.803770, -0.059060, -0.418010, 0.450550, -0.416100, -0.072470,
-0.289360, 0.359390, -0.234790, 5.651310, -1.110130, 1.048290, 0.865510, 0.282940, -0.531880, 2.539770,
-0.739500, 0.631400, 15.653080, 0.085610, 0.853310, 5.610040, -0.500540, 0.457600, 16.525930, 0.445620,
-0.208940, -3.482520, -0.193340, 0.639390, 4.924730, -0.960220, -1.824010, 0.839230, -0.513670, 0.599740,
0.903900, -0.632810, -0.184520, -1.252220, 0.362240, 0.165660, -0.732000, 0.540430, 0.578540, 0.339230,
-0.164720, 0.518700, -0.622460, -0.023650, -0.822820, 0.348410, 0.448870, 0.624760, 0.326410, 0.849430,
0.914350, 0.492940, 0.530120, 0.365440, -0.455270, 0.096370, 0.601670, -0.427220, -0.218750, 0.288820,
-0.611780, -0.382650, -0.802330, 1.048360, 0.274240, -0.896090, -0.969000, -2.511610, -0.691090, 0.242130,
-0.748710, -0.195630, -0.296820, -0.628470, -34.375610, -0.302920, -0.630350, -1.034000, -0.652000, 0.693590,
0.504030, -0.692240, -0.207790, -0.366070, 0.349000, 0.526840, -0.197940, 1.140920, -0.123140,
-0.411660, 0.551110, -0.439160, 0.182500, 0.878320, 0.311710, -0.418650, -0.255400, -0.475520, -0.358460,
0.567970, 0.104380, 0.348370, -0.540530, -0.801490, -0.323300, 0.926340, -0.244340, 0.194470, -0.133540,
-1.077500, -0.968840, 0.601880, 0.534950, 0.004680, 0.497940, -0.587050, 0.106130, -0.610710, -0.192080,
-0.453160, -0.472910, 0.853700, -0.272300, -0.109700, -0.492240, -0.176180, -0.561560, 0.465300, 0.044110,
0.371150, -0.284880, 0.689890, -0.322460, 0.561620, -0.650870, -0.836060, -0.529090, -0.052940, 0.357910,
0.102830, -0.370200, 0.108550, -0.818560, -1.357530, 0.601500, 0.768390, -0.147700, 0.394690, -0.825300,
-0.006710, 0.514560, 0.720770, -1.506530, 0.482020, -0.041260, -1.259170, 0.173500, 0.169640, 0.176090,
0.279350, -0.821100, -2.238080, 0.640890, -0.568200, -0.963300, 0.079240, 0.549430, 1.811210, 0.353720,
0.984620, 0.717000, -0.586640, 0.594500, 0.591240, 0.749960, 0.378090, -0.805580, -0.139680, 0.911580,
0.858300, 1.079210, 0.564230, -0.573760, 0.983060, 0.844970, -0.396380, -0.171100, -0.450030, -0.289810,
-0.231110, 0.184600, 0.685260, -0.848180, -0.536070, 0.825350, -0.733380, -0.224090, 0.185590, 0.037390,
0.699580, -0.983860, -0.790360, -1.744800, -2.892060, -2.218340, -0.589780, 1.309200, -0.118900, 0.040090,
0.367550, 0.270550, 0.611090, 0.184650, -1.087320, -0.171920, 0.787130, 2.080790, 0.172030,
-0.998410, -0.521790, -0.796220, -1.323730, -0.930330, 0.711000, -0.460780, -0.721400, 0.187360, 0.774060,
0.208760, 0.027500, -1.081800, -0.258880, -0.801450, 0.020830, 0.133470, 0.203340, -0.800900, 0.497590,
-0.714840, -1.093080, -0.303970, 0.703790, 1.243480, -0.468010, 0.690130, 0.848250, 0.561710, 0.153030,
0.485780, 0.940090, 0.370270, 1.050830, 0.570170, -0.675070, -0.136690, -0.761530, 0.770080, -1.281130,
-0.957600, 0.286530, -0.287250, 1.653650, -2.073870, -0.694120, -0.673590, -0.037570, -0.612080, -0.358820,
0.254490, -0.071830, 1.089610, -5.949150, 0.114530, -0.324770, 1.339030, -0.097160, 0.783350, -1.210410,
-0.913260, 0.189990, -1.593820, -1.057340, 0.356830, -3.589270, -2.059110, -0.208010, -0.361250, 3.618490,
-0.651770, -0.512410, -5.838170, 0.412370, -1.540760, -10.567240, 0.236210, -0.466230, 2.777720, -0.682240,
-0.078830, -3.432660, -0.568730, -0.704850, -2.189020, -0.258570, -0.036890, 4.245280, -0.142120, -0.041350,
-1.287690, 0.459220, -1.134380, -0.147440, 0.592980, 0.555640, -0.914090, -0.113850, 0.831880, 0.009710,
1.284770, 1.874950, 0.478740, -0.769820, -0.807210, -0.747650, 0.813160, 0.101670, 0.681570, 0.047970,
0.591850, 1.616940, -0.662550, 2.005350, 4.193830, -0.220930, -0.312100, 0.523100, -0.091730, -0.560120,
-0.481060, 1.628270, -0.385210, 0.484150, -0.934990, -1.068940, 0.575890, 4.038520, 0.487490,
0.335950, -0.009600, 0.139200, -0.174120, 0.806400, 0.702570, -0.700200, -0.399490, -0.208040, -0.466260,
0.435880, -0.303130, 0.545660, 1.006140, 0.710150, 0.274540, 0.198290, -0.796030, 0.105400, 0.766960,
0.721590, 0.345790, -0.963810, 0.366470, 0.305150, 0.861900, 0.697880, 0.344990, -0.095430, -0.852460,
-0.225120, -0.810440, 0.010890, -0.398520, -0.682750, 0.312020, -0.001240, 0.422830, -0.179480, 0.145930,
-0.780830, -0.521990, 1.689080, -0.018850, -0.796700, -0.499580, -1.052360, -0.584180, 2.283010, -0.257600,
0.459280, -1.695650, 0.888370, -0.248390, 1.564030, -1.494700, -3.891240, -1.662710, 0.750910, 0.704620,
-0.508290, 0.639690, -0.680970, -0.798250, -0.283190, 2.299110, -0.211010, 0.570070, 0.638230, -0.208690,
-0.722550, -0.419020, -0.363870, 0.825550, -0.563860, -0.560400, -0.329840, -0.385590, 0.041650, -3.073510,
0.792760, 0.047330, 0.754690, 0.551850, -1.043080, 0.327190, -0.584010, -0.041130, 4.707800, 0.326690,
-0.629800, -0.792020, -1.754030, 0.816910, -0.384250, 0.200680, 0.548700, 2.464950, 1.452750, 0.628850,
-0.633210, -0.270590, 0.661070, -0.905080, -0.719520, 0.701090, 0.534930, -1.068600, 0.825310, 0.718930,
0.877620, -0.052470, -0.476180, 0.183900, 4.131950, -0.814490, -0.443360, 0.273020, 0.259290, 0.166370,
0.244910, -0.355760, 1.317580, 0.685960, 0.091340, -0.040170, 0.415050, -1.587880, -1.596050,
0.018630, -1.088710, -0.684820, 0.353130, -0.171420, -0.692590, 0.451160, 0.310030, -0.407200, -0.399790,
-0.178130, -0.605510, -0.228360, -0.145340, 0.718040, 0.199330, 1.068170, -0.022620, 0.214690, -0.012210,
0.033170, -0.008710, 0.536380, 1.106900, 0.877110, 1.060510, 0.214010, 0.706030, -0.368670, 0.180750,
0.848680, 0.312890, -0.470240, -0.042160, 1.277230, 0.683230, -0.303930, 0.561420, -0.893310, 0.958400,
0.984190, 0.559430, -0.814400, -0.111280, -0.600330, 0.065490, 1.259550, -1.035520, -1.225450, 0.494230,
0.474530, 0.618680, 0.476190, -1.012890, -1.205210, -0.326250, 1.326720, 2.188930, -0.162480, -1.173320,
-0.207210, -0.765090, -0.168670, 1.089720, 0.782420, -0.359190, 0.748810, 0.003480, -0.427720, 0.269390,
-0.567380, 0.230320, -0.368650, 0.090680, 0.049050, -0.159070, -0.693770, -0.760180, -0.425730, -0.885930,
-0.534830, -0.463560, -1.028270, 0.160770, -0.513840, -0.354290, -0.825250, -0.548820, -0.500100, 0.427390,
-0.085170, 0.476500, 0.039930, 0.551040, -0.790750, 0.022150, -0.622110, 0.804460, 0.632590, 0.426960,
0.404250, -0.472490, -0.091550, -0.125680, 0.072910, -0.565450, -0.661060, 1.003630, -0.879980, 0.355490,
0.585680, -0.134960, -0.446180, 1.636500, 5.794780, -0.853800, -0.906680, -0.126920, 0.607000, -0.139340,
-0.442280, 0.373790, 0.144850, 1.144910, -0.858110, -0.560130, 1.159820, 0.096690, 0.324190,
-0.207540, 0.346200, 0.953010, 0.218880, -0.263930, -0.576130, -0.363120, -0.166470, 0.425100, -0.520950,
0.829820, 0.302550, 0.630880, -0.127740, 0.584730, -0.220050, 0.377480, 1.005110, -0.839580, 0.276910,
-0.490290, 0.995650, -0.653770, -0.889970, -0.528910, 0.053180, -0.106500, 0.377420, -0.567730, -0.360760,
0.119310, -0.567330, 0.204180, 0.975550, 0.412090, 0.227480, 0.368530, 0.287070, -0.240100, -0.567830,
0.903190, 0.472640, 0.541350, 0.414640, 0.747610, -0.713650, -0.627460, -0.613000, -0.498360, 0.065730,
0.274770, 0.800660, -0.140850, 0.071690, -0.491140, -0.024180, -0.511880, 4.208630, 0.709230, 0.043130,
-1.195130, -0.095290, -0.549640, 2.185840, 0.112100, -0.382450, -0.517740, 0.361270, 0.510910, -0.233620,
0.674470, -0.021260, 0.392360, 0.416380, -0.639580, 0.732080, 0.534280, -0.698010, 0.299830, 0.610640,
0.036620, 0.830730, 0.426790, 0.702220, 0.288360, 0.261670, 0.995980, 0.603280, 0.487660, 0.237430,
0.528240, 0.081810, 0.318390, 0.147440, 0.658800, -0.150180, -0.271640, 0.084670, 0.965680, 0.399410,
0.687290, 0.674980, 0.132530, -0.499350, 0.044550, -0.466480, -0.787650, -0.727760, 0.076210, -0.017990,
0.790390, 0.980490, 0.345480, -0.627840, -3.098760, -2.143270, -0.657690, 0.724430, -0.893680, -0.766240,
0.177620, -0.946660, 0.638950, -0.751560, -0.117320, -0.401580, 0.287970, -2.939200, -0.070740,
-0.037160, 0.230270, -0.240070, -0.003210, 0.682940, -0.882750, 0.853220, -0.215090, 0.395820, 0.082400,
0.304190, -0.359100, -0.367350, 0.805040, 0.601460, -0.164560, 0.350990, -0.286270, -0.295730, -0.627650,
0.732120, -1.017020, 0.918490, 0.197380, 0.739560, -0.372970, 0.278970, -0.172700, -0.714970, 0.039170,
-0.677910, -0.212060, -0.529110, -0.143620, -0.327060, -0.334520, -0.188620, -0.081440, -0.403380, -1.032340,
0.379910, -0.140020, 0.322630, -3.547500, -0.474490, -0.310840, -0.760550, -0.751290, -0.580180, -0.975000,
0.479710, 0.234390, -1.442760, -0.794810, -1.158050, 0.016940, 0.040650, 0.215180, -0.965090, -0.417370,
0.048250, -0.378570, 0.567390, 0.386150, 0.245960, 0.390750, 0.834460, -1.035690, 0.573020, 0.540310,
1.540680, 0.144180, 0.447450, -0.613770, -0.375300, -0.966910, 0.266220, -0.911310, 0.892620, 0.946920,
-0.203070, -0.582850, -0.671090, 0.898320, -0.000220, -0.642010, 0.946500, -0.746830, -0.154900, 0.500310,
0.792780, -0.666580, -0.654430, 0.491780, 0.664970, 0.708940, 0.819020, -0.558990, 0.775990, -0.796860,
-0.067280, -0.113460, -0.643330, 0.035790, -0.510150, -0.016580, 0.914160, 0.765890, 0.754430, 0.680440,
0.479710, -0.109930, -0.558140, 0.273620, -18.259800, 3.180210, -0.678030, -0.903530, -0.463380, 0.521090,
0.426490, 0.308700, 0.454960, 0.535050, 0.455930, -0.257910, -0.208910, 1.273320, 0.083250,
0.663690, -0.616760, 0.083020, -0.101510, -0.177540, -0.847830, -0.182540, 0.579920, 0.770960, -0.377440,
0.725750, 0.718010, -0.718920, 0.053560, 0.281210, 1.209630, -0.114840, -0.539410, 0.930500, 0.200720,
-0.990520, -1.065890, 0.349130, 0.094750, 0.242060, -0.211530, -0.064730, -0.822600, 0.506500, 0.828540,
-0.254420, 0.321280, -0.280130, 0.841140, -0.664680, -0.718300, 0.712020, -0.350280, -1.030720, 1.501400,
0.220010, -0.843150, -0.474380, 0.873950, -1.228850, 2.979460, -0.725020, 0.213780, -0.413000, -0.123440,
-0.753760, -0.196370, -0.436680, -0.536760, -0.196610, 0.345630, -0.987910, 1.107310, 0.654540, 0.511610,
-0.507550, -0.419550, 0.531340, -0.350480, 0.081180, 0.704420, -0.585320, 0.670510, -0.013190, -0.120160,
0.675980, -0.345170, 0.940470, -0.514410, -0.795740, -0.289570, -0.286020, -0.826590, -0.327760, 0.867290,
0.002550, 0.696480, 0.158860, 0.060310, -1.000630, 0.377440, 0.045360, 0.016230, -0.090240, -0.059490,
0.804120, 0.730290, 0.048100, -0.280490, 0.358510, 0.603380, 0.814550, -0.400820, 0.366010, -0.147590,
0.096150, 0.246340, 0.436640, -0.841070, 0.585890, 0.662720, 0.045280, -0.599620, -0.083120, -0.394650,
-0.600760, 0.599890, 0.702990, 1.311200, -11.599990, 0.034450, 0.956100, -0.274920, -0.077650, -0.588600,
-1.159440, 0.953830, -0.860420, 0.548220, 1.217160, -0.769120, 0.845760, -4.000170, 0.053770,
-0.374460, 0.366290, 0.567820, -0.927260, 0.007430, 0.465050, 1.378690, -0.628970, 0.782660, -0.527470,
-0.849590, 0.267150, -1.020580, 1.395360, 0.735510, 2.155160, -0.568690, 0.131570, -0.529160, 1.238920,
-1.020730, 0.840770, -0.268120, -0.306440, -0.626480, -0.682040, 0.070730, 0.677070, 0.596090, 0.437070,
0.506510, -0.325470, -0.985370, 0.180730, -0.852350, 0.374290, -0.958570, 0.789580, 0.022090, -1.448620,
0.236070, 0.936580, 2.687180, -7.287370, 0.068190, -3.411220, -1.065060, 1.285610, 0.822330, -0.939460,
-0.520890, 0.079060, -9.281820, -0.344620, -0.412070, -1.347910, 0.774380, 0.266650, -1.121170, -0.194020,
-0.654240, -4.768080, 0.395650, 0.736860, -1.170380, 0.767540, 0.402770, -0.202670, -1.018850, -0.997290,
0.259000, -0.694600, -0.404990, -0.310410, -0.455340, 0.197090, 0.280190, 0.552460, 0.578480, 0.849970,
0.202380, 0.169230, 0.302040, 0.439690, 0.115690, -1.634100, -0.448790, -0.453070, -0.474710, 0.359350,
-1.036120, -0.679680, -0.113090, 0.617120, -0.285890, -1.093400, -0.514550, -0.049580, -0.130760, -0.883900,
-0.180520, -0.915680, 0.453120, 0.044270, -0.117350, 0.690270, -0.917950, 1.087290, -0.456120, 0.428360,
0.472760, -0.367320, -0.256430, -2.618410, -13.234930, 1.833180, 0.449310, 0.268590, 1.890790, -0.900520,
-0.357120, -0.245910, -0.089240, 0.384650, 0.127610, 0.222220, -1.064870, -0.227670, 0.099730,
-1.100850, 0.123600, 1.852990, 0.317520, 0.138800, -0.420060, 0.456690, -0.574060, 0.211870, -0.031580,
0.670050, -1.002910, 0.503180, 0.116610, 0.381620, 0.265300, -0.677220, -0.568650, 0.289320, 0.709250,
0.307430, -0.453140, -0.951410, -0.985280, -1.002710, 1.609070, 0.485710, 0.305370, 0.248040, -0.253140,
-0.401260, 0.406280, 0.673600, 0.730190, 4.828430, -0.631870, 0.124500, 1.667210, 0.370260, -0.462970,
-7.095030, -0.509320, 0.108860, -0.460660, -0.113360, -0.646050, -7.487250, -0.487370, 0.513140, -0.275940,
1.247280, -0.427890, 0.839060, -2.821430, 0.027330, 0.225580, 1.561640, 0.134040, 0.165040, -0.803670,
-1.119380, 0.503350, 0.430430, 0.502530, 0.311510, 0.372790, -0.301150, 0.694490, -0.983770, 0.475630,
-0.517860, -1.012590, -1.175330, 0.738010, -0.752890, -1.310280, -0.567360, -0.701870, 0.163780, -0.054620,
-0.464800, -3.379990, -0.804650, 0.793640, -0.487700, 0.056310, -0.786190, 1.048180, 0.047500, 0.601010,
-2.695330, 0.822670, -0.334070, -0.306940, -0.616110, 0.712440, 0.177050, -0.228380, -0.588350, -0.472960,
0.627230, 0.317450, 0.244520, -0.002720, 0.084730, 0.381710, 0.118990, 1.835010, 0.599350, -1.068090,
-0.591960, 0.869060, -0.328650, 0.582610, 1.016240, -16.015221, -0.275670, -0.172590, 0.356590, 0.208850,
0.302100, 1.442640, 0.081500, -0.703440, -1.482400, -0.864620, 0.644320, -2.260250, -1.411380,
-0.163510, 0.176540, -0.897970, -0.540470, -0.698210, 0.017550, 0.603440, -0.043910, 0.917560, 0.176030,
-0.607160, -0.489550, 0.034240, 0.586710, 0.899540, -0.498760, -0.003060, -0.299820, -0.894010, 0.698800,
-0.809850, -0.616540, -0.711330, -0.508390, 0.836920, 0.612630, 0.562530, -0.589570, 0.147730, 0.510330,
-0.695190, -0.401950, 0.434090, -0.119680, 0.022790, 0.084100, -0.901460, -0.637730, 0.893640, 0.221320,
-0.077870, -0.674820, 0.388130, -0.432500, -0.820700, 0.097980, -0.701200, -0.528600, -0.398400, -0.798200,
-0.252440, -0.762690, 0.750180, -0.456070, 1.026230, -0.603690, -0.050840, -0.371890, 0.487670, -0.819390,
-0.110970, 0.984370, 0.644490, 0.744710, 0.500050, -1.336770, 0.337850, 0.170900, -1.263240, 0.400470,
6.803240, 0.258590, 0.212180, 0.410290, -3.132780, 0.612500, -0.335430, -1.572230, -0.195530, 0.094170,
-0.710810, -0.168720, -0.509590, -7.136920, 1.004150, -0.719010, -1.877780, -0.190240, 0.797410, -0.643840,
0.422120, -3.547190, -0.438220, 0.834760, -1.053990, -2.867120, 0.977580, -0.483160, -0.910190, 0.514920,
0.807190, -0.045850, -0.604310, -0.506520, -0.098650, 0.135960, -0.839670, -0.106590, 0.529130, 0.206690,
-0.127110, -1.057960, 0.018080, -0.325900, -16.321690, 0.101820, -0.820970, -0.874970, 0.821780, 0.645470,
-0.438060, -0.831320, -0.812910, -0.706630, 1.113980, 0.186140, 0.165200, 1.862940, -0.599430,
0.021920, -0.623080, -0.455840, -0.795500, 0.257980, 0.723380, -0.388520, -0.732980, -0.134230, 0.498450,
0.112220, -0.762560, 0.285330, -0.863560, 0.670430, 0.456250, 0.393400, -0.563490, -0.797840, -0.321790,
-0.887410, 0.347880, -0.279440, -0.061910, -0.993720, 0.333470, 0.406480, -0.536260, -0.686800, -0.892410,
0.293150, -1.335930, -0.344310, -0.397110, -0.125270, 0.504770, -0.243030, -0.656330, -0.141740, 0.599660,
-0.242520, -0.076990, 0.538920, -1.058350, 0.610910, -0.065010, -1.109320, 0.906960, -0.433730, 0.390300,
0.428280, -0.219990, -0.893820, 0.794340, 0.058770, 0.434610, 0.940110, -0.822060, -1.083390, -0.192540,
-0.221670, 0.663460, -0.518870, -0.597380, -0.310840, -0.499450, 0.747130, -1.016000, -0.502950, -0.273030,
-0.129670, 0.495780, 0.511390, -0.775570, 0.561160, -0.397240, 0.446760, -0.376560, -0.613650, -1.346520,
-0.086950, -0.186990, -0.311200, -0.330490, -0.735070, 0.043080, -0.077280, 0.823100, 0.180480, 0.049780,
-1.169260, -0.790500, -0.893800, 0.578850, -0.030130, 0.922010, 1.542770, 0.792320, -0.452410, 0.447900,
0.498380, 0.737660, 0.847990, -0.202800, 0.353440, 0.373570, -0.433960, -1.509270, -0.795090, -0.334430,
0.847090, -1.624160, -0.465210, 0.021160, -2.476260, -3.125640, 0.305980, 0.452650, 0.598660, 0.560400,
1.026840, 1.204810, 0.951240, 0.416830, 0.649740, 0.235790, -0.295080, -0.149100, 0.577070,
-0.355690, -0.928600, 0.046160, -0.701950, 0.417150, 0.844400, 0.351510, 0.772920, -0.199310, 1.281440,
-0.722650, 0.372790, 0.940800, 0.366960, -0.390610, -0.566680, 0.156960, -0.661730, 0.691980, 0.300620,
0.320330, 0.141210, -0.803870, -0.873200, -1.314790, 0.713340, -0.625170, -0.761670, -0.907460, -0.148620,
-0.600690, -0.749760, 0.121560, -0.455060, 0.457840, 0.556930, 2.936890, -0.280150, 0.713870, -0.825400,
0.861300, -0.409780, -0.170040, 1.325820, 0.815500, 0.683940, 0.137950, -0.546880, -0.449130, 0.454760,
0.369400, 0.251200, 0.035670, -0.083020, 0.130300, 0.586030, 0.323130, -0.039850, -0.641600, -0.563810,
-0.698410, 0.226710, -0.426850, -0.593970, 0.870800, -0.802780, -1.538160, -1.356850, -0.654360, 0.470210,
0.761260, 0.392020, -0.427920, -0.730920, 0.872650, -0.951440, 0.664840, -0.242760, 0.671190, 0.275600,
0.755380, -0.718130, 0.234240, -0.045610, -0.302130, 0.821950, 0.473210, 0.128500, 0.127410, 0.150680,
-0.243680, -0.866590, -0.108000, 0.020890, 0.021460, 0.506110, -1.410530, 0.827910, 0.244610, 0.485260,
-1.167740, 0.392610, -0.889210, -0.875560, 0.040620, 0.558940, 0.768930, 0.949210, 0.087910, -1.321570,
-0.776870, -0.122330, 0.721560, -30.192671, 4.360380, -20.180470, 0.951130, -0.812130, -0.321440, -0.029740,
-0.703770, -4.455960, 0.043060, 0.683640, 2.139810, 0.315030, -0.855430, -2.395880, 0.847870,
2.043470, 0.332630, -0.279070, -0.004540, -0.247490, 1.095990, -0.129780, 0.625530, -0.392910, -0.143670,
0.041220, -0.584440, -0.884540, 0.183930, -0.081420, 0.036330, 0.657090, 0.724090, 0.941990, 0.825490,
0.906230, -2.142160, -0.552840, 0.817460, -1.260780, 0.167190, 0.205560, 0.335530, 1.103430, 1.011220,
-0.630670, 1.089040, 0.186260, -2.390410, -0.316530, 0.514340, 0.921910, 0.950390, 0.690420, -0.192490,
0.513600, 0.136700, -1.066400, -0.555480, 0.800140, 0.899890, -0.316650, -0.012570, -3.092860, 0.081640,
-0.744300, -0.951930, 0.119960, 1.206070, -5.381130, 1.098740, 1.206410, -0.533740, -0.184390, -0.641810,
-0.496380, 0.128290, 0.802320, -0.253820, -0.264720, -0.123130, -0.506160, -0.915650, 0.850970, -0.476460,
-0.527580, -0.273410, -0.116260, -0.015540, -0.942050, -0.331340, -0.664560, 0.335620, 1.074340, 0.612190,
0.739880, -0.991500, -0.491930, -0.419760, 0.057550, 0.849470, -0.288230, 0.925920, -0.336420, -0.208660,
-0.585690, 0.189010, 0.388180, 0.596620, 0.081790, 0.400620, -0.773210, 0.383710, -0.790270, -0.927950,
-0.181940, -0.041850, -0.688890, 0.150380, -0.930200, 0.190650, -0.047350, 2.063160, -0.594600, -0.562340,
-0.340560, -0.513060, -0.428110, 1.618120, -0.886910, -1.343640, -0.165280, -0.356060, 0.154580, -0.724400,
-0.026650, 0.289170, 0.457470, -0.778370, -0.494370, 0.918470, -0.925410, 5.336680, 0.422130,
0.071450, 0.214170, 0.960900, 0.599500, 1.163260, -0.404950, -0.451900, 0.997920, -0.102800, -0.613600,
-0.577720, -0.097090, 0.371410, -0.179810, 0.896580, -0.960660, 1.047620, 0.193820, 0.656480, 0.021240,
0.236470, 0.107480, 0.449820, -0.518520, -0.988490, 0.795420, -0.427610, 0.079600, -2.275450, -0.455190,
0.335330, 0.502260, 0.386050, -0.743230, -0.566090, 0.930480, -0.204080, 0.418200, 0.333280, 0.201620,
1.311880, 0.553490, -0.242130, -0.712320, 0.370070, 0.507310, 0.397380, 2.050660, -0.590410, 0.081350,
-3.441750, -0.080740, -2.111440, -1.231840, 0.121160, 2.473760, 0.553820, -1.061000, -0.077980, -0.884440,
0.396170, -1.112900, -0.533600, -0.589750, 0.561820, 0.190780, -0.136580, 0.654910, -0.414730, -0.216190,
-3.324220, -0.232230, -1.297180, -0.088290, 0.046000, 0.050670, 0.810200, -0.159620, 0.250860, -1.681030,
0.237930, -0.051920, 1.130000, 0.305840, -0.615390, 0.900640, -0.259490, 0.508400, -0.381860, -0.386180,
-1.165410, 0.794680, -0.259900, 0.691630, -0.776920, 0.185960, -0.946960, 0.412840, 0.596710, 0.485320,
-0.352160, -0.303030, 1.048410, -0.689990, -0.542730, 0.213560, 1.429020, -0.269430, 0.532900, -0.755720,
-0.313590, -0.159700, 0.328430, 1.491460, 36.033630, 0.089270, 0.191000, -0.148430, 1.066170, -0.598820,
1.340960, 0.072040, 0.677200, 1.102720, -0.846280, 0.896650, 1.186390, -0.260160, 1.534410,
0.814510, -0.172210, -0.541970, -0.549210, 0.560640, 0.248250, 0.215980, 0.196330, 0.373750, 0.987240,
-0.946900, 0.188190, 0.751900, -0.380610, 0.292690, -0.541530, 0.966010, -0.570090, -0.556210, 0.027260,
0.096600, 0.412880, -0.006810, 0.311060, 0.495880, -0.113030, -0.456310, -0.346800, -1.771880, -0.807280,
0.527140, -0.002940, 0.290230, -0.212700, 0.792280, 0.619050, 0.092150, 0.939480, -0.294120, 0.452890,
0.791740, 0.201110, -1.340500, -0.295910, -0.084240, -1.105690, 0.626350, -0.939510, -0.428120, -0.393940,
0.558060, 2.113900, 0.482420, 0.494240, -3.076610, 0.197810, 1.265490, -0.427710, -0.968740, 0.528000,
0.350470, -1.009840, 0.734570, 0.226660, 0.299120, 0.891610, 0.704870, -0.995510, -0.084120, 0.337050,
-1.037930, -1.032040, -0.437100, -0.242410, 0.551470, 0.208300, 0.307390, 0.705680, 0.852330, -0.015050,
0.084190, 0.354740, -0.273020, 0.697920, -0.804040, 0.624240, -0.480780, 0.822540, -0.515390, -0.391410,
-0.092030, 0.167620, -0.506610, 0.418820, -0.976880, -0.811980, 0.317600, 0.571930, -0.536150, -0.463390,
-0.029230, 0.666820, -0.399250, 0.284160, -0.238180, -0.024000, 0.276460, 1.902580, -0.305490, -0.220720,
0.606440, -0.171190, -0.790070, -0.833690, 2.371570, 1.461220, -0.495800, -0.372050, 0.035110, -1.138190,
-0.450640, -0.944200, 0.634970, -0.356050, -0.512180, 0.674260, -0.691930, 0.988160, 0.089490,
0.726490, -0.124560, 0.383940, 0.598980, 1.016460, 0.417130, 0.882050, -0.346480, -1.146940, -0.137570,
-0.149790, -0.051470, 0.049610, 1.175210, 0.419760, -0.454160, -1.345560, 0.297060, -0.044310, 0.281350,
-0.078570, 1.231650, 0.905610, 0.119700, -0.230630, -4.220430, -0.607300, -0.082000, 0.412440, 0.219260,
-0.479370, -1.214600, -0.480450, -0.110590, -4.999030, 0.292290, 0.954740, 0.702990, 0.782640, -0.099890,
-1.157920, 1.032190, 0.795990, -1.043650, -0.401680, 0.250090, -2.722860, -0.205590, -0.539040, -2.793160,
-0.389230, 0.694640, -0.994940, 1.251860, 1.717710, -6.313730, -0.523840, 0.105030, -0.289450, 0.793250,
-1.351740, 0.875760, 0.032240, 0.009390, -3.857970, 0.373480, -0.135230, -0.845320, 0.573740, -0.127730,
0.102270, 0.589210, -0.389050, -1.042200, -0.376620, -0.357180, 0.138020, -0.410030, 0.748310, 1.098830,
-0.466400, 1.136610, -0.267960, 0.266620, 0.421420, -0.901780, 0.288200, -0.750750, 0.844340, -1.099660,
-0.097740, -0.387760, -0.402700, -0.117310, -0.139720, 0.628280, 0.926380, 0.538410, 0.384450, -0.686380,
-0.260760, -0.303450, -0.751420, 0.746640, 0.251020, -0.083790, -0.708120, 5.153160, 0.728670, -0.679000,
0.042360, 0.118450, -0.311220, 0.877430, 10.477830, 0.911440, -1.085860, -4.479560, -1.497460, -1.164870,
-0.646190, 0.023110, 0.640850, 0.542460, -1.355030, 0.076570, -0.735540, 0.301690, -0.465070,
-0.640520, 0.164120, -0.093880, -0.217620, -1.534280, 0.017500, 0.692230, -0.504870, -0.627860, -0.047390,
-0.293060, -1.318100, -0.539900, -1.127000, 0.262500, -0.229720, 1.437570, 1.175380, 0.052420, 0.207950,
-0.083100, 0.149160, -0.328150, 0.528710, -0.845460, -1.333580, -0.425890, 0.617970, 0.120000, 0.107370,
-0.135210, -0.800820, 0.499710, -0.957310, -3.639730, 0.777770, 0.168340, -1.110940, -0.459330, -0.853870,
-0.210580, -0.018230, -1.112350, -0.437320, -0.647190, -0.693250, -0.964730, 0.733880, 0.253960, -0.308800,
0.456410, -0.163770, -0.644040, 0.448840, -1.245970, 0.315420, 0.456130, -0.008780, -1.439480, 0.530440,
1.652600, 0.384170, 0.645420, -1.799780, 0.705400, 0.479430, 0.081220, -0.888490, 0.266450, 0.752700,
0.604470, 0.208970, -0.987860, 0.238290, 0.482740, 0.889280, 0.979550, -1.334430, 1.068280, -0.924710,
-0.753550, -1.286280, 0.256410, 0.331340, 0.201010, 0.519430, 0.201670, 0.614510, -0.075330, -0.126300,
-1.850250, 0.673310, 0.108210, -0.049310, -1.123080, -0.554630, -0.462010, 0.655570, 0.786670, 0.473640,
-0.411330, 0.388840, -0.081410, -0.100290, -0.591790, -0.542200, -0.583070, 0.287600, 0.307700, 0.649950,
0.456330, 0.618980, 0.120170, 1.054470, 3.422030, -0.364850, 0.323380, 0.004480, 0.974100, -0.059760,
-0.284410, 0.145740, -0.639540, -0.002390, 1.119400, -0.181700, 0.528170, -0.111410, 0.847890,
-0.005600, 0.264840, 0.020130, -0.001090, 0.304920, -0.157560, 0.015940, 0.862760, 0.434750, 0.054710,
-0.805060, 0.831130, -0.293700, 1.046330, -0.913720, -0.854870, 0.073740, 0.521120, -0.193750, -0.591110,
0.013300, -0.496930, -0.037750, 1.185560, -0.526640, -0.662680, 2.258310, -0.510420, -0.718250, -1.440300,
0.550570, -0.884460, 0.019540, -1.023370, -0.733870, 0.726780, -0.480660, -1.690540, -0.313030, -0.318980,
0.820000, -4.871290, 0.004750, 0.486950, 1.898900, -0.252860, -1.076020, -1.478320, -1.019440, -1.657080,
-0.106650, -0.524590, -0.875480, 0.462390, -1.223350, 0.539580, 1.420140, -0.464040, 0.005250, -0.057550,
1.942510, -0.180120, 0.421730, -1.418410, 0.650130, -0.375180, 0.862030, 0.345870, 0.132900, 0.923680,
-1.112490, -0.385780, 0.430410, 0.903200, 0.168850, 0.544570, 0.478130, 0.697820, 1.202560, -1.890920,
0.428340, -1.170720, 1.446730, 0.212130, -0.224710, 1.681420, 0.567460, 0.744910, -1.420160, 0.074190,
0.186620, 0.560100, -0.642440, 0.133520, 2.784650, 1.109800, -0.488140, -1.567990, -0.364970, -0.731940,
0.468840, 1.013750, -1.041160, 0.898700, 0.590420, -0.498400, -1.109050, -0.541710, -0.234740, -0.340470,
0.850210, 0.792410, 0.105970, -0.581200, 158.949829, -2.100210, 0.210450, 0.569890, 3.560580, 0.440800,
0.873720, 1.297920, -0.352450, -0.413720, -1.103580, 1.392640, -0.588470, -0.140650, 0.008460,
0.268390, -0.125590, -0.339890, 0.553610, 1.264220, -0.048690, 0.833830, -0.136760, -0.514690, 0.378020,
-2.983110, 0.426320, -0.079740, 0.288310, -0.476600, -1.030240, 0.411840, -1.082070, -0.535640, 0.669210,
0.662540, -0.231990, -0.042710, -0.735820, 0.188490, -0.309330, -2.784090, 0.064580, -0.184660, 4.779980,
1.206100, -0.387210, -0.657830, -0.233770, -0.512150, -0.724370, 0.183430, -0.021930, -1.185450, 0.932360,
0.594520, -0.784170, -0.451030, 1.041960, -2.355160, 0.819800, 0.636850, 2.570340, -0.938910, 0.553710,
-0.432830, -1.054220, -0.832270, 0.566340, -0.811840, 0.543790, 0.023820, 0.118110, -0.562240, -1.096530,
-0.431410, 0.244420, -0.151940, 0.297660, 0.296050, -0.411580, 0.532350, 0.185900, -1.102040, 0.750800,
-1.172160, 0.714180, 0.719440, -1.053070, -0.054460, -0.123610, -0.930120, -0.694800, -0.008350, -0.684870,
0.248670, 0.065620, 0.225490, 0.322290, -0.801090, -2.377060, -0.711270, -1.301620, 3.450380, 0.651290,
2.464700, -3.310280, 0.584430, -0.847500, -1.295070, -0.648340, -1.591580, 0.526240, -0.736530, -0.407720,
-1.344590, -0.220440, -0.158220, -0.133600, -0.041250, 0.852770, -0.879860, 1.272190, -0.521520, 0.483590,
-0.448630, 0.858680, -0.512900, 0.696980, 5.704000, -0.381470, -0.230830, 0.550070, 1.159650, -0.434240,
-1.276480, -1.024170, -2.959280, 0.476750, 0.791400, 0.226670, -0.131110, 2.105520, 0.673120,
0.280190, 3.749330, -0.081630, -0.707670, -0.615780, 1.135120, 0.648200, -0.032060, 0.488740, -0.237450,
-0.423740, -0.084200, 1.093090, 0.776960, -0.422930, -0.567210, 0.851270, 0.135950, 0.092430, -0.453940,
1.172250, -0.026620, 0.358890, -0.581240, -0.294450, 0.541700, -0.715190, 1.302560, 0.077470, 0.922740,
-0.448530, 0.614250, 0.839860, 1.548940, 0.806570, 0.439740, 1.257330, 0.590390, 0.628100, 1.000180,
1.002710, -0.816320, 0.820410, -0.483690, -1.212050, 3.288570, 0.595850, -0.790160, 1.415260, -0.148360,
-0.243690, 0.275110, 0.393500, -0.902710, 5.722820, -0.623040, 0.091690, -0.771060, -0.372650, -0.948560,
-0.044680, -0.625070, 0.304900, 0.027340, -0.432190, -0.599880, 0.903280, -0.345310, 0.672120, 0.671090,
-0.253480, -0.571570, 0.414830, -0.624120, 0.576030, -1.874820, 0.015230, -0.552270, 0.286830, 0.533820,
0.132220, 3.268290, 0.144150, 0.916520, -2.025880, -0.844460, -0.582770, -0.353460, 0.129390, 0.042880,
0.110300, 0.913470, 0.177620, 0.505950, -0.242720, 1.067220, 0.580970, 0.875530, 0.662050, -0.281320,
-0.237930, 1.048090, 0.521280, -0.588670, 0.266040, -0.273810, 0.794180, 0.081410, 0.944750, -0.545880,
-0.633730, -0.165150, 0.640340, -0.665730, -1.693090, -0.642790, 0.456700, 0.711020, 0.260470, -0.917510,
-0.750460, -1.738010, -0.062030, 0.213370, 14.008960, -1.038300, 0.666960, -14.421910, -1.116910,
-0.665520, -0.435750, 0.385780, 0.255030, 0.591760, -0.007800, -0.372280, -0.811160, 0.612140, 0.902010,
-0.206120, -0.573320, -0.024150, 0.607850, 0.130550, 0.361960, -0.649320, 0.066950, 0.438780, 0.992580,
0.824930, -0.685650, -0.442350, 0.594630, 1.003240, 0.029280, 0.211400, -1.048220, -0.488800, -0.904870,
-0.107950, 0.561830, -0.942750, -0.396160, 0.420070, -0.507860, 0.109290, 0.080590, -0.971320, 1.618630,
-0.946300, 0.215470, -2.932640, 0.055940, -0.946450, 5.627830, -1.359960, 0.447570, 0.352350, 0.882390,
-0.523120, -1.935950, -0.170700, 1.387040, 0.684000, -0.977110, -0.711670, 0.288710, -1.081720, 1.029460,
-0.017080, -0.964240, -0.026360, 0.436700, 0.191090, -0.285730, -0.003920, -0.632090, 1.081930, 1.108520,
-0.076150, 0.731000, -0.093720, -0.568170, -0.369950, -0.427570, -0.097770, -0.206760, -0.745950, -1.248790,
-0.483260, 0.541730, 0.497870, 0.273940, 0.125720, -0.065140, -0.155030, 0.086110, 0.161390, 0.592690,
-0.907400, -1.079980, 0.944900, 0.083300, 0.054940, -0.504510, -0.387500, -0.012990, 0.400740, -0.025500,
-0.387100, -0.313710, 0.555180, -0.575120, 0.272750, 0.691540, -0.360350, 0.574340, 0.493860, -0.391030,
0.718870, -0.397030, 0.773140, 2.559860, -0.250030, 2.252330, 0.538820, -0.581880, -0.446740, 0.254950,
-1.270600, 0.385020, -0.595050, -0.579480, 0.722460, -0.584880, -0.669470, -5.829580, -0.662830,
-0.730130, 0.331780, -0.606740, 0.672130, 0.063720, 0.536430, -1.042330, -0.083840, -0.163600, 0.797190,
0.586300, 0.832220, 0.125570, 0.791990, 0.731530, -0.061960, -0.234270, 0.554060, -0.678450, 1.260130,
1.165960, 0.361960, -0.479000, 0.041480, -0.573940, -0.863590, -0.024050, 0.908450, 1.327790, -0.472430,
-0.276930, 0.695930, -0.186650, 0.793330, 1.189170, -0.010080, -0.599230, -0.899880, -1.043990, -0.143710,
0.125540, -0.598670, -0.136550, 0.322550, -1.976960, 0.736490, -0.885720, -0.527960, 0.566510, 0.281830,
-1.405970, 0.445780, 1.455720, -2.269950, -0.503590, -0.693480, -3.521190, 0.056000, -6.513100, -0.187220,
0.535970, -1.531970, -1.453930, 1.216040, -1.880770, -3.003840, 0.231640, -0.526950, -0.483340, 0.462430,
-1.049990, 0.470460, 1.047430, -0.584750, 0.522680, -0.694430, 0.533410, 0.027670, -0.088720, -7.272780,
0.592400, -0.215180, -0.740720, 0.602090, -0.605940, -6.212240, -0.674790, 0.349600, -0.062130, -0.193220,
0.200980, -0.884090, 0.638310, -0.864390, -3.660990, 0.668090, -1.490380, 1.815320, -0.904880, -0.343170,
-0.397920, 0.733150, -0.747570, 0.301980, 1.198390, -0.181060, 0.860440, 3.042960, -0.379140, -0.262250,
0.866680, 0.183200, -0.494650, 1.416780, 10.731420, 0.130110, -0.487750, 0.977710, 0.767830, -0.704250,
-1.176130, 0.529890, 0.386610, -1.160670, -0.646780, -0.025670, 0.491300, -0.206040, -2.009480,
-0.101390, 0.329670, -0.144050, -1.023620, 0.608360, 0.896990, 0.113380, -0.181000, 0.359040, 0.328560,
0.061410, 0.760150, -0.471760, -0.383240, 0.924410, -0.410440, 0.085780, -0.771400, -0.365790, -0.327240,
0.694280, -1.025950, -0.150630, -0.964550, -0.241710, -0.652300, 0.829680, -1.030900, 0.382520, -0.134990,
0.538260, -0.400320, 0.409160, -0.179070, 0.053890, 0.620870, 0.439690, -1.341310, -0.357470, 0.715260,
-0.231120, 0.309240, -0.774140, 2.614080, 0.474790, 0.121050, -4.011340, -0.403340, -0.923850, 0.815220,
-0.751340, -0.930480, 0.853070, -0.945010, 0.079060, 0.555510, -0.152310, -1.181160, -0.031070, 0.262850,
-0.185560, -0.134830, 0.108760, -1.043650, -0.711810, -0.445980, 0.081350, -0.789040, -0.563910, -0.390390,
0.698940, 0.297530, -0.694320, 0.810960, -0.638660, -0.960180, -0.134450, -0.274880, 3.010110, -0.333120,
0.132830, 0.146910, 0.716390, -0.435470, -0.279430, -0.887300, -0.637960, 0.854340, 0.719790, 0.684170,
-1.630490, 0.260970, -0.463820, -1.631080, -0.755480, 0.723930, -2.350800, 0.064560, 0.678780, 0.888610,
-0.617870, -0.108230, 0.799890, 0.564560, -0.585360, -0.404650, -0.136590, 1.816070, -0.336920, 0.616110,
0.659270, -0.260500, -0.068470, -5.101200, 0.188080, -1.430760, -0.191950, -0.259810, 1.047110, -0.178520,
1.048120, -2.111780, -0.315330, 0.764130, 0.744380, -0.696190, 0.620880, -0.532190, 0.000060,
-0.552940, -0.721400, 0.639010, 0.861600, -0.198910, 0.194300, -0.418800, 0.111410, -1.882600, 0.147480,
-0.042380, -0.780560, 0.157650, 0.973550, -1.887980, -3.559950, 0.500080, -0.073930, -0.670470, -3.048940,
-0.971020, -0.641090, -0.024330, -0.236900, -0.657870, 0.504210, 1.262830, 0.571270, 1.268190, -0.167230,

-0.835600, 0.636580, 0.154560, -1.080250, 0.808030, -0.832780, -0.520640, 0.059200, 0.037940, -0.868750,
0.047930, -0.230860, -0.117590, 0.042120, -2.306670, -2.269030, -1.797880, -0.661140, 0.683060, -0.097330,
-0.209650, 0.531150, -3.822600, -0.864200, 0.222850, 0.348370, 0.817070, -0.670630, -4.043610, 0.321750,

0.743600, 0.426340, -0.988990, 0.510610, 0.499730, -0.001720, -0.005900, -0.381240, 0.140740, -0.065110,
-0.168250, -0.563830, 0.051330, -0.972320, 1.560910, 3.090480, -0.408810, 0.268130, -0.279800, -0.282540,
-0.191950, 0.057060, -0.046060, 1.017590, 0.834210, -1.054120, -0.876550, -0.471020, -0.784940, 0.420890,

-0.972370, -0.101110, -0.248320, 0.194390, 0.383140, -0.906720, 0.246950, -0.756970, -1.732530, 0.107630,
-0.890010, 0.314580, 0.258870, 0.120950, 0.795440, -5.973570, 0.873530, 0.150780, -0.787080, -1.929460,
0.647100, -1.357750, 0.773930, -0.725650, -1.131360, 0.672950, 0.300030, 0.104780, 1.526720, -0.352810,

0.069730, -0.374030, 0.745540, -0.741840, -0.280420, -0.698500, 0.310180, 0.711900, 1.011780, 0.410050,
0.188410, -0.913470, -0.749680, 0.014360, -3.417250, -1.936220, -1.418060, -0.448500, 0.284740, -0.367100,
0.444290, 0.021980, -2.531910, -0.549520, 0.611720, 0.577370, -0.121030, 0.104320, -1.841230, 0.645400,

0.019720, 0.658180, -0.545660, 0.415730, -0.381140, 0.864640, -0.829980, 0.672160, -0.818350, -0.738200,
0.043910, 1.150950, 0.443820, -0.154660, -0.665760, 2.495470, -0.721220, 0.866620, -0.516480, 0.330560,
0.360670, 0.918600, -0.467360, 0.176450, 0.194730, -0.872820, -1.108910, -0.202090, -0.920140, 0.044310,

0.591470, -1.014100, -0.540100, 0.105420, 1.114610, -0.372910, -0.037670, -0.860150, -1.999340, -0.817400,
0.368000, 0.800420, 0.478860, 0.836750, 0.359680, -8.673260, 1.047680, 0.381930, -0.879320, -0.829710,
-0.360360, -0.679730, 0.485770, -0.805980, -1.015360, 0.915030, 0.282610, -0.765610, 1.323790, -0.662350,

0.419260, -0.745180, 0.064620, -0.184250, -0.461750, -1.082730, 0.533200, 1.011080, 1.511530, -0.457210,
0.075400, 0.179930, -0.802380, -0.268460, -5.603380, 1.322550, -2.320040, -0.170940, 0.448940, 0.435500,
0.515470, -0.785940, -2.052170, 0.154580, -0.371800, 0.623150, 0.149190, -0.105510, -1.232100, 0.609770,

0.307780, 1.062410, 0.678280, -0.521760, 0.059310, 0.534100, -0.434750, 0.645180, -1.223440, 0.148200,
-0.683390, -0.600470, 0.200150, -0.086170, -0.303970, -0.496310, -1.223490, 0.304540, -0.639310, 0.065680,
-0.058340, 0.828650, 0.290960, 0.756160, 0.474220, -0.728020, -0.460520, 0.517440, -1.428330, -0.368480,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.739040, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, -0.396320, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.012580, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, -0.114660, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.368830, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.042810, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.882810, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.476930, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.210770, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.905500, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, 0.672630, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.450980, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.514040, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, 0.123000, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, 0.351010, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.040340, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, -0.408530, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, 0.695440, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, -0.363090, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, -0.984900, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.108510, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.081050, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, -0.075780, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, 0.027080, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.850440, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.560380, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, 0.220770, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, 0.884080, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.290610, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.237370, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.270960, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, 0.725600, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, -0.293710, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.462730, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.901820, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.686840, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, -0.195010, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.824870, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.839450, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
0.09287, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
0.50309, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
0.28289, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.42851, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
1.21973, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.00003, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
1.28421, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.00126, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.00000, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
1.31441, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
1.31663, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
1.42244, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
1.23819, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
1.42607, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
0.15584, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
0.00000, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
0.44176, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.19417, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
0.00000, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.00000, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
0.22687, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.34410, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.36858, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.03832, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
0.54785, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
0.56436, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
1.42857, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
1.39874, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
0.43777, 0.500000, 2,
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
