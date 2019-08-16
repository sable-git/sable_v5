/*********************************************************
  test_new3.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:08:21 2004
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
-0.487450, 0.179770, 0.333640, -1.574860, -2.257100, 1.414880, -2.116810, -1.856600, -0.715180, -0.704150,
-1.593610, -2.301350, -2.942470, 0.077010, -2.078350, -1.805860, -0.167060, -0.617140, 2.116210, -2.647820,
-1.018610, 0.981450, 0.580290, -0.556260, 1.056520, -1.674850, 4.329740, 0.898820, -1.926620, 0.214740,
0.406180, 0.444190, 0.917970, 0.352330, 0.708460, 0.215340, 2.852190, -1.744100, -2.457800, -0.927460,
0.129860, 4.669200, -1.058830, -0.357870, 0.861630, -1.134880, -1.340120, 1.420820, 0.406970, 0.599030,
0.520260, -0.136590, 0.146810, 0.492260, 2.455560, 0.052150, -0.316360, -0.368720, -0.398030, -0.868640,
0.663120, -1.361270, -1.444880, -0.390780, -0.641270, -0.743170, -1.085310, 0.569210, -0.682320, 0.820990,
-6.422020, -0.788590, 1.095630, -3.334930, 0.877760, 0.512400, -0.903910, 0.494000, 0.329090, 0.282210,
0.184230, 1.631270, -6.845830, -0.552220, -0.102260, -0.242260, -2.168070, -0.219140, 0.246680, 0.722000,
1.459180, -0.875420, 1.981060, 1.950590, -1.314310, 3.682790, 6.519960, 5.212810, -0.094180, -0.405930,
0.851290, 3.646350, 0.532570, -2.181240, -1.812380, -1.431750, 1.854850, 0.311240, -0.039780, 0.343420,
-0.813350, 1.532200, -5.270420, 0.839760, 0.206210, 0.704330, 2.955550, 3.585800, -0.474110, -10.260420,
-0.512870, -0.132920, -0.873940, 1.305070, -6.962070, -2.247600, 0.084870, 0.666730, 2.590280, 4.123360,
2.278130, 1.548700, 2.077990, -6.760740, 2.760560, 2.226120, 0.899140, 8.732360, 2.731120, 0.646730,
-8.367480, -0.467870, 0.031970, 0.353390, -0.076420, -2.451530, -4.661780, -0.182430, -1.104670, -3.036210,
0.312260, 0.273500, 0.369590, -0.533840, -2.821060, 1.460060, 1.554120, 0.160050, 6.543240, 5.613140,
0.638760, -4.204810, 0.872800, -1.819520, 1.010000, -1.583230, 1.594820, -3.557760, -0.873400, -0.736000,
1.847050, -1.164010, -0.090220, -1.015880, -0.877900, -0.595110, 3.879580, -1.681190, 0.943200, 0.824650,
3.088900, -0.328460, 0.555550, 0.072190, -0.429130, 2.610420, -0.812430, 2.374860, -0.378790, -1.564090,
0.473200, -0.333340, 2.065210, 0.287000, -0.642640, 1.556800, -1.944730, 0.662230, -0.366810, 0.231500,
1.893430, 1.645550, 1.366580, 0.818710, -0.463610, 0.622360, 0.755050, -1.898180, 0.301630, 0.193740,
-1.223850, -0.160660, 1.884200, 1.127500, 1.580930, -0.680670, 0.935070, -1.379970, -0.000580, 2.350970,
-1.141100, 1.508470, 1.365310, -0.017340, -0.557090, -0.924640, -0.258410, -0.403630, -0.002400, -0.512320,
-1.627570, -0.194210, 0.270110, 0.482900, -1.303170, 3.700240, 0.882080, -0.357320, -0.687110, 0.941190,
1.409130, -0.082890, 0.154810, -0.618190, 0.229140, 0.287260, -1.694640, -0.563250, -0.248250, -0.758120,
-0.212480, -0.039550, -4.835280, 0.619360, -0.037070, 0.098460, -0.192300, -0.025470, 0.385260, -0.440720,
1.773860, 0.879920,
-1.255150, 0.421650, 3.207750, -0.656760, -0.445710, 0.538500, -0.021170, -0.416240, -0.151380, 0.724830,
0.689730, -0.064950, -0.717100, -0.432060, 1.339450, -0.281940, -0.325100, 0.341720, 0.418340, 0.376210,
0.591010, 0.062600, -0.159100, 0.779370, -0.322550, -2.742820, 0.363550, 0.092490, 0.429490, 0.267490,
-0.054030, -0.442670, 1.420710, -1.840360, 0.751340, -0.184980, -0.124260, -1.469590, -1.223930, -0.926710,
-1.195700, 1.113560, -0.242970, 1.432840, 1.948710, -0.788010, -1.763950, 0.910180, -0.457480, 0.616780,
1.013940, -0.136510, 0.593010, 0.105850, 0.204510, -0.428920, -0.306100, -0.144510, -0.653840, 0.052110,
1.029310, 0.219890, -0.382150, 1.602260, 0.922360, 0.207010, -0.163630, -0.884730, 0.022900, 0.691780,
-0.512960, -0.291200, -0.087240, -0.566030, -1.281130, -0.259840, 0.205710, 0.048960, -1.868200, -0.658850,
-0.371260, 1.394970, -1.147250, -0.933600, 1.349470, -0.599590, -0.218100, 0.547140, 1.720510, 0.087380,
0.504570, -2.202900, -0.148960, 1.226620, 0.039910, -0.348130, 0.377940, 1.878420, 0.836060, 0.569170,
0.342420, -1.572870, -1.021590, -0.334640, -1.789390, 0.884320, -1.057270, -0.114330, 2.491450, 0.683900,
1.600030, -0.286780, -1.484980, 0.368670, -0.460720, -0.731060, 0.864530, 0.270850, -0.528350, 1.618120,
-1.830000, 1.835430, 0.511040, -0.487210, 0.663430, -0.785910, 0.567670, -0.085790, 0.246270, 3.101030,
2.009890, -0.641160, -0.067350, -1.732520, 0.205750, 0.228850, 0.023220, -0.796520, -0.184570, 0.617200,
1.520620, 0.289270, 1.598410, -3.053430, -0.874210, -0.201350, -1.172430, 1.068820, -0.633550, -0.943470,
1.937190, -0.181480, -0.587470, -0.262450, -4.093050, 0.625080, 0.332220, 0.295420, -0.324610, -0.250090,
-1.128480, 0.230700, 0.347550, 0.701590, -0.148570, -0.880140, -0.194450, -1.913000, -0.571910, -0.223880,
0.068960, 0.296850, -0.074100, -1.421540, -0.606950, -3.026750, 0.886820, 1.101940, 0.165980, 0.626430,
-0.158300, 1.383950, 1.751360, 0.930140, -0.685470, -0.935500, -1.463260, 1.742580, -0.756210, 0.329740,
0.975950, -0.496680, 0.896360, 0.768420, -0.934960, -0.404490, -3.506360, 2.319770, 0.001840, 0.402050,
1.416440, 1.683740, 0.766690, 0.322580, -1.124640, -0.767700, 0.374660, 0.604130, -0.395980, 0.829180,
-1.032790, -0.419830, -2.047760, -1.655040, -0.637020, 0.168370, 0.960340, 0.371030, 2.605820, -0.517140,
1.310830, 0.530140, 2.555200, 0.199790, -1.239060, -0.063790, -0.985100, 0.229180, 0.756900, -1.192700,
0.435710, -0.628010, 2.099660, 0.531960, 1.281070, 4.703810, 1.838500, 0.345500, 1.221800, -1.247290,
4.938300, 2.182400, 0.719610, 0.424730, 0.973810, 0.452950, 0.673230, 1.575550, 2.446740, 1.298810,
1.895270, 1.523600, -9.105040, 0.409760, 1.768100, 0.686200, 2.624180, 0.873890, 0.348490, 1.860620,
2.143160, 0.266730,
-0.450790, 0.008320, -0.765580, 1.128320, -0.047670, -1.464850, -0.619750, 0.170840, 0.643160, -0.897600,
0.822740, -0.274470, 0.504020, -1.831590, -0.609340, 0.699280, 0.508790, -0.268830, -0.732560, -0.729840,
0.183440, -0.312580, -1.371590, -2.359110, 1.313970, -0.255180, 1.565080, -0.442070, -0.918590, -0.169950,
-0.664600, 0.906530, 0.058810, -0.415540, -2.025710, 0.705590, -0.502720, -1.091210, 1.055480, -0.872650,
-0.382220, 0.200980, 1.040680, 1.366790, 0.993820, -0.090870, 0.316840, -0.222760, 0.242720, -2.713450,
-0.813810, 1.333170, -0.480050, 0.471380, -0.688300, -0.289530, 1.935990, 1.749760, 0.054320, -0.213520,
0.082650, -2.876690, 0.412150, 1.262940, -1.154960, -0.334870, 5.833350, 1.680230, 0.388580, -0.984110,
-3.420830, -1.101290, -0.673640, 0.764910, -1.411300, -1.733410, -2.512570, 3.536160, 0.800930, 3.166680,
-0.688130, -3.349380, -2.221350, 1.924080, 0.395010, -3.335180, -2.564520, 8.608630, 1.212030, -2.815250,
-0.999160, -1.475560, -0.618960, 0.723780, -2.259010, -0.700600, 0.146200, -4.701900, 8.284610, 1.429980,
5.219950, -0.358000, -1.114440, 4.774780, 0.341020, 1.874430, -0.533840, 0.499460, 1.193950, -0.604010,
-1.225320, -1.447720, -5.500690, 0.054460, -0.340340, -1.492440, 1.660930, 0.115910, -1.311370, 9.656840,
-0.677400, 4.798120, -0.632060, -2.680820, 1.898040, 0.148250, -0.162250, -2.479080, -0.903870, 2.606790,
-2.840820, -1.049290, -3.162290, -1.379410, -2.541570, -1.347080, -0.155180, -1.530720, -1.733490, -0.735340,
9.883440, 0.895990, 0.611460, 1.872820, -2.711490, 3.213330, 0.117750, 1.343400, 1.172800, 2.146810,
-0.169550, 1.030210, -0.798010, 0.736710, 0.138360, 0.147580, -2.903980, -0.471500, -0.487850, -5.818170,
0.519640, 5.814520, -1.974770, -0.573280, 1.003810, 0.156260, 3.009130, 1.379480, -0.050580, -0.893370,
1.100240, 0.125320, 1.832050, -2.247620, -0.365760, 0.144160, -0.018670, -0.309330, -0.687050, -2.810390,
-3.109260, -0.584680, 0.199620, -0.036290, 0.766600, 2.072260, -3.725270, 0.446660, 0.304490, 2.418790,
-1.564170, -0.273620, 0.072530, -0.312970, 0.040390, 1.272320, 0.378900, -0.195430, 0.032790, -1.145080,
0.430900, -0.126810, 0.557440, 2.055310, 0.339610, -0.382810, -0.992960, 1.655950, -3.912030, 0.716270,
-1.320610, -1.057060, 0.687360, 0.452290, -2.041150, 0.447220, 0.881880, 0.669520, -0.361340, -1.328450,
1.953860, 0.535460, -0.655810, -0.408480, 0.004010, 0.469040, -1.233900, -0.457230, -0.734580, 0.250180,
-0.772120, -0.724750, 1.270160, -0.047580, 0.156340, 3.270090, 0.326810, 0.085230, -0.321200, -0.355460,
0.735960, 0.554960, -1.666940, -0.174140, 0.474020, 0.690750, -0.804690, 0.612360, -0.838660, -1.092030,
0.919390, -1.104830, -0.366240, -1.006810, -0.099570, 0.494010, -1.180700, 1.002420, 0.730000, -0.757430,
-0.394910, -0.371580,
-1.510300, -0.554680, 0.279910, -0.717680, -0.298840, 0.188920, -1.163260, -0.678170, 1.138720, 0.155200,
-0.229240, -2.091620, -0.933990, -0.710800, -1.299480, -0.235630, -1.276310, 0.176240, -0.164570, -0.504410,
0.096360, 1.242910, -0.086290, -0.775030, -0.407160, -1.741070, -0.482900, -0.177930, -0.017350, 0.911310,
0.702600, 0.473590, 0.373660, -0.929400, -0.924870, 0.527040, -0.414530, 0.082150, 0.471850, -1.174810,
0.582000, 0.319370, 0.288930, -0.513810, 0.344750, 0.727910, -1.280070, 0.446270, -0.520480, 0.013720,
-0.929170, -1.009580, 0.089240, -0.030510, -0.436750, -0.380560, -0.207410, -1.809250, -0.286770, 0.465270,
-0.812160, 0.683260, 0.249050, 1.390190, -1.027090, 0.342620, -0.910950, -0.104840, -0.136690, -0.070570,
-0.135270, -1.319280, 0.466800, -1.297340, -1.272020, 0.157110, -0.533610, 1.575820, 1.079280, -0.256700,
-0.806720, -0.401830, 0.745610, -0.482570, 1.614640, -1.464660, -1.320610, 0.131200, 0.832610, -0.493710,
-1.152390, -1.408880, 0.752320, -0.494280, 0.043620, 0.195330, 1.041890, -0.733910, -0.577540, 0.682460,
1.690380, -0.010810, -0.171430, -0.799700, -0.520820, 0.320550, 0.635050, 0.667540, 0.603380, -0.026210,
0.979230, 0.019540, 0.267690, -0.247930, -0.379440, -0.008850, -0.497280, -0.200970, -0.907050, -1.048720,
0.126610, 0.650330, -0.814120, -3.705510, -0.034600, -0.630440, -1.442050, 0.545500, -0.141580, 0.263870,
-0.099430, 0.669500, -0.380770, -0.246380, -0.316470, 1.291500, -0.814250, 0.788090, 0.156370, -0.074470,
-0.681840, 0.269620, 0.246170, -0.061740, -0.310340, 0.413310, 0.195360, -0.632450, 1.010490, 1.334710,
-0.157560, 0.817270, -1.130200, -1.206980, -0.554860, 0.275700, -0.132510, -0.095020, -0.958630, -0.046710,
-0.616910, -0.785550, 0.405050, -0.785940, 0.574200, -1.016400, -0.695270, -1.321010, 0.570050, -0.647330,
-0.111770, 1.110530, 0.581760, -0.594690, 0.858200, -0.185260, -0.347090, -0.453360, 0.408190, -1.219190,
1.443450, -0.037420, -1.869770, -0.195180, 1.658530, 1.025330, -0.897170, -0.748750, 0.032740, 0.869530,
-0.601070, -0.837230, 0.445470, 0.439790, -0.486960, -0.972170, -1.067020, -0.344410, -0.773540, -0.387030,
-0.254880, 0.355060, 0.484860, -0.473800, 2.258420, -0.830550, -1.180310, 0.973870, -0.441980, -0.663540,
0.527840, -0.863450, -0.482110, -0.908460, -1.475680, -0.664460, -1.342680, -0.770360, -0.525430, 0.210090,
-0.145660, 1.368280, 0.850590, 0.677550, 0.415760, -0.826880, -0.642390, 0.111530, 1.031410, -0.320500,
-2.024580, -0.674300, -0.136150, -1.505080, -1.958130, 0.039890, -1.104510, -0.678270, -1.848650, -0.305670,
-1.393890, -1.020270, -0.089620, -0.286280, -2.204820, -1.083770, -1.864460, -2.084300, -0.453870, -0.824340,
-1.582340, -0.496680, -11.287630, -2.065700, -1.503570, -0.268820, -1.342610, -1.754080, -0.577260, -2.298400,
-0.139960, -1.537080,
2.363830, -0.219430, -1.523850, 0.391600, -0.191970, -1.448640, -0.281610, 0.192710, -1.778750, 0.962160,
-0.824760, -0.371950, 1.182020, 0.179450, -1.262670, 0.113720, -0.905560, 0.775580, -0.017350, -0.833660,
-0.116160, 0.498730, -1.224460, 1.710640, -0.838370, -2.821940, -0.671730, 0.692450, -1.313640, -0.450220,
0.540300, 0.150510, 1.759550, -0.015280, -0.016060, -0.245990, -0.915220, 0.119260, -0.664820, 0.246780,
-3.617890, -0.828310, 0.289500, -0.760930, -2.708820, -0.641270, -1.786260, 1.549140, -0.781480, -0.094280,
-1.178610, 2.666740, -0.708050, 1.255920, 2.007880, 0.820970, 0.720400, -0.721210, 2.063020, 0.154580,
0.534140, -3.793690, -0.196270, 1.027860, -0.957910, -1.235370, -0.309640, 0.410960, -1.310600, -0.389430,
-2.663570, 0.550780, 2.312850, 0.703600, 4.382970, 2.049640, 2.993130, 0.267370, 0.325010, 2.026410,
0.698110, 1.515280, -1.900940, 0.131020, 3.849040, 0.794230, -1.381870, -0.722750, 0.979270, -1.080130,
0.710440, -0.371830, 0.311120, 0.396800, -2.865450, 1.834040, 4.674960, -0.815590, -0.049210, 0.302210,
0.909580, -0.256930, -0.212910, -4.526970, 0.882740, 1.441730, -0.072740, -1.788630, -0.376730, 1.085670,
-1.072490, 2.496270, -4.744450, 2.664990, 2.415720, -0.133600, 4.778730, 5.832990, -0.347680, -3.517530,
0.182680, 0.532070, 0.149390, 0.998780, -4.349290, -0.985940, -0.944620, 0.181510, -2.985320, 0.719900,
-0.428690, -1.218340, 0.889370, -7.377640, 1.597490, 2.512110, -1.562410, 3.771990, 0.269800, -0.435080,
-0.019660, 0.819800, -0.404930, -0.899070, -1.241430, 1.495920, 0.652410, 1.162180, 0.219910, -2.011390,
4.273040, -0.608730, 0.774690, 0.805200, -2.237860, 0.362350, 1.461480, -0.050270, 0.821820, 2.383170,
-0.336690, -2.617020, 0.402790, 0.169690, -1.103060, -0.025290, 2.547790, -1.244630, -2.068740, -0.269260,
-2.452560, 1.817780, 0.817550, 2.135190, 0.074260, -3.041610, 0.569970, 2.035490, 0.139260, 3.968540,
3.236630, 0.543300, -0.118430, -0.084830, -0.545710, -0.984040, -1.389070, -0.958960, 1.405130, -1.785340,
2.675780, -0.696500, -0.087740, 1.156890, 1.589700, 0.667570, -6.161400, 0.076970, 1.694820, -0.534720,
5.518150, 5.114630, -0.654050, 0.264890, 0.866760, -0.876720, 0.982890, 0.997500, -3.206760, 1.578590,
0.915970, -2.095460, -1.488300, -0.011840, 1.462560, 0.913040, 2.137010, -1.360320, 2.298170, -0.062630,
0.298020, 3.812060, 4.839720, 1.496210, -3.228920, -0.312520, -1.919250, 1.048510, 1.530610, -0.838280,
1.687240, 0.693640, -0.895930, 1.122480, -0.832320, 9.989190, 0.396740, 1.072240, -0.878100, -0.622780,
2.259660, -0.007260, -0.556460, -0.450040, 0.291000, 1.014800, -0.597480, -0.574040, -0.465640, 0.081410,
1.075020, 0.857090, -14.358140, 1.189170, 0.177310, 0.509330, -0.556330, -0.141150, 0.097800, -0.184290,
5.259530, -0.470270,
1.188900, -0.701860, 0.001600, -1.223010, -1.117730, -0.405230, 1.041610, 0.992430, 0.187230, 0.885160,
2.469050, 1.081220, -1.795080, 1.285380, 0.624410, 0.155930, 0.114240, -0.722990, 0.752840, -0.469720,
0.298520, 0.064920, -1.292490, -0.202560, 0.967870, 0.133280, -0.317050, 1.219420, -0.427940, -0.253470,
1.245200, 0.353310, -0.010110, -1.800430, -0.430860, 0.301150, 0.353060, 0.747470, 0.523100, 0.196120,
2.321800, -1.769350, -1.038500, 1.047820, 2.663980, 1.063900, -0.527300, -0.383150, 0.909380, 1.107880,
0.573570, -0.807040, -0.618970, -0.257690, -0.475760, -0.304990, 0.654560, 2.058730, -0.420530, -0.890570,
-0.357390, 1.652900, 0.751600, -0.400440, -0.318340, 5.903640, -0.650440, 0.268480, -0.656960, -0.207200,
1.383560, -1.161640, -0.835680, -0.369480, -0.812230, 1.204390, -0.376120, -1.699030, -2.712590, -2.265590,
-0.556040, 1.613590, -1.273170, -0.460380, -1.063420, -0.461720, 1.467490, -5.644770, -0.990420, 0.829010,
1.295150, 2.950890, 1.147010, 2.217180, -0.699110, 2.397480, 0.440810, 0.129300, -8.471700, 0.153080,
-5.256380, 0.126160, 4.068950, 0.036620, 0.589920, -0.880620, 0.531980, 0.646620, -2.197420, 1.024640,
-0.594560, 1.202580, 2.590830, 1.250450, -0.981930, -1.189990, -0.269240, 0.456350, 1.729730, -7.926210,
1.502680, -2.433810, 1.628650, 2.134220, -1.849680, 0.685240, -0.880990, 1.309490, 0.809540, 0.125890,
1.319110, 0.188180, 1.513590, 0.497470, -0.098810, 0.180330, 0.729860, -0.982170, 0.494920, -1.394920,
-3.344690, 1.151620, 0.184640, -0.935900, 1.567710, -0.046800, -0.117410, -0.276740, 1.545560, 0.949600,
-1.536550, -1.849950, 0.993620, -3.093840, 3.327300, -0.510950, -0.688360, 0.532110, 1.322520, -0.244160,
-0.689180, -2.331740, -0.386800, -2.549680, -0.428050, 0.539840, -0.997670, -0.775740, 0.666050, 0.608960,
-0.562190, -0.031600, 0.370760, -0.527160, -2.596840, -0.696250, -1.285840, 0.221510, 2.559360, 0.978450,
-0.579510, -0.216260, -1.156490, -1.870250, 0.003050, 0.333210, -0.896340, -0.597430, 0.228070, 0.212280,
-1.354120, -0.293240, 0.388680, 0.234500, -0.943590, 0.125910, -1.152860, 0.725060, -1.429930, -0.370840,
1.085360, -1.305670, -1.730070, -0.579660, 1.031400, 2.344470, 2.385590, -0.311980, -1.300260, 0.431790,
1.483130, 0.485290, 3.688380, 0.752620, -0.448010, -0.090770, 1.352840, 0.051660, -0.573810, 0.475690,
0.460180, 0.677350, -0.288550, -1.337500, -0.431700, 1.170540, 0.145110, 0.731510, -1.137360, 1.430260,
-0.568440, -1.008080, -1.526100, -0.593880, -2.040120, 0.605620, -1.636030, 1.273500, -0.779990, -0.414160,
-0.610850, -1.262320, -0.920180, -0.563010, -0.578950, -1.768990, -1.073890, -0.846080, -0.184560, -2.154880,
-0.410060, -0.168430, -0.259850, 0.014190, -1.220630, -1.595590, -0.926590, -1.731440, -0.728560, -1.585130,
2.871540, -0.148980,
0.433780, 0.029250, -1.009280, 0.250800, -2.999250, -0.482520, 0.450120, -0.552750, 0.465750, 0.918380,
1.231300, 0.579140, 1.387670, -1.812910, -0.356410, -0.835400, -0.917850, -0.116800, 1.806850, -1.784940,
1.032460, 0.958070, 1.337950, -0.798720, -1.804500, -0.378690, -0.284000, 0.478250, 0.472040, 3.001250,
-0.264770, 1.308610, 1.356850, 3.007000, -0.721940, -0.320730, -0.369470, 0.657830, -0.351680, 0.368540,
-0.992720, 0.248930, 1.222910, -1.274980, -0.105070, 0.964950, 0.723360, 0.345290, 0.439900, -1.176840,
1.443820, 3.566260, 0.313110, 1.764560, 1.362380, -0.074350, 1.188370, 0.140920, -1.156940, -2.157090,
0.166720, -3.302190, -0.317380, 0.178740, 0.166770, 1.619150, 0.744250, 0.049750, -0.648740, 0.726310,
-0.915440, 1.955150, -0.830160, -0.060700, 0.517230, 1.691530, 0.322960, 0.565530, -1.195660, 0.754480,
-0.571910, 0.318620, -0.236270, -2.927220, -0.206780, -0.638610, -1.407180, 1.479490, -1.196140, 0.769760,
-2.224180, -1.427070, -0.077810, -0.322800, -1.802180, 0.366100, 0.842970, -2.276510, 1.673170, -2.658080,
1.023740, -0.507370, -1.577930, -0.464300, -1.974670, -0.194680, 0.437230, -0.391980, 1.420380, 0.115530,
-1.228390, -2.347530, -3.719280, 0.048110, -0.835740, -0.711940, -0.434880, -0.777880, -2.102260, 3.821560,
0.254970, 3.391100, 0.146930, -0.908990, 0.367660, -0.376440, 0.857520, -0.578290, -1.177900, 2.194740,
0.911570, -0.763640, 2.663570, -1.069600, -0.127970, 0.104710, 0.545880, -0.623240, 0.067480, 1.798580,
0.831390, -0.180960, 0.629710, 0.508010, 0.955340, -1.119360, 0.511620, -1.443830, -0.862440, -1.390850,
-0.253140, -1.382230, -0.856730, 0.313440, -0.433180, -0.236580, 0.967150, 0.610640, 0.510740, 0.986430,
-0.207440, -0.797100, 0.834060, 1.004480, 0.022030, -0.633750, -0.987650, 0.974950, 0.230080, -0.118160,
0.893050, -1.727410, 1.245150, 1.058410, 2.871280, -0.306430, 0.307530, 1.103830, 2.372320, 0.195840,
0.915700, 1.488140, 0.110800, 1.033070, -2.749320, -0.358150, 1.797020, -0.684450, 1.856690, -0.700340,
-0.200860, -2.856510, -0.830030, 0.984650, 1.120410, 2.186700, -0.933560, 0.460910, 1.459430, 0.608850,
-0.213970, 1.609540, -0.805650, -1.506430, -0.926640, -0.527900, 1.487730, -0.021150, -1.319720, 0.949450,
1.285440, -0.668140, 0.546790, -2.040530, -0.561350, 0.250490, 2.118440, -2.762280, 1.136990, 1.626890,
-0.445200, 0.710410, 3.056350, 0.774420, -0.497650, 0.542430, 1.198830, 0.575740, 0.860130, -1.766090,
1.894250, 0.115160, 1.436010, 1.069930, 0.863310, 5.664030, 0.697070, 0.039970, 1.601360, 0.942310,
1.794200, 0.303520, -0.282640, 0.018110, 0.487870, 0.956770, 0.487010, 0.282630, 1.090800, 1.495830,
0.153230, 0.462570, -0.852090, -0.505890, 0.522810, 0.952980, -0.389140, 0.838720, 1.401930, 1.093870,
1.264340, 0.586800,
1.863110, -0.271600, -1.003140, 0.759730, 0.598450, -0.796400, -0.084010, 2.145970, -0.304620, -0.029090,
0.512470, -0.672920, -0.783170, -1.787900, 1.271390, 2.408540, 0.091930, -1.213420, -1.011820, -1.846620,
0.707610, -0.585460, 0.553440, 0.106940, 1.921440, 0.426420, -0.106600, 0.062610, 0.800590, -0.950220,
-1.017150, 2.988530, -0.143490, -0.066320, -0.230940, -0.938890, 0.561960, -0.320680, -1.921460, 0.820100,
1.248310, 0.114300, 2.491480, -0.311820, 0.181860, 1.151100, -0.255170, 1.304760, -1.823000, 2.401410,
0.052020, -0.181710, 1.827610, -1.407210, -4.013360, -0.496790, -0.070600, 0.350580, 0.038670, -0.005350,
2.248930, -0.289300, -1.700690, 0.722510, -0.840420, -0.324140, 0.113640, -0.045710, -0.302250, -0.999930,
-0.993690, -0.249000, -0.066570, 0.620900, -0.279890, -0.269870, 1.394710, -0.176200, -1.789120, -0.758020,
-1.036280, 0.432130, -1.074690, -0.455120, -0.449800, 0.462870, 1.387400, -0.705040, -0.852150, -0.046970,
1.917410, 0.311850, 0.758570, -1.814600, -0.891910, -0.007920, 3.934840, 1.606840, 1.169070, 0.855940,
1.112050, 0.164560, 0.273400, -0.047080, 0.269420, 0.355100, 0.081130, -1.320060, -4.841760, -0.499830,
0.364410, 5.381630, 1.466110, 2.222300, 0.967300, -1.301570, 0.946490, 4.444690, 1.672820, -0.391070,
-0.974470, -1.770610, 1.717550, 1.689300, -6.475030, 0.247630, -1.639530, 1.440000, -1.025460, -1.826760,
-0.655210, 1.814580, 3.564820, 1.453770, 0.730570, -3.519830, 0.889280, 1.626640, 4.928960, 0.068220,
-10.731420, -0.870830, -0.649200, 0.882820, 2.974850, -8.235750, -1.608490, -0.419390, -1.055510, -1.154200,
-0.125030, -1.200780, -0.133360, 2.743160, 1.362640, 1.789720, 4.141050, 0.158040, 2.676120, 3.717860,
0.407750, -6.732050, 0.477630, -0.820310, 1.849350, -0.098010, -4.160800, -0.731730, -0.642020, 1.590150,
0.446170, -0.055650, -0.494130, 0.621790, -0.721310, -2.096380, 1.429070, 1.259850, -0.552970, 3.628450,
0.807450, 0.467490, -6.470390, -1.318730, -4.185790, 1.081190, 0.548560, -1.971240, -1.728000, 0.336780,
0.502480, -1.877600, 2.347710, 0.710190, 0.081230, -0.687330, -1.050030, 1.038320, 1.299540, 0.561340,
1.361420, 2.487040, -1.780320, -5.557860, 0.184710, 0.125610, 1.398830, -0.889750, -0.722460, -0.910670,
-0.015670, -1.816760, -0.517580, -0.327910, 0.256180, -0.664700, 0.767950, -1.891670, 0.291650, 0.531950,
0.256980, 1.705790, 3.219760, -0.677340, 0.140720, 0.883150, -0.768020, -0.336490, 0.624280, -1.105860,
-0.223240, -1.400200, 0.952050, -0.415080, -1.580570, 1.545220, -0.479860, -0.140320, 0.260150, -0.201180,
0.523860, -1.322920, -0.906140, 0.169640, -0.772420, -0.512780, -1.908170, -0.423420, -1.434410, -0.704480,
-0.078500, -0.832120, -3.857780, 1.197900, -0.189190, -0.625410, 0.214060, -0.526260, -0.453740, 0.201970,
4.882170, 0.459880,
-0.203970, 1.699930, 0.154240, -0.003490, -1.947110, 0.237040, 1.225160, -0.555610, 1.360970, -1.268000,
-0.536200, 0.465020, -0.831410, 2.218630, 1.280690, -1.152720, 0.408600, 0.870110, 1.216360, -0.764540,
0.243340, -0.445730, 0.570420, 0.329110, 0.671180, -0.653080, 0.559680, -0.035830, 0.557860, 0.021380,
-0.277260, -0.439670, -0.002690, 0.799290, 0.678120, -0.952460, -0.151960, -0.025200, 1.438140, -0.020330,
-1.517850, -0.220860, -0.381440, -0.310760, -0.026840, -0.403490, -0.506080, -0.533660, -4.658980, -0.857170,
-1.609590, 1.122530, -1.218190, 1.093340, 0.372070, -0.286750, -3.013030, -0.640890, -0.097440, -1.122910,
0.136260, -2.101550, -1.693360, -0.420860, -0.638710, 0.623410, 0.911700, -0.741040, -0.751550, -2.078900,
0.063000, -0.998620, 0.858550, -1.006840, 1.276550, 2.612850, 2.441720, 0.420960, -0.000240, -1.110350,
0.669310, 0.534880, -0.031070, -0.368630, 1.436840, 0.917650, -0.132600, -0.846070, 0.690620, -0.340460,
2.686650, -0.552990, 0.618140, -1.579770, -0.072500, 0.763510, 4.182030, -0.159020, 0.433580, -0.303250,
1.267620, 2.264090, 0.121530, 0.983700, 0.388140, -0.536480, -0.303810, -0.433240, -0.890940, -1.157090,
-0.559110, 1.856830, -0.740690, -0.947720, 1.494200, -0.925010, -0.106720, 4.370340, 0.672920, -2.041380,
-0.832190, 1.832580, 2.165950, 0.637840, -2.364090, -0.600970, -1.038520, 1.123760, 4.500910, -0.862210,
-0.420080, 0.545620, -0.168950, 0.174920, -1.488030, 0.284930, 1.077060, 6.003690, 3.109490, 0.922750,
-1.583130, -2.197630, -3.689970, -2.882260, 0.752350, -0.636000, 0.469870, 0.012990, -0.382570, -1.744330,
-0.496050, 1.054570, -0.841030, -0.313360, -3.956070, 0.361130, 1.310500, 1.465570, 2.227840, 2.654520,
-0.110060, -1.066070, -0.261420, -0.782470, 0.569340, -1.081060, 0.513740, -1.029500, 1.288280, 0.258740,
0.480650, 3.668490, 3.872190, 0.627490, 1.422130, -4.196680, 0.145160, 0.800470, -0.601500, 0.753110,
2.402170, 1.015280, 0.596760, 0.224430, 0.928280, 2.582560, 1.883250, -0.176920, 1.297090, -0.436710,
0.944110, 1.009440, -1.714420, 2.223180, -0.284590, -0.790890, -1.001760, -0.626950, 1.955000, 0.104280,
1.794520, 2.924810, 1.007370, -2.979410, 0.305660, 0.201350, 0.263740, 0.185620, 0.350560, 0.631150,
-0.983050, 1.002150, -0.090620, -0.444660, -2.498970, 2.029610, -0.657990, 0.283610, -1.852200, 0.420690,
1.263080, 3.800930, 3.295080, -2.068940, -1.474850, 0.546170, -1.676780, -0.161880, -0.203510, -1.410990,
-1.370210, 1.269900, -2.517410, -1.347460, -2.004990, 4.100930, -2.562590, -0.359250, -0.173110, -0.017010,
1.014180, -3.761830, -1.281040, 0.091770, 0.302710, -1.777520, -2.827910, -3.358470, -2.560230, -1.795720,
-0.927370, -1.577030, -4.380610, -1.426460, -0.662550, -2.926800, -0.515970, -3.184270, -2.458920, -2.686500,
0.884620, -1.147270,
-0.465010, 0.041410, -0.288110, -0.305960, -0.061050, 0.242400, 0.941540, 0.340440, 0.294790, -0.009200,
1.339390, 0.424800, 5.456740, -0.721100, -0.094840, -0.041340, 0.996700, -0.042110, -0.991880, -0.897810,
-0.491060, -0.474450, -0.691390, -0.273950, -0.213200, 0.185420, -0.971940, 1.129400, 1.060050, -0.405190,
-2.246450, 0.284880, -0.273890, 2.101260, -0.915530, -1.771350, -1.420600, 0.495830, -0.335480, 2.580430,
-4.209270, -0.200630, -0.759560, -1.691880, -2.623910, -1.587680, -1.575580, -2.261770, -0.614190, -1.945670,
-2.622140, 1.319180, -0.720100, 0.178230, 4.237080, -1.406620, 1.153850, -1.077110, -1.112430, -1.273290,
0.442170, -6.288050, 2.544960, 4.248800, -1.837710, -0.926780, 1.162980, 0.969160, 0.317060, 0.813530,
-0.505690, -1.008450, 2.403640, -1.605250, 7.290940, 1.447590, 0.416130, 0.223480, 0.509850, 1.215460,
2.871330, 1.211250, -4.157750, 1.803410, 0.070180, 0.298090, -0.563910, 0.624630, 0.363840, 2.146210,
5.890760, -0.382350, 2.465260, 0.305580, -1.896210, 4.324050, 0.690500, -1.955800, 0.030360, -1.457180,
2.975390, 0.149760, 0.700820, 0.187860, 1.245760, -2.410120, 0.201730, -5.720080, 0.142380, 0.157050,
-1.306260, 1.570410, -5.540500, 0.514880, 0.818570, -0.350660, 2.778260, 2.432770, -2.771490, -1.367940,
-0.313040, 1.997480, -1.496910, 0.152510, -0.718120, 1.354220, 0.545650, -2.350880, -3.421950, 0.599730,
1.445170, -3.844250, -0.310420, -2.959390, 2.747920, -0.715380, -2.320230, -0.739010, 3.664910, -2.218190,
0.847430, 0.155210, 3.052890, 1.215090, 0.385240, -0.101430, 1.194690, 0.284760, -0.590430, -0.175200,
2.532010, 7.329030, -5.419040, 0.582710, -5.379680, -1.093980, -0.986390, -2.213450, -0.547580, 5.168090,
2.476460, -1.542940, 1.143290, 3.696140, 2.364930, -2.116290, 0.066710, 3.311790, -2.663620, -3.208670,
-0.560870, 0.481120, -2.023800, 0.481490, -0.461810, -2.346410, -0.751860, 1.129760, -0.449560, 1.192180,
3.462700, -2.123050, -1.037050, 0.853130, -0.650630, 2.070240, 0.464860, 0.432330, 3.324840, -1.011310,
-0.699780, 0.576680, -0.086880, 2.093400, -0.221380, 1.274110, -1.361920, 1.822410, 2.616220, 0.833240,
1.367680, 0.076060, -0.298640, 0.105110, -2.026000, -1.009970, 1.619180, 0.467570, -2.059600, 0.480620,
-0.357190, -0.026220, -1.726620, 0.102440, 4.593730, 0.245320, 1.523340, -5.490580, 2.880470, 1.607140,
-0.083860, 1.853770, 2.418840, -1.939160, -1.607160, 0.767060, -2.129750, 2.645570, -0.712550, -2.242260,
2.197330, -2.470750, 0.612610, -0.476460, -0.069730, 0.465090, -0.721470, -0.828410, -0.624300, 0.926110,
10.476570, 0.160710, -0.131210, -1.108220, 0.011110, -1.082920, -1.688510, -0.666330, -0.412860, -0.360970,
0.097670, -1.281990, 1.030220, 0.228540, 0.441910, -0.893640, -0.179870, 0.098310, 0.192350, 0.121550,
1.043340, -1.155450,
1.064800, 2.835810, -1.486210, 1.494590, -1.818900, 0.222520, 0.101320, -0.323710, -0.291080, 1.320400,
0.132900, 2.150300, 0.735600, -0.862840, 0.692470, 1.131260, 1.913330, -0.202540, 0.308660, 1.380530,
-2.187810, 0.615790, 0.115540, -0.033560, 0.352840, 0.212200, 0.106700, 0.742280, 1.047690, 0.202910,
1.025470, -0.274030, -0.463320, -0.647610, 2.036570, -0.647990, 0.905540, 1.034120, 0.737990, 0.418650,
3.141300, -0.839960, 0.122560, 1.417950, 0.547960, 0.906900, 0.673070, -3.152010, 0.290820, 0.568330,
0.173870, -2.411770, -0.281460, -0.782830, -0.830520, 0.818940, 1.043370, -0.873120, 0.257120, 0.298430,
-1.239940, 1.525840, -0.549950, 0.069450, -0.469720, -1.196490, 1.463860, -1.655790, 0.359070, -0.535920,
-1.666900, -0.777220, 0.310690, -0.364500, -2.776770, -3.052230, -0.555840, 1.144190, -0.342820, -0.753520,
0.163050, 0.191660, 0.659750, 1.445950, 0.307860, -0.397090, -2.009120, 0.097260, 0.097960, -0.516980,
-0.507010, 0.833700, 1.821030, 0.223280, -0.465100, 0.793950, 1.487990, 0.280680, -0.299910, -0.177860,
0.490980, 0.776010, 2.101530, -2.042500, 0.269500, 1.719750, 0.565690, 2.082420, -1.025970, -1.601030,
-1.248030, -0.672240, -0.270580, -0.210790, 1.076650, -2.283530, 1.011230, 1.859320, -1.119300, 0.595600,
-0.367660, -0.095640, 0.392670, 1.683980, -1.621520, 1.083060, -1.411420, -3.213730, -3.685820, -2.172150,
0.224410, 0.756460, 3.516350, 4.568210, 1.679560, 0.840940, -2.671280, 6.957290, 3.875700, 1.223980,
-3.772130, -0.266170, -2.693950, -0.174270, 3.393810, -7.968950, 0.551170, -1.562890, 2.159690, 0.063670,
-3.574290, 0.714440, 1.611810, 2.566380, -0.092450, 1.628360, 0.675390, 1.157470, 3.163470, 7.429860,
-0.370770, -10.513710, -1.460030, -3.598000, 0.671670, 1.118860, -10.235730, -1.224900, -1.662900, 1.835220,
-1.151960, -0.182690, 1.072090, -0.556020, -1.538720, 0.626670, 1.287520, 2.141180, 0.010150, 1.929310,
5.660640, 1.482490, -16.891510, -0.364000, -1.081260, -0.999280, 2.803870, -1.796090, -0.568540, -2.973570,
1.086900, -1.810120, -0.067670, -0.220070, -0.149450, 0.609900, 0.850510, 0.129460, 1.743810, -1.068460,
1.778970, 4.848850, 1.487240, -8.886140, -0.891760, -2.529650, 3.340330, 3.232870, -2.881600, 0.485890,
1.250750, -1.157990, -3.338450, 2.268460, 1.755930, -1.160710, -0.088210, 2.300600, 2.291280, 0.378220,
1.108100, 1.182610, 3.680590, -0.618710, -3.278840, 1.262820, 0.677120, -0.282970, 0.110130, -2.077360,
0.337140, -1.677430, 0.268380, 0.158310, 0.878540, -2.676870, -0.328950, -0.279660, -0.930950, 0.115300,
0.527770, -0.211130, -1.539700, 0.294200, -0.452820, -0.272690, -0.342510, 0.762290, -0.268370, 0.140520,
-1.900320, -0.933080, -2.770270, -0.327810, 0.175640, -1.851210, -0.012340, -0.844740, -0.098320, -0.900780,
0.445030, 0.904040,
1.256720, 0.054160, 1.150460, 1.292850, 0.560480, 1.862410, 5.866260, 0.227120, 1.917170, 1.420950,
1.449650, -2.661240, -1.447280, 0.119940, -0.839050, -0.036260, -1.952450, -0.123410, 0.536560, 1.013820,
0.921810, -2.084540, 0.257820, -0.885010, -3.588570, -3.061730, 0.540790, 0.409680, -0.812840, 0.260360,
-0.279110, -0.377060, -1.311890, 0.385430, 0.377550, 0.299520, -0.631050, -0.841430, -1.042190, 5.992990,
-1.823250, 0.189530, -0.609280, -0.061220, 0.426640, 1.683840, -0.513990, 0.138750, 2.130480, 1.623340,
-0.547550, -0.576810, -0.691500, 0.471510, -2.460960, -0.550290, -1.201550, -0.437570, 0.480540, 1.858750,
-0.914940, -0.154720, 0.240030, -0.164710, 1.177410, -3.334710, -0.253310, -0.890290, 0.294830, -0.136950,
-0.721040, -1.020130, 0.778160, -1.808320, -0.825140, 0.883970, -0.236620, 0.278710, -0.887530, 0.928480,
-2.328230, -1.535740, -0.445290, -2.023690, -0.018280, 0.403200, -2.794390, -2.648170, -0.353670, 0.710520,
0.394230, -0.713880, -0.278080, 0.923400, -0.617910, 0.515480, 2.006020, 0.658340, -2.386930, 0.956440,
-0.143150, -0.215240, -0.670480, -1.512290, 0.060750, 2.548010, 0.342380, 1.512330, 1.394360, 2.726470,
0.794730, 2.593090, -2.436650, 2.345150, 0.171990, 1.606430, -0.070120, 2.157490, 0.617670, -1.891420,
0.481050, -0.955150, 0.560200, -0.363910, -0.700150, -0.441670, -0.187470, 0.386040, -3.367370, 3.422350,
-1.103440, -1.757780, -0.765660, -2.146670, -2.389770, 0.179910, 4.357390, -0.886610, -0.189980, -0.348680,
-2.101740, 1.978010, -0.709390, 0.263180, -2.984950, 4.732620, -1.899970, -0.451870, 0.799340, 2.469270,
-2.386620, -3.467020, 0.978700, -12.032570, 0.196460, -3.713440, 0.895550, 1.376610, 1.103360, -2.397770,
-0.809980, -0.471270, -2.891620, -1.953770, -0.860590, -0.035820, 3.415320, -0.640940, -0.187080, 1.363240,
0.461120, -0.726790, 1.709000, 0.041100, 0.299960, -2.620040, -2.191370, -0.208820, -0.440180, -0.381210,
0.190510, -0.341950, -1.384540, -1.013240, -0.671510, 1.998110, -0.907230, 7.820790, 0.381990, 1.488790,
-0.698310, 3.697940, 0.463180, 1.365360, 0.259900, 1.352690, -0.505960, 1.199840, -1.171360, 0.347610,
-2.626520, -0.550530, 1.745840, 0.058210, 6.321160, -0.029420, -1.294620, -0.877780, -0.111180, 0.553230,
-1.719630, 0.646250, -1.448290, -1.856360, -11.017920, -0.694640, -2.814050, 0.246750, -2.428590, 0.187490,
-1.593160, 0.382820, -5.369930, -1.186740, -1.119220, -0.876100, -0.537930, -5.995190, 1.334500, -1.346220,
-2.733190, 0.686840, 0.671940, -0.645880, -0.088150, -0.058730, 0.317040, 0.643770, 0.414390, -0.521970,
-0.884210, 0.644590, -0.696460, -1.279790, 0.472730, 0.623900, 0.548060, 0.640970, 0.363000, 0.282850,
-1.357580, 0.171340, -1.213040, -0.330500, -1.252030, -0.646060, -0.904900, -1.485360, 0.490150, -0.898500,
0.609760, -0.337100,
-1.221260, -0.918420, 0.030270, -0.041130, -0.392370, -1.540350, 1.770040, 0.210870, 1.751170, 0.012610,
1.469040, 2.169630, 2.630520, -1.482080, -2.986870, -2.410950, -0.103070, 2.170100, 1.554890, -1.630910,
0.377940, -0.167710, 0.068240, -1.900890, -1.948780, 1.255010, 1.396490, 1.470270, -0.498100, 0.033850,
0.453480, 0.805970, 0.243970, 0.861770, 1.030970, -0.737950, 0.118820, 2.116850, -1.092190, -0.366960,
-2.891510, 0.206910, 0.505290, -0.977770, -1.335590, -1.266800, 0.255080, 0.620820, 0.291720, -2.872480,
0.898810, -0.678840, 0.619930, 0.283210, 4.396990, 1.022420, 0.345840, -0.038800, -0.321330, 0.162260,
0.686820, 1.409830, 3.121840, 0.934910, -0.512520, 0.958650, 0.733350, -0.696630, -0.909340, 1.279530,
-0.397480, -0.427180, -1.148420, 0.580990, 0.455520, 5.363900, -1.669690, 1.670790, 1.120450, 1.963070,
-0.280270, 0.673430, 0.212980, -0.168310, -1.911310, -1.369940, -4.509070, -0.126440, 2.275290, -2.569200,
2.355100, -0.346230, 3.355220, 0.694650, -0.499020, -1.421240, 2.654060, 0.971230, 0.207920, -0.546480,
0.752050, 1.524970, -0.316000, 1.031360, -0.236770, -1.172440, 0.033480, -3.145540, -0.009100, 1.203680,
-0.454120, -0.331550, -2.011630, 1.439620, 0.227960, 4.095460, 2.183910, 1.055940, 1.549350, -0.048630,
1.005520, -0.464240, -0.883920, 1.276200, -0.122150, -0.002410, -0.446340, 1.650730, 0.613390, -0.631560,
2.599020, -0.473820, -4.696510, -0.247480, -0.154680, 0.959860, -2.405900, 1.625700, -0.447330, -0.644960,
1.004900, 0.139300, 0.003640, 0.880780, 0.880570, -1.307020, -0.421800, -4.937870, 9.987770, -1.606460,
-1.827240, -2.566170, 0.843540, -2.977100, 2.565300, -2.773760, -0.269970, 1.829580, 0.648100, -1.035460,
1.824050, -0.446040, -2.117420, -2.245470, -4.207490, 2.389910, -1.015570, 0.061850, 1.569880, -1.179800,
-1.284710, -2.993170, -1.356830, 0.083480, -1.348730, -0.521770, 0.769410, -0.311700, 0.165870, 1.498960,
-1.451440, -1.008570, 2.132440, 1.150230, 0.889970, -0.193910, 1.031620, -0.149110, 0.753780, 1.701800,
-1.028380, -2.753230, 0.621920, 0.741360, -0.669940, 1.676510, -1.901590, -0.321770, -0.052150, -1.753560,
-1.115120, -2.877400, -0.113850, -0.846700, 1.409940, 1.505190, 1.343210, -0.396800, 0.771180, 2.575110,
-1.157180, -0.681980, -0.666200, -1.139940, -1.493640, 1.621570, -3.233070, 0.254870, -0.290430, -0.094310,
1.348740, 0.161760, 0.099390, -0.594210, -0.528630, 0.469900, -0.444380, 0.338890, 1.317780, -1.900220,
-0.008390, 1.970830, -1.285250, -1.251000, 0.298980, -2.329940, -0.060490, 1.220730, -1.134030, -1.122550,
0.513600, 0.443270, -0.460250, -0.921990, 0.206680, 0.386180, -1.560270, 0.257280, -2.716120, 1.311630,
0.403400, -1.229750, -1.507400, -0.577270, 0.031480, -0.070440, 0.523740, 0.631350, 0.061730, 0.109750,
-0.103500, -1.354670,
1.454650, -0.854230, -1.314840, 0.350190, 1.609240, 1.642660, 0.069380, 1.063310, -0.726430, 0.274410,
-2.126410, -0.085190, 0.348940, 0.112410, 1.949180, -0.059040, -0.738810, -2.268910, 0.479220, 1.358050,
0.003340, -1.146170, -0.196570, 2.022620, -0.715240, -1.651170, -0.346870, -0.437520, 1.459440, -0.947020,
-2.354190, -1.455950, -1.666390, -1.513960, -1.697900, -0.462090, -1.534140, -0.154510, -2.150990, 0.583100,
-1.609800, 0.045100, -0.539350, -1.119640, -2.331090, 0.738460, -0.974960, 2.187430, 0.395020, -0.993430,
0.942750, 1.220570, -0.853270, 0.690360, 3.797100, 2.026500, -0.203710, 1.332930, -0.974780, -0.382080,
0.504210, 1.193420, 2.789380, -0.237990, 1.153590, -1.695760, -1.623870, -2.466050, 1.380870, 0.030670,
0.422030, 1.557610, 0.737510, 1.006150, -0.029570, 0.666250, 1.160620, -3.621370, -0.512220, 0.134800,
-1.314920, 2.185630, -3.057100, -0.410710, -1.160150, 1.537480, 1.236050, -2.137690, 0.050410, -0.753090,
0.451220, 0.561710, 0.769900, 1.186450, -0.573340, 1.084160, 2.822130, -0.266480, 0.370410, -2.912350,
-1.519500, 0.743380, -1.054690, -6.917960, -1.233000, -2.555440, -1.977750, -0.339500, -0.999280, 0.883610,
0.285650, -0.318140, -1.095760, -1.059820, -0.517010, -1.720820, 0.446650, 8.126370, 0.630960, -8.078360,
-2.380760, -0.458490, 0.384040, 2.136620, -4.495240, -0.969530, -1.388500, 0.319510, -2.994970, 0.422840,
1.315050, -0.102840, 1.754800, -0.184870, 0.753230, -0.359710, -1.619130, 0.759870, 7.699790, 0.136500,
-1.273520, -3.854590, 0.537970, 1.141020, 0.712570, -3.579860, -0.700330, -1.237030, -0.440980, -4.583230,
1.936850, 0.797120, 1.816060, 0.605790, 1.142610, 0.395710, 0.072090, -1.782020, 0.521840, 0.578650,
-0.035420, -8.152890, -1.610570, 2.373050, 0.893380, 0.340010, -2.250460, 0.269400, -0.903830, -0.950560,
-2.126940, 0.883150, -0.038470, 0.959690, 1.585750, 0.771910, 1.999410, 1.595570, -0.447620, 2.072090,
2.133430, 0.364640, -11.553410, 1.695510, 0.033830, -0.460960, 0.666750, 0.449490, -0.252880, -0.725530,
0.488920, -0.136820, 1.305100, 6.417690, 0.001690, -0.945020, -3.051900, 1.716430, 1.405090, -0.146980,
1.164800, 1.999430, -0.717110, -5.708070, -0.488780, -0.124180, 1.948860, 0.193660, -0.598720, -0.058020,
0.269780, -1.468100, 0.918170, 1.652650, 1.465450, 0.864120, 0.798870, -0.723780, 0.496650, 0.795530,
-0.176790, 2.319550, 0.658130, 0.303950, -2.428690, 0.954860, -0.729010, 1.452990, -1.185260, 0.996810,
0.513970, -0.449580, -0.803330, -0.232630, 0.046680, -1.882300, 0.437270, -0.448780, -0.925330, 0.092250,
-0.134690, 0.350360, 0.706630, -0.051900, -0.447130, -0.715790, -1.035480, 0.711130, -0.466370, -0.113100,
0.336800, 0.164090, 0.143300, 0.578460, -1.067530, 0.742150, -0.429330, 0.296740, 0.396120, -1.861930,
0.954320, 0.198420,
-1.627470, 0.255770, -0.189670, -1.869370, -1.399810, 0.001460, 2.055160, 0.978360, -1.487190, -1.520330,
-0.433420, 0.031440, -0.710350, -1.958030, 2.188760, 0.270690, -0.128590, -1.061930, 0.882600, 0.527050,
-1.576520, 0.583800, -0.887620, 0.532820, 0.158100, 1.006700, -0.438870, 1.243180, 0.389690, -0.557110,
-1.150660, -0.484780, -0.359140, 0.891850, 0.761740, 1.454200, 0.716780, 0.303060, 0.855590, -0.972690,
1.148600, -1.573840, 0.253510, 0.588400, -0.535860, 2.290280, 1.590240, 0.713700, -0.137180, -0.960050,
-1.711230, -1.321210, 0.697630, -0.784050, -1.035350, -1.031950, 2.676550, -0.027240, -0.754410, -0.918600,
-0.812980, 3.918930, -0.622030, -2.124380, -1.355630, -1.088360, 0.064830, -1.717450, -0.773070, -2.150940,
0.346540, -1.840580, -1.260440, -0.011840, -0.706180, -1.672930, 1.207210, 1.798440, 0.575230, 0.136570,
0.204800, 0.238760, -0.007710, -0.497930, 1.446010, 0.232090, 1.222170, 2.876710, -0.519900, -0.020280,
-4.044600, -1.578020, 0.828920, -3.546680, 0.796980, -2.666250, -7.722090, -3.112760, 2.107560, 3.382410,
-0.015980, 0.110690, -1.624200, 1.732520, 1.294890, -0.914730, -1.389350, 0.582370, -0.478420, 0.551450,
1.768240, -0.484680, 2.908390, -0.451900, -0.202510, -0.623590, 0.284000, -1.301670, 0.107540, 0.773560,
-0.636380, 1.312840, 0.706300, -0.516160, 2.634260, 1.519150, 0.470540, -0.287610, 1.455310, -0.278700,
-0.913920, -0.384950, 0.329680, 1.285040, -1.531590, -4.162650, 1.728150, -1.151080, -5.815490, -1.050680,
0.340460, 0.552100, 0.606720, 0.067960, -2.133440, 0.667980, 1.645220, 1.155330, -0.529300, 0.856680,
0.872690, -1.867360, -2.259760, -3.282430, -0.955900, -1.115580, 0.151650, -4.408460, -2.154790, -4.087600,
-2.980200, 4.512120, -0.222560, -0.146250, -0.812380, -1.667400, 2.509300, 1.900320, 1.268670, 0.064400,
-0.410010, 0.985960, -3.846880, -0.225860, -1.202840, 2.304220, -3.817020, -0.435600, -0.191270, -1.452660,
-2.864530, -1.208840, 6.263730, -1.331610, 0.567760, -1.604270, 0.986010, 0.710210, -0.483950, 0.756700,
-0.289680, 0.986390, -2.529120, -0.956830, 2.592770, 2.964710, -0.201370, -0.230920, -1.188160, -0.093530,
-2.672800, -2.333660, -2.647680, 1.560290, 2.494930, -0.476340, -1.111560, -3.637130, 1.289310, 0.951600,
1.616170, 0.056050, 1.266650, -0.651220, -2.019140, 0.463620, -0.725940, 1.140450, -2.251800, -1.067850,
2.303920, -4.118630, -5.945910, -1.803350, 1.635600, 0.163200, 0.164310, -2.326530, 0.844830, 0.407810,
0.913240, 0.353670, 0.274140, 0.982480, -0.139860, -4.743270, -1.349730, 0.464120, 0.106150, -0.508160,
-0.108050, -1.126090, 1.087400, -0.045620, -0.650840, -0.101510, 0.958370, 0.519160, 0.437120, 0.624970,
-0.769050, -0.540170, -1.179180, -2.263010, -0.568490, -0.340410, 0.205050, 0.029550, -0.679720, -0.441160,
-3.979300, -0.202110,
0.858180, 0.881280, -0.019750, -0.771190, 0.595130, -1.048860, -1.565960, -0.586360, -0.420530, -0.625440,
0.092740, 0.738340, 1.270190, -0.587350, -0.098730, 0.050200, -0.078960, 0.765860, -0.664990, 0.036050,
-2.905910, -0.461000, -0.694750, 0.586780, -0.265500, -0.473090, -1.141970, -0.451680, -0.320580, 0.150660,
-0.753510, -0.305250, 1.020700, -0.126260, -0.997360, -1.154680, 0.896690, 0.012710, -0.312390, 1.304400,
-1.072840, 0.202880, -0.857190, 1.821960, -0.376460, -2.020480, 1.251020, -1.370030, -0.173010, -1.122690,
-0.561950, 0.187790, -0.636630, 0.632700, 2.055290, 0.454530, 2.076730, 1.006100, 1.377750, -0.280530,
0.103020, 1.959860, 0.416910, 0.840910, 0.285740, 0.215420, -0.365420, 5.120600, -0.149160, -0.874820,
0.059700, 0.313900, 1.408840, 1.730210, -0.536880, 0.855280, 0.643870, -1.480010, 0.083030, 0.126950,
-0.071890, -3.545270, -0.194830, 1.910870, 0.501840, 0.177150, -0.403060, 0.245210, 3.412010, -0.887100,
0.307130, 1.324560, 0.727840, 0.859990, 0.703900, -2.374060, 0.029370, 0.288050, -0.135030, 0.143260,
-1.290670, 0.233360, 0.989970, 3.387340, 0.644430, 0.377030, 0.388500, 1.582720, -0.159620, 0.680940,
1.951650, -0.695700, -0.085060, 0.137390, -0.556260, 2.558700, -1.562310, -1.795710, -0.123890, -0.944990,
-0.247350, -1.780800, -0.820620, -0.782480, 2.615810, -0.507340, 1.834580, -2.477960, 3.211790, 1.282600,
-0.606140, -0.253590, -6.109090, 0.498150, -4.439910, -2.295250, 2.854610, -0.708340, -3.687530, -0.529170,
0.589170, 1.057250, -0.403790, -0.697570, -1.624490, 1.149300, -0.533810, 0.854210, 0.455580, 2.472440,
-0.589960, 0.312290, 0.000710, -3.479430, 2.405020, -0.945500, -1.581980, 1.316780, -4.654140, -12.148160,
-0.551730, 5.538670, -0.028410, -0.600440, -0.383430, -1.725170, 7.650010, -0.381380, 0.811650, -0.131130,
-0.180900, -0.623710, -2.264500, -0.638960, -0.716210, 1.715850, -4.382360, -3.287760, 1.735930, -1.564700,
-6.903920, -0.254630, 2.858080, 0.547660, 0.678620, -0.624980, 0.017170, 1.629820, 0.514060, 0.214800,
0.566490, 0.918920, -0.986240, -0.159540, -0.439060, -1.565620, 8.661770, -2.059690, -2.998140, -0.259150,
-3.312040, -4.893370, 0.673350, 9.471540, -0.298520, 2.206660, 0.782210, -1.390970, 0.460090, -1.311200,
1.889620, -0.751830, 1.215580, -3.269500, -1.633980, 0.835090, -1.657230, 2.573480, -1.822560, -2.576940,
-0.983270, -4.466580, -4.549410, 1.202910, 5.734740, 0.083690, -2.119940, -1.193490, 0.216110, 0.432480,
0.045390, -0.613960, 1.347140, 0.494950, 0.210810, -3.486380, 0.078280, 0.503980, 1.485680, -0.193720,
-1.363090, 0.958380, -0.417740, 0.813490, -0.057300, -0.401940, 1.221150, 0.262210, 0.656650, 0.492090,
-0.223100, 0.254200, 18.875259, 0.820450, -0.035250, 0.823220, -0.044240, 1.157080, 0.766180, 1.174970,
-2.647810, 0.335840,
0.264660, 0.905780, -0.636500, 0.152070, 4.573560, -1.317920, 0.145140, 1.736450, -1.464020, -2.012440,
-0.434950, 0.641270, 1.091980, -1.448080, 1.584040, 0.335100, 0.480700, 0.391830, 0.274640, -0.632100,
-1.194580, -1.460990, 1.306940, -1.212090, 0.518440, 0.596490, 2.279400, -1.102100, 0.100000, 0.276770,
-1.099700, -0.527620, 1.072200, 0.033770, 0.522200, 0.702220, -1.656900, -0.950160, 3.931220, 0.199080,
0.256010, 0.987820, 2.469830, -0.741380, -0.206760, 1.840690, 6.044200, -1.927920, 1.339100, -1.127880,
1.691910, -2.021310, -0.046560, 0.402730, 5.740960, -1.402910, -0.496240, 0.974000, 0.568090, 2.333080,
-0.956420, 0.545260, -3.217170, -2.202750, 1.133370, -0.198730, 0.039550, 1.009860, -1.115060, 0.953930,
-1.377250, 0.357130, -1.305180, -3.281660, -1.979960, 3.304850, -0.304210, -0.114940, 0.307440, -1.070270,
-0.348220, 0.657780, 0.048450, 0.297410, 0.421810, -0.537270, 0.242040, 2.183860, -0.699270, -0.954010,
-0.776510, -0.196380, -0.465040, 0.253380, 0.055300, -0.802240, -2.478280, 1.078840, 3.141470, -0.018820,
0.694030, -3.559410, -1.438330, 0.787000, -0.038380, -1.199990, 1.773330, -0.726930, -2.213910, -2.149800,
-1.056880, -0.461460, 0.956360, 0.760980, -0.417600, 0.280340, 0.377150, -1.188200, 0.939250, 0.562700,
-0.328970, -4.487540, 4.558450, 2.537410, 0.121800, -0.519710, -0.599250, -0.391350, 3.679570, 1.568930,
1.372160, 0.004880, -0.734870, 2.792850, 0.726800, 0.073360, -0.247770, 0.358460, 0.354080, 1.007180,
-2.830540, -0.346820, -0.851410, -0.870870, -0.208600, 0.009330, -0.817050, -0.218830, 0.600540, -2.249760,
-0.737310, -1.724560, 0.698400, -0.215880, -0.819320, -0.620600, 1.229500, -0.779460, -0.456530, 0.743030,
-0.918720, -1.009350, 2.212530, -0.044650, -0.176610, 0.898070, 0.266310, -1.413070, -0.555770, -0.043890,
-1.013420, -1.696560, -1.338570, -0.445880, -10.302190, 3.039380, -0.908520, 1.908390, 0.051670, 1.477380,
-4.462540, -0.007270, 0.432360, 1.102860, -1.463820, -1.852110, 0.951290, -0.210610, -1.545260, 1.964480,
0.447720, -0.176870, 0.920760, -1.635110, 0.566830, -0.306670, -0.838990, -0.816040, 0.341170, 0.392900,
0.201820, -5.974420, -0.476020, -1.254940, 0.505270, 0.341380, 0.246380, 0.378610, -0.227540, 0.588380,
1.564910, -4.771910, 1.204790, -0.863550, -1.071550, -4.174800, 4.752510, 12.285080, -0.699450, -7.330410,
-3.412200, -8.838280, -3.796430, -2.444290, 0.837750, 3.124750, 2.712680, 1.205120, -4.425160, 3.789500,
-0.995390, 1.350230, -0.357530, 0.938950, 1.253970, 1.117560, 0.141460, 1.177130, -0.239970, 0.548440,
-3.504160, 0.209760, 1.509950, -0.061920, 0.348830, 0.858560, -0.060590, 1.441000, 1.515590, 0.493100,
-0.205740, 0.317350, 3.507810, 1.231700, 1.134470, 0.975420, 0.453470, 0.045770, -0.295370, 0.437970,
-0.375770, 0.751930,
-0.993880, -0.834760, 3.493810, -0.129200, -1.559630, -0.625430, -1.447590, 1.710710, -0.252220, 1.132060,
-0.744670, -1.152010, -0.683790, 0.936520, 0.436610, -1.169440, -1.202640, 0.809220, 1.613870, -1.345470,
-0.751700, -0.351060, 0.120540, 0.964200, -0.293220, -1.139540, 0.079580, 1.830460, 1.411430, -0.501670,
0.708020, -1.404450, 1.241840, 0.940290, -0.153080, -0.423730, 1.644560, -2.728560, -0.030140, 0.478050,
-3.093600, 1.646780, 0.215410, 0.863830, 1.706080, -0.170180, -2.569860, 0.735510, -0.868800, -2.065710,
-0.623840, -0.638590, -0.315040, -2.441050, -0.217120, -1.104470, -1.992540, -0.549190, -0.876250, 0.791970,
0.750540, -5.389330, 3.446840, -0.807700, -0.608370, -0.025740, -0.976320, -0.026660, 1.816910, 0.937640,
-0.940920, 0.447450, -0.760690, 1.651770, 0.060710, 4.150240, 1.306890, 0.257190, -0.409520, 0.671890,
-1.581510, -1.197640, -7.852350, -0.708640, 0.052380, 0.185210, -0.619300, -0.232740, 0.708420, 0.008290,
1.313770, 0.017120, 2.258230, 1.086070, -0.768800, 2.948300, 0.933010, 1.557770, -0.181560, 0.326890,
0.301360, 0.415670, -0.787850, -2.316780, 0.045670, -0.363090, -0.406810, -5.485970, 0.908150, 1.478860,
0.258170, 2.370460, -0.026180, 1.451530, -3.626470, -1.900220, -0.158160, 5.221430, 1.709130, 1.170380,
0.623450, 0.044750, 1.689820, -1.266380, 0.047050, 0.781140, 0.450240, -0.427010, -0.471090, 0.649400,
0.058580, 1.689110, 0.216700, -1.371060, 1.026750, 0.137000, 0.036920, 0.679550, 2.683430, -0.335920,
-0.563600, -0.904440, -0.831580, -1.293590, 0.796400, 0.921910, -0.513480, 0.025110, 1.324090, -5.468180,
0.799460, -0.145860, -0.682040, -2.831680, -2.506200, 0.056080, 3.174200, 0.297400, 4.018640, 0.338770,
1.979300, -1.394580, 0.479240, -0.750530, 0.525050, 1.498590, 0.087110, 1.056110, -0.467390, 1.295830,
-0.276930, -0.131820, -0.582810, 0.497470, 0.635360, -1.602740, -0.716900, 0.910160, -2.149290, 3.110530,
6.118840, 0.571920, -0.925640, -0.340990, -0.665160, -4.547970, -0.089620, -1.619940, 1.117370, 0.022520,
1.258620, 0.267340, 1.405410, -1.949320, 0.710860, 0.756150, -1.640790, 0.282400, 1.877720, 0.821880,
2.105270, 1.689330, -0.269040, -3.355420, -0.873430, -0.827200, -0.541630, -1.512580, -0.361610, 0.702470,
-1.503840, -0.688080, -2.351040, -2.018670, 2.153850, 0.948190, -7.447660, -0.391760, 1.196240, 3.175140,
1.496440, 1.453670, 4.750670, -2.259460, -0.913500, -0.259470, -2.452630, 1.716760, -1.422260, -0.253010,
0.867280, 0.016410, -0.520490, 0.090780, -1.840450, 1.371640, 0.575670, 0.911920, 0.687260, 0.487910,
1.142550, -2.241980, 0.294960, -0.631780, -0.420130, 0.535480, -8.697620, -3.862440, -0.957760, 0.386020,
0.919500, -0.650160, -4.883880, -0.809520, 0.294380, -0.381050, 0.186900, -7.846150, 0.202980, -0.512970,
1.198840, -0.508890,
-0.244870, 0.014390, -1.049040, -1.291890, -0.166010, 1.006110, 0.119980, -2.628050, -0.578670, 0.373790,
0.523770, 0.426970, 1.507130, -0.395610, -2.489600, 0.802270, 0.708790, 0.113150, -0.285590, -2.500250,
-0.403710, -1.028310, -1.206280, -0.463910, -0.653950, -0.975170, -1.870860, -0.354540, -1.971580, 1.714240,
1.990260, 1.123440, 0.540090, 0.208860, 2.032210, -1.704060, -1.440210, 0.601370, 2.099300, 0.151630,
-1.562750, 1.940940, -0.573960, -0.607880, 0.395750, -0.735420, -1.516230, 0.522170, 1.748370, -2.376350,
1.222980, 1.000770, -1.306180, 0.903940, 4.031440, 0.527530, -1.302010, -0.559790, 1.323670, -2.271600,
-0.210320, -4.449120, -0.381210, -0.339350, 0.356820, 0.568390, 1.241870, 0.150060, 0.989430, 0.406380,
-2.506050, 0.448390, 1.371890, -0.871820, 3.183100, 2.096850, 1.420770, -1.701170, -1.941390, 0.486620,
-0.100830, -1.119400, -2.614140, -0.552070, 0.425070, -0.797040, 0.150800, -0.531080, -0.124370, 0.482320,
0.561220, -3.899800, -0.739810, 1.479590, -0.709960, 0.981890, 0.297630, -0.650600, 0.573260, 0.226260,
0.143320, -0.606860, -0.413330, 0.325000, -1.569660, 0.879370, -0.822870, -1.999200, 1.875940, -0.920930,
-0.801270, 1.200020, -7.226280, 2.556250, 1.343380, -0.583990, 2.939840, 1.303710, 1.434070, 0.815040,
-0.220540, 1.852040, -1.425070, -1.660080, 0.042140, -2.047830, -1.375400, 0.319900, -0.726440, -0.808870,
-0.608990, 0.788520, 3.162890, -0.551630, 2.904940, 0.605240, -0.607570, 3.969320, 7.275580, 0.116190,
-1.503970, 0.681400, -0.113530, 0.248380, 0.086650, -2.288000, -0.560180, -1.555670, 1.940510, -1.395550,
-0.548200, 1.031780, -0.571170, 1.022830, -2.753260, 3.410510, 2.835560, -0.578090, 4.006620, 5.880950,
-0.105180, -5.997240, 2.533480, -0.518960, 0.446900, 1.290620, -1.335710, -0.286090, -1.653660, 0.490340,
-1.775820, -0.183570, -2.146440, 1.486110, 0.973030, -11.143270, -0.770430, 1.163240, 0.629740, 8.277070,
4.314440, 0.178540, -12.647870, -0.527800, 0.545810, -0.047140, 1.237760, -2.897130, 0.078880, -0.951790,
1.189160, -1.307300, 0.121300, 0.833030, 0.039090, 1.095610, -1.539210, 2.135020, 0.848760, 2.411610,
4.866940, 5.203980, -0.362810, -2.792340, 0.654670, -1.077350, -2.465610, -0.311270, -1.839970, 1.086600,
-1.605770, -0.211400, -2.562860, -1.152740, 0.806190, -0.132380, 1.359330, -5.332190, 0.403600, 2.323080,
0.416020, 1.310460, 4.697350, 0.907730, -2.974510, -0.237380, -2.442780, -0.931030, -0.502410, -2.048550,
0.393610, 0.571810, 0.438180, 0.230630, -0.200540, -0.561520, -0.221290, -0.455460, 0.851650, -0.233660,
-0.308370, 0.755470, -0.821320, -0.086610, 0.303900, -0.770340, 0.513400, 0.033910, 0.880530, 0.775720,
-0.072150, -0.572210, -7.223860, -0.524830, -0.481830, 0.578510, 1.043030, -1.007650, 0.182180, 0.560470,
2.101410, 0.014860,
0.260240, -1.265920, -1.234490, 1.946550, -0.605760, -1.026260, -0.837540, 1.590240, 0.191450, -0.084160,
-0.344000, -0.840060, 3.876770, 0.862720, -0.041570, -0.472370, 2.484150, -3.049000, -2.350820, -1.421440,
-0.565690, -0.322030, 1.277190, 0.413430, -0.808120, 0.065550, 0.079470, -1.190330, -0.995280, 1.003220,
0.204920, 0.211570, 0.432390, -0.459440, -0.120860, -1.040340, -0.729430, -0.724830, -0.005830, -1.062840,
-0.053920, 0.204780, 1.303940, -1.152590, -1.129220, 1.245240, 0.852570, 0.677980, 1.393460, -0.396240,
0.672320, -1.329710, -2.952470, 1.926500, 0.119360, -1.756660, 0.598840, -0.652640, -0.080820, 0.643460,
1.442720, 0.572190, 0.135930, -1.388100, 0.633310, -1.198380, 1.399690, -0.224690, -0.600530, 0.457880,
0.646240, -1.473680, -0.552920, 0.443850, -2.792300, 1.338940, -0.734560, -4.603270, 1.758250, -1.103390,
0.524250, 0.903950, -1.583320, 1.935260, -1.043750, -0.055590, -1.792440, -0.986790, -0.262510, -0.340680,
-0.883600, 0.066470, 1.179650, 1.841800, -2.538190, 0.771210, 1.324720, -0.386390, -9.124940, -2.048560,
-0.983010, -0.147660, 2.469750, 13.861500, -0.271770, -4.473790, 0.539120, 2.241620, -7.441120, -0.046010,
-0.021220, 0.448950, 1.821030, -0.000830, 0.697490, 0.281720, 6.001150, 0.962930, 0.481740, -4.497990,
-1.851200, -4.237570, 1.040780, -0.509590, 1.804530, -0.993310, 1.729490, 1.193030, 1.998060, -5.118380,
1.171310, 0.958270, 0.514010, -0.475760, 0.442970, -0.210510, 1.048940, 2.032440, 1.577490, 3.843100,
-6.290610, 0.498570, -3.008900, 3.283520, 0.687840, -5.062630, -0.676300, 2.432150, 0.670260, 0.533240,
-2.186240, 0.737120, -0.258150, 1.688760, -0.703620, 1.794780, 1.023320, 0.878440, -0.071550, 6.121300,
-1.569650, -11.468210, 0.509080, -2.108600, 3.910220, 0.732420, -5.254880, 0.008500, -0.330760, 2.445330,
1.255130, -1.760510, -2.071390, -2.006320, -0.855180, 0.594160, -1.471010, -0.070590, 0.619160, -1.057910,
2.115580, -0.447890, -9.887750, -0.404350, -6.521740, -1.759700, 2.224350, -1.649260, -0.113200, 0.122800,
1.324780, 0.716000, 1.876800, 0.663740, 1.674870, -0.817650, 2.455070, -1.484530, -0.378920, 1.303630,
1.124080, -0.434490, -0.311920, -7.115250, -0.497670, -2.946830, -1.167620, 2.526720, -1.473400, -0.873490,
-0.750590, -1.306290, -0.603750, 0.792270, 2.455160, 1.862200, -0.048980, -0.995690, -0.452770, -1.035920,
0.101460, 1.519470, -0.083450, -0.200160, -2.502840, -0.305400, -0.038360, -0.881510, -0.521360, 2.219450,
0.325280, -1.613440, 1.085120, -0.670930, -0.611460, -4.687750, 1.074690, -1.566820, -0.239670, 0.539400,
0.178170, 0.787580, 0.769300, 0.232590, 0.698050, -0.018980, -2.113550, 0.134650, -0.760590, 0.735420,
-0.663390, 0.837020, -0.031270, 0.076780, 0.797580, -0.338320, -0.902740, 0.011170, -0.099810, -1.495120,
0.673890, -0.399520,
-0.666620, 0.221970, 0.217400, 0.391070, -1.006290, -1.428050, -2.653080, -0.773450, 0.264820, 1.193180,
0.579520, 0.223570, -0.481390, -0.253020, 0.129600, -0.557010, 0.515310, 0.123420, 0.783410, -0.243220,
-0.421830, 0.915870, 2.008960, -0.734250, -0.143070, 1.175590, -0.184820, 0.210800, -0.283210, 1.343840,
1.149120, -0.317990, 0.595820, 0.622640, 0.745100, -0.671430, 0.195520, 0.571730, 0.776820, -0.385760,
0.682100, -0.112850, 0.629060, 0.668430, -1.134470, -0.531260, 0.145380, 0.714560, -1.381470, 0.240780,
0.726160, 0.024160, 1.379020, 0.073210, 0.585590, 0.477250, 0.051380, -1.824910, -0.217230, -0.845420,
1.360420, -0.168030, -1.726310, 1.803170, 0.213920, -1.208710, -0.621590, 1.350090, 1.346350, 1.262980,
-0.473530, -0.193610, 2.423060, -1.555620, 0.903340, 0.216980, 0.457030, -1.139510, -0.832990, 0.170040,
0.217190, 0.197130, -0.402120, 0.567570, 2.310200, 0.809600, -0.491020, -0.554230, 0.381860, 0.741000,
0.704880, 0.506020, 0.186680, -0.307870, -0.920420, -0.034250, 0.481670, -0.486750, -1.071550, -0.053780,
0.216650, 0.609530, 1.017320, -0.047600, 0.262240, 0.499000, 0.259460, -0.764400, -0.152640, -0.853960,
0.073360, -0.031220, 0.648750, 0.362910, 0.564930, -0.899560, 0.870820, 1.469740, 0.765370, -4.049920,
0.280290, -0.431480, -0.844370, 0.702870, -0.508280, 0.327770, 0.595520, -0.645560, -0.662150, 1.766300,
3.240680, -0.599430, 1.632000, -0.559030, 0.827990, 0.092230, 0.001080, -0.668130, 0.262930, 0.405560,
1.038370, 1.461190, -0.650830, 1.771000, 0.325780, 0.580850, -2.046770, 0.144860, 0.288840, -1.904010,
-0.953580, 1.272930, -0.554770, -3.449950, 0.705770, -0.495880, 0.473490, 1.337040, 0.801400, 0.546880,
0.450760, -0.475270, -0.335100, -0.304710, -1.516780, 0.450950, -1.035930, 0.722910, -0.165660, -0.891000,
0.936650, 0.883600, 0.914030, -0.865630, 2.611630, -0.016000, -1.272250, -0.894500, -0.590070, -0.049100,
-1.291130, -0.190530, -1.193810, 0.455050, 0.538020, 1.353040, -0.505190, -0.296400, 0.590750, 1.273780,
-0.903140, 0.214250, -1.122760, -1.328320, 0.868440, -2.689610, -0.223970, -0.756210, 0.482190, 0.060770,
0.427460, 0.738740, -0.063770, -1.041200, -1.728100, 1.732130, -1.820090, -0.117040, 0.012050, 0.257230,
1.336970, 1.693550, 0.813830, -0.616290, 0.086730, -0.110970, 0.042230, -1.101440, -0.436280, -0.341730,
0.009690, -0.231810, -0.451570, 1.015000, -0.273340, 1.758450, -0.050280, -0.488320, 0.517830, 0.006640,
-0.139670, -1.721660, -2.492020, -0.875760, -2.129060, -1.939770, -2.897210, -1.359140, -2.952710, 0.114250,
-1.740700, -0.970280, -2.707610, -1.357540, -1.923090, -0.033840, -0.567480, -1.915990, -1.577400, -0.360140,
-1.222200, -0.746480, -5.033170, -0.771270, -2.250690, -2.514960, 0.684470, -0.610660, -0.799650, -1.542780,
-1.021390, -1.417300,
-0.652060, 0.868890, 0.592960, 0.314890, -0.629200, 0.221390, -0.181470, 0.307420, -0.003190, 0.263860,
0.112950, 0.972880, -0.496340, 1.284710, 0.468180, -0.476150, 1.358940, -0.932250, 0.119360, 0.407770,
-0.403360, 0.407730, -0.116280, 0.721250, 1.046320, 0.756670, 1.819340, -0.623630, 0.098050, 0.645720,
0.113940, 0.091620, 1.251460, 0.929120, -0.370490, 1.604630, 0.271930, 1.726750, -1.571500, 1.067150,
0.070470, 2.194340, 0.005730, 0.275700, 0.695850, 0.119560, -0.052240, 0.737990, 0.603630, -0.562800,
-1.001210, 0.719790, 0.627040, 0.670160, 0.439630, 0.117010, 0.491150, -0.496320, 0.587270, 0.373560,
1.325240, 0.605560, 1.603870, 2.843890, 1.227370, 0.378050, 1.934890, -1.554970, -0.934730, 1.254770,
0.261840, 0.604460, -0.556400, 0.370860, -0.771360, -1.754850, 1.282100, 0.884910, 1.251020, 0.572650,
0.045170, 0.368280, 0.454550, 0.160870, -0.075710, -1.236150, -1.147480, 0.221280, -0.443810, -0.583250,
1.409020, 1.427690, 1.524840, 0.351280, -0.370030, 1.144730, 2.022810, 2.704480, -1.075710, 0.931900,
-0.558310, 0.180740, 2.855820, -5.360800, -0.016880, 1.208310, 0.046410, -1.037710, -3.645320, 0.098770,
1.910930, 4.610800, 2.617200, 2.771640, -1.066060, 0.425490, 0.816400, 6.751360, 3.089770, -5.970000,
0.217180, 0.145030, 1.643440, 2.020620, -7.317090, -2.219960, 2.363420, 1.005690, -0.643890, -0.062840,
0.741210, 1.477080, 4.645580, 1.259050, 3.683100, 1.475170, 0.280980, 1.402490, 8.028700, 1.840640,
-10.257120, 0.310920, -0.120020, 1.767840, 1.257900, -9.693060, 0.647350, -0.396070, 2.432670, 0.271180,
-1.048430, 1.661340, -0.555090, 1.443080, 0.017100, 2.462520, 0.422790, -0.028070, 0.964740, 3.530310,
0.925580, -9.436460, -0.508010, -1.216890, 2.489500, 4.293640, -2.877210, -1.483820, -0.599490, 1.338310,
-0.981250, -0.190670, 0.920360, 0.711170, -0.559910, 0.459970, -1.536340, 1.347120, 1.365230, 0.575270,
2.334250, -0.755150, 0.090600, -0.005850, 1.044190, 2.452350, 0.481240, -2.872870, -1.117060, -0.573530,
0.225840, 0.045320, 2.600490, -1.859210, 1.538510, -1.233590, 0.009660, 0.722760, 0.883100, 0.074290,
1.763300, 2.008550, 0.691440, 0.889240, -0.030770, -0.785110, 0.476480, -0.394440, -0.013790, -0.021570,
-1.314460, 1.293810, 0.392100, 0.782630, 3.270280, 1.697430, 0.120000, -1.896670, -0.555090, 0.041830,
-0.919350, 0.234220, 2.446320, 3.322940, -1.829290, 0.111850, 0.971860, 0.074700, -1.734250, 0.519720,
-0.612310, -0.651040, -0.746230, -0.002690, 0.439290, 1.818420, 0.620180, 0.541360, -0.638080, 2.040350,
0.446490, -0.011030, -0.975020, 1.138630, -0.732690, -0.688390, -1.390030, -0.642840, 0.799070, 0.115580,
-0.171260, 0.428980, -0.521380, -0.082130, 0.048350, 0.101270, -0.646350, 0.184130, 0.176940, 0.238820,
0.816750, 1.223490,
0.447690, 0.640480, -0.653530, 0.294010, -1.521950, -1.072220, -0.467980, 1.004250, -0.018220, 0.997620,
-0.029570, -1.850660, -0.822920, -0.587570, -0.811610, -1.180840, 0.965410, -1.309260, -0.184250, -1.186760,
0.450000, -0.328550, -0.005210, 0.566400, 0.385410, 1.101440, 0.540350, -0.777610, -1.795630, 0.037100,
1.399840, 0.401900, -1.839130, 0.645330, 1.647490, -1.210740, 1.710930, 0.092110, -0.435660, -0.934500,
1.219330, 0.858850, 0.113730, -0.493190, -1.905780, -0.140130, -2.093860, -0.116000, -0.224850, -3.879870,
-0.081380, 0.699920, 0.646460, 1.304110, 1.457560, 0.121840, 0.186110, 0.483860, -0.304840, -0.984300,
0.326190, -1.530490, 1.969310, 0.031860, -1.010830, 1.062240, 0.620260, -0.627970, -0.689260, 2.783450,
-0.023820, 0.734600, 0.789760, -0.660010, -0.422660, -0.286330, -2.184650, 0.698420, 0.080700, 1.581380,
-0.002940, -1.000370, -5.647230, -0.489810, 0.199630, 1.174430, -0.384170, -1.943700, 0.047130, -0.372640,
0.177170, -1.150170, 1.977420, 1.106140, -1.499910, 2.141310, 1.830000, 0.168480, 1.023640, 0.913260,
-1.234440, 0.697140, 2.338310, -9.076580, -0.140070, 0.346790, -0.563810, -0.850840, 0.856450, 0.990390,
0.489150, -0.091280, -1.628290, 0.003650, 0.862310, -1.507450, 5.819370, 1.374510, 0.521910, 1.130920,
-0.851720, 0.375800, -0.802270, -0.244910, -2.156510, 0.224170, -2.413070, -1.411450, -1.499250, 3.007630,
-2.181130, -2.880260, -1.011100, -5.285180, 0.809320, -0.312310, 0.113830, 1.173010, 0.342780, -0.387450,
1.624040, 0.240150, 1.870170, -0.078920, -3.040610, 1.145940, -0.514320, 0.735880, 0.350450, -0.468110,
1.032470, 0.205150, -0.642910, -0.083420, -4.512810, 1.967010, 0.747980, -0.421060, -0.447690, 0.930240,
-2.231450, 2.129070, 1.160310, 0.705040, 1.367430, -1.115930, 3.746980, 0.034830, -0.427280, -0.347940,
0.178430, -0.775320, 1.320290, 1.230320, -0.150540, -2.342770, -0.992460, 0.891890, -0.334690, 0.216430,
-1.936090, 0.348270, -0.118050, -0.398750, 0.746100, 0.585400, 0.556040, 2.239130, -0.042490, -2.502250,
-0.889180, -3.149300, 1.630120, 0.971510, -0.124290, 0.551420, 0.354980, 0.052460, 1.694620, 0.874470,
-1.582230, 1.592700, 0.473330, 1.888470, 1.730040, -0.371430, -3.902050, -0.795130, -0.575730, -0.603150,
-0.410460, 0.205870, -2.062750, -0.121220, 0.083190, -0.118890, 0.537270, 0.346560, 0.055130, -1.018800,
-0.958010, 0.399730, 2.381800, 1.442510, -2.144260, -0.288210, -1.009770, -1.327790, 1.157430, -1.349720,
0.714750, 0.614000, -0.241590, 0.556490, 1.374090, -0.112070, 0.432240, 0.961250, 1.089520, 0.958790,
1.299450, 1.647460, -0.177200, 1.322320, 0.825930, 0.902860, 0.275450, -0.523430, 0.039650, 0.705960,
-0.099330, 0.902440, -6.261430, 1.422310, 0.143150, 1.234640, 1.163560, 0.743640, 0.630690, 0.532110,
0.425450, 1.403310,
-0.250960, 0.974520, 0.711770, 0.344140, -0.808400, 0.410170, 1.636980, -0.400540, -1.310080, 0.070200,
0.760340, 1.508650, 0.542400, -2.336370, 0.503390, -1.129970, 0.725650, -0.644030, 4.403190, -0.580920,
0.895130, -0.984170, 2.037340, 0.085630, -5.223950, 1.833310, 3.198390, -0.302650, -0.120690, -0.357700,
-1.940430, -0.063810, -2.376400, -0.375150, -0.045750, -0.806300, 2.045020, 2.069940, -1.785130, 0.322580,
0.517060, -1.691350, -0.405100, -0.131890, -0.152340, -0.033030, -1.209150, -0.023180, -3.638720, -1.861250,
0.369620, 0.112600, 0.790220, 0.552900, -0.388800, 0.837630, -0.742870, -0.869720, -0.672630, 1.370700,
1.012980, 0.446120, -0.755150, 1.421160, -1.268890, 0.376680, 2.260090, -0.485280, 1.030440, -0.080080,
0.646240, -0.554600, 0.049410, 1.322440, -1.247600, 0.016910, -1.943290, 3.095940, -0.077920, 0.158730,
1.303170, -2.230070, 1.495280, -0.827030, -0.418000, 1.362720, -0.039310, 1.080900, -0.493930, 0.680860,
-0.078560, -1.148840, 1.426360, 0.039590, 0.973320, -0.070240, -1.830820, -0.676880, -0.447910, 0.495150,
0.794060, 0.459540, -0.283470, 2.220200, -0.807490, 2.208680, 0.279380, -1.947710, -0.128690, -1.221090,
0.240510, -3.983430, -1.781040, -1.879830, 0.048530, 1.322720, 1.006410, -0.937320, -0.109220, 4.241220,
0.760190, 0.597170, 0.336370, -1.121880, 2.501760, 0.075830, 1.441230, -0.656430, -1.806680, 1.336790,
2.491940, -0.115700, -1.787930, -4.556660, 0.715570, -2.262510, -1.295900, -3.224440, -4.376110, 0.385860,
7.178830, -1.942750, 3.736520, 1.130610, -1.881350, 4.410280, 0.099270, 2.226930, -1.098350, 1.745560,
3.252080, 2.380530, -0.866190, -0.808160, -2.927310, -0.314550, -0.002080, -1.675960, -0.427940, 0.007460,
1.530000, 9.616310, 0.052320, 7.011370, 2.553500, -0.861530, 3.727380, 0.004550, -0.731050, 2.808050,
0.882790, -1.908870, -1.469340, -0.431110, -1.415650, 0.516780, 0.566230, -0.741480, -1.338300, 0.445470,
-1.425740, 0.471000, 3.818170, -0.695730, 4.713260, 0.341880, -2.521970, 1.835590, 3.893770, 0.795210,
0.472710, 0.708940, 0.648660, -0.346810, 1.179300, 0.113840, 0.795490, -1.402200, 0.749480, 2.283280,
0.438990, -0.185510, 0.864880, -0.906070, -1.082890, -1.267590, 0.918890, 1.674290, -1.676560, 0.310750,
0.841130, 0.888290, 3.388560, 0.151890, 0.554380, 0.488770, 1.167340, -1.332810, 0.477790, -1.442080,
1.196990, -0.551710, -1.646450, 0.415770, 1.602860, 2.485580, 1.963770, 1.059460, -1.123250, 1.724280,
0.647590, 2.841640, 1.564350, 0.461800, -0.019530, -4.614320, 0.307950, -0.306890, 0.006800, -0.470580,
0.157010, -0.132490, -0.233820, 0.533640, 0.347770, 1.051510, 0.158940, -0.023760, 0.464750, -0.124520,
0.918290, 0.808000, -2.043590, 0.213970, 0.730310, -0.114470, -0.838070, 0.238440, -0.285140, 0.615980,
-0.923080, -0.150980,
-1.067780, -0.639550, 0.229900, -0.761800, 1.785500, -0.026890, 1.120360, 1.764320, -1.416030, -0.915800,
0.582600, 1.196760, 0.833080, -0.510450, 0.925010, -0.163930, 1.150770, -0.121830, 0.830520, 3.914250,
1.416510, 1.142810, 0.542550, -0.021930, 0.307170, 0.888100, -1.351260, 0.640550, -0.151040, 0.405730,
-1.767410, -0.934200, -1.165990, 1.243870, -0.554670, 2.916700, 0.396650, 0.837490, 0.261540, -2.419130,
4.301460, -0.366950, 1.810210, 0.700460, -2.016040, 0.475530, -0.769910, -1.813750, 1.392270, 0.235330,
-0.667800, -1.203920, 0.862150, -0.617720, -0.621640, -0.346550, -3.445190, -0.980970, 1.154450, -2.225710,
-0.670470, 2.089740, 2.760020, -2.481160, -0.003030, -4.526840, -4.611110, -4.961950, 0.843460, -3.582790,
2.351980, -1.508600, 1.111920, -0.971550, -0.188880, 0.300940, -0.405450, -5.261050, -2.241600, -5.476160,
0.716940, 2.357910, -0.714980, 0.181050, -1.807130, 0.932450, 1.908700, -3.483970, -2.877690, 0.371880,
3.865540, 0.722690, -2.310390, 1.374120, 0.932810, 0.330920, 1.417650, 1.841490, -0.349190, -2.010970,
-2.970230, 1.571270, 2.320990, -2.263060, 1.744390, 0.195000, 0.499400, 1.676550, -0.117380, -0.213870,
1.272520, 2.094210, 0.699390, -0.116650, 0.015040, -0.440590, 0.174460, 3.025260, -2.303650, -2.788680,
0.207350, -0.608240, -0.975960, 0.669690, -1.154070, -0.780150, -0.462730, 0.812460, -1.150160, -0.494840,
-1.773410, 0.988640, -1.050100, 0.655430, -1.000460, 0.399990, 0.351870, 1.356970, 0.095870, 2.192780,
-2.108560, -1.940780, -0.082860, -0.689050, 1.418950, 0.808390, 0.654810, -1.252810, 0.823750, -2.233380,
-1.223870, -1.721110, -0.923010, -0.874160, -2.128900, -0.290320, 0.033630, 0.181210, 1.882340, 1.517990,
-0.439180, -1.815530, -1.285000, -2.308500, 0.426410, 0.636330, 1.010500, -1.916710, 1.682270, -1.566850,
-0.071240, 4.987850, 1.993130, -2.896080, 0.350100, -1.497300, 0.489210, -1.281110, 0.891760, -1.019550,
0.307770, -1.466070, 0.651370, 0.299690, 1.613100, 2.210640, -1.807540, 3.628990, 0.692180, 2.186110,
1.440790, 2.983090, 1.571370, 0.116250, 1.003110, -0.207780, -2.447570, -1.013090, -0.356420, -3.654310,
0.545370, 2.028530, 1.176080, 0.062760, 3.577630, -0.034470, -0.208960, -1.118080, 0.713860, 1.668250,
0.396460, 1.061680, 0.512650, -0.089590, -0.807230, 1.668790, -0.623560, -0.506820, 0.073050, 0.335440,
0.337350, 0.206000, 1.697120, 0.324250, 1.491250, 0.299980, 0.085860, -3.064260, 0.183790, 1.528730,
0.267920, -1.609170, 0.458280, -0.123250, -1.630960, 3.344830, 0.039820, 0.428270, 0.325900, -1.165540,
0.327460, 0.286350, 0.392910, 0.059780, 0.254970, -0.625940, 0.303790, -0.148810, -1.194010, -0.934970,
0.889060, 0.739090, 1.890600, 0.532050, 0.161460, -0.412090, -1.027250, -1.018210, 0.190970, 0.254560,
1.401600, 0.686810,
-2.070090, -0.201520, 0.060010, -0.911380, -0.675190, 0.767020, -0.162320, 0.979590, -0.016100, -1.599170,
-2.724310, -1.016850, 0.683850, 0.637970, -0.328940, -0.013570, 0.706140, -0.700980, -0.447890, -1.061610,
-0.196230, 0.203800, 1.683510, 0.217810, -1.052440, -2.316480, 0.303270, 0.784120, -1.518190, -1.435070,
0.546100, -0.140620, 2.905920, 1.342430, 0.405190, 1.459170, -1.305330, -0.682060, -2.114500, 0.601990,
-2.317440, 0.399390, -0.242890, 0.272990, -2.541520, 1.188660, -0.024170, 1.074940, -1.201810, -0.174740,
-0.393220, 0.386370, 0.532480, 1.517040, 0.112660, 0.038880, 0.426860, -0.575590, -1.147030, -0.633120,
-0.826000, -0.718160, -2.475080, -0.428600, 0.651200, -1.214940, 1.111790, -0.271580, -0.386510, -0.238470,
-0.929270, 0.625100, 0.891080, 1.114440, -0.503050, -0.798230, 0.265230, 0.530970, -1.147030, -0.821470,
0.605670, -2.013360, -1.599830, 1.439130, -0.463550, 0.350440, -0.039990, -0.893110, -0.299310, -0.263000,
-1.358320, -0.803480, -1.404090, -0.800780, 0.388180, -0.431000, 0.192940, -1.476680, 1.273170, 1.272970,
-0.165590, -0.832790, -2.311460, 2.438310, -0.186910, 1.175860, -0.544220, 0.485280, -0.241150, -0.678900,
-1.456480, -1.524720, -5.835970, -0.670050, 0.230420, 0.954770, -1.179980, -3.136990, -2.334850, 2.010410,
0.239200, 1.157690, 0.239570, -7.705220, 5.454610, -0.023830, -0.246780, -1.608370, -0.416540, 1.576170,
-0.686930, -0.166240, -3.895050, -0.546510, -0.657770, -0.574150, 0.065040, -3.266860, -4.126860, -0.794260,
5.187980, -0.859190, 2.510460, -1.449400, -2.215480, 2.086040, 1.133790, 0.700380, 0.153760, 1.094490,
-0.024010, 2.129430, -0.842840, -0.915590, 1.241070, -0.661570, -0.852530, -0.526020, -1.238750, -1.922800,
0.408510, 6.581940, -0.858170, 0.033000, -0.557620, 0.329040, 0.237530, 0.073180, 0.052480, -0.470590,
1.481330, -0.398600, -0.134130, 2.059950, -0.560950, 0.029620, 0.245290, -2.848850, -1.736630, -1.490120,
-0.475250, 0.831040, 2.689650, -1.221330, 1.352590, 0.849570, -1.566350, 0.132410, -0.128160, -0.199180,
0.502300, -0.021270, 1.149040, -1.698090, -0.607380, -0.927630, 4.479770, -1.465270, 0.860650, 0.683890,
-0.406350, -1.892540, 0.386150, -0.238450, -0.674240, -1.052600, 0.169330, 0.045940, -0.653900, 0.175970,
2.823570, -0.221060, 4.119980, 0.703210, -1.271560, -0.423130, 3.726950, 1.367650, -0.460390, 1.321510,
-0.472820, -1.220850, -2.866330, -0.701320, 0.090240, -0.389840, -0.658270, -0.140550, -0.375710, -2.963420,
-1.045470, 1.660820, -0.303850, -1.102800, 0.307350, -3.823800, -0.125180, 0.093570, -0.948570, -1.156230,
-0.395370, -0.761410, 0.285720, -2.758780, -1.364700, 0.070530, 0.068390, -1.000690, -0.262490, -0.539420,
-0.716600, 0.027930, -0.968380, -1.002470, 0.408820, 0.255660, -1.119960, -0.335610, 0.295910, 0.683970,
-2.862900, -2.689610,
-0.809580, -0.938620, -0.905760, 0.393410, -0.269770, -0.335000, 0.454570, 0.125010, -0.259160, 0.089620,
1.735920, -0.460550, 1.234730, -0.370830, 0.061170, -0.034850, -0.014510, -0.314960, 0.920770, 1.082490,
0.834080, 0.617570, 0.452820, -1.955730, 0.055990, 0.107690, -0.892410, 1.356390, 1.849970, 0.120550,
1.103100, -0.304730, 0.979710, 1.151300, 0.609760, -1.581940, -0.449970, 0.034610, 0.922240, 1.834710,
-1.580500, 0.089230, 1.303450, 0.250810, 0.045170, 0.768950, 0.602700, 0.114790, 1.252060, -1.040080,
0.926130, 1.432510, 1.021810, -0.074010, 0.061450, -1.353400, 0.229340, 0.168850, 0.940070, -0.385980,
-0.526710, -2.677640, 0.273600, 0.622540, 0.259600, -0.164640, -1.487830, -2.862750, 0.220050, -1.081000,
-2.494690, 0.551910, 2.986190, -0.673430, 3.062830, 0.673850, -0.714500, -0.183040, 0.213520, 2.004220,
-2.786360, -1.711420, -3.780830, 1.018110, 0.424330, -0.068910, -2.449720, -0.194560, -1.977690, -1.318450,
0.342750, -6.450300, -2.697840, 0.478400, -1.708060, 0.980520, -1.297850, 0.103720, 1.252990, -1.681530,
1.111180, -1.990560, -0.188020, 0.527270, 0.262370, 1.084570, -1.651400, 0.234110, 0.896430, 0.705390,
-1.583340, 0.191030, -3.862410, -1.690290, 2.009190, -1.247560, 3.171860, 1.096920, 0.017550, 1.444210,
0.544980, 0.126930, -0.178360, -0.398810, 0.751440, -0.022520, -0.916920, -0.159770, 0.707300, 1.124260,
0.130400, -0.342280, 0.983740, -5.260850, 0.064290, 1.577980, -0.313590, 5.032480, 4.529160, -0.776920,
-2.232190, 2.009170, 1.238050, 0.620140, 0.037920, -0.615500, -0.271390, -2.343720, -1.115600, 0.540960,
-0.910130, 0.721930, 1.029680, 1.520100, -2.197290, 1.008280, 0.028560, 0.579200, 1.038080, 0.013130,
-0.011920, 2.549900, -1.509110, 0.516830, 0.221980, 0.489790, -2.101780, 0.678710, -0.892060, -0.885200,
-0.670940, 2.544130, 0.777640, -0.058960, 0.510750, -0.464030, 0.449320, 0.443700, -1.080190, 1.321500,
3.964480, -0.106060, 3.091490, -0.174430, -1.437610, 1.069960, -0.420750, -3.157060, -0.698590, -0.483050,
-1.816050, -0.818330, 0.286600, 0.427310, -0.499870, 0.548300, -1.772820, -0.549340, -0.658900, -1.138590,
2.017660, 4.254040, 0.895720, -2.789840, -1.616110, -0.586850, 1.640580, -0.379210, -3.825670, 1.577270,
0.025110, -0.410060, 2.068790, 0.767020, 2.040750, 0.625240, 0.439640, -7.215780, -0.605250, 1.335280,
-1.933040, 2.121380, 2.707730, 1.616480, -2.626720, -0.101010, -3.426280, 0.250710, 0.653060, -3.092500,
1.475960, -2.863740, -1.110940, -0.208190, 0.129020, 4.904430, -0.089290, -0.170760, 0.135630, 0.452570,
1.740800, -0.778730, 0.612900, -0.436030, -0.374000, 0.687160, -0.182140, -0.105940, 0.654730, -0.422830,
1.419440, 0.482590, -15.719170, 0.117840, -0.604840, -0.011770, -0.516640, -0.253100, 0.983910, 0.480870,
0.939120, 0.182540,
3.286250, -1.177180, -1.825740, -0.051290, -1.116400, 1.528510, -1.015350, 2.064610, -0.843190, 1.235730,
-0.472270, 1.188690, -0.251880, 0.120800, 1.056690, 0.571830, -1.092330, -1.660820, -0.495980, 0.654090,
0.425040, -0.328360, -1.760500, -0.858560, -0.699820, -1.601880, -0.112420, -0.190100, -3.281630, -0.779160,
0.591450, -0.853570, 0.533280, 0.647400, -1.036920, 1.293370, 0.958280, -1.856490, 0.724170, -2.624900,
-1.989680, 0.643490, 1.688780, 0.914260, -0.712970, 0.174920, 0.285980, -0.227850, -0.557470, -3.042230,
0.346220, -3.290160, 2.296870, -0.167970, -0.831740, 0.302330, 2.506740, 1.406510, 0.583520, -0.373510,
-1.236710, 0.560940, 0.482270, -0.156900, 0.207670, -0.434990, -0.421370, -0.192890, 0.639880, 1.443120,
-0.435780, -1.163790, 1.088440, 1.646170, 0.879390, -0.170240, -1.281640, 2.620110, -0.551590, 1.039990,
0.859760, -0.544240, 1.350480, -1.303550, 0.496490, -0.467010, 1.402940, 0.892240, -3.778660, 0.289710,
-3.496910, -2.196430, -4.069390, 2.162740, 0.552860, 0.225710, -2.239910, -1.606000, 4.353610, -3.646950,
0.766530, -1.192880, -1.078120, 1.535620, -0.413670, 2.271040, -3.187620, -0.387030, 2.622360, -0.380690,
-1.629960, -1.497920, -6.059250, -2.117230, -0.839890, -1.743920, -0.502040, -1.124720, 1.395990, 11.052220,
-0.642510, 6.557330, 0.383100, 0.033120, 3.206520, 0.054430, 2.254140, -4.068710, 2.200470, 2.194050,
-0.608340, -3.774200, -0.349380, -11.691610, -0.123040, 4.002270, -4.203820, -0.749540, 2.042920, -0.369300,
7.279660, 1.757330, 6.326470, -2.130570, -6.338020, 2.472760, 0.496940, -0.980940, -0.677140, -1.498740,
0.389110, -0.360960, 2.142930, 0.576510, -2.931850, 0.104650, 3.069520, 0.341150, -1.044870, -0.009870,
-0.077370, 2.126490, -1.443830, 2.522310, -1.722700, -2.788310, -0.962280, 0.213370, 0.233100, -0.976360,
-1.877210, -1.057740, -0.095200, -3.652420, 0.015290, 0.235190, 0.409730, 3.432660, 0.392480, -0.680070,
-0.337140, -0.834730, 4.059430, -1.357780, -0.292780, -0.458750, -0.424600, 0.141800, 0.102630, 0.148650,
-7.020780, -0.114350, 0.724830, -0.946650, -1.078730, -0.102700, -1.983820, -0.073720, 1.667840, -3.583310,
-0.270960, 0.256420, -1.342080, -0.592630, 0.061610, 0.244570, -0.575110, -2.200260, 0.529410, -0.372550,
-0.509940, -0.689530, 0.474190, -0.109150, -0.376710, 0.938750, 2.836660, -0.288250, 1.732870, -0.068620,
-0.263120, -0.056440, 3.537710, 0.078210, -0.998270, 0.994040, -2.214690, 1.680550, -1.730760, -0.838040,
3.113300, -0.691400, 1.192820, -0.499200, 1.528100, 2.178050, -0.691470, 0.282130, 0.872850, 0.829620,
-0.645640, 0.667740, 0.336080, -0.091230, 1.468080, -0.435590, 0.253260, -0.342930, 0.377410, -0.627580,
0.761310, 0.082220, -1.189080, -0.331630, 1.160580, 0.669000, -0.103720, 0.907870, 0.630780, 1.515070,
0.812100, -0.384420,
0.788910, 0.333400, -0.043830, -0.407740, -1.504840, -0.556390, 0.067090, -0.314570, -0.114590, -0.418770,
0.552910, -0.128700, -0.502310, -0.773430, 1.188990, 0.390040, 0.133340, 1.053660, -0.305600, 1.000490,
-0.118260, 0.522200, 0.420630, 0.221540, -0.190870, -1.610490, 0.029040, 0.239820, -0.343940, -0.102320,
1.059620, 0.217340, 0.550190, -0.722270, 0.458530, 0.543440, -0.153150, -0.501670, -0.737380, -0.340070,
1.503870, 0.272210, 1.454270, -0.428120, -1.408950, -1.193400, -0.620810, 0.528350, 0.364400, 0.618460,
-0.417870, -0.957040, -1.610830, 0.630160, -0.862480, 0.410570, 1.115820, 0.685190, -1.214850, 0.670140,
0.240330, 1.851650, -1.434080, -0.753340, 0.180410, 0.515520, -1.044060, 0.790980, -0.819920, 0.687570,
-0.639250, 0.431410, -1.662870, -0.566750, -0.158520, 1.013670, 0.792860, -0.306350, -0.240820, -0.101400,
0.493840, 0.063740, 0.679300, 1.137150, 0.866600, 0.034140, 0.793660, 1.334920, -0.409520, -0.336740,
1.018970, 0.433120, -1.901980, 0.006620, 0.459150, 0.333940, -0.293560, 0.466180, -0.375010, -0.463120,
0.214950, -0.293120, 0.338850, -0.123360, 0.874330, -0.290420, 1.668620, 0.202960, -0.385930, -2.575970,
0.609180, 0.088990, 0.131750, -0.535660, 0.628220, 0.814970, 0.770280, -0.384960, 1.022160, -0.714560,
-0.859450, -1.684350, -1.284060, 1.203120, -0.388110, 0.009490, 0.192430, -0.357520, -0.453420, 0.129210,
0.261240, 0.363800, 1.374600, 1.075770, -1.095870, -1.072800, 0.479860, -0.325960, 0.307670, 1.383570,
-0.807860, 0.309820, -2.786860, 1.768950, 1.159920, 0.361270, 0.344490, 0.668260, 0.795060, 2.274350,
0.170770, 0.343340, 0.113610, 2.553140, -0.720200, 0.458020, -0.862380, -0.159060, -0.033470, 1.803820,
0.257040, -0.475630, -0.404740, 0.187840, -0.774900, -0.016520, 0.035750, 1.131750, -1.226800, -0.280440,
1.361940, 0.137540, -1.899830, -0.059760, -0.536130, -0.874480, 0.251480, 1.544570, 0.022520, 1.298710,
1.215840, 0.362770, -1.691180, 0.897200, 0.326750, -0.869790, 1.548360, -1.061960, -1.842560, -0.698210,
0.092020, -0.413740, -0.323210, -0.461640, 0.529850, -1.429160, 0.479990, -1.341890, -0.335610, 0.067530,
1.957590, 1.148320, -0.250800, 0.106370, -0.896470, -0.085180, -1.190780, 0.590930, 1.910080, -0.621400,
-0.452130, 0.584820, 0.218590, 1.555070, 1.044310, 0.757200, -0.813810, -0.683350, 0.245260, 0.532430,
-0.048260, 0.682540, 2.158350, 0.126460, 0.650840, -0.274260, 0.525270, 0.464570, -0.616620, 0.961620,
0.603850, 0.291640, -0.609690, -1.581690, -1.662430, -2.033050, -0.188310, -0.628570, -0.911280, -0.891380,
0.864720, -0.875640, -1.588060, -1.024890, -0.584420, -0.457660, -3.692550, -0.727020, 0.107170, -1.314750,
-1.091260, -1.140610, -2.292110, -1.166700, 0.072280, -1.167350, -0.447800, -0.542660, -0.163410, -3.219470,
-0.726740, -0.430500,
0.170980, 1.584200, 2.630240, -0.465170, 0.405550, 2.047200, -1.811950, 0.364810, -1.165370, 1.002320,
1.083010, -0.571400, 0.133040, -1.508920, 1.357230, -0.981980, 0.635510, -3.303240, 1.019600, 1.790200,
-0.735480, 1.898700, 0.964190, 1.778350, -0.201240, -0.179230, 0.020550, 0.247370, -0.283250, 0.332510,
0.123440, 0.749780, -0.643510, -0.335420, 0.505340, 3.331720, 1.336220, 1.897390, 0.665860, -1.383200,
1.546580, -0.898090, 0.839920, 1.244040, 2.462270, -0.841430, -2.654970, 0.185870, -1.570450, 1.182060,
-1.172930, -0.135200, 0.033790, 0.225150, -1.821750, 1.192670, 0.763750, 0.963400, -1.231540, -2.709920,
-0.373240, -1.212100, 0.326680, -0.007160, 0.406830, 0.657010, -0.478250, -0.549370, -0.423410, -0.527010,
2.836130, 0.726240, 0.991460, -1.113320, -0.116540, -0.373540, -0.495350, -0.311910, -0.458070, 0.563380,
-2.179900, 1.234340, -1.717810, 0.338080, 0.430190, 1.137270, -0.945850, 1.139120, 0.068830, 0.911930,
-0.624320, 0.871830, 0.864240, 0.567220, -0.477650, -0.911870, 0.466000, 0.795280, -1.402330, 1.517690,
-0.559290, 0.758430, 0.983720, 2.488230, -0.289630, 0.641130, 2.888490, 1.821120, -1.158010, 0.134830,
-1.270630, 5.122390, 3.666290, 1.333750, 0.327070, -1.374550, 1.599430, 1.283870, 1.225930, -6.420550,
-0.833320, -1.251870, 2.558190, 3.501350, -5.386190, -0.189140, -1.115380, 2.935720, 0.903470, -4.020680,
-1.521280, 3.347860, 1.053440, 10.728390, 0.714210, 2.595480, 1.462370, 3.081120, 1.793530, 3.613960,
-10.421180, 0.757440, -5.599880, -0.601050, 4.628150, -4.880780, 1.680940, -2.516640, 2.844110, -1.555620,
-2.992990, 0.362620, 2.628110, -1.430920, 4.313100, -0.194980, 1.339140, 0.425660, 2.292370, 0.767880,
-1.325730, -9.448450, -1.402550, -3.199090, 0.648750, 3.822520, -1.728090, -0.781770, -0.661620, 0.683120,
1.250070, 1.350590, 1.477050, 0.222630, 0.829740, -0.034250, 4.561960, 1.035340, -0.501850, 0.683820,
0.226930, -0.499230, -1.498480, 1.007120, 1.796310, 0.856360, 1.826150, -0.972910, -0.517950, -0.448490,
0.722440, 1.379660, 0.531650, 0.805210, -0.960960, 1.504550, 0.637550, -0.523170, 1.030600, -0.097270,
2.938340, 1.721830, -0.480340, -1.264570, 1.116690, -1.623720, -2.248580, 1.521700, 0.297430, 1.303610,
0.409640, 0.653220, -0.754210, -0.400920, 0.742750, 0.171660, -1.796700, -1.561110, -1.923500, 2.681230,
1.076970, 2.502140, 0.870180, 0.812670, -1.443600, -0.251470, -0.745430, -3.109470, 1.673110, 0.486480,
-0.815890, -0.528240, 0.644970, -0.874090, 0.131870, -3.193370, -1.165260, 1.303440, -0.024580, -0.749490,
-1.940220, -1.399330, 0.681190, -0.654670, -0.031140, -0.245340, -0.164340, 0.850490, 0.618820, -0.669650,
-0.247800, -0.879400, 1.851930, -0.584550, -0.333890, -0.503710, -0.568820, -0.870330, 0.298910, -0.244750,
1.054950, -0.470450,
-0.564880, -0.566710, -0.332950, -0.391020, -0.199420, -0.418240, 0.981770, 0.001850, 0.322580, -0.030010,
0.901840, 0.638200, -0.185530, 0.627570, -0.795880, -0.238760, -0.001930, -0.350140, 0.854010, -0.299660,
-0.164080, 0.220570, -0.675670, -0.228830, -0.510790, 0.374840, -0.393760, 0.028300, 0.889990, 0.990180,
-0.063410, -0.867860, 0.918530, -0.322140, 0.175750, 0.894000, -0.784350, -0.182930, -12.851990, 0.774740,
-0.302850, 2.814900, 1.058370, 0.157760, -0.819670, -0.210910, -0.054910, -0.952960, -0.245170, 0.506470,
-0.393760, 0.769220, 0.588600, 0.395850, -0.554930, -0.286130, -0.174070, -1.454590, -0.387760, 0.910190,

-0.437210, 0.122170, -6.019180, -1.561640, 0.228540, 0.846890, -0.787150, 0.255280, -1.069400, -0.512310,
-0.876090, -0.451690, -0.438060, -0.231250, -1.547670, -0.234420, -0.018890, -0.598500, 0.053300, 1.135080,
1.031030, 0.759770, 0.545770, 0.338710, 0.006510, 0.167010, -0.223780, -1.654020, 0.254360, 0.686110,
0.244260, 0.789570, 0.469430, -0.223850, -0.226880, 0.705850, 0.207880, 0.243580, 21.846680, -1.920800,
0.877630, 11.234120, -1.090300, 0.775560, 0.537760, 0.031740, 0.278810, -0.135550, -0.105700, -1.215980,
-1.788500, -0.695570, 0.594660, 0.749730, -0.434360, -0.035280, -0.649350, -0.350430, 0.691050, -0.253000,

-0.999330, -0.942060, -0.379750, -0.774900, -0.010810, 0.964090, -0.377420, 0.664080, 0.092530, 0.713640,
0.174870, -0.479850, -0.589020, 0.190610, -0.059000, -1.104850, 0.645500, 0.022030, -0.429430, 0.849330,
0.394520, -0.238850, 0.754490, 0.248500, 1.468160, -0.638680, 0.029060, -0.607980, 1.035750, -0.167600,
0.159300, 1.462140, -0.426860, 0.157120, 0.544560, 0.306540, -1.008550, 1.983450, 24.892441, -1.114010,
1.792260, 27.952049, -0.941750, 4.760120, 0.316700, 0.160990, -0.088710, -0.549300, 1.110700, 0.116780,
-0.938630, 0.970290, 0.382760, 0.204260, 2.060190, 0.899480, 0.594650, -1.681550, 4.650600, 0.246260,

0.738420, -0.134630, 0.258190, -1.034150, 0.100930, -0.382950, 0.645610, -1.043300, 0.514010, -0.875720,
-1.031070, 0.636150, 0.455340, -1.030420, -0.456170, 2.314800, 0.695310, 0.192800, -0.579180, 0.021940,
1.531380, 0.286200, 0.496270, -0.176170, 0.155750, 1.065710, -0.695900, -0.350470, -2.037780, 0.810710,
-0.561220, -0.607030, 1.111740, 0.687000, -0.279370, 0.723850, 0.735500, -7.463720, -2.238110, -0.609210,
-0.220020, -0.013560, 1.074360, -0.423250, -0.700470, -0.000930, 0.246570, 2.680290, 0.214850, 0.259810,
0.109080, -0.763110, 0.390680, -0.361530, -0.666530, -0.720900, -0.472270, 1.150110, -1.250800, 0.398370,

-1.644670, -0.877170, -0.966470, -0.672920, -0.982740, 0.099220, -0.523480, 0.706730, -0.842620, 0.299000,
0.703820, -1.450790, -1.353290, 0.709930, -0.902740, 0.019890, 0.444590, -1.108580, -1.879790, -0.042690,
1.251270, -0.743530, 0.581840, -0.655310, 1.734890, -1.008000, -0.392100, -0.472430, -1.522380, 0.842660,
0.069290, 2.683080, -0.188060, 0.548940, 0.620390, 0.836910, 0.541610, -0.897770, 78.499428, -2.271420,
0.940220, 3.131500, -0.826630, 0.949410, -0.197350, 0.700560, -0.596420, 0.585270, 1.437800, -1.074150,
-0.819680, 2.103570, -0.225720, -0.596440, -2.648700, 1.970310, 2.120250, 0.875180, 4.252990, 0.222080,

-0.933180, 0.169940, 0.197000, -0.295400, -0.139070, -0.030310, -0.424770, -0.109690, -1.503830, -0.013110,
0.266190, -1.005770, -0.827690, -0.688290, 0.232080, 0.034810, 0.096780, -0.216770, 0.154940, 1.451100,
-0.675870, -0.674020, -0.915840, -1.494210, 0.535450, 0.913010, -0.763380, 0.457020, 0.103430, -0.395640,
0.028580, 0.013360, -0.672730, -0.451680, 3.877430, 0.747090, 0.219650, 0.812010, 0.940730, -0.434730,
3.354070, 1.763940, 0.783650, -1.653600, 0.848730, 0.667340, 0.577780, -0.031200, -1.053560, -0.809770,
0.435990, 0.832820, -0.006090, -0.773550, -2.270910, 2.196800, 32.430901, 6.706360, -0.958540, -0.350030,

-0.239780, 0.587970, -0.516690, 2.048800, 0.424170, -0.462240, 0.878980, 1.199440, -0.185010, -0.340280,
0.449510, 0.530700, 0.089220, -0.386800, -0.603220, 0.267260, 0.808120, -1.363080, 0.236040, 0.528080,
-0.657810, 1.918470, 0.085660, 0.426890, 0.245570, -0.665410, 0.860180, -0.513340, -0.013570, 2.869240,
-0.649170, -1.054280, 0.568500, -0.982340, 0.342480, 0.724660, -0.138440, 3.222420, -1.396260, -0.947720,
0.464550, 5.008160, 0.266500, 1.790730, -0.202680, 0.089520, -0.468160, -0.028400, -1.207470, -0.744130,
0.697020, 0.532840, -0.052350, 2.000000, 0.784530, -2.752020, -3.029560, -3.244370, -0.208110, 0.773070,

-0.269060, -0.774430, 0.399920, 0.171490, 0.429710, -0.801320, 0.977550, -1.224530, 0.580560, 0.148970,
3.030560, -0.986450, -1.482050, 0.916100, -0.724560, -0.846530, -1.655180, -0.927380, 0.945040, -0.684960,
-0.764920, -0.450710, 0.783470, 0.596500, 0.410710, 0.462930, 0.865530, -0.204580, 0.538510, 0.382300,
-2.947650, -0.442620, -0.663830, -0.272240, -0.452910, -0.795560, -1.159250, -4.463250, -2.053280, 0.079130,
2.788100, 0.245580, -0.306100, -1.506890, -0.103730, -1.179600, 0.308730, -0.902290, -1.278250, 0.368270,
0.290800, 0.708510, -0.579320, -0.191150, -0.483950, 0.189140, 3.400490, 0.950330, 0.266900, 0.108440,

-2.302510, -1.698700, -0.047460, -14.708380, -0.958720, -1.329220, -2.588200, -0.358190, -6.925410, 0.337300,
-2.150940, -11.665360, 3.550100, 0.338170, -1.990710, 0.472980, 1.925010, -2.538880, 1.956630, -4.881690,
-0.749030, -0.878110, 0.031150, -4.000170, 0.498260, 2.303360, -3.669790, 0.369220, 0.940570, -359.800232,
4.871050, -11.801730, -0.056990, 1.463630, -1.107580, -1.482780, 1.734700, -1.923550, 2.864260, -0.131670,
-0.109760, 1.044040, -2.622510, -10.863000, 0.838840, -1.474960, -0.832730, -4.380620, -2.987580, -2.124760,
-8.827640, -0.059270, 1.397480, -14.510860, 3.934490, 2.002470, -28.684879, 1.221880, -0.768290, -3.170810,

-0.045690, -0.198430, -0.346310, -0.698020, 0.326870, -0.420390, 0.210600, -1.233620, -0.987880, 0.339160,
-0.352120, 0.254010, -0.362870, -0.109030, 1.176260, 1.111130, -0.071180, 0.252250, 0.017090, -1.054470,
0.861570, -0.867940, 0.487230, 0.335450, -0.311950, 0.523880, 0.410290, -0.501940, -0.737580, -0.572070,
-1.103210, -0.654100, 0.017050, -0.365450, 0.540580, -0.873260, -0.391410, -0.701240, -0.087270, 0.090520,
0.677140, 17.393110, 0.366090, -0.336850, 0.222700, -0.125830, -0.128820, 0.567960, 0.522470, -0.557260,
-0.407810, 0.263920, -0.334910, 0.298330, -0.257390, -0.866840, 1.410210, -0.076960, -1.062650, -0.108440,

-1.177850, -1.281190, -0.260540, -1.495490, -0.911430, 0.301840, -0.213360, -0.522960, -1.101490, -1.210610,
0.514060, -0.092610, 0.822750, 0.002180, 0.039550, -0.536030, 0.785610, -0.177150, -0.534430, 1.554720,
2.001320, 0.771310, -0.784070, -1.505550, -1.591210, 0.668300, -1.085860, -2.530140, -0.278830, 1.574180,
1.253700, 0.934670, 0.263950, 0.078660, -0.264060, -1.121850, 0.880590, 2.105030, -12.199500, 0.328720,
0.403450, 4.682670, -0.004000, -2.442520, -1.243040, -0.014480, 0.617010, -1.297070, -0.926990, 1.345630,
-0.238840, 0.877000, -0.916790, -0.671340, -1.306670, 0.631940, -0.249490, 2.861630, -1.506900, 0.777880,

4.792850, -1.043260, -9.243680, -0.237560, -4.521630, -0.201000, -11.408740, 0.723170, -1.901490, 1.627250,
5.637260, 0.165250, -0.537320, -2.711620, 7.292180, -1.285370, -4.706710, -12.298100, -0.381990, -0.958040,
-0.365980, 3.221240, -2.392650, -8.528790, 0.277210, -0.372040, -15.630660, -1.191360, 2.745860, -0.053110,
-0.186870, 0.112380, -1.920580, -2.379010, -0.427370, -2.480660, -0.368530, 9.072410, 8.759240, 0.479930,
6.714970, -0.156480, -2.663270, -1.227910, -2.450940, -2.577730, -2.278260, 0.734610, 5.219160, -0.660600,
1.226760, -0.985030, -1.284430, 11.541320, -1.252120, 4.398290, -0.672340, -0.235800, 0.149410, -0.849020,

0.007450, 0.874940, -0.021700, 0.497080, 0.811860, -1.271840, 0.132360, -0.557840, -0.204720, 0.499670,
-0.700770, 0.457190, 0.623880, -0.403120, 0.441100, -0.605210, 0.785330, -0.574440, 0.268310, 0.856990,
0.030330, -0.676500, -0.182840, -0.168530, -0.294520, 0.645900, 0.144180, 0.261910, 0.611400, -0.448140,
0.065980, 2.822480, 0.101860, -0.754150, 2.571870, -0.923520, -0.599630, 2.109580, -7.499630, 0.724700,
3.181660, -9.660450, 0.965410, 9.621830, -0.673160, 0.774330, -0.148870, -0.583650, 0.258260, 0.890500,
-1.513170, 0.855760, 0.584200, 0.448100, 0.694110, -0.571880, 3.461950, -5.036210, 3.878410, 0.138700,

-1.950510, -1.214150, -6.228770, 2.584180, -0.757730, 2.001970, -0.621010, 1.441370, -1.111370, 1.857740,
-1.660050, -0.308830, -1.676940, 0.113780, 0.335150, -1.610010, -0.480530, -3.653530, -1.823440, 1.945590,
-0.824890, 1.533970, -0.887670, -4.510840, 2.219700, -0.983250, -2.489590, -1.255250, -2.075980, 0.396720,
-0.212640, 6.676550, 1.574050, -0.623100, -0.968860, -0.569080, -0.573580, -2.339580, -13.311950, -1.594130,
0.144740, 13.247910, -1.341430, -0.127910, -0.565070, -1.225690, -1.345730, -0.231990, 0.165190, -0.821060,
-1.491910, -2.323030, -1.014520, -1.975500, 0.316660, 0.211430, 4.386720, -0.046120, 0.262520, 2.790760,

33.808079, 33.794830, 33.931099, 34.856300, 34.841091, 33.556721, 34.203510, 34.234348, 34.334320, 33.747952,
34.918400, 33.311260, 33.270901, 35.179199, 34.926731, 33.744881, 33.580849, 34.794659, 33.451950, 33.526810,
34.707260, 33.450111, 33.934231, 33.637661, 33.364281, 33.850319, 34.310188, 35.182499, 35.137779, 33.502911,
33.954620, 35.234741, 34.284721, 34.945518, 34.303490, 33.800739, 35.246670, 34.110180, 33.729660, 34.310600,
33.702492, 1.553460, 34.356731, 0.820090, 33.729240, 34.932510, 33.318680, 34.871460, 35.202599, 34.513451,
34.494110, 34.099709, 34.920441, 34.677380, 34.297230, 34.373772, 35.146320, 34.918419, 0.348610, 35.029060,

-0.307640, 0.498670, -0.226650, 1.689070, 0.723850, 0.357840, 0.507910, 0.711750, -0.170050, 0.099610,
0.279370, -1.109470, -0.027450, -1.158380, -1.186620, -0.438280, 0.028050, -0.536020, 0.676120, -0.554480,
-3.728370, -0.132490, -0.948220, 0.178850, 0.883600, 0.228530, 0.648760, -0.169430, 0.560900, 0.704130,
-0.431050, 1.191650, 0.706660, -1.187680, -0.180770, 0.422120, 0.737400, 1.313480, 1.828000, -0.368590,
0.937370, -6.788540, -0.344590, 1.238640, -0.308800, 0.449770, -0.051410, 4.845680, -0.308760, 0.064100,
0.704960, 0.705310, 0.685220, 2.507480, 0.053550, -2.290670, -5.091810, 0.041290, -1.438470, 0.453920,

-0.220390, 0.792550, 0.996870, 0.787710, -0.229000, -0.040870, 0.017150, -0.292910, 0.482120, 0.626380,
-0.500080, -1.015470, 0.599130, -0.859490, -0.775790, -1.046860, -0.045290, 0.448480, 0.874310, 0.586440,
-1.472810, 0.021680, 0.853150, -0.579760, 0.403720, 0.846730, 0.341400, 0.275930, -0.128470, -0.631210,
-0.878140, -0.105500, -0.475880, 0.174600, -0.046680, -0.275370, 0.735820, -0.689490, -2.697500, 0.860120,
-1.366170, -0.980950, 0.367050, 0.218090, 0.329390, -0.086880, 0.357530, 0.762360, -0.091760, -0.609520,
0.794160, 0.871690, -0.264380, 2.401730, 0.308670, 0.598030, -0.873570, 0.838480, -0.047320, -0.346280,

1.399790, -0.525620, 0.821190, 1.530560, 1.559200, 0.436470, 0.330030, 0.561010, 1.076020, 1.010670,
1.054600, 0.958830, -0.331030, 0.521940, -1.107800, -0.069520, 0.239310, 0.494120, 0.607140, -0.127650,
-2.182180, 0.619710, -0.343130, -0.125280, 0.686490, -1.141680, 0.252920, -0.446250, 0.730800, -0.428750,
-0.715050, -0.066200, -0.244830, -0.473060, -0.412400, -0.560560, -0.580410, -0.493590, 1.627480, -0.178860,
-1.813610, -0.765640, -0.679680, -1.130950, -0.265390, -0.109730, -0.578390, -0.246240, 0.384970, -0.589260,
0.151030, 0.177750, -0.585370, 2.913440, 3.869860, -0.807310, -3.345440, -0.692460, -1.657860, -1.084490,

-0.085510, -0.293120, -0.335180, -0.552880, -0.363990, 0.918040, -1.162580, 0.623780, 0.765690, -0.092510,
0.987690, -0.111470, -0.534460, 0.975630, -0.495730, -0.865250, -0.470550, -0.015730, 0.781300, 0.956610,
0.263260, 0.593420, 0.826260, -0.696150, -1.190710, -0.325260, 0.273840, 0.112830, 1.213850, 0.124350,
-0.169280, 0.703860, 0.662480, 0.885210, -0.596640, 0.262180, 0.138550, 0.100090, -3.557950, -0.769040,
0.371090, 2.620790, -0.175250, -1.840300, -0.978110, -1.055210, -0.961760, 0.564040, 0.613730, 0.489220,
0.470270, 1.375480, -0.719980, 0.164640, 0.594020, 0.019120, 0.723800, -0.104450, 0.460370, 0.437820,

-0.863210, 0.650100, 0.248210, 1.139450, 0.451440, -0.263760, 0.750910, -0.596970, 0.354770, 1.272130,
-0.066950, 0.723980, -0.331390, 0.560090, -0.458400, -0.253350, -0.241210, 0.387890, 0.076100, 0.170090,
-1.141380, -0.817600, 0.741290, 0.571500, -0.021140, -0.656420, 0.927760, 0.055650, 0.912390, -0.184860,
0.094480, -0.942450, -0.776170, 0.569590, -0.291380, -0.875690, -0.916220, -0.247670, 6.374870, -0.626200,
-2.785250, 7.933800, 0.308380, 0.555650, 0.151750, 0.027500, -1.047030, 2.048570, 0.590030, -0.059400,
0.739540, 0.411600, 0.736730, 1.144600, 4.732760, 0.425670, -2.938740, 1.702720, 1.015450, -0.258950,

-0.700100, -0.017460, 0.903950, -0.947160, -1.267230, -0.446290, 0.368930, -2.321200, -1.142790, 0.535090,
-0.348930, 0.904920, 0.233040, -0.826820, 0.862570, 0.064630, -0.270310, 1.481890, -0.949390, 1.039500,
0.551180, -1.407590, 0.436470, -0.191900, -1.249130, -0.236420, 0.388530, -0.894470, -4.163690, -0.977380,
0.008040, -1.766290, -0.384630, -0.434500, 0.082090, 0.426630, -0.216930, -0.031070, -0.079890, 1.975880,
-1.258810, 9.425530, 0.191470, 0.879060, -0.543630, 0.772230, -0.002310, -0.225360, -0.699960, 0.003680,
0.233570, 0.921980, -0.801270, -1.184650, -0.133240, -0.407710, -11.348660, 0.497120, -1.070000, -0.090290,

1.566590, -1.103830, 2.284920, -0.185410, 0.158280, 0.562350, 0.757250, -0.131020, 0.355230, -0.705300,
-0.847710, -0.785810, -0.457180, -0.379410, 0.808890, -0.944740, 0.862370, 0.352800, 0.354670, -1.457340,
-0.300210, -1.407990, 0.188350, 1.190060, 0.876420, -1.273810, 0.786840, 2.210630, -0.701610, -1.449670,
0.090410, -1.426910, -1.249980, -0.861370, 1.510340, -1.075970, -1.136890, 2.710700, -15.231160, 0.020710,
-0.263490, 2.752210, -0.483190, -0.890920, 0.011530, -1.037870, -0.377170, -1.446360, -1.670210, 0.719700,
2.260200, 0.682300, -0.003220, -0.760420, -0.762040, 2.534400, 1.711770, -2.635710, 0.220260, -0.550370,

0.293450, 0.983250, -1.609900, 0.335410, -0.543020, -0.305930, -0.704490, -0.792370, -0.180970, -1.206590,
-0.618380, -0.873060, 0.153280, -0.073910, 0.625640, -0.705610, -0.374300, 0.861130, 0.894140, -0.487960,
-0.325800, -0.377140, 0.034740, 0.818160, -0.227120, -0.434770, 0.589560, -0.049850, -1.284200, -1.556720,
-0.037880, -1.113520, -0.216040, 0.005590, 0.318040, 1.133310, 0.687120, 2.277010, 52.369549, 0.466110,
-0.448830, -4.219560, 0.005990, -0.560920, 0.785340, -0.145000, -0.542810, -0.747750, -0.800320, 0.849820,
1.429060, -0.809120, 0.822370, -0.759370, -0.380880, 0.677930, 0.664550, 0.225120, -0.982540, 1.234620,

-0.704830, -0.636190, -0.501910, 1.640270, 0.381060, 0.725120, 0.344540, 0.946950, 0.733850, 1.020960,
0.313370, -1.114430, -2.990560, 0.917010, 0.235390, -2.408910, 0.310490, -0.158130, 0.346810, -0.000670,
-0.904060, 0.305380, 1.219420, 1.056980, -5.578660, -0.454430, 0.368690, 0.045470, 1.821070, -0.838080,
0.339510, -1.178500, -0.373080, -0.309420, -0.581530, -0.847880, 0.399770, 2.817880, -2.762320, 0.637050,
-2.733130, -5.493250, 0.396300, 0.611880, -0.545060, -0.397870, -1.005420, 0.782150, -0.833520, -0.735980,
1.342590, -0.695710, -0.647790, 1.215700, 1.970450, 0.102900, -0.265070, 0.998280, -0.374910, -0.177510,

-0.298290, 0.725690, 0.413950, 1.377780, -0.132520, 0.598550, 0.103120, 0.308700, 1.568820, -0.711290,
0.809860, 0.438560, 0.928110, 0.326470, 0.596420, -1.061060, -1.058840, 0.139170, 0.041060, -0.503250,
-0.994620, 0.160250, -1.338790, -1.300500, 0.412560, -0.787560, 0.295720, 0.400370, 1.010340, -0.101290,
-0.690900, 0.237150, 0.687540, 0.439300, 0.298970, -1.322500, 0.046030, 1.040120, -61.299599, -1.730650,
-1.787870, 1.594350, -1.139860, 0.149750, -0.743570, 0.060880, -0.480650, 0.613750, -0.395740, 0.052030,
0.080710, 0.493890, 0.271920, 0.767300, -0.848460, 0.009860, -0.872130, -0.719680, -2.339590, 0.406710,

-0.786260, -0.167100, -0.052180, -1.889420, -1.127990, 0.160730, -0.528000, -0.144700, -0.849000, -0.444400,
-0.561310, -0.610900, 0.134500, -0.018420, 0.506320, 0.240530, 0.491370, -1.267290, -1.414510, 0.293340,
2.436980, 0.031120, -0.399360, 0.289550, 0.939170, 0.506210, -0.444390, -0.812350, -0.446750, -0.345310,
1.007860, -0.358540, 0.011170, 0.047630, 0.163490, 0.943320, 0.241750, -1.190810, 2.749370, 0.245720,
1.500710, -15.655190, -0.920600, 3.346820, -0.495160, -0.201960, -1.211640, -0.829670, 1.104110, -0.099890,
-0.736190, -0.079840, -0.690820, -0.335850, -3.601060, 1.007810, 6.336330, -0.563850, 2.999750, 0.062220,

0.619250, -0.073870, 0.856880, -6.399350, -0.776630, 0.400700, 0.168020, -0.097320, -0.755650, -1.289520,
0.884830, -2.606870, -1.193670, -1.139580, -3.019260, -1.223810, 0.556190, 0.102240, 0.177720, -1.550370,
0.523640, 0.421080, 0.705270, 0.523350, -0.012240, 3.062680, 0.395650, -0.140200, -0.358940, 1.607550,
-0.619180, 3.678680, 0.850370, -0.802400, -0.590130, 0.155460, 0.376860, -22.792210, 5.106530, -3.785100,
-0.843180, 11.525940, 0.265860, -0.106430, -1.338130, 0.307410, -0.404940, -1.409610, -0.194940, -1.329720,
-2.499620, 1.873470, -1.280960, 0.384790, 0.151650, -0.325420, 0.021500, -4.568110, -2.169430, 0.331840,

-0.111060, 0.114400, -0.717090, -0.180750, -0.055380, -0.094540, 0.233000, -0.481200, 1.258740, 1.056880,
-2.581410, -0.218490, -1.144750, -0.436760, -0.746490, -0.806620, -1.320150, 0.584240, -0.107360, -0.661930,
0.341980, -2.044950, -0.523430, -0.311340, 0.363360, 0.314810, -0.996140, 0.620640, -0.739910, -2.277110,
-0.643360, -0.237710, 0.010180, -0.509150, -0.011240, -1.271280, 0.923460, -2.114240, 8.806300, -2.171160,
0.010990, 12.730250, 0.114390, 0.123460, -0.716250, 0.788080, -0.129170, -0.209030, -0.410850, -0.009430,
-0.705990, -0.259730, -1.082060, 1.296530, 1.078190, 4.016530, 1.345140, 0.062450, 1.407500, 2.477540,

-0.698650, -1.519810, -0.628070, -4.739530, -0.768000, 2.621170, -3.312530, -0.630490, -0.842100, 1.241110,
-0.611640, -0.621130, 1.453420, 0.107080, 0.271320, -0.800800, 0.752160, -1.597020, -3.100780, -0.916770,
2.769930, 0.926870, -0.348150, -1.223400, 1.859000, -0.922650, 0.075780, -0.364460, 0.517300, -0.043040,
1.797940, -0.853510, 0.924950, -0.428830, 3.698790, 0.767530, 0.125050, -10.496850, 4.086400, 0.545430,
1.713190, 22.030029, -0.888920, 0.870690, -1.731250, -0.997580, -1.479580, -3.664500, 0.028350, -0.531020,
0.362090, 1.101980, -0.558550, -3.352920, -1.254420, -0.539110, 2.808320, -1.745190, 0.678250, 0.179400,

-0.157710, -0.929560, -0.098930, 0.361260, 0.145140, -1.554490, 0.133710, 0.033540, 0.280310, -0.237740,
-0.080550, -0.166860, 0.242270, 0.892380, 0.582580, -0.842160, -0.405550, 0.049480, 0.996220, 0.964590,
-0.199430, -0.486600, -0.543440, -0.197680, -1.001660, 0.299000, 1.407110, 0.505620, -0.021290, 0.218960,
0.000350, -1.198790, -1.422290, 0.993390, -0.003780, 0.145410, -0.630630, 3.184310, -81.524406, -0.272370,
-0.888390, 12.141510, -0.544860, 0.818290, -0.476450, 0.108070, -0.133130, 0.752310, -0.817660, -0.779660,
1.096690, 0.092190, 0.042820, 0.225150, -1.618230, -1.370320, -0.531050, 1.924330, -0.993920, -0.724740,

-0.542590, 0.243800, 0.277020, 0.646070, -0.806640, -0.985270, -0.248150, -0.752210, -1.355140, 0.556760,
-1.212530, -5.475900, 0.285810, -1.243800, -0.875450, 0.194840, 0.669780, 0.947590, 0.767250, 0.163510,
-0.005930, -1.576220, -0.530300, 0.601420, 2.202180, -0.853470, -1.710580, -2.239450, -1.205300, -1.032870,

-0.277970, 1.454900, 0.292710, 0.050340, 0.881470, 0.629730, -0.762330, -0.211630, 1.610910, 0.097630,
-0.044050, 0.621630, -0.622140, 0.718510, -0.454490, -0.894560, 0.077480, -1.414450, 0.154400, -0.630840,
-0.718160, -0.297300, -0.545620, -0.718350, -0.789390, -0.254280, 0.985210, 1.028430, 0.381080, -0.160610,

0.577150, -0.763770, 0.258370, -1.073420, 0.021380, 0.637040, 0.220750, 0.326150, -1.153970, -0.468520,
0.916160, -0.256790, -0.256460, -0.786330, 0.364950, -0.030090, 0.434320, -1.031580, -1.332870, -0.386200,
0.539120, 0.901250, 0.090070, -0.345410, -1.296020, -0.857620, -1.004890, -1.171430, -0.518530, 0.996060,

-0.603230, -0.657180, 0.409620, -0.873570, -0.597090, -0.592200, 0.655240, -2.908930, -0.214110, -0.250770,
-2.435060, -6.658850, 0.476050, -1.328200, 0.251360, -0.221960, -0.235740, 0.979400, 1.000960, -0.027260,
-0.624640, -0.696710, -0.492210, 1.041000, 2.330340, -1.368600, -1.978640, -1.175830, -1.834770, 0.032620,

-0.051500, 0.945670, -0.545150, 0.414900, 0.965580, 0.087880, 0.048820, -0.822100, 4.663460, -0.470570,
1.147750, 4.073290, -0.059980, 0.558070, -0.617070, 0.166040, -1.004210, -1.632670, 0.694050, -0.433900,
-0.700090, 0.077050, -0.048780, -1.287070, -1.332090, 0.402270, 0.959950, 0.915930, 0.547810, -0.269610,

0.414050, -0.369990, -0.711310, -0.017780, 0.308540, 0.378320, -0.545230, 2.142000, -5.239440, 0.203750,
-0.019380, -1.109090, -0.146760, -0.440020, -0.515140, -0.189690, 0.749590, -1.018350, -0.913710, 0.344370,
0.596730, 0.252370, 0.360840, -0.826150, -1.808150, -0.151410, -0.348170, -0.542620, -0.547720, 0.260690,

0.377890, -0.550190, 0.635190, -0.685570, -0.554990, -0.738280, -0.084520, 2.078810, -0.951680, -1.641040,
-2.600790, -7.619930, -0.300270, -1.350700, -0.187390, 0.859670, 0.004250, 0.832810, 1.109960, 0.509480,
-0.486630, -0.526050, 0.407580, 1.177220, 2.084950, 0.056690, -1.249700, -0.902410, -1.789190, -0.167290,

0.453430, 0.528230, -0.700080, -0.269680, 0.543260, 0.746160, -0.217210, -1.208280, 2.465880, -1.080970,
1.939110, 1.330770, -0.818500, 0.494150, -0.316390, 0.045980, -0.922180, -0.593120, 0.364090, -0.686330,
-0.334700, -0.398270, -0.516720, -2.024400, -1.893790, 0.493260, 0.763850, -0.397690, 0.427830, 0.727750,

-0.602400, -0.537900, -0.680260, -0.088300, 0.242280, 0.332080, -0.615850, -1.460720, -2.174810, 0.900140,
-1.141240, -1.746590, 0.460980, -0.650280, -0.208820, 0.088360, -0.016540, -0.785130, -0.882680, 0.293730,
0.547930, 0.482250, -0.113470, -1.014040, -1.977730, -0.193650, 0.033350, 0.617100, -0.425860, -0.366370,

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
      0.0, -0.182270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.115330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.183460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.786550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.536220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.814820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.118050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.553190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.347580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.465990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.902700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.548660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.911680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.914240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.615780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.558790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.363380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.041500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.643110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.101940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.842770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.688370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.076640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.523710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.119300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.595900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.918870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.699860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.936910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.539920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.614570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.537450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.855040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.354450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.018440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.932050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.672280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.828500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.164610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.763890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.173570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.392890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.391420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.479730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.804380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.465810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.369430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.792200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.484020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.475670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.529760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.187570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.606140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.254700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.065090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.111530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.972530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.106240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.765090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.194920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.946140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.473540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.109530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.994560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.530850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.700790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.667930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.949090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.014180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.944900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.962530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.574540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.060200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.259460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.920920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.224390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.030980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.536670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.646560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.151840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.310940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.340050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.543390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.499730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.691960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.035270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.148530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.471520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.012140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.037910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.092350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.476170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.799430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.830270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.375260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.779120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.944080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.126870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.572670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.210760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.030760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.794000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.418910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.758980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.722180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.454160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.870850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.313950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.618580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.055750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, -0.391150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.357470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.782090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.699950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.770000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.042880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.641700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.225640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.879630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, -0.499300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.406270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.777040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.401030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.975980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.041640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.475060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.756210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, -0.070880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.365400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.899110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.729060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.763250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, -0.041180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.960340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.366540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.443440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, -0.736640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, -0.721770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.649940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.340660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.201790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.682100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, 0.168160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.009060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.774690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.924510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.813010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.149950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.579460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, 0.125800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.689420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.591130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.625880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.780140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.223500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.486900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.140270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.532050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.582890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.410910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.660300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.705990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.639050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.265370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.619220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.958470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.827540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.072970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.771410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.563410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.775040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.855330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.673830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.203060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.682730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.079260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.241530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.866810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.753640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.705810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.655780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.663220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.064530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.740130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.263970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.379070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.338360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.544030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, 0.901110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.277800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.637360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.116720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.331760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.365220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.522290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.796480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.628170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.280430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, 0.509450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.536830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.815990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.594620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.453410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.082010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.445000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.305880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.063860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.776730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.444000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.023000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.307950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.271810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.321350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.915390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.356650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.364560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.459890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.775960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.042730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.343720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.838460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.808000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.486690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.561360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.603170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.626000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.574770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.907310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, 0.781550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.127100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.970210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, -0.997990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (hid11) */
      0.0, -1.091830, 262,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (hid12) */
      0.0, 1.520080, 262,
       &Sources[262] ,
       &Weights[262] ,
      },
    { /* unit 235 (hid13) */
      0.0, -0.593050, 262,
       &Sources[524] ,
       &Weights[524] ,
      },
    { /* unit 236 (hid14) */
      0.0, -1.816030, 262,
       &Sources[786] ,
       &Weights[786] ,
      },
    { /* unit 237 (hid15) */
      0.0, -0.456010, 262,
       &Sources[1048] ,
       &Weights[1048] ,
      },
    { /* unit 238 (hid16) */
      0.0, -1.054100, 262,
       &Sources[1310] ,
       &Weights[1310] ,
      },
    { /* unit 239 (hid17) */
      0.0, -0.578340, 262,
       &Sources[1572] ,
       &Weights[1572] ,
      },
    { /* unit 240 (hid18) */
      0.0, -0.508810, 262,
       &Sources[1834] ,
       &Weights[1834] ,
      },
    { /* unit 241 (hid19) */
      0.0, -1.716590, 262,
       &Sources[2096] ,
       &Weights[2096] ,
      },
    { /* unit 242 (hid110) */
      0.0, -0.291960, 262,
       &Sources[2358] ,
       &Weights[2358] ,
      },
    { /* unit 243 (hid111) */
      0.0, 0.277950, 262,
       &Sources[2620] ,
       &Weights[2620] ,
      },
    { /* unit 244 (hid112) */
      0.0, -0.091070, 262,
       &Sources[2882] ,
       &Weights[2882] ,
      },
    { /* unit 245 (hid113) */
      0.0, 0.478670, 262,
       &Sources[3144] ,
       &Weights[3144] ,
      },
    { /* unit 246 (hid114) */
      0.0, -0.161790, 262,
       &Sources[3406] ,
       &Weights[3406] ,
      },
    { /* unit 247 (hid115) */
      0.0, -0.569210, 262,
       &Sources[3668] ,
       &Weights[3668] ,
      },
    { /* unit 248 (hid116) */
      0.0, -0.199300, 262,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 249 (hid117) */
      0.0, -0.585360, 262,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 250 (hid118) */
      0.0, -1.335540, 262,
       &Sources[4454] ,
       &Weights[4454] ,
      },
    { /* unit 251 (hid119) */
      0.0, 0.433680, 262,
       &Sources[4716] ,
       &Weights[4716] ,
      },
    { /* unit 252 (hid120) */
      0.0, 0.152870, 262,
       &Sources[4978] ,
       &Weights[4978] ,
      },
    { /* unit 253 (hid121) */
      0.0, -0.587940, 262,
       &Sources[5240] ,
       &Weights[5240] ,
      },
    { /* unit 254 (hid122) */
      0.0, 0.383280, 262,
       &Sources[5502] ,
       &Weights[5502] ,
      },
    { /* unit 255 (hid123) */
      0.0, 1.442550, 262,
       &Sources[5764] ,
       &Weights[5764] ,
      },
    { /* unit 256 (hid124) */
      0.0, 0.081020, 262,
       &Sources[6026] ,
       &Weights[6026] ,
      },
    { /* unit 257 (hid125) */
      0.0, -1.163930, 262,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 258 (hid126) */
      0.0, 0.462140, 262,
       &Sources[6550] ,
       &Weights[6550] ,
      },
    { /* unit 259 (hid127) */
      0.0, 0.640260, 262,
       &Sources[6812] ,
       &Weights[6812] ,
      },
    { /* unit 260 (hid128) */
      0.0, 0.072460, 262,
       &Sources[7074] ,
       &Weights[7074] ,
      },
    { /* unit 261 (hid129) */
      0.0, -0.093790, 262,
       &Sources[7336] ,
       &Weights[7336] ,
      },
    { /* unit 262 (hid130) */
      0.0, -0.731760, 262,
       &Sources[7598] ,
       &Weights[7598] ,
      },
    { /* unit 263 (hid21) */
      0.0, -0.663050, 60,
       &Sources[7860] ,
       &Weights[7860] ,
      },
    { /* unit 264 (hid22) */
      0.0, -0.812690, 60,
       &Sources[7920] ,
       &Weights[7920] ,
      },
    { /* unit 265 (hid23) */
      0.0, -0.622590, 60,
       &Sources[7980] ,
       &Weights[7980] ,
      },
    { /* unit 266 (hid24) */
      0.0, 0.538000, 60,
       &Sources[8040] ,
       &Weights[8040] ,
      },
    { /* unit 267 (hid25) */
      0.0, 0.565570, 60,
       &Sources[8100] ,
       &Weights[8100] ,
      },
    { /* unit 268 (hid26) */
      0.0, 0.161340, 60,
       &Sources[8160] ,
       &Weights[8160] ,
      },
    { /* unit 269 (hid27) */
      0.0, 0.781670, 60,
       &Sources[8220] ,
       &Weights[8220] ,
      },
    { /* unit 270 (hid28) */
      0.0, -0.178770, 60,
       &Sources[8280] ,
       &Weights[8280] ,
      },
    { /* unit 271 (hid29) */
      0.0, 0.005170, 60,
       &Sources[8340] ,
       &Weights[8340] ,
      },
    { /* unit 272 (hid210) */
      0.0, 0.924500, 60,
       &Sources[8400] ,
       &Weights[8400] ,
      },
    { /* unit 273 (hid211) */
      0.0, -0.456580, 60,
       &Sources[8460] ,
       &Weights[8460] ,
      },
    { /* unit 274 (hid212) */
      0.0, -2.094820, 60,
       &Sources[8520] ,
       &Weights[8520] ,
      },
    { /* unit 275 (hid213) */
      0.0, 0.706810, 60,
       &Sources[8580] ,
       &Weights[8580] ,
      },
    { /* unit 276 (hid214) */
      0.0, -0.846890, 60,
       &Sources[8640] ,
       &Weights[8640] ,
      },
    { /* unit 277 (hid215) */
      0.0, 33.351200, 60,
       &Sources[8700] ,
       &Weights[8700] ,
      },
    { /* unit 278 (hid216) */
      0.0, 0.533080, 60,
       &Sources[8760] ,
       &Weights[8760] ,
      },
    { /* unit 279 (hid217) */
      0.0, -0.229800, 60,
       &Sources[8820] ,
       &Weights[8820] ,
      },
    { /* unit 280 (hid218) */
      0.0, 0.075370, 60,
       &Sources[8880] ,
       &Weights[8880] ,
      },
    { /* unit 281 (hid219) */
      0.0, -0.860690, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 282 (hid220) */
      0.0, -0.318480, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 283 (hid221) */
      0.0, 0.335930, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 284 (hid222) */
      0.0, 0.283770, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 285 (hid223) */
      0.0, 1.174900, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 286 (hid224) */
      0.0, 0.644720, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 287 (hid225) */
      0.0, 0.544470, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 288 (hid226) */
      0.0, 1.027820, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 289 (hid227) */
      0.0, -0.476010, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 290 (hid228) */
      0.0, 0.603240, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 291 (hid229) */
      0.0, -0.805340, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 292 (hid230) */
      0.0, 0.868940, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 293 (out1) */
      0.0, 0.094730, 30,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 294 (out2) */
      0.0, 0.813110, 30,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 295 (out3) */
      0.0, 0.085960, 30,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 296 (out4) */
      0.0, 0.426690, 30,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 297 (out5) */
      0.0, -0.387540, 30,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 298 (out6) */
      0.0, 0.087960, 30,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 299 (out7) */
      0.0, -0.693190, 30,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 300 (out8) */
      0.0, 0.878640, 30,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 301 (out9) */
      0.0, 0.826050, 30,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 302 (con11) */
0.09332, 0.500000, 2,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 303 (con12) */
1.42850, 0.500000, 2,
       &Sources[9932] ,
       &Weights[9932] ,
      },
    { /* unit 304 (con13) */
1.41943, 0.500000, 2,
       &Sources[9934] ,
       &Weights[9934] ,
      },
    { /* unit 305 (con14) */
0.00000, 0.500000, 2,
       &Sources[9936] ,
       &Weights[9936] ,
      },
    { /* unit 306 (con15) */
0.13595, 0.500000, 2,
       &Sources[9938] ,
       &Weights[9938] ,
      },
    { /* unit 307 (con16) */
0.00176, 0.500000, 2,
       &Sources[9940] ,
       &Weights[9940] ,
      },
    { /* unit 308 (con17) */
1.42545, 0.500000, 2,
       &Sources[9942] ,
       &Weights[9942] ,
      },
    { /* unit 309 (con18) */
0.00996, 0.500000, 2,
       &Sources[9944] ,
       &Weights[9944] ,
      },
    { /* unit 310 (con19) */
0.00001, 0.500000, 2,
       &Sources[9946] ,
       &Weights[9946] ,
      },
    { /* unit 311 (con110) */
0.29627, 0.500000, 2,
       &Sources[9948] ,
       &Weights[9948] ,
      },
    { /* unit 312 (con111) */
0.00022, 0.500000, 2,
       &Sources[9950] ,
       &Weights[9950] ,
      },
    { /* unit 313 (con112) */
1.41802, 0.500000, 2,
       &Sources[9952] ,
       &Weights[9952] ,
      },
    { /* unit 314 (con113) */
1.09268, 0.500000, 2,
       &Sources[9954] ,
       &Weights[9954] ,
      },
    { /* unit 315 (con114) */
0.00252, 0.500000, 2,
       &Sources[9956] ,
       &Weights[9956] ,
      },
    { /* unit 316 (con115) */
1.33819, 0.500000, 2,
       &Sources[9958] ,
       &Weights[9958] ,
      },
    { /* unit 317 (con116) */
1.42047, 0.500000, 2,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 318 (con117) */
1.06362, 0.500000, 2,
       &Sources[9962] ,
       &Weights[9962] ,
      },
    { /* unit 319 (con118) */
0.00009, 0.500000, 2,
       &Sources[9964] ,
       &Weights[9964] ,
      },
    { /* unit 320 (con119) */
0.02952, 0.500000, 2,
       &Sources[9966] ,
       &Weights[9966] ,
      },
    { /* unit 321 (con120) */
0.00003, 0.500000, 2,
       &Sources[9968] ,
       &Weights[9968] ,
      },
    { /* unit 322 (con121) */
0.09000, 0.500000, 2,
       &Sources[9970] ,
       &Weights[9970] ,
      },
    { /* unit 323 (con122) */
0.00104, 0.500000, 2,
       &Sources[9972] ,
       &Weights[9972] ,
      },
    { /* unit 324 (con123) */
1.41001, 0.500000, 2,
       &Sources[9974] ,
       &Weights[9974] ,
      },
    { /* unit 325 (con124) */
1.42829, 0.500000, 2,
       &Sources[9976] ,
       &Weights[9976] ,
      },
    { /* unit 326 (con125) */
0.00075, 0.500000, 2,
       &Sources[9978] ,
       &Weights[9978] ,
      },
    { /* unit 327 (con126) */
1.42505, 0.500000, 2,
       &Sources[9980] ,
       &Weights[9980] ,
      },
    { /* unit 328 (con127) */
0.09000, 0.500000, 2,
       &Sources[9982] ,
       &Weights[9982] ,
      },
    { /* unit 329 (con128) */
1.42742, 0.500000, 2,
       &Sources[9984] ,
       &Weights[9984] ,
      },
    { /* unit 330 (con129) */
0.00000, 0.500000, 2,
       &Sources[9986] ,
       &Weights[9986] ,
      },
    { /* unit 331 (con130) */
0.00023, 0.500000, 2,
       &Sources[9988] ,
       &Weights[9988] ,
      },
    { /* unit 332 (con21) */
1.15535, 0.500000, 2,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 333 (con22) */
0.00005, 0.500000, 2,
       &Sources[9992] ,
       &Weights[9992] ,
      },
    { /* unit 334 (con23) */
0.01027, 0.500000, 2,
       &Sources[9994] ,
       &Weights[9994] ,
      },
    { /* unit 335 (con24) */
1.42708, 0.500000, 2,
       &Sources[9996] ,
       &Weights[9996] ,
      },
    { /* unit 336 (con25) */
0.00052, 0.500000, 2,
       &Sources[9998] ,
       &Weights[9998] ,
      },
    { /* unit 337 (con26) */
1.13171, 0.500000, 2,
       &Sources[10000] ,
       &Weights[10000] ,
      },
    { /* unit 338 (con27) */
0.71766, 0.500000, 2,
       &Sources[10002] ,
       &Weights[10002] ,
      },
    { /* unit 339 (con28) */
0.00360, 0.500000, 2,
       &Sources[10004] ,
       &Weights[10004] ,
      },
    { /* unit 340 (con29) */
0.00000, 0.500000, 2,
       &Sources[10006] ,
       &Weights[10006] ,
      },
    { /* unit 341 (con210) */
0.78148, 0.500000, 2,
       &Sources[10008] ,
       &Weights[10008] ,
      },
    { /* unit 342 (con211) */
0.03074, 0.500000, 2,
       &Sources[10010] ,
       &Weights[10010] ,
      },
    { /* unit 343 (con212) */
0.00000, 0.500000, 2,
       &Sources[10012] ,
       &Weights[10012] ,
      },
    { /* unit 344 (con213) */
1.39675, 0.500000, 2,
       &Sources[10014] ,
       &Weights[10014] ,
      },
    { /* unit 345 (con214) */
0.00000, 0.500000, 2,
       &Sources[10016] ,
       &Weights[10016] ,
      },
    { /* unit 346 (con215) */
1.42857, 0.500000, 2,
       &Sources[10018] ,
       &Weights[10018] ,
      },
    { /* unit 347 (con216) */
0.30241, 0.500000, 2,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 348 (con217) */
1.38563, 0.500000, 2,
       &Sources[10022] ,
       &Weights[10022] ,
      },
    { /* unit 349 (con218) */
0.00241, 0.500000, 2,
       &Sources[10024] ,
       &Weights[10024] ,
      },
    { /* unit 350 (con219) */
0.00764, 0.500000, 2,
       &Sources[10026] ,
       &Weights[10026] ,
      },
    { /* unit 351 (con220) */
1.29505, 0.500000, 2,
       &Sources[10028] ,
       &Weights[10028] ,
      },
    { /* unit 352 (con221) */
1.39754, 0.500000, 2,
       &Sources[10030] ,
       &Weights[10030] ,
      },
    { /* unit 353 (con222) */
1.40081, 0.500000, 2,
       &Sources[10032] ,
       &Weights[10032] ,
      },
    { /* unit 354 (con223) */
1.41482, 0.500000, 2,
       &Sources[10034] ,
       &Weights[10034] ,
      },
    { /* unit 355 (con224) */
0.02053, 0.500000, 2,
       &Sources[10036] ,
       &Weights[10036] ,
      },
    { /* unit 356 (con225) */
0.00255, 0.500000, 2,
       &Sources[10038] ,
       &Weights[10038] ,
      },
    { /* unit 357 (con226) */
0.07531, 0.500000, 2,
       &Sources[10040] ,
       &Weights[10040] ,
      },
    { /* unit 358 (con227) */
0.00000, 0.500000, 2,
       &Sources[10042] ,
       &Weights[10042] ,
      },
    { /* unit 359 (con228) */
0.00181, 0.500000, 2,
       &Sources[10044] ,
       &Weights[10044] ,
      },
    { /* unit 360 (con229) */
0.00002, 0.500000, 2,
       &Sources[10046] ,
       &Weights[10046] ,
      },
    { /* unit 361 (con230) */
0.43175, 0.500000, 2,
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
