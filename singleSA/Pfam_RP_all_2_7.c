/*********************************************************
  Pfam_RP_all_2_7.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:19:01 2005
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
-0.349610, -1.122540, -1.212350, -0.299660, 0.098950, 0.063580, -0.489330, -1.220180, -0.904820, -0.416250, 
0.907030, 0.560300, 0.301360, -0.659220, -0.095100, -0.143690, -0.408210, 0.504330, 1.498790, -0.294240, 
-0.433460, 1.341380, -1.129940, -0.525510, 1.927360, 0.237780, 1.980580, 0.383790, -0.632260, 0.118260, 
0.622430, -0.089840, 0.528900, -0.806900, -0.591550, -0.214310, -2.326520, 0.222910, 0.648040, 0.352040, 
0.748090, -0.541300, 1.000040, -0.414540, -1.092010, -1.509890, 0.142270, 0.718470, 0.742400, 1.516370, 
-0.368740, -0.718820, -1.545700, 1.483510, 0.974170, 2.400310, -0.292270, -0.845660, -0.097190, 1.262470, 
0.086930, -0.176350, -1.171130, 1.610090, -1.089860, -0.103680, -0.039830, -0.623940, 0.896340, 0.629070, 
-0.736920, 0.748440, -1.142240, -0.038510, -0.248620, -0.231910, 0.304750, 0.452560, -0.679640, -0.103180, 
0.458050, 0.670280, -0.957420, -0.202550, -0.151570, -1.071420, 0.948330, 0.417810, -0.458230, -0.296630, 
-1.349530, -1.529490, -0.375530, 0.793540, -1.355340, 0.206500, 0.879620, -0.330600, -0.901900, -0.277120, 
0.093650, 0.649660, -1.028610, -1.139390, -0.759710, 0.618710, 0.920300, -2.105130, 0.607230, 2.809400, 
0.155140, 0.374800, -0.920230, -0.601860, -0.677400, 1.317430, 2.127230, 0.759960, -0.244300, 0.550360, 
0.244330, -0.467030, -0.563160, 2.017490, 2.925100, -1.183700, -0.133470, -0.790640, 1.040850, 0.915280, 
1.317410, -0.146970, 2.074980, -1.178200, -1.447150, 2.509600, -0.745280, -1.561780, -1.570600, 0.647280, 
-0.380170, 0.328890, -0.767270, 1.569110, 0.229310, 1.883990, -0.180290, 0.382310, -0.835300, -0.128500, 
0.836930, 1.830120, 1.121880, -0.625780, -0.621030, 2.259750, 0.523970, -0.515560, -0.476250, -1.301680, 
-1.078020, -0.416280, 1.248880, -0.033830, -3.208320, -0.551010, -2.097000, -0.011190, -0.350170, -1.155220, 
0.680620, -0.579000, -0.496460, 0.292190, -0.227220, -0.161160, -0.522650, -1.510320, 0.782450, 0.290740, 
0.015370, -0.854960, 1.925890, -3.405350, -0.431090, -0.030590, 0.878510, 0.182000, -0.699130, -0.203310, 
-0.564220, -0.122920, -0.641440, 0.899220, 0.767440, -0.263550, -0.265450, 0.251790, -0.442060, -0.511610, 
-0.238500, 1.391920, 0.041410, -0.575180, 0.917140, -0.511800, 0.217530, 0.331630, 1.248420, -0.547340, 
-0.709470, 0.298160, 2.983790, -0.046430, 0.169760, 0.757340, 1.937910, -0.098030, 1.097670, -0.456530, 
-2.879740, -0.492310, 0.190490, 1.617020, 0.777630, -0.423770, -0.115850, -0.292360, 0.290930, -0.710010, 
-1.982860, 0.509830, 0.878800, -0.066290, 0.812870, -1.828400, 0.127750, -0.760160, -0.003370, -0.338380, 
0.639010, 0.263790, -0.358390, -2.097310, -0.587950, -0.532280, -0.682040, 1.446910, 0.732920, -0.585600, 
-0.822600, 0.693920, 0.103700, -0.341800, 0.790240, 3.108240, 0.503050, -0.594100, 0.099660, -0.665380, 
1.039920, 0.593550, -2.386030, -1.542830, -0.098640, 0.046020, -0.129300, -1.402100, 0.931150, -1.018080, 
-0.757660, 0.287670, 0.490410, 0.592020, -0.974780, 0.968190, -0.412730, 0.825850, 0.369500, -0.083990, 
-0.290910, -0.979330, 0.219660, -0.111050, 0.015180, -0.431710, -0.482260, 0.304890, -0.091130, -0.324870, 
0.673430, -0.975020, 0.118990, 0.027920, -0.496130, -0.546810, 1.202330, -0.036620, -0.712620, 
-0.132480, 0.762310, -0.895560, 2.718220, 0.640590, -0.208040, 0.950280, -0.400390, 0.722520, -0.968140, 
-0.798450, 0.087290, -0.294030, 1.147050, -0.377340, 0.751280, 0.686710, -1.122270, -0.618650, -0.105700, 
0.719920, -0.965910, 2.071210, 0.190350, -0.337520, -0.154120, 1.545490, -1.359910, -0.930310, 0.453200, 
-1.714310, -0.270240, -2.390520, 0.881460, 0.003620, -0.155600, 0.950740, -1.054270, 1.405710, -1.139520, 
-1.550950, -1.454740, -0.461220, 1.009550, -0.655580, -0.527370, 3.437650, 2.093780, -1.323190, -0.202320, 
1.334090, -0.483880, -0.460840, -0.285490, -0.088910, -0.902240, 0.285640, 0.784930, -0.053230, 0.709060, 
1.208110, 0.039020, 0.330140, -0.910860, -1.826920, 0.257960, 0.679310, 0.304680, 0.916000, -0.023330, 
4.139860, 1.230210, 0.218820, 0.148990, -2.070790, -0.017730, -0.076060, 0.310720, -0.186670, 1.387490, 
0.032920, 0.883120, 3.846490, -0.369140, 0.891760, 1.235620, -0.904020, -2.643970, -0.937520, 0.702080, 
-0.915380, 0.318350, 1.316790, 1.029730, 0.966430, -0.634690, 0.449960, -0.838740, -0.745740, -0.812220, 
-0.777890, -0.094120, 0.979370, -0.954860, 1.336050, -0.216800, 1.307050, 1.115490, 0.049290, -0.120490, 
0.582790, -0.944620, -0.764200, -0.351110, -0.005240, -1.640680, -1.693460, -0.081790, 2.223270, -3.639780, 
-1.885860, 2.569770, -1.370220, -2.591280, -8.194950, 0.685560, -2.795070, 0.117330, 0.230250, 0.239300, 
0.014510, 0.188850, -18.239309, -1.371570, -3.030840, -2.734990, -6.422620, -2.138150, 0.000040, -1.112020, 
-0.702130, 3.035560, 0.774590, -0.032080, -0.311530, 0.813570, -0.765320, -1.333770, -0.118580, 0.237370, 
1.023170, 1.195860, 0.555660, 0.815840, -0.162430, -1.144150, -0.961260, -0.110350, -0.798960, 0.014640, 
0.739710, 1.905180, -0.336770, -0.190110, -0.760560, 0.259080, 0.222760, 1.483280, -1.215960, 0.519230, 
0.180540, 1.074440, -0.411890, 0.531850, 3.109210, -0.406980, 0.292000, 0.315430, 0.355180, -0.866790, 
-0.754300, 0.417420, 0.102110, 1.076100, 1.495960, 1.397350, 1.523100, 1.106330, 0.056680, 0.199860, 
0.797800, 0.215480, 0.306640, 0.886910, -1.881500, 0.473140, 0.603110, 2.780570, -0.311820, 0.475940, 
0.555300, -0.600210, 0.382990, -0.022670, -0.878740, -2.702120, -0.301520, 1.557310, 1.092020, -0.667220, 
0.976120, 0.861220, -0.808660, 0.853720, -1.208770, 0.311850, -0.561530, 1.010280, 0.071780, 0.725890, 
2.105310, -0.689070, -0.270380, 0.930330, -1.869990, -0.089590, 0.729120, 0.859530, -0.322500, 0.823960, 
0.623100, 0.763830, 0.712740, 0.043220, 0.444810, 0.035410, 1.764060, -0.432860, 2.569780, -0.064800, 
-0.538430, 0.227090, 0.717290, 5.483710, 0.787570, -0.695870, -0.591300, -1.736150, 0.207060, -0.092030, 
2.802540, -0.448870, 6.892410, 1.657200, -0.384190, 2.506380, 0.792860, -0.827470, 0.830490, -0.236500, 
0.603690, 1.040550, -3.179780, 0.263720, -0.718380, 0.291830, -0.970960, 0.365540, 0.342060, -0.298440, 
0.481220, -0.249280, -0.576300, 0.363950, 0.925870, -0.422060, 1.016400, -0.532490, 0.247930, 0.262380, 
0.930550, -0.344310, -0.579120, -0.408730, -0.063140, -0.921540, -0.255210, -0.038080, 0.257390, 0.132720, 
-0.441560, -0.913350, -0.735300, 0.330650, -0.050550, -0.323860, -3.170120, -0.723080, 0.413260, 
-0.200510, 0.985240, 0.121940, -0.198150, 1.268290, -0.932480, -0.024440, 1.980400, 0.230490, -1.777570, 
0.098980, -0.254450, 0.530500, 1.022900, -0.297380, -0.223560, 0.958890, -0.428110, -3.093670, 0.228770, 
-0.071340, 1.232890, 0.586240, -0.227360, 0.291370, 1.521140, -0.737620, -0.357370, -1.320320, 0.425620, 
5.656220, 1.097130, 1.254230, -0.087610, 0.626120, 0.335600, 0.790710, 0.809540, 0.218540, -0.254740, 
-1.686470, 0.112200, -0.490700, -0.550790, 0.514180, 1.092090, 0.568880, -0.635810, -1.217330, 0.486790, 
-1.065160, 0.879910, 0.874270, 0.933840, 0.973620, -2.771800, 0.408670, 0.439290, 0.853510, 0.994690, 
0.559350, 0.435320, 1.155950, 0.724780, 0.542140, -0.552200, 0.055340, -0.626350, 0.932670, -1.735640, 
1.414660, 0.837260, 0.144070, 1.599860, 0.189360, 0.768980, 0.409850, -1.024610, -1.664900, 0.791820, 
0.722800, -1.126310, 1.653060, 0.580900, 1.576510, -0.630090, 0.690720, -0.824630, 0.371910, -0.757490, 
3.815180, 1.786870, -0.374180, -0.701810, -0.531900, 1.246720, 0.656920, 0.575120, 0.862010, 1.779750, 
0.938960, -0.345630, -0.216140, 0.599190, -0.806750, 1.163150, 2.112990, 0.440630, 0.889030, 0.557970, 
-1.989680, -0.332140, -0.986960, 0.913280, 4.009420, -0.630670, -2.495280, -2.773450, 2.028470, -2.135280, 
-0.452040, -4.609690, -0.658030, -1.848920, -3.841990, 1.540350, 1.191360, 0.382510, -1.739960, -0.500850, 
1.347250, 0.057780, -3.309410, 0.570820, 1.707620, -1.995650, 0.087130, 1.354500, 0.115920, 2.293510, 
-3.622460, -1.914090, -0.403410, 1.045410, 0.399030, 1.041710, 0.148330, -3.234860, -1.286280, -0.326210, 
0.674620, -0.264440, -0.210250, -0.303740, 0.538850, -0.307630, 0.321050, 0.215560, 0.400200, 3.631250, 
0.596640, 0.158610, 0.574150, 1.002560, 0.309360, 0.349350, 0.705950, 0.189770, -0.322420, 0.639370, 
-0.421890, -0.620540, 1.143700, 0.152650, 0.845650, 0.706530, 1.181500, 0.560950, -1.286270, -0.863810, 
-0.411920, 0.374700, -0.630470, 1.775270, 0.582890, 0.374930, -0.800560, 0.600730, 0.376650, 0.408540, 
-0.077280, 0.461330, 0.941080, -1.302110, -2.829440, -1.377170, 0.568060, 0.829380, 0.402990, -2.059750, 
-1.354250, -1.411250, 3.320380, -0.815580, 0.000080, -0.354010, 0.476020, -0.153060, -1.114810, -2.366920, 
3.813710, -0.447040, 0.322310, -1.260880, -0.028450, -0.514470, -0.627230, 0.944050, -1.684500, 0.261840, 
-0.512640, 0.757480, -0.333480, -0.736330, -0.697020, -0.503490, 0.736770, -1.646010, -1.081770, 1.497360, 
0.670740, 0.502610, -1.885700, 0.736060, -0.960340, -0.568540, 0.935540, -0.354450, 0.436310, -0.934100, 
1.425540, 0.893700, 0.270300, 1.378530, -0.473170, -1.207680, 0.316080, -0.794550, -0.594810, 0.360040, 
-0.350200, 0.345440, 1.942260, -0.635800, 0.120340, -3.139110, 0.203090, -0.043240, 0.667070, 0.756000, 
2.501350, 0.639310, 1.902240, 1.542340, -2.506420, 3.411760, 0.797700, 1.427390, 0.420060, -0.124310, 
1.060750, -0.729660, 0.919570, -0.410950, 0.910430, 1.095640, -0.595140, -0.912290, -0.662930, 0.858760, 
-0.603430, -0.267210, 0.504280, 0.138890, 1.037680, -0.405460, 0.844740, 0.037900, -0.457740, -0.784450, 
0.935040, -0.325180, -0.350290, 0.506820, 0.376830, 0.921740, 0.636410, 0.903530, 1.009590, 
1.036380, 0.322850, 0.392720, 2.780540, -1.212230, -0.502700, 0.020060, -0.315600, -0.361680, 2.162380, 
1.512960, 1.276540, 0.160570, 0.250290, 0.361050, -1.358200, -0.345350, 0.516960, -1.099760, 0.446260, 
-0.749930, 0.627130, -1.584180, 1.968480, 0.082180, -0.269140, 1.054580, -1.936650, -0.727400, -0.056090, 
-1.230080, -1.202610, 0.282000, -1.364810, 0.397120, 0.252540, 0.693420, -0.646250, 0.429100, 1.081200, 
-0.773950, -0.444550, 0.151440, 0.055930, 0.690110, 0.414790, 0.345210, -0.556910, 0.231410, 0.035970, 
-1.064420, 0.013300, 0.482400, 0.215380, 0.055280, -0.606460, 2.692660, -0.739300, 0.368620, -0.669490, 
-0.563690, 0.330290, -0.346860, -0.245150, 0.500640, -0.404070, 0.829940, -0.665760, -1.404200, 0.855600, 
0.499720, 3.110500, 0.594740, 0.287990, 0.635550, 0.693800, 0.669880, -0.180920, -1.078060, 0.481110, 
-1.416300, -0.459860, -1.831100, 0.792630, -0.169500, 0.932090, 0.698110, 0.888460, -0.432030, -0.073070, 
1.355960, 1.372260, 0.191880, -0.756670, 0.495440, -1.556390, 0.001270, -0.062050, 1.250020, 1.939100, 
0.469720, -0.786610, -0.864090, 0.526230, 0.743820, -0.510850, 0.331820, 0.470380, 0.813480, 0.373390, 
0.836740, 0.805380, 0.334590, -0.821660, -1.719670, -1.255700, 0.950530, -2.455710, 0.416860, -1.114490, 
-0.572390, 1.854230, 0.595870, -0.718260, -1.249780, 1.531210, 2.196850, 1.201460, 3.501350, -0.917630, 
1.001790, 2.093440, -1.049500, 0.829740, 1.521180, 0.711600, 3.241040, -0.414900, 0.767900, 1.118890, 
1.685190, -1.359580, -1.991920, -1.401570, -0.164730, -0.932520, -0.888340, -0.668950, 1.419290, 0.167970, 
0.545400, 2.969670, 0.947150, 0.494530, 0.127510, -1.623620, 1.188180, -3.618720, 0.522740, 1.079560, 
-2.942870, 0.956960, 1.573540, 0.807300, 1.246490, 0.848720, 1.420300, 1.414500, -0.151130, 0.372380, 
0.537790, 0.786830, -0.605460, -3.203580, 0.328150, 0.171810, 0.695450, -0.947760, 0.756690, 0.148280, 
-0.852400, -0.432030, 0.442860, -1.058050, -0.150580, -1.740890, -2.799670, -0.052820, -0.412730, -0.370610, 
1.455800, -0.212250, -1.141500, 0.566950, 1.243430, 0.638560, -1.007820, -3.717770, 0.568400, 1.921230, 
1.413830, -1.964380, 0.342660, 1.176270, 0.239810, 1.088080, -0.994250, 0.449300, -1.866400, -2.250800, 
-1.332480, 0.088590, 0.201330, 0.081030, -1.811900, -0.626730, -0.126140, 0.812320, 0.178770, 1.526070, 
0.280680, 0.324650, 2.436200, 0.312280, -0.905860, -0.815090, 0.482810, -0.691950, 0.643900, 0.018700, 
-0.812370, 0.194560, -0.395390, 0.968100, -0.178470, 2.055290, -1.376990, -0.949370, 1.751880, 1.169920, 
0.784420, -0.747950, -1.503040, 0.883490, 1.145430, -0.550100, 0.634480, 0.643670, 1.252320, -0.127810, 
0.025310, 0.159360, 0.841930, -0.618670, 1.906420, 0.208510, -0.104410, 0.214840, 0.160490, -1.361830, 
-0.292700, -0.922470, 1.092440, 0.396180, 0.593320, -1.707400, -0.737690, 0.586060, 0.296800, 0.710140, 
-0.501010, 0.096630, -0.523240, -0.364050, -0.852590, -0.272060, 0.057270, -0.451170, -0.795730, 0.143070, 
-0.394230, -0.909380, 0.962720, 0.003680, -0.994040, 0.019860, 0.745030, 0.287670, 0.784710, 0.725110, 
-0.166890, 0.440650, 0.865180, -0.540800, 0.257990, 1.524610, -0.559150, 0.666160, 0.706290, 
0.277350, 0.067640, -0.057310, -0.134000, 0.598030, 0.274920, 0.360450, 0.681800, 0.805970, 0.798570, 
1.396090, 0.943420, -0.143420, 1.046150, 0.460310, -0.968280, 0.053570, 1.138690, 0.843980, 0.978600, 
0.291410, 0.032040, 0.785770, -0.954920, -0.800100, 0.159840, -0.471200, -0.262600, -0.066640, -0.867120, 
-0.106750, -1.321040, 0.097030, -0.264030, 0.165090, 0.778080, -0.755820, -1.236120, -0.314290, 0.451050, 
-0.607030, 0.335570, -0.980750, 0.959720, 0.153720, -0.530170, 0.468190, 0.419790, -0.690380, -1.374960, 
-0.267950, -1.587620, -0.725740, -0.356860, 0.288760, 0.089290, 1.618060, -0.538350, 0.148260, 0.712040, 
-0.282200, -0.246590, 0.960430, -0.951630, 0.057110, 0.676890, 0.521250, -0.556310, -0.086940, 0.758450, 
0.171770, 0.198560, 0.954480, 1.091670, 0.223390, 0.522510, 0.899080, -0.422320, -0.161900, -0.973420, 
0.038800, -0.771410, 1.043860, 0.426200, 0.172290, 1.186910, 0.059080, 0.774760, -0.553650, 0.311380, 
-0.179170, 0.705350, 0.719810, -0.575590, 1.629270, -0.547380, 1.287350, 0.816250, -0.115530, -0.500150, 
0.161590, 0.432350, -1.125600, 0.121570, 0.762470, -0.487210, -0.758600, 1.205110, 0.315640, -0.646750, 
-0.786960, 0.525720, -0.640170, 3.244230, 0.615130, -3.288940, -0.652960, 0.490590, 2.473470, -2.638460, 
-1.063770, 0.927900, -1.644470, -3.172710, -2.989820, 1.696530, 2.342300, 1.576210, -1.522120, -2.723370, 
1.817020, 0.532770, -2.569440, 1.207040, 2.492300, -0.962110, 2.928110, -3.487820, -0.514410, -2.281360, 
0.144190, 1.753190, -0.287980, -0.719980, 0.472260, -0.065050, -0.707150, -0.400390, 0.122760, -0.790580, 
-0.116190, -0.475050, -0.709210, 0.574240, -0.029660, -0.515890, -1.560210, -0.188090, 0.307450, 1.662190, 
-0.618110, -0.481630, -0.608690, 0.627870, 0.396840, 0.801430, 0.311500, 0.079810, -0.006150, 0.021070, 
0.311360, -1.251270, -1.676190, 0.401890, -0.234560, 0.590530, 0.203050, -1.155260, 0.881750, 2.610460, 
-0.431760, -0.065470, -0.099060, -0.366810, -1.688160, -0.212170, 0.032090, -1.088340, -0.611530, 0.197920, 
0.346470, -0.673900, -0.183650, -0.375670, 0.624380, 0.422390, 0.453800, 0.079430, -0.483790, -0.374880, 
0.649820, 0.786670, -0.281420, 0.602310, -0.559710, 1.203610, -0.730980, -1.378580, 0.184870, -2.722200, 
-0.275900, 0.047380, -1.453940, -1.107880, 1.475760, 0.454680, -0.725040, -0.319520, 0.229680, -0.746050, 
-0.278380, -0.817770, 0.879000, 0.766980, -0.384160, -0.350320, 1.479380, 0.254950, 0.531090, -0.365950, 
0.102820, 0.914780, -0.956520, -0.420370, 0.234290, 0.270730, -0.567280, -0.672780, -0.007280, 0.201270, 
0.196750, -0.389310, -1.266770, 0.634360, 0.352050, -0.184630, -0.537560, -0.501190, 0.270410, 0.424230, 
0.675350, 1.052140, -2.054470, 19.794670, 0.505250, 0.557170, -0.151220, -0.185940, 0.234210, 0.660020, 
-0.232760, 0.241090, 3.978830, 0.726040, -0.926760, 0.778990, -0.217210, 0.455830, -0.419930, -0.519230, 
0.031100, -0.179700, -0.464430, -0.102210, 0.547540, 0.847980, 0.626130, -0.166430, 0.305740, 1.054540, 
-0.531810, 0.625280, -0.155620, 0.424640, 0.166000, -0.632900, 0.276510, 0.285260, 1.124710, 0.435080, 
-0.947050, 0.530640, -0.558160, -0.469990, 0.129450, -0.189330, -1.064730, 0.647380, 0.860120, 
0.916040, 0.528870, -1.820600, 0.250270, 0.273710, 0.642270, 0.528060, -0.431970, 1.124430, -2.105190, 
0.677670, -0.972330, -0.182140, 0.721260, -0.096710, 0.835950, 0.289580, 0.250670, -0.309810, 0.365230, 
0.004660, 1.042010, 0.730590, 0.818000, -0.056960, 0.455120, -1.039780, -0.761360, 0.529240, 0.716190, 
0.071740, -0.489450, -1.056050, -0.278150, 0.732070, 0.533740, 1.734790, 0.628480, 0.238950, -0.361360, 
-0.609120, 0.445870, -0.935950, 0.378600, 0.738630, 0.493490, 1.546810, 0.114640, -0.844270, 1.420310, 
0.002360, -3.431750, 0.583690, 0.802540, -1.734440, 0.102290, 1.222800, -0.281430, 0.454080, -1.120150, 
0.878830, -0.701380, 0.500850, -2.441310, 0.568950, 0.707780, 1.011410, -1.047440, -0.525100, -0.522240, 
0.303490, -2.218450, 0.663970, -0.514650, 0.297060, 0.403100, 1.090120, 0.629550, -0.312450, 4.644480, 
2.764140, 0.058640, 0.081090, 1.432570, -1.243890, 1.641180, -1.774590, -0.656320, 1.218830, 0.232350, 
1.272610, 0.807880, -1.270850, -0.979400, 0.004930, 0.853700, 0.317370, -2.925950, 0.950430, -2.270140, 
0.052920, 0.040460, 1.325080, 0.004140, -0.890310, 0.137040, -0.642140, 1.071990, -0.800540, -0.537630, 
-2.347320, -0.697360, -0.378040, 1.060520, 0.993410, -0.413350, -1.971950, -0.758450, 15.260490, -1.116020, 
-1.217140, 1.355460, 2.359370, -1.429300, -1.647500, -0.371500, -5.110530, 0.760080, 0.935580, -0.855290, 
-7.873850, -0.027570, 15.009470, -1.049380, 0.989250, 6.719940, 1.316500, 0.359410, -0.024830, 0.000200, 
-0.728880, 1.992930, 0.537540, 0.325870, 1.653420, -0.236260, -0.823200, -0.180940, -0.118510, -0.034120, 
-0.433900, -1.319740, 0.379990, -0.036380, -0.036630, -1.293580, -0.199230, -1.203300, 0.036100, -1.928670, 
0.151730, 1.816520, -0.521530, -1.452280, 0.172390, 0.970530, 0.612110, 1.468370, 0.796160, 0.023060, 
0.440350, 0.023440, 1.203190, 0.023560, -1.374330, -0.158060, 1.096940, -1.199290, -0.800890, 0.236630, 
1.515700, 0.302650, -0.624370, 1.269450, -0.083270, 1.400980, 0.256090, 0.767720, 0.653290, -0.207870, 
1.369010, -0.099120, 3.897540, -0.288000, -0.604750, 0.138490, 1.281530, 1.179950, 1.135010, -0.977190, 
1.645810, -0.522840, 0.209720, 0.544390, 1.059120, -0.849050, 1.636840, -0.619740, -1.708860, 0.338150, 
2.721880, 0.196490, 0.385140, -0.183360, 1.175740, -0.216540, -0.508740, -0.646780, -0.248820, -1.016050, 
3.272600, 2.613470, 0.558440, -1.350080, 0.201600, 0.335650, 0.470730, -0.155390, -0.458710, 0.406810, 
1.607710, -0.426580, -0.745700, -0.077670, -0.289530, 0.294980, -0.013640, 0.900640, 1.988340, 0.092940, 
0.413250, -0.397430, 0.279060, 1.392710, 1.278000, 0.392650, 0.351140, -0.544280, 0.223760, 1.658630, 
-0.340330, 3.582800, 0.442680, -8.715490, 0.035190, -3.092540, -0.106030, 1.066180, 0.429620, 0.686490, 
2.329930, 0.207070, 2.308250, 5.250740, 0.582920, -3.644450, 0.022130, 0.814260, 0.420450, -0.197070, 
0.915890, -0.639550, 0.731640, -0.740950, -0.693800, 0.917720, -0.273210, 0.498710, -0.826940, 0.364960, 
-0.593560, 0.627390, -0.513350, -0.020470, 0.791050, 0.545950, -0.058220, 0.045500, -0.679160, -0.966810, 
-0.365170, -0.513010, -0.174880, 0.607700, -0.394620, -0.007690, 0.258550, -0.325780, 0.951640, 
-0.547330, 1.849230, -1.051270, 0.408790, 0.551240, 0.763610, 0.770880, -0.950240, -1.028350, -0.235850, 
-0.970670, 1.501330, -0.228290, 1.085550, -1.188910, -0.089260, -1.379320, 1.576610, 1.165020, 0.203570, 
0.898340, 0.968700, -0.315490, -0.204330, -1.080360, -1.249770, 1.245320, -1.516580, 0.356690, 0.091640, 
-1.738550, -1.081790, -1.433680, -0.779290, 1.518470, -0.147310, 0.559810, 0.631470, -0.010980, 1.370320, 
-0.582040, 0.985530, 0.792820, -0.062670, 0.948480, 0.633850, -2.340560, -1.784970, -1.418620, 0.155130, 
-3.131020, -0.628220, 0.859030, -0.577410, -1.388510, -1.352320, 1.965370, 0.218820, -0.380580, 0.081200, 
1.486290, -1.254420, 0.170710, -1.427160, 2.086550, 0.748730, -0.065360, 1.369060, -1.186540, -0.125000, 
0.200180, 1.107840, 0.421970, 0.740180, 0.489020, 1.377290, 0.286350, -0.438660, 0.735780, 1.827350, 
2.167100, -0.466680, -0.130160, -0.902000, -2.329570, 1.737110, 1.096670, -0.734290, -0.689920, -0.543130, 
0.162270, 3.521310, 0.291800, -0.350790, -0.306700, 0.680550, 1.187980, -0.134830, 0.391090, -0.813090, 
0.812300, 2.314920, 0.025130, 0.211120, 0.637420, 0.679580, -0.387600, 0.018880, -0.502590, 0.488210, 
1.228120, -0.271580, -0.932170, 0.773590, -0.334860, 1.572320, -3.853530, -4.240730, -0.601660, -0.057890, 
-0.384380, 1.434770, -0.321610, 0.076170, 0.279700, 1.331060, 1.620780, 1.785120, 0.168400, -1.187990, 
1.320990, 0.614950, -7.921690, 0.429000, 1.655170, -0.139290, 0.180620, 0.492530, -1.405800, 0.169200, 
-0.933770, 1.078420, -0.638910, -2.185740, 1.380810, 0.909450, 0.038940, -0.870280, -0.830500, 1.808300, 
-0.150130, -0.475640, -2.491880, 0.420730, -1.495520, -1.896730, -1.352090, -1.649620, -0.871570, -1.006300, 
2.083230, -0.489780, -0.798660, 3.469860, 1.448040, 0.592200, 2.316960, -1.016590, 7.202930, 0.350900, 
1.143730, -0.503110, -0.054550, 1.025610, 2.078760, 1.311100, -0.725290, 0.157700, 0.931920, -1.278540, 
1.482500, -0.097790, 0.374270, -0.850950, 1.225960, -0.667840, -0.532020, 0.407570, 0.085460, -0.261550, 
-0.715440, 0.592320, 1.026580, -1.299140, -1.131570, 0.152350, 0.311130, 2.257080, 0.131240, 1.138710, 
-2.535080, -0.409410, -0.702990, -1.754030, 0.448840, -0.527280, -0.374060, -0.253750, -2.166030, 0.901280, 
0.470150, 0.588520, 0.185920, -0.594690, -1.406110, 0.286250, -0.434910, -1.875020, 0.913000, 0.313570, 
0.749070, -1.353940, 2.752720, 1.796400, -2.060430, 0.446670, -0.072650, -0.826190, 0.344980, 0.977570, 
1.944600, 1.290770, 0.376700, 2.659550, 0.511190, 1.621190, -0.161000, 0.021540, -0.511230, 0.545040, 
0.692640, 0.711780, 0.312900, 3.019960, 0.384120, -1.383250, -0.031090, 0.679940, -0.450220, -0.788780, 
-0.358840, 1.268410, 0.080880, -0.796010, -0.302950, 0.469770, 0.508680, 0.284030, -0.107570, -0.955070, 
-1.927640, 1.878250, 3.739640, 1.372420, -0.357560, -0.496980, 0.544500, 1.840370, 0.721870, 0.711910, 
-0.729840, 0.574590, 0.413600, -0.485040, 0.782500, 0.843560, -0.172140, -0.365010, 0.400430, -0.176380, 
1.417260, -0.711840, -0.365280, 0.033090, -0.036890, 0.209110, -0.187200, 0.511500, -0.242130, 0.724840, 
0.293270, -0.345660, -0.068470, -0.712850, 0.620870, 0.074120, -0.241460, -0.452740, -0.635270, 
-3.048020, -2.284190, 0.754310, -1.159040, -1.427300, -0.248090, -0.062210, 0.631740, -0.247830, 0.976620, 
-0.795200, -0.110190, -0.170110, -2.780640, -0.956020, 0.064130, 0.169220, -0.910070, -0.459250, 0.347020, 
0.665750, 0.665540, -1.103160, -0.413740, -1.083390, -0.005370, 3.912450, 0.682000, -1.252480, -0.790960, 
-1.084040, -0.386800, 0.452650, 0.840260, -0.613920, -0.456500, -0.506760, -0.053220, -0.174200, -0.680550, 
-0.113400, -0.168300, -0.298230, 0.153000, 0.285200, -0.659140, -0.245420, 0.051420, 1.006810, -0.012500, 
1.752530, -1.080300, -1.941470, 2.437180, 0.903710, 1.586740, -0.285770, -0.526240, -0.201180, 0.192980, 
-1.452230, 0.190170, -0.659570, 2.418770, -0.017610, -1.542450, 0.254000, 0.149050, 0.310590, -0.256120, 
0.638500, -0.458120, -0.619980, 0.043750, 0.711370, -0.193920, -0.473400, -0.183650, 1.503850, -3.547050, 
0.332500, -0.138610, -0.173070, -0.502160, -2.040870, -0.049400, 0.372000, 1.253140, -0.417530, -0.173670, 
-2.028050, -0.311380, -0.263510, 3.321130, 0.123790, 1.598980, 0.955380, -0.615470, -2.158270, 0.574100, 
-0.094180, 1.652430, -0.426940, -0.337900, 1.493310, -0.237180, 0.705920, 0.051420, -0.601350, -0.227700, 
0.720290, 0.568220, -0.191060, 1.390920, -0.190320, 1.724300, 4.394720, 2.243550, -1.521790, 1.237760, 
2.246940, -9.191320, 0.857270, 4.311160, 4.475100, -4.601210, 0.153980, 1.468270, 1.894590, 2.787580, 
-2.581650, 0.533490, 9.468380, -0.558900, 1.116750, -1.367590, -5.082190, -1.699590, 0.068150, 0.301430, 
0.238040, -0.483610, -0.230080, -0.164090, 0.247810, 2.354980, -0.591960, -0.580620, -1.071100, -0.238500, 
-1.301910, 0.080430, 0.319530, -0.700080, -0.968610, 0.976620, 0.341780, -2.285100, 0.767120, -0.055020, 
0.459750, -1.998300, 1.183950, -2.145830, 0.685010, -1.447520, -1.980250, 2.229380, 0.880860, 0.438980, 
1.406220, -0.114510, 2.867320, 0.247950, -1.188220, -0.383980, -1.104270, 0.377670, -0.856420, -0.458890, 
0.072730, -0.574410, -0.075770, -3.690040, -0.272230, 1.350780, 1.429860, 0.454910, 1.098220, 0.248490, 
-0.505790, -1.378770, 0.697880, 0.947310, 0.122940, 0.545290, -1.381790, 0.200550, -1.229670, -1.526270, 
-0.355020, 0.370250, -0.480840, -2.709160, -0.612220, 0.448100, 0.077160, -0.488380, -1.084910, 0.317620, 
1.243670, -1.654790, -1.142160, 0.169450, 1.041860, -1.428510, 1.990380, -0.491100, -0.108410, -1.308210, 
-2.559130, -1.045940, -0.452470, 0.349410, 0.923240, -2.844950, -2.538810, 0.336510, 1.246460, 0.033610, 
0.320530, -0.868690, 0.205560, -1.245790, 0.522290, -1.208750, -1.083900, -0.194230, -0.409270, 0.216820, 
0.746320, 0.506350, -0.623120, -1.189870, 0.816440, 1.315880, 0.522470, 2.077100, 0.106460, -0.459590, 
0.342230, 0.364870, -1.522010, -0.887200, 0.440680, 0.496600, -0.504950, 0.143390, -0.494200, 0.198590, 
-2.421090, 0.048890, -2.488550, -3.445060, 0.565500, -0.005430, 0.584520, -0.713330, 0.372940, -0.618240, 
0.507250, -0.811790, 0.502010, -0.526160, 0.017940, 0.104710, -0.489420, 0.603530, 0.398600, -0.531970, 
-0.761350, 0.079730, 0.146960, -0.115820, 1.190120, 0.265680, -0.795930, 0.936550, -0.322910, 0.320340, 
-0.042330, 1.368700, -0.072660, 0.969480, -0.218010, -0.296140, 2.086560, 0.497590, -0.417300, 
-2.880240, -1.541290, -1.467300, -0.071440, 0.243000, 8.989990, 0.954390, -1.437830, 0.135310, -2.228410, 
-0.354110, -0.078460, 0.191560, 0.024730, -0.537560, 0.322050, -1.104250, -2.214960, -0.099690, 0.617620, 
0.463690, -0.999810, 2.168890, 0.396770, -0.943540, -2.771980, 1.471010, -0.873040, -0.546740, 0.583510, 
-3.170760, -2.078050, -1.881610, 0.356520, 0.103370, 0.050910, -0.839960, -1.080450, 0.230530, 1.165140, 
-2.999870, 0.151580, -0.667740, -0.053080, 1.499130, 0.035490, -2.143520, -2.875110, -1.081790, 0.545840, 
0.309170, -0.613150, 0.804830, -0.036100, -2.367380, -2.669340, 1.006650, 0.657560, -1.191250, 0.652010, 
-2.502270, 0.659040, 0.447560, -1.029510, 2.380720, -2.432940, -0.042660, -0.528480, 3.906060, 0.745370, 
1.031170, -0.273410, 0.537600, -1.428710, -0.266070, -0.958690, -0.832760, -0.862730, 0.461760, 1.485220, 
-1.591200, -0.013630, 0.744050, 0.856230, -1.528590, -0.594210, -1.161820, 0.714020, -0.852240, 1.051870, 
-0.465770, 0.481250, -0.580230, 0.410430, -0.314900, 0.248150, -1.203130, 0.470950, 0.229430, 0.861080, 
-0.165020, -0.214850, -0.960660, 0.061070, 2.677300, -0.451990, -0.542150, -1.735800, -0.547850, 0.099510, 
0.157940, 0.584700, -0.146980, 1.164370, 1.013560, -0.698360, 0.293490, -1.764290, 4.253530, -0.191790, 
-3.522250, 2.525730, 1.076070, -0.099680, -1.438650, 0.979600, 0.716710, 1.288000, 0.034880, 1.061130, 
0.896780, 2.703300, 0.271890, -0.891630, 1.807150, -0.008120, 0.236370, -2.919810, -0.111810, -2.123290, 
-1.461900, -0.946270, -1.931020, 0.001290, 1.971480, -1.069240, 1.609650, 0.121990, 0.225670, 0.540500, 
-0.214400, -0.616820, -1.625080, 0.555480, 1.511790, -4.260980, -1.074800, -0.748380, 0.935880, 0.790090, 
2.614420, 0.079520, 0.810640, 0.048380, 0.896790, -0.139610, 0.674500, 0.064270, 0.055370, -0.384290, 
-2.588860, -0.244080, -0.920430, 0.231950, 0.983310, -0.112470, -0.836970, -1.796640, 2.801080, -0.964570, 
-3.207590, 0.831500, 0.252500, 0.530280, -2.795030, 0.569460, -0.050140, 0.332430, 0.879270, 0.873590, 
1.226610, 1.256910, -0.375800, 0.086740, 0.548040, -1.013860, 0.938100, 0.381850, -0.173520, 0.664260, 
-0.130520, -0.182870, -0.898290, 1.792220, 1.550970, 0.742900, 1.745940, -2.194490, -0.735800, -1.647710, 
1.292530, -2.046510, -3.794130, 0.687170, -0.562680, -1.799990, -6.409300, 0.705530, -0.775220, 1.324690, 
-1.303080, -0.625240, -0.110440, -0.575510, -1.848570, -2.378010, -0.469080, -0.185540, 1.835810, 0.915460, 
0.714760, 0.754020, 0.586110, 0.870660, 0.917870, -0.679550, -0.956970, 0.692390, 0.355370, -0.738450, 
-0.351450, 1.439580, 1.548230, 0.023800, 0.667900, -1.771160, 1.223880, -0.583610, 0.029910, 0.523160, 
0.093020, 0.215000, -1.254280, 0.552930, 0.974970, 0.317090, -0.127760, -0.202250, 0.311140, -0.876510, 
-1.886180, 1.564940, 4.892410, 0.706170, 1.473670, -1.336920, 0.268460, 1.716510, 0.135900, 1.640980, 
1.364440, 0.067900, -0.923870, 0.152150, -0.297990, -0.756310, -0.165370, -0.731360, -0.778760, 0.943700, 
-1.858710, 0.680770, 0.303260, -1.702370, -0.475460, 0.637630, -0.248690, 0.575450, 0.363890, -1.209620, 
0.807940, 0.054820, 0.364530, 0.848390, 0.619800, -0.301990, -0.010180, 1.230730, 0.626920, 
0.087320, 0.347060, 0.432310, -2.615760, -1.651970, 0.889940, -1.741380, 0.362190, 1.797470, -0.552600, 
-0.926090, 0.012280, -0.593100, -0.361740, 0.791190, -0.205630, -0.901660, 1.122190, -1.798540, 0.509070, 
-0.206560, -0.234290, -0.484710, 0.051360, -0.692890, -0.089170, -1.408740, 0.106440, -2.015480, -0.348450, 
-0.762320, -1.460970, 1.088030, -2.212720, 1.564380, 0.188720, -0.305720, -0.540860, -7.832090, -0.830230, 
-0.148280, 1.308440, -0.517130, -0.393960, 0.329860, 1.571960, 0.382830, 2.100430, 2.066470, 1.337580, 
0.315050, -0.235300, -7.335590, 2.491270, -0.219200, 1.620630, -0.644270, 1.119020, -0.867610, 1.318310, 
0.036050, -0.828860, -0.200110, 0.538140, -0.229260, -0.746860, 0.270680, -0.548800, -0.279090, 0.172990, 
0.166020, -0.245340, 1.977350, -0.371100, 0.507480, -1.670870, -0.354210, 0.523850, 0.291790, -1.656070, 
-0.854460, -1.082100, 0.464410, -0.845730, 0.326160, 0.740150, -0.796840, 0.433290, 1.691480, -1.188760, 
-1.058570, -0.034430, -0.569380, -0.545940, 0.303520, -0.345740, -0.431120, 0.542800, -1.373380, 2.135200, 
-0.420430, 1.684410, 0.134750, -1.040420, -2.249670, -1.269430, 0.372660, -0.396020, -1.087090, 0.318580, 
-0.826730, -0.967260, 0.026890, 0.163780, 0.537090, -0.444930, -0.625180, 2.587980, -1.064020, 1.432170, 
-1.446430, -4.369480, 1.521760, 5.246220, 5.901160, 0.569100, 0.481790, 0.622460, 1.539330, 1.107000, 
1.608060, -0.133530, 3.975480, -0.752430, -0.958780, 5.673960, 0.245870, 0.723820, -0.324610, -0.133720, 
-0.561610, -3.317800, -0.584360, -0.271760, -0.143730, 1.706500, -0.922200, -0.597360, 0.073530, -0.794930, 
-1.936160, -0.645190, -1.224370, 0.081860, 0.147700, -0.312530, 1.324580, 0.753090, -0.663100, 0.912370, 
1.314580, -1.077210, 4.356840, -0.593230, 1.664740, -3.317410, -0.517380, 1.019070, -1.174620, 0.116330, 
0.189520, -1.049420, 2.378040, 0.380020, 0.759880, 0.744730, 0.340970, -0.332280, 0.227630, 0.289200, 
-0.952290, 0.890800, 0.236110, -2.880610, -1.741640, 0.822360, 0.202210, 0.456230, -0.178840, 0.903990, 
-0.649150, 0.012440, 0.452370, 0.310080, 0.516770, -0.050650, -0.086070, -0.719020, -0.529570, -0.144320, 
0.294460, 0.060570, 0.324420, 2.984400, -0.810560, -0.017420, -1.176650, 0.604320, 0.739960, 0.460150, 
-0.113940, -0.839480, 0.101370, -1.735370, -0.656550, 1.074730, 2.239420, 1.619860, 0.266280, -0.216620, 
-0.147390, 2.850670, 1.072720, 0.499350, -0.883370, -0.780800, 0.009970, -0.203400, 1.511930, -1.099640, 
0.091890, 1.562750, 0.817690, -2.244340, -0.164450, 0.101920, -1.304890, 0.249170, -0.071850, -0.352800, 
-0.808650, -0.698040, -1.138520, -6.176270, -0.411550, 0.403170, -1.161590, -0.257050, -0.097660, 0.120060, 
-1.735030, -0.576950, -0.088230, 0.207610, 0.330680, 0.634320, 0.101950, 0.080030, 1.494700, 0.745900, 
1.046390, -1.157300, -2.352920, -1.652710, 1.949420, -0.956380, 0.003570, -0.920470, -0.227330, -0.064460, 
-1.216380, -0.419950, 0.506570, 0.523150, -0.701070, -1.105710, -0.306270, -0.492410, 4.344960, -0.317750, 
1.477450, 0.391330, -0.443260, -0.287340, -0.927420, -0.916710, 0.341070, -1.287390, -0.102190, 0.691480, 
-1.272990, -0.726690, -0.878070, -0.057530, -0.741870, -1.042700, 14.268160, -1.850230, -0.885800, 
-0.239480, 0.402380, 0.739140, 0.026940, 0.441250, 0.182730, 0.012160, 0.657880, -0.382240, -0.896100, 
-0.391130, -0.333110, -0.196330, 2.464190, -0.910830, 0.108880, 0.392620, -0.625810, 0.048960, -0.324040, 
-0.165490, -0.891610, -0.151030, -2.041830, -0.239130, -0.111250, -1.124840, -0.244010, -1.077730, 0.630520, 
-0.034320, -0.226940, -1.155660, 0.321540, 0.855420, 1.148310, 0.210570, -0.692410, 2.211570, 0.405330, 
-0.474920, 0.795920, -0.546740, -0.301230, 1.446040, 0.360360, 0.206240, -0.240660, -0.794870, -0.296510, 
-1.124850, 0.848610, -0.947730, 0.033260, -0.234260, -0.744420, -0.714030, 0.198110, -0.308160, -2.509750, 
-0.983410, -0.415450, -2.985940, -2.334190, -0.273740, 1.929770, -0.229040, 1.302890, -1.007700, 0.738080, 
0.515980, -0.472880, -1.310780, -0.954200, 0.519230, -0.091650, 0.037910, -0.744730, 0.117050, -0.241290, 
-0.491590, -0.025960, 0.969140, 0.248380, 0.615850, -0.196620, 0.466900, -0.210400, -1.496080, 1.122780, 
-0.123290, -0.119180, 0.623180, 0.863470, 0.650780, -0.472870, 0.496250, 0.042480, -0.363850, 0.931000, 
-0.218910, -0.665910, 0.565220, -0.067320, -0.055090, -0.477690, -1.651260, -1.436910, 0.044470, 1.109940, 
-0.010780, 0.282630, -0.851850, 1.511280, 1.481760, -0.535540, -0.404940, 0.792940, -6.023670, -0.580390, 
0.382750, 0.781470, 1.048980, 0.677120, -1.019480, 0.220280, 0.904300, 2.272800, 0.570720, -0.107960, 
1.719790, -0.221320, 0.536860, -0.582280, 0.709610, -0.308570, 0.163510, 0.859780, 0.677700, 3.037270, 
-0.307520, -0.618080, -1.140530, 0.849950, 0.015440, -0.582110, -2.403570, -0.646760, 1.005900, 0.776730, 
0.923470, 2.527630, -1.369230, 0.053360, 0.970960, -1.023940, -1.468590, -0.010550, -0.320680, -0.197690, 
0.737200, 0.216030, 0.541160, -0.099420, -0.653380, -0.423290, -0.262610, -0.626460, 1.333750, 0.279550, 
0.270590, 0.202470, -1.317220, 0.281990, -1.355660, 1.074170, -0.821040, -0.488610, 0.031740, -0.130100, 
-0.653630, 1.113470, -0.508140, -0.560100, -0.885430, -0.027280, -0.745390, 0.929080, -0.212750, -1.012690, 
-0.418010, 2.863260, 0.821680, 0.153530, -0.933800, 0.361020, 1.742530, -1.772370, 0.396190, 1.718100, 
0.253720, -0.420350, -0.444580, -0.036460, -0.414870, 0.135710, 0.390820, -1.061850, -1.346390, 0.966850, 
-1.461550, -0.095010, -1.373290, 0.394450, -0.720700, -1.365350, -0.643040, 1.039230, 0.491170, -0.403950, 
-0.152670, 0.291930, 0.846940, 0.291870, -0.383020, 0.381400, -3.117210, -0.127730, -0.498180, -0.843870, 
0.495730, -0.203050, 0.682510, -0.829160, -2.337860, 0.422210, -0.437880, 0.029210, -0.716720, 0.691840, 
1.016710, 0.469510, -0.751240, 0.279800, -0.127080, -0.731900, -0.290220, 0.811680, -0.023920, -0.482240, 
0.408160, 0.178700, -0.131850, 0.430420, 0.623170, -0.360620, -0.344770, -0.251620, 0.596470, 0.797410, 
1.423180, -0.033160, 3.659500, 0.177570, -1.524630, 0.935130, -0.423700, -1.288360, 0.626500, 1.580390, 
0.790320, 1.424380, 0.358530, -0.373610, 0.905480, 0.513000, 2.485990, -0.039210, 1.461370, 1.670170, 
1.092780, 1.146770, 0.858850, 1.295680, 0.963930, 1.154420, 1.023980, 0.955670, 0.638770, 2.298390, 
0.338690, 0.138470, -0.143600, 1.089590, -0.154710, 0.937150, 1.978720, 1.928310, 1.025400, 
-0.340140, 0.009260, 1.679650, 0.508020, 1.663360, 3.187690, 0.247580, 0.584110, 0.284160, 2.619250, 
-0.525790, 0.929850, 0.975850, -1.546820, 0.094040, -0.369720, 0.838630, -1.381500, -0.337430, -0.174050, 
0.104870, -0.054480, -0.545640, 0.733560, 0.078760, 1.351650, -0.706850, 1.440620, 1.020860, -1.013810, 
1.201070, 0.473220, 1.433970, -1.062190, -0.430090, 0.051580, -1.017340, 0.058620, 1.157370, -0.691410, 
2.444610, 0.257980, 0.368440, -0.512150, -1.834460, -3.335480, -0.044320, -0.209060, 2.603580, 0.480300, 
-0.057200, 0.210800, -0.819970, 3.137970, 2.709150, 2.204540, 1.098280, 0.359040, 0.362390, -0.776830, 
0.296670, -0.407410, -0.676390, 8.136900, -1.154320, -0.062000, -0.386980, -1.595200, -0.866330, -0.549050, 
0.162290, -0.382370, 0.783300, 3.417740, 2.604810, 0.405830, -0.805960, 2.075460, 1.080110, -1.933460, 
0.952980, -1.222380, 0.112920, 0.168660, -0.277180, -4.155980, 3.657120, -0.278880, -0.730330, -0.886950, 
-1.061120, -0.920740, -0.592140, 0.323040, 1.023270, -0.016760, 1.577660, 0.875330, -0.100770, 0.049260, 
1.078930, 3.612330, 2.262460, -1.186140, 0.504800, -0.215110, -0.247260, -0.388110, -3.306080, 0.449260, 
2.989570, 1.028890, 0.274190, -1.943870, -0.837270, 2.973950, 1.075130, 3.180280, -1.324870, 1.507670, 
1.548530, -1.948720, -2.349090, 3.692650, 8.019260, -3.219970, -4.594500, -2.501820, 0.606140, 0.089750, 
-2.435200, -1.376850, 7.673410, -1.340640, -1.751330, -0.092160, -1.329610, -1.995420, 0.443150, -1.816700, 
0.977110, -2.620360, 0.433490, 1.053580, -1.268340, 1.429950, 0.465280, 2.224660, 0.577850, -0.515830, 
-1.250480, 1.597060, 0.047880, -0.800110, 0.047000, 2.122390, 1.048340, -1.721680, -0.130730, 0.661920, 
-0.373200, 2.445940, 1.933930, -0.628210, -2.745650, 0.376250, 2.365030, -1.011110, 2.448530, -0.585580, 
0.390910, -0.790120, 1.338610, -0.252890, -0.385610, -0.646880, -0.222770, 0.563260, -0.531700, 0.179140, 
-0.239280, -0.865380, 0.479840, -2.769150, 0.163910, -1.932480, 1.071320, -0.746920, 0.302030, -1.069980, 
-0.129320, -0.231770, -0.473640, -0.943550, 0.402150, 1.781980, -1.602960, 0.378340, -0.678100, -0.956570, 
-0.793750, 1.164720, -0.137160, -0.184120, 0.206160, -0.113880, -1.662490, -0.184560, -0.935920, 0.006910, 
-2.130370, -0.811840, 0.916420, -0.635620, 1.044740, -0.151880, 1.439120, 1.312760, -0.937090, -0.170170, 
-1.611420, 0.112730, -0.826080, 0.047670, -1.630380, -0.862480, -1.713340, -0.516610, -1.392140, -0.860500, 
-1.169710, 1.135920, -0.489540, -0.628370, -0.378880, -2.349240, -0.250460, -0.898140, 0.226420, 0.699890, 
-0.150100, 1.086270, -0.242760, -1.037190, 0.393690, 1.176570, -2.295990, -0.039300, 1.051480, -0.095810, 
-0.837410, -0.351010, -2.252310, -3.113070, -0.912580, 2.125500, -0.988270, -2.898970, -0.703490, -0.193070, 
1.366740, 0.226090, -2.644960, -3.113180, 2.413600, -0.200090, 1.153530, -0.672220, -0.634850, -1.600620, 
-0.111590, -0.604610, 0.589640, -0.359100, 0.178260, -0.149780, -0.704730, 0.645470, 0.665160, 0.102510, 
-0.658710, -0.502500, 0.075830, -0.709120, -0.787330, 0.143530, 0.101610, -1.086870, -0.102910, 0.571220, 
0.085840, 0.196680, 0.346670, -0.980880, -1.037180, 0.832850, -0.477840, -0.085300, -0.242920, 
1.304180, 0.217100, -0.659510, -1.052700, -1.556110, -1.171550, 0.076560, 2.664070, -0.910590, 0.746250, 
0.179320, 0.493460, 1.553240, -0.575230, -1.511880, -0.227130, 1.812450, -1.421270, 2.220250, -0.398160, 
-0.720800, -6.270140, 4.903570, -0.288970, -1.625490, -0.782660, 0.656850, 0.011910, -1.099690, 0.940820, 
0.852160, -0.011340, -1.575530, -1.863570, 1.798280, -0.205850, 0.284920, -1.553680, -0.401220, -0.716970, 
-0.543800, -3.963020, 0.788150, 0.206140, -1.090360, 3.535170, -0.881120, -1.164000, -2.346700, -0.896510, 
-2.002850, -1.158960, -0.061780, -0.702820, -1.015760, -0.862780, -0.424250, -1.440190, 0.923430, -1.523350, 
1.986860, -0.428700, -0.372790, -0.438600, 1.847150, 1.234610, 0.681100, 0.374750, 0.900810, -0.257010, 
-0.783780, 2.658220, -1.218890, -1.560560, -1.158140, 0.385150, -4.535170, -3.808230, -0.543330, -0.087880, 
-0.610830, 0.899320, -0.922510, -2.575950, -0.340420, 0.100120, 1.466070, -0.723930, -0.006260, 0.498530, 
0.884530, 0.162360, 0.559450, -1.855250, 0.766290, 0.387650, -1.111620, 0.463800, 1.690880, 0.885430, 
0.092260, -0.801050, 0.401350, 0.346760, 0.614230, -0.507520, 0.411210, -0.025650, -0.384670, -1.210690, 
-0.915540, 1.412660, 0.723270, -1.257770, -0.928600, 1.668130, -60.909451, -0.526440, -3.845510, 1.333480, 
-0.633280, -0.608300, -1.258750, -0.254490, -0.780820, 1.922500, -0.051200, -0.874210, -36.471191, 3.073980, 
-0.475320, -0.285740, -0.343430, -1.172930, -0.312690, -2.939070, -1.749860, 0.863560, 0.454350, 0.435700, 
0.117830, -0.669790, 0.153100, 1.482400, 0.074560, -1.677980, -1.075800, -0.418070, 1.647390, 0.264070, 
1.310350, -3.151380, -0.597290, -0.398450, -0.911610, 0.765830, 0.185560, -0.756730, 0.148230, 2.438480, 
-3.473530, -0.872560, -10.627670, -0.515080, 2.496920, 2.094380, -1.705160, -1.306110, -1.442430, 0.294500, 
-0.804300, 2.958720, -1.799290, -0.504250, 0.394950, -0.256990, 0.238000, 0.312120, -1.149750, 0.183470, 
0.309330, -0.114780, -0.613790, 0.825180, -1.589640, -3.786940, 0.016120, -1.314340, -1.611400, -1.409460, 
-1.534990, -0.803970, 1.166650, 0.775990, 0.415870, -0.631460, 0.067080, 0.973300, 0.847910, -0.716760, 
-0.058510, 0.293320, -1.205330, 1.317360, 0.712640, -1.324450, -0.348150, 0.702090, -1.864180, 1.174380, 
0.095790, 0.546640, -1.169840, 2.904370, -0.987370, 0.307680, 0.003840, -0.460200, -1.076490, 1.513940, 
1.076110, 0.148370, -1.254010, 0.263940, -0.378300, -1.118390, -0.377640, 0.704300, 0.021860, -1.247700, 
0.142020, 0.457230, 1.918340, 0.568740, 0.148640, 1.124140, 0.279300, -0.097900, 1.718000, -0.014470, 
-1.302250, -0.771280, 2.923370, 2.486280, 0.257930, -1.184430, -2.196420, -0.231710, 0.150370, -0.160660, 
0.752530, 0.777170, 0.325750, 3.683970, -0.265770, 0.317460, -1.130220, 1.365680, 0.269870, -0.214150, 
-0.038930, 1.489570, 1.127760, -1.061830, -0.720980, -0.764260, 0.121540, -1.011620, -0.365800, -0.399350, 
0.816200, -0.602930, 0.728110, -0.826380, -0.880360, 0.106750, 2.480440, -0.373650, 0.837630, -0.671610, 
-0.441580, 0.926920, -0.987760, -0.253320, -1.014040, -0.185850, 0.090700, -0.447370, -0.083840, -0.475260, 
-0.136140, -0.813630, -0.401120, 0.137520, 0.325570, -0.120190, 0.052770, -0.795650, 0.381750, 
-1.249130, -0.041350, -0.679120, 0.609970, 0.114360, -0.145730, 0.103540, -0.759510, -0.890440, -5.711980, 
0.470380, 0.227150, -0.359600, 1.276550, 1.996730, -1.250370, 0.801720, -1.522530, 0.664250, -0.878230, 
-0.109820, -0.673360, -2.890460, -0.593180, 1.010960, 0.834470, 0.725220, -0.621190, 0.128360, 0.618570, 
-1.211500, -1.341270, -0.196980, -1.748890, -0.322950, 0.089880, 1.421870, -1.898800, 0.721840, -1.795460, 
-0.913080, 0.914490, 1.982950, 0.279210, 1.048790, -0.217390, 3.310640, -0.792820, 0.094670, 0.025820, 
-2.724970, -0.305900, 0.552880, 0.749780, 0.797110, -0.804820, 0.889840, -0.353910, 0.640870, 0.852190, 
-0.118490, 0.922950, 1.109770, -0.873160, -1.192870, 0.401490, 1.006200, -0.930620, 0.963660, -0.744450, 
-1.027960, -5.272220, 1.077200, -1.970820, -0.615470, 0.779080, 3.937450, -5.036560, -2.968060, 0.917050, 
-1.355840, -0.320220, -0.510620, 0.606640, -0.210520, 0.147160, -0.873930, -0.141200, 0.260810, 0.339600, 
7.007930, -0.502630, -1.455380, -0.269720, -1.796950, -0.021820, -0.511560, -0.011210, 0.940330, -1.165280, 
-1.796840, -1.525790, 0.925670, 1.333630, 0.474900, -0.536020, -0.790520, 0.849270, -0.766210, 0.983910, 
0.024280, -0.570200, 0.266760, 2.342830, -0.132840, 0.491860, -0.502820, -1.399240, -1.824250, -1.626500, 
6.049960, 0.208540, 1.163780, -1.464830, 2.382940, 1.823150, 1.541860, 0.979170, 2.303340, 0.804160, 
1.183630, 1.106350, 0.665590, 0.787030, -0.417820, 5.908790, 1.214400, -3.885920, -0.485660, 0.428760, 
0.077160, -0.719060, -0.364940, 0.512040, -0.016100, 0.375840, 0.910780, 0.296570, 0.457260, 0.365360, 
-2.181690, 0.088760, 0.163010, -0.024290, 0.053120, -0.117300, -1.177570, 1.269310, 0.789250, -0.028110, 
-0.923220, -0.224520, 2.799770, 4.493460, -19.798731, 0.139230, 0.038410, -0.255310, -1.252380, -0.151280, 
-0.730360, -0.368440, 0.106570, -0.334050, 1.343090, 0.738620, 1.727320, -1.687320, 4.147770, -0.791940, 
0.283400, -1.007430, 0.458470, -1.522850, -0.307450, 6.202340, 0.119550, -0.548760, -1.018810, 0.982980, 
-0.170360, 1.364560, -0.548500, -0.018880, 0.835680, -0.025040, -0.966660, -0.201090, 0.330380, 0.349560, 
1.533650, -2.636030, -0.954200, 1.934820, 0.624900, 1.239830, -0.462050, -0.815130, -0.835640, 0.220590, 
0.846060, 1.510370, -0.826780, 0.212500, -0.801730, 0.446620, 1.170350, 0.161460, -1.777470, -0.411080, 
0.238490, 1.285830, -0.545060, -1.778630, -1.288790, -0.407570, 0.241090, 0.982500, -0.538830, 0.959600, 
-0.102540, -0.337080, -0.417860, -0.672750, -0.897730, 0.910200, 0.204170, -0.168520, -1.180140, 1.149790, 
1.190920, -0.928120, -0.753450, 0.035520, 0.551540, 0.421250, -0.679440, -0.295280, -0.686740, 0.005670, 
-0.067200, 0.629790, 0.845520, 0.007190, 0.459540, -2.178050, 0.313890, -0.207760, -0.382920, 0.521250, 
0.968900, -0.082900, 0.892200, -0.866950, 0.161870, 0.770070, -0.725560, 0.970980, 0.790990, 0.679990, 
-0.676520, -0.288540, -0.469060, 0.499700, 0.876480, 0.722680, 0.761450, -0.587180, 0.498420, 0.259730, 
-0.341410, -0.672710, 0.476580, -0.296830, 1.080940, -1.733690, -1.217630, 0.512020, 0.294170, 0.488230, 
-0.758440, 0.817430, -0.665910, 0.029730, 0.148070, -0.372250, 0.485400, -0.249030, -0.304200, 
0.071820, -0.052920, -0.304730, -0.648980, 1.206540, 0.546150, -0.244110, 1.206860, -0.648980, 0.776610, 
1.661680, 0.926850, -1.840410, -0.323300, 0.536750, -1.551070, 0.445600, -0.238250, -0.959020, -0.368160, 
-1.608380, 0.689270, -2.198950, 1.663940, 0.241650, 0.768820, 0.577720, 0.164830, 0.654450, -0.575990, 
1.535730, -0.301250, 1.293780, -0.586180, -0.334730, 0.333890, -0.983970, -0.949170, 0.005250, 0.668390, 
1.043150, 0.183980, -0.044510, -0.029160, 0.455200, -0.652270, 0.303440, -0.315110, 4.103300, 1.190320, 
-0.593760, 1.265960, -4.468110, 2.037470, 1.514940, 2.406720, -0.407720, -1.499850, 0.245460, 0.651990, 
1.005380, -0.716490, 0.777700, 0.651530, -0.621070, -1.560990, -0.658720, -2.399960, -1.171510, -0.118800, 
0.108230, 0.783390, 1.412160, 1.359410, 1.693200, 2.140530, -0.335880, 0.213040, 1.196880, -0.795390, 
0.926530, 0.983790, -1.448700, 0.190850, -1.765380, -0.467210, 0.995820, 1.291490, 1.009960, 0.050100, 
-1.267070, 0.520930, 0.967300, -0.890670, 1.517650, 0.427100, 0.834850, 0.018560, 0.237370, 0.901130, 
0.880140, 0.619000, -0.070020, 0.070720, 0.743050, -1.773900, 0.029400, -0.092920, -1.097850, -1.257000, 
0.067400, 0.939980, -0.081910, 0.168320, -0.805430, 2.969020, 2.749470, 1.414400, -0.264310, 3.281450, 
0.157410, -4.129500, 2.421910, 2.899250, 0.707680, 0.014070, 1.917750, -0.174130, 1.299380, 4.233420, 
0.834310, 1.290310, 16.811840, 0.505670, 0.803400, 0.902640, -0.045550, 1.771960, 0.870120, 4.021330, 
-0.740020, 0.170870, -0.223030, -0.281390, -1.785100, 0.256890, -0.295670, 0.017700, 1.497950, -1.237060, 
1.563020, 0.076620, 0.606730, 0.460580, 0.415290, 0.054310, 0.355280, -0.117110, -1.695110, 0.583090, 
1.391910, -0.970390, -0.300030, 1.334670, -3.524900, -0.180360, 0.318250, 0.140640, 0.586630, 0.262020, 
-0.983130, -0.190540, 0.789770, -0.482050, -0.152280, -0.302890, 0.366210, -0.108100, -0.086230, 0.794560, 
-0.323330, -1.016570, -0.055500, 0.327480, -0.458690, 0.220710, 2.422920, -2.939570, 1.559370, 2.390000, 
-0.182350, -1.020090, 1.154130, -0.321300, 1.275130, -0.010490, -0.042470, -1.056640, 0.046030, -0.862010, 
0.499510, -0.722900, -0.517400, -0.923190, 0.779850, -0.391960, -0.678440, -0.689530, 0.848520, 1.089280, 
-1.400000, 1.247380, 2.226890, 0.066310, 0.634850, 0.679350, 0.094620, 0.817060, -1.117090, -1.428900, 
-0.166490, 0.016850, 0.321220, 0.372080, 0.413900, -0.141850, -0.250370, -0.231770, -1.209850, -0.820460, 
0.460940, 0.088580, 0.457360, -0.426990, 1.268480, 0.315480, -0.244740, -0.610990, 0.599070, 0.525660, 
-0.418210, 0.535300, 0.769840, -5.785010, 0.711770, 0.615730, -0.414160, 1.356370, -0.086170, -0.072100, 
-0.258210, 1.028810, -4.146480, 0.506250, 0.657420, 0.311430, 0.556750, -0.448380, 0.067150, -0.744000, 
-0.804300, 0.239450, -0.268450, -0.798450, -0.013400, 0.733570, 0.897980, 0.396410, 1.681330, -0.480920, 
-0.464770, -0.556440, 0.645590, 0.772160, 0.111380, -0.017650, -0.941220, 1.272240, 1.093740, 0.816680, 
-0.498990, 0.826170, 0.423420, 0.253350, 1.261680, -0.236740, 0.314460, 0.313510, 0.799170, -0.277870, 
-0.308610, 0.288190, 0.120200, 0.599270, -0.244730, -0.805790, 2.632000, -0.271430, 0.803860, 
0.548240, 0.018420, -1.224170, 0.525460, -0.578290, 0.481700, 0.417640, -2.403670, -0.253560, 0.209600, 
-0.849350, 1.480600, 1.229570, -2.342590, 0.692360, -0.899150, -0.016600, -0.287810, 0.376220, -2.083280, 
-0.634080, -1.613110, 0.714580, -0.633710, 0.218510, -0.291980, 0.506430, -0.554390, -0.698270, 1.108070, 
-0.919810, 0.038870, -3.046570, 0.910220, 1.046610, -1.357600, -0.452120, -0.484770, 0.079690, 0.020530, 
-2.458550, -0.116120, 0.492210, -0.651080, -0.268550, 3.003160, 0.506260, -0.476640, -0.305470, 1.038610, 
0.105240, -0.039510, 0.682090, -1.800480, -1.487010, -1.798900, 1.136410, 0.541470, -0.168540, 1.518480, 
0.087870, -0.380790, -0.203600, -0.692350, 1.525230, -0.372810, 0.561910, -0.259580, 0.575500, 0.826950, 
-0.392440, -1.074050, 0.804970, -1.865550, -0.470060, -0.587990, 0.031140, -0.713000, -1.004500, -0.063520, 
-0.065950, 0.683480, 0.314540, 0.355060, -0.023020, -0.575430, -0.958260, 0.521350, 1.369420, 0.318790, 
-1.042850, -1.189980, -0.266170, 0.626820, 1.336240, 0.745840, 0.557880, -0.822850, 0.053330, 1.835600, 
2.812840, -1.484240, -0.415780, -1.567220, -0.475280, -0.406180, 0.754330, 0.408630, 0.295660, -2.175210, 
-0.896160, -1.778010, 1.006280, -0.958500, -0.062680, -4.605170, -7.606630, -2.980510, 0.381000, -4.606640, 
0.775130, 2.666240, -2.165060, -4.169030, -8.470050, 0.455670, 0.648670, 1.512140, -4.776660, 0.823530, 
-0.337220, -0.076400, -19.803160, -1.913270, 0.982470, -1.800280, -8.802960, 2.805520, -1.387510, -0.555400, 
1.355160, 1.231740, 0.663170, -2.397390, -1.172030, -0.795360, -0.923090, 0.758150, 0.304860, 1.247330, 
-0.357490, -0.396840, -0.803280, 1.133960, -0.497240, -1.109220, 1.338040, 1.284070, 0.628310, -0.292510, 
3.007900, 0.494170, -0.283660, -0.002590, 1.555850, 0.883230, -2.042240, 2.536380, -1.499200, -0.043120, 
-0.842700, -0.063200, -0.782460, 0.193520, 0.294640, 0.597110, 0.061780, -0.131630, -0.662380, -0.561260, 
-1.958540, 0.909800, -0.890820, 0.928450, 0.834880, -2.900010, -0.403330, 2.126130, 0.675590, -2.225940, 
0.846940, 0.716490, 0.332940, -0.588790, -3.138120, -1.564950, -0.556740, 0.496040, 1.352240, 1.224070, 
-0.118490, 0.592590, -0.086240, 0.053720, -0.131080, -1.978640, 1.618010, -2.529280, -3.381230, -1.281260, 
2.824730, -0.509640, -0.277050, 0.655440, -1.228680, -0.467450, -0.895100, 1.294090, 0.185250, 1.037450, 
-0.052550, -1.322500, -0.114930, 1.273210, -1.886090, 0.526330, 0.306290, 0.665400, 0.470860, 1.153950, 
0.001640, 3.896150, 2.325500, -0.899940, -0.291250, -0.472970, 0.708100, -0.609590, -1.206500, -0.365970, 
-0.866850, -0.559230, 2.520520, 0.426410, -0.593100, -0.179080, -0.974230, -1.237300, -0.663350, -2.406500, 
0.307070, -0.508280, 3.439200, -19.190500, 0.199570, -1.123810, -0.742330, -0.481100, -0.820350, 1.141390, 
-0.828600, -0.216940, 1.186480, -0.649690, -0.631970, 1.100020, -1.167590, 1.214840, 0.733550, -0.618680, 
-0.198680, -0.075410, -0.221030, -0.866840, 0.887990, 0.775730, -0.452590, -0.211810, -1.303710, 0.787430, 
0.510860, -0.977310, -0.510340, 0.327700, -0.811590, -0.630750, -0.918200, -0.180530, 0.629470, 0.439320, 
-0.983110, 0.585870, 0.019920, 0.584660, -0.997660, 0.667970, 0.732060, -0.379350, -0.533410, 
1.227230, -0.695010, 0.748990, 1.225530, -1.004110, -0.799940, 0.485480, 0.884080, -2.163830, 1.413530, 
0.814490, -0.354230, 1.114970, -0.050710, -1.585780, 1.778730, 0.649070, -0.362620, 0.151010, 0.463510, 
3.639160, -0.721940, 0.727140, 0.047980, 1.680240, 1.842930, -1.492330, -0.483510, -0.031360, 1.135470, 
-1.658250, 0.089650, 1.201220, -1.767300, 0.157720, -0.933410, -1.341830, 0.285090, -1.123300, 1.179370, 
-1.945620, 1.826860, -2.361880, 2.069140, -0.526330, -0.774370, -1.033700, -0.431990, -1.153880, -0.194870, 
1.011300, 0.355800, -0.288850, 0.267970, 0.927530, 0.502110, 0.213710, -0.330540, 0.073510, 1.556690, 
0.099550, 0.957060, 0.888680, 0.677800, 0.627750, 1.880630, 3.956750, -0.995320, 1.833110, 1.268170, 
1.427620, 0.624590, -0.934110, 0.937670, 0.816870, 3.557710, -0.122320, 1.310580, 0.571230, 0.536380, 
0.584860, 1.789060, -1.025010, 0.148120, -1.908960, 0.107390, 0.670680, 1.053480, -0.541460, 0.312070, 
-0.769960, -1.359260, 0.170710, 2.020560, 0.530110, 1.425870, -0.881600, -1.949630, -2.241620, 2.037560, 
-0.465950, 0.490660, -0.517700, 0.904610, 0.994100, 0.713930, 0.917430, 0.087610, -0.269250, 1.272440, 
2.306600, -1.283140, 0.220300, 0.196160, -0.137110, 2.388240, 1.311830, 2.766320, 1.364980, 10.402830, 
-0.559080, -2.096820, 3.579350, 4.672880, 8.293110, -3.265610, -0.381350, -1.997700, 7.771660, 1.794890, 
-5.748240, -6.873180, 6.035130, -7.344350, -0.169710, -0.945650, -8.790160, -0.502110, -0.560920, 2.396770, 
1.721600, 1.767750, 0.640380, -1.591060, -1.790350, 0.640550, 2.725380, 2.009700, -0.071650, -0.847140, 
0.281840, 3.078170, 0.068750, -0.685810, 1.267330, 0.191010, 0.188790, -0.079440, 2.004420, -3.836430, 
0.221310, 0.096410, 2.802390, -1.643420, -5.256640, 0.719520, -0.382360, -0.140360, 0.457270, 0.216110, 
-0.044850, -0.449840, 0.402850, -0.809130, 0.180340, 0.438900, 0.337560, 0.747670, -0.143370, -0.553600, 
-0.653180, -0.615950, 0.046020, 2.076770, 1.057640, 3.929920, 1.163420, 1.580140, 2.110450, -0.764880, 
1.296250, -1.183580, 4.423300, -0.152030, -1.041970, 1.071470, -0.621400, -2.150340, 0.703830, -1.904720, 
0.958460, 2.864370, 0.726650, 0.173290, -0.234320, -0.263900, 0.824520, -0.435200, -1.415330, 3.269620, 
0.875990, 1.898270, 0.796200, -0.375650, 5.366850, 2.688420, 0.238710, -0.004820, 0.647400, -0.091230, 
0.021920, -0.995690, 0.529720, -0.159560, 1.209510, -0.252040, 0.617580, -0.715510, -0.990640, -0.106830, 
-0.395570, -0.045320, -0.845840, 3.968900, -1.612960, -0.910350, 1.170730, -0.373210, -1.211070, 0.040190, 
-0.702830, 1.620270, -1.421050, -1.565520, -1.109280, 0.190880, -0.423720, 0.598200, -0.243470, 0.557630, 
0.776210, 0.479270, 2.384700, -0.976860, -0.147950, -0.853140, 0.429020, -0.472590, 0.068160, -2.724710, 
4.347930, 1.136220, -0.990480, -0.789010, 0.483340, -0.173040, 0.788480, 2.196600, 0.606380, 1.078690, 
0.411190, -0.047360, 0.545300, -0.336660, 0.844050, 0.544840, 0.261160, 0.367070, 0.682680, 0.731020, 
1.086160, 0.409840, 0.770170, 0.465310, -1.041470, 0.805750, 0.933700, -0.331670, 0.720020, -0.348670, 
0.743380, -1.088300, 0.783790, 1.493050, 0.232060, -0.673710, 0.165080, 2.231010, -0.611640, 
0.282520, -0.204340, 0.565070, 1.537150, -0.972670, 0.610710, -0.504800, 1.297250, 0.007830, 0.599850, 
0.131860, -1.534990, -0.229070, -2.529240, 0.549750, 1.032840, 1.751360, -1.550710, 1.371860, 0.410740, 
-0.102560, -0.921830, 0.168520, 2.308730, 0.512380, 1.178370, 1.162990, 2.289560, 1.788970, 1.363470, 
0.597660, 0.238100, 0.913370, -0.679850, -0.509300, -1.463610, 1.288950, 1.170230, -0.413220, 1.103130, 
0.099310, -1.138600, -0.254920, 0.657560, -0.298190, -0.935720, 1.825480, 1.401430, 1.824030, 0.137680, 
1.316000, -0.563300, 0.783980, 0.120380, 1.273210, 2.526640, -0.834590, 0.044760, 1.297950, 0.315870, 
1.482430, 0.454270, -1.511540, 0.840320, -1.088650, 1.003980, -0.022980, -1.577760, -0.413290, -0.648880, 
0.437230, 0.222110, 1.880440, 1.231370, -0.798160, 1.646180, 1.175190, -0.935760, 0.355890, -0.913710, 
-0.695270, -0.543040, -1.151520, -0.613660, -1.259820, -0.634760, 1.746880, -0.091290, -0.764400, 0.779410, 
-0.240920, 0.915380, 0.191470, -0.623000, 0.189270, -1.010100, -0.741740, -0.715210, -2.256410, 0.595570, 
0.329180, 1.595870, 0.620880, 0.021090, 0.187800, -1.149850, -0.033980, 1.681160, 0.274410, 0.591780, 
0.702020, 0.854970, 0.018240, 0.135500, -0.394750, 1.767000, 3.575360, 1.945340, -3.555890, 0.872830, 
0.370290, -2.328230, 1.699940, 5.927950, 1.045540, -1.449290, -0.197310, 0.045710, 0.990230, 1.486050, 
1.807460, 0.427090, 1.979880, -0.423420, 0.266550, 0.648490, -1.022860, -0.209710, 1.316070, 1.094390, 
1.763940, 4.530760, 1.793820, 0.048570, -1.790280, 1.318870, 1.670910, 2.208290, -0.538370, -0.991700, 
-1.403360, 0.510320, 0.681940, -0.394710, -0.742190, 2.311660, -1.174190, 1.020300, 0.859080, -0.525040, 
-1.632750, 0.114020, -0.786180, 0.635860, -0.766530, -0.183020, 1.072830, 0.547780, 1.725440, 1.118700, 
1.619240, -4.805500, 0.185200, -0.084120, -0.896320, 0.644680, 0.474070, -1.159840, 0.561560, -0.344740, 
-0.200460, -0.278480, 0.236070, 0.270390, 0.540430, -2.502770, 0.686780, -0.178090, 0.441830, 0.131270, 
1.804930, -0.525500, 0.451920, 1.001220, 0.105770, 0.465910, 0.967810, -0.101590, 0.045660, 0.802880, 
0.719490, 2.318740, 0.234240, 0.707870, -0.611460, -0.959850, -2.574880, 0.103530, -0.059440, 1.737700, 
1.079580, 1.737430, 1.477370, -2.194490, 2.098500, 1.506090, 2.376750, -0.014730, -1.846340, -0.663730, 
-0.927670, 0.607360, -1.788390, -0.850260, 2.093370, -0.148670, 0.492820, 0.484170, 0.314890, -0.313340, 
0.279860, 0.005570, -0.887040, -0.203070, 0.294680, -0.416470, 1.033060, -0.060840, 0.263580, -0.598890, 
-0.069280, 0.091770, 0.123940, -0.559330, -0.935660, 1.193250, 1.445950, 0.632370, 0.820610, 2.132710, 
-0.733820, -0.527580, 0.747540, -5.212480, -0.551280, -0.721850, -4.667940, 0.096610, 0.864180, -0.189340, 
0.447130, 0.264640, 0.704150, 0.213050, 0.267510, -0.758810, 0.080680, -0.163260, -0.405740, 0.725240, 
0.242930, 2.169880, -0.824060, -1.244280, 0.223480, 1.006810, -0.898140, -0.487550, -0.241750, -0.620340, 
-0.621020, -0.036620, 0.615280, 0.945440, 0.097620, 0.266810, 0.103950, -0.158040, 0.893240, -0.309390, 
-0.143510, -0.628420, -1.014940, -0.076760, 0.017550, 1.139550, -0.051970, -0.083350, 0.246390, 
-0.520660, -0.996270, -1.514220, -0.619700, -0.504550, -0.973920, 0.023050, -0.931940, 0.699000, -0.760320, 
0.830690, 1.283010, -0.884550, 3.649000, -1.360510, 1.462310, 1.068860, 0.190640, 0.164750, 1.651950, 
-0.452960, 2.121670, 2.612890, 0.413740, -0.194180, -3.218580, -0.315190, -1.932850, 0.091880, -0.106190, 
0.962760, -0.493330, -1.704060, -0.775530, -0.688980, 1.645840, 0.409300, -1.367000, -1.574890, 4.722980, 
0.743160, -0.807820, 0.305030, -0.247650, 1.248210, 1.029670, 0.649770, 3.093170, 0.137010, -1.404820, 
-0.625550, -1.072570, -0.340410, -2.456370, -0.826140, -0.775270, 2.383050, -0.757630, -0.379870, -0.746800, 
-0.308980, 0.166730, -0.774510, -0.311280, -0.372980, 0.760200, 0.656840, 1.473120, 0.703930, -1.607280, 
-3.368990, -0.770850, -1.178330, -2.473140, -1.248290, 1.241860, 0.135130, -0.968680, 0.546030, 1.241520, 
-0.792160, 0.588830, 0.753850, -0.377000, -1.496520, 2.292310, -0.454550, 2.131300, -0.428260, -0.814230, 
2.350150, 1.009060, -0.694540, 0.096690, -0.188440, 1.325940, -3.803500, -0.891200, 0.321580, -1.196600, 
0.684780, -0.100000, 1.030260, 0.597740, 0.567610, 0.117310, 1.427470, 2.642130, -0.115840, 0.497310, 
-0.214440, 0.701440, -0.064490, 0.618970, 0.580220, -2.354840, -8.072200, -3.553880, 7.763540, -5.339400, 
-1.572620, 1.252820, -1.866380, -3.166750, -8.738730, -0.410860, -1.362840, -0.220260, -10.709410, -2.875230, 
-2.152750, 0.099330, -15.311930, 0.356290, 0.255500, -1.523810, -8.296960, 0.132110, -0.356830, -0.026840, 
0.010170, -0.947560, -0.687290, 0.605320, 2.692850, -0.030880, -0.617760, -0.931040, 2.732350, -1.297300, 
-0.468350, -2.524870, 0.406620, 1.373400, 1.781170, -0.466170, 0.057250, -0.114910, 1.012910, -0.315590, 
2.094770, -0.785290, -2.686770, -0.669020, 5.163000, 0.829450, -0.880990, 1.985850, -3.660660, 0.736150, 
-0.260330, 1.182140, -1.214780, 1.850840, -0.352020, 1.598230, 0.375220, 1.838500, -2.700010, 0.127970, 
1.235520, -0.732490, 1.854270, 0.416850, 0.397090, 1.406980, -0.719530, 2.540930, 0.754220, 0.353410, 
-0.774630, 0.758560, 0.767150, -2.653970, -1.264130, 1.978850, -1.164320, 0.488170, -1.675730, 0.741660, 
1.121740, -1.454530, 1.090460, 0.998470, -0.853970, 0.050460, 1.966020, 0.095840, -0.445230, -0.542970, 
0.459350, 0.217330, -0.581390, -2.335160, -1.832870, -0.103650, -1.507160, -0.033960, -0.217830, 1.481060, 
0.044320, -0.352680, 0.247730, 0.883810, -0.884530, -0.647070, -1.004840, -0.657930, -0.026460, 1.324420, 
1.868280, 1.006790, -0.969120, -0.741410, 0.692250, 0.265490, 1.153250, -1.009060, 0.733020, -0.448150, 
0.515320, -1.181810, 0.164560, 0.964610, -1.742150, -0.036640, -0.342590, -0.252310, 0.897380, 1.565740, 
0.838460, -0.573850, 1.837330, -9.332190, 0.566760, -0.941320, -0.764550, 0.555730, -0.978710, 0.013340, 
0.081460, -0.306170, -0.233740, 1.144340, 0.187700, -0.775280, -0.357000, 0.885520, -0.176150, 0.556640, 
-0.327460, -0.283850, -0.618010, -0.696310, -0.220780, 0.388800, 0.047640, -0.949900, 0.259910, 0.260660, 
-0.267540, -0.967480, -0.463660, 0.136790, 0.311840, -0.729410, -1.094840, -0.885420, 0.901400, 0.688260, 
-0.449410, 0.885480, 0.200790, 0.512530, 0.236790, -0.680610, -1.959100, 0.252910, 0.467070, 
-0.402500, 0.511080, -0.240410, -1.714030, -0.133540, -0.789430, -1.024840, -1.410450, 1.187730, -0.356800, 
-0.767680, 0.327070, -0.386450, -0.246880, 0.148400, 0.166310, -0.386310, 0.357910, -0.869780, -1.124170, 
11.713700, 0.542740, 0.510570, -0.296740, 3.023140, -0.149680, -0.961720, 4.073050, 0.376220, -0.223060, 
-0.991520, 0.320080, -0.771350, 0.457500, -2.036860, -0.530680, -0.208110, 2.458660, 0.818090, -1.911840, 
0.878350, -2.508820, -0.841070, 1.713630, 2.191140, 0.624590, 2.517160, -1.418720, 4.413480, 0.227330, 
-0.772010, 0.655080, -0.672180, 2.486520, 0.411510, 2.231080, 0.151420, 1.293630, 0.690940, 0.635660, 
-2.494740, -0.044440, 0.596590, 0.694260, -0.540380, -0.155750, 4.220350, -0.704770, -2.878950, -0.660930, 
-1.153430, 0.919310, -0.818340, 0.716970, 0.404490, 0.067290, 0.637730, 0.020070, 3.201720, 0.598910, 
-1.252940, -0.671910, 2.785090, 0.091560, 0.136900, 0.179490, 0.939490, 2.149040, -0.580340, 10.905290, 
0.384100, -1.542070, 1.820810, 0.897910, -0.718810, 0.539750, 0.936260, -0.481640, -2.053830, 0.438890, 
0.655170, 0.082400, 0.370640, -0.239470, 0.546160, 0.407160, -1.604170, 0.475500, -0.444950, -2.303640, 
-0.197340, 0.776290, 0.341640, -0.468930, -0.270710, 1.085460, -4.161050, 0.160070, 0.727010, 0.851740, 
-1.565220, -0.244010, 0.291230, 0.108430, -0.082350, 0.491510, 0.611000, -1.321100, -9.834190, 0.345330, 
-0.589900, -0.415300, 0.590300, 0.045780, 0.575810, -15.783510, -0.244100, 6.702860, -0.865400, 1.101120, 
-0.592950, 0.619720, -0.148040, -0.719560, -0.724230, -0.774040, -1.555870, -0.201480, 1.668300, 0.773030, 
-0.092130, -0.254700, -0.370950, 0.705920, 0.676880, -0.449510, 0.971450, -0.827610, -1.584800, 0.409270, 
0.659070, 0.752920, 0.339890, -1.604600, -1.177940, 0.010140, -1.193610, 0.300500, 0.104660, -0.211560, 
-1.072820, 0.745660, 1.056780, 1.104010, 0.238110, -0.749740, -0.870520, 0.669720, -0.298770, -0.329290, 
-0.304980, -0.294180, -0.600820, -0.419670, -0.202840, -1.177340, -0.790060, 1.192890, 0.418660, -1.065120, 
0.117060, -1.213680, -2.359490, 0.357070, -0.763260, 0.367760, 0.461490, -0.794410, -0.514320, -1.098770, 
0.967580, -1.849470, -0.417750, -0.651050, 0.201680, -0.729540, 0.726000, -0.655970, -0.423040, 1.792970, 
1.218120, -0.662360, 0.232250, 0.441040, -0.194480, -0.073060, 0.746630, 0.167170, 1.319470, -1.060730, 
0.506770, -0.144170, -0.648290, 0.514650, 1.183940, 0.293360, -0.983930, -0.698420, 0.441750, 0.299930, 
-0.231340, -0.714360, 0.096130, 1.113500, -0.671150, -0.490930, -0.694000, 0.404690, -2.748020, -0.955330, 
-2.120040, -0.082450, -0.249500, 0.103500, -1.389090, -0.702480, -2.559700, 0.953620, -0.451280, -1.100700, 
11.267190, 1.916530, 0.840550, -0.121360, -0.256930, 0.266550, 0.402700, -0.159060, -0.819090, 0.025730, 
2.116280, 0.421930, 0.921140, 0.481700, 0.495950, 0.598380, -0.278010, -0.321030, -0.348440, 0.444530, 
-0.290730, -0.575010, -0.898770, -1.303150, -1.567670, 0.106500, 0.201110, -0.478460, -1.391780, -0.760070, 
-0.760060, -0.355870, -0.109490, 0.065470, 0.028550, -0.836320, -1.114500, -1.154920, 0.443590, 0.790960, 
-1.557920, -1.476160, -1.591670, -0.728610, 0.082610, -1.434850, -1.041070, 0.054040, -0.013070, 
0.876890, 0.055140, 0.659460, -0.333410, -0.229440, 1.084760, 0.628770, 0.399230, 0.644550, 0.474190, 
-0.914040, -1.170490, -1.952830, -2.026970, 0.323690, -0.502500, -0.266780, -0.611510, -0.128850, 0.210590, 
0.505150, -0.511330, 0.291640, -0.479890, 0.458660, 1.350550, 0.805040, 3.707700, 0.089760, 0.757810, 
0.748890, -0.042080, 3.161650, 1.141290, -0.706470, 0.198760, -0.848620, -0.427350, 0.215090, -1.221560, 
2.191010, -1.078550, -0.166940, 0.291780, -0.722080, -0.251680, 0.994640, 1.432740, 2.084120, -1.354460, 
-0.058010, -0.290830, 0.591580, -2.400420, 0.004540, 0.796980, -1.541560, -0.668020, 0.258870, -0.528300, 
0.777730, -1.342290, -0.483820, 1.747760, -0.396100, 0.245430, -0.015930, -1.113070, 0.016000, 0.381540, 
-0.640660, -0.035440, -1.160780, 0.214980, 0.049870, 1.120290, 1.230580, 2.318990, -3.354390, -1.602410, 
-0.045360, 0.606740, -0.403360, -0.421700, -0.545120, -0.212660, 0.296980, 2.495060, 1.401710, -0.603710, 
-1.028990, -1.798360, -0.066880, 2.328220, -0.068960, -0.951010, -0.837980, 1.697260, 0.018110, -2.896370, 
0.134910, 1.106800, 0.061910, 0.386590, -0.605560, 0.683790, 0.932330, -1.913450, 0.460730, 1.717710, 
0.263070, 0.240110, -1.051570, -0.492900, -0.667130, 1.180100, 3.515530, 2.993690, 2.274430, 1.451840, 
1.899620, -2.317380, 1.115230, 1.456560, 2.886820, 0.078960, -0.538380, -0.403500, -1.076020, -0.361200, 
-0.158930, -0.079500, 3.582610, -0.971980, -0.698420, 2.991810, -0.457170, 0.472890, 1.952800, -3.260080, 
1.805560, -0.020020, 0.909810, 0.026450, -0.715170, 0.020840, 2.428060, 2.398240, -0.024810, -1.206480, 
-0.103920, -1.258890, 3.839510, -0.446260, -0.251980, 0.623040, -0.829260, -1.162610, -0.969910, 0.026850, 
-0.898280, -1.940870, 0.285670, 1.549820, -2.294340, -0.850030, 1.158720, 2.275040, -0.168730, -1.092510, 
0.178520, 0.521740, 3.162370, -1.256960, 0.076000, -2.532900, -0.129670, 0.082650, -0.565490, -0.087130, 
-0.245020, 0.526600, 0.797530, 0.148540, -0.485330, 1.594730, 1.731610, -0.661190, -0.262640, 0.521620, 
-0.646710, 0.616550, 0.241330, -0.081080, 0.846240, 0.305350, 0.398780, 0.044190, -0.551890, 0.926430, 
0.216310, 0.043530, -1.062850, -0.516410, 0.040440, 0.006480, -0.645000, 1.121970, 1.075720, 0.280840, 
-2.833730, 1.760220, 0.527250, -0.258160, 0.718800, 0.360650, 1.915730, -1.066150, -0.258430, -0.873300, 
-0.015480, -1.662440, -0.207040, 0.240130, 1.388670, 0.055970, -0.545070, -1.065480, -2.034430, -2.125340, 
-1.045520, -2.035150, 0.593320, -1.598990, 1.316640, 0.514540, 2.475030, 0.757290, -1.055910, -0.970260, 
1.658510, -2.147510, -2.912540, 0.540750, -0.846230, -0.980550, 1.074730, -0.781900, 0.427550, 1.157060, 
0.102090, -0.513030, -2.575580, -0.247270, 0.090500, 0.755330, -1.145860, 1.599660, 0.716200, -0.141080, 
1.791700, -0.782600, -3.289090, -1.351800, 0.122890, 0.189270, -0.525500, -0.568000, -0.960930, 0.655420, 
-0.363650, 0.450210, -0.006480, -0.025170, -0.523100, -0.012750, -0.275130, -0.704040, 0.604470, -0.444900, 
0.091750, -1.057350, -0.856490, -0.629420, -0.218570, -0.518060, 0.296140, 0.756560, 0.843090, -0.443530, 
0.623640, 0.201900, -0.238740, 0.102090, -0.927050, 0.526750, -0.295320, -0.304160, -0.183060, 
0.250630, -0.578470, -1.390740, 1.078840, -1.180720, -0.405960, -0.294520, 0.255980, 1.064010, -0.408960, 
0.055900, -0.507960, -0.238680, 1.056850, -0.247200, -0.064690, 0.942410, -1.082420, -0.671880, -0.142130, 
-0.039410, 0.158060, 0.319690, 0.891270, -0.861210, -0.640190, 0.536080, 1.402630, -0.818850, -0.029070, 
0.542080, -0.840450, -1.186130, -0.386600, -0.398610, -0.432380, 0.118080, 0.443050, 0.166550, -0.442050, 
-1.551480, -0.976520, 0.077470, 0.416010, 2.113160, -0.581060, -0.102740, -0.596020, -0.579300, 0.560070, 
0.552640, -0.087960, -2.118450, 0.493260, -0.808800, -0.045220, -1.780050, -0.143750, 0.216310, 1.374920, 
0.940290, -0.563400, -1.031470, -0.357530, -1.585010, 2.127000, 0.940440, 0.740870, -0.951430, -0.443000, 
-0.764030, 0.186380, 1.429260, -0.333890, 0.383180, -0.566620, 1.154790, -0.728000, 1.135090, -1.144790, 
0.430350, 0.318810, -0.092020, 1.115580, 0.488650, 0.854050, 0.601740, -1.499890, -0.228230, -0.673930, 
-0.726090, -1.679770, 0.808750, -0.114390, 1.192170, 0.121090, 0.925460, -0.020570, -1.000250, -1.042250, 
0.164700, -1.775300, 0.067400, -1.710980, -0.753880, 1.163060, -0.405140, -1.111160, 0.378180, 0.695280, 
0.013400, 0.775320, 0.598190, 1.228080, -0.381780, -2.872960, -2.028560, -2.444990, -0.188390, -1.689460, 
-0.732810, 4.342090, -0.584710, -4.230560, -3.087600, -0.436920, 0.513580, 0.302750, -1.004670, -0.200910, 
5.245930, 0.895910, -3.177970, 1.180950, 0.662690, -0.102400, 0.533830, 2.634970, 0.783060, 0.343530, 
0.406990, 0.834400, -0.482650, -0.581500, 0.298080, 0.569130, -0.505850, 1.496540, -0.146550, -0.266130, 
0.922750, -0.139630, 0.291310, 0.504130, -0.344060, -1.001630, -1.096780, 0.671430, -0.059410, 1.050800, 
0.098550, 0.066310, -1.843860, 0.626650, 0.184180, 0.066410, -1.292980, -0.087830, -0.078130, -0.026230, 
1.392830, -0.751750, 0.810660, -1.438570, -0.633820, 0.961000, 0.999610, 1.299660, -0.898630, 0.224490, 
0.497470, -0.870840, 6.326310, -1.100210, -0.178370, -0.607870, -0.138110, 0.152250, -0.579870, 0.192980, 
-0.880370, -0.056760, 0.519350, -0.651020, 0.451160, 0.910570, 0.504170, -0.477060, 0.094770, 0.471380, 
1.129840, -3.594070, 0.455180, 0.617950, -0.390130, 0.450550, 0.332500, 1.098120, -0.792680, 1.116940, 
0.495960, -1.381800, 0.359450, 0.869880, 0.066520, 0.998190, -0.891860, -0.065820, -0.161180, 0.682370, 
-1.484930, -0.179750, 1.176100, 0.111190, -1.118330, -0.024500, -0.363120, 0.509540, -1.010070, 0.058860, 
0.141870, -1.313670, 1.010390, 1.916330, 0.688910, -0.389880, 0.131160, 0.302300, 1.776140, -0.678060, 
0.842260, 1.335690, -0.652330, 1.508510, 0.631110, 1.039230, 0.385760, 1.564920, 0.777640, -0.534480, 
0.034170, -0.343970, -1.138980, 0.842590, 0.212820, 0.820960, 0.769080, -0.506940, 0.369940, 0.192940, 
-0.330660, -0.646530, 2.636460, 2.614550, -0.627250, 0.551950, 0.025530, 1.106900, -0.145840, -0.498900, 
0.392660, -0.341340, 0.934230, 0.978330, -0.829870, -0.078550, -0.670550, 0.640050, 0.561180, 0.229960, 
0.911780, -0.023410, -0.723080, 0.639960, -0.714470, -0.164150, 0.849570, 1.000800, 1.021700, 0.771810, 
-0.685670, -0.004050, 0.790990, 0.584790, -0.892120, -0.639750, 0.745010, -0.329420, 0.732120, 
0.240940, 1.025380, -0.995480, 0.620190, 1.173550, -0.156610, -0.255930, -1.694120, 0.739940, -3.268470, 
-0.887200, -0.079130, -0.143340, -0.334060, -1.466320, 1.281420, -0.081530, 1.170780, 0.154360, -0.653540, 
0.201650, -0.788980, -0.575940, -1.205260, -1.315540, -1.025620, 2.301440, -0.502060, -1.998190, 1.177090, 
-0.354870, -0.282440, -2.038870, -0.135410, 1.035030, -0.158830, 0.279330, 1.010250, -0.326280, 0.227010, 
-0.496050, 0.059340, 0.987020, 2.374360, 1.202500, 0.265350, -0.798700, 0.364640, -1.884180, -0.147060, 
-0.911010, -0.751760, 0.555000, -0.552080, -0.579440, -2.331340, -0.568590, -0.031970, 0.820770, 0.331400, 
-0.452270, 1.414670, 0.489080, -2.379360, 0.348140, -0.138990, 1.623880, 0.400890, 0.078910, 0.398400, 
-0.649660, -0.779480, -0.959220, -0.360240, -0.226530, 0.734410, -2.206730, 0.805820, -1.735130, 3.246530, 
-0.271200, 0.175780, -0.013850, -0.914460, 1.223690, -0.097270, 0.203670, -0.516130, 0.253940, 0.241130, 
-0.564760, -0.145290, 0.179420, -0.233850, -1.286890, -3.162480, -0.201750, -3.295490, -0.169460, 0.406260, 
1.015570, 1.076080, 1.469970, 0.464570, 0.965910, 0.087850, 2.022240, -1.282850, 2.306550, -0.185130, 
-1.858870, -0.012800, 0.246690, 1.033270, -0.771280, -3.374370, -5.621670, -2.827820, 7.441390, -3.226700, 
-1.957610, 11.735230, 1.527200, -6.819460, -3.576600, -0.157230, 1.284080, 1.971060, -3.426140, -4.479710, 
-1.245300, -0.931830, -2.710850, -1.155260, -3.294310, -2.983870, -3.092130, 0.531440, -2.848270, -0.208050, 
-3.272490, -1.055610, -0.106020, -1.560290, 0.347040, -0.378550, -1.693330, -3.103630, 0.281660, 0.577960, 
-0.063930, -1.103630, -0.466600, 0.249250, -0.685560, -1.145320, -0.157670, -0.103180, 0.373790, 1.486310, 
0.221860, -0.100500, -0.965200, -0.769350, -0.328780, 0.551620, 0.888320, -1.163540, -1.185630, 0.221940, 
-3.513170, 0.124030, 1.412820, 0.487280, 0.753530, -0.266820, 0.510440, -0.783530, 1.117690, 0.596170, 
-1.340450, 0.375370, -0.551620, 5.438480, 0.558620, -1.041650, -0.153500, 0.511430, 0.311980, 0.474920, 
1.383840, 0.194890, 2.362570, -2.173580, 0.314980, 0.580340, 1.724340, -0.350380, 1.524140, -0.435340, 
0.045960, -2.214110, -0.225610, 1.349870, -0.392730, 0.869270, 0.775910, -0.669640, -0.834590, 2.111660, 
1.090670, -0.287850, -0.538850, 0.786400, 1.962770, 0.886350, -2.554820, 0.401780, 0.653310, -0.394630, 
0.026150, 0.021050, 0.800850, -0.300520, -3.399000, 0.103490, 1.650610, 0.538180, 0.942610, 0.685540, 
1.607370, -0.354430, -0.678780, 0.768940, 0.385850, 0.298590, -0.085040, 1.097530, 1.510870, 0.381910, 
0.620700, 0.600940, -0.463580, -0.109630, -1.008290, -1.137120, -0.487200, 0.464870, 0.970520, 0.563840, 
-0.013830, -1.369450, 1.329260, 0.792930, 0.132070, -1.466310, -0.615280, 1.407120, -1.342500, -0.639520, 
-0.992520, -0.745390, 5.526010, 1.200070, -0.504230, -1.150170, 0.746350, -0.040720, -0.399270, 0.958310, 
-0.615560, -0.351890, 0.882100, -0.278500, -0.457350, 0.607190, -0.614550, -0.412550, 0.472110, -0.914710, 
-0.116950, -0.390030, -0.094690, 0.231860, -0.386410, -0.733250, 0.000590, -0.564460, -1.001240, 0.648980, 
0.770440, 0.479820, -0.684690, 0.580550, 0.271710, -0.467100, -0.416400, 0.052050, -0.578740, 
2.932480, -0.365560, 0.431970, 0.648930, -0.482830, -0.832860, -0.364480, 1.641110, 0.367150, 0.481530, 
-0.004420, -1.862530, -0.246910, 1.428460, 1.361290, -0.889910, 0.526150, -3.009960, -0.296090, -0.345120, 
0.768510, -0.567270, 0.497640, 2.630460, -0.507640, 1.432350, 0.394260, 0.013910, 1.690630, 0.962640, 
-0.902570, 0.863950, -0.596370, -2.252560, 0.120950, 1.301870, 1.743640, -0.892480, 0.386710, 1.363450, 
0.573920, 0.737920, -1.312840, -0.169350, -2.863160, 0.755100, -0.457560, 1.140900, 0.899350, 0.043510, 
0.163740, 0.357020, 0.110510, 0.292210, -0.178130, -0.526260, -2.394230, -0.498820, 2.300630, 0.721900, 
0.536590, -0.296870, -2.015930, -0.025650, -1.410650, -0.747770, 0.319960, 0.090750, 0.664320, 0.705330, 
0.812530, -0.277300, 0.770830, 0.708280, 0.091070, -0.370670, -0.218220, 1.091610, 2.001490, 0.631920, 
-0.242100, 0.966430, -0.195600, -1.838820, -0.302800, 0.377410, 1.141890, 0.157510, 0.886610, -0.447980, 
0.025010, 0.350840, 0.445690, 0.013840, -0.305200, -2.867170, 0.166330, -1.020870, -0.499210, -0.250210, 
0.549610, -0.524970, 0.228220, -0.020050, 1.705130, 0.537360, 0.378010, 0.206190, -0.644630, 0.113450, 
-1.002410, -0.906670, 0.479510, -0.249810, 1.108260, -1.315890, -0.041150, -1.238960, 0.593310, -0.146930, 
-1.231930, 0.533860, -2.880680, -2.340360, -3.532130, 0.737450, -0.351070, 0.043280, -1.173090, -0.166190, 
0.249340, -0.116210, -3.893980, 0.103250, 0.345050, -0.341780, 1.279940, 0.583400, -1.080960, 0.522370, 
0.590090, 0.071970, 0.837150, 4.641050, -0.084150, 0.578540, -0.319450, 0.113240, 0.592540, 0.859110, 
-1.348370, -0.596770, -0.202730, -0.569130, 0.915210, 1.080140, 0.738550, 0.088730, 0.843350, -2.008790, 
1.907930, 0.735930, -0.842460, 1.915610, 2.149560, -0.720690, 1.517620, 1.451400, -0.628040, -0.041930, 
3.535620, -0.654730, 0.149630, 0.246820, -1.014870, -1.532040, 0.743690, 0.926380, 0.028700, 0.267020, 
2.211550, -0.986630, -1.309510, 3.533640, 1.507330, -2.972140, 1.277260, 0.477470, -0.893640, -0.189690, 
0.623500, 0.069980, -0.556710, -0.144400, -0.814410, -0.340910, -0.209460, -1.626550, 0.170690, 0.331380, 
0.542840, -2.280230, 1.397590, 2.129870, 0.591280, 0.426390, -1.162140, 3.657780, 0.045510, 0.525310, 
-0.013040, 0.141270, 0.510540, 0.594690, 0.024420, -0.335370, 0.075180, -0.455660, 0.204500, -0.842020, 
1.120200, 0.425750, -0.560510, 0.406010, 0.137290, 2.097940, 0.383330, -0.502930, -1.106610, 0.394240, 
0.617240, -0.456160, 0.598010, -0.645790, 0.020210, 0.270180, 0.896580, 1.383680, 0.880390, -0.725870, 
-0.251440, -1.194480, 0.331300, 0.443600, 0.213180, -1.119260, 0.643060, -0.202930, 0.151730, 0.681010, 
0.840270, 3.033200, 4.865020, -0.060820, -0.029620, -1.193610, -0.643610, 0.671200, 0.415600, 0.840780, 
-0.136900, 0.312100, 1.137810, 0.586560, 0.550410, 0.361060, 0.332070, 0.195140, -0.140460, 0.835280, 
0.469730, -0.648460, -0.904550, 0.744920, 0.140160, -0.383820, 0.629180, 0.045290, 1.106380, -0.544400, 
0.408920, -0.194380, 0.900200, -0.235140, 0.389870, 0.114080, 0.521650, 0.665530, 0.423720, -0.847370, 
0.426410, 0.390940, -0.547120, 0.734820, -0.128100, -0.014540, 0.785300, 0.297980, 0.862220, 
0.403290, -1.544160, 0.433300, -1.437260, 1.149400, -0.268920, 0.857970, -1.155360, -0.329590, 0.836080, 
1.173590, 0.230410, -1.081350, 0.282770, 0.795630, -0.402410, 0.589100, 0.811300, 0.346090, -1.252020, 
-1.590970, -1.296780, -0.500400, -0.066190, 0.084430, 1.085390, 0.917910, 0.933650, -0.174630, -0.157250, 
1.165240, -2.223700, -0.805670, -0.469850, -0.864940, 0.131540, 0.383030, -1.864420, -0.098000, -0.291420, 
-0.664010, -0.285960, -0.475850, 0.061030, 0.216570, 0.821460, 1.460140, 0.759530, -1.169350, 0.198580, 
1.714310, -1.869990, 0.556250, 1.737090, 0.178390, 0.246740, 0.325530, -0.829230, 0.161600, 0.301200, 
0.259060, -0.776820, -0.327200, -0.839980, -1.736650, 1.238650, -0.983220, -0.240090, -0.411200, 0.788750, 
-3.267250, 0.742480, 0.447720, 0.728080, 0.240610, 1.065490, 1.896060, -1.293550, -0.389830, -1.030330, 
0.140470, -0.441330, -1.430620, -0.341450, -0.693990, 0.495500, -1.080950, -0.461830, 0.111110, 0.332610, 
0.471490, -0.649600, -1.166780, -0.368390, -0.377480, 1.063950, -0.170850, 0.855960, 0.545160, -1.277770, 
-0.301440, 0.952910, -0.052760, -2.127890, 0.237800, -0.775470, -1.163280, -0.655210, 0.076120, -0.479690, 
0.240990, -0.561820, 0.523700, -0.252940, -1.335570, 4.360670, 5.050350, -0.889460, -3.007940, 18.830120, 
2.957630, -3.409080, 7.859680, 4.538380, 5.737240, -1.876300, -0.834080, 0.980310, 13.851950, -0.523780, 
1.755280, 0.455960, 20.191299, 0.490890, 0.500590, 1.524400, 3.977990, -1.452490, 1.613910, -0.742700, 
0.242590, -1.188390, -0.413530, 1.292800, -0.354410, -0.623880, 2.086510, 2.325700, 1.487510, 0.986950, 
-0.867950, 0.381560, 1.183990, 0.056700, 0.673260, 0.399260, 2.002230, 1.877250, -0.840660, -0.710540, 
-0.733200, -0.230440, -1.927120, 0.611430, 0.263050, 0.650630, -0.830980, 0.543090, 3.107000, -0.029920, 
1.653850, 0.037450, -0.616310, -0.308720, -2.047280, 0.914600, -1.331350, -0.296520, -0.895920, 0.214470, 
-0.804680, 0.373220, 1.433560, -1.180010, 1.272620, 3.149230, 0.325250, -1.151080, 1.240600, 0.217750, 
0.807360, 0.726510, 0.257440, 1.865960, 0.519350, -0.475320, 0.557930, -0.647660, -1.899180, -0.751430, 
0.144820, -1.120640, -1.363770, -0.396220, -0.589580, -0.147120, 0.344010, -0.672850, 0.500470, 0.282340, 
-1.848030, 1.738300, 0.278330, -1.395180, 0.728500, -0.216960, 0.356640, -0.352320, 0.171190, 0.635490, 
-0.795730, 0.209350, -0.112210, -0.639080, 1.119520, -1.846380, -1.747900, -0.618730, 0.185840, -0.605150, 
0.267620, 0.704060, -0.525210, -2.383470, 0.589690, -1.114070, 0.621310, 2.618810, -1.311170, 1.229520, 
0.897980, -0.789490, -0.461920, 1.025910, 1.623360, 0.333110, 0.482840, -2.261880, 0.513450, -0.644270, 
0.991040, -2.128690, 0.138950, -0.877000, 1.860790, 0.126610, 0.527380, -0.448290, -0.634220, -0.389560, 
0.244420, 0.108590, 0.901250, -1.299510, -0.487860, -1.418780, -0.567500, 0.536480, 0.663610, 0.439060, 
-0.880970, -0.622270, 0.165580, -0.698190, -0.831690, -0.093040, -0.056480, 0.818080, 0.713140, -0.700850, 
-0.301090, 0.597870, 0.594750, -0.038660, 0.515940, 1.023960, -0.530120, -0.558750, 0.656780, 0.681440, 
-0.661550, 0.396050, -0.536070, 0.693470, -0.251910, -0.436670, 0.227220, 0.441440, -0.591110, 
-0.329170, 0.351540, -0.690790, -0.425880, -0.832010, -0.310830, 0.591530, 0.286080, 1.168190, -0.701350, 
-0.659390, 0.788630, -0.199480, -0.453630, 2.101860, 1.261570, 0.601280, -0.675880, 0.938650, -0.223220, 
0.599560, -0.006250, 0.077950, 0.088960, 1.706610, -1.164470, -0.375620, -1.665480, -0.430800, 0.289870, 
-0.527600, -1.001730, -1.155190, -0.530770, 1.670810, 0.603360, 1.012070, -0.486650, -0.527570, 0.230490, 
-1.209750, -0.556200, 1.072900, 0.478760, -0.892760, -0.362940, 1.110440, -0.186120, -3.039080, -0.642290, 
0.780650, -1.249040, 0.686070, 0.465150, -1.631240, -0.639850, 1.781220, -0.423830, -0.520340, 1.027160, 
0.989820, 0.285860, 2.135950, -1.234320, -0.757160, -0.573640, 0.813330, 0.060260, 0.392210, -0.377300, 
-0.791200, -0.607220, 0.877060, -2.597550, -0.681870, -1.368710, -1.251840, -1.454380, -1.127340, 1.245490, 
0.919830, -0.030110, 0.944690, 0.373130, 0.850690, 0.471370, -1.194070, 0.327060, -0.170310, -0.019770, 
-0.033790, -0.431900, -0.244710, -3.062010, -0.328150, -1.083850, -0.973110, -0.682700, -0.993030, 0.899570, 
-1.072170, 1.083610, -0.577030, 0.420800, -0.134700, 1.287530, -0.360080, -0.086490, -0.107120, -0.636980, 
0.367850, 0.026920, 0.628870, 1.094330, -0.262100, -2.677950, -1.447170, -2.087340, 0.833230, -1.863820, 
-0.062330, 2.742040, -1.140210, -3.205990, -1.985370, 1.228850, 0.909810, 1.844650, 0.295380, 0.509720, 
0.448130, 0.525750, -3.451890, 1.172590, 1.045650, -3.470820, -1.579660, 0.033110, -0.213930, 0.483510, 
-1.691160, 0.727290, -1.321570, 1.005480, 0.530870, 0.197140, 0.104660, -0.503310, -1.896760, 1.344330, 
0.815940, -0.780860, -0.214440, -0.310580, 0.794510, 0.426630, -0.459690, 0.115790, -0.315620, -0.949530, 
0.110270, -0.230190, -0.526190, 0.876650, -2.240200, -0.935760, 0.849920, -1.165160, -0.893030, 1.666900, 
-0.039220, -0.011970, -0.136330, 0.180400, -0.014820, -0.367090, 0.479890, 0.381510, -1.315250, 0.406260, 
1.456480, 0.603260, -0.774440, 0.296200, -0.155620, -1.405960, -1.407140, 1.498310, -0.268450, -0.201500, 
1.069710, -0.199870, 0.051700, -1.693610, 1.479110, 0.446050, -0.155780, 2.484840, 0.336470, 1.879360, 
-0.289140, -0.686670, 3.058030, 0.049900, -0.224190, -0.580570, 1.598800, 0.869340, -0.344400, -2.102740, 
-0.423190, 1.901110, -0.576890, -0.237760, 0.640140, -0.746600, -1.064290, -0.480330, 0.150440, -0.144860, 
1.688120, 1.638790, 0.410960, -0.142340, -0.807120, 1.628330, 2.032230, 0.595660, 0.842580, -1.563820, 
0.344610, 0.226190, -0.672480, -0.535770, 1.069870, -0.186360, -0.183500, -1.762570, -0.775140, 0.455480, 
1.111290, -1.163550, 0.427510, 0.177030, -0.308820, 0.854890, 0.357580, -0.189410, 3.232340, 0.196360, 
0.833180, -0.164180, -0.281600, 0.809410, -0.202830, -0.914290, -0.298950, -0.086050, -0.561130, 0.737650, 
-0.438300, 0.475650, 1.944280, 3.169780, 0.161280, -1.056380, -0.732710, -1.184440, 0.312560, 1.196590, 
-0.406610, -0.271780, 0.418480, -0.257070, 0.254990, -0.261340, -0.578620, 0.885900, -0.221380, 0.264290, 
1.029930, 0.923850, 0.283710, 0.542240, -0.448600, -0.735240, 0.726590, 0.289970, -0.580220, -0.049720, 
-0.396920, -0.482210, 0.517020, 0.466660, 0.050790, -0.391330, 0.194080, -0.238980, -0.268100, 
0.152070, 0.924240, -0.935920, -0.078450, 1.097930, 0.427110, 0.165790, 1.028290, 0.272500, -0.586740, 
0.134130, 0.229510, -0.580110, 0.247430, 0.086060, -0.048090, -0.307350, 0.080420, -0.665360, 0.130010, 
-1.296630, 1.507700, 0.120050, -0.913990, -2.298760, -1.348980, 0.764190, -2.904970, -0.734180, 1.089890, 
-1.879980, -2.254100, -1.397580, 0.992640, 0.557880, -0.227420, 1.954250, -0.703740, 0.322330, 0.867220, 
-0.544790, 1.339930, 0.961950, 0.377350, 0.192410, 0.517330, -2.514380, -1.564090, -2.599990, 0.332240, 
-1.370770, -0.717620, 1.012970, -0.021520, -0.945950, -2.359050, 1.402340, -1.134270, -1.179140, 1.172060, 
1.539120, 1.830690, 0.657100, -2.407190, 0.814450, 1.065910, -0.449190, 2.874790, 0.607530, -0.239870, 
0.909120, -0.002550, 0.760510, -0.482910, 1.564930, 0.869270, 0.160010, 0.791350, -0.407210, 3.915430, 
0.557360, -0.917520, -0.002060, 0.649830, -0.837720, 1.482950, 0.324090, 0.317340, 0.541880, -0.079870, 
-3.203490, 1.767060, 0.005950, -1.148610, 0.020920, 1.130410, -0.646470, 0.256820, 1.348410, 0.692790, 
-1.462970, -0.251530, -0.261990, -0.028900, -0.724970, -0.813770, -0.333110, -0.853280, 1.271890, 0.208400, 
-0.066260, -0.484590, 0.761770, -1.549480, 0.176360, -1.067040, -3.424340, -2.662180, 1.934980, -2.334670, 
-0.395190, 3.190710, 0.094590, -2.269900, -2.222130, 1.048710, 0.824780, 2.230110, -2.063310, -2.216920, 
1.889450, 1.469860, -1.479030, 0.024660, 0.889510, 3.700250, 5.631390, -0.342800, -2.678370, -0.516030, 
-2.455300, -4.264640, -0.553200, 1.397110, 1.231820, -0.246130, -2.611520, -3.906550, 0.069830, -0.339470, 
0.934630, -2.033950, 0.282760, 0.110620, 0.125690, -2.187720, 0.571090, 0.375650, -0.814140, 1.664610, 
1.123820, 0.906570, 0.452550, 0.317680, 0.739480, 0.816270, 1.086880, 0.537020, 0.446470, 1.706140, 
-2.110720, -0.693340, -0.320350, 0.575910, 0.476280, 4.485440, 0.073430, -0.067090, 0.725870, -0.893050, 
-0.177290, 1.028620, 1.443090, 1.720370, -0.389310, -0.881940, -1.300300, -0.481750, 0.589410, 0.103270, 
0.167280, 1.226610, 1.000540, -1.525150, -1.180700, 0.142440, 0.009260, 1.078900, -0.324610, -0.118440, 
-1.475190, 0.119940, 1.611680, -0.133590, 0.430570, 0.988980, 0.672330, -0.311120, -0.348990, -0.888790, 
2.388540, -0.150920, -2.627540, 0.039880, 0.157300, -2.056380, -3.183190, 0.272630, 1.526150, -0.665030, 
0.172740, -1.082670, 1.259140, -0.436960, -2.289260, -0.625640, 3.555890, -0.634630, -0.711100, 0.075780, 
1.907880, 0.046110, 0.580200, 3.125690, 2.310390, 1.139880, 0.251990, 0.523980, 0.199760, -0.479320, 
-2.353010, 0.773850, 0.197430, 2.224760, 0.489040, -0.215230, -0.549990, -2.413920, 0.557170, 0.012700, 
-0.218510, -0.262960, 0.415210, -0.796330, 0.943250, -1.688760, -0.045990, -0.924220, -0.235160, 0.803790, 
-0.664160, 0.533050, 0.135840, 1.766450, 0.828420, 0.217680, 1.198890, -0.060780, 0.314280, -0.265030, 
0.473260, -0.222770, -0.029720, 0.489600, -0.426180, -0.340740, -0.157620, 0.605920, 3.186420, 0.789880, 
0.634680, 0.673950, 0.345180, -0.127970, -0.395530, -0.562700, 0.610490, 0.797970, 0.402600, -0.905550, 
0.528520, 0.534430, 0.470810, 0.355590, -0.817510, 0.806410, 0.038980, 0.166230, -0.341520, 
-1.579260, -0.614560, -0.067980, 0.591290, -0.017850, 0.980200, 0.531710, 1.202060, -0.412080, 0.967440, 
-0.495190, 0.215610, -0.242170, -0.497350, 0.593660, -0.020710, -0.514100, -0.756330, 0.101160, -1.077380, 
0.659150, 0.374670, 4.042010, -0.335050, -0.549020, 1.215120, 1.162500, -0.641300, -1.664820, 1.240800, 
0.896010, 0.823470, -1.376680, 0.078490, -0.680220, -0.480770, -1.411990, 0.448470, -0.541090, 0.959180, 
-0.299000, -1.531090, -0.589550, -0.363870, -0.567790, 2.171440, 1.828020, -1.297670, 0.005370, 1.542380, 
0.123760, -1.342330, -0.692030, -0.355590, 1.691940, 0.636900, 0.796530, 0.247440, 1.279170, -0.860920, 
1.017790, 0.572070, 0.366430, 0.113410, 0.274210, 0.934950, -0.770920, 0.082810, 0.271800, -1.218210, 
-2.738360, -0.078110, -0.283200, 0.615130, -0.826410, 0.585360, -2.180150, 0.174210, 0.479790, 0.293860, 
0.281310, 0.429630, -1.611350, -0.515220, -1.644690, -0.774640, 0.803080, 1.141710, 0.167760, -0.946600, 
-0.276550, -0.588050, 0.624980, 1.466280, 0.967410, 0.970760, -0.769660, 0.917210, 0.272570, -0.887770, 
0.041590, 0.188120, 0.685170, 0.577710, -0.453710, 1.364610, -0.267540, 0.216990, -0.580570, 1.051870, 
-0.355070, 0.183030, -0.543540, -0.269770, 2.184950, 1.090390, 0.288110, 0.316600, -1.086350, -0.257820, 
0.311540, -0.429810, -1.609480, -0.903890, 0.409990, -0.370070, 0.473830, -2.373340, 1.131180, -0.106580, 
-0.777360, 0.558100, 1.199950, -1.343390, -0.227100, 8.568990, -0.519190, -8.054280, -0.227790, -3.480380, 
-0.047360, -1.051490, -0.099230, 0.373770, -0.797670, -0.344630, -1.446810, -0.051070, 0.555990, 0.396780, 
-0.134760, -0.099020, 0.929500, 1.578700, 0.526910, -0.577920, -0.403370, -0.359720, 0.695370, -0.172840, 
-1.886390, 0.357510, 2.486770, 0.333550, -1.025520, 1.503560, -0.836510, 0.639160, 0.399510, 0.425290, 
0.913100, -0.419920, 0.127930, -0.315520, 1.220930, 0.478890, -0.212440, -1.018170, 1.720810, 0.178210, 
-0.304500, -1.371350, 0.336490, -2.438090, 0.729980, 0.632350, -0.663280, -1.153020, -1.594660, -0.767190, 
0.068660, -0.453200, -0.281690, -2.659200, -0.093820, 0.211700, 1.068540, -0.425510, -0.574490, 0.324670, 
0.102110, 0.315790, -1.545740, 0.203100, -0.226680, -0.275750, 0.161250, -0.449250, -0.354840, 0.486650, 
0.582450, -0.887350, -2.641510, -0.214000, 0.477210, 0.268730, -0.197650, -0.250430, 0.293260, -0.479950, 
-0.419230, 0.175790, -0.420520, -0.366660, -1.068570, 0.871870, -1.889010, -1.457620, 1.371720, -0.255180, 
0.204860, 1.067100, -0.701230, -0.002560, -0.152970, -0.219490, -0.797740, 1.568940, -0.096930, 0.767540, 
0.982480, -0.320160, 0.427480, -1.105190, -0.432220, -0.801240, 0.204830, 0.702050, 0.149850, -0.420180, 
-0.321430, -0.473910, -1.838870, -5.472970, -0.529370, -0.277700, 0.173770, 0.336320, 2.540990, -0.206320, 
-4.284530, -1.614880, -1.187820, -2.122430, 0.450200, -1.785800, -0.268300, -0.584030, 0.450470, -2.384080, 
-0.334780, -0.610310, -1.083240, -2.089170, -1.876260, -1.669260, -0.408070, -0.698720, -1.555460, -1.765240, 
-1.545500, -1.327030, -1.119830, -0.903590, -0.545440, 0.201940, -1.052680, -0.094720, -3.359810, 0.373680, 
-0.497340, -1.336350, -0.756330, -1.963970, -0.811480, -2.101760, 0.236990, -1.552850, -1.153140, 
-0.472480, 1.701640, -1.429970, 0.119970, 0.680670, 1.035090, -0.444370, 0.553920, 0.060800, -0.749590, 
-2.232260, -0.708000, 0.591610, 0.810520, -1.590850, -1.752430, 0.191350, 0.397490, 0.085250, -0.582370, 
4.664810, -0.575240, -0.772160, 2.191860, 0.185810, -1.182430, -0.929060, -0.993270, -0.183120, -0.093810, 
0.354000, 1.530440, -1.418820, -0.146940, 0.009730, -0.350320, 0.492400, -0.733050, -3.477330, 0.188210, 
0.378950, -0.400880, 1.097670, 0.301660, -0.778610, 1.233160, 0.937320, -0.050340, 0.194520, -0.469980, 
-0.306570, -0.966990, -0.898790, 1.363290, 1.642150, -0.120450, 0.106110, -0.020080, -1.128760, -0.875500, 
-0.483250, 0.923020, 0.326870, -0.731450, 0.054800, -0.881840, 1.315800, -0.313570, 0.460370, -0.484380, 
-0.833630, 1.130480, 0.563380, 0.977850, -1.112950, -0.903130, -0.101980, 0.628660, -0.487550, 2.200320, 
0.185100, 0.607510, -1.929460, 0.415350, 0.222960, 0.894960, -0.393670, -1.041420, -0.358960, 1.173070, 
-0.793420, -0.111280, -0.023740, -2.629660, -0.294250, -0.200440, -1.811440, -0.874820, 0.753230, 0.384660, 
0.420880, 1.051200, -0.134150, -0.577270, -2.040750, 1.129270, 0.081020, -1.693410, -0.485670, -0.244840, 
0.289520, -0.372700, 0.433720, -0.427050, 0.294880, -1.584060, -1.557950, 0.116280, 0.046360, -0.936260, 
0.596960, 0.549900, 0.449410, -2.632040, 0.532320, -0.581200, -0.754260, -1.079870, -2.124920, -0.308990, 
-0.790730, 1.262050, -1.152740, -0.404040, -0.115980, -4.752960, -1.602960, -0.197430, -0.063990, -0.857500, 
-0.509020, -0.505030, -0.028260, 0.907850, 0.100580, 1.098020, 0.122910, -0.535040, 1.673660, -1.183310, 
-1.031370, -2.543030, -0.600580, 0.060170, -0.095500, -0.908100, 0.143780, 0.290470, 3.376240, 0.074840, 
0.748600, -0.125090, -3.980950, -0.882530, -0.813290, -0.561450, -2.077090, 0.131530, -0.269070, -0.161220, 
-0.199540, 0.503840, 0.059480, -0.038210, -0.112380, -0.391950, 0.289480, 1.445170, 1.864180, -0.605800, 
-0.231100, 0.532230, 0.951810, -0.431320, -2.105310, -0.678030, -1.379470, 1.604410, -1.098750, -1.334620, 
1.834380, -1.209270, 0.182820, 0.372510, 1.512390, -0.382760, -0.435700, -0.984950, 0.170520, 2.624540, 
1.116440, 0.319030, 1.965800, 0.391730, 7.489270, -0.203100, 1.246500, -0.221190, 0.057960, -1.003530, 
-1.011630, -0.663610, -3.731100, 0.422090, -2.487580, -0.746400, 0.208960, 0.203790, -0.711530, 0.698580, 
0.648800, 0.488850, 0.295830, -0.208950, -1.720040, 1.434670, -0.825960, 0.480570, 1.027420, -1.925410, 
1.256680, -0.569590, -0.977780, 0.939990, -0.115420, -1.328760, -0.419180, 0.516040, -0.404540, -0.338760, 
-1.023450, -1.567070, -0.419720, 1.371900, 0.259770, -0.330030, -0.244440, -0.237630, -0.459220, -1.111840, 
-0.689560, -1.614250, -0.533380, -8.984660, -0.113350, -0.106320, -1.225380, -0.108070, 0.226120, 0.313640, 
1.805940, 4.352250, 0.912610, 2.097700, -4.405030, 0.029040, -2.275650, -0.805010, 1.273450, 0.162910, 
-0.911040, -0.601010, -0.861040, -1.513140, -0.765750, -1.348310, -1.133180, -0.954310, -0.501320, -0.439310, 
-0.530420, 0.060290, -1.409410, 0.021590, -0.728310, -0.897980, -0.694090, -0.144470, -0.480750, 0.211940, 
-1.407530, -1.164990, -0.963790, -1.147900, -1.235820, 0.315200, 0.700320, -1.115090, -0.945710, 
0.770360, 1.646130, 1.627720, 0.554820, -0.810340, 2.031440, 0.420890, 1.095560, 1.183320, 0.921510, 
2.597610, -0.130900, -0.350120, -0.131630, 0.885350, 1.387300, -1.567050, 0.798630, 0.439590, 0.823140, 
0.499700, -0.606510, 1.460810, 0.637200, 0.586270, 0.035080, 0.314710, 1.169170, 1.421390, -0.062360, 
-0.113330, 1.013840, 0.719460, 1.219430, -0.256170, -0.859040, 4.055980, 1.089560, 0.868820, 3.615540, 
0.953840, 0.659630, 0.486210, -0.399540, -0.748500, 4.140830, 0.978120, 0.388850, -1.650480, 0.320950, 
0.088250, 1.223990, -0.353870, -0.592080, 0.942980, -0.427340, 0.741650, 2.582300, 1.481640, 0.491740, 
0.989350, 0.374490, -0.765680, -0.893750, -2.412650, 0.288200, 0.039880, -0.353280, -0.821060, -0.598420, 
-1.110880, 0.842790, -0.193380, -0.283580, 0.261320, 1.210850, -0.319150, 1.147880, 0.866340, -0.234010, 
1.113620, 0.782550, 0.562070, 0.984680, 1.494860, 0.608010, 2.363320, 0.173820, 2.565590, 0.711430, 
-1.449550, 5.994990, 0.109160, 0.178460, -0.278220, 0.633150, -1.357710, -1.157310, -0.492000, 1.223710, 
2.533730, 0.095300, 3.635510, -0.492250, 1.338040, 0.356150, 0.158750, 0.720050, 0.641070, -0.133850, 
0.502550, 0.360580, -0.076640, 0.259200, 0.808820, -3.154300, -2.422920, -2.493300, 5.370460, -1.302560, 
-0.805700, 4.574530, 0.475630, -4.686170, -11.728230, 0.442430, -1.945480, -0.643830, 0.300830, -0.673610, 
-0.535820, 0.117900, -3.231210, 0.663340, -0.869160, -0.695360, 0.007570, 2.797200, 0.117310, 1.343260, 
0.317310, -0.838560, 0.881970, -2.944130, -1.015790, 0.472700, -0.349120, 2.232690, -0.447160, -0.313920, 
-0.481060, 1.004750, 0.611970, -0.191240, -0.947090, 0.340200, 0.087810, -1.328640, -0.274550, -0.082330, 
1.757670, 0.300260, -0.634310, -2.574550, 3.467590, 0.711220, 2.198500, 1.263300, -0.461630, 3.622590, 
0.713020, 0.544240, 1.635850, 0.753020, 1.036380, -0.896160, 0.016220, 0.691090, -0.234430, -0.341240, 
-1.934790, -0.685640, 1.459760, 1.460250, -0.044280, -3.083600, -2.380180, -0.254680, -0.351660, -0.853780, 
1.256990, 0.922230, 0.545010, -0.942650, 0.650930, 0.167610, -0.866730, -0.604590, -0.406790, 0.709120, 
-0.058860, -0.199850, 0.076150, -0.035260, -0.961390, 0.976390, 0.704750, 0.368940, -3.327980, 0.656820, 
-1.947470, 0.614000, -0.063360, 0.193730, -1.279260, 0.737030, 0.368440, 0.580080, -0.310610, 0.267430, 
2.777800, 0.684450, -1.027360, 0.153680, -0.858600, 1.264260, 2.240200, 0.916050, 0.268560, 0.349100, 
-0.109140, -0.173490, 0.543790, 1.058880, -0.341760, -0.463970, -2.000320, 0.370270, 0.591220, 0.732270, 
-0.729680, 0.612180, 0.366900, 1.061920, -0.266780, 1.195410, 0.609430, 0.058390, -0.571480, 1.880580, 
0.390480, 0.104680, 2.415040, -0.310550, 0.139210, -2.969550, 0.733480, -0.627370, -0.938840, 0.936270, 
4.192870, 0.452790, 1.747280, -0.434800, 0.507300, 2.579930, 0.533830, -0.828880, -0.024390, -0.979220, 
-0.405110, -0.608790, 0.940000, 0.081670, -0.685400, -0.848980, -0.799920, 0.391240, 0.120160, -0.955720, 
-0.544070, -0.810760, 0.700420, 0.350030, 0.098120, -0.607720, -0.229100, -0.602340, -0.621290, -0.698110, 
-0.099340, 0.885450, 0.779370, -0.564810, -0.414560, 0.019320, 0.371320, 0.156660, 0.504230, 
0.511870, -1.076180, 0.094090, 0.287480, -0.664460, -0.584300, 0.935000, 0.643020, 0.804890, 0.738760, 
-0.359550, -0.690780, -0.992940, 0.176110, 0.878340, 0.834390, -0.547460, -0.460220, 0.786650, 0.722640, 
0.169410, -0.481330, 0.531450, -0.678970, -0.993560, -1.022090, -0.766400, 0.104380, 0.189300, -0.684220, 
-0.439880, 0.168420, -0.813240, 0.391200, -9.246620, 0.684060, -0.142590, -0.377510, -0.496770, -0.909540, 
3.775050, 0.792630, 0.891110, 0.775000, -0.606600, 0.146160, -0.080410, 0.325350, 0.853030, -0.655580, 
-0.873020, 1.478220, 0.683200, -0.194480, 0.013690, -0.243680, 0.105070, 0.925890, 0.811810, -0.086630, 

0.907290, -0.535760, -0.017610, -0.175470, -0.017470, 0.440740, -0.088370, -0.859390, 0.151200, 0.884140, 
0.213790, -0.800150, 0.212980, -0.759710, 0.843180, 0.090970, 0.448890, 0.352360, -0.939480, 4.443970, 
0.951160, -0.551050, -0.536450, 0.704830, -0.126750, 0.382430, 0.503220, -0.111930, -0.804720, -0.785790, 
0.457990, -0.318910, 0.515180, 0.898660, -0.268410, 0.368520, 0.585210, -0.167200, -0.777040, 0.338000, 
-1.009430, -0.417070, 0.820270, 0.965870, 0.408010, -0.783600, -0.904860, 0.753240, -0.130910, 0.320440, 
0.411290, -0.353710, 0.275150, -0.151100, -0.277530, 0.793920, 1.020390, 0.651570, -0.201540, 0.268370, 

0.042650, -0.788800, -0.083910, 0.012670, 0.746860, -0.201470, 0.192910, -0.608910, -1.098080, 0.997780, 
-0.639950, 0.767870, 0.156260, 0.400180, -0.317550, 0.688670, 0.008320, -0.573990, -0.810870, -1.116090, 
-0.232240, -0.016790, 0.426580, 0.354910, -0.486370, 0.012580, 0.929180, 0.740580, -0.808350, -0.802510, 
0.465660, -0.113480, -0.882760, 0.025850, 1.295620, 0.335510, -0.622670, -0.692770, 0.282280, 0.387870, 
-0.967710, -0.083720, 0.295300, -0.022790, 0.173720, 0.133800, 0.472180, -0.210160, -1.096320, 0.445770, 
0.320590, 0.929050, 0.105780, -0.742910, -0.122580, 0.530530, -0.386680, -0.881210, 0.412070, 0.861940, 

0.813970, -0.971890, 0.667030, 0.626410, 0.278310, -0.714720, -0.510980, -0.432440, 0.775660, -0.320670, 
-0.520260, 0.381070, 0.404530, -0.007180, -0.770680, 0.390900, -0.101740, -0.287480, -0.444180, -0.298540, 
-0.539180, -0.126700, -0.791770, 0.326570, 0.923680, -0.422480, -0.660050, 1.618600, -0.108850, -0.813500, 
0.485550, 0.836370, 0.618310, -0.902650, 0.605880, -0.072480, 0.261820, -0.628150, -0.781310, 0.874780, 
1.417370, 0.583460, 0.691330, 0.330150, 0.052060, 0.408000, -0.180620, 0.483070, 0.384870, -0.300330, 
-0.024390, -3.223490, 0.764810, 0.547700, 0.336850, 0.265640, -0.829240, -0.530630, -0.699840, 0.545760, 

-0.678370, -0.415150, -1.756100, -0.933330, -0.535490, -3.904620, -0.101730, -2.476160, 0.220360, -1.535900, 
0.156740, -4.946170, -0.814670, -1.211070, 3.160520, -0.792200, -4.350710, -2.996980, -1.152490, -6.647420, 
3.853880, 0.404900, 0.128350, -1.388770, -20.964340, 7.534450, -0.732100, -6.231370, -4.264890, -0.258000, 
-0.855550, -1.244420, 0.336420, -4.939560, -20.515520, -1.114080, -0.080720, -0.256420, -1.163140, -1.161840, 
2.711640, -4.249520, -0.077020, 35.268711, 1.491120, -1.260520, 4.276060, 0.001640, -0.111440, 0.057150, 
-0.315650, 6.045590, 0.155950, 0.201590, 0.364050, 0.282310, -2.958620, 0.249660, -0.790270, -1.350750, 

-0.607280, -0.358710, 0.079180, -0.553450, -0.945480, -0.312330, -0.118040, 0.252980, 0.663690, 0.782540, 
0.682790, -0.576330, -0.501680, -0.505520, 0.966230, -0.685590, -0.728190, -0.227270, -0.859940, 0.756410, 
0.725420, 1.943640, -0.755650, 0.829090, 0.539070, 0.135470, 0.520220, 2.975650, 0.505360, 0.528310, 
0.377630, 0.179630, -0.055560, -0.056990, 0.704960, -0.066470, -0.630340, 0.911890, 0.276850, 0.046460, 
0.740590, 0.460760, -0.164280, 0.871810, -0.690200, 0.948650, 0.551550, -0.174080, 0.031490, 0.794340, 
0.992810, 1.067740, 0.384640, -0.731890, -0.631450, 0.428770, 0.519130, -0.493490, -0.374670, 0.370160, 

-0.001640, -0.290960, 0.050260, 0.416470, -0.845240, 0.745030, 0.658280, 0.101710, 0.586120, -0.740840, 
0.888330, -0.689960, -0.675690, 0.291840, 0.805050, -0.075820, 0.636170, 0.902720, -0.782690, -0.911310, 
0.205490, 0.977890, -0.595860, -0.797850, 0.598590, -0.507600, 0.300490, 0.407720, -0.844160, -0.167960, 
0.380110, 0.477190, 0.488840, -0.033620, -1.339330, -0.443100, 0.240620, 0.191040, -0.308590, 0.845210, 
-0.495930, 0.141840, 0.229380, -0.322820, -0.646000, 0.814410, -0.878000, -0.616200, -0.615840, 0.838840, 
-0.902930, 0.928970, 0.760990, 0.053770, 0.298380, 0.054840, -0.207040, -0.746910, 0.718550, -0.697770, 

0.644150, 0.843620, 0.057050, -0.784530, 0.263160, -0.901420, -0.431430, 0.948190, 0.438720, 0.949080, 
0.875990, -0.345440, 0.967440, 0.588170, 0.005670, -0.259720, 0.079800, 0.880920, -0.681300, 0.531020, 
0.107640, -0.222080, -0.719750, -0.341270, 0.854000, 0.281610, -0.477400, -0.513210, -0.899650, 0.394510, 
-0.893310, 0.396020, 0.610580, 0.039990, 3.285690, -0.848320, 0.634090, 0.953500, -0.057020, 0.910030, 
-0.889930, -0.801190, 0.184280, -0.179720, -0.424820, 0.336760, -0.022380, -0.686870, 0.362350, 0.964900, 
0.210520, -1.156950, -0.764460, 0.701320, 0.014000, 0.843050, 0.820180, -0.003120, 0.226190, -0.705540, 

0.617600, -0.721590, -0.360530, -0.277000, -0.140270, 0.319320, -0.703860, 0.423390, -0.928360, -0.320710, 
-0.827850, 0.173310, -0.478190, -0.177410, 0.443200, 0.628200, -0.109480, 0.770400, 0.095770, 0.294480, 
0.685640, 0.183310, -0.418390, 0.189510, -0.643570, -0.366210, -0.990270, 0.012310, -0.356340, 0.066680, 
-0.128820, -0.272010, 0.080660, -0.730190, -12.246520, 0.000110, 0.927440, -0.225420, 0.760960, -0.614920, 
0.089630, -0.532130, 0.441940, 0.449730, -0.282320, 0.065540, -0.216840, 0.044310, 0.395360, 0.914530, 
0.637340, -0.041280, -0.728590, 0.074080, 0.634180, 1.002320, -0.021410, -0.477290, 0.241810, 0.705860, 

-0.497040, -0.356040, 0.926860, -0.735150, 0.882840, -0.897390, 0.798760, 0.783730, 0.171310, -0.087810, 
1.008190, -0.354000, -0.528880, 0.000330, 0.876010, 0.278460, 0.487710, -0.595490, -0.473930, -0.604920, 
0.140530, 0.671290, 0.366040, 0.338050, 0.136790, 0.086650, -0.956130, -0.345430, 0.626210, 0.585290, 
0.797020, 0.053930, 0.716300, -0.542970, -1.213510, -0.535550, 0.716870, -0.514620, -0.767490, -0.264810, 
0.761710, 1.077570, 0.651490, -0.838730, 0.238400, 0.637650, -0.797800, -0.779020, -0.606860, 0.788240, 
0.953340, -1.274330, 0.419320, -0.204620, -0.143560, -0.242750, 0.344340, -0.202190, -0.213660, -0.312690, 

0.845310, -0.501980, -0.133710, 0.110720, 0.313080, -0.979270, -0.664120, -0.357400, 0.334850, 0.258590, 
-0.616580, 0.317430, 0.855080, 0.729030, -0.287560, -0.183620, -0.173180, -0.037960, -0.649390, -0.114340, 
-0.381580, -0.391060, 0.104610, -0.561800, -0.464370, 0.703880, -0.726810, 0.435110, -0.028220, -0.361090, 
-1.115740, 0.796930, 0.593440, -1.026810, -1.657650, -0.699930, -1.126760, -0.422840, 0.779210, -0.308370, 
0.548840, 0.457520, 0.727730, -0.995580, -0.854550, -0.503270, -0.994800, -0.278270, -0.003340, 0.184270, 
-0.942480, -1.380080, 4.285880, 0.978600, 0.063250, -0.569190, -0.232130, 0.563470, -0.141570, -0.263490, 

-0.550070, 0.840920, -0.135490, -0.947520, -0.190770, -0.395210, 0.719070, -0.332380, 0.882320, -0.408520, 
0.101590, -0.831030, 0.669300, -0.982330, -0.858270, 0.950360, 0.015040, 0.027700, 0.174340, -0.516120, 
-0.276950, 0.022910, -0.776670, -0.886220, -0.071700, 0.288730, 0.889200, -0.810210, 0.078880, -0.951290, 
-0.899780, -0.621560, 0.619860, -0.018810, -1.400540, 0.497120, -0.228350, 0.438890, 0.105610, -0.075970, 
0.114740, 0.795860, -0.701340, -0.295320, 0.982620, -0.095110, 0.022200, 0.135080, 0.305530, 0.719150, 
0.572780, -1.508520, -0.141220, 0.762670, -0.770740, 0.913930, 0.412030, 0.514320, 0.009760, 0.150770, 

-0.774350, -0.268550, 0.033920, -0.403460, -0.078230, -0.601370, 0.564870, 0.055290, 0.636770, 0.797390, 
-0.901450, 0.804370, -0.137290, 0.414120, 0.426900, -1.003430, -0.866020, -0.569880, -0.656110, 0.920040, 
0.450900, -0.412380, -3.253000, -0.515540, -0.392750, -0.986280, 0.260590, 115.678467, -1.077240, -0.083360, 
0.140030, -0.544530, -0.815560, -1.208340, -4.084460, 0.737240, 0.451810, 0.262060, -0.202200, 0.023610, 
-1.834000, 0.761190, 0.499290, 0.580780, 0.005060, -0.276960, 0.491220, 0.732710, -0.339070, -0.580300, 
0.025740, 6.516660, -2.564530, -5.719540, 0.497740, 0.607160, -0.925920, 0.871450, -18.322050, 0.694350, 

0.422610, -0.407460, -0.270520, -0.128890, 0.833500, -0.229430, -0.211740, -0.625360, -0.709440, 0.034650, 
0.591680, -0.643380, 0.624120, -0.276090, 0.301270, -0.658830, -0.725410, -1.392520, 0.528020, 0.102140, 
0.163590, -0.917690, -0.179500, -0.657300, -0.442420, 0.723570, -0.169590, -0.739270, -0.532670, 0.089340, 
-1.016930, -0.424330, 0.055180, 0.262160, 0.005360, -0.851040, 0.883890, 0.271200, -0.480390, -0.857260, 
0.082610, -0.179220, -0.461290, 0.732030, -0.405140, 0.166680, -0.267730, 0.565920, 0.016540, -0.293880, 
0.200660, 1.515400, 0.039100, -0.993860, 0.174920, 0.125180, -0.355940, -0.330300, 0.836810, -0.645530, 

-0.129240, -0.571970, 0.711860, 0.192870, 0.707310, 0.646540, 0.399390, -0.846320, -0.339060, -0.499050, 
-0.271110, -0.573870, -0.112060, 0.658340, -0.397640, -0.771680, -0.127570, -0.661300, -0.547820, 0.455280, 
-0.812030, 0.851140, 0.392210, 0.565550, -0.642480, 1.151920, 0.792790, 0.153350, -0.588380, -0.952960, 
0.590860, -0.250220, -0.179750, -0.761460, -0.944340, 0.383230, 0.549360, -0.681850, 0.937950, 0.478870, 
0.646490, 0.361700, 0.989030, -0.642400, 0.453890, -0.351560, 0.986980, -0.610110, 0.789320, -0.222270, 
0.738240, -1.048340, 0.746980, -0.308740, -0.050310, -0.320890, -0.243680, -0.805250, 0.789640, 1.006840, 

0.586840, -0.485780, -0.465930, -0.155940, -0.830220, -0.460750, -0.804350, 0.206990, 0.324480, 0.751130, 
0.773140, 0.804270, -0.460400, 0.224820, -0.514200, -0.470580, 0.346510, -0.952020, 0.581220, -0.035790, 
-1.007420, 0.560160, 0.056650, 0.053390, -0.183570, 0.715440, 0.944650, 1.133930, -1.521400, -0.911030, 
0.324320, 0.427360, 0.607270, -0.338800, 14.781520, -0.987750, 0.786440, 0.577670, 0.693160, 0.531040, 
32.954449, 0.920640, -0.214160, 2.089930, 0.228710, -0.261270, 0.474570, 0.713630, 0.018620, 0.307540, 
-0.818100, -2.821800, 1.764680, -0.145750, -0.730380, -0.630980, -0.293870, 0.711450, 0.603310, -0.615740, 

-0.874490, -1.750880, -0.444030, -1.417830, 0.282530, -0.590790, -0.832020, 0.156970, -0.134410, -0.917320, 
0.212230, 0.318780, -0.738670, -0.323280, 0.064470, 0.476910, -0.778170, 0.933570, 0.052590, -0.805100, 
-0.190770, -0.073030, -0.216300, 0.088630, -0.002260, -0.302700, -0.293450, -0.368940, 0.278120, -0.223380, 
0.824120, 0.650550, 1.063080, 0.091730, -0.774380, 0.344850, -0.108860, 0.393320, -1.070510, -0.125920, 
0.149520, -0.807670, 0.325000, 1.152390, -0.761370, -0.521990, -1.183470, -0.269630, 0.743960, 0.455820, 
-0.963910, 1.437290, -0.971230, 0.101340, -0.012340, -0.498170, 0.065920, -0.796170, -0.502390, -0.087650, 

0.610970, -0.570340, -0.009050, -1.002240, -0.580410, -0.597410, -0.136460, 0.431870, -0.355070, 0.335190, 
0.830100, -1.496350, -0.451670, 0.540020, -0.835090, 0.005440, -0.331400, -0.857500, -0.155170, -0.663530, 
0.487100, 0.104560, 0.337160, -0.459010, -0.227170, 0.104660, -0.956790, -3.163240, 0.804980, 0.287620, 
0.819510, 0.871780, -1.632050, 0.695340, -18.532280, -0.072330, 0.804100, -0.708040, 0.804280, -0.571080, 
-36.061291, -0.331700, 0.010970, -1.815140, -0.769780, -1.191920, -0.244650, -0.400230, -0.427290, -0.168420, 
-0.654120, 5.786550, -5.496520, -0.693150, -0.129590, -0.161110, 0.001430, -0.258720, 0.653850, 0.762970, 

0.074270, -0.307880, 0.241210, -0.197090, 0.193990, 0.237060, -0.125710, 0.180030, -0.476220, -0.062190, 
0.105030, -0.257480, -0.464320, -0.309900, 0.711330, -1.121900, 0.556290, 0.598210, -0.534200, 0.372000, 
0.436970, 0.130000, 0.026220, -0.815330, 0.631700, -0.194160, -0.258210, 0.182540, 0.549800, -0.150730, 
-0.686560, -0.816040, -0.373530, -0.537810, 1.652270, 0.325450, -0.876240, 0.035940, -0.335660, 0.320250, 
0.773530, -0.487560, 0.347970, -0.338940, -0.929430, -0.578630, -0.608790, -0.699560, 0.091680, -0.574830, 
0.881940, 3.274110, 0.215920, 0.577150, -0.544850, -0.292390, -0.233600, -0.193990, 0.842900, -1.003640, 

-0.695400, 0.570440, -0.677950, -0.284150, -0.628250, -0.573830, -0.649240, -0.048000, 0.634770, -0.085290, 
-0.565500, 0.737810, 0.521010, -0.132270, -0.310480, -0.002400, -0.738660, -0.006250, 0.641630, 1.086830, 
-0.754360, 0.303690, -0.798260, 0.741890, -0.626230, 0.369280, -0.945430, -0.581770, 0.685330, 0.123800, 
0.190500, -0.610260, 0.315790, -0.498910, 1.398220, 0.437420, -0.347240, -0.919670, 0.175280, 0.252790, 
0.781480, 0.769050, 0.846100, 1.009970, 0.214010, 0.044000, 0.351990, -0.643740, 0.243090, 0.752070, 
0.118840, -1.162690, -0.401650, -0.550000, 0.089100, 0.232920, -0.771460, 0.575910, 0.513680, -0.071770, 

-0.478180, -3.170860, 0.249630, -0.488530, -0.962080, 1.803780, 0.319830, 0.672650, -0.641540, 0.259400, 
0.201420, -0.466170, 2.750090, -0.102480, 0.410210, -0.054810, -0.276530, -0.327180, -0.330400, 2.536200, 
0.416870, 0.448740, -0.216090, 0.346180, 0.564270, -0.435020, -0.306330, -7.500790, -0.208590, 2.258270, 
0.002730, 0.967840, 0.183260, -0.557410, -5.544520, 0.415170, 0.953700, 0.970640, -0.800160, 0.529620, 
-6.947700, -0.567150, 0.224660, 0.192930, -0.430140, 0.059660, 0.085830, -0.532580, 0.788400, 0.723090, 
-0.631140, 0.928310, 2.767780, 0.139720, 0.129010, 0.718470, -0.235470, 0.681460, 0.133480, 0.716790, 

-1.062660, 2.974690, -1.487760, 9.147800, -5.133650, 3.985630, -5.610090, 0.311790, 0.595780, -2.076060, 
5.611370, -1.004590, -1.079760, -14.010050, -0.722080, 18.229900, -1.960690, 23.662010, -0.280300, -1.512030, 
-0.934650, -1.765810, 2.878870, 48.063179, 0.540030, 5.169990, -1.566490, -0.762840, -1.396180, 13.820030, 
9.496240, -0.470450, -0.612740, 1.942290, -1.337670, -0.875950, 0.665450, 0.409570, 0.069880, 0.145790, 
0.156300, 9.098770, 0.881790, -0.602200, -0.232470, -0.482140, -0.470020, -0.114060, 0.529060, -0.798210, 
0.183840, 0.523890, -7.784090, 0.387020, 0.567040, -0.280510, 10.124460, -0.240160, 2.455790, 0.895470, 

0.557860, 0.294310, -0.702090, -0.478070, -0.375080, 0.589550, 0.012680, 0.626390, 0.755560, -1.001280, 
-0.944340, 0.199140, 0.318360, 0.008890, 0.494750, -3.095640, 0.785730, -0.306820, -0.616510, -0.210210, 
0.932720, -0.998350, -0.415700, 0.631990, -0.180440, 0.845780, 0.196180, 0.622950, 0.481350, 0.381090, 
0.090060, -0.390310, 0.222550, -0.216160, 0.814610, -0.042900, 0.622730, -0.685370, 0.179060, -0.263570, 
1.127540, -0.724240, 0.794810, 0.333300, 0.615750, 2.263910, -0.783180, 0.399110, -0.278820, 0.773840, 
0.258050, -2.810120, -0.441480, -0.404230, -0.869600, 0.880910, 0.351930, -0.137250, -0.727470, -0.813900, 

0.236770, -1.512920, 0.129920, -0.381390, 0.647370, -0.223310, 0.080440, -0.192200, -0.428780, 0.684430, 
-0.933980, -1.028070, -1.092970, -0.183800, 0.498930, 0.692400, -0.017240, -0.724530, 0.357300, -0.185080, 
0.317700, -0.911290, -0.423500, -0.633440, -0.676250, -0.493110, -0.820720, 0.673710, 1.770970, -0.261680, 
-0.752350, -0.010900, -0.037290, 0.858660, 1.275630, -1.006920, -0.330430, 0.119690, -0.683690, -0.946730, 
0.228890, 0.298530, 0.294430, 0.189370, -0.526950, -0.582100, -0.703960, 0.543940, 0.018950, -0.577220, 
0.310310, -0.479750, 0.631340, -0.150620, -0.549900, -0.246740, 0.608360, 0.683110, 0.956320, -0.070310, 

-0.396340, -0.118240, -0.522960, 0.478830, -0.809580, 1.020540, -0.017870, 0.912050, -0.611610, 0.153960, 
0.522710, -0.568930, -0.650740, 0.156550, 0.037510, 1.001480, 0.002420, 0.993790, 0.841950, 0.221220, 
0.988910, -0.135500, -0.841810, -0.689060, -0.432140, 1.039260, 0.862830, 0.155130, -0.335280, -0.017780, 
-0.736910, 0.908720, 0.138780, 0.492190, -1.099630, 0.775830, 0.467200, 0.389870, 1.065980, -0.595130, 
-1.175230, -0.636380, -0.387550, -0.011350, -0.730900, -0.241740, -0.775390, 0.061300, -0.742860, -0.360870, 
-0.858030, -0.318310, -0.108730, 0.321420, 1.068200, 0.755190, -0.711160, 0.363140, -0.417310, 0.658670, 

-0.105000, 0.387350, -0.081140, 0.850810, 0.537130, 0.062070, 0.995770, -0.146810, 0.572860, 0.727290, 
0.664620, 1.181860, -0.621160, -0.174740, -0.171060, -6.420480, -0.018960, 0.087550, -0.874090, 0.444430, 
-0.727070, 0.788220, -0.461830, -0.738900, -0.502000, 0.935220, 0.519040, -0.667790, 0.633430, -0.470800, 
1.175650, 0.596590, 0.300910, -0.584890, -1.159470, 1.022300, 0.866500, -0.753630, -0.659020, 0.179550, 
-3.491210, 0.315690, -0.689050, 0.320840, 0.757250, -0.504240, 0.934600, -0.100990, -0.616520, 0.853000, 
-0.288490, 3.765790, -0.915300, -2.832050, 0.635050, -0.641890, -0.758330, -0.230790, -0.273190, 0.091440, 

0.226450, 0.766650, 0.015430, 0.697290, -0.664930, 0.776130, -0.307410, -0.599120, 0.525870, -0.356160, 
-0.983340, -4.145250, -0.488720, 0.720880, -0.893950, 0.376550, -0.404770, -0.214330, 0.960760, -0.009920, 
0.626600, 0.246950, 0.639550, -0.049840, 0.124890, 0.580710, 0.920340, 0.644790, 0.279500, 0.782710, 
0.001850, -0.140680, 0.438740, -0.545110, -0.840390, -0.367580, 0.190460, 0.697850, 0.297400, -0.729690, 
-2.885970, -0.737780, -0.684060, -0.155610, 0.544420, 0.031710, -0.129330, -0.067360, 0.092230, -0.019110, 
-0.246220, -1.236970, -1.256460, -0.937280, 0.180950, -0.849910, 0.931410, -1.004890, -0.453750, 0.321970, 

-0.482590, 1.151470, 0.824150, 0.771850, 0.664550, 0.316530, 1.512010, 0.814540, -0.351850, 0.396610, 
0.131490, -0.126890, 0.863860, -0.153990, 1.008050, -3.837740, -0.432950, -0.797160, 0.437120, 0.323740, 
-0.882890, -0.220400, 0.801060, -0.087910, -0.132960, 0.611110, -3.821620, 0.239650, 1.103890, 0.023930, 
0.349260, -0.251150, 0.107740, -0.554300, -2.497330, -0.428640, 0.503630, 1.021120, -0.007250, -0.430460, 
-0.200460, -0.140770, -0.906490, -1.561710, -0.198730, 0.227390, 0.900830, 0.963150, 0.008010, -0.066490, 
-0.571720, 4.815960, -6.650030, -15.602150, 0.865150, 0.447720, -0.870200, -0.758950, -0.102910, -0.759290, 

-0.750720, -0.625360, 0.002660, -0.133070, 0.272770, -0.282280, -0.441080, -0.003850, -1.034390, -0.679480, 
0.054430, 0.325190, 0.420850, -0.886660, -0.249790, 0.768820, 0.747920, -0.992230, -0.338180, -0.926110, 
-0.760200, 0.118690, 0.338150, 0.859670, -0.927500, -1.006870, 0.921840, 1.549020, 0.828030, -0.280470, 
-0.973000, -0.290180, 0.265900, 0.785590, 0.216190, -0.463270, 0.565560, 0.606010, -0.362070, -0.510370, 
1.287740, 0.366240, -0.333360, 0.830590, 0.392110, -0.912000, 0.420970, 0.400990, -0.385530, 0.540280, 
-0.856830, 0.299460, -3.564940, 1.096530, -0.696810, -0.572790, 0.553510, -0.698810, 0.073150, 0.374530, 

-0.071070, -0.560700, 0.194420, -0.018950, 0.710550, -0.463740, 0.338140, 0.124840, 0.881790, 0.513980, 
0.581960, -0.022950, 0.800200, -0.100210, 0.726450, 0.740550, 0.016110, -0.906540, 0.771170, 0.767710, 
-0.954640, 0.546900, 0.872920, 0.257360, -0.693540, 0.220480, 0.804250, 0.553700, -0.668590, -0.212430, 
-0.852280, -0.926990, 0.682420, -0.019890, 10.147600, 0.244010, -0.288880, 0.567510, -0.491320, -0.661170, 
-0.374260, -0.643980, 0.894850, 1.032480, -0.154370, 0.320390, -0.099950, 0.907110, 0.075200, 0.812220, 
-0.937230, -0.232900, 0.773560, 0.802790, -0.812360, 0.344100, 0.090780, -0.361320, -0.175030, -0.819490, 

0.740680, -0.579670, 0.631360, 0.319010, 0.387170, 0.826440, 0.684710, 0.704440, -0.776820, -1.016180, 
0.633500, -0.354260, -0.308250, 0.796620, -0.367300, 0.203090, 0.702660, -0.107110, 0.185830, -0.329720, 
-0.056800, -0.196000, 0.586070, 0.839660, -0.339340, -0.215700, -0.844100, -0.105080, 0.353920, -0.859990, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, -0.459970, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, -0.248680, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, -0.039930, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, 0.666730, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 1.047620, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, -0.359730, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, 0.838700, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, -0.123900, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, -0.119390, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, -0.063940, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -0.024760, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, -0.489580, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, 0.501210, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, 1.038450, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, -0.365930, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, -0.715750, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, -0.491780, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, -0.272690, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, -0.817900, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.650040, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, 0.548840, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, -0.503840, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, -0.498450, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, -0.457950, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, -0.641110, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, 0.243700, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, 0.185060, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, -2.322410, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, -0.124410, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, 0.492520, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, 0.512770, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, -0.863510, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, 0.152060, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, 0.196120, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, -0.047890, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, 0.340390, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, 0.425590, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, 0.172190, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, -0.902320, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, 0.489830, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, -0.319090, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -0.690520, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, 0.549190, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, 0.204240, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, -0.581630, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, -0.613060, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, 0.083510, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, 0.290320, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -0.187430, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, -0.015190, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, 0.103820, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, -0.766350, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, -0.848950, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, 0.698570, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, 0.911400, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, 0.096930, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, -0.246280, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, 0.936210, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, -0.370010, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -0.225380, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, -0.251370, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
1.09405, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.09031, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
0.09248, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
0.33530, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.12568, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
1.02988, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
0.58351, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
1.42320, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
0.00911, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
1.42742, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
1.34222, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
1.42518, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
0.33848, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
0.09251, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
1.13450, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
0.00029, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.39331, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
1.39318, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
0.00071, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
0.00091, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
1.39181, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
0.42529, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
0.00839, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
0.42521, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
1.12918, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.03847, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
0.02627, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
0.00053, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
0.00810, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.02908, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
1.08482, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
1.42465, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
0.47659, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
0.12388, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
0.00006, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
1.42010, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
1.39003, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
1.42357, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
1.38860, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
0.76259, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
0.00238, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
0.04160, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
1.42852, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
0.05406, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
0.24649, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
0.13993, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.28219, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
1.30534, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
1.22436, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
0.11930, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
1.42837, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
1.42857, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
0.20973, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
0.00474, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
1.42496, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
1.42818, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
0.00006, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
1.42746, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
0.00091, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.10813, 0.500000, 2,
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
