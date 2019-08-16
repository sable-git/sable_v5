/*********************************************************
  Pfam_RP_all_0_7.c
  --------------------------------------------------------
  generated at Fri Jan 14 10:18:45 2005
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
0.987010, 0.715160, 0.711030, 0.751910, -1.101030, -0.393230, -0.200800, -0.188470, 2.242940, -0.143340, 
-0.022990, -0.474080, 0.811360, 3.657730, 0.226980, 0.369970, 0.436120, -0.187640, 1.139660, -0.534440, 
-0.586930, -1.264110, -0.983910, 0.777540, 1.428600, -0.783640, -0.638980, 0.078140, -1.589370, -0.732480, 
-0.639750, -0.002670, -5.228580, 0.485230, 0.014960, -0.271910, 1.234430, -0.070350, -0.013130, 0.112390, 
-0.946060, 0.924200, -1.330890, -0.379940, 3.288790, -0.212080, -1.835460, -0.571700, -1.251060, -0.884030, 
-0.147770, -0.427400, 0.397220, -1.214790, -0.381930, -0.045230, 1.121350, 0.199810, 0.966710, 1.016760, 
-0.649090, -0.054860, 2.899820, -2.083160, -0.213680, 1.835240, 0.356480, -0.300750, -0.656980, -0.458020, 
-1.284240, 0.067600, 1.731740, -0.480700, 0.846630, 0.067690, -1.783000, -0.436880, 0.321500, -0.607180, 
0.103400, 0.198890, 4.004230, 0.165270, 0.415730, 0.359160, -0.262800, 0.796400, -0.023210, 1.666820, 
2.878180, 0.933020, -0.456720, -0.320220, 0.205480, -1.183080, 0.636920, 0.187790, -0.052090, 1.788450, 
-0.063810, -0.338480, 0.289780, 0.605230, 1.594580, 1.546840, 0.244020, 2.092190, -0.395730, -1.047140, 
-1.058700, -0.081250, 0.961530, 0.768260, -0.065910, -1.171160, -1.943360, -2.943850, -0.284060, -4.987870, 
-1.161520, 1.017570, -2.840380, -3.020120, -1.792360, -3.374170, -4.370760, 1.040900, 1.840930, -1.774320, 
-1.475020, -0.286220, -8.896680, -1.643610, -0.563820, -5.031850, -0.350200, 0.203070, -0.014120, -0.028360, 
0.716910, -0.446400, -0.228070, 0.786210, 0.480660, -0.280310, 0.423300, -1.051410, 3.709160, 1.643880, 
-0.194220, -1.567040, 1.329750, -0.623900, 0.262370, -0.032670, 0.848780, 2.137250, -0.792830, -0.045090, 
0.616040, 1.858070, -1.419230, -0.419640, 0.617390, 0.281200, -1.141130, 1.140250, -3.436390, 2.013230, 
-0.617310, -0.355610, 0.462870, 0.674840, 0.463780, -0.696040, 0.656060, 0.538480, -0.363420, -0.912880, 
0.479410, -0.537290, 0.515130, -0.261910, -2.685860, -4.218850, -0.607580, 1.612400, -1.964080, -1.374540, 
-0.150070, -0.689080, -2.867350, 0.149540, 1.995090, -0.067620, -0.549780, -0.764250, 1.740330, 0.143600, 
0.816390, -1.388660, 0.011790, 1.251100, -0.898100, 0.431970, -0.736080, -0.792590, -1.254340, -1.925100, 
0.220950, 0.076920, -1.083650, 0.954560, 0.093670, -0.992500, -1.894620, -0.255420, -0.017600, 0.818550, 
0.968070, 0.916340, 1.019080, 0.712970, 3.580180, -0.174920, 1.097240, 0.449480, -0.928230, 1.150730, 
-1.557470, 0.793220, 0.714050, 2.282450, -0.540070, 0.059220, 0.230790, -0.788960, -2.460900, 0.271130, 
-0.871270, -1.745420, 0.350870, 3.434220, 0.910310, -0.408210, 0.531660, 0.243860, 0.457930, -0.562620, 
1.563240, 0.614030, 0.258780, 10.072900, 0.602630, -3.139610, 0.901700, -0.417060, -0.353610, -0.483840, 
-0.827580, -0.297590, 1.360510, 1.839320, -0.110690, 0.512310, 1.493850, 1.039760, -0.534970, 1.057680, 
0.374720, -0.245110, 0.474770, -0.321280, -0.704540, 0.898720, 0.347470, -0.377490, -0.482630, 0.284580, 
-0.054310, 0.278530, -0.189160, 0.055810, 0.651680, -0.337090, 0.204930, 0.560180, 0.731520, 1.033860, 
0.826620, -0.897900, 0.681010, -0.816560, -0.693020, 1.084990, -0.755230, 0.101760, 0.836540, 
-0.561640, -0.450790, -0.999730, -0.873290, -0.624500, -0.227500, -0.141670, 0.885260, -0.424230, -0.179010, 
-0.809670, -0.356160, 0.861750, 0.639480, -0.151400, 0.003580, 0.138900, -0.066990, 0.746190, 0.278190, 
0.744010, -1.828380, -1.221630, -0.585830, 0.164990, 0.964290, 0.848290, -0.426880, 0.346450, -0.640730, 
-1.481910, -0.056700, -1.234200, -0.211770, 0.264280, -0.306530, -1.009760, -0.282810, -1.408490, -0.468250, 
-1.186780, -0.347610, -0.419570, 0.704110, -0.273280, 0.573410, 0.400390, -0.377850, -0.058750, 0.534300, 
1.027300, 0.987660, -0.564980, 0.568630, -0.554350, -0.663680, 0.210350, -0.156680, 1.048370, -0.029460, 
-0.401660, -0.182980, 0.205630, -1.024120, 0.891020, -0.171150, -0.558250, -0.023040, -2.307080, -0.106600, 
0.556340, -0.063070, 0.292580, -0.224850, -0.689250, -0.730010, 0.767950, -1.447480, 1.144200, 1.518760, 
0.630500, 0.014030, -0.045360, 0.147430, -0.342330, 0.076740, 0.141340, 1.655360, -0.611450, 0.703810, 
-0.759380, -0.676440, 0.488300, -0.228790, 0.932630, -0.755060, 0.046320, 0.523730, -0.837740, -0.862150, 
0.495930, 0.048610, 2.064680, 0.817900, 1.028130, 0.429670, -0.625470, -0.170060, 0.473560, -0.118710, 
-0.911110, 1.139020, -1.371390, -0.385560, -2.203990, -1.664500, -6.084750, 0.289210, -2.126720, -0.112870, 
-4.545990, -0.133800, 0.525890, -2.899130, -5.212730, -0.623550, 0.384800, -0.395450, -0.645750, -0.180140, 
2.561390, 1.061610, -2.948460, 2.309460, 1.573730, -5.765670, -1.242690, -0.339350, -0.607040, 0.369680, 
0.163980, -0.771300, -0.250160, 0.124380, -0.692610, 0.807350, -0.976670, -1.979090, -0.193470, -1.426910, 
0.658150, 1.292830, -1.094150, 0.460130, 0.628470, -1.916330, 0.135850, 0.615610, 0.214050, 0.424110, 
0.489960, 0.900760, -0.412520, 0.134160, 0.523310, -0.107230, 0.138630, 0.047010, 0.973570, 0.131730, 
-0.717620, -0.392040, 0.652680, -1.063240, -0.581350, -0.039770, -0.389220, -0.253780, -0.545510, -0.709930, 
0.976750, 0.680920, 0.217600, 1.352180, 1.313420, 0.427110, -0.486890, 0.679580, 0.598530, 1.930540, 
-0.057110, -0.430960, -0.243550, -0.246080, -0.477280, -0.816850, 0.805320, -0.380350, -0.377730, 0.339290, 
0.995370, -0.116180, 0.315060, 1.505460, 0.446540, 0.263180, 1.384120, -1.105070, 0.569380, 0.029180, 
-1.007300, 0.615090, 1.451480, 0.103240, -0.032330, -0.229090, -0.594190, 0.373360, -0.309300, 0.010510, 
0.579680, 0.133880, -0.104980, 0.283390, -0.455420, 0.060490, 0.007000, 0.801930, -1.941260, 0.536990, 
-1.188950, -1.710270, 0.444590, 0.510720, -0.347680, -0.208530, -0.869540, 0.521680, 0.525270, -0.148540, 
-1.250700, -0.543350, -1.217310, -0.290550, -0.104050, -0.385380, -2.491880, 0.379280, 0.630470, -0.810270, 
1.629080, 0.933230, 3.015290, 0.916760, -0.297600, -1.568660, -0.917250, -0.418690, -0.649400, 5.832610, 
4.289820, 1.694780, 0.741370, 0.067750, -1.222790, 0.198610, 0.203070, -0.060130, 0.014240, 0.449830, 
1.518850, 1.223270, 0.982800, 0.618820, 4.666940, 0.353270, 0.243180, 0.500950, 1.016390, 0.179280, 
1.563310, 1.750940, 1.134920, 0.664510, 0.142180, 1.012190, 0.185480, 2.682860, 2.285610, 1.348890, 
1.689790, 0.230730, 1.019200, 1.838670, 1.291460, 0.957810, 2.797550, 0.345800, 3.422890, 
-0.746760, 0.735600, -0.153960, 0.534200, -0.152170, -0.618910, 1.351690, -0.584750, 1.622760, 0.617640, 
1.095280, 0.783560, -0.186040, -0.116700, 0.723020, -0.469150, 1.066970, -0.919560, -0.925840, -1.037210, 
-0.552320, 0.513670, -0.105610, 0.294840, -0.480520, 0.723830, 0.227680, -2.754910, 0.091270, 0.296700, 
0.807760, -0.705830, 1.129220, 1.971790, 0.763490, -0.336940, -0.068870, -0.673360, 1.892040, 1.706570, 
-1.441540, 0.147940, 0.913110, -0.978440, 0.254340, 1.374950, -0.701180, 0.163620, 0.284180, -0.237170, 
-4.331910, -0.292450, 0.830360, -0.012650, -1.959950, -1.318580, 2.640050, 0.288960, -0.374770, -0.773320, 
-3.450520, -0.064170, 1.481280, -0.351280, 0.577620, 0.335420, -0.529790, -1.167880, -0.629980, -0.382710, 
-3.776960, -0.820310, 1.967190, 1.085330, -1.259820, 0.977680, 0.611730, 0.254350, -0.533130, 0.740730, 
0.163640, -0.692180, -0.004590, -0.309460, 0.836870, 1.270900, -0.708600, -1.049340, 1.375250, -1.076550, 
0.899940, -0.914540, -0.932360, 1.450190, -0.231540, 0.572730, 0.981890, 0.029380, 2.158700, 1.578790, 
0.143020, -1.076940, -1.384930, 0.023540, 0.886030, 0.427130, -0.794290, -0.031480, 0.819710, -2.292660, 
0.824410, 0.382980, 0.022460, 0.610530, 3.299570, 0.840040, 1.242300, -5.224000, -0.480320, 2.973180, 
0.640520, -0.008240, 1.430080, 0.138290, -0.953200, -0.285450, 0.178200, 0.516700, -0.243840, -0.160330, 
-2.520680, 0.705030, -0.679590, 0.952420, -0.238970, -0.718120, -1.371480, -0.771340, 0.690780, 3.988110, 
3.250450, 1.341730, 0.290300, 1.535680, -0.903750, -0.701800, 0.279990, 0.729720, -0.285130, 0.151570, 
0.652860, -0.447000, 0.937780, 0.341090, -1.013350, 1.685110, -1.670440, 0.137430, -1.012940, 0.517980, 
-1.329620, 1.379670, 1.805170, 0.406530, -1.242740, 0.891830, -0.204870, 0.480660, 0.296930, 1.313520, 
0.323190, -0.261140, -0.856970, 0.291190, -0.027220, -0.228520, -0.175720, 0.129510, 0.371710, -2.538850, 
-0.870110, -0.620200, -0.577390, -4.875610, 2.928680, 0.087250, -0.143520, -0.963110, 0.646550, 0.498890, 
1.940690, 0.434430, 2.201960, 0.993330, 0.467410, -0.737690, -0.081350, 1.348280, -0.329370, 1.158720, 
-2.954710, -0.250840, 0.768630, 0.061080, 0.292040, -0.276600, -1.798540, 0.232490, 0.072600, 1.764080, 
0.415480, 1.327990, -0.014750, -0.261200, 0.040500, 1.529470, 0.334290, -1.201280, 0.095370, 0.698880, 
3.303520, 2.894700, -0.830600, -0.702770, 2.415230, 0.716020, 0.425650, -0.509310, -0.487400, -2.425170, 
0.124720, 0.909060, 0.107260, 2.304420, -0.289560, 0.522690, -0.843430, -0.780020, 1.715130, 0.109470, 
-0.037770, 0.020260, 0.792680, -0.443600, -1.053980, 0.049590, 0.163900, 0.495390, -1.240720, -1.109630, 
0.403030, -0.822680, -0.486150, 0.843840, 0.254990, -0.983940, -1.044900, 1.017160, -0.409670, 1.393140, 
0.165990, 0.071090, -1.621920, 1.483360, 0.638530, 3.900490, -1.339250, -0.007720, -0.749050, -0.365040, 
-1.017280, -0.630860, -0.086830, -2.177350, -0.335930, -1.129830, 0.278150, -0.046030, -0.662190, -1.863600, 
-1.055140, -1.453320, -1.584570, 0.023380, -1.556490, -1.233720, 0.156010, 0.018600, -0.821110, -1.171510, 
-1.023310, -1.076990, -1.593390, -1.032940, -2.398280, -1.209470, 0.313600, -2.234440, -7.006570, 
3.661960, 1.846130, 2.510360, -0.197180, 0.128650, 0.313610, 0.537050, 1.084130, -0.373430, 0.585660, 
-0.160170, -0.135000, 0.665450, 0.765440, -0.678810, 2.158720, -0.677960, -0.655700, 1.134940, -0.595470, 
2.287430, 0.324240, -0.066670, -0.471610, -1.490850, -0.776790, 0.481650, 1.658760, 0.258020, -0.903810, 
0.863700, -0.970460, -1.553410, -0.895930, -0.293620, 0.005770, 0.410050, -0.482140, 0.000170, 0.855970, 
0.677500, -1.565860, 2.657340, 0.874200, 1.938900, -1.122830, -0.213790, -0.174210, 0.045900, -0.705400, 
0.908540, -3.195800, 1.627710, 0.093110, -1.134050, -0.748380, -0.204300, -1.014000, 1.227270, -1.876490, 
-0.008020, -0.531020, 0.572090, -1.708650, -0.562940, -0.835370, 0.957790, 1.237440, 2.539640, -0.127920, 
-3.521710, -0.565340, 0.526240, 0.179590, -0.251790, 0.237530, -1.165300, -0.885310, 3.121560, -0.076390, 
0.413810, -0.152050, -3.735090, -0.253940, 1.429310, 1.186110, 3.425240, -0.741000, 1.323170, 0.168340, 
1.060490, 3.094240, 0.724250, 0.641290, -1.057990, -0.870870, -1.552330, -9.397380, -0.025080, 0.310760, 
0.582050, 0.757230, -0.322260, 0.969190, 1.948920, -0.156680, 0.630540, 2.379860, -0.634430, -1.842240, 
-0.071830, 0.281520, 0.402720, 1.502030, -0.106080, -1.035420, -1.980870, -0.146110, -0.446860, -1.745090, 
-0.981450, 0.827090, -0.781580, -1.208180, -1.279980, 0.337500, -0.355490, -0.920540, 0.095350, -1.874200, 
0.382580, -0.185100, -1.862480, 0.218150, -0.789030, 0.869190, 1.701360, 0.166510, 0.281450, -0.148010, 
0.534310, 1.303010, 0.971970, 0.861330, 0.510720, -0.890310, 1.097460, 0.990730, 1.375650, -0.420620, 
0.607770, -0.383600, 0.668710, 1.202330, 1.159210, 0.705360, 0.939250, 0.028480, 0.843740, 1.522680, 
1.519990, -0.847770, 1.300390, 0.337580, 1.674560, 1.648350, -1.667930, 1.781640, -0.075860, 1.687370, 
1.720090, -0.294930, -0.534390, 0.727490, 1.247830, -0.092390, -1.510570, -0.077610, -1.597770, -0.588790, 
-2.490240, -0.021790, 4.184530, 1.037820, -0.675860, -0.781390, -2.398400, 0.868950, -0.897170, -2.825580, 
-0.501300, -1.069650, 0.170410, -1.581210, -0.487320, 1.091310, -0.496400, 2.193360, -0.603550, 1.440150, 
0.097650, -2.511310, 4.550080, -1.388550, 1.435120, 1.199500, -0.461890, 0.484030, -0.176650, -0.976540, 
0.632560, -3.084740, -1.671320, 0.096030, -3.138650, -1.714700, -0.958200, 1.263100, -0.636470, -0.763830, 
-0.895730, 0.729990, -1.431870, -1.182600, 0.026980, 0.118780, 1.654850, 0.241880, 0.532030, 0.509000, 
2.009740, -1.732390, 0.793080, 1.343890, 1.678890, -0.787540, -1.202860, 2.483030, -1.196970, -0.608070, 
1.386270, 0.356740, 1.100210, -0.221610, -0.674280, 0.216320, -0.189080, -1.239930, -0.229150, -1.265380, 
1.464220, 0.257400, -0.898340, 1.271250, 0.016680, -0.330210, -0.005800, -0.027570, 0.587020, 0.176610, 
2.000460, 0.166570, 3.174370, 0.083530, -0.442870, -0.922860, -0.731260, 0.140940, 0.266720, -0.466220, 
0.802510, 0.131910, 0.701600, 0.091920, 0.530890, -0.008780, 0.516260, 1.158420, 0.327330, 0.063990, 
0.216740, -0.680330, -0.917650, 0.132100, 0.243290, -0.174740, 0.887570, -0.682020, -0.376220, -0.628590, 
-0.410710, -0.791790, 0.223010, -0.680040, -0.740840, 0.916600, 0.557950, 0.624350, -0.041230, 
0.319790, -3.107100, 1.192090, -0.533870, 1.468770, 1.916650, 0.387850, 1.417940, 2.204750, 0.184260, 
-0.947800, 1.435580, -5.938100, -0.699570, -0.812270, -1.843070, 0.126440, 0.065510, 0.080300, -0.995150, 
-0.506290, -0.484040, -0.756990, -1.015510, 2.178900, 0.258400, 0.483520, -0.084570, -0.030110, 0.693360, 
0.024230, 0.412600, -0.104140, 1.262570, 0.637480, 0.673550, -1.440050, -2.282090, -0.838300, -0.034330, 
0.953970, 0.778340, -0.491390, -0.180040, -0.133580, -0.880480, 0.495060, -0.217870, 3.928700, -0.648470, 
-0.410990, -0.063000, 1.525510, -0.051420, -0.116180, -0.234010, 1.846250, -0.036870, 0.492510, -0.681390, 
1.309910, 0.397270, -1.365080, 0.174330, -1.135070, -1.097720, -0.287150, -1.279960, 0.357780, 0.231880, 
3.477120, 0.762170, 2.311180, 1.113210, 2.037950, -0.061130, 0.223250, 1.116740, -0.232210, -0.213780, 
-2.128530, -0.265280, 3.376680, 0.375300, -0.162180, -0.285680, 0.187680, -0.207680, -1.575710, -0.562830, 
-0.954400, -1.176150, -0.102910, -0.061040, 0.039700, -0.065770, -1.201760, -1.382900, 0.565690, 0.676160, 
-0.729880, 1.626880, 0.117070, 0.837350, 0.254230, 0.873390, -1.162390, 1.435000, -0.530600, 0.618500, 
-2.333020, 1.248970, -0.724020, -1.462440, 0.251760, 0.201540, -0.575800, -0.866010, 6.283600, -1.158210, 
1.820860, 1.019070, 2.074730, 0.131380, 0.375530, 0.733680, 0.316360, -0.700140, 1.423040, -1.795340, 
-0.743000, -0.497950, 0.578700, -0.889960, 0.372870, -0.725160, 7.224410, -0.708410, -0.476020, 2.765320, 
7.864660, 1.368230, -0.258450, -2.282670, 0.220120, 0.264130, -0.010410, 0.599710, -1.554640, -2.128010, 
0.409900, 0.879320, -0.174290, -7.583660, -0.671530, 0.888950, 0.882840, 0.289430, -0.789340, -1.383470, 
1.548750, -0.105100, 0.282020, 1.947460, 0.685250, 4.262760, 0.636230, -0.697210, 1.435860, 0.757780, 
0.699350, 1.572000, -0.236610, -8.637620, -0.057300, 1.115110, -0.616650, 2.383770, -0.476650, -0.494630, 
-0.482430, -1.161480, -4.890010, -1.129020, 0.826610, -0.788260, 0.208880, 3.779450, 1.466850, -0.422830, 
-0.415890, -0.024810, 0.982370, 0.089940, 0.314370, -0.121410, -0.325160, -2.310150, 2.269480, 0.343380, 
-0.477940, -0.793240, 0.995110, -4.011930, 0.373370, -0.431990, 1.685310, -0.277920, -1.433570, -0.638630, 
-0.956330, 0.319940, -0.437250, -0.228830, 0.076830, -0.975690, 0.356180, -1.229270, -0.271240, -0.218430, 
-0.651690, -0.412210, -0.211540, 0.267050, -0.804740, 1.245280, 0.143070, -0.549360, 0.673120, -1.046320, 
-0.400640, 0.595250, -0.622230, 1.239900, 1.433610, 0.949510, 4.654480, 0.442120, -1.252960, -0.928180, 
-1.317500, 2.421280, -0.403550, -1.234340, -0.968400, -1.596120, -1.060120, -1.219660, -1.415390, -2.019580, 
-0.839820, 0.288750, 0.942040, -4.538630, 0.949560, -6.393720, 0.440210, 0.344040, 0.128540, 4.038990, 
0.931770, -0.251460, -0.185500, -0.852090, 0.661810, -6.284270, -0.049130, -0.994340, 0.236210, -1.156560, 
0.019910, -0.206000, -2.673270, -0.807050, -0.548800, -0.431140, 0.639850, -0.085130, -1.363740, 0.110080, 
-1.331680, -0.249980, -0.248960, 0.916120, -0.822530, -1.587790, 0.177190, -0.550310, -1.120010, -0.034050, 
-1.143720, 0.118800, 0.154370, -1.238740, 0.081880, 0.309180, -1.078110, -0.707000, 8.423090, 
0.719550, -0.493270, 3.639200, -0.372900, -0.434570, 2.237490, -0.564540, 1.123950, 1.092660, 0.931790, 
0.304100, -0.917780, 1.559660, 1.166520, 0.789000, -1.090700, -0.247130, -1.213870, -0.165000, -0.104570, 
-0.896340, -1.752160, -1.557650, -0.130030, 1.168360, -0.264940, -0.574840, 1.304370, 0.926480, 0.279800, 
1.092800, 0.818540, 0.655060, 0.766620, 1.603290, -0.053490, -1.264610, 0.117870, 1.122140, -1.352140, 
2.698640, 0.747560, 0.825820, -0.927050, -1.675470, -1.263920, -0.063660, 0.094840, -0.053900, 0.530470, 
0.847020, -0.325460, -0.912010, 1.525550, 0.941960, 2.310460, -0.872110, 0.197180, -0.182560, 0.219330, 
-0.375680, 0.329760, -1.178440, -0.015920, -0.822490, 0.037550, -1.061090, 1.802490, 0.209320, -0.057500, 
0.665120, 0.569930, -0.291840, 2.486210, 1.677110, -1.841410, 1.187660, 1.375450, 1.918870, -0.995610, 
0.794310, -0.588430, -2.336430, -0.833250, -0.596010, -0.000770, -0.077450, -0.684350, 1.428050, 0.679950, 
0.242230, -1.019720, -0.205650, 0.814030, 1.157440, 0.162490, -1.107460, 1.433270, -0.020530, 0.588760, 
-0.672150, -0.259510, -0.800210, -0.084510, 0.418850, -0.816990, 0.305280, -1.024980, -0.101320, 1.798640, 
1.186620, -1.710000, -0.452410, 0.120610, 0.880800, 0.895320, 3.671470, -0.297520, -4.932030, 9.757650, 
-0.668960, -4.465950, -0.300300, 4.388690, 7.616000, -1.868170, -0.215730, 0.001740, 4.038690, 0.362280, 
0.501800, 0.927520, 12.375180, -1.181040, -2.900450, -0.193650, 2.787690, -0.833770, 1.188210, 0.845230, 
2.344460, -0.398270, 0.050460, 0.657170, -0.341480, -0.715810, 1.055860, -0.945910, -0.099720, -0.476620, 
-0.164680, 1.873050, 0.104600, 2.621620, -0.646150, -1.459130, -1.755400, -0.890740, -0.602970, 1.115510, 
-1.532690, -0.389860, 1.010550, 0.671100, -2.544830, -0.040400, -0.159130, 0.098220, 0.926970, -3.208110, 
-0.339000, 0.397690, -0.840680, -1.805330, 0.172390, -0.208660, -0.491680, -2.202570, 1.273340, -0.768190, 
0.184930, 0.471040, 0.559770, -10.360310, 0.111850, 1.063290, -0.839620, 0.536860, 0.520380, 1.135260, 
0.073580, 0.613990, 0.194590, -0.806170, 0.195810, -0.366390, -0.290690, -0.131510, -0.008200, -0.384270, 
-0.055070, -1.894610, 0.463050, -0.038750, -0.314880, 0.806220, 0.750590, 0.133150, 1.139510, 1.918050, 
-1.894550, -0.034410, 2.068490, 0.032830, 0.076450, -0.642790, 0.240050, -0.337750, 0.536440, 0.068290, 
-2.019030, 0.137420, -0.389040, -0.642250, -1.925780, 1.257510, -0.562640, 0.199490, -0.815180, -0.775060, 
-3.664260, -0.174110, 0.061740, 0.495700, -0.077630, -0.970730, -0.819940, 1.715990, -0.834560, -0.658360, 
0.875710, -0.019690, 1.020290, -0.624340, -0.031380, 0.444230, -0.247590, 0.218460, -1.606500, -0.001180, 
-0.017940, -0.740320, 0.133630, -0.397030, -0.302510, 1.184560, -0.452010, 0.134710, 0.149230, 0.888380, 
-0.234770, 0.517240, -3.676070, -2.089270, 0.149970, 0.926210, -0.513030, 0.747280, 0.985970, 0.964950, 
-0.893610, -0.852820, 0.482820, 0.981250, -0.538860, 0.931610, -0.703290, 0.437510, 0.883410, 0.090050, 
-0.496830, -0.857820, 0.345860, 4.297480, -0.485120, -0.311360, 0.336640, -0.061790, -0.075340, 0.110360, 
0.223370, -0.224950, -0.518990, 0.113400, -0.553230, 0.664520, -0.158660, -0.948320, 0.252790, 
0.465720, 0.608200, 0.706780, 0.314020, 0.183550, 0.465700, -0.125630, 0.374300, 0.042420, 0.040970, 
-1.413670, -0.342590, 0.949940, -0.139670, 2.765970, 0.566260, 0.653700, -0.706310, -1.298060, -0.493860, 
1.191100, -1.829740, -0.504200, -0.846010, 0.502590, -0.602210, -0.415040, -0.250880, 1.114500, -1.066530, 
-3.021180, -0.334550, -1.366390, 0.293270, 0.488010, -0.530120, 0.188600, -0.264430, 0.254980, -0.307940, 
0.501930, -3.501940, -0.351120, 1.108910, -0.703480, 0.203250, -0.648040, 0.038980, -1.388610, -1.755120, 
1.518160, -0.711130, -0.840820, -0.746700, -0.530930, -2.202670, -0.018570, 0.919660, -1.022600, -0.653460, 
0.923930, -1.813980, -1.848560, 0.136870, -1.449560, 0.150520, 1.824030, 0.496470, 0.496270, -0.927120, 
-0.490700, -4.184900, -0.520020, -0.571550, -2.634640, -0.144600, 0.007720, -0.213140, 0.036120, 0.684990, 
-0.758110, -0.700870, 0.528950, -0.576290, 2.834940, 0.170320, -1.076660, -1.437620, 0.927280, 1.498610, 
2.470690, 0.089030, 1.376440, 1.234280, -0.613730, -0.141480, 2.039010, 0.530290, 0.605710, -0.415310, 
0.294760, 1.224820, -1.258440, -0.465120, -0.326990, -1.235930, -0.722790, -0.587830, -0.651150, 0.272450, 
-4.523630, -0.597870, 1.331190, -0.275140, 0.995100, 1.087430, -0.695950, -0.230020, 1.065320, -0.763970, 
-0.376040, -0.646990, 1.992440, 4.906610, 16.077471, 1.691630, -0.095710, -1.001900, 1.710700, 1.419760, 
0.246870, 0.621920, 0.468460, -1.057690, 0.681270, 2.338100, 0.515870, -1.767780, -0.731940, 0.893830, 
-0.805890, 0.654500, 0.355960, 1.181550, 0.272860, -3.501200, -0.399770, -0.418840, 0.723670, -0.743130, 
-0.459370, -0.354450, 2.674290, -0.673950, 0.298580, -0.051080, 0.370400, -0.800750, 0.757010, 0.801600, 
0.706750, -1.474980, -1.161900, 0.965830, 3.215300, -0.520130, 0.167860, -1.151430, -1.762410, 6.367550, 
2.621420, 0.105740, 0.692140, 0.670810, -1.022710, -1.076290, -0.908710, -0.125290, -3.065330, -0.544250, 
-0.666600, 0.964450, -0.673920, 1.011270, 0.844750, 0.308390, 1.103200, 0.936440, -0.429110, -1.019870, 
2.411790, -0.980670, 1.877770, 1.177560, 0.301580, 0.139200, -1.305840, 1.989140, 0.057860, 0.444840, 
-0.898910, -0.513730, 0.378370, -0.119960, 1.656940, -0.220100, 0.867330, -0.903900, -1.151930, 1.428540, 
0.408820, 0.207250, -0.948640, 2.505020, -3.766890, 2.319150, -1.877120, 0.908140, -1.962750, -3.033310, 
-0.237650, 0.110920, -1.871790, 0.367560, -0.334650, -1.883840, 0.003560, 0.603470, 0.006180, -0.310130, 
1.149350, 0.735390, 0.844680, -0.502410, -1.470530, -0.368410, -0.881100, 1.098420, -0.400330, 0.784720, 
-1.211600, -0.896840, -0.667940, 0.956590, 0.514230, -0.793540, -0.797990, 0.082620, 0.455790, -1.886630, 
1.481050, -0.116720, -0.259680, -7.371580, 0.118730, 0.352960, 0.696330, 0.999280, 0.809540, -0.812150, 
1.637930, 1.124390, 2.276650, 2.158100, -2.097270, -0.389600, 0.943360, 0.082800, 0.464410, 0.159720, 
2.208430, 2.126940, 0.414840, 6.362880, 2.937340, 1.577200, 0.556520, 0.739240, 0.961000, 1.094210, 
1.373590, 2.427280, 1.606780, 1.373410, 1.570480, 0.290880, 2.643050, 1.743080, 0.304660, 0.864810, 
0.165070, 0.997860, 2.857060, 1.486410, 1.571980, 0.605360, 0.674770, 0.249230, 1.781010, 
0.285150, -0.348580, -1.296810, 0.038640, 0.651720, 0.732570, 0.656050, 1.354750, 0.579600, 0.409510, 
0.029770, 0.476510, 0.176070, -0.065240, -0.820530, 0.099710, 1.146400, -0.568260, 0.371000, 0.054930, 
-0.104190, -0.533450, -0.685530, 0.801340, 0.042550, -0.362070, -0.322230, 0.870130, -0.349090, 0.414440, 
1.123070, 0.214800, -0.528400, 0.417680, -0.252400, 1.112570, -0.507040, 0.388120, 1.130550, -0.839520, 
0.474570, 0.305290, -1.372320, -0.837040, -0.319450, -1.258960, 0.964270, 0.620190, -0.577490, 0.369860, 
0.743220, 1.488840, -0.294380, 0.869290, -1.426230, -1.243870, 0.024100, -0.202300, 0.398270, 2.136990, 
0.754030, -0.632380, 1.030570, -1.121670, 1.614370, -1.267620, -0.363100, -0.746580, 0.532730, 0.040890, 
0.208460, -0.231020, 0.106800, 0.659280, 0.622800, -0.854890, 1.887440, 0.492280, 0.186520, 0.056280, 
1.071040, 0.282920, 0.878370, -1.123340, 2.280120, 1.179640, 2.648760, -0.364100, 1.170890, 1.009250, 
1.148790, -0.222760, 0.884620, -1.051930, -1.040390, 0.445850, -0.792410, -0.277670, -0.362220, 0.465740, 
0.706450, 0.914720, -0.047080, 1.316680, 0.463720, 0.385210, -0.098600, -0.084600, 0.841670, -0.826270, 
-1.005960, -0.092340, -0.030070, 0.438950, -0.759400, -2.347190, -2.351690, 0.454460, 3.122160, -0.798360, 
-0.824540, 1.703180, -1.202390, -3.026480, -3.229420, 2.507450, 2.261020, -0.911910, -0.572320, -0.907270, 
1.259690, 0.250800, -0.973930, 0.779610, 2.741790, -1.215450, -3.967770, 0.151030, -2.200530, 0.380520, 
-0.840510, 1.060480, -0.300390, -0.816840, -0.674480, 0.282690, -0.456880, 1.143600, 0.507200, -0.259240, 
0.339160, -2.523680, 0.411160, 0.022830, 0.697470, -0.792670, 0.536880, 0.682700, -0.214240, -0.179230, 
0.349270, 0.071190, -1.093900, -0.117760, 1.083060, 0.990770, -0.977150, -0.175280, -1.247050, -0.239840, 
0.549100, 1.602650, 0.596340, 0.064850, -0.162090, 1.557110, 0.190120, 1.428920, -1.164730, 1.871520, 
0.335570, -0.590070, -0.299310, 1.261390, -0.437490, 0.584990, -0.738570, 1.060550, -1.342640, -1.463390, 
0.848390, 1.664460, 0.967000, 0.900660, 0.625500, 0.420860, 0.986780, -3.807450, 0.343720, 0.655860, 
-0.634650, -1.191220, 1.577140, 1.016020, 0.501990, 0.631940, -0.612340, 0.459870, -3.500520, 1.700590, 
0.495070, -0.381790, -0.301720, -1.554320, -0.535320, -1.443460, 0.108690, 0.210290, -0.461360, 0.014940, 
1.938870, 0.008570, 1.067640, 0.281390, -0.934330, 2.926930, 0.522900, -0.877320, 3.633070, 0.910520, 
1.223990, -2.844110, -0.815120, -0.191410, 0.304220, -1.012970, -0.011480, 0.520590, 2.750400, -1.085510, 
-0.025880, -0.594990, 0.780870, 0.890370, -0.153900, 0.848980, 0.379820, 0.497960, -0.545700, 1.130940, 
0.649360, -0.683030, 1.121580, 4.872550, -0.665960, -0.686110, 0.570270, -0.473530, -0.622600, 2.740270, 
-0.120270, 1.114290, 4.473330, 1.146640, -0.806560, 0.525610, 0.840710, 0.193700, -0.204970, -0.353100, 
-0.248220, -0.242470, -0.941790, 0.128150, -0.743970, 0.507600, 0.732660, 0.381840, 0.801690, 0.014020, 
0.942040, 0.139660, -0.150910, -0.744380, -1.156300, -0.724210, -0.305920, -0.040410, 0.642780, -0.112380, 
0.393430, 0.647920, 0.511470, -0.722100, -1.332760, -0.498280, -0.477780, -0.171530, -0.773410, 
0.522750, 0.802640, -0.284330, -0.405120, -0.160810, 1.001880, -0.646040, -0.500520, 2.101440, -0.873290, 
-1.695810, -1.779690, -0.329450, -0.145160, -0.682110, -0.455820, 0.472420, -0.351250, 0.168650, -0.474740, 
1.184360, 0.319410, 4.505950, 0.296640, -1.228360, -0.973770, -1.301420, 0.337420, 0.176270, 0.162590, 
0.548880, -0.968200, -0.062030, 0.679640, -1.231310, -0.414390, 4.588570, 0.246340, 1.216520, -0.777130, 
0.357040, 1.218640, 0.019180, 0.851080, 0.295390, 1.530720, 0.404800, -1.102810, -0.825140, -0.252900, 
-0.064150, 1.209740, -1.034180, -0.039020, -0.769280, -0.355810, -0.462140, -0.040630, -0.860960, 0.223700, 
0.872500, -0.945570, -1.605040, 0.093040, -0.729560, 0.555860, 0.323640, 2.251810, 0.328300, 0.231040, 
0.323100, 1.103140, 1.595100, 0.949770, 0.300420, -0.410770, -0.112750, -0.998250, 1.054380, 0.572960, 
-1.150610, -1.370100, -1.423530, -0.475870, 1.577110, -0.711710, 0.528630, -0.617950, 0.177910, -0.071050, 
0.131610, 0.059470, 0.738960, 0.059330, -0.961190, 0.635320, -0.086730, -1.582620, -0.394860, 0.004280, 
0.154450, -1.537930, -2.453200, -0.905880, 0.417260, -1.190590, 0.069350, 1.008040, 0.016970, 0.151250, 
1.233240, -1.129620, 1.168680, 0.108120, 1.747360, -0.677560, -0.800100, -0.271870, 0.064500, -0.520970, 
0.124230, 0.063490, 1.283140, 0.990560, -0.743420, -0.435580, -1.035230, 2.131290, -4.457620, 0.822250, 
2.936140, -0.977080, -2.349030, 1.404800, -0.844570, -0.308070, -0.353250, 1.150030, 0.161230, 0.689660, 
-1.500530, 0.488560, 0.201520, 3.205930, -0.941460, 0.233440, -0.682020, -0.214360, 0.288390, 0.077430, 
-0.925680, -1.946890, 0.572390, -0.707570, 0.203660, -0.415390, -0.544370, -2.086190, 1.349570, 0.365960, 
6.508290, -1.187900, -3.515300, 0.056810, -1.476720, -0.017010, 1.011870, -3.679730, 0.720790, -0.032350, 
-0.416040, 0.536370, -1.728700, 1.277970, -1.112390, -1.435340, 0.292460, 0.313410, -0.608390, 0.276070, 
0.526590, -0.548440, -2.728550, 1.342140, 0.092220, -1.201850, 0.651600, 1.359410, -1.066190, -1.039690, 
-0.575200, 0.115280, -0.157510, 2.048830, -1.206700, 0.851930, -0.079580, -0.317280, -0.129210, -0.516400, 
-1.897100, 0.407460, 0.061200, 1.136530, -0.275300, -0.821760, -0.591370, -0.577830, -0.206760, 0.379170, 
-0.422400, 1.290600, -0.031290, 0.731510, 1.274810, 2.455880, 0.117010, 0.061100, 1.071050, -0.656420, 
0.577600, 0.439830, 0.039050, -0.489510, 0.073570, 2.938520, 0.799440, 0.727490, -0.972490, -0.308330, 
1.930750, 2.335190, -1.343320, 0.271660, -0.730850, -0.071110, 1.734660, -1.491010, 0.450260, -1.084500, 
-0.320380, 0.104690, -0.767320, 1.212780, -1.696270, -0.342150, 0.921440, 0.417880, -0.610100, 0.035180, 
0.341820, 0.259180, -1.075290, -0.462490, 0.231410, -2.368170, 0.692420, 1.145220, 0.797620, -0.460880, 
1.433270, 0.750050, 0.922750, 0.501120, -0.851940, 3.004620, -0.149790, -0.450940, 0.437430, 2.231750, 
0.354510, 1.024370, -0.473350, 0.960430, 1.113770, 1.086060, 1.018640, 0.473620, 0.567640, 0.119010, 
-0.408010, -0.144100, -0.222920, 3.953910, 0.298520, -0.405610, -0.729150, 0.029880, -0.057920, -0.304570, 
0.284950, 0.133150, 0.976740, 0.402530, -0.682760, -0.183130, -0.009600, -0.710080, 0.474870, 
0.166270, -0.370190, -0.590220, 1.240470, 1.085240, 1.588980, 0.490070, -1.834100, -0.592130, -0.642210, 
0.631770, 1.896700, 0.049570, 1.388730, -1.802690, 0.877700, 2.660230, -0.051910, 1.776520, 0.862440, 
0.255790, 0.158460, 1.107280, -0.764320, 1.097370, -0.854040, -0.353090, 0.165220, 1.072200, 0.633730, 
1.602300, 0.211330, -0.989760, 4.335900, 0.238400, 0.625970, 0.846910, 0.846410, -0.745960, -0.803360, 
-1.157060, 0.637950, 1.507850, -0.674240, -0.210070, 1.728990, -0.396980, 0.137410, 0.552100, 4.706300, 
-0.117010, -0.192280, 0.326570, 1.005670, 0.044700, -1.687180, 1.857290, 0.184520, -0.194610, 0.567210, 
0.022000, 0.817990, 1.345440, 1.176060, -1.225450, -0.508020, 0.280220, 0.798260, 2.660150, -0.690160, 
-0.617550, -2.766960, 1.231260, -1.115560, -0.497360, 1.374630, 1.207950, 0.101920, -0.801790, 2.238070, 
0.943510, -0.290470, 0.576120, 0.240390, 0.567920, 3.623930, 0.049580, 1.864260, 1.341240, 0.615410, 
1.668010, 0.993440, 0.474510, -1.961690, -0.289460, 1.289270, 0.375540, -1.312250, 1.357780, 0.318630, 
0.145330, 0.479210, 2.953960, 0.785560, 0.937920, -0.065510, -0.835990, 0.735490, 0.412430, 0.228340, 
1.076090, 0.097880, -0.329840, 2.004320, 0.097950, -2.030440, 2.213070, -0.074010, 2.230670, 0.477780, 
-0.697020, 1.303830, -0.440060, -2.194480, 1.678250, 1.025100, 0.145650, 0.198710, 0.479300, -1.422100, 
0.895440, 1.877090, 1.686910, 0.623700, 0.821600, -0.524030, 0.870290, -0.902990, -2.488150, -2.232430, 
-1.551880, -0.037670, 0.714760, 0.213310, 0.930770, -2.825750, 0.674150, 2.185210, 0.723650, -0.013230, 
2.261170, -0.767090, -0.022750, -0.451010, 0.906780, 0.119990, 0.593960, 1.263110, 0.609040, 1.048000, 
-0.360430, 0.045610, 0.194360, -0.341810, 1.158350, -0.511680, -2.383440, 0.741010, -0.851250, -0.132020, 
-3.189030, 1.045040, -0.531270, -0.733100, -0.518120, -1.015500, 0.518550, -0.323400, 0.773010, -1.012310, 
-0.760240, 0.612980, -0.081260, 1.286190, 0.228530, -0.243860, -1.058620, -0.365250, 0.273000, -3.360980, 
1.614380, -2.056880, -0.663370, -0.005150, 0.822510, 0.402240, 0.715610, -1.506630, -0.296890, 1.123590, 
0.643400, -1.590200, -1.011930, -0.168560, -0.428060, 2.644170, 1.586580, 0.154390, 1.165640, 0.619970, 
0.058750, -1.001200, 1.729030, -0.323860, -0.292170, -0.921610, -1.329030, -0.040980, 0.218450, -1.413140, 
-0.015500, 1.313370, -3.089040, 0.440040, -0.402460, -0.577540, 2.086670, -0.027510, -0.670260, -0.383360, 
0.033030, -0.394590, -1.449790, 3.606890, -0.138980, 0.823610, -0.848440, 1.938070, 0.255480, -0.074050, 
0.742700, 1.350720, 0.997420, 0.855010, 0.869890, -1.028140, 0.614110, -0.035630, 0.459030, -1.184490, 
-0.236200, 0.515660, 1.573680, 9.850500, 0.086070, -0.702020, -1.088770, 1.710750, -0.011580, -1.020580, 
0.301490, 1.007620, 0.545390, -0.042020, -0.318980, -2.449860, 0.025550, -2.391740, -0.506280, 0.925670, 
0.452430, -0.026340, 0.480410, -0.469010, 0.980150, -0.756200, -0.141460, -0.054280, -0.001080, -0.190820, 
0.517730, -0.608550, -0.479110, -0.483480, 0.876410, 0.161070, -0.013110, -0.777200, 0.427310, -0.168290, 
-0.908860, -0.888620, 1.060590, 0.749420, -0.085960, 1.124380, -0.783810, 1.031800, -0.921350, 
1.320010, -1.350160, -0.699830, -1.681990, 0.498720, 0.992230, -0.529370, 0.856930, -0.453450, 0.432000, 
-1.116590, -0.512230, 0.149950, -0.073100, -0.048150, -0.723410, -1.523360, -0.283750, 0.774430, 0.294430, 
-1.618550, -0.695480, -1.440940, -0.900770, 0.732940, 1.207920, 0.063810, -0.443730, -0.030040, 0.847460, 
1.991090, -0.242460, -0.240110, -0.427960, -0.527150, -0.111390, -2.321870, 0.823790, -0.410700, -0.679500, 
1.132530, -1.025090, -1.296360, -2.835580, -1.238930, -1.064050, 0.538230, 0.862010, 0.391240, 0.691160, 
0.037400, -1.371210, -0.132490, 2.473600, 1.316220, 0.154270, -1.112620, -1.225260, -0.119120, -0.677890, 
0.383130, 2.298400, -0.877320, 0.111540, -0.217050, -0.562960, -6.949080, -0.330040, -1.050610, -0.340350, 
2.394780, -0.123760, 3.179400, -0.367410, -1.085500, 1.048470, 0.359970, -1.223770, -0.763590, -4.185190, 
0.633900, 0.411080, 2.265020, -0.837840, -0.952640, -0.256080, -2.016140, -0.967550, 0.029630, -3.773080, 
0.963020, -0.466290, 0.182640, 2.176940, 0.195520, 0.950420, -0.631990, 0.710560, 0.445640, -1.167810, 
-0.071630, 0.564940, 0.575340, -0.875630, 0.084490, 1.506320, -0.286330, -0.026060, -1.032300, 0.409880, 
-0.112950, 0.337680, -0.623890, 1.358500, 4.382830, 0.525480, 0.686040, 1.008830, -6.248000, 0.137300, 
0.411480, -0.759460, -1.661880, 0.341580, 3.222140, 2.164460, 0.237750, 1.355750, -1.094240, -1.249060, 
0.310630, 0.591530, 1.400900, 0.873380, -1.278230, -58.710331, 2.137510, 1.754110, -0.825420, -0.666010, 
0.671660, 2.651220, 0.695000, -1.728640, -0.795750, -2.750280, -1.432650, 3.064890, 3.527440, 2.107290, 
-1.081670, 1.512790, -1.840430, 2.573020, 2.751980, -1.812770, 0.582890, -1.064260, -0.587710, -0.507080, 
-3.405370, -0.403460, -0.087550, -0.218800, 0.312380, -0.148140, -1.596150, 4.467850, -0.144620, 0.895160, 
1.108170, -1.019270, 0.136400, 0.626900, 1.227230, -0.103770, -0.751870, 0.643150, 1.357500, -1.593330, 
1.578770, -3.888430, -0.306880, 0.910760, -0.613920, 0.600510, 0.351910, -3.317750, 0.872160, 1.591190, 
-0.586250, -0.057180, -0.720150, 0.709570, -0.999960, 0.163780, -0.915350, 1.588260, 0.631530, -0.215610, 
-0.968860, -0.448940, -0.380870, -0.080200, 2.897460, -0.013520, -0.296230, -0.755660, 0.730560, 0.370940, 
0.644370, 0.036740, 0.191760, -0.748350, 0.008150, -0.575910, 1.477130, -0.837480, -1.237310, -0.802690, 
-1.130320, 0.588380, -4.037360, 1.558630, 2.034750, 1.120530, -0.660640, -1.174620, -0.722130, 0.953550, 
0.366400, 0.370610, -0.179380, -0.970770, 0.812470, 2.622410, 0.361300, 1.758150, -0.167230, 0.964250, 
-2.446350, 0.208390, 1.398690, -0.628540, -0.094300, -0.799990, 0.147770, -1.008620, -0.016610, -0.365810, 
-3.114430, 0.724430, 0.638540, -0.460780, 0.969060, -0.750870, -0.403870, 1.129280, -0.635920, 1.825080, 
2.292770, 0.270990, -0.971560, -0.114060, 1.421300, -0.609360, -0.030510, -0.228960, -0.059270, -1.846110, 
-1.068340, -1.865710, -0.089340, -1.755110, -1.506860, -0.232340, 0.217950, 0.000910, -0.457070, -0.229450, 
-0.169030, -0.586160, -1.581920, -0.701310, -0.408470, 0.273720, -1.429890, -1.621430, -0.704850, -0.303060, 
-1.207070, -0.770910, -1.620610, -0.216440, -0.416270, -0.009650, -1.443950, 0.112560, -0.471360, 
0.328690, -0.936430, -0.169990, -0.005400, 0.158100, 0.284660, -0.223620, -0.155590, 0.132880, 0.833270, 
0.321330, -0.805450, -1.420420, -0.658350, 0.306860, -1.067820, -0.476020, -0.041490, 1.801700, -0.497350, 
0.352840, -0.106280, -0.172130, -0.099620, -1.188840, 0.711080, 0.321350, -0.739650, 0.643070, -1.354180, 
-0.833680, -1.903250, -0.555670, -0.770660, -0.131530, 0.156550, 0.259050, -0.717730, -0.584880, 0.245750, 
1.022170, -1.059800, -0.911910, -0.328870, 1.189470, 0.497670, -0.297750, 0.831040, 0.388990, -0.180090, 
1.305440, -0.174840, 0.411330, -0.632640, -0.958830, 0.884320, -0.723430, -0.684220, 0.783920, 0.159340, 
-0.329430, -1.404590, 0.155120, 1.736350, -0.766970, -1.225750, -0.682770, 0.564830, 1.551430, 2.599030, 
0.218870, 0.039200, -1.825640, 0.817430, -1.104900, -1.543610, 0.009550, 0.643830, -0.305610, 0.485450, 
-0.091480, 0.311560, -0.943260, -0.274750, -0.115560, -1.651540, -1.419890, -0.492700, -0.239710, -0.075760, 
-0.072810, -1.714140, 0.135230, 2.292180, -0.368500, -0.703810, -0.116450, -0.131630, 0.344530, -0.946340, 
-0.356380, 0.356120, -0.363040, -1.310390, 0.527650, 0.276840, 0.643540, -0.595410, -1.076320, 0.535320, 
2.394200, -0.709140, 0.187740, 0.140200, -0.788220, 0.437630, 3.705610, 1.196730, -1.991570, 0.602440, 
2.814410, -2.350370, 2.438510, 0.373970, 1.234670, -0.330100, -1.161060, -0.135780, -0.231230, 1.070220, 
-0.707210, -0.051600, 5.474750, -0.447210, -2.056470, 3.313010, 4.663240, -1.488430, -0.047380, -0.282090, 
1.260240, -0.538420, -0.095300, 0.144650, -0.338200, -0.577450, -0.708570, 1.621710, 2.099390, -0.210850, 
-0.170000, -0.017940, 0.467450, -0.318270, -1.159450, 2.070560, 1.876940, 0.366870, -0.215820, 0.357340, 
-0.054370, -2.278030, 0.420180, 0.131550, -2.388620, 1.088840, -1.186770, -1.075880, -1.075450, 0.938300, 
0.315960, 0.045220, 0.628910, -0.378780, -0.765230, -1.342480, 0.211270, -1.826820, 1.451770, -0.318860, 
-0.210050, 0.172560, 2.711970, -0.431770, -0.312560, 1.218020, 0.260100, -1.304160, -0.937290, 0.666300, 
0.834600, -1.744040, -1.157460, 0.314360, 0.973970, -1.978470, -0.799380, 0.004610, 0.860180, -0.929810, 
-0.810450, -0.147680, -0.997500, 0.987320, -0.393020, -0.613210, 0.268440, -0.879290, -0.664190, -0.803640, 
-1.269710, -0.967740, -0.882030, -1.264840, -1.154360, 0.349110, 0.676580, 0.481220, -0.392790, -0.570410, 
-0.362320, -0.689550, 0.626510, -0.023930, 0.508470, 0.975930, -0.121610, -0.003960, 1.736310, -0.359610, 
-1.244290, -0.398430, -0.913990, -1.440880, 0.527150, -0.909900, -0.468590, -0.090280, 1.895280, -0.274750, 
-0.526220, -0.270040, -0.874060, -0.384500, -1.543300, 0.528800, -1.232400, -0.284990, 1.006200, 0.598840, 
-2.006950, -0.291480, -1.752810, 11.064460, 0.461250, 2.595660, 0.516020, -0.174300, -0.205460, -0.328360, 
0.323580, 0.166200, -3.181490, -0.143600, 0.402070, 0.409520, 0.882450, 0.487540, 0.468160, -1.512970, 
0.373080, 0.145110, -0.435620, -1.015050, -0.765290, -0.494060, -0.756530, 0.818370, -0.734810, -1.327040, 
0.387280, 0.433100, -0.090720, 0.910680, 0.835240, -0.905620, 0.639860, -0.369890, 0.011010, 0.076260, 
-1.966500, 0.807380, -0.114730, -0.244250, -0.152260, -0.621090, -0.466850, 0.025790, -1.127220, 
1.105310, 0.475520, -0.044010, -0.236410, 0.661440, -0.922980, 0.807800, 1.294780, -4.157050, -1.062000, 
-1.189820, 0.109240, -0.579740, 0.673420, -0.654930, -1.175580, -1.854310, 0.217960, -1.948340, -0.425390, 
0.136960, 0.772440, 1.926500, -0.473520, -0.155980, 0.609540, 0.435100, 0.242950, 1.299900, -0.215790, 
-0.684280, 0.878100, 2.566410, -0.086840, 1.499700, 0.232870, 0.321360, 0.467670, -0.573850, -0.898800, 
0.584140, -0.181400, -0.617790, -0.086820, 0.456300, -0.226010, -0.362550, -2.418800, 0.665810, 1.837680, 
-0.755740, -0.663840, 0.062600, -0.253360, 1.082450, -0.622620, 2.125150, -0.623050, 0.746760, -0.359380, 
-2.150860, -0.231170, -2.314430, 1.412950, 0.057210, 0.137380, 0.646390, -1.183800, 0.078190, 0.339670, 
0.725720, -0.508030, 3.805610, 0.612210, 1.020150, -0.343530, -0.984740, -1.011290, -1.773110, 0.005550, 
-1.266770, 1.080570, 1.707730, 0.176530, -1.005130, -0.422560, 0.558910, -0.131940, 0.252080, -0.686740, 
-0.042690, -0.224240, -1.060050, -0.402420, 0.495140, 0.224910, 0.224450, 2.123040, 0.880240, -0.592950, 
-1.323500, 0.388480, 0.685730, -0.665690, -0.545150, 0.077730, 0.230270, 0.047510, -1.725550, 1.004120, 
-4.709590, 4.100900, 0.949360, -4.158320, 1.237760, 13.354160, 3.293370, 8.039240, -2.818260, 2.053750, 
-3.296640, -6.240270, -0.335020, 16.197420, 3.673730, -2.536790, -0.356140, -1.371650, -0.090460, 1.445300, 
-1.643230, -7.102020, -4.587770, -3.313270, -1.776210, 0.368770, -11.441010, -1.402560, -0.232830, 1.054410, 
-1.735760, 1.192740, 0.700320, 1.108770, -2.273950, 1.054710, 0.816800, 0.501220, 0.797870, 0.010800, 
-0.486160, 0.485180, -0.536290, 0.598560, -0.790500, -0.342750, 1.163850, 0.579720, 0.027000, -1.403070, 
-0.063680, 0.184200, -0.228770, 4.991540, -1.305100, -0.054840, -0.489760, -0.165170, 0.198930, 0.124100, 
-0.066740, 1.521890, 0.581410, 0.171880, -0.567250, 0.088940, 0.990030, 0.210360, -0.480950, -0.189550, 
0.229180, 0.767780, -2.689010, -1.499340, -0.350110, -0.829930, -0.817950, 0.266960, 0.835070, -0.049660, 
-1.029020, 1.187110, -0.315410, 0.376830, 0.048990, -0.544990, -0.574950, 0.161590, -0.060930, -1.139570, 
-0.957560, 0.300350, 0.625560, -0.092090, 0.429450, -1.883540, 0.300110, -0.541660, -1.317020, -0.204190, 
-2.959250, 0.271850, -0.228330, 1.049530, 1.729690, 1.098280, 1.980770, -0.081700, -1.439390, -1.236370, 
0.793050, -0.496700, 0.185570, -0.946810, 0.086550, -1.552820, -0.808870, 1.115750, -0.891130, 2.487910, 
1.061780, -0.650410, -1.400570, -0.430970, -1.087590, 1.007380, 0.186060, -0.530910, -0.650500, -0.748290, 
-1.306630, -0.071350, 0.804830, 0.080530, -0.492420, 0.664970, -0.584480, -0.571010, 0.116940, -1.418520, 
-0.481940, -0.253140, -0.823410, -1.475390, 0.083920, 2.970790, 1.197420, -0.600140, 0.078340, -0.889180, 
-0.063960, 0.469290, -0.887130, 0.192160, 0.313800, -0.577250, 0.318520, -0.231070, -0.483890, -0.937310, 
0.080580, -0.551020, -0.862410, -0.417330, 0.380420, -0.819620, -0.464110, 0.321260, 0.297840, 2.577470, 
-0.100610, 0.720770, -0.685780, -0.496030, -0.174260, -0.276010, -0.277240, 0.521800, -1.250220, -0.344130, 
-0.912130, 0.799940, -0.733160, -0.788720, 0.700160, 0.720480, 0.572550, -0.288910, 2.579600, 
1.224830, 0.472160, 0.691840, 1.409460, -1.263790, -0.279630, 0.283520, 1.061250, 0.274400, -0.223720, 
-0.336730, -0.224070, 0.089020, 0.857770, 0.974000, 0.314560, -1.596920, -0.037510, -1.513420, -0.191640, 
-0.274500, 0.252650, 0.375740, 1.249860, -0.234160, -1.041020, 0.190520, 0.513540, 0.906140, -0.955240, 
-0.566970, 0.446420, -1.265990, -0.100660, 1.922150, 0.396630, -0.753670, -0.684090, -0.370980, 1.131880, 
0.303720, -1.297010, 0.124750, 1.028780, -0.130580, -1.939840, -0.541840, 1.001240, -2.007140, 0.049550, 
0.145910, 0.135960, 2.668590, -2.197590, -0.195970, -0.224620, 0.076780, 1.797480, -0.012210, 0.500590, 
-0.276200, 0.600990, -1.033170, -0.956180, -2.967070, -0.683410, 1.123760, -0.525800, -0.369050, -0.045130, 
0.577510, -0.821000, 0.861580, -0.474180, 0.777710, -0.170130, 0.640810, -0.148940, -0.367430, 0.063800, 
-0.955810, 0.718220, 0.261140, -0.288480, 0.434820, 1.659240, 0.615320, -0.441320, -0.840810, 0.996840, 
-0.373560, 0.393550, 0.063960, -4.539550, -0.402160, -0.078980, -1.214940, -0.368030, 0.911660, 1.523440, 
-0.478110, -1.068160, -2.350690, 0.121370, 0.425130, 0.353120, 0.127660, -0.474550, -1.471560, -0.897380, 
-0.949840, -1.314710, 0.014300, 1.148620, 2.256330, -0.799210, -2.288430, 0.182890, -0.546520, -1.067130, 
-3.131770, 0.281790, -1.781300, -1.209720, -1.856460, 0.905160, -0.196820, 1.163790, -0.425920, 0.854160, 
3.136390, -0.919600, -4.832990, 0.354110, 0.367070, -0.077790, -0.461990, 1.635520, -1.765670, 0.746150, 
-2.012540, 1.630970, 1.058870, 1.628920, 0.364370, 0.066840, -1.385250, 0.139160, -0.411950, 0.302890, 
0.437230, 0.658000, 0.226530, -1.975720, -0.477980, -0.721130, 0.802710, 0.329420, -0.174540, -0.613930, 
1.201390, 1.223290, -3.106390, 0.760090, 0.863180, 0.871870, 0.097060, 0.786260, 0.484800, 0.548880, 
1.391360, 0.106110, -0.371260, -0.183760, 1.038740, 0.713430, 1.726670, 0.040020, -0.014900, -0.038680, 
1.233260, -0.901700, 1.133930, 1.095290, -0.545060, -0.354140, 1.371130, -0.703550, 0.046840, 0.552580, 
0.204840, 0.121210, -1.233230, -1.230610, 0.288060, 0.461900, 0.362480, 0.779850, 0.241630, -2.455510, 
-0.025440, -1.690430, 0.837130, 0.295360, 0.370400, 1.968320, 2.588340, 1.157010, 0.483410, 0.797130, 
-1.165720, 0.366070, 0.927320, -0.030820, 0.673690, -1.673530, -3.823720, 1.763660, -1.076110, -1.026800, 
-0.204640, -0.287680, -0.221540, 1.742010, -3.061820, 0.315460, -1.735230, 0.208700, -0.519970, -0.017060, 
-0.309280, 0.072700, -0.523900, -0.139420, -0.434660, 0.508820, 0.864250, 2.833740, -0.793840, 0.857500, 
-0.313720, 0.340050, 1.101520, 1.662060, 0.205420, -0.082800, 0.440230, 0.028480, -0.776220, -0.377150, 
0.367690, 0.945900, -0.807840, 0.743110, 0.074200, 0.341950, -0.288980, -1.220720, 0.515880, -0.512060, 
0.428320, 0.086750, 1.156030, -0.201760, -2.326190, -0.153390, 0.146620, 0.585040, 0.426990, 1.999280, 
0.241990, 0.076780, 0.045000, 0.952490, 0.706520, 0.156740, 0.766070, -0.454450, 0.910240, 0.381190, 
-0.287850, -0.380840, -0.248940, 0.405470, 0.609810, -0.552950, 0.385230, -0.446600, 0.419370, 0.486100, 
0.845770, -0.608290, -0.269550, 0.166580, -0.828600, -0.174060, 0.685840, 0.215790, 0.384350, 
0.348330, 2.475460, 0.519190, -0.336010, -0.340040, -0.990890, -0.896370, 0.503630, 0.734700, 0.680190, 
0.407670, -0.365430, 0.278460, 0.669000, 0.554830, -0.643080, 0.865690, -0.447530, 1.062490, -0.126080, 
-4.896760, -0.824840, 0.078540, 1.174280, 0.696910, 0.576690, -1.325390, 0.363170, 0.180690, 1.237250, 
0.692230, 0.692550, 1.539780, -1.003550, -1.088210, -0.493610, 1.464930, 0.108030, 0.658680, -0.131960, 
1.174510, -0.277340, 2.193810, -6.378090, 0.231160, -0.121030, -1.028370, -0.839960, -0.297560, 0.466770, 
1.102510, 0.697480, -0.268560, -0.244140, 1.120610, -0.238010, -0.424850, 0.731770, 1.050170, -1.177700, 
-0.835780, 0.039080, -0.502880, -0.688260, 0.608100, 0.960340, -0.624780, -0.299630, -0.253260, -0.990090, 
0.302170, 0.464310, -0.929630, 0.314300, 1.602930, 1.443160, 0.111260, 0.331780, 0.593050, 0.602490, 
0.154040, -0.386350, -0.336070, 0.665200, 0.204050, -0.466600, 0.713870, 1.257050, 1.250270, -7.981670, 
0.070820, -0.427260, -0.336880, -0.055660, -0.718000, 1.671090, -1.021570, 0.317020, 0.468890, 0.161430, 
-0.485170, -0.699060, 0.915240, 0.516600, 0.526160, 0.360910, 1.145370, -0.414050, 1.012610, 0.540550, 
0.121030, -0.459010, -14.878770, 2.846640, -0.073540, 1.223310, 1.553580, -2.420480, -2.537650, 0.843430, 
2.061920, -1.493190, 1.763140, -0.289770, -0.205950, -0.905260, -0.447570, 7.780740, 0.574560, 0.076680, 
11.226670, 0.425750, 0.649520, 1.166310, 0.277330, 1.925670, 0.220150, 1.689010, 0.527710, -0.363040, 
1.715660, -1.358520, 0.535400, -0.722790, -0.290380, -0.535380, -0.039810, -0.390730, 0.452560, 0.162510, 
0.461740, -0.276170, 1.484540, 2.408950, -0.182110, -2.043990, -0.818320, 0.289150, -9.853600, 8.802460, 
0.354160, -0.537210, 0.805200, 3.216860, 1.186120, -1.042470, -0.184910, -0.537210, 1.388660, -0.277750, 
0.803540, -0.970490, 0.602190, 0.743930, 0.062210, 0.570870, -0.206030, -0.607740, -0.258890, 0.484190, 
1.445470, -0.215190, 0.513040, -0.796590, 0.410420, 0.842820, -0.112990, -1.016120, 0.702330, 0.414290, 
0.859960, 0.840630, 0.655210, -1.624240, 0.224600, -0.368990, 1.264930, -0.012910, 0.186880, 0.743720, 
0.713880, 1.837470, 0.987610, -0.195140, -2.829860, 0.489720, -0.501440, 1.327820, 0.141590, 2.974500, 
0.424840, -0.422210, 0.875020, -0.543300, -0.770060, 0.624850, 0.847060, 1.136190, 2.318730, 0.348360, 
1.124330, 1.007180, 2.898780, 3.079920, 3.408740, -0.336730, -0.048720, -2.884950, 0.967480, -6.124410, 
1.510190, -0.134180, 0.314420, 1.491640, 1.020700, 0.590860, -0.781300, 0.354970, -0.471550, -1.696180, 
1.908550, 0.311530, 0.163250, 0.074800, 2.011350, 0.346430, 2.887370, 0.769110, -0.123720, -0.187010, 
-4.200100, 2.270880, -2.655320, 22.622690, -1.145940, 0.032690, -1.054240, -0.499430, -3.115800, 0.988750, 
2.953890, -7.867470, -0.593730, 0.677120, 0.411210, -0.589760, 0.384460, -0.075620, -0.390970, -0.443200, 
0.355210, -1.224780, -0.008260, 0.560990, -0.092660, -0.847750, -0.270420, -0.129640, -0.162740, -1.546150, 
0.684560, -1.018790, -0.267730, -1.074070, -1.046430, -0.732420, -1.334700, 0.671320, -1.066460, -0.268390, 
-3.489510, -0.485230, 0.458440, -0.725500, -0.220990, -1.751750, -0.307310, -0.190040, -1.060340, 
0.473030, 0.895560, 5.669650, 0.529470, -1.094260, -0.381030, -1.009010, 0.085630, 1.230180, -0.146800, 
-0.603550, -0.304550, 0.461750, -0.847530, -1.613910, 0.751420, -0.850780, -0.882070, -0.524170, 1.960130, 
-0.053050, -0.448300, -1.560740, -0.375160, 0.193790, -0.609830, 0.018590, -0.255930, -0.223150, 0.429270, 
-2.406360, 0.497110, 1.242700, -1.134290, 0.653640, 0.902160, 0.421420, 3.084670, 0.598540, -0.216150, 
-0.734710, -0.278340, 0.587770, -0.996310, -0.790030, -3.919880, 1.752010, 0.865440, 0.745530, -0.695560, 
1.307420, 0.537990, 1.013520, 0.067600, 0.562980, -0.129370, -1.202860, -0.389460, 0.816150, -0.305060, 
0.403930, 0.287040, 0.300530, 1.261460, -0.515890, -0.428980, 0.549430, -0.280170, -2.112590, 0.235160, 
-0.087310, -0.040170, -0.427070, -0.317770, 0.139810, -1.506750, -1.395190, 2.362500, 0.475140, 2.256830, 
1.636900, 0.905610, 2.498920, 1.833150, -1.318600, -0.171990, -2.475650, -2.937240, -2.520370, -0.735400, 
-0.259360, -3.048890, 1.419460, -0.226170, -0.476270, -1.653650, 0.178130, -1.001990, -0.760520, -1.894700, 
1.280070, 2.857430, -1.335120, -0.104360, -0.118720, -0.979770, 0.634640, 0.928060, -2.291950, -0.039200, 
0.067110, -1.067000, -0.662310, -0.450500, -0.080790, -1.537420, -4.203260, -2.596070, 6.706440, -4.859880, 
-0.693040, 3.216160, -0.802370, -7.953380, -4.476840, 6.237000, 0.134070, -1.043290, 0.244020, -3.164990, 
-8.424620, 0.395800, -2.275780, 1.617740, 1.960450, -5.393200, -4.757110, 1.127170, -0.413450, -4.324890, 
0.647400, -0.359960, 0.050200, -0.926360, -0.398370, 0.400480, -0.407460, 3.523930, -0.136730, 0.349320, 
0.675180, 0.115720, -0.903770, 0.825370, -0.114480, 1.037450, 3.237280, -0.067320, -0.977170, 0.052250, 
0.153180, 0.471660, -8.490300, 2.050950, 0.997060, -0.349920, -2.480310, 0.450050, -3.090130, 0.088770, 
-0.573230, -0.256360, -0.725880, 0.456620, -3.088920, -0.530050, 0.016740, 0.374000, -0.065530, 1.123580, 
-0.310130, -0.529320, -0.023590, 0.530370, 0.826500, -0.603720, -0.369950, -0.392300, -0.419860, 0.135440, 
-0.293150, -0.600340, 0.237430, -0.210620, 0.138120, 0.455670, -0.320890, 0.669920, -0.027390, 0.601870, 
-0.133580, 0.314590, 0.407210, -0.146710, -0.105500, 0.612650, -1.982520, -1.390690, 1.958540, -1.845060, 
0.155360, -1.970120, -0.463860, 0.286870, -1.388080, 0.692290, -0.389590, -1.203690, 0.757870, 0.249270, 
-0.729710, -0.513990, 1.202180, -0.155360, -1.668900, 1.742390, 0.589520, -0.666240, 0.211330, -1.360640, 
-0.487280, -0.345490, 1.296230, -0.600500, 2.227020, 0.261680, 0.735310, -0.637730, -0.454830, -0.148530, 
-1.913420, -1.002020, 0.394720, -0.548540, -4.309450, 0.910560, -1.744930, 0.238760, 1.176560, 0.145460, 
0.857300, -0.258390, -1.046150, -0.463340, 0.065730, -0.954570, -0.284240, -0.748610, -0.992650, 0.683230, 
0.752530, 0.374280, 17.183300, 1.805630, -0.642800, -0.534190, -5.508850, 0.889460, -0.233680, 0.022800, 
-0.380910, -0.387240, -0.636210, -0.743080, 0.364100, -0.917500, 0.148950, -0.030950, -0.654370, -0.109020, 
0.085250, -0.767090, -0.218750, -0.213050, 0.404360, 0.455110, -0.054160, 0.635370, -0.520240, -0.645450, 
-0.470350, 0.813410, -0.565420, -0.373770, -0.969230, 0.143380, 0.542160, 0.928480, 0.893890, 
2.289320, 1.659260, 0.469730, -0.862530, 1.173050, 0.819310, 0.814020, 0.292800, -0.200460, -0.100780, 
0.592210, 1.734010, 1.822830, 1.246140, 1.120470, 1.126180, 0.013180, 0.663820, 0.619770, -0.497240, 
1.457180, 0.353010, -0.181440, 2.720320, -0.560730, -1.092020, 0.181040, 0.149960, -0.224740, -0.164680, 
-0.887150, 1.871230, 0.432600, -0.516800, 0.790020, 0.136120, 2.252480, -0.134500, -0.189970, -0.869550, 
3.412510, -0.582870, -0.725510, 0.783280, 1.941560, 0.350290, -0.078620, 0.087280, -2.010240, 1.017740, 
0.666330, -0.939100, 2.800690, -0.197580, -0.239080, -2.361350, -1.066410, 0.015210, 1.386570, 0.075870, 
0.203080, -0.054260, 0.326960, 3.194890, 0.803660, 0.343270, -0.305190, -0.253600, 0.680960, 0.122080, 
-0.249010, 1.511950, 0.061020, -1.244260, -1.217390, -0.380010, -2.861100, -0.077110, 1.809600, 0.926350, 
0.972860, 0.079440, 1.045260, 0.552640, 2.501770, 2.667890, 0.230460, -0.157140, -1.354790, 0.241570, 
2.512200, -1.725380, -0.743630, -2.447190, 0.121470, -0.102750, 0.038040, -1.129040, 0.587260, -1.109130, 
1.664810, -0.096610, 3.229450, 1.138280, 1.211840, -3.599580, -0.596070, 0.658890, 0.845910, 0.401970, 
0.379500, 0.006110, 0.261940, 1.514940, 1.877550, -0.766580, -4.763380, -1.993210, 1.073230, -3.654410, 
0.510400, 5.245750, -2.985200, -2.004400, -4.193200, -0.762220, -0.157090, 0.465190, -0.811710, -2.345910, 
-5.869390, -0.677630, -5.828430, -7.108500, -8.062020, -1.812690, -1.072170, -1.390820, -0.416990, 0.195500, 
-0.374760, 1.407140, 1.337830, -1.029130, 0.415820, 3.558450, 0.601880, 0.733110, 2.105700, 0.892470, 
2.729320, -2.882230, 0.330120, 2.571670, 0.319920, 3.851920, 0.611480, -2.379990, -0.479690, 0.127650, 
0.166180, 0.335390, -0.876010, -0.936580, 0.453600, 1.743940, -0.376860, 1.701570, -0.465110, 0.727940, 
-1.272120, 1.130690, -0.093640, 1.734990, 0.777650, 0.096390, -0.755670, 0.558980, -0.466400, 1.880040, 
-0.030420, -0.325540, -0.111320, 1.186740, 1.353170, -2.385700, -1.421030, 1.253520, 0.575290, 0.790010, 
2.359060, -0.338530, -0.599760, -1.052880, -0.499890, 0.454590, -0.105890, -0.874000, 0.867270, 0.502130, 
0.174350, -1.629570, 2.427960, -0.437690, -0.850990, -0.794080, 0.570960, 0.937400, 0.640930, -1.322820, 
0.377280, 0.229180, -1.915120, 1.324590, -0.571210, -0.772990, -3.549320, 1.038010, -0.817410, -0.683600, 
2.814820, 0.592210, -0.263020, 1.624610, -3.718590, 0.280900, 2.105950, 0.654550, 0.312230, 2.637540, 
2.239670, 0.566120, -0.382120, 0.326800, 0.525250, 1.875140, 2.836670, -0.461310, 1.932290, -0.034470, 
1.583610, -0.506580, 1.316510, 6.941270, -0.071990, 2.531510, 0.646410, -1.054870, -0.214730, 1.532630, 
0.853520, 1.527550, 2.038610, -27.918030, 0.378170, -4.023280, 0.319580, 0.024870, 0.370540, -2.129900, 
-1.082800, 4.851450, 0.527630, 0.914070, -1.296100, -0.835550, -0.472540, 0.295560, 0.679820, -0.580620, 
-0.144370, -0.386870, 0.040400, 0.139870, 0.892580, -0.652170, 0.385670, 1.465970, -0.758910, -1.565390, 
-0.365200, 0.755980, -0.649940, -2.329110, 0.411710, 1.418210, 0.134070, 0.096930, -1.075200, -0.850580, 
-0.716150, -0.416360, 0.473480, -0.916690, 0.563540, -0.931250, 0.438250, 1.009080, -0.232930, 
-1.405740, -0.007820, 1.090470, 1.366520, -1.968130, 0.745510, 0.479360, -0.512860, 1.103900, 0.494570, 
0.776530, -0.140740, 0.100770, -0.049580, 0.771760, -0.605420, -0.299620, 0.389510, 0.100440, 1.851630, 
-0.495030, 0.176680, -1.132880, 1.310540, -0.586000, -0.011510, 0.948040, 0.484890, 0.259370, -0.221840, 
-0.425180, -0.872930, 0.514500, 0.131570, -0.784060, -0.103650, -0.532320, -0.445040, -1.117080, -1.007180, 
2.098990, -1.212730, 0.203090, 0.904670, -0.550140, -1.525450, 0.308780, 1.594060, 2.894230, -1.812050, 
2.364290, -0.359060, 0.998330, -0.731500, 1.081680, 1.746200, -0.678400, 0.337640, -0.744520, 1.678620, 
2.134990, 0.083550, 1.534270, 1.437740, -1.226360, -0.042990, -0.303250, 0.686830, 0.418020, -0.036570, 
-2.211650, -1.105370, 0.593210, -0.592600, 1.381960, -0.372010, 0.268370, 0.529430, 0.124950, -2.933870, 
-0.166090, -1.442430, -1.887480, 0.042850, -1.877900, -2.158140, -0.653380, -1.973610, -1.233100, -0.951220, 
0.710920, -0.764150, 0.262640, 0.369230, 0.649110, 0.418700, 0.726720, 0.290460, -0.016270, -1.118460, 
-0.781280, -0.899380, -0.693010, 1.289250, -1.040460, -0.776650, -0.277370, -0.262460, 0.395880, 0.583670, 
-0.760830, 2.037510, 0.276150, 0.763500, 1.653690, 4.969490, 8.425940, 1.706230, 0.484220, 4.875740, 
2.238440, -2.219390, 1.931440, 1.585440, 4.765520, -0.295860, -0.770720, -0.752420, 7.395290, 0.642920, 
-0.856260, 0.245930, 7.737530, -1.433500, -0.790130, 4.947380, 7.802660, -1.979840, 0.945820, 0.524360, 
1.533140, 0.884250, 0.530570, 1.685850, -2.155790, 0.309360, 0.092070, 1.062430, -0.087970, 0.037740, 
0.496690, 0.175920, 0.304410, 1.124520, -0.982280, 1.554180, -0.229920, -1.136620, 0.073840, 0.087940, 
-0.102430, -0.191580, -0.076290, 2.944790, 0.153730, 0.486990, -0.418700, 0.404590, 1.359370, -0.197650, 
4.123060, -0.025320, 0.342400, 1.313690, -0.366240, 0.272230, -0.736690, 0.629660, 1.255610, 0.470680, 
-0.477520, -0.804060, -0.139870, 0.594640, -0.538360, 0.117650, -1.153490, -0.833660, -0.213500, -0.444750, 
0.231040, 0.801820, 0.148810, -0.429860, 0.215140, 0.501210, -0.260720, 0.077070, -0.958720, -0.785550, 
-0.207340, 0.247140, -0.571820, -0.191540, -0.568820, 3.102080, -3.026140, 0.459450, -0.296050, 1.288860, 
-0.862850, 1.164140, -0.005060, -0.349160, -0.264890, -0.268050, 2.591940, -0.170610, 0.417100, -0.244160, 
-0.131500, 0.522540, 0.004320, 0.794210, 1.404440, -1.977160, -0.328700, -0.567020, 0.806810, -0.843450, 
0.008010, -2.612960, -1.359640, 0.512280, -0.703110, 2.078660, 1.267580, 0.072490, 0.450200, 2.313370, 
-1.025660, 0.199920, -0.513660, -3.017160, 0.093870, -0.045180, -0.267990, -0.058620, 0.611610, 0.006180, 
-0.801250, -1.930240, -0.439100, 2.980080, 0.183230, 0.297570, 0.898580, -0.874810, 0.401820, 0.395720, 
-0.415450, -0.783370, 5.921220, 0.016640, -0.365840, 0.184680, -0.261080, -0.254250, 0.687630, 0.540050, 
0.671030, 0.573660, 0.662620, -0.257990, 0.096570, -0.752060, 0.484040, -0.342170, -0.580070, -1.321650, 
-0.413460, 0.679970, 0.263010, 1.948820, -0.126260, 0.167640, -0.052050, 0.746480, -0.442510, -0.092880, 
-0.181380, -0.600310, 1.384660, 0.632290, 0.163240, -0.264360, 0.650340, -0.893840, 6.373760, 
1.217050, -1.445060, -0.282010, 1.901500, -0.549910, 0.387550, 0.455960, 0.263860, 0.283150, 0.700850, 
-1.330810, 0.290010, 0.167560, -1.511470, -1.083090, 0.936190, -1.741920, -0.155040, -0.737890, -1.141280, 
-1.741290, -0.681540, 1.606830, 0.108230, -0.364370, 0.997400, 1.540360, -0.385810, 1.522090, -0.406760, 
-0.276290, -0.096120, 0.434550, 0.666540, 1.346850, 0.445500, 0.327310, -0.502080, 1.719000, 0.019440, 
0.061750, 1.281030, -0.633890, -0.444080, -0.383900, -0.421610, -1.316900, -0.276440, 0.190600, -0.221790, 
-0.021210, -0.450230, 1.330570, -1.044920, -0.919990, 1.352340, -1.335170, -0.542680, -0.020860, 0.911100, 
-0.174150, -1.035740, -0.306060, -0.429560, -0.140250, 0.605800, -0.559180, 0.046900, -0.274830, 0.090370, 
-0.180840, 0.520530, 0.730480, 0.359550, -0.612470, -0.613320, 0.578210, -0.576960, -0.491850, -0.549480, 
0.231880, -0.820870, -0.482720, -0.103900, -0.316870, 0.261130, 1.044380, 0.348410, 0.369240, -0.248980, 
0.687660, 0.018650, -0.930970, 0.492160, 0.522650, 2.346920, 1.501350, 1.699450, 0.693370, -0.557870, 
0.955620, -0.677120, 0.177350, 1.022660, -0.184050, -0.065350, -0.522600, -0.559660, -0.780220, 0.898890, 
1.002950, 0.733470, -0.795000, -4.955970, 0.277800, 1.208200, 1.561560, 2.665290, -2.907880, 3.544490, 
-0.853010, 0.608730, 0.162630, 3.865290, 4.204510, -0.233580, -1.247200, 1.167660, 0.613370, 0.738160, 
-0.173720, 0.726130, 6.273240, 0.185240, -1.268560, 2.521770, 6.059530, -1.826360, -1.827710, -1.456830, 
2.012150, -0.706530, -1.107070, 0.775670, -0.654430, -0.645030, 0.332190, 1.100760, 1.745240, 2.091930, 
-0.409780, 0.295050, -0.011980, -0.651140, 0.737420, 1.202420, 2.451330, -0.337730, 0.321790, -0.364700, 
-1.946060, -0.054680, -0.642350, 0.538650, -2.015030, -0.221580, 0.261250, 0.476990, 1.244880, -0.385200, 
0.207890, -0.424120, -0.604030, -0.454830, 0.441520, 0.128390, 0.641700, -0.536030, 0.238900, -1.050060, 
-1.623880, 0.614640, 0.989310, -0.426490, 0.708280, 1.649070, 0.150490, -0.953670, -1.783970, -1.145130, 
-1.160540, 0.735390, 0.521980, 1.660650, -0.345070, -0.299550, -0.127720, 0.370530, -0.030430, -0.781670, 
0.218640, 5.006760, 0.106030, 0.902250, 0.354300, 0.542400, 0.018620, -1.524780, -0.051350, 1.212620, 
-1.103780, 0.783050, 2.227090, 2.004600, -0.605530, 0.771770, 0.806550, -1.326660, -0.610720, 0.651180, 
0.571820, 0.354000, 1.538680, 0.556680, 1.370370, 2.446770, -0.252510, -1.420080, 0.454980, 0.580430, 
-0.903260, 0.300120, -0.562100, -0.196420, -1.101570, 0.120450, 0.202010, -0.660170, -1.441090, 2.075430, 
0.356170, 0.238530, -1.812680, -0.415940, -0.259870, 0.470650, 0.844480, 1.418850, 0.800600, -0.357830, 
-1.426580, 2.138230, -1.832570, -5.100720, -0.006180, 0.224530, 0.522480, -0.095690, -0.101020, 0.800850, 
-1.479370, -1.181770, -12.838330, -2.112920, -0.003520, 1.560880, 0.255200, 0.792960, 0.372720, -0.281370, 
-0.846910, -0.139670, -0.937520, -0.149110, 0.728110, 0.113680, -0.230990, -0.858800, -0.166080, -0.456470, 
-0.395580, -0.342680, 0.770270, -0.552820, 0.405010, -0.423030, -0.672830, -0.451230, 0.539410, -0.134360, 
0.898750, 0.945300, -0.270250, -0.753580, 0.372010, 0.456540, -0.414940, -0.397710, -0.422290, 
-1.810590, -1.021120, 0.025220, -0.245790, -0.684870, -0.435500, 0.078590, -1.904320, -0.355680, -1.089400, 
-0.298920, 0.096310, -0.817540, 1.415790, -1.254760, 0.413320, -0.438260, 1.160170, -0.133440, -0.895960, 
-0.597950, 1.123950, -2.928870, 0.536430, -0.981090, 0.995400, -1.558950, 1.745980, 0.386600, -0.753220, 
-0.517420, 1.320530, 4.442560, -0.287250, 0.404620, -0.074570, -0.790270, 2.301180, 0.417120, -0.686820, 
1.535480, 0.486920, 1.035690, -0.346950, -0.871040, 0.843380, 0.862990, 0.004890, 1.086700, 1.956980, 
-0.451460, 0.524300, -3.053230, 0.785700, 2.171530, -1.058270, -1.370790, -0.575460, 0.067400, 0.478920, 
0.154650, -0.715870, -3.040180, 0.287920, -2.294520, 0.300110, 0.018170, 0.869250, -0.876750, -1.349320, 
0.663670, 1.202270, -2.195630, -0.349040, 1.174510, -0.317730, 1.923310, -2.301270, -0.679110, -0.871770, 
-0.243120, 0.750940, -0.513070, -0.075870, -0.839520, -0.585130, -1.316720, 1.007750, 0.157740, -0.948200, 
0.601980, -1.127550, 1.501920, 1.287940, 11.940020, 0.052900, 1.234870, 1.255540, -0.210060, 1.048270, 
0.645860, 2.022320, -3.104020, -2.051520, 0.084500, -0.263870, 1.312630, 0.469290, 0.068110, 18.674191, 
-0.505640, -1.822640, 0.169390, 4.960900, -1.813430, 0.153980, 0.072480, 2.617970, -0.364770, 0.927690, 
0.108940, -0.360720, 0.456860, 1.591450, -0.146990, -0.820990, 0.729450, 0.004520, -1.513590, 1.162780, 
-0.518310, -1.152550, 0.842710, -0.513100, 0.019900, 0.341840, 0.120060, 1.501200, 2.242030, 1.971960, 
-0.130800, -1.917790, -0.068500, 1.472500, 0.387130, -0.318960, -0.363260, -1.076980, -1.404680, 0.625210, 
0.531020, 0.889490, -0.146140, -0.734530, 1.067270, 3.093290, -0.872020, 1.204730, -2.051640, 2.701210, 
-9.409160, 0.648300, -0.086710, 0.946790, 1.132780, -0.670010, 0.475220, -0.487120, 1.109700, -0.264200, 
0.384550, 0.097830, 0.097930, -0.821700, 1.044110, -2.153460, -0.737590, 0.161630, 2.680920, -0.232080, 
-0.019200, 0.920530, 2.697930, -1.970650, 0.720130, -0.019080, 0.035540, -0.086870, 0.930190, 0.889160, 
-0.681410, -0.912600, 0.887540, -2.039060, -3.137590, 0.622160, 0.049930, -1.034070, -1.263550, -0.794380, 
0.019180, 0.826350, -1.305100, 1.126980, -0.880660, -0.538940, 0.249940, -0.279530, -1.951000, -0.853400, 
0.334370, 0.221980, 1.053310, -2.169410, 0.387690, 0.653010, -0.165380, 0.023580, 0.025200, 0.835460, 
-1.322450, -0.437390, -0.908820, -0.600400, -2.346200, -2.328770, -0.478370, 0.572560, 0.516740, -1.647920, 
0.808790, 1.874030, -0.936220, 0.067060, -0.228470, 1.188180, -0.128980, 0.125000, -0.493860, -0.042510, 
1.074050, -1.717700, -0.832530, -0.255140, -0.877040, -0.060130, -0.436100, 1.007220, -0.075760, -0.179010, 
1.071560, -1.196910, -1.455290, 3.912510, -0.296810, 1.097190, -0.384160, -0.661910, 0.032830, 0.143000, 
0.094040, -2.648640, 3.932590, 1.333300, -1.228850, 4.540890, -0.156020, -0.174770, 2.246990, -0.013460, 
0.748230, 0.498150, 0.646910, -0.845100, -0.481010, 0.634270, -0.561020, -0.037080, -0.851480, -2.873710, 
-0.082500, -0.564200, 0.607610, 1.166610, -0.797090, -0.248920, -0.714730, -0.557770, -0.245320, 0.763650, 
0.737520, -0.756790, -0.624590, -0.800000, 0.786600, 0.344020, 0.002040, 0.462310, 1.694540, 
-0.212860, -0.354270, 0.689540, -0.005570, -0.048500, -0.340580, -1.204060, 0.252490, -0.815100, 0.006640, 
0.691920, 1.191680, -0.454580, 2.023640, 1.592560, -1.163150, 1.610110, 0.768910, -0.310810, 1.799560, 
0.098850, 0.793110, -1.201770, 0.249870, 0.459120, -0.964430, 0.284120, 0.372060, -0.667790, 0.611070, 
0.204250, 2.524730, -1.610310, 0.025720, -0.214130, 1.130430, 0.697490, 0.919270, 1.460420, 1.628680, 
-1.121410, -0.822390, -1.104680, 0.820810, -0.434270, 0.809010, 0.262440, 0.080070, -1.148610, 0.729340, 
0.561190, -2.698510, 0.920200, -1.333470, 0.479900, -0.930610, -1.223980, -0.888650, 0.844720, -0.833570, 
-2.035240, -0.107880, 1.145060, 0.465740, -0.084570, 1.518200, -0.634320, -0.838230, 3.242800, -0.039230, 
-0.571780, -0.841440, -0.454820, -0.494700, 0.471470, -0.096700, -0.100440, -0.561050, -0.332680, 0.348620, 
0.910840, -0.447780, 1.322200, -0.280850, 0.236430, 0.631910, -0.852750, -0.464620, 0.403900, -1.064450, 
-1.221540, 0.501230, 0.657140, 0.503060, -1.056370, 0.263390, -1.628620, -0.673250, 1.429570, 1.164650, 
-2.021430, -0.848660, 2.738550, -0.707180, -0.379390, 0.910320, -1.761440, 1.231390, 1.302950, -3.111750, 
1.079190, -1.360030, 0.126820, 3.061270, 1.393070, -3.108920, -1.068770, -1.619180, 1.014960, 0.938820, 
-0.926810, 3.031290, 0.032250, -2.536130, -10.055280, 3.316070, 0.222300, 1.897220, -1.124200, 0.319000, 
-0.780230, 0.328780, -8.150340, -1.670690, -0.788430, -1.345800, -4.335520, 1.664620, 0.273740, 1.846950, 
-0.204720, 3.034500, 0.357230, -4.181640, 0.923170, 0.162160, 1.858740, -0.762010, -0.022530, -1.093980, 
-0.261390, -0.708680, 0.015540, -0.862290, 2.725120, -1.079360, -2.695890, 0.409100, -0.737960, 0.013170, 
0.402400, 1.216510, 0.577570, -1.223870, 1.665800, 0.362250, -0.791240, 0.861150, 0.936160, -0.311260, 
-1.240930, 0.460350, -3.065050, 0.153390, 0.726950, 0.705950, 1.819190, 1.476520, -0.685250, 0.659680, 
0.083140, -0.377340, -0.634540, 0.021320, 1.012200, -0.442990, -1.071740, -1.883260, 2.016270, -0.584250, 
0.247870, 1.476750, -1.040950, -1.743880, -0.793640, -1.341340, -0.034280, 0.197690, -0.161960, 0.009300, 
1.072780, -0.893660, 0.987640, 0.209860, 0.361510, -0.284710, 1.974430, 0.744010, 1.204870, 0.407780, 
0.882790, 0.576680, -0.297010, -0.287080, 0.984070, -0.391760, 0.330340, -1.132150, 0.377950, -0.542770, 
0.378970, 0.435430, 0.184680, -0.432130, 0.438360, 0.727590, 0.288590, 0.044070, -0.396540, 1.104660, 
0.345630, -0.421080, -1.444170, 0.144440, 0.904130, 0.510120, 0.021370, 0.360380, 1.088890, 0.326100, 
-0.623910, 1.713420, 0.747840, 3.843210, -0.137540, 1.372040, 0.020080, -1.602790, 0.945450, 0.501440, 
1.158050, 0.787920, -0.390120, 11.859120, -0.120040, 1.563610, 0.157460, -1.500400, 0.828390, -0.646970, 
-0.144560, 0.931380, 1.292990, 3.401270, -1.083980, 0.386640, 0.283600, 1.387480, 1.201220, -0.845560, 
0.382710, -0.719630, 0.854500, 1.136220, 0.213740, 0.363540, 0.091980, 0.213840, -0.122560, -1.575710, 
-0.473670, 0.564200, -0.864750, -0.002000, 0.038120, -0.659790, 0.762860, -0.746450, 0.518290, 0.981030, 
0.351200, 0.961600, 0.544850, -0.091830, -2.020870, 1.063040, -0.661660, 0.557060, 1.186810, 
1.134460, -0.454300, -2.471920, 2.445400, 2.310450, 1.678810, 0.780710, 2.389420, 1.197720, 0.754000, 
3.120390, 0.096660, 4.181340, -1.033050, 0.069580, -1.293070, 0.397980, -1.537370, 0.990730, -0.534460, 
-0.091890, 2.029180, 0.539040, -0.027430, 0.454930, 0.070700, 0.248490, -0.845860, 0.045050, -1.756840, 
1.678350, -0.964080, 0.242660, 1.968810, 0.529350, -0.868800, -1.363570, 0.989750, -0.060150, -1.033920, 
0.727050, 0.603620, 0.851170, 0.630880, 0.158840, -5.760050, -0.483270, -0.337240, 1.484360, 0.168590, 
0.625220, -1.224240, -0.999450, 1.064460, 0.084710, -0.125550, -0.020810, 0.209140, -0.400240, -2.869720, 
0.411140, 1.334910, 0.066370, -2.215000, -0.875870, -0.483620, -0.200450, -1.553070, -0.116320, 0.463390, 
-2.064650, -0.234970, 0.463460, -0.713450, -1.762950, 2.254110, -2.006970, 1.667260, -1.832900, -0.705340, 
0.485340, -1.585000, -5.857600, -0.300090, -0.915260, -0.222650, -1.622300, 1.346180, 1.586740, -0.754760, 
1.866940, -0.840800, -1.618670, -0.744670, -0.468080, 1.499830, -0.501560, -2.221280, 1.345420, 1.431880, 
-1.761350, 0.501550, -0.146510, -0.825470, 0.153060, 1.150230, -0.135570, 0.395840, 0.638540, -1.378530, 
0.571860, 1.092570, 0.496950, 0.735510, -0.682940, 0.698400, -2.545130, -0.474160, 12.034380, -4.767800, 
0.156100, 1.313650, 0.267270, 0.494380, 0.537960, 2.207130, 0.503730, -2.160580, -0.967930, -3.854110, 
-1.909640, 0.032560, -1.756580, -0.132560, 0.708300, -0.233030, 0.757270, 1.494880, -0.028550, -3.964820, 
0.039460, 1.064580, 1.206800, -0.298020, 1.852850, -2.373760, -0.054280, 1.743490, -0.257240, 0.582000, 
-0.302590, -0.867300, -0.919110, -0.266620, -1.102770, 1.153300, 2.242750, -0.130160, 0.438280, -0.110770, 
0.807010, -2.055060, -0.619860, -4.003920, 0.490430, 0.483710, 1.896720, 0.132350, -0.157470, 1.170400, 
-0.840210, -1.579250, -0.838870, 0.341130, -0.632340, 0.040020, -0.017270, -0.674920, 0.389600, 0.386720, 
0.024730, 0.057380, -0.542910, -0.518780, 0.774830, -0.824890, -0.242790, -0.219190, 0.598680, -3.872810, 
1.440350, -0.480070, 0.002090, 0.427420, -0.173950, -0.001570, 0.451260, 4.819200, -1.465870, 1.195600, 
-0.281930, -1.105530, 0.649840, -0.616460, 0.265820, -1.164640, -0.520930, -1.438150, 1.470700, -0.324260, 
-0.896970, -1.133890, -0.488800, -0.725390, -0.996060, -1.026590, 0.247680, 0.676190, -0.562120, 1.020790, 
0.807950, -1.478120, -0.552340, 0.125890, -0.205280, 1.236250, -0.431940, 0.480860, 0.860090, -3.074050, 
2.523560, 0.834470, -0.035840, -0.788820, 0.644030, 0.499810, 0.708830, -0.540740, 0.470000, 0.237910, 
-0.300790, 0.028150, 0.363620, -0.705830, 1.361210, -0.169740, 1.996480, 0.854800, 0.420690, 0.958540, 
-0.586920, -0.708920, 2.691990, -11.844670, -0.756470, -0.066480, -0.966290, -2.735870, 0.173790, 0.172360, 
-0.069030, -0.010470, -1.507700, 0.964270, -0.136180, -2.229670, -2.329340, -0.309760, -0.000630, -0.027940, 
-1.052210, 0.295910, 0.559890, -9.312520, 0.063590, -0.108450, 0.504370, 0.354400, -0.944600, -8.049850, 
0.616870, -0.330990, -0.135720, -23.684420, -0.195290, 2.377780, -0.957250, -0.308020, -3.567360, -0.783230, 
-1.043680, -2.242870, -3.389910, -0.478180, 0.383210, 0.545030, -1.509490, 0.780080, -7.648470, 
0.678630, 0.320560, 0.325770, 0.230740, -1.218870, -0.273150, 1.273540, 1.323800, 3.400700, -0.914920, 
-0.585830, 0.250840, 0.636670, 1.125420, 1.669490, 0.553700, 1.046660, 0.786890, -0.236880, 1.214950, 
1.054290, 0.806960, 1.249350, 0.767170, -0.888030, 1.071420, 0.946520, -0.662770, 0.163060, 1.346530, 
-1.744770, 1.427190, 3.743740, 1.694160, 0.602380, 0.944800, 1.726650, -0.717580, -0.026030, -0.281020, 
3.478200, 0.508140, -1.144860, 1.402920, 0.782880, -0.186310, -0.584110, -0.225330, -3.128660, 0.372250, 
0.392540, 0.373050, 1.626210, -1.052720, 1.451120, -0.391950, 0.538420, -0.162700, 1.450200, 2.060430, 
0.623680, 1.157840, 1.256810, -0.541420, -1.025740, -0.653030, -0.162900, 0.389770, 1.180920, -0.251060, 
0.182030, 0.256090, -0.118470, -0.505360, -0.162580, -1.489130, 0.039090, 0.582570, 0.938930, 2.144330, 
0.858510, 0.357130, 0.606520, 2.195730, 0.007150, 1.902650, 0.672570, -4.704040, -0.583910, 0.574210, 
-0.071190, 0.518910, 0.230410, 3.206590, -1.296600, 0.687650, -0.156580, 0.820020, 0.750370, -1.863260, 
1.674070, -0.664210, 2.613290, 0.980200, -0.733000, -0.002000, -0.825120, 1.683420, 0.681630, 1.473360, 
-0.062950, -0.243240, 1.231470, -0.808300, -1.472120, -2.338890, -1.653670, -0.302520, 4.174910, -1.667530, 
0.167690, 7.183140, 0.227240, -19.076059, -19.679001, -5.108870, 0.384780, 2.876940, -1.548830, 1.562170, 
3.656380, 2.036470, -11.447010, -1.456690, 0.680030, 0.099560, 0.527990, 0.914330, 1.053160, -0.316880, 
1.683800, 1.369410, 0.738710, -0.379220, -0.205920, 0.091200, 0.090250, 1.898080, 1.608150, 1.393390, 
0.468580, 0.474760, 0.748790, 0.459950, 0.774020, 0.763760, -0.935850, -1.726060, -1.377490, -0.059420, 
-1.395840, 0.548600, -1.248890, 0.453340, -0.114120, -0.860220, 0.932020, 0.653160, -2.242980, 1.239620, 
0.733810, 0.592690, -0.148120, 0.513040, 0.317400, 0.469570, 0.473520, 4.146290, -2.924790, -1.207880, 
-1.162940, 0.557020, 1.106450, -0.006060, 1.831860, 1.114440, -0.112060, 1.718430, -0.917850, 0.703460, 
1.468310, 0.401420, 0.672140, -0.292100, -0.266990, -1.257420, -0.184960, -0.035840, 1.058310, 0.386370, 
1.352280, 0.043370, -0.461920, 1.562760, -0.499920, 0.246870, -0.222450, 1.499330, -0.731200, 0.835810, 
0.432250, -0.688540, -0.957100, 0.565610, -0.134590, 2.799280, -0.240990, -0.539160, 0.667740, -0.226800, 
-0.215110, -0.324840, 0.322930, 1.925870, -1.343020, 2.241290, 0.519640, -0.175620, -2.715300, 1.079110, 
4.463250, 0.720330, -2.536940, 1.740570, -1.449130, 0.271410, -0.616130, -0.299700, 0.589960, -1.191530, 
0.663000, 1.227180, -0.765910, 1.570440, 1.391980, 0.183430, 0.964330, 0.286260, -0.112480, 0.990250, 
-0.144710, -1.286450, -0.015030, 9.895550, 0.314410, -1.882440, 0.010370, 0.770950, -1.590250, 0.609310, 
-1.481230, -0.794670, 0.142260, 3.429060, -0.341110, -0.185060, -1.469390, 1.045770, -0.780400, -0.118390, 
-0.606220, 0.259650, -0.006460, 0.226190, 0.797790, -0.398290, -0.954490, 0.702450, -0.887020, -0.781640, 
0.455590, -0.539620, -0.285840, -0.400190, -1.002690, -0.704650, -0.645360, -0.678030, -0.346200, 0.664740, 
1.990330, -0.478920, -0.581030, -0.844740, -0.295470, -0.000660, -0.248960, -0.832170, -0.280990, 
-0.478380, 0.115710, 2.427070, -0.466320, -0.403910, -0.423010, -0.221260, -0.233970, -0.955690, 0.274720, 
-1.319110, 0.138580, -0.461270, -1.608010, 0.157030, -1.050320, -1.403280, -1.331230, -0.262460, -0.742510, 
-0.477230, -1.950150, -1.699490, 2.062340, 0.267940, 1.173970, 2.036720, 2.481950, 0.331860, 1.066960, 
-0.378060, 0.900060, 3.777710, -0.488610, -0.479810, -1.074500, 0.551940, 0.742350, -1.373260, -1.235570, 
1.989810, -1.360790, 0.128020, -0.254630, -1.611400, 1.737880, -0.217140, -0.126460, 0.310840, 1.579380, 
-0.328560, -0.522680, -1.119070, -1.097700, 0.204820, -0.058740, -0.693640, 0.838130, -0.303400, 0.289590, 
0.993090, 0.245930, 1.357590, -0.280450, -0.843960, -0.781630, -0.679160, 0.118600, 0.489530, 0.304620, 
1.148220, -0.415470, 0.469470, 0.105310, 0.343380, -0.293440, 0.259070, 0.072270, -0.324170, -1.185880, 
-1.128520, 0.067270, -1.030740, 1.602580, -1.695660, 0.228960, 0.375040, 0.399250, -0.628690, 0.331690, 
-1.205340, -0.647550, 0.195060, 0.944010, -0.689060, 0.240930, -1.062420, 0.152490, 0.782820, 0.714750, 
-0.957150, -0.236740, -0.332240, 0.745830, 0.541170, -0.904640, -1.523660, -0.574950, -1.109390, 1.536350, 
1.684710, 0.055880, -0.421590, -3.940140, -3.126610, 2.211560, 2.641600, 2.020880, 0.756420, 2.924590, 
1.275460, -2.042260, 0.012130, 1.490390, 3.359560, 1.175340, -2.094800, -0.568090, -0.713850, 0.897850, 
-0.559600, 2.070320, 2.695880, 3.566620, 0.751410, 0.789860, 1.144790, 0.440160, 0.062210, -0.259170, 
1.441080, -0.575920, 0.544490, 0.525100, 0.325280, 0.672620, -1.046870, 0.458560, -0.229970, -1.063670, 
-0.378760, -0.200120, -0.617180, -1.007410, -0.992700, -0.224890, -0.036950, -1.064800, 0.220360, -3.604680, 
-0.759040, -0.643600, 0.719970, -1.726490, -0.091310, -0.303690, -1.200450, -0.529960, -1.125020, -0.257130, 
-0.738840, -0.891640, 0.604860, 0.006770, 0.470870, 0.792670, -0.345270, -0.705310, -0.934800, 1.152090, 
-0.052450, -0.344590, -1.915760, -2.719170, 0.704770, 1.029910, -0.057440, -0.335280, -0.692050, 0.860130, 
-0.238180, 3.965640, 0.056250, 0.370730, -0.315400, -0.454510, -0.561970, 0.212720, 0.031870, 0.244440, 
-0.027010, 1.526700, -0.113490, 0.198900, -0.458090, 0.207240, -3.163060, -0.421410, -1.034860, 1.906380, 
-0.673350, -0.004150, 0.393250, -0.722720, 1.055740, 1.649860, -0.046160, 0.195840, -1.046660, -0.748950, 
0.221880, 0.212450, -2.296010, -0.152750, 2.137700, -0.397010, -0.828880, -0.541410, -2.576500, 0.091210, 
-0.389780, 0.057680, 2.033780, -0.480780, -0.855940, 1.841820, -0.089770, 0.838610, 0.315520, -0.560960, 
-0.464060, 0.367510, -1.202240, -0.566560, 0.193950, -0.272600, -0.306670, 3.581580, 0.318160, 0.186530, 
0.054520, -0.916490, -1.931200, 0.830920, -0.272700, -1.052430, -1.225880, -1.050480, 1.320670, -1.074580, 
0.638670, 0.103310, -2.060930, -1.740560, 0.340330, 1.071030, -0.067460, -0.335590, 0.641550, -0.054800, 
0.602160, -1.282430, 0.350780, -0.456030, -0.075770, 0.041220, 0.631680, -0.687100, 0.125790, 0.211370, 
0.496500, 0.018260, -0.913450, -0.040950, -0.794740, 0.205220, 0.426760, -0.074410, 0.703960, -0.174730, 
0.263740, -0.236450, -0.603670, -0.279370, -0.881770, 0.098220, -0.761460, -0.599150, 1.216580, 
0.140170, -0.596610, -1.372260, 0.741360, -0.803190, 0.200480, 2.810890, -1.320610, 1.130620, -2.051820, 
0.255450, -0.094320, 0.961970, 1.829020, 0.364040, -1.797760, 0.420460, 0.130440, -0.981590, -0.554290, 
1.308410, -0.346530, 3.116390, 0.313030, 1.529570, -0.557140, 0.413970, 0.619850, -1.087490, -0.335390, 
0.638100, -0.698540, -0.962380, 0.851600, -0.055460, 0.421700, 0.434340, 0.208200, -0.493350, -0.306660, 
-1.017210, 0.314770, -0.098070, 1.335930, -0.383890, -1.060510, -1.374380, -0.939760, -0.469850, 0.510910, 
1.111840, -0.675840, 0.596710, 0.064720, -1.284200, -0.082100, -2.381670, 1.507190, -0.334990, 0.096380, 
0.982230, -0.293060, 0.040800, -0.811650, -0.100940, -0.955570, 1.419780, -0.438610, -0.279300, 0.427270, 
1.112870, -0.160450, -1.835760, -0.340220, 1.229550, -0.460400, -0.763070, 1.958230, 0.907340, 0.474200, 
-0.099340, 0.822460, 0.344420, 1.201990, -1.291500, 0.223270, -0.688730, -1.658610, -0.401480, 4.139400, 
-0.921610, 1.373710, 0.906710, -2.458070, -0.989280, -0.709060, -0.289000, 1.709960, -0.085650, -0.153670, 
0.738770, 0.752490, 0.092710, 0.813640, -0.155230, -0.863140, 2.054570, -0.324720, 0.962140, -0.658470, 
-1.063420, -0.938760, 0.541160, -0.667620, 0.755970, 0.326180, 0.408330, -0.751200, -1.641580, 0.421430, 
0.604700, 2.410300, 0.556770, 0.883680, 0.896920, 0.482940, -0.025100, 2.223390, 1.178780, 3.246470, 
0.818060, 0.213570, 0.494650, 0.278910, -0.091720, -7.879600, -0.285580, -0.185410, -0.506770, -0.861360, 
0.008600, -0.310160, -1.935790, 0.276870, 2.443880, -0.378330, 0.590140, -0.682100, -0.832510, 0.190350, 
-0.133420, -0.127860, -2.682110, 1.764050, -1.031490, 0.165560, -0.987090, -0.810180, 1.159500, -0.488890, 
2.070620, -0.681690, -0.643080, -1.438080, 0.553740, 0.230320, -0.220100, 0.728220, -2.131170, 0.160550, 
0.345690, 0.547610, 0.962590, 0.016470, 0.101920, -0.884610, -1.263550, -0.973460, -0.092780, -0.985180, 
-1.115710, 0.790580, -0.100920, 1.135280, -0.362350, -0.695560, -0.729190, 0.616160, 1.701450, -1.035810, 
0.379160, -0.024370, 0.210590, 1.194920, -0.165910, -0.962770, -0.843680, -0.341400, 0.785980, 1.086460, 
1.128540, -0.669840, -0.614950, -0.610920, 0.703990, 0.491420, 0.412390, 0.784640, -1.251900, -1.101220, 
0.336070, 0.633620, 0.527490, 1.052270, 0.301030, 1.204180, 0.592180, -0.355790, -0.535950, -0.694650, 
0.951900, -0.862350, 1.663360, 2.375160, -0.404320, -2.894780, -1.487840, 1.116700, 0.307390, 0.745280, 
-0.728380, -0.366630, -0.875990, 0.325540, -0.553980, -0.216350, 1.297820, -0.083140, -1.393030, 1.099140, 
-1.121270, 0.769610, 0.151870, 2.397260, 0.055260, 0.305960, -0.898390, -1.399810, 0.803710, 0.221720, 
3.217340, -0.016250, 2.756860, -14.616330, -0.393790, 2.591090, -0.800270, -0.034960, -0.139980, 3.518510, 
0.775210, -0.189590, 2.138600, 2.338380, -0.444310, 0.376640, 1.064440, -0.298420, 0.843670, 0.827340, 
1.208610, 1.030430, 1.022530, 2.061700, 1.161020, 1.264390, 2.425850, 0.629150, 1.014270, 1.254680, 
0.607980, 1.334010, 1.922250, 0.791570, 0.636800, 0.110610, 0.648340, 1.705500, 0.222140, 1.601060, 
4.120220, 0.176750, 0.846300, 0.921950, 0.313230, 0.975680, 0.107220, 1.752660, 3.297570, 
-2.475220, -0.753310, -0.969960, -0.127390, -1.690980, -0.743200, 0.011620, 0.407810, 0.687160, -0.756030, 
-1.019180, 0.022720, -0.708020, 0.226230, -0.825560, 0.396600, -0.978760, -1.079410, 1.546710, -1.291970, 
0.719440, -0.318380, -1.638070, -0.366240, 0.974130, -0.318670, 1.224370, -1.417910, 1.268010, 0.445030, 
0.864190, -0.511120, -1.247700, 0.356070, -0.753000, -0.860340, -0.146520, 1.154070, -1.147720, -1.054080, 
-0.801470, -1.917270, 1.663630, 1.116390, -0.528740, 1.314380, 0.092170, -0.951040, -1.366090, -0.802800, 
-0.505860, 1.952730, -3.605090, -0.130770, 0.262170, 0.839470, -0.643700, 1.048730, 0.142980, 0.827130, 
-1.808670, 1.481060, 1.785280, -1.528770, -1.835870, 1.165150, 3.586330, -0.552480, -0.413540, 0.809400, 
-0.816660, 0.538650, 0.367980, -0.181850, -0.224540, -0.823330, -0.318370, 0.274450, 0.555770, 0.389470, 
0.332340, 0.271400, 1.276150, 1.483550, -0.450570, -0.379260, -1.449790, 0.832070, -0.054640, 5.395790, 
0.503440, 2.428850, -1.938200, 0.605220, 0.060310, 0.553780, 0.476720, 1.026820, -0.021580, 0.331380, 
0.185140, -2.005690, 0.071390, 0.304660, -0.695610, 1.320970, 0.996980, 0.048740, 1.011980, -5.308170, 
-0.656490, 0.307890, 2.195550, 0.246120, 0.820910, -5.717440, 0.885550, -1.439840, -3.425500, -1.643470, 
5.484810, -0.036720, -1.613450, -6.541620, -5.861570, 1.022180, -0.577840, 0.337520, -4.580160, 0.711770, 
0.988420, 1.213610, -4.294150, -0.824630, -1.644740, -3.227780, -5.881680, 9.516700, -1.454980, -0.042410, 
-0.880290, -0.948550, -0.630960, 0.591640, -0.159240, -0.667370, 0.908620, -2.371470, 0.409810, 0.344140, 
-0.858610, -1.175350, 0.206590, 0.286440, -0.530860, -0.485710, -0.260600, -0.009050, 1.253370, -2.062530, 
-0.511670, -1.881180, -1.743370, 0.108380, 0.230970, -0.995200, 0.539580, 0.661070, -1.904040, 0.589100, 
-0.870640, -0.702130, -0.078920, 1.730310, -1.237810, -1.434630, -2.453170, 0.937540, -1.170180, -0.149480, 
-0.145430, 1.988640, -1.543030, -0.829470, -0.679680, -2.148940, -0.152220, 1.790360, -2.665700, 1.045070, 
-0.149300, 0.610470, -1.066490, -1.325620, 0.849250, 0.409690, 0.510090, -0.304790, 0.976790, 1.251160, 
-0.001040, -3.556550, -1.044900, 0.181330, 0.884510, 1.741930, 0.740270, -0.112220, -1.566000, -2.330600, 
-0.027820, -0.628520, -0.861250, 0.961720, -0.504060, -0.674500, 0.450870, -0.064860, 0.079060, -0.155360, 
0.112110, 0.818530, 0.388640, -0.417240, -1.686910, 0.038730, 0.895170, 0.454500, 0.413210, 0.796420, 
-2.160580, 0.202420, 0.905950, -0.564930, 0.129600, -0.506740, -1.598380, -0.265610, -0.108710, 0.181810, 
0.078120, 0.578730, 1.807240, 1.117560, 0.788380, -0.333040, -0.610600, -0.573950, -0.380010, 0.037530, 
0.643170, -1.365530, 0.790300, -8.662620, -0.424590, 1.093290, -2.015270, -0.607000, 0.017330, 3.363540, 
0.166410, 1.057830, -1.148320, 1.921440, -2.744310, 0.152140, 0.318520, 0.505480, 0.186090, 0.421720, 
-0.966120, 0.292600, 0.367830, -0.574900, 0.330420, -0.842930, -1.031890, -0.634440, 0.689220, -1.183080, 
-0.602150, -0.416890, 0.236290, 1.052180, 0.433040, 0.615020, 0.934230, 0.538400, 1.744390, 0.169920, 
1.211170, 0.306500, -0.327920, 0.329390, 0.447610, -0.182280, -0.058770, -0.323040, -1.521280, 
0.340700, -0.208940, -1.410940, 1.325420, -1.192780, -0.064730, -0.533040, -0.901250, -1.350120, 0.795930, 
-0.113890, 0.216660, -0.930090, 0.951290, 0.291750, -0.456250, -1.605280, -0.907230, -4.021650, 0.167630, 
4.995450, 0.440730, 0.348980, 1.408730, -0.220940, -0.025550, -0.020360, -0.035190, 1.063130, 0.219640, 
0.302220, -0.164420, -0.488020, 0.209810, -0.904640, -0.886590, 0.001760, -0.710620, -0.409780, -0.282700, 
-1.091090, -0.712330, -0.384380, -0.247610, -0.406870, 7.153470, 0.248020, 0.112200, 0.366080, -0.165670, 
-0.402180, -0.228270, -0.953510, 1.107030, 1.032650, 0.313990, 0.020150, 1.110410, -0.437280, 0.499020, 
2.663510, -0.197870, -1.855310, -0.407570, -1.147850, -0.625050, 2.952750, 0.583690, 3.904150, -0.139270, 
1.367550, 0.553540, 0.812300, 0.210090, -0.591100, -0.122910, -1.765270, -0.979690, 2.783120, -1.058580, 
0.089000, -0.271250, 1.156680, -0.498750, -0.242400, 0.154260, -1.226820, -0.127700, -1.255920, 0.720330, 
-1.017270, -0.878340, 0.960950, -1.117020, -0.530280, -0.153560, 0.075190, -1.592590, -0.437660, 0.309630, 
-0.216010, 0.740310, -0.587850, -1.174980, -0.009490, -0.030100, -0.392700, -2.258870, -0.237100, -0.920720, 
0.006360, 1.109440, 3.927840, -0.846030, 0.065000, -3.262650, -3.457330, -0.415970, 2.652230, -2.268280, 
-0.298800, 1.448220, -2.341660, -0.873040, -2.507080, 0.609110, 0.623990, 0.471440, -13.149570, -0.174240, 
-0.041120, -0.372900, -6.538660, 1.644450, 0.172330, -15.320150, -2.812240, 1.958120, 0.703780, 0.043050, 
-0.051630, -0.765270, 0.744200, -0.573200, 0.195510, 0.072160, -2.352450, 0.815640, -0.028840, -1.255970, 
0.843120, 0.121490, -0.239770, 0.296920, 0.726240, -0.059020, -0.222840, 0.091360, 1.039860, -0.169590, 
1.213520, -0.783410, 1.146180, 1.756220, 2.992500, 0.565280, 0.369030, 1.084600, 0.108350, -1.114470, 
-0.383890, -0.999440, 2.142640, 1.348530, 0.700520, -1.590400, 0.345270, 1.045780, -2.097200, 0.074310, 
0.281510, 0.699190, -0.220270, 1.166830, -1.933100, -0.506270, -3.139400, -0.660220, -0.131730, -1.145960, 
-0.855770, 0.994070, -1.551260, -1.759780, -0.893370, 1.561690, -0.644450, 0.504790, 0.675460, 0.256850, 
1.067680, -0.514040, 0.054970, -0.195090, 0.483250, -0.185530, 0.795580, 0.773610, -2.449470, 0.918380, 
0.763980, -0.808260, 0.615400, 0.749770, -1.630550, -1.488680, -1.673950, -1.715780, -1.133140, 1.207900, 
-1.062630, -0.652890, -0.352380, -0.369100, -1.044260, 2.483990, -0.832970, -0.063570, -0.643190, 1.208810, 
-0.851850, -0.609590, -0.723300, -0.429980, -0.687170, 0.118630, -0.236180, 1.639850, 0.798290, -0.205410, 
-0.457980, 0.218210, -2.271420, -0.414030, -0.076640, -0.783650, 0.013140, 0.454200, -0.020070, 0.390520, 
3.704410, 0.194270, 0.932900, -13.695060, 0.930050, -0.371420, 0.576790, 0.176670, 0.422700, -0.685810, 
0.765480, 1.954260, -1.566800, 1.035410, -0.621430, 0.454610, -0.337320, 0.629620, 0.140390, -0.056260, 
0.110730, 1.287970, -0.895580, -0.075680, -0.026960, -0.041550, -0.891340, -0.297160, 0.930710, 0.458140, 
0.482060, -0.085050, -0.570140, -0.440250, -0.193820, 0.083690, -1.067390, 0.909390, -0.238810, -0.442700, 
-0.190340, -0.112630, -0.556620, -1.168990, -0.421550, -0.431980, 0.318240, -0.692090, 0.221150, 
0.897360, 0.848110, -0.478330, 0.715560, -0.115000, 0.966870, -0.064460, -0.508020, 0.871160, 0.097660, 
0.063810, 0.813040, -0.153820, 2.092050, 0.408390, -0.308670, 0.835370, 0.709590, 0.250450, 0.425110, 
1.115180, -0.126460, 2.125300, 0.309450, -1.129970, 0.322370, -0.647590, -1.492260, 0.526950, 0.033720, 
0.043730, -0.138100, -1.023780, -0.101020, 1.102720, 0.900680, 1.220120, 0.555110, -0.631830, 1.653130, 
-0.364850, -0.593080, -0.292440, 0.216200, 0.924740, -0.600430, 0.083700, -0.356580, -0.982950, 0.340830, 
0.862430, -2.637980, 0.023050, -0.337960, -0.399390, -0.517020, -0.411230, 0.433860, 0.548820, 0.650440, 
-0.048070, -0.012000, 0.381410, -0.029910, -0.845710, -0.746400, 0.879960, 1.018730, 0.045110, 0.809360, 
0.885820, -0.331490, -0.117140, -0.292890, -2.869520, 0.165880, -0.214740, 1.294070, -0.995140, 0.673080, 
-0.144740, -0.136930, 2.185050, 1.824020, 1.416100, -0.369070, -0.955740, -0.009490, 0.229140, -0.895840, 
-0.280490, -0.612100, 1.020380, -1.869230, 0.917710, 1.355640, 1.032720, 0.556090, 0.617190, -0.220140, 
-0.485140, -1.180820, 1.819420, 0.227120, 0.183070, -0.217420, -0.783690, 0.260090, -0.236110, -0.256130, 
1.046960, 1.335680, 1.005690, 0.227320, 0.810050, -0.799690, 0.889910, -1.411100, 1.037080, -2.106660, 
-0.608550, 0.009290, -1.972360, -0.635660, -0.884990, 2.437890, 1.245290, 1.373020, -0.563550, -1.409620, 
0.126390, 2.143320, -3.581080, 0.746190, -1.170040, -1.309130, -1.208000, 0.531170, 0.426500, 0.088820, 
-0.149020, 0.374880, -0.904090, 0.901000, -0.144850, -0.545380, -1.580130, -1.030920, -0.374180, 1.563220, 
-0.215490, 0.572270, -5.205600, 2.446210, 0.632760, -1.559030, 1.142490, 0.660820, 0.023290, -1.295990, 
-1.082780, -0.135100, -3.149160, 1.026880, 0.029650, 0.757030, -0.341450, 0.364910, -1.568560, -0.585760, 
2.100060, -0.108780, 0.320300, 0.201060, 0.042170, -0.304800, 1.425760, 0.304040, 1.382990, 0.438350, 
0.077510, -0.263910, 0.007990, 1.237430, -0.695680, -1.003630, -0.071910, 0.887550, -1.514570, 0.175190, 
0.031040, 0.939290, 1.532230, -0.334180, -1.716440, -0.577830, 0.020150, 0.066920, 0.326970, -1.062360, 
1.706700, -0.978410, 0.755520, -0.048970, -0.488140, -0.578530, -1.228300, 0.139110, 0.537700, 0.738720, 
0.910690, 1.124050, -1.640530, 0.679850, -1.060920, -0.686630, 0.438070, 0.697840, 1.442600, 0.047880, 
0.817520, -0.582080, -0.258360, 1.122760, -0.293810, 0.073650, 0.227190, 0.814510, -2.333720, -2.217830, 
0.342360, -1.122130, 1.064020, 0.133350, -0.019370, 0.864560, -0.199600, -3.454600, 0.044650, -0.299840, 
-0.828650, 1.727490, 0.779800, -0.108780, -0.503920, -0.776430, 1.119990, 0.593210, 1.214580, 0.265330, 
-0.348230, 2.456060, -1.713630, -0.003560, -0.182260, -0.783380, -0.522280, -0.453960, 0.806110, 0.256200, 
-1.266850, 1.512710, 1.385580, 2.597610, -0.779500, -0.176430, -0.573270, -0.270940, -0.573010, 0.151440, 
-0.754300, 0.453880, -0.366050, -0.247650, 0.923520, -0.741880, 0.671260, 0.362510, 0.098550, 0.183060, 
-0.167570, 0.836690, 0.100000, -0.550060, -0.181620, -0.625460, 0.433790, -0.291970, -0.559520, -0.509300, 
0.631360, 0.758410, 0.071710, 0.929310, -0.611060, 0.011750, -0.859070, 0.976320, 3.017630, 
-1.285210, -1.319330, -0.006170, 0.452570, -0.065210, -0.030330, 0.808060, 0.057370, -2.123330, -0.671730, 
-0.559400, -0.638870, -0.423390, 1.597650, -0.193280, 0.808360, 0.844380, 0.570830, 1.052360, -0.530290, 
3.361420, 0.241990, 4.163060, -0.338120, -0.118400, -0.314620, 0.609810, -0.397480, 0.314360, 0.438070, 
1.914720, -0.494210, 1.359570, 0.541350, -0.878780, 0.096340, 1.386860, -0.916360, 1.710770, -0.025920, 
-0.857940, 0.624290, 1.068530, 1.881570, -0.679680, 0.761450, 1.008090, 0.217240, 1.640350, 0.104500, 
-0.749790, -1.873350, 0.477130, -1.087150, 0.500060, 1.571920, 0.781420, 0.145980, -0.125860, 0.513850, 
-1.134100, -0.328950, -0.281950, -0.157100, -0.071420, 1.674250, 1.442120, 0.349100, 0.033530, -0.204760, 
-1.303760, -1.222020, 0.884190, -1.453450, -1.446780, 0.660840, -0.743020, -2.750250, 0.884740, 1.067350, 
1.052860, 0.530260, -1.208260, -0.304900, -2.668730, 1.720380, 0.107050, 1.238780, 1.109860, 0.668000, 
1.954470, 2.283430, -0.546950, -0.815850, -1.276170, 0.807060, -0.812860, -0.090410, 0.456860, 1.034720, 
0.396740, -0.085580, 0.156990, 1.021740, 1.023820, -0.268070, -0.577370, 0.568010, -1.539340, 0.109770, 
0.191890, 1.007520, 2.111700, 0.406190, 0.584570, 0.301870, -1.221040, -3.069860, 2.835180, 0.645140, 
-1.965070, 0.826420, -0.848680, -1.370710, -4.882720, 0.446320, 1.387460, 1.165400, -1.726570, 0.235130, 
0.036460, 1.018670, -0.814480, 1.442010, 0.023910, -1.561970, 0.895370, -1.224300, 0.522010, -0.308780, 
0.790420, -0.372750, 0.657540, -0.029530, 2.468420, 1.029820, -0.705070, 1.027980, 0.159980, 0.821620, 
-0.093540, -0.941820, -1.144790, -0.486560, 0.266790, 0.005450, -0.112990, 0.130070, 1.282940, 0.688000, 
3.650090, 1.251670, 0.888850, 0.084800, 1.639080, -0.226500, -1.201490, 0.010260, 0.272710, 0.066140, 
0.375850, 1.458950, -0.012210, -0.658240, -0.189280, 0.432950, 1.747480, -1.016210, 0.459860, 2.177380, 
0.655160, 0.452220, -0.079890, -0.335990, 0.007370, -1.210060, -0.480010, 0.849740, -0.792960, 0.075240, 
1.566170, -1.035080, 0.380200, -0.314510, -0.487460, -0.446130, 0.062930, 1.815420, -0.515490, 1.279450, 
0.104370, 0.652290, 0.415200, -0.204430, 0.332340, 0.342130, 1.128850, 0.448510, -0.419850, -0.743610, 
0.581080, -0.891760, 0.103280, 0.621990, -1.154830, 0.705310, -0.994300, -0.505800, 1.124470, 0.337990, 
1.494710, 0.411470, -0.977760, 1.088910, 0.240060, -0.227830, 1.048160, 1.097680, -0.959700, -0.345000, 
-2.250000, 0.861840, -0.175550, 0.916940, 1.732470, -0.724740, 0.136450, -0.106340, 0.641970, 0.829560, 
0.085410, -1.127170, 0.753840, 1.344620, 0.649730, 0.068680, -0.264520, 0.047960, -0.103100, 1.202140, 
2.362440, 1.504140, 5.223520, 0.160530, -0.192000, -1.498940, 0.710460, 2.588920, -1.296690, 0.621060, 
0.102220, 1.027520, -1.931860, 0.935800, -1.265540, 3.114490, 0.823850, -0.745340, -0.261130, 0.545390, 
-0.195020, 0.014840, 0.039350, -1.059700, 0.776340, 0.536430, 1.136310, -0.213180, -0.403470, -0.813440, 
-0.432840, 0.507670, 0.471420, -0.445970, 0.449870, -0.338020, -0.584590, 0.498740, 1.111080, -0.645610, 
0.721600, 1.129780, -0.552240, 0.777000, 1.269760, 0.127940, 0.414630, 0.761350, -0.659870, 
-0.331020, 0.272390, -0.661820, 0.772910, -0.625610, 0.924930, -0.113100, 0.502900, -0.080800, 1.137000, 
0.959390, 1.234580, -0.190950, -0.223750, 0.252490, -0.055150, 1.048450, 0.888960, -0.477260, -0.066440, 
-1.714810, -1.195960, 1.142060, -0.816770, -1.264640, 0.335120, 1.429330, 1.205290, -0.695280, 0.783300, 
0.027720, -0.691350, 2.027670, 1.006770, -1.223080, 0.138630, -1.362550, 0.221280, 0.384180, 0.255980, 
-1.056690, -0.257290, 0.085900, -0.624720, -0.909230, -2.002980, 0.254600, 0.064690, -0.037860, 2.343660, 
1.200480, 1.279190, 0.250560, -0.521370, 0.447940, 1.682850, 0.964390, -2.236660, -0.837730, -3.125140, 
0.963790, 2.161690, -0.602440, 0.325240, -0.121830, 0.943380, -1.321220, 1.310220, -0.087580, 0.193180, 
0.228400, -0.112680, -0.106420, 0.746820, 0.621760, 0.278320, -0.436850, -0.246280, -0.123300, -0.008760, 
-2.246700, 1.576840, -0.226240, -0.253700, 0.444280, 1.711720, -0.148950, -0.538210, 0.733760, -0.159180, 
1.012260, -1.560530, 0.361080, -0.725650, 0.214620, 1.081640, -0.833140, 1.060220, 0.608830, -0.089050, 
-0.134080, 0.342530, -0.776660, 0.810690, 0.498040, 0.451920, 1.050470, 0.017730, 0.011290, 1.016020, 
1.008410, -0.343360, -1.976730, -0.614380, -0.232230, 1.580120, -0.088710, 0.113200, 1.886340, 0.718750, 
0.577920, -0.687130, -0.092840, -0.527730, -1.498620, 0.588240, -0.419790, -0.281910, 2.440440, 0.865370, 
-4.208680, -0.115790, 1.506550, -1.702370, -1.004460, 0.458860, -0.461640, -0.354600, 1.632130, -0.942070, 
-1.721400, -0.924840, 1.272730, -0.141510, 0.571790, 0.488190, 0.324470, -0.231640, 0.493580, 0.544360, 
0.898240, 0.376260, 0.420770, -1.028550, 1.452090, 0.208210, 0.577170, -0.003160, -0.042700, -0.380240, 
-2.002750, 0.931230, 3.729040, 0.736140, -0.691540, 1.437280, 0.720260, -0.414280, 2.121830, 0.000050, 
0.337550, 0.930310, -2.636490, -0.067530, -1.524470, 0.203110, -1.197000, -1.766840, 0.799390, -1.252350, 
-0.626560, -1.166360, -0.291610, 3.179500, 0.758420, 2.835670, -3.226340, -3.081630, -2.175960, 2.235220, 
-0.268730, 1.330190, -0.765670, -0.273100, 0.846180, 1.715770, 1.705090, -1.484890, -1.044770, 0.051240, 
-0.440520, 0.239930, -1.102090, -0.196360, -1.101560, -0.894400, 0.488770, 0.330480, 0.949640, 0.543780, 
-0.152900, -0.994350, 1.499250, -0.691810, -0.023610, -1.338500, 0.100690, 1.166720, 0.332370, -1.015590, 
0.620890, -0.321550, -0.243680, 0.021560, 0.737780, -1.787810, 0.482870, -0.472710, -0.300310, 0.712120, 
-0.178430, 0.090950, 0.108110, -0.583850, -0.075330, 0.975780, -0.382700, -0.201740, 0.182480, -0.433390, 
0.655820, -0.113590, 0.817790, -0.539300, 0.642090, 0.406100, -0.327730, -0.071210, -0.015960, -0.391670, 
-1.002640, -2.092560, -0.476810, -27.966049, -0.952220, 2.548560, -0.669890, -0.708090, 0.320730, 0.256730, 
0.223460, 0.265730, -0.068210, -1.391710, 5.000920, -1.519750, -1.620280, 0.244760, 0.422110, -0.660820, 
-0.820850, -1.398160, -0.764580, -3.403900, -1.200480, -1.018920, -0.368720, -1.614860, -1.733000, -1.719080, 
-0.328630, -0.698140, -1.879450, -7.348600, -0.039030, -1.700780, -0.873080, -1.577340, 0.304190, -2.577180, 
-4.172130, -1.831820, -1.073830, -0.325820, -0.683990, -2.275810, -0.485800, -1.183460, -0.843420, 
-1.222130, 0.960470, -0.538150, -0.548550, 0.928550, 0.135840, -0.618290, 2.050220, 0.710650, -0.186720, 
0.895590, -0.822270, 0.543260, 0.986230, 0.517160, 1.943830, -0.327730, -0.686830, -0.296690, -0.999200, 
4.219230, -0.387070, 0.366220, -0.508060, -0.816590, 0.645480, 2.161350, 0.788190, 1.235310, -3.783250, 
-0.221370, -0.333130, 1.591490, 0.425230, 1.239170, 0.001840, -0.837670, -0.591090, 0.204250, 0.666440, 
-0.419060, -19.027590, 0.112520, 0.631240, 0.468130, -0.239410, 0.479530, -0.062170, -0.002440, -0.943550, 
-0.348910, 0.520890, 0.412140, -0.021320, -0.985080, -0.361440, 0.463910, 0.093760, -0.212650, 2.000720, 

-1.010220, 0.087180, -0.125250, 0.892010, -0.857360, -0.553340, 0.137280, -0.464440, 0.484790, 0.524290, 
-0.588960, -0.385810, 0.002120, 0.368620, 1.239230, 5.482000, -0.692940, -0.487270, -0.792340, 0.984300, 
0.491820, 1.009050, -0.476170, -0.269980, -0.806980, 1.207600, 1.961300, -0.257760, -0.520970, -1.255080, 
-0.464370, -0.672580, 0.532440, 0.263510, 0.949270, 0.584370, -0.303780, 0.459670, 0.726790, 0.483600, 
-0.479630, -0.718340, 0.672570, -0.826680, 0.195680, 0.525520, 0.772770, 0.938640, -0.331660, -0.111890, 
0.088780, -0.663180, -0.433760, 0.600210, -0.102220, 0.110810, 0.582840, 0.905550, -0.706690, 0.139620, 

12.611740, 36.758251, 5.414730, 36.346199, 2.768320, 4.835120, 11.572110, 4.591960, 3.616250, 36.041061, 
0.177140, 37.107971, 3.830940, 36.999271, 268.396942, 0.083130, 37.354061, -1.511900, -0.948200, -1.050630, 
12.148510, -0.761230, 5.071490, 0.103730, 36.292740, 0.949890, 3.984630, 107.144203, 37.351231, 103.174438, 
12.011300, 106.882584, 4.195760, 106.754356, 12.554900, 1.555060, -1.269370, 105.578003, 0.767780, 12.617800, 
13.274210, 0.802010, 36.398331, 36.367882, 4.112870, 36.783699, 1.319670, 12.391570, 12.891980, -0.750870, 
35.438141, 36.129768, 12.073770, 35.615669, 35.745800, 36.079990, 3.114940, 36.655201, -0.500690, 4.731060, 

78.191109, 26.416309, 229.056458, 77.510674, 27.884350, 27.778919, 78.430458, 26.591000, 79.328934, 79.224739, 
26.355610, 78.924080, 77.563148, 79.348457, 73.147247, 78.960548, 78.723099, 26.063360, 8.751060, 78.041527, 
26.414230, 79.067688, 229.140732, 78.175407, 78.695442, 78.888947, 26.933680, 79.901733, 78.184227, 227.713715, 
77.735497, 77.485764, 8.949950, 8.710650, 220.694641, 27.271250, 77.560699, 25.598761, 77.854736, 25.947281, 
78.422691, 78.167747, 77.512009, 78.951469, 79.237953, 77.647293, 78.048576, 79.328796, 78.266518, 78.483238, 
79.024559, 79.184410, 77.501106, 78.217812, 78.963608, 77.902924, 77.895279, 78.636871, 77.465401, 27.115271, 

-0.721400, 0.022090, 1.702890, 4.547580, 2.286780, -0.051320, -0.029400, -0.380550, -0.825770, 1.467970, 
0.211710, 1.694940, 3.593850, -0.102140, -4.594430, -0.309480, 3.962390, 2.819850, 2.603820, -1.563150, 
-0.349480, -1.470450, -0.015100, -0.575220, 0.961330, -0.076960, -1.222060, -1.159430, -0.918540, -0.969000, 
-0.086200, 0.042270, -0.451330, -0.098450, -1.033180, -0.964130, -3.929850, -1.945980, 1.071570, -1.602180, 
1.378520, -2969.255859, 0.115290, 0.566870, -0.147250, -0.770930, -99.351357, 5.878690, -2977.750000, 1.072660, 
0.602590, 1.807300, -0.644240, -0.545340, -0.470350, 0.787500, 0.599560, -0.949860, -1.262290, -1.487330, 

-0.820420, -0.874420, 0.722380, -0.842200, 0.513330, -0.235050, -0.575660, 0.927640, 0.934150, -0.950120, 
-0.090110, 0.313500, -0.177850, -0.144560, 0.876660, -0.676310, -0.886790, -0.670890, 0.531810, -2.090080, 
0.061650, 1.182260, 0.611740, 0.391450, 0.755990, 0.589110, -0.352960, 0.338380, -1.639670, -66.858963, 
-0.553350, -0.966950, 1.252190, 0.769490, 0.463330, 0.295650, 0.521840, -0.061100, 0.247520, -0.973080, 
0.741360, 0.548340, 0.827530, -0.265930, 0.120880, -1.054420, 0.307060, 0.815320, -0.569500, -0.998200, 
0.850330, -0.413910, -0.726300, 0.085260, -1.019400, -0.913130, -0.859120, -0.551920, 0.421660, -0.183830, 

-0.542090, -0.558300, 0.769460, -0.045560, 0.225770, 0.680630, 0.801990, -0.749350, -0.549780, -0.276190, 
0.357810, 0.271090, 0.180040, -0.194640, -0.663340, 0.039420, 0.051920, 0.118810, -0.757970, -0.327060, 
-0.959450, -0.596540, 0.582420, 0.050400, -0.878030, -0.739580, 0.973410, 0.815910, -0.563640, -32.291851, 
0.101990, -0.486350, -0.630010, -0.417340, -0.519100, -0.302450, -0.452240, 0.678820, -0.708360, -0.611280, 
0.817650, 5.245520, 0.449980, 0.832100, 0.476270, -0.968610, -1.428110, 0.648960, 1.276780, 0.847520, 
-0.092070, 0.588840, 0.310800, -0.094310, -0.155200, -0.619100, -0.828890, 0.215370, -0.639300, 0.396670, 

-0.951960, -1.030400, 0.230130, 0.426710, -0.604310, -0.721130, -0.945040, -0.418420, 0.368760, 0.348800, 
-0.259490, 0.853740, -0.692940, -0.072430, 0.152350, -0.614870, -1.093230, 0.868400, 0.177630, 0.513040, 
0.448990, -0.392540, -0.175620, -0.402950, -0.113330, -0.561780, -0.255870, -0.848470, 0.762530, -0.494580, 
-0.529500, 0.355190, 0.478780, 2.489520, 0.346720, 1.094070, -0.703490, 0.889170, 0.253230, -0.796910, 
-0.118620, -0.534000, 0.284120, 0.284420, 0.250240, 0.164190, -9.258610, -0.361750, 5.943430, 0.124730, 
0.014850, 0.037420, 0.753780, -0.881860, 0.298130, -0.018890, -0.172460, -1.060150, 0.511190, 0.410790, 

-0.403160, -0.506320, 0.057400, 0.958870, 0.449810, 0.860800, 0.338170, -0.459670, 0.731240, 0.368350, 
-0.048100, 0.468380, 0.849700, 0.149580, 0.591370, -0.864420, 0.284050, 0.882810, 0.901120, -0.790300, 
-0.277660, -0.601620, -0.843530, 0.783880, -0.469870, -0.361490, -0.194190, 0.208280, 0.090800, -0.868620, 
-0.945510, -0.660010, 2.984800, 0.015060, -0.199200, -0.471460, 0.083430, -0.370680, 0.698640, -0.593680, 
0.521140, 1.881850, -0.967160, 0.024880, -0.157370, -0.313850, -0.623390, 0.096890, 1.545190, 0.031010, 
0.500400, -0.825230, -0.757940, -0.619180, 0.649760, 0.365400, -0.156790, -0.412830, -0.623500, -0.447320, 

-0.232690, 0.398390, 0.904020, -0.716120, 0.313840, -0.922580, -0.048710, -0.445080, 0.277340, -0.036500, 
0.609040, 1.010220, -0.775860, 1.278130, 0.879780, 0.050420, -0.598070, -0.553460, -0.646350, -0.623340, 
-0.818370, 0.752190, 0.946580, 0.849370, 0.563350, 0.984520, 0.172880, -0.758620, -0.296040, -2.235680, 
0.239350, -0.802130, 9.071580, -1.023210, -0.794700, 0.271960, 0.819360, 0.355290, 0.332810, -0.553580, 
0.414960, -2.414790, -0.639760, -0.657570, -0.372140, -0.099100, 0.469490, 0.390510, -0.584150, -0.018720, 
0.046490, -0.253060, -0.333950, -0.223410, -0.618220, -0.802870, -0.015640, -0.784530, -0.817200, 0.090800, 

-0.829960, 0.198810, 0.778240, 0.070910, -0.400740, -0.550510, 0.435300, -0.213870, -0.359240, 0.283460, 
-0.035890, 0.149490, -0.272770, -0.265520, -0.357950, -1.486810, -1.316020, -0.569760, 0.979970, -0.337590, 
0.604900, 0.262140, 0.008080, -0.285120, -0.913460, -1.231720, -1.342360, 0.589000, 0.746030, 0.439720, 
0.317670, -0.342400, 3.942710, 0.348130, 0.071380, 0.204040, 0.427440, -0.831860, 0.129350, -0.279130, 
-0.893800, -0.667770, -0.464900, 0.707880, 0.426310, 0.183920, -0.195900, 0.192940, -0.266190, 0.079430, 
0.411760, 0.312640, -0.039040, 0.250410, -0.003730, -0.158150, -0.378380, 1.318930, 0.625030, 0.570350, 

0.630960, -0.657820, 0.373450, 0.343090, -0.783640, 0.686010, 0.345540, 0.271850, -0.793320, 0.974940, 
-0.243840, 0.186700, -0.639960, 0.539620, -0.512970, 0.599570, -0.703560, 0.101440, 0.558860, -0.283730, 
-0.552380, 0.084310, 0.984470, -0.098310, -0.877290, 1.301810, -0.023160, 0.670260, -0.590130, -0.794290, 
0.175440, -0.071880, -406.349365, -2.736870, -0.255820, -0.060160, 0.080690, -0.643040, 0.972560, -2.831750, 
0.029230, -0.198250, 0.904350, 0.640760, -0.283120, -0.952700, -0.246440, -0.841680, -216.712601, -0.092370, 
-0.727610, -0.033390, 0.773070, -0.505930, -0.123100, -0.588510, -0.267030, 0.058810, -0.452410, -0.296700, 

-0.169450, 2.974640, -0.018780, 1.193440, 1.249230, -0.085660, 0.422940, 57.050308, 0.013660, 0.333080, 
-1.887980, 0.889460, 0.383740, 0.778500, -1.546830, -3.362040, 0.936050, -0.024930, 0.580430, 0.588340, 
-0.938440, 1.120780, 2.309260, -0.185750, -0.186950, -1.362800, 7.251700, 0.957400, 0.623000, 0.417510, 
0.840170, 0.342360, -1.462080, 0.196390, -0.398450, -0.174190, 0.320450, -0.318020, 0.237640, 0.290810, 
-0.324580, -30.735979, 0.787980, -0.079960, 0.839060, 0.832870, 0.106990, 0.146680, -90.772690, -0.245150, 
-0.259480, -0.403420, 0.701650, 1.075170, -0.690120, -0.008170, -0.262380, 0.799160, -0.471010, -0.286460, 

0.912460, 2.352490, -0.221670, -0.008670, -0.485930, -0.642140, 0.223210, -0.705240, -0.985510, 0.651160, 
0.689650, 0.433680, -0.560630, 0.111670, 5.936220, 0.913040, 1.131450, 1.009170, -0.251840, 0.257230, 
0.540220, 0.520630, 0.990430, 0.469950, -0.489860, 0.144080, 0.060500, 0.453910, -0.040710, 0.823560, 
-0.628300, -0.607150, 2671.406738, 2.117130, -0.323490, 0.112660, 0.184010, -0.025700, 0.690340, 2.214760, 
0.619600, -0.421280, -0.509790, 0.898810, -0.519400, 0.873890, 0.528710, 0.917140, 4.481740, -0.017720, 
0.716440, 0.007680, -0.800310, 0.095100, -0.494540, 0.204820, 0.046600, 0.563540, 0.477860, 0.172920, 

-0.692700, -0.596450, -0.080530, 0.843220, -0.445280, -0.952910, -0.526420, 0.707040, 0.177840, -0.147190, 
0.738150, -0.895240, -0.448370, -0.859410, 0.888880, 0.543870, -0.214870, -0.571230, 0.787170, -0.356980, 
-0.975670, 0.576990, -0.187200, 0.456440, -0.347990, 0.908660, -0.150920, -0.939740, -0.095670, -1.041200, 
-0.386180, -0.691100, 269.891571, 0.112030, -0.215370, 0.099160, -0.947900, -0.769660, -0.560730, 1.025770, 
0.869530, 1.185910, -1.031360, 0.383610, -0.970010, 0.872650, -0.061470, -0.714550, -1.053250, 0.637220, 
0.405830, 0.773300, -0.354500, -0.278070, -0.427140, 0.900720, 0.147760, 0.607510, 0.032800, -0.559300, 

-0.152290, -0.411210, -0.422360, 0.817700, -0.199130, 0.146120, -0.058610, -0.645380, 0.677630, -0.172490, 
0.003450, -0.747390, -0.198440, -0.100680, -0.768120, -0.650560, 0.675780, 0.678420, 0.919240, -0.830330, 
-1.105880, -0.112200, 0.494030, -0.079000, 1.270990, -0.158340, -0.998440, -0.996970, 0.613340, -0.207450, 
-0.872270, 0.796210, 0.033440, 0.158840, 0.520480, 0.826340, 0.729870, -0.849380, 0.450800, 0.335850, 
0.873820, 0.655500, 0.092440, -0.487090, 0.948400, -0.699710, -0.359460, 0.367270, -6.331680, 0.141410, 
0.291600, 0.009750, -0.153000, 0.850270, 0.200500, -0.487880, 0.074710, 0.819520, 0.102580, -0.971880, 

0.644840, 0.777150, 1.363170, -0.302000, 0.746490, -0.827420, 0.232340, 0.822420, 0.888780, -0.199850, 
-1.545920, -0.502850, -17.151300, -0.499390, 2.363700, 0.657760, -0.085070, -0.013690, 0.486410, -3.734860, 
0.818910, 2.634210, -0.140770, -1.978660, -0.686340, 0.110410, 0.611630, -0.662420, -0.597350, -58.596680, 
0.585880, -0.596590, -5.980090, -0.062790, -0.778650, -16.852249, 0.780630, -0.157300, -0.859990, 0.256350, 
0.203270, 1.571750, 0.350920, 0.066970, -1.012320, 0.598170, -0.074530, 0.838860, 3.979760, -0.078580, 
-0.131130, -0.465660, 0.380540, 0.170800, -0.687960, 0.750080, -0.145370, 0.684760, -1.226040, 3.150330, 

0.755000, -0.843470, -0.356610, 0.575740, -0.853530, 0.755310, 0.014070, 0.756150, -0.776510, 0.583240, 
-0.127560, 0.379090, -2.943640, 0.456790, 0.791820, 1.409910, 0.152640, 0.054630, -0.276690, -0.369970, 
-0.770840, 0.646090, 1.082840, -0.531960, -0.796760, -0.272160, -0.118080, 0.832470, 0.666910, 0.686390, 
0.577300, -0.918820, 1.648740, 0.175080, -0.427040, -8.840700, -0.533230, 0.677610, 0.301500, -1.121240, 
0.295950, -3354.537842, -0.943970, -0.858210, 0.475510, -0.434110, 18.403990, 2.406730, -3934.797363, -0.067140, 
-0.196770, 0.345170, 0.920370, -0.995260, -0.713610, -0.981480, -0.577230, -0.504590, 0.682610, -39.367199, 

-0.412660, -0.676330, 0.694670, -0.102750, -0.379110, -0.697120, -0.285880, -0.748080, -0.894240, 0.517280, 
1.056540, 0.313810, 0.391430, 0.078700, 0.268610, -1.399740, -0.601250, -0.838100, 0.062820, -0.765580, 
0.854750, 0.715950, 0.332670, -0.060900, -0.616030, 0.238800, -0.220590, -0.511090, 0.639580, 1.011420, 
-0.531430, -0.797870, -147.425232, -0.581860, 0.465870, -37.666859, -0.603950, 0.137380, -0.502200, -0.600870, 
-0.789310, -3.010440, -0.821880, 0.911810, -0.948780, -0.543420, 61.482189, 1.504880, -26.488939, -0.797860, 
-0.817470, -0.076260, 0.992180, 0.298120, 0.486090, -0.199850, 0.222260, 0.150630, -0.123520, -1.006280, 

-0.640160, 1.031280, -0.999220, -0.437080, -0.321980, 0.761280, 0.043470, -0.142620, -0.048930, -0.130550, 
0.201270, -0.402690, 0.599590, 0.078000, 0.713350, -0.543320, -0.075490, 0.890080, 0.159650, -0.866090, 
-0.290840, -0.929860, -0.865480, 0.827510, 0.426640, 0.823540, -0.035970, 0.145690, -0.765060, -0.071300, 
0.870970, -0.816470, 0.066750, 0.808960, 0.035140, -0.398220, -0.052020, 0.118130, 0.857190, -0.344800, 
-0.034250, 1904.656494, 0.537190, -0.595830, -0.657460, -0.726700, 2.857380, -0.774110, 3063.905029, -0.953640, 
0.441740, 0.889400, -1.005730, 0.096030, -0.872280, 0.877570, 0.061650, 0.828910, 0.432440, 0.871030, 

-0.547730, 0.767970, 1.675650, 0.759060, 1.827930, 0.449870, 0.938200, -0.162210, 0.437750, -0.544640, 
0.671850, -0.595610, 0.469390, -0.597860, -0.077590, -0.208780, -0.269980, 0.560010, 0.021710, -0.858770, 
1.196920, -1.235400, 0.322680, -0.792600, 0.825980, 0.396870, 0.560420, 0.895760, -0.863190, -0.956420, 
0.042940, 0.925130, -1.513030, -0.756770, 0.375190, -0.915230, 0.652670, 0.786260, 0.233710, -0.125380, 
-0.720620, -0.154660, 0.659100, 0.175260, -0.554040, 0.557560, -0.241820, -0.548450, -2.843910, 0.328170, 
0.607040, -0.949170, -0.334550, 0.158770, 0.274630, -0.629610, -1.032460, -0.435910, 0.404830, -0.722590, 

-0.113420, -0.370890, -0.404380, -0.495650, 0.671940, -0.801090, 0.941660, -0.150900, -1.071750, 0.733520, 
-0.364040, -0.892570, 0.132210, 0.997610, -0.759980, -0.187800, -0.668620, -0.204210, -0.395490, -0.526530, 
-0.484280, 0.595290, 1.014620, -0.490500, 0.694110, -0.516100, 0.203130, 0.740530, 0.829850, 0.038850, 
-0.032650, 0.582190, 1094.502441, 2.417610, 0.843580, -0.055020, 0.989580, 0.072940, -0.400150, 0.529580, 
0.402230, -0.745560, -0.357860, -0.297230, -0.476700, -0.137670, 0.165210, -0.300150, 0.748060, -0.049180, 
-0.339140, -0.266280, 0.881040, 0.008850, -0.745620, 0.034370, -0.292560, 0.920150, 1.013770, -0.276530, 

-0.033300, -0.349360, 0.155840, 0.966250, -0.580400, -0.002060, -0.137940, -0.477100, 0.175540, -4.490200, 
1.173680, 0.860160, -0.568570, 0.578450, -0.840390, 0.993530, -0.611150, -0.636000, 0.059870, 0.538110, 
-0.996140, 0.539510, 0.714860, -0.787350, 0.231070, -0.319060, 0.437810, -0.281410, 0.644150, 0.570160, 
-0.144060, -0.679010, -0.097830, -0.651590, -0.977670, -1.010570, -0.007590, -0.414130, -0.278780, -0.688820, 
0.496780, 568.912598, 0.541720, 0.458280, -0.024840, -1.081370, -2.808810, -0.403280, 1161.144409, 0.801490, 
-0.046740, 0.210550, 0.234690, -0.889070, -1.013000, 0.514620, 0.214770, -0.583050, -0.705810, -1.024520, 

-0.778070, 0.918320, -0.474300, -0.419490, 0.272590, 0.042340, -0.624640, 3.748400, 0.764760, -0.489910, 
4.902510, -0.236030, 0.093980, 0.627130, 0.997080, 0.699400, -0.249950, 0.805660, -0.055540, 0.023340, 
0.184380, 0.301090, 0.255220, -0.500290, 0.153700, 0.638600, -2.231640, -0.492440, 1.023100, -0.287800, 
0.485430, -0.168240, 1.705510, -0.543290, -1.035020, -3.222950, -1.975640, 0.381840, -0.966310, -0.536320, 
0.600540, 0.493780, 0.732730, 0.178170, -0.196860, -0.185820, -2.781880, 0.128190, -1.907370, 0.568100, 
-0.620850, 0.432430, -0.028060, -0.816080, 0.801290, 0.557280, -0.894120, 0.404820, -0.106320, -0.872240, 

-1.554570, 1.209410, -1.344680, 0.078570, -0.185780, 1.098810, 0.638440, 0.789300, 0.536600, -0.238460, 
-0.128250, 0.716280, -1.754480, 0.117360, -0.964630, -7.540400, 0.793450, 1.063190, 2.051060, 0.860030, 
-1.430910, 4.487260, -1.944160, 1.122400, 0.422010, 0.357490, 0.985010, 0.045760, -0.367330, 0.325450, 
0.762450, 1.144610, 1.407000, -0.698310, -0.162530, -2.085610, -6.424500, 0.413680, 0.182380, 0.469300, 
0.660690, -20.404751, -0.595180, 1.052680, 0.028310, 0.474690, -11.615740, -0.927450, -20.800711, 0.436600, 
1.051470, 0.778830, -0.980870, 1.147860, 0.799140, -0.362150, 3.867570, 0.190400, -2.391670, 1.492970, 

-0.589460, -0.001090, 0.822440, -0.237580, -0.548520, 0.330970, 0.235160, -0.000870, 0.199320, 0.732890, 
0.666550, 1.076370, -0.059050, 0.350020, 0.243060, -0.199200, -0.349310, 0.723360, -0.692470, 0.021010, 
-0.688490, -0.158430, -0.075310, 0.627140, -0.152990, -1.306660, 0.515840, 0.982730, 0.130720, -2.911520, 
-0.810490, 0.737730, 0.549790, 0.265500, 1.202170, 0.856010, 0.071140, 0.281300, -0.250350, -0.075970, 
-0.904520, 0.101490, -0.610860, -0.788140, -0.096510, 0.770330, 0.899410, 0.980430, -3.561330, 0.248120, 
0.621060, -0.023060, -0.837950, -0.018700, 0.330960, 0.751470, -0.138180, 0.072800, -0.274680, -1.605840, 

-1.002170, 0.369440, 0.232530, 0.632290, 0.145440, 0.050880, -0.713680, 0.534820, -0.037160, -0.459110, 
0.701700, 1.002190, 0.873630, 0.464200, -0.292450, -0.777760, 0.367790, -0.830310, -0.940630, 0.620970, 
-0.866570, -0.754080, 0.577360, 0.597790, 0.657200, -0.561220, 0.637890, 0.581240, 0.110780, 0.970750, 
-0.430830, -0.174240, -0.641460, -0.386920, -0.417410, -0.253350, -0.890630, -0.227580, 0.433100, -0.076760, 
0.177730, 0.707850, -0.920510, -0.473810, 0.079040, 0.390440, 0.507910, -0.504420, 0.162550, 1.100180, 
-0.057130, -0.085530, 0.290170, -0.450290, 0.726190, -0.415610, -0.469480, -0.589230, 0.668440, -0.158710, 

0.909860, 0.508040, 0.362720, 0.893570, 0.788140, -0.487250, -0.714450, -0.271650, -0.228520, 0.519160, 
-0.003540, 0.552630, -0.469140, -0.834200, 0.887410, 0.977680, 0.309690, 0.825600, -0.369900, -1.049650, 
0.171240, 0.315440, -0.146290, 0.319020, -0.173840, 1.001420, 0.959280, 1.222610, 0.125470, -2.790040, 
0.817130, 0.044700, -2.907310, -0.706720, 0.269010, 0.283210, -0.164750, -0.172050, 0.545160, 0.031420, 
0.766480, -0.968100, 0.476700, 0.509930, -0.581670, -0.694770, 2.692380, -0.694300, -10.115180, -0.524430, 
-0.259730, 0.594810, 0.039890, -0.411590, -0.846940, -0.141000, -0.117080, -0.464170, -0.863690, 0.362190, 

-0.103810, -0.616020, -0.890870, -0.397840, 0.664780, 0.461630, -0.773070, -0.762900, -0.905210, 0.676250, 
0.069450, 0.640300, 0.512450, -0.602010, -0.556750, 0.484010, 0.600450, 0.422220, 0.059280, -0.783500, 
-0.300270, 0.604360, -0.165980, 0.493190, -0.331460, -0.125230, -0.707810, -0.456900, -0.986820, 0.437200, 
-0.630090, 0.724220, 0.146210, 0.809690, -0.006850, -0.496730, -0.253160, -0.444960, 0.912460, -0.594480, 
0.763700, -0.071630, -0.877270, 0.341050, 0.309670, -0.632330, -1.104620, -0.838950, -0.648480, -0.672380, 
0.211190, 0.670500, -0.261260, 0.169190, 0.775240, 0.111430, 0.019370, -0.356600, 0.238250, -0.588830, 

-0.131800, 0.363480, 0.109750, 0.751020, 1.181020, -0.308150, -0.892580, 0.543070, -1.055740, -1.058820, 
-1.458020, 0.876330, -0.866850, 0.814740, 4.134260, 0.867420, 0.452620, -0.790540, -0.535210, 0.906610, 
-0.021850, 1.877440, -0.079470, 0.614350, -1.428820, 1.611680, 0.011050, 0.229080, -0.020260, 0.456530, 
-0.338440, -0.850370, -1.052470, 1.092870, -1.601860, 1.049940, 2.395400, 0.870440, -0.337840, 0.641850, 
0.104480, -11.364090, 0.189220, -0.927660, -0.582950, -0.711110, 15.212680, -0.887160, -3.864250, -0.740910, 
-0.165940, -0.794680, -5.694360, 0.856510, -0.662150, -0.038240, -0.708220, -0.326870, -0.778880, 1.560160, 

-0.440060, -0.230560, -0.341180, -0.443020, -0.159650, 0.205700, 0.454320, 0.850050, 0.689980, -0.293680, 
0.459910, -0.301840, -0.437090, 0.182240, 0.604170, -1.022450, 0.189980, -0.650640, -0.792800, 0.879740, 
-0.571860, 0.231370, 0.835180, -0.203630, -0.585090, -0.465230, -0.309260, -0.411670, 0.901290, 0.710430, 

1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
1.000000, 0.300000, 
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
      0.0, 0.176680, 299,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 271 (hid12) */
      0.0, 0.963460, 299,
       &Sources[299] , 
       &Weights[299] , 
      },
    { /* unit 272 (hid13) */
      0.0, -0.509370, 299,
       &Sources[598] , 
       &Weights[598] , 
      },
    { /* unit 273 (hid14) */
      0.0, -0.708940, 299,
       &Sources[897] , 
       &Weights[897] , 
      },
    { /* unit 274 (hid15) */
      0.0, 0.051690, 299,
       &Sources[1196] , 
       &Weights[1196] , 
      },
    { /* unit 275 (hid16) */
      0.0, 0.994320, 299,
       &Sources[1495] , 
       &Weights[1495] , 
      },
    { /* unit 276 (hid17) */
      0.0, 1.724090, 299,
       &Sources[1794] , 
       &Weights[1794] , 
      },
    { /* unit 277 (hid18) */
      0.0, 0.727100, 299,
       &Sources[2093] , 
       &Weights[2093] , 
      },
    { /* unit 278 (hid19) */
      0.0, -0.851620, 299,
       &Sources[2392] , 
       &Weights[2392] , 
      },
    { /* unit 279 (hid110) */
      0.0, 0.819660, 299,
       &Sources[2691] , 
       &Weights[2691] , 
      },
    { /* unit 280 (hid111) */
      0.0, -1.739560, 299,
       &Sources[2990] , 
       &Weights[2990] , 
      },
    { /* unit 281 (hid112) */
      0.0, -0.532600, 299,
       &Sources[3289] , 
       &Weights[3289] , 
      },
    { /* unit 282 (hid113) */
      0.0, 0.591320, 299,
       &Sources[3588] , 
       &Weights[3588] , 
      },
    { /* unit 283 (hid114) */
      0.0, 0.940110, 299,
       &Sources[3887] , 
       &Weights[3887] , 
      },
    { /* unit 284 (hid115) */
      0.0, 0.058220, 299,
       &Sources[4186] , 
       &Weights[4186] , 
      },
    { /* unit 285 (hid116) */
      0.0, 1.068420, 299,
       &Sources[4485] , 
       &Weights[4485] , 
      },
    { /* unit 286 (hid117) */
      0.0, -0.651440, 299,
       &Sources[4784] , 
       &Weights[4784] , 
      },
    { /* unit 287 (hid118) */
      0.0, 0.441220, 299,
       &Sources[5083] , 
       &Weights[5083] , 
      },
    { /* unit 288 (hid119) */
      0.0, 0.262240, 299,
       &Sources[5382] , 
       &Weights[5382] , 
      },
    { /* unit 289 (hid120) */
      0.0, -0.141400, 299,
       &Sources[5681] , 
       &Weights[5681] , 
      },
    { /* unit 290 (hid121) */
      0.0, 0.021820, 299,
       &Sources[5980] , 
       &Weights[5980] , 
      },
    { /* unit 291 (hid122) */
      0.0, -1.015750, 299,
       &Sources[6279] , 
       &Weights[6279] , 
      },
    { /* unit 292 (hid123) */
      0.0, -0.359730, 299,
       &Sources[6578] , 
       &Weights[6578] , 
      },
    { /* unit 293 (hid124) */
      0.0, 0.670330, 299,
       &Sources[6877] , 
       &Weights[6877] , 
      },
    { /* unit 294 (hid125) */
      0.0, 0.081770, 299,
       &Sources[7176] , 
       &Weights[7176] , 
      },
    { /* unit 295 (hid126) */
      0.0, -0.884080, 299,
       &Sources[7475] , 
       &Weights[7475] , 
      },
    { /* unit 296 (hid127) */
      0.0, -0.361090, 299,
       &Sources[7774] , 
       &Weights[7774] , 
      },
    { /* unit 297 (hid128) */
      0.0, 0.189960, 299,
       &Sources[8073] , 
       &Weights[8073] , 
      },
    { /* unit 298 (hid129) */
      0.0, -0.414790, 299,
       &Sources[8372] , 
       &Weights[8372] , 
      },
    { /* unit 299 (hid130) */
      0.0, 0.212720, 299,
       &Sources[8671] , 
       &Weights[8671] , 
      },
    { /* unit 300 (hid21) */
      0.0, 0.307930, 60,
       &Sources[8970] , 
       &Weights[8970] , 
      },
    { /* unit 301 (hid22) */
      0.0, -0.215600, 60,
       &Sources[9030] , 
       &Weights[9030] , 
      },
    { /* unit 302 (hid23) */
      0.0, 35.575459, 60,
       &Sources[9090] , 
       &Weights[9090] , 
      },
    { /* unit 303 (hid24) */
      0.0, 77.949890, 60,
       &Sources[9150] , 
       &Weights[9150] , 
      },
    { /* unit 304 (hid25) */
      0.0, -0.698280, 60,
       &Sources[9210] , 
       &Weights[9210] , 
      },
    { /* unit 305 (hid26) */
      0.0, 0.870700, 60,
       &Sources[9270] , 
       &Weights[9270] , 
      },
    { /* unit 306 (hid27) */
      0.0, 0.374720, 60,
       &Sources[9330] , 
       &Weights[9330] , 
      },
    { /* unit 307 (hid28) */
      0.0, 0.112590, 60,
       &Sources[9390] , 
       &Weights[9390] , 
      },
    { /* unit 308 (hid29) */
      0.0, 0.115120, 60,
       &Sources[9450] , 
       &Weights[9450] , 
      },
    { /* unit 309 (hid210) */
      0.0, -0.855500, 60,
       &Sources[9510] , 
       &Weights[9510] , 
      },
    { /* unit 310 (hid211) */
      0.0, -0.777350, 60,
       &Sources[9570] , 
       &Weights[9570] , 
      },
    { /* unit 311 (hid212) */
      0.0, -0.810040, 60,
       &Sources[9630] , 
       &Weights[9630] , 
      },
    { /* unit 312 (hid213) */
      0.0, 0.013690, 60,
       &Sources[9690] , 
       &Weights[9690] , 
      },
    { /* unit 313 (hid214) */
      0.0, 0.541480, 60,
       &Sources[9750] , 
       &Weights[9750] , 
      },
    { /* unit 314 (hid215) */
      0.0, 0.409030, 60,
       &Sources[9810] , 
       &Weights[9810] , 
      },
    { /* unit 315 (hid216) */
      0.0, 0.951890, 60,
       &Sources[9870] , 
       &Weights[9870] , 
      },
    { /* unit 316 (hid217) */
      0.0, -0.071780, 60,
       &Sources[9930] , 
       &Weights[9930] , 
      },
    { /* unit 317 (hid218) */
      0.0, 0.147670, 60,
       &Sources[9990] , 
       &Weights[9990] , 
      },
    { /* unit 318 (hid219) */
      0.0, -0.402300, 60,
       &Sources[10050] , 
       &Weights[10050] , 
      },
    { /* unit 319 (hid220) */
      0.0, 0.041760, 60,
       &Sources[10110] , 
       &Weights[10110] , 
      },
    { /* unit 320 (hid221) */
      0.0, 0.537810, 60,
       &Sources[10170] , 
       &Weights[10170] , 
      },
    { /* unit 321 (hid222) */
      0.0, 0.894270, 60,
       &Sources[10230] , 
       &Weights[10230] , 
      },
    { /* unit 322 (hid223) */
      0.0, 0.255280, 60,
       &Sources[10290] , 
       &Weights[10290] , 
      },
    { /* unit 323 (hid224) */
      0.0, -0.464220, 60,
       &Sources[10350] , 
       &Weights[10350] , 
      },
    { /* unit 324 (hid225) */
      0.0, -0.391930, 60,
       &Sources[10410] , 
       &Weights[10410] , 
      },
    { /* unit 325 (hid226) */
      0.0, 0.394300, 60,
       &Sources[10470] , 
       &Weights[10470] , 
      },
    { /* unit 326 (hid227) */
      0.0, 0.526460, 60,
       &Sources[10530] , 
       &Weights[10530] , 
      },
    { /* unit 327 (hid228) */
      0.0, 1.013790, 60,
       &Sources[10590] , 
       &Weights[10590] , 
      },
    { /* unit 328 (hid229) */
      0.0, -0.583270, 60,
       &Sources[10650] , 
       &Weights[10650] , 
      },
    { /* unit 329 (hid230) */
      0.0, -0.300380, 60,
       &Sources[10710] , 
       &Weights[10710] , 
      },
    { /* unit 330 (out1) */
      0.0, 0.355040, 30,
       &Sources[10770] , 
       &Weights[10770] , 
      },
    { /* unit 331 (con11) */
0.00836, 0.500000, 2,
       &Sources[10800] , 
       &Weights[10800] , 
      },
    { /* unit 332 (con12) */
0.42089, 0.500000, 2,
       &Sources[10802] , 
       &Weights[10802] , 
      },
    { /* unit 333 (con13) */
0.30075, 0.500000, 2,
       &Sources[10804] , 
       &Weights[10804] , 
      },
    { /* unit 334 (con14) */
0.28225, 0.500000, 2,
       &Sources[10806] , 
       &Weights[10806] , 
      },
    { /* unit 335 (con15) */
0.30080, 0.500000, 2,
       &Sources[10808] , 
       &Weights[10808] , 
      },
    { /* unit 336 (con16) */
1.42588, 0.500000, 2,
       &Sources[10810] , 
       &Weights[10810] , 
      },
    { /* unit 337 (con17) */
1.35895, 0.500000, 2,
       &Sources[10812] , 
       &Weights[10812] , 
      },
    { /* unit 338 (con18) */
0.09809, 0.500000, 2,
       &Sources[10814] , 
       &Weights[10814] , 
      },
    { /* unit 339 (con19) */
1.15963, 0.500000, 2,
       &Sources[10816] , 
       &Weights[10816] , 
      },
    { /* unit 340 (con110) */
0.41525, 0.500000, 2,
       &Sources[10818] , 
       &Weights[10818] , 
      },
    { /* unit 341 (con111) */
0.45417, 0.500000, 2,
       &Sources[10820] , 
       &Weights[10820] , 
      },
    { /* unit 342 (con112) */
1.01555, 0.500000, 2,
       &Sources[10822] , 
       &Weights[10822] , 
      },
    { /* unit 343 (con113) */
1.00693, 0.500000, 2,
       &Sources[10824] , 
       &Weights[10824] , 
      },
    { /* unit 344 (con114) */
0.57619, 0.500000, 2,
       &Sources[10826] , 
       &Weights[10826] , 
      },
    { /* unit 345 (con115) */
1.42614, 0.500000, 2,
       &Sources[10828] , 
       &Weights[10828] , 
      },
    { /* unit 346 (con116) */
0.03502, 0.500000, 2,
       &Sources[10830] , 
       &Weights[10830] , 
      },
    { /* unit 347 (con117) */
1.10306, 0.500000, 2,
       &Sources[10832] , 
       &Weights[10832] , 
      },
    { /* unit 348 (con118) */
1.42114, 0.500000, 2,
       &Sources[10834] , 
       &Weights[10834] , 
      },
    { /* unit 349 (con119) */
1.10254, 0.500000, 2,
       &Sources[10836] , 
       &Weights[10836] , 
      },
    { /* unit 350 (con120) */
1.26404, 0.500000, 2,
       &Sources[10838] , 
       &Weights[10838] , 
      },
    { /* unit 351 (con121) */
0.32781, 0.500000, 2,
       &Sources[10840] , 
       &Weights[10840] , 
      },
    { /* unit 352 (con122) */
0.00000, 0.500000, 2,
       &Sources[10842] , 
       &Weights[10842] , 
      },
    { /* unit 353 (con123) */
0.12925, 0.500000, 2,
       &Sources[10844] , 
       &Weights[10844] , 
      },
    { /* unit 354 (con124) */
1.32740, 0.500000, 2,
       &Sources[10846] , 
       &Weights[10846] , 
      },
    { /* unit 355 (con125) */
1.42857, 0.500000, 2,
       &Sources[10848] , 
       &Weights[10848] , 
      },
    { /* unit 356 (con126) */
0.00023, 0.500000, 2,
       &Sources[10850] , 
       &Weights[10850] , 
      },
    { /* unit 357 (con127) */
0.33487, 0.500000, 2,
       &Sources[10852] , 
       &Weights[10852] , 
      },
    { /* unit 358 (con128) */
1.04053, 0.500000, 2,
       &Sources[10854] , 
       &Weights[10854] , 
      },
    { /* unit 359 (con129) */
0.17734, 0.500000, 2,
       &Sources[10856] , 
       &Weights[10856] , 
      },
    { /* unit 360 (con130) */
0.00000, 0.500000, 2,
       &Sources[10858] , 
       &Weights[10858] , 
      },
    { /* unit 361 (con21) */
0.98214, 0.500000, 2,
       &Sources[10860] , 
       &Weights[10860] , 
      },
    { /* unit 362 (con22) */
1.25750, 0.500000, 2,
       &Sources[10862] , 
       &Weights[10862] , 
      },
    { /* unit 363 (con23) */
1.42857, 0.500000, 2,
       &Sources[10864] , 
       &Weights[10864] , 
      },
    { /* unit 364 (con24) */
1.42857, 0.500000, 2,
       &Sources[10866] , 
       &Weights[10866] , 
      },
    { /* unit 365 (con25) */
1.36047, 0.500000, 2,
       &Sources[10868] , 
       &Weights[10868] , 
      },
    { /* unit 366 (con26) */
0.08565, 0.500000, 2,
       &Sources[10870] , 
       &Weights[10870] , 
      },
    { /* unit 367 (con27) */
0.40467, 0.500000, 2,
       &Sources[10872] , 
       &Weights[10872] , 
      },
    { /* unit 368 (con28) */
1.36134, 0.500000, 2,
       &Sources[10874] , 
       &Weights[10874] , 
      },
    { /* unit 369 (con29) */
1.39421, 0.500000, 2,
       &Sources[10876] , 
       &Weights[10876] , 
      },
    { /* unit 370 (con210) */
1.39653, 0.500000, 2,
       &Sources[10878] , 
       &Weights[10878] , 
      },
    { /* unit 371 (con211) */
1.37818, 0.500000, 2,
       &Sources[10880] , 
       &Weights[10880] , 
      },
    { /* unit 372 (con212) */
0.00000, 0.500000, 2,
       &Sources[10882] , 
       &Weights[10882] , 
      },
    { /* unit 373 (con213) */
1.42278, 0.500000, 2,
       &Sources[10884] , 
       &Weights[10884] , 
      },
    { /* unit 374 (con214) */
1.42857, 0.500000, 2,
       &Sources[10886] , 
       &Weights[10886] , 
      },
    { /* unit 375 (con215) */
1.42857, 0.500000, 2,
       &Sources[10888] , 
       &Weights[10888] , 
      },
    { /* unit 376 (con216) */
1.38997, 0.500000, 2,
       &Sources[10890] , 
       &Weights[10890] , 
      },
    { /* unit 377 (con217) */
0.00000, 0.500000, 2,
       &Sources[10892] , 
       &Weights[10892] , 
      },
    { /* unit 378 (con218) */
0.00454, 0.500000, 2,
       &Sources[10894] , 
       &Weights[10894] , 
      },
    { /* unit 379 (con219) */
0.00000, 0.500000, 2,
       &Sources[10896] , 
       &Weights[10896] , 
      },
    { /* unit 380 (con220) */
1.40064, 0.500000, 2,
       &Sources[10898] , 
       &Weights[10898] , 
      },
    { /* unit 381 (con221) */
1.19477, 0.500000, 2,
       &Sources[10900] , 
       &Weights[10900] , 
      },
    { /* unit 382 (con222) */
1.42857, 0.500000, 2,
       &Sources[10902] , 
       &Weights[10902] , 
      },
    { /* unit 383 (con223) */
0.00083, 0.500000, 2,
       &Sources[10904] , 
       &Weights[10904] , 
      },
    { /* unit 384 (con224) */
1.28104, 0.500000, 2,
       &Sources[10906] , 
       &Weights[10906] , 
      },
    { /* unit 385 (con225) */
1.42837, 0.500000, 2,
       &Sources[10908] , 
       &Weights[10908] , 
      },
    { /* unit 386 (con226) */
1.42467, 0.500000, 2,
       &Sources[10910] , 
       &Weights[10910] , 
      },
    { /* unit 387 (con227) */
0.45147, 0.500000, 2,
       &Sources[10912] , 
       &Weights[10912] , 
      },
    { /* unit 388 (con228) */
0.18232, 0.500000, 2,
       &Sources[10914] , 
       &Weights[10914] , 
      },
    { /* unit 389 (con229) */
0.86686, 0.500000, 2,
       &Sources[10916] , 
       &Weights[10916] , 
      },
    { /* unit 390 (con230) */
0.01115, 0.500000, 2,
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
