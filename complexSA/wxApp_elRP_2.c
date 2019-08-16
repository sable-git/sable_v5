/*********************************************************
  Pfam_elRp_2_forceW7new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:07:22 2004
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
1.581650, -0.087520, -2.215720, -0.148520, -0.378570, -0.792270, -0.441760, 0.232990, -0.066180, -0.487690,
1.777830, 0.315320, 0.660330, 0.028030, -1.307760, 1.318370, 0.346100, 0.169270, 0.181990, 1.665960,
-3.592100, 0.966260, 1.031080, -1.412200, 0.947860, -0.902290, 1.449650, 0.683980, -0.771790, 0.344000,
-1.822510, -0.854220, 3.381610, 0.379110, 0.502790, 0.174010, -1.130480, 0.660150, -0.919050, 0.808950,
-1.257050, -0.066580, -0.064050, -3.618370, 0.825520, -0.792990, 0.276240, -0.142630, 0.201700, 0.746650,
0.038140, 0.843340, -0.845730, -0.469890, -0.281930, 1.037120, 1.355180, 0.766070, -0.945720, -0.033350,
0.482850, 0.705940, 0.612030, 0.011390, 0.160510, -0.566160, -0.110330, 2.021320, -0.187910, 0.788330,
-0.307080, 0.698990, 0.574690, -0.209860, 0.431540, -0.350920, 0.165010, -0.652530, -0.038980, 1.597250,
2.439670, 0.968680, 0.266330, 0.822810, -0.260310, 0.049460, 1.068020, 0.242000, -0.606720, -2.907740,
-0.737030, -2.524680, 1.281640, 1.205360, 1.033940, -0.319730, -0.149190, 0.352180, 0.486460, 0.848690,
0.056550, 0.013820, 0.367060, 3.555800, 0.369890, 0.316300, -0.207110, -0.373500, -0.091380, 1.223570,
0.296870, -0.593170, 0.148130, 0.079080, -0.623970, 4.454570, 1.528500, 0.409470, -6.253360, 3.564880,
2.069820, -1.182600, 3.884850, 1.751970, 0.586940, -1.540490, -1.373440, 0.254400, -0.466870, 2.334830,
0.874280, -0.854930, 0.359090, -1.890290, -2.631470, 1.101060, -1.259290, 0.055530, 0.590730, 0.810940,
-0.368140, -0.224230, 0.216930, 0.533150, -0.433880, 0.948970, -0.490350, -0.497290, -1.213390, 1.621490,
-0.210710, 1.475050, -0.553800, -0.486040, -2.517190, 0.132960, 0.419940, -1.488350, 0.991710, -0.453510,
-0.889430, 0.146920, -0.047990, -1.776330, -1.320820, 0.515870, 0.652820, -0.887860, -1.001750, -1.152090,
-0.326130, 0.188260, 0.233170, 1.348240, 0.557960, 1.228090, 1.430780, 0.541770, 1.206310, -0.842120,
-1.832240, -0.686910, -0.728000, -3.821220, -0.806030, 0.134000, 1.028300, -2.642640, -0.948880, 0.647050,
-0.813080, 0.413260, 0.940510, 1.640320, 0.049030, 2.141210, -0.562520, 0.395830, -0.573400, -0.658360,
-0.833960, 1.723440, -0.227060, -3.018720, 0.074980, 0.073400, -0.530060, -1.788830, -0.139240, 0.399100,
-0.487000, 1.227360, -0.332870, -1.222750, 1.634410, 1.082290, 2.285860, -0.297950, 0.570410, 0.582150,
0.087700, 0.760360, 0.540400, -0.324600, -0.350740, -2.066730, 2.490450, 4.600030, -0.021860, -0.317110,
-0.825130, 0.771680, 0.101460, -0.317990, -0.299230, -0.579740, 0.294270, -1.235360, 0.568160, 0.678840,
0.743000, 1.126600, -0.785980, -0.465380, -0.497930, 0.019140, 0.794960, 0.325300, -1.026200, 0.217910,
0.189310, 0.534590, -1.603930, 4.732470, 0.028500, 1.553140, 0.724820, 0.771490, 1.903580, -5.867480,
1.505170, 0.794490, -1.042670, -0.642640, -1.656790, -0.834940, -0.062450, 0.399370, 1.149110, 2.724450,
1.015910, 0.097470, 1.116850, 2.036840, 0.766740, 0.821950, 1.864810, 2.004700, 2.322750, 1.605910,
1.648030, 2.365810, 1.280220, -3.070000, -0.403710, 0.038580, 1.095450, 1.872960, 2.022160, 1.735730,
0.128180, 1.779310, 1.021480, 2.695820, 1.283850, 1.630720, 0.860750, 2.513640, 3.289320,
0.082890, -0.540390, 0.923200, -1.451570, 0.645660, -0.293750, 0.258340, -1.936710, 0.945600, -0.145170,
0.638990, -0.338740, -0.564240, -1.206900, 0.236490, -0.950490, -0.463620, -0.597410, 0.450000, -0.153720,
0.034280, -0.097950, -0.787960, -0.388460, 0.774810, 1.054220, -0.488590, 1.527300, -0.289000, 1.135250,
0.175590, 1.425670, 3.239020, 0.443270, -0.321160, -0.800050, -3.020040, 1.199330, 2.014210, -0.335470,
2.218770, 0.653930, -0.478800, 0.151670, -1.280900, -0.830000, 1.290640, -1.613630, 0.646020, 1.597390,
1.341110, -1.118800, -0.234210, -1.253760, 0.441700, 0.049190, -1.340470, 1.101010, 2.828690, -1.827390,
-1.166870, -0.334100, -1.031590, 0.831110, -0.495970, 2.986910, 0.798140, -1.048470, -1.083140, 0.842820,
-0.243070, 1.414260, -0.601550, 1.946060, -0.008190, 0.581720, 0.240090, 0.623570, 0.152690, 0.883820,
-0.122070, 1.032600, -0.502290, -0.810510, -0.699200, -0.333640, 4.269590, 3.284720, 0.362980, 1.437460,
0.271680, -0.420650, -0.273270, 0.470500, -0.744020, 1.520380, -0.933060, -0.264990, -0.996460, -1.421200,
-0.035240, -0.765020, -0.576330, 1.199630, -1.157310, 0.398820, -2.205460, -1.632300, -1.096020, -1.057920,
0.600450, 1.613420, -0.752820, 0.518480, -0.961420, 1.880230, 1.472300, -0.663010, -0.823880, -2.456090,
1.326470, -1.292660, -0.277790, 4.949770, 3.916400, -1.827280, -0.891320, 0.240700, 6.393220, -8.482260,
-0.662650, -1.686020, 20.448589, -0.894640, -0.587300, 8.647110, 7.442400, -0.361510, 0.959810, -3.902740,
2.102380, 0.462200, -1.187110, 1.279220, -0.914220, 0.228090, 1.837790, 2.889570, -1.119350, -0.112520,
-0.876430, 3.075500, -0.102800, -0.197470, 1.437590, 0.836540, 1.370630, 2.910780, 1.154410, 0.715570,
-2.500500, -0.897260, 0.638470, -0.504150, -0.159000, 0.434630, -1.292600, -1.629900, 0.003430, -0.243970,
-2.028200, -0.178250, 0.876160, 0.342580, -0.038580, -0.092480, 0.916810, 1.096480, 1.133610, 1.549380,
-0.470260, -1.468750, 0.567940, -0.154360, -0.665260, 1.642600, 0.240310, 1.273610, 1.147650, -1.727000,
0.086840, 2.686860, 0.124790, 1.814500, 2.135590, 2.863330, 0.028600, -0.398230, 0.352380, -0.115640,
2.025670, 0.826850, 0.888040, 1.050120, 0.911760, 2.310070, 0.762840, -1.636160, 0.949620, 1.454440,
0.827860, 1.637400, 0.425150, 1.367970, 2.534310, 0.383280, 1.235940, 0.190700, -0.919620, 0.661440,
-0.563420, -0.663870, 1.771360, 0.703750, 2.136170, -0.675140, -1.044230, -0.593090, -0.658720, 2.333630,
2.195540, -0.192990, -0.444320, -0.926010, 0.677630, 0.062890, 1.926110, 0.186910, 0.016500, -0.869470,
1.658100, 0.952410, -0.144750, -0.552250, 0.414770, 1.264360, -0.197580, 2.163070, -0.298650, 0.747480,
-1.685260, -1.254090, -2.530560, 0.474060, -0.467860, 1.646840, -0.326950, 0.299300, 0.957510, 0.670950,
1.045420, -0.752380, 0.107680, -1.259690, 0.524700, -4.785900, 0.588180, 1.032480, 0.714380, 0.330790,
-0.096270, 0.001190, -0.617790, -0.473180, 0.422790, -0.596580, 0.035560, -0.028600, -0.348480, -0.074790,
-0.140400, 0.181750, 0.448230, 0.111700, -2.324650, -0.234290, -1.294550, 0.920580, -0.228980, 0.247920,
-0.345790, 0.173990, 0.339940, -0.961300, 0.755990, -0.307400, 0.478910, 0.436580, -0.273400,
0.075810, -0.387330, 0.659010, -0.314350, 0.787430, -1.851510, -1.342030, -0.660390, 1.222690, -0.448730,
-0.410570, 2.022120, -2.096910, 1.255610, 0.048840, 2.534370, 0.581450, -0.647520, -0.036840, -0.824200,
1.409240, 1.575730, 0.753990, -0.639340, 0.436240, -1.205770, -0.420610, -0.995880, -0.281360, -0.596260,
0.372070, 0.757170, -0.238090, -0.326610, 0.173320, 0.270510, 0.566970, 0.117220, 0.883310, -0.234230,
0.410760, 0.788740, 0.518660, 0.917970, -0.562360, -0.927470, 0.541130, -0.713410, -0.058080, 0.010630,
-0.742690, 0.192710, -0.400470, -0.032000, 0.795780, 0.789710, -0.228910, -1.273320, 0.158510, -0.960290,
0.165820, 0.385270, 0.932780, -1.024410, -0.554570, 1.120500, 0.664600, 0.310560, -0.815980, 0.268980,
-0.118840, 0.400430, 1.382490, 0.856240, -0.663460, -0.052430, 1.052350, -0.332000, 1.266270, 1.018460,
0.773810, 1.329330, 0.457270, 1.037900, -0.277260, 0.492880, 0.335730, -0.037600, -0.601610, 0.693710,
0.056130, 0.721790, 1.484040, -0.313630, -0.846270, 1.620800, -0.568260, -0.004080, -1.297920, 0.788430,
-0.894730, 0.867590, 0.189770, 0.693870, 0.331760, 0.236380, -0.101630, -0.002470, 1.273000, -2.104800,
0.609810, 0.147640, 1.551500, -0.045930, 0.070540, -0.786240, -1.752100, -1.167980, 0.236280, -0.704190,
-0.069330, 3.322520, 1.271320, -0.375560, -2.792690, 1.008010, 2.022710, 1.906550, -0.314620, -1.001010,
1.944520, 0.020690, -3.842640, 0.594640, 0.789430, -12.026020, -0.764950, -0.113440, -0.149900, -1.142650,
-1.240620, 0.997970, 0.789220, -1.290850, 0.302020, -1.233000, -0.483650, 0.373090, 1.622750, 0.435500,
0.167290, -0.276690, -0.947110, -0.247960, 0.716820, -0.677400, 0.701040, 0.196080, 1.307010, 0.621760,
0.204900, -0.157440, -2.454220, 0.975770, 2.182630, -0.381900, 0.437770, -0.364070, -2.362410, 0.965940,
0.018370, 0.392490, -0.456780, 1.179950, -0.012480, 0.101970, 1.419350, -0.448060, -0.604720, 0.455160,
-0.145370, 0.902540, -2.208690, 0.071960, -0.116320, -1.970470, 0.510740, 2.396160, 0.741140, 0.172960,
0.999910, 0.406730, -0.797050, -1.161810, -0.634330, -0.131960, 0.059810, -0.171280, -0.447460, -0.394840,
0.316420, 0.070610, -1.264460, 0.869230, 1.029930, 0.025090, 0.850260, 1.574830, -1.074120, 0.415310,
1.141390, -0.130150, -0.382990, -1.450540, -1.811700, -1.253180, -2.872360, 0.153520, 0.913980, 0.257660,
1.021350, 1.211450, -0.790360, 1.258650, -0.556690, 0.243990, 1.537910, 1.766610, -1.284380, 0.418000,
0.829980, -1.197170, -0.527110, 0.911610, -0.791090, 0.844890, -0.510250, 0.420670, 0.536600, 0.948640,
1.023650, -0.514790, 1.697760, 1.427710, -1.760410, -0.101010, -0.130310, -1.253950, -0.033130, 0.779940,
1.083140, -0.733800, 0.908060, 0.473780, 0.276370, 0.840800, -0.242650, 0.222790, -0.358800, -0.051350,
-0.477100, 0.149690, 1.310150, 1.403380, 0.015990, 0.431940, -0.394560, 0.147270, -0.739180, 0.988210,
0.261990, -0.501370, 0.400440, 2.123950, 0.655170, 0.610320, 0.581510, -0.142460, 0.810800, -0.287430,
0.486600, 0.899210, -0.621480, 0.057530, -0.445530, -0.411790, -0.217160, -0.774250, 0.044840, 0.439790,
0.555780, -0.258580, 3.452310, -0.784020, -0.538700, 0.299160, -1.657420, 0.738820, 0.367250,
0.312000, -1.100670, 1.486890, 0.907570, 0.029030, -0.857870, 1.520260, -0.023420, -0.416000, 0.649670,
-0.225490, -0.233900, 0.755580, 0.593950, 0.203300, 1.508000, 1.259020, -0.254880, 0.886790, 1.647400,
-0.240230, -0.618900, 1.881370, 1.720030, -0.332960, 0.148640, 1.869500, 0.016300, 0.015730, -0.510000,
0.256760, 2.185740, 0.390110, -0.775270, -1.184450, -0.548650, 2.751330, -0.129340, 0.125170, -1.282030,
2.368010, 0.347680, -0.776890, 1.088860, -2.567640, -0.109520, -0.265890, -0.720700, 0.920870, -0.246850,
0.015500, 0.774630, -0.094290, 0.277170, 0.098380, 0.959880, -3.588310, -1.955660, 0.953760, -0.385190,
-0.343650, 1.433740, -1.113340, 0.265000, -1.926870, 0.409830, -0.024710, -2.730570, -0.928940, 0.524570,
-1.761370, 0.785300, -0.199020, 0.248680, 0.004380, -0.403490, -1.117570, 0.358670, -0.838490, -0.508660,
0.632850, 0.135650, -0.267770, 0.877370, 0.147200, -0.251380, -0.464650, 1.088110, 0.843610, 0.428500,
0.779110, -0.923810, 0.311990, 0.349750, 0.074310, -2.831400, 0.273760, 0.058270, 1.830980, -0.565010,
0.229840, 0.184690, -1.059600, 0.436020, 0.068020, -0.849890, 0.777090, -1.418470, -1.947280, 0.493930,
-0.689040, -0.935250, 2.086820, 0.328500, 0.849630, -0.667440, -1.033980, 0.120030, -0.743700, 0.576270,
-1.105400, -1.287580, -0.572840, 1.648340, 0.204280, -0.902280, -0.027800, 1.853540, -1.862850, 1.367580,
2.044550, -1.714370, -1.283990, 0.817630, 0.233920, -1.839780, -0.782100, -0.493480, 1.038810, 1.143390,
0.862370, -1.086150, 1.069310, 0.445290, 0.054540, 0.252860, 0.442260, 0.799430, -1.109160, -0.792640,
-0.913220, 0.600720, 2.971990, 1.966180, -0.570430, 3.825620, -0.611230, -0.456200, 1.480970, -0.700750,
-1.856070, -0.768080, -0.742210, -0.170880, 0.741740, -0.675530, 0.102770, -0.174650, 0.666350, -1.703710,
-0.699330, -0.350970, 0.169590, 0.442150, -0.438890, 0.299950, 2.145410, -0.458890, -0.585080, -0.205490,
-0.017670, -0.897820, -0.155100, -1.437330, -1.311790, -0.951640, -0.223960, 0.971480, 0.398900, 0.150500,
-0.852940, -0.160590, 0.864290, -0.078760, -0.532130, -0.364250, -0.944750, 3.003930, 0.426060, -0.252410,
1.370180, 0.071210, 0.611640, 0.488710, 0.438220, 0.034560, -2.371010, 1.275730, 0.233430, -0.447860,
1.433550, -0.361650, -1.030600, -1.252560, -0.575150, 1.349040, 1.579390, 0.269650, 0.355350, 0.011140,
0.474320, 0.476800, -0.196380, 0.339590, -0.878330, -0.470220, 0.008420, -0.394910, -1.232770, -1.672780,
0.326900, -0.858300, -0.357730, 0.062080, 1.114090, -1.007110, 0.380560, -0.003380, -0.043260, -1.200430,
-0.205010, -0.781430, 0.267920, 1.214110, -0.872430, -0.502000, -0.680130, -0.365990, -0.518310, 0.390930,
-0.458510, -0.651630, 0.643160, -35.552879, 0.094640, -2.657230, -0.572270, -1.093720, -0.817870, -1.173590,
1.254640, -0.006240, 0.309460, 1.050690, -1.413540, 0.876870, 0.009640, -0.044040, -0.510340, 0.444480,
0.812250, -0.774360, -0.641200, 1.446890, -0.793200, -1.049550, 0.061580, 0.332130, 0.030020, 1.066740,
0.254010, 0.674880, 0.686580, -0.173970, 2.263110, -5.541140, -0.516980, 0.466820, -0.243250, 0.385170,
1.064140, -0.278960, 0.624460, 0.960820, -0.319930, 0.752650, -0.091480, 0.578880, 0.372290,
0.811980, -0.053560, 0.793580, 0.172620, 0.108640, -0.048090, -1.671780, 0.038410, -0.164090, 1.207410,
-0.961420, 0.097030, -0.091220, 1.296530, -0.589110, -0.283300, -0.987320, 0.084900, 0.217900, -0.380220,
-0.390210, -1.270870, -0.057870, 0.750850, -0.284620, 0.032610, 1.042610, -0.082090, -0.088470, 0.438910,
0.453460, -0.040270, -0.545790, -1.033430, 0.644920, -0.196650, -1.672260, -0.114590, 0.181920, -0.300290,
-0.126910, 0.495930, 0.650600, -0.669590, -0.326120, 0.700350, 0.678800, -0.179220, 0.395730, 2.068850,
-0.159400, -3.113280, 1.136860, -1.675620, 0.237600, -0.469710, -0.374350, -0.555830, 1.581110, 1.821090,
0.442990, 0.929980, 1.207480, -0.368910, 1.461530, 0.689790, -0.605750, -0.317550, -0.086180, -1.028910,
0.712420, 0.965350, 0.103220, 1.625580, -0.709950, 1.474500, 0.098730, -0.544980, 0.431300, 0.149370,
-1.714900, 0.483990, 0.255200, -0.254480, 0.338260, -0.870520, 1.172120, -0.743080, 1.718790, -0.134310,
0.319300, -0.114950, -2.388990, 0.015090, -3.547510, 1.424460, -2.679410, -6.307130, 0.589540, 0.254090,
-1.130530, -0.248190, 4.175540, -0.111110, 1.304380, -0.691670, -1.187640, 0.784520, 3.209750, -4.278360,
1.460140, 1.331280, 0.014570, 2.059830, 0.711530, -0.915640, -3.900690, -1.025580, 0.300100, -1.312590,
-0.298750, 1.523700, -0.562510, -1.986790, -7.784540, 0.216280, 0.009810, 0.773170, -2.010720, -0.053110,
-0.707250, 2.441400, -10.574400, 0.510610, 0.161390, -4.866850, -2.323050, 1.752450, -0.743610, 0.338920,
1.009050, -1.568700, 0.722770, 0.159230, 0.129700, -2.134490, -1.545480, -1.136220, 0.691120, 0.936230,
1.996140, 0.821550, -0.620330, 5.354570, -0.138750, -0.926010, 1.646360, 1.091070, -0.186510, 0.806470,
-1.575930, -0.223490, -1.435710, 0.403650, 1.048430, 1.077480, 0.143800, -1.541490, 1.569360, 0.726950,
1.956310, 0.378610, 0.113400, 0.862310, -0.157380, 0.699140, 0.723780, 1.887300, 0.567440, 0.300820,
-0.004260, -1.062640, 0.197700, -1.238770, -0.920070, 0.048370, 0.505760, 2.107570, -0.667920, -2.305670,
-0.087380, -1.051990, 0.082830, 0.478760, 0.011400, 1.260310, 1.286740, -0.072660, -0.710880, 2.383860,
0.017210, -2.104840, 2.500170, 4.109430, 0.601930, 2.228170, -0.863760, -0.151540, 0.001010, 0.331330,
1.934770, 0.834200, 0.390300, 0.461730, 0.190200, -0.213790, -0.375200, -0.649480, -0.369210, 0.334510,
-1.191030, -0.606000, 0.536180, 0.203710, -0.660040, 0.135640, 0.356270, -0.620190, -0.274660, -0.544830,
1.249700, 0.356310, -1.046110, 0.776170, 0.973730, -0.006820, 0.365880, -0.161610, 1.008660, 1.859450,
-0.585500, 0.903610, -0.690350, 0.472170, 0.202790, -1.651970, -0.731750, 0.439730, -0.478000, 0.289870,
0.970550, 0.358620, -0.848200, -1.152980, 0.700380, 0.638650, -1.315150, -0.011210, 0.886570, 0.183650,
0.503100, -0.823610, 1.340530, 0.663240, -0.105660, 0.396240, -0.162990, 0.506370, -0.585610, 0.753330,
-0.211650, 0.813420, 0.166610, 0.364740, -0.874220, -0.943240, -0.553260, -0.593890, 0.160820, 0.050640,
-0.362070, -1.150070, -0.666100, 0.926610, -0.307650, -3.547770, 0.607950, 0.397480, -0.594240, -0.659290,
-0.621000, -1.130830, 0.116660, -0.858490, 0.720690, -1.020860, -0.199430, -1.143190, -0.610000,
0.222170, 0.767540, -0.400010, 1.255910, -0.260660, -0.404680, -0.724870, 0.716780, -0.502240, -0.097520,
-1.449110, 1.415440, -0.366600, -1.101210, 1.097950, -0.117060, 0.374490, 1.156360, 0.390480, 1.104090,
-0.210980, -0.677710, -0.748170, -1.258110, -0.459740, 0.158620, 0.353060, -0.709630, 1.199190, 3.117580,
2.903020, 0.249870, -0.289760, 0.407950, -0.863760, -0.309820, -0.102980, 0.435380, 1.236430, 1.269210,
-0.972640, 2.510760, 0.219660, -1.674080, 0.784590, -0.409270, 0.234650, 1.188710, -0.512580, 0.066940,
0.827090, 0.430750, -0.326690, 0.337800, -0.136020, 1.109380, -1.296570, -0.264830, 0.500320, 0.587040,
-2.184740, -0.826960, 0.391050, -1.633020, 1.875320, -0.802820, -0.777780, -0.583660, 0.511810, 0.352640,
1.564290, -0.440320, -1.227990, 0.103430, 1.136700, 0.533480, 0.015470, -1.116170, 0.291370, 0.482840,
-0.655750, 2.441290, 0.572260, -0.089930, -0.955940, -1.949350, 1.173040, 0.811790, -0.650140, 0.078580,
-1.429600, 1.311540, 0.779840, 0.014400, -0.083370, -0.385410, -3.775430, 0.642110, 0.024200, 1.104620,
-1.333160, -1.613800, 1.193390, 0.009990, -0.129120, -0.591830, -1.065400, -1.155390, 0.285280, -1.547750,
1.360950, 1.577750, -0.960760, 0.111730, 0.853830, 0.547440, 0.607620, -0.689320, -3.249910, 0.271750,
-3.680050, -0.754770, -2.809210, -0.765810, -0.389660, 0.469960, 0.438620, -0.583140, 2.350640, 0.709590,
1.585450, -1.056150, -0.834910, -1.027770, 0.519360, -1.599990, 0.924100, -2.540040, -0.115020, 2.028610,
-0.550860, -0.604100, 1.160250, 2.349370, 0.606640, 0.502100, -0.831490, 0.287040, -0.897290, 0.714680,
0.663510, 2.167450, 1.050860, 1.553010, 0.225340, 1.712410, -1.585280, -0.838920, -1.073380, -0.041520,
0.077750, -0.096610, 0.567550, -0.817630, 0.515830, -0.644470, 0.465680, -0.462860, 3.246620, -0.686480,
-0.247670, -0.159280, -0.892790, 0.717420, 0.776680, -0.312580, -0.064750, -0.177610, -0.538890, -0.368990,
-0.590200, 0.215610, 0.058240, 0.010300, -0.096480, -0.534500, -0.799520, -0.098130, 0.317120, 0.424770,
0.574590, 1.076110, -2.316500, -3.593350, 0.011150, 0.198260, 1.401350, 1.244700, -1.786590, 0.903660,
0.304230, -0.098180, 0.837010, -0.306060, -0.807010, 1.130650, -0.693560, 0.430730, 1.050410, -0.039320,
-0.057500, -0.410540, 0.222070, 1.005020, 0.345390, -0.103160, 0.612740, 1.331220, -0.725500, -0.239230,
-0.448110, 0.708580, 1.382900, 0.682840, 0.110360, -0.218430, -0.516830, 0.475600, 0.228460, 0.160060,
-0.907410, -0.815760, 0.372080, -0.536020, -0.897820, 0.312630, 1.871460, -0.708560, 0.800720, -1.160780,
-0.046510, -0.183620, 0.618550, -0.122870, 0.363650, 0.843660, -0.154790, 1.009200, -0.229460, -0.527300,
0.830650, 1.437180, 0.755010, -16.001631, 0.071620, 0.434950, -0.435100, 0.670120, -0.990680, 5.158990,
1.705520, 1.043130, -0.634830, -0.522350, 0.180250, 3.741670, 1.930350, 1.222940, -1.477940, 0.910400,
0.244160, -0.797380, 0.571550, -0.094830, 0.740700, 0.152430, -0.429320, 0.592500, -0.035200, -1.744460,
-0.733960, -0.633170, -1.234090, 0.711450, -2.613150, -0.578090, -0.534260, -0.655000, -0.620380, 0.101490,
0.148120, -1.566640, -1.039450, -0.631060, -0.074190, -1.267690, -0.915860, 0.579440, -1.228440,
1.230980, 0.494220, -0.429530, -1.769780, 1.707310, -0.205830, 0.783960, -1.158310, -0.737190, 0.009620,
0.209400, 1.007080, -1.152120, 0.517200, -1.759170, 0.402400, 0.197490, -0.004830, -0.917330, -1.339640,
0.240900, -0.646620, 0.631440, -0.117900, 0.845510, -0.785830, 0.344460, -1.417420, 0.068360, -0.321220,
0.533340, -0.244500, -0.251100, 2.540260, 1.110260, 1.078530, -1.477960, -1.937760, -0.245100, -0.548910,
0.193410, -0.481510, 0.549790, -0.630730, -0.287880, -0.377550, 1.504150, 0.115630, 0.012020, -1.394100,
1.574640, -0.168160, 0.293730, 1.021900, -1.018570, 0.441950, -0.366590, -0.105840, -0.609150, 0.010050,
-0.720130, 0.140500, -0.545540, 0.670200, -0.357480, 0.646850, -1.391470, -0.190030, -0.123380, -0.311120,
-1.046900, 0.528680, -0.700760, -1.518650, -1.008620, 0.203560, -0.087160, -0.647650, -0.301870, -0.918620,
1.964990, 0.073310, 0.704210, -0.383570, -0.148750, -0.832370, 0.793490, -0.074830, 1.363510, -1.070670,
-0.234930, 0.269770, -0.605780, 2.136770, -0.803400, 0.186160, -0.410970, -0.388240, 1.176200, 1.327180,
0.169180, -0.017300, -0.583470, -1.231410, -0.036770, 0.208090, -0.548860, 0.670640, -1.138540, 2.317930,
0.429750, -1.248310, -0.378640, -0.812120, -0.957020, -1.153430, 1.593250, -2.546150, 2.952070, -3.882410,
-0.460560, 3.074660, -0.686570, -14.535060, -8.188830, 2.469280, 0.548680, 2.373840, -1.537830, -0.743500,
2.136490, 1.242320, -8.444730, 1.693460, 6.216050, -1.701510, 1.727380, 1.251950, -2.110500, 1.392690,
0.368330, 1.486070, -0.760710, -1.589650, -0.329370, 0.999090, 2.057140, 1.062020, -0.425060, 0.407100,
-0.270310, -0.089230, 0.738310, 0.047880, -1.483030, 0.586380, -0.329460, -0.127010, -0.257290, 2.430270,
-0.936730, 0.497670, -0.919060, -1.077320, 0.884240, -1.397830, 0.018760, 1.009550, -0.102030, 0.103630,
-0.430720, -0.184100, 0.365750, -0.095440, 1.356250, 0.062390, 0.012040, -0.103450, -0.634480, 0.850440,
-1.059870, -0.968510, -0.102710, 0.050650, 1.246930, -0.458990, -0.632250, 1.263650, -0.609660, 0.936110,
-1.084830, 0.413720, 1.286670, 0.133530, 0.890750, 1.966210, 1.132450, -0.085550, 0.270650, -1.278490,
-0.712200, 1.462010, 1.422640, -0.391960, -1.514770, 0.180190, -0.088260, 0.300030, 1.721640, 0.907950,
-3.882080, 0.895170, 0.428040, -1.017710, -0.072460, 1.092750, 2.181060, 0.262890, 1.356740, -0.815630,
1.509400, 2.091610, 0.412200, -1.276380, 0.596630, 1.455710, -0.291210, -1.612390, -1.000730, 0.037200,
-0.079590, 0.141590, -1.364100, -0.609970, 0.861810, -0.926510, -0.538060, -0.072810, -0.240790, -3.918510,
-0.437720, -0.296760, 0.270670, -0.282390, -0.597420, -1.304030, 0.928760, 0.522180, 0.021650, -0.368690,
0.598780, -1.104340, -0.510770, 0.334130, -0.721950, 0.568770, 0.874420, 0.661710, -0.726510, -0.712010,
1.679310, 2.631120, 1.388650, 1.149300, -0.345290, 1.925710, -0.329960, 1.800760, 0.000850, -0.120330,
-1.186930, -0.449750, 0.988340, -0.552870, 0.965960, -0.549090, 0.483340, -0.438150, -0.506030, 0.274230,
-0.264840, 0.534790, -0.605260, 3.285360, -0.027610, -5.203990, 0.977970, 1.288350, 0.040250, -0.003470,
0.486320, 0.080410, 0.501000, 0.791650, 0.081440, 0.749110, 0.310300, 0.096710, -1.826060,
-0.012870, -1.058180, -0.015320, 0.071000, 0.034310, -0.423280, 0.306230, -0.246040, -0.255300, 1.308970,
-0.084440, -0.710540, 0.447940, -1.672520, -1.550370, -1.777850, 1.126100, 0.459330, -0.422530, -0.444710,
-1.015300, 1.382820, -1.741320, -0.616160, 0.175760, 0.767950, -0.795860, 0.805540, -0.684190, 0.446850,
-0.730970, -0.080820, 1.234460, -0.463140, -0.288350, 0.201990, 1.123270, -0.179010, -0.121050, 0.656320,
0.438780, -0.152480, -0.781230, 0.618900, -1.216810, -0.829410, 0.105740, -0.502670, 1.429070, 1.444530,
-0.045750, 0.871990, 0.305820, 0.380990, 0.174700, 0.321950, -1.313800, 0.266060, -3.102910, -1.114180,
-0.838370, -0.674390, -1.248090, 0.122630, 1.258710, -0.441980, -0.068320, -0.348130, -1.523890, 0.843860,
-0.018510, -0.650950, 0.134190, 0.224720, 0.468590, -0.264190, 0.540470, -0.518210, 0.472540, -0.783820,
-1.927710, -0.080380, -1.362670, 1.185990, -0.179070, -0.459750, 2.086400, 0.393250, 0.583730, -2.232110,
-1.445670, -1.407360, 0.011750, -0.846350, 1.331650, -1.416870, 0.799240, 0.855400, 0.908430, -0.553530,
1.075710, -0.408360, -0.818000, 0.704520, -0.560520, -1.211850, 0.539690, -0.509800, -0.972570, 1.115070,
0.457050, 0.119740, -0.790660, -1.359160, -0.242370, 1.529480, 1.880760, -0.442000, -0.995860, 1.679670,
-1.246090, -1.279940, 0.646470, 1.811520, 3.478950, 0.835380, 1.835460, 0.196660, 0.335640, -0.086960,
0.194340, -1.381380, 7.437090, 0.727760, -3.486850, 3.256320, -1.535450, -0.330450, 0.880290, 0.593290,
0.024150, 0.704630, -1.211050, -0.115320, -0.143560, 0.123130, 2.055710, -0.030750, -0.439580, -0.473260,
-0.062270, 0.382690, -0.620750, -0.859150, -0.328110, 1.090740, 0.618340, 0.633140, -0.887290, 0.405640,
0.594140, -1.017690, 1.306110, 3.118680, -1.943870, -0.181280, 0.407580, -0.353690, -0.235950, 0.435100,
1.473310, 0.495450, -0.638420, 1.771850, -0.098260, 1.544980, 1.574220, 0.291930, 0.464840, 1.227120,
0.189590, -2.283090, -0.479060, -1.440880, -0.000120, 0.513310, 2.088050, 0.580650, -0.410240, 1.326090,
-0.357820, 0.052990, 1.527240, 1.665750, 1.367890, -0.463440, 0.523060, 0.152290, 0.216160, 1.287320,
-0.920230, 2.578210, -2.394450, 0.008650, 0.732110, 0.271290, 0.979180, 0.254410, 1.264770, 0.977210,
-1.601580, -0.015400, 1.182070, -1.308130, -0.840160, -0.264810, -0.427530, 2.423920, 1.495580, 0.745760,
0.019910, 0.195450, 0.114130, 0.022940, -0.845930, -1.962860, 0.163660, 1.451160, -0.972880, -0.485990,
0.855610, 1.577430, -0.448110, 0.338200, 1.231060, 1.184470, 1.108640, -0.194100, -0.263360, 0.707830,
0.354490, -0.766270, -0.690590, -1.298410, 0.061210, 0.090840, 0.381570, 1.887040, 1.650720, -0.193430,
-7.494170, -0.352010, 0.401910, 9.260260, 0.495390, 0.139500, 0.654650, -0.657180, 0.786320, -1.471320,
-0.757170, -1.403030, -1.059370, -0.892680, -0.738530, -1.095290, -0.358950, -0.175820, 2.055090, 1.156350,
0.651490, 0.491940, 0.822550, -0.410290, -0.003060, 1.086310, 0.915270, 0.989360, 1.356440, 0.729840,
0.918480, 0.980610, 1.437340, 0.349700, -3.248590, 0.050370, 0.206160, 0.107340, 0.196090, -0.125890,
-0.059390, 1.574310, -0.436430, 1.473640, 0.459320, 1.251670, 0.846690, 0.282280, 1.787120,
1.510320, 1.299460, -0.688880, 0.101340, -0.938710, 1.613500, 0.139660, 0.639250, 1.589170, -0.314890,
-0.924350, 0.036460, -0.719740, 1.881260, 0.675110, -0.238730, -0.942970, 0.536210, 0.002200, 0.734220,
1.210390, -0.334820, 0.556870, -0.802170, -0.993860, -0.330320, -0.354560, -1.603980, -0.566330, -0.560200,
-0.174030, -0.083350, -1.391680, 0.533990, -0.612950, -1.365270, -4.118480, 0.138390, 0.111290, -0.126370,
0.749120, 0.238190, 0.384340, 0.050850, 0.102550, -0.227240, -0.136960, 0.563930, -1.291010, 0.868720,
0.858920, -0.621800, 1.447670, -0.287650, 0.309430, 0.533090, 0.351900, -0.248440, 1.405920, 1.520770,
0.018920, 0.082740, -0.305870, -0.383220, 0.353220, -2.550780, 0.092980, -1.077580, 0.122010, -0.619320,
-1.170470, 0.055180, -0.581730, -0.409230, 0.131900, 0.235210, -0.009710, -0.189820, 1.141810, 0.037490,
-0.697200, 0.050630, 0.757990, -0.000810, 0.812550, -0.310090, 0.222630, -0.647420, -3.388090, -0.423610,
-0.092310, 0.859280, -1.358820, -1.254580, 0.464030, -1.766850, -1.875660, -2.939690, 1.766320, 1.096330,
0.018930, -0.176450, -0.117940, 1.060640, 0.819070, 0.185530, 0.098540, -0.088860, 1.031090, -4.169050,
1.136750, 1.176270, 0.147990, -1.050650, -1.162350, -0.879150, -1.089610, 1.282200, 0.192720, 0.964700,
0.688950, 0.336310, 0.270150, 0.395440, -0.790090, -0.579370, 0.165420, -3.616190, -1.434740, -0.972560,
-0.626180, 0.377700, -1.250160, 0.758310, -0.209520, -3.367680, -0.782010, 0.323000, -0.783160, 1.658210,
-0.256050, 0.506830, 0.900350, -0.687250, 0.419440, -1.165840, -0.767620, -1.528440, 0.569110, 0.716900,
0.371640, 0.106000, 0.447050, 0.356960, -0.832560, -0.978870, 0.653340, -0.423430, 1.142120, -0.486940,
0.226730, 0.681400, -3.118290, 1.023150, -0.046530, -0.173270, 0.858300, -0.626420, -1.670960, -0.130910,
0.401130, -0.962150, -1.357460, -0.609640, 0.822140, 1.356150, -1.507090, -1.350140, -0.597080, -1.572700,
2.267720, 0.421350, 0.147540, -0.531080, -0.490130, 0.315400, -0.560940, 0.097800, 2.311060, 0.119110,
1.124770, -0.895620, -1.197700, -2.524370, 0.519180, -0.428590, 0.336480, 1.930670, -1.642620, 0.337190,
0.116530, -3.147590, -1.450350, -0.242050, -0.862600, 0.578570, 0.130090, -6.165660, -1.085570, -1.234890,
-0.006390, -1.135850, -2.059350, 0.466840, -1.642040, -3.850350, -3.298590, 3.245500, 0.812440, 1.843000,
-0.860130, -1.198060, 2.115870, 0.518010, -1.091220, 0.784210, 0.272310, 0.196720, 1.155350, 1.383430,
0.116370, -1.560500, -1.016310, 0.620970, 0.433630, 0.015480, -0.325210, 0.559590, -0.251440, 0.700860,
0.259980, -0.217370, -1.790780, 1.036620, -0.594560, 1.387400, -0.880310, -0.587100, -0.533670, -0.828960,
0.773690, -1.043050, 0.515110, -8.893600, 0.338190, 0.577060, -2.729220, 0.946620, 1.076590, 1.260960,
-0.268420, 0.080670, -1.316780, -0.337030, 0.248130, 2.683700, 0.079820, 0.145400, 0.697460, 0.964650,
-0.022290, 0.270320, 0.145550, 0.425100, -0.670980, 0.339950, -0.282640, 0.309680, 0.185710, 0.214260,
0.908620, -0.140600, 2.020960, -0.798310, -0.314260, -3.727150, -0.587000, 0.157080, -0.469230, 0.772060,
-0.799480, -0.442130, 1.388330, 0.093800, 0.597040, -0.596280, 0.026090, 0.156960, -0.615380,
-0.682920, 0.486720, 1.471370, -0.664990, 0.720770, -0.671340, 1.293240, 1.770850, 0.380360, -0.494990,
-0.034340, -0.204880, -0.004390, -1.148780, -1.363320, -0.096040, 0.780730, 3.775510, 0.331490, 0.511150,
-1.858680, 0.199770, 0.239890, -0.723640, 0.133580, -0.006100, 0.319660, 0.406680, 0.872950, -0.830390,
1.243120, 0.913050, 3.634710, -0.189240, -0.564230, -0.581960, 0.406880, 1.563500, -3.446500, -0.107530,
3.096860, -0.638570, 0.462030, -0.584840, 0.422890, -0.601890, -0.555470, 0.383290, 0.972110, 2.399270,
-0.519140, 0.045030, 0.366240, 0.141720, -0.247530, 7.254810, -0.972460, -0.715490, 1.284230, 0.342260,
1.197240, 0.264890, 0.199490, 2.414970, -1.406860, -0.362630, 1.027590, 0.078210, -0.082330, 2.073470,
1.272660, 0.618640, -0.897710, 1.269420, 0.897020, -0.994080, 1.043450, 1.202460, 1.608520, 1.038250,
0.150660, 1.331620, -0.189460, 0.740470, -0.265450, 0.857620, 1.563840, 0.263960, -0.997230, -3.009270,
-0.032450, 0.481440, 0.516530, 1.596600, 1.171480, -0.192040, 3.057660, 1.000570, -0.051180, -0.625240,
1.781940, 4.025870, -1.119780, 0.162380, -2.376230, -1.814990, 0.163540, -0.831620, -0.083220, 4.466450,
0.750510, 0.050060, -1.292620, -0.952910, -0.935760, 2.259450, 2.196290, 1.166540, -0.928840, 0.129330,
1.692130, -0.931970, 0.765920, 2.232080, 3.150100, -0.453190, -1.644500, -1.258890, 0.833460, 0.906040,
-3.402010, -1.455760, 2.922630, -1.358230, -0.591680, 2.145540, -0.087690, -2.254850, -1.839380, 0.296060,
0.313910, -2.229210, -0.533580, 0.907230, -1.226500, -1.783380, 0.849770, -0.320650, -2.185650, -1.881860,
0.176550, -0.312600, -0.359040, -0.787290, -0.325840, 0.359420, -0.455450, 0.155680, -0.554460, 0.437080,
-1.195130, 0.604870, 1.056930, 0.972060, 0.115730, -1.021720, 0.136780, -0.808740, 0.931740, 0.364630,
1.220710, -1.389620, -0.055450, -0.386560, 0.707160, 0.563540, -0.557900, -0.433300, 0.514940, -0.499070,
0.253690, -2.715600, 0.283040, -0.125390, 0.218470, 0.340190, 1.340090, 1.781300, 0.197540, -0.771020,
0.184410, -0.172920, -0.460710, 0.704080, -0.904190, 0.466410, 0.279310, -0.688220, -1.173630, 0.252200,
-0.621270, 4.390110, -0.300710, -0.477560, 0.512890, 0.386650, -1.395440, -0.380490, 0.269230, -0.230760,
2.686510, 0.528570, -0.908790, -0.235960, -0.182710, -0.747000, -0.774150, -0.023650, -0.352120, 0.857270,
-2.546800, -0.937100, -0.407690, -0.087000, -0.641840, -0.149350, -0.508990, -0.425310, 0.451970, -2.919960,
-1.612050, 1.203480, 1.370500, 2.019450, -0.956860, -1.048740, 0.597830, -0.818240, -0.675440, -0.192180,
-1.710120, -0.545400, -2.005120, 0.434760, 0.101860, 1.119640, -0.475060, -0.166780, 0.155540, -0.294020,
-0.769110, 0.494980, -0.326800, -0.825000, -0.756950, 0.622840, 0.717780, 0.403040, -0.185490, -1.834070,
-0.503910, -0.188240, -1.126370, 0.027840, 1.370520, -0.878700, 0.162670, -1.620880, -0.143760, -0.902870,
0.623710, 0.452760, 0.579080, -0.027490, -0.073990, 0.056720, 0.214400, -1.537260, 0.811760, -0.374310,
-0.766510, -0.035480, -0.216730, 0.568780, -0.890020, -1.008050, -0.966910, -0.506100, -0.354330, -0.190280,
0.670670, -0.602360, -0.775140, 0.654850, -0.379490, 0.717350, 0.102300, -0.783920, 0.986920,
-0.045280, -0.605830, -2.627320, 1.993960, 0.664410, -0.097830, 0.106730, 1.233060, 1.055680, 1.652720,
-0.484720, -0.235680, 0.000250, 1.538930, 1.194510, 0.761810, -1.173590, -0.019590, -0.892520, -0.838770,
-1.413610, -0.491210, -0.341180, 1.097760, 0.294710, 0.245710, -0.812780, -0.502150, -1.170010, 0.939000,
0.564740, -1.861050, -0.449780, -0.718830, -0.063990, 1.277230, 0.210890, 1.128740, 0.228660, 1.384480,
0.153300, -0.716380, 0.512870, 0.346320, -0.754610, -0.484550, -3.029330, 0.510930, -2.683540, 0.903550,
-1.471610, 0.078330, 0.286210, -0.619200, -0.461200, 0.483090, -0.654010, -0.182290, -0.454140, 1.007700,
-1.364980, 0.636270, -0.574720, -0.597840, -0.053040, 0.553490, -0.371400, 0.876670, -0.810690, 0.681410,
1.543100, 0.304790, 0.935170, 1.063020, 0.591250, -0.364270, -0.077540, -2.606710, -1.221760, -0.281290,
-0.058180, 0.380520, 1.628510, -1.197150, 2.179860, 0.478240, -0.147040, -0.078090, -0.001600, -0.253330,
0.866360, -0.382700, 2.194180, -1.662430, 0.734710, -0.429960, -0.736320, 0.693610, -0.867210, 0.127820,
-1.267230, 0.752000, -0.097790, -0.379460, -0.160070, 0.930440, -0.488820, 0.966810, 0.519280, 1.487940,
0.181230, 0.522660, 0.194340, 0.360780, -1.868630, 0.556520, -0.017460, -0.712550, -0.721350, -0.569460,
0.080920, 1.377150, 0.707050, -0.345680, -0.837710, 0.104600, -0.221580, 3.213680, -0.073890, 1.010200,
0.729100, 1.004470, -0.912940, 0.631450, 1.175980, -0.179130, 0.529680, -0.137370, 0.363380, -0.733580,
1.937140, -1.433700, -1.467050, 0.314570, 0.900750, -0.253600, -1.623320, -0.066400, 0.218190, 0.565760,
0.894510, 0.682790, 0.743240, 0.260640, -0.424090, -1.800340, 2.661780, 1.119070, -0.686680, -0.089140,
-2.914550, 0.324190, 1.037830, -0.938410, -2.832190, 0.661430, 0.374960, -0.804670, 0.073490, -0.733910,
-0.456380, -0.532420, 0.891940, 0.072390, 1.297290, -1.449470, 1.029220, 0.248780, 0.068990, -0.204100,
-0.473040, -0.978310, -0.376320, -1.310930, -1.117450, 0.117440, 0.860620, -1.281700, -3.075200, -0.481330,
1.414130, 0.328840, -0.222770, 0.341910, 1.025340, -0.152930, 0.062530, 1.412250, 0.396530, -0.300470,
-0.752160, -0.884120, 0.825990, 0.770600, -0.480430, 0.057900, -0.032940, -0.098310, 1.302880, 0.086770,
0.400800, 0.228310, 0.784950, -0.295920, 0.429400, -0.591540, 2.930170, -1.123210, 0.062340, 0.614210,
-2.000490, 0.552390, -0.539330, -0.493380, 0.680570, -0.289410, 0.871630, -0.702930, -1.009080, -1.270040,
2.402610, 0.371800, 0.544430, 1.379570, -1.505060, 0.873050, 0.196480, 2.036640, -0.193220, -0.035960,
0.154480, 0.346590, 0.362690, 1.833750, -2.078300, -0.325560, 1.818110, 0.242890, -0.566190, 1.093220,
-1.835130, -0.740840, -0.611300, 0.884850, 0.558390, 0.504120, -1.579400, -5.055470, -1.032760, 1.353190,
-1.190010, -4.261320, 0.179770, -0.455320, 1.285500, 4.229350, -0.057790, -0.904800, -1.729240, -0.571680,
-0.726210, 0.209530, -1.465640, -1.563380, -0.432620, -1.349060, -0.762610, -0.161160, -0.816210, -1.158980,
-0.821930, 0.042120, -1.059020, 3.552810, -0.644840, -4.623230, -0.469960, -0.649510, -0.844550, -0.457640,
-0.836990, -1.725190, -0.312820, -1.531800, -1.116320, -1.107800, -1.342580, -1.661520, -0.890430,
-0.011590, 0.074410, -0.005740, -1.539260, 0.412950, 0.031830, -0.970220, -0.560870, 0.009560, 1.744830,
-2.158110, -2.092630, -0.902670, -1.677070, -0.523630, 1.956670, -0.191430, 0.085200, 0.813520, -0.491210,
-1.037730, 1.863210, -2.441880, -0.510370, 0.378000, 0.791580, -0.192900, 1.191580, 1.092130, 2.353260,
0.510220, 0.535280, 0.983830, -1.367910, 0.077670, -0.684090, -2.203290, -0.654140, 1.889180, -0.779720,
0.803360, 0.794450, 0.398300, -2.538020, -0.632690, -2.254950, 0.535470, -0.360090, -0.089840, -0.738710,
-0.239640, 1.951450, -0.146350, 1.106100, 1.153930, 1.152420, -0.375800, -0.156410, -0.682580, -1.660980,
0.311570, -0.959590, 0.374390, 1.125410, -0.374450, 0.621810, -0.742830, 1.130510, -1.738260, -0.557830,
-0.071280, -0.650470, -0.751670, 1.015460, 0.618150, 0.145280, 0.490900, -0.101710, 1.508010, -1.187050,
-0.385570, 0.013040, -1.611540, -0.092260, -1.260930, -0.637810, 1.826810, 1.240690, 0.111270, -1.683270,
0.280470, -0.719430, -0.031060, 1.720510, 0.552380, 0.165920, 1.086320, 0.101920, -0.225250, -0.445570,
0.377730, -0.317600, -1.901790, 1.239600, -1.494290, -0.227130, -1.143810, -3.508330, -0.748040, 1.671310,
1.260720, 0.195750, 0.611210, 1.944440, 0.124310, 2.527630, -0.127820, -0.930700, -6.352150, 3.437240,
-0.514000, -3.838450, 2.914130, -0.087090, -2.068510, 0.047330, -0.875210, 1.146390, 4.375520, 0.809010,
4.058660, 0.245740, 2.372730, 1.414400, -1.467190, 9.876820, 0.328530, -4.343970, -1.795540, 1.804860,
-0.911390, -1.081040, -0.392560, -1.099700, -1.003110, -1.050100, 0.245640, -0.103730, 0.691280, 0.186900,
0.194580, 0.552880, -4.195720, -0.161490, 0.244210, 1.060230, 0.483270, -0.517120, -4.525850, 1.768070,
-1.189470, 0.369070, 2.414860, 1.322860, -1.797470, 1.277210, 1.333200, -0.212080, 1.042550, 1.366730,
1.200010, -0.830380, -1.559490, -0.096760, 0.209500, 0.719700, -1.474170, 0.232650, 2.362370, 0.652210,
1.913640, -0.685310, -0.245860, -0.806320, 0.911910, 2.176500, 0.512120, -0.734160, -0.462060, -0.343480,
-1.332860, -0.731840, 0.480990, 1.029400, 1.665970, 0.437070, -1.387130, 0.412940, -1.355670, -0.635070,
-0.693700, 0.983990, -1.759600, -2.058660, -1.987770, 0.707990, 0.510550, -0.315940, 0.969750, 0.806560,
-0.712890, 0.822390, 1.039360, 0.709480, 0.389370, 0.721840, 0.109250, 0.331230, 0.401730, -0.160510,
-0.636130, 0.072340, -0.036670, 0.469350, 0.917470, 1.146960, -1.427290, -3.002920, 0.707680, -0.011820,
-0.248680, 0.224980, 1.206940, -1.086450, -0.139250, 2.397460, 0.080350, 0.991100, -0.260410, 0.842740,
-0.189300, 0.564040, 0.031840, -0.625060, 0.142340, -0.113510, -0.680430, 0.263850, 0.268350, -0.242570,
-1.188580, 0.927930, -0.921130, 6.498760, 0.547930, 1.420290, 0.674470, 0.304450, -0.986270, 0.278720,
1.109750, -2.165430, -1.335440, 0.898060, 0.111840, -0.766700, 1.376710, 0.290240, 0.714670, 0.134420,
-0.864520, -1.037490, -0.456690, -0.318980, 0.540300, -0.003570, 0.168840, -0.734640, -0.379350, -0.406450,
-0.355000, 0.416860, -0.017640, 0.141570, -0.595150, 0.670250, -0.193650, -0.889840, -0.194150, 0.316240,
0.599680, 0.394410, -0.636460, 0.651350, 0.480470, 1.071520, -0.233320, -0.774490, 2.398790,
0.070070, -0.507830, 0.535870, -0.555960, -0.573680, 0.156080, -1.867280, 2.895930, -0.800220, -0.564930,
-1.531650, 1.094180, -0.031030, -0.201700, 0.503080, 1.087630, -0.923430, -0.223860, 0.359330, 1.183980,
0.552880, -0.415000, 0.549820, -0.853350, 1.754710, 0.510200, 0.915370, 0.367080, 0.460240, -0.828400,
-0.789390, 0.297890, -0.810470, -0.896690, 3.869710, 1.245120, 0.765710, 0.110280, -1.860220, 0.256760,
0.488280, 3.050040, 1.510990, 0.326230, 0.033300, -1.305730, 1.106650, 0.163980, -0.518460, -1.473250,
0.341030, 0.806210, 0.715750, -1.120810, 0.849760, -0.461810, 0.320950, -0.308580, -0.199720, 0.482510,
0.847790, -0.276510, 0.396400, 0.711770, -0.364740, 2.168290, -2.365260, -0.032020, -1.037630, 0.944280,
-0.351070, 0.913320, -0.505780, 0.210850, 0.573260, 0.628620, 0.538410, 0.907700, 0.824420, 0.184750,
-0.663610, -1.079380, 1.288760, 0.652250, 0.575590, -2.549270, -0.473010, -1.364150, 0.665880, 2.010460,
-0.335400, -1.635170, 0.383980, 0.160390, 0.289680, -0.057220, 0.511070, 0.077060, -0.237750, 0.943220,
1.861630, 0.993610, -1.636220, 0.406950, 0.940890, 0.400220, -1.292090, 0.784230, 0.040020, 0.735860,
0.226550, -0.755940, -0.683350, -1.188290, -1.657620, -0.459350, -0.875530, -0.279520, -4.768910, -0.367580,
-0.507910, 0.571680, 0.247170, -0.136660, -1.056360, 0.539910, 0.027290, -1.182950, -0.504880, 0.583040,
0.307070, -0.497310, -2.924830, 1.300360, 0.487970, 0.933070, -0.613450, -0.224700, -0.631930, -0.051250,
0.727390, 0.094320, 0.778790, 1.212810, -0.325930, -1.302140, -0.835740, 1.126080, -0.595720, 1.035640,
-0.775290, 1.197390, -1.044270, 0.281420, -0.705970, 1.047570, 0.824150, 0.377190, 0.230980, 0.756800,
-0.161580, -0.603620, -0.991730, 0.575050, 0.097120, 0.877280, -0.485760, -0.513910, 0.400690, 0.746430,
0.420920, 0.872180, -0.704010, -0.034070, -1.375750, 1.227480, 0.541570, -0.843430, 1.080080, -1.736220,
-0.816490, 0.502340, 0.223030, -0.871130, -0.057540, -1.822110, -0.496140, 0.859500, 0.913950, -0.503920,
0.150200, 1.640310, -0.799950, -0.990450, 0.694730, 0.884800, 1.041870, -0.161430, -1.645020, -0.767920,
1.691780, -0.237350, 0.642940, 1.324430, -0.174180, 0.172320, 3.287210, 0.310110, -0.710790, 1.235420,
-0.257830, 0.885700, 1.430180, -0.707590, 0.343860, -0.088290, -0.443280, 0.688220, -0.321740, 0.986920,
1.068560, -0.328500, 0.602360, -1.397480, -0.818810, -0.531260, 2.874500, -1.451970, 0.554400, 2.752950,
0.546150, -0.805450, -0.077160, 2.110530, -1.317930, -0.396930, -1.618520, 1.363620, 1.091340, -0.548230,
0.079590, -0.947560, 0.308070, -0.225060, -0.437490, 0.167550, 0.209020, -0.901500, 0.326440, -0.807010,
0.850010, 0.643740, 0.698600, 27.595659, 0.261080, -1.295610, 0.076720, 0.709760, 0.574750, -1.126360,
0.058580, -0.322470, -0.231630, -3.335040, 0.169920, 2.182410, -1.775870, 1.707670, -1.209910, 0.916230,
4.490920, -0.466150, 0.396910, -0.047980, 1.256120, 0.304560, 1.276490, 0.986290, 0.768690, 3.014400,
1.122480, 0.669320, 0.478300, 2.656650, 2.842090, -1.536900, 2.908680, 0.396820, 0.435890, 0.538370,
0.491560, 1.343200, -0.367840, 1.110710, 1.318260, 1.111140, 1.433780, 1.351120, 2.977710,
0.257570, 1.216670, -1.511790, 0.369790, 0.161850, 0.558220, 1.290120, 1.360110, 0.349450, -1.726850,
0.804750, -1.065770, 0.985520, -0.395070, -0.462680, -0.940810, 0.744430, -0.311940, 1.093920, -0.331400,
5.924170, 0.367170, 0.980500, -0.216930, -1.744070, -3.090390, -0.103700, -0.763100, -0.540560, -1.265130,
-0.485450, -0.181940, -1.070200, 0.350600, -0.185180, -0.271480, 0.191950, -0.032900, 1.046890, -0.377830,
-1.582620, -2.559100, 0.349660, 1.321480, 0.015860, -0.237380, -1.713340, 1.171860, 0.650090, -1.198030,
-0.679180, 0.465610, -0.641970, -1.721190, -1.512040, -2.797040, 0.782600, -0.524960, 1.276480, 2.474010,
-0.285690, 0.421670, 0.039390, -2.444120, -0.436770, 1.090850, 0.092480, -0.176450, -0.419350, -0.403880,
-1.347960, -1.707760, -0.802450, -0.618290, -0.004100, -0.676050, 1.284570, -1.294180, -0.206660, 1.732660,
-1.466220, 0.809810, 0.528060, -0.350820, 2.166540, -0.161800, -1.068000, -0.169160, -0.201650, 0.459480,
-0.341790, 1.056600, -0.591760, -0.540870, -0.943040, -1.620510, -0.772130, 0.270870, 0.343420, 0.053690,
-0.842550, -0.566220, -0.262140, -0.975490, -0.000700, -0.534930, -0.872230, 0.051690, 0.547890, -0.585810,
0.941670, 0.473280, 4.639940, -0.152070, 2.317950, -0.404630, -2.171370, 0.440170, 1.902480, 0.330510,
-0.541970, 1.342080, -1.980650, -0.372760, -2.125930, 1.379960, 0.893510, 2.099320, -6.113570, 0.758090,
2.048810, 1.078520, -8.078450, 1.389220, 1.775830, -22.045031, -1.060580, 2.257020, -0.794020, 0.441280,
-1.386700, 0.726980, -1.731020, -0.494030, -0.853640, 1.315020, -1.028670, 0.094300, -1.538160, 0.089470,
0.434060, -1.264880, -0.436670, -1.031900, 1.121600, -0.353880, -0.769720, 0.323840, 1.060950, 0.599460,
0.294760, -0.061080, 0.654360, 0.138670, 0.004460, -0.168040, -0.071620, -0.643560, 0.632670, 0.830970,
-0.420470, -0.861710, -1.231400, -0.332750, -0.131910, 0.746330, 0.139380, -0.716230, 0.359380, -0.538790,
-1.678670, 3.809730, 0.032650, -0.919260, 0.292590, 0.204720, 0.884560, 0.203790, -0.345850, 0.733100,
-0.112410, -0.666800, -0.619700, 0.467030, -0.783750, -0.950160, 0.024300, 0.478670, 0.329700, -0.553040,
-0.421810, -3.474120, 0.117180, 1.070900, 2.892280, -2.492030, -1.603800, 0.753250, 0.762890, -1.213800,
0.187400, -0.389750, -1.379930, 0.058970, 1.107690, -0.400790, -1.005730, 0.475610, 1.441250, 1.784220,
1.871120, -0.636800, -0.119490, -1.891650, -1.266360, -0.439460, -0.837510, 5.371010, -0.717140, 0.273990,
0.094980, -0.058850, -1.067740, 0.147510, 2.377240, 0.125410, -0.366210, -1.491380, -0.003460, -1.346920,
-0.888170, 0.811680, -0.111640, 1.687030, -1.017410, -1.071580, 0.108010, -2.081380, 0.249950, -0.915990,
2.835850, -0.318950, 0.238710, 0.897760, -0.052510, 0.435290, 0.267420, -0.709020, -0.192060, -0.316080,
1.211300, -0.530130, 4.773010, 0.135320, -1.717770, -1.101290, 0.420370, 0.333450, -0.691540, 0.963190,
0.961430, 0.386210, 0.784500, 0.041960, 0.297080, -0.510570, -0.899640, -0.668680, -0.738940, 0.609140,
-0.070220, 0.102910, 0.586860, -0.811330, 4.758600, 1.759360, -0.333950, 0.474590, -0.460850, 0.003950,
-0.283710, 0.426260, 0.464650, -0.956470, -0.885530, -0.443020, -0.604110, -0.886680, -1.158190,
-0.380140, 0.656420, 0.911200, -0.838700, 2.968340, -0.376490, 0.528040, 1.893100, -0.774310, -0.864130,
-0.800540, -1.516570, -1.651680, 1.039530, 0.194680, 1.057350, 1.424980, 2.098510, -0.058280, -1.374090,
-0.518340, -0.073310, 0.239070, 0.430310, 1.393340, 0.656180, 0.229380, 0.074400, -0.093030, -1.615640,
0.022460, -0.212340, 0.258980, 1.471450, -1.269920, 0.409030, -0.067750, -0.579610, 1.689510, 0.087560,
-0.503820, 1.554340, 0.451960, 0.326820, -0.824330, 0.611190, -0.353750, 1.150550, 0.152730, -0.195300,
-0.748600, -0.317520, 0.362450, -0.398960, -0.847800, -0.562020, 1.076930, -0.557590, 0.273230, 0.043760,
-0.431270, 0.707580, -0.495310, -0.261090, 0.921080, 0.583840, -0.508560, -0.491430, -1.128370, 0.595600,
-0.002350, -1.094830, -0.796700, -0.458160, 0.193450, 1.393400, 0.277340, 0.732150, -0.201790, -0.578630,
-0.615510, 3.036040, 2.264100, -0.299410, -0.789200, -0.060070, -0.446600, -1.311400, -1.138900, -0.113130,
-0.172540, 0.861070, -0.854960, -0.430560, -0.116500, 0.487900, -0.298150, 0.078810, -0.057520, 1.966530,
-0.104940, 0.081690, 0.724010, -0.815000, -0.330190, 0.675490, -0.721310, 0.451170, -0.424240, -1.985500,
0.704150, -0.020720, -0.226990, -0.250250, 0.478580, 0.075740, 1.067280, -0.745140, 0.577240, -0.558140,
1.762050, -0.396710, 1.741200, 0.261670, 1.423520, 0.185640, -0.932880, 2.146050, -0.101620, -2.864380,
0.670120, -0.130310, 1.317170, -0.830070, 0.837140, 4.793190, -0.514220, 1.052870, 0.482590, -0.149400,
0.130040, 0.330250, 1.069240, -0.816330, 0.069780, -0.796480, 0.048860, 1.362280, 3.223900, 0.456780,
0.595060, 0.500170, 0.013470, 0.247090, 0.040830, -0.168870, 0.158890, -0.080280, -0.013290, 0.968110,
-0.870330, 0.451670, 0.722730, 1.126770, -0.103540, 0.749710, 1.153720, -1.395470, 0.832800, -0.205890,
-0.528550, -0.807860, 0.541910, -0.411930, 1.708440, 1.176390, -0.280560, 1.831040, 0.255880, -1.204170,
0.586450, 0.729640, 0.362900, -0.502840, 0.176150, 0.592320, 0.114210, -0.579430, 0.878230, -0.334920,
-0.432160, 1.264470, 0.441650, 0.382380, 0.122630, 1.030010, 0.676570, -0.763590, 0.240990, -0.105430,
0.722340, -0.207470, -1.052690, 0.254660, -3.068720, 2.809940, -0.189200, -0.085510, 0.075640, -0.509670,
0.211940, -0.372350, 0.142990, 2.281190, -1.733340, -0.942750, 0.023260, -0.287210, -0.744200, 1.320220,
-0.916320, -1.259370, 0.939930, -1.203210, 0.013850, 0.463510, 0.628690, -2.595290, -0.460480, -0.254860,
0.954980, 2.220620, -0.146830, -0.421580, -0.762320, 1.545480, -0.442750, 0.192200, 0.369360, 0.062280,
0.509860, -0.822150, 0.439840, 0.889890, -0.200880, 1.394210, 1.582600, 1.369820, 1.602500, -0.670020,
-0.850160, -0.039850, 0.551090, 10.778220, 1.060910, 2.293300, -1.179900, -1.339060, 1.164920, -0.895790,
-0.550630, -0.361150, -0.409650, 1.431420, 2.312830, 0.470140, -1.662790, 0.434580, -1.085980, -0.324120,
-1.176030, -2.671880, -1.126730, -2.074200, -0.065160, -0.925710, -0.189290, -1.753940, -0.354540, -1.260650,
-1.517730, -0.053210, -3.340890, 0.032830, -1.046960, -1.812710, -2.536700, -1.318000, -1.873470, -1.771600,
-3.682240, -1.037580, -7.108140, -0.705590, -1.978690, -0.811390, -0.885480, -0.386630, -0.637470,
-0.449980, 0.906600, 1.152670, 0.091340, -0.298480, -0.153180, -0.263880, 0.021070, -0.761450, -0.946010,
0.745710, -1.082500, -0.165480, 1.448160, -0.585480, 0.899270, 1.391040, -0.108080, 0.129330, -0.881360,
-1.336390, -0.892740, -1.208650, -0.781350, 0.963330, 1.450570, 0.006350, 0.664080, -1.986740, 0.227030,
0.931100, -1.074900, -0.495260, 0.447110, -1.095570, 0.204210, -0.146960, 0.990370, -1.357090, 0.900500,
1.077680, -0.715300, -0.742880, 0.359770, -0.505020, -0.395060, 0.093770, -0.139500, -1.368360, -2.266950,
0.267120, 1.282330, 1.336830, 0.399710, -0.354820, 0.630190, -0.116460, -0.044350, 0.695670, 1.964310,
-0.229470, -0.203540, 1.727380, 0.420790, 2.315730, -0.372130, 0.771090, 1.222160, -0.317190, 0.104740,
0.908240, -0.828720, -2.499560, 0.667270, -0.677960, 1.407130, 0.697830, 0.033410, -1.687000, -0.520550,
-1.056780, -0.124850, -1.181770, -0.103420, -0.559940, -0.398820, 0.858080, 0.566960, 0.300300, -2.183600,
-0.434940, -0.664910, -1.326280, 1.752000, 0.074370, 0.986270, 0.393830, -1.205650, 1.003370, 1.005550,
0.368700, 0.106310, 1.995220, 0.363240, -0.749090, 1.360850, -0.098450, -1.226570, 0.651870, -1.052660,
1.819960, 1.810820, -0.732900, 0.951800, -0.991460, -0.439070, -0.638260, -0.283260, -1.052920, 0.431430,
1.315960, 0.216340, -0.006180, 0.118990, 4.081440, -0.712350, 0.888000, 0.384580, 1.214780, 0.357370,
-1.175530, -0.191130, 1.118710, -0.507000, -0.902040, 0.143540, -0.828570, -0.597180, 0.195110, -1.594490,
0.089690, 0.568410, 0.449400, 0.245730, 0.263430, -1.401210, -1.154600, -0.575730, 0.235940, -0.488140,
-0.053430, -0.134030, 0.241630, 0.227190, 1.131350, -0.348910, -0.784380, 0.798230, -0.342380, 0.602910,
0.706230, 0.199780, -2.823190, 0.325240, 0.024540, 1.224950, 1.153220, -0.054150, 0.274700, -1.445050,
-0.570990, 1.060380, -1.249460, 0.486240, 0.834300, 0.684390, -1.074080, -1.157910, -0.774970, 0.478770,
1.172490, 0.013590, -0.179300, 0.487970, 0.334290, 1.536010, 0.280440, 1.008810, 1.287300, 1.171640,
0.465340, 0.062720, -0.777920, -0.363890, 0.070940, 0.855830, 1.374180, -0.767330, 0.183210, 0.273310,
0.784730, -0.657460, -0.639090, -0.145830, -0.391920, 0.498070, -1.102220, 1.643440, 0.049300, 0.303840,
-0.593780, -0.715300, -0.129060, -0.272980, -0.031550, -0.852760, -0.317500, 0.211250, -1.753460, 0.727060,
-0.568770, -0.132410, -1.222030, 1.146280, 0.541660, 1.042850, 0.225200, 1.045970, -0.445810, -0.353420,
-0.616710, 1.159190, 0.271540, 0.063580, 1.582330, 0.240410, 1.462300, 1.497940, -0.604000, 1.147360,
-0.016550, -0.597600, 0.286450, 0.090260, 0.690220, 1.958110, 0.689250, -0.031620, -0.593520, -0.375640,
-0.012530, -0.710490, -0.518960, -2.951220, 1.434800, 0.379900, -1.380530, -1.321650, -0.591150, 2.151280,
1.046540, -0.478600, 1.009580, -0.636300, 1.891690, -0.814760, -1.402730, 0.108580, -1.456430, -1.105580,
-0.157550, -3.001550, -1.033950, -1.520890, -1.736720, -0.931390, -0.908710, -0.063350, 0.187080, -1.722570,
-0.000940, -1.097130, -1.838140, -2.178010, 2.547290, -4.411030, -3.447320, -2.864740, -1.033760, -0.375540,
-4.679350, -1.412740, -3.139070, -0.623630, -1.055050, -0.943730, -0.402560, -0.328640, -0.951260,
0.185790, -0.678880, -0.761560, 1.359480, -0.946340, -0.124910, -0.985190, -1.705160, -0.262730, -0.410310,
-0.247630, -0.949200, -0.441680, 0.039730, -0.696290, -0.183090, 0.676220, 0.816780, 0.827020, -1.066060,
2.187060, -0.763320, 0.104910, -0.720210, -1.632350, 1.134970, -0.065980, -0.793720, -1.379190, 0.777810,
0.898110, -0.731000, -0.196390, 0.310140, 0.864220, 0.661790, -1.202610, -0.628750, -0.713080, 0.543470,
0.158590, 1.144860, -0.118780, -1.070590, 0.268920, 0.028140, 0.419150, -0.628790, -0.513620, 0.190490,
-0.597750, -0.589760, 0.596920, -0.176200, 0.511930, -0.515340, 0.233080, -0.495700, 0.769780, 0.503380,
1.040700, -0.900200, -0.100300, 0.537650, 0.843350, 0.455690, 0.362030, -0.031050, 0.690700, -0.550160,
-1.027480, 0.046860, 0.964400, -0.440610, -0.369460, 0.050780, -0.007760, -0.798970, -0.744520, -0.593680,
-0.073460, -0.781890, -1.263210, -0.524990, 0.657160, -0.330360, -0.816000, -0.775430, -0.782520, -0.359010,
0.221790, 1.485590, 0.495950, -0.972840, -0.677220, 0.031280, 0.228240, 0.197220, 1.224690, 0.822530,
-1.413200, 0.105890, -0.623190, 0.929830, 0.417640, -0.170740, 0.661730, 0.713610, 0.686860, 0.079670,
-0.011520, 0.656880, -0.551800, 1.169820, 0.219990, 0.784950, 1.962610, -0.844940, -0.966280, -0.466270,
0.517270, -0.672410, -0.220300, 0.902290, -0.888220, -0.523300, -0.772780, -0.057640, 0.736310, -0.970380,
-0.542570, 0.010410, 0.760350, 0.835770, -0.987170, 0.977750, 0.416070, 0.105390, -0.160470, 0.290290,
-0.275800, 0.790950, -0.932370, -1.898470, 3.143450, 0.057280, 0.268320, -0.906560, 0.146340, 0.305320,
1.605380, -0.826570, 0.249500, 0.148300, 0.921840, -1.492360, 1.362420, -0.707510, -1.892340, -0.185430,
-0.608910, 1.237330, -0.258330, -0.712120, 1.128070, 1.580280, -0.286040, 0.030100, 0.879050, 1.834040,
-0.411170, 0.305570, -1.003420, -0.041430, 0.534110, 1.095330, -0.655770, 1.220990, 0.638730, 0.097620,
0.372080, 1.247850, 0.397140, -3.472290, -0.321870, -0.067670, -0.497790, 0.197980, 1.508940, 1.050870,
1.441650, -0.104090, -1.086630, -0.191120, -0.140370, -0.955780, -0.218020, -1.413610, 0.634860, 0.803770,
-0.005810, -1.694690, -0.780420, 0.405480, -1.395130, 1.109100, -1.228620, 0.206160, -0.777120, 0.749810,
-1.592720, 0.146780, 0.789540, 0.838460, -0.316020, -0.038520, 0.574450, 0.031050, -0.679430, -0.577020,
0.630580, -1.215380, 0.044440, 0.289720, 1.601370, -0.384130, 1.211980, 0.981430, -0.184820, -0.014320,
-0.943080, -1.464730, 0.629630, -0.424030, 0.026360, -0.622720, 1.075430, -0.449630, -0.896300, 1.161150,
0.448610, -0.098490, 0.699810, -0.769160, 0.007820, -1.178440, -0.993400, 1.164740, -0.146210, -1.663320,
1.506930, 0.417860, -1.338590, 3.307560, 0.736920, 1.195070, -0.767630, -0.682820, 1.266820, 0.519870,
-0.137650, -0.522440, -1.538520, -2.434710, 3.228280, -1.402110, -1.186530, -0.748330, -0.713650, -1.384200,
-0.266860, -1.190820, -0.397580, -2.002430, -0.863950, -1.027070, -1.409180, -0.733270, -0.610120, -1.144470,
-0.754790, -0.227490, -1.431910, -0.771840, -1.243550, -6.417760, -0.735970, -1.106380, -1.536880, -2.010690,
-0.417700, -1.742390, -3.284050, -1.499800, -0.539600, -2.002950, -0.343520, -0.728560, -0.978730,
-0.451140, 0.091710, 0.212290, -0.070640, -0.854470, -1.624690, -0.479280, 0.109170, 0.949040, -0.317760,
-0.956870, -1.336130, -0.527510, 0.623980, 0.053130, -0.182310, -0.748870, -0.462230, -0.953350, 0.036890,
0.314150, 0.292810, 0.503770, 0.063740, 0.665800, 0.356320, -0.372740, 0.384920, -0.046910, 0.340300,
-0.368200, -1.004370, -0.404600, -0.222230, 0.143020, 0.487010, 1.031330, 0.930330, -1.943670, 0.707570,
0.101680, -0.283490, -1.870770, 1.070050, -1.821110, 0.221190, -0.049140, 1.542040, -1.216940, -0.177880,
-0.519490, -1.364730, -1.290800, 0.061490, 1.130770, -0.040280, 0.182700, 0.461300, 0.427050, -0.750050,
0.804100, 0.556480, -0.250690, 0.669560, 0.125710, 1.588420, 1.013330, 0.887350, -0.818200, 0.241600,
-0.215810, 0.268310, 1.089300, 0.422280, -0.066790, -0.387760, -0.874600, -0.516860, 1.245160, 1.763680,
-0.523810, 0.851840, -0.445800, -1.046090, 1.222160, -0.379800, 0.716290, -2.304640, -0.642720, 2.679530,
-0.881410, -0.353090, -0.120970, 0.909190, 0.728840, 1.275470, -0.150970, 0.422860, -0.664510, 0.285830,
0.221270, -0.831100, -1.257690, -0.385500, 0.109220, 0.509130, 0.097730, -0.110610, -0.746470, 1.281570,
-0.852910, -0.765880, 1.509890, -0.272660, -0.488360, -2.585400, -0.500680, -0.517100, 1.172890, -0.946480,
-0.223150, 1.818050, -2.020540, -2.844770, -4.350910, 0.148210, 0.973230, 1.348590, -3.282640, 0.717470,
1.449040, 1.272750, -1.737900, 2.976880, 1.518090, -9.955920, 1.890440, 0.266350, 0.824550, -0.303090,
-0.016850, -1.156180, 0.227210, -0.314790, -1.096070, -0.652300, -0.147040, -0.995050, -0.052270, -0.275810,
0.175320, -0.114000, -0.126770, 1.134450, 1.219470, -1.126300, 1.274110, 0.225410, 0.893090, 0.448420,
-0.349400, 0.471910, -2.654150, 0.458880, 1.789840, -1.045160, -0.434090, 0.202850, -0.779060, -1.533370,
0.950620, -0.485850, 0.118060, 0.036360, -0.793220, -0.203370, 0.106180, 1.481890, -1.273340, 0.092650,
0.404360, 3.007660, -0.142310, -0.548320, -0.205730, -0.447570, -1.086850, 0.201530, -0.634320, 0.744710,
0.209830, -0.696220, -0.864350, 0.221800, -0.417960, 0.968610, 0.067470, -2.572280, -0.764230, -0.828470,
0.266870, -1.840690, 0.410100, 0.494160, -0.299100, -0.336670, -0.973620, 1.046590, -1.137150, -1.366270,
-0.193330, -0.040330, -1.450620, -1.090410, 0.687340, -0.757710, -0.317800, 0.701120, -0.762320, -0.151260,
1.086320, -0.663230, 0.792910, 0.589270, -1.007950, 2.622810, 1.149150, 0.235270, -0.121170, -0.049030,
1.030250, 0.433710, 0.512030, 0.053410, -1.314620, 0.286300, 0.001090, -1.968800, 0.840360, -0.997060,
-0.421760, 0.713780, 0.894500, 0.466430, -1.399950, 0.550630, -1.089610, -0.978260, 0.473900, 0.377150,
2.324040, 0.052040, 0.339550, 0.913750, 0.373180, 0.294030, 0.935120, 1.219450, 0.514120, 1.583460,
-1.384660, -0.275920, 7.828210, 1.433690, 0.770200, 0.182000, 0.055400, -0.379230, 0.849350, 0.162010,
-0.402830, 0.311660, 0.913260, -0.088590, -0.744000, 0.363120, 0.976870, 0.700160, -0.687130, 0.444080,
-0.610480, 1.028690, 0.439650, 0.028220, -0.552900, 0.255680, 0.160500, -0.878150, 0.070050, -0.254840,
-0.885750, 0.252660, 0.215650, 0.479400, -0.093110, 0.798780, 0.904900, -0.646470, -0.879360,
0.863150, -0.490030, 0.568870, 2.390360, 0.273200, 0.531250, -0.602570, 0.937070, -0.837000, 0.833670,
0.172350, 0.405540, -0.089850, 1.445570, 1.214530, -0.671030, -0.227760, -0.321490, -0.692160, 0.499790,
1.075430, -0.692500, 4.231550, 1.546060, -1.356430, -1.189960, 0.903310, 0.377060, 0.212750, 0.212190,
0.130660, 0.949150, -0.408390, -0.547320, 0.285650, 0.013420, 1.115320, 0.092080, 0.217470, -0.233480,
-1.752250, -0.096770, 0.199330, 0.345940, -0.818530, 0.576460, 1.224880, -0.366550, 0.448480, -0.220320,
-0.253530, 1.406010, -1.380530, 1.874940, -0.130650, -1.493550, -0.405270, -0.076020, -0.959060, 0.295340,
0.111890, 0.191870, -0.406320, -1.105300, -0.579010, -1.127300, -0.454870, -0.245580, 1.244090, -0.517270,
1.883620, 0.343710, 1.292090, -0.074980, -0.342910, -0.474820, 0.184080, -0.087550, 0.547550, -0.262770,
-0.732640, 1.159600, -1.525600, 1.513920, 1.075290, 0.777170, 0.952060, 0.303170, -0.946610, 1.111710,
-0.419590, 1.050270, 1.564690, -2.606560, 0.291900, -0.850560, -0.114720, 0.707690, -1.315160, 0.260750,
0.652040, 0.159200, 0.323770, -0.828820, -0.104050, -1.008490, -0.251620, -0.209010, -0.230570, -0.349410,
-2.381890, -0.884240, 0.361280, 0.249550, 1.120320, -2.011270, -4.183970, -0.624630, 1.415280, -0.343640,
-0.240980, 0.169490, -1.060550, -2.762220, -0.898750, 0.448970, 1.634370, 0.956020, -4.167680, 3.210880,
1.862200, 1.608570, -1.925890, 2.092320, 1.828900, -1.191500, 0.579680, 1.577460, -0.032580, -0.088370,
-0.322550, 0.832490, 0.329080, -0.496430, 0.009250, 1.292420, 0.655220, -1.646010, -0.724070, 0.166470,
-1.810470, -0.515910, -0.589780, -0.740640, 0.525490, -1.116630, -0.148000, 0.851190, -0.820900, 0.102940,
0.612510, -0.068770, -1.258670, -1.157020, 0.006910, -1.752840, 1.375250, 0.091930, -0.786180, 0.543570,
1.794940, 1.509510, -0.068000, -0.043670, 0.654930, -1.324520, 0.014580, 0.488910, -0.098770, 0.938100,
1.427750, 0.181200, -3.318740, 3.910560, 0.244760, -2.392800, 0.704730, 0.580330, 0.721850, 0.030520,
0.084280, 0.170620, 0.547370, -0.358510, 0.569830, 0.173480, 0.479320, -1.601870, -0.467250, -0.660500,
0.515710, -1.018680, -0.045900, -0.217840, -0.109580, -0.301530, 0.707810, 0.146630, -1.447530, 0.608780,
-0.138970, 0.629370, -0.278820, 1.422580, -0.274910, 0.345930, -3.138830, -0.390870, -3.498340, -0.056220,
-0.465770, -0.949290, -0.356710, -0.698430, -0.396320, -0.148660, 1.778330, 0.179980, 0.084200, 0.295730,
-0.153550, -0.724080, -0.042200, -0.108840, 0.533840, -0.963740, 0.319200, 0.253280, 0.155820, 0.415160,
-0.857410, -0.296700, 0.721820, -0.403670, 0.061870, 0.453470, -0.068080, -0.170460, 0.352700, -0.045230,
0.048320, -0.853750, -0.043630, 0.772180, -0.923170, -2.160850, -0.320030, -0.020040, -0.457820, -0.559910,
-0.450180, 0.816950, 1.171930, 1.533600, -2.659610, -0.605340, 0.177620, 0.065470, -0.793940, -0.613050,
0.752290, 1.158240, 0.153200, 1.383290, -0.403120, 0.991140, 0.170130, 0.312180, -0.475470, -0.855220,
0.249690, -0.265950, 0.954620, -0.164600, -0.044760, 0.706920, 0.577020, -0.046200, -0.441490, 0.698370,
0.526320, 0.175550, 1.892300, 0.832570, -0.534410, 0.740970, 1.189390, -0.640650, -0.084490,
0.057740, 0.110870, 0.529900, 0.353870, 0.521740, 0.309580, -0.369400, 0.471870, -0.679960, -0.054750,
0.380860, -1.231340, 0.183430, -1.123810, -1.152310, 0.846950, -0.199600, -0.233810, 0.248650, -0.660190,
-1.556710, 1.006470, -1.256680, -0.697290, 0.516230, -0.032400, -0.458350, 0.020380, -0.800160, 0.421470,
-0.475990, -2.198450, -0.406860, -0.866220, 1.295920, 2.235520, -1.766280, 0.391580, 0.227780, 1.035710,
0.812170, -0.187040, -0.943240, -0.046150, 1.383300, -4.922870, 0.593390, -0.014650, -0.414730, 0.777160,
-0.117360, -0.420470, 2.043920, -0.173710, -0.631670, 0.122120, -0.240570, -0.886740, 0.175220, -2.248490,
-0.913270, 0.127860, -0.635740, 0.419780, -0.277920, -0.602630, -0.867020, 0.361470, -0.377630, 2.117390,
2.781610, 0.223880, -0.151340, -0.175910, 1.320320, -0.867250, 1.796140, 1.144210, 0.387480, -0.470200,
-0.433680, 0.513860, 0.941580, 1.152000, -0.650510, -0.480700, 3.217140, 0.539040, 0.199280, 0.474670,
0.213880, -3.299500, 0.058700, 0.581240, -0.261300, -0.476370, -0.378520, -0.591370, 0.615880, 1.086940,
-1.449380, -0.544950, 1.676950, -0.511230, 0.800540, -0.815080, -1.503320, 0.016990, -0.385970, -0.152550,
0.191030, 0.326420, -2.321440, 0.904480, -1.776010, 0.486380, 3.034260, -1.347350, -3.099530, -1.847140,
0.077460, -0.532060, 0.103500, -0.141890, 1.051160, 0.485920, -0.904190, 1.179200, 2.035600, 1.473400,
-0.343820, 0.481980, 1.662110, -0.855540, -0.581640, -0.231740, 2.238030, -1.744660, -0.099120, 0.522700,
-1.345410, 0.110810, 0.445390, -0.255910, -0.339530, -0.060000, -0.588360, -0.237110, 1.974180, 0.017540,
-1.717870, 1.177550, -0.211190, 0.642270, -0.709140, -0.600900, -0.704480, 0.076360, 0.238020, 1.303890,
-2.147620, 0.570490, 2.434810, 0.799430, -0.374150, 1.371250, 1.393570, -1.291050, 4.153730, -0.284050,
0.987900, -0.645610, 0.948330, 1.121760, 1.972550, 0.762370, -0.545570, -0.375830, 0.750370, -0.883160,
-0.653520, -0.753450, 0.202640, -1.718150, 0.230250, -0.365240, -0.642880, -1.536060, -0.852310, 1.047680,
0.811740, -0.072880, -0.369270, -1.184460, 1.599410, 0.415090, 1.735090, 0.553520, 0.241570, -1.677880,
-0.397710, -0.135600, -0.257920, -0.239560, -0.433400, -0.654730, -2.499520, 0.033010, 0.034390, -1.524230,
-0.957230, 0.149760, -1.830240, -0.214490, -0.642400, -1.285270, -0.176760, 1.299130, 0.588510, -0.427320,
-1.448630, -0.225710, 0.337260, 0.407060, 0.012120, -1.866540, 0.318070, 1.307980, -0.215580, -0.110770,
-1.187020, 0.442320, 0.301890, -2.960330, 0.520160, 0.112290, 0.708020, 1.328500, 2.423950, 1.647880,
1.997940, 0.857050, 0.155860, 0.935270, -0.101010, -0.629490, 0.917670, 0.454960, -0.009760, 0.338530,
-4.984910, 2.214450, -2.852180, -2.755930, -0.200670, 7.150740, -0.241180, 0.250970, -0.154880, -0.188630,
-0.328250, -0.604590, -0.359280, -2.294520, 0.748140, 0.584430, -0.521520, -0.487360, -0.827550, -0.602600,
-0.290780, -0.531190, -1.281910, -0.927660, 0.191170, 0.350280, 0.492020, -1.445070, -0.168000, -0.237880,
-1.094620, -0.547420, -0.997270, 0.924620, -0.994760, 1.969440, 0.034420, -0.442500, -0.575340, 0.714180,
-1.229390, -0.652150, -5.694430, -1.311990, -0.404690, -0.411010, -1.765030, -0.560270, 0.007400,
-1.613010, 0.055030, -0.856310, -0.447770, 0.873240, -0.922420, 0.734750, 0.426700, 1.998500, 0.624180,
0.123160, -1.324030, -2.047960, 0.084810, -0.077010, 0.670060, 0.376300, 2.134040, 0.176040, 0.458130,
0.158450, 0.419990, -0.810370, -0.186980, 1.939380, 1.869950, -1.053370, 1.359990, 0.907320, -0.281860,
0.723230, 0.977660, 0.123310, -0.291490, 0.308140, -0.478940, 0.630090, 0.984270, -0.329080, -0.530650,
1.547980, -0.189540, -0.761530, 0.066830, -0.538940, -2.596950, 2.598690, 1.589520, 0.524850, -0.622800,
-0.555570, 0.141150, -0.969660, -1.482370, 0.813810, 0.875890, 0.317260, -0.198520, -0.301350, 0.645220,
3.898830, 0.720900, -1.372510, 0.805770, 0.709260, -1.263980, -0.829970, -2.213020, -0.640430, 1.547620,
1.296560, 1.633080, -1.725520, 0.584630, 0.122080, 0.694850, 3.161360, 2.262930, -0.748990, 0.369810,
-0.198050, -0.506620, 0.144010, 2.230420, -1.971690, -0.682350, -0.582970, 0.450260, 0.194590, -1.508230,
0.134640, -1.018230, -1.825660, 2.229050, 0.538060, 0.056060, -0.482090, -0.280940, 0.101070, 0.180070,
0.887570, -0.762160, -0.421490, -0.007430, -0.392170, 0.411200, 1.043980, -0.639760, 0.421420, 0.442600,
-0.312740, -0.308410, -1.111280, 0.189870, 0.111880, 0.681540, 4.516970, 1.925140, -0.558990, 3.644360,
2.597990, -0.772430, 1.800470, 2.356860, 2.700870, -0.790870, -0.537770, 0.846020, -1.229200, 0.973470,
3.175040, -2.020270, 4.786680, 1.738140, -0.221560, 6.449890, -1.068060, 4.300580, 1.236120, 4.080090,
1.277270, 0.048870, 1.883050, 1.241620, 0.256560, -0.286790, 0.169100, 1.634140, -0.997760, -0.220880,
-0.679420, 0.796790, 1.139450, -0.346250, -1.507960, 0.949260, 0.860310, -0.214330, -0.768470, -0.474520,
-1.107700, 0.290120, -0.581880, 0.131460, 0.263930, 0.675770, 0.607620, 1.929420, 3.934300, 0.015400,
-1.168650, -0.137970, 2.690000, 0.517240, -0.288960, -0.415300, 1.034470, -0.787840, -0.270810, 0.508030,
-1.330130, -3.656270, 1.616390, -1.180480, 1.663300, -0.015200, 0.123620, 0.831750, -0.302540, 1.701850,
0.027500, -0.730400, 0.459560, -0.554950, -0.710500, -0.443520, 0.415360, 1.357330, -0.074130, -0.081240,
0.321960, 0.326100, -3.030750, 0.793240, 0.075990, 0.675300, 0.455470, 0.507690, 3.391240, 1.459930,
-0.395760, 3.272980, 0.775230, -1.164660, 0.666460, -0.325430, 1.527700, 0.162630, -0.109130, -1.140150,
2.466720, -0.285430, 1.405030, -0.383410, 3.412530, -0.739220, 0.724790, -0.162640, -1.022090, -0.158370,
-0.768480, -0.828990, 0.809280, -0.225350, 0.337940, -0.530460, 0.101250, 1.157470, 0.323560, 0.521370,
-1.133870, 0.679850, -0.282300, -2.147810, 1.235890, 0.317340, -0.186930, 1.463580, 0.833960, -0.723540,
-1.379100, 0.996070, 0.399780, -0.947430, 0.798280, 0.364510, -0.524230, -0.521000, -0.081020, -0.728090,
0.006000, -0.294240, 2.874940, 0.432280, 1.678250, -0.009080, 1.531230, -0.436700, 0.193890, -0.489890,
-0.712080, 0.255010, 0.138950, 0.678200, 0.590000, 0.630580, 0.128390, -0.853430, -0.592940, 0.579610,
-0.365410, 0.711100, -0.598350, -2.482720, -0.099240, -0.741140, 0.662240, -1.543530, 0.404210, 0.840520,
0.009710, -0.423410, -0.319730, -0.079300, -0.742120, 0.049330, -0.339080, -0.599930, 0.296630,
-0.465510, 0.468850, -0.257720, 0.106460, 0.951790, 1.021790, -0.813050, 0.697270, 0.699490, -1.113920,
-0.384820, -0.806640, 1.181530, -0.351300, 0.771830, -1.277220, -0.170480, 1.144390, 0.571990, -1.401580,
-0.444910, -0.098350, 0.184680, -0.232740, -0.439860, 0.954590, -0.873410, -0.756170, 0.413570, 2.116390,
-0.390170, -0.252680, -0.259200, -0.688620, -0.221160, -0.850620, -0.232200, 0.253900, 0.234090, -0.589780,
-0.876550, -0.938310, -0.232200, 1.772760, -0.544930, 0.430380, 1.008880, 0.669900, -1.607160, 0.305570,
-1.016910, 0.693960, 0.156510, 1.262770, -1.337330, -0.922390, 0.980590, -0.125700, -0.766930, -0.233340,
-1.055950, 0.688410, 0.455130, -1.692690, -0.499730, 1.554160, 0.916840, -1.437830, 1.081450, 2.161880,
0.507750, 0.394300, -0.143750, -0.601400, 0.806650, -0.137840, -0.788110, -1.547350, -0.217800, 0.005890,
0.693530, 2.184890, -0.301080, 0.689790, -0.265310, 1.713580, -0.688710, 0.256500, -0.851050, 3.059380,
-0.520650, 0.629090, -0.046980, -2.028820, -0.075550, 1.577210, 0.365300, -0.703800, -0.212750, 0.062440,
1.270370, 0.701870, 0.672830, 1.169180, 1.220900, -0.319720, 0.540890, 1.327710, 0.154580, -1.870920,
0.320380, -0.091090, 2.701790, 0.211240, 0.378580, 0.022550, -0.562990, 0.542740, 2.536340, -0.838760,
-1.744930, 3.373380, -1.913040, -0.347510, -4.012800, -0.175470, -1.729670, 1.070410, 0.704920, -0.748540,
-0.580050, 0.472920, -1.982420, 0.255800, 0.578130, -21.373301, 1.379120, 0.163980, -0.557000, 1.210750,
0.051980, 0.261140, 0.491440, 1.137700, 1.579530, -0.637440, -4.258160, -0.124790, 0.166130, -0.040420,
0.350700, -4.169230, -0.712400, 0.129600, -1.093030, 0.024210, 1.253970, 0.571000, 1.457430, 0.102530,
0.883010, 0.394570, -1.141470, -0.813630, 0.217410, 0.844710, 0.747760, -0.922710, 1.457380, 0.425250,
-0.155680, 0.399590, 1.045980, 0.362900, 0.747410, -1.316380, 0.270770, 0.299480, -1.581110, 0.715530,
0.808650, 1.065960, -1.215120, 0.027980, 1.114210, -0.989770, -0.420860, 0.675170, -0.575070, 1.020180,
-2.571840, 0.030570, -0.208290, -0.251500, 0.567350, 0.317590, -0.491290, -0.725800, 1.039420, -0.158900,
0.030750, -2.506440, 0.949680, -0.070600, 0.996970, -0.148860, 0.608500, -0.488430, -0.392350, -1.174920,
-0.186180, 3.088760, -0.771700, 0.629640, -1.064940, -1.222140, 0.671750, 0.695540, 0.241690, -0.374030,
-0.133250, 2.124270, 0.157450, 1.109350, -4.239820, 0.529710, -1.630660, -0.078540, 1.245230, -0.353210,
-1.172780, -0.772970, 0.273310, 0.727750, -0.011980, 0.304250, 0.218770, 0.952110, -1.000410, -0.681200,
-0.015920, -0.041900, -0.349310, 2.479650, 0.062130, -0.161280, -0.104870, -0.038040, 0.686410, 0.704440,
0.267000, -0.250360, -0.587640, 0.507030, -0.638720, 0.530970, 0.488820, -0.396400, -0.704260, 1.270180,
2.604400, 0.283480, 3.144170, 1.046240, -0.661390, -0.952300, 0.744290, -0.637890, 0.182540, 0.787910,
-0.577370, -0.002940, -0.133320, -0.405520, 0.311380, 0.198630, 0.829500, 0.365580, 0.995830, 0.694370,
0.824080, -0.086710, -0.241170, 0.379690, 1.338520, -1.294810, -0.123460, -0.571860, 0.831500, 0.494220,
0.987870, -0.071470, 0.695000, -0.821060, -0.201160, 0.068610, 0.676750, -0.309980, 0.241000,
-0.946500, -1.926370, -0.052880, -1.371870, 0.715060, -0.280000, -0.177940, -0.843170, 0.052820, 0.147340,
-0.350460, -0.367880, -0.688030, 1.427000, -0.769750, -0.524560, 0.052730, 0.559970, -0.156120, 0.347350,
-1.153290, 0.862950, -0.401740, -0.708210, -0.643390, -0.007900, -0.922810, -0.157370, 0.271460, -1.230610,
0.176550, 0.686820, 0.642160, 0.006600, -1.182480, -0.823020, -1.891990, 1.251870, 0.207330, -0.518000,
0.485930, -0.609340, -1.625360, -1.194620, 0.614960, 0.968020, -1.351980, 0.219300, -0.959930, -0.295950,
-0.047570, 0.232970, 1.418760, 0.141540, -0.682120, -0.446060, 0.854290, 0.479330, -0.261660, -0.116970,
-1.078860, 1.827980, 0.992020, -0.459710, -0.016760, -0.377270, -0.811100, -0.332560, 0.720400, 0.917750,
-0.373060, 0.364650, 0.136100, 0.163940, -0.351290, 0.232300, -0.663680, -1.019050, 0.318990, 0.956050,
0.709890, 0.573870, -4.944940, -0.365280, -0.908320, 0.892920, 0.594340, -0.610020, 0.459940, -0.124990,
0.209540, 0.327060, 1.338250, 0.002990, 1.927700, 0.026940, -1.022330, -0.160220, 0.577390, 1.296640,
-0.750150, -0.264300, -0.417410, 2.545670, 0.157990, 1.175330, -0.448930, -0.762640, 0.523820, 0.152670,
0.675190, -3.266310, -1.028980, -1.395480, -0.397090, 2.013930, 0.858400, 2.582870, -0.367710, 0.864410,
0.812890, -4.995780, 0.202260, 3.451980, 4.494670, -1.042380, -1.980870, -2.912140, 1.427070, 0.509880,
-3.607290, -1.068830, 2.639480, -2.321450, -2.406070, 0.663340, -1.817150, -1.351220, 1.229190, 0.128620,
0.026060, -0.006020, 0.233620, 0.238940, -0.033820, 0.791580, 0.461450, 0.730510, 0.552180, 0.344730,
-0.141740, -0.231140, 0.077920, 0.370580, -1.399450, 0.305910, 2.469110, -0.036800, -0.352850, 0.592430,
-0.937710, 0.101170, 1.063150, -0.699750, -1.705870, -0.553970, 1.035900, -0.588570, 0.310230, 0.930540,
-0.602850, -1.806770, -1.079170, -0.327490, -0.058470, -0.878800, 0.242680, -1.338360, 2.199660, 1.005450,
-0.105480, 0.359280, 0.061410, -0.011500, 1.396620, 1.332790, 0.630160, -0.234860, 1.351800, 1.221370,
-1.280450, 0.219550, -0.593730, 1.727620, -0.579190, 0.014560, -1.465220, -0.288310, 1.656250, -0.763930,
-1.207350, 1.511820, -1.377880, -0.117200, -0.734490, -1.034930, -0.855620, -1.253890, 0.458480, -0.433710,
0.190140, -0.858520, 0.077630, -0.611300, 0.868790, -0.170250, -0.573990, 0.843630, -0.306350, -0.901850,
-1.149010, 0.626800, -2.330910, -0.207750, -0.624900, -0.497650, -0.575670, 0.917550, 0.959600, 0.339740,
-1.402150, 0.284630, 0.686240, 0.074450, 1.593370, -1.054370, 1.388410, 1.254310, -0.680150, -0.008280,
-0.737200, 0.092440, 0.852450, -0.011990, 0.251140, 0.808120, -0.184930, 0.607720, 1.021760, -2.214050,
-1.185410, 0.543610, -0.073780, 6.248690, -0.540810, 0.362690, -0.012830, 0.131350, 0.796050, 0.445420,
0.042500, 0.109740, -2.276950, -0.910840, 1.878390, 1.200810, -0.230640, -0.440640, -0.295650, -0.753820,
-0.453290, 0.465280, -0.707510, 0.303040, 0.007030, 0.455290, -0.497340, -0.100890, -0.535020, -0.944760,
-0.304840, 0.487260, -0.157930, 0.608200, 0.556430, 0.636860, 0.581770, -0.596990, 0.937970, -0.813730,
0.343960, 0.948540, -0.106660, 0.877300, 0.910240, 0.417020, -0.431600, 0.017290, 0.886960,
-1.073570, 1.113740, -2.038720, -0.127780, -0.229300, -0.122830, 0.113970, 0.678310, 0.825520, -1.098460,
-1.087860, -0.649950, 0.427500, 0.336710, 0.907140, -1.686250, -0.875260, 0.106340, 0.079770, -2.300990,
1.531990, -0.160610, -0.746800, -1.014730, -0.859770, -0.058160, -0.544810, -1.211110, -0.730980, -0.653780,
-0.522460, -0.186430, -1.232850, -0.083510, 0.156230, -0.925420, -0.529000, -0.313790, 1.479470, -0.327380,
-0.603660, -1.573540, 0.098650, 3.533800, 1.038860, 1.782510, -0.524700, 0.447460, 2.599410, 0.357860,
-1.243760, 0.230120, 0.747140, 0.748720, 0.283000, -1.892450, -0.427960, 0.136070, -0.522160, 1.421170,
0.408380, 0.318950, -0.082720, -0.234430, 1.558170, 0.349590, 0.478970, -0.273550, 1.123250, 0.322230,
-0.883420, -0.004690, 0.187150, -1.845970, -0.247510, 1.918310, -1.736750, 0.434160, 0.120490, 1.009970,
0.526210, -2.193050, -0.388080, -0.858880, -0.343880, -0.552150, -2.522500, 0.512010, -0.687150, -0.575680,
0.302090, 0.886610, 0.756710, -0.291290, 0.449340, -0.346350, 0.492640, -0.441460, 0.830050, 0.405870,
0.129450, -1.094780, 0.734830, -0.916470, -0.051030, -0.022340, -0.433810, -0.055790, 0.581350, -0.922880,
-1.534100, 0.601390, -0.549020, 1.272930, 1.241320, -1.274630, -3.167030, -1.340420, 8.723170, -6.198830,
0.030270, 0.681390, 0.569930, -1.855030, -2.114930, 1.259650, 0.350550, 0.519130, 0.305250, -0.607080,
-0.472770, 2.213980, -7.985020, -0.314140, 0.986930, -5.535830, -0.906910, -0.361450, -0.489490, -1.354960,
0.899050, 5.241540, 0.882830, 1.010670, 1.399810, -0.499530, -1.891080, -0.888190, 2.684830, -1.340180,
0.443660, -1.286560, -2.506170, 0.603340, -0.300490, -1.293710, 0.568360, 0.959240, -0.648080, -0.332230,
0.997160, -0.151990, -2.081260, 0.836640, 1.322190, 0.014080, 0.916890, 0.891100, -1.575610, -0.656730,
-0.431390, 0.138110, 0.492440, 1.037170, -0.752590, -0.134580, -0.588240, -0.418940, 0.368570, -1.337130,
0.271330, -0.670960, -0.995980, 1.553530, -0.918350, -2.258870, -1.386780, 5.270840, 0.533680, -0.443290,
0.214510, -1.857720, -0.788430, -0.065070, 0.063880, 1.087040, 0.817100, 0.411540, 1.893370, 1.192430,
1.057570, -2.035430, -0.633610, -0.158220, 0.355380, 0.612780, -0.135570, -0.524670, 0.435620, -0.960240,
-0.210180, -0.580260, 0.708410, 0.489570, -1.448050, -0.012890, 0.196860, 0.952080, 0.514720, -0.128560,
-0.061330, -0.490510, 2.269400, 0.129980, -1.375130, 0.517570, 1.184200, -0.176040, 1.140010, 1.447620,
0.093490, -1.651430, 0.798180, 0.314590, 1.709980, 0.492500, 1.024750, -1.411710, -0.985850, -0.134350,
0.085040, -0.091050, -0.158910, 0.505580, -1.585370, 0.544560, -0.398250, 0.751790, 0.745500, -0.294880,
-0.552280, -0.551880, 0.487080, -1.710680, -0.067840, -0.220210, -3.210260, -0.171130, 0.459760, 1.984190,
-0.018400, -0.784420, -0.527120, -0.721890, 0.512810, 1.763240, -0.361440, -0.776440, -0.197250, -1.216780,
-0.342310, -0.231230, -0.618010, -0.851650, -0.244120, -1.018830, -2.259420, -0.101630, -0.840930, -0.047020,
-0.888370, -0.963040, 1.321570, -0.467260, 0.248280, 0.856700, 0.115170, -1.113670, -6.025520, -1.057080,
-0.752370, -0.834170, 0.599940, -0.558980, -1.711070, -0.954040, -2.133620, -1.100740, 0.727930,
-1.072490, -0.795780, -1.254570, 0.797350, 1.053460, -0.815240, 0.620730, 2.276490, -2.175290, -2.039050,
1.008630, 1.644560, 0.378150, -0.260800, -0.433150, 0.963990, 0.866530, -0.994850, 1.008050, -0.070950,
0.356890, 1.427820, 0.748960, 0.247990, 0.939670, -0.944390, 0.549920, 0.754730, -0.213690, -0.832030,
0.599200, -0.697720, 0.272570, 0.621580, 0.731500, 0.291650, 0.489450, -0.726470, 0.130940, -0.555460,
0.200320, 0.918150, 1.003760, -0.470090, -0.495500, 0.092110, 0.655460, 0.048970, 2.086340, 0.191310,
0.571060, 0.357200, 0.290180, -0.253150, 0.311440, 0.548260, -0.467450, -0.169560, -0.161300, -0.182430,
-0.786410, 0.047200, 0.037420, -0.166170, -0.274960, 1.784500, 0.366040, -1.211180, 1.284710, 1.028830,
0.455290, -0.455500, 1.316320, 0.874810, 1.555200, 0.447970, -0.515340, -0.042210, 2.391190, -1.064040,
-0.966450, -0.754020, 0.767410, -0.752690, -0.568820, 1.469210, 0.164340, 0.238700, -1.176890, 1.379400,
-1.469400, 3.484580, 4.821890, -1.183170, 1.615620, 1.278940, -0.082020, -1.359370, -1.397880, 2.671340,
6.347790, -0.172480, -1.549730, 0.187590, 1.925620, 0.325450, 1.074300, -0.471040, -0.754570, -1.512670,
-0.927010, -0.567570, 0.729440, 0.077770, 0.304020, -0.377090, -0.594860, 1.202760, -2.634240, 0.195820,
-0.577230, 1.764910, 0.276160, -2.580140, -1.552390, 0.050550, 1.024420, 0.335710, -1.834760, 0.007720,
0.027560, -0.027620, -1.627590, -0.494230, -1.070250, -2.341000, -0.595170, 0.281170, -1.173520, 1.667310,
1.064080, 1.532210, -0.926190, -0.767470, 0.669700, -0.385770, -0.684950, -0.150110, -0.680690, -0.607690,
-0.196820, -3.185500, -3.945910, -0.047430, 0.880190, -2.572690, -0.203550, 0.652030, -0.134650, 0.300700,
-1.135700, -0.272680, -0.337770, 0.065020, 0.464790, 1.055380, -0.011210, -0.090240, -0.578220, -0.212840,
-0.240030, -0.927480, 1.330960, -0.625410, -1.558990, 1.903730, 0.079960, 0.085150, -0.389160, 0.372660,
-0.561110, 1.126370, -0.175550, -0.379360, 0.125260, -1.110970, 0.374140, 1.684150, -0.921180, 0.501530,
-0.137080, -0.490400, -0.513930, 0.838210, -1.643200, -0.206650, -0.022120, 2.742430, 0.314710, -1.861630,
-0.086290, 1.255320, 0.557040, -0.116950, -0.974170, -0.955010, -1.353270, 0.116030, -3.671130, 0.426340,
1.162900, 0.021340, 2.319550, 0.456670, -0.997760, -0.121470, 0.299380, -0.470780, -0.374790, 2.901810,
0.700180, -0.848690, 1.048870, -0.580330, -0.710020, -0.319610, -1.085790, -0.975890, -0.369850, -0.015900,
0.682540, 0.025600, 0.972800, 0.130130, 0.777770, 0.218990, 0.372700, 0.585380, -0.732510, 0.447020,
-1.621620, 1.087740, -0.341780, 1.269160, -0.796010, -0.330230, -0.699020, 0.252710, 0.883120, -0.146420,
-0.491700, 0.372660, -0.683040, -19.199600, -0.413290, -0.126060, 0.702270, -0.940880, 0.564870, 3.416700,
2.301730, 1.224530, -0.078110, 1.550070, -1.290820, -0.300420, -0.528710, 0.125610, -0.516780, 0.269870,
1.274870, 2.820290, 0.844330, 3.877550, 0.777180, 2.911220, 0.167840, 0.487280, 0.556600, 2.509120,
0.568680, 1.395850, 4.145430, 3.845150, 1.047690, -1.334020, 3.009330, 0.779140, 0.225310, 0.601190,
2.893240, 0.485940, 7.874160, 1.099260, 0.153740, 0.814860, 0.959790, 0.663130, 0.325030,
0.611180, -0.179060, 0.088670, -1.285220, 0.604060, -0.510330, -0.472140, -0.474360, -0.798050, -0.412790,
-0.648390, 0.650720, -1.438110, -0.282640, 4.494580, 0.845260, -0.250150, -0.446670, -1.378190, -1.056470,
-2.252770, -0.968360, -3.548320, 1.056720, 1.464670, 0.435030, 0.514960, 0.329880, 0.522060, 0.098360,
0.287300, 0.271790, 0.551180, -0.781980, 0.306830, 0.547720, -0.046520, -0.182570, 0.500690, -0.785330,
0.520020, 0.324730, 0.733350, -1.501620, -0.004840, -0.543340, -0.445810, 0.039240, 0.884410, -1.047770,
-0.829950, -1.672820, 0.784550, 0.443480, 0.268430, -0.723960, 0.080760, 0.169700, 1.160880, -0.849020,
-0.030170, 0.668920, -0.171580, -0.690680, -1.253310, -0.902830, 0.259010, 0.974690, -2.699320, 0.077000,
-1.234870, -0.307680, -1.375710, -0.363780, 0.322990, 0.922000, 0.411940, 0.876380, -0.543770, -0.475400,
-0.381890, 1.882220, 1.600040, 1.072530, -2.284370, -0.975150, 0.443390, 0.934500, -2.066820, -6.394540,
-1.126250, -1.195010, -0.537300, -0.974760, -0.528180, 0.761370, -0.344770, 0.185550, -0.514040, 0.708070,
-0.282060, -1.580840, -0.868560, -0.427330, 0.070250, 0.177580, 0.161180, -1.151500, 1.521170, -0.740910,
1.027460, -0.494650, 0.083430, -0.606570, 0.751480, 1.223140, 1.961480, 1.491310, -1.581660, -0.143370,
0.905450, -2.924870, -0.217560, 2.072890, 10.800800, -1.135700, -1.011430, -2.011820, -0.353740, 0.927800,
-0.782440, -0.528150, 6.649050, 0.451560, 1.291480, 1.471140, 0.421700, -0.369530, -0.540690, 0.024800,
-0.680340, 0.701200, -0.098620, 0.578640, -0.335940, -1.923250, -0.101280, 0.504470, -0.308920, -0.229100,
-1.167080, 1.578980, 1.672820, 0.950940, -0.541500, -0.249960, -1.083450, -0.902240, -0.531280, 0.546290,
-0.884630, 0.059960, 0.314100, 0.719260, -0.463240, -2.004610, 0.986840, 1.791250, -1.219950, 0.604620,
-0.063950, 0.031740, 0.012570, -0.121510, 3.151480, -0.066520, -0.150000, 0.662030, -1.491030, 0.419280,
-1.352170, 0.658720, 0.920380, -1.035340, -0.874440, 0.965340, 0.221410, 0.399000, 0.149040, 1.383090,
0.011440, 0.795430, -1.436860, 0.417650, 0.238270, -0.196260, 0.213210, 0.698720, -0.991410, -0.237360,
-0.341440, 0.752830, 0.620090, -0.917380, 0.505420, 0.664940, -0.990860, 0.768980, 0.320270, 0.401870,
-1.112930, 0.797570, -0.579270, -0.373260, 0.284840, 0.361510, 1.201940, 0.175450, 0.660470, 0.160720,
-0.317270, -0.007950, -0.528000, 0.982000, 0.257580, 0.766500, 0.659900, -0.085870, 0.934460, -2.343270,
0.959530, 1.053100, 0.114240, 0.588300, 0.393980, 0.775020, 0.613550, -0.435420, 0.121250, -0.312960,
-1.233080, 0.542260, -0.348450, 0.232760, -2.370640, -0.872730, -0.135920, -0.712970, 0.006750, 0.167880,
-2.017240, -0.492310, 0.503840, 0.482680, 0.023560, 2.818640, 1.078540, 1.694340, -0.078490, -0.092490,
-0.533510, 0.169530, -1.114410, -0.299440, 0.851280, -1.739850, 1.015040, -0.757420, -0.521590, 0.097240,
-0.143890, 0.952720, 0.762110, -0.838570, -0.627760, 0.676630, -0.942200, 0.751210, 0.199220, 0.323470,
0.328920, 0.398460, -0.116410, 0.284710, 0.039410, -0.029960, -0.035590, -0.956960, -0.899680, -0.933590,
0.507050, -0.346710, 0.019760, 0.491820, 0.510320, -0.138390, 0.835800, 0.910090, -0.699230,
-0.165020, 0.206200, 0.266750, 0.535480, 0.031110, 1.358500, 2.147440, -0.949330, -1.075170, 0.544710,
0.319220, 0.852700, -1.387170, -3.009230, 2.120080, 1.092880, 0.627070, 2.069700, 0.526540, -0.089940,
-2.763280, 0.344270, -2.427720, 0.585860, -0.579420, -0.215240, 0.168080, -1.129360, 0.217940, 0.106110,
-0.880810, 0.585570, 3.682870, 0.859300, 1.642540, -2.696950, 0.850480, 0.595640, 2.001100, -0.244040,
3.560600, 0.557600, 0.746860, -3.716720, -1.014710, -1.136840, 0.155360, 1.418600, 0.959160, -2.017470,
-1.625920, 0.331120, -0.885600, 0.296040, -0.069040, 1.314850, -0.699460, 0.640110, -0.725420, -0.840690,
0.458950, -0.356110, -0.385400, 1.584030, -0.171600, 0.696260, -0.584050, 0.141230, -1.150630, 1.063960,
2.795670, 0.394150, -0.732470, 0.582360, 0.951340, 0.187270, 0.886930, 1.905180, -1.204140, 0.446730,
1.447260, 2.768620, 1.248700, -0.904650, -0.376220, -0.673130, 0.239040, 0.599690, -0.350950, -0.915540,
-0.768480, 0.638910, 0.115380, 0.576300, -0.621560, -0.345890, -0.550900, 1.912110, 0.745760, 1.108080,
-0.407110, 0.607230, -0.918180, -0.349390, -0.571120, -0.001640, -0.999790, 0.482970, 0.360850, 0.441220,
-0.669950, 1.197030, -0.842690, -0.434860, 0.705880, 2.367890, 0.710140, 0.409540, -4.053990, 3.026230,
1.517100, -1.092070, 1.148020, 1.638960, 3.963470, -1.351860, -0.831300, -0.997140, -1.222450, -0.301110,
0.153680, -1.733760, 3.798130, 0.174260, -0.649830, 14.828240, 2.319700, -0.902700, 0.176930, -0.603830,
-0.046230, 0.776700, 1.512150, -0.420700, -0.315500, -0.163360, -1.064230, -0.095710, 0.626770, 1.266450,
0.426050, -0.740440, -0.182760, 0.470230, 0.412930, 0.387650, 0.808220, -1.105300, 0.671010, -0.432950,
-0.081280, -0.136460, 2.630330, 0.403760, -1.237450, -2.075970, 0.499920, -0.128660, 1.566230, 1.656000,
0.896310, -0.430830, 0.837080, 0.085590, 1.189370, -0.489970, 0.527260, -0.339260, 2.478790, 0.948340,
0.335180, -2.722770, 0.021030, -1.538940, 0.085930, 3.236950, 2.944100, -1.220180, 1.102980, -0.040140,
0.107660, -0.347910, 0.041450, 0.911870, 1.123310, 0.068020, 0.472160, 0.499760, -1.707670, 0.124160,
0.076840, 2.628900, -0.860020, 0.107530, -0.471830, -0.707530, 0.164700, 0.189720, 1.222450, 0.190750,
-0.569950, -1.421870, 0.157450, -0.656330, 0.070420, -0.509020, -0.519860, 0.274930, -0.654910, 0.048020,
-0.348070, 0.322760, 0.041820, 0.584360, 1.807460, -0.223940, -0.371940, -1.837230, 0.057800, -0.757030,
-1.028140, -0.740070, -0.498710, 0.338250, -0.029420, 1.643360, -2.268040, 0.185000, -0.775720, 0.000490,
0.288420, 0.677650, 0.356460, -1.379640, -0.673800, -0.215360, 0.446670, -0.119000, -0.654180, 0.570020,
-0.969940, 1.380680, 0.693100, 0.367110, 0.249840, 0.099650, -0.069070, 0.023600, -0.483160, 0.542260,
0.765440, -0.285190, -1.752640, -1.803620, 1.057570, -0.377690, 1.050440, -0.980050, 0.140580, -0.636420,
-0.302600, -0.806450, -0.367200, -0.360280, -0.790070, 0.593480, -0.298170, -0.878910, 0.210940, 0.078710,
0.387190, -0.351250, -0.161750, -0.391610, -1.430840, 2.299610, 0.379010, -0.794600, 0.359770, 0.632870,
-0.635090, 0.833700, -1.285760, -0.735590, -0.131370, 0.075860, 0.267080, -0.710910, 0.754700,
-0.910670, -1.246640, -0.507350, 0.823590, 1.257790, 0.368220, -0.408620, 1.448570, -0.623190, 0.505800,
0.316470, 0.552030, -0.440950, -1.858670, -0.699640, 1.251860, -3.676800, 2.027900, 0.646110, -3.325860,
0.622580, -1.164270, 0.277810, 1.051790, 0.892720, -0.382430, -1.350610, -0.779580, 2.007420, -0.928560,
-0.646090, -0.237990, -0.294300, -0.111830, -0.707600, -0.427390, -1.551440, 0.856940, -0.839520, 0.659540,
-0.425460, -0.623210, -0.194440, 0.597260, 0.406540, -0.222050, 2.304020, 0.658780, -0.234540, 0.054550,
1.121510, 0.583920, -0.955350, -0.329250, 0.743220, 1.777830, -1.488530, -1.612760, 0.871530, -0.521480,
-0.023940, 0.763560, -1.053890, 0.207140, -0.117730, -0.789310, 0.799080, -0.214980, -0.056630, -1.092500,
1.171430, 0.723010, 0.353760, -1.063280, 0.640320, -0.458200, 3.140790, 0.908540, -0.849680, 0.557720,
0.568330, -0.701070, -3.163260, 0.331230, -0.599860, -0.757710, 0.504170, 0.316560, 0.798770, -0.295290,
-0.582690, -0.023200, 0.221180, 0.971460, -0.612170, 0.132840, 0.018480, -0.382660, -0.142520, -1.110150,
0.141500, 0.814990, 0.925370, -1.035340, -0.755650, 0.071560, 0.685760, -0.736240, 1.015540, 0.467750,
-0.006030, 0.390510, 1.122850, 0.708780, 0.718350, -1.634730, 2.103510, 0.572440, -0.497720, 10.748740,
1.209040, -4.013910, 0.365090, 7.016700, 3.202670, -0.603620, 0.460020, 0.702560, 1.777380, -1.639530,
2.391710, -0.274390, 21.706141, -0.537520, -1.872310, 0.818660, 5.944780, -0.635940, 0.820970, -2.155100,
1.119780, 0.622010, 0.388580, -2.016590, 0.695140, -0.569340, 0.591520, 0.785880, 1.371130, -0.553360,
-1.487840, 1.343320, -0.379770, -0.975130, -0.956200, 0.011540, 0.020720, 0.276120, 1.010570, 1.070030,
0.115520, 0.061330, 1.596170, 1.586940, 1.632100, -0.046900, 0.735730, 0.099480, -0.588160, -0.262930,
0.678680, -3.144870, -0.169100, 1.625450, -0.825620, -0.409420, 0.155510, -5.092520, -0.112090, -0.981480,
-0.784360, 0.171000, -0.081050, 0.287010, 1.243060, 0.571090, -0.254930, 1.781710, -0.042980, 0.404880,
0.028720, 0.272760, 0.459600, 0.996740, 1.334820, -0.097650, -1.373280, -0.455720, -0.422280, 0.436840,
-0.735000, 0.778500, -3.505860, -0.244540, 1.422240, 1.918100, 0.014990, 0.457510, -0.736240, 0.149810,
0.396770, 0.582050, 0.439510, 0.515750, 0.243520, 1.367430, 0.752490, 0.035990, 1.123220, 0.741790,
-2.207900, 0.483540, 0.931920, 0.288820, 0.956230, 0.364260, -0.103740, 1.052930, -0.303430, 0.098340,
-0.686570, 0.829340, -0.446180, -1.104330, 0.616560, 1.480030, 0.715630, 0.272590, -0.166990, -1.964340,
-0.869830, 0.918850, 0.178240, 0.481920, 1.200900, 1.764670, -0.969570, 1.148240, -1.605400, -1.137910,
-1.286900, -0.622030, -0.020150, -0.148310, -0.099310, 0.542450, -0.012630, -0.360220, -0.233100, -0.836750,
-0.446480, 0.425780, -3.236990, -0.996000, 1.521420, -3.711630, 1.316310, -0.220180, -0.158670, 0.716950,
-0.551440, -0.686020, 0.724030, 0.903740, -0.077910, -0.030500, 0.117060, 0.172500, 0.060160, -0.951680,
0.227370, 0.906740, 0.642970, 0.399540, -0.231500, 1.855070, -1.249710, -0.322580, 0.123910, -0.848860,
-0.992810, 0.344320, -1.303020, -0.290680, 0.728770, -0.580300, 1.397360, 0.769840, 0.555820,
0.264710, -0.470310, 0.183240, -1.269120, -1.845990, -0.585830, -0.550580, 0.203340, -0.495920, -0.547260,
-0.004710, 0.108530, 1.184910, -0.736350, 1.678140, 0.360020, 0.323920, -0.194480, -0.341010, 0.051520,
-0.789520, 1.029520, 0.408110, 1.016870, 1.126330, -0.484490, 0.570440, 0.114020, 0.032340, 1.121800,
-0.653990, 0.827620, 0.853890, -0.418290, -0.800040, -0.048600, -0.082450, -0.984300, -0.406130, -0.738920,
0.199080, 0.039600, 0.721580, 0.424520, 0.506450, 0.230400, -0.320870, -1.159500, 1.488340, 1.155510,
0.907650, 1.094690, -1.165650, -0.143260, 1.111370, 1.635340, -1.969960, -0.419190, -1.679180, -0.992880,
0.202460, -4.803930, -1.001690, 1.725370, -0.278730, 1.215530, -1.459320, 1.602160, -0.120570, -1.120000,
-0.791420, -1.142620, -1.325040, 0.775770, -1.838590, 0.501800, 0.059360, -1.103570, -1.289470, 0.071510,
-0.713930, 0.905750, -0.185750, -0.411910, -0.300670, -0.251560, -2.600310, 0.105550, 0.711730, -1.561260,
0.801940, -0.520070, -0.798040, -0.315610, -0.253220, 0.301560, -0.448810, 0.674840, -0.231910, 0.630100,
1.146140, 0.403490, -1.162520, 0.568980, -1.054510, -0.907620, 0.910670, 0.563920, -0.928320, -0.380040,
-1.115000, -0.882370, -0.388310, -0.273050, -0.147610, -0.206840, -0.097440, 0.448410, 0.544100, -0.692950,
1.672440, 1.139960, -0.832340, 0.019620, -0.257690, 0.600200, -1.538810, 0.899040, -0.005180, 1.093470,
-1.880390, -0.453720, 0.483900, 0.350410, 2.260380, 0.155190, -0.102740, 0.695210, 1.869050, 0.154660,
0.891460, -0.837890, -0.018630, 1.378790, 0.306100, 0.499750, 1.204460, 0.776090, -2.458640, -0.776820,
-0.825670, 1.729060, -1.295030, 0.656910, -1.249000, 2.776000, -0.979980, 0.687740, 0.699620, -0.332000,
-0.768780, 0.485200, 0.158580, 0.383560, 0.761120, -0.482430, 0.235460, 2.033250, 0.024900, -0.783600,
1.353490, -0.662710, 0.420970, -0.563950, 0.605500, 1.424820, -0.565370, 0.716700, -0.104860, -0.086210,
0.671560, -2.402900, 0.878240, 0.162550, 1.837110, 0.143720, 1.148760, -0.769420, -0.089650, 4.281860,
0.713120, 0.119920, 0.977340, -0.528690, -1.391190, 0.263480, 0.125140, 1.897260, 0.423060, -1.220940,
-1.349240, -0.547820, -1.280630, 1.184580, -0.317540, -2.214300, -0.420010, 0.946940, 0.132990, 0.201010,
-1.758560, 0.233320, -0.282110, -0.066760, -1.339570, 0.742630, 1.225560, -1.634600, -0.615630, -0.192260,
-1.055840, 0.242570, -0.797620, -0.809420, 0.771670, -0.733770, 0.103400, -1.148050, 0.211750, -1.086010,
0.845670, -0.204210, 0.569070, 0.000510, -0.176890, 0.741460, -1.104750, 0.501980, 0.071960, 0.152920,
-0.764360, 0.802080, -0.220030, -0.859530, 0.619470, 0.036080, -0.507840, -0.013400, -1.174320, 0.451940,
-1.182730, -0.587950, 0.214340, 7.235790, -0.493700, -0.566230, 0.306500, -2.385000, -1.803500, -1.095320,
-0.442800, -0.885010, -3.230270, -0.901940, 2.226460, 0.648380, 0.166680, -0.218790, 0.283040, -0.702010,
0.138840, 0.036290, 0.352860, -0.118790, -1.073100, -1.110720, -0.418980, -0.684040, -1.566250, -1.617650,
-0.272110, -0.767000, -0.305710, -1.664230, -2.955600, -1.359510, -1.073620, -0.210590, -0.491070, 0.098790,
0.567710, -0.493660, -4.746450, -1.477590, 0.248910, -0.359810, 0.361160, -0.712680, -1.324010,
-0.772620, 1.348860, -0.688080, -0.739710, -0.055310, 0.551110, -0.270590, 0.154450, -1.220850, -0.129850,
0.707730, 0.834830, 1.282560, -0.965930, 0.615910, -0.006780, -0.403840, 0.085650, 2.231960, 0.229880,
1.145990, 0.451310, 1.260600, -0.405590, -0.276990, 0.501670, 0.300540, -0.440020, 0.789720, 1.540700,
-1.866350, -0.177670, -0.890260, -1.083230, -0.167880, 0.067820, 0.440350, -0.404890, -1.228040, -1.217480,
0.926190, -0.737510, -0.201860, 0.905800, -0.608320, -0.663280, 0.687640, 0.965680, 0.753110, 0.136510,
0.352110, -0.236750, -1.341250, 0.480120, -0.830110, 0.150650, 1.448510, -0.965530, -0.410330, -1.106600,
0.181080, -0.861280, 0.194940, -0.140240, 0.779940, 0.850790, 0.827630, -1.797280, 0.555260, 0.536960,
-0.700750, -0.069110, 0.378960, -0.344580, 0.839830, 0.655350, 0.132050, 1.074870, -3.214280, 0.359620,
0.359810, 0.051390, -1.360410, -0.064960, 1.374230, -1.101760, -1.471910, -0.716830, 0.160220, -1.155060,
0.714660, 0.670720, -0.057560, 0.984390, -0.145440, 1.345640, 0.273850, 1.750350, -1.284940, -0.047600,
1.387810, 0.788920, -0.527900, 0.104410, -0.144980, -0.135540, 0.200630, 0.312790, 0.178460, 2.428930,
0.490940, 1.361520, -0.086250, 0.316760, -0.518010, 0.255030, 2.287870, 0.645230, -0.317710, 0.641330,
0.164580, -0.267110, 0.128280, 0.226030, 1.993350, -0.974340, -0.526770, -0.353010, 1.129890, 0.527910,
-0.092380, -0.285690, 3.034260, -0.458340, 0.287860, 1.238320, 0.296390, -0.802740, 1.532860, -2.280450,
1.453340, -0.030400, 0.653490, -0.068310, -2.294390, -0.351600, 1.400320, 0.377310, 0.796400, 1.544830,
0.073940, 1.402300, 0.074790, -0.080200, 1.202790, 1.873020, 3.943920, -0.091820, 0.092520, 0.160550,
-1.459340, 0.375310, 0.771080, -1.008420, -1.058150, -0.021410, 0.498390, -0.200720, -0.375520, -0.201910,
1.147100, 0.187860, -0.102070, 0.066110, 1.270480, -0.481060, 1.612220, -0.151620, 1.781150, 0.423650,
-0.358110, -0.321350, 0.803590, 0.472090, -0.127210, 0.781690, 0.610530, -0.053630, -0.300490, -0.916090,
-0.797650, -1.578690, -0.281880, 1.461710, 0.981380, 0.739940, -1.265650, 0.452560, 0.399480, -1.198350,
0.352820, 1.528090, -0.351620, -1.604070, 0.997120, 1.488290, -0.229640, 1.325140, -1.089050, -0.314930,
-0.769860, 1.933700, 0.440790, -0.761930, -0.126750, -0.191110, 0.369600, 0.021620, 1.217880, -0.347430,
1.014410, 1.118310, 0.719460, 0.617090, 1.067360, -1.743520, -1.217990, -0.329870, 0.284170, -0.625550,
-0.469360, -0.791040, 0.313330, -0.839150, -1.173310, 0.367280, -0.030820, -0.884880, 0.492240, -0.884610,
0.555560, -0.065340, 1.636800, -0.194120, -1.416380, 0.122990, -0.098060, -0.289050, 0.749360, 0.208640,
-0.334130, -0.483060, -0.001770, -0.697080, -0.391430, -0.961980, 0.526610, 0.036780, 0.311610, -0.816550,
0.359350, -0.629930, -2.767310, -1.314640, 1.712990, 0.064430, 0.101500, 0.221560, 0.792910, 0.263370,
-0.328650, 0.079190, -0.496700, -0.693570, -0.251180, -0.999120, -1.357080, -0.368740, 0.398300, -0.795990,
-1.400650, -1.141670, -1.642530, -0.350830, -1.493630, 1.403790, -0.434890, -1.835430, -0.392520, -0.820120,
-0.841140, -1.179730, -2.474610, 0.259310, 0.222030, -0.826620, -0.949460, 0.310550, -1.381580,
-0.697270, 0.846280, -0.971480, -0.257120, -0.210500, 0.289290, -0.307090, -0.315400, 0.034140, -0.900350,
-0.378620, 0.314460, -0.397250, -0.693990, -0.017040, 0.580860, 1.501120, -0.626870, 0.220580, 0.624640,
-0.028300, 0.088040, -0.042020, 0.251470, 0.148110, 0.722280, 0.629610, 0.849440, -0.519520, 0.641110,
0.482710, 0.155980, -0.342520, -0.502950, -0.280410, -0.523490, 0.615270, 1.074580, 0.629860, 0.191470,
0.319860, -0.092600, -0.033330, 0.109650, -0.585710, -0.380400, -0.468600, 0.483800, 0.949790, -0.423350,
-0.774530, 0.734700, 0.963060, -0.859320, 0.234040, 0.396880, 0.291320, -0.673270, 0.058350, 0.330660,

0.317490, 0.790950, 0.082800, 0.177030, -0.414830, 0.169100, 0.075970, 1.004220, -0.704080, 0.115200,
1.298620, 0.924520, 0.477140, -0.117380, 0.726050, -0.709620, -0.415600, -0.221880, -0.183060, 0.030410,
0.764860, -0.122460, -0.723740, -1.048550, 0.537150, -0.287850, 0.795550, 0.651300, -0.107540, 0.468950,
0.894230, -0.452130, 1.010870, -0.954810, 0.659390, 0.905630, 0.624280, -0.390980, -0.146480, -0.138520,
0.436140, -0.348440, 0.922250, 0.305520, -0.681350, 0.761530, -0.699610, -0.464470, -0.276020, -0.766430,
0.928380, 0.323710, 0.940480, 0.494710, 0.403530, -0.346640, 0.700070, -0.676590, -0.898580, 0.785190,

0.612370, -0.827240, -0.698550, 0.705790, -0.759820, 0.888020, 0.758990, -0.206390, 0.155710, 0.631540,
0.100930, 0.475550, 0.945120, 0.247220, -0.810510, -0.106430, 0.491250, -0.417450, -0.745830, 0.946970,
0.422760, -0.289150, -0.536250, -0.746310, 0.646110, 0.775350, 0.833910, -0.525930, 0.991550, 0.433520,
-0.762760, -0.808020, 0.221010, -0.566870, 0.658870, -0.094830, 0.375400, 1.334760, 0.873200, 0.831580,
0.219130, -0.254440, -0.990920, -0.698150, 0.125490, -0.672940, -0.598650, 0.956240, 0.785230, -0.047190,
-0.579820, -0.818010, 0.759830, 1.151310, -0.747670, -0.005640, -0.596470, 1.131340, -0.025480, -0.445240,

-0.662000, 0.423390, 0.650860, -0.939480, -0.712850, 0.562560, 1.597970, 0.107860, 0.281550, -0.325840,
5.966420, 0.240830, 0.497780, 0.850880, -0.663040, -1.254730, -0.746340, 0.680010, -0.426550, 0.573470,
0.700100, -0.327780, 0.325470, -0.507930, 0.423730, 0.871780, -0.591740, -0.083800, -1.125240, 0.557070,
0.491540, 0.663190, 0.929030, -0.269180, -0.105640, -0.461830, 0.976010, 0.722490, 0.395370, 0.939230,
-0.787810, 3.080780, -0.507370, 0.175920, 2.461230, -0.095380, -0.333630, -0.650450, -0.515900, -0.329420,
-0.681120, -0.411210, -0.801280, 0.688320, 0.917200, 0.538130, -0.170350, 0.533680, 0.984520, 0.170970,

-0.302850, -0.960020, 0.228210, -0.424300, -0.709790, 0.412950, 0.934090, 0.888100, 0.211130, -0.285170,
1.296630, 0.696360, -0.812780, -0.334260, -0.815120, -0.182030, -0.270110, 0.135230, 0.500750, -0.885980,
0.544190, 0.478070, -0.714620, -0.920810, 0.896510, 0.708610, -1.005910, 0.501280, -1.042000, 0.857860,
0.379690, 0.742740, -0.793470, -0.135980, 0.882880, 0.154800, 0.231750, 0.493110, 0.628050, 0.336750,
0.649210, 0.507620, -0.175680, -0.460940, -0.795960, -0.975720, -1.025710, 0.826050, 0.821670, 0.384590,
0.362510, 0.881720, 0.384600, -0.812080, 0.004580, 0.255970, 0.096390, 0.434430, -0.443780, -0.465990,

-0.845800, 0.125040, 0.969290, -0.855020, -0.474970, -0.544530, -0.277730, -0.057140, -0.058950, 0.562530,
0.111750, -0.409170, -0.931410, -0.116380, 0.554810, -1.593360, 0.976650, -0.581660, 0.265040, 0.241680,
0.991550, -1.009350, -0.083270, -0.503280, 0.677650, 0.901770, -0.605910, -0.585930, 0.393080, 0.808140,
-0.689070, -0.341380, 0.524070, -0.314230, -0.368200, 0.548140, 0.084330, -0.163890, 0.382360, 0.329670,
0.909340, -0.391630, 0.839220, 0.433140, 0.768360, -0.297580, 0.731140, 0.118370, 0.190970, -0.852150,
0.325630, -0.687280, 0.683230, 0.859510, 0.697060, -0.270080, -0.490120, 1.273670, -0.498310, 0.672410,

-0.729510, 0.234190, -0.175180, -0.286980, -0.023310, -0.305290, 0.759120, 0.459970, -0.917540, -0.979340,
0.791790, -0.052600, -0.574470, -2.081050, -2.435110, 0.323950, -0.117130, 0.267990, -0.956190, -0.933370,
0.389930, -0.174900, 0.799190, -0.390140, -0.204030, -0.084540, 0.563680, 0.752020, -0.872050, 0.004880,
-0.667500, -1.639220, -0.749090, 0.551280, -0.145230, -0.756640, 0.439060, -0.165680, -0.905810, 0.170870,
0.330970, 2.381220, 0.181380, -0.735940, -0.751650, 0.866530, -0.223230, -0.362670, -0.923700, -0.117910,
1.071180, -0.282940, -0.353490, 5.519090, 0.752390, 0.496690, -0.483850, 0.021990, 0.000460, 0.693860,

0.919640, 0.297440, 0.024350, 1.529180, 0.611060, 2.535190, -1.129130, -0.765270, -0.440670, 0.154570,
-4.070430, 1.889450, -0.015030, -0.951640, -0.598990, -3.704730, 2.435840, -0.857510, 0.086390, -0.084030,
-9.269520, 1.731820, 0.547210, -0.538440, 0.492610, -3.303140, -0.865360, -0.363730, 0.103730, 1.039580,
-0.916140, -0.440340, -0.371850, -0.065200, -0.382870, -0.118030, -1.280480, -1.843680, 0.335660, -0.270540,
0.122700, -3.223660, -0.684720, -0.857890, 0.162390, -1.134040, -0.295400, -0.239140, -0.102200, -0.826460,
-1.620080, 0.026140, -0.212090, -0.713280, -1.849970, 0.175910, -0.552810, -0.253950, -0.288700, -0.021460,

-0.057430, -0.405650, -0.269610, -0.070880, -0.756850, -0.870580, 0.691450, 0.112670, -2.610650, -0.935690,
-0.286530, -0.525770, -0.346460, -0.044360, 0.373190, -0.824100, 0.738520, -0.402650, 0.086470, -0.204050,
-0.622680, -0.283150, -0.742060, -0.929470, -0.585800, -0.442650, 0.134760, -0.677920, 0.722070, 0.763490,
0.206850, 0.313300, -0.797240, 0.296810, 0.122880, -0.380320, -0.381390, -0.237250, 0.936540, 0.324810,
-0.419060, -0.565170, -1.119850, -0.170050, 1.046790, 0.587030, -0.625070, 0.076630, 0.119720, 0.413100,
-0.567450, 0.077430, -0.460810, 0.345890, -0.848800, -0.188300, 0.614460, 0.180200, 0.101050, 0.177020,

0.796740, -0.825200, 0.413210, 0.550750, -0.067600, -0.323200, -0.761080, 0.678810, -0.487720, 0.463490,
0.102820, 0.780050, 0.780410, -0.311190, -0.467970, 0.155600, -0.679540, 0.088480, 0.354440, -0.575150,
-0.033160, 0.561000, -0.640190, -0.855580, 0.743650, 0.347510, -0.052060, -0.052490, 0.173410, 0.608290,
0.792580, -0.396520, -0.362280, 0.575530, 0.596070, 0.124660, -0.683860, -0.183840, -2.150530, -0.105470,
-0.049600, 0.806710, -1.491950, -0.297680, -0.928720, -0.023610, -0.262150, -0.772250, 0.918530, 0.528990,
-1.695690, -1.132170, 0.396400, 0.631170, -0.330160, 0.481110, -0.135360, 0.118500, 0.696700, 0.730000,

-0.950910, 0.370280, 0.655490, 0.608800, 0.276470, -0.491910, 0.969540, 0.495700, -0.301700, -0.006350,
0.004070, 0.471790, 0.730300, -1.089340, -0.253630, 0.067440, -0.468310, 0.895650, 0.923290, -0.238940,
0.015860, 0.396820, -0.796710, -0.393000, -0.202210, -0.489300, -0.263780, -0.220460, -0.464900, -0.026380,
0.608960, 0.425700, 0.950530, -0.789220, -0.441970, -0.345180, 0.801290, 0.642940, 0.904510, -0.530690,
-0.860810, -3.157180, -0.587680, 0.150480, 0.209790, -0.938830, -0.367980, 0.114660, 0.511870, -0.640840,
0.138330, 0.824050, -0.650660, -0.798540, -0.548490, -0.100450, -0.663440, 0.443130, 0.590480, -0.906220,

0.498380, -1.303530, -0.423410, -2.332330, 0.240810, 0.555900, -0.611600, -0.677890, 0.529450, -6.270850,
0.457090, -1.914390, -0.142330, -0.151170, 0.601170, 0.290650, -2.671720, 0.660310, 0.950220, -0.348030,
-1.069880, -0.876370, -0.234310, 0.764240, 0.907620, -0.342980, 0.273210, -0.607410, -1.363970, -0.044570,
-1.578350, -0.612910, -0.501330, -0.389180, -0.886810, -0.596990, 0.988930, -0.943260, 1.075400, -0.509720,
-1.246310, 2.543910, -1.870220, -1.033070, -1.601840, -0.042640, 0.423800, 0.375690, 0.800760, 0.726980,
-0.899910, 0.422960, 0.624110, 1.580040, 0.963630, -1.832190, -0.404400, 0.636830, -0.070440, 0.240600,

0.876710, 0.398950, 0.474000, 0.922420, -0.908240, 0.456830, -1.475370, -0.852440, 0.745850, -0.761600,
0.056570, -0.858200, -0.416530, 0.823960, -0.622820, -1.007980, 1.734000, 0.045140, -0.939160, 0.975950,
0.094070, 0.758150, -0.662720, 1.109820, -0.937030, 0.172480, -0.478650, -0.469280, -0.470640, -1.418170,
-0.813360, -0.555100, 0.447640, -0.771380, 0.424250, 0.293740, 0.941800, -0.205020, -0.196880, 0.830570,
0.897840, -0.524710, -0.658800, 0.531750, -0.858860, -0.137730, -0.829600, -0.586610, 0.177060, -0.897530,
-0.697650, -0.709830, -0.057140, 1.240090, 0.619480, 0.642850, -0.108280, 0.105370, -0.381300, 0.134610,

0.863560, 0.075320, -0.393750, 0.186740, -0.225180, -0.602320, 0.149420, 1.004660, 0.057250, 0.860010,
0.556840, -0.089270, 0.138840, -0.776080, 0.860560, -0.291250, -0.559060, -0.121290, 0.751770, 0.255280,
-0.392010, 0.483330, 0.784790, -0.266450, -0.713470, 0.801240, 0.771300, -0.756210, -0.532270, -0.509570,
0.472460, -0.545470, -0.341050, 0.940240, 0.459900, -0.540000, 0.402310, -0.023180, -0.419000, -0.741310,
0.896530, 2.352620, 0.245030, 0.249680, -0.875150, -0.363290, 0.606150, -0.898050, -0.102400, -0.711220,
-0.735950, 0.178390, -0.970630, -0.626620, -0.826010, -0.030870, 0.462830, 0.215880, 0.776020, -0.628750,

0.873790, -0.981570, 0.428900, 0.257860, 0.175440, -0.929630, -0.654140, -0.209720, -0.053720, 0.453320,
0.252020, -0.189650, 0.184200, -0.259600, -2.229750, 1.199000, 0.164360, -1.473940, 0.296510, 0.741890,
-1.755850, -0.739980, -0.791230, 0.196040, 0.157680, 0.972140, -0.408590, -0.385680, 0.598770, -0.443620,
0.013980, 0.020270, -0.110550, 0.866410, 0.729200, 0.395930, 0.525770, -0.083560, 0.324350, -0.830440,
0.367540, 0.331430, -0.890710, -0.963430, 0.268570, 0.568670, 0.307680, -0.983060, 0.830600, -0.851140,
1.659950, 1.210200, 0.223510, -0.649590, -0.868910, 0.681940, -0.931040, -1.142960, -0.395840, -0.860950,

0.614650, -0.741890, 0.708650, 0.864780, -0.066380, -0.644350, -0.004410, -0.598300, 0.535820, -0.036260,
0.622750, 0.229340, -0.763040, 0.827200, -0.611270, -0.322660, 0.154320, -0.370950, 0.760800, 1.001580,
-0.596670, 0.578820, -0.779030, 0.043530, -0.202290, -0.680570, 0.315340, -0.012570, 0.420780, 0.524200,
-0.839610, 0.367710, -0.316720, -0.481610, -0.955230, 0.662410, 0.331510, -0.308240, -0.330700, -0.177130,
-0.673440, 0.653690, -0.818310, -0.928280, -0.260920, 0.606540, 0.091840, 0.377650, 0.545300, -0.102960,
-0.069020, 0.754660, 0.387440, 0.653190, -0.654100, -0.749740, -0.682200, 0.973140, 0.229560, -0.624340,

-0.874790, -0.049460, -0.489350, -0.372450, 0.272400, 0.321220, 0.291330, -0.448360, -2.084960, -0.951970,
0.304810, 0.421610, -0.860400, 0.328670, 0.585360, -0.335000, -0.878280, 0.276080, -0.218050, -0.439780,
-0.217770, 0.272290, 0.235310, -0.031730, -0.103550, 0.581370, 0.354830, 0.910140, 0.525270, -0.298760,
0.688470, -0.522070, 0.508430, -0.046160, 0.196390, 0.194070, 0.900110, 1.716590, -0.328180, 0.044540,
0.623580, 0.793770, -0.625990, -0.659160, 0.235410, -0.189670, -0.108260, 0.459050, -0.567970, 0.789540,
0.327980, 0.663850, 0.926200, -1.320210, -1.803340, 0.070770, -0.146920, -0.448060, 0.970810, 0.974440,

0.820900, -0.450690, -0.074910, -0.316280, 0.525200, -0.869070, 1.626180, 0.955600, 0.122940, 0.216550,
0.886610, 0.140270, 0.674300, 0.215060, 0.747090, -0.346320, -0.281690, 0.115870, 2.559720, -1.091870,
1.143550, 0.070190, -0.286930, 0.020510, 0.435880, 0.809990, 0.863620, 0.143200, 0.303000, -0.610890,
0.635630, 0.055250, -0.706680, -0.102650, 0.977260, -0.964040, 0.553960, -0.621020, -0.362880, 0.455510,
0.081570, 0.731190, -0.007680, -0.947810, 0.238330, 0.822240, -0.263970, -0.924550, -0.657390, -0.561540,
0.127240, 0.070560, -0.435040, 0.780290, 0.687370, -0.402800, 0.505590, 0.811430, -0.041010, 0.107490,

0.502290, -0.386920, 0.968640, 0.194900, 0.504010, -0.057070, -0.679910, -0.675810, 0.601590, 0.090850,
-0.349680, -0.200980, 0.280300, 0.599560, 0.753260, 0.363920, 0.520090, -0.182390, -0.532140, 0.418330,
-0.534570, -0.017610, -0.799060, 0.568550, 0.084080, -0.329240, 0.751150, 0.475450, -1.036520, -0.533210,
0.071380, -0.382810, 0.835850, 0.165780, -0.294410, -0.408880, 0.520550, -0.247250, -0.968050, 0.037710,
0.770190, 0.574550, -0.929500, -0.131900, -0.826450, -0.882780, 0.125030, -0.890750, -0.307300, 0.620090,
0.950200, 0.152040, 0.323840, -0.788780, -0.033710, 0.694620, -0.497240, 0.159310, -0.925880, 0.750910,

0.502290, 0.576670, 0.857320, -0.908340, -0.773430, 1.537330, -0.144470, 0.834960, -0.028470, -0.238310,
0.062930, 0.824600, 0.732000, 1.316990, -0.616020, -1.036330, -0.945190, 0.773420, 0.581170, 0.396100,
0.088460, 1.047510, 0.512740, -0.411760, 0.921500, -1.376740, 0.492050, -0.443550, 0.675100, -0.952510,
-0.744350, -0.074390, 0.991460, 0.494710, -0.698070, 0.015200, 0.836030, 0.013430, 0.058630, 0.286640,
0.956860, 0.631310, -0.350380, -0.642200, -0.113600, -0.140400, -0.707720, 0.825190, 0.725860, -0.840200,
-0.306060, 0.772740, -0.506060, 0.432220, -0.534030, -0.132400, 0.699830, -1.088310, 0.322380, 0.844890,

-0.880790, -0.484340, -0.856670, -0.153440, -0.199430, 0.213990, 0.016860, -0.953300, 0.170230, -0.516940,
0.267540, 0.291800, -0.695320, -0.714410, -0.269450, 0.931170, 0.108910, 0.580360, -0.334100, 0.001360,
-0.059530, 0.664430, -0.548700, 0.734530, 0.819170, -0.229110, 0.269010, -0.124400, -0.768310, 0.532460,
-0.010610, -0.300960, -0.588860, -0.275940, 0.770060, -0.322250, 0.110630, -0.851840, 0.127250, 0.604950,
1.487980, -3.534120, 0.418360, 0.276440, -0.358980, 0.331970, 0.344550, -0.695640, -0.713480, -0.025220,
-0.150740, 0.217340, 0.269930, 0.686190, -0.881750, -0.528020, 0.477700, -0.165800, -0.826390, -0.028470,

-0.784240, 0.118320, 0.904830, 0.129630, -0.076900, 1.002180, -0.346610, -0.328330, 0.303930, -0.345840,
0.238660, -0.631040, 0.210680, 0.159500, -1.109240, 0.736110, -0.402750, -0.140170, 0.046710, -0.167120,
0.256020, 0.842700, -0.940890, 0.155100, 0.421570, 0.693720, -0.386420, 0.036600, 0.224530, -0.549820,
-0.512090, -0.818360, 0.211900, -0.455830, 0.631880, 0.143500, -0.650180, -0.331820, 0.137490, -0.598950,
0.970170, -0.972610, 0.217020, 0.191180, -0.441350, -0.493860, -0.521240, 0.654200, 0.307140, -0.741800,
-0.480280, 1.107520, 0.390400, -0.772550, 0.718640, 0.174660, 0.376860, -0.422230, -0.611510, 0.686590,

-0.480010, 0.012530, -0.460170, -0.049080, 0.413490, -0.496700, -0.297460, 0.175470, 0.058350, 0.994780,
0.472420, 1.164480, -0.237620, -1.236730, 0.136840, 1.483640, -1.830940, 0.723800, 0.329640, -0.226790,
-0.094260, -0.729840, 0.117910, 37.159050, -0.048130, 0.303020, 0.470270, 0.052740, -1.017540, 0.432410,
-0.650610, -0.281290, 0.935750, -0.086270, -0.607860, 0.049690, 0.924080, -4.790650, -0.688190, -0.255110,
0.296390, 1.019270, -0.417510, -0.836200, -0.121010, 0.322300, 0.850930, 1.005800, -0.883190, 0.692860,
0.827150, 0.177170, 0.124180, -0.932820, -0.792010, 0.249880, 0.891000, -0.097700, 0.361870, 0.370870,

1.004830, 0.206290, -0.332290, -0.868650, -1.033620, 0.731060, 1.512270, -0.344970, -1.245990, 0.743570,
0.746410, -0.344980, -0.878360, 0.174910, 2.088660, 0.485830, -0.618600, -0.897070, 0.767940, 4.095060,
0.623110, -0.793830, -1.010140, -0.660310, -0.586360, 0.642370, 0.407190, -0.460270, -0.437710, -1.041490,
0.380970, 0.863340, -0.688960, -0.385400, -0.754850, -0.398190, 0.707110, 1.006610, 0.378050, -0.720090,
0.580480, -1.595220, -0.421150, -0.820640, 0.904650, 1.363250, 0.251850, 0.072530, -0.923130, -0.824950,
-1.409310, 1.210490, 0.012000, -1.473950, 0.407480, 1.126920, -0.764710, 1.034300, 0.184210, 0.390160,

-0.726980, -0.363790, -0.582730, -0.112180, -0.882490, 0.823850, -0.906450, 0.113530, -0.377530, 0.922100,
1.556280, 0.133040, 0.227630, 1.254120, -0.546960, 0.589440, -0.413010, -1.324100, -0.359120, 0.704570,
-0.453910, 0.053540, -0.400020, 0.484460, 0.102800, 0.431720, -0.253410, -0.894910, 0.967890, 0.535280,
-0.931260, 0.474290, -0.244830, 0.627660, -0.273690, -0.381360, 0.022410, -0.384630, 0.293340, -0.878600,
-0.946440, 0.062190, 0.946990, -0.663330, 1.050070, 0.350380, -0.932570, -0.916830, -0.902720, -0.124570,
-0.127980, 0.739910, -0.535830, -0.809110, -0.215630, -0.974610, 0.288390, -0.994990, 0.903350, -0.508360,

-0.514730, -0.451980, 0.690910, -0.502100, -0.313600, -0.107160, -0.057530, 0.673740, 0.604910, -0.448690,
0.213930, -0.662300, 0.941020, -0.417660, -0.521470, 0.519150, -1.027200, 0.228960, -0.963530, -0.738920,
-0.547550, 0.066750, 0.311730, -0.992320, -0.449680, 0.607340, 0.569990, 0.942360, -0.354210, -0.510640,
-0.301220, -0.463780, -0.584110, 0.538310, -0.923390, -0.532920, 0.964690, 0.387030, -0.193270, 0.350560,
1.003530, -0.273550, 0.570410, -0.761480, -0.798520, 0.028560, 0.424770, 0.249210, -0.005270, 0.017730,
-0.120770, 0.228170, 0.386530, 0.500630, -0.292450, 0.606000, -0.839850, 3.862910, -0.233420, 1.051140,

0.792790, -0.525530, 0.999630, 0.515270, 1.110340, 0.120100, -0.586420, -0.340640, -0.372250, -0.666430,
0.598340, 0.884150, -0.285890, 2.257110, -0.931720, -0.707710, -0.036760, 1.291260, 1.608100, -0.252690,
0.646520, 0.480320, -1.000260, -0.860390, 0.116540, 0.875190, -0.794530, -0.915660, -0.467500, -0.723790,
0.517870, -0.400240, 0.174590, -0.144280, -0.085880, 0.687680, 0.954510, -0.043680, 1.130300, 0.536020,
-0.343800, 1.315030, 0.742510, -0.280890, 0.620330, -0.365040, -0.634000, 0.550700, 0.377990, 0.652130,
0.544420, -0.573880, -0.647480, -0.718610, 1.012990, 0.419610, 0.030210, -0.661300, -0.209520, 0.335670,

0.225570, -0.960510, -0.402720, -0.903760, 0.386930, 0.842420, -0.579340, 0.951690, -0.613910, 0.502340,
0.437550, -0.277430, -0.438270, 0.595980, 0.866360, -1.178480, 1.565640, 0.434990, -0.247290, 0.549880,
-0.108580, 0.413980, -0.212450, -0.656990, -0.724520, -0.289500, 0.026990, -0.099550, -0.457990, -0.481760,
0.078930, -0.859880, -0.836360, 0.460420, 0.713550, 0.452550, 0.148760, -0.293660, 0.182480, -0.580880,
0.654590, -6.611240, 0.204870, 0.104070, -0.616530, -0.556640, -0.925180, 0.294360, -0.253240, -0.842420,
-0.965220, -0.771060, -0.365090, -0.289650, 0.161510, -0.285620, 0.661410, 1.253310, 0.547920, 0.097490,

0.585640, -0.893630, -0.322960, 0.921570, 0.471130, -0.551650, 0.013820, 0.969310, -0.502970, -0.112980,
0.158430, 0.200720, -0.702610, 0.130110, 0.409000, 0.673660, -0.332040, -0.362250, 2.461160, -1.048220,
0.555580, -0.834470, -0.453520, 0.015810, 0.137820, 0.374330, 0.139970, -0.109010, 0.011720, -0.933010,
-0.833180, 0.838260, 0.296430, 0.178990, 0.276300, -0.577460, 0.663050, 0.147130, 0.858350, 0.392770,
0.612180, -0.289950, 11.564650, 0.946320, -0.764820, -0.984690, -0.088020, 0.844000, 0.702170, -0.691670,
0.097300, 1.036080, 0.281990, -0.704120, -0.086670, -1.170350, 0.057050, 0.372170, 0.100080, -0.098590,

0.074710, -0.959220, -0.188460, -0.733170, 0.262410, -0.191160, -0.377360, 0.741160, -0.477210, -0.928270,
0.931020, 0.894070, 0.740810, 0.517770, 0.961500, 0.966360, 0.394660, 0.113000, -0.527320, -0.977000,
0.197820, 0.167000, -0.717750, 0.530940, -0.476110, -0.511300, -0.168420, -0.614560, 0.876300, 0.920530,
0.733180, -0.178350, 0.530730, -0.434520, -0.668590, -0.882130, 0.026140, 0.044620, -0.555230, 0.699610,
0.467610, -0.826290, -1.025150, 0.518830, 0.518890, -0.452530, -0.441890, -0.050040, 0.647640, -0.951900,
-0.371930, 0.600990, -0.962100, -0.981600, -0.593570, 0.788720, 0.217490, -0.709870, 0.270980, -0.291140,

0.818420, 0.948260, 0.928420, -0.401290, -0.765170, 0.550400, -0.161370, 0.920670, -0.985950, 0.340930,
-0.286640, 1.002360, 0.267550, 0.122480, -0.089430, 0.155240, 0.429290, -0.517700, -0.390810, -0.882600,
-0.599760, -0.515300, 0.390730, 0.147030, -0.819120, 0.246160, -0.296040, 0.524190, -0.712680, 0.268360,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.375390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.322020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.242630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.254660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.069470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.878610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.012160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.693010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.006580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.558470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.573390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.472060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.601250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.875430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.710210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.898560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.050750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.396300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.963440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.873900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.974560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.223450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.078810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.279830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, -0.461170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.303850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.831110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.963970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.649000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.184500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.601880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.360240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.729110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.089010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.790960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.795610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.910410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.145260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.666560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.348030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.001150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.072820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.087930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.603940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.795820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.649520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.924760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.422720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.372050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.012950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.591010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.230660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.425330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.160440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.612150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.286330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.688270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.789630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.332410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.358480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.334220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.972180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.036530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.068880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.214880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.227820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.211070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.931970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.607610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.758240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.446660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.674550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.303710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.981430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.925200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.285890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.493660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.251930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.500200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.406400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.741830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.167590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.075530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.134160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.215140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.386660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.672410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.828230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.247370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.659040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.518990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.718070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.959670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.623150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.030510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.816350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.525270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.112310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.880050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.210790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.359280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.287000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.821500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.054530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.451010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.155700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.823550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.358060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.171260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.921140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.646500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.992630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.277440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, -0.832500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.662760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.578600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.100710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.543490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.660550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.490870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.086230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.271520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.984660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.122080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, 0.347070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, -0.151620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.253100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.737820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.790850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.852160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.100460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.328400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.485030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.652050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.164880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.920770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.745380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.631210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.642500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.673420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.133890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.749130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, 0.115590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, 0.062960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.980690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.683270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.950490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.963860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, -0.993920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.729410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.288760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, 0.706880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.667490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.424450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.512770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.640970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.427200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, -0.173370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.568020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.021230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.992180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.911300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.580590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.293800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.673980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.862520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.210550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.602400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.230190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.330490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.322050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.791430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.849260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.309780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, 0.449610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.477580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.547780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.460160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.568040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.374770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.529550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.440450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.510720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.890610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.943760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.616200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.944660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.981450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.489020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, -0.466860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.696980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.300820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.941770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.249350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.185760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, -0.621470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.552120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.859370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, 0.291420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.193010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.447230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.595850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.726330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.613860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.021670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, -0.754160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.327020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.668760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.430340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, 0.271640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, 0.034790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.958280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.172050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, -0.514920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.080970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, 0.847960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.859060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, 0.552950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.516540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.937420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.925900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.269310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.513500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.694230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.708210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.172770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.963540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.410820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, 0.112910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.379380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.458030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.160720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, 0.790690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.209780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.960290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.082540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, 0.699280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.506700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.007910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.785520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.199660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.115160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.091210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.495880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, -0.925910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.641910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, -0.635400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.124740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, -0.934780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.906900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.350910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, -0.262490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, -0.609160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, 0.003960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, -0.708860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.123170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.481240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.619890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.717280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, 0.640000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, -0.571500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, -0.946920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.644020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, -0.709940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, -0.232550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.783140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.054110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.099140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, 0.091860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, 1.764810, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, 0.901310, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.223870, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, 0.562180, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, 0.189710, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -0.005700, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, 0.521870, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.216430, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.833720, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.213940, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.235340, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.732080, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.255540, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, 0.665590, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, -1.483210, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -1.478860, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, -1.904580, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 0.870430, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -0.440990, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, -0.609170, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, -1.027810, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.512480, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.408150, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, 0.370080, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, 1.943640, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, -0.938460, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.405130, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, 0.204730, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.433360, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, -1.096850, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, 0.067040, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, -0.340440, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.072360, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.805000, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -0.107420, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, -0.152200, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.379270, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, 0.293130, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, 0.187740, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.319220, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, -0.042980, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, -0.754470, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, 0.423040, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.438430, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.726000, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, 0.243910, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, 0.966260, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.797140, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, 0.624230, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -0.468840, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, 0.422290, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, -0.253090, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, -0.532080, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, -0.413090, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, 0.907010, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.008120, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, 0.405100, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, 0.786160, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, 0.967900, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.387150, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, -0.896100, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
1.42856, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.42828, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.63696, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
1.32877, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
0.42398, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
0.00102, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
1.07125, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
1.42832, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
0.30832, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
0.10583, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.00075, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
0.41442, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
1.33750, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
0.99090, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
0.30022, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
0.30239, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.29358, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
0.41867, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
1.12529, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
0.00011, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
1.32699, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
0.02666, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
0.40595, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
0.00029, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.12857, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
0.32196, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
0.30448, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.34176, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.09243, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
0.09246, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
0.82024, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
1.33228, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
1.22701, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
1.31118, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
1.27789, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
0.42594, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
0.00074, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
0.00932, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
0.41793, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
1.37383, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.64178, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
0.00020, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.02651, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
1.09623, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
0.01562, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
0.17559, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
1.27635, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
1.41874, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
0.47685, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
1.24856, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
0.08582, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.16885, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
0.81972, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
0.10932, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.00253, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
0.27808, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
1.37060, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
0.16605, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
1.42797, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
0.48471, 0.500000, 2,
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
