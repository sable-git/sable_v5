/*********************************************************
  Pfam_RP_all_1_8.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:18:56 2005
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
-0.318320, -0.119510, 0.246710, 0.083940, -0.579640, -2.556520, 0.651480, 0.525530, 0.341780, -0.487140, 
0.659830, -0.466190, 0.851770, 1.033310, -0.254830, -0.109530, 0.689600, 1.227850, 0.526490, 1.532320, 
0.253260, 1.098930, 1.699810, 1.816640, 1.093550, -0.538920, 0.843140, 0.705190, 0.642970, 0.435670, 
0.867360, 1.214670, -0.006690, -0.436600, 0.971220, -0.241130, 1.096850, 1.984960, -0.163600, -0.962460, 
-2.600930, 1.908450, 0.955190, 0.817100, 1.246850, 1.141930, -0.364480, -0.986170, -2.878170, -0.538480, 
-0.060180, -0.402680, 0.129310, 0.139100, -1.140700, -2.991210, 0.861970, 1.974030, -0.319700, -0.487540, 
-0.333500, 0.655810, 0.583590, -5.326770, 0.423450, -0.122780, 0.385850, 1.601810, -1.348270, 0.737210, 
-1.336590, -0.789070, 0.224870, -0.007770, -1.146450, 0.829140, -0.404360, 0.570000, 0.337790, 4.001460, 
0.048110, -0.800440, -1.067220, 1.983620, 0.554790, 1.032270, 0.910840, -0.852100, 0.490070, 0.088270, 
2.393620, -0.590060, -0.113870, -0.516970, 1.244160, 1.864990, 0.327410, -0.674970, 1.150400, 2.234350, 
1.106570, -0.379250, 0.969350, -0.456460, 0.144230, -0.427020, 0.874730, 1.073330, 0.104500, -1.085910, 
1.078750, -0.355440, 0.892110, 3.452810, 0.456850, -0.531890, -2.837950, -2.066240, 1.825950, -3.291110, 
-0.618920, 1.635310, -0.991360, -0.444020, -9.857700, -0.716390, -0.826050, -1.743550, -2.268960, -0.301230, 
-1.279860, 1.183370, -5.300590, -0.265390, -2.343340, -0.561260, -1.793450, 1.454200, -0.553480, 0.223470, 
-1.253350, -1.137290, 1.063320, 2.686570, -0.086550, 1.096250, -0.752400, 0.041590, 0.269310, 0.607460, 
-0.488810, -1.300230, -0.732200, 1.536300, -0.123610, 0.225510, 1.182450, 2.662410, 0.332310, 1.906180, 
0.255770, -1.062540, 0.110390, 0.089010, -0.314730, 0.731140, 1.660250, 0.154990, 0.471850, 0.530490, 
0.948770, -0.878400, 0.666120, 0.457580, 0.928090, 0.176190, 0.772980, 0.502330, -0.440300, 1.255260, 
0.403810, 0.850200, 0.945360, 0.666880, -0.613070, 0.471200, -0.037920, 0.717700, -0.198930, 0.111420, 
0.533970, 0.593950, 0.151890, -0.557770, -0.329370, 0.884500, -0.116630, 0.046160, 0.500020, -0.083710, 
-0.000810, -0.413390, -1.972270, 2.222620, -0.904760, 0.603600, -0.766290, -2.083530, 0.566310, -2.201730, 
1.108810, -1.646860, -0.933350, 0.771000, -1.584810, -1.540480, -3.009960, 0.162590, 2.189290, 0.378460, 
-0.286710, -0.515150, 0.723800, 1.896890, -5.380670, 5.546570, 1.643950, 0.789940, 3.672320, -0.039720, 
0.149100, -0.491980, -0.484340, -0.926710, -0.194050, 0.238650, 1.313330, 0.137180, 0.448300, 0.493440, 
0.667710, -1.350340, 0.592250, -0.271430, 1.291440, -1.364330, 1.380360, 0.072510, -0.206510, -1.340320, 
0.363210, -0.180720, -0.081870, 17.509569, -0.160280, 0.652530, -0.337910, -1.445120, -0.762550, -0.840290, 
-0.766600, -0.425060, 2.308360, 1.746060, -0.863380, 2.387190, 0.473330, -0.208270, 1.206600, 0.943730, 
0.650530, 0.133270, -0.378920, -0.699880, 1.350840, 1.422990, -0.268020, 0.696800, 0.920520, -0.331200, 
1.100010, 0.122760, 0.696140, 0.707710, -0.088280, 0.340520, -0.601690, -0.945190, -0.209540, -0.316820, 
0.021320, -0.314880, -0.354650, 0.126660, -1.111160, 0.222760, 1.584280, -0.024940, -0.673580, 
0.728950, 0.261430, -0.440570, 0.944870, 0.673870, -0.411190, 0.249460, -1.496910, 0.440920, -0.469190, 
-0.130350, 0.158190, 0.190890, 2.377930, 1.398260, 1.045860, -0.006460, 0.578600, 1.024880, -0.645980, 
0.506740, -0.487460, 0.204520, -0.791280, -0.384280, 0.379910, -1.123160, -0.697020, -1.096440, 0.113260, 
0.267480, 0.725170, -1.728180, -0.666410, -1.162950, -0.321450, 1.391010, 0.081440, -0.881010, 1.256410, 
-0.619640, -2.146360, -2.665120, 0.955870, -2.290760, -0.293600, -0.040700, 0.022520, -1.619250, 0.597040, 
-2.299740, 1.883300, -0.733400, -0.849290, -2.066190, -1.191500, 0.881910, -0.135130, -0.152060, -1.791430, 
0.802800, -0.490380, -0.049920, -1.681700, -0.240670, 0.872340, 0.790020, 0.137270, -0.267170, 0.706500, 
-0.564020, 2.554640, 0.177940, -2.638580, -1.006210, 0.625850, -0.707160, -1.324620, 0.425420, 0.691960, 
-0.563070, 1.350620, 1.321880, -1.211240, 1.115070, 1.683890, 1.257800, -0.127140, 0.511410, 0.622820, 
-0.198320, -0.627020, 1.484150, -2.140120, 0.504000, -0.653500, -0.380000, -2.308510, -0.523130, -0.102460, 
0.280190, 0.194800, -0.634520, 1.060110, 0.699190, 2.139010, 0.238210, -0.396040, -0.302750, -1.536230, 
-1.965130, -0.650590, -0.857380, -0.253760, 1.623020, -2.473310, -4.198000, -0.420590, 0.330410, -3.016450, 
-2.951370, 0.962690, -5.707690, -1.515750, -4.529460, 0.834290, -0.299390, 0.569230, -2.068730, 1.653880, 
2.294930, 1.273180, -8.375540, 1.157550, -0.266990, -3.543420, -3.027110, 3.615580, -2.154000, -0.661220, 
-1.522970, 1.848130, -0.366680, -1.571650, -0.338010, -0.758790, -0.770120, -2.114340, -1.042130, 0.855840, 
0.450290, 2.099350, 0.723670, -0.653280, 1.493010, -0.646190, -1.308920, 1.024470, 0.334030, 0.089940, 
1.538420, 1.656460, 1.818780, 1.096750, 2.644570, -1.189000, -0.697090, -1.715730, -0.378480, -0.451140, 
-0.006900, -0.897220, 0.156830, 0.372310, 2.649630, 0.057720, 0.762170, 0.858570, -1.699830, 0.688730, 
1.023250, -0.726050, -0.112870, 1.454090, 1.051970, 0.264050, 1.262770, 0.695930, 1.639790, 0.344390, 
-1.509860, -0.348960, -1.350960, -0.250560, -0.949530, 0.764400, 0.521730, 2.024580, -0.683680, 1.344690, 
0.218200, -0.130100, 0.913820, -1.235330, -0.957430, -0.143830, 0.454620, 0.816570, 0.284510, 0.718030, 
0.300750, 0.354270, -0.069260, -1.922650, 0.555080, -0.149870, -0.735240, 0.431880, 0.323830, 1.361820, 
1.032270, -0.950660, -0.062500, -0.234050, -2.966700, 0.108240, 0.827150, 0.294500, -0.355310, 0.140400, 
-0.966280, -0.500680, 0.408510, 0.715320, 1.629060, 0.732060, -0.219300, -1.534020, -0.135040, -0.710230, 
-0.322530, 0.094090, 0.381760, 2.096760, -0.489120, 1.405750, 0.105120, -0.551000, 1.206110, 0.440410, 
0.979890, 2.383710, -0.488690, 7.665510, -0.484220, -0.702320, -1.511250, -0.184740, -1.132730, 1.611490, 
-0.549720, 0.781230, 1.224430, 0.669800, -0.302150, 0.702940, 0.439630, -0.131170, 0.005590, -0.414750, 
-0.257880, -0.860500, 0.497830, 0.834760, -0.160430, 0.729310, 0.896770, -0.194490, 0.063880, 0.260350, 
0.608300, 0.665940, -1.004010, 0.174870, 0.672330, -0.839190, 0.430360, 0.603040, -0.598570, 1.012600, 
-0.790950, -0.302520, 0.534800, 0.967710, 0.949990, -0.595570, -2.722370, -0.423020, 0.523860, 
0.636850, 1.107930, 0.974770, 0.201950, 0.605050, 0.594730, 0.332960, 0.563700, 1.791940, 0.017970, 
2.004090, 1.124410, 0.753210, -1.515710, -1.778610, 0.183140, 0.666010, -0.559820, 0.865720, 1.011150, 
-0.215490, 0.054380, -0.040090, 1.162240, -1.228610, 0.175500, 0.303050, -2.288170, 1.255670, 0.218490, 
3.003790, -0.555790, -2.676190, 1.883540, -0.610150, 1.005010, -0.902770, -1.916940, 1.430350, 0.012480, 
-4.623290, 0.402570, -0.438030, 0.191890, -0.165170, 1.097310, 0.210910, -0.996080, -4.983400, 0.493140, 
0.547110, -1.664170, 1.386270, -0.672370, 2.202500, -4.684110, -1.489560, 1.627600, -0.221240, -1.221100, 
0.466710, -0.261600, -0.091010, -0.427750, 0.600190, 0.391030, -0.424860, 0.586480, 0.457800, -2.396190, 
0.242420, -0.161330, 0.111840, 0.336600, -1.354700, 1.431970, -0.256980, -2.616700, 1.329390, 0.706180, 
0.723650, 0.976890, 0.816780, -2.019170, 1.035360, 0.958200, -0.697190, -0.187380, 1.146010, 0.944590, 
2.340820, 1.527990, -0.651960, -0.534480, -1.378240, 0.034940, 2.038540, -0.510390, 0.109320, 0.830070, 
0.045920, -1.786660, 1.516580, 1.009290, 0.718930, -0.173690, -0.295810, 1.048280, 0.457490, -1.919000, 
-3.090770, -1.387010, 0.497930, 1.446490, -1.235860, -1.569670, -2.788750, -0.993040, 0.233990, -0.610560, 
-1.221650, -1.009410, -0.971540, -1.369770, -4.656400, 0.728990, 0.600200, 1.377540, -1.398830, -0.506680, 
0.151870, 0.661570, -4.146440, 0.478170, 0.836630, -3.912940, -0.354670, -1.485000, 0.960430, 0.386750, 
-0.949150, 1.762280, 1.789360, 0.565190, -0.601470, -0.444670, -1.144440, -0.857600, 0.016660, -0.025320, 
-0.046960, -0.306620, 0.394920, -3.345930, 0.486430, 0.205130, -0.314360, -0.795310, 0.495120, 1.549220, 
-0.563650, 1.825260, -2.003900, 0.988280, 1.815310, 0.593030, 0.382730, -0.708360, 0.248360, 1.475560, 
-1.007500, -0.523220, -0.361290, -0.302520, 0.263310, -0.415110, 1.118050, 2.395570, 0.860830, 1.085270, 
-0.454710, -0.605430, 0.275240, -0.181050, -1.170110, -2.314470, -2.473160, -1.331440, 0.876440, -0.573080, 
0.898370, 0.588570, -1.343310, -0.798220, 1.153180, -2.314020, -0.412930, -0.003520, -1.316730, -1.276820, 
-0.286560, 0.147110, -1.006230, -0.639970, -0.426690, -1.240040, -0.854040, 2.847550, -0.072280, -0.738800, 
1.696970, -0.346550, -0.914470, 0.898820, -0.503040, -0.119000, -1.513610, -1.513110, 0.471120, 0.237760, 
1.003960, -0.046510, 1.879140, -0.802400, 1.055710, -0.016230, -0.253140, 0.707510, 1.516030, -1.295140, 
2.184050, 0.740740, -0.500720, -0.130440, -2.288310, 0.345690, 1.216020, 0.265980, 1.777340, -1.137600, 
-0.271410, -0.086610, -0.634030, 1.404320, 1.237440, 0.030410, -0.322040, -1.230260, -0.671100, -0.172020, 
0.295220, 1.009660, 1.086730, 1.351400, -0.401860, -0.677010, 0.973920, 0.365180, 0.867900, 1.676140, 
-1.321580, 0.193710, 9.186650, 1.042700, 0.054850, 0.847180, -0.569920, -0.978040, -0.848710, 0.550020, 
-0.096680, 0.571380, -0.602280, -0.624490, 0.722840, -0.108920, -0.948850, 0.574530, -0.167780, 0.382220, 
0.580580, -0.474670, 0.728160, 0.431850, 0.682220, -0.537360, 0.291050, 0.525580, 0.587100, 0.984710, 
0.057420, 0.143180, -0.544580, 0.822760, 0.450620, 0.967880, -1.554500, 0.061750, 1.547450, 
3.024070, -0.520720, 0.761310, 1.975490, 1.653480, 1.540690, 0.807760, -0.696050, 4.614790, 1.376070, 
-1.296030, -1.450770, 0.033470, 1.566580, 0.563140, -0.325660, -1.789140, -0.044920, -0.902540, 0.855180, 
2.176940, -1.550350, -0.474690, 1.579750, 0.062500, 2.520160, 1.774000, -0.467430, -0.688260, 2.426520, 
6.878470, 0.489650, -0.699710, 0.750700, 3.065120, 1.409210, 0.618640, 0.519340, -0.484060, -0.875930, 
0.395310, -0.737700, 0.927870, 0.900370, -1.607470, 0.621190, 0.130360, 0.242370, -0.135110, -0.446630, 
-0.276150, 1.334830, 1.574740, 0.247470, 1.462530, 1.063270, 0.645490, 0.429850, 7.414510, -0.412530, 
0.722900, 3.247800, -0.418880, -1.046110, -0.133600, 0.879670, -0.452720, -1.189800, -0.439570, -0.316420, 
0.250010, 0.767900, 0.869640, 0.565150, 1.704170, 1.383550, 2.813470, 0.533190, 0.087970, -1.663760, 
0.969620, 0.953430, 0.493320, 0.252470, 1.094250, 1.422660, -0.810200, 0.074060, -1.121320, 0.534110, 
1.463940, 2.552460, -0.161810, 1.679450, 0.935350, -0.136820, -0.850650, 1.422790, -1.737820, 3.182070, 
2.094470, 0.499800, -4.361810, 0.135890, -0.520560, -0.088160, 0.645280, -3.205170, -0.826000, -0.771560, 
-0.748230, 3.576830, 1.836160, 1.483890, 1.762710, 0.403380, -0.580650, 1.971450, -1.432980, 0.069360, 
-0.913230, 0.519150, 0.654780, 1.301370, 0.362660, 0.135980, 0.234690, 1.977000, 0.858720, 1.378060, 
7.171670, 1.313310, -1.198950, -0.252230, 1.517020, -3.823850, 1.026910, 2.278480, 0.859090, 2.010710, 
-1.575590, 1.180660, 0.124120, 1.126440, 0.933110, 0.114670, 1.145440, -0.521970, -1.830730, 3.391690, 
-1.404530, 3.342370, -0.378910, -0.160000, 0.145970, 2.440810, -0.415130, 1.575290, 0.052210, -1.542460, 
0.169170, 1.733440, 5.509780, -1.105950, 2.094370, 1.033680, 6.896210, 0.041170, 0.117730, 1.958640, 
1.977970, -1.742180, -2.965400, 0.518340, 5.384860, 2.304500, 1.310990, 1.340890, 1.405820, -0.445680, 
-0.693760, 0.343250, -1.617170, -2.403060, 0.920490, -0.140970, 2.699580, 0.410040, -0.696920, 0.483210, 
0.852130, -0.292840, -0.711190, 0.057220, -0.038140, 0.386930, 1.313480, 0.566950, 0.900470, -1.008890, 
-2.094170, -0.713770, 1.481160, -0.907730, -0.890440, -2.159570, -0.250410, -1.061650, 1.354350, 1.727620, 
2.269150, 1.474430, -2.009550, 1.031590, 1.037690, -0.194470, -0.229040, 1.098580, 1.819190, 1.960090, 
1.249490, 0.092360, 1.885930, 1.228940, 0.720160, -0.249560, 2.654770, -1.053180, 0.292910, 0.027380, 
0.096270, 0.489750, 1.471990, 0.932010, -0.728510, -0.893300, -1.668290, -0.404060, 0.783030, -0.334460, 
-1.368220, 0.577310, -0.013590, 3.205350, 1.388040, 1.446220, -0.204290, 0.185690, -3.116370, 0.370380, 
0.027270, -0.779090, 1.217200, 9.377180, 0.020370, 1.254190, 0.342590, 1.228490, -0.266800, -0.784300, 
1.513280, -1.112790, 1.089300, 1.995570, -0.405290, 2.097190, -0.830320, -2.678930, 0.642170, -1.672120, 
-2.393010, -0.109470, -0.168480, -0.640630, -1.673930, -2.692080, 0.142130, -0.542050, -0.966740, -1.401440, 
-0.931530, 1.250440, 1.039000, 0.637100, -1.052630, 0.076950, 0.389360, 0.113590, -1.819690, -0.934810, 
-0.465100, -2.671740, 0.237200, 0.144490, 0.423090, -1.092020, 0.026610, -0.527300, 2.159550, 
1.131550, 0.602540, 1.035930, 1.332110, 0.338110, 1.636070, 0.403680, 1.223640, 1.092580, -0.059850, 
0.067410, 1.264860, -0.296890, 0.887800, -1.234210, -0.089070, -1.006300, 4.341200, -0.048810, -0.378800, 
0.649560, -0.217980, -3.405790, 0.337130, -0.103590, 0.272930, -2.614150, -1.846440, 2.849690, 0.069260, 
1.062250, 0.187310, -0.462780, 0.902240, -0.129470, 0.270010, 0.058480, -0.297180, 1.052750, -2.257820, 
-0.692310, 0.144030, -0.191090, -0.957170, 0.484410, -0.247620, -0.195470, -2.033280, -1.518340, 1.800600, 
-2.084750, 0.253800, -1.135960, -1.291960, -2.126720, -2.245420, 0.828470, 1.038120, 1.013230, -0.359870, 
0.133090, -0.942360, 0.495750, -2.163780, 2.146900, 3.335410, 0.260570, 1.677530, 1.751020, 0.664340, 
0.291850, 1.017730, -0.288350, 0.976420, 0.357960, -0.874170, -1.413640, 0.951150, 0.649280, 0.963350, 
-1.296810, 0.011000, -0.449110, -1.492390, -0.227620, 0.217250, -0.514710, 1.172680, 0.046540, 0.070680, 
-0.982680, -0.122120, 1.297450, 0.760580, 1.665240, 1.556020, 0.746660, 4.673490, -1.714900, 0.750070, 
-0.393520, 0.104620, -1.538060, -0.775530, 0.064550, 4.685300, 0.494940, 0.920820, -1.112310, 0.854410, 
-1.372840, -0.325890, -1.490410, 0.157610, -7.412530, 0.410610, -0.881020, -0.232670, -3.066630, -1.213770, 
0.153180, 0.013700, 0.824500, -0.393760, -1.391010, -0.197120, -0.646530, 0.731590, -0.988890, -1.027280, 
1.416000, 2.167410, -0.947670, 1.674360, 0.751480, 0.718640, 1.224050, -0.422170, 0.104780, -1.481550, 
-0.405580, 0.838360, 0.735910, 0.111970, 0.517930, -0.431450, -0.792180, -0.745050, -0.339960, -0.690210, 
1.373130, 1.781780, 0.294980, -2.001120, 0.755000, 0.051510, 0.372050, 1.556680, -0.333150, 3.257070, 
0.162280, 2.714950, 4.140010, 5.874260, 1.243720, 3.661670, 0.214230, -0.486460, 1.941670, 6.687670, 
6.807140, -0.248110, -1.277550, 0.172990, 2.003490, 5.091530, -1.398670, -0.389290, 5.061150, -2.610350, 
-2.171130, 1.104300, 0.713910, -3.941230, -0.135370, -0.519240, 2.623400, 0.369970, -0.480910, -2.062920, 
-1.390760, 1.567330, -0.716420, -0.217690, 0.447070, 0.127890, 1.931100, 0.147550, 0.440140, -0.572250, 
-1.821590, 0.359850, 0.852810, 1.262600, -1.052150, -0.349520, -1.206000, -0.957290, 0.425790, 0.094690, 
-0.457580, -1.506120, 2.087050, 2.720290, -1.258420, 0.325690, -1.471960, 1.172530, 3.319320, -0.267930, 
0.306500, -0.414080, -0.259410, 1.149190, -2.591610, 2.424630, 0.753360, 0.795820, 0.740120, 1.471990, 
0.797930, -0.433680, 0.915430, 1.439230, 0.836300, 1.023270, -0.009830, -1.386390, -0.413850, 1.500780, 
-0.959750, 0.316010, -1.750120, 0.986140, 1.283020, -0.544470, -0.312170, 0.886620, -2.507090, -0.857160, 
0.735700, 0.191490, -0.442430, -14.154070, 0.375130, -0.046830, 1.157260, -1.732200, -0.505280, -0.518660, 
0.808730, -1.138410, -1.625450, 1.106990, 0.184310, 0.303690, 1.865250, 2.853890, 0.443820, 0.787410, 
0.741180, 1.522110, 1.182450, 0.687440, -0.782520, -0.881460, 0.289450, 0.247280, 1.031450, 1.214610, 
1.434600, 1.741240, -0.718730, -0.443610, 0.093250, 1.648990, -0.811030, -0.007740, 0.417660, 0.033140, 
2.098300, -1.356030, -0.859600, 0.603430, -2.636860, 2.523750, 0.496760, 0.403040, 1.360120, 
-0.419370, 0.559740, -0.937480, -0.624910, 1.247550, -0.262150, -0.207440, 1.502760, 0.483740, -0.208250, 
-1.459770, -0.768320, 1.000190, 0.719820, -0.202390, 2.281710, 3.048500, 1.083030, 0.589510, -0.293040, 
2.970180, 0.499520, -0.272110, -0.138120, -0.828270, -1.800820, -1.955940, 0.303420, 0.452490, 0.785850, 
-0.559660, -0.355190, -0.591760, -2.289010, -0.071850, -0.226820, -1.758140, 0.683510, -0.182570, 0.330370, 
-1.092770, 0.005620, -2.006560, 1.226350, -0.456260, -0.650260, 0.084690, 1.304780, -0.382460, 0.536670, 
2.844660, 0.846440, -0.272500, 0.750530, 0.257860, -0.719270, 0.213860, 0.806660, 1.102650, -0.252890, 
0.644160, 1.157270, -1.137660, 0.685400, 0.423260, 0.485360, 0.077140, -1.348920, -2.372820, 1.861060, 
1.673380, -1.580430, 0.338680, 0.062070, -0.499630, -0.031450, -0.673940, -0.722080, 0.509910, -0.015280, 
-0.904680, 0.653780, -1.667600, -0.748900, -0.482960, -1.009230, 1.269680, -0.271990, 0.983310, 1.806060, 
-0.720820, -0.508920, 0.863410, -1.130230, -0.530140, -2.645730, -0.638860, -1.593150, 0.702640, 1.796070, 
0.459240, 1.312830, 0.388900, -1.440800, -0.220090, 1.217010, -0.058180, 0.110420, -1.181990, -0.785910, 
-0.441240, 0.517520, 1.258660, 1.223220, -2.718720, -2.213160, -1.328700, -0.198830, 2.744520, -1.224930, 
0.396580, 0.639190, -0.865060, 0.146550, 0.329350, 0.898220, 0.149750, -1.269960, 0.622560, -2.347270, 
-0.144640, 0.471920, -0.545900, -0.063140, 0.959680, -2.831880, 0.292180, 3.810430, -0.010020, -0.537810, 
-0.074300, -0.722750, -1.239680, 0.017660, 0.763640, -0.117950, -0.298890, 0.014900, 0.283710, -2.265000, 
-0.238870, -0.667810, -0.361790, 0.641990, 1.880240, 0.513280, 0.190150, 0.260650, 0.680110, -0.685700, 
-1.365370, -0.640680, 0.897980, 0.359810, 3.036610, 0.265160, -2.255280, 0.211410, -0.848350, 0.067310, 
0.785490, -0.997130, 0.671270, 0.372220, -1.725570, 0.915330, -1.185050, 0.235610, 0.652910, 0.346780, 
-0.857380, 1.593430, -0.566770, 6.003690, -0.687790, -0.806450, 0.699010, 2.190670, -0.214030, -0.365030, 
0.243680, -2.018190, -0.209400, -1.307900, 0.641090, 0.437240, -0.094480, -3.185270, -0.798860, 2.744500, 
0.463770, 0.124490, 1.428670, 0.411820, -0.760120, 0.151810, 0.880340, -1.581430, -1.416170, -0.368450, 
-0.962740, -1.255290, -0.729810, 0.436100, 0.262520, -0.838310, -1.860290, 1.510360, -1.169720, -0.149700, 
-1.907030, -0.427280, 1.056940, 0.884800, -0.515740, 0.128350, -1.235920, -0.081730, 0.347510, -1.651430, 
-1.371930, -2.026200, -0.368820, 0.966370, -1.622750, 1.331830, -0.216870, -3.692860, 0.711170, -0.148070, 
-0.136420, -0.616830, -1.120070, -1.127690, -0.730340, 1.782840, -1.265750, 1.968060, 2.051930, -2.546820, 
-0.587450, -0.294980, -0.284170, -9.453930, 0.009120, -0.793460, -0.215840, 1.134090, -1.186960, 7.470930, 
1.454240, 0.042250, 1.762200, 0.462780, 1.145110, -1.655920, -0.757820, 0.555870, -0.485110, 0.344270, 
-0.011600, -0.185020, -1.103400, 0.168500, -0.549290, -0.439020, 0.363740, -0.649730, -0.528970, -1.127610, 
0.272840, -2.325980, -0.293470, -1.717090, -2.367470, -0.055260, 0.025850, -0.870640, -0.413690, 0.061280, 
1.352910, -0.032960, -0.658420, -3.735220, -1.265240, -1.789440, -14.140690, 0.410670, -4.946920, 
1.273610, -1.252950, 0.182420, 0.384680, -0.081870, -0.938630, -0.962390, 2.840240, -1.192480, -0.383050, 
0.380460, 0.510500, 0.694460, -1.435090, -0.207660, 1.591720, 1.114480, -1.037440, -0.279650, -1.714010, 
-0.151190, 2.592110, -0.041140, -0.629090, -0.912150, -2.173070, 0.012210, -0.734640, 0.579240, -0.119210, 
-0.161300, -0.404660, -0.930340, 0.792970, 0.848160, 0.430540, 1.424390, -0.578920, -0.313570, 0.676990, 
-0.768120, -1.690430, -0.277750, 0.614890, 0.298170, -0.340750, 1.089340, 1.233910, -0.533790, 0.488060, 
1.276040, -0.729590, 0.616440, -0.142530, -1.328820, -0.748010, 1.140310, -0.601800, 1.718110, 0.887370, 
0.083110, 0.119680, 1.275510, -0.456000, -0.268330, 2.131760, -1.294040, -0.698040, 0.716600, 0.006090, 
-1.571510, -0.261450, -0.095430, -1.766110, 0.390600, 0.415750, -0.657380, -0.323490, -0.093960, 1.443890, 
0.459480, 0.076320, 0.445400, -0.481170, 0.130080, 0.566810, -0.138190, -0.711880, -0.382370, 0.850580, 
-0.395750, 1.488000, 0.886540, 0.030890, -1.200590, -0.776490, -0.462890, -1.005010, -0.927520, -0.718780, 
-0.615560, 0.374990, 0.104510, 0.691870, 2.193690, -0.732860, 0.867010, 2.109190, 1.725240, 2.453530, 
-0.543900, -1.000240, -0.011880, -0.008270, -1.506980, -3.773030, -0.246820, -5.021640, 4.137490, -1.012390, 
1.374700, 2.599540, 1.369960, -0.103440, -6.179840, 0.368730, 1.994130, -1.433040, -3.233920, -6.120690, 
-0.052260, -0.018530, -3.238670, -1.384010, 0.815850, -5.347040, -3.531320, 2.946220, 0.124990, 0.846580, 
-0.665310, -0.054330, 0.038700, -0.365290, 0.683860, 2.568130, 0.094600, -0.575110, 0.435010, -0.172260, 
-0.014380, -2.587940, 0.439870, 0.753910, 0.399260, -0.360910, -0.413750, 1.171220, 0.350520, -2.805080, 
1.677790, -0.338800, -3.657000, -1.650350, 1.438670, -0.517510, -0.603090, 0.711060, -0.092610, 0.430260, 
1.187490, -0.085680, -1.688100, -0.522790, -0.438160, 0.002500, 0.105940, -0.522200, -1.590750, -0.546690, 
-0.210260, 1.189260, -1.873630, 0.102630, -0.999560, -0.262010, -0.100120, -0.190710, -0.817590, -0.197020, 
0.134920, -0.823890, 1.445030, -0.382720, -0.497420, 0.644500, 0.314680, -0.144200, 2.089810, -0.918950, 
-0.141130, -3.582890, 0.873390, -0.347480, -0.636350, -1.919340, 0.022750, 0.089080, -1.249950, -0.527200, 
-0.025350, 1.093350, 2.487660, 0.174240, -1.292450, 0.047290, -0.262530, -1.357460, -0.039300, 0.167830, 
-1.203920, 0.488020, -0.292940, -0.421350, -0.846240, 0.787200, 1.810570, -0.137610, 0.465450, -0.920250, 
0.227810, 0.207900, -1.223320, -1.689160, -0.573680, -0.806500, 0.680330, 1.169530, 1.128640, -0.081500, 
-0.094570, -1.821910, -0.596510, 1.553470, -0.267250, 0.061670, 0.065890, 0.188840, 0.238890, 1.234410, 
3.821520, 0.745550, 4.515210, -19.674089, -0.252410, 0.824120, -0.361910, -0.730070, -0.637130, 2.086050, 
4.290520, 1.811810, 0.537200, 1.593070, -0.022710, 0.081720, -0.763400, -1.057120, -0.184630, 0.294080, 
-0.193800, -0.993330, -0.085730, -1.683400, -0.665920, -1.696540, -1.027740, -0.954650, -1.168010, -0.867540, 
-2.928140, -3.488730, 0.193490, -1.188160, -0.383680, 0.318010, -0.762030, -0.473300, -0.887110, -0.203630, 
-4.362420, -0.230420, -0.691060, -2.299190, 0.663420, -2.141540, -1.388400, -0.223880, -1.076870, 
1.608030, 0.596710, 0.072360, 0.460760, -0.529990, 0.839550, -0.848360, 1.069970, -0.085160, 1.105660, 
0.096810, 0.070950, -1.369950, 0.102960, -0.240810, 0.754430, -0.550630, 0.208810, 0.034520, -1.026130, 
-0.436820, -0.988560, 0.848350, 1.707360, 1.496560, -0.492770, -1.301090, 0.273200, 0.025140, -0.377100, 
1.686980, -0.644470, 0.114930, 0.666120, 0.185450, 1.525520, -0.477860, 0.304310, 1.357900, 0.259150, 
0.143650, -0.235880, -0.235370, 0.691870, -0.479260, -0.772740, 0.723330, -0.808590, -0.819400, 0.504020, 
0.016000, 0.677060, -0.108820, 0.270440, -1.123720, 0.544050, -0.287090, -0.172960, 0.139300, -0.487570, 
-0.587820, 0.348420, 0.767400, 0.032800, -0.381930, -0.844680, -0.263780, 0.167990, -0.539210, 0.808490, 
0.878920, -0.066490, 2.165630, 0.980690, -0.397790, -1.376260, -0.476420, 3.575340, 0.755360, -0.279540, 
0.665030, 2.001620, 1.767180, 0.803600, -0.452320, -1.328710, -0.647730, 1.501100, -1.253560, -0.137920, 
0.038740, 1.026560, 1.128000, -2.223970, 0.322110, 1.901040, -1.398290, 0.477240, -2.050290, -0.726350, 
0.244700, 0.265650, 0.256980, 0.281780, 0.867160, -0.513410, -1.805140, -1.224030, 1.123490, 0.647780, 
1.394700, 0.188760, -0.966550, -1.136020, 1.104130, -4.995950, -8.989380, -0.479620, 0.312790, -3.338650, 
-2.561920, 1.630620, -6.419380, -3.580680, -1.990620, -0.905960, 3.382280, 1.529730, -5.462590, -1.119970, 
-1.463980, 0.276890, -2.773810, 1.867630, 2.812780, -1.766560, -2.743970, 4.178810, -2.335780, -7.242160, 
-0.310580, 0.744080, -0.340030, -0.110810, 0.090000, -0.796230, -3.835720, -0.713200, -0.868730, -0.935570, 
-0.964730, -4.198810, -2.468620, 0.707240, 1.457130, -2.307140, -0.367370, 2.103730, 0.189270, 0.940630, 
-0.438190, -3.377860, -8.231350, -0.352010, 2.266120, -0.431720, 0.597390, 0.124360, -0.792650, -0.139830, 
0.114220, 0.779300, -0.673550, 0.769720, -1.061340, 0.869150, -0.189550, 0.731910, 0.511700, 1.421730, 
0.206080, -0.545510, 0.881640, 1.545500, -0.183310, -6.701610, -0.241970, 3.675190, -0.428900, 1.106520, 
1.179630, 0.094910, 0.249280, 0.554550, -0.544060, 0.278730, -0.709460, -0.495540, 1.293130, 0.449090, 
0.530360, -0.834030, 0.657570, 3.104160, -0.333090, -0.589200, 1.303350, -1.181270, -1.497350, -1.480350, 
-0.295340, -0.581810, -0.955610, 0.854280, 1.290970, -2.677750, -0.705020, 0.575350, 0.417300, 0.346020, 
-0.889410, -0.075540, 0.321110, 0.879800, -2.586500, 1.622010, 2.084820, 0.366750, -0.093690, 0.878130, 
0.031260, -0.208800, 1.138080, 0.939410, -0.723970, -1.725790, 1.215260, -1.410940, -0.719060, 0.241750, 
-1.879430, -0.480920, -1.189650, 1.815950, 0.377710, -0.886290, 0.227580, 0.289210, -0.137250, -0.968060, 
-0.426550, 0.729420, 0.898280, 21.029320, -0.521000, -0.026820, 0.237660, -0.900480, -0.147060, 2.765520, 
-0.127870, 0.433840, -0.953380, 2.867610, -0.422640, -0.391600, -0.023940, -0.449420, 0.065810, 0.397410, 
1.194790, 0.989100, -0.449130, 0.310030, -0.649000, 0.782010, 0.954150, -0.312590, 0.586990, -0.519580, 
-0.468360, -0.997380, -0.578820, -0.814930, 0.633890, -0.768530, 0.984500, -0.132100, 0.157180, -0.958810, 
-0.047300, -1.410740, 0.538980, -0.171370, -1.499690, 0.143480, 0.140370, -0.614710, -0.368940, 
-0.386860, -0.863470, 0.063690, 0.135460, 0.330970, 0.814430, -0.219570, 0.045840, -2.358850, 0.141170, 
-0.727050, 0.306150, 0.025870, -2.264680, -0.827420, -0.298110, 0.843850, -0.067670, 0.589250, -0.605790, 
-0.497220, 0.101760, 1.056990, -0.747120, 0.584090, 0.360500, 1.070160, 1.312420, -0.491750, 1.272040, 
0.207860, -0.474090, 1.786690, 0.825660, -1.592190, 0.108730, -0.698550, 0.472460, -0.658570, -0.329860, 
0.188700, -0.165580, -1.929140, -0.569480, -1.549660, -0.207350, 0.189060, -1.408220, 2.653370, 2.163790, 
1.287250, 0.080850, 0.166450, -0.176010, -0.066830, -0.020140, 1.069770, 0.195270, -0.363270, -2.160400, 
0.865520, 0.757470, -0.586970, -4.614420, -0.961300, -0.144590, -1.033790, 0.114160, -1.798830, -1.076970, 
-0.621620, 1.825850, 0.396200, 0.239750, 0.841010, 1.225140, -3.592680, -0.392790, 1.690450, -0.060420, 
-0.350080, -0.866190, -1.339620, 0.426650, -1.463990, 0.025140, 0.332150, 1.294540, -0.435570, 0.458120, 
0.843600, 1.613210, -1.313880, -0.548610, 1.170460, 1.549560, -0.602830, -1.131280, -1.318880, -0.983570, 
-0.206910, 0.298710, -1.200580, 1.053940, -0.106540, 0.086160, -1.193750, -0.761240, -0.054890, -0.980060, 
2.098390, 1.337870, 0.230520, -1.005020, 0.646550, 0.917870, 2.532960, 2.216290, -6.720310, 0.796720, 
0.479390, -5.403430, 1.376040, 2.648950, 5.204460, -0.743870, 2.640590, -1.872380, 0.657250, -0.867400, 
-0.021280, -3.669070, 14.124010, 2.294220, 1.132350, 1.630050, 3.883350, -4.028070, 1.468000, 0.855470, 
-0.113790, 0.145150, -1.578720, -1.070240, 0.294730, 0.202860, 2.427040, -0.528020, -0.254960, -0.460120, 
0.603240, -1.015170, 0.421550, -2.158110, 1.374740, -0.085980, -1.594260, -0.615730, 0.854700, -0.894850, 
0.307340, -1.374550, 0.481700, -3.016190, -1.838120, 0.295160, -1.335530, -1.171940, 0.088720, -1.430310, 
-1.374770, -0.128660, 1.520930, -1.017690, -1.004330, 2.450570, 0.692040, -2.002260, 0.175330, -0.637330, 
0.092730, 0.173760, 0.480800, 1.311020, -0.954440, 1.437710, -0.621460, -0.883760, 0.696940, -1.745220, 
-1.089290, -0.909730, -1.217630, -1.148140, 0.799450, -0.878780, -0.474760, -0.523560, -0.218640, -1.026970, 
-0.764260, -0.222970, -2.795760, -0.834770, -0.789140, 1.184100, -0.465060, 1.183100, -1.380030, 1.570920, 
2.011490, 0.100160, -0.260340, -0.575460, -0.380520, -0.523510, 2.621440, 0.975810, 0.912620, 0.883210, 
-3.429510, 0.229070, -0.625470, -1.666710, 1.070840, -1.705430, -0.516960, 0.776320, -0.948460, -0.258430, 
-2.311920, -0.059080, -2.640080, -1.936290, -0.029560, 0.343370, -0.812030, 1.684750, -0.379710, 0.047760, 
-0.355620, 0.890710, -0.954050, 0.211710, -1.064100, -0.067180, 0.676820, 0.137490, 0.836230, -2.229500, 
-0.621500, 0.544030, 0.404100, -11.927810, 0.061990, 1.125860, 0.450800, 1.935550, -0.353100, -0.916820, 
-1.132050, -0.835290, -0.141950, -0.320920, 0.502380, 0.209270, 0.713680, -0.756180, -1.386940, 0.236060, 
0.071580, -0.709760, -1.243040, 0.295940, 0.367250, 1.705490, 1.453600, 0.253270, 0.336380, 1.972910, 
0.810690, -1.476940, 0.260520, -0.318380, -0.397260, -0.483450, -0.640700, -0.087370, 0.076420, 0.677050, 
-0.312910, 0.657930, -0.003190, -0.436020, -0.639570, 0.982850, 0.354450, 0.524990, 2.122720, 
-0.462540, 1.912750, 1.090490, 0.988840, 0.932860, -0.706680, -0.068750, 0.796340, 0.340900, 0.971520, 
-0.689020, 0.613910, -0.545910, 0.678690, -1.286200, 0.570120, 1.462900, 0.065030, 1.873600, -0.513050, 
-1.168230, 0.521230, -0.016360, -0.701940, 1.428670, 2.296480, -0.309280, -0.819980, 1.121050, 0.176050, 
-1.153220, -1.222150, 0.245780, -0.176700, 2.453020, -1.199740, 0.793540, -0.540030, -1.915220, -0.786370, 
0.546730, 0.317540, -1.021040, -2.085740, -1.053940, -0.697800, -2.848790, -1.203380, 1.754780, 1.283250, 
0.168940, -0.244240, -1.383330, -1.372090, -1.781820, 0.427370, 1.121220, 0.324250, 1.595190, 1.568070, 
1.596390, -1.566950, 1.359870, -0.264290, -1.271860, 0.452570, 0.677370, 0.580460, -5.645640, -0.490150, 
-0.618970, -1.025820, 0.160550, -1.255890, 0.329950, 0.257460, 0.290080, -0.970600, -1.965300, -0.108030, 
-1.464290, 1.876410, 0.821510, -0.499360, -0.230180, -0.067870, 0.276350, 1.711690, 0.557150, 0.411880, 
0.228860, -0.936150, -0.542570, 1.904840, -0.856820, 0.607340, 0.457720, 0.227610, -1.079680, -0.564110, 
-6.765520, -0.203960, -0.227920, 1.353800, 1.255380, 0.806510, -0.927350, 0.659540, 0.389800, 1.038390, 
-0.505120, 0.540120, -0.910610, 1.062460, -0.353910, 0.438860, 4.174470, -1.080930, -2.254440, 3.171900, 
0.799780, -5.090630, 0.494800, 24.197571, 6.073720, 0.530800, 2.271610, 0.032950, 7.669860, 0.210860, 
-2.692260, 2.303720, 7.243380, 2.768970, 4.541850, 0.678210, 4.199730, -3.644480, -2.538940, 2.104970, 
-5.083950, -1.380280, 0.236970, -1.301300, 0.063510, 0.159040, -0.528730, -2.788080, 0.008740, -1.184290, 
-0.092770, -0.310410, -0.939670, 2.473240, 1.350020, -0.383940, -1.246610, -0.299250, 0.403780, 0.728390, 
1.294510, -0.006390, 1.267660, 1.656210, 0.271620, 1.801240, -1.080490, -1.658320, 1.498110, -1.775800, 
-1.439840, 1.267770, -0.218680, -1.482120, 1.362190, -1.094740, 0.288560, -0.401260, -0.508400, 0.879940, 
1.492670, -0.018360, -0.771170, -1.110140, 0.571190, 1.099290, -1.570380, 0.183790, 1.985980, 3.210010, 
-0.180570, -0.586460, -3.603250, 0.606120, -1.396720, -0.702670, 0.087520, -0.244300, -0.630230, -0.199680, 
0.489770, 1.126800, -1.766400, 0.417460, -0.321930, 0.045900, -0.308710, 0.364060, 1.813310, 1.822210, 
-0.405150, -0.401270, 0.039160, 0.306160, 1.618410, -2.389330, 0.230920, -0.381440, -1.560850, 1.493060, 
-0.264240, 0.488320, 1.778840, 1.438460, 0.622320, 1.230660, 0.229540, -0.146000, 0.058660, -1.083670, 
0.429510, -1.414690, 0.238610, -2.606400, -1.867460, -2.200500, 1.246490, 0.175150, -0.557140, -1.073950, 
-1.232980, 0.281710, -0.335700, 0.956360, 1.023490, -2.222000, -0.855920, 1.622970, -0.029790, -0.767750, 
-1.453200, -0.161620, -2.934790, 0.783170, -0.003510, -0.945670, -0.263500, -0.906240, 0.024280, -1.113330, 
1.021950, -2.318370, 4.293520, -3.794960, 0.723310, 0.291300, -0.736690, 1.028810, 0.864910, 2.892710, 
-0.336150, -0.022660, -0.942340, 2.554790, -0.114990, 1.939690, -0.180830, 0.273510, 0.972600, 0.676710, 
0.066410, -0.652690, 1.207370, 0.807000, 0.573350, -0.486380, -0.731150, -1.577980, -0.576850, -0.603830, 
0.188950, -0.529550, -0.021950, 0.217040, -0.697500, 0.791310, -0.664000, -0.592480, -0.333460, 
-0.598940, -1.263530, -0.833000, -0.920860, 0.074000, -0.409990, -1.953400, -0.368460, 1.524170, 1.838300, 
1.218900, -0.258000, 0.402460, -0.763130, -0.001380, 0.797630, 2.092450, 0.599660, -1.923020, 0.136340, 
-2.246540, 1.738620, -0.303430, 0.453410, -1.426280, -2.547720, -1.239740, 0.451450, -0.345130, -0.901390, 
-0.938790, 0.340420, -0.521400, -0.617230, -0.007150, -1.165270, 0.840810, 1.764580, 0.576900, 1.460230, 
0.547850, -1.477310, 0.332590, -0.289840, -0.682400, 0.308210, 0.221570, -0.661940, 0.077190, -0.360380, 
-0.237620, 0.258620, 0.136620, -0.832480, -0.771190, 1.004990, -1.470890, -1.179720, -0.246700, -0.527270, 
-1.342370, -0.642750, 0.965270, 0.157930, 0.617810, 0.016870, -0.679530, 0.875710, 0.625300, -1.132230, 
-0.597870, 2.117560, -1.306810, 0.442460, 0.514410, -0.296510, -1.051550, -1.133880, 0.750760, -1.160830, 
0.834090, 0.218960, -0.150980, 0.319710, 0.081660, 0.247340, -0.356630, 0.560850, -0.001010, -5.064760, 
1.750890, 0.458080, -0.807320, -1.027480, -0.360860, -2.115440, 0.148660, 0.158160, 0.112870, -0.171190, 
-0.638190, -1.216080, 0.079010, -1.525180, -0.866350, -0.062370, 1.063770, -0.592740, 0.843850, 0.081920, 
-0.482520, 0.970940, -5.486330, 0.089990, -0.380300, 1.739570, -1.744910, 0.843540, -3.489420, 0.379070, 
0.987970, 0.140070, 1.465350, -2.954540, -1.362340, -0.306150, -1.092630, -2.082470, -0.702060, 1.069250, 
0.217270, -0.842040, 1.419880, 0.130570, -0.895270, 5.958710, 0.107240, -0.020430, -0.209280, 0.263250, 
-0.266230, 0.242390, 0.250540, 0.480130, -1.196460, 1.393650, -1.412450, -0.318240, -0.669400, 0.605760, 
0.296870, -1.137970, -0.526250, 0.136200, 0.570850, 0.042520, 0.051300, -0.338200, -1.188550, -1.400980, 
-0.575450, 0.829450, 1.883380, 0.007930, -2.320190, -0.274240, 2.801890, -0.782610, 4.891060, 0.639030, 
0.464470, -2.318230, -1.137700, 0.386020, -0.436310, -1.621040, -0.338860, -2.015560, 1.373260, 0.003150, 
0.192720, -0.943990, 0.869120, -0.971060, 2.660650, 0.546760, -0.416500, -2.465540, 0.071860, 0.571330, 
-0.693080, 0.696950, -1.493220, 0.538500, -0.080590, 0.444320, 1.031960, 3.445250, 0.127880, 0.587070, 
-0.564500, -0.691930, 0.108500, -0.487810, -1.179790, 0.253040, -2.718350, -0.592840, -0.347380, 0.502750, 
-2.622130, -0.382500, 0.953640, 0.798200, -0.331950, -0.810610, 1.105980, 0.150320, 1.884930, -1.962450, 
-0.872920, -0.316060, -0.295590, -0.890000, 0.144440, -0.047260, -0.315330, -1.472180, 0.397870, -1.024070, 
1.162110, -0.283180, -1.133850, -2.562830, -1.865320, 0.172850, 0.340400, -0.815460, 0.723860, 0.047410, 
0.156900, 1.002750, 0.299780, -2.700110, -0.212990, -0.497600, -0.084710, 0.405230, -0.304890, -0.667810, 
-0.052700, -3.084530, -1.704830, 5.539580, 0.300240, 0.005490, 0.025230, -0.786690, 1.399610, 1.416400, 
0.071680, -2.334340, -2.019320, -2.248590, 1.178860, 1.109930, 0.209140, 0.071740, -0.111920, -0.411000, 
1.434230, 0.033550, -0.130880, 0.297110, -1.326210, 0.997490, -3.080070, -0.982500, 0.698550, 0.457450, 
-0.442440, -0.644610, 0.848260, -0.032820, -0.151720, 0.511910, -0.486520, -0.121160, -0.602550, -0.659560, 
-0.846730, -0.522600, -0.715410, -1.323140, -2.614520, -1.272210, 0.899700, 1.194600, 2.052260, 
1.007520, -0.733530, -0.974790, -1.805900, 0.905020, -0.157570, 0.568790, 0.211930, 0.100910, 0.974520, 
0.075190, -0.627200, -1.084420, 0.861650, 2.021710, 0.333650, 1.424200, 0.343470, 0.474730, -0.034820, 
-0.648230, 0.526890, -0.510550, -0.081430, 0.477230, -0.373780, 0.289860, 0.397900, -1.304030, 0.928060, 
1.586950, 0.912360, -0.184080, 1.372180, -0.102560, 0.391870, -0.036200, -0.527650, -0.738510, -1.909430, 
-0.268420, 0.374210, -0.485070, 0.755500, -0.078350, -0.086380, 1.887510, -0.069150, 1.634780, 1.551270, 
0.802240, -1.540240, 0.240380, 0.992890, 0.300190, 0.819510, -0.376260, 0.495370, -0.255580, 1.186190, 
1.317010, 0.668500, 1.963790, 3.548600, -0.018330, -0.810700, 0.005240, 1.954790, 0.843220, 2.246260, 
0.020300, 1.315020, -0.387180, 0.013140, -0.764970, 0.023170, 1.877210, 0.812850, -2.200360, -1.045610, 
0.488760, 0.752950, -0.171350, -0.975830, -0.478230, -2.147300, -0.488070, -0.821640, 0.267640, -0.512500, 
2.162830, -2.452200, -0.117920, 1.317200, -1.907560, -1.015770, -1.876580, 1.767480, -0.045640, -1.643810, 
-2.349300, -0.865330, -1.010110, 1.424490, -0.831460, -0.481880, 0.455690, -1.408860, -2.072380, 1.184400, 
-0.994290, -0.301780, -1.034560, 0.982490, -0.773000, 0.589040, 0.427670, 0.315910, -0.599360, -0.147470, 
-0.409450, -1.515040, -0.991110, 2.553270, 1.641890, -1.567790, -1.198010, -0.887750, 3.336200, 0.137660, 
-0.521190, -0.579860, 2.505190, -0.371360, -1.138590, 3.744390, 1.222050, -3.831360, 0.879760, -1.706130, 
1.929850, 0.866910, -0.014810, 0.209690, -1.062290, 0.011150, 0.746280, 0.266970, -0.507720, 2.240540, 
0.427230, 1.441900, 0.831840, -0.952330, -0.990600, 2.450930, -1.085340, 2.076980, -0.972340, 1.550560, 
-2.804890, 0.765650, 1.564820, -0.078610, -2.695380, 0.411010, -1.333090, -0.083880, 1.196830, -1.344830, 
0.087070, -0.065490, 0.813100, -0.459150, 1.056210, 1.161500, 0.492300, -0.885580, 1.707810, -1.347110, 
0.385860, -0.212930, -0.481810, -6.358940, -2.006060, 1.122800, -1.074400, -0.183700, 0.481970, -0.409720, 
-0.872530, -2.578610, 0.883780, -0.189150, -0.844680, -1.282240, -0.503050, -0.359870, 0.114300, -1.340490, 
-0.605840, 1.882720, 0.148690, 1.169580, 0.201770, 0.025350, 0.229570, -0.670860, 2.100760, -0.112060, 
-1.271640, -2.588060, 1.077510, 1.310700, -0.342120, 0.900240, 0.900140, 2.559550, -0.073380, 0.668170, 
-1.101120, -0.853360, 1.482580, -2.470060, -0.352560, 0.242170, -0.991340, -0.087250, -0.318650, 1.252870, 
-1.568660, -0.519000, -0.601650, 0.516680, 1.436580, 0.539760, 1.020500, 1.018810, 0.010600, 0.641150, 
-0.125270, 1.565910, -0.844200, 0.398780, -0.578970, 0.908070, 2.044590, 1.107640, 0.070700, 1.081680, 
-2.243030, -0.627050, 0.206170, 0.014720, -0.618380, 0.763810, -0.113460, -0.505130, -1.065940, -1.123590, 
-0.417510, -0.245650, -0.417870, -1.086160, 1.828150, -0.372530, -0.733260, -0.038840, -0.048900, -0.846830, 
-0.794740, -0.147360, -0.494400, -0.366150, 0.484380, -0.672440, -0.875720, 0.533000, -0.491920, -0.733400, 
0.752320, 0.044360, -0.456500, -0.413410, -0.219160, -0.898690, -0.865200, 0.427110, -0.835970, -0.686140, 
0.050160, -0.654860, -0.394200, -0.366970, -1.120340, -0.617860, 1.486530, 0.932380, -0.987160, 
-1.408900, -0.301270, -1.788950, 0.196500, -0.463880, -1.010930, 1.642010, -0.475560, 1.312970, -0.801300, 
-0.127220, 0.477810, -1.562470, -2.238260, 0.218350, -0.269670, -1.333520, -2.282220, 1.223500, -0.710690, 
-1.383040, 1.039830, -0.873950, -0.209300, -0.330020, -0.799710, -1.358250, 0.117460, 0.545520, -2.441050, 
-0.825360, 1.346640, 0.266830, -0.881480, -0.593520, -1.899150, -0.361120, 1.265080, -1.451760, -3.084610, 
0.576470, -0.991080, -0.396960, -0.741230, 0.096260, -2.380580, 1.842150, 0.390840, 2.042610, -1.851410, 
1.466810, 1.618130, -1.132170, -0.782390, 1.072670, -0.988380, -2.799160, -1.094190, -2.489650, 1.066910, 
-0.336930, -0.984870, -0.357530, 1.336180, -1.622720, -1.204870, -0.308460, -0.099040, 0.532490, 0.760480, 
-0.892060, -1.714810, -1.342910, -1.205200, 2.931500, -0.405560, -2.516840, -0.048620, -0.120520, -0.526300, 
-1.529300, -0.578660, -0.032860, 0.825130, -1.810810, -1.303010, 1.638640, 0.349220, -0.508240, 1.007810, 
-0.061540, 1.623740, -1.295470, 0.648250, 1.443860, 0.480520, -0.810540, -0.728750, 0.101070, -1.668620, 
-0.559310, 0.169380, -1.797210, -0.087730, 0.333940, -0.742770, 1.849660, -1.185280, -0.980540, 1.014040, 
0.851090, -0.037450, -1.566170, 0.061920, 0.690600, -0.914130, 0.929170, 0.159350, -1.244530, 0.978860, 
-0.194530, 0.130510, 0.355710, -0.853000, -1.476380, -0.144880, -1.266870, -1.029630, -1.358970, -0.240270, 
-3.137960, 0.045980, 0.487560, -1.103020, -0.698010, -1.158490, -0.710980, -0.547180, -2.001190, -0.798450, 
0.509460, 0.450320, -0.632510, -1.492510, 1.156030, -1.519430, -1.682950, -2.187400, 2.736800, 1.427850, 
0.196060, -4.517800, 0.150950, -1.812770, -1.789360, -0.815530, -0.666840, 0.919320, -0.568850, 1.659020, 
2.536880, -2.819390, -3.034240, -1.678840, -0.068380, -3.027660, -2.407130, -0.827970, -2.361120, -4.371780, 
-2.582490, 2.029010, 1.128580, 0.537490, -4.397480, -4.693530, 0.214230, 1.255830, -1.964280, 0.130460, 
2.650790, 0.943940, 2.558390, 2.385160, -0.244640, 1.085930, 0.416030, 0.924640, 0.096900, 0.414450, 
-1.592150, -0.644100, -0.221490, -0.550590, -0.280810, -0.643800, 0.434960, -2.083670, -0.528810, -1.416050, 
1.151650, -1.673930, 0.136970, 0.408780, 0.416180, 0.809550, 0.492260, 1.424290, -0.810680, -0.516160, 
0.014190, 1.045800, -1.585060, -0.839590, -0.125190, -1.156140, 2.367390, -1.114610, -1.119430, -0.749480, 
-1.714620, -1.501650, 1.332790, -0.105000, 1.263240, 1.257770, -1.303850, 0.579850, -0.369400, -1.353810, 
-0.559120, -0.417620, -0.731430, -1.460710, -0.975600, -1.506450, 1.004410, 0.291410, -1.108400, -0.685660, 
-0.331890, -0.203460, -0.294840, -0.421120, -2.114690, -0.195240, 0.509150, 2.056780, 0.772600, 1.187830, 
0.774030, 0.248000, -0.442290, -2.961190, 0.023100, -0.030850, -0.873760, -0.574350, 0.051520, 2.810690, 
-0.201800, -0.482600, -2.041430, -0.179640, 2.244630, -2.317100, 0.744500, 1.746730, 0.326160, 0.795170, 
-1.908960, 1.682740, -1.052670, 0.214130, -3.080450, 0.957200, -0.464930, 0.252470, -2.082730, -1.305550, 
-0.608950, -1.509340, 1.158770, 0.082010, -0.912680, -0.751850, -0.012560, -0.189860, 1.200720, 0.214570, 
-0.297010, -0.038840, 0.388440, -0.365140, -0.031420, 0.415070, 2.103780, -0.762270, -2.864990, 
1.535840, 1.313170, -0.717230, 1.585300, 2.037150, -0.695020, -0.335670, 0.214820, 1.519220, 0.301530, 
-2.258820, -0.755860, 0.712010, 1.673040, 0.365820, 0.064500, -0.779940, -0.477650, -0.250110, 0.137530, 
0.628950, 1.242980, 0.187750, -0.074390, -1.677850, -0.013830, -0.322990, 0.948720, -1.056210, -0.367780, 
-1.484720, 1.855150, -2.285170, -1.511590, 1.079430, -1.277200, 0.367910, -0.959500, 1.207330, -0.539500, 
2.497280, 1.637630, -0.017180, 0.471050, 1.503610, -0.513790, 0.033720, -1.347150, -0.942840, -1.551910, 
0.186640, -1.980010, 0.085150, 0.657610, 0.137650, -0.013980, 0.906920, 0.260220, 0.918550, -0.040750, 
0.558090, -0.775790, 0.440050, 2.615430, 0.162300, -0.455120, 0.749160, 0.008650, 0.133490, -1.087920, 
-1.293090, 1.141920, -0.451210, 1.207510, -0.861280, 0.136510, 0.914340, -3.180480, 1.919630, 1.550470, 
0.030420, 1.025400, 0.668390, -0.467660, -0.892310, 0.147550, 1.528090, 0.887640, 0.649950, -0.921520, 
-3.098840, -3.932750, 0.959650, 1.567420, 0.959920, 0.522120, 0.427700, 0.737720, 0.317270, 1.051040, 
1.563140, -0.895910, -2.410760, -1.150740, 0.522000, -2.603230, -1.790670, 0.213500, -0.215830, -0.703200, 
-0.006350, -0.944340, -0.367350, 3.851220, 1.263210, -1.707440, -1.474380, -1.025640, 1.886760, -1.971070, 
-0.962500, -1.490970, 2.859570, -2.857090, -4.660920, 0.887910, 1.923590, -0.808140, -1.228130, 0.828150, 
4.058730, 0.916140, -2.420240, 7.065130, -0.350700, -1.919890, 1.454830, -1.358980, -0.860610, 0.284470, 
-0.756600, -1.323320, 1.847830, -1.694630, 1.359430, -1.376030, 1.199270, -0.168490, 0.731120, 1.153480, 
0.181720, -0.875660, -0.301480, -0.531150, 1.234280, 0.874800, 1.239310, -0.033620, 0.734730, 2.149380, 
3.200060, 2.293270, -1.261070, -0.102700, 1.861890, 0.461770, 0.282610, -0.529400, -0.976440, -0.686270, 
-0.029700, 0.594520, 1.219180, 0.176050, -1.568670, 0.700860, -0.137090, -0.421740, 0.620840, 0.165300, 
-1.518900, 0.544700, 2.151340, 0.156830, 0.042530, -1.386050, 0.725780, -1.030680, -1.342110, 0.045580, 
-0.762690, 0.026240, 0.571590, 1.170840, -0.126090, 0.948390, 0.158380, 0.390180, -0.652320, -0.491400, 
0.944810, -1.039570, -0.536960, 3.852070, 0.306370, -1.207300, 1.864300, 1.142420, -2.196620, 1.649120, 
2.439880, 0.037360, -0.818290, 1.364050, -0.408620, -1.569750, -1.217300, -1.530510, -0.624370, -0.344680, 
-0.141190, -0.701170, 0.491680, 1.382620, -1.016790, 1.137050, 2.206620, 0.337740, -1.222090, -0.648170, 
0.012250, -0.907440, 0.654770, -0.136710, 1.946480, -0.976750, -0.151860, 1.832540, -0.842920, -1.065790, 
-0.184950, 0.231220, 0.371120, -1.240760, 1.321820, 0.588920, -0.553930, -0.596040, 1.244880, -1.725200, 
-0.092600, -1.719860, -0.240530, 7.686880, 0.941580, -0.322960, -0.174850, 0.607900, -0.485760, -0.102880, 
-1.711320, 1.198360, 5.514300, 0.496090, 0.086740, -0.147360, -0.170660, 1.722420, 0.621830, 0.600010, 
-0.657750, -0.730740, -0.087630, 0.035420, 0.214940, -2.644720, -1.767230, 0.155070, -0.053070, -3.406530, 
-0.455020, -0.583180, -0.947370, 0.436670, 0.341550, -0.143360, -0.769450, 0.231510, 0.740450, 0.854430, 
0.163280, -0.602510, -0.531400, 4.019110, 0.488960, -0.567570, 0.031210, 0.577300, 0.666940, 
0.604220, -2.470900, -2.494530, -0.871400, -0.889180, -0.465510, -0.477140, -2.090950, -0.703810, -1.896460, 
0.138480, 0.111480, -0.316510, -2.909920, 0.575340, 0.804190, 0.054030, -2.556030, -0.929310, 0.365360, 
0.893850, -0.764560, 1.454100, 1.381040, -0.964250, -0.440260, -0.515740, -2.185770, 1.279660, -1.942920, 
-0.451400, -0.196120, 0.042130, -0.295900, 0.797260, -0.034260, -1.313130, 0.064480, 0.342080, -0.457750, 
-0.057040, -0.111870, 0.555000, 0.903750, 1.228330, 2.526490, -0.369130, 2.185370, 1.078260, -2.494660, 
1.537920, 0.454820, -0.937960, 2.547840, 0.919170, -0.836150, -0.396710, 0.431920, 0.279850, -0.388590, 
0.229720, -1.244510, -0.226820, 0.276660, -1.342790, 0.057010, 0.358910, 1.620480, -0.845740, -0.288090, 
0.355610, 2.395040, 0.331390, 0.245610, 1.791640, 0.694060, -0.056150, 0.734300, 2.752220, 0.489720, 
0.475670, 0.863130, -0.935720, -0.302690, -0.021990, 0.824190, 0.303960, 1.813120, -1.182480, 1.779260, 
-0.951340, -0.889350, 3.597230, 0.669230, -2.466160, 0.406080, 2.436880, -0.497090, -0.267690, 0.150420, 
0.775420, 1.139780, -1.625010, -0.832400, 0.228860, 0.314560, 0.025950, -0.046110, 0.606680, 0.253000, 
2.042000, 0.802900, 3.733550, 0.095420, 1.085490, 0.676250, -2.040200, -1.045720, -2.178010, 1.438430, 
-2.791460, 0.838810, -0.787660, 0.382680, -1.652540, 0.823080, -0.249140, 0.270970, 4.807570, -0.054030, 
0.332330, 0.410090, -0.317310, -3.085090, 0.731960, -1.260280, 0.074900, -1.354990, 0.692040, -0.622180, 
0.609040, -0.568740, -0.093520, -0.100710, -1.849430, -0.147760, 1.059680, -0.528910, 0.287800, -0.309180, 
-0.943490, 1.997070, 1.519480, 0.086020, -0.328900, -0.781480, 1.255120, -1.608690, -0.647300, -0.223600, 
0.729660, 0.234820, -0.191160, -0.737370, 0.615030, 0.165230, -0.679690, -2.427140, 1.021270, 0.577000, 
-0.021040, 0.728700, 0.209860, -0.571740, -0.485860, -0.786480, -0.294140, 0.914550, 0.878610, -0.532480, 
-0.118690, 0.282980, -0.486930, 2.019150, 1.095390, -1.290530, -0.304880, -1.962440, 0.934600, 1.200220, 
0.052150, 0.268380, -1.061340, -0.032210, -0.243170, 0.897790, -1.389750, -0.852920, 2.675480, 0.257230, 
0.119060, 0.456780, -0.823700, 0.327080, -2.816780, -0.094940, -0.376480, -0.480110, 0.374680, 0.511390, 
1.851750, -0.217430, 0.328160, 0.915410, -1.200400, 1.150550, 0.535460, -0.666840, 1.298480, -1.774410, 
0.936970, 0.226650, 0.160890, -0.154440, -0.144920, -0.921780, -1.654420, -0.191490, -0.420380, 1.347350, 
0.173220, -1.295160, -1.433610, 1.678870, -0.726870, -1.674670, 1.677390, 1.420930, -0.303740, 1.441210, 
-0.873550, 1.150590, -0.407050, 1.230120, -0.480840, 1.490450, 0.533530, -1.646100, 0.348100, 1.731410, 
-0.066080, -1.098740, -1.922080, -8.060710, 0.090180, -1.887740, -1.046330, -0.372300, 2.536160, 2.303890, 
3.223330, 0.294640, 0.282380, 2.007800, 0.514130, -2.981930, 1.930360, 1.429290, -0.073180, 1.543650, 
0.888440, 0.876930, 0.958750, 3.206600, 2.310530, 1.463720, 2.237630, 0.092470, 1.566320, -0.016970, 
0.539200, 1.844880, 2.897000, 1.769760, 2.474690, 4.203020, 0.033250, 0.238870, 1.990220, 3.310410, 
3.250190, 0.573050, 0.609750, 6.308520, 1.571060, 0.425070, 0.721140, 0.122440, 0.238860, 
0.454370, 1.421560, -0.682520, 0.938670, 0.550940, 0.244260, -0.187960, -1.189030, 0.155650, 0.351700, 
0.301110, 1.542290, 0.161890, -0.271570, -0.378520, 1.547310, -0.038000, 0.218610, 0.696510, 1.795850, 
0.108720, 0.348420, -0.203610, 0.190470, 1.096940, 2.281150, 1.164290, -1.660140, -0.119870, 0.059150, 
1.243620, 0.803300, -1.710030, -1.534430, -0.028730, 0.854870, 0.890550, -0.038310, 0.161930, 0.817800, 
1.761740, 1.432460, 0.882810, 0.347730, 0.653340, -0.050680, -0.360350, -0.873770, 0.899860, 1.160430, 
0.916230, 0.434090, 1.073940, -1.486760, 0.916550, 0.826550, -1.985690, 0.266840, 0.489670, -1.117630, 
0.285410, -0.294620, 0.634660, -0.974780, 0.157310, 0.104910, -0.338560, 0.715670, -0.288530, -1.539300, 
0.567370, 0.504820, 1.040730, 1.562150, -0.957680, -0.360160, 0.398750, 1.733810, 1.567890, -1.508320, 
0.540250, -0.274700, -0.544900, 0.698580, 0.350710, -0.483830, -0.520390, -1.434340, -0.222520, 0.985530, 
3.157050, -0.055960, 0.947190, -2.984930, 1.113400, -2.106340, 0.901910, 0.577200, -0.263990, 0.174040, 
0.672990, -0.995070, 0.460120, 1.352750, -0.452640, 0.073640, -1.337080, 0.648110, 0.112410, 1.122310, 
-0.971690, -2.107600, 0.694080, 4.751050, 1.950290, -1.624350, -2.061060, -1.775930, 3.184970, -1.021140, 
-0.663780, 3.123450, 2.913830, -2.907270, -13.831770, 1.834660, 0.683760, 1.642740, -1.511470, 0.801590, 
0.927200, -1.748130, -11.790310, -0.852320, 1.972990, -0.658090, 1.581320, 7.721110, -0.845770, -0.175030, 
0.041310, 0.930520, -1.095940, 1.865550, -0.704800, -1.113270, -0.729420, 2.047390, -2.427400, -1.210810, 
-0.264490, 0.334960, 0.231150, -0.040230, -1.544810, 2.349330, -4.799770, -1.820610, -0.505710, 2.535950, 
1.846710, -0.414610, -1.446720, -0.983770, 0.212340, -0.620580, -0.234330, -0.109750, -0.787700, 1.036240, 
1.676120, -0.241060, 0.573670, 0.061920, 1.597350, -0.047810, -0.722460, -2.387310, -1.073920, -0.824430, 
0.951620, -0.774160, 1.767440, 0.291710, 1.417210, 0.032240, -2.034990, 1.230120, -1.158190, -0.252010, 
-0.137270, -2.530320, -0.724050, -1.296300, -2.075940, 1.293290, 0.742540, -0.278990, 0.708230, -0.234340, 
1.373540, -0.504620, 0.199800, 0.329730, -0.399340, 2.942010, -0.025860, 0.805170, 0.635080, 0.631000, 
0.897290, 0.337990, -0.317280, 0.541030, -1.092140, 0.485930, 2.348630, 1.069420, 0.646960, 0.875050, 
0.379840, 0.825170, 1.639250, 1.264530, 2.386820, 0.066670, 0.391710, 0.110430, 0.529030, 1.973580, 
-0.222870, -0.568390, 0.825220, 1.652310, -0.133770, 0.483920, -1.633150, 0.833540, 0.968050, -0.394830, 
0.583150, 0.488300, -0.144800, -0.541490, 0.094260, 0.179380, -1.077840, 1.509430, 0.278710, -0.088010, 
0.583980, -0.173610, -0.066600, 17.460991, 0.130810, -0.081300, 0.277390, -0.846630, 0.345890, -0.909600, 
0.418490, -0.806200, 5.923680, 0.717640, -0.140250, 6.544940, -0.230800, 0.002490, 0.124080, -1.489230, 
-0.190320, -0.146840, -0.335440, 0.397430, 0.379080, -0.951810, -0.944620, -0.816690, 0.238660, -1.309360, 
-0.803920, -1.256210, -0.535500, -0.273270, -0.145720, -0.061480, -0.786900, 0.789710, -0.007280, 0.044170, 
-0.440900, -0.192710, -0.459340, 1.157970, 0.002920, -0.697660, -0.863650, 0.178830, -3.398530, 
-1.238280, 0.238470, 0.365370, 0.684930, -0.857210, -0.030900, -0.691550, -1.240020, -0.041410, -0.229670, 
-0.480980, 0.591120, 0.273270, -2.739340, 0.966770, 1.087830, -2.744970, 0.410410, 0.290520, 0.023700, 
-1.171200, 1.757030, -0.055500, -0.130580, -0.370540, 1.585670, -0.808280, 0.725770, -1.468020, -1.895650, 
0.456950, -1.235150, -0.962210, -1.084330, 0.657170, -0.690690, -2.131600, -1.315310, 2.321100, -0.592860, 
-0.151000, 1.410190, -0.865740, 0.061700, -0.342900, 1.082870, -1.939440, -0.452180, 0.480010, -0.304190, 
0.382590, 1.624530, 1.443660, 0.088750, 2.114940, 0.614000, -0.591230, 1.921170, -0.914790, -1.168380, 
-0.917000, 0.126560, -0.444640, 1.693630, 2.012670, 2.675750, 0.370700, 0.522460, 0.560260, -0.827330, 
0.375100, 1.104880, 0.313820, -0.039610, -0.211230, -0.135290, 1.240590, 1.265910, -0.019500, -0.680310, 
-1.109870, -0.029430, -1.065440, -0.763230, 2.383390, -2.014960, 0.496680, 0.448280, 2.237680, -0.103700, 
-0.460360, -0.252510, -4.549860, -1.330920, -0.665680, -1.507710, -0.559960, 0.473870, 0.493980, -0.054080, 
-1.427140, -1.149570, -0.861900, 0.437200, -0.427810, -1.220020, -1.029970, 2.441770, 0.464110, -0.107780, 
2.487740, 0.684790, 0.075890, 2.453520, -1.963760, 0.919320, 2.121110, 3.475390, -1.265310, 2.791650, 
1.165100, -0.831410, -0.400470, 2.174440, 8.962250, -0.427820, 0.160520, 0.667710, 1.533760, -0.301570, 
0.379780, -2.329940, 12.525900, -0.624250, -0.009700, 3.380950, 5.571740, -1.627890, 0.652320, -2.373500, 
0.138290, 1.502830, -0.641170, -0.648270, -1.307200, -0.899910, 0.282640, 1.299470, -0.602210, 0.820940, 
-1.813800, 2.109880, 3.824870, -0.797530, 1.079650, 1.336340, 2.068900, 0.970020, -0.007500, 1.477350, 
1.414890, 0.170770, -0.360170, 0.870060, 1.747120, 0.056460, 0.511840, -0.315480, 0.018030, 2.164890, 
-0.567060, -1.227230, 0.418150, 0.953870, 1.378260, 1.323820, 1.133980, 0.399680, 1.494020, 0.497830, 
0.148090, -0.668940, 1.280460, -0.238330, 1.874930, 0.517300, 0.523740, -2.034610, -0.653290, 1.156470, 
0.332550, 0.212020, -1.946430, 1.253090, 0.989110, 1.106960, 1.329180, -1.969020, -0.418690, -0.423720, 
-2.775630, 0.785490, 0.680130, -1.242140, 0.425000, 2.187790, 0.174770, -0.670440, -0.318100, 0.784540, 
0.002060, -0.276480, 0.284400, 0.663210, 0.871910, 0.731370, 0.661850, -0.285050, 1.060930, -0.579420, 
-0.140890, -0.321560, -0.010560, 2.379430, 4.414950, -1.598730, 0.252650, 0.226000, 0.547430, -1.059580, 
0.081030, -2.296510, 1.376930, 0.743970, -0.367970, -0.096970, -0.520710, 0.097230, -0.001620, -1.233830, 
0.221540, -0.752090, -0.939260, -1.880080, -0.067970, 2.291720, -3.329220, 0.459350, 1.154940, -0.893400, 
-1.441300, 0.386670, -3.874400, -5.114080, 0.386110, 1.665210, -0.206130, 1.953890, 0.249820, -1.226810, 
-1.584010, -0.892170, -0.567720, -1.255990, -0.293510, -1.584770, -1.169240, -0.222560, 1.828150, 1.525800, 
-1.156430, -0.571910, -0.102060, 0.314400, -0.697830, -0.048260, 0.262960, 0.768700, -0.083130, -0.029330, 
-0.142270, 0.304460, -1.520680, -1.011220, 0.760190, -0.714950, 0.445040, -0.333110, 1.028090, 0.352650, 
0.384270, 0.836580, -0.031750, -1.790460, -0.212410, -0.896500, -0.118430, -0.568730, -0.543630, 
2.353390, 1.677070, 2.443670, 1.422130, 0.563960, -0.172170, 1.619460, 1.982740, 3.948380, 1.177950, 
-1.940020, -1.681680, -0.094900, 2.844760, -0.933740, 0.915950, -0.150100, -0.183750, 0.735610, -1.025320, 
0.873260, -2.234040, -2.088510, 0.309070, -0.946390, 1.625960, -0.017290, 3.483980, -0.510930, 1.553960, 
-0.959520, -0.316660, 0.444620, -0.257160, -0.684190, -0.957900, 7.387210, 0.412920, -0.074710, 0.470100, 
-2.081800, -0.429820, 1.563890, 0.166340, 0.091040, -0.390290, 0.012000, 1.037840, 1.861290, -0.621670, 
0.675560, 1.305280, -1.108950, 1.953800, 3.147470, 1.194180, -2.169020, 1.436820, 1.195610, 2.277410, 
-0.427310, 3.787220, 2.026920, 1.411700, -0.815970, 2.100700, 0.385260, -0.571670, -1.527140, -1.116300, 
0.535200, 1.851010, 3.972420, -0.407000, -1.776880, -0.660620, 0.537040, 0.123870, 0.860830, -0.636860, 
0.225000, 0.407720, 1.081360, 1.412540, 2.614580, 0.610830, -0.435430, -3.652800, 0.913220, -0.546920, 
-0.441980, 0.266840, -0.815260, 0.643810, 0.274290, -0.735920, -0.625310, 0.148530, 0.318260, 0.669270, 
0.129100, -1.973560, 0.838430, 1.090200, 0.888480, -1.115380, -0.655080, 0.511500, -0.455520, -1.670220, 
1.340210, -1.243240, 0.433120, -1.023300, 2.731060, -0.818660, -0.429850, -0.115200, -3.252110, 0.115590, 
-0.671170, 2.326230, -0.640420, -0.029880, -2.022250, 2.716890, 0.513980, 1.555260, -2.962680, -0.690800, 
0.204560, 1.500620, -0.420800, 0.824670, 2.060750, -1.716990, -0.318610, 1.168060, 0.873960, 1.622750, 
-1.253630, 0.960420, -0.434450, -1.719440, -2.667210, 1.264850, 0.220780, 0.539760, 0.820500, 0.329070, 
-1.436390, -0.693430, 1.146900, -1.868490, 1.488860, 0.614210, 1.470870, 2.040570, 0.820830, -0.981040, 
5.278060, -2.039390, -0.264220, -0.090360, -1.099390, -1.135580, 1.066320, -0.251290, 0.037290, -0.402540, 
-1.039600, 3.445490, 0.707390, 1.099780, 1.119810, -1.000180, 2.967270, 1.743760, -1.035480, 0.727230, 
1.239920, -0.387150, -0.427930, 0.013370, -0.805620, -0.856340, -3.053940, 0.135390, 0.342400, 1.705420, 
-2.704100, 2.263810, -0.388800, -0.935270, -1.070780, -0.492120, 1.533450, -0.229730, -1.837920, -0.201060, 
0.811110, -0.990590, 2.165240, 1.914140, -0.438850, -0.676750, 0.165690, -0.115750, -0.327460, 1.188320, 
1.460990, -0.846830, -1.308160, 1.426470, 0.532700, 0.609240, -0.166210, -0.710120, -0.931870, -0.048260, 
-0.473240, 0.832870, -1.662290, -0.368800, 0.407610, 1.606250, -1.446130, 0.533420, -0.429590, -0.407830, 
0.255340, -0.314910, -0.145010, 1.643090, -1.092920, 0.713890, -0.874990, -1.401960, -1.949800, -0.395850, 
-0.475470, 1.021010, -0.143980, 0.738440, -1.144770, -0.484960, 1.632430, 2.723660, -1.325670, -0.262540, 
-0.107490, 0.764210, -1.590140, -13.368680, -1.071320, -2.701820, -1.069830, -0.051000, 0.068980, 0.778510, 
1.265590, 0.980310, 0.988670, 0.860220, -0.588000, 0.488150, 0.465650, -0.899570, -0.523930, -0.914340, 
-0.008790, -0.646350, -0.036480, 0.168860, -0.402150, -0.301710, 0.325310, -0.093500, -0.215840, 0.030430, 
0.749710, 0.806350, -0.391570, -0.452840, -0.807410, 0.713410, -0.565940, -0.414950, 0.024850, 1.027510, 
-2.235390, -0.932380, -0.465210, 1.714600, -0.200540, -0.066750, 1.104670, -0.143840, -0.042120, 
0.123770, 0.068030, -0.114310, -0.601040, -1.159650, 0.377610, -0.528410, -0.114230, -2.539990, 0.091320, 
-0.881350, -0.401240, -0.929660, 0.010630, 1.729000, -0.099280, 0.770070, 1.683170, -0.372580, -0.620190, 
0.007520, -0.350570, 1.098420, 0.786040, -1.337370, 0.222250, 0.687290, -0.683620, -1.416590, -2.156860, 
-0.575940, 0.337130, 0.588650, 1.817850, 0.692630, 0.291710, 0.719140, -0.618270, 1.036850, -0.243020, 
0.780260, 0.482280, -0.344100, 1.244800, -0.395390, 1.568060, 0.312500, 0.893090, 1.802420, 0.099250, 
0.810170, 1.401790, 0.877130, 0.686480, -0.489430, -1.810340, 0.301090, 1.974930, -1.250560, 1.760340, 
0.905790, -1.854020, -1.125600, -0.922650, 0.985070, -1.877470, 1.453200, -1.280100, -0.838630, 0.565070, 
0.825860, 1.409760, 0.932690, 0.255540, -0.290480, -1.131010, 1.531370, -0.439930, 0.234100, -0.736540, 
-0.896130, -0.566110, 1.070110, -1.363110, 2.348270, 1.283750, -0.135330, -1.296640, -0.578490, 2.418380, 
-1.797730, 2.319240, 0.542690, 0.233250, -0.097060, -0.510910, 0.168120, 1.315250, 0.508570, 0.072620, 
-0.834700, -0.811940, -1.003380, -0.132620, 0.574530, 1.644500, -0.033420, 0.417580, 2.516350, 0.239510, 
-0.507960, 1.828760, 0.737220, 0.912070, 2.769790, -0.584230, 0.186660, 0.456060, -1.547290, 0.393340, 
-0.016730, 2.280260, 2.090710, -0.863330, -1.388290, 1.687610, 0.708060, 1.075340, -2.522370, 0.526480, 
1.641870, -1.165570, -0.923240, 1.704990, 0.172770, -5.493640, -2.124710, 1.181190, 1.229640, 6.196800, 
-1.074170, 0.369920, -1.266740, 0.063420, -0.563920, -0.885900, -0.432940, -1.581530, 0.299830, 3.079490, 
-0.120850, 0.448750, -0.331480, -1.547590, 0.920160, -2.076530, -0.583040, -0.810950, 0.599640, -2.389120, 
1.822370, 2.841070, -0.344240, -0.352110, 2.991470, 0.537470, 0.676650, -1.500780, 1.141020, 0.490290, 
1.138230, -1.233820, -0.747570, -0.476150, 0.594950, -0.281700, 1.307590, 0.467510, 0.649700, 1.101150, 
2.297460, 1.099960, -2.179820, -0.325400, -1.910360, 0.806850, -0.651310, 0.237080, -0.286180, -1.639560, 
0.914140, -0.584580, 0.140660, 0.152010, -3.840090, -0.372550, 0.005280, -1.751790, 0.707860, -0.198990, 
0.722960, -0.305850, 1.106430, -0.827230, 1.215660, -0.255150, 2.752770, -0.466650, -1.764340, 0.232700, 
-0.842180, -0.797920, 0.325120, 0.839810, 0.157070, 0.717380, -0.397180, 0.633130, 0.289740, 1.174280, 
-0.150300, -0.193130, 1.130400, -2.422730, -0.390660, 0.903950, 0.506420, -0.371260, -0.460560, 0.263230, 
0.795320, 0.172670, 0.806910, 1.812520, 0.659510, -0.862640, -1.426260, 1.418870, 1.469390, -0.664520, 
-1.279820, -0.131060, 1.402550, 0.173940, -1.147780, -0.310240, -0.433120, -0.778490, -0.770280, 0.594910, 
1.859120, -0.766560, 1.239130, 20.924549, 0.200450, -0.226140, 0.467680, -0.171230, -0.119860, 0.858920, 
1.059200, 0.530360, 0.401230, 0.840880, -0.900810, 1.890980, -0.238780, -0.261080, -0.101230, 0.099010, 
-0.085120, 0.596770, 0.245310, 0.417020, 0.900740, -0.731600, 0.512130, 0.331590, 1.175010, -0.539570, 
0.342890, 0.326140, -0.554820, 0.491920, 1.198580, -0.129140, 0.628360, -0.259520, 0.822910, -0.714590, 
-0.017710, -0.180360, 0.837980, 1.528130, 1.314820, 0.938380, 0.500440, 0.941580, 0.923460, 
1.085090, 0.298370, -1.420480, 0.057730, 0.233690, 1.162490, -0.666100, -0.957650, 0.612840, 3.027150, 
-1.056930, -1.218170, 0.224240, 0.819330, 0.094090, -0.652130, -0.827820, 0.123530, 0.173400, -0.139220, 
0.394570, -1.729370, 2.462780, 1.405610, 0.313800, 0.153020, 1.959400, -0.239580, -0.624670, 0.712760, 
1.147630, 0.100140, -0.076910, 0.962700, -0.268100, 0.722330, -0.198530, 0.853640, -1.201010, 0.746410, 
1.612140, -2.162680, 1.280030, 0.575630, -0.935340, 0.644390, 1.122700, 0.553560, -0.151130, 0.879400, 
1.454770, -1.255690, 0.648540, 0.812260, -2.021280, -0.449320, -0.382530, 0.371830, 1.452190, 0.528820, 
-0.821360, 1.464440, 1.022960, -0.678730, 0.024180, 0.584200, 0.443900, -0.384740, -0.156860, 1.532100, 
1.523170, 0.937500, 0.947230, 1.469510, -0.634180, 0.326160, 0.402370, 2.319360, 2.572720, -1.191870, 
1.126970, -0.203100, -0.761320, -1.300920, 1.544290, -0.673890, 0.917960, 1.155340, 1.097850, 0.891790, 
3.605810, 1.513970, -1.255630, 1.823670, 1.396150, 0.052330, 0.952420, -0.556470, 0.747290, -0.052700, 
2.142760, 1.196090, 1.012770, -1.178960, 0.348550, -0.171480, 1.297620, 0.194620, -0.333340, -0.287690, 
0.047590, 1.874060, 0.545510, 1.168110, 0.305830, -0.317700, 1.534240, -0.329550, 4.686750, 0.468510, 
-0.275610, 2.514010, -0.198190, -0.692320, 0.711320, -1.190730, 1.260060, 0.074330, -3.947440, 0.032160, 
-0.138860, 0.410630, 0.713540, 0.885010, 1.004690, -1.135210, 0.648430, -0.687330, 0.003410, 0.118180, 
0.470410, 0.678990, -0.149090, -0.529950, 0.795960, -0.827240, 1.205590, 0.474970, 1.376360, 0.240090, 
-0.874870, 0.938290, 1.590000, 0.618200, -0.007540, 0.608400, 2.037460, 1.457950, 0.278490, -1.106160, 
0.303390, 0.859070, 0.217600, -0.245510, 0.714890, 0.287850, 0.451210, -0.074300, 0.805950, 0.476550, 
1.329440, -2.112790, 0.095440, 0.793120, 0.141240, 0.914710, -0.522130, 0.803770, -0.602270, -2.200630, 
-1.281300, 0.172700, 1.896470, -0.094580, -0.003710, 0.822620, 3.421330, -1.132990, 1.461130, -0.197800, 
1.745500, -1.097880, -0.267930, -0.612270, 1.069110, 0.538630, 0.408880, 1.012710, -0.853750, 0.776730, 
-0.522750, 3.026960, 1.960470, -0.060490, 0.074030, -0.032730, -0.128560, 2.143200, -0.429140, -1.252590, 
0.382170, -0.461980, 0.319130, -0.517610, -0.179070, -0.318210, -0.695350, -0.597650, 1.121800, 0.114850, 
-0.565170, -0.634280, 0.278120, 1.171400, -0.282240, 3.019890, -0.294720, 0.745140, 0.233720, -0.544250, 
1.499420, 0.020480, 0.432880, -0.004840, 0.000160, 2.423230, -1.609550, -1.458300, 3.182270, -1.930870, 
0.688530, -1.960550, -0.701270, -0.390450, 1.621990, -0.359510, 1.297870, 1.118610, -0.173120, 1.544220, 
0.182920, -1.270520, 0.501220, 35.787170, -0.817150, -0.035650, -0.368530, -0.292180, -0.448100, -0.278230, 
-1.976840, -1.651890, -0.656190, -0.437000, 0.418960, 1.233570, -0.438880, 0.465960, 0.344510, -0.045350, 
-0.712560, -1.404140, 0.208160, -1.464780, -2.676080, -2.143480, -0.197290, 1.083320, -0.892350, -3.896000, 
-0.181660, -2.115280, 0.348520, 0.369770, -1.344700, -0.206880, -0.844660, -1.038710, -0.187350, 0.429940, 
-1.281170, -3.320510, -1.053190, -0.977670, 1.258940, -3.198290, -1.172800, -1.423510, -3.760320, 
4.662600, 0.799370, 1.734520, 1.012490, 0.640640, 0.174580, 0.202020, -1.787580, -0.575750, 1.603690, 
0.252910, 0.206130, 0.436170, 0.446710, 0.134620, 0.556770, -0.602830, 0.970170, -2.979660, 2.194590, 
1.241250, -0.897630, 0.917370, 0.455320, -0.016360, 0.946770, 0.846990, -0.179780, 2.730640, 0.823750, 
1.483980, -0.861340, -2.325970, 0.623190, 1.511460, 1.825580, 2.169050, 0.602970, -0.209340, 3.236560, 
-1.292580, 1.621490, 2.944190, -0.758360, -0.050710, -0.058920, -0.844780, 0.820400, -1.330450, -0.247410, 
-2.275950, 0.732400, 1.746150, 0.667010, -0.994610, -1.343000, -1.520030, 0.152900, 1.840840, -0.426070, 
-1.328770, -0.610770, 0.753960, -1.175030, 0.285930, 1.335560, 0.582990, -0.077520, 1.399400, -1.413800, 
-1.586190, 1.265380, 3.756250, 1.742580, -0.524530, -0.214000, -0.143450, -1.880700, 0.668840, 1.822320, 
0.735840, 1.882820, 1.787590, 1.527680, 0.742650, 1.459690, 1.805220, -0.405750, 0.588860, -0.326830, 
0.172690, 0.846000, 1.719440, 0.475700, -0.844250, 2.683600, 1.448600, -1.323790, 0.612300, 3.617180, 
0.898730, -0.472560, -0.273890, 0.976410, -0.328570, -0.153320, -0.415390, 1.841100, -0.538030, -0.594000, 
-0.055880, -0.218700, 0.049740, 1.123760, -0.231470, 1.096130, -1.255860, -3.002300, 2.438200, -0.185570, 
-1.654220, 2.310110, -0.034170, 1.265080, -2.764150, 2.824900, 0.982800, 4.451440, -1.280920, 1.992600, 
5.538350, -0.220500, -0.309140, 0.608040, 2.765290, -2.710580, 1.564690, 0.327400, -0.716850, 0.312430, 
1.323290, 1.632880, 0.223940, 0.603310, -0.366500, 1.587290, -0.435310, 1.306200, -2.442520, 0.013170, 
-0.106550, 0.634950, -2.183070, 1.173620, 3.300640, 0.051550, 0.038040, 0.602370, -0.163960, -0.150220, 
0.322660, 0.945480, -0.732390, 1.464560, 1.414460, 0.521790, 1.943010, -0.389760, 3.032340, 5.286030, 
4.509120, -1.319860, -0.535620, -3.145710, 0.452330, 1.928430, -1.170530, 1.432750, -0.361290, -1.315800, 
-2.130240, 1.009450, -1.012610, -2.278880, -0.801350, -0.679320, -0.029550, 1.056900, -0.759230, 1.730110, 
-3.366560, -0.578860, -0.177150, 0.496440, -3.106540, -3.012120, -0.595110, 0.450350, 0.666820, 0.714900, 
-1.559310, 1.211310, -0.261900, 1.196990, -0.268630, 1.911620, -0.379170, 1.186660, 6.793310, 0.037860, 
0.462320, -0.227420, -0.517940, 0.160160, 0.552390, 1.237650, -0.808570, -0.439770, -0.555570, 2.223980, 
0.764090, -0.842410, 1.024570, 1.177680, -0.869650, 1.435840, 0.739520, -0.045700, 1.216830, 0.490120, 
0.988300, -3.510670, 0.833730, -0.925340, 3.028790, 0.703450, 1.056040, 1.960810, 1.257530, 0.401350, 
-0.846010, -0.914420, -1.451540, 1.795960, -1.560880, 1.536910, -0.367090, 3.164620, 0.453360, -1.479620, 
-0.480500, -0.795210, 0.266130, 15.759500, 0.071930, 0.258620, 0.912630, -0.133270, -1.350290, -1.869910, 
0.743080, 0.012080, 2.277390, 2.947220, -2.506680, 3.706240, 0.265180, -0.814160, -1.496970, 0.687360, 
-0.373080, -0.639240, -0.797050, 0.398280, -2.173280, 0.421740, -0.047790, 0.205890, -0.144870, -1.186560, 
-0.111960, 4.470780, 0.697810, -0.051810, 1.594290, -0.280800, 1.612830, 1.097800, -0.278990, -0.778010, 
0.056790, -0.086970, 0.188250, -0.507550, 0.930190, -0.513620, -1.905570, -0.497520, -0.100840, 
1.465560, 0.477760, 1.907610, -0.118740, -0.811140, 1.358280, -1.875730, 0.182800, 0.537560, 0.832230, 
0.480190, 1.589300, -0.207100, 0.128030, 0.854290, -0.268980, -0.313870, -0.232090, 0.342240, 1.025480, 
-0.584100, -0.691990, 0.984960, 1.421970, -0.863110, 2.045580, 2.120020, -0.622110, 1.455400, -0.704680, 
2.442250, 0.656590, 1.381750, -0.565110, -1.764350, 0.530260, 0.349450, 0.116040, -0.190490, 0.751500, 
0.652770, 0.985630, 1.059690, -2.253480, 0.350320, -0.963250, 0.815130, 0.310960, 2.252350, -0.469280, 
1.269350, 1.002160, 1.274020, 0.379490, 1.639070, -1.952350, -1.150940, 0.733700, -0.605650, 0.692270, 
-0.092820, -1.059010, -1.137240, -1.488760, 0.384560, 0.603060, -2.349610, -0.248480, -1.395840, 2.600510, 
1.493070, 0.727750, 0.057130, -0.220510, 0.188170, -1.423040, 2.074880, -1.644780, 0.823560, 1.218980, 
1.112280, 0.476770, 0.354060, -0.913850, -1.580830, 0.047570, 1.530640, 0.919880, -1.363060, -0.780340, 
0.116290, -3.589950, -0.801770, 0.818230, -0.000560, -1.517710, -1.939960, 3.198830, 0.621010, 1.409680, 
-0.103550, 0.054030, 0.980320, 1.076990, 0.693160, 2.094830, 0.122370, -0.818900, 1.141340, 3.106660, 
0.337700, -0.015250, -1.660740, 1.443890, 0.154500, 0.081420, 1.520580, 1.306300, 0.082310, -1.252200, 
1.190350, 1.237840, 0.196180, -1.703460, -1.325170, 1.055560, -0.098430, -0.413990, 0.080940, -1.896170, 
1.539410, 1.196800, -1.352010, 1.374000, 1.516070, 1.221520, -0.357670, -0.309090, 1.464930, 0.909160, 
0.084050, -0.710780, 1.331710, 1.592860, 0.858300, -0.051530, 1.437560, -1.372140, 0.758270, -1.332000, 
-0.752920, 2.222120, 1.205130, 0.948350, -1.353080, -0.139440, 0.048220, 0.841110, -0.735030, 3.768160, 
-0.963450, 0.926550, -0.023270, 0.562720, 2.834610, -2.305540, 0.412430, -0.309110, -0.419470, -0.071970, 
1.026630, 0.182700, 2.108500, 0.348420, 2.015910, 1.121940, 1.316870, 0.829600, 0.228020, 0.073410, 
1.958970, -1.667770, -0.663020, -0.877260, 1.588520, 0.917840, 0.852940, -1.195930, 1.856980, 1.392400, 
1.042590, -0.355750, -0.271460, 1.781680, 0.699900, 0.871370, 0.404890, 0.538570, 0.425770, -1.407370, 
-1.059480, 0.189000, 0.838740, 1.099250, -3.554020, 0.668960, 0.585400, 0.430690, 2.070470, 0.729160, 
-0.052350, -0.019030, -0.106670, 1.048580, -0.473390, 0.530140, -0.762100, 0.091360, 0.631640, 0.118420, 
1.396890, 0.699310, -0.700920, -0.457810, -1.017200, 0.286380, 1.190880, -2.057180, -0.659290, -0.540130, 
-0.291360, 0.835090, -0.083230, 1.019880, 0.481570, 2.937850, -1.487410, 0.724440, 0.457930, 1.456190, 
2.418060, -0.113450, -0.025370, 0.094370, 1.408570, 5.218540, 0.010690, 1.779670, 0.084550, -0.432920, 
-3.614040, 0.405810, -2.631090, 5.330520, -0.187250, 1.913710, -0.479690, 0.362690, -0.026330, 1.327630, 
0.047130, -0.580390, 0.915400, 0.310240, 0.636570, 1.137530, 1.286920, -0.596180, -0.407450, 0.301430, 
-0.703750, -0.604070, -0.589050, 1.032080, -2.766500, -0.155500, 0.216160, -1.008760, 0.226760, -0.933410, 
-1.340390, -0.674940, 0.312650, -0.861820, -1.038290, -2.158990, -1.327500, 0.299030, -2.408920, 0.456110, 
1.186940, -1.609120, -0.203540, -2.240360, -0.876810, -0.446760, 1.422740, 0.132280, -0.797130, 
-1.991410, -0.299830, -2.869250, -1.196170, -0.829460, -0.175220, -0.745220, 0.377400, -0.352150, -0.508580, 
-2.067630, 0.244010, -1.907370, -0.811320, 0.923790, 0.485770, 1.769210, 0.143300, 3.129330, 3.610620, 
-0.360070, 0.952910, 4.135400, -0.456120, 0.167360, -1.325740, 1.084290, -1.707750, 1.552250, -1.105030, 
-2.142050, 0.522520, -1.720120, -1.357870, -0.307280, -0.684070, -1.981840, 0.433390, 1.987800, -0.259950, 
-1.244790, 0.865170, -0.056660, -0.409860, 1.040050, 1.674750, -0.243800, -0.550870, -1.416060, 0.367510, 
-0.275560, 0.165850, -0.907260, -0.548390, -2.352110, 1.291910, -1.349140, -0.715220, 0.565060, 0.385030, 
0.108030, -0.918200, 1.589860, -0.310450, -0.417530, -0.972420, 1.475990, 1.182740, -2.563210, 0.704370, 
0.101710, -1.268470, 0.608090, -0.591060, -0.722450, -0.969610, -2.500110, -1.266860, -1.289810, 0.553600, 
0.155560, 0.192320, 0.743510, -0.802370, -0.427770, 1.277250, -0.255640, -1.394110, 1.755840, -0.613320, 
1.109370, 1.021120, -2.260460, -0.659630, -0.593500, 0.482440, 0.134510, -2.479940, 0.607460, -3.320470, 
-1.401780, -0.004920, 0.590140, -1.325620, 0.827590, 2.996400, 1.223570, -0.174100, 0.188240, 0.531350, 
0.741920, 1.831290, 0.361680, -1.067240, 3.311250, 0.271450, -3.614140, -7.711430, 1.376540, -20.292130, 
0.703850, 2.083020, -2.414700, -5.067290, -5.670770, -0.282390, 0.089440, -2.232760, -5.070470, -1.874160, 
-1.373310, -1.742860, -18.241020, -0.925440, 0.429880, -3.367490, 0.814590, 2.152560, -0.446850, 1.468320, 
0.734930, 0.131170, -1.593230, -1.321510, -1.459180, 0.473070, -2.161250, -1.179250, -1.122090, -2.045450, 
-1.651800, -2.883360, -1.307730, 0.260760, -3.061770, -1.231780, -0.787920, -0.329230, 0.356660, -0.210990, 
5.874400, -1.912440, -2.079700, 0.527840, -0.078300, -0.072320, -1.070930, 0.171680, 0.657960, 1.295090, 
-0.217040, -0.844990, 1.890530, -0.169740, 0.534300, -0.494190, 0.436210, 2.336800, -0.904420, 0.973220, 
3.195940, 0.909990, -0.931430, 0.103560, 0.760750, -1.431610, 1.886210, 4.310010, 4.607820, -1.563790, 
-0.139150, 0.831600, -1.469910, -4.647880, 0.656590, -2.445100, 1.675120, 0.270230, 0.300970, -1.291970, 
3.248630, 5.308430, 2.828180, 2.337050, 1.863600, -6.195010, -0.673820, -0.135890, 0.011950, 0.472200, 
1.443050, -1.182940, -0.376140, -1.010260, -0.773710, -0.831750, -2.977180, -0.023190, -2.600170, -1.315420, 
0.395400, -0.972490, -1.512440, -0.846170, -0.914460, 0.643490, 1.104020, -0.538990, 0.705860, -1.328730, 
2.563870, 0.391030, 0.112950, -0.600360, 0.366530, -1.625960, -0.082230, -1.829300, 1.990760, -0.410580, 
2.002870, 1.761920, 0.520150, 0.453580, -0.183890, 0.343060, 0.129390, 0.149030, -1.451500, 1.548680, 
1.138740, -0.675510, 0.587690, -0.755580, -0.862860, -2.171730, 1.200650, 1.706240, 0.785760, 0.909800, 
-0.076670, 1.548810, -2.015450, 2.182360, -1.076450, 1.045760, -0.733450, 1.676370, -0.437100, -0.870250, 
-0.026340, -0.374590, 0.534400, -0.837140, 1.228020, 0.235420, -0.896670, 0.212120, -0.111100, 0.346500, 
0.332120, -0.953030, 0.413750, 0.257270, -0.149510, -0.960320, 0.742400, -0.849310, -0.925650, 0.643690, 
-2.612000, -0.950710, -0.956880, -0.452530, 1.104950, 0.398880, -0.701260, 0.682300, -0.548730, 
0.250560, 2.195270, 1.645730, -0.346390, 0.573690, 0.234860, 0.785780, 0.660450, 4.159280, -1.485110, 
1.625430, 0.682530, -0.024920, 1.474490, 0.326210, 1.148380, -1.697650, 0.018400, 0.784520, -0.256220, 
-0.151080, -0.258450, 1.554990, 0.461610, -1.087540, -1.517520, 1.473540, 1.076280, -1.986590, 0.988620, 
-3.023780, 1.204500, -4.939030, 0.895900, 1.409700, 0.150230, -0.326660, 1.746050, -0.343900, 1.613530, 
-5.139870, 0.194570, -0.864000, 0.899530, 2.152900, -0.483700, -0.221960, 1.388360, -0.177900, -0.978030, 
-0.128800, 0.235720, 0.299080, 0.497040, -1.307940, 0.908150, 0.198120, 0.677340, 0.710290, 1.405710, 
0.839920, -0.236520, 1.275060, -0.535900, -0.083870, -0.712540, -0.503820, 0.691140, -0.639260, -0.728730, 
0.555400, -0.866640, -0.655100, 0.113770, 0.924230, 1.600860, 1.540250, -1.443240, 0.222340, 3.462090, 
1.308220, 0.503820, -0.113820, -0.490000, 1.025170, 0.605730, -0.874910, -2.012640, 1.008650, 0.462370, 
-2.420910, -0.175660, -0.821880, -4.378570, -2.945130, -0.378340, -0.283440, 0.595950, -0.832100, 2.265210, 
0.149440, -1.817260, 1.965110, 0.742180, 0.470430, 1.171760, 0.653360, 1.455540, 0.966350, 1.188050, 
0.707430, 1.219720, 0.461570, 0.142360, 0.580040, -2.498060, -7.673360, -1.725390, 0.957770, -3.477450, 
-0.047470, 1.989180, -1.336980, -1.519890, -4.704330, -0.003190, 1.448460, 1.348220, -1.367850, 0.490400, 
0.675910, 1.698680, -3.623470, 0.318240, 1.520120, -3.152190, -1.191720, 1.208850, -0.335440, -0.908460, 
1.099150, -0.365520, -0.678770, 0.429820, -0.507760, 1.402790, -0.563290, -0.593750, 0.261050, 0.633050, 
-0.296170, 0.700480, -0.949870, 1.207300, 0.144220, -0.146290, 1.180380, 0.051610, 0.184100, -1.130290, 
1.185940, 1.232810, -1.570450, -1.792830, 0.097580, 0.424860, -0.681690, 0.989260, 2.355830, 0.736030, 
-1.308960, 0.174250, 0.942830, 1.393800, 3.421490, 0.695440, -1.668950, 2.390580, -0.007030, -0.770690, 
1.226050, 0.725270, -1.123870, -0.728620, 1.267530, -0.071150, -0.995170, -2.251170, -2.309530, 3.354550, 
0.842830, 1.924790, -0.643860, -1.161450, 0.868680, 0.530230, -0.327090, 0.369730, 0.341190, 1.291940, 
-0.856560, -2.244400, 0.480130, 0.864980, -0.180680, 0.651070, 0.162410, 1.911790, 1.076200, 0.554550, 
3.023960, 0.260990, -2.295090, 1.865130, 0.459240, 0.560590, -0.156870, -0.374910, -0.781850, 0.320870, 
-0.264020, 0.139780, -0.312470, -0.281620, 0.762430, -0.758250, -0.369400, -0.012800, 0.210510, 0.278520, 
0.691820, 0.089230, -2.335190, -0.802790, 0.561640, -0.379580, 0.604220, 1.080020, -0.020890, -2.075150, 
1.267040, -0.784490, 0.157730, 2.758030, -0.656510, 0.306670, -0.606170, -1.150830, -1.297880, -0.160890, 
0.181770, 2.209250, -0.458990, 0.515590, -1.147940, -1.433710, -0.279920, -0.721350, -0.349820, 0.535430, 
-1.220570, 1.515850, 1.513850, 0.839630, -0.593860, -0.522070, -0.980110, 1.505300, -0.909640, -0.360010, 
0.035140, 0.916820, -0.502770, 0.453070, -0.487720, -0.045490, -0.976590, 0.044850, 1.069060, -0.202290, 
0.041330, 0.466620, 0.146790, -0.884090, -0.847400, 0.353320, 0.849610, 0.533750, -0.254660, 0.136310, 
-1.881380, -0.510950, 1.588830, 0.956880, 1.186950, -0.772850, 0.390260, -0.131410, -1.585480, 
-1.516760, -0.437350, -2.054790, 0.952380, -2.083890, -0.385310, 0.972490, -0.210350, -0.559060, -0.437240, 
0.019550, 0.747550, -0.811250, 1.469400, -2.945560, 0.805380, 0.981230, -1.632430, 0.594140, -1.484760, 
2.949540, 1.549490, 1.638320, 0.916820, 0.518670, 0.326440, -1.969570, 1.480420, 0.706130, -2.698550, 
0.814290, 4.012180, -0.274680, -0.814820, -0.124870, 0.260480, 0.401960, -0.181150, 1.299930, -0.625420, 
-0.495620, -0.063980, 1.368510, -0.834460, 0.093010, -0.643050, 2.110830, -1.562200, 0.463740, 0.949870, 
0.641860, -0.036160, -2.732450, 1.980950, 2.937190, -0.352680, -1.527010, -2.228600, -1.114110, -0.269470, 
0.307990, -1.558500, -0.317680, -0.398150, -0.741820, 0.818780, 0.991030, 0.732130, 5.249840, 0.115300, 
2.049010, 0.121180, -1.368250, -1.803460, 1.988000, -1.797610, -0.829520, -0.745570, 1.159490, -2.278480, 
-0.204060, 1.613250, 0.778750, -0.246460, -1.912350, -1.495520, 0.497670, -0.112280, -0.657020, 0.894440, 
0.097620, -0.838300, -1.144050, -0.816550, 0.051120, -2.428160, -1.345180, 1.262630, -0.895710, -0.936490, 
-1.431580, 1.229800, 0.369370, -0.083820, -1.012240, 1.106490, -0.646220, -0.818890, -0.363080, 0.261270, 
-0.329360, -1.676580, -0.156410, -1.316880, -0.175650, -1.540510, -2.538250, 3.373820, 1.369640, 0.365900, 
0.540070, 1.565020, 0.801960, 3.244330, -0.376320, 0.396640, 0.867260, -1.113290, -1.907350, 9.259580, 
0.889450, -0.484100, -0.212290, 0.009880, 0.678560, -35.436710, -4.710710, 0.390610, -0.360540, 0.078580, 
0.753320, 1.155060, -1.576460, 1.016340, 0.717710, -0.311820, -1.230570, 0.641150, -0.420850, -0.958700, 
0.713670, -1.213530, -1.955700, 0.010050, 1.309370, -0.659430, 0.338860, 2.125530, -0.369680, 0.434800, 
1.211600, -0.029720, 0.592510, 0.793790, 0.724850, -0.744620, -0.456540, -0.290250, -2.560520, -0.865220, 
-1.646750, 0.803480, 0.458720, 0.011540, -1.844680, 1.230430, 1.462660, 1.189730, -1.002400, -0.973440, 
-0.111090, -0.144940, 0.560820, 0.097710, 0.471700, -1.735160, -1.156930, 1.934380, -0.338590, -1.062460, 
0.754870, 0.189520, -0.450600, -1.219760, -0.466070, -1.324480, -0.512160, 0.082350, -1.539950, -0.597080, 
-0.380860, -0.579650, 0.335740, 1.155260, 3.774620, -0.837980, 1.493770, -0.322310, -0.590660, 0.071760, 
-0.722660, -2.097550, -0.788760, 0.872240, -1.629840, 1.521670, -0.077730, 1.161330, -0.247690, 1.205200, 
0.178840, -0.593260, 0.972550, 0.691500, 0.897590, 0.467640, -0.399810, 1.796460, -0.861720, 0.518510, 
-0.442740, -0.145410, -0.985570, 0.599050, -1.212430, 1.793670, 1.679530, -1.352500, 0.701990, -0.685610, 
-1.419590, -1.111040, 0.574510, 1.043960, -0.362140, -0.737180, 0.606920, 1.475900, -0.309820, 0.864460, 
4.689010, 1.091050, 7.483220, 12.352530, 0.831640, 0.730720, -0.429830, 1.578090, -4.242680, 2.878820, 
0.625120, 0.355840, 0.453420, 1.341710, 1.284430, 3.911030, -1.392500, 0.622050, -1.598270, -0.615020, 
-2.778600, -1.255650, -1.166690, -2.551120, -0.572450, 0.379330, -0.490610, -1.809010, -0.294840, -0.192980, 
-0.870360, 0.093350, -0.472620, -0.925430, -1.812750, 0.702870, -3.731170, 0.810650, -2.318910, -0.081760, 
-0.697860, -0.120300, -2.668250, -0.672810, 0.399490, -0.637560, -3.046980, -0.329700, -0.700470, 
0.932400, 0.284750, -0.760230, 0.012640, 0.896280, 0.838250, -0.697750, -0.295070, 0.524840, 0.850630, 
-0.022870, 0.094950, -0.435390, -0.059800, 0.085080, -0.083330, -0.072540, 0.670240, -1.334230, -0.380600, 
2.083430, 0.421920, -0.683100, 0.561130, -0.332460, -0.174300, -0.346750, 0.973880, -0.442130, 0.222370, 
0.013220, -0.010200, -0.186860, 1.036660, -0.235870, 0.478130, 0.201370, 0.723830, 0.581800, -0.296790, 
-0.945660, -1.004470, 1.064910, 1.344200, 0.235280, -1.095260, -0.813790, -0.234690, 0.181590, 0.333970, 
-0.864150, -1.690980, 0.999010, 0.370750, -0.395850, -1.096120, 1.311200, 0.940450, 0.294500, -0.056940, 
0.441840, -0.119980, 1.296760, 0.634920, -0.074870, -0.035570, -0.183790, -0.426980, 0.824900, 0.923260, 
-0.385190, 0.925430, -0.313310, 0.195340, -1.842570, -0.685910, -1.091840, 0.040570, 0.342970, 1.071920, 
-0.248180, 0.091950, 0.282080, -0.522390, 0.202240, 1.182310, 0.127180, 0.328240, 0.700450, 0.333240, 
1.472460, 0.712980, -0.614710, 0.518900, 1.590000, -0.572090, -0.068660, -0.489960, 0.669740, 0.873900, 
0.965820, -0.418470, 1.017940, 0.069830, 0.306330, 0.651830, 0.461500, 0.988670, 0.533170, -0.235670, 
-0.334050, 2.364760, -1.926760, 1.447840, -0.385430, -2.460040, -0.066460, -0.793660, 6.175690, -4.661130, 
0.556640, 2.680390, -1.089210, -1.707450, -2.415610, 1.008680, 1.260320, 0.287320, 0.799820, -1.484740, 
-0.616730, 0.704370, 1.273930, 0.121330, 1.054910, 0.401660, 0.066760, -1.136540, 1.956920, 0.290620, 
0.421070, 0.610060, 0.329910, -0.384450, 0.078570, -1.124340, 0.039710, 0.339270, 1.144530, 0.098530, 
0.682030, -0.367070, -0.175090, 1.253290, 0.856060, 0.765100, 0.174860, 0.933440, -0.682570, 1.173710, 
-1.025320, 0.969660, -1.009160, 2.008730, 0.455060, 2.717890, 1.280970, 1.010430, 0.020800, 0.679270, 
-0.246830, 1.441670, -0.483260, 0.656550, 0.326360, 0.231570, 0.539350, -1.214360, -0.398490, -0.363090, 
-0.158820, -1.091070, 2.408200, 0.648730, 1.113460, -0.400010, 0.698440, 0.133590, -0.095500, -0.006260, 
0.732250, -0.265190, -0.278540, 0.632440, -0.334470, -0.008520, 0.083890, 1.065610, 0.192870, 0.919660, 
-0.153010, -0.299550, 0.010990, -0.224390, 0.738020, 1.246550, -0.158660, -0.112820, -0.341910, -0.322830, 
-0.419760, -1.044660, -0.329910, -0.365120, 1.238130, 0.797860, -1.494740, -1.436150, 1.001680, -0.561270, 
0.205590, 0.270800, 0.401950, -0.562460, 1.591060, 0.324340, -1.831070, -0.673230, 0.190360, -0.550860, 
2.695200, 1.153920, -0.603280, -0.718590, 0.158650, -0.795330, 0.889750, 0.590310, 0.782610, 0.013140, 
-1.077950, 0.924120, 0.998100, 3.155670, 0.295750, -0.636180, 1.020270, 1.505110, -0.609570, -0.365420, 
0.494850, 1.256980, 0.509930, 7.458540, 0.086480, -3.944680, 0.212720, 0.610820, -0.013200, 1.800880, 
-0.957080, -1.267470, 2.053700, 2.664090, 0.367970, -0.513940, -0.270160, 0.940960, -0.866160, -0.191760, 
-0.765750, -0.476070, -1.441240, -1.584140, -1.526690, -2.126140, -1.478920, -1.693240, -2.046800, -4.858300, 
-1.175820, -1.970480, -0.933840, -0.529380, -0.566750, -0.409730, -0.692500, 0.158180, -1.903290, -1.687970, 
-0.614860, -0.646500, -0.138970, 2.451510, -1.066940, -2.333170, -0.491510, -0.677660, -3.043360, 
-0.117380, -0.626220, 0.576880, 1.217330, 0.193970, -0.329350, -0.433660, 0.083200, -0.280900, 1.317720, 
1.389850, 0.360830, -0.349480, -1.759020, -0.691530, 0.869190, -0.743840, 1.238290, 0.516540, -0.917920, 
0.634410, -0.452610, -0.399140, 0.322400, -0.797850, 2.010380, 0.053780, -0.207010, 1.143900, 1.341770, 
-0.909380, -0.158980, 1.474890, 1.094990, 0.651300, -0.872230, 0.326140, -1.035870, -0.872280, 0.284380, 
-0.325180, 0.347930, -0.759400, -0.159730, 0.277820, -0.997830, 0.604970, 0.397050, -0.458440, -0.365290, 
0.137820, -0.881170, 0.955570, 1.085520, 0.795460, 1.621920, 1.937960, -0.117510, 0.198910, -1.188260, 
0.240720, -1.475180, -2.150610, 0.591850, -1.904580, -0.762880, 0.116530, -0.326680, 1.201390, 1.263000, 
0.726740, -0.444680, 0.632840, 0.167520, 0.894210, -0.177660, 0.278360, 1.222340, 1.093490, -0.100360, 
-0.093060, 0.184420, -1.877620, -1.143810, -0.460650, 1.399310, 0.351490, -0.797510, -0.360080, 0.637870, 
-1.372520, -0.014010, -0.817230, -1.746520, 0.051100, -0.701220, 0.071300, 1.508340, -0.292650, -0.835970, 
2.749870, 0.807580, -0.490780, -1.625710, -0.852860, -0.181570, 0.421370, -0.352630, 0.639320, 1.448450, 
-1.383110, -0.466560, 0.656610, -2.990960, -0.613950, 4.352350, 4.962880, 2.415180, -0.761530, 2.030460, 
2.265840, -4.104670, 0.032250, 4.637510, 1.910710, -0.434140, 0.304850, -1.007010, 2.509830, 1.538950, 
1.058240, -1.186810, 6.739730, -1.258370, -0.280560, 3.671100, 1.215590, -1.012410, 0.247550, -1.126940, 
0.979900, 0.342740, 0.832960, 0.466120, -0.252280, -2.099430, -0.576060, 2.001670, -0.841070, -0.031650, 
-0.890430, -0.364660, -0.268860, -1.033920, -0.077620, 0.464220, 0.152670, -0.964630, -0.734500, -2.148010, 
1.174530, -1.240400, -0.298320, 0.715230, 2.149250, -1.623350, 0.244220, -1.452590, 2.396500, 0.546190, 
2.375070, -1.738740, 0.112880, -0.193880, 0.281130, 1.161860, -0.644900, -1.133230, 0.733500, -0.066280, 
-1.753320, -0.614480, 0.470610, 0.159070, 0.667070, -0.010150, 1.692690, -1.225190, 0.121030, -0.258880, 
0.864600, 0.062770, -1.364910, 2.582440, 0.075640, -0.107430, -0.885520, -0.263310, -0.682030, -0.188250, 
0.677730, 2.565030, -3.224260, 0.443810, 0.267440, -0.331120, 0.403830, -0.311970, 0.269510, -0.215650, 
-0.711200, 0.138330, 0.643980, 0.000470, 0.380200, 0.077500, 0.491170, 0.016100, -0.453030, 0.427970, 
-0.838940, 0.404670, -0.501120, -0.094130, 1.145810, -0.598860, 0.009910, 0.152510, 0.367610, -0.389150, 
-0.758760, 1.054090, 1.692260, 0.332070, -0.751960, -0.823690, -0.511090, -0.224740, -0.683880, -0.718590, 
0.730300, -0.502120, 0.325110, -0.589450, 1.963840, -0.845720, 0.453890, 0.033590, -0.411370, -0.822460, 
-1.115280, -0.575180, 0.014600, 3.020610, -0.519160, -0.792850, 0.641560, 0.263790, 0.511520, -0.447610, 
0.006900, -0.390050, -7.665920, -1.390830, 0.281390, 1.974950, -0.356620, -0.675330, -0.110990, 0.083300, 
0.557640, 0.245000, -0.943970, 0.767860, 0.455770, -0.546440, -0.522420, 0.411000, 0.153520, 1.461010, 
-0.266430, 0.606420, -0.780520, 0.634360, 0.668800, 0.293390, -0.348820, -0.374420, 1.166340, -0.291180, 
-0.938060, 0.592150, -0.128150, -0.251530, -0.950480, -0.917810, -0.376550, -0.491550, 0.664140, 
1.314000, -0.432240, 1.657340, -0.069190, 0.006060, -1.608610, 0.803470, 1.661940, -0.704200, 1.165390, 
-1.097330, 0.114020, -0.586290, -2.243970, -0.469820, -0.756190, -2.141850, 0.783840, 1.658180, -0.894150, 
-2.810360, -0.521810, -1.700840, 0.419420, 1.223030, 1.419750, 0.389860, -0.046620, -0.804350, -0.593910, 
0.003430, -0.831160, 1.211270, 0.711700, 0.127530, 1.370690, 0.832540, 1.342340, 0.968980, -1.302880, 
-1.121580, 0.160900, 1.946640, 0.529550, 1.238550, -1.945520, 0.027110, 0.144740, 0.087530, -0.471020, 
0.794910, 0.286490, 0.261930, 1.275960, 0.661140, -1.223400, -1.585830, -0.757210, 0.988580, -1.154170, 
-1.204860, 2.122660, -0.622790, -0.529380, -0.607870, 1.037270, -3.145220, -0.501750, -0.031590, 2.077470, 
-0.810270, 0.665410, 0.172780, -0.086490, 1.017330, -2.829790, 0.313570, -2.219740, -0.200290, -2.620820, 
-0.742980, 0.244800, -0.868140, -0.542850, 0.147050, -1.579810, -1.390190, 0.649270, 2.083040, -2.258670, 
-0.652230, -1.054860, 1.577070, 0.956260, -0.640250, -0.282110, 1.241930, 0.412030, 0.798630, 0.947210, 
0.178300, 0.578150, 0.435070, -0.952860, 0.064670, -1.620870, 0.426100, 0.275790, -0.934850, 1.827950, 
-0.356660, 1.201610, -4.739450, 0.807660, 0.387720, -0.695890, 1.972510, 0.841480, -0.454400, 1.063180, 
-0.213780, -1.020360, 0.731210, -0.947970, -0.676730, -0.139100, 1.547890, 2.931180, -0.552960, -1.521800, 
7.712390, -1.015050, -1.362140, 0.586020, 0.460590, 4.965970, 0.640230, 1.379510, -0.489730, 0.637400, 
-0.157380, -0.604450, 0.183310, -0.236470, 0.281990, 0.739950, 0.364510, -0.137890, 1.119970, -0.223220, 
-3.372440, -1.179860, -0.046890, -0.046400, -0.757270, -0.392420, -0.370650, 1.931920, -7.190640, 0.658670, 
0.180360, -0.149330, -0.419120, 0.055240, 0.003990, 0.748240, 0.644870, -0.438240, -0.340140, 0.232190, 
-1.147070, -1.263030, -0.770530, 0.390110, 0.678880, 1.801910, 1.808790, 0.297930, -0.685510, -0.728780, 
0.406000, 2.666130, 0.886770, -1.299320, -0.601230, 1.129410, 1.263810, -3.973060, 0.622180, 1.843320, 
0.010780, -0.333030, 0.166560, -1.830370, -0.327390, -0.756520, 0.863740, 0.819380, 0.922670, -0.469460, 
-0.218780, -0.755310, 0.225430, 1.110570, -1.149990, 1.424130, -1.575120, -0.477150, 0.791830, 1.304170, 
-0.890550, -0.370230, 2.096830, -0.461170, 0.378760, -0.262020, -0.440100, -1.430740, -0.746940, -0.258700, 
0.837190, 0.401240, 0.345690, 0.782940, 0.424180, -0.625290, 1.040960, 0.227960, -1.833830, 1.581220, 
0.189340, 1.578680, 1.959810, -0.105850, -0.296110, -0.320870, 0.075300, 1.040330, 0.776320, 0.949820, 
1.274340, -0.536350, 0.465080, -0.459120, 1.028450, -0.610610, 0.414230, -0.085900, 1.097320, -1.624110, 
0.218990, 0.669490, -1.529680, 14.052390, -0.825000, 0.263420, -2.188810, -0.693680, -0.095710, 1.011160, 
-0.964220, -0.502190, 0.943760, 2.356210, 1.582190, 2.261420, -0.402160, 0.080780, 0.144120, -1.032660, 
-0.776580, -0.946060, 0.740920, -0.391660, -3.290320, -0.229980, -0.121900, -0.665240, 0.125150, -0.777000, 
-0.740330, -0.735530, 0.142120, 0.033510, -1.841160, -0.475790, 0.571020, -1.539360, -1.914870, -0.477500, 
1.419490, -0.816780, -0.990040, -1.960600, -1.124940, -0.552150, 5.180140, -1.084580, -0.396020, 
1.569670, -0.537820, 0.763650, -0.039750, 0.699400, -1.572130, -0.550060, 0.308930, 0.391280, -0.469990, 
0.938200, 0.142340, -0.451840, 1.279450, -0.144130, 0.618970, -0.591840, -0.067330, -1.612320, 1.322260, 
1.194330, 1.183150, 0.911820, -0.086520, 2.003100, -0.284230, -0.036870, -0.720650, 0.716590, 0.685530, 
0.956210, -1.521480, -0.277610, 0.662540, 0.014270, 1.908960, -0.432240, -1.286380, 0.450870, 2.725410, 
-2.061030, 0.251760, -0.227800, -0.484340, -2.393640, 2.791770, -1.062030, -1.593920, -0.191290, -0.368370, 
-0.313670, -1.032450, -1.278380, 0.321910, -0.517380, -0.390120, 2.636290, -0.889240, 0.213870, -0.277330, 
-3.606800, 0.465550, -0.703400, -0.948760, 0.122670, 0.891160, 0.865610, 0.120710, -0.759340, 0.022680, 
1.001080, 0.121640, -0.019710, 0.814300, -1.093890, 0.640000, 0.277760, 0.207370, 1.688330, 1.844870, 
1.533940, -0.216330, 1.246640, 1.164110, 1.568090, -0.890450, 0.420290, 0.348180, 1.927380, -0.603520, 
-0.592150, -0.375380, 0.106110, 1.505030, 0.544160, -0.876890, -2.078420, 0.603800, -0.802570, -1.016590, 
-1.722090, 2.869750, 0.571530, -1.413470, 0.142430, 2.067370, 0.361210, 0.290910, -2.615510, -1.034290, 
-1.462800, 1.971460, -0.068690, -0.858370, -1.779080, -1.123080, -1.592960, -0.976120, -2.652840, -0.631770, 
-1.527610, -0.324080, -0.599040, -0.001740, -0.948200, 0.148010, -0.365370, 2.478610, 0.394730, -0.905020, 
3.345500, -0.157150, -0.724150, 0.756160, 0.369290, -1.607280, 1.050180, 0.397250, 0.822550, 0.460930, 
-0.568220, 0.628380, -0.319060, 0.940320, 0.155200, 1.033070, 0.427110, -0.834890, -0.516420, 0.150620, 
-0.356160, 1.826680, 0.601280, -1.074710, -0.464660, -0.400000, -0.875710, 0.066270, -0.914920, 0.367410, 
-0.328650, -0.208610, -2.307970, 0.593900, 0.947020, 1.184040, 0.646220, 1.030580, 1.364580, -0.722980, 
2.391390, -0.429580, -0.655830, -0.352130, 0.889150, 2.018220, 0.577180, 0.322260, 0.357040, -1.332700, 
-1.686240, 0.176330, -4.091000, 0.553830, 0.235850, -0.434060, 0.731590, -0.091740, -0.582890, 0.734790, 
1.992020, -0.125700, 0.768370, 0.189160, 1.561830, 0.873350, 0.858240, 1.018640, -0.256570, -0.154870, 
-2.311810, 0.601010, 0.907840, 0.266470, 0.531590, 0.574380, 0.515600, 0.259790, 0.397540, 0.841310, 
-0.766410, -0.219280, 0.665900, -1.054570, 0.210180, 0.878710, -0.277040, 1.717850, 0.297060, 1.175510, 
0.718740, -0.295020, 1.197930, 1.148090, 0.470240, 1.501890, -0.872550, 1.138150, -1.747240, 0.810630, 
1.711710, -0.019560, 0.462420, 0.211820, -0.283590, -0.597190, 0.345300, 1.648000, -0.308840, 1.106060, 
0.941680, 0.534510, 0.634810, 1.509590, 0.413410, -0.011250, 1.268280, 0.479350, -0.188790, -0.008790, 
1.167200, -0.151160, 1.695910, 1.960800, 0.216360, -0.970460, 1.272450, -0.038570, 0.487350, 0.669850, 
4.506960, 0.613530, 0.573350, 0.819650, -0.465260, 0.501410, 0.811210, -1.647250, 0.514270, -0.361320, 
0.203630, 1.018340, 0.241840, -0.334190, 0.415140, -2.585370, -0.169810, 0.434890, 0.039720, 1.756880, 
0.299110, -0.487030, 0.633660, -0.032530, 1.158350, 1.402630, -0.139860, -0.144120, 0.507260, 0.154920, 
-0.974820, -0.781070, 0.276570, 0.216140, -0.802090, 0.004310, 1.275650, 0.605870, 1.824480, 
1.825570, 0.246200, 1.581780, -1.351320, 1.193900, -0.328080, -0.322240, 0.148570, -1.634320, -0.359800, 
2.105930, 0.185550, -0.823950, -0.266390, -1.148640, 1.031960, -0.537710, 0.499170, -1.189270, -0.023230, 
0.694950, 0.415600, 0.215650, 1.550620, 0.557740, -0.349920, -0.500420, -1.874520, 0.094260, -0.021810, 
0.622800, -1.445610, -0.501600, -0.678520, 1.065820, 0.629480, 0.231780, -0.016350, 1.417930, -0.212170, 
-0.651620, -0.375090, -0.432170, -1.250310, -0.251350, 1.438170, -1.629010, 0.561130, -0.415000, -0.554240, 
1.225230, -0.273830, 0.201640, -0.054260, -1.181610, 0.872930, 1.249200, -0.773290, 0.458240, -0.227240, 
0.274080, 0.022220, 1.626600, 1.333530, -0.315160, -1.487300, -0.649270, -0.074430, 0.004660, 1.051290, 
2.604040, 0.177610, -0.734660, 0.268530, -0.417250, 0.361850, -1.027120, -0.031590, -0.369260, 1.749320, 
0.923430, 0.437180, 1.712370, 0.471690, -0.659600, -0.119920, -0.029350, 0.626340, 0.165600, 0.314650, 
-0.667650, -0.129390, -1.012830, -0.500470, 0.774230, -0.953120, -2.254000, 0.837240, -0.124410, 0.655170, 
0.890850, -0.845180, 0.209650, 0.081070, 1.097800, 1.951740, -0.105610, -0.195210, -0.518690, -0.055040, 
-0.574770, -0.043410, -0.954230, -1.017630, -0.894770, 0.349080, 1.381940, -0.159510, -0.042990, -2.618670, 
0.014940, 0.579220, 0.103660, -0.041520, 1.204350, -0.181700, -2.726320, 0.518560, 1.371680, 0.632150, 
-1.356810, 0.201500, 0.306390, -2.229980, -3.610990, 2.337830, -0.033160, -0.109730, 1.523770, -0.716300, 
1.028900, 0.546450, 0.308790, 0.069570, 0.617420, -0.132570, 2.631320, 0.376770, 2.024830, -0.085460, 
-0.897260, 0.175610, 0.767060, -1.934180, -0.235500, -0.011330, 0.722850, -1.107650, -0.503280, 0.022310, 
-1.139380, -0.588390, 0.723620, 0.442220, -0.958110, 0.361070, 0.183630, 1.123400, -0.685760, 0.357960, 
-0.401600, -0.243550, -1.012340, 0.323960, -0.949630, 0.483680, -0.674470, 0.191090, 1.966800, -0.271150, 
0.116000, -0.022460, -0.497030, 0.047930, 0.172310, 0.070110, 0.603600, -0.557710, 0.208820, -0.122790, 
-0.309180, 0.947800, 0.897210, -1.672060, 0.493060, 0.446700, 0.838150, -1.218190, -1.312800, 0.181900, 
-0.311610, 0.077940, 1.334800, -0.622500, -0.803500, 0.310630, 1.067620, 0.593470, 0.554850, -0.036600, 
2.572630, 0.114890, -2.265040, 0.032770, 1.041290, 0.113720, 0.958580, 1.391880, -0.103450, 1.980190, 
0.782440, -1.913610, 0.538240, -1.151230, 0.526930, -0.385230, 0.502680, -1.040990, 1.969150, 0.640140, 
-0.345860, 0.995690, 0.756660, -0.606360, 0.317370, 0.275620, 0.954400, 0.027160, -1.123790, 0.135520, 
-0.634900, -0.757550, 0.400790, 1.017610, 1.069210, 0.116780, 0.935160, -0.896230, -0.559940, -0.572510, 
-0.890160, 0.636770, 1.200460, 5.736910, 0.897270, 3.160460, 0.665290, -0.438550, 0.758080, 1.868450, 
-1.193290, 0.462090, -0.152900, -0.845050, 6.046930, -2.479310, 1.484190, -2.147480, -0.779730, 0.310370, 
-3.559490, 0.107040, -1.147920, -1.137620, 0.935010, -4.544490, -4.507670, -1.224490, -1.127860, -0.487710, 
-1.241480, 0.011380, -1.106240, -1.601890, -0.724570, -1.458220, -1.247120, -1.467580, -0.583790, -0.899550, 
-0.954070, -1.784840, -1.778680, 1.250420, 0.062810, 0.387570, 2.215490, 0.376680, 0.299330, 
0.642760, 0.609030, 4.132090, -1.003050, 0.119220, 0.788290, 0.852610, -0.060900, -0.540470, 0.092670, 
0.427130, 0.538840, -0.884390, 0.248910, 0.337810, -0.240510, 0.053820, 2.377340, 0.109750, 0.341380, 
0.231820, -0.143490, -0.225910, -1.089350, -0.491300, 6.270060, -0.889920, 0.070590, 0.166360, 0.242650, 
-0.397310, 0.624340, 0.862930, 0.069110, -0.491930, 0.898980, -0.095160, -0.235910, -0.569000, -0.871620, 
-0.447650, -0.646040, 0.838050, 0.896240, -0.230830, 0.250010, 0.526550, -2.520210, -0.211640, 0.406310, 
0.860420, 0.008800, 0.825210, 0.181310, -0.324470, 1.722390, 0.134320, -0.856740, 0.753940, 0.271420, 

-0.657100, 0.675380, 0.543420, 0.124930, 0.676580, -3.737040, -0.022360, -0.967800, 0.361040, -0.497530, 
1.136380, 0.079290, -0.352870, 0.374680, 0.155380, -0.678210, 0.011280, -0.122800, 0.645420, 0.281980, 
-0.148480, -0.527150, 1.517910, 2.848350, -1.615420, -0.605930, 0.269260, -0.485590, 0.246870, -0.962020, 
0.248100, 0.065220, -0.210170, 0.897990, -0.838540, -0.239180, 0.428000, 0.254040, 0.854980, -0.721130, 
0.038370, 0.914190, 0.143440, 0.769420, -0.134530, -1.036080, -0.106390, 0.755070, -0.828210, 0.477470, 
1.006410, -0.176270, -0.758250, -0.231650, -0.740100, -0.523000, -0.439290, 0.527150, 0.425620, 5.041270, 

-0.059720, -0.385260, 0.359910, -0.858580, 0.193970, 0.689310, -0.044850, -1.198060, -0.608500, -0.682550, 
0.256170, 0.712440, -0.104980, -0.032720, 0.359990, -0.600010, 0.771650, -1.038450, -0.103520, -1.044030, 
0.257490, -0.377640, -0.418450, -0.101930, 0.126990, -4.392920, 0.776600, -0.350490, 0.331410, 0.956630, 
0.896140, 0.939560, 0.540610, -0.664790, 0.362580, 0.852170, -0.057090, 1.424570, 0.452100, -0.451280, 
0.710210, 0.581420, 0.119860, -0.436240, 0.111680, -0.615290, -0.038330, -0.506210, 0.193110, -0.321040, 
-0.021040, 0.658270, -0.967460, 0.233090, -0.925210, 0.985950, -0.724890, -0.305450, -0.468790, 2.851200, 

-0.921900, 0.487120, -0.995240, -0.169830, 0.656830, -0.747100, -0.468580, -0.568310, 0.864830, 0.839810, 
1.791570, -0.633370, -0.828740, -0.752010, 0.165190, -0.869280, -0.933400, -0.630550, -0.629600, -1.339790, 
0.429720, 0.474590, 0.095080, -0.429290, 0.473870, -0.682720, -0.135960, -0.412590, -0.336810, 1.444960, 
0.006850, -0.568430, -0.353920, 0.104960, -0.229190, -0.083000, -0.056680, 0.281660, 0.412120, 0.697600, 
-0.117750, 0.703350, -0.655780, 0.350870, 0.017500, -0.262120, -0.279960, 0.588430, -0.210240, -0.792780, 
-0.041390, 0.812910, 0.539710, 0.800420, -0.962430, -0.030190, 0.724460, 0.936150, 0.901360, 0.918630, 

-0.610340, -0.283790, -0.201260, -1.027040, 0.808360, -0.171400, -0.985040, 0.462820, 0.340330, 0.453730, 
0.210670, 0.002860, -0.223320, -0.031510, -0.691670, 0.807360, 0.597830, -0.951470, 0.171160, 0.303720, 
0.817110, -0.166490, -0.900370, -1.146100, -0.145000, -1.170590, 0.927560, -0.656020, 0.323460, 0.626270, 
-0.347180, 0.844480, -1.005450, 0.322410, 0.186410, 2.091930, -0.881050, 0.828230, -0.566460, 0.962940, 
-0.480680, 0.113780, 0.012330, -0.638000, 0.058290, 0.621770, -0.844120, 1.388890, -0.142770, 0.788760, 
0.268480, 0.835950, -0.109360, -0.992600, -0.409520, -0.705970, 0.429670, -0.259050, 0.482090, -3.908860, 

0.841770, -1.258000, 0.123530, 0.786430, 0.035570, -0.203760, -0.102570, -0.375000, 0.252560, 0.114980, 
-0.884320, 0.262340, -0.174180, 1.246410, -0.541740, -2.807460, 0.632210, -0.895940, -0.442140, -0.671880, 
-12.288360, -0.111820, -0.354050, 0.441730, 0.727250, -2.212480, 0.848080, -37.326389, 0.392800, 0.300260, 
-0.741090, 0.591490, 1.025130, 0.376020, -0.036430, 2.969190, -1.106070, -0.637030, 0.278390, 0.480140, 
-1.009860, 0.225430, -1.044180, 0.245060, 0.549160, -0.565310, -0.904650, 0.187090, -0.270550, 0.141990, 
-0.790670, -0.510070, -0.851330, -1.068450, 0.253860, -0.247750, -0.923770, 0.296040, 0.861920, -2.338070, 

-0.783550, -1.752280, -1.165300, -0.076300, -0.639680, 1.939950, -0.876170, 0.455560, 1.036520, 0.605780, 
-0.280020, -0.650230, 0.293910, 0.856590, 0.867760, -0.223390, -0.473640, -1.110230, -0.663680, 0.862600, 
-0.477380, 0.763750, 2.262950, 0.862740, -9.386230, 1.423590, 0.527140, 0.457640, 0.317200, -4.066140, 
-0.946520, 0.539240, -1.087090, 0.309470, 0.317750, 7.699780, -0.775700, 1.863650, -0.810070, 0.087530, 
1.924690, -0.236200, -0.849430, -1.058350, 0.185430, -2.686980, -0.989010, -5.178930, -0.223840, 0.752320, 
0.168690, -0.483980, 0.239560, -0.227620, -0.336180, -0.409000, -0.596580, -0.247170, -0.025960, 4.395580, 

0.777740, -0.160380, -0.039940, -0.834940, -0.940020, -0.863850, -0.686090, 0.086740, 0.931270, -0.424350, 
0.156110, 0.433570, 0.394000, -0.449540, 0.158020, 1.645030, 0.734500, 0.021600, 0.317540, -0.359040, 
1.334930, 0.572040, -0.225780, -0.907810, -0.550460, -0.440290, -0.482340, -0.381300, -0.986730, -0.027960, 
0.865040, -0.282380, -0.562510, -0.631470, -0.120680, 0.835330, 0.412320, -0.812930, -0.211080, -0.456780, 
-0.498860, 0.205070, -0.286860, -0.631560, 0.245270, -0.653080, 0.922870, 1.120670, -0.460420, -0.528730, 
0.687890, -0.533710, -0.644020, 0.456910, 0.001170, -0.954320, -0.940040, 0.161720, -0.306560, 0.264720, 

-0.120790, 0.432350, -0.060090, -0.505570, -0.735210, -0.083640, 1.821200, 0.741790, 0.567090, -0.182690, 
0.122890, -0.854680, 0.853570, -0.310300, 0.364430, -0.348340, -0.083290, 0.133730, 0.174160, -0.357600, 
-0.594790, -0.880900, 1.047500, 0.089620, 0.961320, -0.417760, -0.302730, -0.331420, -0.203060, -0.291900, 
-0.251740, 0.769050, -0.587130, -0.685550, 0.077700, -0.086830, -0.635590, -0.204030, 0.439310, -0.017580, 
-0.326590, 0.917800, 0.601720, 0.515400, 0.459160, -0.367620, -0.318360, 0.479010, -0.939160, 0.993960, 
0.004870, -0.605740, 0.581770, -0.013140, 0.247800, 0.506210, -0.563630, -0.445350, -0.729840, -0.700970, 

-0.929380, 0.613240, -0.378550, -0.056710, 0.736590, -0.622300, -0.139870, 0.187560, -0.511390, -0.257550, 
0.024290, -1.302670, 0.352020, 3.241660, -0.431580, 9.879620, 0.696800, 1.726590, 2.006860, 0.679290, 
0.567000, 0.553670, 0.049280, 1.504900, 0.726030, 4.197850, -0.733120, -0.994170, 0.541420, 0.059200, 
0.421360, 0.686900, -0.328560, 0.979040, -1.002850, 3.430450, -0.552560, -1.093210, 0.513970, -0.368750, 
0.607970, 0.021400, 0.131070, 1.012230, 0.613160, -0.205830, -0.487120, 0.399700, -0.760610, 0.177710, 
0.074340, 0.388780, 0.452730, -0.849840, -0.587120, 0.237140, -0.201960, -0.439520, 0.114140, -0.680410, 

0.177070, -0.344270, -1.197540, -0.547220, -0.632550, 1.232050, 0.612970, 0.747890, 0.157770, -0.502120, 
-0.335730, 0.085280, 0.535830, 1.741810, 0.792930, 0.105890, -1.665720, 0.243590, -0.577100, -3.429860, 
-0.860080, 1.000990, 0.091340, 0.041400, -0.020870, 1.337730, -0.614030, -0.918360, -1.511130, 0.240930, 
-0.523730, 0.714970, -0.004800, -0.202680, 0.115200, 0.026540, -0.285740, -3.025630, -0.308620, 0.282830, 
0.822940, -0.925120, -0.508030, -0.625760, 1.058490, 0.391060, -0.502670, -1.289860, 0.080920, -0.903400, 
-0.425710, -0.298240, -0.615800, 0.218270, -0.551640, 0.507450, 0.834340, 0.583710, 0.742540, 6.587700, 

0.904750, 0.312590, -0.517530, -0.991740, 0.891040, -0.712670, -0.716530, 1.058490, 1.338420, -0.921470, 
0.050620, 0.871690, 1.620720, 0.442940, -0.552550, 0.589700, 0.630050, 2.105620, -0.480280, -0.211250, 
0.807290, -2.542470, 0.398080, -1.065540, 0.866350, -0.008980, -0.945510, 6.224510, -0.850260, -1.676630, 
0.699710, -0.021870, 0.124980, -0.253810, 0.143580, 1.193580, 3.747020, -1.248670, 0.426310, 0.489870, 
2.035920, -0.648400, 0.706310, 0.309450, -0.484510, 0.058250, 0.838900, 0.153860, 0.162520, 0.457400, 
-0.548290, 0.739410, 0.643390, 0.453370, 0.666040, 0.594040, -0.841980, -0.048780, -0.033620, 4.543760, 

3.359220, -0.107530, 1.155130, 1.397320, 0.379260, 1.306810, 0.206760, -1.643250, -0.226150, -0.298270, 
0.241440, 0.546000, -0.735030, 1.966390, -0.096740, -0.269960, 0.138860, -1.872260, -0.711400, -1.654880, 
-4.559040, 0.202470, 1.274370, 0.055850, 2.019670, -0.731170, -0.165140, -0.947210, 1.158400, -0.414870, 
0.043650, -0.847190, 0.375650, 0.328460, 0.879700, -7.333000, -1.210640, 0.437190, -1.212280, 0.387540, 
2.093010, 1.085290, -1.919500, -0.889040, 0.948230, 1.022280, -1.962130, -0.172120, -0.895760, 0.469650, 
0.551900, -0.101450, 1.060310, -0.080800, 0.738310, 0.895830, 0.564230, 0.959780, -0.479160, -5.729940, 

0.444870, 0.812310, 1.380510, -0.455220, 0.920200, 1.229910, -0.406000, 0.198820, -0.872720, 0.430260, 
1.653830, -0.144110, 1.946180, 0.699160, -0.630760, 4.241420, -0.819180, 0.049660, 0.705900, -1.116430, 
0.340560, 2.396580, 0.445530, 0.254150, -0.354250, -0.548130, -0.794610, -0.323950, 1.191220, -1.405700, 
0.170590, -0.762080, 0.121930, 0.372640, -0.084790, 0.785960, -1.131420, -0.577340, 0.645570, -0.655700, 
-0.494880, 0.568890, -0.846020, 0.581650, 0.614130, 0.521960, -0.613090, 0.108130, 0.163420, 0.800610, 
0.793070, 0.467100, -0.491700, -0.899950, -0.059040, 0.977700, 0.399530, 0.024730, -0.919710, -0.230710, 

-0.301810, 0.429000, -0.911120, -0.490890, 0.957500, 0.084390, -0.739370, 0.692490, 0.484900, 0.408050, 
0.093900, 0.363440, -0.242250, 1.002270, 0.602310, 0.122890, 0.805280, -0.101290, -0.971360, 0.224160, 
0.370980, 2.937100, -0.715430, -0.285140, -0.926350, 0.764280, 0.539240, 1.278550, -0.049430, 1.119460, 
0.122680, -0.038170, 0.447440, -0.206570, 0.754580, 0.493670, 1.985720, 2.323910, -0.780240, -0.039920, 
-0.963180, -0.444820, -0.438610, -0.466030, 2.781890, 0.644920, 0.653420, 0.576620, -0.152120, -0.642560, 
-0.225220, 0.281080, -0.999460, 0.519840, -0.070590, -0.039030, -0.243650, 0.007920, -0.960520, 7.041150, 

-0.420840, -1.009180, -1.011930, -0.860540, -0.499620, 1.458010, 0.336460, -0.232270, 0.630390, 0.045940, 
-0.712490, 0.830370, 0.904630, -0.443960, 0.153680, 0.222640, 0.959400, -0.417040, 0.057870, 0.784000, 
-0.840780, -0.141670, -0.725270, -0.802240, -0.202090, 0.012470, -0.501940, -0.276210, -0.481860, -0.507020, 
-0.543540, 0.276730, -0.272480, 0.753680, 0.426810, -0.303550, 0.417850, 0.761020, 0.850110, -0.029290, 
-0.040820, 0.701700, 0.180850, -0.553360, 0.284570, -0.966600, -0.449020, 0.821940, 0.305140, 0.198820, 
-0.078050, -0.475690, 0.616040, 0.570100, -0.331010, 0.620420, 0.046730, -0.351860, -1.018980, 1.389130, 

0.573680, 0.809870, 0.483120, -0.206310, -0.127520, -0.558100, 0.107110, -0.142380, -0.308840, -0.007010, 
0.967380, 0.222520, 0.512710, -0.608770, -0.269860, 0.123930, 0.164660, 0.403600, -0.807630, -0.521660, 
0.244360, -0.070030, 0.377430, 0.373970, -0.485200, -0.208020, 0.407090, -0.182790, 0.474530, 0.723160, 
0.605500, -0.815810, -0.216710, -1.134940, 0.550430, -0.524080, -0.545190, -0.439510, -0.797700, -0.089370, 
-0.101470, -0.408920, 0.908430, 0.330170, -0.539020, 0.029130, 0.569870, -0.253160, -0.033810, 0.369110, 
0.530570, 0.402440, -0.114890, 0.379720, 0.738120, 0.517060, -0.207560, -0.525220, -0.554570, -1.216280, 

-15.043050, 1.061760, 0.788660, -1.909750, 0.617890, -3.132750, 1.707510, -0.329090, -0.311010, -0.097870, 
-0.519140, -1.205510, 2.607690, 0.185630, -0.710180, 0.998200, 0.511240, 0.901530, -0.479910, 3.656250, 
0.329590, -1.384940, 0.304320, -7.223250, 1.848560, -25.652201, 0.917330, -1.320750, -3.664470, -2.507380, 
-0.728120, 0.335950, -0.974950, 0.104600, 0.413600, 1.689030, -4.347140, -2.699090, 0.810440, -0.024490, 
0.399660, -0.281830, -0.865890, 0.108120, -0.049910, 0.763510, 0.060090, -0.200480, 0.478530, 0.546290, 
0.696130, -0.754880, -0.349280, -0.670250, 0.128220, -1.597380, -0.256460, 0.262780, -1.066340, -1.150420, 

0.012440, -0.109800, -0.268560, 0.186810, -0.616130, -0.828050, -0.766980, 0.827160, 0.311650, -0.855000, 
0.010790, -0.484370, 1.087270, 0.245290, 1.506590, 0.384690, -0.284620, 0.285390, 0.114560, 0.924230, 
-0.022350, -1.164390, -0.005750, -0.253000, -0.185900, -0.035530, 0.649500, -2.778600, 0.579230, 0.689280, 
-0.334060, 0.667260, 0.182440, 0.763270, -0.732120, 1.204580, -1.415200, 0.508260, 0.477320, -0.422090, 
1.462010, 0.108480, -0.577180, 0.384130, 0.142000, 0.081740, -1.081050, 0.296200, 0.097780, 0.354360, 
-0.104890, 0.065240, 0.551920, 0.757280, 0.808010, -0.711110, -0.343200, 0.534300, 0.743640, 2.411970, 

-0.033410, 1.510350, 0.018180, -0.757870, 0.749330, -1.336220, -0.196670, -0.849250, 3.301320, -1.057230, 
1.700620, -0.579870, 1.102820, -0.107220, 0.863740, -0.672690, -1.193640, 0.574390, -0.668320, -0.407140, 
-0.606320, -0.514040, -0.620220, -0.918230, 156.058380, -1.825990, 0.383700, 0.626500, 0.945780, -0.624160, 
0.742620, -0.124860, 10.947310, 0.936740, -0.143450, 1.678580, 4.077520, -2.520010, 0.422230, 0.425840, 
-2.047240, 0.967990, -0.132880, 0.651470, -0.414080, 0.365170, 0.706160, -2.209310, 0.807230, -0.940650, 
-0.200710, 0.949490, -0.139900, -0.097340, -0.763870, 0.356900, 0.489790, -0.194550, 0.592270, 1.095440, 

0.932130, 0.376700, -0.712590, -0.142050, 0.048940, 7.455820, -1.705760, 120.693420, 0.789570, 0.474900, 
-0.986030, -2.442640, 2.404660, 0.260400, 0.928150, -0.167420, 0.382340, -0.357040, 0.965430, 0.205780, 
-0.015540, 0.309740, -0.516620, -0.902480, -1.080250, -2.120350, 0.812590, -0.938610, 0.274950, -0.171640, 
0.599030, 0.637370, -0.641080, 0.173280, 0.887290, 44.479149, 2.270530, 0.449800, 0.077180, -0.155600, 
-1.666810, 0.535590, -0.169460, -0.410980, -0.694130, 0.607380, 0.110250, 1.190240, 0.963040, 0.855000, 
-0.239410, -0.760560, -0.840570, 0.518630, -0.420880, -1.646810, 0.194390, 0.295420, 0.613930, 0.687880, 

3.724410, -0.080600, -1.583390, -0.859720, 0.078410, -1.642490, -2.619660, 7.026240, 0.420640, -0.362770, 
0.848060, -1.255220, -0.525070, -0.230280, -0.098110, 1.568270, 1.456580, 0.455540, 0.981960, -1.815130, 
3.926150, -6.325290, -1.319190, -0.059460, -0.835510, 9.166940, 0.493060, 23.280590, 0.104720, -2.561320, 
0.598950, -0.533470, 0.975710, 0.176310, 1.022680, 1.447710, -1.858340, -5.833950, -0.483290, 0.132300, 
-0.405420, 0.546430, 0.484300, 0.218130, 0.415380, -0.054310, 0.666850, 0.535270, -0.796720, 0.608970, 
0.282580, -0.191250, -0.690000, 1.042890, -1.039030, 0.831820, 0.240340, 0.084440, -0.170440, 17.266720, 

-0.716740, -0.786590, 0.833000, 0.134330, -0.692090, -0.136290, 0.803480, -0.662210, -0.503120, -0.071390, 
0.177210, -0.251790, -0.349240, -0.735170, 0.645350, -0.238050, 1.052940, 0.891380, 0.463070, 1.022330, 
0.412370, -0.489130, -0.195820, -1.249370, -1.691170, 1.120540, 0.828070, -1.421330, -0.805570, -0.787240, 
-0.853740, -0.591710, 0.964370, 0.411080, 0.116490, -2.748530, -2.076930, -1.853080, 1.335510, 0.911030, 
0.339060, 0.497270, -0.021720, 0.725350, 0.771790, 0.701790, 0.787870, -0.827230, 0.787590, -0.417040, 
0.317250, 0.669130, -0.606260, 0.262620, -0.412670, 0.685380, 0.798980, 0.033280, -0.449270, -4.795810, 

-0.454580, 0.093540, 0.452630, 0.859500, -0.586370, 1.013620, 0.112490, -0.570330, -0.206380, -0.307270, 
-0.385040, 0.094960, -0.870760, -0.538350, 0.527920, 0.606390, 0.626160, -0.292000, 0.863590, 1.485310, 
0.403290, 0.381880, -0.369870, 0.678600, 0.186720, 0.362820, -0.645470, -1.155910, 0.487810, 0.758170, 
1.011670, 0.188520, -0.496110, 0.044150, -0.550200, 0.475800, -0.690810, 0.012110, -0.052440, 0.913120, 
0.076970, -0.832540, -0.224470, 0.172500, -0.467180, -0.398040, 0.440250, 0.955360, -0.935760, 0.766750, 
0.543120, 0.022610, 0.069020, 0.441530, -0.157700, -0.056170, -0.635500, -0.488900, -0.135270, -0.771480, 

0.884350, 0.230880, -0.607910, 0.165090, 0.602390, -0.657520, 1.187380, -0.645830, 0.034980, -0.972950, 
-0.982660, 0.316060, 0.490060, 1.160160, -0.581320, 0.874540, -0.123090, -0.641290, 0.597580, -0.597140, 
0.304700, -0.777120, -0.442350, -0.308720, 0.724720, 2.233610, 0.901300, -0.098810, 0.904880, 0.599670, 
0.494570, -0.907020, 0.112600, 0.555230, -0.625230, 0.522750, 0.908650, 0.543390, -0.831920, 0.291130, 
0.593460, -0.744560, 0.383890, 1.002870, 0.141440, 0.141840, 0.308620, 0.540300, 0.138000, 0.643020, 
-0.899970, -0.310140, 0.224940, -0.859650, 0.388590, -0.750670, -0.399510, 0.543800, 0.367080, -3.465160, 

0.880560, 0.188140, -0.037380, -0.892710, 0.276330, 1.344820, -0.703080, 0.969080, -1.861510, -0.391210, 
-1.025710, -0.905220, -0.409200, 0.300580, -0.536770, 0.447150, -0.040030, -0.814050, -0.463900, 0.401350, 
0.304910, -0.355780, 0.329930, -1.520850, 0.460740, 0.968120, -0.601230, -1.000540, -0.791080, 0.516770, 
0.212700, -0.855590, -0.304400, 0.210900, 0.578080, 0.724160, -0.882640, -2.039330, -0.221710, -0.838740, 
0.434280, -0.368520, -0.695100, -0.068800, 0.546680, -0.625970, 0.429330, 0.212520, -0.075420, -0.363000, 
0.972290, 0.867660, -0.859420, -0.020450, -0.288000, -0.465310, 0.854760, -0.814520, 0.975360, -0.435170, 

0.290550, -0.479940, 0.719150, 0.460430, -0.877130, -0.689110, 1.681700, -0.205330, 0.266970, 0.367630, 
0.499300, 0.194280, -0.420060, 1.264290, 0.726280, -0.026420, 0.445530, 0.023310, 0.115090, 0.026840, 
-0.046560, -1.537840, 0.916620, 0.805560, -1.110870, -0.805660, 0.024980, -0.116440, -0.843090, -1.093300, 
-0.977730, 0.685450, 0.367850, 0.297960, 0.210130, 0.469740, 0.417350, -0.784690, -0.736090, -0.430960, 
1.267000, -0.531550, 0.340860, 0.666650, 0.807620, 0.172420, -0.926250, 0.600490, 0.715660, 0.877710, 
0.796220, -0.799200, 0.425100, -0.270610, -0.600700, -0.846600, 0.437290, -0.467700, 0.807820, -1.381440, 

-0.132360, 1.010420, 1.067750, 0.067070, 0.299240, -0.198810, -0.360670, 0.782990, 0.197240, -0.656450, 
-0.908920, 0.790300, -0.469010, 0.530050, 0.931860, 7.824360, -0.715890, -0.149880, -0.734550, -1.509180, 
-1.170250, 0.825200, -0.604560, -0.172730, 0.726550, -0.675440, -0.702620, 1.877580, 0.958390, -0.769050, 
0.832480, -0.246930, -0.611660, -0.533260, 0.536660, 2.243340, 1.260110, 0.322870, 0.464650, 0.055440, 
-0.353640, -0.409060, -0.486510, -0.060920, -0.371540, 0.287220, 0.698360, 0.005940, -0.757090, -0.584190, 
0.861210, 0.871510, -0.029290, 0.391690, 0.252120, -0.979290, 0.486300, 0.591010, -0.174080, 0.584400, 

-0.120770, 0.775380, -0.831600, 0.469890, 0.747110, -1.021440, 3.059080, 0.668330, 0.049970, 0.606620, 
0.464680, -0.506020, -0.355370, 0.861160, 0.006990, 0.679960, -0.043760, 0.642600, 0.487580, 0.092650, 
0.219030, -0.778210, 0.065760, -0.792120, 0.984450, 4.502380, -0.319820, -0.448020, -0.953860, -0.807780, 
-0.546810, 1.009520, -0.553790, -0.707560, 0.353240, -0.289350, 0.825170, 0.509140, -1.300830, -0.255480, 
-0.117180, 0.952130, -0.045780, -0.173770, -0.627050, 0.405010, 0.560280, -1.209830, 1.018830, -0.400040, 
-0.359740, 0.901590, 0.901300, -0.463040, 0.275380, 0.054380, -0.840520, 0.184690, 0.043290, -2.075740, 

-0.388080, 0.020610, 0.286970, 0.465970, -0.597920, -0.388550, -1.318400, -0.447900, -0.465310, 0.138690, 
1.487550, -0.752740, 1.514410, -1.381050, -0.951500, 0.945800, 1.225340, 1.376250, 0.215480, 1.480750, 
0.889820, 0.420090, 0.442050, -0.458320, 1.290390, 2.897380, 0.765440, -0.611840, -0.512960, 2.192040, 
-0.634780, -0.639380, -0.772320, -0.182030, 0.843020, -2.194910, -0.283710, 1.007600, 0.040010, -0.208340, 
-0.403160, -0.860220, -0.873860, -0.942500, -0.934350, 0.538830, 0.816500, -0.875080, -0.461400, -0.282090, 
-0.685480, 0.672180, -0.582100, -0.689930, -0.196380, -0.633990, 0.452360, 0.136530, -0.780760, 2.679710, 

-0.233740, 0.117820, 0.380920, 0.515170, 0.445340, 0.779880, 0.475950, 0.919740, -0.925610, -0.203390, 
-0.447750, -0.612940, -0.056970, -1.012810, 0.150320, 0.572750, 0.249500, 0.265640, -0.907060, 0.958220, 
0.811810, -0.159790, -0.915810, -0.791820, -0.240070, -0.694900, 0.841470, -0.610180, -0.115780, 1.374870, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, 0.055940, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, 0.418300, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, 0.972620, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, 0.193670, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 0.970660, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, -1.528900, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, -0.006530, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, 0.065970, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, -0.017680, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, 0.138590, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -1.093480, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, 0.181650, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, 0.321740, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, -0.262930, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, 1.042910, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, 0.888280, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, 0.610420, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, 0.276970, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, -0.435690, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.602040, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, 0.720060, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, 0.485260, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, 0.968870, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, 0.002520, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, -0.304840, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, -1.711340, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, 0.108400, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, -0.062110, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, 0.950990, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, -0.819460, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, -0.188700, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, 0.965340, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, -0.245320, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, 0.851560, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, -0.164180, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, -0.098060, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, -0.605240, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, 0.585500, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, 0.013780, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, -0.652600, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, 0.195830, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -0.780400, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, 0.482900, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, 0.809100, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, 0.758740, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, 0.563980, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, -0.819090, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, -0.711620, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -0.717640, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, 0.300550, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, 0.446040, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, -0.136290, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, -0.091750, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, 0.188830, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, -0.651710, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, 0.802200, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, 0.408480, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, 0.139430, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, -0.470370, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -0.240440, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, 0.851440, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
0.39806, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.08453, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
0.22559, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
0.30839, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.01839, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
0.00022, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
0.00004, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
0.03579, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
1.42117, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
1.00325, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
0.40137, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
0.75870, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
1.11675, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
0.41807, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
1.42624, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
0.02322, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.42800, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
0.54003, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
1.04738, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
0.30811, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
0.31341, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
0.35895, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
0.39031, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
0.32735, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
0.30275, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.01370, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
1.38859, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
0.32417, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
0.38059, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.00095, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
0.91852, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
1.39037, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
0.49716, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
1.38974, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
1.38243, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
0.07366, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
0.00671, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
0.10708, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
1.29007, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
1.20265, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
0.10137, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
1.42542, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
1.32732, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
1.37248, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
1.34128, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
1.13833, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.32073, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
0.08672, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
1.42262, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
1.42845, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
1.41931, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
1.42568, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
1.42652, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
0.65089, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
0.63199, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
0.01403, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
1.42510, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
1.08948, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
0.68095, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.01703, 0.500000, 2,
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
