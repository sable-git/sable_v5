/*********************************************************
  ELMAN268-30-30-9ENTROP2+weight.c
  --------------------------------------------------------
  generated at Tue Aug  3 10:02:51 2004
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
0.804470, -0.094850, 0.640980, -1.605760, 0.145770, -1.160450, 0.373300, 0.552430, 0.857390, -0.207900,
1.471070, 0.126760, 0.657920, 2.411810, 0.137410, 1.599670, 0.142400, 0.350710, -0.015250, -0.898060,
-1.085130, 0.492860, -0.547590, 0.748490, -0.637490, 0.244850, -0.526770, 1.110160, -0.577410, 1.321440,
0.260310, -1.217080, -0.760200, 1.289350, 0.396730, -0.333360, -0.297220, -1.068970, -0.268900, 0.610530,
-0.400830, -1.466820, 1.124080, -0.911450, 0.983470, -0.029840, -1.428070, 1.802600, 0.331270, -1.448520,
-0.650320, 0.015120, 0.153200, 1.035780, 0.190040, 0.571000, -0.715000, 1.329350, -0.719010, 0.157140,
-0.260650, 0.558530, 1.047130, 0.735320, -0.572880, 1.088030, -1.330610, 1.545470, -0.307720, 0.294790,
0.148670, 0.766340, -0.324470, -0.319340, 0.534570, -0.316030, 2.101770, 1.598420, -0.290940, -0.026130,
0.853020, -0.141280, 0.006010, 0.002430, 0.343190, -0.096630, -1.705420, -0.736200, 0.482960, -0.002310,
0.819820, 0.258750, -1.032270, -2.223570, -0.086550, -1.469310, -0.996350, 0.410640, 1.175210, 0.182120,
-0.450090, -0.425550, 0.582190, -0.340390, -0.198970, 0.305610, -1.007460, 0.129790, 0.870500, -1.227100,
-0.902690, 1.177420, -0.156520, -0.561760, -0.623750, -2.485270, -0.950830, 1.000960, -0.720100, -0.806160,
0.759190, -0.579290, 0.648450, -2.261210, 1.129870, 0.182940, -0.188780, 0.810920, 0.329690, -0.364170,
-0.076260, 1.986990, -0.200500, -1.486220, -1.697090, -0.249090, 0.125770, -1.342670, -4.025780, -1.676360,
-0.441890, 1.994380, -1.662530, -0.584500, -1.262750, -0.992320, -1.129370, 1.741960, 3.249460, 0.938610,
-0.925190, -4.187450, 0.729300, 0.965330, 0.744590, 0.851150, -0.677700, 0.454910, -0.872240, -2.206210,
-0.014280, -0.007330, -3.921090, -0.240990, 1.790620, -1.103180, -0.266810, -0.502570, 2.348500, 0.491060,
0.869590, 2.012350, 1.410260, 1.039760, -2.548950, 0.741130, 1.795780, 1.318770, -0.665380, 0.226210,
1.977220, -1.174800, -0.668770, 2.696120, 0.112360, -3.725160, 1.424340, 2.098800, -0.609950, -0.112560,
0.000640, 1.764810, -1.345210, 0.226220, 0.336730, -0.455670, 0.743510, -1.066260, 2.353480, 0.329520,
0.723730, -0.819490, -0.347060, 1.332780, -0.688410, 1.191730, 0.704700, -0.115870, -3.234480, -0.731700,
1.374860, 0.805010, -0.802370, -0.018400, -0.461290, 0.991130, -1.416910, 0.701650, 1.826320, 1.077920,
1.596870, 0.849400, -0.395050, 1.711340, -1.321660, 0.755670, -0.541310, -1.714400, -0.516170, -0.389790,
0.741180, -1.035610, -0.210420, 1.489590, 0.357090, 0.028540, -1.287710, 0.256310, -0.515980, 0.445520,
0.122350, -0.468620, 1.590760, 2.838030, -1.871300, 2.407580, 1.013170, 0.746310, -0.163750, 0.032690,
0.980680, 0.148640, -0.055620, -0.288520, -0.064480, -1.073290, -0.231840, -0.353310, -0.246520, -2.337010,
-0.231220, 1.982950, 0.266970, -1.469610, -0.290610, -1.065510, 2.122800, 2.544320, 0.030970, -0.091060,
1.018730, 0.389920, 1.004950, -0.188540, 2.323210, -0.107050, 4.869360, 1.235970, 0.455860, 0.270960,
1.234520, -0.131900, -0.009720, 0.396990, 0.508260, 1.078480, 1.160650, -0.085050, 2.008890, 0.387410,
0.546500, -0.312780, 1.293110, 1.136510, 0.025730, 0.484070, -1.167230, -0.065120,
-0.028190, -1.152750, -0.202380, 0.376360, -1.565230, 0.377720, 0.755920, -0.953350, -0.754460, 1.384090,
-0.393620, -0.625670, 0.677600, 0.387200, -1.182630, 0.356140, 0.628180, 1.155290, -0.470120, 0.217950,
-0.834170, -1.022380, -0.092810, -0.825150, 1.116250, -0.620000, 1.394870, 1.036140, -0.046190, 0.588510,
-1.987080, -0.931990, -0.539650, -0.936470, 0.365420, 0.101150, -1.434820, 0.058800, 0.888080, 0.790970,
1.401470, 0.482590, 0.499310, 0.138430, -1.890340, 0.168870, 1.161160, 0.096820, -0.557330, 2.279550,
0.168850, 1.033560, -1.257800, -1.602230, 0.515560, 2.079950, -2.647910, -0.716820, -0.799620, -0.993660,
0.359240, 0.948160, -0.136220, 2.230580, 0.650630, 0.211100, 1.151960, -0.314800, -0.507060, 0.671920,
0.468790, -0.067300, 0.856140, -0.007570, -0.470240, -1.614300, -0.451340, 2.866300, 2.843450, 1.079280,
0.797580, 0.238020, -0.626930, 0.804060, -0.448630, -1.338120, -0.069500, -1.107770, 1.077560, -1.091020,
-0.298560, -1.150600, -0.588820, 0.374270, 0.459200, 2.350360, -1.330640, -0.921080, 0.098240, -1.177620,
0.019970, 0.614030, 0.143620, 1.470560, 0.563810, -1.138850, 1.261470, -0.079720, -0.535290, -0.665390,
1.474290, 0.364330, 0.198280, -0.059050, -0.077020, 1.047020, 1.362540, -0.945280, -0.142910, -0.366130,
0.455800, 1.253440, -3.044550, 2.231220, -1.110670, -0.710210, -0.567560, -3.542430, 0.803450, 0.300950,
0.255900, -0.823150, -0.432540, 2.000860, -0.322460, 0.880170, 0.858000, 1.166720, 1.874700, -0.506610,
0.713240, 0.003160, 0.719190, 0.849610, -1.750900, -2.660020, 2.014130, -0.278760, -2.908770, -0.752830,
-1.216940, 0.787720, 0.213990, -0.304030, -2.265960, 1.265840, -0.834140, -1.464050, 3.032980, 0.088870,
-0.387890, 0.452430, 0.267470, -0.848290, -0.601050, 0.313290, 1.463150, 1.281180, 0.577190, 0.737300,
1.366190, 1.139060, 0.264430, 1.064400, -1.310620, -0.401720, -0.125170, -0.496990, -0.023870, 1.500700,
1.058640, 0.110410, -0.893780, 0.431880, -1.225280, 1.581200, 0.387820, -0.005070, -0.339980, -1.679490,
1.153960, -0.276690, -1.993220, -1.748330, 0.757860, 0.174520, 0.730560, -0.671930, 0.327790, -0.960740,
-0.392130, 1.726520, 2.018360, 0.376060, -0.105580, -0.674590, -0.332430, 0.177140, -0.663110, 1.127260,
-0.954620, 1.328690, -0.099760, -0.970350, -2.064700, -0.005650, -0.795140, -1.027920, 0.486950, -0.844020,
-0.499990, -0.473900, -1.088100, -1.583000, 1.236810, 0.678450, -1.496880, -0.130580, 0.080660, -0.232990,
0.550890, 0.493240, 1.041990, 1.902350, 1.388190, -1.035510, 0.080920, -0.701700, 0.898600, 2.552840,
0.164490, 0.072410, 0.018050, -0.766700, 0.215140, 0.787970, 1.035270, 1.695430, 0.083370, -1.162560,
-0.296400, -1.058530, -0.765830, -2.629840, -1.141560, 0.122770, 0.779730, 0.146410, 0.147910, 1.484450,
-0.446590, -0.858350, 0.092670, 0.627530, -0.625470, 0.931710, -0.645550, 0.095640, -2.223110, -2.001790,
-1.255920, -0.370380, -0.522120, -2.927420, -0.849490, -1.560780, 2.132950, -1.665290, -1.128050, -0.490580,
1.935270, -0.596420, -3.010810, -0.890030, -1.686250, -0.191590, -2.120080, -0.074310, -1.458460, 0.408700,
-0.985630, -1.423880, -1.797390, -1.037810, -0.269180, -0.441550, -0.341200, -1.630390,
-1.375340, -1.620300, 0.166520, 0.317680, -0.779170, 0.002370, 0.466740, -0.793080, -0.643230, -0.194580,
1.107620, 0.971990, 0.234180, 0.468390, 1.123150, -2.619100, -0.914650, -2.082660, 0.253650, 0.656180,
-0.090010, -0.436270, 0.643500, -0.823360, -1.594220, -1.485380, -0.471180, -0.661240, 0.355560, 0.492760,
0.206120, 1.109220, -0.867580, -0.700710, 0.758460, 0.481950, -2.027410, -0.449590, 0.070030, -0.040120,
-1.856170, 0.496790, 0.669590, -1.052010, -2.056900, 0.393080, 0.322910, -0.134050, -1.731270, 0.099010,
-0.335430, 1.662890, 0.369010, -0.122760, -1.026640, 0.330210, -2.191080, -0.054070, 0.829720, -1.125640,
0.503860, 0.412560, 0.446200, -1.126400, 2.547990, 0.446650, -1.793250, -0.180050, 4.362360, 0.707900,
-0.214980, -0.104850, -0.159260, 0.124340, 0.609370, -0.501430, 0.316880, -0.608830, 0.892800, -1.399040,
-0.323930, -0.238370, 0.695910, -0.008690, -1.033220, -0.219610, -0.070890, 1.015720, 1.186140, -0.978000,
-1.066280, 1.238080, 2.612610, 3.409960, 1.851900, 1.102130, 0.044390, -0.637810, 0.087040, -1.302130,
3.495470, -0.813790, -3.230860, -0.239480, 0.830740, 0.704690, 0.298150, 0.826640, -0.962030, -1.139100,
3.318640, 0.907130, -0.193920, 0.155260, 0.640580, 4.571960, 1.084480, 0.216390, 0.740750, -0.789980,
1.864960, -0.388430, 0.016510, 4.825400, -2.874990, -6.412960, -0.677750, -0.835650, 0.679390, 1.019650,
-2.500840, 1.143070, -1.154910, 2.939070, 2.948420, 1.157510, 0.235020, -1.602170, -1.959660, 0.582930,
-0.921980, 2.816730, -2.088740, -0.545190, -0.559550, -0.101550, 0.132800, -0.739650, -3.975180, -1.045870,
0.908410, -1.874870, -1.109870, -1.200140, -0.801000, 2.647490, 0.715810, -0.456990, 0.554690, 0.627470,
2.514180, -1.043700, 0.176000, 0.840770, 0.144890, -1.441760, -0.174560, 0.819850, 0.269930, -1.605920,
-1.273430, -0.670590, -0.707040, 1.501740, 1.857090, -1.061910, 0.112010, 0.096930, -0.181680, 2.199220,
0.169430, -0.733700, -0.690240, 1.109470, -0.049680, 1.405590, -1.611720, 1.071890, 0.687550, -0.443040,
-0.068480, 0.459440, -1.828390, -0.105890, -0.195860, 0.860960, 0.454070, -0.490390, 2.505910, -0.958620,
0.147190, 2.019130, -1.819670, -1.664860, -0.190010, 0.046760, -1.318240, -0.615060, -1.000200, -1.513830,
1.585720, 0.401180, 0.653440, 0.801740, -1.122720, 0.969520, -0.528940, 0.749900, 0.867490, -0.133190,
-0.569570, -0.064910, 0.458500, -0.704010, -0.033930, -0.378100, -0.651530, -1.180460, 1.001990, 0.019160,
-2.095200, -0.432450, -1.065790, 0.167570, -0.246200, 0.017250, -0.550850, 2.505670, -1.542340, -0.604490,
-3.191520, -0.257200, -1.469540, -1.437480, -0.371450, -1.275390, 0.079830, 0.061120, 1.930960, 0.567060,
-0.033490, -0.238010, -0.534620, -1.272540, 0.614190, -1.738440, -0.048220, -1.216800, -0.880500, 0.071820,
0.531800, 1.145790, -2.127060, -0.786310, 4.844030, -0.131140, -0.611700, -0.698240, 0.920690, 5.362250,
-0.269130, 0.746360, -0.916800, 0.695150, 0.771450, 0.857670, 11.840720, 0.423630, 0.094050, 0.839870,
10.659960, 0.153830, -0.690740, 0.984100, 0.235780, 3.461170, -0.088380, -0.068270, 0.906160, -0.173420,
0.287790, -0.359860, -0.526080, 4.904020, 0.681440, 1.535460, -0.416190, 0.873840,
-0.921670, -0.846680, 0.146110, 2.262020, -1.272450, 0.716020, 1.283430, -1.251300, 0.216550, 0.104840,
0.394090, 0.241500, -1.408630, 0.136020, 1.668590, -0.424330, -0.503530, 0.198670, 1.576440, -1.305000,
0.337300, -2.594060, -0.570090, -0.728110, -0.326100, 1.141200, 0.293470, 1.333690, 0.335430, 1.042030,
-1.340510, 0.463080, 0.609970, -1.518940, 1.617800, -1.963840, 1.117210, 0.766810, -0.012600, 0.644300,
0.335870, 0.201560, 1.245380, -0.895330, -0.875220, -0.268570, 0.186460, 1.940570, 2.929600, -2.164370,
-0.204490, 1.241410, -1.175300, 0.038200, -0.557390, 0.846690, -0.605690, -1.489070, -1.124770, -0.342070,
-0.936460, -1.257510, -1.391970, -0.954530, 1.334200, 0.417630, 0.064320, 0.845110, -0.462360, 1.081170,
4.488780, 3.048060, 4.665400, -0.616400, 4.386440, 0.765720, -2.448580, 0.322110, -0.473160, -1.117080,
0.369900, -0.983200, -1.399220, 0.719080, 0.117170, 0.642610, -0.724830, -1.423540, -0.348500, 1.811350,
0.627410, -0.248820, 1.510430, 0.828610, -0.741560, 3.882480, 1.138420, 0.683990, -0.958180, 0.422020,
0.652850, 1.020990, -3.378630, -0.982450, -0.162700, -0.195650, -0.046500, -0.125630, -0.106770, 0.025820,
2.650590, -0.645110, 0.985400, 0.573670, 0.620380, 0.247080, 1.974830, -1.285400, -0.209800, -0.585700,
0.013090, -0.233490, -1.014010, 0.511040, 0.237990, -1.622880, -0.371250, -0.453020, 1.109950, 0.374390,
-0.523160, -0.099540, 0.551560, 1.129510, -0.374580, 1.583690, 1.236110, -0.201010, 2.656700, -1.738380,
-0.880500, 0.250780, 0.760370, 1.462830, 0.136800, 0.780130, 1.355830, -2.741190, -3.441790, 0.512310,
-0.944060, -0.783670, 0.981360, -2.755440, -1.255960, 0.433600, 1.612720, 0.887410, 0.038380, -0.676100,
1.593610, 0.126570, 0.486700, 0.419080, 2.064380, 1.552610, -0.625210, -0.376490, -0.686790, 1.955200,
1.832340, -7.823750, -1.166800, 1.842910, -0.155490, 1.176390, -1.478250, -1.985700, 1.409690, 1.061100,
1.296400, 0.003160, -1.920940, -0.736640, -0.540270, 1.311070, -1.172090, 0.351440, -0.991990, 0.001500,
-0.442180, -0.933310, 0.255660, 1.534330, 0.222920, -0.132550, 2.447430, 0.150990, 1.396550, 0.966640,
0.426500, 1.712190, -0.057990, 0.261650, 0.485460, -0.259640, 0.058890, -0.739760, 0.804190, 1.302420,
-1.829730, 1.289850, -2.917720, -0.069330, 0.002510, -1.952700, -0.325590, 0.393640, 0.478050, -0.122280,
1.669370, 0.999870, -1.375730, -0.310710, 0.830560, 3.228380, -0.595250, -0.516240, 0.676350, -0.796190,
2.342810, -1.443980, 0.500990, 4.631640, -0.425400, 0.294480, 1.114160, -1.762720, -1.328930, 1.431840,
-1.354880, 0.924440, -1.031830, -1.026290, 0.928790, 0.351300, -0.292240, -2.928840, -0.496440, 0.641860,
-0.528990, -0.801340, 0.282990, 0.762410, 0.958620, 0.233640, -0.775720, 1.407550, -2.437020, 0.258560,
-1.215380, -1.348550, 0.327140, -0.802930, -4.868350, 1.358400, -1.488810, -0.414660, 0.573980, 0.222970,
-0.142450, 0.474050, 0.434850, -1.832000, -0.692380, 0.043420, 0.680360, 0.374250, -0.373550, 0.186920,
2.264420, 0.416910, -0.266140, 0.597580, 0.873980, 0.892110, -0.746870, 0.990330, 0.338310, -0.130220,
0.533030, 0.025730, -0.864930, 0.740230, 0.319140, -1.169140, 0.063140, -0.610480,
0.303910, 0.439210, 0.368490, -2.742220, -0.416850, -0.386940, 0.408760, -0.377660, 0.576210, 0.556430,
1.329310, -0.304930, 0.256510, 0.876730, 0.264160, -0.588680, 0.210340, -0.545720, 0.888330, 0.284790,
-2.151760, -0.027960, -1.443790, 0.396550, 0.228100, -0.644220, 0.772920, 0.429000, -0.965870, 0.284840,
0.798280, 1.559710, -0.206750, -0.375870, 0.980270, -0.574710, 0.912690, -0.716130, 1.121600, 1.590210,
0.499470, 1.336900, 0.025440, 0.200830, 0.599820, -0.549100, -1.695120, -0.039000, 0.447760, 0.216410,
-1.455080, -0.236440, -1.479110, -1.383210, 0.218810, 0.287850, 2.416400, 1.197560, 0.915300, -0.182560,
-0.993450, -1.202870, -0.732800, 0.732680, 0.658540, 0.861050, 0.713510, 0.937450, -0.424270, -0.479090,
-0.192480, 0.001930, -0.062500, 0.168350, -0.472470, 1.170460, 0.608270, -0.118210, 1.553050, 1.122870,
0.098240, -0.300470, -0.482130, 0.494990, 0.062550, 0.698110, -0.520390, -0.546260, 0.755820, 0.028570,
1.171470, -1.237150, 0.611710, -3.255680, 0.027310, -1.098430, 0.825780, 0.018740, -0.205800, 1.033490,
-0.478350, -0.873140, 1.513860, -0.098350, -1.882950, -0.182530, 0.149410, 0.723500, -1.671340, -0.038650,
-0.475630, 0.994080, -0.353050, -0.383290, -1.715760, -0.376540, -2.059280, -0.645290, -1.960160, 0.210650,
-1.945740, -0.168470, 0.829540, -0.144310, -0.996510, 0.894870, 1.873300, -0.888050, 2.226950, 1.589340,
0.005810, -3.320940, 1.692250, -1.771020, -0.812990, 0.136150, 1.210910, -1.015960, 2.420470, 0.962630,
-2.159470, -4.439540, -0.070990, 1.482180, 0.769220, -0.459700, 0.984950, -1.483550, -2.242890, 0.446420,
-0.478530, 9.333230, 1.071590, -1.099750, -3.594020, -1.825220, -1.034170, 0.892830, -0.978020, 2.276010,
-2.534090, 2.319440, 6.042220, -3.936580, -7.935510, 0.270880, -0.263470, -0.155910, 0.193040, 1.575620,
-0.568430, -1.731660, 0.342830, 0.573420, 6.112570, -1.612080, 1.345450, -0.893980, 0.309300, -1.756410,
-1.878270, 1.464920, -0.938750, -7.929730, -0.644560, 4.365030, 2.579260, -1.201350, 0.888480, -0.047850,
-0.630490, 1.503180, -0.414920, -2.060980, -1.237320, -1.407100, -0.789200, 3.688460, -0.287350, 1.443440,
0.111330, -0.129710, -0.352950, -2.428620, 2.011990, -0.596450, -2.486040, -0.540250, 0.341610, -1.866680,
1.207910, -0.124020, 0.485140, -0.726640, -0.235450, 5.943600, 1.221240, 0.001250, -0.948780, 1.627450,
0.989990, 0.948970, -0.532230, -1.781790, -1.032400, -0.443540, 0.015910, -0.342850, -0.882860, -1.122150,
-0.227500, 1.238200, -0.611720, -0.686220, -0.534960, 2.543560, -0.011610, 0.884350, -0.271450, 1.081600,
-0.211420, 1.814750, 0.215900, 1.509830, -3.664420, -0.296430, -0.182750, -0.833090, -0.835910, -0.860410,
0.074180, -0.968450, 1.651770, -0.132850, 0.954700, -0.121610, -0.040260, 1.078430, 1.103710, 2.345110,
1.056570, 0.231660, -0.333930, -0.912380, 1.734540, 0.128930, -0.022800, 0.738390, -0.756380, -3.698490,
-0.466820, -0.072340, 0.866060, -0.501350, 0.360730, -0.412350, 0.694630, 1.960720, -0.463220, 0.404720,
-4.531680, 0.051340, -0.286670, -0.183600, 0.059030, 0.874900, 0.748970, 0.795010, 0.182660, -0.300120,
0.574320, -0.643600, -1.143080, -0.980420, 0.814810, -0.249450, 0.690170, -0.649950,
0.975570, -0.750000, -0.323520, 0.412060, -0.091570, -0.661870, -0.338510, 0.158590, -0.325760, 0.283650,
0.051970, -0.416560, -0.256200, -0.037670, -1.328590, 0.484370, -0.839240, 0.654340, 1.024340, 0.194520,
0.201070, -0.102690, 0.008750, -0.229850, 0.547740, 0.696240, 1.022010, -0.412570, 0.369780, -0.758360,
0.751570, 0.305260, 0.467230, -1.224810, -0.805040, -0.714060, -0.288280, -0.725410, 1.136390, -0.266190,
0.496520, 0.746900, 0.472040, -0.007670, -0.275250, -0.344120, 0.333600, 1.364470, 1.523350, 0.606980,
-0.273560, 0.354680, 0.659360, -0.940840, 1.948390, -0.842900, -0.698580, -0.510580, -0.287710, 0.526120,
0.113740, -0.205690, -1.019650, 0.991160, 0.133190, -0.868180, 0.289420, 0.974240, 1.288820, 1.490510,
1.402860, 0.014990, 0.501870, 0.716680, 0.775400, -0.911780, 0.229240, 2.260430, 0.337120, -0.435220,
-0.443160, -1.335370, 0.429620, 1.504270, 0.045800, -1.862900, 2.272530, -1.098230, 0.408090, 0.235680,
2.510690, 0.016820, 0.768280, -0.318320, -0.402520, -0.052090, -0.887690, -1.297130, 0.028160, -0.710970,
0.292300, -0.092670, 0.282240, 0.177100, -0.320230, 1.875300, 0.732230, -0.075740, 0.012960, -0.170950,
-0.271380, 0.045540, 1.040930, -0.056530, -0.197760, 1.197380, -0.152930, 1.095150, -1.438310, 0.634730,
-0.359310, -1.104440, 0.590890, 1.450590, 0.946830, -0.278680, -0.355270, 0.292410, 0.122750, 0.340520,
0.461130, 0.368250, 0.265540, 0.036540, 0.466340, 1.774780, -0.263320, -1.641660, -1.498490, -0.769050,
-1.410720, 1.421530, -0.326660, -0.545310, 1.972310, -1.806040, -1.788650, -1.352480, 1.311280, 0.420300,
0.295460, 1.144320, -0.090810, 1.169240, -0.572540, -0.665530, 0.600890, 1.099630, -0.423440, 0.752810,
0.727350, -0.645820, -1.265080, 0.103100, -1.822240, -0.439750, -0.001270, 0.527980, 0.081910, -1.442220,
-0.028010, 2.361280, -1.965920, -0.292810, -1.890610, 0.804890, 0.318960, 0.122400, 1.042400, -1.301880,
0.638360, -0.526660, -0.623580, 0.170300, -0.955700, 0.136570, -1.350600, 0.898210, 0.085500, -0.920170,
0.703640, -2.668400, 0.502680, -0.693640, 3.841720, -0.631760, 0.096940, 0.575680, -0.337570, 0.401060,
0.465400, -0.750570, -0.369710, -0.724750, -1.079320, 0.560570, 0.784540, -0.150800, 1.037460, -0.281410,
-0.106560, 1.319030, -0.544290, 0.578560, 1.188140, 0.498360, 1.152900, 1.741970, 1.356400, 0.802410,
-0.004550, 0.748880, -0.230310, 0.999060, 0.327820, -0.900450, -0.430220, -0.000940, 0.089920, -0.186490,
-0.948490, 0.397130, -0.196920, -1.302070, 0.631140, 0.045420, -0.389720, 1.093090, 0.432480, -0.507100,
0.482780, -0.067240, 0.737700, -0.201040, 0.620340, -0.298810, 0.618540, -0.432890, -0.826320, -1.048720,
0.466140, 1.212560, 0.148300, 0.591020, 0.733910, 0.519990, 0.609140, 0.573770, 0.963410, -0.172560,
0.701270, 0.463750, 0.503840, 0.705510, -1.456260, -0.786380, 0.030790, 0.109430, -0.949260, -2.983160,
-1.135860, -1.444970, -1.186810, -2.112870, 0.024810, -0.693810, -8.056500, -0.567650, -0.871980, -1.090630,
-1.946270, 0.034720, -1.186730, -1.225660, -0.302800, -0.966880, -0.567760, -0.961210, -0.039230, -1.498850,
-1.966850, 0.236270, -3.494980, -2.430600, -2.211010, -0.122940, -0.750870, -1.389980,
0.094310, 2.157470, 0.193570, -1.394060, -0.861520, 0.631810, 1.114840, -1.005270, -0.048500, 1.510630,
-0.352680, -0.716800, 0.938140, -0.362440, -1.541990, -0.658660, -0.289660, -0.403760, 1.614500, 0.378160,
-1.672420, -0.624100, -0.580790, 0.151950, -1.587270, -2.974490, -0.698980, -1.288690, 0.756350, -0.417380,
1.162270, 0.854960, 0.068930, -1.471560, 0.026990, 0.516600, 1.119640, -0.655760, 0.803720, -1.870570,
-1.234980, -0.536940, 2.112070, -0.086930, -0.409710, -0.509250, -0.623210, -0.087650, -0.385010, 1.463390,
-0.643270, 0.437890, 0.042360, -1.005150, 0.497170, 0.399750, -1.740660, 0.209090, 0.075020, -0.040110,
-0.423930, 2.360540, 0.082180, 0.051550, 0.820620, 0.070800, -0.955720, 0.929280, -1.261380, -1.164110,
-0.337730, 0.394060, 2.541570, 0.003330, 4.112460, -0.741350, 1.911500, 3.382370, 0.496360, -2.738190,
-1.319470, 4.136740, -0.994080, -0.023170, 0.392600, 0.353650, 2.453030, 1.228330, 0.182240, -1.132680,
-0.068420, 0.462670, -2.728770, -0.938520, 0.111470, 5.367540, -0.166860, -0.134320, -0.520600, -1.849950,
-0.877490, -0.452010, -0.243560, 3.447220, 1.269220, -0.271750, -0.962250, 0.172580, 1.255370, -0.390880,
0.855930, 1.838110, -0.982810, -1.197250, 1.069530, -0.451140, -7.025890, 2.547270, 4.911960, 0.239080,
0.253420, 0.583860, -0.767600, -3.126830, 3.832450, -0.162720, 0.731290, -0.472380, 2.015120, -0.344910,
1.438240, -0.182660, -0.606260, 3.005420, 1.208970, -2.357980, -0.733960, 2.343520, -1.402390, -2.680000,
0.017960, 3.449200, 0.162850, -0.375390, 0.074230, -0.109650, -0.287950, -3.081440, -2.027660, 0.268880,
1.276770, -0.131590, -0.908960, 0.783150, 0.629610, 0.063820, 2.201820, 2.501100, -0.898780, -0.264620,
0.254100, -0.000180, -2.474180, 0.663330, 3.602240, 0.869030, 0.014010, 0.432870, 2.793060, -1.756550,
0.646220, -1.579320, 0.314720, 1.682360, -0.443760, 0.599700, 1.250280, 1.260340, -0.898310, 2.514070,
2.115710, -0.826160, 0.029220, 0.881860, 1.796170, 5.460100, 0.513810, 3.725370, 1.012310, 0.353700,
-1.218860, -1.216950, 2.961750, 1.192090, -0.336980, 0.625250, 1.425050, -0.927610, -1.628700, 0.031090,
0.130020, 0.295760, 1.888480, -0.065050, -0.560830, 1.046360, -0.378350, 0.168820, 2.391930, -0.695060,
1.372410, -0.288480, -1.522300, -0.893960, 0.020600, 0.288260, -2.582260, -0.832330, -0.015650, -0.776350,
-0.090610, 0.296810, -0.004620, -0.438770, 1.494260, -0.660290, 0.819080, 0.919690, 0.992820, 1.450330,
-0.530880, -1.963510, -0.642060, -1.098240, 0.651690, -0.014830, -0.449080, 0.838680, -0.059850, 1.543040,
-2.748470, -0.887560, 0.144270, 0.707390, -1.969990, 0.797870, -0.127560, 2.578570, 1.116300, 1.026870,
-0.138260, -0.485820, -0.823630, -2.044910, -0.877310, -0.967390, -1.177680, -0.474090, 0.496560, -1.729440,
-1.169950, 0.901310, -0.119060, 1.437550, -5.021060, -0.460840, -1.236390, 1.883780, 1.813700, 1.677140,
0.082190, 0.404840, 0.188360, -1.854790, 0.491220, 0.749780, 1.138180, 0.883610, -0.863500, 1.685630,
6.334120, 0.849810, -3.352340, -0.520420, 0.090580, 0.652460, -1.128860, -0.950120, -0.065000, 0.280480,
0.033860, -0.259550, 1.905150, 0.373580, 0.656700, 0.171730, 0.455040, -0.484600,
0.640700, 0.640450, 0.533280, 1.400780, 2.576380, -0.556060, -0.378600, -0.705020, -1.395900, 0.351470,
-1.256370, 0.962540, 1.192990, -0.328970, 0.912370, -0.579680, 0.154730, 0.882850, -1.647920, 0.363770,
0.420370, -0.610210, 0.831740, 0.484190, 0.181870, 1.050000, 2.866060, 0.893310, -0.509430, -1.041920,
0.114310, 1.353850, 0.360230, -1.685250, -0.317550, -0.025630, -0.273490, 0.048110, -0.800220, -0.175590,
0.304030, -0.887300, 0.914490, 0.740530, -0.635330, 0.377790, -1.313480, -0.064650, -0.277580, 0.371240,
-0.866470, 0.056550, -0.587120, 1.147140, 0.540790, 0.231170, 0.257010, -0.915340, 1.405130, 0.759720,
0.705280, 0.436660, -0.813070, 1.229390, 0.326800, -0.383890, -0.957370, -0.372330, -0.182270, 0.349060,
0.347650, -0.198000, 2.033030, -0.173500, 0.544190, -0.859880, 0.346520, 0.055100, 1.619510, -1.542310,
1.526100, -0.772090, -0.896870, -0.110760, -0.688840, -0.346150, -0.000120, 0.574200, -0.469650, -0.108830,
0.434450, 0.669710, -0.645910, 0.522780, 1.129850, 0.959660, 1.965430, 1.242230, 0.314790, -0.874630,
0.921880, 1.127870, -0.079290, 1.987260, -0.920920, 0.739930, -0.728120, 0.875750, 0.439740, 1.117030,
1.561670, 1.276100, 0.041400, -1.306200, -0.187850, 1.227050, -1.671360, -0.175890, 1.401530, 0.971830,
0.200580, -0.610620, -0.590880, 0.480490, -0.992690, -0.787600, 0.470410, -0.741670, 1.340490, 1.038160,
-0.331470, -2.086290, 0.602000, 1.374700, 1.400800, -0.606580, 0.569920, 0.779450, 1.505060, 3.912530,
0.608180, -3.842280, 0.624100, 0.356210, 3.475770, 0.602040, 5.085770, -1.222190, 0.287520, -0.203350,
-3.899470, 3.527070, 1.869130, 1.356380, -2.098150, -0.813270, -0.380730, 0.621470, 0.130990, 2.593790,
-0.355300, -0.046480, 3.660280, -0.001940, -3.437940, 1.615820, 1.258780, -0.546270, 1.287780, 1.864480,
-2.014270, 0.055600, 0.817870, 0.529220, 1.959930, 0.030710, -0.505590, -1.344780, 1.355590, 0.729500,
-0.159630, -0.085470, -2.019630, -1.545390, 0.768740, 2.931680, -0.951620, -1.102640, -1.697690, 1.448180,
2.058600, -1.399820, -0.129610, -0.201900, 0.491600, 0.415920, -0.096380, -1.243250, 0.356340, -0.709070,
0.159080, -0.630100, -0.649040, -0.292390, 0.175840, 0.835850, 0.095780, -2.216240, 6.452530, 0.114860,
-0.805850, -0.801070, 0.830330, 2.071720, 1.597310, 0.868680, -0.016900, -0.529200, 1.316380, -0.088500,
-0.219940, 1.143430, -0.013070, 0.679780, -1.065140, 0.336700, -1.599770, -1.039880, -3.559630, -0.568110,
-1.137250, 0.815170, 0.212600, 1.687430, -1.978220, -0.075760, 0.568960, -2.034240, -2.009730, 0.793670,
1.804880, 0.448270, 0.572720, -0.685950, 1.479450, -0.534390, 0.926240, -1.068920, -1.855500, -0.518850,
-1.205100, 0.414110, 1.868290, -0.425190, -1.032760, 1.728960, 0.346630, 0.287120, 0.381240, -3.681100,
0.015770, 1.123830, 0.582730, -0.821280, -2.433610, 0.368010, 0.877350, -0.416330, 0.470130, -0.979180,
0.961940, 0.765080, -0.857530, 1.381620, -0.453860, 0.441450, -1.207740, -0.964160, 1.150540, -1.004460,
-3.756230, -0.477590, 1.152560, -1.041480, -0.278690, 0.437450, -0.314070, 0.068890, 0.064250, 0.270480,
0.558850, -2.718530, -1.784970, -1.002240, -0.383510, 0.745630, -0.393370, 0.587500,
0.717370, -0.582040, -0.381150, 0.313000, 0.226760, -0.873720, -0.187770, 0.479760, -1.136370, -0.093430,
-1.569830, -0.278900, -0.190590, 0.322700, -0.358160, 0.873130, 0.218300, 0.229780, -0.755100, -0.260690,
0.781770, -0.317030, -0.857550, -0.157160, -0.022210, 0.877460, -0.596830, -1.321170, 0.749600, 0.642950,
-0.269520, 0.470030, 0.554350, -0.413340, -0.092260, -1.113010, 1.785880, 1.596650, -0.122830, 0.934170,
0.738270, 0.414090, 0.814230, 0.106560, 0.172670, -1.217150, -0.018640, -0.126110, -0.324590, -0.004910,
-2.051680, 0.487940, -0.627140, -0.803710, 1.177320, 0.419990, -1.807410, 0.500380, -0.525500, -0.349200,
-0.687060, -0.745730, -1.096310, -1.326050, -1.148200, -2.187360, 0.834550, 0.672610, 0.087400, 0.232090,
1.864340, -0.462590, 0.351610, -0.681870, 0.038490, 1.737630, -0.980860, -0.192870, -0.451890, -0.038420,
0.609830, -1.041180, 2.278920, 0.577440, 1.083790, -1.000370, 0.642190, -0.511020, 1.252320, -0.296720,
-0.729860, 0.309640, 1.278870, 0.968390, -2.380130, -0.650750, 0.481830, 0.779340, 1.028490, 1.467020,
1.261990, -2.847990, -1.850650, 0.140610, 0.407140, 0.681710, 0.702800, -2.021450, 0.066850, -0.688660,
-0.882280, -0.077770, -1.265010, -0.210430, -1.643340, -0.505630, 1.938410, -0.938390, -0.543580, 0.840380,
-0.312600, -0.159110, 1.872510, 0.054190, -0.301920, -1.486560, -0.847180, 1.043900, 0.437730, 0.134730,
0.049350, -1.532910, -0.975060, 0.710860, 0.786430, 0.755100, 0.894000, 1.154670, 0.902710, 3.436230,
-0.889150, 0.866840, -1.319870, 0.365070, 0.151680, 0.795260, 0.339900, 2.093510, -0.950380, -0.444030,
2.723140, -0.861930, 0.320170, 1.169410, -1.201290, 1.844740, -0.255370, -0.376830, 1.067940, 0.320300,
-0.967490, -0.157790, -0.649590, 1.475120, 0.985010, -0.899560, -0.594750, -0.561490, 0.743610, 1.600300,
3.427610, 0.115080, -0.547080, 0.866130, 0.983070, 0.291340, 0.691500, -0.522410, -0.332870, 1.043770,
0.579400, 0.538260, -0.880000, 0.155180, 0.367790, -2.019140, -0.482840, 2.138030, -0.116880, -0.632300,
-0.514010, 0.120420, -0.173740, -1.065180, -0.236180, -1.576100, 0.380360, -0.755360, 0.998430, 0.063900,
0.603620, -0.858840, -0.205110, 1.122500, -1.320740, -0.822100, 0.498640, -0.010660, -1.369130, 0.846500,
2.405150, 0.091590, -0.487140, -0.172530, -2.162560, 0.267150, -0.580600, -0.226840, -1.981960, 0.136490,
-2.122640, -0.440120, 0.392810, 0.058670, -0.281870, 1.186980, 0.605020, 0.103430, -0.181740, -0.542410,
-0.812580, -1.079320, 0.911920, 3.039050, 1.530470, -1.987710, -0.148790, -1.112310, 0.837620, 0.861060,
-0.814470, 0.088010, -0.290840, -1.218590, 1.337360, -0.969990, -0.518520, 2.944200, 0.609950, -0.022780,
1.016070, -0.151960, -1.167600, 0.511750, -1.176910, 0.933900, -0.340110, -1.763720, 0.034110, 0.657930,
0.723790, 0.436940, 0.354650, 0.971810, -0.977320, -0.496590, 0.250320, -0.533850, -1.189440, -1.495700,
-0.329570, -0.299830, -2.072480, -5.071990, -1.173320, -1.976110, 0.832780, -1.533050, -1.163700, -0.412220,
0.202220, -2.328010, -2.280840, -1.394340, -0.262900, -1.273680, -1.812300, 0.242100, -0.497520, -0.359190,
-3.596420, -2.506180, 1.128520, 0.396870, -1.545430, -0.982650, -0.817590, -0.970230,
0.691920, 0.861000, -0.494820, -1.183950, -0.230210, -1.077230, -1.769230, 0.741770, -1.265960, -0.018660,
0.803150, 1.294790, 0.190310, 0.619980, -2.316490, -0.817940, -0.126150, 0.775030, -2.947560, 0.395460,
0.159120, 0.077290, 0.537380, 0.550290, 0.481320, 0.328210, -2.270210, 0.073540, 0.370230, -1.248550,
0.432500, 2.340000, 0.991810, -0.241980, -0.878930, 1.441790, 0.052970, 0.793770, 1.136890, -1.239370,
0.672320, -0.657140, 0.179310, -1.525620, 1.332110, 0.312200, -0.084100, -0.067200, 0.054560, -1.656140,
1.006260, -0.234260, 0.790830, 1.270280, 0.555560, -0.533220, -0.129520, 0.848970, -0.135830, -0.080980,
1.170070, 0.411210, 1.338970, 0.447130, 1.478460, -2.887490, -0.420350, 1.134500, 0.784640, 1.991360,
1.304050, -0.536840, -5.396290, 1.087580, -1.112470, 2.897020, -0.986180, -1.921010, -1.370330, 0.039840,
1.162710, -1.029290, 2.785640, -1.889300, -0.502170, -1.064830, -0.163020, 1.664260, -0.825380, 1.015400,
1.093700, -0.189130, -1.007130, -0.792170, 0.737440, -4.481730, 0.343050, 0.555610, 1.322880, -0.195020,
0.422470, -0.061870, 3.229340, -0.534080, 0.125820, 0.886180, 1.759660, -1.155070, -0.395580, 0.168140,
-1.378410, -2.574960, 0.672320, -0.009060, -0.232970, -0.789230, -0.024690, 1.332590, -3.886270, 0.604710,
-0.659910, 0.014800, 0.831300, -0.411230, -0.606150, 1.509030, -0.536700, -0.474160, 0.857090, 0.339450,
-1.540350, -0.240290, -0.344770, -1.643460, -3.078960, 0.388930, 1.669350, -1.371600, -1.767370, -0.010630,
0.701880, -2.814180, -0.909000, -2.117200, -0.325300, 2.193360, 1.036050, -0.076990, 3.327060, 0.775110,
-0.590660, -1.200530, 0.841130, 0.070800, 0.933540, -0.153090, -1.140960, -1.893640, 0.720180, 1.645960,
-0.638030, -0.536880, 2.469590, -2.417530, -2.082020, 0.502030, 0.548530, 0.868750, 1.014600, -0.780430,
1.041700, 1.940900, -0.585740, 0.423890, -0.475970, -0.908430, 1.670590, 0.017940, -0.200610, -1.389810,
1.740970, 0.275990, -1.116400, -1.822820, -1.827270, 7.266980, -0.590430, -2.758820, 0.184200, 1.624920,
-0.674570, 1.876440, 1.086590, 0.032990, 3.305060, -0.179240, -0.080250, -1.348340, 0.982910, -1.082550,
0.007520, -1.541390, -3.566940, -1.527140, -0.842610, -1.115140, 0.104910, -1.193550, 4.138290, 0.542020,
-2.556290, 1.248250, 0.960790, -2.454890, 1.069490, -1.045330, -0.485410, 0.584030, -1.752270, 0.485800,
1.564930, 0.893680, -0.917400, -0.998120, -1.374700, -6.055370, -2.636020, 1.671400, 0.250680, -1.120690,
-2.854650, 2.618710, 0.327090, -3.746400, -0.877410, 1.571220, 1.679810, 2.213010, 1.950080, -0.860780,
1.617040, -2.187770, 0.824940, -0.480570, -0.460340, -1.908660, -2.145440, 1.712800, -1.785890, 0.617940,
-1.279470, -2.098320, -1.171220, 1.213250, 0.467690, -0.979050, 0.334920, -2.653490, -2.121440, 0.797260,
-1.106710, 1.368970, -1.754260, 2.160880, -0.102460, -0.041020, -0.569180, 1.161070, -0.084340, -0.518240,
-0.239110, -0.906570, 0.604580, 1.787000, 0.766800, 0.479190, -0.234490, 0.642140, -0.422550, -1.054630,
-5.822930, 0.264270, 1.716110, 0.286660, -0.603350, -0.996180, -0.091570, 0.575230, 1.003430, 0.913030,
0.545080, 0.197410, -0.828690, -1.957690, 0.053080, -0.019730, 0.206220, -0.478380,
-0.048600, -0.433380, -0.246750, 1.049930, -0.335540, 1.324390, 0.326760, -1.222020, -0.614330, 1.025510,
-1.204270, -0.937150, -0.856020, 0.319240, 1.635200, 1.832610, -0.709690, 0.598670, 0.224430, -0.170080,
0.174960, -0.451610, -0.267930, -0.844510, -1.074850, 0.390620, 1.693890, 1.082870, 0.492150, -1.332800,
-1.331800, -1.481960, 0.583720, 0.510780, 2.248690, 0.012990, -0.352530, 1.013500, 0.365710, 1.251040,
2.089250, -0.945650, -0.473030, -1.472280, -1.767950, -0.549450, -0.918940, -0.396860, 2.063400, 3.238340,
-0.334210, 0.235040, 0.992230, -0.716640, 0.840490, -0.053200, -1.027820, -0.081970, -1.835570, 0.679300,
0.798640, -1.769500, 1.221910, -1.696450, 0.147230, -0.440500, -0.048490, 0.458670, 0.610960, 2.711140,
3.172840, 0.399830, -0.551660, 0.469930, 0.979620, -1.699810, 1.038620, -2.213540, 0.948600, -3.160390,
0.275080, -0.368390, -0.645500, 0.422960, 0.398460, 0.185460, 2.437130, 3.972930, -1.551180, -0.565350,
-0.783810, -0.299660, 3.978740, 7.584380, 1.004000, -1.586690, 0.228830, 1.472600, -2.516340, -2.614800,
5.087550, -2.051050, -1.948730, -0.293420, -1.343760, 2.078850, 1.813750, -0.861240, -2.021360, 2.773780,
-2.158200, -1.211910, 1.392300, -1.776060, -2.350430, 0.526460, 3.788050, 2.386620, 0.804980, 0.649730,
0.562510, -0.221030, 0.257920, -0.224850, -0.813080, -5.031290, -0.813930, -1.396720, 1.884890, 0.534510,
0.217480, -1.574570, -1.033290, 0.209740, -0.201560, 1.092280, -0.464880, 0.769930, 0.354280, 1.807020,
-1.599430, -0.248760, -0.098020, -1.603420, -1.106090, -3.455960, -0.902260, -1.170820, -1.398880, 2.644130,
-0.122790, 1.532950, -0.033580, -0.904730, 0.358680, -0.311940, 1.964610, 1.969650, -0.195640, -0.293040,
-0.846750, -0.017640, 3.500720, 0.605460, -1.825770, -0.524340, 2.210630, -0.092490, -0.399750, -0.444190,
-0.663860, 0.785080, 1.314630, -2.134760, 1.554940, -0.479580, -0.343210, -1.305840, 0.544710, -0.289350,
-0.183130, -0.132140, -0.684250, 2.153110, 0.963840, 0.239350, 0.830580, -1.207430, 0.445670, 1.259970,
0.707960, -0.007890, 0.164800, 2.121360, -1.407680, -1.987280, 0.703730, 0.118000, -1.088530, -0.247510,
-0.572500, 1.018990, 0.426660, 0.594580, 0.749450, -2.069600, -1.716850, 0.305410, 1.588410, 1.422490,
0.468370, -1.359410, 0.102760, 0.986410, 1.432180, -0.277000, -0.117330, 1.173650, 0.832200, -0.198190,
0.136880, -1.482860, 0.199940, 0.715790, -0.211490, -0.189450, 0.447710, -0.019680, -1.029860, 0.499950,
-0.403010, -0.385370, -0.825370, -0.129330, 0.038610, -0.348110, 2.798160, 0.339800, 0.231040, -0.266970,
-0.578230, 1.410830, 0.094620, 0.091800, -0.011360, -0.911810, -0.189650, -2.479230, 0.197460, -1.964240,
-0.371860, 0.304280, 0.382730, 0.911100, 0.734100, -0.579140, -1.624550, 1.211160, 2.632030, 1.844920,
0.772110, -1.435240, 0.470110, 1.394300, 1.637490, -0.782670, -0.786370, -0.242630, -0.726930, 2.207540,
0.430780, -0.884730, 0.497970, -0.548040, -1.355080, 0.150240, 9.266680, -0.190410, 0.156830, -0.046580,
-1.959170, 0.359730, -0.715260, 0.774000, -1.646310, -0.055180, 0.007480, -1.282770, -0.476710, -0.236670,
-1.050380, -3.257410, -2.283440, 1.338810, 0.195480, -0.216310, 0.982160, -0.092670,
-1.264240, -0.250660, -1.448000, 0.154690, -0.109350, 1.744650, 0.719700, 0.351780, -0.186200, -0.538750,
-1.518160, -0.492070, 0.670630, -0.688530, -0.487900, -1.503930, 1.796480, -2.314750, 1.586810, -2.180110,
0.369260, -3.834270, 0.169090, -2.287130, -0.504130, -1.620520, 3.769570, -0.447730, 0.572720, -0.640110,
-0.314940, -0.011330, -0.057840, -1.141590, -0.443210, 1.493210, -1.339470, -0.200920, -0.702670, -0.071980,
-2.023590, 2.172840, -0.612570, 0.040980, -0.873500, -0.334250, -1.247790, 0.480210, 0.362340, 1.058160,
-0.970380, 1.382830, 0.088480, 0.314020, -1.512840, -2.066520, 0.476850, 0.413870, -0.018790, -1.905340,
3.648730, -1.918890, -0.124900, 1.312440, 2.246660, 2.913720, -0.836800, -1.072650, -1.886700, 0.078360,
0.038490, -2.678730, 1.540370, 0.581760, -0.346090, 0.818860, -1.166130, 0.594860, 0.917580, -6.236620,
-1.596890, 2.166940, 0.407930, -0.480860, -1.512080, -0.979100, 0.443950, 1.849550, -0.847740, 1.001860,
-1.880430, 0.835450, 0.790840, 0.844340, -0.910000, 0.889130, -2.978720, 0.257200, -0.314330, 1.090520,
1.949140, -0.870110, -4.487630, -1.756230, 0.947950, 0.756860, -2.243050, -2.997760, -1.366230, 0.220740,
3.131320, 0.757660, 0.190210, -0.941200, 0.861220, -0.164060, 0.036170, 0.331770, 0.406170, -0.959240,
0.574940, -0.488260, 0.671380, 0.510640, -1.517900, -2.843590, 1.254750, 1.675990, 0.920950, -0.875830,
0.762930, -1.199980, -0.571560, 5.950970, 0.927030, 0.801940, 3.636470, -0.361520, -0.092100, 2.387230,
0.442180, 0.448610, -0.536200, -0.753900, 0.265940, 0.486290, 0.733390, -0.341900, -4.551040, -0.633710,
0.828990, -1.476080, -1.195100, -2.381560, 0.633360, 0.203610, 2.617430, 2.029890, 2.038260, 1.111280,
1.399450, -0.201890, 1.870640, 1.937640, 3.299070, -0.303680, 1.499410, 2.371370, 2.050130, -0.978230,
1.116090, -7.944320, 1.181070, -2.376260, -1.107740, 2.063450, -0.899620, 1.155570, 2.540240, 0.710890,
0.386120, 0.594650, 0.248960, 0.307170, -0.585250, -0.450710, 1.075110, 4.546090, -0.252660, -1.703290,
-0.249950, -0.707530, 0.973700, 0.847240, -5.669580, 0.761430, -1.947480, -1.571560, -0.308970, 0.218710,
-0.404740, 0.934560, 3.682810, 1.025280, 0.577280, -0.371180, 1.420970, -1.395260, -2.513510, 0.366030,
4.297260, 0.396490, -0.528330, 0.668780, -1.352720, -1.736260, 1.546560, -2.419100, -0.235780, -0.639120,
-2.747450, -0.341330, -2.213260, 0.620710, 1.210860, 2.174920, 3.139740, -1.231210, -1.185470, 1.707470,
-1.232400, -3.270760, 0.823220, 4.751660, 0.370590, 0.046440, -1.598510, -0.034920, -2.082210, 1.051870,
-2.122300, 0.737770, 0.771010, -2.148380, -1.898850, 0.442430, 0.844250, 1.247600, -0.379650, 0.753890,
-1.909920, 0.306030, 1.539410, -0.396090, 2.118660, 0.974630, 0.652420, 1.589320, -0.575400, 0.262360,
-1.504810, 0.241180, 1.413080, 0.571180, 0.671680, -0.853030, 0.409010, -0.454400, -0.874070, 0.668500,
0.578000, 0.489460, -0.528100, -3.421400, -0.114460, 0.749700, 4.126630, -0.802130, -0.860700, -0.171160,
3.018530, 0.215210, -0.119080, 0.986450, 0.852520, 0.153120, -0.638730, 0.407490, 0.593580, 0.756900,
-0.245530, -0.121520, 0.161590, 1.468550, -0.856460, 0.186470, -0.124300, -0.365030,
-0.686080, -0.363260, 0.348980, 0.218930, -0.089840, 0.560660, -0.448410, 0.550010, -1.002030, -0.006840,
0.951770, -0.240540, -0.025040, -0.003500, -0.353820, 0.236560, -0.793930, -0.428730, -0.232870, 0.187240,
0.225450, -0.340890, 0.306370, 0.055670, -0.121110, 0.835500, -0.182640, 0.301770, -0.590890, -0.481240,
0.838110, -0.218980, 0.439350, 0.638740, -0.948210, 0.288150, -0.273390, -0.310100, 0.077680, 0.146010,
0.204310, -0.076430, -0.457000, 0.568420, -0.035990, -0.123660, -0.098210, -0.340670, -0.651940, -0.282030,
-0.319390, 1.035030, 0.226630, -0.055100, 0.190710, 0.263250, -0.737970, -0.240960, -0.071020, 0.523440,
0.069880, 0.048150, 0.446300, -0.780620, 0.906050, -0.087030, -0.505850, -0.224020, 0.446840, -0.704130,
0.456140, -1.388750, 0.383590, 0.733920, 0.277070, -0.822620, 0.231550, -0.370360, -0.841550, -0.299390,
0.272070, -0.573150, 0.201140, 0.632580, -0.018860, -0.278660, -0.059040, 1.261360, -0.939830, -1.759140,
0.099480, -0.949640, 0.455750, 0.664630, 0.194220, 0.301130, 1.139060, 1.327960, -0.887910, -0.800740,
0.332860, 0.851910, 1.186680, 0.101640, 0.681680, 0.217760, 0.744840, -0.677960, -0.145920, 0.341240,
0.414010, -0.777420, 1.124460, 0.634490, -0.237970, -0.413040, -0.042840, 0.388810, -0.442120, 0.016260,
1.331660, -0.762770, 0.344090, 1.011340, 0.047660, 1.571170, -0.117340, -0.119340, 0.062380, -0.318330,
0.424100, 0.271240, -0.338170, 0.069440, -0.044310, 0.622090, -1.594160, -0.092460, -1.398160, -0.077150,
0.186620, 0.795030, -1.536110, -0.062840, -0.044490, 0.038430, -0.510760, -2.110020, 0.031760, -0.155140,
-0.290670, -1.000800, 0.518980, 1.293110, 1.017050, -0.818710, 0.846650, 0.894190, -1.042970, -0.317560,
-0.445800, 0.552780, 0.700170, -0.545980, -0.053050, 0.197900, -0.690210, 0.632320, -0.293440, -1.115240,
-0.704320, -1.210480, 0.001150, -0.676190, 0.621150, -0.426320, -0.085480, 0.417390, -0.526830, 0.873610,
0.569730, -0.686790, 0.546560, 0.449970, 1.160330, 0.632790, 1.084900, -0.023910, 1.012660, 0.273930,
-0.608040, -0.048490, 0.314540, 0.621040, -0.153920, -0.573920, 0.059890, 1.188580, 0.380910, -0.204400,
0.771520, 0.746980, 0.404240, -0.619120, 1.335780, 0.353480, -0.598900, 0.112480, 0.200720, -0.021030,
0.922240, -0.100930, -0.598230, -0.268210, 0.125860, 0.986720, 0.309520, -0.316290, -0.283040, 0.155500,
-0.312350, 0.306200, 0.271960, -0.195450, -1.082580, 2.017180, -0.066130, 0.285530, -0.288400, -0.589380,
-0.629050, -0.307880, -0.604360, 1.625600, -1.185010, -0.202000, 0.925760, 0.348070, -2.129560, -0.798070,
-0.034980, -0.269710, 0.293740, 0.175170, 0.627320, 0.523450, 0.648570, -0.865660, 2.508800, 1.203840,
-0.330780, -0.186610, -0.222720, 1.695320, 0.033990, 0.176370, 0.493350, 0.235660, 0.310800, 0.095840,
-0.111850, -0.069580, -0.560590, -0.551080, -1.035010, -1.646040, -0.144390, 0.171410, -0.874290, -0.011370,
-0.946700, -1.593940, 0.007530, -4.952270, 0.090420, -1.253030, 1.729760, -1.777070, -1.236390, -1.834700,
0.231910, 0.175740, -0.941700, -1.069440, 0.236340, -0.750450, -1.208300, -0.391240, -1.255340, -0.894360,
-1.270060, -2.118890, 0.166410, 0.462320, -1.747350, -0.589600, -0.891240, -1.255500,
0.177950, -0.798090, 0.715720, -1.053580, -0.788320, 1.974300, 0.203110, -0.505890, 0.966070, -0.869250,
-0.812420, -0.152590, -0.239440, -1.988120, 0.930330, 0.643280, 0.217730, -1.223360, -0.865850, -1.155530,
0.303810, -0.998680, -1.756600, -0.809640, -0.385000, -0.355900, -0.995250, -0.331490, -1.379750, -1.500490,
-0.430980, -0.131830, 0.120500, 0.020150, 0.943890, -1.185820, 0.491410, 0.649960, -1.196110, -0.143140,
1.759110, -0.149070, -0.902490, -0.014460, -0.084750, 0.392400, 1.041170, -1.458870, 0.357930, -1.263880,
2.830510, 2.154520, -0.982970, 0.418820, 1.819500, -1.262670, -0.200080, 0.186080, 2.080950, 0.018240,
0.657080, -1.108480, -0.041000, 1.052060, -0.549250, -0.030770, -1.480310, 0.800320, -1.018470, -0.299890,
-0.234360, 0.192950, -0.135200, 0.493510, 0.265050, -0.095030, -0.401330, -0.925670, 0.100610, 0.506780,
1.228900, 1.315940, 0.127870, 0.770930, -1.069970, 0.697710, -0.263020, -0.080010, 0.273260, -0.734140,
-0.807080, -1.185720, -1.152460, -1.111990, -1.737430, 1.173230, -0.937040, -1.035370, 1.216910, 1.505590,
0.137840, 0.868180, 0.012400, 0.941180, 0.984070, 2.185020, -0.134090, -1.600420, -1.481770, 0.051130,
-0.958000, 0.380030, -2.324000, -0.634850, -0.402360, -5.234190, -1.728380, -0.104770, 5.770370, 0.671680,
-0.561080, 0.094230, 0.652140, -4.031010, 0.580070, 2.937170, -0.009340, -0.288830, -0.628790, 1.766660,
0.082310, 2.702540, -0.651870, -0.153530, -2.201070, 0.550080, -2.675760, 0.683480, -2.419510, -4.281180,
-0.617520, 3.656850, -0.134320, -0.288820, -0.199940, -2.598430, -2.409850, 2.947210, 2.420080, -1.707120,
0.816690, -4.433030, -0.409920, -0.110160, 2.463160, -0.327170, 0.171670, -1.015290, -0.055080, -1.445270,
0.966150, -1.088600, -6.922590, 0.450580, 2.485160, 1.696030, 0.307050, 1.518320, 1.169900, -1.799820,
0.143370, 1.702590, 2.245660, 2.195330, -5.181850, 0.442440, -1.043330, 1.115040, -1.190720, 1.235460,
0.206570, -0.989960, 0.199220, 0.265500, 0.197810, -6.707860, 1.755870, 1.595830, 1.770550, -0.830130,
-1.627190, -0.483850, -0.988880, -2.288840, -0.799770, 0.685540, -1.118480, -1.139160, 0.102850, 0.092550,
1.971170, 1.129420, 1.632600, -0.212590, 0.916040, 1.402690, -0.487140, 1.987790, -2.051230, 1.700990,
4.188230, 0.323200, 0.234650, 0.333730, -1.471290, -0.626950, -0.367620, -2.741410, -1.115650, 1.010940,
-2.604690, 0.385790, 1.424470, 0.291680, -0.698940, 1.564450, 1.021210, -1.162050, 2.401850, 1.172430,
-0.599320, -5.514620, 0.682220, 1.499960, 0.204080, 0.267990, 0.398740, -0.905010, 0.428450, 1.140630,
-4.009650, 0.195340, 1.555750, 3.143410, -0.224110, -0.586540, 0.723180, 1.585440, -0.051370, -0.161060,
-0.538880, 0.325130, 1.777770, -0.341970, -2.819030, 2.002450, -0.496440, 2.061450, -0.224130, -1.195830,
0.004050, -0.383850, 0.951550, -2.003500, -2.375760, 0.015080, -0.309450, -1.113940, 0.949780, 1.379930,
-0.847300, -0.941790, -1.439290, -0.074870, 0.870570, -0.784840, 4.923620, 0.550640, 0.893450, -0.227010,
0.547740, -0.753910, 0.671850, 0.100090, -0.311510, -0.061980, 0.540290, 0.819970, 0.166740, 0.256520,
-0.355940, -0.659760, 0.691560, -1.589990, 0.462730, -0.778040, 0.729240, -1.631520,
-0.079990, 1.157750, 0.335760, 0.211850, -0.878720, 0.450040, -0.188200, 1.099700, 0.544990, -0.806490,
1.352380, -1.298400, 1.004110, 0.642570, -0.968240, 0.585410, 0.266460, -0.928440, 0.287030, -1.532030,
-0.983230, -0.962120, 0.169120, -0.595090, -0.006260, -0.485660, 1.722120, 0.897150, -2.566890, -0.264800,
-0.262660, 0.018140, -2.237780, 2.666930, -1.087640, -2.284670, -0.593500, 0.974070, -0.382870, 0.150340,
0.107130, 0.012250, -0.431180, 0.641010, -0.276100, 0.197040, -0.364470, -0.585620, -1.192010, -1.910510,
1.174920, 1.608990, -1.101290, -0.836550, -2.820820, 2.176580, 0.654210, 0.516700, 0.937330, 2.121430,
0.563700, -0.053490, 1.814460, 0.205100, -0.475380, -0.470140, 0.342100, -0.582250, -1.263560, -0.319840,
-0.226050, -0.645320, -1.507800, -0.109300, 1.512300, 0.166350, 0.875220, 0.516240, -1.344700, 0.277940,
0.099540, -1.995850, 1.768290, -1.023140, 1.776810, -1.111590, 0.573630, 0.248820, -0.376260, -0.213110,
1.184760, 0.355010, -0.272810, 0.397360, -0.686080, -2.632200, 0.144410, -0.934690, 0.399160, -1.983190,
-0.411800, -1.636410, 0.163910, 0.451910, -0.884810, 5.174820, 0.391550, 1.378190, 0.595910, 1.075330,
-0.797260, -0.824730, 0.258640, 1.221010, -1.475630, 1.665960, 5.455930, -0.561570, -2.114960, -0.519130,
-0.554330, -1.379290, 0.451230, -0.540810, -3.740170, -0.494550, -2.356050, -1.265920, 1.596510, -0.990330,
-1.439130, -2.263470, -0.423100, -3.201830, -2.283460, -1.125930, 1.784910, -0.848730, -0.953570, 4.485550,
-2.538640, -2.346120, -0.295880, 0.667260, 0.908930, 1.126200, -0.354780, -1.462800, 1.311840, 2.495230,
1.571210, 0.069390, -0.777720, -0.106240, 1.388040, 1.859300, -0.506300, -0.834270, -0.559940, 0.354810,
-1.012610, -0.506840, 1.182590, 1.961570, -1.814130, -1.514490, 2.916150, -0.453230, -0.613070, -0.480540,
1.428110, 1.673440, -1.252290, -0.189260, -1.717540, 0.069650, 0.334920, -0.450580, -1.150360, -1.177000,
-0.236000, -0.869960, -1.098230, 0.988170, 0.152960, -2.310820, -0.980650, -0.570610, 0.631320, 0.462570,
-0.318850, -0.405910, 0.309180, 0.201430, 1.041270, 0.159920, -0.477510, 0.953040, -0.742030, 0.069880,
0.422970, -1.819490, -0.117790, -0.372760, -0.734510, -0.629690, 1.610310, -0.730550, 1.814450, 0.792610,
-0.901280, -0.070880, 0.396370, -0.438900, 1.013410, -2.600290, 0.615450, 1.031270, -0.748280, -0.335860,
-1.224790, 0.220510, 1.114420, -0.399790, -2.224310, 0.024660, -1.515620, 0.522840, -1.894930, 1.693670,
-0.471920, 0.587300, -0.316250, -0.707970, -1.066950, -0.752270, 2.041050, -1.088690, 0.198600, 0.873160,
3.186470, -0.859900, -0.264350, 0.834140, -0.467390, 0.192430, -0.183260, -2.078980, -1.695750, 0.586820,
0.244150, -1.154860, -1.261050, 1.350420, 0.733130, 0.591420, 0.418360, -0.996200, 6.833480, 1.421180,
-0.598540, 1.156820, -1.494120, 0.026910, 11.389470, -2.053840, -0.201100, -0.823050, 0.254290, 0.056220,
-0.208350, -0.103430, 0.112320, 2.067250, -0.585140, -0.043770, -5.239250, 0.196670, -0.404730, -0.440490,
-14.226840, -0.757950, 1.087330, 0.264250, 0.395020, -0.110730, 0.893820, 0.310960, 0.124480, -0.121100,
-0.547740, -0.588080, -2.679720, -1.340070, 0.511950, 0.313600, 0.675620, 0.390930,
2.021330, -1.556600, -1.276710, 2.041850, 0.551900, -0.815300, 0.692990, -2.381800, 0.880920, 0.774730,
-0.364180, -0.177440, -2.618960, -4.134190, -1.194150, 0.310210, -0.466940, 0.768970, 1.014710, 0.849690,
-0.566390, -1.281480, 0.530760, -0.085640, -0.121160, 0.018290, 1.409540, 1.976700, 0.405150, -0.104460,
-2.400450, 0.765140, -0.118060, 0.303090, -0.236380, -0.641000, -3.032200, -2.243900, -1.735820, 1.037880,
-0.891230, 1.462390, 1.018740, -1.018120, 0.323830, 0.073550, 0.739600, 1.134000, 1.251470, 1.957570,
1.540200, 1.563080, -0.457510, -1.753800, 0.318960, 0.643410, -1.767660, -1.172990, -0.094040, -2.790530,
-1.377090, -0.446280, -1.815020, 1.479290, 2.658660, -0.340660, 1.537150, -0.273090, 2.347910, 2.012470,
-2.085070, 1.118250, 3.274290, 0.148900, 2.237200, -0.410540, 0.035390, 4.938350, 0.842120, -5.736960,
-0.982460, 0.217860, -0.739490, 0.530760, -1.096120, 1.315640, 1.572180, 1.628780, 1.805550, 1.101870,
0.128710, 1.918580, 0.632300, 0.081540, 0.241650, 3.402500, -0.069350, 0.071990, -0.551870, -2.231360,
2.843730, 0.644270, -2.012460, -1.778530, -1.387510, -1.780270, -0.146470, -1.013650, -1.291690, -0.423990,
1.072090, 0.937620, 0.917480, -0.244840, -0.639760, 0.329600, -1.745730, -0.281660, 4.825570, 0.170510,
-1.242380, -1.111250, -0.923130, 1.049340, 1.699830, -2.510070, 0.307600, -1.489060, 0.409150, -0.449550,
-0.389060, 0.350370, -1.230020, 1.743480, -1.559420, 0.481530, 0.859170, 1.922670, 0.482520, -0.244930,
-1.103940, -0.543140, 0.713950, -1.277630, -0.434440, -1.608930, 2.072310, -0.193780, -0.822960, 0.238900,
-0.213920, 0.187130, 0.668910, 0.250610, 0.616220, 2.708900, 0.506980, 0.950900, 0.287260, 1.144360,
-1.586140, 1.062140, 0.502250, -0.097680, -1.392450, 1.587310, -0.405410, -0.355320, -0.699050, 0.400670,
0.704730, -0.050510, 0.080060, 0.247680, 0.695440, -1.047710, 1.004320, 0.076960, 1.908440, -1.668210,
-0.749270, 1.396880, 0.586010, -0.798920, -0.081000, 1.643290, -0.349230, -1.539110, 0.515020, -0.164200,
1.035080, -0.258770, 0.200740, 0.291950, 1.402390, -0.365010, -0.292240, -1.071880, -0.894050, -0.976500,
0.689310, -0.854430, -1.673200, -3.629560, 0.958200, -1.703110, 1.043700, 3.939290, 1.673930, 0.839980,
0.204050, -0.825070, -0.744070, 0.053000, 0.004680, -0.429010, 1.078870, -0.261810, 1.027750, -1.062040,
-1.019200, 0.613380, -0.754740, 0.759710, 1.061530, -0.413300, 1.168290, -0.861200, -0.543670, 0.924250,
0.505110, -0.711240, 0.494880, -1.136000, 0.263660, -0.802000, 0.181290, -1.631820, -0.989790, 2.289970,
-1.552530, -1.216760, -0.109410, 0.079500, -0.177340, -1.250830, 0.721870, -1.951070, 0.730050, 0.493990,
-0.173980, -1.757700, 1.125220, 0.690630, 1.265000, -0.979990, 1.233780, 1.115840, 1.283650, -0.984000,
-0.010950, -0.140850, -0.210210, 1.216750, 0.368830, 0.464120, -0.506980, 1.453390, 0.257580, 0.443250,
-0.824620, -1.246890, -0.772060, -0.947210, -0.733440, 0.433830, 2.907060, -0.781870, -0.594210, -0.928600,
1.488000, -0.890360, -0.222650, -0.148850, 0.073150, -0.709040, -0.360860, -0.399870, -0.854520, -0.367580,
-1.120020, 0.497420, -0.013870, 0.389130, -1.078550, 0.009720, -0.532770, -0.464160,
0.588780, -0.371550, 0.355780, 0.161900, -0.518630, -0.395530, -0.584800, -0.654980, -0.948710, -0.044670,
-1.547740, -0.180250, -0.525590, -1.137270, -0.259250, 2.123710, -0.775240, -1.269910, 0.879990, 0.180010,
-0.011100, -0.319440, -0.089500, -0.941860, -1.065600, -0.259220, -0.999140, 0.189110, 0.771090, -0.556920,
-0.131980, 0.144810, -0.061820, -0.178540, 0.253810, 1.447610, -1.516660, 0.373770, 1.025700, -0.404820,
-0.886800, -0.372070, 0.637000, -1.617270, -0.914470, 1.042330, -0.307360, -0.828930, 0.423200, 0.412900,
0.044650, 1.273250, -0.287110, 1.729800, -1.742030, -0.329820, 0.858290, 0.726950, 1.962160, -0.454390,
-1.707690, 0.834670, -0.898460, -1.059980, 0.362810, -0.063030, -1.311260, 0.642960, 0.083960, 0.943280,
-0.318450, 1.592800, -6.104840, -0.635840, -0.374810, 1.863660, -0.580840, -0.040840, -0.002780, -4.390050,
-0.836050, 1.619690, -2.117220, -0.564740, -0.189950, -0.293800, -0.367030, 1.883360, -0.329650, -0.321720,
-0.326650, 0.286020, 0.713090, -0.124710, 0.264510, 2.974700, 0.631750, 0.770740, -1.183300, 0.328580,
1.617110, 1.230520, -2.938920, -0.401760, 0.627310, -1.357750, -1.110760, 1.985560, -0.274330, -2.351330,
-0.505100, 1.279110, -0.861580, -0.574260, -0.304850, 0.499260, -4.070080, 2.839230, 2.520050, -1.314530,
0.729200, -1.307420, 0.085870, 1.018830, 2.539230, -1.162620, 1.271350, 3.093000, -0.387580, 0.121950,
-1.427810, 0.277500, 0.583670, 2.424840, -0.268220, -0.289690, -0.510870, 0.466310, -3.310790, -3.835410,
1.994900, 2.399000, -0.856890, -0.420640, 0.366500, -1.775110, -0.283430, 0.619320, -0.081500, 2.299810,
1.697780, -0.898260, -0.259380, 0.183980, 0.379330, -1.027800, 0.641900, 2.776560, 0.268920, -1.142410,
-0.805120, 1.648170, -4.124870, 0.756510, 1.969660, -0.013350, 2.238400, -0.824790, -0.091280, -0.214160,
4.582170, -0.837060, -1.523760, 1.765510, -0.565990, 1.748480, 1.309240, -0.671370, 1.010970, 3.065150,
2.901150, -0.357300, -2.286620, 1.243040, -0.341320, -6.814030, -0.184780, -0.367790, -0.222180, -1.996120,
0.617520, -2.779000, -2.522790, -0.403860, 0.774640, 3.143630, -0.513660, -1.059940, -0.708250, 0.776400,
1.654120, -1.351560, 2.311730, 0.376700, -2.927220, 0.635570, -0.273440, 0.217830, -3.496360, 1.337000,
1.655070, 1.118710, -1.551410, -2.029390, 1.102920, -1.480700, 1.289410, -3.078970, 0.898440, 2.047500,
-0.496550, -0.381670, 0.878900, 1.347830, 0.813030, 1.495960, -1.638860, 0.642170, 1.117280, -0.539830,
-0.161250, 0.103040, -0.159210, 3.339290, -0.211520, -0.227390, -0.004360, -1.477720, -1.135300, -1.310460,
-3.232980, -0.084830, -0.388260, 0.103880, -0.833130, 1.493640, 1.935290, 0.696780, 4.976330, 1.823750,
-1.249210, 0.925370, -1.156090, -3.477090, -0.119250, 0.126470, 0.018210, -0.193360, -0.870920, -2.672490,
0.472530, 0.558980, -0.989390, -1.266980, -0.870890, 1.566570, -0.527140, 1.479960, -0.654810, 0.682440,
-0.363610, 0.717070, 0.671310, -2.421280, 0.605950, -0.745160, 3.223830, -0.173190, -0.276110, -0.695720,
7.007110, -0.308170, -0.489520, 0.714480, -0.165100, 1.522990, -0.210430, -0.783970, 0.290300, -0.201130,
0.624250, 0.801250, 0.895120, -0.715350, 0.237650, 0.840310, -0.490730, -0.849560,
-0.518370, -0.087060, -0.818230, -0.432400, -0.155460, 1.159330, -0.154240, 0.315590, 1.443780, 2.008590,
0.577320, 2.066900, 0.439770, 1.495300, 1.325600, -0.715360, 2.316250, -0.755210, -0.302310, -0.428110,
-1.369260, -0.989720, 0.117800, -0.218510, -0.444600, -0.307240, -0.503680, 0.276750, 1.994430, 1.846380,
1.043120, -0.561720, -0.321900, -1.786230, 0.495350, -3.166010, -0.092000, -0.975870, 1.183720, 1.061880,
-1.517470, 0.152800, 0.081650, -1.179640, -1.347320, -0.245810, 1.971670, 1.012360, 0.763320, -0.357910,
0.486850, 1.251260, -0.165060, 0.751930, -0.170480, 0.362260, 1.320620, -1.228310, -0.652980, -0.272860,
1.775620, -0.711030, -1.248820, 1.312040, -0.453890, -0.336890, 1.089650, -3.088590, 0.657560, 2.781010,
2.131540, 1.793400, 2.801100, 0.981070, 3.399500, -0.883070, -0.291740, 0.938580, 0.441660, 0.218950,
0.593390, -1.519430, -2.323210, 0.545700, 1.177370, 0.557840, 0.544580, -0.111240, -0.526040, -0.411980,
-2.696500, -2.643650, 2.975220, 2.280870, -3.453340, 1.269950, -0.038710, 0.572970, 1.206090, 1.305660,
1.748380, -4.176320, -2.451580, 1.372690, 0.927770, 0.084230, -1.485050, -2.881170, -0.639870, -0.351360,
1.109460, -1.096340, -0.196870, -0.063110, 0.021110, 0.685910, 1.061730, -3.668680, 0.667680, -1.423360,
-0.178440, -2.074720, 1.491280, 0.936220, -1.256240, -5.171070, -1.255540, -0.632380, 1.604800, -0.317740,
-2.093960, -2.263700, -2.075380, 1.738380, -0.138040, 0.814300, 0.359160, 0.086060, 1.196140, 0.262460,
1.712020, -0.141410, 1.009200, 0.774090, -1.138720, 0.630080, 1.405830, 2.580930, -3.493730, 0.055340,
0.523300, 1.308520, 0.556190, -0.115000, -0.462350, -0.471320, -0.532440, -0.919780, 2.911210, -0.107640,
-1.537820, 1.380560, -0.539630, 1.214140, 2.310180, 0.916850, -0.243860, -0.192910, -0.151740, 1.677170,
2.112250, 0.857220, -2.266730, 0.613160, 1.510360, 1.016550, -0.217100, 1.457220, 1.553590, 0.715590,
0.390480, 1.513550, -0.956940, 2.020700, 0.106290, 0.795700, -0.119120, 1.257020, -0.342900, 0.549180,
1.028100, 0.003530, 0.886100, -0.705410, -0.623100, -0.027730, -0.762090, 0.428270, -0.731570, -0.900880,
-0.036270, -1.726820, 1.726180, 0.533810, -0.785870, -0.875580, 1.476760, 0.802030, 0.648540, 1.802420,
1.424680, 0.584310, -0.246670, 0.300090, -0.440080, -1.057960, -0.667620, -0.728400, -1.661520, -0.293760,
-5.047800, -0.554700, -1.210090, 0.073100, -2.393590, 1.979530, 1.669810, -0.433320, -1.628020, -0.275010,
2.893720, 1.487550, 1.664390, 4.160560, 3.371740, 1.308930, -0.999320, -1.318210, -0.505870, 1.573380,
-4.135200, -1.872680, -1.527680, -0.607740, 2.548620, -1.208070, 2.919650, 0.727290, -0.753650, -0.220740,
-0.416300, 0.308630, 1.405000, 0.597640, 0.524450, 1.352980, -0.547810, -0.457420, 0.777700, 2.413750,
0.155500, -0.008990, -1.128960, 0.651340, -0.211950, -1.332110, -1.934140, -1.797680, -0.158050, 1.956820,
0.021420, -1.139640, 0.046550, 0.302460, -1.547860, -0.008380, 0.278350, -0.120690, -0.993290, 1.367750,
-0.786050, -0.968330, 0.169990, 0.603270, -0.343330, -0.092250, -1.595730, -0.101800, 0.120810, -1.150910,
-1.294820, -1.767130, 1.015820, -0.946200, 0.427020, 0.250050, -0.438290, 0.012080,
0.926760, -0.214870, 0.880350, 0.401880, -0.682850, 0.438930, 1.444630, -2.656340, 0.929150, 1.780280,
-1.724080, -3.163800, -0.167650, -1.141400, 0.180380, 0.384730, -0.787130, -0.718330, 1.228240, 2.481680,
-1.688580, -1.180660, 0.650080, 0.934960, -0.090650, 0.471450, 2.943770, -0.404410, 0.497250, -1.374110,
-2.655200, 0.414900, 0.452400, -3.176390, -0.929660, 0.742940, 0.230520, 0.875710, -0.956850, -2.491730,
0.509420, 0.381280, 0.480810, -1.425570, -0.820790, 1.990140, 3.996370, 0.911670, -0.666200, 2.040060,
0.321260, 1.852600, 1.270290, 0.990290, -0.012810, 0.404260, -3.269980, -0.234000, -1.262130, -0.210620,
-0.239230, -0.630410, -0.153830, 1.696680, 1.679800, 0.889870, -0.721310, 0.465940, -0.129380, 1.868340,
0.805530, -0.448130, 1.024160, 0.201180, 2.346820, -0.168280, -1.354970, 1.346130, -0.341000, -4.554170,
0.803930, -2.945660, 1.950360, 1.120190, -1.537890, -3.041050, -0.082200, 3.234900, -1.730280, 0.815840,
3.945760, -0.821060, 1.478520, 2.938070, 0.985320, -0.832140, 0.087140, 1.543450, -1.137060, -1.306610,
1.734060, -2.806500, -6.265690, -1.324330, -2.179290, 4.695280, 0.287530, -1.427860, -1.673800, 0.345350,
-1.210680, -0.745940, 0.881360, 1.411890, -0.703650, 0.955120, 4.209000, 0.936840, 0.837070, -0.250280,
1.668990, -1.543280, -0.466740, 1.339500, -0.807800, -0.758150, -0.874740, -0.567210, 1.687430, 1.004890,
-0.520830, -1.640780, 0.520790, -1.609230, -1.314750, 0.711520, -0.075760, -1.633350, 0.869710, -0.642640,
0.455260, 1.353340, 0.495290, 0.530250, 0.344560, -0.834290, -3.241520, 1.321820, 0.223630, 2.575450,
0.736290, 0.103430, -0.170790, -0.417310, 1.609300, 0.772350, 0.736440, 1.067230, -0.192190, 1.261330,
-0.697650, -1.928390, -1.472730, 0.118140, 0.449310, -0.647380, -0.117150, -1.768770, 1.399130, 0.965890,
0.933430, 0.322620, 0.608050, -1.212720, -4.085790, -0.995090, 1.845570, -0.489260, -0.162040, -0.818250,
-0.915010, 0.245320, 0.417140, -1.688340, -1.116900, 0.531000, 1.506260, 1.022680, 2.164910, 0.463160,
0.131320, -1.366410, 1.503240, 0.448420, 0.494190, -1.544200, -1.545420, -4.021730, -0.526750, 1.004440,
0.414310, 0.620580, 4.114640, -0.975870, 0.264110, -0.959090, 1.175160, -1.058260, -0.351270, -0.051390,
1.945210, -0.919950, 0.116030, 0.810920, -1.868810, -0.047290, 0.738900, 1.541330, -0.150240, 0.795840,
-1.630810, 0.993890, -0.988210, -2.454510, -1.128950, 0.161810, 0.534590, -4.444370, -0.162400, 0.591270,
-1.761450, -1.647230, 0.405660, 0.275800, -4.206180, -0.658900, 0.226160, -0.480790, -0.738510, 2.763880,
0.545020, 0.457680, -0.292940, -0.275530, -1.469210, 0.047870, 0.659870, -0.100740, -1.409040, 0.869350,
-0.394150, 0.214160, 1.429840, 0.859620, 3.333430, 1.738140, 0.455970, 0.376620, 2.984310, 3.872430,
0.413720, -0.845930, -0.713390, 0.960280, -0.103740, -0.272010, 0.624050, 0.461170, -0.510080, -1.773310,
0.274630, -0.632400, -0.199260, 0.749990, 0.692190, -0.032390, -0.921980, -0.331620, 0.494770, -0.251030,
-4.715240, -0.542290, 0.273060, -0.136190, 0.221640, 0.739810, 0.051970, -0.750330, -1.149010, -0.059520,
-0.195000, -1.146030, -1.085000, 0.342680, 0.453440, -0.194350, -0.770510, -0.548820,
0.667930, -0.172240, -0.711280, 1.287550, 1.194860, -0.969720, 0.067720, 0.325760, 0.383880, 0.259890,
-0.271940, -0.278820, -0.936160, 0.028210, -0.071890, -0.079740, -0.986460, -0.568960, 0.006220, 1.268580,
0.487220, -0.605010, 0.444770, 0.516630, -1.841580, 0.493230, 1.765130, 0.591190, 0.510280, 1.577870,
0.418190, -1.528970, -0.805450, 2.784410, 1.366590, -0.608530, -0.483710, -0.981230, -0.741410, 0.488970,
-1.246820, 0.209880, -1.657500, -0.252470, -3.112510, -1.114980, -0.141210, -0.716340, 1.227740, 0.408670,
-0.552520, -0.577510, 2.941030, 0.598450, 0.074260, -1.116470, -0.418070, -0.341810, 0.122740, -1.152890,
0.299780, -0.004020, -0.345360, 0.194180, 2.275070, 0.873200, -0.983630, 0.089150, -0.347550, 0.553900,
-0.718640, 1.708590, -1.082660, 0.122780, 0.469860, 0.328940, 1.152270, 0.475190, 1.689600, 1.477850,
-0.418360, 0.561700, -0.290770, -1.611370, -0.460240, -1.207940, -1.685130, 0.337430, 0.729330, -0.592420,
1.256930, -1.132940, 0.467360, 0.518890, -0.583760, -0.109860, -2.325000, -0.946240, -1.087960, -2.095160,
2.017800, 0.246060, -3.296520, 0.212060, -0.746270, -0.453390, 1.477740, 0.082670, -0.167400, -1.249200,
0.763790, -2.204750, 0.555900, 1.240220, -0.746020, -0.626790, -0.774400, -1.244670, 0.630270, -0.278980,
1.367570, -0.962470, 0.639690, -0.230430, 0.029940, -1.548190, -2.649700, 2.496870, -0.618180, -0.599630,
-0.095750, -0.217360, 0.080850, 1.336090, 0.648090, -0.618560, -0.168990, -0.762850, 0.546390, 1.963510,
0.064250, 1.049530, 0.435280, -1.094820, 1.001910, -1.968570, 0.036580, 0.001870, -1.011460, -0.568340,
-0.827140, -0.846320, 2.053790, 0.064990, 0.950310, 0.680980, -0.091120, -0.313890, 1.490370, 0.126480,
0.125270, 0.470490, -3.107400, -0.304070, 3.186480, -0.804180, 0.231610, -2.360940, -0.849560, 0.504720,
1.441780, -0.499640, -0.260880, 1.123000, -5.997140, -0.388220, -0.385530, 0.374070, -0.307260, 2.994810,
0.391630, -0.490160, -0.204660, 1.061600, -1.236590, -1.141010, 1.391100, 5.098050, -1.048680, -0.649030,
1.105440, -1.233950, 0.146010, 0.554720, 0.418440, 1.583770, 1.122760, -0.825440, -1.606830, -0.381640,
0.055570, 0.741910, 1.918210, 0.459480, 0.234990, 0.606100, -0.579550, -2.310680, -9.847130, -0.582250,
3.781060, 0.082220, -0.367850, 1.310660, -0.995010, -1.410100, 0.313350, -3.117360, 1.415850, 1.373540,
-0.543450, -2.596030, -0.486740, 1.135310, 0.517780, 0.986300, 1.729190, -1.489990, -1.589310, 0.903340,
-0.170030, -6.652590, 0.201190, -0.310540, -1.246350, -0.744310, 0.747690, -4.162160, -2.735440, -0.614280,
-4.120140, -0.410340, -0.856080, -3.795330, -0.282500, 1.040830, 0.163050, -0.055610, 2.028360, 0.395780,
-0.048840, 0.598970, -0.200290, 0.708490, 0.103450, -0.916560, 0.460400, 0.628110, -0.161320, 1.493570,
1.259760, 0.712970, 0.722090, -2.076750, 0.514020, 0.770280, 2.811850, 2.164220, -0.990630, 3.513470,
0.897900, -1.855620, -0.735560, -0.227100, -0.853350, -1.121140, 7.312760, -0.198530, 0.105890, -0.732360,
3.183580, -0.261790, -0.368280, 0.656760, -0.653160, -0.783610, 0.968650, 0.373670, -1.051210, 0.375300,
-1.432630, -0.923370, -2.173400, 0.194930, -0.405540, -0.179490, -0.064320, -0.331960,
0.864320, 0.423460, 0.981830, 0.905660, -1.144020, -0.559740, -1.034540, 1.417040, 0.259070, -0.540570,
-1.160020, 0.127480, -0.090880, -0.042980, -0.188300, -0.842650, -0.327510, 1.194440, 0.098000, 0.577230,
1.539120, 0.380700, -0.184550, 0.367740, -0.110580, -0.773500, 0.416870, 0.486930, 1.428210, -0.900590,
-2.195540, 0.270770, 0.534010, 0.402070, -0.161600, -0.912640, -1.354710, 1.530820, -1.436700, -0.359950,
1.073750, 0.620080, -1.393450, 0.827380, -0.122040, -0.501640, 0.142440, 0.625200, -0.487500, 2.437950,
0.304750, 0.842160, 0.317360, 0.259980, 0.090410, -1.327340, -1.454700, 0.031440, 0.956910, 1.559960,
-1.445230, 1.196420, 0.087820, 0.825150, 0.000520, -0.372280, 0.410470, 0.115430, -0.221850, 0.389520,
-0.223380, -0.131040, 0.531650, 1.184210, -1.790440, -0.066700, 0.679830, -0.404450, 0.160780, -0.378070,
0.850330, 0.132280, -1.023170, 0.356630, -0.820790, -3.505610, 1.607340, -0.027810, -1.088130, 0.534820,
0.843650, -2.172280, 0.870250, 0.285290, 0.294430, 0.380230, -0.374440, 1.293950, 2.136320, -0.955040,
-0.799680, -0.308650, -0.434820, -1.014270, -0.253690, 1.187490, -0.689340, -0.161350, -0.962470, 0.155250,
0.160550, 0.273190, -0.140960, 1.950020, -1.106150, -1.116180, 0.789220, -0.492750, -1.448540, 0.439690,
1.916380, 1.356310, 0.550720, 0.739790, 0.693000, -0.097230, -0.134110, 0.277480, 0.473230, 0.301560,
-0.813630, -0.116410, -0.510150, 0.558310, 0.330340, 0.464810, 0.629580, -1.182940, 1.150330, 1.071780,
-0.810280, -3.546790, -0.521380, -0.618590, 1.222380, -0.300940, 0.769040, -4.448740, -0.117890, 0.537690,
-0.479810, 1.497000, 0.365540, -0.493780, -1.955870, -0.291890, -0.192810, 0.374550, 0.936560, -0.592820,
-0.649220, 0.700020, 4.053860, -3.042060, -3.351220, 0.289450, 0.731350, 1.524730, -0.663210, -3.116110,
-2.785440, -0.402760, 0.301110, 1.763150, 0.100220, 1.382930, 0.925780, 1.775350, 0.638340, -0.308500,
-1.630160, -0.101020, 0.123530, -1.503320, -2.283400, 7.007880, -0.424520, -3.758320, -0.938260, 1.647060,
-1.125680, -0.349050, -0.698600, 0.162600, 1.872530, 1.207320, 0.878380, 0.032650, 0.174660, -1.506630,
-0.881180, 0.296060, -2.429040, 0.631700, -0.844440, 0.239460, -0.796440, -2.133050, 3.662620, 0.342920,
-3.532110, 2.585530, 1.024120, -0.968220, -0.108400, 1.783840, -0.615180, 2.838710, 1.140810, -1.152100,
0.059840, -0.082160, 0.612140, -0.676450, -0.660740, -0.297720, -1.733100, -0.616450, 1.058950, -0.491780,
-1.175130, 0.163160, -2.665960, -2.274750, -0.322400, 0.700100, -0.483300, -0.013510, 0.658940, -1.844380,
1.230890, 1.082460, 0.208770, 1.303370, -0.385190, -0.132160, -1.380840, -0.759750, -0.859490, -0.105590,
-0.406990, -0.476400, -0.484680, 1.290510, -0.209970, 1.569540, -0.252270, 3.234540, 2.568050, -1.233280,
0.408130, -1.415480, -0.393870, 1.537710, 0.964050, -1.097760, -0.937980, 0.320060, 0.629340, -0.590710,
-0.240960, 0.062260, 1.685840, 1.783080, 0.164810, 0.323870, -5.899260, 4.101600, 0.634760, -0.438490,
-2.820490, -0.818870, 0.580330, -0.579970, -0.496890, -0.546410, 1.580120, -1.077890, 2.932960, 0.769850,
1.166040, 0.974920, -3.072460, 1.991570, 0.801610, -0.086870, 1.045940, 0.692480,
-1.104080, -0.765620, 1.100910, -0.073490, -2.196850, -1.434410, 0.794430, -0.273840, -0.632330, 1.372690,
-0.087610, -0.036650, 0.083070, 0.193810, 1.263720, -0.782790, 1.301570, 0.804680, 0.869980, -0.447270,
-1.295560, -0.120670, -1.075750, 0.227120, 2.639350, -0.843120, -0.870770, -1.318800, 0.550570, -1.055760,
0.165630, 1.952330, -0.257310, -0.618080, 3.068380, 0.276690, 1.038980, 0.654530, 0.855640, -1.320780,
-0.449430, -0.878770, -1.172430, -0.080660, -1.012220, -1.058380, -0.305340, 2.019090, -1.416280, 1.541870,
-1.745000, 0.121970, -0.393480, 1.845850, 1.611790, 0.123820, -3.136740, 0.838170, 0.611390, -0.721630,
-0.906420, -0.252970, -1.274150, 0.084990, 0.956290, 0.968570, 0.845990, -0.191390, 0.242980, 1.968770,
2.400990, -1.823240, -0.462200, -0.903550, 1.598750, -0.888340, -0.182900, 1.061250, 0.269580, 1.748050,
-0.789530, 0.863350, 2.956310, 1.042640, 0.582960, -1.094920, -0.772510, 0.427020, 1.283990, -0.247480,
-0.772690, 0.018680, 1.027860, 2.789530, 0.067660, -1.556820, -0.567860, -0.382530, -1.111920, 1.155270,
2.490740, -1.505640, -2.183370, 0.722880, 0.476600, 6.028330, 0.789340, -0.040840, -4.128950, 0.541350,
0.610680, 0.350810, 1.815870, -0.366720, 1.026040, 0.192260, 0.075250, 2.226640, 0.178900, 1.219460,
-1.969960, -0.195880, -1.603550, -1.761330, 3.831020, -4.249300, 1.185060, 0.716170, 1.736380, 1.495620,
-0.298340, -0.116130, 2.734720, -1.132140, -0.709130, -0.688080, -0.243340, 1.353230, -5.329780, -0.821800,
0.910800, 0.217780, 1.959680, 0.114850, -1.411240, -0.297040, -1.823900, 2.497160, 0.203850, -1.260390,
0.949230, -0.887440, -0.339900, -0.472360, 0.504390, 0.749720, 0.478890, -0.081570, -1.449590, -0.171290,
-0.720440, -3.033700, -0.631010, 0.276760, -0.703120, 0.448330, 1.089230, 0.591280, -0.617860, -1.880540,
0.381560, 3.313360, 1.175280, 0.909680, -0.180640, -0.765850, 0.253500, 1.286960, -1.573630, 0.565340,
-0.681230, -0.390270, 1.718420, -0.046060, 0.522780, -0.135690, 0.111170, -0.972620, -0.587890, -1.004140,
0.810710, 1.922390, -0.742530, 0.166120, -0.012300, 0.008940, 0.606190, -1.523900, 0.167660, -0.558850,
1.317690, 0.182100, 0.454880, -1.416300, 0.308320, -1.212890, -0.136870, 0.277800, 0.728550, -1.770200,
2.970190, -0.637280, 1.227570, -0.166790, 0.185320, 0.680810, -0.989720, 0.948830, 0.426070, -0.703770,
-2.257730, -0.037630, -1.597760, -1.108960, -0.384420, 0.211870, -0.542130, -0.245120, -0.139240, 0.678390,
-0.557090, 0.733860, 1.511870, 0.509290, -1.655550, -0.179710, 0.730740, -1.041370, 0.376170, 0.970150,
-1.306900, -0.154410, -0.557400, -1.555940, 0.359290, -0.446500, 2.100220, 1.169770, 0.262900, 2.011910,
0.649190, -0.933750, -0.389240, -0.248380, 0.171950, 1.122900, -2.737480, 0.686690, 0.574720, 0.443440,
-0.090520, -0.820780, -2.702470, 1.594100, -0.564110, 0.037070, 1.160700, -0.467080, 0.625500, -0.450110,
-0.858360, 0.650660, -0.413820, -0.380990, 0.237040, 0.859170, -0.468730, 0.738820, -0.378740, 0.087640,
-0.740770, -0.503350, 0.610010, 0.440030, 0.649420, 1.444050, 0.794390, 0.107430, -0.281610, 0.759220,
-0.597910, 0.583400, -1.694150, -0.450820, -0.450970, -0.433170, 1.352600, 0.353690,
0.079230, -2.392860, -0.756510, 0.492430, 1.340930, -0.187600, -0.329660, -1.754720, -1.969860, -0.088090,
-0.404950, -0.781680, -2.201540, -1.106140, -1.134790, 1.279690, 0.857450, -2.119300, -0.419130, -2.050850,
-0.541760, 0.431060, 0.286000, -0.086290, -0.765850, -0.215870, -2.041200, 0.763100, 0.034050, 0.883720,
0.659950, -0.844740, -0.321020, -0.052750, -0.046740, 0.330900, -0.627400, 0.105990, 1.783670, -0.578550,
1.029280, -0.015870, -0.155240, -0.764360, 0.433950, -0.732840, -0.498680, -1.705840, 0.424230, 0.175190,
0.885250, 0.047360, 0.827860, -0.999690, -0.830330, -0.594970, -0.750650, -0.241550, -2.164770, -0.963280,
-0.069700, 0.101730, -1.060440, 2.217720, 0.342680, -0.079860, -0.182560, -0.954430, -0.802490, 0.293760,
-0.356100, 1.761270, 0.781450, 1.833790, 1.818490, 0.429440, -1.074260, 1.232270, -0.244810, 0.147270,
0.735100, 1.424980, 2.559260, -0.983970, -0.049610, -0.732640, 1.932460, 3.559360, 0.310660, -0.629490,
-0.075420, -1.953010, 1.547120, 0.211510, 0.203850, -0.909540, 0.861300, -0.801780, -0.087790, 2.736980,
2.178190, 0.584190, 0.204670, 0.105580, -0.842940, 2.529590, 0.671820, 0.374770, -1.304180, -0.555540,
-1.031370, 0.127960, 1.373620, 0.544180, -0.946810, 0.810670, 1.287950, 1.160780, -0.353780, 1.485690,
0.658780, 2.037790, 1.005060, -0.971130, -0.201240, -0.047310, 2.088500, -0.329190, 3.113620, 1.418890,
1.920530, 1.373600, 1.043420, 0.480050, -0.738670, -0.630000, -0.344680, -0.884580, 1.104930, -1.933990,
0.435090, -3.402160, 0.975770, 1.533400, -2.237860, 2.686070, -0.627780, -0.805380, 0.330450, 0.138810,
-0.121880, -1.131370, 1.991470, 1.335750, 1.699750, 0.824150, -5.189300, -1.934670, -0.176570, 0.594040,
-0.377980, -0.717430, 1.833650, -3.024940, -1.489920, -0.389360, -3.119350, 1.114330, 1.339090, -0.704430,
-1.025150, 0.952450, 0.783750, -0.808840, 2.618930, 0.890120, 0.389230, -0.135600, -0.333180, 0.799030,
-0.745920, -0.965550, -0.421760, -0.552750, 0.378180, 7.424890, -1.050000, -5.798740, -1.308680, 0.660280,
0.809530, 2.086240, 0.324370, 0.035640, -0.328010, -0.830160, 0.279280, 1.356320, 0.898580, 1.214800,
0.310110, 0.700800, -3.600670, -3.642660, -0.134020, 0.119810, -0.477950, 0.428490, 2.391120, -0.644870,
-2.245900, -1.928970, 0.156850, 1.361510, -1.006540, 0.765390, 0.231640, -0.110680, 0.522050, -1.790510,
0.361980, -1.755670, -0.114970, -0.947640, -3.207530, -0.683970, -0.400950, -0.876020, -1.081770, -0.131690,
0.730240, 2.689770, -1.004960, -1.625300, 3.060460, -0.037290, -0.563780, 0.430900, 2.215460, 0.726420,
2.041540, 0.816100, 0.195300, 1.240720, -0.248350, -0.199700, -0.495220, -0.627740, -1.678110, 1.114580,
-0.119890, 0.163260, -0.570190, 1.472400, 1.806080, 0.241420, -0.626920, -2.127990, -0.081890, 3.654090,
-0.391010, 1.022380, 2.562930, 0.239090, 1.724780, 0.754580, 0.188700, -1.429700, 0.631220, -2.423200,
-0.137750, -0.797320, -0.687680, 2.050630, -0.466310, 0.494330, -6.871280, -0.263150, -0.843190, -0.525370,
-5.082590, 0.320340, -0.035360, -0.724660, 0.526180, 1.243810, -0.446220, 0.844930, -0.458500, -0.381320,
0.721340, -0.424610, -2.553440, -0.264830, 0.237730, 0.266100, -0.853890, 0.488870,
1.639390, 0.962990, 1.112800, 0.315020, -0.038600, 0.511690, -1.317980, -0.847010, 2.023430, 1.093270,
1.956970, 0.410260, 0.382680, 2.187590, -0.294750, 2.020640, -2.048440, 1.402270, 1.520800, -0.374060,
0.040800, 0.654330, -0.334620, -0.996910, 0.029220, 0.704220, 1.635810, 1.006240, 0.679510, -0.497060,
-0.356140, 1.083700, -0.129430, 0.085180, 0.031600, -0.151390, 0.307490, -0.523980, -0.041100, 0.016410,
-1.042470, 0.127890, -1.301990, 0.299810, -0.305220, -1.037170, -0.637140, 0.668700, 0.135890, -1.719760,
-1.375700, -0.692580, -0.149300, 2.040480, 2.338700, -1.419450, 0.956410, -1.260820, 0.147980, -0.112210,
0.820220, -0.222610, 1.331050, -0.452810, 1.032970, 1.414070, -0.744910, 2.253830, 0.488830, -1.037850,
-0.569070, -0.864040, -0.223550, -0.617580, -0.442760, 0.162930, 3.055590, -1.049000, -1.057290, 0.748180,
0.758550, -0.259160, 0.398600, -0.160810, -0.236840, -0.143800, 0.240200, 0.752550, 0.266220, 0.560430,
1.847260, 0.331080, 0.527480, -1.039400, 3.743540, 0.198040, 1.866220, -0.082580, -0.474880, -1.342290,
-0.299330, -0.857530, 1.419350, 1.094490, -0.633080, -0.986080, -0.428280, -2.008080, 0.634350, -0.018990,
0.049090, 0.226870, 0.577030, -0.384890, 0.867760, -1.143610, -2.479700, -0.665810, 0.521880, 0.622310,
-1.125810, 1.102310, -0.248300, -0.980770, 1.313130, 5.948430, 0.594980, 0.418100, 0.474680, -2.403250,
1.838240, 0.920570, -0.389660, 1.253760, 1.986520, -0.126490, -0.105700, 1.502350, -2.843140, -2.692510,
2.144250, -1.789210, -1.049680, 0.304730, 0.379080, -0.479070, -6.139430, 0.173110, 7.766190, 3.245070,
1.910930, 0.402580, -0.841740, 1.404210, 3.059260, 1.293230, -0.846410, -0.118110, 0.348710, 1.268120,
2.484620, -1.029880, -4.328800, -0.109850, 1.402170, 1.728210, -1.092100, -0.110000, -1.468820, 0.013730,
2.642490, 1.384370, 0.875970, 0.285220, -2.318490, -1.054680, -0.055600, 3.134140, 0.572100, 1.621530,
0.763830, -1.927270, 0.233430, 1.726470, -0.117710, -1.869320, 2.077730, 1.417360, 1.070930, 0.179120,
0.287060, -0.437550, 0.127800, -0.224500, 0.292500, 0.588760, 1.843420, -1.195230, 3.071810, -0.468770,
0.511600, 0.538450, 0.843580, 0.339060, 0.433620, 0.009620, 3.989810, -1.556940, -1.077090, 2.199590,
0.398930, -0.208600, 0.236550, -0.043390, -0.472270, 0.525680, -1.493080, 0.594910, -0.156950, -0.314700,
-0.434540, 1.425350, 0.839530, 0.665640, 1.032390, 0.243030, 0.298610, 0.372020, 2.957550, -0.130560,
2.268020, -0.676950, 0.847850, 0.110030, -0.734330, -0.679330, 1.193710, -0.134460, -2.290620, -0.508510,
-0.345590, 0.384590, -0.842390, 1.049200, 0.640690, 0.832110, 1.565990, -1.158490, -0.082850, -1.441940,
0.661850, 0.083580, -0.463330, 0.994720, -0.665580, 0.036310, 2.359060, 0.472710, -0.664610, -0.967070,
-0.481590, 1.255790, -0.464070, -0.339620, -1.663590, -0.811960, 0.411540, -0.189850, 0.094170, -1.723490,
-0.330390, 0.001230, -0.133350, 1.693990, 0.227430, 0.302560, 1.766340, -0.370720, -0.629110, 1.425680,
-0.398380, 0.205630, -1.320660, -1.356760, -0.885680, 0.141690, -3.132720, 0.057250, -1.256770, -0.717430,
0.024380, -0.658330, 1.869070, -2.295300, 0.210270, 0.237940, -0.129090, -0.572600,
0.949790, -1.395270, -0.671670, -0.038860, 0.702510, -1.011410, -0.151530, -1.119570, 2.771030, -0.003270,
-0.804060, 1.124640, -1.501140, 0.984400, -0.627520, -1.384950, -0.179990, -1.055440, 0.328400, 0.471130,
0.911470, 0.460000, 1.043950, 0.864970, 1.308810, -0.844440, 1.283950, 0.513950, 0.382190, -0.519040,
-0.054640, 1.695360, -0.419110, -0.883880, -0.315250, -0.600290, 0.856050, 1.709310, 0.451890, 0.822630,
-1.578640, 0.352290, 0.129540, 0.612720, -0.771220, -0.050020, 1.007970, 0.825560, 1.212220, -0.049960,
0.163060, -0.350850, -0.172300, -0.370330, 1.022590, -0.398050, 1.120060, -1.091710, -0.574620, 0.671210,
-0.195290, 1.345300, -0.393360, 2.929370, -0.002340, 1.039310, -0.073130, 0.542540, 1.340290, -0.974500,
-0.166860, 0.391330, 2.140290, -1.557830, 1.079900, 0.364800, 0.685830, -0.088650, 1.191960, -0.887540,
-1.004820, -0.720700, 0.091010, -0.900260, -0.302810, 2.192600, 1.403240, -0.922200, -0.942290, -0.546570,
-1.053580, 0.924130, -0.619080, 0.731850, 0.373280, 3.549930, -0.847440, -1.103120, -1.660270, 0.218920,
0.238440, 0.622030, 0.208510, -1.011960, -0.145070, 1.571630, -0.670180, -0.431140, -0.157910, -0.680370,
1.944550, 1.512800, 0.859130, -0.472980, 1.234500, 1.104090, 1.917320, -1.190680, 2.835400, 0.752610,
1.201020, -2.365160, 0.958210, -0.623310, 0.974840, -1.937000, -0.297500, 0.368140, -0.910110, 0.683110,
-0.678830, 0.248340, 0.721220, 1.267310, -0.485830, 0.909000, -1.087040, 0.708750, 1.871510, 0.619910,
1.538460, 3.427630, 0.765700, 1.167010, 0.013030, -1.859750, 0.964340, 2.370010, -1.261790, 0.502720,
-0.926330, -0.948570, 0.247220, -0.165880, 0.815840, 1.035660, -0.996420, -1.294490, 1.106660, -0.289920,
2.740850, 0.441070, -2.609120, 0.756830, 3.028830, 0.009840, -1.543570, -2.085100, -1.410470, -1.329950,
0.507110, -1.171340, 1.310510, -2.114510, -0.599670, -1.543910, 0.181490, 0.779240, 1.238810, -0.514760,
-0.185020, 0.198070, -0.084560, 0.631310, 0.030760, -0.025350, 0.469720, 0.045930, 1.085770, -2.234230,
1.752220, -0.862690, -0.844930, 0.859470, -0.408000, -0.530950, 0.408600, -0.645390, -1.310170, 0.721940,
0.479920, 0.240140, 0.615020, -1.201480, -1.769070, 0.343970, 0.302880, 0.791510, -0.860590, 1.412070,
3.340330, 0.464720, 0.637520, 0.106240, -0.356820, 0.311150, 0.321190, -2.480060, -0.833490, 0.127210,
-0.342260, -0.615600, 1.005390, 0.033350, 0.772940, 0.952710, -0.108920, 0.516270, 0.246330, -0.141400,
0.537150, -1.206430, 1.800570, 1.901860, 2.198500, -0.117300, 0.589750, 0.500800, 1.922960, 2.047440,
-2.800130, -0.590280, 0.341760, -0.622510, -0.338050, -0.186690, 0.787460, 0.316970, 0.723860, 0.941530,
2.218320, 0.416740, 0.308430, 1.285830, 0.227510, 0.012050, -1.681130, -0.066470, 1.667500, 0.275150,
-1.136680, 1.283490, 1.603360, -1.512160, 0.415170, -1.948860, 0.175620, -0.521330, -0.755920, 0.795120,
-0.522360, -0.045560, -0.744320, -7.034940, 0.250770, -1.054420, 2.012870, -3.581580, -0.795600, 0.109360,
4.114460, 0.542270, -4.336320, -0.262900, -0.971760, -1.082440, -1.216060, -0.342980, -1.783680, 0.155240,
-0.104500, -0.346580, 0.589740, 0.267150, -0.859610, -0.693850, -1.509860, -0.089230,
-0.284290, 1.452490, 0.387550, -0.255090, -0.556740, 0.512660, -0.135080, -1.264490, 0.260180, -1.118990,
0.047960, -0.443860, -0.654630, -1.196250, 0.445930, 0.008850, 0.686190, -0.608420, -0.509410, 0.641480,
-0.884240, -1.441430, 0.708190, 1.082360, 0.171910, 1.369720, 0.772010, 0.144540, -0.451280, -0.036510,
-0.787830, 1.099550, -0.108550, 0.274190, -0.071190, 0.371710, -0.227740, 0.676940, -0.521470, 0.741540,
-1.587510, -0.202190, -0.012730, -0.709770, -1.506260, -0.669630, 2.559430, 0.166930, -2.227720, 0.363160,
0.316990, -1.325350, 0.173170, -0.397010, 1.467210, 0.201850, 0.978650, -0.229300, 0.358770, 1.119740,
-0.250950, -0.128020, 0.660660, -0.114120, -0.545530, -0.830150, -0.103400, -1.043140, -0.264800, -1.017650,
0.678670, -0.636000, -0.657330, -1.908590, 0.766250, 0.609650, -0.852610, 0.825170, 0.026290, 0.747120,
-0.005010, -0.977200, 0.621030, 0.299220, -0.348760, -0.481040, -1.908930, 0.228500, 0.510960, -0.774410,
0.825360, -1.941290, 0.128710, 0.285220, -0.763890, -1.981630, -0.247950, -0.641620, -0.500910, -0.244070,
-0.874080, -0.172500, -0.296980, -1.337150, -0.177710, -0.252410, 0.203600, -1.211150, 0.004910, -0.478750,
2.029870, -0.412240, -0.198500, -0.097070, -0.656650, 1.094090, 3.698540, 0.254000, 3.330300, 1.363010,
-0.156210, 2.256710, -2.153440, 2.551410, 1.994540, -2.895510, -0.664390, -0.215060, 0.338860, 0.789770,
0.782920, -0.555050, 0.135110, -0.943720, -0.893690, 1.846030, -0.534500, -0.767480, 1.056260, -1.109630,
0.307320, 1.557790, 0.243080, -0.271600, 1.391880, 0.677300, 1.711560, 1.162410, -2.093230, -0.631080,
0.033060, 1.168600, 0.360700, 0.616750, -0.421690, -0.325710, 1.397810, -1.030170, 2.257370, -0.628730,
-0.383230, 0.093060, -1.918800, -3.066680, 2.590010, -0.506480, -1.387320, 0.790570, -1.105620, -0.201820,
-2.177730, -0.489470, 0.064280, 0.561700, -0.146110, 0.871440, -0.520860, 0.780960, -2.297010, 1.065510,
0.193730, -1.007370, 1.379570, 0.973720, -0.678530, 1.439960, 0.150000, 0.475190, 0.020190, -0.486650,
-0.273090, -0.312100, -1.490800, -1.446260, -1.126450, -0.763390, 0.690560, -0.381110, -0.351490, -1.358970,
-1.139600, -0.328020, 1.381300, 0.379330, -0.221680, 1.123770, 0.799820, 0.646490, 1.844830, 0.980060,
-0.071760, 0.392640, 0.936370, -0.917170, 0.520580, -0.126700, 1.888400, 0.087050, -0.212350, 0.305210,
0.954580, 2.938340, -0.321070, 0.342370, 0.885490, -0.816930, -0.129780, 0.687050, -1.895240, -1.806520,
0.274760, 1.375520, 1.232720, 2.601780, -0.933680, 1.679650, -1.934640, -0.345890, -0.236360, 0.103070,
-1.946340, -0.966810, 1.483690, -0.228690, 0.995250, -0.336890, 0.823100, -0.951060, 3.519960, 1.750920,
0.020300, -0.302500, 0.599540, 0.502180, 1.456610, 1.058260, -0.788290, 0.781170, -0.963120, -0.697480,
-0.282890, -0.666590, -0.122460, 0.332780, -0.229770, -0.310610, 1.125950, 0.797530, -0.546470, -1.627950,
-0.438430, -0.946700, -3.911500, -8.325190, -2.027740, -0.286600, 2.348840, -0.433600, -1.908330, -0.746210,
-5.134610, -1.356510, -1.548980, -0.844970, -0.826580, 0.052340, -1.399470, 0.338990, -2.176990, 0.315860,
-0.849850, -0.789130, 0.913790, -0.452500, -0.861970, -1.936320, -1.621730, -0.989360,
-0.225110, -0.242700, -0.517460, -0.740660, 0.192280, -0.682730, 3.567990, -0.765880, -0.320370, 1.652300,
0.314570, -0.404440, 0.754270, 0.304190, -0.508930, 0.785620, -0.069880, 0.900070, 0.009000, 0.696850,
0.599000, -0.247790, 0.847430, -0.152990, 0.441420, 0.061040, -0.098710, -0.472320, -0.202400, -2.209390,
-0.180920, 0.291050, 1.515610, 1.663110, -1.089600, 0.973640, 1.383670, 1.625230, 0.112030, 0.075430,
-0.444110, -1.750190, -1.690060, 0.015880, -1.743990, -0.221740, -1.970790, 0.300690, -0.324540, -0.965880,
-0.715970, -0.131550, 1.172830, -0.054810, -1.759370, -0.522470, 2.298700, -0.012300, 1.032140, 0.589640,
-1.199740, 0.800520, 0.780170, -1.581150, 0.812400, 1.445380, 0.285360, -1.819640, 0.521650, -0.427540,
-1.873110, -0.425950, -0.446260, -0.647200, -0.183190, 1.394710, -0.061710, -4.138300, -0.501930, -0.126370,
1.471420, -0.270670, -0.555600, 0.697570, -0.332760, 0.958790, 0.465500, 0.350570, 0.403380, 0.155400,
0.642430, -0.516040, -2.000860, 0.003500, 2.707550, -1.489010, 1.104960, 3.328590, 0.480090, 0.569550,
-0.380300, 0.913360, 0.385390, -0.186520, -1.597150, -0.470180, 1.805610, 0.825590, -1.653510, 0.047990,
-0.082460, -1.084850, -0.956720, -1.825970, -3.046650, 0.947590, 4.018030, 0.925420, -0.060800, -0.883170,
3.319060, 0.236080, -0.011870, 1.487690, -0.928320, 0.503350, -1.726090, -0.144450, 0.478150, 1.267310,
0.703540, -2.003500, 0.203970, -2.174610, -0.575160, -0.588650, -0.605440, 0.854150, -0.665270, 2.619320,
-1.985440, 0.885530, -0.232460, -0.484740, -0.888050, -0.270140, 0.930110, -3.384030, -0.760310, 0.006180,
0.806960, -1.011780, -0.633120, 0.523230, -2.188960, -0.872730, 1.342270, 0.805390, -1.693910, 0.804590,
-0.764050, -0.840970, 3.529940, 0.795290, -0.615770, 0.860440, 0.689300, -1.369200, 1.200060, 5.319840,
0.628680, -1.846250, 0.328670, 0.336820, -0.290600, -0.551530, 0.442140, -1.460970, 0.003300, -1.064910,
-0.410480, -0.225960, -1.233210, -1.253140, 0.427650, 3.094710, -0.332470, -2.185680, 0.339310, -0.500280,
-3.558290, 0.071870, 1.374750, 0.308720, -0.567510, 1.008710, -1.786390, -0.022610, 1.311550, -0.814530,
-3.170330, -0.822360, -1.625820, -0.657160, 1.186290, -1.895350, 0.250350, 1.242760, -0.005200, 1.372910,
-1.385640, 0.050470, -0.698590, -0.084540, 0.527770, -0.876080, -0.050600, -0.525620, -0.792430, 1.702840,
-0.311550, 0.629030, -0.110620, 0.260410, 0.936850, -0.513160, 0.265610, 0.048130, -0.730990, -0.917170,
0.479900, 0.916930, -2.239950, -1.180020, -0.494160, 1.012010, -1.440580, -0.781530, 1.514080, 0.135440,
1.384550, -0.471540, -0.682290, 0.873380, -0.024190, 1.286970, 0.329000, -0.291700, 0.053440, 0.222420,
-0.068490, 0.402570, -0.289440, -3.018320, 1.158200, 1.294940, 0.157640, -0.635070, 0.244850, 1.211040,
-0.404050, -2.106540, -1.274140, 0.079410, 0.644320, 0.754810, -0.777680, 0.524610, -0.201460, -2.011780,
0.858970, -0.171410, 0.906050, -0.530350, 0.400440, 0.735880, 2.474650, 0.433090, -0.229160, 0.488720,
-0.269240, 0.346140, 1.443030, 0.124440, 0.493530, 3.304750, 1.077100, 0.893290, 0.590900, 0.257400,
0.814800, 0.681100, 2.778120, 1.175930, 0.534750, 0.831670, -0.813790, 0.690370,
-1.359260, -3.776790, 0.045900, 3.226100, -1.030400, 0.329630, -1.159360, -0.213380, -1.621400, -1.142620,
0.080400, 0.295590, 1.957480, 0.269470, -0.709650, -0.428200, 4.106330, -0.311770, -0.100940, 0.308550,
-0.291890, -0.553270, 0.113370, -0.208030, 1.379040, -0.288030, 2.575660, -2.320910, 2.587720, -1.424520,
0.057800, 0.058170, 0.432980, -4.325470, -0.033250, -0.023530, -3.313810, 0.040540, 0.199890, 1.389510,
-2.198990, 0.279520, 3.973590, -1.119140, -0.266620, -0.088710, -0.675620, -0.547070, 0.585120, 1.834840,
-1.770770, -0.117860, -2.336260, 0.838580, 0.200330, -0.967080, -1.487980, -0.254230, 0.844510, -3.218940,
-0.292780, 0.038490, 0.542470, -0.667460, 1.059490, 0.573270, 0.596660, -0.481640, 0.334570, 1.636060,
-0.898590, 1.310140, 1.194910, -0.336270, 1.167360, -2.290910, -0.027270, 0.307900, -0.873560, -4.012700,
0.562600, -0.339750, -1.932340, -0.263100, -1.572780, -0.067280, -3.309950, 4.936310, 4.768360, -0.483640,
-0.965090, -0.712570, 1.741370, 2.223180, -0.724090, 0.174630, -0.470520, 0.367780, 0.020920, -1.701310,
1.481020, 0.138610, -0.346820, -0.899610, -0.563020, -0.274180, -2.168600, 0.317700, -1.218120, -1.408390,
1.392460, 1.560750, 0.677720, -0.334710, 0.141830, 1.451200, 1.073540, 1.276010, -0.539420, 0.453690,
0.603890, -1.172600, -2.562910, 0.767870, -1.087530, -1.846710, -1.417750, -0.074900, -0.253730, 0.552360,
0.332150, -0.347160, 0.227860, 0.334580, 1.303100, -0.488410, -0.240270, -0.318820, 0.263240, -2.212960,
-0.071580, 3.991970, 0.591810, -0.712460, 2.674250, 0.887260, -0.594830, 2.864200, -4.465280, -0.444300,
-0.281730, 0.669090, -1.460920, 0.246580, -0.657630, 0.913950, 4.475550, 0.798990, 0.684990, 0.146100,
1.806410, -0.878440, -2.813980, -0.523660, 4.044570, 1.187090, -0.797740, 3.577850, -2.373400, 0.430070,
1.267690, -3.144410, 0.219620, -1.253080, -2.157620, 1.393020, 0.740560, 0.411800, 2.127610, 1.749800,
-0.298310, -0.610080, -0.269850, -0.065120, -0.182710, -3.240430, 1.640300, 5.662690, -0.997430, 1.155500,
-0.549900, -1.266800, -0.747540, 1.426300, -0.853440, 1.270790, -0.013330, -1.484170, 0.591030, -0.217350,
0.239150, -1.678790, 2.046800, 3.029670, -0.407750, 0.940660, 1.249850, -0.992010, 0.969980, 2.793810,
3.757740, 1.615230, -0.401470, 0.954320, -1.408760, -2.041970, 0.462320, -4.430300, 0.651840, 0.688090,
1.125880, -1.013380, 0.908820, 1.558330, -0.700820, 6.438180, 0.910000, -1.157310, -0.436750, -2.450190,
1.529240, -4.806670, 1.787110, 9.049840, 1.037820, -3.523380, 0.987950, -1.930020, 0.062590, -0.437900,
-2.844130, -0.456700, 1.358840, -1.629350, 0.699920, -1.670200, 0.603390, -0.360430, 2.580900, 1.943660,
0.468250, -0.672660, 1.462070, -1.789410, -0.273770, -2.314780, 0.309690, 0.898340, 0.239620, -0.094450,
1.202970, 0.299990, 3.621920, -2.938390, -0.832090, 0.760210, -1.207790, -0.970570, 0.209720, 8.451580,
-0.086320, 0.528200, -0.012370, -1.585760, 1.014460, -1.129550, 4.389450, -0.057900, 0.163310, -1.036720,
8.582560, -0.848060, 0.416670, 0.424530, 0.342400, 0.384890, -0.403860, -0.016360, 0.515630, -0.659840,
-0.545340, -1.009240, 1.117190, 0.496250, -0.348660, -0.463910, -1.607280, -0.617750,
0.037670, -0.170090, 0.197880, 1.708200, -1.488650, -0.197170, 0.760210, -1.571080, -1.345020, 1.447760,
-0.792960, -1.480310, -0.729840, -1.735110, -1.593210, 1.624750, -2.025970, 0.882930, 1.372680, -0.300840,
0.779740, 0.319770, 0.730340, 0.206030, -1.935300, -0.441510, 0.698200, -0.957750, 1.571170, 0.588350,
-0.470660, -1.162060, 0.541590, -1.043770, -0.116680, 0.829160, -1.646740, 0.851280, -0.309730, 1.043440,
-0.774130, 1.547550, 0.692710, 1.624380, 0.370260, -0.270190, 0.394630, 0.457610, -0.848520, 1.671270,
-1.438690, 0.262570, 0.066670, -0.552250, -0.286740, 0.273610, -0.290900, 0.306610, -0.863760, -0.872920,
-0.444760, -0.907570, 0.427500, 0.576420, 0.593990, 1.312400, 0.019860, -2.272230, 0.333010, 0.165160,
0.868260, -0.334130, 2.146770, -0.751120, -1.379760, -1.141210, 0.930970, 0.127880, 0.599030, 0.426010,
0.631160, -0.492010, 0.705330, 0.402750, -0.367420, 0.158670, 0.829190, -2.380490, 1.398960, 0.207780,
-0.959340, 0.312100, 2.038690, -0.280000, 0.305570, 1.442310, -0.133230, 0.845330, -1.747880, -0.933220,
1.593210, -1.461240, 0.705620, -1.145180, 0.588240, -0.058960, 2.457650, -1.038170, -3.561510, 1.156410,
-0.047690, 1.023760, -0.216290, 0.118230, -0.943130, 1.476460, 3.764720, -0.952370, -1.740500, 0.223700,
0.777270, -1.035120, -0.324370, -0.002130, -0.612410, -0.133630, -0.360660, -1.218090, 5.107040, 1.717750,
0.523470, -2.097090, 1.331570, 0.083860, -0.514900, 1.500280, -0.253150, -4.282300, 1.594620, 7.698660,
1.072370, -1.035540, -0.943680, 1.298850, -1.043490, -0.095140, 1.296130, -0.791130, -2.021750, -0.965110,
-0.328500, 3.256420, 0.382050, -1.135280, -0.353490, 1.450010, -1.104380, 0.433020, 0.139710, 0.977650,
-1.379310, -0.617860, 4.337750, -2.091290, -0.304780, -3.490860, -0.695740, -2.254650, 0.942870, 0.506300,
0.191550, -2.065670, 0.480180, 0.997230, 2.171260, 1.618870, -0.395040, -1.350200, -0.100350, -0.611770,
0.716780, 1.272580, 0.068310, 0.618330, 1.088270, 1.627270, -0.667740, -1.090290, -1.275990, -0.095690,
1.565570, 0.004130, -0.199540, 0.445570, -0.076710, -0.303100, 1.559610, 1.258060, 0.370170, -0.098540,
0.216790, -0.899950, 2.528100, -0.176880, 1.032810, -1.909750, -0.877260, -1.014820, -0.301030, -0.465600,
0.383830, -2.087980, -1.021630, -1.665510, 1.381800, 0.662350, -0.907780, 1.420570, 0.308280, 0.168340,
0.087280, 1.812380, -0.223250, -0.376290, -0.786600, -0.815290, 0.405240, 0.571920, -0.899160, 0.203040,
1.246860, -0.086050, -0.054230, 0.108320, 0.345370, 0.909980, 1.741430, -0.106420, 0.686880, 0.943060,
1.143510, -0.193910, 0.395810, -1.511760, -1.626540, 0.658630, 1.570600, 0.168410, -0.522340, -0.620410,
-1.456410, -0.577180, 1.118570, 0.504640, -0.765690, -1.909330, -0.221680, -0.675460, 0.573340, 0.138210,
0.509700, 0.954210, 1.400840, 1.794960, 0.932300, 0.662580, -1.649370, -1.670200, -1.294360, -0.284370,
-0.049120, -0.582430, -0.340180, 3.069040, 0.002830, -1.158130, -2.703500, 0.370810, -0.041760, -0.292440,
-4.388720, -0.992420, 0.713970, -0.234360, -0.253070, -0.104460, -0.251680, -1.097860, -0.356850, 0.103960,
-1.250070, -1.756690, -0.558980, 0.652360, 0.171320, -1.202530, -0.715620, 0.087530,
0.222340, -0.660740, 0.388110, 0.189740, 0.365700, -0.163520, -1.588260, -0.576710, 0.694440, -0.531470,
1.794580, -0.953420, -0.395700, 0.430970, -1.247660, -0.196420, 1.844240, -0.803020, -0.644640, 1.077420,
-1.478910, -0.264260, 0.741180, -0.240680, -0.419690, -1.186810, -0.732690, 0.680770, -1.545610, -0.108610,
-0.463640, -0.960480, 0.254710, -0.441350, -0.815050, -0.053890, 0.598830, -1.107210, -0.577670, 0.690250,
-0.694370, 0.663890, -0.661330, -1.189380, -0.637290, 1.686590, -0.971760, -1.166030, 0.129800, 0.308760,
-0.314460, -1.297760, 1.447570, 0.263580, -0.448480, 0.589310, 0.038860, 0.315350, -1.587960, -0.725100,
-0.677220, -0.510040, 0.711670, -2.466050, 0.321650, -1.598970, -1.378260, -0.770440, -0.432950, -0.120890,
-1.600020, 0.427710, 1.079260, -0.628490, -0.763260, 1.163410, 1.106320, -1.127950, -1.243690, -0.537610,
-0.479090, 0.281190, -0.917360, -0.274100, 1.310980, 0.575980, -0.212150, 2.261130, 0.613500, -1.908990,
0.659010, 1.015480, -0.363300, -0.537220, 0.108550, -0.639890, 0.321830, -0.819480, 0.141340, -0.886190,
0.475470, -0.603130, -0.830770, 0.608700, -1.183080, -2.462550, -1.309010, 1.960840, -0.701850, -1.036120,
0.264280, 0.628660, -0.370230, 0.277180, 0.771010, 1.645060, 1.165690, 1.304630, -1.078540, 0.815220,
-0.134390, 0.893350, 0.946530, 1.968170, -0.253280, -0.132560, 0.059230, -0.528930, -0.598590, 0.747130,
-0.305010, 0.985620, 0.506560, -1.093790, -0.816120, 0.688440, -0.016290, 0.317390, 1.420780, 5.024750,
-1.180280, 0.700470, -1.003750, -1.716370, 0.399280, -0.567740, 1.968100, -2.203420, -1.665100, -0.965210,
0.870880, 1.938990, 1.248950, -0.315310, -1.732340, -1.244720, -0.147920, -0.416830, 0.422590, 0.408870,
-0.200390, 1.683510, 8.124960, -0.741210, 0.346550, -0.812080, -2.118150, -1.901230, -0.866190, 0.484160,
-0.679660, -1.548720, 0.576560, 1.309630, 1.841430, 1.012350, -2.032720, -0.655490, 0.842290, 1.316700,
-0.393630, -1.058480, 0.574240, 1.394760, 1.648090, 1.210090, 0.562800, -0.460900, -1.361880, -0.247540,
-0.674510, -0.392870, -0.904550, 0.396780, -0.154930, 0.005420, 0.481530, -0.198100, 0.142780, -0.164440,
-0.976730, 1.923070, 0.290940, 0.031850, -1.495800, 0.644090, 0.202370, -1.780290, 0.956320, -0.048830,
0.735950, -1.468600, 0.345620, -0.700020, 0.293790, -2.347690, 1.282610, -0.258720, -0.317840, 1.666210,
-0.094270, 0.450330, 0.571750, 0.029520, 0.223600, -0.083930, 0.608360, -0.058910, -1.031570, -2.234620,
0.262660, -0.377780, 2.136420, -0.155560, -0.431290, -0.689630, -1.300050, 1.441460, -2.831360, 0.787290,
-0.703520, -0.483770, 1.378690, -0.402450, -1.629890, 0.041910, 0.857390, 0.306210, 0.081630, -0.250310,
-0.068020, 0.466990, 0.391700, -0.175390, -0.736970, -0.551540, -0.391180, -0.571710, 0.318940, -1.012970,
0.384950, 0.051380, 1.586340, 0.437200, 0.130760, 0.264520, -0.958830, -0.102170, -1.880890, 0.412150,
-0.522710, -1.215180, 0.576500, -0.691030, 0.459410, 0.433740, -3.054840, -0.770790, -2.696880, 0.394090,
0.129330, 0.092590, -0.276050, 2.802040, -1.218290, 0.378600, -0.085360, 0.635180, -0.867350, 0.155360,
0.103080, -1.061910, -0.269970, -1.595010, 0.337480, 0.076030, -0.429780, -0.419290,
0.608640, -0.478130, 0.682570, 0.279280, 0.002500, -0.420080, 0.809310, 1.036140, 2.036490, -0.866570,
2.454890, 0.819960, -0.313960, 0.341540, -0.212360, 0.059650, -0.263650, 1.210100, 1.375510, 0.466920,
0.660330, 0.547160, 1.922970, -0.576010, 4.761850, 0.427770, -0.153270, 4.796140, 1.014040, -0.752340,
-0.722760, -0.524000, 0.447930, -1.226390, 0.065390, -0.304810, 0.826510, 0.177040, -0.920560, 1.373510,
-0.281870, -0.431030, -0.214430, -1.208390, 0.013820, -0.807910, 0.517610, -0.313280, 6.993460, 0.065680,
-0.750470, -6.770020, -0.776920, 0.580800, 0.402170, 0.339020, 0.834660, 0.638070, 0.487290, 2.576330,

1.184520, -0.386530, -0.763410, -0.370100, 0.966120, -3.313910, 1.349000, 0.021850, 0.481570, -0.566340,
-0.854720, -0.253500, 4.033410, 0.424320, -0.812070, -0.708330, 0.901330, -0.728910, -0.882210, -0.836560,
-0.854300, -0.787140, -0.845190, 0.024850, 1.530670, 1.055550, 0.470280, 0.509760, -0.121320, 0.588200,
0.227120, -0.597760, 2.218850, -0.898260, -0.665990, 0.690920, 0.959470, 0.262140, 0.634570, -1.116730,
-0.010130, 0.203700, 0.754510, -2.646930, -0.477670, -1.182510, 0.437550, -0.205120, -0.245030, -0.181610,
1.058030, 0.129260, 0.337500, 4.699970, 2.107780, 0.633750, 0.286970, 0.619160, -0.602570, 0.815120,

0.223390, -0.570180, -0.708320, 0.799210, -0.292590, 0.530420, 0.485060, 0.246900, 1.708230, -0.180590,
-0.348780, -0.205070, 1.264540, 0.958840, -0.906010, -1.211040, 0.847580, -1.441460, 0.760990, -0.346800,
-1.105460, -1.872240, 0.151290, 0.374690, 0.408670, 0.059710, -0.894070, -0.199760, -0.142870, -1.338910,
-0.612060, 0.724640, 0.616980, -1.494410, -0.323230, -0.647570, 0.718680, 5.272160, -0.643670, 0.189410,
0.343250, 0.032100, 0.254330, -0.336660, 0.551540, -0.659220, 0.646750, -0.008350, 0.021940, -0.241700,
0.222170, -1.062880, 0.178070, 0.366220, 0.139720, 0.599610, -0.059230, 0.295010, -0.730830, -0.548480,

-1.673740, -0.265470, 0.497140, -1.537260, 0.693510, -0.700870, -0.559430, -0.062970, 1.174420, -0.657270,
0.485990, -0.019370, -0.953160, -1.229040, -0.621780, -0.909040, -0.440460, 1.152640, -1.328760, 0.417810,
-0.812740, -1.255200, -0.642670, -0.356120, -0.398780, 0.077200, 0.952660, 0.153670, 0.724490, 1.053480,
-0.506610, 0.781760, 0.822180, 0.465700, -0.405020, -0.037380, -0.875630, -0.269990, 0.391880, 0.046610,
0.562400, -0.059420, -0.619270, -1.293970, -0.174430, -0.822880, 0.578660, -0.088270, 0.253570, -0.181360,
-0.708430, 1.385530, -0.289860, 0.503090, 2.014340, -0.759900, 0.565210, -0.358620, 1.036600, -0.479210,

-0.640340, 1.710260, 0.784420, 0.695940, 0.138230, -0.285460, -0.011730, 0.590720, 6.232710, -0.938030,
1.167450, 0.929230, 1.803860, -0.585460, 0.738270, 1.067640, -0.099390, 0.742300, -0.031010, 0.295250,
0.237090, 0.711290, 0.213850, 0.640440, -0.195300, 1.461090, -0.328340, 0.867870, 0.173980, -0.882960,
0.331750, -0.563120, -0.484980, 0.320030, -0.575830, 0.096060, 0.741000, -0.727010, -1.219530, 0.560890,
-0.445980, -0.642300, -0.511420, 1.141690, 0.873720, -0.332260, -0.819190, 0.672050, -0.401150, 0.914300,
-0.918410, 3.705600, -0.372050, -1.720280, -0.571320, -0.820120, 0.913740, 0.498740, 0.713240, -1.124020,

-2.255130, -1.654710, -1.679390, 2.659150, 1.039670, 0.139840, -2.149880, -1.429240, -0.548610, -0.480270,
0.131650, -1.071340, 0.025990, -0.082940, -0.682200, 1.407000, -0.178820, -1.612090, -0.654780, -2.012130,
-0.349910, -1.439460, -0.612990, -2.130870, -1.847640, 1.643540, 0.690400, -0.466420, 0.634290, 1.398230,
0.779480, -0.333890, 1.305330, -5.892090, -1.596700, 1.079660, 0.677310, 3.812360, 0.013950, 12.652710,
-0.713360, 0.023820, 0.472770, 4.299170, -0.945400, 1.391350, -0.322930, -0.245810, -0.409540, 0.147910,
0.821830, -0.193310, -0.535520, 0.138060, -1.541120, 0.468790, -2.472320, -0.373580, -0.170610, -0.836710,

0.532970, 0.646890, 0.126570, 0.324290, -0.430970, -1.212140, 0.466890, 0.372950, -0.450730, -0.457430,
-0.193380, 0.077770, -0.096450, -0.180370, -0.286900, 0.525760, -0.460180, -0.492340, 0.500000, -0.763890,
0.840930, -0.669350, -0.187440, -0.397820, 0.489950, -0.010240, 1.021060, 0.099860, 0.061600, 0.517430,
0.599810, -0.639080, 1.184480, -0.469090, 0.076830, -0.450850, 0.757580, -0.568210, -0.477710, 0.287540,
0.424910, -0.867100, -0.313170, -0.151040, -0.333710, 1.520380, 0.695020, 0.478930, 0.052000, 0.638920,
0.293000, -0.475080, -0.803080, 0.268680, 0.893160, 1.115620, -0.442150, -0.402850, -0.468720, 0.856680,

-0.164790, 0.062420, -0.978780, -0.373950, -0.443470, 0.107140, -1.052410, -1.024160, 0.844660, 0.067650,
0.732760, 0.457570, -0.689220, -0.158280, -0.355930, -0.674830, -0.338460, -0.122460, 0.764230, -0.308670,
-0.270820, 0.008650, -0.116460, -1.041200, 0.689910, 0.306800, -0.974270, 0.477320, -0.094140, 0.215020,
0.448660, 0.746780, 1.237590, 0.358800, 0.541970, -0.142590, -1.167830, -2.343800, 0.460460, -0.252990,
-0.337010, 0.266770, -0.480370, -0.161110, -0.410670, -0.828590, 0.669990, -0.677470, -0.439080, 0.105260,
-0.877760, 1.586700, 0.272240, -0.117890, 0.970800, 0.297080, 0.120420, -0.446850, -0.691820, 0.411320,

1.478140, -2.057470, 0.390050, -1.786080, -1.490910, 3.246960, 0.106100, -1.361790, -2.177880, 0.671370,
-0.577530, -0.242620, -3.364100, 1.067560, -0.865800, -0.973940, -0.948530, 0.049000, 1.316200, -0.121040,
-1.022460, 1.004720, 1.485030, 1.685560, -1.830280, -1.881930, -2.097210, -0.515660, 2.694650, -4.256870,
-0.121270, 1.469070, 0.277490, -0.395900, 1.115140, -0.442570, -0.923680, 1.248470, -0.368220, 0.941210,
0.064280, -0.987760, -0.408500, -0.342360, -1.024120, 0.302350, -0.126210, -0.505880, 0.469810, 0.154940,
-0.136650, -0.826050, 0.174430, 1.872070, -0.186400, -0.662810, 0.188730, -0.661510, -0.431750, 1.208460,

1.151060, -2.005650, -1.398040, -0.678750, -0.457010, 1.438030, 1.385600, -0.798390, 4.156410, 0.441420,
-0.207630, -1.846530, 0.031900, 0.697860, 0.168680, -0.053780, 0.365320, -2.298290, 0.080820, -0.200680,
-0.010950, -0.452780, 1.596590, 2.137010, 6.277020, 4.337760, -0.840950, -0.251670, -1.693870, -1.561600,
-0.265780, -1.408640, -0.176380, -0.833890, -1.624940, 10.817440, -0.936920, 1.912760, 1.601420, 6.009400,
0.345650, -1.335300, 0.340940, 4.263650, -0.534940, -5.806760, 0.160260, -1.384130, -1.899050, -2.657770,
-0.316100, -5.683600, 0.298270, 0.553910, -3.932800, -0.317480, -1.875400, -0.171400, 0.053540, 0.102920,

-0.902760, 0.439600, -0.683710, -0.442890, -0.438730, 2.687110, -0.760180, 0.045660, -0.753180, 0.997450,
-0.862000, -0.515880, -1.375190, 0.485470, 0.589750, -1.141650, -1.065750, 0.381250, 0.564640, -0.717520,
-0.094960, 0.030410, 0.356140, -0.628950, -1.780300, -1.746760, 0.476640, -0.883760, -0.454880, -0.282280,
0.085190, 0.937310, -0.605710, 0.788000, -0.032370, 0.280870, 0.554760, -1.036370, 1.386790, -1.262850,
0.165860, 0.504440, 0.059610, -0.581630, -0.946880, -0.012500, -0.451940, 0.603210, 4.488390, 0.156660,
-0.183850, -0.845060, -0.096720, 1.185120, 0.303370, 0.463730, 0.271510, -0.354760, 0.687530, 1.115920,

0.719860, 1.482370, 0.771320, -0.397360, -0.012080, 1.075340, 0.831430, 1.679790, -2.405090, -1.214710,
0.406870, 0.452950, -0.081240, -0.634650, 1.358760, -0.895500, 0.463940, 0.775050, 0.726880, -0.037360,
-0.685500, 0.330750, 0.544310, 0.028660, -0.991450, 0.852980, 0.408860, 0.182790, -1.170830, -0.102360,
0.017620, -0.857370, -0.562350, 0.732480, -0.378380, 0.739650, 0.882810, 1.481100, -0.099370, -0.782900,
-0.007660, 0.889920, -1.592910, 0.590280, -0.354530, -0.195060, 0.409530, -0.493660, 1.082930, -0.089570,
-0.849130, -6.029630, 0.906320, 0.308970, 0.618600, 0.382700, 0.713840, -0.407860, 0.590390, 0.926040,

-0.048620, -0.394470, 0.544940, -0.795440, -0.935540, -0.514990, 0.489700, -1.224690, 0.590380, -0.435190,
-0.774860, 0.420940, 1.297340, 0.686200, -0.647690, 0.588690, 0.135700, 0.239570, 0.638050, 1.332520,
-1.023100, 0.386780, -1.146020, 0.362440, -0.028100, -0.145270, -0.417470, 0.812020, -1.608770, -0.504940,
0.232680, -0.851260, -0.644380, -0.956840, -0.421780, 0.926270, -0.883990, -0.734650, 0.110390, -1.401490,
0.151510, -0.066950, -0.808650, -0.521000, 0.013990, 0.626160, -0.859460, -1.213790, 1.201090, 0.723800,
0.676230, 0.654390, -0.571930, 0.485320, 0.457020, -0.053890, -0.381270, 0.703400, 0.818090, -0.025660,

-0.266470, 0.508580, 0.204230, 0.373630, -1.014040, -1.478300, 0.786440, -0.307500, -2.849560, 0.069830,
0.498900, -0.323380, 2.489690, -0.089630, -0.527710, 0.511120, 0.843080, -0.585870, -1.240640, 0.604650,
-0.275970, -0.562980, -0.081780, 0.523620, 0.627480, 1.170950, -0.951420, 0.157140, -1.021250, 0.384320,
0.597940, 0.512970, 0.466380, -0.175150, 0.185730, 1.002040, -0.660120, 0.789640, -1.005490, -1.667530,
0.323670, 0.704290, 0.148780, 2.001220, -0.964510, -0.554310, -0.691770, 0.280040, -0.708670, -0.490570,
-1.081880, 0.266680, -1.855960, 0.028050, 0.213020, -0.268190, -0.126930, -0.271170, 0.557400, -1.321620,

0.254700, 0.403780, -0.027000, -0.284670, -0.752810, -0.631530, 0.262770, -0.590580, -0.423420, -0.945350,
0.086120, -0.528320, -0.085850, 0.248440, 0.071260, -0.746880, 0.352490, 0.356700, -0.429470, 0.372200,
-0.254720, -0.321770, 0.041250, 0.557810, 0.109870, 0.178270, 0.298730, 0.286520, -0.324630, 0.046270,
-0.146590, 0.782890, 0.675740, -0.652160, -0.708780, 0.032390, -0.974650, 1.107990, 0.497170, 0.043090,
0.771030, 0.891120, -0.107480, 0.244390, -0.935460, -0.363990, -0.294070, -0.653140, 2.211550, -0.740190,
0.019740, -1.542990, -0.387100, 0.120680, 0.677600, -0.496970, -0.001700, -0.537980, 0.852040, 0.189200,

-1.067790, 0.334730, 0.767360, -0.785860, -0.152520, -1.410930, -0.773030, -0.344630, 1.172050, -0.510980,
0.891380, -0.341550, 1.129290, -0.585910, -1.914250, 1.160940, 0.673140, 0.088630, -0.832330, -0.092930,
0.205670, -0.991830, -0.782250, -0.906310, 0.436240, 0.787150, -0.089120, -0.350520, 0.074020, -0.575670,
0.799420, 0.862370, -0.142520, -0.583040, 0.216310, -0.337670, -0.814650, 2.113950, -1.927740, 0.604090,
-1.336500, 0.163520, 0.646080, 0.867480, -0.740700, 0.935650, -0.038990, -0.076010, -0.869160, -0.304240,
0.717330, -4.634010, -0.597170, -0.691920, -0.134140, 0.589200, 0.704130, -0.355190, -1.099460, -1.267130,

0.894440, -1.502660, -0.924410, 0.022090, 0.664940, 1.875180, -0.775200, 0.597300, -6.550610, 0.498630,
0.175910, -0.686110, -3.395090, 0.351310, 0.490210, -3.636120, -1.367680, -0.837790, -0.279610, 0.426980,
0.971110, -0.191570, 0.478330, -0.252770, -1.868360, -2.815880, -0.178940, 0.279440, -0.509000, -0.775140,
-0.457610, 0.354040, 0.920570, -0.301350, 0.495920, 3.435430, -0.581450, -1.079780, 1.885190, -3.194710,
0.659790, 0.806840, 0.573250, -3.114630, 0.381520, -2.546220, -0.182810, -0.211680, 7.869750, 0.365180,
-0.804110, -2.359250, 0.902620, 1.296790, -0.114470, 0.562060, 0.287470, 0.004560, 0.764630, 0.572060,

-0.359260, -0.107180, -0.297390, -0.388720, -0.514270, -1.525930, -0.715440, 0.763190, 0.212030, -0.393260,
0.983800, -0.016380, -0.020500, -0.042330, -0.547110, 0.329670, -0.653850, -0.354880, 0.903610, -0.217440,
0.032000, -0.611810, -0.098180, -0.193270, -0.098880, 0.295320, -1.214080, 0.720710, 0.363170, -0.512410,
0.170190, -0.425110, 0.436930, 0.714420, 0.104920, 0.815340, 0.444230, -0.519750, -0.444270, -0.993790,
0.033190, 0.852490, -0.792880, -0.961360, 0.802460, -0.541350, -0.084390, -0.685930, -0.947270, -0.932780,
0.137820, 0.340040, -0.318190, 0.550810, -0.229180, -0.172900, -0.387110, -0.433720, 0.415840, -0.555500,

-0.611210, -0.190970, -0.430730, -0.159100, 0.065940, 0.873660, -0.641400, -0.169700, -0.635230, -0.364240,
0.874630, -0.221600, -0.583550, -0.833510, -0.623540, 0.408790, -1.373300, 0.041470, 0.592820, -0.261120,
-0.029730, -1.137920, -0.586700, -0.795710, 0.473290, -0.024530, 0.788320, -0.014580, -0.250800, 0.153000,
-0.141500, 0.622380, 1.023070, -0.744780, -1.504010, -0.199170, 0.595790, -0.315400, 1.176010, -0.004900,
-0.427670, 0.125260, -0.586400, -1.153380, 0.316790, -5.405000, 0.190460, 1.031230, 0.321730, -0.810210,
0.268960, -0.866970, -1.506250, 1.910750, -1.389490, -0.706680, -0.116170, -0.334090, 0.783920, 0.801950,

0.715210, 0.241940, -0.426050, 0.200860, -0.284150, 0.527450, -1.223930, -0.442550, 1.383310, 0.823850,
0.302880, -0.185200, -1.051460, 0.229090, 0.644900, 0.704130, 0.670970, -0.006970, 0.400020, 0.518930,
0.478350, 0.156660, 0.439350, -0.040460, -0.671920, -0.162060, 0.321890, 0.214590, -0.108400, -0.304850,
0.161910, -1.560000, -0.695400, 0.296420, 0.492230, -0.127460, 0.014800, -4.910330, -0.123380, 1.809760,
0.075850, -0.957530, -0.576110, -2.173010, -0.902430, -0.783150, 0.038980, 0.526720, 2.169090, -1.135670,
0.249610, 1.422020, 1.324190, -1.322800, 0.721820, -0.641100, 0.612050, 0.274810, -0.528040, -0.113530,

0.538610, 1.147340, -0.045560, -1.672560, -1.228080, 0.918930, 0.010720, 0.780790, -1.131300, -0.561670,
0.795240, -0.053430, -0.495720, 0.309410, 0.439590, -0.828340, -0.907810, 1.228370, 0.104210, 0.118960,
0.148810, -0.460750, -0.138680, -0.463910, -1.548120, 0.271070, 0.647490, 0.225140, -0.123570, -0.162700,
-0.280070, 0.767440, 0.023210, -0.190910, 0.425310, -0.372260, -0.259830, -0.685840, -0.196430, 0.440500,
0.314520, -0.301270, -1.359410, 0.810340, 0.819240, 0.340000, 0.399740, 0.031360, -0.802500, 0.182490,
0.836190, 0.585890, 0.002730, 0.865320, 0.169710, 0.519940, 0.715140, 0.535040, 0.669130, -0.044000,

0.227100, 0.297460, -0.027230, 0.189710, -0.579300, -1.349140, -0.705730, -0.815800, 1.194950, 0.260810,
-0.270500, 0.914530, 1.121170, -1.006320, 0.021920, 0.056130, -0.065090, 1.090620, 0.055900, 0.192120,
-0.396410, -0.323700, -0.980530, -0.618720, 1.209060, 0.018050, 1.018540, 0.112810, -0.260130, 0.677830,
0.944110, -0.285430, -0.905990, 0.319680, -1.006070, -0.207290, -0.029270, -1.080420, 0.050590, -0.031490,
-0.278270, 0.713560, -0.007520, 0.412510, -1.040660, -0.496650, 0.383070, 0.535590, 0.436190, -0.184920,
-0.345900, 0.072990, -0.750480, -0.371650, 0.032170, -0.458440, -0.877070, 1.048840, -0.773330, -0.930620,

-1.424650, -0.157680, 0.591710, 0.983740, 0.975950, 0.187760, -0.865730, 0.789220, 1.089360, 0.791670,
-0.808420, 0.663080, -1.042500, -1.137650, 0.673150, 0.948230, -0.960800, -0.622280, 0.710230, -0.752370,
0.944830, 0.019460, -0.754530, -1.309870, -0.416480, -0.503800, -0.200870, -0.719040, 0.362070, 0.929520,
-0.187810, 0.497700, 0.486060, 0.155080, 0.268700, 6.363400, -0.865770, -0.874150, 0.451190, -7.616070,
-0.591630, 0.743420, 0.106430, -0.140440, -0.453750, -0.069470, 0.416230, -1.109660, 2.093400, 0.322300,
-0.489560, -1.419380, -0.172920, 0.245830, 0.801790, -0.703500, 0.555440, 0.137810, -0.602300, 1.380440,

-0.019150, -2.219980, -0.481710, 0.371210, -0.472580, 0.474260, 0.093570, -1.150180, -2.612810, -0.299910,
-1.627420, -1.042480, -1.142970, -0.013720, 0.147590, 0.510700, 0.013430, -0.776050, 0.433130, -1.161970,
0.505370, 0.544440, 0.646680, 1.327060, 1.887130, -2.689050, -0.413230, -0.077150, 0.663350, -0.087680,
0.490420, -0.566800, 1.166540, -1.108400, -0.675880, 1.359740, -1.139520, 1.228380, 1.078100, -1.069350,
0.961480, 0.197970, 0.564960, -0.727210, 0.501450, -3.192960, -0.470790, 0.854870, 0.143970, 0.714450,
0.227260, -0.203010, -0.114700, 0.213500, -0.637710, -0.412840, -0.775150, -0.046700, -1.064990, -0.290100,

0.674440, 0.851370, -0.527050, 0.456800, -3.861530, -1.827560, 0.205520, -1.133070, 3.746120, 0.234180,
0.582750, 0.370930, 2.584780, 0.507620, -1.334210, 0.076400, 0.220740, 0.505270, -0.233550, 0.819260,
-1.092910, 0.091230, -1.339190, -0.933740, 0.766190, 1.464010, 0.180880, 0.619470, -1.728320, -0.415790,
-0.159700, -0.039540, 0.237680, -0.603040, -0.110350, -0.348610, -0.601060, 0.769180, -0.768180, 1.326320,
-0.577990, 0.349400, 0.142870, 0.798230, 0.110030, -0.445940, -0.439310, -0.649620, -1.194460, -0.983710,
0.674810, 1.384950, 0.704630, -0.248570, -0.257750, 0.735720, -0.170940, -0.397490, -0.679570, -0.307860,

0.509070, 0.125440, -0.564640, 0.869800, 0.600530, 0.567840, 0.697520, 0.556930, -0.856210, -0.501130,
-0.104690, -0.056370, -0.215380, -0.451090, -0.094950, 0.329820, 0.091580, -0.700120, -0.399030, -0.521580,
0.550200, 1.002120, 0.204700, 0.510220, 1.076340, 0.406770, 0.036540, -0.375480, -0.617520, -0.058980,
-0.158500, 0.146580, 0.782380, -0.817450, -0.065930, -1.336920, -0.853500, 0.245130, -0.409530, 1.442760,
0.324800, 0.703390, 0.726150, 0.886240, 0.148010, 0.667860, 0.287230, -0.347780, -0.715270, -0.263700,
-0.264850, 0.394510, -1.149450, 1.838070, 0.425490, -0.823330, -0.844640, -0.551730, 0.460610, -0.078730,

-0.577600, 1.920130, 0.625900, 0.931640, 0.298020, -2.908110, -0.672150, 0.560330, 1.956190, 0.414150,
0.703870, 0.842030, 1.382210, -0.279960, -0.021890, 0.469670, -0.050050, 0.542550, -0.929450, 0.451200,
-0.519010, -0.153870, -0.363510, -0.221890, -0.762420, 1.321310, 0.322860, 0.572210, 0.776990, 0.870590,
0.701120, 0.951330, -0.152390, -0.652990, 0.789490, 1.497370, -0.661130, 0.414320, 0.130560, -0.408730,
-0.110270, -0.541230, 0.357450, 0.359560, 0.593360, -0.342710, -0.573600, -2.270980, 0.570060, -0.982980,
-0.513270, -0.645070, 0.405060, -0.960060, 0.229490, -1.000860, -0.353860, 0.520150, 0.108300, -1.244710,

-0.679460, -0.063020, 0.583040, 0.019030, 0.721110, 2.741790, -0.785710, 1.981370, -2.767320, 0.721610,
-0.214800, -0.251380, -1.417400, -0.784940, -0.484690, 0.514120, -0.921130, -0.552400, 0.396140, -1.283790,
0.866700, 0.315680, 2.137310, -0.065050, -0.895860, -0.412010, -0.141490, -0.820100, -1.153700, 0.479900,
0.023490, 0.405630, -0.241150, -0.937150, -0.196470, -1.331280, 0.525750, 0.703470, 0.866610, 1.341970,
-0.458320, 0.774470, -0.899100, -0.095070, -0.636380, -0.038540, 0.018190, 0.703980, 2.007210, 0.026460,
-0.202070, 0.404080, 0.312730, -0.254420, 0.851700, 1.027090, 0.724130, 0.426820, -0.507120, 0.539830,

-0.120650, -0.112640, 0.713550, 0.382990, 1.151620, -1.265280, 1.137070, 1.334380, 2.053590, 0.273980,
0.215630, 1.105710, 0.647620, -0.178540, 0.599120, -0.366370, 0.774800, 0.405300, -0.100790, -0.162540,
-0.450190, -0.146220, -0.389620, -2.748110, 0.562560, 0.515020, 0.134790, 0.458660, 0.603250, 0.861320,
-0.513760, -0.722000, -1.810720, 6.349060, 0.339230, -0.545310, 0.685330, 0.598950, 0.302850, 0.724070,
0.835050, 1.035150, -0.173530, -0.647430, 0.740150, 0.260690, 1.123830, -0.146340, 0.554080, -0.500320,
0.401990, -2.928130, 2.168750, 0.976910, 0.082690, 0.420830, -0.288120, 0.045220, -0.449470, 0.477880,

0.774940, -2.174320, -0.820590, -0.696530, -0.370890, 1.403230, -0.013620, 0.366330, -5.006510, 0.169480,
-0.590310, -0.999390, -1.090540, 0.529630, -0.053940, 0.676310, -0.644700, -1.338410, 0.030910, -1.709250,
0.733690, 0.568960, 0.800210, 0.528830, 0.244330, -1.826410, -0.680890, -0.810340, -1.568810, 0.153160,
0.803460, -0.853900, 1.002350, -0.338950, -0.260530, -3.390640, -0.645660, -0.582970, 1.519940, 3.504160,
0.789840, -0.020810, 0.595000, -0.235450, -0.541670, -0.350120, 0.595040, 1.912040, 0.340010, -0.134790,
0.582980, -0.899720, -0.530290, 1.080680, -0.390310, -0.847500, 0.313860, -0.739410, -0.067860, 0.052220,

0.839230, -0.190760, 0.293180, -0.891350, -0.125110, 0.235170, -0.147830, 0.368710, -0.816730, 0.072010,
-0.489300, 0.071000, 0.499000, 1.428640, -0.281220, 0.820590, -0.663430, -0.730320, -1.656430, -1.252290,
0.486330, -2.968910, -0.077990, -1.169440, 0.479030, 0.160340, 0.979280, -0.400420, -0.446460, -0.519170,

-0.615340, 0.650840, 1.029870, 0.555110, -0.743150, 0.603400, 0.218800, -0.238680, 0.562840, 0.303780,
0.775660, -0.558190, -0.508200, -1.383500, 0.715660, -1.262720, 0.327970, 0.296430, 1.144150, -0.904580,
0.420840, 0.314280, 0.177420, 0.284800, -1.216320, -0.459670, -0.480930, -0.216350, 0.192610, 0.229600,

0.831130, -0.706940, -0.218910, -0.072270, 0.550330, -0.516530, -0.417260, 0.129130, -0.188360, -0.093090,
-0.579370, -0.383680, 0.160250, -1.118320, -0.837710, -1.111430, 0.044880, 0.166710, -1.420990, 0.772620,
0.232790, 1.328130, 0.128460, -0.313230, -0.215250, -0.424060, 0.504620, 0.518790, -0.964160, 0.692810,

-0.025190, 0.195200, 0.448260, -0.542790, 0.568590, 0.159100, -0.658910, 1.534950, -1.608780, -0.007260,
-0.087880, -0.276580, 0.797280, 1.031110, 0.613650, 0.631350, -0.643410, -0.060350, -1.735590, -0.346120,
-0.366060, -1.153950, -0.533120, -1.759960, 0.497020, 0.714730, 0.199590, -0.455160, 0.317950, -0.610890,

-0.811480, 0.644910, 0.698190, -0.743900, -0.518370, 0.656780, 0.255030, 1.317900, 0.786710, -0.002510,
0.100760, -0.851880, 0.142550, -0.946660, 0.184160, -1.196860, 0.999600, 0.036460, 0.378360, -0.962310,
-0.650780, 0.021490, -0.117870, 0.883010, -1.126060, -0.219350, -0.653530, 0.974240, -0.783690, 0.617860,

-0.483570, -0.745460, -0.948990, 0.514670, 0.557260, -0.251590, 0.248950, -1.931300, -0.152790, -0.065140,
-0.135240, -0.169440, -0.441230, -0.588320, 0.495690, -0.817710, -0.176620, 0.531950, -0.437440, 0.455460,
-0.461590, 1.025380, 0.637050, -1.148260, -0.609830, -0.756490, -0.282840, 0.754010, 0.394400, -0.460120,

-0.503920, 0.071780, 0.506390, -0.454170, 0.466680, -0.343560, 0.436980, 1.352140, -1.482500, 0.311890,
-0.568200, 0.472590, 0.789130, 0.859050, 0.243040, -0.058450, -0.223640, -1.034930, -0.919740, -0.474970,
-0.375170, 1.361320, -1.080100, -1.960180, 0.592610, -0.287410, 0.466510, -1.291710, -0.785180, -0.383600,

-0.328430, -0.357640, 0.834090, -1.107920, -0.392510, -0.453680, 0.242730, 0.981430, 1.013660, 0.712910,
0.317160, 0.340890, 0.319680, -1.138140, 0.263620, -1.103330, 0.384290, 0.591430, -0.348590, -0.180030,
-0.814650, -1.757340, -0.623550, 0.839110, -1.662380, -0.071620, -0.797330, 0.041820, -0.756160, 0.771440,

-0.027580, -0.636120, -0.608730, 1.017750, 0.170700, 0.571480, 0.967020, -0.708140, -0.572830, -0.610020,
0.193380, 0.467830, -0.772080, -0.386000, -0.652370, -0.288180, -0.115290, -0.057280, 0.708160, -0.161280,
-0.525110, -1.085060, 0.609250, -1.099380, -0.568050, -0.614260, 0.757390, 0.981660, -0.449510, -0.219590,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.030900, 298,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid12) */
      0.0, -1.683520, 298,
       &Sources[298] ,
       &Weights[298] ,
      },
    { /* unit 271 (hid13) */
      0.0, 0.123410, 298,
       &Sources[596] ,
       &Weights[596] ,
      },
    { /* unit 272 (hid14) */
      0.0, -0.663310, 298,
       &Sources[894] ,
       &Weights[894] ,
      },
    { /* unit 273 (hid15) */
      0.0, -0.442850, 298,
       &Sources[1192] ,
       &Weights[1192] ,
      },
    { /* unit 274 (hid16) */
      0.0, -1.644740, 298,
       &Sources[1490] ,
       &Weights[1490] ,
      },
    { /* unit 275 (hid17) */
      0.0, -0.780940, 298,
       &Sources[1788] ,
       &Weights[1788] ,
      },
    { /* unit 276 (hid18) */
      0.0, -0.115120, 298,
       &Sources[2086] ,
       &Weights[2086] ,
      },
    { /* unit 277 (hid19) */
      0.0, -3.634450, 298,
       &Sources[2384] ,
       &Weights[2384] ,
      },
    { /* unit 278 (hid110) */
      0.0, 0.380480, 298,
       &Sources[2682] ,
       &Weights[2682] ,
      },
    { /* unit 279 (hid111) */
      0.0, -1.296050, 298,
       &Sources[2980] ,
       &Weights[2980] ,
      },
    { /* unit 280 (hid112) */
      0.0, -0.534500, 298,
       &Sources[3278] ,
       &Weights[3278] ,
      },
    { /* unit 281 (hid113) */
      0.0, 0.392160, 298,
       &Sources[3576] ,
       &Weights[3576] ,
      },
    { /* unit 282 (hid114) */
      0.0, -0.096430, 298,
       &Sources[3874] ,
       &Weights[3874] ,
      },
    { /* unit 283 (hid115) */
      0.0, 0.707330, 298,
       &Sources[4172] ,
       &Weights[4172] ,
      },
    { /* unit 284 (hid116) */
      0.0, 0.022070, 298,
       &Sources[4470] ,
       &Weights[4470] ,
      },
    { /* unit 285 (hid117) */
      0.0, 0.219500, 298,
       &Sources[4768] ,
       &Weights[4768] ,
      },
    { /* unit 286 (hid118) */
      0.0, -0.736560, 298,
       &Sources[5066] ,
       &Weights[5066] ,
      },
    { /* unit 287 (hid119) */
      0.0, -1.273210, 298,
       &Sources[5364] ,
       &Weights[5364] ,
      },
    { /* unit 288 (hid120) */
      0.0, 0.855840, 298,
       &Sources[5662] ,
       &Weights[5662] ,
      },
    { /* unit 289 (hid121) */
      0.0, 1.193130, 298,
       &Sources[5960] ,
       &Weights[5960] ,
      },
    { /* unit 290 (hid122) */
      0.0, -0.427900, 298,
       &Sources[6258] ,
       &Weights[6258] ,
      },
    { /* unit 291 (hid123) */
      0.0, 0.744480, 298,
       &Sources[6556] ,
       &Weights[6556] ,
      },
    { /* unit 292 (hid124) */
      0.0, -1.096240, 298,
       &Sources[6854] ,
       &Weights[6854] ,
      },
    { /* unit 293 (hid125) */
      0.0, -0.236350, 298,
       &Sources[7152] ,
       &Weights[7152] ,
      },
    { /* unit 294 (hid126) */
      0.0, -1.714470, 298,
       &Sources[7450] ,
       &Weights[7450] ,
      },
    { /* unit 295 (hid127) */
      0.0, 0.587740, 298,
       &Sources[7748] ,
       &Weights[7748] ,
      },
    { /* unit 296 (hid128) */
      0.0, -0.883510, 298,
       &Sources[8046] ,
       &Weights[8046] ,
      },
    { /* unit 297 (hid129) */
      0.0, -0.552870, 298,
       &Sources[8344] ,
       &Weights[8344] ,
      },
    { /* unit 298 (hid130) */
      0.0, -1.246290, 298,
       &Sources[8642] ,
       &Weights[8642] ,
      },
    { /* unit 299 (hid21) */
      0.0, -0.973610, 60,
       &Sources[8940] ,
       &Weights[8940] ,
      },
    { /* unit 300 (hid22) */
      0.0, 0.859480, 60,
       &Sources[9000] ,
       &Weights[9000] ,
      },
    { /* unit 301 (hid23) */
      0.0, 0.730850, 60,
       &Sources[9060] ,
       &Weights[9060] ,
      },
    { /* unit 302 (hid24) */
      0.0, 0.733470, 60,
       &Sources[9120] ,
       &Weights[9120] ,
      },
    { /* unit 303 (hid25) */
      0.0, -0.157280, 60,
       &Sources[9180] ,
       &Weights[9180] ,
      },
    { /* unit 304 (hid26) */
      0.0, -0.507090, 60,
       &Sources[9240] ,
       &Weights[9240] ,
      },
    { /* unit 305 (hid27) */
      0.0, 0.622210, 60,
       &Sources[9300] ,
       &Weights[9300] ,
      },
    { /* unit 306 (hid28) */
      0.0, 0.446210, 60,
       &Sources[9360] ,
       &Weights[9360] ,
      },
    { /* unit 307 (hid29) */
      0.0, -0.816570, 60,
       &Sources[9420] ,
       &Weights[9420] ,
      },
    { /* unit 308 (hid210) */
      0.0, -0.974700, 60,
       &Sources[9480] ,
       &Weights[9480] ,
      },
    { /* unit 309 (hid211) */
      0.0, 0.469710, 60,
       &Sources[9540] ,
       &Weights[9540] ,
      },
    { /* unit 310 (hid212) */
      0.0, 0.591590, 60,
       &Sources[9600] ,
       &Weights[9600] ,
      },
    { /* unit 311 (hid213) */
      0.0, -0.094630, 60,
       &Sources[9660] ,
       &Weights[9660] ,
      },
    { /* unit 312 (hid214) */
      0.0, -0.728690, 60,
       &Sources[9720] ,
       &Weights[9720] ,
      },
    { /* unit 313 (hid215) */
      0.0, 0.625720, 60,
       &Sources[9780] ,
       &Weights[9780] ,
      },
    { /* unit 314 (hid216) */
      0.0, 0.506110, 60,
       &Sources[9840] ,
       &Weights[9840] ,
      },
    { /* unit 315 (hid217) */
      0.0, -0.248450, 60,
       &Sources[9900] ,
       &Weights[9900] ,
      },
    { /* unit 316 (hid218) */
      0.0, -0.436640, 60,
       &Sources[9960] ,
       &Weights[9960] ,
      },
    { /* unit 317 (hid219) */
      0.0, -0.164130, 60,
       &Sources[10020] ,
       &Weights[10020] ,
      },
    { /* unit 318 (hid220) */
      0.0, -0.234970, 60,
       &Sources[10080] ,
       &Weights[10080] ,
      },
    { /* unit 319 (hid221) */
      0.0, -0.631080, 60,
       &Sources[10140] ,
       &Weights[10140] ,
      },
    { /* unit 320 (hid222) */
      0.0, -0.847600, 60,
       &Sources[10200] ,
       &Weights[10200] ,
      },
    { /* unit 321 (hid223) */
      0.0, 0.207610, 60,
       &Sources[10260] ,
       &Weights[10260] ,
      },
    { /* unit 322 (hid224) */
      0.0, 0.284620, 60,
       &Sources[10320] ,
       &Weights[10320] ,
      },
    { /* unit 323 (hid225) */
      0.0, -0.320820, 60,
       &Sources[10380] ,
       &Weights[10380] ,
      },
    { /* unit 324 (hid226) */
      0.0, -0.047920, 60,
       &Sources[10440] ,
       &Weights[10440] ,
      },
    { /* unit 325 (hid227) */
      0.0, 0.962790, 60,
       &Sources[10500] ,
       &Weights[10500] ,
      },
    { /* unit 326 (hid228) */
      0.0, 0.744840, 60,
       &Sources[10560] ,
       &Weights[10560] ,
      },
    { /* unit 327 (hid229) */
      0.0, 1.273880, 60,
       &Sources[10620] ,
       &Weights[10620] ,
      },
    { /* unit 328 (hid230) */
      0.0, 0.275830, 60,
       &Sources[10680] ,
       &Weights[10680] ,
      },
    { /* unit 329 (out1) */
      0.0, -0.934900, 30,
       &Sources[10740] ,
       &Weights[10740] ,
      },
    { /* unit 330 (out2) */
      0.0, -0.892070, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out3) */
      0.0, 0.253830, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out4) */
      0.0, -0.666610, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out5) */
      0.0, 0.334230, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out6) */
      0.0, 0.813430, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out7) */
      0.0, 0.921360, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out8) */
      0.0, 0.636440, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out9) */
      0.0, -0.577290, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (con11) */
0.08521, 0.500000, 2,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (con12) */
0.02863, 0.500000, 2,
       &Sources[11012] ,
       &Weights[11012] ,
      },
    { /* unit 340 (con13) */
1.41618, 0.500000, 2,
       &Sources[11014] ,
       &Weights[11014] ,
      },
    { /* unit 341 (con14) */
0.42041, 0.500000, 2,
       &Sources[11016] ,
       &Weights[11016] ,
      },
    { /* unit 342 (con15) */
0.40192, 0.500000, 2,
       &Sources[11018] ,
       &Weights[11018] ,
      },
    { /* unit 343 (con16) */
0.30000, 0.500000, 2,
       &Sources[11020] ,
       &Weights[11020] ,
      },
    { /* unit 344 (con17) */
0.00509, 0.500000, 2,
       &Sources[11022] ,
       &Weights[11022] ,
      },
    { /* unit 345 (con18) */
0.49516, 0.500000, 2,
       &Sources[11024] ,
       &Weights[11024] ,
      },
    { /* unit 346 (con19) */
0.00000, 0.500000, 2,
       &Sources[11026] ,
       &Weights[11026] ,
      },
    { /* unit 347 (con110) */
1.42848, 0.500000, 2,
       &Sources[11028] ,
       &Weights[11028] ,
      },
    { /* unit 348 (con111) */
1.40290, 0.500000, 2,
       &Sources[11030] ,
       &Weights[11030] ,
      },
    { /* unit 349 (con112) */
0.31227, 0.500000, 2,
       &Sources[11032] ,
       &Weights[11032] ,
      },
    { /* unit 350 (con113) */
0.00020, 0.500000, 2,
       &Sources[11034] ,
       &Weights[11034] ,
      },
    { /* unit 351 (con114) */
0.00105, 0.500000, 2,
       &Sources[11036] ,
       &Weights[11036] ,
      },
    { /* unit 352 (con115) */
1.32851, 0.500000, 2,
       &Sources[11038] ,
       &Weights[11038] ,
      },
    { /* unit 353 (con116) */
1.38953, 0.500000, 2,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 354 (con117) */
0.32952, 0.500000, 2,
       &Sources[11042] ,
       &Weights[11042] ,
      },
    { /* unit 355 (con118) */
0.30990, 0.500000, 2,
       &Sources[11044] ,
       &Weights[11044] ,
      },
    { /* unit 356 (con119) */
1.42565, 0.500000, 2,
       &Sources[11046] ,
       &Weights[11046] ,
      },
    { /* unit 357 (con120) */
1.00675, 0.500000, 2,
       &Sources[11048] ,
       &Weights[11048] ,
      },
    { /* unit 358 (con121) */
1.42775, 0.500000, 2,
       &Sources[11050] ,
       &Weights[11050] ,
      },
    { /* unit 359 (con122) */
1.39030, 0.500000, 2,
       &Sources[11052] ,
       &Weights[11052] ,
      },
    { /* unit 360 (con123) */
1.42477, 0.500000, 2,
       &Sources[11054] ,
       &Weights[11054] ,
      },
    { /* unit 361 (con124) */
0.00001, 0.500000, 2,
       &Sources[11056] ,
       &Weights[11056] ,
      },
    { /* unit 362 (con125) */
0.00007, 0.500000, 2,
       &Sources[11058] ,
       &Weights[11058] ,
      },
    { /* unit 363 (con126) */
0.11697, 0.500000, 2,
       &Sources[11060] ,
       &Weights[11060] ,
      },
    { /* unit 364 (con127) */
1.42849, 0.500000, 2,
       &Sources[11062] ,
       &Weights[11062] ,
      },
    { /* unit 365 (con128) */
0.30028, 0.500000, 2,
       &Sources[11064] ,
       &Weights[11064] ,
      },
    { /* unit 366 (con129) */
1.11707, 0.500000, 2,
       &Sources[11066] ,
       &Weights[11066] ,
      },
    { /* unit 367 (con130) */
0.33953, 0.500000, 2,
       &Sources[11068] ,
       &Weights[11068] ,
      },
    { /* unit 368 (con21) */
1.42635, 0.500000, 2,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 369 (con22) */
0.09987, 0.500000, 2,
       &Sources[11072] ,
       &Weights[11072] ,
      },
    { /* unit 370 (con23) */
0.01550, 0.500000, 2,
       &Sources[11074] ,
       &Weights[11074] ,
      },
    { /* unit 371 (con24) */
0.03579, 0.500000, 2,
       &Sources[11076] ,
       &Weights[11076] ,
      },
    { /* unit 372 (con25) */
1.41327, 0.500000, 2,
       &Sources[11078] ,
       &Weights[11078] ,
      },
    { /* unit 373 (con26) */
0.00228, 0.500000, 2,
       &Sources[11080] ,
       &Weights[11080] ,
      },
    { /* unit 374 (con27) */
1.06967, 0.500000, 2,
       &Sources[11082] ,
       &Weights[11082] ,
      },
    { /* unit 375 (con28) */
0.04991, 0.500000, 2,
       &Sources[11084] ,
       &Weights[11084] ,
      },
    { /* unit 376 (con29) */
0.35791, 0.500000, 2,
       &Sources[11086] ,
       &Weights[11086] ,
      },
    { /* unit 377 (con210) */
0.00000, 0.500000, 2,
       &Sources[11088] ,
       &Weights[11088] ,
      },
    { /* unit 378 (con211) */
1.24068, 0.500000, 2,
       &Sources[11090] ,
       &Weights[11090] ,
      },
    { /* unit 379 (con212) */
1.40837, 0.500000, 2,
       &Sources[11092] ,
       &Weights[11092] ,
      },
    { /* unit 380 (con213) */
0.12102, 0.500000, 2,
       &Sources[11094] ,
       &Weights[11094] ,
      },
    { /* unit 381 (con214) */
0.00264, 0.500000, 2,
       &Sources[11096] ,
       &Weights[11096] ,
      },
    { /* unit 382 (con215) */
0.06917, 0.500000, 2,
       &Sources[11098] ,
       &Weights[11098] ,
      },
    { /* unit 383 (con216) */
0.03332, 0.500000, 2,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 384 (con217) */
0.87738, 0.500000, 2,
       &Sources[11102] ,
       &Weights[11102] ,
      },
    { /* unit 385 (con218) */
0.23904, 0.500000, 2,
       &Sources[11104] ,
       &Weights[11104] ,
      },
    { /* unit 386 (con219) */
0.00705, 0.500000, 2,
       &Sources[11106] ,
       &Weights[11106] ,
      },
    { /* unit 387 (con220) */
1.37339, 0.500000, 2,
       &Sources[11108] ,
       &Weights[11108] ,
      },
    { /* unit 388 (con221) */
1.39157, 0.500000, 2,
       &Sources[11110] ,
       &Weights[11110] ,
      },
    { /* unit 389 (con222) */
0.03990, 0.500000, 2,
       &Sources[11112] ,
       &Weights[11112] ,
      },
    { /* unit 390 (con223) */
1.31023, 0.500000, 2,
       &Sources[11114] ,
       &Weights[11114] ,
      },
    { /* unit 391 (con224) */
0.09550, 0.500000, 2,
       &Sources[11116] ,
       &Weights[11116] ,
      },
    { /* unit 392 (con225) */
0.00101, 0.500000, 2,
       &Sources[11118] ,
       &Weights[11118] ,
      },
    { /* unit 393 (con226) */
0.08741, 0.500000, 2,
       &Sources[11120] ,
       &Weights[11120] ,
      },
    { /* unit 394 (con227) */
1.19360, 0.500000, 2,
       &Sources[11122] ,
       &Weights[11122] ,
      },
    { /* unit 395 (con228) */
1.42394, 0.500000, 2,
       &Sources[11124] ,
       &Weights[11124] ,
      },
    { /* unit 396 (con229) */
1.42830, 0.500000, 2,
       &Sources[11126] ,
       &Weights[11126] ,
      },
    { /* unit 397 (con230) */
0.20307, 0.500000, 2,
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
