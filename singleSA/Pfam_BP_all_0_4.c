/*********************************************************
  Pfam_BP_all_0_4.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:18:13 2005
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
-0.782500, 0.389460, 0.231700, 0.089850, 0.627360, -1.426780, 0.873490, -0.168210, 0.400840, 1.007130, 
-0.051160, 0.126050, -0.467420, 0.746930, -0.307580, -0.476120, 0.131640, -0.747530, -0.528480, 0.213160, 
-0.202810, -1.109100, -0.110430, 0.342060, 0.706610, -0.877630, -0.595470, -0.038840, -0.975470, -0.975300, 
0.515540, 0.571970, 1.174640, 0.398830, 0.622990, -1.816160, 0.407290, -0.788920, 0.901820, 0.935570, 
0.576280, 0.608930, 0.902910, -0.499660, 1.308390, -0.282650, -0.065350, 0.227920, 0.400140, -0.780940, 
-0.686820, 0.010610, 0.131810, 0.452440, 0.501390, 0.417460, 0.608480, 0.179370, 0.543180, 0.590160, 
-1.128590, -0.182980, 1.372870, 0.306690, -0.410160, -0.820460, 0.528520, 0.138150, -0.175400, -0.046450, 
-1.139140, -0.508790, 0.015560, -0.630220, -0.429120, -1.029810, -0.354450, -0.973930, 0.765110, -0.868380, 
0.689150, 0.011060, -0.257780, 0.119630, 0.493790, -0.035630, -0.139090, -0.245060, -0.619900, 0.460590, 
0.246320, 0.677180, 0.562020, -0.157480, -0.908380, -0.336420, 0.757600, 0.566210, 0.717160, 1.514580, 
-0.812370, 0.078620, -0.789110, 0.296880, 0.488050, 0.862500, -0.022880, 1.136600, -0.844500, 0.026210, 
-0.834880, 0.381240, 0.668580, -0.122790, 0.236070, -1.181680, -1.552080, -0.640160, -0.733810, -0.360410, 
-0.527930, -0.475560, 1.100280, -1.454150, -1.062540, -0.620750, 0.097180, 0.315050, -0.458590, -0.112780, 
-0.026600, 0.532530, -2.238750, 1.438280, 1.763800, -0.842270, -0.688610, 0.728520, -0.102880, 1.470040, 
0.579710, -0.601760, -0.759090, 0.108100, 1.433120, -0.290410, 0.566370, -0.661640, 1.095980, -0.951900, 
-0.764270, -0.680710, 0.198530, -1.058150, 0.101140, -0.630410, 0.691010, -0.487020, -0.311600, 0.777890, 
0.236910, -0.593410, -1.507550, -0.272560, 1.495410, 1.054120, -0.513690, 0.430910, -0.842250, 1.370620, 
0.675710, -0.021240, 0.000300, 0.056410, -0.000880, 0.633440, 0.014500, 0.952660, -1.173050, -0.742030, 
0.420950, -0.553420, -0.450440, 0.156380, -0.210620, -1.243740, -0.216110, -0.022040, 0.810980, -0.935440, 
-1.269560, -0.002780, 1.357080, 1.730130, -1.493190, 1.454620, 0.049460, -0.560850, 0.946460, -0.178700, 
0.710520, -1.136220, -0.721340, 1.437090, -0.304720, 0.099660, 0.165300, 0.853960, -0.165810, -0.134970, 
-0.221440, 0.138210, 0.158530, 0.385010, -0.858260, -0.146990, -0.023850, -0.514770, -0.490040, -0.375550, 
0.328010, 0.666460, 0.355640, 0.103790, 0.409140, 0.202530, 0.733940, -0.094640, -0.892020, 0.245090, 
-0.688960, 0.437450, 0.385430, 0.258000, -0.513030, 0.830450, -0.238720, -0.623400, -0.862960, 1.007970, 
-0.010310, -1.710840, -0.130550, 0.582700, 1.263640, -0.420440, 0.370340, 0.367790, 0.827480, -1.017690, 
0.085180, 1.124320, 0.114270, 1.034860, 0.645650, -0.540510, 0.268210, -1.272690, -0.259460, 0.865870, 
-0.727010, 0.256860, 0.210280, 0.414310, -0.241790, 0.589640, 0.633570, 0.371300, -0.372410, 1.177550, 
0.569040, -0.533950, 1.379650, -0.490210, -0.013880, 1.017270, 0.454930, 0.248370, -0.892330, 0.987740, 
0.452460, -0.154830, -0.320750, -0.611750, 0.800020, 0.204120, 0.543200, 0.219830, 0.367780, 0.961820, 
0.226180, -0.447680, 0.398040, -0.308980, -0.297140, 1.056300, -0.605630, 0.337270, 0.950800, 
0.398670, 0.243420, -0.523460, 0.611850, -0.755170, 1.111130, -0.607650, 0.454710, 0.144550, -0.520760, 
-0.484540, 0.404350, 0.570680, 0.105000, -0.634580, 1.060870, 0.282180, -0.135270, 1.406500, 0.390600, 
0.257530, -1.280900, -1.293640, 0.482570, -0.216510, 0.830620, 0.106830, 0.770370, 0.153560, -0.023890, 
0.079450, 0.039420, -0.290560, -0.230470, -0.822690, -0.090540, 0.481300, 0.071180, 0.128080, -0.376310, 
-2.011780, 0.705730, -0.661310, 0.416910, -0.580470, -0.163360, 0.440430, -0.010340, -0.901950, -0.035720, 
0.877280, 0.771650, -1.007110, 0.528070, -0.164790, -0.209820, -0.891320, -0.090770, 1.585410, 0.514300, 
-1.003810, -0.133310, 0.234330, -0.769850, 0.886560, 0.303100, 0.986620, -0.300380, 0.309950, 0.169560, 
-0.643220, -0.150910, 0.934440, 0.008330, -1.104060, -1.506530, 1.528980, -0.349960, -0.108330, -1.408440, 
0.261880, 0.149460, -0.046440, 0.658620, 0.174160, 0.608820, 0.974640, 0.357030, 0.204070, 0.675860, 
-1.374380, -0.451810, 0.069460, -0.413570, 0.368890, 0.291940, 0.130880, -0.637620, -0.666280, -0.322790, 
0.353880, -1.223700, 0.067340, -1.405160, 0.225650, 0.377820, 0.395050, -0.398130, 0.610140, -0.503240, 
-0.764880, 0.190010, -0.019050, 1.484070, 0.527960, -0.353900, -0.940670, -0.692450, 0.154020, -0.819980, 
0.990020, 1.053030, -0.233500, -1.612230, -1.408080, -0.644160, 0.747550, 0.195120, -1.080630, -0.306790, 
2.405190, 0.049990, -2.569610, 0.824380, -0.121990, -2.028550, -0.573570, 1.370080, 0.391260, 0.896230, 
-0.171010, -0.179390, -0.349500, 0.196780, -0.337050, -1.599410, -1.040650, 1.583060, -1.351490, -0.090250, 
-0.639620, -0.227450, -0.215450, 0.254370, 1.138580, -0.606530, -1.104700, -0.008040, -0.285700, 0.500660, 
-0.669680, 0.478100, -0.662290, 0.344240, 0.525580, -0.401580, -0.583550, -0.296950, -0.557870, 0.056610, 
0.053000, -0.841340, 0.709550, 0.118920, -0.661830, -0.686670, -0.555610, 0.115310, -0.981740, -0.380690, 
0.261750, -0.273670, 0.380160, 0.534120, 0.670610, 0.270040, -1.565240, 1.491400, -0.090910, 1.074500, 
1.132370, -0.033990, -0.366480, -0.880850, -1.419740, 0.030240, 0.569970, -1.007410, 0.360960, -0.574880, 
0.279390, -0.711970, 0.168550, 0.332160, -1.117740, 0.991070, 1.932950, -1.117550, 1.077320, -0.419760, 
0.016110, 0.332240, 0.469730, 0.951140, -0.850530, 1.200640, 0.270080, -0.160180, 0.719410, -0.127970, 
0.184240, 1.296380, -0.946730, 0.191180, -0.120980, 0.031780, 0.015780, -0.231650, -0.323710, 0.349050, 
0.356810, -0.201440, 0.192270, -0.418400, -0.876780, 0.897600, -0.516680, 0.627040, 0.289270, 0.810200, 
0.183800, -0.647940, 0.118630, 0.456280, -0.838620, 0.823090, -0.368090, 0.150250, 0.723360, -0.250080, 
1.379640, 0.264720, -0.332030, 0.296640, 0.036890, -0.762780, -0.054880, 0.012180, -0.234280, 0.768920, 
0.373600, -0.003990, 1.420250, 1.145430, -1.724100, -0.402880, 0.086010, -1.017570, -0.581760, -0.761350, 
-0.326210, 0.525560, 0.623950, -1.061660, 0.273030, -0.518470, -0.667130, 0.080980, 0.381100, -0.088540, 
0.721560, 0.842620, -0.735290, -0.086010, -0.303010, 0.454800, -0.113600, 0.753160, -0.463270, 1.355720, 
1.157190, -0.542170, 0.285110, 0.671480, 0.250540, 0.750060, 0.636120, -0.705130, -0.011130, 
0.424690, 1.070710, -0.017090, 0.747590, 0.564670, 0.455760, -0.214880, -0.935420, 0.270560, -0.088720, 
0.600750, 0.330510, 0.191510, -0.795520, -0.574010, 0.207570, 1.239680, 1.003030, -0.096900, -0.409400, 
-0.368470, 0.096250, 1.132690, 0.904110, 0.080000, 0.344780, 1.227290, 0.055510, -0.691790, 0.843310, 
0.571500, 0.310410, 0.606140, -0.034970, -0.304600, -0.381580, -0.661320, 0.115920, 0.012490, 0.452780, 
-1.068820, -1.036500, -0.121290, -0.736880, -0.809860, 0.638670, -1.176410, 0.484750, 0.001240, 1.095650, 
0.283300, -0.150680, 0.020990, 0.333030, -1.063990, 0.640060, 0.337490, 0.468390, 0.044760, -1.486900, 
-0.195070, -0.786960, -0.434810, 0.602390, -0.388350, -0.271290, -0.090190, -0.873600, -0.067040, -0.147000, 
-0.588580, 0.472750, 1.027620, 0.219690, 0.263180, -0.448320, -1.186130, 0.117900, 0.541480, 0.251740, 
-0.911850, -0.386110, 0.099050, 0.160930, -0.433570, 0.345300, -0.797180, -0.747330, 0.818810, -0.373100, 
0.595720, -0.265160, 0.973410, 0.809200, -0.198610, 0.488590, 1.082460, 0.901440, 0.195930, 0.215090, 
-0.449710, -1.266430, -0.428380, -0.004050, -0.489910, -0.908480, -0.808220, 0.262150, -0.054290, -0.089480, 
-0.088080, -0.213260, 0.876100, 0.224580, 0.837950, 0.744140, 1.138930, -0.831050, -1.571850, -0.119620, 
0.080890, 0.016060, -0.607290, 0.323480, -0.724310, -0.424100, -1.026250, 0.243240, 1.513610, -0.154120, 
-0.344920, 0.355750, 0.278120, 0.850430, 0.173090, 0.753140, -0.054170, -1.466050, 0.404340, -0.729590, 
-0.197650, -0.249780, -0.704300, 0.693940, -0.097930, -0.313200, -0.992130, 0.070160, 0.283060, -0.189730, 
1.541090, -1.479790, 0.757320, 0.525980, -1.383790, 0.621170, -0.814380, 1.168390, -0.361280, 0.356500, 
-0.580730, 0.355690, 1.071780, 0.564410, -0.982650, 1.457650, -0.031660, 0.131820, -0.029260, 0.293400, 
1.056620, 0.040010, 0.453110, 0.956310, 0.339770, -0.531810, -1.273630, 0.511670, -0.477650, -1.123360, 
-0.918870, -0.253930, -0.168410, -0.421760, -0.221540, 0.266840, -0.945490, -0.452760, 0.132850, 0.437690, 
0.784110, 0.186050, 0.500000, -0.860320, 0.511340, -0.923220, 1.086010, -0.560050, -0.148220, -0.020940, 
-0.493810, -0.697360, 0.041860, 0.852050, -1.065690, -0.015420, 0.746460, -0.160340, -0.767840, -0.425070, 
-0.394210, 0.531140, 0.246870, -0.262780, -0.617280, 0.418250, -0.614650, 1.156880, -0.615010, 0.322300, 
0.389050, 0.881650, -1.370100, 0.522340, 0.376810, -0.286710, -0.079540, -1.213960, -0.614450, 0.774950, 
0.286540, 0.628890, 0.314390, 0.583820, -0.612200, -0.100900, -0.348600, 0.022830, -0.497110, 0.664080, 
0.485890, -0.063700, 0.315220, -0.466780, -0.746620, 0.337400, 1.200520, -0.395240, -0.185930, -0.641100, 
-0.569020, -0.234310, -1.129440, 0.467950, 1.513270, -0.591920, 0.396020, -0.861840, 0.976880, 0.440100, 
-0.922860, -0.743710, -0.728740, -0.112680, 1.283600, -0.704890, 0.250350, 0.771890, -0.352010, -0.867540, 
-0.719090, -0.166260, 0.409940, -0.058750, -0.765450, -0.345030, 1.062520, 0.331250, 0.110010, -1.139610, 
-0.022830, -1.113700, -1.027810, 0.402370, 0.784020, -0.220900, 0.496320, 0.105380, -0.072460, -0.205820, 
-0.945910, -0.469900, -0.944940, -1.343550, -1.265430, -0.508910, 1.250220, -1.040460, -1.004240, 
0.287830, -0.826380, -0.065420, -0.315250, 0.471280, 1.093170, -0.293780, 0.566920, 0.177600, 0.308640, 
-0.620430, 0.598570, -0.182720, 0.194600, -0.472850, 1.377290, 0.316200, 0.000490, -0.523270, -0.587000, 
-0.775580, -0.697280, -0.386960, 0.336060, -1.411730, 0.526820, -0.276870, 0.727970, 0.671740, -0.427730, 
0.658390, -0.321940, -0.304540, 0.496770, 1.252880, -0.927910, -0.710660, -0.266750, 0.044950, -0.149630, 
0.047270, -1.555520, 1.042050, -0.220470, -0.108020, -0.157160, -0.266050, 0.043030, -1.673860, -0.395000, 
0.657860, -0.541170, -0.220590, 0.191910, 0.671760, -0.351460, 0.316010, -0.906530, 1.037120, -0.600050, 
-0.454780, 0.486770, -0.545980, -0.088080, 0.199140, 0.927710, 0.410250, 1.034080, -0.555400, 1.147940, 
-1.068650, -1.168160, 1.042430, 0.371570, -0.136980, -0.168020, -0.442270, -0.324260, -1.205380, -0.539720, 
-0.030060, 0.618770, -0.147470, -0.872650, 0.430870, 1.236060, -1.126460, 0.264960, 1.663060, -0.507120, 
-0.129180, -0.931910, 0.691950, 1.059650, 0.399720, -0.350620, -0.464980, 0.610940, -0.715690, 1.216840, 
0.806450, 0.796460, -0.581040, 0.715370, 0.526100, 0.918370, 0.893910, -0.009770, 0.008520, -0.397540, 
-0.200280, 0.246900, -0.777940, 0.425060, 0.271910, 0.122830, 1.199660, 0.958950, 0.854320, -0.261130, 
0.878630, -0.812640, 0.877120, 1.034120, 1.878760, -0.691030, -0.835980, -1.081230, 0.236920, 0.458420, 
-1.138170, -1.080140, 2.098630, -0.462930, -0.643050, 2.827190, 0.589210, -0.865000, 0.054790, 0.992960, 
1.154920, 0.554330, 0.384210, 0.383480, -0.499930, -0.346770, 1.381580, 0.665360, 0.584140, -0.288310, 
-0.485200, 0.394440, 0.804720, 0.718490, 0.336670, 0.700560, 0.289640, -0.067610, 0.371300, 0.223320, 
-1.473970, -0.801170, -0.021450, 0.401240, 0.519710, 1.325640, 0.153090, 0.806630, 0.140810, -0.724050, 
0.113330, 0.130700, -0.417890, 0.083020, -0.015800, -0.055440, -0.525740, 0.193670, -0.229440, -0.214620, 
-0.518420, -0.685310, 0.812370, 0.412770, 0.609720, 0.648030, 0.079310, 0.103800, -0.728470, -0.431550, 
-0.712120, 0.896310, 0.206590, -0.783390, -0.507250, 0.501840, -0.576470, 1.302720, 0.230880, 0.005240, 
-0.326110, -0.097310, 0.294280, -0.694480, 0.553890, -0.053080, 0.408440, 0.010010, -0.543160, -0.290380, 
-0.056210, 0.601410, 0.746620, -0.929700, -0.042840, 0.070480, -0.292410, 0.746940, -0.406750, 0.746740, 
-0.954540, 0.476320, 0.094620, -0.028670, 0.179410, -0.742060, -0.243560, 0.168950, 0.166330, -0.364400, 
0.075220, -1.095280, 0.770060, -0.090630, 0.074130, 0.392760, -0.000110, 0.042550, -0.688830, -0.996900, 
-0.513210, -0.519180, -0.387900, -0.097340, -0.199600, 0.631110, 0.240440, -0.620130, -0.391650, -0.444480, 
-0.137790, 0.424560, -0.148390, 0.167890, 0.052960, 0.941790, 0.486220, 0.510390, 0.670460, -1.311630, 
-0.714290, 0.108830, 0.541270, -1.196040, 0.596360, -0.122390, 0.400410, 0.694610, 0.643470, -1.274760, 
0.783970, 0.100980, 1.187510, 0.370260, 0.021590, -0.449190, -0.511990, 0.232600, 0.432790, -0.562050, 
-0.150860, -1.521770, -1.493900, -0.141750, 0.252860, -0.701360, 0.504470, -0.479030, -0.756240, -0.443320, 
-0.646110, -0.849170, -0.399140, -0.980590, -0.589780, 0.669450, 0.402470, 0.183290, -0.767990, 
-0.092660, -0.578070, -0.423930, 0.308790, 0.004680, -0.121250, -0.064220, 0.683030, 0.672190, 0.541080, 
-1.518020, 0.181370, -0.325370, -0.420820, -0.705910, -0.323960, -0.408010, -0.454020, 0.446200, -0.597950, 
0.668800, -1.190530, -0.369040, -0.078060, 0.253380, -0.189150, 1.156030, -0.357540, -0.343640, 0.429310, 
0.119300, 0.590760, -0.519280, 0.377540, 0.535780, 0.242330, -0.593480, -0.893580, -0.416890, -0.759890, 
0.211350, 0.161950, -0.933130, -0.035860, 0.103940, -0.614940, 0.642350, -0.164720, 0.430870, -0.328790, 
-1.120280, -0.253050, 0.057540, -0.088200, -0.336620, -0.328420, 0.379210, -0.387750, 0.455550, 0.360670, 
0.008760, 0.568570, -0.008920, -0.357940, -0.710930, 0.549100, 1.012700, -0.770160, -0.572840, -0.164430, 
0.207600, -0.322360, -0.753120, 1.073430, 0.138510, -0.943450, -0.532720, 0.426510, 0.673090, -0.331630, 
-0.386200, 0.353520, -0.225010, -0.191120, 0.012610, -0.337780, 0.565420, 0.043060, 0.079810, 0.636960, 
-0.760200, -0.566910, -1.149510, 0.436310, 0.526490, 1.287470, 0.175040, -0.620960, 0.587970, 0.756280, 
-0.695970, 1.279660, -1.179500, -0.799180, 0.624620, 0.498520, -0.227370, 0.788670, -0.128510, 1.459850, 
1.148130, -0.748380, 0.453590, -0.296970, 0.266410, 0.404260, -0.443820, -0.987330, 1.290310, -0.407210, 
-0.545750, 0.746940, 0.477660, -0.891650, 0.014940, -0.562690, 0.194180, 0.174330, 0.477670, -0.099280, 
-0.423710, -0.983210, -0.007670, -0.815280, -0.296250, -1.850730, 0.471670, 1.162870, 0.460200, 0.469640, 
0.664120, 0.858730, 0.007330, 0.556780, 0.484300, -0.022820, 0.541420, 0.625270, -0.878970, -0.688940, 
0.043150, -1.166840, 0.209240, -1.246250, -1.289600, 1.046130, 1.234650, 0.835570, -0.417980, -0.571200, 
0.647400, 0.435910, -0.807640, 0.432340, 0.393270, 0.566370, 0.568140, -1.029100, 1.337050, -0.649870, 
-0.880410, 0.791380, -0.795480, 0.251380, -0.547780, -0.200850, 0.410990, 1.118000, -0.009540, -0.680520, 
-1.220690, 0.200470, -0.756960, -0.913220, 0.957990, -1.156850, -0.167020, 1.260070, 0.369960, -0.549830, 
0.321760, -0.146850, -0.694180, -0.495590, 0.041730, 0.985300, -0.386050, 0.104770, -0.401490, 0.613070, 
0.117280, 0.266020, 0.538160, -0.508640, 1.109530, 0.389160, 0.757620, -0.291470, -0.895590, -0.649420, 
-1.374900, 0.919990, 0.360470, 0.374600, 0.052360, -0.094380, -1.203000, -0.869230, -0.438940, 0.606200, 
-0.213100, 0.447870, -1.586450, -0.037480, -0.889710, 0.868280, -0.558020, 0.576160, -0.393240, 0.477440, 
-0.994700, -0.986110, 1.045100, -0.086960, 0.464430, -0.451660, -0.051110, -0.405260, -1.000910, 0.112890, 
-0.027350, 0.199170, -0.635780, -1.159240, -0.465500, 0.272940, -0.645510, 0.088220, 0.007830, -1.118880, 
0.326240, -0.765100, -0.598840, -0.264530, 0.444580, -0.198530, 0.388240, 0.258270, 0.662800, -0.283190, 
0.633810, 0.614260, -0.049990, 0.257720, -1.156350, -1.111850, -1.146360, 0.760530, 0.511610, -1.114780, 
0.329860, 0.028750, -0.082580, -0.823940, -0.466260, -0.729880, -0.044430, 0.162260, -1.007800, -0.638050, 
-1.382620, -0.721710, -0.445970, 0.048570, -0.949640, -1.330760, 0.349420, -0.667730, -0.652120, 0.538380, 
-1.280630, 0.152190, -0.054970, -0.940380, 0.611020, 1.124030, -0.310290, -0.563210, 0.298130, 
-0.203540, 0.185760, 1.041710, -0.936710, 0.263580, 0.004120, -0.127330, 1.011960, -0.301980, 0.935660, 
1.320880, -0.006790, 0.596210, 0.832450, 1.381110, -0.315560, -0.433360, 0.033820, -0.267440, -0.718770, 
-1.612250, -0.844320, -1.377550, -0.174500, 1.341220, -0.697540, -0.065110, 0.418230, 0.173010, 0.173940, 
-1.826570, 0.832420, 0.624300, 0.696860, 1.304810, 1.087710, -0.010520, 1.234410, 0.559000, -1.068440, 
0.324200, 0.551210, 0.399260, -0.652950, 0.910950, -0.924140, 0.705560, -0.199470, 0.411450, 0.405770, 
-0.585090, -0.254300, -0.467540, 1.022390, -0.354690, -0.695790, -0.599260, 0.318490, -0.235020, 0.721270, 
0.388480, 0.057000, 0.501950, 0.342840, -0.629950, 0.864890, -0.372070, 1.319400, -0.550540, 0.965730, 
-0.706450, 0.448420, 0.068020, -0.410100, 0.776160, -0.365940, 0.432180, 0.549130, 0.438370, 0.745930, 
0.902980, -0.350600, 0.260370, -0.083310, -0.999350, 1.060460, -0.905390, 0.600700, 0.901270, -0.508480, 
0.198020, -0.279060, 0.234690, -0.409650, 0.598990, 0.173280, -0.879050, -0.831660, 0.548530, -0.249480, 
-0.358940, -0.877470, 0.642880, -0.107490, 0.439470, -0.657890, 0.628320, -0.371930, 0.578410, 0.188230, 
-0.620830, -0.242080, -0.857780, 1.363190, 0.277300, 0.632410, -0.359900, -0.632280, -0.111420, 1.742560, 
-0.513330, 0.236210, -0.674740, -1.832550, -0.519090, -1.458430, -0.406850, 0.915830, 0.421640, 0.569370, 
0.844360, 1.004510, -0.845260, -0.015220, 0.456370, -1.069040, 0.347870, 1.664950, -0.936870, 1.673910, 
0.136530, -0.072350, -0.020110, 0.176590, 0.061430, -1.226460, -0.007480, -0.828370, -0.601530, 0.154190, 
-0.640430, -0.099540, 0.432560, 0.764850, 0.588780, -0.670680, -2.144870, -0.896690, -0.956760, 1.164910, 
-0.335410, 0.263260, 0.438200, -0.152010, -1.238600, -0.033130, 0.170670, 1.434990, 0.089880, -1.203880, 
-0.916060, 0.399450, 0.201190, -0.551820, 0.355960, 0.046490, 0.027270, 0.011240, -0.409360, 0.289150, 
-0.693390, 0.140700, 0.028440, -0.084290, -0.875400, 0.132260, 0.335830, -1.117720, -0.352400, -0.095980, 
-0.620160, -0.092120, -1.375180, -1.031420, -0.552110, 0.188350, -1.004380, 0.101110, -0.835550, 0.071590, 
-0.629060, -0.439710, 0.697950, -0.234770, -0.370180, 0.081630, -0.143700, 0.372390, -0.515160, 0.762060, 
0.236710, 0.337750, 0.534960, -1.012150, 0.085360, -0.483460, -0.220720, -0.472990, 0.050340, 0.246470, 
-0.476120, 0.608640, -1.149690, -0.085120, -1.085260, 1.296470, -0.159240, 0.049630, -0.943270, 0.579660, 
-0.806460, 0.154910, 1.211710, 0.443720, -0.113110, -1.578590, -0.483910, 0.849680, -1.320270, -0.499340, 
0.689850, -0.623770, 0.973230, -0.591890, -0.340380, -0.297840, -0.272740, -0.276220, -0.798930, 0.103110, 
0.662930, -0.491670, 0.595110, 0.059620, -0.487760, 0.370480, -0.270030, -0.196790, -0.153540, 1.321460, 
-0.018520, 0.218520, 1.613700, 0.657860, 0.857370, 1.164790, -0.078500, -0.190650, 1.208490, 1.697820, 
-0.776610, -1.159010, 0.359680, 0.904760, -0.200460, 1.076560, -1.148290, 0.794910, 0.840790, -0.164750, 
-0.158580, -0.883480, 0.645960, -0.161690, -0.803300, -0.391710, 0.499350, -0.303820, 0.169910, 0.547630, 
0.508960, 0.582890, -0.459220, 0.796510, -0.568750, 0.375280, -0.026670, -0.537480, -0.060030, 
0.295250, -0.660790, 1.223420, 0.902610, -0.209090, -0.140110, 0.399430, 0.056090, -1.088100, -0.357430, 
-0.515330, -0.321620, 0.013540, -0.544330, -0.868190, -0.161370, 0.080620, -0.758000, -1.118380, -0.687610, 
-0.550360, -0.455870, -0.881840, -0.184760, -0.363990, -0.617960, -1.867800, -0.024460, 1.779550, 0.337700, 
0.974230, -0.781800, -0.732560, 0.399030, 0.531170, -0.241970, -0.054420, 0.473620, -0.163190, 1.183680, 
1.005680, -0.477690, 0.102560, -0.349010, -1.117380, 0.606200, -0.252660, 0.104460, -0.785410, 0.673740, 
-1.121760, -0.510920, 0.607240, 0.832760, -1.409990, -0.091630, -0.224930, -0.611360, 0.444520, -0.207760, 
-0.657240, 0.016760, -0.120090, 0.368430, 0.123250, 0.727770, -0.497340, -0.364320, 0.837630, 0.333300, 
-1.038210, 0.528900, -0.313290, -1.199910, -1.086960, -0.315880, 0.067520, 0.882610, -0.619140, 0.966350, 
-0.304200, -0.299980, -0.471400, -0.770010, -0.367010, 0.375110, 0.068660, 0.255090, 0.257930, -0.181110, 
0.048050, 0.060280, 1.797400, 1.060560, -0.917320, -0.368120, 0.546990, 0.077260, 0.860840, 0.657620, 
-0.407610, 1.534610, 0.374530, 0.356770, 0.394880, -1.461810, -0.618900, 0.329870, -1.078950, 0.209050, 
1.512520, 0.507520, -0.216690, 0.926260, 0.364510, 0.027540, -0.132840, -0.745660, 0.473670, -0.997140, 
-0.645190, 0.063260, -0.429350, -0.633120, -1.193240, 1.267530, 0.929240, 0.237920, -0.147950, 1.353940, 
-1.194640, 1.592640, -0.886000, 0.915600, 0.096410, -2.344690, 0.162250, -0.140250, -0.165270, 0.906160, 
0.640360, -0.198330, 0.742930, 0.781870, -0.351150, -0.290660, -0.473220, -0.877450, 0.155260, -0.347770, 
0.634690, -0.590700, -0.128820, -0.719280, 0.600530, 0.542530, 0.707780, -0.312550, -0.096150, 0.586740, 
0.736040, -0.514770, 0.326560, -0.137380, -0.456740, -0.632520, 0.449950, -0.347270, 0.074010, 1.423340, 
0.792050, 0.429620, 0.451720, 1.082630, -0.473960, -0.464310, -1.159080, 1.198740, 0.510000, 0.924820, 
-1.003270, 0.763600, -0.684220, 0.176360, 0.593480, -0.323950, 1.372170, 0.291300, 0.706700, -0.021860, 
0.994690, 0.942670, 1.200340, -0.788500, 0.846440, 0.651050, -0.297880, -0.081290, -0.069410, -0.096980, 
-0.745520, 0.541050, 1.203570, 0.530870, 0.311100, 0.952960, 0.304180, -0.291600, -1.292740, -0.174030, 
0.110700, 0.380790, 0.184940, 0.379150, -0.741870, 0.844760, -1.328080, -0.051080, -0.006180, 0.875460, 
0.260990, 1.005910, -0.627710, 0.772560, -0.459760, -0.047070, 0.219710, -1.088070, 0.800240, -0.924280, 
1.196460, -0.352440, 0.617120, -1.295610, -0.410780, -0.119630, 1.873970, 0.904570, -0.800610, 0.544600, 
0.351880, -0.297400, -0.069210, 1.276180, -0.574320, -0.584290, 0.109940, -0.702120, 0.255630, 0.374650, 
1.587980, -0.027680, 0.299210, -0.032910, -0.008830, 0.422950, -0.001330, 0.493110, 0.692050, 1.587100, 
-0.517210, -0.118300, 0.641210, 1.273780, -0.992410, 1.057590, 0.392960, 0.306000, 0.516380, -0.478460, 
-0.147070, 0.387630, 0.067300, 0.655260, 0.682270, -0.082430, -0.101900, -0.497030, -0.158480, -0.544780, 
0.313720, 0.572790, 0.308980, 0.836470, 1.074770, -0.324840, 0.110900, 0.358480, -0.032620, -0.719390, 
-0.862220, -0.059400, -0.053430, -0.247620, 0.442040, -0.096940, -0.784270, -0.550270, 0.478540, 
-1.149770, -1.215690, -0.398720, -0.447810, -0.554130, -0.482430, 0.277140, 0.806880, -0.638390, 1.420710, 
-0.384540, 0.107420, -0.249980, -1.918260, -0.647280, -0.820780, 0.966820, -0.380030, -0.071270, -0.361530, 
-1.006410, -0.818380, -0.548860, 0.459600, -0.254280, 0.200350, 0.995600, -0.718640, 0.358750, -1.021580, 
0.888350, 0.302380, 0.588760, -0.255290, 0.442680, 0.499760, -0.325150, 0.560820, 1.093490, -0.557350, 
0.723940, -0.073390, -0.554630, -0.270380, 0.484340, 0.464030, 0.208280, 1.184940, 0.045520, 0.469490, 
0.441210, 1.252170, -0.811120, 1.182560, -0.565260, 0.417060, 0.078330, 0.116780, 0.955350, 0.570430, 
0.775230, -0.018760, 0.765140, 0.054290, -0.327020, -0.802320, -0.141480, 0.581840, 0.228010, 0.880780, 
0.188510, -0.428280, -0.340390, 0.431170, 0.841350, -0.924110, 0.760770, 1.224100, 0.415010, -0.760040, 
-0.030560, -0.544990, -0.952140, -0.612420, 0.132890, 0.787130, 1.739390, 0.229000, 0.099490, 1.346550, 
-0.484410, -0.273010, 0.577140, -0.924650, -0.802160, 0.328360, -0.474770, -0.607680, 1.015560, 0.279030, 
-0.185140, -0.106030, -0.358220, 0.123680, 0.287130, -0.343120, -0.579770, 0.919240, 0.633510, 1.104100, 
-0.499330, -1.290990, 0.157810, 0.391510, 0.278610, 0.569380, -0.251270, 0.940210, 1.911880, 1.075750, 
0.270880, -0.252530, 0.019100, 1.272100, -0.447700, 0.777880, 0.451680, -0.766860, 0.745950, -0.558930, 
0.169680, -0.952790, 0.800420, 1.047840, -0.743540, 0.100630, -0.394910, -1.014420, -0.755770, 0.439430, 
-0.434240, 0.264550, -0.655090, -0.676500, -0.556300, 0.161540, -0.580800, 0.466610, -0.139800, 0.229820, 
-0.158260, -0.699260, 0.673510, -0.315520, -0.140510, -0.634820, 0.434290, -0.790080, -0.527800, -0.954330, 
-0.144230, -0.428810, -0.901190, 0.387930, -1.231130, -0.473580, -0.716170, -0.293420, -1.313190, -0.686360, 
-0.144530, -0.603890, 0.908940, -1.379470, -0.761020, 0.636180, -1.144020, -0.080260, 0.656080, 1.244820, 
-1.465490, -0.292700, -1.043580, 0.502440, -0.002490, 0.287330, 1.319580, 0.449680, -0.859060, 0.170340, 
0.803630, 0.837680, 0.878420, -0.192250, 0.246490, -0.650320, 0.439570, -1.193810, -0.363850, 0.064540, 
-0.476780, 0.011780, -0.680870, 1.007470, 0.330470, -0.780880, -0.368010, 0.285860, 1.101270, -0.505100, 
0.408820, -0.357070, 0.351670, -1.219990, -1.228190, -0.871800, 0.777390, 0.336420, -0.066980, -1.370930, 
0.488380, -0.788150, 1.063590, -0.340110, 0.191410, 0.862880, 0.683430, -0.551130, 0.744450, -0.187690, 
0.083920, -0.168380, -0.274120, -1.149490, 0.077680, -1.251050, -0.174640, 0.763500, 0.450690, -1.378030, 
-1.085210, -0.358330, 0.178240, 1.031300, 0.272390, -0.495460, 0.372130, -0.227660, -0.333930, 0.325730, 
0.300840, 0.094330, 0.691150, 0.508440, -1.007450, 0.635680, 0.435860, 0.196240, -0.222980, 0.165000, 
0.011670, 0.454990, -0.140360, 0.619540, -0.233480, 0.394920, 0.371540, -0.244300, 0.067560, -0.012070, 
-0.101180, -0.095310, -0.249530, 0.127660, -0.273340, 0.707520, 1.084400, 0.681870, 0.821880, -0.308040, 
0.523260, -0.621840, -0.462720, -0.300710, -0.349930, -1.146280, -0.321040, -0.159160, 0.729690, 0.016560, 
0.452120, 0.576180, 0.831780, -0.394310, -0.078470, -0.771870, -0.821820, 0.107810, -0.264420, 
-0.299910, 0.521620, -1.097390, 0.026590, 0.867120, 0.233120, -0.218150, -0.161260, 0.709530, -0.192050, 
-0.268890, -0.929590, -0.674300, -0.349730, -1.286520, -0.082660, 0.330580, 0.696590, 0.817030, -0.680850, 
1.634590, 0.438430, -0.501580, 0.436180, -1.068310, -0.314720, 0.084150, 0.565930, -0.352210, 0.196460, 
-0.256420, -0.472980, 0.501590, 0.724780, 0.101350, -1.030420, 0.833040, 0.082160, 0.866490, 0.162440, 
0.335040, -0.300880, -0.524570, 1.320900, 0.359290, 0.548680, 0.575770, -0.033370, -0.890540, 1.057700, 
0.073750, -0.003980, -0.771040, 0.774480, -0.460240, -0.427690, 0.971800, -1.297740, -0.492480, -0.697170, 
0.590360, -0.156290, -0.478970, 0.928410, -1.245150, -1.257280, 0.587200, 0.201740, 0.291330, 0.375700, 
-0.101170, 0.020770, -0.433600, 0.436170, 0.043080, 0.104980, 0.479580, -1.416180, 0.674610, 0.374480, 
-0.576570, 1.758040, 0.628300, -0.559400, 1.025760, 0.108230, -1.114720, 0.919010, -0.003630, -0.588550, 
-0.042530, 0.321420, 0.757660, 0.785180, -0.453660, 0.658160, -0.216540, -0.751860, -0.445570, 0.627830, 
0.426760, -0.999020, -0.007920, 0.398330, 1.242920, -0.400020, -0.228210, -1.136300, -0.177780, 0.271760, 
0.744780, -1.384430, 0.876130, 0.437400, -0.186470, -0.316400, -1.609630, 0.335080, 1.721830, -1.032640, 
-0.920320, 1.066780, 0.616160, 0.180820, -0.926840, 0.609840, -0.579240, -0.164760, -0.254270, -0.111370, 
0.404620, -0.374180, -0.792830, 0.265480, -0.522870, -1.399020, -0.523270, -0.017470, 0.634200, 0.655410, 
-0.710120, 0.464610, 0.129100, 0.719050, -0.382360, 1.296480, -0.945230, 0.400480, 0.287710, -0.356250, 
0.635810, -1.021610, 0.289350, -0.265910, 0.897650, 0.620570, -0.012000, -0.468980, 0.511010, -0.247200, 
-0.900420, -0.815210, -0.843730, 0.487480, -0.261500, -0.031460, -0.402710, 0.164610, 0.947330, -1.062440, 
-1.212160, 0.447090, -0.520360, -0.670420, -0.339500, -0.188960, 1.083530, 0.907780, -1.222160, 0.002410, 
-0.274100, -0.750440, -1.659460, -0.083070, 0.519970, 0.786660, -0.646450, 0.278560, -0.456210, -0.017460, 
0.787340, 0.613510, -0.071570, 0.459160, 0.678290, 0.125400, 0.275410, -0.406870, -0.480130, -0.120860, 
-0.177970, -0.661820, 0.197680, 0.300640, 0.115120, -0.299150, -0.870170, -0.078750, 0.059660, 0.080890, 
-0.068790, 0.464240, 1.140540, -0.714340, 0.221810, 0.547080, -0.141090, 0.349450, -0.816840, 1.243570, 
-0.829660, -0.616310, -0.479710, 0.716380, 0.946820, -0.170860, 0.100680, 0.076460, -0.755080, -0.401830, 
-0.164270, -1.317480, -0.956550, 0.936760, 0.153100, -0.471370, 0.335040, -0.794110, 0.348230, -0.860620, 
-0.882690, -0.585950, -0.156060, 0.192190, -0.512820, 0.631110, 1.061840, -0.623140, -0.724920, 0.041300, 
-0.330760, 0.448220, -0.925470, -0.559960, -0.172570, -1.444300, 0.878660, 0.929260, 0.634700, 0.089630, 
0.516750, 0.545220, 0.935630, -0.056530, -0.323500, 0.437560, -0.522220, 0.229740, 0.224680, 0.513340, 
0.416780, 0.141670, -0.355610, 0.337140, 1.172600, 0.406470, 0.858510, 0.745170, 0.769310, 0.585910, 
-0.012380, 0.240460, -0.503070, 0.648490, 0.199520, -0.570740, -0.981580, -0.027460, 0.260150, -0.732290, 
-0.324560, -0.603010, 0.482520, -0.048910, -0.974660, -0.126080, -0.877220, -1.267120, 0.401840, 
0.193320, -0.216580, -0.878340, 0.304280, 0.878030, -0.860570, 0.567870, 0.630070, -0.644870, -1.215100, 
-0.284780, -1.123110, -0.801730, 0.045590, 0.332510, 0.405250, -0.766850, -0.143560, -0.346030, -0.292760, 
-0.027820, 0.384840, -0.220340, -0.512160, 1.566790, -0.556670, -1.417400, 0.559020, 1.220240, -0.628000, 
1.073830, -0.566090, -0.990930, 0.053230, 1.094440, -0.222230, 0.663310, 0.824530, -0.319480, -0.797990, 
-0.609350, 0.482550, -0.288010, -1.593580, -0.988760, 0.135640, 0.038640, 0.075100, 0.646320, 0.779390, 
-0.094840, 0.222910, 0.032870, -0.241360, 0.024900, -0.946220, 0.092700, -0.538260, 0.928330, -0.352170, 
-0.426030, 0.111630, 0.855150, 0.709810, -0.407950, -0.903120, -0.479970, 1.205590, 0.307990, -0.423040, 
-0.627560, 0.279070, 0.563260, -0.163080, -0.433850, 0.280560, 0.481080, 0.576600, 1.016180, 0.478280, 
-0.137570, 0.312640, 0.313390, 0.171040, 0.504940, 1.044630, 0.934550, -0.447270, -0.018720, 1.251570, 
0.738880, 1.372190, -0.152200, -0.512100, 0.505400, 0.288090, 0.697130, -0.188810, 0.915920, 0.119830, 
-0.097960, 0.557830, 0.298250, -0.099340, 0.043160, -0.804600, -0.294740, 0.160670, -0.735480, 0.652410, 
0.823230, -0.253690, -0.094220, -0.181700, -0.504410, 1.846450, 1.032500, 1.309000, -0.190240, -0.233900, 
-0.511410, -1.043300, -0.236580, -0.418830, 1.822670, -1.220400, -0.792800, -0.039320, 0.839140, 0.040290, 
0.500210, -0.238770, -0.935900, -0.282700, 0.129950, -0.007050, -0.733720, -1.639240, 0.239000, -1.027730, 
0.720550, -0.618500, -0.193210, 0.244970, -0.707690, -0.044150, -0.531930, 0.530940, 0.057220, -0.368100, 
0.506320, 0.379750, 0.058340, -0.862990, 0.111140, 0.503340, -1.114550, -0.940950, 0.374210, 0.238790, 
-1.137200, 1.103920, 0.479190, -0.133480, 0.507220, 0.689570, -0.753710, -0.459980, 0.627160, 1.383610, 
-0.069420, 0.708540, -0.290230, -0.146560, -0.305100, 0.195970, 0.085350, -0.259740, 0.444000, -1.104950, 
0.571300, 1.141150, 0.308450, 0.473670, -0.085840, 0.670290, 1.163820, -0.589080, 0.797520, -1.327640, 
1.177010, -1.043800, -0.721520, 0.667950, 0.449550, 0.224460, 0.840760, -0.580500, -0.103930, 0.518950, 
0.043410, 0.265310, -0.790110, 0.173840, -0.540790, 0.265150, -0.442500, 1.042350, 0.908080, 0.878790, 
-0.099670, 0.133110, 1.469040, 0.422560, -0.204990, -1.128210, -0.704790, -0.314370, 0.579020, -1.011310, 
-0.231390, 0.805170, -0.879570, -0.200870, 0.795080, -0.105740, 0.789330, 0.554300, 1.106240, 0.213210, 
0.138350, -0.466030, 1.123800, -0.205250, 0.472900, 0.570750, -0.392090, 0.660400, -0.355800, -1.059240, 
0.422850, 0.194880, 0.187000, 1.107820, 0.220570, -0.436730, 0.434970, -0.147290, 0.238030, -0.786740, 
-0.717430, 0.202820, 0.046960, 0.711300, -0.440370, -0.076820, -1.645210, 1.023600, -0.459380, -1.433110, 
-0.301840, -0.424350, -0.121840, -1.181160, -1.332150, -1.436530, 0.040090, -1.170030, -0.379090, 0.999090, 
0.558660, 0.549200, 0.121490, -0.438200, 0.938600, -1.227610, -0.685810, -0.421010, 0.114670, 0.317040, 
0.043250, -0.942830, -0.540250, -0.818380, -0.045680, 0.068790, -0.535790, -0.681140, 0.402930, -0.074600, 
-0.705730, -0.357030, 0.430210, 1.327880, -0.158400, 0.635650, -0.753180, 1.427860, -0.211830, 
0.582950, 0.174930, -1.411050, -0.022740, -0.014150, 1.098790, 0.049560, 1.216430, 0.109510, 0.647250, 
-0.162770, -0.870030, 0.822310, 0.858360, -0.358410, -1.135420, -0.948760, 0.045840, 0.323030, 0.329940, 
0.626860, -0.593140, -0.756370, -0.662950, 0.866300, 0.350960, 0.079260, 0.731440, -0.737890, -1.068490, 
0.331240, 0.003150, -0.241770, -0.835310, -0.721980, 0.162820, -0.252010, 0.499070, -0.479500, -0.894100, 
-0.008000, -0.887010, 0.581230, -0.009630, -1.069370, -1.108920, 0.691300, 1.166720, -0.215120, 0.474020, 
-0.151470, 1.028570, -0.706740, 0.515960, 0.839940, -0.710160, -1.013700, -0.910170, -1.215610, 0.514760, 
0.686880, 0.534420, 0.132120, 0.351650, -0.705640, -1.150230, 0.014780, -0.380510, -0.628030, 0.897650, 
0.533120, -0.363020, 0.177530, -0.723900, -1.160450, 0.927760, 0.510630, -0.466140, -0.482870, -0.681630, 
1.405530, 0.810220, 1.145340, -0.324410, 0.082390, -0.121720, -0.918690, -0.796150, 0.390620, 0.439480, 
0.376850, 0.771100, 0.022070, 0.707440, 0.655520, 0.468020, 0.182850, -0.267420, 1.117970, 0.412610, 
0.214220, 0.919760, 0.175250, -1.033470, 0.654230, 0.504210, 0.251320, 0.603330, -0.192730, 0.396460, 
-0.029360, 0.562230, 0.382180, 0.605570, -0.590050, 0.633600, 0.895150, 1.600090, 0.179610, 0.689150, 
0.146300, -0.743650, 0.196270, 0.293440, -0.064500, -0.042230, 0.451530, -1.237140, -0.342810, 0.348040, 
0.580960, 0.424490, -0.021980, 0.643320, -0.681840, 0.466560, 0.588710, 0.169810, -0.403900, 0.798720, 
0.308020, -0.188440, 0.581430, -0.710400, -0.488800, 0.741030, 0.466710, 0.710210, 0.616630, 0.377940, 
-0.714660, 0.259070, 0.033210, -0.345450, -0.933440, -1.214900, 0.102090, -0.643020, -0.206900, -0.095860, 
0.562430, -0.572580, -0.369750, -0.678780, -0.084010, -0.384980, 0.401920, 0.256800, -0.572550, 0.406480, 
-0.054100, -0.491930, 1.491400, -0.011690, 0.964450, 0.223790, -0.350590, -0.264880, -0.313560, -0.443530, 
0.157110, -1.438910, 0.208870, 0.201250, -0.455310, 1.056830, 0.640880, 0.214020, -0.009500, 0.283210, 
0.107830, -0.119090, 0.234030, 0.002650, -1.074430, 0.089140, -0.598680, 1.497760, 0.249130, -0.024220, 
-1.154410, -0.513120, 1.272970, -0.058240, -0.621600, 1.087890, 0.171480, -1.004650, 0.724730, -0.618520, 
0.674590, -0.424960, -0.046560, 0.040450, -1.227010, -0.061080, 0.318650, -0.068070, -0.306950, -0.807700, 
-0.991860, 0.885800, -1.038280, 0.843430, 0.413140, 0.167010, -0.231980, -0.571060, 0.237110, 0.606260, 
-0.089000, -0.577530, -0.219800, -0.275100, 0.252970, 0.901740, 0.237040, 1.093500, -0.047430, -0.190860, 
0.596360, 0.837600, -0.282690, 0.010360, 0.142190, -0.451720, 0.710240, 0.458850, 0.674860, -0.275970, 
-0.257650, -0.166800, -0.119930, -0.796440, 1.170370, 0.317160, 1.404280, -0.039200, -0.508840, -0.364860, 
0.764120, 0.290000, -0.835880, 0.248140, -0.803590, -0.500630, 1.418820, -0.286810, 0.579680, -0.513090, 
0.049160, -0.542100, 0.243210, 0.402470, -0.622430, 0.953870, 0.448100, 0.632430, -0.108790, 0.412400, 
0.784580, 0.541190, -1.357090, -0.704220, 0.264050, 0.408150, -0.612890, -0.497780, 0.581510, 0.607260, 
-0.058690, -0.064570, -0.488770, 0.803290, 0.057460, 0.535090, -0.503890, 0.795520, 0.453760, 
-0.017430, 0.175540, -0.619190, 0.275030, -0.340740, -0.762450, 0.894810, -0.181090, 0.804480, 0.679360, 
-0.571970, -1.493600, 0.375860, 0.095620, 0.756670, 0.538200, -0.254420, -1.267150, 0.462090, -0.398680, 
0.336160, 0.928440, -0.462660, 0.471280, -0.426350, -0.616440, -0.035060, -1.040830, 1.158480, -0.043330, 
-1.058960, -1.143510, -1.672840, -0.660080, 0.403180, 0.245580, 1.446930, -0.267850, -0.819360, 1.257160, 
1.183300, -0.974880, -0.223030, -0.485110, 0.613020, 0.347210, 0.539600, -0.498870, 0.079410, -0.554060, 
0.070510, -0.542750, 0.506130, 0.907850, 0.703910, -0.968250, 0.337590, 0.456120, 0.331690, 0.730650, 
0.191630, -0.641680, 0.727880, 0.863050, -1.071920, -0.722490, 0.209740, 0.486940, 1.053530, -0.140290, 
-0.322740, 0.627410, 0.734090, -0.832100, -0.211180, 0.516470, -0.406750, -0.432450, 0.311040, 0.733620, 
0.517670, -0.388840, -0.096040, 0.469930, 0.760830, -0.327350, -0.476980, -0.981790, -0.611240, 0.876380, 
0.278790, -0.874190, 0.819430, 0.095780, -0.499700, -0.347840, 0.033750, -0.139470, -0.501780, 0.472150, 
0.216660, 1.348100, 1.452230, -0.047650, -0.297170, 0.853640, 1.040300, -0.160660, -0.726500, -0.904920, 
0.732990, -0.173740, 0.662000, 0.615930, -0.432950, 0.173350, -0.737870, -0.085580, -0.939670, -1.019180, 
-0.030400, -0.078210, -1.325930, -0.835290, -1.671030, -0.060640, 0.603480, 0.967670, -0.294590, 0.291050, 
0.068230, -0.510840, -1.511160, -0.850510, -0.563280, 1.040430, -0.351990, -1.596010, 0.448800, -0.432920, 
0.355420, -0.269170, 0.975980, -0.094100, 0.508020, -0.044620, 0.930670, 1.473970, 1.712260, 1.172680, 
-0.182050, 0.210360, 0.560490, 0.234800, -0.459550, -0.594910, 0.057700, -0.130240, -0.134960, 1.308730, 
-0.915890, -0.686260, 0.830460, -0.666870, -0.198910, 0.681820, -0.063620, -1.169190, -0.480460, 0.185080, 
-0.045520, 0.256110, 0.898810, 0.577000, -1.034700, 0.050180, -0.270800, -0.384160, 1.083040, 0.450620, 
-0.946670, -0.207840, 1.448980, -0.109210, -1.247740, -0.754730, -0.760030, -0.852220, -0.797230, 0.993860, 
0.201620, -0.155350, -0.848790, 0.396700, 1.133610, 0.284860, 0.023440, -0.389860, 0.313170, -0.241000, 
0.959320, 0.730090, -0.590000, 0.224830, 0.253060, 0.419370, 0.129340, -0.479050, -0.436630, 0.382630, 
-0.448620, -1.229170, 0.158550, 0.002200, -0.645620, 0.640160, -0.002760, 0.242300, -0.108640, -0.195830, 
-0.104830, 0.070230, 0.524410, -0.328900, -0.290460, -0.312200, -0.737860, 1.575330, 0.547200, 0.581020, 
1.676670, -0.451700, -0.235550, -0.448880, -0.372460, 0.077520, 1.196400, 0.559780, 0.556470, -0.591100, 
-0.465520, 0.047630, -0.309800, 0.900990, -0.515080, -0.472910, -1.823700, 0.753700, 1.151590, 0.572220, 
-0.709700, -0.457560, 0.207800, -0.176490, -0.017180, -0.380570, 0.599860, 0.549900, -0.257450, 0.308060, 
-0.481820, -0.067720, 2.723930, 0.810030, -0.530510, -0.233520, 0.074460, 0.581490, -0.362490, -1.120850, 
0.262810, 0.897710, -0.065380, -0.707620, -0.631350, -0.111940, -0.665930, 0.167370, -0.262490, -0.563390, 
0.786460, 0.381900, 0.025710, 0.910040, 0.729360, -0.449080, 0.407960, 0.266550, 0.437970, 0.204600, 
-1.145460, 0.702320, 0.228830, -0.876590, 0.222800, -0.025160, 0.410340, 0.977390, -0.940010, 
0.955300, -0.073270, -0.905870, 0.169970, 0.890600, -0.445880, -0.958700, 1.211070, -0.222920, 0.754740, 
-0.236060, 0.871130, -0.335720, -0.011800, -0.396730, -0.819710, -0.804850, 0.096600, 0.106260, 1.000810, 
0.718230, 0.098310, -0.304690, -0.182970, -0.194150, -0.214420, 0.048770, -0.767520, 0.323250, -0.021220, 
0.941400, 0.686680, 0.330850, 0.767930, -0.598690, 0.293870, -0.110990, 0.169960, -0.163300, -0.406280, 
0.839870, 0.220240, -0.314040, -0.220280, 0.803520, 0.280610, 0.230950, -0.397980, -0.606500, 0.578850, 
-0.539900, -0.261780, 0.373520, 0.236920, 0.156210, 0.321320, 0.727920, -0.652000, 0.691400, -0.345810, 
-0.445290, -0.790290, 0.385530, -1.066240, 0.350740, 0.180570, 0.361290, 0.814380, -0.363320, 0.301380, 
0.366270, -0.019460, 0.599380, -0.559600, 0.365030, -0.460410, -0.336640, 0.290320, 0.745990, 1.103780, 
-0.575760, 0.997410, 0.372730, -0.887140, 0.425720, 0.186850, -0.445380, 0.098410, 0.556990, -0.204750, 
-1.311870, -0.447650, -0.267820, -0.323800, 0.970790, 0.168330, -0.090980, 0.638630, 0.639960, 0.714310, 
0.514060, 0.073670, -0.297070, -0.483570, -0.753010, -1.003670, -0.047130, -1.449890, -1.061540, -1.026300, 
0.372340, 1.279510, 0.661630, 0.154120, 1.021860, 0.142380, 0.641080, 1.037270, -2.422420, -0.272270, 
-1.040830, -0.682560, 0.145710, 1.356500, 0.282020, -1.170830, 0.183540, -0.301350, -0.910420, 0.268840, 
-1.103200, 0.166220, 0.160380, 0.755510, -0.508610, -1.600010, -0.180980, 1.100230, -1.110630, 0.577490, 
-0.798880, 0.595660, -0.155960, -0.019440, -1.718870, 0.304950, -0.237230, 0.930600, -0.053130, 0.416920, 
-0.425750, 0.177810, -0.836800, -1.053820, -0.383110, -0.923440, 0.942070, 0.387890, -0.239800, -0.426910, 
0.037450, 0.563190, -1.608170, 0.142880, 1.068400, 0.577350, 0.239630, -0.405970, -0.051560, 0.626760, 
0.816260, -0.477320, -0.220140, -0.373760, -0.336290, 0.514130, 0.767990, 0.216170, 0.800950, -0.314440, 
0.556870, 0.928020, -0.028970, -0.065240, -0.531940, -1.167930, -0.355730, 0.728770, 0.370310, 0.665180, 
-0.957140, 1.407770, -0.592860, 0.423340, -0.435940, -0.351960, -0.248190, 0.709730, 0.315660, -0.903900, 
-0.745490, 0.122120, 1.008940, 0.189020, -0.046580, -0.296410, -0.065480, -0.592390, -0.561490, 0.079930, 
0.648260, -0.334030, 0.542200, -0.023530, -0.220750, 0.390940, -0.013040, -0.232580, -0.220780, -0.700530, 
1.407700, -0.752200, -0.336110, -0.144740, 0.619630, -0.355790, 0.592310, 1.056450, 0.890550, -0.307770, 
0.540550, -1.396850, -0.522690, 0.322070, -0.809320, -0.051440, 0.302010, -0.055450, 0.039590, -0.805420, 
-0.655110, 0.237940, 0.307590, -0.812430, -0.640270, 0.278430, 1.026770, 0.421810, 1.190020, 0.225710, 
-0.092830, 0.677810, -0.700440, -0.621590, 0.664440, 0.360790, 0.611450, -0.072230, 0.394200, -0.382040, 
-0.180190, 0.440170, 0.549650, -0.233940, -0.365440, 0.272300, 0.392250, -0.098810, -0.767450, -1.041140, 
0.468750, -0.537510, -1.112270, -0.465130, -0.116950, -0.656010, -0.046480, 0.068170, -0.225450, -0.425160, 
0.179790, 0.891510, -0.455410, -0.775920, 0.041820, -0.656400, -0.297950, 0.272080, -0.806990, -0.530730, 
-0.800350, 0.305630, -1.098250, -0.724160, 0.368040, 0.607310, 0.973430, -0.113750, 0.034140, 
0.286320, -0.004630, -0.390450, 0.492240, -0.479720, 0.427580, 0.695080, 0.270890, 1.018860, -1.263460, 
-0.404710, 0.043410, -0.116950, 0.452010, -0.056660, -0.225320, -0.848880, 0.554200, 0.662730, 0.237160, 
1.145080, 0.518070, 0.429650, -0.072580, -0.041240, -0.977930, -0.874970, -0.170620, 1.217360, 0.300350, 
-0.738160, -0.843300, 0.655410, -0.644830, 1.054200, 0.645280, -0.924840, -0.528720, -1.062180, 0.149330, 
0.039140, -1.391350, 0.360290, 1.838790, 0.159520, 0.425340, -0.596250, -0.049650, 0.449250, -1.093400, 
-0.175780, -0.053290, 0.159930, 0.012030, -1.209900, -0.059810, 1.202860, 0.799850, -0.507970, 0.505210, 
-0.052560, 0.105480, -1.776530, 0.057660, -0.254690, -0.256320, -0.000210, 0.168590, -0.466270, -0.383240, 
0.530450, -0.385820, 0.155400, 0.271680, 0.632770, 0.294060, 0.852940, -1.380940, -0.011430, 0.767410, 
-0.305130, -0.011990, -0.053980, -0.685280, 0.115650, 1.041590, 0.683570, -1.589580, -0.868580, 0.800530, 
-1.325660, 1.032010, -0.709920, -0.031270, -0.626200, -0.894740, 0.284790, -0.888200, 0.366660, 0.814200, 
-0.114570, -0.632700, -0.638400, 0.359470, -0.126000, -0.038540, 0.137070, -0.637190, 0.033050, 0.528090, 
-1.679230, -0.439580, 0.944040, 0.794330, 0.686940, -0.791470, -1.283820, 0.233790, -0.439790, -0.338100, 
0.486430, -0.462740, -0.359480, -0.397860, -1.601230, 1.813230, 0.509620, 0.554270, 0.383960, 0.388400, 
0.403970, -0.465970, -2.288540, -0.241520, 0.025630, -2.579770, -0.885490, 0.663200, -0.423480, -0.108540, 
-0.988190, 1.220720, 0.036130, 0.591520, -0.101120, -0.503160, -0.468870, 0.806280, -0.193090, 0.230490, 
0.429390, 1.412870, 0.467200, -0.881010, -0.105940, 0.002530, 0.304280, 0.059820, 0.877780, -1.085330, 
1.082020, -0.298660, -1.251030, -0.365130, 1.234690, 0.865260, 0.546800, -0.005960, 0.123480, 0.442030, 
0.674970, 0.244570, -0.112090, 0.145350, 0.217950, -0.084660, 0.117230, 0.178390, -0.503820, 0.227070, 
0.012490, -0.480670, 0.843770, -0.621530, -0.789450, -0.751180, 0.298150, 0.111630, -0.250440, -0.420600, 
0.366130, -0.046740, -0.064680, 0.021400, -0.555460, -0.157310, 0.056330, 0.958690, 0.321750, 0.481950, 
0.132540, -1.123660, -0.672290, -0.374810, 1.094100, -0.876490, 0.408660, 0.728040, 0.412600, 0.630120, 
0.117620, 0.430990, 0.392460, 0.958690, 0.846650, -1.134750, -1.393980, -0.456510, -0.165910, 0.794330, 
-0.028150, -0.686800, -0.856620, 0.693740, -0.420880, -0.265570, -0.131700, -0.351110, -0.997330, 0.442970, 
-0.959480, -0.356640, -0.686920, -0.437640, -0.745210, 0.146170, 0.315550, 0.533340, 0.366770, 0.347650, 
-0.871040, -0.036980, 0.668110, 0.408650, -1.134740, -0.822590, 0.128920, 0.380620, -0.390630, -0.794060, 
1.076320, -0.753680, 0.451740, 0.728490, 1.339360, -0.284240, -0.928150, -0.704790, 0.353550, 0.997180, 
2.483560, 0.674480, 0.467200, 0.059170, -0.437100, -0.366970, 0.107380, 0.764140, 0.845490, 0.785700, 
0.042080, -0.055520, -0.676980, 0.861500, 0.537020, -0.211150, 0.389810, -0.391730, 0.515010, 0.220100, 
-0.512480, -0.087060, -0.118940, 0.527420, 0.404030, 0.074760, -0.145800, -0.049170, 1.085710, -0.020860, 
-0.131230, -0.864430, -0.183680, -0.448070, -0.766070, -0.237720, 0.005940, 0.261740, 0.050310, 
-0.767980, -0.115960, 0.038320, -0.159640, -0.800300, -0.716500, -0.431170, 0.866850, 0.092780, -0.191350, 
0.380050, 0.379120, -0.462160, -0.102310, 1.070550, -0.410720, 0.560970, -0.083790, -0.440690, -0.277060, 
-0.065880, -0.656880, 0.116390, -0.064660, 1.128310, -0.835540, -0.856510, 0.632670, -0.492770, 0.387700, 
0.831720, 1.576390, 0.478450, -0.457520, -0.347220, -0.498140, 0.193120, 1.036230, 0.453910, -0.088940, 
0.228670, 0.661920, 0.917800, -0.591170, -0.008150, 0.038480, -0.297360, -0.624300, 0.537960, -0.198930, 
0.522620, -0.269350, 0.102970, 0.203410, -0.457880, -0.389460, -0.004620, 0.995000, 0.318620, -0.458300, 
-0.480990, 0.625370, -0.462410, -0.850460, -0.709750, 0.242880, -0.285830, -0.503460, -0.770580, 0.320070, 
-0.682680, -0.184730, -0.581420, 0.973680, 0.516940, 0.124550, 0.536130, 0.844130, 0.492560, -0.056320, 
-0.150600, -0.077710, -0.104070, 0.713720, 0.180520, -0.985570, -1.078520, -0.901980, 0.061080, 1.938600, 
0.452190, -0.040550, -0.519810, 0.291360, -0.710540, 0.493560, -0.404520, -0.064950, -0.477960, 1.329660, 
-0.406520, -0.711260, 0.791450, -1.249880, 0.581910, -1.286200, 1.232220, -0.275470, 0.478730, 0.650100, 
0.715790, 0.443120, 0.575800, 0.037770, 1.296690, -0.747230, -0.142280, -1.320250, 1.098060, -0.285010, 
-0.099900, -0.053480, 0.671940, -1.461310, -1.829870, -0.150030, 0.556340, -1.432210, -0.686500, -0.299320, 
-0.118310, 1.092850, -0.196730, -0.977460, 0.066080, 0.356070, 0.850100, 0.097700, 0.399450, -0.127070, 
0.344620, -0.652940, 0.463620, -0.874900, -0.495470, -0.137530, -1.014740, -0.419610, 1.260990, -0.050140, 
0.465650, -0.620740, 0.851430, 0.848060, -0.202980, 0.502040, -0.198570, -0.290910, -0.327730, 0.087860, 
0.255640, -0.085520, -0.430910, 0.009970, -1.004380, -0.455550, -0.070990, -0.282720, 0.080770, -0.444940, 
1.227000, -0.084460, 1.062280, -0.894320, -0.641890, 0.650490, -0.073890, -0.677820, -0.118110, 0.261960, 
1.130000, -0.486330, 0.120270, -0.456890, -0.042720, -1.402770, -0.604280, -0.496430, 0.612700, -1.401710, 
-0.216980, 0.169800, 0.668640, -0.699840, 0.943060, -0.870760, -0.771940, -0.950300, -0.333600, 0.439460, 
0.656970, 0.324150, 0.601430, -0.751930, -0.931250, -0.516840, 0.660290, 0.116030, -0.315550, 0.560380, 
0.412430, 0.701910, -0.777460, -0.373450, -0.515510, 0.826200, -0.378680, 0.632470, 0.197940, 0.234970, 
0.456190, 0.404800, 0.244140, 1.113930, -0.005690, -0.458370, 0.522320, -0.507070, 0.584260, -0.447030, 
1.254640, -0.417660, -0.950030, -0.407070, 0.241900, 0.161890, -0.605250, 0.106620, -0.131100, -0.912200, 
0.039290, 0.207570, 0.725880, -0.432150, 0.014420, 0.326960, 1.192910, -0.169920, -0.721530, 0.406680, 
0.471540, 0.434310, -0.456110, -0.893210, -0.672900, -0.522720, -1.645740, 0.135020, -0.528660, 0.493280, 
-0.981230, -0.416030, -1.123470, 0.149430, -0.218130, -0.171980, 0.569610, 0.667480, 0.218550, -0.379410, 
0.772630, 0.430530, 0.053820, 1.112710, 0.447110, -0.148660, 0.113750, 0.328210, -0.096940, 0.029660, 
0.170720, -0.812470, 0.025770, -0.592550, -0.673220, -0.110630, -1.215580, -0.556910, -0.148910, -0.421420, 
-0.020300, -0.272160, 0.002610, -1.033010, -0.416100, 0.194960, 0.436500, -0.420220, -0.860020, 
0.670850, 0.834970, 0.479480, 1.009120, 0.438630, -1.256620, -0.611680, 0.507170, -0.082280, -1.851010, 
-0.229490, -0.140830, 0.243940, 0.425170, 0.982790, 0.906910, -0.414410, -0.465460, 0.091060, 1.921990, 
-0.594380, -0.118840, -0.416120, -0.764780, -0.066400, -0.027980, -0.896060, 0.512520, -0.109330, 1.397300, 
0.220750, -0.766710, 0.654470, 0.292720, 0.137120, 1.145600, 0.385850, -0.330950, 0.268270, -0.099480, 
-0.203490, 0.351550, -0.516040, -1.217890, -0.590310, -0.432940, 0.152790, 0.577420, 1.264180, -0.688560, 
1.326190, -0.876700, 0.841260, -0.192980, 0.543720, 0.232880, -0.101280, -0.276000, 0.286770, -0.545210, 
-1.434170, 1.044510, -0.179210, 0.073280, -0.267690, 0.526230, 1.044970, -0.140640, -0.282900, 0.150050, 
0.589380, 0.528300, 0.133680, -0.025760, 0.430240, -0.904970, 1.340550, 0.638720, -0.174570, 0.651960, 
-0.878540, 0.741250, 0.872100, 0.719000, -0.894620, -0.771560, 0.908200, 0.486740, -0.026290, -0.519730, 
-0.172620, -0.357330, 1.382200, -0.282850, -0.943540, -1.177740, 0.062310, 0.289900, 0.052210, 0.467630, 
0.651310, -0.821180, -0.505240, 0.506830, -0.065190, -1.116280, 0.369940, 0.044660, 0.417290, -0.311940, 
-0.295930, 1.422270, -1.540680, 0.055230, -0.115660, 0.718030, 0.879130, 0.052200, 0.593220, 0.163050, 
1.226770, -0.545760, 0.615990, 1.168430, 0.625920, 0.629800, 0.063570, 1.186470, 0.944550, 0.697790, 
0.270700, 0.512610, 0.035180, 0.752950, 1.095560, 1.975100, 0.231800, 0.258270, -0.360960, -0.310900, 
0.686350, 0.269690, -0.346480, -0.357490, -0.342640, -0.202970, 0.503790, 0.195270, -0.908310, 0.617580, 
0.300700, 1.103610, 0.024300, 0.367530, -0.495590, 0.489260, 0.635620, 0.488060, -1.263070, 0.319100, 
-0.462460, 0.044030, 0.637470, -0.161990, 1.742290, -0.451510, -0.612190, -0.013400, -0.969140, 0.464350, 
0.168940, 1.104430, -0.265930, 0.535470, -0.945840, -0.563180, 0.101910, -0.075480, -0.829330, 0.502510, 
-0.358800, -1.302200, 0.680520, 0.472110, 0.719330, 0.085390, 0.922260, -1.189090, 0.499600, -0.433380, 
-0.691490, 0.212800, 0.527770, -0.020860, 0.440370, 0.286980, 0.140360, 0.502350, 0.255880, 0.225650, 
-0.173410, 0.535100, -0.415390, -0.346460, -0.462220, 1.456940, 0.496330, -0.348120, 0.165730, -0.023180, 
-0.046830, -0.348770, 0.393210, 0.582080, 0.628620, 0.205140, 1.297030, 0.050770, 0.610230, 0.478300, 
-0.370400, -1.279900, 0.529430, 0.605890, 0.561570, -0.116370, -1.365720, -0.774160, 0.028760, -0.348870, 
0.045220, 0.762350, 0.590430, -0.125150, 0.203170, 1.203660, 0.926480, 0.449150, -1.281650, 0.309740, 
-0.819600, -0.155270, 0.140460, -0.996160, -0.674850, 1.117170, -0.964760, -0.185530, 0.105520, -0.370890, 
-0.597520, -0.013100, -0.901720, -0.625570, 0.939830, -0.147610, -0.711120, 0.070250, 0.451310, -0.815750, 
-0.681880, 0.228950, 0.451530, 0.715120, 0.075250, -0.507990, 0.801940, 1.150140, 0.283400, -0.044040, 
-0.472430, 0.063070, -0.355040, -1.409880, 0.057300, -0.371970, -0.320830, -0.180260, -0.546170, -0.828770, 
0.370290, -0.629210, 0.231880, 0.832590, 0.785080, 0.609150, -0.498030, 0.847390, -0.624420, -0.919550, 
0.371440, 1.306620, 0.730280, -0.127460, 0.504070, -0.398810, 0.047650, 0.393380, -0.023040, 
1.370780, 0.896130, 0.594370, -0.027430, 0.863010, 1.016120, 0.507860, 0.461940, -0.958940, 0.559070, 
-0.140810, -1.169730, 0.937230, -0.508090, 0.252290, -0.396690, -0.271340, -0.248470, 0.563630, -0.069990, 
0.525280, 0.436000, -0.236150, 0.655650, 0.877780, 1.281060, 0.538760, -0.896390, 1.069020, -0.855600, 
-0.713260, 0.370610, 1.148540, 0.721860, 0.210770, -0.722760, -0.363560, 0.041300, -0.399370, -1.489950, 
-1.020060, -0.488370, -0.314470, -0.655610, 0.121570, 0.369070, -0.532340, -0.575970, -0.699000, 0.915270, 
0.718650, -0.562100, 0.326070, 0.614850, 0.319390, -0.434640, -0.183720, 0.591780, 0.197160, -0.419250, 
0.641340, -1.069120, 1.306180, 0.613940, 0.563310, -0.519920, -0.093090, -0.459900, -0.045910, 0.405740, 
0.879010, 0.829520, 0.056560, -0.382570, -0.058760, 0.391680, -0.272280, -0.721260, -0.297820, -1.222050, 
-0.674100, -0.192200, 0.968870, -0.325190, 1.177830, -0.368920, -0.368380, -0.277650, 0.932460, -1.258160, 
0.532810, -0.712760, 0.064890, -0.595010, 0.269170, -0.160770, -0.449010, -0.102120, -0.172210, -0.644940, 
0.357880, -0.001010, 0.629910, 0.978990, -0.005540, -0.440410, -0.929610, -0.836020, -0.360410, 0.350690, 
-0.034240, 0.754640, -0.580910, 0.850540, 0.619940, -0.041100, -1.019250, 1.685800, -0.804450, 1.216380, 
0.354960, 0.062880, 0.448110, 1.338730, 0.893430, -0.597760, 0.003500, 1.077820, 0.295440, 0.209250, 
1.429560, -0.549630, 0.354750, 0.646540, 0.610560, 0.822430, -0.875670, 0.160000, 0.716300, 0.197230, 
-0.877630, 0.941810, -0.019590, -0.412070, 0.107190, 0.672870, 0.504380, 0.530890, 0.556450, -0.390120, 
-0.949680, -0.237830, 0.894900, 1.054820, 0.615720, -1.403290, 0.389520, 0.197560, -1.867700, 0.803100, 
0.416450, -0.188340, -0.645490, 1.286770, -0.330070, 0.652080, 0.578440, -0.998590, 0.853210, 0.287610, 
-0.137870, 0.880010, -0.451920, 1.659850, 1.099840, 0.732690, -0.589990, -0.528180, 0.133860, 1.131490, 
0.028680, -0.717490, -0.559800, 0.242410, 0.558540, 0.411180, -0.685330, -1.031190, 0.075850, 0.708570, 
-0.048120, -0.027470, -0.195030, 0.125660, 0.269210, -0.261120, -0.143780, -0.775850, 0.545090, 0.234780, 
-0.870970, 0.034130, -0.308960, -0.277420, -1.044220, 0.493960, -1.240810, 1.048290, -0.063550, -0.219290, 
0.018880, 0.451890, 0.276800, 0.276710, 0.233300, 0.221900, 0.522560, 0.492300, -0.976350, 0.898400, 
0.568970, 0.745280, -0.373490, 0.860860, 0.398890, -0.751260, 1.236120, 0.929370, -0.888220, 0.109310, 
1.027870, 1.069080, -0.157480, -1.647830, 1.006160, 1.322230, 0.180170, -0.570480, 1.185280, -0.042190, 
0.203000, -0.518170, 1.205180, -0.032040, -0.581090, 0.482840, 0.444530, 1.245080, -0.912890, 1.112970, 
-0.506780, 0.428300, -1.034550, -0.832980, 0.187310, -0.091760, -0.236020, -0.110980, 0.672400, -0.560900, 
-0.360250, -0.103410, 1.123110, -0.122730, -0.171800, -0.154660, -0.363820, -0.734060, -0.355950, -0.174550, 
-0.254590, 0.485660, -0.130280, 0.205790, 1.125170, -0.001250, 0.091800, 0.672100, -0.468660, -0.599240, 
-0.371480, 0.268930, -0.606300, -0.813400, 0.921750, 0.843970, 0.534270, -0.022630, -1.095360, 0.382140, 
0.114750, -1.101560, 0.494030, -0.240050, 0.769470, -0.477360, -0.025270, 0.538030, -0.265820, 
-0.544740, 1.230390, 1.439640, 1.328710, -0.591840, -0.819130, -0.390190, 0.050210, 0.608140, 0.396550, 
0.799570, 0.117000, -0.926670, 0.419730, 0.406830, -1.321450, -0.637410, 0.263950, -0.156560, -0.432690, 
0.182110, -0.226850, 0.348850, 0.746990, -0.551560, -0.234050, 0.679820, 0.238100, -0.641510, -1.389510, 
-1.690270, 0.798730, -0.764510, 0.248250, -0.747440, 0.862820, 0.038790, -0.220280, -0.464690, 0.459530, 
-0.382220, -1.051670, 0.828760, 0.660720, 0.255130, 0.333570, -0.453060, 0.281400, 0.363320, -1.111270, 
-0.172600, -0.356790, 0.521340, -0.618980, -0.873820, 0.652890, 0.163320, -0.523370, -0.705340, 0.341610, 
-0.159570, 0.060390, 0.465280, 0.444950, -1.343850, -0.189670, -0.659260, 1.088840, 1.413280, 1.085510, 
0.392310, -0.309390, -0.440780, -1.036990, 0.212110, 0.324090, 0.324810, -0.302860, 0.421370, 1.051140, 
0.527570, -0.496110, -1.263980, -0.259300, -0.743600, -0.511770, 0.444330, 0.290500, -0.482260, -0.803770, 
0.370400, 0.418580, -0.062430, 0.445810, 0.087810, -0.018220, 0.375780, 0.041800, 0.612930, 0.159510, 
-0.174690, -0.299890, -0.175500, 0.761050, -0.375430, -0.381930, 0.128330, -0.739740, -0.150580, 0.790420, 
-0.922280, 0.052160, 0.393290, -0.784850, -1.007120, 0.709750, 1.453500, -1.135670, 0.437380, 0.578190, 
1.071030, -0.947570, -0.322700, -0.297450, 0.117060, 0.162100, 0.723820, 0.776420, 0.379800, -0.278490, 
-0.153940, 1.035280, 1.458910, -1.243310, -0.751030, 1.841240, -0.686580, 0.065290, 0.997370, 0.693780, 
0.102830, -1.483850, -1.285210, 1.109240, -0.928200, 0.088170, 0.221550, -0.488890, 0.125960, -1.176690, 
1.019560, -0.005860, 1.256740, -0.186270, 0.048070, 0.044580, 0.446560, -0.375300, 0.761670, 0.236570, 
-0.238220, -0.246100, 0.234840, 0.622000, -1.075510, 0.127130, -0.146990, -0.152740, -0.082960, 0.591110, 
1.543140, -0.545180, -0.410790, 0.630330, -0.965730, -0.106340, -0.759630, -0.196750, 0.717090, 0.608430, 
-0.635190, -0.276130, -1.122380, 0.381940, -0.859450, -0.458560, -0.891340, 0.137730, 0.118640, 0.884370, 
-0.321870, -0.155830, 0.346320, -0.113810, 0.023600, 0.291870, -0.940290, -0.966480, -0.390360, -0.077560, 
-0.037780, 1.460750, -0.411580, 0.451110, 0.546770, 0.551940, -0.495330, -0.447790, -0.361810, 1.050170, 
0.506100, -0.592070, 0.048790, -0.184230, 0.788850, 1.013100, -0.035050, -1.027730, -0.499700, 0.348570, 
0.901870, 0.665490, -0.280780, 0.451720, 0.903070, -0.198260, -0.364370, -0.241430, 0.861620, -0.694790, 
-0.198350, -0.258320, -0.259530, -0.634460, -0.806140, 0.249400, -0.878640, 0.066940, 0.532700, -0.610990, 
-0.714680, 1.265510, -0.405850, -0.548720, -0.964260, -0.044550, 0.533980, -0.275240, 0.430250, -0.918250, 
0.194790, 0.214190, -0.246240, 0.201780, 0.239280, 0.826650, 0.145970, -0.160140, -0.451130, -0.660310, 
-0.809340, -0.193730, -0.678370, 0.795500, -0.371350, -0.386900, -0.725770, 0.434160, 0.266590, -0.064360, 
0.961000, 1.328590, 0.171640, -1.065680, -0.076210, -0.981120, 0.314980, -0.062720, -0.991040, -0.424720, 
-0.824560, 0.827750, 0.177970, 0.144100, -0.596090, 0.100820, 0.221030, 0.501930, -0.151520, -0.347430, 
-0.368800, -0.042970, 0.301400, 0.763930, -0.381560, 0.319040, 0.737930, -0.147950, 0.069960, 
0.531220, -0.748350, 0.213420, -0.664450, -0.294450, 0.437500, 0.500500, -0.106100, -0.149610, 0.831710, 
-0.573970, -0.033220, 0.311060, -0.643180, -0.446080, -0.087100, -0.616610, -0.512670, 0.005920, -0.060240, 
-0.664570, -0.478130, 0.098690, 0.974450, -0.565860, 0.017560, -0.493230, 0.012490, 0.161500, -0.371160, 
-0.983370, -0.000670, 0.222600, -0.118210, 0.570320, -0.149160, 0.740090, -0.578290, 0.063080, 0.619650, 
0.348170, 1.056990, -0.367480, 0.544180, 0.268770, -0.385900, 0.290170, -0.074860, 0.607720, 0.048070, 
-0.146940, -0.106240, -0.053550, 0.233710, 0.442190, 1.545980, -0.387080, -0.245110, 0.506680, 0.236670, 
-0.799770, 0.223180, -0.468380, 0.389660, 0.334110, 0.040970, -0.821900, 0.114160, 1.170110, -0.061040, 
0.068440, 0.605030, 0.039570, 0.046810, 0.233880, -0.764380, 0.555140, 0.444980, -0.351070, 0.265350, 
-0.781080, -0.146050, -0.220400, -0.582190, 0.600930, -0.080540, -1.232940, -0.184500, -1.139230, -0.716110, 
0.126610, 0.450320, -0.972140, 0.112120, 0.564930, -0.344080, 0.495300, -0.631970, -0.434670, 0.169610, 
0.264120, -1.252700, -0.205140, -0.559610, -0.594670, 0.343310, 0.502120, -0.816540, 0.286670, -0.268850, 
0.900030, -0.202850, -0.472550, -0.283580, -0.133490, 0.157280, 0.478600, 0.121440, -1.198380, 1.453700, 
-0.706170, -0.767390, -0.428610, 1.233520, 2.050420, -1.244550, -0.808290, -0.020150, 1.378890, 0.017270, 
-0.233440, 1.005360, 2.886090, -0.383360, -1.112380, 4.760450, 2.119120, -0.248370, -1.115570, -0.324070, 
-1.288920, -0.235870, 0.903810, 0.532310, -0.052280, -0.377660, -0.096400, 1.647140, -0.362050, -0.483790, 
-0.013440, -0.409830, 0.361160, -0.307230, 1.117720, -0.109560, -0.872040, -0.186800, 0.059240, -0.504900, 
-1.022200, -0.220480, -0.240740, -0.145210, -1.726250, -0.280700, 0.013660, -0.056940, 0.889770, 0.333960, 
-0.827620, 0.503280, -0.084580, 0.001170, -0.047280, 0.253210, 0.142800, 0.027190, 0.152070, -1.352520, 
-0.729610, -0.048560, 1.345510, -0.698650, 0.304920, 0.578900, 0.069920, -0.790270, -0.926350, -0.087270, 
-0.369300, 0.241960, -1.068920, 0.414340, -0.063980, -0.454940, -0.622150, -1.053590, 0.438490, -0.967990, 
-0.171140, -0.722430, -0.251350, 0.150080, 0.235000, 0.574840, -1.042610, 0.235990, 0.044530, 0.636340, 
-0.716530, 0.240600, 0.165840, 0.212870, 0.130940, 0.281360, 0.085240, -1.291600, -0.793920, 1.017300, 
0.073130, 0.030950, 0.926800, 0.173440, -0.264750, 0.100000, 0.116680, -0.111240, 0.218600, 0.352710, 
0.234930, 0.184370, -0.044990, -0.565690, -0.129750, 1.004680, 0.619680, -0.736050, -0.254790, 1.158070, 
-0.429070, 0.062130, -0.379350, 0.219250, -0.864450, 0.176180, 0.118240, 0.185380, 0.544630, 0.371880, 
-0.950540, -0.029570, 0.165750, -0.002360, 0.116110, 0.333480, 0.552410, 0.222030, 0.253570, 2.367030, 
-0.130960, -0.416380, -0.405640, -0.834480, 0.931710, -0.040340, -0.209560, 0.438830, 0.199080, -0.893060, 
-1.143190, 0.503450, -1.041340, -0.119380, 1.104960, -0.032620, -0.539790, -0.157130, 0.057830, -0.160480, 
0.000970, 0.683220, 0.453020, -0.073620, -0.021850, -1.410210, 0.076120, 0.114980, 0.345380, -0.210100, 
0.085890, -0.072560, -0.538360, -0.243630, -0.140390, 0.712780, -0.021800, -0.356950, 0.958240, 
0.059950, -0.471120, 0.148710, -0.098870, -1.067220, 0.111440, 0.062260, -0.239090, -0.110690, -0.370370, 
-0.141670, 0.938570, -0.525160, 0.884800, -0.071600, -0.056910, -0.441500, 1.057000, 0.685870, -0.389730, 
-0.916140, 0.185720, -0.949980, -0.362920, -0.249570, 0.549450, -0.847700, -0.870790, 0.796490, -0.244430, 
-0.073600, -0.424640, -0.438390, 0.152770, 0.171340, 0.011330, -0.577200, 0.505380, 0.189970, -0.388670, 
0.927070, 1.054900, -0.940240, 0.332310, -0.496680, -0.407290, 0.895910, -0.093350, 0.036470, 0.396100, 
-0.373060, 0.381480, -0.553680, -0.439160, -0.542010, -0.976690, -0.167410, 0.644440, -0.092000, 0.153740, 
-1.207800, 0.043330, -1.012910, 0.261210, 0.082460, 0.757400, -0.476140, -0.039140, -1.001710, -0.001230, 
-0.731010, 0.290000, -1.285390, 0.199400, 0.451360, 0.259920, 0.414280, -0.811970, -0.431590, -0.626170, 
-0.508190, -0.166390, -1.118310, 0.297760, -0.639510, -1.539790, -0.098410, 0.141490, 0.106950, -1.750180, 
0.741710, -0.081510, -0.429100, 0.691200, -1.028610, 0.316960, -0.638670, 0.326560, -0.309170, 0.519210, 
-0.143260, 0.493310, -0.435720, -0.428810, 0.242450, -0.141780, 0.953680, -0.756280, 0.348060, -0.324000, 
-0.382020, 0.264020, -0.097160, -0.390320, -0.700700, 0.405030, 0.426010, -0.308370, -1.942670, 0.690410, 
0.140530, -0.977410, -0.207340, 1.498150, 1.203730, -1.502500, 0.793160, 0.158200, 0.331600, 0.028810, 
0.532610, -0.452920, 2.131990, -0.804440, -0.548150, 4.614670, 2.639140, -1.077970, 1.129120, 0.154180, 
0.589980, 0.344980, 0.956370, 0.057810, -0.275850, 0.214970, -0.320900, -0.697620, 0.013600, 0.794130, 
-0.003690, 0.696780, -0.061790, -0.328410, 0.414190, -0.751780, -0.036640, 0.135120, -0.621150, 0.091710, 
-1.302950, -0.795550, 0.599350, -0.425990, -0.586340, -1.007050, 0.060400, -0.758710, 1.452600, -0.072200, 
-0.111970, 0.609520, -0.512170, -0.649670, -0.122320, -0.041320, 0.850740, -0.779850, 0.705260, -1.149470, 
-0.581740, 0.766300, 0.957200, -0.653880, -0.497150, 0.383050, -0.123100, 0.457000, 0.915610, -0.259730, 
-0.515880, 0.104430, 0.490220, -0.631760, 0.179020, 0.018420, 0.134480, -0.784990, -0.060860, 0.114890, 
0.297790, 0.726340, -0.894860, 0.464840, -0.775270, 0.001650, -0.009570, 0.113930, 0.895420, -0.470620, 
0.437300, 0.590930, 0.696710, 0.008630, -0.494460, 0.679150, -0.168720, -0.274420, 0.518420, 0.470970, 
-1.111140, -0.040890, -1.338090, -0.767190, -0.609480, -0.653790, -0.163710, 0.972210, 1.032530, -0.578490, 
-0.670170, -0.209370, -0.645100, 0.069650, 0.271070, -0.000460, -0.281320, -0.119050, -0.560070, -0.310070, 
-0.091020, 0.117010, -0.139660, -0.171680, 0.437170, 0.065620, -0.694510, -0.101940, 0.078170, -0.202370, 
-1.418640, -0.639250, -1.590120, -0.685670, -0.122820, 0.706970, -0.410060, 0.215300, 0.375210, -0.345390, 
0.087460, -1.119740, -0.822870, -0.280640, -1.008710, 0.275370, 0.034670, -0.794050, -0.114980, -0.200040, 
0.335490, 0.444650, 0.808040, 0.253240, -0.377850, 1.342520, -0.429660, 0.139340, -0.498030, -0.991470, 
0.184560, -0.044580, 1.466260, -0.009820, -0.219010, -1.022300, -0.347070, -0.494760, -0.668130, 1.200590, 
0.587160, -1.934230, -0.577310, 0.448470, 0.595020, -0.260620, 0.590410, 0.343330, 0.307380, 
0.227160, -0.330070, -0.419180, 0.075980, 0.032910, -0.241950, -1.186590, 1.340180, -1.245670, 0.330800, 
-0.306160, 0.235330, -0.135330, 0.640630, -0.308560, 0.083110, 0.510940, 0.976380, -0.662810, 0.982090, 
-0.280880, -0.086110, -0.544870, -0.223720, -0.738700, -0.310970, 0.199400, -0.229610, -0.560420, 0.237390, 
0.290800, -1.027980, 0.662610, -0.036750, -0.165400, 0.925130, 1.053260, -0.084540, 1.154350, 0.350630, 
-1.289670, -0.282840, -0.222520, -0.082620, 0.646700, -0.151660, -0.353020, 0.516430, 0.239470, 0.258490, 
0.253680, -0.056920, -0.275330, -0.824490, 0.809870, 0.895240, 0.058040, -0.651950, 0.351920, -0.763570, 
-0.087390, 0.259830, 0.194200, -0.592410, -0.204840, 0.344230, -1.396320, -0.884420, 0.107620, 1.180910, 
-1.083700, -0.595110, 1.137980, 0.550610, 0.260910, -0.816710, -0.351780, -0.336240, -0.243000, -0.675330, 
0.942260, -0.508110, 0.674510, 0.095760, -0.415360, 0.250760, -1.274230, 0.164070, 0.542570, -1.239390, 
-0.288350, 0.440910, 0.136460, -0.808280, -0.498850, 0.742310, -0.373250, 0.441280, -0.088160, 0.138640, 
-1.031520, -0.107510, 0.129680, -0.897430, -0.072740, 0.862460, -0.255180, -0.296590, 0.467470, -1.081380, 
0.617280, 0.003610, -0.677040, 1.659060, 1.309430, -0.226530, -0.947550, 0.942960, -0.843960, 0.836780, 
0.362580, 0.845490, 1.078830, 0.138810, -0.182560, 1.155370, 0.561980, 0.433060, -0.128720, 0.059320, 
-0.507230, 0.603100, -1.517180, -0.710730, -0.176120, -1.028720, -0.103050, 0.415020, 0.051610, 1.159690, 
-0.931980, 0.703230, -0.519010, -1.213360, -0.116770, 0.274060, -0.626670, -1.238560, 0.260750, -0.957760, 
-0.476330, -0.851370, -0.156770, 0.438990, -1.477960, 0.082150, -0.498530, 0.910150, -1.544350, 0.659290, 
0.716990, 0.402190, 0.872630, 1.036760, 0.897770, -0.292540, 0.247320, 0.392660, 0.437840, 0.371690, 
0.300160, 0.288310, 0.766840, 0.662930, 0.423840, 0.086700, 0.951660, -0.585200, 1.072880, -0.814720, 
0.784540, -0.460300, 0.376920, -0.047330, 1.226430, -0.174830, -0.174410, -1.037120, 0.582610, -0.515010, 
-0.071140, 1.063090, -0.986080, -0.916730, -0.271300, 1.250370, 0.393310, 0.390850, -0.443020, -0.545400, 
0.202680, -0.752990, 0.073920, -0.127500, -0.543530, -0.288370, 0.187530, 0.933600, 0.650270, 0.838500, 
-0.151180, 0.481270, -0.136470, -0.071840, 0.654600, -0.721020, 1.270190, -0.636750, 0.680640, 0.335570, 
-0.081230, -1.259370, 0.768210, -0.118820, 0.142810, -0.541210, 0.032310, -0.302560, 0.100830, 0.085350, 
-0.446990, 0.158790, -0.098220, -0.669200, 0.541300, -0.772260, -0.902110, 0.644470, 0.770640, 0.293990, 
-0.424860, 1.226650, 0.806300, 0.460400, -0.411420, 1.063790, 0.963260, -1.158200, 1.134880, 0.860830, 
1.232400, -0.262770, -1.484520, 0.803170, -0.051130, 0.980810, 0.167840, -0.117210, -0.190500, -0.625700, 
1.043690, -0.210860, -0.538410, -0.227830, -1.041880, -0.041920, -0.041920, 0.978020, 0.461290, -0.751980, 
0.480600, -0.260030, 1.180990, 1.049890, -0.088830, 0.452040, 0.106290, -0.370830, 0.063430, -0.808570, 
-0.231490, 0.877250, -0.654850, -0.566830, 0.194820, -0.383170, 0.541150, -0.252590, 0.562480, 1.145430, 
0.667770, 0.848030, 0.612180, -0.375820, -0.907550, 1.363150, -0.656980, 0.742640, 0.428680, 
0.232250, -0.446030, -0.481610, -0.092850, -0.359340, 0.493450, 1.234210, -1.539320, -0.241970, 1.491190, 
0.186730, 0.113990, 0.074410, 0.538770, -0.402670, -1.005280, 0.583700, -0.421640, 1.844220, -0.907210, 
0.282640, 0.621580, 0.517760, 0.456460, -0.229060, -0.147010, -0.512530, -0.102240, 0.211400, -0.636480, 
0.008760, -0.620930, 0.489060, 0.535310, 0.494780, -0.440500, 0.007970, -0.015910, 0.069440, 0.078740, 
-0.141880, 0.783420, 0.210400, 0.359590, 0.899100, 0.802300, 0.499570, -0.879030, 0.805670, -0.530760, 
0.198590, 0.653760, 0.132630, 0.189460, -0.294030, 0.593370, -0.584270, -0.145040, -1.020570, -0.680430, 
-0.589910, -0.279930, -1.194420, -0.322490, 0.047440, -0.721750, -0.605520, -0.624360, 0.227250, 0.846170, 
0.876770, 0.417380, 0.641000, -0.062730, -0.671210, 0.347900, 0.260180, -0.635900, -0.145160, -0.675750, 
-0.240760, 1.081650, -0.718710, 0.022790, -0.292350, -1.016230, -0.127780, 0.475370, 0.314380, -1.122820, 
-0.055320, -1.256880, -0.183750, 0.018990, -0.350230, 0.526870, -0.602360, -0.316480, -0.286860, 0.547740, 
0.804540, 0.867840, 0.142610, -0.029180, 0.847330, 0.530010, -0.192050, -0.383580, 0.793340, -1.414640, 
0.836290, 0.379900, 0.640900, -0.971180, -0.282280, 1.252650, -0.377360, 0.358780, -0.925750, 1.426230, 
0.647830, -0.618350, 1.081620, -0.488320, 1.192640, 0.917130, 1.165390, -0.566480, 1.085240, 0.325210, 
0.050600, -1.085200, 0.933970, -0.160940, -0.049720, 2.191640, 1.531610, 0.373910, -0.602870, 0.696440, 
0.519210, -0.618010, 0.102010, 0.181960, 0.429270, -0.920680, 0.702740, 0.552980, -0.520140, 0.274300, 
-0.444220, -0.562900, -0.830630, -0.552200, -1.006500, 1.398750, 0.961380, -0.017390, 0.417420, -0.081910, 
-0.339400, -0.156070, -0.204790, 0.009200, 1.342330, 0.397320, 0.341660, 0.161540, 0.976500, -0.384590, 
0.198450, -0.542560, -0.245190, -0.687560, -0.449710, -0.513230, -0.059250, -0.932820, 1.130950, 0.201380, 
1.360170, -1.157290, -0.904760, -0.412800, -0.008100, -1.259750, -0.142810, -0.757410, 0.449420, -0.443710, 
-0.155000, -0.555440, -1.310940, 0.437670, 0.118270, 1.130730, -0.312990, 0.119440, 0.154220, -0.621190, 
-0.580980, 0.059660, 0.069460, -0.836330, -0.407030, -0.931010, 0.473650, -0.890820, 1.172480, 0.791270, 
-0.454800, 0.797490, -0.700350, -0.587910, -0.637450, -1.023310, 0.050920, 0.947520, -0.444680, 0.902680, 
-0.504200, 0.152790, -0.300730, -0.108870, -0.092780, -0.296970, -0.908840, 0.752040, 0.439560, -0.185300, 
0.710650, -1.051290, 0.389750, 0.424630, -0.755450, 0.364200, 0.360410, -0.158820, 0.179300, 0.106040, 
1.258020, -0.073650, -0.599540, -1.111180, -0.975430, 0.008840, 0.444000, 0.824090, 0.030490, 0.459630, 
-0.939260, -0.031420, 1.171950, 0.530370, -0.631060, 0.245260, 0.520470, -0.386600, 0.346270, 0.375220, 
-0.696030, 0.360130, -1.305180, 0.597630, -0.963820, -0.134960, 0.624800, 0.089050, 0.600190, 0.718120, 
0.402300, -0.335570, 0.562020, 0.679240, 1.114800, 0.883210, 0.840030, 0.536650, 0.078890, -0.654770, 
-0.671490, 0.249830, -1.030710, -0.282070, 0.324890, 0.298390, -0.148350, -0.808190, -0.077210, -0.089110, 
-0.017070, -0.391000, 0.350070, -0.299480, 0.742400, 0.541520, -0.660740, 0.650860, -0.016610, 
-0.017090, 0.433970, 0.867430, 0.893370, -0.589110, -0.688190, 0.331920, -0.216310, -0.524300, 0.925140, 
0.075970, 0.191330, 0.235290, 0.887960, 1.552510, -0.107490, 1.396480, 0.259580, 0.048550, 0.664480, 
0.785770, 0.494650, 0.304600, 0.380480, -0.718940, 0.794830, 0.882230, -0.228540, 1.253450, 0.494260, 
-0.126650, -0.877900, 0.153960, 0.870870, 0.410100, 0.011360, 0.652390, -0.532310, -0.977720, -0.773740, 
0.254870, -0.166160, -0.860500, -0.342930, 0.165660, 0.294440, -0.502530, -0.754360, -0.852780, -0.880160, 
0.275340, 0.351980, 0.658750, -0.310480, 0.832750, -0.367390, 0.193480, -0.267500, 0.519890, 0.196830, 
-0.871140, 0.948230, 0.829130, -0.000640, -0.181380, -0.032370, -0.258820, 0.274840, -0.194670, -0.247620, 
0.884240, 0.575550, -0.228200, -0.478660, -0.555610, -1.078250, 0.603200, 1.276330, 1.097550, -0.278130, 
0.352120, 0.729220, -0.100250, 0.552970, -0.349680, -0.407140, -0.260980, -0.564770, -0.646710, 0.012500, 
0.074490, -0.179860, 0.688390, 0.939330, 0.749480, -0.663320, 0.463140, 0.189220, 1.295410, -1.107560, 
1.513560, 0.795750, -0.551010, 0.319720, -0.523090, -0.514100, -0.816320, 1.446550, 0.406930, -0.562080, 
1.038530, -0.425690, 0.603440, -0.538920, -0.756420, -2.187000, -0.056310, 0.550690, 0.724650, 0.066600, 
-0.760180, 0.497470, -0.546640, -1.778530, -0.409930, 0.691790, 1.000010, 0.231430, -1.495180, 0.782400, 
0.218470, 1.202860, -0.145080, 0.295520, -0.112360, -0.492710, -0.709760, 1.711180, 0.937290, 0.161170, 
0.868690, 0.531460, 0.521330, -0.189960, 0.219310, 0.118680, -0.557690, -0.620520, -0.339080, 0.411330, 
0.496160, 0.227850, 0.646670, 1.068670, 0.263490, 0.927520, 0.105280, -0.840710, -1.022070, 0.248740, 
-0.221010, 0.440120, -0.693370, 0.806890, 0.876310, -0.858360, -0.702360, 0.556860, 0.732880, 0.512390, 
0.218620, -0.685950, -0.500340, -0.013410, -0.158690, 0.348470, -0.270370, -0.244450, 0.745400, -0.648430, 
-0.532780, 0.611470, 0.893080, 0.702930, 0.270260, 1.248750, -0.266770, -0.347250, -1.090900, 0.435040, 
-0.556550, 0.399080, -0.157840, -0.391240, 0.175680, -0.698690, 1.139170, -0.766250, 1.089880, -1.016690, 
0.536370, -0.282290, -0.554950, 0.866430, -1.014240, 1.126310, -0.651360, 0.426130, -0.866390, 1.086520, 
1.148740, -0.503080, -0.949610, 0.021200, -0.509490, 0.027480, -0.490540, 0.432890, -0.703320, -0.181550, 
-0.785170, 0.569840, 0.354590, 0.484130, -0.940800, 0.468220, 0.127610, -0.313800, 0.255660, 0.708710, 
0.027220, 0.104980, 0.897770, 1.515500, 0.426100, 0.895550, 0.108340, 0.069960, -0.644870, -0.516210, 
-0.203600, 0.423620, -0.558620, -0.008030, -0.080630, -0.283640, 0.000480, -0.627790, -1.165410, 0.738810, 
-0.589680, 0.332370, -0.395510, -0.789520, 0.452750, 0.661480, -0.315000, -1.069600, -0.048750, -0.553100, 
-0.879490, -0.576120, 0.270060, 0.815650, -0.608070, 0.517960, -0.972060, -0.594000, -0.667550, -0.190270, 
-0.362480, 0.461180, -0.217990, -0.089870, 1.018020, -0.516250, -0.768530, 0.276160, -0.593560, -0.865680, 
0.505530, -0.901630, -0.250260, -0.737890, -0.283330, -0.896070, -0.690220, -0.792030, -0.330110, 0.839630, 
0.349880, -0.697030, -0.113250, -0.680530, -0.136790, 0.053100, 0.240070, -0.805310, 0.886290, 
0.549300, 0.155280, 0.887500, 0.953070, -0.455910, 0.069480, 0.114010, -0.039860, 1.202480, 0.046310, 
0.291360, 0.088330, -0.176520, -0.229300, 0.354910, -1.264410, 1.002440, -0.179750, 0.203280, 0.197800, 
-1.249790, 0.007980, -0.399080, 0.304220, 0.986600, -0.459510, 0.534020, 0.745300, -0.083250, 1.551400, 
-0.118310, -0.570050, 1.583680, 0.072610, -0.165810, -0.527370, 1.368380, -0.187530, -0.477420, 0.877690, 
0.107590, -0.063250, 0.656660, -1.107600, -0.060520, -0.238620, 0.102060, -0.531300, -0.244170, 0.431820, 
-0.238910, 0.113790, -0.008300, -0.106040, 0.285640, -0.085850, 0.044560, 0.299580, -0.262540, 1.092890, 
1.729910, 0.438970, 0.697050, -0.859390, -0.529930, -0.814350, -0.634650, 0.133780, 0.537320, -0.371590, 
0.513820, -0.151880, 0.381940, -0.385600, -0.668920, -0.111890, 0.653200, 0.878240, -0.366350, 0.137600, 
1.232620, -0.059230, -0.214320, 0.473610, -0.096150, 0.965420, 0.198170, -0.541720, -0.085450, -0.256440, 
-0.249030, 0.045240, 0.478020, -0.225660, -0.385630, 1.327710, -0.591680, 0.525980, 0.905140, 0.142850, 
-1.290210, -0.046400, 0.652110, 0.921670, 0.246230, 0.060160, -0.148310, 0.853810, -0.841900, 0.274260, 
0.528750, -0.754090, -0.970720, 0.082190, 0.420750, 2.125110, -0.138960, 0.468520, -1.536930, 0.831980, 
0.353330, -0.855930, -0.250890, 0.322940, 1.110880, 0.410520, -1.848430, -0.565310, 0.954110, 1.004240, 
-0.941880, -1.061810, 0.761360, -0.179620, -0.238430, 3.134130, 1.388360, -0.613310, 1.136000, 0.618040, 
1.335660, -0.122300, 0.835430, 0.515790, 0.039010, 0.395250, -0.207170, -0.900620, 0.113990, -0.408670, 
-0.095880, 0.213390, 0.213700, 0.235060, -1.202880, 0.697440, 0.090490, -0.114220, 0.299880, 0.235790, 
-1.239310, 0.815450, -0.086220, 0.437030, -0.868940, -0.748050, 0.233370, 0.276480, -0.114160, 0.191440, 
-0.443190, -0.581400, 0.909520, 0.265060, 0.682170, 0.693380, -0.340730, -0.105920, -0.233150, -0.164670, 
-1.213710, -0.440710, -0.274680, -0.174930, 1.127340, 0.647580, 0.656730, -0.851650, -0.337650, 0.768110, 
-0.820550, 0.836600, 0.684860, 0.292280, 0.451120, -0.181200, 1.020640, 0.152840, 0.552030, 0.245400, 
1.250730, 1.355380, 0.471660, -0.403960, -0.964090, 0.164940, -0.865410, -0.116020, -0.681120, 0.027340, 
-1.222840, 1.538560, 0.090740, 0.478130, -0.540850, 1.076040, 0.089260, 0.504590, -1.164070, 0.094760, 
-0.396090, 0.309070, -0.773430, 0.124250, 0.382520, -0.061780, 0.219610, -0.478040, -1.205860, 0.105020, 
-1.225440, 0.105630, 0.096310, 1.108260, -0.556890, -0.102070, 0.451400, 0.369110, 0.657400, 0.854230, 
0.164340, -0.921740, 0.354590, 0.008760, 0.515240, 0.150090, -0.283820, 0.176750, 0.811950, 0.446970, 
-0.467070, -0.825890, 0.687330, 0.861200, -0.077370, -1.500370, -0.466340, -0.747890, 0.595220, -1.106010, 
-0.057720, -0.070090, -0.225130, -0.296590, 0.042410, 1.233300, -1.041740, 0.651750, 1.033720, -0.224240, 
-0.381250, -0.175820, 0.323270, -0.090540, -0.411490, 0.278180, 1.194530, -1.032150, 0.398980, 0.510050, 
1.184920, 0.726690, -0.600220, 0.056120, -0.077680, 0.107320, 0.439560, 0.086680, -0.121670, 0.526910, 
0.183860, -0.443050, -0.228190, -0.241730, -0.675180, 0.723800, 0.028930, -1.169850, 0.778440, 
0.304680, -0.624130, -0.438740, -0.836300, 0.349760, 0.004690, 1.240360, -0.424980, 0.495350, -1.100610, 
-0.564020, -0.539770, -1.065110, -0.831470, -0.744960, 0.333710, 0.790250, 0.822190, -0.611610, -0.268980, 
0.224720, -0.450520, 0.911140, -0.431020, -0.067910, 0.299970, -0.497320, 0.186270, -0.089510, -1.145310, 
0.275880, -0.314960, -0.570590, 1.276960, -0.496890, -0.457210, 0.135500, 1.100970, 0.041440, -0.351880, 
-1.698670, 0.089290, -0.754620, 0.970180, -1.012200, 0.690850, 1.597080, 0.696340, -0.680330, 0.415080, 
0.070500, 0.177300, -0.211770, -0.221160, 0.927170, -0.226790, -0.496460, 1.435500, -0.486260, -1.172770, 
-0.316560, -0.889950, -0.249500, -0.787300, -0.332530, -0.307680, 0.718850, -0.322600, 0.715020, 0.515850, 
-0.081850, 0.253760, 0.640340, -1.115930, 0.508870, 0.175500, -0.032910, -0.695050, -0.428960, 1.596510, 
-0.027250, -0.633610, -0.918160, -0.472650, -0.218150, 0.909690, -0.342570, -0.866960, 0.166550, 0.889800, 
0.429220, -0.493770, 0.818910, -0.452970, -0.074150, 1.221840, -0.616440, 1.270690, -0.023330, -0.179340, 
0.754890, -0.997830, -0.894150, 0.860570, -0.433570, -0.471150, 0.197910, -0.732930, 1.364010, -1.453270, 
-1.200040, -0.631620, -0.262850, 0.444060, 1.434870, 0.134100, -0.884970, -1.239390, 1.103590, 0.678800, 
0.200600, 0.372050, -0.548170, 0.605750, -2.038810, 1.335300, 0.958630, 0.031470, -0.074650, 0.044460, 
2.205720, 1.361880, -0.573040, 1.135910, 0.265290, -2.380420, -1.255270, 1.055800, -0.567490, -0.494750, 
0.781190, 0.076350, 0.456480, 0.236770, -0.142070, 1.349640, 0.474520, -0.993340, -0.159990, -0.151230, 
0.000580, -0.343400, 0.062270, 0.782000, -0.589650, -0.398550, -0.900080, 0.570440, 0.690830, -0.186690, 
1.692680, 0.430800, -0.054180, -0.633200, 0.389100, 0.265720, -0.295070, 0.931670, 0.074020, 0.648700, 
0.958250, 1.755880, -0.393060, 0.419990, -0.723140, 0.627850, 0.070360, 0.279570, 0.245360, -1.186340, 
-0.284370, -0.266070, 0.332510, 1.503750, -0.192170, -0.328450, 0.885840, -0.025750, 0.576110, -1.022910, 
-0.649770, -0.867540, -0.113030, 0.040390, 0.254450, 0.118620, -0.764990, -0.284190, 0.520950, 1.348460, 
0.274280, -0.452780, 0.166130, -0.762270, 0.661620, 1.178790, 0.398350, -0.357240, -0.731440, -0.615180, 
-0.121610, 0.230750, 0.322390, 0.480900, -0.459140, 0.806080, 0.199000, 0.111130, -0.302600, 0.746260, 
0.032910, -0.504390, 1.158370, -0.075080, -0.154920, 0.102020, 0.440380, -0.259590, 0.849530, -0.458690, 
-0.479040, 0.396430, -0.195870, -0.869000, -0.306360, -0.684230, -0.638010, -0.499240, -0.583310, -0.205040, 
-0.042350, -0.842420, -0.435310, -1.253280, 0.131790, 0.258860, -1.100170, -0.503410, -0.364460, -0.277520, 
1.402880, -0.067930, 1.337530, -0.725800, -0.455320, -0.075630, 0.350760, 0.357240, -0.306180, 0.435060, 
0.025280, -0.456070, 0.560130, 0.611990, -1.262490, 1.216950, 0.346460, 0.622970, 0.874030, -0.928600, 
0.089490, 0.453850, 0.458600, -0.017750, 0.375310, -0.271960, 0.720690, 0.012820, 0.567240, -0.346420, 
-0.028780, 0.437200, 0.428200, -0.371550, -0.326210, 0.007680, -0.355230, 1.235200, -0.714500, 0.621230, 
0.447580, -0.182570, -0.347270, -0.062680, 0.346140, 0.439750, -0.876480, 1.099850, -0.230400, 
-1.152760, -0.814960, -0.770190, 0.566260, 0.249890, 0.370070, 0.514060, 0.363340, -0.052350, -0.497020, 
-0.522260, 0.095250, 0.448470, -0.510030, 0.245330, -0.251300, -0.213600, -0.393160, 1.078670, 0.310290, 
-1.098860, -0.135350, -0.765750, -1.808470, 0.079220, 0.254390, 1.238640, 0.159130, 1.128660, 0.287250, 
1.621880, -0.351670, 0.461620, 0.608140, -0.392740, 0.069440, 0.557660, 1.027990, -0.938400, -0.567690, 
-0.431870, -0.120910, 0.515210, -0.582570, -0.478070, 0.151410, -0.611920, -0.587670, -0.772260, 0.645180, 
-0.133310, 0.184810, -0.601100, -0.005260, -0.535040, 0.671520, -0.742910, 0.611930, 0.701750, -0.128130, 
0.007100, 0.103980, 1.336700, -0.393300, 0.228830, 0.637800, 0.517540, 0.250660, -0.397040, -0.000160, 
-0.188140, -0.101390, 0.570120, -0.486090, -0.371210, -0.599730, 0.685230, -0.863140, -0.129250, 1.196300, 
-0.102130, -0.747340, -0.118960, 0.816710, -0.656680, 0.537490, 0.208260, 0.262980, -0.118590, 0.557310, 
-1.298370, 0.031220, -0.562160, 1.192590, -0.697360, 0.458840, 0.261120, -0.203010, 0.276330, -0.088990, 
-0.691620, -0.810020, 0.055290, 0.343190, -0.153350, -0.097680, -0.377100, -0.629780, 0.438990, -0.396360, 
-1.476540, 0.164310, 1.021040, -0.334230, 0.161220, -0.037940, 1.001320, 0.258940, -2.010680, 1.585370, 
-0.734580, -1.140990, 0.781180, 0.755360, 0.114130, 0.873980, -0.072890, -0.073280, 1.495390, 0.904940, 
1.291970, 0.439250, 1.155120, -0.004580, 0.167520, -0.168640, -0.242360, 0.524570, -0.324800, 0.119730, 
0.195060, -1.190140, -1.239640, 0.170510, -0.265240, -0.496560, 1.080780, -0.883820, -0.775690, 0.231210, 
-1.087710, 0.320840, 0.738020, 0.127810, 0.038600, -0.030660, -0.946420, -0.746160, -0.019190, -0.398730, 
-0.428970, -1.095950, 0.451670, -0.277270, -1.267570, -1.483630, 0.180900, 0.264180, -1.067750, -0.784540, 
-0.434530, 0.287770, -0.382440, 0.257450, -1.237660, 0.511590, -0.542190, 0.329060, 0.223470, -0.455510, 
0.467430, 0.499550, 0.615270, -0.258610, 0.285670, 0.150200, 0.367690, 0.843400, -1.037030, 0.517260, 
0.896520, 0.684470, -0.931950, -0.998740, 1.321900, 0.160370, -0.703680, -0.088420, -0.891800, -0.019880, 
-0.889650, -0.203590, -0.132700, -0.199290, 0.268590, 0.045380, 0.643360, 0.318300, -0.968700, 1.080860, 
-0.124160, -0.001850, -1.003010, -0.196780, -0.078640, 0.318010, 0.767190, 0.564470, 0.685560, -0.761730, 
-0.098860, 0.622390, 0.753230, 0.333630, -0.062230, -1.231980, 0.396020, -0.386660, -0.669020, 1.045790, 
-0.992400, -0.068390, 1.378600, -1.180530, -0.280650, 0.143610, -0.990480, 0.694080, -0.272210, -0.085410, 
0.746820, 0.473240, 0.227000, -0.278380, 0.876810, -1.129580, -1.524800, -0.335710, -0.138560, 0.244060, 
0.118540, -1.059670, 0.230820, -0.374050, -0.842340, 1.427860, -0.898950, -1.052110, -0.241280, 0.374940, 
1.050470, 0.138490, -0.947040, -1.277410, 1.022650, -0.182170, 0.370430, -0.022660, -0.712010, 0.509600, 
-0.371460, 0.845380, 1.031190, -0.485230, -0.188800, -0.405290, -0.678880, -0.794630, 0.518860, 0.124910, 
-0.498830, -0.548310, -0.328760, 0.230780, 1.110650, 0.666620, 1.371030, 1.073260, -0.155350, 0.756990, 
0.707050, 0.387730, 0.858870, 0.669780, 0.167350, 0.302640, -0.543760, 0.409430, -0.065080, 
0.992060, 0.560190, -0.426540, 0.227400, 0.415580, -0.244560, -0.121960, -1.154600, -0.868890, -0.408360, 
0.194750, -0.095200, -0.014640, 0.313430, 0.238190, -0.163070, -0.767920, 0.596520, 0.006310, -0.208780, 
-0.538720, -0.853960, -0.974440, 1.232320, 0.297280, -0.405130, 0.015460, 0.166640, 0.503140, 0.479100, 
-0.887420, 0.135980, 0.400270, 0.683100, -0.445290, -0.537240, -0.539410, -0.020890, 0.552990, 0.200960, 
-0.127000, -0.136010, 0.475050, -0.616560, -0.626230, -0.571790, 0.367360, -0.783210, -1.547230, 0.957050, 
-0.879340, 0.126220, -0.153420, 0.571620, -0.484820, 0.028790, 0.029310, 0.196000, -0.227290, -0.525840, 
1.452010, -0.219100, -0.802710, 1.041000, -0.968110, -0.250750, -0.869240, 0.837040, 0.727650, 1.370860, 
1.413680, 0.813090, 1.273830, -0.280980, -0.382220, -1.020190, -1.332480, 0.279170, 0.595700, -0.364720, 
0.464520, 0.205380, 0.193130, -0.514200, -0.770030, 1.133190, -0.888650, -1.235410, -0.600170, -0.984810, 
-0.907780, -0.858180, 0.398180, 0.578370, 0.449760, -0.430760, 0.959400, 1.240660, -0.179810, -0.720310, 
-0.902850, -0.150080, -0.525600, -0.950390, -0.274810, 0.256370, -0.488860, -0.957760, 0.309750, -0.197580, 
-0.512240, -0.932420, -0.101300, -1.253300, -0.249600, -1.275270, 0.980070, -0.072680, 0.881500, -0.488850, 
1.141490, -0.586160, -0.095610, 0.384300, 1.637870, 0.578140, -0.640090, 0.337340, 0.519920, -0.496860, 
-0.554620, -0.774270, 0.266130, -0.173510, 0.933980, 1.171730, -0.809220, -0.072480, -0.037730, -1.061700, 
0.001870, -0.037790, 0.899430, 0.296170, 0.511640, -0.242700, -0.961630, 0.647910, 0.302750, -1.131270, 
0.301230, 0.702670, -0.035780, 0.746420, -0.732730, 1.013520, -0.379180, 0.398540, -0.430490, 0.345680, 
-0.056920, -0.315480, 0.823230, 0.130600, 0.719810, 0.812880, 0.405460, 0.633850, 1.011470, -0.604040, 
-0.001390, 0.011580, 0.709520, 0.429110, 1.164070, -1.127570, 1.199760, 0.112910, -0.585180, -1.393390, 
0.168390, -0.434900, -0.758810, -0.047440, -0.611930, 0.245230, -0.813740, -0.873640, 0.807570, -0.993270, 
0.056390, 0.768090, -0.310520, -0.427680, -0.896460, 1.009970, 0.756100, 1.178250, 0.158930, 0.344790, 
1.057940, 0.682840, -0.929690, -0.521270, -0.751030, -0.361460, 0.585240, 0.769120, -0.726720, 0.053230, 
0.103240, 0.628990, 0.915680, -0.388800, 0.329250, -0.643430, -0.745700, -1.641160, -0.365800, 0.600070, 
-0.243410, 0.267420, -1.579110, -0.415580, -0.584630, -0.537180, 0.382230, -0.902150, -0.421910, -0.052370, 
-0.448370, -0.670240, -0.060980, -0.086280, -0.675520, -0.952080, 0.669360, 0.869160, 0.158490, 1.318510, 
0.596680, -0.252590, 0.897430, -1.070450, -1.010220, 0.724820, 0.353180, 0.947540, 0.790610, -0.471330, 
-0.169980, -0.399960, -0.510930, 0.345290, 0.921220, 0.433810, 0.317900, 0.046820, 0.679430, -1.066530, 
-0.970460, -0.722860, -1.141710, -0.087560, 0.361320, 0.022440, -0.636890, 0.596160, -0.232290, 0.477780, 
0.607630, 0.444810, -0.663170, 0.584200, 0.002080, 0.473840, -0.577250, 0.139300, 1.191660, 0.901890, 
0.546950, 0.493680, -0.564240, 0.384830, 0.042740, 0.646870, -0.107350, 0.724580, -0.177250, 0.183150, 
-0.360030, -0.221300, 0.090200, -0.985070, -0.360410, 0.282090, 0.161500, -0.541210, 0.072210, 
0.878920, -0.142920, -0.665110, 0.295400, -0.504280, -0.058640, 0.088460, -0.836190, -0.555950, -0.061020, 
-0.315160, -0.243020, -0.695580, 0.665700, -0.013600, -1.002970, -0.851500, -0.496360, -0.116900, -0.059830, 
1.345020, 1.188190, 0.062330, 0.477390, -0.556500, 0.709370, 0.185770, -0.497180, -0.222610, -0.192020, 
0.557320, 0.451190, -0.303280, -0.561850, -0.098340, 0.638090, 0.041870, 0.235720, -0.423300, 0.338580, 
-1.281310, 1.129040, 0.425190, 0.643740, 0.514140, -0.446430, -0.319900, -0.338620, -1.062630, 0.361070, 
0.585470, 0.466260, -0.491360, -0.559920, -0.634170, -0.332690, -1.076780, 0.387680, -1.064190, -0.425730, 
-0.001160, 0.480550, -0.372220, -0.221040, -0.837800, 0.310760, 1.635080, 0.821660, -0.534780, 0.077400, 
1.668870, 0.271480, 1.473260, -0.113600, -1.034650, 0.156050, -0.325430, -0.787840, 0.263990, 0.443980, 
-0.955840, 0.103220, 0.837050, -0.330170, 0.277770, -0.763990, 0.213970, 0.150210, 0.922490, -0.681120, 
0.282110, 1.470090, 1.000890, -0.648310, -0.607410, 0.243990, -0.436380, -0.040410, -0.100650, 0.847470, 
0.229160, -0.046310, 0.060960, -0.229650, -0.151820, 0.923970, 0.406830, 0.263680, -0.784800, -0.432030, 
0.140200, 0.681580, 0.926080, 1.089330, 0.984510, -0.548320, -0.685280, -0.884100, 1.728950, -2.125550, 
-0.331640, 0.963300, -0.609770, 0.459250, -1.811340, 0.434050, 0.266730, -0.086540, 0.886160, -0.053210, 
-0.845090, -0.406340, -2.285340, 0.612060, 1.184460, -3.623660, -1.519810, 2.020210, 0.461440, 0.097310, 
-0.220280, -0.453320, -1.223530, 0.851480, -0.322830, 0.167780, -0.523080, -0.810580, -0.138000, -0.122610, 
-0.091190, 0.002680, -1.132280, -0.000350, 0.635170, -0.040740, -0.608740, 0.274210, 0.228530, -0.504160, 
0.492820, -0.329650, -0.778880, 0.243490, 0.051150, -0.937220, -0.535070, 0.126240, 0.131150, -0.383530, 
-0.478590, 0.156760, -0.887470, 0.057500, 0.835040, -0.312720, 0.684040, -0.278340, 0.493100, -0.330900, 
-0.176880, 0.496970, -0.073800, 1.651050, -0.125590, 0.292690, 0.019500, -0.832090, -1.309670, -0.525340, 
-0.168530, 1.373250, 0.326280, -1.486210, -0.589130, -0.498280, 0.126110, -0.549400, 0.246840, 0.644940, 
-0.002460, 0.945310, 0.198210, 0.021600, -0.248040, 0.137970, -0.581320, 0.858310, -0.001510, -0.188550, 
0.418030, 0.682460, -0.807210, -0.753250, -0.347000, -0.713650, 0.645700, -0.511960, 0.024630, -0.384510, 
0.196300, -0.096170, -0.068990, -0.345340, -0.826430, 0.276500, 0.537570, 0.746530, 0.694500, 0.238660, 
0.273560, -0.927430, -0.021440, 0.344370, 0.050400, 0.576120, -0.258360, -1.005820, 0.229960, -0.761720, 
-0.659000, 0.807330, -0.290430, 0.289920, -0.120060, -0.053440, -0.438800, 0.652600, 0.513810, -0.357230, 
0.951910, 0.971310, -0.114770, 0.231470, 0.162590, -0.739890, -0.490150, -1.027530, 0.553980, 1.847030, 
-1.400140, 0.495320, 0.983120, 1.130350, -1.159800, 1.064200, -0.139420, 0.246410, -0.870350, -0.981680, 
-0.531780, -0.022150, 0.228470, 0.104930, 1.074080, -0.809070, 0.301810, 0.187410, -0.405830, 0.281760, 
-0.402090, -0.038320, 0.180800, -0.727040, 0.505270, -0.163990, 0.439280, -0.591270, 0.029310, -0.799170, 
1.107950, 0.558080, -0.649920, -0.051910, -0.220060, -0.022110, -0.142110, -0.306500, 0.153100, 
-1.186590, 0.125160, -0.071300, -1.309120, 0.862020, 0.376190, 1.147950, -0.487420, 0.056880, -0.102560, 
-0.042460, -1.045740, -0.243070, 0.500490, -0.600770, 0.126320, -0.102400, 0.645050, 0.622830, 0.759450, 
-0.791920, -0.277110, -0.378810, 0.043720, 0.095410, -1.465080, -0.634340, -0.311020, 0.073060, 0.999260, 
0.299320, -0.328190, 0.873260, 0.874960, -0.852160, 0.063950, -0.962050, -0.654100, -0.692020, 1.341760, 
-0.382350, 0.654560, -0.571680, 0.806780, -0.029770, 0.167110, -0.549130, 0.243900, 0.739620, -0.931870, 
-0.348570, -0.112220, 1.318210, 0.855010, 0.792370, 0.736150, 0.548710, 0.397670, -0.649690, 0.606660, 
-1.376270, -0.337410, -0.719610, -0.551290, -0.217580, 0.508330, 0.434880, 0.373290, -0.754860, 0.477660, 
-0.917550, -1.066380, 0.715440, -0.548880, -0.957500, -0.711650, 0.366290, -0.515710, -0.214660, 0.892040, 
0.837190, 0.285140, -0.647040, -1.110330, -0.318540, 0.083510, -1.351120, 0.976640, 1.043680, 0.235990, 
1.055570, -0.155120, -0.988800, -0.089360, -0.963010, 0.357220, -0.283420, 0.912680, -0.194570, 1.001460, 
0.986720, -1.349450, 0.318290, 0.296430, -0.072280, 0.617590, 0.495110, 0.210100, 0.228720, -0.148490, 
0.278930, 0.363340, 1.434710, 0.127770, -1.182880, 0.983600, 0.941740, -1.787900, 1.380530, 0.092830, 
-0.528680, 0.907860, -0.612930, -0.667760, 0.297030, 0.199480, 0.493950, -0.774410, -0.879750, -0.231290, 
-0.959480, 0.282250, 1.271830, 0.644820, -0.359440, 1.193120, 0.911620, -0.347500, 1.308570, -0.141150, 
0.732460, -0.641840, -0.361210, -0.004970, 1.010560, -1.088880, -0.353730, 0.348510, -0.143120, 0.690120, 
0.330150, -0.016810, -0.674320, 0.012500, 0.859090, 0.679860, -0.336820, -0.099510, 1.163390, 0.623750, 
-0.147660, 0.924270, 0.112020, -0.032890, 0.792100, 0.466750, -1.122950, -0.840480, 0.182990, -0.810450, 
0.016000, -0.049660, -0.972660, -0.129650, 0.328790, -0.994880, 0.718370, -0.827530, 0.687480, 1.038600, 
1.127790, -0.041180, 0.060850, -0.209490, -1.084880, -0.275050, -1.224970, -0.330860, -0.427290, 0.469190, 
-0.216780, 0.125250, -0.130940, -0.425840, -1.076210, -0.342650, 0.016550, -0.588710, -0.064870, 1.022960, 
-0.160990, 0.450870, 0.016350, -0.464950, -0.116380, 0.746880, 0.711620, -1.090300, -0.014850, -0.030230, 
-0.914190, -1.108000, 0.083590, 0.786950, -0.704970, 0.494980, 0.132140, -0.418830, 1.281860, -0.777680, 
-0.059410, -0.993630, -0.346270, 0.057580, -0.009510, -0.199960, 0.188340, 0.033210, -0.132190, -0.657330, 
-0.101510, 0.289970, -0.048960, -0.555620, -0.646920, -0.723480, -1.496470, -0.411040, -0.163440, 1.421460, 
0.347670, -1.102830, -0.931770, 1.516130, 0.306350, 0.441330, 0.167850, 0.344250, -0.187340, -0.260420, 
0.638930, 0.437920, -1.128550, 0.933640, 1.264640, -0.179720, 0.473950, 0.455250, -0.138700, -0.487700, 
0.758230, 0.420860, -0.777170, 0.524770, 0.497580, 0.250830, 1.014400, -0.693940, -0.295570, 0.062450, 
-0.259470, -0.360820, 0.127830, -0.272080, 0.511160, 0.262190, 1.199890, -0.206560, -0.933920, -0.661060, 
-0.803850, 0.263680, 0.137410, -0.302320, -0.092990, -1.179410, -0.384970, 0.791780, 0.632550, -0.695930, 
0.285100, 0.097480, -0.222090, 0.609910, 0.328270, -0.150790, 0.209600, -0.026410, -0.492660, 
-0.526080, -0.012830, 0.207520, 0.074970, -0.685430, -0.926710, -0.088190, 0.263260, 0.328220, 0.912680, 
-0.096320, 0.237570, -0.632260, -0.576320, 0.205240, -0.368630, -0.195400, 0.697910, -0.098830, -0.402000, 
-1.516180, -0.254870, 0.641830, -0.231240, -0.659020, -0.186440, -0.215690, 0.673100, 0.547000, 1.267820, 
-0.305650, 0.033620, 0.402970, -0.401710, -0.574250, 0.195890, -0.272590, 0.322780, -0.101320, 0.543360, 
0.191270, 0.356000, 0.005360, 0.333870, -1.226030, -1.045040, 0.183210, -0.559550, -0.131530, -0.774680, 
-0.483100, 0.626730, 0.160770, -0.146730, 0.818800, -0.627830, -0.673600, -0.760190, -0.594760, -0.794090, 
-0.132440, -0.528910, -1.796810, -0.707340, 0.405220, 0.456570, -1.057110, -0.124470, -0.271510, -0.530720, 
0.166540, 0.563760, 0.930650, 0.834800, 0.832080, -0.475130, -1.388340, -0.295950, 0.997990, -0.184430, 
0.025940, 0.276420, -0.056190, -0.170700, 0.154060, 0.401830, 0.119440, -0.527610, 0.853570, 0.196550, 
1.204820, -1.036570, 0.447590, -0.728490, 0.981520, 0.843230, -0.961970, 0.161090, -1.266750, -0.454940, 
0.547490, -0.507790, -0.192340, 0.253640, 0.346450, -0.395360, 0.580080, -1.156280, -0.096190, 0.272870, 
0.529420, -0.441450, -1.468360, -0.620360, -0.057120, 0.608270, 1.227390, 0.639300, -0.673220, 1.173060, 
-0.090220, -1.147220, 0.960890, 0.055290, 0.269020, 0.486950, -0.924660, 0.734680, -1.240670, 1.170460, 
0.937600, -0.057740, 1.425950, 0.828740, 0.567630, 0.473000, -0.651730, 0.578560, -0.740260, 0.344450, 
0.303330, 0.300790, -0.251370, -0.551680, -0.038070, -0.843540, -1.164890, 1.052470, -0.739050, -0.255500, 
0.487940, -0.370910, -1.096510, 0.025750, -0.173050, 0.905250, -1.017630, 0.285440, 0.244950, -0.028210, 
-0.069860, 0.502330, 0.766640, 0.697860, -0.869200, 0.304500, -0.019760, -0.795390, 0.120370, -0.185670, 
0.122940, -0.515290, 0.121620, -1.132370, -0.737400, 0.178820, -0.022680, 0.428070, 1.047870, -0.368980, 
-0.228350, -0.767940, 0.055970, -0.989550, 0.490520, 1.405850, 0.416630, -1.429840, -0.066240, 0.035670, 
-0.082420, 0.359810, -0.027940, -0.628800, -0.101330, -0.024240, 0.270090, 0.068440, -1.107780, -0.376660, 
-0.238760, 0.197590, -1.210110, -0.274140, 0.559030, 0.164060, -0.647700, 0.673750, 0.131750, 0.440250, 
-0.200180, -0.053750, 0.645150, -1.509530, -0.294980, -1.272150, 0.230130, 0.243000, -0.311870, -0.462260, 
-0.715680, 0.139880, -1.010410, 0.642920, 0.119410, 0.139220, -0.204320, 0.145930, 0.123170, 0.672420, 
0.779250, -1.001000, -0.086820, 1.304130, 0.136780, 1.054020, -0.623050, 0.172920, -0.171810, -0.454490, 
0.421770, 0.677290, -0.270350, 0.569050, -0.096060, 0.319260, -0.084050, -0.002780, 0.947790, -0.259700, 
0.040060, -0.772470, -0.636290, 0.599610, -1.450240, -0.237010, -0.336620, 0.080770, 0.312270, -1.045520, 
0.336450, -1.093220, 0.275190, -0.580340, 0.951350, 1.272290, 0.024630, 0.016230, -0.094850, 0.511180, 
-0.473200, -0.698370, -0.186620, -0.827870, -0.658660, -0.208640, -0.795120, 0.083330, 0.147650, -0.494560, 
0.898680, 0.482740, 0.464090, -0.370210, 0.444470, -1.190990, 0.475650, -0.276910, 0.457330, -0.991980, 
-0.643040, 0.679280, -0.365330, 0.731290, 0.568610, -0.753830, 0.778900, -0.467610, -0.076000, 
-0.733080, 1.636050, -0.451610, 0.109600, 0.803340, 0.289130, -0.440600, -0.611620, 0.263050, 0.364460, 
-0.019740, -0.647550, 0.500500, 1.081930, 0.821210, -1.485330, -0.180770, -0.238670, -0.166800, -1.417380, 
1.858560, -0.235200, 0.221840, 0.104920, -0.351750, 0.992330, -1.651360, -0.344910, 0.577560, -1.104430, 
0.431300, -0.079870, 0.484410, -0.487460, -0.579560, -0.651570, -1.020980, -0.547410, 0.111130, 0.630760, 
-1.034500, 0.082490, 0.379610, 0.799530, -0.312530, -0.336790, 0.685060, 0.176880, 0.735330, -1.056140, 
-0.255360, 0.535710, -0.660820, 0.485330, -0.509470, -0.493560, 0.762600, 0.296190, -0.761360, 0.157950, 

-1.515880, 0.074270, -0.305060, 0.372230, -1.594080, -0.053050, -0.452810, -1.043540, 0.182080, 0.420740, 
0.450800, -0.581220, -0.319680, 0.512370, 0.915520, -0.538290, -1.058330, -1.596380, -0.611140, 0.620140, 
1.016800, 0.508460, -0.336990, -0.952270, -2.024740, 0.205450, 0.964550, 0.325030, -1.451800, -1.580750, 
-0.112510, -0.736780, 0.624350, -0.843040, 1.218960, 0.457850, -0.157110, 0.176720, 0.071410, 0.708770, 
-0.071840, -0.410850, 0.549190, -1.127470, 0.179530, 0.037730, 0.667640, 0.478310, -0.147840, -0.352360, 
-0.026330, -0.569490, -0.780280, -0.438740, -0.637990, -0.332740, 0.151980, 0.616300, -0.804190, 0.246640, 

-0.517900, 0.906280, -0.320280, 0.480910, -0.442100, 0.164830, -0.796550, 0.729920, -0.542830, -1.349920, 
0.912830, -1.595400, -1.731250, 0.699500, -1.414510, -0.683770, 1.945610, -1.753540, -0.126680, -0.129720, 
0.542660, -1.240670, 0.536460, -0.198210, -0.046640, -0.689110, -0.267700, -0.486950, 1.769860, 0.783040, 
-0.022920, 0.546710, 0.638450, -0.001780, 0.435960, -0.322990, -0.081700, 0.373620, -0.570250, 0.363950, 
0.008570, -0.166100, -0.303970, -1.062230, 0.066510, 0.230070, 0.878770, -0.247010, 0.430090, -0.440850, 
-1.216960, 0.411730, -0.041270, -0.785020, -0.336560, -0.755970, -0.696260, 1.427190, -0.112020, 0.677090, 

-0.788800, -0.522800, 0.606470, -0.838060, 0.299130, 0.662760, 0.126100, -0.524000, 0.886610, 0.092910, 
-0.114500, 0.375880, -1.141460, 0.535800, -1.172570, -0.515960, -0.248440, -0.688860, -0.434980, -0.377960, 
-0.407070, 0.301240, 0.710970, -0.311390, 0.458540, -0.417160, 0.387460, 1.026800, -0.532610, -0.830280, 
-0.568380, -0.991990, 1.132720, 0.416540, -0.768680, 0.247250, -0.880120, -0.892390, -0.568370, -0.695370, 
-0.125030, -0.180000, -1.013590, 0.534820, 0.777490, -0.743290, -0.444130, 0.813120, -0.175200, 0.080220, 
0.248910, 0.403640, -0.940300, -0.290150, 0.431840, -0.534820, -0.557360, 0.137350, -0.975170, 0.081470, 

0.043400, 0.547950, -0.774990, -0.011300, -0.412020, -0.114340, -0.285210, -0.201240, -0.017040, -1.316110, 
-0.207960, 0.905330, 0.735330, 0.678360, -0.082580, -0.043860, -0.565560, -0.795890, -0.007720, -0.244450, 
0.068040, -0.418470, 0.113760, -0.635250, 0.278290, 0.419420, -0.630290, 0.279720, 0.191190, -1.901340, 
0.480310, 0.791660, 0.580090, 0.475060, 0.500130, 0.081480, 0.230620, -1.212430, -0.171330, -0.154640, 
-0.036880, -0.690200, -0.106810, 0.169000, 0.476270, -1.272710, 0.211960, -0.802020, 0.491800, 0.451930, 
0.446480, 0.078560, 0.470790, -1.016890, -0.673950, 0.683420, -0.334060, -0.303630, -1.033590, 0.634050, 

-0.611120, -0.546210, 0.537600, -1.010030, 0.195670, -0.102270, -0.212640, 0.458180, 0.918940, -1.068720, 
-0.126610, 0.217320, -0.552510, -0.074390, 0.621700, -0.757140, -0.971660, -1.122530, -0.221450, -1.208760, 
0.340560, 0.579880, 0.556540, 0.121520, 0.720760, 0.213270, -1.372850, 0.563510, -0.846220, 0.236900, 
-0.489250, -0.895720, -0.946150, 0.548700, 0.576970, 0.319530, 0.585660, -0.417750, 0.241730, -0.984970, 
0.464950, 0.577540, 0.768560, -0.454940, -0.027070, -1.456010, 0.295550, 0.799080, -0.812210, -0.806960, 
1.101490, -0.512390, -0.692610, -0.172640, -1.316410, -0.719880, -0.828470, -1.005840, 0.077200, -0.152200, 

-0.870410, -1.065890, 2.142430, 0.415600, 0.272540, 0.689790, 0.232180, -0.322180, -0.131530, 1.461270, 
-1.044110, 0.182760, 0.077060, -0.573340, -0.435090, 0.539980, -0.361120, 0.581440, 0.010910, -0.020170, 
-0.335650, -0.641650, 0.351070, 0.522110, -1.097030, 0.275390, 0.644180, 0.148010, -0.347090, -1.922630, 
-0.245620, -0.561240, -0.578840, -0.234150, -0.499130, -0.260520, -0.765470, 0.999460, -0.491460, -0.636680, 
0.319530, 0.646420, 0.466430, 0.285160, 1.052920, -1.337120, -0.278630, 0.015250, -0.262210, 0.716770, 
-0.518810, -0.434120, 0.282570, 0.011060, -0.256690, -0.681450, -0.869460, -0.174830, -1.285300, 0.387750, 

-0.487970, -1.287270, 1.198750, 0.917790, 0.894730, -0.555690, -2.406440, 0.308900, -0.720540, 1.408770, 
0.453080, 0.918250, -0.375380, -1.012330, 1.126270, -0.758480, -0.425880, 1.211920, 0.423250, 1.211920, 
0.548480, 0.081970, -0.392490, 0.269950, -0.667660, -0.294330, 0.439420, -1.327220, 1.134710, -1.237840, 
0.116600, -0.232230, 0.367890, 0.454250, 0.689520, -0.735460, 0.058220, 0.234590, 0.320320, -0.922060, 
-0.352250, 0.218350, 0.580360, -0.665880, -0.924930, -0.412890, 0.525950, -0.057560, -0.122130, -0.159780, 
-0.535450, -0.990330, 0.872270, -0.328480, -0.001840, -1.322190, -0.688030, -0.817560, 0.112950, -0.591100, 

-0.574660, -0.737630, 0.084200, -0.331190, 0.252750, 1.589900, 0.527550, -1.379060, 0.698460, 0.130460, 
-0.341440, 0.623160, -0.421410, 0.194260, 0.314460, -0.913950, -0.085280, 0.883480, 1.161630, -0.706980, 
-0.628620, -0.188680, -0.924920, 0.952700, 0.220510, -1.031730, 0.336210, 0.437840, 0.518880, -0.990590, 
-0.303460, -0.268070, -0.133960, 0.330020, -0.474750, -0.745740, -0.072620, -1.125840, 0.882720, -0.614680, 
-0.168120, -0.146770, -0.225660, 0.204530, -1.192400, -0.432060, -0.082740, -0.098430, 0.917660, -0.053780, 
1.323230, -1.311790, -0.655020, -0.010640, 0.636820, 1.102680, 0.065420, -0.318020, -1.240060, -0.326560, 

0.497980, 0.030170, 1.180290, 1.054160, 0.602200, -1.867040, -0.977110, 0.002460, 0.298620, -0.626100, 
0.374430, -0.001790, -1.080990, 0.117470, 0.338960, 0.138050, -1.623310, -0.409630, -0.612080, -1.099480, 
-1.628390, 0.868430, 1.140290, 0.372810, 0.947520, 1.649190, -0.311550, -1.082140, -1.058310, -0.185560, 
0.324290, -0.910710, 0.589340, -1.088740, -0.763750, 0.159610, 0.727720, 0.670680, 0.572290, -0.986370, 
0.649680, -0.045680, -0.774620, -0.773270, 0.331540, -1.276460, 0.410360, -0.435890, -0.302080, -0.208210, 
-0.393400, -0.279360, -0.418510, -0.617550, -0.946970, -0.997450, -0.176290, -0.497510, -1.405280, 0.367370, 

-0.665100, 0.664780, 0.113260, 0.681680, 0.305090, -0.400430, 0.507660, -0.203970, -0.958850, -0.178260, 
-0.103250, 0.530010, -0.460500, -0.718040, 0.675680, -1.704640, -0.119050, -0.956950, 1.611580, -0.319590, 
0.532770, 0.518900, -0.335220, -1.576880, -0.791010, -0.716210, 1.376040, 2.333010, 0.396870, 0.596480, 
-0.091800, -0.610010, 0.985900, 0.497200, 0.249890, -0.474290, 0.468770, 0.344100, 0.458920, -0.461820, 
-0.188360, -0.860030, -0.854640, 0.158430, -0.183140, -0.134380, 1.332670, -0.318620, -0.106550, 0.059840, 
0.037890, -0.743900, 0.018910, 0.044140, -0.148950, 0.126900, -0.603940, -0.346940, 0.579190, -0.134010, 

0.005890, -0.626670, 1.025330, 0.631150, -0.682410, 0.207970, 0.030640, 0.728490, -0.498740, 1.369770, 
-0.696640, 0.337440, -1.055390, 0.756160, -0.846790, 0.137210, -1.743360, -1.056210, 0.151500, -0.488710, 
-0.298460, 0.484720, 0.511470, 0.682110, 0.250700, -0.002550, -0.148170, 0.829550, -0.500900, -1.297330, 
0.014650, 0.055770, -0.185260, -0.207340, 0.494220, -0.146580, 0.255450, -0.380490, 0.681460, -1.217150, 
0.392620, 0.994310, 0.711590, 0.436660, 0.979540, -1.293960, -0.657340, -0.634840, 0.729130, -0.248590, 
-0.734630, -0.883520, 0.831390, -0.434990, -0.327250, -0.932460, -0.277490, 0.134280, -0.925900, -0.301870, 

0.282960, -0.281920, 0.031010, -0.326070, 0.462930, -0.804200, 0.207770, -0.854760, -0.390380, -0.440170, 
0.343140, 0.448160, 0.399510, 0.085490, 0.173520, 0.567390, 0.726550, -2.098900, 0.325780, 0.503920, 
-0.501080, -0.454770, 0.128940, -1.205110, 0.188590, 0.051260, -0.759600, 0.761280, 0.243050, -0.583600, 
0.564140, 0.572960, -0.420830, -0.401080, -1.436220, -0.385170, -0.111300, -0.617100, 0.243390, 0.370440, 
-0.024610, 0.130300, 0.181880, -0.117750, -0.058070, 0.228120, -0.487920, 0.008110, 0.793820, -0.465040, 
0.549130, -0.925930, 0.615990, 1.028580, -0.979270, -0.452570, -0.154730, 0.237380, -0.862990, -0.379770, 

0.849720, 0.244030, -0.222140, -0.370980, -0.999380, -0.800040, 0.001250, -0.825890, -1.096410, -0.316940, 
0.416490, -0.388840, -1.005550, -0.361760, 0.318700, -0.097060, -0.041050, 0.371840, -0.344960, 0.084350, 
0.443100, -0.302580, -1.115510, 0.103640, -0.731580, 0.009850, -0.721360, 0.248130, -0.460110, 0.162900, 
-0.575210, -0.588780, 0.705890, 0.488990, -0.561360, -0.203020, 0.072400, -0.724200, 0.909820, 0.133920, 
0.460660, -0.620260, -0.483000, 0.624270, -1.223220, -0.044470, 0.080710, 0.864070, -0.515750, -0.083520, 
0.535570, -0.445990, -0.849880, -0.049120, -1.201030, 0.233750, 0.009830, 0.266750, -0.292610, -0.465300, 

-0.874340, -0.730830, -1.500270, 0.415150, -0.912520, -1.600800, 0.086030, 0.558200, 0.384870, 0.331940, 
0.609230, -2.040310, -0.090440, -0.780050, -0.194600, 2.080290, -0.476600, 1.147320, 0.488000, 0.033470, 
-1.091770, 1.389250, -0.844970, 2.496620, -1.069860, 1.520030, 0.792750, -1.558810, -0.011440, -1.099680, 
-0.252960, -0.826340, -0.616370, -0.082300, 0.082490, 0.463550, -0.981510, -0.981310, -0.591580, 0.019220, 
0.409510, 0.653080, -0.582240, -0.515060, -0.033930, -0.804670, -0.060730, 0.418330, -0.768070, 0.459810, 
0.855120, 0.259410, -0.015720, 0.678970, -0.819690, 0.640470, 0.687220, -0.136940, -0.666140, -0.916130, 

0.930340, 0.458630, -2.156620, -0.272700, -0.841520, 0.739890, -0.507840, 0.267050, 1.021150, -0.658230, 
0.478340, -1.994230, 0.317950, 0.452210, -0.305600, 0.630110, 1.106390, 0.279480, -0.043040, 0.020080, 
-0.723730, -0.622570, 2.334120, -0.264330, 0.568450, 0.924570, 2.112710, -1.572950, 0.403270, 0.582410, 
-0.420530, 1.281710, 0.134380, -0.655740, 0.542560, 0.362950, 0.576800, 0.262770, 1.153130, 0.400530, 
0.630610, 0.516590, 0.190170, 0.037140, 0.160480, 0.156100, -0.484870, -0.314790, 0.126080, -0.123410, 
-0.009380, 0.743180, -0.542440, 0.693060, 0.508690, 0.182130, -0.225710, 0.519710, 0.288180, -0.835110, 

0.536010, 0.207640, 0.357990, -1.376570, 0.591880, -0.092500, 0.892200, -0.950030, 1.266830, -1.208730, 
-1.328700, 0.317490, 0.842620, -0.804130, 0.870200, -0.398300, -0.187580, -0.137330, -1.564090, -0.066920, 
1.646750, -0.076420, -0.146320, -0.432800, -1.526580, 0.193210, 0.418170, -0.263100, -0.410540, -0.461470, 
-0.166030, -0.566110, 0.336270, -1.042140, 0.291620, -0.013970, 0.404010, -0.070340, -0.529020, 0.052210, 
0.162470, 0.076300, -0.810930, -0.063860, -1.433190, 0.006590, 0.405870, -0.612440, -0.374320, 0.071330, 
-0.101230, -1.556860, 0.373660, -0.806220, -0.855730, 0.668420, -0.671190, -0.433350, -1.008850, 0.057550, 

0.891780, -0.748880, 0.153740, 1.097510, 0.243400, 2.196470, -0.380770, 0.611670, -0.366900, 0.132200, 
0.695620, 1.353300, -1.665980, 0.760380, 1.035600, -0.105610, -0.125540, -1.194810, -0.889310, -1.133580, 
-1.221370, -0.067150, 0.784140, -0.702520, -1.215110, -1.490560, 0.306170, 1.346780, 0.352010, -0.047310, 
-0.287510, -0.826620, 0.159710, 0.271680, -0.800420, -0.445940, -0.741180, -0.120780, -0.101330, -0.595370, 
-0.052850, -0.496930, -0.704610, -1.050490, 1.015860, -1.573680, -1.236960, 1.383790, -0.866720, -0.100130, 
-0.440400, -0.125120, 1.311910, -0.701390, -1.088890, -0.283200, -0.783810, 0.269280, -0.056190, -0.615550, 

-0.429690, 0.555530, -0.303880, 0.797680, -0.094990, -1.527740, -0.304200, -1.283380, -1.084170, 0.141590, 
0.942240, -0.463780, 0.520650, 0.082530, 0.227980, -2.205770, -0.903750, -0.236730, 0.412230, -0.416720, 
1.429600, -0.028770, 0.257970, 0.020980, -1.247460, 0.311470, 0.186860, 0.116510, 0.493330, 0.801620, 
-0.788330, -0.670850, -0.372960, 0.420230, 0.239000, -0.692830, -0.990950, -0.356100, -0.646870, -0.748910, 
-0.621930, 0.246000, -0.587890, 0.967290, -0.777210, -1.165950, 0.150050, -1.042420, -0.261580, -1.117010, 
-0.453630, -0.762820, 0.831230, -0.148800, 0.057240, 0.344080, 0.043520, -0.417660, -0.272760, 1.065960, 

-0.825510, 0.776650, -1.198680, -0.326340, 0.392720, -0.226600, -0.293130, 0.044990, -0.018320, -0.457370, 
0.208240, -1.289640, 0.753210, 0.109660, 0.419780, -0.969300, -0.880820, -0.179290, -0.033510, -1.104930, 
-0.766360, -1.032310, -0.996630, 0.312670, 0.489540, 0.348180, 0.313370, -0.090070, -0.834250, -0.868300, 
0.985920, -0.881760, 0.146540, -0.316760, -0.531770, -0.585880, -0.143450, -0.250860, 0.645960, -0.215360, 
-0.379560, 0.636360, 0.217550, -1.035610, -0.532590, -0.979050, 0.073390, 0.516000, 0.007880, -0.874120, 
-0.007550, 1.006370, -0.960640, 0.042190, -1.325620, 0.431390, -0.198610, 0.683880, 0.106620, 0.074660, 

-0.336850, 0.507140, 0.352300, 0.753780, 0.263040, 0.519190, 0.631900, -0.222970, 0.745840, -1.168630, 
-0.031110, 0.811690, -0.045960, -1.401560, -0.273170, -0.547370, -0.797350, -1.489900, -0.907090, -1.745630, 
1.615140, -1.075120, 0.243470, -1.103420, 0.514840, -0.162180, 0.545360, 0.812570, -1.535890, -0.722930, 
-0.152700, 1.027760, -0.643460, -0.915090, 0.201590, -1.150280, 0.112540, -0.231690, 1.165780, 0.117690, 
-0.368910, -0.404190, 0.935030, 0.370990, -1.013680, 0.482540, -0.842420, -0.622830, 0.328540, -0.041570, 
0.476170, -0.883000, -0.211410, 0.335200, 0.323910, 0.265890, -0.742220, -0.350010, 0.244100, -0.607860, 

-1.493860, 0.224180, -0.794270, -1.021700, 1.966070, -1.181510, 0.971790, 0.620560, -1.958550, 1.267570, 
-1.749670, 0.019490, 1.156100, 0.090950, -0.975730, -0.739000, 0.395910, -0.831920, -0.566500, -1.068690, 
-0.094980, 0.461030, 0.684360, -0.586080, 1.610450, -1.831180, 0.324910, 1.494150, 0.361310, 0.330440, 
0.255380, 0.160250, -0.105270, -0.355240, 0.079620, 0.083800, -0.463340, 0.108660, -0.892010, -0.426180, 
-0.114880, -1.835430, -0.080690, -0.137130, 0.223920, -1.445710, -0.387910, -0.990960, 0.277790, 0.131680, 
-0.430520, 0.041480, 0.458910, -1.017500, -0.824630, 0.374660, 0.091330, -0.006130, 0.163190, -0.253610, 

-0.871100, -1.241970, -0.016670, 1.337480, -0.409050, -0.317330, -1.027020, -0.070240, -0.023630, -0.379670, 
0.265340, 0.545240, 0.081290, -0.002200, 0.984740, 0.710080, -0.645120, -0.145050, 0.715620, -0.378300, 
-1.329400, 0.147070, 0.396860, -0.501940, 0.165210, -0.791020, 1.064290, -0.443080, 0.147250, 0.262030, 
-0.066610, -0.635950, -0.500040, -0.822560, -1.095670, -0.953080, -0.054350, -0.775160, 0.686310, -0.670510, 
-0.539820, 0.083220, -0.008630, 0.339540, -0.225760, -0.898470, 1.090510, -0.490440, 0.815170, 0.942580, 
-0.679510, -0.029210, -0.845440, -1.311620, -0.705750, 1.231180, 0.300090, 0.228730, -1.322050, -1.062020, 

-0.273760, 1.049570, 0.077400, -2.007490, 0.835270, 0.204210, 0.131670, 0.542170, 1.209830, -1.779500, 
0.836810, 0.484330, -0.091280, 0.133420, 1.179740, -0.302330, -0.642270, 0.126820, 0.218880, 0.252760, 
-0.193260, 0.070170, 0.116680, -0.952660, -0.182710, 0.083190, 0.291960, 0.979690, 0.620170, -1.021290, 
-0.266140, -0.049680, -0.369680, 0.629670, -1.568350, -0.185050, -0.113540, 0.320390, -0.985720, -0.462200, 
0.272940, 0.363610, 0.453020, 0.125630, -0.816750, -1.391410, -0.361850, 0.169130, -0.196970, 0.460930, 
-0.213240, 0.556870, -0.057650, -0.629860, 0.244440, 0.005860, -0.967050, 0.417040, -0.287420, -0.358420, 

0.673990, 0.921940, -0.716500, -0.509090, -0.656880, 0.065350, 0.289850, 0.280620, 0.363460, -0.613910, 
-0.843740, -0.134500, -0.703160, 0.462110, -0.091100, 0.360150, 0.256520, 0.146270, 0.084440, 0.241720, 
-0.456720, -0.263470, -0.902610, -0.030800, -0.093720, -0.019430, 0.061160, 0.295160, -0.714190, -0.461670, 
0.593100, 1.095830, -0.767750, -0.674140, 0.155580, 0.153950, -0.968520, -0.051300, -0.158310, 0.386120, 
-0.155640, -1.046430, -0.860940, 0.935790, -0.326790, -0.596980, 0.879740, 0.126230, -0.951760, 0.097570, 
0.940150, 0.394110, -0.093630, 0.860210, 0.268050, -0.408570, 0.056930, 0.238630, -1.375020, 0.191310, 

1.316980, 1.221000, 0.156000, 0.856040, -0.704100, 0.197310, 0.233300, -0.640760, -0.208830, 0.182370, 
-1.906130, 0.968180, -0.297570, -0.101390, -0.244290, -0.928440, -0.596370, -0.081390, -1.068370, 0.134130, 
1.028380, 0.323420, 1.159000, 0.761940, -0.679750, -1.313870, -0.105680, 0.424130, -0.599850, -0.357570, 
0.174730, 0.597510, -0.173150, -1.248390, 0.629640, 0.806820, -0.482320, -1.166660, 0.664480, -0.045010, 
-0.669600, -0.301700, 0.151000, 0.060110, -1.106220, 0.186180, -0.129440, -0.060350, -0.549290, 0.151730, 
-0.441610, 0.225900, -0.845410, -0.225550, 0.325580, 1.667190, 0.046100, -0.320990, -1.118910, -0.580210, 

-1.016310, 0.458740, 0.003010, -0.467050, -0.198760, -0.317270, -0.628390, 0.380530, 0.203940, -0.097430, 
0.404430, 0.778080, 0.747430, 0.101910, -0.439060, -1.478010, -0.262440, -1.422230, -0.607690, 0.808390, 
-1.230670, -0.922640, 0.337360, 0.063510, 0.670480, -1.427940, 0.993490, 0.460260, -0.557400, 1.012780, 
-0.468360, -0.027110, 0.376540, -0.649760, -0.686550, 0.335360, -0.965800, -0.619560, 0.052800, -0.026950, 
0.074900, 0.568350, -0.505670, -0.789730, -0.505480, -0.614530, 0.455480, -0.320090, 0.849410, 0.889620, 
0.298260, -0.508040, 0.341560, -0.524730, -0.125570, -0.318270, -0.457530, -0.137170, -0.278130, -0.028040, 

0.174520, 0.243330, 0.118710, 0.437550, 1.506860, -2.012560, 0.253520, 0.038890, -0.169330, 0.130500, 
-1.159560, 0.160790, -1.254220, -0.729570, 1.368440, 0.377660, -1.060980, 1.254020, -1.074800, -2.175940, 
0.290960, -0.370090, -0.087910, 0.032440, 0.214210, -1.266440, 0.463280, 0.794030, 0.115330, -0.990460, 
0.470850, 0.342260, -0.786970, -0.806120, -0.703150, 0.362630, -0.519320, -1.156790, 0.203670, -0.383450, 
-0.324690, -1.249870, 0.696960, 0.775410, -0.463970, -0.462370, 0.364820, -0.211180, 0.638880, -0.551080, 
-0.408570, 0.911400, -0.013680, 0.497040, 0.171090, -0.107850, 0.083810, -0.222430, -1.273280, 0.426380, 

-0.286680, 1.075750, -0.216240, 0.296750, 0.818060, -0.167150, -0.858630, 0.061150, -1.014800, 0.362970, 
0.510360, 0.897160, 0.411100, -1.079360, 0.037060, 0.886430, 0.849000, 0.034160, 0.831950, -0.047660, 
0.059210, 1.461130, 0.840900, 0.683630, 0.160540, -0.624200, 0.551020, -0.425070, -0.403820, 0.735430, 
0.248260, 0.165870, 0.528040, -0.481300, 0.805130, 0.321300, -0.348350, -0.992690, -0.205180, -0.672350, 
0.782610, -0.063620, -0.879090, -0.323070, 0.188200, -0.429120, -0.337920, -0.244250, -0.669450, -0.411920, 
0.210940, 1.170200, -0.411950, -0.347520, 0.399980, 0.224010, -1.082460, 0.287550, 0.944380, -0.577920, 

-0.628540, 0.532890, -0.049090, 0.600850, 0.692400, -0.370820, -0.663740, 0.101170, -0.313740, -0.763020, 
0.351940, 0.669390, -0.952300, 0.727520, 0.498790, -0.144830, 0.468910, -0.490410, -0.668510, 0.737660, 
-0.065480, 0.372240, -0.175490, -0.215360, -0.347650, 0.438740, -0.002390, 0.626210, 0.136730, 0.177020, 
-0.448350, -0.966550, 0.999750, -0.585750, -0.431140, -0.860580, 0.480160, -0.872150, -0.639540, 0.561210, 
-0.004520, 0.032860, 0.108380, -1.119000, -0.702060, -0.999050, -0.933730, -0.875040, -0.080230, -0.837900, 
-0.303410, -0.746880, 0.913320, 0.629500, -0.943240, -0.249540, -0.853710, -0.467740, -1.268670, 0.733910, 

-0.582320, -1.417820, 0.723750, 0.565710, 1.101670, 0.114710, 0.665620, 0.567980, -0.473250, -1.298240, 
0.467010, 1.319400, -0.749080, -0.326110, 0.764280, -1.589520, 0.869860, -0.653880, -1.442190, 0.979350, 
-0.578350, -0.979230, 0.942260, -0.804920, -0.182930, -0.599560, -0.654890, -0.940130, 1.114000, 0.451420, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, 1.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (inp2) */
      0.0, 0.998030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (inp3) */
      0.0, 0.916740, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (inp4) */
      0.0, 0.646710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (inp5) */
      0.0, 0.270800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (inp6) */
      0.0, 0.817340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (inp7) */
      0.0, 0.815400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (inp8) */
      0.0, 0.025570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (inp9) */
      0.0, -0.053500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 10 (inp10) */
      0.0, 0.091130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 11 (inp11) */
      0.0, 0.533640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 12 (inp12) */
      0.0, -0.662580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 13 (inp13) */
      0.0, -0.863460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 14 (inp14) */
      0.0, -0.136120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 15 (inp15) */
      0.0, -0.112190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 16 (inp16) */
      0.0, 0.898340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 17 (inp17) */
      0.0, -0.534100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 18 (inp18) */
      0.0, 0.962170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 19 (inp19) */
      0.0, 0.495280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 20 (inp20) */
      0.0, 0.403610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 21 (inp21) */
      0.0, -0.751960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 22 (inp22) */
      0.0, -0.063110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 23 (inp23) */
      0.0, -0.840520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 24 (inp24) */
      0.0, -0.030860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 25 (inp25) */
      0.0, -0.620860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 26 (inp26) */
      0.0, 0.623160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 27 (inp27) */
      0.0, -0.772630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 28 (inp28) */
      0.0, -0.141230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (inp29) */
      0.0, 0.846450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 30 (inp30) */
      0.0, -0.630550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 31 (inp31) */
      0.0, -0.969780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (inp32) */
      0.0, 0.763300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 33 (inp33) */
      0.0, -0.787810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 34 (inp34) */
      0.0, -0.568970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 35 (inp35) */
      0.0, 0.798170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 36 (inp36) */
      0.0, 0.493380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 37 (inp37) */
      0.0, 0.960320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 38 (inp38) */
      0.0, 0.243250, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 39 (inp39) */
      0.0, -0.357750, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 40 (inp40) */
      0.0, -0.361850, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 41 (inp41) */
      0.0, -0.505410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 42 (inp42) */
      0.0, 0.987540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 43 (inp43) */
      0.0, -0.248810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 44 (inp44) */
      0.0, 0.747080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 45 (inp45) */
      0.0, -0.235100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 46 (inp46) */
      0.0, -0.541860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 47 (inp47) */
      0.0, 0.626930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 48 (inp48) */
      0.0, 0.006560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 49 (inp49) */
      0.0, -0.019000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 50 (inp50) */
      0.0, 0.368120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 51 (inp51) */
      0.0, -0.403410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 52 (inp52) */
      0.0, 0.265510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 53 (inp53) */
      0.0, -0.752620, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 54 (inp54) */
      0.0, 0.258010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 55 (inp55) */
      0.0, -0.050500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 56 (inp56) */
      0.0, 0.144330, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 57 (inp57) */
      0.0, -0.085490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 58 (inp58) */
      0.0, -0.335960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 59 (inp59) */
      0.0, 0.657720, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 60 (inp60) */
      0.0, -0.661560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 61 (inp61) */
      0.0, -0.723810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 62 (inp62) */
      0.0, -0.538440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 63 (inp63) */
      0.0, 0.894840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 64 (inp64) */
      0.0, -0.933460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 65 (inp65) */
      0.0, 0.331430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 66 (inp66) */
      0.0, 0.835810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 67 (inp67) */
      0.0, 0.459370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 68 (inp68) */
      0.0, 0.851480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 69 (inp69) */
      0.0, -0.352450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 70 (inp70) */
      0.0, -0.620320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 71 (inp71) */
      0.0, 0.071580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 72 (inp72) */
      0.0, -0.138370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 73 (inp73) */
      0.0, -0.024410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 74 (inp74) */
      0.0, -0.173020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 75 (inp75) */
      0.0, -0.477520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 76 (inp76) */
      0.0, -0.743380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 77 (inp77) */
      0.0, -0.155930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 78 (inp78) */
      0.0, -0.929410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 79 (inp79) */
      0.0, 0.332940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 80 (inp80) */
      0.0, 0.214340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 81 (inp81) */
      0.0, 0.646140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 82 (inp82) */
      0.0, 0.776260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 83 (inp83) */
      0.0, -0.705360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 84 (inp84) */
      0.0, -0.622340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 85 (inp85) */
      0.0, -0.909770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 86 (inp86) */
      0.0, -0.808570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 87 (inp87) */
      0.0, 0.722170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 88 (inp88) */
      0.0, -0.372370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 89 (inp89) */
      0.0, 0.746030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 90 (inp90) */
      0.0, 0.991820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 91 (inp91) */
      0.0, 0.998990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 92 (inp92) */
      0.0, 0.614100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 93 (inp93) */
      0.0, -0.173560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 94 (inp94) */
      0.0, 0.250080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 95 (inp95) */
      0.0, 0.946430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 96 (inp96) */
      0.0, 0.070470, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 97 (inp97) */
      0.0, -0.570690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 98 (inp98) */
      0.0, 0.115530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 99 (inp99) */
      0.0, 0.424190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 100 (inp100) */
      0.0, -0.706710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 101 (inp101) */
      0.0, -0.051940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 102 (inp102) */
      0.0, -0.456830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 103 (inp103) */
      0.0, 0.467370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 104 (inp104) */
      0.0, -0.566970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 105 (inp105) */
      0.0, 0.063910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 106 (inp106) */
      0.0, 0.606010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 107 (inp107) */
      0.0, 0.105650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 108 (inp108) */
      0.0, -0.456880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 109 (inp109) */
      0.0, -0.932190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 110 (inp110) */
      0.0, -0.513680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 111 (inp111) */
      0.0, 0.067890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 112 (inp112) */
      0.0, -0.737930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 113 (inp113) */
      0.0, 0.731920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 114 (inp114) */
      0.0, -0.692110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 115 (inp115) */
      0.0, 0.963820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 116 (inp116) */
      0.0, -0.881710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 117 (inp117) */
      0.0, -0.340160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 118 (inp118) */
      0.0, -0.599940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 119 (inp119) */
      0.0, 0.713570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 120 (inp120) */
      0.0, -0.220920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 121 (inp121) */
      0.0, -0.816570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 122 (inp122) */
      0.0, -0.548830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 123 (inp123) */
      0.0, 0.267870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 124 (inp124) */
      0.0, -0.888580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 125 (inp125) */
      0.0, -0.769640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 126 (inp126) */
      0.0, 0.109660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 127 (inp127) */
      0.0, 0.673940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 128 (inp128) */
      0.0, 0.150370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 129 (inp129) */
      0.0, 0.040290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 130 (inp130) */
      0.0, 0.937740, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 131 (inp131) */
      0.0, -0.216860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 132 (inp132) */
      0.0, -0.584520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 133 (inp133) */
      0.0, 0.635010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 134 (inp134) */
      0.0, -0.050240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 135 (inp135) */
      0.0, -0.797520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 136 (inp136) */
      0.0, 0.382420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 137 (inp137) */
      0.0, -0.885250, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 138 (inp138) */
      0.0, 0.223950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 139 (inp139) */
      0.0, -0.861020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 140 (inp140) */
      0.0, -0.822770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 141 (inp141) */
      0.0, 0.324560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 142 (inp142) */
      0.0, -0.065620, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 143 (inp143) */
      0.0, -0.404150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 144 (inp144) */
      0.0, -0.942020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 145 (inp145) */
      0.0, -0.536170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 146 (inp146) */
      0.0, -0.503880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 147 (inp147) */
      0.0, 0.818270, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 148 (inp148) */
      0.0, -0.707930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 149 (inp149) */
      0.0, 0.650710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 150 (inp150) */
      0.0, 0.960460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 151 (inp151) */
      0.0, 0.161890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 152 (inp152) */
      0.0, 0.407260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 153 (inp153) */
      0.0, 0.243540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 154 (inp154) */
      0.0, 0.162570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 155 (inp155) */
      0.0, 0.723100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 156 (inp156) */
      0.0, 0.238310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 157 (inp157) */
      0.0, 0.400440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 158 (inp158) */
      0.0, 0.957980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 159 (inp159) */
      0.0, 0.522390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 160 (inp160) */
      0.0, 0.925780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 161 (inp161) */
      0.0, 0.557880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 162 (inp162) */
      0.0, -0.050870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 163 (inp163) */
      0.0, 0.010950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 164 (inp164) */
      0.0, -0.765040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 165 (inp165) */
      0.0, -0.547660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 166 (inp166) */
      0.0, 0.882000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 167 (inp167) */
      0.0, 0.760400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 168 (inp168) */
      0.0, -0.095600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 169 (inp169) */
      0.0, 0.316170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 170 (inp170) */
      0.0, 0.086380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 171 (inp171) */
      0.0, -0.176240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 172 (inp172) */
      0.0, -0.170300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 173 (inp173) */
      0.0, 0.860150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 174 (inp174) */
      0.0, -0.637860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 175 (inp175) */
      0.0, 0.193680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 176 (inp176) */
      0.0, -0.170970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 177 (inp177) */
      0.0, 0.617680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 178 (inp178) */
      0.0, -0.784550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 179 (inp179) */
      0.0, 0.647340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 180 (inp180) */
      0.0, 0.584590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 181 (inp181) */
      0.0, 0.768500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 182 (inp182) */
      0.0, 0.682170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 183 (inp183) */
      0.0, -0.985290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 184 (inp184) */
      0.0, -0.363140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 185 (inp185) */
      0.0, -0.623590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 186 (inp186) */
      0.0, -0.284430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 187 (inp187) */
      0.0, 0.341320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 188 (inp188) */
      0.0, -0.475110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 189 (inp189) */
      0.0, -0.646970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 190 (inp190) */
      0.0, -0.442520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 191 (inp191) */
      0.0, -0.315960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 192 (inp192) */
      0.0, 0.282450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 193 (inp193) */
      0.0, -0.220730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 194 (inp194) */
      0.0, 0.169990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 195 (inp195) */
      0.0, -0.629910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 196 (inp196) */
      0.0, -0.547930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 197 (inp197) */
      0.0, 0.451380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 198 (inp198) */
      0.0, 0.910520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 199 (inp199) */
      0.0, -0.202080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 200 (inp200) */
      0.0, -0.028180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 201 (inp201) */
      0.0, -0.260430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 202 (inp202) */
      0.0, 0.638210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 203 (inp203) */
      0.0, 0.443000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 204 (inp204) */
      0.0, 0.095020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 205 (inp205) */
      0.0, -0.285970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 206 (inp206) */
      0.0, -0.485660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 207 (inp207) */
      0.0, 0.172690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 208 (inp208) */
      0.0, -0.236100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 209 (inp209) */
      0.0, -0.236580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 210 (inp210) */
      0.0, -0.708870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 211 (inp211) */
      0.0, 0.637090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 212 (inp212) */
      0.0, 0.384140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 213 (inp213) */
      0.0, 0.953340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 214 (inp214) */
      0.0, 0.981640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 215 (inp215) */
      0.0, -0.902910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 216 (inp216) */
      0.0, -0.981510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 217 (inp217) */
      0.0, 0.590120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 218 (inp218) */
      0.0, -0.208190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 219 (inp219) */
      0.0, -0.871300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 220 (inp220) */
      0.0, -0.119130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 221 (inp221) */
      0.0, -0.093730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 222 (inp222) */
      0.0, 0.121740, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 223 (inp223) */
      0.0, 0.100500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 224 (inp224) */
      0.0, 0.386390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 225 (inp225) */
      0.0, 0.598370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 226 (inp226) */
      0.0, 0.568400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 227 (inp227) */
      0.0, 0.900210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 228 (inp228) */
      0.0, 0.580880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 229 (inp229) */
      0.0, -0.149130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 230 (inp230) */
      0.0, -0.829640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 231 (inp231) */
      0.0, 0.168780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 232 (inp232) */
      0.0, -0.308320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 233 (inp233) */
      0.0, 0.288600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 234 (inp234) */
      0.0, -0.173400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 235 (inp235) */
      0.0, 0.216110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 236 (inp236) */
      0.0, 0.932300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 237 (inp237) */
      0.0, 0.428970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 238 (inp238) */
      0.0, 0.816790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 239 (inp239) */
      0.0, 0.111230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 240 (inp240) */
      0.0, -0.851870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 241 (inp241) */
      0.0, -0.842570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 242 (inp242) */
      0.0, -0.211860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 243 (inp243) */
      0.0, -0.722290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 244 (inp244) */
      0.0, 0.970570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 245 (inp245) */
      0.0, -0.373400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 246 (inp246) */
      0.0, -0.689140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 247 (inp247) */
      0.0, 0.740710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 248 (inp248) */
      0.0, 0.880690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 249 (inp249) */
      0.0, 0.973860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 250 (inp250) */
      0.0, 0.217680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 251 (inp251) */
      0.0, -0.731350, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 252 (inp252) */
      0.0, 0.969890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 253 (inp253) */
      0.0, -0.848580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 254 (inp254) */
      0.0, -0.773440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 255 (inp255) */
      0.0, -0.324140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 256 (inp256) */
      0.0, -0.309820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 257 (inp257) */
      0.0, 0.847320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 258 (inp258) */
      0.0, 0.814050, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 259 (inp259) */
      0.0, 0.993500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 260 (inp260) */
      0.0, -0.053340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 261 (inp261) */
      0.0, -0.579510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 262 (inp262) */
      0.0, -0.308040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 263 (inp263) */
      0.0, -0.091790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 264 (inp264) */
      0.0, -0.596780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 265 (inp265) */
      0.0, -0.453510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 266 (inp266) */
      0.0, 0.493370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 267 (inp267) */
      0.0, 0.489510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 268 (inp268) */
      0.0, 0.723290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 269 (inp269) */
      0.0, 0.034100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 270 (hid11) */
      0.0, 0.613290, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, 0.455870, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, -0.299080, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, -1.375850, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 0.105260, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, 1.480240, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, 0.551520, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, 0.816270, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, -0.971190, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, 0.614170, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -1.072040, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, -0.197280, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, 0.468260, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, 1.020220, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, 0.338690, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, 1.198940, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, -0.338990, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, 0.304240, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, -0.125180, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.628600, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, 0.071070, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, -0.560400, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, -0.351560, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, 0.654200, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, -0.523620, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, -0.305560, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, -0.236070, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, 0.217940, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, -0.912970, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, 0.929610, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, -0.089340, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, -0.683660, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, -1.113810, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, -0.442660, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, -0.952360, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, 0.606240, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, -0.208470, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, -0.288510, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, -0.180780, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, -1.378070, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, -1.060910, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -1.240990, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, -0.887340, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, -0.109620, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, -0.800860, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, 1.320290, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, -0.154740, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, -0.829740, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -0.747220, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, -0.068830, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, 0.195110, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, -0.386550, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, 0.082790, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, -1.512010, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, -1.294230, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, -0.039920, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, -0.264120, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, 0.568020, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, 0.030310, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -0.502690, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, -0.508530, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
1.42621, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.38029, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
0.31962, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
1.00225, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.15594, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
0.37321, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
0.43790, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
1.09645, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
1.29543, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
1.25772, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
0.39795, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
0.33674, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
1.00086, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
0.12994, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
0.09855, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
1.13479, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.38470, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
1.31711, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
0.10509, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
1.32624, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
1.41948, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
0.37253, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
0.27033, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
1.30715, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
0.07668, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.69394, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
1.36402, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
0.00060, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
0.00265, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.56652, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
0.03371, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
0.00517, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
0.03626, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
0.01963, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
0.00074, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
0.00455, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
0.07254, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
0.82685, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
0.09815, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
0.00115, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
0.12582, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
0.00441, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
0.01314, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
0.12355, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
0.97936, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
1.42730, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.41314, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
0.02007, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
0.00375, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
0.00469, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
0.15360, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
0.00163, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
0.02926, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
0.04024, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
0.02651, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
0.75681, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
0.01352, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
0.01164, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
1.39307, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.00885, 0.500000, 2,
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
