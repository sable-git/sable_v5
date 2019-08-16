/*********************************************************
  ELMAN268-30-30-9ENTROP2.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:05:23 2004
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
0.616700, -0.857230, -0.703420, 0.938730, -0.677990, -0.383260, 2.452170, -0.749360, 0.354030, -0.082650,
-1.188240, -0.491180, 0.511890, 0.565870, 0.816380, 0.848230, 1.308710, 0.455310, 0.784330, -0.466420,
-1.010710, 0.443260, 0.201880, 1.483600, -0.361920, -1.617880, 0.087230, -0.864110, -0.337620, 1.396980,
-0.062620, -1.601620, -0.705650, 0.407960, 0.185340, -0.335270, 1.729690, -0.621640, -0.379610, 0.251100,
0.840210, 0.443080, 1.426790, 0.424470, -0.370550, -0.077000, -1.140180, 1.653900, 0.714580, -0.476510,
-0.802210, -0.251980, -1.942640, 0.496280, 0.591950, -0.509090, 0.056780, 0.228530, 0.136850, -0.108190,
-1.803510, 0.510150, 0.144150, 1.950570, 0.155880, -0.710180, 4.283160, 1.704470, -1.539510, -0.205720,
0.082190, 2.155280, 0.416120, 0.291470, -1.557350, -0.066370, 1.848030, 1.778910, -0.186890, -0.287330,
2.052600, 1.474020, 1.941330, -1.001890, 1.925470, 1.418340, -0.406230, -0.328610, -0.241340, -0.157840,
0.918570, -0.517110, -1.372100, -0.165400, -0.576750, -3.141260, -1.475020, 0.097610, 0.279910, -0.463810,
-1.749260, -1.037860, -0.513090, -0.834390, 2.040080, 5.732560, 0.045030, 0.605490, 1.521690, -0.378550,
0.215640, -0.541480, 0.112570, -0.106940, -0.507230, -0.590010, -0.428630, -1.788010, -2.004530, -0.882970,
0.950130, -0.556680, 0.550450, -0.212120, 0.917800, -0.498900, -1.300420, 1.107080, 4.019190, -1.042090,
-0.522380, 1.046740, 0.497460, 0.598360, -0.099710, 0.213580, -2.683140, -0.668000, -6.293160, -3.776220,
3.371960, 3.403180, -0.453340, -0.146600, 0.069440, -2.185390, -1.019010, 5.330000, 2.239850, -1.405330,
1.272460, -4.443470, -0.289160, 1.551150, 3.533250, -0.465120, -3.991560, 0.091840, -0.586650, -0.727370,
1.025290, 0.128710, -7.996880, 0.797800, 3.939750, -0.182250, 1.037150, 0.154830, 0.884340, 0.061660,
1.677590, 1.543660, -0.238400, 0.453430, -6.189610, 0.759690, 2.153760, 0.781530, -2.143690, 0.789040,
0.449300, -1.852110, 0.272970, 0.893190, -1.163050, -7.771550, 2.179710, 3.318740, -0.872500, -1.744410,
-0.147160, 1.426420, -2.672840, 0.788860, 1.664900, -1.198130, 2.073790, -3.641950, 0.244300, 1.637570,
1.506590, -0.592170, 0.402480, 2.365610, 0.222570, 1.192160, -0.566090, -0.092220, -7.796540, -2.044490,
2.340920, -0.251620, 0.569110, -0.148630, -1.386370, -3.359170, -1.847230, 0.584290, 1.759970, 0.281650,
1.027590, 1.405900, 0.407270, 2.789700, -0.705170, 0.894000, 2.092660, -1.926320, 0.488490, -1.111480,
0.353980, -0.445090, -0.021850, -1.360440, 0.220170, 0.048380, -1.579800, 0.718270, 1.862000, -0.001890,
-0.231300, 1.845700, -2.158280, 1.292800, -1.098890, 0.939170, -1.770980, 0.434370, 0.775890, 0.800900,
-0.222530, 0.644870, 1.132390, -1.539510, -1.207660, 0.038730, 0.041640, 1.460620, -3.331610, -1.031730,
-0.389160, -0.120420, 0.240860, -4.132380, 0.225940, -1.097040, 1.780270, 0.971170, 0.481500, -0.191950,
0.842840, 0.156150, 1.376540, 0.927120, 2.047680, 0.052720, 0.425900, 1.746820, 1.135400, 1.621380,
2.614620, 0.701610, -0.091010, 0.487000, -0.092390, 0.157670, -1.088910, 1.544560, -0.209600, 1.168250,
0.469680, -0.361900, 1.693610, 1.231670, 1.009740, 0.416320, 1.521400, 0.600550,
0.301100, -0.104750, -0.133130, -0.229520, 1.067170, 1.543660, 1.075480, -0.748220, 0.885310, 0.229290,
-0.936190, 0.028390, 2.248160, 1.211240, 1.151010, -0.237110, -0.038070, 1.177190, -1.396740, 1.593640,
-0.226210, -0.309290, 0.626330, -0.172400, 0.014070, 0.709640, 0.234830, -0.213690, 0.028370, -0.714330,
-1.603710, -0.000090, 0.933170, 0.738690, -0.776660, -0.785060, -1.947290, 0.621050, 0.013790, 0.526950,
-0.552700, -0.599650, -1.605430, 1.402800, -0.488290, -0.235620, -0.747440, 0.794700, -0.314630, 1.955360,
-1.905610, 0.423380, 0.935860, -1.212180, -0.464710, 0.560350, 0.298830, 1.531690, 0.092990, 1.377560,
-0.221320, -0.724250, -0.271340, -1.229460, 0.556390, 0.441510, 0.010410, -0.684380, -0.252350, 0.899930,
2.540860, -1.621790, -1.498400, -0.356180, 0.242840, -0.245320, 2.274160, -1.974520, -1.421520, 0.506080,
0.303800, -0.175580, -1.068670, 0.648660, -1.839260, -0.326310, -0.196250, 0.535760, 0.151000, -0.275310,
-1.006000, 0.776750, 2.022600, 3.812620, 0.103740, 1.398890, -0.847820, 2.787540, -1.312120, -0.568490,
4.651940, 1.648230, -0.094970, -0.451280, 1.069190, -0.675940, -0.171450, 0.614190, -0.386960, 0.052650,
-2.094790, 0.057880, 1.562860, -1.588050, -0.277920, 0.813510, 1.801820, 1.573930, 2.607830, -0.175080,
1.313170, -0.347420, -2.267150, 3.396960, -0.672380, -3.736590, -0.459610, -0.005430, 0.462740, -0.590750,
-0.006880, 0.076960, -0.051450, 2.105990, 0.548520, 3.181470, 0.180960, 0.312610, 0.290840, -1.374620,
0.162580, 2.876310, -2.467400, -0.868760, 0.868920, -0.993240, 0.438530, 0.213730, -1.578860, 0.800650,
-0.398280, -0.303300, -0.039800, -0.214480, -0.315580, -1.447020, 4.462980, 1.290940, 0.341370, 0.607590,
-0.548070, 0.366830, -0.706830, -0.771770, 2.504920, 0.182970, 0.192710, 0.501890, -0.863380, -0.104580,
0.938390, -1.829690, 0.516740, -0.484700, -0.173260, -0.278680, -1.879280, -1.254620, 0.080450, 2.646710,
1.414530, -0.452630, -0.221800, 0.863700, 1.644010, -0.911420, 1.439030, 5.105250, 0.178220, 0.147090,
-2.059850, -0.660470, 1.228560, 0.244070, -2.306930, 0.513920, -0.904610, 0.543620, 0.314810, 0.324560,
-0.524020, 2.274690, -0.391130, -1.597940, 1.915420, -1.226640, -1.561860, -0.047740, 4.299670, 1.612440,
0.217240, -1.430250, -0.239930, 1.206200, -0.453990, -0.566720, -0.454770, -2.664380, -2.740010, -0.619390,
-0.284580, 1.125620, 0.129180, 2.288530, -0.594970, 1.811330, 0.959940, 1.478000, 0.285020, -0.336120,
1.744210, -2.083210, 1.566880, 3.614940, 0.706610, -1.290120, 0.808820, -0.927270, -1.546420, 1.513740,
-2.899440, 0.693740, -0.996230, -1.406530, -2.270810, 0.995760, 0.805950, -0.557630, 3.149550, 1.143680,
0.059490, 0.052100, 0.289060, -0.817090, -1.123100, -0.340180, 1.828820, -0.770170, -0.893390, -0.693370,
0.137210, 1.024580, 1.110360, 0.509020, -0.177490, 0.403960, -1.182470, -0.120090, -0.170710, -0.327160,
-1.080530, 0.554870, -0.012590, -3.635480, -0.502720, -0.439040, 0.281760, -0.961330, -1.051020, -0.031330,
1.986430, -0.384920, -2.087380, -0.800090, -0.921710, 0.590960, -2.103050, 0.000620, -0.717120, 0.727030,
-0.653000, -0.727930, -0.958440, 1.021290, -0.033820, 0.550670, -3.091930, -0.747160,
1.026280, -0.389600, 0.128120, 1.370950, -0.810430, 0.543910, -1.836220, -1.059960, -0.487000, 0.900520,
0.403610, -0.104850, -1.142950, 0.293060, -0.775870, -0.942150, 2.668500, -1.541720, -0.035410, 0.470690,
-1.059890, -1.343950, 1.568180, 0.151640, -1.008030, -4.217390, 0.286610, 0.492950, -0.461060, 1.698650,
-0.053730, -0.765910, -0.368040, 0.870460, 1.459840, -1.365750, -1.030320, -1.197770, 1.598190, -1.595140,
-1.299810, -0.230010, 1.300920, -0.589720, -0.404650, -0.209390, 0.735460, -0.530470, -0.801680, 1.506280,
-0.252380, 1.775600, -0.449190, -0.301010, -0.135930, 0.872130, -1.206300, -0.302330, -0.080120, -1.665030,
1.591530, 1.073280, 0.474700, -0.607380, 0.933350, -0.827320, -2.250270, 0.094120, 1.644510, -0.298230,
0.493690, -0.236300, -0.997690, 0.257820, 1.502540, -1.558390, 0.002180, 0.420510, 2.784910, -0.436890,
-0.120600, 0.940270, 0.804960, -0.928890, -0.736180, -1.094560, 0.452150, -0.065310, 0.395830, -0.481180,
-1.191020, 0.263510, 1.574750, 4.751450, 2.361690, 1.944050, -0.142370, 0.046390, -0.778920, -0.693960,
1.128810, 0.345590, -2.130860, -0.638810, 0.252850, 0.524770, -0.063380, -0.276310, -0.504280, 0.214900,
1.900900, -0.513070, -1.170360, -0.116280, -0.378100, 0.601380, 3.044130, 1.033880, -0.888740, -1.095510,
1.273260, -0.612280, -1.767740, -0.189990, 0.567700, -3.369200, -1.029940, -0.204750, 1.680550, 0.140850,
-1.269760, -0.609090, 0.693420, 4.258480, 2.420150, 0.324440, -0.871960, -0.109980, 1.114940, 3.014480,
0.395240, 0.331600, -1.821190, 0.623280, -0.977440, 0.216670, 2.971930, 0.226530, -8.583160, -0.541130,
0.595250, -0.388470, -0.614130, -0.802050, -0.708970, 1.719130, 2.020570, 2.018820, 1.370330, 1.028170,
0.299310, 2.285810, 0.438510, 0.318180, -0.551420, 0.278690, -0.952220, 0.352110, 0.316460, 0.299080,
0.022940, -4.546770, -0.480870, -1.049240, 0.917550, -1.151470, -1.005400, -1.394440, 0.616610, 1.049290,
-0.194310, 0.326260, -0.883030, -1.097090, -0.553560, 0.648460, -1.866120, 1.277570, 0.775880, -0.934070,
-0.006330, 0.000600, -0.262230, -0.437660, -3.297400, -1.238350, 1.066130, 0.133520, -0.034590, 0.426340,
-0.947320, -0.459570, 1.863080, 1.444000, 0.392260, 0.324920, -0.453050, 0.940470, 0.859590, -0.286790,
0.297880, -0.480450, 1.627270, 0.380650, 0.349840, 0.083990, -0.905730, -1.045380, 0.831310, 1.568710,
-0.814320, 2.526940, -1.077890, 0.885470, 0.157440, 1.322630, -0.426280, 0.531090, -0.925790, 0.472290,
-1.048080, -1.134830, -0.465870, 2.199690, 1.686050, 3.698120, -0.039890, -3.129240, -0.286540, -0.810080,
-0.520160, -2.604300, -1.348410, -1.001330, 0.247860, -0.093320, -1.959330, -0.581470, 2.708220, 0.289240,
1.449880, -1.469810, 1.568200, 0.035160, -0.539150, 0.402330, -0.938140, -1.067970, 0.236210, 1.689060,
-0.714840, -0.008910, -0.739730, 0.595720, 2.058750, -1.443720, 0.804940, -0.789680, 1.379180, 2.637520,
0.419920, 2.460740, -0.513650, 0.375010, 1.363930, 1.294640, 1.622040, 0.761800, 0.339120, 1.463230,
1.733160, -0.208460, -0.386460, 2.124570, 0.445860, 1.462630, 0.177380, -0.219110, 1.262680, 0.478230,
0.384950, -0.212810, 1.025720, 1.032290, 1.371850, 2.859820, 0.742840, 3.499450,
0.623040, -0.757880, 0.944850, 1.256640, 2.666310, -0.325140, 1.060310, -0.917940, -0.841940, 1.529950,
0.294910, 1.369690, -0.696860, -0.128960, -1.083310, -0.916900, -0.621290, -0.598700, -0.244180, -1.803820,
0.816580, 0.707100, -0.860390, -0.546710, 0.409800, 1.802490, -0.892470, 0.223520, -1.056460, 1.298840,
0.299640, 0.061090, 0.831010, -1.728440, -0.976550, -0.076650, 0.489310, -0.385480, -1.614500, -1.650370,
0.672090, -0.663690, -0.072240, -2.560860, -1.300180, 0.062320, 0.576520, 0.106030, 1.272960, 2.209880,
-0.315450, 0.435790, 0.377190, 1.330410, -0.968980, -1.358540, -1.406130, -1.825630, -0.332120, 1.154560,
-0.243380, -1.118520, 0.693100, 0.345240, 1.162170, -0.116570, -0.222980, -2.269710, -0.161860, 0.698800,
1.558760, -2.333790, 1.424510, 0.261170, 3.481390, 0.896030, -0.925940, 0.412540, -1.994050, -3.298440,
-0.869360, -1.292410, -0.720190, -0.037500, 0.504360, 0.052400, 0.106490, 0.642490, -0.178300, -2.142830,
0.215220, -0.859440, 2.213060, 4.057760, 0.968850, 1.316920, 0.524220, 2.541690, -0.293850, -0.874530,
1.410760, 2.467670, -4.866550, -2.534700, -0.728220, -2.281810, 1.111760, 0.138270, -2.034880, -0.084820,
1.676050, -0.215780, -0.208980, -0.272500, 3.507800, 3.199360, 1.653180, -3.233180, 0.901740, -0.414470,
0.644540, -1.284100, -2.805040, 8.397570, 2.226630, -5.455750, -0.667880, -0.783610, 2.591000, -0.888100,
-1.624700, -0.472080, 0.428220, -0.527220, 0.400390, 0.058590, 0.294720, -1.469140, -0.122650, 0.832080,
-1.141480, 0.564730, -2.305480, -2.840790, -0.549470, -1.142020, 0.823920, -1.653430, -2.540960, 0.168190,
-0.995460, 1.077690, 1.064450, 0.093020, -0.558940, -0.953370, -0.864960, 0.238660, -1.074780, -0.363410,
-0.023390, 0.047590, 8.300710, -0.481970, -2.224980, 0.309970, -0.786520, -0.270080, -0.858230, 1.714680,
-1.646340, -4.463450, -2.746240, -0.119070, -0.088640, 2.009410, -3.298080, -0.042240, 0.383180, 0.432800,
0.737990, -0.083050, -1.442610, -1.143890, 1.551260, 6.052570, 2.453080, -2.468200, 2.195960, 1.176810,
-1.271340, -0.376770, 1.388420, 3.631100, -6.574590, -2.487730, -1.507960, 1.319440, 0.711580, 0.523820,
-1.866680, 2.444830, -1.019170, 0.275950, 0.340710, -3.669770, -3.089700, 0.927960, 1.108020, 2.035850,
1.778210, 0.860200, 1.141520, -1.232170, 1.424610, 0.294960, 1.704730, -0.478270, 0.332840, 2.431460,
0.578750, 1.826050, -0.972190, -0.515350, 1.162540, 0.019570, 0.267530, -0.680900, -0.979840, -1.048020,
1.675300, 0.338180, 0.262340, 1.238690, 0.359090, 0.910210, 1.148690, -0.925660, -2.775430, 1.319200,
0.056240, 0.509940, 0.595850, -1.939400, -1.877080, -0.451250, 1.318520, -3.074620, 2.208610, -0.176000,
-1.479480, -1.348330, 0.659740, 0.652750, 2.543250, 0.773770, -0.614340, 0.779960, 0.356380, 0.685190,
-2.752640, -0.324090, -0.760770, 1.124820, 1.411840, 0.926300, -0.264620, 0.312010, -0.187720, -0.835100,
-0.053400, 1.465320, -0.214210, -0.828940, -0.559420, 1.948210, 1.754230, 0.159460, -0.153630, 0.299670,
-1.437480, 0.409180, -0.067500, 0.798070, 0.901210, 0.184520, -0.801250, 0.378330, 0.629120, 0.071240,
0.813100, 0.286980, -0.804590, -1.084180, 0.618590, -0.438000, 0.428320, -0.165760,
2.056640, -0.275970, -0.782070, 0.017860, 0.502660, 0.049190, 0.695620, -0.364870, -0.263990, -0.614420,
-0.299950, 0.089510, 0.965320, 1.301030, 0.776110, -1.156980, 1.013130, 0.963270, 0.783870, 1.248390,
-1.319660, -0.091790, -0.538070, 0.900560, 0.246090, 0.630370, 0.691260, 2.013070, -0.276340, -1.195440,
-0.937990, 0.020210, 0.461930, -0.644140, -0.120260, -0.087170, 0.854910, -2.078530, 0.619440, 2.157800,
2.330500, 0.985630, -1.269850, 0.157150, 0.841720, -0.728010, -2.075890, 0.662760, -0.030910, -0.581190,
-2.935760, -0.323200, -1.166620, -0.155630, 0.340750, 2.505900, -0.890060, -0.419240, -0.130230, -0.449140,
-2.312290, -0.781810, -1.613310, 0.505470, 1.466080, -0.257440, 0.262900, -0.215170, -0.520440, -1.751900,
0.264910, 0.436650, 0.880360, -0.113420, 1.197790, -1.315630, -1.451920, -0.734130, 0.625150, -0.634930,
-0.711020, 0.166640, -1.487280, -2.074730, 1.000190, -0.442320, -0.244050, 1.584330, 0.691560, 0.259520,
-0.298910, -0.285730, -1.686060, -0.656380, 1.238110, -0.179970, 0.512760, -0.565900, -1.232270, -1.166400,
-0.435670, 0.597550, 0.892810, -0.824930, 0.615980, -0.073490, -0.828630, 0.360730, -0.264470, 0.333470,
1.823890, -0.329120, 1.242300, 0.068010, -1.631460, 2.771190, 0.193240, -0.671350, -2.410890, -0.602740,
0.006750, -0.142980, -0.405800, -1.067710, 0.008560, -1.450820, 0.555680, -1.424360, 3.611980, -0.267750,
-0.424370, 0.504390, 1.085980, 0.859800, 0.973530, 0.617820, 1.640280, -1.834750, 4.818090, -2.058860,
-1.861110, -4.375470, -0.160920, 2.106150, 1.254950, -0.412900, 1.564230, -2.803640, -1.223960, -0.085380,
-1.083410, 5.673050, 1.513750, -1.241540, -1.404640, -0.298050, -0.939470, -0.057990, 1.905320, 2.289340,
-3.856710, 4.757730, 7.052410, -1.566500, -6.811010, -0.797450, 0.312520, -0.781740, 0.801730, 0.157090,
-0.452780, -1.025070, -0.140260, -0.059660, 8.484400, -1.202000, 1.919540, -1.414240, -0.209420, -0.773220,
0.353970, 0.210350, -0.510470, -6.626530, -0.151880, 6.572140, -3.591400, -4.182200, -2.194660, 1.004110,
-0.377450, -0.742030, -0.595760, -0.598240, -0.670550, -0.949030, 0.477360, 2.040770, 0.724030, -1.415490,
-1.009050, 0.426870, -2.175560, -0.990380, 0.858710, -0.982600, -1.353310, -0.552660, 4.642850, -1.071640,
-3.579280, 0.951320, 0.867880, -0.751070, 0.279400, 2.461930, 1.491260, 0.671360, -0.907040, 1.057440,
0.840600, 0.421400, 0.001250, -0.704080, -1.332240, -1.746500, 0.091560, 2.256160, -0.526310, -1.606600,
-0.729130, 3.254970, -1.294010, -3.218780, 1.234140, 0.203820, 1.611460, 0.999400, -0.038780, -0.336930,
1.130290, 0.259620, 1.048660, -0.602700, -1.366780, -0.223870, -2.639410, -1.131080, 1.155290, 1.183790,
-2.893270, -0.829170, -1.214360, 1.081660, 0.586550, -0.666480, 0.674090, 2.931460, 1.554770, -0.339010,
-0.497680, 0.140530, -0.152170, -2.702110, 1.897740, 1.020400, -0.542990, -2.077330, -1.798360, 0.385340,
0.098160, -0.168660, 0.924740, -0.098610, 0.520770, -0.176640, -1.174250, 1.129170, -0.585910, 0.298570,
-3.428810, 0.076070, -0.084600, 0.847510, 0.307600, 0.951550, 0.585640, 0.606590, 1.092490, -0.321330,
1.691000, -0.661490, -0.561050, -0.275750, 0.900360, -0.411940, -0.410490, -0.573470,
-0.357580, -0.148250, 1.077370, 1.411580, -0.134110, -0.764170, 0.347890, -0.345000, 0.973880, -0.278210,
-1.697120, 0.078060, -1.025090, -1.011410, -1.110710, -0.264750, -1.356300, 1.227030, 0.581560, 0.019330,
1.014920, 0.410120, 2.014840, -1.092610, 0.142370, 1.837500, -0.683970, 0.799650, 1.240940, 0.036010,
0.514550, 1.575480, -0.595990, -1.094030, 0.470150, 0.446180, -0.077160, -0.890690, 0.114110, -0.167540,
-0.716860, 1.885440, -0.691210, -0.877050, 2.676530, -0.115530, -0.982190, 0.202800, 0.406310, -0.241270,
0.109580, -1.219860, -1.501290, -0.465240, 0.932820, -0.117080, 1.243980, -0.368970, 0.494650, 1.062140,
-1.202970, 0.140580, -0.150070, 1.100240, 0.806900, 0.243880, -0.381280, 0.827140, 1.186570, -1.611250,
0.770330, -0.023950, 1.338830, 0.147240, 0.515690, -0.325070, -0.250350, -4.626420, 3.030280, 0.425470,
1.652070, -0.151930, -0.440510, 0.476620, 1.630820, -1.905690, -0.429680, 0.232620, 2.462990, -0.116370,
0.556270, 0.071910, -1.601360, -0.785740, -0.492730, 1.359810, -2.178350, -1.009990, 0.542790, -0.591050,
-1.918090, 2.116110, -0.382510, 1.427220, 0.890470, -0.810760, 0.917720, -0.718480, 1.699390, 1.570530,
1.000300, 1.801150, 0.598940, 0.332600, 1.432830, 0.804110, 0.649500, -0.742670, -0.263740, 1.554540,
0.577590, 0.579040, 0.066770, 0.040080, 0.660210, -0.771200, -0.059820, -1.176300, -1.230580, 0.719690,
0.792120, 0.098600, -0.346340, -0.600990, 1.329740, 0.503190, -0.433440, -1.106450, -0.483420, 0.545380,
-0.033170, 1.689860, 0.347980, -0.854450, 0.012620, -1.288780, -0.390640, -1.439300, -1.190000, -0.371850,
-2.963000, 1.498290, 1.122020, 0.360860, 0.210720, -0.214240, -1.887990, -0.123860, 0.626990, 0.275350,
0.524250, 1.756120, 0.901360, -1.574540, -2.483030, 0.578540, 0.686550, 1.358220, 0.705730, -0.015110,
-0.732590, -0.667460, 0.596480, -2.975270, 0.801020, 0.994330, -1.070520, -1.101220, 2.861670, -2.151430,
-0.627590, -0.279800, -0.742940, -4.502910, 0.645100, 2.250460, 0.869320, 0.152200, -0.908220, -0.204670,
1.669620, -1.740910, 0.744270, 0.334780, -1.553440, -1.174640, -0.630630, 0.971120, -0.572600, -1.721080,
-0.047920, 0.559430, -1.121760, 0.009330, -0.135240, 0.735930, -0.095350, 1.248700, 3.507510, -0.486270,
-1.964400, 0.685910, 0.161800, 0.360980, 0.498720, 2.113060, -0.291390, 0.435770, 1.586600, -1.984020,
1.135670, 1.106490, 0.613030, 0.707210, 1.053290, -0.819980, -0.418460, 1.321930, -0.779830, -1.365870,
0.217670, 3.824630, -0.081670, -0.601430, -0.679910, 1.621550, 0.286150, 0.643410, -0.717750, -0.984430,
-1.048160, -0.012690, 0.450480, 0.763570, -0.144910, -1.079220, -0.298290, -0.122650, -0.495760, -0.978680,
1.743970, -0.048840, -0.213090, -0.980050, -1.322710, 0.300510, 1.268980, 1.329130, -0.316830, -2.547320,
0.235940, -0.157800, 0.035210, -1.097790, -0.708280, 0.154560, -1.017550, -1.408560, -0.555800, -2.645100,
-1.114700, -1.816300, -1.079930, 0.132550, 0.257210, -0.674260, -1.376870, -0.805210, -1.747710, -2.409820,
1.030350, 0.541700, -1.044400, -0.597070, -0.248190, -0.808020, -5.061820, -1.024090, -0.209420, -1.752850,
-1.613830, 0.437600, -0.115320, -0.156620, -1.404310, -0.012180, -1.137780, -4.185930,
-0.988550, -0.119330, 2.926140, -0.934900, 0.264000, 0.501640, -0.999470, -0.012590, 2.670860, -0.078490,
0.293410, -1.029490, 1.155780, -0.066140, -0.668280, 1.447480, -0.762170, -0.887600, 1.240190, 0.383830,
0.232040, 0.459360, -0.463760, -1.289010, -3.221960, -0.125380, 0.326460, -0.718270, 0.310710, 0.328320,
0.722470, 0.590530, -1.337020, -1.094590, 0.117930, -0.836290, -0.179230, -0.257380, 1.580470, -1.754810,
0.655140, -0.478050, 2.083020, -1.348290, -0.561830, -0.431950, -1.715580, -0.585410, -1.106240, 0.250640,
-1.408270, -0.578740, -0.215380, -0.196300, 1.876050, -0.108800, -0.680940, 0.067170, -0.607390, -0.461150,
2.485780, 1.346760, -1.281340, 1.565590, -0.577480, 1.162550, -0.741320, 1.072740, -0.767610, -0.608780,
-1.800740, 1.376750, 1.047320, 0.699300, 2.678120, -2.284780, 0.232010, 0.650810, 1.446010, -0.131490,
-2.060510, -0.221760, 0.580840, -0.019180, -0.426600, 2.190020, 1.420510, 0.046420, -1.087110, 0.031880,
-0.465370, -0.486350, -1.639270, -1.360480, 1.545720, 5.038570, 1.563440, 0.352280, 0.759990, -2.429720,
-0.002090, 1.961260, 0.863680, 1.302280, 2.727690, -1.304990, -0.403850, -0.002020, 0.727380, -0.912850,
1.320960, 0.515160, 0.286530, -1.329530, 1.002740, -0.855570, -7.946640, 2.450070, 1.685080, 0.058800,
-0.969070, 1.079400, -0.414260, -1.038950, 1.333410, 1.157610, 0.547330, 1.109540, 0.039410, -0.541820,
0.265750, 0.917410, -0.138780, 1.368370, 0.078310, -1.800270, -1.218640, 0.037350, -0.750650, -7.267900,
1.116150, -1.345040, 0.234210, -1.281040, 1.202530, -1.832740, -2.961630, -1.415800, 3.070630, 0.446720,
2.236850, 1.544160, 0.345450, 0.869660, 2.234670, 1.645650, 2.305360, 2.078050, -0.916520, -1.114520,
-3.581720, -0.657550, -2.894790, -1.074480, 2.888530, 0.018850, 0.547060, 1.016180, -0.651220, -0.604050,
-0.896160, 0.153970, 1.046610, 1.735910, -2.273670, -1.036160, 1.777840, 2.135310, -0.232050, 2.246340,
1.964570, -1.191800, 0.522250, 1.918410, 2.009690, -0.517150, -0.931350, 0.858400, -0.935390, -0.873250,
-0.247830, -0.937400, -0.426920, 0.518080, 0.656490, 0.582940, -0.328390, -1.494840, 0.333780, -0.951560,
0.603440, -0.255600, 1.499280, -0.649350, 0.976410, 1.547770, 0.004130, -0.087860, 2.445230, -1.911370,
0.056860, -0.403640, 0.329120, 0.218990, 1.021850, -0.215620, -2.657280, 0.011710, -0.467740, -0.363560,
-0.550930, -0.078680, 0.723350, 0.654820, -0.646160, -0.540650, 1.263740, 1.056520, 1.466460, 0.457380,
-0.408170, 0.100280, -1.375440, -0.773970, 0.224720, -0.666270, -0.199940, 0.006210, -1.118140, 0.204010,
-1.303040, -1.989260, -1.736850, 0.737520, -1.225190, 3.519680, 1.080070, 0.695710, 1.838830, 0.595800,
0.068720, -1.074990, -1.661070, 0.239080, -0.053520, -0.971370, -0.548380, 1.055060, 1.842160, -2.373470,
1.910390, -1.344090, -1.277040, -0.237520, -3.017630, -0.924290, 0.488880, 0.471020, 0.753510, 5.144000,
-0.031910, 0.303000, 0.873750, -0.505310, 0.572410, 0.721750, 2.676200, 0.903420, -0.778420, 1.009330,
6.346150, 0.940620, -2.143030, 0.903880, -0.102800, 0.813320, -1.508890, -0.638470, -0.087870, 0.268920,
-0.728190, 0.494380, 1.302340, 0.816730, 0.655660, -0.357020, -0.038500, -2.468920,
-1.070350, -0.538790, 0.871350, -0.272840, 0.695990, -0.384170, 1.827440, -0.517560, -2.500350, 2.808470,
-0.500650, -0.055700, 0.728950, 0.449680, 0.432540, -0.743900, 0.381090, 0.949970, -0.124560, 0.725330,
-0.676620, -1.702810, 0.090830, -1.389240, -0.824480, 0.308120, 2.405640, 1.901440, -0.579080, -0.522960,
-0.952860, 0.466090, -0.663050, -0.430090, 0.451880, -0.221960, 1.677750, 1.256400, -0.630430, 2.980870,
-1.842290, 0.391130, 0.122520, 1.021220, 1.132450, 1.168880, 0.171730, -1.164700, 0.206190, -0.108960,
0.302670, -1.385620, -0.088310, -0.048840, 0.135670, -1.204600, 0.075490, 0.067550, -0.212960, 0.546850,
1.458040, -1.142120, 1.335020, 0.073010, -0.103660, 0.250390, 0.359600, -0.414520, 1.546730, -0.279970,
-0.929320, -0.344540, 2.378820, -0.540880, 1.078820, -0.154060, 0.368880, -0.045590, 1.625680, -1.294420,
-0.063070, -0.861830, -3.034960, 0.885130, -1.172410, 0.854350, -0.445910, 0.235670, -0.237060, -0.386630,
0.057210, 0.496750, -0.946810, -0.073440, -1.339850, 0.458890, 1.354760, -2.698040, 0.769420, -2.151270,
0.525400, 1.940690, -0.220730, 4.681320, 0.945360, -0.991920, -0.445350, 2.078890, 0.954890, 0.340460,
2.260760, 0.081950, 0.188820, -0.472690, 0.407440, 2.659980, -0.253870, 0.367710, 0.004790, -1.029450,
0.425790, 1.787350, -1.522640, 0.726580, -0.979650, -4.308430, -0.375010, -0.817210, -0.131460, 1.255620,
-1.995090, -0.731810, -0.079210, 2.901620, 0.551880, -0.461420, 1.751740, 0.719600, 3.658860, 2.963610,
-0.296320, 0.064400, 1.069000, 0.519160, 0.767390, 1.159460, 5.251800, -4.352620, -6.563000, -1.832620,
-1.506530, 0.489190, 1.677590, -3.713110, -4.241710, -1.036040, -0.899980, 0.719630, 1.129560, 1.091140,
-1.955250, 2.155480, 5.731270, -1.801290, -1.629250, 0.489710, -0.496700, -0.908250, 2.027790, 0.669830,
0.041030, -2.842400, -1.072200, 0.010000, 3.366230, -0.068490, -0.066330, 0.730740, 1.181470, 0.178050,
0.316560, 1.356310, -1.565860, -1.617010, 0.214130, 4.874490, -1.221080, -1.260660, -0.425440, 0.791490,
1.254790, -0.745470, 0.370900, -1.851430, 0.354270, 1.950130, -1.509020, 2.813980, 0.006930, 0.020770,
-0.350200, 0.294430, 1.318910, 0.256610, 1.151960, 2.599860, 0.025550, -1.429790, 1.709340, 0.076180,
-1.527220, 0.096490, 0.881210, -0.001300, 0.312260, -1.685090, 0.046360, -0.154830, -0.015230, -0.330750,
1.782150, -0.822930, 1.003120, 0.404250, -1.843310, 0.373930, -1.056790, -0.860200, -2.670890, -2.218960,
0.206840, 1.738460, 0.395910, -0.381840, -0.934660, 0.955940, 0.387050, 0.381110, -1.378200, -0.389720,
0.811080, -1.454520, -1.948980, -0.983590, -0.830430, -1.105070, 0.659040, 0.019630, -0.793960, -1.622250,
0.492200, -1.828730, 0.262860, -0.125450, -0.536930, -0.296870, -0.730450, 0.204010, 1.871870, 0.206780,
1.093700, -2.255720, 0.542720, -0.965900, 0.549320, 0.239680, -2.306730, -0.191720, -1.984430, -0.751500,
0.561460, 1.020920, -1.066750, -0.970950, 0.236780, 0.211380, 0.516420, -0.847850, 1.086460, -0.856180,
0.820460, -0.927000, -0.063980, 1.027720, -0.133800, 0.173450, -0.749190, 0.043800, 0.150370, 0.419590,
-0.503890, -1.050080, 0.781660, -1.078260, -0.346980, 2.710400, -0.805480, 1.299340,
-0.776790, -0.736040, 0.945640, 0.756580, 1.289310, -0.315130, 0.338780, 0.289210, 0.401130, -1.521950,
-0.222490, 0.356720, 0.046620, -1.298930, -1.033340, 0.473070, 0.497890, 0.178310, -2.070300, 2.060340,
0.612490, -0.909520, -0.544290, -1.387550, 0.718990, 1.692060, 0.162220, -0.622450, 0.166380, 0.301930,
0.001680, -0.177540, 0.230610, -0.253470, 0.809770, -0.482220, 0.840670, 0.762090, 1.400020, -0.123230,
0.327720, 0.266950, 0.027650, -1.073000, -1.849710, -0.589940, -0.624930, 0.080960, 0.158830, -0.430920,
0.077020, -0.654100, -0.466090, -1.632840, 0.920090, -0.151350, -1.241150, -0.029850, -0.950340, -1.737460,
-0.573300, -0.713310, -0.938570, 1.316700, -1.794670, 1.247720, 0.974010, 0.192410, 0.401690, 0.940370,
0.938830, 0.220530, 1.201050, 1.299680, -0.476930, 0.459950, -0.109740, 0.580300, -0.259990, -0.805790,
0.023130, -0.700920, -0.244110, -0.762330, 1.232100, 0.217200, -1.596650, -0.139730, 0.831090, -0.694800,
-0.493670, -0.270000, 0.277660, -0.042210, -1.519470, 1.639000, -0.604670, -0.632370, 1.022540, 0.179300,
-0.073700, 0.185630, -1.012200, -1.379420, -0.363110, -2.184440, 0.759020, 0.296460, 0.693970, -0.954510,
0.147400, 1.654830, -0.142730, 0.153490, -0.712710, 0.452520, 2.431490, -1.427570, 0.402240, 2.249080,
0.383180, 0.005740, 0.387460, -1.168240, 1.134950, -2.331780, -1.077710, -0.538660, 0.390780, 0.410340,
-1.907130, -1.447910, -1.606410, 1.730820, 0.167750, 0.199150, 0.224050, 1.793490, 1.331230, 3.026430,
-0.115540, 2.302380, 1.599900, 0.872360, -0.247560, -2.233410, 2.828960, 2.552660, -1.698660, -0.556750,
0.923520, 0.591270, 0.833160, -0.089780, -1.261790, 1.107190, -0.368560, -0.824210, 1.758220, 0.075530,
-0.462270, -0.115100, -0.534950, 0.541830, 0.294250, -0.279170, -0.579630, -0.143300, -0.232490, 1.479900,
0.967660, -3.025190, -0.556410, 0.334160, -0.349240, 0.900940, -0.576330, -1.371610, 0.528190, 2.032900,
0.540950, -0.135170, -0.010720, -0.661550, -0.410190, -1.099120, 0.012260, 2.391030, -0.844060, -1.868520,
0.461530, -0.907830, -0.868460, 0.674120, -1.015700, 0.212390, 0.765490, -0.859540, -1.248180, -0.401330,
1.068720, -0.968570, 1.095120, 0.530510, -2.714840, -0.079740, -0.020250, 0.340080, 1.333870, 0.086090,
1.106430, 0.756520, -1.031720, 0.805710, 1.094620, -0.130230, -0.350890, -1.898570, -1.282870, 0.337450,
-0.923260, -0.426420, -0.516780, -0.337080, 0.648410, -0.530370, 0.037900, 0.740920, -0.854620, 0.440660,
2.194210, 0.114650, 1.290560, 2.168540, 1.418050, -0.181640, -0.575040, -0.822330, 0.595790, 1.050890,
-3.589890, 0.844850, 0.491610, 0.507460, -0.609990, -0.919380, 0.847400, 2.828000, 0.478620, -0.268180,
0.635480, 0.101140, 0.132520, -0.266980, 1.225740, -0.011420, -0.103610, 0.605280, -0.391880, -0.754610,
0.331690, 0.267530, -0.563330, 1.378050, 1.709620, 1.614660, -1.000500, 0.159330, -1.324790, -0.865390,
0.679660, -2.665300, -0.948170, -6.748050, -0.095430, -0.523330, 4.638080, -1.685900, -1.513270, -0.568760,
1.617130, -1.471070, -1.107550, -0.924000, 0.759290, -1.361840, -2.836010, 0.557140, -0.460250, -0.150650,
-0.100690, -0.794790, -0.850650, -0.618570, -0.189230, -1.019730, -0.513450, -0.439080,
-0.743460, -0.243670, -0.111820, -1.217830, 0.596300, 0.399960, 0.104100, -0.447020, -0.199680, -0.306040,
-0.117670, 1.079730, 0.935140, 0.532270, 1.735940, -0.984040, -0.917960, 1.091250, -0.816060, -0.284940,
0.699590, 0.904110, -2.072100, 1.643020, 0.497090, 1.843770, 0.063700, -0.294040, -0.839120, 0.856300,
2.209480, -0.990890, -0.980560, -0.194360, -0.448460, -2.121890, 3.033680, 0.763050, 0.607520, -1.717400,
0.276930, -0.881870, -0.459030, -0.394030, 0.306300, 1.331160, 1.431480, -1.974930, 1.010100, -0.423590,
-0.470670, 0.371250, 0.892840, 0.574620, 1.313510, -1.140320, -0.241040, 0.549100, -0.492660, 2.447970,
2.463530, -0.651990, -0.474220, 1.275180, 0.042630, -2.768640, 0.198900, 0.100820, 0.532400, 0.182590,
-0.563400, -1.326090, -2.301630, 1.104480, -3.495260, 0.689040, 0.073030, -3.190570, -0.226240, 1.738070,
1.397040, -2.265760, 0.762950, -0.683840, -1.268410, -3.169940, 1.866490, -2.248790, -0.285440, 0.616340,
0.005150, -0.348430, -0.881140, 0.523000, -0.828490, -2.850170, 0.043790, 1.166410, 5.042140, -0.414200,
0.301570, -1.304910, 3.986810, -0.819810, 0.659630, 1.117050, 1.329610, 0.254760, -0.929960, 0.502540,
0.858680, -1.287990, 0.363220, 0.396300, -0.753580, -0.405820, 1.105400, 0.339540, -5.738700, 0.132020,
0.962290, 1.104900, 2.039250, 0.355820, -0.339010, -1.035660, 0.085490, -0.466020, -0.051170, -0.461810,
-0.693760, 0.145860, -1.025970, 0.148330, -0.352600, 0.364940, 0.657930, -3.580360, -5.862440, 2.675150,
0.826740, -2.980460, 1.041760, 0.338200, 0.620590, -0.022380, -0.944680, 0.803580, 4.565820, -0.169760,
0.727390, -0.821320, 2.120050, -0.397300, 0.492020, 0.438450, -0.994510, -0.517940, 0.511580, -0.668610,
-1.690910, -2.313160, 0.622580, 1.814110, -2.146120, 0.837460, 1.524220, 0.341780, -0.335510, -0.255450,
0.455730, 1.771690, -0.630970, 0.394860, -3.930970, 1.485580, -0.837590, -1.910630, -0.772160, -1.855670,
-0.973890, 0.540660, -0.459560, -1.828290, -0.844950, 2.189560, 0.336800, -0.177990, -1.836330, -0.988220,
-0.822940, 0.493910, 0.045240, 1.002160, 2.342920, -0.992940, 0.560870, -1.419040, 0.470540, 1.333210,
-1.311750, 0.460600, -3.940120, -1.979260, -1.741250, -0.534280, -0.686690, -1.187760, -0.141330, -1.734170,
-1.766940, 2.335020, -0.009270, -1.190560, 0.578060, 1.730390, -0.631300, 2.512420, -0.298990, 0.678690,
-0.058430, 0.023950, -0.881280, -1.280430, -0.815940, -3.306380, -0.050550, -0.856330, -0.294040, -0.464870,
-1.201500, 5.053880, 2.266810, -3.758190, 1.288980, 0.860080, -0.451990, 2.458300, 1.252700, -1.799570,
-0.457540, -0.110880, 0.096450, 1.560120, -0.764490, -1.264100, -1.160450, -0.211580, -2.326380, -0.265510,
-1.668810, 0.356670, -1.046940, 0.440690, 1.219630, -0.150620, -1.177040, -0.935860, 0.987440, 1.833240,
1.602390, 0.867870, -2.097860, -0.418600, 1.211510, 0.508250, -1.195660, 1.579080, -0.124340, -0.987260,
-0.082550, -0.675040, 0.666730, 0.531900, 0.767190, 0.610930, -0.955110, 0.202210, -0.264160, -0.905370,
-6.806820, 0.271020, 0.198540, -1.193750, -0.351690, -0.882750, 1.898950, 0.625370, 0.753810, 0.947910,
1.039990, 0.663640, -0.212450, -1.170540, 0.115590, 0.735830, 0.294110, -0.435730,
-1.536670, 0.324560, 1.069840, 2.653260, -0.993710, 0.806670, -1.078420, -1.220490, -0.268970, -0.424810,
-0.204170, -0.625070, -0.585020, -1.223790, 0.608310, 0.048460, 0.499770, 2.347270, 0.694230, -1.840290,
-0.519380, 0.612300, -0.392340, -2.035840, -1.318560, 0.271480, -0.141680, 1.243800, -0.217220, 0.185510,
0.051640, -0.193760, 0.581130, 0.336870, -1.411020, 0.932590, 0.085700, 0.709040, -0.060500, -1.253420,
1.753110, -0.923610, -1.600140, 2.108040, -1.661480, 0.218300, -0.704840, -0.490860, 0.339530, 0.642190,
-0.735860, -0.619700, 0.897260, 0.119580, 0.721570, 2.361870, 0.333030, -1.210480, -0.297730, 1.263650,
0.466170, -1.491440, 0.790330, -0.418090, 0.386310, -1.103310, -0.704360, -3.975470, 1.236680, 0.558130,
0.530320, 0.000150, 0.245890, -1.199970, 2.025590, 0.102660, -0.927180, 0.591510, -0.101460, -0.244900,
-0.889740, 0.531940, -2.352300, 0.382060, 0.945370, 0.184430, -0.660810, 2.871390, -0.703380, -0.981050,
-0.711210, -0.860330, 0.185480, 2.374120, -1.543870, -0.831070, 0.135660, 0.147280, 0.857110, 0.690620,
0.072530, -1.868740, -3.999650, 0.338260, -2.079650, 0.956700, 1.282340, 1.671930, -1.521380, 1.062030,
2.987230, -0.467590, 0.344300, 0.834110, -1.839860, 2.837320, 4.679510, 1.619710, -2.017910, 1.487220,
1.638630, -0.391360, -1.306340, 5.677980, -4.228630, -2.213010, -2.615980, -2.297550, 2.008300, 1.559130,
-3.040870, -3.138640, -0.154980, -2.217350, -0.267890, 1.038170, -1.057070, -1.957750, 2.004540, 3.242140,
-0.248490, -1.513000, 1.126640, -0.011530, 0.915600, -0.227000, 1.338710, 0.241270, -1.495930, -2.431860,
0.401830, 1.635850, 1.449110, -0.466580, -0.070440, 0.286310, 0.705380, -1.209370, 1.193600, -1.150130,
-0.955550, 0.285860, 2.336480, -3.597540, -1.098690, -0.131460, 1.298310, 1.034340, -1.723440, -0.611260,
-1.758580, 0.229120, 1.006040, -0.460440, 1.769730, -0.893680, -0.346340, -0.102240, 0.416090, -0.138850,
0.075290, -0.240070, 0.364150, -0.463520, 1.908450, 0.463770, 1.856240, -1.371620, 0.230850, -0.168420,
-0.825870, -0.119140, -0.503970, -0.618110, -0.393370, -0.951880, -1.434920, -0.248280, -1.033390, -1.120030,
-0.931740, -0.636150, 0.169820, -0.155690, 0.630990, -2.985410, -0.022740, 1.725180, 0.502270, 0.404390,
-0.274370, -0.491230, -0.182710, -0.943690, 0.556440, 0.684670, 0.862950, 0.934010, 0.656300, -0.135700,
-0.200690, 0.497930, 0.945270, -0.220090, 1.437620, -1.539420, 0.348840, -0.494240, -2.546730, 0.511790,
-0.416390, 0.200160, 0.345630, -0.670360, -0.691070, -0.766000, -1.228060, 0.298800, 0.330450, 0.954540,
-1.484640, 2.253240, -3.190650, -3.411410, 0.974730, 0.121480, -0.576850, -2.394790, -1.150840, -1.475500,
-0.395150, -0.187680, -0.294620, 0.856550, -1.013160, -1.418280, -1.349430, -0.788820, -0.505210, 4.073960,
0.598690, -0.575570, 0.441310, -0.401930, 0.893740, -0.353200, 0.621720, 0.107250, -3.094360, 1.522780,
0.427550, -1.008140, 0.624290, -1.192470, -1.078980, 0.536200, 1.071740, -0.196280, 0.276440, -0.238110,
-0.983630, 0.587410, -0.538930, 0.779310, 0.083880, -0.124710, 0.001330, -1.261100, -0.510080, -0.165710,
-0.833720, -1.393560, -0.734500, 1.108310, 0.213990, 0.155390, 0.684460, 0.023520,
-0.296450, -0.593670, -2.244890, 0.243890, -0.970330, 0.114670, 0.194910, -0.663640, -2.403440, 1.611440,
-0.039860, -0.982490, 0.196090, 0.428740, 0.703060, 0.144570, 0.210750, 0.192990, 1.178910, -0.272810,
3.855950, -2.787730, 0.010940, -1.270550, -0.656460, -0.736710, -0.457270, -0.324390, 0.962940, -1.331620,
0.027270, -0.364150, 0.967400, -0.084940, -1.781070, 0.891770, -0.857110, 0.105720, -0.466350, 0.562530,
-1.887730, -0.197600, 1.046880, -0.190520, -0.627880, -0.107580, -0.746890, 0.997490, -0.304130, -1.008520,
-0.521920, 1.610770, -1.475200, 1.004790, -1.031760, -0.985960, -0.405350, -0.499510, 1.194670, -1.548100,
1.655000, -2.333500, 1.459940, 1.263180, -0.006340, 2.211830, -0.970140, -2.005750, -0.174930, 1.667040,
0.412430, 0.025330, 2.348820, 1.742150, 1.431040, -0.818770, -0.398900, 1.227540, 0.736930, -0.947150,
-0.543150, 0.739400, -1.783370, 0.587720, 0.200860, -0.738800, -1.263340, 0.285210, -0.755630, 0.866360,
-1.827870, 0.265680, 0.211030, 1.752850, 0.025930, 1.382570, -0.877650, 3.601300, -0.707790, 0.866410,
2.385610, -1.591170, -1.541110, -0.911710, 0.270440, -1.008710, -0.286530, -0.986730, -0.579060, 0.334730,
0.113440, 0.489540, -0.176120, -0.528490, -1.383660, -0.619910, 2.543610, -2.357990, 2.900670, -1.275170,
-0.318490, -0.082700, -0.588310, 0.075730, -0.934260, -3.211730, 0.785140, -0.212960, -1.361630, -0.894510,
-0.197600, -0.814160, -1.953440, 5.178630, -1.913450, 0.099720, 1.427210, -1.126790, 0.968970, 3.571780,
0.952940, 0.341960, -0.411500, -0.510330, -0.655400, -0.752000, 3.406710, -0.093950, -3.024560, -1.399550,
-0.654850, 1.157220, -1.154260, -1.311430, -0.455150, 1.295240, 2.607560, 0.594280, 1.187550, -0.639070,
0.569990, 3.138140, 1.174160, 1.708530, 4.423970, -0.483060, 0.682990, -0.124770, -1.014890, 1.844800,
3.520450, -3.364980, -0.636250, 0.124750, 0.267850, 3.766790, -1.152680, -1.528630, 1.347280, -0.308060,
-0.377410, 2.682720, -1.720860, -0.982190, -0.000500, -1.154310, 0.238840, 1.869390, -1.097310, -0.261350,
1.119790, -0.861830, 0.128050, 2.547840, -1.074930, 0.013400, -0.216530, -2.436190, 0.174510, -0.918640,
-0.690180, -0.430040, 2.611280, 1.684290, 0.916320, 0.287670, 1.056740, -0.062770, 1.721090, -1.029390,
4.554760, -0.800000, -0.837090, 2.729520, -2.062940, -0.850230, 0.018840, -2.092160, 0.600630, 1.165240,
-3.374440, -0.266870, -1.629780, 1.556530, -0.358120, 2.644960, 1.981840, -2.555430, 0.106870, 3.207890,
-0.175000, 0.054390, -0.683420, 3.209610, -0.384120, 1.260120, -1.213050, -1.911620, -0.495280, 0.179720,
0.886150, -1.267880, 0.335200, -0.476060, 0.827620, 0.455640, 1.028680, 3.788780, 0.801840, 0.713280,
-0.750530, -0.166430, 1.553800, -1.116360, 1.328880, -0.224420, 0.293620, 0.238870, 0.101790, -0.388950,
-0.101960, -0.035830, 1.579190, -0.433840, 0.936720, -0.957320, -1.799200, -0.819290, -0.901220, 1.108570,
-0.833490, 0.385960, -0.882790, -2.074670, -0.133480, 2.866280, 3.015570, -0.838270, -0.962870, -0.096880,
0.215570, -0.184810, -0.153440, -2.120050, 0.834540, -0.868690, -1.464550, 0.302470, 0.621350, 0.724840,
0.289700, -0.312120, -0.113760, 0.760930, -2.824790, -0.409080, -1.285350, -0.351000,
-0.159400, -0.079080, 0.195140, -2.096460, 0.818130, 0.927310, 0.640140, -0.018090, 0.058060, -1.320510,
0.377250, -1.216290, 0.807320, 1.662970, -0.157080, -0.228350, -1.245020, -1.421830, 1.338800, -0.249810,
-0.388590, 0.160580, -0.315400, 0.947870, -0.059280, 0.824060, 0.176040, 1.581790, -1.576130, -0.329830,
0.812330, -2.179070, 0.629420, -1.302960, -1.345760, 0.000350, -1.345080, -0.736760, 0.842210, 1.343040,
-0.632710, -2.291450, -0.502990, 2.215610, 0.306680, -2.002990, -0.155860, -0.675520, -2.203990, -0.145950,
-0.020840, 0.488240, 0.016270, -0.255330, 0.323600, -0.875110, -0.515020, -0.409440, 0.185240, 0.781970,
0.434160, -0.477680, 1.085540, 0.513550, 0.513510, 0.377850, -0.099030, -2.552090, 0.884150, -0.686470,
0.068640, -1.576090, -0.323170, -0.588010, 0.713370, 1.217660, -0.306180, -1.174220, -1.273240, -0.877820,
-0.441740, -0.002300, 0.420800, 0.649570, -0.079470, -0.798100, -1.262950, -0.274930, 0.028640, -1.437840,
0.162370, -0.299320, -0.371330, 0.318540, 0.604230, -0.399350, 0.813950, 0.565330, -1.133360, -0.372270,
-0.860110, 0.944010, -1.063810, 0.021070, -0.133030, -0.728150, 0.624720, -0.184000, 0.295590, 0.605000,
1.765340, -0.054570, -0.234300, -0.022700, -0.683020, -0.780010, 0.810270, 0.028330, 2.017240, 0.342960,
0.722750, -0.578210, 0.937190, 1.769270, 2.120360, -0.636540, 0.294440, 0.199460, -0.079220, -0.912300,
-0.370940, -0.219690, 1.003140, 0.546580, -0.542800, 0.426400, -0.877170, -0.031320, -0.300960, 0.678640,
-0.594380, 0.017000, -1.344150, -1.550930, 0.439160, 1.404510, -0.403470, -0.960960, -0.972140, 0.383300,
-0.568120, -1.178000, -0.019150, 0.624700, 0.481540, -1.155560, 0.997440, -0.074660, 0.069010, -0.067600,
0.004230, 0.390950, 0.868670, -0.735350, 0.710340, -0.565230, -0.489170, 0.610850, -0.306350, -1.022860,
-3.894680, 0.013110, 0.214700, 0.969710, 1.194100, -0.061520, -1.125880, 0.498360, -0.783700, 0.693360,
0.958650, -2.489240, 0.944050, -0.050820, 0.083100, 1.297460, 0.921310, -0.331190, 0.345820, 0.896650,
-0.139440, 0.246110, 0.010310, 0.584230, 0.554190, -1.133860, 0.827840, -0.441660, 0.709720, -1.144450,
0.585640, 1.271770, -0.051020, -0.000320, -0.583340, 0.763700, -0.124050, -0.604540, -1.352730, -0.240950,
1.737690, -0.211920, 1.162020, -2.037620, -0.116650, 1.543010, -0.512080, -1.609960, 0.190340, 1.350690,
-0.124200, -0.353910, 0.478540, 1.273950, 0.944450, -0.778720, 0.892880, 2.848650, -2.252610, -0.550990,
-0.158320, -1.328060, 0.250440, 2.481170, -0.986250, 0.152820, 0.231390, -0.061800, -1.816870, -0.981680,
0.072160, -0.338770, 1.484610, -0.114820, 1.092670, 1.035060, 0.535890, -0.688620, 3.191000, 1.463820,
-0.198330, -0.450640, -0.103430, 0.871260, 1.369220, -0.286210, -0.449010, -1.386920, 0.700760, 0.284350,
0.426920, 0.405700, -1.026300, -1.233630, -0.879290, -1.200780, -0.032950, -0.357470, -0.696620, -0.700090,
-1.085180, -0.549510, -0.049230, -2.403760, 0.293610, -0.874310, -0.752050, -6.296890, -1.101560, -1.256800,
3.334510, 0.467820, -0.946260, -0.467620, 0.479180, -0.558270, -1.609980, -0.103450, -2.408420, -0.873160,
-1.694160, -1.151390, -0.107470, -1.545820, -1.340070, -1.801560, -1.366070, -2.026490,
0.489410, -0.665510, 3.203160, 0.296290, 0.405550, 1.183110, -0.178560, 0.323440, 0.536300, 0.210960,
-0.361010, 0.535890, -2.439340, 0.059120, -0.440680, 1.656440, -0.055680, -0.134310, -0.228720, -1.636210,
1.103100, 0.653530, -0.844070, -0.465560, -1.182200, -0.110310, 0.684910, 0.976610, -0.072980, -0.906320,
-0.460330, 1.865380, -1.913230, 0.109700, 0.119810, -1.634820, -0.827210, -1.259150, 1.320090, -1.745510,
1.988650, -0.605150, 0.145030, 1.803140, -0.758450, 0.072440, 0.414570, 0.547130, 3.148040, 0.669970,
-0.634240, 0.583280, 0.868380, -0.892490, 1.739280, -1.556240, -0.760760, -1.042450, -2.097290, -0.356760,
2.291210, -0.249330, -0.784520, 1.722690, -0.952690, -1.237480, 0.896620, -0.226820, -0.733380, -1.206020,
0.299260, 1.970390, 1.714070, 0.411800, -0.223400, -0.129410, -1.337840, 1.911160, -0.662970, 2.073620,
1.271380, 0.304930, 0.498790, 2.236610, -1.410530, 0.556760, -1.131650, -1.617420, -0.456310, -0.299990,
-0.405400, -0.481270, -0.027240, -0.272360, -0.288630, 0.623370, -1.526830, -1.852960, 1.525990, 2.054630,
0.618190, 0.201360, -0.398490, 0.945900, -1.414110, -0.595510, -0.300080, 0.624380, -2.562670, -0.644290,
2.748340, 1.159800, -0.823920, -0.522130, -1.212860, -1.288200, 0.737190, 0.876840, 1.522850, 0.387320,
-1.183120, -0.467000, -0.952340, -1.004320, 0.135880, 0.571780, -1.004840, 0.098430, -2.721050, -0.268300,
-1.200490, 0.635900, -0.498300, -0.057140, 2.254240, 0.889210, -1.267180, 0.227020, 0.040240, -2.166260,
0.228710, 2.307730, 1.027020, -1.008010, 0.261100, -0.244050, 0.927000, 1.961530, 0.893980, -1.559720,
0.737170, -1.491790, 0.330640, 0.764420, 2.015010, 0.483740, -1.441750, -0.706100, 1.261490, -0.503510,
0.903810, -0.198870, -2.478290, 0.631560, 3.448240, 1.426090, -0.720320, 0.580520, -0.403990, -0.532850,
2.918660, 3.281680, 0.637820, 0.620160, -1.225510, -0.305260, -0.938660, 1.901050, -0.795780, 1.167410,
1.101690, -0.802520, 0.287170, 0.498280, -0.250720, -0.957880, -0.176540, 1.580490, 0.646990, -1.331620,
0.175810, -1.871560, 0.694650, -1.601040, -1.136340, -0.982550, -0.551480, -2.696440, -1.984460, 0.270810,
0.859640, -1.097810, -0.332650, 0.341840, -0.562200, 1.605700, 1.013620, 1.017290, -0.093950, 2.463610,
1.796140, 2.841230, -1.387200, -1.043200, -0.771970, 1.550950, 0.401890, -1.210810, -0.938190, 0.933940,
-1.176730, 0.073880, 0.750060, 1.445990, 0.439130, 0.822750, 0.776890, -0.515090, 0.777020, 1.961750,
1.333190, -0.351410, 1.238970, 0.365060, 3.414650, -2.142380, -0.370920, -0.539340, 1.100460, 1.872030,
-0.441290, -0.035010, -1.128690, -0.120500, -0.528250, 0.519850, -0.157780, 1.192410, 0.592140, -0.347390,
-0.383440, 0.264020, 0.122380, 0.037130, 0.021460, -0.006080, -0.418840, 0.274570, -1.019840, 0.764190,
-2.135240, 0.717760, 0.545940, -0.584160, -1.536480, 0.255470, 0.809410, 1.647510, 0.898970, 0.941230,
-0.741450, -1.776900, -0.567110, 0.222300, 0.042900, 0.321450, -0.758870, 0.618680, -0.916410, -0.067680,
1.069730, 0.207030, 0.493070, -2.850070, -0.504170, 0.144000, 0.696420, 0.900810, 0.074500, 0.130910,
-0.389360, -0.117270, -0.307980, -1.166890, 0.237880, -0.044750, 0.785010, -0.898660,
0.864770, 0.807510, 0.437640, 0.746280, 2.483850, 0.805730, -0.690160, 0.327830, 0.039140, -1.855860,
1.269400, -0.485580, 0.427070, 0.249160, -1.246570, 0.046140, 0.747120, -0.764540, 2.345820, -0.818970,
0.403370, 0.011960, 0.878540, -0.990580, 0.616980, 1.207870, -2.493980, -2.548940, 0.331680, -0.198810,
-0.456180, -0.340210, -1.124230, -1.568580, -1.544560, -0.890480, 1.782600, 0.603750, -1.191440, -1.108450,
1.766710, 1.393010, 2.118030, 0.862540, 0.336020, 0.122530, -1.061000, 0.363090, 0.286720, -2.110070,
0.228910, 1.035670, -2.435430, 2.666010, -1.142760, -0.217870, -0.682340, 1.836620, 0.742990, 0.918920,
0.911490, -1.163780, 0.070320, 0.198930, 1.511620, 1.565820, 0.332680, -0.640040, 0.292980, 0.762890,
-0.761120, -1.792970, -0.951790, 0.579080, 0.962420, -1.745650, 1.167070, -0.459520, -0.827430, -1.008680,
0.313020, -1.949610, 2.651460, -0.379290, 0.301940, -0.203490, -0.026230, -2.297740, -0.085650, -0.944880,
0.681700, -0.455090, 1.662100, -0.650170, -0.471890, -3.267660, -1.369250, -0.652490, -0.954930, 0.227900,
-0.128160, 0.954140, -1.798600, 0.105260, -0.896790, -0.920680, -1.703960, -0.586270, -0.090420, 0.147070,
-1.661960, 0.163170, -1.247370, 1.043290, 1.616640, -0.744820, 0.613090, 0.907270, -1.792240, -1.003930,
-0.452270, 0.726750, 2.814140, 0.536060, -2.653000, 0.537940, 0.258440, -0.381380, 1.328030, -0.643750,
-1.418640, 0.801470, -0.515460, -0.941790, 0.487770, -1.485410, 1.101900, -0.506680, -1.341580, 1.041370,
-2.081100, -0.436360, -0.481680, -0.206400, 0.169770, 1.294390, -0.100080, -1.620580, 0.299060, 1.024440,
1.088430, -0.888540, -0.674980, -0.035310, 2.430540, 2.716050, -1.571850, -0.735430, -3.504390, -0.928270,
-0.457230, -0.065790, -0.354250, -2.040430, 0.440650, -1.458130, 1.139360, -0.207210, 1.441780, 0.105790,
-0.204890, 1.182460, -1.800840, -1.068680, -0.714580, 1.092150, 1.349060, -0.395560, 1.007000, -0.351520,
0.439350, -0.671350, -0.465830, 1.178260, 0.622950, 0.416680, -2.088100, -1.107520, 0.413360, 1.137700,
0.365140, 2.081040, -0.185740, -0.875840, 2.096040, 0.452760, 1.135900, 1.973990, -0.252050, 0.255830,
1.216370, -2.338050, -0.317920, 0.142750, -0.303940, 0.057940, 0.570070, -1.454930, 1.703540, -0.658510,
0.622950, 0.151440, 0.368710, -1.255710, 2.135890, -0.058290, -0.807110, 3.188630, -1.142020, 0.305230,
1.540720, -2.570580, 1.845240, 0.594050, -2.435420, 1.016900, -0.199240, -0.691360, 0.015080, -0.275360,
-0.678790, 0.807860, -0.932170, -2.195130, -0.394940, 0.051640, 1.605690, 1.661540, -3.706070, -1.174920,
2.705420, -1.229400, -0.085240, 3.198270, -0.597080, 0.237870, 0.047460, -0.262080, -1.748710, -0.297860,
-0.293110, -1.139710, -0.936350, 2.466620, -0.239280, 0.868410, 0.243330, 0.134330, 1.562720, -0.106980,
0.774740, 0.269070, 0.269970, -1.007360, 3.878630, -1.360420, -3.491620, -0.096700, 0.333700, 0.018520,
-0.125600, 0.470040, 0.811700, 0.012850, -0.479180, 0.018980, -0.488720, 0.044420, -0.310590, -0.247710,
-6.798790, -0.658670, 0.647460, 0.354580, 0.673850, -0.872960, 0.729540, 0.383340, 1.769050, 0.008840,
-0.445310, -0.479740, 0.221340, -0.607990, 0.159930, 0.397230, 1.075670, 0.440950,
0.043290, 0.432570, 0.387410, 0.853430, -1.003390, -0.156560, -1.073020, -0.224850, 0.702440, -0.087290,
0.778230, -1.125580, -0.917310, -2.161320, -0.143500, 0.459450, -0.723540, 0.341870, 0.440930, -0.839810,
-0.562310, 0.445340, 0.858670, -0.225950, -0.659340, -0.415850, -0.015710, 0.224540, 1.060810, -0.653260,
-0.573620, -1.991120, 1.204850, -2.096000, -0.713450, -0.697480, 0.136890, 0.537030, -0.442770, 1.145670,
1.091530, 2.393750, 0.913790, -1.094060, 0.701650, 0.544740, 0.376110, 2.070340, 0.961980, 2.950070,
1.246150, 0.235610, -0.440000, -0.339210, 1.198170, -0.046770, -3.549010, -0.777320, 1.161770, -0.203300,
-0.481380, 0.352690, -0.621880, 1.539080, 4.520760, -0.390430, -0.013510, 0.839990, 1.166250, 0.082040,
0.718040, 0.647650, 0.237640, 1.516800, 0.555900, 0.031580, -3.961750, 2.643020, 1.538470, -1.039800,
-1.153950, -0.441380, -0.267010, 0.412760, -0.787780, -0.972180, 3.124500, -0.046570, 0.341430, 2.128080,
0.218860, -1.177560, 0.910630, 1.415050, -0.878460, 0.099380, 0.794490, 0.623300, -0.289740, -1.279110,
0.555940, 0.766710, -0.503610, -1.083950, -2.279480, 0.850600, -0.443850, 0.154990, -2.331790, 0.388450,
3.354360, -0.774560, 0.923680, -1.724450, 1.019460, 0.129470, -0.230760, 0.107490, 1.459470, 0.031700,
-0.918820, 0.973220, -1.165450, 0.405970, -0.240230, -1.272290, 0.735560, 0.376810, -0.315250, -0.092170,
-0.460670, 0.536030, -0.605270, 0.969370, -0.726440, 0.904160, 0.176000, 0.553300, 1.250150, 1.600280,
0.309550, -1.768860, 1.928870, -0.564000, -0.238460, -1.458450, 1.051680, -2.292140, 1.635720, 0.153800,
0.552600, 0.665350, 0.033930, 0.595570, -2.565140, 0.936020, -0.466040, 0.190110, -0.995570, 0.767270,
-1.385200, -0.474950, 2.867570, 0.202830, -4.956380, 1.762100, 0.727890, -0.263670, -0.056800, 2.799670,
-2.133950, -1.208150, 0.222220, -0.366650, 2.978980, -0.321820, 1.916190, 0.361920, 3.892750, -1.697920,
-1.485280, 0.841420, 0.167640, -0.097140, -2.625230, 2.520640, 0.301440, -2.905030, -1.193540, -0.864130,
0.303930, 1.852970, 1.264220, -0.641280, 0.090180, -2.210600, -1.480850, 1.367440, 0.159800, 1.907520,
0.176360, -0.921070, -1.266220, -1.140230, 0.948600, 0.643310, 0.515520, -0.926290, 1.289700, -0.128370,
-0.854010, -1.662430, -0.397550, 0.207840, -0.746470, -1.076060, -0.657110, -0.789170, 0.258820, -0.314460,
-0.289100, 0.272350, -1.660680, 0.481250, -1.406380, 0.545360, -0.015040, 0.048480, 0.546330, 0.982180,
-0.084380, 2.948340, 0.119600, -2.662300, 0.854980, -0.166690, -0.153560, 0.167010, -0.453250, 1.358780,
0.970930, -0.348870, 1.146760, 0.071300, -0.750550, -1.932880, -0.373860, -1.934020, -1.138850, 0.872450,
-0.130040, -0.661480, 0.489200, -0.963720, 0.370850, 1.026060, 0.061900, 0.970020, 0.773220, -1.022880,
-1.993310, 0.562630, 0.332460, 0.060890, -1.619630, 1.997290, 1.285930, 2.400610, 0.344400, 1.604230,
-1.194300, -1.431430, -4.100240, -0.854180, -0.544880, 0.210180, 1.040280, -2.729860, -1.134850, -1.121460,
3.092390, -1.337990, -0.487530, 3.723250, 0.166850, -0.873850, -2.864840, -0.377690, -1.470230, -0.990340,
-1.717810, 0.132070, 0.188000, -0.152380, -1.709060, -1.745100, -3.410860, -0.481990,
-0.782090, -0.707690, 1.299000, 0.793840, -0.273160, 0.794740, 0.265400, 0.142490, 0.475710, -0.282000,
-2.645970, 1.036800, 0.094300, -1.055930, -0.726770, 0.466260, 2.095850, -0.258190, 0.368120, 0.496070,
0.139220, -2.765300, -0.299740, -0.986570, -1.332650, 1.157770, -0.793930, -1.434770, -0.496060, -1.981320,
1.649450, 0.199420, 0.459430, -0.562010, 1.665840, 1.173320, 0.361840, -0.640550, -0.760300, -1.226230,
0.589380, -0.637360, 0.299890, -2.261220, -0.902800, -0.680600, 0.759240, -1.019860, 0.053790, -2.148430,
1.259480, 0.005670, 0.320940, -0.903470, -1.623860, 0.016710, 0.458320, 0.557760, 0.164280, 0.872020,
0.390350, 0.275780, 1.518000, -0.785450, 0.286480, 0.807090, -1.764420, 0.646720, 0.690060, -0.094150,
-0.871220, 0.803500, -0.731090, 1.284380, -0.854490, -0.382830, -0.525500, 0.498080, -1.819360, -2.943560,
-1.096550, 0.879510, -3.506820, -1.419450, -0.350730, 0.903750, -2.133510, 0.565080, -0.924910, -0.885510,
-0.030680, 0.373880, -0.805450, 1.992380, -0.448600, 2.111880, 1.235100, 2.066760, -0.958100, -0.387360,
4.779700, -1.057260, -1.638090, -2.170510, 1.489080, -0.433320, 0.348510, 0.041320, -0.423700, 0.538600,
2.544580, 1.535460, -0.179160, -0.169110, -0.162750, 0.734980, -0.373430, 2.034050, -2.805170, 0.268200,
0.517130, -2.270430, -1.286890, 1.170590, 2.059090, -1.162520, 0.184060, 0.777700, 1.951450, -0.436380,
-0.571390, 1.305780, 2.378230, 0.919310, -0.759410, -0.492200, -0.384750, 0.665360, -0.856820, -1.210500,
1.748580, 3.989910, -0.158250, 0.072620, -0.389680, -1.231850, -0.205700, -0.514580, 0.667210, 3.209580,
1.354780, -1.789110, -1.021730, 1.781170, 1.235390, 0.455350, 0.049760, 0.471630, 0.903600, 0.600540,
0.626970, 3.265780, -5.982940, 0.403550, 5.613070, 0.168110, 0.120400, -0.539600, 0.673830, -2.380350,
4.355210, -2.635020, 0.611990, 0.921210, -2.006120, 1.088730, 1.018870, -0.961290, 0.753990, 1.674570,
3.526820, 0.749570, -1.273810, 2.529060, -0.592120, -10.720400, -1.295330, 1.371780, -0.920580, -4.039220,
-0.653150, -1.739760, -2.271440, -0.640220, -1.030200, 2.275180, -2.096290, -0.710890, -0.841160, 0.813400,
0.156240, -0.787580, 12.023260, 3.766080, -0.309330, 1.137870, -0.252690, -0.885600, -5.958600, 1.104400,
4.504920, 3.270240, -1.069780, -0.748010, -0.795260, 0.421700, 0.365190, -0.639920, 0.442130, 1.224040,
-1.624590, -1.088980, 0.613260, -0.985380, 1.020980, 6.136290, 1.759580, 0.056180, 0.776200, 0.525550,
0.435470, -0.966740, -0.657680, 3.678550, -2.612160, -4.396500, -0.026070, -1.219100, -3.025800, -2.114690,
-0.217500, 0.258620, 0.281710, -0.171230, -0.933270, 0.728200, -0.423490, 3.431890, 2.373720, 0.796320,
-0.770540, 0.782380, -2.236280, -0.937660, -1.110180, -0.618130, -1.338000, 0.139360, -1.470140, -1.204790,
0.519250, 0.943920, 0.361030, -2.125950, -3.607970, 0.260010, -0.170310, 1.402840, -0.621350, 0.410240,
-0.396960, 0.770460, 0.082860, -0.637010, 0.667620, -1.088840, 2.481310, 0.606750, 0.942310, -0.504150,
0.934690, -0.234450, -0.665200, -0.438350, -0.083460, 1.444880, -0.086640, -0.594240, -0.840430, -0.209980,
0.630370, 0.817560, -0.351490, -0.155030, 0.219780, 0.737600, -0.137740, -0.864040,
0.143470, 0.874050, -1.742540, 0.329200, -1.301740, 0.403890, -1.083160, 0.681520, 0.827760, -0.380110,
0.296490, 0.067270, -0.788590, -0.127710, 0.483050, -0.028720, 0.402070, -1.065460, -0.320570, -0.451220,
-1.137500, -1.133570, 0.790460, 0.342370, -1.371680, -0.130550, -0.911570, 0.490920, 0.866350, -0.709240,
-1.261520, -0.625900, -0.609050, 1.001270, -0.883930, -0.422060, 2.533910, -1.441180, 0.565970, 1.183930,
-0.661480, -0.440130, -0.602000, -0.274200, 0.281310, -0.440210, -2.888880, -1.352570, 0.164770, 0.756140,
-1.790050, 0.863310, 0.731240, 0.884000, -2.037750, 2.291610, -1.935530, -1.160840, -0.948350, 2.054770,
0.705280, -1.017480, -0.457450, -1.183510, -1.309920, 0.881670, 0.582270, 0.164290, 0.161620, 0.760060,
1.047920, -3.031540, -3.036470, 0.378120, 1.558550, -1.094730, -0.633700, -0.843330, 0.951560, 1.114180,
-0.394650, -0.978440, -0.395240, -0.023570, 1.066730, -1.345950, 0.279420, 0.572410, 2.560370, -0.205970,
-0.339910, -0.888400, 1.612290, -0.337960, -1.986540, 2.075350, -0.477810, -0.631090, 1.530030, -1.091640,
0.690130, -0.050270, 0.043250, -1.437780, -0.114830, -2.269320, 0.339790, -0.528190, -0.192600, -1.826000,
1.885660, -1.856290, 0.109470, -0.175920, 0.477710, 0.352770, 1.267640, 1.015290, 0.239180, -0.279620,
1.243810, 1.218480, -1.576860, 0.780170, 0.859680, -0.172570, -3.749860, -0.594040, 0.332260, 2.143820,
-0.525750, -2.050610, -2.895970, 1.125180, 0.930740, 1.194000, 0.160770, 0.165290, 0.631050, 0.683430,
1.088950, 2.973080, 1.990640, -0.371930, -1.599920, -1.749060, 0.198830, 0.960560, -0.501440, -1.518570,
0.554380, 0.573900, 0.112910, -1.315730, 0.791510, -0.317920, -2.218950, 1.799430, 1.098950, 0.507080,
0.351020, -0.034720, 0.991270, 1.022080, 3.059760, 2.362880, -1.494170, 0.651650, -1.457560, 0.309480,
1.789600, 0.941040, -0.510620, 0.949600, 0.696220, -0.431180, 0.443750, 1.212930, -0.083700, 1.820540,
0.303640, 0.047800, -0.124400, 0.796820, 0.874540, 2.425720, 2.333970, 3.656410, 0.209320, 0.335480,
-0.062150, -2.558890, -0.756720, 0.066940, -1.441590, 0.365070, 1.516270, -0.149160, -0.087840, -2.380790,
-0.027390, 1.247050, 3.850780, 1.024260, -0.147090, -0.252620, 1.037640, 0.976370, 0.676410, 1.902900,
2.285030, 0.658610, 0.265860, -1.133080, -3.446120, 0.951740, -0.107440, -0.008630, -1.824000, 0.888040,
0.376140, -0.139560, -0.715530, -1.665900, 2.026410, 1.448360, 1.559150, 0.376340, 0.704850, -2.630870,
1.537250, 1.559110, 0.756080, 4.544750, -1.106590, -0.175800, 0.377890, -0.055970, -0.603770, 2.087920,
-1.300040, -2.581960, 0.102470, -2.081330, -0.224850, 0.166300, 0.895030, 0.458290, 2.616350, -0.281140,
0.031510, 0.631800, -0.243280, -1.315690, 0.622350, -0.401030, 0.215550, 0.711230, -0.448930, -0.281460,
-0.325570, -0.827500, 2.154970, 1.906790, 0.354680, -0.789390, -0.279910, 0.005040, 0.816900, 0.336040,
-0.431860, -1.373170, -0.066720, 1.404850, -0.801520, -0.512130, 1.746600, -0.377260, -1.125630, 0.869900,
3.309160, -0.539870, -0.088170, 0.945970, 0.004350, 0.255320, -3.418610, 0.395510, -0.033320, -1.727060,
-0.630820, -0.798990, 0.357110, -0.231850, 0.017830, -0.323110, -0.919290, 0.215070,
-1.127480, 0.836850, -1.265840, 0.925470, -2.055990, -1.539210, 0.030610, -0.579980, 0.165610, 1.523490,
1.560370, -3.621710, 0.614100, -0.119910, 1.101710, 1.523860, -1.052140, 0.981230, -0.338690, 1.294670,
-2.656460, -0.481420, 0.368230, -1.845100, 0.221100, 0.418800, 0.570490, 1.746190, 1.870310, -0.683460,
-0.054890, -1.859860, -0.462300, 1.587920, -0.711600, 0.164060, -1.800860, 1.179330, -0.805770, 0.054860,
-0.872500, 0.601810, -0.426410, -1.044110, 0.007740, 0.247930, -0.145770, 1.487150, 0.759550, 0.024690,
-0.208480, -0.789550, -0.147490, 0.615050, -0.945790, 0.624600, -1.144250, -0.248290, -0.552070, -1.143680,
-0.937620, -0.298180, 0.431190, 1.193350, 0.788670, -1.144150, -0.432600, 0.913510, 0.222140, 3.639040,
1.692400, -1.848860, 0.940140, 0.800520, -1.636000, 0.584350, -0.368970, 1.588750, 0.588280, -3.556060,
-0.147000, -0.313990, 1.088150, -0.549220, -0.292410, -0.822480, 0.943060, -0.115640, 1.383420, 1.880700,
-0.213490, 0.744830, 1.974260, 0.386000, -0.464080, -1.075250, 1.785620, -0.527260, 0.055110, 0.186960,
0.649120, -0.747930, -2.335080, -0.962280, -2.055190, 3.319140, -0.475110, 0.426610, -0.608200, -0.699590,
2.625400, 2.374700, 1.404350, 1.920030, 0.390940, 1.762980, 2.946870, 0.657040, -2.847230, 0.081970,
0.648510, 0.683540, -0.677320, 0.913530, -1.354890, -1.982030, -1.330860, -1.232730, 4.346450, 0.025270,
-2.009800, -2.658380, 0.663260, -2.216420, -2.212860, 1.143220, 0.018080, 0.595740, -1.962690, 4.352230,
0.500840, -0.535620, 0.355230, -0.218180, -0.863600, -2.641600, -1.761190, 1.421500, 0.808020, 0.942540,
1.804920, 1.841280, 0.161440, 1.325700, -0.334280, 0.770820, 0.486050, -0.262190, 0.642710, 0.190430,
-1.304280, 0.229200, 0.081740, 0.532720, -0.662840, 0.211550, 1.467540, 0.699430, -0.179480, 0.003820,
-0.885200, -0.142330, 1.459840, -0.638080, -1.776170, -2.310780, 0.412820, -0.023010, -0.229190, -1.214610,
-1.489390, -0.163070, 0.540490, 0.099980, -3.423660, 0.259030, -0.614510, 0.149160, -0.283510, 0.078630,
1.033400, -1.153730, 0.077500, 0.196520, 0.951580, 0.388340, -1.452420, -1.399070, 0.435680, 1.079720,
-0.028270, 0.517320, -1.580000, 0.068400, 0.899330, -1.387050, -0.193590, -0.035280, -0.400610, -1.372300,
0.335170, -1.077240, -0.279770, 0.837640, -0.292480, 0.700650, -0.979810, 0.082010, -0.172490, 1.025790,
-1.712810, -0.150410, 0.391930, 0.224580, -0.324740, 1.028050, -1.014830, -0.223090, 0.314810, -1.752660,
0.129120, 2.088080, 0.406590, -1.235680, -1.371400, -0.246920, -0.627820, -0.738790, 0.204240, 0.694190,
-0.396510, 0.089810, -2.031220, -1.989790, -0.731340, -0.068740, 0.341610, -2.109050, -0.185960, 0.259600,
0.365260, -0.509550, -0.742440, 1.920220, 6.879150, 2.561440, 0.642800, 0.013600, 0.221180, 1.240110,
0.615130, -1.934710, 0.193290, 0.943930, 3.939720, -0.167510, 1.597940, -0.123310, -1.428610, -2.836580,
0.533150, -0.729400, -0.751910, -1.976260, -0.738770, -0.178090, -1.185110, -1.065940, 0.340070, -0.493660,
-9.127610, -1.072660, 0.194900, -1.161280, -0.217860, 0.212060, 1.334890, -1.252340, -1.143230, -0.403430,
-0.629210, -1.267120, -2.480250, -0.916970, -0.709560, -1.193890, -0.809300, -0.229240,
0.880450, -4.668400, -1.317250, 2.395480, 0.087160, -0.855690, -0.165400, -0.061930, -0.088110, 0.933700,
-0.666790, -0.200910, 0.258950, 1.070800, -0.232300, 0.696250, -0.922760, -1.345220, 0.977040, 0.026490,
0.690620, 1.208740, -1.474050, -0.623080, 0.368860, -0.063960, -0.072050, -1.308620, 0.245500, 1.230430,
-0.972420, -2.071240, -0.410160, 1.752850, 1.580720, 1.611360, -1.595020, 0.202870, -0.627210, -0.336700,
-1.731400, 2.534550, 1.097780, -0.471630, -2.813680, -3.105910, 0.570300, 1.178940, 0.425600, -0.505120,
-0.522830, -0.915620, 0.315940, -0.239920, -0.500840, -0.672130, 1.155950, 0.315890, -0.135860, -1.889800,
-0.013590, 0.107380, -0.131950, 0.223200, -2.415690, 0.762550, -0.228570, -0.669010, -1.418620, 0.544760,
-0.364920, 0.695700, -0.254120, 1.215340, 2.418810, -0.539530, -0.283890, 2.242180, 1.536140, -1.039950,
-0.574610, -0.195190, 0.022490, -0.583470, 0.061880, -1.448490, -2.977810, 2.201780, 0.483730, 0.441860,
0.533060, -1.124880, 0.441980, 0.075160, -2.729890, -0.776800, 0.760720, -0.710980, -0.725280, -0.347140,
1.570770, 0.627090, -3.267580, 0.881140, 1.519440, 0.968120, -1.121370, -1.163420, -0.338420, -1.637100,
0.236030, 0.528230, 0.902190, 0.619150, -0.901950, 0.975130, 0.211760, -0.545630, -0.071180, -0.893220,
1.662870, 0.019130, -0.220630, -0.017960, 0.231400, -2.761470, -0.701330, 2.063680, 0.156960, -0.244450,
0.023890, 0.703810, -0.941380, 1.275290, 1.490220, -0.090590, -0.634480, -0.914660, 0.694270, -0.007970,
0.190740, 1.185100, 0.215780, -0.427810, -1.014800, -1.272820, 1.307060, 0.418970, -2.616120, -1.962270,
0.350680, -0.188400, 0.785070, 0.838450, -0.283100, 0.556900, 3.493100, 0.010220, 2.114530, 0.043960,
-0.433320, 0.194080, -2.666600, 1.214940, 3.186050, -2.503850, 0.605180, -1.032490, -0.080750, -0.397550,
1.945650, -0.004730, -0.155490, 1.652700, -1.802350, 0.111230, 1.799920, 0.369040, -0.831540, 1.906850,
0.758080, 0.067960, -1.072940, 1.017890, -0.886920, -3.263460, -0.662450, 5.264280, -0.271870, -0.231870,
0.459810, -0.050070, 1.076040, 1.011330, -3.283360, -0.290100, 1.407020, -4.673810, 0.011000, 0.958250,
1.125790, -1.054120, 1.240390, 2.465440, -0.312430, 0.330770, 0.621390, -0.415820, -8.081680, 1.071130,
3.861550, 0.137710, -3.441060, -0.398680, -1.126070, -2.634840, 1.195690, -0.886150, -0.185790, -1.964570,
-2.829440, -1.373740, 0.330710, 0.997590, -0.891680, 1.743950, 0.827780, -0.955860, -0.924990, 1.426020,
-1.183720, -6.370100, 2.251970, 5.128160, -0.731190, -1.717340, 1.334780, -3.205650, -0.465030, -1.619360,
-5.184600, -0.115180, -1.271970, 0.523950, 0.395060, -0.515220, 1.497610, -0.320050, 4.300520, 1.014280,
-0.887920, -0.755990, 1.446430, 0.591260, 0.553210, -1.177780, -0.162440, -0.063310, -0.927810, -0.270050,
-0.753470, 0.965750, -1.936640, -0.633040, 1.354560, 0.496190, 0.772980, 0.109990, -0.845600, 0.252440,
0.896470, -0.590640, -1.451740, -1.200890, -0.857280, -0.024320, 1.526930, 0.020760, 0.087210, -0.715540,
0.704720, -0.377490, -1.196740, 1.347930, -0.653030, -0.815170, 0.915160, 0.694040, -0.922830, 0.373360,
-0.084030, -0.620620, -0.256540, 0.164690, -0.311480, -0.215550, 0.306020, -0.342420,
1.081090, -0.007530, 0.408640, 0.040750, 0.516350, -0.633710, 0.035700, 2.373290, 0.413350, 0.060240,
-2.264500, -0.376840, 1.187410, -3.042570, 0.419910, 0.401850, 0.655540, -1.629630, -0.523830, 0.798820,
0.578240, 0.223220, 0.231240, -0.374050, -2.415450, 0.349350, -0.010090, 0.989000, 0.901980, 0.528610,
-0.494340, -1.736740, 1.352670, 0.658840, 0.640320, -0.691580, -2.647480, -0.475290, 0.243580, -0.182540,
-1.123120, -1.329980, 0.225340, 0.537690, -1.980940, -0.067640, 1.417810, 0.766150, 0.120560, 0.387930,
-1.159750, 0.157650, 0.595680, -2.914890, 1.891070, -1.365060, 0.014620, 0.182420, -0.790210, 0.800490,
-0.211210, 0.996730, -0.383980, 3.146340, -0.804490, 0.169510, 0.707440, -0.497780, 0.313870, -0.119360,
-0.757450, 2.129990, 0.837050, 0.123750, -0.988570, 0.516010, 0.320610, 0.060910, 0.408410, -1.748020,
-1.904130, -2.417780, -0.117670, 0.193020, 0.048820, -0.950710, -0.532520, 1.541550, -0.539570, 1.847820,
0.380250, -1.356710, 0.166220, 0.704950, 1.723010, 0.984910, -0.476650, -1.650970, 0.496520, -1.367670,
-0.566620, -0.581310, -0.782500, 0.953940, 0.149760, 0.071850, 0.248300, -1.266700, -2.075800, 1.959910,
0.635100, 1.125790, 0.074380, 0.274580, -0.944680, -1.178200, -0.441200, -0.696890, -1.421220, 1.467930,
-0.251990, 1.007670, 1.170200, 0.791070, -1.570500, 0.199230, -1.346630, 0.262600, 1.129190, 1.319690,
1.671350, -1.174670, 0.699830, -1.411050, 0.172850, 0.556930, -0.716910, 1.270070, -0.443900, -3.817540,
-0.597230, -5.401500, 0.899580, -0.768210, 1.547390, 1.557830, 0.401890, -0.473810, 1.781130, 0.483090,
-0.339690, 0.070380, 0.242360, 0.991030, -0.738430, -0.899290, -1.082690, 1.875370, 0.828790, -0.340200,
-1.741720, -2.770080, 4.629470, -1.231580, -6.565170, -0.812180, 1.276890, 3.080520, 0.990380, -2.532190,
-1.973470, 3.721090, 0.985520, 1.463440, -1.886350, 0.474300, 0.007190, -0.727270, 1.049860, 0.117900,
-0.391260, -2.232060, -0.237270, -2.685180, -3.002550, 5.406780, -0.534410, -3.557530, -1.139450, -0.161650,
0.523000, 1.256940, 1.175520, 0.156020, 1.909560, 0.747720, 0.901900, -0.371750, -0.330080, -1.144330,
-1.606820, 0.087540, -2.466370, -0.290290, -1.025810, -0.252740, -1.271240, -0.621980, 3.519250, -0.843030,
-2.047780, 0.563570, 1.195670, -0.248370, 1.418750, 1.072800, 0.505790, 2.385530, 1.844950, -0.855740,
0.775450, 0.968810, 0.180170, -0.478810, -1.465780, -1.988620, -1.261670, -0.661380, -0.842080, -0.748770,
-0.873270, 3.446510, -1.142270, -3.265400, 0.225920, 2.448080, -0.346060, 0.646420, -1.195150, -1.221650,
4.614830, 1.608340, 1.041670, 0.160590, -0.340170, 0.380920, 0.145710, -0.180310, -2.382810, -0.688750,
-2.902790, -0.032090, -0.892060, -0.901330, -0.888380, 1.174280, 0.131740, -0.463360, 0.021080, -0.597820,
-1.638690, 0.667750, -1.142880, 2.299630, -0.354380, -0.441460, 0.977170, 1.598620, 0.505220, -0.009220,
-0.030670, 0.272220, 1.978980, -0.306990, 0.076420, 0.673400, -2.536670, 0.719240, 0.850180, -0.505900,
-5.659810, -0.961830, 0.419070, -0.615790, -0.443030, -0.320520, 1.305270, -0.851020, 1.546720, 0.985550,
0.234500, -0.119090, -1.443740, -0.981780, 0.953530, 0.119860, 1.096940, 3.751870,
-0.476620, -1.009990, -0.700260, 2.000050, -0.372620, -3.155170, 1.633290, -1.329440, 1.284280, 2.894520,
0.722370, -0.284740, -0.877660, 1.395680, -1.480110, -0.170440, 1.059630, 0.221700, 0.755670, -0.297990,
-0.100700, 0.571090, -0.398710, 0.984390, -0.092980, -0.217650, 7.413930, -1.600100, 1.536000, 0.919190,
-3.779260, 1.858770, 1.202650, -4.275220, 2.326770, -0.318870, 0.239720, 0.403180, 1.580170, -1.438680,
-1.977180, 0.114960, 0.421420, -0.350840, -0.925800, -0.782400, -0.662580, -0.293930, -0.967380, 0.620540,
-1.051450, 0.601970, 0.726800, 1.398710, 1.067550, 0.042070, -0.119740, 0.102950, 1.294060, -0.277140,
-1.028200, -0.667610, -0.407240, 1.829700, 3.856780, 1.081550, 0.794950, 2.475210, 1.397240, 0.274490,
0.981460, -0.139120, 2.248410, -0.477870, 0.656710, 0.574590, 0.145600, 0.985940, 0.567950, -1.529220,
-3.054480, 1.152970, 0.573510, -0.334690, 1.453390, -1.058710, 0.797540, 0.729460, 1.634180, -0.443180,
0.185810, 0.343030, 3.100340, 1.165600, 0.921370, -0.979960, -0.882740, 0.907360, -0.709080, 1.133550,
1.192580, -0.326320, -15.114840, 2.040380, 0.645140, 1.766820, 0.262930, -2.172440, -1.476730, 1.528110,
1.693630, -0.457320, 1.290610, 1.531050, -0.283960, 0.555970, 1.548710, 1.047910, 1.601390, 1.740080,
1.086600, -1.028680, -0.260350, -0.056280, 1.342250, -5.154080, 0.171170, -0.944520, 4.613170, 0.114730,
0.346300, -1.950220, 0.392380, 3.023300, -1.607370, 0.108270, 1.581810, -0.968120, -1.547230, -1.093910,
-0.267300, 1.457390, -1.526390, -1.868570, 0.785020, -1.264250, -3.997790, 0.445710, -0.171170, -0.489030,
0.532540, 0.008780, -1.560730, 0.344200, 1.704220, -2.627060, 1.156390, -1.753910, 0.533790, 0.889420,
-0.856790, -1.342820, -2.936830, -1.359360, 1.588960, 2.535330, -2.151220, 1.199500, -1.585730, -1.826020,
-0.998340, 1.707460, 0.730950, -0.035920, 0.209340, -0.065670, 0.271900, 0.910720, -3.716210, -0.123190,
-0.532060, 0.173520, 1.293790, 0.693160, -0.425830, -0.857860, -0.486410, 1.661110, 1.014880, -0.551280,
0.111650, -1.039870, -1.755310, 0.545370, -0.326850, 0.772820, -0.286300, -1.188600, -0.364900, 0.302940,
1.275510, 0.865090, 1.464060, -0.611410, -0.087200, -1.227420, 0.494750, 0.260280, -0.065490, -0.673630,
2.621320, -0.432610, 0.117780, -0.082050, -0.657980, -4.242380, -0.686150, 1.353890, 1.350140, -0.832540,
-2.169380, 0.082970, -0.249950, -0.282530, -0.492550, 1.382410, -0.051710, 0.414750, -1.150730, 2.004520,
0.728400, -0.504010, 2.093760, 2.346040, -0.014070, -2.670190, -0.149290, -1.249210, 0.067630, 0.053600,
-2.904380, 0.186430, 0.239320, -2.030950, 1.121700, 0.290100, 2.460420, -2.328920, 0.414020, -0.196630,
1.284850, -0.008940, 0.411800, 0.228270, 1.336330, -0.684690, -0.548000, 2.088350, -0.888750, 0.528920,
0.620290, 3.160780, 0.459670, -0.041840, 0.553750, 0.145950, 1.655120, 0.329830, 0.527580, 0.986290,
-0.634410, 0.666670, -0.450660, -1.593090, 0.362650, 0.970150, -0.253670, 0.716570, 0.342000, -1.398550,
2.814440, -0.454080, 0.564950, 2.576910, -0.268250, 1.175950, -1.739750, 0.959610, -0.291330, 0.916450,
-0.716960, 0.733710, 0.774260, 0.773870, -0.439430, 0.126020, -0.240700, 0.248230,
0.663310, 0.387740, -0.018910, 0.375960, 1.190370, -0.347300, -0.004060, -0.570730, -0.049810, -0.240140,
0.201710, -0.857270, 0.870900, -2.255750, -1.306910, -1.339100, 1.043110, -1.089800, -0.792970, 0.647650,
0.078490, 0.594300, -0.725070, -0.961140, 0.266400, -0.613250, -0.411070, 1.587940, -0.331180, -1.474570,
0.655120, 0.209610, -0.635420, -0.754980, 1.189520, -1.265310, -0.814720, -0.891220, -0.390110, 1.377490,
1.744930, 0.102330, -0.017540, 1.551430, 0.139580, -0.560470, -0.699580, -1.484020, -0.405810, 0.259980,
0.444370, 0.097770, 0.432680, -0.201410, -0.475420, 0.091250, 0.186820, -0.939170, 1.211960, -0.426220,
-1.175540, -0.576900, -1.968130, 2.537010, -0.345720, -0.057040, 1.539520, -0.803070, 1.940830, 0.157820,
2.394440, 0.388820, -0.569130, 0.864760, 1.536220, 0.322000, -1.800490, 0.566870, -0.171930, 0.902760,
0.945390, 0.917330, 0.541450, 3.714710, 1.162250, -2.591910, 2.985160, 0.117930, -0.293470, 0.089510,
0.495010, -4.823250, -0.514240, 2.410580, -0.643700, -0.185980, 2.225720, -1.609980, -0.139930, -0.522720,
0.881050, 2.177530, 1.036940, -0.261410, -0.883980, 3.270460, 2.186440, 0.170080, -2.301700, 0.835140,
-0.293150, -1.331330, 2.351120, 0.052810, -1.653160, 2.430510, 2.450130, 1.906620, 0.126830, 0.582110,
0.521020, 0.764330, -0.078360, 0.730970, 1.161830, 0.899390, 3.014200, -0.379680, 1.754980, -0.912140,
-0.063860, -0.570970, 1.711360, 0.341050, -1.185820, -0.644280, -0.325330, -0.326030, 1.741690, 1.519350,
-0.062120, -0.316050, -0.928750, 0.810010, -1.286880, 0.834630, -0.972410, -1.342590, 0.807570, 1.608960,
-0.396970, -0.628000, 0.738550, 1.449880, 2.765730, 1.495910, -0.659360, -0.622450, -2.821750, 0.695520,
-0.083900, -0.841550, 0.852770, -2.553190, -2.968630, 2.839750, -0.758610, 1.047730, 0.462830, 0.390250,
-1.363440, -0.337810, 1.980140, -0.098790, 3.169480, -0.486570, 1.259700, 2.055510, -0.931180, -1.479530,
2.210910, -0.665200, -1.799910, -1.113330, 1.287560, 3.289870, -0.695480, -4.030610, -0.419820, -0.012300,
0.776110, 0.713470, 0.969780, 1.372150, 1.409610, 0.999090, 1.573020, 2.454460, 1.407460, -2.173230,
1.455890, 1.212300, -1.291450, -0.925570, 1.051300, -1.091730, -0.836300, -1.654560, 4.261810, -0.831760,
-0.312260, 0.989450, 0.093390, -0.329250, 0.363880, -0.824880, -0.046010, 2.233330, 2.023940, -0.812770,
-0.126720, 0.669150, 1.354720, -0.168630, 1.482320, -1.071760, -1.406330, -0.606590, -2.674210, -0.237570,
-0.472420, 1.206440, -0.470240, -1.974050, -0.159020, 0.544100, -0.071410, -2.341770, 0.743440, -0.038380,
2.034910, 0.567430, 0.446440, 0.344470, -2.073410, 0.724440, -1.006200, -0.061740, -0.657790, 0.557060,
-0.149520, 2.977020, -0.653540, -3.768680, 3.204030, -1.971950, 1.297090, -0.066340, 1.093790, 0.599320,
-0.066740, 0.505360, 0.037290, 0.251330, -0.204560, 0.961700, -0.993550, -2.650170, 0.741400, -0.386790,
1.007450, -0.200210, -0.110670, 0.550230, -0.388820, 1.225620, -0.416080, 0.206660, -0.093940, 1.236720,
-3.143520, -0.723990, 2.291450, 0.453140, 0.625650, 1.278920, 0.136740, 0.897610, 0.296580, 0.279960,
1.524870, -0.046990, 0.583950, -0.309920, 0.604140, 0.348750, 0.715300, 2.705780,
0.592300, 0.835070, -0.504140, 0.234560, 0.106410, 0.352200, -1.428720, 1.377900, -0.006810, 0.088160,
-0.367020, 0.791720, 1.684400, -0.481790, -0.731850, 1.329330, -0.912840, 0.231100, -0.032640, 0.085870,
1.150390, 3.917640, -0.036640, 1.727120, 0.463920, -2.585840, 2.258490, 0.580310, -0.390870, -1.845440,
2.013750, -0.208580, 0.794650, 0.274180, 0.649240, 1.815620, -0.033520, 0.024280, 0.465700, 0.335400,
-0.059700, 0.166780, 0.290550, -1.793200, 0.769430, 0.811950, -0.443270, -1.277700, -0.255350, -0.452730,
0.431870, -0.870790, 0.837860, 2.047540, 0.849330, -0.826700, -0.336210, -1.556680, -0.324010, -1.026830,
-1.082380, -1.259190, -0.869490, -1.652260, -0.145200, -0.389090, -0.011980, -0.170650, 0.925030, -0.422400,
2.304970, 0.018950, -0.177350, 0.275820, 0.029040, -0.659640, -0.362090, -0.123550, -0.213000, 0.036220,
0.799600, -0.876530, 0.632940, 0.199800, 0.800930, 0.796990, 0.589570, 0.652380, 0.223580, 1.262450,
-0.442480, 0.680030, -3.175890, -0.401090, 1.448330, 3.770550, 0.665350, -2.057860, -0.414500, -3.102660,
-1.550710, 1.852140, 8.635200, 0.977190, -0.223740, -1.388250, -1.381630, 2.127260, 1.117440, -0.517160,
-0.908890, -1.088880, 1.274770, -0.509670, 5.297990, -3.023010, -4.633080, 0.116630, 4.000570, 2.143070,
-1.558850, 3.023340, -0.356410, -2.478470, 1.037310, 4.798090, -0.624840, 0.057200, -3.173290, -0.219220,
1.152180, 4.354180, 0.575580, 1.064300, -1.620070, -0.130280, 0.332920, 3.202530, -3.819070, -2.168390,
0.166210, 1.627020, -0.491410, -0.821020, -0.346770, -1.290340, -2.030020, -0.120680, 3.604900, 1.133100,
-0.556470, -3.641880, -1.028510, -0.076320, 6.590890, 1.534620, 2.360370, 0.664570, 1.157500, -0.052840,
4.445390, 1.136550, -4.283010, -1.681920, 1.383780, 0.620960, 0.451120, 0.943810, -1.205180, -0.029850,
0.441090, 2.271980, 1.772650, 1.731330, -2.191300, 2.169750, 0.362080, 11.458830, -0.178890, 1.961070,
0.996760, 0.735200, 0.660640, 2.380480, 0.062700, -3.586250, 1.708410, 0.355710, 1.173150, 0.708000,
1.288640, -1.336720, -1.205370, -1.425700, -0.463460, 0.527190, 0.535210, 2.562380, 2.379860, -1.279520,
-0.430120, 0.501910, 1.694280, -0.381420, -0.281150, 2.104070, 1.577760, 1.178520, -0.699460, 1.208890,
-0.772800, -0.916240, -1.353610, 0.632020, -0.574870, -0.273730, -1.567310, 0.638070, -0.194210, 3.304820,
-1.030760, 1.401680, 2.332740, 0.663180, 0.928490, -0.660940, 0.774920, -0.182300, 1.767700, -0.488090,
3.581370, -2.766800, -1.931140, 2.370830, 0.358930, -0.134420, 0.556480, -1.188210, 0.048160, -1.299700,
-0.304160, 1.190500, -0.133510, 0.677280, 2.098960, -0.022640, 0.255180, 1.138280, -1.283940, -0.155500,
-0.519990, 0.423550, 0.130540, -0.294880, 1.664020, 0.643800, 0.825390, 1.753760, -1.339730, -0.519730,
-1.265500, 2.286720, 1.902960, 2.387030, -5.722950, -1.186330, -0.080980, 0.123950, 1.865870, 0.190940,
-0.483360, -1.223350, -0.883460, 3.025980, 2.265170, -1.991720, -0.434620, -0.147520, -0.720790, 0.960180,
1.157030, 1.264040, -1.301680, 0.822480, 0.034010, 0.893700, -3.116890, 0.719960, -1.535900, -0.329310,
-0.331990, 0.505380, 1.775450, 0.332110, 0.475150, 1.367610, -0.691960, -1.155400,
0.170690, -1.192050, 0.292910, 0.115070, 0.893390, -1.452020, -1.768100, 0.420910, -0.093400, -0.307770,
-0.846950, 0.038790, -0.750360, -0.334990, 0.347370, -0.144720, 0.708740, -1.768570, -1.389430, 1.019780,
-0.385030, 1.016550, 0.786610, -0.929550, -1.049180, 0.881020, 0.989010, 0.476170, 0.319120, -0.473440,
0.386840, 0.797440, -1.399250, 0.020530, -1.551210, 0.163000, -1.899130, 0.586310, 0.296580, 0.404420,
0.025250, -0.932600, 0.817780, -0.503540, -0.173340, 0.483910, 1.230530, 0.395820, 2.167540, -0.108510,
1.048220, 0.580110, -1.444270, 0.115250, 0.751250, 0.248960, 0.324500, -0.135750, -0.513260, -0.858360,
-0.395310, 0.053520, 0.021840, -0.558150, 0.162100, -0.332650, -0.753640, 0.701280, 0.361950, -0.278160,
-0.373780, -1.544950, -0.145590, -0.367780, 0.340470, -1.304830, -0.908680, 0.821960, -0.076250, -0.519750,
-0.535620, -0.146540, -0.593220, 0.388030, 0.152820, 1.510950, 1.796260, 1.521250, -0.111070, -0.265350,
-0.744900, 1.263920, -0.330120, 1.406460, 0.175020, 0.974480, -1.830700, -1.742000, 0.105160, 0.184520,
-0.016120, -1.250560, -2.268230, 0.824590, -0.336940, -1.647740, -0.396960, -0.675670, -0.423160, 0.184660,
1.853160, 0.474400, -1.824300, -0.991590, -0.859020, -0.425290, -1.651140, 0.524980, 2.046510, 0.748990,
-1.711060, 0.073800, 0.717950, -0.273550, 0.883690, 1.459110, -0.414430, 1.621130, -0.821560, -0.873210,
2.103160, 1.138460, 0.164270, -0.215640, 0.540120, 0.344120, -1.997370, -0.354450, 1.150560, -1.689910,
0.804590, 2.386870, 0.001740, 1.403050, 0.340270, -1.692450, -0.643910, 4.461290, 1.852310, 0.374810,
-0.194800, -1.558650, -0.673310, 0.376070, 0.790510, 0.286010, -0.879510, 0.011370, -0.787930, -1.652900,
0.479250, -0.875950, -5.131990, 1.730670, 1.229270, 2.196880, -1.199860, 0.343640, 1.080080, -0.376760,
0.637370, 0.593740, 0.772970, -1.247880, -1.792910, -2.001820, 0.519460, 1.151010, 0.262020, -1.068280,
0.091080, -2.692880, -1.077840, -0.099730, 0.479130, -0.144960, -0.537690, 0.515370, 2.396310, 0.083150,
1.955600, -2.815620, -0.475220, 1.121890, -0.609560, -0.832600, -0.329710, 1.031070, -0.319310, -0.550030,
0.694920, 1.022730, -0.254600, -0.651430, -3.359120, -0.078800, -0.818160, 0.327530, -1.349950, 1.258550,
-0.645040, 0.573140, -0.217370, -1.864190, -0.504690, 1.347250, -0.932510, -0.362280, 1.199900, -0.550990,
0.135850, 0.449530, 0.085390, 0.863790, 0.436730, -0.672840, -0.604650, -2.387840, 0.711200, -2.545210,
0.899040, 0.020880, 0.213220, 0.704800, 1.871910, 0.357160, 0.398120, -1.145470, -0.504990, 0.508540,
-1.473140, -0.664380, 0.744780, 0.063390, 0.561720, 0.674720, -0.560310, 0.946820, 0.800500, 0.486930,
0.351640, 1.985020, 0.650090, -0.897360, -0.193320, 0.298040, 0.700420, -1.094210, 1.097180, 0.464110,
1.043370, -1.308110, 0.301140, -0.292160, -0.167970, -0.522300, -1.064760, -0.603900, -0.583380, 0.777290,
-0.433020, -0.043980, -0.410420, -1.856710, 0.209230, -3.005770, -0.679510, -1.211480, -0.717700, 0.263600,
2.337120, 0.605340, -0.992720, -0.005990, -0.774040, -0.968520, -3.213510, 0.712440, -3.966440, 0.208370,
-0.208180, -0.266090, 0.551670, -0.110210, -0.780260, -0.446860, -3.166210, 0.303330,
0.453030, 1.120490, 1.898050, 0.780870, 0.372050, -1.211310, -0.801200, 0.676590, -0.456540, -0.073120,
-0.942550, -0.225550, -0.677340, 1.796420, -0.339040, 0.516430, 1.026850, -0.485640, 0.868260, 0.446270,
0.008170, -0.220120, 0.935830, -1.011950, -0.067480, 1.681610, 0.564170, 1.010540, -0.860550, 0.992360,
-0.016800, -0.868890, 1.503490, 0.680430, 0.943280, 0.264290, 1.522460, 0.771650, 0.588000, -0.423140,
1.436320, 0.672050, 0.615090, -0.326670, -0.861270, 0.049150, 1.271960, -0.698600, 0.400190, -0.155080,
0.035860, -0.908870, -0.812820, -0.523970, 1.024060, -0.502030, 1.695760, -0.430020, 1.022230, -2.558340,
-0.617430, -0.552100, -2.002130, -0.166210, 0.631200, 1.460000, -0.663900, 0.118440, 2.402530, -1.574660,
-1.265680, -0.069530, 0.915230, -0.259690, 1.562430, 0.784900, 0.684100, 3.408720, 1.222310, 0.510900,
0.189300, -0.179820, -0.643570, 2.191590, 0.544260, -0.003830, -0.232120, -0.441570, 1.872000, -0.756530,
0.143610, -0.338330, -0.528810, -1.061390, 0.498150, 0.866200, 0.727150, -1.656680, -0.717100, -1.376130,
-2.260960, 1.914470, -0.577630, -1.039580, 1.437760, -0.702600, -0.991920, 0.995330, -0.127780, 0.792070,
3.113820, -0.333340, 0.496610, 0.155220, -2.489480, 0.665910, -2.879050, 0.318430, 1.560910, 1.044820,
0.726210, -0.088290, -2.013350, 1.354330, -0.841590, -0.184020, -2.136520, -1.389280, 0.696900, -1.547280,
1.821930, 2.501660, -0.189470, -0.220540, 0.410740, 0.144260, -0.850380, -1.245570, -0.029030, 0.907690,
0.404470, 1.066390, 0.878280, -0.998300, -0.035430, 0.491060, -0.097340, -1.673880, -0.981920, 0.266800,
-0.982840, -1.198300, -0.430350, 0.245800, -0.897310, -0.172300, 1.614920, 3.828660, 0.667070, -0.424910,
-0.103670, 1.009450, -4.159530, 1.153570, 0.610450, -0.597640, -0.478790, 1.535700, 2.005410, -2.511730,
-0.372830, -0.720920, -0.694150, 0.606660, -0.794460, 0.145010, 0.561060, -0.405060, -0.664840, 1.461290,
0.044370, -2.722580, 0.818550, 1.009170, 0.040700, 1.161130, 1.233110, -4.114740, 0.229660, -0.599060,
1.187420, 1.543030, -1.084400, -0.467160, -0.943130, 0.215550, 1.013110, 1.831680, -1.724110, 0.161110,
-1.967770, 0.671040, 0.626670, 0.220100, 0.078340, 0.085650, -1.817340, 0.746930, -0.518740, 0.847880,
0.389580, 0.930870, 0.449450, -0.848860, -0.182870, 0.095770, -0.572630, -4.315180, -0.332320, -0.163780,
-1.438050, -0.022440, -0.124230, 1.030980, 0.494910, 0.212640, 0.317410, 0.239280, 0.024310, -0.766470,
-0.990990, -0.135010, 0.053140, -0.033540, 0.657960, -1.416270, 1.007550, -0.053680, -0.075250, -1.604440,
-1.451520, 0.245670, -0.244770, 0.067590, 0.456230, -0.458650, 1.335760, 0.622190, 2.218380, 0.427240,
-0.264070, 0.128700, -0.248710, -0.493610, 0.251230, -0.662680, 1.040130, 0.953630, -0.779930, 0.707720,
0.071800, -1.393170, -1.106030, -1.060900, -0.554610, 1.305160, -0.742610, 2.124250, -0.021350, -1.292980,
-0.215420, -0.248030, -1.307180, 0.019700, -0.576590, 0.375050, -0.808940, -0.296570, -1.583400, -0.623750,
8.607690, -0.940360, -1.083050, -0.304950, -0.146310, 0.479870, -1.427880, 0.368230, -2.015950, 0.225740,
-5.791820, 0.415890, -0.150130, 0.816970, 0.254340, -1.445910, -8.565700, 0.383600,
-0.009850, -0.126330, 0.273720, -0.363290, 0.025260, -1.387070, -1.340580, -0.744950, -0.312660, -0.215580,
0.063650, 1.271900, 0.171470, 0.043290, -0.607170, -0.939310, -0.530230, 0.177920, 0.082400, -0.527130,
0.480710, 1.436850, 0.940040, -1.030120, -0.879440, 0.058560, 0.184490, -0.616790, -0.267780, -0.142670,
-1.256400, -0.535030, 0.585020, 0.152190, 0.021410, 0.864610, 0.891500, -0.160350, 0.072610, -0.370050,
0.701870, -0.612820, 0.338220, 0.054620, -0.284310, -0.798380, -1.137360, 0.229250, -1.268000, 1.252830,
0.096900, -0.375740, -0.410300, -0.822200, -1.200840, -0.033910, 0.324180, 0.020040, -0.116510, 0.589100,
-0.412860, 0.863450, -0.612430, -1.035220, -0.382370, 1.216590, 1.793210, -0.309570, -0.172800, -1.603810,
0.587540, 0.298210, 0.653350, -0.688410, 1.034350, 1.379030, 0.276450, -2.810990, 0.442780, 1.260870,
-0.080130, 0.344460, -0.725120, -0.945020, -0.843430, -0.023030, 1.157260, -0.545230, 0.737800, 0.018370,
-1.477540, 0.082280, -1.300810, -2.042360, 0.322530, -0.091520, 1.375390, 2.549430, -0.371160, 0.635800,
0.147940, 0.930890, 0.346440, 0.896210, -0.743040, 0.178600, 0.038070, -0.515850, -1.513770, -2.191860,
0.618660, -0.218570, -0.836640, -0.068760, -0.848150, 1.087720, 3.005310, -0.285620, -0.530790, 0.184340,
3.386750, 0.008900, 0.827850, 2.635120, -0.959050, -1.976260, -1.215200, 1.199200, -0.351670, 0.930590,
-0.446360, -0.860100, 0.974610, -1.625600, 0.066990, -0.890080, -0.695630, -0.094200, 2.213480, 8.914980,
0.536460, -0.162340, -0.663560, -0.405210, -0.005810, -2.343650, 4.061980, -0.512260, -1.096590, -1.061610,
0.397410, 1.529720, -0.989200, -0.217720, -3.645730, -2.303100, 1.898580, -0.529910, 0.554520, 0.440590,
-1.589400, 0.235040, 7.441870, 2.137350, -1.128250, 0.447270, -0.205520, -2.014000, 1.103550, 4.026700,
0.021410, -1.306770, 0.371220, 0.061900, 3.207930, -0.431330, -0.440860, -4.159860, 0.300010, 1.254180,
-0.833480, 0.548660, -1.173310, -2.818690, -0.531310, 2.541340, 0.932360, 0.612250, 0.067390, 0.998130,
0.194740, -0.977470, 2.098550, 0.576820, -1.308790, 0.881690, -0.311930, -0.080740, -0.699500, 0.437330,
-1.196320, -1.115890, 0.907790, -0.564930, -0.108180, -0.702080, 0.976270, 0.268400, -2.172390, 2.330610,
-0.081900, 0.597020, 0.269080, -0.581260, 0.195030, 0.067040, -0.438810, -1.490440, 0.183410, -0.024820,
-0.548300, -1.742390, 0.401400, -0.338500, -0.725430, -0.568890, 0.759170, -0.354790, -0.238900, -0.999680,
-0.307160, 0.096890, 0.394420, -0.143230, -0.264320, -0.702910, -1.505690, -0.923970, 0.547330, -0.303410,
2.494500, 1.038090, -0.145710, 0.548230, 0.925320, -1.627950, -2.887360, 0.872120, -1.387210, -0.412730,
0.010820, 0.785570, -0.414640, -2.642380, 0.608360, -0.279970, -0.634210, -1.353360, -2.159430, 2.208610,
-0.366370, -1.097720, -0.630690, 0.888340, 2.351000, 0.807810, -1.214480, 0.745070, -0.586680, 0.380630,
0.450540, 0.404140, 0.589500, -1.318360, -0.177030, 0.524550, 0.976570, -0.146270, -0.874660, -0.386330,
-2.919610, 0.052600, 0.480740, -0.777610, 0.609330, -0.746170, 0.458970, 0.207540, 0.286620, -0.124860,
0.543440, 0.285520, -0.014450, -0.790750, 0.435510, 0.499140, -0.322290, 0.296620,
-1.039610, 0.962730, 0.162010, -1.319590, -0.267550, 0.422450, 0.759670, 0.469560, 0.281680, -0.833800,
0.697960, 0.611250, 1.071220, 1.013570, -0.956660, -0.697430, -0.141500, -2.758820, -0.596990, 0.542820,
0.274440, -0.070380, 0.047140, -0.262520, -1.811590, -0.728410, 1.389620, -1.389120, 1.809290, -0.422900,
-1.196120, -0.115820, -0.499870, -2.341280, 1.662690, -0.799140, -0.268870, 0.198370, -1.682080, 0.775800,
-1.248450, 0.765430, 3.344730, -1.034440, -1.296110, 0.325020, 0.248650, 1.440010, 0.132030, 1.557720,
-1.436970, 0.752760, -1.459620, -0.843910, -3.108710, -1.225600, -1.823080, -0.900150, 0.987470, -1.463280,
-0.735240, -0.044460, 0.585180, -2.732540, 0.770450, -1.653010, 0.009130, -1.030490, 0.350650, 0.334110,
-0.097010, 3.054050, 0.446210, -4.130550, 0.775560, 0.537110, -1.161030, -1.391030, 0.129250, -2.899930,
0.548900, 0.601560, -1.271250, 0.194870, -0.929960, 1.002490, -2.890830, 1.091730, 1.790530, 0.072680,
-0.411690, -0.835030, 0.130190, 0.311080, -1.907590, -2.121170, -0.611210, 1.298700, -0.480540, -1.428530,
0.760600, -0.087610, -0.741970, -1.285600, 0.593150, -2.206260, -0.969330, -1.409330, -0.900820, -2.922580,
2.597370, 2.761700, 0.267850, -0.112020, 0.491570, 0.141090, 2.719770, -1.967370, 0.689280, -1.271610,
2.752780, -0.729370, 0.374890, 0.268230, 1.266220, -4.696940, -0.494620, 0.435040, -1.534010, -1.339470,
1.018770, -0.035240, 0.258740, 2.299860, 2.379550, -1.007630, -0.027450, -0.339190, -0.486710, -2.472600,
1.370440, 3.980690, 0.415550, -0.585450, -1.281320, 0.554120, 0.934250, 1.358370, -4.399690, -0.173680,
0.591110, 0.839900, -1.190190, -0.812410, 0.373470, -0.024520, 1.860030, 1.638920, 0.047600, 0.564190,
0.573230, -0.462480, -1.952560, -0.091180, 4.178080, 0.609290, -0.811540, 0.946350, -0.221130, 1.069930,
3.028470, -4.330060, 0.921670, -3.040750, -0.815690, 0.030100, 0.416110, -0.185120, 2.261400, 4.026430,
0.619510, 0.963040, -0.307570, -0.337620, 0.989750, -3.708210, 2.160650, 5.327020, 0.650510, -0.002850,
-0.183210, -0.554010, 0.851090, -0.460550, -6.413700, 1.281700, -0.392570, -0.516400, -0.896690, -2.535730,
-0.063690, 0.694460, 2.358620, 0.971900, 0.845400, -0.212810, 0.624220, 1.153720, -2.007390, 2.850670,
5.530820, 0.567970, -0.813680, 0.171300, -0.982030, -1.696660, 0.050260, -3.442930, -0.771780, -1.192860,
1.093060, -1.999820, -0.150380, 1.592560, 1.082590, 4.569440, 0.763150, -0.299040, -0.421210, -0.052300,
0.348140, -1.906190, 2.362590, 3.695360, -1.185790, -1.484000, -0.065280, -0.611840, -4.165590, -0.202110,
-4.416720, -0.894170, 1.854840, -2.035690, -1.425090, -1.633040, -0.276610, -0.124390, 4.205850, 4.749250,
0.576290, -0.093960, -1.634690, 2.033660, 1.130540, -1.101000, 0.569130, 2.092740, 0.097160, 1.375430,
-1.528470, -1.114790, -0.863280, -0.239250, 2.141680, 1.507700, -1.497200, -1.611290, 0.072390, 1.969180,
-0.168820, 0.924090, -1.672920, -1.307130, 0.890790, -0.752820, 1.009210, 0.235700, 0.206570, -1.014100,
3.022030, -1.115200, 0.572440, 1.397850, 0.201200, 0.036190, -0.166920, -0.175110, 0.562530, -0.855870,
-0.994370, -1.016920, -0.735610, 0.307600, -0.892600, -0.533330, -0.743650, -0.759120,
-1.348780, -0.832580, 0.887070, 0.852690, 1.498010, 0.384810, -0.450230, 0.254990, -1.101420, -0.603800,
-0.693440, -0.542010, -0.403560, -0.758760, -1.298520, 2.521260, -0.301440, -0.515570, -0.603020, -1.088580,
-2.274450, 0.907330, -1.201500, 1.104110, -1.003730, 0.387280, 2.464400, -1.910130, -1.145290, 0.198430,
-1.662810, 0.274660, 0.049010, -3.664620, -0.348220, 0.347310, -1.069100, 0.543910, 0.490250, 0.932550,
0.792680, 1.216050, -0.550740, -0.981090, 0.564080, 0.233800, 1.272600, 1.806330, -0.626720, 2.023760,
0.307310, 0.788830, -1.006980, -1.442690, -1.284800, 1.470490, -1.188930, 0.827690, 0.361440, -1.787160,
-0.192090, -0.354570, 0.600850, 0.713420, 0.019480, 1.739140, -0.074030, -1.140260, 0.197140, -0.274750,
0.901620, -0.478290, 0.299660, -0.313980, 0.653240, -1.011850, -0.123290, 1.898730, 0.800250, -2.656040,
0.698870, -1.204540, 2.377370, 0.903460, -0.839010, 0.613810, 1.966820, 0.903380, -0.256150, 1.936520,
-0.593030, 2.657440, 0.915090, 1.046130, -0.900310, 0.684850, 0.749770, 0.755100, -0.744990, -0.737720,
2.279680, 0.757280, -1.784880, 0.390610, -0.026480, 3.534790, 0.033660, 0.160840, 0.018610, 2.949460,
-0.347890, -1.416660, 2.319030, 0.163450, -0.328600, 0.983160, -3.973020, 0.095730, -0.617760, 0.056090,
-0.942990, 0.094810, -0.761330, 0.635580, 0.017210, 0.068830, -0.457600, -1.414910, 4.261170, 0.654190,
1.094890, -1.599950, 1.511010, 0.952530, 0.020160, 1.005440, -0.564060, -1.521460, 0.231030, -0.498250,
1.242620, -2.156680, -0.330930, 1.955560, 0.491090, -3.040220, -0.863240, -2.286890, -0.481840, -0.673510,
-2.525850, 3.204470, -0.050360, -2.368160, -1.434810, 0.688630, -0.389300, 1.615250, 0.089590, 0.751120,
-0.802290, -0.270880, 4.217400, -0.655990, -3.736760, -0.603530, -1.384810, 1.297700, 0.966290, 0.019160,
-3.326040, 0.049770, -0.338220, 1.916140, 0.967610, 0.137060, 0.536060, -0.094750, -0.025070, -1.448820,
2.275830, -1.201420, 0.333580, -0.826230, -0.215800, 2.341650, -0.865120, -3.292210, -2.298020, 0.138490,
-0.715820, 1.045050, -2.331890, -0.141500, 2.311560, 0.080360, 0.655640, 1.070570, -1.064230, -0.192940,
1.752530, 0.595900, 0.452290, -1.418570, 0.912630, -1.388840, 0.129380, -0.937990, -0.238310, 0.711890,
-1.521330, -0.673560, -0.268610, -0.143740, 0.063670, -0.580370, -1.006870, 0.368300, 0.117020, -0.881190,
-0.356620, 0.793930, -0.748000, 0.353560, -1.059480, 0.005060, -0.083600, -0.564930, -0.847050, -0.366730,
0.410490, 2.532500, 0.129220, -2.638130, -1.674790, 1.020530, 1.068260, -0.616190, 0.683360, 1.682600,
2.758190, 1.297480, -0.170650, -0.642460, -1.379320, -0.388650, 0.312390, -0.165810, -0.092780, -0.489160,
-0.532530, -0.939680, 1.035310, 1.718810, -2.160800, -1.524310, -1.870930, -0.226390, 0.115750, 2.001180,
1.705450, -0.083990, 0.571180, 1.647110, 3.873340, 0.963680, -1.128180, -1.280400, -0.949320, -0.373440,
-0.029140, -0.420130, -1.339820, -0.002480, -0.812420, -0.897350, -1.508390, -0.923860, -0.163150, -0.298700,
-3.354710, -0.509270, 0.049380, -0.325640, 0.292340, -0.629780, -0.905670, -1.129910, -0.305240, 0.411430,
-0.904570, 0.136360, -1.706290, -2.968750, 0.323590, -0.864650, -0.887640, -0.260340,
0.497690, -1.733540, 0.957510, 2.100050, -1.118990, 0.229650, 0.375120, 0.182070, -0.023490, -1.570360,
0.695070, 0.161170, -0.412860, 0.694180, 0.012770, -0.425770, 0.066740, -0.555510, 0.402940, 0.478010,
-0.200350, -0.273140, 1.538080, 0.002850, 0.307170, 0.489350, 0.034390, -0.901530, 1.047080, -0.871380,
0.554980, -0.903120, -0.289540, 1.494600, -0.491730, 0.223960, 0.645310, -0.109230, 0.058370, 1.052780,
0.393860, 0.064510, 0.765620, -0.146530, -0.558650, 0.101610, -2.216310, -1.655930, 0.212440, 0.639870,
1.468580, -1.056530, 1.261710, -0.449970, 0.606160, 1.024960, 0.495320, 0.891500, -0.237400, -1.458460,
-1.124070, 0.093030, 0.574710, -2.452090, 0.571800, -0.110960, -0.174470, -1.142510, -1.897850, -0.661830,
-0.706810, -0.268600, 0.719970, -1.336740, -2.347810, 1.587260, -1.890810, -1.955350, 0.479870, -0.408510,
-1.081670, 0.274220, -1.992110, -1.064640, 0.507160, 0.135700, 0.068000, 1.933710, -0.363980, -0.496960,
0.786170, 0.546970, 0.591890, -0.244510, -0.047100, 0.214350, 0.980170, -0.410890, 0.744700, -0.662740,
-0.027380, -0.615390, -1.351480, 0.257090, 0.517110, -1.501780, -1.098910, 0.538870, -0.208210, 0.135850,
2.731140, 0.442120, -0.358200, 0.037430, 1.561610, 1.080500, -0.124980, 0.867250, -1.239560, 1.174650,
0.667380, 1.613110, 1.019240, 0.708650, -0.652700, -0.579190, 0.719790, 1.683380, -0.272410, -0.393330,
0.837750, 0.109590, 0.469170, 0.267750, -0.265630, -0.204510, -0.890880, -0.262400, 1.420080, 3.555030,
-0.709100, -0.660380, -0.258950, -0.196710, 0.073200, -0.014680, 2.646410, -1.402460, -2.803710, -0.238710,
-0.023450, 0.546670, 0.863930, 0.326750, -1.109880, -0.666700, 0.186770, -0.285470, 0.793500, 1.992470,
-0.886510, 0.743460, 1.432860, -1.336630, -0.992250, 0.148920, -0.778450, -0.638690, -0.187800, -0.602930,
-1.207200, -0.484570, 0.370710, 1.578100, 0.511330, -0.375090, -1.485070, 0.040470, 1.874320, 2.264300,
0.306110, -2.031300, 3.273950, 0.965580, 0.821190, -0.522260, -0.857680, -0.063070, -0.956230, 0.038070,
0.052210, -0.235060, -0.443720, 0.158770, -0.384990, 0.895010, -0.061260, 0.847490, 0.279280, -0.332230,
0.578200, -0.167010, 0.205050, -0.953970, -0.366880, 0.661910, -0.491500, -1.838440, -0.331760, -0.233100,
-0.245210, -0.889620, 0.649030, -1.906660, -0.339390, -1.922040, -0.688770, 0.023650, -0.608450, 0.802370,
-0.004060, 0.621210, 0.685810, 0.460990, 0.602620, -0.921660, 0.119980, 0.052890, 0.054150, -2.472110,
0.442500, -1.428310, -1.410490, 0.590030, -1.472760, -1.664370, 0.248120, 0.526530, -2.652470, 1.326310,
-2.380840, 0.057210, 0.413110, -1.267190, 0.137240, -0.466990, 2.621650, -0.037840, 0.231990, -0.296600,
-0.769540, -1.576430, 2.155400, -1.634140, 1.175130, -0.041330, 1.085180, -0.129690, 0.146100, 0.194020,
-0.222810, 0.269510, 0.319070, 1.658410, -0.768200, -0.439250, 0.069690, 0.005970, -2.724150, 0.458360,
-0.690120, -1.742880, 0.309450, -0.741540, -0.436570, 2.213190, 0.740980, -1.615020, -1.434950, -0.248170,
-2.003830, -1.109840, -1.239600, 2.566910, -0.077650, 0.446460, -1.091910, 1.351280, -1.477050, 0.062340,
-0.173770, 0.418420, 0.561550, 0.166390, 0.138830, -0.139760, -0.170050, 0.024400,
0.586020, -0.628880, 1.288370, 0.181390, 0.359830, -0.644080, 0.856340, -0.552920, 3.025910, 0.115050,
0.545940, 0.306870, 0.768110, -1.340200, 2.118560, -0.078240, -0.357330, -0.378240, -1.946400, -0.076700,
0.657430, 0.048740, 2.407410, -0.538310, 0.327590, -0.228480, 0.081340, 0.566600, -0.407980, -0.723030,
-0.713090, -0.515420, -0.929660, -0.886420, -0.028830, 12.215380, 0.840950, 0.950740, -1.148640, -0.198770,
-0.288760, 0.837630, -0.287960, 0.081200, 0.019480, 0.002240, 0.473690, -0.429960, 0.016970, -0.212980,
-0.744370, 0.745410, -0.035520, 0.803580, 0.414540, 0.353220, 0.833270, 0.599360, 0.493800, 1.985750,

2.215730, -0.848310, -1.057250, -0.525290, 0.919220, 0.601310, 0.112050, -0.096530, -0.454460, -0.635860,
-0.707180, -0.508350, 1.220140, -0.288120, -0.707940, 0.751940, 0.412480, -1.278100, -3.610390, -1.068280,
-0.722000, -0.136930, -0.351330, 0.573170, 0.150940, 0.708450, 0.153700, -0.058870, -0.843550, 0.231750,
0.179940, -0.735200, 1.270790, -1.308450, -0.544260, 0.958770, 0.916100, 0.906440, 3.428430, 0.801960,
0.121800, -0.545190, 0.822930, 0.636360, -0.805480, 0.559290, -0.833550, 0.029160, -0.264150, -0.413800,
0.994930, 1.756700, -0.202280, -0.032070, -0.436040, 0.582830, 0.399070, 0.317800, -0.653110, -2.511300,

-0.146800, 1.236840, -1.469360, -0.056180, -0.193580, -0.117100, 0.319400, 0.240820, -0.203700, -0.345000,
0.485390, 1.503740, 0.590540, -0.585350, -0.957340, -0.310270, 0.481650, -2.174050, -1.078200, 0.030480,
-0.217160, -0.217960, -0.158730, -0.093110, -0.638110, 0.344380, -1.084680, -0.601980, -1.681720, -1.688750,
-0.619720, 0.746060, 0.289960, -2.345800, -0.062150, -0.442940, 0.721410, 0.478160, 1.709450, 0.759900,
0.204330, -0.326760, -0.935090, 0.678660, 0.553670, 0.012290, 0.617000, 0.502280, -1.809520, -1.761260,
0.224580, -1.171420, -1.222370, 0.055610, -0.033270, 0.466460, 0.085140, -0.156600, -0.728730, -2.571790,

-0.944220, 0.827320, 0.772380, -0.218950, 0.570630, -0.698320, 0.111220, -0.061320, 0.428220, -0.911800,
0.332660, 0.130370, 0.962820, -0.103350, -0.868620, -0.805040, -0.231740, -0.326790, -1.900140, 0.356410,
-0.813520, -0.921380, 0.259200, -0.384410, -0.284610, -0.447090, 0.545000, 0.171830, -0.217130, 0.924010,
-0.585370, 0.673820, 0.592390, 0.213320, 0.085620, 0.342980, -1.016660, 1.252970, 0.263850, -0.935060,
0.261300, 0.025370, -0.556220, -0.057110, -0.282210, -0.584540, 0.432180, -0.286890, -0.509180, 0.533310,
-0.799480, -0.458930, -0.535410, 0.128050, -0.552890, -0.821420, 0.840860, -0.471580, 0.945740, -0.718350,

-0.696530, 0.322880, 0.531410, 0.242310, 0.158400, -0.477510, 0.111080, 0.381370, 0.611310, -0.939960,
0.339590, 0.351660, 0.711700, -0.567370, 0.651640, 0.147000, 0.254800, 0.747790, -0.531410, 0.171110,
0.283980, 0.713830, 0.345490, 0.676460, 0.459710, 0.123290, -0.453970, -0.348060, -1.133820, -0.959350,
0.366020, -1.281130, 0.286650, -3.223050, -0.756930, 0.095230, 0.819200, 0.308790, -1.049570, -0.563350,
-0.529920, 0.568170, -1.511540, 1.174420, 0.805600, -0.789120, -0.847040, -0.659150, 0.124040, 2.411380,
-0.840380, -0.528280, -0.706800, 0.110300, -0.243820, -0.894730, 0.846170, 0.500100, 0.791400, -0.794420,

-1.046380, -1.222950, -0.667970, -0.648180, 0.641790, 0.805170, 0.512360, -1.175060, -0.095320, -0.523860,
0.070240, -0.091160, 0.457850, 1.498980, 0.640530, -0.918350, -1.679590, -1.720910, 0.618510, -1.837590,
-0.435140, -0.128010, -0.741280, -0.919960, -0.050870, -0.573590, -2.294650, 0.310390, 1.213470, 0.232180,
0.517360, -0.318430, 0.888250, 1.366160, 0.278820, 2.479930, 0.415510, -0.952490, 2.527530, 1.189160,
-0.482510, -1.742910, 0.591060, -2.833560, -1.075340, -0.313690, -0.373260, -0.659750, -0.011540, -0.410730,
0.630870, 0.561880, 1.919940, 0.548240, -1.123220, 0.581530, -0.535390, -0.621660, -0.435020, -1.701340,

0.537490, 0.912950, 0.227880, -0.408400, -0.857540, -1.549180, -0.339930, 0.298160, 1.083630, -0.459280,
1.039890, 0.786140, 0.995490, -0.045230, -0.576160, 0.936330, 0.222850, 0.835850, -0.360250, 0.434880,
-0.842660, -0.565370, -0.464510, -0.484880, 0.386510, 0.654750, 0.659360, 0.200930, -0.716400, 0.407970,
0.606020, -0.107140, 0.990630, 1.019240, 0.171020, 1.673530, 0.749010, -1.114050, 0.257390, -0.984470,
0.364460, -0.857880, 0.516020, 2.194120, 0.493220, 1.894400, 0.593430, 0.140680, -1.229890, -0.224760,
0.303400, -0.371290, -0.688210, 0.257910, 0.151310, 0.541400, -0.320240, -0.518070, -0.460290, -1.386790,

-0.311030, 0.132290, -0.987660, 0.223810, -1.102310, -0.123860, -0.840940, -0.869740, 0.594510, -0.823290,
1.012640, 0.651070, 0.900990, -0.296210, -0.474330, -0.997100, -0.071530, 0.182750, 0.438250, 0.200020,
-0.141080, 0.326080, -0.366240, -0.873010, -0.088020, 0.869820, -0.951960, 0.675400, -0.333270, -0.149260,
0.589000, 0.670980, 0.769310, 0.719500, 0.686540, -0.269200, -1.134690, 0.401690, -0.747570, -0.667660,
-0.927460, 0.446390, -0.225720, -0.135190, -0.524080, -0.383640, 0.174240, -0.481260, -0.791890, 0.236590,
-0.673650, 2.671930, -0.027460, -0.499140, 0.822900, 0.582150, 0.435040, -0.354220, -0.550660, -1.500270,

0.562690, -0.567160, -0.145800, -1.116680, -0.849520, 1.312730, 0.607680, -1.122780, -1.985700, 0.604990,
-2.592020, -1.761760, -0.625770, 1.649170, -0.179520, -0.580300, -0.023100, -0.507580, 0.536640, -0.338380,
-0.675380, 0.171980, -0.264680, 1.176840, -0.452610, 1.301880, 2.179960, -0.923450, 0.220760, -1.657420,
-0.164080, 0.707700, -0.084400, -0.004220, 0.739960, -0.549240, -0.938750, 0.166350, -0.626780, 0.016940,
-0.021200, -0.708120, 0.057290, -2.006030, -0.479010, 0.316010, -0.214000, 0.260600, 0.555260, 0.113740,
-0.233370, 0.398350, -1.248000, 1.029620, -0.213600, -0.453370, -0.063330, -0.578980, -0.472970, 1.548060,

-0.592060, 0.671880, 1.947450, 1.469080, 0.335770, 0.085520, 0.144440, -0.328490, 2.605260, 0.412640,
0.655710, 0.860780, 0.436100, -0.275010, -0.182900, 0.148580, 0.897630, 0.058730, -0.600000, -1.658150,
0.313250, -1.366700, -0.676630, 0.542630, -0.429970, 0.568210, -0.092160, 1.832440, -0.765740, -0.300000,
-0.077500, -1.045210, 0.101200, -0.148330, -1.039580, -0.639130, -0.656820, 0.670360, 0.494750, 0.609430,
0.383370, -0.694520, -0.769240, -0.659470, -0.185370, 0.314970, 0.489810, -0.499570, -3.226630, -0.831160,
0.039430, -0.108790, 0.434730, -0.653030, -0.394040, -0.025770, -1.258190, -0.185610, 0.335600, 0.415080,

-1.008770, -0.740740, -0.675040, 0.403430, -0.530800, 0.669530, -0.745950, 0.010250, -0.789100, 1.011070,
-1.629960, -0.526430, -0.783320, 0.547230, 0.562040, -1.676410, -1.054400, -0.095740, -1.045660, -0.854320,
-0.340520, -0.128260, 0.204080, -0.667370, -0.787740, 0.448640, 0.451380, -0.680540, -0.510010, -0.480800,
0.066200, 0.850500, -0.541530, -1.117730, 0.001100, 2.638290, 0.551200, -1.358400, 2.425840, 1.469690,
0.133460, 0.426350, 0.095570, -0.578020, -1.051970, -0.814480, -0.681110, 0.599580, 1.270490, 0.094140,
-0.202820, -0.099370, -0.584760, 0.299650, 0.457730, 0.478140, 0.140560, -0.508520, 0.683960, 0.964530,

0.505070, -0.107300, 0.524610, -0.116940, 0.340680, -0.948390, 0.929570, 0.945120, 0.965580, -1.010310,
0.327050, 0.550690, 0.571730, -1.124780, -0.600090, 0.090790, -0.035170, 0.907300, -0.261820, -0.193350,
-0.695410, 0.378260, 0.481900, -0.173780, -0.233440, 0.423890, -0.302040, 0.015470, -0.656900, 0.147920,
-0.228500, -0.771880, -0.490530, -0.143040, -0.859890, 1.035010, 0.862140, 1.549870, -1.942620, -0.862000,
-0.207050, 0.548900, 1.025010, 0.976360, -0.355680, 1.237930, -1.190070, -0.169580, 0.385050, -1.041890,
-0.939490, -0.196860, 1.003950, -0.148650, -0.133030, 0.460670, -0.265290, -0.469360, 0.532680, -0.368930,

-0.046850, -0.220860, 0.424800, -1.048720, -1.547980, -5.032280, 0.436440, -0.285890, 0.713410, -0.534120,
-0.902030, 0.249010, 2.058500, 0.662800, -0.739660, 0.907580, 0.122100, 0.447910, 0.523050, 0.698880,
-1.652990, 0.365130, -1.573530, 0.263750, -0.197760, -0.842140, -0.524930, 0.634270, -0.937340, -1.131020,
0.200390, -0.682520, -0.983160, -1.244410, -0.470490, 0.106170, -0.917520, -0.808080, -1.661060, -0.266880,
0.241450, -0.089670, 0.165520, -0.542710, -0.020080, 0.734080, -0.906890, -0.074920, 0.874280, 0.667180,
0.643600, 1.846930, -0.363600, -0.129610, 0.254840, -0.080990, -0.549320, 0.501460, 0.785490, 0.121310,

-0.212780, 0.403290, 0.404750, 0.369440, -0.790760, 0.188280, 0.802920, -0.123740, -0.140450, 0.134450,
0.552890, -0.169070, 0.399210, -0.864050, -0.243900, 0.657420, 0.865600, -0.396090, -0.831790, 0.688970,
-0.136640, -0.226040, -0.093170, 0.551390, 0.627210, 0.768840, -1.730940, 0.428290, -1.801490, 0.573520,
0.597890, 0.531330, 1.519420, -1.326520, 0.184730, -3.875080, -0.660840, -0.052030, -2.638010, -0.972600,
-0.212270, 0.703950, 0.490230, -0.277190, -0.964530, -0.078180, -0.687480, 0.526380, -1.682470, 0.130770,
-1.081950, 0.114000, -1.481780, 0.403020, 0.198320, -0.259590, 0.250500, -0.365820, 0.557510, -2.316070,

0.490760, -0.120690, 0.632660, 0.005650, 0.385260, -0.369310, 0.092340, -0.611730, -0.073990, -0.490210,
0.397460, -0.039570, -0.533020, -0.575340, 0.509890, 0.389870, 0.320770, 0.224220, -0.247350, 0.460560,
0.452060, -0.039880, 0.218540, 0.384920, -0.142800, 0.236230, 0.222670, 0.183290, 0.031200, 0.622090,
-0.171940, 0.961990, 0.058010, 0.110360, -0.693960, -0.186030, -0.957720, -0.171760, 1.607200, -0.667190,
0.936840, 0.310150, 1.087840, 0.217770, -0.824710, 0.263500, -0.477140, -0.617510, 0.043290, 0.193500,
-0.011270, -2.708490, -0.331710, 0.679380, 0.764910, 0.260670, 0.027690, -0.443670, 0.820860, -1.145390,

0.174380, 0.459660, 0.784620, -0.987900, -0.129160, 0.068440, -0.756110, -0.401040, 0.681570, -0.611250,
0.647340, -0.263220, 1.331110, 0.393830, -1.002560, 0.822700, 0.470130, 0.022130, -0.786820, -0.078000,
0.261740, -0.986410, 0.000570, -1.085200, 0.561410, 0.204710, -0.088230, -0.338650, -0.112290, -0.805510,
0.804280, 0.851810, 0.076610, -1.735870, 0.140130, -0.989060, -0.807400, 0.735750, -2.619690, 0.360210,
-2.716540, 0.188280, 1.833980, 0.580130, -0.734390, 0.235550, 0.633500, -0.126770, 0.178290, -0.217810,
0.728780, 0.302950, -1.048630, -0.376970, -0.692640, 0.583860, 0.775550, -0.186960, -1.087970, -2.631200,

0.872540, -1.145100, -0.921080, 0.097180, 0.670280, 0.331300, -0.754190, -0.387600, -2.087550, 0.796960,
0.147610, -0.614330, -2.160290, 0.362660, 0.998770, -1.077310, -0.928780, -1.523710, 2.013760, 0.769480,
0.934440, -0.116860, 0.499750, -0.398810, -0.859680, -1.061350, -0.173850, 0.263800, 0.443540, -0.854440,
-0.452140, 0.300640, 0.639290, -0.167010, 0.761830, 3.961130, -0.579760, -1.647950, 3.367370, 1.438480,
3.603980, 0.780210, -1.877260, -1.194810, 0.366750, -1.444070, -0.171900, -0.167170, 0.268630, 0.692240,
-0.794980, -1.695120, -0.406960, -0.026930, 0.417800, 0.557000, 0.238480, -0.214330, 0.779950, 4.412760,

-0.363100, 0.332700, -0.798630, -0.555740, -0.535330, -0.160730, -0.814180, 0.421700, 0.988240, -0.186490,
-0.063220, 0.302310, 0.529400, -0.155820, -1.102970, 0.206770, -0.589780, -0.419380, -0.771550, -1.029380,
0.097290, 0.517130, -0.678990, -0.176500, 0.283310, -0.074400, 0.002080, 0.569320, 0.039890, -0.535510,
0.151210, -0.362190, 0.569330, -1.160610, 0.197540, -0.760850, 0.471980, 0.037080, -0.166430, 0.078150,
-0.132580, 0.729540, -0.958820, -4.648560, 0.832440, -1.481880, -0.676380, -1.438590, -0.915090, -0.058960,
0.164190, 8.101620, -0.121910, 0.541380, -0.078820, -0.680900, -0.513060, -0.460830, 0.444750, -1.440190,

-0.181380, -0.068390, -0.095560, -0.189470, 0.601180, 0.200930, -1.029170, 0.092990, -0.277260, -0.597160,
0.063610, -0.294740, -0.821990, -0.636280, 0.426110, 0.376190, -0.826930, -0.232040, 0.579290, -0.250410,
-0.265240, -0.841600, 0.390410, 0.024380, -0.775780, 0.368840, 1.340300, -0.476940, -0.082040, 0.619550,
-0.533480, 0.236650, 0.441500, 0.668810, 0.043390, -0.490230, 0.212030, -0.616160, 0.105700, -0.289070,
-0.292820, -2.700760, -2.263460, -6.543770, 0.423650, -0.903930, 1.046200, 0.255410, 1.182300, -0.418600,
-0.117280, -0.799360, -0.568020, 0.069710, -0.283030, -0.119820, -0.172090, -0.867300, 0.397530, 0.750580,

0.570180, 0.373390, -0.463460, -0.179610, -0.990840, -1.972700, -1.970420, -0.565410, -0.756340, 0.011230,
0.407390, -0.683540, -2.752580, 0.720940, 0.175680, 0.089330, 0.884230, -0.322070, 0.260170, 0.444800,
0.717950, -0.034080, 0.550670, -1.441820, 0.037340, -0.359450, 0.064830, 0.435770, -0.174250, -0.428500,
0.409880, -1.897190, 0.308580, 0.098830, 0.524780, -1.099610, 0.176200, 0.025560, -0.490450, 1.574780,
-0.610120, -0.580520, -1.830980, 0.273440, -0.254800, -1.203380, 0.406500, -0.884730, 1.487360, -0.579060,
0.491440, -0.071790, 1.682330, -0.669920, 0.748340, -0.355760, 0.654250, 0.660450, -0.922870, 0.036100,

0.438260, 0.382500, -0.785190, -0.113490, 0.147010, -1.902630, 0.235050, 0.809640, 0.676400, -0.174530,
0.678480, -0.317540, -1.306110, -0.458310, 0.080400, -0.562350, -0.899490, 0.829340, 0.598590, -0.624290,
-0.243710, 0.313540, -0.478360, -0.029590, 0.615280, -0.135260, 1.776730, 0.246660, -0.470760, -0.355000,
-0.164090, -0.485620, 0.145190, 0.136490, 0.257580, 2.655270, -0.309730, 0.359600, 9.939790, 0.193360,
0.550170, -0.482790, 1.306620, 0.544350, 0.961740, 0.662180, 0.355050, -0.805100, -1.154820, -0.366210,
0.794340, -0.692330, -0.508660, 0.948930, -0.457290, 0.668690, 0.748010, 0.908450, 0.669740, 0.203990,

0.288400, 0.154320, -0.663800, -0.215880, -1.045270, 0.562920, -0.232620, 0.067950, 0.177300, 0.660640,
0.468250, 0.781680, 0.218900, -0.543440, -0.681100, 0.026460, 0.367030, 0.233660, 0.369510, 0.585780,
-0.666200, -0.398870, -0.696990, -0.169320, -0.503380, -0.005480, 0.152220, 0.669790, -0.653960, 0.328760,
0.937590, -0.467520, -0.650380, 2.096320, -0.923340, -0.077840, -0.078890, -0.740230, 0.167330, 0.227730,
-0.176810, 0.515000, -0.094860, -0.230710, -0.377200, -0.231960, 0.352130, -0.896260, -0.532550, 0.041080,
-0.338770, -4.965290, 1.453380, -0.662720, -0.334810, -0.668580, -0.795380, 0.738990, -0.764830, -0.874940,

-2.263760, -1.196960, 0.425900, 0.474600, 0.372380, 0.371330, -0.766890, 0.759910, 0.009610, -0.507270,
0.650450, 0.370030, -1.446290, -1.225650, -0.753330, 0.896110, -0.397490, -1.246760, 0.965650, -0.305220,
0.846120, 0.177790, -0.713410, -1.236920, -2.130310, -0.529840, -0.102290, -0.402580, 0.977180, 1.223500,
-0.220840, 0.633350, -0.389690, 0.181610, 0.229650, -0.097920, -0.853580, 0.640350, -0.149240, 1.366080,
-0.480370, 0.771240, 0.951910, 1.347360, -0.332010, -0.241060, -0.742360, -2.086900, 1.006570, -0.076600,
-0.416140, -0.232070, 1.558680, -0.607290, 0.928960, -0.594130, 0.549520, 0.190960, -0.589940, 0.520300,

0.195530, -0.952710, -0.243470, 0.375540, -0.373420, 0.857830, 0.320900, -0.900790, -0.288180, -0.482880,
-0.808740, -1.138110, -0.394600, -0.323790, 0.302900, -0.224670, 0.659570, -0.598490, 0.096090, 0.020780,
0.755470, 0.403310, 0.168390, 0.828300, 0.725880, -0.646950, 0.073440, -0.016140, -0.053790, -0.316630,
0.730630, -0.317370, 0.851520, -0.681100, -0.453520, -1.616070, -0.893570, -0.433580, 1.677990, 0.025270,
0.738660, 1.075290, -0.805190, -0.642310, 0.747550, -0.425670, -0.164130, 0.745200, -1.059650, 0.866630,
0.465620, 0.385600, 0.073120, 0.474810, -0.709850, -0.230140, -0.574370, 0.069080, -0.826640, 1.478380,

0.678670, 1.426360, -0.706290, 0.396790, -0.053680, -0.190440, -0.897200, 0.250790, 1.512800, 0.315140,
-0.291120, 0.277770, 1.248680, -0.046970, -0.854110, 0.292280, 0.114850, -0.059140, -0.425160, 0.398100,
-0.839030, 0.162510, 0.417660, -0.797290, 0.425380, -0.569720, 0.693530, 0.602980, -0.477640, -0.505360,
-0.088820, 0.045800, 0.695820, -0.632900, -0.048070, -0.312360, -0.534770, 0.864390, -1.519960, 0.292000,
-0.495880, 0.414450, 3.050640, 0.606880, 0.176230, 0.610920, -0.485770, -0.272240, -1.193110, -0.519090,
0.744980, -0.716560, 0.615020, 0.459300, -0.459250, 0.803500, -0.185860, 0.069000, -0.670590, -0.504980,

0.086890, 0.826540, -0.609900, 0.478690, 0.681780, 0.684830, 0.378740, 0.489710, 0.644940, -0.189050,
-0.113040, -0.707210, -0.560680, -1.107920, 0.002560, 1.358290, 0.479250, 0.681790, -0.469260, -0.115920,
0.697770, 0.520340, -0.188480, 0.333980, 0.655100, -0.298130, -0.015560, -0.061300, -0.169220, -0.166080,
-0.199840, 0.097220, 0.785940, -1.496040, -0.108300, -0.384140, -0.960490, 0.317170, 1.554360, -0.436210,
0.174600, 0.648780, 0.673950, 0.632170, 0.057050, 0.807450, 0.228060, -0.360560, -1.365090, -0.294690,
-0.316080, 0.122080, -0.967610, 0.434560, 0.388700, -0.859440, -0.848340, -0.385800, 0.409380, 0.139840,

-0.569510, 0.926620, 0.672810, 0.640290, -0.167620, -0.452420, -0.783390, 0.592160, 0.921100, 0.409240,
0.145120, 1.250080, 0.385470, -0.165860, -0.641700, 0.490220, -0.125570, 0.101700, -0.422210, 0.236600,
-0.514540, -0.005410, -0.345700, -0.225840, -0.600830, 0.719280, 0.226340, 0.887660, 0.031650, 0.858980,
0.701450, 0.595150, -0.260390, -0.571680, 0.668150, -0.602040, -0.665540, 0.884480, -0.610880, -0.243640,
-0.242990, -0.444260, 0.538650, 0.156690, 0.585500, -0.142530, -0.558610, -1.168180, -0.390010, -0.917570,
-0.517700, 0.036870, 0.536250, -0.740410, 0.196050, -1.004190, -0.445810, 0.527540, 0.103880, -1.068950,

-0.795810, -0.041250, 0.667440, -0.170010, 1.028990, 2.346560, -0.837630, 0.871040, -0.814440, -0.037420,
-0.213190, -0.094770, -0.686790, -0.277410, -0.427450, 0.146910, -0.974720, -0.660070, -0.010240, -1.160530,
0.804720, 0.240470, 0.938570, -0.138480, -0.641670, -0.441820, -0.458430, -0.807270, 0.301090, 0.403740,
-0.039660, 0.321220, -0.966690, 0.083580, -0.194400, 0.183180, 0.476090, -0.182660, -0.224600, 1.018050,
0.113890, 0.712910, -0.483200, 0.345930, -0.701900, -0.265690, 0.090690, -0.524190, 0.487480, 0.483060,
-0.266690, 0.380570, -0.048540, -0.085550, 0.792620, 0.952030, 0.664490, 0.419430, -0.577780, -1.257300,

-0.416590, 0.028020, 1.034230, 0.590340, -0.519700, -0.529360, 0.166950, 0.708980, 0.107830, 0.630510,
0.464880, 0.416800, -0.357820, 0.211170, -0.771570, -0.644270, -0.598510, -0.196840, 2.274780, 0.249450,
-0.066420, -0.144240, -0.244320, -0.626300, -0.748320, 0.018910, -0.629090, 0.282960, 0.078080, 0.262210,
-0.539390, 0.438870, -0.335670, 0.722550, 0.453060, 6.860730, 0.752130, 0.692020, 0.607900, -0.029710,
1.122550, 0.838400, -0.452120, 0.561910, 0.904590, 0.444140, 0.610080, 0.401870, 0.437460, -0.166250,
0.137520, 0.790220, 1.546200, 0.125740, -1.520040, 1.248170, -0.402190, -0.450030, -0.538680, -0.929780,

0.700400, -0.917710, -1.001420, -2.370460, -1.264910, 0.602750, 0.187980, -1.167300, -3.833410, -0.084490,
-0.782170, -0.428400, 0.076650, 0.805490, -0.161590, 0.109500, -0.646390, -0.572500, 0.600170, -0.692960,
0.626670, 0.475490, 0.877460, 0.601870, 0.403820, -1.290070, -3.890640, -1.456520, 0.980360, -0.299400,
0.668020, -0.968890, 0.484550, 1.941940, -0.297420, 0.013270, -0.764990, 0.215860, 1.133110, 1.668180,
0.621520, 0.247980, -0.082220, 0.086790, -0.637500, -0.604480, 0.470730, 0.016380, -0.139740, -0.389290,
0.458730, 0.586760, 1.274300, -0.224750, 0.135380, -0.992400, 0.429910, -0.501840, -0.195650, -0.544990,

0.806840, 0.322570, 0.505960, -1.094870, -0.287380, -2.402270, -0.116180, 0.468570, -1.552170, -1.195010,
-0.756510, 0.037390, 0.498730, 1.050540, -0.255980, 0.995480, -0.612700, -2.704430, -1.798660, -1.492180,
0.521930, -1.435460, 0.324640, -0.191410, 0.408770, 0.672010, 0.828480, -0.291590, -0.478650, -1.070880,

-0.559680, 0.718320, 0.322100, 0.580610, -0.830940, 0.892330, 0.307380, -1.932550, 0.976130, 0.468010,
0.867320, -0.443740, -0.590630, -1.538970, 0.730790, -0.784030, -0.025970, 0.685270, 0.945880, -0.765710,
0.511440, 0.607780, -0.526400, -0.273240, -0.473270, -0.286240, -0.827500, -0.437020, 0.283260, -0.075870,

0.872890, -0.665390, -0.465240, 0.300340, 0.705300, -1.466480, -0.489000, -0.053240, -0.715900, 0.284140,
-0.735810, -0.390260, -0.342160, -0.973570, -0.712520, -0.813570, 0.080200, 1.456530, -0.499750, 0.976780,
0.265540, 0.664470, -0.071800, 0.491740, -0.231620, -0.935530, 0.454190, 0.481940, -0.931540, 0.439980,

-0.041460, 0.743300, 0.710080, -0.689230, 0.561640, -3.341740, -0.681140, 0.608560, -1.889080, -0.951800,
-0.633510, -0.220250, 1.999670, 0.829430, 0.676210, 1.133010, -0.673430, 0.631420, -0.946360, -0.489130,
-0.369670, -1.964370, -0.693280, -0.570560, 0.318500, 0.884980, -0.039060, -0.542320, 0.314330, -2.029690,

-0.900190, 0.565110, 0.115370, 0.741950, -0.112400, 0.732190, 0.171710, -1.540220, 1.721330, 0.415710,
0.585920, -0.710680, -0.274820, -0.983690, 0.098520, -0.320690, 0.968890, 0.576030, 0.231650, -0.815150,
-0.723830, -0.491430, -0.604790, 0.320060, 0.080530, -0.086110, -1.127630, -0.212320, -0.403810, 0.418470,

-0.543300, -0.717420, -0.748560, 0.215580, 0.423770, -1.063920, 0.202390, -0.629060, -1.462890, 0.421720,
-0.558870, -0.279760, -1.370250, -0.693000, 0.430230, -1.272010, 0.201150, -0.093760, -0.165620, 0.573330,
-0.543020, 1.948720, 0.740010, -0.323350, 0.258040, -1.038860, -0.452730, 0.903900, 0.287510, 0.118570,

-0.528820, 0.391320, 0.692300, -1.332780, 0.160030, -1.511090, 0.534330, 0.783380, -2.327660, -0.738680,
-0.816150, 0.323660, 1.629150, 0.948430, -0.368110, 0.641430, -0.317500, -0.089610, -0.282850, -0.416340,
-0.454990, 2.145380, -1.478660, 0.180740, 0.624580, 0.001420, 0.480770, -1.138720, -0.856780, -2.157420,

-0.474960, 0.139340, 0.426760, -0.135370, -0.217130, 0.288050, 0.304160, -0.680400, 1.410560, 0.223250,
0.393240, -0.060420, -0.300940, -1.187230, -0.298880, -0.596540, 0.399330, 0.231250, -0.635260, 0.161540,
-0.715420, -1.038480, -1.009690, 0.712950, -0.460610, -0.054410, -1.175400, -0.001760, -0.686450, 1.433020,

-0.029790, -0.490870, -0.764400, 0.930180, 0.080090, -0.713910, 0.953330, -0.777460, -1.159770, 0.335170,
0.240640, 0.210190, -1.489330, -0.852160, -0.619550, -0.412540, 0.348400, -0.396650, 0.364270, 0.215960,
-0.523260, -1.682110, 1.398110, 0.355050, -0.426570, -0.245440, 0.777580, 1.162630, -0.447730, -0.661540,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.265650, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, -0.993610, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, 0.377920, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.443500, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.424470, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -1.459690, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.886540, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, 0.019260, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, -1.422200, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, 0.362810, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.105550, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.532220, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, 0.490350, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -0.201530, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 0.847830, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, -0.334290, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, 0.196730, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, -0.305120, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -1.352640, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 1.002440, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, 1.190940, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.354690, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, 1.240250, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -0.367110, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.175120, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, -1.021910, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, 0.204890, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, -0.886240, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, -0.653730, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -1.213240, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -0.967070, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, 0.808960, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, 0.733420, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.642550, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, -0.079150, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.771490, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, 0.630800, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.589150, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -0.857800, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.692740, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, 0.466150, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, 0.539850, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, -0.127230, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.728560, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, 0.594730, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, 0.517590, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.233110, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, -0.407750, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.550510, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, 0.005760, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, -0.630410, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.839130, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.219800, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.522940, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, -0.311840, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, -0.099150, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.958360, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.673680, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 1.185090, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.147980, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.967410, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.801480, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, 0.286510, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, -0.670250, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.261200, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 0.706530, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, 0.849590, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.706110, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.575450, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
0.09861, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.39417, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
1.42494, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
1.42839, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
1.42019, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
0.00302, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
0.39934, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
1.42833, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
0.03519, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
1.42848, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
1.42526, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
0.93525, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
0.00023, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
0.02888, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
1.36799, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
0.31055, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
0.03079, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
0.03916, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
1.39782, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
1.00008, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
1.42850, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.39038, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
1.42018, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
0.00022, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
0.00821, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.00096, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
0.39666, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
0.00252, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
1.39000, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
0.02757, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.42510, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
0.00695, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
0.00159, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
0.02506, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
1.38173, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.05117, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
0.35965, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
0.09685, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.00008, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.11559, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
0.02837, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
0.07751, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.00157, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
0.00204, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
0.67376, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
0.05511, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
1.38284, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.03260, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.07958, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
1.32567, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
1.39789, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
0.04812, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
1.34807, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
0.36241, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.19359, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.17831, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
1.21963, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.41775, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
1.42738, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.08166, 0.500000, 2,
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
