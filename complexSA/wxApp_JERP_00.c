/*********************************************************
  PfamReduce_JERP_00_forceW15new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:00:12 2004
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
0.001680, 0.934040, 0.746490, 2.380500, -0.239570, -0.460820, 1.572390, -1.169820, -0.425650, 0.623100,
0.886180, -1.581480, 0.410910, -0.514030, 0.436590, -1.739670, 1.177380, 3.289300, 0.312930, -0.680610,
-0.378360, -0.509700, 0.914420, 0.439630, -0.439090, -0.372410, 1.073210, 0.703940, 0.296050, -0.780370,
-1.107890, -0.418640, 0.249940, -1.409750, 0.503640, 1.909120, -2.306250, -1.062670, -0.162600, -0.442950,
0.547020, -1.414470, 0.579250, 1.326950, 0.152030, -0.442580, -0.838510, -1.936450, -0.797430, 1.112400,
-1.250930, -0.094300, 0.567470, 0.231020, -0.767350, 0.059370, 0.398290, 0.025010, -0.095790, -2.131040,
-0.184170, 0.728150, -0.534920, 0.462880, -0.680140, 0.489560, 0.773290, 1.137970, 0.471590, 1.558640,
-1.332620, 0.799650, 0.540930, -0.040030, -0.280950, 0.345290, -0.690830, 2.994370, -0.037800, -0.067310,
-0.267000, 0.568280, -0.858690, -0.122000, 0.354690, -1.011370, 0.556170, -0.174880, -0.937890, 0.755370,
-0.730930, 2.319280, 0.865510, -0.881150, 0.572050, 0.114740, 0.682390, 1.933870, 2.754130, -0.233930,
0.078930, 0.094660, 0.641220, 0.472890, -0.186750, -0.326520, 2.229800, 1.203210, -0.779000, -0.429410,
1.011220, 0.237220, 0.599890, -0.480750, 0.353310, -0.438690, 1.420180, 0.453240, 1.153160, 0.610800,
0.511160, 1.007940, -0.324910, -0.651590, 1.292780, 0.984640, 0.598950, 0.444090, -0.241160, -0.633180,
-1.777220, 0.249730, 1.370080, -0.460260, 0.297550, 7.495400, -0.294490, 0.185910, 2.008230, 0.071210,
0.614280, 2.937880, 1.628890, -0.805140, 2.152690, -1.049290, 1.464860, 1.045730, -0.896390, 0.349770,
-1.013600, 0.507360, 0.282350, 0.620300, 0.955490, 0.656530, 0.298620, -0.777380, 0.964230, -0.998300,
-1.432990, 1.243010, 0.780020, 0.154390, -1.547680, 0.127050, 0.780310, 1.051740, -1.563510, 0.268790,
-0.279040, 0.475920, 0.806940, -0.556330, -0.791470, 0.594490, -0.364390, -1.015420, -0.022300, -0.725740,
-1.000280, -3.486350, -0.772170, -0.608370, 1.003180, 1.648770, 0.626390, -0.259490, 0.529200, 0.117490,
-0.167700, -0.390820, -0.857990, 1.374520, 0.873010, -0.970790, -0.102870, -1.918850, -0.697750, -1.432260,
-0.565080, 0.127650, 0.060500, -2.422750, 1.212830, 0.831970, 0.064930, -0.573620, 0.417450, -1.470820,
0.733860, -1.141430, -0.237900, -0.580000, 0.783760, 1.110360, 0.552270, -1.349960, -0.821710, -0.543650,
-1.205970, -0.594200, -0.426550, 2.237170, 0.362380, 0.276990, -0.417510, 1.103180, -0.808060, 0.813210,
-1.288050, 0.391160, 0.011810, 0.385570, -0.045920, -0.685520, -0.818360, 0.267400, 1.001850, 0.366350,
-1.210260, 0.166590, -1.565170, -0.614990, -1.203270, 0.053740, 0.358410, -0.277790, 0.422510, -0.086950,
-3.317410, -0.383040, -1.350040, -15.787380, 0.167810, 1.966210, -1.674940, 0.852850, 0.691180, -1.513910,
-1.821150, -1.866940, -0.595930, -0.082300, 0.264960, -3.216640, -0.229860, -0.676090, -0.388120, 0.349560,
0.089960, 0.038290, -1.753450, 0.158240, -1.021980, -1.035520, 0.053390, -0.716090, 0.378620, -0.781150,
-0.211240, 1.114590, 1.347890, -0.641460, -1.059510, 0.578890, 0.513300, 0.083020, 0.602470, -1.096710,
0.627310, -0.387000, -0.246550, -0.609970, -0.407380, 0.204500, -0.001500, 0.880610, -0.290420,
0.313120, -0.035010, -1.121830, 0.638160, 0.429900, 0.460970, -0.173110, -0.659340, 1.466490, -1.002370,
0.113360, -0.721450, 0.720570, -1.009440, -1.005190, 2.013260, 0.584790, -0.934090, 0.213790, 0.721410,
0.381970, -0.030440, 1.078110, -0.316470, 0.972430, 1.448210, 0.932540, -1.924360, -0.329110, -0.519940,
1.056380, -1.640960, -2.039060, 0.159110, -0.793590, -0.088700, 0.887930, 0.913120, -0.416040, 0.235710,
-0.736560, 0.041770, -0.989810, 1.479300, 1.574950, 0.934120, -0.769290, 1.365170, 0.067060, 1.119940,
0.140880, -0.558620, 0.207000, 0.155320, 0.440000, 0.142030, 0.741790, 1.051090, 0.494350, -0.213840,
-0.691170, -0.582020, 1.895090, -0.775300, -0.569500, 1.095480, 0.877130, 0.527780, 1.390030, -0.504070,
0.127460, 0.773740, -0.406860, -0.571490, 0.309160, -1.464980, -1.583520, -0.527140, 0.853670, -0.313960,
-0.797210, 0.935030, 1.668620, 1.245480, 0.707020, 0.180860, -0.797740, 1.184120, 2.875300, 0.327390,
2.646080, -0.470170, 0.295540, 1.003970, 0.649470, -0.557940, 0.178790, -2.050160, 0.782730, -0.268110,
0.615350, 0.185180, -0.528650, -0.230190, 1.491600, 0.790260, -0.397340, 1.578600, 0.362390, -2.716340,
0.477020, -1.565030, 2.105410, -1.063130, -0.442940, -1.084910, -0.503800, -0.349610, 2.604940, -2.179960,
-0.133170, 0.955280, -0.066290, 0.233210, -1.005200, 1.945830, 0.862240, 0.911460, 0.417580, -2.176350,
-0.396930, 1.215690, -3.889050, 0.926770, 1.220870, -2.523310, 0.940720, 0.985710, -0.843920, 0.886450,
0.153580, -0.708430, -2.300740, -0.720740, -0.181950, -0.246790, -0.496120, 0.483700, -0.484170, 0.480290,
-0.477860, 0.730980, 1.003090, -1.308730, 0.691480, -0.579260, -0.624260, -1.477510, 0.415010, 0.190530,
0.466420, -0.788050, 0.927740, -1.184860, -2.912540, -0.735170, 3.662210, 0.313650, -0.260760, -0.103240,
-1.180110, 0.924250, -0.679690, 0.637630, 0.511520, 0.411420, 0.831890, 0.382250, -0.459870, -0.594970,
-0.872300, 0.179780, -0.151360, -0.751320, -0.324430, -0.247360, -0.120630, -0.448460, 1.262700, -0.483650,
-1.574090, -2.230510, -0.007380, 0.614740, -1.848420, -1.928610, 1.000730, 2.253020, 1.258230, -0.425670,
-0.905170, -0.650860, 0.363750, -0.269240, 0.374680, -0.072040, 0.215380, 0.098010, 0.140810, -0.500660,
-0.244370, 0.186780, -0.099080, -0.141920, 1.408950, -0.940190, 0.806280, -0.730700, -0.292700, -0.281310,
1.035510, -0.200370, -0.594360, -0.741750, -0.151930, -1.062880, 0.035070, 0.000240, -0.070040, 0.057420,
-0.252450, -0.957590, -0.799430, -0.682700, -2.112490, 0.711180, 1.115980, 0.005340, -0.050810, 0.359800,
0.024270, -0.455520, -0.450790, 2.247010, 0.332250, -1.120000, -0.393530, -1.029450, 0.340500, -0.524330,
0.479660, 0.223340, 0.994090, -2.500390, 0.265210, -0.134850, -0.063490, -0.525380, -0.194140, 1.300170,
-0.680220, -0.575250, 1.957890, -0.695650, 1.097860, 2.296300, -0.002380, 0.733460, -0.235510, -1.241020,
-1.185760, -1.213370, -0.196100, 0.411340, 0.192530, 0.071940, -0.691030, -0.290450, -1.289170, 0.596840,
0.485220, 0.287260, 0.034580, -1.438080, -0.497580, -0.722120, -0.888260, -0.623590, -0.359500, -1.194350,
-1.102350, -1.645170, -1.171100, 0.027460, -0.511670, -1.283390, -0.830840, 0.479210, 0.000500,
0.170990, 2.155620, 1.133280, -0.153960, 0.365880, -0.258130, -0.143800, 1.060200, -0.373780, 1.013580,
-0.148520, 0.064030, -0.875880, -0.008810, 1.311260, -0.057060, -0.109560, 0.148670, -0.124180, 1.190070,
1.405490, -0.002640, 0.077040, 0.115830, -0.078350, 0.781790, -0.130440, -0.346160, -1.102260, -1.572250,
1.397060, 1.879270, -0.619310, -2.930600, -0.695860, 1.826320, -0.107430, 0.407930, 1.276790, 0.154900,
0.361540, -0.987670, 1.858910, 1.775600, -1.040370, 1.276600, 0.855980, -0.848380, 0.238780, -0.114570,
0.846740, 2.594040, -0.734180, 2.481350, -0.267480, -0.982830, 1.553650, 1.488800, -1.886310, 0.192350,
1.711770, 0.768360, -2.999090, 0.062000, 1.323940, -0.704930, -0.768320, -0.592500, 0.413350, 1.758050,
-0.768020, 2.217040, 0.656040, -1.029450, 0.536530, 0.911610, -0.448800, 1.268230, 3.780370, 0.083150,
0.680630, 1.090230, 0.057600, 0.976180, 1.684130, 0.004880, 1.046200, -0.161750, -0.188900, 0.245560,
-1.201610, 0.634760, 4.156350, 1.043550, -0.196490, -0.134570, -0.760220, 0.810240, -1.558700, -0.149530,
0.182410, 1.162840, -2.163230, -0.659150, -1.015440, 0.142140, 2.107550, -0.914710, -1.624880, 0.624290,
-3.703940, -0.486040, 1.008870, -0.390060, -1.027420, -0.885910, -0.234120, 0.254670, -1.061410, -0.196910,
-0.790030, 1.735650, -0.017850, -1.846990, -1.744940, 1.646260, 1.011820, -0.991940, -0.029690, 1.199280,
0.315780, 0.645920, -2.859150, 0.210210, 0.005490, -2.965400, -0.743480, -0.983200, -1.732340, 1.979190,
-0.409240, 0.612900, 0.996550, 0.716150, -1.283450, 0.743940, 0.638520, 0.448600, -0.839470, -0.734830,
-1.653310, 2.768540, -1.147420, 2.102670, 1.065520, -0.855970, -0.774340, -1.856440, 0.100840, -1.128810,
0.842310, 0.491580, 0.346660, 0.456870, -0.254450, -0.410220, 1.321970, -0.109300, -2.616040, 2.776270,
0.916200, 1.974360, -1.922310, 1.470110, -0.321930, -0.414330, 1.346910, 0.979940, 1.081920, 1.182490,
-0.070890, -0.683270, 0.805060, 0.991080, 0.294250, 0.576300, -0.846780, 0.987050, 1.044830, 1.001000,
0.323290, 0.312760, 0.005120, -0.002460, -1.390910, 1.771210, -0.135450, 0.835850, 0.580450, -0.692820,
0.775150, -0.152710, -1.378120, -0.220850, 0.114700, -1.216740, 0.331830, 1.103610, -0.150010, -1.268010,
-1.305970, -1.603220, 0.736610, 0.245950, -0.392190, -0.300030, 0.101480, -0.837150, 0.024100, 1.458500,
-1.026740, 0.293400, -1.407210, -1.043930, 1.861110, 1.012210, 1.013940, -1.076810, -0.036310, -0.192890,
0.115550, 0.007930, 2.029460, -1.276000, -1.333180, 0.141250, -0.254270, -0.372040, -0.025230, 0.412490,
0.334810, 0.501810, 0.810550, 0.031730, -0.657870, 0.715240, 0.611070, -0.835350, -1.135950, -0.736600,
-0.212020, -0.217720, 0.552300, 3.906330, -0.752080, -0.068110, 0.039620, -2.731970, 0.497820, 2.008790,
0.707530, -0.601770, -0.465460, 0.119520, 0.346130, 1.036490, -0.735710, 0.577140, 1.047810, 0.148250,
0.625560, 0.721810, 0.817510, -0.950950, 1.071480, 0.932410, -0.703000, -0.548210, -0.653800, -0.180060,
-0.233730, 0.980090, -0.849790, -0.660260, 1.202070, 0.603240, -0.713400, -0.434870, -0.341110, 0.364720,
1.145180, -1.052500, 0.461330, -0.805010, -1.082700, -0.866520, 0.820680, -0.573350, 0.145710,
0.940640, -0.658310, -1.199080, -0.163160, 0.437930, -0.465920, -0.320630, -1.234160, -0.768320, 0.391580,
0.318730, -0.274140, -0.076720, 1.280650, 0.666040, 0.005080, -1.109520, -0.445550, -0.170210, -0.791770,
1.523230, -0.023010, 0.750580, -1.627200, -0.054520, 0.335250, -0.622790, -0.604930, -0.175430, -1.304720,
-0.298370, -0.990270, -2.078350, 0.479720, -0.836270, -1.539380, -0.128170, -0.143690, -0.761660, -1.018210,
-0.627870, -0.540770, -0.781860, 0.734190, 0.761240, 0.888250, 0.873330, -0.373580, 0.052730, 0.251160,
1.199550, -0.867500, -0.656870, -1.320850, 0.601900, 0.592550, 0.722970, -0.493340, 2.162260, -0.321640,
0.542190, 0.359790, 0.420020, -0.483700, -0.390370, 0.775080, -0.040680, 2.333780, -0.295900, -0.400950,
0.012000, -0.643620, 0.174460, -1.197290, 0.374050, 1.204350, -0.603400, 1.000030, -0.810340, -0.255410,
-1.055060, 1.072040, 0.354780, 0.169220, -1.314960, -0.080970, -0.523390, -1.455800, -0.702810, 3.550300,
0.283690, 1.177590, -0.575530, -1.560360, -0.821410, 0.158310, -1.203530, -0.871400, -0.608820, 1.392590,
0.048360, 1.513640, 0.556540, 0.037510, 0.739300, 0.654590, 1.051590, 0.506550, 0.178540, 0.041990,
0.706020, -0.187300, -0.423630, 0.486010, -0.193410, -2.095350, 0.057260, -4.089090, 4.813030, -5.594380,
1.406250, 1.953070, 2.250350, -0.409950, -3.920850, 1.350130, 0.952690, -0.694550, 0.535100, -1.470640,
-0.924330, 0.333680, -1.345920, 0.269460, 0.467790, -2.014530, 2.001310, 1.417540, -0.411010, -2.610490,
-0.723460, -0.126120, 1.956350, 0.139880, 0.159150, 0.805920, 0.098770, -0.017560, 1.082000, -0.540730,
1.139770, -1.459450, 0.724630, -0.477110, -0.058340, -0.809540, 0.366710, -0.578480, 0.285160, 0.199240,
0.759280, 1.607820, -0.979730, -0.499580, 2.910210, -1.696300, -0.518440, 0.719470, -1.154680, 0.253890,
-0.703300, -0.065970, -1.322120, 0.285240, -0.067730, -1.990690, -0.836640, 1.325960, 0.958570, -0.563760,
0.566230, -0.268110, -0.012600, 0.953330, -0.028560, -0.740540, -1.003250, 0.063630, -0.620330, 0.057100,
0.266090, -0.593040, -0.493860, 0.523770, -0.120120, -0.479770, -0.003160, -1.737480, -0.596870, 1.094150,
0.124490, 0.179860, 1.441540, 0.252050, 0.657660, 0.885770, -0.794360, 1.305310, -0.676870, -0.668000,
1.336730, -1.370260, -0.761900, 0.952110, -0.105330, 0.479460, -0.062320, -1.626870, 0.755300, -0.456560,
0.951180, -0.549590, -0.114610, 0.049420, -0.777980, 0.927260, 2.516530, -1.032680, 1.009000, 1.927930,
0.437120, -1.197350, 0.292600, 0.291350, -0.195020, -0.194850, 0.186140, 1.044460, -0.368670, -0.323770,
0.196870, 0.063430, -1.032500, 0.424160, 0.674710, 0.524340, -0.412660, 0.736890, -0.545920, 0.161130,
-0.906350, 0.507760, 1.248250, -18.858990, -0.134630, -1.626480, -0.482660, 0.058080, -0.700320, 0.610520,
0.422730, 0.317290, -0.255530, 0.468460, -0.579450, 0.870490, 0.333410, 0.626080, -0.430240, -0.749180,
-1.919550, -1.187230, -3.100160, -1.927420, -1.585260, 0.127130, -1.041290, -0.762030, -1.123290, -1.232360,
-1.163070, -1.573660, -0.971530, -0.626130, -0.064260, -0.252550, -2.015820, -0.872510, -1.831870, -1.222140,
-1.293980, -0.382090, -0.306790, -4.509300, -0.577760, 0.133630, -0.507690, -1.285870, -0.863030,
-0.113230, 1.058730, -0.098960, -1.193630, 1.521980, -0.631080, 0.622850, 0.565460, 2.914360, 0.061500,
-0.393250, -0.600650, 1.314830, 0.542310, -0.226680, 2.249520, -1.334380, 1.153700, 0.299370, 0.648770,
0.012160, 1.159550, 0.518170, 0.626190, 0.860190, 0.302170, -2.156190, -0.231020, 1.096790, -0.983380,
3.310260, 1.921510, 1.465370, 1.203480, -0.870000, 0.565760, -0.241540, 1.514770, -0.575750, 0.321060,
-0.828140, 1.445560, -0.559420, 0.216970, 0.224280, -0.731870, 0.374200, 0.883750, -0.214620, -0.179720,
1.490030, -1.064670, 0.052920, -0.707610, 0.542750, -0.440140, 0.327690, -0.167900, 0.626160, -1.005170,
-1.630390, -1.360440, 0.267890, -0.077050, 0.558120, -2.227590, 0.385150, -1.191500, 2.622450, -0.743770,
0.132600, -0.871750, -0.967050, 0.333370, -2.463880, -0.374860, 0.384330, 0.159570, 0.332730, -0.370450,
-0.244830, -1.838960, -0.778180, -0.701620, 0.270520, -0.315930, -0.272580, 1.195920, 1.645000, 0.525310,
1.398060, 1.343240, -0.364260, -0.797700, -0.132450, 0.360530, 2.753920, -0.463460, 1.856500, -0.874490,
0.428050, 1.753950, 1.158550, 0.798530, -0.588760, 0.832230, 2.029800, -0.038400, -0.080750, 1.184330,
0.777340, -0.332170, 0.395280, 0.459780, -0.736230, -0.088430, -1.080690, -4.857090, 5.251860, -3.349440,
1.681470, -1.876500, -2.468060, -0.884760, -0.215290, -1.171650, -0.107580, -2.423490, 0.394610, -1.411830,
-2.261830, 1.484790, 0.740380, 0.831450, -0.986400, 0.292080, -0.141870, 3.417670, 0.040830, -0.015000,
2.959960, -2.865680, -0.706960, -0.945070, 0.895280, -0.379700, 0.358870, 0.249550, -0.087740, 0.142490,
-0.979900, 0.979190, 0.082780, 1.261430, 0.516960, 1.006300, -0.023810, 1.124500, 1.455070, -0.227750,
-0.610940, 0.179570, -0.727510, -0.982930, 0.776610, -1.448300, 0.493790, 0.559240, -1.069110, -0.774670,
-1.025610, 1.800930, -0.053840, -0.412320, -0.004270, -1.574780, 0.693100, 2.823920, -0.533990, -0.145480,
0.194850, -0.412110, -0.242520, -0.700560, -0.571180, -0.222070, 0.913270, 1.563060, -0.674060, -3.241420,
1.149000, -0.635860, 0.151890, -1.510680, -0.491180, 1.358040, -0.216550, -1.000230, 0.725400, 1.070540,
0.713400, -2.579260, 0.461630, 0.140400, 0.610380, -1.326610, 0.796070, -1.509410, -1.236090, 0.803770,
-0.160550, -1.039260, -0.099210, 0.891640, 0.423050, 0.595030, -0.201500, 0.079830, 1.590630, -1.184450,
1.179650, -1.915780, 0.702180, 0.640980, 0.052240, 1.833720, -0.413330, -0.316990, 1.622640, 0.633230,
-0.778010, 0.200930, 1.041650, 1.035780, 0.052510, 1.081310, -1.676820, -2.547100, -0.063630, 1.761560,
-0.940170, -1.464130, 1.417400, -1.240200, -0.871240, -0.770200, 0.529420, -0.012880, -0.508720, -0.235690,
1.323680, -1.273130, 0.500440, -11.851770, 0.086730, -1.581930, -0.054200, 0.542290, 0.246110, 2.698710,
0.298150, 0.432370, 0.483450, 2.093520, -1.164750, -1.866940, -1.103070, -1.382010, 0.547240, -1.255710,
-1.143330, -1.345190, -1.628100, -0.219830, -2.318270, -1.338270, 0.827520, -0.481500, -1.499940, -1.576550,
-0.336560, -0.636310, 0.111990, -0.260600, -0.957020, -0.421220, -0.621330, -0.557880, -1.438140, -0.745730,
-2.035010, -0.898500, 0.037810, -0.467580, 0.806300, 0.144890, 0.381510, -0.804140, 0.139420,
-0.847100, 0.159810, 0.824760, -1.352900, 1.007170, 1.561810, -0.034460, -1.578580, 0.392960, 1.374670,
0.762570, -0.227180, 0.571200, -0.398360, 0.235310, -0.995850, -0.395640, -0.358970, 0.032050, 0.523780,
0.173740, 0.839110, 1.242450, -0.332390, 0.040990, 0.825910, -1.519680, 0.742260, -0.593110, -0.073320,
0.679760, -0.217650, 0.130550, -0.298450, 0.832870, -0.957930, 0.220810, 0.317640, 0.192300, -0.738890,
0.436350, -0.599540, -1.073370, 1.054660, 1.105470, -0.758100, -0.381990, 1.059930, 0.160840, -0.206810,
0.338740, -1.088860, 0.749790, 1.550290, 0.589570, -0.874700, 0.841670, -0.030560, 1.017070, 0.707320,
1.538130, -0.253010, 0.179800, 0.977500, -1.159420, 0.623270, -0.931900, 0.601810, 0.273220, -0.001010,
-0.086010, -0.473230, -1.405810, 0.096800, -0.581130, -0.025270, 0.005650, 0.697780, -0.251090, -0.210470,
-0.428890, 1.075530, -0.420020, 0.177710, -2.018470, -0.968110, -0.132620, -0.607810, -0.586840, 1.477980,
0.690120, 1.105120, -0.690000, 0.992090, -1.842560, -0.677640, -0.431450, -0.145040, -0.468240, 0.243460,
-0.858230, 1.051530, -0.014560, -0.000450, -0.383920, 1.010780, -0.790010, -0.709790, 0.256120, 0.992420,
-1.149710, -0.373720, 0.164460, -0.626560, -0.376410, 1.368140, 1.134830, 0.503360, 3.621550, 0.053240,
-0.135640, -0.700270, 0.169010, 0.684050, 1.323170, -0.157820, -0.420420, -1.016570, 0.453160, 0.031370,
-0.437620, -0.791990, 1.122670, 0.598390, -0.050940, 4.865230, -1.077560, 0.524610, 2.051210, -2.941630,
1.556060, 0.685520, 0.074670, 0.153610, -0.295390, 0.835830, 0.975540, 1.062740, 0.372210, 0.299240,
0.101260, 0.841250, 0.792570, 0.278500, -0.103480, 1.556400, -1.024960, -0.620160, -0.311620, -1.665910,
0.036810, -0.216660, -0.929370, -0.617580, -0.100200, 0.113990, -0.386370, -0.807030, 0.154520, -1.595850,
-0.073870, 0.880620, 0.332970, 0.163570, -0.144230, 0.405890, 0.972840, 0.032750, 0.270500, 0.559560,
0.850900, -2.139260, -0.334060, -1.226520, 0.468160, 0.268420, 0.371950, -1.608390, -0.601400, 1.184600,
-0.632990, -0.718900, -0.112760, -0.578860, -0.119960, 0.030650, 1.951210, 1.258880, -0.109520, 0.442160,
1.077730, 0.851200, 0.425820, 0.260550, -1.112100, 0.090450, -0.836820, -0.125950, 0.862920, -0.450940,
-0.657920, 0.661070, 0.199160, 0.420740, -0.124590, 0.633220, 0.187170, 0.719040, 1.497830, 0.232970,
-0.228000, 0.555370, 0.694900, 0.201960, 0.607840, -0.206620, 0.449600, -0.091530, 1.271940, -1.873420,
0.384520, -0.423860, -0.537070, -0.367700, 0.683560, -0.177510, -0.397230, -0.313260, 0.367500, -0.780140,
-0.298610, 0.689360, -0.840790, -0.664780, -0.153650, 0.455680, -0.505820, 0.578930, 0.823310, 0.384890,
-0.357640, 1.095210, 0.286100, -1.071010, -0.499820, 0.607240, -0.420190, -1.127220, -0.712270, -1.009290,
-0.194620, 0.539260, -0.767030, -1.456820, 3.628890, -3.179400, -0.655880, 0.254540, -0.104860, -1.095370,
0.087590, -1.528700, -0.611400, -0.121270, -1.048090, -1.710420, -0.033130, -0.513510, -0.734730, -0.518910,
0.263020, -0.268790, 0.229410, -0.943510, 0.050140, -1.292520, -0.995290, -1.219030, -0.311860, -0.350190,
-0.240240, -0.794730, -1.680930, -0.081670, -1.491490, 0.138340, -0.538210, 0.219940, -1.161300,
0.938050, -1.022040, -0.671210, 0.308760, -0.330210, 0.492380, 1.878850, 0.347310, 0.491100, -0.720190,
-0.742590, -0.878930, 0.020380, 2.015830, -2.210280, 0.015730, -0.593560, 1.018310, 0.385950, 1.073980,
1.151980, -0.896430, -0.743620, -0.113130, -1.233130, 0.533780, -0.399870, -0.865910, -0.526580, -0.537730,
-0.126350, -0.389950, -0.336240, 0.976780, 1.290580, 0.672010, 0.045470, -0.813990, -1.245480, -0.658800,
-1.403210, -0.214290, -0.445550, 0.270380, -1.601950, 2.498760, -1.348910, 0.112390, -1.197120, -1.037700,
-0.015860, 0.991660, 0.376660, 1.306350, 0.083810, -0.998290, -0.232780, 0.214110, 0.394240, -0.008680,
-0.645180, 0.521220, 0.961140, -1.995540, 0.260920, -0.069560, -0.160800, -0.167250, 0.398920, -0.248390,
-0.077850, -1.309270, -0.525490, -2.086960, 0.630320, -0.609240, 2.065880, -0.350910, -0.708410, 0.135470,
0.208790, 0.686860, 0.302580, -0.478220, -0.242170, -0.346740, -0.022730, -0.876550, 2.416590, 0.885540,
0.475160, -0.651730, 0.452070, -0.800700, 0.758360, -0.071430, 0.219450, -1.118810, 1.128990, -2.510110,
0.661370, 0.332570, 1.213720, -0.806750, 0.156400, 1.303670, -0.832660, 2.728270, -0.711260, -0.547830,
-0.832190, 0.042950, 2.369970, 0.297510, 0.047760, -0.321430, -1.227320, 0.059840, -1.018550, 0.742160,
-0.858220, 0.754940, -0.851610, -0.071570, 0.117270, -0.195830, 0.203210, 0.882720, -0.109820, 1.724350,
1.372930, 0.257900, -0.449100, 0.217010, -0.537980, -3.992070, -0.557740, -0.678690, 0.689110, 0.204360,
0.249190, 0.561740, 0.898740, 0.454290, 0.245990, 0.751330, 1.549810, -0.365070, -0.490300, -0.502630,
0.895810, 0.100220, -0.051830, -0.623030, 1.135550, 1.349910, 0.375850, 0.007340, 0.869820, -0.749320,
-0.474390, 0.855820, -1.172810, 0.051370, -0.587740, -0.178080, 0.029520, 1.734010, 0.092480, 0.664120,
-0.804110, -0.554460, 1.371570, 0.260710, 0.563710, 1.081000, 1.732000, 0.258330, 0.328950, -0.671520,
1.621600, -0.350360, -2.669540, -0.068210, 1.045850, -1.247060, 1.307070, -1.370950, 0.348770, -0.560350,
-0.275240, -0.762720, -0.607380, -2.779190, -0.459180, 0.183300, -0.491500, -2.127460, -1.029140, 0.539570,
1.000730, -0.947580, -0.780610, 0.384860, 0.952970, -1.261630, -1.181690, -0.424880, 0.240630, 0.408550,
-0.835530, -0.376900, 0.892650, 3.327100, 0.980490, 0.868880, -0.378570, 0.261730, -0.372920, 0.742010,
-0.746910, 1.167190, 1.448780, -0.324550, 1.695930, 0.740700, -0.504090, 1.010730, -0.240810, 0.089280,
2.596950, 1.225700, 0.692970, -0.537050, -1.680290, -0.414260, -2.053040, -1.576740, -2.051260, 0.755430,
0.249240, -1.463020, -0.278160, 0.725520, -0.587660, 0.782190, 0.866230, -1.078430, 1.838020, 1.542150,
0.528340, 0.091390, 0.181610, 4.662080, -1.330170, -1.050640, -0.480950, -1.454670, 1.237700, -0.385040,
0.254380, 0.201780, -0.667690, 0.017830, -0.338960, -1.057510, 0.725980, 0.604320, 0.797660, 0.536830,
-0.212680, 1.211100, -0.479650, 1.142740, 0.726020, 0.306780, 0.133060, 0.065530, -0.268690, -0.046890,
0.427840, 0.812810, -1.279250, 0.830030, -0.664360, -0.082560, -0.343700, 0.019220, 0.160710, -0.728560,
-0.509580, 0.192610, 0.576290, -0.245520, 0.801860, -0.348580, 0.899220, 0.858080, 0.712780,
-1.020040, -0.770230, 0.444940, 0.205600, 0.152360, -1.797300, 0.034500, 1.072050, -0.377190, 0.805150,
-0.692330, -0.776590, 0.611570, 0.927450, -0.345050, -0.595690, -0.379050, -0.128530, 0.575540, -0.807280,
-0.422370, 1.340710, -0.926810, 0.852980, -0.298380, 0.287130, 0.251830, 0.100920, -0.359530, 1.005670,
-0.125130, 0.279660, 0.501190, -1.889420, 0.994330, 0.881130, -0.253590, -0.900520, -1.854640, -0.550640,
-0.136450, -0.472820, 0.653760, 1.680540, -0.890960, 0.154360, -0.419430, -0.946990, 0.399680, -0.951970,
1.800720, 0.161610, 2.073920, 0.100920, 0.728330, 0.219430, 0.559120, 0.357270, -0.150650, 0.162570,
-0.393170, 0.466810, -0.289320, -0.486880, 0.339400, -1.439840, -0.059520, -0.317360, 0.522920, -0.708180,
0.660550, 0.311150, -0.225030, 0.468610, 0.111840, 0.549140, -0.162340, -0.827430, -0.545940, -0.470700,
-0.013950, 0.031290, 0.425180, -0.699030, 0.935590, -0.790760, 0.730620, -0.413520, 0.959980, -1.227320,
0.305930, -0.613550, -0.296740, -0.012780, 0.140340, 0.375500, -0.673590, 0.982090, 1.444480, -0.455880,
0.642010, 1.270290, -0.767730, 0.276240, -0.370670, 0.335390, 0.608540, -0.997600, -0.257570, 0.713060,
0.385310, -1.343360, -0.367050, 0.425530, 0.113440, 1.144470, 2.080520, -0.217070, 3.292850, 0.134960,
-0.246660, -1.277590, 0.627510, 1.830330, 4.186670, -1.693510, -1.271200, 0.482470, 2.234580, 0.444390,
-0.962850, -1.566460, 1.306010, -1.616250, -0.087530, 4.551520, -1.161640, 0.396730, -1.228960, -1.068640,
0.461000, 0.613200, 0.655610, -0.535300, 0.525570, 0.386660, 0.981180, 1.494720, 0.707900, -0.289330,
-0.010850, -0.782430, -0.144710, 0.740020, 0.876020, 1.352120, 1.570140, -0.874290, -0.221230, 0.028330,
0.557790, -0.161070, 0.740960, 1.311440, -0.410480, 0.527330, 0.540060, -1.142440, 0.323340, 0.296080,
-0.891720, -1.034410, 0.264020, 0.027470, -0.182190, -0.205070, -0.681430, -0.019720, 0.978090, 0.936790,
-0.372020, -0.731630, 0.087890, -0.971450, -0.249740, 0.705350, 1.756040, -0.211810, 0.720940, -0.437140,
0.294710, -0.055380, 1.739980, 1.252790, 0.385580, -0.797400, -0.632200, -0.918420, -0.575500, -0.519110,
0.356000, 3.060010, -0.701100, 1.279510, 0.406830, -0.078250, 0.608240, -0.517230, -0.549010, -0.747120,
-0.539420, -0.931910, -0.013210, -0.235170, 1.378910, -0.954930, 0.305170, -0.394370, -0.706640, -0.940890,
-2.018310, -0.751810, -0.376920, 0.168150, 0.162960, -0.377580, -0.847840, -1.321740, 1.494020, -0.444270,
0.327220, 0.670460, 0.185220, -0.216500, -2.183080, 0.323860, 0.170680, -1.180460, -0.907120, 1.723660,
1.252410, 1.054690, 0.074670, 0.869020, 1.170960, 0.147880, -0.434350, 0.251880, 0.202900, 0.392280,
-0.794850, 0.366690, -0.541670, -0.482880, -0.473210, 1.075060, -0.096100, -0.234690, -0.151200, -0.828130,
-0.667410, -0.340030, -2.074250, -1.191260, 0.242510, 0.025480, 0.221000, -0.214850, -0.637630, -1.106150,
-0.683690, -0.673220, 0.526570, -0.133800, -0.632440, 0.496430, -0.771850, -0.934280, -1.262310, -0.514530,
0.302170, -0.430180, -1.022290, -0.512990, 0.261450, -1.133750, -1.220040, -0.391270, 0.010610, -0.524310,
0.242460, 0.369690, 0.618660, -0.041290, -1.115040, -1.326180, -0.531430, 0.387790, -0.615930,
1.142370, -0.687960, -0.554700, -0.975040, -0.496890, 0.703380, -0.634550, 0.019290, -0.175050, 0.862160,
0.710770, 0.661060, 0.113220, 0.307310, 0.291440, -0.719410, 0.184840, 1.001430, -1.057810, 0.263330,
0.176510, 0.579500, -0.707420, -1.056080, -1.333660, -1.094120, 0.218210, -0.025260, -0.093310, 1.133830,
0.693530, -0.086050, 0.079880, 1.493840, 0.233830, -0.911080, 1.994760, 0.198700, 1.136420, -0.179400,
-0.634840, -1.288620, 0.264740, 0.042730, -0.386530, -1.260970, 1.383950, -1.622820, -0.324150, -1.300400,
0.567470, -0.448750, 1.643100, 0.380400, -0.185200, -1.608820, 0.724050, 0.277960, -0.349460, 0.859630,
-0.816220, 1.200970, -0.866660, -0.225850, -1.257710, 0.152240, -0.330920, 0.383870, -1.269300, -0.744760,
0.246820, -0.457100, 0.511830, 1.431660, -1.089770, -0.027750, -0.499010, -0.791160, 1.023870, -0.089580,
0.464010, 0.016080, -0.421270, -0.303660, 0.138650, -0.821350, -0.352530, 0.443730, -1.096190, 0.599620,
-0.741810, 0.463030, -2.046360, -2.425630, 0.726080, -0.538130, -0.681160, 2.291660, 0.111280, 0.488380,
-0.312870, -1.151880, 0.444480, -0.889940, 0.094230, -0.918280, -0.511510, 0.747010, 0.516360, 0.849210,
-2.525550, -1.258570, -0.035850, 1.745930, 0.753950, 0.407050, -2.593120, -0.418530, 0.602780, 3.922560,
-0.145810, 0.284430, 0.060550, 0.140570, -1.225490, -0.153410, 1.347420, 2.676840, -1.440950, 0.687300,
4.473210, 0.404520, -2.054670, 0.211610, -0.421280, -2.145090, 0.813820, 0.842160, -0.018590, 1.155840,
0.296890, 1.230320, 0.730530, -0.787640, 1.698820, 2.034290, -0.410920, -0.757510, -0.659300, -0.282270,
-0.228300, -1.651590, -2.530040, 2.590640, 2.374780, 0.258300, 0.522350, -1.020930, -0.244120, 1.333940,
1.540940, -0.850160, -1.372750, 0.600760, -1.272240, 0.216020, 1.336340, -0.083230, 1.616520, 0.082480,
-0.137660, -1.052530, -0.573220, -0.200600, -0.783640, -0.860000, -0.489930, -0.395960, -0.667980, -0.097830,
0.847800, 3.018920, -2.753190, 0.291750, -0.804580, -0.655560, -0.297540, 0.205210, -0.712740, -0.367220,
-0.720410, 1.245860, 0.125480, -0.668190, -0.226760, -1.046730, -1.623600, -0.778370, 0.541720, 0.954930,
0.745120, 0.684570, -1.517010, -1.557710, -0.428730, 1.018960, 0.805210, 0.843190, -0.156180, 0.158990,
1.288250, 0.316160, 0.232970, -0.533000, 0.266930, -0.270710, -1.337630, 0.133620, -0.335600, -1.044990,
0.297800, -1.589480, 2.164290, 0.179230, 0.307750, 0.944790, 0.661380, -0.942830, -0.734720, -0.209230,
-0.464700, -0.329000, 1.324020, 1.720970, -0.114340, 0.216330, 1.433980, 1.076780, 1.284190, -1.435170,
-0.530490, -0.718600, 0.224670, 0.806750, -0.232930, -0.846690, -0.970890, 0.632190, 0.147550, 0.323610,
1.287110, 0.422890, 0.304700, 0.814800, 0.300450, -2.050170, 0.381050, 0.287560, -0.123230, -0.343830,
-0.986210, 0.081390, 2.791210, -0.203530, -2.504920, 0.122860, 0.188570, -0.393430, 0.167180, 0.159020,
2.408360, -0.407690, 1.172660, 1.235020, 1.051960, -0.477660, 0.797850, 0.396720, -0.893250, 1.187130,
0.528670, 0.437590, 0.829290, 0.174060, 0.612520, -0.483210, -0.182940, 0.882020, 0.821060, 0.244640,
-0.323510, 0.337470, -0.456650, 0.392050, 0.823410, 1.035680, 1.050440, -0.305440, 1.417160,
-0.866230, 1.814640, -0.734090, -0.830100, 0.413120, 0.997790, 0.030380, 0.338380, 1.321930, -0.300890,
0.360410, -0.599250, -0.352200, -1.048110, -0.028640, 1.452730, -1.107620, -1.155850, -0.199750, -0.714970,
0.532410, 0.009940, 0.468240, 1.341080, -0.623940, 0.137500, -0.155030, -0.638590, 0.567450, -0.864840,
0.483660, -0.421610, 0.685900, -0.114360, -0.511470, 0.333550, -1.024640, 1.053190, -0.715240, 1.298120,
1.669200, -0.246240, 0.204840, -0.105270, -0.382120, 0.197880, 2.418800, 1.280580, 0.891650, 1.086760,
1.064370, -0.891550, 0.452060, 0.463340, 0.121560, 1.069160, 0.660980, -0.604980, -1.506780, 0.393900,
0.203540, 0.767990, -0.866100, 0.919230, 1.056930, -0.129670, -0.609240, 1.162490, -0.270020, -0.169300,
0.554410, -0.108160, 0.632950, 0.082630, 0.517420, -0.417620, 0.225080, 2.214640, -0.038320, -0.286590,
-0.137270, 0.965030, -0.412570, 0.475510, -1.383980, -0.067270, -0.867880, -0.554690, 0.323780, 0.531120,
-0.288280, -0.673640, -0.703080, -0.671570, -0.987250, 0.932160, 0.726210, 1.412510, 0.205050, -1.356520,
-0.549050, 0.088320, -0.601000, -0.127980, 1.387050, 0.348920, -0.498010, -0.153110, -0.317040, 0.019580,
-1.705320, 0.752980, 0.703550, 0.656480, 0.399100, 1.453720, 1.831790, -0.068660, 0.541920, 1.034340,
1.203960, -1.309840, 0.374470, 1.187780, 3.180290, 0.201930, -1.595850, -2.103630, -0.278210, 0.407800,
-2.993840, -0.379500, 5.449600, -1.220570, 0.218270, 7.806660, -0.602330, 0.576240, 0.561650, 0.251270,
0.120950, -0.167970, 0.002360, -0.569830, -0.487730, -0.559380, 1.119480, 1.011390, 0.182110, 0.188620,
1.225530, 0.408390, -0.634010, -0.526850, -1.259390, 0.195180, 0.062430, -1.531470, -0.629220, -0.646450,
-0.163860, -0.640090, 0.152260, 1.106660, -2.606720, -0.587780, 0.336510, 0.099660, -0.665420, -0.014290,
0.472640, -0.908880, 0.703720, 0.797510, 0.162290, 0.250080, -0.773830, 0.371680, 0.420410, 0.201710,
1.258930, -1.427540, 1.438870, -0.038650, 1.320160, -0.470470, 1.502730, 0.723390, 0.160450, 0.020820,
-1.554030, 0.934220, 0.627910, 0.758670, 0.951290, -0.229140, -0.804280, 0.572150, 1.334250, 1.105980,
1.337270, 0.869370, 0.892320, -0.549630, -0.280740, -0.116270, -0.725180, -0.550290, 0.516390, -0.058640,
-0.824430, 0.043930, 0.628120, 0.440960, -0.007490, -1.478200, 0.421260, -0.319360, 0.341570, 0.355840,
0.519580, 1.346030, -0.295130, 0.472040, -0.011360, -0.000690, 0.104670, 0.408200, 0.501860, 0.361330,
0.706940, -0.064210, 0.490190, 0.282730, -0.595400, -2.359390, 0.087190, -0.341560, 1.346370, 1.022660,
-0.346560, 0.659640, 0.674850, -0.155760, 0.128520, -0.109660, 0.693140, 1.727480, -0.955650, -0.165970,
-1.063520, 0.266560, -0.612330, 4.266020, 0.193000, -0.582050, 0.057460, 0.689950, 0.616910, -0.852690,
0.747030, 1.079280, -2.197460, -1.522560, 1.035240, 0.143050, -0.068610, 0.932010, 1.043860, -0.464100,
-0.865140, -1.057350, 0.425890, -0.325180, -0.151950, 0.070010, -2.941330, 0.231690, -1.347380, -0.715860,
-1.100160, -0.888230, -0.140970, 0.723010, -0.130280, -0.096450, -1.330780, -0.820870, 0.057190, 0.074100,
-0.977540, 0.050710, -0.094990, -0.447790, -0.433050, -0.466380, -1.504660, -1.299290, -0.300080,
1.307110, 0.430340, -0.896480, 1.769610, -0.445090, 0.560710, 0.595470, -1.523210, 0.616700, 0.300920,
-1.399690, 0.346550, -0.074600, -2.528620, 0.901360, -1.194930, 0.316710, 0.458860, 0.166980, -0.463680,
0.093800, 0.162400, 1.083790, -0.300230, -1.690840, 0.125220, 0.035520, -1.136300, -0.782410, -1.212290,
-0.360650, -0.515470, -0.138330, 0.175330, -0.815560, 0.418480, 0.798340, -0.954130, -0.709910, 0.188960,
-0.903790, 0.014930, -0.259360, -0.374140, -1.531130, -0.581250, -0.311390, -0.728270, -1.745010, 0.487010,
-0.681970, -0.525440, -1.258620, -0.976000, -0.591220, 0.105990, 1.006550, -0.280420, 0.565090, -0.499910,
0.666410, -0.035840, 0.146570, -1.383850, -0.883980, 0.808680, -0.132680, 0.645750, -0.556560, -0.305850,
-1.095360, 0.586700, 1.317500, 1.305600, -1.074850, -0.014370, -0.325320, 1.194950, -0.939040, 0.997270,
1.182160, -0.182680, -1.466290, 0.804620, 0.663910, 1.090390, 1.970470, -1.090170, -0.191380, 0.017440,
0.842600, -0.102540, -0.967920, -1.474490, 0.231950, 0.080950, -1.626510, 2.271750, -0.431580, 0.084860,
-0.453620, 0.259730, -0.415690, 0.215760, -0.230340, -0.199280, -0.132840, -0.062900, 0.089820, -0.589440,
-0.442960, 0.170990, -0.229300, -0.177700, 0.432830, -1.263710, -1.191850, -0.331770, -2.055450, 0.267330,
-2.171100, 1.087350, -2.850990, -0.389450, -2.052560, 1.746110, 1.765180, 0.945400, -2.162310, -1.254070,
1.485450, -0.008580, -2.035700, 0.960690, 1.214300, -2.200600, 1.649800, 1.059640, -1.730400, -0.304430,
-1.900820, -0.612860, -0.164910, 1.019860, 0.274780, -0.232580, -0.744030, -0.105550, 0.228530, 0.183100,
-0.129480, -0.548840, -0.362410, 1.300680, 0.297950, -0.897460, 0.494230, 0.434160, -0.041280, 1.852170,
-0.686760, -2.621510, -0.945630, 0.273210, 4.372900, 1.958270, 0.043070, 0.142750, -0.747280, -0.148590,
-1.351120, 0.674770, 2.742080, 0.072730, -0.032580, -1.444470, 1.237830, 0.711200, 0.061950, -0.201480,
0.910040, 0.259480, -2.266630, 0.035300, -0.911140, -2.711150, -0.166060, 1.968350, 2.231120, 1.638620,
-0.330070, -1.184420, -0.141940, 2.973220, -0.082070, 0.163510, -0.032960, 0.761520, -0.232700, 1.741620,
0.816740, -0.197810, 1.022050, 0.751690, 0.563210, 0.607750, -0.157380, 1.372490, 0.968700, -1.025240,
-1.507350, 0.524040, -0.651760, -0.019680, 0.128540, -0.974870, 0.034920, 0.626910, 0.479090, -0.892320,
0.543180, -1.724390, 0.115550, 1.561600, -2.191380, 1.011290, 1.845320, -0.793330, 0.707980, -0.222090,
1.799280, 0.978630, 0.212200, -1.282710, -0.629640, -0.646580, -0.868340, 0.450920, -0.166080, -0.730350,
0.406020, -0.363730, 0.172650, 0.855370, 0.546650, 0.442940, 0.645100, 0.901340, -0.557170, 0.260980,
0.238650, 1.295830, -1.066430, -30.126150, -0.438390, 0.361780, 0.066380, 0.845210, -0.397660, 1.685940,
-0.405920, -0.545270, 7.515540, 1.692170, 0.131130, -2.402990, 0.263820, -0.155590, 0.147630, 1.079810,
1.436900, -0.858840, 1.178490, 0.084180, -0.417140, -0.331740, 2.364470, -0.574800, -0.456880, -0.954370,
0.225620, -0.667760, 0.767340, 0.606080, -0.833790, 0.683740, 0.439420, 0.648790, 0.701610, -0.472330,
-0.663540, -0.079810, 0.641880, 0.173700, -0.467390, -0.378390, -1.949530, 0.162710, 1.130940,
1.209970, 0.060650, -0.769090, 0.854930, -0.542580, 0.006070, -0.576690, 0.473180, 1.780230, -0.031030,
-0.148570, 0.939150, -1.541550, -1.356120, -0.851380, -1.154680, 0.127020, 0.904310, 0.285440, 0.371550,
-0.530110, 0.065580, 0.319330, -1.609680, 1.030860, 0.617930, -0.001970, 0.868620, -0.862940, 0.357420,
0.182760, -0.481240, 0.684790, 2.702510, -0.613190, -1.199380, -0.993050, -0.192950, 1.517410, 0.712610,
0.073170, -1.679550, -0.686610, -0.565650, -0.010570, 0.284880, -1.547710, 0.805070, 0.884550, -0.125460,
-0.407190, -1.752670, -0.156460, -0.835780, 0.753010, 0.855730, 0.385100, -1.314740, 1.072760, -1.988840,
-1.398500, 0.472880, -0.546020, 1.123790, 1.158980, -0.170550, 0.308220, -0.528080, -0.614650, 0.735430,
-0.382430, -1.259000, -0.264030, -0.190490, 0.508280, -0.107050, 2.329880, -0.059440, -1.889420, 0.201890,
1.198090, -0.313720, 0.884380, 1.014010, -0.471740, -0.044720, 0.646520, 0.912300, -0.645560, -0.332980,
-0.059460, -1.004770, 0.843040, -0.938070, -0.017510, 0.827310, -0.157380, 0.933920, 1.004500, 0.892450,
1.067810, -2.212070, -0.689890, -0.448130, 0.663420, 1.192850, 0.672160, -0.529840, -0.873600, 2.798220,
-0.641070, 0.605830, -0.879530, -1.082020, -0.973660, -0.334640, 0.564880, 1.968860, -0.265530, 1.331090,
0.847500, 0.589210, 0.008890, -1.572000, 1.594790, -0.465020, -1.248730, 0.080160, 0.538200, 0.803230,
-1.776300, -0.446170, 2.456390, -0.991860, -0.376390, 2.562330, -1.108980, 0.804760, 0.735320, -1.978180,
-1.832010, -1.446230, 0.488220, -0.200700, 0.027250, 0.685330, -0.410760, -0.760650, 0.222330, 1.151780,
-1.194790, 0.638160, -0.220410, 1.364990, -0.501200, 0.197220, -1.751180, -0.844750, 0.916470, 0.781260,
0.759160, -1.854250, 2.144030, 0.102310, -1.423960, -2.122390, 1.256820, -0.208020, -1.224830, 1.741360,
0.749810, -0.672370, -0.140740, -2.062950, -1.012490, 0.365500, 1.768130, 0.127690, -0.154750, -1.525140,
0.943330, 1.170710, -0.853150, 0.405910, 0.428860, 0.371570, 0.107940, -1.659240, 0.533580, -0.975640,
-0.362790, 0.469690, -0.769290, -0.006580, 0.648220, -0.252690, -0.939730, 0.541090, 0.558350, -0.035170,
-2.017520, -0.779480, -1.588970, 1.222460, 0.431490, -0.517020, 2.738840, -0.032480, 0.183890, 0.117610,
0.806050, 0.468960, -0.792240, -0.816020, -0.448880, 0.417490, -0.382870, -0.689390, 0.669610, 0.042310,
-0.445420, -0.027750, 0.220200, -0.748080, 0.233080, -1.544970, -0.087930, 0.544830, -0.563670, 0.391810,
-1.595900, 0.052610, -0.644700, -1.871050, 0.916100, 0.871130, -0.415380, 1.020800, 0.002070, 1.536300,
0.340430, -0.695550, -1.264950, -0.899590, 0.393750, 0.518320, -0.442270, 0.180810, 0.774950, -0.962740,
0.307600, 0.095940, 1.307080, 3.740460, -0.398400, 1.352360, 0.227460, -0.342640, 0.964810, -0.723230,
-2.781340, -0.309430, -1.884210, -0.748770, 1.372910, 0.636980, 0.326380, -1.725740, 0.004840, -0.873580,
-0.121750, 0.846400, 0.073100, -0.811790, -0.613150, -0.079680, -0.829430, 0.164110, 0.873980, 0.448380,
-0.647190, 0.466680, 0.454270, -0.059470, 0.813030, -0.864700, 0.171760, 0.784030, -0.210900, 0.865440,
-0.578120, -0.639350, -0.741350, 0.160630, -0.706020, 0.545720, -0.777360, 0.334140, -0.639190,
0.736170, 0.360840, -0.130460, -0.193260, -0.107780, 0.742160, -0.216760, 0.370370, -1.201370, 1.120200,
0.990720, 2.630890, -0.291860, -1.194390, 0.486850, 0.893800, 1.236500, 1.860690, 0.349920, 1.222540,
0.037740, -0.829060, -0.957630, 0.113890, 1.951350, -0.636400, 2.865770, 0.365790, -2.098470, 0.327730,
0.352080, -1.041240, -0.079850, 0.666190, -1.026030, -0.920340, -0.069620, 2.418700, -1.194160, 1.100250,
2.671120, -0.695190, -2.629360, -0.849140, -0.701350, -0.862330, -0.372470, 1.119360, -1.948800, 0.042110,
0.094240, 0.115870, 0.271060, -3.721800, -0.284460, 1.115560, 0.692330, -0.279810, 1.195190, -0.633240,
-0.232970, -1.612190, -0.888200, 1.480720, -0.857660, -1.337230, -0.502920, 0.070920, 0.593840, 2.315870,
0.625260, -2.990230, 0.738810, -0.905100, 0.265220, -3.043660, 0.538320, -1.367370, -1.337440, 0.042860,
-0.313020, 0.192050, 0.174720, 2.197950, -2.269470, -1.103030, -1.087260, 1.161820, -1.115790, 0.500340,
0.160480, 0.680760, 0.541930, 2.023810, 0.443710, 2.053710, -1.038450, -0.967830, -0.304620, 1.255530,
0.038130, -0.867780, 1.715930, -0.016550, -0.562890, 0.859870, 2.059270, -0.580570, 0.644960, 1.530220,
-1.470050, -0.100810, -0.312140, 0.185780, 1.760300, 0.296150, -0.734290, 0.716650, -1.280790, -1.206500,
0.913080, -0.117510, 0.213240, 2.244470, 3.266650, -1.596670, -0.670070, 0.670870, 0.984670, -0.256650,
-1.507170, -1.140610, 2.629550, 0.299230, -0.297210, 0.266230, 0.309840, -0.377120, -1.491610, -2.996780,
-1.279060, -2.833360, -1.268240, -1.332060, -0.903240, 0.189210, 0.364000, 0.040920, -1.573180, 0.861510,
-0.060990, 2.543150, -0.386400, 0.051770, 1.118000, -0.927960, 3.011590, 0.731180, -1.361570, -0.647620,
-6.046700, -0.195080, -0.330050, -2.993720, -1.866980, -1.740580, -2.016370, -1.946510, -1.128930, -0.618660,
-2.987410, -0.277610, 0.168130, -0.385090, 1.223570, -1.161570, 0.379800, -0.648170, -1.397840, -0.533310,
0.259260, -0.840450, 1.643260, -0.921340, -1.090630, -0.779250, 1.484630, 0.323850, -1.803460, 0.504010,
1.698820, -0.832190, 0.181050, -0.008640, -1.569150, -0.674250, -0.088530, -0.021530, 0.275510, -0.492860,
0.202930, 0.492830, -1.586270, 0.134020, -0.286480, -0.717770, -1.318510, -0.229350, -0.490760, 0.593960,
-0.388790, 0.259530, 0.164020, -0.749690, -1.416110, -0.037470, -0.235950, -0.180780, 0.811630, -1.235340,
-0.388590, 0.501290, 0.864380, 0.307450, -0.953180, -1.190350, 0.438960, -1.173610, -0.717700, -0.871940,
0.977250, 2.462520, -0.477890, -0.320330, -0.674040, 0.719450, 1.061910, 0.710250, 0.894500, -0.931820,
-0.147160, -0.045050, -0.495140, 0.300870, -0.743230, -1.568520, 1.574040, -0.567980, 1.118320, 1.912280,
-0.125410, 0.968890, -1.082380, -5.028250, 0.886470, 3.718390, 2.059640, -1.109310, -0.239060, -1.830220,
-1.847510, 0.300400, 0.459740, 0.151990, 1.583280, -0.867070, -0.060910, 0.071850, -0.909730, 0.232850,
0.804920, -0.707930, -1.248250, 0.611910, -1.685870, 0.682890, 0.778660, 0.392860, 0.546410, 0.122740,
0.122460, 0.293100, -0.212130, 0.824150, -1.002750, 0.042490, -0.357830, 0.036380, 0.341680, -0.213610,
0.007020, -0.166050, 0.028880, 0.615630, 0.698460, 0.036260, 0.830710, 0.896050, 0.852230,
-0.906460, 0.811010, 1.045690, 0.457190, -0.962270, -0.491250, 0.295480, 0.946860, 0.660450, 0.571690,
-0.548450, 0.331290, -0.399410, 0.569700, -0.737610, -0.837030, -0.455710, -0.254250, -0.353140, 0.457270,
2.800500, -1.460480, 0.082250, 0.651660, -0.168880, 0.041480, -1.307740, -0.589920, 0.349370, 1.345820,
-0.073000, 0.750340, 0.519280, 1.948110, 0.922930, -0.590910, 0.119730, -0.246930, -0.719700, -1.187710,
-0.951610, 1.110470, -1.118970, 0.828600, -1.072330, 2.167090, 0.840360, 0.930030, -0.430420, -1.499290,
1.331030, 0.530550, -0.967880, 0.809670, 1.929290, -2.510910, 0.521470, 0.904760, 0.488110, 1.140860,
1.128070, -0.067050, -0.493780, -0.069710, -0.777370, 0.178440, 0.292340, -1.621630, 0.021590, 1.745870,
0.035340, -1.246230, -0.202920, -0.078820, 0.314440, -0.381060, 1.212250, -0.735150, -0.518120, -0.481670,
-0.077230, -0.947890, 1.387950, 0.054710, 1.171200, 1.234930, 1.032900, 0.293070, 0.082250, 0.682310,
0.060620, -0.103070, 1.446360, 0.485930, 0.122580, 1.007100, -0.260880, -1.439310, -0.022590, -1.378630,
1.460620, -0.186310, -0.234470, -0.348010, -0.810950, 1.287880, 0.016850, 0.765020, -0.452030, 0.278950,
0.335990, -0.275480, 0.405520, 0.616530, -0.066370, -0.273810, -2.288350, -0.866560, 2.258630, -3.362180,
-0.206490, -0.995830, -1.075320, -3.422430, -0.591280, 0.707180, 0.144750, 0.567260, -0.046180, -0.040100,
-1.121560, -0.385410, -2.886930, 0.495860, 0.516150, -2.402590, -0.417090, 2.673850, -0.912060, -0.995240,
-0.848440, 1.296170, 0.918560, 1.211290, 1.374480, 1.023100, -1.497840, -0.472740, 0.441720, 0.579660,
-0.606030, 0.530700, -1.320530, 0.457860, -0.597370, -2.792820, -0.574840, 1.139680, -0.732720, 0.747920,
3.249990, -1.141270, -2.313520, 0.770260, 1.106620, -0.120420, -0.489930, 0.375850, -2.507120, -1.169690,
-0.199920, 0.262010, -0.814750, 0.071460, -0.045180, 0.819090, 0.300040, 0.003780, -2.502680, -0.940150,
-0.752780, -0.319520, 0.416020, 0.933360, -1.225500, -0.197760, -0.757290, 1.805180, -1.105920, -0.589600,
1.166640, 0.416550, 0.267600, 0.711020, -0.479340, 0.137640, 0.567880, -2.289710, -0.025060, -1.215190,
-0.018590, -1.892650, -0.689450, 1.490830, 0.600170, -1.452560, 0.309270, -0.424340, 0.784700, 0.213220,
1.983610, -0.446690, -0.674590, 1.039040, -2.574260, -0.658580, -1.452650, 0.185410, 0.149450, -0.659830,
-1.189910, 0.832290, -0.576160, 0.814290, -2.672190, 1.154530, 0.249540, -0.534410, -0.205870, 0.785950,
-0.157600, -0.614610, 0.602190, 0.131740, 0.247660, -0.159590, 1.494090, -0.969910, 0.331770, -0.676230,
-0.571540, -0.176260, -0.020820, -2.430430, 0.171270, -1.493670, -1.167940, -0.445850, 0.293920, -0.006870,
-1.014070, 1.026700, 0.757150, -1.472270, 0.398080, 0.919250, 0.857680, 0.071390, -0.675770, 0.737580,
-1.019060, 0.317800, -0.457430, 0.915910, 0.523830, -1.232920, -0.606140, -0.080300, -0.204810, -1.009820,
-0.572370, -0.961250, -0.096820, -0.126270, 1.033680, -1.000050, -0.070110, -0.602830, 0.776480, 0.298420,
0.438130, 0.724120, -0.005380, -0.390570, 0.171640, 0.003380, -0.858130, -0.380360, -1.618310, 0.506640,
-0.170300, -1.226350, 0.387560, 0.447880, -0.055000, -1.301500, -0.612730, 0.593590, -0.777700,
-1.569250, -0.474480, -0.391790, 1.010480, -0.042990, -1.274950, 0.219720, -0.126070, 0.804350, 0.859780,
0.516570, -1.228950, -1.199050, 0.831000, -1.265940, 0.002000, 1.111430, -0.589880, -2.323440, -1.218310,
0.486840, 0.962940, 2.367700, 0.706180, 0.067410, 1.289520, 0.069070, 0.249660, -0.600600, 0.270180,
0.700160, 0.509740, 1.523830, -1.226040, -0.411560, -0.667620, 0.916850, 0.984930, 0.603080, -1.775520,
-1.100650, -0.035250, 0.591310, 0.838960, -0.227790, 0.440360, -0.490490, 1.316510, -1.157670, -1.279230,
-0.627990, 0.669080, -0.313430, 0.775260, -0.041110, 0.837990, 0.334550, -0.914730, -0.886410, 0.582710,
0.349360, 0.832100, -0.107780, 2.274890, 0.052570, 0.025380, 0.141540, -0.144310, -0.573980, -0.153040,
0.684100, 0.036920, 0.162060, 2.296550, -0.783570, 0.125190, 0.186840, 1.127530, 1.931320, 0.329200,
0.470590, 0.538930, -0.144890, 0.634820, 0.398450, -1.754690, 0.256510, -0.516730, -0.958060, 0.194610,
-0.361270, 0.379930, 0.516190, -0.695760, 0.185500, -1.193940, 0.608540, -0.143820, 0.622440, 2.589190,
1.014470, -0.426400, 0.346400, -0.506990, 0.311240, 0.509980, 1.477230, 0.120380, 0.332730, 0.677820,
-0.026680, -1.575260, 1.271420, -1.050230, 0.177140, 0.253670, -0.955990, -0.176640, 2.582880, -2.651460,
1.220520, 0.594630, -1.237920, 0.604910, -0.858100, -1.018540, 1.843500, -0.767350, -1.761870, -1.417120,
-2.784760, 0.402340, -1.704600, -1.714720, 2.367270, 0.272620, -0.241390, 4.417600, 0.551110, -1.427320,
0.819420, 0.283000, 1.921120, -0.939590, 0.352500, -0.388630, 1.939460, -0.594710, 0.059880, 0.675690,
-0.944350, -2.691770, 0.041040, 0.267760, -0.738800, 1.406230, 0.148660, 0.617720, -0.501010, 0.430960,
1.794600, 1.557800, 0.115280, 0.601870, 1.348990, 0.174840, 1.106030, 0.074810, -1.064920, 0.340270,
0.424540, 0.187790, 2.468130, -2.372810, -0.808850, -0.468970, -1.564870, -2.323520, -0.633530, -0.014730,
-0.512300, 0.108520, 0.096190, 0.558270, 0.666550, -0.234990, 2.324570, 1.326700, -0.268630, 0.184540,
0.001820, 0.295350, -1.423120, -2.052510, -1.240760, -0.974470, -0.815390, 1.122930, 0.630700, 0.883910,
0.569870, -0.017820, 0.955900, -0.405880, 0.206750, -0.304240, 2.404120, -0.027570, 1.807500, -0.808040,
0.436600, -1.461290, 0.227960, -0.341800, -1.422550, 0.728210, -1.697250, 0.772760, -0.170510, -0.124670,
-0.532350, 0.495870, -0.269620, -0.095370, -0.108950, -0.493930, 1.432750, -0.051100, 0.046540, -1.013070,
-1.746050, 0.696050, 0.294450, -0.199910, -0.230920, 0.090950, -0.219880, -0.525090, 0.499540, 0.396360,
2.059570, -0.148300, 0.340440, -0.462650, -0.434250, 0.360250, -1.489530, 0.246940, -2.244890, -0.423490,
0.245800, -0.278560, 1.276620, 14.083600, -0.076700, -1.074290, 0.716770, -3.570350, 0.019390, 0.199180,
-1.673880, 0.335220, -1.557640, -0.043020, -0.298940, 0.097830, 0.081630, 0.823810, -0.348370, -1.277300,
-1.097000, -0.829840, -5.626710, 0.337990, -0.435350, -0.063240, -0.791090, -1.482870, -0.423730, -0.616180,
-0.343050, -1.182960, 0.137170, -1.095730, -0.007290, -1.577560, -1.263610, -2.217600, -1.363380, -1.308380,
0.626190, -1.369050, -1.138670, -1.999860, -0.332360, -0.365450, -0.406310, -0.334540, -0.592680,
-0.623030, 0.323890, 0.606330, 0.797870, -0.232930, 1.422260, 0.142200, -0.106300, 0.487640, -0.132570,
-1.555540, -1.097550, -0.689640, 1.475680, 0.805230, -0.051200, -0.010620, 0.221390, -1.234110, 0.299260,
1.017110, -1.633620, -0.762400, -0.162690, 0.068850, 0.688530, 0.016570, 0.574310, 1.521400, -0.273240,
0.701240, -1.059080, 0.329570, 0.996050, 0.386100, 2.233420, -0.495430, -0.207410, 0.968520, 0.600390,
0.673100, 2.460060, -0.548090, 1.165480, -0.535060, 1.525050, 0.094110, 0.450290, 1.155120, -0.314920,
-0.916510, -0.861880, -1.452630, -0.947060, 3.262240, -1.218530, 0.188740, 1.240350, 0.638570, -3.616480,
-1.897420, 0.326420, -0.242970, -1.291740, 1.232130, -0.169270, 0.181240, 0.510590, 0.784860, 0.606970,
-0.001890, 0.099970, -0.731450, 0.845660, -0.793500, 0.171730, -1.573950, -1.230650, 1.458260, 1.347800,
0.895180, 0.651140, -0.085900, -1.534200, 1.664260, 0.984240, -0.512760, -0.776110, -0.073600, 2.014730,
0.646040, 0.837490, 0.151580, 1.055580, -0.594040, -3.529900, 0.296170, -0.645720, -0.501190, -0.688110,
-1.621700, -0.063660, -0.748610, 0.104920, 0.074670, -0.019140, -0.830740, -0.969340, -1.125750, 0.846560,
-1.637860, 0.746580, 0.933590, 0.949890, -1.198480, -1.897330, 0.568250, -1.111400, -1.717190, 0.516530,
-1.477290, -1.321770, -0.347420, 0.424010, 0.096190, 0.061910, 0.688280, 3.266290, -0.372980, 1.950620,
1.783210, -0.186170, -1.291300, 0.250040, 0.407360, -6.551660, 0.268030, 0.516050, 0.292680, -0.012210,
-1.230110, -0.479090, 0.106550, 0.786280, -0.368130, -1.452070, 0.547640, 0.627700, -1.514580, -0.108620,
-0.080710, 1.022480, 0.289550, 0.033400, -1.073590, -0.345920, -1.319210, -0.536460, 0.218520, 0.114390,
-0.330110, 0.378050, 0.832340, 1.648800, 0.675370, -0.449160, -0.382120, 0.710450, -0.634920, -0.583990,
0.471840, -0.338140, -0.082070, 0.062740, 0.010660, -0.584160, 0.356410, -0.192790, 0.534460, 0.917820,
-1.347610, -1.272320, 0.569910, 1.080860, -0.478460, 0.857490, 2.255080, -0.893680, 0.735830, -0.699000,
-0.851880, -1.369920, -1.339530, -0.707000, 0.823980, -0.250290, -1.279530, 0.351990, -0.387180, 0.316560,
2.719540, -0.632330, 0.621770, -0.646440, 2.479610, -1.011200, -0.394980, -1.637760, 0.210630, -0.298980,
1.480080, -0.089490, -1.307560, 0.387800, -0.478940, -0.984850, -0.892430, 1.560950, -0.177990, 0.705240,
0.471280, 0.963480, 0.746940, 1.452250, 0.403970, -0.118000, 0.460170, -0.350670, -1.593180, -0.538390,
0.446430, -2.173990, 0.514210, 1.744670, 0.254680, 1.279430, -1.161630, -0.357670, -0.363060, 0.227820,
1.297590, 0.899260, -1.212900, 1.518600, 0.001080, 1.318030, -1.177660, 0.068110, 2.037250, 1.083560,
1.157420, -0.312500, 0.694480, -0.477400, -0.190360, -1.141460, -1.469560, 0.274170, 0.737810, -0.516450,
0.637330, 1.939480, 0.821610, -0.406570, -0.209670, 2.249210, -0.698340, 0.686540, 0.096910, -0.611900,
1.183090, -0.584030, -0.590890, -0.221120, -0.355140, 0.206680, 0.687160, -0.825400, 0.073090, 0.053840,
-0.601920, 0.194460, 1.019620, 1.592190, 0.657670, -0.227100, 0.109210, 0.347120, -1.303890, 0.132170,
-0.186830, 0.530240, -0.486940, 0.602920, -0.393200, 0.988740, 0.418000, 0.797970, -0.788470,
0.134540, 1.111980, -1.827960, -0.431280, -1.157000, -0.360210, -0.443920, -0.963040, 0.074030, -0.387630,
0.880380, 1.433150, -0.759620, 0.992040, -0.232200, -0.977630, -0.712740, 0.698900, -0.824270, -0.053110,
1.331340, -0.087250, 0.716700, -0.057370, -0.348190, -0.439050, -0.014110, -1.478830, 0.284950, -0.259580,
0.059230, -2.254200, -0.055920, -0.075620, 0.156310, -1.220210, 0.391810, -0.566010, 1.073840, -0.986310,
-1.948840, 0.128140, -0.435250, 0.988140, -0.008150, 0.990820, -0.816000, 0.498180, 0.210840, 1.098120,
-0.721490, -0.742400, 0.581170, -0.403920, -0.640290, -2.534410, 0.346030, -0.140970, 0.537970, 0.982290,
-0.199680, -0.286040, 0.231110, -0.201250, -0.466820, -0.577060, 0.134930, -0.719400, 0.533060, -1.671920,
-2.311270, -0.008260, 1.662310, -0.486780, -0.399310, -0.030450, -0.785040, -0.679430, -1.040500, -0.491510,
-0.187380, -0.142000, 0.885950, -0.692780, 0.878410, -0.225660, -1.004790, -1.254690, -0.953640, 1.944450,
-0.058360, -0.037990, -0.563470, -0.896510, -0.067820, 1.292140, 0.661600, 0.423020, -0.454380, -0.708110,
-0.585740, 0.962930, -0.322970, 0.142250, 1.500310, -1.010570, 0.326110, -0.830430, 0.275680, -2.409650,
-0.435700, 0.459760, 1.986220, -0.536780, 0.570390, -1.428390, -1.516630, 1.122470, 1.721590, -1.818580,
0.561660, 1.430710, 0.228850, -1.472950, -2.707920, 0.335350, -1.728780, -1.076380, -0.016290, 4.352480,
-2.976630, -0.899890, -7.359590, -1.481850, 0.377510, -14.812970, 0.653870, 3.610570, 0.461130, 0.845860,
-1.255030, 0.101170, 0.259880, 0.701060, 0.843700, 1.504060, -1.933600, -1.629120, -0.289770, 0.163270,
-0.062230, 1.868550, -0.491930, -0.222980, 0.885180, -0.757970, -0.271300, 0.271940, 1.499670, -2.232980,
0.411140, 0.563810, -0.751710, -1.000760, 1.827700, -0.335120, -0.592080, -0.832370, -0.762130, 0.281430,
-0.235950, -0.448500, -0.234160, -0.490550, 0.527740, 0.783400, 0.118610, -0.156060, -1.057760, 0.185800,
-0.494610, 0.481740, -0.030330, 0.458350, 0.228530, -0.098850, -1.244560, -0.061390, -0.806470, 1.667590,
-0.281070, 0.370050, -0.065130, -1.744160, -2.793650, -0.451340, 0.569870, 1.000100, 1.304450, -1.154860,
0.065250, -0.698500, 0.945330, 0.673380, 0.082800, 0.532450, 0.776390, 1.117470, 0.001160, 0.061880,
-1.047960, 0.308470, -1.316880, 0.099750, 0.968320, 0.591020, 0.027100, -0.860770, 1.219960, 0.180160,
1.471370, 1.249960, 0.276050, 0.410160, -2.122960, 1.031960, 0.313950, 0.746240, -1.374250, -0.044620,
-0.507390, -0.661320, -1.998570, -0.951960, 0.166250, -0.325350, -0.268390, -0.630190, 0.717540, -1.284590,
-0.964850, -1.103500, 0.217440, 1.392760, 1.087190, -0.035360, -0.382930, -0.430670, 0.110770, -1.162230,
1.774010, -0.796700, 0.942500, -9.994650, -0.154220, -0.532610, -0.634600, -0.043130, 0.363530, 0.919550,
0.063870, 0.319180, -2.037380, 0.169160, -0.943300, 1.021520, 0.210420, 0.215830, 0.817010, -0.886100,
-0.519610, 0.600910, -0.661420, 0.370860, -0.488670, -0.462950, 0.426430, 0.126410, -2.436340, -1.162130,
-0.328600, -0.113140, -0.365860, 0.781670, 0.684750, -0.497400, -0.505470, -0.596040, -0.605290, -0.126400,
-1.127430, -0.837440, -0.681100, 0.386990, 0.106530, 0.154510, -0.590900, 1.092430, -1.146690,
-0.150250, -0.079310, -0.555240, -0.883090, 0.710050, 0.673450, 0.151680, -1.650980, 0.222540, 0.014700,
0.110740, -1.297900, -0.783420, 0.216420, 0.486620, 1.055850, 0.352950, 0.311120, -0.505990, -0.029990,
-1.179680, 0.995750, -0.468480, -0.555460, 1.031710, 1.164100, -0.813560, -2.383930, -0.639100, -1.366780,
-0.554290, 0.310300, 1.285390, -1.221360, -0.867710, -1.207110, -0.894060, -0.072050, -1.121410, -1.296520,
2.547300, 1.193180, -1.316540, -0.908270, 0.248860, 0.130770, 0.643830, -0.432880, 0.479330, 0.190620,
-1.214290, -0.321870, -0.625680, 0.378290, 0.587690, -1.186110, -0.989400, -0.276990, -0.865760, 0.757360,
0.425340, 0.197040, -1.265910, 1.049040, 0.403730, -1.374340, -0.380020, 0.846530, 0.392710, 1.251440,
-0.595250, -0.068220, -0.660550, -0.503590, 0.166760, -0.333790, 0.911370, 0.955980, 0.363050, -0.444530,
0.087960, -0.020100, 0.596920, 0.120450, -0.534950, -0.497550, -0.555360, 1.498900, 0.192210, -0.639260,
1.308420, -1.236790, -0.410700, 0.073250, 0.170510, 1.878100, -1.187260, 1.297800, -0.541860, 0.280980,
0.293110, -0.914430, -0.072020, 0.543160, -0.057870, -0.218800, 1.118500, -1.093780, 0.164900, 0.848190,
0.237840, -0.333400, 0.656840, -0.596810, 1.157260, 0.296130, 1.015240, -0.408130, -2.864320, 0.334300,
0.550370, -1.627400, 1.121310, 0.175430, 0.228480, -1.204660, -0.989240, 0.089670, 2.908470, 0.533110,
-1.062970, 0.376800, 0.899550, -0.549480, -1.049730, 7.525880, 1.853850, 1.490430, 0.270320, 0.355860,
0.358800, -1.775310, 0.004800, 1.042540, 0.034510, 0.194570, 1.187490, 0.136020, -0.622830, -0.488570,
-0.399130, 0.260450, 0.008200, -0.760500, -0.107970, 0.534890, -1.822720, -1.141680, -0.125810, -0.910210,
-0.479740, 1.552280, 3.007490, -0.072620, -0.903780, -0.697170, -0.093230, -0.340020, -1.532420, 1.479630,
-1.691330, 0.615700, 0.280890, -0.427080, -0.349510, -0.164520, 1.154370, 0.471660, 2.223650, -0.169000,
-1.268770, 0.293180, 0.152350, 0.889090, -0.247050, 0.099390, 0.356960, -2.499460, 0.147750, 1.383580,
0.935920, 0.259830, 1.114170, -0.311400, -1.954050, 0.993330, -1.126550, 1.332160, -0.069130, -1.659190,
0.819300, 0.140170, -1.009430, -1.071600, 0.069290, 0.313470, -0.448750, 0.814800, 1.039520, 0.649080,
-0.969340, 0.112260, 0.663970, -0.770670, 0.095840, -0.774870, 2.757550, -0.621840, -0.466480, -0.854480,
-1.875020, -0.128060, 1.058570, -1.010630, 0.528500, -0.787850, 0.116850, 0.331950, 0.163910, -0.557570,
-1.071390, -0.415600, 1.240240, -1.237900, -0.772470, 0.827880, 0.285100, 0.274590, -0.115670, -0.353030,
0.145820, 0.789670, 1.318870, -1.286800, -1.023830, 0.349030, 0.251020, -0.508600, -0.414290, 0.642020,
-0.664900, 0.569370, -0.011390, 3.539080, -0.041620, 1.449380, 0.167480, -0.898370, -0.523340, -1.735530,
1.947650, -0.922220, -1.589570, -0.274330, 0.572540, -1.038660, -0.748900, -0.022780, 0.578760, 0.143520,
0.715170, -0.421830, 2.868240, 1.284040, 1.090060, -0.541600, 0.823080, 0.416790, 0.694390, 0.064510,
0.837650, 0.977790, 1.067700, 0.650710, -0.535510, 0.226530, 0.319560, 0.726420, 0.975730, 0.358950,
-0.456170, 0.142600, 0.014670, -0.221330, -0.023290, 0.126970, 0.512150, -0.135050, 0.786340,
0.484450, -0.867770, -0.619700, 0.908640, -2.151370, -0.460860, -0.599790, -0.274840, 0.398980, -0.750640,
-0.706960, 0.289790, 0.265240, 1.082230, 0.311580, -1.762530, -0.064380, -0.992750, 0.085610, -0.549310,
1.876610, 1.013890, -0.297950, -0.283200, -0.056820, -0.272580, -1.553400, -0.260340, -0.805370, 0.884650,
-0.355660, 0.946900, -0.848290, -0.908550, -0.439730, -0.633830, 0.115110, 1.296690, -0.467720, 1.617820,
-0.556150, -0.905290, -0.251220, -0.235850, -0.672670, 0.335050, 0.678400, -0.193270, 0.491150, -0.312340,
-0.009450, -0.012490, 1.434830, 1.950840, -1.255790, 0.222460, -0.259790, 0.162360, 0.048250, 2.078860,
1.091290, -0.298480, 1.314830, 0.455030, 0.174810, -0.180940, -0.091060, -0.301290, -0.571570, -0.250180,
0.860370, -1.691080, -0.987930, 0.126850, 0.269830, -0.033870, -0.095470, -0.084970, 0.665190, -0.979960,
0.783800, 0.234630, 2.396690, -0.166190, -0.659070, 0.800710, 0.360320, -0.273690, -1.718190, 1.524580,
0.553690, -0.694650, 1.727020, 0.117410, -0.734210, 0.059850, -0.740010, 0.202870, 0.174090, 0.732700,
0.058710, 0.074870, -0.958770, -0.848980, -0.349520, -0.546320, -0.715240, 0.766170, 0.321660, 0.518530,
0.845130, -1.441380, 0.949390, 0.602350, 0.726460, -2.198630, -0.894640, -3.941870, 4.256390, 2.026780,
0.129940, 3.622550, -2.303480, -0.469870, -6.524600, -0.735880, 1.048320, 1.051150, -2.026840, -0.078420,
0.077560, 0.540040, -4.033160, 0.380070, 0.653200, -4.267760, -2.686940, -0.091110, 0.434780, 0.617500,
-2.191390, -0.468210, -0.245920, 0.854440, 0.631170, 0.210460, 0.146750, 1.007010, 1.211920, -0.655940,
0.079970, -3.271900, 0.781810, 1.361890, -0.468700, 0.553670, 0.302040, -0.528390, -0.735260, -2.658700,
0.077050, -0.999590, -1.469800, 0.546940, -0.006990, -0.413590, -0.166330, 0.042690, -1.563500, -0.389430,
1.016590, -0.179330, -0.138210, -0.299170, -1.039370, 0.272130, 0.763740, 0.496780, 0.007220, 0.557900,
0.159690, -0.033620, -0.195780, 0.035090, -0.252050, -2.196930, -1.382510, 0.480750, -2.338610, 0.375130,
0.308740, -0.886950, 0.482430, -0.274970, 0.624890, -0.940680, 0.537930, -0.640820, -0.284030, 0.788230,
-1.017340, -2.083470, 0.519860, 1.093860, -0.442440, -0.374250, -0.429200, -0.285670, 0.626890, 0.261420,
-1.459290, 0.914220, -0.128090, -0.301880, 0.631620, 0.752810, 0.505310, 0.495760, -0.502720, -0.112960,
1.559440, -0.077180, 0.337010, 1.091220, 0.141490, 0.365210, 0.406390, -0.555810, -0.243190, 0.687450,
0.113570, 0.388930, 1.412990, 0.633450, -1.734570, -0.347580, -0.471230, -1.107010, 1.050780, -0.403710,
0.508990, 0.109270, 0.683910, -0.844410, 0.536810, -0.007580, -0.357190, -1.171680, -0.020030, 0.177250,
3.416210, -1.420600, -1.391170, -17.604389, 0.353520, -1.161190, -1.769790, -0.306930, -1.881790, 1.444080,
0.227290, 1.029370, 3.892910, 1.538730, -0.312800, 0.464540, -0.368770, 0.051340, 0.553850, 0.770820,
0.708130, -0.394860, -3.099560, -0.386900, -1.411410, -0.454660, -0.320380, -0.366880, 0.245130, -0.269070,
-0.108570, 0.024970, 0.492760, 0.520620, 0.638460, -0.239680, 0.141480, -0.460550, -0.965030, -0.966510,
-0.616930, -0.731730, 0.810370, -0.365770, 0.595250, -0.742350, -0.383090, -0.584590, 0.492550,
0.603230, -1.297910, 0.902900, 0.091360, 0.289250, 0.056500, 1.470810, 1.059350, 0.352450, -2.372260,
-0.686980, 1.530870, -0.422140, 0.302770, 1.347180, 1.351220, -1.444380, -0.132560, 0.430250, 1.627330,
-0.941570, -0.047510, 1.170370, -0.403300, 0.073280, -1.503440, 1.794810, -0.215640, 0.744970, 0.558280,
-1.596440, 0.895650, 0.234800, -0.383290, 0.000040, 1.684670, 0.970120, 0.215510, -0.609700, 0.408930,
0.148300, -0.244130, 0.648200, -1.123090, -0.847480, 0.326950, -1.289920, -0.089500, 0.089670, 0.875950,
2.369280, -0.577560, 0.730060, 2.014030, 0.151970, -1.056790, 0.186410, 0.803350, -0.469460, 0.283860,
-0.311660, 2.409190, -0.769750, -1.080630, -1.159090, 0.074000, -0.259120, -1.590490, -0.242490, 0.257030,
0.915450, -2.345510, -1.333340, -0.529230, -1.418520, 0.882090, 0.195270, 0.169300, 0.383800, 0.719790,
-0.440060, -0.224230, 0.439650, 3.842550, -0.133080, 0.511740, -0.391300, -1.145930, 0.759270, -0.042720,
1.155250, 0.496070, 0.229650, 0.164030, -1.748010, -0.778270, -0.488970, 0.397490, -0.007790, 0.427970,
-0.445790, 1.188980, 0.637220, -0.328240, 1.880020, 0.458010, 1.549900, 1.518900, 0.182740, 0.041460,
-0.009850, 0.280570, -0.632460, -0.434240, 0.736340, -0.716520, 0.737040, 0.272560, 0.448850, -2.969640,
-0.906440, 3.276430, -1.391730, -2.585730, -1.719870, -0.582140, -0.479350, 4.553890, -2.143750, -1.012350,
-0.417630, 1.335890, -8.977250, -0.452200, -1.597030, -15.948820, -0.200740, -0.620280, -0.888390, 1.046040,
0.292880, -1.685450, 1.396540, -1.192570, 1.303390, 1.275650, -0.085150, 0.093320, -0.871620, 0.235050,
-0.174410, -0.098940, 2.587480, -1.020920, -0.274330, 0.655460, -2.054810, -0.564890, 1.412590, -0.333200,
0.763930, 0.881960, 0.707330, 0.965600, -0.716170, -1.052510, -0.425080, -0.338760, 0.166920, 0.846650,
-1.925940, 0.833990, -1.529850, -0.657320, -0.239880, -1.259290, -2.339560, -0.245320, -1.249710, 1.350640,
0.806440, 0.209750, 0.251340, -0.244720, -0.405630, -0.688150, -0.504690, -0.358190, 0.118250, 0.722390,
0.221330, 0.807680, -1.073630, -0.372760, -1.026500, -0.461040, -1.879310, 1.337380, -0.373100, 0.427780,
1.263040, -3.961470, 2.214780, 1.478500, -0.237960, -1.327210, 0.076700, -0.890050, 0.684990, -0.664710,
-0.171680, -0.148330, -0.168660, -1.876080, -2.286460, -0.153600, 0.106360, -0.285330, -1.809860, 0.620070,
0.335500, 0.171050, -0.472290, 0.727390, -1.031610, -0.723100, 0.312480, -0.248970, -1.468390, -0.203850,
-0.291460, 0.578260, -0.106180, -0.332100, 1.066390, 0.389050, -1.648440, 0.709300, 0.089240, -2.508850,
-0.861690, 1.337140, -1.334120, 0.985490, 0.019720, -2.998380, 0.614700, -1.436470, 0.814740, -0.313500,
-0.437560, 0.277030, -0.402570, -8.297230, -0.004300, -1.267420, -0.654850, 0.106020, -0.713040, -0.322670,
-0.790280, -0.140100, -0.012580, 1.248650, 0.156780, 1.085770, 0.102490, -1.025720, -0.002060, -1.182860,
0.789600, 0.207820, -0.893810, -0.924070, -0.527710, 0.019960, -1.297870, -0.422340, -1.154290, -1.300030,
-0.569030, 0.363370, -0.947850, 0.883840, -0.001180, -0.624840, -1.090540, -0.713090, 0.324890, -0.122320,
-1.320260, -0.317500, 0.653990, -0.657310, -0.211140, -0.686460, -0.211870, 0.748160, 0.850130,
0.798670, -0.231090, -0.527590, -0.672430, 0.895670, -0.609000, -0.137100, 1.329110, 1.601900, -0.299930,
-0.046890, 0.845280, 0.229000, 0.015640, -0.013470, 0.903740, 0.564080, -1.002260, 0.152270, -0.540330,
0.661450, 1.549130, -0.363540, -0.227900, 0.149860, -0.666000, -0.292040, -1.033710, -0.571660, -0.031590,
1.540520, 1.145220, 1.942930, 0.128870, 1.648650, 0.263620, -0.396890, 0.077740, -0.998210, -1.521140,
-0.150180, 0.783090, -0.017320, -1.234160, 0.571020, -0.689350, 0.256300, 0.303400, 0.798850, 0.059010,
1.849330, 0.051720, -1.426060, -0.317470, 1.334390, 1.029190, -0.291690, -0.619880, -0.579540, 0.750130,
0.265500, -1.687220, -0.667130, 1.132320, -0.552220, 0.146620, 1.681910, 0.486580, 0.088700, -0.769390,
1.243400, -0.842950, 1.251760, -0.654160, -0.976870, 0.731220, -0.514240, -0.264960, -0.425140, -0.881930,
-0.245890, -0.320170, -0.187080, -0.305350, 0.507620, 0.098120, -0.404200, 1.717170, 2.599770, -0.678270,
1.153450, 0.383340, -0.469870, -0.310010, 1.029990, -0.763850, 0.414080, -0.230910, -0.220600, 0.440470,
1.626180, -0.750010, 0.619330, 0.651660, -0.398080, -1.178920, -0.056150, 1.072880, -0.406590, 0.026300,
-0.035930, 0.337960, -1.057750, -0.346330, -0.275370, 0.457720, -0.178890, 0.987850, -0.279560, 0.316810,
0.286040, 0.048630, 2.110700, 0.109940, 0.414510, 0.423690, -0.496760, -0.781530, 0.589950, 0.765040,
0.747950, -0.731340, -0.890320, -0.793090, -0.358570, -0.178460, 3.877940, -0.146040, 1.221520, 0.833830,
-0.450820, -2.312340, -0.257160, -0.533270, -0.857810, 0.297780, 0.800050, 0.691610, -0.144070, 0.047540,
-0.387750, 1.075790, 2.059780, -0.187240, -1.301710, 2.071180, -0.868200, -2.834840, -0.849470, -1.670510,
0.243690, 1.931210, 1.918500, -0.060990, -1.481410, -1.182490, 0.210370, -0.747860, 0.979190, 2.510560,
-0.346150, -2.694870, 0.122890, 0.469300, -0.998280, -1.300630, -0.593380, 0.320900, -0.134050, -0.409150,
-1.779490, 0.205070, -1.004980, -0.764430, -0.919890, -0.318790, -0.601970, -0.029320, 0.644900, 0.505640,
-0.718980, -0.176810, -0.586770, 2.571650, 1.174930, -0.458330, 0.691120, -0.702570, -0.088030, -1.339840,
-0.038760, 3.334910, 0.782640, -1.647690, -0.131650, 1.250280, 1.246480, 1.807870, 0.233110, 1.868060,
-0.362770, 0.680630, 1.181400, -0.847290, 1.256300, 1.810750, 2.950510, -0.527700, -0.596960, -1.819010,
0.735550, -0.507510, -0.597000, -3.804370, 0.822460, -2.619030, -1.265780, -0.191170, -1.820270, -1.080060,
-1.359030, 0.330980, 0.223180, 0.895060, 1.328690, -0.843680, -0.388470, -0.390110, -0.073110, 0.641460,
0.618240, -0.366080, -0.965540, -1.829540, -0.407580, -0.357790, 0.912800, 0.873830, -0.858630, 1.090900,
-0.251800, 0.031110, 0.711790, 2.826660, -0.271670, 0.799520, 0.249240, -1.467040, -0.521330, -0.766480,
-0.134800, 1.527730, -3.639700, -1.529810, -0.211370, 0.599230, 4.953550, -0.259700, 0.687230, 0.564890,
0.174950, -0.560540, -0.240970, 2.677940, 4.038420, -0.551090, 0.282220, 0.156960, 0.237810, 0.738810,
-1.111550, 0.128850, -0.103260, -1.206670, 1.017170, 0.583690, 0.124600, 0.422030, 0.134220, 0.205110,
-0.862180, 0.314680, 0.568450, -0.797440, -0.830820, -0.419910, -0.363700, -0.355460, 0.363000,
0.576540, 1.641770, -0.198020, 0.815020, 0.741520, -0.002610, 0.806290, 0.384540, 0.075090, 0.255020,
-0.367490, -0.046960, 0.116620, -0.518050, 0.624540, 1.844310, 0.899310, 0.593560, 0.915380, 0.427140,
1.050670, -0.228130, 0.891710, -0.410620, 0.036580, -1.293400, -0.198520, 0.159030, -0.448650, 0.649550,
0.071740, 1.504460, 0.550380, -0.217650, 0.641420, 1.171010, 0.407510, -1.659020, 0.730250, 2.129080,
1.128520, 1.718600, -1.220500, -0.278440, -0.767260, 0.632380, -1.282740, -0.116140, 0.090560, -0.508730,
-0.916300, 0.585430, 1.007900, 2.156640, -0.473800, -0.760590, -0.228310, -1.126430, 0.205860, 1.208330,
-1.269760, 1.136870, 0.734530, -1.362100, 0.745370, -1.623840, 0.684850, 0.438980, -1.540630, -0.320760,
-0.239510, 1.282060, 2.044130, 0.514770, -0.133630, -1.252740, -1.533230, 1.687020, -0.200040, 1.118740,
0.006180, 1.195410, -0.770630, 1.112570, -0.123050, -0.703800, 0.285170, 2.868070, -0.766170, 0.145690,
-1.431840, 0.406670, -0.510720, -0.191440, 1.160450, 0.609270, 1.326680, 0.270230, 0.041380, 0.152580,
0.299570, 0.231880, -0.642280, 0.339790, 0.463600, 0.820950, -1.331090, -0.063690, -1.860880, 1.068990,
1.537810, -0.023000, 0.519980, -0.031540, 0.115270, -0.859700, -0.456810, 1.184390, 0.072680, 0.983690,
0.680960, 2.108150, 0.679260, -0.991360, -2.641700, -0.139190, 0.025860, 3.121320, -0.318830, 0.024270,
-1.170500, 2.410620, -2.666960, 1.167340, -0.220350, -1.374760, -0.117980, 0.696120, 0.670410, -0.376600,
-1.236460, 0.890140, -1.716100, -0.287290, 0.354610, 0.527580, -0.746400, -0.142600, -0.312820, 2.177990,
0.745550, 1.200910, 0.996850, -0.079360, 0.985970, 2.115900, 0.063040, 1.574590, 0.736240, -0.947460,
-0.573210, -0.381970, -0.499520, -0.327930, 0.268330, 1.706090, -0.553030, -0.847100, -0.481370, 1.110250,
0.911820, 0.387170, 1.122650, 0.424870, -1.209070, -0.242150, 0.989180, -1.435710, -0.187410, -0.286230,
-0.850750, 1.338330, -0.712470, -0.019990, 1.099310, -0.427420, 0.602410, 0.275470, 0.071780, 1.026670,
-0.983160, 0.046400, 1.224310, 0.181760, -0.503830, 2.262640, 0.220430, -0.250680, 0.206760, -0.011170,
0.435730, 1.266960, 0.496910, 1.127210, -0.207580, -0.818040, -0.957680, 0.933290, -0.200750, -1.216400,
1.582020, 0.704340, 0.641240, -1.890240, -0.448310, 0.595730, -0.061600, -0.333890, 0.978110, 1.504000,
2.401870, 1.146920, -0.285490, -0.573120, -1.405800, 1.778480, 1.415120, -0.230420, -0.424130, 0.061470,
-0.632710, -1.040200, -0.098730, 0.912340, 0.004810, 0.568650, 0.168590, 2.441280, -0.024820, 0.869380,
0.980960, -0.829790, 0.075000, 0.530170, -0.729550, 0.356980, -0.910620, -0.319250, 2.462210, 1.411180,
0.643820, -2.109730, -1.472950, 3.524080, -0.449640, 2.417500, -0.175670, 0.914700, -0.619690, -0.279060,
0.230080, 1.017200, 1.141280, -0.062490, -1.247620, 0.488500, -0.024810, -1.333190, -0.360190, 0.014890,
-0.480430, -0.104380, -1.386670, -0.855700, -1.009560, -0.213890, 0.761810, 0.713540, -0.624780, 0.072180,
-0.073250, -0.581600, -1.424910, -0.706160, -1.133360, 0.209680, -0.450810, -1.428130, -2.026670, -1.149760,
0.469320, 0.164070, 0.253850, -0.809390, 0.138580, 0.105210, -0.051510, -0.487650, 0.374030,
-0.246180, 1.588440, 0.725400, 0.408590, -0.217550, -0.708130, 0.011740, 0.307950, 0.974630, -0.612440,
1.642870, -1.066490, -1.414710, -0.434110, 1.479720, -0.254070, 1.028840, -0.282660, -0.009990, -1.420180,
1.750690, -1.271050, -1.051510, -0.474610, -0.499090, -0.747940, 0.033920, 0.045300, 1.041470, -1.346670,
-0.573740, -0.620250, -0.833770, -0.518280, 1.492180, 1.133930, 1.007060, -2.180040, 0.019540, -0.477560,
-0.799180, 0.816540, -0.859270, 0.316620, -1.601720, -0.556280, -0.200030, -0.158380, -0.722650, 1.255380,
-0.069810, 0.430980, -0.159570, -0.594220, 0.060760, 0.800630, -1.191600, 0.596910, 0.451980, -0.087570,
1.167210, -0.654580, -0.929790, 0.720190, -0.669000, -1.571420, -0.302120, 0.117220, -0.547550, -0.596520,
0.117610, 0.223630, 0.761990, -1.634900, -0.246210, 0.286410, -0.498490, -0.767560, 1.505840, -0.523630,
0.418100, -0.303110, -0.169220, -0.183720, -0.522020, 1.658420, -0.751070, -1.127470, 1.500950, 2.525250,
0.270110, 0.648120, 0.206100, -0.551680, 1.364240, -1.581430, 0.379650, -0.196700, 1.264520, -1.537180,
2.459070, 1.150210, -0.294540, -1.152030, 1.804720, -0.251280, 0.186430, 0.005970, -0.896980, 0.737150,
-0.648590, 1.765530, 1.214110, -0.000480, -0.399770, -1.655400, -0.313720, 0.377380, -0.098320, -1.279480,
0.358760, 2.653240, 0.452410, -0.005870, -2.305300, 0.703320, -0.190420, -1.107940, -1.021380, 0.232460,
-0.068690, 1.081660, -3.671930, 0.572370, 0.995050, -5.839330, -0.389790, -0.558900, 0.437920, 0.787230,
-1.499270, -1.145630, 0.921510, -1.779870, -0.712930, -0.202480, -0.262260, 0.720190, 0.213740, -1.992880,
1.128460, -0.180840, 0.764020, 1.116580, 0.375090, 0.444220, -0.756880, 0.712730, 0.797490, 0.083520,
0.201490, 0.526080, -0.158350, 1.134210, 0.290450, -0.292940, -0.624750, -1.693430, -0.896880, 1.994370,
-0.059930, -0.066490, 0.494740, -1.131690, 1.028380, -0.443720, 1.917020, 1.518670, 0.068470, -0.971630,
2.229300, 0.599150, -1.153450, 0.360440, 0.444330, -0.228920, -0.017510, -1.471030, -0.071770, 0.352180,
0.378900, 0.055030, 0.921050, 1.482890, 0.464050, 0.628790, 1.494980, -0.069890, -0.800110, 0.058080,
-0.560820, -1.053190, 0.328560, 0.261410, -0.515670, -0.059690, -0.109760, -0.195610, 0.242380, -0.990730,
-0.156970, 0.400300, 0.700360, -0.388590, -0.028510, -0.279710, -0.338910, 2.039300, -1.202160, 0.688590,
2.808900, 1.439140, -0.179960, -0.429980, -0.977390, 1.406810, -0.326050, -0.619730, -0.735430, 0.863360,
2.312660, -0.615560, -0.232740, -0.117400, 0.850990, -1.113760, -0.102280, 0.966300, -0.584000, -0.440740,
0.237690, 0.681670, 1.055100, -0.943090, -0.369050, -0.243190, -0.618280, -2.121850, -0.390260, -0.823320,
1.858040, 0.189190, -0.718540, -0.033980, 0.450710, -0.549110, 0.910830, 0.342650, -0.498210, 1.351090,
0.183500, 0.765810, 1.091280, -0.225020, -0.772690, -0.210270, 0.377710, 1.118510, -0.543500, -0.033900,
-2.304580, 0.331620, 0.112970, -1.342800, -0.303630, -0.419300, 1.156290, 0.395600, -0.051840, -0.185470,
-0.747630, -0.180070, -1.185920, 0.345190, -0.495050, -0.300210, 0.333950, 0.274430, -0.116840, -0.534460,
0.074050, -0.428650, 0.204750, -1.138720, -0.998070, 0.312630, 0.936990, -0.237800, 0.728320,
0.016760, -0.152320, -0.518800, 0.248730, -0.116150, 0.747290, 0.076300, -0.771570, 0.322230, 0.668950,
-0.664920, 0.848750, -0.485110, -0.286280, -0.256220, 0.377380, 0.308900, 1.265150, 0.645520, 2.944950,
-2.213930, -0.673480, -1.468480, 0.525270, -2.451580, 0.148020, -0.261510, 0.116580, 0.903520, 0.894150,
-0.407810, 0.320120, -0.367220, -1.636710, 1.273900, 1.116490, 0.227740, -0.025600, 0.631210, 0.437300,
-0.239640, 2.153750, -0.223750, 0.071220, 0.011730, -3.115320, 0.458040, 0.813560, -0.855850, 0.097380,
0.737430, -0.509030, -0.415610, 0.704510, -0.115450, -0.046270, 1.090570, 1.925330, 0.099620, -1.747870,
-1.171140, 0.023860, -0.551480, 0.997160, -0.915350, 0.600870, -0.474360, 0.379930, -1.351440, 0.225670,
-0.099630, -0.181650, -0.942580, 0.686420, -1.086360, 1.216340, -0.134970, 0.649030, 0.234810, -0.769290,
-1.043960, 1.758740, -0.258730, 0.507940, -0.036050, -0.161300, 0.381420, -0.616220, -0.099300, -0.776230,
0.360330, -1.565050, 0.712360, 0.403360, 0.780850, -1.721580, 0.093450, -0.548870, -0.284400, 1.051670,
-1.056530, 0.341320, 0.060640, 0.129710, -0.191310, 1.165980, 0.546390, 0.411470, -0.673210, 0.007430,
-0.080040, -0.304310, -2.350370, -0.039360, 0.928500, 0.222420, 0.914860, -1.866940, -3.524110, 0.245350,
-0.004470, -0.074400, -0.260760, -0.556080, -0.550900, -0.125390, -1.065830, 0.356510, 0.916740, -0.390780,
0.167380, -1.027980, 1.981100, -0.616950, -2.356510, 5.108030, 1.135430, -3.144480, -0.621050, -0.102690,
-0.767650, 0.392950, 0.165940, -0.089610, -0.484220, 0.039290, -0.098100, -0.238080, -0.016470, 0.585520,
0.689820, -0.656060, -0.395760, -0.093660, 0.245880, 0.210790, 0.412620, -0.565950, -0.526510, 0.502960,
-0.118360, 0.269680, 0.697770, -0.689420, -0.170920, -0.283080, 0.578040, -0.221490, 1.161780, -0.450090,
1.372600, -0.239520, 0.704380, -0.499720, 0.674320, -0.863280, -1.279520, 0.138600, 0.070510, -1.362550,
-0.374320, -0.139720, 1.623610, -0.809970, -0.361000, 2.330530, -1.004650, -0.678720, -1.445200, 0.060250,
-0.997020, -0.915570, -0.402650, -1.065130, 0.891880, -0.273420, 0.555250, -0.341910, -1.389950, 0.207650,
0.938640, -0.535380, -0.486560, -0.783540, -0.944870, 0.014090, -2.600790, 0.166180, 0.243820, -0.228280,
-1.164720, -0.473200, -0.362690, -0.780730, -0.399740, -0.517060, -1.790740, -0.024890, 0.096420, -1.319030,
-1.114170, 0.895510, 1.295260, 0.711060, -0.888580, 1.287890, 0.424950, 1.421020, -0.186130, -2.002410,
0.793550, -1.102920, -0.304510, 0.478560, -0.045940, 0.459010, 0.351550, 1.629480, 1.473190, -1.453770,
1.329350, 0.575430, -1.462020, 0.078390, -0.084550, -1.760560, -0.556630, 0.052260, -0.505100, -0.264100,
-0.933340, 0.088220, -1.707730, -0.837970, 0.354820, -0.162840, 0.514480, -0.186070, 0.431580, -1.485170,
2.099020, -1.491150, -0.742710, -1.027010, 0.558240, 0.033200, 0.827310, -0.397650, -0.909090, -0.999140,
0.414360, -0.802910, 0.487920, 0.296760, -0.627790, -0.422770, -0.634670, -0.452660, -0.962590, -0.328940,
-0.480740, 0.187440, -0.590860, -0.237030, -0.812490, 0.109100, -0.774250, 0.616400, -0.252470, 0.416170,
0.481350, -0.486150, -0.362030, -0.604370, 0.656720, -0.350580, -0.394240, -0.116190, 0.535780,
-0.140010, -0.652540, -1.205900, 0.958800, -2.265700, -2.173570, -0.153710, -0.815340, -0.468340, 0.487610,
1.783890, -0.974720, 0.785810, -0.326200, 0.905670, 0.589860, 0.573400, 1.538920, -0.121540, -3.133670,
0.246500, 0.896530, -0.334960, 1.510330, -2.091480, 0.630800, 0.742950, -0.937570, -0.917250, -0.234080,
0.206240, -0.480220, -1.088680, 0.456000, 0.720290, 0.178060, -0.216820, 0.923520, 0.738020, -0.646920,
-0.682650, -0.768200, -0.673720, 0.285910, 0.281340, 1.304250, -0.898420, -0.761960, -0.046720, -1.281750,
-0.170590, 0.467450, 0.285610, -1.203580, -1.988830, 0.553200, 0.977630, -0.497940, 0.695870, 0.431720,
0.390890, 1.161660, 2.085100, -0.252920, 0.712140, -1.171360, -1.245280, 0.426100, -3.545860, 0.324330,
-1.163360, 0.841480, -0.733980, -0.914870, -1.056040, 0.358250, 0.232000, 2.057250, -1.155900, -0.457640,
0.640050, 0.146720, -0.912850, -0.518070, 0.982400, 0.157200, -2.164460, 0.559670, 0.522030, -1.070950,
0.758750, 1.293290, -0.704870, 0.266150, 0.294350, -0.635920, 1.111220, 1.259290, 0.989960, -2.575360,
1.072760, -0.852630, 1.245840, -1.031620, 0.336390, -1.005280, 1.082970, 0.499970, -0.516510, -2.137820,
-0.139120, -0.256860, -0.196830, -0.025470, -2.746650, -0.006040, 0.444170, -0.043950, -2.724460, -0.681350,
0.850730, -1.221210, -0.607320, 2.211280, 2.069720, 0.601400, -0.820770, 1.161080, 0.193180, -0.612900,
-2.727780, -0.739200, 2.471550, -0.907340, -0.868620, 2.633830, -0.617350, -6.344980, 0.149290, -0.993000,
0.368950, -2.577460, -1.331400, 0.545580, 0.182790, -0.161330, 3.408370, -0.400630, 1.377460, -0.369220,
0.321410, 0.022220, 0.317580, 2.335930, 0.071130, 2.106960, -0.134430, 0.394840, -0.494760, 0.489650,
-2.883940, -0.294670, 1.916810, 0.450480, -0.501650, 0.089790, 1.447440, -0.005460, 0.348260, 0.242580,
-1.806770, -0.733110, 0.914640, 1.230870, -0.710460, 0.281210, -1.712280, -0.344010, 0.868830, -0.356400,
-0.449690, 0.166250, 0.487620, -2.319680, 0.711950, 0.922820, -0.584730, 1.020720, 0.100830, 0.224010,
-0.335880, -0.265080, -0.869890, 0.009950, 0.470440, -0.099570, 0.000710, 0.314230, 2.692800, 0.953480,
0.575790, -0.650080, 0.025240, -0.513720, 0.041080, 0.484430, -0.679990, -1.118610, -1.611610, -0.437650,
0.229390, -0.471210, -0.311830, -0.557480, -0.964050, -0.315830, -0.373770, -0.552520, -0.362610, -0.272480,
0.796990, -0.828040, -1.488680, 0.004120, 0.651000, -0.480800, 0.180650, 0.628700, -2.014280, -1.902790,
0.066150, 2.013380, 2.196870, 0.630100, -0.795500, -0.829560, -0.871850, -0.606080, -0.028080, 0.114540,
0.373010, -0.690640, -0.022890, 0.488530, 0.771300, -0.360610, -0.746250, -0.508670, 0.430840, 0.086300,
-0.814170, -0.066280, -0.101280, -5.277690, 0.159460, -0.597140, 0.642290, -0.829650, 0.226930, -0.129440,
-5.193590, 0.945550, -1.241120, -0.945700, 0.556380, -0.287360, -0.069830, -0.118660, 0.748660, -0.821620,
0.757980, 0.460560, -0.048840, 0.041300, -0.389530, -1.182730, -0.865600, -0.950970, -1.205470, 0.332470,
-1.192000, 0.626530, 0.114690, -1.529780, -0.957020, -0.008030, -0.574960, 1.470910, -1.323030, 0.563880,
-0.929350, -0.994090, -0.634690, 0.577580, 0.133830, 0.368780, 0.513640, 0.593440, -0.501270,
1.744590, -0.484870, -0.678610, -0.763570, -0.179150, 1.028870, 1.127480, -0.548410, 0.109180, 0.507000,
0.003060, 0.626040, 0.613330, 0.240690, 0.178430, -0.638230, 0.200660, 0.699330, -0.315700, 0.096030,
-0.850550, 0.406930, -1.344670, -1.210880, 1.157840, -0.426830, 0.308950, -2.319210, -0.970050, 0.052670,
0.286060, 0.442430, 0.205120, 0.888630, 0.925620, 0.575080, 1.611050, 0.769760, 0.278570, 0.903890,
1.474780, -0.023090, -0.383560, -1.833540, -0.943470, 0.430960, 0.718460, 0.245940, 0.788390, -0.260730,
1.213820, -0.349000, -0.699320, 0.820110, 0.800050, -0.705950, -1.251080, 1.431150, -1.600720, 0.148100,
0.898110, 0.579860, -1.402890, 1.492100, -0.233760, -1.264940, -0.946470, -0.022720, -1.732930, 1.101370,
-0.370040, 0.407860, 0.880280, 0.270620, -0.032060, -1.373640, -0.780120, -0.100800, -0.816350, 0.156820,
0.559410, -0.006960, -0.364050, 1.586700, 0.429110, 0.792950, 1.268160, 1.065060, 0.605500, -3.087760,
0.382380, -0.771380, -1.323450, 0.332670, 0.676070, 2.517820, -0.901580, 0.054750, 2.457620, -0.734110,
0.590460, -0.753780, -0.202290, 1.099150, 1.295570, -1.831600, -0.931030, 0.493600, 0.578700, 0.269970,
-0.280760, -0.177370, -1.152120, -0.118050, -0.355980, -0.295090, 2.825990, -0.061600, 1.113900, -1.289250,
-0.440710, -0.338320, -1.182390, -0.196270, 1.155620, 0.701420, 0.449370, -0.733030, -0.847110, -1.001260,
-0.414480, 0.092090, 2.099740, -1.205800, -0.623340, 3.644930, 0.412730, -2.838110, 1.295520, 0.728900,
0.869740, 0.780110, 0.901340, -0.741560, 0.520050, -0.637070, -1.044090, 0.389280, 0.294010, 0.619180,
0.507070, 0.340330, 0.527520, -0.665160, 0.128680, 0.039860, 1.523930, 0.661220, -0.313440, -0.447930,
-1.425370, 0.031720, -0.082940, 0.726980, 0.226840, 0.423490, 0.838310, 0.862730, 1.607310, 1.736400,
-0.496690, -0.048720, -0.507880, -0.389780, 0.789370, 0.335020, 0.555760, -0.705990, 0.348900, 0.576240,
-0.074150, -0.534710, 1.425690, -0.551920, -0.201840, -0.181640, 0.426910, -0.162890, 0.220470, 0.110610,
-0.241900, 0.788610, 0.912990, -0.594070, -0.865430, 0.476790, 0.361290, 0.452560, 1.158490, 1.217340,
-0.979560, 0.300140, -0.372570, 2.422670, 0.701350, 1.149090, -1.138030, -0.482480, 0.917260, -1.057940,
0.048950, 0.746330, -0.177930, 2.840680, -1.104370, 0.453620, 0.986050, -0.407840, 0.242960, 1.559400,
-1.079760, 0.876350, -0.961700, -0.830840, 1.630980, -0.345140, 0.383030, 0.989310, 0.559920, 0.224600,
-0.002120, -0.698210, 0.780570, -1.873910, 0.608320, 1.513010, 0.682300, -0.500890, 0.290070, 0.759310,
0.114200, -0.065570, 1.246070, -0.626090, 1.476410, 0.674030, 0.155890, 0.237150, 1.166990, -0.365500,
-1.173800, 1.180710, -0.268800, 0.174320, 0.084740, 1.110380, -0.050030, 0.203540, 1.041750, -0.171240,
0.006710, -1.536950, -0.382000, -0.560310, 0.487870, -0.131720, -0.766420, 0.825040, 0.925700, -0.413030,
0.073330, 0.631210, -0.088230, 0.074370, 0.232470, -0.901850, -0.682680, 0.682990, -0.425790, -0.842070,
0.195040, -0.772980, 0.598350, -0.840740, 0.302100, -0.222190, -0.778840, 0.529210, 0.786080, -0.611870,
0.569680, -0.489680, -0.794390, -1.096360, -0.364470, -0.758150, -0.866920, 0.467560, -1.103640,
-0.066880, -0.161690, -0.492250, 0.664740, 0.671320, -0.271000, -0.680330, -0.615200, -0.432040, 0.422250,
0.832330, -0.318150, 0.202280, -0.357780, -1.447810, -1.413300, 0.476480, 0.431420, 0.551940, -0.116110,
0.825430, 0.932440, -0.571010, 1.607500, -1.073240, -0.474100, 1.313470, -0.923870, -0.015910, 1.670440,
1.850890, 0.477230, -0.405710, -0.534040, 0.830950, 2.333580, -1.816480, 1.160220, -0.904530, -0.910460,
-0.273450, -0.266460, -0.623350, 0.207740, 0.380460, -0.155460, -0.016870, -0.427840, 0.379950, -2.056480,
0.622170, -0.403610, 0.516060, 0.759210, -0.021770, -1.220330, 0.883680, -1.776000, -0.521440, 0.508500,
-0.559070, -0.825680, 0.530990, 0.274200, -0.254050, 0.600940, 0.466670, 0.803160, -0.536770, 1.141320,
0.725380, 0.875540, -0.187490, -0.356990, -0.282100, 0.122050, 0.369950, -0.330020, 0.742100, -1.242280,
0.348250, 0.434330, 0.161090, 0.848600, -1.756310, 0.438590, -0.104780, -0.387600, -0.284910, 0.705450,
-0.702750, -1.651200, -0.305840, -0.624170, -1.132270, 1.242960, -0.058080, -0.456640, -0.341180, 2.260200,
-0.336910, -0.892810, 0.500100, 0.922830, 0.790450, -0.361540, -0.363530, -0.869920, -0.384930, 0.458370,
-0.910150, 0.235230, 1.170290, -1.072800, 1.511960, -1.001750, 0.704230, 0.390060, 0.173370, -1.253520,
-1.151100, 0.498280, 3.012310, -2.383090, -1.612640, 1.296800, -0.160320, -0.049730, 0.539460, -0.886970,
0.177050, 0.199790, -2.158700, 0.746430, -0.470190, -6.517680, 0.005720, 0.822040, -0.513380, -2.746330,
-0.148220, -0.651870, 0.222580, 0.296790, 1.002300, -0.768770, -1.161670, -1.134140, 0.085120, -0.082090,
0.364700, -1.316930, -0.194740, -2.486030, -0.825710, 0.119560, 0.733660, -1.399110, -0.659120, -0.426410,
0.378860, -0.269160, -1.504910, 0.017490, -0.691390, 0.979780, 1.000270, -1.038790, -0.038520, 1.078550,
-0.341660, 0.445860, -0.065960, 2.579160, -1.058880, 0.121210, -0.201830, 0.353770, -1.248170, -0.582140,
1.480960, -0.022980, -0.776330, -1.026470, -0.213830, -1.251330, 0.056980, 0.206030, -0.890040, 0.753430,
-1.354990, 0.838540, -0.572070, -0.985770, 0.472080, -0.289600, 1.190710, -0.274760, -0.359400, -0.936240,
0.076380, -1.964880, 0.206550, 1.034240, 1.240770, -1.697890, 1.007830, 0.711810, -0.653340, -0.727120,
-1.884260, -0.355840, 0.427080, -0.777560, 0.793890, -0.463220, -0.202850, 0.166730, 0.735970, 0.818740,
1.405500, 0.282240, 0.405190, -1.274720, 0.016170, 0.995620, -0.164620, 1.003070, 1.377970, -0.661130,
-0.128620, -2.117030, -0.410120, 0.167520, 0.053160, -0.513590, -0.856680, 0.109440, 0.543170, 0.375760,
-1.484430, 0.441280, -1.217060, 1.043200, 0.138340, 0.004370, 0.756760, 0.542310, 0.262510, 0.878500,
0.803170, 0.072710, 0.202420, 15.634190, -0.958710, -0.147910, -0.361140, -0.981120, -0.084900, 2.627360,
0.381970, -0.434090, 2.626050, -0.270260, 0.058830, -1.913700, 0.406850, 0.701020, 0.073050, 0.922010,
0.800580, -0.255590, 0.230780, 0.223610, -1.051100, 0.690490, 0.073310, 0.899580, -0.834530, 0.746620,
-0.390590, 1.505870, 0.126310, 0.642310, 0.102810, -1.003390, 0.164930, 0.840910, 0.897570, -0.254500,
-0.858380, -0.403950, -1.046880, 0.166520, 0.721480, 0.803220, -0.155350, -0.344460, 0.667230,
0.619050, -0.599970, -1.108300, 1.666670, 0.837920, 1.773030, 0.737820, -1.196780, -1.288250, -0.327320,
0.645860, 0.345460, 0.775830, -0.545400, 0.516590, 0.617340, 0.217670, -0.116180, -0.355860, -0.025690,
-0.052330, -0.420390, 0.062590, -0.553480, -1.477530, 0.850410, -0.259910, -0.485880, 1.332110, 0.741400,
0.669950, 0.315770, 5.486880, -1.721960, -0.676820, -0.189990, -0.863800, -0.277110, -0.205650, -2.537120,
-1.818490, 2.076490, -1.637140, -1.015460, 0.357970, 0.495620, -0.995270, -0.445260, 0.150480, -0.212080,
0.741580, 1.665500, 2.639810, 2.231370, -0.782000, 2.755430, -0.301930, -0.880560, 0.177470, -0.531640,
1.557180, -0.194330, 0.454150, 0.413600, -0.489810, -0.319700, -0.618940, 0.773410, 0.779840, -0.244690,
1.836690, 1.369410, 1.784430, 0.446050, 0.241700, 0.170000, -0.029650, 0.464150, 1.397880, -0.622340,
-1.113330, 0.629390, 0.679070, 0.483420, -0.497470, 0.757470, -0.906630, 0.183640, 0.236930, 0.237800,
-0.365820, 1.586020, 0.395170, 1.513160, 2.583850, -0.097310, -0.471160, 0.366670, 1.258980, -0.799110,
0.391210, -0.547530, 0.582810, -1.383200, 0.079030, -3.147020, 0.063320, 0.329600, -1.017910, 0.367750,
-0.466180, -1.884300, -0.149640, 0.834990, 0.110310, 1.135220, 0.567500, 2.067530, -5.485320, 2.816110,
1.201090, -2.380600, -0.164110, 1.458420, 3.558040, -0.512820, -1.914070, -1.622230, 0.345420, -0.923240,
-5.175680, -2.288050, 3.510710, -1.398350, -1.844640, 3.191300, -0.673650, -0.102360, 1.044450, 0.773050,
-0.154660, -0.843360, 0.566180, 1.841950, 1.210720, 1.239140, 0.764440, -1.224170, -0.514590, -0.982680,
-0.079910, -1.559730, -0.497750, -1.427200, -0.668470, -0.151390, 1.020620, -1.799120, -1.353630, -1.166690,
0.762850, 0.329000, 1.543440, -0.338910, 0.546700, 0.229580, -1.090230, 0.389460, -1.361280, 1.510940,
0.065020, -1.992700, -1.897910, -1.111540, -0.494060, 0.981940, 0.455860, -0.309520, -0.580540, 0.485160,
0.554020, -0.285740, -0.913860, 0.440410, 0.098230, -0.655440, 0.703060, -0.434890, 1.138060, -0.785350,
-0.707900, 0.082590, -0.285130, 1.462020, -0.646920, 0.039360, 0.421100, -0.116270, -0.566270, 0.586890,
-0.627770, 0.442240, -0.451960, -1.066730, -0.335580, -0.193990, -1.203460, -0.686420, 0.952280, 0.649140,
-0.841160, -1.340090, -1.552720, -1.780820, 1.303850, 0.392830, -0.649430, 1.642540, 1.030810, 0.794710,
0.777980, -0.119260, 0.575590, -0.912680, 1.445180, -1.232500, 0.136850, -0.062460, 0.322880, -0.374760,
0.119030, -0.249010, -0.112760, 1.100300, -2.291700, 0.088050, 0.015880, 1.302110, 0.808960, 0.515900,
2.021650, 0.567600, 0.201410, -0.110920, 1.515220, -0.641410, -0.526280, 0.277210, -2.148390, -0.085510,
-1.350120, -0.011540, -0.429190, 3.211920, 1.256120, 0.480720, -0.748930, -0.206370, -0.981220, -0.433470,
-1.376120, -0.526210, -2.075930, -1.033450, -0.324630, -0.722150, 1.521280, -0.226490, -0.773290, 0.203870,
-0.094670, -0.529000, 1.290110, -0.533300, 0.275020, 0.091280, 0.138060, 0.168620, -0.611660, 0.122830,
-0.057160, 0.418620, 0.475640, 0.594550, -0.211190, -1.169950, 1.560000, -1.162930, 0.301420, 0.785720,
-0.486350, 0.949460, 0.191170, -0.432650, -0.557370, -0.653780, -0.087480, 0.206580, -0.768930,
1.161940, -0.036260, -1.074300, -0.187120, 1.119610, -0.679450, 0.770850, -0.142380, -0.142220, 0.480010,
0.303790, 0.749900, -0.359650, -0.118820, -0.234770, 0.411700, 0.043280, -1.269750, -1.406030, 0.515330,
-0.533690, -0.238420, 0.783490, 0.264960, -0.302810, -2.381690, -0.089410, 0.137630, -0.968210, -0.976090,
0.107700, 2.230930, -0.373020, 1.525630, 1.825430, 1.086730, 1.719290, 1.022560, -0.548660, -0.881250,
-0.785280, 0.443390, 1.066510, -0.082070, 0.272060, -0.507960, 1.680030, 1.553780, -0.234980, 0.210770,
0.609090, -0.195460, -1.677210, -0.227190, -0.833070, -0.225020, -0.834570, 0.142830, -0.767640, -1.094720,
1.496010, 0.509910, -1.365770, -0.363950, 1.691360, 0.448770, -0.606200, -0.743640, 1.075310, -0.204470,
0.901510, 1.177500, 0.785010, 0.025680, -1.182630, -1.517350, -1.110300, 0.622250, 1.776250, 0.601140,
-0.577880, -0.784840, 0.037590, 1.287740, 1.788320, 1.482940, -0.077320, 0.012740, 0.187250, 0.536090,
0.175090, 1.469010, -0.220950, 3.058610, 0.692330, 0.987080, 0.200970, 0.052360, -1.375870, 0.183480,
0.811370, 0.304810, 0.682330, -0.169350, 0.984230, 0.555520, 0.232950, 0.000520, 0.380730, 0.532440,
-0.073790, 0.460670, 0.334270, 0.571950, -3.070350, -1.419470, -1.823410, 0.891310, 2.421970, -2.331500,
-1.024120, 1.799330, 0.381430, -11.871260, -5.322190, 0.651140, 1.757480, 0.358940, -1.690800, -0.109370,
0.915130, -0.049740, -5.689490, -0.372450, 0.540980, -3.719210, -2.736320, 0.902410, -0.684520, 0.378610,
0.405680, -1.030560, 0.566960, 1.381560, -1.392420, 0.781870, -0.192620, -0.477340, -0.406200, -0.489030,
0.807150, 0.507640, 0.768290, 0.230560, -0.887220, -0.723180, -0.611480, -1.043130, 0.556430, 1.714290,
0.600830, 0.644720, -0.262880, -0.353390, 1.831240, 0.465100, -0.807250, -0.626080, -0.831110, 0.391170,
-0.585420, 0.064800, -0.091330, -0.039500, -0.349980, -0.534450, -0.347410, -0.602060, -0.356790, -0.333330,
1.088170, 1.545680, 0.450660, 0.012300, -0.069960, 0.133260, -2.187490, 0.477460, -0.822310, 0.461910,
-0.289570, -0.292590, -0.722540, -0.996980, 1.334350, 0.188660, -0.784810, -0.353720, 0.350050, 1.040660,
0.168190, -0.434380, -0.350320, -0.228400, 1.287720, -1.240970, -0.194480, -0.565860, -0.490140, -0.930780,
1.091750, 1.571110, -0.265440, 0.578190, -1.266240, -0.270940, 0.683590, -0.505530, 0.409710, 1.075200,
1.145980, 0.206330, 1.057640, -0.536010, 0.458050, 0.673280, 0.646370, 1.073700, -0.500950, 1.030730,
-0.967840, -0.313930, -2.385960, 0.338000, 0.575420, -0.273880, 0.045970, -0.742070, 0.618080, 0.592380,
-0.451460, 1.338620, 1.314510, 0.106960, 0.084300, -0.622970, 0.939220, 0.784540, 0.246620, -0.792960,
4.357280, -0.410570, -0.748830, 10.724130, 0.136930, -0.212720, 0.202680, -0.988670, -0.368490, -0.192640,
0.001300, 0.352330, 0.722990, 1.472450, 0.136800, 0.308160, 0.434380, -1.516180, -1.007920, -0.715580,
-0.562270, -0.696180, -0.548360, 0.194060, -0.469860, -0.670130, -0.736390, 0.380940, -2.747130, 0.127010,
0.581260, -0.250640, 1.175180, -0.686710, 0.099560, -0.281410, 0.576140, 0.655370, 0.165740, 0.556630,
-0.839580, 0.238550, -1.108200, -0.246680, -0.695460, 0.587940, -0.814250, -1.327070, 0.762640,
-0.314670, -0.400020, 0.063580, -1.682200, -0.867380, 1.731540, 1.331210, 0.091350, -0.660500, -0.127770,
0.531230, 1.499420, 1.700340, -0.564630, -0.412210, -2.814280, -1.158340, -0.852740, -2.294350, -0.579300,
0.034580, 0.464410, 1.027010, 1.344750, 0.760890, 0.451120, 0.710180, -1.170250, -0.691460, 0.043980,
-0.272420, -0.671380, 1.342390, 0.790080, -0.226160, -0.379780, -0.562240, -0.993350, 0.143820, 0.213510,
0.017430, -0.275530, -0.323960, -0.579720, 0.253730, 0.700090, 0.293100, -0.090420, 0.409320, 2.235040,
1.103870, -0.289610, 0.268920, -0.107700, 1.606120, 0.386460, -0.206270, -1.512010, -0.016540, 0.759570,
1.643520, 1.252950, -0.526840, 0.437190, 1.808110, 0.720580, -0.262380, -0.771770, -1.153760, -0.021040,
-0.398440, 0.631740, 0.409310, 0.977460, 1.231970, 2.241270, 1.304160, -0.272920, 0.854850, -1.067130,
-0.218000, 0.924320, -0.979720, -0.309390, 1.274070, -1.620010, 0.110730, -1.056970, -2.800590, -0.791370,
-0.986920, -1.422800, 0.122220, -0.869320, -0.231400, 1.515880, 2.048760, -1.370400, -0.681680, 1.329120,
-0.539210, -0.509990, -0.617080, -0.196200, 1.261010, 0.970630, 0.260860, 1.264720, -0.515640, 0.851810,
0.622290, -0.583700, -0.514740, -0.303670, -2.105180, 0.599260, 0.011290, 0.955620, 3.343870, -0.317080,
1.221500, -1.843420, 2.231220, 3.277450, -0.121920, -1.399990, -0.854560, 0.207060, -0.645720, 5.469200,
-1.797840, -1.255420, 0.429020, -1.552640, -1.036930, -0.030450, -0.490570, -0.907550, 2.316140, 4.966610,
1.111970, -2.164420, 0.654950, 0.075610, 0.978290, -1.643710, 1.369090, 0.169290, 0.067570, 0.353060,
1.007260, 0.360890, 0.580620, 1.148980, -0.305760, 2.397190, 0.441000, -0.167840, 0.325270, -0.364410,
-2.264990, 1.177350, -3.074570, 0.627330, 0.084060, 0.337240, -1.297130, -0.294080, -2.344430, 2.069630,
1.415010, -1.938370, -0.159610, 1.081540, 0.108550, 0.217300, -0.254450, -1.399690, -0.434840, 0.097210,
1.029090, 0.542200, -1.133610, -0.838880, 1.023930, -0.095690, -0.128460, 1.439420, 3.368680, -0.272390,
0.180250, 0.736040, 1.401450, 0.039500, -0.692700, 0.143560, 1.074900, 2.713670, 1.817000, -0.642090,
1.372880, 1.747390, -0.397870, -1.385100, 0.659360, -0.619330, -2.166030, 0.378050, -0.316110, 2.043220,
-1.014450, 0.970670, 1.911260, -0.073510, 0.549980, -1.353960, 0.338150, -0.648230, 0.582470, -0.371540,
-2.062320, 0.776120, 0.348320, -0.334610, 1.757440, 1.619560, 0.134360, -2.276610, -0.281550, 0.413150,
0.817020, -1.179450, 0.495130, 1.267430, 0.889940, 0.320100, -0.201060, -0.833240, -0.334110, -0.534750,
-1.347950, -0.755410, 0.261060, 0.408780, 0.038280, 2.676230, 1.178930, -0.001010, 0.890910, 1.461800,
-0.187780, -0.351170, 0.119770, -28.799000, 0.295420, 0.966170, 1.100340, -0.056320, 0.097930, -0.745290,
-0.743700, 0.844640, 0.461510, -1.130040, -0.768870, -0.002910, 0.975300, -0.114890, -0.124260, -1.021300,
-1.981300, 0.875980, -1.988370, -1.300630, 0.631380, -1.044740, -0.621640, 0.507990, -1.191030, -0.124570,
0.536780, 0.776060, 0.289730, -0.782230, 0.501140, 3.515240, 0.410800, -0.419770, -0.167910, -0.945740,
-0.645970, -0.701290, -0.009840, 0.903310, -0.805140, 0.509320, -0.123410, 0.469420, 0.570180,
0.208720, -2.098160, -0.324030, -5.116130, 1.716110, 0.521200, 0.301560, 1.415250, 0.074410, 0.716590,
-0.686230, -2.303550, 0.441070, -0.804950, -3.443390, -0.088910, 10.663190, -0.642420, 0.700540, 0.736470,
-0.294350, 1.217160, -1.487070, -0.182350, -0.539910, -0.896770, 0.012970, -0.809780, 0.893620, -0.028430,
-6.150810, -0.284780, 0.460910, -0.448090, -1.654900, 0.286920, -1.098460, -7.779000, -0.725550, 0.080730,
-0.280040, -0.851200, 4.106200, -1.159660, -0.775960, -1.114350, -0.387850, 0.037130, -0.779440, -12.370150,
-1.217150, -0.153350, 0.976480, -0.401680, 7.119760, -0.224240, -0.273940, -0.146630, -0.158870, -1.257310,

0.360170, -2.815960, 0.795390, -11.629450, -0.038730, -0.044480, -0.505030, -0.923020, 0.890220, 0.130630,
-0.003260, -0.868030, 0.331690, 1.004890, 0.521680, -0.380960, -0.889400, 0.347140, 0.404260, -3.454120,
-1.679860, -5.695850, -0.564550, -1.735060, 0.637220, -1.026590, -0.376390, 0.877330, -0.476100, -0.247150,
-4.119000, 2.275980, -0.112520, -0.464030, -2.445100, 75.245796, 0.660720, -0.321260, -0.703390, -0.628060,
1.004240, 0.876080, 22.866341, -0.035360, 1.028030, -6.090650, 0.296280, -2.313970, 0.072560, 307.517609,
0.424050, 0.555350, 1.103470, -1.036620, -20.605890, 9.744700, -0.787630, 0.846420, 5.528410, 7.492080,

0.769200, -0.340650, -1.113250, -0.195750, -0.351170, 10.004070, 0.060860, 0.078100, 0.355740, -1.025690,
3.352040, -0.442500, -0.226600, 0.621930, -0.409010, 0.084330, -3.858220, 0.315780, 2.121220, 1.856540,
1.254760, -1.107870, 0.642470, -1.178160, 0.196480, -0.636140, 0.580290, -0.345790, -0.814090, 0.226500,
14.919130, 0.501620, 0.382310, -0.157540, 0.744460, -1.099760, -0.175230, -1.369790, 0.654410, -0.041350,
1.306160, 0.981330, -1.455880, 0.674480, 0.264660, -0.121370, -0.673550, -0.491020, 0.768730, -61.754230,
-0.685700, 0.456770, -0.375950, 0.162760, -1.978340, -1.605100, 1.223080, -0.630340, -1.495620, -0.674620,

2.355040, -5.591760, -2.108350, -1.259650, 1.239950, -2.050880, 0.254600, -0.380010, 0.514420, 0.632590,
-0.141790, -0.524600, 0.357190, 0.741180, -2.498220, -0.261940, 1.417100, 0.715710, -4.770360, -1.139200,
0.025580, -0.435770, 1.374180, -0.130640, -0.643190, -1.685410, -0.676950, -0.400020, 1.207350, 0.797110,
-3.726450, 1.264840, 1.004340, 0.893990, 0.614330, -1.817210, 0.126690, 5.347190, -0.574430, -0.649450,
0.776420, 0.710560, 0.852730, 0.442890, 1.231710, 1.089610, 0.429610, -0.222750, 0.049160, 4.920300,
0.751850, 0.578340, -0.382810, -0.580080, -4.459160, 0.080860, 0.646640, 0.452140, 0.904410, 0.563750,

-0.353360, 3.028290, -0.043800, 1.615210, 0.153660, -0.410380, 0.128810, -0.299180, 0.220210, -0.846890,
0.917770, -0.676800, 0.637640, 1.008180, 2.272740, 0.105450, 1.630710, -0.605360, 0.190570, -0.279320,
-1.004010, 1.147840, 0.902030, -0.054590, 0.025150, -0.395850, 1.279890, -0.001130, 0.502540, -0.911470,
-0.429270, 0.339660, -0.324180, -0.400750, -0.353170, -1.045890, -0.241630, -0.989090, -0.453580, -0.373950,
0.226160, -0.096010, 0.159750, -0.293510, 0.704250, 1.065900, -0.638630, -0.653080, -0.420970, -1.052850,
0.399720, 0.678900, -0.293860, 1.148850, -0.569290, -1.068320, -0.130940, -0.319650, 0.554230, -0.157070,

0.274520, 0.748220, -3.521740, 6.069870, 0.415490, -0.021360, 5.185970, -0.726550, -0.556110, -0.151110,
-1.539280, -0.119270, 0.047110, -1.431630, -7.497510, -1.582150, 0.551330, 0.295010, -9.650190, 1.868390,
-0.167870, -0.915960, 1.517430, -0.546090, -0.884050, -0.272880, 0.647120, -0.677210, -4.789760, -0.476510,
2.582380, 0.522100, -0.019220, -0.829070, -1.319920, -11.946080, -0.596650, -0.347000, -1.120500, -1.308950,
-0.085380, 0.240500, -4.974310, 0.565520, -0.283810, 1.132350, -1.107550, 1.447600, -0.943390, -15.957380,
0.108280, -0.654900, 1.658620, -0.841190, 15.289220, 2.189710, -0.368060, 0.480140, 5.235750, -3.813010,

4.294850, 1.381390, 0.623390, 0.564170, 1.651460, 1.175870, -7.736890, 1.392090, -0.645350, 1.932830,
-1.671860, 0.428020, -1.007730, 1.112710, -1.428030, 0.380720, 0.853210, 1.216630, 10.895240, -0.418230,
0.578320, -0.146340, -15.299080, 0.828540, 0.843920, 0.413200, 0.312890, 0.223880, -7.417520, -0.606560,
-12.663050, -0.003180, 1.175930, 0.686610, -0.514070, -19.033020, 0.180370, -7.666940, 0.609930, -0.622160,
0.978370, 0.417170, -29.854660, 1.093080, 0.292820, -1.006290, 0.249900, 0.698310, 0.864920, -99.795303,
-0.269780, 1.224720, 0.382710, -0.362330, 0.729520, -19.743139, 1.119700, 0.529350, 14.589340, -6.170180,

-1.882870, -5.570830, -0.502360, 0.042710, 0.143680, 1.651430, 2.038920, 0.530890, 1.191650, -0.287440,
-0.759680, -0.051730, 0.459200, -0.350100, 1.861460, -0.253000, 3.615110, 0.667880, 4.109820, -0.868960,
-0.568570, -1.077380, -1.161970, 0.364060, 1.038940, -0.101050, 0.872860, 0.399890, 0.419040, -23.014259,
1.214120, -0.685340, 0.157390, -1.050950, -1.090590, 2.119260, -0.240310, 2.848180, -0.751830, 0.392750,
-0.943530, -0.190960, 0.219220, -0.132700, -0.213960, -0.407680, -1.071500, -0.432920, -0.701450, -4.619930,
-1.182090, -0.293950, 0.692640, -1.058980, -41.790070, 2.329220, -0.166680, -0.592130, 0.482020, -0.970060,

-1.019030, 2.135730, 0.734510, -0.099100, 0.427980, -0.932020, 0.747240, -1.016350, 0.803500, -0.810290,
-0.157810, -0.976260, 0.330590, -0.208450, -1.130730, 0.689950, -0.087990, -0.588140, -0.417990, -0.983940,
-1.645710, -0.038890, -0.398280, -1.055240, -1.083760, -0.698740, 0.932700, -0.204090, 0.071330, -0.725420,
-3.217590, 0.643830, 0.300520, -0.056790, 0.200800, -0.881740, 1.125190, -1.923910, 0.791040, -0.330060,
-0.229810, 0.959030, 0.110830, -0.493420, 0.345280, 0.425000, -0.218060, 0.242730, -0.442930, 0.191880,
1.132680, 0.801660, -0.900410, -0.276880, 22.642900, 0.363760, 0.872770, 0.316320, 0.281870, 0.422000,

-0.170220, -0.066540, 0.010930, -0.351850, -0.146010, -0.951730, 1.480800, -0.562730, 1.243830, -1.258890,
5.855210, -0.989320, -1.534710, 0.660760, 0.295500, 0.289550, 0.416260, -0.418820, 1.081200, -0.499240,
0.344340, -0.708380, 0.348350, -1.033080, -2.066370, -1.682010, 0.237030, -0.399570, 1.691320, 0.271070,
8.935390, 0.650110, 0.138260, 0.502480, 0.136870, -1.350370, -0.682640, 10.196320, 0.130210, 1.195080,
0.714440, 0.006370, 0.817460, 0.458910, 0.770670, -0.675000, -0.178550, 0.112970, -0.247780, 8.614670,
0.416840, -0.612520, -0.343240, 1.146530, -1.024410, 1.366810, 0.566210, 0.136930, 0.604790, -0.609150,

1.535790, 2.086910, 0.521680, 14.434820, 0.300460, 4.252190, -0.319380, -0.760010, 0.437300, 0.158870,
-0.113470, 0.761190, -0.066540, 0.867230, 1.137750, -0.344210, 0.823460, 0.894620, -0.203810, -1.500280,
-0.366490, 0.413360, -0.446400, 1.008970, -0.625800, 3.597130, 0.634140, 0.807460, 0.607210, -0.084730,
-3.586240, 0.172630, -0.438720, 0.583760, 0.286060, 4.137630, 0.235990, -15.653670, 0.634170, 0.839020,
0.534300, -0.327980, -6.539500, 0.344640, 1.115040, 0.276530, 0.326140, -0.521520, 0.826440, -5.744360,
0.506410, 0.779190, 0.273890, 0.968760, -21.433929, -9.548300, 0.667590, -0.319260, 0.576940, -0.460160,

0.194310, 0.228120, 1.798980, -1.835970, 1.375120, 0.448480, 0.805760, 0.656890, 0.651970, 0.554950,
-1.744560, 0.833150, -0.601180, -1.623890, 1.113610, 0.460270, -0.115680, -0.511390, 1.342030, 0.007210,
-1.055390, 1.161140, 0.068310, 11.022920, 0.230110, -0.623990, 0.029970, -0.006090, -0.723180, -1.596810,
-2.335680, 1.137530, -0.182350, -0.340120, 0.772300, 5.999100, -0.475610, -5.808230, -0.326320, 0.875210,
0.469710, -0.067730, -0.308450, 1.104480, 0.606970, -0.333670, -0.044940, -0.716410, -0.517270, 1.231510,
0.468810, 0.359620, -0.447660, -0.469470, -5.488300, -0.076070, 0.012970, 0.237770, -4.302540, 0.242720,

-0.097420, -0.186320, 0.188040, -1.224480, -1.995630, -0.332820, -0.952840, -0.164300, 0.690960, 0.312200,
-0.145870, 0.784390, -2.400580, 0.665340, 0.343420, -0.634100, 1.107580, -0.438770, 0.704590, -0.449310,
0.159160, -0.217240, 0.718210, 2.042550, 0.540770, 1.036750, 0.545960, 0.365920, 0.972910, 0.458950,
-0.251420, 0.071760, 0.488800, -0.453570, 0.778310, -0.072300, -0.539530, -4.104030, -0.479260, 0.089340,
-0.202930, -0.337370, -1.229930, -1.093740, -1.053340, 0.144680, 0.068760, -0.984190, 0.105790, -1.777430,
-0.915530, -0.590080, 0.634130, 0.071380, -25.443930, 0.910020, 0.437960, -0.451610, 0.469640, -0.622800,

-0.262960, 1.189730, 0.668570, 1.773640, -0.927890, 0.349200, -0.342290, -0.887610, -0.394940, 0.176350,
1.900280, 0.409980, -0.684780, 1.630710, -0.733510, 0.457020, 0.701990, -0.186020, -0.037560, 0.026160,
0.917650, 0.294400, 0.705220, -0.972150, -0.895050, 1.224050, 0.683040, -0.136480, 0.904970, 0.728580,
6.643440, -0.661800, -0.511110, 1.248080, -0.285380, 0.937940, -0.320610, -3.719890, -1.105280, -0.425240,
1.024710, 0.458520, 0.442590, -0.557050, 0.211800, 0.784970, 0.669500, 0.082700, 0.101950, 0.234530,
1.277490, -0.544730, 1.298830, 1.285370, 1.165070, 0.767610, -0.281670, -0.435840, -0.265970, 0.407220,

0.443790, -0.650180, 0.786970, -1.717880, -1.260970, -1.194500, -0.412730, 0.297160, 0.641910, 0.159770,
-0.480210, 0.277750, -0.140230, 0.034840, -4.505870, -0.770180, 0.849950, 0.308520, 0.517050, -0.218330,
1.162210, 0.212620, 0.430650, -0.907390, -0.149570, -0.467220, -1.107460, 0.712550, -0.778440, -0.245290,
12.606580, 0.223310, -0.546340, -0.180880, -0.256540, -6.443520, -0.194850, -9.419860, 0.573970, 0.868250,
-0.462510, -0.727480, 0.572890, 0.268030, 0.377390, 0.972980, 0.086440, 0.183340, -0.635380, -2.106560,
1.054340, 0.453140, -0.055900, -0.183320, 118.609528, 4.007560, 0.707500, 1.052420, 0.265490, 0.607040,

-0.411090, -1.493650, -1.184810, -0.000910, 3.603270, -76.151543, -1.048610, 0.673010, -0.629090, -1.770250,
-1.527790, -0.073400, -0.280370, -1.153710, 0.607560, 0.110320, -1.039610, 0.261010, -0.998260, 0.982530,
1.093110, -2.205350, 0.631620, 0.046690, 0.850130, 1.437480, -0.050490, 0.196170, 1.673980, -1.093980,
-9.669370, -1.079600, 0.192790, 0.685380, -0.210350, -0.588770, -0.523440, -13.089170, 0.236630, 0.065560,
-0.361880, -0.001280, -1.191670, 1.183180, -0.731350, -0.527470, -0.265670, -0.365160, 0.195380, -0.263090,
-0.569090, -0.725000, 0.211170, -0.380140, 0.673840, 0.495510, -0.291860, 0.471500, 1.022770, -0.699070,

0.085170, 0.091970, 0.677890, 1.265100, -0.204210, -0.407440, -0.223480, -1.033860, -0.643930, -0.208560,
-0.562730, 0.403960, 0.474030, -1.243370, -1.370730, -0.520250, -0.186200, 0.802020, -0.638970, -0.278700,
0.101240, -0.735960, -1.040810, 0.486690, 0.052270, 0.146580, 0.551730, -0.506240, -0.697630, -0.565010,
3.480560, 0.847310, 0.821990, 0.373090, 0.682420, -1.359980, 0.978040, 4.374050, 0.193550, -0.707500,
0.882590, -0.113990, -3.449980, -0.669280, 0.117070, -1.075030, 0.055010, 0.137800, -0.634760, -6.203650,
0.936640, 0.348780, 0.204070, 0.048890, -0.927510, 0.238630, -0.894320, -0.751520, 1.102280, 0.694930,

-0.637310, 0.324340, -0.080920, -1.764060, -0.240930, -0.685620, 0.446570, 0.302680, 0.876170, 0.162940,
1.497720, -0.142100, 0.239510, -1.163780, -0.086400, 0.792050, 0.435450, -0.575680, -1.050180, -0.165470,
0.608100, -0.000960, -0.791330, -0.233060, -0.371170, -0.203890, -0.795790, 0.329560, -0.764400, 0.240270,
-2.823590, 0.792490, -0.840980, -0.244570, -0.789150, 0.128070, 0.641680, 1.879000, -0.745950, 1.058750,
-0.439770, 0.505830, 1.301250, 1.058850, 0.336590, 0.658590, 0.496930, 0.799220, -0.800430, -1.359710,
-0.828320, 0.600800, 0.483220, -1.180520, 4.117850, 0.942160, 1.004560, 0.599490, -0.173440, -0.073960,

-0.404260, -0.027540, 0.369590, 0.193270, -0.535830, -0.947800, 0.375960, -0.503760, 0.117310, 0.517630,
-0.394690, -0.255300, -0.142130, 0.957380, -1.778010, 0.400530, -0.531740, 0.523010, 0.467230, 0.669740,
-0.118700, 0.483800, -0.561900, -1.211840, -0.585040, -0.388880, -0.674940, -0.558960, 1.255950, -0.129610,
-0.712920, 0.057920, 0.022990, 0.627440, -0.163690, 0.622820, -0.200280, 0.521590, -0.174280, 0.458470,
-0.009020, -0.439520, -0.344220, 0.398550, -0.249810, 0.572320, 0.957090, 0.304650, 1.234010, -0.839660,
0.946250, 0.313720, -0.789760, -0.704310, -2.216330, -0.529460, 1.116180, -0.295880, -0.768770, -0.827620,

0.164310, -3.622340, 0.584920, 0.165720, -0.532320, 0.121280, -0.628400, 1.791550, 0.075260, -0.959120,
3.493400, 0.571750, -0.465480, 0.403570, -4.047480, -0.899710, 0.118090, -0.043200, -1.115340, 1.142280,
-0.127070, -0.346490, -0.583210, -0.923890, -0.448350, -0.016290, -0.614420, -0.763220, -0.395250, 0.613980,
-3.998900, 2.565730, -0.241170, -0.052770, 0.210180, -1.507740, 0.242040, -2.038780, -0.583710, 0.209360,
0.587940, -0.622260, 4.238610, 0.129290, -0.794990, 3.250430, -1.328900, -0.685740, -0.512520, 1.030590,
-1.026090, -0.826790, -0.661290, -0.657870, -21.101620, -10.699710, -1.175790, 0.253770, 0.322630, 1.135090,

-1.182230, 0.987030, 0.209090, -0.396380, -0.318490, -0.925240, -0.127290, -0.836590, 1.790280, 0.037640,
-0.203460, 0.241610, -0.467710, 0.370200, 0.128580, -0.382470, 1.012070, -0.086110, 1.215130, 0.321000,
0.785820, 0.930480, 0.521420, 0.517710, -0.112780, 0.106360, 0.971190, 0.462810, 0.232280, -0.949200,
-0.737260, 0.202100, -0.593590, 0.144520, -0.297400, -0.095640, 0.573320, 1.648280, -0.586350, -0.147260,
0.569380, 0.229010, -0.795710, 0.045220, 0.387680, 0.592610, 0.115360, -0.995910, -0.034550, 1.571560,
-0.067190, 0.743750, 0.629980, 0.751980, 2.422750, -0.671490, 0.381380, -0.297810, 0.303830, -0.274340,

-0.416970, -0.888040, 4.550310, -2.128970, -0.028360, 0.932270, 0.984110, -0.486540, -0.663080, -0.669070,
1.725580, -0.363550, 0.397160, 0.068360, -2.147020, 0.935300, 0.223940, 1.054590, 1.013720, 1.586100,
3.111720, 0.304480, 0.244530, -0.747360, -0.590800, 0.081670, -0.407080, 0.157630, 0.774350, -0.483940,
2.960410, 0.768120, 0.294400, 0.671740, -0.678380, 2.787480, 0.348930, 8.742910, -0.696270, -0.128490,
-0.291930, -0.612670, -0.910160, -0.561330, 0.617430, -3.136130, -0.401650, -0.276780, 0.541310, 3.377640,
0.792980, 0.133160, -0.842550, -0.164060, -0.016390, 0.139700, -0.361590, -0.138300, -0.023880, -1.008960,

0.435910, -0.432700, -0.095680, 0.043710, 0.346600, 1.580160, -1.073270, 0.060600, -0.151370, 1.009210,
-0.077720, 0.556430, -0.379370, 0.764160, -0.941380, -0.491000, -1.150230, 1.129330, -0.612140, -0.748410,
0.868020, -0.175080, -0.163620, 0.532920, -0.321550, 0.869130, 0.690510, 0.242640, -0.840940, -0.780800,
-1.376370, -0.109000, -0.453780, 0.165090, -0.851130, 0.910250, 0.343560, 1.546060, 0.280190, -0.182810,
-1.029980, 0.936160, 1.246150, 0.375760, 0.139580, 0.576720, 0.214400, 0.819510, 0.265560, 0.060350,
-0.732700, -0.123350, -0.489940, -0.635810, -0.681740, -0.238500, 0.864170, -0.079150, -0.667420, 0.889720,

0.323130, -0.964800, 0.475260, -0.131420, 1.122580, -0.020360, -0.186430, -0.838910, 0.057690, 0.069350,
0.138380, -0.957670, -0.398040, 0.066260, 0.141070, 0.852550, 1.126770, 0.743110, 0.735340, 2.129700,
0.745660, -0.128370, 0.030560, 0.610090, -0.375250, -0.661250, 0.542670, -1.191300, 0.977010, -0.158990,
-6.369680, 0.745540, -0.609020, 0.569010, 0.623790, -0.635160, 0.344020, -2.021910, -0.764380, -0.210390,
-0.427970, 0.135340, -2.645490, 0.982850, -0.771000, -0.641430, -0.326960, -0.463520, 0.356130, -1.687870,
0.262250, 0.412100, -0.700080, -0.476490, 1.499450, 0.418210, -0.372400, 0.523890, 0.041540, 0.978620,

-1.455850, 4.838150, -1.545370, 5.048680, -0.187270, -1455.574341, -20.525730, 0.934270, -0.542770, 1.813080,
-5.920800, -0.060300, -0.238460, -1.604890, 0.810490, -0.869180, 0.074000, 0.139600, -1.327000, -0.131950,
-1.443400, 1.095610, -9.134760, 1.109680, -0.041900, 1.612600, -0.697210, 0.373340, -1.496890, 0.217310,
6.190620, 0.473650, -0.720570, 0.438880, -0.960860, -17.041361, -1.156080, -9.111620, 0.263030, -0.715260,
-0.663000, 0.687240, -1.329490, 0.639260, -0.702000, 2.450820, -0.485020, -0.621670, -1.300510, 4.975920,
0.081670, -0.857150, 0.049160, -0.087680, -10.876880, -0.757600, 0.308370, -0.063410, 0.995710, -0.480220,

-0.022310, 0.464630, -0.322190, 1.120440, 0.933600, -0.495740, 0.453990, 0.014320, -0.623290, 0.122060,
-1.141800, -0.469080, 1.051430, 0.013790, -4.449340, 0.040760, 0.440500, -0.997230, -0.445580, 0.137210,
-1.314820, 1.535480, -0.390270, 0.379790, 0.783260, -1.181050, 0.306700, 0.350930, 2.520550, -0.005610,
0.253750, 0.609480, 0.189230, -0.020000, -0.169200, 1.887330, -0.064530, -0.203020, 0.342880, -1.296360,
0.165130, -0.782690, -1.179050, 0.129940, -0.526440, -0.417370, 0.297330, 0.204130, 0.424740, -1.491800,
-1.290460, -1.058210, 0.626210, 0.535720, 4.952370, -0.692830, -0.817840, 0.185040, -0.938640, -1.052630,

-0.072510, -0.824860, -0.829440, -2.267510, -1.562360, -0.685590, 0.526650, -0.879250, -0.464760, -0.140300,
0.082070, 0.311670, 0.546070, -0.669420, -0.108900, 0.148720, -0.856630, 0.598960, -0.333670, 0.111510,
0.028930, -0.622850, 0.416560, 0.388480, 0.521810, -0.155880, -1.046020, 0.698040, 0.452810, 0.546940,
-0.772360, -0.028860, 1.055130, -0.681750, -0.408400, -1.235200, -0.035410, -0.338460, 0.680530, 0.432460,
-0.524520, -0.882580, -0.310820, -0.309140, 0.514110, 0.415830, 0.652730, 0.886950, -0.648610, 0.059170,
0.950130, 1.052160, -0.225580, -0.570600, -0.361000, -0.103910, 0.792660, 1.042110, -0.251980, -0.071990,

0.277140, -1.066230, -1.226190, -1.229890, 1.344060, -0.373630, 0.092900, -0.483700, -1.070520, -0.224810,
0.647850, -0.141260, -1.055060, 1.762530, 0.361790, 0.385360, 0.563300, -1.171730, -0.365910, -0.406480,
0.409950, 0.002730, 3.891380, -0.716140, -0.939650, 1.033120, -2.162500, -0.297150, -2.427610, -0.599990,
-3.461050, 0.081850, -0.659160, 1.317040, 0.174620, -0.699490, -0.517940, 9.397000, 0.434310, 0.518840,
1.073700, 0.076940, -1.331460, 1.068340, 0.719600, 2.313990, 0.717480, 0.054250, -0.243180, -0.632440,
-0.563770, 0.868920, 0.930110, 0.720760, 164.958603, 1.082450, -0.808080, 1.188090, -0.975490, 0.788030,

-0.732560, 0.877230, 0.478130, -0.418440, -0.637700, -0.150550, -0.000790, 0.693980, -0.135280, 0.716620,
-0.332210, -0.849820, 0.235090, -0.553440, 0.067010, -0.874950, 0.849540, 0.467310, -1.288900, -1.113930,
-0.473420, 1.034230, 0.236710, 0.754910, -0.068280, 1.166580, -0.118250, 0.788660, -1.597050, -0.967960,
0.134390, 4.670320, 0.155620, -0.990380, 0.750240, 1.675530, 0.527940, -3.371980, -0.099850, 0.128980,
-0.320330, 0.492320, -0.771540, -0.761190, -0.319680, 1.333300, 0.384680, 0.044310, -1.071860, -7.428760,
-0.415620, -0.864100, 0.631680, -0.101900, 0.969990, -1.078660, -0.968340, -1.106780, 0.844920, -0.452360,

-0.667870, -0.708490, -0.531560, 0.008870, 0.073980, 0.454160, 0.533110, -0.356500, 0.547050, -96.919220,
-0.555540, -0.323170, -1.596410, -0.128880, 0.010050, -0.304710, -0.544820, 1.515430, 1.312740, -0.429290,
-0.046100, -1.328090, -1.013100, 0.951400, 2.273070, -0.785570, 1.320900, -0.246840, -0.197230, -1.082320,
7.807680, 0.026400, 0.700680, 0.358030, -0.141860, -0.558070, -0.604430, 0.891860, 0.490440, -1.061850,
0.823360, -0.225100, 0.144030, 0.212680, -0.794230, 0.470370, -0.859160, 0.700780, -1.056430, 1.991840,
-0.656600, 0.302160, 0.937240, 0.222910, 0.734520, -0.545800, -0.800220, -0.330750, 0.114900, -0.979580,

0.368080, 0.018350, -0.300340, -0.244240, -0.442050, 0.165530, 0.036680, 0.447970, -0.368090, -0.304450,
0.247340, -0.109720, 0.750000, -0.459620, 0.138160, 0.256000, 0.175640, 0.675890, -0.640170, 0.227080,
-0.554940, -0.099420, 0.899900, -0.307130, 0.684110, 0.310170, 0.858660, -0.437720, 0.089370, 0.334680,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.207070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.680970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, 0.293330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.106830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.362610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.772860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.968830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.168180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.681260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.232570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.382010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.882280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.799710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.672910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.681860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.066130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.208290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.165400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.460060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.219040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.413200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.484750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.402950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.848920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.190030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, -0.714760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.883940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.325660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.692950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.994490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.075240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.065190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.575750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.468780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.965500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.386430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.201710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.217430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.575120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.771790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.390690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.696280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.324680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, 0.225050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.287220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.507110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.207230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.063260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.081280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.304980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.345640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.892740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.263920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.887780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.985140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.033200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.454460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.951400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.183910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.590070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.755390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.881260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.478310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.394340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.782990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.003600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.420050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.427170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.729850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.351080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.083020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.919270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.549350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.246900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.542720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.290930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.399360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.339530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.437930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.131910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.648930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.218780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, -0.637530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.688020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.639060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.886790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.150230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.041330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.868710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.827020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.765170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, -0.522730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.202150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.376510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.523100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.189980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, 0.749500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.030730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.555070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.746240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.057640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.997170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.721030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.962610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.629780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.514230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.370860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.931470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.871120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.618860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.015780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.559730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.152710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.421940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.357870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.477350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.652020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, 0.996370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.910430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.517650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.169100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.403250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.556310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.007820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, 0.865940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.213870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, 0.041050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.563720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.560980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.832410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.299560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.614610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.577530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.267360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, 0.892870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.566820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.938650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.111810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, 0.647170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.864360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.819300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.054310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.743390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.391130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.860380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.089820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.202870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.786610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, -0.387090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.677470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.479400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.302540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.356310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.154420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.453760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.870780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, -0.323880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.905170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.253920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.236390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.702740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.245390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.289180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.948620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.682760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.845960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, -0.485270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.488030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.803690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.244700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.360940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.577130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.297070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.497370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, 0.542710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, 0.498160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.886440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.726570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.459880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.097410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, 0.351960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.730160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, 0.406590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.360120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.666290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.752610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, -0.299330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.853770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.797090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.492840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.222640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.683780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.664040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.254830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.514100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.781570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.701620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.118660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.715160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.313810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.383540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.309610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, -0.787170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.917420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.756530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, -0.963090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.889950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.229550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.923750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, 0.247050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.051210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.436150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.121080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, -0.214490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.632880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, 0.106930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, 0.945780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, 0.056290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.430200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.414550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.608640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.964840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.659200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.146330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, 0.790440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.465950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.761800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.552220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.894510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.478100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.642710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, -0.652260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, 0.498040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.487010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, 0.323610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, 0.223560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.054640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, 0.467180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.197560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.741790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.908220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.410850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.211510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, -0.120000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.378360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.645150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.049040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.817710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.475200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, -0.834090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, -0.956870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.335810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, -0.804150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, 0.518730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.253670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.504570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.084350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, -0.801260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.154210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.131850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, -0.940920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.292260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, 0.136990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.641820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.569360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.325650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.091260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.910550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, -0.367760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, 1.066490, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -0.282110, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.282880, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, -0.443710, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, -0.819960, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -1.346900, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.738380, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.818700, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.468290, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -1.339030, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.065230, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, -0.931340, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.171880, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, -0.310610, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, 0.440290, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, 0.053090, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.222550, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 1.184430, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -0.029000, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, 0.274690, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 0.815630, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.337590, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.440410, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.868550, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, 0.384180, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.504490, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, -0.472260, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.671190, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.201940, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.526140, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.494280, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, 0.648420, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.366810, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 1.267900, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, 0.354810, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, 0.340070, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 1.309240, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, 0.053160, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, 1.155590, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.714240, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, 0.872770, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, 1.179570, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -0.187260, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.157040, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.787100, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -0.742030, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, -0.407660, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.100580, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, 0.446200, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -1.046570, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, -0.831030, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 1.022780, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 0.183680, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, 0.414950, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.581670, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.112900, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.781360, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, 1.113370, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, 0.625460, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.219970, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.037900, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
1.15384, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.00087, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.09744, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
0.02417, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
0.33823, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
0.26054, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
0.12680, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
0.19689, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
1.41015, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
1.03736, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
1.33021, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
1.05690, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
1.20300, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
0.03418, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
0.30111, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
1.03737, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.01546, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
1.40017, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
0.34458, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
0.00081, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
0.40062, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
0.36179, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
0.30378, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
1.01217, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.00630, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
0.10183, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
0.09242, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
1.10129, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.02837, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
1.30778, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
0.00020, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
1.42649, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
1.42746, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
1.42832, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
0.34368, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
0.00749, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
1.42543, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
0.00080, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
1.37566, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
1.42323, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
1.42831, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
1.37806, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.01475, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
1.30987, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
1.11856, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
0.00117, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
1.10174, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
1.41688, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
1.27703, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
0.00697, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
1.09989, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
1.03063, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
1.07544, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
1.08581, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.00001, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
0.02693, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
1.37975, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
1.41185, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
0.85319, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
0.01042, 0.500000, 2,
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
