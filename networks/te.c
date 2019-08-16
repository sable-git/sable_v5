/*********************************************************
  test_new.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:07:27 2004
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
-0.898320, 1.538990, 0.180550, 0.692020, -0.312350, 0.111720, 0.630800, 0.003260, -0.884730, -0.837490,
0.683750, -0.874420, -1.509800, 0.323590, 2.052640, -0.233820, -2.302170, 0.154550, 0.402150, 1.920850,
-2.550190, 2.163840, 0.922860, 1.630300, 0.883660, 1.316860, 0.306670, 0.849870, 1.259840, -1.015400,
-1.890430, 0.170360, -0.508420, -3.253400, 1.232840, 0.537730, 0.149450, 0.130640, -0.084900, -0.022920,
-0.871940, 0.490870, 1.098300, 1.210700, -0.204820, -1.629490, 0.364100, 1.216160, -0.578630, -0.561720,
-1.257810, 0.689260, 2.289810, -1.248060, -2.625770, -1.715820, -1.540800, -1.372250, 0.097060, -0.673680,
-0.958610, 0.416280, 0.431580, -0.542940, -1.130390, -0.604480, 0.267100, 0.153550, 0.978610, -0.188200,
1.599330, -0.488730, -0.875450, 0.438570, 0.778100, -1.463640, -1.354270, 0.914550, -0.609780, -1.309220,
-2.530300, 0.086770, -0.229420, -0.320140, 0.079610, 1.266430, 1.041320, -2.464880, 0.115640, 0.613620,
-1.161390, 6.517400, 0.063070, -1.335340, 1.461260, -2.346240, -0.521580, -1.075880, -1.540970, 0.688620,
-0.998220, -0.355030, 2.625470, -1.427180, -1.150480, 1.312750, -0.030870, 2.686800, -0.900310, 1.260200,
0.005530, 1.752320, -0.732490, -0.126970, 0.348440, -2.352320, -1.422720, -1.698990, 0.007840, -0.428880,
-0.150680, -0.652490, 0.954180, 1.123570, -0.368370, -0.474580, -0.414230, 0.860860, -1.551500, -0.513840,
0.832000, 0.897910, -0.642310, 3.562590, -1.751850, 0.562030, -0.235960, -1.683110, 2.109630, -1.075040,
-1.020850, 1.260690, 0.027540, -0.560980, 0.597970, 1.059170, 0.304980, 3.889480, -1.830810, 0.733240,
1.760850, 1.171870, 0.681290, 0.469310, 1.348150, 2.451190, -1.531260, -2.763000, -2.390850, -1.606990,
-0.472160, 5.133920, 2.295160, 1.500660, 1.037180, -0.746540, -1.761460, 0.538040, -0.063720, 0.409420,
-1.644430, 0.332670, -0.707550, 0.621050, -2.634540, 2.580780, -1.659130, -0.738460, -0.927170, -2.094300,
2.313470, -0.610560, 1.239650, -1.531200, 2.034150, -1.352240, 0.055680, 0.586290, -0.319930, 0.719930,
1.221160, 1.032040, -0.151040, 2.050220, 1.336620, 1.113140, 0.822410, 4.734460, 0.005390, -0.387300,
-1.499080, -0.166170, 1.120630, 2.213800, 0.624650, 1.925190, 0.892950, -0.290840, 2.342510, -0.929030,
0.633550, 1.906870, 0.559390, 0.414720, 0.450420, -0.160200, -0.840580, 1.072690, -0.694060, -1.102030,
0.495280, -0.241960, 1.420160, -1.777740, 1.607280, -0.845100, 1.550800, -0.182120, -1.177550, 1.320820,
-1.730500, 0.047310, 0.594190, -0.152280, -1.376620, -0.582200, -0.261440, -1.947630, -0.208590, -0.271570,
-0.318120, -1.376690, -0.411820, -0.568800, 0.218130, -2.851050, -0.033580, -1.226080, -0.550340, -0.568840,
-1.146480, -1.449800, -1.591520, -0.920610, -0.552310, -0.973280, -1.559690, -5.715400, -18.542330, -0.735460,
-1.812210, -3.552780,
1.415930, -1.304500, 2.096070, 0.833630, 1.336730, -0.105260, -0.352900, 1.905970, -0.798740, -0.998980,
0.460400, -0.383350, -1.504560, 0.193680, 0.609240, 0.531550, 1.144660, 0.946850, 0.094810, 0.471980,
0.881290, 1.062610, 0.053650, 0.062860, 0.644620, 0.061810, -0.956860, 0.051030, 0.483370, -1.024160,
-0.466920, -1.491960, -0.536080, 0.357220, 1.538540, 0.438950, 1.165200, -0.251790, -1.580270, 0.648050,
0.269460, 1.218610, 0.440650, -0.399830, -0.907660, -0.182890, -1.084170, 0.300920, 1.311850, 0.888520,
0.646430, 1.775260, -1.965270, 0.335670, 0.088940, -0.154660, -0.797190, -0.831230, 0.661020, 0.055000,
0.065520, 1.532650, -0.302550, 0.171360, 0.268170, 0.057820, 0.376310, -0.135470, -0.224360, -0.431610,
-0.849290, -0.954190, -0.162990, -0.480650, 0.143030, 0.415240, 1.833120, -2.209950, 1.535630, -2.188750,
-0.121440, 0.707010, 0.752910, 0.386060, -0.386000, 0.226240, 0.387460, -2.452370, -0.036380, -0.225600,
-0.129180, 3.028610, -0.630480, 2.480060, 0.724920, -0.673540, 2.193790, 3.538940, -1.738650, -1.061610,
-2.146450, 0.694910, 1.619130, -1.976070, -0.653220, 1.793210, 1.117010, 0.267020, -1.418060, 0.339800,
0.245340, 0.317160, 1.818760, -0.897760, 1.213320, 0.118970, 1.124040, -1.019420, -1.226510, -3.107410,
1.264530, 0.220690, -0.337550, -1.121170, -0.902190, 0.089060, -1.151000, 0.592780, 0.765450, -1.384380,
-0.933740, 3.091640, 0.465330, 1.275350, -1.828330, 1.508520, -0.675720, -0.673180, 1.173220, 1.617710,
-0.980330, -0.188180, -1.230800, 0.173540, 0.287650, -1.564820, -0.958910, -0.615180, -0.826770, 0.588230,
0.028170, -0.212480, -0.456770, 0.850300, -0.094460, 1.946720, -0.647210, 0.553820, -0.713250, 1.375450,
0.469600, -1.961550, 0.328500, -0.726060, 0.110040, 0.451360, 1.503940, -1.421730, -1.289230, -0.979790,
-0.839280, 1.059550, -1.059610, 0.348410, -0.033500, -0.718160, 1.370730, -0.347140, -2.030320, 1.416560,
1.510960, -0.321900, -0.358500, -0.878440, -0.232560, -0.221700, 0.356000, 1.201920, -0.303860, -0.142640,
0.744170, -0.874700, 0.483420, 0.837640, 0.162580, -4.008560, -2.228010, 1.727150, 0.474110, -0.541830,
0.352020, 1.040210, 0.090450, -0.079960, 1.108230, 0.652150, 0.494690, -0.152950, -0.874230, -1.456060,
-1.166200, -1.035800, 0.092370, 1.200820, 1.486230, 1.059010, 0.230870, -0.319200, 1.506790, -1.113380,
-0.422330, 0.843140, 1.011910, 0.565080, 0.822410, -1.353970, 1.253430, 3.471400, 1.954380, 0.595140,
0.474300, 0.121510, -0.139080, 0.473090, 0.389310, 2.087480, 0.619960, 0.632480, 1.132180, -0.009320,
0.569220, -0.709010, -0.680830, 0.730920, -0.239140, -0.792020, 0.749020, 0.451190, 2.000700, 1.218930,
-0.331220, 1.350420, 0.221360, 0.824920, 1.127020, 0.600440, 1.012470, 3.054270, 10.711030, 1.384690,
0.568750, 0.616850,
0.290640, 0.457920, 0.834560, -0.162390, -1.268800, -0.517400, 1.525610, -0.422390, -0.993610, 0.945740,
1.473360, 0.215060, 1.921450, -0.445910, -0.483250, 0.991400, -0.117310, 0.377940, 1.305390, -0.560700,
-0.408290, -0.062090, 0.199520, -0.285520, -0.376710, 0.611840, -0.225670, 0.138860, 1.159480, -1.392670,
0.837570, 1.000430, 0.251070, 2.900420, -1.048920, 0.004320, 1.968410, -0.179070, 0.008430, -0.111970,
-0.826060, -0.027160, 0.908190, -0.181700, -1.563860, 0.400840, -0.134010, -0.326530, 1.133810, -0.707600,
-0.960710, -0.036910, -0.541560, 0.328840, -1.366760, -2.379220, 4.621570, 0.050170, 0.269960, 0.099290,
-0.553450, 3.199490, -0.241920, -0.935970, -0.499880, -1.283770, 0.795760, 0.102240, -1.721370, 0.441200,
-2.145250, -2.701620, -0.511850, 1.127030, -1.138330, -1.473050, -0.325740, 4.375390, -0.075260, -1.251690,
0.523210, -3.472410, 5.517040, -1.027820, 0.975160, -1.029630, 1.107080, 5.320210, -2.479470, -1.578880,
-5.425520, -2.142620, -1.516520, 0.221530, 1.455700, -1.870290, -5.330480, -1.224390, 7.364510, 0.265720,
0.364530, 0.258880, -2.345930, 8.476400, 0.144400, 0.732990, -3.491770, -2.122700, 1.473470, -0.507160,
-2.566700, -2.887530, -1.319200, -4.331380, -3.108670, -0.826910, -2.447670, -10.219920, -1.032840, 6.824030,
-0.179440, 2.386100, -1.058270, -2.506620, 5.470210, 0.556540, 4.263180, -0.680130, 0.306630, 1.435220,
-1.327110, -0.049230, -0.240470, 0.159380, -0.395140, -1.040310, -1.663020, -0.694740, -1.529090, 0.627310,
5.807540, 0.038540, 1.205010, 0.347460, 0.202830, 0.034740, -0.046920, 1.181460, 0.609040, 1.587750,
-2.482030, 0.352120, 0.090450, -0.164130, 0.358600, -0.933980, -0.024510, -1.086580, -1.793460, -2.154440,
-1.669740, 3.275240, 0.099810, -0.169240, -1.958110, -0.180310, -0.159040, 0.844240, -0.131140, -1.258430,
0.942020, -2.286190, -0.919730, 0.770480, 0.384970, -0.122140, 1.207360, -0.951910, 0.401720, -0.848260,
-3.744870, -1.163300, 2.396160, 0.466220, -1.314640, -1.525310, -1.609860, -0.866730, 1.072970, 1.033100,
-0.101070, -0.006480, -1.253120, -0.136810, 0.216380, 1.229410, -0.420860, 0.540050, -2.449370, 0.703890,
-0.875910, 0.523910, -0.235880, -0.010640, 0.231940, -0.404620, -0.171320, 0.476730, -2.406310, 0.519300,
0.064340, 0.432620, 0.208730, -0.838090, -1.844960, -1.090350, 0.212750, 0.519990, 0.283530, -0.526340,
-2.414070, -2.974160, -1.846360, -0.829120, -0.415080, 0.279190, 0.438610, -1.241260, -0.386610, 0.098510,
3.860210, 1.991210, -0.148370, -0.354590, 1.449870, 0.280380, -0.424830, -0.519120, 2.076060, 0.112740,
-0.117190, 0.499040, -0.220600, 1.130170, 1.043790, -0.078370, -0.602670, 0.826420, 1.271680, -1.067350,
-0.419070, 0.465490, -1.310910, -0.676400, 0.231410, -0.690790, -0.187910, -2.400370, -5.744590, 0.053060,
0.224330, -0.016030,
0.937790, -0.842630, -0.537840, 0.955230, 0.665640, -0.597600, -0.598560, 0.051140, -2.286600, 1.048400,
0.494730, -0.214860, -0.057590, -0.982220, 0.057030, 0.144140, 0.124800, 0.161720, 0.754130, 1.150670,
0.468290, -1.964710, 0.152050, 0.333220, -0.412890, -1.459580, -0.805700, -0.994720, 0.800820, 0.723240,
-1.146310, -1.184180, -1.660250, -0.813380, 1.041750, -1.323430, -1.083260, -0.300500, -0.873350, 0.031890,
-2.942760, 0.760050, -0.113610, -1.091280, 0.404580, 0.832820, -2.442240, 1.438880, -1.325490, 0.080660,
-1.909740, -0.117060, -0.804860, 0.461840, -1.416230, -1.549270, -1.569780, 0.732390, 0.253240, -1.154950,
2.462440, -1.654060, 0.335030, 0.043250, -0.316760, -0.884580, -4.273800, -2.591340, 0.392980, -0.007580,
1.373490, -0.062510, 0.873520, 1.004560, -1.482110, -0.869880, 0.411720, -1.301160, -0.046660, -1.930650,
1.165480, 1.851510, -2.721510, -0.339340, -0.917170, -0.627250, 1.062520, -0.849790, 0.247780, 0.169250,
1.375170, 0.936940, 1.104840, -0.562760, -1.006830, 1.698630, 4.232770, 1.264990, 0.108300, 0.603660,
-1.483100, 0.068730, 2.031890, -0.422550, -0.022660, -0.148760, -0.553390, 0.494370, 0.717910, 0.510770,
-0.228830, 2.807550, -1.385110, 0.016480, 2.076650, -1.577000, 1.888420, -0.558950, 1.058990, -0.978520,
-1.284200, 1.658500, -1.066500, 0.022760, -1.728430, -0.491340, 0.526950, 0.554430, 0.816830, -0.192470,
-1.398380, -0.197420, -2.111990, -0.963350, 0.197080, 0.084910, -0.832800, 1.148460, 0.099780, -0.121470,
-4.037050, -0.049660, 1.070930, 0.080670, 0.424130, -2.141130, -1.255350, -1.016470, -0.899740, -0.473630,
0.146000, -2.558510, -1.343120, -1.067400, -3.272940, 0.711090, 1.241330, -0.171000, 3.466250, 3.006270,
-0.471730, -3.708620, 0.485150, -1.620890, 1.656310, 0.242170, -1.042920, -0.283080, 1.315570, -2.112650,
-0.941050, 0.998050, 0.913160, -2.038200, 1.193280, -6.276260, 0.159210, 1.382280, 0.067240, 0.618410,
0.999380, -0.362430, -2.253330, 1.363490, -3.080010, 0.491750, 0.511190, 1.864110, -1.569220, 0.293250,
0.263090, -2.148800, 0.320490, 0.127000, -0.347640, -1.048490, -8.233330, 2.285280, -0.709960, 0.327030,
2.566970, 3.851090, -0.771650, -3.906070, 0.862240, -0.868750, -0.714120, -0.074970, -4.495660, -0.888950,
-0.884360, -0.394580, -0.069340, 0.092360, -0.535480, 0.947750, -2.437700, -1.120240, -1.649320, 1.636310,
0.367210, 3.634800, 4.494450, -0.555590, -2.012070, 3.681410, -2.157610, -0.974740, 2.074050, -1.773020,
-1.181290, -0.561020, -0.495760, -0.341690, 0.002360, -0.116280, -1.088370, -1.125170, -0.716330, -0.080420,
-0.018930, -0.181730, -1.649630, -0.706520, -0.224800, -0.176510, 0.431340, -1.631970, -0.437520, -0.402200,
-0.979170, -0.187910, -0.429770, -1.283390, -3.271230, 0.059040, -0.706580, 0.854560, -0.263850, -0.584420,
-0.242680, 0.203890,
0.018380, 0.404880, -0.170610, -1.012000, -0.631500, -1.611190, -0.411880, -0.488270, -1.012850, 0.207300,
-0.066850, 0.802740, 0.683700, 0.987860, -0.051600, -0.672180, -0.988200, -1.052990, -1.671840, -1.102980,
-0.310810, 0.039840, -1.715180, -0.116020, -0.777070, 0.646530, 0.668630, -0.347150, -1.190090, 1.192300,
0.544130, -0.020550, 0.935160, -0.705650, -0.051360, 0.526610, -0.433100, 0.147830, 1.147400, 0.079190,
-2.029560, -0.122320, 1.074240, -0.974790, -0.528720, 0.774160, -1.159850, 0.415550, -1.747050, -2.464960,
-1.319290, 0.728800, -0.346560, 0.825600, -0.678500, -0.614060, -1.636020, 0.829540, -0.185450, 1.128290,
0.356420, -0.986100, -1.150340, 0.616990, -0.944880, 1.450770, 3.939260, 0.974810, -0.134800, 1.898880,
-2.407260, 1.289960, -0.952800, -0.816310, -1.259540, 0.729730, 0.203800, 0.403980, 0.041530, 0.925770,
0.313540, -1.256590, 1.293620, 0.606390, 1.157040, 0.372100, -1.236210, -0.555950, 0.344270, -0.458390,
0.173310, -3.383730, -1.686710, -0.481320, 1.135220, 0.113970, 2.801750, 0.332940, -0.130740, 0.494550,
-0.441600, -1.407280, 0.432810, -0.072250, 0.320980, 1.720220, -1.730560, 1.095790, 0.204900, 1.534460,
-0.952150, 1.622550, -5.471610, 1.814470, -1.584480, -2.388510, -0.584620, -0.869350, -0.281960, 0.159150,
0.232710, 0.281830, 0.677780, -0.300440, 2.005380, -0.792280, -0.260830, 0.275260, -1.863690, -0.013810,
-3.690870, 0.792910, -2.240050, -2.613800, -1.256160, 1.404280, -0.432500, 0.752850, 1.430280, -0.322490,
-1.704950, 1.043540, -0.038470, -0.563980, -0.346660, 0.821960, -0.315820, 0.346550, 1.903050, 1.125520,
-0.110210, 1.660420, 0.043780, 0.862240, -0.783960, 0.265210, 2.262500, -0.452960, -1.835660, -0.128800,
0.422770, 0.026290, 0.222260, 0.386980, 0.791100, 0.933940, -1.384290, 1.030930, -0.374190, 1.144700,
-0.378320, -0.748640, 0.493990, 0.449110, -1.761420, 1.153100, -0.008140, -0.459240, 0.237880, 1.094790,
0.506940, 1.161570, 1.991850, 0.286610, 1.644190, 0.232850, -0.149910, -1.694660, 0.485190, -0.629220,
1.118740, 1.228740, 0.811730, -0.978530, 0.040660, 1.237000, 0.025970, 2.124680, 0.114020, 0.106730,
1.693970, 1.473240, -2.488000, -2.207110, 0.275720, 1.692580, 0.791150, 0.900090, -1.922690, 4.348440,
-0.890100, 0.426980, -0.465930, -0.174570, 0.325040, 0.235800, -1.854850, -3.857430, 0.862180, 0.568290,
0.464820, 2.016080, 2.189480, -0.152010, -1.639570, 0.027270, -0.805440, -0.351900, 0.309140, -1.376930,
-1.606940, -0.703280, -3.180430, 0.642840, 1.061440, -0.524710, 1.705100, 0.499940, 1.213900, 0.699530,
0.496560, 1.365960, 0.822280, 0.473960, 1.083980, 2.440300, 1.287080, 0.315780, 1.942910, 0.288330,
1.471930, 1.797930, 1.515840, 0.713840, -14.765650, 1.734100, -0.525840, 4.146780, 6.234280, 0.466950,
2.185180, 14.684350,
-0.691050, 1.369070, -0.500370, 0.604920, 0.402020, 0.187710, -0.474230, -0.120170, 1.118330, 1.092020,
-0.145200, -2.400420, -2.258050, -0.611920, 0.793830, 1.025380, -0.743960, 0.907640, 0.114460, -0.200230,
-0.021810, 0.323190, 0.541430, -2.117130, -1.580070, -1.670040, -0.775310, -0.147880, -0.324560, -1.314910,
0.154720, -1.367860, -0.258680, 1.831400, -2.378280, -0.942610, -0.059700, -1.249650, -0.302170, 0.302580,
-1.098710, 1.319250, -0.013630, -0.313800, -2.253180, 0.199980, -1.189740, 1.272350, -0.326070, -0.397150,
0.282820, -0.333190, 0.173310, -0.420230, -0.114860, -0.899530, 0.450000, 0.382750, 0.498910, 1.871450,
-0.147560, -0.650060, 1.268210, 1.085200, 1.461960, -0.598410, -0.091800, 0.120510, -0.273790, -0.506560,
-1.447320, 3.082740, 0.158120, -0.553240, -0.414350, 0.472950, -1.768370, -0.694070, 0.976820, 1.577180,
1.231590, -0.630890, 0.641930, 0.588400, 2.112350, 0.774620, 2.069970, 1.332790, 2.184430, -2.418540,
-1.735320, -1.596920, 0.818000, -1.378270, 1.205700, -0.134070, -0.669270, 0.596270, -0.152030, -0.411920,
2.409780, 0.403690, -1.478380, -0.794290, 0.204900, 1.661370, -0.524680, -0.242850, -0.126620, -0.630220,
-0.707780, -0.543950, -3.281670, -1.049850, -1.057200, 0.395490, 2.541260, 0.200360, -0.119030, 4.488960,
-0.938060, 0.583550, -3.357890, -1.519180, 1.417100, -0.602460, 0.239050, 0.215520, -1.301820, 1.811990,
-0.282770, -3.221810, -1.736800, -6.932690, -0.067070, 1.541760, -2.911560, 1.694900, -2.047290, -1.854180,
7.589810, -0.362560, 0.669220, 0.585770, -5.852690, 4.375250, -1.167080, 1.631060, -2.896980, -1.412210,
3.375800, 0.295860, -0.434530, 1.257160, -3.275720, 1.349350, -2.832470, -3.239120, -1.923550, 1.568330,
-0.203890, 11.300550, 2.318400, 3.584610, 0.786660, -1.096380, 3.225630, 0.503820, -0.960890, -0.342520,
-0.022480, -1.511760, -1.088140, -0.658930, 0.776930, -3.457130, -0.882490, -0.744180, -1.804110, 0.260500,
-1.356030, 0.481020, 0.735220, -0.002750, -0.099660, -0.333310, 1.036430, -1.387650, 0.611500, -1.403130,
0.841310, 0.681840, -1.345430, 0.025950, 0.889720, 0.457640, 1.094120, 1.052550, 0.100510, 0.145260,
-0.794840, 0.192800, 1.276090, 4.566220, 0.140650, -2.277580, 0.497980, 0.737790, -0.764960, 0.016630,
0.729180, -0.321460, -0.651850, 0.929850, 1.130840, -2.507610, 0.580990, 0.715080, -1.056160, 0.762590,
-1.079360, 1.039420, -0.157900, 0.332800, 0.500420, -0.194330, -0.452940, 0.855690, 0.604680, -1.122510,
0.206450, -0.791130, -0.432980, -0.097060, -0.442810, 1.364510, -0.364350, 1.741320, 0.796040, 0.003040,
0.355790, 0.267690, 0.053910, 1.315200, -0.219370, 1.428840, -0.020840, -0.637560, 0.737200, -0.602940,
1.353120, 0.615140, -0.129850, 0.716220, -1.978490, -0.703140, -0.748600, 1.184730, -0.456500, -0.464630,
2.065400, 0.618630,
0.402020, -0.164630, -0.868800, -0.416700, 0.453780, -1.234590, -0.357590, 0.344440, -0.612650, -0.593380,
1.165180, -0.565160, -0.944360, -0.670540, -0.151490, -0.531100, -0.308190, -1.169620, 0.143620, 0.941380,
0.472750, -1.699370, -0.231570, 0.534240, 0.307680, 1.085290, -0.079260, -0.378080, 1.065470, 0.199200,
1.007770, 0.343670, -0.256710, 0.717880, 1.659520, 1.542370, 0.321420, 0.171020, -0.354070, 0.992640,
1.206690, 0.604910, -0.595840, -0.051790, 1.017740, -0.649780, 0.605860, 0.256070, -1.986140, -0.708440,
-1.886970, -0.223950, -0.369790, -1.774620, -0.472210, 0.323360, -0.152690, -0.050490, -0.479270, 0.484830,
-0.429980, 0.878530, 1.483770, 0.722880, -0.378590, -0.491700, -0.609210, -0.674900, 1.022440, 0.510140,
0.279180, -0.258740, 2.076320, 0.169600, -0.007340, -2.950450, 1.300700, -1.736070, -1.370950, -0.470130,
0.472630, 0.951770, 0.363740, -0.725670, 1.451770, 0.982050, 4.477910, 1.314350, -1.138920, -0.518390,
-0.411660, 1.051220, -1.574900, -0.166580, -0.231640, -0.791440, -1.588570, -0.265260, 0.355000, -0.890690,
0.181330, -0.862080, 0.912190, -1.310740, 0.085680, -0.007220, -0.481690, 0.872110, -1.651440, -4.086280,
0.531650, 0.648480, -2.437070, -0.969280, -0.052340, -0.454370, -0.117290, -2.858780, 0.543600, 8.004160,
1.402620, -0.686420, 1.023250, 1.973800, -0.774030, 0.017680, -0.149970, -0.151020, -0.706170, 0.214310,
0.706200, 0.781520, 1.821150, -0.262490, 1.471610, -0.611610, -2.039920, 0.140810, 2.126850, 0.953980,
2.455730, 0.937210, 1.656170, 0.607450, -0.331420, -1.530920, -0.594180, 0.912610, 0.018060, -1.568300,
1.852150, -1.708900, -0.168720, 5.382950, -0.031420, 2.608540, -1.696510, -1.519700, -0.425410, 1.206650,
-1.658730, -1.206740, -0.195850, 1.077420, 0.445270, 0.608240, -4.222520, -1.510900, 0.155650, 1.052550,
-0.883110, -0.669830, -0.528690, 0.570100, 0.576860, 0.351650, 1.530750, 0.822010, 0.456430, 0.449740,
1.253650, -0.309580, -5.134430, -0.171530, 1.093130, 0.194620, -2.210350, -1.472800, -3.145110, -1.881270,
2.419850, -0.677040, 1.508390, -1.217710, -0.249690, -0.782520, -0.564190, -0.401160, 0.934360, -0.534670,
0.474950, 2.392550, -0.276120, -0.288870, 0.736740, 0.260780, 1.948840, -0.557270, -4.203510, -0.914810,
-0.680080, -2.047730, 0.032510, 1.060630, 1.704990, 0.808750, -0.443010, -0.452190, 0.634550, -0.065060,
-0.533910, 1.152960, 1.434780, -1.301780, -0.452580, -0.269640, -0.668380, 2.185840, -1.495370, -2.934990,
0.958670, 0.361960, -1.752760, -1.465000, 1.514780, -2.092360, -1.591270, -0.895650, -2.550520, -1.118950,
-2.023510, -1.213680, -0.750310, -2.123950, 2.305450, 0.638220, -1.009270, -3.742330, -0.937450, -2.110000,
-1.844900, -1.441330, -2.237090, -0.823470, -1.678570, -2.506740, -2.112410, -1.434270, -0.235060, -1.506450,
1.112510, -3.112160,
0.690220, -0.105430, -2.393340, -0.635020, -0.526210, 0.759090, -1.273660, 0.353370, 1.353530, -0.974200,
0.136890, -0.064710, 2.875970, -0.474020, -1.282590, -0.873460, 0.024030, 2.336280, 0.803390, 0.155870,
-1.352600, 0.925760, -0.080330, -2.071990, 1.222430, 0.193800, -0.516940, 2.407520, -0.379290, 0.848490,
0.476150, -1.193290, 0.327470, 1.768620, 1.137660, 1.684140, -0.461310, -0.624460, 0.271120, 0.401190,
-1.374400, 0.606730, 0.229510, -1.128510, -0.334520, 1.716990, 0.721340, -0.229370, 1.816510, -5.990430,
-1.709860, 0.635680, -0.397500, 0.995840, -0.533070, -0.080000, 1.657810, 1.652080, 1.367620, 0.890790,
0.084610, 0.299910, -0.758410, 1.318680, -0.928300, 0.829770, 2.443580, 0.546530, -0.346550, 1.616730,
-7.948610, -2.707120, -0.727310, 0.032640, -1.002860, 0.466300, -0.728690, 0.115780, -0.662450, 2.207000,
0.240420, 0.709430, 1.785940, 0.385900, 0.377190, -2.524380, -0.618900, 1.350470, 0.724140, -2.446600,
0.840130, -4.985620, 0.919410, 0.536400, -1.017820, 0.577520, -1.048380, -2.484690, -0.286670, 1.085990,
1.426240, -0.430270, -3.041460, 0.653500, 0.384590, 1.558300, 0.860660, 1.025520, 1.057600, 0.095660,
-1.102010, 0.233340, -3.923340, 1.001340, -0.350290, -0.977860, 1.578170, -2.502250, -1.148320, 0.707050,
0.669760, 0.825140, 0.330120, -1.861480, 2.167560, -0.364760, 0.683070, 0.185320, 1.027100, 1.216580,
1.048760, 0.529930, 1.801880, 2.052920, -0.582690, -1.673770, 0.172450, -0.497390, -1.282260, -2.907640,
-0.125470, 1.137000, -0.048190, 1.265930, 0.774830, 1.666850, -0.056470, -0.776480, -0.321630, 0.817800,
0.323220, -0.516600, -1.499030, -0.420630, -1.186740, 0.412690, 1.242520, -2.137450, -0.208180, -0.973360,
-0.258870, 2.536160, -0.768050, -1.889870, 0.062930, -0.115710, 1.030440, 0.605920, 1.326990, 0.702050,
-0.903390, 0.537320, -1.179210, -1.249150, 0.647520, 0.985170, -0.119140, -0.186780, -0.588660, -1.611000,
-0.908240, 0.303710, 3.018900, 1.182840, 0.863510, 2.176280, -0.925410, -0.380730, 1.747180, 1.545010,
1.381530, 2.334130, -0.893270, 1.615050, 1.159910, 1.552380, -1.074070, -0.259530, -0.167340, -0.445220,
-0.457960, -1.207530, -0.900260, 2.105250, 0.784670, -0.082830, 0.063900, 0.708870, -2.047570, 0.263090,
-0.478110, 0.974600, -1.666480, 1.082630, -0.467480, -1.821390, 0.511660, -0.477710, -0.942840, -0.264900,
-0.574820, -0.534990, 1.466050, -0.760400, -0.365800, -2.929160, -1.500640, -0.906960, -1.129910, -3.661680,
1.846570, -1.927700, -0.489050, 1.082390, 0.576800, -0.228330, 0.141380, 1.718290, -0.172580, -0.224630,
0.949120, 0.651300, -0.406770, 0.984440, 2.167470, 1.221960, 0.919250, 0.083760, 0.839390, 0.666970,
1.746410, 1.098930, 0.886060, 1.427970, -3.471260, 0.721860, 1.153960, 1.632750, -3.588980, 0.109960,
0.772400, 2.510390,
-0.644420, 0.116740, -0.967610, 0.558700, -2.173840, 0.981630, -0.614310, -0.528830, 1.151720, 0.394970,
-0.047680, 0.522010, 0.801190, 1.346830, -0.879920, -1.050300, -0.497360, -0.279480, 0.942970, -0.160330,
0.632080, 0.202400, 0.485330, -1.232440, 0.737930, 0.134230, 0.565400, 1.247800, 0.147910, 0.513810,
-0.207430, -0.160590, 1.105030, 1.488820, 1.095700, -1.217350, 0.720220, 0.542810, 2.605490, 0.314540,
-1.271610, -0.988170, 0.285230, 0.492370, -2.917290, 0.235560, 0.789530, -0.728130, -0.423830, -0.210950,
2.399530, 3.190710, -0.479210, 0.405300, 2.086370, 0.571680, -0.464930, 0.766680, 0.379890, -0.572800,
0.364890, -0.131180, -2.556160, 0.800400, 2.045030, 0.124520, 2.125240, 0.529120, 1.346110, 0.467290,
-1.026600, 1.075200, 0.200860, -0.709620, 2.264140, 1.313250, 0.083270, 1.276960, 0.233680, 2.416720,
-1.158420, -1.323000, 0.919040, -0.405730, 1.351480, -1.050070, -1.866430, 0.087960, 3.227460, -0.290080,
1.314810, -5.243930, -1.524130, 0.662560, -0.666970, 0.470240, 0.083770, 0.608220, 0.482080, 1.006090,
4.105880, 2.040490, -1.083350, -0.798880, -0.359230, 0.476610, -1.643750, -0.751180, 0.590950, 1.894840,
-0.505560, 1.798360, -2.513180, 0.930670, 0.116390, -0.346900, -0.262360, -1.183380, 0.380190, -0.795200,
-0.117030, 2.554150, 2.360480, -0.433000, 4.304890, -0.943870, -1.759690, 0.447200, -1.320950, -0.135270,
1.376910, 0.514820, 1.544160, 0.494840, -0.263600, 0.936350, 1.753810, 1.290890, 1.100800, -0.139750,
-1.234650, 2.653720, -2.057350, 0.487300, 1.785110, -1.037470, -0.918380, 2.450370, 0.154060, 0.084290,
0.277740, -0.761040, 0.567300, 1.687240, 0.365160, -2.140150, 1.199850, -0.288590, 2.568890, 1.470340,
0.426720, -6.299180, 2.074270, -1.825620, 0.343820, 1.080560, -1.601150, -0.141010, -2.402940, 0.477670,
-3.102120, -0.868270, -3.202780, 0.185030, -3.887950, 0.882590, -0.445680, 0.462000, 1.310130, 1.916910,
0.564100, -2.603700, -4.117920, -3.206320, -8.961830, -0.033700, 1.251900, -2.802270, -0.394230, -0.771740,
0.122500, -1.177520, 0.315430, -0.310340, 2.524340, -0.836820, 0.730580, -0.269710, 0.023140, 1.596910,
1.774920, 0.344810, -0.637310, -7.125530, 0.269240, -2.728990, -2.679000, 1.759980, -0.652390, 2.382680,
-0.808170, 0.078460, -2.060250, -0.486090, -1.153390, 0.413140, -0.943900, 0.618570, -1.774340, 0.570830,
0.305660, 1.389000, 1.300740, -0.038070, -1.278190, -0.110360, -0.551030, 0.102880, 1.836320, -1.439760,
3.105110, -0.654880, 0.963180, 0.578990, -0.153560, 3.781770, -0.071350, -0.106550, 2.651430, -0.034340,
0.382760, 0.554160, 1.069150, 0.793460, 1.274430, 1.043260, 1.519550, 0.365860, 3.765080, 1.877340,
1.349470, 1.133030, 1.587680, 1.351130, 0.589150, 1.426710, 0.591800, 13.282310, 5.571150, 0.366890,
0.779560, 8.828470,
-0.154920, -0.346210, -0.624420, -2.131470, 1.031060, 0.274470, -1.781270, 1.190090, 3.445320, -0.174330,
-4.654510, -1.422280, -0.464030, -1.073960, 0.484440, -0.004200, -0.116550, -0.044910, -0.782070, -0.705550,
0.356010, -0.027700, 0.090900, -0.031440, 0.730230, 0.037430, -1.372040, -0.748700, -0.988750, 1.741910,
-0.564890, -0.662070, 0.317840, 1.424300, 0.161770, 1.610450, -1.388030, 0.375240, 0.347150, 0.261490,
-0.140570, -0.599560, 1.673740, -0.995640, 0.331080, 0.479500, 3.849040, 0.241400, 2.881750, 0.223420,
0.275890, 0.843380, -0.329560, -1.455980, -1.054730, 0.456830, 1.325780, 3.785560, -0.041060, -0.021310,
-1.881060, -0.475100, -1.162270, -1.020890, 1.001420, -2.258960, 0.931820, 0.082970, -0.498670, -1.112750,
-0.440750, -0.643190, -0.303750, 0.621290, 0.329910, -2.090920, -1.493690, 1.799160, -0.190400, 0.143870,
-1.852150, -1.010800, 2.858220, 0.230770, -0.384860, 0.611350, 0.180330, 1.296360, 1.521080, -0.911620,
-9.188670, -1.444930, -1.601780, 2.219020, 0.496720, -2.182980, -3.179410, -2.592180, -0.053810, -2.485870,
0.221200, -0.857260, -3.481680, 3.838330, -0.253100, -0.522070, -1.203290, 0.457720, -0.423930, 0.659420,
-0.319320, -2.262590, -0.415780, -1.267920, 0.048670, 1.057040, -1.079010, -7.310040, -0.492640, 2.976180,
-0.636430, 2.386200, -0.300490, -0.706420, 13.766380, 0.301280, 0.230370, -0.052380, 1.146850, -0.930480,
-1.176970, -0.061180, -5.244340, 0.098200, -5.294450, -0.968950, 0.203090, -1.031580, -0.659140, -0.151010,
7.034750, 0.133000, -1.367280, -1.070580, -0.074100, 0.331970, 0.147950, 0.100620, -1.112050, 1.284610,
-3.462820, -1.328450, -0.704530, -0.296900, 4.099240, 1.533910, -1.672610, 0.181910, -1.775400, -2.803830,
0.483530, 4.797070, 1.371280, 0.442600, -0.060000, -4.583260, 0.983650, 0.839800, -0.070230, -1.502020,
0.930020, -2.224110, -0.940870, 1.519320, -0.445030, 2.043480, 0.505690, -1.236410, -0.301430, -1.190940,
-0.324790, 0.605940, 2.671810, -1.370280, -1.078910, -0.959880, -0.329390, 1.269180, -0.996360, 0.362040,
0.698180, 1.039680, -0.688240, -2.359930, -0.676250, 0.931370, 0.474850, -0.633020, -0.682650, 1.096620,
-2.623460, 0.206700, -0.289370, -1.669850, 1.056890, 0.629980, -1.100100, -0.244400, 0.092100, -0.262460,
-0.770640, -0.832340, -1.179960, -0.241340, -1.860840, -2.262800, -0.798070, 1.413570, 1.301340, 0.253310,
-0.053680, -3.287730, -2.284110, -0.214640, 0.719800, -0.541700, 0.791110, 0.055810, 0.085580, 0.471980,
0.038520, 0.365180, 1.016800, -0.677830, 0.941020, -1.368480, -1.202890, -0.025700, -0.075490, 0.827730,
-1.142610, 0.034280, 0.343380, 0.543630, 0.365700, 0.011460, 1.141490, -0.708980, -2.291960, -0.676200,
-0.343280, -0.714250, 0.044050, 0.765080, 0.544050, -1.647870, 0.101470, -7.844410, -1.467160, 0.506990,
1.398690, -1.442590,
-0.475010, -1.777980, 0.161940, 0.830620, -0.096640, -1.597980, 1.179120, 0.742850, -0.515480, 0.305190,
-0.185440, 0.703770, -0.565950, 0.799730, -0.483010, 0.520160, -0.846860, -0.368570, -0.759620, -0.272310,
-0.289050, -0.511420, 0.027910, 0.128970, -0.166400, 0.770320, -0.570830, -0.430420, 1.643250, -1.186950,
-0.698850, -2.238560, -0.995110, 1.646230, -0.177260, 0.349980, -1.784400, 0.959900, -0.527420, -0.403030,
-2.976960, 0.862290, -0.885870, -0.762480, 0.022190, -1.843010, 0.708900, 0.316220, -0.137680, -1.034160,
0.491730, 1.112120, -0.966810, 2.835270, 1.789820, -0.226850, 1.286020, 0.206950, 1.860880, -0.202270,
-1.231450, 0.663550, 0.223300, -0.724420, 1.512710, -0.850540, 0.353090, 3.422700, -0.002300, 1.806140,
1.397350, 2.152500, 0.134590, 0.597800, -0.051100, 0.796850, 0.197910, 0.513900, 1.053190, -0.636740,
0.732420, -0.650740, 1.750080, -1.468740, -0.214030, 0.537770, 1.488720, 0.423800, 1.179470, 0.139550,
2.389480, -0.856340, 1.675170, 0.012690, 0.689170, -2.358340, -0.906540, 1.398890, -0.970520, 0.864680,
-0.476900, -0.108380, -0.731210, 2.797840, -0.217290, -1.205530, 1.370000, 1.918960, 0.582400, 0.543740,
-0.067040, -4.177570, -1.202480, 1.518120, 2.021540, -0.822050, 0.016510, -1.195210, 0.450520, 0.421450,
0.186470, -0.233560, -1.553480, 1.326660, 2.729850, 0.134010, 1.195090, -1.026650, 0.359270, -0.814810,
-1.453000, -1.259140, -4.343720, 0.039800, -0.787580, 1.553170, 1.423900, -0.595050, -2.234680, -1.083380,
-0.438790, 0.249720, -1.377680, -0.751010, -1.453220, 1.873960, -0.235630, 1.711410, -0.416720, -0.098160,
1.164930, 0.832420, -2.524490, 0.203640, -0.808980, 0.231500, -1.622280, -0.731360, -2.467180, -2.426910,
-0.122600, 2.900850, 0.524790, 0.877490, -0.017900, -2.126460, 1.297350, 0.855240, 0.108780, -0.915950,
1.397290, -0.476610, -0.635160, 1.443310, -0.827030, 2.645720, -1.037780, -0.545510, 0.010500, -2.447290,
-1.486170, 0.934690, -0.134200, -0.038610, 1.065500, 0.252670, -0.783380, 0.500970, -0.780550, -0.829480,
-0.352230, 0.724380, -2.047350, -3.692320, 0.800400, -1.202490, 1.461450, -3.246880, 1.080170, 1.043560,
-3.050210, -2.177060, -0.065700, 3.268910, -0.531000, -2.420750, -5.376320, 0.570670, -1.768910, 1.222230,
3.151210, 0.628800, -1.001290, -1.352310, -0.263890, 0.483030, -0.986630, 4.323890, -1.103430, -0.725290,
-0.139200, -3.728220, -5.613640, -0.109240, 2.803200, -0.408310, 0.206520, -0.270110, -0.218100, 2.343770,
0.443300, -0.088940, 2.570970, 2.699380, 1.332000, 1.728670, 0.559970, 1.675190, 0.310840, 1.036290,
1.056320, 0.587330, 2.456790, 1.154260, 0.388490, 0.138800, 0.316870, 1.189860, -0.211910, 2.634840,
0.250080, 0.852240, 0.949050, 1.524890, 8.603390, 0.960960, 1.162460, -0.628440, 0.080630, 2.461550,
0.811130, 3.211340,
-0.470260, -1.476500, -0.099960, -0.237750, -0.411920, -0.639920, 0.584090, -0.629710, -1.276120, 0.058380,
-0.042350, 0.152310, -1.257240, 0.375960, -1.730430, -0.130360, -2.338970, -1.361110, -2.089280, 0.211850,
0.796210, 0.386260, -0.652970, 0.300240, -0.565420, 1.360770, 0.417840, 1.120860, -0.642230, -0.126520,
-1.342880, -0.618010, 0.318620, 1.163640, 1.204970, -0.808270, 0.358210, -1.207440, 0.028800, -1.324130,
-0.722090, 0.611540, -1.144950, -1.576940, -0.656390, -1.263010, -0.793110, 0.513450, 0.213640, -0.057030,
0.658840, 0.237100, -0.650900, 1.272800, 0.615390, 0.350120, -0.731330, -0.452970, -0.565340, 1.489130,
0.105330, 0.042530, 0.370450, 0.303250, 0.326590, -1.158130, -0.713990, -1.086730, 1.275810, -0.653280,
0.093280, -1.546490, 0.058820, -1.273410, -0.787020, 1.237590, 0.715730, 0.609950, -1.670010, 0.760820,
1.199380, 0.068750, -0.892790, 0.284450, 0.336660, -0.596310, -0.057760, 0.602810, 0.742560, 1.737790,
1.167390, -0.282220, -1.401860, -0.716890, 0.806350, 1.012790, 1.160910, -1.364130, 1.107330, 0.496880,
0.332480, -1.076740, -1.587280, -2.178440, 0.818100, -0.248340, 1.408100, 1.239300, 2.741060, -0.950640,
0.234920, -2.071520, -1.812640, -1.150930, 1.761420, 0.600930, -0.510450, -4.708820, -1.983220, 1.178970,
-0.450370, 0.570440, -1.314140, -2.303580, 4.929570, -0.254170, -0.524620, -1.301690, -0.520220, 2.805820,
-1.152420, 0.410220, -3.959520, -1.478830, -2.013770, 1.008110, -1.738430, -1.146460, -4.148980, -0.009850,
7.112610, 0.353290, 0.643180, -1.752610, -3.768230, 4.491400, 1.200260, -0.250070, -0.621790, 0.214640,
0.070810, 0.010100, -0.512180, -0.627300, -2.242260, -1.308210, -1.443510, 0.276140, -2.502740, -3.643680,
-0.272220, 8.822130, -0.820280, 4.433860, -0.081590, -2.302600, 8.076370, 0.002530, 0.682820, -1.202730,
-1.422510, 0.284080, 0.067680, -1.389620, 0.744030, -0.367750, -0.950680, -1.228850, -1.673030, -2.354810,
-3.493380, 0.076190, 7.584810, -0.089450, 2.010830, 0.090490, -0.186630, 2.328410, 1.026800, -0.109100,
0.020740, -2.743230, -1.247400, -1.097270, 0.220430, -0.360660, 0.130120, 1.401830, -1.062000, -0.906970,
-1.536590, -1.611280, -0.625010, 3.891200, 0.021060, 0.106920, -0.414520, -1.581770, 1.825610, -0.736660,
-0.407890, -0.803660, -0.932940, -0.825620, -1.238890, -0.125000, 0.156240, 0.579330, -0.051480, 0.393540,
0.535610, -1.372600, 0.168780, -0.716990, 0.234810, -0.311250, 0.611520, -0.318380, -0.973150, -0.774840,
-0.750490, 0.804620, 1.101860, 0.757120, -0.752710, -0.389890, 0.260320, 0.064510, 0.059860, -0.887040,
0.628340, -0.667800, -0.138010, 0.121450, 0.013570, -0.240400, 1.175170, -0.903340, 0.021720, -0.629220,
0.375110, 0.685280, 0.281870, 1.036290, -1.846860, -0.795600, 0.782050, -3.220320, -0.979870, 0.630640,
-0.495540, -1.272720,
-1.469360, -0.487090, -0.512520, -0.015090, -1.038110, 0.612100, 0.353030, -2.060730, 0.533020, -0.449340,
2.430460, -0.298630, 1.739090, 0.616560, -0.139430, -0.406390, 0.674130, -0.351150, -0.465180, 0.480750,
-0.952350, 2.740240, 0.056630, 0.564750, 0.631800, -0.384070, 0.412060, -0.151250, -0.072960, -2.003550,
0.586880, -2.285660, -0.311100, -0.496660, -0.009600, 0.337290, -0.190480, 0.537040, 1.050600, 0.064340,
0.764320, 0.559310, -0.637150, 0.875800, -0.794350, 1.016000, -0.669560, -0.227890, 0.897740, -0.970100,
-1.143900, -0.101120, 3.033050, 0.394650, 0.383200, 0.978150, 0.177080, 0.259890, -0.281860, -0.614980,
-0.640050, 0.911530, -0.618460, 3.312060, 1.589380, 1.584480, 0.016470, -0.543860, 0.289850, 0.227320,
-1.012820, -0.287640, -1.535060, 0.309020, 1.586900, -1.654950, -1.748980, 3.994430, 0.167300, 0.761330,
-0.910240, -1.793620, 1.331900, -1.312340, 1.148340, -0.629910, -1.880860, 3.544590, 0.229660, -1.220360,
-1.071940, 0.415570, -1.322080, 0.619010, 0.955910, 2.213050, -3.301500, -0.733940, 5.818030, -0.477250,
3.625630, -0.739250, -2.541020, 3.049720, -0.378330, 1.071530, 0.798910, -0.413560, 1.557110, 0.861210,
0.011330, -0.657110, -2.109710, -0.730580, 0.467660, -0.163180, 0.865120, -0.614010, -2.208930, 9.154410,
-0.072930, 1.380610, -0.403820, -0.855150, -2.437190, 0.847200, 0.048240, -0.978250, 0.511790, 1.532720,
-0.080490, -1.479970, -0.892300, -2.148100, 0.905220, 0.627240, -3.660760, -1.723810, -2.521080, -2.051610,
6.208610, -0.013000, 2.159380, -0.561810, -1.081890, 3.435350, 1.166940, 0.812710, -1.567400, 0.875790,
-1.121200, -0.623020, 0.434620, 0.740840, 0.399370, 0.624720, 0.899360, -2.271400, -0.434510, 1.776000,
2.966490, 2.674730, 1.402960, 0.853180, 1.117150, -0.801680, 0.630480, 2.244300, -1.773460, 0.112970,
0.103350, 1.361860, 0.069700, -1.073290, 0.173450, 1.085160, 2.049110, 1.445240, 0.079500, -1.134330,
2.389210, -0.284320, 1.966120, 0.268560, -0.098110, -0.967550, -1.133090, -0.025310, -0.182920, -0.657030,
-1.401180, 0.483710, -1.835890, -0.480340, -1.829250, 1.114130, 1.031540, -0.315440, 0.546710, -0.535830,
0.282240, 1.134960, -0.966700, -0.710830, 1.195980, 1.378040, -0.917590, -0.873830, 0.026860, 1.319070,
0.254440, 0.257290, -0.811680, -1.242930, -0.067280, 0.535700, 1.488730, 0.436450, 2.295980, -0.334120,
-0.105930, 0.283090, 0.721200, 1.765820, 2.466730, -0.288110, -0.025000, 0.164640, -0.436880, -1.309900,
0.656910, -1.201370, -1.166670, -1.704880, 0.766270, -0.345770, 0.904930, -0.556170, 0.994350, -0.755220,
0.507540, -0.231680, -0.267760, 0.219210, -0.655210, -0.721110, 0.516710, -0.729930, 0.210380, 0.451620,
0.101650, 0.394010, 0.586480, 0.417760, -0.113120, -0.189010, 0.069750, -5.074550, -0.358780, 0.739060,
-0.597140, -1.311250,
-0.302870, -0.436020, -0.296130, -1.396190, 0.647220, -1.725480, 1.038830, 2.847650, 1.024110, -1.045650,
0.782390, 0.712860, 0.992760, 2.324670, 0.307850, -0.908910, 2.546850, -0.069130, -0.992510, -0.535420,
0.681870, -0.173970, -1.083670, -0.891140, -0.317570, 2.003060, 0.182330, 0.123470, -0.276190, 1.451970,
0.372740, 0.193710, 0.973130, 3.443040, 0.842490, -1.518070, -0.002730, 1.335740, -0.129540, -0.748600,
-1.764690, 0.508880, 1.198460, -0.635090, 0.073880, 0.776750, 0.588810, -0.556360, -1.130470, -1.469330,
1.276320, 1.734590, -1.225730, -0.299250, 3.276050, -0.818800, -0.888780, 3.175940, 1.006840, 1.885820,
-0.508110, -0.824560, 0.336990, -0.421190, 0.044960, 0.339160, -1.162460, 2.010280, -0.803740, 2.340270,
-0.212060, 0.731720, -0.143910, -1.579450, -0.579920, 3.207990, 0.071320, -2.115630, -0.093490, 1.789060,
1.016130, 0.544740, -3.582770, -1.694150, 0.600060, 0.169310, 0.426700, -0.279840, 0.582700, 0.651910,
0.785870, -3.509140, 2.285870, 1.105400, -1.453480, -0.135780, 1.026380, 0.642800, 0.287070, -0.072840,
1.532910, 1.898390, -0.208690, -0.791010, 0.210050, 0.644150, -2.018440, -4.467200, 2.746610, 0.338760,
-0.499460, -1.547300, -5.981040, 1.400420, 1.297440, -0.009690, 0.831970, 5.218170, -0.066830, 0.737490,
1.278570, 2.904020, 1.495090, -1.329030, 0.607490, 1.884280, -1.439480, -0.246990, -0.373710, 0.801390,
-1.677630, -3.574710, -3.191240, -5.849060, 0.703550, -0.351290, -0.387120, -0.143050, -0.134240, -1.526660,
0.519300, -6.343970, 2.129560, -3.417770, -6.202900, 1.179910, 0.975190, -0.958990, -1.796180, 1.283380,
0.317640, -0.038160, -2.391960, -9.115830, -1.897190, 0.021540, 2.667720, -0.021200, 0.710280, 1.389630,
-0.031200, 0.543130, -4.208890, 0.721210, -1.471020, 0.288720, 0.688270, 1.099170, 0.337170, -0.292210,
-2.764950, 0.938510, -0.936010, -0.714380, -1.523570, -0.930000, -0.916450, 1.159680, 0.409450, -0.146810,
2.737660, -0.974370, -0.444330, -3.124730, -1.534710, 0.952360, 0.939980, 3.175430, 3.796680, -0.712290,
-0.676570, 1.061400, 1.020450, 5.326710, 0.212800, 3.530860, -3.264190, -1.001590, 1.053520, -1.241400,
-0.389600, 0.694820, -0.066470, 0.863090, 2.333010, 0.083660, 2.959450, -1.386130, -0.104120, 2.658320,
0.046500, -0.012080, 0.885860, -0.796540, 1.131790, 1.004560, 0.895930, -2.173280, -0.159930, 1.854760,
0.047240, 3.462800, 3.136730, -1.334440, -0.084260, -0.959440, -0.318070, -0.409470, -0.222140, -1.832990,
3.728530, -1.527950, -0.503280, -1.121010, 0.211420, 0.319940, -0.447890, -0.651640, 2.090390, 0.919060,
0.210320, 0.513120, -0.507360, -0.070280, -0.788990, 0.764100, 0.950920, -0.813720, -0.315080, 0.565200,
0.569170, -1.201070, 0.967620, 0.912020, -5.696340, -0.525240, 1.027760, -2.048200, 3.488360, 0.273020,
0.813640, 1.291100,
-0.049380, -1.002620, 1.126060, -0.652580, -0.730520, -0.809610, -0.346230, 2.011870, 0.080550, 0.559890,
1.380960, 0.269200, -1.042510, -1.624430, 1.092300, 0.674120, 0.537490, -1.015640, 0.861820, 1.938190,
1.757380, -0.083550, 0.291970, 0.914220, 0.408720, -1.486800, 2.414350, 1.676260, 0.413050, 1.527010,
0.626790, -0.882170, -0.137270, -0.637910, -0.820060, 0.925190, 0.633590, -0.015030, -0.437710, -0.657700,
1.738990, -0.291310, -0.068210, -0.174730, -1.503980, -1.030820, 2.082860, -0.795150, 0.225370, 1.557080,
2.602740, -0.707780, 0.573390, -1.418210, 0.661990, -0.457060, -1.954720, -1.854750, 1.726280, 0.607250,
0.250260, 0.398180, 2.285970, -0.373800, 0.382800, 0.571530, 0.134910, 0.198770, -0.211650, -1.010890,
1.829810, -1.891410, -1.437540, 0.858590, -0.570770, -0.014830, 1.564080, -0.731710, -0.515130, -0.167800,
0.699290, -1.252330, -1.982890, -0.462460, -0.593240, 0.062540, 1.262090, -0.049400, -1.475350, 1.971060,
0.976760, 0.503530, 2.157640, 0.202780, 2.213780, 0.505340, -0.446600, 0.390380, -0.182650, 0.789110,
-1.606000, 0.032930, 0.724320, 0.185350, -0.035050, -0.463650, 0.214790, -1.644940, 0.779490, -0.282210,
-0.202160, -1.425980, 2.343560, 0.412210, 1.204670, 1.572640, -1.350600, 1.614370, -0.215270, 0.136830,
0.158160, 0.130600, 1.258190, 0.762270, -0.255820, 2.046340, 1.787980, -0.688890, 1.078220, 1.973660,
2.900680, -0.395400, 0.464160, -1.386110, 1.594410, 2.235990, 0.052460, -4.029200, -4.101310, 0.113550,
2.017360, -0.050940, 3.702060, 1.596810, -1.685550, 6.056540, -0.963600, 0.062420, 0.418350, -6.466050,
0.660760, -0.744140, -1.216810, -2.323340, -1.115050, -0.585550, 0.260860, 1.921690, -2.096960, -2.106170,
-0.120970, 0.675000, -1.106800, -0.349100, -1.222370, -1.652020, 2.340550, 0.287170, 1.632310, 0.463070,
-0.260720, 4.500560, 0.538180, 0.515890, 1.447950, 0.005980, 0.815910, -2.021570, 0.278550, -1.710480,
-2.125290, 0.391020, 2.945800, 2.815940, 1.050260, -0.508230, -1.686290, 1.126740, -0.989860, 2.555240,
0.233560, 0.746070, 0.061020, -1.070290, 1.419250, -0.292470, -1.028320, -0.500790, -1.460330, -2.491500,
-0.686040, -1.031530, 2.385330, 0.050080, -0.583400, 4.027170, -2.084420, 0.113250, 2.089470, -0.260230,
0.043580, -0.345220, 1.536240, 0.110270, -2.136140, 0.776070, -0.090450, -1.260950, -1.659250, -2.124370,
0.538390, -0.958160, -1.664950, 1.164210, 2.186070, -0.412140, 5.554390, -1.464820, -0.481170, -0.524880,
-0.452600, -1.970520, 0.855030, -0.340730, 0.214290, 1.028550, -1.195910, 0.402170, -0.264090, 1.009990,
0.190660, 0.587240, 0.449480, 1.351220, -0.080950, 0.193530, 0.791740, 1.562080, -0.392040, 0.480450,
0.231930, 1.001350, -0.476910, -0.133050, 5.059180, 1.430760, 0.759660, -0.638750, -3.204360, 0.865820,
0.502440, -0.599260,
-0.357740, 0.845730, -0.345520, -0.746530, 0.844950, 0.836850, -1.056410, -1.150390, -0.371810, 0.132320,
-0.275310, 0.401410, -0.163790, 0.507130, 1.491960, -0.203810, 0.565120, -0.733090, -2.347520, 0.267770,
-0.523640, 1.392640, 0.771210, -0.334060, -0.833190, -1.154940, 0.027900, -1.226760, 0.324910, 1.024920,
0.890300, 0.431220, 1.248460, -0.675710, 0.387190, 0.478490, 0.172100, -0.918520, 0.930910, -0.979760,
2.616610, 1.063310, -0.499420, 1.367380, 0.262590, 0.109520, -0.714990, 1.173950, -1.170870, 1.123060,
-0.580780, -0.929670, -0.901800, -1.679230, -0.444420, 0.167480, 0.506610, 0.367420, -0.577730, -0.651250,
1.831000, 0.764900, 0.071980, 0.941630, 1.562070, 0.027180, -0.295820, 0.065830, -0.153640, -0.776400,
0.388840, 0.064600, 0.160360, 0.236910, 0.070770, 1.590430, 0.057050, -1.702700, -1.145110, -0.563200,
-0.652530, 0.373220, 1.996450, 1.055420, -0.097790, 0.458330, 0.076490, 0.944900, -0.465380, -1.595430,
-0.901100, -1.337810, -1.939250, -0.326310, -0.268820, -0.410240, 0.898970, 0.634510, -1.060810, -0.967460,
0.098860, -0.597680, 0.091110, -1.040700, 0.440950, -2.333220, 4.168600, -0.576370, -3.589120, 1.294500,
0.644590, 3.705740, 5.489900, 1.503870, 1.144990, 2.448060, 0.170080, 3.990490, 1.733620, -0.076920,
-1.847190, -4.919390, 2.097110, 3.420790, 0.008040, 1.386540, 1.005370, -0.093280, -1.097000, -0.322030,
1.110820, 0.544410, -0.283680, 2.438760, 1.267330, -1.037630, -0.467430, -0.607280, 1.774650, 1.540980,
-4.137340, -0.440740, 0.358320, 0.337930, 0.547600, -2.363920, 1.282670, 1.963740, 1.667510, 0.255260,
-0.173640, -0.801220, -1.393230, 2.021650, 1.169610, -0.728180, -0.051640, -1.219610, 0.569770, 1.359540,
-0.861430, -1.041220, 0.089340, 0.314350, 0.472090, -0.084010, -0.952490, -0.160710, -0.587880, 0.922400,
-0.047260, -0.039920, 0.173460, -1.153910, -0.652950, -0.387230, 0.389200, -0.094770, 2.641910, 1.876420,
1.999250, 0.507880, -4.222400, -2.184870, 0.357690, -0.324980, 6.269430, -1.302510, -0.725150, 0.167750,
-1.454630, -1.616180, 0.046670, 1.155630, 0.486690, -0.733010, 0.297170, -0.672290, 0.522500, -1.119860,
-0.045040, 1.064730, 1.372940, -0.476190, 0.061280, -1.906250, -0.253120, 1.822460, 4.980920, -2.205940,
-1.710230, 1.508400, -0.124140, -0.253400, 0.845020, -1.309770, 0.108380, -0.515520, -0.327860, 3.318430,
-1.110320, 1.483090, 1.844850, 0.903890, -1.962730, 0.680640, 1.832150, 1.010500, -1.772750, 4.857310,
0.306410, -0.265470, -0.856730, -0.058050, 0.272190, 0.770780, 0.541180, 0.838300, 0.360120, -1.429120,
-0.489560, 0.281310, 0.866790, -1.052890, -0.746910, -1.283270, -0.687220, -0.947950, 0.002890, -0.400810,
-1.306700, 0.470130, 0.087340, -0.433910, 1.068560, -0.247360, 0.135840, 0.819580, 0.728050, -0.991620,
-0.168960, 2.156690,
0.469390, -0.617290, -0.035120, -0.523040, 0.083540, 1.176950, 1.168660, -0.475310, -0.772010, -0.402540,
0.057160, 0.870770, 1.053830, -0.654880, -1.100560, 0.194770, -0.705610, -0.049990, -0.594740, 0.030290,
0.200080, -0.492540, 2.527650, -1.034150, 0.927170, -0.480590, -0.723970, 0.345240, -0.796380, 0.295240,
0.813220, 0.162650, -0.916920, 1.828490, -0.893730, -0.512430, 0.485990, 1.301020, -0.207680, -1.744610,
-0.358550, -0.395750, 0.053280, 0.274240, 0.579380, 0.255610, -0.154220, 0.320710, 1.958710, 1.252910,
-1.079330, -1.042830, -0.142780, 1.288510, 0.255570, 0.874200, -0.781300, 0.551820, -1.002190, 0.518470,
0.844000, 0.251350, 0.954710, 1.136390, 0.088140, 0.067330, 2.426330, -0.759010, 0.478070, -0.406410,
-0.186240, -0.053210, -0.048290, 0.529280, -0.824050, 1.938450, 0.997010, -0.153790, -0.308260, -0.340800,
-0.661000, 0.575090, -0.671580, -0.880720, -0.672150, 0.164900, -0.760450, 0.462570, 0.086580, 1.191910,
-2.652700, -0.628970, -0.158190, 0.116540, 2.537590, 0.055270, -2.824080, 0.457560, 0.979090, -0.221870,
0.817690, 0.153050, 0.375370, 0.114070, -0.395920, 1.452270, -0.021220, -0.803610, 0.148060, -2.024320,
0.717390, 1.087640, -2.842420, -0.765980, 0.206180, 2.311000, -0.056290, 0.781240, 1.752460, 0.076280,
0.268470, 1.568050, 0.247920, -0.531340, 0.012560, 0.753540, -1.826850, -0.263230, -0.873980, -4.121060,
1.258720, -0.134140, 2.284120, 2.128720, 1.026680, 0.865060, -0.962820, -0.397730, 2.411050, 0.427050,
1.234320, -0.193320, 0.581720, -1.456750, 1.681340, -2.413710, 1.344570, -0.008000, 1.434300, -2.111590,
0.568600, -0.638770, 0.654690, 3.191790, 0.249910, 0.898460, 0.232370, 0.218440, 1.680890, 7.535920,
2.525380, -3.300110, -1.444030, -0.062560, -1.028130, -0.135630, -4.594380, 0.397630, -0.587290, 0.005080,
-0.971040, -0.582980, 0.842320, 0.495410, 1.338640, 2.418710, 0.534510, 0.812840, -1.310790, 3.845680,
4.314960, 0.175280, -4.608750, -0.150220, 0.113580, 1.345030, -0.048900, -2.933190, -1.327460, -1.319560,
-0.681930, -1.560090, 2.728300, 0.841140, -0.119630, 0.439690, 0.274500, 2.970480, 2.277480, 0.391740,
2.377170, 4.737770, 1.405480, -6.371050, -2.379300, -2.823260, 2.090070, 0.873250, -0.510920, 0.231370,
-0.454280, 0.165190, -1.192280, 2.046660, 1.161130, -0.541070, 1.905120, -5.122640, 1.509340, 1.979910,
0.509160, 4.311490, 2.966080, 0.485420, -2.781200, 0.016020, -0.933220, -1.987670, 0.914050, -0.379430,
1.212500, -0.710620, 0.679080, -0.457420, -0.432070, 0.034420, 0.477070, -1.603900, 1.001160, -1.592870,
0.524790, -0.630220, -1.331900, -0.327730, -0.102380, -0.210420, -0.358800, 0.189800, -0.293790, -0.565360,
0.129630, 0.854550, -0.370740, 0.060360, -3.278640, -3.230290, -0.941630, -1.148720, 0.013360, 0.293850,
-0.768200, -0.053140,
-0.276420, 1.751080, 0.760460, -0.576250, -0.947570, -1.525950, -0.376770, -0.126440, 2.065000, -0.607540,
0.570140, 0.147120, 0.421460, 0.365700, 0.927780, 2.962170, -0.777950, 0.851160, -0.918420, 1.275690,
-0.287720, 0.176460, 0.915120, 1.158600, 0.648910, 0.003960, 0.483830, 0.132370, 1.891310, 2.206760,
-0.806640, -0.701180, -1.662760, 0.801360, 1.282000, 1.901730, -0.919270, 1.768220, -1.517760, -0.541040,
1.349790, 1.915690, 1.081320, 1.739990, -0.389040, 0.704190, -0.282410, -0.141680, -0.771040, 0.305440,
0.357280, -1.009170, 0.389170, -0.713640, 0.692570, -0.692650, 0.062230, 1.103810, 1.028700, 0.184250,
-0.307060, 0.605480, 0.757440, -0.976660, 2.214910, 4.590220, -0.470930, -1.341910, -0.819440, -0.692510,
1.287450, 0.026180, -1.744730, 1.305680, -3.398290, -1.044900, -1.052850, 0.420170, 3.969970, 0.065180,
-2.093170, 0.248180, -0.150520, -0.579430, 1.044290, -0.938720, -0.404740, 0.324910, 0.830640, -0.097270,
-0.179160, -0.581610, -0.465260, 0.613870, -0.719010, -1.956330, 2.531400, -1.010210, 1.323160, -1.485860,
-0.618590, -0.911440, 1.522870, 2.511180, -0.563420, -1.003400, 1.534450, 2.098590, -0.937660, -0.572360,
-0.403370, -2.348550, 1.965110, -0.679330, 0.816740, -0.734050, 0.027740, 0.257560, 1.153370, -2.188210,
-0.661160, -0.931520, 0.898240, -1.803490, -1.883800, 1.194580, -1.469960, 3.389730, 0.627500, -2.540570,
-1.627260, 2.036970, -0.370730, 6.018860, -0.317080, 0.287770, -0.909470, 3.334500, 1.346790, 1.042560,
-4.152270, -1.821390, -1.792710, 1.548080, 4.527960, -4.760040, 0.758160, -1.673100, 1.539120, -1.386060,
0.120150, -0.432460, 0.273810, 1.274810, 8.137540, -0.640420, 0.640830, 1.628960, 1.419370, 0.474440,
-0.364120, -5.850040, -0.870670, -4.016940, 0.998940, 4.546030, 2.466230, -0.697600, 1.182110, 1.126560,
-0.375640, 0.756080, 1.355710, 0.143770, 1.510560, -0.587690, 0.934380, -0.655070, -1.301270, -1.398880,
2.945000, 1.366740, -2.307480, 1.875930, 0.121280, 1.315320, 1.937610, 0.099290, 2.205350, -1.242510,
1.593740, 0.415050, -1.219670, -0.816180, 1.310050, -0.540360, 0.538700, -0.605180, -1.380470, 1.086950,
2.193970, -0.441310, 1.035320, -5.075070, -0.226380, 1.278410, 1.374810, 2.980840, -0.282190, -0.323530,
-0.518010, 1.282400, -1.808960, -0.732110, -0.917260, -0.160640, -1.622520, 0.524120, -1.730730, 0.370390,
2.723100, 0.587010, 0.781710, 0.156480, 0.031470, -1.005260, 1.112940, -2.089820, 0.190530, 0.994520,
-0.255670, 0.159550, 1.048450, -2.537240, -1.420460, -1.187060, -1.837990, -1.795790, -0.777360, -0.143930,
0.215000, 0.565310, -1.214380, -2.877870, -0.193710, -1.414890, -1.004670, 0.066290, -2.138380, -1.670420,
-0.320080, -0.030600, -0.393150, -1.429530, 0.896720, 0.342170, -0.342920, -0.325460, 2.061100, -0.401410,
-2.798270, -1.809800,
1.723050, 0.977630, -0.216170, -0.455500, 0.355900, -0.013080, 1.774190, -0.720480, 1.957450, 1.220990,
2.673720, -1.319480, -1.520690, 1.410080, 0.997550, 0.664440, -2.610680, -1.708270, 1.916550, -0.184950,
-1.007890, 0.063080, -0.337410, -1.970130, 0.017320, -0.788020, -0.278470, -1.197990, 0.326960, -0.114490,
-0.652950, -2.046370, 0.648320, 0.100030, 0.673920, 0.973750, 0.610970, -1.488980, -0.499010, -0.638200,
1.467200, -0.144310, -0.747030, -1.403330, -1.149190, -2.352660, -2.010650, -0.837910, -0.111890, -1.899140,
-2.005570, -1.346810, -0.540510, -0.941370, -0.174550, -0.014220, 0.227240, -0.059130, -1.080360, -0.313620,
0.622580, -0.156660, 0.475320, -0.753770, -0.484760, 0.679260, 1.061600, -0.361410, 1.863050, 1.015700,
0.496410, -0.547820, 0.360410, 2.789140, 0.685860, -0.013210, 0.833860, 0.542300, -1.072050, 0.935160,
-0.582170, -0.318750, -0.925850, -4.768090, -0.222940, -0.932790, -1.594290, -1.016180, 0.257690, 1.703020,
-0.691450, 1.651050, -1.710820, -0.184540, -0.764090, 1.489680, -0.766050, -0.164720, -2.005370, -0.163950,
-0.535800, -0.259850, -0.177040, 0.019760, -2.718060, 0.957040, 3.362210, 0.494400, 0.792240, -0.629580,
-1.204310, 1.006480, -3.614220, -0.129190, -2.094280, -0.501840, 0.332150, -0.508510, 1.589170, 0.402200,
0.203040, 1.717200, 0.360040, -0.935600, 4.587720, -1.556740, 0.619680, 0.630220, 0.354650, 2.247710,
1.002310, -0.260230, -5.825210, -3.470390, 0.698550, 0.651200, -0.764360, 0.114220, -0.930820, -1.603090,
6.151000, 1.967240, 1.371370, -0.295760, -2.322540, -0.649300, -0.309620, 1.104970, 4.340350, 0.973070,
0.286530, 1.509590, 0.125250, -2.004710, 0.586470, -0.556140, -0.109360, -0.180050, -0.023300, -0.584970,
0.446550, 1.311090, 2.441300, 0.876050, -1.205000, -2.834400, 0.844130, 0.124570, 0.863620, 0.100490,
1.514740, -0.344610, -0.328400, -0.226330, -0.580480, -0.372350, -0.426770, -1.213550, -0.598830, 0.038920,
-1.533560, 0.702070, 1.867070, 0.104070, -0.396450, -1.187130, -2.294300, 1.469130, 0.650280, 0.638570,
1.082470, 1.916550, -1.057220, -0.989760, 0.145720, 0.427330, 1.710150, -1.340720, -0.703830, -0.524120,
-0.607800, -4.656890, -0.106050, 5.012480, -2.047710, -0.686420, -3.600130, -0.736420, 0.267120, -1.547380,
0.821410, -0.247660, -0.194510, -0.414350, -0.519300, 1.575700, -0.479520, -0.033090, -0.509710, -3.692580,
-0.803650, -1.975860, -2.264510, 0.399740, 1.768130, -1.360590, -0.760740, 0.135800, 0.438790, 0.553660,
-0.412100, 0.229730, 5.455380, 1.635590, 0.184740, 0.664270, 1.384920, 0.033360, 0.752420, -0.726220,
-0.729430, -0.192690, 0.823430, 0.963320, -0.445430, -0.651610, 1.381550, 0.365200, -0.847890, -0.925620,
1.109340, 0.321930, 0.290980, 3.257580, -0.900120, 0.446370, 9.392030, -2.808980, -0.359210, 1.499540,
-1.212460, 0.082850,
-2.042560, 0.963860, -1.556080, -0.607330, -0.123870, -0.756810, -0.228170, 1.091410, 0.373130, 1.451570,
-2.797660, 0.319440, -0.082980, -1.125390, -0.116990, 0.460940, -0.864360, -1.096930, 1.536620, 4.640070,
-0.355710, 0.762710, -0.225620, 2.653470, 0.424400, -1.065590, 0.506880, -0.531200, 0.577530, -1.159610,
1.250000, -1.016900, 0.909970, -0.329130, -1.252660, -2.115270, -1.041060, 0.082220, -0.997270, 1.185160,
-0.175470, -2.219220, -1.190310, -1.411640, -0.657040, -0.617560, 0.612400, 0.786280, 0.254870, 0.326450,
0.922910, 0.568150, 0.413150, -1.673580, -5.201690, 2.006690, 2.660750, -0.100130, -0.144790, 0.864060,
-0.631050, -1.124530, -1.321050, -1.109920, 0.948740, -1.076030, -1.246330, -3.389590, -0.048460, -0.399350,
3.068080, -0.460410, -0.225740, -1.788330, -0.300760, 0.083470, 1.291640, -0.623380, 0.633120, 0.726130,
0.158530, 0.972720, 0.449730, -1.497530, -0.537530, -0.971210, 1.454180, -0.333410, 0.739590, 0.082590,
3.693920, 1.191910, 1.203950, -0.115560, 0.719560, 1.261620, -3.688810, 2.200520, -2.030500, -0.694910,
-0.156890, -2.886690, 1.639180, -1.855020, -0.993390, -0.747760, -0.436580, -0.700880, 0.443140, 0.659590,
-1.620400, -0.910430, -0.430430, -1.566670, 3.432020, -4.746000, 1.150580, 2.094010, 1.441610, 1.118820,
0.741520, -0.122220, 0.130980, 1.319120, -3.386630, -0.277180, 0.668920, -0.771740, -0.467610, -0.263550,
-0.934080, -0.772600, 6.283330, -0.794260, 4.195790, 2.348440, -7.621460, 3.379510, 8.699880, -1.012330,
-0.754920, -0.492150, -1.318980, 3.414650, 0.556470, -3.922370, 0.488880, -0.888550, -0.433930, -1.340500,
-0.832650, 1.037150, 1.196430, 2.209440, -3.257410, 2.776490, 1.517650, -0.363940, 0.656130, 5.352400,
0.012320, -9.702320, -0.524770, 0.137720, 0.470570, 0.691220, -3.356210, -0.870150, -0.921990, -0.237170,
-1.322570, -0.496730, -0.536360, -0.180970, -0.029820, -2.100180, 0.124310, 2.696050, -0.143950, 2.670600,
6.305040, 0.280320, -3.378090, 1.118760, 0.537190, -0.565100, -0.300810, -1.118710, -0.053210, -1.057460,
-0.290710, 1.512890, 0.420350, -0.525000, 0.710970, 0.095990, -2.730210, 0.245520, 0.355460, -1.044650,
8.282170, 4.137750, 0.042060, -5.360110, -0.236350, 0.957470, 0.542530, 0.693400, -2.835250, -0.377780,
0.286450, -0.169810, -3.897780, 2.694470, 1.898020, 2.570740, -0.567300, -0.530480, 0.385690, 2.611210,
1.155040, 1.843170, 4.889380, 2.331160, -2.669490, 0.041650, 0.468880, -0.569050, 0.947680, -0.440280,
0.300050, -0.710360, 0.004600, -0.689100, -0.418140, -1.337480, 0.540930, -0.721680, 1.095750, -0.590700,
-0.366110, 0.011150, -0.024460, -0.784710, -0.506000, -0.075400, -1.261710, 0.485590, -0.311550, -1.278500,
-0.949660, 0.845230, -0.271990, -0.818400, -4.775100, -2.932620, -0.556020, 1.380580, 0.883030, -1.497020,
-0.232820, 0.946380,
-0.033630, -0.020090, 1.749040, 0.365090, -0.936400, -0.125900, 0.165970, 0.509770, -0.533100, 0.175460,
1.060720, 0.881460, -0.417160, 0.367560, -3.026250, 0.789760, 1.588700, -0.932630, 0.602670, -1.471760,
-5.475580, -0.515310, 0.363110, -0.526990, -0.833740, -0.437700, -1.109200, 1.198820, -0.378650, 0.164170,
0.651510, 0.557560, 1.171570, 0.922810, -0.061710, 1.404070, 0.772950, 0.056110, -0.006950, -0.065670,
-1.630000, -5.386520, 0.165850, -0.637750, 0.052540, 1.609380, 1.390440, -0.254250, 2.035770, -8.741360,
0.157860, 1.773040, 0.021180, -0.398570, 0.121590, -2.251420, -0.807280, 0.229780, 4.241110, 0.288830,
-1.755510, -0.394080, -0.829610, -0.754270, 0.028720, -1.475930, -1.474950, -1.090800, -0.955660, -1.013110,
0.665930, -0.156820, 0.126600, -0.234020, -0.454300, 0.000120, -0.773960, -0.720690, 0.205650, 0.652560,
-0.239310, -0.338410, 1.258210, -2.385260, 0.171380, -1.777740, -0.179020, 1.052600, -0.747630, -1.456270,
-3.602710, -0.567080, 0.172060, 0.110480, 0.338300, 0.906300, 0.375720, 1.160610, -0.308800, -0.320740,
3.224860, -0.858040, -1.276550, 1.313340, -1.282550, 0.719800, 0.549220, -0.307040, -0.485030, -1.607260,
-0.769360, 2.832970, -1.134540, 1.046780, 0.616010, -0.778730, -0.376210, -0.544990, 0.901460, 1.821520,
-0.694910, -1.870020, -0.797140, -0.622620, 1.275670, -1.145570, -2.145770, 0.546290, 1.464250, -2.127450,
0.543860, 0.601880, 0.667860, -0.420520, 2.160500, 1.207790, 0.899620, 0.700480, 2.492570, 2.010730,
-2.276460, 0.401000, -2.351560, 1.206310, 0.255760, -1.680230, -1.038230, -2.682600, 1.450520, -1.037410,
-0.208340, -0.791760, 1.738960, -0.853270, 1.296920, 0.281210, 1.093300, 0.391660, 0.882260, -0.116740,
-0.529750, -1.130790, -0.625800, 1.182130, -1.121340, -0.573950, -1.707520, -0.598300, 0.704560, 0.813930,
0.312330, -2.613000, -1.175300, -0.051640, -0.454640, 0.944350, -0.491940, 1.010160, 0.280720, -0.283020,
-2.273270, 0.119560, -1.197350, 0.182790, -0.262080, -1.040910, 3.088190, -0.415890, -3.080670, 1.680360,
-1.248540, -0.268560, 0.528280, 0.049220, -1.437240, 1.240390, -0.156620, -0.533870, -1.395620, 1.589790,
2.191640, -0.163590, -0.527590, 0.233120, -1.691380, -0.753180, -1.042500, -0.636300, -2.768310, -0.306350,
-0.684810, 2.604170, -0.880030, 0.293430, 1.494220, 0.874750, -1.962680, -0.487770, 0.905520, -0.299450,
0.490590, 2.019660, 2.822740, -0.049900, 1.147290, -0.689890, 0.414960, -0.176630, 0.241220, -1.498850,
-1.133800, 1.949450, -1.702490, 0.763210, -2.721130, 2.801050, 1.607450, 0.046130, 1.873150, -0.340350,
0.179790, 0.820480, -0.063560, 0.514470, 0.436620, 0.608530, 1.351250, -1.154570, 0.490120, 1.081180,
1.133650, -0.592960, 0.773890, -0.330500, -1.710840, -0.569460, 0.473760, 1.504290, 1.498550, -0.433520,
1.307230, 0.494280,
-0.145590, -1.062170, 1.504240, -0.170360, -0.901340, -0.080820, 1.127830, 0.255660, -0.487460, 0.889350,
0.844610, -0.025670, -0.351760, 0.606320, -2.076770, -1.568500, 0.406370, 1.587650, 0.352150, 0.678180,
-0.742100, -0.736030, -1.058340, -2.054940, -0.555180, -0.118640, 0.452340, 1.161750, -2.110870, 0.425500,
2.337030, -0.368460, 2.165860, 2.591020, -0.493450, -2.339800, 0.462330, 0.524870, 1.069290, 1.959730,
-1.962370, -1.615330, 0.506100, 0.002260, -0.734340, -2.471370, 0.475980, -0.498260, 1.696780, -1.097480,
3.085920, -0.560890, -2.086830, 2.543920, 4.307040, 0.433060, 0.383590, 0.176150, 0.823780, 4.236550,
0.929440, -4.888970, -1.846870, 0.153270, 0.421350, -8.973560, 0.080930, 0.781100, 2.188780, 3.246330,
-1.172100, 2.425420, 3.295930, 3.143520, 2.888920, 5.378570, 2.394490, 0.734450, 2.051750, 2.045630,
-0.014440, 0.273000, -0.766180, -1.081670, -0.361450, -1.641870, -3.069700, 1.699750, 1.719950, -0.558790,
0.186210, -2.015830, -0.735130, -0.081710, 0.662600, 0.678640, 1.637310, -0.678460, -0.712430, -0.194310,
0.875500, -1.965480, 0.198010, -0.579790, -3.298770, 0.926630, -0.835070, -2.239840, 0.183090, 1.453380,
0.074260, 1.328850, -2.039310, 0.576040, 1.469240, 2.154890, 0.165420, 1.648400, 0.708890, 0.504170,
1.986260, 0.518250, 0.345000, -1.052760, 1.623530, -0.775270, -0.446560, 0.520050, -2.814950, -1.024220,
2.109900, 0.127250, 1.577740, 0.686170, -1.242420, -0.762670, 1.125800, -0.602980, -0.386130, 2.392230,
-1.831540, 1.066760, -0.108260, -1.029080, -0.955510, 0.806880, 1.419680, -6.861150, 2.363650, -0.637680,
-1.724100, -0.873840, 1.693420, -3.047340, -0.053000, -2.138790, 0.914740, 1.714150, 1.199100, -2.914470,
2.064550, 1.221690, -0.724060, -2.433580, -2.243350, 0.674410, 1.688690, 0.696620, -2.815680, 0.878080,
-0.045450, -1.799480, 0.300080, 1.797570, -1.781690, 0.345480, -0.418910, 1.074530, 1.920210, 0.692590,
-2.588280, -0.670440, 0.523180, -1.152330, -2.483910, 1.258270, 0.846420, -0.626650, 8.471820, 1.912930,
0.056040, -0.507400, 0.701750, 1.207100, 0.430230, 0.239270, 0.236440, -0.449260, -1.062370, 0.754850,
-1.874590, -1.634880, -0.590320, 2.111140, 1.932700, 1.477650, -1.315740, -0.072490, -1.002530, 3.165250,
2.386900, 1.264860, -0.166340, -0.117630, -3.319560, 2.917050, -0.946900, -0.332790, 0.647230, -1.060950,
1.499140, -0.851890, -2.526470, 0.993820, -0.023520, 0.728990, 0.662100, 1.230760, -1.366440, -0.739950,
-0.084880, 1.214660, 0.318730, 0.232740, 0.746980, 0.073630, -0.590260, -0.002710, -0.181400, -0.134830,
-0.226200, 0.859740, -0.120020, -0.757170, 0.633590, -0.346480, -0.260670, 0.050070, -0.876490, -0.659690,
-0.265910, -0.248970, 0.977090, 0.488360, 1.482070, 0.747040, -0.414570, 1.045860, 0.800420, -0.362660,
0.428510, -0.874550,
0.054690, -0.617870, -0.279560, 0.328370, 0.983180, 0.353820, -0.014290, -1.052080, 0.065040, -0.348350,
0.262050, -0.036710, -0.104610, 0.644450, -0.416760, 0.915890, 0.800810, -0.104170, 0.250480, 1.119410,
0.843130, -1.120700, 0.553610, 0.029560, -0.980020, 1.837390, -0.429790, -0.846460, -1.032470, -0.743690,
-0.424580, 1.149540, -0.482370, 1.032580, -1.465950, -0.776400, -0.518090, 0.502490, 0.383330, -1.771300,
0.930590, -2.002000, -1.224150, -0.757230, -1.069210, 1.086470, 0.971470, -0.021230, -0.684360, -0.128730,
-0.676130, 0.563320, -1.202150, -2.078200, -0.585460, -1.456810, -0.159890, 0.545210, 0.005780, 0.840420,
0.351140, 1.904900, 0.772970, -0.251030, 0.199780, -0.453000, -0.342950, -1.161600, 0.061930, -0.399660,
1.704360, 0.200170, 0.192090, -2.494900, -0.882750, 0.553830, 0.577750, -0.312270, -0.059230, -0.662330,
0.542200, 1.002320, 1.112610, 0.040980, -0.266420, 0.329820, 1.391790, -0.702110, 1.423220, 0.404960,
3.468790, 2.077970, 0.660860, -0.916330, 0.534640, -2.118680, -0.085190, -0.435020, -0.899270, 0.420340,
-0.618270, 0.583110, 0.072110, -0.951850, 1.502900, -1.809960, 1.642950, -2.594070, -1.546420, -0.678880,
0.444460, -0.640130, 2.985910, -0.451840, -0.084060, 0.738370, 0.258160, 3.326750, -0.222570, -1.530490,
-0.951490, -0.822510, -0.249950, 2.107960, 0.681960, 2.947770, -0.352680, -0.464660, 1.867660, -0.053890,
0.589380, 0.646660, 2.295820, 2.313830, 1.182150, -0.042160, 0.083970, -0.634620, -1.557410, -1.239520,
-0.416740, 0.092680, -1.434230, 0.823910, 0.862220, -0.667620, 2.728210, -1.015270, 0.482900, -0.516940,
-1.034220, -1.177300, -0.040990, -1.323720, 1.198140, -0.142650, -0.301610, 0.396530, -0.099540, 1.113990,
-0.392750, 0.901100, -0.813800, -1.668270, -1.081430, 1.345570, 0.147810, -0.512020, 1.634300, -1.055330,
0.603920, 0.158600, 1.163680, 0.553540, 1.418510, 2.476900, 1.592030, -0.459760, -1.141710, 0.150940,
-0.353140, -0.193140, 0.320170, 1.261920, 1.702880, -0.572510, -0.390920, -1.963660, -0.311720, -0.223260,
0.525720, 0.706520, -1.704240, -0.209890, -0.435990, -0.485100, 0.195730, -0.732810, 0.446780, -0.912730,
0.014210, -0.511130, -0.177080, 0.656410, -0.659970, 0.782160, -0.941470, -1.122960, -0.096680, -1.335980,
1.882020, 0.143580, 1.021800, 0.869620, -0.353380, -0.628030, 0.026560, 0.359240, -0.050880, -0.132800,
-1.173130, -0.650320, -1.428260, -0.028090, 1.542880, 0.345200, 0.506210, 0.581600, -0.312750, 2.200700,
1.492910, -1.345360, 1.786520, -0.303650, -1.745760, -1.423730, 0.010580, -0.258290, 0.131420, -1.597670,
-1.085170, 0.121690, -0.808270, -1.556300, -0.017760, -1.767340, -0.827150, -0.898400, -1.641410, -1.621020,
-3.034270, -2.960450, -0.351300, -0.876080, 1.192970, -2.051280, 0.108250, -10.698930, -7.468480, -1.624130,
-0.702160, -8.185550,
1.376780, -0.588280, 1.302760, 0.643940, 0.833120, 0.510350, -0.380860, -2.130980, 0.458140, 0.514480,
0.567880, -0.669580, -2.820570, -0.672500, -0.234700, 0.566460, 2.919080, -0.549810, -0.496410, -0.535500,
-0.707400, -0.131690, 1.269990, 0.820600, 0.402010, 0.197280, -1.205190, 0.844760, 3.237120, 0.193640,
-0.645190, -0.496370, 0.236410, 0.290120, 0.840330, 0.344070, 0.446100, 0.293930, -4.198070, 1.226530,
0.779580, 0.189070, -0.953920, -0.080780, 1.016910, -1.244700, 0.005430, -1.399320, 0.023060, 2.552880,
-1.352130, 0.490780, 0.643820, 0.274890, -0.387580, 0.724590, -1.018110, 0.875970, -0.602220, 0.525470,
-0.839270, 1.081040, 1.148420, -1.048950, 1.286380, -1.090950, 0.295230, 0.893410, -0.182260, 1.539880,
0.855300, -0.332860, -1.137670, -0.233630, -0.290450, 2.050400, -0.908000, -0.580340, -1.686810, -0.977160,
-0.236540, 0.413030, -1.133540, -1.908630, -1.321430, 0.840880, 2.559620, -0.779560, -0.890910, 0.974730,
1.158160, 1.945260, 2.337480, -0.482450, 0.277910, -1.646230, 0.974470, 0.396290, -2.333670, -0.809790,
-0.564240, 0.232710, 2.625370, -0.439310, 0.433740, -5.836600, 1.313870, -1.454490, -5.677740, 0.432870,
1.266840, 3.095640, 6.690290, -0.913030, -1.590320, 1.373530, -1.338950, -0.614060, 1.692760, -5.596640,
2.069790, -3.476590, -0.730150, 2.401890, -8.241280, 0.125000, -0.984930, 1.719650, -0.852750, -2.777770,
-0.306810, 1.658840, 2.827750, 9.337400, 2.491740, 0.893840, -0.869880, 2.062750, 2.068260, -0.390300,
-10.208570, 1.458280, -5.730720, 0.214780, 5.460780, -6.099800, 0.894720, -0.157120, 0.625160, -0.536260,
-0.824740, 2.585300, 1.520820, 2.586340, 1.186830, 2.224650, 2.351970, -1.652080, 0.278050, 10.276920,
1.619850, -8.038110, 0.637680, -1.417580, 1.718070, 0.243660, -4.485940, 0.480510, -0.786200, 0.242470,
0.462290, -0.442230, -2.989130, 1.833930, 0.380610, -0.249460, -0.188980, -0.819940, -0.730750, 1.708890,
1.492620, -0.708280, -5.090290, 0.407880, -1.471780, -0.135290, 0.182850, -0.341470, 0.012520, -0.379540,
1.502570, -0.459820, 0.131940, -0.963610, 0.910660, -3.329290, 1.829070, 0.494860, 0.583320, 1.449660,
2.577950, -0.023800, -0.425690, -3.546420, 2.239910, -0.008310, -0.732390, -0.719240, -0.133390, 0.118540,
0.275170, 3.361490, 0.911610, -0.191650, 0.104580, -0.273210, -0.719680, 0.519000, -0.778000, -0.249940,
-0.925730, 0.569460, 0.845310, 0.847250, -0.838760, -0.659890, 0.062150, 0.056890, -0.535550, 2.152530,
-1.076760, 0.935050, 2.287550, 0.048370, -2.451310, 0.091480, 0.473510, -0.734150, -1.014740, -0.698320,
-0.961090, -0.626450, 0.383950, -2.582780, -0.427510, -0.413000, 0.049010, 0.048550, 0.115340, -1.175250,
0.041890, 0.522210, 0.026790, -0.459480, 1.868870, -0.852240, -0.768660, -1.833620, 0.166660, 0.146210,
-1.811900, -0.477260,
-0.558730, -0.177990, 1.220620, -0.852690, 1.272300, -0.240150, -2.526470, -0.007800, -3.536050, 0.191410,
0.085380, 0.185570, 0.238790, -0.022810, -1.439850, 0.601490, -0.301350, -0.616510, 0.933610, -0.868790,
-0.458320, -0.604340, 0.150770, 0.428830, -0.131610, -0.921700, -0.980700, -1.648570, 1.123540, -1.746250,
1.403360, 1.399060, 0.817630, -0.025970, -0.183220, 1.779230, 0.517020, -0.707080, -0.560900, 0.498990,
0.157010, -0.864470, -0.762450, 1.951080, 0.480390, 0.359300, -0.477840, 0.078280, 0.455430, 0.458890,
-0.002880, 1.257020, -0.485860, 2.475610, 3.012710, 2.865280, -0.745350, -0.396450, -0.134770, -1.204550,
-1.605030, -1.372360, -0.085680, 1.881790, -0.404670, -1.017760, 0.597060, 3.817810, 2.556920, 0.360600,
1.759070, 0.861390, 1.255620, 0.563860, 0.201190, -0.581340, 1.277190, -7.041750, 0.257430, 0.160330,
0.257340, 0.406240, 0.479440, 0.702820, 0.442410, -0.433810, -0.227380, 0.059880, 3.226570, 0.165380,
1.279180, 2.121190, 4.062790, 0.974150, 0.417270, 0.323760, -1.110020, 0.109590, -4.595930, 0.007230,
-0.651900, 1.286240, -0.612650, 0.743020, 0.289460, -1.007580, 0.099850, 0.494180, 0.133230, -2.311340,
2.238580, 0.381750, 2.014960, 3.879110, -0.488420, 3.363650, -2.526220, -2.015670, 0.152610, -1.406450,
-1.762540, -3.417020, -0.230330, -1.056730, 0.956460, 0.203670, -0.487820, 0.332450, 0.982780, 0.189800,
-0.873310, -2.778310, -2.063210, 0.864720, -0.988500, -1.102480, 0.446680, -1.228440, -5.856680, -1.385900,
-0.387990, 0.207990, -2.947210, 0.567530, -0.810680, 2.204500, -0.297210, 0.155970, 0.425380, 0.492490,
1.654230, -2.032650, -0.655380, -1.859520, 3.743200, -1.201800, -3.675660, 0.213430, -5.168120, -3.561850,
1.352240, 1.815350, -0.733870, -0.165070, 0.127310, -0.160600, 4.032080, 1.712770, 0.531570, 0.091000,
0.143170, -4.317030, -0.512960, -0.005330, -1.300530, 8.021490, -0.631480, -4.182070, -0.343610, -2.298240,
-4.191510, -0.829470, 9.417580, 0.088330, -0.707120, -0.669040, 0.651620, 1.594110, -0.368800, 1.293680,
1.413510, 2.684050, -0.816040, 0.403350, 0.115780, -0.000910, 11.053930, -0.967060, -2.188890, 0.557300,
-3.062360, -4.244760, 0.889980, 2.531040, 0.671240, 1.063770, 0.172840, -1.149110, 0.901200, -0.308490,
1.070460, 0.427930, 2.775030, -0.621980, 0.123900, -0.724880, -0.525680, 11.338050, -0.733470, -0.397830,
0.568760, -2.597820, -6.235830, -0.234110, 1.828380, -0.588250, 0.097060, -1.497600, -1.100710, 1.144960,
-3.084160, -0.250180, -0.226770, 0.461550, 0.704400, -0.801990, -0.773520, -1.066880, 0.364540, -0.585860,
-0.894250, 0.771700, 0.675580, -0.547100, -1.023120, -1.085850, -0.333280, -0.169260, -0.699290, 0.249340,
-1.017880, 0.285920, 0.214490, 0.399730, 1.060550, 0.635180, -0.647880, -1.810260, -0.313200, 0.001720,
-1.110280, -0.696390,
-0.523940, -0.021750, 0.112960, -1.302300, -0.277480, -0.734570, -0.115370, -1.159350, 0.535870, 0.522500,
0.118290, -1.019730, 0.020860, -0.486440, -1.222850, 0.541330, 0.166700, -1.153810, 0.011270, -1.531630,
0.213350, 0.705600, 0.374260, 0.108680, -0.654130, 0.155760, 0.637610, 1.412750, 0.030140, 0.788100,
-0.377640, 0.677200, 0.231790, -1.228470, -0.845430, -0.072830, 0.006770, -0.471660, -0.745600, -1.023970,
0.974600, -0.403160, 0.016680, 0.125840, 0.568090, 0.787390, 0.228840, -1.224470, -0.391580, 1.241140,
-0.841100, 0.134660, 0.771500, -0.364210, -0.608280, 0.735110, -0.168160, -0.395420, -0.408650, -0.894920,
-0.921360, 1.051010, 0.295470, 0.997720, 0.746690, -1.325130, 0.624050, -1.340580, -1.648120, -1.529780,
-0.105250, 0.421550, -0.414820, -0.057380, 0.412480, -0.468610, 0.586350, -0.126730, 0.499700, 0.120010,
-1.539800, 0.772710, -0.414410, -0.582520, 1.475640, -0.624200, -0.546640, 0.241570, 0.461280, 0.338710,
-1.243300, 0.503710, 0.684310, 0.679790, -0.554480, 0.025310, -0.841830, -1.003740, 0.029210, 0.703570,
0.939380, 0.982620, 0.632100, 0.759870, 0.833310, 0.848590, 0.744230, 1.236680, 0.048200, 0.207870,
0.960000, -0.293540, -0.012190, 0.562330, -1.081970, 0.562710, -0.384480, -0.363690, -0.431380, 0.041590,
-1.555700, 1.252700, -1.515010, 0.472580, -0.120520, 0.072870, -0.201580, 0.036660, -0.031350, -1.159620,
-1.219250, 0.046840, -1.752260, -0.304060, -1.842840, 1.308400, 0.579250, 1.040160, 1.119070, 0.642420,
0.294690, -0.248950, -0.933030, -1.115080, 0.991760, 0.382090, -0.526620, -0.290330, 1.361060, 0.585000,
-0.729220, -0.724810, -0.589640, -0.553070, 0.276120, 0.958990, -0.346760, 0.443710, 0.112740, 0.291790,
0.688830, -0.280490, -0.711430, -0.901890, 0.592620, 0.814800, -0.732960, -0.569700, 0.094720, 0.117260,
1.499970, -0.047340, 1.050520, 0.571400, 1.596960, -2.136690, 1.584550, -0.210200, -0.988630, 0.082570,
1.110890, -0.312880, -0.798340, 1.477510, 1.753230, 0.233680, 1.433600, -0.407590, -0.363910, 0.096870,
0.233910, 2.125410, -1.375190, -0.602640, 0.057800, -0.006360, -0.046040, 0.705220, 0.959500, -0.852720,
0.905700, 1.482070, 0.988900, -0.321630, -0.275450, 0.083030, -0.976540, 0.158240, -0.108790, -0.087380,
0.238950, 0.181410, -0.958440, 0.086880, -1.898860, -0.540870, -0.567510, -1.085560, -1.055070, 0.864060,
-0.214940, 2.233730, 2.909770, 0.212440, -0.790610, -0.617720, -1.529440, -1.152210, 0.946220, 0.332540,
-1.163150, -0.781720, -1.969310, -0.309610, -0.549990, -1.307310, -1.505240, -0.850040, -1.107820, -1.935950,
-1.373250, 0.035610, -2.027190, -0.967480, 0.140020, -1.229910, -0.701590, -1.433500, -0.801890, -1.235810,
-0.549570, -1.222130, -0.584380, -0.883830, -4.069430, -2.321240, -2.141560, 1.967120, -1.037870, 0.317050,
-1.277580, -1.443150,
1.352950, -0.045490, 0.022230, 0.202440, -0.450080, -0.030240, 1.493710, 0.555630, -0.989200, -0.541370,
0.023240, -0.917580, -0.502560, -0.137640, 0.459690, 0.332020, -0.463920, -0.936680, 0.270720, 0.168000,
-0.916380, 0.483450, 0.014090, 0.401700, -0.349540, 0.165280, 0.308320, -0.419090, -0.680170, -0.901040,
-1.417120, 0.096460, 0.201720, 0.297820, -0.700180, 0.028530, -0.199250, 0.383500, 0.356360, 0.409200,
-0.046510, -0.795200, 1.037720, -0.116090, -1.091110, -0.497890, 0.367140, 0.002210, 0.675810, -0.663810,
0.498010, 0.645130, 1.274820, -1.121930, 0.802390, 0.161690, 0.812520, -0.358620, -0.056180, 1.276440,
-0.198170, 0.203150, 0.234490, -0.146040, -1.631350, -0.277860, 0.111560, 0.218460, 1.090750, 1.004920,
0.343760, 0.154110, -2.203800, 0.629230, 0.296610, -0.427070, -0.637970, 0.935440, 0.072950, 0.404350,
0.216820, -0.436520, 0.604690, 0.448920, -0.554910, -0.344760, 0.699020, -0.068010, -1.873050, 0.075150,
-0.719940, -0.120060, 0.370840, 1.008050, 0.083510, -0.471720, 0.237210, -0.858040, 0.718700, -0.546940,
0.869430, -1.382190, -0.131590, -0.962880, -0.627040, -0.857080, 0.854810, -0.356010, -1.222450, -0.196690,
-0.451970, 0.211290, -0.748770, -0.491240, -0.702570, -0.801220, -0.726830, -0.321060, -0.124830, 0.084650,
-0.374480, -1.074130, -1.296350, 1.393000, -0.392670, -0.652000, 1.168500, -0.434390, -1.190790, 1.103610,
0.481610, -0.605900, 2.022440, -0.907970, 0.507250, -0.206120, -1.003400, 0.733930, 1.970480, 0.760560,
1.385240, -1.337200, 1.815230, 0.751320, -0.379930, 0.390530, 1.021920, 0.658720, -1.139310, -1.303870,
0.760420, 1.884050, 0.583060, 1.336220, -0.473480, 1.818840, -0.330850, -0.256000, 0.119080, 2.319910,
0.981990, -1.697910, -0.034860, 3.048840, 0.143220, 0.735720, -2.359920, 1.270220, -1.228490, 0.916660,
0.269680, -0.065750, -1.052130, 0.599610, -0.904070, 0.554080, -0.469120, 1.499180, 0.584750, 1.049650,
1.043610, -0.195930, -1.729690, -0.078020, -0.020650, -1.105910, -0.544680, 0.076100, 0.098820, -0.987800,
-0.460690, -0.744540, -0.809720, -0.422620, 0.052800, -0.751970, -0.266350, 0.685180, 0.291210, 1.738010,
-0.344900, 1.107590, 0.421110, -0.049600, -0.439000, 0.150800, -1.111220, 0.231760, 0.004440, -2.257190,
0.550450, 0.128700, -0.143680, 1.187870, 1.377030, -0.703020, 0.636660, 0.178680, 0.480510, -1.164650,
-0.394120, -0.390670, 3.023910, 0.130490, -0.334300, 0.378210, 1.303790, 3.235060, -0.154660, -0.125260,
2.747420, -0.570550, -2.243560, -0.546210, -2.277780, -1.351290, -0.382670, -1.876110, -0.739060, -0.880040,
-1.059520, -1.390520, -1.709950, -0.849310, -1.829370, -0.921610, -2.208880, -0.343490, -0.697050, -0.200840,
-1.376860, 0.368600, -1.002250, -0.651470, -0.235650, -1.116040, -1.712820, 1.234910, -1.370980, -0.598980,
-0.937520, -0.089510,
-1.089700, -0.533270, -1.104500, 1.189700, 1.105730, -0.184700, -0.061930, 1.251100, -0.274010, -0.280460,
0.918360, 0.298880, -1.074120, 0.004940, 0.348390, -0.320730, 0.936150, 0.051790, -1.227600, 2.792990,
0.183230, 0.508560, -1.483080, 0.561190, 0.005420, 2.918940, 0.770090, 0.462240, 0.298200, 2.516770,
-0.937610, -1.394820, -0.412230, -1.635250, 1.086860, 1.224540, 0.989640, -0.199990, 1.131260, -1.252510,
1.046230, 0.758670, 0.945110, -0.363170, 2.811870, -0.205680, 2.053930, 1.816270, -2.355880, 0.919930,
0.079140, -2.454190, 0.258930, -1.431800, -2.779670, -3.182970, 1.660280, 0.265500, -0.249130, 0.616410,
-0.509730, 4.084500, 1.694020, -1.996940, -0.477810, 2.352170, -0.195970, 2.353370, 1.505370, -1.581620,
4.238090, 0.671600, -2.710600, 0.289990, -1.733070, -2.064490, -1.215680, -0.207240, 0.693280, 1.246820,
-0.451150, -0.018440, 3.854750, 0.883240, -1.263920, -1.838640, 2.492610, -0.484610, 0.090530, 0.860020,
-2.060780, 1.654350, 0.976970, -0.492690, -0.017550, -1.217320, -2.614510, -1.103950, -1.628260, 0.758000,
-0.936700, -2.392600, -0.385780, 2.416330, 0.853340, 1.451140, -0.554830, 3.705580, -1.260530, 0.214050,
0.404460, -0.415860, 2.512120, -0.083090, -0.982530, 0.904490, -1.478350, -4.600510, 0.568010, -0.593640,
0.450210, -1.354550, 1.271280, -0.004120, 1.008020, -0.005150, -0.077930, 0.703820, 2.152660, -2.055440,
0.113930, 1.639370, 0.385240, 1.914920, 0.275150, -2.067560, -0.076400, -1.602920, -1.133060, 1.462790,
0.143110, 0.349620, -0.491910, 1.136860, 0.541420, -3.400330, -0.623180, 0.059150, -0.073740, -0.511750,
-2.884420, -0.848940, 1.188060, 0.684170, 5.708200, 0.153180, -0.292590, 0.359910, -2.370450, -0.684000,
-0.047990, -2.926070, -0.853520, 0.643110, 0.068530, 0.377340, -2.417180, 0.084240, 1.264200, -0.163560,
0.286870, -0.173480, -1.474120, 0.172870, -0.434190, 1.044900, 0.482540, 1.252570, 2.037220, -2.591860,
-4.360900, -0.124340, -0.903350, -0.506310, 0.591620, 0.221460, 0.592110, -1.086450, -1.073880, 0.890390,
0.388570, 0.357890, 0.758150, -0.979730, -0.624660, -0.639670, 3.449290, 1.639950, -1.414720, -0.323370,
-2.982380, -3.139710, 0.175050, 2.313140, 0.286090, 0.558080, -1.534850, -0.020720, 2.131850, -1.846120,
0.338000, -0.443830, -0.851680, 1.252860, 0.647120, -1.278870, -0.098420, 2.548880, -1.788220, -0.969060,
0.062170, -2.432800, -1.449050, -1.654020, 1.544970, 1.565450, 0.067050, 0.638120, -0.427550, 1.641030,
-0.878930, -1.248460, 1.089530, -0.555660, 0.676340, -0.119840, -0.881610, -0.367690, -0.548560, 0.164540,
-0.151450, 0.647980, -0.768200, -0.618920, -0.685930, -0.571310, -0.282660, -0.197780, 0.007620, -0.041610,
0.368730, 0.257710, -0.462410, -0.101940, 1.018020, -0.580110, -0.338630, 0.686670, -1.001240, -0.730670,
-1.335180, -3.107350,
0.027090, -0.678240, -0.767890, -1.023000, 1.135910, -0.736860, 0.932040, 0.405180, 0.808290, 0.346740,
-1.319050, 0.425450, 2.318010, -0.460500, 0.518740, -0.310350, -0.847680, -0.353680, -1.255340, -2.964460,
0.364690, -0.633170, 0.232360, -0.147750, -0.248350, -1.054500, -1.386980, 2.273730, 0.252110, 1.612330,
0.162940, 1.117820, 0.258880, 0.436230, 0.038760, -2.995430, 0.333190, -0.134280, 0.714220, -1.112360,
-0.366210, -0.614400, 0.379670, 1.808100, 2.095620, 1.323920, 0.114470, 0.682600, -0.430980, -0.275050,
0.299600, 0.152460, -0.602340, 0.045900, 0.482110, -0.026460, 0.845270, -0.261140, -0.563160, 0.863480,
-0.531750, -0.699880, -0.747590, 2.129240, -1.559200, 0.619800, 1.370480, -0.018530, -1.925270, -2.995130,
-0.427710, 0.021810, -1.767410, 0.398990, 1.266920, -0.507210, -0.962630, 1.330320, 1.547560, -2.051330,
0.706520, 0.734790, 0.367640, 1.364150, 0.427500, -1.151510, -0.280440, 3.186650, 0.869380, -1.864780,
1.548230, -3.348100, -0.337970, -0.908890, -0.537630, -1.531410, 0.490400, 0.555680, 4.805620, -0.472100,
2.547200, 1.290370, -4.791510, 0.882640, 0.488450, 1.028490, -2.503120, -0.248400, 5.289100, -0.416350,
-1.917280, -2.972120, -10.852330, -3.013340, 2.208700, -0.999690, -1.909830, 0.465600, -1.975930, 8.532820,
0.934520, 5.530780, -2.635870, -5.865620, 2.549600, 0.828120, 0.921540, -0.101780, 1.013230, 0.428470,
-2.224440, -1.033040, -1.227130, -1.088470, 0.101940, 0.886030, 0.853560, 0.719780, -3.028270, -2.009690,
6.586360, 0.013180, 1.329030, -1.061740, -1.431580, 2.158600, -0.049260, -0.079960, 0.852860, -2.537470,
0.103070, 1.636360, -0.904480, 0.521260, 0.998300, -0.163280, -0.953160, 1.350380, -2.057580, -2.895730,
0.191720, 3.325840, -1.885140, 0.955360, 1.016850, 0.140290, 1.517960, -0.237330, 1.032060, -2.289630,
2.502070, 1.974080, 0.832710, -2.153110, 0.782750, 0.277380, -0.868510, -0.156220, 0.054340, -1.468770,
0.554070, -0.131180, 9.171250, 0.710900, 3.159800, -0.121430, -0.344800, -0.041580, 0.895760, -0.977190,
-1.491670, 1.177710, -1.464800, 0.191790, -0.819210, -0.239620, 1.151160, -0.668040, -1.124650, -0.263650,
1.744490, -3.238750, 0.728960, 0.122110, 0.056960, -0.844860, -1.229420, 0.069000, -1.037130, -0.520340,
-1.911440, 2.029550, -0.915600, -1.151780, -2.377630, -0.646510, -1.379590, 2.632340, -1.541930, 0.231170,
0.566240, -0.483720, -0.053950, -1.053650, 1.025220, -1.814880, 0.668880, -1.077970, 2.230850, 0.062520,
1.522630, 0.716050, 0.648210, 0.375580, 0.047020, 0.371090, 0.999210, 0.743750, -0.010240, 1.675930,
0.007820, -0.097720, 0.098540, 0.698970, 1.210770, 1.911600, 0.819140, 0.997700, 0.380280, -0.246600,
0.104300, 0.427130, -0.802300, 1.603530, -2.479850, -0.631580, -0.174970, -0.755480, -0.216630, -0.481080,
0.969050, -2.716630,
-1.917660, -0.824250, 0.140680, -0.585400, 0.621030, -0.575760, 0.560190, 0.565770, -0.293010, 0.607580,
0.536310, -1.044510, -0.281700, 0.727770, -0.593500, 0.147220, 1.307440, 1.565940, 0.891090, 0.070530,
0.379220, -0.067170, -0.430770, 0.851440, 0.527670, 0.376870, 0.600250, 0.206870, 0.662300, 1.052930,
0.131140, -1.023130, -0.245770, 1.971230, 0.858310, 0.534650, -0.284370, 1.764800, 0.770150, 1.279970,
-1.323280, -0.467870, 0.329840, 0.683590, 1.075250, -0.411630, 0.856900, -0.335510, -0.994390, -0.657110,
0.228380, -0.395130, 0.464230, 0.515440, 1.222840, 0.675870, 0.727540, 1.858440, 2.193030, -0.008540,
1.361300, -0.412100, 0.660580, -0.443270, -1.339700, -0.635820, -0.739940, -1.277370, 0.859840, -0.530360,
-0.268680, 0.502200, 0.983220, -0.331910, 0.680550, 1.413120, 0.558540, 1.126340, -1.009310, -0.189150,
1.067380, -0.483680, -2.170670, -0.192880, -0.971330, -0.845280, 0.410790, -0.104330, 0.919190, -0.592460,
0.752570, -1.528210, 1.714270, 1.045650, 0.397310, 1.855790, 0.853660, -0.293520, 4.136840, 0.045760,
2.630870, 0.622730, 0.854460, 1.029980, 0.552330, -1.137900, -0.435000, -1.287290, -0.162550, 0.586000,
1.128140, 4.592800, -1.170190, 0.436270, 0.632850, -1.363320, 1.567430, 5.459770, -0.079550, 0.992510,
-0.516120, 1.945920, 2.633270, 0.196260, -0.513770, 1.870830, -1.945110, -0.097340, -1.199480, -0.483530,
0.989510, -1.624130, 1.626190, -0.451080, -0.349580, 1.004910, 0.457960, 2.228260, 5.385180, 0.388800,
-4.665600, 1.067340, -0.514420, 0.867610, -0.392020, -3.465580, -0.193870, 0.082110, -0.341550, -3.974880,
-0.631750, 0.811510, -1.301420, -0.514990, -2.171750, 0.043620, 0.311340, 0.386450, 2.688650, 3.364060,
-0.579210, -2.190760, 0.334270, -1.088870, 1.409080, -0.715070, -0.162310, -1.270640, -0.521850, -0.476860,
0.857200, 5.310730, 1.702280, 1.424530, 0.612010, 0.326710, 2.805590, 0.414970, -0.115320, -0.543040,
3.014200, 1.069970, 0.353550, -0.461500, -0.406650, 1.749940, -0.555420, 0.015080, 1.100570, -0.330630,
-1.534600, -0.080830, 2.555100, 1.011750, 0.775140, 0.488530, -1.969350, -0.228140, 2.430030, 1.004010,
1.886770, 0.875180, 0.092770, 1.751120, -0.202230, 2.645740, 1.180000, -1.114290, 0.449370, 2.977040,
-2.478850, 0.442080, -1.033950, -0.198860, 1.892890, -0.624520, -0.704360, -1.217840, 0.420340, 1.064660,
-0.421520, 3.115110, 1.703580, 0.653890, 0.221790, 0.225580, -0.535960, 0.116060, -0.130550, -0.064490,
-1.174920, 0.329070, -5.856360, -1.964090, 0.615580, -1.024630, -1.003700, 0.127980, -0.609590, -0.527750,
-0.869600, -0.989260, -1.758160, -3.060720, -0.453490, -1.150050, -1.228160, -2.163720, -0.885870, -1.371010,
-0.252760, 0.235920, -0.737390, -0.565340, -13.747120, -1.491510, -1.364750, 0.462350, 1.187850, -1.301620,
-0.156780, -0.606230,
-1.380830, 0.406340, 0.364360, -0.255000, 0.957550, -0.625980, -0.323600, 0.497460, 0.909920, -0.892100,
-0.016680, -0.670200, -0.452990, 0.218520, -0.551970, 0.375550, -0.557420, -0.718860, -0.544090, -0.455990,
0.075750, 0.414090, -1.343610, -0.536970, -0.548280, 0.930010, 1.150000, -0.680110, -0.159070, 1.413780,
-0.692060, 0.495520, -0.173680, 0.174670, -0.101220, -0.167670, 2.870780, 0.670170, 1.125230, -0.868570,
1.113390, 1.148960, -2.294600, 2.055680, -2.628210, 4.497060, -0.794300, 0.664610, 2.056300, 0.087300,
-0.570810, 0.880330, 0.447590, -0.915400, -3.681500, -1.490620, -0.596430, 0.741120, -1.102430, -0.386820,

-0.883060, 0.539530, -0.115950, 0.464400, 1.251240, 0.056650, -1.535880, -0.070370, -0.908060, 0.198140,
0.764530, 0.158340, -0.142250, -0.856460, -0.051480, -0.706430, -0.754300, 0.720670, 1.051910, -1.218150,
-0.345560, -0.020760, 0.173330, -0.896140, -0.178400, 0.601140, -1.834140, 0.023960, 0.176400, -0.541460,
1.028990, 0.407880, 0.899560, 0.079310, 0.431690, 0.968970, 2.857280, 0.230760, -0.218120, 0.354010,
0.039960, 0.026330, 0.882670, -4.575880, 1.082900, 4.270680, 1.447860, -1.287700, 0.531260, -0.631040,
0.844380, -1.540000, -0.311910, 2.751290, -0.109500, -0.460370, 0.909830, 0.160490, -0.054270, -0.503940,

0.634800, -0.315350, -1.017560, 1.625780, -0.125240, -0.122620, 0.609170, 0.169450, -0.939290, -0.610240,
0.015370, 0.415610, -0.047570, -0.822000, -1.512390, 0.957870, -0.393990, 0.951260, 0.243910, 0.193790,
0.670200, -0.456540, -0.239800, 0.129750, 0.026780, 0.794050, 0.832030, -0.903120, -0.521650, 0.160570,
0.461400, 1.199000, 0.904630, 0.346500, 0.454540, 0.639560, -0.303050, 0.581870, -0.819570, -2.939390,
0.266090, -0.281430, 1.383110, 0.293970, -1.471680, 0.336340, -2.889390, -0.857810, 3.689060, 0.696100,
1.118240, -1.208010, -0.426890, 0.068310, 0.926910, -1.383540, 0.146820, -0.207060, -0.539050, 1.332550,

0.501640, -1.048390, -0.357740, -0.324910, -0.217840, -1.060030, -0.416540, -0.817300, 0.233100, 0.393350,
-0.547250, -0.138630, -0.452830, -0.582750, -0.846250, -1.138090, -0.902700, -0.553560, 0.446670, 0.224870,
0.443070, 0.151390, 0.627890, 0.502570, 0.438960, 0.238770, -0.001770, 0.729290, -0.541440, 0.720180,
-0.230970, 0.452820, -0.467120, -0.133130, -0.509660, 0.409160, -0.262560, 0.163310, 0.758600, 0.078320,
1.196100, -0.528880, 0.105550, -1.573160, 1.353310, -0.378390, 2.323670, -0.502780, -0.883110, 0.743610,
-0.112950, 1.505040, -0.306640, 0.864840, 1.403010, 1.335510, 0.719150, -0.262710, -1.079610, -1.173750,

1.623250, -0.672330, 4.736300, -0.820960, 0.607760, 0.387920, -0.030350, -0.141740, -0.400660, 0.959210,
1.561390, 1.191790, 0.428620, -1.276470, 0.018660, -0.448420, 0.099040, -0.432070, -0.031630, 0.204690,
0.581770, 0.625930, 2.160520, -0.149450, -0.057510, -1.459000, -1.132320, 0.642570, 2.762740, -1.212090,
0.419080, 0.544550, -1.619800, -0.465380, -0.229880, -0.811030, -1.044810, 1.608250, 0.329390, -0.468150,
-0.400970, -0.317920, 24.183470, 5.760420, 5.410890, 1.215330, -1.430770, -0.225220, -4.501270, -0.760720,
-0.277690, -0.816530, 1.045050, 0.358350, -1.063430, 2.228070, -1.267770, -0.329830, -0.294850, -2.062090,

0.405740, -0.835120, -0.695450, -0.318230, -0.549940, 0.127590, -0.010090, -0.368000, -0.149140, -0.421320,
0.750110, 0.348900, -0.289920, -0.247410, 0.412520, 0.021090, -0.533510, -0.054590, 0.141140, -0.345750,
0.297430, 0.891160, -0.210300, 0.474670, -0.078360, 0.041250, -0.480670, -0.627570, -0.488380, 0.172630,
0.690480, -0.151970, 0.449160, -0.168530, -0.481400, -0.760720, -1.164810, 0.696330, 1.151340, 0.663730,
-0.588710, 1.097770, 0.589330, 0.759880, 1.572520, 0.203670, 0.697320, 0.765030, -1.372830, 0.514720,
0.427520, 0.631440, 0.588120, 0.092150, -0.743230, 0.250000, 0.131800, 0.479240, -0.400580, 1.849320,

-2.081500, -0.792900, -0.216530, 0.470920, 0.376980, 0.055010, -0.230260, -0.077370, -0.239310, -0.340550,
0.487430, -0.030240, 0.276910, -0.467580, -0.177060, -0.275630, 1.029270, 1.252130, -0.373310, -0.311140,
-0.060050, -1.896810, 0.107730, 1.339950, -0.405460, 0.946390, 0.260860, -1.943450, 0.655650, 1.852380,
-0.109730, -1.266470, 0.268700, 0.477890, 0.274290, 0.153310, 0.829580, -0.700750, -0.668160, 0.380030,
1.355450, -1.173960, 0.232480, -0.971560, -3.420830, -0.291710, 4.679560, 2.088570, -0.048610, 0.451980,
-0.827020, -5.940800, 0.232750, 0.592620, -0.352990, -5.018720, -0.627380, -0.677160, -1.087280, 0.234330,

0.374760, -0.607250, 1.439010, -0.958530, -0.258020, -0.546600, -1.248900, -1.073110, -1.386940, 1.387800,
1.076720, 0.210470, -0.016420, -1.262500, 0.250200, -0.347450, -0.454350, -0.224250, -0.317870, -0.672130,
-0.121970, -0.305910, -0.026350, 0.562130, -0.028710, -1.081920, -1.215150, 1.577320, 0.051830, -0.821650,
-1.011630, 0.281130, 0.371240, -0.981530, -0.154180, -0.823360, 1.834450, -0.222850, -0.213720, -0.136710,
-0.648760, -0.844660, 1.064080, -0.456830, 1.696240, 1.151940, 2.319330, -0.686920, 2.837270, -0.319040,
1.083000, 2.475260, 1.491720, 0.793510, -0.947420, 0.879410, -0.328950, -0.404210, 0.305680, -1.211300,

0.144190, 1.157360, -0.709970, 0.418430, 0.859980, -0.009200, -2.117930, 0.446680, 0.072880, 0.000970,
0.177010, -0.744240, -0.694790, -0.725590, 0.619390, 1.116010, -0.641370, 1.185400, 0.913830, 0.372850,
0.328570, 0.497330, 0.224880, -0.098790, 0.614400, 0.655560, 0.734090, 0.343830, -0.587560, 0.022710,
0.932610, -0.838660, 0.458840, -0.347480, -0.139810, -0.527870, 0.190860, 0.708700, -0.055290, 0.063640,
0.814100, -0.385450, -2.222570, -6.765820, 0.783120, 0.353610, -0.993100, 1.304650, 0.147650, 0.629340,
-0.597310, 2.116100, -0.230250, 0.104160, 0.257220, -0.213920, -0.605020, 0.375060, -0.359640, -1.968400,

0.612140, 0.922360, -0.676390, 0.583250, -0.334830, -0.204690, 0.082540, -0.725220, -0.024110, -1.207690,
0.351270, -0.523520, -0.794060, -0.532870, 0.250860, 0.972150, 0.358980, 0.738060, 0.208110, -0.494970,
0.153570, -0.339140, 1.575590, 0.399770, 0.395290, -0.805290, -0.618880, -0.909080, -0.072290, -2.072120,
-0.212730, 0.660540, -0.856950, -0.106090, 0.182790, -0.541860, 1.722260, 0.983220, -0.314730, 0.727670,
-0.445070, 0.204090, -0.927600, -2.702850, -0.488200, -0.513170, 0.885690, 0.357060, 1.100040, -0.378680,
-0.053640, 1.514990, -0.589930, 0.641650, -0.652800, 1.115600, 0.699840, 0.347030, 0.252690, -1.071280,

-1.514100, 1.325470, -0.219680, 0.912810, 0.521160, -0.591930, 2.570210, 0.579560, 1.483950, -1.449450,
-1.228620, 0.123890, -0.593840, 0.898440, -1.105720, 0.679110, 0.619210, -0.141170, -1.010330, 1.086930,
0.651130, -0.616560, -1.240820, -0.164040, -1.227060, 2.620630, 3.448560, -0.078240, -1.635100, 1.099190,
0.823100, -0.871620, -0.971080, 0.373120, -0.524680, 0.725270, 0.200020, 0.622490, -0.513880, -0.931680,
-0.275680, -0.731130, -0.743360, 1.227200, -3.100380, 1.481400, -1.484480, -0.416110, 0.652550, 0.129430,
-0.146380, -0.692380, -0.156040, 0.314700, -1.913380, -0.907850, -0.158610, 0.284640, -0.794600, -0.776990,

-0.244580, -0.266820, -0.575270, 0.437800, 0.783420, 0.639460, 0.918740, -0.278150, -0.088320, 0.406580,
-0.851350, 0.192020, 0.303280, -0.564930, 0.483550, 0.735970, 0.491000, 0.488400, -0.303360, 0.521650,
0.633750, -0.928030, -1.159630, -0.412040, -0.545270, 1.204480, 0.124990, -0.692140, -0.852350, 0.590260,
0.587540, 0.995910, 0.799250, -0.481750, -0.275700, -0.799550, -0.931330, -0.357330, -0.112570, -0.346520,
-0.369100, -0.723190, 1.096680, 1.239030, 0.244400, -0.007400, -0.224200, 0.782820, -1.206860, -0.307580,
0.299390, -1.342150, 0.164550, -0.238170, 1.354600, -1.117310, -0.680020, 0.178430, -0.990250, -0.422850,

-0.147430, 0.283920, -0.403770, 1.928810, -1.188550, 0.270930, -0.484210, 0.339240, 0.093830, -0.314650,
-0.926880, -0.231890, 0.868990, 0.320100, -0.237190, -1.564900, -1.894140, -1.909000, 0.140340, -0.545650,
-1.244200, -0.643800, -0.318040, -0.815100, 0.501760, -0.137790, 1.929770, -0.382760, -0.240800, -1.229800,
-1.556740, 0.392760, 0.379710, -0.085240, 0.290350, -0.978300, 2.004110, 0.389360, 0.520730, -0.546610,
0.151800, 0.436210, 2.330240, -0.478720, 0.157070, -1.835940, -0.572020, -0.114900, -4.374490, 0.473420,
0.076750, 1.475200, 0.327950, 0.520580, 1.541370, -0.442130, -1.512660, -0.966490, 0.404490, -0.970580,

-0.141800, 0.294960, 0.112500, -0.225170, -0.664480, 0.506230, 1.218230, -0.420530, -0.414740, 0.089450,
-0.081120, -0.134360, 0.422930, -0.360520, -0.999990, -2.075900, 1.957670, -0.467730, 0.104200, 0.236750,
-0.823010, -0.913800, -0.374780, -0.702650, -0.781130, 0.930440, 0.728460, -0.223120, 0.140210, -0.257350,
0.398410, -0.637760, 0.636010, -0.668510, -0.741190, -0.016130, 0.413330, 0.260080, -0.293420, -0.055170,
-0.905410, -0.686130, 1.331200, -1.660650, 0.329360, 0.095660, 0.452680, -0.412030, 0.775930, -0.863740,
0.154200, 0.023920, -0.276340, -0.987710, 1.291040, 0.699760, -0.317140, 0.771800, 0.836320, 0.656140,

1.442760, 0.675340, -0.724380, -2.239710, 0.933090, -1.196710, -1.186890, 0.666360, 0.591890, 0.148940,
1.007020, -2.952080, 0.207330, -0.939430, -1.174920, -0.739660, 0.571040, -0.304260, -1.040660, -0.586100,
0.601320, 1.434510, 0.653280, 1.847550, 0.573360, -0.859830, -3.808030, 0.713830, -0.184570, -1.487160,
-0.442510, -0.531790, -0.463540, -0.613170, 0.293190, 0.151960, 0.313150, -0.311840, -0.825820, -0.283870,
-0.252020, 0.821450, 3.546350, 0.206890, -0.438940, 0.830720, -0.324910, 0.155990, -0.951290, -0.833290,
0.210170, -0.538950, -1.120940, 1.288080, 2.151920, 0.431170, 0.102940, -0.316800, 0.758490, -0.246500,

-7.065550, 0.447140, -3.044060, 0.748060, -0.391020, -0.451560, -1.728490, -1.067810, -0.778000, -6.416090,
1.174260, -3.188910, -5.137490, -3.452290, -6.928550, 0.231410, -0.539020, 1.685130, -3.794350, 1.785410,
-2.832690, -4.457920, -4.736780, 0.975450, -0.025840, 0.672080, 1.293020, -2.848630, 0.311630, 1.110440,
1.535560, -0.157150, 1.477440, 1.822910, -2.999020, 1.153280, 0.536890, 0.373990, 1.433440, 1.425970,
0.198780, 0.656950, -3.660110, -4.079940, -1.171760, -0.211430, -0.446970, -0.262280, 0.994690, 0.120570,
0.035410, -0.978850, 0.400820, -1.321250, 0.184970, -1.454150, 1.482330, 0.999910, -0.128980, 0.628030,

-2.319940, 0.144880, -0.723140, -0.271530, -0.910180, -5.691010, -2.216220, -0.458080, -0.842280, -1.655800,
-0.454020, 0.193010, -9.525390, -1.052750, 0.268050, 0.616130, -0.321790, 1.419950, 0.193910, 1.264250,
-0.233910, 1.033950, 4.779100, 0.072360, 0.096250, -1.931120, 2.614630, 1.819530, -0.803170, -1.899730,
-0.847680, -1.101690, -1.234670, -0.093590, -0.380300, -0.740140, -3.891390, 0.409930, -0.549870, -0.871260,
0.358990, -1.217170, -0.066060, -0.260840, 0.538190, 0.890630, 0.578620, 1.666390, 1.421160, 0.487610,
-3.117360, 0.447090, -0.634320, 2.491240, 1.003940, 1.750290, -0.579990, -0.389650, -0.613360, -0.688030,

-0.776940, 0.518180, 0.291260, 0.403810, 0.603850, -0.621270, -1.128060, -0.490010, -0.514500, -0.007630,
0.488630, 1.496030, 0.200670, -0.424940, -0.844620, -1.426610, 0.948760, -0.074170, 0.422290, -0.269600,
-0.306440, -0.216220, -1.161250, -0.240390, 0.726840, 1.036610, 0.132700, 0.362760, -0.665790, -0.604320,
-0.815250, 0.444940, 0.253690, -0.545710, -0.619120, -0.877150, 3.145050, 1.545280, -0.575940, -0.509200,
-3.844600, -0.362280, 2.197060, -1.430610, -1.310090, -2.273170, -1.437840, -0.261220, -1.119460, 0.724820,
0.886860, -6.120600, 0.244340, 1.669740, -0.872490, -0.591750, -0.455150, -0.010880, -0.238080, -1.466510,

-0.536210, 0.197650, 0.285790, 0.405150, -0.019780, -0.631600, -1.442550, -0.332020, 1.137590, -0.073880,
-3.062530, -4.996670, -0.673010, 0.238850, 0.094040, -0.349850, 1.718530, -0.936120, -0.347700, 0.615940,
-0.772060, -0.428260, -1.534140, -0.884720, -2.630740, 0.772740, 2.137520, 0.230590, -0.491380, -0.993450,
-1.109530, -0.192960, 0.221960, -1.188600, -0.245470, -0.312850, 0.814060, 0.468860, 0.588500, 0.454830,
1.202100, -0.008630, 0.605570, 1.260080, -0.351410, 1.438470, 0.949970, 0.974650, 0.127980, 0.593450,
0.291930, 0.462070, -0.413390, 0.286790, -0.631770, -1.253990, -0.467690, 0.130350, -0.159020, 0.730220,

-0.112240, 0.293940, 0.453540, -0.273970, 0.603210, 1.427060, -0.684440, 2.288340, 0.546260, 0.169850,
1.026310, -4.011080, -0.349350, 1.666510, 0.107690, 0.573340, -0.031590, -0.186610, 1.008040, -0.270460,
-0.620670, 0.249310, 0.194420, -1.539540, 0.874990, 2.585220, 0.648420, -0.290910, 0.450480, 0.098360,
-0.850830, 0.937730, 0.555630, -0.392000, 0.104770, 0.271190, -0.407170, -0.598430, 0.991050, -0.064700,
-0.236790, -0.091070, 0.380120, -2.673050, 1.386270, 0.880730, 5.184830, 1.297430, 0.155470, -0.355660,
-0.718270, -0.608940, 0.622230, 0.281430, 1.012000, 1.030640, -0.684390, -0.583920, 0.449630, -1.227600,

-0.267970, -0.752160, -0.693740, -0.402810, 0.003720, 0.174850, 0.221210, -1.354940, -0.236870, -0.042970,
0.005450, 0.612450, -0.510700, 0.139620, 0.707000, -0.893920, -0.333330, 0.277170, 1.030360, -1.233450,
0.261040, 0.618970, 0.788860, 0.783890, 0.472060, -1.470400, 0.189530, -0.326120, -0.520900, -1.076810,
-0.022330, -0.369940, -0.138420, -0.514810, -0.083930, 0.862360, 0.303270, 0.890520, -0.881120, -1.173540,
-2.074190, -0.440770, 1.252050, 1.598360, -1.442240, -0.973650, 0.672480, -0.490250, -0.026280, -0.382520,
1.131300, -3.238200, -0.751220, 0.629300, -4.256290, -0.913020, 0.364770, 0.403710, 0.916800, 0.944040,

1.087040, -1.051880, -3.232070, 0.268070, 3.442540, -2.489060, -1.322250, -5.856230, -0.698500, 0.936920,
-0.931470, -0.255530, -2.422210, -0.523420, -2.208540, -0.054400, -1.547750, 0.981340, -0.520770, -0.973450,
-1.840310, -1.152850, -0.302560, 0.002750, 0.205690, -2.973310, 0.969130, -0.039750, -0.974900, -1.740520,
-1.930410, -0.483050, -0.476380, -0.206670, 0.320090, 0.651500, 0.389800, -0.684000, 0.873100, 0.041150,
0.757110, -0.734360, 0.508060, 0.626690, 1.279630, 0.979610, 2.238580, 1.883920, 1.648350, 0.060420,
0.124490, 1.435120, -0.517160, -0.249270, 0.893370, -0.152060, 0.100270, -0.376920, -0.744550, -2.301460,

0.170810, -0.153640, -0.364680, -0.226560, -0.774670, 0.624780, 3.230630, -0.183410, 0.449890, 0.896190,
-0.373620, -0.237760, 1.093140, -0.777100, -0.424690, 0.873370, -2.121190, -1.196310, -0.196470, 0.002330,
-0.532290, -0.375970, -0.481870, -1.003940, -0.753610, -0.972580, -0.237040, -0.085630, -0.286030, 1.710460,
-1.814950, 0.033090, -0.758560, -0.627630, 0.402340, 0.699550, -2.245600, -0.023100, -0.281400, -0.239240,
-0.163000, 1.043620, 0.070770, 3.381530, -0.336130, -3.643270, 2.404140, -0.276260, -4.182040, 0.361220,
-0.281670, 5.791670, -0.420410, -0.681530, 1.063150, 1.362730, 0.246610, -0.075980, 1.121120, -2.144060,

-0.589810, -0.663570, -0.019630, -0.361780, -0.691500, -0.030510, 0.851110, 0.228810, 0.883920, -0.609500,
-0.101730, -0.608110, -0.360720, 0.329190, -0.283930, 0.408560, 0.020410, 0.801680, -0.932870, -0.259590,
0.748980, 0.815910, 0.860150, 0.829000, 0.043370, -0.755830, -0.001420, 0.090270, -0.404860, -0.309750,
-0.666510, 0.120210, -0.870780, -0.861230, 0.820410, 0.478820, -0.287590, -0.676930, -0.653370, -0.895480,
-0.004830, -0.762040, -0.624120, 2.401160, 0.797020, -1.570390, -2.555360, 0.757890, -1.388320, -0.357400,
0.200560, -4.127080, 0.097460, -0.957180, -0.701950, -0.498610, 0.262790, -0.266510, 0.190370, 1.418690,

0.019250, -0.412850, -0.038380, 0.174710, 0.322520, -2.303620, -0.719030, -0.053890, -0.400800, 1.077560,
0.406500, -0.456800, -0.755120, -0.288200, 0.040890, 0.698280, -0.030280, 0.526510, -1.498230, -0.723560,
0.117660, 0.474740, 1.301240, 0.299520, 0.246410, -1.080110, -0.648350, 0.840100, -0.026790, -0.750860,
-0.120840, -1.103450, -0.025240, -1.128390, 0.619820, -0.758680, 2.626410, -0.350530, -0.502000, 0.182700,
-1.197510, 0.253800, 0.005850, 2.602350, 0.075690, -0.501230, -0.320610, -0.175930, -1.159250, 0.566750,
0.267260, 0.634850, -0.781780, -0.305820, -0.038590, 0.242040, -0.837660, 0.012860, -0.404510, 0.560720,

1.106180, -0.500670, 0.306100, -0.421200, -0.309310, -1.209340, -0.930710, 0.157960, -0.742920, 0.291000,
0.196240, -0.736240, -0.888370, -0.493230, 1.161490, 0.445990, -0.546470, 1.246260, -0.775590, 1.129400,
-0.711850, -0.104090, 1.109620, 0.204210, 0.403670, -2.162430, -1.428050, 0.623770, -0.508770, -0.346950,
0.089100, -0.576640, 0.145330, 0.818570, 0.317100, -0.620480, -2.458240, 0.619910, 0.694190, -0.254780,
-0.484650, 0.599530, -0.879720, -3.796180, 0.480730, -5.868540, 3.957680, 0.167790, -3.765420, 0.744390,
0.656970, 1.686740, -0.148400, 0.470690, -0.312770, -0.177480, -0.713870, -0.213170, 0.488830, -0.895220,

-0.387120, -0.057920, 1.005210, 0.248310, -0.566000, 0.635120, 1.728010, 0.890100, 0.394730, 0.468250,
0.643530, -0.063370, 0.718600, -0.310420, -0.966100, -0.123240, -0.189500, 0.259940, -0.230710, 0.360570,
-0.479850, 0.703270, -1.175550, -0.909640, -0.268460, 1.036270, 0.646210, -0.602290, 0.665330, 0.898220,
0.208820, -0.196940, -0.109020, -0.553930, 0.732250, 0.081620, 3.393530, 0.701910, 0.355760, -0.505160,
0.756240, 0.826990, 1.962050, 0.807180, 0.199290, 2.480830, -2.193950, -1.062600, -0.347900, 0.639070,
-0.341630, -2.068660, 0.042340, -2.003210, -0.439120, -0.905220, 0.331340, -0.427620, 0.306800, 3.919810,

-0.383110, -0.001160, 0.381990, 0.152210, 0.351530, -0.123610, 0.811470, 0.686370, 0.823210, 0.001730,
0.629320, -0.512920, 0.709940, 0.232470, -0.431870, 0.250120, 0.555700, 0.175790, -0.680370, -0.295720,
-0.162740, 0.155360, -0.576860, -0.451400, -0.149100, -0.805090, 0.575150, -0.265180, 0.223300, 0.429510,
0.114690, 0.658980, 0.155090, -0.573390, -0.084460, -0.559690, -0.550580, 0.659290, -1.076450, -1.435020,
0.452250, 0.330720, 1.629910, 2.825120, -1.839860, 0.931390, -1.481570, -0.716590, -0.932760, -0.204230,
0.622690, -0.291780, -0.204630, -0.550750, -0.943780, -0.585850, -0.497640, -0.870780, 0.679600, 1.033440,

0.498070, -0.866840, 0.195310, -0.170140, 0.621320, 0.618350, -0.448060, 0.686360, -1.385800, 0.692580,
0.259010, 0.619190, 0.707290, 0.932960, 0.109630, -0.042770, -1.088590, -1.529460, -0.235000, -0.473590,
0.024140, -0.177860, 0.278440, -0.645240, 0.698950, -0.613390, -1.171430, -1.468880, -0.266670, 0.010270,
0.495360, -0.272980, -0.725810, 0.734180, 0.293940, -0.529830, 0.913820, 0.289230, -0.191770, 0.822870,
0.060300, -0.939120, -1.715240, -1.328480, 0.572460, 0.313440, 2.347650, 0.683340, 0.702380, -0.986780,
-0.258030, -0.993640, -0.629950, -0.077470, 0.594060, 0.924990, 0.950800, 0.000220, 0.285830, -0.075540,

0.058820, -0.646730, -1.670680, 0.081520, -0.822500, 0.157150, 0.757460, 0.005400, 0.810930, -1.146370,
0.603270, 1.346090, 0.008710, -0.498770, 0.075830, -0.623330, -0.939700, 0.223210, -0.301200, 0.095700,
0.622360, -0.189830, -0.283040, -0.446390, 0.141070, -0.861670, 0.053810, -0.548240, -0.263310, 0.601390,
1.113130, -0.153900, -0.906400, -0.008040, -1.182560, 0.712200, -0.026660, -1.321460, -0.293410, -0.545700,
0.226460, -0.734230, -0.210440, -2.396770, -0.844950, 1.492990, 0.833220, 1.560880, 0.065790, -0.415520,
2.061260, 0.342970, -0.404960, -0.716020, 0.977070, -0.810810, -0.472800, -0.849140, -0.133390, 1.831470,

0.820270, 1.021420, 0.638900, -0.376390, -0.360210, 0.320330, 0.763210, -0.777070, 0.824780, -0.703640,
0.876850, -0.688300, -1.433640, -0.769820, -0.878270, 1.029030, -1.000470, -0.697990, 1.135220, -0.813130,
-0.134220, -0.255540, -0.594140, -1.364000, 0.471190, -0.738330, 0.135990, -0.555910, -0.184000, 1.300830,

-0.630550, -0.943810, -0.792320, 0.316880, 0.479170, 0.693010, -1.502140, -0.261720, -0.050670, 0.784720,
-0.550290, -0.556630, 0.759570, 0.229160, 0.155950, -0.886710, 0.886960, -0.068450, -1.193250, -0.227910,
-0.867740, 1.564600, 0.572740, -0.354980, -1.372150, 0.271960, -0.926030, -0.873610, -0.109330, -1.782540,

-0.455170, -0.341350, 0.644030, -0.903820, 0.491400, 0.105050, -0.738050, -0.013570, -0.307480, -1.009360,
-0.676540, 0.271510, -0.688970, 0.334150, 0.736060, -0.395630, -1.296280, 0.954260, -0.768380, -0.738330,
0.548140, -1.988380, 0.630820, 1.523250, 0.918120, -0.055370, -0.347250, -0.004010, -0.169540, -1.440900,

1.017330, -0.643720, -0.281110, 0.518280, -0.622340, -0.268480, 0.697190, -0.383390, 0.244940, 0.150730,
0.750930, 0.859490, -1.658780, -3.225180, -1.170090, 1.056240, -1.354470, -0.085980, 1.456990, -0.458900,
-0.240670, -0.826590, -0.224200, -0.257560, -1.094920, -1.220950, 0.104870, -0.147740, -0.729370, 0.701440,

0.216490, -0.630930, -0.185490, 0.340230, 0.692080, -0.682160, -2.500130, -0.080910, 0.884530, 1.027990,
-0.825910, 0.104110, -0.086730, 0.098550, 1.077690, -0.960390, 1.307900, 0.477990, -1.352760, -1.093890,
-0.841090, 1.378280, 0.396160, 0.709860, 0.756530, 0.812880, -0.620510, -0.884360, 0.628990, -1.768200,

-0.471870, -0.090160, 0.128140, -0.420130, 0.467120, -0.689380, -0.864480, -0.187690, -0.557940, -0.578270,
-1.216010, -0.032250, 0.493000, 1.772340, 0.155300, -0.591760, -0.949610, 0.196560, -1.347210, 0.224730,
1.038230, -1.445050, -0.194240, -0.253120, -0.354280, -0.080410, 0.902360, 0.314680, 0.313110, -0.504720,

0.504180, -0.687310, -0.441120, 0.278440, -0.536030, -0.883300, 0.726520, -0.395950, 0.003980, 0.168660,
0.926190, 0.964230, -1.557580, 0.779730, -1.035090, 0.939520, -1.083880, 0.423930, 1.392680, 0.437670,
-0.456320, -0.022090, 0.123050, -0.395560, -1.380440, -1.192490, 0.909350, -0.431130, -1.686620, 0.112810,

-0.394640, -0.655790, -0.008520, 0.844240, -0.042110, -0.378520, -1.381140, 0.282330, 0.451880, 0.750120,
-1.198760, -0.321780, -1.043110, -2.545050, 1.244810, -1.242820, 1.073810, 0.534470, -1.441410, -0.807080,
-0.787640, 1.357280, -0.125020, 1.350300, 0.846340, 1.018730, -0.111200, 0.457280, -0.407920, -2.046680,

0.078770, -0.172160, 0.630970, -1.139980, 0.040140, 0.571910, -1.130200, 0.281510, -0.886390, -0.690560,
-1.283150, -0.646160, 1.425630, -1.016160, -0.447220, -0.561370, -0.715960, -0.462630, -1.161530, 0.514110,
0.599120, -1.128060, -0.027130, -0.518780, -1.749630, -0.105180, 0.310510, -0.648860, 1.056700, 0.074900,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.207070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.680970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.293330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.106830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.362610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.772860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.968830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.168180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.681260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.232570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.382010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.882280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.799710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.672910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.681860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.066130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.208290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.165400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.460060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.219040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.413200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.484750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.402950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.848920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.190030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.714760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.883940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.325660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.692950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.994490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.075240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.065190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.575750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.468780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.965500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.386430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.201710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.217430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.575120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.771790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.390690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.696280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.324680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.225050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.287220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.507110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.207230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.063260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.081280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.304980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.345640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.892740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.263920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.887780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.985140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.033200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.454460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.951400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.183910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.590070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.755390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.881260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.478310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.394340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.782990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.003600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.420050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.427170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.729850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.351080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.083020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.919270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.549350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.246900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.542720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.290930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, -0.399360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, 0.339530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.437930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.131910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.648930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.218780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.637530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.688020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, -0.639060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.886790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.150230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.041330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.868710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.827020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.765170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.522730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.202150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.376510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.523100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.189980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.749500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.030730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.555070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.746240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.057640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.997170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.721030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.962610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.629780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, -0.514230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.370860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.931470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.871120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.618860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, -0.015780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, -0.559730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.152710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, -0.421940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, -0.357870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.477350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.652020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.996370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.910430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, -0.517650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.169100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.403250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.556310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.007820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.865940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, -0.213870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.041050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, -0.563720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.560980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.832410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.299560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.614610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, -0.577530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.267360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.892870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.566820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, -0.938650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, -0.111810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.647170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.864360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.819300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.054310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, 0.743390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.391130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.860380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.089820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.202870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.786610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.387090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, 0.677470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.479400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, 0.302540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.356310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, 0.154420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.453760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.870780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.323880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, -0.905170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.253920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, 0.236390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.702740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.245390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.289180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.948620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, 0.682760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.845960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.485270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.488030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.803690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.244700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.360940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.577130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.297070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.497370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.542710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.498160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.886440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, -0.726570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.459880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.097410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.351960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.730160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.406590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.360120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.666290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.752610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.299330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.853770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, 0.797090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, -0.492840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.222640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.683780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.664040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.254830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.514100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, -0.781570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.701620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.118660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, 0.715160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.313810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.383540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.309610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.787170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, 0.917420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.756530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.963090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.889950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.229550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.923750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.247050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, 0.051210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.436150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.121080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.214490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.632880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.106930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.945780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.056290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.430200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, -0.414550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.608640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.964840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.659200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, 0.146330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.790440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.465950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.761800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.552220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, 0.894510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.478100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.642710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.652260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (hid11) */
      0.0, -1.081330, 262,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (hid12) */
      0.0, 0.034270, 262,
       &Sources[262] ,
       &Weights[262] ,
      },
    { /* unit 235 (hid13) */
      0.0, -0.674200, 262,
       &Sources[524] ,
       &Weights[524] ,
      },
    { /* unit 236 (hid14) */
      0.0, -1.204250, 262,
       &Sources[786] ,
       &Weights[786] ,
      },
    { /* unit 237 (hid15) */
      0.0, 1.478150, 262,
       &Sources[1048] ,
       &Weights[1048] ,
      },
    { /* unit 238 (hid16) */
      0.0, -0.550310, 262,
       &Sources[1310] ,
       &Weights[1310] ,
      },
    { /* unit 239 (hid17) */
      0.0, -1.696710, 262,
       &Sources[1572] ,
       &Weights[1572] ,
      },
    { /* unit 240 (hid18) */
      0.0, -0.354340, 262,
       &Sources[1834] ,
       &Weights[1834] ,
      },
    { /* unit 241 (hid19) */
      0.0, -0.179420, 262,
       &Sources[2096] ,
       &Weights[2096] ,
      },
    { /* unit 242 (hid110) */
      0.0, 0.386510, 262,
       &Sources[2358] ,
       &Weights[2358] ,
      },
    { /* unit 243 (hid111) */
      0.0, 1.289210, 262,
       &Sources[2620] ,
       &Weights[2620] ,
      },
    { /* unit 244 (hid112) */
      0.0, 0.219480, 262,
       &Sources[2882] ,
       &Weights[2882] ,
      },
    { /* unit 245 (hid113) */
      0.0, 0.758210, 262,
       &Sources[3144] ,
       &Weights[3144] ,
      },
    { /* unit 246 (hid114) */
      0.0, -0.092630, 262,
       &Sources[3406] ,
       &Weights[3406] ,
      },
    { /* unit 247 (hid115) */
      0.0, 0.234540, 262,
       &Sources[3668] ,
       &Weights[3668] ,
      },
    { /* unit 248 (hid116) */
      0.0, -1.077600, 262,
       &Sources[3930] ,
       &Weights[3930] ,
      },
    { /* unit 249 (hid117) */
      0.0, -0.435660, 262,
       &Sources[4192] ,
       &Weights[4192] ,
      },
    { /* unit 250 (hid118) */
      0.0, 0.038600, 262,
       &Sources[4454] ,
       &Weights[4454] ,
      },
    { /* unit 251 (hid119) */
      0.0, 0.847120, 262,
       &Sources[4716] ,
       &Weights[4716] ,
      },
    { /* unit 252 (hid120) */
      0.0, 0.061260, 262,
       &Sources[4978] ,
       &Weights[4978] ,
      },
    { /* unit 253 (hid121) */
      0.0, 0.289660, 262,
       &Sources[5240] ,
       &Weights[5240] ,
      },
    { /* unit 254 (hid122) */
      0.0, -0.320240, 262,
       &Sources[5502] ,
       &Weights[5502] ,
      },
    { /* unit 255 (hid123) */
      0.0, -1.454700, 262,
       &Sources[5764] ,
       &Weights[5764] ,
      },
    { /* unit 256 (hid124) */
      0.0, -1.239260, 262,
       &Sources[6026] ,
       &Weights[6026] ,
      },
    { /* unit 257 (hid125) */
      0.0, 0.700600, 262,
       &Sources[6288] ,
       &Weights[6288] ,
      },
    { /* unit 258 (hid126) */
      0.0, -1.632550, 262,
       &Sources[6550] ,
       &Weights[6550] ,
      },
    { /* unit 259 (hid127) */
      0.0, -0.997170, 262,
       &Sources[6812] ,
       &Weights[6812] ,
      },
    { /* unit 260 (hid128) */
      0.0, -0.294750, 262,
       &Sources[7074] ,
       &Weights[7074] ,
      },
    { /* unit 261 (hid129) */
      0.0, 1.419810, 262,
       &Sources[7336] ,
       &Weights[7336] ,
      },
    { /* unit 262 (hid130) */
      0.0, -0.806610, 262,
       &Sources[7598] ,
       &Weights[7598] ,
      },
    { /* unit 263 (hid21) */
      0.0, -0.106550, 60,
       &Sources[7860] ,
       &Weights[7860] ,
      },
    { /* unit 264 (hid22) */
      0.0, 0.915450, 60,
       &Sources[7920] ,
       &Weights[7920] ,
      },
    { /* unit 265 (hid23) */
      0.0, 1.170550, 60,
       &Sources[7980] ,
       &Weights[7980] ,
      },
    { /* unit 266 (hid24) */
      0.0, -0.243120, 60,
       &Sources[8040] ,
       &Weights[8040] ,
      },
    { /* unit 267 (hid25) */
      0.0, -0.075570, 60,
       &Sources[8100] ,
       &Weights[8100] ,
      },
    { /* unit 268 (hid26) */
      0.0, 0.445580, 60,
       &Sources[8160] ,
       &Weights[8160] ,
      },
    { /* unit 269 (hid27) */
      0.0, -1.082420, 60,
       &Sources[8220] ,
       &Weights[8220] ,
      },
    { /* unit 270 (hid28) */
      0.0, 0.233510, 60,
       &Sources[8280] ,
       &Weights[8280] ,
      },
    { /* unit 271 (hid29) */
      0.0, -0.866260, 60,
       &Sources[8340] ,
       &Weights[8340] ,
      },
    { /* unit 272 (hid210) */
      0.0, -0.483750, 60,
       &Sources[8400] ,
       &Weights[8400] ,
      },
    { /* unit 273 (hid211) */
      0.0, 0.294880, 60,
       &Sources[8460] ,
       &Weights[8460] ,
      },
    { /* unit 274 (hid212) */
      0.0, 0.950510, 60,
       &Sources[8520] ,
       &Weights[8520] ,
      },
    { /* unit 275 (hid213) */
      0.0, 0.116530, 60,
       &Sources[8580] ,
       &Weights[8580] ,
      },
    { /* unit 276 (hid214) */
      0.0, 0.216430, 60,
       &Sources[8640] ,
       &Weights[8640] ,
      },
    { /* unit 277 (hid215) */
      0.0, -0.696960, 60,
       &Sources[8700] ,
       &Weights[8700] ,
      },
    { /* unit 278 (hid216) */
      0.0, 0.481770, 60,
       &Sources[8760] ,
       &Weights[8760] ,
      },
    { /* unit 279 (hid217) */
      0.0, -0.691730, 60,
       &Sources[8820] ,
       &Weights[8820] ,
      },
    { /* unit 280 (hid218) */
      0.0, -0.694030, 60,
       &Sources[8880] ,
       &Weights[8880] ,
      },
    { /* unit 281 (hid219) */
      0.0, 0.042700, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 282 (hid220) */
      0.0, 0.844930, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 283 (hid221) */
      0.0, 0.781910, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 284 (hid222) */
      0.0, 0.657040, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 285 (hid223) */
      0.0, 1.001660, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 286 (hid224) */
      0.0, 0.503430, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 287 (hid225) */
      0.0, -0.161460, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 288 (hid226) */
      0.0, -0.353670, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 289 (hid227) */
      0.0, 0.559790, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 290 (hid228) */
      0.0, 0.628690, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 291 (hid229) */
      0.0, 0.456160, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 292 (hid230) */
      0.0, 0.064660, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 293 (out1) */
      0.0, -0.956940, 30,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 294 (out2) */
      0.0, 0.520080, 30,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 295 (out3) */
      0.0, 0.658190, 30,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 296 (out4) */
      0.0, 0.749090, 30,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 297 (out5) */
      0.0, -0.569970, 30,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 298 (out6) */
      0.0, -0.164000, 30,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 299 (out7) */
      0.0, 0.415380, 30,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 300 (out8) */
      0.0, -0.526450, 30,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 301 (out9) */
      0.0, -0.188790, 30,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 302 (con11) */
0.03793, 0.500000, 2,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 303 (con12) */
0.00908, 0.500000, 2,
       &Sources[9932] ,
       &Weights[9932] ,
      },
    { /* unit 304 (con13) */
1.41981, 0.500000, 2,
       &Sources[9934] ,
       &Weights[9934] ,
      },
    { /* unit 305 (con14) */
0.02711, 0.500000, 2,
       &Sources[9936] ,
       &Weights[9936] ,
      },
    { /* unit 306 (con15) */
1.42222, 0.500000, 2,
       &Sources[9938] ,
       &Weights[9938] ,
      },
    { /* unit 307 (con16) */
1.42753, 0.500000, 2,
       &Sources[9940] ,
       &Weights[9940] ,
      },
    { /* unit 308 (con17) */
0.03509, 0.500000, 2,
       &Sources[9942] ,
       &Weights[9942] ,
      },
    { /* unit 309 (con18) */
1.42016, 0.500000, 2,
       &Sources[9944] ,
       &Weights[9944] ,
      },
    { /* unit 310 (con19) */
1.41710, 0.500000, 2,
       &Sources[9946] ,
       &Weights[9946] ,
      },
    { /* unit 311 (con110) */
1.33583, 0.500000, 2,
       &Sources[9948] ,
       &Weights[9948] ,
      },
    { /* unit 312 (con111) */
1.40221, 0.500000, 2,
       &Sources[9950] ,
       &Weights[9950] ,
      },
    { /* unit 313 (con112) */
1.42824, 0.500000, 2,
       &Sources[9952] ,
       &Weights[9952] ,
      },
    { /* unit 314 (con113) */
1.12510, 0.500000, 2,
       &Sources[9954] ,
       &Weights[9954] ,
      },
    { /* unit 315 (con114) */
1.41795, 0.500000, 2,
       &Sources[9956] ,
       &Weights[9956] ,
      },
    { /* unit 316 (con115) */
1.10076, 0.500000, 2,
       &Sources[9958] ,
       &Weights[9958] ,
      },
    { /* unit 317 (con116) */
0.00007, 0.500000, 2,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 318 (con117) */
0.00033, 0.500000, 2,
       &Sources[9962] ,
       &Weights[9962] ,
      },
    { /* unit 319 (con118) */
1.00022, 0.500000, 2,
       &Sources[9964] ,
       &Weights[9964] ,
      },
    { /* unit 320 (con119) */
1.42847, 0.500000, 2,
       &Sources[9966] ,
       &Weights[9966] ,
      },
    { /* unit 321 (con120) */
0.00005, 0.500000, 2,
       &Sources[9968] ,
       &Weights[9968] ,
      },
    { /* unit 322 (con121) */
1.42834, 0.500000, 2,
       &Sources[9970] ,
       &Weights[9970] ,
      },
    { /* unit 323 (con122) */
1.39104, 0.500000, 2,
       &Sources[9972] ,
       &Weights[9972] ,
      },
    { /* unit 324 (con123) */
0.00001, 0.500000, 2,
       &Sources[9974] ,
       &Weights[9974] ,
      },
    { /* unit 325 (con124) */
0.00076, 0.500000, 2,
       &Sources[9976] ,
       &Weights[9976] ,
      },
    { /* unit 326 (con125) */
1.40171, 0.500000, 2,
       &Sources[9978] ,
       &Weights[9978] ,
      },
    { /* unit 327 (con126) */
0.00000, 0.500000, 2,
       &Sources[9980] ,
       &Weights[9980] ,
      },
    { /* unit 328 (con127) */
0.00812, 0.500000, 2,
       &Sources[9982] ,
       &Weights[9982] ,
      },
    { /* unit 329 (con128) */
1.00822, 0.500000, 2,
       &Sources[9984] ,
       &Weights[9984] ,
      },
    { /* unit 330 (con129) */
1.42755, 0.500000, 2,
       &Sources[9986] ,
       &Weights[9986] ,
      },
    { /* unit 331 (con130) */
0.00038, 0.500000, 2,
       &Sources[9988] ,
       &Weights[9988] ,
      },
    { /* unit 332 (con21) */
0.13210, 0.500000, 2,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 333 (con22) */
1.42638, 0.500000, 2,
       &Sources[9992] ,
       &Weights[9992] ,
      },
    { /* unit 334 (con23) */
1.32472, 0.500000, 2,
       &Sources[9994] ,
       &Weights[9994] ,
      },
    { /* unit 335 (con24) */
0.06957, 0.500000, 2,
       &Sources[9996] ,
       &Weights[9996] ,
      },
    { /* unit 336 (con25) */
1.42450, 0.500000, 2,
       &Sources[9998] ,
       &Weights[9998] ,
      },
    { /* unit 337 (con26) */
1.31103, 0.500000, 2,
       &Sources[10000] ,
       &Weights[10000] ,
      },
    { /* unit 338 (con27) */
0.00112, 0.500000, 2,
       &Sources[10002] ,
       &Weights[10002] ,
      },
    { /* unit 339 (con28) */
0.75435, 0.500000, 2,
       &Sources[10004] ,
       &Weights[10004] ,
      },
    { /* unit 340 (con29) */
0.74179, 0.500000, 2,
       &Sources[10006] ,
       &Weights[10006] ,
      },
    { /* unit 341 (con210) */
0.03650, 0.500000, 2,
       &Sources[10008] ,
       &Weights[10008] ,
      },
    { /* unit 342 (con211) */
0.00325, 0.500000, 2,
       &Sources[10010] ,
       &Weights[10010] ,
      },
    { /* unit 343 (con212) */
0.32502, 0.500000, 2,
       &Sources[10012] ,
       &Weights[10012] ,
      },
    { /* unit 344 (con213) */
0.00443, 0.500000, 2,
       &Sources[10014] ,
       &Weights[10014] ,
      },
    { /* unit 345 (con214) */
0.01120, 0.500000, 2,
       &Sources[10016] ,
       &Weights[10016] ,
      },
    { /* unit 346 (con215) */
0.07804, 0.500000, 2,
       &Sources[10018] ,
       &Weights[10018] ,
      },
    { /* unit 347 (con216) */
0.00008, 0.500000, 2,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 348 (con217) */
0.00000, 0.500000, 2,
       &Sources[10022] ,
       &Weights[10022] ,
      },
    { /* unit 349 (con218) */
0.97745, 0.500000, 2,
       &Sources[10024] ,
       &Weights[10024] ,
      },
    { /* unit 350 (con219) */
0.00002, 0.500000, 2,
       &Sources[10026] ,
       &Weights[10026] ,
      },
    { /* unit 351 (con220) */
1.41387, 0.500000, 2,
       &Sources[10028] ,
       &Weights[10028] ,
      },
    { /* unit 352 (con221) */
1.41260, 0.500000, 2,
       &Sources[10030] ,
       &Weights[10030] ,
      },
    { /* unit 353 (con222) */
0.00000, 0.500000, 2,
       &Sources[10032] ,
       &Weights[10032] ,
      },
    { /* unit 354 (con223) */
0.25710, 0.500000, 2,
       &Sources[10034] ,
       &Weights[10034] ,
      },
    { /* unit 355 (con224) */
0.82346, 0.500000, 2,
       &Sources[10036] ,
       &Weights[10036] ,
      },
    { /* unit 356 (con225) */
0.00703, 0.500000, 2,
       &Sources[10038] ,
       &Weights[10038] ,
      },
    { /* unit 357 (con226) */
0.21679, 0.500000, 2,
       &Sources[10040] ,
       &Weights[10040] ,
      },
    { /* unit 358 (con227) */
1.38808, 0.500000, 2,
       &Sources[10042] ,
       &Weights[10042] ,
      },
    { /* unit 359 (con228) */
1.19519, 0.500000, 2,
       &Sources[10044] ,
       &Weights[10044] ,
      },
    { /* unit 360 (con229) */
0.86271, 0.500000, 2,
       &Sources[10046] ,
       &Weights[10046] ,
      },
    { /* unit 361 (con230) */
0.04695, 0.500000, 2,
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
