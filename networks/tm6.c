/*********************************************************
  tmp6_snns3.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:09:37 2004
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
1.281930, -1.804310, -0.904640, 3.061300, 1.538370, -2.295260, 0.282060, -1.145380, -0.460160, -0.443550,
0.438200, -0.456460, -1.423330, 1.548620, -1.167260, -0.934810, 0.205250, -0.704770, -2.089780, -0.375210,
-0.501880, -1.109040, 1.006830, 2.849350, -0.900450, -0.234470, 1.047040, -0.234230, 0.128450, 2.361620,
-0.072060, -0.138620, 0.083020, -0.999840, -2.310410, 0.088400, 0.114250, -1.108370, -1.306260, 0.650000,
-4.509710, -1.094520, 0.397570, -0.005030, 1.034030, 0.572510, 1.133460, -1.158070, -0.268590, -0.773690,
-0.536670, 0.109040, -1.432050, -0.898160, -0.458830, -1.422700, 1.751350, 1.178940, -0.550720, -0.793220,
1.460500, -0.476230, -0.603630, -0.913210, -1.304700, 0.850810, -0.203160, -0.948840, 0.276420, 1.280920,
-0.579160, -2.221340, 3.903330, -0.475060, 1.166860, 1.189490, 0.866260, -1.238500, -0.809940, -0.240690,
-1.654060, 2.862070, -0.651870, -0.400760, -0.344790, -0.979450, -2.463600, 2.226000, -0.073840, -3.836290,
-0.479210, 0.345790, 0.949810, 1.275400, -3.343770, 0.329430, -2.247270, 2.173040, 0.252190, 1.792500,
-3.444260, 1.825670, -1.430410, 2.164460, -1.135790, -2.791650, -0.342210, -0.996700, 0.979220, -0.134090,
0.116170, -1.738900, -0.300140, -3.356980, 1.899720, -0.013960, 4.734090, 1.298530, 2.921830, 2.813530,
0.051770, 0.186190, -1.004450, -0.744370, 4.675980, -3.051800, 0.959590, 0.400000, -0.695610, -0.751780,
-1.215810, -0.415670, -0.316710, -0.540820, -1.479050, 1.541220, -3.578940, 0.718810, 5.487160, -3.845220,
-2.759170, -1.556440, -1.801980, -0.962920, -1.005620, -4.267040, 4.145450, 0.530360, -2.589630, -0.833820,
-0.651210, 1.810010, -0.420100, -2.018630, -5.952130, -2.566490, -0.874840, -0.188450, 1.319580, -0.678630,
-1.305310, 0.123200, 1.779250, -1.641680, 3.055720, -0.398810, -1.001350, -1.852820, -1.436090, 0.471960,
-4.175140, -4.143710, 1.169810, -2.173170, 2.423650, -0.112360, -0.532280, -0.852010, -4.952850, -0.474300,
0.430050, -0.052760, 0.459630, -0.391090, 3.003200, -1.789790, -2.913170, -1.139960, -0.578200, 1.745590,
0.073190, 0.425000, -0.011160, 0.824090, -1.975850, -1.838560, 0.212990, -0.142470, -2.162620, -3.795480,
-2.054250, 1.890830, -0.321230, -1.014220, 1.758210, 0.791000, 0.487530, 4.606150, 2.022880, -2.053940,
-1.910960, -2.635080, -2.301950, -1.399020, -0.925470, -0.280460, 0.296730, -5.025230, -2.163770, 0.398010,
3.360220, 0.624040, -0.389860, -0.165010, 3.172330, -0.910240, 0.230410, -0.519980, -0.879590, -1.249500,
0.276760, -0.869960, 0.511750, 0.880020, -0.250790, -3.471590, 0.566770, -0.089790, -2.762330, -0.596050,
-3.247460, -1.061220, 0.864260, -2.291660, 1.458320, -2.134260, -0.430460, -0.584170, -1.550020, 1.339150,
-0.140890, 2.506070, -0.044120, 3.048920, 0.266200, 0.550580, 1.917700, -1.064810, -1.919530, -1.181700,
0.308260, -1.242190, 0.396510, 3.130010, -6.322640, 0.694640, 0.637960, -2.416150, 0.395160, -1.345160,
-0.876120, 0.941470, -0.029740, 0.478090, 0.504730, -0.171640, 1.464250, -0.379570, -2.920250, -0.829000,
-0.583970, 1.051600, 0.315120, -0.852300, -1.611340, -0.563150, -0.820520, 1.129760, -0.978270, 0.165690,
-0.760330, -0.084740, -0.215470, 0.357400, -1.547530, -0.986730, 0.755820, -0.904830,
-0.653860, -0.450060, -1.730860, -0.176860, 0.280830, 0.707770, -0.172250, -1.242810, 0.184930, 0.809170,
-1.426700, -0.537240, -1.502120, -0.793800, -2.537210, -0.245960, 0.365470, -2.037740, 0.509380, -0.068230,
1.322450, -8.819900, 3.110220, 0.594570, 0.181190, -0.401340, 1.210340, -1.018160, -1.496870, -3.208640,
-0.503690, 0.019690, -0.785930, 1.832990, 0.397350, 0.159300, -0.383740, -2.858830, -0.874140, 0.762990,
0.216530, -0.629770, 0.820910, 1.606880, -2.147260, 0.773950, -3.559960, 0.178470, -0.635470, 0.407220,
0.475320, 0.128880, 0.085500, -1.074580, -0.519540, -0.166670, -0.415580, 1.263920, -0.989490, -2.654940,
0.331640, 2.092820, 0.324570, -0.047430, 1.929020, 0.804090, -0.803400, 0.148570, -0.021850, 1.164000,
1.672190, 0.281250, 1.472670, 0.304720, 2.500700, 1.384900, -0.130900, -0.408200, 1.749280, -7.483630,
-2.662330, -1.213990, -4.547810, 2.102790, -4.114090, 0.220440, -1.609210, 2.416700, -2.773800, 1.837760,
-0.351440, 0.646420, 6.666450, 3.125860, 0.781600, -0.887390, -0.925360, 1.544770, 0.120970, 0.057810,
10.505360, -3.125450, -5.759140, -1.818480, 1.071110, 4.690310, 1.268010, -2.839860, -0.299210, 0.978840,
1.059340, -1.114600, 1.181240, -1.964400, -2.395620, -2.411850, 6.456890, -1.747320, -0.979860, -1.915970,
1.029050, -0.270950, 0.889650, 0.285230, -2.053600, -5.811430, -1.053310, -2.082880, 0.778790, -0.611940,
0.181160, -0.836440, -0.197110, 0.637280, 1.706270, 2.611240, 0.852850, -0.826110, -1.008140, 3.413210,
0.217890, -2.619040, -1.723070, -1.242130, 0.128300, 0.665720, -0.972850, -0.300630, -1.242850, 1.066350,
-2.335210, -2.197220, 0.578870, -2.307620, -1.525050, 1.569580, 2.151870, 0.054290, -1.044610, 2.815160,
-1.619990, 2.192040, -0.728380, 2.751930, -0.088250, 0.761700, 0.464190, -1.125390, -0.108490, -0.553160,
1.078490, -2.770470, -1.192730, -0.641190, 1.585650, 0.096050, -0.252920, -0.506550, 0.370250, -1.468360,
-2.295920, 1.897340, -2.186120, -1.040340, -0.114270, -0.520480, 1.243200, -1.548120, -2.245920, 0.297500,
1.969000, 0.845620, 0.264810, 2.388200, 0.801050, -3.938240, 1.349870, -0.856860, 0.185490, -0.022710,
-0.405640, 4.306430, -1.786900, -1.300810, -2.809320, 1.454080, -1.386880, -0.067940, 1.083580, 0.759980,
0.517700, -1.413570, -0.660080, 0.781590, -0.061890, 0.186970, -0.659780, 2.825830, -0.366620, 1.647990,
1.038640, 1.728170, 0.711170, 3.212260, 0.970360, -0.624430, 0.658980, -3.020970, 0.439660, -0.219630,
1.377140, -0.752630, 0.523400, -2.021570, 0.286530, -0.055090, -1.851550, -0.674240, -0.859200, -0.007250,
-0.448970, -1.027060, 2.182160, -2.114040, -0.700910, -0.744120, 1.605530, -1.608630, -4.890090, -0.092250,
0.685130, -0.138210, 1.814710, 1.219700, 1.017950, 2.112410, 2.310020, -0.433900, -2.580690, 8.611440,
-1.452080, -2.055940, -1.191370, 0.500710, 0.224480, 0.942990, 0.100100, -0.418580, -0.974900, 1.392630,
-0.090350, -2.562290, -0.871930, 0.166350, 0.608230, 0.903840, -2.783600, 0.765180, 0.326780, 0.644260,
0.139960, -0.597700, 0.661000, 0.998390, -0.379070, 0.152490, 1.711370, -1.433750, 2.528550, -0.091710,
-0.542540, -2.181660, -1.375290, 0.879460, -3.681870, 3.875710, -0.204250, 2.400620,
-0.426550, 0.873380, -0.563060, 0.365230, 0.680890, -0.372960, 0.263200, -1.095300, -0.992910, 0.495790,
-0.644890, -1.078220, 1.140160, 0.059610, -0.027910, 0.349200, -0.026920, -0.094400, -1.278300, -0.335390,
-1.005910, 2.277930, -0.648090, -0.595690, 0.370220, 0.776260, 2.453370, -0.144960, 1.345350, -1.315520,
-0.527330, -0.046040, -0.445480, -2.321420, 0.748690, 2.228950, -0.872610, -1.765920, 0.313970, 2.026990,
-2.402560, -0.385040, -0.310510, 0.177670, 0.112270, 1.014850, -0.136530, 0.160630, -0.240300, 0.941170,
-0.360850, 0.291310, -0.355050, -1.974950, -0.651910, 1.080740, -0.392940, 0.092370, -0.474480, -6.314560,
-0.123270, -0.481500, -0.707490, 0.363950, -0.391820, 1.250130, 0.728650, -1.087110, -0.909820, 2.201170,
1.026450, 0.328030, -0.936860, -1.709070, 0.315890, -1.459830, 1.815520, 0.092260, -0.635740, -1.387440,
0.131770, 0.467170, 0.130100, 1.971120, 0.649280, -1.820850, 1.472530, 1.498810, 0.290410, 0.297030,
0.335570, -0.139120, 0.994320, -1.512110, 0.149330, -0.120650, 1.088310, 0.821710, 2.076430, 0.835530,
2.002160, 0.616050, -1.279290, -1.745510, -0.857000, 4.575490, 2.058910, -0.290120, -1.500400, 3.695830,
-0.888070, 0.129640, 0.195530, 3.814910, 1.547890, 1.724860, -0.478530, 0.399230, -1.790930, 1.886750,
-1.436970, -0.695340, -1.059600, -0.667360, -0.106960, -2.124900, -0.551230, 0.236750, 2.639510, 3.511110,
-0.638680, 0.393960, 0.386840, -0.266790, -0.444200, -0.694030, 0.821350, -0.658430, -0.434180, -0.328850,
1.619250, -5.569380, -0.901050, -0.691700, 2.331300, -1.566200, -1.452440, -3.020080, -0.194400, 0.007330,
-0.974560, 2.402860, -0.468870, -0.157920, -0.514300, 0.656580, -1.944690, -3.300600, 1.407470, -0.526730,
-1.579260, -1.329020, 5.176160, -1.232480, -4.036670, -1.737390, 1.650060, 0.256750, 0.261450, -1.896960,
-1.619920, 1.392180, -1.569520, 1.459130, -3.632830, -1.045510, -0.392280, 1.029670, 1.236380, -1.501200,
-1.733620, 0.416140, 0.689820, -1.364520, -1.644800, 2.081300, -2.389710, -2.701740, 0.079160, 2.195810,
0.633400, 0.205540, -1.580880, -0.913980, 2.970200, 0.642840, 0.082310, -1.248730, 1.222160, 0.274910,
2.584690, -0.825270, -3.679280, -1.407290, -0.259350, -0.014770, 0.556050, 0.093040, 2.639160, 1.088990,
-2.119470, -2.684960, 0.745770, -0.961960, 0.585830, -0.272430, 0.790380, 8.724580, 0.163760, -0.118070,
-0.287030, -0.537140, -0.241460, -2.967660, -0.144810, -1.515890, -0.973100, -0.340860, -0.516470, 1.770200,
-0.880270, 1.553970, -0.942210, -4.675100, 1.276020, -0.543120, -0.524330, 0.672200, -2.037110, -0.398820,
2.437020, -0.958450, -2.373260, -0.470360, -0.230400, 0.867060, 0.106670, -1.990080, -1.201560, -2.079130,
-0.892210, -0.905870, -0.334270, -1.056960, -0.981510, -0.345860, -2.142460, -0.453650, 0.993560, 2.257820,
-0.566780, 1.358140, -0.128430, 1.782570, -2.333650, 0.055900, 2.451640, 1.252940, -1.297720, -0.748960,
1.013880, -2.272260, 1.815350, 0.138570, 0.058190, -2.385770, -1.607640, -0.393790, 0.867120, -9.199000,
-0.961560, -0.439650, -0.423560, 0.028700, -1.190410, -1.381120, 0.068940, -0.569600, -0.525180, -1.378970,
0.043270, -0.342250, -2.095630, -0.519080, -0.048170, 0.593330, -0.996620, -1.737290,
0.480750, 1.229020, -0.159790, -3.411370, -1.207340, -0.051760, 0.500680, 2.067300, 0.861560, 1.726770,
-0.131850, -1.778690, 1.108100, -1.903730, -0.884360, 0.232550, -1.902790, 2.964190, 2.858910, 1.208540,
1.760580, -0.261350, -2.434220, 0.431320, -0.100280, 1.855120, -0.658920, 0.482470, 0.707310, 1.039950,
1.036850, -0.688540, 0.722830, -1.060490, 0.425900, -1.072060, 0.675660, 0.806780, 0.644040, -0.437430,
0.714900, 0.884160, -1.495230, 0.430730, 1.334930, -0.575500, 0.798690, -1.455610, -0.869480, 0.606300,
-0.165570, -1.225610, -2.624170, -2.000330, 2.825240, -0.957700, 1.635820, 0.588470, 0.706800, -0.771050,
0.366710, -2.723930, 1.736160, 0.090220, 0.801050, -0.931210, -0.841920, 0.252470, -0.509650, -0.506510,
-1.158720, 0.031120, 0.298710, 0.801090, -1.708360, -1.794340, -0.089950, 1.506820, -2.078530, 2.683070,
-0.544470, -0.237420, 1.176170, -0.606200, -0.949150, -1.092060, 0.423900, 0.914900, 2.186140, 3.163220,
-2.035530, -1.921390, -0.410090, -3.789800, 1.638320, 0.596410, -1.345760, -0.904680, 1.021840, -1.305460,
-1.090390, 0.138040, 0.920210, 1.178970, -1.759880, 0.138890, -1.496350, -0.657700, 2.916440, -0.675500,
-4.228670, 3.381120, 0.608960, -0.203100, 0.075010, -5.593550, -3.951690, -1.774470, 1.169480, -2.522400,
-0.103680, 0.093190, 1.128250, 0.358030, -1.197670, 5.209400, 1.316500, -0.707000, -1.539180, -0.764530,
0.693580, 1.704160, -0.936510, -1.618160, -0.760640, 0.328480, 1.193350, 0.310360, -5.559440, -1.978240,
-0.588140, 1.013120, -2.045910, -0.499490, 0.916260, -0.237370, -6.166020, 0.924100, 8.597050, 1.817190,
2.444880, -2.963590, 0.286170, 2.999170, 0.217980, -0.880390, 2.351800, 1.264900, -2.759570, 1.214150,
0.023360, -1.371670, -0.805090, -0.872060, -0.079200, 1.650560, -0.041290, 1.162380, 1.772800, -1.017180,
1.524020, 1.513500, 0.017420, 1.307570, -1.592620, -1.292060, 1.132510, 5.134330, 1.244620, 0.873690,
0.870140, -0.040350, 2.884450, 1.909860, 0.105640, -2.457810, -0.032210, 3.524840, 1.591060, 1.265300,
1.509140, 2.480240, 1.203420, 3.536570, 0.224370, -0.056230, 0.063660, -3.740370, 3.500220, 0.014800,
0.987760, 3.410360, 0.998710, 2.449670, -3.209120, 0.035830, 1.177980, -0.607780, -1.831920, 0.354800,
1.009430, -0.345550, -0.930590, 1.839420, 0.174610, -2.265690, 1.476590, -1.853670, 1.261230, 1.160840,
-1.370950, -0.561470, 3.266140, -0.625210, 0.004660, 1.011280, 0.687610, -0.949990, 3.679680, -0.316660,
0.531290, 1.508560, -1.493740, 0.398840, -1.307720, -3.197520, 0.321520, -0.230490, -2.649700, 0.215130,
-1.037700, 0.456000, -1.332590, 3.084850, 1.691170, 0.198910, 1.436810, -0.410910, 2.902230, -0.922430,
-1.027310, 1.304240, -0.532950, 0.313790, 0.394960, 0.261950, 0.204960, 1.299210, -2.334580, -3.473200,
-0.013960, 0.738760, -2.068890, -0.241280, -3.881300, -2.655450, 1.962070, -1.631520, 1.022230, -0.639760,
-0.956450, -0.390900, -0.988160, -2.516240, -5.941140, -1.407490, -1.220860, -3.832340, 0.067740, -0.963270,
0.290570, 0.381790, -1.063220, -1.007040, -1.585040, -1.324240, -1.791920, 0.954400, -0.344700, 0.329700,
-1.607860, 2.640060, 0.106240, -0.285630, 0.932890, -1.580720, -0.449500, 1.542380,
1.321810, -2.479100, 0.667110, -1.702080, -2.521840, 1.886080, -2.139090, -0.405160, 1.234180, -1.250420,
0.181620, 1.010450, -0.343770, 0.282760, 0.021470, -0.645160, 0.977100, 0.286570, 0.079480, 0.411560,
1.075670, -0.768220, 0.110200, 0.452270, 1.570740, -1.211770, -1.912180, -0.220480, -0.727400, 0.741080,
2.555750, 0.058800, 0.874240, -0.966490, -0.669470, -1.200390, 0.932560, -0.789090, -0.446080, -1.682730,
1.035980, -0.156110, 0.185640, 4.573340, 0.302490, 0.174910, 2.118830, -0.065480, -0.146530, -1.360110,
-2.369520, 0.138140, 1.746900, 0.020480, -0.181600, 2.028250, -1.180360, -0.181490, 0.158630, 0.505200,
-1.589130, -2.742890, -0.472920, 1.110870, -0.177590, -2.061160, 1.595590, 1.419480, -1.132550, 0.352690,
0.624100, -0.555630, -2.758040, 0.716990, 1.570530, 0.398100, -1.105520, 0.833670, -0.140010, -2.332820,
-1.359430, 1.101310, 0.521690, -2.007610, -0.761780, 1.399670, -0.254290, 1.581900, -1.328190, 1.914240,
0.385650, 0.011380, -0.632750, -1.627790, -0.461680, 2.571720, -0.193800, -1.318010, -0.028760, 0.207180,
0.295250, -0.110500, 0.099480, 1.125730, -0.427980, 1.736060, -0.666930, -0.863880, -0.536120, 0.754710,
1.159590, 1.464290, 0.244260, -1.728290, 0.931310, -0.595000, -2.157940, 1.698860, -1.759530, -0.096510,
0.432180, 0.956080, 1.951910, -2.070340, 0.625690, 0.225930, 0.277940, -1.088070, -0.720990, 1.746940,
0.030050, 0.342700, 0.220830, 0.956940, -0.534960, -0.254780, 0.950010, 1.595230, -1.663630, -6.809060,
0.194900, 1.288530, -1.716480, -2.499420, 1.687470, -1.525160, -3.239620, 0.278590, 3.454000, 1.300420,
-0.026100, -0.820300, 1.520960, -0.883260, 0.184270, -0.398990, -0.286760, 1.459250, -0.260020, -0.023030,
0.310530, -1.549930, 0.082010, -1.371480, -1.789950, -1.111070, 1.350480, -2.288270, 1.437650, -0.844930,
1.336500, 0.996960, 1.681430, -3.129640, -0.456050, -0.572700, -0.530280, 0.857370, 1.768760, -2.807680,
1.671660, -0.681570, 0.355240, 0.320640, -0.195770, 1.973890, -0.088510, -1.285960, 2.097330, -0.361540,
-1.377220, 2.196770, -0.768720, 0.363030, 1.157750, -1.106510, -0.477610, -0.643260, -1.864950, 2.199100,
1.591970, -0.990920, 2.183570, -2.044840, -1.806500, 1.065170, -2.652540, 1.611500, 4.910660, 1.449900,
-0.453600, 0.835570, -0.084540, 1.052290, -0.183000, 0.917360, -0.502270, -0.886690, 1.635540, -0.929670,
4.081900, -2.097010, -1.306310, 2.607630, -0.048370, -0.670450, -0.523770, -0.001650, -0.555720, 0.599170,
-0.406600, 0.226170, -0.705890, -3.976350, 0.225350, 0.858460, -0.088160, 3.127120, 3.552820, 0.092280,
0.575970, -0.213190, -0.826420, 3.832150, -0.133080, 2.349570, -3.604570, 2.967980, -0.491260, 0.810580,
0.324570, 0.201740, -2.331350, 0.914830, 1.339630, 0.958730, 0.441070, 1.107800, 1.651650, 1.556710,
0.017390, -0.614120, -0.401600, 1.095340, 0.746230, 1.820320, -0.245000, -0.181530, 0.317480, -1.307380,
-1.343510, -0.564180, 0.134600, 0.399420, -3.898900, -5.067320, -0.115710, -2.209820, 0.563990, -4.192000,
-1.065100, -0.941730, -0.552650, -0.624990, 1.808280, 0.062870, -1.182880, -0.063070, -1.077850, -0.469320,
-0.661280, 1.170600, -0.736640, -2.004900, -1.306010, -2.277140, -0.818590, -0.774980,
-0.843540, 1.585590, 0.531040, 0.173420, 1.431620, 0.751920, -0.858260, -0.402120, 0.579250, -0.756200,
-0.064630, 0.190810, 0.091190, -0.589770, 0.191460, 0.456230, 0.675940, -1.627800, -0.807360, -0.027170,
2.128950, -1.375010, -0.325310, 0.317360, 0.140000, 1.739090, -0.255820, -1.922240, 0.350500, -3.434590,
1.533070, -2.125810, -0.193920, 1.028740, 0.090320, 0.639980, -0.322730, -0.677890, -2.036140, -1.521340,
-1.230500, -0.904290, 0.975090, -0.434540, -0.156940, -0.334620, -1.602500, -1.354050, -1.056770, -0.244590,
-0.300040, -0.814890, -1.089320, 2.921730, -2.592230, 0.486700, -0.183650, -0.737210, -0.003240, -0.430270,
2.033540, 0.514830, 0.198250, -0.417140, -0.812060, -1.257520, -0.128570, -2.526320, -0.454270, -2.034230,
-0.603980, 0.407110, 0.079400, 0.778500, -2.277710, -1.195470, -2.548180, -0.012580, 1.734900, -0.476410,
-0.214780, 2.917970, 1.087240, -0.532960, -0.125620, 0.220780, -0.267770, 2.705420, -0.901810, -3.123330,
-2.752340, -0.674810, 0.129660, -2.860310, 0.657750, 3.549570, -0.582730, 0.003050, 2.303250, -3.734100,
-1.069200, 1.372990, 2.716550, -2.248110, -1.611910, -3.205830, 0.762240, 1.403390, 0.332450, -0.171030,
0.919530, -0.432650, -0.702620, -0.346390, 6.761770, -0.483610, -0.840340, 1.307170, 1.176780, 0.490910,
0.975730, 1.358440, 0.313930, -2.310380, 0.015240, 0.978970, 1.826260, -0.238220, -6.804930, 0.487800,
2.919710, -0.240470, 0.050880, -0.026520, 0.979650, -4.189540, 0.409630, 1.121410, 3.038850, -1.259350,
-1.726030, -0.800270, -1.889560, 1.023430, 3.597140, 0.087340, -1.306620, -3.746480, -1.390590, -0.641470,
-0.787320, -1.426430, 0.007130, 2.771680, -2.541660, -1.623410, 0.654070, 3.078720, 1.251740, 0.549760,
1.355250, 1.097350, 1.298270, 0.185200, -4.708440, 0.433840, -0.084470, -0.127620, 0.398950, 0.717290,
-1.231580, -1.701740, 0.989150, 1.068930, 2.514850, -1.790310, 0.145090, -1.396560, 0.572620, -1.669070,
-0.242010, 1.714150, -0.512500, -1.109730, -1.094610, 1.910880, 0.555440, 0.450630, -0.935870, 0.012940,
-0.170470, 1.845250, 2.404160, -4.499210, -4.727210, 0.505190, -0.726820, 2.103870, -0.102630, 1.940660,
2.467700, 1.064370, 0.499290, -2.068700, -2.142950, -1.354130, -2.319330, 1.237740, 0.394890, -1.401960,
-1.242050, -1.843540, -1.229540, 0.811910, 2.087110, -1.026890, 0.954760, -0.536720, -0.440200, -0.044530,
0.421550, 0.576090, -0.074870, -0.005270, 0.987000, -1.412480, 1.669710, 0.685360, -0.472030, -0.870780,
0.766200, 2.012960, -0.909230, 1.073780, 0.480890, 1.917630, -0.875010, 0.401500, -0.074790, -1.101200,
-0.142490, -1.044720, -0.581170, 3.050040, -1.216040, 0.992190, -0.081150, -1.572260, 1.382500, -2.581080,
-0.239400, -0.821780, 1.175330, -0.915320, -2.507520, 0.902120, 1.539410, -0.096260, -2.196540, -3.161630,
-0.138620, -0.050010, 0.672940, 2.790950, -5.878510, -0.351060, 1.969860, 0.474010, 1.744520, 0.074150,
-2.134410, -0.189630, 1.627100, -0.199080, -0.592650, -0.185800, 0.216580, 0.306950, -1.601480, 0.510800,
-0.314750, 0.211250, -1.365060, -4.615570, -0.581100, -1.243790, -1.699150, -1.005500, -0.543000, -0.131580,
0.920960, 0.468110, -1.208070, 0.227350, 0.105110, -2.206870, -0.858920, -0.262790,
-0.849270, -2.737210, 1.473410, 0.844300, -0.937110, 0.607170, -0.961190, 2.747150, 0.587410, 1.622990,
1.570640, -1.758950, 0.089900, -1.287170, -1.958770, -0.812230, -1.398930, -0.830440, -0.261710, 0.596490,
-0.388900, 1.342860, 3.500170, -3.138640, -2.014260, 1.307630, 1.728950, -0.484850, -3.464170, 0.903560,
1.771090, 2.305930, -0.211150, -0.614130, 0.467590, 0.460860, -2.080260, -2.563630, 1.812340, 1.276000,
2.122560, 1.545230, -1.337630, 1.174040, -2.494450, -3.026140, -1.141260, -0.596050, 0.250790, 3.184040,
-1.319810, 0.434390, -0.191280, -1.876670, -3.048380, 0.732520, 0.506970, -1.456570, -0.462430, -2.719530,
-0.110040, -1.479280, 3.117030, -2.144060, -0.098270, -0.116710, 0.147350, -4.668670, 1.409080, -0.739590,
-1.313860, 2.900030, 0.034070, 0.728740, 0.554430, -0.745970, 2.065830, -1.172620, 2.366660, 2.099010,
-2.447950, -0.285980, -5.393920, 0.232950, 1.637540, 2.385330, 1.252170, -0.564300, 1.108840, 0.495670,
-1.721470, -0.000680, -1.762380, 0.871400, -0.331140, 0.511020, 2.939210, -0.539590, 1.331810, 2.212300,
0.492570, -0.365650, 1.113240, 2.711030, -0.431410, 0.457570, 2.183030, -0.418420, 0.223620, 0.382220,
-1.249390, -1.275450, 0.641990, -0.945780, 1.158160, 1.105090, 0.990040, -1.673880, 0.087860, -2.551880,
-0.323250, 0.066090, -2.786850, -0.574490, -2.519380, -1.446720, -0.470330, -1.126700, -2.238170, -0.779470,
-0.897250, -0.955220, 0.123730, 0.814940, 1.304290, 2.350930, 1.883890, 0.068890, 4.133880, 4.509600,
-3.012250, 0.610590, 0.702870, -0.669150, -0.305890, -2.481320, 1.482000, -0.559710, -4.037910, -3.742450,
-0.101600, 2.824250, -0.260280, -1.197000, -3.740940, 0.447310, 1.231000, -1.153000, 1.462560, 1.079140,
-3.407550, 3.975280, 6.170330, 0.898780, -5.684430, 1.385040, 2.887960, -1.320810, 1.147760, 0.905740,
2.792980, -3.387470, -3.238540, -0.888260, 2.450700, 1.539400, -0.861180, -1.551610, 1.663030, -0.831760,
-2.664320, 1.648710, 0.934120, -2.195460, 0.504220, 2.780210, -1.378120, -0.857280, -4.517250, 0.323670,
0.459500, 1.641090, -0.709950, 0.148120, -2.657630, 0.959260, 0.801700, -1.063480, 1.384590, 0.080810,
-0.788400, 0.650020, 3.280750, -0.521620, 0.263020, -0.440290, 0.286550, -2.205430, 0.583790, -2.097120,
-0.563670, -1.352080, 0.281420, -0.078730, 0.073840, 0.265640, -0.833640, -1.153210, 1.293530, -1.360600,
1.450260, -0.812380, -0.241210, 0.977900, -1.383300, 2.754090, 1.549500, -1.632530, 0.479440, 1.589880,
-1.367600, 1.317720, 1.459970, -0.075560, 0.272800, 0.014700, 0.380630, -1.245730, 0.092450, 2.260110,
-1.374170, -0.506640, -0.226480, -1.256910, 0.269220, 0.072220, 0.417950, -1.064630, 0.707130, -1.531060,
0.781600, -1.199230, 2.038690, -1.202380, -1.617870, 0.607260, 0.300740, 2.029670, 0.313240, 0.228260,
-0.191110, -0.052500, 1.125860, 2.049720, 1.849190, -0.341190, -2.730640, 1.281170, 3.101410, -0.322400,
-3.162330, 0.155360, -0.050560, -0.532800, 1.108610, 0.740600, -1.661850, 0.787870, -3.375040, -2.577940,
0.266240, -0.017570, -0.825790, 0.258110, -1.589870, -1.162130, 0.865790, 0.393600, 2.059880, 0.579060,
0.271110, -4.002370, -1.150730, 0.667200, -0.405380, 0.646100, -0.007370, 0.373400,
0.284040, -0.567040, -0.850630, 0.843030, -0.964800, -0.056370, -1.778530, 1.307140, 0.144180, 0.516480,
0.409640, -0.470030, 0.073420, 1.023820, 0.344810, 0.356860, -0.307760, -0.114450, 0.223140, -0.555990,
0.422860, -2.727650, -0.171940, 0.559240, 1.280470, -1.473390, 0.649830, -1.594500, 1.587150, 1.550170,
-0.237910, -1.091370, 0.967530, -0.124420, 1.141080, -1.807690, 0.601120, -0.522380, -0.330590, 1.041490,
-0.495620, -0.771870, -1.417990, -0.160400, -0.915850, 2.720360, 0.535410, 1.086360, 0.245800, -0.680730,
-1.245770, 0.423740, -0.830210, -0.921200, -1.008620, 0.832020, 0.157310, 1.507540, 0.095390, 0.452820,
-0.450700, -0.027040, -1.022070, -0.611320, -1.398290, 0.944470, 0.204080, 0.261680, -0.655990, 3.461470,
-0.375920, -0.109700, -2.913090, 0.674320, 2.663220, -0.854310, 0.229100, 2.425610, -0.717930, -0.117850,
-1.086690, 0.738040, 0.461210, 1.035910, 0.123500, -0.817310, -0.495650, 0.373020, 1.394680, -0.455430,
-1.249970, -1.183720, 0.830700, 2.835870, 0.144980, -0.321880, -0.489660, 0.591260, -0.409690, -0.151350,
2.083690, -1.039230, -0.792390, 0.950300, -0.737810, 3.477970, -0.948940, -0.063910, -0.343770, -0.210650,
0.582190, 0.390250, 0.484390, -0.846160, 0.611340, -2.219110, 1.654100, -2.214100, 1.743860, -0.423410,
0.337990, 0.461220, -2.514400, 0.277870, -0.796780, -0.378790, -1.440000, -0.674780, -1.022890, 0.382290,
-0.394340, 0.504830, -2.936690, -0.494290, 0.525820, 0.205830, -0.018470, -0.802990, -0.486560, 3.826530,
0.240790, 0.612390, 0.116790, 1.464220, -0.075990, -1.488390, 0.324920, 2.780210, 0.269640, -0.626960,
-0.868870, 0.949150, -0.196420, -0.795850, -0.787340, 0.398040, 1.825720, 0.648220, 1.126340, 0.009650,
-0.222380, 0.770770, 0.016820, 2.114050, 3.089690, 1.173040, -0.514380, -1.100150, -0.688930, 2.062650,
2.019280, -0.570010, -0.085390, -1.205310, -3.131460, 0.761110, 0.081030, 0.981790, 1.808580, 0.032790,
-0.134340, 1.227640, -3.716720, -2.677340, -0.708820, -2.573050, -1.920460, 3.603740, 1.496610, -0.892060,
0.301330, -1.875090, 2.064350, 0.064010, -1.458810, -1.276920, -2.167560, -4.082000, 0.397330, 1.158390,
-2.071180, -0.512210, 1.236040, 1.663310, -0.152150, -1.188660, -1.011370, 0.738750, -0.793870, -0.297530,
1.820600, 3.245410, -1.446100, 1.780780, -1.503070, -0.679250, 0.249720, -0.150770, 0.378810, 0.278240,
-1.193450, 0.994600, -1.854330, 0.157290, -0.257040, 0.920110, -0.733130, -1.660320, 0.970610, 1.245360,
1.431840, -2.430340, 0.588080, 2.789790, 1.518780, -1.280040, -0.447880, -0.833850, 1.432400, -0.267700,
-1.339470, -0.796020, -0.720490, 1.931150, -1.505820, 0.822490, -2.293180, 1.996750, 2.381840, 1.717270,
0.338580, -0.384790, 1.503380, -1.872230, 0.593920, -1.018350, -1.348710, -0.805010, 0.460860, -0.184000,
-1.252940, -0.834900, 0.390190, -1.418220, 0.312910, -0.721720, -0.726430, -0.786770, -1.257020, -0.211070,
-1.046590, 0.580970, -6.371610, -1.231810, -2.600390, 0.096300, 0.204480, -1.329650, -1.062630, -0.008150,
0.131220, -0.192590, 0.043420, -2.906980, -0.855230, -0.318890, -2.450710, -0.488440, -1.486390, -1.486040,
-0.612360, -1.379100, -0.661430, -0.565860, -3.348280, -0.060990, 0.394120, 0.864280,
1.143890, 1.415290, 1.053730, -0.041010, -0.426390, 0.957630, 0.175450, -0.844030, -1.707960, 1.635040,
-2.890270, 1.373240, 1.500940, 1.603010, -0.041890, 0.015520, 0.045910, 1.382990, 1.883140, -0.364010,
0.352310, 2.758810, -0.103530, -1.759600, 0.864050, 0.045410, -1.271500, -0.458700, 1.599760, 0.950510,
1.379200, 0.045150, 2.094630, -0.699450, -3.164360, -0.341610, -0.732830, -0.439520, 3.192450, -0.434160,
-0.541050, 0.462770, -1.390850, -0.440840, 0.738160, 1.779410, 0.714480, 1.685060, 1.644360, -0.468730,
0.434350, 0.446850, 0.327190, -2.451090, -0.497570, 0.619290, 2.986480, 0.792700, -0.085700, -4.306190,
-0.078630, -0.151430, 1.154690, -0.780220, -0.873080, -1.078070, -2.437820, 0.282310, 0.372780, -2.819500,
-4.773720, 1.532340, -0.652860, 0.720600, 0.031830, -1.081210, -0.504200, -1.472420, -1.202450, 0.567860,
0.234930, -3.348710, -4.552630, -2.707290, 0.812200, 1.820300, -2.450240, 0.475280, 0.886760, -2.309900,
2.615010, 3.133580, -2.777650, -14.368160, 2.063110, 2.628000, -2.186770, -2.969140, -1.136060, 0.437150,
0.055670, 1.868340, 3.808050, -0.629890, 0.380130, -2.789600, -0.290660, 0.205660, 0.983260, 0.387160,
2.151150, -0.814190, -1.491190, -3.513470, -2.146320, -0.236450, -0.283050, -1.002010, -0.724130, 2.152870,
0.412410, -1.659180, 0.611010, -0.150170, -0.679740, 0.654000, -0.002690, 3.202600, -2.386630, 0.921520,
-0.920960, 0.666070, -1.293600, 1.313320, 0.032710, -2.891180, -1.641320, 3.141470, -0.266560, 3.284010,
-0.000740, -0.158260, 0.823570, 1.805280, 2.015610, 1.888390, 1.066210, 2.584680, -0.661840, -1.221500,
1.023320, -0.587190, 0.567610, 1.031800, 1.587750, -1.047120, -3.145500, 3.140240, 1.107960, -2.376570,
1.072050, 1.572340, -3.791050, 1.277110, 1.954350, -2.810790, 2.512170, -0.274720, -0.237460, 0.114980,
4.475170, -1.672080, -1.042790, -0.411450, 1.313950, 0.857160, -3.570370, -2.071390, -0.468060, -0.331810,
2.139880, 0.547680, 1.281230, 1.761970, 0.115060, -5.482820, 0.911120, 2.057370, -3.345380, 0.702820,
1.811700, -3.650060, -2.145430, 0.049160, -3.146720, -1.613830, 2.197120, -2.688850, 0.936030, 0.584990,
-2.039920, -2.938690, 0.918090, 1.391140, -2.154800, 2.886710, -2.063930, 2.185040, -2.887130, -1.456270,
0.555830, -0.388710, 0.262910, -1.719510, -2.164460, -0.803090, -1.602880, 2.262170, -1.883740, -0.646070,
2.014450, -1.204020, -1.707500, -0.373090, 0.331200, -3.638650, -0.384300, 1.546660, -0.108720, -0.092140,
2.018090, -2.748020, 0.952760, 1.302820, 2.100570, 2.124570, -2.216810, 0.152440, -0.584630, 0.716930,
1.833390, -1.071200, 2.427140, 4.786980, 1.388350, 0.591710, -0.309480, 2.607000, -2.714940, -0.291420,
3.351070, 1.560200, 0.547580, -1.287030, -2.038320, -1.053040, 0.255340, -1.314890, 1.929420, -0.118990,
-0.946510, 0.920510, -0.024220, 0.244400, 1.555460, 0.558920, 0.035470, 1.229010, -0.336580, -1.620920,
-2.086480, 4.376670, -0.816820, 0.150030, -1.134280, 0.403670, 1.703720, -3.304240, -1.511850, 1.140720,
0.177570, 2.617000, -0.872280, -2.161890, -0.623160, 0.452520, -4.703250, -0.781550, 0.360250, -1.222130,
-0.435160, 1.126150, -0.015050, 0.552190, -0.242390, -5.307200, 0.284920, 0.550200,
-2.659360, -0.600790, 0.440280, -1.836560, -0.366820, 0.283400, 1.678540, 0.222620, -1.651590, 0.833820,
-0.477740, -0.156940, 0.450380, 0.393340, 0.023120, 0.258910, -1.079780, 1.193850, 0.532670, -1.052060,
2.159730, -3.635190, 0.062330, 2.092450, -0.160330, 0.286760, 1.517380, 2.255100, 0.362590, 0.811360,
-0.598320, -0.368900, 2.609160, -1.286270, -2.583360, -2.603080, 0.394260, 2.421820, 0.083560, -0.455980,
0.560550, 0.003940, 1.529620, -0.757520, -0.829540, 1.129150, 1.104530, -1.273250, -0.698680, 1.898130,
1.489830, -0.130440, 0.250660, -1.277930, 1.096370, -0.996750, -1.506800, -2.055800, -2.652530, -0.903550,
-1.721620, -1.423430, -1.234070, -0.421480, -2.472010, -2.789180, -0.136940, -0.548210, 1.025770, -0.104640,
2.808840, -1.511920, 1.061260, -1.815900, -0.212950, 1.178260, -0.310110, -2.299230, -3.830900, -4.453940,
0.503900, -0.166330, -2.540170, 1.132190, -0.250520, 0.902960, 1.108550, -1.541900, 2.124690, 0.192630,
0.230950, -1.555630, 4.624050, 3.856140, 2.695120, -1.049620, -0.862500, 1.359850, -2.272780, -2.753230,
4.089100, 0.644690, -8.859940, -4.447280, -1.916560, 1.018750, 0.378790, -2.391550, -0.877220, -1.477390,
1.527700, 1.217250, -0.044050, 0.112600, -2.090940, 1.229600, 2.968840, 0.413580, -1.692430, 0.633100,
-0.887970, -1.809360, -0.034010, 2.936640, 2.367100, -1.670890, -2.222560, -0.333090, 3.907050, -0.277930,
-2.334760, -2.688870, 1.562830, -1.481880, -3.346960, 2.329110, 0.417020, -2.556800, -2.599660, 1.961300,
0.282610, -0.939520, -7.306660, 2.186690, 0.713190, -0.045560, 0.100760, -3.128710, 0.262120, -0.331650,
0.058580, 1.851410, -0.084960, -0.309690, -1.450390, -3.004600, 1.677450, 0.903500, -0.075710, 1.702790,
0.435180, 0.756650, 0.481100, -0.079020, -1.350710, 0.070020, 0.347430, 2.546930, -0.994540, -0.984070,
0.319160, 1.002980, -0.367740, 1.434350, 1.098360, 0.477180, -1.600660, 1.430810, 2.503620, -2.917330,
1.766980, -1.169430, -1.574070, 1.903530, 2.499480, 0.872950, -1.060910, 3.834470, 0.559230, -1.177090,
0.616160, 0.282680, -0.110540, 4.982910, 1.570120, -0.402070, 2.981810, -2.089540, -0.532510, -2.628340,
-4.480700, 2.366190, -1.104920, -1.261310, 0.563530, -1.868160, -0.633650, 0.997410, 0.782960, -0.100320,
6.550100, 0.203100, 1.317510, -1.542950, -1.524390, 0.567030, 1.866970, 0.464830, -1.836230, 0.852970,
-3.508990, 1.663820, 0.168760, -1.429590, -0.713880, 0.854210, 0.144720, 1.562060, -0.289400, 0.468480,
2.362260, 2.865560, 0.693840, 0.123430, -1.379210, -2.265130, 1.078360, -1.174430, -3.082010, 1.792330,
-0.981240, -0.345960, -0.179170, -1.753620, 0.321940, 0.999510, 0.721630, -0.542390, 2.306960, -0.669740,
0.631050, -1.950810, -2.419860, -0.197600, 1.259800, -0.419070, -0.140650, -0.076380, 4.154580, 4.672410,
-1.283320, 0.120760, -0.622530, -0.744350, -0.685200, -1.167610, -1.209680, 0.487240, -0.011320, -0.354230,
-0.552200, -0.432490, 0.317520, 1.067650, 1.245700, -0.527850, -4.543180, 0.470820, 0.447920, -1.798050,
1.631290, 0.433640, 0.891990, 1.481500, -2.068770, 0.265290, 1.014850, -2.454840, 3.549950, -0.614050,
0.500400, -0.972040, -1.919890, 1.626150, -0.603510, 1.821170, -1.368490, -0.777270,
0.861090, -0.371240, 0.167590, 1.796580, 1.204940, -0.317230, -1.066680, -1.025250, 2.197040, -0.834660,
-1.078590, -1.444880, 1.579790, 2.762930, 0.095890, 0.766390, -0.285150, -0.864860, 2.113040, -1.174420,
2.740070, -1.008290, 0.920950, 0.475160, -0.758530, -3.045710, -0.663900, 0.678410, 0.214650, -0.152160,
0.597790, 1.768490, 0.527340, -0.018330, -0.470680, -0.896690, 0.803770, -0.350000, -0.923420, -0.283790,
0.295510, 1.830580, -0.380240, 1.322350, 0.519970, -0.969990, 1.349620, 1.412180, 1.745860, -0.138580,
0.896500, -0.044160, -0.457750, 1.117840, 2.269120, 2.298290, 2.468510, -0.108400, 1.663180, 3.896530,
1.084130, 0.741320, -0.836790, 0.725090, -1.666970, 1.727900, 2.281620, -1.116690, -0.214430, 1.857840,
-0.366530, 2.525540, -0.370290, 0.210690, -0.707540, 0.644870, 0.202130, 1.745880, 1.757300, -0.330510,
-0.552180, -0.932190, 1.550450, -1.569890, -0.056540, -2.564350, 0.155820, -4.341440, 1.497350, 0.670270,
3.236840, 0.786530, -0.798170, 0.208680, 1.255610, -1.889020, 0.828330, 1.865080, 0.460680, -2.267150,
-0.143260, 0.863260, 2.221720, 0.283960, -0.874590, 2.402430, 0.837590, -0.472810, -1.305970, -2.089580,
0.335400, -0.347920, 0.019950, -0.079170, 1.730930, 1.440480, 0.083770, 3.047830, 0.971960, -2.026150,
2.270700, 0.298040, -1.206280, -0.420610, 1.034970, 2.908620, 1.332410, -1.011070, 1.057230, -1.217280,
0.191960, 1.437690, 1.526880, -2.016280, 0.825570, -1.067250, 1.544360, -1.030730, -0.817240, -3.761950,
-0.101360, -0.383230, 0.988920, -0.007780, -0.360990, 0.861730, -2.676220, 0.461290, 3.576210, 0.673510,
-0.696030, -1.476310, 2.621620, 5.415290, -0.383900, 0.028100, 0.265230, -0.320680, -2.501590, 1.217980,
-1.737600, -1.949830, -5.932220, -0.917740, 1.377250, 1.918540, 0.198180, 1.102750, 1.055850, -6.286630,
-0.546500, 1.980050, 1.763730, -2.410780, -0.736770, 0.218280, 0.364010, 0.150480, -1.247910, 0.824590,
0.014050, -2.241650, -0.417640, 0.280090, -0.436030, -2.312490, -1.978000, -0.197100, 1.899080, 2.180750,
-0.238880, -2.587840, -0.044550, 0.629490, 0.953040, 0.848640, 1.358580, -1.245130, -0.598560, 0.041640,
0.077020, -0.553660, 0.815250, -1.779470, 1.936440, 0.099900, 0.013910, -1.869380, -1.185120, -3.842040,
-0.227980, 0.602510, 0.399890, 0.451370, -1.172020, -1.435870, 0.206610, 0.846410, -0.209160, -1.236380,
-1.541850, 2.996630, 1.486310, 1.105100, -3.314280, -1.446480, 0.937820, -0.979100, 1.873210, 0.898460,
0.582900, 1.731190, -1.426770, -1.638190, 0.276410, 0.012030, -0.737860, -0.391500, -1.256350, -1.173110,
1.188820, -0.781470, -1.086060, 0.368190, 1.468000, 3.116100, 0.368210, -0.591100, -1.505680, 1.311060,
0.669660, 0.608710, -0.593870, -0.332360, -0.289470, -0.818930, -0.404550, 1.774030, -0.711860, -1.897330,
-3.125430, 0.100350, 2.365600, 0.941790, -0.770370, -0.392070, 0.148130, -0.244200, -3.895140, -0.586620,
0.520220, -0.861180, -1.044900, -0.117670, -2.296070, -0.383530, -4.242510, -1.115120, -0.564200, -15.459870,
-1.353970, -2.434010, -0.573970, -2.018030, -0.785930, -1.528740, 0.303680, -0.493570, -0.864680, -1.303830,
-1.531880, -2.439480, -2.877970, -2.427710, 0.011100, -3.465330, -2.807420, -0.605440,
-0.089300, -1.002110, 0.557880, -1.165780, -0.063640, 0.899860, 0.781470, 0.538150, -0.649720, 0.172710,
-1.415330, 0.214550, 1.286630, -1.255950, -1.127090, -0.419230, 1.809520, -1.186610, -0.912910, -1.447050,
2.032350, -1.142880, -1.127540, -0.109910, 0.419280, 1.088500, 0.727110, 0.337680, -0.843970, -0.172780,
-0.954820, -0.669310, 0.662110, 0.711590, 1.156510, 0.255910, 1.960700, 0.269800, -0.619530, 0.977370,
1.354690, -0.603430, 0.982040, 1.657640, -0.825620, -0.760800, 0.136320, 0.000950, -0.981730, 0.347160,
-1.718090, -0.578550, 0.715190, 0.112070, -0.346460, -0.255010, 0.465490, -0.879110, 0.801890, 0.415070,
-0.913840, -0.234740, -2.362330, -0.390670, 0.269820, 0.719250, 0.859380, 0.156780, -0.688420, -1.613440,
0.594790, -0.496460, -0.371720, -0.379970, -0.677630, -0.608530, -0.519510, 0.567090, -2.007250, -0.599470,
1.344940, -0.280760, 0.973040, -0.059320, 0.954360, 0.738500, 1.048660, -0.910630, 0.734580, -0.934930,
1.037710, -2.431020, -0.287660, 1.051150, -0.125000, -2.864240, 1.810190, 1.397770, 2.648770, -0.988060,
-1.311510, 0.609410, 0.176500, -0.628850, 2.118110, -0.094700, 0.755250, 1.332660, 0.507460, 0.676190,
-2.283150, 0.221100, 1.345200, -2.422610, -2.950880, 0.366090, -3.381690, 0.044610, 0.760750, -4.047790,
0.890640, 0.254790, 2.385890, -0.776450, 2.763670, 0.358880, 1.056790, -0.638070, -0.511430, -1.096010,
-0.189950, 1.578060, -0.434430, -1.087870, -1.832490, 0.533760, -4.018860, 0.492180, -2.234110, -1.215430,
-0.424380, -0.983060, -0.882500, -0.055910, -0.116250, 2.086630, -2.060470, -1.470410, 1.564990, 0.888110,
-0.483690, 0.256830, -0.493980, 2.851500, 0.247160, -0.828540, 1.408400, 0.827490, -4.193740, 0.714870,
-1.574670, -0.635900, -1.831330, -0.135150, -0.734810, 1.012630, 0.615280, 0.401660, 0.992310, -1.917470,
0.080410, -0.195250, 0.574750, -0.611380, 0.377480, 1.183240, -0.422410, 0.636150, 1.002720, -1.495580,
1.093360, 0.219880, 0.386150, -1.584710, 0.179590, 0.058830, 1.666720, 0.138870, 0.569500, 1.210350,
-0.734710, 1.316990, 1.739710, 2.579410, -0.886310, 1.045250, 1.001250, 0.734420, 0.318340, -0.762020,
-0.052500, 0.839370, -0.969050, -0.217560, 1.673740, -0.986930, -1.151040, -1.865680, -0.173310, -0.079660,
0.080740, -0.295680, 0.225950, -1.204150, 0.389510, -0.220240, 0.065020, -0.044410, -0.723890, 0.346290,
-0.927400, 0.836310, -2.304940, -1.294920, -1.424960, 1.516200, -2.004990, 0.747030, 1.978980, 0.294850,
-1.898750, -1.398650, -0.788130, 0.252330, -1.021970, 0.102870, 1.284950, 1.594370, -0.920360, -1.797740,
0.398350, -0.198730, -0.244220, -0.201480, 2.508210, 0.406230, 0.554140, -0.928650, 1.906420, -0.188980,
-1.727700, 0.987230, -0.937980, -0.050120, -1.103360, 0.004270, 0.850330, 0.451740, 1.705220, 0.358690,
-0.343750, 0.873800, -0.361890, -0.590610, -0.807130, -1.077280, -0.324630, 0.219880, -0.010770, -1.490430,
-1.731750, -0.265810, -1.383370, -3.382440, -2.394980, -0.686970, -0.531960, -0.488140, -3.027340, -3.919870,
-4.585950, 0.770610, -1.784620, -1.981250, -1.796300, 0.537120, -0.839180, 0.914730, -1.589660, -1.794220,
-0.855310, -0.533610, -0.105970, -2.880280, -1.253940, -1.333860, -0.653260, -0.688790,
-1.984810, 0.770020, 1.350140, 0.365630, 0.903780, -1.250610, 1.320590, 2.186370, 0.782990, 1.126420,
-0.749310, -0.571530, -0.266840, 1.800610, 1.513050, 0.294670, 2.627350, 0.959500, -1.283520, 1.250840,
-2.117080, 0.461030, -1.710340, 4.747800, -0.291110, -0.173590, -1.944260, -2.017540, 1.048840, 0.936050,
0.849740, -0.406620, -0.210690, -0.075640, -2.686350, -1.904510, 0.643940, -0.320650, 1.448790, 2.992420,
0.552900, 0.646860, -0.499410, -1.627720, 0.907090, 0.657230, 1.860390, 0.124650, 1.127430, 0.026070,
-1.742510, 0.190510, -1.450240, -0.199310, -0.342730, -0.104960, 1.813380, -1.384490, 1.129230, -0.509620,
-1.150050, 1.155280, 1.392480, 0.673890, 3.388160, -2.133220, -1.211280, -0.982140, -3.818000, 1.007060,
-0.968830, -0.012030, 0.868270, -0.223460, 0.893590, -1.566130, -1.630940, -0.142180, 1.956240, 0.272300,
-1.320230, 0.717120, -2.369190, -0.278060, 1.371540, 0.920670, 0.100580, 0.208560, -0.611410, 1.848370,
-1.632050, -2.013460, -0.205470, 0.851540, 0.025050, 1.124360, -2.159430, 0.173110, 0.400020, -1.262080,
-2.469350, -0.066510, 1.626840, 0.860390, 1.008360, 0.654610, 2.134090, -0.688810, 1.725590, 4.003900,
0.879500, -2.316250, -0.782960, -0.647410, -1.352530, 4.141090, -0.792580, 1.929950, -4.111440, -1.619330,
1.654220, 0.949870, -0.376110, 0.738020, -1.570860, -0.876110, 1.565140, -1.081250, -0.037730, -0.104430,
-0.739880, -1.139320, 1.148850, -3.038630, 0.447530, -0.243070, 0.705070, -0.474920, 1.404720, 2.838990,
0.319350, -1.795040, -1.460500, -2.273530, 0.297070, 1.486390, -0.445540, -1.655830, -2.556560, -1.320380,
-0.929820, -1.327870, 3.607000, 0.049750, -7.361640, -0.163860, 1.078070, 4.098500, -1.365270, 2.443790,
-5.539260, 0.236770, 3.879010, 0.228260, -2.336710, -2.138660, 1.283450, -0.962220, 1.492800, -0.959770,
-1.335870, 0.137760, 2.224700, 0.478810, 0.688590, 0.852020, -0.956020, 1.082260, 0.981710, -0.075910,
0.615190, -1.455430, 0.114900, -1.155310, -0.853720, 3.058110, -1.374900, -5.529870, 1.448940, -0.576660,
1.187350, 1.034390, 1.561430, 1.775060, -0.933310, 0.130300, 1.887850, 0.312220, -0.801790, -0.065930,
-3.294370, 1.228030, -0.934350, 0.370470, 2.740290, -0.240200, -3.603940, -0.991110, -0.055440, -1.279330,
-1.431140, -1.159490, -2.120820, 0.467290, 0.994280, -0.223800, -0.501960, 2.980650, -1.324680, 0.503050,
0.554980, -0.148820, 0.913450, 0.368050, -1.239520, 0.107440, -0.440930, -1.089930, -2.960440, -1.183480,
-0.472380, -0.404800, -1.797990, -1.650680, -0.417620, 0.451390, -0.612180, 1.465010, 1.375190, -0.124820,
0.570460, -0.543320, 0.748740, 0.539890, 1.976710, 0.550950, 0.131460, -2.431700, -1.614580, -0.461120,
-1.546210, -1.121140, -0.622830, 0.451260, 0.072260, 0.124850, 1.267860, 0.106320, -2.735340, -0.293240,
0.516570, -2.096700, 0.935510, 0.137620, 0.481890, -1.186980, 0.965050, -0.734120, -0.108740, 0.504030,
0.621490, -4.325550, -1.557420, 0.753810, 2.993060, -1.169880, -1.623400, 0.370430, 0.186800, -2.110240,
2.345050, 0.006630, 4.580490, 0.064550, 0.125830, -0.355870, 0.509920, 1.972110, 0.663840, -0.921160,
0.296700, -1.426800, -1.001530, 0.478120, -3.131570, 1.113130, -1.013840, -0.587150,
-2.405210, 0.513210, 0.730630, -1.166570, -0.746110, 0.710800, -0.345510, 0.201890, 2.090460, -0.680350,
0.625030, -0.167610, 0.750880, 1.004860, 1.347780, 1.250230, 1.954600, -0.472410, 0.474360, -0.583460,
-0.158620, 0.217000, 1.055970, -0.316900, -2.259830, -0.992310, -0.340150, 0.201610, 0.083680, -0.871440,
2.086630, 0.636800, -0.568430, -1.327340, -1.989910, 1.175220, 0.935320, -1.227370, -0.691470, -1.020960,
-0.691340, -0.672660, 0.018640, 0.608190, 1.400120, 1.870790, -1.375680, -0.002390, 0.621770, -0.708630,
0.055240, 2.052810, 0.135940, 1.328250, 0.933350, 0.234470, 1.684970, 0.507560, -0.769110, 3.044210,
1.341050, -1.732600, -0.874160, -1.640740, -1.242510, -0.068320, -0.121560, -0.417870, 2.272440, 0.699810,
-0.338290, -0.330470, -3.545960, -0.445890, -0.796280, -0.886950, 1.250630, -1.640000, -1.365520, -0.182650,
-0.696630, 0.248530, -0.509240, -0.679770, 1.745440, 1.095880, -0.725390, -1.335430, -0.874820, -1.388360,
0.820870, 0.955730, 0.833830, -1.481230, -1.011290, -0.001640, -0.276580, 2.476650, -0.508640, 0.083210,
-0.198920, -2.485260, -0.438180, -0.106230, 0.513070, 0.246000, 1.450930, 2.203070, -1.204210, 0.324700,
1.035670, 1.457180, -0.929910, 1.610230, 0.469560, 1.095400, 2.814630, -1.293040, -1.960060, -0.995690,
0.426110, -1.145440, 2.261560, 3.308770, -1.337470, -3.586880, 1.452570, -1.165620, -0.578630, 0.553920,
1.410790, 0.150720, -1.178080, 0.693310, 0.040120, 0.169200, -0.141450, -0.165150, -0.107450, 0.117340,
1.772440, 3.078460, -2.100920, -0.801980, -5.395140, 1.641110, -0.416070, 1.104480, -3.474750, -3.290890,
0.554820, -1.851190, -0.321310, 0.214620, 0.152700, 0.356850, 1.826830, 1.488920, -0.669960, -1.170060,
1.370610, -0.557440, -2.304560, 1.058140, 2.633210, -1.592090, 2.108080, 0.674780, 0.590210, -0.993590,
3.282940, -2.272230, -1.570050, 0.974150, -3.208490, -1.521440, -0.500560, 1.640860, -3.159130, 0.441470,
0.187670, -1.059930, 0.458860, 3.573600, -1.462940, -3.425780, 2.024130, 2.581470, 1.347370, -2.524060,
-0.894090, 0.267990, -2.945480, -0.419130, -2.573070, 0.766650, 1.683100, -2.417850, 0.330950, -0.267960,
0.492160, -0.359800, 0.554730, 1.074420, -2.756680, 1.757670, -2.458820, 0.439130, -3.116900, -0.363990,
3.867300, 0.784270, -1.715580, -0.609610, -1.620420, -0.774590, -1.862320, -1.090840, -0.921070, -1.401360,
-1.470630, 0.658720, -0.168760, -0.586340, -0.182750, 4.245830, 0.904020, -0.233970, 0.821750, 2.919720,
1.536200, -3.305150, -0.569110, 5.075320, 2.621300, -1.919790, -0.825820, 0.549350, -0.524920, 0.129120,
-3.664140, -3.553530, 1.337140, -1.530600, 0.774220, 1.505640, 0.125670, 0.987090, 1.906770, 1.672180,
1.289040, 1.295650, 1.340640, -0.066380, 0.475080, -0.809840, 0.687940, -0.955140, 0.625050, -0.735040,
1.435230, 1.114320, -1.040350, -3.259180, 0.004990, 1.283220, -0.143320, -1.101450, 0.479110, 0.094260,
0.227230, -0.731730, -0.588810, 0.347750, -1.497220, 0.357470, -1.213140, -1.027620, -0.332540, 0.410110,
-1.892840, -0.083080, -0.913710, -2.219350, -1.004360, 0.619510, 0.475670, -0.301990, -0.035520, -0.756510,
-0.396250, 0.009500, 0.686950, 0.514930, -0.066970, -1.119780, -0.202400, -0.102210,
1.801310, 1.350290, 1.451240, -2.060650, -0.716250, 0.134280, -0.662830, -2.189870, -0.592840, -1.538430,
0.719860, -1.835020, 1.591750, 1.184650, 0.915180, -3.102400, -0.826060, 1.422460, -0.175520, -1.770220,
-0.539660, -1.574510, -1.766520, 0.015410, -0.356790, -0.260980, -0.891190, 4.519910, 0.222540, 0.455920,
-1.265440, -3.041250, -0.850180, 0.439430, 1.063660, 4.294560, 2.207530, 1.030530, 1.462750, 1.249100,
-1.075380, 0.471580, -1.906380, 1.130640, 0.621260, 1.877410, 0.808170, -0.675800, 0.910910, 2.156050,
-1.868530, -3.546430, 0.857440, -2.525310, -0.382510, -0.283890, -0.649500, -0.520770, 2.230730, 1.692920,
1.089580, -0.120410, 2.371610, 1.189880, 0.090010, 1.932380, -1.340840, -2.932090, 1.538460, -4.555750,
-0.183250, -0.588340, -1.336310, -0.415680, -0.677190, -1.454260, 2.040960, -1.062920, -0.706810, 3.686790,
-0.531820, -0.818760, 0.675010, -1.829740, 3.572200, 2.125050, -0.103140, 2.138240, -1.469050, 0.099260,
-1.253860, -1.230400, -3.212170, 1.651500, 1.009370, 1.162090, 1.902880, 1.719610, -0.633170, -0.954610,
-1.366060, 0.848650, 2.439490, 4.293440, 0.708690, 0.315960, 0.460790, 1.866510, -2.123150, 0.104010,
-1.669190, 1.140070, -1.086340, 0.796360, 0.755740, 2.317090, -0.482640, -1.904020, -0.388440, -0.837280,
-0.500900, 1.094170, 1.283330, 0.560870, -2.728180, 0.391020, 0.143600, -2.389800, -0.526460, 0.065920,
-0.095280, -3.313260, -2.580380, -2.426740, 1.890930, -5.057280, -0.218030, -3.059900, 0.703470, 3.130030,
0.091500, -4.778850, 0.408470, 0.250700, -0.243140, -1.303770, 0.189930, -3.932710, 3.653870, -1.032000,
-1.115050, 1.569940, -2.982790, -2.025280, -0.723750, 3.430940, 0.393870, 2.234220, -0.136830, 2.737650,
-0.284430, -1.328940, 0.021930, 2.567450, 2.364180, -1.270910, 1.842170, -0.933270, 0.119780, 2.302630,
-1.698640, -0.261430, 1.203260, -0.007410, 0.087870, 1.085120, -0.624410, 0.781120, 0.087960, 1.551710,
1.399200, 0.005530, -1.170900, -0.779310, -1.096850, -1.694860, 0.208930, -1.927250, -2.337040, 2.000060,
-0.290280, -2.257960, 0.991390, -0.440570, 1.876550, -1.487460, -0.715400, -0.122290, 0.300250, -0.580010,
1.867300, 0.319570, -1.108840, -0.309130, 1.003810, 1.234420, -3.249070, 0.220740, -1.299910, -4.337130,
0.987590, -2.052300, -0.386340, -0.035380, -1.850070, -1.812650, 0.782420, -5.338920, 0.820010, 1.027850,
1.700470, -2.028310, 0.347590, 1.683940, -1.300600, -1.507630, -1.904350, -1.270950, 1.351850, -1.457420,
-3.676270, -1.119010, 0.061260, 0.420150, -0.137300, -1.035350, 1.488780, 0.029410, -2.601980, 1.924380,
-1.358450, -0.095950, 0.995600, -1.308170, 0.286180, -1.227270, 2.011100, -2.352590, 0.383440, 3.147190,
-2.104350, -3.286790, -2.237340, -1.783780, -3.478360, 1.327780, -0.421320, 1.171560, 5.224090, -4.023080,
1.596490, -0.118890, 1.106640, 2.944980, 2.917380, -1.812010, 0.069400, -1.662030, -2.326750, 0.135180,
6.014930, 0.891980, 0.230100, 1.429020, 2.990400, -1.170570, -1.124590, 2.184910, 2.325210, 1.157090,
-0.066500, -1.554440, 0.931140, -0.495260, 0.745910, -1.120520, 0.352960, 0.157170, 0.148560, 0.338480,
0.731560, -2.697300, -1.539300, 1.228720, -1.264590, 1.346120, -0.118010, -0.773760,
-0.887720, -1.539330, -1.100760, 0.268890, 1.202380, 0.852990, -0.291620, -1.047700, -1.299880, 1.691910,
-0.097540, 1.005830, -1.795290, -0.453620, -0.271660, 2.113290, 0.084300, 0.453080, 2.046620, -0.423020,
0.521150, -0.874070, -0.102770, 0.420450, -1.457940, 1.262560, -0.800520, -1.872630, 1.159270, -0.546850,
-0.142820, -1.987790, -0.321940, -1.596740, -1.567340, 0.355740, 0.065730, -1.452570, -1.145770, 0.113570,
0.970030, -1.259500, 0.716740, 0.404720, 1.725440, 1.304670, -0.696560, -0.203260, 1.023420, 1.697660,
-0.734870, -0.051870, 0.581690, 0.836390, 0.680690, -1.253500, -0.414290, 3.090720, -1.595060, -3.518870,
-1.685340, 1.221370, 0.994950, -0.068430, -0.652100, 0.547320, 0.658760, -2.539480, -2.403520, -1.538130,
-0.824350, 0.932240, 0.341730, -0.029170, -0.832170, 0.488460, -0.437790, 0.820340, 0.705770, 1.114940,
1.385800, -0.387110, -0.343920, -2.174860, -0.133400, -2.167490, -1.730150, 2.694310, 1.741380, -0.523890,
-1.604190, -1.355910, 1.793850, -2.141090, -0.027630, 1.755210, 0.920810, 0.873410, -3.391980, -1.129010,
-0.169220, 0.692600, -0.435840, 0.163130, 1.067440, -0.989230, -0.123900, 0.763720, -1.227950, 0.611530,
-1.081420, 1.014340, 1.319330, -0.987710, -0.435940, -1.996290, -0.261660, -1.343180, 0.344650, 1.653310,
-2.114720, 0.508590, -1.644760, 0.373340, -0.929070, -0.334880, 2.617290, 0.322340, 2.272610, 1.406700,
-0.332900, -0.391390, -1.003230, 1.325410, -0.421820, -0.462290, -0.243260, -4.143710, 1.434680, 0.385560,
-0.451090, -3.997050, 1.070360, 4.866660, -0.139760, 5.321100, 1.310050, -0.143820, -2.324080, -1.236490,
-2.000350, 0.967320, 0.025510, 1.981140, -1.357770, 1.680900, -1.269350, 0.353630, 0.727380, -1.185220,
-3.133140, 1.667500, 5.465630, -1.905750, -3.983650, 1.160260, -0.684150, 1.809590, -0.692850, -1.523170,
-2.681990, -0.201530, 1.547950, -1.437790, 7.087870, 1.021190, 0.058130, -0.881300, 1.480990, -0.497210,
1.510050, 0.745790, 4.030990, -5.920920, -0.153460, 8.741700, -1.007480, -4.087070, 0.036460, 0.802910,
-0.888060, 2.440650, -2.394020, 2.481610, -2.888330, -0.956200, 0.811810, 3.151990, 3.065190, -0.632940,
-0.006950, 0.407880, -0.503280, -0.115340, 2.300030, 1.404000, -3.929190, -1.539860, 3.185910, -0.049220,
-1.418290, 0.083560, 0.602360, 0.927280, -1.484210, 0.707710, -0.784820, 0.698250, -0.562930, 0.152280,
-0.227070, -0.620100, 0.234750, -2.407610, 1.578610, -0.312190, -0.752170, -0.081720, 0.928060, -2.318100,
-1.179670, 0.310960, -0.908090, -1.012310, 0.204540, 0.557030, 0.841250, 0.044010, 0.965650, 0.472390,
3.273420, 0.324830, 0.960860, 0.618400, -1.212590, 0.142490, -1.416800, -0.093960, 1.381490, -0.654910,
-0.146030, -1.662330, 0.798250, -0.618250, -0.758630, -2.214060, 0.549090, -0.184960, -0.891690, -0.246610,
-1.193790, 0.217510, -1.015150, -1.960630, -0.092030, -0.895840, -0.664210, -0.898310, 1.237300, 0.526660,
1.626760, -0.019200, 1.239620, -0.305630, 0.746520, 0.655440, -1.655190, -0.206060, -3.621640, -1.074150,
0.962590, -2.040310, -0.347930, 1.019320, 1.955950, 0.094830, -0.181760, -1.346260, -0.553030, -0.301530,
-1.191510, -1.511430, 0.208010, -1.121090, -0.194100, 0.646750, -0.134070, -2.034780,
0.940690, 3.493790, 0.206510, -1.494610, -1.124120, -0.694980, -0.054250, 1.944310, -0.263110, 0.613540,
-0.026990, -0.932260, 2.573370, 0.401640, -0.137740, -1.574530, 0.383410, 2.538110, 1.606290, -0.444660,
-1.732870, -0.812960, -2.014340, 1.241170, 0.262540, 0.117500, -1.278660, 0.616150, 1.765050, 0.539470,
-0.043070, 0.651750, 0.063130, 2.076650, -1.102200, 1.230600, 0.826350, 1.781660, 1.479880, -2.509310,
0.900220, -2.029330, 0.793360, -2.211630, 0.754200, 2.915090, 0.140540, 0.063930, -0.278170, -3.758450,
-1.257940, 0.987160, -1.800090, 0.943350, -0.342000, 0.694260, 3.033470, 0.220150, 1.404430, 2.936690,
-0.566880, -1.832570, -2.874460, -1.919190, -2.578980, 0.526060, 0.633640, 1.098460, 0.272620, 0.377600,
0.073740, -1.607260, 1.409610, 0.323590, -1.632870, -0.179350, 1.514110, -3.090880, -2.122280, 1.966500,
0.133180, 0.247060, 0.098690, -0.718330, -0.631840, -0.381700, -2.410860, 0.247590, 0.239830, -1.067820,
0.066560, 0.485100, -0.604310, -0.401760, 1.463790, -1.152500, 1.605160, 0.608680, 1.433190, 1.304140,
-1.714170, 1.131470, 0.670270, 1.845370, 0.574190, -2.424840, 0.813750, 1.320050, 0.205950, -0.872210,
-1.213720, -1.338230, -0.740620, 0.474550, 0.037330, -0.437420, 3.316080, 1.423470, -0.544010, -1.975610,
-0.447800, -0.764750, 3.224870, 0.891840, 2.815110, 2.460820, -0.743110, 0.941720, -1.915210, -1.702680,
-0.492430, 3.482450, -0.564910, -0.088690, 0.333540, -0.714110, -0.060220, 1.574040, -0.581560, 4.240420,
-1.289610, 4.706520, -1.709260, 0.885360, -1.727570, 0.800870, 2.907390, 1.320610, -2.725810, -1.308700,
-0.990230, -3.327180, 0.057910, 0.169830, 0.447750, -0.865570, 2.059170, -1.028310, 0.793430, -2.707540,
0.825080, -1.285550, -1.667100, -0.997210, 1.304550, 1.062580, 2.587360, 0.217390, -2.736230, 2.478160,
0.471430, -1.964150, -3.023800, -1.397120, -3.197520, 1.893540, -0.067550, -1.822670, -0.697660, -3.519410,
0.028580, 1.972200, -1.258290, -0.207320, -0.745780, -0.844740, 1.518510, 2.680660, -0.217830, -0.210310,
-0.186870, -2.819220, 2.259610, 1.591200, -3.162060, -1.329450, -0.981960, -1.090010, 0.612830, 0.867320,
-0.303020, 3.052260, 1.161580, 0.650500, -0.777730, -1.284910, -0.870710, 1.990100, 0.825950, 0.094820,
0.185000, -0.521500, 1.930460, -0.711480, -0.409820, 1.238750, 0.067590, -0.264480, -0.060680, 0.832560,
1.991360, -2.543760, -0.575870, 0.259940, -0.388930, 2.567130, -0.874050, -1.796170, 1.035430, 0.658530,
1.177360, -1.161850, -1.224960, 0.687480, -1.517700, 1.601590, -4.368410, -0.537390, 2.007090, -1.547100,
-1.617410, 0.498170, 1.444970, 0.180160, 1.845980, -1.377880, -0.510730, 0.540530, 0.747390, 1.736080,
1.801030, -4.854480, -1.228670, 5.059260, 0.005940, 0.588940, 0.562820, -2.178170, -1.032290, 2.312050,
1.061480, -0.692960, 0.043920, 0.512580, 2.705350, 0.838310, -1.853450, 1.320610, 0.433810, -1.105600,
0.891160, -0.847690, 2.771580, -1.004640, -0.505370, -3.074190, -1.050020, -1.088140, 0.546840, 3.181950,
-0.650140, 0.022450, 0.970220, -0.596930, 0.547030, -2.233920, -0.211770, 0.062290, 0.770210, 0.532770,
-0.637780, -0.314360, -2.069660, -1.705170, -0.625290, -1.729070, 0.213210, -1.547990,
-2.155980, 1.332510, -0.410340, -0.870250, -1.403320, -0.146860, 1.101730, 0.522380, 2.426450, -0.907930,
0.478170, 0.530070, -0.372380, 0.528840, -0.221160, -1.190600, -0.086210, 2.059580, -0.135460, -1.001200,
0.949320, -0.272790, -1.635020, -1.008880, -1.985340, 0.579130, -0.894640, 0.399340, 0.289300, 1.453850,
1.482150, 0.872830, -0.376910, -0.980200, -0.615950, 1.030180, 1.801180, -0.756550, 1.583970, 1.589240,
-0.307200, 0.630880, 0.268530, -1.299490, 0.348870, -0.633950, 2.068040, -0.883630, -0.218370, 0.546110,
0.419900, 0.737810, -1.431360, -0.612030, 0.094360, -0.583430, 0.526760, -2.134820, 1.705290, -1.169150,
-0.615520, 2.650170, -0.076050, -3.223960, 0.320680, -2.736800, -2.080730, -1.126980, 0.796660, -2.213330,
-1.041040, 1.573910, -1.040900, -1.179900, -0.460020, 0.168920, -0.130950, 1.789200, 1.372500, -1.889320,
0.822730, 0.731440, 3.255380, -0.867960, -1.887140, 0.036820, -1.400880, -0.330870, 2.972320, 0.789680,
0.924500, 1.836570, -0.823380, 1.201600, -0.826950, -0.251920, 0.347390, 0.709020, 2.353770, -0.409450,
1.352570, -3.083860, 1.166980, -1.206680, -0.063640, 0.692640, 1.768000, 0.043040, 0.816170, -1.887990,
-0.653470, -1.738340, -1.080550, 0.554420, 6.160750, -0.304930, -0.497820, -1.392620, -0.575080, 0.761060,
2.306050, -5.044570, 1.469960, 1.646240, -0.627380, 1.320070, -3.429290, 0.794260, 1.742410, 0.786280,
0.864800, -1.906500, 0.118180, 3.277380, 1.042070, 0.295770, 4.213850, 2.407540, 0.095960, 1.202050,
2.863940, 3.037600, 0.266000, -0.507370, -1.237670, 0.464750, -0.795790, 1.798390, 0.595890, 0.097010,
0.814110, 0.465070, 2.443630, 2.133220, 0.567010, 3.195550, -1.304970, 1.100690, -2.661790, -0.353820,
2.502940, -0.566620, -9.449330, 1.512290, 6.367330, -1.215840, 0.151050, 0.514960, -4.697660, -3.193080,
-0.058490, 2.249410, 1.877610, -0.207030, -1.669090, -0.273060, 0.458050, 2.075260, -1.280390, 0.716780,
1.842950, -1.177490, 5.131050, 1.426610, -0.268010, -0.039190, 1.158590, 0.860420, 4.419190, -0.436020,
-3.540890, 2.573990, 1.521650, 0.786400, -3.727690, 0.909320, 0.205720, -2.256920, 0.448770, -0.510650,
1.261410, 1.538840, 1.828990, 0.103250, 1.826290, -0.642120, -1.732180, 0.159140, -6.788790, 0.850110,
1.138470, -1.386810, -1.074320, -0.710820, -0.235000, -2.126480, 1.213610, 1.150740, 1.767060, 1.531690,
0.363980, -2.097210, -0.910380, 1.779660, -0.042640, 5.965990, 2.220730, 0.006140, 0.624970, 0.053680,
0.365110, -3.279210, 0.288600, 2.564330, 0.741470, -1.126710, -2.641150, -0.767790, 1.176820, 0.791140,
-4.621370, -1.209710, -1.693220, -1.657930, 0.692720, -1.372870, -1.395700, 3.024710, 1.699690, -0.053840,
3.069060, -0.430740, 2.150810, -2.124990, -2.621970, 0.520570, -1.267860, 0.092950, -2.954280, -0.806980,
-0.147820, -0.192780, 0.968150, -2.487470, -0.173010, -0.723000, 2.363520, 3.884540, -0.094110, 0.700880,
-1.673310, 0.719390, -4.460910, -0.064940, 0.992530, 0.340640, 2.053620, -0.742240, 2.003840, 0.605930,
-0.744650, 0.171060, -0.891120, 0.145730, -0.946030, 0.977290, -0.358280, -0.791610, -0.410620, -0.232110,
2.091290, -1.529120, 1.524800, -0.168470, -0.165200, 1.119570, -0.206850, 1.926290,
-0.422120, -1.290770, 0.092890, -1.359820, 0.280720, 1.749570, 0.245960, -0.096810, -0.426670, 1.145840,
-1.781010, -0.822540, -2.503980, -0.657170, 0.320020, 0.636900, 3.512980, -1.471270, -0.227960, -1.041630,
0.255040, -0.308610, -1.267630, -0.158470, 0.197010, -2.828210, -1.983340, 0.756960, 0.706860, -0.566380,
0.014020, 1.252670, 0.500760, -1.273100, -0.184540, 0.050980, -1.286940, -0.887030, -1.133380, -0.265420,
0.625950, 0.298610, 3.126000, -0.921380, -0.338310, -1.690790, 2.363690, -0.084570, -0.428810, 1.117220,
0.202640, -0.208880, 1.947000, -2.549490, -0.594530, -0.806640, -0.766270, 0.896020, 0.830810, -0.302650,
-1.212780, 1.430040, 0.670750, -0.851400, 0.366420, -1.448550, -1.341770, -1.177620, -1.571980, -0.431760,
0.721280, -1.261640, -1.066970, 0.110230, 0.168890, -0.138320, -3.531160, -0.061940, -0.188060, -4.306200,
-1.437740, 2.575330, 0.188220, -1.171910, -0.024980, -0.806620, 1.492490, 0.727560, 0.961690, -1.833510,
0.714330, -1.387780, 5.653420, 1.460040, 1.167260, -3.152720, -1.882970, 1.325820, -1.075150, -0.923140,
1.704570, -3.876320, -2.133950, 0.974220, -0.333190, 1.697090, 0.380720, 1.101360, -2.630980, -0.284480,
-0.563150, 1.920470, 2.030470, 0.175380, -2.448880, 1.333510, 3.231470, -2.133460, -1.008160, 2.403430,
1.923880, -2.111270, -0.764730, 0.035160, -2.015940, -4.760720, -0.184170, -0.315490, -0.409870, 0.092150,
0.355010, -0.717210, -0.444180, 1.741650, 0.816900, 0.539350, 2.754850, -1.467860, 0.418880, 0.865220,
-1.387860, 0.248740, 1.372530, -1.792580, 1.373010, -1.195560, 1.023720, 1.234690, -2.300420, -0.772280,
-0.028760, 2.520060, 0.227510, -0.787200, -0.638410, -0.081820, -1.454240, 0.072880, 1.495470, 0.801770,
-4.248940, 0.913740, -1.143640, 2.323410, 1.179040, -1.487460, -1.553250, 0.722660, 0.240190, -0.349440,
1.508200, -2.350380, 0.391530, 0.233300, 1.495150, 0.718220, -0.319490, -1.725420, 0.380390, 0.080240,
1.500770, -0.690440, -0.096430, -2.707680, -1.123330, -0.560160, -1.813830, 2.447220, 0.934700, -0.438100,
-0.704040, 0.843780, 0.165350, -1.479420, -0.820400, 0.027360, 0.362740, 0.023820, -2.157720, -0.430640,
-0.897920, 0.049380, 0.006680, -0.580370, -1.051780, -1.060780, -1.471860, -0.957390, 0.793130, -1.412760,
-1.767840, -1.040360, -1.884600, -1.822260, 0.449600, 0.225150, 0.519530, -0.072600, -1.961570, 1.112160,
-1.356540, 1.106760, -0.099980, 1.773330, 2.149450, -1.733620, 1.030920, 0.618400, -0.030770, -0.735930,
-1.017150, -0.984810, 0.468440, 2.510830, 0.967520, -2.097840, 1.806690, -0.788990, -1.836410, -0.561110,
-0.313440, -0.032100, -1.131560, -2.855460, -1.549060, -0.891090, -0.204310, 1.770430, -1.230510, 0.176700,
-1.001620, -0.662840, 1.281900, -0.428720, 1.048790, -0.731470, -1.681800, -1.057060, 2.935480, 2.622000,
0.472920, 0.381140, -0.343920, 0.220650, 0.939110, 1.674210, 0.248760, -2.230170, -0.286630, -0.761440,
3.609710, -3.767460, 1.864320, 0.991140, 2.418940, 0.010060, -2.312480, 0.709040, 1.634910, -4.016580,
1.124740, -4.053090, 1.091340, 2.616620, 0.947350, -1.110590, 2.727950, -1.090200, -0.484950, 0.941910,
-2.408110, -0.363580, -1.249720, 0.546520, 0.483100, 0.735320, -2.281720, -1.653730,
-0.163840, -1.528540, 0.976130, -0.606950, -0.973250, 2.579170, -0.537590, -0.622800, -0.570840, 0.861340,
1.316550, 0.154340, 0.203990, -0.080830, 1.131480, 0.405650, -0.233350, 0.876160, 0.717980, -0.894080,
2.213610, 1.003970, -2.453100, 1.316070, -0.424830, 2.327660, -0.801040, 0.864790, 0.765290, -2.777230,
-1.420620, 1.234560, 1.347950, -1.976250, -1.525410, -1.416060, -3.075260, 1.382930, -0.150120, -2.376550,
0.934990, 0.028500, -1.170670, -0.268010, 3.067130, -1.731630, 5.980500, -0.217240, 0.554840, -0.089590,
-3.567060, -0.885570, 1.596150, -1.835700, 0.279450, -2.866020, -0.496820, 0.256210, 2.776990, -0.244720,
-0.904460, -2.738360, -3.512910, -1.738140, 1.100990, 1.132190, -0.972500, -0.146530, -0.426080, 1.591270,
1.953240, -2.639730, -0.857910, -0.686230, -0.108650, -2.676490, -1.566870, 1.582530, -2.438580, -1.024360,
-1.279080, 1.427020, 2.914720, 1.076690, 1.070140, 2.744950, 0.998440, -0.284680, 1.636510, -1.820490,
4.707100, 0.549910, -0.515160, -0.038770, -0.302880, 0.007050, 2.435390, 0.310100, -0.821620, -0.282970,
0.044810, 1.032860, 0.231480, 2.569290, -2.174370, -0.645790, 0.648090, -0.011590, -0.517500, -1.552570,
1.885120, -0.737550, -0.469430, -0.419160, 0.085140, -1.081480, -2.183300, 2.216690, 2.152120, -2.693570,
-2.362030, -0.482930, -0.386700, -0.208020, 1.266540, -2.372490, -0.300700, 0.260800, -1.272510, -2.396410,
0.071040, 2.187500, 0.721410, -1.272990, -3.268230, 1.142370, -0.591270, 0.230140, -2.741510, -11.215750,
0.835030, 0.174920, -1.246780, -1.931120, 13.639850, 0.417320, -1.412040, -0.341130, 3.137690, 0.683020,
0.833920, -3.389790, -2.647250, 0.018870, 3.045190, -0.249170, 0.169090, -1.388480, 1.156260, 1.833220,
-0.995490, -3.528300, -7.401520, -2.186440, -1.061210, -0.448900, -0.242510, 0.008520, 0.875980, -1.541790,
-1.308920, 2.641320, -0.583370, 1.083710, -2.728130, -0.171040, -0.631210, 3.138230, -0.645070, -0.192110,
-0.150900, -0.326230, 0.953760, 1.322030, 1.127290, 0.457390, -0.894370, 0.312220, 1.477950, -0.377340,
-1.226350, 2.830800, 0.563570, -0.093300, 2.355940, 1.534070, -2.021190, -2.362160, -0.659410, -1.025080,
3.139630, 0.667740, 0.201550, -0.745840, 1.360750, -1.133280, 2.074220, 1.441550, -0.363760, 1.004980,
0.383700, -2.310120, 0.625080, 0.088360, -0.330380, -1.434080, -2.330320, 1.486710, -0.389110, 0.510020,
1.021230, 1.977530, 0.875250, -0.141350, -0.088510, -1.578960, -0.104420, 1.708840, 1.536370, 1.420160,
1.570660, -4.306870, 1.385060, 0.222910, 0.781450, -0.149390, 0.723610, 0.180570, 0.061820, -0.226620,
2.457890, -1.376570, 0.354010, -1.211460, -0.702880, 0.270240, -2.184550, -1.990920, -1.488560, -0.952840,
-0.768200, 0.769870, -2.681210, 1.524300, -1.762270, -0.339990, 0.519230, -0.814870, -0.702430, 0.267490,
1.349200, -0.052800, -0.216550, 1.181200, 0.776970, -1.376100, 2.343550, -0.929400, 1.075220, -1.069780,
-3.000550, -0.780190, 0.357530, -1.312510, -2.581900, -0.337520, 0.042520, -1.224680, -0.076450, 2.325480,
-1.760230, 0.666590, -0.812210, -0.157650, 0.071610, -1.015400, -1.664970, 0.468170, 0.034380, -2.811950,
0.076660, -2.374770, -0.612830, -0.676270, 0.182260, -1.736110, -0.375100, 0.176630,
1.567110, -0.842060, -1.657020, -0.662810, -1.394330, -1.963940, 0.298810, 0.235880, -0.989620, 0.175580,
0.908030, 0.171180, 1.014980, 0.061070, -0.768790, -1.699420, -1.339040, 0.689250, 2.541350, 1.296800,
-0.418250, -0.401540, -0.755900, -0.160420, -1.322230, -1.558100, -0.071840, -0.682570, 0.791830, 2.078230,
-0.347140, -1.443020, 0.850860, -0.518650, -1.185620, -0.526070, -0.222860, 0.681040, 1.273790, -0.348900,
-0.871710, 0.301590, 1.564680, -1.569020, -2.441340, -0.525210, 0.978610, -2.396120, 0.296180, -0.000020,
2.236910, 0.863670, -0.835400, 0.041010, 0.099570, 1.244000, 1.465140, -1.478560, 0.510420, -1.173290,
-0.139120, 0.055400, 0.574560, 0.836980, -0.295800, 0.682710, 0.641160, -1.396000, 0.771240, -0.181200,
1.346950, 0.872300, -0.383690, 0.414020, 0.873670, -0.532790, -0.228010, 0.888410, -0.280280, -1.102090,
1.342520, -1.125860, 0.410860, -2.058540, -1.566920, -0.714880, -0.785430, -0.318110, -0.104010, 1.558660,
0.486360, -0.103770, -0.079590, 1.523680, -1.408300, -2.023750, -1.372490, 0.121970, 1.340790, 0.534390,
-0.265420, -2.297760, -2.683740, 0.537440, -0.049270, 0.807890, 0.054870, -0.130860, -1.526950, -1.475560,
1.822120, 2.459970, -3.180420, -0.347240, -1.675800, -1.085890, 3.450100, 0.423450, -1.779420, -0.130170,
-0.521560, -0.256800, 0.630460, 2.821420, -1.856530, -2.534070, -0.765590, -0.531970, 2.731330, 0.597710,
-1.234000, -0.268920, 0.024080, 0.662210, -2.188280, 2.581910, 0.547930, -1.712160, -1.570750, -0.421520,
1.047940, 1.264790, 0.286610, 0.438370, 0.346620, 1.113150, 1.875000, 0.685890, 0.102050, -0.388380,
0.255590, -0.657740, 0.857210, 1.160310, -0.717430, -0.143520, -1.776520, -2.197760, 2.947670, -1.456860,
-0.278600, -0.777150, 0.116200, -1.480280, 3.562540, -1.297230, 0.046720, -0.510860, -0.291250, -0.142730,
-1.576250, -0.325500, 0.551050, -1.572970, -1.117080, 0.294670, 1.674560, 0.076670, -0.686610, 2.064740,
-0.300280, -0.995760, -1.263470, 1.496550, 1.257230, -0.048410, 2.287930, 2.201080, -1.265540, 0.913300,
-1.439440, 0.408350, 0.009230, -1.327170, -1.374760, 1.116980, 1.329640, -0.585640, -0.729540, 1.061070,
2.837240, -1.611060, 0.924210, -0.591740, -0.653250, -0.279960, 1.641760, -1.347860, -1.014040, -0.087270,
-0.338590, -0.789600, -0.518930, 1.557440, -0.897380, -2.069980, -0.592340, 0.460830, -0.304730, -2.020410,
-0.834880, -3.274540, -0.466390, 2.510680, -1.190660, 0.866800, 1.115450, 0.431070, -6.051400, 0.463720,
-0.668560, -1.684500, 0.714670, 0.401110, 0.054910, 0.614830, -0.275200, -0.089460, -1.447420, 2.115170,
-1.497670, 0.412420, -1.400710, -1.161070, -0.737580, 0.693620, -0.151830, -1.915080, 0.152560, 1.108840,
-0.443500, 0.246080, -0.848770, 1.281090, 1.772970, -1.615860, 0.809040, -0.783940, 0.623560, 1.380650,
0.469020, 1.005020, 0.014610, -2.376860, -1.292080, -0.900360, -1.027270, -1.574750, -1.095120, 1.075520,
-1.074850, -1.591250, -0.415290, 0.657520, 1.562800, -0.632550, -0.041050, 0.027660, -0.642950, -0.832040,
1.186350, -1.644010, 0.897830, -0.665620, -1.121900, -0.473950, -0.151010, 0.544590, 1.003110, 0.742250,
0.409340, 0.042030, -0.618990, 0.313830, -2.113560, 0.512260, 0.867080, 0.607770,
0.105530, 2.404520, 0.836250, 1.715460, 0.003260, 1.405740, -0.199330, 0.289810, -0.144640, -0.469130,
-0.143570, 0.755070, 0.777590, -0.154320, -0.814180, 2.304360, 0.558890, 0.656080, 0.881840, 0.657110,
0.659810, 1.399070, -1.328610, 0.219630, -0.531420, -1.092440, 2.756200, -3.468690, 1.788890, -0.290240,
0.814740, -1.558290, -0.799510, -0.496080, 1.577900, -0.122970, 3.731910, 1.632600, -2.833810, -0.241570,
-1.776050, -0.294320, 0.609020, 1.267610, 0.263590, 1.729660, -0.940220, 1.333320, -1.122920, 0.063590,
-0.688990, 0.255440, -1.137020, -0.215230, -2.084810, -0.496990, -0.283500, 2.743480, 0.169200, 0.413390,
-0.386060, -2.028290, -1.274360, 0.878220, 2.052350, -0.744830, -0.956670, 2.363650, -2.033080, -0.053430,
-0.352030, 0.931540, 0.902240, 0.378300, -0.019050, 0.785270, 0.754320, -3.548900, 0.455530, 1.824110,
-0.195140, 1.722920, 3.985770, 1.171200, -1.595810, 2.487250, -2.170780, -4.551530, 2.904040, -0.505590,
0.173560, 2.210390, 0.075000, -3.801120, -0.410150, -1.346510, -1.212010, 1.081130, 3.007160, -0.506460,
-1.735090, -0.570300, 2.212700, 1.731310, 0.177150, -2.086250, 0.297920, 0.775930, 2.344090, -0.970800,
-0.063500, 1.580370, 0.749280, 1.223570, 0.205970, 0.762860, -2.311270, 0.080580, -1.124740, -2.038720,
2.329480, 2.494890, 0.451990, 0.700870, 0.557190, 0.005720, -2.134190, -0.680340, -3.368910, -3.456280,
2.687910, -1.059810, -1.183290, -2.662900, -2.126640, -1.079990, 0.156660, -0.191790, -0.411900, -2.929370,
-0.624600, 1.139980, 0.295310, -0.050420, 3.200340, 0.613340, 1.223210, -0.575160, 4.460900, 0.546480,
2.468030, -1.986520, -0.869800, 1.145940, -0.447490, 0.667120, 2.617850, 2.594410, -0.517600, 0.500680,
1.686380, 2.916810, -2.424030, 0.334210, 1.982190, -3.547550, 1.785130, -1.577830, 0.993840, 3.894130,
2.098400, 2.420680, 0.926130, 1.767560, -2.888180, -2.826700, -0.692760, -0.374530, -0.938770, 1.598430,
-0.796060, 0.732340, -0.081690, 2.947960, -0.065100, -3.508030, 1.004270, 0.527840, -0.636000, 0.067110,
-0.447860, 3.475650, 2.478570, 1.723110, 0.250220, 2.550690, -0.690880, 0.550930, -0.375090, -0.949470,
-0.447990, -0.500230, -0.350500, -1.441500, -0.774060, -1.148310, -0.914320, 1.693020, -1.690320, -0.494960,
2.105960, 1.852980, -0.808890, 2.003110, -2.062760, -4.142750, -0.097720, -0.855260, -0.380540, -1.706500,
-2.964390, 1.572440, -1.095920, 0.707030, 1.914230, -0.793040, 0.066060, -1.366340, 0.035300, -0.478790,
-1.460810, 2.287090, -1.712710, -3.151460, 0.557960, 2.294630, 0.188730, -2.122660, -1.204620, 1.244400,
3.473760, -1.689510, 1.862550, 1.060510, -2.147540, -1.903880, -0.571200, -1.082830, 0.106140, -0.521670,
2.899540, -1.362180, -1.739170, -1.230700, 0.002070, 0.030910, 0.813710, -2.212700, -1.830790, -0.751640,
0.504070, 0.705730, -2.956060, 0.747100, 2.923520, 1.574820, -1.620780, -2.446910, -3.360120, 0.593750,
0.722170, -0.483420, 2.556210, -1.044980, -0.159280, -0.877110, -4.207550, 0.415770, 2.163110, -5.482870,
0.442130, -0.720980, -0.786530, 0.350600, 2.487970, -2.738030, -0.747170, -0.702850, -1.157150, 1.223990,
0.072770, 3.396610, -0.167830, -1.142650, 0.506200, 0.295500, 0.031340, -0.628500,
-0.877650, 0.418790, 0.917250, 0.315750, 0.277100, -1.785890, 0.326200, -2.593520, 2.800130, -0.712850,
-0.340120, 0.578460, -1.566280, 1.044390, 0.949430, 0.506920, -1.598580, 3.441340, 2.399960, 1.522630,
1.692120, -0.593410, -3.986850, 1.187740, -1.111240, -2.006660, 0.792860, 0.168970, 1.152220, -1.008440,
-0.300310, 2.102860, -1.773740, -0.604980, -0.431550, 0.412410, 0.803330, -0.975150, 2.097170, -2.261650,
-1.539380, 1.516850, 2.427630, -0.045640, 0.485120, 0.283760, 1.974660, -0.658730, 2.020140, -2.106490,
-0.751580, -0.727110, -0.069750, 2.022640, -0.535470, 0.212710, 1.854620, 0.758900, -1.761380, 0.939510,
1.247840, 0.501890, -1.328970, 0.351510, 1.929020, 0.368160, -1.029270, 1.565780, -0.203600, -2.033890,
1.234770, 1.395850, -0.362690, 0.195110, -1.284970, -0.692160, -0.701360, 2.153280, 0.639730, -1.855470,
-0.237880, -1.098640, 2.242380, -1.009590, -1.517080, 0.300000, 0.436240, -0.158380, 0.785100, 1.603770,
-0.097800, 0.717730, -1.523350, -0.707710, 0.563870, 0.855100, 0.432390, 1.194670, -0.306650, -1.446760,
1.729690, -0.345250, -0.030300, 0.883850, 0.819070, 1.611200, 0.420680, 1.502360, 0.277890, 1.011640,
0.958830, 0.776090, -1.850550, 0.061610, -1.819230, -2.769130, -1.941690, 2.719570, 5.808390, -1.507270,
-4.588740, -2.405140, -1.498310, -0.905830, 0.987230, 0.933010, 2.208780, 1.187520, -2.334890, 0.066550,
-1.452220, 3.769130, -1.170230, 1.404630, -1.023850, -1.782960, -0.158380, 0.672630, 0.074310, -2.684310,
1.538710, 5.203280, 0.947690, -1.835710, -0.117570, -0.515800, 0.111380, 2.487110, 5.663940, -2.143180,
-0.111300, -10.489670, 0.481250, 2.285260, 2.564070, 0.408970, 2.090300, -0.183470, 0.452150, -3.565490,
1.820360, -0.183250, -6.789800, -0.088580, 4.538430, -1.788480, -3.112590, 1.294830, 1.800940, -2.307880,
0.191850, 1.526790, 0.183550, 2.342380, -4.429710, -6.082870, 1.329000, 0.447640, 0.845330, 5.378880,
2.044750, -1.285360, 4.557350, 2.085840, -2.588000, -6.378680, -0.944700, -3.108470, 3.067010, 4.384920,
0.076700, -0.002130, -1.240710, 0.173580, -0.635530, -1.533890, 0.337490, -0.331160, 1.000120, 0.978000,
0.899420, 0.730960, 0.706290, 0.227350, 1.407360, 1.435010, -0.800500, 0.251930, -2.242670, -0.610510,
2.494730, 1.567890, -0.734910, -0.007060, 2.540840, 0.302080, 0.309630, -0.714670, -0.093470, -0.648590,
-0.681540, 0.859960, 0.359740, 0.247680, -1.122130, -0.131990, 2.981290, -0.925850, -1.104790, 2.206380,
-1.378760, 0.010490, 1.888960, -1.707410, 1.917740, 0.862490, -1.131700, 0.362260, -0.709470, 1.042200,
-2.333100, -0.636600, -0.187210, 2.770150, 0.201340, -0.865140, 0.818960, 0.840860, 0.896530, -0.168270,
3.703470, 1.618940, -3.217720, 0.441730, 0.392790, 1.372580, -1.839300, -2.960440, -0.786890, -1.247840,
-1.968570, 1.811780, -1.630590, 0.254140, -3.643380, -0.166340, -0.555880, -1.029340, -0.642710, 0.430930,
-1.151950, 0.376820, -0.509070, 0.047070, -1.331340, 0.320220, 1.403500, -0.589070, -4.762850, 1.716170,
-0.263440, -0.793550, 0.762310, -0.300240, -1.171220, 1.339370, 0.308360, -0.285930, 0.362820, -0.151420,
1.324440, 0.958740, 0.433950, 0.077070, 0.717860, -0.222280, 1.277960, 0.299050,
-0.482690, 0.248950, -1.115400, 0.706630, 0.863320, -1.654660, 0.605480, 1.681790, 1.981590, 1.178200,
-0.108700, 1.423510, 1.062950, 0.914130, 0.777140, -2.922230, 0.641190, 1.564610, 0.758370, -0.456780,
-0.174680, 0.164800, -1.650470, 1.683820, -0.947240, 0.582630, 1.667380, 0.754260, 0.287120, -0.800670,
-1.602840, 1.681630, -1.388190, 0.036420, 0.135150, -1.272480, 1.157470, 0.384380, 0.886910, -0.573500,
1.138650, -0.275650, -0.383510, 0.437730, 1.653490, -1.727420, 1.296910, -0.372200, 0.965880, -0.853150,
-0.046650, 0.438720, -1.759360, -2.192100, 1.756820, -2.339560, -0.246340, -1.113320, -0.392400, 0.436400,
1.110720, -0.484480, -0.364900, -0.174530, -0.245200, -3.301730, 1.315450, 2.156550, -0.565440, 0.877740,
0.671270, 1.359130, 0.424790, -0.773840, -1.079710, -0.670720, -0.191270, 0.420010, -1.978390, -4.041310,
-0.284510, 1.006660, -0.096800, 1.329820, 1.023220, 1.248290, -1.012910, -0.121370, -0.817730, -0.026080,
1.948820, -0.880320, -0.323170, 0.535500, -0.678470, 0.314860, -0.938160, 0.101430, 1.749250, 0.384470,
-1.279850, 0.316770, -0.399650, -1.487440, 2.454430, 1.124350, 1.006320, -0.872360, 2.497410, 1.949550,
-1.597010, -0.816290, 0.695470, -2.978330, 1.254900, -2.993730, -0.793020, -0.345660, 2.360000, 2.040890,
-2.419210, 0.681720, 1.772780, -0.168260, 0.061400, 1.812110, 1.297940, 1.095520, -0.891620, 0.965110,
-0.795380, 2.380250, -0.662080, -0.461360, -0.408700, 0.032250, -0.886240, -0.624810, 1.527610, -0.465540,
2.330700, 1.856150, 0.164510, 1.340220, 1.156960, -1.588210, -1.746530, 2.639600, 3.624780, -0.504990,
-0.164030, -1.017530, 1.225750, -1.453030, 0.413890, 0.594290, 0.239270, -1.446910, -0.914410, -1.140090,
-0.472830, -1.664680, -0.905250, 1.903670, 2.610410, 0.284140, 0.071160, 0.768430, 0.648040, -2.106540,
1.274830, 2.992020, 2.452290, 1.020230, -1.774580, -0.884720, -0.764770, 1.195300, -1.217720, 1.055930,
-1.631800, -1.886040, -0.293220, 2.167280, -0.103190, -0.928620, 0.091470, 2.527580, 1.374590, 1.238460,
0.026360, -0.261420, 0.979440, 0.809430, 3.361350, -1.529170, 0.444740, -2.542540, 2.136740, 0.147360,
-0.639890, -0.404820, -1.172360, -0.212090, -0.331870, 2.039620, 1.216580, -0.363070, -0.978990, -0.646250,
-1.359870, 1.227840, -0.265430, 0.227920, -0.807860, 1.489070, -2.761740, 0.277970, -0.777540, -0.166310,
-0.188900, 0.215360, -1.431420, 2.119950, -0.928360, -1.485800, -0.695630, -1.801810, 1.138280, 0.776670,
-0.703810, 1.290530, -1.208930, -3.927870, 1.208130, 1.483890, -0.456340, 1.734080, 2.758000, -0.775690,
3.104600, 0.674840, -0.691790, 0.221500, 0.824680, 0.900480, -0.937580, -0.868980, -1.345870, -0.552870,
0.992270, 0.380150, -0.219180, -1.222800, -1.414490, 0.152430, 0.647360, -0.248420, 1.248820, 0.744170,
-0.128270, -0.006810, 0.804270, -0.231120, 2.097360, -1.899280, -0.232270, -0.734060, -2.278300, -0.869410,
0.538860, -0.053470, 0.542420, -2.463480, -13.649080, -2.178580, -0.728440, -2.404800, 1.442110, -1.025790,
-1.339130, -1.021880, -0.359570, -0.128000, -0.947460, -1.427630, -1.251720, -1.118900, -1.817000, -0.657360,
-0.106740, 1.125600, 0.498130, -1.625750, 1.036140, -1.330550, -0.635050, -1.923910,
0.393670, 3.695460, -1.056950, 1.479460, 0.035740, -0.865050, -2.015460, 1.722210, 1.507710, -0.147130,
0.246640, -0.486180, -1.257380, -2.633540, 1.648880, 0.590520, 0.012260, 0.852780, 0.350400, -0.904570,
-2.243680, -0.767230, -1.477480, -1.594360, -1.673770, -0.316020, 0.067950, -2.052820, -0.345540, -1.023810,
0.106830, -0.728990, -1.157240, -1.361050, -4.004380, 1.128420, 0.260340, -2.166030, -0.123240, -2.168020,
2.606940, -0.816170, 1.734430, 3.584540, 1.442960, 2.689690, 0.254770, 0.786570, 1.163080, 0.044050,
-0.164960, -2.669990, -0.537120, 2.118800, 0.634840, 0.183420, 1.401440, -2.372880, -0.555110, -0.143980,
0.337100, 1.822350, -2.881220, 3.135300, 0.503110, -0.695690, 0.326910, 2.566490, -2.376840, 0.399700,
1.709950, 0.431860, -0.739670, 0.868550, -3.621490, 2.540200, 0.103930, -0.408060, -0.636430, -0.297460,
0.195840, 0.653830, 0.852870, -1.774680, 1.972760, 0.314630, -0.686670, -0.544470, 0.287290, -1.205140,
0.534650, -1.234230, 2.373310, 1.201530, 2.094180, 1.143130, -2.470530, -3.925460, 0.619010, -0.519060,
-0.267770, 1.782560, 3.575900, -0.659620, 0.268940, 1.033080, 2.345030, 1.440590, -0.208360, -1.733860,
0.477260, 1.723170, 1.432820, -1.279490, 1.431510, 1.853100, -0.257310, -0.606010, 0.648010, 3.265550,
-1.147420, 0.433630, 0.117950, -6.145400, -0.105800, 2.933710, 0.135790, 0.739660, -1.835630, -0.141650,
-0.694960, 0.382860, 2.343540, 0.101070, -0.035460, 1.307610, -1.972150, -1.793100, -0.096600, -1.484450,
1.120600, 1.816560, 0.979100, 0.644540, -0.013890, 2.215240, -2.275670, 3.157990, 3.725180, -0.968260,
0.099360, -2.930450, 0.233320, 2.940900, 1.112320, -0.836910, 3.057580, -0.705290, -0.101700, -5.312420,
0.363690, 1.850050, -2.822630, -1.300110, -0.067380, 0.364600, 1.171530, 1.668470, 0.271330, -3.379350,
0.527650, 2.900430, 1.369170, 0.672320, 1.353680, 1.078040, -0.872550, 1.513060, 1.401410, -1.478460,
0.613080, -1.561610, -1.321570, -0.994780, 0.408890, -0.955070, -1.030420, -2.962970, -3.010280, -3.230270,
0.291150, -0.471950, -2.092350, 0.605450, -0.713360, 0.793750, 1.896970, 0.725060, -1.342310, -0.005370,
2.703340, 1.705840, -0.334980, -2.798560, -0.026560, -0.449700, -1.066070, -1.851030, -0.959460, 0.516170,
-0.828180, 1.024570, -0.432540, -0.339670, -0.417780, 3.277960, -0.055710, 2.322850, 0.196060, 1.813900,
0.388620, -1.496850, 1.737910, 0.770340, 0.018350, -1.106750, -0.100180, 0.174630, 3.190680, 0.574370,
-2.307240, 1.722220, 0.571200, -3.523330, 0.217770, -0.722730, -0.276380, 2.849250, 2.009920, 1.247780,
-0.447310, -2.210710, 1.015310, 0.246920, 1.382270, 1.207890, -1.161050, 0.137090, -1.988510, 0.128850,
2.005430, 0.391530, -0.368160, -0.007890, -4.098210, 0.793120, 1.702500, 0.670740, 0.377560, -1.508290,
-0.198900, 3.206300, 0.228890, -3.628060, -2.568860, -0.328410, -0.425760, 2.250200, -0.592370, -0.954010,
-3.763620, 2.756760, -1.827380, -0.062880, 0.461950, -1.359590, 0.671570, -1.260120, -0.338000, 0.701130,
-1.368520, 2.487310, -3.012530, -1.034740, -2.550560, 1.287100, -5.728790, 1.276070, -0.226600, -1.301230,
1.043330, -1.362400, 1.896960, -0.465090, 0.334420, -1.479300, -0.372110, 0.279610,
-1.225850, 0.388910, 5.416930, 0.417980, 2.762260, 1.733840, -0.306240, -1.924090, -1.007980, -1.235960,
-0.480390, 1.513160, -0.085670, -2.367370, 1.031280, 0.046900, -0.226190, -2.649020, 1.012590, 1.775760,
-1.415130, 0.202200, -3.104860, -0.713570, 0.624320, 1.335480, -5.071550, -0.620810, 3.326130, 0.510810,
0.339110, -1.368780, 1.383640, -0.225500, 2.194640, 0.840880, -1.027430, 2.847630, -2.474120, 1.016740,
-0.475310, -1.766990, -1.306330, -0.790370, 0.534950, -2.051680, -0.651840, -1.398860, -0.369450, 0.560420,
-0.283120, 0.034900, -0.072850, -0.474200, 2.179520, -0.802770, 2.139720, 0.237160, 1.428880, 0.694500,
-1.136470, -1.209770, -0.436630, 0.768730, 1.413220, 1.577290, -0.696830, 0.262890, -1.036450, -0.218670,
0.561990, -0.204610, -0.370900, 1.448320, -2.138070, 2.790130, 0.222370, 0.464580, 1.333370, 0.779670,
0.518250, 2.243260, -1.080120, -0.272460, 0.102320, -0.612450, -0.508610, -2.942970, 1.043440, -0.617410,
0.227600, 0.484230, -0.428380, -3.376340, 2.870550, 0.761370, 2.525790, -0.810410, 0.004890, -0.654240,
-0.937740, 1.565470, 0.593550, -0.910490, 0.101030, -0.773440, -1.796030, -0.064330, 0.841150, -0.108790,
2.915760, 2.416320, 0.080690, 1.115140, 1.418600, 1.331070, -2.430140, -0.734170, 2.405970, -0.905340,
-0.268670, 1.656690, 0.552660, 0.192140, -1.041430, -0.784920, -2.329780, -0.089690, -0.991110, 0.655400,
1.119420, -0.797970, -0.269030, 1.953230, 3.575300, 1.086840, -0.413990, -0.217320, 1.944090, 0.508690,
2.291270, -0.479050, 1.512240, 0.380700, -1.740300, -0.789200, 3.174810, -1.438440, -9.643990, -0.396300,
-0.706960, 0.555810, -2.233320, -1.604480, -3.151510, 0.166970, 1.386160, -0.899870, 1.407590, 0.873960,
-0.781770, 0.749070, -0.600560, -0.915410, -0.328570, -0.157440, -2.196600, 0.117600, 0.564450, 1.354680,
-1.643940, -4.258690, -1.013950, -0.826070, -1.462430, 0.622890, -0.013670, -1.295860, -0.130980, 2.554140,
1.769750, -0.826140, 1.117230, 0.509740, -1.596040, -0.822040, -1.012590, 1.045870, 1.091950, 0.556880,
0.289960, -2.237090, -0.695180, 2.928860, 0.971410, 2.748560, 0.176750, 1.119800, 1.171960, -0.792650,
1.356120, 2.903510, 0.260760, 2.282530, 1.089020, 1.124610, -0.505200, -0.935870, -0.125050, 0.812380,
1.478260, 1.856040, 2.601540, 0.750900, -1.304110, -0.638450, 2.208180, -1.515600, 0.370830, 0.730420,
-0.793940, 1.443570, 0.920560, 1.248510, -0.844290, 1.954660, 0.545500, -2.150910, -0.395060, -0.738630,
1.876010, -1.353770, -1.080310, 2.019810, 0.357300, -0.541530, -1.014970, -6.735430, -1.541480, -0.615910,
-1.261490, 1.711190, -0.397420, -2.189660, -0.236750, 0.472870, -0.355750, 1.260670, 5.710470, 5.955280,
0.835200, 1.435370, 2.094650, -3.790930, 1.839150, -3.009200, -0.844730, 1.310140, -1.963670, -6.510010,
0.410430, 1.647790, 1.152110, -2.130010, 0.766260, 0.498810, -0.731410, -1.778220, 1.364740, 0.647060,
-3.338620, -0.854050, 2.542690, 0.178470, 2.215860, -0.155600, 0.413050, 0.203910, -0.946440, 1.106480,
-1.208890, 0.421220, 0.398960, -0.290410, -0.101190, 0.507870, -0.420990, 1.059930, 0.842880, -0.616810,
-0.347140, 1.210880, -0.405130, 0.370010, -0.838430, 0.173220, 1.093950, 2.196560,
-1.285920, -1.248560, 1.027520, -0.488450, 1.978200, -0.285900, 1.105500, -0.041070, 1.518220, 0.025950,
-1.239730, -1.277290, 1.254290, 1.355910, 0.487380, -0.038330, 0.311250, -1.107490, 0.576650, -2.024490,
-0.185600, 1.722430, 2.403660, 0.165550, 1.297590, 1.087210, -0.110980, -1.721000, -0.349710, -1.528550,
1.019360, -2.120650, 0.718650, -1.572490, -0.611820, 0.261040, 0.027870, -0.698080, -1.351430, -1.051770,
-0.411380, -0.993410, 0.716860, -1.005990, 0.365000, 1.402570, 2.519580, 0.472740, 1.145440, 1.167270,
0.188220, -0.557440, -1.416550, 1.828810, -1.015850, -0.163600, 0.649100, 1.522750, -0.420040, 0.898060,
0.271610, 0.904000, -0.750270, 2.147160, 0.316750, 2.159380, -1.476450, -0.705930, 0.638990, 0.442560,
-0.044710, -0.169990, -0.025110, 0.114580, -0.641350, -0.784580, 1.332290, 0.803390, -0.011370, -1.782980,
-0.087210, -0.114820, 1.413210, 0.928130, -1.200180, -0.545660, -0.850800, 0.288450, 0.976610, 3.012880,
0.323110, 0.743210, -1.121860, -0.826520, -1.557450, 0.972210, -1.052180, -2.636320, 1.196280, 1.812490,
-0.780770, -3.909870, -2.051690, 0.624870, -0.570180, 2.672430, -1.104280, -1.251390, -0.329240, 0.257690,
0.304040, -1.670600, 1.095490, 1.193460, 2.317970, -3.022570, -0.172020, 1.364020, -1.434520, -1.741770,
-0.430880, 2.312870, -0.037500, -5.423260, 1.890720, 5.159350, -0.009950, 0.021100, -0.515280, -0.478640,
2.022460, -1.425130, 0.798820, -3.322700, 1.300990, -1.016740, 0.090310, 1.532400, -0.702770, -0.759730,
-0.114560, -2.335120, -0.375280, 0.867020, -0.849830, 1.540500, 0.466530, 0.306280, 0.526420, -0.548320,
-1.621460, -3.580850, 1.438100, 1.923900, 2.618900, 3.908490, -2.237240, -1.964330, 0.368820, -0.209200,
0.382700, 0.705780, -8.409340, 2.174310, 0.966690, -0.599570, -0.942380, 1.202490, 2.348610, 2.525060,
0.521450, 2.714840, -0.672640, -0.556860, -0.914570, 1.574160, 2.707350, 0.571840, -0.228280, -2.875150,
-0.656290, -0.930080, 0.327650, 2.897560, -1.611940, -3.791520, -1.109100, 1.569000, -4.411820, 0.042490,
2.145000, 0.079180, -1.278090, -1.000910, 2.452690, -0.296320, 0.815840, 0.742530, -1.412460, -0.694870,
1.316130, -3.175870, -0.711170, 0.191790, -3.002270, 0.242800, 6.412910, 1.782400, -3.835780, -4.385630,
0.128200, -0.982080, 0.834140, -0.981890, -0.563240, -1.574060, 1.746340, 4.556820, -1.484160, -0.016910,
1.051020, 0.428980, -0.094720, -0.077510, -2.244330, -0.245660, 0.039040, 0.695600, -0.213260, 2.978030,
3.830410, -1.516960, 1.982410, -1.160770, 0.940710, 1.364900, -0.197880, -0.200020, -0.707970, -0.338680,
1.014420, 0.289550, 0.729150, 1.580720, 1.015250, -0.123740, 0.420460, 0.061130, -1.151300, -0.528760,
-0.694570, -1.637180, 0.746210, -0.617800, 0.709860, 1.523290, 0.242510, -0.956310, 0.473480, -0.452350,
0.273060, 0.941890, 0.494160, -1.133230, -5.082820, -0.488940, -0.422760, -0.663010, 0.405340, -0.508170,
-0.247120, -0.503420, 3.490920, -0.401270, -1.824780, 0.578320, 0.607610, -0.413100, 1.871100, -4.343300,
0.311120, 0.793220, 0.901530, 1.461740, 1.779590, 0.994010, 0.911710, 0.051700, -1.249590, 0.899910,
-0.379070, 1.725790, 0.015110, -1.269500, 3.325880, -2.440260, -0.322300, -0.716360,
-1.667820, -0.148300, -0.751330, -0.365470, 1.675970, -3.746820, 0.256690, 0.780860, -0.053100, 3.359970,
1.051420, 1.056190, 0.122800, 0.399340, -1.335400, -1.976420, 0.646300, -0.107610, -1.606340, -1.116880,
1.024740, 0.961550, -0.983430, -0.906500, 0.996830, 0.108890, 1.192580, 1.099050, -1.294150, -0.752220,
0.366860, -1.191810, 1.279380, 2.270160, 0.202680, -0.706340, 0.716230, -0.933780, 0.589710, -0.862350,
0.355340, -0.315870, 1.332450, -0.418200, -0.218880, 0.258090, -0.108370, 0.563860, -1.740290, 0.329010,
-0.348940, -1.113630, -0.684500, -0.577860, 0.130120, -0.079230, 0.486260, 2.788620, 0.333090, -1.118660,
1.870490, -2.882370, -0.767740, -0.855370, 1.271260, 1.224380, 0.925490, -2.809660, 0.451940, -0.412110,
0.825320, -3.157090, -0.526780, 1.745100, 0.440970, 1.074550, -3.254020, 2.180230, 0.392890, -0.041740,
1.100290, -1.243660, -0.021530, -1.014340, 0.872190, 0.845720, 0.686430, 1.447540, 1.086220, 0.892960,
-1.870980, -2.282240, 2.195860, 3.313540, -0.099490, -1.359340, -1.472640, 0.791170, 0.456300, 1.776040,
1.108720, 0.208870, -0.282560, -0.576880, -3.214210, -0.614700, -0.921410, 1.713770, -2.813760, -1.061340,
3.044350, 0.319480, 1.987550, 1.893550, 0.856820, 0.488760, 9.712160, -0.475910, 0.355450, -0.977340,
-0.952900, -0.034670, 3.267030, 2.494540, -1.467190, -2.898480, -0.432070, 0.464800, 4.185650, 0.999290,
0.028050, 0.589010, 1.061270, 2.017510, -1.868270, 1.535290, 0.870000, 0.691210, 1.815980, 5.685830,
-0.236730, -1.385060, -0.833980, -2.127310, -1.405350, -3.258790, 3.845810, -1.740160, -5.683950, 0.619380,
-0.161000, 1.737050, 1.039130, -3.168540, -1.970170, 0.390580, 1.039700, -1.355200, 2.622060, 1.804790,
-0.663120, -1.784090, 5.923130, 0.218450, -3.918990, -1.470570, -0.150350, 0.274320, -0.432570, 3.582170,
-0.953690, -2.695040, -0.321120, 0.059670, 4.243050, -0.793160, -1.392360, -2.865270, 1.120420, 2.201960,
-0.891000, 1.429990, 0.232210, -0.986950, 0.486310, 0.880220, 1.238940, -1.424490, 1.284550, -1.403600,
-1.722390, -1.907810, 1.240060, 0.272600, -0.418940, 0.182460, -1.457320, -1.564150, -1.375540, -0.761490,
-1.352460, -0.196490, 0.083530, -1.937780, 0.551580, 1.011690, -0.407880, -1.502660, 0.010930, -1.025330,
1.222590, -1.104060, -1.763620, -0.690960, 0.267380, -0.829830, 2.063370, 0.759390, -1.067850, 0.775960,
-1.653870, 1.153280, 1.644930, -1.307470, 0.135050, 1.324970, -0.421490, 3.304270, -1.472010, -0.867970,
0.350950, 0.398980, 0.403710, 0.580050, 0.722170, -0.017850, -0.178810, 0.366190, 0.239160, 1.368930,
3.800440, -1.630450, 0.222850, -1.321730, 1.152730, -0.150770, -0.361540, -0.027230, 1.033090, -0.355820,
2.532730, -3.405890, 0.289570, -0.844960, -1.373360, 0.484610, -2.742370, -1.305790, 0.164730, -3.420960,
-0.170310, 0.184150, 0.034110, -1.301700, 0.583350, -0.810870, 0.141330, 0.478200, -0.244170, 0.208510,
1.589390, -1.328110, 2.740720, -0.403610, 0.771160, -1.144220, -2.114560, 1.591450, -1.351010, -1.200660,
2.022400, -0.529950, -0.198270, 1.502780, -0.987220, -1.025520, 0.125470, -1.860020, 0.724710, 1.002880,
-0.846460, 0.598690, -2.024050, 0.015360, -1.837040, 2.420150, -0.565670, 0.881450,
-0.025040, -1.626890, -0.317100, 2.896970, 2.904320, -0.620920, 1.590880, -1.462310, 1.228380, 1.724970,
-0.049220, 0.984060, 1.729280, -0.904860, -0.772640, 0.473920, 1.648820, -0.187420, -2.110770, 1.712410,
-1.763010, -0.346330, -1.942770, 3.257020, 1.928610, 0.506420, 0.488240, -1.544860, 1.163460, -0.788230,
-1.005860, -0.200410, -0.616640, -0.635790, 0.679030, -0.537930, 0.100800, 0.448100, -0.834290, 1.022910,
-1.675160, 0.225130, 0.767930, 0.633140, -1.255020, 0.553230, 0.374550, -1.190330, -0.482350, 1.908530,
-1.151730, 0.783630, 0.841360, -1.274130, 0.092240, 2.750570, 0.313590, 1.640420, -1.892360, 0.625190,
-0.600530, -0.636980, 2.974150, 0.854320, -3.013550, -0.985070, -0.005840, 1.556610, -2.448640, -0.299770,
1.605840, 0.553610, 1.379220, -1.016770, 0.922240, 0.139230, -0.128040, 1.331440, 0.981870, -0.897410,
0.056610, -0.130260, 3.601830, 3.102090, 1.635640, -0.169970, -2.630320, -1.441510, 0.403780, -0.916050,
-1.080920, -2.973450, 1.227670, 0.442760, 0.622770, -0.059910, 0.575510, 0.436390, -0.515460, 0.195950,
2.668520, -2.860370, -2.941340, 1.394230, -0.325590, 2.797180, -1.589940, -1.351220, -3.022920, 0.214370,
-3.254380, 0.540080, -2.257010, 1.739900, -1.060650, 0.481760, 0.480230, -1.355850, -0.286430, -0.656520,
-0.689030, 1.059440, -2.448990, -1.657980, -1.644680, -1.381800, 0.719520, 1.835000, -1.238760, 0.711440,
-0.662850, 2.404540, -2.678470, -1.311520, 1.112910, -0.026480, -1.355340, -0.583660, -1.038810, -1.245510,
0.294330, 2.263960, 0.450980, -1.352920, -0.128070, -2.446690, -1.730970, 4.483830, -0.030670, -0.366360,
-0.464250, -1.424190, -0.595680, -1.676560, -0.318970, 0.906250, 2.339920, -0.092510, 0.849170, -1.514270,
-1.631560, -0.604890, -5.704730, 1.715070, 0.922310, -0.357690, 0.139070, -0.551480, 1.465850, -0.018940,
1.487960, 2.639750, 1.341420, -2.151960, -8.301360, 0.189540, -0.834710, -1.721770, -0.736290, 6.377590,
0.849860, 1.171260, -0.532000, -1.042170, 2.378110, -7.644380, 1.638400, 0.931010, 0.196760, -1.471250,
0.951760, -4.572010, -2.119700, 2.164280, 3.899200, 1.841240, -1.571030, 2.244090, -0.397970, -0.363960,
0.376730, 0.626700, 2.411910, 3.554010, -1.885810, 1.423780, 1.610720, 1.700210, -6.382740, -0.401790,
1.373570, -0.067060, -1.747840, 1.108010, -3.477990, -2.784330, -1.592900, -3.166970, -0.278060, 2.602930,
0.180110, -1.376060, -1.599510, 1.860150, 0.356780, -0.276680, 0.957730, 0.658500, 1.034030, 0.822750,
-0.156370, -3.506650, -1.299510, 2.338780, 0.184010, 0.206820, -0.002390, -4.910140, -2.877720, -0.176920,
-0.602200, 1.170620, 1.402570, -2.298550, -0.248480, 0.028640, 0.482510, -0.569070, 2.339000, 1.786040,
0.052560, 3.234740, 3.724430, -1.771370, 1.792160, -0.845530, -0.496920, 0.309620, -3.551870, -0.467090,
-2.133930, 0.106110, 0.168540, -3.446570, -2.998740, -2.239870, -0.071260, 0.710630, -0.912070, 1.300610,
0.074840, -0.987820, -2.135730, -0.896120, -0.826940, 2.409710, -1.379280, 0.415670, 1.428680, -0.377440,
-1.015000, 1.761990, 0.668520, -0.581390, -0.918950, 2.322810, -1.192200, 0.925890, 0.857680, -1.099170,
-0.129650, -0.474110, 0.779600, -0.883100, -0.328610, 0.485290, 0.271180, -0.917760,
0.921470, 1.670270, -1.375280, -2.732960, -0.193990, 1.238130, -0.313580, -1.030250, 0.255110, -0.726080,
1.255660, -0.966300, 0.973080, 2.033210, -0.641350, 2.554870, 0.877020, -0.909580, -1.189240, 2.172790,
0.162620, -0.226640, -2.511890, 0.229060, 2.181800, -1.091950, -0.462410, -0.708600, 1.481780, -0.194840,
0.107050, 0.916600, -1.206770, 0.588060, 2.362440, 0.002340, 3.275180, -1.271090, 2.866330, -1.404030,
0.751250, -1.327940, 0.326710, 1.772940, 0.327930, 0.110680, 3.948120, 1.617660, -1.713520, -2.227450,
-0.743160, 3.198550, -0.354390, -1.569140, 0.858580, -1.898000, -3.380130, 0.995530, 0.684840, 3.005560,
-0.654840, -1.741000, 3.026310, 0.097500, 0.570390, -0.556280, -0.394970, -0.690220, 2.310090, 0.794940,
0.899880, -0.530830, 1.311810, -2.672440, 0.452830, -0.471480, 1.357030, -1.102790, 0.968600, -1.941820,
-2.843280, 1.524540, 2.967410, 0.922510, -1.790370, -3.619590, -1.599390, 4.672750, -1.355090, 1.516130,
2.083840, 1.130290, -0.749970, -0.412860, 0.177350, -0.221350, -2.024530, 1.058760, -0.191590, 1.240050,
0.295900, -2.044070, -1.346840, -0.489510, 0.728650, 0.312630, -0.132610, -0.966630, -4.110800, 0.422050,
3.414900, 0.750090, 0.917410, 1.490940, 1.153700, 0.180070, 1.571540, 3.188410, 1.807110, -0.048020,
-0.286410, 0.008350, -0.797520, 0.756830, 0.541750, 0.046900, 0.273620, 2.099350, -1.084620, 1.468600,
-0.587950, 0.573670, 1.314040, -0.389190, 2.105050, -0.524920, 1.842700, -0.147160, 0.011230, -1.990800,
2.496670, 5.782650, 0.151890, 1.169350, 1.827440, -1.219230, 2.094560, 2.015220, 0.414020, 1.699550,
1.385280, -1.691970, 2.623470, 1.235780, 2.097360, 2.495300, 1.301860, 0.725810, -0.566200, -1.360680,
-3.285360, -1.797370, 0.034130, 0.903680, 2.804680, 0.567520, 0.002440, 0.284370, 1.218180, -0.050790,
2.016370, 0.657880, 1.475350, 0.215950, 2.336200, -1.106650, 0.415730, -0.546100, -1.822450, 0.727860,
0.218980, -0.289940, -0.176930, -0.921480, -0.861070, 3.295590, 0.579990, 3.240450, 1.067510, 0.436580,
0.729610, 0.242740, -1.458960, -0.020570, 0.627260, 0.881430, 0.147200, 2.326390, 0.976450, 0.080730,
0.563780, 0.732170, 3.146080, -0.626480, -0.892850, 0.233490, 1.189740, 1.171860, 3.941870, -0.316450,
4.711980, 0.402050, 2.990970, -0.483860, -2.320670, -2.815080, -0.742210, -2.602380, -0.609000, -0.576770,
1.700690, -0.085670, -1.908800, 3.051130, 2.442640, 1.163610, -2.285040, 0.933260, -1.666760, 0.217180,
0.007010, -0.711010, -2.172620, 0.697140, 1.888460, 2.115990, 0.960100, -0.242680, 2.234650, 1.167400,
1.376750, 1.213400, 1.537940, 0.211720, 1.084440, -0.358670, -0.008650, 1.145530, 2.902820, 0.193890,
0.611470, -0.538480, -0.947450, 1.600100, -0.596660, 1.016600, 0.426850, 1.858720, -1.322760, 1.988160,
0.236610, -0.798350, 1.416900, 2.755710, -1.705710, -0.099360, -1.128380, -0.585880, -1.815430, -0.194240,
-3.440670, -0.666030, -1.579880, -1.476740, -2.198330, 1.234510, -0.939690, -0.703750, -0.702140, 3.070590,
-0.847030, 1.184080, -0.657570, -2.735740, -2.050640, -0.091540, -0.262370, -0.326640, 0.636670, -0.662900,
0.790160, 2.355110, -0.752620, -0.494980, -1.481050, 0.761550, -0.088420, 1.013250,
-0.348790, -0.288930, 0.095990, 0.715090, 0.438290, -0.129200, 0.559420, -0.695160, 0.318940, -0.570730,
-1.023880, -0.853490, 0.850800, 0.284820, 0.200750, 0.255670, -0.172650, -0.636450, -0.272370, -0.224320,
-0.104110, -0.075490, -0.423870, 0.409210, 0.694920, 0.541450, 0.242170, -0.101040, -0.366930, 0.385900,
-0.131700, 0.548190, -0.335860, 0.364220, 0.420810, -0.168680, -0.001090, 0.440020, -0.418810, 0.357080,
-0.694300, -0.831420, 0.782030, 0.183950, -0.953880, 0.561440, 0.683500, 0.412520, -0.294040, -0.433230,
-0.432780, 1.254440, 0.352450, -1.648330, -2.050160, 1.166990, 0.023720, 0.645000, 1.385700, 0.327920,

0.609570, 0.261050, -0.311100, -0.695350, -0.637060, 0.853770, 0.889870, 0.932740, 0.986440, 1.003630,
-0.922330, 0.842280, 0.400270, 0.363500, 0.691640, 0.160690, 1.111050, 0.663680, -0.042610, -0.135420,
0.519080, 0.537640, 0.633660, -0.617930, -1.091010, 0.932190, -1.030150, 1.437370, 0.328740, 0.879020,
-0.154960, 0.299980, -0.984560, 0.811250, 0.237060, -0.411100, 0.881670, -0.828660, 0.255030, 0.001020,
0.482870, -0.733540, -0.053770, -0.771990, 0.027560, 0.130020, -0.981190, -0.557620, -0.352370, 0.689010,
0.715540, 0.060710, -0.196750, 0.672190, 0.017590, -1.079570, 0.137590, -0.871940, 1.911910, 0.532910,

0.459420, -0.327530, 1.109460, 0.739140, -0.390700, -1.066630, -0.535160, -0.090580, 1.051700, -0.605830,
0.763220, 0.127490, 0.336290, -0.463310, -0.148710, 0.750090, 1.966300, -1.012590, 0.507850, 0.442070,
-0.138510, 1.391840, -0.004260, 0.287940, -1.077860, -0.917520, 0.675910, 0.964620, 0.475480, -0.192270,
-0.800420, -0.678850, 1.571200, 0.832560, -0.622710, 0.059290, -9.473080, 0.569420, 1.136670, 4.388870,
0.056470, 0.782490, -0.167020, -0.118490, 0.365580, -0.260610, 0.074180, 0.257150, -0.267360, 0.165920,
-0.847340, 0.588930, 0.854120, 0.304020, 3.126870, 4.700130, -0.411770, -0.605320, -4.608030, -0.444860,

0.704620, 0.688690, -0.345430, 1.970540, 0.981760, 1.441720, -1.221880, -0.709170, -0.600260, -0.113880,
-1.592630, 0.735620, 0.503620, 0.190840, -1.303520, 0.263160, 1.066950, -1.068020, -1.641040, -0.642510,
0.425340, -0.386020, 0.578080, 0.073750, 1.993370, 0.081180, -0.043920, -0.581810, -0.267760, 0.617500,
-0.655320, 0.769740, 0.184920, -1.043670, 0.042290, -0.559080, -0.678200, 0.350660, 1.155820, -1.340910,
1.137870, 0.797450, -0.244800, 0.965010, -1.121630, -0.013410, 0.531800, 1.263520, -0.328080, -0.334730,
-0.350090, 0.581940, -0.936760, 0.879400, 1.722890, -0.460590, 0.044540, 0.584410, -1.874920, -1.371410,

-0.213050, 0.782020, -0.265740, -0.406640, -0.536200, 1.470500, -0.616110, 1.030230, 0.493850, -0.148300,
0.887640, 0.435780, -0.344910, 0.076140, -0.089480, 0.333320, 0.818770, 0.340010, -0.542240, -0.160280,
0.026600, -0.200420, 0.579580, -0.265950, 0.203490, -0.573280, -1.106400, -0.037090, 0.566930, -0.673170,
-0.676320, -0.835680, -0.378990, 0.338240, 0.874060, 0.506830, -0.222680, 0.406390, 2.191850, 2.374700,
-0.170840, 0.200780, -0.888760, -0.404540, -0.927390, -0.434360, -0.449250, -1.452890, -0.159010, 1.042070,
-0.098340, 1.374560, -1.392730, -0.435460, 0.933300, 4.098640, 0.439340, 0.773390, 0.128800, 0.122730,

1.617560, -0.678840, -0.879150, 0.172860, -0.409240, -0.216510, 1.132560, 0.388800, 0.066340, 0.233570,
-1.153310, 1.047740, -1.356720, 0.377730, -0.875850, -0.751530, -0.906900, 0.585310, 0.494200, -0.293620,
-0.108690, -1.304660, 0.453150, -1.086100, -0.024760, -0.631600, -0.182350, 0.599490, 0.071410, 0.867060,
-0.198570, 0.814100, -1.547400, -0.644070, 0.150480, -0.124440, 2.565570, -0.760810, 0.758810, -1.582570,
4.770640, -0.915510, 0.713160, 0.093180, 0.014160, 0.508910, 0.797710, 0.940970, -0.950730, -0.920640,
0.538020, -0.463880, 0.010160, 0.268770, -1.155560, -2.606900, -0.512240, -0.170390, 4.979500, 0.460830,

0.854700, 0.995060, -1.704160, -0.909440, -1.402490, 1.662740, 1.034810, 2.949320, 0.107970, 1.582800,
-1.428100, 2.336770, -0.114530, 1.155570, 0.399100, -1.922850, -1.231510, 0.327390, -0.910970, 1.527460,
1.555450, -0.070680, 2.707580, -0.840950, 0.622960, 1.327400, 0.006310, -3.120530, 1.172250, 0.299490,
-0.959340, 0.401070, 0.065750, 0.817890, -0.530910, 0.210640, 0.698610, -0.665900, -1.012640, -0.720610,
-1.218270, -1.360220, 1.219970, -0.034680, -0.383040, -0.887420, -0.716280, -0.005950, -0.613910, -0.928250,
0.120770, -0.990310, 0.474060, -1.328750, -0.927420, -1.483930, -0.334720, -0.472210, -0.473530, 1.114990,

-0.498390, 0.829010, -0.298300, 1.022950, 0.490560, -0.861740, -0.462810, 0.269810, 0.692800, 0.300420,
0.379620, -0.329980, -0.078980, 0.980170, -0.281920, -0.517940, -0.477970, 0.222010, -0.245600, 0.091740,
0.442850, -0.200120, 0.218110, 1.250900, 0.750100, -0.161020, 1.445370, -0.818740, 0.820650, 0.432470,
-0.286650, 0.299230, -0.624730, -0.342510, 0.183910, -0.602110, 0.066190, -0.296090, 1.237230, -0.611740,
1.162150, 0.910610, 0.687020, -0.478030, 0.863220, -0.628360, -0.386880, 0.660890, 1.024290, -0.914520,
0.486360, -0.312400, 0.448700, -0.067380, -1.874690, -2.375260, 0.199380, 0.008100, -0.390910, 0.397550,

-0.044820, -0.551350, -0.135410, 0.370500, -0.100170, -0.651010, 0.314330, 0.672630, 0.113720, 0.821160,
0.801350, -0.400960, -0.979680, 0.677530, -0.075120, 0.583920, 0.399010, 0.210360, 0.299630, -0.954830,
0.400520, 0.629040, 0.038560, 1.794780, -1.062190, -0.884980, 0.888870, 0.213420, -0.010110, -0.712940,
-0.837790, 0.305910, 0.214790, -0.514110, -0.613390, -1.270250, -4.265450, -0.332870, 0.746720, 0.755970,
0.135230, 0.105420, 0.671530, 0.352290, -1.157080, 0.428380, 0.343240, 0.291280, 0.348770, 0.449540,
-0.948070, 0.175920, -0.665560, -0.018330, 2.999250, 2.268400, 0.868790, 0.800240, -5.895070, -0.395200,

0.066240, -0.101280, 0.180670, -0.862270, 0.055510, -0.509710, -0.064440, -1.614680, -0.416810, -0.056140,
1.758700, -0.361830, 0.322880, 0.111030, -0.417340, 0.832010, 0.722310, 0.845890, -0.455140, -0.098450,
-0.849180, 0.579470, 0.113810, 0.700780, 0.902640, -0.630390, 0.675950, -0.092450, -0.540720, -2.240540,
-0.136040, -0.231160, 0.137030, -0.340890, -0.112130, -1.532510, -3.850630, -0.068750, -0.557740, -0.274660,
-1.514010, 0.688790, -0.907670, 0.030930, -2.080610, -1.059580, 0.668260, 0.278810, -1.651470, 0.643950,
0.764350, 1.130630, 1.010990, -0.658760, 1.385490, 0.933470, 0.464950, -0.658670, -2.399310, -1.626050,

-0.315350, 0.768590, -1.563840, 0.629600, -1.245740, -0.344940, 0.486710, 1.286590, 1.323090, 0.062380,
-0.948360, 1.326400, -1.238880, 2.010290, -0.054290, -2.286390, -0.049700, 1.667420, -0.055660, -0.310380,
0.316570, 1.385450, -0.565880, -0.592930, 0.044540, 0.646050, -0.524800, 0.484740, 0.413070, -0.161870,
-0.574470, -0.120600, -0.673710, -0.305440, -0.529870, -0.447940, 0.169000, -1.230150, -0.546130, -0.659120,
-0.567300, 0.167330, -0.107580, -0.895800, 0.589500, 0.080520, 0.088770, 0.281610, 0.531050, -0.416100,
-0.558740, 0.333400, -0.463600, 0.569730, -0.228060, -1.101280, -0.201860, -0.782480, 1.507850, -0.920770,

-0.797140, -1.525760, 0.819520, 0.839050, -1.881730, -1.445780, -0.322540, 3.441330, -0.868350, 1.749180,
-0.396710, -1.219080, -0.359920, 1.047200, 3.197720, -0.005410, 0.043070, -0.424010, 2.956820, -0.065500,
0.641110, 0.835330, 0.341190, -0.554780, -0.918790, -0.699320, 1.385060, 1.972180, 0.302030, 2.332930,
1.258390, -0.007180, 0.240150, 1.020180, -0.178660, -0.283030, -4.625550, 0.790320, -1.564360, 41.947639,
3.155110, 2.515730, 1.445140, -0.284970, -2.801920, -0.646150, -0.501040, 3.379250, 0.105860, -0.519520,
-1.465010, 4.057510, -0.104210, -0.235370, -1.271410, 18.278959, -1.903140, 1.126620, 1.258680, -0.665970,

0.908440, 0.633080, 1.025270, 0.569890, 0.121540, -0.015090, 0.237110, 0.133360, 1.040750, 0.503360,
0.188380, 0.400070, -0.345830, -0.056700, -0.499040, 0.006490, -0.541760, -0.945200, 0.388420, -0.320660,
-0.563430, 0.804150, -1.107660, 1.120790, -0.328630, -0.234040, 0.922070, -0.140320, -0.306880, 0.084600,
-0.619430, -0.703620, -0.662460, -0.145870, 0.074980, 0.021720, 1.385630, -0.052020, 0.869300, -0.968470,
-0.722970, 0.386640, 0.651680, -0.025660, -1.926780, -0.933420, -1.017980, -0.687050, -1.027500, 0.333180,
0.638850, 0.928950, 0.145810, 0.379950, -1.412680, 1.145890, 0.221490, -0.716070, 4.081200, -0.391920,

-0.812480, -0.494400, 0.532700, 0.700850, -0.614060, 0.163320, -0.602810, -0.537230, 0.153400, -0.225500,
-0.613640, 0.137670, -0.371040, -0.238190, 0.261910, -0.179530, -1.192450, 0.630340, 0.000630, -0.438270,
-0.468770, 0.150040, -0.085290, 0.222810, 1.010420, 0.542030, 0.539740, -0.434540, 0.201730, 0.803950,
-0.107060, 0.356020, -0.375800, -0.247680, 0.790470, 0.144700, 1.013870, -0.156800, -0.438010, 0.200100,
1.556110, 0.183790, -0.021120, -0.386590, 1.271220, 0.701380, 0.009920, 0.454520, -0.202500, 0.590020,
-0.138860, -0.562760, 0.230100, -0.407960, 0.491150, -2.309730, -0.424430, 0.420300, 1.451010, 0.219660,

0.616130, 0.494090, -0.012850, -2.036250, 0.258260, -0.678100, 0.890090, -0.089380, 0.378600, -0.005970,
-2.511330, -1.504710, -0.044750, -0.482770, -0.172280, 0.782590, -0.066980, -2.214510, 0.368160, -0.010270,
0.798340, -0.959840, -1.282580, 3.828950, 1.940810, 0.484210, -0.277840, 0.177160, -0.342470, -1.434980,
-1.078950, -0.088950, 1.289620, 0.663180, -0.127810, -1.441830, -1.196970, -0.357230, 0.436300, 0.205160,
-1.200250, -0.393580, -0.634890, -1.414900, 1.496600, -0.243880, -0.656070, 0.772860, -0.423880, 0.587760,
0.398700, 0.189140, -1.642050, -0.205850, 2.874650, 0.207190, -0.257860, -0.957670, -2.151050, -1.099270,

0.292790, -0.492060, -0.946930, -1.145010, -0.990530, 0.781670, 0.936060, 0.687200, 0.069610, 0.322560,
-1.702520, 0.090570, 0.332260, -0.228540, 1.008770, -0.160890, 0.725560, 1.163750, -0.638710, -0.017000,
0.107440, -0.981940, 1.738320, -1.105640, -0.425330, 0.173750, -1.004820, 1.055250, 0.156110, 0.364360,
0.164240, 1.662690, -0.725090, 0.857990, 0.533270, 0.419000, 0.558410, -0.724530, -0.626250, 0.936900,
4.420530, -0.777510, -0.471520, -0.237690, 0.244280, -0.270070, 0.574400, 0.482720, 1.386690, -0.121030,
-0.135270, 0.660290, -1.261750, 0.085330, 0.472460, -1.780830, 0.544220, 0.600030, -0.090780, 0.268980,

0.702640, -0.723350, -0.701400, -0.580640, -0.288540, 0.625190, 1.463010, 0.116600, -0.125150, 0.208210,
-1.415740, 0.682150, 0.441510, -0.195550, 0.433590, -0.210890, 0.622680, 0.032740, -0.456700, -0.515530,
-0.304750, -0.614300, 0.769120, -0.539730, -0.383190, 0.136380, -1.456970, 0.623510, -0.105560, 0.264760,
0.636000, 0.278320, -0.541660, -0.746460, 0.716230, 1.155520, 3.923870, 0.721420, 0.758040, 0.019480,
3.309940, 0.586560, -0.015430, -0.798440, -0.931450, 0.368670, -0.435920, -0.250860, 0.612760, -0.092700,
-0.278930, 0.623390, -1.061770, 0.852120, -0.157550, -1.421370, 0.557910, 0.403770, -0.445280, 0.859700,

-0.679480, -0.440650, 0.229010, 0.364700, -0.802640, -0.546710, -0.635450, 0.033300, 0.150220, 0.129480,
0.118670, 0.660140, -0.424880, 0.514110, -0.319750, -0.681250, -0.419010, 0.353320, 0.233520, -0.431320,
-0.295240, 0.107450, -0.244120, 0.687670, 0.904960, 0.629000, 0.211220, 0.364340, -0.450150, 0.408900,
0.698700, 0.519550, -0.399740, 0.189280, 0.349130, -1.185720, -5.706450, 0.185130, -0.064160, 0.945150,
-0.849070, 0.714730, 0.204520, -0.518190, 0.691160, -1.068700, -0.191050, -0.696140, -0.897630, 0.027820,
0.490640, -0.096330, 1.491910, 0.383940, -4.085200, 0.229850, -0.547190, -0.520040, -2.446260, 0.299410,

0.738360, 0.589010, 1.014900, -2.227340, 0.992400, 0.418810, 0.527760, -0.040220, -1.682170, 0.624970,
2.186110, -1.185890, -0.295420, -0.537910, -0.805390, 0.455340, 0.483610, -0.737400, 0.679690, 0.385090,
-0.350740, -0.606200, -0.421800, 1.013410, -0.622720, 0.289800, -0.154220, 0.844020, -1.462910, -1.125030,
0.102590, 0.714590, -0.726710, 0.261730, -0.639100, -0.764860, 0.158020, 0.693110, 0.417420, -1.018230,
-1.919360, 0.114780, -0.165680, 0.877210, -0.190070, -0.913840, 0.150060, -1.502510, 0.650000, -0.637240,
0.805690, -0.750990, 0.987130, 1.068970, -0.744650, -5.041740, -0.531130, -0.899360, -2.059610, 0.156160,

-0.091850, -0.475380, 0.605080, 0.785320, -0.623550, -0.249640, -1.001880, -0.748960, -0.238700, 0.338130,
0.750540, 0.902490, 1.325010, -0.913540, 0.148540, 0.561920, -0.339760, -0.414990, 0.209740, -0.558500,
-0.326750, 0.229440, -0.943300, -0.459260, -0.418500, 0.340820, -0.196950, 0.217570, -0.629840, 0.579080,
0.538320, -0.537890, 0.599740, 0.482820, 0.863050, 0.716120, 0.814260, -0.552960, 0.460570, -0.588120,
-0.748880, 0.467650, 0.036510, 0.567510, -0.526110, -0.968750, 0.061960, -0.096380, 0.552080, 0.304850,
0.401870, -0.190270, -0.341190, 0.754920, -0.163690, -0.349350, 0.414450, -0.110560, -0.534490, 0.029490,

0.626900, 0.147040, 0.216760, -0.121220, -0.666270, 0.620970, 0.180270, 0.207440, -0.188680, -0.952370,
0.456790, 0.957800, -0.696480, 1.187590, -0.676300, -0.187390, -0.577010, 0.422070, -0.178230, 0.241220,
-0.721280, -0.496360, 0.593110, -0.844580, 0.640300, 0.257620, -0.408870, 0.364150, -0.457170, -0.021890,
-0.348270, 0.244370, 0.182860, -0.553140, -0.725560, 1.130910, 1.652350, -0.567180, -0.416650, 0.283650,
0.665520, 0.055110, 0.883640, 1.170540, -0.407270, -0.481520, -0.465370, 0.047020, -0.085170, 0.473350,
1.087610, 1.273370, 2.613550, -1.551070, -2.412810, 0.864210, 0.759880, -0.892760, 1.264350, 2.866280,

-0.702170, -0.240170, 0.642520, 0.798530, 1.422350, 0.067630, -1.245350, -0.697840, -0.651290, -1.155230,
1.642920, -1.021820, 0.154000, -0.963290, -0.476920, 0.288200, 0.944090, -1.275870, 0.139420, 0.464230,
-0.692250, -0.608220, -0.282280, 1.926680, 0.638310, -0.409860, 1.515090, -0.754910, -0.243180, -0.001710,
0.569900, 0.023790, 0.425140, 0.029990, -0.482130, -1.531890, -2.113400, -0.775300, 0.484630, -0.603590,
-3.644790, 0.052040, -0.017640, 0.130430, 0.607420, -0.060740, -0.025900, 0.854840, -0.275350, 0.249320,
-0.056630, 1.240330, 0.114570, -0.884380, 1.569030, 1.258120, 0.392970, -0.090130, -3.551290, 0.049550,

0.690790, -1.388250, -1.652520, 0.436840, -1.275140, -3.116310, -0.088660, 0.362040, -0.473030, -0.813170,
-0.222930, 0.707760, -0.214270, 0.473290, -1.305560, -1.058800, 0.378700, 0.690150, -0.437890, 2.662180,
0.459160, -1.637810, -0.144250, 0.732850, 0.611840, -0.403150, 0.428330, -0.884400, 0.713360, 0.164690,
-0.851770, 0.568040, 0.556020, -0.708480, -0.184570, -0.677300, 0.969780, 0.182870, -0.867790, -0.025090,
-0.227910, 0.624680, 0.486010, 0.608590, -1.225960, 0.116920, 0.358930, -0.652480, -0.460900, 0.653360,
-0.917460, 1.907330, -0.052360, 0.684910, -1.098410, 0.796650, -0.801840, -0.064460, -1.511190, -0.380070,

-0.789670, 0.895850, -1.080130, -0.493110, -1.118330, 1.766020, -0.585510, -1.160580, -0.615520, -1.301390,
-0.537130, 0.036550, 3.394770, -1.921520, 0.595510, 1.244080, 0.362550, 0.441320, -2.007160, 0.035540,
1.353380, 1.472050, -0.546740, 1.486670, 0.493770, 1.928450, -0.677850, -1.614360, -2.331640, -1.421010,
0.065560, 2.577290, -0.059080, -0.253450, 0.013550, 4.037160, 2.283830, 1.983360, -0.740840, 0.315470,
-6.284900, -0.160150, 0.985360, 0.430160, 0.400830, 0.357930, 2.102380, 0.635420, 0.210050, 0.093540,
-1.693030, -0.666450, 2.131170, -0.990380, -2.643440, 0.314840, -0.215950, 0.977100, 7.113140, -0.543830,

-1.175360, 0.357660, 0.667480, -0.320010, 1.022790, -2.543720, 0.152120, -0.467540, -0.787310, -0.302030,
0.676000, -0.126140, 0.474250, 0.738790, 0.962720, -0.431810, 0.761200, -0.890650, -0.447640, 1.315820,
0.081430, 0.639950, 1.167880, 0.347680, -0.132060, 0.339480, 0.648770, 0.512910, 0.097100, 0.065070,
0.353980, 1.223670, 0.195270, -1.074310, -1.561940, 1.515780, -0.456450, -0.375180, -1.090660, 0.831630,
-0.686290, -0.350680, -0.458890, -1.220340, 1.132260, -0.507580, 0.978310, -0.343270, 0.169370, 0.079630,
0.112890, -0.865410, -0.894270, -0.601360, 0.223850, -0.630890, -0.348490, 0.190870, -0.197670, -0.377100,

0.587490, -2.221750, -0.692260, 0.583280, 0.740240, -0.320660, -0.485430, -0.189280, 0.767120, -0.654260,
-0.712120, -0.896460, -0.506990, -0.845820, -0.123340, 0.671540, 0.945070, -1.101550, 0.565280, -0.193450,
-2.359890, 0.268900, 0.399350, 0.788890, -0.787970, -0.699470, 0.454230, 0.461430, -0.216020, -1.368830,
-0.767360, 0.343270, 0.729940, -0.381630, 0.616790, -0.545820, -1.134110, 0.012190, -0.510100, 0.211580,
-1.829530, 0.051340, -0.175060, 0.213480, -0.160020, -0.232480, -0.851840, -0.103240, 0.040670, -0.424410,
0.921350, 0.837510, 0.833250, -0.377480, 0.338570, 0.640290, -0.134140, -0.695130, 0.740540, 0.542220,

0.092620, 0.493930, -0.142760, 0.607670, 0.612630, 0.374960, -0.652880, 0.328040, 1.262390, -0.456450,
1.118600, 0.289550, 0.476890, 0.853490, -0.685670, 1.547220, 0.353950, -0.173390, -0.960750, -1.107060,
-0.065390, 0.033000, -0.193320, -0.033630, 0.033040, -0.592800, -0.284900, 1.114220, 0.526750, -0.800180,
-0.315600, 0.797650, 0.025730, 0.711360, 0.539120, -0.897300, -2.094660, 0.671130, 1.876170, 0.664410,
-2.716120, -1.102700, -0.128670, 0.685040, 1.287850, -0.712440, -0.244890, 0.001910, -0.073050, -0.819040,
-1.219670, 0.372100, -0.837840, 0.869210, 0.595200, -2.004960, 1.438590, 1.055760, 0.179820, -0.607650,

-1.923540, 0.396840, 0.401460, 0.798800, -0.763310, 0.053720, -1.571240, 0.383960, -0.336540, -0.250890,
0.001770, -1.086730, 0.619570, -0.212540, 0.426340, 0.206920, -0.926950, -0.121380, 0.857310, -0.048860,
1.159170, -0.602680, -1.508210, -0.893680, -0.122060, 0.021830, -0.490950, 0.116980, 0.128020, 1.197820,
1.065950, 0.920080, 0.074830, 0.587820, 0.359190, 2.260500, 3.152960, -0.184030, 0.677690, 0.908560,
2.188690, 0.440040, -0.155990, 0.699750, 1.816220, -0.973450, -0.534440, -0.996900, 0.819730, -0.075740,
0.076260, -0.321720, -0.830460, 0.530680, -1.296480, 0.659550, 0.132650, -0.376090, 1.348230, 0.158370,

2.506520, -1.324150, -0.171550, -0.952490, -1.617490, -6.901550, -3.154990, 1.143610, -1.006080, -0.748290,
-1.439060, 3.415270, -0.640270, 0.428830, -0.853480, -0.449900, -3.207680, 0.496420, -3.118310, 1.330530,
0.034450, -1.778680, -0.282860, -2.854860, 0.728620, 0.571800, -0.065590, 1.188930, -0.077920, 1.628120,
0.294100, 0.750570, 0.743970, 0.187940, -0.376280, 1.966090, -1.685070, -0.216580, -0.278740, -1.358540,
-0.621400, 0.576490, 0.558200, -1.094250, 0.252930, -0.565180, -0.181460, -1.396120, -0.223010, -0.772450,
-0.827190, -2.084990, 1.937920, -0.939500, 0.430230, -1.943230, 1.076530, -0.666170, 0.532730, 0.248890,

0.242990, -0.051330, -0.974070, 0.348100, -1.534870, -0.658480, -0.676930, 1.095200, 0.502820, -0.889850,
-0.822760, 1.586710, -0.152130, 0.165100, 0.337710, -0.935500, -0.356630, -0.242760, -0.702450, 0.676500,
0.422660, -1.898700, -0.438480, -1.477520, 0.977320, 0.204820, -0.596510, 1.073040, 1.345400, 0.945910,
1.003170, -0.019500, -0.511970, 0.349660, 0.192490, 0.027200, -0.068620, -0.220880, -0.839460, -1.070980,
1.556510, 0.950590, -0.671540, 0.060900, 0.345860, -0.725460, 0.853920, -0.045750, 0.222400, -0.343130,
-0.697750, -0.245050, -0.159460, -0.859440, 0.036380, -3.783920, 0.184850, -0.606730, 0.548050, 0.454990,

0.602080, -0.082120, -0.780830, -0.725300, -0.442310, 0.040870, 2.281480, -0.231390, -0.915300, -1.241610,
-0.481820, -0.611120, 0.710440, 0.448390, -1.409630, 0.292940, -0.126400, -0.497040, 0.260110, -0.116300,
0.727400, -1.403050, 0.635660, 0.610890, -0.723000, -1.417130, 0.976120, -0.161570, 1.736190, 0.645580,

0.896260, 0.112160, 0.569970, -0.730750, -0.490890, -1.501820, -2.014680, -0.061740, 0.017930, 0.513400,
-1.034390, 0.749310, 0.292000, -1.024230, -0.329940, -0.560860, 0.113740, 0.873730, -1.051150, -0.220710,
0.884930, 0.546400, 0.390450, -0.147900, -1.358000, 1.151800, -0.689200, 0.330350, -1.318830, -0.593450,

-1.104600, -0.645570, 0.964800, 0.608510, -0.195430, 0.036420, -1.662660, 0.138000, 0.399830, -0.460230,
0.747550, 0.840040, -0.789350, 0.567940, 0.559170, -0.008550, 0.608370, -0.424370, 0.394490, 0.168960,
-0.947900, -0.470480, -0.519600, -0.552390, 0.802930, -1.142060, 0.366140, -0.197340, -1.596670, -0.372740,

0.002670, 0.803590, -0.383670, 0.526160, 0.213050, 0.832630, 2.104240, 0.491370, -1.032080, -1.529870,
-0.169030, -0.657870, 0.586190, 0.350960, -0.816280, 0.106260, -0.255210, -0.190940, -0.181520, -0.989870,
0.393810, -1.533000, 0.807690, -0.989870, -1.428730, -1.691530, 0.493770, -0.805100, 1.871170, 0.868170,

0.492700, -0.197700, 0.208890, 0.811740, 0.606560, -2.483490, -2.735180, -0.191660, 0.528860, 0.269320,
-1.517200, -0.903160, 0.574450, 0.242160, -0.748510, -0.390390, -0.887080, -0.143540, -0.862010, 0.124840,
0.735500, 0.862550, 0.774950, -0.699360, -1.450850, 1.324980, -0.656870, -0.859990, -1.361560, 0.122260,

-0.342990, -0.507130, 0.151950, -0.518250, -0.452050, -0.767590, -1.869940, -0.181970, 0.416040, -0.724740,
0.295550, 0.483380, -0.726960, -0.627870, 0.818220, 1.081590, -0.622380, 0.315510, 0.360290, 0.961670,
-0.692650, -1.050920, -0.974630, 0.730210, 1.288830, -1.254100, -0.478620, -0.187870, -1.371820, -0.697390,

-0.804560, 0.560100, -0.712090, 0.406800, -0.039230, 0.483440, 1.994050, 0.609590, -0.404330, -0.793600,
3.139500, -0.404470, 0.342790, -0.066340, -0.821640, -0.388980, 0.922780, 0.243960, -1.183070, -1.146520,
0.385370, -1.400150, 0.596370, -0.556560, -1.044850, -1.364140, 0.489870, 0.227290, 1.894620, 0.833590,

-0.740770, -1.086130, 0.311410, 0.226860, -0.020860, -2.232610, -2.470050, 0.461110, -0.456700, 0.182950,
-3.666160, -0.471880, 0.898240, 0.702670, -1.113520, 0.515020, -1.094080, 0.411980, -0.864550, -0.351730,
0.087920, 0.922070, 0.921720, -0.608970, 0.392700, 1.145020, 0.492400, -0.544240, -1.420310, -0.309120,

0.362290, 0.659490, 0.641790, -0.268500, -0.847560, -0.476920, -1.947880, -0.719820, 0.024300, -0.058850,
-2.737080, 0.395540, -0.367840, -0.513120, 0.951960, 0.089570, 0.930380, -0.036250, 0.888410, 0.018840,
-0.269750, -0.699000, -0.890130, 0.834440, 0.339160, -0.900220, -0.405110, 0.412630, -1.408540, -0.649880,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.853920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.429630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.752430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.878160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.900500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.262390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.164540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.674990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.919020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.224660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.263160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.604750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.895200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.978880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.927260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.979760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.656700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.931130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.686330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.211080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.047490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.407100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.056340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.859600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.339100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.676640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.619830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.002820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.774990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.384640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.135440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.937620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.031400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.405600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.530140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.754420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.378820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.916010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.324450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.131240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.148400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.971350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.291020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.101050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.600960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.727240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.455760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.882490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.905300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.664830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.682210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.278490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.405830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.666450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.533280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.894720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.948860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.112090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.778860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.582180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.256330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.012520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.248960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.105720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.243760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.236380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.924560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.091400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.399940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.507140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.450960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.520890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.353070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.053170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.445800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.818460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.418850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, 0.686180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.290350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.957660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.411510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.726880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.292130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.177890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.012090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.845000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.616500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.434580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.475880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.516280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.519270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.471350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.199290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.739570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.719660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.369880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.229190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.484360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.987410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.077920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.768180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.939600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.339810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.195590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.133670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.271130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.795110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.990650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.085890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.739540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, -0.948710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, -0.119810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.910200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.032410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.247050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.297760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.877400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, 0.948160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.336830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.806680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.858170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.357710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.356050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.349930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.956440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.533650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.762800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, -0.323280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.643450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.157800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.759340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.278110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.305440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.538030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, 0.502130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.425380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.596690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.304320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, 0.572320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.574610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.007720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.823400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, 0.166720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.482650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.934190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.873220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.094100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.178820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, -0.496700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.207490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.564560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, 0.769650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.120430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.440820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.036460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.881980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.247530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.498500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.889070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.951270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.497760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.442010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.232990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.067110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.559810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.371480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.471980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.607640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.862200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.032930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.258400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.520730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.496700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.657440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.328850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.968370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.734760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, -0.073920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.124030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.088850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, 0.088970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.473440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.077150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.742880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.998280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.386800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.339480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.517720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.857240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.960180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.301600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.138300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.477730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.982200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.628210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.157800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.012490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.256900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, 0.191970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.971490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.991360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.467380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.968110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.685980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.075820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.901510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.962230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.086300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.387360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, 0.709250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.588880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.491860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.800620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.424880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.362860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.514070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, 0.706110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.652150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.533540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.599900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.923470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.648170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.531690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, 0.789250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, 0.123230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.114940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.560590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.974330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, 0.797610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.442060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.700100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.385070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, 0.878860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, -0.326030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.902340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, 0.042090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, 0.070160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.677170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.570710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, 0.509040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, -0.205790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.806950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, -0.543740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.835160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.894370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.418660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, -0.733020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.781980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.132000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, -0.654220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, -0.026090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.774900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.359620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.759200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.969010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.449040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.503120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.794270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, -0.062370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, 0.921970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.990600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, -0.537600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.643180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, -0.612340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.699620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, -0.978070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.411810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.187570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (hid11) */
      0.0, 0.869050, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, 0.410000, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, -0.973130, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.581250, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.356860, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -0.274820, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.307410, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, -0.316660, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, 0.215600, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, -0.542570, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.712340, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.954500, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, -0.249610, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -1.087480, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 1.075580, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, 0.808520, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, -0.764760, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, 0.549640, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -0.437220, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 0.199780, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, -0.672810, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.266260, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, -1.070000, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -0.685070, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.429240, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, 0.705240, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, -0.385300, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, 0.491440, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, 0.057770, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -0.799040, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -0.228360, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, -0.596610, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, -0.810050, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.021000, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, 0.699030, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.367830, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, -0.562920, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.694600, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -0.515280, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.865400, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, -0.310270, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, -0.149090, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, 0.774160, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.103500, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, -0.826200, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, -0.192770, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.965130, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, 0.875730, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.096260, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, -0.296660, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, 0.856190, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.858080, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.551300, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.331960, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, 0.317350, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, 0.470070, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.174190, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.772140, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 0.228870, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.485290, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.657430, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.828100, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, -0.553890, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, 0.326800, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.219810, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 1.112160, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, -0.692100, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.517490, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.521210, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
0.00031, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.03801, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
0.00916, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
1.41611, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
1.33546, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
1.30031, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
0.00341, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
0.00033, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
1.30003, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
0.12896, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
0.00295, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
0.03505, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
1.33860, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
0.25524, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
1.42857, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
1.22597, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
1.31070, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
0.40441, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
0.03857, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
1.32700, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
0.42822, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.33095, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
0.41697, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
0.29975, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
1.24429, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.39905, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
0.38936, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
0.01155, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
0.17550, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
1.38993, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.29839, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
0.79900, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
1.42650, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
1.42793, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
1.42090, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.00370, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
0.00632, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
1.03168, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.93190, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.09867, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
0.00650, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
1.42290, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.32459, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
1.08116, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
0.00687, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
1.15212, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
1.32225, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.29413, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.00873, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
1.37707, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
0.11800, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
1.22597, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
0.30082, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
1.42270, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.03656, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.38580, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
1.42815, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.38510, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
0.01176, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.11531, 0.500000, 2,
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
