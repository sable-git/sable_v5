/*********************************************************
  Pfam_elBP_1_new10new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:03:54 2004
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
  static UnitType Units[391];
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 331,
Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341,
Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349, Units + 350, Units + 351,
Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379, Units + 380,
Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389, Units + 390,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 270, Units + 331,
Units + 271, Units + 332,
Units + 272, Units + 333,
Units + 273, Units + 334,
Units + 274, Units + 335,
Units + 275, Units + 336,
Units + 276, Units + 337,
Units + 277, Units + 338,
Units + 278, Units + 339,
Units + 279, Units + 340,
Units + 280, Units + 341,
Units + 281, Units + 342,
Units + 282, Units + 343,
Units + 283, Units + 344,
Units + 284, Units + 345,
Units + 285, Units + 346,
Units + 286, Units + 347,
Units + 287, Units + 348,
Units + 288, Units + 349,
Units + 289, Units + 350,
Units + 290, Units + 351,
Units + 291, Units + 352,
Units + 292, Units + 353,
Units + 293, Units + 354,
Units + 294, Units + 355,
Units + 295, Units + 356,
Units + 296, Units + 357,
Units + 297, Units + 358,
Units + 298, Units + 359,
Units + 299, Units + 360,
Units + 300, Units + 361,
Units + 301, Units + 362,
Units + 302, Units + 363,
Units + 303, Units + 364,
Units + 304, Units + 365,
Units + 305, Units + 366,
Units + 306, Units + 367,
Units + 307, Units + 368,
Units + 308, Units + 369,
Units + 309, Units + 370,
Units + 310, Units + 371,
Units + 311, Units + 372,
Units + 312, Units + 373,
Units + 313, Units + 374,
Units + 314, Units + 375,
Units + 315, Units + 376,
Units + 316, Units + 377,
Units + 317, Units + 378,
Units + 318, Units + 379,
Units + 319, Units + 380,
Units + 320, Units + 381,
Units + 321, Units + 382,
Units + 322, Units + 383,
Units + 323, Units + 384,
Units + 324, Units + 385,
Units + 325, Units + 386,
Units + 326, Units + 387,
Units + 327, Units + 388,
Units + 328, Units + 389,
Units + 329, Units + 390,

  };

  /* Weigths definition section */
  static float Weights[] =  {
-1.961970, -1.041020, -0.286870, 0.983660, -1.066930, -1.842200, -0.115260, -0.660800, -0.410890, -2.242230,
0.832680, -1.405570, -0.559680, -0.188620, -0.216360, 0.476280, -1.059490, 0.824720, -0.901550, 0.663340,
-1.325090, -0.006510, -0.318310, 1.487580, -1.261060, 0.923620, -0.607980, 0.840440, 0.657990, -0.877900,
0.334340, 0.542730, 2.155280, -0.293670, 0.106210, -0.221010, 0.893020, -1.010900, -0.612260, -0.895720,
1.540480, 2.004560, -0.151110, 0.013940, -0.665510, -0.404150, 1.039670, 0.329420, -1.234860, -0.860680,
0.740070, 1.915630, -1.639570, 0.183330, 1.465810, 1.863250, -1.164110, 2.506740, 0.408220, 0.320400,
1.593310, -1.153530, 0.599050, 1.301900, 0.947520, 2.102730, 1.403780, -0.621970, -1.779110, -0.800500,
0.889140, -1.198130, 1.401050, -0.934530, 0.953300, 0.005430, -1.868650, 0.026720, -0.033400, -0.971170,
0.917280, -0.066160, 0.621840, -1.410820, -0.174060, 1.099590, -0.436050, 1.330620, -0.374710, 0.474720,
1.261320, 0.648080, 0.740800, 0.075380, -0.245320, -0.654560, -0.417730, 0.060460, 1.189100, -1.223700,
-0.588760, 1.588090, -2.243550, 2.945250, -0.002530, -0.380980, -0.878880, -0.577360, 0.489200, 1.003040,
0.542460, 0.384420, 0.037730, -0.560390, 1.378680, 1.231770, 1.939000, -0.440020, 0.731360, 1.877120,
-0.704430, 0.140480, -2.661040, -0.502850, -0.671370, 1.337290, -0.312250, -0.331440, -0.282240, 0.363360,
-0.077320, 0.068780, 0.024630, -0.806370, -1.306870, 1.122190, 2.379660, 0.472590, -1.330080, -0.803120,
0.044370, -0.291830, 0.969910, 0.034710, 0.665110, -0.984660, -0.277070, -0.399340, 1.277830, -0.598790,
-1.076530, -0.451340, 1.667220, -0.102930, 0.580190, 1.052200, 1.059120, -0.452950, -1.921610, -0.373260,
-0.633630, -0.651990, -0.359860, 0.250900, -0.032350, -0.001970, -2.416800, -0.693360, -0.638420, 0.275420,
0.575180, -0.639540, 1.225990, 0.543180, 0.201850, 0.602010, -1.956550, 0.477500, -1.869690, -0.846720,
-0.268770, -0.562680, -0.940030, -1.157450, 1.869620, 1.688040, -1.918800, 0.543740, 0.213610, -1.687970,
-1.217860, 1.049070, 0.421120, -0.250490, -0.055290, 0.126320, 2.253660, 1.645170, 0.901810, -1.344000,
3.357080, 1.493080, -0.627410, 0.944760, 0.497010, 1.139400, 0.363210, -1.879800, 1.379920, -0.337420,
1.661130, -1.039570, -1.706060, 0.226520, -0.317970, 1.945720, 0.864980, 0.542470, 0.751400, -0.519690,
0.132940, 1.541620, -0.244840, -0.294890, 0.086820, -0.373490, 1.220660, -0.029260, 0.351640, -0.620820,
-0.111750, 0.198950, 0.679660, -0.951320, 0.088280, 0.157100, 0.752370, -1.092040, -1.040600, -0.556300,
0.557970, -0.965980, -0.554730, 0.444060, 0.392880, -0.689230, -0.685220, 0.829080, 0.837470, 0.214100,
0.374970, 1.025920, -0.616320, -0.547630, 1.429790, -1.062070, 0.710870, 0.842210, -0.694210, -1.187270,
-0.647960, -0.921410, 1.402720, 0.171720, 1.592990, 2.542010, 0.416880, -0.437800, 0.684640, -0.086020,
-0.094080, 1.287240, 1.574030, -2.487420, -1.022130, 0.269050, 0.311180, 0.010810, -2.740880, 0.215090,
1.103490, -1.792190, -0.090190, -1.416410, -0.682150, 0.138670, 1.216090, -0.104750, 0.916830, -0.156090,
-1.131280, 0.680630, 0.070150, 0.163770, -0.998750, -0.130780, 1.121280, 1.235090, -0.237840,
1.166640, 1.021930, -0.203360, -1.367740, 1.315820, -0.041270, -0.757860, -0.622140, 0.634210, -1.024460,
1.452180, -0.732270, 1.368610, 1.987390, -1.687230, 0.895340, 0.372250, -1.164440, -0.965120, 2.222780,
1.380440, 0.747110, -0.836190, -0.824010, 0.084890, -0.327540, 0.053230, 1.639660, 1.962260, 1.014630,
-0.069420, -0.577670, 2.134540, 0.993660, 0.899920, -0.136040, 0.282310, 0.186610, -0.006360, -1.022690,
-2.797580, 0.261080, 1.026300, 0.947250, -1.623580, -1.547600, -0.701710, 0.257680, -0.732830, 1.293830,
-0.740110, -1.160160, -1.956780, -0.240540, 1.490680, 0.261350, 0.467090, 0.654090, -0.806930, 0.851380,
0.561700, 1.338000, 1.011580, -0.854700, 0.020670, -0.770820, -0.470380, -0.314440, 0.047020, -2.063500,
-0.093830, -0.997320, -0.314420, 0.815820, 1.273650, 0.133850, -0.958430, 0.977580, 0.357800, -1.465480,
-0.367460, -0.638750, 0.545630, 0.160240, 0.484040, 1.148530, 0.011320, -0.026540, -0.438800, 0.621450,
-0.203250, 0.262120, -1.447460, 1.291840, -0.995540, -0.231260, 1.194450, -1.415490, 0.225180, -1.653730,
1.071130, 0.392530, 1.141690, -0.854980, 0.343530, 0.268230, 0.477650, -0.493820, 0.862050, -1.334590,
0.356940, -0.258870, 0.373030, 0.026740, -1.006480, 0.369100, -1.393580, -0.526080, 1.375720, -2.148120,
0.488860, 0.096130, 0.284560, -0.057110, -2.410690, 1.306250, -0.225130, -0.750720, 0.752140, -1.016060,
-1.214390, 1.998090, -0.727040, 0.083050, 0.326330, -4.617230, -2.329690, -0.298620, -0.150970, -1.018400,
-1.292480, -1.989160, -1.095670, -0.635900, 0.998120, -0.158960, 1.688270, 1.952430, 1.523920, 0.629890,
0.439910, 0.194250, -0.407060, 0.073930, -0.002940, -0.919620, 0.778460, -0.085540, -0.703600, -0.688050,
-0.970210, -1.553580, -2.566110, -0.829380, 1.023930, -0.669150, 0.851810, -0.629300, -0.216540, 0.324290,
-0.797610, -0.472270, -1.188420, -1.867120, 1.116630, -1.956670, 2.397950, 0.939130, -0.164640, 0.390040,
0.613080, 1.086780, -0.793230, -0.146250, 0.472550, -1.504040, 0.167210, 0.382800, 1.394070, -1.127990,
1.220130, -0.410120, -0.398850, 0.591870, 0.501840, 1.524090, 0.389410, -0.514670, 1.674660, -1.315680,
-0.273580, -0.907520, -0.467810, 1.057780, 0.935390, -0.253270, 0.499690, -0.677720, 0.141420, 0.760690,
-0.264770, 0.252460, -1.342410, 1.921740, -0.279510, -0.613540, -1.914860, -0.731760, -1.016300, -0.860660,
1.405300, -0.940600, 0.558280, 0.683340, -0.499250, 0.884080, 0.137480, -0.876750, -0.278460, -0.329440,
1.464670, -0.070110, -1.161180, 0.150790, 0.634720, -0.187940, 0.825430, 0.243790, -1.255020, 2.073490,
0.026170, 0.225230, -1.394350, 0.462970, 1.432600, -0.666360, -0.493450, -0.710930, -0.230500, -0.962700,
2.356280, -0.720830, 1.647150, -0.189480, 0.434030, -1.829290, 0.220790, 1.655610, -0.446460, -0.083490,
0.596140, 0.923250, 1.019490, -0.062340, -0.666690, 1.829130, -0.713010, -0.375910, -1.109570, -1.524090,
1.285930, 0.381500, 0.043040, -1.583970, -1.518150, -1.571430, 1.353850, 0.562000, 0.344960, -1.603990,
-0.674740, -0.796610, 0.271060, 1.158180, -0.048200, 0.364630, 0.674110, -2.291000, 1.442900, -0.784810,
-0.144210, 1.014960, 1.397940, 0.155910, 0.728080, -0.733080, -0.080950, 0.534680, -1.460690,
0.404260, 1.086470, 1.180020, -1.042750, 0.289600, -0.543020, 0.873950, -1.329450, 2.349840, 0.349710,
-0.491950, 0.988700, 0.376550, -0.846160, 0.359550, -1.173090, -0.712170, 0.954020, -0.030830, -0.064150,
1.797970, -0.519700, -0.940510, -0.113410, 0.052860, 0.115270, -0.466400, -0.112370, 1.331500, 0.344360,
1.103740, 0.758420, 0.169170, -0.148260, -1.817840, -0.425770, -0.978520, 1.566960, -1.702230, 1.031640,
0.183210, -2.051810, -0.962620, 1.438250, -0.035230, 1.795560, 0.076110, -1.017080, 0.159550, -0.799050,
0.638800, 0.146210, 0.348310, 0.866750, -1.989300, 0.280120, 1.254130, 0.396460, -2.096600, 0.026330,
0.565240, 0.265350, -0.080280, 0.464450, -0.437290, -0.632900, -1.819690, 0.734750, -0.362180, -0.386010,
-0.599210, 0.253500, -0.952200, 0.497160, 1.744110, 0.100990, -0.468640, -0.911050, 0.261610, -0.686410,
0.719340, 0.602550, -0.074550, -0.782640, -0.522520, -0.077010, -1.236790, 1.920200, -0.921770, -0.331890,
0.426850, -0.544290, -0.826970, -1.264570, -2.524520, 0.549660, 0.289520, 0.540680, 2.551210, -1.029570,
0.777030, 0.620510, 0.114030, -0.039170, 0.143760, -1.426690, 1.142300, -0.755950, -1.144660, 2.989260,
0.751300, 0.818890, -0.697900, 1.396780, 0.756350, -0.553470, 0.203810, -0.004200, 1.255860, 0.658170,
0.796780, 1.242560, -0.239820, -1.265110, 0.424030, 0.874870, -0.810470, -0.241180, 3.148010, -0.072360,
-1.013600, -0.447790, -0.316780, -3.999100, -0.575330, 1.977750, 0.080620, -1.572210, -0.916040, -1.395930,
-0.532130, -1.842850, -0.678370, 0.492340, 0.780050, -0.240160, -0.821530, 0.203320, 0.045880, -0.762900,
0.563010, -0.999230, -0.380050, 2.389230, -1.162680, 0.426510, 1.433890, 0.902730, 0.427040, 2.376030,
0.399960, 0.045760, -0.261550, 0.527050, 2.046960, 2.155410, 0.106400, 1.602750, -1.215910, 1.684820,
0.186170, -0.053550, -0.153850, -2.333480, -0.023550, -0.286950, 0.023090, 0.590520, 0.951080, -0.761680,
0.715610, -0.241160, 1.226130, -0.324820, 0.448660, 0.307580, 0.846340, 0.664240, -0.407450, 0.421770,
-1.683070, 0.899100, 0.337430, 0.889500, -0.680860, 1.271570, -1.294730, -1.218480, 0.896700, -0.871160,
-0.840930, 1.210290, 0.386470, -2.161670, 0.864980, -0.588890, 0.388200, -0.459610, 2.201320, -0.068640,
0.666460, 1.202880, -1.261860, 0.287370, -0.169460, -1.075940, -0.898570, 0.673250, -1.444680, 0.349660,
0.611310, 0.017320, -0.303500, 0.432650, 1.321030, -2.337510, 0.974960, -1.080560, 1.502710, 0.473360,
-0.133770, 0.710820, -0.177350, -0.160000, -0.705130, 0.439730, -0.319090, -0.368040, -0.097270, -0.480040,
1.434720, -0.645690, 1.574550, -0.303660, 1.367130, -0.279630, 0.096430, -0.804160, -1.780110, -0.905940,
0.364730, -0.052800, 2.822010, 0.023690, 1.300510, 0.954130, 0.910460, 0.343740, -0.016380, 1.762700,
-0.785730, -1.671160, -3.210370, -0.256120, 1.729060, 1.394680, -0.698900, -0.513080, 0.642160, -0.136910,
1.586960, 0.490500, 0.301520, -0.357400, 0.397890, -0.180040, -2.364370, 1.180170, 0.011190, 0.165540,
1.347040, 0.035130, -0.449040, -0.343570, 1.179660, -0.553430, 1.557630, -0.994110, -0.983250, 0.636380,
0.487420, -0.227620, 0.347110, -0.458850, 0.080550, -0.766260, 0.334030, 1.288530, 0.034180,
2.727640, 0.606560, -0.080440, -0.935200, -0.107350, -2.594750, -0.065370, 1.438150, 1.007790, 1.015710,
1.341470, 1.026440, -1.161250, -0.098940, -0.250600, -2.431260, -0.239290, 0.093810, -0.357900, 0.588730,
0.151670, 1.309830, -0.386160, -1.930340, -1.943700, -0.839990, 0.384450, 1.330390, 0.677210, 1.161880,
0.355400, -0.061090, 0.469400, 1.060170, 2.009230, 0.631930, 1.194010, -0.160440, -0.600240, 0.218350,
1.276610, 0.887000, -0.941030, 0.632270, -0.720440, 0.894990, -1.381680, -0.378360, 0.154820, -0.666470,
0.492410, -0.945480, 0.968310, 0.476490, -0.356990, 0.512420, 0.450100, -1.227200, 0.173090, 1.050900,
1.164120, 0.694930, -0.244230, 0.008460, -0.842160, 0.057880, -1.281160, 0.409310, 0.527390, -0.122630,
-0.623440, 0.132440, -0.460550, 0.466390, -0.015120, 0.397320, 0.243620, -2.918990, -1.242810, 0.132740,
0.202290, -2.631440, 0.495880, -0.929610, 0.919990, 0.451600, -0.950410, 0.830720, -0.011850, -0.738040,
0.038940, 0.661430, 0.180910, -0.329680, -2.687800, -0.250430, -0.225420, 1.147550, 0.977300, -0.370630,
-0.169050, -0.670370, -0.845860, -0.589830, 1.114860, 0.479490, -0.376010, 0.186630, 0.220410, 0.931570,
0.096940, -0.893990, -2.200430, -0.888420, 1.435620, -2.231780, -2.074500, 1.367620, 0.056740, 1.779650,
-1.763640, -0.145130, 0.520860, -0.873370, -0.503380, 1.538310, -0.776010, 0.647540, -2.008670, 0.339040,
0.878510, 1.100660, -0.850550, 1.116350, -0.931750, -1.454420, -1.010960, 2.014380, 0.318300, 2.282130,
1.074390, 0.981450, -0.806280, -1.390260, -2.501690, 0.582100, -1.158850, -0.719250, -1.350020, -0.761590,
-0.134560, -1.255180, -0.082800, -0.746520, 0.025070, -2.288450, -0.481340, -0.962430, 0.003970, -1.133950,
1.844650, -0.532790, -0.954590, 0.056600, -0.920400, 0.441350, 1.741890, 0.416000, -0.964140, 0.834120,
-1.065530, -1.188250, -1.511260, -0.200050, -1.163000, 1.245730, 1.547370, -1.339820, -0.733260, -1.037660,
-0.162450, -0.571700, -1.070620, -0.646420, -1.464310, -0.741970, 1.491410, -1.629350, -0.095980, 0.915840,
0.231280, -0.317770, 0.486140, 0.854230, -1.484460, 0.268700, -1.570100, 0.305590, -0.674570, -1.442230,
-3.732450, 0.639070, -0.750430, -0.851640, 0.314420, -0.858310, -1.153970, 2.018510, 0.286730, 0.997090,
-0.284240, -1.148140, -0.650290, 0.874670, -1.061470, -0.860110, -0.416320, 0.566530, -1.106490, 1.066410,
1.686730, 1.932850, -1.698180, -0.119180, 1.054630, -0.193120, 2.338070, -1.094350, -0.286740, -0.074570,
0.922260, 0.035740, 0.716750, -0.246850, 0.685510, 0.735570, 0.994060, -0.695630, 1.279160, -1.364220,
-1.340820, 1.926960, -0.174580, 1.369960, -0.376480, -0.072920, 0.034100, -1.914100, 0.685280, 0.450680,
-1.075560, -0.177500, -0.963600, -0.014860, -0.188140, 1.612670, -0.427380, 1.598200, 0.374620, 0.194580,
1.462330, 0.045550, 0.080530, -1.372640, 0.701510, 3.886420, -0.283430, -0.602260, -0.111520, 0.690330,
2.303370, -0.128490, -0.174530, 1.242260, 1.804480, 0.063170, 0.433390, -0.766070, -0.645880, -0.050720,
0.045150, -0.730290, -0.465130, -0.403800, -1.711170, -1.907930, 0.882040, 0.775160, 1.210720, -0.443740,
0.208920, -0.110630, 0.778220, 0.152310, 0.256610, 0.747670, -0.621150, 0.709080, 0.481210,
0.581310, -1.254110, 0.764320, 0.965190, -0.130720, -1.309810, -0.761010, -0.338090, 2.631330, -1.582490,
-0.395600, -0.520410, -1.399050, -0.648090, -0.005950, -0.519520, 1.414920, 0.838170, 1.088950, 0.020530,
0.024220, 0.718000, 0.000420, 0.656450, 0.099000, 0.772390, 2.218270, 0.143290, -1.213680, 1.280330,
-0.929960, 0.773230, -0.441830, -0.183540, -0.072530, -0.344060, 0.005090, 0.457160, 2.806570, -0.331320,
1.090870, 1.570710, 0.238110, -0.276300, 1.014280, 0.954700, 1.587950, -0.937470, 1.384230, -0.219510,
0.231650, 0.188800, 1.119140, 0.366460, -0.102260, 0.749140, -0.520900, -0.108810, -0.739620, 0.597000,
-0.306460, -1.196790, 2.542460, -0.336600, -0.170220, 2.792330, 0.715910, -0.148460, 1.680530, 1.271850,
0.196260, 1.822450, -2.023160, -1.885870, 0.461900, -1.291710, -1.487210, 2.007550, 0.549180, 0.529590,
-0.736710, -1.578140, 0.092990, -0.646000, 0.449920, -0.361390, -1.386420, 0.553810, 0.095930, 0.823230,
-1.409750, 0.374870, 1.340820, -1.657130, 1.280500, -1.081560, 0.215550, 1.441320, -0.985250, -1.657470,
0.230130, -0.526490, 0.047430, -0.733890, 0.087710, 0.753240, 1.390380, -0.129470, -0.956070, 0.558170,
-0.195740, -0.041870, 0.460570, 0.642060, 1.390680, -0.601290, -0.404110, 0.913400, 0.166190, 0.872030,
0.542340, 0.287160, -0.389730, -0.339460, -0.151610, -0.293500, 0.548350, -1.867490, 0.221810, 0.462560,
1.442350, -0.997010, -2.936410, 0.309840, 0.217810, -1.784170, -1.437960, 0.538790, 0.089690, -0.773850,
1.322130, 1.407760, 0.908640, 0.940560, -1.337810, -0.219440, -0.034580, 2.102550, 1.259740, -0.735940,
0.277290, -3.253370, -0.541650, -0.221980, 0.473040, 1.518850, -0.680270, -0.716670, 0.283330, 3.216230,
2.023030, -0.743260, -2.084240, -1.897310, -1.515420, 0.453960, 1.795310, -0.272950, -1.299910, 1.654750,
2.184560, 1.046230, 0.226170, 0.209460, -0.841570, -0.161640, 0.313130, 2.559630, 0.244280, 2.581890,
1.269430, -0.745290, 0.464590, 2.350530, 0.112760, 0.719190, 1.565040, 0.208730, 0.174000, 0.082030,
-1.098240, -0.203090, -0.887970, 0.458800, 0.372110, -0.869410, -0.703800, 0.018350, -0.403010, -2.158280,
1.431300, -0.085130, -1.172230, -0.611260, -1.396390, -0.004690, 0.881410, -2.562020, 0.169230, -0.831330,
-0.151970, 0.596010, 1.135200, -0.895760, -1.986700, -0.350800, 0.782150, 1.249010, 0.030210, -0.283300,
0.530130, 1.161880, -2.212220, 0.583090, -0.951520, -1.076940, -2.005490, 2.544050, 1.538180, 1.071930,
-0.198330, 0.521060, 0.070770, 2.144390, 0.979090, -2.622650, -0.396040, -0.285850, -1.210170, -0.585750,
-0.099440, 0.326830, -0.578220, -0.748070, -0.826070, -0.882280, 1.070600, 0.903760, 0.405640, 0.622120,
-0.875820, 0.464550, 0.286410, -0.904260, 0.056500, -1.541940, 0.011800, -1.151650, -0.424950, -0.478460,
0.677760, -1.787630, 2.395910, 1.544450, -0.571330, 2.395030, 0.207970, -0.896120, 0.082180, 0.266320,
1.634300, 1.791890, 0.007030, 0.564670, 0.222710, 0.775670, 0.476820, -0.257580, 0.780550, 0.825140,
-0.673040, -1.099290, 0.125160, -1.452780, 0.963970, 0.935430, 1.297590, 2.732330, 0.336390, -0.256410,
2.166860, 0.012810, -1.040980, -0.298880, 0.740230, 1.315930, -1.039340, 1.055950, 0.312460,
0.680650, 0.666200, -0.875470, 0.593580, 0.875320, -0.445550, 0.769770, -0.394930, -0.040370, -0.364600,
1.599260, 0.826140, -0.075380, -0.212560, 0.451440, 0.190080, 0.053490, -0.147820, 0.117280, -2.084940,
-0.343990, -0.789400, -0.196240, -0.624290, -1.139220, 0.133600, 0.305570, -0.792710, 0.790500, -0.122090,
-0.835080, -0.022360, 0.837630, 1.166570, -0.461900, -0.703530, 0.314710, -0.153310, 0.389560, 1.548690,
0.920740, -3.140490, -0.167240, 2.075290, -0.111340, 0.633180, 0.605000, 1.184800, 0.679240, -0.172430,
-1.267610, 0.882740, -0.070040, 0.499390, 0.356670, -0.052790, 0.351290, -0.129040, -0.090590, 0.776970,
0.406450, -0.175250, 0.004690, 0.848870, -0.122670, 0.694960, -1.781520, 0.079510, 0.432530, 0.888380,
0.675340, -0.166100, -0.295330, 0.673020, 0.053520, 0.631670, 0.018980, 1.755530, -1.908070, 0.424290,
0.653020, 1.063970, 0.399710, -0.040790, -0.562630, -0.825770, 0.083440, -0.156760, -0.235840, -0.732670,
-0.026540, 1.481870, -0.923980, -0.516360, 0.367060, -0.158560, 1.144840, 0.454000, 0.282670, -0.591900,
0.847270, 1.357610, 0.483440, -1.504990, 1.060840, -1.166220, -0.237640, 1.269030, 0.985070, 1.178620,
-0.338330, 0.047820, -3.164430, -0.693750, -0.019730, 1.247730, 3.139510, -0.253820, 1.283930, 2.824980,
2.155570, -2.063450, 1.399690, 2.602210, 4.234920, -0.941780, 1.116320, -1.933580, -1.973050, 0.307970,
-2.749150, -0.794440, 2.883130, 1.399510, -0.430560, 8.245240, 1.124840, 2.041030, 0.380700, -0.100560,
0.123260, -0.374520, 0.002520, 0.534000, -0.642760, -0.005050, -0.185280, 0.341030, -0.551140, 0.560270,
-1.006240, -0.876540, 0.966180, 0.549830, 0.501750, 0.123120, -0.417900, -0.292790, 1.635170, -0.417750,
-0.653670, -0.684650, -1.432820, 1.662000, 0.549190, -1.022790, -0.369100, 0.044770, -1.030380, 1.473660,
0.721780, 1.018730, -1.300410, -0.734940, 1.451240, 0.131470, -0.195450, -1.031300, -0.133000, 0.575810,
-0.855780, -1.923140, 1.475610, 1.102990, 0.393390, 0.000820, 1.637800, -0.274920, 0.875830, -1.709160,
0.817390, -0.401060, 0.303830, 1.361470, 0.911440, 0.250490, -0.376600, -0.276220, -0.122670, 0.273160,
-0.575220, 1.709490, -0.989780, -0.244120, -0.493560, 1.095290, -1.540400, 1.166030, -0.339110, -0.604450,
0.396000, 0.643240, -0.943880, -0.875850, 0.514220, 0.924500, 0.228850, -1.456400, -0.212780, 0.594750,
-0.647990, -0.647120, 0.388060, -0.141290, 0.508970, 0.269540, -0.247280, -1.724570, 0.809800, -1.633340,
-0.440480, 0.807330, 0.677900, 0.030860, -0.763880, 0.551310, -0.101640, 1.095850, -0.774420, 1.168440,
0.947990, -0.354390, -1.198620, 0.627190, -0.294470, 2.256130, -0.032620, 1.848520, 0.984520, -1.228820,
-2.700270, 0.235820, -0.100460, -0.324730, 0.374270, -0.299550, 0.707290, 0.009560, -0.637510, -7.015820,
-0.092640, -0.645210, -1.875260, -0.921330, 1.735210, 0.034880, 0.227250, 0.332820, 1.391240, -0.314590,
-0.265220, -1.344910, -0.936640, -0.907740, -1.424630, -1.556900, 0.269600, -1.479110, -1.554090, 1.069490,
-0.224870, -0.858140, -0.201710, 0.968330, 0.258920, -1.269010, -0.913850, -0.823370, 0.113290, -0.503340,
0.550720, -0.417070, -1.248740, 0.672110, -1.265860, -1.223160, -0.295200, -0.192090, -2.644030,
0.502700, -0.573000, 1.575170, -0.488240, -1.454800, 1.138760, -0.990190, -1.081010, -0.178340, -0.466020,
-0.573350, 1.245480, -1.811360, 0.750830, -0.652760, -0.712460, 0.635230, -0.234910, 0.594640, -0.808630,
-0.684300, 0.563280, 0.583720, -1.148350, -1.057290, 1.319750, -0.804810, -1.043020, 1.285910, 0.055720,
-0.749700, 0.925040, 1.107900, 0.289880, -0.339380, 0.102300, 0.109700, -0.449250, -0.053920, -0.915770,
0.229320, 0.133690, 0.243730, 0.622700, -0.548390, 0.189710, -0.560410, -0.259180, 2.351120, -0.004880,
1.471640, 0.904750, -1.086900, -0.027990, 1.546420, 0.375310, 0.200700, 0.001660, -1.616960, 0.067980,
-0.704590, -1.012680, -0.092040, 0.912110, 0.142490, 1.059410, 1.541170, 0.168860, 0.861270, -1.662870,
0.362580, 1.209020, 2.426620, -1.353040, 0.752980, 0.758950, 1.631990, -1.617930, -0.868230, 0.406070,
-0.226420, -0.697390, 1.252190, 0.283530, -0.600650, 0.337750, 0.081290, 0.126290, 1.460740, -1.835150,
-0.566390, 2.344350, 0.091360, 0.978740, 1.306730, 1.501110, 1.260170, 0.397470, 0.849310, 0.024420,
-1.284270, -2.186920, -0.349900, 0.578120, -1.482850, 0.971190, -1.388750, 0.700260, -1.255440, -1.891140,
1.689780, -0.342110, -0.473220, -0.167190, 1.407310, 2.177840, 2.886750, 0.390280, -1.852190, 1.391990,
0.354550, -0.970410, 0.583600, 1.205830, 0.382130, 0.433210, -0.356350, -1.614740, 2.278870, -0.762990,
-0.032450, 0.644740, 2.506750, 0.554580, 0.223260, 1.616530, 0.061160, -1.396160, 0.871170, 1.769670,
-1.153720, 0.903570, -2.019310, -0.317690, -0.381860, -1.346110, 1.230610, 0.518440, 2.374570, 0.099770,
1.407560, 1.780770, 0.136660, 1.190130, -0.477970, 1.199610, 0.546680, 0.957690, 0.670500, 0.202940,
2.197460, -0.194240, 0.860400, -2.034080, 0.887480, -0.697820, -1.288860, 0.354450, 2.596590, 1.133980,
-0.730210, -0.182070, -0.407830, -0.772230, 0.925370, 0.242850, 1.637110, -1.450990, 0.077230, -1.260720,
0.987430, -0.385810, -0.676040, 1.233910, 1.385270, 1.053290, 1.102410, 0.342420, -0.787170, -0.701450,
-0.600120, 0.675310, 1.364680, -0.620510, 0.641260, -0.615230, 0.458130, -0.315220, -0.552260, 0.323070,
0.503230, 0.807090, 0.297910, -0.095180, -1.237680, -0.421320, 0.951220, 1.479460, 0.652820, 1.049070,
0.977730, -1.271200, 0.378350, -0.425380, 0.869760, -0.085110, 1.689160, 0.233900, 0.660480, 0.362700,
-0.583440, 0.872010, 0.400080, 1.303350, -0.509550, 2.934200, 0.740640, 0.741210, -0.822630, -1.041360,
-0.302040, 1.808620, -0.258020, 0.026340, -2.254630, 0.341220, 0.389850, -1.114980, 0.561700, 0.647880,
0.010310, 0.450310, -1.008570, -1.348230, 0.742470, 0.046720, 0.682580, -0.373810, 0.194250, 1.333320,
1.769160, 0.537900, -0.485520, 0.362180, -0.317310, -0.559220, 0.251350, -0.204520, 0.024180, 0.984310,
-0.474180, -0.148670, -0.812340, -1.145940, 1.037120, 0.210580, -1.468180, 0.576860, -0.381250, 0.794560,
-1.349500, 0.119410, -0.617110, -0.173200, -1.519130, 1.209130, -0.078300, 0.478340, -0.904830, 0.241180,
-1.808890, -2.101440, 0.820710, -0.001930, -1.238410, -0.547380, -0.108480, 0.558150, -0.130730, -0.452910,
0.211880, -1.193850, -1.004750, -0.108520, -1.322420, -0.409500, -0.507980, -0.709690, 1.531900,
-0.095790, 1.047940, 0.625300, -0.331080, -0.998600, 1.393690, -0.236360, -0.197500, 0.541010, 0.716940,
0.720200, 0.694210, -0.550830, -0.290940, 0.151420, 0.841460, -0.617330, 0.070240, -2.119710, -0.203900,
-0.102410, -2.243310, 0.162720, 0.488620, -2.407920, -1.135880, -1.883480, 0.930670, 0.442680, -0.351240,
0.479710, 1.612780, 0.466300, -1.493220, 0.426110, 0.950120, 2.256000, 0.565380, -0.162450, -2.314030,
2.107600, -1.201050, 0.754180, 1.438680, -1.232240, 0.090740, 0.718510, -0.322350, -1.038300, -2.082850,
-0.151850, 0.615950, 0.434040, 0.559750, -0.654490, -0.548560, -0.417680, -1.366540, -0.107310, -0.603090,
-0.198750, 0.002940, -0.662540, -1.082020, -1.578480, -2.159650, 0.434840, -1.211750, 0.244500, -0.831620,
0.479790, -0.581650, 0.979880, 0.362120, -0.169610, 0.324500, -0.615470, 2.211900, 1.426800, 0.531750,
-0.478610, -0.495980, -1.234760, 2.111300, 0.392840, 0.997710, 0.296290, -0.419100, 2.487290, 0.678950,
0.102660, -1.240260, -0.538330, -2.189950, -0.164440, -1.793160, -1.592830, -2.121980, -0.060380, -0.897100,
0.117310, 1.014410, -0.960690, -0.981550, 0.196770, -0.023960, 0.774350, -0.520780, -1.657670, 0.242180,
0.853160, -1.113340, 1.439360, 0.942400, -0.630450, 1.422580, -1.138080, 0.185140, 2.355980, 0.876650,
-1.824260, 1.725910, -1.560300, -1.161800, -3.097550, 1.557610, -0.445290, -0.645930, -0.867190, -1.276150,
-0.804420, 2.279560, -1.112050, 1.497860, 0.016990, -1.592590, 1.222180, 0.159790, -1.283410, 0.275800,
0.678990, 1.094380, 0.827980, 0.497450, 0.607810, -1.533170, -0.672120, -1.353820, 0.352280, -0.439350,
0.468340, -0.459910, -0.544430, 0.833970, 0.777240, 0.201810, 1.116770, 0.519550, 0.346330, -1.261050,
-1.176660, -0.092230, -1.232980, -0.928840, 0.414570, 1.270610, 0.348340, -1.224830, -1.299920, -1.596050,
0.427850, 1.043350, -0.828600, 0.564900, -1.351110, -3.266730, 0.619080, -0.917090, -0.155490, 0.786870,
1.239120, -2.365440, 0.134740, -0.761990, -0.451790, -1.133560, -0.243030, 1.891730, -0.330570, -0.767720,
-0.152110, 0.444900, 0.764230, -0.311530, -1.636110, 0.005370, 1.690870, 0.280930, 0.505500, 0.337460,
-0.044410, 0.331330, -0.420250, 0.097420, 0.448810, 0.996010, -0.546740, -0.281810, 0.498250, 2.380690,
-0.573710, -0.254830, 0.915700, -1.231720, -0.200610, -1.591350, 0.104220, 1.252490, 0.783000, -0.859220,
-0.839590, -0.326680, 1.744610, 1.190930, -0.632660, -0.031230, -0.046350, -0.051540, 1.207610, -0.260320,
-0.935250, -1.371970, -0.155190, 0.705470, 0.041650, -0.594230, 0.305100, 1.117140, -1.704620, 0.068410,
-0.128110, -1.631270, 0.585150, -2.913190, 0.786160, 0.696620, -0.387760, 0.941560, 0.046250, 0.253800,
0.337880, -2.020420, 0.070700, 0.811290, 0.052220, 0.928320, 0.241340, -0.309240, -0.595600, -0.358000,
0.351640, -1.116060, -0.183050, -0.426480, -0.484790, -0.531900, 0.320500, 1.456090, -1.175320, -0.357430,
-0.067460, 0.548320, -1.319920, 0.850590, 0.168050, 0.011470, 0.507350, -0.523750, 1.943030, -1.085610,
1.132970, 0.475730, 1.705180, -1.601370, -0.495010, -0.632120, -0.498920, -0.289350, -1.456000, -0.093920,
-1.184590, -0.281490, -0.084650, -0.316540, -0.222820, 0.606320, 0.179730, 1.123250, 0.743070,
0.324870, -0.877090, -0.610250, 1.009520, -1.561200, 1.023690, 0.241230, -0.122420, -0.950510, 1.748880,
-0.415220, -0.168730, 1.532710, -0.703350, -0.573310, 0.889440, 1.017660, -0.407810, 1.531460, -0.325550,
1.681940, -0.992290, 0.348580, 0.893760, 0.333080, 0.374830, 1.799400, -0.963680, 0.446220, 0.539140,
0.516190, 1.262050, -3.043570, 0.689430, 0.903760, 0.103160, 1.457580, -0.535570, 1.063510, 1.561260,
-1.410430, -0.279720, 0.064630, -0.112740, 0.796680, 0.504170, 0.222520, -1.003950, 1.770290, -0.885300,
0.966670, 0.536240, 0.431710, -1.670300, -0.224410, 0.368000, 0.681220, 0.210340, 0.072520, -1.611930,
1.268610, -0.316880, 0.759720, -0.382960, 0.539220, -1.104270, -0.473260, 0.891330, 0.195090, -0.424600,
-1.066550, -1.944340, 0.938290, 0.128470, 0.155680, -0.931180, -0.167390, -0.820860, 0.183970, 0.353210,
2.429230, -0.308910, 0.741210, -0.190650, -1.286270, 1.008140, 0.898440, 0.369790, -1.714050, 1.185430,
0.973730, 0.100740, -1.131190, -2.110030, -1.640320, -0.835000, 0.146660, 0.496560, 0.730280, 1.360930,
0.287200, -1.334700, -1.047160, 0.373250, 1.442080, 1.476330, 1.393960, -1.444180, -2.345010, 0.779820,
-0.734240, -1.053140, -0.048930, -0.340280, 0.567760, -0.060480, 1.179880, -1.750720, 2.125320, 0.073900,
-1.078360, 1.389740, -0.013900, -1.745130, -1.011070, 0.830540, 2.044130, 2.227060, -1.656730, 0.028870,
0.464520, -1.021850, -0.509070, -1.155470, -0.927570, -2.010140, -1.284490, -0.837550, 0.806620, -1.682050,
-1.087240, -0.838870, 0.575210, 0.683380, -0.074560, -1.936120, -1.744220, -0.536490, -2.105520, 1.385120,
0.686050, -0.584830, 1.304500, -1.020010, -1.181690, 0.278640, -0.501470, 0.136270, 0.691570, -1.331310,
-1.002920, 0.112420, -0.074680, 0.523100, 0.257140, 1.156040, -0.017410, -0.506280, -2.203680, 1.102310,
2.439480, 0.047990, 0.278120, -0.034860, -0.919240, 0.044320, -1.599690, 0.093710, 0.487670, 0.674850,
1.106510, -0.598470, 0.590160, -1.114720, 0.678380, -1.722400, 0.086010, 0.697460, -0.477050, -1.708210,
2.173900, -1.644390, -0.400750, -1.263140, -0.236220, 0.024000, 1.194430, -1.594400, 0.228190, -0.038010,
0.954210, 0.412830, 0.037120, 0.158550, -0.069550, -1.147020, 0.782030, 0.639490, -1.180800, -1.315830,
-0.524160, -0.615100, -0.730840, 1.026760, -0.409870, 0.269190, -2.132040, -0.597970, -0.226330, 0.658490,
0.050660, -0.352370, -0.155340, 1.083510, 0.033460, 1.379340, 0.609010, 0.486080, 0.258490, -0.315070,
0.554610, 0.241050, -0.194990, 1.077020, -0.631280, -0.553960, -0.205170, -0.171320, 0.615620, 1.134840,
-0.300340, 0.076150, 0.755360, -0.139520, -1.152210, -0.450010, -0.901080, 0.988810, 0.284460, 0.950580,
0.660970, 0.458710, -0.468460, 0.794680, -0.824180, -0.522640, -0.559020, 1.303930, 0.269870, -2.997130,
0.598360, -1.477670, 0.864990, 1.249230, -2.513990, -0.920330, -0.585500, 0.481310, 1.390830, 0.414390,
1.578120, 0.384200, -0.998290, 0.573050, -0.396720, -1.231940, -0.738930, -0.656370, -0.295080, -0.169640,
0.749920, 1.732050, -0.448810, -1.372930, -0.363650, -0.063590, -0.666510, -0.785610, -0.890370, -0.685650,
-0.239390, -0.908020, 0.073380, -2.107080, 0.021450, 0.127380, -0.033680, -0.149190, -1.249410,
-0.345220, -0.295950, -1.648560, -0.799950, 0.977520, -0.268840, -0.399590, 0.312930, 1.886380, -0.470550,
0.619960, 0.856490, 0.631210, 0.997540, 0.277880, -1.587650, 0.419660, 0.681570, -0.877960, -1.742770,
0.803520, 0.406080, 0.310930, 1.165360, -2.166900, 0.339990, -0.448560, -0.951010, -0.573520, 1.129210,
0.222020, -0.494840, 1.821310, 0.124650, 1.481010, -0.791620, -0.731490, -0.404880, 1.331930, 0.410480,
-1.665860, -0.454080, 2.025740, 1.952780, 0.226530, -0.723150, 0.986100, 0.925030, -0.539150, 1.273170,
1.652220, -1.584360, 0.793020, -0.765140, 0.647510, -1.444720, 0.125280, -0.122180, 0.881070, 1.136490,
-1.917660, 1.819380, 0.175550, -1.424210, 0.562170, 0.325930, -0.057690, 1.488150, 1.376460, 1.532170,
1.150820, 1.235290, 0.106450, -0.764570, 0.676990, -0.478180, -0.106130, -0.796620, -0.834320, -2.039030,
-1.657230, 0.569880, 1.462530, 0.222110, 0.280810, 0.308340, -0.026060, 2.118420, -1.486550, -0.261280,
-0.164390, -0.305400, 0.252750, -3.083570, 1.414790, 0.822330, -0.494840, -0.162300, 0.331590, -0.859980,
-0.654690, 1.387770, -0.116010, 0.875140, -1.575760, -0.932210, 0.626460, -0.149080, 0.510950, 0.151600,
-0.518080, 0.211440, 0.921910, 0.898670, 0.309040, 0.233340, 0.110840, -0.224310, -0.091400, 1.334560,
0.282400, 0.059200, -0.737750, -0.442690, 0.149740, 0.601180, -1.818220, 0.913910, -0.465650, -0.539720,
1.341600, -1.263390, -2.696800, 0.815540, 1.271730, -2.548650, -0.016070, 0.382270, 0.513990, -2.439960,
0.998600, 0.478720, 0.763180, -1.478290, 0.532940, -1.885010, -0.275790, -0.950610, -1.325130, 2.764350,
-1.865200, 0.663370, -0.412930, -0.039630, 1.808630, -1.367560, -0.351760, 1.126080, -2.026060, 0.256490,
-0.779200, 1.012960, 0.169570, 1.088240, -0.690980, 0.793200, -0.060500, 0.360840, -0.951030, -0.244220,
0.732010, -0.279800, 0.381380, 0.215650, -0.624190, 0.936800, 0.349740, 1.078830, -0.747550, 0.498780,
-0.917030, -1.075000, 1.717940, 1.696380, 1.354330, -0.358930, 0.123860, -1.135700, 0.842850, 2.765590,
-0.807450, -0.218430, -1.355150, 0.171020, -0.953210, 1.149970, -0.544100, -1.003260, 0.706490, 0.522650,
-0.079150, -0.419550, 0.631210, -1.385730, 1.389380, -1.433930, 1.067120, 1.371900, 1.551650, -0.950640,
0.252120, 0.669130, -1.691650, 0.802190, -0.771840, -0.130060, 0.549600, 1.051290, -0.312940, -1.966010,
0.513440, 0.272660, 1.432200, 0.000680, 0.582140, 1.530900, 0.230540, -1.136350, -0.563660, -0.794140,
-0.055970, 0.157830, 0.196380, 0.084730, -0.415410, 0.441200, -0.639680, 0.170510, 0.530030, -0.791230,
1.416820, 1.091200, 1.959030, -0.218180, 0.388450, -1.477770, -0.645550, 0.180570, 1.876890, -1.920090,
0.205900, -0.063430, 0.449740, -0.640890, -0.519810, 2.602980, -0.227560, -1.817890, -1.143510, 2.024650,
-0.480830, 1.197410, 2.227790, 0.561570, -0.618170, 0.909580, -0.528990, -0.550400, -0.947250, -0.480330,
0.982740, -0.933620, -0.279850, 1.112700, -1.348510, 0.188020, -0.533800, -1.547630, -1.265310, 1.104190,
-0.168420, -1.229200, 0.182610, -0.862350, -0.678350, -1.472290, -0.923000, 1.392610, 0.393320, -1.145980,
0.171430, -0.432840, -1.477780, 0.610100, -0.355980, -0.162870, -0.876380, 0.797470, -0.252170,
0.989750, -0.299240, -0.051890, 1.930150, -1.289280, -0.949810, -0.812680, 0.665290, 1.064630, -0.914090,
-1.671500, -0.551070, 0.060380, -0.764690, -0.493240, 0.780510, -0.648760, -1.408060, 0.349360, -0.873200,
0.798150, -0.090930, 0.878050, 0.229180, 0.063550, -0.820370, 0.523680, -2.204970, -0.407950, -0.842380,
-0.869990, 1.802960, 0.100520, 0.568120, 0.814370, -1.428690, -0.115790, 1.039960, -1.124250, -0.180680,
1.249340, 0.374580, -0.980310, 1.864130, 1.546920, 0.975660, 0.371640, 0.395560, 0.312860, 0.272340,
0.064760, 1.945900, -0.861480, 1.398350, 0.898900, 1.551840, -1.010350, 0.135410, 1.187040, 1.598980,
-1.268030, -0.863020, -2.686750, -0.859200, -1.108880, 0.234580, 0.456050, -2.005570, 1.648230, 0.128930,
1.192280, -2.161900, -0.147000, 2.729610, 0.806120, -0.037990, -0.295390, -0.652670, 0.128460, 0.917590,
-1.056150, -0.537480, 1.372090, 1.203610, -1.450690, -0.050960, -0.926140, 0.543100, -0.766510, 0.093440,
-0.888140, 0.116760, 0.582070, 0.228830, -0.031510, -0.208180, 0.537760, 0.469950, 0.276360, 1.158010,
-0.948640, -0.449210, -1.146060, 0.093930, 0.170600, 0.612960, -0.142800, -1.654160, 0.963060, 0.107300,
-0.092890, -0.353050, 2.475770, 0.376260, -1.597860, -2.723980, -0.113140, 0.360850, 0.661750, -0.808210,
0.386270, 1.791480, -0.001190, -2.566550, -0.565920, -0.905980, 1.171420, -0.329670, -2.290400, 1.708550,
1.923250, -0.860860, -2.536910, 2.166960, -1.156300, -4.714860, -0.991580, 1.522220, 0.106860, 0.266390,
-1.476300, -0.054790, -1.877430, -0.707910, 0.861100, 0.913310, -1.030130, -0.907070, 0.724180, -1.389010,
-1.030270, 0.188040, 0.647370, 0.732420, -1.263960, -0.418380, 0.605350, -0.468810, -0.493880, -0.707580,
-0.116340, -1.221500, 0.711800, -0.438650, 1.593870, -0.731880, 0.127370, 1.141200, -1.038750, -2.325260,
-1.353480, 0.577400, -0.060710, -0.733170, -1.162170, 0.747570, 0.223980, 0.169440, 1.369670, -2.181570,
-1.240490, 0.849640, 0.715030, -0.353500, -0.422020, -0.404670, 0.721600, -0.719670, -3.395490, 0.655930,
-0.272260, 1.661680, 1.315990, -0.497180, 1.782500, -0.951970, -0.944280, -1.337200, -0.581660, -1.387860,
-0.323390, -0.291980, 0.523700, -1.341850, 0.514380, -0.200180, 0.605040, 0.316270, -0.013450, -0.654190,
0.412250, -0.806950, -0.110490, -0.440840, 0.945980, -0.780520, -1.224450, 0.786470, 0.214990, -0.544890,
-0.957680, 0.574100, -0.754710, -2.075250, -0.604090, 0.843310, 1.299340, -0.697220, 0.610900, 2.168540,
0.614830, -1.670510, -2.224560, 1.931840, -1.779770, 1.339710, -0.688410, -0.831150, 1.479800, 1.992160,
-1.611850, 0.569700, 0.656740, -2.205740, 0.121920, 0.748750, 1.730410, -0.832260, 0.131990, 0.195350,
1.269540, -0.849520, -0.607830, -0.913510, -0.796780, -0.497930, 1.622260, 0.017960, 0.122000, 0.416530,
-1.333540, -0.001550, 1.767600, 0.819520, -0.188260, -0.029250, 0.610350, -0.452730, -0.210810, 1.780540,
0.105730, 1.785450, -0.659780, -1.501700, -0.018220, 0.871160, -0.809760, 0.144000, -1.148220, -0.572790,
0.713790, 2.627080, -0.198150, 0.760220, -1.045160, -1.512310, 0.035830, 0.699730, -0.057520, -1.230320,
-0.778490, 1.315210, -0.491750, -0.869060, -0.803110, -0.635000, -0.490470, -0.661700, -0.925400,
1.877510, 0.367610, 0.506000, 0.820550, 0.102800, 1.075970, -1.017920, 0.879740, -0.971120, -1.151190,
0.265200, 0.255210, 1.742560, -2.408870, -2.079880, 0.401160, -0.318280, -0.174350, 0.778300, 1.089100,
0.328240, 0.648780, 0.714160, 0.762720, -1.123390, -0.306980, 1.203500, 0.584860, 1.827160, -0.669780,
1.726770, -1.142320, -0.035820, 0.313830, 0.423380, -0.250380, 0.280470, 0.172130, 0.330510, 0.486400,
0.735910, 0.315660, 0.485770, -0.625630, -0.581220, -0.072940, 0.031260, -0.587840, -0.308500, 0.025310,
0.040440, 0.895820, -0.550690, 0.785690, -2.020720, 0.152960, 1.137470, 0.210860, 0.243060, 0.825430,
1.515110, -1.545440, -0.588020, 0.943400, 0.882920, -0.767400, 1.683430, 1.657180, 1.090110, 1.294390,
-1.749470, -1.331600, -0.595990, -0.623710, 0.223820, -0.308070, -0.032540, -3.006420, -1.101150, -0.891850,
-0.733790, -0.294940, 1.026130, 0.301050, 1.390680, 1.761220, -0.961670, 0.597550, -0.886310, 1.026730,
0.117110, 0.595250, 2.267340, -1.037750, 0.586100, -1.507750, -0.999740, -0.059350, -0.144820, -1.094710,
-0.874640, 1.240550, 0.282040, -2.893040, -0.577380, 1.610670, 0.791850, 0.758300, -0.925430, 0.232480,
1.160320, -0.581330, 2.319120, 0.641830, 1.453980, -0.991870, 0.729820, -0.578360, -1.319560, 1.266860,
0.409900, 0.902140, 0.603680, -1.529340, -2.304950, 0.557980, 3.841600, -0.813150, -1.400890, -0.099770,
1.813610, 0.209400, -1.121830, -0.139250, -2.387190, -3.043960, -0.478760, 1.291490, 0.706050, 1.277920,
-0.853750, -0.775200, 0.644060, -0.375720, 0.648160, 1.955480, -1.212510, -1.573210, -1.543940, 1.453560,
-1.119330, 1.741790, -1.916830, 2.272200, 1.134140, -2.454670, -0.126010, 0.403220, -1.597460, -1.021680,
-1.158880, -0.321950, -0.356320, -1.344380, 1.260800, -0.948580, 2.072980, -0.306980, -1.505230, 1.397890,
1.039390, 0.491760, 1.177570, 0.641770, 1.507990, -1.011930, -0.966060, 1.394330, -0.031570, 0.850410,
0.134190, -0.408140, -0.934830, 1.565620, 0.864790, -2.604920, 0.089470, -0.311570, 0.088570, -0.338540,
1.682250, 1.976860, -0.795700, 1.342780, 0.667040, -1.359480, -0.495300, 0.090030, 1.315660, 0.789220,
-0.420920, -1.909960, 0.376090, 0.297430, 1.643910, -0.775790, 0.643090, -0.684500, 1.394700, -0.467050,
-1.203970, 1.599090, -0.712520, -1.152240, -0.780080, 1.129910, -0.642320, -1.451060, -2.681970, -1.391570,
-0.313040, 0.413160, 0.647230, -0.266890, -2.588280, 0.665810, -0.389490, -1.477830, 0.061830, -1.447870,
1.810300, 0.463140, -1.141400, 0.005120, 0.411980, -0.551380, 0.321790, -0.065360, 0.292210, 0.023680,
-0.011600, -1.051300, 0.455300, 0.563200, 0.080050, 0.829590, 0.458500, 0.451360, 1.623740, -1.561180,
1.555430, 0.804010, -1.079210, -0.237530, -0.245650, -0.656150, -1.335880, -0.936520, 0.764960, 0.738510,
1.018770, 0.176580, 0.408090, -0.810420, -0.740590, 0.374120, -0.840710, -0.099360, 1.544640, 0.860840,
0.455790, -0.231280, 0.245070, 0.069740, 0.456660, -0.033080, 1.543380, 0.180790, -0.244920, 0.323170,
0.756190, 0.262610, -0.051530, 2.715020, -0.491920, -1.841210, -2.277610, -0.068790, -1.308410, -0.256470,
1.185070, 1.000480, 0.073720, 0.266190, 1.177560, -0.164260, -1.557390, 0.293960, -0.327520,
2.324470, 0.263380, -1.648530, 1.823660, -0.158300, 0.830490, 1.327350, 1.659910, -0.219330, 0.400980,
-0.770030, -1.320590, 1.144720, 0.124460, -1.323960, 1.711840, -0.309770, 0.148690, 1.128720, -0.271240,
-2.134750, -0.105400, 1.954800, 0.268540, -1.401650, 0.543740, 1.742170, 0.815740, 0.751050, -0.027180,
0.045540, -0.442920, 0.810820, -0.090280, 0.518390, -0.558700, 0.656460, 2.455290, -0.230710, -0.972200,
1.565600, 2.202370, 0.790850, 0.427440, 0.011110, -1.026490, -0.760140, -1.402870, -0.229640, 1.330870,
0.454200, 1.180150, -0.383420, -0.387950, 0.817810, 1.001430, 0.109650, -0.220950, -0.278860, -0.837450,
-1.237560, 1.446720, -0.426250, -0.480390, 0.410310, -0.962220, 0.504100, -0.917910, 2.236180, 0.879640,
-0.935880, -0.572990, 0.524560, -0.725200, -0.394130, -0.149650, -1.200530, -0.638390, 0.905510, 0.815850,
-1.667150, 0.982680, 0.346830, -1.337750, 0.220560, 0.687220, 0.887610, 0.342540, 0.155060, 1.024460,
-0.809790, 2.793280, 1.861810, -2.077360, 0.306380, 0.704200, 1.913690, -0.056040, -0.239240, -1.271660,
0.677790, -1.102460, 0.316390, 0.060840, -1.574990, 1.480320, 0.788800, 0.540680, 0.750300, 0.728780,
1.289620, 0.419110, 1.342320, -0.329950, -2.088600, 1.711980, 0.765130, 0.697400, 0.466320, -0.089900,
0.340720, -0.924170, -1.497340, 2.912690, 2.086530, -1.556150, -0.948420, -2.073170, 1.834910, -0.698720,
-2.647260, -0.027170, 2.949120, -1.511520, -0.533020, 2.645110, -0.179210, -2.762530, 0.871160, -2.605620,
0.872410, -1.366430, -0.140100, -1.116480, 1.374310, -0.763070, 1.540610, -1.271440, -0.099740, -0.020930,
-1.424350, 1.675820, 1.462090, 0.611870, -0.552220, 0.332130, 1.129240, 0.231650, 1.641090, 0.741700,
-0.341510, -0.051710, -0.454800, -0.668600, 0.066920, 1.398450, 1.174270, 0.620940, 1.261560, -0.216150,
0.132750, -1.896320, -0.554200, 1.574920, -2.558580, -0.764000, -1.130410, 0.573930, 0.725710, -1.250460,
0.452240, 0.313990, -0.093780, -0.594110, 0.232870, 0.646150, 1.121230, 0.679620, 2.381440, -0.710780,
-0.266020, -1.003150, -0.446460, 0.604830, 2.022210, -0.423740, -0.636630, -0.351680, 1.180240, -0.307220,
1.878780, 0.601180, -0.920500, -0.008120, -0.262520, -1.537260, -1.675640, -1.518220, -0.559970, 2.244230,
0.815630, -0.088400, 1.393040, -1.123440, -1.176890, 0.682040, -0.390130, 1.770430, 1.938800, -1.056620,
-0.778790, 0.381020, -0.469450, 0.136190, 0.117610, -0.880140, 1.925250, 1.580470, -1.272900, 0.925620,
-0.054790, 0.428140, 0.709750, 1.357060, 0.318300, -0.519550, -1.967080, 1.116320, 0.552060, 0.028350,
0.991090, 0.647540, 0.574880, 0.341190, -1.242470, 1.132660, 0.188910, 0.518120, 1.519030, 0.787120,
-3.288540, 0.174020, 0.326350, -1.397880, -0.385980, 2.250060, -1.432700, 0.363420, 1.084710, -2.429510,
1.385810, -0.796430, -2.880750, -2.613550, 0.193980, -1.959270, 0.653820, 1.139890, 0.691310, -1.402270,
-0.060560, -1.186330, -0.614870, -1.556110, -1.074540, 0.849090, -2.714870, -0.088710, 0.759280, -0.340440,
-0.181180, -0.526120, -0.769450, -1.524940, 1.147100, -0.965740, 0.403800, -0.874650, -0.444290, -2.077960,
0.224480, 0.287930, 0.271420, -2.438330, -0.493920, -0.589980, -0.226980, 0.099820, -0.905050,
-0.728460, 0.159640, -0.311200, 0.791160, -0.117320, -1.580330, 0.687850, -2.391260, 1.847100, -0.402870,
-0.248180, 0.479850, -1.005280, 1.157710, 1.735790, -1.069730, 0.284050, -1.017100, 1.122450, -1.700840,
1.703630, 0.468670, 0.511660, 0.016810, -0.802920, 0.808490, -1.156720, -0.096230, 0.181770, 0.158170,
0.980240, 0.137170, -0.739510, -0.671940, -0.084110, -0.668180, -1.067580, -0.000460, 0.750680, -0.101220,
0.143400, -0.475060, -0.853980, 1.524710, 0.739240, 0.064890, -1.435100, 0.264550, 0.515030, -0.291340,
-0.999920, -0.462120, 0.644990, 0.439890, 2.534800, -0.078260, 1.432550, -0.212390, -0.082350, -1.840210,
0.768870, 0.020710, 1.213590, 0.139940, 1.028920, -0.778280, -0.720400, 1.167190, 1.261380, -0.858920,
-0.243550, 1.202090, -0.290630, 0.421130, 0.579410, -0.910270, 1.649830, -1.255570, -0.149560, -1.932880,
-0.181380, 0.628050, 0.796290, -0.748050, 1.351250, -2.115680, 0.585040, -0.851770, -0.356130, 2.274170,
-0.191380, 0.766940, 0.806170, 0.936290, -0.550590, -0.229800, -0.257920, -1.122000, -1.207480, 1.268360,
0.990180, 1.817590, 0.024570, -1.602330, 0.310610, -0.509210, -1.797600, -1.372230, 0.095930, 1.174420,
0.211480, -1.246610, 2.049690, 1.051220, 0.006270, -0.556840, -3.036610, -0.174210, -0.454720, -0.767650,
-1.557030, 0.608710, -0.397530, -1.177210, -3.953880, -1.116650, 1.294780, -1.621070, 0.656680, -0.266630,
1.328550, 1.176170, 0.265540, 0.082090, -0.148250, -2.996710, -0.643140, -0.499550, 0.636180, 1.150600,
-0.677550, -0.466810, 2.063770, -1.446250, -1.146550, 0.111060, -1.177600, -0.263190, 0.684630, -0.797610,
0.645430, 0.737950, -1.345130, 1.970150, 0.346960, 0.830360, -0.418590, -0.900630, 1.504060, -1.106430,
0.404470, 0.137520, -0.753750, 0.058440, 2.086900, 0.246710, -1.297380, -0.298410, 0.574600, -0.121870,
0.001870, 0.725500, 0.280590, -0.579420, -1.742780, -0.098530, -1.331870, 0.639960, -0.326910, -0.090040,
0.514590, -0.404240, 2.409450, 0.668270, 0.859440, -0.271970, -0.121030, -0.413760, -1.331700, -1.488150,
0.154140, -1.462320, 1.085300, 0.313290, 0.152640, 0.296940, -2.308520, 0.504220, 0.542050, 0.760690,
0.548400, -1.136310, 2.024890, -2.085070, 0.575450, 0.823000, 0.604250, 0.919840, -0.988410, -1.924110,
-0.427890, 0.249780, -0.857130, 0.985550, -0.118310, 0.232180, 1.897520, -0.305950, 1.146620, 1.431840,
-0.514030, -1.450980, 0.410110, 1.211760, 0.120960, 0.064450, 0.569030, 1.356510, -1.734160, 2.111530,
-1.292370, -0.557210, -0.357890, -0.609760, -0.691340, 0.267810, 0.238870, 0.501750, -0.227260, 0.305490,
-0.968560, -0.626800, 1.812570, -0.825280, -1.758840, -2.444260, 0.919830, -1.303510, -1.102030, 0.304100,
-0.569570, 0.801560, 0.669030, -0.613170, 0.088610, 0.286150, 0.859120, 0.494150, 0.777210, -0.429410,
0.340810, 0.844940, -1.836140, 0.917570, 0.993410, 1.415300, 0.828200, -0.608860, -0.283310, -0.855840,
-0.689180, -0.211890, -0.114040, 1.103680, -0.261850, -0.509270, 0.350510, -0.351700, -1.137140, 0.272540,
1.038560, 1.439740, 0.023840, 0.692310, -2.017480, 0.963300, -0.607690, 0.387310, -1.199620, 1.455340,
-0.663400, 2.035430, -0.504950, -0.475890, -0.876580, -1.367710, 0.858810, -0.220310, 0.119030,
0.010110, -0.659680, 0.348360, -0.874240, 0.684950, -0.822880, -1.942980, -0.761220, -3.075930, 0.498740,
-1.417360, 0.294020, -0.104600, -1.076810, 0.909430, 0.216850, 0.389560, 0.865520, 0.579450, 0.484250,
1.009990, 1.222680, -2.165620, -0.116220, -0.927260, -1.417080, 0.213570, -1.160990, 0.347000, 0.550860,
-2.247940, -1.641400, 2.126510, -0.250010, 0.780080, -1.960560, -0.953280, 0.045500, -0.269490, -1.798020,
1.471630, -0.397410, 0.540350, 0.516640, 1.108950, -1.424730, 0.333330, 0.905110, -1.010090, 1.004380,
-0.938110, -0.610700, -0.074570, -1.891110, 0.423930, 0.328260, 0.584030, -1.078960, 0.289100, -1.480990,
-0.374210, 0.321350, -0.105760, 0.815880, 1.733710, -1.849730, -0.180590, -0.060030, 0.373920, 0.814660,
-0.589700, -1.412630, -1.923700, -0.220160, -2.027580, 1.248210, 2.161630, 0.318710, -1.395710, -1.419650,
1.374560, -0.085960, -0.648770, 1.233870, -0.237720, 0.693590, 1.444110, 1.119250, -0.080170, -0.784190,
0.357840, -0.459800, -1.539250, 0.651030, 0.999280, -1.300290, 0.875590, 1.263760, 1.043060, 0.175060,
0.697870, -0.397410, 0.822250, -0.693960, 0.786760, -0.930250, 0.905720, -0.500950, -1.135010, -0.316380,
0.484920, -0.398690, -2.947970, -0.836040, -0.369150, 2.195850, 2.063220, -0.152900, -0.404820, 2.284900,
-0.765930, -1.995020, 0.069710, 1.902600, 1.956820, 1.743340, 1.018820, 1.474550, 0.451740, -1.459420,
0.505170, -0.539610, 2.277550, -0.153680, -1.309390, 3.513070, 0.404070, 0.470240, 0.491310, 0.236810,
-0.784980, 0.296650, -1.104290, -0.089520, 0.579200, -1.093480, 0.303190, 2.095670, -0.033240, 1.051210,
-1.341470, -0.655720, 0.021430, 0.300490, -1.394300, -0.226590, -0.919090, 2.190090, -0.473510, 0.067610,
-0.240310, -1.748770, 2.654290, 1.691270, -0.658140, -0.073610, -1.208130, -2.279860, 0.917260, -1.156070,
0.345890, 0.191320, 1.750850, -0.482550, 0.321190, -0.964090, 1.365470, -0.722580, 2.425190, -1.173980,
-0.685900, -0.074400, 1.102920, 0.532190, -0.123150, 0.671210, -0.052790, -0.798760, 1.306900, -0.858190,
0.189100, 0.716590, 0.289810, -0.467300, 2.089990, 1.513020, 0.250800, 0.996240, 2.456380, -0.511670,
-3.352470, 2.154540, 0.342190, 0.722800, 0.332900, 0.646610, 1.218800, 0.123000, 1.876960, -0.729030,
-0.099900, 1.202170, 0.574060, 0.439850, -0.662810, -0.518480, 1.103660, -1.468990, -0.585570, -1.365830,
0.369990, -0.949350, 0.020500, 0.270100, -0.509060, -0.331200, 0.006190, 0.246660, -0.120310, 1.303950,
-1.445650, 0.009960, -0.189630, -0.074970, -0.610200, -1.292100, 1.514920, 1.015420, 2.910570, -0.361370,
-1.011470, -0.924540, -0.583250, -0.824650, -0.724860, -0.656200, 1.199390, -0.598640, 0.760410, -0.320920,
0.850730, 0.490310, 1.247230, -0.784240, -0.305880, 1.614500, -0.280420, -1.899960, 0.034740, 0.435460,
0.339480, 0.606600, -3.102830, -0.114780, 0.715460, -2.616110, 0.485560, -0.903690, -1.463590, 0.478610,
-0.205450, -0.651080, -0.617810, -0.744180, 0.033980, 0.066830, 0.244030, -0.601130, -0.944750, -0.292800,
-0.212470, -0.246720, -0.934770, -1.000810, -0.976270, -1.407590, 1.677710, -1.443740, 0.120290, -0.633070,
0.601090, 0.539620, -0.082300, -0.837330, 0.000100, 2.113400, 1.196620, 0.836220, -0.625040,
0.956630, 1.218810, -0.387730, -0.207820, 0.776620, 0.050680, -0.944670, 0.033350, 0.217940, 0.376970,
-0.948100, 1.285070, 0.225000, 0.523680, 1.495230, -1.092680, -0.314010, 0.628080, -0.243150, -1.707160,
0.226220, 0.674290, 0.137030, -0.450930, -0.718300, 0.347260, -2.076620, 1.018480, -0.761200, 1.054040,
-0.453940, -0.412370, -1.866620, 1.281160, 1.500830, -1.462600, 0.805520, 0.290690, -0.088840, -2.184670,
-0.057440, -0.564220, -0.554500, -1.611860, 0.541610, 1.206080, 2.011490, -1.197740, 0.495040, 0.027470,
1.899990, -1.191420, 0.516130, 1.867450, -0.977120, -0.671200, -1.307280, 0.064440, 0.137320, -1.685390,
1.281330, 0.233610, 1.701960, 0.045530, -1.020830, 0.160020, 2.087920, -1.956600, 0.712830, -0.320350,
-0.722900, 1.478100, 0.790680, 1.103220, 0.201070, -0.779100, -0.798020, 0.046150, -0.551970, 0.612420,
-0.334380, -0.122910, 0.414850, -0.241870, -0.664360, 0.272600, -0.951010, -0.133660, 0.412630, 2.090600,
0.648550, -0.476400, -0.148830, -1.464260, 0.990860, 0.129880, 0.811930, -2.523480, -0.223230, 2.136770,
-1.362860, 1.088840, 0.402260, -0.435610, -1.206890, -1.365480, -0.227140, 0.411260, 0.088870, -1.515600,
1.025530, 0.481710, -0.282320, -0.801890, -0.558400, 1.306830, -1.286270, -1.711040, 1.479690, -1.664610,
-1.336500, 1.819560, -1.242690, 0.185950, -1.598720, 0.084920, 2.068600, 0.477920, 0.839100, 0.731740,
-1.715090, -0.173830, -2.792880, 0.086820, -1.346820, -2.013470, -1.013260, -2.409870, 0.426550, 0.616670,
0.361190, 1.119380, 0.899200, -1.680310, -1.354040, 1.371470, 0.495770, -0.580160, -0.418470, 1.252090,
-1.286250, -1.352780, -0.159280, 0.602870, 0.628370, 1.307120, -0.633470, 1.528700, 0.853650, -0.098600,
-0.350950, -0.335660, 0.680890, -0.527710, -0.978560, 2.007500, 0.744420, 1.309370, -0.689020, 0.729990,
-0.755090, 1.120500, 0.171900, 0.393770, 1.049750, 0.660260, -0.401460, 1.769760, 0.814660, 1.024090,
-0.751570, 0.950790, 0.519920, -0.438910, 0.618970, -0.590090, -0.459110, 0.785240, -1.720490, -0.036360,
-0.458090, -0.679460, -0.605210, -0.836620, 1.631010, 1.235820, -0.592470, -1.652170, 0.093650, -0.580890,
-1.633230, -0.858770, -0.920810, 0.731170, -1.076150, 2.526630, 1.052470, 0.058850, -0.943330, -1.236750,
-0.720190, 1.427410, -1.009390, -0.102130, -1.227400, 0.367540, 1.252710, 1.497930, -2.210470, 0.380960,
0.015420, 1.081730, 0.889200, 0.713140, -0.316410, 0.270090, -2.792630, -0.363410, -0.444960, 0.438280,
0.522940, -0.020870, 1.295890, -0.336720, 0.424950, -0.949500, 0.723110, 1.176440, -0.312700, 0.212090,
-0.313950, -0.175300, -2.431150, -1.049280, -0.655510, 1.991350, -1.306960, -0.360170, -0.147200, 0.565680,
-1.223160, -0.104580, -0.657610, 0.982920, 1.086760, 0.402220, 0.992080, -0.415720, -0.150370, -1.289110,
-1.586930, 0.724570, 3.370600, 0.278470, -0.183570, 0.162530, 1.005520, 0.946220, 0.105310, 0.703370,
-0.702420, -1.743790, -1.221170, -1.384090, 1.701650, -1.111030, -0.247950, -0.850070, 0.469550, 0.207490,
-2.746820, -1.097690, 0.244170, -1.150830, 0.237380, 0.050170, -0.765780, 0.624780, 0.978590, -1.521130,
-0.812450, -1.052120, -1.155060, 1.088620, 0.031460, 0.075130, -1.124990, -0.176230, -0.869710,
-0.053930, -0.611340, -0.773680, 1.640050, 0.581990, -0.453880, -0.649150, 1.486700, -0.204140, -0.703810,
0.255510, 0.048490, 0.656320, 0.748830, 0.951410, 0.188210, 0.082540, -1.153700, -0.199950, -1.431480,
0.281410, -2.273220, 2.546730, 1.433080, -0.437860, -0.776740, 1.347870, -2.325680, -0.455400, 0.900510,
-0.281280, 0.931810, 0.831950, 0.888750, -0.293720, -1.139670, 0.645930, 0.510830, 0.396320, -0.209050,
-0.644820, 1.012890, -0.942250, -1.253010, 1.993380, 1.379890, -1.936250, 0.401700, 1.361880, -1.199930,
-0.109980, 1.630160, -0.631810, -0.147990, -1.116830, 0.656470, -0.147380, -0.163570, -0.062720, -1.567120,
0.121920, 0.010670, -0.261780, -0.933320, 0.510490, -0.019410, -1.937240, 0.265970, -1.143000, -0.284170,
-0.209610, -1.222000, -0.279890, -1.184130, -1.349740, -0.550670, 0.649900, -0.823000, 1.763760, -1.302810,
-0.580030, 0.127530, -1.318480, -0.754890, 0.626040, -1.214520, 0.556310, -1.697360, 0.201020, 0.658010,
0.294860, 0.904820, 0.355440, -1.260180, 0.281540, 0.565070, -0.474050, -1.607120, 0.659900, -0.325870,
-0.176670, -1.165500, -1.771610, 1.615290, 0.305220, -0.225740, -0.893700, -1.564890, 0.544690, 2.065650,
0.627560, 0.419140, -0.863380, 0.614800, 1.792590, 0.307510, -0.086730, -0.960550, -0.427840, 1.052070,
-1.015180, 0.374320, 0.903180, -1.077350, -2.492460, 2.352700, 2.072660, 0.029850, -0.598700, -0.377150,
-2.488170, -0.563500, -3.249800, -0.745100, 0.708340, -2.448370, 0.361690, 1.170040, -1.330190, 3.038050,
1.042320, 1.572140, 1.086360, 0.742460, 1.721830, 0.629530, -1.004220, -0.024300, -0.581780, -0.039670,
-0.419480, -1.286000, 0.554360, -1.159210, 0.752770, 0.527220, -1.098450, 0.792610, 1.538670, -0.616770,
-0.335980, 2.050250, -2.281940, 0.670520, -0.022760, -0.126370, -0.290330, 0.266750, -1.703310, 0.482400,
0.390360, -0.066210, -1.277630, 1.455680, -0.501100, -1.608140, -0.623700, 1.718360, -0.476480, -0.873970,
-1.364130, 2.400350, -0.670420, 1.312370, -0.045390, -0.100310, 0.555200, 0.695610, -0.257970, -0.431220,
0.637000, 0.320980, 0.333500, -0.911100, -0.148060, -0.457120, 0.646910, 0.275070, 1.024280, 1.107890,
-0.080460, 0.692850, 0.305410, -0.323640, -0.788110, -1.348810, 1.262070, 1.243420, -0.316180, 2.096130,
-1.060900, 1.249430, -0.677310, -1.055910, -0.848790, -0.187350, -0.497260, -0.565550, -1.545350, 1.187270,
0.948760, -0.507340, 0.661420, -0.235550, -0.691270, 1.614770, -0.104230, 1.572330, 0.175240, 0.537610,
-0.101490, -0.136770, 0.764820, 0.335020, 0.895500, 0.655950, -0.782140, 0.762410, 1.059410, -1.273310,
1.428990, -0.755980, -0.485880, 0.581340, 2.030420, 2.144620, -1.658290, 0.325300, 0.033200, 0.338750,
0.447170, 0.092520, 1.405330, -0.672300, 0.055690, 1.104160, -0.095140, 1.532450, 1.436650, 0.812130,
1.568310, -0.065470, 0.115200, 1.928530, 1.899130, 2.331990, -0.640870, -0.001420, -1.235080, -0.075260,
1.031100, 0.309830, -0.221790, 0.401810, 0.107950, -1.074180, 0.357290, 1.065440, 0.150770, 1.439640,
-0.553490, -1.111240, 0.462700, -1.462040, 0.589520, -0.285530, -1.065220, 1.956930, 0.180700, -0.875820,
-1.804180, 0.501280, -0.121500, -0.600100, 0.359610, -1.426290, -0.670710, -0.679070, -0.727490,
-0.529940, 0.377110, 0.539470, -0.832300, -0.447870, 1.137880, -0.937240, 0.796540, -1.422390, 1.004200,
-1.020500, 0.362730, -0.177270, 1.269800, 0.931920, 0.947340, 0.467810, -0.640130, -0.259170, -0.497070,
-0.216510, 0.280720, -0.009910, 0.942520, 0.840050, -1.173050, -0.541130, 1.132460, -0.540730, -0.331750,
0.540860, -1.315660, 0.132240, 1.021810, 1.099740, -0.074530, 1.182560, -1.758930, -0.445360, 0.502670,
-1.024770, -1.470280, 0.002720, 1.933130, -1.567190, -0.256450, -1.333370, -0.107490, -1.433630, -0.594960,
-0.618160, -1.383240, 2.314290, 0.786310, -2.029670, -1.536030, 1.772860, 0.194720, -0.081480, 1.109750,
1.138480, -0.539240, -2.077260, -1.383860, 0.260990, 0.420880, -0.237050, -0.197970, -0.204520, -1.195570,
0.672440, 0.762120, 0.261380, -1.132090, 1.659080, -0.028390, 1.025710, -0.508890, 2.025340, 0.726470,
0.699170, 2.108140, 1.488260, 2.185830, -1.121560, 1.086970, -0.481530, -0.155150, 1.368910, 0.761150,
0.207430, -0.653770, -1.271900, -0.172740, 0.197410, 0.666280, 1.856900, -0.330670, -2.014260, 0.434640,
0.424120, 2.098910, -0.922990, -0.070710, 0.380840, 0.113130, -0.518240, -0.025090, -1.086480, 0.057120,
-0.749480, -1.244500, 1.372590, 1.401020, 0.070890, -1.579220, -3.274480, -2.234730, -0.068730, 0.067220,
-0.603110, 0.503970, 0.319450, -1.136800, -3.138060, -0.957200, -0.329530, -1.880510, -0.023190, 0.407530,
-0.085620, 0.841670, -3.295840, 0.410520, -0.061610, -4.559940, 1.209930, -0.420230, 0.555720, 0.704040,
-0.209660, 0.579040, 0.042700, 1.800910, 0.413820, -1.436510, -1.818840, 0.847180, 0.348640, 0.583020,
-0.995630, -0.986150, 0.338560, -0.919580, -1.735000, -0.419670, 1.197710, 0.364150, -0.563420, 0.748060,
1.783920, 0.263550, -0.028670, 1.110210, 0.842840, 0.639950, 0.894930, -0.164580, 1.415080, 0.124690,
-1.941390, 1.159430, 0.741670, 0.404100, -1.371540, -0.897760, 0.960410, -1.364400, -0.156040, -0.298370,
-1.389360, 0.589630, -0.940430, -0.864120, 0.768980, 0.617640, 1.047070, 0.168130, 1.703420, -0.383120,
-1.266240, 0.848370, 0.880940, 0.070650, -0.816020, 1.201960, -0.147130, 2.110740, -0.601870, 0.396620,
-1.448780, -1.895270, 0.370980, 1.433410, -0.056010, 0.652910, -0.142050, -1.246680, 0.270490, -1.400380,
1.026180, 0.070180, 0.970650, 0.526260, 1.337500, 0.263480, 0.536720, 0.430070, 1.673630, 1.600410,
0.413810, 0.415810, -0.372270, -1.225380, -1.023510, 1.211700, 0.373910, -3.038860, -1.715270, 0.403490,
-1.478940, -0.943940, 0.537100, 1.097790, -0.268510, -0.858910, -1.189860, 1.294460, -0.019000, -1.255190,
1.384080, 0.697960, -0.828410, -1.327470, 0.074890, -0.508230, -0.871720, 1.591510, -1.100580, 0.224800,
2.058080, -1.009540, 1.558420, -0.747530, -0.639350, 0.223900, 0.965420, 0.118850, -0.225160, -0.326970,
2.267830, 0.549590, 4.721580, -1.141200, -0.692190, 0.606840, 0.705780, 0.095180, 1.080930, -1.265950,
0.542720, 0.559230, -1.054080, -0.124650, 0.681470, -0.511320, 0.369280, 0.232130, 0.362910, 0.951210,
-1.152870, 0.928340, 1.040760, 0.390680, -0.345820, -0.040570, 1.165970, 0.048670, 1.327290, 0.419780,
2.302930, 1.639320, 0.507470, -1.084590, 0.870630, -0.364440, 3.230000, 0.828450, -1.016430,
-1.191250, -0.037030, 1.118550, 1.088220, -2.001060, 0.406470, -1.570860, 0.139800, 1.285490, -0.554880,
-0.936210, 0.260510, -0.647450, -0.833610, -0.701540, 1.499870, 0.094380, 0.312810, 0.081830, 0.801410,
1.643010, 1.607190, 0.814320, -1.016750, 0.018010, -0.027360, 0.632460, -0.676620, -1.618520, -1.520300,
0.140840, -0.890870, -0.440380, -0.073320, -0.988850, 0.104800, -0.363540, 0.891250, -1.961350, 0.850640,
-0.300070, -1.607380, -2.390550, -0.580320, 0.675580, 0.324050, -0.772540, -0.516140, -1.059230, 1.272000,
0.807480, 0.841340, -1.045680, 1.095760, 0.208890, 1.125020, -2.572880, -0.354880, 0.461780, 0.316680,
-1.302250, 0.338080, -2.008570, 0.583620, 0.231360, -0.056230, -0.580340, 1.679740, 0.823230, 0.097190,
-0.558030, 1.730850, -0.275230, -0.237100, 0.879630, 0.266840, 0.493560, -0.685960, 3.505830, 0.733170,
1.254640, -0.317580, 0.185460, -0.888240, 1.149330, 0.047900, -0.177560, -0.519590, -1.841030, 0.803070,
-0.939490, 0.288290, -0.726060, 1.198290, 0.263020, -1.036050, -0.697900, -0.829270, 0.472260, -0.425540,
1.477610, -0.422860, 1.331260, 0.749780, 0.851390, -2.347870, 0.253840, -0.772290, -1.093000, -0.395690,
1.349930, -0.416070, 1.301470, -0.003490, 0.621070, 0.618400, 0.015070, -0.647910, 2.227790, -1.513690,
-1.372380, -0.971870, -1.374530, 0.470290, -0.495080, -0.058860, 1.537880, -0.482940, -1.545470, 1.220480,
-0.979470, 0.218750, 0.291410, 0.374130, 0.624710, -2.035670, -0.767610, 1.917780, -0.702620, -0.002990,
1.745920, -0.042700, -1.211420, -0.511580, 0.140430, -0.549650, -0.672710, -0.820100, -0.595390, 0.640880,
-0.990470, -0.351780, 0.614580, -0.473370, 0.911260, -1.265850, -0.942780, 0.017010, 2.588230, 0.985440,
2.087910, 0.027550, 0.682560, 0.082750, 1.354800, -0.313220, -1.230950, 0.515510, 1.275170, 0.006000,
-0.748070, 1.145220, 0.007130, 0.066690, -0.774040, 1.686700, -0.135750, 1.586530, 0.230120, -0.643990,
0.583300, 1.017830, -0.589190, 1.081150, 0.811980, -2.609470, -1.100160, 1.937190, 0.333080, -0.791580,
-0.917050, 1.099810, -0.039960, 0.221780, -1.574010, 0.172490, 1.309870, 0.204820, 1.541000, -0.327000,
-0.678130, 1.223570, -0.565160, 2.158140, 0.728030, -0.067050, -0.909800, -0.021790, -1.719080, 1.606510,
1.609760, 0.274820, 0.634830, 0.467120, 0.571610, 0.031040, 0.712290, -0.123970, -0.426310, -1.016820,
-0.477780, 1.716280, 1.343390, 1.615490, -0.517270, -0.575650, 1.065930, -0.089640, -0.846210, 0.495900,
0.737390, -0.741050, -1.769890, 0.604290, -1.761650, 0.553060, -1.439510, 0.050800, -1.066190, -0.615100,
0.897460, 0.204670, -0.908280, 1.168450, -0.922800, -0.943650, -0.228270, 0.440790, -1.282130, -0.332650,
0.060710, -0.066130, 1.912250, -0.723790, 0.439740, -2.036860, 0.032110, -1.340620, -1.225510, 0.609450,
-1.880370, 1.079320, 0.819390, 0.102240, -1.532220, -1.112300, 0.622460, 0.999810, 1.397390, -0.748330,
-0.897140, -1.270960, 0.646220, 0.397270, 0.908910, 1.102020, 0.841780, -1.209620, 1.067500, -0.030790,
-0.316470, -0.287270, 0.230710, 0.371400, -1.260010, -0.157320, 0.460080, 1.924840, 1.720130, 0.021410,
0.480370, -0.310900, 0.749920, -1.864820, -0.131050, 0.681660, -0.171820, -0.174640, -1.682800,
0.633660, -0.295290, 2.001290, -0.622120, 1.515900, -0.157050, 1.269320, 1.031660, 1.346810, -0.966770,
-1.570220, 0.505740, -0.489610, 0.522100, 0.283490, -0.554410, -1.785390, 0.925860, 2.499540, 0.489320,
-1.876080, 1.825770, -2.582220, 0.066450, 1.209430, 0.915410, -0.470610, -0.244060, 0.730280, 0.313970,
-0.248740, 0.394390, 0.198410, -0.307510, -2.084680, 1.811130, -0.827390, 1.210240, 0.818140, 0.061060,
0.911040, 0.628770, 0.638740, 0.567880, 0.147190, -0.186070, 1.877790, 0.650380, 0.163670, -0.534170,
0.631100, 2.152090, -1.854670, 0.245230, 0.813410, -1.502950, -0.337650, -0.236490, 0.640030, -1.708180,
-1.795530, -2.158510, -0.502480, 0.187780, -0.969910, 0.209670, 0.310070, 1.216250, 0.428600, -0.935820,
0.158750, 1.592800, -0.150140, 0.903750, -0.262820, -0.223830, -0.748410, 0.126610, 1.987110, -0.866550,
-0.150750, 0.097700, -1.534510, -2.394830, 1.734990, 0.938010, 2.977330, 0.317630, 0.452160, 0.705920,
-0.698070, 0.297880, 0.664040, -1.847580, 0.283690, -0.425950, 1.605180, 1.352340, 1.195070, 1.175010,
-0.036470, 1.381230, -0.097110, -0.510710, 0.368760, -0.623130, -0.330260, -0.584880, 2.344060, 0.140480,
-0.720680, 0.741480, 0.077850, -1.218750, 0.981570, 2.988100, -2.318560, 2.389610, 0.241730, 0.880340,
-1.111560, 1.738780, 1.358450, -1.434980, 0.601900, 0.744420, 1.865170, -0.486400, -2.899470, -0.169560,
1.879480, 0.671820, -0.758460, 1.181670, 0.132880, -1.424840, -0.525500, 2.303820, -2.108650, 0.017880,
-1.997300, 0.313700, 0.332700, 0.552870, -0.557660, 0.591620, 0.428980, 0.132910, -0.277730, 0.493670,
0.768380, -0.334760, 0.428480, 0.163870, 0.225710, -0.928350, -1.085400, -0.012250, 0.372340, 1.026290,
-0.186890, -0.229510, -1.337710, 1.465620, 1.862080, 1.523930, -0.046770, 2.088570, 0.484250, -0.613750,
2.400260, -0.390130, 2.330230, -1.692010, -0.502120, -0.614690, 0.707160, -0.428830, -0.248570, 0.986990,
2.022920, -2.297900, 0.300700, 0.185950, 0.327710, -0.269760, 0.673760, -0.106080, 1.546960, -0.653620,
-0.700150, -1.076250, -1.438790, -0.970840, 1.214650, -0.184680, -1.368680, -2.433120, -2.741310, 1.041440,
-0.417570, 0.159450, 1.218100, -1.090180, -0.865600, -0.350360, -0.336710, 1.341500, 0.252840, -0.772670,
-0.947420, 0.222550, 0.877830, -1.038430, -1.352940, 0.218720, 0.728470, -0.100150, -0.397500, -0.727860,
0.048970, -0.310920, -0.658420, 1.836640, 0.546100, -1.410840, 1.562490, -0.710070, 0.413270, 0.536270,
-0.124790, -1.607090, 0.475500, -0.532030, 1.201290, -0.336210, 2.028910, -1.074940, -0.759460, 1.326840,
-0.127680, -1.516470, -0.372450, -0.195390, -0.352620, 0.390990, 0.415370, -1.182430, 0.150990, -1.377760,
0.837450, -0.781570, -0.486610, -0.190600, -0.178450, -1.836860, -1.340770, 1.006230, -1.326120, -0.230240,
3.653900, -0.165790, 1.870150, 1.926790, -3.024270, -0.383700, 0.337750, -0.032500, -0.034000, 1.462900,
-0.796750, 1.007080, 0.819880, 1.295190, -0.589560, -0.728430, 0.946890, -0.113230, 0.807690, -0.135000,
1.038930, 0.842370, 0.648630, 0.208900, -0.651960, -1.578250, 0.159290, -0.133090, -1.400050, -0.548440,
0.836660, 0.951940, 0.741460, -1.036020, -1.586160, -0.524360, 0.956050, 1.434020, -0.560540,
-0.250400, 0.369460, -0.308930, -0.662310, 0.055900, 0.162990, 1.370790, -0.494670, -0.135250, 0.248940,
-0.836970, -0.556550, 0.734990, -1.012020, -2.484080, -1.628640, -1.495990, 0.343630, 0.443500, -1.460450,
0.571420, -1.463480, 0.891920, -2.099090, -0.318020, -0.233410, 0.393680, -0.443190, 0.088340, -0.295500,
-0.409730, -0.855350, -1.126160, -0.420840, -0.249970, 1.193820, -0.766670, -0.083810, 0.215920, 1.803450,
0.686700, 0.783980, 0.495380, -0.585940, 1.132180, -0.153490, -0.039410, -0.731360, -0.085550, 0.151740,
0.691570, 1.366740, -0.093530, -0.800830, -0.131250, -0.158330, 0.230480, 0.738250, -1.173600, 0.720530,
1.197370, -0.654920, -0.272370, -1.455530, 2.284670, -0.456040, 1.488190, 1.768030, -1.078010, -0.295620,
0.108550, -0.876220, -1.421760, -0.491740, -0.922270, -0.549660, -0.115610, -2.418430, 0.058160, -0.238580,
0.240530, -0.368930, 2.115350, -0.720190, -1.533840, -0.982760, 0.307430, -1.248260, 1.001920, -1.218520,
-0.351290, 1.145400, 0.237150, -0.121310, 0.450910, 1.243900, -1.216200, 0.542520, 1.628630, 1.481160,
-0.708070, -1.799900, 1.165680, -0.185810, 0.402910, -0.694830, -0.937920, 2.168300, -0.603530, -1.344170,
-1.334560, -0.204910, 0.056560, 0.168120, -0.918500, -1.767760, 0.613820, 0.521660, -1.318280, 0.577480,
-0.509250, 1.348400, 0.434290, -0.941970, -1.624040, -0.364580, 1.236540, 1.062560, -2.561840, -0.419530,
2.018340, -1.042370, -2.964460, 0.645270, 0.189190, 0.239940, -0.214680, -1.368550, 0.646390, 1.137820,
-0.950130, -2.556090, -2.478300, 0.742110, 0.409140, -0.533870, 1.293720, -1.178190, -2.056900, 1.115320,
-0.515210, 0.703070, -0.357700, -1.221880, -1.005000, 1.101180, -1.888920, -0.072980, 0.200600, -0.322480,
-0.475010, 1.741300, -0.393430, 1.287090, -0.531050, -0.572970, -0.725720, 0.833480, 1.841050, 0.210560,
0.450620, -0.529660, -1.060510, 0.578200, 1.370420, -1.157390, 1.017500, 0.154150, -0.202080, 0.023240,
-1.095490, 0.184600, 2.104060, -2.447080, -0.345280, 0.160700, -0.078120, 0.808730, 0.273800, -0.539110,
0.564530, -0.682170, 1.437090, -1.715980, -0.092320, 1.401670, -0.576270, 0.752880, 0.203410, -1.002220,
-0.385820, 0.167710, 0.094520, -1.072940, -0.720360, 0.259940, -0.763420, 0.114120, -0.999580, -0.805450,
-0.284500, 1.506280, 0.100390, -0.789370, 1.890260, 0.133000, -0.785870, 1.861670, 0.112450, 0.682570,
1.039480, -0.046870, -0.410680, -0.083240, -0.799820, -0.246390, -1.401500, -0.271190, -1.364240, 0.065140,
-0.182630, 2.386520, 1.290570, -0.099220, 0.818420, 1.419250, -0.308850, 0.779530, 1.695470, -0.022300,
1.095360, 0.638750, 1.176840, 0.720610, 0.295840, 0.455060, 0.322810, -0.419860, -0.407360, 0.811060,
0.863750, -0.721540, -0.648820, 0.358760, 1.514940, -0.121250, -0.594900, 0.970040, -2.107700, -0.813380,
2.113680, -1.644930, 1.192800, -1.832340, 1.641060, 2.212790, 0.948640, -0.586440, -0.154590, -0.250640,
0.015480, 1.090670, -0.135790, -0.874530, 0.241640, 0.631180, -1.027870, 0.801440, 0.228600, 1.592960,
0.798190, 0.719260, 1.013080, 0.369630, -0.446140, -0.507790, -0.572230, 0.558130, 0.828780, -0.362510,
-0.253210, 0.844110, 0.860990, 0.225820, 0.278760, -0.724290, 1.048010, 0.936610, 0.750170,
1.220830, 1.602000, -1.426420, 0.678280, 1.907930, 0.964010, 0.622060, 1.148540, -1.498440, 1.236390,
-0.587470, -0.063360, 0.806750, 0.947590, 2.073460, 0.560740, 0.585730, -0.807430, -0.310610, 0.777120,
0.260530, 0.229330, -1.609240, -0.193890, 2.249440, -0.134290, -0.077710, -1.570180, 1.631800, 0.133260,
0.649250, -0.773920, -0.041920, 0.291640, -0.375130, -1.388200, 0.177790, 1.651490, -1.620620, 0.354370,
-0.053410, -0.757350, 1.247320, 0.676620, -0.277430, -1.250590, 0.244270, 0.426220, -0.912630, -1.028880,
1.469410, -0.439140, 0.472520, -1.551630, -0.569310, -1.351780, -0.020890, -0.311720, -1.059190, -0.387300,
-0.341480, 1.449570, 0.421750, 0.000310, -0.013980, -1.013250, 0.904030, 0.083810, -1.535360, -2.230690,
-1.146380, 0.169960, 0.444740, 0.487630, -0.321720, 0.460410, 2.480860, 0.446150, -0.701840, 1.357950,
-0.509760, 0.735520, -0.264030, 0.469960, -0.839520, -0.543590, 0.174980, -1.445180, -0.319210, -1.161950,
-1.739890, -0.429330, 1.207390, -1.872070, -0.988470, 0.875870, -0.144470, -0.607870, -1.810150, 0.782250,
-1.108340, -1.106670, 2.269210, -0.389710, 1.429690, 1.354680, -0.965600, 1.135680, -0.663360, -0.862370,
0.193890, 0.398440, -1.795640, -0.377720, 0.290120, -0.002060, -0.061070, -0.269840, 1.226430, 0.123880,
1.707980, 1.562890, 0.248850, -1.725650, -4.007340, 0.634850, 0.004950, 1.782770, -2.239440, -0.614440,
1.072120, 2.097420, -1.868470, 0.215900, 0.840830, -0.784780, 0.028950, -1.957380, 0.734310, -0.540700,
0.463760, -1.307200, -1.414450, -0.810350, -0.984400, -1.147200, 1.576180, 0.926540, 1.399570, -0.503930,
1.170230, -0.662320, 1.560520, 1.157120, -1.012740, -1.219550, -0.660080, 0.350350, 0.294200, -0.289380,
-0.455270, 0.498390, -1.640550, 1.621550, 0.861120, 1.456840, 2.289640, 1.240830, -2.420350, -0.914700,
0.345710, 1.118840, 2.072340, 0.967920, 2.004500, -0.468690, -0.320400, 0.290330, -2.101470, -0.962860,
0.359530, -0.134050, 0.417520, 0.772350, -0.471870, -0.902580, -1.030620, 1.756110, -0.166270, -0.430950,
1.006610, -0.176260, -0.369730, -0.658420, 0.639920, 0.195720, -0.937600, -0.911940, 0.973310, -0.575180,
-0.429860, -1.825840, 0.032170, 1.349250, 1.828620, 1.756510, 1.438820, 1.601140, -0.901390, 1.510400,
1.746530, 0.256820, 0.979620, 0.783610, 0.595780, 2.661260, -1.814220, -1.435820, 1.132390, 1.387720,
-0.830980, -0.922920, -0.395510, -0.229390, -0.039400, 1.567020, 1.993410, 0.958580, -0.499040, 1.059890,
0.806020, 1.323550, 0.225520, -0.800510, -0.038350, 0.825900, -1.117440, 2.999440, -1.051600, -0.818040,
-1.577870, 2.688370, 1.185240, -0.352610, -2.591710, -0.111520, 0.740060, 0.050770, -0.503820, 0.072160,
0.714160, -0.993180, 0.976830, -0.014770, 0.948360, 0.183850, -1.352980, -1.070060, -0.016620, -0.435570,
0.687090, -0.479380, 1.232920, 1.081010, 1.334270, 1.356240, -0.979940, -0.546560, -1.335210, 0.209900,
-0.666040, -0.905890, 1.005550, -0.074060, 0.503280, -0.502130, 0.979220, -0.204460, -0.595720, 2.176220,
-0.520610, -0.820330, 0.134080, -0.232050, 1.505060, 2.210720, 1.117230, -1.240730, 1.435360, 1.527370,
-0.553400, 0.345100, -1.162560, 0.532360, 0.145090, 0.854470, 0.248890, -0.006070, 0.456800,
-0.206440, -0.954490, -0.648350, -0.340290, 0.640930, 0.389430, 0.419690, -0.405930, -0.050950, -0.525770,
-0.487480, 0.345780, 0.557040, 0.386830, -0.175350, 0.945050, -1.363850, -0.499700, 0.342020, -0.928270,
0.932100, 1.024180, -1.975020, -0.648490, 0.282060, 2.403640, -0.913320, -0.408700, -0.389040, 1.471300,
-0.417560, 0.909400, -1.755390, -0.995210, -0.621700, 0.462160, 1.027460, -1.019990, 1.607720, 0.567710,
0.958490, -0.409720, -0.919550, -1.010980, -0.735120, -0.566730, 1.655090, -0.272660, 0.637120, 0.641160,
0.617760, -2.218670, 0.037360, -0.024160, -0.628920, 1.564350, -0.536660, -1.063540, -0.682300, -1.074700,
0.010940, -0.933260, -0.957850, -1.636790, 0.107890, -1.296760, 0.984160, 0.879530, 0.542040, -0.293450,
-2.168260, 1.717460, 1.443610, 0.365650, 1.321320, -0.450960, 0.117830, -0.060350, 0.037680, 0.579850,
1.519550, -1.637260, 1.211270, -1.298650, 0.428710, -0.168000, -1.203680, -0.398640, 0.504130, -2.389000,
-0.798200, 0.589770, -0.081570, -1.171680, -0.526020, -0.158850, 0.195430, -1.486520, -0.778060, -0.210290,
0.618420, 0.391280, 1.210960, 0.491200, -0.772300, 0.320790, -1.020010, -2.300140, 0.234540, -0.338600,
1.138240, 1.139160, -0.647100, -0.416060, 2.075820, 3.593270, -1.045070, 0.169320, -2.713870, 1.241610,
-0.304470, 0.096280, 1.019390, 0.302840, 0.673000, -1.406690, -0.406390, -0.400430, -0.459030, 0.028390,
0.862070, -1.325170, 3.072870, -1.723490, -0.346470, 0.348300, -0.371860, -0.402130, -1.263350, 1.313560,
1.714220, 0.211300, 1.978830, 0.264660, 0.241220, -0.115940, -1.378620, -0.926190, 1.143130, 1.697290,
-0.768540, 2.233920, -0.522610, 1.342780, -2.056940, -0.183140, -0.583230, -0.237600, 0.205040, -0.595230,
0.522070, -0.789570, 0.854270, -1.056700, -1.507320, 1.367170, -0.314400, 0.331640, -0.000310, -1.500520,
-0.695240, -0.960630, -1.102260, -0.861950, 1.028600, 0.434720, -1.854330, 1.762120, 1.186220, 1.488110,
-0.080480, 0.291740, -1.504740, 0.765880, -1.238800, -0.628530, -0.372020, 1.401530, -0.071150, -2.182730,
0.535780, 1.032390, 1.761510, -0.174290, 1.395930, -0.283490, 1.453670, 0.616900, 0.578400, -0.184480,
-0.892680, -0.614980, -2.282130, -1.062710, 1.692140, 1.537180, 2.939480, 0.858310, 0.349610, 1.308520,
-0.635020, -1.709450, 0.657270, -0.572800, -0.084580, 0.481260, 0.833710, -0.021210, -0.007940, -0.351780,
-1.118260, 0.434820, 0.257740, 0.762980, 1.917100, -1.122770, -1.687950, -0.277100, -0.279500, -0.702510,
-0.647980, 1.321730, -1.196970, -0.169110, 0.959850, -1.952720, 0.872950, 1.341450, -0.712080, 0.989340,
-0.809320, 1.335750, -0.308170, 0.573030, 0.180940, -1.529110, 0.630040, 1.362860, 0.843250, -1.279110,
-1.432480, -0.865140, -1.344720, -0.498340, 0.277920, 0.099980, -0.739980, -0.380410, 0.484970, -0.556290,
1.062980, 0.080460, 0.152520, 0.588980, 0.043560, -0.465110, 1.503410, 0.533660, 0.492190, 0.681880,
0.378020, -0.341030, -0.588600, 0.381370, -1.640440, -0.561270, -2.387690, -1.553120, -0.757450, -0.778700,
0.082530, -0.185530, 0.516100, -0.623210, -1.408300, 0.789150, -1.138140, -1.173830, 0.137330, 0.802450,
-0.423460, -0.278960, -0.131450, -0.528970, 1.115460, 0.361350, 0.070730, -0.107440, 1.031820,
-0.789120, 0.426520, -0.583340, 0.025160, 0.601080, -0.683260, 1.264680, -2.285890, 0.294070, -1.234600,
-0.493430, 1.802100, -0.481400, 0.615830, 0.133070, -0.200470, 0.183790, -0.317560, -0.141960, -0.549930,
0.389410, 0.299120, -0.202070, 0.501620, -0.685160, 0.026850, 0.069250, -0.143770, 1.031410, 1.103700,
-0.683400, -0.347520, -1.733840, 0.625400, 1.169300, 0.009470, -1.063650, -0.289220, 1.067880, -1.199160,
-1.684170, 0.822980, -1.402130, -0.365580, -0.659100, -0.415300, 0.749150, -0.056440, 1.380500, -0.823940,
-0.600830, -0.624740, 1.121950, -0.219520, -1.456380, 1.289210, 2.142200, -0.708830, 1.241730, -0.786740,
1.192300, -0.415390, 0.574090, 0.502880, -1.207910, 0.045620, -2.270900, -0.462850, -0.771550, 0.259320,
1.771190, 0.420520, -1.393310, 2.006060, 0.239820, 0.337590, 0.469100, 1.890070, 1.792890, 0.398420,
0.210380, -0.718980, 2.046920, 0.682520, 0.811700, -1.138810, -1.443980, 1.742670, -1.620710, 0.075760,
0.866490, -0.694260, 0.786110, 0.161280, 0.449230, 0.674370, -1.767490, -1.035290, -0.413210, 0.740640,
-0.028880, 0.239810, -1.184120, 1.306460, 0.313860, -2.378180, -0.943140, -0.537340, -0.867630, 0.477840,
-1.500550, -0.136930, -0.135620, 1.214730, -2.993450, 0.346040, 1.959910, -1.424390, -1.333690, 2.075340,
-0.923490, 0.193930, -0.153920, 0.531050, -2.779170, -0.790770, 0.581260, 1.567310, 2.378090, 1.886330,
2.028500, -1.822570, 1.483130, -0.067840, -0.397150, 1.459260, 1.181560, -1.050930, -0.910570, -1.893150,
0.254660, -1.357860, -0.328500, -0.990760, -0.445800, -0.983080, -0.068220, -0.065680, 1.668970, -0.175080,
-0.771010, 0.161710, 0.214300, -0.360640, -0.237130, -0.846700, 0.816340, -1.707660, -2.646780, 1.549930,
-1.247800, -0.127870, 0.985690, 1.256150, 0.222370, 0.661130, 1.711110, 2.413480, 0.089850, 1.932660,
-0.260300, 1.039310, -0.145010, -1.096620, 0.569410, -0.360810, 0.709810, 0.359490, 1.010140, -0.154280,
-0.874470, 0.577320, -0.576980, -1.033660, -1.598430, 0.294860, 1.248610, -1.017240, 0.210270, -0.862210,
-0.567150, -0.049390, 0.953290, 1.239230, 1.644180, -1.243850, 0.730040, 0.117050, -1.389380, 0.043520,
1.006640, -0.959780, -2.234030, 0.055170, 0.769880, 0.280970, 0.269540, 0.422380, -1.304240, -0.645670,
-2.159530, -0.913510, 0.824490, 0.109050, 0.881800, -0.174650, 0.745910, -0.665450, 0.061730, 0.173060,
0.196420, 0.688740, 0.989470, 1.419110, -0.552620, 0.441000, 1.310290, -1.579230, 0.861500, 0.121340,
0.783570, 1.856430, 0.386190, 1.130180, 0.452330, 0.580860, 1.285750, -0.092870, -0.563310, -0.942340,
0.217680, 2.032440, 0.367150, -2.631590, -0.235020, 0.087990, -1.308540, 1.078980, -0.808380, -0.677390,
-1.274000, 1.141310, -0.569100, 0.903390, -0.764490, 0.519070, 0.162220, -0.524630, -0.486850, 0.998330,
1.444150, 0.912150, 0.924410, -0.571430, 0.649100, 0.218960, 1.058810, 1.065530, -1.015890, -0.979110,
-0.764910, -0.387280, -0.378430, 0.405820, -1.312210, 0.183090, -0.709910, 0.493970, -0.601880, 0.765890,
-0.792480, -0.698690, 0.550490, -0.527090, 1.184100, -1.315580, -0.144510, -0.689080, -0.554870, -0.256250,
1.114310, 0.732690, -1.000660, -0.836460, 0.325800, -0.193830, -0.374640, 0.729410, -1.314400,
0.168820, 0.267640, 0.293490, 0.318710, 1.557080, -1.058830, -1.312860, -1.273650, 1.136490, 2.042540,
1.367110, -0.415220, -0.332040, -0.630880, 1.270070, 0.629030, -0.542640, -0.133000, -1.028710, 1.484190,
-1.325240, -0.648080, -0.379740, -0.979010, -0.354600, 1.061070, -1.570200, 0.767750, -1.295950, -0.515130,
1.828630, -0.030820, 1.560430, -0.007020, -0.047080, -1.850090, 0.435960, 1.581670, -1.852920, -0.993760,
-2.108780, 1.568430, -1.465460, -0.606020, 1.259210, -1.059820, -0.338580, -0.297130, -0.013330, -0.577410,
-0.162470, -1.184150, 1.619670, 1.015180, 0.075230, -0.315350, -0.908760, 0.160800, -1.307640, -0.476250,
0.265650, 0.095540, -1.006100, 0.168510, 0.713830, -0.100000, -0.180130, -0.327880, 1.115230, -0.995100,
0.110420, -0.010890, 1.518140, 1.356560, 0.110320, -0.848670, 0.020790, 0.748840, 0.852260, 0.629760,
0.096940, -0.795740, 0.292190, 0.837390, -0.699270, 0.810980, 0.587590, 0.328970, -1.328630, 1.224590,
-0.045020, 1.515300, 0.390410, -1.042170, 1.153100, -0.966790, 0.006250, -0.737340, 1.260670, -0.578610,
-0.668600, -0.464220, -0.679110, 0.150490, -2.556920, -0.916740, -1.350840, -0.284300, -0.238210, -0.158530,
1.043440, 0.954910, -0.498660, 3.378190, -1.683290, 0.804100, 0.685970, 1.334640, -0.983350, 1.456460,
0.377140, -0.725360, 2.543040, 1.117510, -0.605100, 1.280370, -0.041710, 1.787210, -0.710120, 0.040360,
0.531710, -0.508620, 1.309670, 1.417550, -0.523220, 1.972530, 1.851350, 1.813410, -1.030710, 0.476700,
1.153130, 1.291120, -0.276810, -1.640930, 1.385290, -0.216260, -0.643670, -0.563300, 0.242490, -0.735020,
0.521220, 1.757280, -1.199370, -0.724920, -0.087240, 0.667700, -1.138270, 1.109040, 0.004400, 0.809580,
-0.625300, 1.102040, -0.905160, -1.080650, -0.406330, 1.556080, 1.359950, -0.251520, 0.204190, 1.296320,
-0.227330, 1.318900, -0.310460, -1.968360, -0.066460, -0.852740, -1.430470, -0.685600, 0.967430, 0.708540,
0.348320, -0.236490, 1.144560, -0.025100, 1.412130, 0.107360, 0.476500, 1.574920, -1.372830, 0.085920,
0.861660, -0.905420, -1.322460, 1.038360, 0.020820, 2.277220, 0.285930, -1.644680, 1.780270, -1.011270,
-0.396200, -0.791760, -0.584840, -0.371970, -0.524840, 0.498880, 0.434600, 1.235500, -0.798520, -1.053890,
0.730690, 1.124760, -0.020290, -0.908610, 0.792680, 2.213870, -0.516410, 1.055400, 0.992390, 1.511560,
-1.465570, -0.945950, -0.387880, 0.324120, -0.452780, -0.530660, -1.096860, 0.629940, 0.902710, 3.040290,
-0.180120, -1.860960, 1.474290, 0.424470, -0.218420, -0.222590, -1.114300, 1.147010, 0.755170, 0.046300,
1.137110, 0.329150, 0.703970, -1.537330, -0.976830, -0.014990, -2.344470, 0.884790, 0.665750, -0.524120,
-2.409230, -1.171020, 0.468030, -0.672970, -0.112670, 0.519290, 1.021380, -0.220900, 0.275200, -0.782580,
0.102300, 0.956360, 0.724160, 1.960810, -0.031590, 0.636410, -0.171370, 0.533880, 0.799540, -0.125870,
0.406400, -0.149270, -0.117620, -1.042010, 0.901400, 0.640660, 0.058400, -0.593810, 0.694170, 0.430820,
0.488700, 1.534060, -0.403600, -1.271940, -0.097130, -0.774450, 0.659020, 0.130620, 0.573850, -0.945130,
-0.849530, 0.512330, 0.973300, 0.236310, 0.656270, -1.138290, -1.357250, 1.024460, -0.061510,
1.518190, -1.149980, -0.151640, 0.956180, 0.317210, 1.841160, 0.435300, -0.711260, 0.749910, 1.063110,
0.467610, -0.063470, -0.207420, -0.306150, 1.363360, 0.809470, 0.906610, 0.370480, -0.223880, -0.497850,
-1.900270, 0.437050, -0.025230, 2.651370, 1.419630, 0.923290, 0.778240, 0.639960, 0.757030, 0.550600,
0.776820, -0.420260, -0.359210, 0.505850, -0.204160, 0.428980, 0.276620, 0.525890, 1.285900, -0.291740,
-0.347040, -0.302880, 0.426110, -0.528140, -0.561170, -0.399950, 0.213630, -0.529070, 1.028540, 0.963590,
0.274250, -1.408970, 0.730040, 0.236100, 0.940880, 0.180970, -1.668400, -1.097050, 0.110220, -1.194260,
1.016780, 1.074710, -2.283090, -0.509180, -0.058110, -0.712980, -0.718150, -0.305210, -0.469440, 0.478610,
-0.496040, -1.979370, -2.070400, 0.420530, 1.189120, -0.228470, 1.241920, 1.042870, 0.448270, -0.953800,
-0.038630, 1.952650, 0.410750, -0.805110, -1.274360, 0.314810, -1.120230, -0.663860, -1.231380, -1.970950,
0.360070, 0.183190, -0.985670, -0.726320, -0.330710, -1.100020, -1.071620, 0.608670, 0.109730, 1.160000,
-0.594050, 1.318160, -0.441690, 0.267430, 0.826160, 2.200900, 1.647800, -2.185370, 0.665690, -2.594830,
1.902340, -1.293060, -2.686590, -0.468390, 0.903750, -0.355940, 0.583020, 2.390200, -1.051430, 1.756340,
-0.125550, -1.481920, -0.153500, 1.862330, 2.603290, -0.517960, -0.823400, -1.691990, 0.090770, -0.461330,
1.251900, 0.260300, 4.309620, 1.376990, -1.103480, 3.905170, 1.137930, -0.439700, 1.147940, -0.616490,
-0.070440, -0.440420, -0.631190, 0.200960, -0.649620, 1.847050, -0.499830, -0.887670, -1.260800, -0.894270,
-1.303270, -2.984400, -0.813830, -0.633680, -0.537610, 0.433260, -1.501680, 0.953550, -0.261310, -0.512640,
1.465150, 0.796470, -1.368300, -1.081790, -0.615330, 2.107530, 2.463220, 1.021730, -0.980630, 1.306760,
0.577240, -0.445140, 0.567120, 0.251390, 0.422870, 0.182560, 1.016710, 1.641600, -0.052950, 2.017880,
1.548980, -1.476800, -0.193670, -2.133900, 1.135650, 0.869660, -0.756720, -0.880000, -0.607790, 1.318000,
1.007620, -1.772310, -1.414370, -0.726460, -0.046820, -0.113870, 0.524790, 0.758480, 1.047650, -0.483240,
-0.972850, -0.695030, -1.064160, 0.782840, 0.770990, 1.614520, 0.804160, -0.308270, -0.943770, 1.445460,
-1.305830, 1.395250, -2.011360, 0.525470, -0.455550, 0.207220, -0.372900, -0.968990, -0.185460, -0.040270,
-0.790960, -0.804930, 0.969400, 0.122710, 1.648460, 0.123340, -0.119230, 1.471420, -0.670870, -0.267280,
0.132490, -0.701620, 0.187660, -0.317560, 1.257180, 2.047330, 0.378370, 1.385930, -0.038840, 0.932460,
0.165090, 2.259120, 0.087040, -1.129290, -0.536490, -0.411610, 0.562110, -1.007940, -1.328450, -0.001680,
-0.006820, -0.343350, -2.037990, 0.651050, 0.107700, 0.368590, 0.107280, -0.512850, -0.398570, 0.967050,
2.776020, -0.095370, 0.782740, 0.032830, -0.530410, 0.961920, 0.333060, -0.461750, -0.277030, -0.879560,
-1.048180, 0.132280, -0.791320, 0.336750, 0.564070, -0.289770, -0.099270, -0.723370, -0.516450, 0.957870,
1.410980, -0.343240, 0.317760, 0.781850, -0.543040, -0.150660, 1.041390, 0.314980, 0.073040, -0.065520,
0.688260, 0.669520, 1.667210, 1.251600, -0.255110, -0.105770, 0.129310, 0.735060, -0.396190,
0.246080, 0.579110, -0.422100, 0.001530, -1.312410, -0.469480, -1.237290, 0.674490, -0.117100, -0.471300,
1.003400, -1.149490, 0.922660, -1.477120, -0.202380, -0.228350, 0.099850, -1.603520, -0.612280, 0.517650,
-0.370150, -0.082440, 0.561600, -1.157580, 1.235310, -0.324730, 1.544170, -0.353390, -1.544050, 0.916560,
0.431070, 0.518250, 0.260640, -0.481820, 1.060070, -1.009240, 0.513130, -0.976820, 0.719670, 1.080720,
0.372100, -1.042090, 0.133140, 2.112020, 0.947400, -0.346440, -1.957280, -0.506280, -0.081410, -0.420310,
3.153700, 0.965980, -0.854600, 1.090990, -0.258800, 1.096350, -1.092710, -0.874420, 1.462060, 0.726110,
-0.775090, 0.921230, 0.471540, -1.173210, -0.174500, 0.787500, 0.819980, 1.637950, 0.283020, 0.973940,
0.549010, 0.216330, -0.068380, 1.328180, 0.874900, 2.166480, -1.064780, -0.376480, 1.506510, -0.737260,
-2.354720, 0.042300, 0.941140, 1.415870, 0.212850, -0.779470, -0.642970, 2.651180, -0.059450, -1.331980,
0.116500, -0.375220, 0.288090, 0.901720, 0.266890, -0.062250, 0.156810, -3.080580, 0.128300, -1.763840,
0.376860, -0.416630, -0.485070, -0.530570, 0.676000, 1.859530, -0.525800, -1.417990, 1.786680, 2.781290,
-0.087650, -1.362890, -0.232210, -0.270790, -0.942570, 1.147340, 0.967460, 0.348110, -2.209280, 1.621300,
1.065560, -0.048330, 1.153410, 1.302600, 1.428700, 0.737340, 0.338540, 0.684800, 1.159980, 1.791270,
1.127440, 1.433520, 1.869180, -0.381750, -2.448060, 3.105470, 0.083610, -0.698800, 0.165860, -1.757690,
1.373480, -0.584200, -1.350760, -1.268570, -0.421200, -0.462960, 0.636870, 0.755300, -0.421580, -0.015730,
-0.886120, 1.345380, -1.732350, -1.022790, 1.633460, -0.055030, -0.383670, -0.718520, -0.312020, 1.214470,
0.327580, 1.361540, 1.514580, -0.712890, -2.808220, -0.258900, 1.568230, -0.688610, -0.153720, -1.740130,
-0.368020, 2.093690, 2.062200, 0.110460, 0.065080, 1.755900, -1.043190, 0.627940, -1.668710, 0.891150,
0.232110, 0.194630, 0.142800, -1.941850, 0.811940, -0.093780, 0.721940, 0.115640, -1.749900, -0.004140,
-1.124900, -0.696710, -1.997180, 1.855910, -1.422750, 0.923810, -3.280410, 0.738520, -0.183080, -0.316330,
0.003510, -1.499140, -0.174550, -0.485600, -0.520090, -0.224720, -1.014070, -1.383840, 1.643550, -1.579510,
0.830250, -0.447340, -1.127660, -0.802230, 0.471550, -1.534810, -0.537620, -0.382520, -0.601190, -0.808350,
-1.589740, 1.614610, -1.886600, 0.111150, -0.953290, -2.396510, 0.774290, 1.133950, -0.257340, 0.387850,
2.151320, -0.573400, -0.548710, 0.707930, -0.853570, 1.313500, -0.346470, -1.291610, -1.834840, -0.439900,
-0.199130, -0.708050, 0.572200, -1.311200, 1.172150, -0.394790, -0.092030, 0.552680, -0.071600, -0.696310,
-1.941160, 0.431000, 0.894220, -0.355470, 0.364900, 1.153490, 0.996140, 1.947600, -0.394640, 0.741840,
0.442850, -0.156290, -0.096330, -1.195030, 2.155720, 1.132870, -0.901000, 0.406650, -1.013520, -0.806840,
-0.437880, 0.246550, -0.001020, 0.233380, 0.286990, -0.049460, 0.132450, -0.438850, 0.713950, 0.742290,
1.213100, -0.706470, 1.040540, -0.517890, 0.310630, 0.336160, 0.351460, -1.031290, 1.307570, -0.476710,
-1.197490, -1.296540, -1.172420, 0.643450, 1.060990, 2.590650, 0.704800, -0.075980, -0.969420,
0.439630, -0.632060, -0.101200, 0.631430, 0.444310, 0.267090, -1.516300, 0.052310, -0.438840, -0.562230,
-0.544960, 0.756500, -0.921780, -0.636170, -0.720360, 0.105750, 0.662940, 0.889550, 0.706700, 0.017710,
-2.158040, 0.982200, -2.134480, 0.966050, 1.754940, -0.090070, 1.232250, 0.014540, 0.123970, -0.456840,
0.089740, -0.033180, 1.424120, 1.356970, -0.704020, -0.388240, -0.699130, 2.259400, 0.945420, -2.435630,
-0.177800, 1.234530, 1.182280, -1.070220, 2.250260, -0.124130, -0.218140, -1.025800, -0.334110, 0.063970,
0.966220, 0.999410, -0.423380, -1.203870, 0.921610, -0.024390, 0.201290, 0.014090, 1.730820, -1.241290,
0.687270, -0.262190, -0.462430, -1.757370, -1.712470, 0.084100, 0.612430, -1.070930, -0.464170, -1.288180,
1.035920, 1.229700, -0.333710, 1.565590, 1.882390, -2.103370, 0.480750, -0.927580, 0.773820, 1.144970,
-1.074490, -0.151770, 0.176630, 1.199130, 0.445780, 0.042140, -0.346440, -1.521270, -0.842580, -1.608320,
-0.212160, -1.426060, -1.877680, 0.098530, -0.175010, 1.206420, 1.237900, -0.380600, 1.028780, 1.479020,
-0.607090, 0.925190, 0.019430, 0.260110, -0.515840, -1.203720, -0.353580, 0.162780, 0.230680, -0.863580,
-0.110590, 1.417650, -2.030250, -0.750360, -0.116420, 1.724250, 2.133340, 0.007250, -0.227200, 1.195210,
-0.417570, -2.015060, -0.377440, 1.563320, 1.475920, 0.685680, -0.125570, -0.592640, 0.828050, -0.288500,
-0.858870, -0.472410, 3.220140, 0.947060, -1.375590, 4.593920, 0.467330, -2.420790, 2.516670, 0.033590,
1.323870, -0.502120, 2.233640, 2.155200, -0.720830, -1.293080, 2.019890, 0.621080, -0.120200, 1.629590,
1.244260, 0.411870, -0.236650, 1.124030, 1.391560, -0.203210, 1.055120, -1.636290, 0.847670, 0.777680,
-2.083280, -0.478640, 0.943980, 0.434800, -0.335360, -1.879970, -0.293930, -0.174640, 1.989610, 0.460250,
-0.742140, -2.486030, 0.873440, 0.404380, -0.360610, 0.525490, 0.017280, -0.373300, 0.791330, 0.316420,
0.579730, 1.043010, 0.469480, -1.066370, -0.600320, -1.097940, -1.177170, -2.312310, 0.624540, 0.267760,
-0.301400, 0.882870, 1.715700, -0.753700, -0.536670, 1.077410, -0.731420, 0.945820, -1.416660, 1.101970,
0.293010, -0.142180, -0.014380, 0.348660, 0.154190, -0.151030, -0.449750, -0.749400, 0.021950, -0.494970,
-0.556570, 0.971350, -0.841870, 0.979780, -0.831400, -0.045190, 1.141150, 0.538880, -1.870440, -1.449390,
0.938080, -0.205050, -0.578540, -1.088950, 1.485310, -0.064590, -1.120190, -0.351810, -0.489630, 1.138130,
-0.087860, -1.578870, 0.271750, 0.330800, -0.105580, 1.192700, -1.406390, -0.054440, 0.558910, -0.321400,
0.892200, -0.077750, 0.467090, -1.321050, 1.086620, 1.232310, 0.025820, 0.056730, -1.911690, -0.111140,
-1.916550, 0.056120, 0.017390, 1.087970, -0.298060, 0.211850, -0.263630, 1.916480, 1.944490, -1.823190,
-1.500130, -0.105330, 0.884350, -1.431590, -0.540390, 0.818050, 0.679130, -1.636490, 0.084190, 0.135890,
-0.305390, 1.169090, 0.630890, 0.331000, -0.229100, -0.487680, -0.399990, 0.013420, -0.967750, -1.110730,
0.051210, 0.027650, -1.389680, -0.337930, -0.242750, -0.124350, -0.129090, 1.134620, 0.759100, 1.739220,
0.346840, -0.249630, -1.770320, -0.920770, 0.231380, 0.321370, 0.044910, 0.989680, -1.174480,
2.326080, 0.228680, 0.751140, -0.534810, -0.666400, 0.552360, -1.487330, 1.934790, 1.364430, -1.012480,
-1.123540, -0.888780, 0.538230, 0.404900, -0.235240, 0.701510, -0.669320, -2.007540, 0.325240, 0.236490,
0.820150, 1.838580, -0.879930, 1.680340, 0.696800, 1.179650, -0.947360, -0.687730, -1.741580, -0.002080,
0.402670, -2.174390, -0.515480, -0.356040, 1.209960, -0.719310, 0.935440, -0.709930, -0.415130, 0.243620,
-1.522090, -1.046680, -0.998820, -0.569350, -0.544120, 0.436520, 0.881910, -0.772220, -0.637280, -1.147730,
-1.919840, 0.082110, -0.799280, -0.082540, -0.551640, -1.438740, 1.856770, 1.860300, -0.755080, 1.873190,
-0.091220, -0.298940, -1.735470, -0.317430, -0.541350, 1.486270, 0.541650, 0.001820, -0.506290, -0.728170,
1.175190, -0.259360, 0.820920, -0.596100, -0.248780, -1.267300, 0.670690, -0.785180, -0.340550, -0.994850,
-0.167380, -1.729470, 2.121370, -1.048460, 0.460980, -0.809710, 0.363240, -1.596090, 2.236580, -1.461090,
1.000170, -2.942770, -0.600470, 0.638190, -0.766180, 0.212480, -0.620070, -0.520920, -0.178860, 0.396050,
1.048240, -0.946030, -0.399710, 0.545950, -1.333550, 1.034140, 0.588180, -0.467370, -0.108610, -1.585610,
-1.237100, 0.410970, -1.347400, 1.464290, -1.093240, 1.511330, 0.348000, -0.492150, -0.726540, -0.795960,
-0.026460, -0.082250, 0.879280, -0.053300, 0.328790, 1.500150, 0.236910, -2.058320, 0.298850, -1.070810,
0.439020, -1.676530, 0.675830, -0.749610, -1.265620, 2.840550, -0.590230, -0.402090, -1.509990, 0.282600,
-1.052890, 1.326760, 0.336390, 0.200620, 0.379240, -0.914350, 0.817100, 0.549130, 0.092840, 2.287210,
-0.623160, 1.367050, 1.119220, -0.490810, -0.504940, -1.079530, -0.727940, -0.333990, 1.086730, -0.293150,
-0.938460, 0.365580, -0.752890, -0.072740, 1.099500, 0.706590, -0.613290, 0.365800, -0.312760, -0.752060,
0.864130, 1.873490, -0.733970, 1.788920, -0.780180, -2.055380, 0.560570, 0.520700, 0.734580, 2.298210,
-0.624430, -1.543990, -0.307440, 0.686140, 1.093560, -0.659810, 0.025090, -0.793690, 0.201890, 0.052980,
0.488080, 1.768630, 0.092290, 0.314170, -0.683840, -0.834700, 2.077500, -0.300670, 0.294510, -1.509170,
1.614240, 0.482220, 0.156910, 1.240640, 1.453020, -1.224190, 0.483440, -1.519300, 0.004080, 1.792040,
-0.360200, -1.461170, 0.954740, 0.695980, -0.091770, -0.535070, 1.180680, 1.125430, 1.430980, -0.016670,
-0.470590, 0.851980, -0.031010, -1.725610, -0.490340, -0.335090, -0.235860, 1.330190, 1.129940, 2.137920,
0.324680, -0.003130, -0.880900, 0.099400, 1.390910, -0.470100, -2.036570, -0.602800, -1.954780, 1.374950,
-0.688600, -0.180800, -2.152070, -1.658040, 0.242810, 0.460460, -0.459330, -0.281230, 0.579940, -1.100290,
0.179550, 1.660180, 2.790600, -0.449500, 0.525720, 0.267220, 0.158840, 0.373160, 0.933430, -1.250060,
0.655930, 0.231600, -0.092090, -0.564960, 2.121440, 0.099040, -0.046870, 1.114610, 0.596360, 0.667130,
0.833120, -0.809940, 0.559160, -0.966310, -0.414890, -1.065580, -0.526080, -0.764090, -0.630870, 0.233460,
-0.448490, -0.272050, 1.454360, 0.843060, 1.746170, -0.300130, 0.685570, -0.956000, -1.053510, -0.104450,
-1.393710, 0.451920, -1.027240, 0.526430, -0.307780, 0.054320, 0.378770, -1.373450, -0.559780,
-1.008170, 0.264820, 1.136220, -1.457110, 1.040890, -1.335240, -1.295590, 1.642850, 0.989090, 0.837580,
0.007020, 0.510560, 1.194860, 0.687720, -0.004270, -0.721350, 0.188260, 0.573860, -1.116940, 0.839170,
1.037630, 1.940770, -0.240800, -0.369690, -1.751480, -1.658060, -0.674080, -0.789190, 0.415430, -1.588010,
-0.064360, -0.755900, 1.464870, -1.228440, 0.017660, -0.435360, -1.624790, -0.644260, -1.657490, 0.906520,
0.429870, 0.155330, -0.271480, -0.594870, 1.957290, 1.932370, -1.129930, 0.544780, -0.191840, 1.517700,
1.093620, -0.767280, -0.130420, 0.068530, -0.748550, 1.170270, -0.127130, -0.530860, -0.555700, 0.085690,
-1.354210, -0.913460, 0.790100, 1.866000, 0.822590, -1.501030, 0.293530, -0.669600, 0.633130, -1.737560,
-1.657140, 0.386430, -0.412860, -2.481080, 0.874930, 0.016610, 0.160880, 0.343660, 0.141280, -1.270110,
1.287720, -1.319740, -2.154830, 0.259040, -2.225310, -1.168320, 0.869640, -0.326310, 1.078140, -0.948330,
-0.536960, 0.711970, 1.158570, -0.623160, 1.260440, 1.329960, -0.800590, 0.375420, -0.667530, -0.716850,
0.948960, -1.074670, 0.412600, 0.261670, -0.045660, -0.297360, -0.955530, -1.088990, 0.065080, -0.053810,
1.506420, -0.106620, -0.571470, 0.914140, -0.113700, 0.692030, -0.494390, 0.022760, -1.209410, 0.041510,
1.636410, -1.000340, 0.579230, 1.451160, 1.879970, -0.388460, -0.022590, -2.055150, 2.138500, -0.140360,
1.393610, 1.559980, 4.074880, 1.069350, -0.308330, 4.428020, 1.059490, 0.062050, 1.584980, 0.603520,
1.716090, 1.163300, 0.995930, -2.083980, -0.652670, -0.616360, 0.699520, -0.034160, 1.150470, -1.874420,
0.531120, 0.131500, 0.136560, -0.595340, 0.130560, 1.102040, -0.195300, -0.002300, -1.557430, -0.887960,
0.020130, -0.101910, 0.829140, -0.723460, 2.117100, 1.087770, 0.763710, 0.667330, 0.516730, -0.521570,
-0.865700, 0.895610, 1.836730, 1.535700, 1.578980, -0.201070, -0.300680, 1.246890, 2.022490, -0.523060,
-1.442860, -2.073730, 0.604630, 0.898720, -0.822350, 1.769210, 1.232560, 0.278460, -0.445200, 0.818500,
0.418410, 0.952760, -0.262670, -0.390770, 0.246460, 0.832610, -0.426710, -0.291240, 1.116480, -0.327550,
-1.317100, 1.778060, 1.124880, 0.641990, -0.423030, 0.421170, 0.652510, 1.249850, 0.853370, -1.798690,
-1.751300, 0.945480, 0.102390, 0.377320, 0.600120, -0.099590, 1.187000, 0.661830, 0.296160, 0.085880,
-0.427470, -0.430550, -0.423090, -0.700490, 0.193180, -0.448610, -0.423320, -0.140410, -0.000330, -1.161770,
-0.092270, 1.190970, -0.572500, -1.328250, 1.281600, -1.206640, -0.137440, 2.424010, 1.293080, 0.391250,
-0.434020, 1.562280, 1.287390, 0.107140, 0.668830, -2.542210, 0.227710, 1.640070, 0.061880, -0.484200,
0.864950, -0.462350, 0.741880, -0.263540, 0.375040, -0.935890, 0.300920, -0.080590, -0.743160, -0.519310,
-1.105920, -0.315160, -2.453100, -1.329400, 1.823900, -0.736840, 0.989930, -1.728190, 0.303080, -0.680420,
-1.042450, -0.891620, 1.861720, -1.822830, 1.530020, -0.091870, 0.929900, 1.701340, 0.705120, 0.696740,
1.536540, 0.838270, 0.173260, 0.329300, -1.037990, -2.083320, -1.811170, -1.001760, 0.485390, 0.457900,
-1.832980, -1.339820, -0.736620, 0.336490, 1.059170, -0.261970, -0.593210, 0.173410, -0.038230,
1.451420, -0.935660, -0.041400, -0.144270, 0.366100, -1.067890, -1.863590, 1.213960, -3.099190, -0.924030,
2.140720, 0.981630, -2.718820, 1.217860, 0.307600, -0.676350, -0.461270, -1.431820, 1.097370, -0.497390,
2.468110, -0.065080, -0.707490, -0.633810, -1.802560, -0.774320, 0.499600, -0.764730, -1.266590, 0.024600,
0.086550, 1.308330, -0.637350, 0.918240, -0.544200, -0.388060, -0.133330, 0.205560, 0.460150, -0.176780,
0.547900, 0.330460, 0.080500, 0.752270, -0.182790, -0.687760, -1.131580, 0.746020, -0.123790, -0.400060,
-0.983850, 0.792990, 0.182640, 0.138950, 0.466410, -0.883660, 0.530510, 0.453230, -0.986950, 0.019320,

-3.346120, -1.510740, 3.224580, -4.522960, -4.820610, -3.554510, 1.507570, -1.288090, -0.473920, -3.283120,
-0.102510, 0.547670, 0.942120, -2.826770, 1.103510, 3.571760, 3.303760, 0.658250, 0.768240, -0.506460,
1.155350, -2.543660, -1.548700, 2.644560, -2.202140, -3.249130, 0.661110, -0.257750, -1.529770, 0.128850,
0.042230, -0.144140, -1.602630, -0.803510, -0.840430, -1.420200, -1.195130, -1.095700, 0.364210, 0.227520,
-0.256810, 0.783590, 0.233070, -0.677150, 0.058120, -0.928830, 0.294570, -0.440640, -0.213370, 0.654020,
-1.122550, -0.724870, -1.310650, 0.807430, -0.355040, -0.762070, 0.286630, -1.054650, -0.914740, -0.081300,

0.761290, -0.138980, -0.532760, 0.009160, -0.490700, -0.036560, -1.302410, 0.175540, -0.454510, -0.496130,
0.330380, 0.139570, -0.188970, -1.241210, -0.943660, -0.775980, 0.173440, -0.620180, -0.467260, -0.759060,
-0.192660, 0.690330, 0.239830, 0.448270, -0.701000, -0.352090, -0.557570, -0.679850, -0.530160, -0.207600,
1.094430, -0.561470, -0.058130, -0.951010, 0.287120, 0.016380, -0.609230, 0.066850, -0.707900, 0.659780,
-0.855090, 0.469380, 0.771850, 0.236140, -0.227250, -0.656790, 0.484570, -0.438280, -0.819640, 0.722970,
0.103470, -0.834100, -0.435350, 0.245810, -0.653410, -0.060430, 0.102640, 0.269910, -0.688840, 0.716410,

1.191900, 1.411890, -1.665890, -0.491760, 0.338550, -1.296200, -0.893250, 1.452620, 1.016390, 0.613710,
0.018370, 0.028710, -0.506250, 2.059260, -0.339580, 0.265450, -0.071420, 0.342470, 0.815050, 0.018180,
-1.762180, 1.430290, -0.333270, 0.067010, -0.256830, -0.475180, -0.716780, 0.282360, -0.635790, -0.645240,
0.160330, -1.179720, -0.577330, -0.038070, 0.071710, 0.519730, -0.940080, 0.495750, -0.283390, 0.472150,
-0.619920, 0.977150, 0.508400, -0.185260, -2.548390, -0.374390, -1.469670, -0.006150, 0.171360, -0.727530,
-0.851770, -0.016880, -0.419720, -0.884380, 0.179820, -1.015950, 0.174410, -0.135400, 0.260830, -1.365230,

-2.040650, 0.751370, 2.631950, -3.133070, 1.805500, -2.709230, 0.771870, -2.486550, 3.088360, -1.656370,
-4.461970, -2.436460, 2.961660, 1.079640, -2.703370, 3.742820, -2.303420, -1.209030, -0.041460, -4.562340,
-1.915430, -3.571110, 0.625880, 0.818500, -1.297570, -0.917290, -2.081890, -0.102180, -0.885090, -0.682670,
1.035800, 1.217720, -0.679860, -0.566730, -0.799140, 0.504850, -0.984100, -1.965270, -1.037150, -0.693490,
-1.238470, -1.613820, -1.275660, -0.384050, -1.326980, -0.513460, 0.457760, 0.644140, -0.739430, -0.161480,
0.392600, 0.303940, 0.821080, -0.606110, 1.039940, -1.558250, -0.696670, -0.456330, 0.269570, -0.423630,

-1.199390, 1.596390, 0.123910, 0.508780, 0.065500, -3.576810, -0.172030, 1.048420, 0.276960, -0.639170,
0.884790, -0.014510, 2.855440, -1.526900, -0.437680, 0.308980, -0.716910, 0.655910, -0.515750, -0.556300,
-0.729510, -0.015400, 0.333920, -1.053650, -0.715160, -0.515690, -1.208560, -0.666700, 0.900970, -1.150540,
0.996290, -1.658160, -0.553370, 0.536330, -0.870080, 0.151800, 0.992140, 0.967310, 1.164740, 1.283010,
-0.712500, 1.278170, 1.651160, 0.662380, 0.870860, 1.438840, -1.064050, -0.726720, -0.082680, -0.325050,
0.062780, 0.915520, 0.056960, 0.300780, -0.585090, 0.612910, -0.686530, 0.993470, -1.947810, -1.424050,

-1.291010, 0.014350, -1.270670, -0.124540, 0.403190, -1.602250, 0.946900, 0.019430, -0.496930, 0.384680,
-0.713220, -0.507070, -0.266790, -0.348350, -0.692300, 0.451800, -0.191380, -0.645070, -0.082460, -0.272750,
-0.592750, -0.235270, 0.456170, -0.515770, -1.331610, 0.356710, 0.079830, -0.792680, -1.023130, -1.155570,
0.679060, -0.049580, 0.586630, -1.389940, 0.411680, -0.908850, 1.469610, 0.702870, 0.019960, 1.081650,
-1.155370, -0.228350, -0.854690, 0.926890, 0.293930, 0.644760, -0.169490, 0.335690, 0.578410, -0.391250,
0.582750, 1.348510, 0.630350, -0.968960, 0.385470, 0.575480, -1.128420, 1.043700, 0.373930, 0.357040,

-0.522640, 1.128420, 0.398700, -0.949160, -1.518090, 0.612860, 1.691040, 0.510680, -1.403360, -1.260930,
-0.263140, 0.908200, -1.009660, 0.386110, -1.286560, 0.043220, 0.321870, -1.340130, -0.492500, 0.196920,
-0.754090, -0.167620, -0.105200, 1.653960, -2.020540, -0.870920, -1.098720, -1.063940, -0.573880, 0.249930,
0.959270, -1.602920, -0.930610, 1.285750, -1.153610, 0.618380, 0.711800, -0.453040, -1.542040, -0.072050,
-0.295970, -0.316290, 1.461180, -0.373270, -1.243010, 0.454650, -0.334400, 0.090000, 0.108430, -0.546380,
-0.632240, -0.158350, -1.027100, 0.076760, -0.553790, -1.415990, -0.565200, 0.403590, 0.191320, 0.068550,

0.432950, 0.592020, 1.367610, -1.250240, 0.206270, -0.187500, -1.139630, 0.353580, 2.488110, 0.610680,
0.434270, -2.111000, -1.473610, -0.647940, -2.013370, 1.218490, -0.486090, -0.043510, 0.192310, 2.128430,
-1.775810, 0.184830, -1.645650, 1.170620, 0.463430, -1.255700, 0.722530, -1.648560, 0.978920, -0.104770,
-0.194140, -0.542340, 0.420370, -0.161200, -0.845430, -0.188800, -0.472930, 1.514090, -0.054530, 1.062860,
0.090570, -0.250540, 0.694900, -0.868000, -2.081850, 0.124350, -0.820570, 0.105390, 0.739280, -0.241990,
0.090410, -0.199010, 0.342300, -0.120630, -0.624020, 0.307110, -0.230990, -0.658530, -1.456180, -0.958350,

0.026960, 0.438160, 0.482660, -0.684550, -0.483840, -2.167650, -0.831440, -0.871600, -0.393110, -1.141550,
-0.307190, -0.754870, 0.626620, -0.298800, -1.909980, 0.648060, -0.197540, -1.563040, -1.016720, -0.614980,
-0.528230, -1.504130, 0.808970, 0.027600, -0.382940, 0.185100, -2.387420, -0.213310, 1.637290, 0.496420,
-0.401800, -0.218370, 0.507340, -1.392980, -1.141390, 0.046510, -0.104560, -0.268880, 0.676010, -0.011110,
-0.105550, 0.646500, 0.325980, -1.214060, 0.070770, -0.512610, 0.235400, -1.444620, -0.736250, -1.246200,
-0.343640, -0.940730, -0.130950, -0.771500, -1.149560, 0.518920, -1.648020, -0.527350, -0.476670, -0.090630,

-2.640120, -2.583640, 0.168510, 0.167250, -1.751030, 0.301260, -2.534230, -1.191370, -1.168890, 1.504750,
-2.174460, 0.973780, -0.400650, -2.933570, 0.687250, -0.275880, -0.933910, -2.986560, -0.700300, -1.796130,
0.743360, -0.580970, -4.096400, 1.556060, 1.927510, 2.472700, 0.305390, 2.844840, 3.360710, 0.807000,
0.677260, 0.830700, -0.672700, -1.941390, 0.715400, -1.155220, 0.924910, 0.455290, -0.057200, -0.090410,
-0.263540, -1.237010, -0.585440, -0.034070, 0.162030, -1.533880, 1.488130, -0.787550, -0.908400, -0.566010,
-0.168460, -0.462640, -1.094340, -1.086850, 0.455630, -2.032850, 0.709790, -0.894590, 0.251720, 0.230720,

1.242200, -0.517830, 0.915920, -0.678140, -1.420910, -0.787780, 0.667540, 2.338770, -0.956700, 0.359040,
-0.080780, -0.924340, 0.125230, -0.462990, -0.624200, -0.472050, 0.580100, 0.023340, 0.209040, -0.803260,
-0.159500, 0.234280, -1.625060, 0.415530, -0.454610, -0.458440, -0.619390, -0.405690, -0.098530, -1.186970,
1.330330, -0.831370, 0.652930, 0.078650, 0.276130, 1.032240, -0.718970, 0.362620, 0.298900, 1.071940,
-2.546760, 0.908680, 0.378550, 0.045100, -1.320950, -0.456520, -1.351490, -0.895910, -1.654890, -0.133730,
0.317630, 0.800450, -1.533420, -0.110170, 0.014070, -0.650190, -0.132900, -1.018280, 0.219950, -0.602270,

-0.544730, 0.645820, -1.463010, 0.149170, -1.501010, 0.283570, 1.824330, -1.867130, -1.407360, 1.045250,
1.145630, -0.241210, -0.557000, -0.230250, 1.247570, 3.505570, -1.019940, 0.082320, 0.447960, -0.457490,
-1.553300, -1.237070, 0.726190, -3.261070, -2.396440, 0.042710, -0.633300, -1.802470, 0.541540, -0.705810,
-0.842300, 0.513950, 0.290590, 0.627620, -0.394630, -0.520760, -0.008590, -0.740730, -0.608600, 0.577220,
-0.275570, 0.551890, 0.568960, -0.546440, -0.306140, -1.311880, -0.935860, 0.190410, -0.728860, 0.064150,
0.748430, -0.800910, -0.784600, -0.041010, -0.095180, -0.149000, 0.216650, -0.669570, -0.011840, 0.157650,

0.017900, -0.023060, -0.386440, -1.516860, -0.785410, 0.159190, 0.413350, 0.270320, 0.044550, -0.455590,
-0.085030, 0.234320, 0.898690, -2.027230, -1.190570, 0.147660, -0.422900, 0.466490, -0.285790, -0.083770,
-1.197750, -1.706770, -0.020140, -0.371460, -0.972660, -1.026940, 1.626120, -0.107720, -0.601890, -1.205490,
0.767200, -0.429370, 0.458200, -0.454980, -0.335300, -0.206450, 0.010730, -0.237120, -1.306410, 0.532510,
0.120110, 1.038770, 0.336260, 0.017100, 0.443910, -0.497300, -0.285690, 0.255020, 0.347470, -0.573590,
-0.020350, 0.105100, -0.240460, 0.450080, -0.662780, -1.704130, 0.439230, -0.413950, -0.341140, 0.351890,

-0.019580, 0.139570, -1.810860, -0.848610, -1.376800, -1.135000, 1.276400, -0.579060, -0.574650, 0.766660,
-0.428770, 0.154190, -0.163610, 0.429220, -1.649320, 0.238240, 0.086980, -0.358190, -0.403320, -0.104710,
0.693570, 0.050730, -1.598330, -0.056800, 0.054870, -0.494000, -0.438460, -1.024210, -1.035300, -1.393470,
-1.875550, -0.237400, 0.724240, -1.339120, 0.349290, 0.687600, -0.826070, -0.360780, -0.015350, 0.366570,
-1.122130, -0.438410, -1.002180, -1.122680, 1.360800, 0.507620, 0.820560, 0.450690, -0.416590, -1.032180,
-0.405990, 0.450060, -1.078590, 0.700860, 0.469240, -1.356670, -0.349200, 0.259530, -0.706290, 0.210740,

1.121800, 0.388090, -0.368690, -1.282050, 0.950510, -1.494600, 0.848650, -0.684200, 0.849250, 0.145780,
0.279660, 1.864110, -3.325560, 0.630510, -0.572690, 1.755510, 0.119800, 0.696590, -1.220820, -0.736740,
0.850710, 0.235720, -1.310740, -1.290480, -0.638730, 0.105570, 0.349090, 0.553120, 1.509910, -0.985990,
-0.397670, -0.182870, -0.078940, 0.789210, 0.243800, 0.514560, -0.033160, 0.287930, 0.336950, -0.734810,
-0.806070, -0.626690, 0.390000, -0.182770, -1.292150, 1.144850, -0.561310, -0.349850, 0.507800, -1.105810,
0.810550, 0.822630, -2.567360, -0.583530, -0.949700, 0.600500, -0.592890, 0.397370, -1.145620, -1.318020,

0.314930, -1.260240, 0.691700, -1.583850, -3.386150, -1.041520, -2.048350, 2.506710, -1.242410, 0.841660,
-1.065990, -0.384050, -1.013310, -0.748290, -0.767510, -1.328000, -0.305430, -0.556390, -0.894050, 0.645620,
0.859070, -0.931080, -1.909070, 0.615260, 0.324040, -0.888200, -0.879560, -0.023610, -0.350850, 1.621580,
-0.654240, -0.787820, -0.238300, 0.290620, -0.739260, -1.324740, 0.133290, 0.144320, -0.358640, -0.643270,
0.395900, -0.678290, 0.066700, -1.449150, 0.913600, 0.134260, 0.792010, -0.433730, -0.813130, 0.325270,
1.617620, -0.138890, 0.114550, -0.276310, 0.859170, -0.188300, -0.054370, 0.444680, -0.609200, 0.209240,

-0.601380, -1.383960, -0.773080, -0.940900, -0.410580, 0.799290, -0.285900, 0.485830, -0.061140, -0.317670,
-0.457800, -0.280260, 0.101830, 0.188060, -0.403060, 0.841410, -0.339800, 0.708430, -1.179310, -0.562360,
-1.477600, -0.903970, -1.672570, 1.333190, 0.011730, -1.042420, -1.583970, 0.014380, -0.243710, 0.193600,
-0.945180, -0.303390, 0.801220, -0.998730, -0.225300, -0.487160, -0.832780, 0.222430, 0.335260, 0.039260,
-0.708050, 0.412990, -0.227740, -0.035340, 0.824510, 0.403690, 0.749190, -0.379630, 0.952560, 0.097640,
-0.234610, 0.125690, 0.816930, -1.097980, -0.631730, -0.509970, -0.497850, 0.219140, -0.998490, -0.707160,

-1.534010, 0.671020, -0.039150, -1.085850, -1.401010, -1.157550, -0.243610, 0.075940, 1.619020, 0.434350,
-1.107330, 0.653170, 1.789540, -1.028570, 0.132680, 0.677540, 0.839110, 0.748990, 2.040000, -0.115710,
0.566560, -3.631680, -2.797360, -1.827900, 1.600930, -2.934370, -0.054830, -1.166760, -1.283770, -0.559090,
-0.317470, 0.322400, 0.795710, -1.795780, -0.490890, -0.043600, -0.296960, -0.011270, 0.749480, -0.025820,
-0.267090, 0.676370, 0.882670, -0.991510, -0.349580, -0.532880, -0.941260, -0.071870, 0.911250, 0.443060,
-0.319560, 1.136550, -0.710950, -0.380530, -1.182830, -0.293450, 0.099200, 0.550250, 0.770720, 0.148600,

-0.410690, 0.480410, 0.210540, -2.733450, 0.223020, 2.425480, 3.619420, -2.235980, 0.412250, 2.897270,
3.157410, -1.686000, 0.003470, -2.149200, -0.549170, -0.406690, 1.295000, -1.513080, -0.459520, -1.442070,
1.377360, -1.329850, -0.209530, -1.611170, -1.569690, -0.403620, -0.410940, -1.502300, -0.611270, -0.113410,
-0.764180, -0.809800, -1.370950, 0.663830, -0.724130, -1.369030, -0.505250, -1.215000, -0.890810, -0.140160,
-0.187260, -0.521620, -1.322840, -0.075600, 0.566590, -2.193230, -0.368200, -1.147800, -0.753080, -0.189370,
-0.504080, -1.075700, -0.924720, -0.631240, 0.210330, -0.652690, -0.572400, -0.643930, -0.568940, 0.917850,

-1.499510, 0.291350, 0.810660, 1.209590, -0.684630, -0.552440, -2.229090, -0.657690, -0.424380, -0.255250,
0.402340, 0.709390, 0.026430, 0.046720, -1.731210, 1.056120, 1.862820, 0.956440, 0.227810, -0.594350,
0.781540, -0.454090, 0.627980, 0.759210, -1.727910, -0.897570, -1.877160, -0.545010, -0.623080, -0.341390,
0.139850, -1.823360, -0.755800, -0.344810, -2.327590, 0.629890, 0.189570, 1.413310, 0.363500, 1.284450,
-0.585080, 0.354060, 0.932370, 0.875860, -0.342730, 1.521460, 0.814970, 0.438760, -1.078050, -0.995790,
0.819310, 0.279300, -0.691700, -1.469930, -0.290420, -0.713800, -1.343180, 1.736770, -0.398170, -0.980190,

-1.687430, -0.220440, -0.166090, -0.093080, -1.741150, -0.854590, -0.808090, 0.688430, -4.178250, 1.297890,
0.346950, 0.395460, -0.622060, -0.041850, 0.493570, -0.579310, -0.913130, 0.168870, -0.304100, -1.595160,
0.430990, -0.043810, 1.251940, -1.447710, 1.870250, -0.105970, 0.849620, -0.993410, -1.368260, 0.055700,
0.201370, -0.758760, 0.310370, 1.061060, -1.493740, 0.733500, 1.234890, 0.317290, 0.965920, 0.573820,
-0.692290, 0.608610, 1.361750, 0.555810, -1.174090, -0.076110, 0.278380, -0.044880, -0.000240, -1.148810,
1.364760, -0.024050, -1.254080, -0.597140, -0.460190, -0.187680, -1.285140, -0.206130, -0.886310, -0.535920,

1.515620, -0.428500, -0.149610, 1.164630, -0.237580, -0.321540, -0.172460, -0.296690, -0.540900, -1.209890,
-0.574810, -3.224090, 0.249860, 0.297160, 2.030850, -0.297980, -2.223610, -1.278720, -0.694950, -0.327420,
-3.180140, 1.759600, -0.121740, -2.328960, -0.982190, 1.010850, -0.404770, 0.960420, 0.281870, 0.714250,
-1.506330, 1.106700, -1.224710, -1.089990, 0.328360, -0.110220, -1.070780, 0.193880, -0.034780, -0.108030,
0.548950, 0.402490, 0.553090, -0.201440, -0.848000, 0.067820, 0.228400, -0.658680, 0.066220, 0.266830,
-1.175270, 0.121460, 1.345950, -0.065660, -0.146040, 0.924540, 0.178820, 0.028940, -0.438340, 0.990810,

-3.047070, -0.801320, -0.993970, -2.879050, -0.060270, 1.689170, -4.248450, -1.439400, -1.228950, -1.174420,
-1.061760, -4.116070, 1.400660, 2.654830, 2.053570, 1.188630, 0.471460, 0.832710, -2.585250, -2.307200,
-2.713250, -0.019760, -0.253170, 1.529890, -2.835960, -2.943790, 2.690500, 0.237380, 1.215050, 0.016480,
-0.513480, 1.117230, 0.504500, -0.121470, -0.160750, -0.783380, -1.151930, 1.002620, -0.545220, 0.545680,
-0.345510, -1.053410, -1.134730, -0.769480, 0.165530, 0.831430, -0.455060, -0.129610, -0.523760, 0.307820,
-0.182950, 0.608620, -0.317870, 0.760750, 0.058510, -1.329790, 0.065290, 0.427430, -0.260950, 0.121100,

-0.981660, -2.325630, 0.622430, -1.631910, -1.523730, -1.211270, -0.801030, 0.234000, 0.829360, -0.407610,
0.000950, -0.358810, -1.489400, -0.826000, 1.060260, -0.515480, -1.145450, -0.518600, -2.076170, -0.947920,
-0.867250, 0.678640, 0.125340, -0.195000, -1.476550, 2.057420, 0.095110, -0.941440, -0.421140, 1.143520,
0.114670, 0.532270, -0.195910, -0.073420, -1.055330, 0.092060, -0.657220, -0.940190, -0.753950, 0.293800,
-0.187260, 0.208670, 0.319280, 0.271430, -0.688680, -0.439000, -1.956830, 0.262710, -0.211640, -1.151690,
-0.263330, -1.149220, 0.146500, -0.001950, 0.626480, 0.342380, 0.119400, -0.359870, -0.004780, 0.837260,

-1.554860, 0.032530, 0.198730, -0.719040, -0.396010, -0.587550, 0.823530, -1.164810, 2.082750, 0.255220,
-0.724480, -0.595040, -0.934460, -0.399030, -0.750330, 0.667220, 1.916430, -0.166380, 0.758610, 0.606770,
0.867810, 1.463720, -1.479440, -0.924340, 0.464340, -0.537600, -1.414990, -0.026500, -2.368710, 0.878790,
-0.882290, -0.290950, -1.163630, -0.320360, 0.015040, 0.981290, -1.534760, 1.142440, -0.990860, 0.010070,
-1.793970, 1.769580, -1.280020, -0.670200, -1.549020, -0.274410, 0.162680, -0.083540, 1.422460, -0.993140,
-0.411580, 1.306940, 0.606340, -0.339300, 0.317200, 0.437680, -0.459810, -0.892020, -0.841980, -0.592330,

1.903560, -0.679590, -0.800020, -0.958340, -1.788240, -0.093120, 0.343170, -1.809680, -0.124720, -2.070260,
-0.745870, 1.784070, 1.263900, -0.306760, 0.600380, 2.351920, -2.213790, -1.171270, -0.141100, 1.614150,
-2.347950, -1.292840, -0.406750, 0.480750, -0.351310, -1.010300, 2.192880, -0.445570, -0.542620, 0.408230,
1.600200, -0.050530, -0.014580, -2.195530, -1.208980, -1.706820, 0.523250, -0.648490, -0.878770, 0.624490,
-1.197180, 1.321730, -0.608650, 0.378680, 0.597040, -1.028930, 1.351370, -0.417290, 0.455500, -0.794660,
-0.198660, 0.974540, -0.629810, 0.151680, 0.715610, -0.866520, -0.579860, -0.332050, 0.465570, 1.039840,

1.833340, -1.735170, 1.799250, -0.269430, -1.884720, -3.580070, -0.728170, -0.388210, 0.566300, -0.078260,
-0.955790, -0.413850, -2.300210, -0.845130, 0.591270, -2.045600, 0.424170, -1.434870, 0.956020, -2.196050,
-1.103130, 0.272520, -0.226830, 0.956160, -2.141360, -1.435770, -0.598530, 0.633330, -0.330030, 2.656570,
-0.004090, -0.919250, 0.522530, -1.142200, -1.460510, -0.402370, -0.212810, 0.810070, 0.206220, -0.391000,
-0.340840, 0.030070, -0.351150, 0.125940, -1.152250, -0.546050, 0.613150, -0.399930, 0.415560, -1.382050,
0.517270, -0.534430, -0.783510, -1.711040, 0.736180, -1.177930, 0.648690, 0.671730, -0.192780, -0.064790,

-1.396170, -0.313680, 3.353630, -0.728200, -2.348670, 1.259160, 0.042700, 0.831750, 0.276680, -2.942370,
-1.888280, 0.408700, -0.435160, -0.979300, -0.733290, -2.575720, -1.004920, -0.972830, -0.595740, -2.780930,
0.849180, -2.794030, 2.120700, 0.527900, -0.332620, 2.314670, 1.701820, 0.804820, 1.505930, 2.033190,
-0.091050, -0.068250, -0.072460, 0.831250, 1.050550, -0.540370, 1.310250, -0.656990, -0.757910, 0.053990,
-0.228260, -1.919590, -0.185700, 0.539170, -0.580250, -0.268130, 0.411830, 0.026690, -0.107300, 0.584490,
0.790410, -0.712010, 0.169940, -1.111380, -0.146540, -0.684830, 0.286010, -0.630670, 0.344280, 0.209510,

3.045800, -0.172700, -1.498000, -0.911740, -1.497970, -2.883630, 0.880410, 3.048560, -0.563280, 0.700540,
-0.760510, 0.353110, 0.394150, -2.065520, -1.909760, -1.220370, -2.134450, -1.698380, -1.099320, -1.897680,
-2.199410, -2.898970, -0.810900, 0.889960, -0.721920, -1.696670, -0.402750, 2.411750, -2.401300, 0.866980,
0.014890, 0.543220, 0.280540, -0.645940, 0.629760, -0.858740, -1.452810, 0.748750, 1.037360, -0.315910,
-0.391800, 0.157030, 0.221990, 0.270520, -0.202190, 0.394370, -0.056710, -0.386110, -0.666210, -2.636210,
1.108370, -0.012080, 0.126410, -0.030190, -1.078340, -0.451430, 0.201020, -1.169150, -1.028880, -0.592960,

-0.670560, 1.411560, 1.077330, -0.860030, 1.440680, -0.537250, -1.093470, -1.651300, -0.659180, -1.646470,
0.729040, -1.185540, -1.868770, -1.062330, 2.295570, -0.388710, 1.270540, -1.444570, -0.993230, 0.791150,
-0.293870, -0.689370, 0.546750, 1.023640, 1.635560, -0.901210, 0.753150, -1.586420, 0.481330, 1.674500,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
  static UnitType Units[391] =
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (inp1) */
      0.0, -0.621030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.119770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.435930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.194800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.737700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.813780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.133960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.852870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.866800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.634090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.468630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.652310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.161580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.778180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.360820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.007850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.592730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.171250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.284970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.398470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.686000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.000580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.292170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.230070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.026000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.125690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.512350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.543850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.292790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.999430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.680930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.549080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.621880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.819160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.669230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.012450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.382920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.027250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.147080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.891740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.481550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.067950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.590290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.414360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.815480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.002370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.392060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.187200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.536190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.221880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.373300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.296660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.553690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.192720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.319910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.127820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.241930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.861650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.540100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.806410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.723890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.338740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.922520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.154140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.255650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.492710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.805270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.011530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.295740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.919150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.505450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.580450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.788070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.638800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.504200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.612290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.711030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.833730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.014010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.638070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.273950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.970190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.087420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.992490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.925010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.791040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.419920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.167180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.789690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.690160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.095280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.818080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.578650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.136670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.106520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.102440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.592550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.054360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.099160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.165370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.854050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.440170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.007610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.294190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.834330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.353100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.207910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.168230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.321520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.771220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.700180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.601710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.167770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.256410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.360740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.239070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.470260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.148080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.205420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.242780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.840880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.834010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.480530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.768660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.778260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, -0.262960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, 0.520070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.160910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.998520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.529230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.570890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.611350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.877390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.147850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.300890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.728570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.468910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.207230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, 0.448680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.075790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.789190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.380470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.124060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.664380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.520050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.123680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.005460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.291740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.071480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.472270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.066420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.315620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.177540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.667080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.784640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.119820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.883930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.439290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.902160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, 0.741590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.987090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.086130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.633090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.702100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.281250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.625400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.354110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.758850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.966800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.064150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.506220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.684180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.143410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.633350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.352720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.516580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.994350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.646360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.931780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.477550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.960160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.553320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.670490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.229870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.960980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.412570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.567530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.144040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.957380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.664100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.741310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.010860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.672140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.185440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.987970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.798940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.864840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.781580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.580210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.005910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.223170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.166880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.211810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.922480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.553670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.467030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.964170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.292530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.345670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.528270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, 0.646680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.262640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.921100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, -0.149240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.627610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.418400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.469730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.792570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.133430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.391530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.049200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.333970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.374640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.983870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.235560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.689450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.452830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.192610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.177500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.133440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.540330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.702340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.464400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.378630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.717160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.177900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.110690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.977290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.131700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.593610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, -0.282770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.326810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.167080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, -0.609150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.807210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, 0.949240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.680910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.335430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, -0.587910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.165460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.951860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.416460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.314550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, 0.470890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.416480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.011960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, -0.019120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.355210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.232940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.544980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.848830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, -0.843820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.147520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.502400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.342860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.667980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, -0.375420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.186900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, -0.198660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, -0.825010, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -0.626050, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, 1.237090, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, 0.945820, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, 1.046540, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -1.783900, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.290180, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.950960, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.104920, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.515530, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.845080, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.904480, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -1.779750, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, -0.617570, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, -0.018930, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -1.112620, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.342510, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 0.269230, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -0.205520, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, -0.524850, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 0.215630, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.213510, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, 1.480460, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.466150, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, -0.427280, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.002190, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.737230, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.792560, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -1.072170, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.086380, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -1.357510, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, 0.544740, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, -0.737950, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, -3.818960, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -1.271960, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, -1.599140, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, -0.096130, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, -1.741240, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -2.063190, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, 0.023390, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, -2.143160, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, -2.720040, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -2.416210, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, -0.485730, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.805820, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -3.934740, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, -0.811270, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, -0.031770, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, -1.048130, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -1.597360, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, -0.210440, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, -1.122500, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, -0.292760, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, -1.323960, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -1.619100, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -2.647140, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -2.105540, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, -1.747700, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, -2.440360, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.292160, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, -0.539380, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
1.28496, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.00785, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.39321, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
1.27862, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
1.32263, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
0.93410, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
0.41775, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
0.09860, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
1.00141, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
0.00557, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.43799, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
1.10338, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
0.09245, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
1.10099, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
1.11521, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
1.38236, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.03724, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
1.10510, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
1.33547, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
1.33538, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
1.34134, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
1.29294, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
1.31890, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
0.00261, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.33589, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
0.31123, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
1.41736, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.33637, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.11662, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
1.41730, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
0.28711, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
0.03295, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
0.00201, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
0.12764, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
0.00075, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
0.00629, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
0.00189, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
0.00129, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
0.02987, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
0.00010, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.00491, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
0.00429, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.00391, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
0.00568, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
0.00014, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
0.02090, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
0.00005, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
0.00258, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
0.00935, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
0.00370, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
0.00888, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.00264, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
0.25123, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
0.00209, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.00033, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
0.06080, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
0.33987, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
0.00010, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
0.10213, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
0.00137, 0.500000, 2,
       &Sources[10918] ,
       &Weights[10918] ,
      }

  };



int net(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[269] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100, Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110, Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120, Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130, Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140, Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150, Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160, Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170, Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180, Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190, Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200, Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210, Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220, Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230, Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240, Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250, Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260, Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269}; /* members */

  static pUnit Hidden1[30] = {Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279, Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289, Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299}; /* members */

  static pUnit Hidden2[30] = {Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309, Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319, Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329}; /* members */

  static pUnit Output1[1] = {Units + 330}; /* members */

  static pUnit Special1[1] = {Units + 331}; /* members */

  static pUnit Special2[1] = {Units + 332}; /* members */

  static pUnit Special3[1] = {Units + 333}; /* members */

  static pUnit Special4[1] = {Units + 334}; /* members */

  static pUnit Special5[1] = {Units + 335}; /* members */

  static pUnit Special6[1] = {Units + 336}; /* members */

  static pUnit Special7[1] = {Units + 337}; /* members */

  static pUnit Special8[1] = {Units + 338}; /* members */

  static pUnit Special9[1] = {Units + 339}; /* members */

  static pUnit Special10[1] = {Units + 340}; /* members */

  static pUnit Special11[1] = {Units + 341}; /* members */

  static pUnit Special12[1] = {Units + 342}; /* members */

  static pUnit Special13[1] = {Units + 343}; /* members */

  static pUnit Special14[1] = {Units + 344}; /* members */

  static pUnit Special15[1] = {Units + 345}; /* members */

  static pUnit Special16[1] = {Units + 346}; /* members */

  static pUnit Special17[1] = {Units + 347}; /* members */

  static pUnit Special18[1] = {Units + 348}; /* members */

  static pUnit Special19[1] = {Units + 349}; /* members */

  static pUnit Special20[1] = {Units + 350}; /* members */

  static pUnit Special21[1] = {Units + 351}; /* members */

  static pUnit Special22[1] = {Units + 352}; /* members */

  static pUnit Special23[1] = {Units + 353}; /* members */

  static pUnit Special24[1] = {Units + 354}; /* members */

  static pUnit Special25[1] = {Units + 355}; /* members */

  static pUnit Special26[1] = {Units + 356}; /* members */

  static pUnit Special27[1] = {Units + 357}; /* members */

  static pUnit Special28[1] = {Units + 358}; /* members */

  static pUnit Special29[1] = {Units + 359}; /* members */

  static pUnit Special30[1] = {Units + 360}; /* members */

  static pUnit Special31[1] = {Units + 361}; /* members */

  static pUnit Special32[1] = {Units + 362}; /* members */

  static pUnit Special33[1] = {Units + 363}; /* members */

  static pUnit Special34[1] = {Units + 364}; /* members */

  static pUnit Special35[1] = {Units + 365}; /* members */

  static pUnit Special36[1] = {Units + 366}; /* members */

  static pUnit Special37[1] = {Units + 367}; /* members */

  static pUnit Special38[1] = {Units + 368}; /* members */

  static pUnit Special39[1] = {Units + 369}; /* members */

  static pUnit Special40[1] = {Units + 370}; /* members */

  static pUnit Special41[1] = {Units + 371}; /* members */

  static pUnit Special42[1] = {Units + 372}; /* members */

  static pUnit Special43[1] = {Units + 373}; /* members */

  static pUnit Special44[1] = {Units + 374}; /* members */

  static pUnit Special45[1] = {Units + 375}; /* members */

  static pUnit Special46[1] = {Units + 376}; /* members */

  static pUnit Special47[1] = {Units + 377}; /* members */

  static pUnit Special48[1] = {Units + 378}; /* members */

  static pUnit Special49[1] = {Units + 379}; /* members */

  static pUnit Special50[1] = {Units + 380}; /* members */

  static pUnit Special51[1] = {Units + 381}; /* members */

  static pUnit Special52[1] = {Units + 382}; /* members */

  static pUnit Special53[1] = {Units + 383}; /* members */

  static pUnit Special54[1] = {Units + 384}; /* members */

  static pUnit Special55[1] = {Units + 385}; /* members */

  static pUnit Special56[1] = {Units + 386}; /* members */

  static pUnit Special57[1] = {Units + 387}; /* members */

  static pUnit Special58[1] = {Units + 388}; /* members */

  static pUnit Special59[1] = {Units + 389}; /* members */

  static pUnit Special60[1] = {Units + 390}; /* members */

  static int Output[1] = {330};

  for(member = 0; member < 269; member++) {
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

  for (member = 0; member < 1; member++) {
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

  for(member = 0; member < 1; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}
