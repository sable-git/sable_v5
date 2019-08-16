/*********************************************************
  ELMAN268-30-30-9ENTROP4.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:06:02 2004
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
0.563160, -1.045680, -0.126880, -0.466480, 0.015540, -0.989870, 0.410040, 0.328860, 0.437330, -1.085190,
0.106560, 1.156180, 0.370510, -0.582800, 0.028080, 1.100760, -0.015440, 0.381800, -0.817920, -0.484690,
-0.730040, 0.403800, -1.710660, 1.144330, 0.907510, 0.029400, 1.299130, -0.896950, -0.918160, 0.768320,
0.274460, 0.385710, -2.038790, 0.137750, 1.752060, -1.549850, -1.126900, 0.844030, 0.599080, 0.251510,
1.822580, 0.150370, 0.372580, -0.094610, -0.181730, -0.216360, 0.288790, -0.285130, 0.058820, -0.326220,
-1.442020, -1.648010, -0.577540, 0.094820, 0.192270, -0.269760, -1.343740, -0.216720, -1.073500, -0.103790,
0.786560, -0.201170, -2.273510, 3.524930, 0.042170, 0.473660, 1.711750, 1.355220, -1.427440, 0.730740,
0.728500, 0.431220, 0.370670, 1.623230, -0.630970, -1.268270, 1.845490, 1.437740, -1.807420, -1.331020,
-1.049440, -0.353200, 0.838620, 0.344020, -0.211050, 0.707630, -0.604300, -0.482270, -0.069010, 0.876850,
2.744050, -0.292060, 0.427020, 2.130300, 0.403870, -0.013870, 0.759940, -0.183670, -0.819520, -0.529780,
-0.077970, -1.795880, -0.452860, -0.065900, 0.895110, 4.001390, -1.825250, 0.192950, -0.944910, 0.392860,
0.418720, 0.064000, 0.416950, -0.756340, -0.176790, -1.129620, 0.012070, 0.273120, -0.779750, -1.189340,
-0.740710, 0.658650, -0.129420, 1.590010, 1.518500, 0.131570, -0.231240, 0.528010, 3.439570, -0.966610,
-0.525650, 0.747090, 0.289560, -1.319400, -1.493190, 3.605400, -2.210770, -1.069480, -6.209750, -1.930730,
1.612380, 2.788390, 1.637260, -0.067910, -0.091550, -2.583390, -1.056990, 2.920880, 2.051520, -0.902220,
2.348080, -5.266720, -0.251010, 1.331340, 1.267120, -0.201300, -1.964780, 1.111640, -1.028650, -1.637990,
1.221260, -1.566630, -4.200870, 1.612440, 4.007130, 1.712290, 1.501740, 1.898190, -0.215130, 1.497230,
0.954860, 2.500310, 1.361590, 1.176010, -5.996870, -3.203480, -0.104500, 1.255130, -0.607170, -0.465990,
1.433560, -1.979740, 0.084480, 5.825070, -0.362980, -7.938420, 0.133070, 1.324190, -0.238110, -1.595750,
0.684710, -0.613860, -3.238230, 0.158100, 1.281250, -0.136900, -0.281880, -5.237880, -0.329140, 0.521710,
2.880720, -0.193190, -2.018290, 1.471710, -0.652980, 1.636920, 0.787870, -0.229520, -6.058240, 0.385080,
1.553010, -0.448530, 0.049240, 0.762400, -0.626230, -2.083120, -2.120630, 2.213540, 1.711710, 0.470540,
-0.599780, 0.755920, 0.303640, 4.381980, -1.556180, 3.902050, 0.164400, -1.191570, -0.827530, -0.595850,
0.277920, -2.402600, -1.317120, 0.822310, -0.020220, -1.454460, 0.412340, -0.274360, -1.323350, -0.132980,
-0.213030, 1.161280, 0.000650, 0.993490, -1.675110, 1.479690, -1.119340, 1.531670, 0.603160, 0.648290,
1.254270, 0.819000, 2.003610, -0.924760, 0.652730, 0.433350, 1.081970, 0.109140, 0.817030, -0.885160,
0.681680, 0.418320, 1.320350, -2.640600, 0.283770, -1.395320, 1.720770, 1.136850, 2.179120, -0.665820,
0.543780, -1.341800, 1.134200, 0.776650, 1.250990, 0.087010, 0.195550, 0.773330, 0.298920, 0.441000,
-1.569390, -0.033530, 0.095520, 1.275970, -0.060700, 0.763530, 1.225620, 0.068070, 0.682530, 0.837340,
-0.033800, 0.173230, 1.355120, 1.282330, -0.380210, 0.082840, 0.674890, 0.535840,
0.115900, 0.956730, -0.203780, -2.731560, 1.446610, 0.832830, -0.599110, 0.653210, 0.457010, -0.566280,
-1.189540, -0.293040, 0.859360, -1.001400, 0.513060, -0.758850, -0.094030, -0.582060, -0.674020, 0.143870,
0.690920, -0.144510, 1.053170, -0.614610, -1.166630, 1.361870, -3.170960, -0.719660, 0.240900, 0.061490,
-0.224280, 0.485610, 1.711510, 2.488500, -0.296130, -0.361000, 1.446530, -2.147830, 0.540180, -1.271360,
-0.400060, 0.297170, -0.309700, 0.996330, -0.692040, -0.574290, -0.348520, 0.131680, -3.013550, 0.922130,
-0.893080, 0.575580, -0.476800, -0.153130, 0.404460, 1.224450, -0.382450, 0.134840, -0.539510, -2.400230,
-1.112160, 0.592100, 0.345460, -3.270180, -1.720000, 1.364780, -0.024330, -0.511370, -1.655020, -0.066260,
1.771680, -0.448670, -0.077410, 0.506360, 0.710390, 0.429800, -1.090100, -1.027040, 0.181530, 0.435310,
-0.395790, -0.172300, -1.143140, 0.888110, -0.350990, -0.766960, -0.330850, 1.524760, 2.614500, -0.361820,
-0.219050, -0.101860, 1.439810, 1.059690, -1.309020, 0.529380, -0.926470, 3.920120, -0.042800, -1.026680,
1.329310, 2.087370, -0.657540, -1.513760, -0.784010, -1.465810, 0.745160, 0.110790, -0.653790, 0.572680,
-0.098340, -0.508070, 1.106880, -1.133460, -1.094020, 0.722430, 2.234580, 0.727420, 2.456920, -0.199730,
1.487660, 0.299160, -3.619730, 2.712470, 0.848630, -0.283700, -0.855150, -1.618740, -0.305280, 0.373180,
0.239760, -0.379090, 0.604060, 0.076780, -1.462260, 1.231350, -0.447230, -0.342720, 0.282210, 1.755940,
-0.344620, 2.164900, -0.932870, -0.816710, 1.490490, -1.973040, 0.436420, 0.215390, -1.506190, 0.722160,
2.144940, -0.207730, 0.404830, -0.088570, -0.462330, -0.327130, 2.330440, 1.898870, 0.426170, 0.517470,
-0.567460, 1.900140, 0.228060, -0.275420, 3.582350, -0.521740, 0.850530, 0.075300, -1.581310, 0.090750,
0.590930, -0.285740, -0.778170, 0.763540, -0.398490, -0.805300, -1.288920, -0.326950, 0.025720, 1.143160,
0.175320, -0.761720, -1.462040, 2.135210, 1.260370, -1.319900, 1.887130, 2.947840, 0.445180, 0.183720,
-2.555800, -0.300500, 0.660760, -0.067890, -1.109450, 0.764100, -0.258220, -0.046300, 1.717360, -2.512120,
-0.550560, 1.450100, 0.603230, 0.247150, 2.407430, -3.296330, -1.916190, 1.231170, -1.096010, 2.264880,
4.084040, 0.339620, -0.508000, 1.105210, -0.746150, -0.244950, -0.971390, -1.612520, -1.002880, 0.858090,
-0.602070, 1.740080, 1.067090, 2.487510, 1.302570, 2.743880, -1.691360, 1.064500, 0.612770, 1.100500,
1.685220, -1.393280, 1.442590, 4.838020, -0.466020, -1.914950, 0.841010, -0.736900, -0.998030, 0.996330,
-2.868410, 0.739320, -0.874620, -1.297250, -0.712110, 0.737120, 1.179480, -0.104660, 3.932600, 3.763340,
0.340420, 0.003870, -1.036680, 0.166830, 0.158630, -0.466780, -2.004790, -0.657390, -0.181760, 1.025270,
0.305930, 0.926490, -0.362570, -1.104090, 0.007680, -1.080970, -0.070060, 0.765440, -0.217850, -0.378320,
-1.271920, 0.423470, 0.007470, -8.834390, -0.473750, -3.078600, 2.398110, -1.040580, -0.754510, 0.333360,
1.597940, -0.542010, -0.042110, -3.895140, -1.073650, -0.256330, -1.196480, -0.109380, -2.215870, 0.485920,
-0.731100, -1.930470, -1.096410, -0.851950, -0.645340, -0.920150, -0.685360, -0.892800,
-1.833320, 2.923220, -0.694480, 1.527560, -1.364370, -0.460240, 0.904560, 1.322770, -0.973660, -0.276930,
0.211080, 0.034180, 0.577970, -1.323570, -0.691770, -1.548710, 0.811370, -4.339790, -1.378500, 1.318550,
-0.537460, -0.726110, 0.259390, -1.247180, 0.076620, 1.624590, -2.079910, -0.913190, -0.315610, 0.627870,
-0.053990, -0.567780, -1.459010, 0.960540, -0.712580, 2.043890, 0.438410, -1.068350, 2.165530, -1.014550,
-1.133860, 1.170440, 1.926270, -0.768620, -0.598320, 0.179400, -1.531320, -0.184090, -1.586560, 1.704330,
-0.109120, 2.162020, -0.770700, -0.583580, -2.378230, 0.285920, 1.512530, 0.789110, -1.138970, -1.629070,
-0.182870, -0.425420, -1.647280, -1.941210, 1.502920, -0.354690, -1.831440, -3.312350, -0.388190, -0.438740,
-0.255830, 0.490310, -0.839590, -0.774210, 0.899760, 0.522830, -0.086660, 0.241480, 0.567390, -0.304770,
-1.154580, 0.535270, -0.083020, 0.413640, -0.689340, 0.445860, 0.308470, 2.110810, 1.689950, -1.129470,
-1.641830, 0.366890, 1.431680, 1.583050, 1.091410, 0.555710, -0.466050, -0.023240, -0.928790, 0.602410,
1.408060, -0.906410, -1.800130, -0.557540, 1.331470, 0.159590, -0.496720, -0.279180, -0.288000, 0.194230,
2.934870, 0.473610, -0.802360, 0.145910, 1.061580, 0.712550, 2.236160, 1.638450, -1.267770, 0.905240,
-0.130110, 0.990870, 1.470380, -0.521540, 0.561620, -1.833150, -0.378830, 2.761340, -0.597960, -1.505030,
-0.280520, -1.405010, 0.385050, 2.928870, -0.234500, 0.795370, -0.499650, -0.362760, -0.017960, 2.482020,
2.214520, -0.447310, -1.002090, 0.501730, -0.297000, -0.615690, 0.038810, -0.073830, -3.751440, -0.869050,
-1.878550, 0.093600, -0.907470, -0.718160, -0.732700, 1.062810, 4.316620, 0.021870, 0.253110, -1.452380,
1.256740, 1.661400, 0.955410, -0.382970, -0.267010, 0.256250, 0.177570, 0.704310, 1.194450, 2.389220,
0.420670, -1.485780, -0.270900, 0.240070, -0.604920, -0.558680, -1.620600, -0.023930, 0.704350, 4.089650,
-0.098800, 0.386210, -1.018180, -0.204330, -0.421280, 0.254740, -0.946210, -0.104610, -0.179980, 0.143830,
-0.870620, -0.870760, -3.503740, -0.597300, -5.962090, 0.578650, -0.360100, 0.195540, 0.055010, 0.334460,
-0.261830, -2.380280, 0.477810, -0.632940, 0.091670, -0.885730, -1.449270, 1.003130, -0.590170, -0.223860,
0.774520, -0.851430, 0.145820, -1.497120, -0.752270, -1.195140, -1.543920, -0.019350, 0.114070, -0.032010,
1.315910, -0.782470, -0.612250, 0.232730, -1.448910, 1.358680, 2.042080, 0.292380, 1.005290, 0.444620,
-0.834100, -1.164560, 1.038420, 3.626760, 0.998510, -1.376670, 0.346600, 0.041920, 0.225360, -0.572150,
-1.668360, 0.972010, 0.357640, -2.030680, -0.510130, -0.070900, 0.438930, -0.556230, -0.487970, 0.792990,
1.196410, -0.480720, 1.604250, 0.632920, -0.991590, -0.193440, 1.324430, -0.209900, 0.079070, -0.076500,
0.979670, -0.584560, -1.019560, 0.242600, 0.458100, 0.909270, -0.149420, -0.310750, 1.418590, 2.667470,
0.380830, 1.687760, -0.584190, -1.468980, 1.318010, 1.038970, 12.814430, 0.770640, 0.561130, 2.209070,
0.795300, 0.246460, -0.561780, 2.130530, 0.392360, 1.567980, 0.996030, -0.226260, 1.248880, 0.477290,
0.661580, 0.065480, 1.472510, -0.266820, 1.627980, 1.788550, 0.405490, 1.242450,
-0.461770, -0.470010, -0.087410, 0.439510, 0.857920, -0.546180, -1.018680, -1.668130, -0.066830, 0.071020,
-3.921460, -0.603670, -1.689220, -2.750920, 0.886390, -0.286410, -1.215390, -0.699360, 1.262690, -0.095760,
0.451690, 0.345170, 0.086790, 0.445040, 1.168520, 2.240630, 2.828510, 0.884020, -0.267460, 0.088440,
1.125510, -1.080070, 0.215530, -0.023930, -0.133390, 0.442510, 0.511060, 0.608260, -0.266740, -0.346270,
-0.405140, -0.655160, 0.261700, -0.282400, -2.747940, -0.412150, 1.591420, 0.196600, 1.032130, 0.778570,
0.471820, 0.023130, 0.404440, -0.143070, 0.034830, 0.509450, -2.508990, -0.382200, -0.195030, -0.831170,
0.373210, 0.146850, -1.306730, -0.220770, 1.529490, -0.549100, -0.032090, -0.693610, -0.141740, 1.287390,
1.921690, -0.700860, 2.300870, -0.744110, -0.075840, 0.800890, -0.304170, 0.034720, -1.670300, -0.010480,
0.120060, -1.004400, -1.933200, -1.369350, 0.011680, -0.328610, -1.514360, 0.520010, -1.040250, -0.490360,
-0.631370, -2.501870, 0.193820, 0.925770, 1.472490, 2.464150, 0.849900, 0.819100, 1.281760, -3.994650,
0.163150, 0.975230, -4.918160, -0.424300, -0.845390, -1.143350, -0.302110, -0.652790, -1.131050, -0.506970,
2.069370, 0.617440, 0.430490, 0.828510, 1.457320, 4.668790, 2.658070, 0.244740, -0.491220, 0.413940,
-0.971480, -0.820540, 0.248690, 6.839130, 0.610540, -5.596630, -0.604980, -1.367300, 2.271000, 1.958820,
1.368860, -2.459550, -0.235780, 2.657620, 0.194020, 3.219240, 0.243630, 0.334750, 1.368850, 3.380840,
0.095070, 0.623050, 1.326380, -0.504570, -0.345820, -1.177310, 3.085780, -2.831480, -10.383910, 0.707650,
-1.144670, 2.952270, 1.186450, -1.062850, -0.753520, 0.624490, 1.124310, 2.093780, 1.229940, -0.566160,
1.408930, 2.075910, 6.473960, -0.890020, 0.763450, -0.633290, -0.757520, 1.053690, -2.591660, 0.438900,
-2.302040, -6.053990, -1.123350, 0.675940, 1.327020, -1.260220, -1.326300, 0.194080, -0.487520, 0.108880,
1.878740, -0.605410, 0.450040, -1.457950, -0.041940, 0.552670, 1.470680, -0.024500, 0.227120, -1.985780,
-2.002950, -1.293280, 2.465320, 1.289420, -2.616560, -0.963820, -0.348880, -0.224710, -1.034100, 0.312770,
-1.465010, 2.316980, -0.749190, 0.441670, 0.624180, -0.302970, -1.821440, -0.256170, 1.621010, 0.134900,
0.110510, 2.213490, 0.590310, 0.195860, -0.527940, 0.879890, 2.969400, -2.297350, 0.072480, 0.965090,
-1.144710, 0.739150, -1.660980, -0.403630, 2.344310, -0.018000, -0.179720, 1.646960, -2.223850, -1.139490,
0.878460, 0.016870, 0.397980, 0.453320, 0.082940, 0.394520, 2.003810, -1.925230, 0.045480, 1.654410,
-0.487850, 0.177860, -0.044630, -0.823550, 1.261060, -0.631730, -0.231610, -1.165020, 2.074510, 0.662970,
-0.454350, -2.403250, -0.320880, -2.812170, -1.133170, -1.165180, 0.338640, -0.133010, -0.973720, -2.057330,
-1.065660, -1.243860, -0.300520, 1.045030, -3.814680, 0.247870, 1.164680, 1.070720, 0.405830, -0.891870,
-0.683150, 0.946240, -0.214710, -2.178340, -1.402980, 0.255850, 1.095010, 0.448240, -0.500110, 0.335560,
-1.329490, -0.022540, -0.223790, 0.934890, 0.232850, 0.656250, -0.547200, 0.881490, 0.154140, -0.420010,
0.727360, -0.076220, -1.054540, 0.950540, 0.525690, 0.974760, 0.337670, 2.743150,
-0.298410, 0.285930, -0.724670, 0.261310, 1.005470, -0.631310, 0.487510, -0.591230, 0.715200, 0.033000,
0.035490, 0.272300, -0.600760, 1.535310, 0.120560, -0.272620, 2.366920, 1.077710, 1.842130, 0.637310,
0.322510, 0.794460, -0.756030, -0.354070, -0.533950, 0.104460, -2.450550, 1.727390, -0.895570, -0.074810,
-0.252650, 0.886720, 0.039540, 0.827200, 0.169610, -0.499330, 0.485430, 1.860020, 0.395330, 2.509840,
2.018510, 0.419900, -1.789440, 0.717310, 0.541800, -0.630500, -0.977100, 1.283680, 0.173120, 0.888910,
-1.570950, -0.295700, -0.976180, -1.275430, -0.001320, -1.139600, 0.563460, 0.923550, -0.610570, -0.973770,
-0.567570, 0.227580, -0.574630, 0.085180, 0.384160, 0.230170, 0.367480, 0.574220, -1.048760, -0.636430,
0.707210, 1.470180, 1.736060, -0.203900, 0.973950, 0.544350, -1.435810, -1.806680, 1.504180, -0.698940,
-1.146590, 0.108660, -0.988060, -1.054430, 0.821200, 0.531480, 0.763520, -0.197630, 1.525730, -0.984910,
0.681330, 1.510260, -0.544100, -1.360890, 0.257040, 1.820640, 2.045070, -0.239650, 0.180700, 1.515320,
-0.560080, 0.251910, -0.197840, -0.121460, 0.655450, 0.170630, 0.361930, 0.361590, -1.135350, -0.769890,
-0.451340, -0.229260, 0.662250, -0.109540, -2.826670, 1.280140, 2.152210, 0.677680, -2.639630, 0.432390,
0.722130, -0.129270, -0.040680, -1.064290, -0.489840, 0.079780, 0.387090, -0.738150, 1.445760, -1.120490,
-0.136090, -0.190660, 1.598810, -2.441310, -1.218940, 1.851670, 2.206470, -0.807140, 4.006780, 5.748720,
-1.871180, -4.422480, 0.342800, 2.407400, 0.081810, -1.227180, 2.039820, -2.853340, -2.214130, -0.553270,
-1.245970, 5.057440, 1.984570, -0.720550, -1.917180, -1.787600, -0.644990, 0.000730, 0.433980, 0.382250,
-5.299350, 2.516430, 9.654620, -1.847550, -4.464070, -0.418330, -0.014310, 0.004620, 0.879520, 0.518980,
-2.671070, -1.607140, -0.729200, 0.077530, 6.920090, -0.601750, 1.398950, -1.389060, -0.395950, -0.934390,
0.931620, 0.218710, -1.922790, -3.292860, 0.276410, 4.720460, -1.736250, -1.946700, -0.939820, 0.173820,
-0.310440, -0.843100, 0.444920, -0.769800, 0.043120, -1.131580, 0.490700, 2.395710, -0.184230, -0.410640,
-2.118550, -0.609290, -0.424310, -1.044270, 0.324730, -0.443410, -1.445100, 0.491260, 5.680730, 1.175720,
-0.875190, -1.187630, 0.932690, -1.267170, 1.361470, 0.248450, 0.310620, -1.154400, -1.640830, 0.368590,
1.363680, -1.049630, 0.340390, -0.579680, 0.851330, 1.148680, 0.039140, 0.540750, -0.228380, -3.012450,
-0.003940, 0.346940, -1.383030, -1.292170, 0.094330, 0.814230, -1.797090, 0.856140, -0.170620, 2.467700,
2.673440, -0.310090, 2.242750, -0.217030, -2.676510, 1.412020, -0.607670, -0.762770, -0.263160, 0.647350,
-0.852690, -1.001090, 0.780800, -1.188900, 1.386180, -0.402000, 1.290590, 0.119780, 0.536770, 0.419500,
0.672630, -2.530960, 0.536070, 0.528940, 3.365970, 0.713540, -0.905100, 1.484470, -1.118070, 0.583690,
-0.455770, 0.607420, 2.617220, -1.336080, -0.252710, -0.024160, 0.768060, 1.284620, -0.532770, 0.363640,
-2.864280, -0.402420, 0.308400, 0.613330, 0.449210, 1.036990, 0.791820, 0.915440, 0.156580, -0.339680,
1.680780, -1.950900, -0.190150, -0.288440, 0.983160, -0.200880, 0.305540, -0.610540,
0.178530, -0.873690, -0.327190, -1.609280, 0.158360, -0.481810, 0.987140, 0.254650, 0.599790, -0.111940,
-0.477160, -0.847890, -0.310490, -0.449860, -0.135640, 0.696930, 0.058240, -2.832050, -0.604720, 1.564370,
0.768160, -0.414150, 1.785040, -0.607400, 1.250180, 0.554050, -1.030390, 0.773920, 1.272190, -0.323300,
0.056480, -1.265150, -0.203820, -2.985190, -0.377540, 0.538310, 0.476900, -1.082530, 0.925520, -1.071770,
-0.667810, 1.644730, -0.975610, 0.684630, 0.850000, -0.861460, 0.270780, 0.814230, 0.740080, 0.031940,
-0.510890, -0.376340, 0.720090, -0.157160, 0.597110, 0.017650, 0.548970, 0.870710, 0.825010, -1.066330,
0.079950, -0.193040, 0.148950, -0.054080, -0.683420, 1.132080, -1.408270, 0.228220, -0.408100, -0.859220,
-0.609930, -0.290840, 0.025890, 0.029480, 0.643570, 0.483010, -0.987280, -0.666280, 0.004940, -0.593460,
1.769470, -0.900610, -1.607310, 0.292030, -0.729780, -0.085290, 0.892310, -0.528390, 0.837030, -0.301750,
0.621170, 0.462860, 0.103330, -0.254060, -0.518040, 1.737260, -1.540470, 0.596010, 0.397410, -1.913170,
-1.028430, 0.865370, 0.245960, 0.146050, 0.071530, 0.561480, 0.857700, 0.430070, 0.429050, -0.190060,
0.899730, 0.672260, 0.930640, 0.128390, 0.492620, 0.250740, 0.089330, -0.430050, -1.121480, -0.242390,
0.039950, -0.584650, -0.659050, -1.059540, 2.872060, 0.590570, 0.919600, -1.244830, -0.653040, 0.059440,
0.805320, 0.024890, -0.281250, 0.438270, -0.231450, -0.462740, -0.255010, -1.069180, -1.261880, 1.339640,
0.058900, 0.064330, 1.105120, -1.518580, 0.019030, -0.760140, -0.777900, -2.506230, 1.416090, -0.353240,
-0.633500, 0.773320, 0.182690, -0.567240, -0.696480, 0.287870, 0.023800, 0.407470, 0.469960, 0.521210,
0.913090, 1.084610, 3.273440, 0.062510, -1.794830, 1.835250, 1.821260, 0.148120, 1.222990, 1.147070,
0.102370, 1.087960, -2.220280, 0.352590, 0.486920, 0.084100, 0.006000, -4.495810, 0.357670, -1.781380,
0.794910, -0.009280, -3.546450, -0.864860, -1.404050, 3.098190, -1.655390, 1.607560, -1.004910, -1.098890,
-1.084370, -0.545790, 1.462430, -1.370480, -0.069210, -0.753750, 0.320910, 0.104990, 0.084880, 0.277360,
0.023150, -1.634250, 0.958260, -2.634450, 0.091300, 0.477900, 0.027060, 1.631790, 3.271960, 1.746690,
-1.653040, 1.599340, 2.039950, -0.334000, 2.546200, 1.700350, 1.511300, 0.797270, -0.635650, 0.183010,
0.562000, 1.009410, -0.274900, -0.957610, 1.581380, -0.606650, 0.778760, 1.487540, 0.520150, -1.681910,
-0.970020, -1.116490, 1.042290, -0.087520, 0.945080, -0.648200, 1.810800, -0.945410, 1.365490, -2.199470,
-0.915530, -1.205060, -0.146140, 1.356230, -1.228130, -0.752680, -0.246830, -2.410310, -0.308670, -1.040970,
0.995620, -0.356190, -0.100560, -0.794420, 1.016460, 0.423470, -0.666150, -1.048900, 0.286720, 0.233190,
0.247440, -1.413950, 0.626300, -0.753850, -0.154570, -0.274730, 1.108140, -2.966750, -0.664060, -2.833100,
-1.412030, -4.592580, -1.367630, 3.388350, 0.138390, -0.890480, -2.355090, -0.747750, -1.311630, -1.575330,
-1.635900, 0.456020, -0.107640, -1.406530, -0.116410, -0.924770, -2.830420, -0.829370, -0.119460, -1.638790,
-1.836860, 0.168230, -0.566000, -0.637660, -1.725990, 0.020900, -1.329250, -0.955840,
0.116580, 0.453710, 0.552780, -0.878190, 0.948180, 0.668220, 0.075170, 0.757230, 0.213680, -1.052300,
0.021240, 0.518450, 1.379650, -0.872140, -0.740330, 0.692610, 1.112490, 0.085900, 0.722190, 1.379740,
-0.653050, -0.122750, -1.185980, -1.084890, -2.771640, 0.155400, -1.613190, -0.510700, -0.675240, 0.110600,
-0.999430, 0.681410, 1.300730, -1.052690, -0.066020, -1.195900, 2.328420, 0.972080, 1.121450, -1.963330,
-0.000010, 0.246810, 1.288090, 0.131080, -0.267590, 1.105510, -1.836010, 2.163270, 0.206360, 1.608350,
-0.428230, -0.413240, 0.484250, -2.333970, 0.397170, 0.839720, -0.289270, 0.043290, 1.739440, -1.352270,
0.008620, 1.500540, -1.526710, 1.311710, 0.878450, 0.131950, 0.045580, 2.094170, -0.436040, 0.295530,
-2.221270, 0.781600, 2.235850, 0.659040, 1.754300, -1.107770, -0.708240, 1.820920, 3.486630, 0.196940,
-0.241250, 1.885490, -2.243240, -0.342580, -1.092830, -2.193600, 1.514990, 1.720390, -0.833220, -1.025160,
-0.465850, 0.222230, -4.108020, -1.558920, 1.200350, 7.421150, -0.111750, -3.517000, -0.346940, -0.620680,
-3.233690, 0.950000, 0.124450, 0.467360, 0.008710, -3.698820, 1.242910, -0.435970, 1.388630, 0.137380,
1.059820, 2.286430, -0.103520, -0.783010, 1.953870, 2.192880, -4.128070, 0.376440, 1.587100, 1.119510,
2.640170, 0.782340, -1.551030, -0.490690, 2.947220, 0.733890, 1.531520, -1.255160, -2.077730, -0.280530,
-3.155050, 0.925520, 1.155250, 0.117300, 0.023150, -0.907600, -0.629510, 0.093030, -1.712760, -2.057690,
-0.592910, -0.958020, 1.227840, -1.625070, -0.220380, -0.254230, -3.678780, -0.857050, 1.934510, 1.243470,
-0.118200, -0.124770, 0.426100, -0.938530, 2.914630, -1.146200, 1.854890, 1.909870, -0.433200, 0.166380,
-0.208510, 1.210320, -5.477070, 1.375640, 3.418940, 0.413400, 0.805320, 1.414210, -2.417970, -0.225900,
-0.106050, 1.473560, 1.008870, 0.850580, -1.440680, -0.913570, 0.951840, 1.109180, -0.123600, 3.204460,
2.106760, -0.698390, 0.283150, -0.526850, 0.121910, 0.024840, -0.191840, -1.685150, 0.277940, -0.574710,
-0.310180, -1.020270, 3.781960, 0.903390, -3.057040, 0.172590, 0.721460, -0.257190, -0.377260, -0.645330,
0.287710, -0.153010, 2.044150, -0.345980, 0.507860, 0.817970, 1.025340, 0.458060, 0.235240, -0.687380,
0.659070, 0.111850, 0.631010, -0.253450, 0.030570, 0.294330, -1.160270, -1.751870, 0.422110, 1.237970,
0.284030, -1.276180, 0.970390, -0.311520, -0.325780, 0.400440, -0.926860, 1.491580, 2.152420, 1.180430,
1.632270, -0.798470, 1.282200, 0.340750, 1.647530, 0.002240, 1.258490, -2.403970, -0.304470, -0.194260,
-0.065320, -0.464440, 0.135390, 0.756360, -0.992260, 1.450820, 0.206240, 0.807220, 1.343980, 1.430310,
0.734050, -0.490510, -0.792720, -1.473250, 0.213840, -0.920860, -0.259020, 1.879530, 1.069360, -1.285780,
-0.690290, -0.152140, 0.080760, 0.138440, -0.649540, 0.144700, 0.446840, 0.248850, 0.871550, 1.165150,
0.104270, 0.390630, 0.462920, -0.177270, -0.242090, 0.648550, 2.387780, 0.909120, -0.878860, 0.990580,
7.946350, 2.074090, -1.002110, -0.342780, 0.006490, 2.119720, -1.163060, -0.976800, -0.222760, 0.323520,
-0.855870, 0.599320, 1.644560, 5.367780, 0.597660, 0.264520, 0.470930, -0.383980,
-0.480590, -0.972870, 0.997520, -0.320160, 0.959160, 0.488400, -0.647650, 0.521090, -1.095630, 0.764800,
-0.019440, -0.176320, -0.046000, -0.360310, -1.668090, 0.622460, -0.325750, 0.686150, -0.709100, -0.359820,
-0.550430, -0.309590, 0.593000, -0.096030, -0.838510, 0.437080, 0.949100, 0.762760, -0.154730, 0.371280,
-1.439410, -1.011090, 1.517960, -0.766730, -0.208500, -1.021130, -1.641340, -0.050000, -2.204710, 0.290810,
-0.784240, 0.263150, 0.502340, -0.212650, 0.769230, 1.312870, -1.269010, -0.980650, -0.654260, 0.355460,
0.577540, 0.151170, -0.441230, -0.281970, 1.056320, 1.021260, 0.610260, -0.508180, -0.457550, -0.438140,
-0.058660, 0.020680, -1.274880, -1.355990, 0.244500, 0.368330, -0.781600, -0.335200, 0.966580, -0.214280,
-0.471950, 0.504300, 2.066100, 1.038240, 1.025900, -0.672170, 1.173730, 2.019700, 0.232250, -0.274190,
0.254360, 1.062460, -1.404070, -0.425210, -1.550670, -0.716140, -0.139830, 2.025290, 0.910670, -1.130190,
0.560570, 0.532500, 0.481360, 0.344460, 1.032540, 1.167990, 1.971580, 1.038490, 0.951290, -0.700600,
-0.247500, 0.671650, 0.145710, 0.838350, -0.666380, -1.933220, -1.291710, -0.707810, 0.152630, 0.429380,
3.070820, -0.163650, -0.014020, -1.201650, 2.387900, 3.955610, -0.455860, 1.285830, 0.963220, 1.732560,
-3.120080, 0.099310, 0.052160, 2.430730, 1.296230, -0.400210, -0.698800, -2.807160, 2.088190, 1.374320,
-1.292450, -1.258150, -0.523780, 3.100890, 1.466700, 0.321910, 5.106890, 0.394280, 5.243190, 0.140150,
-0.456480, -1.624400, -0.123070, -2.095360, 1.974050, 2.314260, 1.072970, -2.326350, -2.184980, -2.291840,
-0.559070, 1.755810, 0.324580, -1.590830, -3.426030, 0.181710, 0.733850, 1.399570, 0.617590, 0.240340,
-3.144190, 1.244150, 6.104360, -0.669730, -7.832030, 0.600960, 1.268300, 0.370450, 0.830330, 1.468820,
-2.473040, -0.682930, -0.084830, 1.876930, 3.653570, 0.691850, -0.577670, -0.814050, 1.133670, -2.032190,
0.471630, -0.025280, 0.254030, -0.413350, 1.258220, 7.234300, -1.422770, -2.890310, -1.632500, 1.749250,
2.476460, -1.225520, -0.093010, -0.053350, -1.083370, -0.495400, -0.509910, 2.394290, 1.205850, -0.355900,
-0.586780, 1.237290, 0.234640, 0.196510, 2.093120, 0.762190, 0.046960, -0.996630, 2.849470, -0.610090,
-2.437110, -2.746360, 1.430750, -0.200730, 2.583750, 0.624080, 0.040790, -0.304130, -0.896390, 0.369920,
1.324370, 0.551090, 1.124280, 0.278170, -1.496850, 0.335970, -1.992020, -0.655850, -0.618560, -1.063190,
-0.430610, 1.601890, 0.822690, -1.430190, -0.764210, 0.844550, -0.219570, -0.064790, -0.532480, -1.315470,
1.674380, -2.764630, 0.815740, -0.208990, 0.069410, 0.419700, -0.890630, -0.821260, -1.627340, 1.313930,
0.365970, -0.370390, 1.110120, 0.092900, 0.063810, 0.180790, -0.729850, 0.132130, 1.842970, -0.750180,
0.945420, -0.321050, -0.010730, -0.200810, 2.148730, 2.298380, -1.747270, 0.566530, -0.223560, -0.684590,
0.914110, 1.136780, -0.740780, -0.241990, -0.618210, 0.378420, -1.103020, -1.146730, 2.243110, -0.854860,
-2.285550, -0.641570, -0.019170, -0.896430, -0.224530, 0.351720, -0.528550, 0.122340, 1.597260, 0.258160,
0.236080, -0.250760, 0.774070, -2.194770, -0.240950, 0.659790, -0.669670, 0.457010,
-0.050740, -0.934610, 0.030100, 1.285040, -0.657830, -0.182110, 0.587150, -0.802010, 0.289740, -1.239880,
0.013950, -0.115190, -0.128900, -1.581870, -0.515210, -0.701620, -0.335990, -0.885350, -0.484800, -0.371280,
0.475580, 0.233120, -0.460570, -0.687240, 1.126870, -0.081680, -0.497430, -0.249070, 0.093720, 0.891530,
0.396510, 0.320110, -0.966410, -1.630470, 0.567640, 0.291290, 0.092270, 0.229740, 0.718140, 0.410410,
0.447840, 0.143560, 0.774640, -1.062990, -0.555890, -0.439530, 0.018290, 0.732660, 0.199150, -0.511860,
0.320580, 1.523840, 0.019670, -1.239330, 1.055020, 0.719420, 0.102150, -1.120940, -0.056770, -0.749410,
-0.189080, 0.217560, 0.123780, 0.040970, -1.697230, 1.240390, 0.232990, -0.017080, -0.167350, 0.344930,
0.221460, -1.444480, 0.847620, -0.603430, -0.620340, 0.162090, 0.932270, 0.131780, 0.923590, 0.222190,
-0.700950, -0.689370, -0.145800, -0.821930, -0.549560, 0.190520, -1.052080, -0.895670, 0.413940, -0.566400,
-0.238270, 0.777120, 0.635410, 0.829980, -0.832730, -0.160210, 0.277090, -0.740610, 0.825030, 0.017780,
-0.953010, -0.758120, -0.333830, 0.809740, -0.587660, -0.450610, 0.191070, -0.526260, 1.047570, -2.423130,
0.300350, -1.012650, -2.742020, -0.490460, -0.278330, -0.560860, 3.335130, -0.837270, -0.585030, 1.504590,
0.848200, -0.173790, -1.167160, -0.803760, 0.357040, -2.537970, -0.894220, 0.255710, 0.561010, 0.623690,
-0.138950, -0.938650, -0.996470, 1.066200, -0.189830, 0.927790, 0.622990, 0.215980, 1.149900, 2.276430,
-0.924570, 2.080880, 1.440510, 1.092970, -0.572610, -2.168320, 3.710950, 2.321060, -0.439290, -0.633200,
1.310050, 0.563000, -0.752960, -0.656300, -1.356400, 1.349190, -0.345890, -0.288270, 4.507070, -0.052220,
-0.768560, -0.614130, 0.505600, 0.289020, 1.433080, -1.176480, 0.514220, -0.245270, 0.064240, 2.493630,
-0.042390, -0.989720, 0.221970, 0.229470, -0.406030, 1.392510, -2.152090, -0.476660, 0.386290, 0.945850,
1.233280, -0.219730, -0.067930, 1.043870, -0.248130, -0.869180, -0.286090, 2.026570, -1.147560, -2.362430,
0.808140, -0.279900, -0.758100, -1.258210, 0.498790, 0.151150, -0.289110, 1.215770, 1.853360, -0.302650,
1.162140, -0.699500, 1.081310, 0.187600, -2.954590, -0.083300, 0.328230, 0.479030, -0.785000, 0.735030,
1.313630, 1.344730, 1.129220, 1.085610, -1.371740, -0.346140, -0.698080, -1.345170, -0.747080, -0.262320,
-1.402140, 0.322780, -0.350280, -0.905970, 1.405830, -0.526120, 0.397580, 0.561530, -0.120930, 0.322110,
0.925320, -1.403540, -0.467940, 4.453280, 2.388650, -0.537880, -0.742420, -0.476220, 0.316290, 2.061680,
-3.471120, 0.339140, 1.110120, -1.011550, 0.813890, -1.005230, 0.298880, 1.832210, 0.067300, 0.431310,
1.285700, 0.146860, 0.007490, -0.369880, 0.536950, -0.243620, 0.502470, 0.402500, -0.139670, -0.293600,
-0.054160, 0.280040, -0.234500, 0.883350, -0.994630, 0.328630, -2.400400, -0.745060, -1.259170, -0.977710,
0.256370, -0.129490, -2.463900, -6.857430, -1.709380, -1.110730, 0.765020, -2.757220, -0.922660, -0.326270,
0.585660, -2.221470, -1.805030, -0.657260, 0.366430, -1.472280, -3.155440, -0.128630, -0.566560, -0.040350,
-1.066450, -1.556980, -1.345080, -0.791930, -0.272400, -1.554920, 0.310160, -0.991390,
1.570550, 0.325180, -1.372450, -0.116320, 0.962360, 1.935220, -0.112950, -0.275080, -1.694070, 0.465140,
1.824790, 0.500250, -0.753410, 1.662950, 0.919680, 0.464480, -1.068350, 0.888890, -2.311530, -1.106330,
0.711900, -0.072190, -0.084330, 1.346960, 0.840830, 1.468530, -2.272230, -2.331640, -0.992440, 0.809320,
2.337240, 0.323850, -1.603360, 0.094700, -0.184310, -0.591360, 2.270810, 0.140530, 0.732160, 0.035210,
1.622070, -0.833860, 0.736060, -2.165200, -1.363980, 0.954070, -0.771550, -1.058680, -0.448800, -0.758290,
0.070910, -1.457330, 0.340140, 2.018870, -0.098540, -2.065720, 0.223800, 0.297540, 0.603090, 1.078820,
0.455270, -1.035180, -1.683870, 1.222940, 1.367480, 0.733440, -0.130280, 0.380720, -0.917220, 0.521900,
1.322510, 0.007510, -0.962410, 2.800830, -3.329340, 0.840570, 0.354520, -0.882200, 0.146590, 1.958100,
0.465060, -0.807260, 0.323230, -1.431190, -0.829430, -1.166900, 1.039570, -1.893740, -0.717870, 0.591430,
0.319150, -0.054140, -0.708970, -0.708740, 1.675110, -1.411870, 0.954860, -0.150380, 0.375000, -0.037660,
-2.557900, 0.708210, 3.035580, -0.564590, -0.644070, -0.820870, -0.762070, 0.836560, 3.220100, -0.655360,
-1.337910, -1.464300, 0.613380, 0.543460, 0.269920, -1.757590, -1.001040, -0.288500, -2.801740, -2.503610,
-3.820240, -1.587820, -0.566520, -1.482540, -1.600260, -0.794920, -0.208740, -0.081800, 0.845310, -0.347210,
0.978700, -0.445480, -1.610490, -1.005030, 0.120400, -0.113780, 0.835600, -1.338120, -0.928670, -0.717520,
-0.934340, -2.512010, -1.072250, 0.950730, 0.458450, -0.297550, -1.528760, 0.068520, 2.936720, -0.496540,
0.457050, -4.365600, 0.942660, 0.737920, 0.376630, -2.156800, -1.803890, -0.207300, 0.250940, -0.996870,
-1.588090, -1.295500, 5.062590, -1.465250, -3.015960, 2.401440, 1.709290, 1.603300, 0.119720, -0.512460,
0.220600, 1.408330, -0.471910, -0.391740, -1.650370, -0.930370, -1.073980, -1.625390, -0.262200, -0.749070,
0.435320, 0.392050, -0.451360, -1.635090, -0.657320, 5.011170, 0.739880, -4.977200, -0.718680, 1.826990,
-0.082080, 3.588380, 1.759180, 0.341410, -0.026730, -0.732860, -0.542740, -1.450820, 0.375880, 1.233510,
-4.743900, -0.789530, -6.992440, -0.558740, -1.199910, -1.391440, -0.339620, -1.650320, 2.973570, 0.581970,
-2.277170, 1.178770, 2.401820, -0.731890, 2.719660, 5.091060, 1.737980, 4.699730, -2.872230, 0.889130,
0.790750, 0.720310, -1.356670, -0.433740, -0.980860, -4.168640, -1.774180, -0.808510, 0.362400, -1.228310,
-0.148290, 5.453520, 1.923660, -0.801390, 1.131780, 1.652230, -0.476620, 2.771570, 0.176560, -0.013250,
0.519550, -0.611490, 1.588880, 1.445600, 1.142340, 0.905430, 0.285890, 0.370340, -2.365200, -0.525170,
-1.445270, -0.662360, -0.951170, 1.022540, 1.696200, -0.004710, 0.522190, 0.075840, 1.334460, 0.557060,
-2.007480, -0.524350, 0.149840, 0.931270, 1.073240, 1.510900, -2.709300, -1.635690, -0.071190, -2.226700,
-0.123640, -0.790530, 0.686350, 4.643500, -0.340660, 0.573550, -2.727200, 1.177160, -0.271000, -0.983670,
-5.238220, -1.215380, 0.184870, -0.987700, -0.364890, -2.171480, -0.249350, 0.608310, 1.185150, 0.926170,
1.403740, 0.700400, 0.477530, -1.103290, 0.073000, 0.921890, 0.272870, -0.353580,
-0.433310, 0.185460, -0.769380, -0.192720, 0.324490, 0.357920, -0.738550, -1.996200, 1.200940, 1.764470,
-0.827620, -1.215910, 0.198770, -1.119820, 2.487140, 0.737690, -0.893850, 1.094330, 0.202800, -0.267580,
-0.845190, -1.793530, -2.130500, -0.372710, -0.807460, 1.601550, -1.979970, 0.730880, 1.830710, -0.393730,
-1.851720, 3.023060, 2.373600, 0.994380, -0.479070, -2.653750, 0.111250, 1.141880, -2.069070, -0.998370,
1.392550, -1.049290, -0.218630, 0.663800, -1.457660, 1.176920, -0.916470, -1.290180, 1.264860, 1.102670,
0.062510, -1.209750, 0.958720, 1.481460, 0.204870, 0.417350, -0.617760, -0.350940, 0.113780, -1.380920,
0.837440, -0.298800, 0.800090, -0.415460, 1.550840, -0.220010, 0.240420, 0.173340, 1.117950, -0.626720,
0.548730, -2.107740, -0.739980, -0.017440, 0.100440, 0.480220, -0.011850, 1.848440, -0.567550, -1.044590,
0.039890, -0.905950, 0.516880, 0.973890, 0.977640, -2.205900, 0.554780, 3.852710, -1.947420, -1.407020,
-1.768160, -0.620330, 0.685370, 7.416880, -0.168260, 1.303220, 0.386180, 1.278130, -0.192000, 1.037060,
3.338990, -1.789300, -1.364460, -0.263150, -2.371180, 2.172580, 2.392780, -2.653030, -1.363330, 0.557870,
-0.956850, 0.388700, 2.461380, -1.534040, 0.704070, -0.291080, 4.233510, 1.781870, 1.998680, 0.091850,
1.826080, -1.201040, 0.375840, 3.272910, -0.400210, -3.009480, -1.554500, -1.226550, 1.593980, 0.525830,
-2.138940, -1.506490, 0.822410, -1.353810, -1.289930, 4.617320, -0.840320, -2.519040, 0.614860, 3.756800,
0.390870, 0.160690, 0.228750, -1.553790, -0.714600, -0.211520, 0.518950, 1.052140, 0.107120, -0.304010,
1.696580, 1.738040, 2.700750, -0.991760, -0.942310, -0.059070, 0.222280, -1.588010, 1.656010, -0.901470,
-0.628050, -0.343840, 0.364310, -1.199490, -1.504580, 1.103510, -0.244760, -0.010510, 0.139940, -0.236590,
-0.001720, 0.121070, -0.053930, 0.636680, 1.693820, -1.073810, -0.800200, 0.083130, 0.857310, -0.371680,
0.787950, 1.205920, 0.204280, -1.681180, 0.742970, -0.724440, 0.113160, 0.175000, -1.340970, 0.852860,
-0.492450, -0.005750, 0.738840, -0.494290, -0.913280, -0.794900, 0.122990, -0.518890, -2.176650, -0.147740,
0.028790, 0.438280, 0.492010, 0.255200, -0.414270, -1.548170, -0.155100, -0.485710, 0.164730, 1.723470,
-0.576550, 0.078250, 0.516150, -0.194650, -1.462410, 0.213040, 1.012920, -3.056370, 0.205440, 0.036700,
-1.083950, -0.825590, -0.128520, 0.245860, -0.344960, -0.225620, -1.909670, -0.388770, 0.609040, 0.841780,
-0.579390, 1.741850, 0.191620, -1.032790, -3.146660, -0.190190, -0.687440, 0.726030, -1.442250, 0.013960,
-0.683790, -0.264310, 0.563300, -0.790540, -1.071510, -0.504080, -1.050890, -1.359560, 0.048590, -1.139080,
-0.366220, -0.669090, 0.524860, -0.158020, 0.764540, -0.622440, -1.554010, -0.969800, -0.922270, 2.074880,
0.773230, -2.038320, 0.596650, -0.788450, 1.287750, -0.064120, -0.777110, 0.421720, -2.313740, -0.084880,
0.416780, -1.007890, 0.509750, -3.120460, -1.759290, 0.192620, -0.809880, -0.221500, 0.427550, 0.191880,
2.921020, 0.283550, -0.530530, 3.293690, -0.940460, -2.161250, 1.782570, -1.743400, -0.540600, -1.090640,
-0.844150, -5.249090, -0.379200, -0.825910, 0.495770, 0.793040, 0.648020, -0.050770,
-1.561830, -1.002960, -0.959820, -0.698260, -0.674220, 1.570150, -0.564100, -0.518100, -2.600140, 0.626100,
0.930430, 1.118960, -0.091190, -0.198380, 0.408460, -0.279400, 0.058030, -0.247630, -0.490480, -0.368460,
1.553580, -1.784210, 0.225120, 0.472810, -0.472990, -0.049500, 2.698750, -0.812860, 1.764260, 0.698150,
-0.145360, -1.600320, -1.468150, -1.322970, 1.917660, -0.089480, -1.143580, 0.707950, 0.647690, -0.519250,
-0.964500, 1.940840, 0.707210, -0.637620, -1.955440, -1.086540, 0.721330, 0.550650, -0.267930, -0.397060,
0.229950, 0.585410, 0.608930, -0.363470, -0.308550, 0.235160, -0.287260, 0.655940, 0.370160, -1.431780,
2.267240, 0.380290, -0.677020, 0.142640, 0.411360, 0.304350, -0.484120, -2.058700, -0.876630, 1.405220,
2.885700, -0.815420, 0.474090, 0.249040, 1.159260, -1.280560, -0.214160, 1.937480, -0.185840, -5.526930,
-0.331280, 0.406860, -2.600390, 0.302390, -0.332500, 1.608360, 0.708010, 0.954360, -0.594960, 0.611100,
-2.306430, -0.143950, 1.334150, 2.096370, -0.164650, 2.420500, -1.462470, 0.772740, -0.369980, -1.276890,
2.633670, -0.382660, -2.720110, -0.831630, 0.060220, -0.050500, -0.306310, -0.990700, -2.112470, -1.923250,
5.515210, 1.227770, 0.354050, -1.363200, -0.742390, -1.024250, 4.383190, -1.724000, 1.301450, -3.742740,
0.160560, -0.386520, -0.026130, 1.032940, 0.681710, -3.685660, -0.295670, -0.671520, -1.243060, 0.076340,
-0.435980, -1.641390, -1.904120, 2.632630, 1.845690, -0.157580, 1.221880, -0.738870, 2.112940, 4.230030,
0.505270, 0.267490, -1.604540, -1.274830, -0.243100, 0.416110, 4.753870, 0.206240, -4.253180, -1.719930,
1.098640, 1.547360, -0.991610, -2.577270, -1.439720, -0.839890, 1.790790, 0.771850, 2.369350, -1.012050,
1.758280, -0.591120, 1.187190, 0.764340, 2.205340, -0.093550, 0.967600, -0.419760, 0.630890, 2.040130,
1.173770, -5.927410, -0.214060, 0.253320, 0.373490, 0.163760, 0.241260, 0.569510, 1.897700, -2.175130,
-0.479990, 1.588890, -1.129740, 0.834510, -0.109390, 0.901470, 0.897860, 1.626030, -0.478100, -1.620790,
1.000980, -0.008730, -0.743810, 0.491420, -1.614840, -0.932040, -0.072220, 1.045860, -1.370630, -0.002440,
-0.636020, 0.436130, 0.333150, 0.856710, 2.126270, -0.015980, 0.659650, -0.239030, 1.733700, -0.461760,
2.511280, -0.979860, -2.032780, 0.334810, -0.054890, -0.919670, 0.892170, -3.451670, -0.563510, -0.445160,
-2.521480, -1.065520, -0.892980, -0.282050, 0.168970, 1.777020, 2.165950, -0.410380, -1.520600, 1.258400,
-1.499670, -1.265760, 0.870960, 3.163620, 1.605350, 1.662720, -0.894020, -1.139510, 0.452700, 0.104180,
1.040890, -0.909260, -2.226200, -2.262690, 0.083870, -0.074270, -0.927170, -0.994540, 0.801040, -0.880880,
-1.037330, -0.834010, 0.897330, -0.606690, 2.426850, 0.383830, 0.446280, -1.466890, -1.251320, 0.080420,
-0.122680, 1.724780, 1.726520, -0.738200, 0.013110, -1.383410, 1.967370, -1.757110, -3.415240, 2.766830,
0.558740, 0.511260, -0.521610, -2.961650, -0.119710, 0.795970, 2.443380, -0.809750, -0.990360, 0.589920,
0.480900, 0.205160, -0.112220, 0.592600, -1.179410, -0.725250, -0.553610, 0.239920, 0.510070, 0.771370,
0.332740, -0.915950, -0.079070, 0.702660, -0.839400, 1.265440, 0.699620, -1.029950,
-0.445310, -0.306140, 0.583090, -0.500500, -0.719740, 0.292510, -0.064450, -0.136890, 0.353140, -0.023980,
0.114390, 0.012350, -1.490610, -0.493990, -0.993320, -0.192380, -1.178970, 0.283290, 0.464860, -0.030900,
0.668850, -0.105130, 0.579130, -0.670180, -1.210640, -0.622490, 0.700340, -1.329500, -0.283530, 0.131370,
1.115520, -0.666530, 0.963760, -1.190540, -0.287400, 0.204440, 0.935000, 0.585000, 0.076080, 0.292050,
0.691370, -1.777780, 0.466880, 1.984770, -0.626160, 0.063450, 1.134500, -0.930990, 0.736850, 0.069610,
-0.889910, 0.121350, 0.167580, -0.137700, -0.934930, -0.128670, 1.527650, 0.309390, -0.503300, -0.517040,
-0.607420, -1.777490, -0.586800, -0.533540, 0.616190, 0.411120, -1.210650, 0.106100, 0.587980, -0.137420,
0.800730, -0.203760, -0.598020, 0.141920, -1.007390, 0.028480, -0.088800, -0.679410, -2.122190, -1.827660,
0.278360, -0.350690, -0.219700, 0.918840, -0.377790, 0.123520, -0.756400, -0.089460, 1.333490, -1.969640,
-0.755780, -1.015990, -1.228640, 0.983980, 0.760500, -0.166590, 1.707290, -0.413580, 0.452500, -1.165240,
0.978920, 1.734060, -0.327650, -0.709390, -0.364140, 0.594530, 0.724840, 1.262120, 0.747010, 1.014110,
0.024150, -0.036870, -0.343760, -0.593450, -0.670230, -0.296900, 1.434440, 0.437080, 0.309510, -1.366000,
-0.043410, 0.093240, 0.664100, 0.915410, -0.091160, 0.819090, 0.886540, 0.291980, 1.177470, -0.033120,
0.059570, 0.935780, 0.744440, -0.340610, -1.297710, 0.329640, -0.756420, 0.923950, 0.284790, 0.434480,
-0.616750, 0.628750, -0.413210, -0.123710, -0.898690, 0.809150, -1.893240, -2.105100, -1.026270, -0.527810,
0.713170, -0.359530, 0.474240, -0.000880, 1.179990, -2.383330, 1.063550, 1.184220, -2.306030, -0.146040,
-1.789300, 0.684010, 0.756810, -0.213450, -0.538800, 2.681910, -0.762210, 0.164180, -0.678630, -0.689090,
-1.876360, -0.601310, -0.579240, 0.422840, -0.131840, 0.600470, -0.755160, 0.483350, -1.007270, -0.428170,
0.312320, 0.657320, 0.046030, -1.751520, 0.992570, 1.361630, 1.606540, 1.097260, 1.139870, -0.012190,
-0.620660, 0.052230, 2.612950, 0.922240, 0.603200, -0.320080, -0.100730, -0.008950, -0.580220, -0.226810,
0.827470, 2.330000, -0.659390, -0.868320, -0.223170, 0.536310, 0.502280, 1.082690, -0.692810, -0.412820,
1.096820, -0.339680, 0.343110, -0.870110, -0.241350, 0.769950, -1.272770, -1.241390, -0.268500, -0.375570,
-1.144630, -1.016600, 0.872010, -0.591600, 0.672400, 1.117870, 0.946740, 0.697220, -0.142780, 0.201580,
-0.677190, -0.230850, -0.452740, 2.573450, 0.009970, -0.178990, 1.150850, -0.225750, -1.758890, -1.294080,
-0.400580, -0.078160, 0.100270, 0.800840, 0.567430, 0.799080, 1.502900, -2.346200, 3.041220, 0.729890,
-0.440330, -0.522960, -0.040510, 0.111880, -0.159100, 0.446220, 0.609050, 0.305510, 0.257100, -0.989780,
0.117670, -0.281740, 0.034530, -0.392100, -1.640420, -0.875790, 0.188320, 0.075940, -0.809630, -0.197640,
-0.375090, -0.342140, -0.094940, -5.879020, 0.128350, -0.824590, -0.758680, -3.132760, -1.041360, -1.462940,
-0.830060, 0.114500, -1.280350, -1.104060, 0.394260, -0.706950, -3.132720, -0.773700, -2.478330, -1.153400,
-1.775590, -1.403800, 0.764110, 0.260380, -1.395340, -1.489150, -0.441700, -1.177830,
-0.251670, -0.403880, -0.392510, -0.324900, -0.377080, 0.696820, -0.765810, -0.194810, -0.439890, 0.440820,
0.804010, -0.203610, -0.612020, -0.356590, 0.574590, -0.423320, -0.108250, 0.427170, -0.680080, 0.514830,
-0.856010, -1.669600, -0.448590, 2.542990, -1.443450, -0.264620, -0.058170, 1.688570, -0.789760, 0.597230,
-0.799200, -1.269120, 0.312270, 0.901910, -0.263180, -0.324470, 0.746680, 0.264830, -1.080200, -3.085030,
1.153160, 0.998650, -1.237680, 0.340490, 2.996820, 0.038730, -0.071120, -1.466800, -0.659900, 0.224900,
-0.400620, 0.366660, -0.009010, -0.478610, -0.354920, 0.197490, -1.977690, 0.396620, 0.167770, -0.142980,
1.006180, -1.709200, -2.088370, 1.829830, -2.503070, -0.608980, 1.845180, 3.056250, -0.058030, 1.169710,
0.696370, 0.401990, -1.638300, 0.832000, -2.509670, 1.757620, -0.096250, -0.531980, -0.893470, 0.934630,
-0.934900, 0.657810, 1.410110, 1.284190, 0.834300, -0.012560, 0.745130, -0.589690, 0.407600, 0.263450,
0.783020, -3.219020, -0.743090, -1.086880, -3.066220, -0.274820, 0.319650, -0.087670, 2.641400, 0.517220,
0.494570, -1.731370, -0.637930, -0.002530, 0.293480, -0.994850, -0.863110, -0.445260, -1.952020, -2.012020,
-1.156150, -0.055980, -2.453580, -0.239170, -1.374290, -2.055490, -0.364700, 0.914870, -0.507410, 0.432920,
-0.782750, 0.500080, 2.263870, -2.853500, -0.318510, 4.205490, -2.453400, -0.272760, 0.504430, 0.054680,
1.732220, 4.113270, -1.547260, -0.584080, 1.668580, 1.120360, -0.423770, 1.225620, -0.047610, 1.939840,
-1.571360, 3.632700, -0.527370, -0.566100, -0.193010, 0.622210, 0.508620, 1.204320, 1.013130, -1.728930,
1.296150, -0.993560, 2.004120, -0.120310, 2.452880, -0.100960, -1.129590, -0.424150, 0.179400, 0.654790,
0.869530, 0.165590, -1.300490, 1.937150, 1.712560, 1.870630, -0.513590, 0.371960, 0.809000, -0.877840,
4.263750, 2.570580, -1.767920, 1.816440, -1.098620, -1.032700, 0.196670, 0.746340, -1.949840, 1.232880,
-0.052270, -1.391060, -0.508780, -0.358790, -1.665830, -3.207370, 0.036550, 1.416200, 1.398750, -1.161390,
1.427610, -1.433130, 0.455890, 0.500150, 1.847520, 0.842430, -0.547990, -1.408000, -0.129830, -0.177140,
0.752510, -3.176790, -1.481650, 1.225180, -1.606110, 1.515850, 0.157000, 0.556170, -0.816160, 0.924440,
1.051940, -0.167030, -1.441770, 0.263400, 0.035670, -1.233320, 0.291790, -0.424940, -1.456520, 0.340700,
-1.802040, -1.538330, 0.813410, 0.750860, -0.248250, 1.458070, 1.786220, -1.008820, 0.044740, 1.615460,
3.679880, -1.240790, 1.146030, 0.534740, 1.742090, 0.197390, -0.656300, 0.362270, 1.829200, 0.633060,
-0.913580, -0.072540, 1.459610, -0.783190, -2.294130, 0.017440, -0.518710, 1.945690, 0.373740, -0.018750,
1.918770, -0.832070, 0.449650, -0.001020, -0.291570, 0.839410, -0.301800, -4.944030, -2.504760, -0.581310,
1.933460, 0.258230, -0.196070, 0.189980, -0.291470, 2.531140, 2.306380, -0.221730, 0.945070, -1.163370,
-2.391890, -2.154800, -0.483660, 2.680490, -0.121570, 0.343380, 0.644360, 0.756380, 0.839400, -0.329430,
-4.360720, -0.099280, 0.936980, -4.857280, -0.978870, 0.442200, 0.532670, -0.083770, 0.144660, -0.436340,
-0.437730, -1.226740, -0.871880, -1.182340, 0.162590, -1.833180, 0.738260, -0.780970,
-0.596460, 3.641310, 0.557370, 2.138630, 0.466660, -2.141190, 0.944810, -0.665400, 1.111980, 2.122290,
0.887210, 1.639170, 1.790640, -0.878790, -0.820160, -0.874970, 1.964540, -0.387190, 1.137510, -0.779620,
0.766960, -0.351290, 0.943870, -1.108110, -2.273460, 0.904220, -1.739230, -1.318660, 0.848670, -1.241100,
1.051880, 0.835720, -0.187210, -0.697000, 1.514730, -0.655930, 2.822630, 2.701350, -1.429200, -0.137410,
-0.387900, 0.983950, 1.808560, 0.472630, -0.382060, -0.614580, -0.286980, 0.172280, 1.253610, 0.938100,
3.666010, 2.874480, -0.318390, -1.879410, -2.069360, -0.512860, 1.783700, 1.786390, 0.893810, -0.769870,
0.606510, -0.592550, 0.940300, -1.493280, 0.674130, 1.490550, -0.311520, 0.347650, -0.551660, 4.343880,
2.526720, 1.238810, -1.397100, -0.617980, 3.889570, 0.557500, 2.116570, 1.179060, -0.436100, -2.882900,
-1.997080, -0.580690, 4.408170, 4.169510, 1.207100, -2.022090, 1.130480, 0.209350, 1.227000, 0.086820,
0.896880, -3.120080, 1.967550, 4.999750, 0.218780, -4.384220, -0.627550, -1.519850, -0.739200, -1.055240,
0.677310, 2.256040, 0.760790, 3.832040, -1.587520, 5.611840, -1.495030, 0.581310, 1.138640, -1.121960,
-0.417470, 2.693570, 0.288150, 2.219270, -2.906090, 1.389370, 7.965850, -0.568680, -3.302530, -0.184500,
2.923960, 0.453230, 1.484990, 1.246880, 3.001450, -0.775600, -3.125030, -3.417270, 1.509560, 4.124470,
-1.346970, 0.318750, 0.124080, -5.405560, 1.473870, -0.770290, -0.028840, -0.984030, -2.180820, 2.443850,
-0.918240, -0.257070, -0.396210, -0.282670, 0.220840, 0.535450, 1.110920, -0.939400, -0.128020, 0.181760,
1.247800, -1.523370, -0.743850, 0.350250, -0.850130, 0.702680, 0.307740, -0.190230, -0.586530, -1.019920,
-0.834630, 1.289530, -0.993080, -1.070190, 0.487200, -1.754390, 0.516910, 0.421850, 2.170560, -0.601970,
-1.566770, 1.144620, -0.570330, 1.194740, -0.396590, 1.329430, 1.203970, -1.380030, 0.946050, -0.837120,
1.034720, -0.953210, -0.587900, 0.183170, 1.795060, 0.159160, 0.621400, -2.203510, 0.242080, -1.267650,
-1.795850, -1.238100, -1.101060, 0.866310, 0.530290, 0.042860, -0.419390, -0.746020, -0.631310, -1.625910,
0.468900, -0.740460, -0.413740, -0.135970, -0.501730, 0.096960, 0.650900, -1.698670, 1.703980, -0.896210,
-1.238100, 1.768940, 1.093180, -2.038120, 0.917650, -1.200850, 3.318860, 0.782110, 1.225690, -0.073960,
-0.159640, 0.401110, 1.579830, 1.761700, -1.303730, -0.778730, -1.466510, -0.273400, -1.035660, -0.866370,
-0.422420, -0.427560, -0.571810, -0.363270, -1.177060, -0.784160, -0.025490, 1.196540, 0.420100, 0.741040,
1.468230, -1.710270, -0.050930, -0.842780, 0.084020, 0.725260, -1.379880, -0.710310, 3.002230, 0.733970,
0.665820, -1.110690, -0.695360, -0.427820, 0.343200, 0.912120, 0.090460, 0.022460, 1.657050, 2.291750,
2.508050, -0.798290, 1.744100, 1.324950, 2.549850, -1.586570, -0.820880, -0.969910, 0.363860, -0.092580,
-0.018670, -0.402650, 0.807290, -0.657270, -0.698410, 1.003200, -3.079520, -0.282160, -0.259860, -0.119250,
-6.384620, -0.603490, 0.829930, 0.100550, 0.661530, -0.681180, -0.482360, 0.369070, 0.329890, 0.057910,
-0.306330, -0.973210, 0.664700, -2.893320, 0.256920, -0.059400, 0.787130, 1.123850,
0.736890, -0.450080, -0.263560, 0.764410, 0.491170, -1.213560, -0.012170, 0.012180, -0.224980, 0.916690,
0.274460, -0.286980, -0.739550, -0.357030, -1.113100, -0.215800, -0.104730, 1.433660, 1.567140, -0.442960,
-0.772100, 0.452730, 2.040560, -0.438950, 1.234010, -0.625890, 0.182780, -0.604550, 0.320190, -0.435380,
0.129310, -0.028470, -0.158700, -1.728100, -0.384080, 2.257260, -0.866810, -0.617760, 0.188190, 2.775580,
0.636670, -0.278060, 0.238010, -1.330990, 0.311080, -0.219330, -1.377200, -0.298330, -1.451000, 1.093160,
1.073730, 0.779830, 0.670920, -0.794380, 0.690470, 0.090080, -1.558370, -1.485180, 1.542170, -0.918750,
-0.803240, -1.057060, -0.746720, 0.712800, 2.182080, 1.883430, -0.530000, 0.939110, 0.504210, 0.696210,
0.654710, 2.581550, 1.269490, -0.509010, 0.713880, -0.603050, -0.186560, 1.409890, 0.770330, 0.595570,
-1.048630, 0.096990, -1.392120, 1.345340, -0.929840, -0.893000, 0.839490, -1.344810, 0.677230, 0.898780,
0.043740, -0.528090, 0.524380, 3.110820, -0.055850, 2.807480, -0.808060, 1.196330, -1.016210, -0.608280,
1.645280, 0.800400, 0.157190, -0.312710, -1.546430, -1.385160, -0.700030, 0.161800, -1.174920, 0.274310,
1.654840, -0.170730, -0.244050, -0.830370, 2.125640, 0.102660, -1.603340, -0.450100, 2.240760, 0.146710,
-0.872210, 0.336530, -3.080450, 0.891790, -0.513850, -1.151940, 0.433740, -0.907070, -0.467550, -0.560050,
-0.145650, 0.069620, -0.801330, 1.245070, -0.724250, -0.483620, 0.851910, 0.594180, 0.333560, 0.348740,
-0.454800, -1.278960, 1.163800, 0.639630, -0.119750, -2.294510, 3.295790, -2.248160, -1.487120, -0.825500,
-0.934600, 1.215750, 1.033520, -0.970410, -0.454390, -0.002320, -0.875080, -1.006360, 0.066520, 0.911470,
0.631720, 0.906680, -0.228010, -0.172200, -3.140200, 3.994860, 0.111120, -0.853500, -0.486050, 1.501080,
0.095740, 1.345160, -1.345200, -0.818660, 2.848920, 0.686110, -0.700810, -0.475430, 1.600450, -1.953330,
-0.202600, 2.475860, 0.169000, -1.764930, -1.630940, 2.263920, -0.163890, -0.329500, 0.129500, -0.606220,
-0.065940, 0.632510, 0.386460, 0.024870, 0.653340, -0.283870, 0.462740, 0.192730, -0.418590, 0.144300,
-0.089680, -0.376480, -0.011130, 0.399570, 0.501760, 0.479950, 0.553420, -0.831280, 2.426490, -0.382750,
0.730160, -0.417410, -0.881870, -0.555820, 0.061820, -0.418160, 0.585110, 0.575830, 0.383790, -0.162640,
-0.761170, 0.772480, -0.570640, 1.170240, -1.017820, 0.191380, 0.173180, -0.264610, 0.526520, 1.481490,
0.128780, -0.742940, -0.216520, 0.307800, 0.063410, -0.450040, -0.825150, 0.904550, -0.123870, 0.856910,
0.805810, 0.876190, -0.403780, 0.108510, -0.081650, -1.082590, -1.882850, -0.846490, 0.243410, -0.347540,
-0.782480, -1.457900, 1.091490, -0.251820, 0.998560, -0.284080, -1.147610, -0.745260, 1.209860, -0.716150,
-0.631450, 0.718550, 1.360690, 1.047780, 1.126290, 0.614440, -0.776760, -0.290320, -0.095140, 0.830980,
-1.126350, -1.551980, -0.359150, -5.004130, -0.551610, -1.853220, 0.321730, -0.988430, -0.871170, -1.248510,
0.871780, -1.345160, -0.824170, 1.037970, 0.153670, -0.990310, -1.181130, -0.783390, -0.523140, -0.647050,
-1.382830, 0.651980, -0.083030, 1.510590, -1.473130, -0.175220, -0.300200, -0.341050,
1.447030, -1.700330, 1.403760, 1.089720, -0.918220, 0.311400, 0.299440, -0.398170, -0.429520, -0.101130,
0.389940, 3.446770, 1.140890, 1.093940, 0.592400, -0.844540, -1.288200, -0.580830, 1.708100, 0.433110,
0.509890, -0.619970, 0.904680, 0.172430, 0.094150, -0.398350, 1.145230, 0.170860, 1.291620, -0.599570,
0.193720, -4.137090, -0.161930, -3.344400, -1.369190, 0.099100, -2.261880, 0.819800, 0.686160, -1.118980,
1.903340, 0.473390, 2.378070, -1.867430, 0.459370, 0.888100, 0.823670, 1.316580, -0.994040, -1.268830,
-0.062930, 0.368760, -0.993600, 3.019130, -1.922090, 0.918860, -2.566590, 0.910550, 4.078670, -0.840600,
-1.710400, -1.258330, 0.758530, -0.815880, 0.870060, 0.795630, -0.449510, 1.238680, 0.418450, 1.518830,
0.614120, -2.779560, 2.623890, 0.764950, 0.535510, -0.608520, 1.515360, 2.812560, -0.299410, 0.086390,
-0.805240, -0.492790, -6.204900, -1.598700, -0.618700, -0.526110, -2.330230, 0.194230, -0.315620, -1.394860,
-0.069190, 0.640640, -0.790040, 0.109180, -1.989740, 3.234760, 0.220050, 1.688280, -1.922040, 0.013310,
0.849650, 0.598400, -0.874470, -1.031610, 0.787740, -1.816890, -0.343100, -0.102190, -1.025020, -3.370900,
1.724750, 2.560170, -0.625630, -1.689280, -0.441090, -0.728140, 1.825160, 1.389830, 3.490190, -0.833940,
0.649220, -0.690580, -0.343240, 3.625760, 2.070060, -0.988600, -0.782750, 2.391120, 2.103600, 0.616060,
0.042260, 1.706670, 1.760490, 1.602690, 3.558750, -0.191630, 0.396530, 1.128490, 0.611730, 0.556730,
3.146770, 5.302880, 0.590920, 2.116170, 0.054040, -0.523990, 1.254870, 0.150960, -1.223220, 0.372540,
1.331360, -1.377150, -0.664140, 0.375200, 0.893460, 1.224000, 2.358520, 1.530580, 0.650290, -0.164470,
0.234330, 1.413030, -5.839540, -1.410840, 3.560740, -0.852090, 0.677660, -1.202750, -1.038810, -0.699570,
1.055990, -1.297590, -0.715410, 1.098240, 0.295810, 1.928020, -0.841720, -1.222850, -1.382270, 2.593060,
-0.371540, -0.255980, -0.759130, 0.485710, 1.018720, -4.818900, 1.542090, 2.185420, -1.538670, 0.043100,
-0.260010, -1.445110, 0.628840, 0.333500, -2.880600, -1.354390, -0.779010, 2.297170, 0.576090, -0.900310,
-1.791490, 0.183390, 6.674520, 1.770590, 0.555440, 0.170910, -1.182900, 0.202470, 1.167440, 0.790210,
-0.404660, 1.134490, 0.476490, 0.666440, -2.270780, -1.277470, 0.774230, -5.879040, -0.667690, -2.901710,
0.633470, -1.338290, -0.023680, 0.193010, 1.675100, 5.893080, 1.767070, 0.774220, 0.874790, -5.072700,
-0.105440, -2.018740, 0.519330, 7.704550, 1.283430, -1.343080, -1.168050, -3.176490, -1.312700, -0.659300,
-6.335510, -1.065770, 1.574970, 0.719390, 1.475090, 0.336280, -0.124250, 3.201690, 4.212860, 0.520700,
-0.422150, 2.332420, 0.100090, -3.043820, -1.656150, 1.146330, 1.654110, 0.704450, -0.882970, -2.327870,
-0.580930, -1.049870, -0.711910, -0.537110, -1.605360, 2.231450, -0.852970, 0.962340, -0.677520, -0.392860,
-0.375380, 0.696190, 0.666650, -3.344640, 0.569950, -0.742830, 5.374340, 0.722230, -0.387810, -0.621980,
3.884360, -0.226550, -0.629480, 0.381440, -0.181620, 0.447460, -0.150040, -0.621800, -0.050560, -0.229840,
0.649770, 0.923150, -0.765240, 0.925080, 0.215990, 0.605470, -0.747870, -0.866700,
-1.496000, -0.013860, -0.043640, 0.291620, 0.436030, -0.904700, -0.344630, -0.476240, -0.012550, 1.505770,
0.444500, -0.109810, 0.242550, -0.284470, -1.696280, -1.827670, -2.267840, 0.420430, -0.664520, 0.610500,
-0.010790, -2.427350, 2.399710, 1.044080, 0.168640, 1.319960, -0.738400, 0.451690, 0.910880, 0.329050,
1.269640, -2.038290, -0.163530, 0.129920, -0.214420, -0.104950, 2.018880, -1.482730, 2.477550, 1.400990,
-1.715640, -0.328350, 1.752270, 0.232120, 0.198080, 0.473480, -1.902750, -1.912150, 0.305920, 0.960370,
-1.905300, -0.183910, 1.953090, 0.962080, -0.309950, 0.123560, 0.771430, -0.283280, 1.184320, 0.572400,
1.584460, 0.444770, 0.505130, -1.391230, 1.464740, -0.068720, 0.381840, -0.594340, 5.118650, -0.237300,
0.096810, -0.868770, -1.575300, 1.204040, 0.866610, 0.388500, 0.970460, -1.370860, 2.200950, -0.539200,
-0.439920, 1.049630, -0.485130, -0.080630, 1.811540, -0.549960, 1.216550, 0.978140, -0.176750, -0.195800,
-0.035950, 1.512450, 0.996510, -0.073010, 0.588800, 3.576730, -0.891800, 1.868440, 1.944720, -1.260280,
1.621710, -0.693660, -1.482580, -0.976920, -0.298170, -1.732630, 1.301890, -0.145620, 0.089560, -0.272980,
0.226530, -0.730610, 0.026790, -0.075240, 0.355140, -0.740820, -1.178920, -0.448590, 2.909320, 0.134290,
-0.166210, -0.938870, -0.756780, 0.526890, 1.645380, -1.477890, -0.376730, 0.159710, -1.126730, 1.337890,
1.497920, 0.676060, -2.408420, 1.919700, 1.770260, 1.082040, 0.469900, 2.652230, -1.030920, -0.023600,
1.510470, 0.622530, -0.876900, -0.702000, -1.505790, -0.513290, -0.795580, 0.018620, -1.708080, 1.888820,
2.160660, 1.497400, 0.710360, 1.080610, 1.968910, -0.202070, -1.198110, -1.415410, 0.446790, 0.362420,
0.006290, 0.917590, -0.480060, 0.425740, -5.096890, 1.171780, 0.374590, 0.817290, 0.627770, 0.374720,
1.080270, 0.873460, 0.131320, -0.495980, -0.198700, -0.523950, 1.712630, -0.807300, -1.659610, 5.007460,
1.438090, -0.536350, -0.453600, 1.328990, 1.225830, 1.400720, 0.802230, -2.049050, 0.498720, -2.002480,
1.450700, -1.143110, 2.108640, -0.436700, 0.823230, -1.138890, 0.855460, -0.070700, 0.222240, -0.184180,
2.150540, 0.519980, 0.939020, 0.710840, -0.551550, 0.665680, 1.584110, -0.701030, 4.531750, 2.447630,
0.124560, 0.163360, 0.951350, 1.064750, -1.158340, 1.303550, 1.789390, -0.647060, -1.684220, 1.446410,
0.378350, 0.468740, -1.765200, -0.165400, 0.527430, 0.343710, 1.064810, -0.001840, 0.466860, 0.864890,
3.413330, 1.160300, -0.773410, 0.101730, 0.735590, 0.335700, -0.501320, -0.671120, -1.189250, 1.097360,
-3.329750, -0.545070, 0.983010, -0.525530, 0.739860, -0.868400, 0.449380, 0.238220, 2.972950, -1.277940,
0.046430, 0.611910, -0.545040, -3.452670, -1.082480, 0.930430, -0.091990, 0.629440, -3.051410, -1.295950,
-1.316800, -0.122330, 0.526870, 1.712630, -3.191980, -1.290730, 1.162360, 0.104010, 0.832500, 0.492190,
-0.064180, -0.683770, -0.987340, -4.790420, -0.665580, -0.028520, 2.910870, -0.635350, -2.160600, 0.897380,
4.050810, -0.546030, -0.885870, 0.923890, -0.084380, 2.923930, -2.169820, 0.290600, -2.105820, -0.831410,
-0.280570, -0.609290, 0.465940, 1.719200, 0.137830, -0.555440, -1.680640, 0.344800,
-0.896570, -0.203260, 0.636260, 1.305110, -1.549280, -1.133630, -0.257360, -1.519880, -0.069950, -0.585580,
0.063600, 0.195560, -1.730480, -1.423410, -0.346210, -0.892780, 0.178880, 0.041090, 1.703010, -0.008710,
-1.659290, 0.126630, -0.676790, -2.703390, -0.365570, -0.009710, 1.583100, -1.054990, -1.001100, 1.336470,
-2.659190, -0.763800, -0.759440, -0.276160, -1.135740, -0.029080, -0.546360, 0.289250, 0.754130, -0.104170,
-0.531560, 1.580600, -1.229840, -0.655960, 0.490680, 0.607680, 0.585140, 2.007270, -0.057830, -1.376470,
0.063090, -0.842880, 0.989900, -1.303330, -1.845970, 0.675860, -1.572800, -1.222110, -0.328020, 0.538260,
-0.316870, -0.078800, -0.085850, 0.294370, 1.010140, 1.251580, -0.189200, 1.610710, 0.038990, 0.720320,
-0.897780, -0.205740, 0.847310, 1.911650, 0.774150, 1.405490, -3.930090, -0.595360, 2.069060, -1.399980,
0.135210, -1.183130, -1.993600, -2.366060, -1.256210, -2.120660, -0.424420, 3.372130, -0.586320, 2.231210,
0.537370, 1.883110, 1.525010, -0.034920, -3.358470, 0.559590, 1.272040, 0.309840, -2.440540, -0.378450,
1.435710, -2.636380, -3.949870, -1.525080, -0.321880, -0.434530, -0.995470, -1.118030, -4.424480, -1.658430,
2.072700, 1.688610, 1.706760, 1.723400, -0.009330, 4.244140, 1.238860, -0.229150, -0.684190, 0.054420,
0.091940, 1.380810, 0.174440, 2.760850, -4.940540, -2.013780, -2.803020, -1.980560, 0.724340, 0.789240,
-0.613870, -2.853500, 1.212200, -4.468570, -1.482250, 2.336740, -0.023990, -1.278870, 1.261980, 6.806920,
0.402650, -2.801840, 0.666270, -0.203400, 0.558090, -0.404770, -1.175790, 0.898720, 0.292600, 0.860490,
0.955650, 2.647530, 0.258610, 0.381420, 0.897750, 0.426230, 0.619140, -0.756970, 2.075330, 1.329000,
-2.036280, -0.527330, 1.481370, 1.082070, -1.709790, -0.730730, 0.087400, -0.192130, -0.747230, 0.269010,
-0.603350, -0.327700, -0.028010, -0.580920, -0.432360, -1.314360, -0.125210, -0.450960, -0.239560, -1.227290,
0.127100, -0.155490, 0.735920, -1.224970, -3.997690, -0.307270, -0.134090, -0.247690, 0.496050, 0.319940,
1.539500, -1.769240, 1.669550, 0.330540, 1.936960, 0.180540, -0.632110, -3.156250, 0.879610, 0.132620,
0.355550, 0.233330, -0.822220, -0.329340, 0.471880, 0.722720, 0.535110, 1.094150, 1.178510, -2.168280,
-2.374250, -0.465020, -0.702510, 1.720500, 2.096980, 0.214390, -0.196930, 1.891650, -1.041070, -0.043150,
-0.907110, -0.349560, 1.569250, 0.679100, -0.599320, 0.289020, -0.830160, 0.223860, 0.402200, 0.111070,
0.700540, 1.345600, 0.374230, -1.138340, 0.993580, 1.977730, -0.298680, -0.011190, -0.658200, 0.006370,
1.456390, 0.838660, -1.001600, -2.437420, -1.040040, -0.246430, -1.556150, -1.825030, -0.182530, -1.688470,
-1.599620, -0.335960, 0.569320, 1.186460, 1.673290, -0.032780, -0.242320, 2.168270, 1.933560, 3.652680,
0.598260, -1.666810, -1.343890, 3.294910, 6.725390, 0.990360, 1.334780, -1.336790, -0.605340, -1.288880,
-0.036880, -0.673920, -0.410110, -0.413570, 0.314140, -0.516120, -1.294390, -0.014100, 0.056370, -0.665750,
-4.236730, -2.157250, -0.375000, -0.659620, -0.242880, -1.365250, -0.099550, -1.267140, -0.862840, -0.674070,
-0.046090, -2.131840, -0.255010, -0.472380, 0.446250, -1.159840, -0.602020, -0.521310,
-0.328020, -2.181830, -0.052240, 0.109130, 0.950250, 0.428490, 1.291880, -0.495280, 0.334510, 1.808140,
-2.489350, 0.619440, -0.271700, 0.236890, -1.075220, 0.745310, -0.357050, -2.521840, 0.687350, 0.134800,
0.435740, 0.063540, 0.225610, -1.011930, -1.673580, -1.405370, -0.288940, 0.845230, -0.974620, 0.121210,
0.159440, -2.079980, 0.082950, 0.351590, 0.176930, -0.252890, -1.209490, -1.961590, 0.301860, -0.550470,
-3.244130, 1.344280, 0.609020, -0.324310, -1.505450, -1.470520, 0.831900, 0.450990, -0.214750, -0.400880,
0.283760, -1.327100, 0.724600, 0.184520, 0.009910, -0.913970, 1.126920, 0.820620, -0.830070, -2.168300,
1.779430, -1.109640, -0.691580, -0.019680, 0.463970, 0.860080, -1.051110, -1.248920, -0.766480, 0.359730,
-0.183570, -0.108780, -1.021200, -0.011290, 1.346800, -0.176190, 0.763380, 2.432780, 0.936300, 0.484060,
-1.414860, 0.469070, 0.952360, -0.682990, -0.501730, -1.771720, -0.566340, 0.490510, 1.834280, 0.733090,
0.565250, -1.911830, 0.670270, 2.140900, -1.454580, 0.967080, -1.317590, -0.846150, -0.348900, 0.904670,
1.315960, -0.207970, -8.785890, 0.447750, -0.239160, -0.405560, -1.843130, -0.794710, 3.216510, -1.903720,
-0.556940, 0.221770, 0.576570, 1.906440, -0.601280, 1.160160, 2.478700, -2.327830, -1.468830, -0.642210,
1.343300, -0.734280, -0.498070, 0.083230, -0.782060, -2.162550, 0.298670, 0.003730, -0.306190, -2.265470,
-2.013540, 0.406620, 0.164030, 0.580150, 0.626680, 0.284490, -0.732680, -0.611460, 0.576900, 0.474150,
-1.811800, 2.755910, 2.132160, -0.882300, 0.948160, -1.702180, -0.476370, 2.866790, -2.833150, -0.606460,
-0.221690, -2.455650, -0.788500, -1.873860, -0.623960, 1.888110, 1.362700, 0.834540, 1.327680, -0.048610,
-0.145970, 1.876160, -1.942160, 3.851440, 2.750570, -1.235330, 1.529310, -1.202700, 0.210910, -0.068280,
2.026480, -1.342550, -0.058990, 0.788890, -2.545090, 1.994840, -0.376650, -0.476950, -1.182640, -0.938140,
1.590370, -0.539830, -0.220250, 0.968990, -0.055660, -5.413980, 0.289340, 3.113780, 0.017970, -0.740420,
0.774110, -0.015400, -0.962650, 0.230180, -1.081520, 2.895280, 0.547440, -2.537220, -0.241090, 1.861600,
1.101120, 0.114650, 3.516670, 1.608620, 0.043560, -0.427480, 0.097530, 0.911230, -4.436670, 0.353780,
4.967360, 1.583380, -1.850130, 0.459850, -1.104600, -1.920400, -0.082880, -0.285800, 0.651310, 0.606640,
-0.526780, -0.101250, -1.082610, -0.155810, -2.916040, 2.133160, 0.931920, -0.574530, -1.681350, 1.462320,
-1.462230, -4.179620, 1.250640, 1.822530, -3.128010, -1.402140, 3.047600, -1.658530, -1.369010, -0.531300,
-2.651850, -0.061270, -2.552670, 0.277580, -0.760950, 0.236100, 0.256890, -0.242450, 2.107000, -0.127610,
0.241500, -1.712830, 2.181510, 0.688350, 1.280420, -0.252820, 0.828510, 0.412290, -1.579370, 2.102170,
-0.602630, 0.020950, -1.531070, -0.915150, 0.462020, 1.333600, 2.165160, 2.261020, -1.246810, 0.339890,
0.894150, -0.242920, -1.285030, -1.718730, -0.854260, -0.180080, -2.837420, 0.028250, 0.027710, -0.711410,
0.665210, -0.144090, -1.028510, 0.654240, -0.322720, -0.590540, 2.411020, 0.436190, -1.297930, -0.911100,
0.301650, -0.624850, -0.030530, 0.173280, -0.294230, 1.697610, -0.197200, -0.364960,
-0.133420, -1.514160, 1.068420, -1.044540, -0.134150, -0.122000, 0.685790, 0.233640, -0.151950, 0.399250,
0.239860, -2.301590, 1.652290, 0.903190, 0.483250, -1.412310, -0.200510, -0.183880, 1.351580, 0.811680,
0.237670, 0.365940, 0.105540, -0.725190, 0.583070, -1.877110, -0.054750, 0.291760, 0.918330, -0.149790,
-0.488900, -0.446130, -1.035820, 0.327750, 0.789420, -0.224500, 0.301630, -0.540440, 0.359030, -0.813650,
0.355420, 0.519040, 0.224020, 0.143190, -0.646630, -0.738740, -0.166200, 1.717410, 1.083590, -0.180750,
-1.114280, 0.797300, 0.013450, -1.945770, -0.067500, -1.526920, 0.971650, 1.010500, 2.487160, 0.414050,
0.196350, -0.169240, -0.460260, 1.545100, 1.046980, -1.545170, -0.040870, -0.665580, -0.603490, 0.758300,
0.462250, -0.497550, -0.385260, 1.086340, 0.278490, -1.378950, 0.191090, -0.311290, -2.469350, -1.703750,
-0.135050, -0.412110, 0.151440, 0.154410, -0.214970, -0.754840, 0.383370, -0.672170, -0.687210, 0.584930,
0.175590, -1.881580, 1.378900, -0.422280, 0.342270, 0.712140, -0.800750, -0.527110, 1.283440, 0.402680,
-2.205580, 0.157210, -1.412180, 0.341340, -0.151380, 0.517500, -0.588020, 0.014600, -0.901430, 1.262550,
0.028350, -0.988050, 0.040680, 0.477180, -0.011550, -1.512660, -2.435600, -0.547910, -0.080530, -0.931130,
-0.196430, 0.606890, 0.255230, -3.425600, -1.191920, 0.701340, 0.826450, 0.412580, 1.780060, -1.028860,
0.161360, -0.021580, 0.168350, -1.763450, 1.829140, 0.871770, -0.703380, -0.564630, -1.542630, -0.835650,
-1.013360, -2.442610, -1.721640, 1.002770, 1.693600, 1.213620, 0.592000, -3.128850, 0.883660, 1.021240,
0.051430, 1.720020, -0.357500, 0.162280, -1.313250, -0.223550, -1.411010, 0.722110, 0.126680, 1.129500,
-1.610390, -0.222740, 4.317650, -0.525590, -5.433050, -1.097510, 3.573860, 1.006430, 0.853080, -2.086760,
-4.635620, 3.067860, 0.043810, 0.026970, 0.267900, -0.824920, 0.662790, -0.081130, -0.040390, -0.874730,
-0.950870, -2.182790, -0.122480, -2.052300, -1.046650, 1.967860, -2.123790, -1.788540, -0.374520, 0.394880,
-0.699980, 0.064980, 1.212090, -2.006480, 1.788470, 0.826290, 0.109850, -0.581360, 2.275290, -1.565110,
-0.293490, -0.264230, -0.901160, -0.250390, -0.910510, -0.202230, -1.479200, -2.418200, 3.054290, -0.897540,
-3.175180, -0.126180, 1.148630, -0.248660, -0.206360, -0.707360, -0.652180, 1.039400, 0.046610, 1.701220,
-0.170760, -1.065350, 0.205000, 0.477730, -0.247380, -0.747530, 0.011160, -0.877390, 0.237410, -2.543110,
-1.671220, 0.603000, -1.321290, -1.906920, -0.819980, -0.068890, -0.691500, 0.391370, -0.625490, -0.340820,
2.638100, 2.459680, 0.035890, 0.513400, 2.405840, -0.511330, -0.441910, -0.825090, -2.303320, 0.055360,
-1.475930, -0.480390, -1.616980, 1.259660, 0.905530, -0.443180, 0.727630, 0.481290, -0.393440, -1.681230,
-1.666530, -0.729730, -0.060110, 4.513570, -0.700760, -2.158010, 0.224160, -0.705990, 0.899500, 0.002420,
-0.021820, -0.098180, 1.839720, 6.770950, 0.235320, 0.588370, -3.124420, 1.384300, 0.880150, -0.588450,
-3.629230, -0.516400, 1.561720, -0.486400, -0.347810, -1.154930, 1.837240, -0.893350, 3.382420, 0.986020,
0.400080, -0.046810, -0.773950, -1.132440, 0.937160, -0.297150, 0.757160, 0.521580,
-0.941510, -1.465830, 1.222110, 1.674230, -1.418110, -2.188840, 1.270590, 0.335650, 0.109490, 1.047720,
-0.072770, -0.965690, -0.303460, 1.369330, -0.417630, 0.890900, 0.837060, -0.284620, 1.070330, 0.703880,
-0.269830, 0.119110, -0.940930, -2.565030, 0.309880, -1.254880, 2.290870, -1.848630, 0.121610, 0.045970,
-1.041610, 0.599700, 0.749840, -2.414770, 0.181230, 0.781880, -1.140170, -1.184190, 1.218600, 1.253850,
-0.088570, -0.023230, 1.003290, -0.646290, -0.293570, 1.133900, 1.194600, 0.066090, 1.916990, 4.974900,
-0.137440, 1.606740, -0.992310, 0.231870, 2.340280, 1.751360, -0.671930, 0.914210, 0.008120, -2.134830,
-1.951380, 1.207240, -0.716430, -1.665690, 3.991520, -0.246320, 0.518350, -0.225640, 0.050460, 0.832330,
2.892240, -1.112200, 1.818470, 0.430680, 0.019810, -0.848200, -0.982050, 3.187270, 1.762890, -2.516490,
-0.908460, -2.308560, -0.789370, 0.851030, -0.891560, -0.331330, 1.616810, 4.117980, -0.889660, -1.394360,
1.048130, 0.449630, 0.518660, 0.949700, 1.473330, 0.877410, 0.254330, -1.293090, -0.429370, -0.549220,
0.147060, -0.513090, -5.235830, 0.230280, 1.582480, 0.259610, 0.057330, -3.133120, -0.776760, 0.678400,
1.033940, -1.410510, 0.510630, -0.759230, 0.414200, 1.030630, -1.225050, 1.879520, 0.701840, 0.577320,
-0.132450, 1.131350, 0.042240, 0.358940, 1.673460, -2.732810, -0.581290, 1.593730, 1.795170, 0.053910,
-0.895320, -0.285920, 1.573480, -0.709660, -0.587970, 1.582740, 0.257600, -1.320200, 0.135870, -3.549950,
3.142830, 2.579930, -1.003950, -0.657640, 1.408020, -0.980650, -4.781030, 0.513390, -0.749530, 0.386820,
0.610290, -1.099640, -0.515480, -0.588850, 0.419760, 1.488770, 0.739080, -0.409430, 0.445310, -0.047110,
-0.421850, 0.365750, -1.021010, 0.162670, 1.275030, 2.472220, -0.190060, 0.825270, -1.414950, -1.993430,
1.315420, 0.962610, 0.456840, 0.088710, 2.244150, 0.311580, -0.570540, 0.990090, -1.905990, 0.904720,
0.609570, -0.453410, 0.028670, 0.673120, -0.964850, 3.544630, 1.586960, -0.732080, -0.876600, -0.827220,
0.875420, 0.525660, -1.831520, 1.415970, 1.346570, -0.171630, -0.325860, -0.557270, -0.635580, 1.284710,
1.475800, 0.421680, 1.183730, 0.073770, 0.141110, -0.104140, -2.589690, -0.287100, 0.246390, -1.199660,
0.690670, 0.565160, 0.672850, 0.380190, -0.557370, -0.851580, -0.466650, 0.764230, 0.677220, -1.242710,
0.467280, 1.295180, -0.598310, 0.387340, -0.139030, -0.018870, -0.507010, -0.152990, -0.582510, 0.724260,
-1.207510, 1.661790, 0.388310, 0.700990, -0.602100, -1.052970, 0.443370, -0.420620, 0.546030, 0.864390,
1.253480, 1.396410, -1.131170, -0.975210, -0.013610, 2.205840, -0.157090, 0.002260, 0.077940, 1.348040,
1.157420, -0.043010, -0.478710, -0.848040, 2.557490, 0.600380, 0.537370, 2.213480, -1.812960, -0.193150,
-0.905990, -0.265050, 0.703220, 0.688630, -1.852930, -0.183110, -1.534770, -0.132910, 0.985560, 0.199200,
-0.361690, 1.189700, -0.613650, -6.520240, 1.245280, 0.993320, 6.161190, 0.391780, -0.182020, 0.317510,
0.800280, -0.206330, -0.404290, 6.047680, 1.108530, 1.546300, 0.619300, 0.428280, -0.001430, 1.160510,
-0.594970, 0.936540, 1.125350, 2.299640, -0.463420, 1.063560, 0.007790, 0.579990,
0.254800, -0.202010, -0.466500, 1.861470, -0.603220, -1.165810, -0.379240, 1.095910, -0.650410, 0.026410,
2.291890, 1.008960, -0.415880, -1.451430, -0.465090, 0.037350, 1.365390, 0.435120, -0.366630, 0.137860,
-1.425710, 1.275940, 0.801660, 1.665440, 0.265360, -0.135410, 0.167400, -0.063930, 0.773180, 1.239980,
0.267330, -1.482300, 0.378170, -3.695520, 1.151410, -3.062700, -2.429160, 0.523380, -0.951360, 1.846960,
0.726110, 1.421960, -0.326530, -0.000350, -0.733300, 0.127250, 1.854440, -2.471900, 0.319920, -0.839330,
-0.946320, -0.605050, -0.162620, -0.925360, -0.575630, 0.358180, -3.359200, -1.375720, -0.352480, 1.986430,
-0.538510, 0.077120, -0.861820, 3.437150, -1.217250, 1.319170, -0.526730, -1.568200, -1.124940, 1.929410,
1.737690, 0.202860, -1.146730, -0.100340, 0.378960, 0.294100, -1.052970, -0.492590, 0.388240, -3.846580,
1.344380, -1.316040, 4.983230, 3.010430, 0.212340, -2.108970, -0.935330, -0.365970, -1.285970, -0.704680,
-0.429760, -2.434090, 0.915260, 6.458420, -1.030680, -0.965950, 1.598990, -0.715650, -0.063670, -0.145260,
1.757210, 0.363190, -0.958670, -0.364790, 0.411260, 1.510070, 1.781290, -0.233130, -4.615680, 0.266960,
0.854770, -0.019690, 0.834350, 0.813530, -2.832980, 1.729850, 4.094240, 0.947690, -0.344230, 1.420960,
0.593400, 1.542850, -3.362080, 0.967850, -0.740760, 1.710630, 1.458950, -0.508040, 1.635870, 0.957120,
0.781300, -0.027630, 2.076120, -2.214510, -3.621310, -0.654800, -0.735430, -0.467500, 0.667280, -1.341990,
-1.149260, -0.783290, -0.030330, 2.989990, -1.258760, 1.673530, 0.157580, -3.296890, 1.106220, 0.089990,
-1.877490, 0.453740, -0.377300, -0.140690, 1.092620, 1.553790, -1.493970, -1.519530, -0.232260, 0.471150,
-0.902950, -1.644910, -3.219510, -2.204710, -6.499670, 1.909070, -1.861840, 1.176470, 0.554830, -1.342500,
-1.987460, -0.759710, -0.172780, 0.316280, 1.827560, 1.422750, 0.459570, -0.030730, -0.522890, -0.138250,
-0.539930, -0.921180, -0.643330, -1.794030, -1.038750, 5.712310, 0.234270, -2.578970, 1.333790, 0.654780,
0.642930, -0.491730, 1.825260, -0.291390, 0.582730, 1.692990, -2.087720, 1.287100, 1.416910, 0.970870,
2.159610, 0.248270, -0.293090, -1.803610, -0.050400, -0.229700, -0.944870, -0.280370, 5.277620, -1.093100,
-1.505960, -0.434620, -0.143020, 0.137510, -0.844680, -0.068440, 0.475000, -0.926060, 0.725270, -0.243710,
-0.934870, -0.001750, 1.247400, -0.668560, 0.237610, 0.820510, -0.478450, -0.285930, -1.562740, -0.060410,
0.735570, 2.224240, -0.883620, -1.631500, 0.032710, -1.133190, -1.302400, -0.434560, -0.015330, -0.236150,
1.322300, -0.845850, 0.242070, -0.618250, -0.963030, 0.746190, -0.820340, -2.709740, -1.234480, 1.195210,
-1.309420, 1.375740, -1.266450, -0.050750, 3.406850, 1.212900, 0.142380, -0.359760, 3.550390, 0.398660,
0.013490, 1.371890, 0.587950, 4.260110, 3.496430, 2.426450, -1.253550, -4.690360, 1.036470, -0.415710,
0.202650, -0.442900, -0.409410, 1.098300, -0.475290, 0.715130, -3.228240, 0.182670, -0.320600, -0.146360,
-2.281300, -0.014780, 0.866670, 0.270640, 0.620760, 0.083350, 2.993260, 0.983470, 1.051910, -0.045040,
1.677120, -3.029480, 0.729430, -1.498360, 0.773680, 0.387800, 1.399040, 0.506590,
0.409740, 1.226110, -0.283310, -0.206300, -0.107340, -1.904080, 0.600000, 1.541200, -0.098930, 0.247920,
-1.894090, -0.648350, 1.388370, -0.537810, 0.016240, 0.044530, -0.928830, -1.739310, 2.200240, -1.253100,
-0.619910, 0.886740, -0.995770, -0.338980, 0.241920, -1.151420, 0.691120, -0.863430, 1.250040, -0.589660,
1.057380, 0.554190, -1.913670, 0.275270, -0.149520, -0.779430, 0.613860, 0.308280, 1.161500, 0.343840,
0.538480, 1.755440, 1.105450, 0.106350, 3.806060, 0.875450, 0.124300, 0.473690, -0.043390, -0.111450,
0.896920, -1.273780, -0.877210, -0.617600, 1.051000, -3.142890, -0.706950, -0.871000, -0.105620, -0.864660,
-0.591880, -0.907180, -0.181220, -1.048350, 1.879720, -1.122910, 0.772900, 1.882030, 1.422660, -0.629820,
-2.212220, 0.643880, 0.000650, 0.438190, 0.921390, -0.255900, 2.217060, 0.642560, 0.812100, -0.057510,
0.091090, 0.033500, 0.279970, 0.419840, -1.979830, 1.041600, 0.682940, 0.271130, 1.108290, 0.827710,
1.119450, 1.750450, -2.497720, -4.559880, 1.354540, 4.290400, 1.718140, 0.002270, 0.716180, -0.064120,
-2.275200, 2.952970, 6.891550, 1.639010, 0.169460, 0.520170, -2.219330, -0.391190, 3.772980, 1.383290,
-0.203400, 0.672700, 0.341940, 0.883440, 3.108880, -2.127940, -3.782020, -0.475620, 2.254520, 1.447600,
-3.517020, 1.025790, 0.523310, -8.345300, 2.359840, 5.525400, 0.533110, 0.506030, 0.117210, -0.898240,
1.572960, 5.566090, -0.325250, -0.063270, -0.263610, -0.064850, 0.826300, 2.027620, 0.462640, -2.094440,
0.150970, -0.730990, -0.301360, 1.200330, 0.119030, 0.833910, -1.920750, 1.557900, 1.784520, -0.138040,
2.366950, -3.849690, -1.607510, 1.816380, 1.259610, 1.388190, 1.719170, -2.524260, 0.509100, -0.271290,
2.387350, 0.906390, -0.847820, -2.008720, 2.313610, 0.085830, 1.221580, -0.388050, -1.303990, 1.033170,
-1.225370, -0.843940, -0.446340, 0.230300, -1.601220, 0.605560, 1.118800, 1.504930, 0.815320, 2.703330,
0.729600, -0.541710, -0.311340, 2.565330, -0.027940, -2.139750, -0.049240, -0.240390, 0.059740, -0.528300,
2.311240, -0.427940, -0.500160, -1.321720, -0.622140, -0.242840, 0.608820, 3.784960, 0.042240, 2.349450,
0.651060, 0.451480, 1.863110, -0.328260, -0.595410, 0.957450, 1.181030, -0.742160, -0.397850, -0.060950,
0.808490, 0.289770, -0.638390, -0.549990, -2.343620, 0.177010, -1.402470, -1.186720, 0.532260, 0.341890,
-0.447000, -0.188980, -0.129470, 0.250260, -1.634260, 0.433000, 0.957500, -0.354420, 0.091120, 0.721450,
1.669600, -1.435630, -0.579970, -0.054390, -0.592880, -0.002090, 0.424420, 1.133140, -0.120680, -0.619820,
-2.550880, -1.081440, 1.469270, 2.091200, 0.688880, 0.209980, -0.369930, 0.209440, -1.126180, 0.555310,
0.299120, -0.719890, 0.628070, -0.714320, 0.090860, 0.150980, 0.849730, 1.701980, -0.329220, -2.178570,
-0.367090, 1.337810, -0.321360, -1.421520, -0.530740, 1.831250, -1.964370, -0.170200, 0.176500, -2.679350,
-0.470070, -2.017390, -2.425460, 0.540480, 0.580590, 0.193250, 1.518870, -1.779840, -0.625540, -2.818680,
-1.306350, 1.022530, -2.384830, -2.506980, -0.204230, 0.344710, -3.940520, 0.539670, -3.250920, -0.194540,
-0.202660, -0.185940, -0.737040, -0.712000, -0.395600, 0.576140, -2.669350, -0.616240,
1.545950, -0.677770, -1.696620, 1.218000, 0.866550, 0.229030, 1.154320, 0.245260, 0.090780, -1.669200,
-0.719490, 0.303280, -0.055960, 0.543010, -0.693820, -0.292570, 0.476900, -1.005350, -0.869890, 1.587870,
-0.457780, 0.581960, 0.037250, -0.772420, -0.376520, -1.451040, 0.496930, -1.527230, 0.507390, 0.239660,
-0.196290, -0.085780, -0.645990, 1.032010, -1.773980, 0.579400, 0.081510, 1.375390, -1.062870, 0.400790,
-1.478320, 0.912870, 0.061830, -0.721070, -1.484080, 0.365450, 1.245170, 1.387150, 1.051570, -0.001780,
-1.244790, 1.058010, -1.027890, -0.453850, 0.435370, -0.717290, 0.964670, 0.085080, 0.504400, 0.569960,
0.583900, -0.112930, -1.173480, 0.209430, 0.580790, 0.777200, -2.336100, 0.240590, -0.127690, -0.739850,
0.509320, -1.426560, -0.017490, -1.109780, 0.509020, -0.397620, 0.456580, -0.233050, 1.260360, -0.826870,
-0.045950, -0.499820, 1.280600, 0.169520, 1.934070, 0.834490, 0.388170, 2.286550, -1.382900, -0.497540,
-0.126240, 0.737120, 0.584110, -0.090140, 0.549400, 0.469680, -0.326570, -0.140670, -1.255720, 1.148690,
0.457180, -0.542300, -0.294950, -0.150830, 0.661960, 0.286980, -0.689040, -0.327460, -0.081170, -0.301890,
1.641420, 1.521260, 0.261720, -0.584660, -0.588780, 0.734490, -1.977100, -1.058170, -2.386110, -0.513000,
0.504430, -1.059640, 1.417430, 0.522530, -0.259520, -1.674730, -0.482400, -2.332730, -0.631010, -0.004740,
-0.358850, -1.749190, -0.045530, -0.134800, 0.805750, -0.385220, -0.977350, -0.490080, -1.179970, -0.709030,
0.846820, -0.042560, -1.316270, -0.382890, -0.674040, 1.126960, -1.250520, -0.840960, 0.874000, 1.672720,
-1.104230, -0.898830, -0.550380, 2.404390, 0.443620, 0.156600, -0.078730, 0.609900, -0.245090, 0.125630,
0.414160, -0.633240, -2.476560, 0.375190, 1.257270, 1.178110, -3.401710, 2.168090, 2.243030, -0.665670,
0.153410, -1.846300, 1.521160, 1.079230, -1.598640, -2.257240, 0.217050, 0.227910, 2.601240, -1.062470,
0.169150, -0.334020, -0.087070, -0.961180, -0.075830, 0.294900, -0.993030, 4.675770, 0.683470, -0.637360,
1.745370, -0.566050, -1.026860, 1.964820, -0.509680, -0.322680, 0.159340, -1.562010, -0.246230, -0.625360,
2.642880, -0.763890, 0.945850, 1.052520, -0.867930, -1.680210, 0.295290, -2.596000, -4.018310, 1.329680,
0.932030, 0.624290, 0.765770, -1.098550, 2.305060, 0.427710, 0.466880, -2.346700, 0.941600, -0.310620,
-1.805800, -0.507900, -0.090830, 1.863000, -0.623380, 1.600290, 0.008130, -0.147620, 0.255080, -1.445940,
0.251330, -3.603450, 1.724780, 2.087110, -0.699360, -0.296140, -1.604620, -0.113060, -4.940540, 0.144950,
-1.864470, -2.160510, -0.510050, -0.938480, 0.115360, 1.711520, 0.143210, 0.299210, 1.483900, 2.397370,
-1.390870, 1.518020, -0.462630, 1.891590, 0.265920, 0.417970, 0.036600, 0.377590, 2.863200, 1.187440,
-1.814230, 1.095140, -0.435740, 0.735750, 0.195780, -0.064330, -0.074840, -1.304090, -0.506280, 0.377680,
-0.416400, 0.105910, -1.260770, -6.428860, 0.240470, -0.999020, 0.300280, -1.243630, -0.819790, 0.365710,
1.086000, 0.689520, -1.488720, -0.037280, -0.786590, -0.671170, -1.387350, -0.134520, -1.067220, 0.349570,
-1.751810, -0.232890, 0.533480, 0.399500, -0.796440, 0.313730, -2.369160, 0.403830,
0.076850, 0.083970, 0.692940, -0.951100, 0.017210, -0.215780, 0.090470, 0.045740, -1.232480, -0.093620,
-0.296890, 0.301610, -0.517380, 2.353950, 0.498560, 0.797190, 1.190910, -1.552070, 0.116360, 0.427450,
-0.107970, 0.545840, -0.266740, -0.224550, -0.337990, 0.303460, -0.407620, 1.138440, -0.319500, 0.238280,
-2.267640, -0.510930, 0.211590, 0.791720, -0.188090, 0.035560, 0.122320, 2.229930, -0.656680, 2.208950,
-0.570890, -1.175470, -0.116380, -0.671180, 0.448220, -1.386130, 0.565480, 0.912410, -0.142290, -0.816450,
0.125630, 0.343750, -1.073400, -0.725150, 0.223540, 0.375070, -0.036010, 0.172850, 0.464760, 0.902250,
-1.552310, 2.912590, -0.363980, -0.024770, -1.540590, 0.491880, -0.329520, -0.142460, -0.893160, -1.345780,
-0.765390, -1.979000, 0.123080, -1.451410, 2.303190, 0.111980, -1.297300, 1.081420, -3.020000, -1.534110,
0.253290, -0.935970, 0.526970, 0.925400, 0.820190, -0.781980, -1.941850, 0.782640, 0.454130, 0.320680,
0.239300, -1.979650, 0.744230, 1.180530, -1.050680, -0.762620, 0.566930, -0.667440, -0.340610, 0.159160,
-1.661260, -0.443740, -0.122310, -0.805700, 0.213020, -0.042740, -0.568600, -0.325090, 0.281700, -0.067440,
1.365200, -0.085010, 0.537910, -0.034390, -0.099590, 0.907810, 2.396460, 0.506070, 3.169640, -0.179680,
1.300110, 0.834770, -1.069310, 0.662300, 1.492830, -0.464140, -1.948070, 1.022250, -0.194320, -0.557430,
0.890790, -0.015960, 0.108320, -2.919150, 1.074940, 0.392800, -1.924110, -1.282290, 0.888670, 0.106650,
0.898700, 1.876040, 0.253080, -0.296870, 0.363470, 1.211310, 0.343230, 0.464640, -3.511510, 0.993980,
-0.794780, -2.041300, -0.588300, 0.272360, -0.900370, -1.540570, -0.704270, -0.248510, 0.797100, -0.663960,
-0.715290, 0.282960, 0.208670, -0.267100, 0.862900, -2.597010, -1.003930, 1.519250, 0.261220, -1.361170,
-4.298160, -0.950570, -0.066300, 1.025340, 0.741250, 0.176640, 1.382440, 0.612380, -1.069860, 1.251020,
0.994860, -1.186830, 0.805410, -0.765020, 0.255220, 0.602270, 0.986340, -1.720340, -1.089640, -0.693240,
-0.989980, -0.525830, -0.805780, -0.064410, -1.863540, 0.329080, 0.494600, -0.359170, -0.011490, -1.386120,
-1.642840, -0.550300, 2.027150, -0.221010, -0.441450, 0.117480, -0.593220, 0.826220, 1.651920, 1.057260,
0.252140, -0.046860, -2.459060, -0.457650, 1.993010, 0.548960, 0.418920, -1.014920, 1.193610, 1.022770,
0.920460, 1.620360, -0.209610, -0.240040, 0.862430, -1.208230, -0.322800, 0.848950, 0.666040, -4.757210,
-1.061170, -1.008020, 0.745990, 0.906760, -1.599320, 0.255740, -0.116770, -0.653420, 0.230680, -0.586070,
-1.705280, -0.109120, 1.479010, -1.456080, 1.349610, 0.510630, 0.889240, -0.990810, 1.882140, 1.105700,
-0.154290, -0.345010, 0.424690, 1.507260, 1.912570, -0.345460, -0.931670, 0.837980, -0.668580, -1.457870,
0.780680, -1.374360, 0.414710, 0.062360, -0.051540, -0.101160, 2.221520, -0.559190, -0.132020, -1.413320,
-0.243430, -2.235660, -2.078340, -8.225340, -0.660880, 0.348710, -1.038340, -0.711880, -1.688320, -0.800410,
0.489810, -0.453430, -1.302270, -0.324680, -0.193120, 1.058120, -2.278600, 0.311170, -3.410610, 0.522830,
-1.669270, 0.308370, -0.254340, -0.803360, 0.209600, -1.359800, -3.199550, 0.155890,
-0.246190, 1.404580, -0.987330, 0.455180, -0.567190, -0.061800, 0.456880, -1.340070, -0.613170, 1.023090,
0.350840, 0.604620, -0.178230, 0.692990, -0.281750, -1.422700, 1.878540, 0.168170, 0.525020, 0.060100,
-0.082870, -0.038970, 0.198600, -0.714680, -0.663530, 0.389780, 1.810440, -0.023890, -1.280360, 0.432080,
-0.265060, -0.447880, 0.298870, 0.879750, -0.302890, 0.872080, 0.648260, -0.454180, 1.395900, 0.957510,
-0.392300, -0.752620, 0.094640, 0.262920, 0.179270, -0.790500, -1.826890, 0.353770, 0.629870, 0.449320,
0.238550, -0.076990, 0.413080, 0.093010, -1.285670, -0.289800, 0.688070, -0.723640, 0.517910, 1.091890,
-0.233410, 0.761060, -1.120900, -1.534550, 0.102090, 0.850980, 0.085490, -0.058260, -0.877520, -1.716750,
-0.591890, -0.626690, -1.603320, -0.970500, 0.533490, -0.265050, -0.724490, -5.533990, 0.214620, 0.223680,
-0.356880, -0.804880, -0.791710, -2.055000, 0.804340, -0.520620, 0.220410, 0.340200, 0.381510, -0.158220,
-0.936940, 0.235600, -0.458980, -0.692050, 0.523740, -3.348320, 0.651110, 1.859510, 0.657850, 0.096640,
-1.391480, -0.913370, 0.471190, 0.316530, 0.066850, -0.214500, 1.285950, -0.267140, 0.336030, -1.064670,
-1.458690, -1.026510, -0.690220, 0.111820, -1.491100, 1.043460, 2.754690, -1.192350, -0.180860, -0.608760,
2.134690, 0.203590, 0.080360, 1.831880, -1.189230, -1.911470, 1.345370, 0.823670, -0.091420, 0.909460,
-0.206990, -0.817510, -0.806210, -2.323210, 0.087780, -0.700570, -0.724450, -2.046560, 0.210270, 2.915840,
-0.007060, -0.744340, -0.962710, 1.204120, -0.822080, 0.515770, 2.009250, -1.271640, -2.658800, -0.766700,
-0.702970, 1.062410, -0.385080, 0.207060, -1.783630, -1.044300, -0.240780, -0.423310, 0.264040, -0.100750,
-1.057750, -1.082980, 6.810840, 0.989580, 0.713360, -0.015600, 1.464260, -1.988680, 0.145260, 5.215470,
-0.472960, -1.964210, -0.951910, 0.392810, 1.243790, 0.459910, -0.340380, -3.522090, 0.351470, 1.232990,
0.378870, -0.471400, -2.142740, -1.725060, -2.574810, 1.795660, 0.335510, 0.082980, -0.019940, 0.268870,
-0.235560, -0.103460, 1.825610, 0.004390, -0.430960, -0.840710, -0.057660, 0.592840, 0.624410, -1.182170,
-0.282850, 0.231660, 0.274170, -0.166960, -0.534570, -0.879160, -0.085370, 0.631340, 0.306260, 0.864200,
0.739120, 0.007780, 0.840360, -1.182980, -1.445930, -0.597270, -0.875160, -1.513600, -0.025140, 0.197130,
0.184470, -0.387830, 0.283730, -0.186070, 0.316040, 2.682390, -0.303590, -0.248470, -1.082940, -1.092930,
-0.949270, 0.233100, 1.618450, 1.260500, -0.831400, -0.295410, -0.102870, 0.390420, -0.439360, -0.668230,
0.251700, -0.911180, 0.400190, 0.923620, 1.214650, 0.923470, -0.359190, -0.355910, -0.093840, -2.554290,
-0.958480, -0.648500, -0.806910, -0.803300, -0.659940, -0.284530, -0.238010, 0.258630, 0.156310, 0.742040,
0.012380, 0.700280, -0.456820, 0.391670, 4.879000, 0.150700, -1.359170, -0.756910, -1.573450, 0.521490,
0.545570, 1.005930, 1.480450, -1.189680, -0.458930, 0.298430, 0.576160, 0.151300, 1.685000, -0.303650,
-3.614040, -0.102180, 0.168830, -1.814230, -0.848820, -1.246490, 0.636410, 0.762940, 0.512890, 0.133220,
2.864900, -4.176110, -0.037800, -2.464350, 0.403270, 0.553870, 0.080390, 1.361860,
-1.860670, -1.367090, 0.094400, 0.939840, -0.069430, -1.128280, 0.121200, -0.047480, 0.113210, -0.597380,
2.857450, -0.631480, -1.001250, 2.633620, 1.290540, -0.600360, 0.524690, 0.013680, -0.081000, 0.969030,
0.224100, -3.315420, 0.325200, -0.615560, 0.760660, -1.475270, 0.487990, -0.214490, 0.249020, -1.404760,
-1.144190, -0.337040, 0.823680, -1.479660, 1.058290, -2.809380, -0.993720, 0.814800, -0.733350, -0.191160,
0.003770, 0.645010, -0.904080, -0.859690, -0.932800, -0.168030, -1.925330, -0.841260, 0.453740, -1.112100,
-1.547490, 0.532750, -0.111130, -1.237420, -2.283300, 1.154440, -0.026450, -0.679040, 1.229120, -1.183740,
0.288390, 0.250230, 2.060330, 0.903650, 0.110350, -3.181530, 0.569460, -0.895580, -0.822330, 0.204300,
0.705580, -0.554060, 1.445720, 0.123040, 1.162550, -1.734910, -0.827630, -0.122440, -0.151460, -5.771200,
0.602770, -0.520570, -3.334220, -0.835420, -0.245530, 0.293190, -1.151980, 1.474850, 1.718810, 0.348170,
0.171980, 0.540550, 0.493870, 0.701310, -1.919720, -0.433510, -0.461650, 0.916720, -0.489690, -0.327180,
0.639320, 0.903920, -0.573540, -1.442130, -0.135770, -2.718730, -1.582820, 0.213850, -3.254210, -1.619220,
3.050680, 2.251620, 0.291520, -0.747440, 1.342290, 0.308690, 0.932550, -2.284460, 0.354630, -0.493010,
0.199810, -2.306170, 0.942180, 0.774610, 1.271170, -2.948240, -1.237890, -0.156450, -2.118900, -0.753110,
0.262070, 0.087830, -0.376120, 1.178390, 0.712360, -1.326340, 0.391850, -0.080290, -0.218730, -0.790560,
0.606160, 2.197280, 0.892500, -0.491040, -1.329420, 2.575940, -1.173250, 1.067280, -4.990740, -0.014980,
-1.569560, 0.351290, -2.601430, 0.288740, -1.224230, -1.480610, 1.800340, 0.823880, 0.582740, 0.361530,
0.581580, -0.368250, -0.980140, 2.641460, 2.703790, -0.198510, 0.241550, -1.213160, -0.889130, 1.434880,
1.251490, -9.189590, 0.889240, -0.800630, -3.517150, -0.324470, -0.500390, -0.400060, 0.092190, 5.431230,
2.475070, 0.070910, 0.320930, -0.951670, 0.382780, -2.731590, 2.897790, 1.631360, 0.753750, -0.401390,
0.128750, 0.368830, 2.144540, -0.209650, -3.136080, 0.743170, -1.974440, -1.952190, 1.436560, -0.509200,
-2.916470, 0.885150, 4.401570, 0.898440, 0.848140, 0.454390, -1.371770, -0.907540, -5.291930, 1.787050,
3.314380, 1.748050, 0.265650, 1.084310, 0.271440, 0.145600, 0.847910, -5.692900, -0.321770, -0.729630,
-3.215630, 0.534860, 1.166850, 1.551870, 0.143390, 3.358350, 1.865010, -0.772210, 0.257650, -0.378290,
0.615840, -1.481460, 2.274840, 3.733270, 2.193540, -3.383240, 0.621670, -1.124360, -0.979880, 0.120870,
-5.460290, -0.721590, 1.590020, -3.145410, 0.245690, -1.517440, 1.652020, 0.149510, 3.060800, 3.155070,
1.098530, 0.017300, -1.663900, 0.151930, -0.655020, 0.400670, -1.035100, -0.661510, -0.037800, 0.404960,
0.156830, -1.143170, -1.026660, -2.072120, 0.676380, 0.895690, -1.258310, -0.666520, 0.122020, 1.246810,
-0.075610, 0.806490, -1.277470, -10.835480, 0.927490, -0.742190, 3.969160, 0.137730, -0.014020, -0.942510,
1.027150, -0.953420, 0.713600, 0.077480, 0.298050, 0.002350, -0.140780, -0.145400, -0.143170, -0.774760,
0.607540, -0.990740, -0.765290, -0.319750, -0.779370, -0.365130, -0.659240, -0.725840,
-0.955620, -1.043330, 1.969930, 1.450010, -0.422100, 0.750190, 0.048430, 1.484850, -0.630080, 0.640040,
0.325010, 0.099470, -0.054100, -1.715650, -1.964030, 1.422190, 0.506430, -1.065920, 0.912340, -1.059040,
0.460780, 0.313510, 0.433130, 0.480830, 0.312750, -1.036100, 1.663470, 0.076000, -0.773570, -0.952340,
0.494740, 1.538470, -2.398730, -0.987670, -0.402370, -0.172090, 0.781320, -0.078100, 1.470090, 0.826190,
-0.215620, -0.230580, 1.652960, 0.742330, 0.091110, 1.958090, 0.578730, 1.299280, -1.673740, 2.079620,
-0.422270, 1.098130, 0.064690, -0.563170, 0.279610, 1.794700, -0.684880, 0.094990, -0.910860, 0.105430,
-1.504350, 1.058190, 2.806190, 1.379270, 0.012890, -1.271280, -0.923330, -1.357280, 1.160370, 1.561770,
1.776390, -0.312710, -0.826990, 0.156000, -0.080720, -2.077530, -0.053930, 2.526700, 1.235630, 0.802310,
0.085130, -0.328740, -0.598940, 1.510250, -0.305490, -0.379020, 0.439120, 0.521970, 0.692020, 1.205770,
-0.748090, -0.084140, 1.317380, 0.797750, -0.165540, 0.183520, 0.995120, -0.352590, 0.237020, -0.854380,
0.485780, 1.270490, -1.919780, -0.520370, -0.616040, 1.822600, 0.508730, -0.061520, 0.775290, 1.930770,
-0.121530, 0.796050, -0.335460, 1.402770, -0.996540, 2.481790, 3.097660, -0.870510, -2.999960, 0.163150,
1.234110, 0.560670, -0.161190, 2.057380, -0.083480, -0.987720, -1.156800, -1.881180, 2.319110, 0.638000,
-0.542260, -2.151810, 1.990340, 0.691380, 0.415510, 1.726120, -0.592920, -2.394510, -0.245360, 4.000230,
-0.558680, -1.968960, -0.881540, 0.672260, -1.232550, -1.076930, 0.841180, -3.894220, -2.177950, -1.128800,
-2.023450, 2.299500, -0.474860, 0.580910, -1.321560, 1.622740, 0.863980, 0.657290, 0.339430, 0.431230,
-0.574280, -0.389210, 7.933590, -0.656110, 0.205430, -3.030370, -2.490640, 0.497040, 2.770610, 0.560950,
0.255410, -2.290660, 1.631660, 0.967400, 1.772990, 1.089690, 0.206840, -0.009140, 0.496560, -0.888790,
-0.617120, 0.832860, 0.117430, -0.268810, -0.567640, 5.393490, 0.100550, -2.188370, -2.201500, -0.801190,
-0.695530, 0.575000, 1.189480, -0.129730, 3.246020, -0.626650, 0.775050, 1.463560, 0.113620, -0.631280,
-0.490830, -0.242610, 1.453190, -1.755550, 0.885800, -0.796440, 0.200210, -0.884200, 1.557030, -0.066530,
-2.156400, 0.250750, 0.088840, 1.274220, -1.219470, 1.062590, -0.611080, 1.092670, -0.886140, -0.523420,
-0.060090, 1.486860, -1.325590, 0.077270, -1.648370, 0.192680, 1.383010, 0.696720, -1.178770, 0.526270,
-0.084150, 2.007000, -0.812350, -1.678700, -2.450500, 0.563890, 1.296720, -1.788590, -1.323170, 1.957960,
1.649540, -0.750580, 0.826230, -2.165420, -1.499560, -1.010060, 0.379110, 0.444900, 0.036060, 0.927500,
-0.691740, -2.260670, 1.620550, 1.689280, -0.179440, 0.716660, -0.452370, -1.169460, -0.883780, -0.517410,
1.562630, 1.893160, 0.894570, -0.436210, 1.313290, -1.034670, -2.033590, -0.705630, -0.118830, 1.046880,
0.206760, 0.056130, 0.778500, -1.381840, 1.256290, -0.729570, 0.061080, 0.519870, 0.213660, 0.029830,
-3.434490, -2.621950, 0.024060, 0.486400, 0.391620, -0.898290, 0.956900, -0.617460, 0.096880, 0.597890,
1.621830, 0.365470, -0.738270, -0.592070, 0.561820, -0.528260, -0.608230, 0.423640,
0.989120, -1.039010, 1.339700, 0.692530, -0.438320, -1.904690, -0.177410, 0.903870, -0.331530, -0.312310,
0.287240, 1.314660, -0.689840, -0.046750, -0.119520, -0.332340, -0.027900, -0.514530, 0.121250, 1.768820,
-1.033310, -0.429170, 0.565890, -3.873870, -0.922450, -0.360060, 0.022130, -1.103190, 0.858240, 1.391260,
-0.756970, -0.887140, 0.128420, -0.050080, -0.814640, 0.784680, -0.185540, -0.830860, -0.148070, 1.645880,
-0.100010, 1.004810, -1.580180, -0.611920, 0.602390, -0.359640, -1.583730, -4.765730, -1.119660, 2.247340,
-0.670520, -1.218740, 0.734460, -1.695910, -0.403600, 2.296560, -0.538040, 0.345250, -0.152760, -4.273700,
-1.825850, -0.508660, 4.264400, -1.172970, 0.488000, 1.115080, 0.019320, -1.125530, 0.229520, 0.009890,
-3.576190, -0.067950, 2.760210, -0.511890, 0.869790, 1.800160, 3.865300, -0.834400, -0.156000, 0.251560,
-0.581230, 0.507820, -1.918270, 0.485450, -0.031740, 1.964330, -0.943100, -0.391380, 1.169210, 0.835250,
1.190670, 1.665250, -1.064960, 0.906920, -0.423550, 1.171440, 1.219520, -2.282070, 0.796100, 0.548660,
-0.664700, -0.469890, 2.630960, 1.002260, -1.646560, -3.738730, -0.897610, 2.440450, -0.581250, -0.237860,
-0.302750, 1.926310, -0.270710, 0.632830, 1.369230, 0.768080, -1.399970, 1.765220, 0.134230, -0.042060,
0.140630, 2.786060, 0.357270, 0.273420, -0.220270, -0.308220, 0.145870, -0.382950, 0.753960, 0.285390,
-0.369900, -0.819140, 1.304520, 0.151460, 1.742280, 0.284710, -0.938000, 0.775140, 1.601380, 0.698980,
0.556140, 2.552080, -0.799030, -1.609970, -0.835220, -0.132310, 1.393160, -1.845190, -2.480890, -2.383000,
1.417260, 0.533780, 1.607490, -0.120520, -2.463270, -0.940780, 0.754530, 0.032720, 0.645220, 1.385030,
-0.184270, 1.195940, 0.393080, -0.851120, -0.477750, -0.434710, 0.353260, 1.141080, -0.686840, -0.005960,
-2.019180, -1.370440, 0.290910, 0.516450, 1.648110, -0.139430, -1.044700, 0.887990, 1.062840, 0.808290,
-1.617330, -0.586030, 1.657340, 0.261880, 0.145860, -1.147910, 0.201220, -3.804300, -1.747340, -0.995250,
1.084290, -0.167770, -0.327930, -0.522760, 1.681850, -0.578230, 1.540570, 4.043930, 0.067490, -1.996200,
1.503770, 0.936350, -0.148420, -1.112480, 0.576920, 0.344210, 0.762230, -0.633170, 1.091130, -0.098290,
0.653980, 0.141600, -0.258550, -1.590270, 2.072640, -1.833580, -0.076230, -0.155040, 1.077820, -0.311290,
-0.342700, 0.193280, -0.330490, 0.040380, 0.639640, -0.767070, -0.349290, 0.158310, 0.248180, -1.423350,
0.205890, -0.890060, -0.444910, 1.028440, -0.851220, 0.255250, -1.003700, 0.664000, -2.561970, 0.736080,
0.076620, 1.250000, -0.681130, 1.161710, -1.208420, 1.041620, 0.550000, 1.924300, 0.231240, -0.848700,
-0.368600, 0.844790, 0.715910, -3.812700, -2.546060, -0.515770, -0.274790, -0.345720, 1.116780, -1.235740,
0.269430, 1.130150, -0.142070, 1.028020, -1.374650, 0.369240, -1.362440, -1.334390, -0.754290, 1.536120,
-0.256660, -0.908920, 0.532690, -0.701770, 0.980480, 0.356070, -4.529160, -1.304380, -1.381150, 0.251340,
2.634090, 0.269470, -1.684810, 1.877980, -0.109440, 0.453060, 0.022860, 1.127110, -1.615020, -0.269810,
-0.582870, 0.111220, 1.498570, -0.380630, 0.160480, -2.552210, -3.139620, -0.652260,
0.391710, -0.560270, 0.697680, 0.258170, 0.083200, -0.420980, 0.849680, -0.536630, 0.165880, 0.193570,
0.437830, 0.456150, 1.336920, 0.360850, -0.844070, 0.597640, -0.724730, 0.360980, 0.625950, 0.335140,
0.618340, 0.222050, 0.726460, -0.467870, 0.376990, 0.283100, -0.238150, 0.493790, 0.433960, -0.366920,
-0.807610, -0.620930, -3.896020, 0.683910, -0.126740, 0.204240, 0.669500, 0.353620, -2.120520, 0.282240,
-0.456850, -0.269560, -0.180520, 1.917200, -0.076580, 0.388420, 0.222770, -1.822920, -1.254310, 0.071480,
-0.840400, -1.217220, 0.018820, 0.827500, 0.309040, 0.258890, 0.752540, 0.628950, 0.397780, 0.261900,

1.647570, -0.746850, -0.870440, -0.465100, 0.621410, -0.219780, -0.634930, -0.268680, -0.338170, -1.103710,
-1.026250, 0.521130, 1.100020, 0.343690, -0.758380, 0.301200, 0.424500, -0.815300, -0.261010, -0.986210,
-1.119510, -0.268820, -0.525580, -0.692400, 0.017530, 1.128610, 0.008790, -0.393840, -0.798970, 0.456360,
0.330660, -0.848940, 5.954390, 0.188160, -0.507730, 0.185380, 1.111700, 0.732000, 4.249080, 2.352400,
-0.584510, -2.282550, 0.886680, -0.764970, -0.390140, 1.441220, -0.784710, 0.062360, 2.807640, -0.279390,
1.162210, 0.842170, -1.651570, 0.083880, -0.287980, 0.766140, 0.410690, 0.278320, -0.493460, 0.154270,

0.380240, -0.523830, -1.085520, -1.306490, -0.488220, 0.202590, 0.234180, 0.540380, -1.960880, -0.480880,
-1.393160, -0.088120, 0.291000, 0.525450, -0.594960, -1.793150, 0.932210, -1.812050, 0.461860, -0.797600,
-0.419610, -0.793760, 0.133560, 0.059820, -1.725820, 0.068520, -1.336140, 0.001960, -6.765790, -1.317330,
-0.779310, 0.596870, 0.476620, 0.268580, -0.231970, 0.502480, 0.680400, 0.895960, 0.491900, 1.029920,
0.306520, -0.379830, 0.613100, 0.630960, 0.431130, -0.254320, 0.575230, 0.568250, -0.680100, -0.515780,
0.103820, 1.654210, -0.306790, -0.062130, -0.027210, 0.428310, 0.100840, -0.049960, -0.849200, -0.161780,

-1.103370, -0.046480, 0.546330, -0.120030, 0.512390, -0.811360, 0.037440, -0.075360, 1.386300, -0.791920,
0.766330, 0.449130, 0.439900, -0.176950, -0.880560, -0.503230, -0.303970, -0.351470, 0.464340, 0.445960,
-1.245240, -0.736280, -0.990880, -1.275830, -0.765210, 0.020510, 0.538770, 0.327200, 0.365570, 0.679000,
-0.553340, 0.327070, 0.185520, 0.459890, 0.088290, 0.767220, -1.005770, -0.307970, 1.452690, -0.056680,
0.369700, 1.223710, -0.929490, -4.433490, -0.275750, -1.217470, 0.439600, -0.056140, 0.569750, 0.206200,
-0.790860, 5.047470, 1.240030, 0.126030, -0.544420, -1.329170, 0.946920, -0.331600, 0.954470, 0.350980,

-0.686030, -0.094440, 0.463840, -0.218510, 0.142990, -0.221190, 0.651840, 0.291370, -0.268690, -0.866980,
0.069890, 0.743700, 1.105680, -0.599960, -0.364370, -0.793200, -0.056940, 0.051620, -0.899940, 0.427650,
0.327770, 0.721120, -0.058470, 1.084240, 0.692490, 0.167760, -0.237060, -0.084120, 0.020990, -0.727520,
0.388410, -0.654900, -1.576190, 1.376560, -0.741790, 0.404330, 0.621090, -0.589830, -3.347140, -0.610080,
-0.609510, -0.617460, -0.545260, 0.536570, 0.832760, -0.839370, -0.915520, -0.282210, -0.552960, 1.389720,
-0.898300, 1.214290, -0.452470, 0.150970, -0.224400, -0.981860, 0.764320, 0.318840, 0.733500, 1.580720,

-0.611770, -0.966570, -0.698060, -0.144520, -1.633510, 0.980040, 0.625900, -2.060470, -5.721260, -0.486610,
0.600200, -0.218680, -0.192330, 0.695530, 0.896590, -1.953230, 0.469520, 0.418200, 0.338470, 0.328590,
-0.507360, 0.399030, -1.667710, -1.652070, -0.093240, -2.721470, 0.063100, 0.970840, 0.306950, -0.392720,
0.756340, -0.512150, 0.867740, -0.281800, 0.517090, 0.374380, 0.644440, -0.345920, 0.486420, -1.173400,
-0.650330, 0.054140, 0.571870, -0.942100, -1.014140, 0.506820, -0.619560, -0.742850, -1.131820, -0.047060,
0.798740, 0.316870, -1.148070, 0.492110, -0.731390, 0.470380, -0.480580, -0.425600, -0.193660, -1.876300,

0.426860, 0.753830, 0.232000, -0.648600, -0.557570, -0.021470, 0.860060, 0.298030, -0.055610, -0.288590,
-0.034910, 0.012410, -0.123100, -0.167220, -0.530450, 0.028880, -0.370510, -0.140130, -0.497390, 0.000230,
0.992280, -0.652840, -0.407250, -0.366740, 1.004790, -0.081030, -0.250030, -0.246570, 0.041060, -0.907150,
0.500790, 0.708550, -1.523940, -0.407100, 0.090050, 1.450810, 0.646730, -0.457030, 1.369590, 1.625890,
0.487850, -0.891610, -0.316130, -0.858020, 0.389390, 0.417260, 0.962550, 0.420030, 1.727130, 0.509080,
0.199980, -6.071160, 1.231680, 0.133900, 0.888230, 0.794120, -0.451940, -0.150920, -0.561780, -0.302740,

-0.246350, 0.188380, -0.830260, 0.293770, -0.799870, 0.578000, -0.769580, -0.556020, 0.541210, -0.228210,
0.697670, 0.790720, -0.119210, 0.058910, -0.966950, -0.001130, -0.100240, 0.349650, 0.420640, -0.147150,
0.099030, 0.406980, -0.265420, -1.048620, 0.109810, 1.102150, -0.765220, -0.082870, 0.067990, 0.004900,
0.686270, 0.778550, 0.676780, 1.931850, 0.798610, -0.338730, -1.032990, 1.005300, -0.722300, -1.098680,
-0.692970, 1.473050, -0.222300, 1.643070, -0.438480, 0.501450, -0.086440, -0.344770, 0.000690, 0.198080,
-0.602650, 1.460390, 0.456350, -0.459660, 0.912410, 0.678390, 0.582790, -0.235510, -0.416680, -0.230220,

0.391130, -2.680940, 0.444350, -1.555060, -0.160840, 1.313870, 0.340160, -0.630160, 0.009750, 0.484690,
-0.521360, -2.708260, -0.523790, 0.984620, -0.687020, -0.461570, -1.264580, 0.294610, 0.901340, -0.150350,
-0.550990, 2.057830, -0.239240, 0.925900, -0.771780, 0.272770, -0.497660, -0.326380, 1.207030, -0.721810,
-0.318510, 0.629330, 0.280060, -0.336760, 0.699370, -0.318090, -0.820810, 0.691670, 0.828080, 0.480380,
-0.039990, -0.768840, -0.870810, -0.531870, -1.079870, 0.093310, -0.513650, 0.053320, 0.015470, 0.076080,
-0.405710, 0.365760, -0.411170, 0.312080, -0.262210, -0.807150, -0.152370, -0.570640, -0.645330, 1.307140,

-1.049190, 0.215730, -0.185920, 2.904860, 0.431260, -0.401400, 0.923670, -0.456690, 0.377630, 0.587010,
0.166400, 0.327420, 1.783070, -0.209040, 0.193150, -0.170620, 1.139610, -0.021290, -0.081600, -1.275030,
0.314260, -1.076950, -0.534590, 3.217920, -2.682740, 0.654030, 0.131630, 1.059670, -1.173160, -0.751650,
-0.034150, -1.012490, 0.965680, -0.064030, -0.908130, -0.553730, -0.494810, -0.305820, 0.129910, -0.315980,
0.680320, -1.086910, -0.607940, -1.229690, -0.287420, 0.013740, 0.375700, -0.487270, -1.434070, 0.420830,
-0.066400, 0.192410, 0.565050, -0.582320, -0.807800, -0.145830, -1.153940, -0.067680, 0.303220, -0.562610,

-0.894470, -0.006240, -0.685570, 0.360270, -0.649850, 1.362290, -0.643290, 0.041090, -0.948670, 0.870140,
-0.942300, 0.012120, -1.148690, 0.591830, 0.437790, -0.486450, -1.040590, 0.361300, -0.610110, -0.315300,
-0.316160, 0.340670, 0.195260, -0.624760, -0.800330, -0.620940, 0.429840, -0.553390, -0.756090, -0.458160,
0.122620, 0.957470, 0.452280, 0.060110, -0.009910, 1.734430, 0.675790, -0.954580, 4.135040, 0.402760,
0.187110, -0.297980, 0.130540, -1.080680, -0.926950, -0.484430, 0.018380, 0.743190, 1.291780, 0.115770,
-0.102790, -0.864330, -0.830880, 0.069240, 0.547370, 0.585550, 0.238730, -0.488890, 0.768250, 1.668380,

0.520490, -0.415880, 0.585090, -0.012230, 0.165440, -0.198320, 0.985550, 0.995470, 0.683220, -0.797410,
-0.048280, 0.569170, 0.688920, -0.740250, -0.308210, 0.338400, 0.183520, 0.923260, 0.529100, -0.611650,
-0.866940, 0.810960, 0.568910, 0.218960, -0.837830, 0.353780, -0.295010, 0.376280, -0.132670, 0.686600,
-0.169910, -0.888910, 2.629310, -0.338730, -0.868080, -2.269920, -0.355050, 1.163980, -5.880440, -2.656140,
-1.205160, -0.594890, 0.047010, 0.688600, -0.360230, 0.376010, -2.099790, 1.304480, -6.643490, -1.440230,
-0.943950, -1.122160, -0.401160, 0.071690, -0.140980, 0.403660, -0.214820, -0.435720, 0.529850, -3.448290,

0.206980, -0.167290, 0.511000, -0.880320, -1.074920, -2.537360, 0.558300, -1.084990, 2.402740, -0.768920,
-1.084670, 0.124510, 2.175140, 1.072560, -0.734370, 0.570790, 0.093430, 0.385770, 0.752000, 0.673020,
-2.084130, 0.352710, -0.965630, 0.427740, 0.551370, 0.429850, -0.503330, 1.005420, -1.112150, -1.481890,
0.199580, -0.715540, -0.742500, -0.146920, -0.459440, 0.293160, -0.975870, -0.831290, 1.822700, -0.492800,
-0.646810, 0.249410, -0.540670, -0.631620, -0.020140, 0.695120, -0.929670, -0.173400, -0.508120, 0.624830,
0.642750, 0.493840, -0.568340, 0.757860, 0.422700, -0.126970, -0.414590, 0.251100, 0.784570, 0.210530,

-0.241450, 0.288510, 0.378830, 0.339730, -1.005690, -0.010860, 0.789670, -0.146190, -0.615290, 0.145220,
0.534940, -0.255210, 0.806660, -0.023550, -0.362320, 0.676970, 0.779970, -0.434380, -2.152950, 1.084070,
-0.126040, -0.251580, -0.110810, 0.612450, 1.144680, 0.850310, -1.065880, 0.297170, -0.967850, 0.698310,
0.564910, 0.581930, 0.124030, 0.021700, 0.153200, -1.905120, -0.711850, 0.002440, -2.800030, -1.173060,
-0.327410, 0.745420, 0.606550, 0.000340, -0.993480, -0.293820, -0.801620, 0.496540, -7.435300, -0.397620,
-1.110700, -0.290200, -2.371280, 0.390020, 0.174890, -0.288550, 0.238850, -0.483670, 0.524580, -1.247830,

0.505290, 0.107610, -0.062600, 0.062190, 0.190500, -0.067200, 1.114150, 0.000940, -0.055930, 0.288390,
-0.123640, 0.151710, -0.333900, -0.526160, 0.053740, -0.037320, -0.129020, -0.294120, -0.182090, 0.172480,
0.834280, -0.115270, 0.482250, 3.216890, 0.294210, 0.205270, -0.338280, 0.128870, -0.092900, 0.225450,
-0.093650, 1.383870, -3.318570, -1.044780, -0.601240, 0.368390, -0.897250, -0.013910, -2.808600, 0.588230,
1.136430, -1.779230, -0.826540, 0.269690, -0.749510, 0.466870, 0.461170, -0.129500, 0.591370, 0.244320,
0.115260, -3.013200, -0.119100, 0.605100, 0.918240, 1.831730, 0.087400, -0.412970, 0.947380, -0.263340,

-0.060730, 0.516520, 0.768560, -0.862410, -0.123720, -0.029680, -0.749340, -0.131620, 2.124600, -0.705710,
0.926390, 0.381100, 0.928020, 0.402930, -0.855850, 0.893100, 0.480980, 0.328200, -0.897630, -0.038520,
0.242870, -0.975340, -0.719110, -1.085370, 0.496320, 1.281660, 0.189540, -0.304470, -0.159240, -0.599720,
0.803300, 0.844990, 0.869650, 0.183110, 0.143470, -2.233750, -0.826700, 0.639840, -3.677160, -2.532570,
-1.823660, 0.219390, 3.143720, 2.835640, -0.749640, -0.035830, 0.174150, -0.161680, 0.093540, -0.240240,
0.727290, 1.735550, -2.372040, -0.001610, -0.820370, 0.588810, 0.704340, -0.219590, -1.089450, -5.814610,

0.915330, -1.075510, -0.906580, 0.037190, 0.528710, 1.025090, -0.713140, -0.388770, -2.224520, 0.381580,
0.129250, -0.595480, -0.921940, 0.381680, 0.545790, -1.203300, -0.889790, -1.120380, -0.493930, 0.165210,
0.700010, 0.006610, 0.371060, -0.327820, -0.961150, -1.470410, -0.188410, 0.207170, 0.270650, -0.826390,
-0.440750, 0.372870, 2.915200, -0.352210, 0.772930, 3.423890, -0.568170, -1.102880, 2.072930, 0.739800,
0.666180, -5.904270, 0.606980, -2.339850, 0.397800, -0.735160, -0.210740, 1.085750, -0.016900, -0.106350,
-0.794530, -0.565760, -0.776640, -0.097610, -0.394370, 0.628390, 0.375400, -0.364580, 0.780370, 2.871950,

-0.314370, 0.116630, -0.399030, -0.207490, -0.207660, -0.400030, -0.657840, 0.887400, -0.831800, -1.519900,
1.039220, -0.609820, 0.933160, -0.244650, -0.056970, -0.703150, -0.705820, -0.212980, -0.620620, -0.231560,
0.100600, 0.421820, -0.196010, -0.964510, 0.299770, -0.020460, -1.034940, 0.014840, 0.172390, -3.319690,
0.152310, -0.315720, 1.397810, 0.456100, 0.174620, -4.569100, 0.417560, 0.394740, -0.492720, 0.395980,
0.078170, 0.684420, -0.661490, -0.914310, 0.813770, 0.233890, -0.714220, -0.506120, 2.028620, -1.682480,
0.114220, 0.823850, -0.905120, 0.486670, -0.129970, -0.082290, -0.407420, -0.465630, 0.392380, -4.034700,

0.043410, -1.010500, -0.464560, 0.022500, -0.280680, 0.936590, -0.597420, 0.599160, -1.896490, -0.561210,
-0.274480, -0.361070, -1.647570, -0.130780, 1.023360, -1.385760, 0.232220, -0.769360, -0.174970, -0.708210,
-0.236630, -0.415180, -0.033660, 0.565080, -0.054840, -0.690010, 0.252540, -0.300820, -0.057390, -0.166030,
-0.585340, 0.433570, 3.101290, -1.767260, 0.125250, 1.707680, 0.381320, 0.178890, 3.111870, 0.978040,
-0.364330, -2.382610, -0.809090, -3.764000, 0.108410, -0.909920, 0.176550, 1.938130, 0.191400, 0.128950,
0.062920, 1.891420, -0.458920, -0.452260, -0.272880, 0.276480, -0.754820, -0.306830, 0.574700, 1.369520,

1.086410, 1.519940, -0.330890, -0.054760, -0.164750, 0.450580, -1.786500, -0.391970, -0.041680, 0.747570,
0.655260, -0.477400, -2.022160, 0.487570, 0.790780, -0.118930, 0.969430, -0.166150, 0.104750, 0.490510,
0.203650, 0.003740, 0.534420, -1.464430, -0.675850, -1.294900, 0.988520, 1.129710, -0.630580, -0.483860,
0.475670, -1.377500, -0.252780, -0.630170, 0.302780, 1.208280, 0.181660, -0.079980, -0.242370, -0.235650,
-0.499120, -0.672880, -0.504740, -0.377070, -0.219770, 0.156910, 0.382890, -2.122010, -1.207680, -0.380320,
0.526740, -0.589910, 2.225730, -0.638490, 0.251550, 0.345820, 0.254580, 0.298030, -0.818550, 1.156490,

0.591820, 1.436460, -1.651670, 0.427310, -0.888810, -0.279360, 0.343970, 0.568680, -0.425580, -0.126920,
-0.109850, 1.093570, 1.452440, -0.495010, 0.083880, -0.929960, -0.787960, 0.303030, -0.649050, 0.531190,
-0.254120, -0.056550, 0.371430, -0.117870, -0.223510, -0.081830, 0.491760, 0.789620, -0.016430, -0.653170,
-0.220190, 0.734290, 0.756160, -0.233060, 0.293060, 0.289740, -0.372100, 0.283870, 2.177570, 0.959940,
0.085070, -0.170220, -0.876390, -0.374080, 0.900470, 0.244220, 0.281090, 0.240970, 4.220930, 0.342680,
0.771700, -1.922360, 0.801620, 0.831950, -0.528920, 1.013030, -0.188010, 0.644130, 0.598790, 0.645790,

0.450240, 0.016250, -0.273070, 1.072320, -0.526640, -0.625630, 0.892160, -0.864930, 0.840150, -0.218280,
-0.076230, 0.737870, 0.501000, 0.007060, 0.939400, 0.432860, 0.489110, -1.241610, 0.681900, 0.637810,
-0.710180, -0.391470, -1.425260, -1.068450, 0.801720, -2.180150, 0.145830, 1.606440, 0.722100, -0.010760,
0.862830, 0.133610, -1.859590, -1.073680, -0.987820, -0.031620, -0.163130, -0.819170, -1.325640, 1.382240,
-0.168960, 0.295770, -1.049560, 0.037990, -0.448220, -0.783030, 0.329140, -1.303640, -1.001780, 0.360840,
-0.413110, -6.698630, 1.782590, -0.655800, -0.535790, -0.692380, -0.806160, 0.764290, -0.840420, -0.933430,

-1.708990, -0.488380, 0.549850, 0.989580, 0.640070, 0.260470, -0.711460, 1.043860, -0.049540, -0.185450,
0.631050, 0.812130, -0.443890, -1.199110, -1.214890, 0.953160, -0.550250, -1.716200, 0.992440, -0.625300,
1.051660, -0.494070, -0.301240, -1.062730, -0.057520, -0.654930, -0.100750, 0.077360, 0.859790, 0.901720,
-0.292830, 0.588980, 0.717900, 0.528460, 0.158430, -0.494840, -0.852020, -0.878800, 2.203150, 0.659880,
-1.017440, 1.216390, 0.073010, 0.186660, -0.418130, 0.207440, 0.624030, -0.220870, 0.033470, 0.369220,
-0.499270, -0.525760, 0.541040, -0.653270, 0.834690, -0.462070, 0.546030, 0.165750, -0.612060, 0.962560,

-0.130940, -0.045460, 0.055940, 0.446350, -0.061850, -0.528540, 0.031320, -0.292430, 0.329990, -0.337630,
-0.460130, 0.154010, 0.594120, -0.366400, 0.615070, -0.394370, 0.649400, -0.498870, -1.155930, 0.482760,
0.065300, 0.532160, 0.245310, 0.970200, 0.371360, 0.054780, 0.266450, -0.117360, -0.406530, -0.509830,
0.835330, -0.269510, 1.233000, 1.006390, -0.325910, -2.384150, -0.717730, 0.605240, 0.620720, -0.128230,
0.956730, 0.228070, 0.855490, -0.187430, 0.851010, -0.428860, -0.057940, 0.098850, -0.561590, 0.971920,
0.571430, -0.409110, -0.553400, 0.525640, -0.606180, -0.182520, -0.467400, 0.246760, -0.720630, 0.541530,

0.618010, 1.348540, -0.541320, 1.230990, -0.676280, -0.476670, -0.915450, 0.256330, -0.014970, 0.452610,
-0.158560, 0.389470, -0.068730, 0.494270, -0.139260, 0.167800, 0.135630, 0.028720, 0.014680, 0.339800,
-0.694620, -1.110360, 0.749460, -0.854830, -0.530820, 0.292380, 0.762850, 0.754450, -0.090120, -0.287530,
-0.103530, -0.021640, 0.656800, -0.559610, -0.036670, -1.151780, -0.569640, 0.708120, 0.250380, 0.236220,
-0.337450, 1.738730, 0.107830, 1.851130, 0.141340, 0.464320, -0.384320, -2.012010, 0.653890, -0.382280,
0.710840, 0.159330, 0.763600, 0.568570, -0.473950, 0.760310, -0.215670, 0.124930, -0.643500, -1.708850,

-0.139330, 0.827960, -0.564550, 0.494000, 0.667970, 0.398710, 0.317000, 0.537130, 0.644590, -0.909500,
-0.071810, -0.671790, -0.190390, -1.089860, 0.071510, 0.845610, 0.478190, 0.700970, -0.555610, -0.059680,
0.687170, 0.593460, -0.166320, 0.714450, 0.487330, -0.208450, 0.025220, -0.122500, -0.191190, -0.131990,
-0.185320, 0.066420, 0.919070, -0.464110, -0.115250, -3.089670, -0.920160, 0.245420, 0.442570, -0.827730,
0.211350, 0.687540, 0.579980, 0.619120, 0.083150, 0.202850, 0.270850, 0.409950, -0.600400, -0.288010,
-0.290010, 0.073040, -1.048880, 0.747840, 0.362050, -0.845280, -0.885880, -0.381670, 0.435450, -0.020460,

-0.586250, 1.629960, 0.541140, 0.729450, 0.156360, -1.097970, -0.785370, 0.416760, 1.023200, 0.399050,
0.053010, 0.886390, 0.648630, -0.180880, -0.688950, 0.896880, -0.128670, -0.021150, 0.122560, 0.638300,
-0.521750, -0.701670, -0.349210, -0.234360, -0.483580, 0.751170, 0.145020, 0.960400, 0.381910, 0.836410,
0.692150, 0.733780, -0.379480, -0.200180, 0.652630, -0.458210, -0.682980, 0.400700, -0.512080, 0.425110,
-0.136320, 1.355010, 0.626830, -0.075350, 0.576480, -0.052280, -0.579860, -1.072950, 0.755290, -0.938480,
-0.534340, -0.999580, 0.517140, -0.728120, 0.180380, -1.019050, -0.383860, 0.511990, 0.087290, -1.127150,

-0.770330, 0.019340, 0.697170, -0.175570, 1.125480, 1.415920, -0.872640, 2.298190, -0.716020, 0.562710,
0.100140, -0.125070, -1.179370, -1.276780, -0.416200, 0.471400, 0.054720, -0.280640, -0.140350, -0.534610,
0.898460, 0.652230, 0.913190, 0.217490, -0.636000, -0.091560, -0.361350, -0.759940, 0.095020, 0.407170,
-0.061700, 0.326840, -0.375380, -0.834780, -0.243330, 1.896850, 0.476440, -0.175340, 2.614230, 0.239980,
-0.304990, 0.016950, -0.489610, 0.304500, -0.694260, -0.209700, -0.077820, -0.872610, 0.859520, 0.210220,
-0.287440, 0.012970, -0.350980, -0.530330, 0.794520, 0.971960, 0.668260, 0.712670, -0.592330, 0.301490,

-0.448000, 0.167840, 1.258280, -0.374310, -0.210840, -0.939490, -0.318410, -0.192150, 0.632720, 1.129860,
0.400720, 1.073460, 0.500200, -0.104290, -0.117350, 0.255710, -0.485180, -0.150520, 1.040180, -0.281960,
-1.151960, -0.358340, -0.450300, -0.996100, -0.610310, 0.235080, -0.539760, 0.905440, 0.970120, 0.487900,
-0.536610, -0.307510, 0.078960, -0.167550, 0.434750, -0.711410, 0.708870, 0.016250, 0.776970, -2.260040,
0.564870, 0.569630, 0.375550, 0.777560, 0.936070, 0.239950, 0.588570, -1.247980, 2.104370, 0.142360,
0.289510, -3.716090, 3.104330, 0.635580, -0.038020, 0.498680, -0.286090, -0.348070, -0.562130, -2.540810,

0.716170, -1.400350, -1.118840, -1.586240, -2.158580, 1.210510, 0.070150, 0.131940, -3.306090, -1.047750,
-0.547000, -0.988920, -0.957470, 0.690360, 0.438680, -0.836520, -0.820480, -0.154150, 1.035860, -0.815360,
0.625110, 1.179320, 0.893030, 0.328330, 0.313980, -0.728890, -4.224340, -1.909660, 0.368420, 0.093570,
0.740950, -0.949000, 0.568740, -0.249500, -0.235160, -0.120620, -0.737900, 0.736450, -0.021130, 2.454820,
0.167950, -0.202110, 0.389380, -0.852650, -0.635510, -0.298790, 0.032210, -0.029820, 0.547810, -0.352140,
0.487630, 0.061660, 2.726030, 0.329170, 0.232060, -1.058850, 0.392350, -0.436730, -0.163260, -0.937910,

0.798120, -0.041230, 0.401680, -2.226820, -0.499000, -0.456520, -0.194090, 0.792260, -2.101480, -0.844310,
-0.314220, 0.836830, 0.517060, 1.044600, -0.334600, 0.639250, -0.545720, 0.392520, -1.381100, -1.261960,
0.451560, -0.562270, -0.032520, -0.002840, -0.200750, 0.352960, 0.806450, -0.541850, -0.487680, -1.502240,

-0.652120, 0.722710, 0.984850, 0.375610, -0.841350, 0.744600, 0.300230, -0.722540, 0.670820, 0.400370,
0.851020, -1.385140, -0.738180, -1.503680, 0.715870, -0.187760, -0.115670, 0.584640, 0.539660, -0.759530,
0.480070, 0.599390, 0.016250, -0.410340, -0.351000, 0.196680, -0.525440, -0.358780, 0.251900, -0.481620,

0.843560, -0.594010, -0.912970, 0.463850, 0.592930, 0.328560, -0.311450, 0.353970, -0.832020, 0.179410,
-0.366310, -1.045780, -0.112130, -1.291730, -0.753750, -0.633890, 0.060960, -0.623180, -0.708600, 0.959480,
0.236670, -0.036150, -0.174380, 0.364610, -0.238270, -0.640770, 0.498980, 0.456490, -0.960580, 0.978470,

-0.119920, 0.424510, 0.137830, -0.393230, 0.585700, -1.499940, -0.711610, 0.464540, -3.343470, -1.272310,
-0.041020, 0.235250, 1.135330, 1.004250, 0.642600, 0.924150, -0.824990, 0.604730, -1.582440, -0.588750,
-0.343940, -2.327040, -0.969380, -0.739160, 0.375630, 0.761870, -0.003030, -0.763670, 0.341350, -1.961180,

-0.978630, 0.740150, 1.226700, -0.649850, 0.082060, 0.919870, 0.128750, -0.282580, 1.637680, 0.518140,
0.565310, -1.057890, 0.016210, -1.614870, 0.018760, -0.556210, 0.862730, 0.155600, -0.027290, -0.828980,
-0.803250, 0.102540, -0.352970, 0.365940, 0.191100, -0.046230, -0.988720, 0.470270, -0.429870, 0.269380,

-0.591610, -0.520690, -1.538790, 0.462180, 0.394090, 0.905080, 0.193250, -0.146740, -1.766670, 0.059850,
-0.523640, -0.381280, -0.712090, -0.686810, 0.867080, -0.963140, -0.254490, -0.576050, -1.701660, 0.443950,
-0.560740, 1.388320, 0.805540, -0.694710, 0.577040, -0.889290, -0.344690, 0.799710, 0.269780, 0.741480,

-0.472560, 0.366670, -0.022620, 0.294910, 0.168790, -1.406140, 0.550870, 0.414840, -3.369840, -1.192010,
-0.854990, 0.546420, 0.909070, 0.999470, -0.385170, 0.629560, -0.354380, 0.388580, -1.341850, -0.774680,
-0.409470, 1.067960, -2.123750, 0.216150, 0.539740, -0.309680, 0.589770, -1.292630, -0.833470, -2.198450,

-0.524860, 0.296860, 1.176680, -0.782330, -0.659070, 0.956840, 0.370200, 0.453550, 1.718800, 0.468970,
0.428160, -1.142210, 0.041760, -1.620950, -0.257270, -0.815930, 0.363350, 0.917830, -0.234180, -0.073040,
-0.755300, -0.691260, -1.162510, 0.616570, -0.607990, -0.128860, -1.051900, 0.256110, -0.619590, 1.409320,

0.068430, -0.409750, -1.230970, 0.069110, 0.169940, 1.272150, 0.513200, -0.260470, -2.458950, 0.209990,
0.275550, 0.148420, -1.173570, -1.009330, -0.549530, -0.389660, -0.204520, -0.475470, -0.571090, 0.135470,
-0.433310, -1.272540, 1.690740, 0.173560, 0.055780, -0.529230, 0.848820, 1.141270, -0.357300, -0.294460,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.021130, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, -1.283240, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, 0.477220, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.494190, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.365150, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -1.308870, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.827680, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, -0.096810, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, -2.106950, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, 0.342580, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.110190, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.514320, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, 0.468820, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -0.140780, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 0.809340, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, -0.220900, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, 0.201420, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, -0.302460, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -1.309940, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 1.009360, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, 1.297380, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.077210, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, 1.150800, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -1.110900, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.154240, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, -1.134400, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, 0.480670, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, -0.843340, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, -0.171560, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -1.536510, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -1.063100, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, 0.968590, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, 0.612480, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.651210, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, -0.137040, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.530170, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, 0.528750, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.721350, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -1.030140, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.725140, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, 0.550810, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, 0.535410, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, -0.128060, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.757290, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, 0.721240, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, 0.516110, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.232660, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, -0.460560, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.373230, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, -0.525520, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, -0.701370, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.914810, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.197870, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.628990, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, -0.284800, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, -0.073040, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.941650, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.659380, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 1.161470, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.180400, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.976100, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.832850, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, 0.257420, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, -0.643240, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.181460, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 0.688830, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, 0.872850, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.771810, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.484350, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
1.39000, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.00001, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
1.42855, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
0.40336, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
1.37911, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
0.21514, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
0.96141, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
1.42828, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
0.03411, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
0.42855, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
1.42531, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
1.26195, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
0.00004, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
0.00931, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
1.40970, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
0.52656, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
0.33407, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
0.15973, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
1.42518, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
0.01499, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
1.42433, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.39108, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
1.41971, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
0.00003, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
0.00051, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.00029, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
1.42827, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
0.00264, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
1.39528, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
0.03968, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.42271, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
0.14191, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
0.00014, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
0.36404, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
1.36052, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.00145, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
1.34940, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
1.01210, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.00484, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.01243, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
0.04445, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
0.29456, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.00527, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
0.00029, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
1.33933, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
0.00689, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
0.03892, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.03875, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.03345, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
1.37066, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
1.40182, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
0.04206, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
0.96368, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
1.29193, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.62334, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.13644, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
0.97006, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.41853, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
1.42759, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.60523, 0.500000, 2,
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
