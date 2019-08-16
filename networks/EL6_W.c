/*********************************************************
  ELMAN268-30-30-9ENTROP6+weight.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:06:45 2004
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
  static UnitType Units[398];
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
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
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 338, Units + 339,
Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349,
Units + 350, Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359,
Units + 360, Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367,
Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278,
Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288,
Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298,
Units + 368, Units + 369, Units + 370, Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377,
Units + 378, Units + 379, Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387,
Units + 388, Units + 389, Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308,
Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318,
Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328,

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
Units + 293, Units + 362,
Units + 294, Units + 363,
Units + 295, Units + 364,
Units + 296, Units + 365,
Units + 297, Units + 366,
Units + 298, Units + 367,
Units + 299, Units + 368,
Units + 300, Units + 369,
Units + 301, Units + 370,
Units + 302, Units + 371,
Units + 303, Units + 372,
Units + 304, Units + 373,
Units + 305, Units + 374,
Units + 306, Units + 375,
Units + 307, Units + 376,
Units + 308, Units + 377,
Units + 309, Units + 378,
Units + 310, Units + 379,
Units + 311, Units + 380,
Units + 312, Units + 381,
Units + 313, Units + 382,
Units + 314, Units + 383,
Units + 315, Units + 384,
Units + 316, Units + 385,
Units + 317, Units + 386,
Units + 318, Units + 387,
Units + 319, Units + 388,
Units + 320, Units + 389,
Units + 321, Units + 390,
Units + 322, Units + 391,
Units + 323, Units + 392,
Units + 324, Units + 393,
Units + 325, Units + 394,
Units + 326, Units + 395,
Units + 327, Units + 396,
Units + 328, Units + 397,

  };

  /* Weigths definition section */
  static float Weights[] =  {
0.545550, 0.130190, 0.408310, 0.932460, 0.333180, -0.325180, -1.006630, 0.204640, 1.273540, -2.776360,
-0.175520, 0.170990, 2.263190, -0.262760, -0.303840, 0.164300, 0.278060, 0.958570, 0.343870, -1.335120,
0.080280, 1.644950, 0.155310, 0.990210, -1.721830, -1.023250, -0.299260, 1.387530, 0.329750, 2.849720,
-0.782450, -1.689260, -0.156010, 0.858560, -0.638450, 0.595370, -0.644410, -0.776760, 0.332690, -0.113800,
-1.101600, -0.612350, 0.368590, -1.352300, 0.614920, 0.915820, -2.076890, -0.734910, 1.022380, -0.264000,
-0.617460, -0.505250, -1.115060, -1.029190, 1.321300, 1.086410, -0.402690, 2.029940, -0.739730, -1.329950,
-1.303970, 1.536030, 1.073740, 0.557890, -0.616350, -0.939110, 0.390220, 1.286360, -1.565180, 0.333840,
-0.954400, 0.031690, 0.562570, -0.739050, 1.055680, -0.496780, 1.080520, 1.780170, -0.769480, -1.474970,
0.771390, -1.145350, 0.453900, -0.614100, 0.113200, 0.867750, -1.374040, -0.396330, 0.558100, -1.214200,
0.874020, 0.612330, -2.753270, -3.224160, -0.051450, -1.859300, -1.400080, 0.073950, 1.235510, 0.434180,
-1.566160, -0.155890, 1.069420, 1.003210, 2.057190, 1.601860, -1.862140, -0.571760, 0.823830, -0.976860,
0.240830, 1.882860, -2.471890, -1.262730, -1.332630, -2.838420, -0.621690, -0.294180, 0.612780, -1.064810,
1.622220, -0.105870, -0.535200, -2.453390, 2.409840, 0.519000, -1.781930, 1.168450, -0.333080, -0.552850,
0.527850, 2.336910, -0.729440, -0.507740, 0.675920, -0.016680, -4.359960, -0.351090, -3.000750, -3.666650,
0.330080, 1.076600, 0.606850, -0.617500, -0.050570, -1.184180, -0.859550, -0.089910, 3.735620, 0.156830,
-0.310190, -3.727090, 0.871360, 0.603470, 1.042600, 0.858630, -1.543250, 0.609190, -0.808020, -0.097600,
-0.225620, -0.348210, -6.780760, 0.459670, 4.449380, 0.072650, -0.050180, 0.233280, 0.744980, 0.660040,
0.666430, 1.888230, 1.098380, -0.119760, -1.388030, -0.334030, 1.584340, 1.019880, -0.799140, 0.761980,
2.755150, -1.815160, 0.016780, 3.836200, 0.140800, -3.323160, 3.123630, 1.152840, 1.377190, -0.511720,
-0.735090, -1.028350, -0.704560, -0.753800, -0.052090, -0.734930, 0.172070, -2.680980, -0.183400, 0.110690,
0.774680, -1.057890, -0.712990, 1.255380, -0.855840, 1.035450, 0.553210, -0.271680, -4.382030, -2.943360,
2.163450, -0.028330, -1.119350, -0.299870, 0.176510, 1.071100, -1.486560, 0.432250, 1.024830, -0.606770,
0.540820, 2.050910, 0.949780, 0.831060, -0.609950, 0.453620, -0.437510, -0.627740, 1.173790, -0.377190,
3.638440, -0.878090, -0.398520, 1.131360, 0.861550, -0.802420, 0.338210, 0.729270, 1.290530, -0.210550,
-2.506440, -0.565130, 1.564550, -0.107650, -0.559870, 1.136740, 0.572180, 0.903310, 0.488730, -1.929450,
0.924150, 2.145830, 1.193680, -0.405580, -1.792720, -0.243300, -0.401790, 1.055700, 0.299300, -1.831800,
0.135220, 2.813900, 0.755330, -1.608880, -0.319350, -2.249800, 0.822450, 0.702650, -0.081920, -0.141120,
0.534040, 0.395780, 1.177130, 0.780850, 1.924240, -0.249900, 1.146400, 1.272500, 0.434310, 0.281060,
2.636030, -0.189080, 0.093570, 1.027420, 0.112770, 0.107160, 0.276000, -0.138940, 0.937670, 1.144650,
0.398480, 1.293270, 0.031910, 1.846620, 0.014150, -0.089030, -0.063690, 0.166040,
0.329550, -0.456200, 0.383870, 0.831120, -0.849330, 1.867590, 0.735660, 0.332200, 0.313430, 1.658000,
-1.597840, -0.470790, -0.088290, 0.025680, 0.923500, 0.038550, 0.264050, -0.247620, -0.428860, 0.543090,
-0.621300, -0.271520, 0.385960, 0.209370, -0.728610, -0.013250, 1.602380, 1.032720, -0.300980, 0.054770,
-1.015340, -0.604530, -0.443160, -1.737710, -0.877020, -1.103070, -1.559560, 0.670590, 1.209530, 1.170350,
0.746200, -0.154520, 0.082660, -0.199570, -0.009000, 1.010500, 0.206260, 0.675270, 0.948810, 2.033580,
1.716980, 0.920580, 0.439090, -1.072860, 1.982600, 0.804920, -2.772170, -0.882750, 1.389090, -1.481670,
0.249140, -0.737930, -0.738750, 0.392370, 3.635850, 0.913340, 0.729330, -2.087110, -0.153270, 0.258360,
2.077570, -0.353040, 0.567250, 1.022900, -0.173300, -0.695010, 0.803290, 1.631700, 1.893360, -2.013480,
-0.446810, 0.435050, -0.807400, 0.305620, -1.072360, 0.319000, 0.633830, -1.437490, 0.955790, 2.080820,
-0.527170, 1.278580, -1.574260, 1.648840, -0.234290, 1.714100, -0.741580, -0.483250, -0.817420, -0.717220,
0.177040, 0.806310, -0.204850, 0.844090, -1.437880, -0.787300, -0.488430, 0.255870, -0.601280, -0.369780,
1.117340, 0.491430, 0.576230, -0.363710, -0.250960, 1.282180, 2.215990, 0.179190, 0.218400, -1.939440,
0.173810, 0.226650, -1.813950, -0.657080, -0.747150, -1.702810, -0.807820, -1.358640, 1.699920, 0.085990,
0.274010, -0.866650, -0.017670, 1.908050, -0.236590, -0.016810, 0.486070, -0.816070, 1.965940, -2.678200,
1.879320, 0.703550, 1.527550, -0.818760, -1.076550, -2.209390, 1.770980, 0.216010, -2.547860, -1.275260,
-0.447730, 1.203430, 0.278660, -1.743480, -0.994860, 1.523440, -1.727240, 0.214800, 3.449910, -0.108450,
-0.969120, 1.168080, 0.588400, -0.512400, 0.925800, -0.072710, 1.167560, 0.151050, 0.350340, 1.760680,
2.368060, -0.278330, 0.346960, 0.384790, -0.410090, 0.241930, -0.878390, -0.588010, 0.241670, 1.775990,
-0.012100, 1.483050, -0.941050, 1.409670, -0.719000, 2.368060, -0.751960, 1.098670, -0.155660, -1.070390,
0.286860, -1.312100, -0.599310, 0.660880, -0.968080, 0.785150, 0.151890, -0.940090, -0.029460, -1.583150,
-0.826970, 0.540910, 1.361360, 0.704220, -0.399660, -0.704340, 0.162760, -1.830750, -1.212970, 0.623790,
-1.850170, 0.953340, 0.702100, -0.555380, -1.128190, -1.250920, -0.248940, 0.095840, -1.605350, -2.073660,
-0.547300, 0.756990, -0.488520, -1.998770, 0.390950, 1.056630, -0.424660, -0.643010, 0.614800, -1.157620,
2.334740, 1.086620, 1.811810, 2.404700, -0.013170, -0.162720, 0.383500, -0.786950, -0.166920, 2.032350,
-0.589070, 0.704790, 0.147030, -1.159020, -0.466710, 0.727370, 2.034620, 2.378880, 0.112870, -2.256770,
-0.156290, -0.548460, -1.096170, -0.458640, -0.395080, 0.701620, -1.138970, -0.701940, 0.560050, 0.314640,
0.495390, -0.855770, -1.824280, -0.490090, 0.032090, 0.293260, -0.849080, -0.641590, -0.307610, 1.386270,
-1.255810, 0.101210, -1.784510, -1.620100, -0.603200, -0.970560, 0.397940, -1.074900, -1.056100, -0.376810,
5.458980, -0.475940, -3.131350, -0.716870, -1.050050, 0.603860, -0.210910, 0.010460, -3.068400, 0.553980,
-1.237080, -0.853670, -0.492860, 1.243290, -0.331560, 0.586440, -0.987080, -1.129520,
-1.535400, 1.489150, -0.252600, -0.937110, 1.797140, -1.326870, -0.787810, -2.521210, -0.218960, 0.865640,
0.884440, -0.395150, -0.562620, -0.016330, 1.355350, 1.043530, 0.689900, -0.529390, -0.486340, 1.171450,
-0.125280, 0.012590, 0.949700, 0.147850, -0.355950, -0.547590, -3.480120, 0.378760, 0.507150, 5.030770,
1.393800, 2.230420, -1.515640, -0.864670, 2.163060, -0.429540, -0.538030, -1.383590, 0.665690, -1.028710,
-1.407820, 1.177090, 0.471720, -1.056830, -3.399910, 0.167690, 0.968830, -0.444850, -0.661950, 4.099050,
-0.388120, 0.498940, -0.915570, -0.481890, -0.805570, 1.105620, -1.628360, -1.148440, 1.577610, -2.826390,
1.092590, 1.773450, 0.278710, -1.320460, 1.542080, -1.066000, -0.987790, 0.231700, 0.443010, -0.400740,
-1.132080, 0.741430, -0.213430, 1.188790, 0.639720, -0.811780, -1.706040, -0.162820, 0.819430, -0.550490,
0.229310, -0.249970, 0.396130, 0.246260, -0.602230, 0.032160, -0.082410, -0.539810, -0.667120, -1.586650,
-0.999650, 0.749940, 2.325440, 3.663240, 2.159430, 3.395200, 0.465360, -0.470010, 0.397640, -2.262980,
2.176610, 0.969460, -1.759090, -1.256770, 0.823650, 1.248340, 0.464220, 0.374140, -0.761050, -0.267960,
3.893170, 1.984300, -1.450660, -0.252990, -0.409330, 3.805000, 4.065980, -2.432510, -0.782820, -0.271390,
-0.290840, -3.113380, -1.135440, 3.392830, -1.682980, -11.563880, -1.295070, -0.274380, 1.198650, -0.851950,
-1.733480, 0.424960, -1.635530, 1.799260, 1.430010, 1.722500, -0.822900, -1.811800, 0.036390, -1.457960,
-1.071700, 0.958650, -0.527160, 1.066050, 0.156750, 1.910020, 0.370030, -0.963590, -8.810610, -0.464170,
0.194310, -0.155210, -1.108660, -1.330630, 0.278090, 1.010690, 1.827970, -0.375760, 1.805160, -0.379730,
1.327980, 1.071310, 0.549000, -0.171110, 3.974890, -0.441980, 0.278790, 0.830710, 0.649170, -1.145890,
0.946000, -2.283540, 0.448780, 0.830760, -0.318620, -1.119020, -1.700300, -0.768920, 0.112000, 3.169300,
0.428910, -0.395320, -0.811480, -0.669010, -0.608080, 0.145060, 0.840810, 1.225640, 1.286700, -0.527530,
0.252460, 1.049120, -1.565370, 0.818950, -1.855530, -1.979710, -0.067450, 0.075410, 1.383850, -0.050190,
-0.155800, -0.469400, -0.083100, -0.836410, 0.664390, -2.222090, -1.161520, 1.237770, 0.787830, -0.137190,
1.357160, 0.409580, -0.153400, 2.018060, -0.893250, 0.151640, -0.223710, -1.461470, 1.987650, -1.278070,
-3.061740, -0.130290, -1.557260, 0.158210, 0.330080, 0.556640, -0.377200, -0.250850, 0.304950, 0.223140,
-1.090790, -0.354100, -2.824160, 0.589710, 1.620610, 0.243780, 0.820470, -0.097720, -0.590110, 0.316710,
-0.700280, 0.512070, 0.082720, -1.449270, -1.263810, -1.035420, -0.863770, -0.864380, 0.673650, -0.601080,
0.423920, -0.791560, 1.069830, 0.884500, -0.086900, 1.265080, -1.526720, 1.162850, 0.643180, 1.497290,
1.080750, 0.057700, -0.072980, 1.308220, 2.008470, 0.072630, 2.453260, 2.234780, 0.893600, 4.964300,
0.055470, 0.859190, -0.885790, -0.390230, 0.743800, 0.848920, 1.151920, 0.395930, 0.195920, 0.755050,
19.042870, 0.122360, -0.869800, 1.070520, 0.120970, 1.106800, -0.083030, 0.097390, 0.879310, -0.048370,
0.262160, -0.455670, 0.987350, 3.987780, 0.651080, 2.128900, 0.438030, 1.379910,
0.854200, -0.773340, 0.948270, -0.346720, 0.696150, 0.524820, -0.040380, -2.810080, 0.682540, -1.335620,
-0.048700, -0.143600, 0.372980, 0.567490, 1.762680, -1.234230, -0.995960, -0.898820, 1.116050, -0.099150,
0.375990, -0.651320, -1.955560, -0.700960, 0.503760, 1.171550, 0.606600, 0.698950, 0.053350, -0.188900,
-1.186370, 0.905110, -0.284750, -0.599080, 1.003320, 0.019880, 0.555620, -0.314320, 0.462090, 0.094240,
1.623830, 1.635710, -1.809950, -0.984490, -1.089960, 0.690760, -0.488980, 0.541030, -1.001510, -0.189640,
-0.029730, 1.808030, -0.818530, -0.239630, 0.771030, 1.357150, -3.026120, -0.719370, -0.273430, -0.844910,
1.146180, 0.308660, -0.506040, 0.292230, 1.925980, 0.548010, -0.216510, -1.711030, -1.133560, 0.532820,
2.560720, 0.777330, -1.541300, 0.540220, 0.232260, 0.820290, -1.771500, -1.360700, 1.704600, -2.375060,
-0.480890, -1.433610, -0.493180, -0.889390, -0.279420, 0.396340, -1.504770, -0.848940, -5.222060, 1.138580,
0.233590, -2.524100, 0.447220, 1.224820, 0.112090, 3.992710, 2.820150, -0.560130, -1.763320, -1.126000,
-0.662730, 1.620310, -3.796710, 0.814980, 0.272180, -0.491230, 0.019310, 1.096880, -0.992400, -1.919190,
6.935360, -0.649450, 1.237500, 0.723320, -0.797510, 0.566320, -1.250130, -0.622470, 1.067780, -1.762120,
0.162510, -0.491040, -1.589550, 1.309550, -1.317430, -1.285210, -1.552070, 0.391700, 0.682190, 1.124750,
0.080300, -0.454360, 0.506190, -0.214270, -0.055830, 2.724740, 0.391580, 0.587460, 0.012160, -1.073640,
-3.688370, -0.298520, 0.894660, 0.323900, 1.352040, -1.661730, 0.808080, -0.631160, -3.041010, 0.345200,
-0.075910, -1.656400, -0.020900, -0.913760, -0.799570, -0.636530, 3.977770, 1.887700, 0.033600, 0.818860,
-0.373260, 0.481360, 2.611440, 0.165370, 1.655760, -0.806530, 0.388060, 1.173750, -2.136330, 0.477410,
-2.092110, -6.118410, -1.293390, -0.001600, -0.042110, 0.423320, -0.589010, -0.189880, 2.605230, 0.472380,
0.867080, -0.098460, 0.256480, -0.597770, -1.420680, 1.917540, 1.890080, -0.875990, 0.084120, 0.222720,
-0.400340, -0.551870, 0.454430, 0.511900, -4.774800, -1.777600, 2.355200, -0.173580, 1.593230, -0.077670,
-1.263550, 2.449220, 1.402650, -0.152100, 0.402000, 0.535580, 0.530800, -2.478410, 3.320460, 1.736990,
1.435300, 0.481800, -1.861810, -0.314160, -0.295780, 0.014030, 0.819360, 1.276880, 0.960150, 0.251370,
-0.330830, 0.347990, -0.283230, -0.572830, 1.326850, 0.954900, 0.710860, 0.095250, -0.229150, -2.200200,
1.245650, -0.390250, -0.474770, 1.644380, -0.022770, -0.032440, 0.464740, -1.687960, -0.072890, 2.888900,
-0.113360, -0.132470, -1.089610, -1.879600, 0.695910, 0.208820, 0.093200, -0.195570, -0.491410, 0.886620,
-0.987180, -1.206380, -0.691410, 1.117350, 0.310940, 1.412580, -1.609070, 0.521350, -1.496760, -0.228060,
-1.731680, -0.235800, 2.659750, 0.189470, -3.334280, 1.538390, -0.330060, 1.146250, 0.566280, -0.417220,
-0.334990, 0.384610, -0.296520, 0.688150, -0.671910, 0.078210, 1.276950, 0.377690, -0.473500, 0.338240,
0.875310, 0.315760, -0.369470, 0.527970, 0.882050, 0.811990, -0.690150, 0.746250, 0.344850, -0.161770,
0.535160, 0.296680, -0.707530, 3.426470, 0.044560, -0.758460, 0.283090, -0.607610,
0.372050, 0.522290, 0.638790, -2.413340, -2.160730, -0.459540, 0.707940, 0.241570, -3.232870, -0.354170,
0.274130, 2.335390, -0.918440, 1.692110, -0.773240, -0.506140, 0.759810, 0.135070, 0.636710, 1.103640,
-1.255150, -0.756800, -1.287350, 0.409100, -1.158520, 0.784510, -0.088390, 0.248800, -0.151240, 1.900010,
0.308050, -2.662520, 1.064870, 0.746380, 0.941190, 0.142520, -1.038490, 1.182980, 0.786930, 2.378370,
-0.047580, -0.213040, 0.302730, 0.630820, 0.206640, -0.544670, -3.231220, 2.550990, 0.381850, 0.464720,
-0.288510, 0.029160, -1.805100, -1.567330, 0.658970, -0.352860, 1.423320, 0.545070, 1.209060, 0.077380,
-0.081430, 0.968100, 0.448000, -1.165820, 1.036220, -0.299210, 0.458900, -0.360580, -2.215850, 0.401430,
1.037020, -0.181550, -0.201360, 1.060420, -0.178700, 1.003590, -0.794390, -1.429100, 1.266520, 0.878200,
0.073840, 0.186720, -2.885910, -0.560420, 2.034850, 0.542640, 0.231870, -1.752160, -0.128610, 0.860460,
0.856460, -0.273120, -0.710710, -1.912270, -0.222600, -1.106820, 0.721540, 0.375980, -0.772070, 0.483430,
-0.473760, -0.683170, 1.208810, 0.647430, -1.756100, 0.263490, 1.082680, 1.055710, -1.762220, -0.506020,
-1.491650, -0.662320, -0.432450, -1.138800, -2.603560, 0.686280, 4.428620, -1.323660, -0.109210, 0.280680,
-0.311060, -1.132680, -2.025700, -0.767170, 0.011880, 0.633350, 0.419880, -0.967060, 3.348840, -0.977500,
-0.758300, 0.233460, -1.834120, 0.070430, -1.863930, 0.437850, 0.401440, -2.490810, 1.682700, 1.176490,
-1.689480, -4.090850, -0.058610, 1.501210, 0.296500, -0.563660, 2.171500, -1.009780, -2.427350, 0.263260,
0.098620, 4.849560, 1.366020, 0.033970, -2.462140, -1.767760, -2.306620, -0.391740, 0.365770, -1.073280,
-6.504020, 1.339090, 10.142310, -0.557750, -4.913660, -0.791410, 0.787590, 0.335680, 0.691320, 1.863850,
-3.876830, -1.833260, -0.166330, 0.671080, 5.505390, -0.809310, 1.311090, -0.844890, -1.863530, -2.382640,
-1.200530, 0.474460, -1.096790, -5.354670, 0.702080, 6.151950, -1.684590, 0.190360, 3.021300, -0.338310,
-0.201790, 1.592300, -0.134650, -1.383620, -1.859900, -0.447450, 0.901750, 1.329220, -0.480960, -1.788470,
0.140680, 0.264220, -3.103920, -0.768000, -0.400870, -1.579200, -2.286130, -1.257530, 2.806430, -3.006610,
-3.358120, 0.575210, 1.625940, 1.701040, 0.857340, 0.064900, 0.589570, 0.412510, -1.673350, -0.090210,
1.587150, -0.216300, 0.932810, -2.990890, 3.140040, 0.704180, 0.503030, -0.200860, -0.656780, -1.138400,
-0.244790, 0.638520, -1.132110, -3.257930, -0.961430, 0.624150, 1.354510, 2.511710, 0.506320, 0.110140,
1.075730, -0.983720, 0.492740, -0.162460, -0.860380, 4.814530, 0.381480, -1.771230, 1.004340, -0.527430,
-0.451870, -1.121650, 0.866300, 0.397310, -0.647310, 0.070450, 1.022310, -0.926560, -1.802500, 0.384270,
0.057870, -0.694850, 2.272420, 1.144680, -0.002570, 0.135200, -0.222290, -0.423520, -0.705390, 0.368680,
-0.488230, -0.090250, 2.102870, -1.956500, 0.280660, -0.233380, -5.081720, 1.369610, -0.366180, 0.388540,
-1.204130, -0.055010, -0.076140, -1.283700, -1.304960, 0.846090, 0.999420, 0.287370, 0.113120, -0.309170,
2.199650, -1.699850, -0.126080, -1.105150, 0.811150, -0.272520, 0.507140, -0.082930,
-0.279860, -0.115180, 0.676710, 0.472190, -0.362170, 0.178040, -0.646200, 0.472690, -0.420400, 1.205360,
-0.109160, -0.739510, -0.966240, 1.354970, 0.145140, 0.613260, 0.347260, -0.150210, 1.079290, -0.142720,
0.876120, -0.470860, 0.775140, 0.823510, 0.864580, -0.555670, -0.523270, 0.662780, 1.512670, -0.468040,
-0.668930, 2.719440, -0.051020, 0.537930, -1.174470, -2.292420, 0.493930, 0.013990, 2.547400, -0.570950,
-1.296020, 0.654410, -0.285570, 0.503430, -0.294390, 1.046780, 0.006990, 0.677720, 0.853420, 1.996560,
-0.636790, -0.164450, 0.211910, -2.013660, 2.837610, -0.846370, -0.076700, -1.048700, -0.307940, 0.481240,
0.670460, 0.320910, -0.724450, 0.896750, 0.190990, -0.442250, 0.084150, 0.059290, -0.302060, 0.454170,
1.077640, 0.292060, 0.463710, 0.180760, 1.110390, 0.402310, -0.403120, 2.230130, 0.683940, -0.342720,
-0.108080, -0.684730, 1.349350, 2.934440, 0.503690, -1.066350, 1.693330, -1.009280, -0.167980, 0.249470,
1.112200, -0.787930, -0.016510, -0.699970, -0.325300, 0.916350, -1.711700, -1.012080, 0.321400, -1.721270,
-0.606330, 1.244220, -0.751990, 0.211710, -0.012550, 0.947350, -0.559130, -1.382120, 0.415810, -0.487860,
-0.057130, 1.171980, 0.263560, -0.062230, -1.160450, 0.944620, -0.784240, 0.482440, -0.496080, 1.088270,
0.970600, -0.591170, 0.218350, -0.772630, 1.601630, -1.398550, -0.142370, -0.066660, 0.598010, 0.241440,
0.731600, 1.027220, 0.052740, -0.025760, 0.388370, 0.423640, -0.092770, -0.782490, -1.558230, -2.394780,
-1.084110, 1.205780, -0.432990, 0.026980, 1.354860, -1.835620, -0.804460, 0.424560, 2.469920, -0.357240,
1.437490, 0.412730, -0.548110, -0.239110, -0.622040, 0.086350, 0.096890, 0.463350, -0.348330, -0.786490,
-0.132990, -1.410110, -2.974760, 0.005540, 0.698750, -1.028860, 0.009640, 0.603900, -1.657940, -2.765330,
-0.505460, 1.310480, 0.541210, -1.138530, -1.640370, -0.006700, -0.481950, 0.848710, 0.916310, -1.467040,
1.494150, -0.422160, 0.367480, -0.926870, -0.845300, -0.205920, 1.305570, -1.131530, 0.596870, 0.353480,
0.297950, 0.487690, -0.370820, 0.631550, 4.755080, -0.279980, 0.092340, 0.471650, -0.006910, 0.355280,
-0.476360, -0.108790, -0.871740, 0.132410, -1.145170, 0.547860, 1.516780, -0.873140, -0.021500, -0.198260,
-1.338660, 2.819650, -0.616140, 0.761640, 0.037290, -0.772840, -0.224860, 2.218750, 0.707320, -0.294110,
-0.199310, 0.869490, 0.480040, 1.243990, 0.360650, -0.786860, 0.553070, -0.097340, 0.605660, -0.264480,
-0.408340, 0.054190, 0.405550, -2.133890, -0.267610, 1.333230, 1.174900, 0.454990, -0.729980, 0.001410,
-0.672610, 0.755730, -0.113180, -0.070540, -0.009660, 0.409090, 1.000810, 0.219420, -1.392830, -0.937490,
0.858470, 0.724840, -0.015370, 0.405300, 1.822550, 1.624700, 0.211830, -0.244950, 0.380390, 1.026440,
-0.006620, -0.901850, 1.941780, -0.446180, -0.101450, -0.301000, -1.262400, 0.948530, -0.747800, -4.720160,
-1.002960, -1.798610, -1.373140, -1.630900, 0.053890, -0.864680, -13.407760, -0.541650, -0.731150, -1.228160,
0.444600, 0.246510, -0.997520, -0.967630, -0.155890, -0.988130, -0.423420, -1.081990, -0.057020, -1.512100,
-1.295660, 0.263850, -3.214770, -1.635790, -1.761950, -0.112190, -0.767100, -2.081040,
-0.496280, -0.672060, 0.189860, -0.402260, -0.057900, 0.129200, 0.286900, 0.600280, 4.371460, -0.001830,
-2.027970, -0.419160, 1.302340, 1.206270, 1.596910, 1.623330, -0.265010, -1.812020, -0.066040, 1.238500,
-1.554020, -0.379480, -1.223640, -0.413670, -3.610990, -0.700410, -1.159500, 0.211490, 0.781230, 0.938120,
0.484520, 0.310000, -0.633790, -1.676490, 0.408190, 0.564210, 2.166490, 3.808300, 0.911540, 0.456130,
-0.083200, -1.233170, 2.616300, -1.107500, 0.365560, 0.375930, -1.579570, -0.272980, 0.598870, -0.699000,
0.255370, -0.468240, -0.148930, -0.824560, -0.145340, -0.886360, 0.095510, -0.661780, 0.271210, 1.718080,
-1.108520, -0.654430, -1.464680, -1.905180, -0.237520, -0.661640, -2.218830, 1.272650, -0.618810, -0.095050,
-1.257900, 1.174430, 0.107710, 0.924930, 4.129560, -0.996730, 0.366170, 3.546920, 3.253360, -0.367150,
-1.325720, 4.218630, 0.032220, -0.166910, -0.256330, 0.477040, 2.366280, 1.185020, 0.758730, -1.724590,
0.172400, 0.618840, -1.735470, -0.836200, -0.208120, 7.712310, 1.617460, -1.550470, -0.524170, -0.087530,
-0.311880, -0.236130, 1.167870, 1.144040, 0.609040, -0.311420, -0.027500, -0.666360, 1.264780, -1.357030,
0.219980, 1.383110, -0.637250, -0.249450, 1.403530, -0.889490, -3.786360, 0.542680, 4.849190, 0.051060,
-0.341820, -0.990630, -0.360960, -1.707620, 2.150180, -0.810050, 2.040870, 1.699720, 1.577730, -0.631920,
0.255470, 1.209630, -0.425450, 2.288430, 1.648400, -0.931390, 0.241110, 3.619080, -1.828130, -1.040340,
1.812990, 4.036860, 1.160130, 0.781280, -0.064660, 0.090630, -1.434530, -0.844090, -2.219920, 0.057290,
1.709520, 0.915710, -0.900560, 0.553770, -1.394540, -1.102950, 2.863040, -0.470430, -0.894110, -0.834350,
-0.442600, 0.709890, -5.038860, 0.858800, 3.821940, -0.002420, -1.103170, 2.153470, 0.399740, 0.269140,
-0.291240, 0.171090, 1.999070, 2.766760, 1.694320, 1.880520, 2.171730, 2.217760, 0.669760, 3.482740,
4.127580, -4.391440, -0.310390, 1.265110, 2.473250, 0.284350, 2.052680, 2.973750, 1.640780, -0.475550,
-0.469430, 0.013780, -0.162890, 1.241400, 0.575330, -0.708540, 0.440590, 0.103190, -0.416220, 0.656310,
0.266090, 0.631110, 1.095160, -1.138610, -0.853070, 0.582940, 0.515570, 0.761150, 1.608410, 0.072390,
0.198540, -0.698680, 2.194620, -1.598540, -0.850260, 0.031840, -1.377240, -3.204450, 0.003220, 0.808390,
1.026020, 0.603700, -0.305860, -0.585440, 1.210590, 0.801620, 0.239650, 0.586390, 0.991820, 0.573430,
1.457840, -1.818270, 0.497760, 0.758790, 2.587700, -0.186840, 0.840020, 1.177410, -1.202960, -0.375130,
0.658470, -0.016550, -0.347610, 0.197040, -0.964370, 0.362620, -0.436570, 1.063520, 1.584830, 0.717470,
-0.155770, -0.600630, 0.257820, -0.213500, -1.133880, -0.331200, -0.209140, -0.360180, 1.755930, -1.401400,
0.015100, 0.563600, -0.284730, -0.850800, -1.451070, 0.131110, -1.973600, -1.652970, 0.945280, 3.262210,
0.145180, 1.138680, 0.786490, 0.375910, -0.401290, -0.176720, 0.373180, 0.859910, -0.776610, 1.445310,
3.925940, 0.893620, -0.970500, 0.276610, 0.001550, 0.860330, -1.654900, -0.915120, -0.318370, 0.008080,
-0.267470, -0.319390, 1.378960, 6.229000, 0.748110, -0.001570, 0.284990, -0.480220,
0.557540, -0.664160, -0.280510, 3.472740, 1.358360, -2.349040, -0.698840, -0.327680, 1.029510, 0.553190,
-1.137880, 1.482660, 0.611240, 1.010230, -0.224420, 0.169060, -0.767160, 1.734070, -0.136610, 1.379990,
0.253060, -0.968370, 1.530810, 0.614050, -0.522530, 0.696820, 0.648810, 1.628920, -0.472900, -0.843920,
-0.321990, 1.577100, 0.666960, -1.558400, -0.870430, -0.543550, 1.258820, -0.609570, -1.682070, 0.412360,
0.355880, -1.094240, -1.624650, 0.372930, -0.482120, 0.977390, -1.394960, -0.990100, -0.672670, -2.508380,
-0.881510, 0.136190, 1.601490, -0.363600, -0.095150, -0.053900, -0.082610, 0.037290, 1.243630, 0.679050,
0.703170, 0.289530, -0.849740, -0.295560, -1.186370, 0.187600, -1.123380, -0.042240, 0.737200, 0.268860,
-0.632200, 0.245190, 1.236900, 0.677050, -0.312970, 0.029270, 0.714410, 0.553850, 0.722140, -0.528750,
0.103200, 0.009660, -1.075680, 0.451540, -0.277870, -1.020710, -0.159950, -1.415630, 1.048210, -1.092160,
0.338020, -0.325500, 0.533690, 0.916220, 1.111170, -0.943340, 0.999040, 1.477900, 1.933560, -1.553840,
0.952470, 0.274990, 0.076490, 1.023250, 0.817450, -1.262530, -1.148560, -2.445640, 0.080050, 0.903360,
0.171290, 0.461990, 0.476510, -1.023390, -0.240270, 2.151470, -3.793420, 0.717330, 3.392430, 2.035280,
0.101250, -1.511710, -0.638220, 0.082480, -0.836630, 2.668600, -0.658430, 0.458340, 2.708590, 0.873530,
-0.095720, -1.123600, -0.344050, 2.574190, 0.244880, -0.982490, 0.203230, 1.777460, 1.059990, 3.143600,
-0.483300, -1.481140, -0.595350, 0.125200, 1.651570, 2.193600, 1.828060, -2.013370, 0.244010, -0.370220,
-0.004360, 4.184940, 0.877150, 0.878730, -4.344520, 0.728940, -0.682030, -0.557250, -0.240950, 1.104620,
-0.783660, 0.179810, 5.781070, 0.069370, -3.376160, 2.171960, 0.118530, 0.088110, 0.152830, -0.185860,
-2.815160, 0.469860, -0.824040, 0.611400, 3.922150, -0.840470, -0.330990, -1.702770, 1.249330, -0.456340,
0.350970, -0.011580, 0.095210, -1.646270, 0.184420, 4.788980, -2.931260, -3.136180, 0.903610, 1.056680,
1.374170, -1.760000, 0.045920, -0.589890, 1.183620, -0.329120, 0.844770, -0.399050, -3.735380, 0.547950,
0.482070, 0.227570, -0.219730, -0.268780, 0.764760, 0.644960, 0.460500, -0.881570, 5.545180, -2.295320,
-1.022790, 0.183830, 0.379340, 1.051820, -0.069050, 0.269740, 1.405930, 0.801480, 1.103270, 0.263720,
-0.076380, 0.916400, 0.360100, 0.587050, -1.996450, -0.511730, -0.659930, -0.732750, -2.543670, -0.310450,
-0.001810, -0.103870, -0.109080, 2.580020, -1.235940, -0.376510, 0.965120, 0.055970, 1.170590, -0.691070,
1.530950, 0.366150, -0.702610, -1.419680, 1.527400, -0.252250, 1.035350, 0.920380, -2.563380, -0.648180,
-1.584340, -0.285600, 0.907900, -0.290290, -1.110900, 1.397190, -0.366190, 2.570810, 0.797320, 0.553500,
-0.090750, 0.337960, -0.989440, 0.498680, 1.235770, 0.073570, 0.250200, 0.182020, 0.645230, -0.475810,
0.651580, 0.709410, -1.073570, 0.713460, 0.382550, -0.051330, -5.256080, -0.962900, 1.452430, -0.948110,
-1.947160, -0.360440, -0.268640, 1.692340, -0.424840, -0.704460, 0.594600, -0.043560, 0.061060, 0.363340,
-0.930010, -1.450400, 1.184130, -0.959060, -0.471960, 0.800930, -0.793380, -0.079460,
-1.764290, -0.226770, -1.782160, -0.883190, -0.385720, 1.552110, 0.647990, 0.089890, 0.985050, -0.185900,
-0.768520, -0.117470, 1.082940, 0.444990, 0.572240, -1.340190, -0.691130, 0.663440, -0.104380, 0.030420,
0.544190, -0.519340, -1.002250, -0.147690, -0.161810, 0.607390, -2.043020, -0.912300, -0.061090, 0.804460,
0.191090, -0.682430, -0.035610, -0.194740, 0.405960, -0.676890, 1.990740, 0.234770, -0.487930, 0.105660,
0.214350, -0.229010, -0.433170, 0.675830, -0.921410, -2.280860, 0.284560, 0.034280, 0.333510, -0.880750,
1.068540, -1.291520, 1.267080, 0.152440, 0.995260, 0.161120, -0.052790, 0.058350, -0.694500, 0.324100,
-0.126990, -0.226910, -0.960190, -3.135930, -2.525750, -0.425990, 0.452850, 0.932500, 0.471280, 0.408290,
-0.137000, -1.631230, -0.469090, 0.211600, -1.292380, -0.446090, -0.538360, -0.468490, -1.340280, 0.116300,
0.219450, -1.866320, 1.478270, 1.152420, -0.354330, -0.978940, -0.613120, -0.454730, -0.111910, -0.301060,
-0.481220, 0.469180, 1.132220, 1.404880, -1.422840, -0.916850, 0.062400, 1.540660, 0.603100, 0.528600,
0.946180, -3.377290, -1.518200, 0.708220, -0.681130, -0.289760, -0.146750, -0.216140, -0.954290, -1.210790,
-0.677660, 0.519400, -2.090110, -0.952500, -1.678480, -1.672460, 0.970470, -2.788820, 0.786330, 2.321300,
0.608210, -0.746270, 0.688190, -0.584020, 0.569700, -0.559750, -0.634560, 0.220950, -0.725640, 1.482780,
-0.270960, -0.988680, -0.823060, 0.738880, 0.445700, -0.180910, 0.484870, 0.469370, 0.187030, 3.688010,
0.122370, 0.341180, 1.979950, 0.708140, -1.080780, -0.886850, 1.065980, 2.447320, -1.342070, 0.653310,
1.338080, -0.840370, -0.230750, -0.360300, 0.253260, -0.653830, -0.019960, -0.318590, 2.791910, 0.052950,
-2.586910, -0.827840, -1.759410, 3.118700, 1.488460, 0.206940, 0.348980, -0.413500, 0.954980, 2.709830,
0.550970, -1.123470, -0.968680, 0.458330, 0.118950, 0.748720, 0.933550, -0.366900, -0.666490, -0.015480,
0.867290, -1.272530, -1.668490, -0.012870, 0.307880, -1.138350, 0.346220, 2.318160, 0.495310, -0.529640,
-0.337220, -0.499790, -0.461220, -0.450490, 0.830730, 0.864540, 0.327430, -1.913300, 1.635360, -0.379080,
0.728340, -0.850360, -0.774320, 1.325380, -4.604600, -0.228110, 1.179100, -0.052040, -0.336920, -0.141060,
3.861180, -0.033690, -2.031070, 0.288820, -2.251420, -0.204230, -0.201530, -0.999030, -0.729400, -0.347520,
-2.131470, -0.193700, 0.340320, -0.807120, -0.076720, 0.683460, -0.033910, 0.422530, -0.650080, 0.444060,
0.262130, -1.239520, 1.079930, 1.970740, 0.384960, 0.739240, -2.174430, -0.295970, 0.552630, 0.403350,
-1.417120, 0.541620, -0.858680, -0.960380, -1.215920, -0.435020, 0.497160, 0.878510, -0.194110, -0.447690,
5.090990, -1.812750, -1.473340, 0.060360, -0.744780, 0.236820, -0.259860, -0.486790, -0.178220, 1.575510,
-0.263880, 0.472910, -0.185970, -0.867900, 0.562410, -1.447300, 0.871990, -0.413470, -1.878560, 0.738240,
-0.251140, -0.659100, -0.811650, -1.758920, -0.931950, -2.352290, 0.381360, -1.458600, -0.901970, -1.177240,
-1.891410, -2.972850, -3.331450, -2.659880, -0.804310, -1.153950, -1.375030, 0.241030, -0.294490, -0.533940,
-1.040660, -4.594260, -1.806780, 1.233660, -1.029850, -0.516870, -0.693730, -0.689200,
1.772490, -0.382580, -0.119650, -1.862070, -0.246900, -1.737880, -0.778310, 1.735340, -0.501440, 0.069490,
0.601540, -0.342170, 0.308970, -0.135070, 0.332750, -0.253130, -0.167140, 1.058050, 0.262070, -0.631630,
0.979510, 0.494080, -0.442180, 0.855350, 0.180720, -0.838860, -4.198200, 0.651980, 0.310690, 1.942990,
0.799870, -0.582480, -0.191530, -0.861340, -1.469710, 0.670830, 0.469860, -1.117000, 0.413750, -1.053070,
1.129900, 0.900300, -0.176730, -0.992790, 3.300330, 0.632780, 0.211140, -2.644160, 0.063850, -2.930400,
0.869970, 0.096950, 0.246570, 2.265840, 0.714160, -0.652440, 1.544630, 0.435650, -3.671930, -0.479540,
-0.110820, -1.091750, -1.868980, 0.674040, 1.057090, -0.304540, -0.013300, 1.178280, 0.437070, 3.383490,
-0.425010, -0.869730, 0.568040, -0.927360, -0.512140, -0.801530, 1.087770, -0.186350, -1.325530, -0.598040,
0.173690, -3.375370, -0.093180, -1.887890, 0.292930, -0.310100, 0.107190, -0.080850, 0.754440, 0.868440,
0.251200, -1.524830, 0.400960, -0.393400, 1.477440, -0.810640, 1.368870, -0.929940, -0.932650, 0.958080,
0.077110, -0.462160, 3.211320, -0.033890, 0.887040, 1.127320, 1.348250, -0.067620, -1.609240, 0.484160,
-0.232450, -2.024380, 0.733780, -0.517290, -1.684160, -1.482140, -1.008450, 0.592860, -1.231260, -1.533210,
-2.787780, 1.711610, -0.595790, -0.352960, 0.300110, 1.617510, -0.486020, -0.714500, -1.832150, -1.612390,
1.580230, 0.520040, -1.260970, 1.129190, 0.787210, -0.279040, 0.699720, -1.479740, -1.451140, -0.559360,
-0.051460, -4.457080, 0.789220, -0.830870, 0.189240, 1.285460, -1.566490, 0.274800, 2.419240, 0.212660,
-0.730890, -0.398940, -0.438660, -1.658300, 1.639780, -1.188310, -0.941680, -1.326110, 0.954830, -0.319670,
-1.194620, -0.278720, 0.304750, -1.153780, -5.349690, 1.279060, 2.185180, -1.000400, 1.850180, -1.251850,
0.072120, 0.634700, -0.955250, 1.631340, 2.748420, 1.215770, 0.090830, -1.709600, 1.598920, -0.795310,
0.896030, 2.304740, -0.739620, -1.897390, -3.468600, 1.361530, 0.014080, -3.526330, -0.501310, 0.995380,
-0.445450, 2.808030, 0.204700, -0.983590, 0.735680, -0.237570, -0.097620, -1.711130, 1.546270, -0.507600,
-1.603120, -1.212760, -3.093330, -0.447510, -0.954580, -0.239310, -1.498380, -1.286830, 6.882280, 2.392110,
-1.038570, 0.670220, 1.108300, -0.028940, 4.107290, -0.390520, 0.705450, 0.002410, -0.846250, -0.215790,
1.072760, 0.164320, 1.192800, -3.389650, -1.527390, -6.694250, -5.593990, -0.556260, -0.230140, -1.096370,
-1.391910, 3.057450, 1.546360, -1.955220, -0.115330, 1.873420, -0.827580, 3.099100, 1.750390, -0.603650,
1.173760, -0.279530, -0.609440, -0.530260, -0.966920, -1.112020, -2.107230, 1.405640, -3.063160, -0.545940,
-1.151440, 0.217110, -0.739020, 1.762690, -0.971620, -0.291680, 1.125540, -1.664410, 0.600010, 4.049570,
-0.259440, -0.226470, -1.975120, 0.526140, 0.383280, -0.255750, -1.020580, -1.118060, -0.087010, -3.006840,
-0.250090, -0.799710, 0.926850, 1.539020, 0.805100, 0.546700, 0.237940, 0.006520, -0.399040, -1.060800,
-17.447969, 0.260150, 0.182910, -1.431820, -0.695680, -1.148770, -0.314320, 0.309960, 1.601890, 0.908130,
0.518750, 0.729570, 0.047030, -0.623480, 0.133510, 0.802750, 0.197990, -0.502050,
-0.401500, 0.456950, 0.602160, 0.117810, 1.774000, 1.552520, 1.141890, -0.269140, -1.002010, -0.286260,
-1.074460, -1.862120, -0.781840, -0.204700, 0.011600, 1.165130, -0.975710, 0.520980, -0.790290, -0.459480,
0.088810, 0.947230, -0.550620, 0.218770, -0.904810, 0.306330, 1.475990, 0.032510, 1.781290, 0.502760,
-2.523300, -1.354170, 0.926120, -0.256600, -0.236650, 1.293750, -1.586160, 0.763210, -0.118300, 0.117240,
0.671250, -1.394940, -1.031860, -0.345890, -1.111350, 0.975710, -1.952710, -1.159360, 1.866780, 0.523690,
-0.489930, -0.461640, 0.321220, -1.425520, 0.795880, -0.746460, -1.273090, 0.126750, -2.097760, -1.781060,
0.801500, -1.656850, 0.381480, -0.672890, 0.725770, -1.237170, -0.825760, 0.443430, 1.197760, 1.834330,
4.845450, 2.586660, -1.467020, 0.287700, 0.741630, -0.401360, -0.366070, 0.206460, 0.164830, -5.936590,
0.533660, 0.135610, 1.871870, -0.580500, 0.305830, -1.021550, 0.767930, 4.047340, -1.169390, 0.183560,
-1.086930, -0.911160, 0.456480, 6.797030, -3.822250, -1.112830, 1.232140, 0.535590, -1.229390, -1.425680,
4.307940, 0.387480, -3.775920, 0.277680, -2.045750, 2.651370, 2.572260, -3.514220, -1.353360, 4.739290,
-1.658750, -0.311680, 1.573320, -1.405010, -1.225950, 2.132330, 6.430940, -0.397680, 2.073260, -0.256770,
-1.116010, -1.530920, 0.269490, 0.952680, -0.230510, -5.965440, 0.041680, -0.114280, 4.000290, 0.237790,
-2.158620, -1.355740, -0.983350, 0.932490, -1.437380, 1.790030, -0.150580, 0.509860, 1.050270, 5.247760,
-0.995610, -1.064260, -0.641520, -0.805910, 1.363840, -1.619820, -1.128020, -4.148860, -0.574600, -0.191840,
-2.092400, 2.625370, 0.131220, -1.129660, 0.426710, -0.130100, 2.389870, 0.312060, 0.058180, -0.324110,
-0.689600, 0.558950, 2.879470, 0.105200, -3.830050, -0.200770, -0.580890, 2.225100, -1.383020, -0.108580,
-1.108780, 0.759720, 0.638440, -0.204170, 0.978900, -0.265930, 0.004320, -1.685500, 0.699210, -1.959770,
0.812960, 0.258440, 0.085460, -1.022790, 0.402100, 0.414320, 1.213740, -0.998980, -0.869800, 1.837610,
0.393500, -0.018850, 1.551250, 2.154830, -1.792660, -1.775520, -0.294320, -0.914950, -1.050280, 0.343090,
0.918130, 1.232130, -0.457350, -1.255080, 0.876310, -2.601940, -3.429280, 1.582200, 1.227270, 0.001210,
-1.578680, -0.767360, -0.391310, 1.121570, 0.280090, -0.271830, -0.063050, 0.573120, -3.644160, 0.779540,
-0.312200, 0.345690, 2.391270, 1.820550, 0.296760, -0.808220, -0.126070, -1.024270, -2.582080, 0.326780,
-0.539350, -0.879490, 1.022180, -1.490790, 0.096700, -2.542300, -0.024400, 1.938370, 0.511910, -0.915630,
0.432990, 1.867040, -0.339550, -0.877680, -0.189170, 0.141890, -1.143010, -1.796740, -0.793320, -0.647760,
-0.867320, -0.175220, 0.342210, 0.650550, -0.074930, -0.623530, -2.350250, -0.696380, 0.591650, 2.072130,
1.088890, 2.102080, 0.734500, -1.285610, 1.648190, 0.056780, 0.125250, -0.395890, -1.059710, 1.633060,
0.314990, -1.070910, 0.174370, -1.604390, -1.458920, 0.083780, -2.052750, -0.299680, 0.052760, 0.713920,
0.421980, 0.349980, -0.740290, 1.734270, -0.129880, -0.061810, -0.128630, -1.307100, -0.510620, -0.951880,
-1.064710, -2.418970, 0.151820, 0.577270, 0.389240, 0.164650, 0.655110, -0.109860,
0.189100, -1.381380, -1.956080, 3.510090, -0.646710, -0.442250, 1.183960, -1.025530, -0.710010, -0.325680,
-0.406830, 0.333790, 0.270890, -0.728670, -1.409290, 0.021720, -1.040890, -0.776790, 1.489640, -0.850830,
0.393920, -1.759910, -0.785420, -0.798690, -1.467690, 0.535790, 1.338400, -1.559910, 0.975940, -1.514830,
-0.839880, -0.971660, -0.435360, -0.459350, -0.589480, 1.538500, -2.009080, -0.697890, -0.372740, -0.064740,
-1.255750, 1.981200, 1.815100, -0.143610, -0.581330, 0.350470, -1.136300, -0.259020, 1.222160, 1.737710,
-0.169160, 2.882290, -0.268510, 0.907230, -0.792080, 0.917600, -1.090770, 0.661120, 1.924330, -1.076620,
-0.242480, -1.214490, -0.243300, 0.419780, 1.538990, 2.885850, -2.182690, -1.028010, -1.349630, -0.263350,
-0.129400, -0.518980, 4.186010, -0.302050, 0.439760, 0.567140, -2.396140, 2.087940, 0.050020, -2.719960,
-0.763050, 0.342740, -0.640560, -1.457280, 0.721480, -0.064690, -0.665000, 1.420200, -0.058410, 0.382500,
-1.870810, 0.338620, 0.973780, -0.040910, 0.558730, -1.721530, -2.909400, 0.882780, -2.157860, 2.026410,
1.821430, -0.907160, -4.129730, 1.055580, 0.875580, 0.517400, -3.607510, -0.015170, -0.410150, -0.623900,
0.079250, 2.241340, -0.183610, 1.009930, -0.178290, -0.342990, 1.719070, -0.566130, 1.497770, -1.234190,
-0.123310, 0.071800, 2.242470, 0.184910, -0.627260, -5.229280, 0.873160, 1.598980, -0.507150, -0.633320,
0.144430, -0.709870, 0.077220, 3.707470, 2.910910, 1.199930, 1.721060, -0.030470, 0.849360, 0.331450,
2.329460, 3.608960, -0.994890, -0.816960, -2.707110, -1.229100, -0.527750, -0.546740, -6.150780, 0.103370,
1.022710, -0.348750, -0.397750, -1.577700, 0.483250, 0.213480, 1.975490, 0.002540, 1.493210, -0.411040,
1.117580, -0.484010, -1.050300, 1.383340, -0.427730, -2.554230, -0.249110, -0.595090, -0.452000, -0.356080,
2.301410, -5.080980, -0.490050, 0.021910, 0.678220, 0.529910, 0.510820, 1.149460, 0.926010, 4.254400,
0.988270, 0.093620, 0.722500, 0.086070, -1.266280, 0.580270, 1.512680, 3.958960, -0.065930, -0.366680,
1.824860, 0.685930, 1.082600, -0.014110, -0.081800, 0.349410, -3.808810, -0.687230, 0.036970, 0.464310,
-0.655790, -0.126330, 3.492580, 1.991000, -0.473350, -2.544070, 2.252270, 0.168200, -2.835380, -2.388760,
0.638700, 0.662870, -0.822320, 0.795720, 0.186860, -0.742770, 1.392990, -6.263670, 1.083700, -2.190850,
-1.293990, -0.868890, -0.893720, 3.022630, 0.670290, 1.889260, 1.147580, 0.428490, 0.522500, 1.009470,
-2.704780, -2.097800, 0.420850, 4.384780, 1.985250, 1.771360, 0.374170, -7.070080, -1.709860, 0.110310,
-1.152890, 0.937890, -2.651530, -1.847700, -0.066290, 1.646280, 0.976250, 1.711690, 1.800640, 0.478360,
-0.946650, 0.011140, 1.277260, -1.261410, 1.864250, -2.545510, 1.953500, 0.658330, 1.140480, 0.795220,
0.123530, -0.904680, 0.481130, -0.952660, 0.320880, 0.128910, -3.068920, -1.512710, -0.930650, 1.173360,
0.591090, 0.500120, -1.447160, -0.983230, -0.249610, 0.685520, 3.846650, -0.893290, -0.943740, 0.204760,
2.930460, 0.182340, -0.153380, -0.747330, 0.864940, -0.551720, -0.578410, 0.381560, 0.618530, 0.440220,
0.109680, -0.282110, 0.313490, 0.999970, -0.873190, 0.312930, 0.658810, -0.292920,
0.336150, 1.008210, 0.251260, -0.478790, 1.159560, -0.803110, 1.098980, 0.078630, -0.589170, -0.343960,
0.559070, 0.009510, -0.070400, 0.580270, -0.276420, 0.223230, 0.228740, -0.305400, -1.072700, -0.129530,
1.488800, 0.084580, -0.013640, 0.122970, -0.282090, 0.077690, 0.133650, 0.806620, 0.491970, -0.788660,
0.723780, -0.299050, 1.821770, -0.303760, 0.408690, -0.624150, -0.322420, -0.294400, -0.426750, 0.383050,
0.194790, -0.215190, -0.654930, 1.884130, 0.393020, -0.180470, -0.928150, 0.168860, 0.002710, -0.262940,
0.155780, 0.959770, 0.648500, 0.370110, 1.570110, -0.440760, 0.373080, 0.467440, -0.691290, 0.754660,
-0.282520, -0.173830, 0.487710, -0.252000, -0.208040, 0.467370, -0.335240, -0.249600, 0.162010, -0.648820,
0.833240, 0.170950, 0.993600, -0.829590, 0.535860, -0.648460, 0.080810, -0.518170, -0.515120, -0.033470,
-0.294580, 0.374710, -0.582300, 0.347100, 0.074640, 0.129250, -0.899550, 0.031830, 0.082520, -2.329560,
-0.098980, -0.457000, -0.058530, 0.396990, 0.066340, 0.075010, 1.235930, 0.976640, 0.240120, -1.350730,
0.824580, 1.078740, -1.525750, -1.034480, 1.171460, 0.243320, 0.347900, -0.639200, 0.966660, 1.002610,
0.302780, 0.486650, 2.230470, -0.046480, -0.952190, 0.613700, 0.039720, 0.546120, -0.732030, -1.119970,
0.590480, -0.279330, -0.189660, 2.097700, 0.869130, 0.308760, -0.164070, 0.007930, -0.289800, -1.491320,
0.882430, -0.021760, 1.260770, 0.208890, -0.725520, 0.926820, -1.337890, -0.710460, 0.260390, -0.325370,
0.146450, 0.055100, -1.122370, -0.089420, -0.358020, 0.649210, -0.741120, -0.578140, -0.621840, -0.001710,
-0.097490, -0.749490, -0.387930, 0.913690, 0.827760, -0.587020, 1.177450, 0.687140, -2.657890, -0.352640,
-0.304970, 0.031620, 0.210410, -0.458640, -0.512760, 1.142680, -0.655060, -0.146370, -0.059290, -1.496290,
-1.019850, -0.385460, 0.313530, -0.831780, 0.760470, 0.278930, -0.049550, 0.565390, -0.634480, 0.671250,
0.803690, -0.348400, 0.623080, -0.516290, 2.498440, 1.220300, 1.084090, -1.350570, 1.067030, 0.747390,
-0.323500, 0.267860, -0.198080, 0.827320, 0.674260, 0.162380, 0.413510, 0.572760, 0.074460, -1.171680,
0.681430, 2.207580, -0.905840, 0.324050, 0.695310, 0.101730, -0.187380, -0.073600, -0.233640, 0.675900,
-0.195320, -0.115660, 0.675360, -0.294400, -0.777480, 0.626780, -0.263870, 0.284250, 0.127880, -0.438810,
-0.238550, -0.184520, -0.415300, -0.481240, -0.396460, 0.247560, 0.106480, 0.692860, -0.920810, -0.733580,
-0.573120, 0.126400, -0.110350, 2.229190, -0.412430, -0.328150, 1.123570, -0.829190, -0.726920, -1.259020,
-0.827050, -0.008530, 0.328700, -0.862610, -0.396940, 0.556440, 1.096740, 0.112130, 1.955450, 0.747410,
-0.642330, -0.480590, -0.861220, 0.653790, 0.091870, 1.375130, 0.407100, 0.229080, 0.398310, 1.370070,
0.492070, -0.140640, 0.546470, -1.049390, -1.540970, -2.611480, 0.050950, 0.168010, -0.946200, -0.170040,
-0.385500, -0.820840, -0.069410, -1.949230, 0.102830, -2.633910, 2.275070, -2.142300, -1.285000, -1.465060,
-0.856620, 0.214550, -2.275560, -1.047200, 0.300020, -0.807920, -3.207110, -0.532230, -1.724970, -0.936970,
-1.261310, -1.445010, -0.201210, 0.464000, -1.661440, -1.319010, -0.901980, -1.178430,
-0.013210, -0.367930, 0.545850, -0.249700, 0.193110, 0.406660, -0.333860, 1.108260, -0.367440, -1.885330,
0.398520, 0.052510, -1.642750, -0.384690, 0.810730, 0.618030, 0.096050, 0.459150, -1.086680, 0.684050,
0.562050, -0.179120, -0.843640, 0.106410, 0.177130, -0.111390, -0.446010, 0.120930, 0.322810, -0.385340,
-0.422520, -0.005900, -0.196930, 0.182170, 0.527870, 0.225280, 0.764180, -0.248510, -0.881010, -1.087240,
2.911350, -0.198340, -0.918340, -0.282120, -0.387630, 0.102620, 0.339750, 2.442480, 0.257430, -1.156830,
1.107720, 0.374310, -0.463300, 1.077710, 1.560450, -1.362210, 0.521430, 0.036750, 0.718560, 0.179590,
1.749310, -1.199330, -0.639590, 1.328870, 1.815980, 0.666770, -0.577210, 0.314940, -0.520510, 0.076630,
0.413050, 0.063840, -0.686270, 0.513000, -0.596920, -1.013260, 0.829680, -1.101440, -0.855680, 0.391370,
0.907890, 1.062970, 1.464210, 0.748020, -0.099140, 0.027030, -0.682680, -0.969400, 0.380280, -1.935490,
-1.577450, -0.598730, -2.125590, -0.395710, -0.459110, 1.901940, -0.836560, -0.371940, 1.316860, 0.661540,
-0.906020, 0.900570, -0.402490, 0.628760, 1.190270, -0.619890, 0.797250, -0.308790, 0.293330, -0.246050,
0.027690, 1.163420, -1.964660, -0.564760, -1.995520, -3.903270, -2.009310, 0.308610, 4.319410, 0.237090,
-3.535250, -1.478740, -0.472060, -3.514450, 2.422660, 4.303680, -0.059150, -1.625410, 0.728690, -0.029350,
1.260360, 5.388640, -1.151130, 0.570240, 0.045270, 0.453190, -3.503220, -0.017690, -4.020320, -3.655380,
0.695980, 4.240190, 0.382560, 1.144770, 0.502710, -1.644260, -1.692340, 3.892110, 1.095130, -0.880610,
1.536970, -3.527160, -0.835440, 0.256410, 3.279430, 1.425800, -1.116180, -2.800930, 1.185320, 1.034440,
3.467240, -0.868560, -5.980450, 1.401240, 4.115510, 2.062240, -1.206790, 0.248140, 1.788910, -2.324410,
1.739560, 0.484440, 0.286400, 0.745350, -5.557450, 0.779900, 0.362080, 1.582820, -1.440350, 0.848030,
0.943060, -2.735600, 0.396000, 1.009580, 0.509760, -5.309140, 1.376450, 1.736580, 1.194210, -0.848940,
1.654430, 0.596130, -0.942610, -0.643400, 0.019770, -0.425840, 1.032510, -1.630480, 1.507850, -0.234940,
1.287410, -1.317840, 0.765070, 1.632800, 0.115650, 0.838960, 0.580350, 0.733950, -0.358300, 0.430190,
1.665200, 0.619410, -0.801850, 1.448030, -1.066320, 0.764550, 0.346140, -1.832720, -1.478050, 0.635230,
-0.910220, 0.643240, 1.212900, 0.621980, 1.187160, 1.814940, -0.204320, 0.566720, 2.668160, 0.871030,
0.634310, -2.503020, 0.677920, 1.524560, 1.080120, 0.147000, 1.708660, -0.654970, 0.757710, 0.290970,
-1.701870, 0.228630, -0.030680, 0.206060, -0.314850, 1.441300, 0.352490, 1.063510, 0.632930, -1.399830,
0.227160, 2.175570, 1.248350, -1.947980, -0.446370, 0.030320, 0.060920, 0.907560, 0.409460, 1.259660,
-0.541080, 0.874620, -0.506180, 1.512970, -0.660450, 0.980400, 0.866480, 0.956220, 0.973350, 0.493740,
-0.999320, -0.934340, -0.897890, -0.079430, 0.221190, 0.640370, 3.167400, 0.613660, -1.346680, -0.133210,
0.437240, -0.745180, 0.885920, 0.856410, -0.422930, 1.781410, 0.120240, 0.946300, 0.111200, -0.162690,
-0.352100, -0.530790, -0.554100, -0.768080, 0.465170, -0.989160, 0.723040, -1.382270,
-0.136230, -0.213500, 1.626110, -0.510920, -0.596440, 0.977840, 0.143970, 1.352120, 1.003940, -0.769720,
0.214520, -1.461090, 0.645820, -1.634540, -0.833190, 1.590110, -0.241830, -2.613440, 0.194710, -0.770400,
0.403930, -0.432800, 0.569770, 0.152190, 0.787550, 0.390680, -0.395280, 0.436420, 0.461600, -0.991620,
-0.878280, 0.545660, -0.882600, 2.280770, 0.055710, -0.169070, -1.530660, -0.249510, -0.848870, -0.272830,
2.159490, -0.630020, 0.098460, 0.348520, -1.124370, -0.508110, -0.123080, 2.159180, 0.484750, 0.282900,
3.555020, 1.011540, 0.239600, 0.127340, -0.886000, 0.520330, 0.159700, 0.709130, 1.064190, -0.107650,
0.814650, -0.435320, 1.288180, 0.084960, 0.024300, -0.266950, -0.096390, -0.026590, -2.059750, -0.116300,
-0.919910, -0.245260, -0.675430, 0.275720, 0.830030, -0.551400, 2.387420, 1.164280, -0.151070, -0.915140,
2.376940, -1.174160, 0.977240, 3.068700, 0.121040, -0.799830, 1.515720, 0.324730, -1.470130, -0.299950,
2.063980, -0.449650, 1.122430, 1.290420, -1.192450, -0.964520, -0.970790, -2.361650, -0.003530, -2.019840,
0.499500, -2.060240, 0.450510, -0.091910, -0.423020, 2.889250, -0.048000, 0.019710, 1.655320, -0.261500,
-1.144720, 0.345360, 0.082910, 2.041090, -3.260790, 1.698810, 1.448270, -0.237620, -5.128440, -1.312350,
0.112640, -0.463450, 2.040480, 0.483590, -0.154020, -2.349990, -0.535030, -1.114030, 1.491270, 1.409330,
-1.449060, 1.619730, -0.105040, -2.595710, 0.617590, -0.993040, 1.110080, -3.706030, -2.117620, 3.342150,
-0.677840, -0.822420, -0.114150, -2.044540, -0.485700, 1.683420, -2.075920, -1.865890, 2.449990, 1.540530,
0.585140, -0.204700, -1.329950, 1.043480, -0.134880, 0.209480, 0.168230, 0.186820, -0.776780, 0.365250,
-1.222500, -0.399260, 0.773880, 0.920880, -1.791200, -0.525700, 0.565490, 0.646530, 0.559090, 1.800630,
1.205890, 4.008660, 0.070390, -1.086260, -1.831230, 0.526900, -0.046160, -0.946460, 1.125030, -2.543820,
-0.397430, -0.623490, -1.068060, 1.013060, -0.301050, -1.414890, -0.876670, -0.550080, -0.679700, 0.100430,
1.229460, -1.119270, 0.549780, -0.445680, 1.037540, -0.567180, -0.853420, 1.707060, -0.803320, 0.375580,
0.167500, -0.591640, -1.834000, -0.312650, -0.839500, -0.254510, 0.138710, -2.159330, 1.629840, 0.811630,
-2.437800, 0.569340, 0.114930, -0.629730, 1.094430, 1.910170, 1.496480, 2.089550, -2.349520, 0.914510,
-1.207580, 0.094240, 0.771210, -0.907810, -1.691470, -1.038910, 0.012000, 0.022900, -0.531950, -0.751760,
-0.769400, 0.332090, -0.689870, -0.219900, -0.507490, -0.692500, -0.039700, -0.856750, 0.793800, -0.233410,
0.613110, -1.209780, -0.047770, 0.900920, -0.964530, 0.206250, -1.180750, 0.129600, -0.701370, 1.256020,
0.026530, -0.838900, -0.340870, 2.060500, -0.243180, 0.722600, -0.366890, -0.111670, 1.496960, 5.997830,
-0.217630, 0.114160, -2.470950, -0.761910, 12.509820, -0.698570, 0.329240, -1.733760, 0.257270, 0.140680,
-0.308280, -0.107010, 0.350470, -0.043730, -0.629740, -0.098140, 0.315620, -0.476380, -0.399430, -0.388540,
-11.983890, -0.752570, 0.685620, -1.826890, 0.468310, -0.137870, -0.758110, 0.318410, 0.613600, -0.104700,
-0.435420, -0.502680, -1.189000, -0.925290, 0.338270, 0.163510, 0.642850, 0.920770,
1.846710, -0.590790, -0.423240, 1.550800, -0.582880, -1.065970, 0.333540, -2.397420, -0.318870, 2.256700,
0.134970, -1.280970, 0.534530, -1.318400, -0.007710, 1.462250, -0.964500, 1.466100, 1.098030, 0.072860,
0.147750, 0.351170, 0.845090, 0.460120, 0.614270, 0.884540, 2.515640, 1.719320, 0.103580, 0.579710,
-1.544350, -0.469920, 0.419070, -0.641000, 0.745830, -0.935100, -1.422540, 0.008700, -2.039650, 0.093890,
0.388990, 2.212990, -0.080860, -1.524410, 0.779760, 0.955380, 0.385180, 0.472300, 1.080420, 1.881760,
1.302510, 0.552840, -0.701160, -0.066070, 0.435460, 1.362530, 0.929450, -1.518020, 0.902460, -1.517430,
-0.968820, -0.444280, -0.891210, 1.297020, 1.481170, 0.846930, 0.387550, 0.074720, 1.826460, 1.983930,
-0.638660, -0.065470, 2.439550, 0.343080, 1.381820, -2.220740, 0.748950, 3.306170, -0.588320, -2.094080,
-0.966550, 0.371050, -1.187640, 1.789240, -0.403760, -0.795240, 0.757130, 1.634590, 1.273920, 1.177050,
0.044590, 0.482080, -0.527630, -0.146090, -0.007260, 2.867340, -0.459340, 0.139640, 0.131100, -2.255080,
1.373430, 1.656370, -1.599980, -0.941460, -1.920570, -0.136160, -1.750960, -0.780140, -0.661320, -1.938640,
1.574870, 0.807200, -0.184520, -0.015960, 0.001140, 0.371610, -0.741110, -0.681340, 2.416430, 1.507170,
-0.691450, -0.099600, -1.039640, 1.144960, 1.771440, -2.506320, 0.870870, -1.033160, 0.721630, -0.037530,
-0.373490, 0.471130, -0.150010, 0.925080, -1.481800, 0.717460, 1.714230, 0.635880, 0.895960, -0.677680,
0.787390, -0.331060, 1.584270, -1.584010, 0.494830, -0.661150, 1.238160, -0.125120, 0.352010, 0.144900,
-0.373050, 0.808520, 1.324960, -1.532210, 0.390720, 2.686660, 0.016030, -0.278070, 0.348860, -0.284160,
-0.760620, 1.513720, 1.377320, -2.309970, -2.356520, 0.152520, 0.094500, -0.242570, -1.298660, -0.032710,
0.060240, 1.954320, -1.522190, 0.663720, 1.177730, -0.762440, 1.072510, -0.029930, 2.054460, -3.139550,
0.461290, 0.473840, 0.792810, 0.286980, -1.282990, 3.146890, -0.574260, -1.827570, -0.663660, -1.598520,
0.545080, 0.439520, 1.651560, -1.086070, 2.138780, -0.689060, -0.280640, -0.722960, 0.118510, -0.175590,
-0.200710, -0.702240, -2.050680, -1.653750, 0.350700, 0.514470, 1.039550, 0.386820, 1.740400, -0.932930,
-1.378250, 1.184170, 0.180450, -0.573670, -0.986150, -0.225040, 1.107600, -1.470410, -0.660920, -0.767640,
-2.679890, 1.324030, -1.308310, 0.263520, -0.626430, -0.932790, -0.503620, 1.153100, 0.434140, 1.160840,
0.112460, -0.031970, 0.693130, -1.302570, -0.322170, -0.212850, -1.358850, 0.897040, -0.812160, 2.891500,
0.830300, -1.505520, -0.500420, 0.002470, 0.020580, 0.503110, 0.145410, 0.153390, -0.010010, 0.271270,
-0.323410, -0.666820, -0.066260, 0.259760, 0.325240, -0.760940, -0.331700, 1.708810, 1.315370, -2.490310,
-0.012000, -1.692260, -0.693460, 1.350420, 0.318750, -0.483820, -0.362110, -0.769150, 0.308650, 0.085270,
-0.784010, -1.209760, -0.532970, 0.223960, -0.815570, 0.427030, 1.940850, -0.818400, -0.574580, -0.918170,
3.606420, -0.884980, -1.531910, 2.623850, 0.108190, -0.625500, -0.406560, -0.374070, -0.910720, -0.361500,
-1.267820, -1.329830, 0.624610, 4.210740, -1.263490, 0.027140, -0.545330, -0.418570,
-1.759410, -0.154610, 0.567120, 3.996980, -1.675460, -0.697020, 0.058550, 0.913890, 0.364070, 0.352060,
-2.386610, 0.492610, 0.141390, 1.248390, -0.186370, 0.225340, -1.911320, -1.602360, 0.959580, 1.347150,
-1.189950, -1.158440, -0.247750, -0.298490, -1.385100, 0.570500, 1.919860, -0.450550, 0.024260, -0.700070,
-0.885250, 0.751630, 0.925140, 0.360100, 0.779280, 2.571240, -1.078180, 1.256760, 0.827820, 0.520480,
-0.025630, 0.011910, 0.281540, -1.433650, 0.728360, -1.575530, 1.164350, -1.489280, -0.070630, 0.061490,
1.396260, -0.983500, 0.136080, 0.539750, -2.162400, 0.167530, 1.302290, -0.243240, 1.229090, 2.220420,
0.712750, 0.622060, -0.290140, -1.976080, 0.383330, -1.095010, -0.678050, 0.189080, 0.370550, 1.974520,
0.033780, 1.047970, -1.236630, -2.610240, -0.672270, 0.979400, -0.410910, -0.071030, -1.114800, -5.953160,
-1.023960, -1.327790, -0.492920, 1.657040, -0.587410, -0.595760, -1.221610, 1.183830, 1.090980, -0.948500,
0.553120, 0.832860, 1.547920, -1.177990, -0.013260, 2.985990, 0.588420, 0.447220, -2.376820, -1.112730,
0.260840, 0.177140, 0.188790, -1.645770, 1.748660, 1.936050, 1.057490, 0.279100, -0.647240, 0.175190,
-0.968840, 0.589840, -0.746320, -0.512940, -0.568790, 0.233850, -0.145000, 1.635260, 1.124710, 0.034380,
0.312240, -0.178340, -0.625700, 1.147170, 1.312080, -0.476740, -0.146450, 2.038160, 0.385720, -0.763060,
0.067360, 0.833770, 0.893910, -1.414550, -1.796880, 0.298280, -1.179570, 0.341610, -1.396740, -3.376160,
0.351860, 3.171710, 0.553860, -0.353790, 0.691300, -2.560730, 0.497840, 1.375380, 2.881910, 0.747470,
-0.251660, -0.881280, -0.515750, 2.741970, 1.510920, -2.071080, 1.565690, 1.316400, 0.487410, 0.564560,
-0.633920, -2.343450, -5.800320, 1.303880, 2.676940, 1.076200, 0.127960, -1.940230, 1.233060, -1.576110,
3.276740, -1.517810, -0.170130, 0.940170, -1.535950, 1.477350, -0.239310, -0.535990, 2.966220, 1.593930,
1.650170, -0.574400, -0.008930, 1.909920, 0.135470, -11.824320, -1.946340, 3.260300, 0.433470, -1.946360,
1.405580, -5.901730, -1.322860, -1.336650, 1.818680, 2.842350, -0.310100, -2.069100, -2.200920, 1.504800,
0.847320, -1.274930, 4.334140, 5.461710, -1.073240, 1.169610, 0.484110, 0.367840, -2.107640, 0.847790,
1.967880, 0.542970, -1.832260, 1.092160, -0.886280, -2.601150, -0.250090, -2.507350, -0.154810, -0.072410,
-2.333640, 2.496700, -0.068350, 0.555120, 0.458090, 0.216840, 0.680350, 0.393610, 1.129970, 0.683830,
-0.977890, 0.033490, 0.162230, 2.725250, -1.183640, -2.041170, -1.066270, -2.404040, -0.316610, -1.527240,
-0.680430, 1.671310, 0.501930, -0.333530, -1.498800, -0.235520, -0.153760, 0.184800, 3.433800, 0.179770,
-0.743840, 1.123880, 0.325290, -1.944040, 0.071880, 0.209420, 0.937980, 0.377890, -3.186050, -0.997830,
0.486300, -0.693390, 0.214370, -1.370100, -0.320680, -0.770200, -1.047760, 0.158090, -0.635060, 1.011860,
-0.280130, 0.725710, 0.679550, -0.161040, 0.630200, -0.406820, 4.337730, 0.581780, -0.343190, -0.700120,
9.547720, -0.328730, -0.513300, 0.913200, 0.128890, 0.612640, -0.087360, -0.265210, 0.360800, -0.184020,
0.662300, 0.842860, 0.696860, -0.063250, 0.239050, 0.716210, -0.439630, -0.588620,
0.037650, 1.656540, 0.449500, 0.050300, -0.575400, -0.229620, 0.681490, -0.236580, 0.776200, 0.485310,
0.985470, 0.685260, -0.065680, 0.494100, 0.435680, -0.974460, 0.421190, 0.451660, -1.509430, 0.444300,
-0.541750, -0.473710, 1.113140, 0.347520, 1.551020, -0.132030, -1.394250, 1.732170, -0.765600, -0.121610,
1.746200, 0.025580, -0.266430, 0.017660, -0.516990, -1.005840, 0.171180, -0.402060, 0.117760, 1.471910,
-0.335880, -1.639370, -1.138050, -0.542800, -0.055740, 0.088480, -0.062020, 3.400940, -0.137870, -0.433330,
-0.380500, 1.287230, 0.077810, -1.298480, 2.524310, -0.159730, 0.091740, -0.171050, -0.753000, 0.329540,
0.840960, -0.108130, 0.179180, 1.081130, -0.293040, -0.238980, 0.890740, -2.401530, -0.268820, 2.494950,
2.551690, -0.420300, -1.993560, -0.496510, 3.576610, 0.428610, -1.684600, 1.915270, 0.292750, 0.698180,
0.811490, -0.963520, 0.107560, -0.181090, 1.073520, -0.072680, 1.020960, -0.519460, -0.121130, 0.454880,
-0.628920, 0.205100, 1.224610, 0.618750, -2.001490, 0.040810, -0.543540, 0.377760, 3.364610, -0.199370,
0.560120, -2.155980, -2.024910, -0.462870, 0.680460, -0.359990, -0.350290, -0.846290, 0.130470, -1.586750,
0.061100, -0.197880, 0.173810, 0.377490, -0.625610, -0.270550, 1.435690, -0.845640, -3.107930, -2.528400,
-0.161060, 0.856950, 0.797810, 1.998740, -0.767890, -2.461680, -3.359600, -2.459940, 1.046920, 0.032460,
-1.748260, -1.716280, -1.240810, -0.498890, 0.821130, 0.668460, 0.071270, -0.226170, 1.144430, 0.882150,
0.294940, 1.100660, 1.720310, 0.251210, -1.612170, 0.101200, 1.056020, 1.492250, -4.648930, -0.607070,
1.785440, 1.594310, 0.945640, -1.441950, -0.460400, 0.624350, -1.470390, -0.709010, 3.105320, -0.367350,
-3.229360, 1.772590, -0.388800, -0.862870, 0.872030, 0.223930, -1.151770, 1.087420, -0.509490, 1.969500,
2.833520, 0.931930, -0.848090, 0.890660, 0.738140, 2.164290, 0.330560, -0.496560, -0.274240, -0.224660,
1.218540, 1.407650, -0.990860, 0.627220, 1.767370, -0.439020, 1.355340, 0.662160, -1.300860, -1.629630,
1.197210, 0.698380, -0.515830, 0.501470, -0.274300, -0.636300, 0.788060, 1.207250, 0.234340, -0.195840,
1.576340, -0.967340, 0.359080, 0.433770, -1.010270, 0.650500, 1.021910, 0.559570, 0.657550, 1.505850,
0.177010, 0.172870, 0.205740, -0.597700, -0.206520, -1.811280, 1.173160, -0.675670, -0.525410, 0.048840,
0.439520, 0.786720, -1.105140, -1.399020, -1.424090, -0.860130, 1.287010, -0.320690, -0.844420, 1.038340,
0.563740, 2.890460, 3.581170, 1.196730, 1.121270, 0.313220, -1.082030, -1.138500, -0.272140, 2.830710,
-1.585830, -0.589240, 0.497110, -0.126090, 0.559520, -1.524830, 0.122570, 0.026010, -0.610910, 0.320930,
-2.534390, -1.186100, 0.534080, -0.846190, 2.049920, 0.580360, 0.248710, -0.988320, 0.635110, 0.127640,
-1.367890, -1.541700, -0.124910, 0.475900, 1.718210, -0.005750, -0.018800, -0.070650, 0.339160, -4.558910,
-0.338620, -1.121620, 0.047190, 0.108740, -1.904910, -0.006690, 2.822600, -0.010740, -1.117600, 0.393830,
-0.106050, -0.736050, 0.061240, 0.273120, -0.621370, -0.154060, -1.290410, -2.144430, 0.441030, -1.273850,
-1.164480, -1.317990, -0.626910, -4.017770, -0.093610, -1.188500, -0.303960, -0.597280,
-0.761400, 0.490650, -0.453910, 0.518230, 0.641430, -0.991740, 2.864590, -4.026120, -0.906960, 1.189610,
-2.590510, -2.287660, 0.874030, -0.060880, 0.052800, -1.222680, -1.957810, 1.149930, 0.709280, 2.733110,
-2.580180, -2.269510, 0.555880, -0.085020, 0.302170, -1.037180, 4.328400, -0.249700, 1.912830, -1.043410,
0.042820, -1.295450, -0.879080, -1.146730, 0.182160, 0.323790, 0.125060, 1.566530, 0.247300, -1.099050,
0.845240, 0.843890, -0.335390, -0.196860, -0.512160, 1.334370, 1.875250, 2.952130, -0.519630, -0.168530,
-1.096600, 1.412810, 2.289590, 2.787800, 0.381450, 0.358370, -3.649690, -0.376250, -2.209600, -1.112120,
-0.378230, 0.608790, 0.011780, 1.095120, 0.526550, 0.041940, -0.771320, 0.937860, 1.039960, 1.763300,
4.450140, 0.283550, -1.461080, -0.639330, 0.485950, 0.177390, -1.219380, 0.775260, -2.127780, -5.045400,
1.149030, -0.767560, 2.492930, -0.624520, -1.485480, -3.595340, -0.643010, 3.571710, -2.269890, 1.546980,
0.278470, -0.539180, 2.887130, 3.690640, -0.186950, 0.508650, -0.406320, 0.654000, -2.115040, -0.586260,
2.555000, 0.895630, -8.138830, -1.017890, -1.016130, 3.750230, -0.856580, -0.485790, -0.256060, -0.722390,
-1.163250, 0.464600, 1.472520, 0.927210, -0.806520, 1.156450, 3.801350, -0.510510, -2.013170, 0.728070,
-0.459770, -0.291100, 1.103530, 3.537110, -1.320870, -1.828010, -1.412030, -3.135130, 1.680440, -1.898000,
0.021290, -0.924470, 0.151000, -1.221570, -3.047430, 0.592640, -0.183250, -3.108660, 1.174810, -0.319960,
0.234610, -0.729660, 0.441410, 0.135540, 1.762170, -0.761370, -1.406570, 0.395660, 0.240830, 1.982380,
-0.437710, 0.430160, 0.386750, 2.447260, 0.703330, 0.541260, 0.986800, 1.343970, 0.692970, 1.225800,
-0.041750, -2.036560, -1.191580, 0.844000, -0.014280, -0.009580, -0.020970, -1.192320, 1.777840, 2.699150,
0.083770, -1.105310, -0.145390, -1.119690, -3.216620, -0.644800, 1.180670, -0.786640, 0.487000, 0.069950,
2.661050, 0.035950, 0.184970, -1.319660, 1.342450, -2.153480, 0.942970, 1.410920, -0.610900, 1.392340,
-0.822650, -0.508810, 1.071880, 1.141370, 2.242010, 0.593030, 0.558880, -2.039820, -1.192600, 1.827960,
1.231320, -1.535800, -0.134680, 0.176200, -0.197620, -0.684740, 0.208140, -0.029820, -0.053390, -0.018910,
2.204050, -0.324420, 0.192590, 0.153110, -1.956800, -0.204370, 2.163430, -1.759250, 0.163250, -0.599680,
-3.781410, 0.310060, -0.154210, 0.599460, -1.374590, -0.414500, -1.499240, -0.761210, 0.154890, 3.512020,
-0.583810, -0.936820, 2.600730, -2.207040, -4.524670, -2.232770, 1.678800, 0.333780, -1.161000, 0.660840,
1.183350, 0.714800, -4.032710, -0.944650, -1.162890, -1.944140, -1.738210, -0.651880, 0.337100, 0.252310,
-0.591150, 0.160600, -0.020450, 1.578760, 4.856590, 1.020730, -2.432400, -0.846180, 2.856800, 3.188380,
0.682180, -1.357490, -1.721370, 0.271670, 3.401170, -2.183470, 2.926900, 1.299790, -0.548870, -1.536870,
0.105700, -0.538630, -0.540220, -0.483140, 0.540130, -0.477900, -0.842080, 0.104870, 0.366150, -0.296380,
-2.207900, -0.461070, 1.605740, -1.072640, 0.019860, 0.574460, -0.337380, -1.108900, -1.129600, -0.285020,
-0.173760, -1.242780, -0.267240, -0.653800, 0.486250, -0.852020, -0.728750, -0.571370,
-0.650180, -1.037060, -0.006390, 1.912430, 0.578740, -0.708360, -1.565720, 0.701820, 0.582560, -0.754140,
-0.920980, -0.801740, -0.335340, 0.223130, 0.492400, 0.182330, -0.208340, -2.015360, 0.328070, 1.144130,
0.622010, -0.941030, 1.207660, -0.973980, -1.778360, -2.699010, 1.342740, 0.974500, -0.018810, 0.070620,
-1.872980, -0.317590, -0.390470, -0.157830, 0.476830, 1.530570, -0.730780, -1.241410, -1.138040, 0.377630,
-1.693700, 2.058720, 1.013110, -0.119390, -2.215560, -1.940920, -0.140600, -0.844020, 0.437530, -0.001620,
0.668770, -0.611260, 0.210410, 0.845460, -0.480080, -1.476430, -1.030170, -0.372890, -1.614710, -1.230120,
-0.194870, 1.410230, -0.205180, -1.179070, 2.242950, 0.165510, -1.063630, 0.110970, -0.716530, -0.414040,
-0.636650, 0.425560, 0.158000, 1.021870, 2.036150, 0.162130, 2.904870, 1.146500, -1.001280, 0.680400,
-2.697650, 1.172430, -0.500210, 0.172100, -0.521630, -1.316300, -1.035730, 0.037640, 0.258230, 0.216890,
0.443450, -0.178990, 1.245200, 2.484430, 1.021370, 0.712890, -1.123980, 0.144210, -1.662760, -1.506980,
2.791850, -2.551130, -1.036610, -0.202840, 0.239590, 0.283830, 0.336780, -0.862900, 0.076670, -1.747970,
-1.906860, -1.511820, 0.709310, 2.376200, -1.143620, -0.630930, 2.159070, 0.172380, 0.516650, 0.207050,
-0.538090, 1.634140, 1.215870, 0.808470, -1.501290, -1.301400, -0.492460, 0.970260, -0.183190, -0.244640,
-1.388880, 0.885460, -0.240140, 3.806340, -1.247930, -0.398580, -0.592280, -1.115970, -0.860490, 1.682110,
0.908960, 0.131070, 0.172820, -0.678780, 1.478840, 0.758660, -0.380550, 1.681630, -1.892710, 0.021990,
-0.302760, -0.966450, 0.309820, 0.020910, 0.646940, 2.273530, 0.108840, -0.428440, 0.800290, 0.048680,
-0.546580, 0.863180, -0.744710, 1.613440, 3.543070, 0.507150, 0.754480, -0.413420, -1.611590, -0.440900,
0.964460, -3.642220, 1.266110, 0.317740, -2.720320, 0.219220, 1.622310, -0.002590, -0.070610, -0.394580,
-1.904130, -0.727210, -0.115450, 0.417130, 0.172420, -3.293370, -1.175460, 2.796150, -0.767610, -0.711740,
0.935950, 0.563290, 0.158550, 0.889690, -0.322550, -1.151200, 0.275170, -1.667670, 0.324760, 0.327670,
-0.507700, 0.488040, 1.246800, 0.190930, -0.326430, -0.307360, 1.216860, -1.455190, -4.372050, -0.142340,
2.604430, -2.371370, -1.982320, 0.742910, -2.043870, -1.948900, -1.379980, -0.559980, 2.043800, 1.054070,
-1.391470, -0.833860, -0.412420, -0.151170, -1.071350, 2.056140, -1.261140, -0.791020, -0.967050, 0.738820,
0.142460, -3.316560, 1.740740, 2.636620, -2.362740, 1.470920, 2.787290, -0.903550, -5.975820, -0.483630,
-2.730980, -0.264210, -0.162220, -1.871540, 0.788470, -0.410030, -0.355750, -0.193440, 0.900180, -0.823930,
-0.383990, -0.892590, 1.392720, -0.577500, 1.816960, -0.747730, 0.644080, 2.701940, -1.326540, 0.506930,
0.682230, 1.018630, 1.286400, -0.969300, 0.340650, 1.199520, 0.670450, 3.058610, -0.995000, 2.247340,
0.811880, -0.259050, -1.211370, -0.857460, -1.033890, -0.031820, 2.603540, -0.226010, 0.068060, -0.730440,
0.646780, -0.264350, -0.373570, 1.815600, -0.647410, -0.795340, 0.912410, 0.369930, -1.016930, 0.358960,
0.420380, -0.773360, -0.398490, 0.173060, -2.025510, -0.209370, -0.873620, -0.375110,
2.174480, -0.543080, 0.055300, 0.233410, 0.460820, -0.885510, 0.150330, 0.833600, 1.131150, -1.854410,
-1.436210, -0.708490, -0.184510, 0.655310, 1.085810, -0.088360, 0.703330, -0.672480, 1.124750, -0.615970,
0.537610, 1.120990, 0.325240, -1.451450, 0.596960, -0.408680, -0.660490, 0.888390, 1.360340, 0.193470,
-1.265500, -0.666920, 0.169300, -1.508740, 0.333690, -2.363450, 1.053940, -0.987980, -0.956750, -0.165490,
1.415680, 0.086310, -0.794750, 1.280240, 0.336620, -0.114830, 1.306070, 1.330610, -0.386500, 1.204200,
0.494250, -0.904740, 1.104310, -0.233730, 2.429130, -1.275270, -0.894360, -0.666450, -0.296280, -0.304510,
-1.308810, 0.795020, 0.033400, 0.720670, 0.652330, -1.095980, 0.237520, -0.650330, 0.572840, -0.037120,
1.049520, 0.582370, 1.291490, 0.935570, 0.207060, 0.501530, 0.157870, -0.112010, 1.683450, -2.330210,
0.395160, 1.108560, -0.018690, -0.058500, 0.214470, -1.108880, 0.186350, 1.772210, -1.090670, 1.210370,
1.093140, -1.436710, 0.947910, 0.675320, -0.198860, 1.753560, -0.232660, -0.456250, 1.256970, 0.127380,
-1.188300, -0.495800, -0.583700, 0.554000, 1.113660, 1.214600, 1.540880, 0.187980, -1.352030, 0.193020,
0.391600, 0.565170, 0.111260, -0.192620, -0.799040, -1.420800, -1.462020, -0.330700, -0.534050, 1.003570,
1.114160, 0.420670, 1.070580, -1.440220, -0.855590, -0.634200, 0.117270, 1.147720, 0.994240, 0.313860,
0.198580, -0.091920, 2.439930, 0.458770, -1.081730, 0.392760, -0.170600, -0.893780, -0.010290, 0.066150,
-0.410400, -1.101930, -0.216900, 0.220820, 0.665570, -1.462590, 0.407940, -3.603460, -0.960630, 0.261130,
-2.106740, 0.226200, 0.374140, -1.502920, -1.191880, 0.599680, -1.000510, -1.614240, 0.644400, -0.521970,
-0.357630, -0.775980, 4.081200, -1.156740, -4.431790, -0.444490, -0.374210, 1.074490, 0.000490, -2.175920,
-3.388920, 1.310530, 0.888260, 1.124160, -0.231370, -0.304600, 0.414560, 0.993220, -0.071630, -2.935910,
-1.138380, -1.015460, 0.187020, -4.587940, 0.424090, 5.707340, -1.438730, -2.533610, -0.449700, 0.621870,
1.647340, -1.398150, 1.088150, -0.418170, 3.956140, 1.142530, 0.958090, -1.524320, 2.603590, -0.529880,
-0.319180, 1.684520, -2.077740, 0.625970, -0.844990, 0.234390, -0.824260, -0.319020, 4.660990, 1.312310,
-2.807940, 0.931410, 1.728450, -0.866670, 0.629760, 0.916440, -0.684070, 2.722390, 1.367770, -0.145590,
1.486240, -1.291990, -0.350960, -1.914440, -2.895600, -0.283980, -1.517720, -0.002180, 0.693310, -1.218530,
-0.346240, 2.970420, -0.685120, -0.779350, -0.605610, 1.558960, 0.005600, -0.028770, 0.616530, -2.274720,
2.427520, 0.596310, 0.160970, -0.197300, -1.076950, -0.996720, -0.322520, -2.688710, -2.473450, -1.025380,
-0.725280, -1.293360, -0.655090, -1.850620, -1.157950, -0.253830, -0.217330, 1.135430, 1.968840, -1.591240,
1.994890, -0.687490, -0.421420, 2.775150, -1.143940, -0.267650, -1.451990, -0.838910, 0.607470, -0.090230,
-0.223290, 0.072940, 1.773970, 0.719810, 0.146510, 0.406610, -1.000610, 4.598110, 0.643420, -0.435440,
-0.959660, -0.802540, 1.147790, -0.626900, -0.495300, -0.911050, 0.799390, -0.906070, 1.607970, 0.785220,
0.535570, 1.441190, -1.409500, -1.010070, 0.944950, -0.099830, 1.361150, -0.018360,
0.418580, -0.746640, 0.506080, -1.205240, -0.198160, -0.080960, -0.584560, 0.804550, -0.109920, 0.647150,
-0.144930, -0.056640, -0.155380, 1.551940, -0.149570, -0.339030, 0.948710, -1.195220, 1.131020, 0.265130,
0.892710, 1.381000, -0.977980, 0.760800, 1.944840, -0.416200, -1.586740, -0.681020, -1.126000, 0.146450,
-0.571470, 0.833060, 0.944630, -0.665740, 1.004780, -0.274210, 1.194190, -0.074310, 1.811830, -0.751170,
-1.035410, -1.074320, -0.115550, -0.195330, -2.507210, -0.643600, -0.767760, 1.535680, -0.583060, -0.676530,
-2.382990, 0.759250, -0.126220, 1.310980, 1.177570, -0.636580, -3.248310, 0.619430, 2.052930, 0.290420,
-0.984320, -0.146440, -1.307650, -1.133830, 2.083370, 3.643600, 0.605700, 0.346220, 1.208630, 2.484320,
5.340040, -0.757340, -1.717130, -0.127450, -0.008450, -0.185770, 0.029080, -0.056890, -0.671590, 1.530010,
-0.284130, 0.499160, 0.931390, 0.848450, -0.297360, -1.758320, -0.800540, 0.179680, 0.562310, -0.175640,
-0.993820, -0.799530, 2.116260, 4.663380, 0.883880, -1.172390, 0.647610, 0.678260, -1.747270, 2.226560,
3.226420, -4.560760, -5.099590, 0.464030, 0.759520, 7.087170, 0.678460, -0.771980, -2.859820, 1.280280,
0.363810, -0.980430, 0.638620, -1.178560, 4.880930, 0.367960, -1.154090, 1.682630, 0.011740, 1.820550,
1.078220, -1.826050, -0.434000, -0.589000, 0.319810, -0.629130, 0.802240, 0.120020, 3.384970, 2.257460,
0.503190, -0.502830, 0.884400, 0.196310, -1.086190, 0.298340, 0.155660, 0.127170, -1.130540, -0.665620,
1.211710, 0.167110, -2.262960, -0.466300, -0.475470, -2.233230, -1.041440, 1.260450, 4.305140, 0.035650,
4.226490, -0.535170, -0.410430, 0.321080, 0.691980, 0.345390, -0.249170, -0.226560, -2.729870, 0.071780,
-0.828700, -0.681570, -0.347360, -1.129990, -0.718160, -0.576750, 1.056960, 0.542600, -0.965040, 0.799580,
1.051810, 3.649840, 2.738090, 0.008200, -0.326590, -1.164460, -1.055170, 1.379530, -0.537000, 0.382320,
1.368740, -0.948650, 0.927430, -2.274840, -2.113990, 1.810630, 0.035090, -0.534840, 0.581860, 1.378370,
-0.386820, 0.932220, -1.105050, 1.777370, -0.102260, 0.726780, 1.000290, 0.455570, -1.727840, -0.203410,
0.595560, 1.582300, 0.173920, 1.271660, 0.223450, -1.311270, 0.749740, 0.817090, -1.464960, 0.528110,
2.414500, -0.840730, 2.080050, -0.159030, -1.382020, -1.075890, -0.884010, 3.073570, 0.292250, 0.291690,
0.257810, -1.234150, -0.974120, 0.708190, -1.165400, 1.076250, 0.464310, 0.445160, 0.355490, 1.384830,
-2.703560, -0.357130, -0.878760, 2.017990, -1.538270, 0.057180, -0.289170, -0.574770, -0.001190, -0.220270,
-0.170340, 0.402770, -0.797540, 0.518950, 1.712120, -0.825140, 0.530800, 1.870250, -0.384010, 0.949820,
1.668080, -0.323280, 1.576480, 0.682790, 1.506050, 0.721040, -1.783870, 0.616400, -2.190830, 0.927170,
-0.180950, 1.133140, -0.534860, -0.848510, -0.954650, -0.092870, 1.714010, 0.240670, 0.431890, -0.419740,
-0.859380, 0.701460, -0.341910, -2.058260, 0.289880, 1.002090, 3.873840, 0.743130, -0.556130, -0.291610,
-1.437950, -0.524650, 0.595330, -0.269070, 0.651270, 1.044640, 0.391230, 0.446920, -0.267260, 0.763500,
-0.571460, -0.152280, 1.542570, 1.188010, 0.044020, 0.273020, 0.448750, 0.718840,
1.125500, 1.122020, -0.457890, 2.164210, -0.450880, -1.194260, -0.565910, -1.088670, -0.193090, 0.484110,
0.093670, -0.422550, 0.152510, -0.631480, 1.208080, 0.364780, 1.776770, 0.680820, 0.189060, -0.343480,
-1.759830, 0.380080, -0.245860, 0.591790, 0.344180, -0.746120, 0.637810, 1.204420, 0.174550, -0.492260,
0.898790, -0.370640, 0.985410, -0.667660, 0.889230, 2.158980, -1.365500, 0.772340, 0.225800, 0.557150,
0.373090, 0.536810, 0.158050, -1.101170, 0.521680, 0.312430, 1.848880, -0.483000, -0.002040, -0.469860,
0.183110, 0.755570, -0.475220, -0.839300, -1.334820, 0.897090, -0.236920, -1.343300, -0.738530, 0.591500,
1.424500, -0.627020, -0.195230, 1.080140, 0.920390, -0.762720, 0.750960, -0.714860, -2.616650, 0.735950,
0.930180, 0.336010, -1.050310, 0.557480, 0.231390, 0.146070, -1.650680, 0.824080, -2.238300, 0.700300,
0.454870, 0.153560, 3.253740, -0.557350, 0.368770, -0.678060, 3.087480, 1.047510, 0.461180, -0.451970,
-0.973580, -2.126560, -1.372480, -0.973210, -0.274580, -0.607010, 1.797590, 1.641830, 0.598030, 1.829560,
0.150370, 1.259340, -0.393140, 0.212820, -1.163710, 1.601500, 0.912950, 0.167390, -1.212910, -0.608950,
-0.541120, -2.948860, 0.874790, 0.072660, -2.658530, -1.739990, 2.206560, 0.431790, -4.188000, 0.902270,
-0.005770, 0.637670, 0.867440, -0.303490, -0.346020, 0.655860, 1.826340, -0.227690, 3.180110, 1.445050,
2.306510, 1.249930, 0.819400, 0.331130, -0.684070, 0.755520, -0.106780, -0.667900, -0.632980, -1.532150,
-0.129580, -3.170860, 1.478430, 2.097430, 1.395790, 3.543000, -0.443660, -0.485010, 1.527080, 0.508490,
-0.728230, -0.112140, 0.948910, 0.300390, 1.214080, 1.254650, -2.937040, -1.215110, 0.231040, 0.581510,
-0.421200, -0.282820, 0.708410, -1.855960, -3.465300, -0.209440, -0.301430, 0.110810, 1.102500, -5.641790,
-0.335010, 1.373790, 0.884420, 0.642520, 0.040830, 1.683290, 0.565620, -0.209380, 0.078690, 0.372650,
-0.011190, -0.302700, -0.596600, -0.583020, 0.117570, 4.236590, -2.139970, -4.693380, -0.549040, 0.237320,
-0.497990, 0.034670, -0.916580, -0.221670, 1.464930, 0.650820, -0.137950, -1.319500, 1.369610, 0.939460,
0.743990, 1.059970, -2.007400, -0.961700, -0.661010, -0.310140, -1.816370, 1.006750, 3.185440, -1.960220,
-2.636600, -1.565100, -0.316070, -0.282590, -1.127070, -0.633360, 0.735040, 1.848530, 0.984050, -1.136790,
1.914060, -0.946700, 1.292710, 0.934460, 0.392500, -1.107460, -1.578980, -0.879600, -1.009160, -0.810110,
0.523120, 2.058560, -0.706810, -6.604610, 0.085030, -0.258640, -1.603390, 0.995980, 0.849310, 0.770980,
3.992720, -0.038740, 0.888970, 0.428130, 0.293080, 0.023410, -0.019920, -1.380880, -2.140250, -0.184900,
-0.074520, 0.355150, -2.207930, 1.986010, 1.100530, 2.127050, 1.170070, -0.766040, 2.054020, 3.591160,
0.480960, 1.379970, 2.442240, -0.027940, -0.268480, 2.473500, -0.070520, -1.324810, 0.626370, -1.868100,
-0.143910, -0.802770, 2.007560, -0.795910, -0.607430, 0.472850, -5.371740, -0.223680, -0.479860, -0.505610,
-1.498340, 0.181040, 0.035550, -0.368960, 0.364680, 0.918660, -0.432000, 0.847180, -0.167910, -0.399240,
0.510800, -0.924840, -1.769270, -2.148540, 0.250840, 0.274280, 0.079360, 0.159270,
2.754220, 2.143410, 0.095930, -0.217560, 0.585600, 1.238300, -2.808580, -0.885090, 1.426030, 1.395020,
-1.089200, 3.561060, 1.123200, -0.453620, -0.596180, 1.204380, -0.700700, 1.416960, 2.052320, -0.752470,
-0.170530, 0.334640, -2.124920, -0.203970, 0.773400, 0.363320, -0.985510, 1.020940, 2.244810, -1.277150,
-0.146360, -0.298890, 1.468320, -0.231110, 2.441700, 0.066380, 1.132490, -0.072290, -1.828610, -0.969410,
-0.572520, -0.250420, -0.583400, 0.336640, -0.760650, -0.785330, -1.048970, 0.254020, -0.155960, -0.470090,
-1.225530, -1.208580, 0.595090, 0.619520, 0.628850, -0.111800, 1.078970, -0.099890, 1.370730, 1.022040,
0.450040, -0.049070, 0.434110, -1.664530, 1.619290, 0.460850, -0.466160, -0.567400, -0.117580, -0.512200,
-0.200420, -0.849480, -0.721880, 0.262380, -0.630820, -0.598530, -0.893240, -0.675710, -1.024370, 0.722850,
1.425460, -0.251890, -1.901830, 0.034620, -0.659440, 1.662830, 0.461900, -0.021600, -1.300000, 0.026540,
0.661880, -0.115350, -1.433700, -1.844110, 1.057870, -1.726760, 0.686350, -2.584000, -0.117110, 1.154710,
-1.119830, 0.099270, 0.458160, 2.472040, 0.047540, -1.034870, -0.128870, -0.899770, -0.781230, -1.259270,
-0.656350, 2.565690, 0.998550, 0.286930, -0.832700, 0.133440, -1.070090, -1.868570, 2.856740, -0.016560,
0.221310, 1.228280, -0.989270, -2.836440, 0.257710, 4.471520, 1.599280, -0.178990, -1.223940, -0.641100,
0.885660, 1.419930, -0.867900, 0.179230, 0.215140, -0.007540, 0.174030, 0.364060, -3.746000, -0.444390,
1.231850, 1.490730, 0.121850, 1.136790, -0.509860, 0.436980, -5.598300, 1.258040, 3.381680, 2.122570,
1.576760, -1.759280, -0.494200, 0.648430, 3.570230, -0.913950, 1.621150, 1.355550, -1.597100, 1.498060,
1.334960, -2.048100, -3.546860, -1.000920, 3.697890, 3.417430, -0.564970, -0.562230, -1.190840, 0.389650,
3.604830, 1.377520, -0.085640, 1.979810, -0.736210, -0.891480, 0.436300, 1.611690, 0.866170, 0.762620,
1.193690, -0.427490, 1.104510, -0.824150, 0.962800, -1.891360, 0.575740, 2.665700, 2.822890, 1.748580,
-0.429240, 0.615570, 1.881760, 0.779250, -0.910160, 0.518800, 0.388760, -2.622180, 0.391250, -1.946030,
-0.014960, 0.147230, 1.639930, 0.575500, -0.117470, -0.068710, -0.030930, -0.176670, -0.896150, 3.233380,
1.228980, -0.935160, -1.691800, 0.167090, -0.249870, -1.065690, -3.272520, 0.661680, 0.734030, 0.108070,
-0.989290, -1.095340, -0.752810, 0.936410, -0.439340, -0.375420, -0.064060, 0.744930, 0.602230, -0.179530,
1.200860, -0.757940, -0.328870, -0.049420, -0.099680, -1.088760, 1.608790, 0.296540, 0.478180, -1.021420,
-2.540310, 0.123240, -0.752740, 1.876440, 1.375800, 0.055760, 0.797010, -1.062550, -1.161800, 3.880660,
0.990120, 3.363710, 0.388660, -0.736810, -4.496250, 0.608350, 0.956880, -0.079370, -1.380800, -3.198020,
0.208970, 0.979610, -0.013580, -0.360790, -4.283160, -0.454700, 0.300990, 1.712280, -0.086460, -1.261160,
-0.674040, -0.272940, -0.260560, 0.541430, 0.157300, 0.334380, -2.280920, -0.516060, -0.527670, 0.202640,
1.610360, 0.563280, -3.162490, -0.045640, -0.892650, 0.168990, -0.818060, 0.977160, -1.338340, -0.766970,
-0.022000, 1.293600, 0.149150, -3.295010, -0.291770, -0.108350, -0.495810, -1.140020,
0.702920, -0.406810, -1.138550, -0.444980, 0.433830, 0.287950, -0.697220, 0.950360, -0.043810, 0.636180,
-0.303890, -0.047750, -0.503440, 0.092190, -0.095560, -0.181000, 0.688140, -0.798580, 0.047140, 0.800010,
-0.208840, 0.391950, 0.637970, -0.624150, 0.782440, -1.699980, 0.226640, -0.312020, 2.650800, -1.204760,
-0.033420, -0.530910, -0.851640, 4.184300, -1.639930, 0.130700, 0.793740, 0.182560, -0.107740, 0.451570,
-1.769010, -0.834700, 0.282720, -0.713450, -0.098880, 0.825230, 0.813210, 0.091070, 1.156740, 0.156390,
-0.669270, 0.693440, 0.065460, 1.505810, 1.119710, -0.172020, 1.522790, 0.033390, 0.332010, 1.116770,
-0.279740, -0.512020, 0.584560, -0.073020, 0.465790, 0.884160, -0.504180, 0.693880, 1.198100, 0.763910,
0.389510, -1.341110, 0.607780, -0.626790, 0.173520, -0.620280, 0.906270, 0.101700, 2.259610, 0.220920,
0.743610, -0.089610, 2.122780, 1.426330, -1.318560, 2.878520, 1.390830, 2.015990, 0.515180, -0.321800,
-0.853200, 0.999020, -1.390100, -2.091940, 0.434420, 2.739930, -2.516450, -0.814690, -0.410170, 0.294180,
-0.770270, 0.372750, 0.846890, 0.091560, -0.031110, -0.537800, -0.151370, -0.401090, -0.807270, -0.431710,
1.372840, 1.953870, 0.663280, -0.652150, 1.709270, -1.493670, -0.580990, 0.190310, -0.218830, 0.561330,
0.870510, 1.204870, 0.968030, -0.895870, -0.171640, 1.185320, 1.909490, -0.665670, -0.389790, 0.460310,
1.169150, 0.135530, -0.883880, 5.634380, 1.719740, -0.663580, -0.837920, -0.195300, 0.249650, 1.510080,
-1.355310, 1.268870, -0.510900, 0.784900, -0.513260, -0.786240, -0.031280, 1.213860, 1.309600, 0.882210,
0.193640, -0.149790, -0.403930, -0.142690, 1.279200, 0.590260, 1.008920, -0.831560, 0.146460, 0.587830,
1.118390, -1.548830, -1.530990, 0.555080, 0.045760, -0.049830, 0.547740, 0.597220, 0.940670, -0.128540,
1.308970, -0.127390, -0.874610, 0.425770, -0.225330, 0.106920, -0.289050, 0.427110, -0.079510, -0.311450,
-0.277850, -0.101440, 0.190480, 0.756220, 0.065370, 0.815730, -1.519980, 0.895780, -0.084930, -0.811290,
-0.083730, 0.318680, -1.131330, 0.460670, -0.320070, 1.429810, 0.477600, 0.019460, -1.027200, 0.811780,
2.478950, -0.172020, 1.171330, -0.044200, 0.292070, 0.411070, 0.310520, -0.691390, -1.388760, 2.206180,
-0.125810, -0.912060, -1.481890, -0.317150, -0.212790, 0.077980, 0.200070, -0.712490, -0.580230, -0.510250,
-0.012180, -0.664950, 1.559930, -0.720090, -0.795340, 3.317830, -0.639630, 0.620690, 0.413070, -0.308000,
1.423250, -2.609880, 0.857650, 1.866690, 1.829390, -0.531470, 0.844730, 0.050690, -1.516970, 0.866020,
-2.809640, 0.794040, -0.720990, 0.875140, -0.006930, -0.825120, -0.977630, 0.703700, 2.070210, 1.883900,
1.003880, 0.692980, -0.559410, 2.635840, 0.712450, 0.740460, -1.957280, -1.819740, 1.472750, 2.772050,
0.272540, -0.615120, -2.144960, 0.291490, -0.462060, 0.268420, -1.081950, -1.666950, -0.714930, 0.702020,
-0.522680, -0.324230, -0.864820, -3.252740, 0.247530, -1.074240, 1.051580, -1.951180, -1.957200, -0.396140,
0.583240, 0.543360, -5.247810, -0.282650, -0.968110, -1.081300, -2.010520, -0.338160, -2.024700, 0.150570,
-1.177180, -0.438740, 0.584120, 0.737550, -2.454590, -0.582050, -2.739720, 0.248450,
-0.065790, 0.171220, 0.012170, -0.865490, -0.350980, 1.009140, -0.123690, -0.641850, -1.445580, -1.248560,
-0.172360, -0.439590, -0.287210, -0.160610, -0.148750, 0.846670, 1.603550, -0.262400, 0.081350, -0.472840,
-0.534340, -0.301510, -1.127430, -0.152260, -0.161220, 1.448990, 0.215250, -0.680010, 0.087860, 0.362670,
-0.853280, 0.068840, -1.451210, 0.686120, -0.411660, 0.174600, -1.246910, 1.153600, 0.057360, 0.673690,
-0.695390, -1.137590, 0.359550, -0.958930, -1.371000, -0.792950, 0.211310, 0.223560, -0.660860, 0.166660,
0.735610, -0.344910, 1.448800, 0.160130, 1.162930, 1.664420, 2.116570, -0.360970, -0.187500, 1.462890,
0.432860, 0.455600, -0.371550, -0.581370, -1.295670, 0.671830, -0.332880, -0.617600, -0.496990, -0.844490,
-0.204570, -0.377000, 0.190690, -3.217900, 0.246400, 0.565450, 0.319610, 1.666730, 0.018050, 0.691580,
1.520140, -1.247510, 0.849690, -0.797250, 0.384520, -0.778680, -2.034430, 0.354690, 0.310830, -0.345540,
1.023280, -0.425650, 0.332100, 2.417810, -0.380000, 0.433750, -1.100400, -1.514600, 0.474970, 0.032360,
0.034800, 0.290510, -0.347910, -0.935740, -0.344080, -0.212780, -0.069630, -0.015720, -0.501330, -2.060470,
2.783780, -0.447010, -0.104750, 0.049960, -1.102640, 0.792000, -1.026690, 0.268270, 3.565160, 1.418890,
1.833020, -1.057870, -1.376140, 2.305900, 0.892730, -3.722890, -1.932190, 0.305960, -1.118210, 0.757540,
0.615570, -0.039140, 0.968550, -0.316230, 0.384710, 1.466430, -0.398880, -1.750280, -0.912850, -0.952660,
-0.296140, 2.612040, -0.581900, -1.099930, -0.138150, 1.019690, 2.915260, 0.837130, -0.266060, 0.235830,
-0.045700, -0.425280, -0.034950, -0.059370, -0.295090, -0.069950, 0.063980, -1.373180, 0.946750, -1.185630,
0.357780, 0.801770, -0.072360, -1.105770, 3.566480, 0.242310, -1.073910, 1.984110, -0.371730, -3.898640,
-1.683450, -0.597250, -0.253400, -1.115620, -2.410780, 0.279960, 0.727470, 0.863520, -1.726500, 0.419820,
0.180690, -0.667650, 2.486980, 1.135740, -0.876960, -0.052830, 0.754910, -0.600960, 0.358090, -0.345440,
-0.824530, 0.346210, -0.824390, -1.521480, -2.193890, 0.295350, -0.126240, 0.491520, -0.918920, 0.086870,
-1.084810, -1.127790, 1.869590, 0.683600, 0.409670, 0.313660, 1.141310, 0.193680, 1.540210, 0.352180,
2.097350, 1.710410, 0.147590, 0.638530, -0.546940, 0.947870, 1.441000, -0.794340, -0.085910, 1.448560,
-0.908210, 1.526780, -1.116890, 0.629680, -0.113580, -0.526170, 1.661380, 0.816190, -2.859610, -2.103240,
-0.197750, -1.029010, 0.399970, 1.155900, -0.570790, 0.871180, -0.020860, 1.193600, 0.613790, -1.049270,
-3.509530, -1.204990, 0.167640, -0.790580, 1.118020, -1.385330, 2.297440, -0.903060, 4.143460, 0.847740,
-0.216990, -0.330240, -0.466560, -0.205460, -0.474690, -0.218960, -0.929580, -0.617500, -0.816060, 0.333480,
-0.363750, 0.582590, -0.417640, -0.283020, -1.510750, -0.160020, -0.596990, -0.550560, -0.382330, -1.631450,
-1.122250, -2.792960, -3.344160, -6.177920, -1.116910, -0.328940, 0.849820, -0.429130, -0.321000, -1.025150,
-5.747420, -1.698040, -1.572900, -0.945390, -0.276130, 0.042150, -1.055590, 0.245950, -0.458240, 0.082950,
-0.738290, -0.273830, -0.352790, -0.822710, -2.010280, -2.268390, -3.872200, -0.226500,
0.999920, 2.367680, -0.301080, -0.957500, 0.180270, 1.086190, -1.770870, 1.417540, 0.936920, 2.475340,
1.259150, 0.379600, 0.537810, 0.069290, -1.082410, 0.421580, 1.648940, 0.257500, 0.470820, -0.601210,
1.052880, -0.028160, 1.095970, -0.322250, -0.057260, -0.410730, 0.361240, -0.041670, -0.160090, 0.353750,
0.094610, -0.539160, 1.753030, 0.455460, -0.220420, 0.296840, 1.031680, 1.452000, 0.114680, -1.090890,
-1.547490, -1.320840, -0.101900, -0.012840, -0.023670, -1.117270, -0.306670, -0.329720, -0.731810, -1.363780,
-0.191720, -0.864660, -0.202300, -0.156460, -2.119000, -0.560740, 2.880100, 0.454060, 0.706880, 0.360870,
-1.657920, -0.219680, 0.155630, -2.260710, -0.728110, 1.449290, -0.021000, 0.214160, 0.682290, -1.109760,
-0.640160, -0.600610, -1.014150, -0.625560, -0.535070, 1.094520, -0.581830, -4.589410, 0.167500, 0.346740,
-0.326790, 1.002440, -1.069990, -2.005250, -0.049170, 0.406350, 0.632500, -0.688850, 1.151890, 0.231260,
0.394590, 0.021100, -0.959990, -0.310590, 0.179970, -2.334070, -0.118520, 1.701500, 0.206480, 0.082240,
-0.554890, 2.029230, -0.708300, -1.243670, 0.535990, 0.216890, 2.930800, 0.378830, -2.037440, -1.094160,
-0.129640, -0.861310, -2.245000, -0.826800, -1.833360, 2.612060, 4.035090, 0.121440, -2.928690, -0.900480,
1.308220, 0.499330, 2.110020, 4.814970, -1.374830, 0.561250, -1.626510, 0.343740, 2.132350, 1.790760,
-0.584860, 0.032300, 1.140340, -0.601300, 0.230430, -1.150150, -0.314770, -0.825980, -0.307260, 8.795040,
-0.951060, -2.862260, -0.290880, -0.433490, -1.297920, -0.192830, 1.112050, -2.576250, -1.671200, 0.161480,
0.099550, 1.442840, 0.807480, 1.840530, -0.711180, -0.583240, 1.503460, 1.009760, 0.033400, 0.563400,
-0.251740, -2.946460, 3.781610, 1.764030, 0.099260, 2.010960, 0.907990, -3.347090, -0.606390, 6.770640,
0.648570, -0.638800, -1.670180, 1.111640, 1.070390, 3.519890, -1.709060, -1.941980, 1.009820, -0.210420,
-0.530440, -0.342770, -1.258470, -1.365430, 1.730600, 1.671060, 2.167210, -0.709730, 2.682430, -0.722610,
-3.365400, 0.981220, 1.761770, 0.422550, -0.611740, 0.284150, -0.808690, 0.249420, 0.745130, -0.491500,
-2.156060, -0.668490, 0.062760, 0.056350, -0.056720, -0.761640, 0.785730, 0.114830, 1.826080, -0.088250,
-1.111890, 0.146030, 0.195460, -0.192380, 0.006730, 0.547610, 2.491730, -1.462770, -0.807600, 0.041400,
-0.035520, 0.749450, -0.813040, 0.069750, 0.791210, 0.161690, 0.608030, 1.088970, -1.094970, -1.775030,
-1.382260, 1.838340, -0.815820, -1.526140, -1.787710, -0.597550, 0.237410, 0.160230, 2.027180, -0.582650,
4.023540, -0.419270, -2.568520, 2.846210, 1.176530, 0.114810, -0.326100, 1.660220, -0.384010, 0.674280,
-0.418280, 0.111080, -0.929690, -1.247790, 0.040840, 0.883090, -1.322520, -0.862270, -0.306150, 0.128040,
1.069340, -1.732370, -0.092110, -0.437740, 0.577300, -1.446450, -0.782240, -0.603960, -0.190450, -0.713450,
3.326150, 0.416860, 0.955910, -1.165700, 0.366440, 0.719040, 1.050170, 0.458530, -0.104560, 0.037740,
1.012700, 0.359060, 0.473940, -0.620390, 0.973220, -0.351700, 0.972950, 0.953690, 0.612800, 0.237350,
0.833860, 0.625540, 1.409600, -0.125410, 0.538390, 0.641190, 0.344440, 0.453620,
-0.463530, -2.065870, 0.571660, -0.069160, -0.519710, -2.239530, -0.968860, -0.859270, 0.537200, -0.336660,
0.289210, 1.244220, -1.095610, -5.416210, -0.726830, 1.418760, 3.128260, -1.047170, -0.438290, 0.531910,
-0.421390, -0.579450, 0.085700, 0.057970, 1.514270, -0.867850, 2.299550, -1.428850, -0.356380, -0.599040,
-0.279720, 1.047460, -0.841700, 0.161970, 1.972360, -3.094660, -3.050350, -0.089020, 0.555240, -0.967080,
-2.163660, 2.840600, 5.077650, -0.942640, -1.665780, 0.531370, -1.150170, -1.795430, 0.643660, -0.928920,
0.783190, 1.049330, -1.221160, 1.072630, -0.591370, -0.642530, -1.326380, -0.530080, -0.999030, -6.233670,
-1.411010, -1.003800, 0.316530, -0.007930, 0.805070, -1.500130, 0.263060, -0.499440, 0.425140, 0.579630,
-0.649920, 0.462390, 2.300820, 2.708150, 0.940350, -0.798560, 2.428650, -0.737340, -0.113070, -2.834360,
1.594940, -1.478030, -1.223780, 0.014870, 1.309020, 0.694830, -1.250310, 6.444050, 2.098230, 0.086980,
-1.007060, 0.270480, 0.864040, 1.002690, -1.632140, 0.173160, -0.689270, -0.479460, 0.904630, 1.068400,
0.749620, -0.286310, -0.146970, -0.813190, -1.530850, -0.919850, -0.425000, 0.593700, -2.010400, -2.908750,
1.351500, 1.558300, -0.769890, -0.717540, 0.402210, 0.902350, 0.090430, 0.271470, 1.320900, 1.066750,
0.213670, -2.161030, -2.821430, -0.124430, 1.588630, -0.746320, -0.743350, 1.484320, -0.351990, -0.021560,
-0.185620, -0.576370, -1.135200, 1.707400, 2.365640, -0.394580, 0.566830, -0.249040, -0.766560, -3.831750,
1.431530, 2.893210, 0.499700, -0.453930, -0.577020, 0.062190, 0.164880, 0.865330, -2.244050, -0.494180,
-1.196760, -0.038580, -4.306680, 0.426780, -0.357350, 0.303790, 4.847090, 3.159250, -0.196330, 0.163680,
1.016470, -0.557280, -3.675420, 2.321230, 2.768570, 0.795250, 0.287310, -2.100030, 3.608950, 1.401930,
0.937860, -4.991420, 0.376840, -1.959050, -1.064180, -2.309080, 0.723160, -0.435500, 1.197010, 4.702960,
0.596370, -0.899220, -0.188830, -0.250170, 0.088250, -3.555710, 2.145880, 4.457720, 1.529710, -0.608280,
-0.101840, 1.932180, 1.626570, -0.875490, -1.146490, -0.396250, -2.223140, 0.192740, 0.275200, -0.477800,
0.525320, 0.334950, 2.900230, -0.332500, -0.255340, 0.597760, 0.866130, -2.344710, -1.639870, 1.199240,
2.592320, 4.035750, 1.367410, -2.071230, 2.414340, -3.807480, -0.383160, -1.777380, -0.675750, 0.327200,
-1.609610, -1.603290, 0.421160, 3.865540, 0.787130, 3.231700, 0.414720, -0.171700, -0.533490, -0.784530,
0.516410, -2.085080, -0.523370, 2.314420, -1.213130, -1.498200, 0.631600, 0.973890, -0.965750, -0.746740,
-2.891440, -1.257160, 2.033400, -3.439020, -1.015050, -1.433010, 0.609100, -0.080010, 3.061960, 4.007680,
0.553310, 0.133180, 1.091880, -0.614590, -1.854030, 0.209070, 0.837620, -1.868430, 0.097670, -0.315380,
-1.884610, 0.870640, 0.986540, -2.286340, -1.610720, 1.578300, -0.915200, 1.542480, 0.214890, 2.977800,
-0.016140, 0.888110, -0.452880, -0.155010, 0.890810, -0.729870, 10.311320, -0.160990, 0.042270, -0.814960,
4.967810, -0.843890, 0.414370, -0.050430, 0.363150, 0.518210, -0.212370, -0.010010, 0.604580, -0.783040,
0.798140, -0.990610, 1.432320, 1.660180, -0.411090, -0.422320, -2.150810, -0.601670,
-0.694920, 0.613820, 0.623150, 1.305930, 0.472760, 0.018500, 0.187680, 0.898730, -0.791980, 0.517790,
-0.140970, -0.122660, -0.357000, -0.832960, -0.218590, -0.221420, -0.780870, 0.579570, 0.423040, -0.857950,
-2.078220, 0.391890, -0.264430, -0.250610, -1.503810, -0.739360, 1.693780, -0.054650, 0.664240, -0.481050,
-0.695470, -1.042050, 0.749230, 0.357210, 0.000160, 1.317950, -0.815230, 0.415420, 0.041920, 1.620710,
-0.570640, 0.269700, -0.170970, 0.543920, 0.386790, -0.246700, -1.302940, 0.408590, 0.180910, 0.304210,
-0.188980, -0.393870, 0.123210, 0.099170, 0.525430, -0.345360, 1.075590, 0.193870, 1.006700, 0.196850,
0.281850, -1.130580, 0.609740, 1.505030, 1.198710, -1.269780, 0.109040, -0.433930, -1.130490, -0.402010,
-0.935710, -0.836880, 0.718830, -0.038480, 1.235630, -1.467260, -0.145710, 1.668520, 0.238980, 0.031010,
-0.612360, 0.730110, -0.040360, 1.895630, -1.111510, 0.287590, 0.308850, 2.215510, 1.291460, 0.773440,
-1.038050, 1.908970, 2.433050, -2.100950, 0.719990, 1.361220, -0.260540, -1.279270, 1.282420, 0.256950,
0.595870, -0.135060, -1.023130, 0.693600, -0.244730, -0.388860, 0.761220, -0.910530, 0.268280, 2.699370,
-1.281160, 2.359470, -0.216600, 1.144060, -1.050410, 2.120170, 4.074300, -2.410680, -2.709110, -0.051190,
0.853400, 0.054100, -1.649220, 1.497070, -0.960060, 0.118040, -0.431450, -1.563260, 1.527990, 0.938760,
-1.360580, -1.744880, 1.084570, -0.312150, -0.673510, 0.479190, -0.501320, -2.742050, 0.255780, 3.250580,
-0.354490, -1.877740, -0.435590, 1.475110, -0.681840, 0.074700, 1.639700, -0.557890, -0.212350, -0.525510,
-1.022450, 4.091340, 0.142350, -0.865360, -2.366700, 0.033810, -0.565930, 1.539900, 0.319780, 0.113090,
-1.376110, -0.074370, 3.765630, -0.955200, 1.424740, -0.277810, -2.072750, 0.308460, 0.504030, 0.665470,
1.227850, -0.965820, 1.222370, 0.386920, 1.506430, 2.084970, -0.151960, -1.113510, -1.495420, -0.804450,
-0.153100, 0.773950, 0.661330, 0.467720, 0.418580, -0.289560, 0.636050, -0.457970, -0.504800, -0.616520,
0.902670, 0.726200, 0.672630, 0.181190, 1.727490, -0.372200, 0.310110, 1.403430, -0.641730, 1.055260,
0.216540, 0.110440, 0.868340, -0.969730, 1.004010, -0.843220, -0.331920, 0.454720, -1.289440, 0.544650,
0.757990, -5.516620, -1.573610, -0.937280, -0.306420, 1.456590, -1.607510, 1.675880, -1.174550, -2.408730,
-0.880340, 1.422090, 0.336120, -0.769180, -0.691850, 0.619300, -0.092900, 0.580750, -2.533140, 1.387110,
-0.891640, 1.297250, -1.667000, -1.629220, -1.565520, 1.316260, 0.667200, 0.262150, -1.029880, 0.804190,
0.432320, -0.660890, -0.503340, -0.719870, -0.644310, 0.552470, 1.062000, 0.291560, -0.233310, -0.108680,
-0.561620, -0.939130, 2.281170, 1.172820, 0.515310, 0.497190, 0.413510, -0.178060, -0.401640, -1.640360,
0.218160, 0.400410, 0.342340, 2.406380, 2.951990, -1.201330, -0.540630, 0.154150, -1.825690, -0.313410,
-0.076840, -0.588820, -0.650190, -2.428770, -0.486670, -1.152320, -3.121970, -0.010720, -0.213260, -0.313190,
-1.449310, -1.012110, 0.370630, -0.333660, -0.022970, -0.666820, 0.082300, -1.113780, -0.448760, 0.187280,
-0.946630, -0.796200, -0.790920, -1.147390, 0.128160, -1.107500, -0.759210, -0.047460,
-0.428630, -0.840950, 1.324980, -1.006860, -0.773700, 0.158260, -0.904850, 0.745910, 0.221010, -0.913210,
2.844950, -0.083160, -0.645040, 0.221320, 0.009620, -0.423590, -0.000210, -1.027140, -1.053810, 0.594700,
-1.703690, -1.354910, 0.540440, -0.960060, -1.750500, -0.850660, 1.125070, 0.321680, -1.125690, -0.562540,
0.669970, 0.227830, 0.950640, -0.268530, -0.561830, -0.109770, 0.202850, 1.095760, 0.392870, -0.108240,
0.089050, 1.186520, 0.581480, -1.566600, -1.614630, 2.083850, -2.729930, -3.965320, -1.361890, 0.491740,
0.491730, -1.968330, 0.176800, -1.089330, -0.860230, 0.127390, -0.075090, 1.034090, -0.183180, 1.135660,
-0.621040, -0.487310, 1.289310, -0.089550, 0.719840, -0.512670, -1.175470, -0.471090, 0.191080, 0.213170,
-1.798970, 0.873570, 0.425500, -1.388220, 0.701050, 0.647840, -1.703410, -2.751970, -1.136070, 0.154810,
-0.671750, 0.048170, -1.625760, -0.078180, 0.749200, -0.058160, 0.811790, 1.383420, 0.006880, -1.017660,
0.379130, -0.521700, 0.241940, -0.170870, -0.711300, 0.190600, 0.776770, 0.799850, 0.097660, 0.335290,
0.680420, -1.745630, -0.802040, 0.759050, 0.859730, -2.050570, -0.517870, 2.196440, -0.209470, -0.712810,
-0.409270, 1.666530, -0.365020, 0.176460, 1.668600, -0.343400, 1.100680, 0.934790, -2.370200, 0.792410,
0.353930, 0.683890, 0.676000, 0.475240, -0.614640, -0.270880, -0.132210, -0.182900, 0.815800, 1.438850,
0.850430, 0.420250, 0.814730, 0.458870, 0.062890, 0.559020, -0.776640, -0.095160, 0.719450, 9.370850,
-3.006730, 0.720770, -1.313210, -0.258100, 0.523600, -0.678600, 0.446560, -1.959970, -1.092190, -0.170160,
0.903210, 2.182610, 0.014130, -0.572650, -1.880150, -0.937780, 1.416210, 0.827130, 0.288140, 0.533180,
0.218790, 0.646520, 5.048350, -0.108320, -2.013870, 0.045090, -0.277280, -1.398040, -1.703210, 0.609550,
-1.380470, -2.727260, 1.593780, 0.528130, 2.775670, 1.509030, -1.589030, 0.181440, 0.507640, -1.137210,
0.429150, -0.798350, 1.576920, -1.314870, 0.589060, 1.614360, 1.939450, -1.745190, -1.390550, -0.302510,
-1.454260, -0.241210, -0.872200, -0.694530, -0.157800, 0.160440, 0.532970, 2.177160, 1.421890, -0.078940,
-0.869720, 0.287450, 0.080810, -0.276660, 0.063970, 0.998110, -2.922090, -1.859360, -0.390150, -1.492610,
0.620430, -1.300610, 0.861760, -0.069630, -0.634830, -1.957440, -0.315560, -0.911680, 0.420280, 0.463770,
-0.352380, -0.083360, -0.812200, 0.281180, 0.789960, -0.315530, 0.531940, 0.568380, -0.269340, -0.058880,
0.389640, 0.788770, -0.939990, 0.031370, -1.272500, 0.188340, 2.265130, 0.055550, -0.405500, -0.145890,
-0.270870, 1.043740, 1.710320, -0.042520, -0.022270, 0.260960, 0.413680, 0.896450, 1.325190, -0.308250,
0.231450, 0.892570, 1.660540, -4.694160, -0.096920, -1.098050, 0.496430, -0.588130, 0.558030, 0.101290,
0.643140, 1.043850, 0.703670, 1.289980, 0.375260, 0.229280, -0.771160, -0.145690, -1.106080, 0.524490,
-2.207630, -1.247700, 0.230580, -0.922420, 0.471130, 0.373380, -2.143740, -0.759010, -2.339910, 0.368870,
-7.116350, 0.400660, -1.296280, 2.420910, -0.323250, 1.311750, -0.151500, 0.399660, -0.854940, 0.143810,
-0.173020, 0.454740, 0.687490, -0.751980, -0.452980, -0.146900, 0.741100, -0.085630,
0.650230, -0.762090, -0.123950, 0.251990, 0.197010, -0.525310, 0.823170, -0.500100, -0.285610, 0.289720,
0.397010, 0.505340, -1.012180, 0.368790, -0.079260, -0.714680, -0.211640, 0.161090, 0.994430, 0.357380,
0.632770, -0.238460, 0.090670, -0.567290, 0.036160, -0.544270, -0.143750, -0.287940, 0.847930, -0.717230,
-0.723240, -0.524640, 0.603610, 1.562740, 0.188400, 1.214210, 0.840730, 0.195740, -1.477050, -6.192490,
-0.294870, -0.424620, -0.088010, 0.507360, 0.019220, 3.012110, 0.525900, -0.503180, 0.168850, 2.238690,
-0.753030, -0.333980, -0.539820, 0.721030, 0.731990, 0.345760, 0.826030, 0.670000, 0.485150, -0.647030,

0.846560, -0.275580, -0.671830, -0.082840, 0.969640, -1.037830, 0.463080, -0.148460, 1.863730, -0.500120,
-0.904410, 0.045130, 1.518930, 0.434560, -0.676780, -1.389540, 0.463650, 0.583670, -0.644720, -0.822420,
-0.611500, -0.801120, -0.336420, 1.246690, -0.455280, 0.816460, 0.486180, 0.490040, -0.620400, 0.608410,
0.178560, -0.570480, 0.390810, -0.979780, -0.716070, 11.171580, 0.993450, 0.064600, 0.037370, -0.500180,
-0.042840, 0.141730, 0.811390, 0.575410, -0.464640, -0.859940, 0.869850, -0.392880, 0.966350, -0.200700,
1.008200, 5.334930, -0.624210, 0.557260, -1.283670, 0.586760, 0.185470, 0.622340, -0.647540, 0.670970,

0.184020, -1.095520, -0.027820, -0.438120, -0.504290, 1.407280, 0.310500, -0.347790, 1.010420, -0.216480,
-0.389500, 0.195910, -0.134950, 1.438250, -1.186360, -1.215250, 0.523870, -0.846560, 0.281160, 0.085760,
-1.145370, -0.974470, 0.112810, 0.191190, -0.582620, 0.711270, -0.932530, -0.516550, -1.149790, -1.452030,
-0.650820, 0.674450, 0.516650, -0.110430, -0.347630, -2.009670, 0.680540, 0.436340, -0.396480, -2.021150,
0.279800, -0.034580, 0.208750, 1.238260, 0.491590, -0.357830, 0.583600, 0.253760, -0.632710, -0.158420,
0.192930, 1.141130, -0.532880, 0.333120, 0.774270, 0.489400, -0.000040, 0.262350, -0.759980, -0.590790,

-1.017370, 0.316440, 0.759830, -0.997640, 0.716370, -0.722100, -0.637060, 0.062210, 1.827140, -0.459680,
0.196870, 0.282540, 0.319600, -0.953690, -0.727710, -2.214250, -0.318040, 0.166130, -1.093310, 0.348740,
-1.222500, -1.957890, -0.265600, 0.104140, -0.078770, -0.208120, 0.731520, -0.021330, 0.564400, 0.938680,
-0.560100, 0.788570, 0.141920, 0.732230, 0.052400, 2.002850, -0.903240, 0.104260, 0.613230, 0.500880,
0.528420, -0.024290, -0.537270, -3.318380, -0.177660, -0.348970, 0.549620, 0.368370, -0.419220, -0.095530,
-0.690260, 3.291760, -0.248760, 0.346930, -0.642180, -0.741490, 0.826060, -0.371490, 1.053390, -0.706640,

-0.650000, 0.554950, 0.728520, 1.457310, 0.200260, -0.367690, -0.021360, 0.582590, 2.030870, -0.895940,
0.419190, 0.938100, 0.358060, -0.597150, 0.480870, -0.100210, -0.075750, 0.964750, 0.496840, 0.286860,
0.283270, 0.705150, 0.246480, 0.613800, 1.277390, 1.984380, -0.440500, 0.568430, 0.137420, -0.875970,
0.273700, -0.632770, 0.105730, -0.454160, -0.781980, -3.234380, 0.732310, -0.732210, -0.791650, -5.076620,
-0.400040, -0.684320, -0.498370, 1.056540, 0.803750, -0.645480, -0.781190, -1.518630, -0.206220, 1.164600,
-0.927280, -0.507590, -0.310950, -0.136280, -0.181890, -0.829220, 0.873350, 0.535520, 0.717790, -2.301840,

-1.467950, 0.362740, -0.187470, 1.969710, -2.687030, -71.094482, -0.023980, -2.523490, -5.587820, -0.339290,
-0.181280, 1.374000, 1.430060, 1.915620, -0.047900, -8.644270, -0.355810, -3.895250, -0.291910, -2.120980,
-0.560910, -0.532000, 1.251620, -2.045110, 1.754600, -0.522410, -1.667690, 0.962110, 0.034220, -15.110050,
0.791520, -0.281030, 1.179340, -1.502310, 0.076350, -1.056650, 0.730860, -1.921000, -7.943810, 1.469400,
-0.321310, 0.959320, -0.215860, -4.213310, -0.944160, -8.930550, -0.244810, 0.942060, -2.386470, -0.491660,
0.834120, 0.592760, -1.836010, 1.293490, -0.954490, 0.499100, -1.444700, -0.360390, -0.158340, -2.205880,

0.500990, -0.259470, 0.124000, -0.520910, -0.194330, 0.472230, 0.204490, 0.336920, -1.628290, -0.300060,
-0.135090, 0.045390, -0.577250, -0.238780, -0.213500, 0.152500, -0.594810, -0.188090, 0.466670, -0.326720,
1.036130, -0.674930, 0.113460, -0.338660, -0.849150, -0.519040, 0.225580, -0.309060, -0.052900, 0.266210,
0.610330, -0.648980, 0.992080, -0.449880, 0.085940, 1.952740, 0.815830, -0.324230, 1.423730, 0.768790,
0.481560, -0.857000, 0.164730, -0.126350, 0.501200, 0.651890, 0.138130, 0.589060, 2.114990, 0.611640,
0.305170, -0.866800, -0.522550, 0.598450, 1.031530, 0.435020, -0.448710, -0.387710, -0.456550, -0.109530,

-0.474130, -1.380760, -1.168450, -0.374460, -1.825690, 1.239720, -2.316350, -1.933500, 0.558440, -0.349290,
0.761920, 0.385040, 0.404520, -0.389110, 0.387340, 0.752260, 0.179640, -0.153320, 0.357320, -0.426450,
-0.719440, 0.204790, -0.055110, -0.007150, 0.568940, 0.140660, -1.472780, 0.029740, -0.154300, 1.460850,
0.418020, 0.541240, 0.000220, 0.627720, 0.532430, -6.077510, 0.916770, 0.412490, 1.677610, 1.107630,
-0.722600, 0.271640, -0.472030, -0.755170, -0.684500, -0.703780, 0.261490, 0.784450, 0.573670, 0.228010,
-0.851250, -8.251840, 0.212490, -0.734900, -0.338330, 0.367140, 0.111800, -0.124170, -0.684090, -0.416050,

0.545050, -2.377660, 0.579800, -2.156630, -1.155400, 3.849880, 0.139080, -1.035120, -1.895510, 0.644000,
-0.414080, -0.144560, -3.667970, 0.957770, -1.038710, -0.624620, -1.033670, -1.595810, 0.495520, 1.203460,
-0.743740, 1.313590, 2.777660, 0.987170, -3.000000, -0.318320, -2.098870, -0.877720, 2.516740, -2.594050,
-0.076410, -0.123170, 0.949930, -0.589120, 0.920440, 0.345470, -0.931280, 2.809740, 0.182180, 0.122170,
0.005050, -1.018510, -0.738130, -0.373290, -1.024240, 0.848170, -0.722170, 1.206100, 1.879310, 0.009630,
-0.179660, -0.720130, 1.622400, 1.339030, -0.399390, -0.805460, 0.058140, -0.697360, -0.419270, 0.711510,

0.012440, -4.782600, -0.987890, 1.620130, -0.386890, 1.095140, 0.655760, -1.337360, -0.013460, 1.415770,
-3.803320, -0.228550, -0.459900, -0.415040, 0.800580, 2.350960, 1.161510, -1.010750, 0.641240, -1.968950,
0.522750, -0.461580, -2.454440, 0.626730, 0.797780, -0.797800, -0.519520, -0.298240, 1.568060, -1.483000,
0.166350, -1.102770, 0.108080, -0.793160, -0.545180, 3.658130, -0.634780, -0.317320, 0.852350, 2.547350,
0.652540, -0.755670, 0.632000, -0.310700, -0.230870, 0.531060, 0.440440, 0.391150, -0.263510, -1.405880,
0.005300, -0.852340, 0.311210, -0.468440, -0.626580, -0.067950, -1.307020, 0.077270, 0.374870, 0.475220,

-0.907520, -0.589950, -0.673640, 0.366930, -0.675440, 1.953420, -0.772260, 0.020400, -1.135230, 1.229870,
-0.922280, -0.534520, -1.337110, 0.474090, 0.603390, -1.145340, -1.061420, 0.368150, -0.270140, -0.723770,
-0.062100, -0.004190, 0.371090, -0.559520, -0.828730, -0.605030, 0.574410, -0.727900, -0.329600, -0.287550,
0.069420, 0.953740, -0.445560, 0.809260, 0.008380, 1.990920, 0.569580, -0.695140, 1.543890, 1.505360,
0.196530, 0.471200, 0.061970, -1.349410, -0.928570, -0.913410, -0.461550, 0.639010, 3.564030, -0.841610,
-0.167440, -0.851330, -0.123770, 0.391790, -0.473560, 0.448180, 0.296840, -0.214530, 0.703880, 0.500760,

0.575340, 1.253820, 1.054630, -0.944410, -0.167090, 0.328820, 0.854950, 0.621450, 2.524070, -1.248640,
0.300330, 0.849700, 0.147820, -0.103980, 0.226760, -0.758650, 0.804050, 1.616540, -0.105380, 0.717400,
-0.654470, 1.230630, 0.648100, 0.300870, -0.210470, 0.852510, -0.212620, 0.755510, -0.209030, 0.369610,
-0.094810, -0.847560, -0.398730, 0.704250, -0.479330, 8.896150, 0.981120, 0.590580, -0.384960, -2.904470,
-0.033060, 0.886930, -1.086820, 1.466350, -0.322980, -1.384830, 0.403350, -1.849010, 1.058950, 0.096400,
-0.917440, -1.809720, 0.817300, 0.232920, -0.054870, 0.403370, 0.278960, -0.215110, 0.556350, 0.530180,

-0.059540, -0.194940, 0.570170, -0.779410, -1.428850, -0.391210, 0.488580, -0.527990, 1.104050, -0.623200,
-0.789780, 0.393750, 1.368880, 0.694680, -0.722680, 0.603260, 0.511130, 0.721640, 0.638330, 0.698720,
-1.656270, 0.388910, -0.972590, 0.292240, 0.145980, 0.487210, -0.411910, 0.756040, -1.482500, -0.452070,
0.230820, -0.853930, -0.701330, -0.991700, -0.397470, 1.558800, -0.893650, -0.433590, -0.962050, -0.339670,
-0.060260, -0.068960, -0.626970, -0.401000, 0.011400, -0.377760, -1.021970, -0.968290, 0.145920, 0.752100,
0.673490, 3.796340, -2.315520, 0.629430, 0.487590, -0.055660, -0.352710, 0.653080, 0.815380, 0.280490,

-0.224390, 0.243600, 0.448450, 0.383690, -0.778270, -1.788440, 0.791890, -0.323310, -1.462220, 0.049320,
0.525330, -0.214850, 1.823530, 0.016210, -0.512280, 0.954340, 0.876950, -0.511620, -0.521260, 0.634540,
-0.463130, -0.539970, -0.095120, 0.540870, 0.656810, 1.238370, -1.770500, 0.475680, -1.994820, 0.551410,
0.596260, 0.557600, 0.302500, -0.221040, 0.196550, -6.722110, -0.661110, -0.550510, -1.617460, -1.020350,
0.308260, 0.717510, 0.501340, 0.755510, -0.935640, -0.177560, -0.642090, 0.441000, -0.582950, -0.475850,
-1.083530, -0.399230, -2.327930, 0.302700, 0.297010, -0.222340, -0.074200, -0.212760, 0.555950, -1.168410,

0.370520, 0.473250, -0.135360, -0.353610, 0.393290, 0.274910, 0.436890, -0.678320, -0.138690, -0.890920,
0.109880, -0.260550, 0.339420, -0.586040, 0.380250, 0.029870, 0.122780, 0.433000, -0.584600, 0.152040,
0.040580, -0.237710, 0.082350, 0.680500, -0.026640, 0.283040, 0.306470, -0.312670, -0.254870, 0.518510,
-0.121570, 0.077850, 0.425070, -0.851540, -0.648880, 3.330960, -0.935560, 0.005560, 1.593130, -0.440530,
0.713960, 0.928110, 0.207380, 0.022560, -0.813650, 0.930220, -0.360010, -0.136540, 1.258340, 0.146580,
0.039180, -1.775070, -0.343190, 0.767630, 0.249820, 0.485820, 0.028390, -0.418960, 0.871430, -0.269630,

-0.106320, 0.306570, 0.776610, -1.002140, 0.195410, -1.495030, -0.781000, -0.436470, -0.878750, -0.610720,
1.787700, -0.365110, 1.924770, -0.483090, -1.618350, 1.069560, 0.468620, 0.120530, -0.902510, -0.021820,
0.226970, -0.689120, -0.744160, -1.062250, 0.539200, -0.001150, -0.078290, -0.336240, 0.079770, -0.408780,
0.835690, 0.883160, -0.166830, -0.503200, 0.129570, -0.761780, -0.799760, 0.596170, -2.011530, -2.283050,
-1.714010, 0.195030, 0.565930, 1.011440, -0.720020, 0.573440, -0.299150, -0.054750, -2.548630, -0.980670,
0.769370, -4.324830, -0.841510, -0.414360, -0.013710, 0.619710, 0.660660, -0.322770, -1.047410, -1.096830,

0.924190, -1.047090, -0.920590, 0.066410, 0.656720, 0.660890, -0.738650, -0.291420, -0.707390, 1.092150,
-0.210930, -0.783710, -3.638150, 0.344230, 0.795850, -1.813470, -1.049970, -0.652130, -0.374640, 0.712350,
1.008130, -0.076430, 0.487230, -0.245100, -2.898100, -3.027820, -0.088790, -0.746710, 0.637350, -0.788270,
-0.437810, 0.379950, 0.958640, -0.316270, 0.659200, 2.664120, -0.571040, -1.083410, 2.335430, 2.392030,
0.703130, 0.774540, 0.645420, -3.679610, 0.406090, -1.075390, 0.564220, 0.777240, 1.710200, 0.319180,
-0.786530, -6.860840, -0.323220, 0.147980, 0.035450, 0.590550, 0.245690, 0.095230, 0.788760, 0.829340,

-0.375160, 0.484650, 0.142760, -0.695370, -0.316300, -13.529110, -0.676010, 0.894380, 0.111390, -0.202880,
0.947620, 0.423090, 0.945850, -0.114920, -1.799430, 0.576110, 0.092340, -0.424760, 0.988550, -0.252970,
0.137350, -0.604330, -0.138580, -0.238070, -0.187850, -0.257510, -0.279550, 0.698290, -0.115530, -0.367760,
0.165450, -0.439450, 0.743180, 0.380560, 0.177390, -2.149430, 0.424060, -0.451360, -0.765170, 1.533110,
-0.010450, 0.628300, -0.661750, -1.005820, 0.789140, -2.126990, -0.744870, -0.574980, -0.535270, -0.909300,
0.113590, 4.633260, -0.327370, 0.328820, -1.073400, -0.145160, -0.380300, -0.463740, 0.391250, -1.644820,

-0.419380, 0.553390, 0.379380, -0.146430, 0.037670, -0.271750, -0.739850, -0.287660, -0.679090, -0.414170,
0.788530, -0.742230, -0.007000, -0.131730, -0.378900, -0.320880, -1.094780, 0.043960, 0.384360, -0.087100,
-0.458710, -1.532060, -0.387580, 0.033780, -0.517200, -0.049180, 0.625200, -0.413360, 0.432300, 0.020680,
-0.155590, 0.618530, 0.798530, -0.723020, -0.885520, 1.350590, 0.588330, -0.319950, 1.888680, 0.679760,
-0.588020, -0.299250, -0.742720, -1.441680, 0.313550, 0.055240, 0.154980, -0.933490, 0.384740, -0.747470,
0.267030, -0.040740, -0.945620, 0.713470, -0.876970, -0.601320, -0.059160, -0.343950, 0.781850, 0.786880,

0.434540, 0.721450, -0.432510, -0.682250, -0.346690, 0.601220, -1.627910, -0.103830, -0.375410, 0.438760,
0.805220, -0.043750, -0.573910, 0.419510, 0.949490, 0.582880, -0.173600, -0.103710, 0.701800, 0.353000,
0.430630, 0.121070, 0.545220, -0.958940, -0.718050, 0.385030, 0.346590, 0.776180, -0.559860, -0.532280,
0.171330, -1.567200, -0.416480, -0.886400, 0.490280, 3.953890, -0.053780, 0.396340, 0.496590, -0.370080,
0.309790, -0.954230, -0.390920, -2.825170, -0.885820, 0.458740, 0.241770, -0.087620, 3.157760, -0.404370,
0.252890, -0.402590, 1.541540, -1.608550, -0.158860, -0.318990, 0.579690, 0.349720, -0.524720, -0.077100,

-0.411520, 2.987300, 0.857980, -0.396600, -0.933410, 0.255300, 0.273140, 0.222350, -1.016730, -1.693620,
0.750160, 0.405810, 0.965010, 0.255720, -0.006820, -0.814580, -0.476350, 0.874570, 0.597790, 0.703310,
-1.297400, 0.337890, 0.618280, -0.889430, 0.191490, 0.934020, 0.623920, 0.779370, -0.795980, -0.267870,
-0.192630, 0.829060, -1.003170, -0.569910, 0.301850, -1.859820, -0.350640, -2.747190, 1.730380, 2.307240,
1.406820, -0.280420, -1.262120, -0.020050, 0.924680, 0.075680, 1.265940, -0.632890, -0.780320, -0.393570,
0.821860, -2.072150, -0.147460, 0.821380, -0.539230, 0.506850, 0.714570, 0.912380, 0.638340, 0.110550,

0.452410, 0.680780, 0.660850, 0.660850, -1.177490, -0.315580, -0.543430, -0.677890, 1.386220, -0.627480,
-0.080380, 0.452430, 1.014190, -1.946540, 0.358920, -0.307980, 0.303360, 0.982270, 0.245900, 0.507260,
-0.879710, -0.067270, -2.103510, 1.380410, 0.865530, -0.256850, 0.234000, 0.049300, 0.502600, 0.839150,
0.889750, -0.406460, -1.474350, -0.523680, -0.997650, 2.170820, -0.079220, -2.432910, 1.116080, 1.863570,
-0.304570, 0.730900, -0.455200, -0.326420, -1.032120, -0.726470, -0.141500, -0.907290, 0.728130, -0.898540,
-0.335690, -3.247870, 0.806600, -0.469230, -0.046910, -0.661400, -0.881580, 0.745270, -0.763030, -1.224590,

-1.308850, 0.229180, 0.118220, 0.825930, 0.027770, -0.179750, -1.297830, 1.777330, 1.186150, 0.804850,
0.136290, 0.840890, -1.044160, -1.690390, -0.218200, 0.722040, -0.973140, -0.849420, 0.700600, -0.713780,
0.890730, -0.581100, -0.759790, -1.034860, 0.193030, -0.554700, -0.280200, 0.418940, 0.924700, 1.483250,
-0.217600, -0.313720, 0.881180, -0.371570, 0.205970, -0.811140, -0.900660, -0.146940, 0.369700, 2.164040,
-0.638280, 0.712920, 0.141730, -0.527670, -0.388040, -0.135030, 0.411900, -0.854510, 1.008060, -0.149630,
-0.493340, -2.666320, 0.504390, -0.137060, 1.310880, -0.700290, 0.482760, -0.465280, -0.604980, 0.674870,

0.042080, 0.120380, -0.433140, -0.232330, -0.452060, 0.684160, 0.128260, -1.121950, -2.400700, -0.078420,
-0.230370, -0.951820, -0.618550, 0.045090, 0.722070, 0.006400, -0.324260, -1.029960, 1.208540, -0.411930,
0.679090, 0.024230, 0.634040, 0.534420, -0.824220, -1.286080, -0.203880, -0.385460, 0.025270, -0.078420,
0.577520, -0.473630, 1.306230, -1.604460, -0.601220, 0.281880, -1.078950, -0.273220, 1.731260, 3.030550,
1.027310, 0.246620, 0.394140, -0.157410, 0.562530, -0.296220, -0.250710, 1.106550, 0.195190, 0.793820,
0.312090, 0.043540, -0.679140, 0.306370, -0.597110, -0.365800, -0.881810, 0.272770, -0.980190, 1.574120,

0.652230, 0.730890, -0.424450, 0.426460, -1.001190, -1.034460, -0.974480, 0.063140, 3.198130, -0.269580,
-0.222400, 0.237210, 3.492560, 0.488930, -2.615420, -0.474840, 1.397220, 0.807840, -0.261150, 0.455930,
-1.023240, 0.016780, 0.036940, -1.211200, 0.680070, 1.469210, 0.560270, 0.593020, -1.574220, 0.347360,
-0.173990, -0.051580, 0.266060, 0.637690, -0.091760, 1.239820, -0.614080, 0.616000, -1.532940, -2.403070,
-0.671380, 0.339180, -0.317370, 1.933530, 0.097000, 0.564140, -0.617810, -1.629660, -0.780960, -0.948540,
0.660440, 2.359770, -0.586600, 0.309480, -0.756730, 0.727310, -0.095700, -0.219210, -0.694080, 0.258260,

0.355320, -0.192840, -0.580870, 0.822800, 0.825560, 0.630740, 0.221780, 0.401360, -0.788490, -0.918350,
-0.060700, -0.153470, -0.145400, -1.361030, 0.036260, 0.808860, 0.637040, 0.505840, -0.436040, -0.016950,
0.540850, 1.046240, -0.095000, 0.612350, 0.028830, 0.018610, 0.025920, -0.573540, -0.229890, -0.020540,
-0.207370, 0.103560, 0.747010, -0.510780, -0.104750, -4.435810, -0.921730, 1.246640, 0.571040, 5.848310,
-1.015990, 0.681850, 0.046880, 1.096120, 0.106510, 0.817700, 0.135080, -1.233610, -0.758550, -0.485290,
-0.291530, -0.329340, -1.234320, 0.544540, 0.540010, -0.717280, -0.846680, -0.438370, 0.439380, 0.265710,

-0.670080, 1.023340, 0.644070, 0.932230, 0.539550, -0.533210, -0.777660, 0.423000, 2.531310, 0.389750,
0.395010, 0.901400, 1.388540, -0.646330, -0.702050, 0.130280, -0.034610, 1.053300, -1.457220, 0.494430,
-0.531700, -0.119940, -0.360560, -0.245580, 0.567990, 2.183910, -0.165790, 0.803660, 0.432420, 0.870580,
0.696780, 0.927640, -0.147510, -0.490180, 0.705130, -1.680310, -0.684790, 0.275570, 0.737320, 1.023600,
-0.122930, -0.551080, 0.663520, 0.116690, 0.573900, -0.305050, -0.593480, -1.039470, 0.249430, -0.966480,
-0.524430, -0.265890, 0.502150, -0.960790, 0.325160, -1.005330, -0.344220, 0.497400, 0.099910, -1.132200,

-0.673140, -0.888490, 0.531120, -0.271920, 1.417700, 1.201480, -0.784690, 0.986650, -2.586310, 1.531680,
-0.193060, -0.269110, -0.266770, -0.853790, -0.435400, 0.511490, -1.079770, -0.460950, 0.420270, -0.874680,
0.972150, 0.310720, 0.998910, -0.050660, -0.973450, -1.306360, -0.035190, -0.844510, -0.742060, 0.486740,
-0.000340, 0.413860, -0.163370, -0.946860, -0.192860, 7.329610, 0.540340, -1.165910, 1.121000, -0.908860,
0.444300, 0.747610, -0.890240, -0.289970, -0.636960, -0.141690, 0.419260, -0.110440, 0.994430, -0.043390,
-0.208440, -0.295130, 0.299980, -0.240520, 0.707110, 1.020450, 0.719750, 0.455330, -0.513570, 0.486790,

0.137470, -1.000610, 0.959510, -0.173980, -1.457200, 0.093900, 0.369190, 0.039090, 0.431520, 0.866850,
-0.641880, 0.596400, -1.105400, 0.968640, -0.079650, -0.527050, -0.427430, -0.427820, 1.195540, -0.149330,
-0.679510, 0.564430, -0.055080, -0.092610, -0.733740, -0.655760, -2.108450, 0.466160, 1.357650, 0.016310,
-0.495660, -0.507310, -0.377560, 0.523840, 0.476500, 0.855180, 0.767060, -1.652640, 0.618730, 0.032920,
0.199000, 1.237300, -0.152620, 0.753120, 0.904280, 0.351780, 0.418740, 0.070240, 1.193170, 0.725480,
0.330970, -2.128750, 1.166380, -0.328340, 0.087230, 0.574890, -0.210150, -0.247810, -0.520710, 0.070300,

0.813500, -0.822020, -1.291420, -1.452670, -0.312370, 0.827630, 0.002730, 0.317160, -2.947540, 0.173010,
-1.600610, -1.314480, -1.383280, 0.559960, -0.056720, 0.581270, -1.139170, -1.814490, 0.613780, -0.977120,
0.844810, 0.246930, 0.767800, 0.547830, -1.004670, -2.097870, -0.413220, -1.175880, -2.488140, 0.003670,
0.794400, -0.817310, 1.104750, -0.354170, -0.204760, -1.096350, -0.605080, 0.403560, 1.154980, 1.352910,
0.796130, -0.024010, 0.564700, -0.788590, -0.502700, -0.162130, 0.590770, 0.223630, 1.089220, -1.243550,
0.588000, 0.883500, -0.770350, 0.688680, -0.076120, -0.807170, 0.322710, -0.742470, -0.062930, -0.334600,

0.835610, -0.153550, 0.370000, -1.453520, -0.212280, -1.973440, -0.145900, 0.303480, -1.303480, -2.108010,
-0.697590, -0.015450, 0.392800, 1.517630, -0.274870, 0.970960, -0.633150, -1.043570, -0.925310, -1.324570,
0.480060, -1.188580, 0.216030, 0.059660, 0.347350, 0.290880, 0.887760, -0.205890, -0.455670, -0.806550,

-0.623800, 0.686520, 0.953860, 0.244790, -0.729000, 1.879660, 0.281570, -1.013770, 0.403350, 1.401320,
0.770120, -0.537990, -0.756810, -1.863330, 0.714290, -1.086030, 0.055830, 0.291140, 1.253470, -0.854300,
0.408090, 0.741730, 0.264890, 0.234160, -0.612220, -0.063050, -0.472630, -0.222600, 0.187000, -0.106220,

0.834600, -0.500470, -0.392460, 0.232650, 0.564710, -0.433290, -0.416190, 0.648500, 0.073560, -0.742650,
-0.479580, -0.371810, 0.116720, -1.061920, -0.547330, -1.276940, 0.179380, 0.464010, -1.612930, 0.921710,
0.234940, 0.376420, -0.187590, 0.366380, -0.280240, -0.577900, 0.515670, 0.454560, -0.962820, 0.038570,

-0.039000, 0.060050, 0.453730, -0.350720, 0.561620, -2.542460, -0.683280, 0.098350, -1.630620, -2.579150,
-0.168790, -0.279580, 1.085580, 1.462820, 0.614350, 0.511920, -0.548020, 0.172210, -0.921650, -0.526870,
-0.372090, -2.373970, -0.584370, -0.414380, 0.544080, 0.616550, 0.120200, -0.481850, 0.311700, -0.926830,

-0.803630, 0.644300, 0.707800, -0.799520, -0.304360, 1.367140, 0.304130, 0.181330, 0.826730, 1.740010,
0.114330, -0.843140, -0.338410, -1.134060, 0.191000, -0.742960, 1.055500, 0.058790, 0.339850, -1.137380,
-0.640250, 0.248380, -0.213260, 0.564240, -0.478130, -0.100010, -0.587120, 0.562870, -0.773160, 0.506790,

-0.512020, -0.784140, -0.352400, 0.459980, 0.479950, 0.437820, 0.281470, 0.179640, -0.143250, -1.605210,
-0.191150, -0.202140, -0.853120, -1.087190, 0.827800, -0.894680, 0.082920, 0.109000, -0.481000, 0.703190,
-0.492200, 1.332940, 0.452240, -1.287230, -0.361860, -0.866130, -0.399020, 0.725920, 0.337720, -0.801420,

-0.525330, -0.056110, 0.141150, 0.079960, 0.436120, -2.292320, 0.517430, 0.018780, -1.799650, -2.308130,
-0.859570, 0.504130, 1.054700, 1.368060, -0.330790, -0.053260, -0.294290, -0.516370, -0.775390, -0.492680,
-0.391670, 2.957270, -1.770330, -0.020530, 0.767680, -0.276760, 0.689100, -1.068630, -0.854620, -0.665820,

-0.382260, -0.195460, 0.908090, -0.979570, -0.353440, 0.670440, 0.263550, 0.829860, 1.032230, 1.786400,
0.341340, 0.339470, -0.236840, -1.365240, -0.110590, -0.623150, 0.384450, 0.640950, -0.550790, -0.485870,
-0.809660, -1.649990, -1.035600, 0.623040, -0.752310, -0.150730, -0.780300, 0.033080, -0.726500, 0.984100,

-0.005010, -0.463640, -0.562510, 0.786660, 0.145390, 0.832120, 0.970450, -0.645100, -0.638550, -1.099740,
0.153330, 0.469260, -0.810700, -0.837060, -0.653470, -0.212720, -0.108830, -0.227830, 0.494900, 0.099240,
-0.526520, -1.756010, 1.118490, -0.158800, -0.331740, -0.375450, 0.756190, 1.014960, -0.450260, -1.069270,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
  static UnitType Units[398] =
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (inp1) */
      0.0, -0.169340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.605430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.516570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.133920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.113400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.669510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.444310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.590570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.937720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.830520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.869710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.786990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.776390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.182690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.966700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.296420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.210180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.058580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.797170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.844310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.498580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.570160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.467960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.083140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.387880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.237490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.288650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.627180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.505170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.396050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.380230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.187940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.664410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.840340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.006630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.217520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.737880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.312810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.614030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.539830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.405000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.501690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.075120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.357540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.335010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.858440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.735210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.913370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.492810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.847410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.999490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.966610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.602730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.193300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.564830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.446190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.078530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.609230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.085620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.501290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.632010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.905860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.981690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.881870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.716140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.769420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.235600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.510640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.352720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.521520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.465090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.638540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.913380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.429580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.616030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.474230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.924930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.315270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.930350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.301050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.990710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.698180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.367440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.118510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.943420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.532560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.298190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.960400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.434670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.583520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.341610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.478140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.814470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.816840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.953640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.512730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.251760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.031300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.413150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.446240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.401260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.714180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.662380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.840620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.448360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.751780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.364510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.621780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.097850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.150270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, -0.616460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, -0.485740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.806180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.871290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, -0.313400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.362580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.500160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.157950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.445060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.891130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.378660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.400330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.257230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.279060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, 0.141790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.314370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.223870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, -0.352780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.919190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.413990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.441660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.403430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.099360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.081010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.863320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.418190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.596260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, -0.570570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.641390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.261310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.410200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.080670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.794960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.454300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.632350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.555310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.422110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.829240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.688480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, 0.975690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.661530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.746560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.147680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, 0.506450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.685960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.199940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.989870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, -0.569460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.531070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, 0.634500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.484460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.132570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.704820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.220530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, 0.413780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.438800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.083900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.649050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.757390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.565970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.778770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.379220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.428230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.207890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, 0.680010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.897740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.885700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.601190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.026420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.658210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, 0.716020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.289020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, 0.921910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.735520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.685040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.367040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, -0.010450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.532540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.244610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.355510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.942360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.396900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.943950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.379010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.458900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.437560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.083920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.661030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.561050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.950340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.088250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.647740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.633860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, 0.901100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.490270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.584080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.588880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.559530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.651430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.334130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.418270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.070970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.415920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, -0.426620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.993360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.670790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, 0.542740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.110850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.892140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, -0.337650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.011720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.899660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.918980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, 0.368500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.028630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.076140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.322710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.790570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.971990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.480760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.935430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.892380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.771970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.687730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, 0.409460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, 0.110460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.040500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.556970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.632800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.794670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.659020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, -0.430010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, -0.256990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.961060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.737800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.273190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, -0.913390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, -0.606590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.057530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, -0.578970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.974530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.045210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.922670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.598780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.425760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.778330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, -0.286130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.845550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, -0.212270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.635500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, -0.879170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.983120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.248650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.867050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, -0.831860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.283090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.924930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.649000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (hid11) */
      0.0, 0.026240, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, -1.119250, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, 0.095820, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.630540, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.448250, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -1.696330, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.775440, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, -0.135380, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, -2.311310, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, 0.369820, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.487510, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.603800, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, 0.264820, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -0.100810, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 0.699770, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, 0.018640, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, 0.243430, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, -0.694930, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -1.220290, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 0.857750, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, 1.093870, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.374530, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, 0.740140, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -1.067050, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.240040, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, -1.758860, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, 0.599180, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, -0.856960, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, -0.593860, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -1.326530, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -0.975720, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, 0.814550, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, 0.701630, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.750260, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, -0.152770, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.494810, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, 0.634370, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.453760, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -0.804070, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.653440, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, 0.486070, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, 0.561890, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, -0.097340, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.730150, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, 0.645180, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, 0.558170, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.228280, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, -0.461200, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.166180, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, -0.231670, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, -0.652900, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.837190, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.204900, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.369420, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, -0.335220, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, -0.069080, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.954390, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.738440, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 1.203080, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.280780, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.944150, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.897680, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, 0.255130, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, -0.672790, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.344790, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 0.757350, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, 0.851720, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.666040, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.578200, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
1.32723, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.06565, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
0.07597, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
0.41802, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
0.10120, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
0.00023, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
1.35949, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
0.16555, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
0.00482, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
1.10022, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
0.03855, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
0.36168, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
0.00916, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
1.42507, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
0.93651, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
0.00155, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
1.12525, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
0.00329, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
0.12803, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
0.12007, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
1.39956, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.42564, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
0.42924, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
1.30000, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
0.08266, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.74811, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
1.12785, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
1.08683, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
0.01156, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
1.01135, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.11494, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
1.36410, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
0.30533, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
0.03829, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
0.31652, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.22515, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
1.29746, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
0.00637, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.12979, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.75463, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
1.17285, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
1.42307, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.36064, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
0.04175, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
1.28993, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
0.00170, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
1.40095, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.05004, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.14360, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
0.36006, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
1.39828, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
0.01334, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
0.03930, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
1.18152, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.10163, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.14208, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
0.30932, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.38735, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
1.41496, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.53914, 0.500000, 2,
       &Sources[11128] ,
       &Weights[11128] ,
      }

  };



int net(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[268] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130, Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170, Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268}; /* members */

  static pUnit Hidden1[30] = {Units + 269, Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298}; /* members */

  static pUnit Hidden2[30] = {Units + 299, Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328}; /* members */

  static pUnit Output1[9] = {Units + 329, Units + 330, Units + 331, Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337}; /* members */

  static pUnit Special1[1] = {Units + 338}; /* members */

  static pUnit Special2[1] = {Units + 339}; /* members */

  static pUnit Special3[1] = {Units + 340}; /* members */

  static pUnit Special4[1] = {Units + 341}; /* members */

  static pUnit Special5[1] = {Units + 342}; /* members */

  static pUnit Special6[1] = {Units + 343}; /* members */

  static pUnit Special7[1] = {Units + 344}; /* members */

  static pUnit Special8[1] = {Units + 345}; /* members */

  static pUnit Special9[1] = {Units + 346}; /* members */

  static pUnit Special10[1] = {Units + 347}; /* members */

  static pUnit Special11[1] = {Units + 348}; /* members */

  static pUnit Special12[1] = {Units + 349}; /* members */

  static pUnit Special13[1] = {Units + 350}; /* members */

  static pUnit Special14[1] = {Units + 351}; /* members */

  static pUnit Special15[1] = {Units + 352}; /* members */

  static pUnit Special16[1] = {Units + 353}; /* members */

  static pUnit Special17[1] = {Units + 354}; /* members */

  static pUnit Special18[1] = {Units + 355}; /* members */

  static pUnit Special19[1] = {Units + 356}; /* members */

  static pUnit Special20[1] = {Units + 357}; /* members */

  static pUnit Special21[1] = {Units + 358}; /* members */

  static pUnit Special22[1] = {Units + 359}; /* members */

  static pUnit Special23[1] = {Units + 360}; /* members */

  static pUnit Special24[1] = {Units + 361}; /* members */

  static pUnit Special25[1] = {Units + 362}; /* members */

  static pUnit Special26[1] = {Units + 363}; /* members */

  static pUnit Special27[1] = {Units + 364}; /* members */

  static pUnit Special28[1] = {Units + 365}; /* members */

  static pUnit Special29[1] = {Units + 366}; /* members */

  static pUnit Special30[1] = {Units + 367}; /* members */

  static pUnit Special31[1] = {Units + 368}; /* members */

  static pUnit Special32[1] = {Units + 369}; /* members */

  static pUnit Special33[1] = {Units + 370}; /* members */

  static pUnit Special34[1] = {Units + 371}; /* members */

  static pUnit Special35[1] = {Units + 372}; /* members */

  static pUnit Special36[1] = {Units + 373}; /* members */

  static pUnit Special37[1] = {Units + 374}; /* members */

  static pUnit Special38[1] = {Units + 375}; /* members */

  static pUnit Special39[1] = {Units + 376}; /* members */

  static pUnit Special40[1] = {Units + 377}; /* members */

  static pUnit Special41[1] = {Units + 378}; /* members */

  static pUnit Special42[1] = {Units + 379}; /* members */

  static pUnit Special43[1] = {Units + 380}; /* members */

  static pUnit Special44[1] = {Units + 381}; /* members */

  static pUnit Special45[1] = {Units + 382}; /* members */

  static pUnit Special46[1] = {Units + 383}; /* members */

  static pUnit Special47[1] = {Units + 384}; /* members */

  static pUnit Special48[1] = {Units + 385}; /* members */

  static pUnit Special49[1] = {Units + 386}; /* members */

  static pUnit Special50[1] = {Units + 387}; /* members */

  static pUnit Special51[1] = {Units + 388}; /* members */

  static pUnit Special52[1] = {Units + 389}; /* members */

  static pUnit Special53[1] = {Units + 390}; /* members */

  static pUnit Special54[1] = {Units + 391}; /* members */

  static pUnit Special55[1] = {Units + 392}; /* members */

  static pUnit Special56[1] = {Units + 393}; /* members */

  static pUnit Special57[1] = {Units + 394}; /* members */

  static pUnit Special58[1] = {Units + 395}; /* members */

  static pUnit Special59[1] = {Units + 396}; /* members */

  static pUnit Special60[1] = {Units + 397}; /* members */

  static int Output[9] = {329, 330, 331, 332, 333, 334, 335, 336, 337};

  for(member = 0; member < 268; member++) {
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
