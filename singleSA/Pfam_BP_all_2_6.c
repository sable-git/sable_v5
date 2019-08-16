/*********************************************************
  Pfam_BP_all_2_6.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:18:33 2005
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
-0.204000, -0.005110, -1.208590, 0.724760, 0.314760, -0.394520, -0.525490, -0.671910, 0.420860, -0.119080, 
-0.247430, 0.210410, -0.753080, -0.168980, 0.973300, 0.908310, 0.047230, 0.229840, 0.587240, -0.450480, 
1.025880, 0.524320, 1.100440, -0.820880, 0.753140, -0.705160, 0.020130, -1.344060, 0.194220, -0.280760, 
-0.053150, -0.215820, 0.599640, 0.025110, -1.188520, -0.117060, -0.362110, -0.522850, -0.078350, 1.326720, 
-0.430820, -0.166970, 0.500670, -0.122720, 0.431760, 0.221800, -0.510960, 1.114140, -0.696100, -0.172650, 
-0.381450, -0.756220, -0.655960, 0.987260, -0.503680, 0.325300, 0.110650, 0.065550, 0.556580, 0.394210, 
-2.209020, 0.366100, 0.098950, -0.853700, -1.145910, 0.413960, -0.378570, 0.215850, 1.647900, -1.775520, 
-1.362520, 0.705450, -0.595880, 1.383420, -0.669630, 1.000710, 1.012770, -0.458390, -0.198670, 0.541920, 
0.725820, 1.207110, -0.385000, 0.227640, -0.299380, -0.353740, 0.853030, -0.020330, -1.475910, -0.055730, 
-1.072790, 0.202880, -0.783980, -0.034800, -1.472440, 0.360810, 0.608970, 0.715470, -0.820070, 0.775150, 
0.678730, -0.010450, -0.062780, -0.652480, -0.493070, 0.998890, 0.542450, -0.141660, 0.723110, 0.175910, 
0.712000, -0.149100, -0.711580, 0.715240, -0.048610, 0.036270, -1.962280, -0.560790, 0.369930, 0.088980, 
-0.305300, 0.848600, 0.969570, -1.472630, -0.629830, -0.622380, 0.396950, 0.421440, -1.128470, 0.663540, 
0.951040, 0.060660, -1.174920, -0.704470, -0.227620, -0.955690, -2.588510, 1.772140, -0.273210, 0.685320, 
0.582260, 1.491920, -0.204500, 0.005950, 1.000650, -0.389340, -0.675880, -1.230200, 0.151890, -0.627150, 
-0.552470, 1.686820, 0.511450, 0.368410, -0.125390, 0.821040, -0.842020, -0.535800, -0.234390, 0.110580, 
1.179430, 0.701070, 0.378600, 0.782460, 0.651280, 0.013330, -0.915160, 0.741240, 0.248470, -0.520640, 
0.927870, 0.707610, -0.961820, 0.581940, 0.542590, 1.597600, -0.603420, 1.588290, 1.021320, 1.353070, 
-0.206320, -0.735620, 0.128950, 0.635910, 0.510070, -0.053740, 0.567830, 0.420850, -0.026590, -0.331330, 
0.798570, -0.135950, -0.268690, 0.077850, 0.361980, 0.000270, -0.469320, 0.601810, 0.124530, 0.088890, 
-0.492230, 0.897220, 1.369910, -1.107510, 1.123190, -0.412270, 1.160340, -0.095970, 0.110450, 0.219190, 
1.372330, 1.077110, 0.822210, 0.402810, 0.680280, -0.298820, -0.182890, -0.941280, -0.174040, 0.701760, 
0.676340, -0.985610, 0.169930, 0.470390, 0.196910, 0.146890, 0.368000, -0.493600, 0.599530, 0.501930, 
0.200210, 0.436920, 0.404080, 0.680670, 0.405450, -0.820060, -0.348480, -0.547300, -0.380230, -0.301720, 
-0.285590, 0.776440, -0.371930, -0.015690, 0.528340, 0.193170, -0.708490, 0.283860, 0.122390, -0.503700, 
-0.063970, 0.708590, 0.652360, -0.222270, 1.330940, -0.987240, -0.878150, 0.188230, -0.519350, -1.558810, 
3.606410, 1.061280, 0.510390, 0.789560, -0.292190, 1.998260, 0.110640, 1.191490, 0.689850, -0.392140, 
-0.572210, 0.327310, 0.026860, 0.991060, -0.057120, 1.053110, -1.059990, 1.263220, 0.667520, 0.385500, 
-0.211920, -1.282810, -0.308150, 0.682030, 0.134650, -0.029120, 0.084340, 1.039090, 0.033970, -0.946890, 
0.318400, -0.559560, -0.037880, -0.490850, -0.461330, -0.798700, 0.393690, 0.407500, -0.423190, 
-0.038670, 0.038530, -0.869810, -0.322920, 0.922510, -0.646240, 0.327460, -0.153660, -0.883260, 0.629500, 
-0.825210, -0.228550, -0.851020, -0.189720, 1.001270, -0.816440, -0.014320, -1.265410, 0.257200, 0.696590, 
0.673140, 0.309790, -0.552910, 1.133060, 0.928440, -0.126760, -0.041840, -0.563510, -1.107030, 0.608050, 
-0.553950, -0.135070, -0.607260, 0.639620, -0.166710, 0.463090, -0.116470, -0.678600, 0.248270, -1.243920, 
-0.873460, -0.831600, -0.207990, 0.348280, -0.481450, 0.002700, 1.024490, -0.558060, -0.111320, 0.200190, 
0.394740, -0.349830, -1.027890, -0.940480, 0.100490, -0.106570, 0.349860, 0.730130, -0.758390, 0.900300, 
0.121340, -0.845000, -0.695650, -0.696420, -0.721630, -0.114380, 0.048050, 0.842630, -0.359780, 0.553810, 
-0.438300, -0.071270, 0.848110, -0.482770, -0.560070, -1.112180, 0.004200, 0.094510, -0.003630, -0.980720, 
-0.193540, 1.457680, 1.452250, 0.331470, -1.361580, 0.822730, -0.422600, -0.264480, -1.046480, 0.902260, 
0.536110, -0.137790, -0.541640, 1.219030, 0.153160, -0.470570, 1.105380, -0.215680, -0.110380, -1.164310, 
-0.211700, -1.511110, 0.582400, -0.947800, -0.344420, -0.666280, 0.107130, 0.247200, -0.477880, -0.663290, 
0.162110, -1.711190, -0.023250, -0.686660, 0.886450, 0.066890, -1.127120, -1.007180, -0.842450, -0.347790, 
-0.156060, 1.912400, -0.665960, -0.482800, -0.171040, 0.223380, 0.648890, -0.885660, -0.063210, 1.154180, 
-0.645120, 0.541140, -1.162120, -0.472740, 0.540540, -0.764200, 0.319510, -1.777130, 0.486800, -0.355670, 
-0.081370, 0.715500, 0.046210, 0.443820, -1.020500, 1.392130, -0.418580, -1.113260, -0.708050, -0.613620, 
0.173310, 1.090270, 0.801710, 0.226430, -0.630880, -1.159200, 0.167030, 0.259320, -1.185610, 0.218230, 
0.896220, -0.486140, -0.950100, 1.356890, 0.130310, -0.914860, -1.807500, 1.084390, 0.217530, -0.465490, 
-0.622410, -0.309530, -0.013240, 0.538380, 1.433030, 0.996240, -1.368800, -0.304750, -0.191840, 0.006770, 
-0.563790, 1.323910, -0.819530, 0.819380, -0.368750, 0.609160, -0.057040, 1.404820, -0.869250, 0.090090, 
-0.723750, 0.074460, -0.480330, 0.958570, -0.883290, 1.246200, 0.629420, 0.906510, -0.591980, -1.949400, 
-0.321850, -1.515360, -0.478200, 0.655830, -0.885770, -0.955910, -0.248180, -0.798540, 0.694620, -0.417680, 
-0.909690, 0.430040, -1.497470, -0.232500, -0.407740, -0.417600, 0.484440, 0.644520, -0.172500, -0.973230, 
0.409880, -0.464090, -0.247260, 0.854650, -0.519690, -0.915160, -1.292350, 0.485490, -0.519480, 1.408140, 
-0.444760, 0.601420, 1.053540, 0.327630, -0.351190, -0.345740, -0.207040, 1.142050, 0.391680, -0.051550, 
-0.775230, -0.415600, -0.624170, 1.119110, 0.233460, 0.759000, -0.672300, 0.357310, 0.418520, -0.390050, 
1.384040, -1.004880, -0.478380, 0.707900, -0.465110, 0.586910, 0.680790, -0.231320, 0.386150, 0.457590, 
1.216880, -0.548110, -0.048680, -1.650970, -1.114660, 0.052520, -0.364980, -0.437920, 0.500250, -0.485660, 
-0.039200, -0.607940, -1.369710, -0.278430, 0.217040, -0.595230, 0.799550, -0.703120, 0.018330, -0.360380, 
0.494150, -0.812230, -0.187200, -0.634720, -0.092360, -1.005750, -0.407450, -0.187280, 0.407590, 0.355830, 
-0.715240, -0.495220, -0.315160, -0.015160, 0.045560, 0.460630, 0.555110, -0.234140, 0.484240, 
1.324100, 0.615510, 1.369110, 0.577430, 0.693610, -0.798260, -0.177080, 0.566250, 0.264500, -0.641800, 
0.208940, -1.076080, -1.141890, 0.116880, -0.352180, -0.012960, 0.857330, -0.912830, -0.181230, -0.287590, 
-0.158540, 0.759480, -1.357380, -0.789100, 0.169220, -0.547340, -0.600260, 0.773780, -0.492890, -0.057320, 
-0.006320, 0.336340, -0.404810, 0.639460, 0.036620, 0.870370, 0.981220, 0.045110, -0.355140, -0.488740, 
0.148280, 0.187430, -0.735550, -0.256580, -0.306150, 0.679040, 1.149420, 0.732830, -0.070250, 0.133200, 
-0.477230, 0.765270, 0.324930, -0.665720, -1.215120, -0.287720, 1.389420, -0.508310, 0.251160, -0.504600, 
0.323260, -0.057400, 0.467990, 0.997130, 0.533020, -0.644570, 0.051470, -0.448250, 1.032760, 0.458110, 
-0.082440, -0.888420, 0.180430, 0.239180, 1.968650, -0.126090, 0.577530, -1.257930, -1.408580, 1.541870, 
-0.033150, -0.587670, 1.575770, 0.422540, 0.504810, -0.894550, 0.123730, 0.096370, 0.520300, -1.693990, 
-0.445610, 1.281790, -0.897700, 0.893360, -1.234900, -0.082990, -1.427400, 0.133010, 0.000110, -0.020380, 
-0.854980, -0.855980, 0.944800, 1.174980, -0.182850, 0.535540, 0.731870, -0.925520, 1.242730, 0.585180, 
0.023630, 0.412220, -1.336690, -0.673820, 0.234470, 0.557680, -0.354690, -0.965210, -1.211990, -0.496360, 
1.134390, 0.389470, 0.794690, 1.612340, -1.497260, 1.540800, -0.057890, 0.426040, -1.531640, -0.786140, 
-0.327740, -0.869950, -1.448700, 0.096930, 0.922780, -0.792790, -0.206320, 0.815500, -0.261280, 0.191910, 
-0.391410, -1.078770, 0.763090, 1.212830, 0.015590, 0.795310, -0.468290, 0.082400, 0.489060, -0.556030, 
-0.155040, -0.069000, 0.090060, -0.385850, 0.172900, -0.781880, 0.050480, 0.043250, 0.183810, 0.603720, 
-0.088600, 1.040280, 0.537620, 0.581360, 1.036300, -0.077410, 1.110410, -0.315360, 0.216510, -0.300880, 
-0.505410, -0.520170, 0.784300, 0.215530, 1.444900, 0.096880, 0.487990, -0.037770, 0.234300, -0.565830, 
1.279090, 0.449240, -0.942770, 0.888640, -0.589010, 0.331830, -0.391770, 0.352430, 0.633230, 1.062420, 
0.055210, 0.313950, 1.137840, -0.633590, 0.504250, -0.071960, 0.742000, -0.179890, 0.268010, -0.403430, 
0.003240, -1.694870, 0.136780, 0.398550, -0.324570, -0.702370, 1.473450, -0.014670, 0.180120, -0.460210, 
-0.694230, 1.243830, 0.439000, -0.607630, -0.435760, 1.106340, 0.441580, -0.030660, -1.376600, 1.267190, 
-1.156060, -0.744200, 0.483010, -0.107970, 0.721080, -0.730990, 0.271520, -1.140460, -0.011190, -0.369110, 
0.028800, 0.702400, 0.036930, 0.086770, -1.001730, -0.137360, 0.134740, -0.288180, -0.284550, 0.519960, 
1.660620, 0.616660, -0.521260, -0.258840, 0.572710, -0.391080, -0.984340, 0.361950, 0.075400, 0.483490, 
-1.368770, -0.549600, 0.085950, -0.830390, 0.120520, -0.142190, -0.030540, 0.354030, -0.352890, 2.142630, 
1.048480, 0.170270, 1.375460, -0.380000, -0.265640, 0.745540, 0.084460, 0.115460, 0.208090, -0.441440, 
0.847030, 0.214930, 1.538050, -0.115890, 1.531130, 0.778150, -1.043010, -0.171040, -0.891910, 1.064930, 
-0.522540, -0.215570, 0.076470, 0.487290, 1.086720, 1.023330, 0.379260, 0.206390, -0.418030, -1.024560, 
0.274400, -0.472980, -0.055080, 0.971930, 0.002530, 1.926780, 0.631850, 1.233720, 0.923580, 
1.458630, -0.398620, 0.160980, 0.213740, -1.211410, -1.104540, 1.121450, -0.907130, -0.991440, 0.600540, 
2.164050, -0.938710, 0.782690, 0.653690, 0.636330, -0.327540, -0.592060, 0.270660, -0.849000, 0.552040, 
-0.087450, -0.576590, 0.275900, -0.087080, 0.212870, 0.414940, -0.012370, -0.898210, 1.158310, -0.150560, 
-0.341880, 0.480620, 0.138360, -0.553690, 0.338440, -1.693750, 0.500420, -1.132480, -0.586790, 1.473900, 
-0.584840, -0.932490, 0.771320, -0.749420, 0.218980, 1.526500, 0.785720, -0.667510, -0.935240, -0.825980, 
0.134320, -0.495330, -0.561340, 0.151330, 0.292030, -0.644280, 0.281040, -0.587140, -0.334530, -1.198730, 
-0.824480, 0.497590, -1.060270, -1.850230, -0.040600, -1.084620, 0.719080, -0.880680, -1.607220, 0.146200, 
-0.519880, 0.207620, -0.442800, -1.082320, 0.752650, -0.778700, -0.069780, -0.428980, -0.864360, -0.382230, 
0.180700, -0.806960, -1.628580, 0.369340, 0.006070, 0.268870, 0.218650, -0.772510, -0.895730, 0.026340, 
-0.675610, 0.717290, 0.121860, -0.484560, 1.648460, -0.465880, -0.104740, -0.180830, 0.221980, 0.719880, 
-0.335470, 0.217610, -0.471330, 0.151870, -0.108190, -0.643190, 0.447070, -0.235510, 1.328140, -0.461840, 
0.503150, 1.142050, 0.240990, -0.682340, 1.733170, -1.462160, 0.451300, 0.275580, 0.258060, 0.164060, 
-0.294340, -0.131150, 1.095870, -0.813350, -1.592960, -0.112820, 1.240690, 0.803510, -0.949090, -1.706660, 
0.147390, 0.628480, -2.190950, 0.300570, 1.050290, -2.340890, -1.263580, 1.025840, 0.097330, 1.121610, 
-0.230940, 1.308840, 0.005940, -0.845990, -0.299540, -0.707290, 0.231240, 0.206900, 0.571050, -0.508610, 
-0.186790, -0.410570, 0.169720, -0.266450, 0.130030, -0.399270, 0.437670, -1.267600, 0.440220, 0.524600, 
2.012980, 1.096480, 1.189210, 0.157930, 0.087190, 0.904160, 0.029780, -0.287110, -0.825680, 0.537630, 
0.674470, 0.945250, -0.014070, 0.496440, -0.427180, -0.280410, 0.590680, 0.266090, -0.726920, 0.422750, 
-1.412520, 0.054430, 2.125690, 0.104650, 0.223920, -0.331230, -0.083140, 0.168970, 0.479030, -0.814040, 
-1.199660, 0.021380, 0.949630, 1.735210, -0.831980, -0.252680, -1.008060, -0.484650, 0.774480, 1.409090, 
0.517330, 1.186410, -0.398210, 0.221890, 0.195550, -0.636410, -0.213610, 0.117270, -0.278410, 0.036050, 
-0.284460, 1.212900, 0.974890, 0.293550, -0.648960, 0.492650, -0.197860, 0.849310, -1.169810, -0.352720, 
-0.131370, -0.103130, 0.348400, 0.835860, -1.294640, -0.526820, 0.072910, -0.368140, -0.017360, 0.766130, 
-0.212350, 1.419020, -0.837980, 0.790070, -0.741550, 0.292420, 0.050050, -0.144570, 1.101580, 0.775910, 
-0.712160, 0.066430, -0.227800, 0.212710, 1.115880, -1.437330, 0.603420, 0.529730, -0.701740, -0.420010, 
1.252640, -0.057260, 1.009960, -0.474800, 0.077550, -0.083290, 0.226390, -1.023770, -0.517490, -0.556670, 
-0.427020, -0.275940, 1.435820, 0.222240, -0.311370, 0.747780, -0.388350, -0.897630, 0.171840, 0.488630, 
-1.099170, -0.259390, -0.726150, -0.673710, -0.912550, -0.792290, 0.796990, -0.575080, -0.650160, 0.573920, 
-0.126980, -1.113190, 1.521000, 0.466880, -1.434810, -0.240680, 0.464910, 0.557560, 0.096200, 1.178730, 
-0.479110, 1.007560, 0.341980, -0.367180, 0.225390, 2.164010, -0.696130, 1.284650, 0.879990, 
-0.038170, 0.014560, -0.348160, -0.612430, 0.613510, -0.211200, -0.874280, 0.596690, 0.200460, 0.018730, 
0.871700, 1.047090, 1.009470, 1.220000, 0.085560, -0.373200, 0.575590, 0.469160, 0.218690, 0.321420, 
0.410420, -0.888440, -0.574100, -0.216820, 0.053420, 1.036150, 0.380080, -0.627610, 0.935190, -0.815600, 
-0.121050, -0.514560, -1.149050, -1.368880, -0.219490, 0.678040, 0.322460, -0.796810, 0.323480, 1.252930, 
0.072780, 1.646040, -1.343660, 0.708900, 0.555840, -1.229000, 0.718950, 0.730670, -0.747070, -1.094830, 
-0.486720, -0.557490, -0.849500, 0.758190, -1.496020, 0.871370, 0.340000, -1.153500, -0.668540, 0.092820, 
-0.540030, 0.167920, 0.058910, -0.512290, -0.285740, 0.465720, 0.536810, -0.490180, 0.011600, -0.022170, 
-0.705640, 1.640870, 0.136060, -0.220410, -0.581820, 0.579700, 0.862400, 0.141940, -0.573860, -0.602820, 
0.852870, 0.129380, 0.935990, 1.098390, 0.034290, -0.096720, -0.747690, 2.163130, -0.636180, 0.957710, 
-0.784750, 0.339110, -0.174760, 0.372200, -0.046730, 0.311880, -0.257470, 0.289820, -0.894930, -0.269930, 
-0.432390, -0.763020, -0.665780, 0.182300, 0.354390, -0.421110, -0.871650, 0.801930, -0.176700, -1.281840, 
-0.361610, 1.022200, -0.167750, -0.103590, 0.576900, -1.484020, -0.485740, 1.779810, 2.258850, -1.398450, 
0.854390, 0.396330, 0.579300, -0.267230, -2.077660, 1.262300, 1.900390, -0.056050, -0.139950, -0.379370, 
0.476870, 0.928530, -1.739210, -0.312090, 1.391220, -3.184020, -0.656360, 1.863190, 0.261860, -0.961570, 
1.152560, 0.043820, -0.238050, -0.552320, 0.311450, -0.211730, -0.452100, -1.216210, -0.574170, 0.099190, 
0.057640, 0.842850, 0.152500, 1.125820, -0.013660, 0.175480, 0.379140, 1.259650, 0.132910, -0.812120, 
-0.359780, -0.743440, -0.420990, 0.467600, 0.359580, 0.549030, -0.106600, 0.309230, 0.154050, 0.291710, 
-0.921460, 1.167260, 0.001840, 0.768860, 0.950310, 0.312290, 0.356510, -0.339700, -0.150810, 1.214620, 
1.574300, -0.403470, 0.060150, 0.788480, -0.342300, 0.236460, -0.691210, -0.059130, -1.058590, 0.045300, 
-0.010970, -0.405750, -0.323070, 0.267350, -0.310180, 0.865330, 0.684340, 1.014470, 0.658430, -0.485200, 
0.097160, -0.869470, 0.831610, 0.819730, 0.495620, 0.759880, 0.236760, -0.268030, -0.296750, -0.666660, 
-0.192050, 0.435730, -0.062890, 0.265980, 0.127910, 1.145980, -0.319970, -0.078910, 0.366020, -0.810350, 
-0.022530, -0.591360, 0.908250, -0.117280, -0.478160, 0.659700, 0.402770, 1.215360, -0.457770, -0.098800, 
0.300690, -0.002170, -0.116820, -0.398170, 1.018970, 1.190480, -0.551300, 0.194780, 0.000100, 0.217530, 
0.699460, 0.725250, 0.059570, 1.396120, -0.304290, 0.216580, -1.106440, -1.369240, 0.276270, 0.796310, 
1.422220, 0.043540, -0.153000, 0.956190, 0.000560, -0.179170, 0.166580, -0.130380, -0.096030, 1.057240, 
0.765920, 0.926690, 1.833450, 1.411080, -0.630800, 0.821590, -0.982420, 1.048940, -1.346750, -0.758010, 
0.637070, -0.730210, -0.976260, 0.061100, -0.092530, 1.163400, -0.066800, -0.313090, 0.125780, 0.832910, 
-0.167210, 0.348840, 0.292400, 0.073450, -0.344020, -0.859940, 0.600400, -0.381480, 0.798460, 0.406090, 
-0.678660, 0.607840, -0.530260, -0.984930, -0.204160, -0.281920, -0.248960, 0.034780, 1.052210, 
0.091840, 0.830580, 0.444040, 0.377300, 1.033720, 0.586680, -0.870090, -0.433380, 1.593120, -1.131860, 
0.087310, -0.009770, 0.844840, 0.425770, -0.085280, 0.172460, 0.975570, -0.007040, -0.110620, -0.522040, 
0.178750, 0.584680, 0.874450, 1.260980, -0.261320, 0.165360, -0.285430, -0.695720, 0.435460, 0.900560, 
-1.198980, -0.219750, -1.184390, -1.058470, 1.435460, -0.725970, -0.305080, 0.780810, -0.991900, 1.529310, 
1.006920, 0.865670, -0.345200, -0.069820, 0.624240, 0.582280, 0.140730, -0.068840, -1.147390, 1.478270, 
0.084370, 1.076650, -0.162810, -0.121630, -1.582700, 0.380570, -0.117900, -0.527450, 1.673060, -0.393420, 
0.292910, -0.364390, -0.562480, 0.937370, 0.728660, 0.100320, 0.819950, -0.895780, -0.292360, 1.044980, 
0.577480, -1.424360, 0.356970, -0.653570, 0.383220, 1.116770, 0.868270, 0.113250, 0.402610, 0.815560, 
0.872880, -0.146330, 0.495060, 0.210190, -1.304310, -0.919860, -0.278060, 0.231790, 0.306660, 0.821390, 
0.401070, -0.342300, 1.300830, 0.514810, -0.381610, 0.586500, -0.332020, -0.964520, 0.907120, -0.790990, 
1.184290, 0.170270, 0.207060, -0.594330, -0.392370, -0.195980, -1.114430, 1.267320, -1.127700, -0.852130, 
0.675580, -1.047820, 0.804260, 0.213920, 0.353430, -0.255460, -0.287280, -0.454350, 0.703220, -0.683000, 
-1.999780, 0.243810, 0.123240, -0.504300, -1.688880, -0.536690, 1.004530, -0.697110, 1.198870, 1.177850, 
-0.445560, 0.004840, -0.882140, -1.144110, 1.397960, -0.694320, 0.282030, -0.672620, 0.938240, 0.391770, 
1.374930, -0.218720, 1.354520, 0.999370, -0.517030, 0.987520, -0.596790, -0.322710, 0.012700, 0.112140, 
-0.078790, -1.395510, 0.739890, -0.720920, 0.863800, -0.322530, -0.120450, -1.195160, 0.058060, -0.377880, 
0.051360, 0.751190, -0.275220, 0.051890, 0.334550, -0.704720, 0.763000, -0.597790, 0.659400, -0.895240, 
-0.343130, 0.074360, 0.339330, 0.994390, -0.675560, 0.201220, -0.709540, -1.449380, -0.316920, -0.692370, 
0.263330, 1.516630, 0.080180, -0.195170, -0.407750, 1.068800, -0.274440, -0.257390, 1.032420, 0.399670, 
2.100700, -0.826120, 0.062440, 1.362110, -0.708780, -0.348910, -0.255460, -0.382830, 1.021050, 1.020970, 
0.611970, 0.420110, 0.900560, -0.735740, 0.276930, 0.565530, -0.492080, -1.337070, -1.376140, 0.702500, 
0.275110, -0.747400, 0.827890, 2.254420, -1.343880, -0.316950, -0.001910, -0.878640, 0.250860, 0.160140, 
-0.541990, -0.592320, -0.274140, -0.095960, 0.734740, 0.628660, 0.010710, -0.199780, -1.132970, 0.150460, 
-1.788060, -0.676330, -0.441300, 0.091510, -0.726170, -0.058970, 1.135800, 0.583730, 1.684450, -0.376900, 
-0.182350, 0.669490, -1.052840, 0.907870, 0.148740, -0.049330, -0.536950, 0.504130, -1.035320, 0.780670, 
-0.172280, 0.693710, 0.515130, 0.822570, -0.239570, -0.540550, -0.124960, 1.001930, 0.052710, 2.320730, 
0.312680, 0.465070, 1.126340, 0.864670, -1.066870, 1.060310, 0.396890, -0.207020, 0.138820, -0.480760, 
1.307620, 0.028670, 0.497200, -0.768450, 0.750570, 1.853810, 0.466180, 0.077970, -0.885840, 0.323970, 
0.503910, 0.506130, -0.141620, 0.271590, 0.124000, 0.078010, 0.027220, -0.274780, -0.471500, -0.908270, 
-0.839660, 0.248860, -0.632800, 0.773050, -0.045900, 1.572670, -0.261940, -0.363330, 0.363790, 
-0.334350, 0.241220, -0.931910, -0.195120, 0.247070, -0.201320, -0.013970, -0.517270, -0.621060, -0.256090, 
-1.481990, 1.227700, 0.032870, 0.782520, -0.296540, -0.620500, -0.901330, 1.668090, 0.460560, -0.193590, 
0.671140, 0.382750, -0.671350, -0.153200, -0.570390, -0.318890, 0.618630, -0.900830, 0.222560, -1.061780, 
0.058070, 0.582200, -1.386420, -1.689480, -0.284020, 0.348160, 0.661870, 0.032620, 0.348060, 0.682650, 
0.586120, 0.760860, 0.377240, 0.307530, -0.636810, -0.756280, -0.666760, -0.655720, -0.054120, -0.373380, 
-0.869750, -0.514120, -0.286590, 0.089100, -1.335420, 0.555200, 0.752480, -0.876860, 0.674300, 0.265950, 
0.264040, -0.894680, -0.706400, 0.002720, 0.908120, 0.712970, 0.084280, -0.035300, -0.327520, 0.529710, 
0.580260, 0.325940, -0.133230, -0.913540, 1.464930, 0.628590, -0.968090, -0.226990, 0.173360, 1.367180, 
0.594880, -0.031290, -0.008150, 0.513700, -0.309490, 1.334530, 1.373160, -0.620830, 0.177490, 0.212210, 
-0.419530, -0.282660, 1.165400, -0.435530, 0.133400, -0.251650, 0.472370, -0.173580, 0.434420, -0.132220, 
-0.618550, -0.005860, 0.719810, -0.521540, -0.507020, 0.672100, 0.745790, 0.907500, -0.986760, -0.447320, 
-0.279380, 0.246660, -0.425660, 0.986850, -1.287590, 0.029440, -1.454610, -1.192890, -0.675200, -0.987560, 
-0.079410, 1.990990, 0.002810, -0.041740, -0.658280, 0.347210, 0.685710, -0.965910, -0.216630, -0.618420, 
-0.117440, -1.246240, -2.016610, 0.179480, 1.547410, -2.536370, -0.982180, -0.522930, -2.090170, -0.126550, 
-1.363530, 1.122770, -0.863250, -0.769360, 0.849640, -1.039820, -0.004740, -0.821380, -0.746940, 1.233870, 
-0.569910, -0.962770, -0.656270, -1.084800, -0.530220, -0.728330, -0.680520, 0.054790, 0.097150, -1.085350, 
0.258510, 0.950230, -1.164100, -0.413090, -0.616160, 1.215640, 0.178150, -1.090400, 0.074630, 0.142800, 
-0.410260, 0.137710, -0.007350, 0.625310, 0.415420, -0.260590, -0.009640, 0.192350, 0.498280, -1.059110, 
-0.179280, 1.533680, 0.545200, -0.763390, -0.515490, -0.289850, 0.864190, -0.251120, -1.057410, -0.549360, 
-0.169850, -0.326580, 0.412100, -1.112220, -0.153550, 0.514430, -1.190820, 0.196220, 1.026410, 0.430020, 
-1.619620, -0.285090, 0.267640, -0.405060, 1.345810, -0.501740, -1.113020, -0.817240, -0.592190, -0.394890, 
-0.263350, 0.580830, 0.006790, 0.115870, 0.375660, 0.133570, -0.884930, -1.229810, -0.016340, -0.161590, 
0.552730, -0.788110, 0.613910, 0.726640, -1.113120, 0.427680, -0.467070, 0.113240, -0.197540, 0.552150, 
-0.830850, 0.554320, 0.002760, -0.808860, -0.250110, 0.367250, 0.278590, -1.044320, -0.960650, -1.017420, 
1.420770, -0.194410, 0.134920, 0.160140, -0.538820, -0.525460, -0.078460, 1.475830, 0.369970, -1.482540, 
0.709640, 0.636940, 0.448090, -0.524090, -0.437190, 0.476530, -0.277290, 0.491600, -0.564800, -0.807300, 
-0.646960, 1.070660, 1.298040, 1.032230, -0.432280, -0.059770, 1.159420, 0.731190, -0.595330, 0.022630, 
-1.316020, 0.028020, 0.335290, -0.496800, 0.465540, 1.393210, -1.059550, -0.195620, 0.128000, 0.048460, 
-0.173670, -0.780540, -0.052200, -0.045290, -0.242770, 0.248360, -0.617840, 0.324970, -0.795400, 0.210650, 
0.299930, -0.122580, -0.486570, -1.314820, 0.859230, 0.418480, 0.548500, -0.628760, -1.262890, 
0.668310, 0.471040, 1.344380, -0.026190, -0.077100, -0.799420, -0.263480, 0.511020, 0.283220, -0.289810, 
-0.186550, -0.118980, 0.197220, -0.971500, 0.521530, 1.108280, 0.924530, -0.993190, -0.936820, 0.582360, 
0.937480, 0.127000, 1.473990, -0.327040, -0.035340, -0.682410, 0.847570, -0.239400, -1.403090, 0.473260, 
-0.289850, 0.965080, 0.000820, 0.529810, -0.266260, 0.499930, 0.211100, -0.802780, 0.934600, 0.122910, 
-1.019410, 0.219180, -0.288940, -0.693280, -0.225370, -0.886080, 0.455110, -0.458390, -1.440030, 0.726910, 
1.278690, -0.080440, -0.876580, 0.794680, 0.451380, -0.393420, 1.477340, 0.141310, -0.800210, 0.161310, 
-0.460270, 0.460390, -0.545480, -0.246650, 0.274500, -0.739120, 0.430780, 0.347830, 0.784170, -1.237180, 
0.477450, 0.546790, 1.538240, 1.333390, -0.618320, -0.127710, -0.323620, 0.175800, 1.476880, 0.023280, 
0.245450, 0.288910, 0.241310, -0.881220, -0.047880, -0.045110, 0.590290, 0.962180, -0.127020, 0.377000, 
-0.751840, 0.966570, 1.083770, -0.710560, -0.257640, 1.424260, 0.657630, -1.111420, 0.323510, -0.045510, 
0.282690, 0.642330, -1.252880, 0.665500, 0.925000, 0.062920, 0.985640, 0.515310, 0.317920, 0.081640, 
0.675010, 0.340400, 0.520440, 0.488390, -0.392870, -0.597680, -1.785550, 0.360000, -0.308900, -1.656960, 
-0.728770, -0.196170, -1.150140, 0.366110, -1.153160, 0.964660, 0.693310, -0.788760, 1.242720, 0.611750, 
-0.941430, -1.083830, -0.041950, 0.591740, -0.482660, -2.179340, 1.200150, -0.383000, -1.469160, -0.762720, 
-0.496790, 0.562210, -0.898680, -0.087190, -0.377460, -0.633630, -1.420550, 0.041070, 0.979230, -0.315680, 
-0.396780, 0.601370, 0.067120, -0.762050, -0.228930, 0.369570, 0.529870, -0.175680, 0.187960, -1.074820, 
1.185870, 0.229020, 1.240100, -0.555550, 0.363530, -0.939280, -0.984510, 0.866010, 0.528970, 0.448410, 
0.298880, 1.245410, -1.093970, 1.295590, -1.006800, 0.054300, 0.207790, 0.481600, -0.169390, -1.017900, 
-0.375200, 0.092280, 0.372870, -0.664540, -0.511480, 0.389340, 0.365120, -0.367610, 0.633670, 0.769230, 
0.734060, -0.258720, 1.007370, 0.250650, -0.046290, -0.005560, -0.209920, -0.278610, -1.150490, -0.435520, 
-0.087190, -0.132010, -0.844720, -0.651470, -0.901310, 0.273210, 0.367660, -0.891630, -1.478150, 0.298150, 
0.093040, -1.252120, -0.665900, 0.378270, 0.080420, -0.958000, 0.225100, -1.037510, -0.032370, -0.925430, 
0.758620, -0.352380, -0.001420, 1.051940, -0.788310, -0.331820, -0.728430, 0.006370, 0.900460, 0.429400, 
0.765400, -1.341890, 0.222060, -0.552830, 0.961070, 0.678870, -0.595840, 0.171740, 0.600240, -0.246160, 
0.689340, -0.260630, -0.750880, 1.027890, -0.097660, 0.097370, -0.517640, -0.911690, 0.124360, 0.421190, 
1.647150, 0.102840, 0.378960, -0.690470, 0.203520, 0.244150, -0.691130, -0.384280, -0.710850, 1.269830, 
0.389270, 0.384630, -0.953960, 0.080640, -0.208240, -1.568340, 0.188490, -0.297400, 0.492160, -0.924440, 
0.164570, -1.574140, -0.036890, -0.495800, 0.061660, -0.440450, -0.319920, 0.851300, -0.010680, 0.019070, 
-0.627020, -0.110460, 0.067080, 0.115470, 1.353240, 0.147240, -0.892000, -0.291000, -0.149110, 0.133240, 
-0.961140, 0.933710, 0.106850, 1.084290, 0.040580, -0.362680, -0.021230, 0.295220, -0.695380, 
0.196430, 0.058340, -0.679230, 0.782310, 0.752620, -0.077380, -0.137080, -1.049950, -0.610940, 0.308430, 
-0.540760, 0.825750, 0.878630, 0.897220, -0.563020, 0.701010, 0.990030, -0.199570, -0.031540, -0.365750, 
0.638030, 0.106580, 0.655390, 0.216700, -1.223960, -0.382970, -1.032930, 0.248200, 0.304030, -0.046860, 
0.229260, 0.312740, -1.005320, 0.738840, 0.559980, 0.323980, -1.053460, 0.562600, -1.715700, 0.593560, 
-0.969110, 0.240150, -1.300240, -0.187320, 1.383550, 0.219130, -0.465450, -0.381420, 0.482200, 0.704630, 
1.308160, -1.728190, -1.646990, -1.185100, -0.343430, -1.222260, 1.259010, 0.563270, -0.500920, 1.156080, 
-0.948220, 0.543010, 0.521470, 0.421650, -0.054950, -0.786890, 1.678860, 0.781340, -0.007510, -0.062090, 
-0.277670, 0.492650, 0.722980, -0.810290, -0.728880, -1.480710, -0.966930, -1.120840, -0.701070, 0.408380, 
0.267890, 1.198780, 0.600050, 0.520300, -0.732160, 0.478880, 0.034490, 0.003320, -0.535030, 1.063280, 
0.824000, 1.738580, 0.269720, -0.201500, 0.011370, 0.050000, 0.173110, -0.158460, 0.464960, 0.601430, 
-0.844220, -0.010010, 0.188760, -1.163640, -0.504280, -0.876710, -0.121710, -0.517510, 0.309960, 0.888330, 
0.274640, 0.634890, -0.014040, 0.459400, 1.537520, -0.870600, 0.348490, 0.367180, 2.130140, -1.198340, 
0.205520, 0.998170, 0.311030, 0.846980, -0.791430, 0.589780, 0.168440, -1.067270, 0.404580, 0.007090, 
0.484400, 0.617860, 0.033090, -1.464610, 0.449980, -0.757610, 0.744700, -1.298220, -0.108370, -0.470260, 
-0.242020, 0.318780, -0.369540, 1.319490, 0.081260, 0.353830, -0.271660, 0.674250, 0.405760, 0.913450, 
-0.353000, -0.386050, -0.909960, 2.179280, 0.013030, 0.561360, 0.810390, -1.245900, 1.447100, 0.561300, 
0.802700, -0.459160, 0.411710, -0.849010, 0.156840, 0.150570, 0.357120, 0.766850, -0.806960, -0.112340, 
-1.021130, 1.597170, -0.657830, 0.042350, -0.100680, -0.092790, 0.007440, 0.609890, 0.160920, -0.349030, 
0.497180, 0.853380, 1.770800, 0.093480, -0.551960, 0.328940, -0.419660, -0.417620, 0.671320, 0.232700, 
0.560600, -0.355510, -0.649680, -1.488850, -0.325230, -1.324090, 0.496760, -0.278750, 0.124150, 0.858800, 
-1.291070, 0.225310, -0.765660, -0.035390, 1.035640, 0.258600, 0.722480, -0.501820, -0.905430, 0.401590, 
1.082030, 0.404490, 0.015430, 0.760040, 0.183610, -0.287010, -0.874330, 0.828660, -0.896890, 0.679520, 
-0.492010, 1.252400, 0.329000, -1.123720, -0.179460, -0.953020, -0.828030, 0.062860, -0.761390, 1.031940, 
1.485030, 0.608930, 0.185360, 0.561530, 0.477760, 0.064660, -1.375430, 0.051680, 1.273600, 0.599630, 
-0.755600, 1.062890, 1.051010, -0.861130, 1.048980, -0.331070, 0.245920, -0.781670, -0.488430, 0.016390, 
0.792330, 0.469530, -0.010310, 0.234050, 0.362310, -0.478750, 0.111480, -0.106160, 0.551830, -0.288740, 
-1.342850, 1.577810, 0.303180, -0.114170, -0.822230, 0.677210, 0.475760, 0.434100, 0.000620, 1.697880, 
0.908900, 0.565810, -0.884790, -0.348470, -0.865980, -0.701760, -0.196510, 0.288170, -0.090250, 0.087940, 
0.495950, -0.399280, 0.496650, -0.597800, -0.793080, 0.404610, 0.142140, -0.429930, 0.329940, -0.843870, 
1.301530, 1.142970, 0.533320, 0.067510, 0.317940, -0.966710, -0.090930, 0.302760, 0.187900, 
-0.202700, -0.820550, 0.957200, -0.901770, -0.740690, 0.010710, -0.337100, -0.013870, 1.136250, -0.457750, 
0.222670, 1.177000, 0.096750, 0.649360, 0.604760, -0.582930, 0.175870, 1.843420, -0.166580, -0.709260, 
0.358680, 0.743550, -0.736450, 0.997170, -0.402390, -0.251390, -0.759900, 0.527650, -1.355060, -0.138660, 
0.416880, -0.791530, -0.032960, 0.257450, 0.360750, -0.247270, -0.110860, 0.369430, -0.167790, -0.019500, 
-0.052210, 0.580200, -0.732910, 0.284710, 0.717940, 1.294010, 0.040080, 0.477800, -0.932630, -0.000430, 
0.695580, -0.788600, 0.735490, 1.093620, -1.215930, -1.845360, -0.618760, 2.104540, -0.491090, 1.176720, 
-0.848210, -1.088970, -0.534400, -0.478550, -0.540850, 0.033660, -0.121890, 0.321710, -0.502080, 0.082480, 
-1.251550, -0.235850, -0.734040, -0.636590, -0.504210, 1.190110, 1.362700, -0.268030, -0.513310, 0.744190, 
0.220830, -0.583160, 1.504680, 0.263780, 0.616010, 1.036200, -1.063480, 1.001560, 1.049440, -0.103470, 
-0.884230, -0.581110, -0.670950, -0.147480, 0.350760, -0.768320, 0.150270, 0.612210, -0.144420, 1.047220, 
-0.195270, 1.069060, 0.904560, -0.600780, -0.950440, 0.510930, 0.996640, 0.008530, -1.105210, 0.341790, 
0.020540, -0.618670, -1.784510, 1.883420, 0.972510, -0.507220, -1.471050, 0.634000, -0.524240, 0.546200, 
-1.128110, 0.172750, -0.823530, -1.055230, 0.038950, 0.843320, 1.029330, -0.166390, -0.564360, -0.496140, 
-0.046930, 0.391410, -0.507900, 0.268930, -0.215230, -0.006260, 0.642670, 0.738490, -0.743190, -0.763730, 
-0.026110, -1.174550, -0.223720, -0.261240, -0.533270, 0.326300, -0.657110, -1.207430, -0.584670, -1.558360, 
0.590780, -0.071790, -0.253140, -0.272480, 1.203740, -0.885540, 1.472430, -0.954000, -1.520550, 0.645890, 
0.658630, -0.660080, 0.798540, 0.056990, 1.036680, -0.037030, -0.235000, 0.228110, -0.484350, -0.763130, 
-1.624040, -0.304460, 1.092850, 0.319040, -0.227110, 0.851520, 0.956470, 1.002820, 0.431610, 0.104180, 
-0.034840, -0.067600, 0.780920, -0.044730, -0.870370, 0.729170, 0.121470, -0.530120, 0.182680, 0.815590, 
0.627560, 0.465520, 0.528190, 0.806200, -0.077470, -0.014720, 0.572990, -0.967380, 0.273200, 0.688500, 
0.394780, 0.122890, 0.874470, 0.036920, -0.501850, -0.408910, -0.500730, -0.366880, 0.614720, 0.195590, 
1.093620, -0.026500, -0.303700, 0.610760, 0.767960, -0.858760, 1.100970, 1.485760, 0.338960, 0.435130, 
-0.236180, 0.949910, 0.641430, -0.528870, -1.459840, 0.814080, 0.864160, 0.551360, 1.687260, -0.043630, 
0.645940, -0.099510, 1.118240, -0.301960, -0.493830, 0.613490, 1.183090, -0.746590, 0.048780, -0.834250, 
-0.254070, -0.531990, 0.145080, 0.524360, -0.115420, 0.369340, 0.847750, -0.452330, 0.769090, -0.135900, 
-0.823500, -0.161100, -0.617990, -0.334720, -0.121970, -0.085630, 0.905330, 0.901740, 0.672110, 0.460550, 
0.995270, -1.135990, 0.235930, -0.737490, 0.509690, -0.587180, 0.204830, -0.069620, -0.310160, 0.296690, 
-0.717840, 0.575810, 0.747880, 0.584370, -0.554910, -0.682380, -1.039900, 0.328970, -0.067750, 0.524270, 
0.970990, 0.882180, -0.780830, -0.091180, -0.997260, -0.445520, 1.167880, -1.748900, 0.257970, -0.396780, 
-0.957860, -1.127960, -0.843380, 0.158590, -0.177340, -0.046570, 1.050390, -0.883950, -0.503350, 
-0.085410, 0.605410, 0.658630, 0.313890, 0.721590, -1.375840, -0.413830, 1.148970, -0.223310, -0.087180, 
0.271900, 0.648840, 0.594840, 0.210200, 0.180720, 1.383500, 0.510440, -0.284790, -1.351530, -0.416060, 
-1.116250, -0.597370, -0.449860, 0.346880, 0.257120, -0.370670, 0.235350, -0.092660, -0.836990, 0.188490, 
-0.541590, 1.205760, -0.339940, 0.290350, 1.119460, 0.876030, 0.640760, -0.146050, 0.234770, 0.518940, 
0.173200, -0.120430, 0.156580, -0.342160, -0.033310, 0.029090, 0.344380, 0.039330, 0.295030, 1.119280, 
-0.645070, 0.280710, -0.972260, 0.691690, 0.942500, 0.361660, 0.583310, -0.173940, 0.877330, 0.698670, 
-0.516910, -0.699080, -0.663680, -1.185460, 0.458390, -0.215010, -0.437550, 0.692760, -1.459710, 0.965930, 
1.117280, 0.018470, -1.182090, -1.645510, 0.228030, 0.289760, -0.285360, -0.652440, -0.692050, 1.131670, 
0.202620, -0.554240, 1.201900, -0.184040, 0.224820, 0.795600, -1.180170, -0.013350, -0.405700, 0.383430, 
0.579420, -0.647700, -0.079220, 0.941590, 0.898630, 0.864140, 1.051740, 0.460000, -0.476800, 0.612700, 
-0.179950, -0.963270, 0.338750, -1.385040, 0.507180, -0.801410, -0.107180, -1.292340, -0.071380, 0.439380, 
1.102110, -0.388160, -1.565570, 0.278120, 0.305360, 0.145690, 1.509670, 1.442490, -0.295520, 0.000820, 
0.037120, 0.624790, 1.650440, 0.884700, -1.115900, 0.044110, 0.061490, 1.324940, -1.433970, -0.011290, 
-0.747000, 0.377390, -0.364390, 0.027680, 0.304330, -0.310570, -0.100820, -0.492490, 0.689350, 0.802380, 
1.116970, 0.157560, -1.219320, 1.446840, 0.427160, 0.537110, 0.691370, 0.418860, 0.146280, 0.273520, 
-0.371620, 0.156130, -0.543810, 0.314110, 0.146450, 0.571330, -1.850930, -1.620130, 0.608120, -1.013920, 
0.439520, 0.286870, 0.756920, 0.136870, -0.780300, -0.468350, -0.854570, 0.028170, 1.054640, 1.133450, 
0.430110, -0.089510, -0.149610, -0.268120, -0.345680, 0.739040, -1.045760, -0.204720, -0.771280, -0.081470, 
-0.496080, 0.224840, -1.164290, -0.314090, -0.697410, 0.978850, -0.941080, -0.120320, 0.743580, -0.251180, 
0.133950, 0.159570, 0.877350, 1.362540, -0.292430, -0.279800, -0.424540, -0.113420, -0.018120, -0.146010, 
-1.385410, 0.912070, -0.628770, -0.910410, -1.203700, -1.008090, -0.813180, 0.163290, -0.463410, 1.225950, 
-0.211130, 0.639790, -0.238570, 1.201160, -0.738240, -0.579960, -0.078830, -0.378540, -0.644970, 0.323150, 
0.113090, 0.202000, 1.218170, -0.567370, 0.094880, 0.225940, -0.015130, -0.791350, -0.237200, 0.122610, 
1.712340, -0.121360, -1.913810, -0.659110, 0.443060, 1.047330, -0.530770, 0.586550, -0.272830, 0.221160, 
-0.139110, 0.156600, -0.839160, 0.591970, 0.756060, 0.457140, 0.141740, -0.045280, -0.493170, -0.811080, 
0.308030, -0.090970, -0.395700, -0.232420, 0.240430, -0.264200, -1.038400, -0.674300, 0.169820, 0.737290, 
0.657090, -0.873020, 0.083060, 0.837970, -0.577590, 0.531220, -0.405440, -0.227400, 0.155210, -0.441400, 
-0.059290, 1.391090, 0.211530, -0.855930, -0.233590, -0.288270, 0.910870, -1.298210, -0.643720, 0.233920, 
-0.207720, -0.121490, 1.107120, 0.726230, 0.837200, -0.108140, 0.931610, 1.083040, -0.286450, 1.090830, 
0.391680, -0.968350, -0.841420, -1.030010, -0.899080, 0.053020, 0.047610, 0.976670, 0.997300, 
-0.546430, 0.438280, 0.552360, -0.638440, -0.054280, 1.558530, 0.973690, -0.835450, 1.236950, 0.652840, 
-0.256950, 0.393860, 0.812780, 0.001680, -0.250290, -0.056390, 0.255590, 0.014100, 0.080530, -0.222800, 
-0.524180, 0.436070, -0.589250, -0.044020, 0.051330, -0.361090, 0.056330, 1.138800, 1.171910, 0.514410, 
-0.310180, -0.526300, -0.332800, 0.133040, -0.235710, -0.301080, -0.624600, -0.202910, 0.862260, -0.411280, 
0.313420, 0.905720, -0.527590, -0.696080, 0.769090, 0.741080, 0.725670, 0.427370, 0.204440, -0.767540, 
-1.235770, 0.495570, -0.503170, 0.383770, -0.243110, -0.902070, -0.616330, 0.466710, 0.509290, 0.958270, 
-1.232560, -0.289840, -1.340420, 1.381150, -0.323260, 0.075840, -0.826860, -0.052330, -0.645310, -0.981630, 
0.049850, 0.403230, 0.284830, 0.964470, 0.280070, 1.442240, -0.064800, -0.110440, 1.884660, -0.527570, 
0.195080, -1.003820, 0.149650, -0.645750, -0.413220, 0.147710, -0.272120, -0.802120, 1.128280, -0.285640, 
0.639200, -0.932900, -0.356160, -0.196120, -0.439850, 0.151000, 0.664570, -0.211280, 0.895730, 0.444080, 
0.590690, 0.775690, 0.459060, 0.104730, 0.368030, 0.129060, 0.510090, 0.020270, 0.927300, 0.088400, 
-0.514940, -0.685960, 0.184830, 0.941900, 0.241060, -0.243320, -1.513510, 1.363610, 1.465940, -0.552290, 
0.805260, 0.980190, 0.915310, -0.820510, -1.883850, 1.709450, -0.405020, -0.845410, -1.329800, -0.733560, 
-1.705830, 0.697630, -0.794970, 0.595950, -0.776290, -1.749300, 0.587710, 0.373700, -0.368710, -1.140410, 
0.472270, -0.417090, 0.452120, 0.023200, -0.371250, -0.004760, -0.083070, -0.051260, -0.007020, -1.589720, 
-0.372150, -0.348870, -0.455250, 0.753650, 0.013250, 1.150780, 0.126340, 0.098270, 0.006060, 0.588370, 
0.681650, 0.411950, -0.031640, -0.165590, -0.930850, 0.474820, 0.259740, -0.772270, 0.552980, 0.936970, 
-0.609220, -0.576330, 0.171170, -1.409390, -0.504100, -0.666950, 0.034330, 0.704990, -0.938640, 0.740490, 
0.786800, 0.101210, 1.120410, 0.813540, -0.993070, -1.060890, -0.326660, 1.443090, -0.593880, -1.397200, 
0.891290, 0.929190, 2.075280, -0.360640, 0.531950, 1.083400, -0.052430, 0.270850, -0.392140, -0.824810, 
-0.115870, 0.252320, 1.156450, 0.447780, 1.604070, 0.264190, -0.947880, -0.350390, -1.106940, -0.512610, 
-0.327810, 0.501260, -0.720440, 0.842320, 0.186070, -0.102010, 0.508990, 0.408930, -0.885810, 1.045900, 
-0.515520, 0.031490, -1.242290, -0.125740, -0.793660, 0.510250, -1.063730, -0.411250, -0.441260, -0.397200, 
-1.060160, 0.274840, -0.945800, -0.079560, -0.224270, 0.498550, -0.015440, 0.482840, 1.153230, 0.426390, 
-1.215550, -0.038620, 0.055850, -0.879880, 0.339530, 0.445840, 0.184430, -0.382200, -0.110690, -1.140590, 
0.220330, 1.425930, -0.150850, 0.091040, 0.357270, -0.226240, -0.395180, 0.527310, -0.630540, 1.851560, 
-0.292420, 0.419880, 1.817290, 2.229260, -0.108820, 0.128620, 0.640690, 0.101480, -0.174560, 0.211180, 
0.199190, -0.345520, 0.643170, -0.005020, 0.112920, 0.426350, -0.444090, 0.179600, 1.165350, 0.344930, 
0.207280, -0.101760, -0.346700, -0.107660, 0.123560, 0.060540, -0.171160, -0.841820, 0.225940, 0.221880, 
-0.745420, 0.360750, 0.504080, -2.074350, -1.349230, 0.546290, -0.416160, -0.509900, -0.767410, 
0.359820, -0.126780, -0.492680, 0.554590, -0.755730, -0.587220, -0.305130, 0.867130, 0.194380, -0.249480, 
0.310970, -0.156230, -0.505450, 0.015370, 0.527100, 0.639960, 0.100140, 0.786560, -0.275860, -1.093220, 
0.657040, 0.960000, 0.962980, -0.151690, -0.832990, -0.895860, 0.333140, -0.650550, -0.171800, -0.618190, 
0.863030, -0.345760, -0.627440, 0.230500, -0.605310, -0.436970, -0.171770, 0.049680, -0.172940, -1.309670, 
0.636740, 0.153930, -0.465820, -0.183520, 0.098750, -0.034420, -0.562020, -0.319850, -0.379690, -1.031290, 
-0.589050, -0.135520, 0.959020, -0.613300, 0.778520, -1.220840, -0.565910, -0.387280, 0.670050, -0.326050, 
0.521220, -0.808750, -0.063910, 0.343880, -0.115590, 0.000980, 0.745850, 0.216100, -0.533400, -0.294630, 
0.224530, -0.332740, -0.789670, -0.040050, -0.495400, 0.136220, -0.578690, 0.332450, -0.674030, -0.939550, 
-0.728800, 0.377160, -0.073620, -0.122220, 0.015100, 0.475620, 0.861780, -0.184580, -0.423670, 1.404120, 
1.409750, -0.206800, 0.328720, -0.227210, 1.161430, -0.530450, -0.353720, -0.532450, 0.215130, 0.848940, 
0.520880, -0.787260, 0.319900, -0.013150, 0.203630, 0.006810, 0.267110, 0.703820, 0.328410, 0.584600, 
-0.408100, -0.230970, 0.826580, -0.203330, -0.701840, 0.199760, -0.809810, -1.716980, 2.075730, -1.181000, 
-0.956270, 1.578520, 0.529530, 0.096230, 0.469310, 1.741000, 0.767310, 0.563150, -0.509900, -1.557880, 
-0.120040, -0.077030, -2.501340, 0.814570, 0.616500, -4.584250, -1.944900, 0.444070, 0.614690, 0.629920, 
0.650760, -0.246100, 0.821610, 0.334380, 0.153450, 0.504440, -0.040580, 0.363060, 0.112360, 0.272590, 
1.186400, -0.246390, -0.344940, -0.413370, 0.167660, 0.076530, -0.512390, 0.089390, 0.933740, 0.378530, 
-0.263900, 0.608050, 0.516530, -1.334070, -0.137620, -0.575920, 0.484030, 0.559430, -0.870420, 0.827440, 
-1.343860, 0.443980, 1.426980, -0.844260, 0.539690, 0.338070, 0.120970, 0.435850, 0.018660, -0.190440, 
0.223540, 1.119210, -1.848160, 0.510740, 0.094020, -0.430470, -0.652720, -0.387130, -0.881200, -0.215670, 
0.083170, -0.575150, 0.608940, 0.122260, 0.361960, -0.064390, 0.321380, -0.395770, 0.774730, -0.730430, 
-0.690860, 0.762240, 0.352670, 0.230370, 0.207400, -0.900300, -0.702640, 0.887430, 0.559880, -0.460330, 
0.532810, 0.194640, -0.730470, 0.124520, -0.844500, 0.057800, -0.452610, 0.156450, -0.157500, 0.375710, 
-0.323360, 0.552760, -0.075940, 0.081930, 0.010440, 0.343660, 0.193200, 0.621620, -0.711620, -0.903650, 
-0.205290, 0.305850, -0.495830, -0.770470, -0.002960, -0.065080, -0.093630, 0.172410, 0.353990, -0.238890, 
0.456440, -0.726180, 0.045880, 0.534270, -0.254750, -0.056620, -0.885020, -0.369250, -0.003800, -0.571730, 
2.795860, 1.601160, 1.027300, -0.182100, 0.093110, -0.380790, -0.081450, -0.066860, -0.200630, -1.194570, 
0.215390, 0.763930, -0.864990, 0.320190, -0.839110, 0.266660, -0.520890, -0.864260, 0.151920, -1.142930, 
-0.312390, -1.037510, -0.124400, -0.725070, -0.706020, 0.359590, -0.875120, -0.583040, -0.485600, -0.554070, 
-0.517900, -0.187520, -0.190620, 0.313140, -1.038990, -0.613220, 0.012940, -0.007320, 0.035540, -0.239700, 
-0.899990, -0.725460, -1.157270, 0.295340, 0.357500, 1.119950, -0.087280, -0.684980, -0.551460, 
0.212920, 0.495810, -0.643990, 0.133940, -0.113730, -0.625930, 1.419330, -0.430080, 0.451270, 0.969570, 
1.728930, 0.815480, -0.433730, -0.392660, 1.140560, -0.157160, 1.176340, 0.329640, -0.871140, -1.478990, 
0.205330, -1.014720, -0.180060, -0.573920, 1.398030, 1.024160, 0.822660, -1.054300, 0.824210, 0.760860, 
-0.285060, -0.591850, 0.616150, -0.868530, -1.043690, -0.002570, 0.002340, -0.946330, 0.530490, -0.233050, 
0.741810, 0.396660, 0.000220, 0.570720, 1.687560, -0.605710, 0.135380, -2.332850, 0.739230, 0.055660, 
-0.756350, -0.109070, 0.072050, 0.894690, 1.025850, 0.198630, -1.096510, -1.525160, -0.170000, -0.215480, 
-0.902170, 0.708350, -0.028750, -1.540360, -1.103270, -1.055660, 0.770500, -0.179290, 1.570940, -0.488800, 
-1.497360, 0.958860, 0.920890, 0.123910, -0.213090, 0.320980, 0.757010, -0.284450, 0.717180, 1.275180, 
-0.462550, -0.621610, -1.105720, -0.849470, -0.014090, 1.258800, 0.904740, 0.329900, 0.363120, 0.071640, 
1.019810, -0.408070, -0.577120, -0.603250, -0.412740, 0.839790, -0.013400, 0.084370, 0.841080, -0.271940, 
0.065320, 0.013450, 1.170520, 0.729920, 0.079670, -0.701990, 0.016680, 0.411560, -0.585470, 0.459620, 
0.135370, -1.179770, 1.488380, 0.923680, 0.729730, 0.140740, -0.893560, 0.247340, -0.072850, -0.045580, 
-0.056440, -0.094060, -0.488070, -0.656350, -0.902780, 1.118140, 0.750160, -0.205450, 0.551590, 0.753180, 
0.408040, -0.008040, 0.143600, -0.341400, -0.570210, 1.338830, 0.799390, -0.357350, -0.467010, 0.340290, 
0.706120, -0.814510, 0.130670, -0.227410, -0.590720, -0.075820, 0.881780, 1.100340, 1.463430, 0.506660, 
-0.517100, 0.880830, -0.052400, 1.662420, -0.919320, -0.782900, -0.243250, 0.158120, 0.262200, -0.436870, 
0.948160, 0.682810, 0.810990, -0.692740, -1.819450, -0.516650, -0.485240, -1.148670, 0.928760, 0.515640, 
-0.363670, 0.659380, -0.916970, -0.547610, -0.341950, 0.342120, 0.405730, -0.369990, -1.159190, -0.941400, 
-0.466390, -0.337580, 1.487870, 0.023510, 0.324550, -0.034880, 0.814750, -0.447480, -0.426090, -0.142190, 
-0.801890, 0.332580, 0.100030, 0.557390, -0.142850, 0.181760, -0.860860, -1.258520, -0.172400, 0.560240, 
0.231860, -0.781120, 0.339760, 0.659610, 1.018710, 0.720530, -0.178290, -0.043440, -0.925010, 0.904050, 
0.141250, 0.524100, -0.377460, 0.598400, 1.379240, 0.453840, 0.559530, 0.464020, -0.029650, 0.574780, 
0.059800, 0.932100, 0.401350, -0.913540, -0.467010, 0.115230, -0.031700, 0.746410, -0.727770, 0.420980, 
0.733000, -0.100750, -0.911090, -1.252590, -0.246880, -1.084290, 0.011140, -0.363240, -0.717720, -0.804470, 
0.887770, -1.316040, -0.446660, 1.523110, -0.116030, -0.208050, -0.163350, -0.897290, -0.731290, 0.507550, 
-0.698410, 0.753020, -0.031010, 0.165420, 0.961420, -0.358400, -1.292490, 0.026620, -0.441510, -0.162700, 
1.482240, 0.121120, 0.877570, -0.253470, -0.488570, 0.640100, -0.185820, -0.041190, -0.003250, 0.991930, 
-0.758000, 0.207630, -0.751790, 0.317780, 0.169300, 0.413780, 0.037820, -0.637140, -0.211490, 0.263570, 
0.225720, 0.105600, 0.525210, -0.863170, 1.173080, -0.922270, -1.102670, 0.142880, 0.329950, -0.075530, 
-0.855660, 0.376000, -0.207440, -0.207130, -0.130400, 0.204760, 0.144070, -0.854850, -0.189960, 
-0.173360, -0.449370, 0.493570, -0.774600, 0.919990, 0.504220, -0.844250, 0.121340, 0.051690, 0.083950, 
0.872520, 0.915740, 0.200680, 1.259200, 1.734850, -1.095200, 0.864020, -0.243950, -0.695870, -0.989300, 
-0.502820, 0.631320, -0.372880, 0.515570, -0.028390, 0.473320, 0.229130, -0.074490, 0.658950, -1.023060, 
0.229630, -0.824960, 0.065830, -0.319210, -1.054960, 1.140810, -0.107840, -1.166400, 0.046630, -0.301710, 
-0.397650, -0.903720, -0.234170, 0.216630, 0.165830, -1.196020, 0.900560, -0.699280, -1.043400, -0.046890, 
0.293800, 0.658560, 0.192750, 0.079190, -0.142720, -0.133760, -1.168250, -0.652100, 0.290880, 1.874760, 
0.359800, -0.516370, 0.114000, -0.995260, -0.194230, -1.114130, 0.129650, -1.179900, -1.395740, -0.704040, 
0.233030, 0.262520, 1.074730, 0.627040, -0.254150, -0.348510, -0.079510, -1.349000, 0.502940, -0.734620, 
-0.491830, 1.756710, -0.716950, 0.054400, 0.456280, -0.554480, 0.954700, 1.464530, 0.232130, 0.102910, 
-1.396440, 0.662040, 0.798470, -0.488740, 0.494830, 0.038610, -0.077520, -0.288860, 1.116930, 0.295910, 
1.055710, 0.238140, 0.491530, 0.178860, 0.931530, -0.592520, -1.288490, -0.719250, -0.986540, -0.763370, 
-0.401040, 1.128130, 0.825970, -0.555560, -1.030490, -0.077310, 0.549810, 1.445550, -0.116800, 1.677530, 
0.149410, -1.123430, 0.729070, 0.695840, 0.840000, 0.625180, -0.760340, -1.680290, -2.175550, 0.882100, 
1.775850, 0.557120, 0.898150, -0.580270, -0.439580, 1.173240, 1.473410, 0.596240, 0.096080, -1.744920, 
-0.726920, 0.149210, -0.831310, -0.441160, -0.981750, 0.206130, -0.918170, 0.210780, 0.500550, -0.960690, 
0.389280, -0.190060, -0.251420, 0.469290, 0.029360, 0.545410, -0.756090, 0.325910, -0.535330, -0.009300, 
0.834310, -0.791180, -0.299230, -0.260090, 0.257730, -1.445840, 0.357240, -0.509850, -0.126070, -0.571150, 
-1.207230, 0.101140, 0.779110, 0.240920, -0.245490, -0.327200, -0.570550, 0.182360, -0.551370, 1.201160, 
-0.004330, -0.780770, 0.760280, 0.612720, -0.163580, 0.490950, -0.470520, -0.908820, -0.767070, 1.616370, 
-0.308780, 0.827940, 0.266860, -0.614120, 0.267350, -1.226710, -1.503580, -0.867180, 0.191840, -0.288560, 
-0.692280, -0.693780, -0.662960, -0.475900, 0.939660, -0.367390, -0.400780, -0.310420, -0.946420, 0.302640, 
0.704350, 0.755360, 0.670410, 0.692020, -0.598790, -0.513530, 0.197270, 0.975940, 0.308410, -0.549830, 
-0.563430, 0.770310, 0.293750, 0.452860, -0.250820, 0.502660, -0.272890, 1.091430, -0.639770, -0.124740, 
0.253260, -0.889100, 0.647960, 0.200990, -0.737160, -1.032500, 0.536920, 1.047250, 1.080230, -0.885160, 
-0.580080, -0.019600, 0.540220, -0.486480, 0.748440, 0.704810, -0.279980, 0.553400, -0.997380, 0.492880, 
0.142610, 0.200170, -0.574210, 0.377270, 0.454440, 0.387230, 0.483830, -0.201290, -0.417070, -1.428270, 
-0.398320, 0.893640, -0.466960, -0.249390, -0.811410, 0.493520, 0.305530, 0.305890, 0.486560, -1.607100, 
-0.481510, -0.325350, 0.733340, 0.991080, 0.561010, -0.262810, -0.602260, 0.746190, 0.490030, 0.533020, 
-0.814390, 1.011970, -0.687310, 0.282270, -0.671880, -0.336350, 0.198590, -0.023170, 0.921710, -0.404810, 
-0.338090, 0.182840, 0.548080, 0.656400, -0.338900, -1.308100, -0.444410, 0.157330, 1.037880, 
-0.819170, -0.161530, 1.003300, -0.160060, -0.581770, -0.407470, 0.242470, 0.474760, 0.384190, 0.526220, 
-0.202150, -0.751490, 1.194580, -1.099140, 0.037560, -0.188320, 0.169160, 0.889400, 0.692230, -0.745880, 
-1.404180, -0.689710, -0.103860, -0.646710, 0.308690, 0.793110, 0.506850, 0.336330, -0.074830, -0.326680, 
-0.516900, 0.460120, 0.056780, -0.166600, 0.744580, -1.169850, -0.970120, 1.067860, 0.324050, -0.674390, 
0.076170, -0.101980, 0.958150, -1.106600, -0.523580, 1.855960, 0.224980, 0.542650, -0.108750, -0.389780, 
0.117600, -0.532740, -0.334080, 1.888160, -0.121890, 0.254670, 0.618270, 1.438220, 0.091500, -0.397250, 
-1.299320, 0.144340, -1.142820, 0.806600, -0.718930, -0.810750, 0.560250, -0.345150, 0.143680, 1.170280, 
0.026250, -0.517700, 1.325840, -0.698370, 0.436460, -0.361500, 0.817140, -0.482720, -0.835930, -0.727800, 
0.860770, 0.038730, -1.292870, 0.827430, -1.064010, -1.168490, -0.078250, 0.550750, 0.619960, 0.076010, 
-1.100690, 0.015110, -1.488740, 0.833800, 0.809720, 0.897380, -0.893740, 0.465140, 0.223720, -0.541010, 
0.395480, -0.299430, 0.109120, -0.313580, -0.506100, -0.453130, -0.148280, 0.727600, -0.128250, -0.440300, 
0.935850, -1.587030, 0.242130, -0.640450, 0.006550, -0.110340, 0.403050, 1.017090, -1.045960, 0.783920, 
-0.831300, -1.428130, -1.140300, 1.951280, 0.145970, 0.850010, -0.662140, -0.104580, -1.061140, 0.770140, 
-0.508570, -2.119850, 1.429670, -1.517210, -0.179810, -0.124490, -0.612540, -0.820020, -0.725190, -0.407330, 
1.412480, 0.006760, 0.474380, -0.096960, -1.885510, 0.000580, -0.330940, 0.203210, 0.206490, 0.555400, 
-0.084670, 1.426950, 0.751720, 0.373560, -0.746860, 0.143910, 0.558720, 1.505980, 1.265610, -1.112940, 
0.166070, 0.574450, 1.299460, 0.601910, -0.253680, 0.084390, 0.857210, -1.300150, 2.316290, -0.246930, 
-0.636440, -1.333360, 0.111260, -0.651650, 1.031530, 0.583160, -0.553680, -1.572840, 0.425720, 0.990360, 
0.283910, 1.281340, -0.346020, 0.113960, 0.766850, 0.359660, -0.924100, -0.784350, -0.034190, 0.228300, 
0.829180, 0.077140, 1.171980, 0.675990, 0.131090, -0.709960, 0.014150, 1.202710, 1.180260, 0.138740, 
0.233240, -0.382280, -0.574490, 0.180570, 0.101340, -0.256510, -0.246940, 0.353800, 2.165370, -0.982450, 
0.244730, 0.925880, 0.167650, 1.223650, -0.010570, 0.360130, 0.368460, 1.498510, 0.416210, -0.684560, 
-0.919900, -0.080760, -0.289820, -0.063640, -1.545770, -0.228340, -0.255470, 0.176480, -1.354450, 0.111420, 
-0.344280, 0.765660, 0.232060, -1.209670, 1.007930, -0.258610, -0.391790, 0.133870, 0.273740, 0.328640, 
0.666500, 1.060640, 0.187420, 0.048980, -0.318220, -0.070120, -0.052370, 0.108670, -0.672080, -0.954390, 
-0.349210, 0.790290, -0.524890, -0.346140, -0.290390, 0.981570, -0.439940, 0.240480, -0.754320, -0.861870, 
-0.952570, -0.807940, -1.757380, -2.212900, -0.653440, 0.162760, 0.050770, -0.064300, 0.139170, -1.002580, 
0.362380, -0.321910, 0.138780, -0.339720, 1.083380, 0.802710, -1.004080, 0.208610, -0.406500, 0.499800, 
-0.008790, -0.060000, -0.535490, 0.256020, 0.679790, -0.149020, -0.491960, -0.190110, 0.939720, 1.279030, 
-1.259500, 0.878110, 0.490600, 1.569390, -0.875870, 0.490320, 0.936220, -0.307350, -0.465270, 
0.575200, -0.157790, 0.694490, 0.637410, -0.710580, -0.853340, 0.898190, -0.088420, -0.749270, 1.169630, 
0.551300, 0.138590, 0.186230, 1.010390, -0.585860, 0.859470, 0.538000, 0.495610, -0.063350, 0.879500, 
1.310840, 0.030610, 0.138370, -0.790520, 0.240530, 0.972860, 1.696080, -0.694200, -0.630940, 0.056720, 
0.516480, -0.259740, 0.395380, -0.695290, -0.200020, -1.388920, -0.193380, 0.987060, -0.532220, -0.146910, 
-1.632750, 0.268370, -0.838160, 1.084270, 0.240520, -0.683910, -0.121580, -0.181970, 0.481330, 0.353950, 
0.225820, 0.734900, -0.091090, -0.614630, 0.598820, 0.678640, 0.423440, 0.068620, -0.764160, 0.755250, 
0.971190, 1.064390, 1.268320, 0.084890, 1.560710, 0.888660, 1.114750, -0.676390, 0.433550, 0.385280, 
0.042480, 1.245110, -1.213530, 1.300230, 1.272180, -0.078260, 0.241430, 0.468480, 0.274570, 0.734320, 
-0.455140, -0.383330, -0.571530, -0.337270, -0.732850, 0.602890, 0.757440, 0.918440, 0.358650, 0.363000, 
-0.132060, -0.668170, 0.706270, -0.749280, -0.293360, 0.769050, -0.676600, -0.656330, 0.529660, 1.331090, 
-0.981000, 0.074000, -0.733570, 0.676660, 0.452220, 0.538780, 0.453280, -0.101380, -0.337640, -0.088100, 
1.055490, -0.886450, -0.380640, 0.600020, -0.911960, 0.111600, 1.292560, -1.443140, -0.785930, 1.204470, 
-0.670980, 0.017000, 0.972770, 0.080260, 0.181380, 1.186760, -0.120340, 0.260150, 0.405800, 0.696320, 
0.339780, -0.985960, 0.095220, 0.577210, 0.691760, -0.120250, 0.533460, 1.013160, -0.310290, 1.231420, 
-0.450120, -0.170310, 0.911940, -1.467120, 0.015410, 0.152860, -0.230750, 0.988430, -0.409980, -0.224410, 
0.830540, -0.208000, -1.081820, -0.088550, 0.524800, 0.010690, 0.272420, -0.392740, 1.090870, 1.221720, 
-0.293790, -1.465980, -0.474450, -0.564620, -0.339990, -0.962390, 1.938560, 0.085830, 0.546020, -0.264020, 
1.092240, -0.360390, 0.466700, -1.346050, -0.364090, -0.288490, 0.122190, 0.469710, -0.446360, -0.499990, 
-0.028780, -0.834620, -0.369340, -0.317950, 1.237540, 0.016570, 0.307550, 1.247220, 0.589940, -0.532710, 
0.978400, -1.004940, 1.119430, -0.241540, -0.869050, 0.747880, 0.449120, 0.321230, -0.630510, -0.218700, 
0.013520, 0.167810, 0.714730, 0.618460, 0.849470, -0.401240, -0.065900, -0.550950, -0.332550, 0.245410, 
-1.547080, -0.027640, -0.576080, 0.026470, 0.643210, 0.974750, 0.998760, -0.226300, 0.825390, 0.392400, 
0.304750, -0.706280, -0.299920, -0.515290, 0.928040, -0.764040, 0.721900, -0.196470, -0.174480, 0.102450, 
-0.267410, 0.629260, 0.734970, 0.220410, 0.471490, -1.108210, -0.665600, -0.225750, 0.960180, 0.347090, 
0.790310, 0.962650, -0.886800, -0.755680, -0.217190, 0.702090, 1.249190, 1.463860, 0.334920, 0.404650, 
0.507210, 0.484180, -0.893640, -0.834890, 0.214920, -0.298590, -0.255150, 0.091060, 0.227130, -0.548360, 
1.324390, -0.677050, 0.259680, 0.889310, 0.650960, 0.161520, 0.940730, 0.071650, 0.504270, 0.987480, 
-0.035630, -0.096570, 0.982790, 0.593720, 0.701280, 0.394280, 0.108820, 0.070030, 1.434970, 0.619140, 
0.233330, 0.125880, 0.785610, 0.542970, -1.223580, 0.499270, 0.460110, -0.586590, -0.138680, -0.346860, 
1.765620, -1.071400, 1.183440, 1.032580, 0.330330, -0.724820, 0.800590, 0.741130, 0.179450, 
-0.294880, -0.500900, 0.557300, 1.055570, -1.236940, 0.462550, 1.051660, 0.072450, 0.044680, 0.283790, 
0.243130, 0.783620, -0.447370, 1.030630, -1.587470, 0.772290, -1.373470, -0.063120, 0.447170, 0.548900, 
-0.603510, -1.211690, -0.700150, -0.618830, 0.114130, 0.188900, 0.993370, 1.250950, 0.709040, 0.329520, 
0.195980, -0.688210, 1.030660, -0.592610, 0.780970, 0.948330, 1.024870, 0.069800, -0.263720, 0.955380, 
0.768180, -0.596780, -1.447560, 0.050250, 0.104060, -0.176910, 0.481020, 0.183390, 0.580350, 0.079510, 
0.312530, -0.874240, 0.251170, 0.873730, 0.408370, 0.693960, -1.102540, -0.331680, -0.171970, -0.756470, 
0.149590, -0.798570, -1.313980, 0.115890, 0.796290, 0.377320, -0.077880, -0.103430, -0.818080, -1.366440, 
1.112970, 0.447140, 0.901070, 0.783600, -0.093550, 0.704210, 0.063560, -0.637470, 0.113830, -1.215080, 
0.402890, -0.258640, -0.701890, -0.111580, -0.157610, -0.901810, 0.887430, 0.205360, -0.145620, -0.040940, 
-0.425480, 0.193440, 0.413880, 0.704280, -0.282680, 0.571350, -1.016310, 0.019140, -1.053720, -0.709850, 
0.010120, 0.998660, -0.924340, -0.166610, 0.363950, 0.105590, -0.568340, 0.058030, 0.257800, 1.135150, 
-0.841760, -1.263930, -0.091720, -1.147690, -1.148090, -0.548680, 1.131140, 1.459210, 0.892610, -0.464040, 
-0.054120, -0.368690, -0.182810, 1.435660, 0.724570, 0.808680, 0.557910, 0.080410, -1.199640, 0.386750, 
0.443620, -1.564680, 2.328610, 0.697280, 1.408110, 0.131430, -0.420710, -0.199220, 0.457310, -0.076230, 
0.429160, 0.062600, 0.740120, -0.541590, 0.577730, 0.541290, -0.129940, 0.977950, 0.886320, -0.305290, 
0.212350, -1.333120, 0.151600, 0.393550, 0.395290, -1.063390, -0.406720, 0.899170, 0.958980, 0.206460, 
-0.945430, -0.933870, -0.035670, 0.329250, 0.128010, -0.938200, 0.235010, 0.499650, -0.383640, 1.003280, 
-0.751850, -0.260710, 0.807160, -0.180820, -0.605840, 0.545680, -0.282000, -1.433490, -0.566360, 0.614030, 
-0.020470, -0.393020, -0.549380, 0.342100, -0.387190, 0.010640, 0.144990, -0.150350, 0.153930, 0.072170, 
0.374030, -1.126860, 1.040170, 0.446090, -0.194830, 0.595670, 0.235030, -0.455590, 0.324680, 0.856860, 
1.310870, 0.035150, 0.461260, 0.709430, -0.719680, -1.239710, 1.491720, -1.364510, -1.018280, 0.364490, 
0.828480, 0.718150, 0.241530, -0.818680, 0.112440, 1.779950, 0.183890, 0.236510, -0.715970, 0.585160, 
-0.794900, -0.316060, -1.050570, -0.372840, -0.637150, 0.228190, -0.758200, 0.038730, 0.922720, -0.076980, 
-0.366230, 0.426460, -0.313680, -0.118620, 0.214890, -0.028720, 0.365160, -0.184690, 1.152540, -0.078250, 
-0.167150, 0.302240, -0.747290, -1.089190, -0.195290, -0.215540, -0.275530, -0.370070, 0.932960, 0.165020, 
-1.089130, -1.040330, 1.088510, -0.753760, 0.021400, 0.168180, 0.915610, -0.438000, 0.538470, -0.493110, 
-0.376960, 0.621780, -1.150570, -0.231230, 0.014430, -0.207900, -0.499680, 1.063390, -0.360120, -0.144200, 
0.818870, 0.288010, -0.112120, -0.049010, 1.350740, 1.004960, -0.309350, -1.206280, -0.831550, -1.228150, 
-0.272770, 0.542360, 0.600650, -0.510870, -0.495390, -0.135160, 0.201930, -0.599860, 0.931560, -0.553080, 
0.112410, -0.804010, 0.403450, -0.274450, 0.600440, 0.623890, 1.506160, -0.514790, 0.651470, 
0.526120, 0.477830, 0.540640, -0.213620, 1.254980, -0.448050, -0.353210, 0.212820, 0.892010, -0.161570, 
-1.016110, -0.036100, -0.037530, -0.575180, 0.116650, -0.244920, -0.491600, 0.411850, 1.255050, -0.257100, 
-0.043710, 0.983140, 1.122290, -1.344070, -0.237450, -1.710900, -1.475810, -1.237610, -0.435750, -0.610780, 
1.005030, 1.549340, -0.780710, -0.764570, -0.603360, -0.060370, -1.267840, -0.730850, -1.064510, -0.667890, 
1.462090, 0.247460, 0.220520, -1.307690, 0.126320, 0.784690, 1.164820, -0.440940, 0.286420, -1.131570, 
-0.761370, -0.024300, -0.145940, -0.266640, -0.269690, 0.224880, 0.849590, 0.577300, 0.046500, -1.206860, 
-0.108280, 0.411710, -0.549770, -0.421820, -0.335360, 0.108140, 0.412680, 1.596620, 1.112370, -0.081420, 
0.533430, -0.453230, -1.423020, -0.115790, -0.083960, -0.271230, 0.764520, 0.384570, 0.099300, 0.711090, 
-0.604420, 0.116750, -0.199550, 0.351500, -1.039170, -0.171930, 0.730140, -0.519360, -0.428690, 0.407480, 
0.701210, 0.803930, -1.149360, 0.346190, -0.162020, 0.431710, 1.470900, 1.165570, 0.036340, 0.353420, 
0.670480, 0.330170, -1.233330, -0.012800, 0.020110, 0.643290, 1.036480, 0.578970, -1.012630, 0.271490, 
-0.181570, -0.321310, -0.073690, 1.101480, -0.050080, 1.142590, 0.003080, -0.799020, 1.938550, -1.362050, 
0.472010, -0.976780, -0.001660, -0.078350, 1.888120, -0.506620, -1.583150, -0.820410, -0.684450, -0.751670, 
-0.466410, 0.083800, 0.837900, -1.354770, 0.125250, 1.366860, 1.170680, -1.024050, 0.754540, -1.447330, 
0.196820, -0.701970, -0.556550, 1.209300, -0.262140, -0.048980, -0.314530, -0.626660, -0.273560, -0.556320, 
-0.030460, 0.219440, -0.961860, 1.106550, 1.494740, -0.006320, 1.020510, 0.214670, 0.901680, -0.920250, 
-0.886540, -0.496310, 0.523300, -0.086830, 0.777830, 0.922210, -0.481190, -0.017830, -0.993090, -0.271510, 
-0.702250, 0.121930, -0.367710, 0.604830, -0.682600, 0.520220, -0.379260, 0.234890, 1.134630, -0.870120, 
0.503560, -0.903900, 0.891500, 0.619380, 0.313010, 0.550110, 0.973690, -0.217460, -0.362280, -0.354810, 
0.006870, -1.149260, -0.361710, 0.202000, 0.135650, 0.735340, -0.929820, -0.533960, -0.197800, -1.113450, 
0.543800, 0.628450, -0.935920, -0.355980, -0.731300, -0.485450, 1.018650, 0.218430, -0.091000, 0.410650, 
-0.714260, -0.267410, 0.516220, 1.234330, -0.187810, -0.658890, -0.361020, 0.246250, 0.128080, 1.111850, 
-0.522670, 0.021320, 1.218500, 0.164340, -0.530700, -1.702970, 0.903620, -0.406020, 0.801800, 0.462540, 
0.505100, 0.301330, -0.986120, 0.050990, 0.233240, 0.981630, -0.039550, -0.221740, -0.211700, 0.225610, 
1.323910, -1.030330, -0.139760, -0.145370, 0.277570, 0.825250, -0.660520, -0.404990, -0.573140, 0.038680, 
-2.189730, -1.167680, -0.837050, -0.864000, 0.425260, -0.166320, -1.414700, 0.586370, -0.598110, -2.307970, 
-0.322470, -0.146710, -1.242310, 0.891900, 0.126160, -0.812370, -0.396150, 0.866180, -0.053540, 0.077610, 
-0.346570, -0.978520, 0.081380, -1.163330, -0.699110, 0.108310, 1.248630, -1.447050, 0.399680, 0.458220, 
-0.551870, -0.921460, 0.827200, 0.461090, 0.082270, -1.038180, -1.455620, -0.079170, 0.414120, 0.848170, 
-0.327330, 0.873000, 0.058910, 1.356720, 0.254390, -0.691470, -0.141600, 0.135450, -0.181490, 
1.025220, -0.323690, -0.847170, -1.133130, 1.219190, -0.624860, -0.453710, -0.889630, 0.646520, -0.142440, 
0.387070, 0.619000, 0.080560, -0.904490, 0.303410, -1.781440, -0.099940, -0.972830, 0.708580, -0.934140, 
-1.027330, -0.265940, 0.836780, -0.027690, -0.044730, 0.425630, -0.671420, 0.300780, 1.346750, 0.562940, 
-1.168100, 0.353310, 0.993890, 0.359350, -1.262540, -0.101780, -0.092200, -0.595350, 0.646170, -1.148280, 
0.309190, 0.760730, -0.149530, 0.289320, 0.766720, 0.501610, -0.427660, 0.121620, -0.155690, 0.187440, 
-0.232520, -0.790050, -0.382050, -0.267520, 0.054170, 0.573510, 0.921120, 0.027010, 0.179340, 0.461060, 
0.523840, -0.091290, 0.383790, 1.161960, 0.360690, 0.141620, -0.906650, -0.416380, 0.235460, 0.236280, 
-0.550210, 0.061050, -0.724840, 0.369190, 0.525070, 0.516400, 0.243940, -0.670630, 0.688570, 0.695370, 
-0.438630, 0.040000, 1.029540, -0.659680, 0.207040, 0.266270, -0.232390, 0.944860, 0.032760, -0.248660, 
1.031070, -0.573330, -0.046020, -0.230150, -0.339520, -1.882690, 0.082210, 1.520000, -0.566310, -0.213390, 
-0.550820, -0.716660, 0.457870, 0.307090, 0.260580, 0.509640, -1.724070, 0.589600, 0.389760, 1.081850, 
-0.795990, 0.828210, -0.569500, -0.302910, 0.352560, 0.388730, 0.399250, 1.333160, -0.607440, 1.845080, 
1.026230, 0.281580, 0.962280, 1.224210, 1.842140, 0.325830, 1.242760, -2.197150, 0.274560, 0.833290, 
-0.817340, 0.737510, 1.138840, 0.987190, 0.222000, 2.249480, 1.081660, 0.633700, -0.402820, 1.428270, 
1.086540, 1.588640, 0.931140, -0.150940, -1.066210, -0.536390, -0.772770, -0.564340, -1.521860, 0.085470, 
-0.649610, 1.408590, 0.728740, 0.157770, -0.154770, -0.877610, 0.917360, -0.504950, -1.123380, 0.967740, 
-0.248970, -0.164180, -1.523790, 1.007780, -0.890360, 0.299300, -0.752170, -0.185690, -0.539660, -0.542970, 
-0.153720, 1.007970, -0.226180, 0.130250, 1.435910, -0.232190, -0.429530, 0.011140, -0.716560, 0.100200, 
1.499390, -0.291320, 0.047880, -1.086390, 0.394780, 1.157960, 0.432190, -0.756770, -0.104170, 0.891160, 
-0.996950, -0.314110, 0.476150, 0.993930, -0.622370, 0.973400, 0.787320, 0.428840, 0.003410, -0.946860, 
-0.578550, 2.091190, -0.279120, 0.467730, 1.424990, 0.705610, -0.554000, -0.861310, 0.570800, 0.726040, 
1.481930, 0.542980, -0.145810, -0.213010, -0.042250, 1.186710, -0.020800, -0.492360, -0.150790, -0.941730, 
0.155050, 0.267200, 0.422190, -0.575740, 0.223350, 1.037040, -0.687160, -0.100050, 0.176900, -0.294660, 
-0.533790, -0.887230, 0.120490, 0.144280, -0.396390, -0.348410, -0.367870, -0.754220, -1.211900, 0.379150, 
1.002750, -0.713170, -1.012560, -1.019610, -0.220510, -0.091780, -0.966690, 0.280650, 0.516720, -0.193850, 
0.785330, 0.865610, 0.841220, 0.179870, 0.107440, -0.552040, 0.787670, 0.236220, 0.610080, -1.139670, 
2.027870, -0.058110, -0.633320, -0.301770, 2.271560, 0.750690, 0.532490, -1.063290, -0.014630, 0.418760, 
-0.500930, 0.100720, -0.251880, -0.684330, -1.688950, 0.839460, 1.464440, -0.140420, -1.156300, -0.637640, 
-1.100520, 0.554510, 0.060930, 0.651380, 0.146750, -0.080060, -1.452370, 0.105520, -0.148070, 1.040090, 
-0.708140, -1.257420, -0.694480, 0.426040, 1.050850, -0.687570, 0.143600, -0.619730, 0.424990, 
-0.177760, -0.148250, 0.052070, 0.466070, 0.314980, 1.179910, 0.119830, -0.322230, 0.271370, 0.132710, 
0.153990, -0.299670, -0.901060, -0.530680, -0.770610, 0.604860, 0.678590, -0.361630, -0.693010, 0.113160, 
0.468210, -0.521160, 0.119840, 0.780370, 0.001410, 0.308600, 1.066930, -0.303510, -0.872890, -0.362070, 
-0.011060, 0.235790, -0.192690, -0.876080, -0.412550, 0.231640, -0.645360, -1.225920, 0.720210, 0.198710, 
0.086240, 0.095460, 0.121670, 0.630230, 0.606960, -0.036430, -0.517010, -0.408560, 0.748520, -0.379780, 
-0.356490, 0.046560, -0.328640, -0.406150, -0.210690, -0.221520, 0.797080, -1.524900, 0.632710, -0.589110, 
0.747240, -0.423690, -1.387300, 0.235910, -0.283920, 0.422140, 0.179070, -0.299550, -0.024130, 0.637220, 
0.045710, -0.544950, -0.590520, 0.460650, 0.155960, 0.181690, 0.549510, 0.849550, -0.497190, 0.004500, 
-0.478420, 0.144970, 0.064520, -0.490310, -0.475230, 0.524200, 0.150350, 0.135780, -1.153090, -0.912350, 
0.102210, 0.240170, -0.449840, 0.755870, -0.305840, 0.015790, -0.710580, -0.577980, -0.259570, -0.234650, 
0.642980, -0.285770, 0.859700, -0.269770, -1.069780, 0.073820, 1.126370, -0.146870, 0.249860, 0.633840, 
-0.532390, 0.551690, -1.099330, 0.428610, 0.238740, 1.363900, 2.069260, 0.184520, -0.335720, 2.199100, 
1.313310, -0.850450, 1.663440, 1.868220, 2.237860, 0.232930, 0.802970, -0.560960, 0.015850, -0.500250, 
-1.222510, 0.498740, 3.394590, -0.092410, -0.240790, 6.269910, 1.176110, -0.427680, -0.302580, -1.036990, 
-0.493030, 0.098760, 0.630630, -0.347210, -0.210230, 0.331320, 0.710530, 0.327700, -0.158670, 0.033650, 
0.368120, -0.524330, 0.238730, -0.478030, -0.713210, -0.378440, -0.022120, -0.782890, -0.284160, 0.184070, 
-0.227130, 0.276390, 0.044390, 0.074300, -0.993800, -1.005150, -0.712350, 0.182440, 0.504850, 0.092370, 
-0.456830, 0.667790, -0.102690, -0.340280, -0.647950, 0.612220, 0.395560, -1.466950, 0.183390, -0.676600, 
-0.395080, 0.217460, 0.407010, -0.290820, -1.093720, -0.586580, 1.038710, -0.012080, -0.389490, 0.451740, 
0.041360, 0.068670, 0.278970, 0.290690, 0.328110, -0.482530, -0.861190, -1.161910, 0.287790, 0.608450, 
-0.685590, -0.404730, -0.117190, 0.108690, -0.063260, 0.730290, -0.053850, -0.261470, -0.626220, -0.785580, 
-1.272980, -0.120530, 1.162180, -0.548200, -0.237030, 0.882130, 0.426380, -0.806710, -0.204780, -0.170140, 
0.083830, -0.971080, 0.482030, 0.693430, 1.690550, -0.409390, -0.003590, 0.255930, 1.702430, 0.883710, 
-1.014590, -0.116240, 0.109930, -0.474850, 0.924900, 0.777250, -0.450680, -0.067150, -0.182710, 0.204760, 
0.255930, 0.291780, 0.150680, -0.073410, 0.412220, -0.067370, -0.532260, 1.019350, 0.254900, 0.679900, 
-1.543730, 0.158540, -1.034160, -0.836180, -0.278170, -0.083820, -0.341360, 0.369920, -0.132730, -2.190700, 
-0.786700, 0.078960, 0.576600, -0.468690, -0.336150, -0.450410, -0.400530, 0.013910, -1.051460, 0.083970, 
-0.567120, -0.053590, -0.777170, -0.169800, -0.536470, -0.818010, -0.522230, -1.313640, 1.041630, -1.015640, 
0.729620, 0.346960, -0.175160, -0.331000, -0.341700, -0.296150, -1.130220, 1.079090, 1.466720, -0.348540, 
-0.157200, 0.023890, -0.543540, 0.377590, -0.418790, -0.677360, -0.652770, -1.726070, -0.147400, 
0.183380, -0.160620, -1.282130, 0.867420, 1.305910, 0.901650, -0.410060, -0.257180, 0.755760, -0.645210, 
0.341280, -1.806550, 0.302980, 0.998320, -0.494550, 0.259980, 0.636430, -1.569060, 0.003580, 0.040610, 
-0.817770, 0.338840, 1.077630, -0.123980, -1.509550, 1.221840, -0.124050, 0.590180, -0.448630, -0.622820, 
0.254830, -1.250830, -1.085610, 1.712560, 0.343140, 0.469600, 0.092210, -0.976170, 1.012610, -1.140880, 
-0.422670, -0.916290, 0.796410, 0.104640, 0.334310, -0.818600, -0.746980, -1.009790, 0.031900, -0.311390, 
-0.294490, -0.175700, -1.244960, 0.411370, -0.866510, -0.416640, -0.153180, 0.281150, 0.469390, -0.237990, 
0.902640, -0.246940, 0.078200, 0.852800, 0.547150, 0.350750, 1.890540, 0.011200, -0.623780, -0.717640, 
-0.363690, -0.836900, 0.637290, 0.276330, 1.484370, -2.091100, -0.248370, -0.669550, 1.566320, -0.485620, 
-0.229120, 0.252730, -0.559830, 0.707050, 1.176870, -0.184900, 1.247440, -0.951410, -0.857640, -0.390800, 
0.323210, -0.177420, 0.913340, -1.351540, 0.542200, -0.844550, 0.291220, -0.211990, -0.463690, -0.640750, 
1.001070, 0.574970, -0.759230, -0.183350, 0.218300, 0.852910, -0.807350, -0.233230, 0.195050, 1.680690, 
0.476670, 0.662610, 0.861040, 0.581650, 0.447790, -1.960070, 0.149190, -0.113870, -1.434510, -0.325320, 
0.490580, 0.434420, -0.369170, -0.192610, -1.942940, -0.258590, -0.711500, -1.323370, -0.352730, -0.465070, 
0.571880, -0.034860, -1.694640, 0.762620, -0.202510, 1.197220, -0.169940, 0.645910, 0.900790, 0.368280, 
-0.065220, 0.764460, -0.176020, -0.302460, 0.653090, 0.165650, -0.815880, -0.419520, 1.309280, -0.559060, 
0.801670, -0.535100, 0.288620, 0.758540, -0.195740, -0.724030, 0.404720, 1.207990, -1.131470, 1.215250, 
-0.362250, 0.392060, -0.158600, 0.671050, -0.994340, -0.587230, -0.904210, -0.526310, 0.218880, 0.441070, 
0.456730, -1.295360, 0.670370, -0.479070, -0.047210, 0.445640, -0.238550, 0.513140, -0.760500, -0.074320, 
-0.031900, 0.182220, 1.319200, -1.230840, -0.493840, -1.352320, -0.665800, -1.152560, -0.830720, 0.718650, 
-1.194200, -0.332720, -0.048300, -1.299970, 0.446040, 0.959510, -0.256570, -1.186670, 0.943470, 0.978180, 
0.380990, -0.810220, 0.079060, 1.124720, -0.509380, -0.010290, -1.207130, 1.254870, 0.453350, -0.815490, 
0.041400, -0.179270, 0.912770, -0.164380, 1.049940, -0.151330, 0.978930, -0.495200, -0.239470, 0.920590, 
-1.007060, -0.162920, -0.194570, 0.224690, -0.688950, -0.167440, -0.407880, 0.006650, -0.392470, -1.076510, 
0.031780, -0.275530, 1.269040, 1.137370, 0.007640, -1.218010, 0.167220, 0.263520, 0.738450, -1.036290, 
1.176790, 0.412550, -0.151190, 1.291520, 0.538300, 0.823170, -0.796340, 0.063340, 0.052090, 0.112890, 
0.535430, -0.700480, -0.285580, 0.930990, 0.594950, 1.109630, 0.403810, 0.292340, 1.443800, 0.444630, 
-0.582980, -1.253590, 1.710830, 0.752690, -0.388370, 0.090630, -0.820460, 1.473850, -0.040000, 0.649620, 
-0.094760, -0.090470, -0.182020, 0.905230, -1.420690, -0.214120, 0.237070, 0.619010, 0.635950, 0.271550, 
0.488230, -0.337740, -0.252400, 0.780320, -0.502670, 0.092270, 1.367820, 0.910410, 0.126590, 1.220790, 
-0.519380, 0.299500, 0.569420, 1.047880, -0.360390, 0.350730, 0.309990, 0.058980, 0.844800, 
-0.683630, -0.355950, 0.216230, 0.691090, -0.667810, -0.011600, 0.140790, 0.426230, 0.059210, -0.994300, 
-0.768970, 0.235500, -1.422740, -0.201990, -0.627040, -0.030220, -0.084870, -0.698660, 0.332010, 0.592220, 
0.277080, -0.467770, -0.380550, 0.438700, -0.644110, -0.849190, -0.523450, 0.025630, 0.887740, 0.443270, 
-0.185110, 1.717980, -0.399410, -0.389200, 0.222310, 0.740030, -0.200140, 0.587000, 0.313120, -0.701370, 
1.459390, -0.072210, -0.008480, 0.044330, -1.186270, 0.647100, 0.009390, 0.571770, 1.269840, 0.195610, 
1.131880, 0.669960, -0.517450, 1.166900, 1.778870, 1.026570, -0.436160, -0.248330, 0.487580, -0.039580, 
0.330760, 1.672420, 0.555570, 0.154760, -0.222780, 0.241680, 0.027580, -0.126290, -0.740830, 0.360150, 
0.890390, 0.587660, 0.961930, 1.035760, 0.526170, 0.274440, -0.324530, 0.905710, 0.434740, 0.053680, 
-0.177970, -1.071720, 0.799980, 0.578670, 2.063630, 1.544630, 0.054200, -0.297770, -0.394410, -0.574890, 
-1.323520, 0.410910, -0.361110, -0.458240, -1.196340, -1.516190, 0.200330, -0.767360, -0.020670, 0.373950, 
0.800360, -0.460670, 0.301510, 0.150390, 0.030580, -0.100410, 0.719030, -1.150030, -0.062630, 0.201190, 
-0.163370, 1.482940, 0.680950, 1.825610, 0.795270, -0.202920, -1.711990, 0.132300, 1.377190, -0.210040, 
0.027970, -0.559630, 0.024010, 0.443600, -1.623390, -1.145360, 0.665830, -0.718450, -1.050090, -0.722290, 
-1.128040, 0.685200, -0.787740, 0.196440, -0.525120, -1.174570, -0.349900, -0.092920, 0.303050, 0.884690, 
-0.217510, 0.322240, 0.176450, 0.186520, -0.162780, 0.884280, -0.425110, -0.672900, -1.016070, 1.140790, 
0.986950, -0.177160, -0.909280, 0.610060, 0.521930, -0.209280, -0.271860, -0.483300, 0.396630, -0.195040, 
0.124030, -0.355600, -0.946710, 0.321290, 0.531360, 0.543140, -0.841690, 0.730570, -0.059320, 0.908190, 
-0.276890, 0.247220, 0.443660, 0.232890, -0.417420, -0.689730, -0.520100, 0.030700, 1.278450, 0.375760, 
-0.983860, 0.385050, 0.568830, 1.203670, 0.482730, -0.813380, -0.651430, 0.533110, 0.609930, 0.028420, 
-0.644290, -0.338830, 0.704800, 0.741830, 1.443180, -0.246700, 0.791980, -0.669230, -0.345440, 0.386990, 
-0.594300, -0.180140, -0.520360, 0.851700, -0.089800, 0.420080, 1.771720, 0.286970, 0.200380, -0.628900, 
0.722490, -0.434980, 0.006390, -0.432680, -0.357580, 0.730750, -1.258830, 0.286250, 0.451090, -0.701350, 
-0.280130, -0.039320, 0.770840, 0.077730, 0.231070, 0.370220, 1.255270, 0.057620, 1.318270, 1.087150, 
0.288600, -0.834230, 0.382470, 0.994470, 0.695420, -1.071090, -1.429010, 0.366540, -0.368180, -0.611450, 
0.536980, 1.326720, -0.166690, -0.973630, -0.358160, -1.156450, -0.341730, 0.409860, -0.076180, -0.210570, 
0.012350, -0.239600, 0.812830, 0.900560, 0.058170, -0.676320, -0.553420, -1.353660, -0.374830, 0.377180, 
0.101470, -0.424920, 2.243900, 1.727360, -1.395970, -1.057370, 0.396420, -0.447730, -0.071010, 0.949490, 
0.863300, 0.533590, 0.024850, -0.130960, -0.184630, 0.723050, 0.017180, -1.183640, 0.904240, -0.773560, 
0.201530, -0.295380, -0.322000, 0.363220, 0.029440, -1.247480, -0.041320, -0.889590, -0.097920, 0.158130, 
0.752140, 0.882470, -0.161780, 0.407000, 0.264480, -0.493600, -0.231850, -0.643210, -1.088220, 
0.301530, -0.157080, 0.035140, 0.413260, -0.104450, -1.167670, -0.770570, 1.414420, -0.254120, 0.481600, 
-0.556790, -1.286480, 0.162630, -0.145200, 0.143590, -1.130440, 0.358730, -0.312410, 0.675620, -0.110110, 
0.849210, -0.954830, 0.725410, -0.377530, -0.337390, 0.188530, 0.016260, 0.433820, -0.268210, 0.041500, 
0.431990, 0.261230, -1.651130, -0.488950, 0.655410, -0.216440, 0.328970, 0.501480, -0.028430, -0.376440, 
-0.416460, -0.350950, -0.749620, -0.697400, -1.313430, 0.536340, 0.435460, -0.353230, 1.056800, -0.165900, 
-0.298970, 0.705470, 0.746600, -0.241520, -0.099640, -0.445010, 0.514240, -0.563490, 0.079340, 0.451900, 
1.515260, -0.628520, 1.253880, 0.737740, 0.378020, -0.433170, -0.216480, 0.645970, -1.087820, -0.126840, 
0.459360, 0.947680, -0.505740, -0.156720, -0.633810, -1.235850, 1.128440, 0.801530, 1.122380, -0.813350, 
-0.533560, 1.535810, -0.480390, -1.710780, -0.737890, 0.543520, 1.405560, -0.536410, 0.169510, -0.179620, 
0.982070, 1.852600, 0.285490, 0.193300, -0.216240, 0.146420, -0.139590, -0.559740, 0.250740, -1.349010, 
0.376570, -0.056760, -0.127890, -0.612050, 0.982940, 0.043970, -1.052980, 0.679250, -0.401540, -0.230700, 
-1.405770, -0.863930, -0.227730, 0.144780, 0.583420, 0.206390, -0.403290, -0.078980, -0.250980, -0.554070, 
0.121220, -1.205850, -0.139820, -1.985030, -1.458790, 0.306000, -0.273760, -0.354010, -1.435750, -0.253780, 
1.985240, -0.498920, -1.656480, 0.972630, -0.348600, -0.974260, -0.241450, 1.064460, -0.350300, -0.103030, 
-0.853210, -0.594030, 1.514750, 1.263970, -0.020830, 0.373750, -0.352870, -0.561740, 0.499220, 1.361170, 
-1.039880, -0.869850, 0.163590, -0.344650, -0.084000, -0.672640, 0.127740, -0.637070, 0.879110, 1.782410, 
1.261420, 0.485680, -2.784850, 1.249040, 1.123500, -0.305910, 0.808480, -0.239200, -0.925230, 0.197840, 
-0.197190, -0.122710, 0.712620, -0.488950, -0.564680, 0.043790, -0.443060, -0.211810, -0.878780, -0.242920, 
0.206240, -0.339560, -0.174500, 1.018020, -0.479030, -1.167210, 1.977770, 1.196040, -1.079900, 1.343850, 
0.971970, -1.224150, -0.589020, 0.573140, -1.569710, -0.620730, -0.298240, 1.045250, 0.151750, -0.504530, 
0.900190, -0.995160, 0.841820, 1.589810, 1.121580, 0.882210, -0.323510, 0.183030, -0.510220, 0.653250, 
-0.795760, -0.339070, 0.557980, 0.560210, -0.150350, -0.918230, 0.265980, -0.915710, 0.761290, 0.333670, 
1.593890, -0.620580, -0.143570, 1.290130, -0.058760, 0.173960, -0.858130, -0.320320, -1.060600, -0.054810, 
0.620220, 0.335850, -0.908620, -0.067970, 0.020070, 1.012360, -0.292320, 1.353440, -1.035080, -0.152270, 
-0.431870, 0.094770, 1.253160, 1.001330, -0.288230, -0.493570, 0.177800, 0.023730, -0.030370, 0.849690, 
0.818340, 1.663580, 0.131620, -0.002050, -0.480110, -1.310620, -0.181370, -0.273050, -0.315580, 0.205830, 
0.666580, 0.414530, 1.749490, 0.354370, 0.388980, 0.440000, -0.249010, -0.631170, -1.179340, 0.884960, 
-0.080620, -0.365240, -0.365870, 1.360900, 0.122280, -0.334980, -0.081140, 0.415820, 1.220980, -0.515620, 
0.719280, -0.693870, 0.939540, 0.158140, 0.844330, 0.323270, 0.134700, -0.081470, 0.674000, -0.595730, 
-0.036910, 1.905480, -0.028310, -0.032780, -0.218520, -0.010010, -0.266210, 0.457250, 0.813210, 
0.463780, -0.556690, -0.652780, -0.821710, -1.464540, 0.281070, 0.710230, -0.089490, -0.509500, 0.857600, 
1.023750, -0.305430, -0.272240, -0.109740, 1.370200, 0.150550, 0.870510, -0.312420, 0.617050, -1.557230, 
-0.999020, -0.268330, -0.176280, 0.110240, 0.131910, -0.067360, 0.355000, 0.256950, 0.611750, -0.031230, 
0.986360, -1.289230, -0.380500, -0.921490, -1.000630, 0.249640, -0.004400, -0.055910, 0.097110, -0.256240, 
-1.134880, -0.355580, -1.108150, 0.295230, -0.370380, 1.290970, 0.812080, 0.262290, -0.834170, -1.412480, 
-1.055620, -0.723220, 0.725680, -0.209600, -0.264680, -0.670780, 1.463670, -0.789480, 0.673860, 1.185280, 
1.036060, 0.399080, -0.252180, -0.674480, -0.052380, 0.849500, -0.899090, 0.188430, -1.987080, -0.902310, 
-0.365220, 0.481300, 1.147500, -0.079100, 0.271450, -0.129700, 0.029330, -0.386090, 0.255230, -1.246470, 
-0.929760, -0.661450, -0.719520, -0.364510, 1.602090, 0.321880, -0.307230, -0.026680, 0.266880, 0.162860, 
1.099530, -1.439010, -0.826080, 0.755840, 0.119830, -0.094990, -1.200420, 1.529780, 0.488370, 0.735270, 
-0.495330, 1.082500, -1.167350, -0.872070, 0.243520, 0.325010, -1.125130, -0.347110, 0.121750, -0.339250, 
0.195850, -0.140510, -0.406580, -0.642660, -1.527080, 1.767400, -1.133870, 0.431810, 1.075510, -1.227730, 
-0.357450, 0.810180, -0.256780, -0.644250, 0.191790, -0.460870, 0.067370, 1.325630, 0.457810, 0.330970, 
1.776320, 0.489990, 0.447330, -0.206850, -0.086550, 0.823800, -0.082270, -1.166340, 0.938000, -0.910180, 
-0.232720, -0.592460, -0.581460, 1.116920, 0.942180, -0.637150, 1.017840, -0.487400, 0.968860, -0.365350, 
-0.271970, -0.710670, 0.877630, -1.031650, -0.816440, 0.520020, -0.167490, 0.319920, -1.066940, 0.406760, 
-0.394140, 0.042280, 0.426910, 1.110180, 0.297790, 0.274220, 0.141140, -0.922450, -0.073020, 1.296060, 
0.540570, 0.099780, 0.659690, -0.639950, 0.017830, -0.671660, -0.956630, -0.623240, 1.044100, 0.320590, 
0.053460, 1.086880, 1.121210, -0.870250, 0.666110, -0.090660, 0.031490, 0.418840, 0.149520, -0.408680, 
0.146410, 0.068000, 0.584420, 0.246380, 0.031340, 1.151570, 0.841980, -0.924060, -0.474370, 0.002590, 
0.688280, -0.563340, -0.807700, 0.569770, -0.797870, 0.782360, 0.242460, -0.986080, -0.342760, -1.622470, 
-0.282740, 1.617340, -0.347080, -0.548820, 0.594020, -0.847060, -0.643040, 1.011860, -0.467440, 0.760460, 
-1.001150, -0.988160, 1.229480, -0.107150, -0.100940, 1.529060, 0.073000, 0.700120, 1.392200, -0.788300, 
1.077400, 0.693510, -0.448460, -0.333810, 0.148170, 0.260420, 0.694540, 1.211190, -1.193060, 0.039800, 
0.588150, 0.246030, 0.126750, -1.156520, -1.061280, -0.364910, 0.369320, -0.144720, 0.671550, -1.117830, 
0.012620, -0.419270, -0.066000, -0.473450, 0.255350, 0.612870, 1.080430, 0.492560, -0.777400, -1.231750, 
-0.426340, 0.245340, 0.071910, -0.316760, 0.075180, -0.764980, -0.614100, -0.344790, 0.411820, 0.122580, 
-0.943380, -0.865560, -0.524670, -1.136120, -0.788110, -0.243100, -0.275240, 0.272030, 0.146250, -0.835580, 
-0.608030, 0.102600, 0.607100, -0.584760, 1.011320, 0.688960, -0.623530, -0.258120, 0.876130, 0.738520, 
-0.315140, 0.496970, -0.272810, -0.092610, -0.790210, -0.191570, 0.927670, -0.518880, -0.928120, 
-0.651390, 0.206230, -0.930800, -1.494810, 0.039870, 1.116290, 0.169650, -0.476710, 1.030670, -0.484800, 
0.142060, 0.221150, -0.740410, 0.182210, -0.001330, 0.611890, 0.422240, -0.915820, 0.322480, 0.078490, 
1.191620, -0.943730, -0.332110, 0.495390, 0.898470, -0.782990, -0.373630, 0.083160, 0.108780, 0.187920, 
-0.757030, -0.366300, 0.961480, -0.823760, -0.263400, 0.448180, -0.066560, -0.677560, -0.976170, 0.127450, 
-0.728790, 0.475230, 0.996380, 2.108830, -0.205100, 0.895420, 0.867830, -0.153320, -0.599580, -0.483870, 
-0.493110, -0.616610, 0.091510, -0.166400, -0.961680, -0.842540, 0.647140, 0.972310, -1.065730, -0.979230, 
0.442300, 0.713790, -1.650780, -0.719860, -0.185480, -0.097360, 1.511960, -0.241460, 0.118920, -0.126710, 
0.897020, -1.301870, 0.109580, -0.483500, -0.291990, -1.071710, -1.422330, -0.421370, -0.396710, 0.370870, 
-0.786890, -0.197430, -0.614140, 0.242830, 0.066590, -0.323850, -0.799190, -0.183520, 0.365910, 1.048660, 
-0.486590, -0.280820, -0.316880, -0.903970, -0.335740, -0.331730, -0.827600, -0.437560, -0.895420, 0.269090, 
0.157640, 0.400220, 0.154160, -1.349850, 0.189950, 0.724720, -0.489700, 0.826940, 0.333260, -0.635070, 
-0.710270, -0.080520, 1.678650, 0.882950, 0.059560, -1.912080, -0.371640, -1.219590, 0.817370, -0.209530, 
-0.421000, 2.286530, -0.154230, -1.704440, -1.726050, 0.722810, -0.962880, 1.483400, -0.667220, 1.442070, 
0.627260, 1.104320, -1.863690, 1.232420, 0.129530, -5.964760, -1.558430, 2.012270, -0.186830, -0.533160, 
-0.247370, 0.592410, -0.267000, 0.235950, -0.607750, -0.157460, 0.117790, 0.948830, -0.073340, 0.770730, 
-0.443960, -0.191930, -0.994220, -0.333790, -0.029590, -0.352220, -0.334910, 0.355350, 0.826320, -0.751110, 
-0.071940, -0.159850, -0.999730, -0.705360, 0.164840, -0.585520, 0.426290, -1.310670, -0.689930, -1.138390, 
0.291680, 0.467240, -1.540140, -0.995780, -0.117490, -0.508280, 0.567830, -0.168670, -0.578860, 0.248540, 
0.240380, 0.996250, -0.219980, 1.408430, -0.518210, -0.650190, -1.240980, 0.879470, -0.421910, -0.092880, 
0.435620, 0.570300, -0.240000, -1.387940, 0.520740, -0.088850, -0.911040, -0.443900, 0.471100, 0.924180, 
-0.148570, -0.416190, -0.209240, 0.005620, -0.375810, -1.989810, 1.798890, 0.836470, -0.970100, 0.596960, 
-0.130250, 0.299020, -0.755420, -0.429080, 0.156890, -0.554430, -1.112590, 0.548530, 0.069740, 0.105770, 
0.687030, 0.242480, 0.520610, -0.962830, 1.366070, 0.749350, 0.770960, 0.270290, -0.359610, 0.345100, 
0.397740, -0.412750, -0.176560, -0.720330, 0.340940, -0.068410, 0.467050, -0.497020, -0.512460, 0.859900, 
0.092180, -0.223960, -0.026190, -0.715090, -0.222300, 0.047840, 0.197310, 0.168510, -0.068430, -0.634440, 
0.583380, -0.114950, 0.534340, 0.906640, 0.004640, -0.228720, -0.062310, -0.246890, -0.238770, 1.444340, 
-0.246160, 0.298870, -0.193390, 0.441110, -0.217450, -1.045330, -0.816370, -0.894370, -0.246040, 0.010880, 
-1.307710, -0.360150, 0.664200, -0.937480, -0.311600, 0.290920, -0.807050, 0.319150, -0.563670, 0.384810, 
0.399800, 0.630790, 0.698490, 1.110380, -0.691820, -0.742400, 0.141050, 0.971940, -0.687630, 0.652970, 
-0.058510, -0.155650, 0.322220, -0.267610, 0.099990, 0.025600, 0.671900, 0.129840, -0.051160, 
-0.228990, -0.374670, -0.742000, -0.663840, -0.201770, -0.181680, -0.431170, -0.423150, -0.322060, -0.764100, 
0.036420, 0.352010, 0.634470, 0.503950, 0.998660, -0.038030, 0.161750, 1.486330, -0.443340, 0.480200, 
-1.034330, 1.432180, 0.146510, -0.613550, -1.073200, -0.329100, 0.237240, -0.214790, 0.436460, -0.372450, 
0.618790, -0.777570, -0.246770, -0.317360, -0.049980, 0.072920, 1.066750, -0.972650, -0.720210, 0.076470, 
0.709450, 1.224290, 0.302880, -0.128330, -0.446550, -0.246170, 0.244770, -0.202310, -0.209640, -0.303590, 
0.327590, -0.333220, -0.575320, 0.367630, -0.566530, 0.454210, -0.233890, -0.647960, -0.839170, -0.048200, 
-0.556300, 0.167100, -0.722620, 0.154740, 0.868890, 0.356150, -0.839790, 0.739470, -0.232050, -0.813640, 
0.192380, -0.134730, 0.018970, 0.311310, 0.194360, 0.896310, -0.616860, 1.053920, 0.191920, -0.187860, 
-1.177220, -0.550620, -0.291750, 0.275120, -0.778240, 0.390560, 0.547500, -0.050280, 0.182300, -1.700820, 
-1.141890, 0.260980, 0.363500, -0.120980, 0.034800, -0.048010, 0.424330, 0.218740, -0.294130, -1.400650, 
-0.479640, 0.486720, -0.155260, 0.146830, -0.455270, -0.080000, 0.075510, 0.439050, -0.230140, -0.041290, 
-0.215030, -0.465940, -0.243150, -0.366130, -0.726250, 1.110940, -0.484530, 0.441050, -1.691360, 0.981790, 
-0.086550, -1.222310, 1.345500, 1.378570, 0.823770, 0.551700, -0.841910, 0.233330, 1.627420, -0.695970, 
1.383060, -0.679260, 2.244680, 0.715190, 1.401250, 4.730700, 1.930910, -0.854220, -0.228030, -1.115620, 
0.633180, 0.070190, -0.405680, 1.126500, 0.470450, 0.838920, 0.066340, -1.119520, -0.525700, -0.439220, 
0.517800, 0.514490, -0.963520, -0.292790, -0.579070, 1.046660, -0.894890, 0.006510, -0.531360, -0.326650, 
0.262760, 1.047190, 1.636790, -0.769350, -1.395190, -0.327410, -0.239670, -0.295580, 0.182240, -0.527090, 
-0.944510, -0.566610, -0.237970, -0.162820, -0.923190, 0.746460, 0.604450, 0.554620, 0.624350, -0.495250, 
-0.338600, 0.252920, 0.708080, -0.558410, -1.183090, 0.986860, 0.295650, 0.088760, -1.228370, 0.127060, 
-0.680950, -0.747500, 0.608030, -0.354170, 0.346550, 0.366790, 0.530590, 0.959930, -0.849080, -0.434730, 
-0.852640, 2.148520, -1.225320, 0.223370, -0.305660, 0.888510, 0.891660, 0.769860, 0.147290, 0.821140, 
0.003440, -0.249460, -1.028800, -0.517330, 1.149770, -0.121280, -0.404000, -0.172620, 0.453130, 1.404830, 
-0.089960, -0.190830, -0.078670, -0.683940, 0.696820, -0.691510, 0.595840, 0.579120, -0.513550, -0.441990, 
0.024800, 0.164260, 0.300810, -0.293900, 0.369540, 1.502690, -0.593160, 0.425850, -0.197240, 1.163180, 
1.374180, 0.841930, -0.379430, 0.481750, 0.262790, -0.092040, 0.154030, -1.007040, 0.953980, -0.382940, 
-0.783580, -1.062090, -0.847830, -0.995270, 0.062630, 0.308570, -0.937650, -0.396930, -0.302210, 0.615590, 
0.790560, -1.361250, -1.795330, 0.153120, 1.040010, 0.420160, 0.335830, -0.123900, 0.431730, -0.554170, 
0.762090, 0.277380, 1.106370, 1.178500, -0.786690, -0.688280, 0.460510, -0.117490, 0.802560, 0.595160, 
0.392160, 0.650790, 0.146170, 0.644850, -0.382710, -0.403790, 0.373330, 0.684500, 0.030450, -1.202490, 
0.718860, 0.145390, 0.127580, -0.071020, -0.497000, 0.634060, -0.399190, 0.306020, -0.425290, 
-0.886260, 0.058990, 0.038210, -0.832290, -0.352310, -0.958220, -0.138300, -0.779420, 0.732340, 0.033500, 
-0.202770, -0.637150, 0.398700, -1.143540, 0.125260, -0.034140, -0.558990, -0.214980, -0.629400, -1.412330, 
1.622790, 0.132630, 1.209270, 0.112490, -0.861610, 0.653900, 0.603710, -1.086200, 0.383970, 0.811650, 
1.418580, 0.743580, -0.687310, 0.833530, -0.737460, -0.576130, -0.059090, 0.349960, -0.159670, 0.895840, 
-0.114660, -1.607480, 0.206270, 1.414410, -0.866450, 2.010780, 0.043710, -0.711730, 0.442020, 0.174990, 
-0.508670, -1.513250, -0.839540, 0.450320, -0.112510, 0.465860, 0.867670, 0.842580, 0.426580, -0.157690, 
0.735820, 0.867800, -0.390280, -1.185870, 0.482600, 0.644630, -0.275060, -0.432250, 0.750080, -0.474060, 
-1.906790, -0.175520, -0.161870, 0.538550, 0.095450, 0.718270, 0.624640, -0.492020, 1.142430, -0.267530, 
-0.193060, 0.293990, 0.618340, -0.517350, -0.712010, -0.656490, 0.357610, -0.390050, 0.598090, 0.479360, 
-0.139100, 1.566100, -0.123740, 1.190530, -0.054790, -0.592400, -0.514530, 0.883760, -0.074790, -0.824650, 
-0.185450, 0.344450, 0.533620, 0.393740, 0.018770, -0.445750, 0.321490, 0.523120, -0.725200, 0.119500, 
-1.278760, -0.791720, -0.116410, -0.259370, 1.766750, 0.045260, 0.170140, 0.115940, 0.259740, 0.369100, 
-0.524300, -0.313910, -0.224560, -2.655370, -0.575140, 0.046530, 0.942400, -0.458040, 0.644330, 0.226810, 
0.614500, 1.567540, -0.889740, 0.838110, 0.965130, -2.115380, -1.184080, 1.969300, -1.072040, 0.633790, 
-0.874380, 0.116050, -0.057420, 0.298760, -0.868610, 0.348340, -0.409260, 0.423920, -0.000450, -0.545730, 
0.030340, -0.356470, 0.142120, 0.749300, -0.669760, -0.946790, -0.847110, -0.165790, 0.208900, -1.299430, 
0.483490, -0.399740, -0.174020, -0.649830, 0.771840, 0.381550, -1.253850, 1.175360, -0.619580, -0.475910, 
0.504650, -1.126080, -0.030150, 0.186740, 0.022280, 0.261880, -0.494130, 0.171230, -0.803320, -0.096040, 
0.699020, -0.995810, 0.011730, -0.244830, -0.710790, -0.144690, -0.109270, -0.085300, -0.733410, 0.733740, 
0.328180, -0.427390, -0.781510, -0.516420, -0.295930, 0.032650, 0.382390, -0.606290, -1.242320, -0.039640, 
0.897700, 0.046590, -1.600960, -0.744460, 0.806760, -0.735430, 0.446620, -0.161050, -0.728140, -0.474430, 
1.095240, -1.491600, 0.391220, -1.130540, 1.405630, 1.183850, -0.944900, 0.639560, 0.534630, -0.299880, 
-0.344400, -0.199680, 0.268230, -0.678650, -1.308310, 1.030740, -0.166930, 1.443770, 0.205820, 0.169460, 
0.685090, -0.790570, 0.191270, -0.110850, 0.075380, -0.445200, -0.916370, 0.106810, -1.271160, 1.148990, 
-0.238000, -0.287880, 0.842460, -1.252770, -0.345410, -0.744260, -0.209190, -0.572670, -0.392730, 1.310550, 
0.003710, -1.158570, -1.411600, 0.434150, -0.143850, 0.488620, -1.087910, 0.207960, -0.987100, 0.554810, 
-0.240850, -0.150870, 0.872650, -0.708530, 0.116490, 1.853530, 0.021120, -0.630000, 0.446410, -0.317700, 
0.826980, -0.045200, -0.209470, -0.452890, 0.313470, -1.068250, 0.313440, 0.052360, 0.087150, 0.105560, 
-1.000100, 0.625510, 0.603100, -0.397440, -0.812370, 1.253950, -0.432860, 1.115400, -0.537370, 0.943700, 
0.215960, -0.678220, 0.136420, -0.844810, 1.442510, -0.903400, 0.748780, 0.188420, -0.517280, 
-0.537250, -0.632680, 0.316360, 0.649510, -0.553010, -0.733180, -1.053980, -0.051380, 0.117030, -0.748550, 
-0.001910, -0.712950, 1.033660, 0.390810, 0.845960, -0.235380, 1.471050, -0.742950, 0.848000, -0.987310, 
1.135210, -0.299510, 0.365370, 1.275490, 0.188880, 0.228790, 0.393780, -0.876750, 1.259120, 0.045080, 
-0.359000, -0.328400, -0.773280, 0.275810, 0.586280, 0.381950, -0.739710, -0.307450, -0.482520, 1.331760, 
0.508050, -0.636540, 0.749860, -0.284390, -1.643280, 0.008700, 0.117920, 0.693060, -0.124130, 0.807260, 
-0.296900, -0.191020, -0.574220, 1.259870, -1.267960, 0.551370, 0.129240, 0.998840, -0.344910, -0.349350, 
-0.087080, 1.054930, 1.080200, 0.462270, -0.249030, -0.795820, 0.418850, -1.018540, -0.662930, 0.569210, 
-0.167120, -0.020260, -0.517280, 0.526080, -0.027250, 0.224640, 0.469210, 0.538220, -0.741700, -0.225420, 
0.918420, 0.571350, -1.189930, 0.047420, -0.694720, -0.553420, -0.076880, -0.648140, -0.401110, -1.000740, 
-0.125050, 1.527070, -0.486610, -0.533200, 0.254720, -0.933700, 0.199400, -0.913190, -0.022780, 0.486470, 
0.090530, -0.133610, -1.141970, -1.529370, 0.507600, 0.748370, -0.408660, 0.837190, 0.537740, 0.073560, 
1.296420, -1.014350, 1.011170, -0.771780, -0.049750, -0.042660, 1.082340, -0.229220, 0.556570, -0.155950, 
0.672340, 0.095430, 0.351200, 0.122620, 3.376560, -1.312110, -1.096650, -0.271370, 2.170680, -0.921330, 
-1.576070, -0.534970, 1.689690, -0.703090, -1.886370, 0.790390, 0.617330, -0.191640, 0.826940, 0.220740, 
0.126460, -0.297610, 0.555750, 0.051160, 0.607730, -0.234500, -0.728040, -0.650610, 1.377780, -1.004120, 
-0.197500, -0.164150, 0.408740, 0.203410, -0.004730, -0.702520, 0.799670, -1.496210, 0.541380, -0.060170, 
0.431580, 0.375170, 1.409220, -0.091530, -0.601380, -0.635950, -0.560440, -0.168390, -1.798900, -1.290710, 
-0.146390, 0.894790, 1.291950, -0.373040, 0.901670, -0.029090, -0.759430, 0.376340, -0.179150, 0.936060, 
-0.667330, 1.249480, -0.395200, -0.357080, -0.215500, 0.241510, -0.423570, 0.377410, -0.313790, 1.050190, 
1.521650, -0.820260, 2.000520, 0.843930, 0.750750, -0.657480, -0.130250, -0.267460, 1.151140, 1.128120, 
0.459360, 0.963820, 0.792810, -0.440930, -0.180000, -0.757860, -0.748790, -0.074670, -0.786490, -0.024740, 
-0.416240, -0.665530, -0.184620, 0.791320, 1.168030, -1.297480, 0.379950, -1.584180, -0.972120, -0.130470, 
1.367520, -1.064450, -0.266650, 0.673810, -0.001360, -0.195870, -0.162920, -0.089940, 0.655080, -0.098710, 
0.025480, 1.853310, -0.562870, 0.570610, 0.061640, -0.903400, 0.664810, 1.080820, 0.085790, 0.139740, 
-0.937190, 0.839220, -0.337800, 0.096580, 0.969320, -0.103910, -0.259180, -0.032620, 0.399920, -0.017960, 
-0.848760, 0.705030, 0.194690, -0.538100, -0.014530, 1.268380, -0.231260, 0.882560, 0.338450, 0.109240, 
1.026450, 0.206730, -1.497840, -0.192920, 0.676730, -1.216500, -0.402920, -0.771730, -0.451130, 1.105930, 
-0.545570, -0.404320, -0.189000, -0.321790, -0.003010, -1.172460, -0.694740, -0.047280, -0.413350, -0.849070, 
0.424130, 0.181390, -0.904200, -0.094030, -0.741860, -0.985000, -0.362080, -0.195670, -0.566410, 0.495850, 
-0.282790, -0.484120, -1.208330, -0.698610, -0.564870, 0.688140, 1.148800, -1.088850, -1.079450, 
-0.499750, 1.024910, -0.405430, -0.279560, -0.137480, 0.495390, -0.709440, 0.704050, 1.552590, 0.263760, 
0.928380, -0.130800, -0.208390, 0.436610, 0.793220, 0.681680, -1.324150, 0.337640, 1.201180, 0.885450, 
0.841130, -0.271260, -0.032060, -0.189150, 0.392540, 0.210950, 0.148250, -0.123290, -0.031220, 0.748240, 
0.106300, -1.049010, 0.220780, 1.004730, -0.531390, -1.020280, 0.496320, 0.206100, 0.370660, -0.657190, 
-0.345500, 0.099120, -1.188410, -1.074690, 0.616240, 0.775250, 0.495660, 0.983770, -0.431230, -0.547900, 
-1.168360, -0.218840, 0.442170, -0.449600, -0.962060, -0.567030, 0.299670, 0.635150, 1.055080, -1.033150, 
-0.165710, 0.712250, -0.593530, -0.421250, -0.904200, 0.818410, 0.040620, 0.261970, 0.006940, -1.762590, 
-0.269150, -0.203350, -1.628340, -1.027500, 1.084250, 0.279780, 0.729910, 0.689360, 1.085310, -0.901880, 
0.279920, -0.400070, -0.640370, 0.741160, 0.295670, -0.099870, 0.710760, -0.226330, 0.293970, 0.683060, 
-1.667520, 0.838600, -1.224080, 0.972570, -0.677580, -0.520250, -0.320240, 0.586100, -0.481920, 1.213440, 
1.907480, 0.243570, 0.521470, -0.794730, 0.139100, -0.204930, 0.228750, 0.702290, -0.775030, -0.300690, 
-0.583650, 1.280270, 0.067950, -0.788280, -0.296470, -0.123170, 1.399070, -0.333440, -1.377720, 0.879450, 
-0.067610, 0.186320, -0.947260, 0.246460, 0.775700, -1.501670, 0.648090, -1.025810, 1.282220, 0.170640, 
-0.220570, -0.768980, 0.293390, -0.139190, -0.353000, 0.120030, 0.319180, -0.951120, -0.128460, 1.036770, 
-0.493210, -0.473360, 0.234750, -1.292170, -0.752560, 0.269420, -0.100520, 1.461750, 0.160740, 0.059980, 
-0.176000, 1.944360, 0.726580, 0.166130, -1.032130, 0.075250, 0.114050, -1.572200, -0.557080, 0.636010, 
0.225890, -0.083300, -0.302900, -1.562610, 0.320270, 0.895770, 0.749590, 0.024010, 1.113710, 1.715620, 
0.091510, -0.297240, 0.915890, 0.363030, 1.296680, -0.497300, 0.057990, 0.439430, 0.734750, -1.069670, 
0.564300, -1.707100, 0.540450, -0.181960, 0.165660, -0.256410, -0.280670, 0.372180, -0.039360, -0.806080, 
0.281800, 1.324990, -0.090880, -0.762130, 0.429770, 0.423810, 0.305850, 0.671240, -0.811840, -0.117780, 
-1.234610, 0.344130, -0.485880, 0.119300, -1.562810, 0.624220, 0.187630, 0.653520, -0.600640, 1.207330, 
-0.705080, 0.794670, 1.279090, -0.529050, 0.020560, 1.150830, 1.119180, 1.371100, -0.389690, 0.696890, 
-0.372610, -0.482240, -0.819120, 0.012120, -1.042760, 0.266850, -0.561570, 0.062090, 0.043800, -0.242080, 
-0.428720, -0.025460, 0.291410, 0.063250, -1.551840, 0.112050, 0.001970, 0.829600, 0.797660, 0.081900, 
0.169900, 1.045720, -0.579670, 0.715300, -0.397390, 0.439560, -0.143270, -0.594240, -1.016120, 1.046180, 
0.192290, -0.036300, 1.651490, -0.309440, 0.262070, 0.512870, 0.691960, -0.057060, -0.525110, -0.125670, 
1.423480, -0.675430, 1.248460, -0.848850, 1.282840, 0.038660, -0.233970, -0.058840, -0.473380, -0.511670, 
-0.401090, -0.968480, 0.371800, 0.805260, -0.633960, -0.574230, -1.168810, 0.253680, -0.354720, -0.309420, 
-0.424370, -0.493820, 1.184650, 0.165030, 0.027850, -0.963510, 0.236480, -0.554490, -0.176420, -1.126690, 
-0.697760, 0.580600, 0.379420, -0.964180, -0.201660, 0.778670, 0.075140, -0.252420, 0.774220, 
-0.418790, -2.972290, 0.745910, 0.944150, -0.606720, -1.823320, 2.633100, 2.410050, 1.441630, 1.377680, 
-2.114730, 0.179460, -2.613050, -0.484590, 0.361010, 0.446470, -1.479010, -0.627560, 2.350080, 1.866740, 
0.779990, -1.595410, -0.606150, -0.021020, -1.877490, -1.807000, -0.688480, -0.405810, -0.768170, -1.088480, 
0.322550, -0.617730, -0.154480, 0.820020, -0.248470, 1.262170, 0.932410, -0.472330, -0.712760, -0.435340, 
0.499960, 0.082440, 0.505270, 0.956740, -0.450230, 0.247060, -0.027440, -0.103820, 0.576960, -0.862540, 
-0.033120, -0.211570, 0.646910, -0.175920, -0.303960, 0.758280, 0.660830, 0.881550, -0.002060, 0.637330, 

1.987840, -0.660570, 0.195830, 1.091690, 2.487940, 0.250230, 0.818170, -0.486420, 0.413790, 0.938310, 
0.081520, -0.064550, 1.341520, -0.954470, -0.389290, -0.157910, -0.727410, 0.244090, -2.040230, -0.399720, 
-0.507820, 0.453390, -0.568070, 1.469740, -0.217880, 1.547200, -0.106260, 1.322150, -2.637110, -1.162900, 
-0.274850, -0.028130, 0.590580, 0.765580, -0.982940, -0.190420, 0.725570, -0.003890, -0.120640, 0.184490, 
-0.974970, 0.308670, 0.820060, 0.926370, 0.371200, -0.526830, -1.455180, 1.395300, -0.165670, 0.425950, 
0.734420, 0.805960, -0.196750, 0.277220, -0.032940, 0.475820, 1.033120, -0.324390, 0.459380, -0.159050, 

-0.206450, -1.201000, 0.545590, -1.067720, 1.055500, -0.117200, -0.093410, -0.079620, -1.038470, 1.306930, 
-1.652660, 0.562580, 0.599490, -0.365110, -1.699130, -0.326310, -0.072620, -1.587830, -0.560120, -2.385130, 
0.039080, 0.164050, 0.577470, -0.669960, 0.435480, -0.288250, 0.611780, 1.901010, -1.403330, -1.178970, 
-0.292840, -0.095220, 0.301190, 0.732550, 0.172840, 0.918350, 0.264980, -0.702010, -0.171720, 0.684560, 
-1.321070, 0.354330, -0.090420, 0.287600, -0.727040, -1.303870, 0.502180, -0.349930, -1.404340, 0.123320, 
0.087260, 0.177740, -0.878180, -0.670620, -0.163200, 0.560310, -1.590100, -1.177110, 0.410000, 0.857880, 

1.020370, -0.482760, 1.024190, 1.205870, 0.477870, -0.230180, -1.401620, 1.056040, 1.179940, -0.232420, 
-1.423520, 0.940760, 1.024040, 0.097590, -2.200500, -0.101880, -0.856910, -0.578120, -1.407950, -0.186420, 
-0.426430, 0.730490, -0.873690, 0.444590, 2.028330, -1.031420, -1.842610, 1.012700, -0.614930, -1.149570, 
-0.861160, 1.171630, 0.240830, 0.648030, -0.129030, -0.319970, -0.006940, -0.282350, 0.064750, 1.003340, 
-0.612540, 0.638830, 0.598010, -0.711900, -0.168670, -0.191290, -0.638750, 0.741840, -0.245380, -0.301560, 
0.453580, -1.222410, -0.093070, 0.381070, 0.898760, -0.501860, -0.216210, -0.362360, -0.239840, 0.420300, 

-0.234510, 0.756560, -0.527400, 0.595500, 0.860170, 0.358350, 0.144420, -0.061820, 1.090540, -1.279770, 
-0.058660, -1.032130, 0.005930, 0.664850, -0.902200, -1.835180, 0.173030, -0.692190, -0.476900, -0.526170, 
0.075340, 0.847160, 0.499350, -1.387620, 0.054620, 0.032670, -0.213840, -1.118620, -0.633190, 0.266920, 
-1.046860, -0.653860, 0.423060, -0.242880, -0.385310, -0.602270, -0.025360, 0.602400, -0.894830, -0.347050, 
-0.736350, -0.256750, -0.069540, -0.227540, 0.130830, -0.979710, 0.413840, 0.181280, 0.522860, 1.135740, 
0.396050, -0.168030, 0.264120, -0.319610, 0.802820, 0.566680, -1.085370, 0.590540, -0.597110, -0.146360, 

0.343230, -0.340470, 1.378940, -1.103860, -1.447420, -1.663940, 0.789700, 0.165640, -0.654660, 0.447270, 
2.450460, -0.930170, 0.099190, 1.051520, 0.578980, 1.178330, -0.025110, -0.270280, -1.490910, 1.363040, 
0.576340, -0.712380, -1.738940, 1.608190, -2.229530, -0.599150, -0.270340, 0.293320, 0.342780, 1.209840, 
0.602980, -0.077260, 0.432250, 0.195740, 0.368550, -0.072330, -0.414360, 0.107360, 0.252740, 0.286880, 
0.044540, 0.068210, -0.213810, 1.116690, 0.845310, 0.639280, 0.111480, -0.020580, -0.349300, 0.823590, 
0.658140, 0.358680, 0.529520, -0.822050, -0.004310, 0.655310, 1.286280, -0.251610, 0.705140, -0.222560, 

0.650870, 0.667910, -0.114890, 0.550040, -0.315090, 1.033360, -0.005870, 0.020220, -0.334210, 0.013620, 
0.177480, -0.081010, -0.624310, -0.450140, 0.090150, -1.086760, 0.091330, -0.805950, -0.290880, -1.244770, 
-1.182840, 1.291120, -0.697070, -0.388880, 0.363540, 0.753380, -0.099760, 1.068590, -0.777620, -0.611770, 
0.150990, 0.377820, 1.035400, -0.236470, -0.113100, -0.653140, 0.331310, -0.589370, -0.202350, 0.467110, 
-0.365090, 0.274940, 0.250800, 0.078890, -1.208910, 0.383170, -1.094900, -0.600390, -0.660300, 0.845220, 
0.155150, -0.368670, 0.128970, 0.116390, 0.624500, 0.724300, -1.228390, -1.609530, 0.467520, -0.277450, 

0.368150, 1.074030, 0.050810, -1.400990, 0.536990, -0.618350, -0.152300, 0.054020, 0.515040, 1.441340, 
0.386240, 0.040220, -0.060840, 0.283390, -0.291470, -1.787640, 0.620250, 0.230480, -1.008140, 0.658510, 
-0.167590, 0.200050, -0.442370, 0.020300, 0.977620, -0.745320, -0.462470, -0.484050, -0.404570, 0.769560, 
-1.099010, -0.710750, 0.450200, -0.328300, -0.418160, -1.222680, 0.056820, 1.152440, -0.249800, 0.482010, 
-0.534900, -0.950710, 0.275050, -0.932220, -0.611080, -0.043640, -0.332380, -0.727890, 0.430000, 1.145840, 
-0.455010, -1.016600, -0.320280, 0.676210, -0.495780, 0.406200, 0.267860, -0.788810, -0.218490, -0.750060, 

0.716050, -2.373660, -2.357150, -0.068020, -0.888640, 0.702640, -1.048030, 3.098780, -1.214540, -0.758620, 
-0.069200, 0.409710, 0.123060, -1.323720, -1.043360, 1.481210, -1.264060, 0.787340, 1.144380, -1.458530, 
0.439210, 0.941940, -0.110250, 1.058690, 0.738220, 0.591770, -0.774910, 0.409520, -2.196510, -1.013940, 
0.270530, 0.354850, -0.313510, -1.134590, -0.915660, 0.037940, 0.097270, -0.647700, 0.564940, -0.218470, 
0.379830, -0.971710, -0.019060, -0.335050, -0.217920, -0.297280, 0.262060, -0.791860, 0.635670, 1.068100, 
1.042580, -0.832280, -0.888390, 0.259420, 0.025980, 1.038600, -0.428600, -0.388530, 0.941810, 0.201950, 

-0.627150, 1.389100, 2.372110, -1.528500, 1.600740, -0.749240, 1.069920, 0.796610, -1.053440, -0.331580, 
-0.034110, 0.142840, 0.754080, -0.451990, 1.302210, -1.126670, -0.807420, 0.399840, 0.318120, -2.079090, 
-0.215130, -0.046480, 0.249650, -1.263120, -1.455460, 0.524850, -1.118170, -0.082080, 1.927600, 1.227490, 
0.697600, -0.238690, -0.429790, 0.068640, -1.472930, -1.244810, -0.522130, 0.684400, -0.126970, 0.980780, 
0.122090, 1.738690, 0.823280, -0.334870, 0.523200, 0.944640, -1.400830, -0.652510, -0.226310, 0.935910, 
1.106790, -0.925940, -0.269860, -0.320470, -0.343310, -1.673010, -0.149330, -0.110100, -0.831390, 0.198260, 

1.151960, -1.287870, -1.206030, 0.396350, 1.516920, -0.563300, -1.074820, -0.656870, 1.642650, -0.283030, 
0.149540, 0.549560, 1.054030, -0.714310, -1.074010, -0.699950, -0.576060, 0.922830, -0.888700, 0.645450, 
-0.968210, -0.546820, -0.329510, 1.103690, -0.243680, 0.203540, -0.697820, -0.749620, 1.106360, -0.834310, 
-0.854910, 0.233160, 0.080790, -0.387260, -0.583830, -0.683280, -0.815290, -0.594830, 1.197250, -0.421780, 
0.585000, 0.130860, 0.526260, -1.680760, -0.211520, -0.318430, -1.360390, -0.228530, 0.315570, 0.313720, 
-1.040410, -0.593210, -0.301780, 0.783790, 0.131270, -0.325460, -0.996230, -0.956960, -0.461030, -0.222200, 

-1.275800, 0.089520, 1.391220, -0.725860, 0.650390, -0.220310, 1.460890, 0.158350, 1.201580, -0.436120, 
0.864120, 0.461970, 0.816360, -0.214910, -1.228800, 0.850120, -1.330020, -2.109620, -0.655000, 0.645870, 
-1.218330, 0.032730, -2.227640, -1.226190, -0.692400, 0.147330, 1.313210, -0.385750, -0.361240, -0.661920, 
-0.452410, -0.282760, 0.051360, -0.320280, -0.043150, -0.140710, -0.216040, -0.029370, -0.276320, 0.005880, 
-0.003190, 0.369940, -0.524370, 0.057570, 0.770340, 0.453100, -0.863000, 0.383000, -0.084880, 0.736220, 
1.469520, -1.016410, -0.397230, 0.694210, 0.172190, 0.459300, -0.912630, 0.128940, -0.466850, 0.454150, 

-0.790740, -0.225440, -0.286700, -1.182960, 0.720180, -0.564540, 0.984190, 0.221280, 0.937120, -0.183260, 
-0.458480, 0.493290, 0.091850, 0.101080, 0.484100, 0.083360, -1.095260, -1.052300, -1.702470, 0.775160, 
-0.207620, -0.310070, 1.206360, -0.744910, -0.994300, -0.668710, -0.516420, 0.123100, -0.263470, 0.091770, 
-0.753040, -1.171240, -0.919780, -1.183280, 0.837320, 0.744620, 0.374960, 0.324770, -0.871630, 0.062850, 
0.079080, 0.724950, 0.759420, 0.226800, -0.020960, -0.882690, 0.548110, 0.754080, -0.098140, -0.663140, 
-0.518660, -0.152190, -0.272840, 0.014050, -0.260650, 0.570300, -1.222430, 0.642880, -0.874960, 0.001960, 

1.026060, 0.610350, -0.384380, -0.447900, 1.091820, 0.312210, -0.162330, 0.001820, -0.730390, 0.972390, 
-0.084960, -0.744620, 1.916210, 0.331530, -0.193670, -0.501500, -1.753880, -0.285270, 0.689990, -0.001150, 
0.578080, -0.471460, -0.108090, -0.704380, -0.134270, 0.782390, 0.135360, -1.691240, 0.260060, 1.318380, 
-0.745990, -0.589130, 0.145780, -0.464880, 0.561300, -0.274490, 0.231040, 1.047160, -0.593900, -0.867220, 
-0.099450, 0.004750, 0.183080, 0.294410, 0.349580, 0.112680, -0.315300, 0.928860, 0.381720, -0.307330, 
0.770760, 0.178420, -0.469740, -0.843890, 0.381670, 0.742450, -1.241770, -0.576700, -0.160780, -0.154610, 

-0.429490, -1.614230, 0.445730, 0.891830, 1.386050, 1.146600, -0.223300, 0.099410, 0.908580, 0.253030, 
0.017980, -0.210060, -0.154490, 1.440550, -1.434400, -1.473570, -0.886540, -0.732820, 0.746140, -0.516870, 
0.489760, 0.631820, 0.127090, 0.224210, -2.412400, 0.300620, -0.361950, 0.271990, -0.620000, -0.078020, 
0.195890, -0.171050, -1.440560, -0.318400, -0.842410, -0.028810, -0.823740, -0.341850, 0.261440, 0.971450, 
0.007200, -0.438530, 1.229900, -1.250370, 0.447490, -0.177790, -0.000140, -0.313650, 0.375290, -0.416030, 
0.790440, -0.291410, 1.229130, -0.339910, -0.446330, -0.680610, -0.349810, -1.400510, -0.075360, 0.590020, 

0.574760, -0.152680, -0.981130, -0.618550, -0.229230, -0.577460, -0.231610, -1.233520, 0.935760, 1.548200, 
0.851580, 1.523720, 0.870670, 0.518270, -1.757860, -0.859100, 0.883170, -1.356660, 1.042190, -0.612960, 
-1.407110, -0.465290, 0.058870, 0.262040, -0.810790, 0.976200, 0.122640, -0.959670, -0.181340, -1.072660, 
-0.379070, 0.608470, -0.906140, -0.643510, 0.265640, -0.752490, 0.540800, 0.017980, 0.977720, -0.139660, 
-0.095030, 0.810020, -0.149970, 0.238120, 0.228360, -0.173570, -0.598760, 0.587600, -0.285630, 0.505670, 
-0.921700, -0.514220, 0.687960, -0.316270, -0.372870, -1.654360, 0.072990, 0.691310, 0.816880, -0.181420, 

-1.224620, -0.217290, -1.109660, -1.692040, 0.795370, -0.199570, -1.504740, -0.476090, 0.539940, -2.605700, 
0.669560, -0.982010, 0.025330, -0.457750, -0.630750, 1.165530, -0.287890, 0.579910, 0.485510, -0.326020, 
2.325100, 0.459700, -1.331200, -1.587730, 0.875070, -0.479700, 0.285610, -0.298030, 1.059030, 0.971800, 
0.217990, 1.022380, 0.293620, -0.818120, -0.553290, 0.457730, 0.247860, -0.397730, -0.496540, 0.146880, 
-0.543760, -0.470650, 0.505110, 0.992910, -0.056010, -1.400280, -0.920960, 0.056620, 0.820360, 0.290490, 
-0.982970, 0.058420, -0.721450, -0.197180, -0.467430, -0.883480, -1.429200, -0.613060, -0.451590, -0.116370, 

-0.355820, -0.761490, -0.745460, 0.140710, -0.667750, -0.741550, 0.209440, 0.089300, -0.523260, -0.200140, 
1.191140, -0.383100, -0.698360, 1.542250, -1.128270, 0.430860, -1.155430, -2.442910, -2.025860, -1.083440, 
-0.002600, -0.674300, -1.079880, -0.681270, -1.390180, -0.334440, -0.469800, 0.263360, 1.431350, 1.445510, 
0.766240, 1.021430, -1.079560, 0.356200, -0.292380, -0.489520, -0.124970, -1.051900, -0.014740, -0.296400, 
-0.619420, -0.104450, -0.023940, -1.057080, -0.494130, -0.474670, -1.085030, -0.156810, -0.722430, -0.132750, 
-0.746100, -0.681880, -0.431530, 0.331870, -0.462670, -0.251200, -1.057980, 0.077720, 0.312720, -0.086230, 

-0.326190, -0.235940, 0.374750, -0.322600, -0.240550, 0.636490, -1.145310, -0.491390, -0.361950, -0.955770, 
0.260490, -0.704260, -0.018590, -0.444140, -0.113390, -0.919180, 0.087750, -0.129150, 0.465950, 0.350780, 
0.198000, 0.190550, 0.152470, -1.486720, 0.731760, -0.616300, -0.432690, 0.244200, 0.305750, 0.317410, 
-1.121510, -0.318080, -0.414670, -0.587180, -0.405150, 0.013100, -0.954650, -0.275470, -0.053200, 0.040910, 
0.701930, -0.399930, 0.433550, -0.413990, -0.462200, -0.546000, -0.469810, -0.437330, -0.017700, -0.611140, 
0.567170, -0.141740, -0.041360, 0.668160, -0.464490, -0.231350, -0.478960, -0.444590, 1.245580, -0.878750, 

-0.280720, 0.521560, -0.177980, -1.088110, 0.078690, -1.090680, -0.459710, 0.575040, 0.682290, -1.160150, 
-1.284400, 1.761360, 0.851680, -0.682980, 1.017520, -0.389480, -0.788860, -0.696390, 0.035120, 0.336200, 
-1.368340, 0.348260, -0.528700, 0.754160, -1.710940, 0.436130, -1.845780, -1.581550, 0.923700, 0.201840, 
-0.317820, -0.582440, 0.361640, -0.523410, -0.486650, -0.502120, -0.372320, -0.905280, -1.332430, 0.320560, 
0.467670, 0.689600, 0.845770, 1.333740, 0.476730, -0.096430, 1.187320, -0.529420, 0.182690, 0.648300, 
-0.651420, 0.066490, -0.249830, -0.534040, -0.351970, 0.310330, -0.724100, -0.015470, 0.319670, -0.502280, 

0.254950, -0.206710, 0.765450, -0.243420, -0.468070, -0.148480, 1.202970, 0.683090, -1.349990, 1.523230, 
-0.490630, -0.577040, -1.196720, -0.119800, 0.912110, -0.695740, -0.098750, -0.743590, -1.154540, -0.528480, 
-0.596000, 1.152660, 0.108870, 1.006520, 0.234520, 0.515260, -0.576700, 0.174020, -0.769660, -0.843920, 
-1.256830, 0.963030, -0.531670, 0.665290, 0.541150, -0.267790, -0.084660, 1.202450, -0.285730, 0.544080, 
-0.312000, -0.773740, 0.265620, -0.980650, 0.067610, -0.170320, -0.864620, -0.794690, 0.754310, 0.300310, 
0.296890, 0.175280, 0.100200, 0.032320, 0.004680, -0.436670, -0.825660, 0.442180, -0.260440, 1.002970, 

-1.343980, -0.004680, -0.749040, -1.990220, -0.014270, 0.851490, 0.922680, 1.856790, 2.086190, -2.304520, 
-1.758380, -0.854430, -0.793570, 2.030870, -2.677650, 2.445380, -2.972390, -0.224690, -0.810470, -1.956550, 
-1.043620, 0.333560, -0.082060, -1.262480, 1.865990, -0.707240, 1.167520, -1.558210, 0.955510, 0.107690, 
0.208030, -0.192060, -0.653000, -0.180550, -1.385670, -0.785680, 0.432730, -0.261480, -0.024060, -0.251010, 
0.051740, -0.471310, 0.514370, -0.759030, 0.318060, -0.239590, -0.686440, -0.966780, -0.176230, -0.806870, 
0.209580, 0.328090, -0.838780, -0.077950, 0.676860, -0.321160, -0.834020, 0.251480, 0.330590, -0.034940, 

0.373390, 0.942210, -0.848110, 0.021560, -0.669060, 0.445810, 1.269980, -0.260510, 0.920880, -0.366820, 
-1.497220, 0.266580, 1.086440, -0.372090, -0.502840, -0.803670, 1.057060, -1.730580, -0.859590, -0.293090, 
0.399720, -0.684020, 0.026510, -0.015610, -0.078530, 1.378820, -1.755800, 0.726040, -0.874920, -0.248460, 
0.336090, -0.377380, -0.617160, 0.142890, 0.161620, 0.036910, -0.157180, -0.578110, 0.126450, 0.103390, 
0.350590, -0.820160, 0.955480, -0.142430, -0.282120, 0.807480, 0.122340, 0.581380, -0.119910, 0.945070, 
0.392130, -0.474150, -0.515180, -0.285800, -1.086840, 0.315610, 0.246920, -0.368870, -0.369630, -1.014880, 

0.244330, -1.127260, -0.116810, -0.660110, 0.695320, -0.369100, -0.109240, -0.223900, -0.462290, 0.379320, 
-1.019230, -0.851430, -1.097590, -0.273430, 0.445940, -0.496800, 0.145450, -0.836410, 0.368820, 0.352470, 
0.377160, -1.064060, -0.502560, -0.735600, -0.383580, -0.564130, -0.619250, 0.480630, 0.364770, 0.150150, 
-0.732310, -0.127600, 0.022210, 0.732000, -0.042420, -1.134940, -0.440890, -0.111680, -0.485560, -1.150870, 
0.283840, 0.260890, 0.119000, -0.094930, -0.649620, -0.614920, -0.738480, 0.618980, 0.213850, -0.511120, 
0.113420, -0.972710, 0.661260, 0.038500, -0.587320, -0.281540, 0.307610, 0.335150, 0.871880, -0.256020, 

0.153060, -0.807180, -0.877880, 0.634670, -1.012630, -0.118980, -0.172740, -0.000210, -1.079410, 0.212050, 
-0.655400, -0.622210, -0.237620, -0.181020, -0.189430, 0.217490, -0.830210, 0.106100, -0.315180, 0.138270, 
0.071090, 0.262630, -0.670130, 0.135300, -0.353790, 0.987000, -0.114560, 1.015360, -1.210420, -0.662200, 
-0.699590, 0.831660, 0.425050, -0.262290, -0.286930, 0.013740, 0.193710, 0.138130, 0.002130, -0.911850, 
-0.675220, -0.960270, -0.436100, 0.038400, -0.779560, -0.111520, -0.436580, 0.035110, -0.871020, -0.482210, 
-0.626710, 1.131420, -0.312210, 0.099310, 0.157680, 0.976010, -1.133660, 0.874590, -1.027130, 0.403270, 

-0.742050, 0.028730, 0.752700, 0.864370, 0.074850, -0.536270, 0.453940, -0.025680, 1.159120, 0.063030, 
-0.387410, 0.958570, -0.866980, -0.264940, -0.821480, -0.528060, -0.710900, -0.875180, -1.228900, 0.094890, 
-0.895260, 0.581180, -0.614200, -0.316470, -0.256020, 0.457550, -0.282480, -1.255490, -0.435960, -1.003110, 
0.533950, -0.372550, 0.878060, -0.916970, -0.849050, 1.223910, 0.147040, -0.452670, -0.799870, -0.323710, 
-0.209380, -0.139770, -0.697320, 0.801910, -0.158600, -0.555090, 0.706120, -0.452060, -0.860390, 0.777190, 
0.014770, 0.668060, -0.987390, -0.842180, -0.013820, -0.374110, -1.832140, 0.415530, -0.553950, 0.040800, 

0.749770, 0.992880, -0.250950, 1.928900, -1.673660, 3.195740, 0.010700, -0.061540, 1.527640, 0.432150, 
-1.980260, -0.848230, -0.710310, 1.940080, -1.596330, -0.018170, -1.150750, 0.852720, 1.616850, 0.124660, 
0.876390, 0.661680, 1.688020, 0.566050, -0.144210, 1.604290, 0.897190, 0.423460, 0.270850, 2.350100, 
-0.554470, 0.165330, -0.102530, -0.059270, 0.798160, -0.464000, -0.037030, 0.275970, 0.204000, 0.281820, 
-0.515990, 0.513820, -0.609930, -1.276160, -0.151330, 0.198000, -0.225850, -0.538470, -0.050890, -0.890880, 
0.355750, 0.690310, 0.932300, 0.640130, 0.766810, -0.709310, 0.362800, -0.177330, -0.660950, 0.193190, 

0.021350, 0.510150, 0.508250, 1.133460, -0.090430, 0.846090, 2.393870, 0.978620, -1.799320, 0.960190, 
0.313300, -0.569280, 0.872050, -0.087010, 1.502670, -1.418460, -1.357260, 1.899800, 0.091370, -0.432100, 
-2.483980, -0.073250, -0.520600, -0.579800, -0.165600, 0.623580, -0.612810, 0.920360, 0.193940, -1.644700, 
-0.547030, -0.052720, -0.706390, -0.099950, 0.751350, 0.259140, 0.126680, 0.449960, -0.019030, -0.037530, 
0.343460, 0.493990, -0.875850, -1.163740, -0.549890, -0.885360, 0.186880, 0.864760, 0.083130, -0.232570, 
-0.236670, 0.234780, 0.339290, -0.774620, 0.338300, -0.362970, -0.840360, 0.007710, 0.130690, -0.530520, 

-0.746020, -0.046620, -0.712480, -0.650740, 0.067990, 1.225240, 0.148320, -0.373580, -0.275800, -0.914260, 
-0.691240, -0.127360, 0.863540, -1.483640, 0.531010, -0.276940, -0.711470, -0.945310, -0.318200, -0.066040, 
-0.032360, -0.855890, -0.690610, -0.427890, -0.086660, -0.704630, 0.677660, 1.124720, 1.002630, -0.362260, 
-1.249510, -0.040360, -0.186490, 0.254670, -0.578360, -0.046860, 0.567160, -0.231990, -0.206970, 0.569220, 
0.783180, 0.386260, -0.612020, 0.474720, 1.246740, 0.557140, 1.063310, 0.176240, -0.291520, 0.585600, 
-0.255050, -0.443180, -0.176560, 0.780370, -0.537440, -0.451240, 0.626560, 0.089540, 0.270430, 0.318730, 

0.831300, -1.561060, -0.908140, -0.818390, 1.270060, 0.366130, 1.578710, 1.371590, 0.677720, 0.916090, 
0.321310, -0.165580, 0.874610, -0.930010, -0.697350, 0.223910, -0.271600, -1.827480, -0.062330, 0.439000, 
-1.377890, 1.657690, 0.661960, 0.030680, -0.896690, 0.206490, 1.121420, 0.703280, -0.266620, -0.474640, 
-0.800950, -0.696870, -0.001130, 1.484540, -1.402820, -0.150890, -0.498520, 0.896870, -0.077070, -0.387580, 
-0.719030, 0.372720, 1.029720, 0.211790, -0.540080, 0.479700, -0.923510, 0.809540, -0.166610, 0.830420, 
0.100650, 0.759310, 0.052420, 0.645430, -0.165200, -0.073540, -0.866010, 0.229670, 0.585370, 0.834190, 

0.564150, -0.468560, 1.170650, -0.676430, 1.195870, 1.049160, 0.639750, -0.574580, -0.727700, -0.878860, 
1.068370, -1.130510, -1.304300, 1.304280, -0.613980, -0.665310, 0.599010, -1.610090, 0.844030, -1.703520, 
-0.552570, 1.688090, -0.612130, -0.151420, 0.506280, 0.738510, -1.126810, -0.561950, 0.438950, -0.529810, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, 0.853210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (inp2) */
      0.0, -0.600200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (inp3) */
      0.0, -0.687710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (inp4) */
      0.0, -0.297910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (inp5) */
      0.0, -0.766560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (inp6) */
      0.0, 0.376000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (inp7) */
      0.0, 0.422160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (inp8) */
      0.0, 0.743220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (inp9) */
      0.0, -0.129870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 10 (inp10) */
      0.0, 0.531420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 11 (inp11) */
      0.0, -0.453020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 12 (inp12) */
      0.0, -0.914860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 13 (inp13) */
      0.0, -0.205040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 14 (inp14) */
      0.0, 0.055450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 15 (inp15) */
      0.0, -0.562820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 16 (inp16) */
      0.0, -0.683760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 17 (inp17) */
      0.0, -0.145420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 18 (inp18) */
      0.0, -0.587520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 19 (inp19) */
      0.0, 0.868780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 20 (inp20) */
      0.0, 0.177730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 21 (inp21) */
      0.0, -0.067110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 22 (inp22) */
      0.0, -0.541730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 23 (inp23) */
      0.0, 0.936170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 24 (inp24) */
      0.0, -0.238430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 25 (inp25) */
      0.0, 0.810520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 26 (inp26) */
      0.0, 0.840580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 27 (inp27) */
      0.0, -0.898760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 28 (inp28) */
      0.0, -0.135060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (inp29) */
      0.0, 0.703420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 30 (inp30) */
      0.0, 0.069710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 31 (inp31) */
      0.0, -0.535470, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (inp32) */
      0.0, 0.658910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 33 (inp33) */
      0.0, 0.519200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 34 (inp34) */
      0.0, 0.974160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 35 (inp35) */
      0.0, -0.347930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 36 (inp36) */
      0.0, -0.695490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 37 (inp37) */
      0.0, 0.156620, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 38 (inp38) */
      0.0, 0.697290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 39 (inp39) */
      0.0, -0.032620, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 40 (inp40) */
      0.0, -0.613930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 41 (inp41) */
      0.0, 0.286170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 42 (inp42) */
      0.0, -0.514150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 43 (inp43) */
      0.0, -0.562630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 44 (inp44) */
      0.0, 0.246880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 45 (inp45) */
      0.0, 0.620310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 46 (inp46) */
      0.0, -0.964140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 47 (inp47) */
      0.0, -0.675050, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 48 (inp48) */
      0.0, 0.691410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 49 (inp49) */
      0.0, -0.065770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 50 (inp50) */
      0.0, -0.423630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 51 (inp51) */
      0.0, -0.826960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 52 (inp52) */
      0.0, -0.284240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 53 (inp53) */
      0.0, 0.350480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 54 (inp54) */
      0.0, -0.110130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 55 (inp55) */
      0.0, 0.912680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 56 (inp56) */
      0.0, 0.566540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 57 (inp57) */
      0.0, -0.433610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 58 (inp58) */
      0.0, -0.491890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 59 (inp59) */
      0.0, -0.216570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 60 (inp60) */
      0.0, 0.600280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 61 (inp61) */
      0.0, -0.213680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 62 (inp62) */
      0.0, 0.023370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 63 (inp63) */
      0.0, 0.392200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 64 (inp64) */
      0.0, -0.819340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 65 (inp65) */
      0.0, -0.277450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 66 (inp66) */
      0.0, -0.825080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 67 (inp67) */
      0.0, 0.136510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 68 (inp68) */
      0.0, -0.260590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 69 (inp69) */
      0.0, 0.841180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 70 (inp70) */
      0.0, -0.315370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 71 (inp71) */
      0.0, 0.242260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 72 (inp72) */
      0.0, -0.364360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 73 (inp73) */
      0.0, -0.659220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 74 (inp74) */
      0.0, -0.980480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 75 (inp75) */
      0.0, -0.038890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 76 (inp76) */
      0.0, 0.545830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 77 (inp77) */
      0.0, 0.541690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 78 (inp78) */
      0.0, -0.134110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 79 (inp79) */
      0.0, 0.028690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 80 (inp80) */
      0.0, 0.736630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 81 (inp81) */
      0.0, 0.408630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 82 (inp82) */
      0.0, 0.342560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 83 (inp83) */
      0.0, -0.364020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 84 (inp84) */
      0.0, 0.120910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 85 (inp85) */
      0.0, -0.104560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 86 (inp86) */
      0.0, 0.309790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 87 (inp87) */
      0.0, -0.909540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 88 (inp88) */
      0.0, -0.153990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 89 (inp89) */
      0.0, -0.648070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 90 (inp90) */
      0.0, -0.283090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 91 (inp91) */
      0.0, -0.438340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 92 (inp92) */
      0.0, -0.845870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 93 (inp93) */
      0.0, -0.876110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 94 (inp94) */
      0.0, 0.162910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 95 (inp95) */
      0.0, 0.183900, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 96 (inp96) */
      0.0, 0.199070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 97 (inp97) */
      0.0, 0.058330, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 98 (inp98) */
      0.0, -0.171310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 99 (inp99) */
      0.0, 0.035340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 100 (inp100) */
      0.0, 0.679730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 101 (inp101) */
      0.0, -0.659980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 102 (inp102) */
      0.0, -0.997060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 103 (inp103) */
      0.0, 0.680040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 104 (inp104) */
      0.0, -0.192290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 105 (inp105) */
      0.0, -0.030120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 106 (inp106) */
      0.0, 0.610870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 107 (inp107) */
      0.0, -0.054640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 108 (inp108) */
      0.0, 0.979980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 109 (inp109) */
      0.0, 0.381550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 110 (inp110) */
      0.0, 0.729490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 111 (inp111) */
      0.0, 0.150290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 112 (inp112) */
      0.0, 0.264330, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 113 (inp113) */
      0.0, 0.903320, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 114 (inp114) */
      0.0, 0.018350, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 115 (inp115) */
      0.0, -0.814220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 116 (inp116) */
      0.0, 0.578920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 117 (inp117) */
      0.0, 0.828610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 118 (inp118) */
      0.0, 0.510120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 119 (inp119) */
      0.0, -0.396830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 120 (inp120) */
      0.0, -0.619410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 121 (inp121) */
      0.0, 0.169350, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 122 (inp122) */
      0.0, -0.787280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 123 (inp123) */
      0.0, -0.536840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 124 (inp124) */
      0.0, -0.637820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 125 (inp125) */
      0.0, -0.759230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 126 (inp126) */
      0.0, -0.388640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 127 (inp127) */
      0.0, 0.250340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 128 (inp128) */
      0.0, -0.343040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 129 (inp129) */
      0.0, -0.838770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 130 (inp130) */
      0.0, 0.282760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 131 (inp131) */
      0.0, -0.873390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 132 (inp132) */
      0.0, -0.612400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 133 (inp133) */
      0.0, -0.658440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 134 (inp134) */
      0.0, 0.521180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 135 (inp135) */
      0.0, 0.482750, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 136 (inp136) */
      0.0, -0.923700, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 137 (inp137) */
      0.0, -0.129440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 138 (inp138) */
      0.0, -0.078420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 139 (inp139) */
      0.0, -0.201370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 140 (inp140) */
      0.0, -0.081410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 141 (inp141) */
      0.0, 0.259690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 142 (inp142) */
      0.0, -0.717520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 143 (inp143) */
      0.0, 0.727950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 144 (inp144) */
      0.0, -0.349160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 145 (inp145) */
      0.0, 0.762460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 146 (inp146) */
      0.0, -0.286570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 147 (inp147) */
      0.0, -0.081820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 148 (inp148) */
      0.0, -0.384080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 149 (inp149) */
      0.0, 0.004230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 150 (inp150) */
      0.0, -0.591130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 151 (inp151) */
      0.0, -0.962600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 152 (inp152) */
      0.0, 0.524670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 153 (inp153) */
      0.0, 0.104670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 154 (inp154) */
      0.0, 0.853670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 155 (inp155) */
      0.0, 0.829030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 156 (inp156) */
      0.0, 0.665970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 157 (inp157) */
      0.0, 0.107220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 158 (inp158) */
      0.0, 0.142300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 159 (inp159) */
      0.0, -0.382160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 160 (inp160) */
      0.0, 0.244420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 161 (inp161) */
      0.0, -0.805540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 162 (inp162) */
      0.0, 0.232200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 163 (inp163) */
      0.0, 0.755460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 164 (inp164) */
      0.0, 0.902280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 165 (inp165) */
      0.0, -0.189870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 166 (inp166) */
      0.0, -0.861470, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 167 (inp167) */
      0.0, 0.073510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 168 (inp168) */
      0.0, -0.940960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 169 (inp169) */
      0.0, -0.035310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 170 (inp170) */
      0.0, -0.143910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 171 (inp171) */
      0.0, 0.903540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 172 (inp172) */
      0.0, 0.694460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 173 (inp173) */
      0.0, -0.698060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 174 (inp174) */
      0.0, -0.070150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 175 (inp175) */
      0.0, 0.866210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 176 (inp176) */
      0.0, 0.794860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 177 (inp177) */
      0.0, -0.825460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 178 (inp178) */
      0.0, 0.569290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 179 (inp179) */
      0.0, 0.010740, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 180 (inp180) */
      0.0, -0.467550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 181 (inp181) */
      0.0, -0.665480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 182 (inp182) */
      0.0, -0.284080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 183 (inp183) */
      0.0, 0.427970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 184 (inp184) */
      0.0, 0.975390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 185 (inp185) */
      0.0, 0.802960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 186 (inp186) */
      0.0, -0.052800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 187 (inp187) */
      0.0, 0.937460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 188 (inp188) */
      0.0, 0.826250, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 189 (inp189) */
      0.0, -0.952950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 190 (inp190) */
      0.0, -0.828020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 191 (inp191) */
      0.0, -0.523710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 192 (inp192) */
      0.0, -0.584240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 193 (inp193) */
      0.0, -0.637850, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 194 (inp194) */
      0.0, -0.898420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 195 (inp195) */
      0.0, -0.646200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 196 (inp196) */
      0.0, 0.470260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 197 (inp197) */
      0.0, -0.975310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 198 (inp198) */
      0.0, -0.959890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 199 (inp199) */
      0.0, 0.384790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 200 (inp200) */
      0.0, -0.480240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 201 (inp201) */
      0.0, -0.364130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 202 (inp202) */
      0.0, -0.074170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 203 (inp203) */
      0.0, 0.220520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 204 (inp204) */
      0.0, -0.811720, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 205 (inp205) */
      0.0, 0.497300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 206 (inp206) */
      0.0, 0.282730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 207 (inp207) */
      0.0, -0.048020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 208 (inp208) */
      0.0, 0.943020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 209 (inp209) */
      0.0, 0.821450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 210 (inp210) */
      0.0, -0.956660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 211 (inp211) */
      0.0, 0.598030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 212 (inp212) */
      0.0, 0.579640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 213 (inp213) */
      0.0, 0.152600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 214 (inp214) */
      0.0, -0.471310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 215 (inp215) */
      0.0, 0.589200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 216 (inp216) */
      0.0, -0.841170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 217 (inp217) */
      0.0, -0.782900, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 218 (inp218) */
      0.0, -0.608460, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 219 (inp219) */
      0.0, -0.662090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 220 (inp220) */
      0.0, 0.128450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 221 (inp221) */
      0.0, -0.706080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 222 (inp222) */
      0.0, -0.568810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 223 (inp223) */
      0.0, -0.186770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 224 (inp224) */
      0.0, 0.773760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 225 (inp225) */
      0.0, -0.554770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 226 (inp226) */
      0.0, 0.981490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 227 (inp227) */
      0.0, -0.578990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 228 (inp228) */
      0.0, -0.782440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 229 (inp229) */
      0.0, 0.016030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 230 (inp230) */
      0.0, 0.382560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 231 (inp231) */
      0.0, 0.982640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 232 (inp232) */
      0.0, -0.811760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 233 (inp233) */
      0.0, -0.260080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 234 (inp234) */
      0.0, 0.918030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 235 (inp235) */
      0.0, -0.897560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 236 (inp236) */
      0.0, 0.405280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 237 (inp237) */
      0.0, -0.296570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 238 (inp238) */
      0.0, -0.204980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 239 (inp239) */
      0.0, -0.543530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 240 (inp240) */
      0.0, -0.617270, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 241 (inp241) */
      0.0, 0.051050, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 242 (inp242) */
      0.0, -0.752260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 243 (inp243) */
      0.0, -0.392230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 244 (inp244) */
      0.0, -0.122340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 245 (inp245) */
      0.0, 0.473960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 246 (inp246) */
      0.0, -0.142590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 247 (inp247) */
      0.0, -0.217960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 248 (inp248) */
      0.0, -0.766650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 249 (inp249) */
      0.0, 0.629910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 250 (inp250) */
      0.0, -0.378030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 251 (inp251) */
      0.0, -0.103810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 252 (inp252) */
      0.0, 0.080410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 253 (inp253) */
      0.0, 0.196160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 254 (inp254) */
      0.0, 0.316690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 255 (inp255) */
      0.0, -0.866360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 256 (inp256) */
      0.0, -0.178910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 257 (inp257) */
      0.0, -0.639390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 258 (inp258) */
      0.0, 0.119650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 259 (inp259) */
      0.0, 0.965500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 260 (inp260) */
      0.0, 0.064240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 261 (inp261) */
      0.0, 0.402400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 262 (inp262) */
      0.0, -0.590880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 263 (inp263) */
      0.0, 0.026840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 264 (inp264) */
      0.0, 0.697170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 265 (inp265) */
      0.0, 0.388690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 266 (inp266) */
      0.0, -0.130630, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 267 (inp267) */
      0.0, -0.679800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 268 (inp268) */
      0.0, -0.956020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 269 (inp269) */
      0.0, -0.199300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 270 (hid11) */
      0.0, -0.222580, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, -0.572360, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, 0.435180, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, 0.884090, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 0.712860, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, -0.538140, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, 0.775440, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, -0.054070, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, -0.137210, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, 0.202870, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -1.118020, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, -0.742270, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, -0.260440, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, 1.051560, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, -0.332840, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, -0.148440, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, -0.485820, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, -0.452860, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, -1.221540, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.512940, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, -0.351270, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, -0.257050, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, -0.785040, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, 0.208070, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, -0.728000, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, 0.429750, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, 0.135410, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, -0.983940, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, -0.439580, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, 0.334570, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, 1.516820, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, -1.396290, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, -0.552960, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, -1.471220, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, 0.320030, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, 1.638020, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, 0.027080, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, -0.580780, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, -1.201630, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, -1.763210, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, -0.055800, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -1.684350, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, -0.101000, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, 0.149980, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, -2.134090, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, -1.695700, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, -1.048870, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, -0.591880, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -0.517270, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, -0.641990, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, -1.327800, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, -1.389740, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, -1.957570, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, 0.493690, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, 1.015430, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, -0.316320, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, -0.086820, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, 0.133480, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, -0.063690, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -1.855900, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, -0.401180, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
0.54823, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.02662, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
1.35273, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
0.42770, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.27447, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
0.43314, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
0.00145, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
0.09980, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
1.09218, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
1.08870, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
1.40294, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
0.35415, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
0.00213, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
0.99355, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
0.59923, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
1.39370, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.41995, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
0.61080, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
1.01068, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
1.03784, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
0.76486, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
1.20318, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
0.41191, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
0.14062, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
0.00270, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.02136, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
1.12885, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
0.85741, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
1.09238, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.32897, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
1.06146, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
0.38167, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
0.00552, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
0.15140, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
0.00223, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
1.42575, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
0.04734, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
0.02210, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
0.08037, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
0.01537, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
0.01271, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
0.02876, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
0.00413, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
0.00768, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
0.07328, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
0.17941, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.16600, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
0.00751, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
0.03830, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
0.00026, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
0.02802, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
0.00322, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
0.00161, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
0.06789, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
0.05802, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
0.01560, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
1.41217, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
0.13985, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
0.05518, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.16893, 0.500000, 2,
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
