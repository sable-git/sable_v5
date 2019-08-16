/*********************************************************
  TMPtmp6_0_0.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:26:41 2004
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
-0.369660, -0.888420, -0.218880, 0.763110, 0.463530, 0.893310, 0.788270, -0.021060, -0.072690, -0.095210,
0.842320, 0.383760, 0.651650, 0.194760, -0.584850, 0.300580, 0.013190, 0.200290, -0.600490, 1.052360,
0.776960, 0.626690, 0.270260, 0.737520, 0.273700, 0.297740, 0.108420, 0.393790, -0.014280, 0.242040,
0.471370, -0.515870, -0.757590, 0.832440, 0.324560, -1.059530, -0.997090, 0.989300, -0.039990, 0.871320,
-0.002360, -0.070480, -0.373790, -0.252810, 0.418860, -0.025030, 1.135730, -1.278320, -1.088670, 0.497040,
-0.903030, -0.812790, -0.589270, 0.668860, 0.217600, 0.102580, -1.135530, 0.543820, -0.909750, -0.711890,
0.467980, 0.214540, -0.459240, 0.632770, 0.075800, -0.280230, 1.088610, 0.464830, 0.820210, -0.595520,
1.002290, -0.472760, 0.613130, -0.506940, 0.249330, -0.678120, 0.169090, 0.400470, 0.077470, 0.591520,
0.654570, -0.354870, -0.334170, -0.186980, 0.291800, 0.453800, -0.297270, -0.123510, 0.314380, -0.058610,
-0.257180, -0.111990, -0.439270, 0.337170, -0.434420, -0.924640, -0.612580, -0.633620, -0.407110, 0.452990,
0.816350, 1.297950, -0.218170, 0.416500, -2.639460, 0.287080, -0.412580, 0.569270, 4.930110, -0.810570,
0.699270, 1.619790, -3.442890, 0.520620, 0.760790, 0.446990, -0.335560, 0.723250, -0.331460, -0.304690,
-0.376760, -0.738160, 0.093910, 0.675170, -1.222770, -0.754100, 0.427280, -0.911130, 0.799570,
0.233740, 0.505020, 0.517690, 1.115890, 0.730460, 0.121450, -0.276040, -0.179050, 0.533000, -0.119310,
-0.849110, -0.622900, -0.321610, -0.448870, -0.583290, 0.531820, 1.019180, 0.363290, 0.055310, -0.669170,
0.570030, -0.391850, -0.017500, -0.511400, 0.769870, 0.204540, -0.274010, -0.705410, -0.568220, 0.477000,
-0.260350, 0.403350, -0.503520, 0.025140, 0.657260, -0.825120, -0.379320, -1.150480, 0.364460, 0.392000,
0.973540, -0.497770, 0.247810, -0.170630, 0.985590, 0.629820, -0.531390, -0.861200, 0.285290, 0.755900,
0.144740, -0.706340, -0.800850, 0.773290, -0.221390, 1.033020, -0.788070, -0.280970, -0.383820, 0.048730,
-0.382780, -0.079780, 0.492040, -0.108810, 0.880260, 0.454130, 0.265980, -0.458130, 0.108520, -0.333260,
-0.201550, 0.450720, 0.530380, 1.217820, 0.672120, 1.108840, -0.308670, -0.902910, -1.462350, 0.865240,
0.784940, -0.004790, -0.347580, 0.749250, 0.755930, 0.969950, 0.480010, -0.135180, -0.700970, -0.908670,
-0.596940, 0.005570, 0.891590, 0.964990, -0.703080, -0.850910, -0.014260, -0.519260, -0.159260, 0.706420,
-0.550200, -0.012810, 1.007880, -0.488230, -0.304900, -0.845390, -0.057060, 0.119000, -0.060650, -0.244460,
2.514070, 0.127800, -1.122560, 1.031800, -0.664510, 3.328450, -0.366890, -0.269830, 0.499170, 0.979090,
-0.221380, -0.448390, 0.401280, 0.442930, -0.541890, -0.547910, -0.967260, 0.330810, -0.681140,
1.511530, -0.188640, 0.361220, 1.049430, -0.272670, 0.299250, -0.088870, 0.324670, -0.066950, 1.483150,
1.739550, -0.199400, 0.354170, 1.549130, 0.395560, -2.031400, -0.851320, 0.029920, 1.359250, 0.628430,
0.001840, -0.038280, -0.154910, 0.247280, -0.127670, -2.258610, -0.961050, -0.652950, 1.007920, 0.303650,
0.058980, 6.317360, -0.111900, -1.592600, -6.263030, 0.784280, -0.112060, -5.447900, -0.516280, -4.183690,
-0.917590, 0.447530, 0.734740, -0.114050, -0.774650, -2.959050, -2.982790, -0.874680, 1.351940, 0.985440,
-0.002160, -0.908170, 0.673230, 1.898650, 1.709390, -0.527260, -0.242400, -0.114100, 0.286800, -0.776760,
0.294290, -0.531540, 0.118710, -0.804770, 0.945620, 0.488560, -0.299640, -0.337250, 0.375780, 0.876180,
-0.807540, -1.243920, 0.321870, -0.045000, -0.934770, 0.619450, 0.879180, -1.034230, -0.644500, 0.397650,
-0.716850, -0.101900, -0.947680, 0.236670, -0.702320, 0.423190, 0.138710, 0.616640, 0.589720, -0.362370,
0.169950, -0.676160, 0.574450, -0.082550, -0.058910, -0.032970, -0.762900, -0.531610, -0.599880, -2.081620,
-0.036480, -0.567090, -0.278590, -0.546230, 1.174210, -0.719880, -0.609650, 5.754370, 0.045540, 0.141640,
-0.469600, 3.039570, 2.952170, 0.059350, -0.715820, -0.506580, -0.329850, 0.145870, 0.725930, -1.340000,
0.304190, 0.595290, 0.501200, -0.295420, 0.811000, 2.411080, 0.318780, 0.136850, -2.554430,
0.598090, 0.717790, -0.918170, -0.973270, -0.720140, -0.200720, 0.251560, 0.861140, 0.940090, 0.656270,
-0.939930, 0.225940, -0.657700, 0.383220, 0.307000, 0.406910, 0.135400, 0.465670, -0.030540, 0.165930,
-0.766790, 0.110330, -0.650990, 0.675620, 0.294550, 0.518080, -0.877260, -0.893400, -0.306480, 0.569120,
0.412260, 0.012740, 0.216190, -0.637680, 1.022740, -0.422980, 0.562380, -0.612050, -0.720700, 1.193010,
0.410770, -0.078640, -0.169590, 0.953510, 0.733370, 0.623690, 0.238620, 0.264960, 1.019080, 0.802400,
-0.031590, 0.559290, 0.221970, 0.827720, -0.355600, 0.008260, -0.410460, -0.758750, -0.009410, 0.099810,
1.556160, 0.023340, 0.964820, -0.546840, -0.504610, 0.167980, 0.369350, 0.849660, -0.106380, -0.152980,
0.524490, -0.300880, -0.220990, -0.211220, -0.517820, 0.479190, 0.318790, 0.603860, -0.221500, -0.167760,
-0.643620, 0.806890, 0.445440, 0.277060, 0.396020, 0.342440, 0.425900, 0.542250, -0.705680, -0.557120,
0.173690, 0.205060, -0.279320, -0.513560, 0.808810, 0.165160, -0.112870, -0.456540, -0.613270, 0.038110,
0.159010, 0.372690, -0.391810, -0.853970, -0.613990, 0.927940, -0.779180, 0.658110, 0.737800, 0.873680,
0.720820, -0.097180, -0.625370, -0.598630, -0.817270, 0.899890, -1.061860, -0.995440, -0.154180, -0.624560,
0.568370, 0.062790, -1.170900, -0.221060, -0.139350, -0.450020, 0.795080, 0.337380, 1.148550,
-0.162780, 0.800460, 0.799000, -0.122530, -0.615090, 0.329030, -0.545860, -0.397310, 0.340690, -0.090160,
-0.565010, -1.412970, -0.900160, 0.057710, -0.571550, 0.430890, -0.107440, 0.377730, -0.357330, 0.081240,
-0.564450, -0.639600, -0.276180, -0.817190, -0.627130, 0.150610, 0.212690, 0.650030, 0.063560, 0.271700,
-0.240280, 0.596310, 0.932960, -1.340230, -0.258910, 0.230280, 1.271050, 0.545500, 0.091570, -0.147370,
-0.598500, 1.309740, -0.132720, -0.761130, 0.050050, -0.936930, 2.358960, -0.373430, 0.133770, -0.522820,
0.968890, 0.217200, 0.274280, 1.236990, 0.222770, -0.009260, -0.139030, 0.128470, -0.503880, -0.311900,
1.058430, -0.817400, 0.578280, 0.538940, -0.060210, -0.430960, -0.199910, -0.666450, 1.052180, 0.116790,
-0.122270, 0.905920, 0.576670, 0.904780, 0.268120, 0.333840, 0.501540, 0.552670, 0.654800, -0.095340,
0.281380, -0.310850, 0.349420, -0.293370, 0.067510, 0.732460, 0.621270, 1.233880, 0.374650, 0.627240,
-1.148750, 0.339140, 0.018280, -0.789600, -0.132340, -0.951430, 0.027330, -0.430840, -0.307080, 0.671330,
0.525100, 1.156890, 0.986440, -0.858060, -0.571410, 0.612190, -0.224180, -2.838020, 3.980340, 0.749960,
0.195190, -0.183900, -0.231200, -0.781220, -0.082140, 0.095690, 0.754920, -0.787370, 0.344410, 0.016560,
0.511920, 0.379340, 0.901730, 0.373430, -0.918590, -0.189940, -0.916980, -0.295250, -0.987600,
0.368640, 0.740740, 1.018970, 0.810280, 0.414440, 0.057870, -0.174040, -0.028190, 0.814630, 0.236270,
0.654240, 0.323550, 0.236530, -0.024580, 0.340810, -0.059670, 0.828540, -0.375020, 1.652340, 0.906630,
0.841870, -0.821010, 0.913190, 0.934530, -0.511700, -0.011090, -0.864070, 1.681160, 0.848250, 0.984050,
-0.510710, -0.950580, -0.735750, -2.911360, -0.240000, -0.185740, 0.176090, 0.581880, -0.662250, -1.593790,
-1.166310, -0.139260, -3.469780, -1.490250, 0.641130, -2.163700, 0.726360, -0.892770, -2.943860, 0.184780,
0.373790, 1.722890, 0.461550, 0.943530, -7.243860, -0.458140, -0.701690, -0.579140, 0.178030, 0.946000,
0.707220, 0.653120, 0.990750, 0.088080, -0.645250, -0.150170, -0.282210, 0.373290, -0.785200, -0.821190,
-0.627190, -0.174590, 0.407090, -0.895480, -0.381180, -0.605360, 0.634580, -0.531650, -0.602640, -0.525650,
-0.405070, -0.570530, 0.404730, -0.748180, 1.203700, -0.064670, 0.284840, -0.188530, 0.355610, 0.668300,
0.747610, 0.549690, -0.562440, 0.861590, -0.100890, 0.787240, -0.155020, 0.429310, -0.841220, -0.371810,
-0.575040, 2.235130, 0.712210, 0.516970, -0.477870, 1.320910, 0.033380, 5.941990, 2.983800, 0.190650,
0.051540, 0.128530, -1.730800, 0.247440, -0.723040, 6.594780, -1.140110, -0.081650, -0.615760, 0.323520,
-0.549230, -0.686590, 0.756070, -0.463870, 0.107790, -2.266020, -0.527280, -0.952540, -1.000890,
0.366110, 0.520020, -0.403480, 0.004560, -1.076200, 0.491380, 1.213110, -0.168430, 0.441160, 0.005280,
0.328370, -0.357400, 0.030090, 0.785960, -0.225270, -0.525130, -0.728350, -0.926310, -0.441870, 1.076580,
0.759480, -0.422150, 0.488590, -0.521030, 1.144810, -0.769230, 0.040690, 0.410660, 0.283160, 0.435940,
-0.866050, 0.364930, -0.146220, -0.121980, 0.460820, 0.121610, 0.210910, 0.801650, 0.616060, -0.162180,
0.008270, -1.137100, -1.378070, -0.962600, -0.563640, 0.335140, 0.508530, 0.431350, -0.237560, -0.327740,
-0.397930, -0.348240, -0.231700, 0.817870, 0.396330, -0.512500, -0.330110, 0.728690, -1.779320, -0.744530,
-0.091990, 0.923080, 0.405360, -0.473440, -1.390910, -0.045580, 0.297470, 0.396760, -0.033630, 0.243690,
0.587730, 0.263290, -1.163290, -1.260340, 0.739450, -0.356640, -0.024720, 0.474150, 1.754510, 0.579860,
0.619420, 0.164050, 0.117480, 1.125950, -0.829630, 0.622200, 0.486810, -0.374200, -0.042980, -0.252970,
-0.889570, -0.433180, 0.169780, -0.261230, 0.319630, -0.035520, -0.254570, -0.403730, 0.108570, -0.051600,
-1.033460, 0.021400, 0.505970, -0.077620, -0.286160, -0.867080, -0.760970, 1.164930, 0.340360, 0.336570,
-17.831650, 0.634580, -0.101150, -0.894320, -0.040830, -1.110200, 1.099010, -0.611910, -0.756310, 0.126750,
-0.905020, 0.913230, 0.051490, 0.342670, 0.277240, -1.104500, -0.174370, 0.063670, -0.978690,
0.000620, -0.148700, 0.544460, 0.142910, -0.034360, -0.673740, 0.330290, 1.026590, -0.652010, -0.533000,
0.694610, 0.506900, -0.112610, -0.719530, -0.165390, 0.631630, -0.136610, 0.058060, 0.568550, -0.848280,
0.182700, -1.036950, -0.132430, -0.075760, -0.980360, 0.377410, 0.820980, -0.816500, 0.395680, -0.924790,
0.237780, -0.288080, -0.955670, 0.053180, 0.409900, 0.484470, -0.002360, -0.281330, 0.262430, -0.681040,
0.598400, 0.789200, 0.395210, -2.981500, -0.518780, 0.572570, 4.525840, 0.463760, -0.387940, 0.208660,
0.096130, 0.535880, -9.720580, 0.451420, 0.131390, 0.429710, 0.389450, 0.142010, -6.840420, 1.397520,
0.116660, -0.371560, 0.850430, -0.226670, -8.018850, 0.550040, -0.582040, 0.531440, -0.173020, 0.288680,
-0.571880, -0.738470, 0.423000, -1.279940, 1.076280, -0.200510, -0.507050, -0.844770, 0.377780, -0.349860,
-0.702510, -0.915050, -0.960200, -0.386790, -0.458440, -1.115740, -0.640030, -0.267340, 0.368670, 0.822610,
-0.684030, -0.318570, -0.843770, -0.326530, -0.091350, -0.750660, -0.892490, -0.727450, -0.819130, 0.100540,
-0.237700, 0.229670, 0.738540, -0.623050, 0.183380, 0.053000, 0.397330, 0.003900, -1.206680, 0.585860,
-0.389130, 1.640430, 0.721640, -0.289560, 0.779630, 0.270960, -0.173730, 0.338980, -0.490950, 0.279110,
0.267590, -0.323850, 0.265110, -0.201270, -0.005140, -0.591100, -0.558650, 0.645160, -0.962930,
-0.692610, 0.886420, 0.822100, -0.108860, -0.495000, -0.232910, -0.741190, 0.174360, -0.039790, 0.134750,
1.373160, 1.188200, 0.698000, -0.538930, -0.196800, 0.738330, 0.849720, -1.240110, -0.636380, 0.304460,
-0.165090, -0.762020, -0.307220, -0.298830, -0.041170, -0.976920, -0.763550, -0.383560, 0.518870, 0.624760,
1.072510, 1.872870, -0.656690, 0.202770, -0.962490, -3.873980, 0.775130, -4.132880, -1.328200, 0.667300,
-9.820780, -4.124140, -0.303290, -5.088910, -1.713470, 0.177830, -9.798110, -5.140370, -0.618790, -4.342070,
-1.167690, 0.981220, -7.374390, -0.969890, 1.161750, 0.592360, -0.252650, -0.217780, 5.145740, -0.627410,
0.419260, -9.763460, 0.935040, 0.091600, 6.959090, 0.255960, -0.610760, 6.521890, -0.531700, 0.269950,
-1.845050, 0.319080, -0.492450, -0.485630, -0.798180, 0.184600, 4.030050, -0.773320, -0.649030, 4.012580,
-0.113840, -0.634650, -13.975260, 0.114680, 0.312520, -1.030560, 0.041690, -0.747410, 4.641920, -0.461970,
-0.648310, -8.169950, 0.382330, -0.264630, -1.499300, 0.363840, -0.477790, 0.753230, -0.764700, 0.260140,
-0.324130, 1.447370, 0.073660, -1.158470, 3.677450, -0.711710, -0.615070, -0.498460, 14.500730, -1.200520,
1.987660, -0.335620, 4.759950, 1.025290, 0.196420, 0.671240, -0.826490, 0.542480, -0.539340, 0.379480,
-0.257600, 0.653600, -0.263130, -0.203250, 0.141530, 5.055740, -0.152300, -0.422690, 0.440100,
0.442000, -0.508480, 0.798940, 0.374980, -0.153530, 0.679490, 0.513530, 0.157100, -2.575010, -0.564330,
-0.062880, 0.071230, 0.000530, 0.237330, 0.736480, -0.616620, 0.218550, -2.731210, 0.110700, -0.791010,
0.235440, 0.535580, -0.092810, 0.062420, -0.085350, 0.690630, 0.269140, -2.736790, -0.044570, -0.156730,
-0.476740, -0.032720, -0.930880, -0.571550, 0.184340, -0.172610, -1.937320, -0.048730, 0.670040, 2.810910,
-0.150630, 0.112910, -3.489720, -0.084540, -0.451750, 0.907680, 0.362400, 0.175810, -5.718820, 0.598910,
-1.066050, -16.281071, -0.730820, 0.129780, 2.082430, -0.080520, -1.023180, -15.711450, 0.689940, -0.695460,
-2.332750, -0.214040, -0.405740, -1.306610, 0.108690, -0.201690, -0.023780, -1.259140, -0.667920, 0.026200,
-0.068480, 0.705820, -0.450130, 0.581870, 0.800200, 0.431200, -1.137420, 0.332280, 3.427800, 0.335180,
0.717000, 2.122380, 0.701490, -0.270050, -1.051900, 0.032570, -0.544230, -0.782320, 0.355460, -0.473580,
-1.097240, 0.572020, 0.038290, -0.816410, -0.172900, 0.253250, 0.783930, 0.565610, -0.417600, -1.089600,
0.461210, 3.225830, 0.106290, -0.260450, 0.374140, -0.280540, 0.403170, -2.400920, 0.011420, -0.245720,
1.096720, 2.633240, 3.034650, -0.167140, -1.049940, 0.714120, -0.656720, 0.197560, -0.650720, -0.701660,
0.489170, 3.925520, 0.593170, -0.792450, -0.713280, 0.023030, -0.734680, 1.190460, 0.583610,
0.840150, 0.015060, 0.269760, -0.891470, -0.233470, 0.073260, 0.384850, 1.907310, 0.487880, -0.402710,
0.106110, -0.081910, -0.119050, -0.453160, -0.565230, -0.928930, 0.052420, -0.397120, -0.140730, 1.466720,
0.406500, -0.173090, 0.058610, -0.823060, 0.490010, -0.848420, 0.951140, -1.076990, -1.181160, -0.094800,
0.029670, -1.441390, -1.176490, -0.199690, -0.376990, -0.141060, -0.045570, 0.418430, -0.900340, -1.275480,
-0.025130, 1.408510, -0.421110, -0.281340, -3.496730, -1.382950, -0.240140, 4.136110, 0.557460, -0.265240,
2.285120, -0.539790, -1.802480, -1.728070, 0.579170, 1.399650, 0.258550, 0.110010, 0.705000, 5.580050,
0.625720, -3.318680, 0.162570, -0.416330, 1.628410, 7.413590, -0.484450, 0.104690, 0.543170, 0.169400,
0.354380, 0.603350, -0.156910, 1.654470, 1.134920, -0.373940, 0.474550, 0.573930, -0.742250, -1.433320,
0.377600, -0.071330, 0.951030, 0.131430, 0.114420, -0.136940, -0.243210, 1.908580, -0.124630, 0.118760,
-0.772710, 1.927810, -0.037270, 0.846630, 12.010670, -1.082640, 0.082370, 0.834910, 0.337370, 1.468520,
0.679770, 0.412420, -0.457630, 0.305570, 6.961300, -2.342210, 0.892820, -0.028790, -9.273150, 0.587360,
-1.290230, -3.006670, 3.300260, -2.478350, 0.081660, 0.939670, -0.462530, -0.167880, -0.480430, 0.578780,
0.758020, 0.227460, 4.027120, -0.617250, 0.628620, 5.918030, -0.552770, 0.152350, 0.429170,
-0.737290, 0.690380, 0.600320, 0.246520, 0.173900, 0.866360, -0.372350, 0.023650, -0.506470, 0.695740,
0.098110, -0.584410, -0.009550, -1.249350, 0.252330, 0.361390, 0.384040, -0.380530, -0.146030, -0.631420,
-0.128010, -0.898690, 0.433150, -0.147060, 0.075540, 0.882700, -0.663630, -0.286000, -0.861750, -0.403740,
-0.779290, 0.378900, 0.452570, 0.838800, 0.522550, 0.147370, -0.610830, -0.714440, 0.034990, 0.109830,
0.525740, -0.672010, -1.052090, 0.324500, -0.116130, -0.093100, -0.537190, 0.604360, 0.465180, -2.609370,
0.575290, 0.435490, 1.165610, -0.008050, -0.244200, -1.012120, 0.776310, 0.437080, -0.062440, 0.958400,
-0.412900, 3.778900, 0.885320, 1.428320, -4.105060, -5.310140, 0.272030, 0.776840, 0.813200, 0.394550,
6.387480, 2.417040, 0.556940, -1.632650, -0.580130, -0.268480, -0.536240, -1.152850, 0.280230, 7.105690,
1.116860, 0.010910, -3.625120, -3.613790, 0.643040, -1.853450, -1.023760, 0.083120, 10.381370, -1.103960,
0.536480, -13.559470, -4.830770, 0.202130, -3.324570, -1.491900, 0.530270, -2.516500, 0.456310, 0.600670,
-0.773170, 0.087380, -0.039210, 0.307900, -1.191020, -2.042530, 0.625290, -0.864740, -0.837910, 0.223520,
0.373230, -2.142080, -1.511370, 0.409630, -0.680310, 1.127300, 4.976590, -0.686120, -0.058410, -0.961910,
0.130490, 0.653230, 0.213200, 0.467250, 0.172990, -3.294530, 0.065930, -0.632600, -0.841620,
-0.910620, 0.049790, -0.518760, -0.767500, -0.275680, -0.577720, 0.318580, -0.472600, -0.116510, -0.734930,
0.191340, -0.624540, -0.141560, -0.870520, -0.523560, -0.590180, 0.011240, 0.303370, -0.351350, -1.344070,
-0.909250, 0.892840, 0.718460, 0.135830, -1.143930, 0.779120, -0.477770, 1.836350, 0.162040, 0.639190,
0.013090, 0.841720, -0.812320, -1.861620, -0.152260, 0.230460, 0.971900, -3.440560, 0.146160, 0.642370,
1.116970, -0.733470, -1.751830, 0.163390, -0.650270, -0.076880, 0.512950, 1.011260, 3.003110, 1.284830,
-0.872270, 0.095310, 0.793930, -0.473880, 4.112180, -0.244060, 0.039710, -0.233480, 1.550000, -1.675350,
-0.847170, -0.424530, 0.755790, -1.657770, 1.305250, -1.852410, 5.095290, 1.316270, 0.193770, -2.838600,
-0.429110, 0.103790, 0.020800, 1.434190, -0.251460, -0.831520, -0.016500, 0.140360, 1.532630, 0.184570,
0.028160, -10.399840, 0.777190, -0.601170, 0.983920, -0.468860, 0.325780, 2.109000, -0.305980, -0.268490,
-1.796770, 0.058180, -0.214520, -0.708030, -0.207330, -0.108500, 0.416530, -0.909850, -0.033790, 0.616180,
-1.091940, 0.586240, 0.189550, -0.641060, 0.708470, -1.002760, -0.345940, -7.695830, -0.588820, -0.433300,
-1.310990, -0.367770, -0.785330, -0.114680, 1.267440, -6.010970, 0.976890, -0.227000, -0.205340, -0.442860,
0.054220, -0.680940, 2.279850, 0.041960, -0.725920, -0.823920, 0.808920, -0.757880, -0.718400,
0.251800, -0.605550, 0.043330, 0.510240, 0.294310, 0.653920, 0.387890, -0.154010, -0.277810, 0.880530,
0.149300, 0.171710, 0.593410, 0.476390, 0.205180, -0.633650, 1.094480, -0.300620, -0.030730, -0.304750,
-0.118050, -0.380410, -0.419500, 0.335510, 0.343530, 0.310130, -0.421510, -0.665660, 0.337860, 0.323280,
1.186920, 0.054120, 0.507170, -0.621260, 0.948810, -0.880560, 0.433750, 0.638330, -0.459170, -0.420060,
-0.674770, -0.968680, -3.014150, 1.188270, -0.322830, -0.263500, -0.421620, -0.697610, -4.606480, -0.324860,
0.760190, 3.085910, 0.286650, -1.197450, -5.707540, 0.294070, 0.610090, 4.766370, 1.276790, 0.223340,
1.100910, -0.614720, 0.429910, 0.762500, -0.369030, -2.237130, -0.225070, 0.351500, 0.194800, 0.383650,
-2.229640, -0.403690, -0.387060, 0.632690, 0.334030, 0.234990, 0.394060, 1.065040, 0.948900, -1.304700,
-0.744720, 0.237710, -0.356840, -0.596270, -0.731900, 0.212200, 0.152790, 1.001140, 0.408080, 1.043590,
-0.207590, 0.261920, -0.961170, 0.771760, 0.305880, 0.142630, 0.011400, 0.674150, 0.264310, -0.689840,
-0.083080, 0.047860, -0.344360, -1.005730, -0.023560, 1.258070, -0.231760, 0.785420, 0.977090, -0.690590,
-0.232900, 1.289960, -1.233580, -0.327820, -0.299930, 3.966390, 0.653940, -0.362850, -0.676380, -0.964010,
0.371260, 0.142220, -2.861220, 0.002580, 0.842300, 1.829630, 0.215770, -0.452480, 2.024110,
-0.679400, -0.876590, 0.056480, 0.288870, 0.180400, 0.359780, -0.229450, 0.574390, 0.154280, 0.445210,
-0.523590, -0.608520, -0.341320, -0.338640, -0.312090, 0.319130, 1.143720, 0.148900, 0.931790, -0.848870,
0.495760, 0.981850, 0.739540, 0.619490, -0.478420, 0.717880, -0.017380, 2.674070, 0.075830, -0.720720,
-0.966320, 1.182950, 0.591750, 0.940320, -0.111430, 0.783700, 1.372790, 0.047760, 0.766540, -0.458520,
0.910720, 0.267950, -0.240340, 1.061390, -0.809770, -1.313260, -0.158140, 0.638030, -2.922890, 0.211440,
-0.866440, -1.154350, -0.483700, -0.439520, -1.469200, 0.336800, 0.739050, -0.950690, 0.712470, 0.829540,
3.028550, -1.353010, 0.888260, -10.666890, 0.427090, 0.447520, -0.472770, -0.694690, -0.159420, 2.828150,
0.133870, 0.300990, -1.309430, 0.435090, 0.825720, -0.038620, 0.595940, 0.491360, 0.328370, -0.115210,
-0.092720, 0.264850, -0.747230, 0.495650, -0.383520, -0.810310, -0.141650, -0.394550, 0.425200, -0.104450,
-0.640370, 0.694190, 0.131330, -0.135840, 1.037330, 0.151360, -0.269100, 0.166440, 0.718590, -0.369710,
-0.171080, -0.563880, -0.200160, 0.211700, 0.414840, -1.069260, -0.207940, -0.831930, 1.452110, -0.464280,
-0.852100, 2.507810, -0.064030, -0.041440, -1.023250, -12.183990, -1.877850, 0.714890, 0.662490, -0.600760,
-0.535110, -1.351340, -3.789620, -0.376490, -0.533980, -10.486860, -0.354230, -0.231020, 6.065430,
-0.651370, -0.177680, 0.292070, -0.110570, 0.403380, -0.401080, 0.005270, -0.682890, -0.407140, -0.778520,
0.366360, 0.249170, 0.046400, 0.137150, -0.266240, -0.307790, -0.337970, -0.564610, 0.718860, -0.122350,
0.331100, -0.696450, -0.400760, -0.563420, -0.487480, 0.089820, -0.444290, -0.674520, 0.393510, -0.205420,
0.423320, -0.673350, -0.012230, 0.841870, -0.822560, 0.889500, -0.430170, -0.044260, 0.696050, -0.256000,
-0.563440, 0.842300, 0.748730, 0.452010, 0.679420, 0.657840, 0.101230, 0.706660, 0.218870, -0.948540,
-1.021710, -0.182950, 0.331720, -0.123710, -0.833250, -0.796350, -0.068130, 0.939040, -0.579270, 0.886060,
-1.009070, 0.293020, 0.224300, 0.293940, -1.555790, -0.088100, 0.856030, -0.720550, -0.100490, -0.666690,
0.309850, -0.138840, -0.394310, 0.523280, 0.250170, 0.464350, 0.211010, 0.027420, 0.158610, 1.469650,
0.451740, 0.877150, -1.033740, -0.197770, -0.061220, -0.461390, 0.326330, 0.533560, 1.272740, 0.133970,
0.324420, -0.239070, 0.022300, -0.023760, -0.732970, 0.220640, 3.154360, 0.116420, -0.421510, 0.380920,
-0.109490, 0.381630, 0.404300, -0.739820, -1.371300, 0.743260, 0.067080, -0.332730, -0.219750, 0.839540,
0.557470, -1.080390, -0.194470, 1.029750, -0.374120, 2.169470, -0.633300, 0.740360, -0.101870, 0.029130,
-0.054300, -0.124630, -0.200500, 0.195950, -0.410090, -0.076470, -0.151890, -0.063600, 0.683010,
-0.449800, -0.433700, 0.277280, -0.828920, -1.050970, -0.956690, -0.749360, -0.997650, -0.356400, -0.767900,
-0.562380, -1.113040, -0.011200, -0.550380, -0.003090, 0.272070, 0.670810, -0.163900, -0.966670, -0.790440,
-1.084990, 0.976100, 0.023740, 0.651240, -0.491130, 0.228890, 0.329070, -0.806890, -0.366770, 0.604080,
-0.702980, 0.542760, -0.210040, 0.509370, -0.975420, 0.251730, 0.312600, 0.433670, 0.757730, 0.155090,
-0.113050, 0.688270, 0.774260, 0.020840, -1.421300, 0.492490, 0.750810, 2.230570, 1.100370, -0.062810,
-0.732010, -0.706440, 1.796450, 0.086120, 0.272790, 0.261970, -5.547560, 1.107300, -2.724370, 1.431340,
0.400880, 1.046340, -0.994880, 0.625770, -0.719760, -6.350830, -0.177820, 2.442920, -1.922910, -1.191150,
-2.553350, -0.915280, -0.578710, -0.453600, -4.474340, 0.012670, -5.018270, 0.359440, -0.410400, -9.623770,
0.404890, 0.644150, 6.718810, -1.046290, -0.500000, -11.501530, -0.255740, 0.372000, -0.305910, 1.199420,
-0.589940, -1.642500, 0.709870, 0.697740, -8.397800, -0.695080, -0.972950, 0.198260, -0.307650, 0.750430,
0.519380, -0.344720, -0.511700, -0.379450, 1.905130, 0.770610, -0.787740, 0.075690, -2.450970, 0.599370,
0.133480, -91.671333, 2.078260, 3.520920, 0.165950, 0.341600, 0.373770, 0.009120, -0.538720, 0.165630,
0.556670, 0.710940, -0.538330, 0.439430, 0.418450, -1.446460, -0.591830, -0.643680, 1.929920,
0.722500, -0.244170, 0.467100, -0.783060, 0.118370, -0.578920, -0.043080, 0.516490, -0.081510, -0.316390,
0.001110, 0.015340, -0.036350, 0.653030, 0.088020, 0.565180, -0.235670, 0.778330, 0.444450, -0.551620,
0.751620, -1.052420, 0.460430, -0.249760, -0.457140, 0.261460, 0.560920, -0.433660, 0.551890, -0.106890,
0.320750, 0.070470, -0.185830, 0.690130, 0.427100, 0.422490, 0.462640, 0.070130, 0.164540, 0.542800,
-1.128020, -0.313460, 0.779250, -0.263270, 0.822850, -1.005120, -2.018100, -0.196460, -0.943980, -0.896840,
0.752620, -0.236060, 0.824220, -3.748330, -0.537930, 0.676460, -0.486570, 0.451080, -0.274870, -0.740200,
-0.342150, -0.043410, 0.727780, -0.545700, 0.748940, -1.285320, 0.178540, 0.859990, -0.257590, 1.850030,
-0.425460, -0.389010, -0.282790, 0.805000, -0.755260, -0.894570, 0.007670, 0.544200, 0.897250, -0.519390,
-0.466920, 0.614560, 0.794600, -0.625650, -0.275870, -0.689250, -0.292840, 0.828860, 0.781760, -0.313410,
-3.969350, 0.846920, 0.652660, -1.457020, 0.504230, -0.102480, -0.933940, -0.822650, -0.330660, 0.361340,
0.448350, -0.443400, -0.018790, -0.469390, -0.660410, 0.145560, 0.896960, 0.160420, 0.269910, 0.287530,
0.457710, 0.433520, -1.029080, -0.553480, 0.253330, -1.565090, 0.392120, -0.567770, -0.064940, 0.065540,
-0.964640, 0.076410, -0.491770, 0.068760, 0.057160, 0.360500, 0.335390, 0.104390, -2.990170,
0.939150, 0.791090, -0.233750, 0.195110, -0.947810, 0.178180, -0.866660, 0.794290, 0.690610, 0.165690,
-0.142940, -0.124600, 0.801000, 0.030870, 0.261580, -0.421930, -0.408450, 1.012930, -0.822500, 0.016580,
-0.372210, -0.088550, 0.428750, 0.173760, 0.991770, -1.310210, -0.440560, -0.315170, 2.054590, -0.373280,
-0.738530, -0.085300, 0.504910, 0.619990, -1.565410, -0.138300, 0.614610, -1.350480, 1.172870, -0.347870,
-0.101640, -0.307960, 0.674980, -0.720640, 0.020980, 0.254100, -1.572980, 1.034350, 0.578330, -0.779130,
0.778040, 0.342890, 0.334250, 0.565470, 0.504270, 0.635200, -0.783250, 0.157730, -0.653600, 0.106850,
-0.404950, -1.260560, -0.012830, -0.477990, -0.943770, -0.463560, -0.297620, -0.791070, -0.077690, -1.698250,
-0.405600, -1.000800, 0.069470, -0.823910, -0.794370, 0.195140, -0.273020, 0.195070, -0.152210, 0.834970,
0.499810, -0.179500, 0.062440, -0.682950, -0.655840, -0.918840, -0.289270, -1.343120, 0.121560, -0.926280,
-0.285190, -1.162910, -0.498100, 0.333330, -0.267020, -0.705130, -0.196630, -1.906780, -0.854000, 0.813030,
-0.123670, -0.240750, -0.113510, -0.394920, 0.213540, 0.663310, -0.036540, 1.256260, 0.325300, 0.790960,
0.597430, 2.090240, 0.554390, -0.460770, -0.048830, 0.488810, -0.250490, -0.624310, -0.430330, 0.252530,
-1.024120, 0.475820, 0.891990, 1.232980, 0.580100, 1.323610, -0.155120, -0.620230, -0.930260,
-0.014200, -0.213720, -0.278450, -0.593310, 0.038910, -0.877860, -0.602170, -0.857660, 0.149670, 0.296200,
0.445860, 0.076640, -0.207880, 0.770800, 0.634670, 0.628940, -0.255170, 0.352600, 0.708830, 0.836110,
1.156200, 0.232100, 0.603710, -0.510600, -0.512050, 0.258750, -0.512560, 1.359160, -0.604640, 1.090030,
0.492820, 0.046390, 0.031120, 0.368290, 0.624050, 0.484880, 0.331700, -1.036040, 0.160480, 0.229830,
0.203700, 0.218620, 0.475590, 2.995880, 0.293560, -0.246610, -5.500610, -0.241320, 0.236000, 0.112170,
-0.236760, 0.036480, 7.745130, 0.106210, 0.301250, -1.850910, -0.665870, -0.969070, 1.335130, -0.547110,
-0.471920, -0.376140, -1.181250, 0.190000, 1.800920, -0.299690, 0.153650, 0.794600, -0.310070, -0.144860,
-1.210800, -0.145880, -1.108140, 1.594320, -0.707960, -0.303460, 0.056100, 0.443180, -0.040420, -0.356320,
0.127440, -0.787440, 0.893730, -1.074090, 0.251580, -0.413600, 0.565010, 1.228710, -0.350650, 0.148060,
0.152890, 0.465550, 0.642850, -0.691970, 0.601260, -0.430600, 0.086560, 0.617550, 0.211230, 0.184310,
0.264420, -0.663980, -0.711430, 0.576880, -0.073790, -0.139060, -0.070120, -1.522620, -1.828950, -0.599800,
0.859060, -1.895660, -0.808690, 0.122510, -0.199860, -1.180030, -2.171080, -0.568200, 0.223570, 0.238440,
0.833140, -0.122340, -0.081060, 0.321670, 0.045120, -0.270800, -0.222120, -0.407320, -3.543850,
0.143420, -0.155270, 0.644460, -0.162230, -0.091240, 0.089890, 0.746490, 0.246470, 0.919180, -0.643410,
0.256160, -0.202660, 1.016720, 0.437160, -0.443370, -0.382050, 0.957600, 0.005460, 0.014440, -0.322880,
-0.002090, 0.125800, -0.299090, 0.128510, 0.619620, 0.751490, -0.226240, 0.541090, 0.109490, 0.953780,
-0.821780, 0.191160, 0.818400, 1.292350, 0.715500, -1.359000, -0.902590, 0.094640, -0.532920, 0.447300,
-0.804550, -0.046670, -0.119310, 1.992510, -1.499770, 1.592610, 0.123660, -1.208680, 1.809400, 1.001790,
0.444810, -0.547890, 0.197420, 0.021090, 0.553630, 0.276570, -1.189350, -0.211600, 0.744220, -1.397280,
-1.309690, -0.597600, -0.641500, 1.559690, 0.267690, 0.053050, -0.716850, -0.695080, 0.053710, -0.304110,
0.585610, -0.338970, 0.970780, 0.287920, -0.953030, 0.593130, 0.004410, 1.012360, 0.245520, -1.018800,
-0.564730, 0.525970, 0.265170, -0.181490, 0.173850, 0.408850, -0.221100, -0.915650, 0.160420, 0.657000,
0.750170, -1.058010, 0.459360, -0.942920, -0.774230, -0.650420, -0.234920, 0.225300, -0.490300, -0.034470,
-0.046560, 1.443410, -1.109500, 0.228820, 0.337880, 0.786570, 0.268570, -0.540840, -1.510770, 0.228970,
-0.178930, -2.591820, 2.142510, -0.076080, 0.195600, -1.737100, -1.225030, 0.285790, 0.638120, 0.622020,
0.553760, 0.448220, -0.044400, 0.226550, -0.382690, 0.144420, 0.306690, 0.856990, 0.772740,
-0.220670, -0.495130, 0.165190, -0.762480, -0.255070, -0.362470, -0.242040, -0.732150, -0.809850, 0.876680,
0.644180, 0.102660, 0.493090, -0.728660, -0.462910, 0.415420, 0.542230, 0.845370, -0.848100, -0.765970,
-0.592830, -0.093220, 0.121530, -0.887040, -0.776840, 1.105690, -0.643050, 0.477320, -2.120080, -0.405890,
0.180500, 1.065300, 0.514940, -0.128930, 4.108750, -0.966360, 1.955600, -3.699750, 0.136600, -0.230680,
0.832650, 0.865060, -0.703020, 0.789120, -0.523190, 0.424230, 0.696890, -0.798320, -0.793090, 1.573460,
-0.621330, -0.063600, -0.417010, -0.243820, -1.634480, 1.400980, 0.862230, -0.445460, 0.292210, -0.662330,
0.568550, 0.437840, -0.013120, 0.228410, 0.897130, 0.276720, 0.351570, 0.563810, -0.665590, 0.469040,
-0.988680, 0.124680, -1.419760, 1.128040, 0.011540, 1.170770, -0.322360, 0.699560, 0.297860, 0.491900,
-0.430300, 0.569720, 2.258990, 0.724030, -0.727360, -0.769470, -0.220530, 0.919390, -0.001780, -0.799120,
-0.376780, 0.246070, 0.211330, -0.074680, -0.094230, 1.045900, 0.113920, 1.824510, 0.949610, -0.365720,
0.339930, -0.047660, 0.383870, -0.122940, -0.167730, -0.368000, 0.199060, -0.579680, 0.799230, 0.005060,
-0.906950, -1.993630, -2.448850, 0.745470, -1.076240, -0.242820, 0.623490, 0.020100, 1.451230, -0.053150,
-0.020450, -0.857750, 0.014480, 0.367480, 0.798840, -3.306880, 0.931630, -0.108250, 1.415540,
1.010020, 0.308920, -0.327200, 0.002300, 0.770160, 0.347470, 0.305180, 0.403590, -0.019520, 0.305800,
0.398350, 1.542040, 0.770380, 0.157280, -0.622380, 1.147120, 1.070710, -0.712650, -1.302990, -0.397170,
0.654080, 1.345410, 0.079430, 0.181740, 1.207600, -0.434540, 1.042540, -0.600850, 0.877960, 0.637850,
-0.581760, -0.038340, -0.199190, 1.250420, 0.108450, -0.039570, 0.088410, -0.459090, 0.442420, 1.957680,
-0.413980, -0.647060, 0.674800, 6.204500, 1.873610, 2.317750, -2.291680, -4.238750, 0.467210, 0.072930,
1.019980, -0.161640, 4.633480, 0.962850, -0.116980, -4.121130, 0.911110, 0.274790, -4.200210, -1.436850,
-0.503750, 5.571520, 0.149960, 0.964960, 0.295900, -1.159810, 0.171930, -3.886500, 1.060100, 0.274990,
6.294010, 0.375510, 0.103340, -6.730520, -0.714620, -0.146160, -1.512730, -0.348400, 0.146520, 3.979140,
0.333820, 0.030010, -3.635390, -0.547020, 0.649500, -0.710630, 0.595300, -0.457870, 0.219980, 0.565370,
-0.212290, -2.462220, -0.957340, 1.261550, -2.569630, -0.380680, 0.740080, 1.105610, -0.243170, 0.586500,
-0.017910, -1.084590, -0.153180, -0.201410, -2.680020, 0.601490, 0.137150, -1.464980, -34.131779, 0.726930,
0.021430, -17.933920, -2.362670, -1.149600, -0.583000, 1.179130, -4.830990, -0.132540, -3.826070, -0.661740,
-0.136860, -1.033530, -0.413260, -0.646540, 0.186550, -0.287560, -0.274150, -0.162630, 4.291320,
-0.246350, -0.256860, -0.557680, -0.942030, -0.263520, -0.809240, -0.342120, 0.685020, -0.832160, 0.047790,
-0.366180, 0.577990, -0.869150, -0.780450, -0.319140, 0.687540, -0.559000, 0.266180, -0.640770, -0.001280,
-0.226100, 0.806700, -0.024260, 0.591160, 0.385860, -0.956450, -0.807150, -0.422680, -0.079310, 0.232090,
-0.478870, 0.441390, -0.065410, -0.078210, -2.090320, 0.478270, 1.237560, -0.361840, -0.500610, 0.972940,
-1.322580, 0.686220, 0.375220, -3.744680, 0.111420, 1.499900, -0.901510, 0.326790, 1.078060, -1.465220,
0.763410, -0.327150, -4.883230, 0.933540, 0.315160, -1.643290, 0.595780, -1.109350, 0.115470, 1.496090,
0.655460, -0.161380, 0.347120, -5.216670, 0.144720, 0.419650, 0.985740, 0.145240, -0.188660, 0.065880,
-1.496080, -0.345220, 0.358540, 0.712930, 0.161770, -0.648140, 0.653350, -0.818060, 0.242750, -1.880430,
-0.559840, -0.954310, -0.371520, -0.087700, -0.435080, 0.687330, -0.522050, -0.624740, 0.074870, -0.204920,
0.132660, 0.317380, -0.870190, 0.001140, 0.561570, -0.263580, 0.401510, -0.251510, 0.572420, -0.410280,
0.497270, -0.070540, 0.902970, 0.084150, -0.643610, 0.709670, -0.825180, 1.876140, 2.922370, 0.084190,
-0.235290, 0.473770, -2.441000, -0.022060, 0.257960, 2.572440, -0.863470, 0.673490, -0.583950, -0.645000,
0.483990, -0.639730, -0.717240, -0.498330, 0.395440, 0.603870, -1.026660, -0.357820, -0.401350,
-0.376060, 0.782620, -0.033290, 0.076960, 0.519880, -0.124790, 0.174550, 0.047360, 0.006840, -0.172770,
-0.089740, 0.393190, 0.027870, -0.709290, -0.328750, 0.373130, 0.102560, 0.436410, 0.162590, -0.843900,
0.626370, -0.472130, 0.895930, 0.406960, 0.576180, -0.442840, 0.182310, -0.588300, 1.307460, 0.119440,
-0.079400, -0.535940, -0.832930, 0.538920, -0.477210, 0.934410, -0.351410, -0.340510, -0.255910, 0.312380,
-1.035450, -0.600770, -0.636600, -0.949040, 0.253680, -1.622600, -0.784200, -0.007560, 0.012630, 0.178430,
0.853960, 0.334260, 0.494080, -0.026710, -0.976900, -1.450680, -0.396540, 0.618730, -0.651430, -0.346980,
-0.073610, 0.820200, 0.418550, 1.067390, -0.081820, 1.147340, 0.323410, 0.480280, -0.721270, -0.705110,
0.479650, 0.555920, 0.008700, 0.932150, 0.298310, 0.977420, 0.475280, -0.268650, -0.083080, -0.703980,
0.599210, 0.571270, -0.365070, 0.180020, -0.755810, -0.596070, -1.046320, 0.568720, 0.574490, -0.202300,
0.337410, -0.012120, -1.040510, -0.657550, -0.295720, 0.371720, 0.833240, -0.681570, -0.478040, -0.176630,
0.674270, 0.395770, -0.244610, 0.747760, -0.167880, 0.770790, 0.700480, 0.548800, 0.759370, -0.455320,
0.503650, -1.511910, -2.495680, -0.335150, -0.454200, 1.357090, -0.239230, 0.301690, -0.698320, 0.665410,
1.121970, -0.170770, 1.230540, 0.019020, -0.028770, 0.432410, 0.476410, -0.825660, 0.400950,
-0.996550, 0.623680, -0.553110, 0.382010, 0.544850, 0.508380, 0.181650, 0.552250, 0.678030, -0.254530,
-0.254870, 0.357400, -1.186830, -0.375500, -0.723070, 0.163950, 0.088640, -0.132230, -0.324040, 0.127620,
-0.418190, -0.660940, -0.773180, 0.523110, -0.189630, -0.178940, 0.018610, 0.602600, -0.636090, -0.450740,
-0.363470, -0.178910, 0.138740, -0.219080, -0.849410, 0.280520, 0.027400, -0.996610, -0.206820, -0.630490,
0.465750, 0.075050, -0.463250, 0.236860, 0.755780, 0.307270, -0.883300, -1.000600, 0.093400, 0.433300,
0.865460, 0.907210, -0.039660, 1.120590, -0.841910, -0.547250, 0.472710, -0.202060, -0.157800, 0.419790,
0.702820, -0.481620, -0.322290, -0.709360, 0.335450, 1.980670, 0.324380, 0.321800, -0.083410, 0.483780,
0.598370, 0.496230, -1.074150, 0.176390, 0.772910, 0.295480, -0.211280, -0.495970, -0.515100, 0.483780,
0.189070, 0.558610, 0.220420, 0.013280, 0.092350, 0.015980, -0.259580, 0.762330, -0.189380, -0.347230,
-0.096820, 0.785570, 1.004940, -0.383190, 0.798530, 0.912770, -0.035270, -0.935680, -0.964780, 0.274000,
0.207710, 0.076190, -0.610900, 0.417440, 0.538810, -0.227600, 0.324160, -2.208510, -0.573380, -0.734800,
-0.560560, -0.610710, 0.011590, 0.475850, 0.633300, -2.419880, -1.161220, 0.297440, -0.584900, 0.808640,
0.673500, 0.220340, 1.298480, -0.435030, 0.289820, -0.531650, -0.026050, -0.825430, -1.027380,
1.319590, 0.470850, 0.183230, 1.201700, 1.062270, 0.987380, -0.667410, -1.011950, -0.242930, -0.243930,
0.495480, -0.083930, 0.622520, -0.631180, 0.533710, -0.349690, 0.057750, 0.442380, -0.278890, 0.209530,
-0.820050, 0.364710, -0.226870, -0.990870, 0.427740, -1.151740, -0.090570, -0.019510, 0.647920, 0.742550,
0.333200, 0.570550, 0.811110, 0.014110, -0.355360, -0.697040, 0.511590, 0.358420, -0.992450, -1.108250,
0.572160, -0.303340, 1.145740, -0.630090, 0.833480, -0.341530, -1.841290, -0.054670, 0.933440, -0.784380,
0.487570, 0.884910, 1.715260, -1.395790, -0.498100, -2.477760, 0.902820, -0.510870, 0.938300, 0.078110,
1.616080, 1.293530, 0.813970, -0.194770, 1.045790, -0.896220, 0.060990, 0.803670, 0.174460, 0.819350,
0.788270, 0.757400, 1.461850, 0.713500, 0.718400, 1.313370, 0.187800, 0.913110, -0.705120, 0.215910,
-1.042940, 1.398710, 0.463690, -0.214690, -0.813200, 0.510030, 0.318440, -0.366920, -1.060730, -0.598520,
-0.756740, -0.959820, -0.342980, -0.501040, -0.052340, -0.413230, -0.928990, -0.118490, -0.889440, -0.388470,
-0.146840, 0.440910, -0.650890, -0.376880, 0.241850, 0.565390, -0.147000, -0.030380, 0.944120, -0.263940,
0.228490, -2.636790, -0.569420, -0.878490, -0.456430, -0.775370, -1.074440, -1.121900, -1.096610, -0.058450,
-0.358270, -0.328450, 0.901530, -0.534970, 0.093970, -0.903930, 0.632340, -0.362290, -1.392660,
1.086510, 0.494790, 0.135630, -0.273670, -0.038870, -0.204200, 0.601130, 1.220300, -0.182410, -0.769880,
-0.163370, 0.705680, -0.199760, 0.212920, 0.718820, 1.107610, -0.536920, 0.685930, 0.187650, -0.096290,
-0.127270, -0.614510, -0.283520, 0.489850, 0.784050, -0.590330, -1.524980, 0.407550, 1.070250, -0.315640,
-0.745760, 0.945600, -0.446690, 0.551010, -0.052500, -0.933070, 0.853670, -0.160530, 0.923440, 0.831020,
-0.543170, 0.693700, 0.232940, -0.677750, -0.659530, -1.884070, 0.350120, -0.336640, 1.023640, 0.917930,
-0.939580, -0.210140, 0.628190, -0.117430, -0.669350, -1.444610, -0.178190, -0.236340, 0.144190, -0.989770,
0.128420, 1.105680, -0.408460, 0.607010, 1.132760, 0.069310, -0.395620, 1.568460, -0.463960, -0.743560,
-0.653390, -0.354920, -0.712540, -0.477190, 0.808830, 0.947340, 0.445160, -0.047110, -0.794400, -0.503660,
-0.489340, -0.548470, -0.626210, 0.068320, 0.807250, 0.986980, 0.594120, -0.846530, -0.584440, -0.698940,
0.261870, -0.710210, 0.710670, -0.080010, -0.313040, -0.538310, -0.093650, 0.197780, 0.831370, 0.641240,
-0.449790, -0.680930, -0.677730, 0.983300, -0.333100, 0.457530, -0.918730, 1.820860, 0.371100, 0.256400,
0.078950, -2.494910, 2.340830, -0.366170, -0.127070, -1.481670, -0.839900, -0.096440, 0.563750, -0.255980,
0.725320, -0.556320, -1.385780, -0.225580, 1.036550, 1.907060, 0.317580, 0.503060, 1.388950,
0.767040, -0.660350, 0.483280, 0.727960, 0.632810, -0.299790, -0.147270, 1.080490, 0.873990, 0.143360,
0.989690, 0.424680, 0.986170, 0.709130, 0.871600, 0.431130, 0.773140, -0.096110, 0.542130, 0.118420,
0.195740, 0.678290, 0.038340, -0.232190, -0.156230, -1.008810, -0.670200, -0.848220, -0.758710, 0.513870,
-0.468010, 0.405400, 0.669050, 1.550710, 0.587240, 0.351270, -1.812550, 0.008730, -0.492040, 0.124580,
0.159340, -0.096860, 1.903890, -0.549680, -1.065140, 0.918820, -0.984010, -0.119570, -2.628330, -0.010570,
-0.817480, 2.908820, -0.720310, -0.431260, 1.398280, 0.098450, -0.574930, 7.780520, -0.688530, -0.521100,
-1.052720, 0.122410, 0.309030, 9.074540, -0.706620, -0.139310, -2.066410, -0.650020, -0.624360, -0.002300,
-0.184590, 0.619100, 0.471360, -0.605160, -1.342330, 0.440890, 0.567270, -0.776050, -0.598470, 0.373120,
0.902780, -0.585680, 0.484270, 0.904470, 0.688750, -0.090380, -0.640740, -0.827260, -0.520110, -0.556860,
-0.732330, -0.003890, 0.152370, 0.543930, 0.239280, -0.380100, -0.324340, -0.363430, -0.510140, 0.356630,
0.469410, 0.180090, 0.607000, -0.826710, -0.828330, -0.738170, 1.310130, -2.305260, -0.597660, 0.385620,
-0.387870, 0.332100, 0.112070, -0.069760, -0.607680, -5.399490, -0.763760, 0.726000, 0.014960, 0.137190,
-0.685270, 0.704300, -1.334040, -0.059620, 0.423650, -4.042410, 0.363070, -0.031380, 1.949820,
-1.174940, -0.776140, -0.033640, 0.247020, 0.817770, -0.515510, 1.137290, 0.681680, -0.848630, -0.438000,
0.701220, -0.069530, -0.221370, 0.167390, 0.372430, 0.506660, -0.373430, -1.479380, 0.059390, 0.754130,
0.376020, 0.424940, -0.202050, -0.259310, 0.005770, 0.513360, 0.468080, -0.414450, -0.354750, -0.329930,
0.344830, 0.109830, -0.893080, -0.480140, 0.031960, -0.624030, 0.038850, -1.051780, 1.048230, 0.973730,
-0.000600, 0.750780, -0.087750, 0.477440, 0.277000, -0.046460, -1.608610, -0.786120, 0.369030, -0.653910,
0.675920, 0.380810, -0.580210, 0.443200, -0.961490, -1.046830, -0.760460, 0.369420, -0.220100, -0.489110,
-0.585430, -0.936360, -0.480550, -0.676510, 1.610620, -0.789810, 0.278140, 0.271590, 0.210840, 0.001150,
-1.334350, 0.741110, -1.051150, 0.687890, -0.863610, 0.676140, -0.219680, 0.182910, -0.043040, 0.364480,
-0.314850, 0.623480, 0.339040, 0.646820, -0.238050, -0.599050, -0.964430, -0.574350, -0.343890, -0.865290,
-0.403900, -0.267820, -0.696330, 0.509780, 0.100420, 0.708660, -0.778390, -0.802190, 1.349560, -0.867040,
0.297840, -0.987550, 0.016030, 0.428670, 0.455590, -0.904070, -0.001780, 0.613570, 1.899700, 0.024330,
-0.355070, -2.946300, -0.530830, -0.849060, -0.110060, 0.342950, -5.060920, -0.565140, 0.240280, 0.380900,
0.165650, -0.598480, 0.726740, 0.183710, -0.122700, 1.901740, -0.546860, -0.092310, 0.464800,
0.963900, -0.104450, -1.049630, 0.677250, -0.908250, -1.761780, 0.669020, -0.902090, 0.963810, -1.900300,
-0.920830, 0.541020, -2.036170, -1.315070, -1.585110, 0.886050, -0.017110, -0.209960, 0.280400, -0.470760,
0.278940, 0.398320, 0.696410, 0.799930, -0.212050, -0.599640, -0.247050, -0.458040, -0.284100, 1.510900,

0.374890, 0.395530, -0.806730, 0.575080, 0.866620, 0.553900, -0.911290, 0.355060, -4.642630, 0.927560,
-0.661140, -0.367830, 0.407960, 0.401960, 0.557780, -0.818170, -0.289210, -0.163590, -1.081550, -0.610920,
-0.102770, 0.361380, -1.158590, -0.787370, -1.219380, 0.276590, -1.221660, 0.896360, 0.364980, -0.043030,

-0.875450, -0.734250, 0.805490, -0.489770, 0.626260, -0.397590, -0.516560, -0.122510, -1.416250, -1.320040,
0.820680, -0.060430, -0.407730, 0.648510, -0.659770, 0.686790, 0.085960, 0.757170, 0.423380, -0.012310,
-0.876950, -0.439230, -0.519490, -0.190500, -0.452430, 0.767200, 0.194980, -0.058180, -0.726420, -0.819930,

0.227390, 0.180450, 0.336950, 0.365480, -0.527260, -1.300710, 0.014770, -0.380150, 1.269690, -3.276710,
-0.081640, 0.846050, -1.606100, -1.872280, -1.051610, 0.696370, 1.112300, -0.983330, -0.900520, -0.236800,
0.193750, -1.369530, 0.056080, 0.096680, -0.174010, -1.065590, 0.200370, 0.335000, 0.825150, 0.503870,

0.197040, 0.025740, 0.103680, 0.592560, -0.329350, -0.338760, -0.455790, -0.440280, -3.746620, 0.901280,
0.138860, -0.733960, 0.890120, 0.637010, 0.373610, -0.525670, -1.718760, 0.342520, -0.278520, -0.010430,
0.760770, 0.729780, -1.209790, -1.185310, -0.937780, -0.222630, -1.799990, -0.505750, -0.619700, 0.565780,

-0.366020, -0.136670, -0.317170, -0.678310, 0.833770, 0.300450, 0.121840, -0.246050, -1.035410, -1.083530,
0.739240, -0.447690, -1.050400, 0.881370, -0.360960, 0.041570, -1.163960, 0.248190, -0.538710, -0.679530,
-0.961750, -0.134900, -0.135020, 0.775150, 0.919510, 0.739200, 1.326340, -0.383970, -0.205330, -1.197510,

0.262110, -0.124370, -0.462370, -0.399110, -0.300000, -0.205050, -0.502210, -0.331360, 0.807130, -11.252980,
-1.164880, 1.247590, -1.714020, 1.054490, -1.230630, 0.488900, 1.303700, -1.071370, -0.065480, -0.532890,
0.804790, -0.589870, -0.006030, -1.567350, 0.369980, -0.854130, 0.824820, 0.321510, 0.917920, 0.790930,

-0.005180, 0.545360, 0.296810, -0.620690, -0.546560, 0.081070, -0.250910, -0.915270, -3.357450, 0.708870,
0.136380, -0.923140, 1.603410, 0.668520, 0.167580, -0.624190, -1.942310, 1.192610, -0.570560, 1.326050,
0.081900, -0.136380, -0.545360, -0.383430, -0.180970, -0.086530, -0.103770, 0.446500, -0.188650, 0.558520,

0.174090, 0.239870, 0.266130, 0.461520, 0.118450, -0.108420, 0.738420, 0.530840, -0.918070, -0.028620,
-0.025160, -1.024250, -1.676490, -1.087080, 0.120500, 0.806490, -1.324570, -0.106500, -0.558660, -0.331580,
-0.697730, -0.375760, -0.401220, 1.125890, -0.376040, 1.359380, -0.461930, -0.499030, -0.682210, -1.095300,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.672220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.776520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.778440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.504540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.856390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.388430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.248530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.994680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.677100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.394750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.055350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.584860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.100750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.963360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.632750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.649820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.184110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.178160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.273210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.127820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.019250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.614500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.439050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.348680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.144500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.781710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.911150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.709500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.677600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.320330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.651100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.231920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.623960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.446080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.041270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.462620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.854870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.838550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.713720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.952810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.835780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.251660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.265630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.181580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.729800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.987580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.921760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.512800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.014290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.294480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.175750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.014380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.079200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.316420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.810350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.213690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.994870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.962400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.051260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.907440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.416460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.583710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.704320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.191830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.328100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.408660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.353400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.568110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.977190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.901880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.940070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.119200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.907370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.348310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.722140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.288380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.998330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.424080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.836690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.432210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.177460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.324310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.952070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.015490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.341340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.720870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.782720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.243590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.591580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.099940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.473910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.098510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.812810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.052680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.278320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.131780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.795180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.873960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.403190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (hid1) */
      0.0, -0.517920, 129,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (hid2) */
      0.0, 0.106480, 129,
       &Sources[129] ,
       &Weights[129] ,
      },
    { /* unit 102 (hid3) */
      0.0, -0.337000, 129,
       &Sources[258] ,
       &Weights[258] ,
      },
    { /* unit 103 (hid4) */
      0.0, 0.130970, 129,
       &Sources[387] ,
       &Weights[387] ,
      },
    { /* unit 104 (hid5) */
      0.0, -0.161750, 129,
       &Sources[516] ,
       &Weights[516] ,
      },
    { /* unit 105 (hid6) */
      0.0, -0.451600, 129,
       &Sources[645] ,
       &Weights[645] ,
      },
    { /* unit 106 (hid7) */
      0.0, 0.182160, 129,
       &Sources[774] ,
       &Weights[774] ,
      },
    { /* unit 107 (hid8) */
      0.0, 0.793320, 129,
       &Sources[903] ,
       &Weights[903] ,
      },
    { /* unit 108 (hid9) */
      0.0, 0.025070, 129,
       &Sources[1032] ,
       &Weights[1032] ,
      },
    { /* unit 109 (hid10) */
      0.0, 0.294100, 129,
       &Sources[1161] ,
       &Weights[1161] ,
      },
    { /* unit 110 (hid11) */
      0.0, -0.358890, 129,
       &Sources[1290] ,
       &Weights[1290] ,
      },
    { /* unit 111 (hid12) */
      0.0, -0.105740, 129,
       &Sources[1419] ,
       &Weights[1419] ,
      },
    { /* unit 112 (hid13) */
      0.0, -0.217750, 129,
       &Sources[1548] ,
       &Weights[1548] ,
      },
    { /* unit 113 (hid14) */
      0.0, -1.003440, 129,
       &Sources[1677] ,
       &Weights[1677] ,
      },
    { /* unit 114 (hid15) */
      0.0, -1.043470, 129,
       &Sources[1806] ,
       &Weights[1806] ,
      },
    { /* unit 115 (hid16) */
      0.0, 0.599070, 129,
       &Sources[1935] ,
       &Weights[1935] ,
      },
    { /* unit 116 (hid17) */
      0.0, 0.499750, 129,
       &Sources[2064] ,
       &Weights[2064] ,
      },
    { /* unit 117 (hid18) */
      0.0, -0.388020, 129,
       &Sources[2193] ,
       &Weights[2193] ,
      },
    { /* unit 118 (hid19) */
      0.0, 0.830930, 129,
       &Sources[2322] ,
       &Weights[2322] ,
      },
    { /* unit 119 (hid20) */
      0.0, 0.244810, 129,
       &Sources[2451] ,
       &Weights[2451] ,
      },
    { /* unit 120 (hid21) */
      0.0, 0.319690, 129,
       &Sources[2580] ,
       &Weights[2580] ,
      },
    { /* unit 121 (hid22) */
      0.0, -0.365490, 129,
       &Sources[2709] ,
       &Weights[2709] ,
      },
    { /* unit 122 (hid23) */
      0.0, -0.524410, 129,
       &Sources[2838] ,
       &Weights[2838] ,
      },
    { /* unit 123 (hid24) */
      0.0, -0.450370, 129,
       &Sources[2967] ,
       &Weights[2967] ,
      },
    { /* unit 124 (hid25) */
      0.0, 0.203770, 129,
       &Sources[3096] ,
       &Weights[3096] ,
      },
    { /* unit 125 (hid26) */
      0.0, 0.224750, 129,
       &Sources[3225] ,
       &Weights[3225] ,
      },
    { /* unit 126 (hid27) */
      0.0, -0.516990, 129,
       &Sources[3354] ,
       &Weights[3354] ,
      },
    { /* unit 127 (hid28) */
      0.0, -0.759750, 129,
       &Sources[3483] ,
       &Weights[3483] ,
      },
    { /* unit 128 (hid29) */
      0.0, 0.824220, 129,
       &Sources[3612] ,
       &Weights[3612] ,
      },
    { /* unit 129 (hid30) */
      0.0, -0.225380, 129,
       &Sources[3741] ,
       &Weights[3741] ,
      },
    { /* unit 130 (out1) */
      0.0, 0.324920, 30,
       &Sources[3870] ,
       &Weights[3870] ,
      },
    { /* unit 131 (out2) */
      0.0, -1.037950, 30,
       &Sources[3900] ,
       &Weights[3900] ,
      },
    { /* unit 132 (out3) */
      0.0, 0.781180, 30,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 133 (out4) */
      0.0, 0.024280, 30,
       &Sources[3960] ,
       &Weights[3960] ,
      },
    { /* unit 134 (out5) */
      0.0, -0.117940, 30,
       &Sources[3990] ,
       &Weights[3990] ,
      },
    { /* unit 135 (out6) */
      0.0, -0.245030, 30,
       &Sources[4020] ,
       &Weights[4020] ,
      },
    { /* unit 136 (out7) */
      0.0, 0.132180, 30,
       &Sources[4050] ,
       &Weights[4050] ,
      },
    { /* unit 137 (out8) */
      0.0, -0.921030, 30,
       &Sources[4080] ,
       &Weights[4080] ,
      },
    { /* unit 138 (out9) */
      0.0, -0.013130, 30,
       &Sources[4110] ,
       &Weights[4110] ,
      },
    { /* unit 139 (con1) */
1.40903, 0.500000, 2,
       &Sources[4140] ,
       &Weights[4140] ,
      },
    { /* unit 140 (con2) */
1.42664, 0.500000, 2,
       &Sources[4142] ,
       &Weights[4142] ,
      },
    { /* unit 141 (con3) */
0.00786, 0.500000, 2,
       &Sources[4144] ,
       &Weights[4144] ,
      },
    { /* unit 142 (con4) */
1.37357, 0.500000, 2,
       &Sources[4146] ,
       &Weights[4146] ,
      },
    { /* unit 143 (con5) */
0.52565, 0.500000, 2,
       &Sources[4148] ,
       &Weights[4148] ,
      },
    { /* unit 144 (con6) */
0.00018, 0.500000, 2,
       &Sources[4150] ,
       &Weights[4150] ,
      },
    { /* unit 145 (con7) */
0.00001, 0.500000, 2,
       &Sources[4152] ,
       &Weights[4152] ,
      },
    { /* unit 146 (con8) */
0.73496, 0.500000, 2,
       &Sources[4154] ,
       &Weights[4154] ,
      },
    { /* unit 147 (con9) */
0.86318, 0.500000, 2,
       &Sources[4156] ,
       &Weights[4156] ,
      },
    { /* unit 148 (con10) */
0.00000, 0.500000, 2,
       &Sources[4158] ,
       &Weights[4158] ,
      },
    { /* unit 149 (con11) */
1.37234, 0.500000, 2,
       &Sources[4160] ,
       &Weights[4160] ,
      },
    { /* unit 150 (con12) */
0.55732, 0.500000, 2,
       &Sources[4162] ,
       &Weights[4162] ,
      },
    { /* unit 151 (con13) */
0.00000, 0.500000, 2,
       &Sources[4164] ,
       &Weights[4164] ,
      },
    { /* unit 152 (con14) */
0.05865, 0.500000, 2,
       &Sources[4166] ,
       &Weights[4166] ,
      },
    { /* unit 153 (con15) */
0.00000, 0.500000, 2,
       &Sources[4168] ,
       &Weights[4168] ,
      },
    { /* unit 154 (con16) */
1.42819, 0.500000, 2,
       &Sources[4170] ,
       &Weights[4170] ,
      },
    { /* unit 155 (con17) */
0.89299, 0.500000, 2,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 156 (con18) */
0.00874, 0.500000, 2,
       &Sources[4174] ,
       &Weights[4174] ,
      },
    { /* unit 157 (con19) */
1.38796, 0.500000, 2,
       &Sources[4176] ,
       &Weights[4176] ,
      },
    { /* unit 158 (con20) */
0.04808, 0.500000, 2,
       &Sources[4178] ,
       &Weights[4178] ,
      },
    { /* unit 159 (con21) */
1.42711, 0.500000, 2,
       &Sources[4180] ,
       &Weights[4180] ,
      },
    { /* unit 160 (con22) */
0.02982, 0.500000, 2,
       &Sources[4182] ,
       &Weights[4182] ,
      },
    { /* unit 161 (con23) */
1.42847, 0.500000, 2,
       &Sources[4184] ,
       &Weights[4184] ,
      },
    { /* unit 162 (con24) */
0.29927, 0.500000, 2,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 163 (con25) */
1.35300, 0.500000, 2,
       &Sources[4188] ,
       &Weights[4188] ,
      },
    { /* unit 164 (con26) */
0.00154, 0.500000, 2,
       &Sources[4190] ,
       &Weights[4190] ,
      },
    { /* unit 165 (con27) */
0.25452, 0.500000, 2,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 166 (con28) */
0.40569, 0.500000, 2,
       &Sources[4194] ,
       &Weights[4194] ,
      },
    { /* unit 167 (con29) */
1.42857, 0.500000, 2,
       &Sources[4196] ,
       &Weights[4196] ,
      },
    { /* unit 168 (con30) */
0.18555, 0.500000, 2,
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
