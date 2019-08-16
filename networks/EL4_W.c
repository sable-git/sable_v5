/*********************************************************
  ELMAN268-30-30-9ENTROP4+weight.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:04:24 2004
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
0.436600, -0.594930, 1.046830, -0.127580, -1.196120, -0.237470, -0.241010, 0.883050, 1.213540, -1.391710,
-0.157300, 0.070590, 3.403390, 0.878310, -0.041050, -0.668750, -0.055580, 2.616740, 0.313810, -0.578830,
-1.026710, 0.886680, 0.361450, 1.281500, -1.070130, -1.640600, -1.144950, 0.476480, 0.212280, 1.683610,
0.372910, -0.904930, -1.187450, 0.514940, 0.038780, -0.838790, 0.367820, -0.116440, -0.566880, -0.215750,
-0.602090, 0.407470, 0.697310, -0.382200, 0.105170, 0.444440, -0.549800, -0.074760, 1.324660, -1.498510,
-0.816930, -0.487170, 0.292480, 0.020110, -0.218210, -0.789950, -0.408060, 0.510040, -0.384720, -0.524910,
0.007450, 0.361560, 1.064510, 1.481550, -0.643860, -0.759590, -0.044690, 1.378900, -1.159610, 0.072200,
-3.103350, 0.810600, 0.706730, -1.456360, -0.372270, -1.817780, 2.313910, 0.852130, 0.603300, -1.620830,
1.487560, -1.119050, -0.018960, -0.171460, 0.242990, 0.089320, 0.548590, -0.573890, -2.330750, -0.857350,
1.403950, -0.190230, -1.192520, -0.988500, 1.093830, -2.791640, -1.032410, 0.135630, 1.889300, 0.850520,
-0.815290, -1.425730, -0.133260, 0.704930, 0.630420, -1.269680, -1.682570, -0.483860, -0.325830, -2.001110,
-0.687330, 0.182110, -0.945720, -0.075340, 0.235830, -1.310180, -1.117790, 0.919240, -2.561950, -0.273930,
0.856750, -2.813470, -1.637370, -2.149800, 3.002890, 1.482360, -0.818300, 3.302980, 3.091710, 0.469610,
-1.400540, 3.974060, -0.564020, -2.377950, -0.159560, 0.558800, -1.280970, -0.780400, -3.061480, -1.865720,
-0.202030, 5.232910, -0.618720, -0.433600, -0.193990, 0.173790, -3.394320, 0.882760, 3.913600, -0.186740,
1.102840, -5.096190, 0.585570, 1.394020, 0.708710, 0.210520, -0.472140, 0.365090, 0.320200, -0.282000,
0.751260, -1.228220, -5.031370, 0.877630, 5.930540, -0.272140, 1.288250, -0.112410, 0.946960, 0.297220,
3.764440, 3.408500, 0.964660, 0.793940, -5.573610, 0.924680, 2.427220, 1.493200, -0.084590, 1.877540,
3.048950, -3.470710, 0.438880, 3.173140, 0.450820, -4.540470, 1.843180, 0.911160, 0.540890, -0.187820,
-0.764900, -1.174290, -1.666370, 0.050360, 0.111440, 2.144100, -0.132730, -0.358780, -0.778230, 0.250480,
0.442180, -0.778540, -0.105830, 0.208580, -3.647730, 1.571000, 0.207160, -0.294650, -3.050490, -0.618910,
2.031620, -0.107370, 0.983430, 2.012390, -0.676700, -0.530730, 0.038380, -0.229150, 1.322300, 0.925950,
-0.122150, 1.592880, 1.090960, 3.497420, -1.989420, 0.270620, 1.879360, -1.085490, -0.905200, 2.621610,
2.415280, -1.334230, -1.152930, 2.031340, -0.194540, -0.887610, -0.683310, 0.347600, -0.768820, 0.188070,
-0.548640, 2.446540, -0.498770, 1.311730, -0.920790, 0.596230, 0.723420, 0.536950, -0.728630, -0.479200,
1.259990, -0.378940, 0.651950, -0.279070, -0.555660, -2.091960, -0.764490, -0.165130, -0.303360, 1.199680,
1.508100, 0.709050, 2.459920, -2.505830, -1.986570, -1.576010, 1.256940, 0.934050, -0.177280, 0.706180,
0.556720, 0.536950, 0.978930, -0.479420, 1.247800, -0.226180, 2.999780, 1.190420, 0.396520, 0.384320,
3.249940, -0.207480, -0.229640, 1.402550, 0.098810, 0.383000, 0.314040, 0.360170, 0.863450, 0.883020,
0.467100, -0.153850, 0.428900, 1.493070, 0.037070, 0.565820, -0.073970, 0.480750,
-0.404690, -0.531240, -0.280640, -0.514230, -1.317880, 0.726500, -0.439160, 0.665700, -0.214410, 0.470280,
0.005200, -0.173460, 1.181840, 0.387330, -1.363480, 0.492900, 0.972250, 1.009170, -0.148240, -0.164220,
0.198990, 0.027600, 0.706020, -1.545890, -1.381870, -0.089680, -0.795310, -0.689350, 0.013370, 0.627590,
-1.250320, 0.192390, -0.850890, -0.687580, 0.132230, -0.334810, 0.377690, 0.727460, -0.048430, 0.147820,
1.919820, 0.898010, -1.013800, -0.275950, 0.055320, 1.149420, 0.493500, -0.563650, -0.320540, 0.360150,
0.948070, 1.376030, 0.815520, -1.310920, 0.893880, 2.682730, -2.979180, 0.065700, -0.052860, -1.590680,
0.208580, 0.898130, -0.272840, -0.358440, -0.260960, 1.120670, 0.888630, -0.040170, 1.159030, 1.275960,
0.001710, 0.577970, 1.653080, 0.969700, 0.490270, 0.046420, -0.252690, 2.631370, 1.920710, 1.418000,
-0.441000, 0.117980, 0.235110, 1.637170, -0.285770, -1.458740, 0.460570, -0.550030, 0.444480, 1.487410,
-0.484110, 1.490970, -1.555940, 0.269470, 0.977590, 4.505380, -0.694500, -2.127370, 0.130110, 0.115890,
0.000950, -2.100120, -0.239780, 0.415710, -1.299020, -1.901140, 0.824740, 0.318040, -0.691940, 0.270400,
2.212600, 0.658240, -1.569900, -0.166980, -0.188160, 1.304930, 1.004710, -0.400940, -0.236640, -0.834660,
1.031240, 0.706940, -1.403180, -0.604690, -0.966930, -1.385690, 0.067040, -0.144650, 2.407210, 1.305250,
0.095070, -0.597110, -1.289980, 1.589990, 1.077610, -1.853790, 0.968930, -1.116940, 2.496010, 0.440910,
1.238130, -1.174880, 1.974090, -0.141910, -0.439860, -2.569630, 1.377770, -0.470440, -2.001900, -0.300530,
0.480930, 2.258060, 0.376920, -0.469880, -0.872950, 1.186540, -0.954920, 0.115770, 3.802790, -0.679460,
-1.515210, 0.857080, 0.039670, -0.679950, 0.141580, -0.886820, 0.377380, 0.907770, 0.545280, 3.306060,
-0.189480, -0.637940, 1.551610, 0.975300, 0.541170, 0.355130, -0.284820, 0.014980, 0.789480, 0.680920,
0.890330, 0.296830, -1.068050, -0.313120, -0.876570, 0.810750, -1.196280, 0.500040, -1.657700, -1.131090,
1.725700, -0.918200, -1.230350, -0.710700, -0.191250, 0.954490, -0.225610, -0.954350, -1.882370, -0.831230,
-0.928370, -0.573890, 1.072320, 0.364880, -0.929840, -0.861980, 0.250110, -0.099520, -1.541630, 0.729580,
-1.644930, -0.801810, 0.296520, 0.687650, 1.331500, -2.034710, -0.294860, -0.906600, -2.686850, -1.135900,
-0.525390, -0.238380, 0.434590, 0.498420, 0.563120, -0.667360, -1.021330, -0.343010, 0.653590, 0.176110,
1.287970, 1.650020, 1.522130, 0.527210, 0.344410, 0.104730, 0.707510, -1.373240, 0.657530, 3.344500,
0.340790, -0.081190, 0.120290, -0.123670, -0.321180, 0.614920, 0.541240, 2.228320, 0.393470, -0.693870,
0.973320, -0.888360, -2.089690, -1.748300, -1.073750, 1.155970, -0.911750, 1.429240, -0.187780, -0.493390,
0.818430, -0.132330, 0.406770, 0.374030, -0.696240, 0.480950, -1.132560, 0.240730, -0.407500, -0.321750,
-1.396540, -0.023210, -2.766120, -2.157140, -0.658540, -0.709230, 1.479440, -1.217060, -1.170190, -0.843170,
4.761320, -0.778780, -0.213820, -0.379020, -1.276790, -0.193050, -1.709000, -0.157290, -1.204370, 0.168620,
-3.090010, -1.394930, -1.164490, -1.172630, -0.278560, -1.018290, -1.190770, -1.176220,
-0.972680, 0.583580, 1.540770, 1.183100, 0.994370, -0.362860, -1.177910, -1.374050, 0.268260, 0.172780,
2.371920, -0.770420, 1.270120, -0.518340, 0.630880, -1.019520, 1.510710, -0.272160, -1.814640, -0.328300,
0.282950, -0.599810, 0.333940, -1.523460, -1.448380, -1.701310, 0.021680, -0.611070, 0.079240, -0.042030,
-0.627130, 0.230110, 0.383360, 0.282370, 0.817370, -0.958490, -1.496360, -2.483950, 1.899560, -0.270220,
-7.042620, 0.891370, -0.189440, -1.381840, 0.256220, -0.284070, 0.636040, 0.013910, 0.593220, 1.304440,
-0.498970, 0.548880, -0.089590, -0.495650, -0.919460, 0.355350, -1.528980, 0.745200, -0.757530, -3.428890,
-0.745800, 0.279050, -0.238000, -1.955000, 2.012210, -0.869770, -2.201550, -0.812130, -0.340550, -1.141380,
-0.438660, 0.569320, 3.254990, -0.352310, 0.902500, -0.780530, -0.061260, 0.680540, 2.227430, -1.921210,
-1.620180, 1.422880, -0.432500, 0.595980, -0.792020, -0.836300, -0.532460, 1.804700, 2.389120, -0.185280,
-0.960190, 0.651740, 1.524290, 2.125660, 1.277590, 0.725420, -1.278570, -0.374580, -0.136180, -1.228860,
1.142210, 0.965860, -5.339230, -0.393950, 1.310630, 1.014570, 0.431800, 0.410420, -0.516590, 0.397940,
1.363590, 0.330430, -1.897690, 0.137010, -0.429780, 1.622900, 4.411910, 0.625320, -1.701980, -1.201770,
-1.022020, 0.969620, -0.235750, 4.678870, -1.467190, -5.594460, -0.509720, -0.996720, 0.898720, 0.174500,
-2.021900, -0.413090, 0.357710, 2.704920, -0.348850, 1.448980, -0.895260, -1.736520, -0.018940, -0.166060,
-0.278350, 0.476160, -0.530430, 0.308040, -1.764740, -1.025240, 1.596250, -2.160230, -2.559740, -1.792950,
-1.379530, 0.796550, -0.799200, -2.709760, -1.998730, 2.115010, 0.562710, -0.310920, -0.298730, -0.387750,
1.490670, 0.498260, -0.269650, 0.384630, 1.976520, -1.969220, 0.061430, -0.289060, 0.205470, -0.694040,
-1.429330, -2.664450, -1.631270, 0.320860, 1.831850, -0.446950, -1.033760, -0.241210, 1.049990, 1.621690,
1.210220, 0.659070, -0.872110, 0.034930, 0.526230, 0.193900, -1.205320, 1.209350, 1.033200, -0.810280,
1.048580, -0.440960, -3.310340, 1.081060, -3.512590, 0.877580, 0.213630, 0.693930, 1.825490, -0.398350,
-0.064140, 0.021070, -0.035150, -0.640650, 0.672270, 0.688300, -2.150110, -0.850730, -0.223260, -0.579490,
1.194220, -1.892560, -0.816790, -0.496300, -0.040420, 1.764650, -0.994870, -1.269600, 1.511560, -1.093490,
0.794570, 1.765540, -0.148820, 0.629580, -0.331350, -0.596130, -0.270940, -0.890410, 0.814900, -0.328820,
-0.191250, -1.337660, -0.828000, 1.312590, -1.993110, -0.600430, 0.441110, -2.352860, 0.372560, -0.410820,
-0.918440, -1.165540, -0.410520, -1.025130, -0.679430, -1.911500, -0.671490, 0.593710, 0.567580, 1.316340,
0.744560, 0.004410, 0.073960, 0.320550, -2.946030, -0.217950, 2.684830, -1.982790, -0.875270, -0.449720,
0.272800, -0.777710, 0.396870, -1.471690, 0.186060, -0.009180, 1.149620, -0.827980, 0.965610, 5.266080,
-0.069660, 0.784290, -0.916710, 0.876500, 1.068850, 0.865940, 3.114010, 0.425960, 0.206070, 0.709190,
16.590139, 0.250790, -0.739180, 1.102460, 0.221200, 1.755710, -0.104020, -0.050500, 0.907330, -0.183290,
0.248310, -0.298000, 2.183060, 4.802350, 0.599070, 0.953560, -0.230770, 2.579280,
-0.591790, -0.632510, -0.308880, -0.042620, -0.284040, 0.079090, -1.369770, -2.077890, 0.578540, -0.432710,
-1.053380, 0.519110, 0.284240, -0.824120, 1.587900, -1.070170, 1.505040, -0.634490, 1.430270, -1.201460,
0.597590, -0.303620, -0.325490, -0.678360, 0.545220, 0.801800, 0.738350, 0.804150, -0.530910, 0.882450,
0.076550, 0.196320, 1.773180, -2.472930, 1.074480, -2.318520, 0.238530, -0.590950, 0.245730, 0.307710,
0.396730, 1.157350, 0.471670, -0.170060, -0.931910, -0.389040, 0.614410, 3.596940, 1.932320, 0.154880,
0.467890, 0.221820, 0.668300, -0.828130, 0.090860, -1.911050, -2.442390, -0.897980, 0.443240, -3.899720,
-1.134410, -0.077130, -1.114120, 0.527680, 3.133710, 2.152860, 0.071330, 0.236150, 0.668240, 1.272590,
2.724280, -1.027820, 3.684460, 1.165210, 1.137680, -0.329970, -2.016190, 0.941200, -1.929220, -1.487830,
-0.389950, -0.497660, -1.271100, -1.614180, -0.230710, -0.091800, -1.071320, 0.222460, -0.080830, 1.206610,
0.558470, -2.264350, 0.841520, 1.059540, -0.708300, 4.299550, 2.210190, 0.240790, 0.741900, 0.305820,
1.578400, 2.973510, -4.898660, 0.467640, -0.712440, 2.689880, -0.943260, -0.311300, -0.210850, -0.742150,
4.476900, 0.719220, 2.840350, 0.860690, 1.818430, 0.557680, 0.226440, 1.054740, 1.062340, -0.262050,
0.088700, 1.422480, -0.036300, 0.571330, 1.626060, -1.912600, -0.801160, 0.991270, -0.332700, 1.398310,
0.229380, -0.662200, 1.014380, 0.017260, 0.526360, 3.085360, 0.028400, -0.631160, -0.109960, -0.084300,
1.321700, 3.103710, 1.066130, -1.913060, -0.185070, -0.742700, 1.688470, -0.571670, -0.471490, 1.177720,
0.102920, 0.337610, 1.261160, -3.503240, -0.317420, 0.049960, 0.121140, 1.271170, -0.386870, -0.221630,
0.142220, -0.512070, 0.326900, 0.605170, 2.326970, 0.433740, -0.970050, -0.718110, -2.383830, -0.338770,
2.776050, -6.678720, -1.349040, -0.641450, -0.451030, 1.228470, -1.783170, -0.441910, 3.241870, 1.524720,
1.773490, -0.453840, 0.842410, -0.190690, -0.113940, -0.769810, 0.547550, -0.015160, -2.324460, 0.781520,
-1.957660, -1.885020, 0.661780, 1.826960, -2.621200, -0.219030, 0.298460, -1.066740, -0.043820, 0.244100,
0.631040, 3.690520, 1.473410, -1.842010, 0.242050, 0.516700, 0.489050, -0.124280, 0.719720, 0.798250,
0.667220, 0.627340, -0.875920, 0.999140, 1.203190, 0.749150, 1.555050, -0.052650, 0.304710, -0.714000,
-1.700130, 0.232850, 0.759560, -0.168250, 0.652730, 1.129760, -1.417740, 0.129510, 0.724580, -1.747110,
2.149830, 0.781460, 2.364660, 2.325010, -0.398550, -0.128510, -0.019040, 0.434830, 0.177500, 2.585710,
0.570260, -0.177400, -0.794050, -1.618850, -0.878040, 0.316990, 0.960470, 0.272310, 0.575940, 0.132740,
-0.824580, -0.973730, -0.572730, -0.403220, 0.284000, 0.741660, -0.900570, 1.812330, -1.122730, 1.380090,
-1.373230, -1.341220, 1.426840, -1.138230, -10.055040, 1.828650, -0.828900, 0.389490, 0.563920, 0.472810,
-0.231120, 0.381450, -0.267250, -1.221000, -0.629310, 0.124630, 0.667560, 0.393840, -0.514870, 0.384100,
1.347880, 0.372700, -0.288520, 0.005860, 0.919820, -0.392880, -0.102940, 0.892290, 0.349220, -0.096290,
0.559120, 0.352860, -1.656140, 0.694910, 0.362740, -0.920800, -0.387190, -0.519510,
-0.035000, 0.670520, 1.503830, 0.647850, 0.328600, -0.458040, -0.130000, 0.179940, -0.543880, 0.452200,
-0.516480, 1.818420, -0.244660, 2.200110, 1.081940, -1.098150, 1.337360, 0.002670, 0.500210, 0.501540,
-1.163010, -0.105480, 0.575580, -1.034410, 0.833870, 0.101950, 0.036300, -1.191310, -1.149140, 0.853060,
0.647870, 0.454350, 0.294550, -0.210280, 0.560560, 0.500090, 0.574510, 0.832570, 0.553170, 0.425880,
-0.048270, 1.213720, -0.971380, -0.237850, 0.612630, -1.090700, -1.226650, 1.617840, -0.047780, -0.901860,
-1.500520, 0.402430, -2.091120, 0.264890, 0.645090, -1.107890, 0.448350, -0.777840, -2.284520, -0.759390,
0.333480, -1.988050, -0.759660, -0.155820, 0.888630, -0.299410, 0.834610, 0.809060, -0.909760, -0.163290,
1.642140, 0.953090, 1.747060, -0.182550, 0.327350, 0.066720, 0.787450, -1.214410, -0.990060, 2.051460,
-0.281040, 0.328330, -0.522040, 1.142210, 0.049120, 0.613520, 0.089950, -1.843830, 0.417740, 0.025820,
-1.156820, 1.473890, 0.392240, -1.755930, -0.182950, -2.608650, 1.933490, 0.334360, 0.391530, -0.275150,
-0.357070, 1.251270, 0.696380, 0.028820, -0.886400, -0.610100, 0.519150, 1.084650, -2.966580, 0.072590,
-2.891380, 0.113310, 0.695430, 1.497530, -3.168570, 2.006030, 2.298210, 0.304790, -0.513600, -1.748680,
-1.548190, -0.501540, -3.534240, -0.665070, -2.213810, 1.512350, 1.337900, 1.127530, 2.040740, -0.138590,
0.549490, -0.810860, 0.911150, -1.193300, 0.022040, -0.179610, 2.406490, -1.091370, 4.632140, 3.757890,
-0.347480, -5.873060, 2.174680, 2.758070, 1.523030, 1.130270, 2.036630, -1.667510, -5.598230, -0.557430,
-0.612460, 2.116540, -0.937060, 0.236030, -2.169720, -0.452730, -0.090660, -1.076520, -0.163250, 1.848650,
-2.042090, 1.001180, 9.595500, -6.219800, -1.641210, -0.270670, -1.121540, -0.041190, -0.447790, -0.416620,
-4.693330, 0.847750, 0.646180, -0.279840, 4.129900, -0.545470, 0.509620, 0.267000, -0.705340, -0.857670,
0.802530, 0.452570, -1.558730, -2.432310, 0.651970, 3.377260, 0.580410, -3.959990, 1.428610, -0.004230,
-0.572620, 2.142820, 0.506210, -0.145390, 0.777740, -0.488660, -1.002930, 3.181600, 1.781010, 0.136810,
-0.166360, 0.192070, -3.774520, -1.543310, 0.885130, -0.814670, -1.586910, -0.626370, 4.559610, -1.588460,
-1.281980, -0.517760, -0.110210, -0.565710, -0.810300, 1.746740, -0.978130, -0.030830, -0.195800, 0.099170,
-0.001910, 1.441920, 0.205970, -0.394960, -1.181380, -0.572750, 0.963040, -0.352980, -0.344080, -0.343060,
-0.078820, 1.524730, -0.352280, -1.766800, -1.325190, 3.220960, 1.216020, 1.429690, -1.172150, 1.354940,
1.917190, -2.009440, 1.856660, 1.371800, 1.342660, 0.784000, -0.144490, 0.919820, -0.501850, -1.408730,
-0.285300, -0.769310, 0.441130, -0.540710, 1.268710, -1.514620, -0.418790, 0.010280, 0.413550, 0.731280,
0.316080, -0.405630, 1.241660, 1.000850, 0.127810, -0.661120, 0.866520, 0.470010, -0.732860, -3.007860,
-0.678410, -0.072810, 0.885080, 0.952950, 0.316150, -0.322390, -1.993640, 1.103700, -0.725010, 0.365510,
-2.580750, -0.005270, 0.063280, -0.502900, 0.238730, 0.700200, 0.566710, 0.097340, 0.134560, -0.299980,
0.628580, -0.655540, -1.247910, -0.192020, 0.966120, -0.275450, -0.663310, -0.594160,
-0.158550, -0.600200, 2.105200, 0.170700, -0.677540, 0.162290, -0.119690, 0.166520, 0.152590, 1.972280,
0.991190, 0.120760, 0.139560, 1.385100, 0.299140, 0.591350, 0.027340, 1.222950, 1.675780, 0.610370,
0.773380, -0.371160, 0.364150, 0.965750, -0.692260, -0.371450, 0.424350, 0.466450, 0.825210, -0.122500,
-0.815890, 1.842270, -1.004380, 0.155140, -1.022600, -0.107870, 1.035810, -0.306620, 1.658940, 0.052860,
-1.956210, 0.524140, 0.020470, -0.074740, -1.387570, -0.729320, -0.546070, -0.388860, 0.852910, 1.775600,
1.097180, 0.141580, 1.183410, -0.163950, 3.607070, -1.581820, -0.957570, 0.036780, -0.402120, 1.108200,
0.082420, -0.155510, -0.247730, 0.748150, 0.886380, -1.309070, 0.716150, 0.148240, 0.996160, -0.133740,
0.642460, -1.579670, -1.793320, 1.058020, 1.199140, -0.610540, 0.176020, 1.325920, 2.575110, -0.702690,
-1.350080, -1.381540, 0.332620, 0.946920, 0.179520, -0.961740, 1.950410, -0.582270, 0.111690, 0.211970,
2.183540, 0.071760, 0.629170, -1.020900, -0.602980, 0.267860, -0.514710, -0.492860, 0.787330, -1.128460,
-0.250230, -0.159680, 0.975900, 1.223450, -0.560690, 2.177000, 0.350650, 0.345260, 0.042150, -0.253870,
-0.029830, 1.107340, 0.506420, -0.263090, 0.696530, 1.170490, 0.686250, -0.936540, -0.491360, 1.029110,
-0.139490, -0.299880, -0.235830, 0.098770, 1.377740, -0.741680, 0.571810, -0.422560, -0.840560, 0.254240,
0.288880, -1.161810, 2.215910, 0.570620, 0.988220, 0.580390, -0.325700, -1.121070, -1.815210, -1.358110,
-0.970460, 2.321940, 0.551730, -0.252210, 1.067340, -2.459960, -2.525550, -1.254210, 0.368280, -0.515450,
0.753410, 0.651710, -0.875250, -0.252070, -0.836650, -0.613570, 0.571890, 0.614370, -0.853430, 0.385200,
0.969690, -1.076310, -1.637920, 0.617170, -1.080900, -1.777120, -1.115750, 0.700510, -0.373310, 0.067700,
-0.393820, 1.835930, 0.175890, -0.441460, -1.153610, 0.240560, -0.087540, 0.023470, 0.905300, 0.323900,
1.111910, -0.366130, -0.238770, -0.790740, -1.560600, 0.551520, 0.429100, -0.500710, -0.572830, -0.467120,
0.984100, -1.762030, 0.766400, -0.111660, 0.394860, -2.304620, 1.280970, -0.812060, 0.520000, 0.373480,
-0.643820, 0.221290, -0.637370, 0.130010, -0.942800, 1.036670, 0.021630, -0.338860, -1.518190, -0.427550,
-1.062720, 0.488980, 0.600170, 0.886280, -0.886890, -0.016800, -0.740680, 1.773160, 0.256770, -0.353730,
-0.965110, 0.371330, -0.234830, 0.960710, 0.232790, -0.777640, 0.515430, 0.121660, 0.575090, -0.065860,
-0.018690, 0.579660, 0.662310, -1.132990, -0.516340, 0.433510, -0.356590, 1.329010, 0.668690, 0.881880,
-0.455240, 0.251870, 1.509410, 0.275450, 0.021990, -0.301470, 0.373980, 1.653780, -1.503820, -1.441060,
1.021720, -0.013320, 0.096000, -0.297460, -0.076850, -0.506240, -0.411840, -0.634960, 0.029660, 0.899940,
1.258120, 0.387510, 1.150540, -0.311140, 1.135230, -2.062880, 0.531230, 0.542010, -0.545510, -5.776040,
-1.246550, -1.994570, 0.305860, -1.205160, -0.320620, -1.050880, -5.432120, -0.556340, -0.988640, -1.443280,
-4.820180, 0.393680, -0.586820, -2.448500, -0.061790, -2.717310, -0.369860, -0.859910, 0.359320, -1.651570,
-1.395480, 0.223690, -2.984080, -1.719950, -1.643670, -0.516480, -0.212000, -0.357850,
1.428760, -2.905060, 0.807100, -0.260910, -0.512520, 1.035730, -0.113900, 0.616710, -0.663960, -0.660460,
0.497660, -1.709700, 0.403670, -1.213650, 0.267700, 1.111300, -1.534140, -1.142040, 1.103010, 1.421740,
-0.078930, -0.364900, -1.288320, 0.207830, -1.687220, -0.540140, 0.169750, -1.625470, -0.164190, -0.153700,
-0.860080, 1.545570, -1.192050, -1.310320, 0.624900, 0.480440, 2.968690, 2.229430, 0.356150, -1.243220,
-1.369260, -0.535760, 1.338800, -0.507130, -0.482710, -0.279510, -1.682990, 0.036940, 0.177090, 1.343730,
-0.166950, -0.400390, -0.502890, -1.013930, 2.663290, 0.974600, -0.969610, -0.818620, 2.920420, -2.012600,
-1.881650, -0.284450, -0.048430, -0.039280, 0.120930, -1.767690, -1.642340, 0.798980, -0.627890, 1.281330,
-0.041670, 0.090380, 2.354800, -0.360090, 2.464590, -1.160390, 0.697000, 4.774690, 2.294660, -2.914980,
-0.032590, 2.136300, -0.390130, -0.435950, 0.604500, 0.406720, 1.633610, 0.410730, 0.422910, -1.399640,
-0.867890, 0.537010, -1.493010, -1.651530, 1.284610, 5.549610, 0.754930, -0.929280, -0.189070, -3.078040,
0.995270, -1.310040, -1.488010, 0.913220, -0.251380, -0.285160, -1.042550, 0.998720, 0.606780, -0.412780,
0.298720, 2.033620, 0.143650, -0.172590, 2.695620, -0.367660, -2.341360, -1.526660, 2.063480, -0.040870,
2.569400, 0.258090, -1.357060, -0.232090, 3.733580, 0.934630, -0.574070, 0.816380, -0.290400, 0.000460,
0.782680, -0.431340, 0.816710, 0.372390, 1.560930, -1.112380, -0.800140, 2.737170, -0.823850, -3.692740,
0.012590, 4.537660, 0.367850, -1.101840, 0.748100, -1.559060, -6.551410, -1.073240, 1.319320, 2.038360,
-0.077110, 1.885600, 0.082040, 1.368210, 1.340840, -0.130220, 0.417220, 3.345450, -1.326080, -0.523510,
-0.438690, 0.866090, -3.733910, -0.213070, 3.361490, -1.240010, -1.216410, 0.546760, 0.175420, -1.370750,
-1.403150, -1.052140, 1.452660, 2.824250, -2.198550, 1.373360, 0.566510, 5.499170, -0.605980, 2.059540,
3.056100, -0.819380, -0.054220, 0.444290, -0.299730, -0.181900, -0.860790, 1.320070, 0.416750, -0.359880,
0.094830, 0.189330, -0.523330, -0.151710, 0.772760, 0.835020, 0.300710, -0.738170, 0.204790, 0.364610,
2.148840, -0.446060, -1.148550, -0.293820, 0.338920, -1.391930, 0.123800, 0.863440, 1.396070, 0.905980,
-1.134630, 0.043660, -0.462600, 1.186110, -1.126020, 0.198230, -3.623080, -0.108990, 0.205250, -0.827820,
-1.119970, 0.846030, -0.051520, -0.496110, -0.342980, 0.010900, 0.662900, 0.501840, 2.032900, 0.415840,
-0.341230, -0.746680, 0.075150, -0.374670, -1.933410, -0.575530, -0.664340, 1.341940, -0.642590, 0.035360,
-3.176410, -0.911150, 0.173130, 0.153770, -0.941500, 1.764760, 0.475610, 1.380010, 1.717570, 0.485250,
0.402650, -0.187010, 0.277750, -1.658750, -0.752760, -1.176540, 1.076780, 0.551740, 0.328410, -1.561260,
-0.671280, 0.658150, 1.576530, -0.772250, -2.779450, 0.375810, 0.388520, -1.285490, 0.803370, 1.577800,
0.240580, 0.464740, 0.565770, -4.774840, 1.494060, 1.654250, 1.617850, -0.297860, -0.372630, 1.945750,
11.240740, 0.705730, -1.069840, -0.446300, -0.808990, 0.810020, 0.783100, 0.279050, -0.166050, 0.246150,
-0.237940, -0.452200, 1.537810, -0.077980, 0.741440, 0.057450, 0.503560, -0.492640,
0.309770, 0.187330, 1.356930, 1.093370, 0.851090, -2.092620, -0.523800, 0.516420, 1.604660, 0.568490,
-0.904960, -1.268040, -2.424300, 1.081680, -0.181920, -0.832250, 0.095390, -0.132880, 0.531320, -0.010920,
1.521510, -0.625200, 1.928240, -0.119220, 0.640940, 0.942210, 1.433010, 2.855830, 0.324780, -1.201880,
-0.113500, 3.151240, 1.779060, -5.940660, -0.233340, -0.513580, -0.029480, 0.446670, -1.654620, -1.820940,
0.475520, -0.383300, 1.538540, -1.459620, -1.607800, 0.329930, 0.003920, -0.359290, -0.927770, -0.740580,
-1.026400, 0.246530, 0.801690, 0.641200, 1.343000, -0.487170, 0.143870, -2.244730, 0.016630, 0.819440,
0.147650, 0.519820, 0.500950, -0.698840, -0.969330, -2.991100, -0.731460, -0.049320, 0.266790, 0.280540,
-0.974980, -0.513160, 2.400000, 3.897850, 0.318960, 0.099330, -0.383670, 0.725790, 2.970060, -0.453990,
0.754780, -1.321230, -2.029210, -0.099430, -0.773450, 0.426750, 0.355880, -0.925920, -0.907950, -0.976800,
0.490360, -1.353160, 1.053840, 0.289680, 1.901320, 0.008250, 1.245550, 0.834840, -0.207860, -0.389070,
1.093470, 1.592170, -0.817350, -1.702090, 1.711730, 0.542670, -0.702000, -1.522210, -2.224020, 1.425050,
2.943540, 0.091580, 0.390770, 0.209200, -0.229150, 0.827520, -1.175430, 0.283100, -0.365030, 1.119280,
0.639890, 0.404700, -1.157880, 0.494050, 0.707120, -0.123510, 0.388610, 0.710710, 0.610650, 1.040620,
-0.476720, -0.606500, -0.802060, 1.706440, 1.135780, -0.600520, 0.389670, 1.439690, 2.400930, -0.477180,
-2.277490, -0.489930, 1.678190, -0.098910, 1.882520, 1.556750, 0.839760, -1.012050, 1.352020, -1.317830,
-2.166150, 0.192280, 0.564170, 0.930990, -1.168480, -0.868250, -0.074400, -0.016560, 2.221810, -0.202770,
0.816000, 0.144270, 4.510160, -0.195510, -3.434450, 1.476410, 0.629020, -0.546720, -0.671600, -1.009360,
-0.852090, 1.127710, -0.709290, -0.022290, 0.472310, 0.841190, -0.036620, 0.632420, 0.389250, -0.344280,
-0.679460, 1.138410, -0.292230, 0.028720, 0.610110, 2.333180, -4.355760, -1.111880, -0.800150, 1.912820,
1.189780, 0.466100, 0.385710, -0.395820, 1.114450, 0.460390, 0.522650, 0.168420, -2.482360, -1.567380,
0.230310, 0.755940, -0.425880, -0.956680, 1.638090, 1.847180, 0.806970, -1.559300, 3.297700, -3.005990,
-3.259710, -2.666760, 1.293210, 0.541360, 1.465670, 0.956950, -0.309400, -0.591830, 0.061460, -0.524730,
-1.802420, 0.663250, 0.585630, -0.638050, -1.750320, 1.218960, -1.120670, -1.424370, -1.450150, -0.243680,
-0.927530, 1.261560, -0.787560, 0.017700, 0.814480, 0.332880, 1.577440, 0.698950, 2.645610, -0.583980,
-0.148130, 0.351030, 0.682380, -0.484990, -0.422990, -0.758110, 2.187010, -1.558040, -1.083570, -1.245770,
-0.263460, 0.332670, 1.116230, -0.490090, -0.010270, -0.926130, -0.547630, -0.158400, 0.347870, 0.056190,
2.492650, -0.241610, -0.451230, 0.463670, 1.217900, -0.524140, 0.114760, 0.083430, 0.146400, -0.681970,
0.645170, 0.865100, -0.740740, 0.624530, -0.092470, 0.040540, -0.047350, -0.872490, 0.078360, -0.828200,
-4.155210, -1.781830, 1.246190, 2.430610, -1.099270, 0.469650, -1.131720, 0.197840, 0.176460, 0.105060,
-0.544150, -1.184450, 3.137960, -1.764270, -0.325970, 0.891170, -0.160990, 0.446980,
-0.922030, 0.126170, -0.493330, 0.249570, 0.242700, 0.072220, 0.083160, 1.292320, 2.734380, 0.382530,
-0.078900, -0.385350, 0.259690, 0.422760, 0.108010, 0.235300, 0.287630, 0.594850, -1.123260, -0.807620,
0.702260, -0.294690, -0.577500, -0.577990, 0.045230, 0.835000, -0.775980, -0.236950, -0.600560, 0.784720,
0.969120, -0.599020, 0.463780, -0.830430, -0.703070, -1.222540, 0.956850, -0.386460, -0.318480, 0.744320,
-1.142730, -0.685490, -0.385230, -0.347110, -0.610820, -0.138910, -0.773040, 0.693640, -0.410120, -0.466530,
-1.252990, -0.113400, 1.157800, -0.019530, 0.013130, 0.373330, -0.450190, 0.055920, -1.225530, 0.149910,
-0.272810, -1.067100, -0.664940, 0.006630, -0.772650, -0.302320, 0.451110, 0.451400, 0.224160, 1.762530,
0.072570, 0.695890, -0.432280, 0.248990, -0.295610, -0.038150, -1.868850, 1.435260, -0.115690, 0.546590,
-0.101090, -0.970340, 0.983360, -0.148410, -0.066510, -0.110780, 0.324980, -1.090700, 1.166110, 0.654610,
-0.667450, 0.649610, 1.163080, -0.102900, -0.365860, -1.206140, 1.377150, -0.121600, -0.776710, 0.376710,
1.532350, -1.399790, -0.645880, 0.313280, -0.580670, 0.987880, -1.588580, 0.718220, -0.016690, -0.218960,
-1.466720, 0.086180, -0.114090, -1.266360, -2.321740, -0.498810, 0.971260, -1.655320, 1.569510, -0.049150,
-1.090100, -0.237380, 2.158200, 0.081140, 0.235250, -0.833370, 0.056760, -0.578340, -0.459390, -0.837810,
-0.013460, -0.284580, -4.368390, -0.510830, 0.907260, -1.667520, 1.266630, 0.452900, 1.028360, 3.049800,
-0.864240, 1.118550, 1.597200, 1.982870, -0.182730, -1.717470, -0.550700, 1.100490, -1.725070, -0.720400,
1.601110, -2.274850, -0.611050, -0.188890, 0.021480, -0.366680, 1.258130, -0.528890, -0.723400, 0.324740,
0.658040, -0.213280, -0.763010, 2.312110, 2.650200, 1.452100, -0.387640, 0.212340, 0.473900, 1.836110,
4.349090, -1.985790, -0.705130, 1.460920, 0.495050, 0.670310, -0.964250, -0.909440, 1.944420, 0.303590,
0.490270, -0.267290, -0.269910, 0.077520, -1.841360, -2.184380, 0.664680, 2.810350, 0.862460, 0.296150,
0.023920, -0.688640, -0.303640, 0.979440, -0.780400, -0.109540, 0.166800, -1.635530, 0.469830, 0.251580,
1.306280, -0.238760, 1.038130, 0.741760, -0.638300, -0.782640, 0.475700, -0.540180, -0.629900, -0.093500,
3.185690, 0.204440, -1.057040, -0.203360, -2.169500, -1.016700, -0.838400, -1.553560, 1.113360, 0.165200,
-1.945740, 0.526170, 0.676500, 0.661320, -0.740110, 0.122250, 0.973620, 0.417330, 0.959870, -0.422480,
0.476060, -0.717520, 0.857670, 3.546660, 1.018630, -1.894550, -0.548680, -0.802620, 0.652640, 0.776500,
-0.659730, -0.905800, 0.274370, 0.678480, -0.318830, 0.146790, 0.168770, 2.103810, 0.015610, -0.681510,
0.732520, 0.015320, 0.878440, -0.556880, 0.959040, 1.054130, 2.127630, -0.024150, -1.610690, 0.579810,
0.513430, 0.533790, -0.153630, 1.676200, 0.403900, -2.027420, 0.228520, -0.193680, -1.134800, 0.476210,
0.141500, -0.208690, -2.447610, -7.030800, -0.286810, -1.329750, -0.562530, -2.104440, -1.289080, -1.046890,
-0.853200, -1.512700, -4.713670, -0.685830, -0.172300, -1.648580, -1.782470, -0.430780, -1.119840, 0.096510,
-3.031590, -2.939890, -0.865020, 0.758600, -0.805860, -1.025380, -0.047670, -0.944280,
0.321130, 0.863530, -0.787770, -0.362350, 1.288200, -1.134520, -0.428420, 0.904100, -1.141290, -1.127940,
2.231250, 1.084190, -0.514350, 0.471470, 1.117620, 3.618480, -0.675960, 2.447940, -1.485480, -1.819970,
0.826830, -0.285400, 0.190380, 1.284320, -1.442920, -1.626490, -1.687930, 0.437390, 0.189020, -0.520730,
-0.564360, 0.637600, -0.003170, -0.613650, 0.208780, -0.719190, 0.858710, 0.269360, -0.898710, -0.627660,
1.650940, 0.040710, -0.124360, -0.046210, -0.339130, -0.457860, 0.164770, -0.521580, 0.403940, -0.087120,
0.289770, -0.133190, 1.616190, 0.228830, 0.072160, -0.722010, 0.812380, -1.213430, 0.138570, 1.549940,
0.097730, -0.257780, 0.340630, 0.479440, -1.495690, 0.390240, -0.733970, 0.851330, 0.409440, 1.086680,
0.860040, 0.652870, -0.364140, -1.344780, -0.297260, 1.232800, 1.901430, -3.379490, -0.948060, 2.362160,
-0.941460, -0.149070, -0.214510, -1.594700, -0.795520, -1.112820, -0.648700, 0.595930, 1.933270, 0.801800,
0.323400, -0.134140, 2.716490, -2.452140, -0.958430, -4.161710, 0.642980, -0.461350, 1.000760, 3.599190,
2.787570, -2.249630, 2.336040, 0.197690, -1.026670, 0.707010, 1.963850, -1.277910, 1.174740, -0.723800,
-2.283270, 0.222530, 0.709750, -0.635230, -2.395040, 0.667220, 0.541370, 0.742800, -4.759200, -0.539600,
-0.135270, 0.473170, 0.372110, -0.642020, -1.003250, -0.456270, -0.210980, -0.681940, -0.522050, -0.108010,
1.034100, -0.626940, -0.454500, -3.390250, -2.151870, -0.345220, 0.678690, -1.333750, -2.690430, -0.073200,
-0.301110, -1.100080, -1.502740, -0.504110, -0.575330, 2.496950, -1.785410, 0.905460, 2.192040, 0.835990,
0.025710, -2.320510, -0.176790, -1.619240, 1.057330, 0.063640, -1.195120, -0.487800, 0.185750, -1.266720,
-0.037250, -0.510110, 1.298140, -3.431270, -4.015110, -0.376320, 0.182150, 0.171380, 1.270150, -0.853230,
1.549470, 1.075030, -0.872610, 1.363020, -1.451350, -0.443230, -1.071760, -0.465740, -2.259280, -1.473500,
0.017620, 1.325170, -0.873110, -1.795830, -0.313300, 1.800010, 0.038550, -3.634110, 0.619370, 0.737790,
-0.993700, 2.126860, -0.012200, 1.377220, 1.842050, 0.289550, -1.421120, -0.301540, 0.694960, 1.225230,
-2.712390, -2.238560, -4.278380, -1.681300, -0.837020, -3.551820, 1.152660, -1.274690, 0.387040, 1.323210,
-4.522380, 0.228460, -0.959310, -0.080600, 1.685760, -0.878050, 0.526490, 1.881000, -0.638340, -0.127150,
0.349380, -0.607220, -0.657740, -1.035650, -1.478270, -7.176540, -0.790670, -1.280580, -1.084410, 0.117060,
0.427630, 4.755180, 1.879820, -1.356500, 0.506840, 0.559120, 0.747040, 2.627200, 0.569640, 3.264320,
0.239350, -0.198380, 0.104360, 0.237660, -0.945810, 2.220190, -1.647290, -0.433540, -2.796820, -2.380170,
-2.189260, 0.027110, -2.093110, 2.591200, 0.887360, 0.557400, 0.524720, -0.043470, -0.599690, 0.812280,
0.530430, 0.620280, -0.670950, -0.103790, 0.563030, 2.015900, -1.153630, -1.240630, -0.087540, -1.413090,
-0.143930, -0.613360, 0.724440, 3.728650, 0.532750, 0.663420, 0.222280, 0.383270, -0.312570, -0.970760,
-4.318340, 0.257740, 0.617440, -1.136930, -0.394700, -0.919120, 0.635980, 0.618620, 0.787260, 0.994260,
1.355450, 0.731680, 0.527350, -1.227400, 0.139350, 0.905920, 0.304870, -0.411630,
-0.762200, -0.456370, 1.535460, 3.128260, 1.602920, 0.941120, 0.421810, -0.392770, -0.535070, 0.344490,
-0.572360, 0.488920, -0.945880, -0.439860, 1.510870, -0.557500, -1.629930, 0.123850, -0.097020, 0.108040,
-0.008020, -0.246940, -1.537680, -0.038440, -1.115520, 0.634900, 2.749770, -0.496560, 1.304220, -0.819550,
-1.913680, 1.325690, -0.708730, -0.003760, 0.043610, 0.134220, -0.069540, -0.017240, -0.058230, 2.163090,
2.559370, -1.381160, 0.336940, -0.241370, -0.618200, 1.610010, -0.886590, -0.565280, 0.912240, 0.349730,
-0.402960, -0.242670, 0.471050, -0.439010, 1.092560, -0.520520, -0.872720, -0.115720, -1.325480, -2.707540,
-0.373850, -2.443380, 0.470350, -1.132720, 0.526130, -0.751080, -0.357510, 0.390480, 0.435150, 1.027620,
2.709120, 0.965640, -0.555790, 2.994730, 0.197710, -1.450300, -0.322970, 0.087830, -1.011900, -5.343430,
-0.887510, -1.768210, 0.817330, -1.128540, -0.064220, -3.492470, -1.010800, 2.571930, -0.416140, 0.282700,
-2.234090, -1.965660, 3.788630, 6.468420, 0.123710, 0.488500, 1.241700, 1.452480, 0.293000, -1.210750,
6.156500, 0.718040, -4.020000, 1.113820, -2.586010, 2.975210, 1.958520, -0.369530, 0.915750, 2.229440,
-0.105830, 0.637620, 2.089260, -1.779150, -1.872020, 0.879140, 4.668190, 0.884930, 0.818090, 0.076120,
-0.214440, -0.274890, -1.878120, 1.458190, -0.334510, -4.138790, -0.120050, -1.596690, 0.523860, 0.978420,
-1.343450, -3.728810, -0.854400, -0.183600, -0.968210, 1.443250, 0.486160, -0.540880, -0.815210, 1.832330,
-3.207940, 0.891170, -2.531560, -1.744710, -1.807070, 0.003380, -0.667800, -3.331570, -4.372520, 1.486140,
-1.001940, 2.501090, -1.387990, -1.228360, -0.842150, -1.933130, 1.470920, 1.480110, 0.098110, 0.670320,
-1.151210, 0.401830, 5.312010, 0.529710, -1.263680, -0.056880, 1.413890, -2.199140, -0.479380, 0.460820,
-1.963760, -1.005930, 1.046510, -0.379560, 0.550570, 0.189190, -0.766020, -0.794020, 1.576540, -0.512850,
0.097970, -0.105880, 0.131440, -0.730910, -0.276710, 2.055090, 1.233710, -2.307980, 0.122200, 1.018210,
-0.258780, 1.533740, 2.789620, 0.827440, -1.220170, -0.007640, -0.384620, -0.645180, -0.012920, 0.520600,
-1.130260, 2.887360, -1.154790, -1.591320, 0.789750, -2.529860, -1.650400, -0.766780, 0.349630, 1.279070,
0.247210, -1.953720, -0.495590, 0.353900, 0.632010, 0.347870, 0.414370, 1.444420, -2.232680, -1.106940,
-1.544130, -0.066320, 1.094500, 0.105660, 1.149860, -1.424050, -0.158890, -0.273310, -1.195080, 0.367930,
-0.796410, 0.201390, -0.882900, -1.336850, 0.630950, -1.481110, -0.036060, 0.210120, -1.032640, -0.603410,
-0.957090, 1.372030, 0.288460, -1.050440, -1.057300, 1.185170, -0.086320, -2.403620, -2.092700, 0.914950,
-0.788470, -0.784200, 0.544080, 1.000210, 1.050520, 1.470050, -0.988200, -0.736220, 1.445340, 4.193370,
1.226420, 1.964200, 1.685160, 0.279290, 3.131200, -0.539060, -0.592590, 0.430670, -0.954360, 0.688450,
0.324720, -1.910510, 0.419210, -2.838220, -1.128820, 0.347710, 1.221620, -0.198500, 0.091700, -0.074720,
0.418650, 0.549400, -0.973540, -0.709810, 0.050930, -0.097170, -0.110040, -1.301700, -0.482450, -0.238830,
-0.846750, -1.438380, -0.049840, 0.654400, 0.414580, 0.093830, 0.655830, 0.027770,
-0.686860, -1.210740, -0.504160, -0.751810, -0.858270, 0.815740, 1.230690, -0.948760, 0.505850, -0.826710,
-0.863140, 0.360490, 2.059610, 0.321620, -0.241110, -1.439090, 1.371570, -1.846350, 0.640420, -0.210330,
-1.291760, -2.201480, 1.156840, -1.560440, 0.564540, -0.429510, 0.674250, -1.092720, 1.527890, -0.633740,
-0.200270, -2.951740, 0.890070, 0.231050, -0.600910, 2.207940, -1.419820, -1.185480, 1.121860, 0.626860,
-0.251930, 0.760480, 1.186450, -0.358160, -0.744290, -0.713950, -1.330910, -1.141780, 0.662290, 1.060930,
-0.599030, 2.719730, -1.057030, -0.131390, 0.198470, 1.354580, -0.167010, -0.097780, 0.151060, -2.793650,
0.320210, -0.081420, 0.465160, -0.390780, -0.117570, 1.251610, -1.066620, -0.725920, -0.868570, -0.376270,
1.438630, -1.422940, 0.838170, 0.302340, 1.549460, -0.014620, -2.450680, 0.172870, 0.162110, -7.330520,
-0.811320, 0.771390, -1.553140, -0.514810, -0.789890, 2.628190, -0.388190, 2.300070, -0.039960, 1.256100,
-2.012040, 0.404410, 0.878910, 2.568640, 0.738420, -1.294620, -1.858030, 1.008690, -0.606660, 1.457220,
1.537950, -2.212140, -3.975430, 0.186090, -0.061960, -0.445780, -2.249910, 0.133960, -0.764540, -0.765700,
3.413700, 5.021910, 1.534360, -0.429360, -0.612370, -0.374650, 0.907270, -1.404800, 2.327910, -0.200310,
0.083740, -0.963470, 2.779070, -0.574730, 0.507960, -1.908850, -0.064250, 0.753470, -0.361790, -0.215240,
1.003740, -0.999340, -0.799870, -0.107620, 2.165760, 1.629170, 0.939340, 1.091430, 0.435630, 0.878080,
0.443140, 2.416690, -0.776160, -0.968850, -0.125840, 0.906780, 0.413340, -0.682740, -6.127730, 1.322920,
2.168870, -1.358690, 0.288290, -1.822680, 0.688210, 0.293250, 2.476090, 1.269960, 2.020720, 0.097220,
1.893040, 0.464320, 0.664650, 1.203230, 1.167030, -1.339680, 0.187240, 1.097470, 0.477000, -0.330290,
0.420060, -8.741550, 0.440930, -1.180670, -0.298870, 0.018400, 0.934460, 0.544690, 1.232820, 2.102720,
0.632900, 0.416620, 1.293690, 0.728110, -1.002190, -0.710200, 0.402830, 1.499900, -0.408310, -1.453740,
-1.015150, -0.725000, 0.511720, 0.613730, -5.561880, 0.075010, -1.107880, 0.252610, 1.430810, -0.541590,
-0.390050, -0.213490, 3.948550, 3.632010, -0.821080, -0.152660, 1.420360, -0.252590, 0.092630, -0.462270,
4.709410, 1.354220, -2.274530, 0.416400, 0.769730, -1.937210, 1.169950, -5.154320, 0.080010, 0.386930,
-0.626280, -1.048380, -1.164070, 0.110920, -2.376870, 4.742230, 1.892650, -1.097110, -0.702380, 1.090990,
-1.800400, -1.078200, -0.065730, 5.813750, 0.901870, 2.065060, -2.638390, -1.716750, -1.912500, 1.172470,
-4.732000, 0.619410, -1.378620, -2.499650, -1.260400, -0.629740, 1.248810, 1.173120, 1.477560, 2.147960,
-1.864730, -0.283130, 1.300010, -1.960270, 1.451690, -1.097050, -0.264200, 0.299230, -0.807030, 0.995500,
-2.018350, -1.199910, 0.924510, -0.825380, -1.143060, -1.758310, 0.372620, 0.924650, -0.931870, 0.753340,
0.589010, 0.515150, -0.582990, -0.059930, -0.170010, 1.080120, 2.233180, -0.853840, -0.938080, -0.091530,
0.071850, 0.187900, -0.167590, 0.913760, 0.867520, -0.700120, -0.536650, 0.491220, 0.557940, 0.735210,
-1.488320, -0.158350, 1.753770, 0.773550, -0.839070, 0.224440, 0.098140, -0.312500,
0.182390, -0.171450, -0.617310, -1.276160, -0.151550, 0.238020, 0.295830, 0.513530, -0.527890, 0.156060,
-0.243060, -0.094620, 1.216790, 0.065400, 1.257040, -0.220500, -0.542490, 0.133460, -0.360360, 0.343040,
0.354560, -0.182550, -0.252930, -0.068220, -0.444450, -0.670360, -0.986380, -1.049380, 0.711330, -0.115110,
0.793790, 0.413390, 1.475970, -1.804460, -1.783600, 0.556650, -0.206260, -0.338120, 0.564890, -0.031510,
-0.072900, -0.073760, -0.322370, 0.774390, 0.011510, 0.119040, 0.001940, -0.075310, -0.052780, -0.514060,
-0.239240, 0.618750, 0.285200, -0.043280, 0.203310, -0.833070, 0.266440, -0.547560, -0.306170, 0.429380,
-0.221300, -0.170510, 0.301620, -0.713180, -0.067210, -0.547720, -0.627820, 0.139630, 0.264920, 0.102150,
0.737340, -0.259560, 0.201960, 0.054450, 0.047530, -0.727910, -0.457690, -0.720310, -0.860930, -1.501440,
0.934610, -1.255420, -0.833390, 0.566190, -0.634310, 0.729920, 0.128720, 0.194640, 1.286850, -1.448840,
-0.068770, -0.643640, -0.272490, 1.834600, -1.096740, 0.288720, 1.148200, 0.931050, 1.596430, -0.478390,
0.462070, 2.043850, -1.337830, -0.846390, 0.914420, 0.549730, 0.806960, 0.035120, 1.218820, 1.978910,
0.804020, -0.687050, 1.479760, 0.425690, -0.484730, 0.631150, -0.078270, 0.043840, 2.106060, -0.067510,
0.576730, -0.163160, -0.266530, 2.401570, 1.460690, 1.825070, 0.409720, -0.282860, -1.106430, -1.126800,
0.494240, -0.340860, 1.169910, -0.296180, -0.420880, 0.392380, -1.103340, -0.098530, -1.360000, 0.354280,
-0.535060, -0.111880, -2.022880, -0.298120, 0.544900, -0.047770, -1.054370, -0.491890, -0.821040, -1.028750,
1.173570, -0.200900, 0.480530, 0.782080, 0.860000, -1.103130, 0.770540, 1.065530, -0.752700, -0.444980,
-0.386970, 0.133880, -0.151540, -0.571560, 0.257870, 0.433610, -1.272000, 0.830350, -0.283840, -2.227180,
-0.407000, -0.233780, 0.087820, -0.190510, 1.551400, -0.592950, -0.187490, 0.502680, -0.541600, 0.898440,
0.224730, -0.279520, 0.608280, -0.490800, 0.847240, 0.942650, 1.345410, 0.004650, 1.049690, 0.522040,
-1.419630, 0.029330, 0.518840, 1.864860, 0.654380, 0.071620, 0.602390, 0.968290, 0.755440, -0.888390,
-0.316870, 1.151780, 0.523640, 0.630740, 0.229860, -0.242130, -1.467460, 1.019520, -0.822550, -0.539440,
0.914760, 1.217340, -0.496150, -1.258560, -0.599580, 0.554190, 0.241950, 0.288230, 0.190590, -0.190890,
-0.385080, -0.814450, 0.800210, 0.497380, 0.298470, 0.263990, 0.090150, 1.329610, -0.931870, -0.390440,
-0.702130, 0.615340, -0.009770, 1.330620, -1.049890, 0.271090, 0.675060, -0.297830, -1.047630, -1.201370,
-0.352450, -0.124710, 0.745690, 0.044300, 0.663580, 0.701740, 0.490810, -0.829090, 3.282960, 0.900290,
-0.561950, -0.152330, -1.724440, -0.310830, 0.858940, 0.277580, 1.024860, 0.399960, -0.170260, 1.800530,
0.290530, -1.334730, 0.603370, -1.176980, -1.104650, -1.127600, -0.774570, -0.140330, -0.941950, -0.176010,
-0.379260, -0.537670, -0.055980, -4.036020, 0.130360, -2.608000, -0.258960, -1.619350, -1.208520, -1.598640,
2.251420, 0.222420, -2.360780, -1.062450, 0.299620, -0.774160, -2.793080, -0.289590, -2.017630, -0.884980,
-1.349340, -1.735890, -0.318070, 0.511650, -1.645060, -1.302360, -1.335230, -1.316600,
1.007850, -0.542450, 1.863810, -0.483800, -0.501980, 0.054450, -0.738180, 0.120010, 0.279440, -0.011550,
-0.232340, 0.076370, -0.350410, 1.273620, 0.451290, -0.066310, 0.883490, -0.393460, -0.366220, -0.474080,
0.672410, 1.467720, -1.339880, 0.637750, 0.506340, 0.436490, -1.021160, 0.826690, 0.091420, 0.139230,
-1.267970, 1.176980, -0.553690, -0.533450, 0.752510, -0.157710, 1.028120, 1.090770, 0.824530, -2.274480,
1.204130, -0.124620, -1.285850, 0.834510, 1.303670, -0.423090, 1.331450, -0.086820, 0.226600, -0.325350,
0.881450, 0.372980, -1.412020, -1.026530, 2.458400, -1.690630, 0.988650, 0.236870, 0.095060, -1.086410,
-0.187330, -1.035170, 0.281790, 0.036200, -0.029740, -0.628200, 0.531630, 0.153420, -1.189390, -0.268200,
0.641980, 0.379480, -0.232840, -0.895220, 0.638270, -0.868570, 0.686040, -0.437970, -0.807740, 0.253090,
-0.564490, 4.041050, 1.410590, 1.000890, -0.029260, 0.341950, -0.000570, 0.816440, -0.236310, -1.183260,
-0.631200, -0.464040, -1.179170, 1.462790, -2.180000, -2.840260, -0.027370, -1.845070, 2.097770, 0.233060,
0.086830, 0.375060, -0.509260, 0.271700, 0.601140, 1.097800, 0.044220, -0.132380, 0.459340, -1.188680,
-1.084170, 1.063990, -1.205300, -0.597150, -1.867610, -3.094000, -2.426240, 1.164080, 4.237450, 0.748160,
-1.752740, -0.982920, -0.465260, -2.993470, 1.300310, 1.149950, -0.120860, 0.802250, -1.462680, 1.993770,
0.632500, 1.748820, -0.822520, -0.470940, -0.111900, 0.716080, -0.740780, 0.767650, -4.827890, -2.636260,
0.522050, 3.294210, 0.310610, -0.596620, -0.744350, -0.672870, 1.291460, 1.640780, 1.793800, -1.039070,
1.354500, -3.713230, -0.011040, 0.457640, 3.651180, -0.260020, -1.887030, -1.833950, -0.452660, -1.643190,
2.368410, 0.345040, -7.484480, 1.182730, 4.393060, 3.055060, -1.440290, 0.944830, 1.094330, -2.036710,
0.278850, 1.807760, 0.087130, 0.132920, -8.121740, 0.407010, -0.725190, 0.997050, 0.068010, 1.340250,
0.059700, -2.135830, 0.359800, 2.164950, 0.299290, -6.791270, 1.779500, 1.298910, 1.785110, -0.864200,
0.028710, 0.477840, -3.297510, 0.389540, 0.403750, 1.429980, 0.108680, -1.674740, -0.004600, 1.182470,
1.222480, 0.380490, -0.231830, 0.291250, 0.553060, 1.419300, -0.721760, -0.008550, -5.962760, 0.984640,
2.507100, 0.266850, -0.607520, 1.122350, -0.299060, -0.764740, -0.098330, -1.576210, -1.333150, 0.763090,
-1.016010, -0.115320, -0.041470, 0.627100, 0.852520, 1.373680, 1.032050, 0.183820, 1.863920, 1.088920,
0.274060, -0.832580, 0.061250, 1.288670, 1.378150, 0.780040, 0.767200, -2.257130, 0.519420, 0.882540,
-1.650020, 0.882800, 0.600410, 0.294690, -0.504510, 0.822500, 0.132580, 0.287150, 0.165560, 1.471780,
-0.323410, 0.115070, 0.303770, 0.504930, -1.416480, -0.636680, 0.368940, 0.463540, -0.762360, -0.526060,
-0.706490, 1.672160, 2.429640, -0.807720, -0.052910, 0.996640, 1.245720, 1.023060, 1.023710, 0.420880,
-0.858780, -1.654380, -0.483970, -0.081480, 0.158740, 0.581040, 0.679050, 0.223840, 0.871480, -0.039310,
3.513230, -0.812670, -0.155520, -1.221800, -0.066250, -0.057290, 0.499320, 0.684870, 0.113310, 0.202580,
-1.464930, -0.951030, -0.137160, 0.197370, 0.333900, -0.856570, 1.079210, -1.846170,
-0.858900, -0.025400, 0.259860, -0.284200, 0.253280, -0.884610, 1.806720, 0.418780, 1.081490, -1.016700,
0.552910, -1.777780, 1.688680, -0.480530, 0.010300, -0.935780, 0.914120, -0.788020, -1.488660, -1.319710,
-0.260390, -0.222180, 0.735510, -2.732840, -0.043490, 0.969500, -3.013750, -0.855320, -0.550950, 0.309280,
-0.115770, 1.912750, -1.818150, -0.135480, -0.472220, 0.157640, 1.548940, 0.605090, -0.128850, 0.274880,
1.051280, -0.413710, 0.495700, 0.697650, 0.070110, -0.318130, -0.150360, 1.943400, -1.011220, -0.727490,
1.365860, 2.413130, -2.611170, -2.421340, -0.399330, -0.387100, 0.034640, 1.721540, 1.598590, 0.132330,
-1.912070, -0.225320, 2.111670, 0.647570, -0.646760, -1.026450, 1.231980, -0.353630, -0.381160, 1.043130,
-0.406280, -0.253400, -0.622950, 1.762000, 0.509760, -0.190800, 2.172340, 0.010450, 0.556060, -1.619800,
0.541120, -1.928660, -1.543220, 0.603200, 1.330810, -0.428030, 0.288760, 1.891360, -0.227390, 0.800800,
1.243040, 0.576640, -0.411140, 0.614100, -1.064330, -0.987390, -0.878050, -0.535950, 1.588030, -3.303460,
0.487300, 0.968560, 0.454150, 0.034990, -0.273850, -0.358300, -1.432990, 0.821180, 0.875220, 0.123580,
1.545320, -0.149900, 0.163310, 1.024480, -0.176160, 0.272640, 0.089690, 0.147120, -3.314660, -2.395320,
-0.393970, 0.132680, 0.987360, 0.976480, -0.628960, 0.057060, -1.409120, -1.521670, 2.346350, -0.816190,
-0.785370, -0.886990, -0.484030, -1.521950, -0.115130, -1.459370, 0.506030, -1.584780, -2.133300, 1.639310,
0.618590, 0.670010, -0.541630, -0.540770, 1.295050, -1.185950, -0.946270, -2.216960, 2.878920, 1.153800,
1.562850, 0.015920, -0.955460, 3.453200, 0.010340, -0.081180, -1.153940, 0.198750, -0.813310, 0.356130,
-1.171100, 0.367830, 0.101720, 0.839340, 0.499710, -0.728660, 1.048570, -1.823580, -0.365950, 0.534060,
0.478840, 5.965480, -0.983490, 0.595640, -1.064440, 1.747200, -1.201460, -1.513610, 1.223030, -1.890720,
-0.774320, -0.680560, -2.131530, -0.436910, 0.234530, 1.246740, -1.998380, 0.040490, -0.222930, 0.371020,
0.126760, 1.051600, 0.118880, 0.074560, 1.790900, 0.492980, -1.352520, 0.464200, -1.404940, -0.386720,
0.825400, -1.593830, -1.264810, -1.179100, -0.680260, -0.195750, 0.028990, -0.341910, -0.214210, -0.647940,
0.201240, -0.774810, 1.425120, -0.605400, 2.123680, 2.373430, 1.445470, 1.623800, 0.454240, 0.690750,
-1.701660, 0.894390, 1.294010, -0.041540, -0.751650, -2.824340, -1.224490, 0.932660, -0.996370, -1.583860,
-0.673190, 2.444210, -0.380740, 0.045990, -0.907620, -0.367870, -0.586020, -1.690980, 0.450970, -0.075590,
1.149600, 0.836900, -0.783290, 0.656280, -1.124680, -0.986340, -1.841700, 0.382080, 0.174000, 2.931620,
0.064970, 0.353140, -1.380790, 1.528470, -0.169700, -0.498130, 0.113650, -1.713280, 4.816720, 0.586840,
-0.130200, 0.376710, -1.703220, 0.585970, 5.348550, -0.755080, 0.211860, -1.565960, 0.262020, -0.470520,
-0.302270, -0.107630, 2.310500, -0.877110, -0.548900, -0.049710, -3.698630, -0.688410, -0.452180, -0.629450,
-8.591810, -0.730810, 0.536090, -1.473440, 0.528440, -0.299050, -0.770610, 0.305590, 0.292560, -0.128930,
-0.474630, -0.353840, -3.866480, -1.725600, 0.047920, 0.145320, 0.965490, 0.370050,
1.925470, -1.652210, 1.031200, 1.864320, -1.523010, 0.385410, 0.204280, -1.177840, -0.076110, 0.937090,
0.856270, -0.579980, -0.429870, -0.629460, -0.813200, 0.955530, -0.209430, 1.204530, 0.559340, 0.030640,
-0.375770, 0.063300, 0.988560, -0.753620, 0.067390, 0.792720, 4.423700, 1.097460, 0.124560, -0.380160,
-1.406030, 1.126820, 0.182550, 0.095580, 0.894130, 1.261600, -1.363520, -1.392650, -1.372760, 0.995440,
-0.494390, 1.515510, -0.897660, -1.936110, -0.178010, 0.551200, -0.989660, 1.336220, 2.570000, 2.888230,
1.932730, 1.371700, -1.401010, -0.676360, 0.348500, 0.237950, -1.909390, -1.273470, 0.814260, -0.798770,
-0.545330, 1.045910, 0.190660, 2.928470, 5.930650, 0.059980, 0.944920, 1.095350, 1.080960, 1.422480,
-0.668560, -0.087160, 1.701490, 0.609790, 0.287970, -2.599390, -0.602990, 5.118570, -0.288500, -2.786040,
0.284720, -0.382670, -0.901980, 1.180550, -0.078760, -1.396200, 1.659700, 2.703590, 1.398170, 2.350200,
0.056890, -1.927640, 0.327550, -0.753160, 0.730520, 4.160260, 0.583180, -0.185780, -1.520580, -3.616750,
0.845480, 0.398570, -3.181950, -1.067390, -0.699100, -0.050500, -1.910910, 2.719140, -0.730590, 1.316810,
2.876390, 1.230220, 0.734600, -0.165490, 1.680570, 1.098110, -3.713310, 0.585560, 1.449280, 0.199480,
-0.955330, 0.210120, -1.454240, 0.696420, -0.799690, -0.913510, 0.974960, -1.232010, 0.206460, 0.224750,
-0.814120, -0.605450, -0.781240, 2.091430, 0.289410, 0.320020, 0.808040, 1.695440, 0.465180, -1.941600,
1.382760, 0.053920, 1.468200, -0.929270, -0.366540, -1.472470, 0.642460, -0.492060, -0.084510, 0.007190,
1.812970, 0.461460, 1.093980, -2.614280, 0.761910, 1.286710, 0.097530, -0.942670, -0.218460, 0.683140,
-0.652430, -0.987880, -0.044230, 1.904010, -1.111230, 0.555360, 0.312920, -1.177120, -0.677490, -0.613670,
-0.195770, -0.373810, 0.439340, -0.091940, 0.727510, -0.482040, 0.482630, -0.230630, 2.113510, -0.403030,
-1.729910, 0.947590, 0.769110, 0.133980, -1.941610, 0.142670, 0.694950, -0.567420, -0.538470, -0.920860,
-0.500810, 0.959560, 0.514800, 1.167200, 0.957000, -0.677420, -1.280770, 0.634730, 1.186810, -0.585930,
1.759380, 0.479110, -1.247230, -0.393110, 0.642710, 0.613150, 0.898150, -0.561600, -0.130080, -0.220240,
-1.120680, 0.936230, -0.560340, -0.017270, -2.219740, 0.318540, 1.875760, -1.629830, 1.656850, -1.690190,
-0.869030, 0.222470, -1.492100, 0.689510, 1.478720, -1.088110, 0.716640, 0.832260, -0.438890, 1.198130,
-2.571980, 0.908700, -0.284010, -0.180580, 1.159250, -0.575660, -1.068670, -0.481880, 0.750290, 1.286830,
-1.404510, -0.602410, -0.426600, 0.588200, 0.710070, -1.151390, -0.304180, -0.182610, 0.029280, 0.054350,
-0.172600, -0.826940, 0.694260, 0.319550, -0.493640, -1.823390, -0.431150, 1.262150, 1.027320, -1.427330,
-0.311020, 1.685490, 0.565380, 0.244170, -0.991080, 0.537560, -0.540110, -0.932120, 0.277270, 0.627730,
-0.782590, -1.250930, -1.917120, -3.690620, -0.801960, 0.447530, 0.693440, -0.783150, -0.564490, -0.755180,
1.103550, -0.885830, -0.634110, 2.279880, 0.100010, -0.838210, -1.083870, -0.417610, -1.954640, -0.341170,
-1.593720, -0.541250, -0.253190, -0.770670, -1.062150, 0.006880, -1.192700, -0.027280,
-0.815480, -0.632190, 1.809380, 0.708790, 0.806580, 0.061700, 0.243640, -1.737850, -0.447410, -0.040690,
-1.200610, 0.996430, -1.655410, -0.963030, 0.300910, 0.889020, -0.664820, 0.306380, 1.919940, 0.377380,
1.520630, -0.412070, 0.646730, -0.363320, -0.582250, 0.498750, 0.452540, 1.246490, 0.922900, 1.009180,
0.586010, -0.023320, 0.981240, 1.309600, -0.897510, 0.371310, -1.560820, 0.347860, 1.368880, -0.281530,
0.439730, 0.002810, 2.277650, -2.064010, 0.424250, 0.022060, 0.000450, -0.974550, -0.332250, -0.555920,
-1.232930, 1.574810, 0.411800, 0.469850, -2.211490, -0.896920, -1.738760, 0.009810, 2.645230, 0.007060,
-0.305030, -0.092590, 0.548630, -0.557830, 0.389160, 1.627350, -0.698900, 0.546900, -0.456740, 0.546210,
-0.077370, -0.227710, 2.182190, 0.143010, -0.776670, -0.866800, -1.423560, -0.312480, 0.442780, -4.363450,
-1.102840, 0.818250, -5.338340, 1.070470, -0.873750, -0.396250, -1.050870, 1.776060, 2.732660, 1.050050,
-0.439310, 0.677250, 0.971590, -0.484710, -1.263620, 3.273980, 1.382170, 1.377360, -4.130670, -1.091770,
1.011480, 1.113230, -0.847620, -1.598720, 0.753190, -2.323360, -0.212300, -1.594340, -0.929760, 0.019250,
0.787090, 1.500940, -0.052470, -0.369630, -0.576860, 0.540450, -1.674660, -0.371100, 5.157740, -1.540650,
-2.892200, -0.480520, -0.889430, -0.894150, 1.306350, -1.671550, 1.373810, 0.155370, -0.313530, -0.051740,
0.011510, 1.828130, 0.319560, 2.674590, 1.850600, -0.547000, -2.398590, 1.633890, -0.817580, -3.003180,
2.666860, 2.024230, 4.038230, 3.448420, -0.011580, -1.306340, 0.032560, 3.272450, -1.480670, -0.793090,
0.444700, -1.047610, -0.121890, 0.464840, 1.113100, 1.082420, 0.226030, -0.005540, 0.945360, 0.180930,
-0.929570, -0.221200, -7.365830, -0.665170, 2.859340, -1.071900, -0.100630, 1.204420, -4.003290, -1.776780,
0.138810, -0.169200, -1.411830, -0.200970, -1.358240, 0.486430, 0.047560, 3.852280, -1.189580, 5.246880,
2.981000, -1.510260, -0.619140, 1.184470, -0.404120, -6.575730, 0.887960, 1.604980, 2.607990, 0.074400,
1.538180, 2.099580, -0.553660, 0.237790, -5.415410, 1.631930, -0.045480, -0.343610, 0.227360, -0.177400,
1.800590, 0.034220, 4.190030, 5.714880, 0.388540, 0.460320, -0.693050, -0.128900, 1.293680, -1.587310,
-0.401020, -1.793530, -1.933900, -0.205850, -2.876570, -1.462790, -0.648390, -2.042530, -0.303170, 0.450190,
-0.724870, -1.965670, 0.091430, -1.207250, 1.456820, 2.890130, 1.040340, -0.002190, 1.117790, -0.415920,
-0.943860, -1.607270, 0.308730, 3.565230, 1.046670, 1.461980, -1.280100, -0.362380, 2.472730, -0.223390,
-4.410890, -1.501630, 3.523050, -0.110930, -0.631640, 2.664840, 0.100990, 0.827360, 1.559380, 1.116970,
-0.571950, 1.087890, -1.401710, -2.472540, 0.299860, 1.043440, -3.248270, -2.270850, -0.824420, -1.742390,
0.335550, -0.397300, -1.453640, -2.530730, -3.303470, -0.692240, 1.950850, 1.149200, -0.694000, -0.269490,
-0.205920, 0.741850, 0.251430, -0.679840, 0.630830, -0.753580, 3.382070, 0.591820, -0.138200, -0.662990,
3.765050, -0.318550, -0.630560, 0.997020, -0.139780, 0.477310, -0.394660, 0.683440, 0.298570, -0.195010,
0.551540, 0.834590, 1.736640, 3.231260, 0.251480, 0.720490, -1.203090, -0.834490,
-0.069050, 0.485900, -0.667500, -1.180910, -1.101620, 0.025790, 0.440380, -0.331890, -0.310910, 0.017240,
-0.290610, 0.797070, 0.600600, 0.173670, 1.287000, -2.138730, -0.582310, -0.457500, -0.726990, -0.007230,
-0.520320, -3.729030, 0.469720, 0.959240, 1.274670, 0.956420, -1.629270, 1.896130, 1.445910, 1.612440,
0.662240, -0.009350, -1.390410, -0.551790, -1.066630, 0.233120, 0.308200, 1.343810, 1.139710, 0.686090,
-1.038950, 0.219880, -0.088990, 1.381230, -3.174140, -0.494880, -0.233410, 0.898320, 0.301820, 1.701870,
-0.127560, 0.073080, -1.685350, -1.537120, -0.196920, -1.017250, -0.197250, -1.380310, -0.402340, 0.686240,
0.683720, -0.650770, 0.496180, 2.136000, -0.891490, 0.807090, 0.024930, -2.793480, -1.940640, 0.913840,
1.874050, 0.237140, -2.290880, 2.252340, 1.765590, -0.749360, -0.870070, -0.136060, -1.169510, -1.092250,
-0.070160, -0.004580, -0.558340, 1.417030, 1.102140, 1.235170, -1.629470, -1.112620, -0.782340, 0.822550,
-1.014120, -1.511310, 0.144630, 1.723670, -3.216920, 1.459390, 0.454820, -0.244780, 2.992920, -0.235720,
2.022530, -2.317770, -1.308320, -0.056410, 0.317410, -0.446160, 1.997440, -2.399420, -0.916040, -2.369940,
1.590170, -1.555610, 0.490210, -0.604430, -0.602880, 0.327520, 7.568510, -3.351280, -0.889550, -0.627430,
0.002940, -1.321960, 0.839640, 2.608870, -2.298290, -8.651900, -1.438860, -1.604200, 0.994210, -1.057640,
-2.489250, -2.179650, -0.839510, 0.848850, 0.096800, 1.143580, 0.637490, -0.586420, 0.943600, 4.802320,
1.177450, 0.092100, 1.128980, 1.199980, -2.273950, -0.896330, 4.159440, 2.042630, -2.526980, -1.132570,
1.359500, 0.209270, 0.258760, -0.813850, 0.125110, 0.602250, -1.707940, -1.258490, 4.467690, -0.515230,
-1.138670, 1.102810, -0.954440, 2.233290, 1.635230, 0.078640, 0.027370, 0.406530, -1.395570, 1.601250,
3.244280, -0.342720, -1.578940, -0.034750, 1.356580, 0.846470, -1.013890, -0.413500, 1.015560, -0.708220,
1.454470, 1.567240, 0.730790, -0.555660, 0.049100, 0.223100, 0.737470, 0.703550, -1.547940, -0.233920,
1.006750, 0.139580, 0.941040, 0.110610, -0.179000, 1.593480, 1.485120, 1.074220, -0.329220, -0.821130,
0.765000, -0.744690, 1.770410, 0.491560, -0.164950, -1.410690, 1.249670, 0.379380, 1.164340, 0.704110,
-0.830000, 0.350650, 0.400830, -1.292820, -1.865090, -0.004520, 0.705930, -0.847320, -1.045110, 0.165150,
-2.616920, 0.073540, -2.040710, 0.558060, 0.454410, 1.076330, 1.928440, -0.364490, -0.275330, 2.590860,
0.869870, -0.709520, 2.844910, 3.524960, 0.815410, 0.618570, -0.837910, -0.138280, -0.662000, 1.860310,
-0.253940, -1.095600, -0.454710, -1.456470, 0.670480, -2.162570, 0.048080, 0.377320, -1.020160, 1.121020,
-0.782810, -0.893060, 1.378290, -1.044570, 1.123310, -0.025900, 0.130840, -1.554710, -1.510980, -3.802120,
-1.062870, 0.364550, 0.864190, 0.866830, 3.253110, -0.601330, -0.347410, -1.036870, 0.120990, -0.160700,
-0.475190, -1.192730, -0.009310, -0.012050, -1.634920, -0.046160, -1.329520, 0.034460, -0.888890, 0.309040,
0.022200, -0.693720, 0.002010, 1.573940, -1.649470, 0.085120, -1.392800, -1.321910, 0.314750, -1.290730,
-0.506970, -3.570950, 0.558120, 2.218350, 0.056350, -1.397830, -0.265210, 0.024910,
-0.585330, 0.890650, -0.240620, 0.413350, -0.507970, -0.049040, 0.581050, -0.789320, 1.156170, -1.679830,
-0.598300, -1.947250, 1.230630, -1.098960, 0.865820, -1.032870, 0.075650, 0.046710, 1.481960, 0.548150,
-1.539440, -1.225010, 1.190620, -3.956830, -0.036830, -0.506620, 1.251200, 0.472950, 2.514740, -1.616790,
-0.446930, 0.217060, -0.643090, -1.298730, -0.694300, -0.596620, -1.671590, 0.985030, -0.522260, -0.290660,
-0.917100, 0.510980, -1.188660, -0.768460, -0.204240, 0.866520, 2.087350, 1.200390, 1.117290, -0.842530,
-0.183500, 1.839270, -0.078550, 0.715700, -0.885860, 0.616280, -2.977410, -0.656980, -0.992650, -0.364310,
-0.539780, -0.012340, -2.375370, -0.541900, 0.484920, 2.206990, -0.897460, 0.272960, -0.364820, 6.280420,
3.205170, -0.438660, -0.862710, 0.758160, 0.335870, 0.706630, -0.459580, 2.875110, -0.142180, -5.649180,
-0.121970, -3.017420, 0.584240, -0.942970, 0.581680, -2.087600, 0.604440, 1.462530, -2.085790, 0.753710,
0.908680, -0.860460, 1.937600, 2.565720, -0.165100, 0.179600, -1.010440, -0.740790, -0.234630, -0.755510,
2.070270, -2.430640, -4.018710, -0.753360, -1.597800, 1.450970, -0.857870, -1.270570, -0.321770, 1.318860,
-0.336770, -0.926830, 0.302300, 2.295950, -0.691080, 1.268010, 6.541080, -0.352280, -0.152840, 0.765950,
1.319080, -0.810200, 0.330510, 0.829270, -2.200610, -2.228510, -2.212840, -2.084590, 0.593820, -0.420000,
-0.835950, -0.476720, -0.873620, -0.911130, -1.997160, 0.386780, -0.111700, -1.034980, 0.710050, 2.641640,
-0.072300, -0.873870, 1.494160, 0.217610, -0.096750, -0.807280, -0.759450, 2.970340, 0.880780, 1.370720,
-0.308990, -0.542050, -0.044170, 0.461220, 3.664850, 1.467050, 0.023540, -2.297750, 0.787170, 0.343600,
-0.350060, 0.142490, -0.499400, 0.477600, 1.942960, 1.090610, -0.436250, -0.237710, -3.634220, 0.060500,
0.636050, 1.168270, -0.062080, -1.065490, -1.331110, -0.406620, -0.602260, -0.003340, 0.115370, 0.441570,
-0.454560, 0.113400, 0.476340, 0.308610, -3.056370, -0.976920, 0.966470, 3.987860, 0.726010, -1.158820,
-1.326560, -0.007850, -0.449900, 1.312710, 1.839010, 0.742660, -0.136530, -2.615210, 0.007250, 0.375690,
1.046960, 0.501080, 0.857900, 0.432810, 0.181590, -0.647360, 0.091720, -1.591320, -0.366140, -1.191410,
1.698780, 0.694420, 0.151160, -0.577850, -1.414420, 0.513800, 0.558600, 2.711050, -1.286960, -1.575030,
-1.291490, -1.197980, 2.010590, -4.702840, -0.786890, 2.160790, -0.419180, -0.111370, 0.418670, 2.197920,
-0.748970, -0.825880, -0.169030, 1.257970, -0.228070, -0.519090, -0.033100, -0.297060, -0.338590, 2.024280,
-0.172000, 0.255780, -0.820380, -0.355350, -1.364190, 0.422540, 0.301000, -1.091700, 0.868460, 1.076140,
1.162650, -0.239110, 0.724700, -0.204440, 1.972130, 0.571910, -0.569950, 0.380780, -0.087720, 2.415730,
0.774820, -1.648780, -0.614410, 0.407080, 3.082900, -0.574290, 0.028190, 1.384750, -0.574850, -1.102090,
0.077400, -0.837650, -0.494510, 0.301270, 0.560390, -0.488520, 0.750280, -0.327090, 0.039580, 0.102740,
2.300630, -0.582240, -0.350460, -0.660920, -0.067590, 0.411810, -0.342390, -0.535320, -1.154590, -0.278430,
-0.209650, -1.167260, 0.101270, -0.358780, 0.487790, -0.860520, -0.776840, -1.163420,
-1.667420, -2.394300, 0.748030, 1.709930, 0.401500, -0.231430, -0.491010, -1.225580, 1.401500, 0.928570,
-0.925320, -0.085090, -1.449850, 0.258100, -0.144890, 0.045510, -0.160660, -1.972290, 1.645560, -0.435260,
2.116800, 0.512320, 0.652580, -3.617990, -5.718710, -0.450610, 2.219890, 1.058260, 0.798280, -0.821110,
-1.931720, -0.233420, 1.016730, 2.517910, -0.012660, -0.579770, -3.105860, -1.854510, -0.178310, 1.351630,
-0.544570, 1.414080, -0.535700, -0.138350, -1.323780, -0.104460, -0.122910, -0.044410, -1.201370, 2.373570,
-0.786890, -0.928780, -0.604190, -0.053310, -0.940860, -0.495570, -0.705030, -1.607070, -0.669120, -1.580160,
2.521860, -0.226380, 0.707470, -1.618460, 1.335610, 0.906490, -1.067940, 0.046140, 1.652050, 0.844270,
-0.505560, -2.963460, 1.497230, -0.977180, 2.114060, 0.984830, 3.398830, -2.140990, 1.546050, 0.927150,
-2.053860, -0.652050, -1.449840, 0.020970, -0.122900, 0.075610, -0.577150, 2.169340, 0.887020, -0.272150,
1.050440, 0.358280, -0.483980, 0.222080, -0.070150, 0.024570, -0.697760, 0.151270, 0.783730, -0.426010,
1.574460, 1.471120, -2.095590, -0.392300, -0.919540, 0.538250, -0.381910, -0.571100, 1.087810, -0.679350,
1.131200, -0.145910, 1.423300, 2.684200, -0.552820, 0.261610, 0.066460, 0.699930, 2.865720, 0.189230,
0.346050, -0.163230, -1.807970, -0.158500, -0.467590, -3.079200, -0.684240, 1.015290, 0.133060, -0.769460,
-0.667640, 0.227340, 0.560660, 2.846620, 0.810670, -0.230110, -0.445770, 1.016230, 0.927600, -0.145340,
-0.283600, 1.239530, -0.274540, -0.757220, -0.255560, -1.960370, 2.573270, 0.712520, -6.147760, -1.095150,
0.654880, -0.993910, 0.710570, -0.786560, 0.813260, 1.353770, 2.495700, -1.259020, 1.699910, 1.632290,
-0.973950, 0.247860, -1.280140, 0.681920, 3.613960, -0.242310, -0.080630, -1.340890, -0.601540, -0.412560,
0.531650, -0.677520, 0.957390, 1.768670, -1.490570, 3.204730, -1.299340, 1.028840, 2.483380, 0.568590,
2.398580, 0.570550, -0.114660, -0.706420, -0.452070, -2.175810, -0.098590, 3.288900, -1.275400, -0.326140,
0.738790, -2.300980, -0.167480, -0.054060, -1.309580, 0.014060, 1.033180, -0.586440, 1.627700, -0.341870,
3.310690, 0.359130, 2.117690, 1.151320, 0.248360, 0.630180, 0.283510, -0.285360, -6.340420, -0.891810,
2.263040, -0.098640, -2.229490, 1.641740, -0.245930, -0.016020, -0.066470, -0.059620, 0.341630, 0.702170,
-1.395030, -0.909810, 0.040440, -0.428000, -0.347510, 4.597590, 0.654270, 0.068500, -0.693680, 0.701740,
-1.913890, -5.550160, -1.951870, 2.348580, -2.733500, -0.625190, -0.956370, -0.798820, -6.046370, -0.483300,
-1.845700, -1.163670, 0.921410, -1.545220, 1.033220, -0.239980, -0.834540, 0.406980, 0.338070, -0.580680,
0.858580, -0.757440, 1.959110, 0.261390, -0.262070, -1.269900, 1.229640, 1.588760, -1.046390, 1.408360,
0.375980, 1.004210, 1.421370, 0.498310, 1.096520, -0.086540, 0.642400, 1.494590, -0.961280, -0.076370,
0.924590, -0.212400, -0.748310, -2.970770, -0.981990, -0.017610, -1.881220, -0.160140, 0.091860, -0.193770,
2.313710, -0.237690, -0.289790, 1.617740, -0.629070, -0.768560, 0.664620, 0.420190, -1.019850, 0.403740,
-0.661670, -0.754100, 1.876760, 0.233990, -0.386400, -0.145740, -0.379470, -0.144240,
-0.044670, -0.494210, 0.339380, 0.930010, -0.206330, 0.125650, 0.383110, 0.337590, -0.050170, 0.917770,
-1.340990, -0.503580, 1.553910, 0.542480, 0.178670, 2.245590, 0.372590, -0.432990, 0.181860, -0.049700,
0.020090, 0.467730, 0.548430, -0.113530, -0.777370, -0.539390, -0.012020, 0.924580, 0.907410, -0.498700,
-1.501460, -0.419930, -0.306860, -0.090000, -0.767380, -0.348180, 0.120550, -0.249990, -1.696430, -0.518730,
1.075790, -1.104520, 0.099470, 0.765660, 0.315680, 0.616730, 0.663060, 0.688890, -0.351680, 0.245110,
-0.828830, -0.642320, 1.163570, -0.263850, 0.347050, -1.363200, 0.616210, -0.536630, 2.384350, 0.841530,
0.507080, -0.124290, 0.483720, 0.737470, -0.983650, -0.857460, -0.115340, -0.417400, -1.160400, -0.378490,
-0.405080, -1.824440, 1.700950, -0.219740, -1.434280, 0.882060, -1.589550, 0.169280, -0.415720, -2.635370,
-0.430560, -0.404050, 1.211490, -0.074040, -0.391340, -0.837970, 0.503680, 1.502420, -1.134890, 0.504160,
0.730800, -1.232510, 0.345190, -0.213530, 2.045590, -1.920270, -0.084650, -0.395840, 1.222790, -0.883670,
-1.945720, -0.460270, 0.656810, -0.119870, -1.033140, 0.723740, 0.150780, -0.268070, -1.114560, 1.633550,
-0.509610, 0.176610, -0.009810, -0.137370, -0.544220, -0.865910, 0.342770, -0.952250, 2.096580, 0.873230,
1.411040, -0.403040, 0.729240, -0.051960, 0.374280, 0.719090, 0.011800, 0.201550, 1.730570, 0.074480,
1.299170, 0.090510, -0.281590, 1.235610, -1.674940, 0.376560, -0.402980, -1.456490, 0.615250, -2.493820,
-0.010990, -0.551720, -1.848970, 0.800800, 1.412780, 0.122660, 0.060480, -2.236480, -1.083440, 0.620790,
-1.012270, 0.573160, 0.654830, -1.501990, -1.163050, 0.560720, -0.771230, 0.482160, 0.432580, -0.559720,
-0.000760, 0.592740, 1.199450, -0.436140, -4.701600, 0.141430, -1.362590, 1.306920, 2.571050, -2.537420,
-1.606320, 0.042770, -1.650120, 2.038680, 1.749010, 0.247870, 0.277840, 0.007900, 0.687450, -0.299990,
0.578740, -0.988410, 0.958300, -1.441100, -0.535080, 4.669560, -0.315720, -1.340930, 0.115090, 0.943110,
0.167830, -0.291100, 1.362700, -0.706560, 2.391380, 0.849310, 1.449500, -1.199000, -0.810620, -0.130070,
-1.684180, 0.467690, -0.484430, -0.452550, -0.866930, -0.246090, -0.801240, -0.696270, 2.891260, 0.451460,
-1.336540, -0.852420, 0.802640, -0.798890, 0.190890, 2.252690, -3.010340, 1.982570, 0.248240, 0.449320,
1.766090, 1.273550, 0.859250, -0.305180, -0.526050, -0.219050, -2.431960, 0.954690, 0.261500, -0.423440,
0.107800, 4.418450, -0.202110, -2.279570, -0.351790, 1.386870, 0.349490, -2.704940, 0.566260, -2.340450,
3.837510, 0.434780, -0.110630, 1.043830, -0.112770, -0.378810, -0.081450, -3.286940, -4.619240, -0.240260,
-0.633210, -0.118470, -0.500590, 0.842200, 0.120260, 0.652120, -0.387960, 0.483830, 0.530880, -0.847090,
-0.708600, -1.746720, 0.465140, 1.208390, -0.568390, -0.264580, -0.647990, 1.730220, 0.646870, 0.052620,
0.017760, 0.056180, 3.806570, 3.777990, 0.400860, 0.710950, -1.360700, 2.924580, 0.875800, -0.214670,
-1.664450, -0.533150, 0.523120, 0.031500, -0.348600, -0.300290, 1.298270, -0.854130, 3.264780, 1.033970,
2.769110, 0.904020, -1.153670, -3.175340, 1.065670, -0.040220, 1.171180, 0.963490,
0.255100, -0.398930, 0.738680, 0.128170, -0.640310, -0.434050, 0.330980, -1.156480, -0.585020, 2.641620,
-0.943530, 2.407380, -0.879730, -0.101320, -1.430610, -1.851910, 0.531550, -1.546640, -0.520030, 0.707040,
0.109070, -2.163310, -0.219670, 0.383740, 2.235680, -1.888650, -0.294620, 1.169280, 2.585670, 0.752050,
-1.310070, 0.844880, -2.013680, 0.133550, 1.443410, -1.292430, -0.612420, 0.836230, 1.211760, -0.730060,
-1.299570, -0.233430, -1.564390, -0.037610, -0.532860, -0.829820, -0.358740, 0.137500, 0.612640, 0.663640,
-1.757300, 1.678780, 0.523230, 1.176920, 1.402120, -0.312010, -0.814380, 1.010150, 1.828890, -0.409140,
-1.647520, -0.359060, -1.687060, -0.594920, 2.315780, 2.649780, 0.459570, -0.590930, 0.437090, -0.440480,
5.593690, -1.134250, -4.924910, -2.069640, -0.438550, 1.316860, 0.815870, -0.531650, 0.842360, 1.684470,
-0.997290, 1.463190, 2.505600, 0.608080, 0.455950, -0.907200, 1.561940, 0.059230, 0.363640, -0.170930,
-1.335310, -0.650400, 2.789330, 5.374600, -3.888900, -1.998450, 0.292740, 1.149840, -2.588100, -2.232920,
6.507700, -5.912720, -4.240310, 0.664830, 0.942100, 10.705630, -1.418910, 0.055520, -3.934340, -1.620850,
0.382770, 0.097030, 0.941430, -1.171370, -0.677770, 0.512250, 3.895720, 0.047060, -0.290320, 0.263920,
1.273060, -1.353320, 0.668930, 0.023160, 1.455370, -2.066350, -0.572820, 1.398820, 0.107490, 2.439330,
-0.543650, -1.351180, 1.717570, -0.213000, -1.579890, -0.359380, -0.054380, 0.372080, -4.559730, -0.056550,
0.507700, 1.059090, -1.040200, 0.516330, -0.729470, 0.818180, -0.959960, 0.846300, 0.305580, -0.778380,
0.531260, -0.894630, 0.065850, 0.830470, -0.395910, 0.418160, -0.235690, -0.284220, 0.312760, 0.219920,
0.387240, 0.254670, -0.146370, 0.781020, 1.318630, 0.218210, -2.537360, 1.504040, -0.997260, -0.159030,
0.562950, 0.436870, 0.374420, 0.944180, 0.109130, -0.608370, -0.289170, 1.404140, -2.453630, -0.062090,
-1.243570, 0.245060, 1.009560, -1.187880, 0.572720, 0.532910, 1.005390, 1.358550, 0.787390, -0.284680,
1.393080, 0.535890, -0.288350, -0.520670, -0.011560, 0.568460, -0.093950, -0.227110, 0.444230, -0.288550,
1.154630, 0.890470, 0.636720, -1.955160, -0.271860, -1.802580, 0.881070, 0.317840, -1.162360, -0.907760,
4.320960, -1.694760, 0.808990, 0.373470, -1.823290, -0.851730, -0.505500, 0.712910, 1.097410, -0.255310,
-2.263390, 0.890170, -1.181520, 0.269710, -1.267040, 0.932100, -0.656880, 0.141390, -0.426660, 1.706970,
-1.442870, 0.012500, 4.405820, 0.697220, -0.168850, -0.051970, 0.520780, 1.672830, -0.829870, 0.206700,
-3.139590, -0.598530, -0.287900, -0.714730, -1.306940, 0.828220, 3.832330, 0.487460, -0.116600, 2.272760,
0.911900, -1.355820, -0.602270, -1.414970, 1.749730, 1.627690, -0.418620, 1.913910, -0.357030, 0.875900,
-0.801130, -0.163420, 0.451080, 0.431990, 0.756690, 0.063540, 1.236100, -1.000840, 0.626380, 0.462720,
-0.850420, -0.861030, -0.394000, -0.900600, 0.282500, 0.863590, 0.206270, 0.734140, -0.405780, -0.292570,
-1.213210, -0.516400, 0.562070, 1.428040, 0.656140, 1.297050, 0.767920, 0.092510, -0.288780, 0.763640,
-0.602050, 0.556430, 1.022880, 1.198600, 0.071290, -0.353420, 0.776420, 0.689600,
0.202920, -0.531090, -0.249610, -0.925020, 0.352470, -0.878680, -1.213980, 0.415270, 0.718930, -0.387090,
-0.817210, -0.339540, -0.530500, -0.604830, -1.154120, 0.817660, 0.800540, -0.601340, -0.123350, 0.077170,
-1.213300, 0.920300, -0.196490, -0.259050, 0.210200, 0.591270, 0.138630, 0.934690, -0.713330, -0.051350,
-0.514030, -0.100330, -0.460730, -1.063580, -0.273400, 0.008920, -1.281750, 0.586330, 0.001580, 0.434550,
-0.157490, 1.985900, 0.602080, -1.137260, 0.131510, -0.765140, 0.060870, -0.403670, 1.690080, 0.263100,
1.301850, -0.150170, 0.259860, -0.775210, -1.073950, 0.833080, -0.787000, 0.219840, 0.229580, -1.235050,
-0.068220, -1.067620, -0.463280, 1.380760, -0.859400, -0.015770, 0.804420, -0.747580, 0.281630, 0.115490,
2.052090, 2.627430, 0.023960, 0.742030, 0.120820, 1.053110, -1.123960, 0.329060, -1.291460, -0.825140,
0.531370, 0.625550, 3.961870, -1.961920, 0.425510, -1.418800, 1.897120, 2.907450, 1.793860, -0.458920,
-0.270470, -1.595920, 1.690580, 0.527650, 0.897780, -1.595000, 1.271120, 0.709950, 0.196460, 2.822010,
1.986640, 0.138970, -2.199220, 1.058690, -0.916700, 3.008610, 2.248600, 0.394310, -2.845960, 2.622360,
0.938930, -0.444710, 0.908950, 0.481040, -2.775760, 0.230450, -0.552820, 0.568160, -1.864590, 0.949080,
0.589450, 1.977500, -0.473650, -0.659160, -0.016510, -0.494120, 2.008440, 0.202650, 3.629040, 1.369090,
0.429480, 0.630490, 1.271370, -0.162200, 0.200070, -0.419850, 1.108780, -1.002510, 0.233520, 0.017540,
0.018730, -4.010880, 0.493790, 0.951550, 1.405930, 1.899340, -1.066420, -0.551830, 1.259620, 1.612840,
1.324230, -0.130630, 1.601190, -0.541410, 0.727410, 1.093590, -1.218830, -0.594240, -0.143830, -0.816970,
-2.513120, -1.253770, 0.229520, -0.262600, -2.650170, -0.389780, 0.427230, 1.842210, -1.096300, 0.039790,
-1.275640, 0.933390, 1.231390, 0.342190, 0.718000, -0.086700, 0.095060, 0.105600, -0.849140, 0.486590,
-0.715420, -0.478250, -0.357300, -1.956360, -1.775000, 3.233530, -1.781420, -0.817310, -0.404350, 1.341270,
0.656200, 1.739040, -2.714380, 0.223820, 1.157990, 1.059090, -0.194810, 0.250350, 2.014260, 0.930400,
1.210250, 0.101910, -0.853580, -0.815020, -0.089120, 0.066520, 0.124350, -0.568140, 7.495240, -2.275760,
-4.276240, -1.284680, -0.003770, 0.089480, 0.771570, 0.000180, -0.505230, 1.636030, 0.119360, -1.471390,
-0.241840, 0.121960, 0.178930, -0.886550, 0.361820, -1.479630, -0.984100, -1.146820, -1.193650, 0.099810,
-0.985980, 1.657780, -1.896700, -3.829380, 0.984210, 0.039050, -0.855440, 1.986780, 0.656050, -1.662610,
2.743290, -0.182530, 0.823160, 1.004100, -0.602220, -0.237880, -0.736890, -2.145660, -2.086770, -0.815730,
-0.272680, 0.454920, -2.031920, -0.086840, 2.238130, 2.198980, -1.202750, 1.323750, -0.260800, 3.747100,
-0.061750, 2.576490, 2.025530, 2.613300, 2.091770, 0.345880, -0.845310, -1.843000, 0.611960, -0.018500,
-0.140510, -0.823720, -0.370420, -1.493950, -0.618560, 0.464190, -2.664210, -0.381430, -0.676250, -0.549790,
-2.067400, 0.177900, -0.061930, 0.283730, 0.343590, 0.467810, -0.446320, 0.834300, -0.446750, -0.452280,
0.428200, -0.426500, -0.579300, -2.963740, 0.037150, 0.217900, -0.242800, -0.222130,
2.749740, 0.718870, 0.859260, 1.211060, 0.740730, -1.511740, -0.454850, -0.628070, 0.926600, 1.488040,
0.543750, 1.916820, -0.332510, -0.406920, 0.398840, 0.512100, -3.071250, -0.314580, 0.595420, -1.586500,
0.437130, -0.038130, 0.663180, -0.534220, -0.530170, -1.221920, 0.935870, 1.289580, 0.778870, -1.731280,
0.224770, -0.943440, 1.376020, -0.252870, 0.852470, -1.469270, 1.231240, 0.422060, -0.632860, -0.296710,
-0.846810, 0.236460, -0.102270, -0.211180, 0.268120, -0.322980, -0.593130, -0.073870, -0.755920, -0.955650,
-0.140310, -0.113950, -1.394840, 1.507930, 0.496190, -0.959930, -0.148180, -0.464870, 0.830340, -0.554860,
1.946920, -1.904470, 0.422870, -0.846130, 0.887130, 0.793570, -1.915630, -0.056700, 0.529600, 0.464390,
-2.454620, 0.216590, -2.001140, 0.008540, 0.777940, 0.715270, 1.098820, -0.431890, 0.561800, 1.450990,
0.649280, -0.547620, 0.406970, -0.101380, -1.163450, 0.790900, 0.492050, 0.074980, -0.621560, 0.481880,
0.837890, 2.945400, -1.625330, -4.465790, 2.631580, 0.094240, 0.561330, -1.404400, 0.303550, -1.856070,
-1.129340, 0.176050, -1.460750, 0.538240, -0.480240, -0.423830, -1.238100, -0.213220, 4.066110, -0.046250,
-0.310040, 2.466950, 0.479630, 0.140050, 1.356830, -4.856610, -3.351460, -0.563070, 1.341070, 2.394280,
-0.358030, 0.766130, 0.411530, -6.056650, 5.439950, 4.060140, 2.897420, -0.490370, 0.231990, -1.001780,
0.131320, 6.017760, -0.616840, 0.469830, 0.448290, -0.576090, 0.767520, 1.340790, -0.538510, -4.830530,
-0.758990, 0.755100, 0.613680, 0.855580, -4.707520, -0.203230, -3.951530, 2.316860, 3.303160, 3.551020,
1.264400, -3.136460, -1.536190, 0.051180, 3.642020, -2.369940, 0.503890, -0.159010, 0.219800, 1.959400,
3.405790, 0.507010, -4.850990, 1.402130, 2.691640, 0.002860, -0.289510, 1.492780, -0.572440, -0.172020,
2.341960, 4.105200, -1.815180, 2.301710, 0.495180, 0.751220, -0.142000, 2.020100, 1.736030, 1.876460,
0.095430, -0.696180, -1.087170, 2.263080, 0.640750, -0.679320, 1.405860, 1.757850, 0.411090, -0.471630,
-0.242340, -1.357210, -1.979070, 0.583080, -1.316460, -0.233190, -0.351150, -1.495880, 1.067360, -1.622400,
-0.144640, 0.849540, 1.317610, 0.354970, -0.874450, 1.539390, 1.544390, -0.444730, -2.015260, 0.924460,
1.538030, 0.349440, -1.903360, 0.069070, -0.000210, -0.083600, -0.817200, -3.208700, 0.169250, 0.963380,
0.202880, -0.603650, -0.721930, 0.946980, -0.849710, 1.710430, 1.502630, 0.533570, 0.737360, 0.887530,
0.654060, -0.774690, 0.889360, -0.113600, 0.571160, -0.345350, -0.023480, -1.096020, -1.979770, 0.118730,
-0.395170, 0.853860, 0.153220, 1.277570, 1.132480, -1.183250, 0.851340, 0.506540, -0.083940, 1.197300,
0.662970, 0.177800, 0.895780, -2.120530, -5.907170, -0.388650, 1.083150, 1.455040, 0.801050, -1.836390,
-0.184360, 1.360110, 0.426330, -0.319320, -1.236650, -0.866320, -1.032620, -0.213260, -0.013020, -0.745680,
-0.334590, -0.840400, -0.068180, 0.689470, 0.220540, 0.342490, 1.295310, -0.312320, -2.300430, 0.702500,
-0.121680, 0.271110, -0.952200, -1.215400, -0.559140, 0.994800, -0.278470, 0.200630, -1.197240, -0.711510,
0.043670, -0.258650, -1.883460, -0.080970, -0.427220, -0.052280, -0.057880, -0.651530,
0.252770, -0.525950, -0.052620, 1.273010, -0.788400, -0.617620, -0.802210, -0.337560, -0.741140, 1.270880,
0.406530, -0.115660, -1.295380, 0.558300, -0.053090, 0.402490, -0.333130, 0.216100, 1.656120, -0.367050,
-0.279600, 0.516700, 0.927240, 0.168160, -0.857420, -0.319770, 1.021030, 0.999460, 0.957380, -0.643750,
0.100370, 1.321820, -0.268270, 0.787270, -0.744720, 0.908050, 0.740250, 1.012540, 0.125310, 2.620690,
-0.351050, 1.285210, 1.210870, -1.266050, -1.146280, -0.646160, 0.944780, 0.585350, 0.548880, 2.245530,
0.384100, -1.268340, -0.830770, 1.403610, -0.809850, -0.454740, 0.119700, -0.229690, -0.193280, 0.991840,
0.454770, 0.809170, -1.856740, -1.322350, 0.996320, 1.024370, -0.766860, 0.410990, -0.136200, -0.804460,
-0.176080, -0.942190, 1.939950, 1.192020, -0.752660, 0.834910, -0.088520, -0.954450, 1.102710, -0.647510,
0.711640, 0.243600, 0.267730, -1.395050, -0.865870, 1.482400, -0.285830, 0.364710, -0.272490, 0.659670,
-0.590750, 0.505840, -0.295120, -0.399210, 1.872080, 0.741600, -1.322390, 0.092300, -0.229560, -0.927360,
0.291710, 0.145990, -0.213250, -0.089720, -0.566910, -1.354120, -1.243280, -1.379950, -1.032010, -0.599640,
0.259320, 2.332640, 0.555110, -0.674410, 3.233910, -0.806790, -2.434310, 0.349770, -0.169240, -0.318470,
2.199420, -0.280430, 0.629360, -1.275010, 0.127830, -0.177610, -0.228730, -0.215940, -0.764180, 0.268780,
-0.097550, -0.112460, 0.606310, 2.048860, 0.217630, 0.323840, -0.459220, 0.885700, 1.379670, 0.031080,
0.425720, -0.072920, -0.187490, 0.757560, 0.551680, 1.696140, -0.703820, -0.705950, 0.923540, 1.940890,
-0.036090, -1.157630, -1.656880, 0.798040, 0.836830, 1.398100, 1.400160, 1.369390, -0.086340, 1.288970,
0.529360, 1.689350, -2.804370, -1.315870, 0.837320, -0.391440, -1.834910, 0.994800, -1.180360, -0.144960,
-0.480660, -2.823120, 0.605820, -0.342950, -1.399880, -0.515900, -0.371170, -0.087140, -0.033150, -0.294390,
0.562710, 0.265870, 0.201370, 0.482070, 0.812350, -0.705990, -0.280430, 0.375650, 0.159030, -0.341790,
0.575090, -0.179930, 1.925330, 0.887930, -0.292860, -0.973220, 1.754570, 0.602490, -0.729600, 2.463670,
-0.506600, 0.012630, 0.435320, -1.430350, -0.440790, 0.215680, 0.418940, 0.620340, 1.365260, -0.538220,
-0.932910, -2.035490, 1.359590, -0.011000, 0.538560, -0.445250, -0.248740, -1.955020, 0.086830, -0.401290,
-0.068660, -0.904040, 1.733040, -0.788550, -0.794810, 2.513100, 1.528280, 0.426720, 0.296270, -0.150140,
0.631200, -0.471690, 0.521440, 0.980290, 0.640640, 0.159200, 2.126960, -0.802470, -2.700820, -0.108290,
-1.390620, -0.299200, -0.726540, -0.289910, -0.381970, -0.602170, -0.529670, -1.892720, 3.345750, -1.034910,
0.082350, 1.076840, 0.889390, 4.674750, -0.146080, -0.039520, -0.446450, 0.906720, 3.984030, 1.453230,
0.191650, 0.719500, -0.214720, 3.119570, -0.626310, 1.286860, 0.401410, 1.575010, -0.485250, 0.758400,
-0.485640, -0.256850, -1.915190, -1.541510, 0.267420, -0.918090, -0.391120, -1.527450, -0.819640, 0.408140,
3.950830, 0.767650, -1.143320, -0.260300, -0.741580, -1.283440, -5.693160, -0.293950, -1.775800, 0.146450,
-1.561770, -0.469870, 1.038450, 0.021940, -1.239790, -0.541530, -2.447010, 0.467230,
-0.582180, 1.344810, 1.005300, -0.341730, 0.048890, 0.582590, 0.635810, -0.281550, -1.109970, 0.450940,
0.530080, 0.754700, -2.259500, -0.372460, -0.539990, 1.001530, 0.542510, -1.812280, -1.472470, -0.127450,
-0.070110, 0.629600, -0.402150, -0.096500, -0.375040, -0.523760, 0.939810, 0.385220, -1.529390, 0.549970,
-0.225160, -0.059910, 0.061060, 0.154950, 0.046430, -1.667390, 1.020110, 0.668390, -1.092790, 0.352140,
0.393090, -1.672130, -0.175590, -1.189720, -1.819240, -0.727540, 1.094840, 0.776820, -0.125650, 0.246230,
1.313230, 0.475600, 1.839470, -1.328150, 0.843810, -0.361900, 1.116270, -0.757970, -0.379280, 1.023070,
0.762600, 0.434110, -0.573140, -0.177260, 0.651370, -0.376880, -0.303370, -0.595780, -1.037710, -0.849000,
-0.595630, -0.102930, -0.418100, -1.191730, -0.153860, 0.584910, -1.439490, 0.668170, 0.142170, 0.694050,
-0.268710, -2.663750, -0.942950, -0.966380, 0.113540, -0.922250, -1.464230, -0.733370, 0.478050, -0.743050,
0.226200, -0.658430, 0.276210, -0.964060, -0.760430, 0.009790, 0.892330, 1.316360, -0.219330, -0.872080,
-0.157760, -1.073050, -1.026300, -0.830050, -0.674100, -0.672630, -0.111990, 0.744920, -0.463670, 0.009820,
1.104610, -0.059290, -2.132210, -0.047200, -1.483410, 0.463410, 0.868940, 0.975070, 1.808720, 1.309970,
1.288790, -2.519900, -1.245450, 1.336780, 0.110340, -3.499350, -0.341030, -0.653670, 1.551450, 0.383870,
1.017540, 0.729590, 0.321900, -0.551730, -0.010220, 1.898000, -0.194380, -1.238380, -0.724760, -1.014590,
0.161180, 1.455670, -0.716940, 1.014690, 0.807390, 0.718580, 3.103820, 0.856530, -2.589360, -0.710040,
-0.206900, -0.336050, 0.805450, 0.593180, -0.447290, 0.119720, 1.607010, -1.029840, 1.135660, 0.573310,
0.500010, 0.394680, -0.301410, 0.503370, 2.393470, 0.907380, -1.270430, 0.710640, -0.783840, -0.144930,
-2.168180, -0.652420, -0.391070, -0.256550, -0.096180, -0.496880, 0.288210, 0.689110, -1.718590, 0.504070,
0.499930, -1.728800, 0.904960, 2.438250, -0.292230, 0.468360, -0.749990, 1.074730, 1.051280, -0.935510,
0.800600, 0.573890, -0.263570, -1.446260, 0.340460, 0.278200, 0.051960, -1.076900, 0.124010, -1.154870,
-0.889490, 0.599750, 0.342580, 0.553360, 0.041750, 0.139980, 0.387280, 0.590080, 0.403920, 1.350230,
1.387710, 0.793360, 0.619010, -0.762040, -1.135270, 0.641390, 1.010480, -0.881870, -0.824170, -0.419160,
-0.206470, 2.020640, -0.119730, 0.132450, 0.506050, -0.306190, -0.909270, 0.946200, -1.103150, -1.193620,
0.936430, -2.065240, 0.489360, 3.261960, 1.080530, 0.136920, -0.221520, 0.469700, 0.790790, -0.655860,
-2.811900, -0.578290, 0.510500, -2.884350, 1.221860, 0.056110, 1.179260, -0.786650, 1.983260, 0.672170,
-0.106510, -0.519580, 0.214460, -0.267580, 2.675260, -0.640890, -1.848950, -0.324410, -1.373390, 0.037380,
0.534530, 1.358410, 0.609820, 0.250450, 1.210980, 0.149640, 0.328970, 0.078160, -0.335810, -1.744060,
-0.669450, -0.529730, -2.093850, -7.313430, -0.723460, -0.069180, -1.394180, -0.608740, -1.680500, -0.742440,
-3.764360, -0.943260, -2.112640, -0.647880, -0.369630, 0.039910, -1.674660, 0.227420, -1.421380, 0.296900,
-2.849130, -0.331460, -0.212510, -0.650810, -0.248900, -1.325740, -2.751440, -0.181620,
-2.700710, 1.217280, -0.515870, -0.811800, 1.601700, -0.730360, 1.791660, 0.141740, 0.599010, -0.024190,
2.017320, 1.129360, -0.018470, 0.369790, 0.877220, -0.590060, 0.721150, -0.520360, 0.984180, -0.224160,
-0.005330, 0.387420, 1.706260, -0.029510, -0.417360, 0.090320, -0.375930, 0.127740, 2.387500, -0.224350,
1.534380, -1.114630, -0.017970, 0.910470, -0.168130, -0.519690, 1.629270, 0.897160, -0.769190, -0.138020,
-0.675470, -0.601890, -2.338930, 0.326990, 0.042480, -0.331050, -1.237610, 2.173830, -0.762090, -1.020530,
0.675350, 0.413400, 0.004970, -0.519790, -1.607310, -0.060750, 2.437950, 0.941820, 0.147060, 1.444660,
1.308850, -0.305230, -0.829660, -1.106330, 0.198340, -0.867320, 0.896260, -0.311560, -0.739990, -1.205760,
-0.054820, -1.512290, -1.430450, -0.342400, -0.193190, 1.474390, 0.114970, -0.325250, -0.464370, -0.191460,
0.675960, 1.245930, -0.760900, 0.295080, 0.757130, 0.803900, 0.018810, -0.645220, 0.751960, 0.490390,
0.007380, 1.336200, -1.473700, -1.103640, 1.588480, -3.914160, -0.048990, 2.192040, 1.104170, 0.128810,
0.542150, 0.362830, 0.131750, -1.703140, -1.572680, 0.536170, 1.600910, 0.790180, -1.529240, -0.407000,
-1.242540, -0.938640, -0.193300, 0.131020, 1.431500, 2.805330, 7.739020, 1.285970, -1.904690, -0.760680,
0.712090, 0.374550, 1.151840, 1.563680, -1.190640, 0.611660, -0.234910, 0.709640, 2.459740, 1.542830,
-0.649450, -2.177640, 0.609480, -3.210840, -3.005830, -2.770340, -0.891460, -0.042760, 1.445620, 6.428400,
1.226970, 0.168300, -0.593520, 0.582670, -0.537910, 0.163310, 3.076910, -0.628900, -1.014610, -0.829820,
-0.378360, 0.254980, -0.776360, 0.352500, -6.746680, -1.097360, 2.692590, 0.549790, -0.657920, -0.386480,
-0.486070, 0.399880, 4.768910, 1.595300, -0.691650, 0.049110, -0.366730, -0.725250, 1.416600, 5.320150,
0.646640, -1.026270, 0.116420, -0.212380, 0.703320, 2.915440, -0.304200, -1.444940, 0.236570, 0.205870,
-2.222850, -0.003700, -0.637650, -1.776320, -0.309620, 4.239590, 0.699290, 0.037850, 0.556950, -0.234380,
-4.159840, 0.418780, 2.892360, -0.103760, -0.569260, -0.642140, 0.601230, 1.650210, 2.743010, -1.721100,
-3.056070, 0.769450, -0.654000, -0.612020, -0.609710, -4.642440, -0.330490, 0.784090, 0.679830, 0.580820,
-0.271620, 0.175230, -0.702450, -0.237720, 1.374160, 0.583300, -1.003800, 0.310280, 2.035450, -1.454880,
0.929230, 0.017620, -0.110930, 0.562850, -0.464900, -0.556150, -0.281670, -0.672220, -1.683540, -0.575760,
-1.953090, 1.747580, 0.943290, 0.311400, -0.937030, -0.357240, 0.104860, 0.130360, 0.601600, -0.393010,
2.178330, 0.298150, -0.001470, 0.818320, 1.424150, 1.653950, 0.911920, -0.466260, -0.466410, -1.634170,
-1.685590, -1.641010, -0.761120, -1.740890, 1.095260, -1.110940, -0.898390, 0.351900, -0.170650, -1.537820,
0.062310, -0.582070, 0.031030, -0.523830, 2.858700, -0.283160, -1.912800, -0.510370, -0.225570, -0.870260,
0.768960, -0.653630, 0.863050, -0.765940, 0.330260, 0.665450, 2.750250, 0.535030, -0.179980, -0.381770,
-1.194040, 0.335580, 0.441140, -1.542370, 1.008400, 0.584090, 1.316710, 0.925910, 0.686550, 0.237910,
0.985880, 0.458490, 0.758780, 0.961200, 3.017960, -0.115080, -1.072980, 1.121380,
-2.565330, -1.762910, 1.453880, 0.915490, 0.340990, -1.475840, -0.584400, -1.218380, 1.556800, -1.503620,
-1.464160, 1.628570, -0.663000, -1.541340, -0.817010, -0.695500, 0.784460, -2.039370, 0.455090, 1.199690,
-0.380770, -0.120640, 0.975310, 0.289630, 4.014330, 0.727430, -0.327770, -1.068740, -1.353750, 0.849400,
0.569820, -1.491430, 2.011660, -6.380670, 1.142780, -0.787840, -2.714830, -1.235710, -1.388420, 0.210860,
-3.767790, 2.358720, 4.305340, -0.519100, -0.486110, 0.482230, -0.309710, 2.152790, -0.155630, -2.048540,
1.178630, 3.461200, -2.163830, 1.567220, 0.749040, 0.052160, 1.142790, -2.296080, 1.873160, -2.683070,
-1.047530, -1.380640, 2.214650, 0.954870, -0.855770, 0.255500, 0.566060, -1.287910, 1.141120, 0.664240,
-1.437590, -0.145750, 2.274270, -1.098500, 1.529940, -2.762190, 1.183990, 0.364880, -0.404530, -4.781310,
1.174440, 0.204040, -1.339300, -2.186100, -0.346810, 1.643940, -4.137500, 1.805270, 0.748780, 0.193680,
-0.700130, -0.960920, 1.533170, 0.689410, -0.990470, 1.572080, -0.142420, 0.821830, 0.401480, -1.572310,
1.411560, 0.147210, 0.247110, -0.262640, 0.115540, -2.288720, 1.142040, 0.124640, -1.676770, -1.941010,
1.132760, 0.433400, 0.639210, -0.423750, -0.427140, -0.315820, 0.633870, 0.394250, -0.372920, 0.039700,
1.090750, -1.124510, -5.398610, 1.235860, -0.247770, -2.413690, -1.234910, 0.751960, 0.053670, 0.282250,
0.852930, 0.316590, -1.021510, 1.733430, 4.447530, -0.187740, -0.178430, -0.780660, -0.970360, -2.835370,
-0.214220, 3.629830, 0.787350, 0.456760, -0.664240, -3.559560, -0.127600, -1.109560, -2.399670, -0.438040,
-1.515340, 0.317740, -1.333520, -3.074030, -0.208010, 0.105860, 1.154920, 2.707660, -0.369050, 2.215540,
0.374180, -0.571970, -3.007850, 2.530510, 3.474020, -0.165530, 1.535430, -2.274080, 0.755470, 0.587320,
1.585320, -1.035850, 0.056260, 0.185390, -1.266380, 0.096660, 1.693280, 2.130020, 0.730410, 3.966220,
2.094460, -0.879200, -0.299210, -0.184010, 0.644490, -2.669570, 2.106450, 5.318350, -1.373890, -0.669770,
-0.834770, -2.346370, -1.566970, -0.628260, -0.524390, 1.063470, -1.039890, -0.997940, 0.543470, -0.983310,
-0.981100, -0.080740, 4.288420, 0.758150, 0.618740, 0.455080, -0.964570, 0.198640, -4.188290, 1.609330,
4.609850, 1.476090, -0.504790, 0.397290, 1.524610, -2.737860, 1.246610, -5.619970, -0.522410, 0.724970,
0.374420, -1.067480, 1.682790, 1.267030, 1.417280, 2.600550, 2.150150, -0.285140, -0.729220, -1.348090,
2.354760, -3.989840, 1.389100, 2.576610, -0.283960, -1.606410, 1.997330, -3.000490, -1.880090, -0.338310,
-2.869950, -0.153170, 1.134980, -1.370440, 0.147600, -1.364550, -0.122190, -0.075110, 3.113830, 4.506360,
0.262950, 0.091780, -0.759660, -3.196760, 0.789660, -2.336600, 0.765320, 1.247830, 0.776590, 0.323740,
-0.895930, -0.054090, -0.159700, -5.729070, -1.139320, -0.470810, -2.577980, 0.348370, 0.131800, 1.384190,
-0.036370, -0.666210, -0.232740, -0.248320, 1.061970, -0.728140, 1.729990, 0.271730, 0.226080, -0.804420,
2.095620, -0.799740, 0.739630, -0.472560, 0.365930, -0.173910, -0.099420, 0.023960, 0.630200, -0.758300,
0.890810, -0.969990, 2.986790, 0.798760, -0.439460, -0.428190, -0.631530, -0.357300,
0.437120, -1.294130, 0.530760, 1.416510, -0.825350, 1.408940, -0.359270, 1.007930, -0.155350, 0.606270,
0.260990, 0.241060, -0.308060, -0.868720, -0.292790, 0.102080, -0.872670, -0.810240, 1.251250, -0.299660,
-0.495470, 0.139440, 0.424580, -0.218300, -0.291210, 0.430580, 0.256850, -0.246880, -0.679910, 1.734420,
-0.636410, -0.745250, 0.773630, -0.640910, 0.455380, -0.909980, -1.097170, 1.295530, 0.593690, -0.646230,
-0.240830, -1.020640, 0.816730, -0.337250, 0.536490, 0.146600, 0.660520, 1.311600, -0.755040, 0.205170,
0.243600, 0.532810, 1.436460, -0.312710, -0.506670, 0.684050, -0.089990, 0.261770, 0.308570, -0.457180,
-0.985180, -0.519260, 0.572700, 0.254890, 1.042860, -0.649870, 0.305560, -0.572860, 0.650440, 0.536880,
0.489310, 1.878590, 0.858440, -0.056150, 1.094120, -1.239410, -2.347370, -0.144290, 0.948730, 0.570180,
0.478390, -0.860620, 0.666540, 0.316440, 0.044610, 0.181960, 0.153170, -1.039200, 2.543940, 0.444240,
-0.641150, 3.248590, 2.254080, 1.114420, -0.251820, 0.964290, 1.839380, 0.674970, -0.514920, -0.388830,
1.123330, -2.799590, -1.664780, -0.450680, 0.022910, -0.407420, 0.229910, -1.074970, -1.241620, 0.850790,
-0.514190, 0.674980, -0.279950, 0.946930, -0.450480, 0.814530, -1.210130, -1.254960, -1.822320, -0.235620,
-0.603430, -0.232990, 1.097360, -0.150370, -1.686730, -1.345280, -0.790200, -2.003630, 1.734060, -0.618260,
1.359310, -1.788900, 0.747290, -0.421500, 0.802810, 1.144070, -0.254210, -3.128780, 1.041170, 4.915540,
0.099440, -1.856300, -0.332170, 1.341960, -0.061500, 0.109330, 1.818880, 0.038490, -1.230780, -0.119060,
-0.913750, 4.599630, 1.396900, -1.800630, -0.509830, 0.856480, -1.169010, -0.885530, 2.394890, -0.272830,
-2.006240, -1.369220, 0.447710, -0.584400, -0.201800, -0.922800, -0.357250, 0.173600, -0.768010, 0.141130,
1.269950, -1.202270, -0.068850, 0.281540, -0.175110, 0.889150, -0.070630, 0.321980, -1.425920, -1.287780,
0.275780, -0.370520, 0.020460, 0.397920, 0.456400, -0.094930, -0.500440, -0.963850, -1.104980, 2.396160,
0.517950, -0.105820, -0.386330, 0.676880, 1.142410, 0.698660, 1.432970, -0.952660, -1.107970, -0.026870,
-0.559300, -0.557170, 1.049440, -0.616930, 2.017310, -2.409390, -1.240680, -0.065400, 1.218680, 0.696060,
0.185170, -1.328520, -1.346350, -0.433040, -0.564340, -0.805980, 0.397960, 1.844380, -1.100650, 0.403870,
-0.691440, 0.213110, 0.888020, 0.481680, -1.445220, 0.175300, -0.533820, 1.062100, -0.970800, 0.006780,
-0.390050, -0.915060, -0.371390, -1.279410, -1.983930, 0.295770, 1.539440, 0.575270, 0.145680, 0.018300,
1.223560, -0.188430, 0.322100, -2.703280, -0.546460, 0.895250, 0.571960, 1.525120, 0.080380, -0.245550,
-3.352180, -0.806350, 1.093460, 0.418150, 0.640820, -1.092300, 0.850200, -0.672430, 1.234170, 2.408260,
0.797290, 1.244490, -0.343050, 1.042840, 2.275860, 1.211570, -1.328370, -0.622180, -2.208890, -2.065870,
-0.057680, -0.349400, -0.734910, -0.712420, 0.184430, -0.944680, -5.716360, -0.202220, -0.901880, -0.288810,
-0.282220, -0.964630, -0.545000, -1.176290, 0.208700, -0.615620, -0.819440, -0.850700, -0.454020, 0.089510,
-0.983480, -2.568710, -0.728870, 0.712450, 0.160530, -1.095090, -0.705100, -0.500010,
0.119680, -0.777790, 0.116960, -0.458940, 0.398080, 0.324450, -0.918540, -0.810880, -0.418170, -2.710780,
2.405000, 0.115020, -0.656640, -0.892970, -1.530040, -0.771870, -0.177060, -1.456420, -0.140970, -0.639320,
2.270570, -1.313530, 0.440140, -0.350260, -1.572070, -0.687280, 0.072830, 0.287780, 1.396920, 1.017640,
0.119820, -0.850490, -0.239640, 0.354070, -0.700520, -0.162040, 0.628220, -0.374510, 0.695460, -0.218120,
0.655430, 1.019120, 0.367270, -0.694730, -0.397430, -0.318500, -2.301690, -3.099220, -1.269640, -0.749220,
-0.124620, -0.852700, 1.080210, -0.380410, -1.269160, 0.872210, -0.633290, 0.536260, 0.411820, -2.067820,
0.031880, -0.129330, 1.314100, -1.244020, -0.632440, 0.896860, 0.138520, -1.439390, -0.196340, -0.100290,
-1.276280, -0.908310, 0.778140, -2.374350, 0.406750, -0.173470, 0.902740, -1.465790, -0.248950, 0.129500,
0.456650, -0.111450, -1.927220, -0.582250, -0.055690, -0.136250, -0.426850, 0.470480, -1.142480, -1.677280,
-1.890600, 1.060010, -0.141160, 1.259570, -0.162050, -0.324010, 0.240700, -2.075290, 1.010560, -1.341850,
0.792130, -0.723370, -0.731970, 0.769480, -2.172400, -4.544580, -2.239070, 1.224970, -1.344820, -0.964760,
0.496080, 1.438900, -0.388170, 0.468800, 1.700270, 1.486970, 1.346100, 0.600500, -1.463180, 0.438300,
-0.415980, 0.697650, -0.854060, 2.456420, -0.411940, 1.224220, -0.100410, -0.245730, 0.028210, 1.278810,
0.279620, -0.395390, 0.165080, 0.416930, 1.840470, 0.526820, 0.245030, 0.002120, 1.635280, 3.376410,
-1.518970, 0.050660, 0.089490, 0.353830, -1.103140, 0.678220, 1.380300, -2.853730, -3.133010, -2.946190,
-0.053230, 1.745050, 0.761120, -0.166230, -1.464480, -1.424110, -0.155770, 0.873030, 0.745560, 3.115030,
-0.152290, 0.867220, 5.846510, 0.248320, -1.708020, 1.001760, -0.940680, 0.181900, -1.541990, -0.322700,
-1.089740, -1.677300, -0.096500, 0.757800, 1.567830, 1.002300, -0.908230, -0.202750, 1.518170, 0.196020,
-0.430940, -0.583760, 1.639280, -0.284430, 0.287000, 4.484170, -0.502070, -0.840730, -0.130320, -0.621490,
-1.453410, -0.426090, -1.566010, -0.825670, -1.029860, 1.050730, 0.032320, 1.583670, 1.633000, -0.371990,
-0.627030, 1.206060, -0.072710, 0.571590, -0.985090, 0.319340, -2.127170, -0.899530, 2.553550, -0.338250,
-1.000630, 0.185790, 0.500580, 1.513990, -0.181270, -2.195650, 1.687030, 0.373890, -0.660750, 1.701970,
1.912460, 0.820540, -0.375150, 0.440400, 0.218480, -0.562280, 2.372620, -0.640530, -0.024740, -1.401650,
0.241100, 0.862260, -0.164560, -0.182920, -1.268240, 0.835850, -0.293820, 1.101480, -0.439700, 1.036680,
0.039530, -0.084150, -0.406280, -2.130040, -1.067340, 1.620160, -0.884620, -1.332460, 0.079700, 0.758620,
-0.910020, -0.672750, 0.587350, -2.343210, -1.209410, 0.894530, 0.315920, -0.302830, -0.255360, 0.835230,
0.808470, -0.333220, 2.317480, 0.752050, 1.537830, -0.279850, -0.683460, -1.221040, -1.188390, 0.018150,
-2.128170, -1.186540, 0.329010, -0.136170, 0.092200, 0.364600, -0.816870, -0.387080, -0.662430, 0.339790,
-3.498360, 0.142880, -1.012870, -1.323840, -2.272840, 1.958750, -1.711290, -1.048650, -0.888130, -0.096110,
0.124370, 0.433400, 0.464150, 0.049560, 0.601890, -0.025690, 0.439160, -0.127990,
0.564650, 2.095980, 0.700960, 2.564660, -0.994210, -1.030860, 0.849190, 0.377940, 2.559410, 0.231760,
3.053160, 3.220190, 0.871570, 0.268610, -0.154130, 1.916950, -0.411650, 2.010840, 0.231940, 0.195980,
0.664060, 1.705530, 2.640840, -0.637910, 2.873930, 5.257730, -0.232450, 1.382190, 0.644560, -0.703850,
-0.725580, -0.523830, 0.540430, -0.734620, 0.124750, -1.668640, 0.860240, 0.323120, 1.169190, 4.531090,
0.902890, -0.390680, -3.068500, -0.471330, 4.017950, -0.886550, 0.501450, -0.428410, -3.752230, 0.294590,
-0.748300, -3.242430, -0.125380, 3.910700, 0.638010, 0.343720, -2.248350, 0.653420, 0.495330, -1.175300,

0.759250, -0.327910, -0.315270, -0.436970, 0.463730, -1.976050, -0.084130, -0.311750, 2.097610, -0.674920,
-0.418200, 0.929770, 0.379910, 0.467920, -0.740260, -1.278420, -0.064700, -0.052760, -0.425080, -0.775470,
-0.633460, -0.312930, -0.361270, 0.785660, -0.509570, 1.940710, 1.298810, 1.158560, -0.640240, 0.559160,
0.182680, -0.660900, 1.374880, -0.964860, -0.714830, -2.328760, 0.975920, -0.777810, 0.555790, -0.226030,
0.006670, 0.035360, 3.729150, -0.561400, -0.483150, -0.733860, -0.395840, 0.907170, -0.943620, 0.049180,
1.049480, 0.099080, -0.406040, 0.800860, -0.426280, 0.539450, 0.194730, 0.569640, -0.679920, 0.110210,

-0.084810, -0.655630, -0.278010, 0.575770, -0.281700, 0.835090, 0.260340, 0.125740, 0.347140, -0.296010,
-0.223450, -0.547040, 0.044950, 1.286690, -0.505430, -1.968770, 0.757140, -1.205700, 1.495790, -0.396240,
-1.022500, -0.612030, -0.229530, 0.090180, -0.710310, -0.272800, -0.976010, -0.732110, -0.574740, -1.447300,
-0.631840, 0.618020, 0.236510, 0.165630, -0.344110, -0.131610, 0.702440, 3.128200, 0.775890, 0.511380,
0.431110, -0.000800, 0.526240, 0.546160, 0.533070, -0.475090, 0.531400, 0.379190, -0.194370, -0.120350,
0.205810, -1.101170, -0.421770, 0.054880, 0.021210, 0.432530, -0.012790, 0.633160, -0.747210, 0.087310,

-0.491300, 0.135840, 0.847130, -1.144320, 0.653930, 0.057390, -0.662530, 0.425520, 1.607730, -0.648290,
0.230820, 0.447840, 0.334900, -0.558010, -0.715330, -1.300640, -0.301600, 0.254480, -0.315850, 0.384630,
-0.798940, -1.281390, -0.293120, -0.788050, -0.691780, 0.248020, 0.634070, 0.225250, 0.582090, 0.870610,
-0.534090, 0.641770, 1.072800, 0.704840, -0.270370, 0.482410, -0.922460, -4.054390, 0.911240, -0.980390,
0.575390, 0.076140, -0.579930, -2.618820, -0.407130, -1.039910, 0.295050, 0.935440, 0.583230, -0.003010,
-0.704900, 0.374860, -0.268220, 0.545300, 0.412610, -0.845750, -0.070400, -0.340630, 1.039780, -0.724470,

-0.637890, 0.845330, 0.792880, 0.842890, -0.095630, -0.452460, 0.030890, 1.565700, 2.466570, -0.920210,
0.433780, 1.023400, 0.622190, -0.583070, 0.663530, 0.141070, -0.013430, 0.289070, -0.050030, 0.824140,
0.273800, 1.009000, 0.049080, 0.637510, 1.288050, 2.169840, -0.168560, 0.835420, -1.376210, 0.442410,
0.334510, -0.560670, 0.231160, 0.664640, -0.741360, 0.336010, 0.814350, -0.542750, 1.637980, -1.229230,
-0.378430, -0.674900, -0.383710, -0.183000, 0.775460, -0.265070, -0.749830, -1.431260, -0.204210, 0.901470,
-0.845170, -0.487580, -0.262530, -0.008440, -0.511680, -0.816710, 0.901160, 0.532210, 0.786270, -1.102580,

-2.800670, 0.555450, -0.021930, 0.189370, -1.098700, -3.351320, 0.053830, -0.459610, -1.595360, -0.576650,
1.072500, -0.207300, 1.787790, -2.182300, -0.104780, 1.780000, 1.766080, 0.563610, -1.899790, 2.522110,
-0.512850, 0.578760, -0.658270, -2.277170, 1.173040, 0.652320, -1.991470, 0.169390, 0.660010, 0.678620,
0.322070, -0.400230, 1.129570, 0.118320, 0.010270, 0.621560, 0.224080, -0.905180, 1.205380, -0.435440,
-0.665210, -0.352660, 0.176650, -0.285120, -1.081670, -0.104200, -0.558890, 0.528710, 0.441180, -1.832540,
0.368450, -0.770930, -0.361440, 0.154270, -1.313680, 0.152530, -0.698370, -0.521260, -0.623840, 1.058760,

0.493060, 0.366700, 0.028810, 0.127820, 0.820580, -0.754210, 0.132900, -0.086820, 0.020890, -0.341550,
-0.093480, 0.046640, 0.197450, 0.026370, -0.362080, 1.022890, 0.156950, -0.007350, 0.576220, -0.731100,
0.857760, -0.631470, -0.544560, -0.292550, -0.307300, 0.028450, 0.721160, -0.096470, -0.112230, 0.133830,
0.643700, -0.697350, 1.076840, -0.866800, 0.130850, -0.864080, 0.783280, 1.181460, -3.762820, 0.472860,
0.464140, -0.823770, -0.238640, 1.284730, -1.151920, 0.791300, 0.567350, 0.592120, 0.418610, 0.055540,
0.331670, -0.259110, -0.784700, 1.188160, 1.085360, 0.895450, -0.405630, -0.382320, -0.423180, -1.600120,

0.473690, 0.060710, -1.018360, -0.161250, -1.193700, -0.572980, -1.086870, -1.470410, 1.723460, 0.147470,
-0.346490, 0.216090, 0.088400, 0.647460, -2.730800, -2.315890, -0.227440, 0.021870, 0.314600, 0.359030,
-1.105520, 0.331670, -0.098830, -0.760340, 0.536400, 2.112450, -1.224860, 0.505810, -0.718880, -0.877640,
0.414490, 0.488340, 0.808760, -1.454300, 0.527010, -0.096160, -1.290990, -5.763210, 5.976010, -0.512160,
-0.228870, 0.232650, -0.454790, -0.155650, -0.175910, -0.271990, 0.532690, -0.006330, 1.230670, -0.249260,
-0.907400, 0.932040, 0.396930, -0.732890, 0.717620, 0.364740, 0.047700, -0.581470, -0.722890, -0.541980,

0.513290, 1.295840, 0.661860, 0.423460, -3.795440, 0.961720, -0.443030, -1.238620, 2.226770, 0.576520,
-0.007930, 1.473680, 1.006070, -0.930460, -0.752190, -2.078150, -1.640850, 0.456370, 1.783110, 0.179940,
-2.135740, 0.264940, -4.296560, -0.281280, 0.873830, -1.021290, 0.748890, -0.991410, 0.487420, -0.308260,
-0.170960, 0.477240, -2.285030, 0.588660, 0.731670, -0.674020, -0.945720, 3.909190, -13.782050, -0.059550,
-0.008700, -1.348630, -1.779930, -3.510760, -0.398680, 0.026560, -0.651000, -0.177420, 1.322270, 0.012580,
-0.229230, -2.806650, 1.942960, 1.152100, -1.630030, 0.629550, 0.724710, -0.714520, -0.468650, 2.692580,

-0.089130, 0.652480, 0.571940, 3.517470, 0.398750, 0.629320, 0.268380, -0.694650, -0.582050, 0.669040,
-1.004650, 1.154040, 0.000500, 0.549490, 0.253070, 0.179320, 0.890490, -6.762170, -0.752990, 0.042910,
0.371600, -1.666310, 0.175210, 1.502110, 0.317590, 0.099370, -0.042610, -0.244910, 1.010800, -0.732550,
0.003880, -1.251800, 0.392900, -0.569420, -0.676640, -0.829210, -0.784420, -0.327820, 1.468260, 0.523560,
0.526320, -0.803560, -0.591420, -0.477500, -0.406940, -1.043870, 0.289130, 0.599170, -0.781780, -0.743770,
-0.164230, 0.171400, -0.407980, -0.797960, -0.819790, -0.218390, -1.348770, 0.001980, 0.205370, 0.807330,

-0.945800, -1.013810, -0.692830, 0.249180, -0.137560, 1.692330, -0.794110, 0.013290, -0.904870, 0.997200,
-0.979240, -0.545230, -1.665030, 0.442700, 0.589890, -1.055490, -1.068540, 0.045010, -0.513650, -0.726070,
-0.200980, -0.865290, 0.375460, -0.628000, -0.812630, -1.365440, 0.533310, -0.723080, -0.352290, -0.488070,
0.051180, 0.922890, -0.092070, 0.806210, -0.132350, 0.239310, 0.622820, -1.459870, 0.623990, 2.545810,
0.179170, 0.526800, 0.003850, -0.613960, -0.965910, -0.890000, -0.469160, 0.629040, 4.719070, 0.104550,
-0.115790, -0.814990, -0.327410, 0.958180, 0.196290, 0.531830, 0.140140, -0.320720, 0.755480, 1.850230,

0.653120, -0.139250, 0.098420, -0.347800, -0.388550, -0.309000, 0.650680, 1.084360, -0.861110, -0.041250,
-0.392030, 0.539310, -0.010560, -0.194300, 0.631760, -0.183660, 0.073240, 0.239060, 0.080090, 0.340830,
-0.628390, 0.791620, 0.338000, 0.231920, 0.019770, 0.819850, -0.318300, 0.328980, 0.667420, -0.415010,
-0.042840, -0.747830, -0.969120, 0.078020, -0.515740, 0.669170, 1.010500, 1.613350, -0.720950, -0.472870,
-0.203640, 0.820970, -0.093480, 0.190030, -0.217480, 0.103250, 0.205280, -1.057230, 1.218750, -0.544460,
-0.801120, -1.256560, 1.335470, 0.083490, 0.676590, 0.505400, -0.459790, -0.336630, 0.670550, -0.310740,

-0.039850, 1.103230, 0.578350, -0.798220, -1.425630, -0.741020, 0.494700, -0.271520, 0.937230, -0.455000,
-0.776130, 0.399240, 2.605850, 0.722380, -1.548470, 0.451170, 0.134190, 0.476630, 0.615240, 0.703540,
-1.113640, 0.386970, -2.297070, 0.324160, -0.104170, 1.251100, -0.417150, 0.795350, -1.403280, -0.817580,
0.235870, -0.856830, -0.669870, -0.982100, -0.381300, -4.431410, -0.890150, 0.984320, -2.485390, -1.400680,
0.167900, -0.063900, -0.624070, -0.575220, 0.005280, 0.674150, -0.879210, -0.090770, -0.372940, 0.560180,
0.670400, 0.714770, -1.209660, -0.051040, 0.321120, -0.059370, -0.347330, 0.643840, 0.811760, -1.029300,

-0.227820, 0.225630, 0.451380, 0.365600, -1.340880, -1.500660, 0.788750, -0.404350, -0.820020, 0.262960,
0.703830, -0.327640, 0.830930, 0.017580, -0.523710, 0.335790, 0.853760, -0.596080, -1.634730, 0.668170,
-0.109490, -0.239490, -0.185140, 0.120630, 0.635210, 0.939370, -0.589950, 0.426620, -1.598980, 0.556120,
0.592280, 0.531790, 0.277930, -0.163070, 0.204500, -2.854530, -0.660330, -0.299500, -3.446870, -2.479300,
0.318490, 0.721040, 0.517910, -0.425680, -0.945240, -0.381020, -0.702390, 0.496370, -0.906140, -0.110920,
-1.087480, -0.281190, -2.520450, 0.305270, 0.298460, -0.248790, 0.163290, -0.302040, 0.551960, -1.214690,

0.286040, 0.254200, 0.163260, -0.516730, 0.474390, 0.099270, 0.428990, -0.292450, -0.101250, -1.024250,
-0.081750, -0.370230, -0.026100, -0.376660, 0.458970, -0.193950, -0.105390, 0.834340, -0.551310, 0.354160,
-0.073250, -0.303200, 0.748330, -0.196310, -0.424510, 0.277920, 0.284590, -0.005810, 0.475160, 0.406900,
-0.147750, 0.794310, 0.221950, -0.665560, -0.689220, 2.028830, -0.996030, -1.239050, -1.260570, 0.430630,
0.766970, 0.468050, -0.820170, -0.299220, -0.838400, 0.034620, -0.473890, 0.101720, 1.372840, -2.046810,
0.016300, -0.776170, -0.372510, 0.995910, -0.089410, -0.500710, -0.002700, -0.535300, 0.843420, -0.401240,

0.186140, 0.444970, 0.776480, -0.790500, -0.433240, -0.853120, -0.729480, -0.472540, 0.548900, -0.762090,
0.561060, -0.425680, 0.593400, -0.229570, -0.892760, 0.487870, 0.490330, 0.023030, -1.084180, -0.044620,
0.184450, -1.005610, -0.075850, -1.048250, 0.632900, 0.459550, -0.060040, -0.368630, -0.501800, -0.392340,
0.815000, 0.909590, -0.211460, -0.525510, 0.139640, -2.353680, -0.809860, 5.827270, -4.825200, -2.867640,
-0.942170, 0.174320, 0.667730, 0.924950, -0.694320, 0.746380, -1.098310, -0.091690, 0.250790, -0.875310,
0.744150, -0.345900, -0.502520, -0.227020, -0.637850, 0.599400, 0.683820, -0.407680, -1.072690, -1.608710,

0.881310, -1.545740, -0.915110, 0.083420, 0.936650, 1.735470, -0.794490, -0.373260, -2.052740, 0.423730,
0.151870, -0.724390, -3.056960, 0.299340, 0.486830, -1.414690, -0.908030, -0.427500, 0.160840, 0.775450,
1.075800, -1.043720, 0.378190, -0.251410, -1.980050, -1.619970, -0.177970, 0.666140, 0.591600, -0.505780,
-0.473370, 0.302920, 0.966840, -0.288800, 0.593360, 2.584690, -0.575840, -1.153630, -0.443600, 2.080740,
0.699540, 0.700920, 0.425050, -3.022120, 0.357970, -0.954350, -0.057200, -0.198130, 6.282990, 0.318180,
-0.820030, -0.585690, -0.239460, 0.136240, 0.311470, 0.548290, 0.252240, 0.483030, 0.785630, 1.713030,

-0.380600, -2.783500, -1.278130, -0.901710, 1.900880, 1.374360, -0.677200, -0.003540, 1.877540, -0.249080,
-0.340320, -1.068000, -4.069650, -0.028440, 0.270300, -1.935770, -0.645490, -0.772610, 1.657570, -0.664550,
0.049640, -2.755530, -0.187120, -0.095430, 0.172060, 1.650140, -8.900580, 0.563290, -0.220370, -5.018380,
0.183910, -0.407130, 0.562660, 0.683880, 0.140260, -5.275220, 0.389970, -0.694420, 3.077200, 2.088320,
-0.192920, 0.791890, 0.464210, 1.713850, 0.716660, -0.654200, -0.750890, 0.809650, -0.304470, -0.095640,
0.140350, 0.666310, -0.540710, 0.616380, -0.204310, -0.162550, -0.228340, -0.496680, 0.367080, 0.226800,

-0.582340, 0.034420, 0.115120, -0.138700, -0.114620, 0.574070, -1.129810, -0.176740, -0.106300, -0.444300,
0.903320, -1.197870, -0.209690, -1.014940, -0.500310, -0.687480, -1.032040, 1.028770, -0.455960, 0.018480,
-0.158780, -0.139970, -0.595690, -0.169430, -0.298200, -0.047510, 0.620190, 0.014950, -0.271700, 1.057450,
-0.209780, 0.558890, 0.675460, 0.258100, -0.256160, 1.986260, 0.526880, 1.325900, -6.953750, 3.427230,
-0.599780, -0.119280, -0.545960, -0.869420, 0.253420, 0.060450, 0.082490, -0.000380, 0.279180, -0.295960,
0.205480, -0.562880, -1.734350, -0.271060, 0.077790, -0.792540, -1.011230, -0.402620, 0.720140, 0.469220,

0.545680, 0.047160, -0.458830, 0.232640, -0.399740, 0.439620, -1.343430, -0.392500, -0.193570, 1.438540,
0.477840, 0.255110, -1.362240, 0.354900, 0.444460, 1.000410, 0.799860, -0.685640, 0.640620, 0.397510,
-0.047610, 0.895200, 0.511870, -1.318990, -0.199120, 0.234340, 0.034420, 0.498610, -0.863560, -0.516410,
0.325800, -1.702960, -1.409950, -0.286570, 0.587820, 1.541550, 0.211610, -0.485740, 2.095850, -0.119230,
0.054990, -0.866280, -0.208020, -0.711350, -0.841100, -0.820490, -0.278410, -2.648030, 1.115220, -0.795400,
0.111420, 0.334810, 1.314160, -2.132340, -0.008860, -0.716860, 0.492580, 0.692780, -0.666070, 0.413040,

0.544570, 2.089110, 0.339950, 0.152960, 0.784800, 0.115930, 0.222330, 0.544820, 0.593110, -0.309340,
0.850720, -0.416410, 0.110020, -1.297350, 0.343950, -0.600990, -0.743930, 0.746340, -0.741250, -0.394500,
-0.239160, -0.680530, -1.364470, -0.036740, 0.050830, 0.587440, 2.065550, -0.183010, -0.240290, 1.010740,
-0.192560, 0.848640, 0.796930, -0.721960, 0.242250, -0.170890, -0.349100, 1.010630, -0.128350, 7.115470,
0.393260, -0.364900, -0.647580, 0.295030, 0.928050, 0.325060, 0.323640, 0.994420, -3.698580, -0.334660,
0.788070, -0.112190, -0.024000, 1.649700, -0.418860, 0.508380, 0.728490, 0.859080, 0.624520, 0.462700,

-0.076780, 0.877460, -0.200860, 0.471950, -0.190410, 0.167380, -0.666190, 0.168720, 0.853930, 0.331620,
0.059360, 0.425800, 1.763330, -1.310980, -0.001700, 0.096140, 0.357590, 0.842050, 0.270140, 0.324220,
-0.285160, 0.635270, -0.560320, 0.339380, 0.547370, 0.768050, 0.142240, -0.054040, 0.651010, 0.401550,
0.963660, -0.470650, -0.390160, 0.198970, -0.905910, 0.395660, -0.081870, -2.499370, 2.355840, 0.105710,
-0.321760, 0.722330, 0.313640, -0.250410, -0.372530, -1.363480, 0.403060, -1.698630, 1.783870, -0.014200,
-0.335310, -0.176690, 0.281980, -0.291070, 0.176880, -0.657090, -0.758440, 0.742880, -0.762710, 0.351640,

-2.205310, 0.071740, 0.447240, 0.188710, 0.646450, 1.554980, -1.218370, 1.681820, -1.003170, 0.699280,
0.443090, 1.247570, -1.109760, -1.877510, -0.347640, 0.704700, -1.842630, -0.746370, 0.546100, -0.556950,
0.910790, -0.865580, -1.599060, -1.293910, -0.978250, -0.402650, -0.150600, -0.005810, 1.775640, 0.979280,
-0.225580, 0.263570, 0.016800, 0.707130, -0.016700, 3.120090, -0.813360, -0.191240, -0.249570, 0.064370,
-0.226880, 0.705770, 0.271210, -0.016900, -0.367000, 0.697360, 0.575830, -0.724270, 1.551890, 0.235920,
-0.439970, -1.706890, 0.675120, -0.407060, 0.842030, -0.637050, 0.482860, 0.084680, -0.551560, 0.684450,

-0.051390, -0.210970, -0.028500, 2.134170, 0.007420, 1.137570, 0.027000, -1.208850, -1.291170, -0.229140,
-0.857050, -0.857240, -0.913490, -1.020570, 0.242360, -0.758740, 0.381940, -0.727580, 1.183560, -1.033920,
0.954070, 0.032400, 0.416700, 1.273880, -0.649790, -1.964180, -0.423190, -0.467590, -0.068770, -0.157030,
0.490560, -0.557720, 1.115150, -0.550020, -0.675210, -4.300770, -1.137750, -2.931840, 0.842270, 1.357730,
0.923240, 0.240360, 0.527780, 0.217000, 0.476970, -0.818070, -0.466990, 0.603650, -0.194410, 0.384080,
0.221430, 0.275680, -2.569810, 0.222610, -0.702510, -0.450340, -0.765730, 0.440550, -1.066480, 4.092550,

0.657510, 0.930540, -0.571020, 0.534640, -1.048630, -0.725940, -0.912250, 0.126610, 2.324860, -0.105060,
-0.081020, 0.256220, 2.330420, 0.482800, -2.206620, 0.135580, 0.184980, 0.084370, -0.172200, -0.295490,
-0.996770, 0.131210, -0.528940, -0.895610, 0.461530, 0.297210, 0.641360, 0.479360, -1.631650, -0.560920,
-0.169670, -0.049150, 0.606640, -0.520820, 0.056610, -1.227860, -0.610530, 4.700160, -0.093920, 0.697310,
-0.484110, 0.497200, 0.114140, 0.406470, 0.099650, 0.717640, -0.531090, -0.511430, -0.589210, -0.302170,
0.665530, -0.735600, 0.926120, 0.276540, -0.307300, 0.712810, -0.014580, -0.211840, -0.688890, 0.141330,

0.100190, 1.073520, -0.639330, 0.864420, 0.900580, 0.534170, 0.693390, 0.132470, -0.044640, -0.966160,
-0.184990, -0.390090, 2.374680, -0.882540, 0.223920, 0.950650, 0.342250, 0.640010, -0.331590, 0.128940,
0.656510, 0.536730, -0.062010, 0.072510, 1.072180, 0.364220, -0.026370, -1.053660, 0.145100, 0.094970,
-0.244020, 0.037940, 0.723790, -0.598450, -0.146230, -1.586440, -0.970660, -0.690070, 0.150990, 1.339480,
0.412950, 0.626300, 0.642700, 0.643020, 0.035700, 0.293960, 0.560930, 0.273710, -0.020420, -0.517640,
-0.341670, 0.824740, -1.019880, 0.693140, 0.369670, -0.760510, -0.903210, -0.399380, 0.383700, 0.300710,

-0.591490, 1.120810, 0.628270, 0.868200, -0.197690, -2.162430, -0.690960, 0.414970, 4.329260, 0.392390,
0.650840, 0.792560, 1.396290, -0.190300, -0.671660, 0.471960, -0.030410, 0.379200, -0.370940, 1.317510,
-0.540660, -0.075750, -0.377570, -0.224130, -0.010700, 2.227150, -0.106660, 1.132450, 0.427320, 0.951280,
0.671750, 0.917690, -0.225050, -0.681550, 0.713760, 4.077620, -0.690350, 2.814030, 1.132690, -3.212070,
-0.099720, -0.529250, 0.733370, 0.491250, 0.567880, -0.221760, -0.585190, -1.044660, 0.564910, -0.604100,
-0.545910, -0.006420, 0.985030, -1.169070, 0.221430, -1.029210, -0.340710, 0.501990, 0.075670, -1.823700,

-0.671570, -0.343640, 0.586760, 0.917100, 1.664440, 2.122770, -0.833430, 1.071140, -2.220440, 0.105010,
-0.466340, -0.334940, -0.866450, -0.851500, -0.460380, 0.521260, -1.006110, -0.144360, -0.135700, -0.479720,
0.818970, 0.089330, 2.269980, -0.048650, -1.305610, -0.971350, -0.387660, -0.832300, -1.435100, 0.114950,
-0.000510, 0.408590, -0.195910, -0.936140, -0.188460, -1.435900, 0.526630, -0.972450, -1.424020, 1.590530,
-0.302690, 0.750990, -0.595610, 0.181500, -0.628970, -0.189090, 0.536140, -0.817360, 1.066520, -0.529410,
-0.209850, 0.284000, 0.253850, 0.790910, 0.711770, 0.996910, 0.709880, 0.447360, -0.540460, 1.126110,

0.181200, -0.022850, 0.362110, 0.692970, -0.878070, -0.276490, 0.654140, 0.653090, -0.393400, 1.003730,
-0.038720, 0.589620, -0.735840, 0.324340, 0.366810, 0.014860, 0.428150, -0.517320, 1.160430, -0.067330,
-0.341360, 1.212760, 0.038020, 1.100490, 0.100810, -0.453630, -0.463870, 0.779530, -0.124750, -0.074750,
-1.194680, -0.302530, -1.316660, 0.941980, 0.256180, 0.536270, 0.584970, 4.131600, 0.275190, -0.328700,
0.202860, -1.054500, 0.690040, 0.074010, 0.420280, 0.397910, 0.807560, 0.805240, 0.304060, 1.467980,
0.153870, -0.808910, 1.249450, 0.419750, 0.527210, 0.608270, -0.252340, -0.459980, -0.722410, 2.159430,

0.851740, -4.090920, -1.323390, -0.836910, -0.353950, 0.910500, 0.109640, 0.354100, -2.494400, 0.112060,
-1.561920, -1.369010, -2.071990, 0.659260, 0.039080, 0.669980, -0.656510, -2.099550, 2.038300, -0.829530,
0.719190, 0.461890, 1.003480, 0.583600, -1.778270, -2.236510, -2.077600, -0.922570, 2.105140, -0.909110,
0.701590, -0.894870, 1.141350, -0.547670, -0.155340, 5.657010, -0.674270, -0.417240, -1.965720, -0.605090,
0.707340, 0.066250, 0.625400, -0.244560, -0.645040, -0.221910, 0.515550, 0.135700, 1.383880, -0.215220,
0.551100, 0.347640, -0.456480, 0.306890, 0.043620, -0.964990, 0.288410, -0.843570, -0.099760, -0.571630,

0.837760, -0.057840, 0.331820, -1.269480, -0.189010, -0.001100, -0.144990, -0.039430, -1.450350, -1.974860,
-0.616590, -0.024020, 0.647100, 1.238460, -0.082190, 0.889140, -0.730610, -0.174220, -1.359650, -0.911680,
0.492470, -1.477510, 0.396680, -0.306070, 0.311760, 0.292350, 0.878960, -0.197440, -0.446270, -1.435560,

-0.599750, 0.670240, 1.094050, 0.361280, -0.761090, 1.181850, 0.237480, -0.284990, -0.156480, 1.495980,
0.796340, -0.529350, -0.858880, -1.018580, 0.765450, -1.112160, 0.320700, 0.363220, 1.344220, -1.084710,
0.441540, 0.800350, -0.304170, 0.011940, -0.767010, -0.317290, -0.522900, -0.130490, 0.213370, 0.217370,

0.850180, -0.574450, -0.654880, 0.003630, 0.603400, -0.555500, -0.410520, 0.466310, 0.547880, -0.735140,
-0.571010, -0.353910, -0.333760, -0.478280, -0.907020, -1.551980, 0.091860, -0.877510, -1.555300, 0.748890,
0.242880, 0.485120, -0.086230, -0.123530, -0.133210, -0.587960, 0.235590, 0.539980, -0.953690, 0.637580,

-0.038180, 0.324840, 0.382530, -0.651230, 0.569640, -1.452920, -0.654380, 2.433030, -3.144530, -2.049700,
-0.021460, -0.263120, 0.966890, 1.354580, 0.201980, 0.808820, -0.623160, -0.214570, -1.824850, -0.527180,
-0.365020, -0.677810, -0.321060, -0.484680, 0.438060, 0.645760, 0.626750, -0.583220, 0.317640, -1.915810,

-0.908410, 0.664550, 0.603720, -0.579830, -0.327360, 0.377990, 0.255290, -1.787180, -0.433220, 1.692580,
0.102170, -0.850630, -0.359640, -0.715890, 0.186890, -1.152830, 1.053290, 0.852910, 0.405610, -1.145620,
-0.646740, 0.144890, -0.561740, 0.674740, -0.265200, -0.316990, -0.660940, 0.955140, -0.779900, 0.842350,

-0.495130, -0.720710, -0.480020, 0.178630, 0.529700, 0.650280, 0.218000, -1.728640, 1.745830, -0.769550,
-0.301290, -0.152340, -0.743960, -0.724540, 0.630410, -0.971120, -0.016750, -1.040200, -0.572180, 0.487810,
-0.527360, 0.787200, 0.500630, -1.092130, -0.241670, -0.879810, -0.052170, 0.706380, 0.303950, -0.084880,

-0.358950, -0.087640, 0.433420, -0.561400, 0.330920, -2.172060, 0.523350, 2.530700, 3.065830, -2.056570,
-0.427000, 0.546700, 0.746910, 1.000270, -0.360110, 0.215820, -0.303460, -0.221690, -0.805690, -0.674190,
-0.429690, 0.348610, -1.283460, -0.047580, 0.628600, 0.049580, 0.552130, -1.488330, -0.831480, -2.062550,

-0.508830, -0.296470, 0.939510, -0.595170, -0.375270, -1.485330, 0.258640, -1.845060, -1.961580, 1.277640,
0.337390, 0.371530, -0.355360, -0.590630, -0.132010, -1.346880, 0.439700, 0.861520, -0.370220, -0.215360,
-0.809530, -0.154850, -1.438120, 0.760300, -0.797730, -0.127620, -0.429990, 0.261940, -0.743950, 1.203760,

-0.036700, -0.620440, -0.857070, 0.863120, 0.162650, 1.771730, 0.950650, -1.067140, -1.914290, -0.741680,
0.185720, 0.455190, -1.075700, -0.399480, -0.280470, -0.699520, -0.113700, -0.917890, 0.765130, 0.205180,
-0.536510, -0.257670, 1.149290, -0.056310, -0.248750, -0.468260, 0.600010, 0.983620, -0.460560, -1.028540,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.047590, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, -1.265990, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, 0.124550, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.588610, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.435990, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -1.241370, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.782740, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, -0.022360, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, -1.241210, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, 0.377580, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.123600, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.521480, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, 0.251760, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -0.128330, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 0.706260, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, 0.030530, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, 0.214300, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, -0.557130, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -1.237200, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 0.888180, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, 1.242740, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.426720, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, 0.726270, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -1.058660, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.010190, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, -1.356940, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, 0.570620, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, -0.834640, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, -0.563290, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -1.300230, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -0.965540, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, 0.782270, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, 0.714480, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.736840, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, -0.084300, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.960340, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, 0.667790, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.415120, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -0.853550, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.822830, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, 0.537740, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, 0.677180, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, -0.100950, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.734100, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, 0.622440, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, 0.532920, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.227520, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, -0.485390, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.227760, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, -0.373110, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, -0.673520, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.836980, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.258350, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.278800, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, -0.330140, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, -0.124800, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.930140, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.711550, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 1.025720, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.243950, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.934730, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.871360, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, 0.264540, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, -0.665670, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.338050, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 0.722300, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, 0.874830, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.648660, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.588630, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
0.03275, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.04796, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
1.42040, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
0.42856, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
1.40138, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
0.00420, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
1.39092, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
1.42840, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
0.00019, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
0.71152, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
1.42016, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
0.30805, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
0.00180, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
0.00820, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
1.30316, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
0.19162, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
0.09033, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
1.12395, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
1.39633, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
0.03390, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
1.42855, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.13086, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
1.41812, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
0.00003, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
0.00097, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.03417, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
1.42845, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
1.17143, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
1.12510, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
0.40266, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.42772, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
0.58488, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
0.01287, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
0.35636, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
1.40145, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.00061, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
0.93036, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
0.00022, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.00012, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.00250, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
0.32980, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
1.36422, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.00150, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
0.00175, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
0.23166, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
0.01322, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
1.21407, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.00002, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.01150, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
0.71305, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
1.42477, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
0.53927, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
1.30413, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
0.00426, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.00639, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.18689, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
1.32448, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.42277, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
1.39319, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.11631, 0.500000, 2,
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
