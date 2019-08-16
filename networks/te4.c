/*********************************************************
  test_new4.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:08:48 2004
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
  static UnitType Units[362];
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
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
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,
Units + 330, Units + 331,
Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242,
Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252,
Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360, Units + 361,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272,
Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282,
Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292,

Units + 233, Units + 302,
Units + 234, Units + 303,
Units + 235, Units + 304,
Units + 236, Units + 305,
Units + 237, Units + 306,
Units + 238, Units + 307,
Units + 239, Units + 308,
Units + 240, Units + 309,
Units + 241, Units + 310,
Units + 242, Units + 311,
Units + 243, Units + 312,
Units + 244, Units + 313,
Units + 245, Units + 314,
Units + 246, Units + 315,
Units + 247, Units + 316,
Units + 248, Units + 317,
Units + 249, Units + 318,
Units + 250, Units + 319,
Units + 251, Units + 320,
Units + 252, Units + 321,
Units + 253, Units + 322,
Units + 254, Units + 323,
Units + 255, Units + 324,
Units + 256, Units + 325,
Units + 257, Units + 326,
Units + 258, Units + 327,
Units + 259, Units + 328,
Units + 260, Units + 329,
Units + 261, Units + 330,
Units + 262, Units + 331,
Units + 263, Units + 332,
Units + 264, Units + 333,
Units + 265, Units + 334,
Units + 266, Units + 335,
Units + 267, Units + 336,
Units + 268, Units + 337,
Units + 269, Units + 338,
Units + 270, Units + 339,
Units + 271, Units + 340,
Units + 272, Units + 341,
Units + 273, Units + 342,
Units + 274, Units + 343,
Units + 275, Units + 344,
Units + 276, Units + 345,
Units + 277, Units + 346,
Units + 278, Units + 347,
Units + 279, Units + 348,
Units + 280, Units + 349,
Units + 281, Units + 350,
Units + 282, Units + 351,
Units + 283, Units + 352,
Units + 284, Units + 353,
Units + 285, Units + 354,
Units + 286, Units + 355,
Units + 287, Units + 356,
Units + 288, Units + 357,
Units + 289, Units + 358,
Units + 290, Units + 359,
Units + 291, Units + 360,
Units + 292, Units + 361,

  };

  /* Weigths definition section */
  static float Weights[] =  {
0.411600, -1.187000, -0.519400, 0.479200, 0.548760, 1.701390, -2.911620, 0.611270, 0.675000, 1.008800,
0.320420, -0.998390, -0.183810, 1.062390, 0.602320, 0.285170, -0.552780, -1.075920, 1.042280, -0.286990,
0.525290, -0.680760, -0.838890, 1.050130, -0.895110, -0.616530, -0.793330, -1.658420, 0.977120, -2.003910,
-2.418250, 1.117190, 0.499260, -1.044070, -1.104830, -2.094330, 2.109800, -3.080590, -2.158800, 0.882370,
1.150850, -0.578390, -0.616200, 1.089800, -0.561110, 0.648880, -0.084180, 1.105080, -1.500160, 0.214730,
-1.430970, 0.793110, -0.845500, -0.179370, 1.654740, 1.325350, 0.164650, -0.038690, -0.544080, 0.710360,
1.367240, 3.851730, -1.318340, 0.033200, -0.130250, 0.870440, -2.025940, 0.195760, -0.458940, 3.217060,
3.013730, -1.337190, -2.425950, -0.785880, -0.211840, 2.055540, -0.689370, -6.379590, 0.433150, -2.649340,
1.867250, 2.608170, -1.401330, -2.441010, -1.482670, 2.014710, 2.537420, -7.607630, 0.403560, 1.406490,
6.833070, 7.537030, 1.135250, 2.378820, 2.457680, 0.346280, 1.817760, 1.639590, -6.480770, -0.304790,
-8.759220, 6.072720, 4.843360, -5.632830, -0.687900, -0.214000, 2.141820, -1.183530, -1.752810, -0.476870,
0.527890, 4.635220, 3.934180, -0.239880, 2.822640, 3.683550, 3.323740, 6.308160, 0.953340, -15.303740,
-2.367530, -3.270330, -0.282630, 0.438560, -6.770430, -0.201750, 4.108810, -0.030250, -0.381760, 0.627440,
0.208940, 2.355630, -0.747710, -0.456470, 3.081820, 1.583970, -0.419610, -0.089080, -1.332510, -0.400680,
-6.127690, -0.710780, 0.389910, 2.325120, -2.102630, 0.934510, -2.102510, -0.119970, 1.525390, -2.374500,
1.277000, -0.616190, -0.984180, -2.958090, 0.065930, -1.202810, -0.479310, 1.673090, 1.437920, -0.765380,
1.396490, -1.385840, -0.678820, -0.595640, -1.459620, 0.593560, -1.241230, -0.155730, -0.790600, 0.928530,
-1.624260, 0.380240, -1.732810, 0.437300, -1.182050, 0.564580, -1.163590, -1.046730, 3.870340, 0.161800,
-2.813830, -1.935560, -0.073000, 0.841810, -1.614450, 0.781390, -1.495690, 2.576770, -1.313840, 0.895130,
0.075220, 0.149600, 3.123790, 0.035930, 1.002270, -1.357520, 5.867190, 0.586250, -1.216230, 0.679090,
0.102490, -0.574750, 0.975340, -0.533500, 0.329590, 2.146910, 0.672000, -0.701390, 3.819230, -1.237710,
-0.041300, -0.069680, 0.203930, 0.810910, 0.787920, -0.455550, -0.757680, -0.300550, -2.240240, -1.699780,
2.055020, -0.117640, -3.319990, 1.301500, 0.346030, 0.685780, 0.511320, 0.223110, -0.335140, 0.107120,
-1.024370, 1.098190, -0.791270, -1.124580, -0.896870, -1.246410, -0.071730, 0.724590, 0.976670, -1.011670,
-0.400550, 0.599280, 0.251150, -0.072530, -0.323280, 0.261030, 0.797900, -1.605070, -0.202860, -0.401180,
-0.439350, 0.535440, -0.002000, 0.876800, 0.836760, -0.332250, -0.566210, -0.418090, 0.485860, -1.212280,
-2.491130, 0.943070,
0.349240, -0.630490, -1.404900, 1.522840, 0.577360, -1.115440, 1.351530, -0.404800, 0.364920, 2.341210,
-0.254750, -0.106180, 0.632020, 0.621110, -1.704490, -0.416550, 1.104910, -0.129580, 0.101630, -3.816730,
0.835490, 0.639520, 0.653520, 2.506600, 0.017180, 0.208790, 0.828420, 0.556020, 0.100730, 0.565040,
-0.708000, 0.808770, -0.083290, 3.029260, 1.752120, -1.490330, -0.856350, -0.905380, 1.478000, 0.767010,
-0.948230, 0.669970, -0.908370, -0.108000, -0.753890, -0.759150, 1.706840, -1.480760, 0.219320, -0.617280,
-0.701560, -1.408060, 0.530000, 0.884670, 1.166880, -0.306300, 0.031720, 1.704140, 1.119540, -0.053220,
-1.301380, -2.839670, 1.390280, 1.713630, -1.947730, -0.542200, -0.338830, 2.661470, 1.976330, 0.232130,
-1.019140, 0.421170, -1.036710, -1.040950, -0.760490, 3.723790, 0.444550, 1.474590, 2.149260, 2.458060,
0.998860, -0.192350, -3.807620, -0.107930, 1.948940, 0.374140, -1.140110, 0.105730, 0.764340, 2.740380,
4.176640, -1.067940, -0.659050, -0.016100, 0.129850, 2.866200, 4.015960, -0.178880, 0.191790, 0.371140,
2.415060, 0.623170, 0.749600, -2.410750, -0.142870, -2.410220, 0.154410, -1.999810, 1.041220, -0.224040,
-1.196880, -0.751780, -1.693100, -1.464950, -0.677340, 0.109200, 4.663960, 3.000940, 0.302430, -2.615470,
-1.208160, 0.542860, -0.033190, -1.420450, 1.032700, 0.934230, -0.535040, -1.460010, -1.898030, 3.683320,
-0.280470, -2.765620, -2.446990, -3.515260, 1.266750, 0.566590, 1.827810, -0.841440, -0.956120, -1.712500,
1.899710, -2.388470, 5.974850, 0.939370, -1.771910, 1.399970, -0.734920, 1.170820, -1.219170, -0.596320,
2.215270, 1.228200, -0.319200, -0.229210, -3.222880, 2.099860, 0.031980, -2.902650, 0.076860, 0.532930,
0.179390, 2.005290, 0.741860, 3.056830, 1.119000, -1.696640, 2.543540, 2.298760, -2.008410, -0.272140,
-1.891620, 0.978470, 1.665460, -0.814530, 1.111630, -2.796790, -0.188100, -1.642100, 1.172210, 0.836520,
0.208570, 0.584180, -0.050740, -1.379500, 0.240590, 0.307620, 3.675470, 0.134590, 2.400190, -1.364520,
0.085920, 1.221830, 1.545490, -0.761510, 0.810260, 1.990910, -1.306600, 1.519330, 0.238710, 1.035720,
2.318970, 0.575580, 0.632630, -0.728510, 2.534960, -3.870830, 0.229830, 0.169860, -3.267200, -0.540250,
0.534700, -0.278030, -0.430640, -0.533390, 0.394770, -0.427650, 0.773830, -0.355570, 0.507950, 2.762640,
0.282660, -0.214380, 1.215880, -0.868550, -0.585590, -0.788770, -0.266830, 2.462070, -1.422130, -0.841620,
1.058830, 0.700340, -1.149610, -1.529400, 0.369430, -0.147890, -0.385640, -0.969810, 9.245870, -0.224470,
-0.027520, -0.671290, -1.145350, -0.324340, -0.078220, 1.044760, -0.014260, 8.974870, -0.852840, -0.071620,
1.178170, 1.106510, -0.518060, -4.877040, -0.232220, 0.051880, 0.845380, 0.868250, -1.652000, -0.775050,
-1.305690, -1.090640,
1.955880, 0.958560, 2.018730, 0.671380, -1.466530, -1.694340, -0.006130, -0.946460, -2.056250, 0.798520,
1.700760, -1.161400, 0.292190, -0.386720, 0.938720, 0.611300, -1.046370, -0.620700, -0.071940, 0.184150,
-0.501230, -0.294940, 0.770500, -1.340020, 0.582060, -0.008980, 1.282830, 0.736940, 1.758830, -1.246160,
-1.079820, -0.474120, -0.816180, -1.301460, 0.059860, -0.431650, 0.832200, -0.239400, -0.807280, -0.875350,
0.981780, 0.855240, -1.271970, 1.113550, -0.851980, 0.077800, -2.756620, 2.099320, 0.265300, -0.295530,
-0.287380, -1.619190, 1.613890, -0.535790, -0.269060, -0.691100, 0.017930, 0.535930, -0.270480, -0.042260,
-1.979550, 0.206430, 1.672030, -0.109730, -0.374760, -3.248180, -2.761280, -0.385920, 1.740590, 0.326090,
-2.061230, -0.780510, 0.574190, 4.576710, 1.378210, -1.954800, -2.200040, 0.563190, 0.509590, -2.844730,
2.654130, 0.810480, 1.709270, 0.532220, 2.121660, 0.439930, 1.370170, 2.871670, -0.235970, -1.807070,
-2.285510, -2.435150, -0.336650, 0.054960, 1.290460, -1.701800, -1.714360, -0.012350, 1.057920, 0.799400,
2.821280, -1.381460, -1.007500, -4.516490, 0.388480, 4.195870, -4.002750, 2.896830, 7.373960, -1.543490,
3.399180, -1.798350, -4.842790, -2.375090, -1.252880, -0.269550, 0.773590, -1.468650, -1.216400, 3.520380,
0.036470, 3.868620, -1.242760, -2.344010, -0.006510, 0.704510, 0.486890, 0.317150, 0.386790, 1.527680,
-0.197990, -1.137420, 0.674840, -4.749070, -0.184470, 1.570400, 0.605070, -1.058980, -0.751330, 0.120350,
7.570790, 0.200960, 3.191490, -1.125950, -2.464450, 4.416710, -0.122630, -0.492330, 1.168160, -1.192700,
1.352950, -0.733260, -1.492230, 0.213480, -0.630790, 1.110310, 0.064630, 1.198760, 0.368560, -0.546300,
-0.218030, 6.850450, 0.308140, 4.158840, -1.273100, -1.305020, 7.040750, -0.823750, -2.623470, -1.312430,
0.981110, -0.194070, 0.440370, -0.388560, 0.149280, -0.147050, 1.065900, -1.218680, 0.256260, 0.663550,
1.219660, -1.759080, 3.741850, -2.186360, 3.406690, 0.006250, -1.601460, 2.036880, -0.225590, 1.044320,
-0.940890, -0.704220, 0.217380, 1.930830, 0.014140, 0.878650, 0.145910, 1.982840, -2.577040, 0.936840,
0.268320, -2.425820, 0.905950, 2.290910, 0.692010, 0.250970, -0.899460, 1.554280, 0.446900, -0.115270,
-0.826410, -0.193640, 1.065990, -1.022040, 0.262500, -1.068760, 0.030850, -2.294040, 0.212690, -2.393950,
-1.062690, 0.346080, 0.646630, 1.159010, 4.099570, 0.445570, -0.070800, 0.357720, 0.724050, -0.870780,
1.060600, 0.525790, -0.994850, 1.490790, -0.673640, -1.589040, -0.923790, 0.354380, -2.938940, 0.205720,
-0.183990, -0.027910, 0.594750, -0.179480, -0.438580, 0.781000, 0.518730, 0.638150, -0.607320, -0.936160,
0.594930, -1.015660, -1.762670, 0.715310, 0.497580, -0.704750, -1.461870, -0.395580, 0.455100, -1.267710,
-0.621650, -0.215970,
-0.594280, -0.354580, 1.263930, 2.104550, -2.105140, 0.467440, 0.332340, 0.104700, 0.115130, -0.479620,
0.838760, 1.958900, -0.046340, -0.623040, 0.334170, -0.946970, 0.326810, -0.092060, -1.744280, 0.618670,
0.720110, 0.378810, 0.712250, 0.486680, 0.494450, 0.200020, 0.745990, -0.205770, -0.783240, -0.576210,
0.295100, 0.648720, -0.803780, -3.722090, 0.584730, -0.177990, 1.077650, -1.251930, 0.428030, -0.546920,
1.583270, 0.806420, 2.403250, 0.011890, 1.676130, -0.973810, -0.283100, 0.176620, 0.620330, -0.473980,
0.033420, 1.066400, 0.607790, 1.504490, 0.493180, 2.573660, -0.372230, 2.365150, 1.695620, 0.201290,
0.714230, -0.439200, 1.121640, 3.128510, 1.799580, 0.902380, -0.661750, -0.159050, 0.734810, 1.066640,
-1.699540, -0.750490, -1.409540, -0.355070, 1.024950, 0.836850, -0.143240, 0.286420, 0.181380, 1.771360,
0.171030, 0.423200, -1.852160, -1.402420, 1.227400, 0.005500, 0.900500, 0.056880, -1.906490, 0.510420,
2.680440, -3.192210, -3.102650, -1.789310, -2.359930, 0.230570, -1.036630, 2.820230, 2.738130, -0.943380,
-0.485630, 1.878650, 1.516760, -5.936170, 0.148810, 0.431450, -1.814740, -1.930900, -2.215090, 1.250280,
-1.288860, 2.655820, -0.828170, -0.221350, 0.416950, -0.664520, 3.638010, 4.335650, 3.018300, 2.007650,
-1.405240, -0.303970, 0.408070, 2.879150, -4.552210, 0.689820, 0.893680, 4.365320, -1.054370, -1.239580,
-0.162620, 2.104750, 3.307390, -2.531870, 0.929300, 2.175300, -1.660940, 2.062530, 7.076230, 2.238700,
-6.199000, -1.483440, 1.228030, 1.201450, 0.999970, -4.697770, -0.620680, 2.519320, -2.689320, 0.301620,
4.593440, -0.097380, 0.381670, 1.702830, -2.326220, 0.371120, 1.920370, -0.237780, 1.567320, 4.813860,
2.071060, -6.592430, -2.487160, 2.267570, 0.133830, 0.740210, -1.046070, 0.006550, -1.232000, 0.870330,
-0.550300, 1.108120, 0.817120, -0.412240, 1.260050, -2.345500, 1.599610, 2.286340, -0.211020, 3.585680,
4.404800, -0.238520, -9.001790, 1.496090, 0.659720, 1.517360, 0.145660, 0.999620, -0.628290, -1.115280,
0.947450, 0.646700, 3.458620, 1.633130, -0.608270, -0.366900, -4.428440, -0.633410, 0.581780, -0.688530,
1.904730, 1.033700, -0.583940, -1.400880, -1.944770, 1.753280, 0.125510, -0.865930, -0.152890, -0.936270,
-0.013140, 1.829560, -1.512460, -0.886610, 4.211220, 2.321850, 1.228690, -4.325910, -0.507320, -0.769860,
0.033810, 2.776380, 5.867240, 0.416870, -1.448950, -0.772080, -1.059570, 1.538160, 0.871630, -0.435930,
-3.310110, -0.828250, -0.157140, -0.601130, 0.064690, -0.922950, 0.629380, 0.958380, 2.014970, 0.319470,
-0.148640, -0.401970, 0.317990, 0.613280, -0.867320, 0.391430, -0.567450, 0.975150, 0.536240, -0.647270,
1.819930, -0.947090, 0.737330, -0.895750, -0.610640, 0.052230, -0.452400, -0.570360, -0.899770, -0.436230,
-0.170290, -0.059500,
-0.087980, -0.687750, -0.206450, -0.668550, 0.832810, 0.465670, -0.228910, -1.526350, -1.723340, -1.321280,
0.035970, -1.538730, 0.144540, 1.063510, -0.888560, 0.507350, -0.689690, 0.259410, -0.499310, 0.606480,
-1.271660, 1.849770, -0.557130, -0.466970, 0.459920, -0.101790, -2.861950, -0.888910, -0.564820, -0.312600,
0.340370, 1.571440, -1.707590, 0.317040, 0.991450, 0.697010, -0.009420, 0.700840, 1.676260, -0.594180,
0.030130, -1.331200, 0.143740, 0.357320, 1.039830, 0.835100, -1.677090, 0.605190, 0.303780, -1.587980,
-0.225910, -2.297600, -0.666130, -0.514570, -2.556970, -4.724740, 3.806190, -0.994890, 0.400210, -0.449300,
-0.263000, 0.988620, -0.974230, -0.610100, -1.536650, -0.382270, 0.702940, -0.202020, -0.235980, -1.502520,
-1.043510, 1.478380, 0.757830, -0.939740, 0.735060, -1.186410, -1.059930, 2.126750, -0.877060, -1.108850,
0.095840, 0.746610, 1.801970, -0.843630, 1.997500, 0.376970, 1.533380, 0.146970, -2.100030, -1.203860,
-0.662960, -0.225450, -0.028260, 0.326640, -0.283510, -2.295120, -1.241390, -0.351350, 2.745600, -0.585430,
-0.508070, -2.194650, 0.683000, 1.461060, -1.111350, 2.226380, 1.017230, -1.224070, -2.116830, -2.749060,
0.831470, -0.731500, 1.011100, 0.856050, -0.450460, 1.187910, -0.712300, -1.747160, 2.371160, 2.110550,
0.878290, -3.043650, -0.358450, 1.189760, -4.981950, -0.239180, -0.947550, 0.537810, -0.898750, -6.136300,
-0.381660, 0.445090, 3.215070, 0.789800, 0.344480, 1.745150, 0.229060, 1.805030, 6.210050, 3.336560,
-4.719550, -1.348320, -3.416830, 1.894520, 3.074550, -6.837710, 0.091150, -0.129470, 3.158560, -0.374690,
-3.719510, 0.491000, 1.285230, 5.513890, 0.555910, 0.797270, 2.178720, 0.616070, 4.680240, 5.857930,
0.901470, -10.780720, -1.044540, -1.032380, -2.168500, 2.995850, -0.916670, -0.932710, -0.481570, -0.787130,
1.001270, -1.123750, -1.991990, 2.175790, -0.434570, 1.593230, 0.833610, -0.299630, -0.165790, 0.683490,
3.215840, -0.795200, -5.993050, -2.406920, -2.383680, 0.911390, 1.192810, -3.573100, -1.458950, 1.896880,
-0.467550, -2.892040, 0.038970, -0.108160, 0.770590, -1.308400, -0.692880, 0.314300, 1.096770, -0.232240,
1.042210, 7.090760, -1.572730, -5.459970, -0.286630, 0.000080, 0.975060, -0.626790, -2.560710, -0.041400,
0.713940, 0.756680, -0.493900, 1.812660, 1.849670, 0.812530, 0.261740, -2.802660, 0.828490, -0.976610,
-0.019450, 1.753180, 1.527850, 0.739310, -6.088400, -0.208330, -0.037510, 0.746420, 0.072970, -0.183710,
-0.444280, 0.608570, 0.332890, -0.463930, 0.166910, -0.739050, -0.020650, 0.957780, 4.459060, 0.912070,
0.032260, -0.772230, 0.336460, -0.267460, 0.893130, 0.952750, 0.534130, 2.917390, -0.372360, -0.310750,
0.209170, -0.012460, 0.549090, -0.585460, -0.847460, -0.548990, 0.319080, -0.507320, -0.080960, 0.838000,
-0.285870, 0.636120,
0.401550, 0.908960, 0.054950, 0.709800, 1.202720, -1.666030, 1.023160, -1.761320, 0.793860, -1.184790,
0.023330, -0.692080, -0.029430, 0.776140, 0.791390, -0.113570, 0.742900, 2.625050, -0.020750, 1.888290,
-0.176360, 1.842660, 0.236580, -0.423780, 0.822530, 0.125700, 1.002310, -0.219050, -2.440170, 1.119840,
-0.092070, -1.324830, 0.995950, 1.080610, -1.373680, 2.258150, 1.067040, 1.844410, 0.177270, -1.438710,
0.405660, -0.893410, -0.296170, 1.592530, -0.998080, 2.292740, -1.368900, -2.664340, 0.686760, 0.697200,
-0.306440, -1.952690, -0.194140, -0.320270, -0.022060, -0.640970, -0.200160, -3.460170, 1.443780, -1.605990,
0.176950, -0.499800, 1.958770, -2.379620, -1.711290, -1.526960, -1.767990, 1.195370, -0.023160, 0.147150,
1.355640, 0.526790, -2.790210, 1.381000, -1.729510, -0.833680, -0.183400, -0.524930, -0.540700, -0.361070,
0.250250, 1.289330, 0.449930, 0.488140, 0.550370, 0.285880, -1.138210, 0.361220, 1.986510, 0.827800,
2.817380, -0.703990, 1.003670, -0.319040, -1.552160, -0.218210, -0.238610, -1.039710, -1.996390, -1.026960,
0.637990, 1.892580, 1.412930, -0.133860, 1.577300, 0.882720, 2.541930, -0.904010, -0.793570, -0.495470,
1.832020, 2.138340, 0.650060, 0.650510, -0.616950, -0.236950, 0.735540, 2.096780, -0.123790, -0.980610,
0.661840, -1.393650, 0.416950, 0.000000, -1.230220, 0.787910, -0.210360, -0.623680, -0.789720, -4.223810,
-0.982890, 3.614100, -1.083510, 3.922960, -0.616300, 0.997680, 0.484000, -2.310520, 0.427030, 0.568950,
-3.770560, -1.181050, -3.376940, -1.698850, 0.836310, 0.291270, 0.491260, 1.279620, 1.237240, 0.084200,
-0.016010, 1.033210, 0.584940, -0.041010, 1.190480, -0.227370, -0.908970, 0.765680, -0.958840, 0.743260,
0.613030, -0.633350, 0.514560, -1.826350, 0.486260, 0.493340, -0.126490, 0.681180, -1.351910, -0.350720,
-0.330520, 1.433500, 1.115710, -0.929150, 1.092930, 3.931770, 0.223200, 0.737100, -1.208410, -0.475770,
-2.167250, 0.971270, 2.088120, 1.609150, 0.381410, 2.794980, 0.403770, -0.636270, -0.588780, -0.239980,
0.999400, 1.007660, -0.661330, -0.736160, 0.566440, 0.685660, -0.916230, -0.890260, -0.287170, -0.714340,
-0.979720, -2.181910, -1.279120, -0.042670, -0.326230, 1.355920, 0.598780, -0.518270, 0.580050, 0.022290,
-0.148650, 1.035260, -0.424870, -0.546950, 0.332140, 0.227490, -0.393830, 0.403850, -0.481780, 1.031920,
1.208710, 1.456050, -2.166760, -0.412180, -0.020750, 0.956490, 1.716880, 0.223440, 0.631850, 1.739030,
-0.478500, 1.513320, -0.150130, -1.841100, -0.822720, 1.503430, -0.629720, 1.491600, 0.397540, -4.621520,
-0.377410, -1.301610, -0.378260, -0.029970, 0.259030, -0.556100, -1.936650, -1.578580, -1.202410, -1.329420,
-0.403730, -0.498460, -0.945760, 2.156430, -0.960270, -1.959530, -1.408960, -0.047290, -0.841860, -0.474010,
-1.957410, 1.079030,
-0.548340, 0.169500, 0.632940, -0.112110, -0.415470, 0.573980, 0.036020, 0.615010, -0.409100, -0.662280,
-0.107190, -0.538980, 0.456660, -0.407360, -0.341050, -0.193240, -0.538030, 0.817050, -0.112070, -0.158340,
-0.775710, -1.173350, 0.087470, -0.402710, 0.407400, 0.297330, 0.044140, 0.736200, 0.661040, 0.565510,
0.456610, 0.317820, -1.374830, 0.330610, 0.061950, 0.397630, -0.371570, 0.193590, 1.438840, 0.073930,
0.099540, 0.170270, -1.333170, 1.189700, 1.085850, 0.269310, 0.194650, -0.237260, -0.049510, -0.319530,
-1.221490, 0.486880, 0.161890, -0.872320, 0.899460, -0.551620, -0.036460, -0.372800, -0.023120, -0.540190,
-0.368000, -0.565870, 0.776520, -0.067010, -0.327140, 1.150400, 1.194020, -1.332690, 0.558440, -1.063150,
0.259850, -0.399100, 0.265330, 0.100560, 0.165860, -1.608930, -0.988980, 0.273180, -0.475570, -0.212790,
0.007850, -0.599590, -2.024470, -0.420260, -0.854260, 0.363700, -0.387330, -0.069590, 0.306730, -0.410540,
-0.816330, 0.292290, 0.303700, -0.140430, 1.074550, -0.235050, -0.356370, 0.579140, 1.716020, 1.425570,
0.062210, 0.827590, -0.073140, 0.235480, 0.135480, 0.630760, 0.342890, -0.437080, 1.928440, 1.556610,
0.987080, 2.991070, 0.027390, 1.122010, -1.375000, -0.868750, -0.679190, 1.562670, 0.513100, 0.598210,
-0.521210, 2.361570, 1.506490, 0.055860, 0.393840, 0.593140, -1.140930, 0.025900, -0.959760, -0.153940,
0.413350, 0.285070, 1.253540, 0.588120, -0.253740, -0.330180, 0.477000, -1.173790, 0.426900, -0.623170,
-1.561650, 0.473530, 1.004900, -0.146700, -0.775140, -1.542790, 0.176490, -1.176310, 0.731900, -0.333510,
0.751920, -2.750950, -0.919980, -0.100130, 0.095680, -0.424620, 0.934490, 1.315150, 0.886000, -0.044250,
-0.767550, -1.195580, 0.980120, -1.225620, -0.184360, 0.382750, -0.447830, -0.824530, -0.138150, -0.819200,
-0.095360, 0.648790, 0.029040, -0.278680, 0.866460, 0.247010, 0.891370, 0.455630, 0.557100, 0.277120,
0.393520, -0.161140, 0.538380, -0.374520, 0.244540, 1.231550, -0.503990, -0.007860, 0.380430, -0.000860,
0.568610, 0.151930, 1.819310, 1.964900, -0.028320, 1.473290, 0.349710, 1.018390, -0.130560, -0.379650,
-1.016600, 1.028310, 0.135040, -0.353080, -0.278700, 0.964080, 2.053820, 0.695340, 0.925990, 0.009610,
1.022070, -0.558860, -0.618530, 0.462490, 0.403750, -0.160130, -0.219640, 0.503620, 0.193770, -0.715220,
-1.029380, 2.283730, -0.880250, 0.889510, 1.180250, -0.569660, -0.047100, -0.874900, -0.275670, 0.182190,
1.062480, 1.049260, -1.339010, 0.136660, -0.718450, -0.040180, -0.587760, -2.097090, 2.099460, -1.379000,
-1.130070, -1.455090, -1.570540, -1.503210, -1.127350, -1.913990, -0.531210, -0.735060, 0.137600, -2.283250,
-1.318220, -1.188650, -1.378770, -5.184280, -2.416600, -0.691600, -1.381400, -2.842570, -1.037220, -1.007180,
0.077150, 0.060450,
0.820470, 0.773650, -1.320660, -1.349260, 0.312970, -1.120130, 0.054530, 0.048300, 2.038990, 0.214900,
-0.759000, 1.617020, -2.303430, -0.273640, -1.296790, 0.271640, -1.288420, 0.589710, 0.424480, 0.180860,
0.369860, 1.792580, -0.510680, 0.604080, 0.299580, 0.084830, 0.258780, 0.754380, -0.068990, -0.004100,
0.630140, -0.112170, -0.452060, 0.405130, 1.736530, -0.230290, -0.828340, -1.244640, 0.557240, 0.321570,
-1.739520, -1.052290, 1.435540, -1.322180, 0.752180, 0.513510, -0.350940, -0.478650, 0.458640, -2.455860,
-0.428660, -0.388180, -0.156950, -0.819510, -0.297920, 0.458950, 1.177310, 0.498630, -0.959680, 0.725660,
-1.566620, -3.038490, -2.555210, 0.324320, -0.328940, 0.884560, -0.722270, -1.715460, -2.605350, -1.049940,
-3.619270, 0.821460, 0.834090, -0.530050, 0.428330, -0.689730, -1.079940, 0.357760, -2.358230, 1.497020,
-0.335800, -1.145430, 0.834090, -2.792100, -0.385930, -1.478800, -2.394880, 0.326550, -1.373210, -4.980830,
-2.885110, -1.390980, 0.363300, 0.541170, -3.933920, 0.815950, -0.543250, -2.021800, 2.866510, -1.039560,
-0.530210, 1.551740, -1.123050, 1.770450, -0.430190, -0.236260, 0.593570, 1.184360, 0.165970, -1.393180,
-4.148050, -2.230350, -1.608400, -0.342030, -0.598580, -1.400590, 3.056880, 0.265130, -1.833150, 2.824390,
-0.766060, 1.464020, -0.516010, -0.196570, 1.524350, -1.262320, -0.112380, -0.641310, -0.440490, 1.036000,
-0.140650, 0.540710, 0.839790, -1.370020, -0.009980, 1.200470, -0.992700, 0.279010, 1.186490, -0.494970,
1.326000, 1.112310, 0.003210, 1.097360, 1.805870, 1.947560, 0.239040, 0.193200, -0.032190, -1.149710,
0.991680, -0.094200, -1.388330, -0.034840, -3.503020, 1.231660, -0.727620, 0.358210, 0.147600, 1.970000,
0.471010, -0.884800, -1.391990, 0.203510, 1.678430, -0.827920, -0.970270, -1.039180, -1.271580, 0.053760,
-0.936890, -1.362940, -0.761070, 0.447320, -0.915760, 0.374070, -0.864710, -0.332790, 1.877800, 0.488590,
3.009860, -0.252660, 0.377860, 0.857940, -2.190790, 1.048370, 0.109220, -2.240340, -0.023390, 0.927980,
0.793890, 1.697150, -2.440220, 0.148220, 0.829830, 0.260470, -0.126960, -0.638580, 0.372020, 1.393640,
1.427930, 0.598160, -0.060430, -0.199220, -0.199610, -0.412640, 0.241920, -0.157530, -0.965550, -0.333730,
-4.560090, -0.028110, -1.507160, -2.371830, 0.634440, -1.814460, -0.195950, -0.338990, -1.626360, 2.526640,
0.361730, 2.471590, 1.550040, -1.113410, -5.982490, -0.848520, -4.103920, 0.153120, 1.316140, -2.996760,
2.176340, 2.236280, -0.513600, 1.215320, 1.120100, 0.251580, -0.789380, 0.576060, 4.875550, 1.120210,
1.039780, 0.258910, 0.159150, -0.390840, 0.468130, 0.709340, 0.693080, 0.043500, -0.227990, -0.007350,
0.218470, 1.261840, 0.950630, -0.904530, -0.236130, -0.046730, -0.789160, -0.661790, -0.116560, -0.490520,
0.460680, 0.081050,
-0.217800, 2.159100, -0.182770, 0.571340, 0.375260, 0.247350, 0.387470, 0.692760, -0.574660, -0.393110,
-1.448830, 0.250030, 1.114920, -1.049780, 0.679720, 0.315920, -0.605640, 0.393890, -0.826870, 0.874590,
-0.758430, -1.108430, -1.216740, -0.257290, 0.801670, 0.227950, 0.231840, -0.317400, -0.508500, 0.360090,
-1.307940, 0.135340, -0.870980, -0.593770, -0.174260, -2.505420, -0.672100, -0.941730, 1.573680, 0.301580,
-0.069570, -0.170230, -1.322900, -1.825110, -1.897370, -1.802210, 2.071400, 0.250820, -1.289870, -1.186160,
0.531440, 0.758320, -2.477690, -1.902720, -0.599700, 0.614250, -1.029450, -0.794770, -1.528130, -1.613980,
-3.364800, -2.672060, -0.593740, -0.982940, 1.195350, -0.590600, -1.853130, 1.218180, -1.332710, 3.430130,
1.032330, 0.738910, 1.878460, -1.638580, 2.136420, -0.602920, -0.781520, -1.617010, -1.713330, -0.285990,
0.897430, 0.812750, -5.267640, -0.864940, -1.851320, -0.169160, -0.131940, -2.114540, -0.838590, 2.222110,
3.745780, 1.782590, 0.006720, -0.636290, 0.205740, 0.120080, 1.255940, -0.165640, 0.292140, -0.577660,
-0.454370, 4.745230, 0.173890, -7.640740, -1.460800, -0.737220, -0.551440, -2.329240, 1.754900, 0.824210,
3.266490, 0.326390, -0.973310, 1.070700, -0.233000, -0.189940, 0.308970, -0.384070, -0.955800, -1.096930,
1.462200, -0.879890, 0.794380, 0.376830, 0.600540, -1.316410, 1.057070, -0.031700, 2.904680, 3.743280,
-2.453840, 0.976840, -3.935610, -5.003780, -0.521420, 0.615630, 0.207540, 0.465450, -1.219610, -1.271730,
1.861810, 0.988790, 1.327000, 0.365650, -4.331500, 6.370860, -0.840610, -0.673440, -1.308990, 0.893360,
1.853160, 0.131040, -1.991420, -4.218950, -1.960730, -1.796980, -0.666310, -0.990020, -0.821810, -3.182550,
-1.242310, 6.702010, 0.286220, -0.691860, -1.958060, -1.783100, 8.763860, -0.716010, 0.008750, -1.036010,
1.484060, 1.933000, 1.532140, -2.035970, -0.009730, -0.694500, -2.115710, -1.070200, -0.343040, -1.696410,
-0.876500, 0.707630, 5.311680, 0.948730, 1.432330, -0.880810, -3.801180, 5.494740, 2.718020, 1.776370,
0.066610, 0.344050, 0.176430, 0.023900, -0.234940, 1.656640, -1.258550, -1.654900, -1.076430, 0.510150,
-0.664830, -1.746680, -2.108010, 5.143380, -1.627340, 5.353460, -0.123590, -1.271950, 2.706330, -0.358920,
0.331550, 0.205350, 1.508080, -0.361490, 0.092510, -0.154640, -0.345560, 0.993780, 0.353680, -0.236610,
-0.319950, 0.502740, -1.053670, 1.332310, 1.153020, 1.111040, -1.085050, -0.648070, -0.903740, -0.654770,
-1.219460, 1.978630, 0.152180, 1.615000, -0.142360, -0.385040, -0.556020, 0.584570, 2.518440, 0.779110,
-1.095780, -0.567360, -0.341510, 0.646670, 0.346470, -1.168900, -1.358420, -1.158800, 0.283730, 0.369090,
-0.122450, 0.380400, 0.531710, -0.428690, -0.205620, 0.485580, -0.289930, 0.714860, 0.898420, -0.493610,
-0.115010, -1.282670,
0.303040, 1.057160, -1.700650, 1.196670, 0.324950, -2.369580, 0.647820, -1.003350, -0.233650, -2.137130,
1.995100, -3.187900, -0.080210, 1.476490, 0.198070, 2.011960, 0.103470, -0.021700, -1.397300, -0.775620,
0.864490, 0.527140, 1.635760, -0.631340, -0.680810, -1.629240, 1.088040, -1.186340, -0.577970, -1.611490,
1.460520, 1.806100, -0.364400, -0.202080, 0.400640, -0.309750, 1.107750, -0.904580, 0.730100, -1.151110,
-0.436040, -0.991210, 0.411830, 0.729760, 1.736500, -1.193790, -3.340330, 1.212410, -1.513360, 0.553550,
-2.485110, -1.525860, -0.501010, -0.979150, -1.361080, -0.519960, -0.736190, 0.712140, -3.587140, -1.562090,
-0.064650, -0.664880, 0.953760, -0.806580, 2.342130, 0.976080, -1.978670, -2.961020, 2.186750, -0.069890,
1.210510, -3.409870, 0.641100, -0.207710, -0.014380, -0.842720, 0.745500, -1.820290, -3.344240, -4.082790,
-8.776220, 6.043950, 1.173820, 0.569200, 0.230520, -0.993020, 2.121540, 0.976680, -0.597090, 2.151720,
-1.176890, 1.531810, -2.796940, -1.385800, -0.126170, -0.227390, -1.355260, -2.293380, 0.626980, -0.042330,
0.036250, -1.509590, 0.147960, 0.539370, -0.153340, 1.365020, -0.200000, -0.826660, -1.244390, -1.826050,
0.910780, -1.645650, -0.677030, -0.965560, -0.399360, -0.319360, 0.600310, 0.026730, 1.352670, 4.282510,
-0.294450, 0.033790, -0.608900, 0.365630, 1.524910, -0.549910, -0.445220, -1.077140, -0.746580, 1.077290,
1.251470, -0.383340, -0.447630, -2.358000, 1.440900, -0.339370, -0.716210, 0.385200, -0.526200, 0.782600,
1.320960, 0.281850, 0.642750, 2.124890, 1.052890, -0.184390, -0.877290, 0.467350, 0.289860, 2.035130,
-0.086900, 0.796170, -0.718340, 0.194570, 0.198450, 1.729300, -0.745970, -0.020730, 1.494610, 3.140960,
-1.559420, 0.858980, -0.343660, 0.742250, 0.815740, 0.497120, 1.059540, 0.163840, -0.453800, 1.391210,
-0.350260, 1.096980, -0.172190, 0.045840, -0.864760, -2.357250, 1.592710, 1.725290, -0.136740, 1.232980,
0.066200, -1.855270, -1.693950, 0.514860, -0.356230, -0.035230, -0.266320, 0.410480, -1.005160, 1.008300,
-1.687420, 0.462370, -0.205800, -0.412410, 0.854680, 0.965370, -3.432990, 1.447600, 0.762430, 0.673060,
1.490960, 1.598500, -0.925670, -0.428380, 1.058320, -0.401700, 0.917060, -1.100590, -0.221030, 0.125550,
0.326850, -2.807890, -1.234180, 1.059440, -1.589860, -0.226050, 0.817290, -0.029360, 1.328730, 1.844260,
0.150740, -0.830930, 0.887030, -0.629550, -1.256150, 0.740570, -2.688670, -0.622710, -0.156300, 1.139440,
0.017840, 0.071510, -1.723700, 0.884690, 0.634830, -0.375560, -2.369730, -1.172220, -1.269680, 0.194230,
-1.255720, 0.028320, -0.020820, -0.833480, 1.264420, 0.490040, 0.316890, -2.567470, -0.655440, -1.677350,
0.149830, 0.297090, 0.280770, -1.010250, 0.389060, 0.613600, 0.103160, 0.669640, -0.177870, 0.468450,
2.212220, 1.362000,
-0.389770, -0.579030, -0.558240, -0.051110, 1.969250, 0.856450, -0.392590, -1.942290, -0.228220, -0.161840,
0.121330, -0.409700, -0.715470, -0.494820, -0.221360, 0.853790, 0.496480, -0.589640, 0.177980, -0.643930,
-0.173190, -0.435790, -0.976140, -1.129400, 1.007160, -1.545680, -0.395280, -0.040330, -0.891730, 0.965430,
1.684760, 0.197390, 0.757570, 0.592090, 0.001710, -0.689260, -0.723210, 1.426650, -1.244030, 1.095630,
-0.700740, -0.176090, -0.414120, 1.399010, 0.546880, 0.153190, 0.048930, 0.113130, 1.822650, -0.293770,
0.082710, -0.031960, -0.776660, -0.514130, 0.467520, -0.918700, 1.024230, -1.270070, 0.664090, 0.700640,
-1.301400, 1.972420, -1.576550, -0.344620, 0.018530, 1.592810, 0.714410, 0.502860, 0.374040, 0.119750,
-1.033590, 0.126870, 0.907380, -0.533100, 0.844610, 1.084340, -0.057100, -0.707200, -0.121250, -0.708750,
-0.017190, -2.016630, -0.690790, -0.405010, 0.292970, 0.947310, -1.050290, -3.919380, 0.422690, 0.975280,
-2.012020, -1.475510, -0.463140, 2.463210, 0.312850, -0.176630, -1.319730, -0.156140, -0.552250, 0.039500,
0.964080, -1.098140, -0.433640, -0.675070, 0.266310, 1.030050, 0.362360, -1.015470, 1.009470, 0.373890,
-0.223340, -1.203560, -0.850520, -0.848480, 0.817690, -0.062950, 0.331610, -0.609400, -0.301350, 1.916770,
0.597210, -0.551750, 2.589140, -0.349560, 0.615150, -0.838700, 0.381310, -0.042260, -1.338860, 1.836860,
1.791160, -0.867970, -0.644980, -1.113770, 0.549940, 0.561160, -0.224950, -4.461010, 0.997320, -0.086540,
0.890960, 0.424340, 0.569650, 0.945670, -0.983880, 0.111120, -0.381410, -0.118640, -0.254560, 0.169440,
-0.497090, -1.735130, -1.162480, 1.261170, 1.318510, -0.315140, -0.393680, 0.056360, 0.030440, 0.790360,
0.763050, -0.592100, 0.964400, 2.000730, -0.675820, 0.451360, 1.048530, 0.802180, 0.390540, 0.047470,
-0.927370, -2.821500, -0.421890, -1.642900, -3.988410, -0.751810, -0.198850, -0.043480, -0.376740, 0.201870,
-1.104180, -0.154480, 0.812240, -0.279970, -1.273700, -1.038860, 0.828760, -1.520090, -1.293620, 0.360490,
-0.581830, -0.962720, -0.132030, 0.111890, -0.375310, 1.550720, 0.127540, 0.905730, -0.190490, 0.209660,
-2.885610, 0.980700, -0.506120, -0.222050, -2.468430, 0.393010, -0.771010, -1.165620, -1.255220, -1.465710,
-0.548670, -0.274410, -1.400740, 0.159750, 0.839270, 0.136740, 2.121540, -0.327150, 2.360920, -0.554930,
0.214540, -2.125750, 1.559070, -0.749830, 0.896820, 0.584660, -0.466450, 2.071050, -1.512150, 0.925690,
0.585140, -1.016750, 1.866710, 1.732000, 2.801970, -1.368570, 1.146390, 1.781690, -5.712310, 0.686440,
1.821160, 1.145740, 1.532210, 1.898530, 0.151050, 2.540900, 0.698230, -5.323390, 2.588390, 1.814090,
-1.874150, 1.911630, 1.771540, 0.009140, 1.947460, 0.481540, 2.819680, 0.295480, 2.590240, 0.908020,
-7.377810, 0.616190,
1.145670, -0.684120, -0.870580, -0.203280, -0.102430, -0.325840, 0.139490, 0.177760, 0.547790, -1.431940,
-0.737630, -1.325150, -2.540860, 1.249360, -0.076590, 0.421030, 0.680560, 0.846960, 1.843740, 2.998260,
-1.355620, -0.142730, -0.534260, -0.814420, 0.453730, 0.251870, 0.872460, 0.705810, -0.377070, -0.475980,
0.851250, -0.907720, 0.490540, -2.312840, -0.041320, 4.751110, -0.029350, 0.024830, -1.273200, -0.193270,
5.990080, -0.923780, 3.637540, -0.079630, -1.630210, -0.514400, -2.519440, 1.571690, -1.002280, -0.861270,
-1.812150, 0.683910, 0.181110, 0.322660, -1.375070, 2.592970, 2.849450, -0.923940, 1.736130, -1.187050,
-0.251250, 1.107740, 0.175640, 0.150200, -0.326450, -1.678320, 0.817280, 0.602840, -0.541080, -0.523660,
0.400600, 0.692350, -1.737450, -1.726490, 0.020810, -0.473950, -0.587810, 0.469540, -0.007790, -0.667070,
0.135750, -0.736740, 0.428850, 0.483540, 0.935140, 0.024600, 4.268360, -0.624830, 1.614780, -1.486480,
-0.135710, 1.588380, 2.400340, -2.818690, -0.882510, -0.982620, -1.785030, -1.052520, -0.755240, 0.512270,
-5.332170, -1.012760, 0.094190, 0.523100, 0.556720, 2.547700, 1.103380, 0.344110, -0.765720, -0.804200,
-0.036330, 0.546620, 1.133360, -0.906930, 0.949780, 1.031300, -0.454320, -2.201450, -1.012660, -0.507820,
-0.564940, -0.309290, -2.125040, -0.658390, 0.920480, 0.127940, 1.150360, -0.355220, -0.860220, 0.902180,
-0.513530, -0.335550, -1.056480, 0.047420, -1.745830, -0.315330, 0.004570, 0.734990, -1.242250, -0.207750,
2.849490, -1.265020, -0.898820, 2.929370, -3.053660, -1.293930, -0.455550, 0.837080, 0.008200, 1.775040,
1.012200, 0.940700, 0.404490, 1.397980, -0.939250, 0.767620, -2.324890, -2.645000, -1.956250, -3.191860,
-0.942600, 1.807330, -0.011010, 2.907070, 1.080390, -1.250420, 2.826090, -0.077730, -0.592840, 4.229550,
0.558530, 0.549760, -0.276820, -0.513010, -0.347690, 0.361930, 0.527630, -1.046490, -1.417110, -4.037360,
-2.994360, 1.164610, 2.814540, 0.190010, 0.115200, -1.311530, -1.675460, 1.030270, 0.418740, -0.371790,
2.110490, 1.364540, -0.345470, 0.180180, -0.331740, -2.991270, 1.371180, 0.828080, -0.883060, -0.440670,
-0.834310, -1.046300, -0.173590, 3.806420, -0.031000, -1.314490, -2.538590, 0.318300, 1.134480, -4.040990,
-0.697040, -0.791960, 0.692470, 0.627640, 0.401760, -1.080290, -0.104530, 0.408940, 0.688830, -0.476610,
-1.551470, -0.603270, -3.011650, -0.704120, 4.556120, 0.396840, 1.109500, 1.639910, 0.142380, -0.124520,
-0.803720, 1.805590, 2.560070, 1.370080, 1.846870, 0.224770, 0.489190, 1.455520, -2.040820, 1.154160,
1.128650, 1.375260, 0.913650, 0.846770, 0.919490, 1.730030, -0.083060, -0.769300, 0.906100, 2.998590,
0.262980, -0.093860, 2.057450, 0.083400, 1.530370, 1.961280, 0.191450, 1.763080, 1.026450, 0.242630,
1.007750, 1.400570,
-0.380930, -0.046920, 3.594910, 1.890580, -1.167170, -0.765550, 1.072680, -1.486730, 0.662020, 0.097830,
0.835390, 0.127520, 1.744200, 0.683480, -0.057690, -0.013570, 0.565190, 1.218150, -0.847480, -0.952400,
0.754650, -1.008520, 0.367650, -0.728200, -1.252600, -2.015600, 1.290150, 0.863410, 0.154940, -1.099220,
-2.584850, -0.991120, -1.540840, -0.972980, 0.586530, -1.653630, 1.003840, -0.724610, -1.308020, 0.520680,
-0.943330, 0.483870, 1.913130, -0.804780, -2.585730, 1.131110, -0.878590, -2.651310, 2.504640, -0.649730,
0.218550, 0.423200, 0.523230, 1.043670, -0.094210, 0.940440, -1.076560, 2.024280, 1.024870, 0.283880,
0.129920, -2.469150, 2.456690, 1.782690, 0.153230, 0.857850, -3.673210, -2.506070, 0.310230, 1.570280,
-0.102960, 0.190900, 5.036870, 1.890850, 2.385370, 0.964190, 1.923440, -0.407120, -1.698790, -0.908160,
0.849920, 1.456930, 3.230690, 1.850890, 1.877040, 1.066960, -1.270260, 0.468350, 1.068290, 0.891660,
1.901210, -0.011240, 4.684680, 0.960160, 0.065090, 0.343030, 2.352790, -0.225840, 0.425460, 0.924730,
-0.959030, 3.430730, -1.013700, -1.007170, 2.328620, -0.938190, -0.018010, -3.424620, -0.711880, 0.856490,
5.721030, 2.707330, -0.947060, 2.584000, 1.442390, -0.192060, -1.406880, 1.276460, 3.919260, -4.421540,
0.499420, -0.035470, 2.038070, 1.397350, -1.154380, 0.816440, 0.442070, 1.253690, -2.314000, 0.626970,
1.300610, -0.621400, 0.960660, -0.060020, 0.874820, 2.371160, -0.854210, 1.070820, 1.403020, 0.315180,
-3.023380, 0.062820, -0.381650, 1.054080, 0.114350, -1.170010, 0.981460, -0.515490, -0.394240, -2.090590,
0.463070, -1.016690, -0.008180, 0.796020, -0.417220, 3.697990, -1.284070, 0.389180, 1.215500, -0.871290,
1.210550, 0.422680, -0.120700, -0.449290, 3.221620, -0.846100, 2.222090, 0.555640, -1.209420, -1.085100,
-1.224450, 0.957100, 2.582790, -0.085830, -1.457670, -13.803590, 2.452220, -0.658830, -0.617940, -0.938830,
1.555950, 1.487360, 1.067010, 0.314050, -1.076240, 0.337240, -0.979220, 1.508010, 0.230690, -1.425680,
1.045510, 0.656430, -0.666510, -0.785960, 0.007440, -1.956290, -7.122880, -1.495820, 0.374700, -0.719620,
0.908160, -1.319550, 0.868170, 0.489560, -0.454710, 1.704530, 1.316490, -1.456550, 2.580290, 1.204560,
-0.709140, -0.061860, -1.120810, -1.556050, -1.296150, -0.225390, 0.200810, -0.551670, 0.451200, 1.070540,
0.152180, 0.403340, 2.387280, 0.751940, 0.100980, 0.593230, 0.255740, -1.554560, 0.045810, 2.882640,
-0.073810, -1.433440, -0.728670, 1.442680, -0.164950, 0.666600, 0.317870, -0.897910, 1.982840, 0.272750,
0.408280, -0.760400, -0.452980, 0.978390, 0.827030, -0.800100, -0.687570, 0.445120, 0.572100, -0.213710,
0.084050, -0.662850, 1.481660, 0.730490, -0.553940, -0.519880, -0.632420, 0.310990, -0.875790, -0.550580,
2.421000, -0.185280,
-0.838520, -0.898970, 0.311370, 0.554030, -0.891560, 1.967210, 1.601770, -0.037080, 0.414930, -0.430880,
-0.062590, -0.404490, 0.259830, -0.272880, 0.961730, -0.706360, -0.747100, 0.959090, 0.329650, -0.953360,
0.910340, 1.441690, -1.797120, 0.421110, -0.974110, 0.185850, -0.966900, -0.496120, -0.099730, -0.030370,
-1.374660, -0.834220, -0.025320, -0.156410, -0.385160, 0.172090, 1.955090, -0.093220, 0.824010, 0.330870,
0.350190, 0.137090, -0.515770, 0.371850, 0.744810, -0.471410, 0.504880, -0.650910, -0.163540, 0.797700,
1.214190, 1.075170, 1.802000, 0.716730, 0.363800, -0.667860, 1.757470, -0.078130, 0.180510, 1.325230,
-0.426240, -2.519030, 0.093230, 1.289390, 0.336790, -0.797110, 0.996060, 1.161070, -1.598210, 0.214270,
-0.466210, -0.895940, -0.469850, 0.751610, 0.334900, 0.794840, -0.036240, 0.665240, 1.065330, -0.363480,
0.046200, -0.438510, -0.242970, -1.382390, -0.507610, 0.115370, -1.099900, 1.946920, 1.325750, -0.099870,
-0.295630, -1.163450, -0.610920, -0.016760, 0.722460, -0.874070, -4.781380, -1.527640, 4.610740, -0.555220,
0.037360, 0.691340, -0.327970, 3.958850, -0.678300, 1.385250, -0.001310, -1.988230, 2.970780, -1.849830,
-1.211210, -3.135340, -3.303660, -1.162770, 1.225570, 1.168880, -1.019830, -4.100850, -1.850670, 7.296880,
-0.615430, 0.196230, -1.087720, -4.191620, 5.386730, 0.495670, 1.686550, -0.415510, -1.065340, 0.492650,
-1.422110, -1.393510, -5.137920, -4.562650, -1.645900, -0.459630, -1.330270, -1.718160, -2.865270, -1.208090,
8.427210, 1.181730, 2.060990, -1.359470, -1.478760, 6.504550, 0.831300, 1.396520, -1.691530, 1.258530,
-1.166670, -1.503170, -2.762470, -0.241650, -2.734720, -2.211570, 0.676320, -0.961390, -0.889440, -1.828150,
0.046520, 8.180230, -0.103400, 0.946570, -0.137600, -2.140910, 2.411220, 1.249520, 1.053140, -0.929810,
-0.375170, 0.464490, -0.980530, -1.065720, 0.680560, 0.186890, 0.464000, 0.068330, -0.531600, 0.410250,
-4.463560, 0.643120, 1.969890, -0.021080, 0.478240, -0.371560, -1.071000, 0.404650, -0.178500, -1.241600,
-2.045340, -0.283630, -0.549170, 0.300000, 1.531510, -0.252720, 1.509950, -1.023430, -2.026900, -0.689980,
0.135050, -1.620170, -0.014130, -0.089590, 0.736800, 0.366260, -1.705440, -2.450030, -0.557330, 0.318510,
1.010980, -1.134240, -1.653650, -1.929600, -0.230380, 1.011350, 1.404620, 0.814380, -1.214400, -1.302640,
0.563460, -1.171760, -1.717330, -0.174520, 0.197380, 0.391040, -1.342090, -0.608300, 0.131700, -3.612410,
0.769770, 0.541470, -0.291910, 0.451210, -0.051160, -0.379280, -0.545640, -0.774800, -0.975730, -0.065460,
0.357620, 0.698180, 0.136250, -0.787640, -0.470300, 1.219300, 0.113350, -1.635530, 1.098220, -0.041370,
-0.492450, 0.381610, -0.372190, 0.724480, 0.859790, -0.681690, -0.826170, -0.513590, 0.846420, -0.657890,
-2.162940, -0.951940,
-0.079340, -0.989620, -1.308340, -1.331700, 0.177670, -0.619730, 0.552440, -2.243460, 1.788880, 1.116530,
4.213390, 0.407490, 0.507760, -2.003460, -1.846400, 0.487410, 0.203050, 2.153480, 0.258200, 0.593520,
0.108710, -1.322770, -1.068570, -1.436840, -1.027500, 0.353880, -0.199950, 0.315230, -1.070240, -1.402890,
-0.721900, 1.463860, -1.210970, -1.127280, 2.613620, 0.678350, -2.072270, 1.393940, -0.539330, 0.914700,
0.978190, -1.455410, -0.697430, 0.222920, -0.889740, 0.242560, -0.375060, 0.723500, -0.690680, 0.213610,
-2.880220, 3.915530, 1.840430, 1.983770, 0.625500, 0.538670, -0.780540, -0.112220, -1.011860, -0.139510,
1.566820, -0.292100, 1.506550, 0.754690, 0.062610, -0.522780, -2.689880, -0.374220, -0.740630, -0.470400,
0.865910, -0.235320, 2.145090, 1.731590, 1.381270, 0.901960, 0.815190, -0.424010, -0.529710, 0.244830,
0.800530, 0.654450, -1.551390, -0.131320, -1.086350, -0.499840, -0.711650, -0.385020, 0.624120, 0.907040,
6.104350, -4.530920, 2.822770, -0.455270, -1.436010, -0.492130, 0.974640, 3.600520, 0.494330, 2.675450,
1.492430, 4.622570, -0.623920, -1.985960, 0.781690, 0.211780, -1.512550, -0.691330, 1.035740, 0.652660,
0.289450, 2.770220, -5.742760, -1.399300, 0.336010, -1.540810, -1.013030, 0.296240, -1.105360, 1.326900,
0.474950, 2.113950, -1.393870, -0.418670, -2.479270, 0.306260, -1.242260, -0.591830, -2.970560, 1.181920,
-1.994350, -0.414290, -0.977880, -2.602480, 0.881420, -1.049670, -0.122120, 3.624990, 1.785510, -0.560090,
-0.166320, -0.365910, -0.555120, -2.242060, 0.375760, 6.293390, 0.124650, -2.000650, -2.225380, -1.107550,
2.420790, 1.420020, -1.636090, 0.703620, -4.658270, 2.111840, 0.032220, -1.764230, 0.555840, 1.792070,
-2.832460, -0.691590, 1.734770, 1.676670, -2.198430, -1.081050, 4.213920, 1.848020, -0.520070, -1.343020,
-0.076300, 5.967460, 1.445600, -1.196550, 1.933040, -2.422180, 1.123580, 1.307110, -0.942790, -0.336500,
1.212630, 4.482370, 0.069270, 1.165370, 2.177810, 2.840930, 0.139650, 2.862270, 2.099320, -2.789330,
-0.136360, 0.204130, 0.348010, 0.186150, 2.599540, -2.053550, 1.190800, -0.352990, 6.007230, 0.193400,
2.259870, 0.906590, 0.925280, 0.399690, 1.347810, -1.816620, -1.308120, 0.732040, -1.499570, 0.830700,
-1.573870, -0.769420, -0.296580, 0.731110, -0.358680, 1.437730, -0.846860, -1.827190, -1.865410, 0.884210,
2.504220, 5.374800, 2.234780, 0.907800, -0.594030, -1.524910, -2.464220, -1.259250, 1.015250, -1.099030,
-0.163770, -0.036400, 0.167680, 1.223170, -0.237630, 0.871400, -0.735140, -1.109180, -2.717020, 0.715130,
-0.430440, 0.060330, 0.086450, 0.023880, 1.027850, 0.929890, -0.414310, -0.970680, 0.553060, -0.027920,
0.501730, 0.715810, -0.151420, -0.249350, 0.488220, -1.047160, -0.523800, 0.883570, -0.735210, -1.292970,
3.357230, 0.182230,
-0.028340, 0.487350, 1.230190, -0.433500, -0.262690, 0.840500, 0.616710, 0.439610, -0.841660, -0.754130,
-0.352500, 0.890360, 0.287370, -1.253060, -0.310410, 0.578170, -0.650540, -0.513940, -0.419510, -0.048850,
-0.679880, 0.078790, -0.510020, -0.460040, -0.108850, 0.379630, -0.524530, -1.481460, 1.909000, 0.192140,
-0.645700, 0.961780, 1.040330, 1.573640, 0.634700, 0.325330, 0.713060, 0.091050, 1.932840, 0.901300,
0.737180, -0.740380, -1.433700, 0.295730, -0.086560, -0.234000, 1.284670, 0.460360, 1.152420, 0.458900,
0.951910, -1.014390, -1.452940, 0.266250, 0.226260, -0.026150, -0.070740, 0.152800, 0.034180, 1.373780,
0.810620, -0.099430, 0.055110, -0.512040, 0.033260, 0.061970, 1.294030, -1.286440, -0.285560, 0.349100,
0.408390, 1.116110, -0.611770, 0.483590, -0.229290, 0.941500, -0.141990, -0.503910, -0.056260, 1.724930,
0.402100, 0.593530, -1.811960, 0.470200, -0.497060, -0.141560, -0.931570, -1.529670, -0.466820, 0.924190,
-0.546190, 0.423550, -0.541160, 0.759920, 0.043980, 1.162270, 0.854410, 0.631660, 0.327420, -0.814250,
-0.305070, -0.926120, 1.247860, -0.436780, -1.371030, 1.763580, -0.154500, -0.530460, -1.608040, -0.379430,
0.226130, -1.371660, -1.351360, -0.219350, 1.204810, 0.361530, 0.788170, -0.428930, -0.455550, 0.934200,
1.402020, -0.038450, -0.520460, -1.006270, 0.510430, -0.387560, 1.032340, -0.828780, -0.571900, 2.511000,
2.316070, 0.383760, 1.845710, -1.865780, 0.734010, -0.948110, 0.099300, -0.119020, -0.165180, 0.591330,
1.670280, 0.694160, 1.513050, 1.480200, -1.204170, 0.668870, 0.829710, 0.335890, 1.048760, 1.073620,
-0.478530, 0.491420, 0.649180, 0.233290, -0.245450, -0.124610, 1.100700, 0.877890, -0.206940, 0.693580,
-0.125450, -0.760750, 1.871220, 1.500230, -0.513210, -0.470970, 0.526880, 0.578540, 0.290380, 1.686430,
-0.966690, -0.587610, -1.208510, 0.302250, -2.924340, 0.303380, -0.892140, 0.867400, 0.755210, 1.549920,
-0.679180, -1.201820, -0.741860, -0.490410, -0.252070, -0.461010, 1.373760, 1.456550, -1.676050, -0.787200,
-1.209050, -0.574300, 0.252130, 0.903170, -0.663420, 0.187050, -0.432250, 1.245010, -0.101750, -0.507610,
0.796460, -1.661520, -0.781610, 0.359930, 0.241040, -0.577870, 0.736220, -1.133420, 0.377050, 0.165360,
1.271230, -0.204640, -0.120440, 2.136690, 0.876170, 0.089410, 0.732490, -1.203260, 1.468860, -0.099870,
-1.026900, -1.759170, 0.634540, 1.605050, -0.743540, 0.244070, 1.099130, 1.471010, 0.559430, 0.051570,
3.058340, -0.799280, -1.951650, -0.806410, -0.741010, -1.934880, -1.889810, -2.210170, 0.911140, 0.086190,
-0.531570, -1.414860, -0.338610, -2.465490, -0.309690, -1.980170, -1.805170, -1.006170, -1.512460, -1.380250,
-4.539870, -1.563760, -1.101770, -1.837250, -1.472480, -0.924280, -1.486870, -0.463410, -1.573490, -2.031530,
-1.832150, -0.377740,
-0.891550, 0.560280, -0.143820, -1.192310, -0.203680, 0.038600, 0.290880, 0.080270, -0.006400, 1.510320,
0.135350, -0.949630, 0.894020, 0.225850, -0.646550, -0.622900, -1.482550, 1.510150, 1.279090, -0.621840,
-0.233080, -1.214960, 0.512140, 1.122640, -2.883010, 0.353150, 1.041780, -0.082410, 0.093160, 1.710210,
1.299780, -1.902440, 1.025440, 2.575230, 0.719930, 1.328930, 0.842200, -0.782300, 0.543180, -0.423380,
-1.691550, -0.245550, -1.698640, 0.322130, 0.439290, -1.433210, 0.083660, -2.078510, 0.059490, 0.847270,
-0.443770, 0.530110, -0.389580, 1.521650, 0.762820, -0.781810, -1.173520, -1.114270, 0.658410, 1.872680,
-0.777110, -1.085780, 0.355710, 0.677490, 0.976010, 0.002590, -0.258200, -0.107520, -0.947810, 0.979360,
-0.628720, -0.439350, -1.451610, 0.978070, 0.537560, 0.114910, 1.372800, -0.649990, 0.720530, -1.046110,
-0.823560, -0.838880, -1.868150, -0.068110, 1.017500, 0.264920, -1.314820, -0.606300, 3.309060, -0.175950,
1.090410, -0.535280, 0.384410, -0.191980, -0.632600, 0.025930, -0.191350, 1.225550, -0.944790, 1.254580,
0.040310, 1.830610, -0.394730, -0.298920, -0.856010, 0.138930, -0.852530, -0.860600, 1.170250, 0.248050,
0.830840, 1.219740, -1.553820, 1.192840, -0.892420, 0.900110, -0.635010, -0.596910, 2.223220, 1.278010,
1.767820, 2.789440, 2.418990, -1.819510, -0.030250, -0.659070, 1.305240, -0.054560, 0.224650, 1.158570,
0.057270, 0.206240, -0.871240, -0.444780, 1.450620, 1.109430, -0.869790, 0.562400, -0.301020, 1.318810,
2.625960, 0.938200, 1.729000, -0.344780, -1.180660, 1.397510, -1.629650, -0.565720, -0.295400, -0.260980,
1.049250, 1.880190, -1.069960, -0.982510, -2.824420, -0.566770, -0.863530, 1.290910, -0.955710, -1.455820,
-0.052020, 0.596560, 0.956850, -0.345300, -1.580350, -0.954250, 1.260580, -0.825890, 0.294520, -1.105650,
1.307150, 1.450620, 0.192990, -0.001010, 1.336850, -1.180300, -0.464130, 0.535050, -1.534890, -1.824820,
-1.107630, 0.715050, 2.355390, 0.815970, 0.574270, 0.605980, -0.007990, 2.134070, 0.693520, 0.319600,
0.231430, 0.133950, -0.103490, 0.247860, -0.959750, -0.781740, -0.097920, 0.601820, -0.524960, -3.436570,
-0.985320, 0.723420, -0.547360, 0.386870, 1.005000, 2.288400, 0.219040, -0.998260, 0.359310, 1.778960,
-0.371300, 0.498810, 0.228660, 0.629220, 0.548630, 1.554270, -2.285210, 0.167420, -0.245460, 0.246400,
1.162500, 0.185690, 1.107090, 0.931340, -0.315240, 0.222300, 0.190370, 0.528310, 1.093260, 0.185310,
-3.493360, -0.590640, 0.442140, 1.109480, -0.187540, -0.313340, 0.143010, -0.420900, 1.601170, 1.432120,
0.463340, 0.220810, 1.445170, 1.017250, -0.037640, 0.206310, 1.332280, 6.599650, 0.736380, 2.030270,
2.775830, -0.128250, 0.341720, 0.057380, 2.015750, 1.330110, -0.204030, 0.480080, 1.252670, 0.592300,
-1.964130, -0.821650,
-1.732570, -0.437380, -1.845690, -0.538720, -1.482540, -4.458520, -1.107910, 1.226880, -0.981860, -0.673100,
0.483920, -1.798530, 0.716030, -0.128590, 1.139610, -1.567290, -1.591220, -0.472940, 0.050990, -0.687480,
-1.769620, -0.153050, -0.266920, 0.070970, -0.231930, -0.345950, -1.031650, -1.499810, -0.628020, -0.588070,
-0.677990, 1.399650, -0.028280, 0.399490, -0.397950, 1.775650, 0.769900, 0.139080, 1.343480, 0.975090,
-0.570600, -0.510420, -0.439960, -2.338880, -1.501690, -0.011510, 1.485130, -0.257650, -0.318870, -1.234880,
-1.527480, 0.351980, -0.711550, 1.744890, -2.238030, -0.452020, -1.493970, -0.204200, -1.121240, -1.967900,
-0.649670, -0.606090, 0.659740, -3.727850, 0.265800, -0.056920, -0.454220, -0.721350, 0.214810, -0.538690,
1.199750, -0.675140, 0.879590, 0.131430, -0.934800, 1.170150, -0.489500, -0.753310, 0.986570, 0.443810,
0.087140, -0.253840, -1.725560, 0.192280, 3.446720, -1.282760, 0.143550, 0.179190, -0.356350, 0.588640,
-1.285870, -0.999370, -0.590120, 0.313230, 0.234750, 0.705570, -3.728000, -1.298430, 1.003370, 0.829780,
-0.978440, 1.686750, -0.439830, -1.386330, 1.238780, -0.507540, 2.231240, 0.106880, -3.319890, -2.014270,
-1.453770, -0.150660, -0.246100, 0.940450, 0.470220, -0.142870, -1.184460, 0.182150, -0.386380, 5.312100,
-1.477750, 0.827990, -1.193040, 0.039310, -1.128030, 1.759640, 0.727550, -0.421580, 0.500660, 0.254310,
-0.327600, -2.824060, 0.505490, 0.309090, -0.260690, 0.387600, -1.208660, 0.109710, 0.030060, 0.269130,
0.996670, -0.139170, 2.421520, 0.229820, 0.034280, -0.730980, 2.269320, -0.333540, -1.105290, 0.924860,
0.257680, 0.427680, 0.494910, 1.518680, -6.236390, 0.535390, 1.067720, 0.110980, 0.927520, -0.772980,
0.029640, 0.680530, -1.928980, 1.976220, -1.295490, -0.974030, -0.285050, 0.997710, 0.028080, 0.732900,
-0.746620, 0.126020, -0.359860, -0.001450, 0.831380, 1.299820, -0.654080, -0.309720, -1.378990, 0.750750,
1.706390, 0.873170, -0.704480, 0.832350, -0.390040, 0.276790, -0.645230, -1.472340, 0.495310, 0.172300,
-1.003360, -2.115130, 0.426140, 0.185160, -0.004280, 2.327720, 0.194120, 0.226740, 0.628970, 1.877700,
-0.732100, 1.511400, -0.072260, -4.702620, 0.792860, 0.168900, 0.294280, 0.480680, -0.317550, 2.206600,
-1.487820, 0.062870, -2.231250, -0.576370, 0.428640, -0.618610, -0.458810, 1.400620, 3.195280, 0.410570,
0.547450, -0.316000, -0.013370, -0.363830, -2.576880, -0.570800, -2.199850, 0.480310, 0.349110, 0.961040,
1.526810, 1.612970, -0.651760, -1.374930, -1.251390, -0.210790, -0.228650, 0.449440, -1.665280, -1.563200,
0.102190, -1.584540, -0.512510, -1.156090, -0.232690, -1.634570, -0.484930, -0.163800, -1.031070, -0.357420,
-0.954130, -0.281530, 0.483210, 0.169150, -0.569580, -0.596520, -0.835970, -1.084580, -0.939400, -3.775310,
-7.786900, -0.691170,
0.116780, -0.176650, -1.274240, 0.913330, -1.308260, 0.137800, -0.464860, 1.620960, -0.425210, 0.964080,
0.200170, 0.806510, 1.321910, 1.664710, 0.821290, -0.619260, 0.414210, -0.348380, -0.114020, 0.527340,
0.503820, -0.921270, -1.261170, 0.013780, 0.092950, -0.440510, -0.923540, 0.146030, -0.282640, -0.071610,
-0.660390, -1.207770, -1.820160, -0.016770, 0.705480, -1.308940, 0.228740, -2.756100, 0.058420, 0.944150,
-1.419890, 0.804870, 1.277760, -0.266260, -0.558090, -0.994080, 0.184170, 0.743800, 0.462130, 1.427840,
0.041970, -0.811850, 0.587100, -0.821760, -2.696850, -0.538460, -1.388660, -1.326090, -1.064050, -0.154840,
0.935110, 1.965620, 1.572270, -0.955570, -0.366350, -0.533520, -1.327200, -0.265400, 0.456710, -1.477110,
0.057950, -0.774040, 1.135750, -0.354780, -0.772060, 0.987640, 0.970670, -2.420850, -0.837940, -0.144750,
-2.519580, 0.624920, -1.923850, -0.324080, 0.338600, -0.240090, 0.178930, 0.422430, -0.583390, 0.923680,
-1.254850, 0.153670, -0.750270, 2.034020, 0.142890, 1.635080, 0.859960, 0.283370, -0.240330, -0.510020,
-0.875460, 0.862180, 0.516860, -1.505420, 0.098550, 0.708310, 0.253960, -0.998490, 1.195130, -0.460820,
0.659430, 3.122610, -0.021210, 0.273820, 0.813930, -0.598760, -0.552420, 4.517400, 0.822810, 0.715560,
-0.086210, 1.074940, 1.167270, -0.873030, -1.546770, 0.042560, -1.410110, -0.828110, 1.038280, -0.005590,
-2.602960, 0.415490, 0.859750, 0.219970, 0.678210, 0.285330, -1.611290, 0.540390, 5.656960, 0.660590,
0.015700, 0.043800, 0.631760, 0.976800, -0.297300, -0.465970, -0.708690, -1.366580, -0.848660, -1.000900,
-1.368580, 0.160350, 0.925410, -0.911220, -1.574810, -1.922000, 0.584880, 0.072490, 2.972730, 2.467640,
1.571040, -0.944940, -0.535920, -1.307390, 0.235270, -0.458550, -1.140410, -3.130240, -0.791540, -0.732380,
1.053010, 0.440180, 0.742780, -0.407210, -0.172800, -2.845020, 0.930260, 1.851790, 0.556710, 2.264250,
2.766300, 0.543480, 0.904740, -0.694960, -1.241190, 1.637400, 0.818850, -0.246780, -0.413790, 0.562300,
-0.537570, -0.735240, -0.332470, 1.638680, -0.241670, 1.393220, -3.235280, 1.133080, 0.953660, -0.931700,
0.649940, 3.113870, 1.229600, 0.281080, -0.402630, 0.155250, 0.173520, -0.313310, -0.354160, 1.154810,
-1.621010, -0.362780, -0.601990, 0.065370, 0.351220, 0.456080, 0.309810, -2.553990, 0.082240, 1.913530,
0.385570, 1.537620, 3.800710, 0.725100, -1.401060, 0.211200, -2.407700, -0.242450, 1.255040, -0.766750,
0.922240, -0.869950, -1.057920, -0.780090, -1.252440, -0.528860, -0.889320, -0.091300, -0.108370, 0.009030,
-1.456280, -0.004150, -1.595100, -1.523330, -1.544220, -1.363700, 0.256820, -0.038730, -0.173280, -0.495800,
-0.673150, 0.224040, 0.203120, -2.524030, -1.324600, 0.006720, 0.006400, -1.684890, -1.684910, -0.314690,
2.163630, -0.788450,
-2.330400, -1.846360, -0.307070, -0.124110, -0.106880, 1.681450, 0.160260, 0.088880, 0.405890, 1.000540,
-0.747820, -1.459090, 0.966160, -1.097940, -1.333430, -1.519320, -1.498580, -0.968630, -2.866650, -0.614270,
-1.619970, -1.085690, -0.008870, -1.934190, -0.013140, -0.237900, -0.580020, 0.529750, 0.077860, 0.159950,
0.505020, 0.710790, -0.324080, 1.394630, -0.927150, -1.580230, -0.475690, -1.849950, 0.912840, -1.711170,
-2.699560, 0.082230, -0.047610, -2.662970, -2.056720, 0.078380, 0.848330, -0.466720, 1.334080, -2.608170,
-0.157770, -0.216150, 0.775580, -0.273330, 1.199190, -0.218050, -0.904460, 0.050080, 1.335870, 0.553970,
0.572100, -0.380310, 0.390560, 1.080430, -1.050030, -1.045960, 1.096130, 0.867820, -0.221330, 0.365150,
-2.520300, -0.769930, -0.326020, -1.032710, 0.332400, 0.146010, -0.325580, 3.010840, 0.327170, 2.756560,
2.227040, -1.607370, 0.673650, 0.373830, 3.055290, -0.672270, -1.341020, 5.526950, 1.342480, -0.223820,
-0.527490, -4.580920, 0.535310, 0.891370, 0.257830, 2.454150, 0.743640, -1.131850, 3.785080, 0.128820,
1.005060, -2.844180, -1.236520, -1.104980, 2.206130, 0.190740, -0.560840, -3.051190, 4.443690, 0.012050,
-5.517570, -3.065980, -8.346840, -1.327670, -0.668090, -0.273490, 2.887610, 2.145160, -2.913790, 3.316210,
1.500670, 2.437190, -3.836450, -4.528800, 0.877950, 0.628500, -1.453500, -1.195190, 0.685950, 0.622680,
1.805950, -0.061680, 0.657210, -8.453970, 0.467400, 0.574030, -2.455320, 3.282620, 0.288350, -1.230820,
4.384700, -3.522110, 3.395830, -0.724910, -2.217600, 3.690240, 0.370940, -3.428980, -0.683910, 0.876680,
1.548450, 0.194710, 0.396520, 0.454190, -2.431150, -0.176340, -0.689010, -0.414090, -0.054620, -0.356150,
0.087760, 4.001700, 0.960430, 1.415930, -0.560290, -3.498210, -2.923680, 0.621100, 0.144960, 0.274050,
-0.533100, 0.716480, 0.421320, 0.515120, 0.622730, -1.878120, 0.117440, -0.802890, -0.066530, 0.942810,
-0.632700, 1.569520, 6.214780, -1.921880, 1.613060, -0.682070, -1.768760, 0.705320, 1.008250, 0.153540,
0.420400, -0.604140, 1.858600, -0.746920, -1.628590, 0.687080, 0.814660, 0.947700, -1.364400, -1.177010,
-0.257210, -1.506210, -0.260100, 0.868490, 0.228940, 1.047160, 0.952520, -0.318150, 1.695440, 0.866900,
-0.539170, 0.447250, 1.367350, 1.036940, -0.747340, -0.731180, 2.003530, -1.431230, 0.723230, -0.829320,
-1.858230, -0.466350, -1.326370, 0.754950, 1.480920, -0.389820, 0.782740, 2.221980, -1.292660, -4.822390,
5.836390, 1.759650, 0.460330, 3.039300, 1.093210, -0.509600, 0.284710, -2.920570, 2.492130, 1.456350,
0.201000, -0.538170, -0.570270, 0.056200, -0.792270, -0.069370, -1.459120, 2.957630, 0.323390, 0.100660,
0.137680, 2.508760, 0.870550, -0.669120, -0.218400, -0.749740, -0.086180, 0.304510, -0.960240, 0.118310,
8.339210, -0.376300,
0.877880, 0.622900, -1.249160, -0.746990, -0.018860, -0.652590, -1.878760, -0.651740, 0.636830, 1.258250,
-1.760130, -0.784890, -0.206000, 0.996260, 0.544250, -0.379880, 0.411700, -0.290050, 0.189390, 1.849830,
0.180420, 1.252650, 0.212820, 1.370260, 0.347610, -5.234280, -0.781600, -0.749880, -0.706260, -1.610660,
0.757440, -0.285390, 0.285820, -0.653140, 0.163880, 0.286360, -1.079870, 0.101060, -2.531600, -0.912090,
-1.593090, 1.297990, -1.271700, -0.459290, -1.132660, -1.399470, 0.046860, 0.899320, -2.220180, -3.198370,
0.541430, 0.315290, 0.153780, 0.039050, -1.146610, -1.567320, -0.685520, -1.512840, 0.819770, -0.515180,
-0.726180, -0.836720, 2.296260, -0.208330, -3.859290, 0.878640, 0.972290, 0.583240, 0.818890, 0.095460,
1.332560, 0.117640, 1.558140, -1.761570, 0.167650, 1.086560, 1.791700, 0.193570, 1.014910, -0.046850,
1.185330, 0.066230, -1.313730, -0.302110, -1.146190, 1.588010, -1.986520, -1.476890, -0.800720, -0.243710,
0.167670, 1.549470, -1.626610, -0.954250, 1.146510, 0.788190, 6.103380, 0.875010, -0.046960, -3.538740,
-2.906570, 1.281590, 0.040510, -1.015970, -0.842460, 0.753270, -0.500190, 0.655450, -0.145320, 0.427790,
0.592680, 3.008130, -1.620910, 3.971430, -0.329530, -2.733290, 0.389050, 0.581080, 1.300120, -0.358010,
-0.815440, 0.080800, 4.407910, -0.468320, -0.335260, -1.689830, 0.025550, 1.363170, -0.833250, -0.488870,
-0.302250, 0.478890, 0.468150, -0.803050, -1.317190, 0.811080, -0.238950, 5.510780, 2.051560, 2.806710,
0.072200, -0.171820, -0.492400, -0.605000, 0.445390, -2.104700, -0.829300, -0.854090, 0.760600, -1.569170,
-0.138070, 3.725430, -0.754780, 3.880840, -0.723530, 0.730570, 0.076110, -1.479330, 1.505000, 1.053170,
0.307680, -3.652750, 0.208040, -0.216540, 1.689690, -0.286090, -2.072980, 0.264820, -1.561840, 3.196480,
-3.166420, 0.159050, -0.152550, -0.163050, 0.829740, -4.898710, 0.682160, -0.434930, -0.627750, 2.533510,
5.173460, 0.218780, -1.872730, 0.843520, -0.760280, 0.007120, -0.490890, -0.987150, -1.834780, -0.599130,
0.451890, -1.688670, 0.903220, -0.287890, 0.507300, 0.373270, -3.559570, 0.610600, 0.530930, -0.047730,
6.697830, 5.750680, 0.160040, -1.236170, 0.543700, -6.302360, 0.502130, 2.543830, -1.386810, 0.086700,
-0.847810, 0.116290, -2.269640, -0.003560, -3.318080, 1.485280, -0.068170, -6.716410, 0.474280, 3.570000,
-1.101720, 1.747920, 3.039960, -1.202640, -0.534900, -1.385820, -2.083600, 1.451690, 0.328890, -1.636550,
1.726690, 2.663060, 0.142520, -0.296780, 0.509530, -0.958510, 1.028880, 0.334770, 2.286900, -0.692150,
0.224330, 0.884370, 0.429680, 1.041680, 0.497160, 1.076340, -0.858160, -0.017780, 0.328690, 1.172290,
0.953240, -0.198120, 0.072250, -2.953860, 0.129210, 0.035160, 0.241050, -0.103510, 0.431410, 1.434170,
0.763500, -0.290830,
0.557900, -0.634080, 1.681240, 0.616390, 0.095740, 0.134250, 0.157030, 1.030570, -0.057520, -0.406080,
-0.977490, 0.362830, -1.069390, -0.957600, -0.214840, 0.642180, -0.128720, 0.107750, -0.699980, 1.348730,
-1.735440, -0.674230, 1.297670, 0.841790, 0.180010, 1.211930, 0.219610, -1.021670, 0.071500, -1.636420,
0.899060, -0.301800, 1.854780, -1.061520, 1.357190, 0.713720, 0.161250, 0.670380, 0.705310, -1.969590,
0.598410, 1.210710, -1.143120, 0.215590, -0.251740, -0.616590, -0.162120, -0.801450, -0.612220, 0.561490,
-0.649250, 0.676650, -0.003890, 1.185040, -1.343880, -0.787980, -0.539930, -0.114880, -0.568710, 0.250600,
-0.552980, 0.196220, 2.364480, -1.430710, 0.678460, -0.579220, -1.765210, -1.209760, 0.050860, -0.110310,
0.766660, -0.765780, -0.700210, 0.942490, 0.593110, 1.500270, 0.916340, -0.767970, 0.001120, -1.962750,
-0.709130, 0.635290, -0.421790, -0.127370, -0.606850, 0.805750, 1.469970, -1.494160, 0.175100, 1.078120,
-0.074280, 2.345260, 1.178150, -0.110740, -0.696140, 0.629450, -0.937770, 1.345930, -1.968480, -0.289840,
-1.415030, -0.333430, 1.965760, -0.641760, 1.487250, 0.379540, 0.317830, -0.369730, -1.285280, -0.348840,
-0.893360, 2.056600, 1.706970, -0.207790, -0.451900, -2.147940, 0.553210, 0.907710, -0.735340, -0.766800,
0.512370, 0.001710, -2.791160, -1.385330, -1.436740, -0.151740, 0.267150, 0.300720, 0.385340, -0.189990,
0.801960, -0.428330, -0.620910, 1.317580, 0.107400, 1.612370, -0.650930, -0.522600, -0.308430, -1.184280,
-0.535760, -0.247780, 0.418530, -0.127640, 0.728010, 0.376090, -0.353730, -0.092180, -1.645640, 0.254430,
1.425730, 1.684830, -0.521440, 1.805920, -0.237120, 0.878810, -0.923960, -0.419230, -1.337930, -0.253640,
0.073800, 0.212520, 0.016920, 1.522930, 1.064170, -0.639380, 0.934100, -1.353670, 0.016880, -0.252490,
-1.426550, 0.962940, -2.441720, -2.346980, -0.648140, -1.514150, -0.216580, 0.284870, -0.327820, -0.502630,
2.276910, 0.558510, -0.230100, 0.039290, 1.620730, 1.955980, -0.605030, 2.044220, 0.759080, 0.690060,
-0.570490, 1.157430, 0.268060, 1.976830, 0.435910, 0.435570, -0.404340, 2.130380, -0.705370, -0.947520,
-1.596280, -1.399410, 2.097980, 2.711840, 1.419460, 2.254740, -0.070160, -0.448870, 2.329200, 0.439740,
0.243400, -1.480180, 1.205680, 0.185870, -0.099640, 0.217060, -0.801880, 0.629180, -1.070010, 1.619980,
0.501140, 0.470930, -1.900130, 1.149950, 1.749760, -1.585140, 1.046090, 1.128530, -1.778330, 1.560140,
-0.345540, 0.206250, -1.492510, -2.220720, 0.149110, -1.079910, -0.495470, -0.672950, -7.254490, -1.427130,
-0.382550, -0.797410, -1.122990, -1.223340, -0.876290, -1.384060, -1.142990, -6.399400, -0.484720, -1.217280,
-2.600060, -7.011400, -1.334850, 0.143450, -0.843960, -1.439840, -0.089650, -0.043200, -1.539130, -2.641300,
-3.735870, -0.126170,
0.102360, -0.943710, 0.255760, 0.557240, -1.338630, -0.166140, 0.464820, 0.888530, 1.264130, 0.277690,
-1.405250, 0.731150, -0.859330, -0.598200, -0.495460, -0.933300, -2.698970, -0.264440, -0.330720, -0.603150,
-0.285620, -0.386300, -1.294920, 0.218760, 0.678840, 0.691920, -0.280540, 1.127270, 0.427410, -0.510300,
-0.431810, -4.580420, 0.201300, 1.447360, 0.211010, -0.661740, -0.412490, -1.614500, -0.717740, -0.275630,
-4.404690, -0.617830, 1.480960, 1.104680, 0.412010, -0.565280, -0.247230, -0.539770, 1.556980, 1.942700,
0.607800, -0.314570, 1.403700, 1.387460, 0.079210, -0.931080, 1.110190, -0.899020, 0.177450, 1.084700,
1.462420, -1.093290, 0.567420, -0.108620, 0.966750, 0.081960, -1.520570, 0.602360, 1.162610, 1.499420,
1.438810, -0.082980, 1.245480, 0.466790, 0.399760, -0.082680, -0.556770, 0.756510, -0.991720, -0.652840,
1.113250, 0.440780, -1.908660, -0.363230, 0.028690, 0.112180, -0.209850, -0.669090, 0.969320, 1.150320,
0.540370, -0.439880, -0.657110, 0.336410, 0.509500, -0.000340, 0.367460, 0.070290, -0.093980, -1.199460,
-2.104520, -0.057180, 1.044980, -0.059180, -1.249990, -2.956040, 1.813530, -0.198670, -1.944810, -0.779890,
-1.850260, 2.777010, -0.461470, -1.731880, 0.572680, 1.643350, 1.323690, -1.415280, 0.285230, 1.398720,
-0.485580, -0.171310, 0.702840, -0.266460, 1.414940, 1.431400, 1.915770, -0.862340, 1.018410, 3.908190,
-1.833110, -1.614120, -2.830670, -2.872290, -1.393220, -1.212850, 1.051830, -1.765320, -4.906900, -0.651660,
1.633010, 0.683860, 1.464930, -0.361960, -3.146890, 3.623680, 0.513360, 1.560940, -0.050970, 1.194000,
1.455160, -0.430090, 0.734390, -5.297330, -0.696840, -1.566540, -1.510750, -0.935190, -5.386350, -7.092190,
-1.021390, 10.750480, 0.825000, 3.624200, 0.442930, -2.875140, 10.383130, 1.583710, 1.900880, -1.356760,
1.440370, 0.175460, -1.153320, -0.650520, -1.010450, -1.593180, -1.786660, -4.573500, -1.337340, -2.832730,
-3.242730, 0.838840, 14.451920, 1.009080, 2.987350, 1.315260, -4.932090, 4.361980, 0.527540, 2.503820,
0.930140, 1.567140, -1.349380, -0.607050, 0.308260, 1.510680, -0.310530, 0.390070, 0.086920, -2.066060,
-4.400990, -3.186450, -0.114570, 13.827040, 1.222900, 1.994390, 0.496640, -6.175830, 2.855050, -0.095960,
2.202080, -0.491610, -1.218280, -1.678400, -2.051920, -0.115080, 0.247360, 0.304780, -0.330030, -0.700370,
-3.924650, -2.219110, -3.616850, -2.763860, 5.845110, 0.233660, 0.664190, 0.184140, -2.821640, -0.471700,
0.744570, 1.047430, -0.845200, -1.544410, -1.427320, -0.975460, 0.193240, -3.306090, -0.780950, -0.324610,
0.149870, -0.406820, 0.993230, 0.594220, 0.006230, 0.210480, -1.479830, -0.393970, 0.611230, 0.533780,
0.321020, -0.635150, -0.069750, 1.747810, -0.494230, -0.196590, 0.336300, 0.665410, 0.568140, 0.623060,
0.279160, -0.507550,
1.077850, -0.744220, -0.255110, -0.138760, 0.595410, 0.951820, 0.180050, 1.264480, -0.579310, 1.221930,
-0.372230, -0.173160, -1.153870, -1.141430, 0.862150, 0.303830, -1.021560, -0.313250, 0.296090, 0.467780,
0.157720, -0.345710, 0.309370, 0.034860, 0.247960, 0.749720, 0.582610, -0.876850, 0.671290, 0.362900,
2.115040, 0.324280, -0.293940, 0.329500, -1.068470, -0.774330, -0.142760, 0.266450, -0.091460, -0.738570,
-0.363430, 0.195750, 0.100690, -0.093190, 1.240970, -0.369260, -0.703330, 0.201160, -0.739700, 0.530220,
1.228410, 0.184710, 0.335190, 1.357520, 0.895800, 0.119230, -0.612190, 0.404640, 0.439790, -0.405270,
-0.589570, -0.547440, 1.989580, -0.061370, 1.250630, -1.978830, -1.135660, -2.739780, -0.407040, -0.912090,
1.033460, -0.624690, -0.305780, 1.820070, -0.198820, 0.531600, 0.433210, -0.197190, 0.113230, -0.276530,
-0.110950, 0.391130, -2.908180, -0.793650, 1.625090, 0.609970, 1.940990, -0.000360, 0.395170, 1.022910,
0.735390, -0.096090, 0.571370, 0.208920, -0.752650, 0.530790, 0.240900, 1.483630, 0.951840, 0.034950,
-0.611220, -0.488820, 0.337440, -0.760340, -0.371540, 1.346260, 2.296680, -0.954460, 0.079390, -2.076900,
-1.078330, -1.096230, -3.114600, -0.519730, 0.493710, -0.702650, -0.499390, -0.102060, 0.189000, 0.780230,
-1.129920, 0.227960, -1.428650, -0.693380, -0.056040, -2.693860, 1.512040, 0.086740, 2.388730, 2.685460,
-0.640730, -1.853940, 1.057250, -3.124290, 0.217420, 0.668780, -0.098520, 0.438850, -1.429040, 0.627760,
4.453270, -1.356950, 2.750970, -1.150350, -1.970470, 0.182660, -1.148770, -1.450750, 0.140270, -0.797450,
0.350430, -0.463940, 0.477080, 1.198990, -1.909930, 0.424070, 0.037700, 1.317300, -0.588490, 0.624570,
-0.071280, 0.835450, 0.590750, 0.548110, -2.832190, -0.916600, 1.255030, -2.150470, 0.963250, -0.546330,
0.469600, 0.490870, 0.107920, -1.099270, 0.716030, -1.834440, 0.059220, -0.969270, -0.655940, -0.268440,
0.373720, -1.658280, -1.879150, 1.121430, 0.727680, -0.199710, 0.205390, 0.259490, -0.774060, 0.465810,
-1.008040, -1.065090, 0.853460, 0.547650, 0.029690, -0.308600, -4.187780, -0.148120, 1.478520, 0.814350,
0.342060, 1.027100, 0.966300, -0.680180, -1.149410, 0.809660, -2.192580, -0.371140, -0.639000, -1.604230,
-0.125960, -0.295160, -1.436070, 0.422260, -0.249070, -0.246210, 2.743330, -0.991140, 0.450370, -0.156890,
-1.781250, 2.721690, 2.309130, 0.181610, -1.740540, -0.346090, -1.395690, 1.082100, 0.206070, -1.106780,
1.426520, -1.661290, 1.416970, 2.067470, 0.041920, 1.296730, 0.663060, 0.351910, 3.205620, -0.056560,
1.745860, 2.224160, 1.218830, 0.360630, 1.304840, 1.075270, 0.448140, 3.563000, 0.028630, 2.076650,
1.450920, 1.594100, 2.374270, 0.136560, 0.149860, 2.059080, 1.428220, -0.141850, 1.625070, 0.716680,
6.731500, 1.344520,
-0.943640, -0.033260, -1.108000, -1.113530, -0.113620, 0.184030, -2.306030, 3.178310, 1.015430, -0.105420,
-0.016260, 1.505290, -2.059210, 0.912050, -0.049950, 0.773870, -0.586910, -0.957920, 0.825230, 0.631230,
-1.077050, -0.401700, -0.447170, 1.315870, -0.414230, 0.673920, -1.229140, 0.232510, 1.781020, 0.427990,
0.843130, 1.862830, -0.181800, -1.843210, -1.170060, 1.226910, 0.038270, -1.020940, 0.084030, 2.096460,
-1.114460, -0.891530, -2.689460, 0.900860, 0.124000, -1.808460, 0.957930, 0.443230, 0.664260, 0.929930,
-0.698310, 0.480420, 0.483880, -0.306390, -0.634000, -0.642310, 1.273920, -0.179840, 0.488180, -0.156350,
-0.345370, 0.317650, 0.419630, 2.047030, -0.906500, 0.282590, -2.761070, 1.391690, 0.394620, 1.307350,
1.724960, 0.819210, -0.743600, -1.422020, 0.650000, -0.572250, 1.379290, -1.588630, 1.101270, 1.744570,
0.372240, 0.192130, 1.617230, 0.798420, -1.550480, 1.459120, -0.831310, -1.830680, 3.760120, 0.176450,
-1.103930, 0.084640, -0.083440, 1.896780, 0.638550, -0.836360, 2.206830, -1.723580, 1.431660, 1.205970,
-4.112300, 2.573360, -0.898710, 5.239640, 0.526730, 0.855680, -0.213770, 3.209950, 4.090850, 1.914320,
0.402140, 0.809120, 1.258140, 0.822930, -4.914470, 0.193250, -3.893310, -2.199280, -0.358850, -1.239780,
1.742900, -0.058570, -0.917410, -3.688880, 10.677150, 1.017900, 0.955600, -0.329810, 0.446340, 0.930230,
0.521150, -0.586990, -0.748180, -0.254800, -0.725810, -3.657080, 0.947410, -5.642230, -10.573450, -0.996740,
6.408480, 1.631630, -0.081150, -0.734490, -0.817570, 12.836800, 1.584700, 0.996310, 0.293290, 2.709520,
3.394030, 1.177600, -2.062880, -0.964150, 0.714420, 0.661870, -3.613990, -0.492120, -6.960090, -4.563890,
0.222520, 10.152820, 2.986210, 1.270870, -0.163850, -0.260690, 11.502470, 0.569420, -1.279380, -0.002620,
3.502810, 0.155000, -1.403380, -0.603310, -0.236310, 5.609390, -0.607820, -0.909620, 1.106570, -1.047300,
-2.743970, -0.274590, 5.998300, 1.651900, 0.751770, -2.706750, 2.607550, 1.248470, 0.645650, -0.289130,
0.566110, 5.677680, -0.101140, -1.156260, 1.028030, 1.562190, 0.949560, -1.866940, -1.897550, 1.020780,
-7.559770, -5.207590, 0.278460, 13.844010, 1.153840, -0.368370, -2.049460, 0.715070, -0.429890, 1.167780,
0.806720, 0.814720, -0.365380, -0.612700, -5.076730, 6.710580, -0.829690, 5.750780, -2.577040, -1.591010,
0.375950, -1.683960, -3.386000, 0.938170, 3.144990, 0.312860, 0.062870, -2.295870, 0.579950, 0.766240,
0.073030, 0.575780, -0.071730, 0.357620, 0.371680, -0.657340, 0.037940, 0.748530, -2.425660, -0.761410,
-0.543830, 0.084540, -0.105970, 0.179360, 0.964680, 0.136770, -0.505690, 0.364340, -0.265840, 0.250050,
0.603910, 0.707990, 0.235510, 3.633050, -0.683650, -0.524750, 0.240240, 0.902840, 0.875300, -0.300460,
-2.759810, -0.893720,
0.269320, 1.891420, 0.730700, 0.752300, -0.089120, 1.070900, -0.291920, -0.391780, 0.859450, -0.862920,
0.016500, 1.500810, 2.031130, 1.676060, 0.278570, -1.895590, 1.400820, -0.192180, -0.084810, -0.530510,
0.018060, -0.052060, 0.253530, 0.225480, 0.150490, 0.230440, -0.293810, 1.514570, -0.091100, 0.347310,
1.164300, 0.083110, 1.288640, 1.379450, -0.466110, -0.781710, 0.463000, -0.198930, 2.010070, -0.638470,
0.183690, -1.231870, -1.425350, 1.195850, 0.188580, 1.082290, 0.744520, -0.205390, 0.378960, -0.336420,
-0.273490, -1.085810, -0.630450, 2.693740, 1.525530, 0.511010, 0.444150, 0.706230, -0.301840, -0.055400,
-0.078680, -0.569030, -0.204810, -0.387630, 0.980430, -0.484750, 1.345740, -0.958330, 0.728550, -0.167520,
1.599160, -0.463180, 0.206770, -1.519960, 0.972050, 0.358160, -0.174770, -2.776800, -0.456270, -1.330200,
-0.059850, 0.554570, 0.946570, -0.197410, -2.943180, 0.851120, -1.126880, 0.791480, 1.863100, 1.308310,
0.225860, 2.407110, 0.821330, 1.780750, 0.237180, 0.013250, 1.488500, -0.232250, -3.104980, -0.206430,
-3.114540, 0.675510, 0.602320, 2.191750, -0.919740, -0.519290, 2.255280, 0.535170, -1.121890, 1.237370,
-0.231250, 1.681090, 5.924160, 2.472010, -2.472180, -0.147970, -0.939880, -0.097840, 1.694740, -6.623170,
0.142900, -0.178690, 2.085320, 0.715770, -0.585480, 0.347570, -2.226470, 0.991470, 3.282080, -1.118950,
1.124440, 2.872880, 1.643670, 7.087680, 1.436380, -1.305150, 1.700090, -1.936130, 0.967300, 2.918050,
-6.513000, 1.161170, -1.673890, 3.061970, 3.321840, -3.007070, -0.448840, -2.324360, -0.576010, -2.379880,
-1.697310, -0.192730, 2.210020, -0.327460, 4.402160, 0.303900, 1.928940, 1.841720, 0.477840, 0.043290,
-0.216790, -4.976120, -1.071360, -2.560100, -0.254110, 0.993090, -4.232810, 1.233010, -1.029650, 1.104020,
-0.832830, 1.002600, 0.860280, 0.820630, 0.681070, 2.484850, -1.047720, 0.299090, 1.855150, -0.159230,
-0.491180, -0.493340, -0.399380, 0.029110, -1.958220, 0.611460, 1.475880, -0.275110, -0.628630, 0.820130,
2.634290, -0.054940, 1.684170, 2.491510, 1.490690, 0.746330, 3.901720, 2.216420, 0.134120, 0.730170,
-0.971490, -2.133000, -1.127800, -1.531660, 0.874560, -0.016770, -1.504200, -0.987080, 1.426630, 1.576390,
-0.658480, -0.458240, -1.196510, 0.510820, -0.032330, 0.818760, -0.294830, 2.114720, -0.071000, 0.102050,
0.346290, -0.582690, -1.944730, -0.287650, -0.964960, -0.101120, -1.989440, 0.363970, 0.328790, 0.381170,
-0.985640, 1.064600, 0.104620, -0.498120, -0.507830, -1.154960, -0.472730, 0.181940, 0.914650, -0.560270,
-0.856620, -0.488730, 0.311980, 0.275160, 0.331280, -1.725310, -1.221830, -5.116970, 0.058100, -2.023410,
-1.086300, -0.572570, -0.454730, 3.857620, -1.269590, 0.145810, -0.865580, -0.079790, -1.118190, -0.026500,
-0.108600, -1.242310,
-0.845490, -0.255350, -1.329520, 0.960780, 0.801640, 0.919910, -1.078460, 1.707130, -0.562140, 1.325040,
2.068790, 0.627980, -1.769800, -0.800500, 0.466940, 0.481820, 0.124170, 0.684770, 1.002230, 2.150520,
0.832080, 1.418090, 0.919380, 3.859290, -0.946820, -0.394150, 0.341600, -1.064480, -0.516260, 0.092780,
0.321410, -2.195990, -0.650020, 0.046890, 0.607450, -0.751530, 0.540040, -0.091890, 1.379820, 0.925330,
-0.183200, 0.871250, -0.341850, 0.384160, 1.928590, 0.487910, 0.915930, -0.188000, 0.591360, 1.664460,
0.304690, -0.024370, 1.802770, 0.518770, -2.068330, -0.413210, 0.767080, 1.105120, 0.374250, 0.459250,
0.250490, 3.101340, -0.490730, 0.687680, 1.246870, 0.190760, -1.906100, 0.095180, -0.672860, -0.320260,
1.810080, -1.118630, -0.606370, -0.129380, -1.553530, -3.268150, 1.713790, 0.225990, -0.190250, -1.470260,
-1.214660, 0.914330, 3.556950, 0.793120, -0.634710, 0.085870, -1.102410, 0.209900, -1.890450, -0.181990,
-1.313520, 3.405130, -1.275490, -0.042060, 0.960750, -2.431180, -1.170660, -0.681370, -0.703690, 0.704280,
0.231710, -0.845220, 0.752670, 1.265700, -0.313390, -0.209040, -0.135550, 2.688060, -0.131720, -0.287170,
0.580180, -0.038780, 4.104480, -0.116790, 0.789990, -0.135520, -0.122850, -0.807950, 0.846620, -4.342530,
0.253890, -0.985290, 1.086200, 1.314260, -1.535330, 0.735140, -0.073700, 0.472110, 3.130160, -0.772420,
-0.434010, 2.164760, 1.923820, 0.899370, 0.798560, -0.259350, 0.486990, 1.601110, 1.717330, 0.336310,
-2.582450, -1.037020, -0.073860, 3.035330, 1.191550, -2.282830, 0.098980, 0.392130, 1.017520, -1.027880,
-0.204460, -0.840420, 0.471080, 0.020380, 1.361010, 1.597840, 0.651620, 0.636660, -1.282040, 2.666130,
-0.382170, -3.069840, 0.111750, -2.231760, 1.419800, 0.120250, -1.288130, -0.733540, -1.002690, -0.320240,
-0.065680, 1.139410, 1.084760, 0.206130, -2.485670, -0.006310, 0.979270, 1.598670, -0.440230, 0.764020,
0.418140, 1.547970, -1.592840, 0.216780, -0.379860, -2.257080, -0.829900, 0.219760, -1.970950, -0.416770,
0.393890, -0.897670, 1.072150, 0.271960, 0.449830, 0.282280, 0.337240, -0.340230, 0.293830, 1.763240,
1.036170, -0.451000, 1.725380, -1.625150, 1.661560, 0.320300, 0.443210, 0.931930, 1.598180, -1.308410,
0.077410, -0.684330, -0.699730, 0.622230, 0.573760, 1.304870, 0.038500, -0.179740, -0.142860, 0.371500,
0.619720, -0.467440, -1.171700, 1.332480, -0.690510, 0.511240, -0.555550, 1.085100, 0.727870, 0.455530,
-0.273030, 1.655210, 0.325300, 0.127390, -0.399380, -1.604870, 1.538070, 3.311360, 1.570110, -0.696750,
1.589680, 0.781850, -0.008690, 1.011430, 0.339000, 1.670660, 0.311190, -2.182120, -0.292300, 0.803600,
0.351320, 0.552680, 0.759160, 0.475560, 1.215410, 1.120920, 1.691990, 1.086450, 0.211430, 0.865960,
0.046130, -0.569940,
-0.607280, 0.158670, 0.492560, -0.178810, 0.028820, 0.917810, -0.243830, -1.103940, 0.742500, 0.827720,
0.622620, -0.233320, -1.005580, 1.788330, 1.100940, 0.055630, 0.998470, -0.848110, 0.513410, 2.534420,
0.673480, 0.547170, 0.834970, 0.025070, 1.048180, 1.009650, 1.093170, -1.522550, 3.119700, -0.067790,
-0.946480, 2.241070, -1.093940, -0.647320, 1.502410, 2.117210, 0.428220, -2.163890, -0.323660, -1.201650,
0.465860, -0.106140, 0.676130, -1.082180, 0.900160, 1.915400, 3.571390, 0.210790, 0.766830, -1.946070,
0.142970, -0.356780, 1.882840, -1.158960, -1.117280, -1.391890, 0.384430, 1.007320, -1.249610, 1.007920,
-1.862780, 0.969240, 0.880550, 0.312160, -1.114510, 0.010590, 1.018630, 0.283320, -0.276370, -1.910580,
-0.846410, 0.088080, -1.969040, 1.053540, -2.329080, 1.183440, -0.569800, -0.428040, 0.591820, 0.738830,
-0.268070, 0.216900, 3.124190, -0.465370, 1.843380, 0.066250, 0.916670, 2.312740, 0.985540, -0.493880,
-2.103020, 1.645170, 1.362270, -1.611670, -0.552350, -1.772400, -2.438030, -0.995240, 3.232490, 1.632310,
-1.519680, 3.060040, -1.863500, 2.256500, 0.749750, 0.162570, 1.202390, -0.609890, 0.269310, 0.787080,
-0.807750, -0.154710, 1.108140, 0.291350, -1.915040, 1.807780, -1.982890, -2.566220, -1.347870, 2.824630,
-0.502860, 0.510390, -1.368240, 0.420550, 0.225610, -0.240280, -0.316200, 0.431970, 1.077760, 0.033880,
0.123730, 0.526640, -1.025910, 4.773460, -1.453480, -0.371510, 1.786960, 0.102220, -2.039740, -0.874600,
2.001150, -0.273660, 0.001550, 1.322830, 0.396530, -0.710870, 0.991120, 0.178310, 1.343900, 1.338160,
-0.687600, -0.565240, 1.223300, -2.074860, 2.974060, -0.388400, -1.710620, 2.346910, -1.006500, -3.743810,
0.578940, 1.416190, 1.063430, -1.025310, 0.735440, 0.924900, 0.046220, -0.387070, 1.201000, 0.052140,
0.284390, -1.208420, 0.960720, -0.275800, -0.442130, 3.664520, -1.243470, 1.895670, 0.309980, -3.966330,
-3.401910, 0.156590, 1.232870, -1.113970, -0.320870, 1.679740, -1.956920, -0.206070, -0.421260, 1.799110,
0.503720, 0.877170, 0.000640, -0.054700, 0.883510, 0.169360, 3.252890, -0.118740, -1.612340, -0.666610,
-2.097270, -3.909350, -0.475680, 1.818810, -0.134710, 1.689560, -0.839130, 0.169680, 0.225540, -0.984340,
0.950720, -1.735240, 1.731420, -1.148530, -0.191690, -0.297940, -1.758820, 3.373970, -3.135470, -2.255780,
-1.161150, -4.844750, -9.386960, 0.631750, 4.175850, 0.873800, 0.638010, -1.868800, -0.444270, 2.585650,
-1.288820, 1.057240, 0.355130, -0.944480, -0.311260, -0.570260, -0.821800, -0.062710, -7.083810, -0.043860,
-0.443640, -0.034160, 0.994910, -0.950140, 0.641730, 0.062740, 0.647090, -2.154200, 0.137550, -0.061450,
-1.300650, -0.417730, -0.426560, 0.577440, -2.253660, 0.512440, 0.434210, -0.868750, -0.523340, 0.655390,
-2.305220, -0.556530,
-1.711220, 0.727260, 0.472190, 0.448050, 0.354280, -0.100420, 0.160730, 0.090470, -1.359050, 0.099480,
-0.139070, 0.230000, 0.631290, 0.164250, -1.206410, -0.599430, -0.081400, 0.583260, -0.501690, 0.407020,
0.361500, -0.206550, -0.752370, 0.373720, -0.413930, -1.961930, 0.121350, 1.188540, -1.589830, -0.615490,
-0.069010, 0.137760, 1.359320, 0.712210, 0.465530, -1.437640, -0.689530, 0.850190, 0.419460, -0.554230,
-0.446440, -0.259720, -1.194280, 0.304160, 0.803880, -0.840160, -1.354820, -0.348360, -0.215180, 0.161010,
0.298760, 1.360210, -1.573950, 1.353470, 0.631300, -0.378500, -1.269010, 0.320350, -0.605150, 0.640410,
0.410180, -1.377270, -2.005560, 1.813770, -0.578860, -1.995490, 0.875230, -0.528570, -0.627840, -2.223130,
-1.746890, 0.720090, 0.281340, -0.079650, 0.137930, 0.878620, -0.056370, -2.408800, 1.875110, -2.785980,
-1.628420, 1.094340, 0.102100, -2.351900, 0.290910, -0.024680, 2.090840, -0.887870, 0.028700, 1.292360,
-1.531400, -1.219470, -0.810880, -0.226990, 0.289430, -0.170100, -2.070990, -1.320390, -0.292510, -0.425710,
-0.149580, 0.939220, -0.762630, -1.247470, -2.307050, 0.211690, 0.385340, 0.205610, -0.284660, -0.571680,
0.707550, -0.460860, 0.669620, -0.563100, 1.892680, 0.446870, 2.418720, -0.346260, 0.105140, -0.233340,
0.439820, 0.521010, -1.274130, 0.750940, -0.478120, -0.349080, 0.790190, 1.006690, 1.802700, 0.549070,
-0.844210, -1.007760, -1.181140, 0.441010, -0.897430, -0.150400, 0.491760, 2.659130, -1.954200, 1.407480,
0.883990, -1.944670, -1.060220, 0.193320, 0.318270, -0.084740, -0.185540, 0.301280, -0.755860, 1.022990,
0.410210, -0.739870, 0.967040, -1.895650, -0.624550, 0.185910, 0.924410, 0.051510, -0.386450, -1.790800,
0.221260, 0.155940, 0.087600, -1.015120, -0.820000, -1.744690, 0.814340, 0.473230, 0.465190, 0.624450,
0.390290, -0.314540, 1.157100, -0.908000, -1.535320, -0.812640, -0.590860, 0.651090, 0.560070, 0.299090,
-1.020400, -0.437410, 0.650830, 0.881730, -0.355940, 0.311480, -0.222590, 2.499030, -0.771520, 0.171730,
0.300130, -0.967370, 0.268140, -0.219790, -0.223360, -0.267860, -0.116840, 0.560500, 0.445580, 0.807740,
0.771040, 0.508450, 0.916900, 0.660340, 0.533430, -1.814610, -0.313950, -0.492690, 0.280530, -1.112210,
-0.959170, 0.251730, 0.068920, -2.087930, 0.663620, 0.859400, -0.896090, -0.532570, -0.489060, -1.988690,
0.207380, 4.286200, -0.595050, -1.302530, -1.152740, -0.108630, -0.681540, 0.532550, -0.022330, -0.228250,
-1.082470, -1.907710, -1.361180, -13.202930, -0.666810, -0.632940, -2.077730, -1.805850, 0.821480, -0.760750,
0.179610, -2.106910, -1.250640, -2.033100, -0.675780, -0.025670, -2.763670, -1.713990, -1.418450, -5.556960,
-0.171100, -2.909370, -3.513340, -3.877940, -0.858940, -1.041110, -0.355950, -3.643000, -1.146140, -1.233100,
-0.794270, -3.414040,
-0.078970, -0.677980, -1.652960, -0.500210, 1.090330, 0.943140, 0.360270, -0.889970, -0.158440, -0.371220,
0.486280, -2.558290, -1.031620, -0.709070, -0.030710, 1.296750, -0.032250, -1.805310, -0.089890, -0.534880,
0.929240, 0.998560, -0.746360, -0.641750, 0.183130, -0.046800, 0.509220, 0.214670, -0.699360, 0.241960,
0.608130, -0.822210, 0.228850, 1.505590, -1.929730, -0.474960, 0.131140, -1.813880, -0.768180, -0.309440,
-1.034060, -0.934610, 0.651340, -1.194680, -0.089960, -1.466650, -0.742320, -0.837680, -1.792580, -0.590650,
-0.446960, 0.685700, 0.622750, 0.196840, 0.012080, -0.205260, 0.331610, 0.225160, -1.686880, 1.703570,
-0.180830, -0.181710, -1.445540, 0.938370, -1.285100, 1.535070, 0.567950, 0.045640, -0.936310, -1.427360,
-1.265050, -0.819140, -0.278200, 0.373370, -0.166170, -1.428410, 0.611590, -0.931260, -0.577890, 0.333260,
1.089730, -0.689750, 0.140930, 0.420200, -1.318510, -1.552570, 2.829410, -1.511280, 1.192680, 0.753600,
0.248140, -3.019850, -0.703640, 0.128890, 1.000140, 1.218240, 3.155460, 0.691990, -1.051450, -0.661360,
1.740330, -2.287270, 0.128010, 0.109720, -0.325510, -1.527240, 0.047570, 0.283980, -4.304350, -0.383060,
-0.102520, 0.819840, 1.665800, -1.055820, 0.007680, -2.076250, 1.457610, 3.115350, 2.943690, -1.094000,
-1.704530, -0.355180, -0.765180, 0.848760, -1.968900, -1.075730, -1.651390, -0.124770, -1.094800, -1.543430,
0.504980, -0.995970, 3.321880, 1.068480, 2.129950, 0.908980, -1.808300, 1.863670, 6.177190, 0.351690,
-4.681180, -0.289920, -1.406180, 0.392800, 1.091850, -3.463910, -0.101030, -2.253990, -2.487880, 0.077400,
1.856340, -0.119200, 0.182490, 2.335250, -1.220060, 5.267590, 0.478960, -0.175430, 2.262010, 6.530960,
-0.525770, -4.332150, -0.887840, 1.267990, 2.204520, 2.189610, -1.558830, 0.079020, 2.200470, -0.315070,
-0.794370, 0.259220, -1.635500, 0.926520, -0.090790, -0.795050, -0.362420, 0.260590, -0.033160, 2.807460,
3.735710, 0.683340, -3.976740, -0.154250, 0.460910, 0.498270, -0.279980, -2.764840, 0.455010, -0.772770,
-0.140010, -2.046420, -0.861920, -0.074490, 0.746180, -0.686160, -0.727100, 0.528480, 1.271450, -1.361790,
1.701210, 2.502500, -0.733400, -4.661040, 0.497240, 0.868820, -0.465620, 1.013650, 0.113050, 0.362400,
-1.177980, -0.971480, -1.449330, 1.856660, 1.476340, 2.095020, -1.049660, -1.324030, 1.490720, 1.672470,
-0.799990, 1.713480, 3.752980, -1.930520, -2.057130, 0.228580, 0.361030, 1.948160, 0.362090, -0.200160,
1.519350, -0.212520, -0.397040, -2.327560, -1.161610, 0.017640, -0.596550, -0.531760, 0.273210, 0.211130,
-0.491420, -1.816770, -1.528590, 0.176160, -0.114120, -2.179760, -0.574200, -0.899910, -1.157350, -3.165690,
-0.811070, -1.579220, 0.336420, -3.375500, -0.964830, -0.777220, -2.482200, -0.719260, -1.353690, -0.939680,
-0.291520, -1.096590,
-0.965910, -0.167610, 0.491950, -0.108170, -0.394230, -0.087060, 0.283450, 0.055360, 0.881380, -0.429580,
-0.070930, -0.101020, -0.505070, 0.904930, 0.099980, -0.081010, 0.481320, -0.957260, 0.736600, 1.004480,
0.064040, -0.901090, 0.381560, 0.605560, -0.204320, -0.530090, -0.616280, 0.701090, 0.721230, -0.234120,
-0.074180, -0.402410, -6.630590, -0.630770, -0.715360, -0.322020, -0.789550, 1.013080, -0.554600, -0.647600,
-0.205560, -0.903980, 0.247760, -1.770930, 0.949700, -0.226740, -0.864690, 0.174210, -6.914480, -0.259480,
0.442040, -0.486090, -0.746070, 0.038890, 0.882870, 1.952930, -0.285250, 1.153010, 0.572120, 0.569360,

0.367040, 1.178290, -0.400960, -1.389830, -0.862900, -0.054110, -0.973790, 0.161770, -0.559930, -0.140530,
0.222760, -1.288880, -0.479140, 0.396080, -0.123340, -1.670200, 0.089440, 0.723440, -1.164800, -0.068490,
-0.945710, -1.623940, -0.447460, -0.373720, 0.135610, 0.603780, -2.139850, -0.277430, 0.674910, -1.289350,
-0.281850, 1.185740, -2.549420, 0.633670, -0.303250, -0.833280, 0.607920, 0.009910, 0.160190, 0.801350,
0.702410, 1.149310, -0.121920, -0.446020, -0.395450, -0.486870, -6.934450, -1.204230, -2.834810, -0.400940,
0.543890, 0.505280, 0.065750, -1.469300, 0.347580, -1.840380, -0.072180, -0.549700, -0.243210, -0.241590,

0.088220, -1.149090, -3.236340, 0.856330, -0.661110, 1.073560, -0.247070, -0.073150, -0.398380, 0.190440,
-0.456270, -0.712430, -0.856280, -1.232010, -0.387340, -2.410080, -1.905760, 1.959030, 0.397690, -4.000660,
-2.362720, 1.436600, -0.250270, 0.098890, 1.840240, 0.529000, 0.370630, 0.458200, -2.501980, 0.774890,
-0.072060, 0.500170, -1.114150, 0.384450, 0.284640, 0.346580, -0.541690, -0.045320, 0.258880, -0.875140,
-0.968110, -0.094550, 0.160820, -0.528270, 0.935020, -2.077430, -0.017340, -0.509470, 3.207250, 0.181140,
0.414430, 0.143730, 0.084610, 0.106130, 0.295520, -0.600330, -0.217640, 0.093800, 0.287660, -0.821400,

-1.158730, -0.054370, -1.968800, -0.771830, 0.694360, -0.720410, -1.728040, -0.542100, -0.056960, -1.287230,
0.784120, -0.615660, 0.322030, 0.366650, -0.719290, -2.237330, -1.032750, 0.030950, -1.890690, 0.614960,
-1.178000, 1.036760, 0.252450, -0.861300, 0.913870, 2.449040, -0.221730, 0.199740, -1.822540, -0.836670,
0.098580, 1.167910, 0.694470, -0.013640, 1.252400, -0.442610, -0.290010, -0.078890, -0.864420, 0.567640,
-0.616300, -1.729350, -0.379930, 1.012460, 1.015560, 0.690290, 0.126520, 0.030990, 1.352110, 2.203930,
-0.141370, -0.966910, -0.447910, -0.791400, -0.396580, -0.758520, 0.099440, -0.211250, -0.763740, 0.036590,

0.047630, 0.460130, 0.788210, 1.412010, 1.920230, -0.095550, -0.967890, -2.295090, 0.542240, -0.108450,
0.437610, -0.352850, -0.737070, 0.791830, -0.356390, -3.514690, -0.576220, 0.743000, -1.748410, 2.678380,
0.500020, -0.356390, -0.230690, -0.879600, 0.446230, 0.479730, -1.080200, -0.028340, -2.131800, -3.527120,
-1.594020, -1.854120, 10.739400, -0.853650, 1.991770, 0.233710, -2.754950, -0.587670, -10.199100, -0.660750,
0.006350, -14.973110, -0.585400, 5.411720, -1.180380, 0.328020, 2.790790, 10.479420, -4.179720, -2.986210,
-0.629060, 4.362440, 0.160670, 0.375370, 0.042210, 1.441940, -0.482880, -1.359750, -1.062020, -2.299030,

0.058740, -0.556640, -0.276940, 0.937530, 0.915310, -0.820850, 1.899090, 0.702320, -0.385200, 0.535540,
-0.555160, -1.119790, -0.490280, -0.102790, -0.341510, 1.651040, -1.314630, 0.606750, 2.204620, 0.577710,
0.120700, -1.749500, -3.764630, -0.724670, -1.168440, -0.730910, -0.320410, -1.094270, 1.330000, 0.821930,
0.653940, -0.506940, 0.375150, -0.881280, -0.048950, -0.265310, 1.012040, 0.289230, 0.797160, -0.187240,
-0.238220, 2.834310, -0.366880, 0.277780, -2.475060, 0.813080, -1.883530, 0.840560, 0.962600, -0.454210,
-1.274160, -1.504070, -0.771160, 0.280870, 0.629570, 0.687450, 0.252690, 1.033210, -0.809530, -0.657170,

-0.014110, -0.351150, -2.910070, -0.459980, -0.007340, -0.897400, -0.852560, 0.432050, -1.339700, 0.740350,
0.052070, -0.630750, 0.666820, -2.325160, -0.704760, 0.346710, -2.030160, -0.031930, 0.974240, -1.039210,
1.055300, -0.885760, -0.150720, 0.390180, -0.956300, -0.362360, -0.947650, -3.525240, 0.277850, 0.777290,
0.556680, -3.911560, 0.127620, 0.417340, 0.850500, 0.078210, 1.560260, 0.338010, 1.280330, -0.545130,
-0.633460, -6.019330, 0.596830, -1.483240, -0.727620, -0.475810, -0.229430, -0.373380, 0.341620, 0.850330,
1.184940, 0.385340, -0.975990, 0.226650, 1.446060, 1.187760, -1.167770, -0.023650, 0.194240, 0.941930,

0.440600, 1.326840, 0.427540, 0.898960, -0.852720, 0.000260, 3.129040, 0.309430, -0.190550, 0.216210,
-0.496670, -0.787780, 0.203770, 0.144970, 0.731020, 0.757320, -0.445950, -0.670130, 0.349330, 0.977800,
-0.178860, -0.440780, 1.250230, 0.620120, -0.152720, -0.752860, -0.526190, -0.316760, 1.038560, 0.649840,
-0.485210, -3.571370, -3.304130, -1.094550, -0.526130, 0.848420, 2.534590, 0.017080, 1.371250, 0.466460,
1.299460, 1.994420, -0.047930, -1.634910, 0.000500, -0.348180, -1.801490, -0.993790, -0.423280, 1.598910,
-0.532250, -3.065610, -0.276820, -0.271930, -0.266040, 0.817510, -0.818280, 0.057680, -0.697440, 0.593060,

-0.290340, 0.946360, -4.236130, 0.460620, 0.778320, 0.972490, 1.081690, 0.925890, -0.198140, 0.745190,
-3.830770, 0.198640, -0.179000, -0.123030, -0.149760, 2.469660, 0.637230, 0.286030, 0.878670, -1.406410,
1.070860, -1.228100, -4.861270, -0.122410, -1.151970, -0.649570, -0.064880, -1.547240, 0.144870, 0.144520,
-0.280560, -2.440940, 0.934560, 2.009310, -0.092760, 0.072840, -0.677820, -0.396860, -0.176960, -0.766510,
0.559270, 3.134740, 1.000530, 0.018050, 0.672930, 0.135310, -0.898500, -0.072400, 0.131800, -0.938160,
0.666780, -0.980700, 0.678220, -0.230290, -0.215030, -0.983470, -0.749200, -0.462300, 0.743870, 0.668790,

34.373138, 1.483420, 35.235020, 1.481700, 33.402309, 0.912260, 34.807320, 34.872391, 0.629340, 35.014759,
0.671580, 33.397991, 0.192380, 33.745270, 0.422070, -0.239110, 34.109070, 33.894489, 0.327010, 33.865528,
1.060700, 12.226920, 34.942070, 33.463211, 34.083420, 0.247270, 34.753139, 34.878922, 34.699730, 1.376190,
34.607849, 34.036461, 1.362630, 33.315048, 34.691761, 0.010910, 35.142319, 11.300800, 0.588700, 34.734509,
34.334438, 33.377522, 34.047199, 0.879240, 34.479561, 34.923328, 34.389778, 0.922610, -0.131510, 34.198589,
34.598331, 0.855180, 33.938389, 33.702469, 0.992850, 34.281078, 33.658020, 33.718819, 34.935940, 33.586079,

0.954180, -0.027120, -0.209960, 1.019630, -0.541580, 1.386730, 0.958360, 0.654480, 0.456620, -0.604120,
-0.918870, -0.878910, -0.153950, 0.390930, -0.213190, 1.311190, 0.302320, -0.589390, -0.292470, 0.643660,
-0.360160, -0.560170, -0.245060, 0.843730, 0.391620, -0.092460, -0.648540, -0.606350, 0.840560, 0.001330,
-0.280110, -0.795090, 1.648540, -1.348830, -0.737840, -0.592820, 0.270560, 0.038940, 1.334640, 0.006760,
-0.257430, 1.592620, 0.729380, 3.741760, -3.793090, -1.178400, -1.295900, -0.510330, -5.887210, -0.353300,
-0.112490, -2.194740, -0.248970, -0.713580, 0.377660, 0.539490, -1.329600, 0.347260, 0.808530, 0.026820,

-0.912850, 0.632470, 2.001400, 0.722960, 0.892930, -1.812430, 0.944350, -0.079330, -1.388740, 0.585360,
-0.211110, 0.194620, 0.112890, -0.507500, -0.422530, 0.696720, -0.085860, 1.445790, 0.612150, -0.111420,
0.104520, -1.323930, -1.759300, -0.851520, -0.789420, -5.987580, -0.447240, -2.177640, -2.376370, 1.780290,
0.117260, 0.935300, 0.425580, 0.274910, 0.041430, -2.123720, 3.111240, -1.129070, -1.462430, 0.323390,
-1.313220, -0.212540, -1.014090, 0.026920, 0.469540, -0.031970, 0.409820, 0.661950, -0.740380, 0.533870,
1.081940, -0.216310, -0.348100, -0.309390, -0.742940, 0.324280, -0.136840, 0.854670, -1.073240, -1.018430,

0.242810, 0.720530, -0.535950, 0.193340, 0.145400, -0.487530, 1.215620, -0.015240, 0.152100, 0.847890,
0.438490, -0.401390, -0.551820, 0.174160, 0.329730, 1.128370, -0.456130, -0.606630, -0.176280, 0.472690,
0.144630, 0.804210, -1.105240, 0.747500, -0.777290, -0.377090, 1.427760, -0.036000, -1.245070, 1.071570,
-0.944880, -0.162400, -0.176300, -1.011930, 0.488810, 0.804890, -1.045020, -0.092310, 1.367220, -0.362510,
-0.205490, -4.274420, -0.463560, 1.506330, 0.779710, -1.534990, -0.771050, 0.374430, 1.235380, -1.445330,
1.295150, 1.106090, -0.841580, -0.125470, -0.470780, 0.727330, -1.226550, 1.002360, -0.476330, -0.304610,

-0.350170, -1.175350, -0.633820, -0.825920, -0.632930, 0.270650, -3.723230, -0.919330, 0.451260, -0.818540,
-0.064170, 0.068350, 0.651760, 0.572640, -0.771100, -1.644430, -1.445050, 0.014900, 0.235550, -1.696370,
-0.625900, 0.957070, -0.370830, -0.061140, 0.360400, 0.171040, -0.695880, 0.368020, -1.902370, 0.831610,
0.073620, -3.982430, 1.443730, 1.293980, 0.195120, 0.444900, -0.324250, -0.095310, -0.317920, 0.217920,
0.610340, 1.332680, -0.568390, 0.627330, -2.573530, -1.845300, 0.821330, 1.246880, 0.718370, -0.666060,
-0.976260, 0.181310, -0.134550, -0.879510, 0.062980, 1.037440, 0.751800, -0.125500, 0.287350, -0.580360,

-0.952340, 0.976380, -0.370460, -1.150750, -10.614710, -2.235450, -0.764150, -0.436910, 1.523460, 1.406740,
-0.717680, -0.914980, -0.994390, 2.123230, 1.887030, -0.217670, -0.731620, 1.898270, 1.680110, 0.069920,
0.467620, 0.977630, 0.822290, -0.323300, -0.127890, -3.140190, -1.985470, -0.203650, 0.604960, 1.064890,
0.137930, -8.666280, 0.510630, 2.319220, 0.282510, 0.543500, -3.646860, -0.688750, 3.453270, -1.160980,
-2.284580, -1.173900, 0.506120, 1.021990, 0.751220, 0.481880, 0.717310, -0.296440, 7.522550, -0.354560,
0.172210, 1.279060, -0.824400, -0.738330, -0.508290, -0.211520, 0.212140, -1.434510, -0.200320, -1.250360,

0.053060, 0.684260, 0.670370, -0.904100, -0.675610, -0.894460, -1.773230, 0.261750, 1.086350, 0.672760,
-0.535710, 0.108270, -0.085920, 0.631070, -0.306140, -0.012900, 0.668490, 1.055870, 0.303910, 0.162030,
-0.594990, 0.321550, 0.884230, 0.549010, 0.392360, -0.603430, -0.605730, -0.541460, -0.570870, -0.515180,
0.612540, 1.742010, -0.046710, -0.442650, 0.409880, 0.848390, 0.865410, -0.724660, 0.395670, -0.324950,
-0.268840, -0.943570, -0.323200, 1.193760, -0.825980, 0.572950, 0.831650, 0.080690, 0.700560, 0.149230,
-0.344050, 0.359120, -0.935790, 0.361400, -0.239370, 0.344300, -0.832870, 0.213790, 0.162030, -0.595820,

0.876300, -1.034270, -0.207920, -0.071920, -0.337190, 0.770270, -1.511160, -0.521620, 0.494470, -0.635030,
-0.924170, 0.703340, -0.133290, 0.609670, -1.308160, -2.335630, 0.110220, -0.078260, -1.094720, -0.823630,
-0.652270, 2.710130, 0.615050, -0.410650, -0.096880, 0.761510, 0.507860, 0.657570, -1.756250, 0.313600,
-0.484020, -0.868170, 1.948160, 0.870690, 0.222480, -0.019050, -2.360390, -1.251980, -0.604810, 0.042890,
-1.242990, -4.623480, -0.513390, 1.326760, -1.976880, -0.478310, -0.095820, -0.621760, 1.032820, -0.332550,
-0.825990, 1.744260, 0.150800, 0.127430, -0.657640, 0.364450, 0.390320, -1.379210, 0.554310, -0.506230,

-0.499420, -9.190680, -5.563270, 0.643830, -1.024250, 1.012960, 1.907750, -1.311650, -1.593010, -2.252240,
-1.501460, 1.132070, -4.741930, -1.564210, -2.732800, 0.180250, -1.486220, -0.762690, -1.857950, -2.022140,
2.519730, 3.138370, 1.713200, -0.389330, -0.547090, 0.899700, 0.275520, -1.099410, -0.829920, -0.469020,
-0.142930, 0.980800, 6.734290, -1.000120, -0.359540, 3.426060, -0.490570, 1.520110, -0.271260, -1.714060,
-0.111940, 1.870110, 0.688760, 1.585950, -20.968731, 1.720340, 1.436110, -1.797010, 0.706090, -0.846540,
1.531120, 1.657640, 0.026950, 0.195150, -0.482280, -2.632840, -0.521000, 0.382830, 0.192960, -0.196650,

-0.477160, -1.978080, -0.103440, -0.193260, 0.699860, 0.326180, 0.042040, 0.030870, -20.142349, -1.852970,
-0.224090, -1.239930, 0.244220, -0.104490, -0.331600, -1.176500, -1.503620, -0.573730, -0.315290, -0.514980,
-0.053440, 1.052380, -0.649870, -1.682620, -0.317010, 1.382580, 0.081910, -0.345320, -0.650100, 0.174130,
-0.329350, -0.553410, 1.047280, -0.038490, 1.347270, 0.534610, -0.416970, 0.319200, 0.394270, -0.156660,
0.134550, 0.043600, -0.513540, -0.960990, 1.679440, 0.024710, -1.757690, -0.733560, 0.223240, 0.971350,
1.642710, 0.411270, 0.570260, -0.300360, -0.673100, -1.202080, 0.205430, -0.078090, 0.534400, -0.274920,

-0.627350, -0.520150, 0.882020, -0.481400, -0.905490, -0.806040, -0.557190, 0.363020, -0.864580, 1.294960,
-0.847660, -0.536370, -0.516210, 0.627260, 0.502420, 0.903070, -0.251150, 0.301530, 0.173080, 0.541870,
0.633480, -0.621980, -0.926940, 0.704060, 0.223980, 0.286730, -0.883180, 0.615890, -0.742720, 0.182330,
1.051320, 3.358650, -0.384950, 0.306670, 0.467540, 0.019350, -0.817150, -0.652630, 0.324080, -0.653010,
0.071930, -1.959340, 0.439350, -0.796500, -0.038520, 1.147520, 0.752520, 0.954960, -3.177550, -0.165790,
-0.096410, 0.035000, 0.206910, 0.437980, -1.550940, -0.428290, -0.754990, 0.275140, -0.474600, 0.790540,

0.205020, 0.463210, 0.396940, -1.820120, -0.603460, 0.210620, -0.488220, -0.383020, 0.789700, 0.326940,
0.347180, 0.495120, 0.264990, -0.433120, 0.278910, -1.227430, -0.161120, 0.629110, -0.885880, -0.356760,
-0.244690, 0.769340, 0.990370, -0.843510, 0.421690, -0.213450, 0.069850, 0.333930, -0.551700, -1.082830,
-0.138490, -0.868550, 1.393180, -0.241310, -0.173610, 0.714770, -0.059300, 0.634160, 0.085030, 0.099700,
1.131320, 1.131030, 0.316580, 0.293920, -0.568440, -0.692070, -0.583230, -0.660070, -0.270820, -0.187300,
0.343440, 0.394250, -0.931910, -0.776670, -0.373810, -0.705990, -0.592960, -0.332990, 0.330490, 0.904710,

0.200460, -1.159000, -3.726280, -0.362730, -0.330120, -0.334040, -0.057970, -0.738650, 0.291100, 0.260490,
-0.355810, -0.452850, -0.162640, -4.289130, 0.562870, -1.048170, -0.072180, 0.898040, -0.954510, -0.194050,
-0.440820, -0.510000, 0.216220, -0.933450, 0.735370, 1.081260, 0.801940, 0.382020, -0.802680, 0.353290,
-0.397350, -0.414740, 0.242700, 0.080810, -1.275370, -0.744650, -0.748080, -0.418680, 0.762330, 0.261390,
-0.169680, -0.126380, 0.418160, 0.368100, 1.249640, -0.180660, 0.031910, 1.553450, 2.101160, -0.359010,
-1.215870, 0.283540, 0.738900, -0.559460, -0.895680, 0.610650, 0.514290, -0.888270, -0.507330, -0.376770,

0.319070, 0.492280, -0.281510, 0.146620, 0.167230, 0.133910, 0.298260, -0.083180, 0.331760, 0.275100,
0.869900, -0.611750, -0.020160, -0.489230, 0.331760, 0.472490, 0.029510, -0.160800, -0.378090, -0.201150,
0.449270, 0.002400, 0.267670, 0.619200, -0.721020, -0.074370, 0.378420, -0.553910, 0.112970, -0.378680,
-0.856420, -1.040550, 4.057740, 0.214120, -0.286570, 1.062870, 1.196700, 0.900640, 1.141620, 0.802680,
0.508100, 0.448710, -2.034610, 2.064440, -0.129070, 0.683630, 2.462320, -4.125080, -2.691250, -1.418310,
0.222190, 1.002310, 0.821460, -0.626730, -1.785550, -0.452420, -0.018480, -0.258700, 0.130080, -1.196210,

-1.728590, -0.183630, 0.392560, -0.446430, 0.847310, 0.429750, -0.921660, -0.708510, -0.495860, -0.350750,
0.886750, -0.070110, 0.522830, -0.456330, -1.262910, -1.451560, 0.713870, 1.972590, -0.756520, 0.318790,
-0.471910, 0.021370, 0.609760, -0.801250, 0.493090, 0.101090, 0.937760, 0.540000, -0.045430, -1.283790,
0.512300, -0.601140, -8.807230, 1.604230, -0.938460, -1.001850, 1.954500, -0.893940, -0.267910, 0.567970,
-0.742280, 0.644900, -0.233930, -6.082150, 0.909090, 0.937630, -0.451930, 0.532750, 2.664420, 0.252190,
-1.637620, -1.532460, 0.288920, -0.144770, -0.650840, 1.915730, 0.814640, 0.360950, -0.019550, 0.043520,

1.003160, 0.064200, 0.521480, -0.424390, 0.318390, 0.648250, 0.716870, -0.565030, -0.384060, -0.128550,
-0.530400, 1.157680, 0.151250, -1.081940, 1.021780, 1.002090, -0.415710, -0.283300, 1.797610, -0.432980,
-0.108190, 0.279900, -0.606450, 1.453080, 0.642640, -0.819480, 1.056850, -0.063540, -0.439780, 1.187140,
-0.525120, -0.940820, 1.441580, -0.370710, 0.577670, 0.543850, -0.678340, -0.136890, -0.849410, -0.312610,
-0.091900, 2.061220, -1.643610, 0.325700, -0.819350, -1.266320, 0.881240, -0.000340, 1.598030, -0.156140,
0.021690, -0.765350, 0.326730, -0.029180, 0.220350, 0.410310, -1.769440, -0.006120, 1.127730, -0.112900,

-0.439170, -0.647100, -0.351200, 1.433480, -0.104580, -1.444150, -1.034010, -2.560080, 0.691010, -1.251740,
0.115200, -0.923380, 1.706010, 0.901780, -0.937970, -3.159060, -1.610310, 2.605410, -2.269100, -0.021450,
-0.875230, 1.846220, -0.570480, -1.254510, -1.070910, 0.402780, 0.390420, -0.883600, -3.767080, -1.683420,
-0.116760, -4.537340, 8.761070, -3.454330, 4.235860, -1.543740, -0.569360, -0.846830, -1.442100, -0.682470,
2.713890, -25.822371, -0.866730, 2.226000, 0.165630, 0.233990, -0.650330, 16.081221, -27.527679, -2.721540,
0.726170, 3.192690, 0.068580, 0.195340, 1.905250, 0.327550, -0.270950, -4.785620, -1.344620, -1.524690,

0.246300, -0.358220, -0.526330, -0.728240, 0.041200, 0.200490, -1.672070, -0.655400, 0.090590, 0.016280,
0.389860, -0.728990, -1.277300, 0.594200, -1.505250, -2.995130, 0.684660, -0.297450, -1.435860, -0.212390,
-1.048670, 1.420430, 0.468840, -0.026680, 0.373220, -0.361860, -0.893740, 0.704800, -1.594140, -0.227200,
0.292920, 0.797220, 4.750610, 0.064520, 0.986610, 0.141880, -1.168120, -0.465820, -1.260410, 0.954110,
0.546180, -2.054700, -0.711860, 5.168120, -0.208250, 0.747840, 0.668420, 0.844730, 0.738540, 0.138140,
0.398930, 1.557940, 0.047750, 0.261490, -0.206280, -0.803590, 0.364280, 0.567530, 0.588380, -0.301050,

-0.108350, 0.066070, 0.085440, 0.642690, 0.629860, 0.518150, 0.828850, 0.363250, -0.414230, -0.019430,
-0.778060, -0.155770, 1.244230, -0.357120, -0.714410, 1.186740, 0.151480, -0.143060, -0.968580, -0.791700,
-0.323360, -1.410400, 0.643910, 0.830540, -0.049940, 0.425440, 0.194240, -0.158770, 2.754540, 0.020850,
0.281830, -0.949700, -0.177240, -0.554790, -0.314220, -0.205140, -1.265980, 0.597830, -0.938470, 0.630400,
0.469800, -2.675660, -0.607520, -0.782680, 1.747110, -0.290230, -2.087960, -1.499170, -2.372610, -0.909700,
-0.245870, -0.560000, 0.208990, -1.442820, -0.290610, -1.152910, -1.843460, 0.177740, 0.223880, 0.682030,

-0.897330, 0.737960, 1.413590, 0.352660, 0.533790, -0.447360, -0.778780, 0.375110, 0.253450, 0.088500,
-0.293960, 0.203580, 0.708990, 0.751610, -0.406010, 0.855290, 1.499370, -0.203300, 0.000180, 0.033250,
0.295570, -1.500640, 0.356470, 0.771340, -0.359050, -0.122480, -0.183200, 0.161000, 0.650430, 0.820670,
0.023310, 1.724270, 0.310900, 1.714590, 1.730800, -0.515070, 0.831830, -1.839540, 0.716390, 0.570330,
0.436240, -2.285090, 0.054650, 0.445090, -2.084870, 0.477630, -0.475920, 0.697490, -0.314190, 0.126530,
-1.032600, 0.191770, -0.665970, 0.650740, 0.063290, 0.257560, 0.153130, 1.936540, -0.005650, 0.362230,

-0.473030, 0.762170, -1.867920, 0.372140, -0.673760, 0.006260, 1.728910, 0.814360, -0.261470, -0.447360,
-1.968220, -0.534240, 0.176230, -0.003600, -0.317720, 1.114980, -0.058820, -2.309110, 1.071630, -0.169480,
1.008690, -0.172720, -0.724950, 0.258010, -0.849330, 0.201010, -1.328170, -0.232570, 1.651100, 0.743060,
-1.155080, -1.774900, 0.020130, -1.783650, -1.104100, -0.397530, 1.350210, -0.593090, 0.487000, 1.100930,
0.450140, 2.534460, 0.774330, 3.217980, -0.861290, 0.072690, -0.795480, -0.024290, -0.110700, 0.160660,
-0.611550, -2.061270, 0.600000, -0.865920, -0.129470, -1.741250, 0.354200, 0.022260, -0.648380, -0.200220,

0.359860, 0.529010, -1.122430, -0.992850, -0.512240, 0.560600, 1.716790, 0.118370, 0.601290, -0.250980,
0.745010, -2.563630, 0.510220, -0.872170, -1.069560, -0.424600, -0.887520, -1.515240, -1.379930, -0.691070,
0.947370, -0.494100, -0.783060, -0.709030, 0.876080, -0.813350, -0.499830, 0.686290, -0.870380, 0.901390,

-0.891900, -3.321580, 0.146050, -0.894950, 0.612360, -1.106790, -1.586710, -1.177110, -0.515700, -0.464260,
-0.103210, -0.854130, 0.739350, 1.078080, 0.675880, 0.346090, 0.075430, 1.385070, -1.268510, -1.022170,
-0.439330, 0.596960, -0.115690, -0.260330, 0.751720, 0.710170, 0.778450, -0.794780, -0.481720, -0.235730,

-0.289110, -0.405860, -0.239240, 0.468450, -0.532190, -0.145200, -1.041450, 0.191190, -0.224720, 0.284770,
-0.864000, 1.827300, -0.666610, -0.845280, -0.137940, 0.601530, -0.312220, -0.606750, 1.392670, 0.662970,
-0.866320, -0.189890, -0.346770, 0.836600, -0.836890, -0.940680, 0.713190, -0.328850, 0.683020, -0.627850,

-0.608620, -0.884300, -1.634400, -1.221480, -0.408960, 1.052490, 0.800040, 0.665630, 0.912090, -0.971150,
0.535840, 0.950600, 0.403810, -0.306880, -0.732220, -0.765640, -1.237260, -0.900710, -2.317310, -0.770860,
0.434050, -1.131160, -0.655560, -0.342490, 0.717820, -0.665290, -0.832680, 0.464400, 0.925320, 0.604850,

-1.008230, -0.859570, 1.638400, -0.776080, 0.602180, -0.874570, -1.560110, -1.042520, -1.088000, 0.526170,
0.057150, -2.240480, 0.210860, 1.331080, -0.094150, -0.319430, 1.103030, 1.487740, 0.280490, -1.030420,
-0.252250, 0.813590, -0.693340, 0.101860, -0.071890, 0.161660, -0.393410, -0.938050, -0.309670, -0.495080,

0.525770, 1.049020, -1.339730, 0.053620, -0.187900, -1.008720, -0.388960, -0.483670, -0.601880, 1.065570,
-0.741620, -0.671530, -0.423450, -1.467320, 0.391600, 0.664070, -0.421660, -0.748000, 0.296860, 0.639360,
-0.359300, -0.448930, 0.205220, -0.006200, -1.249370, -0.235080, 0.376780, -0.520120, -0.143440, -0.743560,

0.082890, -1.819470, -1.222200, -1.278060, -0.235070, 0.984590, 0.578490, 0.190680, 1.169180, 0.290230,
0.008970, 3.572170, 1.064380, -1.183160, -0.817510, -1.007800, -1.006300, -0.989670, -1.874730, 0.516400,
-0.504960, -1.228040, 0.412580, -0.116550, 1.076900, -0.036590, -0.796280, 0.813110, -0.741130, 0.986940,

-0.812920, -0.962650, 1.315440, 0.670210, 0.110360, -0.527270, -1.244800, -0.881750, -0.826790, -1.140710,
0.175080, -3.571180, -0.349310, 1.015620, -0.908590, -1.484730, 0.538640, 0.916890, 2.505530, -0.054160,
-0.128070, 0.722810, -0.068010, 0.291020, 0.617400, 0.468990, 1.141320, -0.777550, -1.232660, -0.668010,

0.400270, 1.982800, -1.342400, -0.308330, -0.143510, -0.924060, -0.366120, 0.031100, -1.038150, -0.262260,
-0.529800, -2.641650, -0.363430, -1.032720, 0.919460, 1.547120, -0.075770, -0.520800, -1.970640, -0.401590,
0.193900, -0.570720, -0.059350, 0.220700, -0.676000, -0.106890, 0.642720, -0.159870, -0.719270, -0.307300,

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
  static UnitType Units[362] =
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (inp1) */
      0.0, -0.278150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.281170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.808340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.180140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.803350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.035610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.064420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.900340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.965410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.719170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.283760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.377930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.774190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.967710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.774630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.593950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.235890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.496200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.741420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.109010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.417100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.472170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.947390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.010240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.734490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.260850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.061300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.198940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.719380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.319930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.066150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.508620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.275080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.990960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.723960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.414020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.492110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.969820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.970500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.631250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.199900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.103350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.919250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.177390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.892890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.851360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.301910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.446090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.038180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.619960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.644000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.433640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.912470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.490390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.669010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.159460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.485930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.469430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.896360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.437630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.811100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.390540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.921000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.402000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.711100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.468040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.378700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.899650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.305790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.924260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.291500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.265330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.805490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.114420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.484140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.055890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.301320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.534800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.122850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.363570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.226040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.519740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.941590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.169430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, -0.501770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.315750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.008870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.638890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.665040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.249140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.659270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.611420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.594740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.266760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.631300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.115910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.522680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.482470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.138150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.339560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.103310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.978200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.670430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.359150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.661830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, -0.629110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.407700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.795930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.968940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.707730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.584930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.001300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.292990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, -0.285510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.063730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.399950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.861230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, 0.051900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.789530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, -0.363240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.747920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.530450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.495240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.782460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.451320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.286430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.469410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.004030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.259210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.554100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.955710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.742630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, -0.369820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.200470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.031140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.627540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, -0.387240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.456900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.171610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.776590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.206580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.031700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.499690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.958200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.324440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.245430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.871340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.450610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.064990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, 0.507730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.898690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.193660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.898100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, 0.640010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.345220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.997750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.313530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, -0.104480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.361970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.924840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.242740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.000430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.225560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.936940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.966450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.113050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.010400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.672180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.368510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.543290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.381330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.201220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.382510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.038130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.910040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, 0.325670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.290470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.086150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.705790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.689530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, 0.254690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.485330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.062930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.356710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.183930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.701300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, -0.120830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.770750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.007190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, -0.330090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.248860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.189440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.159100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.477520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.233450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.808010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.919200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.140280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.236450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.581350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.633850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.977210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.555700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, 0.723850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.484470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.346370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.188100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.657570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.629570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.124980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.595960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.693700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.575810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.726950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.491590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.454220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.473890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, 0.885740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.559280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.291620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.931280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.645710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.378520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, 0.104830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.704020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.639840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.504970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.714830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.246910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.224760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.788860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, -0.599880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (hid11) */
      0.0, -1.050890, 262,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (hid12) */
      0.0, -0.811160, 262,
       &Sources[262] ,
       &Weights[262] ,
      },
    { /* unit 235 (hid13) */
      0.0, -1.031440, 262,
       &Sources[524] ,
       &Weights[524] ,
      },
    { /* unit 236 (hid14) */
      0.0, 0.359880, 262,
       &Sources[786] ,
       &Weights[786] ,
      },
    { /* unit 237 (hid15) */
      0.0, 0.552700, 262,
       &Sources[1048] ,
       &Weights[1048] ,
      },
    { /* unit 238 (hid16) */
      0.0, 0.113120, 262,
       &Sources[1310] ,
       &Weights[1310] ,
      },
    { /* unit 239 (hid17) */
      0.0, -0.566530, 262,
       &Sources[1572] ,
       &Weights[1572] ,
      },
    { /* unit 240 (hid18) */
      0.0, 0.914230, 262,
       &Sources[1834] ,
       &Weights[1834] ,
      },
    { /* unit 241 (hid19) */
      0.0, -0.713420, 262,
       &Sources[2096] ,
       &Weights[2096] ,
      },
    { /* unit 242 (hid110) */
      0.0, -0.222430, 262,
       &Sources[2358] ,
       &Weights[2358] ,
      },
    { /* unit 243 (hid111) */
      0.0, 1.284270, 262,
       &Sources[2620] ,
       &Weights[2620] ,
      },
    { /* unit 244 (hid112) */
      0.0, 1.551460, 262,
       &Sources[2882] ,
       &Weights[2882] ,
      },
    { /* unit 245 (hid113) */
      0.0, 0.682860, 262,
       &Sources[3144] ,
       &Weights[3144] ,
      },
    { /* unit 246 (hid114) */
      0.0, 0.751720, 262,
       &Sources[3406] ,
       &Weights[3406] ,
      },
    { /* unit 247 (hid115) */
      0.0, -0.511030, 262,
       &Sources[3668] ,
       &Weights[3668] ,
      },
    { /* unit 248 (hid116) */
      0.0, -1.830220, 262,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 249 (hid117) */
      0.0, -0.175780, 262,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 250 (hid118) */
      0.0, -0.090090, 262,
       &Sources[4454] ,
       &Weights[4454] ,
      },
    { /* unit 251 (hid119) */
      0.0, -0.142200, 262,
       &Sources[4716] ,
       &Weights[4716] ,
      },
    { /* unit 252 (hid120) */
      0.0, 0.948380, 262,
       &Sources[4978] ,
       &Weights[4978] ,
      },
    { /* unit 253 (hid121) */
      0.0, 0.782450, 262,
       &Sources[5240] ,
       &Weights[5240] ,
      },
    { /* unit 254 (hid122) */
      0.0, -0.385730, 262,
       &Sources[5502] ,
       &Weights[5502] ,
      },
    { /* unit 255 (hid123) */
      0.0, 0.521890, 262,
       &Sources[5764] ,
       &Weights[5764] ,
      },
    { /* unit 256 (hid124) */
      0.0, 1.585050, 262,
       &Sources[6026] ,
       &Weights[6026] ,
      },
    { /* unit 257 (hid125) */
      0.0, 0.968760, 262,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 258 (hid126) */
      0.0, -0.857780, 262,
       &Sources[6550] ,
       &Weights[6550] ,
      },
    { /* unit 259 (hid127) */
      0.0, 1.447510, 262,
       &Sources[6812] ,
       &Weights[6812] ,
      },
    { /* unit 260 (hid128) */
      0.0, -0.290110, 262,
       &Sources[7074] ,
       &Weights[7074] ,
      },
    { /* unit 261 (hid129) */
      0.0, -2.660180, 262,
       &Sources[7336] ,
       &Weights[7336] ,
      },
    { /* unit 262 (hid130) */
      0.0, -0.932090, 262,
       &Sources[7598] ,
       &Weights[7598] ,
      },
    { /* unit 263 (hid21) */
      0.0, 0.295270, 60,
       &Sources[7860] ,
       &Weights[7860] ,
      },
    { /* unit 264 (hid22) */
      0.0, 0.840520, 60,
       &Sources[7920] ,
       &Weights[7920] ,
      },
    { /* unit 265 (hid23) */
      0.0, -1.294500, 60,
       &Sources[7980] ,
       &Weights[7980] ,
      },
    { /* unit 266 (hid24) */
      0.0, -0.705640, 60,
       &Sources[8040] ,
       &Weights[8040] ,
      },
    { /* unit 267 (hid25) */
      0.0, -0.400160, 60,
       &Sources[8100] ,
       &Weights[8100] ,
      },
    { /* unit 268 (hid26) */
      0.0, 0.544800, 60,
       &Sources[8160] ,
       &Weights[8160] ,
      },
    { /* unit 269 (hid27) */
      0.0, -0.809810, 60,
       &Sources[8220] ,
       &Weights[8220] ,
      },
    { /* unit 270 (hid28) */
      0.0, -0.087470, 60,
       &Sources[8280] ,
       &Weights[8280] ,
      },
    { /* unit 271 (hid29) */
      0.0, -0.411610, 60,
       &Sources[8340] ,
       &Weights[8340] ,
      },
    { /* unit 272 (hid210) */
      0.0, 34.865150, 60,
       &Sources[8400] ,
       &Weights[8400] ,
      },
    { /* unit 273 (hid211) */
      0.0, -0.158450, 60,
       &Sources[8460] ,
       &Weights[8460] ,
      },
    { /* unit 274 (hid212) */
      0.0, -0.460840, 60,
       &Sources[8520] ,
       &Weights[8520] ,
      },
    { /* unit 275 (hid213) */
      0.0, -0.081140, 60,
       &Sources[8580] ,
       &Weights[8580] ,
      },
    { /* unit 276 (hid214) */
      0.0, -0.222040, 60,
       &Sources[8640] ,
       &Weights[8640] ,
      },
    { /* unit 277 (hid215) */
      0.0, 0.305070, 60,
       &Sources[8700] ,
       &Weights[8700] ,
      },
    { /* unit 278 (hid216) */
      0.0, -0.025780, 60,
       &Sources[8760] ,
       &Weights[8760] ,
      },
    { /* unit 279 (hid217) */
      0.0, 0.693680, 60,
       &Sources[8820] ,
       &Weights[8820] ,
      },
    { /* unit 280 (hid218) */
      0.0, -1.444540, 60,
       &Sources[8880] ,
       &Weights[8880] ,
      },
    { /* unit 281 (hid219) */
      0.0, -1.088630, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 282 (hid220) */
      0.0, 0.143390, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 283 (hid221) */
      0.0, 0.191220, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 284 (hid222) */
      0.0, 0.585680, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 285 (hid223) */
      0.0, 0.638790, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 286 (hid224) */
      0.0, -0.458080, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 287 (hid225) */
      0.0, 0.683410, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 288 (hid226) */
      0.0, -1.691480, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 289 (hid227) */
      0.0, 0.696130, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 290 (hid228) */
      0.0, -0.905180, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 291 (hid229) */
      0.0, 0.844790, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 292 (hid230) */
      0.0, 0.705030, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 293 (out1) */
      0.0, 0.833150, 30,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 294 (out2) */
      0.0, -0.717210, 30,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 295 (out3) */
      0.0, -0.645400, 30,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 296 (out4) */
      0.0, 0.679170, 30,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 297 (out5) */
      0.0, -0.016830, 30,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 298 (out6) */
      0.0, -0.396230, 30,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 299 (out7) */
      0.0, -0.580660, 30,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 300 (out8) */
      0.0, 0.703790, 30,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 301 (out9) */
      0.0, 0.282930, 30,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 302 (con11) */
0.98907, 0.500000, 2,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 303 (con12) */
1.34162, 0.500000, 2,
       &Sources[9932] ,
       &Weights[9932] ,
      },
    { /* unit 304 (con13) */
1.42756, 0.500000, 2,
       &Sources[9934] ,
       &Weights[9934] ,
      },
    { /* unit 305 (con14) */
0.00271, 0.500000, 2,
       &Sources[9936] ,
       &Weights[9936] ,
      },
    { /* unit 306 (con15) */
1.00028, 0.500000, 2,
       &Sources[9938] ,
       &Weights[9938] ,
      },
    { /* unit 307 (con16) */
0.00077, 0.500000, 2,
       &Sources[9940] ,
       &Weights[9940] ,
      },
    { /* unit 308 (con17) */
0.02726, 0.500000, 2,
       &Sources[9942] ,
       &Weights[9942] ,
      },
    { /* unit 309 (con18) */
1.41946, 0.500000, 2,
       &Sources[9944] ,
       &Weights[9944] ,
      },
    { /* unit 310 (con19) */
1.42327, 0.500000, 2,
       &Sources[9946] ,
       &Weights[9946] ,
      },
    { /* unit 311 (con110) */
0.03811, 0.500000, 2,
       &Sources[9948] ,
       &Weights[9948] ,
      },
    { /* unit 312 (con111) */
1.42856, 0.500000, 2,
       &Sources[9950] ,
       &Weights[9950] ,
      },
    { /* unit 313 (con112) */
1.42835, 0.500000, 2,
       &Sources[9952] ,
       &Weights[9952] ,
      },
    { /* unit 314 (con113) */
0.02805, 0.500000, 2,
       &Sources[9954] ,
       &Weights[9954] ,
      },
    { /* unit 315 (con114) */
1.42754, 0.500000, 2,
       &Sources[9956] ,
       &Weights[9956] ,
      },
    { /* unit 316 (con115) */
0.22807, 0.500000, 2,
       &Sources[9958] ,
       &Weights[9958] ,
      },
    { /* unit 317 (con116) */
0.00028, 0.500000, 2,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 318 (con117) */
1.42855, 0.500000, 2,
       &Sources[9962] ,
       &Weights[9962] ,
      },
    { /* unit 319 (con118) */
0.00077, 0.500000, 2,
       &Sources[9964] ,
       &Weights[9964] ,
      },
    { /* unit 320 (con119) */
0.02697, 0.500000, 2,
       &Sources[9966] ,
       &Weights[9966] ,
      },
    { /* unit 321 (con120) */
1.42812, 0.500000, 2,
       &Sources[9968] ,
       &Weights[9968] ,
      },
    { /* unit 322 (con121) */
0.13731, 0.500000, 2,
       &Sources[9970] ,
       &Weights[9970] ,
      },
    { /* unit 323 (con122) */
0.02667, 0.500000, 2,
       &Sources[9972] ,
       &Weights[9972] ,
      },
    { /* unit 324 (con123) */
1.42848, 0.500000, 2,
       &Sources[9974] ,
       &Weights[9974] ,
      },
    { /* unit 325 (con124) */
1.42849, 0.500000, 2,
       &Sources[9976] ,
       &Weights[9976] ,
      },
    { /* unit 326 (con125) */
1.20413, 0.500000, 2,
       &Sources[9978] ,
       &Weights[9978] ,
      },
    { /* unit 327 (con126) */
0.00050, 0.500000, 2,
       &Sources[9980] ,
       &Weights[9980] ,
      },
    { /* unit 328 (con127) */
1.01398, 0.500000, 2,
       &Sources[9982] ,
       &Weights[9982] ,
      },
    { /* unit 329 (con128) */
1.42847, 0.500000, 2,
       &Sources[9984] ,
       &Weights[9984] ,
      },
    { /* unit 330 (con129) */
0.00000, 0.500000, 2,
       &Sources[9986] ,
       &Weights[9986] ,
      },
    { /* unit 331 (con130) */
0.00000, 0.500000, 2,
       &Sources[9988] ,
       &Weights[9988] ,
      },
    { /* unit 332 (con21) */
1.37803, 0.500000, 2,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 333 (con22) */
0.06566, 0.500000, 2,
       &Sources[9992] ,
       &Weights[9992] ,
      },
    { /* unit 334 (con23) */
0.00001, 0.500000, 2,
       &Sources[9994] ,
       &Weights[9994] ,
      },
    { /* unit 335 (con24) */
0.16064, 0.500000, 2,
       &Sources[9996] ,
       &Weights[9996] ,
      },
    { /* unit 336 (con25) */
0.00374, 0.500000, 2,
       &Sources[9998] ,
       &Weights[9998] ,
      },
    { /* unit 337 (con26) */
0.00006, 0.500000, 2,
       &Sources[10000] ,
       &Weights[10000] ,
      },
    { /* unit 338 (con27) */
0.00000, 0.500000, 2,
       &Sources[10002] ,
       &Weights[10002] ,
      },
    { /* unit 339 (con28) */
0.34995, 0.500000, 2,
       &Sources[10004] ,
       &Weights[10004] ,
      },
    { /* unit 340 (con29) */
0.00002, 0.500000, 2,
       &Sources[10006] ,
       &Weights[10006] ,
      },
    { /* unit 341 (con210) */
1.42857, 0.500000, 2,
       &Sources[10008] ,
       &Weights[10008] ,
      },
    { /* unit 342 (con211) */
0.01019, 0.500000, 2,
       &Sources[10010] ,
       &Weights[10010] ,
      },
    { /* unit 343 (con212) */
0.00123, 0.500000, 2,
       &Sources[10012] ,
       &Weights[10012] ,
      },
    { /* unit 344 (con213) */
0.00354, 0.500000, 2,
       &Sources[10014] ,
       &Weights[10014] ,
      },
    { /* unit 345 (con214) */
0.00009, 0.500000, 2,
       &Sources[10016] ,
       &Weights[10016] ,
      },
    { /* unit 346 (con215) */
0.13885, 0.500000, 2,
       &Sources[10018] ,
       &Weights[10018] ,
      },
    { /* unit 347 (con216) */
1.31600, 0.500000, 2,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 348 (con217) */
0.17603, 0.500000, 2,
       &Sources[10022] ,
       &Weights[10022] ,
      },
    { /* unit 349 (con218) */
0.00002, 0.500000, 2,
       &Sources[10024] ,
       &Weights[10024] ,
      },
    { /* unit 350 (con219) */
0.00000, 0.500000, 2,
       &Sources[10026] ,
       &Weights[10026] ,
      },
    { /* unit 351 (con220) */
0.40537, 0.500000, 2,
       &Sources[10028] ,
       &Weights[10028] ,
      },
    { /* unit 352 (con221) */
0.39104, 0.500000, 2,
       &Sources[10030] ,
       &Weights[10030] ,
      },
    { /* unit 353 (con222) */
0.00011, 0.500000, 2,
       &Sources[10032] ,
       &Weights[10032] ,
      },
    { /* unit 354 (con223) */
1.19165, 0.500000, 2,
       &Sources[10034] ,
       &Weights[10034] ,
      },
    { /* unit 355 (con224) */
1.29721, 0.500000, 2,
       &Sources[10036] ,
       &Weights[10036] ,
      },
    { /* unit 356 (con225) */
0.22561, 0.500000, 2,
       &Sources[10038] ,
       &Weights[10038] ,
      },
    { /* unit 357 (con226) */
0.00000, 0.500000, 2,
       &Sources[10040] ,
       &Weights[10040] ,
      },
    { /* unit 358 (con227) */
1.41657, 0.500000, 2,
       &Sources[10042] ,
       &Weights[10042] ,
      },
    { /* unit 359 (con228) */
0.04918, 0.500000, 2,
       &Sources[10044] ,
       &Weights[10044] ,
      },
    { /* unit 360 (con229) */
1.40813, 0.500000, 2,
       &Sources[10046] ,
       &Weights[10046] ,
      },
    { /* unit 361 (con230) */
0.00174, 0.500000, 2,
       &Sources[10048] ,
       &Weights[10048] ,
      }

  };



int net(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[232] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130, Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170, Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230, Units + 231, Units + 232}; /* members */

  static pUnit Hidden1[30] = {Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262}; /* members */

  static pUnit Hidden2[30] = {Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292}; /* members */

  static pUnit Output1[9] = {Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299, Units + 300, Units + 301}; /* members */

  static pUnit Special1[1] = {Units + 302}; /* members */

  static pUnit Special2[1] = {Units + 303}; /* members */

  static pUnit Special3[1] = {Units + 304}; /* members */

  static pUnit Special4[1] = {Units + 305}; /* members */

  static pUnit Special5[1] = {Units + 306}; /* members */

  static pUnit Special6[1] = {Units + 307}; /* members */

  static pUnit Special7[1] = {Units + 308}; /* members */

  static pUnit Special8[1] = {Units + 309}; /* members */

  static pUnit Special9[1] = {Units + 310}; /* members */

  static pUnit Special10[1] = {Units + 311}; /* members */

  static pUnit Special11[1] = {Units + 312}; /* members */

  static pUnit Special12[1] = {Units + 313}; /* members */

  static pUnit Special13[1] = {Units + 314}; /* members */

  static pUnit Special14[1] = {Units + 315}; /* members */

  static pUnit Special15[1] = {Units + 316}; /* members */

  static pUnit Special16[1] = {Units + 317}; /* members */

  static pUnit Special17[1] = {Units + 318}; /* members */

  static pUnit Special18[1] = {Units + 319}; /* members */

  static pUnit Special19[1] = {Units + 320}; /* members */

  static pUnit Special20[1] = {Units + 321}; /* members */

  static pUnit Special21[1] = {Units + 322}; /* members */

  static pUnit Special22[1] = {Units + 323}; /* members */

  static pUnit Special23[1] = {Units + 324}; /* members */

  static pUnit Special24[1] = {Units + 325}; /* members */

  static pUnit Special25[1] = {Units + 326}; /* members */

  static pUnit Special26[1] = {Units + 327}; /* members */

  static pUnit Special27[1] = {Units + 328}; /* members */

  static pUnit Special28[1] = {Units + 329}; /* members */

  static pUnit Special29[1] = {Units + 330}; /* members */

  static pUnit Special30[1] = {Units + 331}; /* members */

  static pUnit Special31[1] = {Units + 332}; /* members */

  static pUnit Special32[1] = {Units + 333}; /* members */

  static pUnit Special33[1] = {Units + 334}; /* members */

  static pUnit Special34[1] = {Units + 335}; /* members */

  static pUnit Special35[1] = {Units + 336}; /* members */

  static pUnit Special36[1] = {Units + 337}; /* members */

  static pUnit Special37[1] = {Units + 338}; /* members */

  static pUnit Special38[1] = {Units + 339}; /* members */

  static pUnit Special39[1] = {Units + 340}; /* members */

  static pUnit Special40[1] = {Units + 341}; /* members */

  static pUnit Special41[1] = {Units + 342}; /* members */

  static pUnit Special42[1] = {Units + 343}; /* members */

  static pUnit Special43[1] = {Units + 344}; /* members */

  static pUnit Special44[1] = {Units + 345}; /* members */

  static pUnit Special45[1] = {Units + 346}; /* members */

  static pUnit Special46[1] = {Units + 347}; /* members */

  static pUnit Special47[1] = {Units + 348}; /* members */

  static pUnit Special48[1] = {Units + 349}; /* members */

  static pUnit Special49[1] = {Units + 350}; /* members */

  static pUnit Special50[1] = {Units + 351}; /* members */

  static pUnit Special51[1] = {Units + 352}; /* members */

  static pUnit Special52[1] = {Units + 353}; /* members */

  static pUnit Special53[1] = {Units + 354}; /* members */

  static pUnit Special54[1] = {Units + 355}; /* members */

  static pUnit Special55[1] = {Units + 356}; /* members */

  static pUnit Special56[1] = {Units + 357}; /* members */

  static pUnit Special57[1] = {Units + 358}; /* members */

  static pUnit Special58[1] = {Units + 359}; /* members */

  static pUnit Special59[1] = {Units + 360}; /* members */

  static pUnit Special60[1] = {Units + 361}; /* members */

  static int Output[9] = {293, 294, 295, 296, 297, 298, 299, 300, 301};

  for(member = 0; member < 232; member++) {
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
