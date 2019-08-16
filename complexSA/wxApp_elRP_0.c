/*********************************************************
  Pfam_elRp_0_forceW7new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:06:27 2004
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
0.507990, 0.465020, -0.497430, -2.439780, -0.136190, -0.178700, -0.080060, -0.440820, -0.425840, -0.623800,
-0.211010, -0.520210, 0.918410, 0.683750, -0.357720, -0.975630, 0.627420, -0.551410, 1.174500, 1.129980,
0.654480, -0.771390, 0.783570, 1.017370, 0.639410, -0.682250, 0.578860, 0.243510, -0.082210, -0.460900,
-0.657420, 0.004940, 0.005690, -0.434260, -0.928440, -0.933390, 0.701080, 0.609630, -0.787400, -1.003660,
-0.098140, -0.347560, 0.267100, 1.404330, 0.312060, -0.133460, 1.068170, -1.775010, -0.800370, -0.894730,
0.900860, 1.437180, -1.051000, -0.396500, 1.424920, -0.083130, -0.560980, -0.994610, 0.065380, 0.451170,
-0.600990, -0.220260, -1.473230, 0.761520, 0.491680, 0.085410, 0.006580, 0.028990, 2.919610, -1.606890,
-1.537340, -0.358370, -1.245600, -0.508500, -0.282160, 1.376800, -0.376130, -0.861260, 1.372500, -0.678040,
0.186990, 0.093750, -0.998850, -0.303010, 1.367870, -0.391300, -0.627080, -0.144300, -1.208470, 0.444530,
0.096540, 1.467480, -0.286690, -1.201430, 0.912520, -0.709070, 0.556650, -1.563760, 0.036980, 0.349030,
0.285250, -0.611170, 0.644060, -0.092240, -0.136010, -0.747640, 0.721660, 1.450130, -0.900150, 0.831540,
-0.587280, -0.149990, 1.322330, 0.292100, -0.551620, -0.506940, -1.669750, 0.981290, -1.245430, 0.739880,
0.180130, 2.047450, 1.619550, -0.452570, 0.238250, -0.336430, 2.217320, 1.368410, -0.533860, -0.661270,
1.720620, -0.250260, -3.534620, 0.320780, 2.018210, -5.178310, -0.371500, 3.216430, -0.694240, 0.038770,
-3.365440, 2.152900, 0.124330, -0.793930, -0.163150, 0.136690, 0.025730, 0.516680, -1.672290, -0.860910,
-0.304760, -0.671310, -1.368880, 0.626790, -0.028490, -1.197080, -0.431210, -0.220920, 0.783710, -0.968970,
1.580720, -0.753440, -0.395240, 1.365070, 0.126470, -0.856760, 0.969810, -0.619670, -0.487580, 1.073600,
0.167300, -0.504190, -0.522930, -0.905870, -0.134020, -0.438480, 0.977510, -0.486240, -1.140630, -1.162280,
0.645700, 0.832360, -0.304920, 0.659420, 0.596690, -0.783840, 1.204240, 0.184400, 0.868050, 1.270740,
-0.343290, 0.382610, -0.264990, -0.995440, -0.109550, 0.038290, -0.052310, 0.926540, -1.364730, -0.191340,
-0.101930, -1.193070, 1.645340, -0.680700, -0.898210, 0.732270, 0.777670, 0.357750, -0.859440, 0.599590,
0.404670, 0.353950, -1.273390, -0.515970, -0.851630, 0.426400, 0.296790, -0.936680, -0.510690, -0.711690,
-0.593230, -1.098600, -0.912010, -0.194490, -1.109720, -0.640550, -0.691080, -0.188330, 0.441090, 1.591750,
0.168550, -0.476790, 0.504090, 0.160270, -0.981360, 0.759120, -0.297510, -0.865680, 0.174770, 1.018990,
-1.024700, -0.133700, -0.899300, 0.732830, 0.370940, -0.002240, -0.678890, 0.190560, 0.238020, 0.613160,
-0.933310, 0.800610, -0.286500, -0.651850, -0.613090, -0.860250, -0.811340, -0.932650, -0.317210, 0.776130,
0.696160, 0.779900, 5.648490, 1.855230, -1.407940, -1.143600, 0.124080, 1.840780, -0.166470, 0.636210,
1.375400, -0.118530, 0.631350, 1.361790, 1.386380, -0.278030, -0.097470, 0.535500, -0.229870, -0.481480,
0.636690, 0.308410, 0.641260, -0.106980, 0.513460, 0.785410, 1.303720, 0.652790, 0.669840, 0.910890,
-0.004570, -0.422150, 0.398150, -0.487210, 1.350730, 1.243880, 0.735190, 0.697740, 0.584400,
-0.873590, 0.750810, -1.593230, -0.472540, -0.799830, 0.732720, -0.980210, -1.970560, -1.239440, -2.252850,
-0.700800, 0.594830, 0.295020, -1.235450, -0.146950, 0.686010, 1.919000, -0.498070, 0.449580, -1.119070,
-0.710550, 1.043640, 0.669980, -1.470770, -0.502660, -0.923500, 1.189010, -0.207730, -0.378050, 1.016910,
-1.162390, -0.436970, 0.968460, -0.767430, -0.131190, 2.227120, 0.580250, -0.071900, -2.927270, -0.526750,
-0.156820, 2.048050, 0.160320, -0.225060, -1.409300, 2.634010, 1.308410, -1.144380, 2.605650, 0.363800,
0.600530, 0.824640, 0.107160, 1.674650, 1.406240, 3.961230, -1.295390, 0.299040, 0.471510, 0.313710,
0.590410, -0.558830, 0.373110, 1.096280, 0.936010, -0.863630, 0.249050, -1.042360, 0.411370, 0.504750,
-0.054900, 0.627080, 1.658070, -1.790710, -0.027960, -0.338770, -1.594920, 0.286610, -0.206080, 0.377970,
-1.158780, 0.244900, 1.330220, 0.796510, -1.597830, 1.020930, -0.185980, -0.082730, -0.767370, -1.203270,
-1.875270, 2.427380, 1.358440, -0.606810, 1.216140, 1.329800, 0.779160, 0.836870, 0.020680, 0.222060,
-0.391970, -1.087150, 0.965780, 0.149440, 0.377160, 0.050660, 0.590260, 0.249230, -0.755730, -0.211430,
-0.467120, -0.518330, 1.008330, 0.893200, 0.027120, -0.168050, 1.790430, 0.877600, -0.005400, 1.117450,
0.118200, 0.505080, 3.089060, 0.375810, 0.709930, -0.400060, -2.022720, -0.381920, 1.264340, 0.935650,
-1.586290, -0.607420, 0.675480, -1.268740, 0.345220, -0.640900, -1.427550, -0.858650, 0.983250, 1.417060,
0.306980, 2.576030, 0.568460, 0.324050, 0.831910, 0.836970, -0.723040, -1.389180, 0.962790, 0.337810,
0.039090, 1.587000, 0.430540, 1.864900, 0.676360, 0.562200, 0.716940, -0.612060, 0.117240, 0.585710,
-1.201050, -0.820440, 1.981050, -1.418750, -0.326320, 2.047290, -0.513460, -2.223970, -0.161860, -0.582200,
0.428690, 0.545440, 0.657950, 1.273880, 3.898960, 1.158450, 0.807190, 3.461310, 1.195640, 0.245030,
0.715670, 0.347960, 2.104390, -0.598990, 0.125830, 1.557820, -0.400890, 0.948140, 0.276900, -0.562300,
-0.672850, 1.994750, -1.411930, 0.968740, -1.584670, -1.348800, 0.161640, 0.947060, 0.229890, -3.367910,
-0.161980, -0.622900, 0.305870, -1.247100, -0.760790, 0.252890, -1.974470, -0.114740, 1.166590, -0.933210,
-3.734720, -0.395400, -0.077580, -0.521790, -0.937250, -0.314420, 0.895550, -0.014080, 1.645240, 1.896270,
-1.469940, 0.292510, -0.327540, 0.530160, -0.329900, -0.048640, -1.181000, 1.298830, -0.911860, -1.116110,
1.340720, 0.467860, -0.684620, 0.386980, 1.254030, 0.357160, -0.379940, -0.295090, 1.514290, 0.714010,
0.495980, -0.255920, 0.463510, 0.264010, -0.025610, -0.216790, 0.042750, 1.313770, 0.854800, -0.706170,
-0.112890, 1.912950, -0.626480, -5.316360, -0.307250, -0.127560, 0.186950, 0.025460, -1.134100, 1.714720,
3.033510, 1.052220, -1.416000, -0.340020, 1.642790, -0.982860, -0.848480, 0.819250, -0.239360, -0.401630,
-1.305770, -0.331240, -0.295840, -1.298360, -0.274750, -0.091780, 0.146220, -0.830510, 2.255020, -0.989950,
-0.481430, 0.106870, -1.068880, -1.135410, 0.388670, 0.078450, 1.011400, -0.026560, 0.035090, -0.522790,
-0.489510, -0.305560, -1.184330, -0.657630, 0.555680, -0.838780, -0.387630, 0.224010, -0.759400,
-0.592470, -0.058440, 0.748790, -0.417470, 1.175170, 0.722660, -6.450580, -0.725110, -0.350490, 1.268370,
0.198670, -1.109860, -0.863580, 1.165000, 1.638080, 0.287320, 0.407410, 0.039980, -1.829970, 0.159720,
1.471680, -1.264910, 0.588100, 1.161230, 0.364310, -1.661760, 0.122400, -1.370550, -0.413380, 2.872550,
0.377560, -1.441480, -2.067920, 1.018330, -0.491870, -2.487930, -0.133130, -1.420090, -1.117730, -0.306910,
-1.602860, 0.346270, -1.086810, -0.699490, -0.566300, 1.104080, 0.901190, -0.809690, -3.005210, -0.512470,
-4.048890, -0.652210, 0.477480, 0.908230, -3.083310, -3.868890, -0.630290, -2.098630, -1.851140, 0.852030,
-1.218780, -0.486990, -0.832980, -1.658880, -0.413490, -0.788350, -0.658360, 1.303320, -0.878090, -0.744420,
-1.070870, 0.374220, 0.031920, 0.577740, -0.067400, 0.811220, 0.288020, -0.180990, 0.566630, 1.166610,
0.914920, 1.896960, -0.815430, -0.649340, -1.165810, 0.552610, -1.052640, 0.351830, -0.239260, 2.194000,
-1.325260, 0.508980, -0.331280, 0.684170, 0.226200, -0.627470, -0.522680, -0.833880, 0.829630, 0.035470,
-0.350290, -1.421980, -0.591840, 1.211510, 1.802340, -0.021600, 0.134720, -0.740100, 1.493540, -1.071150,
1.211660, -0.147130, 0.237130, 1.145400, -0.281080, -3.836930, 0.166210, -4.902230, -0.908150, -1.853080,
-0.469610, 1.384850, -0.449630, -2.741050, -1.913070, 1.820170, 0.383010, -1.272150, -4.029670, -1.085780,
-1.028330, 2.162670, -1.290570, 0.449210, 0.385860, -1.736970, 1.801870, 4.553360, 0.909160, 0.081120,
-2.057620, 1.201640, -0.889790, 0.193160, 0.218330, 0.913370, -2.222720, -0.281490, 0.072990, 1.302780,
-0.974150, 0.590370, 0.802440, 0.861980, 0.655000, 1.459390, 0.115580, -0.189300, 0.177610, -0.462780,
-0.081580, 0.355450, -0.401010, -0.129190, -0.792630, 0.673400, 0.792820, -0.267830, -0.661430, 0.033030,
-0.701420, -1.501260, -1.250210, -1.249060, -0.036150, 1.486170, 0.161510, -0.799260, 0.719010, -0.065730,
-0.055480, 0.132830, -0.356150, -0.769000, -0.191820, 0.876310, -0.491080, -0.160030, -1.160820, 0.116220,
-0.311530, -0.728810, 0.210440, 0.412330, -0.255490, -0.518330, -0.640060, -0.494840, -0.636510, 0.575410,
-2.229220, -0.028490, 0.180540, -0.086550, 1.052460, 0.595570, -0.783070, 1.073140, 0.105900, -0.190880,
0.191300, -1.323030, 0.870970, 1.585870, -0.342280, -0.048380, 0.150530, -0.117380, -0.446760, -1.474690,
1.153810, -0.315980, -0.544400, 0.615680, -1.278890, 0.475150, 0.903160, -0.590810, 1.465250, -0.357210,
1.023680, -0.079090, -0.115180, -1.509440, 0.320710, 0.013260, -0.707150, 1.856560, 1.462200, -0.652990,
1.413530, -0.298570, 0.444590, 1.701200, -0.287040, -0.594670, 0.016330, 0.164210, 0.270540, -0.418970,
1.119390, -0.574730, -0.340620, 4.783120, 0.978710, 3.143920, -1.125580, -0.080800, -2.598100, -0.308650,
1.522000, -0.177960, 0.473110, -0.656410, 0.553300, -0.860620, -0.218240, -0.651050, -0.495610, -0.639160,
0.765820, 0.621300, -0.856140, -0.383870, -0.634620, -0.180920, 0.895600, 0.397310, 3.015760, -0.976200,
-0.515240, -0.418610, 0.426050, 0.794550, 0.732160, 0.536340, 0.302240, -0.468870, 0.473910, 0.316990,
-0.552350, -0.815060, -0.929370, 0.270250, -0.169850, 1.171330, 0.825110, -0.109150, -0.276430,
-1.110300, 1.161880, -1.062070, -0.473790, 0.746410, -0.490620, 0.244100, -0.245210, 1.377300, 1.952240,
-0.618410, 0.000870, 0.145660, -0.710650, 0.093720, -0.947320, -0.047130, -0.781440, -0.303070, 1.077730,
-0.704010, 0.203800, 0.757700, 0.057780, 0.727150, 0.904440, -0.597510, -1.409320, 1.216990, -0.717840,
1.361180, 4.165030, -0.704370, 0.248360, -1.878420, -0.338970, 0.744730, -0.570330, -0.191680, -1.001170,
2.789230, 0.426850, 1.005580, 0.434630, -0.436130, 0.486220, 0.030380, -1.093220, 0.621210, 1.177180,
3.677970, 1.072890, -1.772130, -0.131700, 3.762870, 2.703790, -0.106460, 0.155440, 0.719620, 0.440870,
0.534530, 1.111170, 1.173340, 0.482470, 0.858350, 0.368890, 0.996790, -0.157650, 0.602230, 0.523140,
1.696700, -0.382960, 0.846200, -1.001530, 0.130850, -0.877010, -1.031790, 0.107880, 0.248000, 0.835100,
-1.687240, -0.439990, 0.393580, -0.861610, 0.103410, -0.237540, -0.819580, 0.058430, -0.566290, -0.424020,
0.018020, -1.020130, -1.254490, 1.562110, 0.846180, 1.328950, 0.225650, 0.982860, -0.022460, 1.410280,
-1.271810, -0.612820, 0.384100, -0.705120, -2.224870, 1.038630, -0.590630, -0.887120, -1.217140, 1.483910,
-0.453740, -0.628670, -1.236980, 1.808820, -0.973540, 1.478490, 4.082780, 1.694590, -1.689210, 2.102730,
1.122000, -1.316750, 3.614190, 1.815020, 1.198280, -2.514410, -2.007620, -3.646450, 6.850940, -1.363640,
-4.331050, -1.615500, 2.903940, -1.997870, -2.297730, 13.221210, -1.871800, 0.626350, -0.852120, -0.810800,
-0.199190, 0.594120, 1.386960, -0.114350, -1.915320, -0.360660, 0.067170, 0.729200, 1.531220, -0.047970,
0.497990, -1.138370, 0.327650, -0.941750, 0.094620, 0.929100, -0.348200, -0.196340, 0.840230, 0.324320,
0.137540, 0.727160, 2.288300, 0.765800, -5.392580, -0.237120, -1.522150, -0.768190, 1.004230, -0.323770,
0.098420, 2.119370, 2.003850, 0.168160, 0.321530, -0.406860, -0.591650, 2.232180, -0.786920, 0.565980,
-0.829650, -1.526680, 3.465390, -0.358730, 0.022170, -0.545620, 0.861350, -1.422010, 0.305070, -1.798210,
1.837380, 1.433770, -2.230110, 1.116220, 0.133490, -0.019390, -0.528130, -0.863280, -0.829700, -1.437710,
-0.651210, 3.481180, 0.019140, 0.867130, -0.606510, -0.229380, 0.967870, -2.860040, 0.743280, -0.403860,
-0.306650, -2.343270, 0.830960, 0.632610, -1.033600, 0.622520, 0.103660, 0.969800, 1.051930, -0.791170,
-1.930000, -0.011030, -0.419180, -0.687460, 0.875170, 0.138740, -0.024940, -0.641910, -0.304670, -0.944140,
-0.720800, -0.431620, -0.223570, -1.838480, 1.579840, 1.062640, 0.834690, 0.373550, -1.595530, -1.127010,
-0.884330, 0.629420, -0.886290, -2.882910, 0.992130, -0.187140, -0.741560, 1.018220, -0.057440, 0.189550,
-0.780600, 1.318850, 1.445130, -1.187530, 1.109000, 0.938550, 0.211390, -0.971210, -0.760210, -0.511150,
-0.348870, 1.158490, -2.682510, 0.509550, 0.871330, 0.744980, -0.524000, -1.178140, -0.193050, -0.598730,
-1.097140, 0.966700, 0.738930, 0.839780, -0.758120, 0.590750, -0.820260, 0.367450, -0.345990, -0.382110,
-0.554780, -0.096080, 0.467410, 0.436700, -0.831070, -0.524100, -0.472030, -0.326310, -0.328130, 0.748930,
0.090470, 0.848960, -0.228450, -0.896210, 0.844610, -0.274220, -0.095320, 0.195120, 0.154270,
0.384100, 0.470750, -0.183000, -0.804520, -0.881930, 0.178120, 0.109660, -0.891360, 0.092010, 0.107330,
-1.428340, -0.850560, -0.967360, 0.854140, -3.093100, 0.315550, 0.100500, 0.144380, -0.775760, 0.661970,
0.480160, 0.474530, -0.010650, -0.336380, 0.053430, 0.368500, -5.485890, -1.201140, -0.304860, 0.564930,
1.241750, 0.031930, -1.074000, 0.544540, 1.413060, 0.756600, -0.230730, 1.312810, 0.528320, -0.703850,
-0.468870, 0.508400, -0.619490, 0.581420, 1.051070, 0.314350, -0.128680, -0.182980, -0.363120, -0.014910,
0.360700, -0.284870, -1.047090, -0.049130, 0.314680, -0.050520, -1.550590, 0.249200, 0.200190, 0.725040,
-0.890610, -1.807410, 0.729420, 2.294420, -0.402980, -1.646210, -0.241850, 1.214590, -0.037370, -0.035700,
2.429300, 0.246660, 1.254360, 1.473730, -0.266210, 0.010720, 1.020020, 1.205210, 0.683230, -1.173390,
0.516890, 0.546780, -0.525060, -1.585220, -0.141960, -1.024040, 1.837800, -0.155420, -0.001180, -0.391220,
-1.050980, -0.791030, 0.042910, -2.693860, 0.816800, -7.864950, -0.503740, -1.233850, 0.826580, -0.911060,
-0.434590, -0.578280, -0.905480, 1.378020, 0.618710, -0.118820, -0.666880, 0.983270, -0.018500, -0.382520,
0.717610, -0.508550, 0.415830, -0.995620, -0.877240, -1.586010, 0.186030, 1.117260, 0.321660, -2.088760,
-1.327840, 0.838650, 0.888810, -1.450450, -0.968700, -0.247230, 2.467250, 0.611170, -3.576750, 0.328430,
0.820200, 1.924410, 0.186420, 2.626180, 2.094190, -1.499440, 2.051810, 1.028460, 0.486390, -1.078650,
1.789410, 0.139090, 0.966890, 1.664340, 0.084010, 1.164910, -0.083670, -0.646220, -2.387100, 0.473220,
-0.036340, -0.965900, -0.820580, -0.478080, 0.697650, 0.618440, 0.321120, -0.586850, -0.572960, -0.063950,
1.327750, 0.604030, -2.960280, 0.386620, 1.305620, -2.970590, 0.456580, -0.124100, -0.685670, 0.788920,
0.742480, 0.409150, 0.701520, -0.467850, 0.585010, -2.534090, -0.238200, -0.702540, -0.502030, 0.300720,
-0.795100, -0.814770, 1.421170, 0.300230, 0.764610, -1.838100, -0.199330, 0.680940, -0.560340, 0.042560,
0.066580, 0.558790, -1.050010, -0.147320, -0.554270, 1.021260, -0.293910, 0.694570, -0.707100, -0.236360,
0.062450, 1.056990, -0.483700, -0.435200, 0.475910, -0.732640, 1.537860, -0.176010, -0.631990, -0.258070,
-0.084510, -0.876590, -0.984040, 1.777470, 0.343020, 1.185860, -0.030360, -0.851870, 1.381790, 1.055880,
-3.956890, -2.652810, -2.311250, 0.347200, -0.616930, 3.591660, 0.843800, -1.294670, 0.039600, 0.744640,
-0.222070, 1.995520, -1.573640, 0.870860, 1.034490, 1.919890, 0.741360, 0.417300, -1.841510, 0.095910,
-0.704820, 0.045270, -2.266120, -3.252340, 1.217310, -1.963440, -1.228950, -0.078170, -1.181400, 0.976230,
1.933080, -0.921460, 0.220990, 51.858700, 0.464010, 0.065100, 0.465270, 2.038720, -0.548270, 0.057800,
-1.528810, -3.432000, 0.312880, 0.306110, -0.956210, -0.735380, 0.512610, -0.878070, 0.947230, -0.219830,
-0.033790, 0.012490, 0.892570, 0.209210, 0.498630, 0.170600, -0.206770, 1.382640, -1.608180, 0.998260,
-0.162240, 0.526370, 0.272290, 0.925840, 1.716720, -0.104370, 0.215740, 0.369180, -0.736570, -0.130000,
0.698170, 1.230580, -0.006950, 0.116590, 0.145300, -0.229200, 1.270780, -0.209730, 0.789740,
1.082530, 0.680190, 0.041810, 0.472320, 1.474390, 0.773420, -0.115590, 0.881460, 0.996670, 1.460100,
-0.057560, -0.603110, 0.629040, 0.105800, 0.353490, -0.990760, 0.267740, -0.477510, -0.968240, 0.379100,
0.755350, -1.353630, -0.335820, -0.426470, -0.301630, -0.065070, -0.222320, 0.687900, -0.672080, 0.621860,
-1.027450, -0.568010, -0.030440, 0.206890, -0.136840, -0.320120, 0.490890, -0.408070, -0.689970, 0.341860,
-0.701610, 1.345360, 1.154800, -1.380720, 0.399520, -1.217230, 0.484180, -0.876240, -0.279120, -0.915280,
-0.382010, -0.926580, 0.974420, -1.569920, -0.206290, -0.457540, 0.017420, -0.422210, -0.113660, 1.148960,
0.718540, -0.545630, -0.416550, -0.319790, -0.453660, -0.070370, -0.541180, -0.844820, -1.225300, -0.532040,
1.318520, 0.263650, 0.621950, 1.158120, 1.152230, -0.900650, 3.634410, -0.503620, 2.567130, -0.031430,
1.156130, 1.804170, 0.921820, 0.794600, 0.572440, 0.447410, 0.008810, 0.329430, 0.517970, 1.179500,
-0.816090, -0.031740, -1.114950, -0.182830, 0.095260, -0.698480, 1.182850, 1.159420, -0.685480, 4.948210,
0.558880, -0.206470, 0.392780, -0.837380, -1.838360, -0.034800, -0.757460, -1.805470, -1.021380, -0.220830,
-0.305280, 0.891980, 0.530250, 1.204640, -0.232470, 0.767730, 0.401820, 0.774750, -2.174840, 0.019200,
0.062620, -0.198870, -0.190060, 0.989250, 0.429900, 0.475460, 0.291160, 2.121470, -0.671390, 1.340660,
5.841830, -0.169650, 0.618910, -0.179730, 0.879000, -0.385040, 0.782320, -0.200020, -0.315340, 2.696580,
-1.461160, -1.175800, -1.127310, 0.021220, 0.914060, 2.881800, -0.695650, -0.645170, 0.213540, -0.805180,
0.437940, 0.134090, -0.633760, -0.566800, 1.212260, -1.081940, 0.368680, 0.108210, -2.393020, -0.571220,
0.302250, 0.633060, -0.025800, -0.901500, 0.334280, -1.646880, 3.650790, 1.633140, -0.133620, 0.838840,
-0.242510, 0.705990, 1.204370, 0.404720, -0.228570, -0.521080, 0.454990, 1.023940, -0.716090, 1.053230,
0.946070, 0.509810, 0.078630, 0.037970, -0.375020, 0.539260, 0.103240, -0.729000, 0.272410, 0.401530,
-0.856540, 0.041840, 0.454270, 0.526720, 0.674590, -0.938070, -1.159750, -0.451840, -0.038830, 0.139490,
-0.503650, -0.188410, 0.743510, -0.108020, -2.959820, 0.331050, -0.231130, -0.696150, 1.466120, 1.028960,
0.594340, 0.222490, -0.231490, 0.173880, 0.696820, 0.899510, -0.149410, -0.481730, 0.690790, 1.610340,
0.256910, 0.951010, 2.212990, -0.386070, 0.976700, 0.383290, -0.932210, 0.399680, -0.906750, -0.502280,
0.194150, -1.127280, 1.591210, -0.295890, -0.173800, 0.249490, -0.686060, 1.162590, -0.301240, 1.448550,
0.076640, -0.009820, 1.530210, -0.251390, -1.539540, -0.897190, 0.123920, 0.360950, -0.931450, -0.349800,
3.851940, 0.825640, -1.095650, -0.797480, 0.004820, 1.420460, 0.508660, 0.731700, 0.402740, 2.551380,
3.836380, -0.280560, -0.654080, 0.366230, -1.451230, 4.639830, 0.504210, 0.061600, -0.321590, 1.029710,
1.479110, 1.137710, 0.686130, 0.907550, 0.256210, 1.502770, 0.062200, 0.540970, 5.018700, 0.820570,
-0.190630, -0.324830, 0.712500, 0.130540, 1.165330, 0.583010, 0.729790, -0.414400, 0.059900, 0.066900,
1.519870, 1.492460, -0.459650, 0.665020, 0.464160, 0.052910, 0.483840, 1.731090, 1.357090,
1.219580, 0.697280, 1.999280, 0.518210, 0.264760, 0.095420, -3.140690, 0.740490, 0.122100, 0.115950,
-0.146300, -0.323800, 0.304630, 0.021790, 3.534910, -0.802600, -0.379410, 0.439580, -0.965290, -2.553470,
0.367950, -0.868520, 0.052880, 1.198990, 0.707680, 0.160000, -0.796990, 0.556150, 0.585010, 3.108240,
0.310940, 0.686990, 0.929180, -0.719670, -1.077640, 1.441770, 1.939440, -0.788170, -0.057520, 0.444290,
1.016040, -1.307730, -0.386360, 0.594460, -0.726800, 1.255030, -1.496030, 0.548300, -0.266350, -0.843300,
0.503420, -0.097250, -0.717190, 1.049370, 1.338560, -1.311690, 1.043730, 0.482150, 1.087600, -0.187120,
-1.682490, 0.333610, 0.084200, -0.752450, 0.308180, 0.907110, 0.485360, -0.490100, -2.069030, 0.485470,
0.972780, -0.324050, 0.259230, 0.868960, -0.672130, 0.449950, -1.020410, 0.315550, -0.894950, 0.412420,
1.772120, -2.377890, 0.309010, 0.269610, 0.737400, -0.336010, -0.305620, 0.824990, -0.331020, -0.882420,
-0.510770, 1.287670, 0.303950, 4.987660, -0.074550, 0.094090, -0.572500, -0.267710, -0.433020, 0.475830,
1.341020, 0.289490, -0.127900, -3.195890, -1.150970, 1.968860, -0.633200, -1.385180, -0.654470, 0.121690,
-0.589240, -0.253270, 0.557170, -0.659450, 0.853810, 9.657340, 0.972420, 5.683610, -0.973350, 15.544410,
4.199250, -1.464880, -0.557210, 3.943150, 9.683250, -1.137290, 0.377580, 0.283370, 2.667690, 15.035510,
0.104710, -0.075060, 0.785170, -0.904730, -1.142370, 2.223360, -2.412810, -0.492730, 0.047170, 0.287320,
-0.762960, 0.634540, 3.613510, 0.136540, -0.885770, 0.449410, -1.258520, 0.280750, 0.807100, 0.537900,
1.289630, 1.258510, -0.918190, 1.291940, -0.097010, 1.673710, -0.776800, 0.047050, 0.647370, 0.839330,
-0.347210, -0.374340, -0.240010, -1.622310, 0.099680, 0.683900, 0.573000, 1.943960, -0.145960, -1.125230,
0.806660, -0.087950, -1.451960, 0.506270, -0.199770, 0.000330, 1.621490, -0.476910, -2.534950, -1.582510,
-0.049080, -0.786650, -0.013450, 0.964730, -0.138590, -1.008790, -0.173660, -1.203900, -0.813950, -0.786180,
0.114740, 0.009610, 1.951010, 1.199140, -0.484630, -0.546420, 0.907870, -0.763680, 0.117180, -0.718990,
-0.978720, -0.050200, 0.021730, 0.199960, 0.857790, -0.275960, 0.997540, 0.078140, -2.223700, -1.884090,
-1.078380, 0.601740, -1.195780, -0.762780, 0.373500, -0.238230, -0.497510, 0.689410, -1.261420, 0.729290,
3.342610, 1.485030, -0.332840, 0.384260, -0.909330, 0.603080, -0.928730, -2.538500, -0.198750, 0.206290,
0.552090, -0.125110, -0.562730, -0.068870, 1.354920, 0.440490, -1.007550, 0.674590, -0.952880, -0.152840,
0.158320, 1.593470, -1.243830, -0.424940, 1.199780, 0.977620, -0.202820, 1.588540, -0.168820, 3.201160,
0.825900, -0.539990, -0.625580, 1.358250, -0.128480, 4.477890, 1.355930, -0.345620, 0.304190, -0.826520,
0.393050, 0.904070, -0.747790, -1.939520, 0.233700, 0.622250, -0.067770, 0.608210, 0.622900, -0.336400,
0.684610, 0.131210, 0.217670, 0.579720, -0.292090, -0.380830, 0.088990, 0.373800, -0.396170, -0.238220,
-0.335300, 0.327020, 0.895310, 0.761190, -1.837620, -0.170780, 0.715180, 0.220410, -1.265190, 0.002230,
0.621220, 0.646410, 1.452160, -0.408330, 1.148370, -0.009140, -3.315020, 0.199950, 0.021860,
-1.329220, -0.026190, -0.348470, 1.378690, 0.526740, 0.007670, -0.497630, 0.139120, -0.661490, 1.420950,
-0.097660, 1.132210, -1.090990, -1.424720, -0.024960, 0.781780, 0.048030, 0.589420, -0.588380, 0.501640,
-2.761760, -0.240070, -0.134060, 0.992180, -0.475820, 0.564180, 0.390520, 0.008570, 0.210260, 0.174500,
-0.400490, -0.304260, 1.011030, -0.177230, -0.889900, -1.268150, 0.087140, -1.283230, 0.855420, 0.061830,
2.743700, 0.315700, -0.593540, 0.096760, 0.699720, -0.678900, -0.303060, 0.838480, 0.312730, 0.347260,
1.141080, 0.817020, 0.013650, 1.045820, 1.089420, -0.575530, -0.386740, 0.038360, -0.213790, -0.372840,
-0.206410, -0.049410, -1.720500, 0.350030, -0.481180, 0.598200, -0.557920, 0.598810, 0.264080, 0.271730,
0.636010, 1.741210, 0.072590, 0.881670, 0.416130, 1.938420, 1.801930, -0.570320, -1.239260, -0.939080,
-0.311140, -0.053260, -2.032710, 1.005090, -0.855820, -0.712380, -0.360910, -0.269990, -0.735300, -0.436200,
-0.140980, 2.592570, -0.786830, 1.317160, -0.557100, 0.809710, 0.337660, 1.304180, 1.467350, 0.259770,
0.988520, -0.094950, 0.303200, 0.489800, 0.809240, 0.367980, -1.297790, -0.063150, -0.709430, 0.619360,
1.152910, 1.558570, -0.051660, 1.029380, -0.475480, 1.270880, 1.526570, 1.073460, -9.160880, 5.787760,
1.551430, -4.017590, 2.138340, 1.738450, 6.827110, -1.145190, -2.204570, -2.177880, 1.928220, -3.619770,
-2.336840, -0.897260, 7.092990, -1.117840, -2.234860, 8.102380, 3.223510, -0.726010, 1.789480, -0.112920,
-0.678620, 1.256190, 0.548770, -0.156870, -0.391200, -1.393750, 1.067560, 0.312360, 0.881080, 0.196200,
-0.097470, 3.102070, 0.544160, 0.736130, -1.253520, 0.173240, 0.325940, 0.979290, 0.660010, -0.359620,
-1.054530, 1.117480, 3.050800, 1.089140, 0.741800, -1.416900, -0.273160, -0.065790, 3.646510, 0.059380,
0.671440, -1.838640, 0.185310, -1.241270, -0.883890, 2.122830, 0.674220, -0.323510, 1.374350, -0.495930,
0.837550, 0.367520, -0.391090, 1.143350, 0.738190, -0.424990, 0.793700, 0.091780, -0.471560, 0.581300,
0.179190, 0.620730, -0.014860, 1.797990, 1.194480, 1.944820, 0.436130, 0.246750, -1.950380, -0.044700,
-0.268710, 2.801400, -0.948690, 0.251800, -0.404920, 0.180110, -0.062060, -0.117620, -0.216820, 0.762510,
0.056960, 1.102080, 0.297920, 1.276990, -0.837660, 0.801290, 1.048620, 0.236630, -0.370060, 0.254650,
-0.853110, -0.591190, -0.700210, 0.452250, 3.419480, -0.114180, 0.012350, -0.676860, -1.256520, 0.241870,
-0.229740, 0.768270, 0.392630, -0.127460, 0.931980, 1.520360, -0.999660, 1.495350, -0.947250, 0.031220,
0.835000, 0.224340, -0.075410, -0.336290, 0.564700, -0.752030, 0.600510, 0.834530, 0.350090, 0.230130,
-2.814150, 0.563740, 0.544490, 2.454000, -0.169460, 0.840710, 0.409100, -0.456010, 1.105680, -0.010790,
0.293020, 0.551770, 1.204600, 0.081950, -0.407540, 0.285650, 0.792230, -0.603010, 0.677950, 0.420840,
0.305910, 0.021740, -0.257150, -0.135320, 0.328110, 1.176690, 1.128670, -0.573380, -1.464500, 1.447480,
0.263890, 0.942750, 0.206350, 0.931280, 0.169620, -0.062780, -0.196440, -0.742560, -0.294100, -0.179630,
0.733540, 0.290550, 0.858690, -0.717680, -0.595700, 0.677790, 0.488680, 0.203180, 0.490070,
-2.315240, -0.349870, -0.267720, -0.646810, -0.212850, 0.383830, -1.468440, 0.014300, 0.349620, 0.041840,
-0.462090, -0.115930, 1.730080, 0.455550, 0.085050, 0.877180, -0.234880, 0.139090, -0.122200, 0.046320,
0.302680, -0.008250, -0.167620, 1.787370, 1.085310, 2.014030, 0.919540, 0.873710, 0.031940, 0.028050,
-1.463690, 1.080240, 4.426640, -0.984520, -0.128980, -0.905510, -0.604770, -0.096420, -1.423400, -0.037260,
4.140620, 0.843120, -1.579040, 0.265240, -0.049610, -0.422750, 2.541730, 0.311080, -1.159270, 0.339790,
0.585060, 1.168090, -0.767370, -1.252400, 1.044800, 0.944900, -0.603200, 0.982920, -1.423730, -0.559380,
-0.298940, -1.488980, 0.346490, 0.725260, -0.299990, -0.608530, -0.342090, -0.185210, 0.907390, 3.740060,
2.440870, -0.682000, 1.591390, -0.754970, 0.181050, 0.853440, 0.607090, -0.619610, 0.623640, -0.583390,
0.410070, -0.714930, 0.575300, -0.875430, -0.724630, 0.381750, 0.622060, -0.406460, 1.072480, 0.423130,
0.693990, 0.673020, 0.195110, 0.688470, -0.912800, -0.029500, 1.118880, 0.369890, 0.581630, -0.315520,
-0.164920, 0.755300, 0.132070, 0.365240, -1.695870, 1.335790, -2.843780, -0.696120, -1.513300, -0.119570,
-1.799820, -3.053240, 0.612720, -0.110630, 0.431150, 0.369560, 0.377030, -0.051830, -0.238370, 4.777740,
0.901870, -2.922490, -1.874870, -0.345220, 0.365880, 0.558510, 0.754940, -1.873420, 0.490190, 1.061870,
2.166240, -0.519570, 7.992520, 0.438290, -1.911110, 2.446380, -0.425130, -0.254020, -0.130120, 1.319260,
-0.552760, 0.796360, -0.052680, 2.587250, -2.298000, 0.541080, 2.163600, 3.184080, -0.602600, -0.335370,
0.154840, 1.048350, -0.123880, -0.289240, -1.035490, 5.586900, -0.522980, -3.652730, -0.014970, -0.720660,
-0.900830, 1.069400, -0.576440, -0.282110, 0.788610, 1.136000, -0.869250, -1.205070, 0.774260, 0.579450,
1.224150, -0.365390, 0.682000, -1.044300, -0.947490, -0.759670, 2.206370, -0.806380, -0.331390, -0.100370,
-1.376980, 0.913420, 2.540590, 0.291240, 0.190900, 0.281460, 0.313320, -2.172040, 1.005400, 0.057990,
-0.611160, -0.498880, 0.465600, 1.084600, -1.251060, 0.820330, 0.101420, 0.696110, 0.106100, -0.115590,
0.149550, -0.277520, -1.906110, 0.306080, 1.121320, -1.198810, 0.310480, -0.589210, 0.617260, 1.269850,
-0.300460, -1.651350, 0.613750, 0.414040, 0.238020, 0.496630, -0.456920, -1.161670, 0.193890, -1.099340,
-0.230290, -0.304920, 1.303630, 0.890790, 0.181120, 0.075580, -1.428090, 0.135100, -0.549770, 0.309630,
-1.334080, 0.079830, -0.095420, -0.595690, 0.681600, 0.812990, 0.121270, 0.992850, 0.448350, -0.598990,
0.660150, 0.562080, 0.574360, -0.155700, -0.700520, -0.257150, 0.253370, -0.342020, 0.110790, 1.534630,
0.400770, 0.950010, -0.643180, 0.393870, -0.143880, 2.051820, -1.300620, 0.293730, 0.041280, 0.110150,
-0.257850, -0.959650, 0.278960, 0.059830, -0.326350, -1.115830, 0.704730, -1.025340, 0.490880, 0.245520,
-0.890750, -0.158910, -0.104430, 0.751670, -0.183110, 0.351920, -0.713700, -0.633320, -0.179370, 0.495140,
0.357380, 0.847030, 0.145620, 0.004810, 0.834380, 0.056680, 0.446580, -0.173240, -0.422710, -0.254060,
-1.008190, 2.226660, 0.020630, 0.458030, 0.402060, 1.057970, 0.806280, 0.068790, 0.150020,
-0.644430, -0.407070, -1.283020, -1.286720, 1.794890, 1.155810, -0.437560, -0.429020, 0.532360, -0.966390,
1.826070, 0.836840, 0.180400, 1.330010, -0.998750, 2.078350, 0.208840, -0.023910, -0.713440, 0.558980,
-0.040860, -0.196110, 0.013070, 0.440050, 0.100750, -0.239080, -1.011050, -1.042570, 0.914370, 0.249780,
-0.334820, 0.088490, -0.704830, 0.460070, -0.149570, -0.424760, 0.316580, -1.123120, 0.182630, 0.877280,
-2.424580, 0.924660, -0.388430, -0.601680, -0.131040, -0.739600, -1.018020, -0.667360, -0.210470, -0.663090,
-0.840270, -0.772060, 1.712070, -0.663690, 0.067300, 0.864880, -0.606800, 0.065390, 0.350960, 0.070000,
-0.765820, -0.885880, 0.604670, -0.278100, -0.213560, 0.585260, 0.518860, 0.849290, -0.366310, 0.170560,
-1.218350, -0.800700, 0.353260, -0.859720, 0.093270, -0.474680, 0.161010, 0.973640, -0.235880, 1.048090,
0.625260, -0.078040, -0.149820, -1.761060, 0.053350, -0.800640, -0.936480, -0.195000, 0.483600, -0.093790,
-0.333570, 0.755360, -0.840290, 1.759390, -0.235930, 1.003930, -0.373090, -0.786290, 0.450340, -0.145110,
-1.533590, -0.467170, 2.356680, 0.911180, -0.122390, 1.172370, -0.618620, 0.821690, -0.047190, -0.512320,
0.493790, 1.364690, 0.771860, 0.232710, -0.683490, -0.079570, -0.020400, 0.544490, -1.256810, -0.704590,
0.526420, -0.159340, -1.924130, -1.449410, -0.230180, 0.229670, 0.776650, 0.888100, 0.175730, 0.114790,
0.287610, -0.294180, -0.721670, -0.018930, 0.150200, -1.945580, -0.548950, -1.021070, 0.181210, 0.181550,
-2.015280, -0.265230, -1.427760, -0.638630, -0.660320, 0.207780, 0.276200, 0.483100, -0.284880, 0.667260,
0.115350, -0.539260, 0.669570, 0.916860, 0.367890, 0.045620, -0.053450, -0.880910, 0.620840, 0.610880,
0.322600, 0.885500, -0.264740, 0.572450, 0.053170, 0.494430, -2.103050, -0.961370, 0.928030, 0.953220,
0.799300, -0.165960, 0.236740, 0.432430, 0.844970, 0.212750, 1.450980, -0.222190, 1.525800, -0.684440,
-1.256590, -0.833340, -2.001130, -0.580850, -0.124080, -0.209380, -1.042750, -0.375630, -0.655930, 0.434700,
0.166790, -0.066470, 0.037060, -0.584920, -0.439910, -0.792830, 0.975920, 0.027020, 1.148770, -0.808000,
-2.809090, -1.936570, -2.331170, -0.699670, 0.752500, 0.518040, 0.030490, -0.146350, 0.263370, -0.475560,
0.179150, -0.032220, -0.289050, 0.469350, 0.288540, 0.251990, -1.250430, -1.375720, -0.162570, -0.550530,
1.990860, 2.066160, -1.455940, 0.308510, 1.291470, -2.058390, -0.135730, 0.616060, 0.591990, -0.935400,
0.213450, 2.570030, 0.060850, 0.542630, 1.146050, 0.814440, 0.912850, -1.389330, -0.317450, 0.456920,
1.367600, -0.632070, -0.676380, 1.239950, 0.532190, 0.546850, 0.321260, -0.650940, -0.178910, 0.079720,
0.629190, 0.672930, 1.213190, -4.015510, -0.641230, 0.268300, -1.368080, -1.161840, -1.537710, 7.543290,
2.391550, 1.545600, -0.564240, 0.011500, 0.332990, 4.253070, -0.324080, 1.100900, 0.820390, -1.954950,
-1.386360, -0.077800, -1.989440, -1.216890, -0.913050, -1.723030, -0.750660, -0.793590, -0.298440, -2.900310,
-0.653680, -1.351840, -1.191350, -0.799440, -1.586330, -0.151040, -2.101720, -0.325590, -1.602810, -2.549130,
-2.058060, -1.406650, 0.695780, -0.444020, -0.825500, -0.468490, -1.430630, -1.735900, -0.603650,
2.043190, 0.427810, 0.508480, 1.324810, 2.061690, 0.918160, -2.197610, -0.585700, 0.116690, 0.159590,
0.993050, -1.853830, 1.036370, -0.425570, 0.346680, 0.842110, 0.065000, 0.403950, 0.347380, 2.466520,
-2.519380, -1.201500, -4.119690, -1.179750, 1.261170, 0.835510, -0.413580, -0.286360, -0.975650, 1.540910,
-1.214580, -1.152420, 0.497710, 0.176150, 0.001560, 1.632860, -1.643270, 0.071380, 3.678830, 1.114630,
-0.618530, 0.729950, 1.821140, -2.447830, -0.698720, -3.679830, -0.218300, 1.544780, 0.747380, 1.113540,
0.985710, -0.093100, 0.974460, 0.081990, -0.091450, 1.563460, -0.366380, -0.267120, -0.532620, 0.717490,
-1.224460, 1.707430, -0.849300, 2.597000, 0.701640, -0.350920, -1.143760, 1.122100, -1.603290, -0.895870,
-0.579710, -0.234410, -0.803140, -0.100980, 1.435210, -1.065080, 0.922450, 1.173300, 0.457110, 0.751010,
0.053540, 0.550280, 0.774740, 0.210200, 0.459210, -0.601960, -0.228350, 0.334450, 0.505550, -0.661830,
0.446350, -1.651000, -0.807000, -1.459580, -1.754520, -1.329060, -0.415040, -0.772990, 1.113590, -1.384480,
0.726990, -1.589030, 0.685730, 0.016620, -1.484460, 0.552810, -1.299800, 1.453430, 0.645180, -0.236070,
1.049770, 1.071710, -2.359160, 2.541960, -1.236990, 2.541330, 1.642430, 0.691730, -0.375560, 2.673110,
0.180820, -2.854310, 0.934310, 1.993970, 1.976030, -2.288870, -0.614120, -0.190640, -0.340290, 1.059270,
1.377160, 0.530240, 6.050860, 0.314660, -0.545910, 10.252180, 0.517550, 0.228940, 0.032800, -0.700130,
0.201240, -0.394870, 0.735120, -1.513540, -0.630410, -0.111170, -0.015110, -0.125260, 0.735540, 1.992190,
-0.256420, 0.737460, -1.348440, 1.202390, -2.294540, 0.691570, 0.388590, -0.162300, -0.772640, 0.189150,
-1.829800, 0.258990, 2.023600, -0.653040, -3.284350, 1.256220, 1.549080, 0.627840, 1.051740, 0.639800,
-0.970480, -0.972180, 0.168580, -1.664200, 2.695490, -0.995920, 0.024780, -0.322390, 0.187130, -0.446360,
0.849500, -0.680240, 0.092360, -0.731720, 1.215230, 0.438340, 1.111850, -1.587170, 0.954520, 0.133180,
2.757210, 0.051890, 0.142700, -0.199270, 0.789310, 1.474590, 0.495100, -0.498300, -1.007520, 0.197980,
4.096040, 1.058020, -0.588880, 2.105820, -1.257680, -0.765940, -4.085490, -0.275580, 1.959310, 0.060440,
-0.846900, 0.668450, 0.868990, 1.546290, 0.188860, -0.949780, 0.735650, 0.663620, 0.746410, 1.143420,
-0.508350, -1.256430, 0.303450, -0.457980, 2.705740, -0.196860, 0.198990, -1.002360, -0.171630, -1.552760,
-3.688420, 0.695420, -0.061430, -0.296580, 0.499520, 3.972820, 1.193020, 0.427910, -1.692240, 0.400720,
-0.690980, 0.675210, 0.788070, 0.154520, 0.338960, 1.415040, -1.016410, 2.396620, 0.812030, -1.203690,
-2.095760, 0.175120, -0.701700, -0.004720, -0.602360, -0.239380, 1.518430, -0.043430, -0.227540, 0.121760,
-0.004590, -0.246910, -2.690100, -0.649000, -0.219070, 0.923260, 0.710210, 0.686190, 0.960790, 0.210110,
0.373640, -0.773980, -0.873580, -0.908110, -0.647290, -0.260150, 0.287550, 0.501450, -0.944610, -0.236690,
0.135480, -0.727020, 0.877790, -0.934780, -1.341110, -0.661250, 0.836680, -1.026740, -0.940660, -0.464440,
0.254150, -0.402510, -0.475100, -0.673670, -0.388140, 0.108970, 0.626540, -0.386010, 0.802740,
-1.745280, 0.036920, 0.363870, 0.084420, 0.860520, 0.536800, -0.598720, 0.237600, -0.130210, -0.199840,
-0.058730, -0.176540, 0.347810, 2.452360, 1.341200, -0.059230, 0.369430, -0.633980, 0.324090, -0.406410,
0.455340, -1.496760, -0.861480, 0.272480, -0.314420, 1.450080, -0.459200, -0.739830, -0.116810, 0.317860,
-0.799900, -2.127030, -1.129170, -0.199330, 1.208500, -0.581340, -0.076290, -0.871280, 0.088070, 0.999680,
-1.562540, -0.137330, -1.092600, -0.156770, -0.373720, 1.505670, 0.456360, -1.733460, -0.347230, -0.064800,
-1.382700, -0.027770, 0.868540, -0.221050, -0.732460, -5.167540, 0.425770, 0.265970, -0.701390, 0.184090,
1.242360, 0.976650, -1.159320, -7.740170, -0.017020, 0.473390, -1.443830, 0.224290, -0.795650, -0.655260,
-0.812120, -0.281150, 1.284560, -0.658790, 0.008430, 0.169180, -2.178810, -0.997230, -0.246510, 0.263710,
-0.797110, 1.890940, -0.224040, 0.701270, -0.879620, 0.845060, -0.745170, 0.554520, 0.866800, 0.302780,
-0.459540, 0.030140, -2.050090, 0.103370, -1.079700, -0.177080, -0.201400, 0.707870, -0.691050, -0.230430,
-1.021750, -0.953440, 0.139540, -0.384750, 2.154230, -0.463920, -0.689470, 0.972110, 0.198660, -0.382570,
-1.212910, -0.914360, -0.349790, -0.395100, -0.522820, -0.676550, -0.826150, -2.080780, -2.815170, -0.459820,
-3.445200, 1.873380, -0.699660, -2.904910, -1.179590, 0.646100, 0.792330, 0.649720, -1.970330, 0.155230,
1.444190, 0.444290, -4.474840, 2.182520, -0.003790, -0.690900, 1.642060, 2.159710, -2.409990, -0.439180,
-2.426910, 0.816380, -2.114540, 0.460550, 0.448230, -1.306450, -1.146770, 0.446850, 0.012990, 0.611160,
0.277510, -0.671470, -0.551030, 1.249200, 0.772150, -1.311420, -0.390540, 1.994710, -2.496800, -0.018170,
1.897670, -0.179280, -3.740380, -1.314690, 1.158280, -0.075920, 1.194030, 0.269010, -0.458040, 0.926870,
0.587200, 0.319200, -0.934510, -0.892020, -0.359550, -1.162110, 1.211310, 0.077220, -0.331810, -0.588030,
0.385850, 0.365010, -0.477410, 0.072460, -0.214120, -1.073680, 1.110400, -1.492350, 1.063520, 1.474740,
0.122990, 0.510740, -0.985280, -0.746220, -3.684540, 0.700230, 0.282480, 1.591980, -0.197480, 0.820590,
0.486540, -0.923610, -3.085410, 0.150980, -0.420310, -2.345750, -0.511100, 1.245680, 0.031840, -0.720300,
1.648300, -0.911410, -1.870350, 0.804300, -0.466380, -0.555950, -1.252380, -0.205690, 1.254710, -1.758140,
-0.963750, 0.111620, 0.857750, -0.525190, 0.014260, -0.267790, -0.102240, -0.538640, 0.690100, -0.373840,
-0.039760, -0.214610, -0.282510, 0.117290, 0.124650, -0.767960, -1.386830, 1.472940, -0.342990, -1.041840,
2.421770, -1.319000, -1.191750, -0.559890, 0.345890, 0.548390, -1.036250, -0.816390, 0.697080, -0.213420,
-0.824950, -0.352210, -0.085430, 2.267070, -1.328190, 0.409830, -0.852320, -0.416190, -1.164480, 1.512990,
-0.074400, -0.667700, 2.322330, -0.904780, -1.569790, -0.152400, -0.275510, -0.015770, 0.719610, 0.506770,
-0.817920, -0.449070, -1.141550, -0.415940, 0.445240, -0.581910, 0.368610, 0.014610, 0.520060, 0.461420,
-0.962650, -0.186830, 0.336320, -0.206740, 0.583940, -0.675820, 0.014770, -0.616490, -0.325520, 0.193240,
0.572630, -1.300180, -4.266060, -0.185220, 0.383180, -0.113210, 0.165870, -0.409730, 1.144220,
0.047260, 0.327190, 0.776080, -0.300600, -1.324860, 0.656110, -1.615800, -0.281770, 0.952480, 0.953580,
0.389770, -0.439890, -0.297070, 0.184790, -0.523470, -0.227470, -0.843350, -0.274800, -0.159410, -0.032330,
-0.482240, -0.018350, -1.930140, -1.307250, -3.949200, -1.074840, 0.498250, -0.759130, -0.783370, 1.459650,
-0.305910, -0.428690, -0.860710, -0.415380, -0.981010, -1.753620, 0.752200, 1.125810, -0.954500, -0.791570,
-1.199350, -0.713130, -0.101290, -0.785440, 0.453560, -0.903870, 0.710190, -0.337970, -0.855010, -0.501350,
-0.009930, 0.708650, 1.505790, -0.381360, 0.901750, -0.024470, 2.844780, 1.051900, -0.048280, -1.215720,
-0.542820, 1.803610, 0.495210, -1.943970, 1.519910, -1.367030, 0.310700, 0.896350, 2.052630, -0.426760,
0.498710, 0.128570, 0.225740, -0.262220, -1.159870, 0.168280, -0.894330, -0.537980, 0.090310, 0.110770,
0.057640, -0.103490, -1.216720, -0.605750, -0.439030, -1.113980, 2.096000, 0.648950, 0.187180, 0.957410,
-0.640920, -0.567390, -0.464560, -1.790130, 0.315740, -0.113880, -0.880400, -1.476910, 0.765160, 0.849590,
-1.396530, -0.519090, -0.085290, 0.778880, 1.421480, -0.147460, 0.825860, -0.469580, 0.318820, -1.876990,
-0.257770, -0.451900, -0.815440, -0.047320, -0.262830, -8.835630, -5.480100, -6.813520, 0.111600, -6.911850,
-1.934560, 3.228700, -2.124600, -3.837110, -7.447770, 2.026670, 1.060930, 1.562330, -1.404620, -7.918000,
2.328350, 2.276350, -9.655420, 1.971430, 2.119500, -1.409460, 7.111980, 1.269340, 0.586240, 0.012880,
-0.009560, 1.391260, -1.320140, -0.004510, -0.665570, -0.243570, 0.516570, -1.299860, 0.647630, -0.281080,
-0.311540, -1.016560, 0.360180, -0.056530, 0.381920, -0.198470, 0.455220, 0.543380, 0.179840, -0.288790,
-0.139640, -0.199950, -1.949410, 1.522960, 0.953750, 0.812360, 0.729820, -1.100420, 2.391160, 0.391680,
0.008230, 0.431020, -1.155260, -0.228220, -1.407970, -0.574410, -0.299790, -0.521820, -0.094730, -0.678340,
-1.403970, 0.044730, -0.632050, 1.091550, -0.564240, -0.987360, -0.468240, -0.368110, 0.071660, 0.354950,
0.356850, -0.726000, 0.628680, -1.292870, 0.974620, -0.449720, -0.338400, -0.727720, -0.336870, -0.887080,
0.055070, -0.110800, 0.690840, -0.177000, -1.762980, 0.625190, 2.061230, -1.143460, -0.803710, 0.231520,
-0.416640, -0.567660, 0.196390, 0.222710, -0.967190, -1.301350, -1.475190, 0.543940, -0.874420, -0.758800,
1.013630, -1.031190, -0.487210, -0.465440, 0.453810, -0.707910, 1.097510, 1.374440, -0.113590, -0.516140,
-2.917730, -0.602050, 2.322120, -0.086440, -0.511100, 0.905350, 0.190820, 0.710390, -0.624660, 1.132470,
-0.528990, 0.193760, -0.614990, 2.389040, 0.120330, -1.081600, -0.757900, -0.801840, 2.135750, 0.537830,
0.681840, -1.061140, -0.569680, 9.805360, 0.507680, -1.814020, 0.017470, -0.511360, -0.713740, -0.364250,
-1.873160, -0.602460, 3.462720, 0.261580, 0.654090, 8.416190, -1.155870, -0.739090, 0.421320, 0.728810,
-0.465680, -0.368820, 0.115550, -1.325330, 0.366080, -0.541080, -0.688440, -0.526650, 2.472710, 0.438680,
-0.176040, -1.417450, 0.706210, -0.480820, 0.357130, 0.986400, -1.014910, -0.754270, 0.415120, 0.464330,
-0.930510, -0.849230, 1.202660, 0.044010, -0.985190, 0.522080, -0.922710, -0.794880, 0.630540,
-0.368880, -0.132350, 1.698630, -0.913980, -1.153590, -0.028420, -1.248170, -0.658430, -1.915070, -0.292540,
1.108450, 0.118160, 1.028950, -3.641640, -0.085980, 0.624510, 0.739740, -1.577070, -0.247350, -0.833020,
-2.405470, 1.201480, -0.239300, 0.494130, 0.969780, -0.474280, 1.785940, 0.072950, 0.367690, -0.404140,
-1.408360, -0.337060, 0.527970, -0.025740, 0.868610, -1.653000, -1.239880, -0.211570, -0.870970, -1.110390,
-0.730590, 0.670790, -0.503500, -0.890100, -0.130960, 0.232380, 0.016680, 0.094740, 1.427380, -0.971390,
-0.234190, -0.330750, -0.801420, 0.374290, -0.848130, 1.037780, 0.279150, -0.630230, -1.158190, -2.351260,
-0.461700, -0.750000, -0.050980, 1.396590, 0.814780, -1.515870, -0.055430, 0.596510, 1.616190, 0.267030,
-0.587030, 0.520940, -0.820800, 0.546710, -0.351070, -0.613680, -0.025690, 0.606600, -0.749690, -0.341460,
1.103090, 0.355570, -0.763810, 1.595070, -0.632550, 0.438800, -0.265440, -0.300540, -0.370200, -1.131440,
0.489020, 0.036280, 0.462320, 1.004940, -0.763490, 1.898520, 1.221440, 0.841610, -0.358340, 1.690790,
0.115790, -0.107400, 0.438520, -0.153690, -0.505460, -0.318260, 0.768630, 2.305950, -0.690750, 2.439230,
1.403870, -0.400440, 0.456950, -0.088420, 3.516310, 0.318920, 1.170040, 1.555660, -2.292370, 0.918390,
-0.315870, -1.337110, 0.126250, -0.118960, 3.891470, 0.597390, -0.060610, -1.433840, 1.562580, -0.446880,
-1.251370, -1.115310, 6.195520, -0.135930, 0.460360, 2.406330, -0.800890, -0.919580, 0.473500, 1.195910,
0.850840, 1.413540, 0.190600, 0.068770, -0.196240, 0.659140, 1.212040, 0.065070, 0.080900, 1.129740,
-0.978570, 0.170330, -0.323990, -1.256270, -0.509670, 1.229930, 0.439420, -0.344210, 0.036110, 0.811590,
-0.861290, -0.420800, 1.895950, 0.719940, 0.113880, -0.739360, 1.398170, 0.515920, 0.624280, -0.298510,
1.054160, -0.596990, -1.128270, 0.072050, 0.581850, -3.268900, 0.300620, -0.241600, 0.040130, -0.976050,
0.141450, 0.896230, 0.011440, 0.168880, 0.202090, 2.738850, 0.748950, 0.036480, 1.735920, 0.620500,
0.791180, -1.276740, 0.175690, 1.026080, 0.810160, -0.730690, 0.791310, -0.354950, 0.043250, 0.025500,
-1.826540, 2.367290, 0.347780, -0.241020, 0.802290, 0.052850, 0.850570, -0.429100, -0.004300, 1.008810,
0.503190, 0.373870, 1.471580, 0.750560, -0.186240, -0.127330, 0.002940, -1.084760, -0.072350, -0.188520,
-0.573130, -1.092680, -0.709670, -0.111530, 0.359250, -1.301710, -0.712410, 1.144040, -0.452500, -0.300570,
0.162430, 1.348230, -0.657960, -1.249930, -3.030020, 0.609560, -0.510320, 0.307720, -0.297770, -0.035890,
1.423690, -3.457230, 1.237290, -2.683190, 0.765920, 0.514660, 0.091360, -0.510360, -0.338660, -1.354820,
-4.344190, -0.398700, 0.595840, 4.977710, -0.230390, 0.479970, 0.326550, -0.373950, -0.290610, -0.509310,
-3.536260, -0.703640, -1.071700, 0.667640, 1.460170, -1.841220, 1.736070, 0.626850, -0.575180, -0.880930,
-0.461390, 0.513190, -0.118140, 0.946040, -0.159420, -0.495670, -0.179460, -0.902480, 0.514930, -0.965530,
-0.281360, -0.879270, -0.395350, 0.849510, 0.206560, -0.978660, -0.495520, 0.296350, -0.608790, -0.342480,
-0.279240, -0.267710, 1.104620, -0.289810, 0.912690, 0.909200, 0.812980, -0.618640, -0.597440,
-0.173450, 0.355740, -0.911910, -1.131120, 1.530760, 1.399860, 0.654210, -0.207360, 0.210060, 0.347360,
0.707550, -0.398950, 0.080640, 0.318550, 1.105130, 0.241220, 0.209570, 1.333340, 0.960760, 0.026390,
-4.807770, -0.022640, -0.311660, 0.350800, -0.965810, 0.356550, -0.998440, 1.103000, -0.915700, 0.687450,
0.158700, 0.277160, -1.242610, -0.127940, 0.111420, -1.051910, -1.179460, -0.626760, -1.091830, -0.066150,
1.644000, 0.472460, 0.154650, -0.554610, -0.667230, -1.501790, 0.578260, -2.854240, 0.965760, 0.408160,
-0.088190, -0.271560, -0.135620, -0.046400, 0.724450, 1.924160, 0.439240, -0.255400, 0.454410, -1.111360,
-1.194090, -0.576320, -0.284990, 2.114140, -0.445260, -0.024990, -1.424350, -0.180700, -0.577250, 0.126290,
-0.317810, 0.507970, -0.334500, 0.781530, 0.028780, 0.640210, 1.286570, 0.725000, 0.810220, -1.267160,
0.042750, -0.435670, -0.726090, -0.081290, -0.635940, -1.223210, 1.321030, -0.436580, 0.988910, -4.628200,
0.385880, -0.494250, 1.102290, -0.478290, -0.352210, -0.246800, -0.418830, -0.074160, 0.839140, -0.083620,
0.068710, 0.767030, -1.147600, 0.694920, -0.605750, -0.998240, 0.978910, 0.383260, 0.478350, 0.365970,
0.019110, 1.520120, -3.386970, -0.151620, -0.883980, -0.147090, 0.695390, -3.041110, -1.767320, -0.002100,
-0.427950, -2.783290, -1.325660, 2.273520, 4.978880, 0.131830, -0.562420, 0.282980, 3.114190, 0.696780,
3.489180, -0.705720, 6.181500, -0.357660, -0.041060, 16.014669, 2.682940, -3.270520, 0.473070, -0.472870,
0.359990, -0.091130, 0.398560, 0.111850, -0.481230, -0.595420, 0.773130, -0.745120, 0.139770, 0.687800,
0.836300, 0.889050, -1.521920, 0.967640, 0.940500, 1.524390, 0.634360, -1.308280, -0.792950, 0.793190,
-1.292310, -0.279650, 1.623680, -0.743930, 0.043780, 0.937980, 0.563190, -0.136240, 0.729300, 0.292430,
0.517850, -0.033560, 0.076610, 0.526560, 0.159870, 2.026910, 0.449630, -1.128690, 0.247820, 0.920960,
1.525660, -4.887940, 0.001270, -0.910830, -1.028380, 0.967640, 1.044860, 0.095160, -0.035100, -0.308890,
0.693040, -0.257480, -0.304980, 0.997980, 0.866350, 0.784400, 0.410900, -0.427840, -1.129150, -0.213820,
3.002380, 1.818490, 0.471850, -0.792820, -0.732850, -0.416570, 0.747030, 1.289410, -0.957240, -0.387760,
-0.925400, 0.175260, 0.437550, -0.536750, 0.485500, 0.633380, 0.907350, 0.551630, 0.660750, 0.758060,
-0.327890, 0.076310, -0.764860, 0.092310, 1.173230, -0.574430, -1.176680, -0.544910, 0.454940, -0.274480,
0.428430, 0.978790, 0.881170, 0.593850, -0.553800, 0.487020, 1.046690, 0.241870, 0.996230, 1.581350,
0.520120, 0.502330, -1.034180, -2.276920, 0.606210, 0.379510, -0.257230, 0.707470, 0.288260, -1.415480,
-4.066250, 0.582170, 0.425900, -0.882600, 0.214310, 0.453930, -0.747140, 0.553940, 1.198330, 1.004720,
0.605960, -0.517500, -1.452220, -1.587300, 0.739990, -0.273240, -0.544750, 0.407220, -0.007190, 0.860970,
0.658210, 0.889890, -0.633970, -0.947870, 0.184740, 0.120770, 0.716790, 0.972670, -0.543610, 0.522870,
0.280940, -0.235230, -0.578170, 0.493330, -0.952080, 0.096850, -0.744090, 0.368920, 0.120100, 0.561230,
-0.092270, 0.337610, 1.873870, 0.762110, -0.721790, -0.075040, 0.336150, 0.667240, 0.209820,
-0.960110, -2.424930, 0.415170, -3.230570, 0.018900, 1.147200, -0.400070, 2.655820, -0.217890, -0.399680,
-0.971040, 1.061000, 0.800900, 2.036540, 0.719800, 0.115280, -0.538750, -2.491870, -1.069070, 0.023430,
-0.741250, -1.220310, 0.169180, 0.201090, 0.432560, -0.421000, 0.054540, 0.286630, -2.235110, 1.257680,
2.044940, -0.295310, 0.545240, -0.859010, -0.085150, 2.445780, 0.944240, -0.119900, -1.361560, 1.359810,
-0.532600, 1.431580, 1.357920, -0.179000, 1.003940, -3.944890, 0.756870, 0.051090, 0.158350, -0.240510,
0.172780, -1.334870, 1.243690, -0.211660, -0.497230, -1.173270, 0.237560, 0.562050, -0.455000, 0.474330,
-0.884970, 0.053010, -0.320560, -0.128000, -0.423340, -1.074090, -0.336840, -1.327750, -2.263900, -1.927450,
0.270470, -0.293030, 0.597250, 1.107070, -0.840580, 1.293070, 1.161500, -0.664110, 1.740950, 0.822400,
2.645920, 1.093320, -0.648750, 0.736300, 0.596890, 0.280070, 3.696680, 0.674000, 0.811470, -0.113190,
-0.915740, -0.235440, -0.714730, -1.181040, -0.513990, 0.270140, -0.487070, -0.344950, -0.594250, -0.192310,
0.090150, -0.414560, -0.447050, -0.160840, 0.542430, -0.176570, -0.463610, -0.957760, -0.498450, 0.725870,
0.035100, 1.438520, -1.489380, 0.502850, -0.142270, 0.588840, -1.075550, -0.151260, -1.314040, 1.071060,
1.723980, 0.104180, 2.104410, -0.899570, 0.917460, 1.856680, 0.061980, 3.559260, -0.352590, 0.310830,
5.158040, 0.684220, 0.996520, 4.662920, -2.252940, 0.585150, 1.384270, 1.372280, -0.086580, -2.026610,
0.356410, -0.446160, 0.172560, 0.174090, 0.136540, 0.182820, 0.889260, 0.170820, 0.708420, 0.695140,
1.197370, 1.737640, -0.141350, -0.272950, -0.427870, 0.076440, -0.750230, 0.106300, -0.516140, 0.104190,
0.278500, -0.293180, 1.569060, 1.017260, -0.396910, -0.488600, 0.238910, 0.825200, 0.540470, 2.701940,
0.684470, -0.100100, 0.968850, 0.167500, 1.852190, -0.576250, 1.121970, 1.137960, 0.948190, 1.124750,
-0.225170, -0.823500, -1.007330, 0.428380, -0.560230, -0.442570, 0.201420, -0.103870, 1.479250, 0.672370,
-1.537650, -0.476980, -0.670690, -0.274960, -0.571390, 1.456860, -0.896840, 1.839700, -1.210180, 0.566520,
-0.642730, -0.953710, -0.135860, -1.166940, 0.389000, 0.256880, 0.712680, -0.704030, 0.058090, 0.257510,
-0.555960, -0.153570, 0.251760, 0.615260, -1.224120, 0.004590, -0.768140, 0.276340, -0.975760, -0.279470,
0.011540, -0.573750, -1.293600, 0.947720, 0.423690, -1.346020, 0.020240, 0.322540, -0.072940, -0.114680,
0.016420, 0.382060, -0.164370, -0.714340, 0.021240, 0.473430, 2.186740, 1.033440, 0.861040, 0.135230,
0.530550, 2.268830, 0.869410, 0.006030, -2.217300, -0.624590, -0.146290, -0.425210, -1.563220, 0.215880,
0.087700, -0.512960, -1.815440, 17.492500, 0.031940, 0.534350, -1.864390, 0.172140, -0.133200, -0.097320,
0.874860, -1.356280, 0.718960, 0.034150, 3.083240, 2.494050, -0.126490, 0.843300, -2.569200, -1.285850,
-1.754910, -0.155750, -1.773980, -0.061230, -1.410130, -1.313320, -1.064790, -1.660990, -0.907010, -0.447710,
-1.283320, -0.079570, -0.771860, -2.294260, 0.357210, 0.383240, -0.913360, -0.061260, 0.448000, -0.699530,
-0.766360, -2.947730, -2.119640, -1.154050, 0.038320, -2.328620, -3.562220, -2.862620, -0.670580,
-2.390170, -2.700820, -1.584720, -2.211440, 0.916180, -2.814240, -2.663950, -0.848290, 2.571080, 0.412130,
2.257650, -1.179570, -2.363780, 0.713830, 0.501880, -0.368010, -0.465320, -1.996910, -0.655770, 0.432030,
1.225830, -0.913540, -0.072240, 0.471090, 0.133390, 0.801900, 0.942880, 0.101840, 0.888990, -1.424430,
1.125850, 1.671310, 0.168100, -0.167620, -0.188600, 0.559280, 0.550440, -1.551050, 0.127450, 0.156660,
-0.385780, 0.539770, 0.741650, -0.380420, -0.557720, 1.029010, -0.117420, -0.677120, -0.565890, -0.603400,
-2.003280, 0.301490, 1.793340, 0.521520, -2.107670, -1.989390, -0.450890, -0.949330, -1.421770, -0.361450,
1.241170, -1.215690, -0.057070, -1.236100, 0.641620, 0.818440, 0.117130, -0.471660, -0.034550, 1.556410,
1.494740, 0.396520, 1.228440, 1.368730, -0.738610, -3.321430, 0.416440, 0.746010, 1.387510, 0.099130,
-0.748580, -1.116470, 0.914700, 0.563050, -0.835600, 1.133730, 0.318300, -0.759550, -0.605590, 1.718610,
0.065480, -0.031620, -0.687710, -1.490350, -1.021820, 0.963050, -1.964190, 1.166150, 1.170120, -0.346960,
-1.108150, 2.690570, 0.191010, 0.135170, -1.263680, -0.263900, -1.480500, 0.870920, 2.282720, 1.454610,
0.797590, 0.658880, 0.524370, 1.374870, 0.790790, -10.697310, -0.557570, 2.423200, 3.758430, -5.248870,
1.077190, 4.950660, 1.089640, -10.920270, -2.722230, 0.643760, 0.176130, 0.260300, -0.206720, 0.345240,
1.869010, 0.533790, -6.304070, 1.175220, 1.765440, -0.411750, 2.017270, 1.050290, 0.801650, -2.055960,
-0.805560, 1.603000, -0.233640, -0.516360, 0.905480, -1.500440, -1.915420, -3.773060, -1.319890, 1.481040,
-0.451810, -0.518300, -1.106510, 0.054980, -2.457600, -1.406140, 0.607640, 0.659230, 0.470620, 1.069470,
-0.188300, -0.540900, 0.270880, -0.265760, 1.451330, 1.447960, 1.338040, 0.619500, -1.921180, 0.469390,
0.342690, 0.703910, -0.597060, 0.925920, -2.196840, 1.501930, 0.360920, 1.528080, 0.127370, -1.585980,
2.697310, 0.447450, -0.488210, 0.648600, 0.313680, -1.509250, -0.430500, 0.273180, -1.300220, -0.267660,
-0.842140, -1.199640, -0.355450, -0.237180, 0.078090, 1.549820, -2.139310, -2.783840, 0.494290, 0.473290,
1.550720, 1.297300, 0.221020, 0.422710, -0.732800, -0.491710, 0.960550, -0.232520, -1.428270, 0.497030,
1.276280, -0.041900, -2.643400, -1.026430, -3.144690, -0.473620, -0.944520, -1.251620, 0.432910, 0.853350,
-0.225880, 0.964340, -1.202010, 0.677870, -2.249580, 2.340430, 0.351830, -0.734120, -2.539500, 0.729740,
0.746140, 0.555240, -0.095460, -0.742670, 0.831330, 1.045240, -0.033230, -0.624370, 0.237120, 0.079400,
0.150910, -0.394090, 1.729640, -0.553340, 0.334570, -0.825400, 0.217960, -0.866380, -0.839290, -1.567780,
1.098390, 0.542920, 0.078580, -1.336140, 0.243070, -0.880000, 0.981140, -0.191450, 0.446940, -0.126140,
-0.596140, -1.086020, 3.679230, 2.571010, 0.511090, -0.577770, -0.717800, 0.266940, -1.074120, -0.072250,
-0.443350, 0.759010, -0.649770, 0.121170, -0.962240, -0.245980, -1.123210, 0.978590, 0.910690, 0.825670,
-0.410960, 0.064430, -0.104620, 0.356920, 2.155470, -0.967440, -0.974990, 0.436280, 0.181250, -0.150410,
-0.760010, 0.715060, 0.775720, -0.609010, 0.226750, -0.644680, 0.258610, -0.055920, -0.234870,
1.320200, 0.383630, -0.533790, 0.607740, 0.774320, 0.172470, 0.175140, 1.179690, -0.433790, 0.522090,
-0.271200, -2.791560, -0.999560, 0.248710, -0.663420, -1.301070, -0.408430, 0.777600, -0.856780, -1.933500,
-1.026540, 1.774110, 0.172250, 0.077840, -0.488620, 0.297410, -1.718860, -2.303870, -1.110160, 0.537630,
0.377880, -2.769500, 0.526760, -0.510550, 1.630770, -0.312010, 0.972470, -0.770930, 0.422840, 1.000310,
-0.686100, -0.433190, -1.577490, -5.153130, 1.257850, -0.763390, -0.166930, 0.519700, 0.350580, -0.246570,
-0.700570, 0.805460, 1.134870, 0.908720, -0.035790, 0.397350, 0.036750, -0.377250, -1.218030, -0.247020,
-0.287200, -0.529100, -1.224470, -0.664500, -0.044940, -0.093340, -2.049360, 0.202060, -2.510620, 3.157430,
0.701370, -0.348730, -0.393450, -1.644660, 0.783890, 0.862050, -1.145720, 0.512200, 0.469510, -0.609060,
-0.565430, -0.070330, 1.530410, -2.076620, -0.498910, -1.801110, 0.220140, -0.114330, -1.875480, -1.298500,
0.034710, -0.107550, -1.705690, -0.025670, 0.100190, -0.626010, -1.434260, 0.310760, 0.370210, 0.378650,
-1.361780, -3.541880, -0.154040, 1.635360, -0.257140, -4.754870, -1.586750, -1.434290, -0.411210, -1.694730,
0.818910, 1.750510, -2.675230, -1.386870, 1.632060, 0.722350, 0.645350, 1.285980, -3.643030, 0.408160,
-1.148910, 0.696060, 1.355230, 0.438400, 2.118060, -0.369720, 0.471440, 1.363010, 0.968680, 0.201430,
1.685150, -0.742210, 4.603420, 0.306300, -0.758530, 4.188970, 3.772810, 1.583570, -0.318080, -0.097150,
-1.543330, -1.873000, -7.363680, 0.533180, -0.309020, 0.959430, 0.971280, -0.579290, 0.147480, 0.426990,
-1.125170, -0.050220, 0.520510, -0.184450, -0.844600, -4.890140, -0.488170, -1.004620, -1.104130, 0.527490,
-0.042680, 0.047730, 0.826850, 0.880880, -4.951210, -1.040350, -0.345990, 0.317570, 1.009380, -0.182190,
-1.396380, -1.296340, -2.023340, 1.541100, -0.481710, 1.018220, -1.666470, -2.895380, -0.060410, -3.208650,
-2.588150, -1.570250, 0.174940, -0.209010, -0.537420, 5.792050, -1.079180, -4.229800, -2.152800, -0.300280,
0.726500, -1.242420, 0.261450, -1.108600, 1.047520, 0.362300, -0.137280, -0.781700, -1.317460, -1.159250,
0.992240, 2.133570, -4.764950, -0.512890, -1.232270, 0.811020, -0.202850, -0.921470, -0.510560, -1.453630,
-0.735990, 1.518970, 0.830740, 1.422440, -0.427280, -0.267480, 6.575510, 1.195690, 0.108820, -1.288970,
-1.084350, -0.202190, -0.814080, 0.763370, 1.031230, -1.802800, -2.387200, -1.049500, 0.167050, 1.223730,
-1.341420, -0.574750, -0.253770, -2.118080, -0.147840, -0.197380, -0.896050, 0.055550, 0.085100, 1.157550,
-0.038900, 0.044890, -2.140210, -0.146440, 1.180040, -1.167130, -0.117650, -0.227810, 0.283550, -0.530500,
-2.074800, -0.957310, -0.197910, 0.697090, -0.400480, 0.475950, 0.751610, 1.312880, -0.608440, -0.657200,
0.429700, -0.658340, -1.024940, -1.654720, 0.877800, -1.146410, -0.048370, 0.639650, 0.054260, 0.317850,
0.034830, 0.184490, 0.400510, 0.039540, -0.883350, 0.874880, 0.135880, -0.294660, 0.095700, -0.615390,
-0.912500, -0.686970, -0.261490, 0.307910, 0.642510, 0.457600, -0.701320, -0.632230, -0.434130, -0.384260,
-0.896160, 0.830970, 0.781440, 0.130320, -0.935980, 0.579900, -0.728990, -0.729360, -0.891570,
0.426100, -0.011810, -1.957360, 0.341160, -0.196790, 1.529010, -1.045490, 0.485780, 1.325290, 0.133340,
-0.745350, 1.095640, -1.019060, 0.498640, -0.628670, -0.476040, 0.900580, -0.128610, 0.335730, 1.117040,
2.110770, -0.165890, 0.619740, 1.525350, -0.392550, -0.298410, -0.244350, -0.731110, -0.840010, -0.852640,
0.072690, 0.275850, 1.163650, -0.341340, 3.556770, 0.042170, -0.526450, -1.039970, -0.228720, 0.160760,
0.029760, -0.650360, -1.030250, -0.746000, 0.018900, 4.153620, 0.814250, 0.450990, 0.859480, -2.757890,
0.730190, 0.871180, 1.043750, 0.065460, 1.247810, -0.208860, 1.192760, -0.143300, -0.212730, -0.960350,
1.296500, -0.190510, -0.335080, 0.372720, 0.866580, -1.111850, 0.326100, -0.592750, 0.359770, 0.707100,
0.481630, -1.127570, 1.413060, 1.359960, -0.138230, -1.986160, -0.331910, -0.071460, 0.853990, -1.474280,
0.504810, -0.214290, 2.134550, 0.617110, 1.383550, -1.459420, -1.335930, -1.279310, -1.708020, 0.727190,
-0.591020, 0.426920, -0.310720, 0.731720, -0.436050, -0.579800, 1.101970, -1.265850, 0.913130, 0.091170,
0.049110, 0.119110, -0.018840, -0.162770, 1.182880, -0.136760, -0.010450, 0.751830, -0.553230, 0.121430,
-1.037110, 0.667710, 2.006830, 0.460320, -0.573550, -0.727920, 1.118200, -2.435110, 0.391810, 2.268290,
-1.088020, 2.463690, -0.627610, -1.886170, -3.227010, 0.059620, 2.803470, 0.144990, -2.186990, 0.629930,
1.537350, -0.486680, -3.516450, 0.427130, 0.625960, -6.660540, 0.243200, 0.528130, -0.841690, -1.084880,
-0.756000, 0.302050, -0.589470, 0.328930, -0.157400, -1.033280, -0.152180, -0.175130, 0.804610, 0.240340,
-2.703950, -0.861530, 0.341550, 1.829460, 0.333850, -0.205110, 1.370700, 0.308590, -1.017170, -0.295260,
3.949850, -0.087690, -0.690800, -0.940030, 0.958970, 0.012880, 0.365580, -1.953390, -2.812350, 0.427480,
0.367520, -2.222170, 0.906070, -1.419570, -1.166850, 0.361260, -1.173130, 0.525360, -0.113440, -0.340300,
1.021230, -0.227430, -0.177310, 2.400150, 0.444150, -0.294400, 0.018010, 2.202460, -0.000530, -0.804850,
1.052080, -1.696080, -0.106740, 0.480830, -3.626610, -0.817070, 0.584090, 3.328440, -0.429660, -0.922880,
0.745360, -1.437190, 0.130270, 1.132190, -0.494760, 0.493680, 1.736300, 0.348740, 0.033230, 0.228820,
0.329580, 0.235300, 0.422990, -0.333990, -1.466110, -0.745220, -1.940640, -0.651240, -0.143590, 0.799870,
0.287790, 1.446980, -2.279830, 1.112230, -1.180070, 0.616540, 2.187100, -0.050490, 0.803260, 1.075270,
0.285520, 0.088360, 0.323800, 0.766150, 0.261340, -1.400040, -1.161600, -0.429490, 0.705660, 0.622420,
0.152540, -0.482120, 0.719080, -0.508160, -0.617820, -1.449650, 0.215190, 0.882060, -0.635930, -1.263350,
1.891480, -0.045560, -0.360270, 0.679820, 0.520530, 0.381410, 0.643010, -1.194580, -3.543590, 0.454730,
1.991350, 0.776770, 2.346560, 0.783010, -1.218190, 8.214210, 0.591210, 1.656770, -0.949700, -0.605550,
0.036740, 0.400380, 0.396660, -0.867300, 0.532720, 0.455020, 0.742400, -0.882560, -0.432190, 0.199500,
0.087690, -0.883210, 0.709720, 0.086260, 1.083840, -0.006440, 0.491620, 0.785330, 0.814350, 0.446840,
0.931950, 0.573620, -0.151140, -0.365780, 0.767400, -0.959000, 0.133260, -0.393380, 0.466610,
0.097280, 0.217280, 0.325880, 0.931250, -0.337140, -0.258480, 0.036480, 0.979340, -0.730210, -0.951380,
-1.109440, -0.578450, 0.178840, 0.289860, 0.336750, 0.433160, -0.576340, -0.657510, -0.889360, 0.486840,
5.742100, 0.375330, 1.670140, 1.337280, -0.955500, -2.292900, -1.338300, 1.132730, -0.945720, 0.101750,
0.379800, 0.446630, -0.268000, -0.295490, 0.486650, -0.863550, -0.045830, -1.265910, 0.904630, -0.374410,
-0.651730, 0.304360, 0.486500, 0.789690, 0.425630, 1.392870, -0.175710, 0.729400, -0.928770, -0.035820,
0.882440, -0.443260, -1.599120, -1.221670, 0.208740, -0.939420, -0.723720, -0.339450, 0.344250, -0.097990,
-0.761860, -0.126030, 0.016550, -0.261200, -0.643730, 0.301240, 3.690270, -0.461070, 0.104700, 0.418430,
-0.456140, -0.201530, 0.611070, -0.617580, 0.098310, 0.797110, -2.524890, 0.048320, 1.609970, 0.906540,
-2.859380, 0.220780, -0.716840, 0.341380, -0.690220, 0.282010, 0.783020, -2.646660, 0.615930, 1.551640,
-0.463450, 4.329090, 2.590430, 0.045170, -0.163790, 0.181200, -0.280200, 0.070190, -0.815520, 0.165570,
0.204510, 0.565870, 0.493090, -0.859310, 0.072440, 1.738590, 0.146430, -0.612830, 0.397580, -0.473580,
0.510470, -0.124960, 2.301450, -1.370080, -1.929860, -4.205700, -4.198260, -0.544380, 4.528820, -2.379700,
-2.240390, -0.018920, -1.188280, -4.288100, -2.433470, 1.208820, 2.279610, 0.185800, -4.522520, 3.059890,
4.838530, 0.471260, -4.658600, 0.081650, 1.025070, -11.911840, -0.161730, 8.317560, -0.779380, 1.924250,
-1.123690, 0.881820, -0.291320, 0.584290, -1.375740, -0.003840, -0.577860, -0.370700, 0.164880, -0.015460,
0.784270, 1.939020, -2.841600, -0.314060, -0.970240, -0.271180, 0.847360, -0.164340, 2.408340, -0.527030,
1.432960, -1.032780, 1.791170, -1.839320, 2.496070, 0.683580, -0.414720, -1.002480, -0.573340, -0.467210,
-0.823530, -1.303140, -0.932360, -1.148450, -0.584680, -0.938250, -1.102410, 0.072980, -0.882460, -0.771670,
0.841440, 0.502480, 0.213120, -0.085650, 0.311760, -0.678680, -0.332310, 1.373290, -0.736780, 0.456860,
0.527490, 0.039860, -0.033190, -1.261350, -0.673990, -0.293050, 1.959530, -0.020420, -0.101670, -0.646190,
1.750670, -2.165180, 0.129520, 1.076890, 0.872230, 0.007460, 1.283160, 0.138430, -2.529110, -0.081740,
-0.901770, 0.387940, 0.036920, -0.668810, -0.828100, 0.590920, 0.264680, 0.283900, 0.320370, -0.056040,
0.079100, -0.211800, -0.689850, -0.895740, -1.116520, -0.668590, -0.890590, 1.304840, 1.202100, 0.557860,
0.767560, -0.843940, -1.810120, -0.860180, 0.253330, -0.454450, -0.915210, -0.251060, 0.642690, -0.282680,
-0.394610, -0.478070, -0.531430, -0.044390, -1.338470, 0.549950, -0.493690, -1.195100, 0.380290, -0.002310,
1.458550, -0.564240, 1.755430, -0.528900, -0.071970, -0.372730, 0.726410, 0.393630, 0.287440, -1.271140,
0.010330, 2.637790, 0.592110, 0.973610, -0.852740, 0.189930, 0.287220, 0.168240, -0.423170, -0.030920,
0.048850, 0.825200, 0.211610, 0.686900, -0.609620, -0.470120, -0.138100, -0.876970, 3.672940, -0.985360,
-0.426780, 0.535970, -0.387990, 0.354700, -0.593480, -0.841030, -0.109930, -0.004130, -0.347680, 0.231980,
-0.274710, 0.823990, -0.341840, 0.130010, 0.783520, 0.415060, -0.140280, -0.022490, 0.926100,
-0.259550, 0.299490, -0.338890, -0.127170, -0.352650, -0.137380, -0.913740, -0.062500, -0.665690, 0.252800,
0.455510, -0.337290, -1.417250, -0.417360, 0.268150, 1.245050, -0.597030, -1.313240, -0.250070, 0.224500,
0.319820, -0.609200, 0.612900, -0.834710, -0.212770, 0.675570, 0.863170, 0.065060, 0.307680, 0.250620,
1.742310, 0.251760, -1.043650, 0.602570, 0.151320, 1.301460, 0.782240, 0.065700, -0.002240, 0.630840,
-0.314690, -0.085450, -0.531440, 0.051380, -1.164540, -0.827890, 0.679390, -0.204360, 0.950180, -0.943820,
-0.900320, 0.251430, -0.366270, 1.547700, 0.424210, -0.674720, 1.491150, -0.430990, 0.187650, 1.013930,
-1.351400, 0.052290, 0.856450, -0.592830, 1.063400, 0.872590, -0.330500, -0.633330, -0.697800, -0.143610,
0.899000, -0.229940, 0.528000, -0.474020, -0.242570, 0.105720, -0.051320, 0.299360, 0.878410, 1.019880,
0.775350, -0.484720, -0.243180, 0.353280, 0.501990, 0.900160, 0.551790, 0.008340, 0.305950, 3.611170,
-0.524220, 0.404970, -0.141540, 0.909860, 0.731820, -0.909880, 0.768790, 0.127770, -1.502800, -0.525440,
0.280740, 1.043050, 0.134880, 0.523690, -0.036990, -0.666810, -0.420270, -0.023070, -0.799350, 0.572510,
-1.279850, 0.163070, 0.223750, 0.497350, -1.569200, 0.064910, -1.417160, -0.485780, -1.120830, 0.757670,
-1.209020, 0.514820, -0.484290, -0.346200, -3.552930, 0.102470, 0.347550, 0.058360, 1.184130, 0.815580,
0.595370, 0.761370, -1.485590, 0.621340, -0.790040, -4.572610, -0.550620, -0.737640, -0.144730, 1.207570,
0.560280, -0.134900, 0.294290, 0.821200, 0.001720, 1.112940, -1.707590, -0.547840, 0.284080, 0.693520,
-0.144660, -0.717810, -1.515800, 0.262580, 0.307840, -0.887160, 0.021350, -0.083890, 0.343700, 0.011610,
0.352000, 0.561370, 0.576210, 0.680150, -0.009390, 0.420770, 0.645070, 0.295050, 1.726180, 1.031820,
0.821700, 0.987740, -0.176260, 0.336840, -0.955190, -0.203000, -0.290020, -0.908680, -0.201360, 0.659290,
-0.284710, 1.522720, -1.241620, 0.437140, 0.422160, 0.075570, -0.025160, -0.101160, -0.383420, 0.743620,
-0.200860, -1.075630, -0.552600, -0.212000, -0.261320, -0.548550, -0.118100, 0.585630, -1.330540, 1.099680,
1.174800, -0.237120, -0.137470, -0.661680, -0.039400, 0.756130, 1.781160, 0.953630, -0.135270, 1.455680,
0.914030, -0.717200, -1.018720, 0.141660, 0.610460, 0.063750, -0.819830, 0.866600, 0.937390, 1.275640,
0.222400, -0.116280, 0.182930, 0.870240, 0.120340, 0.354550, -0.714570, -0.867360, -0.016800, -0.799990,
-0.553440, -0.176880, -1.394420, 1.296090, -0.442190, 0.017040, -0.563190, 0.385310, -1.319490, 0.501970,
-0.663930, 1.297530, -0.347070, -0.266970, 0.087790, -1.502310, -1.093920, -3.142530, -0.362630, -0.072840,
0.708140, -0.110790, -0.695080, 1.852930, -1.042040, -1.833080, -0.064880, -0.676740, 0.749450, 0.328880,
0.956390, 0.478600, 0.582020, 0.057730, -0.634310, -0.199280, -0.909720, 1.143700, -0.236860, -0.359940,
1.191270, -0.410530, -0.337320, 1.009370, 0.805550, 1.547540, 0.300450, -0.066870, 1.087230, 0.976110,
-0.588930, 0.235250, 0.370720, -0.322380, 0.567380, 1.085110, -0.226260, 0.827400, 2.057990, 1.493330,
-0.154160, 1.042870, -0.713200, -0.186740, 0.181410, 0.253380, 0.896470, -0.437870, 0.323480,
-0.746620, -0.132580, 0.142740, 0.637770, 0.095190, -1.169160, 0.772630, 1.682210, 0.919370, 0.068880,
-0.996980, -0.363000, 1.307910, 1.605410, 0.228180, 0.183840, -0.240070, 0.470860, 0.217320, -0.267040,
1.002730, -1.699650, 0.566490, 0.177520, -0.602050, -0.954410, -0.532050, 0.250750, -0.549920, -0.051630,
-1.043750, -0.074260, -1.253360, 0.040290, -0.722100, -0.086240, -0.333100, -0.103670, 2.405640, -0.182940,
-0.935500, 0.763660, -0.422690, -0.472630, 0.346990, 0.090370, -0.624760, 0.159170, -0.161770, -0.683160,
0.336180, -0.191850, -0.807340, 1.314320, -0.177780, -0.836000, -0.984010, 0.174930, 0.546280, 0.604380,
0.092770, -0.304590, -0.264630, 0.462210, -0.896240, -0.037500, 0.110040, 1.007860, 0.284670, -0.936530,
0.066550, -0.161340, 0.182660, -1.120250, -0.950010, 0.118340, 0.886350, -0.851980, 0.242330, -0.441470,
-0.806480, 0.053700, -0.845710, 0.005780, 0.864030, -0.678680, -0.182650, 0.083650, 0.078080, 1.259660,
0.393620, -0.048430, 1.689790, 0.108650, 0.262730, -0.908310, -0.842980, 0.278940, -0.471890, 0.813250,
0.616150, -0.608320, 0.046310, -0.294580, -0.797550, 0.201270, -1.716050, 0.303280, 0.658430, 0.000070,
-1.964250, -0.995560, -0.060170, 0.781410, 1.524890, -0.336550, -0.777160, -1.703320, 0.623350, 1.664260,
-0.372900, 1.770040, 0.498920, 0.252800, -0.162470, 1.115310, 0.476750, 2.483270, 0.297330, -1.538730,
1.633410, 2.062630, -1.049320, 0.885860, 0.615900, -1.841140, 0.052630, 1.536240, -1.453440, 0.208430,
-0.757650, 1.128080, 1.052630, 0.096250, 0.104090, 0.995640, 0.546390, -0.907900, 1.626890, 0.165980,
-0.230510, -0.929310, 0.115420, -0.369520, 0.889690, -1.941460, -0.992840, -1.296650, -0.263500, -0.226120,
1.354830, 0.151770, -1.516530, 1.608060, 0.638690, 1.748750, -0.653770, 0.557280, 1.000410, -1.289350,
0.006990, 2.189550, 0.847440, 0.215410, -0.346870, -0.370410, 1.182840, 0.405040, 0.140390, 0.630880,
-0.154200, 0.521910, 0.081950, 1.079170, 0.184040, -2.067210, 1.222030, 0.136160, -1.956640, 0.225590,
0.777010, -0.433390, 0.667380, 0.496610, 1.149610, 1.441590, 1.212450, -1.694870, -0.107490, -1.176630,
0.742150, -2.278450, 1.193010, -0.816340, -0.600240, -1.266930, 2.017820, -1.169500, 0.062770, -0.823530,
-1.356310, -0.898620, -0.170540, -0.923700, -0.453060, -0.465430, -0.306490, 0.114990, -1.992070, 0.355930,
3.101150, 0.551730, -0.204830, 0.024130, 0.013010, 1.631520, 0.267850, 0.184650, 0.450540, 0.853820,
0.043690, -2.082580, 0.762850, 0.637500, 1.119250, 0.655260, -0.153020, -0.565220, 1.444290, -1.618700,
0.698340, -1.349010, -0.120990, -0.188820, -0.278000, 2.483630, -0.925640, 1.420330, 0.583420, 1.009560,
0.660660, -1.033180, 0.014740, -1.028280, 0.981960, -0.948780, 0.674180, -0.478450, 0.353660, 0.252330,
0.552030, 0.003440, 3.103100, 1.190900, -2.240990, -1.067910, 0.470030, 0.371290, -0.776230, 0.639910,
0.020370, 0.865010, -0.976460, -0.156160, 0.601650, -0.118340, -0.490880, 0.198940, 1.109190, -0.951100,
0.429630, 0.418040, -0.037160, -0.128920, 1.667650, 0.492160, -0.429880, 0.273010, -0.531060, -0.504870,
-0.770820, -0.553560, -0.314020, -0.534010, 0.973880, -0.189550, 0.657100, 0.087790, 0.152640,
0.495850, -0.334860, 0.245580, -0.705450, 0.086760, 0.025090, -0.699680, 0.991390, 0.350220, -0.660980,
0.257100, 0.361340, 0.638990, -0.782910, -0.850570, 0.091460, 0.470970, 2.139810, 0.569180, -0.591140,
0.750770, 1.448990, -0.680440, -0.299010, 0.187200, 0.137240, -1.064550, -1.603020, 0.124120, 0.735070,
1.560960, 1.207970, 1.665500, 0.332840, 0.258910, -0.386920, -2.708890, 0.678880, 0.283750, -1.057000,
2.032710, 0.177390, 0.244660, -0.243210, 0.980700, -5.090840, 0.263140, -0.638410, 0.273110, -0.789310,
-0.448360, 1.110640, -0.096340, -0.628220, -0.019400, -1.459100, -0.393240, -0.325480, 0.547510, 0.211820,
0.622100, -0.709170, 0.213150, 1.577900, -1.520520, 2.122710, 0.793850, -2.295800, 0.074020, -0.907130,
-0.105880, 0.667290, -0.047010, 0.065570, 1.058980, -1.122520, 1.351090, 0.762000, -0.281910, -1.328850,
-1.175990, 0.007180, 0.723880, -0.240170, -0.319840, 0.669740, -0.492440, 0.120120, -0.344100, -1.200280,
-0.104050, -0.166380, 1.153600, 1.847650, 0.808690, -0.190900, -1.009850, 0.845450, -0.835660, -0.090760,
1.812940, 0.746350, -0.906410, 0.056600, -0.498430, -0.940310, 0.657710, -0.766290, -0.711920, -0.217360,
0.171540, -2.790650, -0.249140, -0.321570, -0.243590, 2.455770, 5.183370, 1.316270, 0.034340, 0.034490,
-0.170480, -3.429740, 1.470020, 1.488730, 1.997680, -1.158230, -1.751370, -1.818900, 0.425810, 1.055900,
-1.087660, -1.173100, 7.580880, -2.384730, -1.457450, 19.855810, 0.742300, 0.520700, 0.282370, 0.278060,
-0.332230, -0.527110, 0.363100, -0.953250, 0.856370, -0.364090, 0.134260, 1.095410, -0.218700, -0.971980,
-0.295070, 0.702790, 0.975750, -0.424290, 0.658070, -0.227550, 0.801090, 0.437140, 0.273070, 0.672750,
0.138940, -1.193990, 0.780760, 0.137580, -0.385830, 1.238090, 2.377560, -1.028260, -1.368800, 0.380530,
0.094280, 1.250800, 0.117500, 0.306640, -0.554240, -0.369030, 0.089400, -0.382760, 1.045310, 0.204950,
-0.773380, -1.010200, -0.732060, -1.547330, 0.794610, -0.068330, 2.034380, -1.358090, 0.547430, 0.056320,
0.184960, -0.646280, 0.413920, 0.435570, 0.076880, -0.264430, -0.482840, 0.849930, -1.129980, -0.450940,
-0.131300, -0.189480, 0.234580, -1.326590, -0.458660, -0.694500, 0.694770, -0.230890, 0.944480, 1.668820,
0.199150, -0.114910, 0.238390, -0.869060, -1.008190, -0.308300, -1.060690, 0.233510, 0.544790, 1.800160,
-1.564400, 0.752300, -0.795700, 0.232430, -0.006510, -1.142130, -0.006210, -1.424850, -0.726690, -1.085190,
-2.522290, -0.104020, -0.768990, -0.893770, -0.557430, 0.034190, -0.546800, -1.256590, -0.331280, 0.866110,
0.769010, -0.175470, -0.393700, -0.337340, 1.508000, -1.075040, -0.691770, -0.133080, -0.271200, -1.734030,
-1.129330, 0.048800, 2.506410, -0.089770, -0.957770, 0.466540, 1.264040, -1.295780, -0.430730, 1.402940,
2.878570, 0.290970, -1.933770, -1.434070, 0.406250, -3.213130, -0.022240, -0.519130, 0.013900, 0.056530,
-0.969110, -0.520400, -0.695160, 0.524750, -0.502040, -0.486900, 0.261410, 0.522650, -0.149790, 1.144370,
0.135940, 0.243030, 0.652340, -0.676110, -0.063000, 0.338770, -0.379560, 0.361050, 0.651080, 0.952580,
-0.048980, -0.471120, 0.526970, -0.167210, 0.868200, 1.659310, -0.356670, 0.963040, 0.020910,
0.494810, 0.500230, -0.562190, 1.722470, -0.036130, -0.298580, 0.119650, -0.210010, -1.020650, -0.541010,
1.142000, -1.053630, -0.220500, 0.293920, 0.069090, 0.896270, 0.675730, -0.231490, 1.355010, -0.144200,
0.380720, 0.686960, 0.853250, 0.616020, 0.574160, 1.008710, -0.420730, 0.691830, 0.138100, -0.366120,
-0.764970, 0.747520, 0.905310, -0.374860, -0.288260, -0.099590, -0.689260, 0.141180, -0.790110, -0.027940,
1.337250, 1.414110, -0.836880, 0.926010, 0.267310, -0.235770, 0.962260, 0.400430, -0.022780, 0.484270,
0.127280, 0.011850, 0.244730, -2.169110, 0.319410, 0.830110, -0.920820, -1.339850, -0.086630, 1.163980,
0.252250, 0.633450, -0.499530, 5.306150, -0.971330, 0.699030, 0.557330, -0.325110, 0.701030, -1.445360,
-0.716030, -0.738520, 0.796590, 0.295850, -1.913870, 0.887730, 0.154480, 1.723190, 0.384460, 0.116350,
-0.371390, 2.014620, -3.342940, -0.105940, -0.748670, -0.662990, -0.033290, 1.566760, -0.094790, 0.651080,
1.195000, 0.652860, -0.131480, 0.702470, 0.849830, 1.306680, 0.561430, -0.037400, -0.826560, -0.488680,
-1.255170, -0.759890, 0.818390, 0.499350, -0.903880, -0.544080, -0.878050, -0.639950, 0.567300, 0.752340,
1.417000, 0.608190, -0.398320, -0.159950, 0.918680, 0.178530, 1.700740, -0.867260, 0.916520, -0.117770,
-0.498120, 0.311280, -2.446890, -0.355420, 1.302820, 0.501240, -0.415820, -0.909440, -0.091680, -0.262760,
-1.810630, -0.905030, -0.312760, -0.192710, -0.239230, 1.643840, -0.310810, 2.426980, 0.288120, -5.355470,
-0.340380, -0.349350, -0.205600, 0.665760, -0.496830, 2.672330, -0.489510, 1.470450, 0.325920, -0.204180,
-0.377500, -0.645160, 0.693880, 0.965890, 0.658240, -1.644450, 1.691030, 0.078560, -0.404420, 0.233100,
-0.056000, -0.116250, 1.158140, 0.451560, -0.261580, 0.226010, 0.747780, -0.347730, 0.204100, 0.727260,
-1.163990, 0.989970, 0.914120, -0.203730, -0.689320, -1.892910, -1.075500, -0.741170, -1.256760, 0.482610,
-0.027920, -0.713630, 0.398950, -1.113230, -0.139430, 1.410650, 0.945940, -1.034460, -0.171940, 0.000840,
-0.439080, -1.704140, 0.564990, -0.699990, 2.233380, -0.888200, 1.222640, 1.186560, -0.497280, -1.175300,
-0.293860, -0.037500, -1.275180, 0.620800, 1.115840, 0.301760, -0.763280, -0.505350, 0.110910, 0.496250,
1.431400, 0.688570, -0.027240, 0.223690, 0.225130, 0.310530, 0.358510, -0.688840, -0.462480, 0.176570,
0.769800, -0.383940, -0.899540, -0.197540, 0.598010, -0.456070, -0.142210, 0.097710, -0.769190, -0.961380,
-0.894920, 0.484510, 0.048840, 1.339910, -0.020570, 0.876360, -0.481480, 1.829880, 0.550030, -0.211970,
-0.478550, -0.358890, 0.915810, -0.770570, -0.575370, 0.704700, 0.870130, 0.011190, -0.302710, 0.121090,
-0.728660, 0.793020, 0.139640, -4.667750, -0.032150, 1.235740, -1.748250, 2.671080, 0.778480, 1.230340,
-0.186970, -0.694240, -0.743580, -0.593520, 2.338340, -0.589110, 0.260430, 3.071110, -1.160260, -0.313270,
-0.738900, -0.277160, -1.499550, 0.216380, -0.036150, -0.468870, -0.229920, 0.249290, -2.354390, 0.448470,
-0.779920, 0.257140, 0.371410, -0.465560, -1.048710, -1.204740, -1.029200, -1.246370, -0.709010, -0.999400,
-1.468740, -0.725130, 0.482630, -0.653590, -0.437420, -1.609900, -1.481570, -0.295700, -0.553350,
1.454520, 0.288980, 0.334990, 0.797330, 0.998090, 0.872230, -1.709740, 0.399270, -0.210120, 1.080640,
-0.863010, -1.007300, -0.046450, 0.382030, 0.328080, -0.417480, -2.593510, 0.555100, -0.106380, -1.960590,
-0.042150, -0.410220, -0.944680, -0.273290, -1.441670, -0.545250, 0.733380, 0.845230, 0.261880, 0.899700,
0.212740, -2.318350, -1.293230, 1.182880, 0.335870, -0.937560, 0.484840, 0.582940, -0.603520, 0.700400,
-1.638580, 0.071460, 0.450710, 0.304730, 2.022210, -0.419160, -2.710600, -1.788980, -1.173300, 0.865280,
-0.807650, -1.053960, -0.034980, 0.146360, -1.202630, -1.965260, 0.516410, 1.314910, -0.382160, -0.522050,
0.707930, -0.370580, -0.038630, -1.590400, 1.530310, -0.866160, -0.085110, 0.620950, -0.357660, -1.514980,
-0.744880, -0.208600, -0.266220, 0.257120, 0.008880, -0.921340, -0.013500, 0.601600, 0.421650, 1.919510,
-0.010540, 1.891210, -0.297160, 0.054990, 1.867580, 0.104790, 0.894020, 0.422940, 0.900600, 0.331960,
0.362700, -0.936320, -1.112490, 0.697030, 0.265820, -1.192200, -1.203900, -0.494860, -0.721450, 0.033520,
-1.810550, 0.127800, 0.983400, -0.031340, 1.060550, 0.248500, -1.046970, 0.360130, 0.831760, -0.061540,
0.624720, 0.776550, -1.241020, 0.669000, -0.565040, -4.501150, -3.490990, -2.635590, 0.266780, -2.380710,
1.078850, 3.327440, -2.099300, -2.501940, -2.522630, 2.827590, 4.129440, 1.167160, -0.870840, -1.284210,
1.674160, 2.219280, -2.900930, 2.328110, 1.931720, -0.325910, 11.086250, 1.445990, -0.392820, -0.183410,
-0.536020, -2.553360, -0.095040, 0.016260, 0.593610, 0.937070, -0.987070, 0.003260, 0.450280, -0.080540,
-0.645060, -1.001350, -0.350440, -0.536120, -0.057430, -0.042270, -0.497190, 0.087090, 1.084080, -0.434340,
0.610450, 1.889350, -0.570310, -0.645870, 0.216600, 0.060220, 1.061530, 0.662060, -0.292100, -2.358020,
0.808230, 0.567380, -0.210450, -0.465610, 0.983570, -0.172020, 0.292950, -0.382010, -0.686620, -0.829740,
0.419910, 0.201580, 0.412240, 0.358970, -0.819680, -0.171160, -1.362930, -0.963930, 0.360380, -0.096790,
0.879060, -0.069890, -0.267520, -0.738780, 0.129470, 0.364010, -0.045010, -0.375510, -1.988790, 0.027770,
-0.722690, 0.276340, 0.960440, -0.449580, 0.125690, -0.259890, -0.287370, -0.799940, -1.137380, -1.470500,
0.952950, 0.548280, 0.352390, 0.587020, -0.879690, -0.147970, -1.592960, 0.433830, -0.548920, 0.265770,
0.994810, 0.085140, -0.231110, -0.188040, -0.978190, -0.020150, 0.194370, -1.625620, 0.320270, -0.532810,
-1.053480, 1.532180, 1.346100, -0.213120, 0.077460, 0.978030, 0.948760, 0.592660, -0.294120, 0.427960,
0.459240, -0.227720, 0.548120, 1.275810, -0.140160, 0.342470, 1.826480, 0.300450, -0.015580, 0.244820,
2.316960, 1.725000, -0.634370, -25.343019, 0.411190, 0.003590, 0.468820, -0.787250, -0.141740, 0.692170,
-0.290510, -1.497430, 6.898970, 0.631320, -0.109170, -0.144540, 0.213110, 0.027650, 0.472890, 0.505050,
-0.486390, -0.338490, -0.355990, 0.185550, 0.440430, -0.788070, -0.727220, -0.928880, -1.210080, 0.398900,
-0.913520, -0.940100, -0.531560, -0.909950, -0.575930, 0.348120, -0.230030, 0.707170, 0.611650, -0.901980,
-0.564810, -0.002690, -0.463060, 0.724180, -0.178720, 0.872880, 0.165100, -0.118670, 0.248470,
1.044730, 0.980200, -0.618480, 0.792890, -0.978990, -0.697110, 0.523350, -0.034460, 0.020120, 0.187100,
-0.398630, -0.199030, 0.697920, 0.469900, 0.439240, 0.315630, -0.600800, 0.393950, -0.590100, -0.105630,
-0.079070, -0.090220, -0.003560, 1.622170, 0.004150, 0.034180, 1.053170, -2.750980, -0.526340, -0.432200,
0.677510, 1.411280, -4.337870, 0.702720, 1.166260, -1.948720, 0.807070, 0.218190, -1.292230, -0.483190,
-3.771310, 0.842340, 1.048820, 0.510110, -0.019840, 0.955730, 0.943330, -1.495590, 0.558910, 0.168030,
0.242430, 0.017040, 0.179080, -2.255870, -1.308900, -0.135070, 0.433800, 0.940020, 1.741660, -0.136640,
-1.022390, 1.253210, -0.748990, -0.062810, -0.851850, -0.393210, 1.410150, -0.599520, -0.608070, -0.677280,
-2.404870, 1.180920, 2.118210, 0.716960, 0.314250, 2.027730, -2.362110, -1.651780, -0.860900, -1.426830,
0.582260, -0.560390, -0.019350, 0.191930, 0.694120, -0.605280, -0.229790, -2.270800, -0.293890, -0.283510,
-1.158980, -0.170270, 0.378930, -1.970320, -0.710210, 2.186570, 0.786900, -3.292220, 0.987180, -1.357640,
-0.028810, 1.235730, 0.100190, 2.326640, 1.508230, 0.209630, 2.654400, 0.744530, 0.933420, -0.641600,
0.300790, 1.174260, 3.361070, -0.200870, 0.340300, 0.807570, -2.720710, -1.634230, -0.731680, -0.822450,
-1.163220, 4.197020, 0.478610, -0.914320, -1.583440, -0.038360, 0.904820, 0.247170, 0.378190, -1.256780,
-0.554220, 1.265280, -3.987650, -0.115410, 0.156340, -20.182270, 1.338290, -1.362210, -1.265590, 1.025710,
-0.791240, 0.847390, 0.146230, 0.108490, 0.518220, -0.271460, -0.677950, 0.464990, 0.115210, -1.463150,
0.087340, 0.708540, 1.004230, 0.271500, 0.370570, -0.332000, -0.095300, 0.009340, -1.406290, -0.174510,
-0.432920, -0.552840, 0.513000, -1.004400, 0.249430, -0.065640, 0.720780, -0.606380, 0.306400, 0.799510,
0.839030, 0.341140, -0.639230, 0.615000, 0.978620, -0.798160, 0.236570, 0.672540, -3.586110, -0.447210,
0.530760, 2.619630, -1.136320, -1.084870, -0.486190, -1.064960, 0.007490, 1.313530, 0.241450, -1.295540,
0.655350, 0.466820, -0.818950, -1.561160, 1.311550, -0.010790, 0.759700, 0.260150, -1.214040, 1.911930,
0.799400, -1.274950, 2.132510, 0.521850, 0.883960, 0.520440, 0.317080, -0.142070, -0.898020, -0.654330,
1.159650, 0.274370, 0.855060, 1.757320, -1.049650, 0.703290, -0.152250, 1.135380, 0.517990, 0.484500,
0.575250, 0.551060, 0.859440, -0.244500, -0.086830, 1.543640, -1.923310, 0.732120, -0.893340, 0.965050,
-1.378610, 0.544130, -1.101970, 0.103420, -0.215360, 0.421670, 0.407660, 0.880830, -0.184230, -0.874250,
-0.187510, -1.018440, -0.781230, 0.392630, 1.212590, -0.643210, 1.669500, -0.000200, 1.324200, -0.419940,
2.826660, -2.589040, 0.211260, -3.115180, -0.107160, -0.166620, -0.099970, -0.327650, 0.016520, 0.186570,
0.150950, -0.115130, -0.505580, 1.116190, -0.997660, 0.794100, -0.430980, 0.759560, 0.982120, -0.614580,
0.182460, 0.905510, 0.403940, -0.801440, 0.202550, 0.187650, 0.773850, 0.803900, -0.144630, 0.579980,
0.642570, 0.179780, 0.582380, -0.921170, -0.756530, -0.829780, 0.131830, -0.809050, 0.822640, -0.172910,
0.177070, -0.059870, -0.314430, 0.173520, -0.964190, 0.336190, 0.421100, -0.675200, 0.978510,
-0.924780, -1.107070, 0.315040, -1.238120, 0.609680, -0.209270, -0.000840, -0.519620, -0.279040, 1.488420,
0.705730, 0.316090, 1.277330, 0.060700, 0.695630, -0.368840, -0.092490, 0.798730, -0.164590, -0.005780,
0.563460, -0.570810, 0.098120, -2.107330, 0.443270, 0.083920, 3.593420, -0.020580, 0.818510, -0.092790,
0.106330, -0.025120, 0.867620, -0.424270, 0.983310, -0.956490, -1.753960, -0.004820, 0.605700, 0.128360,
0.092930, 0.457830, -0.164670, -1.599910, -0.882770, 0.538920, 0.139440, 0.149140, -0.661460, 0.183170,
1.833180, -0.206030, -0.918760, -0.931780, 0.073570, -0.191140, -0.010370, 0.526530, 0.730650, -1.353840,
0.172100, 0.124920, -0.284190, 1.196020, -0.046100, 0.353320, 0.934910, -0.348220, 0.036000, 0.600310,
-0.372990, 1.171800, -0.941920, -0.468040, -0.509890, 0.295970, 0.272190, -0.243420, 0.532080, 0.200820,
1.180830, 1.453200, -0.656890, 0.007900, -0.453440, 0.385200, 1.982420, -0.186230, 0.582940, -1.998660,
0.744260, 0.515040, 0.653370, 0.257830, 0.789750, -0.936840, -0.453580, -0.754130, 0.242910, -0.848630,
1.104460, 0.971390, -1.175510, 0.029640, 0.284710, -0.668350, 0.601200, -1.930390, 0.299530, 0.508000,
-0.532230, 0.009390, -0.345620, 0.168150, 0.599220, -0.459060, 1.229630, 0.737290, -0.560520, 0.771340,
0.313430, -0.676820, -0.979350, 1.672520, 2.279750, -0.339410, 0.709900, -0.798770, -0.708040, -0.566920,
-0.159990, 0.318160, 5.805180, -0.151440, -2.203370, 15.818030, 0.275100, -3.993310, 0.500110, -0.852070,
0.662240, 0.061900, 1.272070, 1.058730, -0.060400, 1.029640, -0.075580, 1.536840, 0.316390, 0.128290,
0.907890, 0.599520, 0.591260, 0.240930, 0.501170, 1.119010, 0.319770, -1.550910, -0.335200, -0.372360,
1.803630, -1.844520, -0.259940, -0.556280, -1.010450, -1.299160, -0.552490, -1.034340, 0.104270, 0.951840,
1.410230, -0.129800, 0.145320, -0.905280, -0.221030, 1.332820, 0.519820, 1.003780, 1.320800, 0.075230,
-0.073490, 0.075690, 0.464040, -0.377270, -0.562260, 1.602210, -1.156380, -2.584540, -0.640180, -0.232460,
-0.495830, -0.639870, 0.211250, -0.439490, -1.798660, -0.176850, -1.185540, -0.133330, -0.380590, -0.556390,
-0.231140, 0.295260, 0.747320, -1.517290, -0.137720, 0.538860, -1.685510, -0.221280, 1.017960, 0.595330,
-0.189360, -0.200220, -1.143900, -0.813950, 0.976510, 0.017360, -0.150570, -1.181400, 0.657820, 1.076760,
-2.658690, 0.586460, -0.656350, -0.839510, -0.248250, -1.282030, -1.110200, 1.799450, -0.336380, 0.893740,
0.168150, -0.598670, 0.413640, -0.367350, 0.387560, -0.324850, -2.342930, -0.298460, 1.248820, 1.253650,
0.199250, 1.751490, -1.917160, 1.185530, -0.807930, 1.588220, -0.688310, 0.307000, 0.289930, 0.502320,
0.365860, -0.135360, 0.398060, -1.383950, 0.601970, -0.455590, -0.291890, -0.680660, -0.494130, 1.278590,
-0.898090, -0.230910, -0.629020, -1.257660, 1.247940, -1.831040, -0.873760, -0.411960, 0.323720, -0.116300,
0.500200, -1.129310, -0.283590, -1.075460, 0.142420, -0.741600, -0.733850, -1.103430, -1.874550, -0.604760,
0.420040, -0.207360, -1.184270, 0.410280, -0.794280, 0.033240, -0.297130, 0.133820, -0.646910, 0.076610,
0.088980, -0.594710, -1.410860, -1.518100, -0.062360, 0.582440, 0.032070, -0.850460, 0.085900,
0.303300, -0.814460, 0.027270, -0.770040, 0.239920, -0.720390, 0.835600, 0.648830, -0.624290, 0.929120,
0.744290, 0.247730, -0.078430, -0.784730, 0.355510, 0.146090, -1.713000, -1.816980, -0.746990, 0.569500,
0.416390, -0.501870, 0.106620, -0.167580, -0.515930, 0.794510, -0.181390, 0.412890, -0.855070, 0.592980,
-0.244980, 0.358940, -0.258960, 0.278100, 0.045130, -0.032590, -0.544370, -0.590870, 0.643200, 0.218940,
-0.829390, 0.126760, -0.772400, -0.619940, 1.364540, -0.501070, 0.399220, 0.159640, 0.976360, -0.092600,
-0.715620, -0.047600, 1.005970, -0.285740, -0.053580, 0.735040, 1.704800, 0.331010, 1.027750, -0.721720,
0.082050, -0.664740, -0.943000, 0.404800, 0.650650, -0.921830, -0.097910, 0.776460, 0.079640, 1.550730,
0.435480, 0.408430, -0.431590, 1.083210, 0.720870, 0.300770, -0.305240, 2.227620, -0.258300, 0.384280,
0.876170, -0.560640, 0.396790, 0.673800, 0.240370, -0.061680, 0.272550, 0.547740, 0.542170, -0.902700,
0.404840, -0.605330, -0.299230, 0.762800, -1.566660, -0.200700, -0.803640, -1.146240, 1.233870, -0.810050,
-0.012690, -0.104470, 1.349460, 0.551900, 0.419430, 0.778280, 0.154860, 0.829620, -0.180010, 0.394620,
-0.430650, -0.086260, 0.132340, 1.037530, 0.557210, 0.650600, 2.802740, 0.065730, -1.343070, -0.807870,
1.033850, -0.265670, 1.672440, 1.314890, 1.514430, -0.924950, 0.606160, -0.711440, 2.172290, 0.180060,
-0.611270, 0.873980, 4.217350, -0.765790, -1.227700, 2.867210, 0.312760, 0.186620, -1.274040, -0.581270,
-0.187430, 0.052300, -0.082670, -0.439640, 1.195500, -0.252690, 0.761170, 0.970200, 0.834520, 0.012680,
-0.409130, 0.203990, -0.083170, -0.457340, -0.679990, -0.857310, -0.281330, -0.902200, -0.066340, -0.898470,
0.448330, 0.693890, 2.047060, -0.254110, 0.246320, 0.902760, 1.142830, -0.275620, 0.703220, -0.219140,
1.139600, -0.573260, 0.640540, -2.035300, 1.065980, -0.403340, -0.876380, 0.131780, 2.248820, 0.190640,
-0.302880, -0.195700, -0.639610, 0.338180, -0.382170, 1.194860, -0.533490, -1.166160, -0.578980, 0.588990,
-0.130690, 0.328310, -0.048760, 0.473360, 1.623650, -0.469710, -0.339850, 0.659510, -0.638210, 0.296830,
-0.241490, -0.072640, -0.795410, -0.026480, -0.439330, 1.118540, -0.147970, -0.358060, 0.751870, -0.077780,
0.104750, -1.079320, -2.964910, -0.556390, -0.810410, 0.234920, -1.068720, -0.110790, 0.938010, 0.056710,
0.758650, 0.025440, -0.219660, -0.350590, -0.089600, -0.132820, -0.906300, -0.072780, 1.240570, -0.340910,
0.279410, 0.805350, 0.357960, -0.918690, 0.463930, -0.443050, 0.541650, 0.024360, 0.689210, 0.350520,
1.032000, -0.509110, -0.902880, -0.467300, 0.262490, -0.816110, 0.543860, -0.655240, -0.937810, 0.323100,
-0.283470, -0.388920, -1.198510, 12.852530, -0.294050, 1.056660, 0.365900, -0.954600, 0.339660, 0.946260,
-0.126100, -0.513800, -2.726630, -2.045930, 1.350820, -0.129200, 0.184990, -0.751010, -0.217400, -1.310570,
-0.612720, -0.958490, 0.226340, -1.410020, -0.166160, -0.351070, -1.226620, -0.770860, -10.668330, 0.228010,
-0.360810, -0.618670, -1.322400, -0.704140, -1.027720, -0.799960, -0.419900, -0.572310, 0.197200, -1.298420,
-0.868550, -0.997570, -0.103060, -0.606890, 0.249400, -0.852800, -1.313510, -1.309690, 0.505110,
0.088260, -0.166550, 1.156580, -2.155680, -1.237380, -0.452560, 1.400960, 1.156590, -0.218050, -1.349580,
-0.063580, -0.187040, -0.371410, -0.750440, -2.092440, 0.201610, 0.559190, 0.545850, 1.975690, 0.625520,
-0.373420, 1.025300, 1.659130, -0.620630, -0.110140, 0.881740, -1.662490, -0.566480, -0.314680, -1.659840,
1.137830, -0.676400, -0.764840, 0.745800, -0.227880, 0.249060, 0.596470, -0.074510, 1.823060, -1.098870,
-0.643190, 0.079340, -0.189740, -0.771310, 0.129680, -2.108950, -0.422920, 0.944720, 2.982850, -0.540030,
0.099060, -1.192330, -0.362410, -0.528330, -1.233480, 1.197700, 0.147150, 1.388830, -0.295500, -1.294410,
0.615730, 0.234620, -0.889420, 1.174290, 0.246610, 0.129210, 0.971230, 0.125110, -0.321110, 1.005240,
-2.235430, -0.127970, -1.263200, -0.894370, -0.100230, 0.061660, -0.076580, 1.583980, -0.092810, -0.236990,
0.965230, -1.242490, -2.134810, -1.647370, -0.580750, -0.145110, 0.109990, 0.744700, 0.528940, -0.750420,
0.897630, -1.283830, -1.857180, -0.211500, 0.100980, -0.731610, -1.096100, -0.928230, 0.023830, -0.963450,
-0.739740, 0.014960, -0.020720, 0.215230, -0.455140, 0.289750, -0.790420, -1.387220, 0.689320, 0.359250,
0.785880, 0.111750, -1.539580, 0.025270, 0.598870, -0.423310, 1.242600, 0.739220, -1.050670, 1.004160,
1.668110, -0.969750, 1.004000, 1.234210, 6.993280, -1.225840, -1.521660, -1.822670, 1.082330, 0.811690,
-0.750620, -2.298560, 5.300030, -3.010080, -0.013550, -0.327130, -1.273880, -2.894790, 0.676580, 0.803820,
0.456670, 0.454170, -0.538170, -2.027330, 0.132640, -0.567990, 1.695950, 0.262010, -0.516130, -0.551910,
-0.891210, -0.481540, 0.145830, -0.217960, -1.423680, 0.700770, -0.370090, -1.274320, 0.140600, -0.065630,
-1.532440, -0.801180, 3.682690, -0.028380, -1.018050, -0.800930, -0.137970, 0.482140, 0.397070, 0.919230,
0.430930, 0.218720, -0.114050, -1.553570, 0.792830, -1.211210, 0.109060, -0.538030, 4.172700, 0.927670,
-1.050030, -1.140380, -0.551280, -0.735100, -0.002110, -0.225000, 1.624260, 0.474590, -0.338860, 0.780390,
-0.656780, -0.873820, 1.105760, -0.226330, -0.974700, -0.237480, -0.715000, 0.504540, -0.013200, 1.131310,
-0.815750, -0.955500, 0.284770, -0.847710, -0.181920, -0.880910, -0.778050, 1.300650, 0.268440, 1.453200,
-0.476240, -0.452220, 0.837750, -2.022230, -0.153670, 0.665730, -0.744450, -1.369530, -0.004390, -0.946450,
-0.163590, 1.952290, 0.241190, -0.136360, 0.798550, -0.475260, -1.846970, -0.646020, -0.735010, -0.777100,
0.494630, 1.019930, -2.007230, -1.688060, -0.573450, -0.112060, 0.444040, -0.896280, 0.252910, 0.517750,
-0.320900, -1.538000, -0.031540, 1.140560, -0.944000, -0.279380, 0.577510, 1.683300, -0.066570, -0.385440,
-1.079190, 0.624480, 0.750590, 8.563110, 0.004610, -0.356560, 0.705240, -1.144070, -0.094000, -1.405820,
0.898090, 0.262000, -6.065850, -0.572940, -0.924130, 1.448570, 0.447800, -0.532310, -0.007030, -0.653670,
0.479050, -0.313570, 0.423060, -0.456480, -0.907650, -0.822760, 0.343720, 0.891020, 1.105270, -0.653180,
-0.253910, -0.317140, -0.461810, 0.073910, -0.375790, -0.534320, 1.496750, 0.743650, 0.337280, -0.276910,
0.215810, 0.919050, -1.008570, -0.113270, 0.119270, -0.660160, -0.698150, 0.571500, -0.248850,
0.393380, 0.174950, -0.514400, 1.119120, -0.264540, 0.662440, 0.502630, 0.196630, -0.036840, 0.976170,
-0.663970, 0.316550, 0.230550, 0.249280, -0.954260, -0.132400, -0.389340, -0.806160, -0.017850, -0.058380,
1.652980, 0.594900, 3.698670, 0.031380, 0.859740, -0.555830, -2.052910, -2.265260, -0.253200, 0.790440,
-0.900300, 0.595810, 0.167040, -0.808010, 0.302550, -0.452710, -0.200930, -0.499440, -1.660390, -1.231760,
-0.631150, 0.165510, 0.072000, 0.662890, 0.128780, 1.933660, -0.696400, -0.589420, -0.826770, 0.905600,
0.705510, 0.275740, -0.814440, 0.964560, 1.593390, -1.488130, 0.807170, -0.888780, 0.217220, 0.325460,
1.802150, 1.195880, -0.300070, -0.382520, -0.307680, -0.352620, 0.809300, 0.786630, 0.878880, -2.256450,
-0.353130, 1.010850, 2.784850, 0.011140, 1.063950, -0.953410, 0.825210, 0.438990, 2.959980, 1.049240,
-0.024740, 0.402680, -0.504420, -1.041760, 0.644600, 1.637410, -0.364070, -0.897080, 0.095200, 2.622370,
-0.260790, 0.256710, 2.874440, -0.635810, -1.177180, 0.336700, 0.114070, -0.797290, -0.760350, -0.343130,
-0.475580, 0.368230, -0.824670, -0.082500, -0.710790, 0.786450, -1.052540, 1.623630, -1.420020, 0.214050,
-0.611160, -1.133310, 0.396970, -1.632300, 0.098330, 0.697550, 0.600650, -0.649010, 6.934360, -0.117190,
-0.163380, 1.916400, -4.300850, -5.682530, -2.165210, 1.724320, 2.579220, -0.626910, 0.571520, -0.972340,
2.307420, 0.906690, -0.485900, 1.512410, 1.351790, -0.587180, -0.210360, 1.086260, -1.442830, -2.539600,
-1.346770, 1.232110, 1.016980, -1.959490, 0.631180, -0.135030, -1.989970, -0.739030, 1.450860, -0.197340,
0.650380, -2.442360, 1.053880, 0.431180, 0.674980, -1.392840, 0.352870, 2.401760, 0.822420, 0.398130,
1.083430, 0.799790, -4.526740, 0.432570, 2.999830, 0.574160, -0.285810, -1.453840, -3.555380, 0.647710,
2.076220, -0.081470, 0.729710, 0.104370, 0.577770, -1.143330, 1.545570, 0.513260, 0.235820, 0.027610,
1.113230, 1.042120, 0.446390, 0.925370, -0.754040, -1.225440, 1.740550, 0.342720, 0.312100, -1.038780,
-0.362610, -0.780540, 0.287840, -0.393880, -0.053180, 1.778220, -0.727070, -0.727440, 1.922180, 1.029600,
0.367010, -1.345060, -0.796840, 0.356640, 0.344800, -0.151980, -0.737960, 0.708610, -1.754370, -1.177030,
-0.150480, 1.312010, 0.300170, 2.897930, -5.472370, -1.102550, -0.596280, 0.370470, -0.276530, 1.614910,
-0.201850, -0.783540, 2.485170, -0.055500, -0.789280, 0.696450, 0.070870, 1.083930, 0.588210, 1.099620,
0.828400, -1.098730, 1.502620, -0.097510, 0.413230, -0.546680, -1.150160, 1.078280, 0.231080, 1.543930,
-0.647440, -0.173060, 2.427600, 0.212210, -0.187900, 0.820330, 0.530590, -0.908730, 0.576160, -1.267180,
0.793640, -0.360040, 0.632780, 0.051570, -1.259070, 0.375490, -1.091520, -0.478970, -1.088250, 1.183550,
0.368230, 0.863750, 2.486240, -0.041960, 0.574950, 0.996220, -1.019510, 0.520360, 0.447520, -0.551970,
-0.901360, 0.066210, 0.264650, -0.629760, -0.873110, 0.608640, -0.334670, 0.281920, -0.515750, -1.192580,
0.013100, -0.243580, 0.592660, -0.612780, -0.097710, 0.924440, -0.208530, 0.670660, 0.709200, -0.155910,
0.613360, -0.011570, 0.267330, 0.954260, 0.237150, -0.673710, 0.384700, -0.893140, -0.787780,
-0.220080, 0.396870, -0.578450, -0.408460, 0.058640, -0.349990, 0.400410, 0.645860, -0.973070, 0.266010,
-0.089720, -0.952720, -0.713740, 0.132560, 0.407510, 0.522710, -0.909520, -0.895470, -0.209720, -0.692050,
-0.943810, 0.892210, 0.169280, -0.375510, 0.849240, -0.272130, 0.455750, 0.999300, 0.572690, -0.922840,
0.162820, -0.911510, 0.321820, -0.559490, -0.886250, 0.684880, 0.625590, 0.745900, 0.522210, -0.590960,
-0.106740, 0.334260, -0.070720, 0.782560, -0.938690, 0.480660, -0.258690, 0.598670, 0.023700, 0.297520,
0.094670, 0.452620, -0.204760, -0.444030, 0.964030, -0.609410, 0.352040, 0.183290, -0.660010, 0.218060,

0.196350, -0.804230, -0.129770, -0.091810, 0.311880, -1.363410, -0.539610, -0.643420, 0.485470, -2.368400,
-1.021280, -0.861870, 1.075540, -0.244900, 0.037300, -0.593370, -0.567560, 1.287740, -0.800850, 0.226810,
1.193100, -0.857420, 0.071390, 2.590090, -0.567220, -0.190180, -0.432660, 0.854430, -1.435200, -1.577520,
-0.502460, 0.149540, 0.143120, 0.863310, 1.354400, 0.608270, 0.626680, 0.444140, -0.830380, 0.289180,
-1.253610, -1.006260, 0.018420, -2.496170, 1.293820, -0.839790, 4.799340, 1.580820, -0.445790, -1.223340,
0.485970, -1.098250, 0.522440, -1.678670, 1.307680, -0.824570, 0.041350, 1.145370, -0.316130, 0.390530,

0.865580, 0.466060, 0.571170, 0.027210, 0.862400, -0.476940, 0.434680, 0.286390, 0.745560, -1.772370,
0.878750, 0.580480, 0.134980, -0.686150, -0.964420, 0.401110, 0.783900, -0.942600, 0.102960, -0.750230,
-0.768610, -0.552780, -0.270730, -0.619780, 0.246740, -0.665530, -0.131850, -0.606520, 0.860160, 0.412510,
-0.619260, 0.237890, 0.953340, 0.282520, 0.486040, -0.151400, -0.726550, 0.799760, 0.638140, 0.862550,
0.947000, 0.629430, -0.300060, -0.606140, -0.620280, -0.822180, 0.652160, -0.338580, 0.915250, -0.757220,
0.617150, 0.862960, 0.724940, 0.039290, -0.409010, -0.219630, -0.156420, -0.387780, -0.714210, 0.185090,

-0.700070, -0.133340, 0.467820, 0.402310, 0.678790, 0.768760, 0.117520, -0.771600, -0.186010, 0.677810,
-0.039470, 0.082210, 0.150950, -0.811710, 0.005260, 0.881410, -0.207120, 0.352110, 0.249010, -0.033070,
0.818160, 0.710240, -0.069640, -0.488190, 0.583360, -0.499050, -0.080970, -0.633250, -0.922070, -0.745250,
-0.288500, -0.862990, 0.684390, -0.747240, 0.076100, -0.428520, -0.249220, -0.072300, 1.003810, -0.028140,
0.360910, -0.716180, 0.843560, -0.857920, 0.802090, -0.649460, -0.502660, 0.426800, 0.167600, 0.035880,
-0.604810, -0.913250, -0.285950, -0.686110, 0.141230, 0.669290, -0.157320, -0.286540, -0.687130, 0.545220,

0.490660, -0.505270, -0.874470, 0.677680, 0.319450, 0.490120, -0.236940, 0.700610, 0.887300, -0.456800,
1.240740, -0.547790, -0.348390, 0.133400, -0.831480, -0.838790, 0.039190, 0.806730, 1.386140, 0.652700,
-0.544020, -0.156020, 0.259550, -0.703950, 0.648110, 0.967690, 0.705950, 0.682220, -0.799620, 0.851850,
0.889580, 0.715150, -0.389580, 0.210340, 0.425710, 0.611540, -0.952610, 0.710060, 0.026560, -0.043560,
-0.175300, -0.624250, -0.966590, 0.617250, 0.745090, -0.865950, 0.251240, -0.409700, -0.094900, 0.244320,
0.048190, -0.856750, -0.124900, 0.464040, -0.530550, -0.369790, -0.044180, -0.766670, 0.551520, -0.191420,

0.254010, 1.019220, 0.405190, -0.711070, -0.351670, 0.553560, 0.357920, -0.723470, -0.763810, 1.275700,
0.711170, 0.681760, -0.819400, -0.266620, -0.922070, -0.176230, 0.498450, 0.388440, 0.536310, 0.685310,
-0.454720, 0.157170, 0.957070, -0.340620, 0.605760, -0.552300, -0.016050, -0.006020, -0.540980, 0.997920,
0.493700, 0.668480, 0.554920, 0.218020, 0.915120, 0.576800, 0.039710, 1.011120, 0.079590, -0.116920,
-0.778490, -0.834740, 0.325660, -0.339900, -0.079190, -0.844910, -0.439960, 0.334790, -0.802610, -0.638710,
0.930100, -0.305130, 0.708510, 0.165160, 0.876640, 0.528460, -0.673280, -0.145110, -0.335400, -0.881470,

0.010780, -0.952020, -0.267420, -0.281090, 0.866310, 0.447170, -0.150960, -0.525250, 0.576590, 0.234980,
0.492450, -0.188720, 0.293870, 0.634270, 0.280230, 0.793610, 0.241740, -1.176450, -0.571790, 0.626580,
-0.495320, 0.610460, -0.731850, 0.224380, 0.582500, 0.271630, 0.515900, -0.020300, -0.602300, 0.456700,
0.018740, 0.322640, -0.012430, 0.691900, -0.482990, -0.039550, 0.604400, 0.032330, -0.189820, 0.663620,
-0.524260, -0.521130, 0.545150, 0.225130, -0.751180, -0.118150, 0.469350, -0.606780, -0.774670, -0.804580,
0.740750, 0.644510, 0.621940, -0.665470, 0.434810, -0.884310, 0.494620, -0.239430, 0.364080, 0.201000,

-0.719420, -0.195050, -0.535390, -0.899000, -0.212480, 0.543760, 0.039250, 0.951250, -0.015610, 0.847180,
1.592260, 0.303520, -0.404920, -0.400980, 0.885220, 1.359400, 0.237730, 0.268100, -0.842080, -0.169940,
0.228050, 0.554040, -0.344450, -0.148040, -0.786250, -0.207420, 0.903330, 0.520930, -0.365690, 0.627730,
0.833790, -0.602920, 0.102100, -0.716360, 0.396690, 0.282860, 0.634350, 0.358690, 0.762350, 0.824340,
0.179970, 0.033130, 0.534510, 0.607260, -0.502600, 0.242080, -0.201130, -0.514030, -0.513050, 0.494560,
-0.180510, -0.717660, 0.812320, -0.678400, -0.152420, -0.070950, -0.791240, -0.282990, 0.422440, 0.523540,

0.538940, 0.576630, 0.472370, 0.336150, 0.217620, -0.779810, 0.554260, 0.203300, 0.462140, -0.225060,
-0.648190, -0.136400, 0.342440, 0.075830, -0.831480, 0.268070, -0.431780, -0.897720, -0.963280, -0.907430,
-0.220990, 0.387590, 0.822750, 0.401630, 0.419680, 0.295100, 0.080080, -0.408400, -0.841020, 0.116900,
-0.934580, -0.609230, -0.639020, 0.697100, 0.278650, 0.799470, -0.093800, 0.182550, -0.081400, -0.921210,
0.395260, 0.776540, 0.238020, 0.948530, -0.405500, 0.608620, 0.924240, 0.113730, -0.913640, 0.084310,
0.639300, 0.105110, 0.220670, 0.580260, -0.663020, 0.494670, 0.621240, 0.646810, -0.323490, -0.420180,

-0.141660, -0.598010, 0.613250, -0.254130, 0.283490, 1.010010, -0.474500, -0.471700, -0.136430, 1.055660,
0.178440, 0.580580, 1.536930, -0.376820, -0.329300, 0.983890, 0.768740, 1.250200, -0.409810, -0.039030,
0.551020, 0.961030, -0.188350, -0.681640, 0.740090, -0.181170, -0.382690, -0.143890, -0.136040, -0.719720,
-0.908250, -0.062920, 0.205330, -0.656840, -0.019640, 0.356580, 0.522880, 0.097080, -0.575680, -0.331640,
1.021070, 0.235790, -0.051320, 0.426430, -0.847520, -0.560820, -0.546320, 0.230110, 0.736080, 0.017360,
-0.851780, -0.276710, 0.220640, -0.629430, 0.006160, -0.078180, 0.907650, 0.075140, -2.330680, 0.175170,

-0.527130, 0.392460, -0.693150, -0.000110, -0.653850, -0.329530, -0.730280, -0.595500, -0.286320, 0.597250,
-0.455230, -0.501530, 0.169930, 0.501790, 0.318030, -0.518870, 0.183980, 0.197160, 0.262870, -0.127340,
0.651340, -0.548340, -0.833570, 0.939910, -1.158380, -0.199400, -0.852040, 0.031810, 0.910700, 0.584150,
-0.113150, 0.670550, -0.212220, 0.858440, 0.374150, 0.511390, -0.018620, 0.932600, 0.217790, 0.260710,
-0.473770, -0.307230, 0.042790, 0.488200, -0.610640, 0.392310, 0.320860, 0.725140, 0.144980, -0.155790,
0.514210, 0.704780, -0.991440, 0.219960, 0.485170, -0.712370, 0.094890, 0.133450, -0.811090, -0.533110,

0.698890, 0.081040, 0.720410, -0.522470, -0.268490, -0.442660, -0.269350, -0.724560, 0.666990, 1.448650,
-0.378030, 0.590980, 1.070780, -0.288410, -0.421250, 0.624210, 0.201180, -0.185150, -0.396430, 0.675760,
0.496800, 0.432550, -0.315840, -0.389120, 0.952380, 0.904980, -0.289280, 0.922110, -0.741130, -0.985890,
-0.699730, 0.579750, -0.568500, 0.917030, 0.700800, -0.451590, 0.619060, -0.958190, 0.349490, 0.176440,
0.004930, -0.579360, -0.655070, -0.481320, -0.321330, 0.496020, 0.325270, -0.414200, -0.016110, 0.237820,
0.475600, -0.817820, -0.339430, -0.386090, 0.534770, 0.289620, 0.571150, 0.594910, -0.210030, 0.035260,

0.463750, -0.851840, 0.969420, -0.336530, 0.085960, -0.325580, -0.372750, 0.273500, -0.440200, 0.829250,
-0.319750, -0.613930, 0.070310, 0.355320, -0.546250, -0.381570, -0.622190, 0.142490, -0.146030, -0.034840,
0.840480, 0.436900, 0.288370, -0.505640, 0.093890, 0.782750, 0.480100, 0.468180, -0.406420, 0.472260,
0.958070, -0.603280, -0.550680, -0.994220, -0.608880, -0.016420, 0.332760, -0.907090, -0.287310, -0.808700,
1.011600, 0.879350, -0.817680, -0.498210, -0.295700, 0.973270, -0.137400, 0.836400, -0.688560, 0.003410,
-0.661930, 0.609200, -0.769820, 0.723990, -0.812770, -0.028060, 0.995240, 0.956610, 0.183490, 0.102550,

-0.860270, 0.304220, 0.358540, 0.723380, -0.510110, -0.784170, 0.252800, -0.166330, 0.924030, -4.289110,
0.036430, 0.732500, -0.029880, 0.658390, 0.885770, 0.895920, -0.289350, -0.414800, -0.943850, 0.755140,
-0.418810, -0.438710, -0.234360, -0.170020, -0.317000, 0.019140, 0.244310, -0.914680, -0.202070, 0.007730,
0.338870, 0.825990, 0.418360, -0.446710, -0.954220, -0.171050, -0.200710, 0.605380, 0.328060, 1.176670,
-0.900210, -0.674970, -0.806790, -0.160640, 0.460320, -0.701790, 0.862390, -0.110620, -0.418090, 0.014450,
0.057880, 0.546160, -0.817290, -0.518240, 0.636520, -0.627050, 0.241180, -0.611620, -0.616630, -0.724790,

0.073640, -0.446590, 0.259120, 0.786600, 0.006600, 0.665170, 0.618890, 0.990090, -0.653580, 0.048340,
-0.660750, 0.288080, 0.098370, 0.974000, -0.707900, 0.981400, 0.922960, 0.877370, -0.603980, -1.821950,
-0.133740, 0.431010, 0.799310, -0.728710, -0.729250, 0.283030, 0.362830, 0.430540, -0.596950, -0.105020,
-0.149640, -0.880580, 0.067890, -0.636040, 0.966110, 0.739510, -0.121210, 0.964170, -0.068480, -0.702190,
-0.821790, 0.640330, 0.385310, 0.944890, -0.634880, 0.824880, -0.009890, 0.731680, -0.748710, -0.243780,
0.601580, -0.844140, 0.094750, -0.011400, 0.027290, -0.684320, 0.960960, -0.948480, 0.011210, 0.912360,

0.769980, -0.896850, -0.944580, -0.228250, -0.490290, -0.279010, 0.854680, 0.244310, -0.492010, -0.990430,
-0.227730, 0.883800, 0.293730, -0.075470, -0.339610, 0.949520, 0.946000, -0.238050, 0.756970, 0.334470,
0.571760, 0.528840, -0.410020, 0.163830, -0.457420, -0.227950, -0.335060, -1.076340, -0.754110, 0.770270,
-0.436770, 0.106790, -0.666480, -0.836730, 0.412190, 0.840070, 0.158640, 0.674200, -0.814080, 0.643530,
0.870410, 0.645650, -0.403590, -0.166540, -0.364910, -0.350810, 0.101330, -0.261070, -0.369520, -0.587160,
0.376330, 0.751640, 1.235500, 0.909330, 0.638370, 0.640220, 0.248070, -0.087930, 0.207980, -0.581230,

-1.524740, -1.055070, 0.293940, -0.542730, -0.254860, -0.560690, 0.265340, -0.339610, 1.106230, -0.006390,
0.221530, 2.123720, -0.742220, 3.232200, 1.459390, 5.145870, 2.227950, 0.294520, 1.579470, 2.551030,
-0.088230, 0.548780, -0.403470, -1.218990, 0.428030, 0.126790, -4.626190, -0.892850, -4.336560, -0.387130,
-0.346120, 0.324600, -0.795260, -1.483420, 0.052840, -0.997350, -0.773450, 0.480610, -1.693480, 0.509120,
-0.391610, -0.616900, -0.256860, -1.253450, 0.164390, -0.528490, 0.268250, 1.276490, 0.528910, -0.300000,
-1.121050, -0.571520, -8.331890, 3.000450, 2.111440, -0.874960, -1.171120, -0.386060, -0.743210, -0.291420,

-0.035860, 0.094520, -0.718340, -0.787770, 0.982080, -0.342110, -0.744850, -0.659280, -0.539910, -0.034520,
-0.075290, -0.416090, 0.803390, -0.091820, 0.071900, -0.404560, 0.254210, 0.652250, 0.189570, 0.698040,
-0.423400, -0.621900, -0.927560, -0.210580, 0.465560, 0.473600, -0.229390, -0.832380, 0.590380, -0.749050,
0.468660, -0.831890, -0.766450, 0.629800, 0.639990, -0.848390, 0.147430, -0.691440, 0.057010, 0.122800,
0.779470, 0.051570, -0.569560, 0.899340, 0.670520, -0.397790, -0.513050, -0.304300, -0.292830, -0.343020,
0.972900, 0.364260, -0.141650, 0.097040, -0.246160, -0.647770, -0.225850, 0.350800, 0.463160, 0.207640,

0.877670, -0.025990, -0.485310, -0.029010, -0.676520, -0.881610, 0.054760, -0.703340, 0.251790, 2.569520,
0.500360, -0.431310, 1.110780, 0.717670, -0.967610, 0.476190, -0.477230, -0.377830, -0.206120, -0.595810,
-0.229550, 0.492670, -0.253980, 0.683690, 0.903970, 0.071950, -0.777180, 0.011510, -0.896560, -0.217690,
0.674080, 0.167670, -0.103070, -0.889270, -0.521270, -0.485400, -0.642440, -0.300520, 0.154690, -0.564070,
0.581170, 0.205360, -0.766330, 0.565570, -0.826280, -0.764210, 1.785700, -0.535050, -0.181630, 0.861660,
-0.782090, -0.057260, -0.668930, -0.151860, 0.671570, -0.789930, -0.929760, -0.065550, 0.932160, 0.667180,

2.216000, -0.504020, 0.090820, -0.018770, -0.499410, 0.878980, -0.069980, 0.918790, -0.930170, -0.468120,
-0.437800, 0.214110, -0.371240, -0.895340, 0.069720, -0.169520, 0.926750, -0.490230, 0.693730, 0.003240,
-0.162030, 0.956280, 0.399580, 0.275770, -0.400820, -0.935640, -0.378670, 0.434260, -0.029690, -0.326550,
-0.122920, 0.834530, -0.338810, 0.128220, 0.041140, 0.915370, -0.178480, -0.757900, 0.066020, -0.564240,
0.645850, -0.468500, -0.442500, -0.219670, -0.463750, 0.922450, 1.023490, 0.930850, -0.909650, -0.681950,
-0.074410, 0.958580, 0.738110, 1.011290, -0.739970, 0.942840, 0.702580, 0.677200, -0.203520, -0.204370,

0.068270, -0.911530, 0.123180, -0.258030, 0.049070, -0.034120, 0.087600, 0.729820, -0.551340, -0.785260,
0.097080, -0.835910, -0.609050, -0.774460, 0.887420, -0.080800, 0.657140, 0.014100, -0.139130, 0.484540,
0.191610, 0.587600, 0.663900, -0.286820, -0.286170, 0.754280, 0.236160, -0.593960, 0.480680, -0.587310,
0.424560, -0.220040, -0.890630, -0.260340, -0.018390, -0.302280, 0.394550, 0.466430, 0.909460, -0.495800,
-0.182860, 0.937320, -0.308170, -0.445070, 0.551340, 0.683830, 0.233880, -0.765100, -1.450400, 0.703240,
0.989600, 0.600050, 0.884940, -0.012060, 0.020970, 0.344520, -0.881650, -0.104560, -0.745640, -0.580040,

-0.697600, -0.405120, 0.235340, -0.901070, 0.533500, 0.967590, -1.658020, -0.706960, -0.189870, -0.759360,
-0.769150, 0.788640, 0.745570, 0.841830, -0.909900, 0.874430, 0.144740, 0.172440, 0.304700, -0.488840,
-0.598610, -1.174540, 0.659650, 0.030000, -0.650220, 0.730340, -0.779440, 0.404140, 0.295860, -0.158860,
-0.152440, 0.415270, 0.748310, 0.693170, -0.003300, 0.797170, -0.939730, -0.007240, -0.822280, 0.570570,
-0.753300, -0.292220, -0.892330, -0.993780, -0.921130, 0.483950, -1.753790, 0.180290, -3.287940, 0.746040,
-0.661280, -1.015040, 0.699500, 0.498200, 0.602190, -0.912530, 0.002220, 0.425410, -0.187720, -0.991100,

0.673740, 0.651080, -0.591280, -0.261530, -2.748160, 0.256970, 0.873600, 0.357810, -0.307190, -0.648200,
0.882480, -4.748890, 0.455910, 0.301260, -0.733670, -0.593900, -0.145970, -0.333830, -3.768490, -3.731390,
0.230780, -0.774640, 0.468690, 0.118080, -2.482520, 0.500720, -0.967430, 0.483390, 0.641210, -1.009160,
0.312220, 0.127850, -0.462890, -0.143080, -0.861550, -0.025800, -0.742270, -0.675710, -0.798230, 0.074310,
-0.749600, 0.082310, 0.658020, 1.079440, -0.047470, -0.411040, -1.791330, -0.898980, 0.939580, -0.682250,
-0.596890, -0.741270, 0.628840, 0.823710, 0.865160, -0.579760, -0.445270, 0.100940, 0.036860, 0.888220,

-0.014490, 0.924470, -0.137490, -0.219530, -0.899470, 0.145940, 0.018230, 0.214950, -0.537040, 0.288990,
0.512350, -0.257390, 0.136080, -0.175520, -0.021140, -0.272920, 0.538010, 0.102830, -0.997410, -0.018930,
-0.489050, -0.327240, -0.759730, -0.527770, 0.268360, 0.733760, 0.195550, -0.724780, 0.467000, -0.159060,
-0.719660, 0.019550, 0.669620, 0.136200, -0.390180, -0.897050, -0.319220, -0.349920, 0.215500, -0.633950,
-0.299630, -0.149840, 0.806150, -0.512170, -0.630870, 0.825400, 0.010160, 0.111300, -0.423250, 0.866540,
-0.571340, 0.797480, 0.357310, 0.922950, -0.737150, -0.606450, 0.865050, 0.956030, 0.942530, -0.425450,

0.548620, 0.831140, -0.176870, -0.116240, -0.518870, -0.274660, -0.220530, 0.195290, -0.006130, -0.584250,
-0.257370, 0.124530, 0.888510, 0.387510, -0.710680, 0.806690, 0.801760, 0.700990, -0.461640, -0.240190,
-0.609630, -0.763270, 0.276110, 0.718670, -0.187850, -0.507580, 0.096730, 0.758170, 0.547160, -0.741050,
-0.678330, -0.156440, 0.335560, 0.797770, -0.317310, -0.961400, 0.171140, 0.537570, -0.128020, -0.489220,
-0.913290, 0.705290, 0.616140, 0.838940, 0.467190, -0.380800, 0.547950, -0.220730, 0.810670, -0.461640,
-0.677310, 0.675670, -0.004180, 0.006730, 0.365270, -0.640260, 0.606090, -0.634900, 0.308560, 0.447310,

0.173840, 0.641660, 0.858240, -0.355890, -0.324970, -0.818500, 0.031730, 0.591000, -0.555840, 0.816720,
0.492070, 0.110900, 0.306380, 0.270520, 0.435840, 0.526540, -0.050940, -0.244190, -0.523190, 0.206400,
-0.958760, -0.766600, -0.682880, 0.073860, -0.396560, 0.469550, 0.051230, -0.054370, -0.633940, 0.497980,
-0.603330, 0.645310, 0.398710, -0.508030, 0.861680, 0.000570, -0.787160, -0.134670, 0.163840, 0.066740,
0.350380, -0.297200, -0.487060, 0.314170, -0.928100, -0.453500, 0.370330, 0.235980, -0.992400, -0.088630,
-0.358250, 0.425910, -0.368400, -0.538320, -0.070780, -0.773170, -0.841030, -0.244040, -0.012550, 0.440530,

-0.569850, 0.707360, -0.942500, -0.062220, 1.020300, -0.836810, -0.295070, -2.557350, 0.959200, 0.835350,
-0.084470, -0.674230, -7.491170, -1.029050, 0.218610, 0.428740, -0.283910, -0.982080, 0.036260, -0.482720,
-0.342330, -0.817840, -0.604900, 1.329860, -0.699260, -0.712870, -0.679810, -0.458450, 0.909620, 1.141130,
-0.508740, -0.192100, -0.376520, -0.684590, -0.320100, -0.458620, -0.648600, -0.270070, -0.212550, -0.663660,
0.466560, 0.892630, -0.100390, 0.077510, 0.510400, -0.618580, -1.262840, -0.745830, -0.806980, 0.745160,
-0.268620, 0.900770, -0.874240, 0.724780, 0.011660, -0.462250, -6.640000, 0.290940, 0.854220, -0.734020,

0.946050, 0.727490, 0.399980, 0.655430, 0.794420, 1.472440, 0.554450, -0.406140, 0.235270, -1.541570,
-0.037850, 0.456670, 0.467110, 0.446520, 0.366400, -0.772350, -0.365880, -0.146590, -0.013160, -0.687490,
0.969380, 0.896330, 0.940200, 0.085120, -0.662050, 0.008610, -0.766260, -0.174560, 0.899160, 0.295430,
-0.051610, 0.179130, 0.758440, 0.507270, 0.138000, -0.713320, 0.170800, 0.816810, 0.278410, 0.146630,
0.400320, -0.770890, -0.400310, -0.374040, 0.782930, 0.355260, -0.809270, -0.824120, 4.224710, -0.968690,
0.569680, -0.900750, -0.425020, 0.849040, -0.174300, 0.404950, 0.572550, -0.410710, 0.755290, -0.775230,

-0.796500, 0.513830, -0.772270, -0.823090, 0.544520, -0.610230, -0.017010, 0.022240, -0.044730, 0.593560,
-0.766800, -0.470650, -0.280430, -0.706090, -0.337930, 0.829030, 0.233040, 0.046520, -1.171020, -0.442670,
-0.051620, -0.368770, 0.391910, -0.648010, 0.374730, 0.419600, 0.333310, -0.337980, -0.312600, 0.343230,
-0.385280, 0.497880, 0.504260, 0.014020, 0.909090, -0.870080, -0.840720, -0.877870, 0.115080, 0.496020,
-0.314650, 0.917960, 0.177610, -0.969150, -0.349590, 0.781330, -0.136860, -0.363310, 0.584300, -0.417670,
0.028190, 0.257220, -0.989000, -0.348030, 0.139570, 0.200260, 0.449260, -0.879760, -0.112660, -0.463730,

0.254150, 1.646490, -0.610820, 0.519050, 0.397910, 0.992780, 0.815330, -0.317500, 0.161990, -0.143600,
0.548770, -0.612280, -0.818720, 1.007350, 0.428340, 0.035390, -0.407460, 0.581890, -0.112430, -0.354520,
-0.107600, -0.695730, 0.645950, -0.939110, -0.911250, -0.833230, 0.866860, -0.476680, 0.423670, -0.976340,
0.192940, 0.157070, 0.581790, 0.495450, 0.835690, 0.409900, -0.694040, -0.763420, 0.213140, 0.819550,
-0.519400, -0.173400, -0.190070, -0.856260, 0.134960, -0.280190, 0.213660, -0.170110, -0.233200, -0.035800,
-0.118200, 0.583330, 0.545800, 1.808020, 0.552350, -0.384270, 3.034950, 0.504330, -0.945590, 0.643340,

0.285620, 0.169770, -0.939760, -0.706440, 0.314930, -0.824560, -0.617670, 0.516700, -0.220750, 0.869060,
-0.795770, -0.922590, -0.469600, 0.269460, -0.309410, -0.401940, 0.287290, -0.414600, 0.790430, -0.079020,
-0.762900, -0.041470, 0.459230, -0.942140, 0.435220, 0.790840, 0.675760, 0.938030, 0.482470, 0.906530,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.760880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.940250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.320280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.168630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.336670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.272190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.593250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.534120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.403590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.042610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.412490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.558860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.429840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.087390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.066620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.175290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.014680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.446850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.375550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.136080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.085760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.714960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.705590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.920380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.190380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.842260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.658750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.391880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.863160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.888340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.931720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.133090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.037460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.959460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.650450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.047870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.702450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.491360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.529080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.198160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.196400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.393010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.628930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.230310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.075760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.009970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.753380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.045480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.163740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.685760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.353640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.263100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.143480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.804540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.729010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.943860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.904410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.080430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.942620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.670850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.120090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.773110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.261240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.751520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.251070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.034650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.657910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.064320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.713240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.283530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.741620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.870150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.646620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.014270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.837330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.394700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.649070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.346880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.321080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.554740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.919500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.781120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.652430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.820820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.595880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.176940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.661510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.730850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.892830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.041140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.026380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.790440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.140250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.883350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.159210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.763780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.889450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.286550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.908910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.254450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.139310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.105360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.016630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.431960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.523100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.386320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.190770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.795600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.482230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.181520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.967150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, -0.201180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.748480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.567430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.576450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.951970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.233680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, 0.371240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.956950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.163130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.108930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.629120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.239730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.527190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, 0.279130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, -0.491070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.722040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.845380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.990530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.447810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.481090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.786650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.512650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.075530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.866920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.492600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.242820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.123840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.954730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.515900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.731740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.710380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, 0.162160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.422480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.981210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.727590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.426790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.354700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, -0.673100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.308850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.598280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.840880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.900330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, 0.427160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, -0.245330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.955240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.159540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.122570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.229670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.801380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.862610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.648340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.649510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.453130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, 0.088520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.389030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.463600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.665350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.554250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.102390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.583270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.965980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.339640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.433810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.748770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, 0.680470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.092640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, -0.438680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.024960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.011560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.642960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.438810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, 0.162850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.102410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.618170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.598010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.655050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.518600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.205480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.591460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.764640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.208300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.621750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.760090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.027920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.479460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.766030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.871020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.938650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.686440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.212820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.473060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.216800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.820460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.884160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, -0.079770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.703450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.448890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.402150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, 0.448530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.984700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.475480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.160000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.933170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.957280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, 0.811690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.495910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.642990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.007860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.418430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.371300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.118980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.150960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.241000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, 0.755570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.756660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.254940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.984430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.909910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.557190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.888690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, -0.681410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, 0.119790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.865900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, 0.372500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.242470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, 0.179370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, 0.399860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, -0.424850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, 0.951290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.533650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.076290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.368190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.369180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, -0.683090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, 0.311740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.625230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, -0.487250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.994860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, -0.270870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.399900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.704690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, -0.392440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.803170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, -0.335740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, 0.734960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.770530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, -0.577830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.250330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, 0.994640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.469090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.962270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.763810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.500720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.127100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, -0.384920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, -0.771350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.954540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, 0.665580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, 0.488430, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, 0.322990, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.287930, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, -0.243470, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, 1.482760, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, 0.308260, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, 0.618200, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.911760, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.270880, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.957010, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.561200, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.706330, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.929860, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, -0.419940, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, -0.334010, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -1.982410, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.670730, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, -0.213160, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, 0.953540, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, 0.397200, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 1.297900, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.634990, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.472510, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -1.189130, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, -1.007600, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.464180, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.086760, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.522150, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.362860, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, -0.286520, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.413570, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, -0.292850, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.388430, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.053170, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, 0.875820, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, -0.701280, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.207890, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, -0.851230, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -0.813690, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.597000, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, 0.282080, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, 0.384280, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -0.306330, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.225000, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, 0.024250, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -0.165980, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, 0.080850, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.874340, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, -0.591790, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -0.287720, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, 0.871520, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 0.172570, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, -0.917760, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, -0.654440, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.368160, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.135090, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, 0.301790, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, -0.420840, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, -0.162290, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, 0.845270, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.747550, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
1.42784, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.12016, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.30848, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
0.42021, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
1.42610, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
1.42518, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
1.30325, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
1.04749, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
1.42639, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
0.00001, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.33587, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
0.01063, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
1.00166, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
1.12136, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
1.42822, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
0.02713, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.05047, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
0.32744, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
0.41455, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
1.00834, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
1.01878, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
1.42663, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
0.33351, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
0.11714, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.39260, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
1.00831, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
0.42405, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.00075, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.03022, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
0.10105, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
0.75272, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
1.28275, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
1.29962, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
1.04868, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
1.42122, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
1.14122, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
1.21974, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
1.32296, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
1.09834, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
0.58286, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.69205, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
1.30970, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.29326, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
0.28520, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
1.25192, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
0.63320, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
0.10202, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
1.03220, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
0.03918, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
0.78035, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
1.40234, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.01904, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
0.00000, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
0.02573, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.05173, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
0.06792, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
0.00006, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
1.42474, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
0.00676, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
1.41296, 0.500000, 2,
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
