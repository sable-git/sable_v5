/*********************************************************
  Pfam_elBP_0_forceW7new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:02:22 2004
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
-1.116430, -1.077990, 0.311730, 1.512780, 1.026850, -0.745720, 0.248090, 1.816580, -1.244900, -0.496090,
-0.046010, -0.320710, 1.837990, -1.552980, 0.307570, -0.940330, -1.069780, 1.078480, 0.805710, 0.237190,
0.427740, 0.054000, -0.136250, -1.146000, -0.202640, -1.095240, 0.154290, 0.487080, -1.028220, 0.219070,
0.522760, 1.326040, 1.603990, -0.039340, -0.306300, -0.181350, 1.279900, 0.140390, 0.368390, -0.679650,
1.184660, -0.885350, 0.677030, 1.342260, -0.061250, 0.320750, 0.140630, 1.125340, 0.365810, -0.055260,
-1.493510, 0.410490, -0.064710, -0.237930, -1.642090, -0.342330, -0.077020, -0.427260, -0.361210, -1.910820,
0.680830, -0.105910, -0.086920, 1.131830, 0.193230, 0.523920, 1.365970, 0.041590, 2.572760, 1.163440,
0.637430, 1.304470, 1.571170, 0.268920, 1.220700, -0.004070, 1.573510, 2.080980, -0.245220, -0.782580,
1.422360, 1.792700, -0.900520, 0.185870, -0.449820, 0.007570, 0.249820, -0.526210, -0.190560, 0.745540,
0.825530, 0.730550, 0.427550, 0.593920, 0.700700, -0.356760, -0.532570, -0.149440, 0.469200, -0.547090,
-1.249080, 0.544350, 0.860990, -0.171820, 0.449880, -2.697050, 0.506660, -0.979430, -0.010390, 1.886510,
-0.925180, -1.249790, 1.376130, 1.868890, -0.292660, 1.216510, 0.231310, 2.232120, -0.521400, 0.572340,
0.157940, -0.060420, 0.546570, 2.194340, 2.424950, 0.279880, -0.773960, 2.023390, -0.288200, -4.531920,
-2.694160, -1.468530, 1.468980, -1.247860, 0.304710, 2.747300, -1.139710, 0.267550, -0.495880, 1.031260,
0.281680, 0.073550, -0.496300, -0.250360, -0.296170, 0.967430, 3.291100, -0.580070, -1.528030, 0.475990,
-0.019780, -0.861390, -0.156030, -0.160480, 0.207940, 0.496580, 1.878760, -0.488470, 1.440830, -0.831540,
-0.342220, 1.032170, 1.353700, -1.205650, -0.834470, 0.216460, 0.864690, -0.090350, -0.926020, 1.395110,
-0.174390, -1.352940, -0.173630, 0.558670, 0.326660, -0.028200, -0.306730, -0.974100, 0.711780, 0.375800,
-1.120380, 0.498300, -0.696140, 0.393470, 1.806590, 0.319350, 0.735040, -0.497750, 0.136490, 0.713160,
-0.719790, 2.543570, 1.984480, 0.790750, -0.641150, -0.424370, -0.823880, 1.638770, 0.383280, 0.014620,
0.114930, 2.904730, -0.051370, -0.400530, -0.257810, 0.848840, -0.023190, -1.190460, 1.278790, -1.260890,
0.884240, 0.039920, -0.976350, 1.627640, -0.061700, -0.557060, 0.436810, 0.550790, -0.540380, 0.508750,
0.013940, 0.391520, 0.582700, -0.066260, -0.568980, -0.149270, -1.325690, 0.281760, 0.236930, -0.381200,
1.536720, 0.323470, -0.375400, 0.373780, 1.108990, -1.510750, 0.631040, 0.242420, -0.702890, -0.088150,
0.769830, 0.002680, 0.384880, -0.861830, -0.737230, -0.810340, -0.409920, 2.343240, -0.146310, 1.033290,
0.189480, 0.050830, -0.475140, 15.319410, 0.436890, 1.893560, -0.171300, -1.020120, 0.444620, -1.629880,
-1.094620, -0.613270, -0.957380, 0.242840, 0.319490, -0.339060, 0.798940, -1.661470, 0.410340, 0.039270,
-0.488630, 0.468800, 0.257310, -0.600070, -0.092070, 0.247670, 0.882550, -0.811520, 1.011670, -0.024410,
-0.849650, -0.734560, 0.932630, -0.971530, 0.156850, -0.364260, -8.897770, 0.087710, -0.124380, -0.253300,
-0.567560, -0.966600, 0.072810, 0.724230, 0.564070, 0.229770, -0.326230, 3.135770, -0.412030,
0.897720, 1.175270, 1.143650, 0.484200, 0.793960, 0.931230, 1.526280, 0.269700, -0.104670, 0.518130,
0.476250, -0.830840, 0.389150, -0.891900, 0.673410, 0.601770, -0.420020, 1.518470, 0.834790, -0.627830,
-2.071530, 0.803090, -0.956120, -0.028660, 1.291340, 0.871270, -0.430770, -0.418700, -0.468750, 0.646220,
1.536000, 0.927730, 1.280290, -0.717430, -0.712770, -1.077970, -1.435190, -0.437500, -0.744440, -0.964380,
1.008090, -1.282700, -1.280610, -1.174250, 1.152020, -0.325630, 0.687480, 1.160630, 0.979640, 0.234520,
1.275490, 0.229550, -1.303920, 1.174640, -0.656250, 0.594600, 0.285480, 0.354040, 0.453800, -0.897240,
0.614990, 0.351300, 0.096430, 1.199550, -0.640180, -1.289920, -0.152640, 1.006150, 0.042040, 0.498820,
-0.638990, -0.791470, -1.568570, 0.903240, -0.903450, -0.474080, 0.291340, 3.895620, -1.970580, -0.097070,
0.808250, 0.754510, 0.073030, 0.732170, -1.598860, 0.160350, 0.213450, -0.387690, -0.553180, -2.194830,
-0.798860, -0.627170, -0.174310, 1.006990, 0.462430, 0.915410, -0.530260, 1.007620, -0.219710, 1.220360,
-1.147860, 0.251730, 0.915200, -0.032220, 0.718830, -0.206280, 0.220330, 0.276100, -0.759260, 0.317500,
0.588220, 0.525660, -1.881450, -1.107220, 0.677310, -0.457850, 0.439330, -0.204980, -0.574620, -1.630200,
-0.125350, 0.537150, -0.277280, 0.445860, 1.589290, -0.433880, -1.556910, -0.905600, 0.192550, -2.083500,
-1.236220, -0.738160, 1.700440, -0.970850, -0.877400, 4.507040, -0.463320, -0.028270, 0.834220, -3.205070,
2.166060, 0.779400, -0.428580, -0.685780, -0.604730, 0.737030, 1.806370, -0.606980, 1.423280, -0.322410,
-1.755260, 1.926470, 2.086570, -0.281950, -1.094770, 0.210940, 0.401110, -0.658770, -1.245250, 0.121310,
-0.353820, -0.073380, -0.502560, -3.148370, -2.967620, -0.628140, -1.714030, 0.513840, -0.961530, -0.096830,
-2.696660, 0.792380, -0.060480, -1.693680, 1.072890, 1.033690, 0.078110, -0.259400, -0.901540, 0.777900,
-0.670630, -1.970220, 0.774010, 1.349400, 1.262730, -0.796400, -0.500030, 0.873170, -1.172940, 0.656320,
0.431640, -0.439540, -0.599620, -0.354610, -0.056840, 0.537800, 0.029130, -2.717100, -0.824410, 0.249710,
4.075090, 0.347010, -1.192340, 1.463900, 0.504480, 1.319520, 1.966460, 0.185560, -0.479170, 0.495210,
-0.926520, -1.190200, 0.725540, -1.986480, -1.011510, -0.519710, 0.380970, 0.554100, -1.996280, -2.084970,
0.636780, -1.210080, -1.520170, -0.785950, 0.579350, 0.184810, -1.529200, 0.149300, -0.784240, -0.615040,
-0.787530, 0.700870, 0.025480, -0.907850, 0.756770, 0.589660, -0.336100, -0.287100, -0.044720, 1.023020,
-0.581440, -0.232260, -1.853330, 0.285890, 1.145700, -1.081020, -0.921760, 0.334900, -0.647770, 0.616320,
-0.050020, 0.568560, 0.685790, -0.371740, -0.713650, 1.335830, -0.350960, 1.203690, -0.125630, 0.194030,
0.363670, -0.722100, 0.047080, -1.442340, 0.265770, -0.749870, 0.478910, -1.581810, 0.653410, -0.127400,
0.335480, -0.906510, -0.770550, -0.359230, 0.692770, -0.152020, -0.204490, 0.490070, 1.031310, 0.533070,
-0.064480, -1.093630, -0.525450, -2.026230, 0.363720, 0.576460, -0.228260, -0.352340, 0.643850, 0.049360,
0.492040, -0.542100, -0.692760, 0.348920, -0.856610, 0.318160, -0.443730, -1.218940, -0.803670,
-1.456060, -0.373070, 0.309190, -0.737950, 0.078190, -0.725410, 0.596780, -2.151980, -0.240500, 0.171760,
0.937970, -0.764380, 0.465500, -2.362220, -0.192090, -0.071740, -0.837630, 1.594950, -0.166250, -0.734630,
-2.308350, 0.407190, -1.295220, -0.559940, -0.858340, 0.273140, 1.000060, -0.178890, 0.385980, 0.231510,
-0.367000, 0.092870, -1.669400, 0.084020, 0.277110, 0.676080, 0.210970, 0.809100, -0.803440, -0.783270,
1.081170, -0.528100, 0.172020, 0.326830, -0.258090, 0.961640, -0.506160, -0.503110, 0.206200, -0.298670,
-0.238320, 0.065650, 1.340910, -1.227780, -0.263560, -0.695160, 0.406260, -0.945720, 1.106040, -0.001210,
0.181430, 0.160490, -0.798680, 1.498890, 1.780430, 1.478600, -0.658660, 0.261370, -0.048160, 0.921360,
0.076130, -0.891660, -0.802010, -1.152960, 0.565500, -0.529170, -1.730200, -0.966360, 1.234320, 0.433760,
0.215460, 0.616910, 0.611830, 0.344270, -2.033400, 0.006450, 1.945200, 1.021070, -1.383930, -0.395120,
0.727930, 0.880030, -2.696760, -0.570230, 0.278460, 1.233690, 0.110590, -0.479850, 1.295860, -1.089770,
0.037600, -1.518430, -1.078420, -0.659490, -0.399930, -0.849100, 0.753940, 1.275590, -1.904500, 2.009030,
0.822630, 0.632750, -1.494390, -1.530490, -2.056310, 0.936900, 2.463820, 1.071600, -2.735310, -0.968590,
1.222750, -0.121250, 0.924680, 0.351850, 1.732970, -0.726410, -0.372430, -0.706750, 1.052530, 0.244310,
-0.739160, 0.010000, 3.924110, -0.441840, -1.195020, 8.468340, -0.675330, -2.016480, 0.175760, 1.315760,
0.539830, -1.666680, -1.411930, 0.115750, 1.100510, -0.820220, 0.264410, 0.216800, -0.573910, 1.346930,
0.570590, 1.269670, 1.144420, -0.859670, -0.508230, 0.467840, -0.580160, 0.764100, 0.052210, 0.837250,
-1.233780, 0.505810, 4.121240, 1.177280, -1.989280, 0.861390, 1.138280, 1.455260, 1.046880, 0.838020,
-1.336420, -0.340660, -0.495520, -0.731580, -0.127200, -0.171800, -1.028240, -1.171050, 0.697560, -1.418930,
-0.367160, -1.791080, 0.465180, -1.150510, 1.570850, 2.968920, 3.265310, -0.706210, 1.654880, -0.497530,
-1.686690, -0.505520, 0.811130, 1.343280, -0.383040, -2.138900, -3.997430, 0.929690, 0.619940, -0.587460,
-0.691090, 4.634740, -1.093620, -0.416620, -0.781150, -0.699880, -1.099880, -0.088570, 0.228160, -0.703680,
0.588200, -0.738400, 0.830580, 1.514720, 0.761100, -0.297040, -0.246600, -0.750720, -0.205130, 0.106360,
-1.097520, 0.708750, 1.006920, -0.438450, 0.531370, 0.341960, -0.771800, -1.628390, -0.014470, -0.473650,
-0.309990, 2.648250, 0.044110, 0.526950, 0.136800, -0.454100, 0.584170, 0.133380, 2.694390, 0.265810,
-0.276400, -0.195360, -0.136360, 0.271160, 1.576520, -0.627150, 0.503970, 0.589990, 1.629430, 0.256940,
-1.717230, 1.430120, -0.084020, 1.044580, -1.243450, 0.976690, -0.781750, 0.686420, -0.581260, 0.654140,
-0.743350, -1.022690, -0.831490, 0.376750, 1.939690, -0.946020, -0.075010, -0.392120, -0.203100, -0.411230,
-0.409790, -0.069490, 0.510380, -0.306970, 0.863160, 0.349230, 0.269760, -0.319430, 1.810360, 0.633550,
0.470630, 0.426130, -0.926400, -0.064200, -0.401460, 0.768600, -1.552690, -0.811560, 0.824480, 0.860710,
0.665490, 0.603220, -0.719440, 2.458310, -0.626310, -0.870820, 0.356170, -1.894230, 0.517450,
0.595210, 1.605010, 0.125240, 0.207780, -0.121950, 0.496980, 0.668920, -0.403960, -0.369720, -1.796510,
-0.791060, -1.153360, 0.859620, 1.752840, 1.025880, 1.058700, 0.057820, -3.085650, -1.394800, 0.374610,
0.107330, -2.415890, -0.027610, -0.184280, 0.330020, -1.575970, -0.044170, 0.636610, -1.431480, 1.222530,
-1.070000, -0.576700, 0.121930, 0.935360, -1.244630, -0.209120, 3.820590, -0.465980, 0.420930, -0.649920,
-0.436050, 0.237690, -0.511760, 1.336770, -1.841600, 1.234270, -0.735090, -0.648830, -1.023430, -1.074160,
-0.278730, -0.179490, 1.304970, 0.448580, 0.219940, -0.890530, -0.066240, -0.237460, 0.022410, -0.892270,
-0.033860, 1.601230, -0.807820, -2.651270, -0.163050, 0.145240, 0.148990, 0.950180, 0.489960, 0.927340,
-0.132670, -0.440130, 1.155590, -0.404000, -0.044450, -0.898690, -1.404030, -1.535080, -2.686030, 1.770270,
-0.766670, 1.580020, 1.216550, 0.050480, 0.442240, -0.053190, -1.762050, -0.667690, 0.243860, 0.279410,
0.311100, -0.849540, 0.886330, -0.204340, -0.133220, 0.597120, -0.956840, 2.526270, -1.306310, 1.202940,
-1.044040, -0.870400, 0.256520, -1.413200, 1.528030, -0.184600, 0.702720, -0.991400, 0.090390, 0.261690,
-1.274840, 0.075060, -0.054010, -0.970150, -0.342110, -0.241730, -0.828130, -0.680570, -1.460780, 1.858580,
-0.908110, 0.543640, 0.087180, -1.041300, -1.415440, 0.602880, -0.199660, 0.518400, 0.206150, 0.587440,
1.649200, -0.576200, -4.808180, 1.042240, -0.669380, -7.515900, -0.582200, -0.055780, -0.315730, -1.387370,
-1.916270, 0.339120, -2.582520, 0.827720, 0.631140, 1.105530, -0.493130, -1.957850, -0.183450, 0.644930,
0.599710, 0.317370, -0.729900, 1.598460, -0.281830, -1.393950, 0.049550, 1.068500, -0.824340, 0.397490,
-0.860930, 0.398760, -0.969720, -0.604850, 0.164900, 0.281520, 0.068900, 0.258650, -0.812200, -0.253600,
-0.177940, 0.878270, 0.384690, 1.052830, -0.106250, -0.256320, 0.939090, 0.075630, -0.672970, -0.337920,
0.156350, 0.316150, -0.266490, 0.839650, -0.271910, -2.111120, -0.713240, 0.135500, -0.145280, 0.031110,
0.503390, 1.245340, 0.590840, 0.752210, -0.625890, -0.672340, 0.854800, 0.399680, 0.905900, -1.179110,
0.279270, 0.012590, 0.056660, -0.399910, -0.262490, 0.204450, -0.133360, 0.643880, -0.441570, -0.380090,
-1.054480, -0.599950, 0.020540, 0.202200, -0.200610, -0.641330, -0.233650, -0.250690, -0.447000, 0.448490,
0.520390, 1.532300, -0.725600, -0.278710, -0.795990, 0.588500, -0.025670, -0.776970, 0.808150, -1.499840,
-0.503400, -0.773480, -0.227430, -0.554080, 0.446440, -0.723710, 1.330970, 0.976850, -0.987620, 0.440920,
-0.504130, 0.214310, 1.338890, 0.643980, -0.028020, -0.030360, -1.044630, -0.717510, -0.300180, -0.406690,
0.186170, 0.676080, -0.359460, -10.898170, -0.582920, 0.114010, -0.400650, -0.680220, -0.202200, 0.485740,
0.514200, -0.226130, 0.788530, 0.425070, -1.505330, 0.747590, -1.014200, 0.142130, -0.270870, 0.291280,
0.671490, -0.386270, 0.222640, -0.102610, 0.460110, -0.481750, 0.580920, -0.558110, -0.345640, 0.743870,
-0.639430, -0.546620, 0.256860, -0.426300, -0.507520, 0.940830, -0.260720, 0.568150, -0.755140, 0.834770,
1.081070, 0.067570, 0.231730, -0.522920, 0.245000, 1.101050, 0.567960, 1.414170, -0.370120,
1.581260, 0.097300, 1.383850, 1.122410, 0.047230, 0.726720, 0.203530, 0.021780, 0.644860, -0.305590,
0.035000, 0.674560, 0.080750, 0.323490, 0.417450, -0.940840, -0.394990, -1.066370, 0.322790, 1.080600,
2.809090, 0.586380, 0.996850, -0.068260, -0.187070, 0.651020, 0.048300, -0.883760, 1.035130, 0.239200,
0.859740, -0.235320, -3.522190, -0.339010, -0.576090, 1.284620, -0.817700, 0.065710, -1.255370, -0.425830,
-2.241690, -0.699120, 0.429850, 1.309040, 0.043630, 0.333800, 0.903590, -1.414590, -1.027050, -2.543400,
0.488550, 0.829390, -1.410980, 1.224170, -1.390310, 0.362130, 1.133830, -0.612080, -0.175290, 0.786700,
2.549700, -0.003730, -0.261070, -1.307700, -1.070850, 0.904110, -1.442460, 0.582620, 1.105020, -0.916450,
-3.318360, -1.055550, -0.651470, 0.069370, 0.148200, 0.617440, -0.871160, -1.673460, -0.096940, 0.970560,
1.007390, 0.013770, 0.083530, -1.192170, -0.512260, -0.344590, 0.878080, -1.461630, -1.024980, 1.546320,
1.189180, 0.601740, -1.157460, -2.107670, 0.037170, 0.116330, -0.051910, -0.266090, -0.105360, -0.033170,
-1.271520, -0.806700, -0.231580, 0.183950, 0.957570, 0.607970, 1.381670, -0.332040, -0.198040, -0.337440,
0.261470, 0.911450, -0.701450, 0.604270, -0.881080, -1.956070, -0.869770, -3.240970, 2.350230, -4.531170,
2.100010, 1.199580, 1.512090, -2.571630, -0.964610, 0.727850, -0.316290, -1.045880, -2.075430, -1.120140,
0.813120, 1.113270, -8.098900, -2.619970, -0.429740, -3.518870, -4.128900, -0.151300, -1.107720, -0.581500,
-0.521190, 2.015900, 0.946930, 2.691810, -0.384870, 4.653150, -0.923780, 2.240660, -0.514970, 0.404560,
1.126860, -0.081760, -0.775400, 0.557230, -1.017420, -1.623590, -0.251720, 3.120440, 0.565450, 0.360940,
1.030590, 0.663510, -3.785350, 0.628950, 1.329650, 0.322570, -0.555630, -0.077090, -2.093100, 0.604580,
0.582120, 0.998220, -1.137630, -1.285280, -0.311380, 0.403120, 0.585840, 0.247650, 1.369650, -0.521060,
-1.335780, 1.178690, -1.465980, 1.223820, -0.649010, -0.207530, 0.430680, 1.648840, 0.311320, -1.146810,
-2.898620, 0.597110, 0.152090, 1.253300, -0.563250, -0.762070, 0.126990, -0.255420, 0.206070, -0.442780,
-0.198190, -0.667610, 0.404630, -0.488760, -0.743430, -0.603780, 0.819440, -0.197930, -0.551370, -2.143320,
-0.155090, 0.390880, -0.200630, 0.960420, -1.101030, -0.642340, -0.540390, 0.114460, 0.347600, 0.965090,
0.819630, -1.427350, 0.852180, -0.737390, -0.932260, 2.440390, 1.536240, 1.744250, -0.303450, -0.168150,
1.220340, -0.875180, 0.864260, 2.772820, -1.789740, -2.155590, -0.272260, 0.344660, 1.505270, 0.752530,
-1.143820, -0.818240, -1.018390, 0.276800, 0.574740, 1.737690, -0.205050, -0.315650, -0.450230, -0.964710,
3.034020, -1.161040, 1.910110, 0.393790, 0.045720, 0.188700, -2.521210, 1.160600, -1.100290, -0.391640,
1.331500, 0.797370, -0.783320, 1.511900, -1.373240, -0.589760, -0.968110, -1.668770, -1.749600, -0.109550,
-0.558670, -0.824360, -0.842990, -0.856050, -0.100560, -0.789580, -0.503160, 0.660300, 0.214120, 0.095010,
-0.911990, 0.355850, -0.900280, 0.290050, -0.058490, -0.932360, 0.410350, 0.642080, -0.265810, 0.548200,
-0.764180, -0.845350, -0.595750, 0.437110, -0.178100, 0.141040, -0.022260, -0.421960, 0.967980,
-0.008380, -0.344450, -0.000470, 2.178950, 0.295540, -0.720440, -0.287280, 0.235560, -0.332360, -0.049400,
0.408590, 0.511700, -0.486720, 0.554720, -0.363970, -1.262660, 0.158140, 1.459050, -2.343490, 0.946130,
-0.371500, 0.002010, 1.128490, -0.513700, -0.400460, -0.005320, 0.339540, -1.069380, -0.840570, 0.206400,
0.406860, 0.254530, -0.721460, -1.508310, 0.096000, -0.075000, -0.126950, -1.355060, -0.535320, 0.600040,
-0.645580, -0.083900, -0.226970, 0.519780, -0.271420, 0.221230, 0.750000, -0.541860, 1.577950, -0.124870,
0.054300, 0.031400, 0.940030, 1.687820, 0.158650, -1.841090, -2.393140, -0.100190, 0.397550, -0.430610,
1.262820, -0.688790, -3.046130, -0.587130, -0.780730, -1.309880, 0.505800, -0.470810, 0.765600, 1.045410,
3.018950, 0.273840, 0.456300, 0.389910, 0.305380, 1.076540, 0.188250, -1.198340, -0.347500, 0.430880,
-0.150770, -1.392060, 1.826420, 0.370010, 1.307360, 1.230170, -0.812290, 1.040800, 0.162350, 0.185980,
-0.603150, -0.206280, -0.702920, 0.538480, -0.157270, -4.624410, -0.639800, -0.383750, 0.920180, -0.155390,
-0.756720, 0.645120, 0.075610, 0.733360, -0.118810, 0.580890, -0.259140, 0.788790, 0.154190, 1.364540,
-1.662330, -0.585320, -0.955340, 0.620440, 1.150850, -0.112700, -0.528530, 0.116080, -2.524380, -1.113430,
-1.545190, 0.711580, -0.984910, -0.816710, -2.043240, 0.511860, -0.211310, 0.911590, -1.790330, -2.095810,
2.677040, 0.511170, -1.021290, 0.125480, 0.692300, -2.940160, 0.215010, 0.030570, -2.040260, 3.447030,
-0.961510, 1.030170, 0.054910, 0.076290, 0.826480, 1.409460, 0.006370, -6.271000, -1.459270, -0.453240,
-0.982480, -1.067610, -2.857730, -0.088490, -0.929450, -3.629250, -3.031050, 0.395730, 1.578000, -0.961520,
2.052920, -1.258010, -0.027560, -0.946290, 0.599390, 0.097480, 0.863150, 0.700330, 1.050820, 1.246210,
-0.494110, 0.120010, -0.869540, -1.341660, -2.747920, 0.012480, 0.002420, 1.526810, -0.020950, 0.222710,
-0.141680, -0.252250, -0.108970, 1.080870, 1.304480, 0.315240, -0.587850, 0.816990, 0.309620, -0.327620,
0.729050, 0.066930, 1.018650, 0.941600, -1.024360, -0.768950, 0.715830, -1.055910, 0.534130, -0.420370,
-0.449840, 0.701420, 0.519260, 0.534120, -0.687800, 0.234940, -0.627290, -0.481320, 0.476150, -0.899050,
-1.315230, -0.160490, 2.624060, -0.959690, -0.001780, -0.438870, 0.794810, -0.534800, -2.689540, -0.165970,
0.003560, 0.038980, 0.925390, -0.800670, -0.642750, 0.498280, 0.874830, -0.302620, -0.000910, 0.505290,
1.730170, -0.133930, 0.006910, 0.707540, -0.569090, 0.322330, 0.855750, 1.001950, -0.082000, -0.650500,
-0.637620, 0.214920, 0.724920, -0.546440, 0.208710, 0.090860, 0.253150, 0.132620, -0.150940, 0.553750,
0.326200, -0.949060, -0.657880, 2.937870, -0.988790, -2.230150, -0.161280, 0.636340, 0.568380, 0.855870,
0.811740, 0.815490, -0.378520, 0.493130, -0.463830, 7.005300, 0.501890, 0.161810, -0.124530, 0.875360,
0.391050, 0.207470, -0.106730, 1.040930, 0.695010, -0.708160, 0.492900, -0.077580, 1.376220, -0.239150,
-0.369330, -0.018790, 0.288350, -0.507590, 0.572320, 0.043670, -0.316350, 0.732370, 0.486790, 0.588020,
-0.106100, 0.566430, 0.148990, -0.332450, 2.791670, -0.861800, 2.284480, 8.771210, 0.622030,
0.683930, 1.239880, -1.257550, -0.795920, 0.107120, -0.194020, -0.300370, -0.300820, -1.096160, -0.561410,
-1.911060, -0.392740, -0.358790, -0.518120, 0.634690, 0.316010, -2.088790, -0.280220, 2.792960, -1.225440,
-1.500330, -0.369940, -1.610770, -0.425200, 1.664440, 0.481810, -1.397880, 0.560190, -0.729760, -0.346770,
0.323640, 1.389390, -0.431450, -0.311790, 0.192710, -0.201470, -0.965790, -0.590920, -1.176910, 0.461710,
-0.340580, -0.690740, -0.692280, -0.329210, -1.160400, -0.255280, 1.369430, 0.294530, 0.065370, -0.287710,
-0.257920, -0.081360, 0.709750, -0.600830, 1.074260, -0.719250, -2.161390, -0.404400, -0.726460, 0.381860,
0.329440, -0.766510, -0.616190, 1.569680, -0.839510, -1.168120, -1.132060, -1.811300, 0.173730, 0.719910,
0.571730, -1.144980, -1.291650, 2.355440, 0.132300, 1.639730, 3.812500, 1.522630, -1.056290, -0.686070,
-1.406860, -1.013970, -1.221350, -0.824060, -1.180450, -2.640930, 0.494470, -0.185600, 0.049260, -1.062360,
-1.365810, -0.895340, 0.230780, -0.871740, -1.264430, -0.969930, -1.195140, 0.502730, 0.522390, 0.051790,
-1.717040, -0.490130, 0.296440, 1.202790, -0.057810, 0.437320, 0.144290, -0.536960, 0.885320, -0.435940,
0.643000, 0.482700, -0.388920, -0.323340, -1.165420, 1.341320, 0.709190, 0.169080, -4.165450, 1.241740,
-1.383670, -0.029820, 0.037210, 2.282220, 5.880790, -1.717840, 1.046420, -0.843990, -1.020300, -2.618620,
0.733930, -1.120450, 5.324820, -0.353770, -1.482300, 6.527790, -2.127600, -5.228060, 0.884240, -1.080070,
-1.066510, -0.255340, 1.249870, -0.099220, -0.116440, -0.126020, -0.041350, -0.939640, -0.439950, -0.284600,
-1.314850, -0.877890, -1.038720, 0.029760, 0.373290, 1.017200, -0.907720, -0.880030, -0.796280, 0.760660,
-1.175560, -0.116360, -0.400230, -0.316440, -1.546540, 0.232120, 0.022810, -1.386420, 2.155760, 0.295830,
-0.718900, 1.269670, -0.063390, -0.502950, 0.422610, 0.908450, 1.333050, 1.135470, 0.079630, -2.167570,
-0.431850, 0.806540, 0.580550, -0.572870, -1.691420, 0.950400, 0.345100, -0.352850, -2.042860, -1.075310,
-1.246510, 0.670580, 0.144310, -0.344840, 0.681380, -0.481730, -1.217210, -1.478030, -1.118810, -0.923160,
-0.105640, -1.168030, 1.668860, -1.121550, -0.377240, -0.624520, 0.432470, -0.283260, -1.292370, -0.317150,
-1.058520, 0.204420, -0.774600, -0.283680, -0.800680, 0.705150, 0.945030, -0.357950, -0.309380, -0.534700,
-0.108840, -0.950000, 0.138090, 0.467240, 0.948570, -0.255120, -1.153460, -1.445150, 0.796210, 1.305140,
-0.213670, -2.198080, -2.141100, 0.581210, -1.177430, 1.150050, -1.848140, 0.678260, 1.334280, -0.311980,
0.544930, -0.099880, -3.579140, -1.268080, -0.255140, 0.648350, -0.698600, 0.605890, -0.655620, -0.666230,
-1.948720, 0.639360, 0.126230, 0.178140, -0.062830, 0.924810, 0.586050, 1.019170, 0.912280, 0.848540,
-0.571630, -1.020810, -1.663170, -0.766000, -0.415240, 0.285340, 0.643870, 0.014090, 0.117240, 0.428600,
1.070460, 0.378680, -0.089140, -0.182420, 0.327370, 0.762340, -0.656230, -0.045680, 2.265850, -0.736740,
-0.336760, -0.764520, 0.624530, -0.163680, -1.005370, -0.328650, -0.598350, 0.934210, 0.716620, -0.259110,
-1.016530, -0.454450, 0.742360, 0.411820, 0.770310, 0.157650, -0.467060, 0.182260, -0.096810,
-0.756330, 0.291340, 2.393620, 0.139840, -0.965720, 1.073510, 0.175010, 0.383860, -0.568370, -1.006530,
-0.415060, -0.024970, 0.490500, -0.702430, 0.625620, 0.210230, 2.896710, 0.318530, -0.328370, -0.689130,
-0.622750, -0.857990, -0.050220, -1.303140, 0.708850, 1.006530, 1.490040, 0.391040, -0.230630, 2.034400,
0.637000, 0.752650, 2.479990, -0.614990, -0.193830, -1.220230, -0.486160, 1.272160, -1.096950, -0.812120,
0.450420, -0.646750, 0.996940, -0.470210, -0.443200, -1.563310, 1.372370, 0.261110, 0.807670, 0.161740,
0.259180, 0.330100, 0.954580, 1.485420, 1.261930, 2.247330, -0.427910, -0.253750, -0.392330, 1.061680,
2.071200, -0.541790, -1.560220, 1.051910, -0.799620, -0.042550, 0.213110, 0.472760, -0.572800, 1.530870,
1.797030, 0.454730, -0.754600, -0.483400, 0.573290, -0.486640, -0.652730, -0.051890, -1.314840, -0.156960,
-0.383690, 0.074890, -1.630850, 0.138930, -1.274860, -1.632250, -0.798900, 0.550820, -2.198060, -0.288300,
-0.629650, 1.501960, 0.118460, 1.048640, 0.333730, 1.240540, 1.502790, 1.681120, -0.370450, 0.057940,
0.009100, 0.672540, 1.516270, 0.222110, 1.700780, -0.336950, 0.644130, 1.568880, 0.181500, 1.511730,
0.027240, -0.434980, 0.812970, 0.694750, 0.456290, 1.889360, 0.594810, -0.136440, -6.386590, 3.589010,
0.900560, -3.307350, 1.647020, 1.345780, 2.264460, -1.541240, -1.497950, 0.824830, 2.639390, 0.434800,
-1.524140, -0.031340, 3.290320, -0.736450, -1.164840, 5.981280, 2.299930, -1.192690, 2.297790, 0.901580,
-0.030970, -0.863140, 0.213360, 1.977290, 0.563300, 1.155640, 0.754650, 7.494580, 0.929390, 0.091700,
-0.158080, 0.717430, -1.027250, -0.987050, -0.354850, -0.495520, 0.486580, -0.668040, -2.595530, -0.124000,
-0.142020, -0.538940, 1.742530, 1.487990, 0.426050, 1.903770, -1.704110, -0.007490, 1.932870, 0.009850,
0.561800, 0.813430, 0.292100, -1.396060, 0.353570, 1.007460, -0.919250, 0.029280, 1.277830, 0.843640,
0.399760, 0.875640, 1.006600, -0.998980, 0.293720, 1.859390, 0.911440, -1.338320, 0.108800, 1.726660,
1.164530, -0.192500, -0.044950, -0.891970, 1.085630, -0.414430, -0.743290, 0.307120, 0.166730, -0.800190,
1.689870, 3.057230, -1.988310, -1.295220, -2.393830, 1.341350, -2.156600, -0.169040, -0.296290, -0.404490,
-1.436940, -1.281980, -0.085840, 1.154850, -0.999640, -0.467300, 1.179450, -1.247960, 0.715880, -0.549950,
-1.109570, -1.637530, 0.043910, 0.551370, 2.574670, -0.419960, -0.330740, -1.253060, -1.218560, 1.126220,
0.255530, -0.057630, 0.749910, -0.827040, 1.254950, 1.199680, 0.132110, 0.569710, 0.245550, -0.141400,
-0.726080, -0.424240, 0.030620, -0.771440, 2.594520, 0.806850, -0.543350, 1.880650, -0.086240, -1.845870,
-1.297210, -0.559500, -0.030530, -5.981180, -0.182940, 0.774710, 0.158460, 0.391490, 1.010570, -0.770830,
-0.429870, -0.372790, 0.468880, -0.271830, 0.126910, -0.031980, 0.671120, -0.650740, -0.309810, 0.806380,
-0.088490, -0.336000, 0.231270, -0.305620, 0.150080, -0.264770, 0.355860, 0.355940, -0.590270, -0.058180,
-0.056750, -0.132850, -0.077670, 0.567720, 0.674840, 0.788510, 0.533080, 0.772790, -0.862440, -0.808260,
0.344490, -0.559530, -0.232210, 0.737490, 0.108740, 0.708410, 0.095240, -0.892080, 0.019430,
-0.391350, 1.338930, 0.323630, 0.304930, 1.429840, 0.245340, 0.047120, 2.758370, 0.431230, -0.108150,
1.560030, 1.210430, 0.086150, 0.452270, -0.242310, -0.170780, 0.288110, 0.436470, -0.043310, 0.220010,
0.499570, -1.048110, 1.452870, -0.156200, 0.620530, 1.337290, 0.788940, -0.508810, -0.133220, -0.049690,
-0.194730, -0.222840, -0.462870, -0.522260, 0.596720, 0.288690, 1.360000, 0.130940, -0.012480, -0.979490,
-1.014400, -1.486520, 0.272340, 1.534580, -0.833060, 0.230550, 0.281640, 0.486000, -1.887070, -0.031570,
-1.003100, -1.239160, 0.608480, 0.961750, 0.357690, -0.609890, -0.366030, 0.330200, 0.194800, 0.724280,
-0.016570, -0.649780, 0.859470, -1.166540, -0.686540, 0.953030, -0.150900, -1.297950, 0.931840, -1.613100,
1.193780, -0.472290, 2.778180, 0.093940, -0.295470, -1.473160, 1.031520, 0.386600, 2.802940, 1.613560,
1.043760, 0.093180, 0.623350, -1.126270, 0.437790, 0.175380, 1.373440, 0.352260, 0.208310, 1.141800,
-0.688630, 1.470140, 0.287010, 0.504870, 1.025360, -1.521800, 0.506390, 1.805110, 0.810620, -2.427320,
-0.406970, 0.198560, -0.204170, 1.640370, 0.398170, -1.379080, 1.004240, -0.202220, -1.101640, -1.056560,
0.711120, -1.913710, 0.546800, -0.430440, -0.413940, -1.173200, -0.192760, -0.724830, 3.183500, -1.757330,
0.420050, 3.588670, 0.131450, -3.043270, -5.503440, 2.585310, 1.559690, 1.593550, -0.945470, 0.823900,
1.639990, 0.089730, -6.247910, 0.289710, 1.404770, -2.874710, 0.541860, -0.294070, 0.326890, -0.260590,
0.481140, 0.946920, -0.092540, 0.047700, -0.631420, -2.499200, 1.425550, -0.295710, 0.357280, 0.424140,
-0.688820, -1.046480, 0.476490, 0.434290, 0.778450, 0.765570, 0.766590, 0.545770, -0.895610, -0.086440,
1.705410, 1.613630, -0.962320, 0.303090, 0.086220, 0.965280, 0.048120, -1.268270, -0.826980, 0.507410,
-0.290250, 1.365030, 1.473430, -1.127590, -0.515900, 0.108800, 0.906790, 0.169100, 0.186710, 0.598280,
-1.150010, 1.352960, -0.337430, -0.764690, 0.730130, -0.238370, 0.776320, -0.556870, 0.599130, -0.933010,
-0.228440, -0.644470, 0.235070, 0.018530, -1.672630, 0.319520, 0.961030, 0.329060, 0.452460, -0.331760,
0.055760, 0.986300, 0.852210, -1.313260, -0.086720, -0.462070, -1.149020, -0.885190, -2.139880, -0.067110,
1.943800, 0.124360, 0.173010, 0.886790, -1.026970, -0.503270, 0.090950, -0.199070, -0.098400, 0.833570,
0.060380, 0.447990, 0.773930, 0.753800, -0.429990, 3.539540, 0.028270, 1.214540, 1.432400, 0.370790,
-0.614100, -0.554690, -0.219860, -0.105220, 1.058700, -0.015360, -0.729630, 0.139350, -0.631350, -0.219510,
0.082200, 0.823270, -1.070360, 0.008650, 0.432100, 0.573390, -0.530490, -0.115750, 0.157560, 0.817290,
-0.153130, 0.597730, -0.636920, 0.046250, -0.619130, -0.471920, -1.004080, 0.219410, -0.996660, -0.035580,
0.429630, -0.747140, 6.162110, 1.778140, -1.027770, 2.401060, -0.888640, -0.145160, 0.280160, 0.754880,
-0.764510, -0.484710, 0.894330, -0.807150, 0.780260, 0.951780, -0.726760, -0.232000, -1.430990, 0.041770,
0.833010, 1.014900, -0.237350, 0.736740, 0.929650, -0.528600, -1.179050, -0.784990, -0.313540, 0.670920,
-0.826450, -0.163920, -0.272720, 0.222680, 0.719660, 0.899850, -0.366990, -0.724320, -0.066320,
0.615110, 1.628700, 1.321830, 0.853910, 0.191010, 1.459760, -0.600210, 0.643460, 0.249490, 1.865170,
0.101820, -0.580400, -0.479240, 1.784110, -0.384390, -0.944700, 0.071350, 0.678320, -0.615960, 0.621940,
-2.471600, -0.082070, 0.029810, 0.027770, 1.720430, -0.188810, -1.611920, 0.044280, 0.424790, 0.162450,
-1.136260, -0.524590, -0.290470, 1.902180, -0.875040, -0.360000, -0.150140, -0.925110, 0.434180, -1.202570,
-0.492300, -0.395540, -0.003480, -0.590670, 0.711670, -1.240070, -0.065940, -1.392570, -0.302970, -0.287640,
-0.439690, -1.678130, 0.631540, 0.225840, -0.091710, -0.278890, 0.811170, 0.082550, -1.306100, -1.165550,
0.779880, 0.851310, 0.566510, -0.795370, 0.725550, -0.340930, -1.939090, -0.399120, -1.723610, 1.563910,
0.147230, 0.085070, -0.047220, -1.071280, 0.922120, -1.207660, 1.454450, 0.027350, 0.180470, -1.352900,
-0.832930, 0.246750, -0.640450, 0.369430, -0.589490, -0.814090, 1.143030, 0.752440, -2.804650, -0.192380,
-1.033010, -1.453640, -0.561750, 0.894180, -0.772940, -1.033180, -0.457260, -0.255900, 0.140460, -0.304150,
0.507260, -0.306130, -0.482940, -1.681400, 1.975850, -0.243420, -1.056050, 0.665920, 1.224710, -0.341280,
-0.503240, -2.708530, -0.709390, -0.019350, -0.623450, 0.360970, 0.234950, -0.908480, -1.108040, -1.083030,
1.713120, -0.364050, -1.929880, -0.835650, 0.712030, -0.058140, 0.500730, -0.103710, 0.794530, -0.258090,
-0.817000, -0.809710, 0.199820, -0.249210, 0.119170, 2.740240, 0.017260, -0.490340, -0.476840, 0.402130,
-2.156130, -0.139780, -1.222760, 0.211790, -0.301520, -0.214300, -0.047620, 0.490740, -0.459910, -0.510870,
0.519830, -0.616180, -0.631670, 0.227860, 0.074030, 0.079650, -0.459890, -0.941410, 0.451280, -0.161080,
0.626150, -0.608850, -0.628800, 0.111550, -0.836500, -0.865920, -0.319210, 1.128540, -0.777930, 0.209490,
-1.465680, 1.389200, 0.552370, 0.628470, 0.121390, -0.340740, 0.072420, 0.215830, 0.196430, -0.163710,
-0.059560, -0.433570, -0.593180, 3.781980, 0.391940, -0.098360, -0.869170, -0.285750, -0.381110, -0.621950,
0.161950, 0.474190, -1.691950, 0.722650, 1.316080, 0.285060, 0.766670, -0.542470, -0.863450, -0.858300,
0.666880, 1.566390, -1.284540, -0.133450, 0.112980, 1.230750, 2.383850, 0.754900, -0.636570, -0.657300,
1.035330, -0.296720, 0.191340, -0.581480, 0.935100, -0.154080, -1.632670, -1.662700, 0.121920, -0.056600,
1.122850, 0.650800, 0.483230, -0.967090, 0.707590, 0.421290, 0.931060, -0.831690, 0.322420, -0.209630,
-0.833190, -0.413710, -1.101320, -0.565730, -0.260540, -0.899090, -0.213300, 0.268720, 0.528670, -0.401600,
0.319990, -0.030720, -0.359650, -0.123620, 0.644670, 2.154420, -0.162010, 0.270600, -1.009050, -1.165120,
-0.919920, 0.805150, 0.912770, 28.531059, -0.597450, -0.037120, -0.842600, 1.108460, 0.417640, -1.734560,
-2.141970, -4.595390, -0.628290, -1.939330, 0.939860, -0.622820, -1.208050, -1.719840, -0.814900, -0.098000,
-0.871060, -1.102340, -1.125920, -0.271510, -0.675100, -0.601980, -0.252950, -0.727800, -0.484900, -1.496330,
-0.851550, -1.625460, -0.201920, -2.111630, -0.723890, -0.197620, -2.300040, -0.555570, -0.836860, -0.038300,
-0.052520, -1.875300, -0.520490, -1.897730, -1.772120, -1.428030, -1.264990, -0.252920, -1.200560,
1.064810, -0.138290, 1.091200, 1.486000, -0.440300, -0.318440, 0.978620, 0.116040, 1.857490, 0.322330,
-0.498100, 0.064600, 1.553050, 1.500910, 0.548220, -0.535690, -0.132610, -1.099140, 0.346040, 0.368690,
-0.541790, -0.721050, 0.058490, -0.933090, 0.713360, 0.528960, 1.412180, 0.925720, 0.522210, -0.524540,
0.654900, -0.356300, -0.843310, 0.965970, 1.090570, -0.645780, 1.941360, -0.734710, 0.394260, 1.271140,
-2.077980, -0.045970, -0.282150, -0.850540, 1.393740, 0.229950, -1.826050, 3.967630, 0.136210, 1.693740,
-0.313650, -0.104290, 0.249090, 0.562720, -1.547220, -0.431520, 2.127310, 0.773110, -0.874580, 0.935170,
-1.180380, 0.716560, 2.285860, -2.463860, 0.355600, 0.920040, 0.139090, 0.790440, -0.880140, 0.184540,
0.940450, 1.204170, -0.209400, -0.563880, -1.122940, -0.909310, -0.720280, -0.600130, -0.171670, 1.558360,
0.554900, -1.108480, 0.140980, 1.249060, 0.600120, 1.673550, -0.588600, -0.245180, -1.740520, 0.276440,
0.322600, -0.825160, -0.412900, -2.435040, -0.241500, -2.716520, 0.605380, -1.390660, -0.663160, -0.975420,
-0.795590, -0.033440, 0.580270, 0.058620, 0.441820, 0.774670, 0.057550, 0.358510, 0.033880, -2.706970,
-0.741990, -0.325440, -0.184260, 0.868250, -0.769580, -2.171210, -1.710290, -0.655700, -0.305410, -2.056380,
-0.232670, -0.343690, -1.625930, -1.684420, -2.878390, -0.242770, -0.020900, 1.801340, -1.662270, -1.815460,
-1.800160, 0.431480, -6.614360, 0.492980, 0.677440, -4.765000, 0.450610, 0.555260, -0.277500, -0.481940,
-1.193360, -0.147880, -2.841890, -0.199180, 0.499240, 0.866590, -0.318650, -0.436420, -0.354610, 0.826550,
0.644110, -0.432290, 2.034820, 0.704000, 0.107520, 1.452600, 0.848170, 0.539560, -0.599080, -0.318950,
-0.390340, -0.675370, 1.238790, -0.446700, 1.328500, 0.045730, 0.746050, -0.245100, 0.113620, -0.895580,
0.126950, 1.079390, 0.784360, -0.657730, -0.722090, 0.389340, 0.584130, 1.718100, -1.238980, -1.047250,
-0.264150, -0.446430, -0.761020, 0.379960, -0.370410, -1.696340, -2.047520, 0.195040, -0.718880, 0.824040,
0.027250, -1.831680, -0.820340, -3.934540, -0.379910, -0.488610, -0.261360, -0.963940, 1.051180, 3.664820,
-0.010250, -11.983940, -0.347850, -0.887930, -0.046970, -0.844050, 0.450830, 0.425670, -0.827410, -0.847960,
-0.768450, 0.032360, -0.167130, 1.704020, -0.521150, -0.816880, -0.884660, 0.001780, -0.049620, -1.524180,
0.818090, 0.332670, -0.463730, -0.574290, -0.530600, 1.105590, -0.875300, -1.202410, -0.077070, -0.242550,
0.297290, 0.333420, 0.446530, 1.217630, -0.679310, -0.131600, -0.532830, -1.659820, -0.606910, -0.924260,
-0.399320, -0.323630, -0.347420, 0.323910, 0.610050, 0.276400, 0.170640, -3.295990, -0.666510, 0.491890,
-0.554970, -0.004240, 0.713300, -3.568330, -0.839680, -0.419780, 0.045680, 0.497780, 0.997020, -0.659530,
-0.346570, 1.259260, 1.543120, 0.744380, -0.474110, 0.597010, 0.384600, 1.117950, -0.094050, -0.046910,
-0.398950, 0.723550, -0.037970, 0.713910, 0.790490, -0.592090, 0.165440, -0.567760, -1.482800, 0.863020,
-0.734400, 0.962060, -0.099080, -0.505020, -0.407810, -1.025770, -0.739730, -0.518960, -0.997090, -0.754990,
-0.102470, -0.394370, 0.174940, -0.188650, 0.763150, 0.573750, 0.114300, 0.512220, 0.368480,
0.824960, 0.120230, -0.455100, 0.713220, 0.876330, 0.026860, 2.959050, -0.523620, 0.349250, -0.807530,
-0.631380, -1.815280, -1.582370, -1.570640, 0.861160, -0.055130, -0.538950, 3.026770, -1.191480, 0.018350,
-0.688040, -0.098050, 0.859490, 1.393190, 1.047490, 0.542160, 0.944110, 0.910050, 1.782220, 0.300520,
1.561120, 1.810000, 0.672930, -0.588660, 0.262680, 0.213070, -3.521470, -1.035130, -0.403890, -1.247890,
0.076330, -0.297430, -1.891780, -1.232600, -1.127320, 0.888570, 1.308080, -0.561480, 0.108840, -0.036230,
1.315790, 0.052250, 1.619440, 1.098420, 1.913060, 0.659900, -0.779390, -0.077970, 1.351000, -0.492170,
-0.228920, -1.579100, -0.242490, 0.271740, 1.419780, -1.007970, -0.653160, -1.867660, 0.199430, 1.028580,
1.050390, -0.501380, 0.432730, 0.875490, 0.135030, 1.063170, -0.287570, -0.209950, 0.408850, -0.213580,
0.489360, 1.282110, -0.260010, 0.198070, -1.151300, -1.807350, 0.365980, -0.969740, -1.744310, -0.742640,
-0.389560, -0.162690, -1.416990, 0.775280, -0.397420, -1.399630, -0.815030, 0.035610, -0.350950, 0.176870,
1.229310, -0.463230, -0.684440, -0.649000, -0.875040, -1.649600, -1.445220, -0.108620, -1.229810, 2.611500,
1.645470, -1.659420, -1.800250, -0.983440, -1.386080, 0.463640, 3.328390, 0.146050, -0.942940, 1.741130,
-0.619180, -2.065070, 1.140630, 1.565980, 0.990900, -1.341690, -1.478140, -1.080110, 0.112990, -0.594360,
-0.569540, -1.089950, 5.306220, -1.574030, -1.552720, 5.574150, 0.347980, -0.362240, -1.381180, 1.132890,
-1.093960, -0.622240, 1.074400, 0.589490, 0.070080, 0.572430, -0.213520, 0.570530, 0.086740, 0.512500,
0.391130, 1.401390, 0.713730, 0.152590, 0.055060, 0.832410, -0.899350, -0.083930, -2.420070, -0.185460,
-0.622080, -0.634730, 0.549120, 0.729000, 0.249470, -0.018090, -1.288300, 0.764910, 1.127530, -1.734050,
0.784490, -0.017850, 2.277180, 1.541150, -0.885480, 0.876300, 0.611280, 0.522710, -0.460570, -0.273300,
1.421110, -1.512040, 1.849270, -0.097500, 0.857650, 0.935070, 0.317180, -4.894810, -1.055020, -1.819060,
0.106050, 1.014240, -0.790270, -0.545760, 0.796420, 0.164670, 0.066540, 0.203530, 0.435330, -0.127470,
0.429580, 0.377540, 1.509350, 2.620820, -1.067300, 2.315680, -0.921250, -0.334970, -0.879130, 0.224040,
-1.621100, -1.285860, 0.158250, -0.047880, -0.157160, -0.524910, 0.320060, -0.818600, 0.075290, 0.246050,
-1.845410, -0.800530, 1.257360, -0.560210, -0.128190, -1.241200, 0.675800, -0.123570, 0.227290, -1.540590,
-0.526570, 1.490310, -0.403780, -0.685420, -0.345500, -0.790310, 0.776780, 0.217350, 0.301710, -0.710980,
0.078290, -0.582050, -0.840900, -0.057490, -0.217520, -0.167520, 0.013700, 1.663930, -0.868240, 0.522180,
-3.947810, 2.171490, -0.870290, -0.027030, 0.049170, 0.794740, 0.369410, 0.040640, -0.177750, -1.043610,
-0.275280, -1.130660, -4.003830, -0.898680, 0.463450, 0.421490, -0.972700, 0.692130, 0.627250, 0.702960,
0.690670, 0.193370, 0.650180, 0.193480, 0.938420, 0.344050, -0.982950, -0.339890, 1.312430, -0.567120,
-0.331960, -0.398190, -0.441380, -0.352250, -0.298630, 0.013770, 4.092960, -0.476670, 0.039230, -0.427840,
-0.878940, 0.489920, 0.144070, 0.969310, 0.274480, 0.570190, -1.052240, 0.382380, -0.926600,
-0.395080, 2.016500, -0.975340, 0.455290, -0.358120, 1.376600, -0.034090, 0.979400, -0.161930, 1.011880,
0.198630, -1.816540, -0.472570, 0.247230, 0.010360, 0.226920, -1.196640, -0.302750, -0.465660, -0.795840,
0.682610, -0.658070, 1.324670, 0.959400, 0.864980, 0.280110, -0.001590, -1.072260, -1.490030, 0.856710,
3.765720, 2.708270, -0.991320, -0.751200, 1.299460, -1.039200, 0.884420, -0.779060, -0.797470, -0.414150,
-0.208320, 0.967990, 0.891460, -1.375430, 0.128130, 1.218190, 1.201310, -0.658170, 0.543890, 0.173830,
0.967740, -0.337270, 0.912620, 0.170160, 0.670330, -0.162630, -0.093770, 0.178620, -0.023710, -1.563260,
-0.285330, -0.351590, -0.394110, 0.096480, -0.119760, -0.033730, -0.582670, 0.157740, 0.606960, -0.003280,
0.105810, 1.049260, 2.263430, 0.650370, -0.593780, -0.323230, -0.400540, 2.101260, 2.170100, -0.861680,
0.560960, 1.116590, 0.003300, 0.169520, -0.419040, -0.537200, 2.248290, -0.318310, 0.589670, -0.413180,
-0.177900, -1.273320, -0.830400, -2.145580, 0.827420, 0.521460, 0.317430, -0.172420, 0.457210, 0.283370,
0.502770, 2.067270, 0.274000, -0.004940, 0.348080, -0.886640, 0.367640, -0.282850, 0.632370, 1.571450,
-0.245410, 1.082230, 0.217520, 0.519670, -0.785380, 0.721450, -1.194440, -0.314960, 3.161300, 0.058070,
1.710600, 2.747270, -0.853640, -0.936990, -1.527500, -1.252900, 3.598150, 0.052710, -1.731770, -1.881190,
-0.522470, 2.126900, -1.340920, -1.643920, 0.312560, -0.617390, -0.117560, 1.393080, -0.367560, 0.233080,
2.012090, 1.777420, 1.339100, -2.013360, 0.865130, 2.886110, 0.057190, 0.985400, -0.275600, -0.206740,
0.560180, -2.064310, 0.853020, 0.247750, 0.722460, 0.243020, -0.186940, 0.192480, 1.399910, 1.191880,
0.955990, 0.893620, -0.451420, 0.321850, 1.550820, -0.600330, 0.534900, 0.189630, 0.753620, 0.618760,
1.105590, 0.793650, 1.754900, 1.890400, -3.615060, -1.426030, 0.857130, 0.441540, -0.319510, 0.911190,
-0.454030, 0.354420, -0.197540, 2.896580, 0.226040, -3.878560, 0.123150, 1.155030, -0.119080, -0.471200,
1.265500, -1.320090, 1.606210, -0.240050, -0.443820, 0.741970, 0.699780, -2.909280, 0.057540, 1.319470,
0.633460, 0.039290, 1.335460, 1.530490, 0.597230, 1.053260, 0.629280, -0.314060, -2.054970, -0.291460,
-0.634630, 0.491410, 0.776290, 0.377690, -1.949650, -2.861670, -3.207920, -0.253470, 0.801040, 0.533450,
0.742980, 0.095230, 0.255620, 0.828710, 1.500920, 1.435670, -0.296450, -0.366750, -0.044070, -0.689150,
0.722520, -1.677540, -0.946870, -0.884130, 1.026300, -0.383530, -0.350930, -0.060160, 0.466250, 0.768030,
-0.699620, 0.924850, -1.035440, 0.650320, 0.430580, 0.722070, -1.164660, 1.744660, -0.408150, 1.056610,
0.946220, 0.282310, 0.901090, 1.187560, 0.702010, -2.266390, -1.681530, -0.234170, -1.407160, 0.095580,
-0.494090, -1.413570, 0.341530, 1.713660, -0.307770, 1.399210, -0.130470, 0.217660, -1.053580, -0.689990,
-3.668310, -0.398240, -1.578660, 0.284100, -1.806650, 0.019820, -0.217840, -0.968180, -6.628610, -2.677120,
-0.198190, -0.168000, -0.729630, -0.333910, -0.719080, 0.043290, -4.238170, -0.181640, -1.163200, -1.243010,
-0.002310, -0.446240, -0.631350, -0.890630, -2.068880, -1.071450, 0.263130, 0.132910, -1.989310,
-1.502370, -1.096170, 0.431430, 0.403330, -2.270900, -1.005160, -0.472540, 0.483590, -1.409180, -0.585720,
-0.256180, -0.360610, -0.216540, -0.746720, -2.217590, 0.505390, -0.866310, -1.811470, 0.735250, 0.741850,
0.420810, -0.212670, 1.271930, 0.502590, -1.025280, -0.223360, 0.431560, -0.143310, -0.973570, -0.362330,
1.645330, 1.578390, -0.942540, -0.211890, 1.378350, -1.150130, -0.650960, 0.090440, 0.516940, 1.385100,
0.019090, -0.567040, 0.202830, -0.000580, -0.731290, 2.555220, -0.248170, 0.512040, 0.712370, 0.300790,
-0.869260, -0.374220, -1.444310, 0.564230, -0.677010, -0.177400, -0.100780, -0.666690, 0.266090, -1.601340,
-0.479140, 0.621500, 0.157760, -0.977430, -0.551160, -0.148770, 0.373860, -0.827790, 1.873440, -3.389900,
-1.118140, -2.038690, -0.487700, -1.460860, -1.103190, -0.521090, -0.549840, 0.437870, 0.928830, -0.386130,
2.502310, 0.977850, -1.864290, -2.405910, 1.382800, 0.861070, 0.829590, 0.551290, -0.304520, 0.505980,
1.111330, 0.299280, -0.555260, 0.256880, 0.033240, 0.532460, -0.055370, -1.182320, 0.385060, 0.196430,
1.530060, -0.133310, -0.477820, 0.335490, -1.691250, 0.041570, -0.660800, 2.851640, 0.969800, 1.243630,
0.940530, -0.417100, 1.300040, 0.094270, -0.559880, 0.106260, 0.115470, 1.859520, 2.366500, 0.705420,
2.767490, -0.828830, -0.096050, 0.865130, -0.489610, -1.101690, 1.192780, -1.211060, -0.379750, -1.338760,
-0.053930, -0.758920, 1.310810, 0.369760, 0.333640, -0.033140, -0.211490, -0.441470, -0.299580, 0.990610,
-0.060460, -0.058250, -0.468990, -0.620460, -1.357020, -0.816680, 0.975250, -0.031330, -0.798770, 0.212210,
0.587090, -0.299130, 0.289900, -2.151560, -0.796450, 1.269280, -1.172950, 1.070710, 0.146120, -0.832070,
0.427270, 2.100340, 1.649020, 0.928900, 2.541800, 0.116560, 0.193930, 0.817370, 2.944170, 1.752840,
0.457110, -2.270960, -2.155690, -0.459430, 1.504470, -0.015590, -1.649670, -2.370070, -0.331440, -1.100290,
0.270020, 0.285330, -2.530060, 1.348450, -0.191470, 0.396270, 0.532490, -0.094970, -0.382230, -0.256320,
-0.853940, 0.665330, 0.029530, 1.081260, 0.931420, -0.565520, -1.052080, 1.142170, 0.570810, -0.482250,
-2.542870, 2.875680, 0.294780, 0.692530, 0.749060, 0.348030, -0.407360, -0.650150, 0.676110, -1.389040,
0.795670, 1.672110, -0.053250, -0.653590, 0.925550, 1.777590, -0.012280, -1.078670, -0.945540, 0.625570,
0.086800, 0.684670, 0.277450, 0.412920, -0.012830, -0.393870, 1.117740, 1.526660, 0.629840, 0.967020,
-0.534280, 0.469800, -0.402900, -0.318890, 1.626180, -1.260540, -0.864860, -0.409900, 2.623320, -0.730450,
0.631540, 0.039480, 1.001300, -0.367380, 1.569250, -0.442920, -0.746830, 1.791190, 0.533830, 0.613820,
1.506020, 0.528670, -1.163420, 18.635851, -0.563700, 0.559240, 0.594140, -0.025870, 0.489920, -1.862180,
0.470220, 0.133590, 1.041700, 0.175010, -1.412040, 0.583190, 2.214030, -0.221520, 0.207520, -0.449280,
1.001970, -0.194920, 0.084000, 0.894200, 1.811390, -0.552090, -0.729890, -0.136910, 1.919670, 1.237240,
0.721820, 2.641580, 1.263130, 1.437180, 0.292740, 0.445870, 0.750750, 0.586260, 0.606520, 0.754120,
0.743500, 0.366530, 3.061650, 0.025610, -2.247610, 1.861650, 1.184900, 4.039780, 2.182010,
-1.039100, 1.341040, -0.196090, -0.187110, -1.232690, 0.952410, -0.437300, 0.784240, 0.110040, -0.795920,
-2.262380, 0.725460, -0.899700, 0.468410, -2.199780, 2.067350, -0.341000, -4.100550, 1.146590, 1.201670,
3.157060, -2.446520, 0.465230, 1.126340, -0.137840, -3.156710, 0.531490, 0.631240, 0.190310, 1.095300,
1.356960, 1.096830, 0.227860, 0.636690, -1.016250, 1.197550, -0.721340, 0.558800, 1.860220, -1.014750,
-0.986940, -0.026850, -0.018460, 2.169970, -0.474590, -0.333030, 0.197270, 0.394720, 0.373600, -0.731250,
0.636340, 0.383250, -0.451540, -0.730080, 0.646440, -0.184610, 0.453010, 0.661730, 2.247340, 1.454170,
0.845870, 1.154240, 0.126280, 0.252480, -0.831510, 0.196430, 1.306030, 0.320460, -0.902940, 0.136710,
-0.433060, 0.115830, 0.014440, 1.250150, 0.580140, -1.087320, 1.697970, 0.865080, -0.777050, 1.384480,
0.370500, 1.899890, 1.614450, 0.018810, 0.974120, 1.868370, 0.137520, 0.326430, -0.373540, 2.353700,
0.561820, -0.030720, -0.616540, -0.122270, -0.106610, -0.307570, 0.223100, -0.748010, 0.443280, 0.950910,
0.864470, 0.125410, 1.085590, -0.537080, -0.012480, -0.165570, -0.605570, -0.785000, 0.404850, -0.707600,
-0.321570, -0.735890, 1.365880, 0.098980, -0.891770, -3.120150, -2.003690, -1.209930, 1.242280, -0.760980,
-1.692150, 1.136900, -1.449210, -2.937680, -1.211550, -0.574400, 0.042050, 1.420130, -1.448530, 1.286420,
1.131810, 1.253160, -3.066040, 1.122250, 1.144340, -12.268490, 0.623520, 0.148770, 0.714350, -1.496950,
-0.203250, 0.189000, -1.488370, 0.123690, 0.725490, 0.408830, 0.523320, -0.101810, 1.112310, 0.154410,
-0.186930, 0.600440, -0.106540, 1.973460, -0.017000, -0.494800, -0.539290, 2.056970, 0.727960, 0.526070,
-0.350030, 0.299820, 0.157370, 2.145070, 0.374210, 1.000570, 0.393490, -0.797500, -0.791340, -0.608380,
-0.256170, 1.074660, 0.694250, -0.088350, 0.571080, 0.974310, 0.613610, 0.146130, -3.236510, 0.954240,
2.087720, 1.603900, 0.768810, 0.994220, -0.958300, -0.196380, -0.617840, -0.327950, -0.843600, -1.200000,
0.284190, -1.027340, -0.742760, -1.253630, -0.249080, 0.359170, 0.238350, -1.948580, -0.717030, 1.275230,
0.823570, -2.403850, 1.741100, 1.698620, 0.175890, 1.421000, 1.390570, -0.499260, 0.818070, 0.630320,
1.385120, 0.505280, -2.035410, 0.070520, -1.540730, 0.010440, -0.441800, -0.907800, -0.223670, 1.192110,
-0.438780, -0.409860, -0.458650, -0.361120, -0.677920, 2.515720, 0.484030, 0.812540, -0.049220, -0.295840,
0.609570, 0.183430, -0.324450, 0.954000, 0.196070, 0.465240, -0.864810, 0.335390, -0.250060, -0.882080,
0.405840, -0.086140, 0.814510, 0.153750, 0.952820, -1.048740, 0.290250, 0.808220, 0.467870, 0.602820,
2.862950, -2.614560, -1.924860, -6.198070, 0.148060, -2.058650, 0.680600, 0.490410, 0.135270, 0.245260,
-0.325040, 0.275570, 2.173910, 1.092800, -1.196400, -0.184540, 0.312680, -0.540400, 0.506090, -0.490540,
0.365980, -0.609370, 0.284750, -0.634040, -0.317350, -0.456390, -0.280230, -0.441370, -0.632440, -0.011540,
0.462860, -0.649950, -0.591140, 0.777450, -0.128520, 0.779120, 3.877090, 0.602400, 0.014400, -1.108310,
-0.596710, 0.177080, -0.536670, 0.190900, -0.924030, 0.749370, 0.798160, 1.527650, -0.850710,
-0.004280, -0.379190, -1.216840, -0.656400, -1.177860, 0.990580, -0.036950, 0.219050, -0.923790, -0.105810,
-1.829240, 0.306200, 0.239630, 0.630380, -0.794270, -1.102020, 0.560990, 2.342670, 0.449840, 1.066390,
-0.413740, -0.414380, 0.797520, -0.016470, 0.449790, -0.128400, 0.278910, -0.757230, -0.360980, -0.934930,
-0.096410, -1.545270, -1.077710, 0.785200, 0.387010, 2.364730, -0.514670, 0.456080, 0.414130, 0.029680,
-1.748680, 0.948410, -1.074710, 0.302960, -0.773200, 0.775880, 0.629530, 0.086590, 1.417860, 3.538230,
-0.051660, 0.254110, -2.651950, 0.022630, 1.106520, -0.523320, -1.326770, -0.315290, 0.051800, -0.527840,
0.273640, -0.205410, -0.530360, 0.006280, -1.059140, 1.597940, 0.220890, 0.581100, -0.307550, 1.480130,
0.780500, -0.975270, -0.640730, -0.030210, -0.563970, 0.705540, -0.277300, -0.006310, -1.025820, -0.488640,
-0.471390, 0.712700, -1.525630, -1.972080, -0.869270, -0.553840, -1.861150, -0.222770, -0.720280, -0.063070,
0.407060, -0.378710, 0.035960, -0.952080, 0.728650, 0.932350, -0.458320, 0.028740, 0.352450, 0.004260,
-1.310800, -0.725980, -0.773980, -0.350240, 0.556480, -0.612060, -0.572910, -0.530950, -0.848770, 0.092620,
0.636760, 1.236790, -1.638020, -1.186330, -1.500770, 8.511890, 3.064280, 4.010580, -2.566420, 3.101140,
-0.037350, -5.637350, 0.974420, 6.267840, 6.905270, -4.353400, 1.684680, -1.152960, 1.652710, 6.812860,
3.831630, -2.829880, 4.342430, -1.022400, 0.573820, -0.625750, -8.020740, -0.806420, -0.427600, -0.279520,
-0.551220, 1.246620, -0.202950, -0.702580, -0.414830, -0.108460, -0.632640, 0.119260, -0.770400, 0.989220,
2.173850, 0.370010, 1.840790, 2.543210, 0.838320, 0.690730, 0.312600, -1.066700, 0.090560, 0.472940,
-0.961530, -0.293730, 0.466130, -0.183860, -1.505100, 0.566920, 0.545900, -0.730920, -1.941550, -0.439670,
-0.002030, -2.371710, -1.262170, 2.711960, 0.686290, 0.085930, 2.765170, -0.097220, 0.391260, 1.293100,
-0.616470, -0.551310, -0.141560, -1.719630, 0.305770, -1.246630, 0.846390, -0.034500, 1.095580, 0.679420,
-1.177820, 0.021020, 0.534990, -0.333220, -0.987750, -0.465580, 0.896430, 1.361670, 1.247010, 0.486310,
-0.508580, 0.414980, -0.332000, -0.134830, -0.518140, -1.984350, -0.890950, -1.811590, -0.842030, 1.376590,
2.222860, 0.971650, -1.116360, -1.117920, 0.224370, 3.155190, -2.062620, -0.766070, -0.552870, 0.187290,
0.586870, -0.610040, -0.661930, 0.101250, 0.423050, -1.063160, -0.865530, -0.676290, -2.468080, -0.063900,
-0.264270, -0.306900, 1.793290, -0.291870, 0.712130, -0.792450, -0.119700, 0.998550, 0.328230, -0.535530,
-0.444300, 0.266620, 2.705410, -2.431350, 1.131550, 0.227510, 1.339900, -0.687070, 0.205820, 0.220730,
-1.477160, 1.549330, -1.432140, -9.097170, 0.734440, -0.425920, -0.247560, 1.451620, -0.707640, -1.370590,
-0.375890, 0.654130, -9.773010, -1.529410, -0.254600, -2.008020, 0.428330, 1.730360, 3.062040, -0.561680,
0.308900, 0.745760, -0.866820, 0.647930, 0.911910, -0.360050, 0.127540, -0.760850, 0.218810, -0.938030,
0.324950, -0.907950, 0.337280, -0.008700, 0.155140, 0.689700, -3.055530, 0.420290, 0.095090, 1.103520,
-0.130550, -0.545930, 0.579800, 1.050270, -0.726830, -0.239180, 0.380160, -1.334010, 0.593150,
-0.855770, -0.105770, -1.100400, -1.403400, 1.048810, 0.522880, -0.095090, 2.082330, -0.242090, 2.441840,
0.020860, -0.358690, 1.799480, -0.571840, -1.663110, -0.427380, 0.836870, -0.111050, 0.608150, 2.212140,
-1.663650, -0.314100, -0.128850, -0.518780, 0.315650, 0.481340, -1.180240, 2.550670, 0.042720, 0.464050,
-0.179260, 0.408220, 1.052930, -0.446850, -0.159670, -0.120740, 0.836390, -0.540090, -0.242440, 1.622250,
2.382440, 0.750760, -1.650730, -0.543530, -0.928340, -1.116250, -0.406070, 0.104860, 1.036940, -1.377910,
-0.104230, 0.522140, 0.332160, 0.736650, 0.741620, 0.935290, 0.124840, 1.363990, 0.324790, 0.152700,
-1.439970, 0.203780, -0.099360, 0.552520, -0.096290, 0.727100, -1.203640, 0.411820, -0.219780, -0.678280,
-0.612090, 0.539180, 1.071790, -0.737710, -0.051110, -1.374300, 0.445410, 0.898600, 1.169530, 0.996110,
0.609550, -1.138950, -1.450410, 0.205030, -1.536960, 0.242510, 4.202460, -0.565330, -0.988830, -1.792500,
1.186690, 0.346660, 1.205720, 0.876410, 1.527680, -1.653730, 2.240880, 0.608740, -0.212810, 0.018550,
0.436780, -0.469770, 0.475110, 0.281740, -1.774640, -1.602840, -0.369180, -1.140600, -1.122190, 0.479830,
-0.511710, 0.144680, -2.796040, -1.148040, -0.592750, 2.463770, 1.597670, 1.165100, -0.879110, 1.234420,
1.226950, -1.362750, 2.044380, 3.476900, 3.141420, 1.192340, -1.049170, -1.966000, 1.174010, -1.609360,
-2.579740, 0.026270, 3.986360, 0.139640, -0.544860, 11.859150, 2.413670, -0.294920, 1.535630, -3.079320,
-0.444990, 0.737880, -0.303630, 1.162710, 0.810760, 0.058610, 0.060480, 1.617760, 0.012840, 1.212540,
-0.218680, -2.088510, 0.485390, 0.965190, -0.788220, 2.260260, -0.154830, -1.534370, -0.381050, 2.148020,
-0.367660, -0.270470, -0.950180, -0.683390, -0.798880, -0.171680, 0.133130, -1.449090, 1.228020, 0.402270,
1.607560, 0.314170, 1.197340, 0.052250, -0.638940, 0.879280, -0.421080, -1.010860, 1.503290, 0.137300,
0.564560, -1.360030, 1.139450, 0.382370, -0.156120, -0.027820, 0.609240, -0.854600, 0.277670, -0.513950,
-1.030770, -0.900070, 0.873570, 0.104170, -0.520570, 0.621870, -0.588370, -1.107360, -0.704440, 0.608910,
1.276480, 1.670350, -0.143900, -0.617830, -1.250720, -0.053290, 0.547680, -1.671960, 0.488190, 0.697500,
-1.382620, 0.794020, 0.442800, 0.580910, -0.543620, 0.279440, 0.006170, 0.264850, 0.453100, 0.070470,
-0.240890, -1.100870, -0.683050, 0.219520, 0.082780, -0.489340, -0.499020, -1.551690, 1.256290, -1.521630,
-0.942520, -0.235430, 0.590100, -0.710950, -0.370210, 1.248570, 0.122460, 0.898420, -0.623710, 2.489160,
-0.523650, 0.458500, -1.042970, -1.332570, 0.704410, 0.602970, -0.650520, 1.726450, 0.474200, 0.033280,
-1.370930, 3.287900, -0.672490, 0.400820, -0.135860, 0.907070, 0.051150, -1.114310, -0.368000, -1.213590,
0.873580, 0.346760, -2.342890, 0.406770, 0.604970, -0.113360, 0.153550, -0.869750, -0.171130, -0.847680,
0.422410, 0.520190, -0.845110, -1.146580, 0.397490, 0.911880, 0.714040, -0.312740, 0.433090, 0.827480,
0.697630, 0.888570, 0.677150, -0.291860, -0.073650, 0.902090, 1.310780, -0.164170, -0.011030, -0.372710,
0.308990, 0.405770, 0.091220, -0.097420, -0.684530, -0.854140, -0.436210, -1.035160, 0.732940,
-0.307830, 0.287670, -1.277660, 0.267690, -3.253260, 0.051430, -0.264670, 0.706930, 1.050490, 0.708550,
0.214800, -1.277990, -0.464980, 1.733750, 0.614210, 0.433330, 0.009470, 0.813690, -1.034880, 0.890100,
-0.289370, 0.929440, 0.592770, 1.981220, 1.255330, 0.357990, -0.506600, -1.642820, 0.077520, 1.366280,
-0.759440, -0.734390, -0.585550, -1.108210, -0.166900, 3.044110, -0.221390, 1.012540, 0.052200, -0.071400,
-0.697630, 0.485800, 1.338070, 0.237210, -0.734720, -0.310200, -0.217660, -0.767300, -1.053630, -1.649640,
-2.008070, -0.226490, -0.055610, 0.564270, 1.658730, -1.064360, 0.095850, -0.009870, 0.135690, 0.929700,
-0.771220, 1.258260, 1.134680, -0.110490, -0.523950, 2.307290, 0.653480, 0.910340, 0.005280, 1.303480,
1.468610, 1.278730, -1.155560, 0.121760, -0.703780, 0.119610, 0.290030, 1.357430, 1.166550, -0.997250,
0.185720, 0.897000, -0.017900, 0.695510, -1.093440, -0.212050, 0.845090, 0.545270, -0.473720, -1.084500,
-0.269760, 0.330630, -1.797040, -0.762230, -1.024700, -0.787350, 3.128120, -1.869160, 1.287380, 1.397560,
-0.300290, 0.070520, -0.728280, 0.046210, 0.350820, 0.664130, -0.490410, -1.146120, -0.179830, 0.013640,
0.644880, 1.423180, -0.635780, 0.488800, 1.040430, 0.563270, -2.696280, -3.405910, 2.982450, -1.750920,
0.561010, 0.589000, 1.165800, 0.142390, 1.073640, 0.545950, 2.287850, -0.166340, -0.690350, -0.696370,
0.306780, -0.268770, -0.925790, -0.298710, -0.244960, -0.994900, 1.035640, 1.457340, -1.619240, -2.652700,
0.469720, 2.198270, 0.718190, -0.555680, 0.923120, -0.523720, -0.532380, -0.305670, 0.117730, 0.504020,
-0.032340, -0.291860, 0.380020, -0.390730, -0.048070, 3.083460, 1.357560, 1.640820, -0.206440, 0.230410,
-0.291930, -0.149680, -2.381720, 1.063650, 2.162800, 0.558280, -0.050610, 0.881020, -0.807950, -0.196180,
-0.506240, -0.478880, -0.823850, 0.194710, -0.063370, -0.617880, -0.288680, 0.515040, -0.461730, -0.541810,
0.650740, -0.067240, 0.272200, 3.421280, 0.290720, -2.273050, 0.035890, 1.052680, 0.211200, -0.009250,
0.044210, 0.831640, 0.668090, -0.589100, 0.969810, 0.756320, 0.155360, -0.847870, -1.215750, 0.537970,
-0.634750, 0.550400, 2.123660, 2.615990, 0.725240, -0.620600, 0.661040, -0.556820, -0.233730, -0.573750,
-0.663860, 0.066860, 0.668530, -0.427340, 0.959070, -0.246230, -0.583970, -1.379810, 0.423330, 0.278750,
-0.345700, -0.822710, -0.242450, -0.170780, -1.137620, 0.629290, 0.582640, -1.516950, -0.183330, -0.403150,
0.489090, -0.866850, -0.455000, 0.725390, -0.327920, 1.070260, -0.110110, -0.554580, 0.391520, 0.526670,
-0.828060, -0.657280, 1.805130, 0.430230, 0.641490, -0.700520, -0.622790, 0.509280, -0.487010, -0.597900,
-1.240310, -1.188150, -0.910880, 2.876590, 0.771990, -0.001130, 0.876940, -0.225740, 3.034390, 5.834070,
1.480210, -0.009060, 0.597600, -1.237700, 2.136260, 0.734550, -0.036120, 1.115890, -2.655790, -0.992010,
-1.193780, -0.982680, -1.833360, -2.493450, -3.219620, -1.734700, -0.931310, -1.923520, -3.154780, -3.063180,
-1.874370, -2.024700, -1.827310, -1.709250, -2.037640, -3.097200, 2.611180, -2.027970, -3.479210, -3.976270,
-1.857280, -1.901660, -1.937310, -2.153820, -2.351870, -0.613320, -3.064000, -0.817370, -1.929680,
0.759370, -0.784430, 1.288250, -0.420700, 1.157360, 0.473010, -1.062650, 0.650520, 0.556960, 0.333840,
-1.537530, -0.684440, 0.352850, -2.089160, 0.689080, -1.111770, -1.124070, -0.126760, -0.361120, -0.104000,
-2.111010, 0.218250, -0.030930, -0.549380, -0.007500, -1.578290, 1.047190, -0.425260, -0.186850, 1.990760,
-1.690700, -1.193380, -0.773990, 1.313800, 0.276130, -1.356750, -0.077540, 0.529260, -0.005450, 0.872950,
0.912090, 0.421170, -0.692730, 0.326980, -0.789030, -1.083840, -0.773220, -0.725120, 2.363240, -0.736410,
1.626870, -0.397680, -1.371330, 0.067400, 1.137800, 1.540750, -0.696690, 1.088320, 0.494070, -1.722110,
0.386620, 0.470650, -0.176650, -0.440530, 0.128960, 1.123710, -1.722130, 0.368470, 0.360810, 0.720720,
-1.475640, -0.878020, 0.027230, 1.222220, 0.325150, 0.541310, 5.709690, 0.210210, -0.373940, 0.844540,
-0.046200, 1.156470, 0.504630, -1.270080, 2.029050, 1.280170, 2.219870, 1.903420, 1.288950, -1.715000,
0.335060, -0.020220, 0.621540, -1.842810, 0.086030, -1.116470, -0.023150, -0.252390, 0.270300, 0.431940,
0.251900, -1.239250, 0.231470, 0.167490, -0.510110, -0.104200, -0.633540, -0.638170, 1.270530, -0.875880,
1.550090, 1.991040, -1.331960, 1.801440, 0.086090, 1.000020, 1.691950, 1.876940, -1.331270, 2.435870,
0.747550, -5.373750, -0.126300, 1.796350, 9.778550, -2.290740, -1.674480, 0.250550, 0.826370, -1.732010,
-0.661570, -2.528450, 6.827560, -1.288330, -1.006530, 10.397630, 3.153290, 0.288580, 0.384090, 0.504270,
-1.099900, 0.437850, -0.980310, 0.171900, -0.778740, -0.392290, 1.096290, -2.009930, 0.844370, 0.121510,
0.056520, 2.094010, 0.077370, -0.742530, 0.871630, 0.421610, 1.151130, 1.432720, -1.894380, -0.324620,
0.410170, 1.214810, 3.456550, -0.980970, -0.407790, -0.269200, 1.345010, 1.296550, 1.629710, 0.460290,
-0.060260, -1.205330, 0.597000, -0.156450, 0.278600, -0.753440, 0.935110, -0.651150, 1.245620, 0.705210,
0.278690, -0.932610, 0.881550, -1.069570, -0.218540, 3.984610, 1.002260, -0.478910, 0.045960, -0.106560,
0.299260, 0.353830, 0.438880, 0.529320, 2.405130, 2.238130, 1.316120, 1.390950, -2.071530, -0.374000,
-0.281010, 1.678600, -1.337310, -0.132880, -0.187500, 0.897080, -0.379190, -0.073180, 2.322720, -0.089620,
-0.546440, 1.423790, 0.101460, 4.149800, 0.176590, 0.532600, -0.067040, -0.503370, -0.824470, 1.552880,
-1.563260, 1.071230, -0.078620, 0.735460, 1.917230, -0.164070, -0.506160, -1.865910, 0.035660, -0.013860,
0.177290, -0.870610, 1.599820, -1.106750, -0.668530, 0.150090, 0.101610, 1.459980, -0.579020, 0.577620,
2.356270, 0.868810, 0.852640, 0.305860, 0.576200, 1.737180, 1.843460, 1.104590, -0.002040, -0.126000,
-3.258060, 0.131140, -0.005480, -0.100220, -0.657880, 0.280630, 0.924830, -0.211980, 1.141500, 0.860140,
0.287640, 0.410460, -1.227010, -0.357910, 0.518900, 0.537590, 0.146080, -1.058930, -0.557600, -0.358200,
1.221230, 0.667290, 0.881690, -0.046770, 0.498500, 0.171540, -0.157890, 0.401770, 1.251460, -0.930930,
0.508820, -0.377530, 0.436350, -0.462920, 0.057650, -0.102150, -0.540780, -0.975090, 0.706390, -0.623070,
0.533880, 0.089220, 0.528380, 0.047510, 0.094620, 0.307610, -0.564650, -0.206210, 0.113250,
-0.143650, 0.309430, -1.013820, -0.663410, -0.528890, 0.387510, -1.146150, -1.120740, 1.930450, 0.207840,
-1.119160, -0.222670, -1.090800, 2.362970, 0.567440, -0.098740, 0.272540, 0.877510, -0.458760, 0.261110,
1.507000, 0.637370, 0.120970, 0.383020, -0.026880, 0.314470, -0.361600, -0.834150, 0.999880, 0.117030,
-0.635120, -0.468150, 0.038800, 0.167970, -0.517000, -2.761840, 0.601940, -0.652250, 0.028430, -0.944850,
1.481730, 1.091530, -0.323050, 0.895520, -0.156940, 1.333460, 0.148730, -2.167040, -0.841070, -0.048100,
1.361170, -1.089420, -0.696010, -0.318260, -0.620690, -0.299610, -1.480250, -0.896420, -0.300150, 2.062580,
0.264430, -1.174990, -0.553880, -0.274810, 0.926330, -0.244420, 0.058720, 0.328460, 1.010950, 0.116390,
-0.833670, -0.740320, -0.740430, -3.332250, 1.786480, 0.225500, -0.279460, 0.901900, 0.721130, -0.058360,
0.737540, -1.057030, -1.068040, -0.584510, -0.748890, -0.066620, -0.012000, -1.318230, -1.161090, 0.629550,
-0.628660, 0.093700, -0.264050, -0.519350, -2.168310, -1.075370, -0.908450, 0.347550, 0.669800, 0.922590,
0.049090, 0.925930, -1.348510, 0.329310, 0.300570, 0.033190, 1.240520, 0.080110, -0.282530, -0.217220,
0.469540, -0.738780, -0.387020, -1.428550, 0.971850, -1.658400, 0.525020, 0.884580, 0.290740, 0.434730,
-1.246150, -1.141010, 3.954770, -1.590490, 0.498070, 0.923440, 0.810880, 0.295130, -1.734950, 1.210250,
-0.357090, -0.200680, -1.713680, -0.719100, -0.093010, 0.037830, -0.250330, -0.391150, -0.999390, 1.739210,
-1.017220, 0.068800, 0.632470, 0.601860, 0.973520, 1.333950, -1.680390, -0.123440, -0.566370, -0.921080,
-0.406760, -0.672400, -0.611770, -0.150130, 0.147770, -0.641660, 0.904870, 0.103040, -1.144400, 1.085970,
-0.403950, -0.239640, 0.178980, -0.883300, 0.426180, 0.000720, -0.316690, -0.711010, -0.890160, 0.885340,
-0.487100, -1.878710, -0.235410, 0.199050, -0.301530, 0.043770, 0.899080, 0.238630, -1.374540, -0.198720,
1.618970, -0.515760, 1.076980, 0.126920, -0.022560, 1.160780, 0.279170, 0.772490, -0.872880, 0.119460,
-0.023750, 1.337030, 0.487270, -0.418810, -1.403670, 0.092780, -0.538540, 0.902560, -0.938350, -0.718050,
0.266570, 0.448000, -0.511110, -1.133040, 0.368670, -0.320770, 0.091880, 0.304660, 1.905250, -0.830980,
0.425140, -0.454960, -0.235060, 1.554970, 0.429390, 0.014240, 0.928650, 0.185000, -0.463660, -0.982360,
1.619220, 2.564990, -0.865210, 0.778780, -0.350850, 0.727590, 0.195730, -0.506230, -0.073340, 0.315410,
0.574020, 0.526370, -0.667060, 0.264080, -0.513600, 0.461010, 1.262870, -0.146410, 0.906410, 0.882270,
-0.653230, -0.100860, 0.467800, -0.445960, 0.821640, 2.514550, 0.820290, 0.174690, -1.097880, 0.586960,
2.566240, -0.364030, 1.072080, 2.736720, 0.719090, -1.180920, -0.266200, 1.686860, 0.284320, -1.041160,
0.477390, 1.269080, -0.870230, -0.521450, -5.213640, 1.259210, 0.371940, -0.286200, 1.389430, 0.534480,
3.609970, 0.573510, 3.219160, 1.210360, 1.433840, 0.666350, 1.477330, 2.219940, 3.715050, 2.094860,
3.664120, 4.900200, 0.679150, 6.807490, 0.460240, 0.264920, 8.947320, 0.313090, 1.964440, 0.702920,
1.368570, 2.639960, 0.047320, 1.475480, 3.852920, 2.463960, 2.006240, -0.404950, 5.729860,
-1.752820, 0.933280, 0.789270, 0.492190, -0.679100, -2.149370, -2.256380, 0.407350, -0.594080, 0.306430,
-0.896130, 0.031130, 0.016710, 1.255850, 0.401990, 0.831810, 0.632120, 0.133510, -1.371500, 3.971020,
0.676700, -0.951810, 1.312980, 0.487540, 0.116290, -2.486830, 0.171000, -0.706910, -0.379700, 0.346900,
0.013340, -2.503810, -7.171670, 0.032870, -1.994070, -0.791710, 1.134150, 0.200730, 0.348980, 0.417170,
-1.401500, 0.788280, 2.276570, -0.606620, 0.441470, 1.370260, -1.895500, -1.019000, -0.618920, 0.329380,
-1.095730, -0.304260, 0.748110, 0.336280, 0.488140, -0.926320, -1.246410, -2.081460, 0.044130, -0.319700,
-0.797470, -0.746470, 0.590950, -2.094100, 0.795250, 2.152600, 0.718920, 3.241060, 1.139380, 0.138650,
0.134600, 1.046700, -0.107150, 0.908940, -0.317470, 0.918790, -0.247930, -1.178340, 0.586490, 0.016880,
-0.153640, 0.515090, 0.280150, -0.201710, 0.716940, 0.886360, -1.489260, 0.008200, 0.068290, 0.119940,
0.673750, 0.707110, 0.090120, 0.161640, -0.466400, -0.104720, 0.014690, -0.239690, 2.029050, -0.480580,
-0.639010, -0.580220, 0.287010, 1.810310, -1.419040, -0.144010, -0.082190, 1.261650, 1.449450, -0.781390,
2.371020, 0.737260, -0.888880, 1.205630, 2.212080, -0.173330, -0.312230, -0.516190, -2.968590, -1.680280,
-0.103050, 0.720460, -0.238920, -0.381090, -0.749300, -0.031540, 0.117200, -0.518210, 0.530060, -0.605930,
-0.407680, 3.585570, -0.670300, -1.105470, -0.042150, 0.793720, 2.478230, 2.849930, 0.234920, 0.278130,
-1.415230, 0.887160, -1.231240, -0.642320, 0.057750, 0.546310, -0.046320, -1.008910, 0.098850, 0.369080,
0.796440, 1.014330, 1.035960, -0.048030, 0.522570, -0.669910, 0.051350, -0.063400, 0.901550, -0.095800,
-1.577230, -0.065830, 1.020860, 1.051090, 0.988560, -0.294510, 0.147570, -0.263780, 1.008890, 1.329040,
0.874140, 0.604300, 0.553630, 0.481890, -0.447550, -0.892090, -0.009990, -0.469080, 0.105580, -0.410750,
-0.620560, 0.077640, 0.217520, 0.092660, -0.136630, -0.062180, -1.193210, -1.706150, -0.617360, -2.073620,
0.530680, 0.043120, -0.844000, -2.689460, 0.485520, -0.574180, -0.345400, -1.211240, -0.210770, 0.236500,
0.696530, -1.358550, 1.262610, 1.328440, 0.088190, 1.092000, -0.468220, 2.450310, 2.170980, -2.330700,
-0.792130, -0.004940, 1.633490, -0.000390, 0.123530, 0.628150, 0.771550, -0.460160, 0.132610, 1.316210,
1.076360, 1.391940, -0.617270, 0.878090, 2.870030, -0.371650, 1.325490, -0.550260, -1.862560, -0.052320,
0.784970, 0.205880, 1.883740, 0.900380, -1.365410, -0.128960, -0.433740, 1.791740, 1.686460, 1.453860,
-1.556470, -0.448120, 0.357100, 0.770740, 2.726220, 0.600660, -0.931060, 1.409020, -1.861390, -1.034710,
-0.677870, -1.605600, -0.852510, 14.788100, 0.066370, 1.622050, -0.690580, 1.443400, 0.464790, -0.465540,
-0.427690, -0.614660, 0.367710, -0.754870, -0.227310, -0.630980, 1.569390, -0.195250, -0.688990, 0.110160,
0.044790, -0.360830, -0.326730, -0.114180, 0.005610, -1.131370, 0.821960, 0.034800, 3.779830, 0.762150,
-0.701350, 1.713890, -0.386130, -1.701660, -0.078530, -0.764630, -10.325760, 1.007930, -0.908830, -0.633210,
-1.127780, -0.278170, -0.097910, -0.508970, 0.144790, -0.588590, -0.084450, -0.259540, 0.916690,
-0.675240, 0.432680, -0.549420, -1.782500, -0.736310, -0.044640, 0.042480, 0.455620, -1.886130, -1.090670,
1.342120, 1.044920, 0.287820, -0.495970, 0.572270, 0.016060, 1.362140, -1.319000, 0.301990, -1.740950,
-0.185370, 1.231890, -5.774340, -0.324770, -0.627990, 0.223040, -0.146640, -0.991170, -0.606090, -0.149500,
-1.901240, 1.462640, 0.186270, -0.623360, 0.562130, 2.389850, 0.965120, 0.268350, -0.516020, 0.592790,
-0.663650, -0.250820, 2.107890, -0.369380, -0.780220, -1.500160, 0.637590, 0.288430, -0.763570, -1.001130,
0.016320, -1.382390, 1.552810, 1.656300, -2.496000, 0.719610, 0.613800, 0.459670, -0.853960, 1.568860,
-1.013320, 1.575050, 0.289810, 0.815790, -0.123130, 0.326960, -0.419610, -0.490530, -1.491030, -1.202460,
0.893750, -0.632110, -0.897790, -1.516860, 0.686160, -0.362450, -0.185750, -0.730610, -1.268340, -0.377660,
0.953800, -0.862780, 2.358030, 0.821860, -1.036870, -0.198870, -1.288300, -0.114380, -0.108590, -0.748890,
0.247390, -1.935180, -1.003910, 1.109400, 0.628840, -0.840360, -0.380080, 1.081450, 0.631980, -1.361060,
-1.707970, -1.119940, 0.879190, 0.130230, -0.391150, -0.337430, -0.254670, 0.670770, 0.033330, -0.306200,
0.596880, 0.826200, -0.294020, 0.192640, 0.099910, -0.433830, 3.112870, -1.089230, -1.245360, -1.796570,
1.753450, -2.488500, 0.963990, 4.097110, 4.323340, -0.882650, -0.951970, -2.484260, 6.054820, -1.864650,
0.474550, -1.004420, 6.368730, -0.852140, -0.123540, 2.115970, 0.648530, -3.048780, 1.578250, -0.861410,
1.230770, -0.183670, -1.148640, -0.951420, 0.407480, 0.985950, -0.585900, 0.233560, 0.539860, 1.084870,
-0.511940, 1.664490, -0.233710, 1.704610, -0.346150, 0.468320, 0.408040, 0.754770, -0.288220, 0.711000,
-0.159300, -0.395860, 0.136460, 0.614120, -1.267760, -1.227090, 0.831390, 0.635840, 1.063710, -0.160720,
-1.141220, -0.186490, 0.247090, 0.256870, 1.158440, -0.030650, -0.027850, -0.655760, 0.044680, 1.569680,
0.517940, -0.394380, 0.614890, -2.395840, 0.878810, 1.172390, -1.960710, 0.361290, -0.801800, 0.554980,
0.929200, 0.900220, -1.020780, -0.235520, -0.796220, -0.376900, -0.419450, -1.269660, 1.467710, 0.197110,
-1.341150, 0.269450, 0.280920, -0.682130, -0.645940, -0.718240, -0.825530, -1.734680, -0.175560, -0.502860,
0.272840, 0.991240, 0.394390, 1.420580, 0.036790, -0.365370, 0.564960, 0.745050, -0.645130, 0.690040,
-0.676610, -0.534990, -0.086970, 0.083600, -0.053440, -0.702300, -0.734150, -0.067720, -0.372710, 0.483570,
1.079170, 1.352260, -0.891020, -1.383780, 1.073320, -0.979270, 0.715020, 0.630240, 0.342820, -0.361810,
-0.244040, -0.184740, -0.855140, -1.302530, 0.748100, -0.004260, -1.070440, -0.052360, 0.020930, 0.298440,
0.222190, -0.954880, -0.498360, 0.462820, 0.498200, 0.770970, -0.266520, 0.523030, 0.132150, 2.877040,
0.934040, 0.311680, -3.055180, -1.865200, 0.165820, -1.104390, -0.214770, -0.186320, 0.103550, -0.328420,
0.201490, -0.122420, 0.626470, -0.385910, -0.468220, 0.218250, 0.420410, -0.015190, 0.925800, -0.439030,
-0.493900, 0.425800, -0.490170, 0.851450, 0.067250, -0.911070, 0.710780, 0.196130, 0.845040, 0.600950,
0.199170, 0.686580, 0.389780, -0.385300, 0.406750, 0.242920, 0.898030, 0.814070, 1.311250,
-0.886500, 0.473630, 0.747850, 0.807500, -0.924290, 1.149810, 0.620100, -0.151850, -0.080780, 0.688290,
-1.351340, -0.434620, -0.574040, 1.977960, 1.019100, -0.566580, 0.326910, 0.793960, -0.070390, -0.574380,
1.156840, 0.054230, 0.465630, -1.916330, 0.690290, -0.983460, 0.913570, -0.109620, -0.459960, -1.025020,
0.340730, 0.014720, 0.195510, 0.337490, 0.384040, -0.683620, 2.006670, 0.076800, -1.078270, -0.168850,
-0.565740, -0.361810, 0.169520, 2.462850, 0.840000, -0.215660, 0.513860, -0.688620, -1.503940, -0.919010,
-0.949270, 0.677560, -0.407130, 0.947570, 0.085680, 0.900290, -1.251910, 2.473530, -1.113550, 0.621780,
-1.956910, -1.030810, 0.062480, 0.204620, 0.454260, 0.548790, -0.116680, 0.450890, -0.242750, 0.180430,
0.102690, 0.445820, 1.058770, -0.902430, 0.707390, 0.457590, 0.577120, -0.790870, 2.575740, 1.058480,
0.376880, 1.280460, 0.950830, 2.240780, 0.243260, -0.476320, -0.629010, -1.046420, -1.760640, 1.596290,
-1.362830, 0.290090, -0.576610, -0.692970, 1.483040, -0.623080, 0.031180, -0.750720, -0.714610, -0.665970,
0.489620, -0.847800, 0.495130, 0.633940, 0.763010, 0.511780, -0.177380, 0.333820, -0.390360, -0.189780,
0.729790, 0.592750, -0.071630, 0.464510, -1.433160, -0.029270, -0.913350, 0.634090, 1.353860, -0.393510,
-0.608620, 1.591820, -0.570200, -0.972310, -2.616790, 0.173190, 1.378000, 1.801680, -1.994670, -0.535090,
2.574860, 0.560880, -2.049720, 1.939860, 0.771220, -10.169380, 0.101090, 0.579880, -0.177180, -0.859680,
-1.711990, -1.077240, -1.576360, -0.467860, -0.611960, 0.747920, -3.805200, -1.336210, -0.335320, 1.341330,
-0.328100, -0.558920, -0.772760, 0.339830, 0.749830, 0.195370, 0.557600, -0.162900, -1.010300, -0.107400,
1.305930, -1.378680, -3.525520, 0.608900, 1.301100, -1.446520, 0.047270, 0.211110, 0.903670, -1.273900,
0.412410, 1.281030, 0.630970, 0.782100, -0.516980, -0.165010, 0.699630, 0.095230, -1.911020, -0.452810,
0.658170, -0.232360, 0.936350, 0.815500, 1.112770, 0.045420, -0.422450, 0.163020, 0.523320, 2.257640,
0.573690, 0.279640, -0.332330, -0.668340, -0.843700, -0.363630, -0.906460, -0.196320, 0.148470, 0.937360,
1.218700, 0.755750, 0.448230, 0.168110, -0.500870, -0.055620, 0.799180, -1.130970, -1.759730, -0.786590,
0.825150, -0.759220, -1.825930, 0.984290, 0.363380, -0.284250, -1.125860, -0.614250, 0.093740, 0.176500,
-1.691770, -0.487120, -1.133660, -0.088030, -2.402140, -0.962750, 1.513080, -0.940290, -0.813620, 0.207690,
-0.569550, 0.168800, -0.423540, 1.427770, -0.287400, 0.581770, 0.354460, -0.604480, -0.350710, 0.891190,
0.619880, -0.861210, -0.184990, 0.109080, 0.214400, 0.254460, 0.922960, -0.130360, 1.255560, -0.466260,
-0.542940, -0.249090, 0.030960, -11.053550, -0.062270, -0.037530, 0.726150, 0.053440, 0.575040, -0.261060,
-1.167220, -0.615070, 0.660050, 0.448910, -1.422750, 0.929640, 0.448760, -0.403810, 0.889970, 0.451030,
0.212910, -0.464320, 0.384310, -0.211300, -0.363040, -0.204330, 0.290750, 0.020080, -1.319540, 0.086990,
0.220210, -0.415510, -0.889160, 0.609540, 0.314330, 0.809170, 1.722530, -0.819990, 0.041310, 0.709510,
0.322160, -0.911000, 0.319790, 0.757630, -0.215900, 0.184140, 0.319250, -1.718170, 0.325650,
-0.027190, 0.396220, -0.371670, 0.101400, -0.370860, -0.248960, -0.102700, 0.886690, -0.131460, -0.178230,
-0.780420, -0.779120, 0.330850, 0.806610, 0.533180, -0.354560, 0.817610, 0.117430, 0.531930, 0.848710,
-0.426490, -0.090030, -0.064870, -0.836490, 0.028400, -1.433690, -0.256500, 1.521960, -0.151550, 0.061640,
0.151260, 0.275360, -1.097810, 0.603070, 0.541100, 0.071760, 0.803960, 0.191480, 0.195640, 0.214770,
-2.328810, -0.221610, 0.829410, -0.669390, -1.005600, 0.661920, -0.381830, 0.670610, -0.112890, 0.267090,
-0.688490, 0.084750, 1.131770, 0.550930, -0.081680, -1.643130, -0.569690, -0.064630, 0.786140, 1.854050,
-0.479670, 0.423030, 0.449580, -0.776260, 1.849000, -0.795460, -0.191600, 0.291520, 0.538650, -0.500690,
-1.891740, 0.274030, 0.760790, -0.425050, -0.339240, -1.026150, 0.566630, -1.601020, 0.660800, 0.637120,
-0.053360, -0.589250, -0.521910, 0.099540, 0.861730, -0.329780, 0.070340, -0.836910, -1.051180, 0.452250,
-1.041780, 1.387100, -0.199570, -0.764700, 0.140530, -0.385410, 0.537590, 0.387080, -1.078510, 0.298610,
0.415930, -0.805880, 1.712570, -0.810190, 0.331420, -1.055900, -0.085950, 1.747400, -0.278200, -0.592820,
1.151820, -0.478900, -0.482500, -0.339120, -0.630960, -0.815930, -1.768620, 0.368870, -0.977400, 0.275510,
-1.278800, 0.884470, -0.208990, -0.540290, -0.960470, 1.368270, 1.680910, 0.697860, -0.692890, 1.900760,
1.362290, 1.375700, -2.377660, 1.699070, 1.741600, -9.055300, 0.419440, 0.887700, 0.693220, 1.410940,
-0.913410, -0.035780, 0.646910, -0.062820, 0.261070, -0.751080, 0.019730, 0.223170, 0.953270, 0.599240,
-0.710580, -0.236450, 0.381970, -0.258060, 0.589600, 0.428060, -0.972850, -1.995700, 1.479310, -0.227300,
0.352830, 0.826160, -1.293690, -0.710230, 0.947580, -0.368760, -0.411220, -0.535420, 0.221690, 0.321300,
-0.364130, 0.436510, 0.200620, 0.952620, -0.782970, -1.344180, 0.089730, 0.133560, -0.808380, -0.271970,
1.166690, 2.739890, -4.125550, -0.238240, 0.769230, -1.610110, 0.022250, 0.309720, -0.056140, 0.290500,
-0.642650, 0.870510, -0.205660, -1.482080, -0.676070, -0.474020, 0.607890, -0.214610, 0.128260, 1.055270,
0.089260, -1.429560, 0.004650, 0.625810, 0.854310, -0.918080, -0.039240, 0.764930, -0.452970, 0.539020,
-0.410000, 0.848440, 0.060810, 0.400280, 0.254430, 0.390220, -0.934900, -0.333680, -0.444990, 0.086690,
0.943600, -0.140060, -0.156310, -0.471780, -0.570890, 0.269320, -0.616470, -0.358820, -0.386620, -0.615380,
1.045770, -0.069040, 0.370140, 0.493900, 0.103920, 0.557010, -0.588510, -0.293930, 0.454900, 0.455500,
-0.159290, -0.230450, -1.394750, 1.791770, -0.135700, 0.076190, -0.955540, -0.614830, 0.529140, -0.025110,
2.529840, 0.308210, 1.050950, 0.889560, -0.883970, -0.902130, -0.308530, 0.692620, 0.886590, -0.757860,
1.910100, 0.188740, 3.934390, 1.136490, -1.160040, -0.157030, -0.473550, 0.121290, 0.465940, 0.596310,
0.016810, -0.695020, 0.646810, 0.436320, 0.583730, 0.834690, 0.786800, 0.816560, 0.403430, -0.115250,
0.658100, 0.836150, 0.541720, -0.629380, -0.660720, 0.406320, -4.024660, -0.112990, -0.699320, 0.654160,
0.582930, -0.284540, 0.838150, 0.244430, 0.859620, -0.438190, -0.206020, 1.307540, -0.529880,
-2.809690, -0.364790, 0.930940, 0.562190, -0.337280, -0.251880, 0.660950, -0.110100, 0.345730, -0.062920,
-0.579440, 0.978880, -0.490540, 0.616090, 0.036720, 0.372820, -0.064440, 0.685570, 0.890720, 0.667810,
-3.686600, 0.517480, -0.189770, 0.571410, 0.632050, 0.181690, -0.140290, 0.480570, 0.651700, -0.544910,
0.997110, 0.291580, 0.807020, -1.019290, 0.222270, -1.486640, 0.500810, -1.701300, -0.689120, -0.577760,
1.514220, -0.264700, 0.846570, -0.553210, 0.168920, 1.073140, 1.808010, 0.628420, 0.449210, -0.675520,
-1.084620, -1.045950, 0.445220, -0.430980, 1.646080, 1.174100, 0.335260, 0.098060, -0.129110, 0.187650,
0.643240, -0.209460, -1.200850, 0.251610, -0.483340, -0.824500, 0.752470, -0.979210, -0.364040, 0.158970,
-0.898360, -0.311790, -1.647120, 0.519340, 0.238830, 1.221590, -0.726150, 0.347850, -1.423120, 0.141140,
-0.986350, 0.494530, -0.129820, -0.512950, -0.440410, 0.233290, 0.755650, 0.401680, -0.724250, -1.874730,
0.375980, -0.213390, -2.885810, -1.906070, -0.647800, -0.176810, -1.935690, 0.684650, 1.028930, -0.950420,
-0.645740, -0.693340, -0.325670, 1.200340, 0.682320, -0.198260, -0.709530, -0.339510, 0.578090, -2.190410,
2.195660, 0.495260, -2.036310, 1.356590, 1.177540, -0.310160, 0.512800, -0.788800, -2.044720, -1.165110,
0.921220, -0.445260, 0.305310, -1.034400, 1.758620, -0.902400, -1.088710, -0.144370, 0.122290, -0.250400,
0.231750, -0.186040, 2.676390, -0.021530, -0.864380, 1.377370, 0.958020, 0.146460, -0.582050, 0.173240,
-1.464510, 0.480970, 0.157590, -1.363170, 1.447750, -1.679640, -0.578760, -0.432190, 0.193610, -1.836620,
-0.117350, -0.331640, 0.116330, 0.507680, 0.912800, -0.102090, 0.655830, 0.588300, 0.741530, 1.166170,
-0.133430, 0.025070, -0.927540, -0.166310, -0.514440, -1.158380, 0.815170, 0.995820, 2.383200, -0.242810,
2.081010, 0.041860, 1.602780, 0.767940, -2.371340, 0.347630, -0.399450, 0.226480, 0.260420, -0.038220,
-0.625840, -2.765140, 1.052850, 2.151560, 0.690640, -0.355840, 0.745590, -0.977450, -0.580730, -0.254340,
-0.284660, 1.028630, 0.079330, -1.222140, 0.032030, 0.049890, -0.648570, 0.669120, 0.337940, 0.448820,
-0.409460, -0.691340, 0.039340, 0.041300, -1.864330, 0.961210, 1.630990, 0.221150, 0.768760, 0.879280,
0.239550, 1.395800, 1.267610, -0.694690, -1.802860, 1.106700, 0.173190, -0.762770, 0.533130, -1.138580,
0.281870, 0.826050, -2.672960, 0.240330, 1.917400, -0.816130, 0.161880, -0.040100, 1.743530, -0.698680,
0.228040, 0.134010, -0.193800, 0.756070, 0.148410, 0.720590, -0.647580, -1.110550, 0.318580, 0.304410,
-0.600100, -0.058920, -2.641730, -0.904610, -0.758480, -0.412830, -0.375220, -0.528170, -0.458300, 0.175920,
-1.514900, 1.038120, 1.342840, 2.405110, 0.315330, -0.792550, 1.246730, 0.223290, 0.209440, -1.008630,
-2.176570, -1.117360, -1.043070, 0.439310, 0.909590, -0.670280, -1.271580, -0.696130, 0.114770, -0.065530,
0.211050, -1.003990, -0.477720, -0.843470, -0.415560, -1.186150, -0.692730, -0.243190, 0.677580, -0.102750,
-0.799330, 0.571620, -1.491100, -0.739150, -0.467710, 0.235310, 4.147500, -0.068110, -0.799660, 0.253280,
-0.239170, -0.872380, -0.329960, -0.565810, -0.615010, 0.279960, -0.391550, -3.661960, -1.756950,
-0.944600, 0.183280, 1.571020, 0.029690, -0.227740, -1.528970, -0.568470, 1.119380, 0.415060, 0.246240,
-0.113030, -0.232320, -0.056980, 2.954820, -1.287470, 1.041880, 0.848520, 0.833950, -1.290810, -0.226670,
0.439960, -0.282270, 4.561610, 1.010100, -0.766020, -1.278030, 0.024550, 0.087550, 0.642620, -0.436500,
-0.828730, -0.822770, -2.726140, -0.350210, 0.070640, -0.789170, 0.469100, -1.366880, -2.080600, 1.029990,
-1.376260, -1.430800, -0.578460, -0.946170, -1.064570, 5.136450, 2.474130, -0.896150, -0.494890, -0.372710,
-0.427770, -0.070650, -0.767260, 1.215650, 1.412720, -0.658680, -0.543720, -0.935550, -0.440880, 0.893880,
1.163220, 0.002180, -1.330670, -0.384570, -0.069780, 0.744010, -0.926280, -0.745420, 1.118070, -0.056430,
0.738390, 0.118010, -0.159350, -0.462360, 0.198020, -0.322480, -1.937570, -2.007900, -0.549720, 0.038870,
-2.179540, -0.573620, 0.094560, 0.173880, 0.654240, 0.347250, 0.285420, -0.894640, -1.300990, 0.618210,
-0.088570, -0.162400, 1.160230, -1.019540, -1.579760, 1.182310, 0.617370, -2.140670, -0.466780, -0.185690,
-0.821920, -0.518160, -0.469430, -0.537610, 2.730160, -0.562780, 0.128000, 0.614440, -0.479270, -2.319760,
0.394200, 0.610400, -0.328690, -0.249590, 2.073330, -0.570550, -3.726320, -0.523530, 2.995060, -3.872990,
0.094640, 0.811340, -1.584650, -0.637450, -2.683590, 0.808730, 0.409810, 1.705260, -3.689100, -0.247560,
1.707780, 1.681710, -6.168470, 0.850220, 1.500580, -8.780180, -4.802930, 1.876150, -0.204180, -0.556850,
-1.216860, 1.340670, -0.410290, 0.795960, 0.912180, 2.161370, -3.255280, -2.020910, -0.757540, 0.439070,
-0.320070, -3.965480, 1.057460, -0.612030, 0.033520, -0.164020, 0.299430, 0.886050, -0.929300, -1.256980,
0.861680, -0.529590, -3.394000, 0.035960, -0.859170, 0.859810, -0.632490, 0.928710, 0.948040, -0.713610,
-0.496830, 0.374650, -0.727870, -0.164750, -0.872000, 1.507630, 0.178600, -0.777880, -1.039590, 1.281570,
0.214780, 0.146570, -1.262730, 0.797560, -0.569380, -1.116180, -0.350650, 0.458840, 1.052750, 0.567010,
0.281870, 0.390950, 0.928500, -2.480470, -0.782690, 0.077730, -1.010930, -0.966330, -0.236250, -0.395460,
0.082170, -0.554670, 0.110170, -0.865090, -1.572370, 0.434630, 2.905370, -1.539420, 0.112900, -1.371190,
1.594670, -1.382140, -1.105640, 0.322170, -1.110450, -0.749620, -2.591650, -0.201960, -0.286610, -0.184780,
1.684030, -0.332470, 0.932390, 0.129250, 0.062520, 0.215630, 1.642180, -0.876890, -1.264580, 1.272880,
0.224100, -0.803650, 0.133950, 0.093810, -0.505720, -1.128020, 0.561980, 0.053080, -0.245740, -0.542750,
0.530250, 0.056800, -0.490820, 0.110760, 1.147710, -1.357990, 0.172990, -0.881280, -0.471770, 2.357740,
2.551020, -2.064960, 0.725270, -0.580080, 0.119250, 0.001990, 0.457020, -0.567880, -0.658110, -1.192510,
0.398110, 0.492150, -0.414660, 1.708240, 0.021590, 1.171320, 0.080810, -0.653530, -0.579590, 0.613090,
0.440890, -0.631260, -0.982390, -0.136970, -0.228430, -0.626800, -0.617970, -0.947120, -2.489940, 0.455950,
-0.723920, 0.566870, -0.552490, 0.553790, -0.166300, -1.008090, -0.288220, -1.300950, 0.394100, 0.100710,
-0.635960, 0.461330, 0.018010, 0.422210, 0.924990, 0.905300, 0.215650, 2.245300, 0.147450,
-0.076510, 0.698630, 0.046890, 1.274690, -0.337200, -0.319330, 0.134960, 0.233320, -1.036690, 2.212420,
0.088670, -0.371810, 0.290450, 0.061230, -0.284860, 0.814720, 0.332140, -0.226230, -0.074110, -0.334820,
0.912290, -0.719300, 1.301280, -0.698420, -0.836130, -1.994150, 0.559690, -1.538630, -0.331560, 0.426610,
-2.478120, -1.413430, -1.058930, -0.347320, 0.696440, -0.937740, 0.612110, -0.658120, 0.141310, -0.726180,
-1.137760, -0.213690, 0.975100, -1.555110, 1.872600, -0.542290, 0.170740, -1.562190, -0.054310, 1.079250,
-0.422700, -0.507930, 0.103370, -0.009080, 0.660540, -1.006180, 1.230090, 0.653160, -0.272250, -1.009990,
-1.838880, 0.234840, 1.792140, -0.466430, 1.208510, -0.476040, 0.110610, 1.408570, 0.084800, 0.701220,
-0.260680, 0.816110, 0.100780, 0.134440, -0.837220, -2.002320, 0.177500, 0.190720, -0.164980, 0.637060,
-0.861070, 0.534690, -0.417910, -1.586030, -0.047620, -1.820860, -0.882290, -1.383560, -0.325880, 0.028370,
-0.516870, -1.356140, -1.247710, -3.484140, -2.320990, -0.474060, -1.478650, -1.749130, -0.705110, -1.009600,
-0.564890, 0.505650, 4.923570, -0.601970, 1.738430, -3.075650, 0.818960, 1.100130, 0.053310, -2.371390,
-0.111630, 1.299640, -0.833380, 0.497900, 0.202000, 0.384610, -0.629750, -0.332240, 6.870470, -5.656040,
0.752340, 1.351860, 4.053240, 1.057270, -1.416980, 0.255730, -0.387050, 1.482490, -2.906840, -1.105940,
-15.179250, 0.092950, -2.975040, 0.231580, 1.878460, -1.256890, -1.779640, -0.114440, -0.098340, 0.170890,
0.288790, 0.891450, 0.460140, -0.202600, 0.478300, -0.107090, 0.714100, -1.683200, -0.458590, 0.606420,
1.984080, -0.908880, 0.296670, 0.636130, 0.751010, -1.282060, -0.542530, -0.494200, -0.654260, -0.094210,
0.996770, -0.836890, -1.180390, 0.592310, 0.961530, -0.709200, -2.743220, 1.083220, -1.245600, -0.961280,
0.578940, -0.065590, -0.195530, 0.073930, -4.581830, 0.016750, 0.647150, 0.380220, -2.635440, 0.229470,
0.946160, 0.724340, 1.055580, -0.690290, -1.660070, -0.096950, -0.427650, 1.487220, -0.031090, -3.107740,
-1.169800, -1.654140, 0.940410, 0.962650, -0.991930, 0.330480, 0.314940, -0.907680, 1.454720, 1.503910,
-0.354780, -1.458740, -0.106670, 0.136410, 0.962330, 1.302360, -0.049840, 0.551780, -1.067110, 0.257600,
-1.888540, -1.904850, 0.314370, -2.322620, -0.044840, -0.209020, 0.406860, -0.349870, 0.262220, -0.548880,
0.284940, 1.016390, -0.326300, -0.536720, -1.068980, -0.140910, 0.685040, 0.578760, -0.264200, 0.337840,
-1.863330, 0.142490, 0.718100, 1.249070, 0.828920, -1.023350, 1.517720, -0.271210, -0.536480, 1.111860,
-1.923610, -0.767070, 2.660890, 0.783460, 1.052660, 0.078970, 0.642380, 0.115420, 0.921840, 1.146400,
2.720690, 1.735630, -0.347290, 1.142090, -0.155290, -0.075820, -0.460530, 0.768850, 1.215550, -0.893910,
-0.367280, -1.462580, 0.736220, -0.144890, 0.623680, -0.021290, 0.218600, -0.082950, -0.639210, -0.504150,
0.731520, -0.924320, -0.800630, -0.727580, -0.665730, 0.349810, -1.225820, 0.865980, 0.342580, -0.319630,
-1.444080, 0.226140, 0.788190, 0.408560, -1.032550, 0.293150, -3.717220, -0.716120, 0.430500, -0.594430,
0.934810, -0.564200, -0.109180, -0.163140, 0.104870, 0.948020, 0.243770, 0.166630, -0.421710,
0.479510, 1.316610, -2.443440, 0.195010, 2.576110, -0.346580, -0.908050, 0.815730, 1.027850, -0.603070,
-0.018230, 0.860230, -0.498680, 1.339730, 1.017250, 0.798840, 1.313910, -0.326810, 1.507540, 1.156380,
-0.069490, -0.768410, 0.754070, 0.729880, 1.859720, -1.605640, 0.748510, 0.250300, 0.053960, -0.010480,
0.426200, -0.724730, -0.875960, 0.808850, -0.647710, -1.221050, 1.090940, 0.812610, -0.371480, 0.180400,
-2.378450, -0.900660, -1.499580, 0.427910, -0.508450, -1.056370, -0.520660, -1.433200, -0.259810, 0.059370,
0.380260, -0.993990, 0.367670, 1.200980, -0.949470, -0.444830, 1.313250, 0.205840, -0.671880, -0.535600,
0.627240, 0.356710, -0.033790, -1.930250, 0.603080, 2.775970, -0.973900, -2.346880, 0.147430, 0.141100,
-0.377080, -0.941240, -0.245110, -0.084140, -0.716640, -0.692470, 0.201440, -0.359400, -0.056820, 1.467600,
1.379050, 0.276680, -0.042790, 1.164930, 0.015360, 0.054400, 0.117540, -0.273360, -0.112820, -0.471540,
-0.260890, -0.047110, 0.437820, -0.621970, 0.438260, 0.259440, -0.470970, -0.541800, 1.056010, 0.076190,
-1.706340, -0.994930, 0.309000, 1.333300, 1.147110, 1.251810, -1.568930, 0.322280, 1.448340, -0.697340,
-0.050880, -0.423730, -1.159270, 0.587570, 0.175690, -0.109270, -2.901030, -0.604630, 2.333390, -3.340360,
0.473310, 5.067340, 0.207230, -0.543750, -1.899870, 0.090050, 0.129020, -0.524730, -1.177820, -0.212170,
-1.779580, -0.259070, -5.439640, 0.519420, 2.174940, -5.368520, 1.168720, 0.123280, -0.519830, -1.340830,
-1.623650, 0.999940, 0.518020, 0.072710, -0.944170, -2.110830, 0.317260, 0.685050, 1.215820, -1.867140,
1.605060, -0.076390, 0.009180, -0.581750, 1.453190, -1.296560, 0.684570, 1.961000, -0.824410, -1.778850,
1.811000, -1.356030, -4.540610, -0.957250, 0.918230, -0.158880, -0.865890, 1.605830, 0.919630, -0.620270,
-1.279920, 0.636770, 0.834340, 0.399480, -0.080340, 1.170130, 0.241300, 0.567900, -1.564950, 1.439020,
1.900310, -1.333920, 0.847100, 1.026100, 0.098400, -1.052330, 0.772960, 2.122860, 0.841480, -0.928140,
-0.793010, 0.553870, -1.361620, -1.889270, 0.697740, 0.496450, 1.089450, -0.890930, -0.389770, -0.771830,
0.588140, -4.236570, 0.943440, 1.401600, -0.397480, 1.053940, 0.432000, 0.493460, -3.208590, -0.549680,
1.139450, 1.540200, 0.798420, 0.356980, -1.872890, -0.382650, -1.116640, 0.565020, -0.478740, 2.355760,
1.379920, -1.172890, -0.493610, -0.132050, -0.802470, -0.702350, 0.230000, -2.828990, -2.328830, -1.079330,
-0.522170, -0.542740, 0.411850, -1.774580, -0.110510, -1.153880, -1.612240, 1.013750, 0.160280, 0.005790,
1.039310, -0.404910, 1.207170, 3.069480, 1.261390, 1.608370, 1.259240, -0.152890, 1.270630, 1.109770,
0.019260, 0.383310, -1.745030, 5.713670, -0.413530, -0.187150, 0.603670, 0.422740, -0.564740, -0.088470,
-0.478550, 1.471900, 3.226150, -0.299720, 0.049390, 0.380850, -0.451650, -0.933110, -0.832040, 0.724260,
0.150340, -0.684080, -0.452890, -0.015420, 0.896510, -0.092480, -0.912710, -0.543490, -3.095000, 0.480540,
0.243380, 1.577300, 0.431730, -0.480110, -0.965440, -0.240590, 0.931280, -0.458390, -0.855710, -0.363380,
-0.191800, -0.040320, 0.238260, -0.410870, -0.688790, 0.169360, 0.123480, -0.034520, -0.208500,
0.679110, -0.667360, 1.071700, -0.624950, -0.012390, 0.457050, 0.265420, 0.040240, 1.538710, -1.662760,
-0.210840, -0.766680, -0.053480, 0.440000, 0.217410, -0.272230, -1.355670, 1.046670, -0.026850, -0.608090,
1.159730, -0.112030, 1.878500, 1.277150, 1.338110, -0.205140, -0.521290, 0.195340, 0.021210, -1.035510,
0.397010, -0.407930, -0.758100, -0.997990, 0.481420, -0.681680, -0.097650, -0.737740, 0.007670, 0.255240,
0.794790, -0.442050, 0.088990, 1.847940, 0.195750, 0.358420, -0.107440, 0.563420, -0.387840, -1.332070,
0.117210, -0.802390, 1.152580, 0.368040, -0.063710, -1.268650, 0.027810, 0.979320, 0.835680, -0.259040,
1.951180, 0.503640, -0.662120, 1.070520, 0.839380, -1.101160, -0.078230, 0.161010, -0.690020, 0.048450,
0.685870, 1.260530, -0.323830, 0.910800, -0.200650, 1.860840, -0.972560, 0.775790, -2.350910, 0.775050,
-0.715760, -0.198930, 0.129590, -0.508320, 1.211740, 1.147380, 0.372140, 0.312090, -0.665240, -0.292540,
0.846330, 0.665550, 0.254250, 0.683010, -1.084950, -1.530520, -1.732490, -0.519520, -0.793860, 0.260170,
1.761720, 0.361260, 1.084790, -0.004120, 0.490150, -1.984820, -0.503600, 1.361920, -0.690480, -0.797610,
0.954940, -0.249190, 1.340490, -0.346830, -0.591400, -1.433360, -1.437660, -1.630300, 3.514910, -2.802880,
0.251640, 1.606570, -1.429180, -3.655590, -0.003830, 1.706470, 0.628330, -0.528400, 0.461620, -2.374770,
-1.948390, 0.549620, -5.513830, 1.416620, 1.647040, -0.765280, 1.639000, 1.069840, 0.202060, -1.606400,
-1.425380, 1.320460, -0.499280, -0.561120, 1.713080, -1.459210, -1.338320, 0.053590, 0.468880, -0.133820,
1.318280, -1.141010, -0.956390, 0.432610, 1.876060, 0.130310, -0.342270, 0.334950, 0.433150, 0.201620,
0.162390, 0.019590, -0.121630, -1.225040, 1.185480, 0.206220, -0.561540, 1.044180, -1.301040, 0.133500,
-0.538340, 0.104270, 1.199630, -0.117150, 0.024520, -1.426100, -0.598330, 0.685950, -0.856840, -0.202990,
1.427250, 0.615670, 0.771420, 0.376960, -0.055210, -0.403250, 0.050670, 0.543680, -0.878800, -1.204300,
0.803200, 0.281450, -0.271320, -0.846460, -0.260980, -2.700160, -0.419030, 0.685630, 0.060330, 0.418350,
1.181160, -0.725510, 0.748790, -0.908190, 0.330620, 0.604980, 1.862540, 0.536790, 0.054300, -0.657370,
-0.248660, -1.953080, -1.713720, 0.421200, 0.168660, 0.912290, -0.763780, -0.339730, 0.571780, 0.323270,
-0.654690, -0.526910, -0.249580, -0.486520, -0.104980, -0.815260, 0.260820, -0.530980, -0.442930, -0.616600,
-0.426400, 0.128140, -1.249100, 1.408260, 0.451480, -1.231610, 0.370590, -0.421250, 0.970860, -0.267360,
-0.231180, -1.080660, 0.432330, 0.048010, 1.102790, -0.946510, -0.002890, 0.603420, -0.971750, 0.392350,
0.613290, -0.891660, 0.654230, -4.693030, -0.604510, -0.236300, -1.152300, 0.435380, -0.620650, 4.194470,
1.418740, 0.448570, 0.392410, 0.368370, -0.295450, -0.411050, -1.031980, 0.222660, -0.704970, -1.987550,
-1.708250, -5.810560, -1.557870, -1.649400, -2.272930, -2.372560, -2.402070, -2.613810, -1.827800, -1.720500,
-0.706320, -2.069210, -2.368850, -0.493760, -3.198130, -1.562890, 3.767670, -2.619810, -1.274920, -1.584270,
-1.357610, -1.165940, -0.914780, -0.932190, -1.725180, -0.717290, -0.703740, 9.653150, -1.195080,
-0.111500, -0.773630, -1.961720, 0.677580, 0.559880, 0.216450, 1.622480, 0.868770, 2.189180, 0.566210,
0.819110, -0.374620, 0.264450, 1.434330, 0.280690, -1.737820, -1.004800, 0.373520, 0.018970, -0.391140,
1.236710, -0.184130, 0.979180, -1.222070, -1.245090, 0.459830, -0.864160, -0.765740, -0.364620, -0.438440,
-0.789650, 0.206620, -0.916320, 1.240930, -0.358960, 0.046840, 0.553180, -0.872120, -0.728620, -0.281140,
-0.765670, -0.776230, -0.439360, 2.783670, -0.610570, 2.140390, 0.930780, -0.751350, 0.351000, -0.304820,
-0.266840, -0.702650, -0.327860, 0.942970, -0.291050, 0.005080, -0.584590, 1.496680, 0.351240, 2.056490,
0.062460, 0.214930, 0.172610, -2.515200, -1.101290, -0.494700, 1.563930, -1.283310, 0.892760, -0.825220,
0.081250, -0.792060, -0.713850, -0.394560, 1.602560, 0.880530, 0.814260, -0.803220, 0.202800, 0.025780,
-1.271940, -0.335110, 0.962830, -0.849320, -1.907260, -0.879310, 0.182780, 0.123120, -0.325120, 1.157650,
-1.698950, 1.109380, 0.918120, -1.628560, -2.210500, 0.926750, -1.769330, -0.207410, -0.542880, -0.193910,
-0.890690, -3.069370, 1.526790, 0.198120, 0.760460, -0.087460, 0.129500, 1.025880, 0.715010, -0.990710,
1.069920, 0.677720, 1.043910, 0.582460, 0.157610, -1.884960, -1.660610, -0.910170, 2.584390, -1.828020,
-1.324160, 1.416040, 1.531460, -1.393320, -2.307940, -0.642730, 0.656250, 0.188190, -0.532110, -1.289710,
1.377900, 0.221960, -4.104700, 1.492740, 2.505260, -12.074830, -0.089910, 2.669790, -0.356170, -0.555100,
-0.414380, 0.717070, 0.942820, 1.893680, 1.105380, -0.919990, -2.817460, -0.384790, 0.847100, 0.585970,
1.582320, 0.078320, -2.871090, -0.811670, 0.092740, -3.219270, -0.989820, -0.674510, 1.326640, -0.062470,
0.909600, -1.183630, -2.227550, -0.556510, 1.883260, -1.070240, -0.438900, 0.376150, -1.299720, -2.060670,
-1.062140, 0.359280, 0.601650, 0.067650, 0.356400, 1.111690, 0.847590, 0.445470, -1.204300, 0.134280,
0.801160, 1.621370, -0.063280, 0.794620, -0.670620, -0.788690, -0.776250, 1.749150, -0.204260, -1.009520,
-0.700390, -0.729760, -1.278770, -2.112720, 0.739050, 0.764730, -0.962360, 1.046800, -0.234690, -0.654750,
0.720130, -0.970440, -0.234850, 0.796680, 0.615230, 0.415720, 1.618200, 0.574600, -2.363240, 0.992830,
-0.007400, -1.251470, -0.304840, -0.000340, -1.440700, 0.760300, -0.800620, 0.397130, -0.353940, -0.661750,
0.786600, -0.856960, 1.112880, 0.741700, 0.093720, 0.892690, -0.898290, 2.210740, 0.701090, 1.283970,
-0.209670, -0.239490, -2.048560, 0.397700, -0.312310, 0.071650, 0.644380, -0.365470, 0.525670, 0.669860,
-1.566140, -0.651900, -0.311000, -0.895110, -2.131990, 1.325540, -1.059940, -0.338200, 0.088770, -1.919900,
1.006580, 0.306400, 0.801670, 0.363530, -1.169930, -1.142230, -0.416160, 0.833030, -0.966800, 0.912980,
0.094010, -0.417870, 0.204800, 1.166920, 0.761130, 0.705430, -0.001270, 0.133290, 0.590550, 0.215640,
-0.748240, 0.233810, 0.359720, -0.911940, 0.346560, -0.188650, -0.659730, -0.723020, -0.152770, -0.156810,
-0.273980, 0.095940, -0.593230, 0.021960, 0.494570, 0.861790, 5.245800, -0.170190, -0.776960, -0.080630,
-0.517130, 0.484880, 0.118660, 0.439970, 0.927430, 0.136460, 2.084180, -0.441070, 0.027750,
-0.850930, 0.309320, -1.060810, 0.169140, -0.582610, -0.688150, 0.666290, 0.008960, -0.850120, 0.357040,
0.275410, 0.972690, 0.977640, -0.956000, 0.769480, 0.661670, -0.462000, -0.199130, -0.874620, -0.188220,
-0.401880, -0.397900, 0.751670, 0.012770, 0.617210, -0.393500, -0.080080, 0.646840, 0.245030, 0.859820,
-0.750770, 0.697890, -0.317430, -0.756420, -0.589750, -0.371810, 0.168940, 0.701650, 0.100500, -0.295130,
0.204610, -0.180790, 0.697610, 0.169630, -0.927460, 0.505280, -0.792010, -0.513740, 0.445750, -0.376960,
-0.135930, 0.273430, -1.026830, -0.848130, -0.012500, 0.432020, 0.663300, 0.448270, 1.050550, 0.255820,

0.332260, -0.946080, -0.231010, 0.891300, -0.012600, 0.702790, 0.713720, -0.148350, -0.672250, -0.832740,
0.567370, 0.495990, -50.535549, 0.641810, -1.145420, -0.162410, -1.243470, -0.204160, -0.520790, -0.835310,
-0.620160, -0.918490, 1.524380, -0.185310, -0.838000, -0.122630, 0.124960, 0.219280, 1.570590, -1.039180,
0.407700, 3.557070, -0.970860, 1.194100, -0.395800, -0.480110, 0.163400, -0.058460, -0.986040, -0.036890,
1.033030, 0.356370, -0.243840, 0.340720, 0.168460, 1.082400, 0.744120, -1.104200, -0.411170, 1.988130,
0.115470, 0.586970, -0.833140, -0.294370, -0.886320, 0.714970, -0.690290, -0.813140, 1.374080, -0.930520,

-0.911690, -0.399350, 0.929420, 0.718290, 0.157650, -0.355250, 0.545420, 0.872760, -0.781810, -0.650320,
0.064240, 0.635770, -0.736070, -0.977020, 0.408090, 0.400990, 0.137260, -2.176390, -0.033550, 0.566510,
-0.446710, 1.222380, 0.891460, 0.140920, 0.180510, -0.298290, 0.316360, 1.301810, -1.041480, -0.405330,
0.781830, 0.903080, -0.208890, 0.670720, 0.271840, -0.846060, 0.422770, 0.161140, -0.291740, 0.288400,
0.052380, 0.747930, -0.135020, 0.046200, 0.161370, -0.392520, -0.893400, -0.206490, -0.112220, -0.005450,
0.098950, -0.025810, -0.462980, -0.537560, 0.744110, -0.691570, 0.518430, 0.683330, 0.756590, -0.198350,

0.943130, -0.867470, -0.882380, 1.013470, -0.795490, -0.689310, -0.696250, -0.767640, 0.860530, 0.880520,
0.071760, -0.751850, -0.455020, -0.401720, 0.823790, -0.012830, -0.190340, 5.665920, -0.233460, 0.113360,
-0.105010, -0.070440, 1.060880, 0.566610, -0.888490, 0.978950, -0.915310, -0.148210, -0.017310, -0.675770,
0.199140, 0.580620, 0.964010, 0.432250, -0.585920, -0.426950, 0.429740, -0.582040, 0.276970, -0.927060,
-0.543570, -0.652670, 0.187890, 0.630000, -0.111240, -0.347360, -0.278150, -0.623690, 0.683260, 0.236750,
-0.730720, 0.441480, -2.481380, 0.890730, -0.467350, -0.817560, -0.181170, 0.943800, -0.411380, -0.267730,

-0.834690, 0.018180, -0.701050, 0.637970, -0.639390, 0.314560, -0.398880, 0.281940, -0.955210, 0.527320,
-0.741780, 0.020240, 1.201950, -0.881860, 0.646920, -0.153670, 0.328610, 3.164080, 0.529480, -0.741140,
-0.467630, 1.027500, 0.991180, -0.473500, -0.633550, -2.478690, -0.662190, 0.277610, -0.526030, -0.615950,
0.242030, 6.578710, 0.788450, 0.208220, 0.882260, -0.588690, 0.796910, 0.920470, -0.015230, 0.760090,
0.405910, -0.300060, 0.028760, 0.933790, 0.204130, -0.910970, 0.520430, -0.652520, 0.483450, 0.099740,
0.610490, -0.025290, -0.827340, 0.141280, 0.914510, 0.093740, -1.025080, 0.505920, 0.617810, 0.238360,

-0.479160, 1.017620, -0.058080, -0.476410, -0.690000, -0.356710, -0.500960, -0.729580, -1.165930, -0.524830,
-0.569990, -0.849490, -0.669800, 1.890860, 0.777780, 0.876500, -0.227100, 3.913650, 0.655730, -0.704210,
-1.399100, 0.079910, -0.328400, 1.190880, 0.803220, 0.542560, 0.414340, -0.328570, 1.010420, 1.097050,
0.532150, 1.258290, -0.715400, -0.614760, 0.566060, 0.833220, 0.614390, -0.402190, 0.958680, -0.395380,
0.250850, -0.931380, -0.830380, 0.892670, -0.380620, -0.635830, 0.555570, -0.738760, -0.168150, 0.497550,
0.912940, -0.514430, 0.531040, -1.030480, 0.463950, 0.581050, 0.110870, 0.622370, -0.375500, 0.210600,

0.454380, 1.368300, 0.464680, -0.169860, 0.974380, 0.778290, 0.140590, -0.321650, -0.894120, -0.188880,
0.677350, -0.807260, 2.457180, -0.785550, 0.542480, -0.042820, 0.394110, 0.493850, 0.921150, 0.564910,
0.201810, 0.667740, 0.498290, -0.799960, -0.900150, 0.437880, 0.469590, 0.338060, -0.955930, -0.901950,
-0.795050, 0.592890, 0.198530, 0.681200, 0.391760, -0.377580, -0.753580, 0.610120, 0.447350, -0.432220,
-0.028410, 1.798310, 0.910680, 0.992840, -0.702560, -0.126660, -0.767880, 0.579080, -0.947920, 0.810390,
0.859360, -0.400060, -0.897450, 0.851380, -0.782300, 0.116630, 0.886230, 0.970530, 0.953400, -0.564660,

0.542240, 0.593520, 0.754520, -0.915970, 0.437010, -0.276760, 0.419580, 0.993330, 0.285260, -0.750490,
0.116290, 0.070170, 0.745560, -0.554910, -0.002920, 0.645290, 0.913830, 1.487700, 0.312170, 0.611680,
0.997420, 0.179570, 0.157220, -0.620450, -0.629210, -0.120270, -0.728230, -0.258570, 0.218370, 0.650560,
-0.959320, 0.024520, -0.285040, 0.263990, -0.262470, -0.135970, -0.572270, -0.014410, -0.017910, 1.163960,
0.261480, 0.356710, -0.993440, -0.296420, -0.553580, -0.496420, 0.119140, 0.135520, -0.696320, 0.253080,
0.197720, -0.092520, 0.095690, 0.032480, 0.867950, -0.380810, 0.705370, -0.086010, 1.003720, -0.325190,

-0.098680, -0.588310, -0.463740, 0.544980, -0.632650, 0.916570, 0.440040, 0.867890, 0.286150, 0.833260,
-0.431660, 0.448970, -0.766040, -0.980630, 0.789570, 0.648080, 0.767750, -1.375890, 0.511160, -0.653830,
-0.335170, 0.338000, 0.837360, -0.460170, -0.060980, -0.855530, -0.272520, -0.911380, -0.833580, -0.404520,
0.238380, -0.150340, 0.435880, -0.920270, -0.130540, 0.140180, 0.599520, -0.864030, 0.039780, 0.139220,
0.415980, -0.224770, 0.581200, 0.304290, -0.021680, -0.243220, 0.326880, 0.323140, 0.685620, 0.125690,
-0.765660, 0.751500, -0.426040, -0.069050, -0.894000, -0.812620, -0.059090, 0.890290, 0.012800, -0.216010,

0.652200, -0.847820, 0.581910, 0.654440, 0.803520, 0.211660, 0.146960, 0.084570, 0.117590, -0.943030,
-0.723580, -0.501350, -0.156380, 0.937650, 0.490710, -0.157070, 0.770950, 1.286850, -0.332760, -0.534940,
-0.674130, 0.292450, 0.695500, 0.421050, -0.678450, -0.874270, -0.390640, -0.168080, -0.242910, -0.207340,
-0.182180, 0.773940, -0.809200, 0.967050, -0.407280, -0.095280, 0.771580, -0.566060, -0.444330, -0.331360,
0.266340, 0.194790, 0.123870, 0.529040, 0.578630, 0.884450, 0.486810, -0.400240, -0.439830, 0.545000,
0.450490, 0.398450, -0.999760, -0.261360, 0.086240, 0.708060, -0.310350, 0.427520, -0.763900, -0.632350,

-0.666530, 0.306680, 0.354250, -0.423770, 1.312380, -0.318270, -0.956510, 0.204280, 0.729110, -0.569320,
0.135780, 0.257520, 0.556490, -0.146910, 0.333300, -1.800330, 0.781050, 0.345570, -0.854130, -0.483150,
-0.737490, -0.375110, 0.584430, -1.302110, -0.983800, 0.674470, 0.882050, 0.148870, -1.089850, -0.109990,
-0.219020, 0.082850, 0.210970, -0.118780, -0.035480, -0.865030, -0.803070, -0.535780, 0.519440, 0.695120,
0.446710, -0.158320, -1.073720, 0.141820, -0.695150, 0.516980, 0.229830, -0.649680, -0.492600, 1.008700,
0.444440, 0.483330, 0.015630, -0.467490, 0.966510, -0.627920, 0.412490, 0.810830, 1.873490, -0.834110,

-0.038520, -0.392970, -0.504430, 0.309750, -0.353090, 0.582460, 0.611230, 1.032190, -1.054740, -1.466170,
0.251320, -0.533180, 0.132890, 0.133220, -0.620860, 0.734830, -0.148630, 0.678210, -0.443710, 0.996250,
-1.138910, 0.034880, -0.223540, 0.618330, 0.190750, 0.484110, 0.077460, 0.291320, -94.542633, 0.329880,
-0.857650, -0.727590, -0.121650, -0.073410, -0.530370, -0.755210, 0.767180, 0.876020, 0.200010, 0.311160,
-0.814550, -0.847420, -1.025220, -0.435700, 1.940530, -0.587150, 0.984100, 0.035320, -0.448670, -0.652990,
-0.021170, -0.168970, -0.388790, -0.587620, -0.697880, -0.949140, -0.102250, -0.424810, -0.875740, -0.027560,

-0.552750, 0.044350, -0.032890, 0.230740, -0.973540, -0.101070, 0.324850, -0.510830, 0.170740, 0.266330,
-0.931960, -0.787720, 0.818670, 0.551980, -0.156800, -0.971560, 0.489850, 0.167480, 0.553950, 0.828440,
0.493970, 0.091730, 0.784870, -0.571670, -0.329250, 0.997790, -1.532970, 0.446590, 5.352210, 0.410180,
0.852170, -0.652380, -0.743990, -0.659430, -0.916150, 0.072190, 0.449480, 0.086540, -0.178290, -0.607990,
0.213630, -0.950100, -0.208270, 0.027710, -0.572690, -0.193540, 0.952790, 0.109000, 0.744340, -0.063000,
-0.479790, -0.023930, -0.308120, -0.708270, 0.107090, -0.148520, 0.489220, -0.980660, -0.239730, -0.356570,

-0.119360, 0.048160, 0.654580, 0.895200, -0.078620, -0.188220, 0.842810, 0.825350, -0.408320, -0.391030,
0.629570, -0.985980, 0.107130, 0.045380, 0.286020, 0.060830, 0.932690, 2.165330, -0.069900, 0.938130,
-0.118900, 0.457340, -0.560250, 0.027960, -0.564120, 0.177110, 0.098670, 0.623780, 0.476620, -0.857920,
0.230130, -0.768610, -0.968910, -0.581980, -0.298720, 0.197840, 0.918250, 0.306320, -0.477140, 0.898460,
-0.081240, 0.029670, -0.689140, -0.299950, -0.839070, -0.474850, 0.043470, 0.921330, 0.220690, -0.415220,
0.859310, -0.373080, 0.483360, -0.288000, -0.240340, 0.030100, 0.858510, 0.116970, 0.948200, 0.656990,

0.201950, 0.028640, -0.540400, -0.237820, 0.774860, -3.026300, 0.567340, 0.491000, 0.873600, 0.847360,
0.632450, 0.144990, -0.657050, -0.806140, -0.065130, -0.961760, -0.004170, 2.588080, 0.697150, -1.196150,
-0.536700, 0.210110, -0.425700, 0.763690, -0.436750, 0.663080, -0.313700, 0.335870, -2.712220, -0.252110,
-0.930060, 1.132710, -0.818500, 0.465200, 0.682800, -0.954530, -0.320900, -0.656540, -0.749560, 0.232530,
0.225820, -0.617910, -0.875430, 0.047770, 0.587610, -0.432410, -0.955400, -0.776570, 0.070150, -1.079270,
3.851360, -0.392130, 0.127690, -0.690800, 0.566650, -1.061380, 0.049850, -0.706450, -0.546510, 0.931840,

-0.139970, -0.131060, -0.260380, 0.848640, 0.143280, 0.666600, -0.098440, -0.878900, 0.970850, 0.019060,
0.169720, -0.428710, -0.602790, -0.759980, -0.198600, -0.240230, -0.945200, 4.859370, -0.943960, 0.889890,
-0.795090, -0.742250, -0.471330, -0.228400, -0.657770, 0.981520, -0.568000, -0.369140, -0.982990, 0.587820,
0.991730, -0.198900, 0.295020, -0.154500, 0.724770, 0.597430, 0.710030, 0.130590, -0.056200, 0.473240,
0.186810, -0.439170, 0.366110, 0.483190, -0.415960, -0.819820, -0.812190, 0.923480, -0.787750, -0.786140,
0.377330, 0.470750, 0.387850, 0.393510, 0.362180, 0.428980, 0.297860, 0.678640, -0.089630, -0.848070,

0.060170, 0.757620, -0.100830, -0.648830, -0.247010, -0.402620, -0.028260, -0.584950, 0.917840, 0.424080,
0.473870, 0.040380, 0.170330, -0.160360, 0.077920, 0.749060, 0.478900, -0.894800, -0.686670, -0.009010,
0.050670, -0.134310, -0.910340, -0.525600, -0.765730, 0.866610, 0.431690, 0.400530, 0.074370, -0.937340,
0.781950, -1.081070, 0.708210, 0.002490, 0.771900, -0.195120, 0.971360, -0.274160, -0.793850, 0.386400,
-0.805030, 0.653560, 0.092240, -0.704630, 0.525120, 0.631530, -0.496080, 0.053100, -0.926140, -0.632760,
-1.049390, 0.434010, 0.144390, 0.059840, -0.159440, -0.768960, 0.524250, -0.816340, 0.552880, 0.155700,

0.505720, 0.904210, 0.227680, -0.953950, 0.479370, -0.830530, 0.153860, -0.406600, -0.150420, 0.491740,
0.481600, 0.359930, 0.478380, 0.497120, -0.046130, 0.758370, 0.783800, 2.608770, -0.719950, -0.861900,
-0.634590, -0.542310, 0.228550, -0.410250, -0.353050, -0.894400, 0.136160, 0.232110, 0.750650, -0.139850,
0.284200, 0.471980, -0.812960, 0.387240, -0.091570, 0.145690, -0.069270, -0.769240, -0.761830, 0.842180,
-0.924980, 0.950910, 0.325210, -0.128220, 0.462080, -1.062620, 0.896340, -1.642660, 0.500070, -0.277430,
-0.334810, -0.080030, 0.293210, -0.356410, 0.820090, 0.009060, -0.290750, -0.482330, -0.133120, -0.031870,

0.395510, 0.387690, -0.152500, -0.956810, 0.212430, -0.956010, 0.108710, -0.403150, 2.022530, 1.835960,
-0.420860, 0.821830, 0.105640, 0.554940, 11.855850, 0.414960, 0.470140, 1.025880, -0.265760, 0.705670,
-0.052940, 0.000130, -0.246840, -0.102300, 0.126940, -0.486010, -0.873020, 0.303780, -3.832800, -0.150330,
-0.748100, -0.657850, 0.632030, 0.843090, 0.820370, 0.516800, -0.742230, 0.309530, 0.848360, -0.286860,
-0.335840, 0.437220, 0.747360, 0.122730, 0.668470, 0.662580, -0.036220, -0.746400, -0.807590, 0.276150,
0.929970, -0.541710, 11.048010, -0.299880, -0.670260, 0.167980, -0.311630, 0.844090, -1.264030, 0.936680,

-0.029440, -1.033420, 0.562050, 0.417510, -0.359040, -0.558200, -0.612060, -0.675870, 0.838300, 0.638380,
0.704680, -0.146640, 0.757840, 0.843580, 0.999170, 0.343460, -0.022200, -0.462010, -0.306970, -0.963010,
-0.288850, -0.870580, 0.835270, 0.452320, -0.022100, -0.011700, 0.858810, 0.614620, -0.169560, -1.046310,
0.725910, -0.481810, -0.482090, 0.069790, 0.075690, 0.717990, -0.965150, 0.657890, -0.427500, -0.387750,
0.614060, -0.122260, 0.416810, -0.647070, 0.744170, -0.170730, 0.434850, 0.436040, 0.788470, -0.566130,
-0.795450, -0.368050, -0.589610, -0.289140, -0.471660, -0.943760, -0.834990, 0.864930, 0.435090, -0.475470,

-0.226250, -0.727210, 0.643940, -0.611820, -0.401580, -1.007140, -0.697340, 0.487310, -1.000010, -0.806680,
-3.781330, 0.305680, 0.390750, -1.012460, -0.816760, -0.350760, 0.917260, 1.249670, 0.734670, -0.101190,
-2.813630, 0.337970, 0.323480, 0.219940, 0.636120, -0.019450, -0.817330, 0.010270, 0.383500, -0.097890,
-0.610190, 1.078060, -0.113840, 0.643260, -0.733740, -0.215250, -0.507900, -0.127310, -0.305150, -0.796640,
0.531830, 0.768080, 0.427660, 0.811180, -0.894790, -0.673550, 0.798290, 0.520490, 0.277140, 0.685030,
-0.768780, -0.637200, 0.801910, 0.195260, 1.410640, 0.665070, -0.629470, -0.604430, 0.796850, 0.372760,

-0.106530, 0.349710, -0.749240, -0.208180, -0.672070, -0.442870, 0.772000, -0.922840, 0.335310, -0.100930,
0.879540, -0.978230, 0.072080, 0.114850, -0.150570, -0.168610, 0.357760, 0.148510, 0.326970, 0.267830,
-0.062210, 0.626680, -0.322660, -0.702580, -0.644850, -0.200740, -0.308890, -1.266600, -2.725180, -0.548250,
0.192320, 0.508420, 0.124000, 0.011320, -0.976410, 0.975650, -0.245760, 0.824420, -0.859290, 0.885710,
-0.681110, 0.563350, -0.342520, 0.914580, 0.165710, -0.891940, -0.156520, 0.262040, 0.461830, 0.284730,
0.219730, 0.147230, 0.373300, -0.942080, -0.702740, -0.884090, -0.114800, -0.605700, 0.166020, -1.004370,

0.369840, -0.317460, 0.521410, 0.637980, -0.910990, -0.601180, 0.595240, 0.691800, -0.821590, -1.250220,
-0.290690, 0.240150, 0.937810, -0.662630, -0.011030, 0.936250, -0.373910, 1.706930, -0.863880, 0.301200,
0.743770, 0.436710, -0.901510, -0.762660, -0.368230, 0.458160, 0.467630, -0.086710, -3.981500, 0.801000,
0.976720, -39.261162, 0.215110, -0.866590, 0.313450, -0.617690, 0.451650, -0.915460, -0.664280, 0.132740,
0.714370, -0.615250, 0.461510, -0.819910, -0.326380, -0.598170, -0.874780, 0.388710, -0.429800, -0.140770,
-0.531890, 1.505070, -1.958080, 1.236550, 0.600170, -0.459730, 0.216110, -0.990130, -1.283020, -0.515330,

0.027060, -0.561270, -0.691790, 0.786260, 0.818460, 0.086510, -0.847860, -0.550160, -0.456610, -0.837260,
-0.034470, -0.349200, -0.090870, -0.830930, 0.803890, -0.173560, -0.504530, -0.158480, 0.506430, -0.745300,
0.239930, 0.794820, -0.365170, 0.284810, 0.210400, 0.614740, 0.844570, 0.932140, 1.362520, 0.300220,
0.133920, 0.546160, -0.855360, -0.186690, 0.287960, 0.713680, 0.361430, -1.013500, -0.818390, -0.484590,
0.918990, -0.367370, -0.241210, -0.732840, -1.077230, -0.657990, 0.637140, 0.450060, 0.472700, 0.070590,
-16.664749, -0.939940, -1.247470, -0.064140, 0.767110, -0.173650, 0.340800, 0.279610, -0.710780, 0.251090,

-1.221660, -0.079790, -0.396550, 0.866880, -0.397430, 0.625400, -0.455740, 0.583950, 0.139280, 0.842420,
-0.996960, -0.953000, 0.563590, -0.050530, 0.077720, 0.338170, 0.866800, -0.067060, 0.687250, -0.874900,
-0.180670, -0.796080, 0.829180, 0.270300, 0.447100, 0.768770, -0.947990, -0.368690, 0.568670, 0.806500,
0.268660, -0.524160, -0.030590, -1.130570, 0.535800, -0.356460, -0.934340, -0.424240, -0.981450, -0.107640,
0.668840, -0.294990, 0.098230, -0.197430, 0.844500, 0.846520, -0.288030, -0.878970, 0.159790, 0.220830,
-0.885240, 0.161970, -0.441070, 0.230880, -0.749330, -0.822640, -0.529110, 0.339430, 0.510220, 0.596620,

-0.589470, -0.759430, 0.763630, -0.650620, 0.114020, 0.941160, 0.528980, 0.544530, -0.676580, -0.858670,
0.951300, 0.108400, 0.484100, 0.183980, 0.968170, -0.625370, -0.680220, 0.113350, -0.434540, 0.777370,
-0.306140, -0.175820, 0.468410, 1.119350, -0.740500, -0.342850, -0.190780, -0.852060, 5.593230, 0.527410,
0.186100, 0.537620, 0.146410, 0.768280, -0.466340, 0.482150, 0.265280, -0.582140, 0.489900, -0.657690,
-0.498310, -0.132050, -0.286320, 0.845050, 0.881280, -0.354820, 0.134770, 0.755060, 0.458200, -0.209860,
0.514380, -0.567580, 0.757740, -0.224510, -0.370580, -0.635220, -0.252280, -0.306680, 0.547640, 0.069730,

-0.413660, -0.134310, 0.677620, 0.795930, -0.924300, 0.372940, 0.293390, -0.963000, -0.963720, 0.597250,
-0.228920, -0.752140, 0.650870, -0.394750, 0.708350, -0.156570, 0.366230, -2.732550, -0.739790, -0.691580,
-0.874140, -0.922580, -0.749990, -0.383910, -0.298270, -0.302780, -0.272190, -0.724500, -1.366180, -0.888230,
0.682870, -0.361690, 0.294220, 0.200760, -0.576340, -0.059180, 0.830700, 0.303730, 0.842620, -0.229480,
-0.673630, -0.325020, 0.638540, -0.084860, -0.194260, 0.377370, 0.417980, 0.158200, 0.230790, 0.490560,
0.835880, 0.591880, -0.445150, -0.778250, -0.919490, 0.461980, 1.000700, -0.485300, -0.672410, -0.213100,

-0.624230, 0.453130, -1.035910, -0.601360, -0.311710, 0.840930, -0.570110, -0.197510, 0.640310, -0.963960,
0.384850, -0.594920, -0.382430, 0.816050, 0.591680, -0.695380, 0.481630, -0.552920, 0.602050, 0.146820,
-0.711620, -0.394550, -0.333360, 0.690620, 0.153510, 0.602390, -0.113780, -0.482210, 4.818190, 0.425590,
0.830220, 0.423790, 0.005750, -0.154550, 0.444860, 0.519830, 0.363510, -0.993240, 0.003670, 0.114900,
0.788530, 0.475990, -0.493680, 0.162130, -0.021750, -0.809970, 0.380160, 0.283300, 0.671610, 0.785630,
0.323930, 0.499470, -1.313100, 1.634120, 0.318570, -0.043190, 0.441420, -0.458990, 2.735910, 0.943750,

-2.894860, -0.380480, -0.104910, -0.694970, 0.180360, 0.203900, -0.027190, 0.528790, 0.780610, 0.906450,
0.783470, 0.818650, -0.916040, -2.222370, -0.364430, -0.871920, -0.616720, -0.907030, 0.453140, -0.795870,
-0.550180, -0.060360, 0.579990, -1.088620, 0.990840, 0.339710, -0.390820, 0.707300, 2.126100, 0.954880,
0.790160, 0.830250, 0.444050, -0.266500, -0.180860, -0.593160, -0.989410, 0.718940, 0.151670, -0.202970,
0.296140, 0.515720, 0.343230, 0.129240, -0.150670, 0.312240, -0.177410, -0.263350, -0.593750, -0.187370,
-1.509530, 0.666390, 6.446380, 0.124410, -0.491830, -0.552710, 0.463230, -0.792330, 1.744790, -0.607050,

0.794880, -0.292890, 0.209800, -0.880460, 0.762360, -0.750070, -0.907540, 0.314980, -0.077900, 1.291100,
-0.667230, 0.370730, 0.788470, 0.535340, 1.687790, -0.256070, 0.612340, 0.531520, -0.591350, 0.475280,
0.128310, -0.399860, 0.976190, -0.802680, -0.631610, 0.113860, -0.325280, -0.036640, -0.729900, 0.000210,
0.878130, -0.480730, 0.441790, 0.178160, 0.560130, -0.586600, -0.792880, 0.551840, 0.226200, 0.863430,
-1.007230, -0.985080, -0.117130, 0.799250, 1.128910, 0.311440, -0.307610, 0.200790, -0.041970, 0.546510,
3.411310, 1.011100, 12.744250, -0.624370, -0.367260, 0.332560, 0.347890, 0.258700, -1.103760, 0.650120,

-0.822350, -0.025930, 0.709780, -0.353310, -0.268710, -0.636800, -0.442270, -0.192840, 0.754760, -0.680290,
-0.838970, -0.522780, -0.293550, -0.386540, 0.988300, -0.562270, -0.177930, 0.935840, 0.607530, -0.457710,
0.508810, 0.466890, 0.531390, -0.501080, 0.123110, -0.340750, 0.256800, -0.406100, -0.859930, 0.321390,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.193040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.996680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.010460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.593750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.760820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.328290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.884450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.069780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.384920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.656460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.531420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.070270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.882460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.823580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, -0.798620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.256890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, -0.406260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.558430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.427380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.110120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.124080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.959270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, 0.628590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, -0.711690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.675390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.438250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.618010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.744450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.368190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.776120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.179490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.873920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.819640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, -0.495670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, -0.170190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.404470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.659020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.056170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.854940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.444130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.136430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.323890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.296140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.504710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.543330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.497090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.491440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.112990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.306230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, -0.340320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.380730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.139210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.194380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.894950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.363140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.634500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.121130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.358580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.748210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.796550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.255540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.366520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.234020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.051990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.085770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.246240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, -0.323040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.450700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.615170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.884000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.599380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, -0.576260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.724680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.048260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, -0.162270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.764310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.879150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, 0.373430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.863900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.771500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.769400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, 0.032450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.591020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.668480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.619390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, -0.998120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, 0.434060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.444640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.619510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, -0.969470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.398690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.217790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.918200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.493510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.119550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.571340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.903820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.018880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.468570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, -0.736540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.404180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, 0.318820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.890720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.941700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.429840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, -0.092390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, 0.644020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.830810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.251330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.648850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, -0.838670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.111970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.254900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.342880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.758360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.010000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.024390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, 0.394150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, 0.687960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.523470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.996460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.080960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.944300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.228130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.728300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.680230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, 0.880020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.530780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.999830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.817270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.432610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, -0.597130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, -0.965770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.253080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, 0.197360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.301870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.279050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, -0.477360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, 0.514830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.781400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, -0.836040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.870340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.180930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.712130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, -0.250140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.364570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.248350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, 0.677300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.757050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.942880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.125970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.060500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.487430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.406170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.328000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.595690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.106700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.537240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.762950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.357400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.385310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.308400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.065370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.410670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.632130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.586380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.486790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.542660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.327510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.485960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.926850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.715240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.399640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.569150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, 0.564340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, 0.340290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.105470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.394870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.079860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.619210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, 0.019300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.992160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, 0.056850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.224820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.645860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.305420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, -0.985700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.021770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.868720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.749400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.651750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.312340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.410130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.115650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.418090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.067510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.971640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.671830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.778480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.660260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, 0.598430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.418830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.430840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, 0.258070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.883160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.275370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.904020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, 0.553840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.887790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.282300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, 0.985210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.654520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.188260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.178860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.603250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.291470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, 0.249990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.823910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.485640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.432750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.293390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.228470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.163840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.523200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, 0.858510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.934050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, -0.762360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.232590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, 0.357110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.459110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.626620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, -0.754970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, 0.475070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, -0.371490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.773030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.132120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.942210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, 0.313660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.341180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, 0.554750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.774200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, -0.003920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, -0.366160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, -0.352090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, -0.200710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, 0.106580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.645310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.751240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, -0.179450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.359020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, -0.177760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, -0.942240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, -0.882800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, 0.811730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, -0.722510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, 0.302320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.356770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, -0.879950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, -0.294380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.990640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.225690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.710270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, 0.847550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.967370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, -0.309250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.041800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, -0.673830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, -0.962110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, 0.799370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, 0.203070, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -1.153110, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.788860, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, 0.222660, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, 0.478630, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, 1.153290, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.008770, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, 0.791070, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, 0.792920, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -1.778050, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, 0.304230, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.316370, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.283890, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, 0.056490, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, -0.818700, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -0.817130, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, -0.762680, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, -3.600940, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, 0.909890, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, 1.287980, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, -0.322530, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.601330, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, 0.981960, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, 0.680140, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, -0.539630, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.034250, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, -0.472630, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, 0.176760, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -1.073630, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.576490, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.766620, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, 0.024920, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, -0.211460, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.559800, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -0.464500, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, 0.729650, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.039720, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, 0.931090, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -0.197220, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.261970, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, -0.582420, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, -0.916940, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -0.272260, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.198200, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, 0.114340, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -0.404670, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, 0.020210, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, -0.827020, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, -0.337430, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, 0.169830, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, -0.725680, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 0.756040, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 0.066260, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, -0.663690, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.073150, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.180960, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, 0.964210, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, -0.494200, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, -0.695170, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.437970, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.561700, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
0.42650, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.99014, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.63464, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
0.09818, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
0.03044, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
1.02900, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
0.37998, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
1.36498, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
0.09904, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
0.03666, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.00027, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
1.30720, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
0.59446, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
1.42834, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
1.00801, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
1.33064, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.42761, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
0.00022, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
1.41200, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
1.42857, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
1.33500, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
0.33037, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
1.00895, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
1.12420, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
0.41961, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
0.09739, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
0.02738, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.00024, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.00007, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
1.01229, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
0.93093, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
0.00256, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
1.14271, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
0.48128, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
1.36444, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
1.41991, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
1.35519, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
1.28845, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
1.31231, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
0.45082, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.00436, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
0.08997, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.18679, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
1.19754, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
0.00407, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
0.42682, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
0.06547, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
0.03409, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
1.42819, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
0.19600, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
0.01966, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.18757, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
0.01114, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
0.00651, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.39386, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
1.16508, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
0.34507, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
1.31032, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
0.00124, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
1.42198, 0.500000, 2,
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
