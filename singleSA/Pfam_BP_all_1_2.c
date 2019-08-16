/*********************************************************
  Pfam_BP_all_1_2.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:18:19 2005
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
0.132510, 0.431930, 0.250210, -0.242580, 0.861460, -0.542130, 0.405460, 0.008870, 0.134680, 0.584070, 
1.071240, 0.518300, 0.603900, 0.563300, -0.450800, -0.024900, -0.251600, 0.581250, -0.475010, 0.539330, 
-0.987220, -0.738210, 0.190000, 0.487850, -0.707580, -0.761330, 0.354460, 0.451090, -0.749410, 1.223660, 
0.998650, -0.255510, 0.487680, -1.279170, 0.420140, -0.657680, 0.446280, 0.843250, -0.401670, -0.758770, 
0.250300, -0.382460, 0.035340, 0.013260, 0.125760, 0.920070, 0.518990, -0.703500, -0.191870, -0.424420, 
-0.281200, 0.628020, -0.145600, 0.370690, -0.288130, -0.191120, -0.274520, -1.185430, -0.688210, -0.790250, 
0.130850, -0.675470, 0.936970, 0.761400, 0.497350, 0.232170, -0.228620, 0.177440, -1.021520, 0.353610, 
-0.738290, -0.631970, -0.188320, 0.530730, -0.037670, -1.028690, -0.197990, 0.661530, 0.214120, -0.299060, 
0.469090, -0.993590, -0.432960, 0.595980, 0.748630, -0.362710, 0.044700, -0.046820, 0.444210, -0.785860, 
-0.308280, -0.538410, -0.486170, -0.550760, 1.046880, 0.040880, 0.279550, -0.195230, -0.151190, 0.153810, 
1.633770, 0.237640, 0.041950, 0.132240, -0.159920, -0.393170, 0.362730, -0.268890, -0.579740, -0.542400, 
0.308960, 0.765000, 0.467440, 0.920310, -0.782310, 1.197550, 1.070690, -0.142910, 0.412380, 0.334470, 
0.737050, -0.264390, 0.308430, 1.804790, 1.656850, -0.683850, -0.473410, 0.161120, -0.519830, 1.032510, 
-0.790490, 0.301930, 0.319310, 0.061820, -0.288060, 1.283750, 0.600500, 0.417470, 1.017350, 0.016500, 
-0.449060, -0.441950, 0.476670, -0.754890, -0.207880, 0.494010, 0.651470, 0.549250, -0.031860, 0.360660, 
0.196710, -0.137000, -0.012370, 0.733040, -0.520910, 0.565600, 0.822800, -0.573480, -0.200220, 0.177410, 
-1.121150, 0.001250, 1.389650, -0.346000, -0.115790, 0.452030, 1.000980, 0.643620, 0.666850, 1.147080, 
0.465490, -0.200480, -0.210820, -0.513050, -0.492090, 0.436860, 1.009240, 0.246380, 0.448730, -0.303410, 
0.965730, 0.761970, 0.176310, -0.668940, 0.258510, 0.882580, -0.014730, -0.694200, 0.222990, 1.123680, 
-0.433800, 0.361560, 0.050660, 0.485340, -0.971210, 0.031760, 0.152380, 0.891240, -0.059860, -0.312020, 
-0.717080, 0.361650, 0.556160, -0.607470, -1.073770, -0.484410, -1.297750, -0.014420, 1.266430, 0.003170, 
0.091070, -0.866530, 0.572840, 0.278010, -0.011670, 0.313490, 0.463980, -0.153510, -0.555900, -0.065120, 
-0.195040, -0.329050, 0.044960, -0.294090, -0.019350, -1.045120, 0.873570, 0.313030, -0.084320, -0.737690, 
0.037840, 0.517870, -0.605270, -0.823330, -0.646890, 0.480980, 1.089770, 0.508700, -0.416280, 0.831840, 
0.406090, -0.651260, 0.174560, -0.377110, 0.015090, -0.882810, 1.323030, 0.239960, -0.161030, -0.617790, 
-0.252280, -0.601770, 0.019830, -0.422060, 0.153840, 0.593870, -0.098670, 0.056510, 0.235210, -1.285790, 
-1.615790, -0.454850, -0.883840, -0.016800, 0.005350, 1.048700, 0.577510, -0.103390, 0.276840, 0.849090, 
0.012020, 0.434630, -0.247970, -0.514540, 0.417360, 0.328190, 0.383280, 0.742460, 0.652030, 0.460990, 
0.277800, 0.356410, 0.683070, 0.472280, 0.245910, 0.634290, -0.572330, -0.819570, -0.165440, 0.044530, 
-0.328000, -0.027020, -0.221680, -0.290710, -0.532160, 0.169580, 0.886110, 0.182880, -0.398560, 
-0.436260, -0.057630, 0.282320, 0.455730, -0.765450, -0.181040, 0.793490, -0.198690, -0.010390, 0.177550, 
-0.276920, 0.784630, 0.550260, 0.489780, 1.133920, 0.257360, -0.112900, 0.075570, -0.475250, -0.997100, 
0.493520, 0.118520, 0.419950, -0.116180, -0.556130, -0.176780, -0.427220, -0.653440, -0.356890, 0.601580, 
0.766210, 0.400880, -0.170140, -0.351920, 0.315340, -0.117760, -0.683230, 0.207790, 0.113250, 0.369100, 
0.242180, 0.067530, -0.091760, 0.953860, -0.247400, -0.123160, 0.123980, 0.348140, -1.029840, 0.834730, 
-0.479510, 0.518610, -0.188730, -0.754890, -0.876500, -0.384080, 0.646480, -0.066300, 0.275620, -1.449520, 
0.853860, -0.928660, 0.347760, 0.296370, 0.374710, 0.325390, 0.963150, 0.181190, -0.384770, 0.212540, 
-0.615030, 1.031020, -1.088760, -0.118690, -0.376550, -0.181920, 0.157750, -0.546800, 1.211410, 0.509500, 
-0.272920, 0.148570, -0.350660, -0.184180, 0.343660, 0.991160, 0.920260, -0.126100, -0.469970, 0.588780, 
-0.820400, 0.274120, 0.841460, -0.754180, -0.803000, 0.386840, 0.725800, -0.000000, 0.908540, -0.518860, 
0.518000, 1.009270, -0.689340, 0.802990, -0.450800, -0.350360, -0.300510, -0.905590, -0.233950, -1.072270, 
-0.598170, 0.308630, -0.447980, 0.715930, 0.423430, -0.464360, -0.131030, 0.107920, 1.186560, -1.455390, 
0.217580, -0.889860, 0.818250, 0.075830, -1.780480, -0.395680, -0.041940, 0.951990, -0.041120, 0.799810, 
0.014770, 0.986870, -1.094900, 0.916160, 0.680100, -1.825560, 0.024520, 0.675580, -0.940800, -0.505830, 
-0.365020, 0.610440, -0.055860, -0.473400, 0.736430, 0.012150, -0.032190, 0.494670, -1.588920, 0.627260, 
0.149370, 0.570220, 1.057540, -0.304100, 0.961900, -0.257920, -0.128340, 0.450630, -0.026550, 0.025990, 
0.647530, 0.501250, -0.672460, 0.516700, 0.697090, -0.440850, -0.839870, 0.548030, -0.678640, -0.038600, 
-0.692930, 0.065650, -0.255900, -0.153060, 0.488260, -1.020930, 0.999590, -0.156360, -0.803640, 0.333570, 
1.062450, -0.700550, 1.211120, 1.450080, -0.074520, 0.024070, 0.401320, 0.242910, 0.603800, 0.309790, 
0.021360, -0.723330, 0.263410, 0.095130, 0.845480, 0.064870, 0.328940, -0.326050, -0.135320, 0.994180, 
0.160390, -0.077940, 0.397380, 0.253100, -0.349250, -0.519640, 1.140390, 0.644280, 0.241210, 0.385910, 
0.389710, -0.169520, -0.428670, -0.669430, -1.026560, -0.160300, -0.555650, 0.078950, 0.177520, 0.387070, 
0.568640, -0.426990, -0.911810, -0.447030, 0.546750, -0.585810, 0.172400, 0.309040, 0.288690, -0.058930, 
-0.414810, -0.042700, -0.136640, 0.129480, 0.785710, 0.268490, 0.791550, 0.034070, 0.822450, -0.960090, 
-0.632070, 0.735420, -0.354440, 0.519760, -0.528120, -0.465120, -0.009300, -0.334990, 0.355620, 0.774440, 
1.426170, 0.793350, 0.476190, 0.116540, -0.069360, -1.350890, -0.539290, 0.346550, -0.797880, -0.343460, 
0.863340, 0.931010, 0.530390, 1.138110, -1.020970, 0.462960, -0.304860, -0.447830, -0.294760, -0.447480, 
0.093490, -1.321780, 0.158820, 1.065310, 0.552250, 0.084940, 0.971890, -0.231830, 0.287430, 0.833800, 
0.094060, 1.125580, -0.533150, 0.356820, 0.908920, -0.931700, 0.272050, 0.398670, -0.931780, 0.223860, 
0.367170, -0.115960, -0.703300, 0.315770, 0.705410, -0.460560, -0.692240, -0.918510, 0.616860, 
0.519030, -0.169150, 1.217690, -0.268620, -0.731590, 0.532230, 0.777840, -0.302200, 0.812330, -0.086600, 
0.624870, -0.073310, -0.324990, -0.555350, -1.196110, 0.017340, -0.391920, -0.430050, 0.794170, -0.226380, 
0.551090, -0.609540, -0.205080, 1.077280, -0.695070, -1.183810, 0.739150, 0.615020, -0.124880, -0.556720, 
-0.196590, -0.075550, 0.383290, 0.773950, -0.175910, 0.357550, -1.143650, -0.693630, 1.086930, 0.669310, 
0.828880, -0.793190, -0.961350, 0.691810, -0.528230, 0.394170, 0.019650, -0.099240, -0.376010, 0.049240, 
-0.015780, -0.779530, -0.509410, -0.309060, 0.360980, -0.877720, -1.317070, 0.566350, -0.772960, -0.188840, 
0.395900, -0.870120, -0.959580, -0.718730, -0.504240, -0.430460, 0.003380, -0.232990, 0.799960, 0.860020, 
1.181990, 0.225240, 0.233420, 0.751460, -1.045870, 0.619790, -0.872100, -0.361540, 0.492760, 0.967730, 
0.284950, -0.038280, 0.275150, -1.087290, 0.785530, 1.429970, -0.653950, -0.495410, 0.611320, 1.210700, 
0.218540, 0.585800, -0.073900, -0.509670, 0.426610, -0.277440, 0.231220, 0.631520, 0.116330, -0.333550, 
0.199300, -1.085690, 0.981550, -0.538180, -0.399700, -0.056650, -0.456160, 0.537220, -0.453750, 0.931370, 
-0.857300, -0.778260, 0.918810, -0.557420, 0.152150, -0.611290, -1.014550, -0.437540, 0.413520, 0.456350, 
-0.759160, 0.236630, 0.100470, -0.008210, -1.386970, 1.009450, -0.326420, 0.194910, -1.562850, -0.726900, 
0.309580, 1.417440, -0.640210, -1.071510, -0.232110, -2.265960, -0.276480, -0.662840, -0.693070, 0.086430, 
0.285760, 1.142540, 0.494030, 0.169720, -1.046020, 0.637470, -1.003530, -0.297000, 0.043990, -1.126610, 
0.036260, -0.804340, -0.160980, -0.842090, -0.324270, 1.131100, -0.460110, -1.371440, 0.883910, -0.364890, 
0.704060, 0.512040, -0.956270, 0.876440, -0.464060, 0.483560, 0.436330, 0.600260, -0.332890, 0.829250, 
0.607380, 0.155150, 0.454720, -0.911560, -0.294010, -0.459280, 0.131160, -0.021750, -0.465430, 0.441300, 
-0.472340, 0.275920, -0.143470, 0.125550, -0.983050, -0.730960, 0.490090, -0.869690, 0.174600, -0.182890, 
-0.284700, 0.290540, -0.460530, -0.195360, -1.013590, -0.061640, -0.252900, -0.938560, -0.631870, 0.232910, 
0.174240, -0.010190, -0.900250, -0.282190, -0.518670, -0.814590, 0.379780, 1.416400, 0.241290, -0.301700, 
-0.059250, 0.131630, 0.289130, 0.294090, -0.091920, -0.028430, -0.585090, -0.794770, -0.335030, -0.798830, 
-0.231790, -0.248470, 0.469330, -0.460220, 0.073330, 0.154370, 0.013530, 1.255840, 0.407000, -0.056360, 
-0.263030, -0.869050, 0.613410, -0.412690, -0.131800, 0.640820, 0.038150, -0.338930, 0.484460, -0.655230, 
-0.057250, -0.191540, -0.451440, 0.783560, 0.448100, -1.161040, -1.040320, 0.347950, -0.530220, -0.817860, 
1.085930, 1.323920, 1.053030, 0.363800, -0.172310, -1.205350, 0.557710, 0.303250, 0.170620, 1.171030, 
-0.413180, 0.133840, 0.171720, 0.403710, -0.372760, 0.056480, -0.019160, 0.886170, -0.709230, 0.135080, 
-0.054770, 0.391040, -0.450680, -0.034170, 0.274090, 0.060830, -0.611880, 0.240960, -0.814220, -0.332750, 
0.695550, -0.531930, 0.483740, -0.057430, 0.606150, -0.302170, 0.213480, 0.512070, 0.346450, 0.819430, 
-0.100100, 0.104150, -0.744260, 0.307400, 0.047520, 0.710180, -0.309550, -0.154040, 0.213140, 
0.616780, -0.575020, 0.151280, 0.680520, 0.894480, 0.640380, -0.345360, -0.688370, -0.294000, 0.055630, 
-0.610730, -0.294540, -0.873360, 0.482510, 0.270140, -0.713260, 0.246500, 0.453630, 0.584200, 1.266430, 
0.919340, -1.107170, -0.257220, 0.465180, 0.015910, 0.470270, 0.012100, 0.784320, -0.949350, -0.553150, 
0.075520, -0.758570, -0.555150, 0.109800, -0.846200, -0.471490, 0.749880, -0.337100, -0.212030, -0.393200, 
-0.165740, -0.776360, 0.671730, 0.152340, -0.480350, 0.735740, 1.248410, 0.248700, -0.247400, -1.176370, 
-0.756000, 0.418130, -1.098630, -0.119640, 0.916770, -0.240580, -0.410870, 0.178410, 0.222760, 0.265870, 
0.772490, 0.704970, -0.088190, -0.730990, 0.454630, -0.900160, -0.455000, -0.664840, 0.549300, -1.108190, 
0.130890, 0.616080, -0.022500, 0.504080, 0.940410, 0.273570, 0.215670, 0.489270, 1.002550, -1.257090, 
0.319380, -0.357530, 0.203220, -0.949290, -0.448490, -0.612810, 0.489680, -0.063690, 0.099610, 0.313530, 
0.494650, 0.129910, 0.280570, -0.718960, 0.982130, -0.431180, -0.502930, -0.532150, -0.359900, 1.494740, 
0.405490, -0.465070, 0.566660, 0.302660, -0.174790, -0.592940, 0.124340, 0.574770, -0.873160, -0.491450, 
-0.820260, 0.303860, -0.123180, 1.241060, 1.104790, 0.905810, -0.546300, 1.504130, -0.998120, 0.686600, 
-0.908870, -0.621390, -0.404350, 1.021950, 0.553360, 0.060600, -0.128580, 1.175540, -0.560460, 1.299030, 
1.454510, 1.083110, -0.770240, 0.389830, -0.289080, -1.323170, 0.431000, 1.236690, -0.874720, -0.508590, 
-0.976420, 0.109920, 0.581330, 0.140880, 0.600280, -0.782900, 0.363330, -0.005680, -1.211550, -0.585830, 
-0.169850, 0.184590, -0.048110, -0.554340, 0.371550, 0.337390, -0.220080, 0.761100, 0.247280, -0.565120, 
-0.460740, 0.640420, -0.866590, -0.836810, 0.229760, 0.748900, -0.106830, -1.114070, -0.194010, 0.789740, 
0.870780, -0.729310, -0.884730, 0.426890, -0.261080, 1.044580, 0.411820, 0.893600, -0.100440, 0.937880, 
-0.144470, 0.244510, 0.665760, 0.526400, 0.247820, -0.872270, 0.977400, 0.943350, -0.171720, -0.484280, 
-0.278770, -0.601920, -0.576370, -0.700120, -0.259860, 0.920790, 0.057870, 0.562720, -0.288480, 0.774220, 
-0.092890, -0.140710, 1.108150, -0.455760, 1.149960, -0.297700, -0.312270, -0.617830, 0.789640, -0.108860, 
0.430390, 0.529620, 0.175310, 0.262840, -0.568840, -0.896150, 0.456450, -0.405090, 0.283040, -0.574630, 
-0.129760, -0.214710, -0.318960, 0.568680, 0.079910, 0.090980, -0.151460, -0.867010, 0.095250, 0.523110, 
0.227340, -0.028240, 1.045940, 0.166760, -0.862240, 0.934420, -0.195790, -0.697040, 0.723290, 0.331670, 
-0.053560, -0.094090, -0.393000, 0.302330, -0.066940, 0.670290, -0.628690, 0.230450, -0.426090, -0.408010, 
0.035170, -0.653480, 0.812790, -0.450210, -0.529860, 1.012040, 0.201510, 1.040760, -0.057250, 0.475490, 
-0.045170, -0.788340, 0.294050, 0.223900, -0.146660, -0.276860, 0.763700, -0.331690, 0.591360, -0.710600, 
-0.239360, -0.094600, -0.227230, -0.431140, -0.567210, 0.138180, -0.772600, -0.591900, -1.055550, -0.604390, 
-0.877010, 0.812710, 0.537200, 0.081390, -0.756320, 0.058040, 0.505250, -0.635380, -0.423920, -1.107580, 
-0.527020, -0.376950, 0.303010, -0.557860, 0.566330, -0.996200, -0.271360, 0.240540, -0.089480, 
0.597390, 1.348660, 0.589020, -0.998670, -0.849280, 0.030840, -0.456650, -1.017950, 0.808830, -0.027580, 
0.597990, 0.700670, -0.571800, 0.381180, -0.617440, 0.124580, -0.125080, 0.646310, 0.333040, -0.223590, 
0.687540, -0.036990, -0.637350, -0.449080, 0.348230, -0.033900, 0.117330, -0.361560, 0.815730, -0.064200, 
-0.965390, -0.032910, 0.209080, 0.515800, -0.135320, -0.220610, -0.636930, 0.061490, -0.621080, 0.568000, 
0.547050, -0.187970, 0.367040, 0.412990, 0.031650, -1.015590, -0.035990, -0.476410, 0.143440, 0.570280, 
-0.853660, 0.090170, -0.937720, 0.620170, -0.198140, -0.516640, -0.722510, -0.135980, -0.302060, 0.200400, 
0.734970, -0.347350, -0.684570, -0.291950, -0.539230, -0.563270, 0.629390, -0.128960, 0.071270, 0.479250, 
-0.573560, 0.410470, -0.484070, -0.553720, 0.382310, -0.747770, -1.610500, 0.552460, -0.890980, -0.603240, 
-1.223020, -0.347050, -0.226510, -0.111970, 0.034030, 0.113550, -0.757120, 0.789780, 0.022200, -0.127280, 
-0.047750, -0.533210, -0.532390, 0.661470, -0.357140, -0.012770, 0.954840, 0.354530, -0.218650, 0.070520, 
0.419550, -0.959840, 0.453720, -0.165740, 0.285040, -0.454940, -0.202370, 0.618720, 0.732100, -0.257750, 
0.025120, 0.363370, -0.468500, -0.622620, -0.066330, -1.740530, 0.150450, -0.132330, 1.658110, 0.005300, 
0.681720, -0.652080, 0.238520, -0.604020, -0.598250, 0.412630, 0.182320, -0.712430, -1.705750, -1.279600, 
0.474840, 0.705650, 0.803820, 0.435180, -0.113430, 0.235750, -0.434880, 0.688820, -0.464860, -0.994820, 
0.302420, 0.584240, 0.926840, -0.489820, 0.352390, 0.280980, -0.645510, -0.333120, -0.607660, -0.476700, 
0.692900, -0.441860, -0.055550, -0.159730, 0.289070, -0.069770, -0.152510, 0.924920, -0.175600, -1.226230, 
-0.041800, -0.322100, -1.163520, -0.296640, 0.115720, -0.550530, -0.841410, -0.059650, 0.388510, -0.896090, 
0.174180, -0.239420, -0.378820, 0.196370, 0.560050, -0.003750, -0.282020, -0.010330, 0.792670, -0.157740, 
-0.622860, 0.522760, -0.228140, -0.006130, -0.286250, -0.018330, 0.163420, -0.359260, -0.085120, -0.403680, 
0.015640, -0.136140, 0.053190, -1.056780, 0.781730, 0.077410, 0.513110, 0.024370, -0.099200, -0.098440, 
-0.118410, 0.617150, 0.110140, 0.734220, -0.311300, 0.158690, -0.783950, -0.732650, 0.633980, 0.822490, 
0.602600, 0.987000, -0.262330, -0.010230, -1.097360, 1.264470, 0.543420, -0.041410, 0.631610, 0.216640, 
0.185780, -0.704340, 0.363840, 0.115050, 0.384260, -0.036830, 0.564390, 0.270790, -0.405620, 0.717360, 
0.905030, -0.952170, -0.692320, -0.378800, 0.497880, 0.881890, 0.033020, -0.384570, 0.319050, 0.266380, 
-0.242600, -0.752830, -0.804080, -0.296680, 0.842820, 0.645380, -0.328160, -0.020070, -0.505060, 0.261940, 
0.934460, 0.604880, -0.603950, 0.281970, 0.457970, -0.605480, -0.270860, -0.172370, -0.176710, -0.658630, 
-0.962680, -0.270880, -0.778430, 1.098310, 0.056210, 0.016310, -0.834180, 0.079980, -0.097490, 0.577070, 
0.764160, 0.747890, 0.347800, -0.106880, -0.474250, -0.782020, 0.010820, -0.782250, -0.612960, 0.787760, 
0.259450, -0.333820, -0.361590, -0.379360, -0.030010, 0.533600, -0.767010, -0.089400, 0.529190, -0.117370, 
0.405190, 0.841750, -0.535530, 0.301190, -0.222160, 0.466360, 0.013880, 0.214380, 0.424510, 
-0.309920, 0.627120, -0.733790, -0.578920, 0.427110, 1.038910, -0.098810, 0.398200, 0.313310, -0.573180, 
-0.278760, -0.581960, 0.378960, 0.726250, 0.400930, -0.229850, 0.373930, -1.034230, -0.013130, 0.542140, 
0.843720, 0.281200, 0.715400, 0.254210, -0.702680, -0.590950, -0.510720, 1.086200, 0.196330, -0.289270, 
-0.432940, -0.136320, -0.410730, -0.452590, -0.079780, -0.579320, -0.559390, 1.021920, -0.470610, -0.048470, 
-0.324840, 0.523300, 0.061380, 1.472470, -0.207060, 0.425350, -0.109080, 0.642220, -0.064520, 0.757890, 
-0.045410, 0.173830, -0.697320, 0.441260, 0.402400, -0.510450, 0.335280, 0.179130, -0.038370, 0.660370, 
0.175230, 0.493750, -0.493760, -0.103330, 0.296650, -0.118210, 0.363120, -0.821930, 0.712090, -0.297680, 
-0.155340, -0.634800, -0.386630, -0.033020, 0.057010, -0.437830, 0.311330, -0.078220, 1.049590, -0.268800, 
0.339610, 0.264790, 1.068970, -1.001840, -0.255630, -0.248250, -0.740590, -1.170580, -0.323240, 0.207690, 
-0.628880, 0.869470, 0.342290, -1.067080, 0.003040, -0.590140, -0.743310, -0.738830, -0.400170, 1.198110, 
0.182760, 0.066650, 0.133690, -0.193370, -0.065750, 0.090980, 0.222180, 0.234800, 0.273340, -0.454640, 
0.475140, 0.175160, 0.401240, 0.636120, -0.776170, -0.856210, -0.564920, -0.868320, 1.458750, -1.211090, 
0.742530, 1.698270, -0.719680, -1.086550, -0.580320, 0.182150, 0.262070, 1.416280, -0.906430, -0.536470, 
0.180060, -0.116500, -1.093460, 0.031210, 1.068810, -3.937900, -0.985480, 1.814540, 0.677570, -0.291820, 
0.504950, 0.081920, -1.138760, 0.066160, -0.618100, 0.538270, -1.441690, -0.821340, -0.991980, -0.692690, 
0.366330, -0.595140, 0.022770, 0.576330, -0.515940, 0.000380, 0.462900, -0.175780, 1.136270, -1.061470, 
0.098800, -0.797820, -0.446320, 0.259840, -0.078990, -0.794060, -0.202220, -0.371050, 0.704000, 0.006120, 
0.063020, -0.487550, 0.990850, 0.088270, -0.206820, 0.678080, -0.783630, 0.671540, -0.404410, 0.538400, 
-0.238250, 0.508230, -0.293350, 0.083460, -0.170940, -0.703020, -1.274310, 1.068360, -0.107220, -0.489170, 
0.746770, -0.519850, 0.222420, -0.020350, -0.228440, -0.446950, 0.404260, 0.195970, -0.317350, 0.472920, 
0.413940, 0.206730, 1.066240, 0.755590, -0.893270, -0.172260, 0.038200, -0.168370, -1.675720, -0.272580, 
-0.658510, -0.601840, -0.436400, 0.336400, 0.740640, 0.132300, 0.092830, -1.151520, -0.643890, -0.523360, 
-0.585620, -0.341740, 0.257950, 0.563960, -0.093860, -0.553250, 0.288530, -0.754340, -0.366840, -0.463580, 
-0.166020, -1.061510, -0.865640, 0.470010, -0.792860, 0.182380, -0.190990, -0.036530, 0.561800, 0.451630, 
0.767850, -0.653930, -0.101590, -0.018360, -0.442490, 0.204440, 0.502390, 0.914360, 0.096720, -1.023320, 
1.083560, -0.411400, 1.711270, 0.123450, -0.095760, 0.288470, -0.633160, 0.679320, -0.909720, 1.171340, 
0.442280, 0.424920, -0.453940, 0.415340, 0.057900, -0.037410, -0.335140, 0.387480, 0.518690, 0.934200, 
0.617530, 0.066510, -0.266930, 0.405300, 0.478990, 0.433690, 0.099100, 0.274770, -0.755840, 0.019510, 
-0.831020, -0.066930, 0.402130, -0.588600, -0.567200, 0.574360, -0.320100, -0.219190, 0.331340, 0.686630, 
-0.311170, 0.130820, 0.296290, -0.599620, -0.694410, -0.611110, 0.487910, 1.224680, -0.876310, 
0.970030, -0.673650, -0.774270, 0.439090, 1.197540, 0.215460, -0.310330, -0.118990, -0.245180, -0.646910, 
0.957630, 0.053950, 0.127490, -1.204030, 0.068290, -0.226440, 0.580940, -0.649240, -0.379120, 0.547500, 
-1.861740, -0.313860, -0.007880, 0.041300, -0.600950, -0.588860, -0.162220, 0.594360, 1.210820, -0.168890, 
-0.131410, -0.410950, 0.298520, 1.199120, -1.203310, 0.231080, 0.509590, 0.479440, 0.449210, -0.603880, 
-0.345910, -0.690080, -0.276100, 0.441950, -0.682700, -0.455010, 0.283250, 1.171060, 0.561270, -0.375830, 
-0.063450, 0.428100, -0.266340, -0.640100, 0.397080, 0.044920, -0.540050, -0.909780, 0.658790, 0.824960, 
-0.155720, 0.784470, 0.316110, 0.106530, -0.587050, 0.373070, -1.296030, -1.081150, -0.473250, -0.214650, 
0.332210, 0.055910, 0.250100, -0.586960, 0.587170, 0.593310, 1.097630, -0.340710, -0.614010, 0.241310, 
0.644900, -0.104250, 0.331550, -0.334310, -0.757620, 0.353220, 0.752880, 0.183660, -0.231760, 0.559670, 
-0.475510, 0.507520, 0.454560, -0.201850, -0.251820, -1.094270, -0.262250, -0.316270, -0.289210, -1.359250, 
-1.112280, 0.748140, -1.007710, 0.533860, -0.342870, -0.015460, 0.162340, -0.311730, -0.018560, 0.707750, 
-0.467030, -0.348620, -0.474640, -0.451000, -1.102080, -0.211500, 1.184000, 1.206310, -0.162890, 1.112760, 
-0.019630, -0.064870, 1.323620, 0.605030, 1.841160, 0.552450, 0.403010, 0.371680, -0.663290, -1.282040, 
0.639290, -0.172250, 1.262180, 0.492870, -0.657760, 2.124650, 0.344650, 1.557220, 0.099850, 0.593720, 
-0.259800, -0.336370, 0.133390, 0.291260, 0.572240, 0.995840, -0.483830, -0.515080, -0.546450, -0.167890, 
-0.145730, 0.281850, 0.518870, -0.146280, 0.416840, 0.439590, 0.170440, -0.758320, 0.717330, -0.118870, 
0.363570, 0.121010, 0.593680, -0.891360, 0.671630, -0.537680, -0.972570, 0.066780, -0.113440, -1.442270, 
0.288900, -0.098550, -0.328480, 0.141690, 0.041420, -0.633600, -0.274810, -0.584070, -0.686120, -0.471090, 
0.430810, -0.468960, -0.622900, 0.277540, -0.220580, 0.611240, 0.258400, -0.673820, 0.378300, -0.189830, 
0.404180, -0.739890, -0.429940, 1.473460, 0.126860, 0.379410, -0.786190, -0.749300, 1.046390, -0.750600, 
0.425090, 0.640040, 0.962160, -0.383970, 0.349380, 0.044280, 0.621500, 0.880860, -0.369220, -0.453410, 
-0.429940, 0.885620, -0.147310, -0.377180, 0.194190, 0.491810, -0.757750, 0.030640, -0.278750, -0.498220, 
-0.870570, -0.117410, -0.199720, -0.405370, -0.581300, 0.544460, 0.203110, 0.232230, 0.558440, 0.154080, 
-0.566870, -0.018680, -1.125850, -0.720410, 0.204270, 0.409030, 1.108430, 0.450100, 0.711920, -0.120180, 
0.142290, -0.693660, 0.199750, -0.141170, -0.424960, -0.021010, -0.128620, 0.674920, 0.340160, 0.703030, 
-0.108870, 0.314900, 0.577700, 0.374820, 0.029640, -0.183550, 0.587550, -0.460890, 0.576250, -0.137770, 
0.059950, 0.297840, -1.295250, 0.195960, 0.282000, -0.585340, 0.373670, -0.008630, 0.198500, 0.515080, 
-0.364200, -0.371630, 0.251860, -1.076980, -0.301940, 0.086660, 0.253350, 0.219710, 0.410390, -1.013360, 
-0.906540, 0.250480, 0.797100, -0.160670, 0.106780, -0.434620, -0.265300, 0.081110, 0.858510, 0.302540, 
0.210120, 0.968600, 0.009290, -0.868950, 0.456610, -0.113370, 0.262440, 0.125230, 0.638060, 
0.690910, 0.185420, 0.129640, 0.357190, -0.209450, 0.149530, -0.560000, -0.358060, -0.517900, 0.472650, 
0.636520, 0.209430, -0.096060, -0.337770, -0.828800, 0.616040, -0.393600, 0.160930, 0.354600, -0.015560, 
-0.745300, 0.107370, 0.038710, 0.622700, 0.635720, 0.528510, -0.250640, 0.324320, -0.030130, 0.567980, 
-0.044340, -0.181090, -0.483190, -0.659530, -0.204500, 0.245470, 0.871650, -0.566410, 0.504770, 0.732720, 
0.054960, -0.389630, -0.163860, 0.801620, 1.108620, -0.628210, -0.035810, -0.543140, -1.109800, -0.599770, 
0.167220, 0.182240, 0.588320, 0.770290, -0.641910, 0.093040, -0.649920, -0.842430, -0.188790, -0.014380, 
-0.478120, 0.620350, 0.752770, 0.009850, 0.372380, -0.137560, -0.186570, -0.345510, -0.616740, -0.851680, 
-0.017630, 0.535010, -0.420080, -0.003400, 0.278080, -0.403040, 0.361060, 0.790290, -0.857630, -0.119020, 
0.521600, 0.779330, 0.787850, 0.281160, -0.296370, -0.670770, 0.744710, 0.897040, -0.920390, 0.380670, 
0.577840, 0.128140, 0.742830, -0.602080, -0.167840, -0.044560, 0.072450, -0.587580, -0.593710, 0.030180, 
0.020880, 0.328780, -0.778620, 0.025180, -0.167740, -0.070730, -0.141100, 0.115930, 0.884620, 0.585620, 
0.042680, 0.172310, -0.858100, 0.086360, -0.030720, -2.251110, -1.023010, 1.124960, 0.937250, -0.994610, 
-0.310930, 0.591570, -0.232060, -0.945950, -0.358180, 0.222880, 0.506830, 0.105430, -1.082290, -0.047110, 
-0.996090, -0.555890, -1.575600, 0.518630, 0.481870, 0.132540, 0.107490, 1.013890, 0.233630, -0.353310, 
0.877250, -1.588020, -0.129490, 0.758710, 0.769610, 1.771230, 0.424770, 0.044940, -0.524020, -0.553010, 
-0.017660, -1.031250, -0.963010, 0.168870, 0.638370, -1.193950, 0.395130, 0.790720, -0.200510, 1.161660, 
-0.328580, -0.244690, -1.641720, -0.134990, 0.348020, -0.220530, 0.315150, 0.484300, -0.213360, 0.148080, 
0.326740, 0.445650, -1.205360, 0.054330, -1.026420, 0.740130, -0.132330, 0.651260, 0.728150, 0.617550, 
0.317460, -0.856460, 0.876060, -0.057550, 0.540280, -0.093300, -0.700840, 1.101530, -0.645850, 0.547620, 
0.028550, -0.436170, 0.426350, 0.546410, -0.276000, 0.459580, -0.139840, -0.682110, -1.026310, 1.086220, 
-0.164600, -0.398660, -0.293180, 1.168950, 0.686430, -0.204570, 0.216710, -0.918550, -0.792490, -1.087090, 
0.582350, 0.070910, 0.584160, 0.469580, 0.666430, -0.172630, 0.178760, 0.839020, 0.616090, -0.188110, 
-0.879410, -1.109540, 0.326690, -0.053540, -0.462620, -0.047570, 0.559080, 0.206990, -0.465000, 0.043740, 
0.347440, 0.464290, 0.502140, -0.521100, -0.111270, -0.513910, 0.558510, 0.566930, 0.117860, -0.032050, 
-0.636340, -0.669530, 0.071310, -0.065910, 1.001880, -0.896420, 0.156220, 0.062580, 0.077840, -0.048400, 
-0.287960, 0.340850, 0.001520, -0.436840, 0.017160, -0.865380, 0.536680, 0.028000, 0.069260, 0.344260, 
-1.069860, -0.837540, 2.601500, 1.169020, -1.198630, -0.260890, -0.336220, 0.156480, -0.095480, -0.325530, 
1.256960, 0.747960, -0.311520, 0.577100, -0.233040, -0.023860, 0.837160, 0.268300, 0.991780, -0.709040, 
-0.253600, -1.024850, -0.120130, -0.919790, 0.883880, -0.729420, 0.982340, -0.235560, -0.211480, -1.369130, 
0.366810, -1.043020, 0.333990, -0.326140, 0.279650, 0.108250, -0.749380, -0.345920, -0.586610, 
-0.439600, 0.016070, 0.450640, 0.913610, 0.351520, -0.009700, -0.221840, -0.425970, -0.746800, -0.001850, 
0.019160, 0.048470, 0.326280, -0.127410, 0.146180, 0.455810, 0.569430, 0.674460, 1.166650, -0.754540, 
-0.416130, -0.236120, -0.284330, 0.052570, 0.628900, -0.245720, -0.002210, 0.887300, 0.077950, -0.109410, 
0.324180, -1.316100, 0.123430, 0.909610, -0.374230, -0.786340, -0.697530, 0.790930, -0.629490, 0.813910, 
1.005300, -0.350100, -0.409620, -0.316030, -0.402060, -0.317440, 0.562110, 0.443740, -0.020490, 0.913560, 
0.546260, -0.791450, 0.206510, -0.371010, 0.120280, -0.927990, 0.145200, -0.310050, 0.410540, -0.399260, 
0.576080, 0.836560, 0.094330, -0.952570, -0.731580, 0.030980, -0.811010, 0.181910, -0.776520, -0.029250, 
0.253890, -0.777380, 0.485710, 0.048430, 0.328230, 0.351350, -0.341170, 0.461450, 0.361160, -0.319000, 
0.229920, 0.288120, 0.329410, -0.622720, -0.400090, -0.052430, -0.743490, 0.800710, 0.534320, -0.064170, 
-0.818770, 1.290470, -1.166740, -0.181430, 0.387790, 0.293400, -1.008530, -0.034000, -0.455410, -0.599360, 
-0.349370, 0.187380, 0.813780, 0.124730, 0.368920, 1.340380, -0.571190, -0.134590, 0.352130, -1.112600, 
-0.060460, 0.666320, 0.085080, -0.722000, 0.119190, 0.101680, 0.695970, 0.751210, -1.749340, 1.686790, 
0.041630, -0.555730, -0.538440, -0.516790, 0.371810, -0.082340, -0.091060, -0.167330, 0.357600, -1.110370, 
-0.326220, -0.069290, 0.254180, -1.350230, 0.173900, 1.220050, 0.110120, -0.046640, 0.125840, 0.340850, 
-0.738730, -0.383690, -0.567410, -0.040140, -0.120040, 1.088740, -0.239610, 0.138770, -0.080920, -0.983250, 
-0.540430, 0.546390, 0.141210, 0.039000, 0.044160, -0.791970, -1.282140, -0.450370, 0.833860, -0.595160, 
0.267870, 0.373970, 0.389440, 0.334440, -0.768950, 0.383340, 0.159540, -0.466620, 1.185280, -0.024660, 
0.459610, -0.727120, 1.267990, -0.666790, 1.316750, 1.132050, -0.497320, 0.622300, 0.646900, -0.290580, 
-0.277440, -0.081180, 0.542390, 0.224310, -1.057710, 0.913650, -0.511350, -0.605280, -0.274030, -0.387080, 
0.134990, -0.493560, 0.810640, -1.237840, 0.953790, 0.321360, 0.827360, 0.899650, -0.573300, -0.448300, 
-0.694580, -0.728210, -0.228600, 0.741300, -1.112170, 0.245430, -0.656570, 0.260530, -0.562810, 0.713670, 
-0.270140, 0.312020, -0.557720, 0.106400, 0.433080, 0.162380, 0.773030, -0.119910, 0.718340, -0.249270, 
-0.793550, 0.455760, -0.528390, -0.272230, -0.543730, 0.603930, -0.206900, 0.329450, -1.182540, 0.315410, 
-1.015040, -0.458150, -1.454160, 0.326360, 0.262500, 1.412760, -0.541000, 0.689450, 0.709940, 0.632690, 
1.320150, -0.179920, -0.127440, -0.224940, -0.741380, 0.254880, 0.208600, 0.371670, 1.484480, -0.420970, 
-0.844310, 0.371590, -0.508460, -0.510780, -0.290470, -0.183530, 0.189710, -0.174010, -0.825230, -1.039360, 
-0.328040, -0.057130, 0.328830, -0.372010, 0.481320, -0.677320, -0.513260, -0.499010, -0.042320, 0.293510, 
-0.097650, -0.429580, -0.436140, 0.256410, -0.360660, 1.266360, -0.279520, 0.512920, 0.426480, 0.055300, 
0.386820, -0.710720, 0.319600, 0.011320, -0.390140, -0.131880, -0.261820, 0.419890, 0.221560, 1.018990, 
-0.236050, 0.273000, 0.080380, -0.100690, 0.374280, 1.272530, -0.568580, 0.689460, 1.016630, 
-0.363500, 0.821840, 0.873530, 0.011970, -0.821050, -0.081380, -0.658320, 0.751850, 0.067230, 0.169600, 
-0.536950, 0.378870, 0.399520, 0.345410, -1.175910, 0.059830, 0.968960, 0.374250, 0.282200, -0.221200, 
-0.998250, -0.233830, -0.019420, -0.450390, 0.473970, 0.043010, -0.284210, -0.120460, 1.263220, -0.780060, 
-0.590020, -0.498010, 1.037100, 0.011790, 0.686310, -0.179050, 0.235870, -0.116900, -0.613220, 0.012820, 
0.443570, 1.653150, 1.121240, -0.200780, -0.457730, -0.707770, -0.533930, -0.099800, 0.166810, 0.939010, 
-0.086980, 0.220640, 0.170280, 0.219370, 0.852720, 0.319330, 0.135770, 0.575140, 0.142420, -0.876250, 
0.381750, -0.333810, 0.401570, 0.203970, -0.742870, 0.422340, 0.724580, 0.748910, -0.197200, 0.172320, 
0.058680, -0.237450, 0.132330, -0.555410, 0.568580, 0.528940, -0.180570, -1.080180, 0.085400, 0.240550, 
-0.859110, 0.002720, 0.784750, -0.163860, 0.245360, 0.153110, 0.101080, 0.451230, -0.166570, 0.027720, 
-0.716630, 0.343910, -0.360140, -0.997940, -0.452270, 0.319660, 0.345340, 0.789670, 0.179100, -0.264900, 
-0.556780, 0.139850, -0.100310, 0.254950, 0.462120, 0.556700, -0.058860, -0.061320, 0.028010, -0.223120, 
-0.916430, 0.111440, -0.490340, 0.874980, 0.180450, -0.951750, 0.803450, -0.429850, -1.292260, 1.974340, 
0.219380, -0.411930, 1.260750, 0.111290, 0.000040, 0.949540, 0.079350, -0.523280, -0.607870, 0.013620, 
0.494740, 0.191040, 0.617460, 1.395180, 0.711450, -0.403370, -1.241250, 1.298620, -0.364670, 1.155280, 
-0.747080, 0.647300, 0.732910, 0.128000, -0.299930, 0.176340, -0.114360, -0.164520, -0.216520, -0.629830, 
-0.495980, -0.508630, -0.806440, -0.118140, 0.478140, -1.396050, -0.991830, 0.114080, -0.323810, -0.167590, 
0.384560, -1.106440, -0.493340, -0.034650, 0.138280, 0.350760, 0.246240, -0.689520, 0.736090, 0.821790, 
-0.518250, 0.407970, 0.120160, 0.273030, -1.044790, -0.789480, 0.174170, 0.081590, 0.145160, 0.354570, 
0.469320, -0.486420, -0.565460, -0.257960, 0.531570, -0.918660, -0.376610, -0.682470, 0.324740, 1.000590, 
-0.664400, 0.113920, 0.456320, 1.179350, -0.829790, -0.860350, -0.225300, 0.309180, -0.333950, -0.608280, 
0.284510, 0.506070, -0.204450, -0.101970, -0.566460, 0.221300, -0.645790, 0.037440, 0.673040, 0.845960, 
-0.097230, -0.311690, -0.296500, 0.273730, -0.029050, -0.326360, 0.015130, -0.382340, -0.328660, 0.354840, 
0.399980, 0.611860, 0.488550, 0.739090, -0.506090, 0.198580, 0.511880, -0.084380, -0.275240, -0.675580, 
-0.549110, 0.284500, -0.130780, -0.704010, -0.271750, -0.409260, -0.288230, 0.614480, -1.062290, -0.264340, 
-0.025540, 0.678750, 0.488230, 0.232540, 0.299520, -1.083420, -0.081140, -0.057770, 0.105040, -0.212100, 
-1.040310, -0.386070, -0.777110, -0.617100, 0.115380, -0.434760, 0.397860, -0.016350, -0.519790, -0.079730, 
1.593710, -0.092720, 0.006550, -0.593830, -0.071200, -0.151550, -0.151360, -0.277600, 0.248210, 1.146590, 
0.189070, 0.180580, -0.727570, 1.101710, 0.832210, 1.291210, 0.376030, 0.730750, 1.250800, 1.089770, 
0.066370, -0.525120, 0.553920, 0.734060, 0.482680, -0.148390, -0.281680, -0.217250, -0.509550, 0.708580, 
0.005690, -0.323880, 0.192230, 0.773670, -0.295560, 1.129450, -0.596160, -0.663950, 0.079620, 
-0.544450, -0.248610, -0.660560, 0.079010, -0.225030, 0.813440, -0.671490, 0.073460, 1.084510, 0.592930, 
0.927080, 0.140170, 0.485800, 0.670820, 0.077600, 0.542700, 0.686090, 0.560910, -0.245930, -0.584750, 
-0.222060, 0.445630, 0.567430, 0.503430, 0.758930, -0.792860, -0.506150, 0.119250, -0.310970, -0.786580, 
-0.457680, 0.546690, -0.841050, -0.277000, 0.486290, 0.701680, 0.801790, 0.722840, -0.238900, -0.127910, 
0.804330, -0.665410, 0.602480, 0.040270, 0.199150, 0.180680, 0.430690, 0.017170, -0.147500, 0.078770, 
-0.410760, -0.131590, -1.112940, -0.803720, -0.813940, 0.752600, -0.462270, -0.498040, 0.072070, -0.725730, 
-0.031570, -0.286500, 0.679680, -0.434260, 0.619420, 0.184970, -0.714880, 0.001500, 0.551270, -0.591750, 
0.086200, 0.881360, 0.106260, -0.369730, 1.240410, -0.829400, 0.283210, -0.555220, -1.177890, 0.927530, 
0.551270, -0.068590, 0.979380, 0.749720, -0.497630, 0.315280, -0.658150, -0.178180, 0.803990, 0.404280, 
0.001140, -0.344150, 0.431960, 0.137100, -0.492140, 0.621910, -0.655040, -0.054680, -0.830740, -0.453070, 
-0.251450, -0.758090, 0.623790, -0.334960, -0.010510, 0.457070, -0.011020, 0.744070, 1.050040, 0.368040, 
0.243180, -0.562250, -1.287050, 0.420140, -0.004570, 1.065150, -0.989250, 1.172830, -0.865750, 0.837890, 
0.703370, 0.157300, -0.280570, -0.880420, -0.310790, -0.431860, 0.041130, -0.415800, -0.600370, 1.156730, 
-0.308780, 0.472580, -0.391280, 0.547560, 0.068390, -0.005180, -0.624330, 0.353800, -0.097310, -0.480430, 
-0.274390, 0.956810, -0.089450, 0.460100, -0.078030, -0.371900, 0.366840, -0.868410, -0.330720, 0.802620, 
0.415420, -0.655570, -0.234350, -0.214770, 0.864730, -0.231450, -0.004590, -0.396040, -0.972600, -0.452870, 
-0.865490, -0.571480, 0.086910, 0.575170, 0.119060, 0.029820, 0.746020, 0.240330, -1.118890, -0.863320, 
0.396820, -0.161540, 0.615700, -0.358620, 0.028630, 0.353970, -0.720820, 0.932410, -0.068390, 0.375430, 
0.095000, -1.012910, 1.273460, 0.089110, 0.222320, -0.643700, -0.982360, 0.978960, 0.448340, 0.165840, 
-0.225620, -0.031360, 0.355290, 0.327250, -0.176440, 0.584880, 0.495690, 0.301630, 0.156640, 0.349530, 
0.604360, -0.905240, -0.328690, 0.664320, -1.335500, 0.490580, -0.802340, -0.064970, -0.107640, 0.774960, 
1.115460, 0.331450, -0.033650, 0.520110, -0.799830, -0.232060, 0.902940, 0.211890, 0.996420, -0.168150, 
-0.856030, -0.273480, 0.765540, -0.238390, 0.253880, 0.462410, 0.104370, -0.087900, -0.245070, -0.575800, 
0.118940, -0.577260, -0.250330, -0.374730, -0.594070, 0.485870, -0.304570, 0.353590, 0.079440, 0.221240, 
0.104510, 1.026250, -0.226950, 0.415670, 0.335750, -0.508740, -0.410780, -0.542820, -0.784380, 0.094590, 
0.816470, 0.331210, 0.462460, -0.329280, 0.431310, -0.213170, 0.969540, 0.531140, 1.106830, 1.166330, 
0.211640, -0.068640, -0.143950, 0.471270, 0.303200, 0.181190, 0.514950, -0.863420, 0.297080, -0.226740, 
0.091210, -0.215200, 0.776170, 0.115760, -0.218770, -0.331720, -0.552340, -0.531700, 0.045610, -0.085490, 
-0.186190, 0.028530, 0.314000, 0.640060, -0.028760, 0.689770, -0.363540, -0.242720, 0.460710, -0.624650, 
-0.286520, -0.247090, 0.155810, -0.810390, -0.315370, -0.653910, 0.024060, 0.576600, 0.657880, 
0.073410, 0.011690, 0.774370, -0.444570, 0.224960, -1.022930, 1.122040, -0.127430, 0.469730, 1.108120, 
1.122870, -0.071560, -1.051400, 0.729280, -0.122830, 0.631060, 0.471550, -0.469890, 0.329520, 0.405900, 
-1.487910, -0.482570, -0.961430, 0.151680, 0.149180, -0.398520, -0.164510, -0.517460, -0.422810, -0.050750, 
0.564930, 0.981240, 1.051130, 0.676100, 0.264600, -0.899260, 0.209750, -0.393870, 0.011050, 0.264840, 
0.147080, 1.256720, -0.162340, 0.987540, -0.773080, -0.027410, 0.426910, -0.129020, 0.562150, 0.911050, 
0.390970, -0.830910, -0.195200, 0.997890, 0.105400, 0.849170, -0.332800, -0.919360, -0.189680, 0.307490, 
0.650080, -0.635650, 0.172040, 0.655660, 0.259070, -0.333220, -0.229260, 0.771410, 1.145480, 0.344380, 
0.451750, 0.960760, -0.886280, 0.317790, -0.351430, 0.032980, 0.034400, -0.365370, -0.105990, -0.802780, 
0.198250, 0.386550, 0.110560, -0.639260, -0.421340, -0.237270, 0.193310, -0.568650, -0.847770, -1.054890, 
0.376770, 0.935710, 0.579380, 0.690750, 0.019210, -0.756120, 0.419440, 0.943320, 0.412980, 0.183950, 
-0.806360, -0.931620, -0.510930, -0.356380, 0.096810, 0.785240, -0.178020, -1.388410, -0.520140, -0.082090, 
-0.811680, -0.195240, -1.050980, 0.576690, 0.001760, -1.134660, -0.288850, 0.278930, -0.272460, -0.023800, 
-0.783850, -0.954060, 0.266150, 0.248620, -0.238120, -0.721530, -0.473210, 1.324080, -0.676180, -0.362260, 
1.257250, -0.040060, -0.570630, 1.224800, -0.048800, 0.719320, -0.211690, 0.347050, -0.297290, -0.173170, 
0.946790, 0.177150, -0.417790, 0.782590, -0.971910, 0.056960, 0.039660, -0.789570, -0.199010, 0.613350, 
0.886640, -0.338690, 0.241850, 0.364710, -0.777090, -0.323750, -0.732200, 0.856190, -1.003330, 0.293370, 
0.214610, 0.486830, 0.711970, 0.047020, 0.626070, 0.366790, -0.031830, 0.336010, -0.159280, -0.045940, 
0.891390, 0.181870, 0.358830, -0.156950, 0.834710, -0.342300, 1.026110, 0.498410, 0.039810, -0.656530, 
0.534440, -0.659800, -0.551630, -0.462740, -0.865020, 0.121700, -0.047230, 0.594200, 0.522460, 0.536610, 
-0.662660, -0.577590, -0.503160, 0.179710, -0.543440, -0.522140, 0.100430, 0.176200, -0.068040, 0.893210, 
-0.288880, 0.296540, -0.043340, 1.143520, -0.071510, -0.209780, 0.664900, -0.025850, 0.452780, 0.592140, 
0.338090, -0.528910, 0.414170, -1.195150, 0.412310, 1.270220, 0.854650, 0.304890, -0.095630, 0.776950, 
-0.283260, -0.792350, -0.500160, -0.754310, 0.764570, -0.841350, -0.185910, 0.154510, -0.620970, 0.601940, 
-0.670960, 0.147860, 1.159980, 0.843800, 0.222760, 0.860440, 0.134080, 0.086530, -0.227250, 0.484950, 
-0.467510, 0.378160, -0.603210, -0.100940, -0.178230, 0.692640, 0.791380, 0.653660, 0.901780, 0.138340, 
-0.707840, -0.936210, 0.425620, -0.842990, -0.264040, 0.582980, -0.252310, -0.520920, -0.614500, 0.149040, 
1.315890, -0.257250, -0.126880, 0.278150, 0.212430, 0.433500, -1.024210, 0.321230, -0.273820, -0.738810, 
-0.908010, 0.265370, -0.465300, -0.421460, 0.607920, -0.237690, -0.442980, 0.778000, -0.478780, -0.469570, 
0.933530, 0.179890, -0.320630, -0.461610, -0.373910, -0.738280, -0.596410, 0.468020, -0.915920, -0.629840, 
0.001500, -0.704370, -0.582700, 0.622360, -0.266430, -0.660970, 0.517300, 0.561780, 0.419880, 
0.033710, 0.134000, -0.642140, 0.138020, 0.182380, -1.036720, 0.344810, 0.839820, 0.616720, -0.746030, 
0.200160, -0.730920, -0.353050, 1.061490, 0.794310, 0.291490, -0.164610, -0.878410, -0.074790, -0.536870, 
0.401900, 0.323670, -0.613180, -0.446380, 0.643610, -0.933340, -0.638820, -0.566720, 0.790640, -0.411600, 
-1.142590, -0.391300, 0.492470, -0.362570, 0.303310, -0.148280, 0.495070, -0.512020, -0.254040, 0.669210, 
-0.483840, 0.163320, 0.056200, -0.250120, 0.034330, -0.115080, 0.365890, 0.611990, 0.654550, -0.801900, 
0.004070, 0.433830, -0.416580, 0.838450, 0.468070, -0.794100, -0.979870, -0.143940, -0.521910, 0.788820, 
0.521490, 0.641170, -0.446470, 0.063670, -0.028610, 0.634000, 0.311200, 0.722630, 0.382220, 0.004200, 
-0.673880, -0.669900, -0.250250, 0.042490, 0.755100, -0.264260, -0.776590, -0.688470, -0.047350, 0.695990, 
-0.463560, 0.125670, 0.971170, 0.252680, -0.109630, -1.028210, 0.952700, -0.627380, -0.557430, 0.588960, 
0.031310, -0.267740, -0.683490, -0.481830, 0.038270, 0.275770, -1.155760, -0.423900, -0.491940, 0.095050, 
0.618140, 0.633800, -0.987590, -0.262830, -0.056900, -0.301560, 1.025770, -0.848360, -0.697770, 0.129560, 
0.946570, 0.174830, -0.520020, 1.259120, 0.632660, -0.697770, -1.029890, -0.190710, -0.872270, -0.129250, 
-0.794800, 1.120530, -0.269780, -0.836670, -1.700490, 0.083260, 0.654200, -0.141590, -1.147420, 0.013530, 
0.612050, -0.379780, -1.873660, -0.849810, -0.391500, -1.021070, -0.797210, 0.253160, 0.304580, -0.959570, 
0.512230, 0.244080, -0.600060, 0.252510, -0.373530, -1.122630, -0.339800, -0.253940, -0.265690, 1.140950, 
0.527580, -0.920760, -0.647260, -1.013200, 0.204030, 0.427320, 0.596860, 1.219200, -0.582200, 0.837300, 
0.578000, 0.293610, -0.529000, 0.659290, 0.112050, 0.463430, 0.167170, 0.085460, 0.046030, 0.463740, 
-0.552170, 0.363710, -0.118540, 0.523060, 1.118110, 0.343230, 0.067580, -0.249960, 0.831320, -0.681350, 
-0.089150, 0.193300, 1.115640, 1.235160, 0.856020, 0.179450, -0.112630, 0.432510, 0.907230, -0.320910, 
-0.655260, -0.805800, -0.850090, -0.451370, 0.430400, -0.732980, -0.564920, 0.081960, 0.362320, -0.891560, 
0.416690, -0.742090, 0.937420, 0.043890, 0.218950, 0.891070, -0.508070, 0.862020, -0.126810, 0.851540, 
-0.792070, 1.129830, -0.538690, -0.229360, -0.364270, -0.435190, -0.406740, 0.300960, -0.746040, -0.032440, 
0.426890, 0.182960, 0.870950, 0.137590, -0.011130, 0.260050, -0.416790, 0.623470, 0.637650, -0.242140, 
0.921250, 0.402790, 0.375630, 0.423140, 0.320150, -0.224040, 0.647420, 0.575460, 0.088490, -0.251630, 
-0.601540, 0.213760, -0.995530, 0.061850, -0.508020, 0.250990, -0.832210, 0.227040, -0.681460, 0.078670, 
1.067220, 0.002500, -0.711950, 1.066610, -0.172070, -0.909670, 0.008880, -0.356900, 0.295820, 0.814180, 
-0.368290, 0.793530, 0.540990, 0.926010, 0.179550, -0.970040, 0.420280, 1.056470, -0.251830, -0.065790, 
-0.221840, -1.293070, -0.438170, 0.372610, 0.341640, 0.220790, -0.355360, 0.456560, -0.185610, 0.950550, 
-0.217380, 0.018150, 0.703300, 0.496440, -0.398220, 0.239290, 0.189560, 0.319250, -0.436990, 0.330710, 
-0.482810, -0.416380, 0.814750, 0.746140, 0.241030, 0.947350, 1.070540, -0.318570, -0.765160, 
0.248540, 0.615170, -1.079550, -0.294920, 1.114990, 0.764280, 0.406030, -0.763890, 0.825190, -0.163680, 
-1.109910, 0.664380, 0.639790, 0.187390, -0.507170, -0.345870, 1.037220, -0.717370, -0.607110, -0.188640, 
0.354680, -0.970440, 0.081140, -0.179230, -1.159050, -0.010700, -0.377190, 1.045720, 1.190590, -0.302580, 
0.116440, -0.642910, -1.123960, -0.233500, 0.908000, -0.531170, 0.517500, -0.352410, 0.900240, -0.328280, 
-0.709780, 0.300620, -0.222920, 0.613700, -0.528260, 0.956310, -0.067280, -1.004090, -0.182440, 0.059390, 
-0.309710, -0.096120, 0.092660, -0.207030, -0.119990, 0.005090, 0.084990, -0.325470, 0.260610, 0.239010, 
-0.327380, -0.647040, 0.721130, 0.297390, 0.346630, -0.590190, 0.620290, -0.778570, 0.288440, -0.772370, 
-0.947400, -0.411480, -0.390010, -0.444300, -0.732200, 1.298370, 0.566930, -0.626120, 0.728850, -0.391520, 
-0.138340, 0.989430, 0.967110, 0.650540, -0.382990, -0.465160, -0.181620, -0.339930, 1.060470, -1.004260, 
-0.407310, -0.211180, 0.175820, 0.537480, 0.350110, 0.495190, -0.507770, -0.455420, 0.503310, 0.391820, 
0.031240, -0.535340, -0.747700, -0.393310, 0.568960, -0.251920, -0.337340, 0.310470, 0.487790, -1.187990, 
0.756340, -0.396990, -0.196170, 0.318560, 0.368750, -0.090890, 0.499470, 1.257060, -0.375100, 1.468160, 
0.023250, -0.727230, 1.529720, 1.384120, 1.552010, -0.356180, 0.606030, -0.676330, 0.841750, 0.153800, 
0.634710, 0.146580, 0.027870, -1.051600, -0.914150, -0.330510, -0.194300, 0.808360, -0.715190, -0.107120, 
-0.686790, 0.825600, 0.372780, -0.892500, 1.004960, -1.008370, 0.194820, 0.178910, -0.775070, 0.976110, 
-0.372860, -0.051640, -0.708640, -0.119590, 1.069910, 0.320010, 0.970170, 0.564110, 0.526400, 0.366770, 
0.149590, 0.737880, -0.789870, -1.075300, 0.249220, -0.688550, -0.169130, -0.017060, -0.284760, -0.082780, 
-0.581320, 0.472860, 0.100770, -0.726550, -0.415400, 0.551550, -0.582570, -0.597390, -0.420140, -0.252580, 
-0.581830, 0.557100, -0.700930, 0.559840, 0.120560, 0.764310, 0.654200, 0.167410, -0.645560, -0.923860, 
-0.720830, -0.678560, -0.397810, 0.839090, 0.400650, 0.065400, -0.476810, 0.809870, -1.372020, -0.951340, 
0.096760, -0.722190, -0.675390, -0.301730, -0.043130, 0.151800, 0.419660, -0.057670, -0.559880, 0.100430, 
-0.266400, 0.232280, 1.584110, 0.260570, -0.066870, -0.820580, -0.032840, -0.856940, 0.187070, 0.118500, 
-0.168220, -1.151420, 0.175850, -0.028630, -0.673380, -0.092000, 0.218180, 0.682430, -0.149440, 0.404830, 
-0.736350, -0.922910, 0.151200, -0.641780, 0.593120, -0.442610, -0.583450, 0.512520, -0.936550, -0.483050, 
-0.414800, 0.757180, 0.484150, -0.981140, 0.560820, 0.676850, -0.146280, -0.681600, 0.535870, -0.079830, 
-0.604380, -0.617610, 0.091900, -0.383050, 0.515960, 0.550130, 0.985930, -0.296740, -0.709680, 0.552820, 
-0.626500, -0.006380, -0.209080, -0.506730, -0.307950, 0.334620, -0.089120, 0.717230, 0.293520, 0.616260, 
-0.461320, -0.897490, -0.331210, 0.199820, -0.006840, 0.491110, -0.366380, 0.141720, 0.147980, -0.148740, 
-0.538030, -0.511920, -0.869980, 0.773100, 0.475030, -0.204630, -0.841830, 0.190810, 0.696850, 0.733340, 
0.044250, -0.102300, -0.652400, 0.173690, 0.214060, -0.623650, 0.451660, 0.280620, 0.747460, 
-0.064410, 0.095300, -0.555710, 0.222520, 0.523920, -0.468360, -0.412810, -0.553490, 0.118630, -1.047910, 
0.478380, -0.083010, 0.184490, -1.094310, -0.148720, 0.308450, 0.597540, -0.839770, -1.239590, 0.164920, 
0.623600, -0.707530, -0.249440, -0.848100, -0.668850, 0.459440, -0.269900, 0.416260, 1.038000, 0.165390, 
0.309580, -0.656290, -0.741960, 0.154790, 0.591710, -0.648350, 0.552740, 0.101550, 0.177800, -0.746650, 
-0.191980, -0.682730, -0.092500, 0.039490, 0.981010, 0.354540, -0.608650, 0.806120, 0.643810, -0.858260, 
0.849620, 0.099790, -0.382270, -0.085760, 0.459580, -0.936290, 0.914690, 0.342460, 0.483860, 0.006370, 
-0.673370, -0.552980, 1.011290, 0.350940, -0.424560, -0.860650, 0.361720, 0.148610, -0.520300, -0.561070, 
0.548530, 0.044270, -0.221180, 0.201460, 0.882660, 0.604180, 0.153880, 0.674850, 0.139930, -0.491540, 
0.521530, -0.131730, -0.000100, 1.050950, 0.252930, 1.039100, 0.820320, 0.479490, -0.469720, 0.130330, 
0.839300, -0.128960, 0.927460, 0.851070, 0.617540, -0.298430, 0.510260, -0.473550, 0.410850, 0.771710, 
-0.077360, -0.372960, 1.059460, -0.503810, 0.931840, 1.039980, 0.236360, 0.883680, 0.793310, -0.720640, 
0.839260, 0.549100, 0.631300, -0.521790, 0.126380, -1.422720, -1.808190, -0.542710, -0.287840, -0.589790, 
-0.990760, -0.086940, -0.196980, -0.803860, -1.067480, 1.049190, -0.052840, -0.365000, 1.077870, -0.483850, 
-0.122550, -1.073790, -1.888660, -1.182410, -0.066270, -3.718090, 0.019680, -0.691950, 0.519150, 1.053670, 
0.280500, -0.511160, 0.134440, 0.191320, -0.332840, 0.119940, 0.498460, -0.553630, 1.205100, 0.827830, 
0.152160, 0.746290, -0.044380, 0.811350, 0.257730, -0.080320, -0.778640, -0.172140, 0.355710, -0.229960, 
0.551500, -0.579620, 1.260770, -0.811450, -0.070230, 0.611650, -0.727480, -0.162220, 1.362110, 0.553090, 
-0.859940, 1.006600, -0.160950, 0.222690, -0.041720, 0.162320, 0.270320, -0.469600, 0.474420, 0.142400, 
-0.528880, 0.331340, -0.467460, 0.173790, -0.011820, -0.536030, -0.671890, -0.973540, -0.584770, 0.730250, 
1.093630, -0.334890, -0.789520, -0.345010, -0.685390, 0.981160, -0.073680, 0.519390, 0.347780, 0.510940, 
-0.424570, -0.913530, 0.826970, 0.029770, 0.365880, -0.384560, 0.442900, 0.237080, 0.707810, 0.625520, 
-0.515510, -0.230700, 0.498290, 0.188440, 0.697410, 0.435640, -0.676450, 0.772690, 1.283930, 0.183610, 
0.891710, 0.794190, 0.101290, -0.648400, 0.414460, 0.457660, -0.501490, -0.578120, -0.114360, 0.076300, 
0.586590, 0.327530, -0.817570, 0.307110, -1.037360, -0.168610, 0.919550, -0.145060, -0.441770, 0.363690, 
-0.174940, 0.488430, 0.340190, 0.622460, -0.570110, 0.493270, -0.408600, -0.839830, -0.275130, -0.269500, 
0.432420, -0.898020, 1.045600, -0.834980, 0.060900, -0.449450, -0.266010, 0.009570, 0.138450, 0.025700, 
-0.834010, 0.393380, -0.710520, 0.183610, -0.880690, 0.461340, 0.146110, -0.424520, 0.187840, -0.045630, 
-0.351980, -0.610260, -0.803550, -0.018450, 0.641050, 0.273620, -0.454390, -0.854950, -0.401870, -0.586830, 
0.548260, 0.442360, 0.964450, 0.409740, 0.862440, 1.210580, -0.142110, -0.435590, 0.803410, -0.025860, 
0.580360, 0.302530, -0.188210, 0.494380, -0.554100, -0.212540, 0.059140, -0.318370, 0.390140, 
-0.537520, 1.148080, -0.060430, 0.562280, 0.442380, -0.541430, 0.333500, -0.167830, 0.911040, 0.440890, 
0.007190, 0.312830, -0.065030, -0.071600, -0.323430, 0.567060, -0.870970, -0.011390, 0.727660, 0.588860, 
0.248400, -0.619330, 0.533380, -0.067430, 0.368390, 0.030760, 1.017740, 0.081660, 0.067340, -0.001220, 
0.228810, -0.389550, 0.041190, -0.565370, -0.273010, 0.150440, -0.102840, 0.320470, -0.069950, -0.360670, 
-0.077740, 1.193780, -0.413060, 0.391690, -0.748310, 0.943240, 0.603880, -0.373050, -0.108470, 0.874940, 
-0.003230, 0.637870, 0.251770, 0.471900, 0.896600, -0.365260, -0.642280, 0.221710, 0.386080, -1.481160, 
0.005700, -0.387050, -1.108240, -1.209990, -0.891720, 0.735650, -0.226820, -0.786350, 0.116050, -0.350420, 
1.800420, -0.328320, 1.203570, 0.554960, 0.522160, 0.031900, 1.187510, 0.759900, 0.505730, -0.363160, 
-0.031960, -0.506520, -0.859680, 0.734010, 0.712370, -0.238290, 0.269940, -0.263710, 0.968780, 1.241110, 
0.538930, 0.474130, 0.315730, -0.502430, 0.470580, 0.068710, 0.695990, -0.771240, -0.686580, -0.415560, 
0.843070, -0.448910, -0.148020, -0.096050, -0.881100, 0.526320, -0.174500, 0.841280, -0.405490, 0.396970, 
-0.311660, -0.487870, 0.729480, 1.337370, -0.360690, -0.361750, 0.075180, -0.714400, 0.666520, 0.948380, 
0.511420, 0.742620, 0.415950, -1.709170, -1.601120, 0.014840, 0.978260, 0.264570, -0.336290, 1.075320, 
0.960380, 0.232400, -1.858760, 0.343660, 0.263230, -2.289550, 0.022540, 1.993970, -1.219670, -0.245060, 
-0.069840, 0.408160, -1.010180, -0.007880, 0.198700, -0.748530, -0.495860, 0.394040, 0.064730, 0.574150, 
-0.861040, -0.170840, 0.052980, -0.551710, 0.749730, 0.721820, -0.297340, -0.760400, -0.720840, 0.913540, 
0.673620, -0.565280, -0.347620, 0.391130, -0.009110, -0.792450, 0.450290, -0.664380, 0.342630, -0.518580, 
1.141680, -0.025160, 0.608270, -0.299470, -0.115490, 0.451530, -0.289560, -0.080110, -0.406540, -0.041500, 
0.717310, -0.623580, 0.472130, -0.042420, -0.994580, 0.013620, 0.755720, 0.379830, 0.528580, -0.229140, 
0.411710, 0.649610, 0.892700, -0.276520, 0.072350, 1.077950, 0.229320, 1.171090, 0.765530, 0.347310, 
0.844380, -0.420010, -0.834610, 0.187620, 0.071390, 1.305620, 0.021950, 0.139060, -0.077420, 0.173880, 
0.994230, -0.632080, 0.088380, 0.066770, -0.130330, 0.249640, -0.464100, 0.777460, 0.253570, -0.303690, 
0.564400, 0.426620, 0.208100, 0.626310, 0.225530, 0.984120, -0.284960, -0.336300, 0.500930, 1.335500, 
-0.315670, -1.454830, -0.402970, 0.880950, -0.487460, -0.197700, -1.031660, 0.703690, 0.410760, -1.318150, 
0.625960, 0.003980, -0.051240, -0.891100, -0.234040, -0.736660, -0.721700, 0.580400, 0.781430, -0.777560, 
0.432310, -0.305370, 0.001400, 0.771330, 0.093170, -0.702770, 0.455670, -0.258590, -0.081850, -0.822040, 
-0.009760, -0.173760, 0.922510, 0.595470, -0.692930, 0.525940, -0.112360, -0.195080, -0.043470, -0.212400, 
-0.829810, -0.061270, -0.379410, -0.154190, 0.494070, -0.037150, -1.000420, -0.742610, -0.147470, -0.318130, 
-0.721160, -0.213780, -0.965720, -0.525740, 0.333530, -0.046310, -0.546180, 0.601130, 0.242250, -0.050080, 
-0.612090, 0.009460, -0.946980, 0.622680, 0.222450, -0.718390, -0.049830, -0.079680, -0.033120, 
-0.119440, 0.516900, 0.412310, 0.085360, -0.723100, 0.135810, 0.307200, -0.145330, 0.183060, 0.136590, 
0.027130, -0.132950, 0.504190, -0.961220, 0.729510, 0.752190, -0.863900, 0.074580, -0.349240, 0.704730, 
-1.203820, 0.824240, -0.965090, -0.041620, 0.033760, 1.203630, -0.114400, 0.307140, -0.495400, 0.240110, 
-0.130470, -0.993950, 0.495460, -0.369070, 0.676110, -0.242570, -0.769130, -0.510320, 0.989440, 0.494170, 
0.431140, 0.652440, -0.624940, 0.265540, -0.862780, 0.179240, -0.472090, 0.172220, 0.201850, 0.084280, 
-0.016990, 0.259990, 0.353940, -0.744140, 0.923920, 0.651370, -0.869810, 0.976990, -0.579110, -1.193500, 
-0.419880, -0.334700, -0.220530, 0.137080, 0.566950, -0.092800, 0.070110, 0.612840, 0.389510, -0.619780, 
-0.145060, 0.337340, 0.309290, 0.465940, -0.114040, 0.213500, 0.785080, 0.705100, -0.008050, -0.643000, 
-0.717570, -0.404530, 0.093290, -0.159100, 0.547370, -0.039320, 0.362010, -0.349410, 0.039890, -0.295980, 
-0.567600, 0.504600, 0.476900, -0.159430, 0.441230, 0.136730, 0.156310, 0.199830, -0.145500, 0.107930, 
-0.393940, 0.048480, 0.384250, -0.605860, 0.534280, -0.513910, 0.055500, -1.402940, 0.252310, -0.141700, 
0.489990, 0.002120, -0.797940, 0.076390, 0.330450, 0.621820, -0.256250, 0.942560, -0.549390, 1.207250, 
0.198930, -1.156390, 0.285140, 0.561800, 1.104880, -0.137810, 0.113920, 1.137340, 0.520180, -0.064890, 
0.016860, -0.616970, 2.157560, 0.636710, 0.415410, 3.179220, 1.659320, -1.141130, 0.483910, -0.398190, 
1.601430, -0.627480, -0.836050, 0.159440, -0.032580, -0.568960, 0.435780, -0.110570, 0.167350, 0.515900, 
-0.811660, 0.719250, 0.850740, -0.353330, -0.747710, -0.117800, 0.161360, 0.111780, 0.013640, 1.057790, 
-0.274900, -0.143180, 0.581150, 0.322470, -0.574470, 1.107080, 0.221950, -0.376720, 0.151690, 0.450480, 
-0.468920, -0.384350, 0.717620, 0.612220, -0.925910, 0.653830, 0.198920, 0.404130, 0.535630, 0.362600, 
-0.554250, -1.152200, 1.027890, -1.144340, -0.424740, 0.734460, -0.053490, -1.846460, 0.826920, 0.901800, 
0.901560, 0.236730, -0.520440, 0.417150, 0.667000, 1.198950, 0.557300, -0.703650, 0.361710, -0.230070, 
-0.308920, -0.125650, -0.569990, -0.516560, -0.172020, 1.061670, -0.105390, -0.098710, 0.935540, -0.282280, 
-0.406120, 0.203340, -0.039090, 0.517480, 1.093100, 1.054560, 0.597840, 0.557580, 0.312520, -0.190570, 
-0.285960, -0.854330, 0.149320, -0.043250, 0.729700, -1.328430, 0.093140, 0.014320, 0.600310, -0.183940, 
0.356720, -0.488840, 0.401960, -0.066580, 0.719370, 0.192750, 0.188460, 0.063940, 0.917110, -0.559100, 
1.053950, -0.411100, -0.765330, -0.625150, 0.818880, 0.716900, -0.393110, -0.781490, 0.084350, -0.167710, 
-0.381840, -0.219000, -1.127940, -0.201790, 0.051810, 0.106600, -0.501710, 0.299000, 0.744540, -0.010660, 
-1.193740, -0.678020, -0.164680, -0.813040, 0.210850, -1.206400, -0.201580, -0.655420, 0.284990, 0.457480, 
-0.922670, 0.070950, -0.000970, 0.495910, -0.435860, 0.503870, 0.359790, 0.691560, -0.008440, -0.101380, 
0.026350, -0.282930, -1.047240, -0.650170, 0.747510, -0.122280, 0.612750, -0.255770, 0.502430, 0.196460, 
0.942720, 0.552890, 0.145460, 0.138660, 0.047700, -0.557100, -0.788500, -0.551060, -0.300370, 
-0.412560, 0.005900, 0.188360, 0.361690, -0.203540, 0.200970, 0.291460, -0.311130, -0.232180, 0.576700, 
-0.270870, 1.259030, -0.261280, -0.195510, 0.036920, 0.082470, 0.725860, -0.799940, -0.224330, 0.095280, 
0.751320, -0.237280, 0.591660, -0.324160, -0.038860, 0.399590, -0.235750, 0.413600, 0.456120, 0.566650, 
-0.066870, -0.206460, 0.475850, -0.694750, -0.745890, -0.386000, 0.360120, 0.636490, -0.239950, 0.598390, 
-0.294670, 0.246650, 0.554180, -0.218490, -0.030060, 0.555300, -0.032430, 0.662190, 0.359780, -0.982160, 
-0.083390, 0.617570, -0.121640, 0.684210, 0.859560, 0.887080, -0.169810, -0.240100, -0.034660, -0.791540, 
-0.632670, 0.352780, 0.387350, -0.206830, 0.321400, 1.207400, -0.318150, 0.085820, -0.788560, 0.167740, 
0.208100, 1.018110, -1.354830, 1.026700, -0.869140, 0.185310, 0.574250, 0.422940, 0.448050, -0.406230, 
0.365120, -0.661240, -1.077310, 1.581570, 0.111160, 0.036060, -0.638810, -0.147730, -0.054000, -0.915070, 
-1.085500, -0.640710, -0.562230, 0.510800, -0.621360, -0.888930, -0.741410, -0.874210, -0.204950, 0.062750, 
-0.062020, -0.342000, 0.428070, 1.000160, -1.045420, 0.184070, -0.498430, 0.488300, -0.296440, -1.281460, 
-0.232530, -0.082530, 0.075790, 0.002870, -0.551960, 0.353230, 0.431910, 0.133700, -0.504900, 1.447870, 
-0.210090, 0.162050, -0.716070, 0.400530, 1.233380, 0.695340, -0.361820, 0.496930, 0.863710, 0.669730, 
0.079940, 0.097370, 1.320120, -0.530380, -0.154260, 0.290810, 0.261630, -0.373200, 0.013540, -0.100320, 
-0.405990, 0.161100, -0.382470, -1.322070, -0.563850, -0.213170, 0.057910, 0.292390, -0.512680, -0.998220, 
-0.375940, 0.726190, 0.288470, -1.568180, 0.223150, 0.612230, 0.057080, 0.246880, 0.990180, -1.027770, 
-0.878010, -1.057000, 0.388860, -0.398280, -0.211130, -1.062810, 0.049170, -0.105750, 0.057800, -0.488690, 
1.034870, -0.638910, 0.562140, 0.781710, 0.379720, -0.860930, 1.038040, 0.259430, 0.632980, 0.473440, 
-0.204210, -0.587380, 0.565760, -0.510250, -0.088920, -0.444100, 0.272960, -0.570010, -0.330650, 0.337510, 
-0.214260, 0.298340, -0.749840, -0.190920, 0.101160, -0.202210, -0.145840, -0.224420, -0.577200, -0.608950, 
0.125640, 0.078380, 0.361770, -0.534450, -0.407610, -0.697290, -0.343670, 0.464070, -0.039950, 0.646030, 
-0.237960, -0.548980, -1.191160, 0.716140, -0.424970, -0.034740, 0.282280, 0.602770, 0.149150, 0.377980, 
-0.382820, 0.380500, -0.542450, -0.524850, 0.472690, 0.833940, -1.207000, 0.197160, 0.247580, 0.231250, 
0.360480, 0.355070, -0.654120, 0.484330, 0.593080, 0.901480, -0.801100, -0.697670, -0.860040, -0.484100, 
-0.431420, 0.555280, -0.087190, 0.069200, 1.148590, -0.772960, 0.200100, -0.089710, -0.218370, -1.048310, 
-1.228120, 0.083340, -0.256150, 0.728840, 0.651350, -0.681100, -0.634560, -0.116480, -0.491270, -0.045740, 
-0.460260, 0.329540, -1.661200, 0.055330, 0.696080, 0.119380, 0.705830, -0.051320, -0.079770, -0.462550, 
-0.166950, -0.463840, -0.199560, -0.235430, -0.031440, 0.483610, -0.247990, -0.239450, -0.238830, 0.389820, 
0.878350, -0.089550, -0.562070, -0.050580, -1.319310, 0.734410, -0.803450, -0.380250, -0.257720, 1.005770, 
-0.774550, -1.025100, -0.574310, 1.017210, -0.082280, 0.232520, 0.942320, -0.346850, -0.746440, 
-0.451220, 0.387720, -0.168780, 0.453170, -1.084970, 0.299160, 0.298980, -0.759230, -0.575400, -0.276910, 
0.021340, 0.172210, -0.834370, -0.482210, 1.059070, 0.185740, 0.641830, -0.117600, -0.375680, 0.228860, 
-0.195290, -0.707610, -0.248830, 0.011470, -0.702070, -0.368220, -1.135770, -0.766520, -1.299270, -0.685910, 
0.496830, -0.458910, 0.306760, 1.000290, 0.490020, 0.415230, 0.044740, 0.095110, -0.460500, 0.122420, 
0.245700, 0.662790, 0.093500, 1.393630, 0.222510, 0.384230, -0.236530, 0.044660, 0.739960, -0.089740, 
0.230400, -0.734450, 0.437810, 0.073450, 0.895060, -0.308730, 0.015620, 1.044450, -0.766340, -0.191930, 
0.788300, 0.052520, -0.052610, -0.395270, 0.324010, 0.627020, 1.297360, -0.141420, -0.436480, -0.580500, 
-0.547670, 0.331970, -0.103820, 0.305820, -0.896480, 0.595000, -0.988350, -0.517190, -0.327870, -0.305160, 
-0.828420, -0.627410, 0.825700, -0.234240, 0.833630, 0.014570, -0.916300, -1.011590, 0.557190, 0.868250, 
-0.627600, -0.413190, -1.056370, 0.396270, -0.059430, -0.378690, 1.048720, 0.420840, 1.169530, -0.449980, 
-0.066650, 0.536350, 0.564760, 0.535240, 0.538770, -0.017710, 0.579450, 0.586330, -0.289660, 0.781430, 
0.073130, -0.893750, 0.870100, 0.572920, -0.024390, -0.408630, -0.210310, -0.600890, 1.293470, -0.294710, 
-0.482970, 0.753030, 0.021930, -0.908480, 0.055470, 0.579320, -0.462640, -0.159220, -0.543550, -0.618100, 
-0.281970, -0.952110, -0.436610, -0.149910, -0.237340, 0.718210, -0.341250, -0.499740, 0.207810, -0.927590, 
-0.666300, -0.154150, 0.419330, -1.054560, 0.208330, -0.239210, 0.014920, 0.251950, -0.099650, 0.437960, 
0.025830, 0.827450, 0.274720, 0.815260, 0.862370, -0.031900, 0.531340, 0.024910, 0.361820, 0.350960, 
-0.811510, -0.818560, 0.398540, -0.811020, -0.373620, 0.276010, 0.924270, 0.154680, -1.121390, -0.051190, 
0.112160, -0.120420, 1.164080, -0.690700, 0.155590, -0.654790, 1.305730, -0.404400, -0.293110, 0.057290, 
-0.677570, 0.364290, -0.472480, 0.601360, -0.709640, -0.035140, 0.321180, 0.401210, -0.313580, -0.644540, 
0.571340, -1.157350, 0.674390, -0.363300, 0.136870, -0.617360, 0.133270, -0.622410, 0.945660, -0.204220, 
-0.752620, -0.016660, 0.693400, -0.317710, 1.106110, -0.185970, -0.166910, -0.123020, -0.718760, -0.098720, 
-1.047940, -1.231550, -0.598440, 0.526990, 0.748520, 0.806680, 0.644980, -0.434000, 0.360200, -0.036280, 
-0.272350, -0.217040, 0.571590, -0.464890, -0.450070, 0.657200, 0.821580, -0.770720, -0.530230, 0.360030, 
-0.336130, -0.485560, 0.137670, 0.547150, 0.544370, -0.327510, -1.099930, -0.353040, 1.046110, -1.027600, 
0.201010, -0.430030, 0.525390, -0.604060, -0.705830, 0.231260, -0.179780, -0.842300, -0.610770, 0.153350, 
-0.090740, -0.158850, -0.186230, 0.661670, 0.559920, -0.361210, 0.413490, 0.527020, -0.247590, -0.584940, 
-0.902360, -0.387310, -0.321000, 0.446460, 0.081960, -1.014060, 0.214690, -0.023940, 0.174050, 0.241540, 
-0.214740, 0.154770, 0.132240, -0.143720, 0.789790, 0.139590, -0.768490, -0.124540, 0.917460, -1.036600, 
-0.566770, 0.201310, -0.615330, 0.261170, 0.975640, -0.442840, 0.073980, -0.474310, 0.302640, -0.992550, 
0.101670, -0.618170, 0.548910, 0.140590, 0.476290, 0.421570, -0.066170, 0.624830, -0.714850, 
-0.227260, -0.195730, -1.137040, 0.063880, 0.956080, -0.810150, -0.040020, -0.221230, -0.378470, 1.048850, 
-0.441260, -0.648040, -0.487810, 0.301580, 0.018970, 0.078720, 0.747700, -0.426640, -0.881510, 0.104060, 
-0.650010, -1.053770, 0.269960, 0.783300, -0.536320, -0.267010, 0.390060, -0.607440, -0.114010, 0.206560, 
0.658470, -0.866060, 0.241240, -0.494790, -0.635970, -0.544420, -0.784530, 0.713180, -0.154020, -0.570360, 
0.516820, -0.701780, -0.293750, 0.876490, -0.277310, -0.140790, 0.231550, 0.404720, 0.346690, -0.420860, 
0.408790, 0.063360, 0.609370, -0.610620, -1.116240, -0.791650, -0.102670, -0.155980, -0.615930, -0.089810, 
-0.487500, 0.084760, 0.192420, -0.474980, -0.064330, -0.266590, -0.156730, -0.279740, -0.118540, 0.543260, 
0.829480, -0.382650, -0.792440, 0.282010, 0.241580, 0.456180, -0.262280, 0.422700, 0.809120, -0.106410, 
-0.328060, -0.408060, 0.401620, 0.574650, 0.312960, 0.626040, 0.773930, -0.651320, -0.663170, 0.067270, 
-0.281600, 0.851200, -0.699590, 0.766280, -0.366460, 0.656090, 0.256580, -0.593020, 0.315870, 0.643520, 
-0.127340, 0.198700, 0.419290, -0.378830, 0.915930, 0.400020, -0.100240, -0.491310, -0.696630, -0.527990, 
-0.515810, 0.529060, -0.002050, 0.812790, 0.712650, -0.685410, -0.789910, -0.699360, 1.243870, 0.093890, 
0.294820, 0.499920, -0.555180, -1.634410, -1.210710, 0.539760, 0.601460, -0.695470, -0.413130, -0.289380, 
-0.931540, 0.542550, 0.052770, 0.397000, -0.516950, -1.484280, 0.130510, 0.629870, -0.546320, 0.408260, 
-0.825490, 0.715850, 0.075290, -0.790700, -0.166660, 0.667330, 0.760740, 0.706840, 1.049300, 0.104920, 
-0.643580, 0.323470, 0.459860, 0.845350, -0.584370, -0.481790, 0.003320, 0.744990, 0.889170, -0.918590, 
1.382370, 0.928550, -0.120250, 0.512080, 0.626100, -0.447080, -0.522640, -0.286730, 0.117100, -0.509060, 
0.763490, 0.265860, 0.608940, -0.298940, 0.891530, 0.484310, -0.412410, 0.956800, -0.259070, -0.897430, 
-0.118290, 1.057690, 0.941090, -0.087690, 0.025060, 0.541140, 1.137940, -0.543000, 0.450500, -0.515560, 
-0.662770, 0.594670, -0.111170, -0.113650, -0.195910, 0.017100, -0.170540, -0.127440, -1.187560, 0.130570, 
-0.884950, -0.152520, 1.089290, 0.500350, 0.080250, -0.974040, -0.241050, -0.067730, -0.718860, -0.931600, 
0.408980, -0.841490, -0.096690, -0.432170, 0.348210, 0.540660, -0.537380, -0.737580, -0.247380, -0.482580, 
-1.007590, 0.704900, -0.335400, 0.793940, -0.469670, -0.232260, -0.348260, 1.299960, 0.254100, -0.892470, 
0.730280, -0.136910, -0.949900, 0.633250, 0.104210, 0.354130, -0.506100, -0.726910, -0.051710, -1.032300, 
0.948530, -0.521570, -0.177990, -0.456990, -0.367900, -1.102480, 0.642680, 0.244710, 0.116220, 0.214470, 
0.761220, -0.315520, -0.721090, -0.609710, -1.106620, 1.113580, -0.037070, -0.285080, -0.301120, 1.334790, 
1.139990, 1.028730, 0.070620, -0.295970, 0.268350, -0.616970, -0.314170, -0.818960, 0.570100, 0.382400, 
-0.373320, -0.401130, 0.295950, -1.029330, 0.241050, -0.832540, -0.793680, 0.513340, -0.027870, 0.343250, 
1.001700, 0.180410, 1.212530, 0.442870, -0.617450, 0.417600, -0.451910, -0.465300, 0.528470, 0.712220, 
-0.782170, -0.999020, -1.003130, -1.237320, 0.457290, -0.744500, 0.104090, -0.943240, 0.441610, 
1.199310, 0.209160, -0.667210, -0.589350, -0.158620, -0.704150, 0.001420, -0.802210, -0.257660, 0.798610, 
0.818720, 1.064630, -0.768180, -0.384420, 0.884290, 0.959750, -0.816590, 0.512990, -0.542410, 0.003300, 
1.034200, -0.713220, 0.264780, 0.130370, -0.833700, 0.513080, -0.449390, -0.154750, 1.104720, 0.293070, 
-0.183930, 0.596000, 0.296440, 0.740130, 0.574070, -0.081600, 1.015790, -0.275820, 0.084690, -0.292090, 
0.018590, -0.393390, -0.460580, -0.710460, -0.949120, 1.279910, 1.407850, 0.044400, -0.528780, -1.030320, 
-0.418510, 0.725100, -0.583560, 0.487970, -0.746380, -0.248610, -0.667010, -0.051760, -0.989710, 0.723650, 
-0.146650, 0.659360, -0.240400, -0.604820, -0.584910, 1.133750, 0.532980, -0.599600, -0.377510, -0.021500, 
-0.870240, 0.644880, -1.211180, 0.516880, -1.049890, -0.024430, -0.090490, -0.762960, 0.110630, -0.243680, 
0.179820, 0.171180, 0.581170, -1.006780, -0.482370, 0.566720, -0.109850, -0.340470, -0.721960, 0.190390, 
-0.277580, 0.321890, -0.016400, 1.123940, -0.550340, -0.217190, -0.917170, -1.036200, 0.914100, -1.211160, 
-0.632980, -0.149550, -0.135740, 0.617310, -0.907260, -0.289480, 0.524340, 0.295060, -0.365270, -0.380960, 
-0.072010, 0.608730, 0.112510, 0.098940, 0.509410, 0.298250, -0.888700, 0.167260, 0.873160, 0.593780, 
-0.317570, 0.959570, -0.481980, 0.500540, -1.149400, 0.187130, 0.618670, 0.589590, 0.279460, 0.598730, 
1.194880, -0.643280, -1.185460, 0.353640, 0.261030, -2.095480, 0.147440, -0.062850, -1.086460, -0.232700, 
-0.549410, -0.499500, -0.465920, -1.000170, -0.575650, 0.466240, -0.653650, -0.578440, 0.147550, -0.459270, 
-0.313430, 0.082000, -0.878920, 0.360640, 1.171570, -0.462240, -0.547210, -0.580050, -0.622830, -0.122930, 
-0.175110, -0.341590, -0.361670, 0.362370, -0.497800, 0.364780, 1.039430, -0.730740, -0.062180, -0.489760, 
-0.153240, 0.102420, -0.172770, 0.492960, 0.869640, 0.295480, 0.027860, -0.031430, 0.088350, 0.390900, 
-0.910190, 1.324200, -0.843840, -0.358670, -0.393210, -0.223950, 0.543810, -0.765700, -0.700830, 1.074230, 
-0.610910, 0.194460, -0.449930, 0.836360, 0.314420, -0.837150, -1.221660, 0.308460, 0.703630, -0.016590, 
-0.594510, 0.242630, 0.302330, -0.159880, 0.479560, -0.367060, -0.452150, 0.609390, -0.126980, -0.935780, 
-0.598940, -0.236040, 0.437260, -0.174260, 0.302280, 0.523400, -0.194530, 0.272980, 0.276580, -0.161420, 
-0.158500, -1.106950, 0.689970, -0.683860, 0.488820, 0.099720, 0.702830, -0.151380, 0.765800, 0.636060, 
-0.387840, -0.617210, -1.117180, -0.256560, -0.904200, -0.378000, 0.299770, 0.347470, 0.183630, 0.221180, 
0.094820, -0.282950, -0.861240, 0.296470, -0.167040, 0.172330, 0.256770, -0.537590, 0.299800, -0.593490, 
-0.443080, -0.342760, 0.822920, -0.103700, 0.360030, -0.551060, 0.186770, -0.855930, -0.211180, 1.570840, 
1.401020, -0.273740, 0.418390, 0.731760, -0.184080, -0.806740, -0.071400, -0.932450, -0.326610, 0.654090, 
-0.380410, -0.634860, -0.912390, 0.631610, 0.028500, 0.065110, 0.609350, -0.730490, -0.097040, -0.072820, 
0.187080, -0.468250, -0.192330, -0.481310, 0.809640, -0.244100, 0.090040, 0.180960, -0.014120, -0.566130, 
-0.622410, 0.345610, 0.264940, 0.062230, 1.165210, -0.517780, -0.362820, -0.346970, -0.412090, 
0.067770, 0.344260, 0.222600, -0.290480, -1.075960, -0.364210, 0.022720, -0.428880, 0.582210, -0.314370, 
-0.709610, 0.395580, 0.003250, 0.376380, -0.163020, 0.185710, 0.086800, -0.037050, -1.146450, 0.399620, 
0.810110, 0.683710, -0.248020, 0.191130, 0.108520, -0.431090, 0.058890, 0.526730, -0.598360, 0.254800, 
0.452600, 0.035950, 0.159380, 0.433080, -0.262680, 0.373800, 0.710270, 0.669910, 0.012280, 0.166860, 
-0.377350, -0.319660, 0.286270, 0.195350, -0.291320, -0.050760, -0.150320, -0.672100, -0.040220, 0.085100, 
-0.724050, 0.411180, 0.461110, 0.433490, -0.423910, -0.307200, 0.329400, -0.000580, -0.394820, -0.061430, 
-0.427600, -0.481090, 0.288640, -0.304240, -0.331170, 0.876060, -0.486550, -0.256140, -0.256390, 0.814700, 
-0.541620, 0.089120, 0.858970, -0.522180, -0.338910, -0.245540, -0.626120, -1.236400, 0.215460, 0.954740, 
0.464390, 0.308760, -0.506200, -0.700020, 0.834250, 0.213140, -0.901820, -0.573950, -0.392550, 0.466350, 
-0.665110, -0.486240, -0.394490, 0.061250, 0.954720, 0.220880, -0.063030, -0.290900, 0.227450, 0.459500, 
-0.088440, 0.650690, 0.067690, 0.325900, 1.341710, 0.076650, -0.292060, 0.132610, 0.090340, -0.026100, 
-1.535730, -0.835720, 1.344530, 0.052510, -0.018890, -0.256030, -0.429650, 0.263950, -0.338280, -0.825270, 
0.333050, 0.610950, -1.143660, -2.204970, -1.784530, -0.020910, 0.212180, 0.218430, -1.650910, 0.391660, 
1.025220, 0.652940, -2.521710, 0.821350, 1.046780, -3.125560, -0.263460, 0.402080, 0.645520, 0.374520, 
0.165770, -0.605520, 0.476580, 0.228250, 0.395480, -0.297500, 0.364650, -1.193180, 0.654900, 0.025080, 
-0.383110, 1.075910, -0.003580, 0.287940, -0.405250, -0.996970, 0.792160, 0.894090, 0.122720, 0.403870, 
1.133050, 0.219730, -0.186660, -0.501980, 1.174830, 0.088460, 1.009030, -0.114480, -0.402910, -0.172310, 
0.208870, -0.999570, 0.274460, 0.378910, -0.502740, 0.182570, 0.395170, 0.743910, -0.152750, 0.654780, 
0.017960, -0.366130, -0.688860, 0.544490, 0.844370, 1.080560, -0.034980, -0.865470, 0.265000, -0.081290, 
0.764730, 0.299090, -0.474470, 0.258500, -0.236100, 0.404130, 0.044400, -1.154910, -0.234850, -0.708440, 
-0.221500, 0.199620, 0.111320, 0.365870, -0.885130, -0.162980, 0.987870, -0.618350, -0.691670, 0.177660, 
0.910600, 0.898120, -1.735640, -0.479010, 0.322160, 0.394490, -0.162280, -0.192760, 0.654730, 0.335430, 
0.150390, -0.151010, -0.573020, -0.705900, -1.141670, 0.920940, 0.341000, -0.170860, -0.650540, -0.353060, 
-0.500310, 0.273820, -0.325870, 0.236360, 1.179190, -0.041540, -0.523340, -0.767440, 0.139140, 0.323230, 
0.285780, -0.598070, 0.696620, 0.396450, 0.451950, 0.759270, -0.211550, -0.134430, 0.099070, -0.013560, 
-0.316910, 1.278410, -0.177540, -0.443280, 0.081760, -0.613530, -0.193940, 0.316270, 0.793160, -0.411280, 
-0.944720, 0.293690, 0.597750, 0.437170, -0.953510, 0.924140, 0.004240, 0.385630, 0.530940, 0.853770, 
0.606600, 0.058910, -0.164230, -0.933410, -0.127060, 0.468630, 0.172690, 0.294140, 0.555440, -0.263000, 
-0.359880, -0.465630, 0.894550, -0.385080, -0.601050, -0.678450, -0.413470, 0.708670, -0.831000, -0.310650, 
0.821830, -1.112270, -0.350880, 0.235820, 0.582490, 0.490370, -0.530730, 0.303250, 0.915910, 
-0.889120, 0.559630, -0.235620, -0.653830, -0.482610, -0.272860, -0.567380, -1.360530, 0.037760, 0.880830, 
-1.043630, 0.392130, -0.745990, -0.314320, 1.201360, 1.074970, -1.092130, 0.722140, -0.190990, -0.229600, 
-0.869350, -0.000270, 0.297620, 0.432290, 0.526240, -0.357390, 0.092540, -0.743370, 0.301020, -0.388090, 
-0.244310, 0.167520, -0.209360, 0.175880, -0.253880, 1.019200, -0.787090, 0.513300, 0.636500, 0.205280, 
0.919090, 0.362540, 0.407740, -0.580980, 0.858440, 0.747340, -0.273080, -0.600210, -0.589200, -0.157220, 
-0.919450, 0.116560, 0.074330, 1.259040, 0.142400, 0.144460, -0.350640, -0.225180, -0.184850, 0.177050, 
-0.028070, -1.157890, -0.687440, 0.260590, -0.731550, -1.082340, -0.608010, 0.762170, -0.307560, 0.329670, 
1.197440, -0.374260, 0.231460, -0.331560, 1.018230, -0.955120, -0.187390, 0.964200, -0.471120, 0.366650, 
0.514150, 0.038410, -0.361400, -0.347350, -0.536820, 0.214340, 0.383680, -0.180760, -0.354050, -0.558270, 
0.160120, -0.460200, -0.307600, -0.124990, 0.018510, 1.084020, 0.644680, -0.385200, -0.234910, -0.942960, 
-1.118280, 0.594570, 0.771070, -0.383680, -0.177570, -0.427440, 0.635840, -0.920450, 0.015490, -0.115350, 
0.423630, 0.696100, 0.181120, 0.173800, -0.046640, 0.901250, 1.048360, -0.163670, -0.008330, -0.615480, 
0.254710, 0.149790, -0.224720, -0.326480, 0.530890, -0.132440, 0.520210, -0.753780, 0.644900, 0.233670, 
-0.454070, -0.130740, -0.415430, -0.166240, -0.759250, -0.073830, 1.188240, 0.061970, -0.928470, -0.564880, 
0.986630, 0.071350, -0.750290, 0.267300, 0.090110, 1.113510, 0.343270, 0.426970, 0.196050, -1.219730, 
-0.927920, 0.310990, -0.414050, -0.845170, -0.387120, -1.004220, 0.934440, -0.875510, -0.947560, -0.118820, 
0.171630, -1.106350, -0.186020, 0.672790, 0.529910, -0.340290, 0.129940, 0.086160, 0.699320, 0.011350, 
-1.243830, 0.732380, -0.649810, -0.039100, 0.042580, -1.213190, 0.508690, 0.429480, 0.063880, 0.762090, 
0.516650, 0.869480, -0.160920, 0.269720, 0.333640, 1.136850, 0.327600, 0.493970, 0.953060, -0.436510, 
-0.661880, -0.147930, -0.842240, -0.578310, 0.223320, -0.693210, 0.727930, -1.475310, -0.203310, 0.157530, 
0.385070, 0.723220, -0.331370, 0.167510, 0.284520, -1.004840, 0.608310, -0.096870, 0.586290, 0.268610, 
0.797960, -0.306670, -0.243860, -1.072460, -0.912820, 0.211070, 0.343860, 0.362860, -0.972400, -0.910880, 
-0.468950, -0.447650, -0.062750, -0.395560, -0.012110, 0.674810, 0.211090, -0.789240, 0.833060, -0.296720, 
0.753180, -0.865840, 0.011580, -0.729840, -0.593240, -0.418180, 0.753280, -0.424790, 0.346420, 0.101210, 
0.744290, 0.122130, -0.527970, 0.095400, 0.393120, -0.662400, -0.103770, 0.678820, 0.106360, -0.364660, 
0.289150, -0.138620, -0.651580, -0.867720, -0.817800, -0.650530, 0.833900, 1.320900, 0.739460, 0.844940, 
0.135030, 0.157510, -0.042900, -1.065230, -0.448170, 0.511650, -0.651240, 0.290210, 0.290230, -0.484760, 
-0.438470, -0.384200, 0.629940, -0.964360, 0.750190, 0.034940, -0.265330, -0.113860, -0.014940, 0.369510, 
0.460010, -0.827230, 0.898420, 0.085480, -0.086190, -0.780670, 0.615960, -0.520770, -0.958670, 0.538430, 
-0.547540, -0.926740, -1.007410, -0.984770, 0.332520, 0.572970, 0.485590, 0.502240, 0.282210, 
-0.047800, 1.336590, 0.586620, 0.367080, 0.751130, 0.370560, 0.711140, -0.471910, 0.014900, 0.039180, 
-0.100880, -1.073570, -1.238740, 0.218160, -0.808240, 0.977740, -1.101700, 0.113600, 0.881560, 0.017660, 
-0.399440, 0.035360, 0.684830, 0.815200, 0.191430, 0.230400, 0.267430, -0.460610, -0.481840, 0.916860, 
0.508390, 0.258150, -0.356180, -0.468310, 0.592410, -0.461970, 0.232760, 0.030050, -0.043100, -0.782100, 
-0.116440, -0.809570, -1.285380, 0.634040, -0.409070, -0.414470, 1.377500, 1.148900, 0.781040, -0.323150, 
-0.093740, -0.756730, -0.076290, 1.319040, -0.381110, -0.414790, -0.141350, 0.086790, 0.827190, 0.847220, 
0.912990, -0.248650, 0.054130, 0.068810, -1.121220, -0.394560, -0.763830, -0.779290, 0.047480, -1.147750, 
0.264720, 0.111580, -0.259260, 0.244890, 0.653240, 0.746190, 0.490600, -0.394800, 0.588790, -0.529540, 
1.240640, 1.051270, 0.242990, -0.089170, 0.591220, -0.238800, 0.114530, -0.806720, 0.395260, 0.171050, 
-0.542320, -0.793520, -0.120300, -0.537730, -0.634740, 0.501340, 0.503880, -0.214180, -0.965860, 0.589760, 
-0.108660, -1.042250, 0.492160, -1.020770, -0.846700, 0.789070, 0.566730, -0.018050, 0.741090, 0.426000, 
-0.198140, 0.503310, 0.098460, -0.465060, 0.132370, -0.145850, 1.062230, 0.780430, 0.493120, -0.564880, 
1.307380, 0.941630, 0.132400, 0.082810, 0.198610, -0.345400, -0.556820, 0.217450, -0.185930, 0.173250, 
0.831320, 0.448670, 0.097860, -0.402470, 0.626250, 0.851700, 0.717130, -0.347380, -0.898030, -0.997790, 
-0.429990, -1.013430, -1.349210, -0.053260, -0.512810, -0.715900, -0.203600, 0.263720, 0.924140, -0.389400, 
-0.355870, 0.672240, -0.532270, 0.426720, 0.297800, 0.108450, 0.869330, 0.317300, -0.332730, -0.853220, 
-0.528860, 0.124980, 0.673210, -0.732600, -0.214420, -0.423370, -0.468680, 1.000600, -0.254350, 0.115430, 
-0.952490, 0.203840, 0.218670, 0.690530, 0.495700, 0.625790, -0.002940, 0.470650, -0.120160, 0.173570, 
1.116370, 0.121190, -0.779850, -0.852180, 0.591770, 0.882570, -0.898930, -0.744720, -0.686840, 0.491350, 
0.162530, 0.230920, 0.219570, -0.391140, -0.528200, -1.039810, 0.065820, -0.405050, -0.238440, -0.394250, 
-0.087590, -0.836000, -0.695560, -0.126500, -0.794090, -0.705310, -1.056060, 0.626490, 0.228530, -0.036900, 
0.418110, 0.634850, -0.284960, -0.229620, -0.020370, 0.509960, 0.113470, -0.526120, -0.957470, -0.267210, 
0.256350, -0.695010, -0.556610, -0.350810, 0.062000, -0.711040, -0.464670, -0.364220, 0.263930, 0.236900, 
0.583370, 0.266920, 0.769700, 0.275780, -0.755330, -0.497670, 0.732340, 0.132410, -0.461250, 0.647350, 
-0.046760, -1.068290, 0.028270, 1.112680, -0.115720, 0.201260, -0.605910, -0.428330, -0.433520, -0.567760, 
-0.111260, -0.176340, -0.540540, 0.252530, -1.101380, -0.123590, 0.045770, 0.035480, -0.359590, 0.900210, 
0.038930, 0.768830, 0.135980, -0.593830, -0.493780, -0.063380, 0.313650, 0.337580, -0.175920, 0.233960, 
-0.148670, 1.214010, -0.377870, 0.689100, 1.029490, 0.504230, -0.874380, 0.122140, 1.035650, -0.418830, 
-0.417580, 0.164530, 0.484700, -0.788550, -0.869390, 0.336180, 0.832700, 0.584410, -0.366150, 0.293760, 
-0.467170, -0.689990, 0.264250, 0.390290, 0.321550, -0.861240, 1.183190, -0.239840, -0.821310, 
-0.894650, -0.135510, -0.390100, 0.728960, -0.121010, -0.327400, -0.523160, 0.057610, -0.268180, 0.162620, 
0.143480, 0.887980, -0.484040, 0.788570, 0.985340, 0.503390, 1.077060, -0.873800, 0.394350, -0.732050, 
0.953620, 0.237410, 0.344090, 1.258170, -0.123740, 0.576580, -0.515230, 0.025730, -0.072520, 0.040570, 
0.666410, 1.035090, 0.002020, -0.134690, 0.787680, 0.720160, -0.662220, 0.810400, -0.233520, -0.517260, 
-1.012870, -0.382530, 0.471090, 0.417880, 0.462860, -0.268920, 0.230700, -0.149390, 1.153200, 0.898410, 
0.663690, 0.134590, 0.010580, 1.651090, 0.646660, -0.507990, -0.391250, 0.046380, 0.060960, 0.673660, 
0.013640, 0.065940, 0.090920, 0.034730, 0.391250, 0.398720, -1.013180, 0.457170, 0.621530, 0.603190, 
0.551090, 0.858610, -0.916820, -0.490880, 0.609590, -0.607740, 0.035170, -0.949180, -0.402240, -0.612300, 
0.290310, 0.889360, 0.440250, -0.418010, -0.095720, -0.943330, -0.382350, -0.935510, -0.571910, 0.511300, 
-1.045060, 0.727470, -0.900870, 0.162480, -0.086060, 0.753750, -0.905640, 0.271490, -0.070740, -0.707590, 
-0.381270, 0.435200, 0.897120, 0.025680, -0.212420, 0.603980, -0.502570, -0.044110, -0.373160, -0.180160, 
0.077860, -0.116950, 0.392670, -1.000950, -0.907410, -0.463570, -0.871400, -0.563260, -0.294670, 1.917710, 
0.332900, -0.315050, -0.596060, 0.553100, 0.241020, 0.697400, -0.014050, 0.487500, 0.097720, 1.047160, 
0.832630, -0.761540, 1.490730, 0.337420, 0.317560, -0.176360, 0.235590, -0.218000, -0.384430, -0.113300, 
0.109070, 0.275910, -0.191330, -0.980580, -0.614310, -0.229910, -0.772930, -0.638250, 0.081030, 0.918950, 
0.674810, -0.638950, -0.899230, -0.400200, 0.106230, -0.335390, -0.240780, 0.992840, -0.207850, 0.492080, 
-0.770890, -1.031960, 0.616790, 0.145080, 0.372630, 0.219090, 0.590030, -0.503540, -0.812280, 0.440470, 
-0.047370, -0.496360, 0.757520, -0.421800, -0.445900, 0.814490, 0.318290, 0.835850, -0.329890, -0.300800, 
0.087880, -0.018970, 1.019230, -0.230640, 0.316780, -0.182930, -0.663500, 0.774610, 0.484810, 0.171800, 
0.712450, 0.313510, -0.497250, -1.070320, 1.074880, -0.073990, -0.923120, -0.557080, -0.370900, 0.567070, 
-0.130260, 0.832490, -0.470470, -0.129290, -0.461180, 0.857040, -0.359280, -0.554160, -0.375980, -0.166310, 
-0.962130, -0.864530, 0.139150, 0.704040, -0.089780, -0.041790, -0.424340, 0.879420, 0.799710, 0.061050, 
-0.136940, -0.030510, 0.547590, 0.413570, 0.477930, -0.824380, 0.006830, 0.065400, -0.180420, 0.498610, 
-0.304980, -0.634680, -0.156100, 0.654810, -0.821640, -0.241270, 0.814180, -0.674850, -0.452400, 0.032760, 
-0.600140, -0.347560, 0.977300, -0.986020, -0.540450, -0.582860, -0.410590, -0.031710, -0.586130, 1.194410, 
-0.443590, -0.104090, -0.397950, 0.208030, 0.454640, 0.436060, 0.568170, -0.029710, 0.006860, 0.763320, 
-0.290100, -0.546230, 1.064130, 0.161800, 0.612170, 0.299950, -0.378790, 0.525840, -0.392790, 0.544020, 
-0.405460, 0.062700, 0.256250, -0.784580, 0.966140, 1.097220, 0.808050, -1.115410, 0.411250, -0.263530, 
-0.408790, 0.400360, 1.000570, 0.257080, -0.793420, 0.771590, -1.008500, 0.738920, 0.197020, 0.600020, 
0.610690, 0.591620, 0.164800, 0.252810, -0.301090, 0.402800, -0.149700, 0.800200, -0.194740, 
0.227020, -0.054880, 0.585350, -1.299590, -0.233270, -0.151100, -0.564050, -0.323360, -0.082180, 0.327380, 
0.610340, -0.287030, -0.345560, -0.553470, -0.059170, -0.728870, -0.905710, -0.939040, -0.669700, 0.920320, 
0.187340, 0.226540, -0.556110, 0.296680, -0.342170, -0.190600, 0.337240, 0.819540, -0.648790, -0.791870, 
-0.521100, -0.255930, 0.047810, 0.896680, -0.457190, 0.267080, -0.936450, 0.061140, -0.189380, -0.799810, 
-0.416110, -0.921900, -0.475830, 0.873710, -0.965800, 0.255790, -0.687830, 0.066250, 0.870420, 0.336940, 
-0.099100, 0.255110, -0.750750, 0.067340, -0.957190, -1.166280, -0.483320, -0.360380, -0.622830, 0.183260, 
0.392090, 0.575720, 0.612990, 0.933960, -0.846010, 0.035140, -0.650790, -0.516510, 0.093560, 1.099760, 
0.582160, 0.217770, -1.334310, 0.329100, 1.129420, -0.489080, -0.282220, 0.430100, -1.284210, 0.694850, 
-0.288990, -0.273320, 0.069200, -0.245410, 0.054450, 0.368540, -0.495560, -0.298440, -0.628470, 0.137190, 
1.285240, 0.016430, -0.231920, 0.060470, 0.682000, 0.431820, -0.635330, 0.332370, 0.029410, 0.797400, 
0.613990, -0.681050, 0.943410, 0.126760, -0.024400, 0.763200, -0.299140, 1.329250, -0.612970, -0.155370, 
-0.859710, 0.084330, -0.637090, -1.435870, -1.212340, -0.230920, 1.050780, 1.046200, 0.739090, 0.216920, 
0.498470, -0.760080, -1.223510, 0.654640, 1.213240, -0.247280, -0.824860, -0.583740, 1.394960, 0.837920, 
-0.733560, 0.397230, 2.404180, -0.926460, 0.129250, 3.330100, 1.252320, 0.197590, 0.133460, -0.611120, 
0.270680, 0.289680, 0.093500, 0.165450, -0.777740, -0.111090, 0.053610, -0.298710, 0.680720, -0.893840, 
0.085890, -0.840960, -0.575450, 0.646450, 0.865420, -0.531380, 0.040960, 0.372150, 0.005100, -0.082830, 
-1.245660, -0.175100, 0.063720, -0.116380, -0.774780, -0.189010, 0.665180, 0.584270, 0.304380, 0.511610, 
-0.588600, 1.276130, -0.070170, -0.543060, -0.041900, 0.026960, 0.294360, -0.889060, -0.246610, 0.113030, 
0.007380, 0.119800, 0.819330, 0.126160, -0.481400, 0.473080, -0.183960, -0.292370, -0.153600, 0.113750, 
-0.102510, -0.223530, -0.968030, -0.185160, 0.193820, -0.214930, -0.077290, 0.008510, -1.036890, 0.776960, 
-0.302660, -0.857630, -0.018840, 0.784090, 0.669060, -0.469220, -0.879340, -0.072700, 0.587380, 0.871150, 
-0.119520, -0.422250, -0.117750, -0.307890, 0.326000, 0.611740, -0.814030, -0.143680, 1.088010, -0.631930, 
0.226650, -0.075290, 0.170640, -0.330790, -0.432310, -0.313440, -0.500320, -0.727460, -0.577160, 0.874380, 
-0.283420, 0.849920, 0.409700, 0.300270, -1.017840, -0.794850, 0.463760, -0.202770, 0.490340, -1.027810, 
0.184000, 0.305320, -0.195840, -0.021080, -0.753890, -0.363150, -0.526640, 0.441790, -1.023640, -0.123660, 
-1.146740, 0.678070, 0.627620, 0.244680, -0.259990, -0.640100, 0.312940, 0.190810, 0.712470, -1.026270, 
-1.321280, -0.800240, -0.626340, 0.076030, 0.160900, -1.076700, 0.791430, 0.036740, -0.322410, 0.178580, 
-0.652990, 0.385130, -0.359350, -1.048410, -0.284420, -0.686750, -0.201030, -1.049860, -0.203840, -0.088840, 
-0.095460, -0.296300, -0.240260, 0.833620, 0.470950, 0.922920, -0.621340, 0.790120, 0.056520, -0.334060, 
0.439160, 0.109810, 0.185060, 0.000290, -0.460240, -0.361890, -0.310900, -0.131120, 0.230800, 
0.322860, 0.166420, -0.349540, 0.025720, 0.561400, -0.475330, -0.162180, -0.757090, 0.826610, 0.095660, 
1.328860, 0.243640, 0.018630, 0.075230, -0.207340, 0.456880, -0.346070, -0.159990, 0.723510, -0.567780, 
-0.026840, 0.352730, 0.532130, 0.847250, 0.138500, 0.659470, 0.018500, -0.588500, 1.244260, 0.303510, 
-0.084670, -0.870160, 0.150050, 0.573670, 0.013080, 0.696010, 0.629540, -0.205480, -0.776790, 0.421110, 
-0.059090, -0.043070, 0.773400, -0.671870, -0.190740, -0.231100, -0.185360, 0.051040, -0.684180, -0.680020, 
-0.239000, -0.091050, -0.199190, 0.047110, -0.075210, 0.440570, 1.025700, -0.038350, -0.699780, -0.500290, 
-0.125660, -0.258820, -1.071630, -0.475010, 0.395510, 0.323740, 0.269910, -0.410990, 0.548990, 0.591470, 
-0.507750, -0.168050, 0.587210, -0.172200, 1.657420, 0.020480, 0.445130, -1.454320, -0.163570, -0.019630, 
-0.126080, 0.470000, -0.416760, -1.177350, 0.270360, 0.481060, -0.415680, -0.369980, -0.686750, 0.306660, 
0.096020, -0.579880, -0.762220, -0.764210, 0.042560, 0.812290, 0.283820, 0.159270, 0.302700, 0.714840, 
-0.227100, -1.049110, 0.400270, -0.599350, -0.090960, -0.277620, -0.250970, 0.034790, -0.372710, 1.406680, 
0.300940, -0.289400, 0.869620, -1.646980, -0.205220, 1.434670, 0.591610, 0.463200, -1.105030, -0.326130, 
0.673520, -0.967170, 0.255270, 0.796920, 0.773170, -0.206770, -0.625410, -0.768700, 1.634400, 0.616850, 
0.493890, -0.910270, 1.516200, -1.106630, 0.719440, 2.279490, 0.189240, 0.071110, -0.186560, -0.759800, 
0.314650, -0.647520, 0.601050, 0.492370, 0.529140, -0.207750, 0.484790, 0.281730, -0.423130, 0.677700, 
-0.624840, 0.442230, 0.335350, -0.307930, 0.288290, 0.714420, -0.099510, 0.186850, -0.386940, -0.412200, 
0.411990, -0.962200, 0.063280, 0.965630, -1.017890, -1.790620, 0.534160, -0.673450, 0.956090, 1.085260, 
0.320990, -0.390120, 0.423140, -0.361890, 0.248850, 0.456310, -0.375150, -0.025070, 0.168020, -0.117330, 
-1.100080, -0.345360, 0.494590, -0.030650, 1.166450, 0.266490, 1.500050, -0.623580, 0.905070, -0.388900, 
-0.547760, -1.128860, 0.692050, 0.673350, -0.739260, -0.369130, -0.148970, 0.558650, -1.129430, 0.861480, 
-0.406120, 1.582930, -0.019560, 0.446810, 0.146390, -0.096680, 0.786310, -0.774080, 0.170250, 0.035980, 
-0.688470, 0.535220, 0.688340, -0.038320, 0.265310, -0.004300, -0.127260, 0.118870, 0.022920, 0.254130, 
-0.415970, 0.552420, -0.433230, 0.178500, 0.963880, -0.372140, 0.351180, 0.026240, 0.138700, -0.859800, 
0.099380, 0.853750, 0.191730, -0.006270, 0.340330, -0.876830, -0.927580, 0.728460, 0.074760, 0.260970, 
0.528450, -0.173550, -0.246980, 0.689080, 0.295860, -0.761770, 0.528590, -0.328680, 0.480210, -1.421260, 
-1.330240, -0.682510, -0.391790, -0.730810, -0.218730, 0.016810, 0.651040, 1.012360, 0.507620, 0.162390, 
-0.493540, 0.098750, -1.811630, -1.097590, 0.741990, 0.481270, -0.036900, -0.009900, 0.348100, -0.161870, 
-0.166800, 0.129210, -0.778110, 0.387950, 0.678980, 0.339440, -0.373630, 0.550000, -0.212320, 0.371210, 
-0.367740, -0.354110, -0.910030, 0.620550, 0.337880, 0.305360, -0.232090, 0.093840, 0.737530, -0.496520, 
-0.974030, 0.351460, -0.445370, 0.778390, -0.988600, -0.947810, -0.166770, -0.180060, 0.121260, 
0.320670, 0.080440, 0.120490, -0.421680, 0.540210, -0.490800, 0.657750, 0.248880, 0.857130, -0.413460, 
-0.836410, 0.986430, -0.409040, 1.016550, -0.749680, -0.327000, -0.471710, -0.262210, 0.513740, -0.735020, 
-0.542100, -0.189470, -0.002250, -0.261910, 0.719040, 1.234010, -0.066750, 0.476760, -0.318170, -0.906960, 
-0.902440, -0.339520, -0.352620, 0.825640, 0.143130, 0.881320, -0.125790, 0.354000, 0.645230, -0.637910, 
-1.199570, -0.054610, 0.174270, 0.315320, 0.627700, -0.294070, 0.209000, 0.543430, -0.360680, 0.810140, 
-0.192430, 0.420680, -0.136200, 0.159670, -0.334490, -0.146430, -0.124860, -0.606970, 0.948650, -0.178140, 
-0.413170, -0.307740, 1.409000, -0.069620, -0.737630, 0.313910, -0.003820, -0.618790, -0.074480, 0.936220, 
-1.111010, -0.768840, -0.086520, 0.254660, 0.953750, -0.510350, 0.760820, -0.832310, -0.722180, -0.112890, 
-0.478540, -0.203160, 0.097690, 0.479720, -0.199520, 0.261150, -1.066330, 0.006340, 0.548710, -0.481230, 
0.358500, -0.808930, 0.134020, 0.469050, -1.113370, -0.349650, 0.269050, 0.716310, 0.159870, 0.180400, 
0.058190, -0.218600, 0.773030, 0.614870, 0.159390, 1.324510, -0.295810, 0.406290, -0.576150, -0.367760, 
0.993880, 0.418880, -0.428070, 0.458900, 0.458160, -0.448780, -0.593590, 0.505270, -0.604760, -0.539560, 
-1.730300, 0.213150, 0.272360, -1.105220, -1.367750, 0.594870, 1.252830, -0.838390, -0.646810, -0.685030, 
-0.165900, -0.954070, -1.586460, -0.410820, 0.335290, -0.906400, -0.837150, 1.418170, -0.655510, 2.021340, 
-0.245990, 0.162630, -0.300050, 0.211640, 0.480090, 0.007550, -0.825230, 0.147490, 0.905280, -0.553770, 
-0.933020, -0.708000, -0.080340, -0.078950, 0.150450, -0.726600, -1.542440, 0.153610, 0.002070, -0.878000, 
-0.115140, -0.384120, -0.610330, -1.012220, -0.291490, -0.719200, 0.094370, 0.702350, -0.193070, 0.675400, 
-0.523590, -0.275420, -0.265510, -0.410290, 0.564490, 0.241090, 0.881720, 0.887960, -1.013660, -0.544140, 
-0.576180, 0.541930, 0.784290, -0.792430, -0.662460, 0.270750, 0.330680, -0.745790, 0.504080, 0.812390, 
-0.100440, -0.507320, 0.579610, -0.361150, -0.617870, -0.626160, 0.399660, 0.292430, 0.091640, 0.285320, 
0.374110, -1.348440, 0.950080, -0.498220, 0.722180, 1.203970, 0.007520, -0.139710, 0.648800, 0.515570, 
0.256690, -0.311800, 0.094130, 0.545660, 1.034300, 0.364910, -0.221540, 0.125700, 0.610030, 0.746210, 
0.095320, 0.955650, 0.147960, 0.906850, 0.557790, -0.660410, 0.112380, 0.278350, -0.843010, 0.832740, 
0.432180, 1.209240, -0.268040, -0.344740, 1.157670, -0.540970, -0.773810, 0.273170, 0.246620, -0.830280, 
0.773100, -0.183090, 0.522250, 1.037730, -0.308810, -0.456640, 0.885360, 0.561600, -0.110010, -0.525430, 
0.450350, 0.854990, -0.105050, 0.106760, -0.113450, -0.603030, -0.307590, -0.502960, -0.538900, 1.814790, 
-0.584480, -0.616740, 1.382720, 0.296120, 0.102190, 1.264330, 0.161340, 0.681310, 0.477230, -0.546090, 
-0.434150, -0.678850, 0.310330, 0.340970, -0.229670, 0.239030, -0.355880, 0.241240, 0.848290, -0.416710, 
-0.365140, 0.029100, 0.401800, 0.799580, -1.012040, 0.284740, 0.651460, -0.982980, -0.588470, 0.594760, 
1.022750, -0.233770, -0.325170, -0.494320, 0.185260, 0.508800, 0.561870, -1.295650, 0.449130, 
0.087680, 0.550200, -0.324200, -0.155770, 0.131120, -0.400370, -0.992230, -0.486960, -0.775490, 0.147410, 
0.583990, -0.768410, -0.429580, -0.883560, 1.153780, -0.344680, 0.047120, 0.310890, -0.261340, 0.237870, 
2.093510, 0.137580, 0.984730, 0.323900, -0.405920, 0.710310, -0.470090, -0.535340, -0.056690, 0.805870, 
0.634640, -0.570410, -0.691120, 0.240780, -0.501530, -0.245410, 0.014130, -0.017630, 0.177740, 0.843490, 
-1.066910, -0.419470, -0.793900, -0.223560, -0.317680, 0.904030, -0.943800, -0.050960, 0.436800, -1.042910, 
-0.234880, -1.387240, -0.020040, -0.595700, -0.309070, 0.018750, -0.215810, 0.574640, -0.761640, 0.857890, 
-0.317170, 0.371530, -0.342630, 0.435770, 0.055790, -0.348180, 1.779510, 0.757740, 0.265140, -1.429120, 
-0.212290, 0.762200, -0.117270, -0.458050, 0.099090, -0.351470, 0.542490, 0.021220, -0.323230, 0.325130, 
-0.304500, -0.092940, -0.341200, 0.897560, 0.944410, 0.430750, 0.198220, -0.225940, 0.431580, -0.695190, 
-0.380480, -0.561810, -0.014720, 0.020820, 0.689010, -0.246540, 0.045780, 0.277370, -0.304170, -0.278480, 
-0.802300, 0.033970, 0.816920, -0.908090, -0.268000, -0.115480, -0.714800, -0.154190, -0.419570, -0.542080, 
-0.789300, 0.086910, 0.054090, 0.624000, 0.607180, -1.342710, -1.751170, -0.697050, 0.683640, -1.664140, 
-0.625010, 0.502580, 0.081730, -0.789950, -2.375370, 0.017820, 0.295550, 0.464920, -0.775260, -0.193220, 
1.577440, 0.160600, -1.923290, 0.540600, 0.404230, -1.738210, -0.512860, 1.384670, 0.248110, 1.291710, 
-0.435760, -0.080240, -0.023900, -0.432510, 0.019990, 0.181460, 0.508830, 0.766330, -0.012070, 0.039560, 
-0.821630, 0.388790, -0.235850, -0.084160, 0.449540, 0.097000, -0.281840, 0.046270, -0.156140, 0.627030, 
0.566960, -0.130620, -0.901500, -0.262580, 0.169630, -0.409910, 0.000400, 0.269110, 0.284540, 0.108500, 
0.048540, 0.075070, -0.145090, -0.038260, -0.346410, -0.084800, 0.160510, -0.262470, -0.626730, -0.631830, 
-0.166500, 0.531890, -0.489790, 0.618470, -0.434380, 0.349560, 0.258660, 0.304670, -1.028960, -0.353300, 
0.148050, -0.061010, -0.054120, -0.079120, 0.536680, 0.263180, -0.047030, 0.470090, -0.051850, -1.024700, 
-0.842830, 0.290200, 0.421580, 0.008840, 0.756630, 0.297410, -0.265120, 0.688910, 0.573580, 0.928700, 
-0.570040, 0.143490, 0.911380, 0.362700, -0.836100, 0.292410, 0.068790, -0.522990, -0.347750, -0.350220, 
-0.377120, -0.625890, -0.605300, -0.038830, -0.741150, 0.810440, 0.108310, 0.764820, 0.455060, 0.682830, 
1.073530, 0.377710, 0.304150, -0.138830, -0.305430, -1.239830, 0.163380, 0.366730, -0.387650, -0.251770, 
0.332600, -0.372810, -0.153430, -0.259500, -0.111740, -0.244070, 0.346700, -0.739940, -0.243270, 0.545870, 
0.746200, 0.239220, -0.670150, 1.003770, -0.094150, -0.209660, -0.057550, -0.021610, 0.300730, 0.964450, 
0.089190, -0.262130, 2.003680, 0.365780, -0.213460, 0.422240, -0.263710, 0.617370, -0.423230, -0.293510, 
0.584070, 0.489120, 0.095610, -0.434850, 0.633700, -0.768940, -0.948560, 0.051640, -0.612530, 1.244320, 
-0.106350, -0.883560, 0.677660, -0.742320, 1.513270, 0.882760, -0.751050, -0.408040, 0.413500, -0.744030, 
0.123490, -0.592430, -0.200000, 0.175480, -0.262490, 0.249410, 0.266400, 0.374810, 0.518540, 
0.205240, -0.455190, 0.639010, -0.628030, -0.053730, -0.252020, 0.581230, -0.001710, -0.479190, 0.524500, 
0.729290, 0.808510, -0.347280, 0.420010, -0.320520, 0.824160, 0.001030, 0.538200, -0.158250, 0.923370, 
1.594700, 0.826600, -0.841760, 1.197760, 0.362530, -0.244320, 0.004880, -0.080340, 0.198950, 0.240690, 
0.361050, 0.140050, -0.775120, -0.450630, -0.714310, 0.416680, 0.572090, -0.202900, -0.494000, -0.160260, 
-1.232570, 0.679640, -0.413960, 0.305150, -0.345960, 0.838220, 0.720960, 0.128880, -1.310370, -0.229150, 
-0.692600, 0.038290, -0.223920, 0.299710, 0.479730, 1.037580, 0.814650, -1.226790, 0.857750, -0.140640, 
0.449790, -0.294910, 0.624280, 0.592760, -0.139850, -0.438890, 0.347110, 0.367640, 1.001800, 0.128380, 
0.086630, 0.047100, 0.290250, 0.290970, -0.592310, 0.398040, -0.191630, 0.095510, -0.226660, -0.386440, 
0.243550, -0.017510, 0.045950, 0.223500, -0.550670, -0.386180, -0.308090, 0.237490, 0.778160, 0.932380, 
-0.265990, -0.080640, -0.195560, -0.956330, 0.050700, 0.449130, -0.254690, -0.191080, -0.490640, 0.168090, 
0.346670, -0.640220, 0.622570, -0.355790, 0.750090, 0.481040, -0.163960, -0.281440, 0.545110, 0.152560, 
0.366950, -0.774260, 0.357040, 0.046110, -0.341990, -0.155450, -1.020010, -0.466490, 0.155710, -1.531050, 
-0.785930, 1.204510, -0.461510, -1.624770, -0.636840, 1.127440, -0.356040, 0.252620, 1.096620, -0.440270, 
-0.506500, -0.838090, -1.390170, -1.188630, 0.334910, -1.519610, -0.164220, -0.607980, 0.204550, -0.770600, 
-0.482110, -0.269680, 1.014350, 0.264470, 0.666240, 0.881990, -0.300720, 0.730040, 0.760980, 0.535350, 
0.703600, 0.201900, 0.159320, -1.280260, 0.100140, -0.463150, -0.238190, -0.336150, -0.768320, 0.435820, 
0.126940, -0.646320, 0.346010, -0.405110, 1.304770, 0.664950, 0.246210, 0.990310, 0.083110, 0.594120, 
0.057230, -0.047850, 1.280030, -0.099070, -1.076840, -0.615290, 0.213760, 0.853250, 0.386590, -0.632500, 
-0.183650, 0.755160, 1.035790, 1.423230, 0.317300, 0.010400, -0.957950, -0.363760, 0.469530, 0.606790, 
-0.612030, 0.342500, -0.294580, 0.143370, -0.169710, 0.013400, 1.122290, -1.077520, 0.032080, -0.623400, 
1.054270, -1.276520, 0.394990, 0.098970, -0.793780, -0.677730, 1.220410, -0.817160, 0.454150, -0.341210, 
0.145570, -0.402060, -0.794980, 0.726960, -0.043130, 0.320670, -0.453510, 0.547740, -0.518460, 0.279150, 
-0.172780, -0.531230, 0.025570, -0.729210, -0.866580, 0.670230, 0.549580, -0.838520, 0.097410, -0.041260, 
-0.758320, 0.413450, 0.293760, -0.421490, 0.799620, -0.262570, 0.791300, 0.330230, -0.603880, 0.494340, 
-0.525030, -0.429690, 0.547210, 0.443060, 0.226510, -0.117590, 0.077780, -0.595730, -0.229420, -0.738050, 
-0.262890, 0.702710, 0.068410, 0.607340, 0.198290, 0.573290, 1.055630, 0.099350, 0.410160, 0.858930, 
0.314490, 0.024800, 0.305590, 0.233920, 0.760430, -0.211770, 0.394830, -0.036100, -0.057100, 0.976930, 
-0.144160, 0.849310, -0.606110, -0.316790, 0.445910, 0.142880, -0.489980, -0.364530, -0.236320, 0.445300, 
-0.038590, -0.834980, -0.649890, -0.974130, -0.024140, -0.927580, -0.563900, -0.761600, -0.089120, -0.079840, 
-0.647050, -0.473520, -1.102200, 0.198240, -0.415320, 1.322480, 0.452250, 0.802840, 0.087370, 
-0.095970, 1.068530, 0.336390, -0.351480, 0.042450, 0.695090, -0.735970, -0.091520, -1.097430, -0.461470, 
0.237330, 0.483930, -1.059240, 0.150280, 0.282040, -0.640130, -0.114410, 0.690870, -0.292190, 0.695520, 
-0.539110, -0.181480, 0.096270, -0.567630, -0.845330, -0.347310, -1.247690, 0.544200, -0.019650, 0.122840, 
-0.665080, 0.444110, 0.713340, -0.821470, -0.785500, 0.429780, -0.196550, -0.148250, -0.750060, -0.963540, 
-0.465500, -1.030710, 0.594430, 0.567200, -0.077150, -0.011150, -0.037480, -0.509450, -0.086010, 0.045090, 
0.381200, -0.249180, 0.274160, -0.081230, -0.390010, -0.965100, -0.514690, -0.708800, 0.405950, 0.757890, 

-0.715620, -0.099570, -0.207320, -0.191660, 0.512750, 0.248720, -0.011390, -0.725100, -0.047200, -0.491360, 
0.221300, 0.131550, -0.567430, 0.241230, -0.210440, -0.846430, -0.216410, -0.545000, 0.235400, 0.270400, 
-0.460990, -0.295520, 0.686460, -0.146910, -0.272750, -0.260800, -0.117580, -0.363090, 0.576600, -1.002770, 
0.028210, -0.225750, -0.192390, 0.749540, -1.115620, -0.157390, 0.403090, 0.205680, 0.559180, -0.850020, 
0.082150, 0.446810, -0.328200, 0.259860, -0.445860, -1.062550, -0.443430, 0.754110, -1.001600, 0.188040, 
0.979580, -0.505140, -1.238210, -0.714160, -0.785460, -0.754020, -0.574410, 0.195390, 0.093910, 0.695620, 

-0.213310, -0.842110, 0.408270, -1.019660, -0.604790, 0.394250, -0.232700, -1.146830, -0.483400, -1.238520, 
-0.603720, 0.059230, 0.086500, 0.393720, 0.792490, -0.234730, 0.696260, -1.261320, -0.141340, -0.828730, 
-0.009000, -0.163290, -0.929900, -0.385390, 0.529770, -1.565160, 0.885680, -1.274410, 0.182510, 0.651970, 
0.577340, 0.684910, 0.859670, -0.613710, 0.373560, 0.243050, -0.260220, 0.607250, 0.892180, -0.310160, 
0.744520, 0.729600, -0.020110, -0.592890, 0.207820, -0.457970, -0.012880, -0.458310, 0.169180, -0.538380, 
-0.329180, 0.775160, -0.794530, 0.664680, -0.879340, 0.949860, -0.645120, -0.721020, -0.728560, 0.495190, 

-0.978080, 1.283970, -1.516760, -0.686110, 0.465050, -0.532580, -0.363260, -0.813110, 0.189000, 0.480180, 
-0.497950, -0.923140, -1.260570, -1.172750, 0.411010, -0.367530, -1.490350, -0.591780, -1.020570, -1.112200, 
-0.338410, 0.572860, -0.195930, -0.216560, -0.199610, 0.172990, -0.418690, -0.080780, -0.530140, 1.607880, 
-0.345380, -0.718830, -0.266940, 0.460380, -0.091860, 0.113580, 0.228280, 0.068300, 0.317990, 0.355380, 
-0.960050, 0.136870, -0.996520, 0.395770, 0.234650, -0.111700, -0.923120, 0.654720, -0.483820, -0.756100, 
-0.049790, 0.658200, 0.037870, 0.021790, -0.769070, 0.088060, 0.062100, 0.562900, 0.603290, 0.426560, 

-0.236950, -0.518120, -0.956740, -0.822950, 1.109040, -0.112970, -1.041650, 0.322720, -0.220190, 0.705290, 
0.882220, 0.911210, 0.257320, -0.339080, -0.446470, 0.792860, -0.379820, -1.013640, -0.688360, -0.000940, 
0.845750, 0.235570, -0.944060, -0.416560, -0.888890, -0.854870, -0.284240, 0.130190, 0.434680, -0.098030, 
-0.286820, 0.548670, -1.032440, 0.557130, 1.088740, 0.066840, 0.027270, 0.067030, -0.233170, 0.636050, 
0.294320, -0.606440, -0.864450, -0.018590, 0.555550, 0.681020, -1.160140, 0.848200, 0.202130, 0.128800, 
0.027950, 0.536700, -1.174040, -1.809420, -0.680320, -1.076660, 0.013260, -0.407650, -0.505810, 0.194460, 

-0.264250, -1.216170, -0.342420, -0.266730, 0.149010, -0.865880, -0.096830, -1.036810, 0.537310, -1.751370, 
-0.552050, -1.105210, -0.780060, -0.074560, -0.012430, -1.377940, 0.959340, 0.729680, 0.010960, -0.305010, 
-0.557110, -1.076930, 0.234560, 0.518540, 0.340970, 1.457740, 0.660270, -0.874800, -0.941080, 0.841030, 
-0.281710, -0.264960, 0.381790, 1.446440, 0.066380, -0.548390, 0.046080, -0.321470, -0.503680, 0.413410, 
0.754470, -0.023910, 0.191220, 0.027910, -0.012180, -0.104510, -0.538780, -0.283310, -0.649140, 0.257230, 
-0.473200, -0.164640, -0.277860, -0.816360, 0.320410, -0.775250, -0.140390, -0.199660, 0.732520, -0.467280, 

-1.032750, -0.076210, -0.854600, -0.921760, -1.397850, 0.684820, -2.070320, 0.739300, 0.322800, -0.696280, 
-0.245050, -0.292720, -0.090750, 1.672900, 1.270190, -0.660570, -0.159140, -1.214200, -0.479180, 1.468530, 
-0.185590, 0.425490, 0.757730, -1.242410, 0.582860, 0.482290, 0.066210, -0.047340, 0.407060, -0.256740, 
-0.724340, 0.419610, -0.803100, 0.609190, 0.092350, -0.120610, -0.409740, -0.281800, -0.595910, -0.054640, 
0.802400, -0.167840, -0.863630, -0.431710, 0.397170, -0.337860, -1.144150, 0.918970, -0.213540, 0.354350, 
0.139220, -0.373100, 0.089590, -0.317240, -0.193960, -0.392240, -1.024000, -0.080920, -0.261930, -0.008120, 

0.047260, -1.533860, -0.016670, -1.507810, -0.242500, -0.994960, -1.317670, 0.014440, 0.867250, -0.943900, 
-0.090970, -0.030220, 1.193120, -0.750520, 0.732230, 0.031480, 0.719840, -0.226810, 0.237610, -0.179880, 
1.072390, 0.527860, 0.150890, -0.867060, -1.055290, -0.848980, -0.380650, 0.327880, -0.570240, 1.365900, 
0.896390, -0.319680, 0.300980, -0.324190, -0.086300, 0.473400, -0.185880, -0.546030, -0.234200, -0.368660, 
0.982660, 0.291000, -0.621260, -0.719340, -0.391230, -0.481460, 0.978240, 0.997400, 0.139740, -0.591900, 
0.676680, -0.271760, 0.008810, 0.646840, -0.056360, -1.122920, -0.889810, -0.284420, -0.197240, 0.369390, 

-0.450530, 0.884050, -0.368130, -0.199540, -1.073070, -0.341530, -0.350940, 1.290730, 0.214360, -0.130740, 
0.113460, 0.012840, 0.933990, -0.580950, 0.418650, 0.128630, -0.740000, -1.524210, 0.019550, 0.448070, 
-0.464100, -0.233160, 1.225630, -0.340100, 0.590950, -0.765190, -0.969060, -0.111880, -0.359690, 0.366790, 
-0.603480, 0.370710, -1.050020, -0.878180, -0.198840, -0.733180, -0.662910, -0.373020, 0.576720, 0.713200, 
0.143530, 0.579140, 0.606020, 0.140450, 0.741580, -0.769300, -0.975580, 0.496120, -0.162440, 0.716260, 
-0.380710, -0.814090, 0.442450, -0.240340, 0.197610, 0.605990, -0.119870, -0.966850, -1.019110, 0.212320, 

-2.573230, 0.576000, -0.750680, -0.418360, 0.388030, -0.126710, -0.607990, -0.748850, -0.597070, -0.482900, 
0.228510, -1.471750, -0.149820, 0.705590, -0.799050, -0.089630, 0.197200, 0.840810, -0.364320, 0.767230, 
0.690920, 0.076420, 0.020620, 1.293190, 1.129480, 0.598640, -0.811520, 0.168060, -0.159790, 1.456430, 
0.473180, 0.241620, -0.910320, 0.864500, -0.773000, 0.585580, -0.547990, -0.817980, 0.035520, -0.268880, 
0.660800, -0.286620, 0.128120, 0.513440, 0.384510, -0.345580, -0.875990, 0.299010, -0.335610, -0.239440, 
-0.448900, 0.190050, -0.211190, -0.431660, -0.874400, -0.254170, -0.529030, -0.291500, -0.519040, -0.384880, 

-0.903930, -0.245500, -0.538490, -0.859060, -1.225850, 0.358270, 0.198280, 0.580670, 0.289410, -0.344640, 
-0.176830, -0.887670, 0.690040, 0.525400, 0.912090, -0.798440, -0.911620, -0.663490, -1.015850, -0.513650, 
-0.812590, 0.166910, 0.144520, -0.711000, -0.883960, -0.453280, -0.768510, -0.801660, -0.917590, -0.329270, 
-0.648710, 0.562900, -0.174320, -0.654980, 0.065090, -0.174580, -0.193820, 0.589330, 0.272310, 0.239060, 
-0.777780, -1.009450, -0.644140, -0.875550, 1.002270, 0.289090, -0.640240, 0.391630, 0.004300, -1.065030, 
-0.556290, -0.394170, -0.877760, 0.100720, -0.650890, -0.699020, 0.618790, 0.448480, 0.649410, 0.969520, 

0.306390, 0.543160, 0.050260, -0.703590, 0.737190, -0.088100, -0.439560, 0.448350, 0.467030, -1.187530, 
0.106130, 0.883290, 0.335560, 0.064460, -0.405770, 0.309810, -0.302500, 0.390970, -0.718100, -0.013870, 
0.983240, -0.169990, 0.595130, -0.641340, -0.527890, -0.521590, -1.030870, 0.706770, -0.896530, -0.658030, 
0.570870, -0.076140, 0.228970, -0.215320, 0.133910, 0.393500, 0.148190, -0.665860, 0.187230, 0.639820, 
-0.214450, -0.725580, 0.883990, 0.411590, -0.486500, -0.107170, 0.543170, -0.055220, 0.205380, 0.217110, 
-0.567550, 0.734990, 0.328960, 0.536100, 0.649250, 0.738300, -1.183780, 0.063330, -0.049130, -0.603470, 

0.404490, -0.203920, 0.272700, -0.718610, 0.408370, 1.050420, -0.539470, -0.299750, -0.328560, -0.587710, 
0.206710, -0.489580, -0.449060, -0.008240, 0.071850, 0.848060, -0.748610, -0.710790, -0.704740, 0.402530, 
0.355500, -0.207740, -0.882350, -0.081650, 0.632670, -0.324750, -1.066430, -0.598930, 1.162030, -0.462190, 
-0.151020, -1.177240, 0.921690, -1.074860, 0.641340, 0.575760, 0.634390, 0.483390, -1.225340, 0.389170, 
0.212470, 0.522730, 0.058030, -1.194620, 0.613550, 0.651910, -1.499930, -0.480250, -1.001220, 0.161120, 
0.606640, -0.377130, 0.207550, -0.729600, 0.802630, 0.993910, -0.378600, 0.824040, -0.839110, -0.502360, 

0.705520, 0.731960, 0.609390, 0.338370, -0.212580, 0.937810, -1.559810, 0.702040, -0.348060, -0.241850, 
0.960730, -0.267970, 0.840840, -0.954140, 0.699880, 0.978320, -1.546670, -0.258190, 0.167760, 0.033650, 
-0.394020, 0.758810, -0.984380, 0.319240, -1.084390, -0.986080, -1.025750, 0.213140, 0.961950, -0.144860, 
-0.393650, -0.611230, -0.379290, 0.027520, -0.246120, 0.476770, -0.549690, -0.256920, 0.559880, -0.401390, 
0.807130, 0.206430, -0.829860, 0.219110, 0.177990, 0.223120, -0.748890, -0.140340, 0.847720, 0.912980, 
0.456170, -0.254860, -0.542670, -1.134080, 0.607130, 0.048840, 0.643390, -0.957260, -1.084450, 0.872790, 

-1.545390, 0.734020, -1.410380, -0.451880, 0.861430, 0.088730, -1.137580, 1.747490, 0.168880, 0.176810, 
0.569210, 0.306620, -0.628050, -0.102810, 1.061610, -0.185140, -0.113430, -0.738990, 0.586910, 0.036210, 
0.420920, 0.379080, -1.631560, -0.506810, -0.110580, -0.082300, -0.044700, 0.976820, 0.221460, 1.223260, 
-0.170300, -0.208080, 0.077670, 0.111780, 0.482360, -0.500150, 0.178190, 0.455070, -0.347900, 0.562130, 
-0.889020, -0.535290, -0.632590, -0.040890, 1.146570, 0.516810, 0.095070, -0.644660, 0.702980, -0.478210, 
-0.727720, 0.068460, -0.922140, 0.155500, -0.308420, -0.391290, -0.507770, -0.045870, -2.097250, -0.086810, 

-0.755110, -0.726030, -0.919860, -0.876300, -0.733190, 0.628300, -0.294000, -0.386390, 0.413070, -0.203140, 
-0.560280, 0.591030, 0.623090, -0.580420, 0.290730, 0.496880, 0.730410, -0.230840, -0.064100, 0.717260, 
-0.763860, -0.169040, -0.827890, -1.092170, -0.092700, -0.428950, -0.897170, -0.267360, -0.434250, -0.649070, 
-0.723370, 0.047980, -0.207070, 0.793470, 0.178830, -0.236970, 0.516970, 0.191740, 1.023220, -0.101740, 
0.415670, 0.437970, 0.083890, -0.925500, 0.155680, -0.929940, -0.658840, 0.772960, 0.199900, -0.100010, 
-0.303930, -0.597680, 0.220950, 0.371300, -0.342570, 0.698810, -0.562190, -0.433620, -1.073470, 0.603710, 

0.201680, 0.677620, 0.167240, 0.680180, -0.297210, -0.209270, -0.134680, -0.304120, -0.726660, -0.297100, 
0.519540, 0.175460, 0.287990, -0.270580, -0.340630, 0.294260, -0.430800, 0.072550, -1.181090, 0.765160, 
0.208380, 0.136580, 0.045690, 0.006550, -0.293990, -0.599830, -0.147410, -0.242900, 0.997030, 0.546630, 
0.444040, -0.844090, 0.075800, -0.841190, 0.497740, -0.347400, -0.490470, -0.665900, -0.698720, -0.067670, 
-0.986350, -0.531450, 0.687200, 0.032180, -0.629340, 0.095510, 0.237770, -0.218470, 0.081200, 0.278530, 
0.490900, 0.408010, -0.893140, 0.609160, 0.686580, 0.352560, -1.068170, -0.640630, -0.921010, -0.757280, 

-0.912320, -0.203910, -0.887480, -0.355420, 0.773770, 0.184660, 0.265070, -0.209510, -0.147840, -0.592060, 
-0.749460, -1.053030, 0.143660, 0.785780, -0.403440, 0.581260, 0.694280, -0.196620, -0.750190, 1.201780, 
0.480530, -0.629870, -0.555150, -0.449980, -0.661570, -0.960370, 0.819550, -0.730380, -0.605690, 0.813870, 
-0.582840, 0.279440, -1.018310, 0.111520, 0.547730, 0.232230, -0.180020, -0.653110, 0.560480, -0.076550, 
-0.221930, -0.303180, -0.997640, 0.126310, 0.084700, 0.640560, -0.822900, -0.413180, 0.472140, 0.469270, 
0.712770, -0.916450, -0.510390, -0.504540, -0.172420, 0.526610, -0.296860, 0.302700, -0.959640, -0.639580, 

-0.049730, -0.130290, 0.098820, -0.374850, -0.156390, 0.127470, -0.662620, -0.246860, -0.092220, -0.086490, 
0.486750, -0.575010, -0.674660, 0.162530, 0.775250, -0.561650, -0.412130, -1.004990, 0.275900, -0.170730, 
1.197610, 0.122790, -0.038040, 0.665580, -1.142820, 0.067120, 0.013980, 0.744700, -0.085200, 0.181870, 
-1.287320, 0.483840, -1.326120, -0.057710, -0.543990, -1.469080, -0.793460, -0.365110, 0.040350, 0.405560, 
0.065630, 0.502200, 0.120950, -0.062020, 0.743390, -0.681710, 0.293090, -0.980650, 1.068420, 0.089510, 
-0.962760, -0.410760, 0.209100, 0.617540, 0.125530, -1.177910, 0.025840, -0.156330, -0.516430, -0.556590, 

0.927140, 0.627030, 0.121410, -1.291840, 0.946400, 0.265600, -2.032630, -1.033070, -0.063210, -0.853940, 
-0.484330, -0.699080, 0.388030, -0.947470, 1.273050, -1.277060, -0.517340, 0.199390, -1.326160, -0.236760, 
-0.599390, -0.089400, -1.025190, -0.936470, -0.615870, -1.232950, 0.111530, 0.419900, 1.008910, -0.915840, 
0.607620, -0.274240, -0.026190, 0.815290, -0.948590, -1.224870, -1.109610, 0.060560, 0.208320, 0.393060, 
-0.471970, 0.655610, -0.549630, 0.983360, -0.635580, 0.260040, 0.215640, -0.054070, 0.977210, -0.678220, 
0.025110, 0.519700, -0.094520, -0.240290, -0.815360, 0.286670, 0.431480, -0.398880, 0.420240, 0.365740, 

0.272550, -0.890430, 0.140960, -0.429370, -0.256900, -1.547700, -1.021090, 0.627080, 0.000900, 0.504260, 
-1.507060, -0.308020, -0.135330, 0.317590, 0.671790, 0.537070, -0.045240, -0.978630, 0.666110, -0.268170, 
-0.041860, -0.360320, -0.659390, -1.326900, -1.572200, -0.863370, 0.954540, -0.348780, 0.841080, -0.760580, 
0.357390, 0.627450, -0.374610, -0.080350, -0.432540, 0.477440, -0.010480, 0.596950, 0.718250, -0.047650, 
0.314010, 0.469490, -0.529030, -0.640030, -0.640300, 0.458820, -0.158130, -0.548470, 0.298060, 0.594450, 
-0.413020, -0.878160, -0.864440, 0.277370, -0.373050, -1.230240, -0.519220, 0.030030, 0.220500, 0.828420, 

-0.513040, 0.460430, 0.107860, -0.747240, -0.145500, 1.104800, -0.224130, 0.536920, 0.115030, -0.407400, 
0.037370, -0.893930, -0.405230, -0.267100, -0.139640, 0.859580, -0.256980, -1.073320, 0.476840, 0.064840, 
0.506340, -0.146710, -0.370910, -0.663150, -0.252180, 0.027290, 0.252750, -0.139320, 0.194580, -0.768770, 
0.227890, -0.852930, 0.855900, -0.567270, 0.662980, -0.885960, -0.170030, 0.311060, -0.432690, 0.089860, 
-0.110120, 0.282700, 0.159990, 0.073720, 0.379870, -0.303630, 0.425270, -0.060740, -0.791580, 0.183770, 
-0.324120, -0.428740, -1.207330, 0.428820, -0.977320, 0.412350, -0.600560, -0.200320, -0.391720, 0.694330, 

-0.893140, 0.168960, -0.225070, -0.054670, -1.379100, 0.179440, -0.572760, -0.003820, -0.241580, 0.315950, 
0.150170, 0.521160, 1.103430, -0.556860, 0.827130, 0.186510, 0.017390, -0.434090, 0.640190, 0.262570, 
0.475430, 0.468370, -0.894990, -0.585480, 0.440190, -0.592990, 0.210590, 0.176140, -0.037920, 0.410680, 
-1.198490, -0.346030, 0.205880, 0.250730, -0.085670, -0.634960, 0.242680, 0.141570, 0.864860, 0.859040, 
0.180880, 0.505750, 0.165990, 0.203440, 0.760850, -0.421510, 0.900050, -0.628580, 0.721130, 0.100850, 
0.036330, 0.801780, -0.070430, -0.212720, -0.006090, -0.177710, 0.026080, -0.194810, -0.494630, -0.269520, 

-0.390030, 0.101010, 0.674080, -0.766800, 0.296170, 1.167790, -0.087460, 0.012380, -1.245890, -0.534800, 
-0.515260, -0.476750, -0.469900, -0.855280, 1.043280, 0.178840, -0.824990, -0.990230, 1.424040, 0.947230, 
0.556610, 0.662490, -0.125850, 0.194290, -1.548950, -0.102040, -1.024140, 0.168340, 0.330130, 0.760260, 
0.337040, -0.024770, -0.763510, -0.440710, -0.967920, 0.152440, -0.911310, -0.215780, -0.225850, 0.681840, 
0.106600, -0.662650, 0.114680, -0.486780, -0.141390, -0.433090, -0.092300, 0.828220, -0.293390, 0.486080, 
0.662430, 0.013320, -0.044740, 1.008510, 0.102360, -0.466000, -0.771370, -0.163270, 0.035740, -0.232570, 

-0.673580, 0.410960, -0.937400, -0.733000, -0.334060, -0.751860, -1.717390, -1.013670, -0.086090, -1.354720, 
-1.594040, -0.140670, 1.020540, 0.000290, 0.177080, 0.199420, -0.473150, -0.507260, 0.065410, -0.869010, 
0.577610, -1.310420, -0.497430, -0.429850, -0.126350, 0.310830, 0.602270, -0.345240, 0.634840, 1.119400, 
0.379580, -1.256860, 0.120980, 0.346950, -0.631430, 0.128840, 0.821820, 0.712250, -0.616590, 0.244880, 
0.268710, -0.531240, 0.340370, 1.051090, 0.056470, -0.179280, 0.154950, 0.426870, -0.391270, -0.201010, 
-1.015610, -0.049800, 0.114930, -0.957690, 0.529350, -0.205770, -0.379640, 0.260390, 0.233350, 0.322320, 

-0.150320, 1.133600, 0.256800, 0.487660, 0.264210, 0.426750, -1.328490, 0.529770, -1.507570, 0.002650, 
-0.403350, -1.682640, 0.321310, 0.662280, -0.689690, 0.945950, -0.146960, -0.837530, -0.496080, 0.139680, 
0.826210, 0.029310, 0.073630, -1.649760, 0.715540, 0.313960, 0.357180, -1.370350, -1.662450, 0.781570, 
-0.324770, -0.928880, -0.728310, -0.013610, 0.356760, -0.476140, 0.108550, -0.671360, 0.381980, -0.697970, 
0.749790, -0.120010, -0.478660, -0.323040, -0.197270, -0.708230, 0.455290, 0.156810, -0.284560, -0.561940, 
0.628570, 0.840060, -0.361250, -0.449630, 0.016680, -0.471710, -0.265250, -0.906290, 1.365990, 0.934370, 

0.197440, 0.541040, 0.072030, 0.100220, -1.837970, -0.733790, -0.347510, -0.101730, 0.631170, 1.539040, 
1.041400, 1.541420, -0.842520, 0.714990, -0.150800, -0.057070, 0.362580, -0.513200, -0.212150, -0.014920, 
0.853300, 0.079000, 0.756790, 1.518600, 0.267490, 0.302740, 0.138650, 0.845050, -0.520200, -1.378290, 
-1.201520, 0.454040, 0.584340, 0.302100, -0.494420, 0.675420, -0.010380, -1.152320, -0.099180, -0.149370, 
0.754170, -0.118890, 0.598150, 0.442040, 0.876580, 0.101220, -0.289880, -1.048050, 0.404940, 1.046010, 
-0.023010, -0.677660, 0.398040, -0.464400, -0.779440, -1.070060, 0.171560, -0.411840, 0.306450, 0.240360, 

-0.372800, 0.559110, 0.363040, 0.078260, -0.464320, -0.272340, -0.324390, 0.676160, 0.511540, -0.276720, 
-0.597570, 0.948060, -0.824750, -0.231700, 0.673770, 1.083320, -1.149010, -0.531690, -0.840920, -0.355150, 
-1.160380, 0.650500, -0.648940, -1.276930, 0.324540, -1.105830, -0.639700, 0.515160, 1.017440, -0.318490, 
0.394210, -0.243200, -0.715800, -0.584270, 0.187420, 1.035450, -0.738810, 0.144730, 0.048840, 0.159340, 
0.125200, -0.613480, -0.505860, -0.726100, -0.535830, 0.105500, 0.367280, -0.745970, -0.529510, -0.779310, 
0.835090, 0.714690, -0.645220, 0.325800, 0.348990, -0.650960, -0.159350, 0.560480, 0.206370, 0.109570, 

0.852540, 0.622930, -1.334630, -0.827850, 0.951330, -0.890930, 0.622820, 0.358620, -0.449350, 0.562920, 
-0.700410, -0.716600, -0.381260, 1.082730, -1.518490, -0.678050, 0.095610, 0.263350, 0.773640, -0.558960, 
-0.386150, -1.584340, -0.049870, -0.220040, -0.329740, 0.585000, 0.956470, -0.867190, -1.917770, -1.330900, 
-0.142180, 0.089590, -0.158800, -0.379110, 0.352360, 0.175330, 0.870260, 0.501850, -0.943050, -0.300100, 
-0.355070, 0.818220, 0.474010, 0.108110, -0.330600, 0.379370, 0.827150, -0.618750, 1.187660, -0.446790, 
-0.127130, 1.124870, 0.020780, -0.397330, 0.230790, 0.023960, -0.688740, 0.240440, -0.036100, -0.478500, 

-0.472120, 0.361770, -0.449890, -0.295690, -0.516040, 0.225750, -1.003280, -0.528140, -0.018720, -1.044530, 
0.591000, -0.665930, 0.180950, -0.755190, -0.468810, 0.041010, 0.455220, 0.763590, -0.101310, 1.065660, 
0.078060, -0.944000, 0.328230, -1.479020, -0.829450, 0.839320, 0.927730, -0.907300, -0.286640, 0.231970, 
-0.707800, -0.782980, -0.760880, -0.287960, 0.599190, 0.100470, -0.513370, -0.738200, -0.271400, -0.313710, 
0.671810, -1.148800, -1.028220, -0.872490, -0.935150, 0.537990, 0.539210, -0.789030, -0.419430, -0.329350, 
-0.467730, 0.529530, -0.262690, -0.653700, -0.137250, -0.746960, 0.263940, 0.310060, -0.911440, 0.356010, 

0.560530, 0.377530, 1.368320, 0.688980, 0.777880, 0.610230, 0.899900, 0.763720, -0.708510, -0.741860, 
-0.570540, -0.266360, -0.352670, -0.487690, -0.469540, 0.562970, 0.210710, -0.453750, -1.045550, -0.569340, 
-0.574570, 0.387500, -0.296510, -0.893880, 1.262100, -0.696510, 0.802870, -0.431180, 0.723980, 0.667090, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, 0.475540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (inp2) */
      0.0, 0.397600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (inp3) */
      0.0, 0.780580, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (inp4) */
      0.0, 0.159070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (inp5) */
      0.0, 0.775340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (inp6) */
      0.0, -0.535840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (inp7) */
      0.0, 0.145690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (inp8) */
      0.0, -0.871430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (inp9) */
      0.0, 0.538940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 10 (inp10) */
      0.0, 0.513790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 11 (inp11) */
      0.0, 0.411180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 12 (inp12) */
      0.0, -0.702340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 13 (inp13) */
      0.0, 0.003950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 14 (inp14) */
      0.0, -0.272330, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 15 (inp15) */
      0.0, -0.317100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 16 (inp16) */
      0.0, 0.605450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 17 (inp17) */
      0.0, 0.736680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 18 (inp18) */
      0.0, -0.564480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 19 (inp19) */
      0.0, -0.278160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 20 (inp20) */
      0.0, 0.364660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 21 (inp21) */
      0.0, 0.912030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 22 (inp22) */
      0.0, -0.838800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 23 (inp23) */
      0.0, 0.238510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 24 (inp24) */
      0.0, -0.560780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 25 (inp25) */
      0.0, 0.835420, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 26 (inp26) */
      0.0, -0.184130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 27 (inp27) */
      0.0, -0.295530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 28 (inp28) */
      0.0, 0.382910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (inp29) */
      0.0, 0.380780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 30 (inp30) */
      0.0, 0.319990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 31 (inp31) */
      0.0, 0.284450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (inp32) */
      0.0, -0.870000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 33 (inp33) */
      0.0, 0.066820, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 34 (inp34) */
      0.0, -0.394300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 35 (inp35) */
      0.0, -0.133280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 36 (inp36) */
      0.0, -0.548410, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 37 (inp37) */
      0.0, 0.953880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 38 (inp38) */
      0.0, -0.462310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 39 (inp39) */
      0.0, -0.810470, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 40 (inp40) */
      0.0, -0.129570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 41 (inp41) */
      0.0, -0.344290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 42 (inp42) */
      0.0, 0.978280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 43 (inp43) */
      0.0, 0.949840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 44 (inp44) */
      0.0, -0.455220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 45 (inp45) */
      0.0, 0.107490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 46 (inp46) */
      0.0, 0.665660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 47 (inp47) */
      0.0, 0.858040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 48 (inp48) */
      0.0, 0.489590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 49 (inp49) */
      0.0, -0.256940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 50 (inp50) */
      0.0, 0.397110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 51 (inp51) */
      0.0, -0.221080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 52 (inp52) */
      0.0, -0.179100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 53 (inp53) */
      0.0, 0.179490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 54 (inp54) */
      0.0, 0.301110, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 55 (inp55) */
      0.0, 0.382060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 56 (inp56) */
      0.0, 0.125260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 57 (inp57) */
      0.0, 0.003740, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 58 (inp58) */
      0.0, 0.806800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 59 (inp59) */
      0.0, 0.712870, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 60 (inp60) */
      0.0, -0.071730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 61 (inp61) */
      0.0, 0.761030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 62 (inp62) */
      0.0, 0.803390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 63 (inp63) */
      0.0, 0.482670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 64 (inp64) */
      0.0, -0.859920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 65 (inp65) */
      0.0, -0.438210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 66 (inp66) */
      0.0, 0.924960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 67 (inp67) */
      0.0, 0.948830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 68 (inp68) */
      0.0, -0.412880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 69 (inp69) */
      0.0, 0.999570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 70 (inp70) */
      0.0, -0.135640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 71 (inp71) */
      0.0, 0.395960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 72 (inp72) */
      0.0, 0.810980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 73 (inp73) */
      0.0, 0.296130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 74 (inp74) */
      0.0, -0.951300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 75 (inp75) */
      0.0, -0.589940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 76 (inp76) */
      0.0, -0.539510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 77 (inp77) */
      0.0, 0.097010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 78 (inp78) */
      0.0, -0.696780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 79 (inp79) */
      0.0, 0.428120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 80 (inp80) */
      0.0, 0.272060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 81 (inp81) */
      0.0, 0.307450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 82 (inp82) */
      0.0, -0.337810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 83 (inp83) */
      0.0, -0.891190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 84 (inp84) */
      0.0, 0.996900, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 85 (inp85) */
      0.0, 0.307670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 86 (inp86) */
      0.0, -0.901940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 87 (inp87) */
      0.0, 0.659770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 88 (inp88) */
      0.0, -0.919700, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 89 (inp89) */
      0.0, -0.817810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 90 (inp90) */
      0.0, 0.442480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 91 (inp91) */
      0.0, 0.724860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 92 (inp92) */
      0.0, -0.465660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 93 (inp93) */
      0.0, -0.050070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 94 (inp94) */
      0.0, -0.554610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 95 (inp95) */
      0.0, 0.223210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 96 (inp96) */
      0.0, 0.599030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 97 (inp97) */
      0.0, -0.257790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 98 (inp98) */
      0.0, -0.991310, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 99 (inp99) */
      0.0, 0.677860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 100 (inp100) */
      0.0, -0.499090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 101 (inp101) */
      0.0, 0.342030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 102 (inp102) */
      0.0, -0.143960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 103 (inp103) */
      0.0, 0.206650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 104 (inp104) */
      0.0, -0.841670, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 105 (inp105) */
      0.0, 0.209120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 106 (inp106) */
      0.0, 0.945270, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 107 (inp107) */
      0.0, 0.196080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 108 (inp108) */
      0.0, -0.970920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 109 (inp109) */
      0.0, 0.156180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 110 (inp110) */
      0.0, -0.050100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 111 (inp111) */
      0.0, 0.558500, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 112 (inp112) */
      0.0, 0.652350, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 113 (inp113) */
      0.0, 0.139900, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 114 (inp114) */
      0.0, -0.746940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 115 (inp115) */
      0.0, 0.796340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 116 (inp116) */
      0.0, -0.278930, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 117 (inp117) */
      0.0, -0.543090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 118 (inp118) */
      0.0, -0.296150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 119 (inp119) */
      0.0, -0.629850, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 120 (inp120) */
      0.0, -0.127710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 121 (inp121) */
      0.0, -0.894390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 122 (inp122) */
      0.0, 0.442540, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 123 (inp123) */
      0.0, 0.189340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 124 (inp124) */
      0.0, -0.340170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 125 (inp125) */
      0.0, -0.351610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 126 (inp126) */
      0.0, -0.563530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 127 (inp127) */
      0.0, -0.390830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 128 (inp128) */
      0.0, 0.450080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 129 (inp129) */
      0.0, 0.887810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 130 (inp130) */
      0.0, -0.018560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 131 (inp131) */
      0.0, 0.912010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 132 (inp132) */
      0.0, 0.055370, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 133 (inp133) */
      0.0, 0.701980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 134 (inp134) */
      0.0, -0.219970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 135 (inp135) */
      0.0, -0.244160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 136 (inp136) */
      0.0, 0.801230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 137 (inp137) */
      0.0, -0.042450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 138 (inp138) */
      0.0, -0.255210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 139 (inp139) */
      0.0, -0.037240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 140 (inp140) */
      0.0, 0.148270, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 141 (inp141) */
      0.0, -0.630610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 142 (inp142) */
      0.0, -0.705570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 143 (inp143) */
      0.0, 0.864180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 144 (inp144) */
      0.0, -0.093180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 145 (inp145) */
      0.0, -0.820490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 146 (inp146) */
      0.0, 0.488200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 147 (inp147) */
      0.0, -0.621980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 148 (inp148) */
      0.0, -0.837510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 149 (inp149) */
      0.0, -0.391960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 150 (inp150) */
      0.0, 0.219650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 151 (inp151) */
      0.0, -0.675550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 152 (inp152) */
      0.0, 0.162890, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 153 (inp153) */
      0.0, 0.049000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 154 (inp154) */
      0.0, -0.824090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 155 (inp155) */
      0.0, -0.962390, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 156 (inp156) */
      0.0, 0.206660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 157 (inp157) */
      0.0, -0.845590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 158 (inp158) */
      0.0, -0.857560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 159 (inp159) */
      0.0, 0.047600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 160 (inp160) */
      0.0, 0.851980, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 161 (inp161) */
      0.0, -0.677550, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 162 (inp162) */
      0.0, 0.243170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 163 (inp163) */
      0.0, 0.024020, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 164 (inp164) */
      0.0, -0.931700, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 165 (inp165) */
      0.0, 0.077700, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 166 (inp166) */
      0.0, -0.929990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 167 (inp167) */
      0.0, 0.922840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 168 (inp168) */
      0.0, -0.944950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 169 (inp169) */
      0.0, 0.642120, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 170 (inp170) */
      0.0, -0.442090, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 171 (inp171) */
      0.0, -0.414990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 172 (inp172) */
      0.0, 0.827440, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 173 (inp173) */
      0.0, 0.229770, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 174 (inp174) */
      0.0, 0.557520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 175 (inp175) */
      0.0, 0.218030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 176 (inp176) */
      0.0, -0.976640, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 177 (inp177) */
      0.0, 0.683510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 178 (inp178) */
      0.0, -0.029990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 179 (inp179) */
      0.0, -0.838860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 180 (inp180) */
      0.0, -0.863450, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 181 (inp181) */
      0.0, 0.779290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 182 (inp182) */
      0.0, 0.128070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 183 (inp183) */
      0.0, 0.098360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 184 (inp184) */
      0.0, 0.168280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 185 (inp185) */
      0.0, 0.469280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 186 (inp186) */
      0.0, -0.103340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 187 (inp187) */
      0.0, -0.960480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 188 (inp188) */
      0.0, 0.870510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 189 (inp189) */
      0.0, 0.476610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 190 (inp190) */
      0.0, 0.253280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 191 (inp191) */
      0.0, -0.367960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 192 (inp192) */
      0.0, -0.096490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 193 (inp193) */
      0.0, -0.203910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 194 (inp194) */
      0.0, -0.609430, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 195 (inp195) */
      0.0, 0.981950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 196 (inp196) */
      0.0, 0.645860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 197 (inp197) */
      0.0, -0.057490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 198 (inp198) */
      0.0, 0.629240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 199 (inp199) */
      0.0, -0.467140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 200 (inp200) */
      0.0, 0.587560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 201 (inp201) */
      0.0, 0.211030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 202 (inp202) */
      0.0, -0.426560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 203 (inp203) */
      0.0, -0.349380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 204 (inp204) */
      0.0, -0.559520, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 205 (inp205) */
      0.0, -0.891900, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 206 (inp206) */
      0.0, -0.613170, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 207 (inp207) */
      0.0, 0.457590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 208 (inp208) */
      0.0, -0.234190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 209 (inp209) */
      0.0, -0.347800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 210 (inp210) */
      0.0, -0.810260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 211 (inp211) */
      0.0, 0.816190, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 212 (inp212) */
      0.0, -0.784780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 213 (inp213) */
      0.0, -0.045730, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 214 (inp214) */
      0.0, -0.782560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 215 (inp215) */
      0.0, 0.932070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 216 (inp216) */
      0.0, -0.200230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 217 (inp217) */
      0.0, -0.266970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 218 (inp218) */
      0.0, 0.346880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 219 (inp219) */
      0.0, -0.816990, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 220 (inp220) */
      0.0, -0.954000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 221 (inp221) */
      0.0, 0.908530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 222 (inp222) */
      0.0, -0.825780, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 223 (inp223) */
      0.0, -0.076590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 224 (inp224) */
      0.0, 0.797720, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 225 (inp225) */
      0.0, 0.702760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 226 (inp226) */
      0.0, 0.255600, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 227 (inp227) */
      0.0, -0.796680, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 228 (inp228) */
      0.0, -0.179790, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 229 (inp229) */
      0.0, 0.653140, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 230 (inp230) */
      0.0, 0.125840, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 231 (inp231) */
      0.0, 0.706340, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 232 (inp232) */
      0.0, -0.475690, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 233 (inp233) */
      0.0, -0.644250, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 234 (inp234) */
      0.0, 0.969960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 235 (inp235) */
      0.0, 0.476590, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 236 (inp236) */
      0.0, 0.033360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 237 (inp237) */
      0.0, -0.317300, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 238 (inp238) */
      0.0, 0.494060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 239 (inp239) */
      0.0, 0.990160, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 240 (inp240) */
      0.0, 0.668050, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 241 (inp241) */
      0.0, -0.410070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 242 (inp242) */
      0.0, 0.749560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 243 (inp243) */
      0.0, -0.757240, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 244 (inp244) */
      0.0, 0.642050, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 245 (inp245) */
      0.0, -0.279210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 246 (inp246) */
      0.0, 0.998220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 247 (inp247) */
      0.0, -0.721210, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 248 (inp248) */
      0.0, -0.515960, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 249 (inp249) */
      0.0, -0.069880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 250 (inp250) */
      0.0, 0.726910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 251 (inp251) */
      0.0, -0.922810, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 252 (inp252) */
      0.0, 0.286620, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 253 (inp253) */
      0.0, 0.064080, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 254 (inp254) */
      0.0, 0.658940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 255 (inp255) */
      0.0, -0.870560, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 256 (inp256) */
      0.0, 0.405850, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 257 (inp257) */
      0.0, -0.865530, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 258 (inp258) */
      0.0, -0.938880, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 259 (inp259) */
      0.0, -0.817230, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 260 (inp260) */
      0.0, -0.508180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 261 (inp261) */
      0.0, 0.069040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 262 (inp262) */
      0.0, -0.719610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 263 (inp263) */
      0.0, -0.643360, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 264 (inp264) */
      0.0, 0.733720, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 265 (inp265) */
      0.0, -0.007380, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 266 (inp266) */
      0.0, -0.305480, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 267 (inp267) */
      0.0, -0.351150, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 268 (inp268) */
      0.0, -0.313650, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 269 (inp269) */
      0.0, 0.330220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 270 (hid11) */
      0.0, 0.162900, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, 0.338060, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, 0.719870, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, 0.160740, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 0.739500, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, -1.038010, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, 0.863660, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, -0.014870, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, 0.270930, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, 0.479530, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -0.695320, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, 0.236760, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, 0.475390, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, -0.230680, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, -0.242150, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, 0.526380, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, 0.871990, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, 0.346070, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, -0.866560, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.181770, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, 0.423820, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, 0.912510, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, 0.974660, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, 0.047490, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, 0.835790, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, -0.354730, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, 0.240020, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, 0.501960, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, 0.530580, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, -0.191880, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, -0.570640, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, 0.645470, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, -0.391820, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, 0.676580, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, -0.543760, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, -0.212470, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, -0.909170, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, 0.385400, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, -1.158810, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, -2.040120, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, -0.020270, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -1.116510, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, -0.483300, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, -0.373550, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, -0.789230, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, 0.171230, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, -1.478020, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, -0.931040, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -2.539690, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, -0.140850, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, -0.128850, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, -0.522820, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, -0.929340, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, -1.193040, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, -0.727520, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, -0.539770, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, 1.357650, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, -0.542860, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, 0.015080, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -0.388430, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, -1.368490, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
1.41927, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.35894, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
0.39091, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
0.17765, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.27266, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
0.30624, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
1.42362, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
0.73550, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
1.40126, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
1.42688, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
0.39405, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
0.32986, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
0.32100, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
1.09573, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
0.41871, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
0.10950, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.42513, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
0.19399, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
0.13623, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
0.11872, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
0.76319, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
0.42500, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
1.38394, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
0.01267, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
0.16964, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.04545, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
0.59522, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
0.34879, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
0.41010, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.07572, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
0.04683, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
0.16462, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
0.01697, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
0.04442, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
0.06182, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
0.14533, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
0.02441, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
0.08424, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
0.27491, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
0.00558, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
0.06987, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
0.15371, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
0.01383, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
0.33145, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
0.05522, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
0.03198, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.01278, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
0.22880, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
0.06142, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
0.08761, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
0.13902, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
0.03972, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
0.25368, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
0.01254, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
0.00586, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
0.03917, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
1.42492, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
0.09238, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
0.89118, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.01834, 0.500000, 2,
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
