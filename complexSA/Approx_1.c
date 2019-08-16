/*********************************************************
  Pfam_el_0_new10new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:09:45 2004
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
-0.388450, 0.712250, 0.203930, 0.305490, 0.039030, -0.532140, 0.458520, -0.936270, 0.074110, -0.718310,
-1.055860, -0.314320, 0.727560, 0.450180, 0.153170, -0.504790, 0.479870, 0.819140, -0.083640, -0.528610,
-0.325200, 0.238860, -0.434840, 0.224260, 0.721790, -0.619330, 1.315740, 1.007100, 0.398190, -0.359350,
-0.634940, 0.897580, -0.214520, 0.116570, -0.347570, 0.003090, 2.013190, 0.547180, -0.138110, -0.207860,
-0.731360, -0.420120, 1.676510, -0.324390, -0.935750, -0.065520, -0.843310, 0.568750, 0.676510, -0.456360,
-0.032210, 0.436930, -1.077450, 1.279970, -0.597110, -0.631560, -0.651020, 0.188870, 1.130430, 1.363200,
-1.076890, -0.591690, 0.905390, 0.128950, 0.814100, -0.002760, -0.817490, -0.695170, -0.848790, -0.366750,
-0.437320, -0.422070, -0.804860, 0.796580, -0.811550, -0.831270, 0.152850, -2.043550, -0.273330, 0.307850,
-0.113870, 1.660460, -0.103370, -1.110360, -0.073420, -0.343470, 0.431910, 0.916720, -1.055730, -1.595510,
-0.726510, -2.050830, 0.313620, -0.448800, -1.034070, -0.826530, -0.980930, -0.220900, -0.715200, -0.284870,
-0.060210, -2.146180, 0.317240, -0.153130, 0.475590, 0.711660, -0.161530, -0.307260, -0.267730, -1.794630,
-1.395780, 0.540130, -0.237190, 0.644150, -0.674660, -0.990950, -1.104810, -0.599640, -2.749560, 0.100730,
0.007390, 0.621130, -0.298480, -0.185410, -1.939920, -0.412520, 1.711150, 0.609580, -1.114200, 0.195400,
1.077100, 1.465710, -1.145850, 0.710740, 0.614350, -0.211330, 0.128810, 1.836580, -0.639440, 2.606210,
-2.346920, 1.509080, 0.538920, -0.163770, 0.281430, -0.533240, -1.086030, -0.135080, -0.099760, -0.117470,
-0.824350, -0.523220, -0.330800, 0.058480, -0.192550, 0.610540, -2.738650, -1.353160, 0.031990, -1.167120,
-0.124610, 0.109240, -1.096920, -0.926790, 0.737980, 1.471390, -0.767550, 0.147180, 1.032390, 0.803810,
-0.218540, 0.030590, -0.142920, 1.382800, 0.566250, -0.673220, 1.441450, 0.877870, 0.138350, -0.418780,
1.389260, -0.361130, -0.688710, -0.031880, -0.496980, -1.193720, -0.727630, 0.267980, 0.333560, -0.086760,
-0.284930, 1.427110, -0.635780, -0.601190, 0.589410, 0.401170, -0.798030, -0.141330, -0.160060, 0.600560,
-0.514330, -1.432500, -0.220380, 0.370020, -0.911880, -1.672650, 1.771800, 0.197250, -0.635370, 0.680130,
-0.619660, 0.578580, -0.926020, -0.213440, 0.563190, -0.719440, 0.802830, -0.299680, -0.898580, -0.422520,
0.917920, -0.031870, 0.556760, 0.422530, -1.296970, 0.231380, -0.014510, -1.158590, -0.643560, 0.734570,
-1.106670, 0.136150, -0.990770, 0.366370, 0.221770, 0.552470, 0.636100, 0.064930, 0.396450, -0.305580,
-0.123490, -0.482370, -0.070140, -0.485250, 0.810900, 0.271020, 0.523260, -1.234070, -0.366610, 0.720880,
0.483500, -2.995340, -1.169790, -0.585610, -0.101700, -1.027760, -0.835570, 0.271390, -0.822960, -0.902710,
1.307430, 0.858330, 3.400540, 0.614450, -0.939110, 1.170450, -0.949030, -0.019970, -0.409040, 1.249680,
-0.259180, 0.606940, 1.102280, -0.011880, 1.244920, -0.739930, 1.077690, -0.097880, 0.888690, 0.876380,
0.336450, 0.505360, -0.371140, 0.803770, 0.461540, 0.385280, 1.404710, -0.121060, 0.815360, 1.207430,
0.196750, 0.506340, 0.023700, 0.529530, -0.111940, -0.067080, 0.654880, 0.468860, 1.797380,
-1.090460, 1.057370, -0.653800, -0.731160, -0.209350, -1.185560, 0.648940, 0.010770, 1.232490, 0.796470,
0.790810, -0.786280, 0.230970, -1.247920, 1.198180, 0.635550, 0.190600, 2.135580, -0.076600, -1.172220,
-0.888940, 0.915960, -0.960240, 0.047560, 0.831960, -0.076000, 0.854500, 1.112600, 0.173480, -0.335340,
-0.218970, 1.266530, 0.146280, 0.554120, -0.676600, 0.098370, -0.101180, 0.083210, 0.665600, -1.251380,
1.826920, -0.028220, -0.219820, 0.845040, -0.879250, -0.736070, -1.503750, -0.418400, -0.337400, -0.116130,
0.175060, -0.676440, -1.805800, 0.982680, -0.277590, -0.601730, 0.099010, 0.062590, -0.302760, -0.592280,
-0.643660, 0.127170, -0.562450, 1.669870, -0.278310, 0.388100, -0.871840, 0.918850, -0.350910, -0.389590,
0.063190, -1.661060, 0.655440, -0.388690, -0.264110, -0.469880, 0.515830, -1.420290, -1.591060, -0.360400,
-0.308250, 0.391560, -3.422840, -0.845530, 0.158810, -1.480080, -2.423680, -1.022070, -0.460620, -1.681690,
1.135980, -0.562600, -0.557210, 1.389780, -0.302410, -0.208070, 0.707500, -0.250130, 0.961380, 0.237630,
0.261380, 0.958610, 1.222750, 0.168400, 1.065910, 0.092910, 1.144400, -1.609220, 0.485160, -0.128060,
0.325870, -0.417650, -1.424660, 0.126270, -1.956200, 0.170090, 1.521170, -0.126430, -0.007730, -0.107270,
-0.464090, -0.492050, -0.596200, 1.142150, 1.636660, -1.394770, -1.050040, -1.041670, 0.758700, 0.296660,
-0.401700, 0.750700, 0.712840, 0.602140, -0.888510, 0.683990, -1.150270, -0.035460, 1.023230, -0.443070,
0.985420, -0.146830, 0.398090, 0.364760, -1.320270, -0.216830, -0.611070, 1.107380, -1.618820, -0.121910,
0.504150, 0.030460, -0.285440, -0.404460, -0.379640, 1.312900, 0.726950, -0.397540, -0.544390, -1.386890,
-4.040890, -2.594960, 0.885410, -0.172640, -1.509760, 0.481490, -0.666240, -0.587750, 0.196670, 0.234990,
-0.783920, 0.898420, -0.217980, -0.196460, 0.268700, 0.432650, 0.458380, -0.611070, 0.179910, -0.815690,
0.215170, 0.129740, 0.574940, -0.627440, 0.946930, -0.634720, 0.632880, -0.510540, 1.290710, -0.401690,
-0.791870, -0.015220, 0.073660, 0.323090, 0.311120, -0.026570, -0.962770, 0.532780, 1.469010, 0.721480,
0.123880, 0.129850, 0.412650, -0.339990, -0.641890, 0.565150, -1.483580, -0.429350, 0.415450, -0.226190,
-0.339600, -0.457260, -0.166690, -0.360670, 1.171010, 0.936380, -0.739800, 0.059980, -0.673990, -1.297180,
-0.104670, 0.665630, 0.613760, -1.151300, 0.230590, -0.082980, 0.535140, -0.248160, 0.552160, 0.772480,
0.465810, 0.858220, 0.225290, 0.070080, 0.402060, -0.700380, -0.487940, -1.236650, -2.123470, 0.268440,
0.430120, 0.494580, -0.281580, -0.419140, 0.564220, -0.333730, -0.321170, 0.868380, -0.058550, -0.913960,
-1.123210, 1.103570, -0.626420, 0.628220, 0.208420, 0.110450, -0.522930, -0.010300, -0.651940, -0.277260,
-1.435430, 0.204310, -1.408130, -0.382860, 1.270040, -2.254060, -0.660870, 0.421050, 0.448050, 0.362400,
0.173490, -0.634740, -1.915560, -0.601550, -0.735690, -0.907060, -0.337830, -0.490170, -0.492180, -1.261170,
-0.871450, 0.189600, -0.074800, 0.039550, 1.166090, 0.134990, -0.857610, 0.166670, -1.070090, -1.194710,
0.046670, -0.213530, -0.468850, -0.371630, 0.537910, -0.680410, -0.498270, -1.962970, -0.380530,
0.411850, -0.131600, -0.469620, 0.992410, -1.020050, 0.014530, -1.141720, 0.906620, -0.806800, -0.035340,
-0.420860, 0.547800, -0.281480, -0.478040, 0.265970, -0.172270, -0.614900, -0.160090, -0.023340, 1.637280,
-0.975790, -0.713980, -0.946290, 2.475970, 3.778490, 0.234460, 2.955190, 0.399590, 1.944730, 0.365040,
8.846830, 1.017410, 0.236430, 0.756980, -1.208560, -0.461800, 2.662990, 1.705160, 0.579560, -0.512670,
1.104220, -1.623840, 0.282040, -0.049920, 0.090580, -0.193630, 0.296320, -0.854420, -1.008240, 0.097900,
-0.627140, -0.850170, -0.865790, 0.991380, 1.007930, 0.021690, -1.459510, 0.942510, -0.605820, 0.516530,
-0.072570, 0.540160, -0.456780, 0.333420, 1.952470, 0.024810, -0.797550, -0.495650, -1.579960, -0.188010,
1.476720, 0.037060, 2.027250, -0.104270, 0.034920, -0.502150, -0.739950, -0.507700, 0.952340, 0.923890,
-0.537700, -0.118630, 0.226910, 0.216330, -0.695870, -0.089070, 0.003300, 0.264940, -0.187830, 0.659950,
-0.525530, -1.006770, 3.724480, 0.861420, 3.313050, -0.119270, 0.081730, 2.417300, 2.481320, 1.282840,
1.973300, -0.547510, 0.602440, 1.275070, -1.934270, -0.278870, -1.249740, 0.267710, 1.229690, -0.209940,
-1.205400, -0.961730, -0.221000, 0.429510, -0.874490, -0.018960, 0.089960, 1.084000, 0.857040, -0.257380,
0.320520, 1.252560, 0.768190, -1.037940, 0.505070, -0.141810, -0.257260, 0.651330, -0.524840, -2.463860,
2.051950, 0.492830, 0.476870, 1.896700, -0.272520, 0.645620, 1.265280, 1.589450, -0.236370, 2.662040,
0.840930, -3.044900, 0.137720, 0.895280, -0.782800, 1.635000, -0.733420, 0.636480, 0.250210, 0.505750,
2.040860, -0.782980, 0.583810, 1.977770, 0.980900, -0.880760, -0.859480, -0.001450, 0.055150, 0.080520,
-0.213740, -1.089180, -0.519850, 1.256000, 1.738670, 0.045490, -0.253350, -0.420520, -0.131410, -0.487250,
1.820070, -0.370470, 0.733420, -0.494520, 0.709320, 0.537600, 2.820380, 0.088440, 1.577470, -0.308220,
1.142320, -0.983070, 0.818670, -0.798810, -0.775160, 0.437960, 0.229480, 1.304900, -2.335690, -0.059980,
3.328800, 2.855640, -0.321900, -1.457340, 0.538700, 1.651970, 1.152260, -1.207460, -2.862440, -0.580750,
0.434700, -0.822290, 1.712140, -0.327570, 0.111100, 0.076980, -0.616000, -0.949620, 0.032850, 1.785230,
0.930980, -0.147260, -0.501730, -0.886340, 0.418810, -1.560930, 0.188870, 0.135450, -0.189760, 1.871540,
1.050720, -2.808730, -1.145910, -1.850420, -0.875270, 0.341760, -0.272820, 0.561220, -0.485360, -0.078440,
2.442090, -0.957080, 1.035500, 1.017570, 3.172260, -1.075690, 0.313430, 0.797260, 2.312550, 1.582370,
-3.223860, 1.018320, -0.509080, 0.603800, -0.723230, 0.978640, 0.724250, 0.417740, -0.018200, 0.094520,
-0.660250, 2.049500, 0.079420, 5.531850, -2.499370, 0.404110, 1.145110, -0.071770, 0.960290, -1.112920,
2.782080, 0.539480, 0.778980, 1.742500, -1.624820, 0.108420, 1.056870, -1.715560, -0.972620, 1.038760,
1.465830, 1.342050, -0.058110, -0.548200, 0.469430, -1.405390, 0.140180, 1.360970, -0.825060, 0.942700,
1.143270, 0.262040, 0.178280, 0.782020, 2.657530, -0.434330, -0.108860, 1.019720, 0.632440, 0.024370,
-0.049510, 0.274860, 0.983780, 0.823610, -0.427360, 0.990770, 1.548610, -0.037950, 0.303170,
0.538480, 0.654900, -0.990200, 1.443990, 1.123590, 0.424820, 0.830430, 0.642800, 0.531690, 0.042680,
-1.356170, 0.406440, 1.973920, 1.769250, 2.515460, -0.311620, -0.332550, -0.078790, 1.207160, -0.636810,
0.981900, -0.642430, 0.098390, -2.250120, 1.356180, -0.734160, -0.287170, -0.313500, -1.150770, 0.775050,
-0.634280, 0.311850, -0.730060, 0.432810, -1.192720, -0.978480, 0.090340, 0.009060, -0.548750, 0.080910,
0.770130, 0.484680, -0.133710, -0.732310, 1.039730, 2.289700, -0.136910, 0.035420, 0.550080, 0.185660,
-0.574940, -0.362760, 0.434260, -0.470500, -0.173090, -2.291550, 0.511900, 0.938080, 0.336850, 0.519640,
-0.965970, -0.061090, 3.019820, -0.439430, -0.068260, 0.394480, -1.361620, 0.260140, -0.033520, 0.107480,
-2.310640, 0.138480, -0.465520, -0.088440, -0.439190, 0.502170, -0.044170, 0.548760, -1.328780, 0.797770,
-0.653480, -0.611340, -0.631020, -0.208560, 0.130490, 0.360070, -1.588470, -0.022370, -0.690340, 2.642140,
-0.074560, 2.922960, 1.415790, 0.121520, -1.253210, 0.483240, -0.715510, -0.414390, -0.645330, -1.238760,
0.626150, -0.101480, 0.595460, 0.724560, 0.443820, -0.612420, 0.580420, 1.143910, 0.933350, -0.919290,
1.038600, 0.244300, 0.747230, 0.353130, 0.671530, -0.391020, -2.788430, -2.331790, 3.808040, -7.046520,
1.847550, 3.543720, 0.286650, -1.243560, -5.880090, 0.138230, -0.150440, -0.824300, -0.074690, -4.202400,
-1.936900, 1.658620, -5.122350, 0.288200, 1.190430, 0.667960, 2.478450, -0.190400, 0.056310, -0.202490,
-0.106590, -0.501820, 1.749450, -1.150420, 1.778950, -0.472100, -1.004480, 0.393800, 0.881350, -0.712640,
0.101790, 0.405870, 0.189930, -0.338850, 1.238910, -1.253990, 0.787620, -0.211510, -0.037300, 0.539180,
0.762590, 0.877220, -1.797670, -0.354030, 0.441110, -0.511600, 0.748060, 0.241190, 0.625720, -3.293320,
-0.289670, 0.683240, 0.009430, -0.487790, 0.736040, -0.633130, -0.431710, -1.739880, -3.099170, 0.135130,
-0.104970, 1.099990, -0.412730, 0.231220, -1.364040, 0.483950, -0.137370, 1.226630, 0.291650, -1.003460,
-0.099360, -0.025530, -1.050580, -1.406370, 0.399580, 0.159880, -0.573150, 0.102340, -0.246300, 0.022230,
-1.006590, -1.535600, 0.533900, 1.570030, 0.449580, -0.065900, 0.661750, -1.726720, -0.336880, -0.250800,
0.678840, 1.330370, -0.437370, 1.167380, 1.167710, -1.283690, -0.007820, -1.479380, 0.327990, -0.385340,
0.173430, -1.131780, -0.910610, -0.054210, -3.289450, -0.147310, 0.006860, 0.622920, 0.418700, 1.294970,
-0.239700, -0.209110, -1.117620, 0.582960, -1.010460, 0.012740, -0.135750, -0.471430, 0.105970, 0.424670,
-1.036510, 0.256960, -0.473040, 0.784920, 0.617450, 0.591320, -0.115460, 0.692890, 0.294240, -0.477810,
0.389250, -0.193420, 0.833080, -15.299070, -0.071980, -0.119890, 0.122040, -0.340320, -2.449370, 0.936390,
-0.055790, -0.207300, 0.743540, 0.190740, 0.432710, -1.860040, -0.034330, 0.119610, -0.299950, -2.335830,
-4.762880, -1.584570, 8.578430, -2.174570, -0.002870, -1.199760, -2.371930, -0.302910, -3.212450, -1.367890,
-6.024310, -3.526410, -1.329530, -1.336090, -0.913430, -0.229660, -2.770950, -1.855560, -0.846800, -0.127020,
-1.053720, -0.555720, -2.167730, -2.430760, -3.136720, -2.186090, -3.165090, -1.133950, -2.611780,
0.842770, -0.240280, -0.621930, 0.004490, 0.618240, -0.340030, 0.722800, -0.414130, -0.130460, 0.660440,
-1.094620, 0.337290, 1.169260, -0.004350, 0.579860, -0.292820, 0.037370, 1.561350, 1.245820, 0.056170,
-2.256230, 0.610370, -0.796270, -0.432110, -0.643220, 0.902550, -0.349170, -1.114330, 0.812870, 0.411520,
0.574820, 0.507780, 1.015220, -0.871760, -0.135810, 0.181640, 0.627590, 1.405900, -0.598170, -0.333300,
0.918750, -0.711200, -0.433140, -0.411880, -0.419390, 0.467860, 0.892230, -0.985270, 1.168220, -0.499410,
0.736830, 0.282590, 0.761450, 0.063170, 0.869610, 0.756580, -0.455120, -0.207060, -0.006850, 0.001290,
-1.266990, 0.797770, -0.236960, 0.157460, -0.735980, -0.513360, -1.358230, -0.755570, -1.078380, 1.306290,
1.519390, -1.299590, -1.602650, -0.307070, -0.048320, 0.916780, 1.848300, 1.400170, -2.124440, -0.297750,
0.109150, -1.052880, -0.126330, -0.992630, -0.249480, -0.763450, -0.445070, -0.289290, -0.616330, 0.223130,
-1.189320, -0.353920, 0.421560, 0.725530, 0.693160, 0.765550, 0.899360, 0.931000, 0.501730, 0.178750,
0.771980, -2.797820, -2.231390, -0.279270, 0.703970, -0.440760, -0.101290, -0.938260, -0.000740, 0.514780,
-0.221350, -0.423000, -1.528220, -0.302310, 0.034670, 2.982780, 2.400050, 1.644630, -3.307720, 2.772780,
0.432890, -1.321770, -0.878930, 1.810770, 2.767710, -1.254560, -1.728350, -0.557500, 4.784200, -0.231250,
-0.552580, -1.628060, 2.909540, -1.881140, -0.931260, 0.628250, 0.184870, 0.646580, -0.587690, 0.242510,
-0.889230, 0.829600, -1.851720, 0.428350, 0.433700, 0.126460, 0.358070, 0.092780, -0.847050, 0.631720,
-0.214730, 2.379850, 0.668630, 1.916270, 0.337990, -0.365300, 1.297810, -0.241870, -0.376880, 0.379460,
-0.404630, -0.795410, 0.233260, -1.010020, -1.311240, -0.715610, 2.102390, 0.400020, -0.476400, 0.104340,
0.205310, -0.544290, -0.874550, -0.679960, 1.047750, 0.699030, 0.145900, 0.941910, 0.127500, 0.756330,
0.049500, -0.951240, 0.054790, 1.183600, 0.063560, 0.292640, -0.172470, 1.067540, -0.251040, 0.720600,
0.808520, 0.401610, -0.427160, 1.437820, -0.258650, -1.025630, 0.655370, 0.504980, -0.296780, -0.841270,
1.263600, 0.851390, -1.542390, 0.631910, -1.052310, -0.217180, 0.273430, -0.026120, 0.922650, 0.576080,
-2.217580, -0.290360, -0.735530, -0.321790, -0.378830, -0.413130, -0.660000, 0.414550, 0.301340, 0.079720,
-0.226710, -0.030060, -0.644460, 0.316580, 0.683330, -1.721590, 0.387380, 0.708260, -1.105100, -0.189700,
1.029280, -0.435420, 0.754670, 1.226960, -1.257050, 0.307350, 0.781490, 0.611710, 0.452630, -0.438660,
1.727010, 0.133720, -0.614800, -1.266370, 0.114380, 0.997360, -0.877000, 0.015460, 0.132920, 0.270360,
-1.162920, 0.591230, 0.157600, -9.538480, 0.207640, 0.495220, 1.123620, 0.801920, 1.135010, 0.683670,
0.117430, 0.529850, -1.181530, 0.050290, 0.929750, -0.012200, 0.273880, 0.105040, -0.529400, 0.851570,
0.223400, 0.206580, 0.915670, 0.251190, 0.146470, 0.066310, -0.813040, 1.060240, 0.869010, -0.272380,
0.291960, 0.889720, -0.768090, 0.069620, -0.616830, 0.603150, 0.173170, 0.774300, -0.092590, -0.292990,
0.695020, 0.633580, -0.421320, -0.361000, -0.299130, -0.311730, 1.395650, -0.432610, -0.326890,
2.642230, 0.403170, 0.369080, 0.219040, -1.119120, 1.849820, 0.779530, -0.684820, 1.389600, -0.342270,
0.192040, -0.611550, 0.023190, 0.709890, -0.584640, -1.379110, -0.292610, -0.291920, 1.141440, -0.090950,
2.385610, -0.185180, -0.306100, -0.212770, -0.473380, -1.211390, -0.264580, -0.890170, 2.025190, 0.196500,
-0.289020, 2.651830, 0.316270, -0.301090, -0.113660, 1.198480, 2.536950, 1.829260, -0.075410, 1.472710,
-1.290030, 0.670210, -0.859400, 1.665870, -2.036810, 0.869780, -0.265530, -0.163880, -0.198510, -0.168570,
-0.163090, 0.316700, 1.179220, 0.831650, -2.406770, -0.584470, 0.803820, 1.882370, 0.943500, 0.537490,
0.189280, 0.240110, -0.629540, -1.063750, -0.141390, 0.347750, -0.017500, 0.785360, -0.216760, 0.145960,
-0.145580, -2.905980, 1.119260, -0.440720, -0.284140, -0.429990, -0.962370, -0.654740, -0.191320, -0.334930,
1.087740, 0.238950, -0.373120, 1.222500, -0.028590, -0.397890, -1.738900, -0.806070, 0.523990, 1.781920,
-2.379020, -0.464350, -0.383830, -0.247220, 0.226140, -0.572390, -0.619220, -1.090050, 0.059110, 0.059700,
-1.005940, 0.072150, 0.006420, -0.006440, 0.521280, 1.463280, 0.758230, 0.665270, -0.122410, 0.084580,
0.315360, 0.494530, -0.361220, -0.236580, 0.286080, -1.326140, -0.100010, 2.246700, 4.847680, 2.805480,
-1.406380, 3.099010, -2.247800, -3.422320, -4.100690, -0.058740, 1.055800, -1.969170, -0.721640, 1.046440,
-0.295880, 1.226590, -9.941370, 0.693950, 0.683570, -6.204020, 0.351910, -0.593600, -2.506640, 0.168600,
-3.892660, -0.085220, -0.863970, -1.944290, -1.501580, -1.035850, -0.187070, -0.046740, -2.490520, 0.224170,
-0.306620, -0.698230, -0.098700, -0.271000, 0.060410, -1.396690, 0.874700, 0.001200, -1.002300, -0.267860,
-0.922540, -0.136060, 0.344660, 0.624170, 2.454710, -0.469170, -0.581260, -0.382280, -4.931720, 0.284820,
1.849460, 0.897860, 0.041610, 0.718330, 0.753650, 0.697350, -1.123070, 1.099010, 0.479620, 2.268160,
-0.643060, 0.002120, 0.284100, 0.189670, 0.056700, -1.721310, 0.792930, 0.448560, -0.405960, -0.202750,
-0.394450, -1.361690, -0.571530, 0.038770, -0.398510, -0.497890, -1.712160, -0.455420, -0.305160, -0.487760,
0.883620, 0.322870, 0.681650, 1.026080, 1.118710, 1.246960, -1.594600, 0.643650, 0.080730, -0.437450,
-0.553740, -1.874980, -1.719500, -0.001100, 1.138310, -0.498480, -1.536680, 0.147480, -0.040760, -0.072080,
1.857840, -1.432820, 0.213190, 1.649360, -2.015860, 1.680190, 2.078900, 0.822220, 0.103200, 0.261900,
0.949130, 0.589830, -0.338950, 2.420320, -0.574200, -0.590640, -0.436850, -1.375890, 0.476670, 0.422410,
-0.382590, 0.940450, -0.285520, 0.613880, -0.849170, -0.230310, 0.933170, 0.618680, 0.930320, -1.009970,
-0.499840, -0.297530, -0.583410, 0.836240, -0.365010, -1.096660, -0.507980, -0.313620, -1.867550, 1.773800,
1.956450, 0.441010, 2.059180, 0.653000, -1.672910, 0.431850, -0.708120, -0.945820, -0.418870, -0.556840,
0.700240, -0.314290, 1.018490, 0.874520, -0.276210, 0.330850, -0.993860, -0.441720, -0.540740, 0.467850,
0.405840, 0.776600, 0.144820, -0.602270, -0.011370, 0.456620, -0.506590, 0.509440, 0.378600, -0.487340,
0.662400, 0.716290, -0.551870, 0.268580, -0.656550, -1.166230, 0.730150, 0.185060, 0.005950,
0.398730, -0.262550, 1.256480, 1.422290, -1.286440, -0.809830, -0.255720, 0.317980, -1.472390, 0.192930,
2.554220, -1.070760, 1.790940, 0.757640, 0.029730, -1.959820, -0.497210, -0.708560, 1.725350, 1.135630,
0.463860, 0.627370, 1.385410, -1.412510, -1.215540, 0.657430, -0.949890, -0.112520, -0.426270, -0.611330,
-0.908120, -0.588600, -1.862270, 1.107690, 1.504660, -0.396500, 0.867670, -1.798950, 0.182290, 0.081550,
0.028150, 0.997830, 0.251080, 0.595940, 0.696550, 2.789080, 0.223340, -1.828890, -0.475750, -0.018100,
-0.575090, 0.736150, -2.822810, 1.651730, -0.438040, 0.426860, 0.844010, -2.798130, -0.687190, -0.840620,
-1.206410, -1.172870, 0.039040, -0.778410, -0.620890, 0.089960, -1.258420, -0.480650, -0.946930, -0.774840,
-0.557040, -0.819100, 4.723270, -0.638640, -0.023130, -0.834460, 0.495490, -0.566850, 0.752140, 0.656230,
1.022650, 1.321890, -1.445050, -0.135150, 0.312810, 0.930930, -0.212060, 0.397990, 0.308760, 1.192570,
1.343580, 1.019230, -1.316640, -0.767560, -0.294190, -1.175990, 0.143270, -1.289930, -0.674440, 0.197010,
-1.077600, -1.200420, -1.234250, 0.114080, -1.205110, -0.296790, -0.240480, 0.689230, -0.519880, -0.701400,
-1.318160, -2.129180, -0.844980, -1.108650, 0.163010, -0.892890, -6.494020, -1.736890, 0.324880, -0.092400,
-4.120150, 0.152890, -2.179090, 1.100320, 0.310430, -0.072480, 1.558240, 0.267410, -2.424990, -1.664750,
1.343740, 2.640080, -1.016820, -0.227250, 0.267580, -3.909390, 0.722130, 0.573370, -1.916590, 0.674810,
-2.961550, -0.071720, -2.788320, -0.912850, 0.855410, -0.606860, -0.002500, -1.468770, -0.180860, -0.504240,
-0.112420, 0.179320, 0.289960, -0.771490, 1.053640, -2.599190, 0.126780, 0.855890, -1.356430, 0.856530,
1.065290, -0.721840, -0.461690, -0.524450, -1.021560, 2.521700, 1.221730, 1.065770, 1.048300, -0.284170,
0.422220, -0.557120, -0.310040, 0.314480, -0.710640, 0.278600, -0.101850, -1.320460, 0.002110, -0.272960,
0.030430, 0.454440, 0.135040, -0.177050, 0.436220, -0.308720, 2.755550, -0.045680, 0.350980, 0.793180,
0.536130, -0.332730, 0.181010, 0.231460, -1.783080, -0.922780, -0.670810, 0.179370, -0.906380, -0.868480,
-0.673910, -1.486160, -1.340160, -0.972060, -0.240870, 0.613100, 0.617160, 0.224980, -0.911980, -1.232070,
-0.722540, -0.747250, -0.187240, 0.860640, -0.044550, -1.495530, -0.714830, 1.090410, 0.002300, 0.678800,
3.660080, -1.062110, -0.570630, 1.315430, -1.040300, 1.099640, 1.198750, 2.632240, 0.732980, 2.079700,
0.300180, 0.568900, 1.872810, 0.923270, 0.508790, -0.055340, -0.294410, -0.383430, 0.478360, -0.659310,
0.152480, -0.033210, -0.365010, 1.317980, -0.441150, -0.175500, 0.281520, -0.368780, 0.342460, 0.010820,
-0.266640, 0.260610, 0.803600, -17.753599, -1.022680, 0.015910, 0.131880, -0.080820, -0.346880, 2.194020,
0.498100, 0.201570, 1.159880, 0.117750, -2.461100, 4.537180, 0.744730, 0.434310, -0.152160, -2.215950,
-1.707190, -1.221420, 0.451300, -1.519430, -1.236190, -0.864640, -1.148640, -0.274570, -1.739630, -1.179090,
-0.898440, -0.774880, -1.273220, -1.193480, -0.999520, -0.976660, -1.295740, -1.138830, -0.338960, -0.513040,
-2.169630, -1.888220, -1.417420, -1.341120, -0.943240, -2.450500, -0.338030, -1.322610, -0.658490,
-2.445530, -0.505360, 0.533020, 0.036460, 0.167690, 0.040270, -0.339470, 0.019030, -1.352320, 0.933830,
1.580170, -0.417440, 0.635510, -1.596420, 0.442300, -1.097650, -0.320520, -0.420380, -0.230740, 1.466900,
0.215160, -0.449630, -0.906030, -0.530480, -0.849850, 0.542710, -0.941030, 0.573340, -1.429290, -0.815620,
-0.575680, 5.685570, 1.802420, 0.818250, -0.397130, -0.595400, -1.974840, 0.971950, 0.594750, 0.490940,
-1.649810, -0.149400, -0.207780, -1.465690, 1.125830, -0.405200, -1.068550, 1.474330, 1.131920, 0.561700,
-0.252210, 0.106490, -0.339600, -1.059170, -1.293270, 1.157560, 0.544560, -0.478730, -0.923260, 0.521350,
0.182090, -1.170020, -0.017190, -0.124980, -0.841390, -1.044390, -2.939740, -1.172750, 0.520200, 0.683670,
-1.282700, -0.175390, 1.909200, 0.878360, 0.362550, -0.884000, 1.204590, -0.067390, -1.407640, -0.312710,
-0.516930, 0.899440, -0.094190, -0.569850, 0.849100, 1.404330, 0.188980, 1.898640, 0.545140, -5.399880,
1.434120, -0.953450, -0.388340, 5.823400, 0.434170, -0.377990, 0.592550, 1.389880, -0.398940, 0.704070,
0.041230, 0.442410, -0.648710, 2.371630, -0.382610, -1.879830, 0.400960, 1.146910, -0.476700, 2.550650,
1.875440, 0.365890, -1.103840, 0.196980, 0.435690, 1.759550, 4.506130, 0.657860, -1.846220, 1.822910,
1.510470, -1.299130, 1.811840, 1.662610, 2.108680, -0.956320, -0.477110, -0.516430, 8.467440, -5.673780,
-1.474240, -2.360670, 6.063630, -0.865800, -1.319880, 36.100559, -2.141960, -0.475030, 1.440080, -3.495940,
0.698930, 0.245160, -0.282100, -0.293280, -0.514070, 0.164120, 0.716620, 0.259650, 1.507780, 1.061140,
-1.239220, 3.534270, -0.387670, -0.754480, -0.825520, 0.153400, -1.256410, 2.200490, 1.218190, -0.087090,
-0.082890, -1.878380, 7.853180, 0.470330, -1.358820, -0.983870, -1.491450, -0.019130, 2.220950, 0.577060,
-0.701360, -0.806010, 1.149720, 1.773990, -0.110660, -0.755600, -0.381660, -0.658630, -0.473580, -0.711460,
0.195030, -0.615370, 0.687230, 1.338530, 1.964140, 2.676170, 1.925070, 0.578980, 2.354650, -0.293930,
-0.038860, 0.643380, 1.309430, 2.139250, -0.357200, 0.647570, -0.143590, -0.278190, 1.803360, 0.031930,
0.880540, 0.909000, 0.528940, 0.139640, -2.264890, -1.041930, 0.535950, 1.172040, 2.966080, -1.398030,
-2.684570, 0.031210, -0.134780, 0.428680, 2.562210, 0.144680, 1.878730, 0.570390, 1.575300, -0.152880,
-0.880510, -0.499580, 0.350070, -1.105310, -0.100700, -0.146080, 0.096050, -1.012020, 0.802130, 0.766670,
-0.874780, 0.671210, 1.130140, -1.009620, -0.348840, 0.396680, -0.526610, 1.593150, -0.485730, 1.627170,
1.636900, 0.709200, 1.158790, -0.705140, -0.097480, -0.430560, 0.844830, 2.834000, 1.221000, 0.040100,
-1.124940, 1.759550, -0.409310, 0.496410, -0.633980, 1.229380, -0.151610, 0.148220, 0.645200, -0.527120,
-3.154150, -0.671970, -2.876670, -0.396620, 1.091700, -1.315050, 0.049480, -0.025960, -0.692850, -0.889410,
0.172700, 0.819160, -0.629800, -0.745840, 0.976080, 0.597900, -0.582810, 0.146950, 0.959640, 0.420300,
-0.882310, -0.135240, -0.507440, 0.274840, 0.807040, 0.038630, -0.863640, 0.046440, -0.976810, 0.047790,
-0.473780, -0.565690, 0.921180, 0.792880, 0.017750, 0.377770, -0.809590, 0.045080, 0.499110,
-1.458330, 0.143950, 0.922330, 0.144210, -0.945020, -0.288240, -0.466800, -1.109940, -2.606110, -1.433020,
-0.032520, -0.530320, -2.591240, 0.443600, -0.329930, 0.652770, 0.021520, -2.232090, -1.116710, -0.444140,
2.272180, -0.900260, -0.453280, -0.278970, -3.051950, -1.902110, 0.243790, -4.355060, -0.796230, -5.849910,
-0.917100, -0.981490, -11.603500, -3.431370, -1.385460, 2.432980, -0.553170, 0.703720, 1.245570, 0.854910,
-4.650620, 0.613720, -1.680940, 0.842280, 0.890250, 1.666420, 0.704590, 0.370040, -0.648130, -2.190480,
1.827020, 0.159690, -1.164560, -0.139570, -0.493420, 0.220330, 0.794010, -0.953710, 0.707940, 0.424250,
-0.742280, 0.060680, 0.724950, -1.138240, -1.192590, 1.242650, 2.692510, 0.712080, -0.168280, 1.900100,
-0.639210, -0.599380, 2.493530, -2.755490, -1.102540, -1.743000, -2.057080, -3.975450, -1.249920, 0.688980,
-1.827970, -0.363320, 1.384860, 0.023100, -0.950220, 0.736790, -3.301580, -1.196290, 1.569040, 1.798340,
0.654410, 1.034130, -2.319260, -0.968500, -0.530620, 1.981510, -0.076720, -1.476150, 1.173890, -0.543220,
-0.528900, -0.661370, -0.837850, -2.679120, 0.089690, -0.300290, 0.901880, -0.164260, 0.663240, -0.376290,
-0.122610, -1.073070, 0.029190, -0.810550, 0.381540, -1.502800, -5.320870, -2.014880, 8.184000, -1.936750,
-0.845260, 1.293800, -2.139810, -3.315170, -2.327050, 0.724930, 1.115140, -0.194860, -2.750030, 0.622320,
0.991720, 1.884960, -3.856830, -0.572570, 1.791870, -16.006069, -0.076820, -0.220220, -0.264820, -1.510510,
0.209300, 2.884040, -0.489680, -0.220500, 0.306150, 1.261890, -1.410630, 0.271580, 1.110190, 1.849940,
-2.056580, -3.085150, 1.749020, 0.412690, 1.343520, -0.038720, -0.865230, -0.996890, 2.317100, -0.754570,
1.035750, -2.596400, -3.021040, -3.026080, 4.443470, -1.036790, 0.343770, 0.467010, -3.078820, -0.663670,
2.343680, -0.173890, -0.030670, 0.996640, 0.533520, 0.204730, -0.938670, -0.456050, 1.659590, -0.923430,
-0.545930, 2.252260, 0.259540, 1.485310, -0.752650, -0.121840, 0.679120, 0.866300, 0.352410, -1.053640,
-2.551890, -1.310410, 0.251240, 1.318610, -0.691480, -1.047770, -0.009890, -1.369140, -0.505920, 0.362340,
2.838300, -3.202720, -0.704110, 0.997060, -0.409000, -1.432140, 1.420260, -1.187650, 0.377540, -0.713820,
3.469850, -0.727360, -0.461090, -0.769260, 0.204670, -2.586680, -0.581620, -0.560990, -1.113240, 0.949460,
0.150530, 0.556900, 0.378000, -0.026760, -0.799880, 1.125860, 0.887640, 0.758030, 0.584990, -0.494610,
-0.469480, -1.528690, 1.595740, 0.846690, 0.324000, -2.494710, -0.615010, -0.899780, -0.943760, -1.306350,
1.153240, -0.636570, -0.502470, -1.078270, -0.089570, 0.111970, 1.375940, -2.402300, 0.684250, 0.139650,
1.203460, 0.032690, 0.114630, -13.991600, 0.621040, -0.717910, -0.307110, -0.471640, -0.843390, 0.026580,
0.033260, 0.727760, 0.967210, 0.640490, -1.045440, 0.772370, -2.313090, 1.060330, -0.715360, 0.649290,
-0.461220, 0.477000, 0.372410, -0.256390, -0.333890, 0.875900, -0.550650, 0.592460, 0.674850, 0.121010,
-1.242980, 0.565410, 0.267340, 0.533810, -0.950980, -0.756580, -0.640950, 0.731400, 0.733720, -0.878380,
0.629460, -0.761110, 0.549950, -0.170360, 0.869460, 0.679420, -1.314280, -0.275980, 0.328160,
-1.083870, -1.526170, 2.142340, -1.178260, 1.337170, -0.150400, 3.955250, -0.409090, -0.189340, 2.322340,
0.057200, -0.304890, 1.294320, 0.314660, -0.026150, 0.904900, 0.072770, 0.588640, -0.405500, 1.871140,
0.430960, 0.062810, -0.650420, -0.185190, 0.133570, 0.169520, -0.937870, 0.508630, 1.404680, 0.344630,
0.475870, 2.115670, 1.545170, -0.177170, 0.253420, 0.830800, -1.261530, -0.584700, 0.549380, 1.234570,
0.250030, -0.947080, 0.886120, 0.469860, -0.221740, -2.803510, 1.377310, 0.281730, 2.236810, -0.011310,
2.981170, 0.659260, -1.088600, -0.957270, -0.444550, 2.337780, -0.903900, -0.022930, 0.100310, -1.510160,
2.530410, -0.559660, 0.830740, 1.135820, 0.884230, -0.846590, 0.036900, -1.027040, -0.348090, -0.825950,
0.784370, -1.042930, -0.019130, 0.360480, 3.827640, -0.478780, -1.113050, 1.121840, -1.408900, -1.455400,
0.754070, -1.224610, 0.634320, -2.130640, -1.135240, -1.297850, 0.472850, -0.069280, 0.689290, 0.322610,
0.152610, -1.028590, 0.055170, 0.206400, -0.063810, 2.181720, 1.042110, 1.557890, 0.476230, 0.994300,
-2.023430, 0.099470, -1.023670, 0.769180, -0.121230, 0.999230, -2.519140, 0.922320, 0.995290, 1.180670,
-0.693550, -1.580790, -0.808700, -0.481990, 1.617440, 0.580540, 1.595060, 1.455250, -0.402060, -3.414610,
1.256320, 0.044400, 1.172850, 1.660510, 2.685470, -2.227990, -1.729650, -2.092130, 1.776250, -1.480030,
-1.748860, -0.032520, 2.766560, -0.351050, -2.075970, 7.541660, -0.405760, 0.132540, 0.259010, -1.300920,
0.799250, -0.881760, 0.971920, 1.141640, 1.091320, 1.538530, 0.077340, 1.530910, -0.079850, -1.307170,
0.825640, -0.113160, -1.656670, -0.410900, -0.766750, 0.768710, 1.426100, 0.688040, 1.602990, 0.324280,
0.961940, 0.201700, 0.091300, -0.659890, 0.633860, -0.598840, -1.275520, -0.644170, 0.649930, -0.381030,
1.598210, 0.428050, -0.056430, 0.653570, -1.073780, -0.663990, -0.938540, -1.402160, 0.021180, -0.663760,
-0.744350, -0.236650, 1.054360, -0.246470, -0.612340, 2.329270, 0.591630, 0.522380, -2.478210, -0.784250,
-0.922500, 0.163970, -0.669650, -0.336980, 0.766820, -0.336970, -1.629260, -0.896530, -0.701940, 1.491740,
0.984360, 0.146690, 0.727270, 1.183880, -2.145180, 0.557350, 0.664310, 0.127460, 0.647390, 1.198410,
-0.648870, -1.119960, -2.030890, -0.473830, 0.617340, -0.803590, 1.557960, 1.360320, -0.859810, -1.126380,
0.265210, 0.496010, -0.086120, -0.424850, 1.459090, -0.997070, -0.993400, 2.325660, 0.229560, -0.486710,
-0.167960, -0.730940, 2.224610, 1.770540, -0.748250, 0.204690, -0.704820, 1.005280, 0.473110, 0.563850,
-0.401510, 0.149290, 0.842860, -1.628220, -1.116850, -0.191980, 0.385300, 0.535300, -0.193040, -0.276410,
-0.895420, 0.810040, -1.267030, 0.399880, 0.931980, -0.523590, 0.064660, 1.999490, -0.724190, -0.528530,
0.440130, -0.297510, -2.278260, -1.522950, 0.331300, -1.439910, 0.779270, -0.010620, -1.126950, -0.775100,
0.748080, -0.020890, -0.159770, 0.351410, 0.036250, -0.419730, 0.750560, -0.771660, 0.036970, 0.427480,
-0.270090, 0.124320, -0.654780, -0.900610, -0.015630, -0.279170, -0.621760, -0.845840, 0.497370, -0.413720,
-0.733000, 0.043690, -0.592890, -0.285130, 0.031890, -0.626770, -0.320740, 0.016140, -1.028660,
1.535880, -0.002890, -0.552950, -2.128570, -0.265650, 2.506680, 0.111090, -0.624580, -0.854840, -0.919150,
-0.488730, -0.891560, -0.111770, 0.175270, -0.024620, -0.279820, 0.288520, 0.740920, -0.512300, -0.435320,
0.303580, 0.143200, -0.995400, 0.590360, -0.747580, 0.121000, 2.298660, -0.898480, 0.010070, 0.282470,
-2.201570, -0.388770, -0.370610, 0.678480, -1.256020, -1.233850, 1.206430, 0.317700, -1.658240, -0.251920,
0.948950, 1.450490, 0.208890, 0.233110, 0.754820, 2.042710, 0.170410, -0.630660, -0.319360, -0.239450,
-0.515240, 0.525600, -2.753730, 0.922630, -0.040630, -0.772270, -0.018810, 0.120460, 0.110610, -1.268260,
-0.599500, 0.644550, 0.172180, -0.004770, -1.006730, 0.687700, -1.487420, 1.184540, 0.667690, 0.085590,
0.311870, 0.502650, -0.414490, 0.886390, 0.648550, 2.387180, -1.413170, -2.785050, -0.371920, -0.446350,
0.655080, 0.284550, -0.802040, 1.051440, -1.629500, -2.043200, 0.724760, -0.084720, -0.410180, -0.156900,
-0.192600, 1.431410, -0.747470, 0.251580, 2.001880, 0.134490, 0.176290, 0.866610, -1.557600, -0.458380,
-1.329650, -0.198840, -0.697020, 0.363920, -0.777730, 0.323920, 0.425060, -0.750440, -2.154560, 0.076920,
-0.113480, -0.021080, -0.430360, 0.114600, -0.646600, 0.250660, 0.596780, -0.537880, -1.116950, -0.999430,
0.636860, 0.647820, -0.355480, 0.003780, -0.159080, 0.481200, -0.926850, -1.039500, 1.231710, 0.203080,
1.142280, -2.235380, 2.754890, 0.390770, -0.005810, 5.622570, -1.006230, -0.254960, 1.310100, 0.529470,
0.355680, -0.809480, 0.720340, 0.378340, -0.964520, -0.451420, -0.384670, 0.410330, -0.568030, 0.364750,
-1.464420, -0.398210, -0.222580, -2.258660, 0.891100, -1.460450, -0.521930, -0.051720, 0.297670, 0.307040,
-2.911230, 0.880820, 0.506630, 0.193670, -0.632870, 0.836510, 0.664010, 0.006630, -1.601140, -1.718980,
0.786520, 1.051460, -1.975780, -0.234820, -0.027480, -0.607830, -0.314210, 1.226210, 0.383160, -0.376600,
-0.803130, 1.775570, -0.265060, 1.939280, -1.425940, 1.421340, 0.492300, 0.229440, -0.484940, 0.234660,
-2.829890, 0.012070, -1.347760, -0.511310, 0.247210, 0.321690, -0.539400, -1.115330, -0.929330, 0.595460,
-0.523170, -0.684040, -0.182070, 0.159230, 0.180370, 1.040610, 3.059850, -0.331330, 1.475800, -0.088500,
-0.830540, 0.606950, 1.088430, -1.344250, 0.748680, -0.561500, -0.607640, -0.633360, -0.234260, -0.492570,
-2.975900, -0.912070, 0.656380, -0.943960, 0.652800, -1.840210, -0.909500, -0.758210, -1.103620, 0.717620,
0.144540, -0.925580, -0.213620, -0.235890, -0.362200, -2.013430, -1.008090, -0.866550, 0.557070, -1.285730,
0.459490, -1.469990, -0.382280, -0.686000, 0.957560, -1.660000, 0.918490, -0.210950, -0.069610, 0.674180,
-0.298520, 0.953800, 0.653960, 5.138920, 1.822220, 12.725800, -1.755130, 0.124700, -1.076110, -0.071350,
-2.660750, -2.054940, -0.107170, -1.394420, 2.408140, -1.359190, -0.998020, -0.369840, -0.870350, -1.228400,
0.325740, -1.574720, -1.196160, -0.110680, -1.494340, -0.238140, -0.079790, -1.240050, -0.425470, -1.901120,
-0.366730, 0.731070, -0.611680, 0.219280, -0.719880, 0.320400, -0.501440, -1.512140, -2.615050, -0.586120,
-0.175630, -1.299520, 0.045940, -1.476210, -0.186700, -0.469560, -1.522330, -0.818700, 0.208610,
-0.441270, -0.098880, 0.747270, -0.946970, 1.609740, 1.007750, -0.189990, -0.018810, 1.260610, 0.215090,
0.204530, -0.146520, 0.765090, 0.284830, 0.091370, 0.621850, 0.472570, -0.985570, 0.190310, 0.277740,
-2.190110, 1.629620, 0.481690, 0.656030, 0.717770, -0.845790, -0.091800, -0.488450, 0.139910, 0.534550,
-2.464400, -0.010440, 0.163160, -0.475240, -0.634850, -1.120240, 0.336300, 0.617220, 0.105550, 0.350960,
0.380910, -0.303970, 0.577280, -0.096940, -0.028650, 0.095080, 0.707140, -0.889630, -0.394330, 0.485960,
0.145050, -0.469560, -0.111570, -0.281620, -0.119710, 0.138800, -0.504150, -1.099410, 1.013040, -0.954820,
-0.922450, 0.038630, -0.476560, -1.258080, -0.075300, -0.725990, -0.633610, 1.451370, 0.523650, -0.573400,
-1.078490, 0.305400, -0.192210, 0.151910, 0.061120, -0.630590, -0.705430, -0.606320, 0.541870, -0.191290,
-1.017680, -0.467500, -0.326550, -1.825520, -0.023920, 0.588580, -0.096140, 1.302170, -0.609030, -2.993780,
-0.133740, 0.021960, -1.556790, -0.464860, 0.494900, 0.650100, 0.059230, 1.337830, -0.170570, -1.378130,
0.024320, -0.031690, 0.714940, -0.566840, -0.997540, 0.570030, -1.112860, 0.707370, -0.394830, 0.247520,
-0.535130, -0.988830, -0.161590, -0.626970, 0.906730, 0.164840, 0.469980, 0.333090, 1.784790, 0.472400,
0.400680, -1.422990, 0.991230, -0.771750, 0.364310, 1.175720, 0.193730, 0.151890, -0.990670, -0.383630,
-0.185780, -0.054280, 0.479100, 0.314100, -0.520760, 3.394760, 0.831180, 1.702350, -0.657290, -2.164670,
-1.478520, -1.230030, 0.237260, 0.506120, 1.594860, -0.279940, 0.836830, -1.230800, 0.750700, 0.240090,
-1.208060, 0.421510, 0.373610, -0.241610, 0.656920, 0.972310, -0.969930, -0.180010, 0.351130, -0.502940,
-0.784660, 1.005190, 0.668530, 0.524910, -0.566180, 0.870410, 0.730210, 0.665550, 0.555720, -0.368630,
0.215940, -0.006290, 2.832780, -1.078050, 1.675930, 1.094770, -0.125100, -1.501340, 1.344300, 0.001860,
1.077760, 0.691750, 1.232680, -0.817940, 0.671040, 1.578040, 0.244230, -1.289040, 1.175260, -1.043840,
0.222890, 0.623830, -0.213540, -0.783720, 0.704870, 0.299560, 1.241180, 1.515180, -0.337870, -0.099840,
-0.704230, -1.141830, -1.136740, -1.836620, -1.456910, 0.564400, -1.250870, -0.464930, 0.024600, -0.051600,
0.198750, 0.858040, -1.413870, 0.050150, 0.280520, -1.165710, 0.249350, 0.289310, 0.362530, 0.961340,
1.571970, 0.602620, -0.783460, -0.081060, -0.392450, -1.205560, -1.085210, -0.350080, -0.024660, -0.190380,
-1.250950, 0.007960, -0.977220, -0.274220, 1.105440, 1.337010, -0.092940, 0.392150, 2.758560, -1.828370,
-0.514300, 0.403120, -0.425560, -1.447010, -0.447430, -1.143410, 1.160630, 0.321190, -1.420710, -0.242720,
-1.214670, 0.348310, 0.841690, 0.656740, 0.494090, 0.108780, -0.981190, -2.055190, -1.544820, 0.390460,
-1.410770, 0.553080, -0.629540, -1.806080, 2.274930, -0.672450, -0.654500, -1.282770, -0.442840, -0.231640,
-1.493360, -0.635230, -0.771250, -0.065510, -2.133790, -0.941660, 0.168110, 0.015590, -0.906360, -0.152630,
-1.230600, -0.812150, 1.363870, 0.153630, 0.355240, -0.811960, -0.885660, -0.011500, -1.049270, -0.815770,
-0.839060, -0.801650, -0.129450, -0.845340, -1.318160, 0.412350, -0.297790, 0.102040, -0.930600,
-0.136150, -1.422130, -0.416050, -0.240150, -0.657980, -0.303820, -0.672580, -0.812430, -0.953930, 1.149550,
0.166660, 0.279020, -0.788830, -1.893130, -0.527550, 0.884660, 1.353600, -0.763260, -1.078440, -2.947930,
-2.052800, 0.895120, -1.386870, -0.809740, 0.602430, 0.391180, 0.461190, -0.445680, -0.534420, 0.470920,
-1.340240, -1.309820, 0.617050, 0.124460, 0.266950, 1.278600, -1.348050, 1.435980, 0.744680, -0.806450,
-0.016970, 0.046320, 0.357660, -0.780190, 1.163590, -2.155470, -1.210980, -0.198940, -0.146730, 2.897190,
-0.818640, -1.120610, 0.845950, 0.139760, -0.038540, -0.598490, 1.366450, -0.275940, 0.822350, -0.205840,
-0.430660, 0.294450, -0.179490, -0.596320, 0.830780, 1.008560, -0.435560, 0.026120, -0.858810, -0.648530,
-0.419100, 0.990260, -0.649870, -0.241360, 0.800350, 0.141840, -0.458230, -0.152150, -1.061550, 0.138740,
0.233110, 1.602930, 0.116370, 1.133290, -0.776880, -0.146170, 0.173460, 3.528410, 0.944520, -1.342860,
0.458920, -0.457490, -0.235610, 0.023550, 1.510260, 0.381490, 1.524860, 0.725230, 0.641850, -0.179100,
0.648780, 0.656920, -0.134470, 1.892720, 2.212040, 0.781580, 0.406090, 0.956130, -0.324500, -1.177430,
1.354550, 1.313630, 0.478900, 0.134600, -0.684610, 0.814490, 0.223670, 0.013930, -1.025630, 2.083120,
-0.463930, -1.875610, 0.841020, 1.751850, 3.295470, -0.643830, -1.133120, -0.287870, 0.004170, 0.417700,
-1.846890, -0.856770, 2.996740, -0.679400, -0.993790, 5.938630, 0.892910, -2.131920, 0.694300, 0.878100,
0.713470, -1.412560, 0.191270, -1.583380, 1.042220, -0.620630, 1.237930, -0.519310, 1.905120, 0.843010,
0.508760, 0.875930, 0.939790, 1.099140, 0.574370, 0.725040, -0.633150, 0.315220, -1.161890, 0.736030,
-0.638480, 0.531130, 4.116040, -0.494030, 0.517280, 0.958680, -0.987920, 0.598480, 1.420030, 0.418030,
-0.258110, 0.109020, 0.130460, 0.562920, 1.583750, -1.274060, 1.261890, -1.384340, 1.662010, 1.592420,
-1.351280, -1.138460, 0.431840, -1.154760, 1.346600, 1.616620, 1.509960, -1.262700, 2.574040, 1.357080,
1.503700, 0.251880, 0.410370, 2.502120, 0.672020, 0.065330, -1.564730, -0.493930, -0.268950, -1.139990,
0.500400, 2.418320, -1.275430, 0.708160, -0.266000, -1.127640, -0.730130, -0.075920, 0.239850, -0.532880,
-0.125720, -0.013490, 0.197820, 0.904600, 1.567290, -0.219090, 0.439630, 0.711970, 0.054510, -0.693640,
0.220410, -1.301720, 1.147230, -0.257080, 0.194080, -0.975920, -2.224650, -0.337040, -0.095570, -0.589570,
0.066860, 1.183460, -1.024630, 0.342990, 0.039720, -1.402920, -0.187590, 0.011980, -1.470770, -0.425800,
0.890970, 0.938390, 0.323250, -1.641260, 1.544620, -2.426950, -0.119170, -0.116240, -0.470040, -0.396490,
-1.348440, 1.601900, -0.121920, 0.858790, -0.943980, 0.781940, -0.203630, 1.401970, 0.001240, 0.126290,
-0.769920, -0.683300, -1.439820, -1.496200, 0.114770, -1.958890, 0.826530, 0.162770, 0.310510, -0.290700,
0.650260, -0.632910, -1.009940, 0.343850, -0.197670, 0.766370, -0.011490, 0.245360, 0.271690, -0.040560,
0.293430, 0.792330, 0.812490, 0.142820, 1.029480, 0.390230, -0.128610, -0.633760, -0.012230, 0.915640,
-0.145050, -0.311310, 0.303850, -0.530990, -0.505080, 0.221750, 0.773430, -0.546390, -0.368110,
0.867580, -0.334330, -0.770960, 1.094590, 3.414360, 0.527260, 1.030060, -0.872130, 0.092530, 0.279720,
-0.919920, 1.345830, 0.149130, 0.142310, -1.800350, 1.144930, -1.026210, -0.070290, 0.799090, 0.270380,
0.579270, 0.189430, -0.783830, -1.157930, -0.295540, -1.073330, -1.710090, -0.920590, -1.469340, 0.229540,
-3.106170, -1.227620, -4.683160, 1.002440, 1.811750, 0.654580, -1.082130, -1.250920, 2.170690, 1.594130,
-0.895070, 2.239350, 1.132570, -3.971590, 2.071590, 2.205710, -0.445860, -0.132340, -0.734240, 0.295590,
-1.273550, -0.256030, -0.870990, -1.513710, -0.198170, -1.123230, 0.197300, 0.590180, 1.050430, 0.732630,
-0.732650, 0.380230, 1.371420, -1.327080, 1.316270, -0.761930, 0.725620, 1.108410, -0.513940, -1.232740,
-3.563540, 0.266510, -0.532200, 0.236820, 0.146870, 0.792320, -3.424520, -0.056280, -2.485430, 0.936310,
0.057850, -0.713190, -4.185810, -1.249750, 0.323930, -0.454690, -1.373530, -0.650420, 1.241880, -2.406900,
1.031940, 0.696970, 0.061470, -0.446240, -0.065780, -4.622040, -0.200380, 0.686880, -0.168040, -1.783200,
0.622840, 0.195820, 0.230230, 0.499560, 1.227390, -0.127070, -0.769220, -0.207510, 0.055660, -0.869750,
-0.506120, -0.382410, -1.991420, -0.921580, -0.367860, -4.611190, -2.117330, -3.498490, -1.541510, 0.001910,
-1.347470, 0.801670, -1.031750, -1.468730, -0.967610, 0.469690, 1.632600, 1.649650, -0.581940, -1.240750,
0.904230, 1.041080, -0.073370, 1.901120, 0.676640, -0.209340, 0.507180, 6.832290, -0.964100, -2.384080,
-0.048170, -0.355150, -0.457200, -0.378890, 0.711470, -2.217820, -0.480860, -0.539500, 0.560240, 1.697550,
-1.681070, 0.502970, -0.149970, 0.399070, -1.227010, -0.994170, 1.711890, 0.367090, 0.858000, 0.855010,
0.255930, 1.055020, 1.511100, -0.352160, -0.127930, 0.966960, -0.181040, 0.555770, 0.690720, 0.967280,
-1.277800, 0.313080, -0.544030, 0.268540, -1.001900, -1.472200, -0.979350, 0.307100, -0.461820, -0.514890,
-0.315840, -1.062830, -0.447090, -0.016660, 2.118630, 0.749120, -0.527550, -0.942030, 1.772750, 0.022630,
-0.599470, -1.536660, -1.127120, -0.854480, 0.306720, 1.065000, 1.125720, 1.072970, 0.016450, -2.520870,
-1.811790, 0.485390, 0.227910, -1.639160, -1.383720, -0.607670, 1.150980, -1.283160, 0.671590, -0.960420,
0.144230, 0.036620, 0.726400, 0.853350, -1.366520, 0.164140, -1.022190, 0.491300, -0.267690, 0.511010,
-0.514980, -0.002450, -0.973530, 0.892000, -0.330720, 0.803720, -0.967350, 0.610420, 0.568110, 0.824130,
-1.185400, 1.356580, -0.214920, 0.735110, 0.221810, -0.444040, -1.371150, -0.760360, 1.086500, -0.557700,
0.855690, -0.034070, -0.359490, 1.038100, -0.192140, -0.172130, 0.573900, -0.330950, 0.270480, -0.425630,
-2.433780, -1.018060, 0.026830, 15.221100, -0.310780, -0.638280, -2.015730, -0.980170, 0.082820, 0.842540,
1.170090, -1.208330, 0.192100, -2.128370, 0.833680, -0.773390, 0.277680, -0.254890, -0.480760, 0.632690,
-0.230690, -0.549770, -0.009240, 0.018410, -1.011170, -0.267110, -0.574780, -0.754610, -0.035090, 0.432820,
-1.074550, 0.267860, 0.447230, 0.641360, 0.953990, -0.746450, 0.633750, -1.020210, -0.657050, 0.226410,
-1.161730, -0.019300, -0.716080, -0.000520, -0.532520, -0.557480, -0.750940, -0.389900, 0.708910,
1.889600, -0.731590, 0.347120, 0.936730, -1.091190, 0.368830, -1.319380, 0.180340, -0.047550, 0.545540,
0.908320, 0.249930, 1.565420, -0.142800, -2.412500, 1.183740, -1.239040, -0.453190, -0.810110, -0.565040,
0.174810, -1.326750, 0.416820, -1.470140, -4.479920, -4.082140, 0.896490, -1.477330, -4.014760, 0.749380,
-0.925040, -2.593420, -3.990930, 1.752030, 1.125920, 0.727590, -0.660860, -0.290730, 2.896180, 0.046190,
-4.647080, 1.154900, -0.435410, 0.614350, 1.798740, 1.407620, -0.846430, 0.344930, -0.220350, -0.209390,
-2.751230, -3.279570, 0.000820, -3.659850, 1.753300, -0.419730, 0.158100, 0.123460, -0.216150, -0.974930,
-1.293630, 0.167490, -0.139660, -4.156800, -0.094780, 0.178950, 0.256040, 0.003050, 0.903760, 0.524850,
-0.373370, -0.892650, 0.488530, -0.110430, 0.454950, -0.380400, -0.254420, -1.990030, -0.163270, 0.772500,
-2.472200, -0.939810, -0.491720, -0.833350, 0.404010, 0.384180, -0.286720, 1.576410, -0.082520, 1.050260,
1.074920, -1.102480, -0.631980, 0.953430, 1.184010, -1.240810, -0.711150, -0.222830, -1.915030, -0.529340,
0.313510, 0.647410, -1.282900, 0.109480, 0.120420, -0.680340, -0.776950, 0.744040, 0.598680, 1.913330,
1.172580, 0.611790, 0.895450, -0.476130, 1.296650, -1.021060, -10.908070, 0.330690, -4.459960, -1.416680,
-0.862470, -0.719880, -0.052400, -0.500770, -1.586020, -2.592340, 1.966010, 3.251350, -6.343700, -0.628070,
2.778270, 1.189180, -1.437270, 0.556120, 2.257500, -2.774330, 1.794940, 5.616110, -0.824970, 0.465230,
0.059630, -0.182590, -0.407780, -0.996550, 0.373580, -0.280670, 0.764860, -2.518340, 0.746250, 1.049070,
-0.434340, -0.544370, 0.479430, 0.363540, -1.430510, -1.567730, 1.341170, 1.281500, 0.275220, 1.310760,
-2.093320, 0.661200, 0.952440, 0.377010, 1.222040, 0.300480, -0.601790, 0.327880, -0.133580, -0.052630,
-0.374380, 1.084650, -0.324410, 1.720650, -1.159510, -1.208140, 0.881220, -0.075330, 0.212570, 0.767680,
-0.337370, 1.574680, -0.168490, 0.986670, -1.052430, -0.350620, -0.658980, 0.507150, 0.100340, -0.737500,
-3.942580, -0.647400, -1.186680, -0.782600, -2.772870, 0.194510, -0.652230, 4.148940, 1.729140, 0.717760,
-1.512980, 0.628300, -0.617590, 3.266630, 1.247350, -0.826340, -0.481110, -0.940550, 1.315740, -0.787970,
-0.233870, 1.235640, -0.231870, 1.511940, -1.112470, -0.067690, 0.181470, 0.404650, 1.296960, 1.147210,
-0.939880, 0.761210, 2.264240, 0.120530, 1.424490, 0.403720, 1.283740, 1.023150, 0.306080, 0.899390,
-0.209490, -0.370620, -0.748120, 0.724850, -0.476060, 2.526560, -1.223390, -0.145160, -0.178820, -0.431610,
-0.456910, -0.278600, 0.086380, 0.618400, -0.585350, 0.476930, -0.653010, 1.021460, 0.460130, 0.114520,
-0.293850, -0.200410, -0.261750, -2.325640, 1.192500, 0.867750, -1.125080, -0.800610, 0.206700, 0.164270,
-0.153000, 0.568110, 0.785330, -0.244270, -0.009500, -1.027980, -0.075920, 1.108920, -2.494500, -0.364170,
-0.621900, -0.505030, 0.352630, -1.193720, 1.570790, 0.568950, -1.320130, 0.493210, 0.300590, -1.657160,
-0.267600, -1.092190, 0.745770, -0.843790, -0.270100, -0.662760, -0.004550, -1.156550, 0.012970, -0.314370,
0.186830, -0.592480, -0.924020, 0.094240, 0.410990, -3.136580, -0.750390, -0.810750, 0.648810,
-0.230470, 1.207240, 0.885020, 1.649090, -0.050050, -0.712740, -0.207420, 0.196640, -0.436780, -0.326690,
-0.290100, -2.998360, 0.845850, -0.197740, -1.767320, -1.396270, -1.566210, 0.377410, -0.240940, -1.671340,
0.164040, 0.199420, -1.843340, -0.723820, -1.410300, -1.062920, -0.552380, 1.131620, -0.441690, 1.256430,
-0.799210, -2.494710, -0.612540, 0.291970, 1.861140, 0.170360, 0.198120, 1.913520, 0.332320, 0.037440,
0.525950, 1.737490, -0.407930, -2.217720, 2.081630, 0.850940, 0.654980, -0.103750, -1.793210, -1.666500,
0.560620, 3.052980, 1.879350, 0.792220, -1.619810, -0.364870, -0.182120, 3.077960, 2.373880, -1.493900,
-1.080630, 1.236180, 1.104720, 0.568200, -1.480850, 0.012460, -0.822310, -0.410340, -0.926930, -0.131930,
0.631230, -0.813990, -0.273100, -0.384170, 1.108270, 0.975430, 2.360290, -0.311630, -0.724870, -1.067000,
0.163490, 0.251040, -0.284260, 1.023820, 0.681360, -1.753310, 1.037780, -0.257580, -0.522690, 0.026440,
-1.458640, -2.018740, -1.786720, -0.406290, 0.368830, -0.294390, -1.435650, -1.660530, 1.203430, -1.543640,
-0.077050, -0.832220, 0.754940, 0.037450, -0.295670, -1.313910, -1.223380, 0.741360, 0.556620, 0.682880,
-0.507200, 1.045280, -3.733920, -0.501920, -1.968890, 0.074210, 0.615990, -0.345030, -1.622510, 0.144700,
0.249400, -0.815040, 0.789740, -2.171070, 0.378740, 1.437170, 5.534010, 0.257690, 3.340320, -0.211270,
1.588180, 0.530260, -1.265300, 0.605990, 2.740360, 1.700740, 0.732940, -1.388310, -0.559260, -1.364100,
-2.601940, -0.961840, -1.317570, -1.163530, -0.294500, -1.096650, 0.283260, -1.082880, -0.092880, 0.106130,
1.744990, 1.825900, -2.523110, 0.975420, 0.404470, 0.790500, -0.215010, -0.529980, -2.864000, 0.043350,
-3.026140, 0.088050, 0.372680, 0.668190, 0.261550, 0.810560, 1.007880, -0.287680, 0.374790, 0.661040,
1.479610, 0.301380, -0.601430, 0.298090, 2.733390, -0.180470, -0.842230, -0.970990, 1.072830, 0.247570,
1.554170, -0.849400, -0.546560, -5.069920, -1.384290, 0.950870, -0.330810, -1.690580, -0.926450, 2.363710,
0.360920, 0.219080, 0.534750, -0.037100, 0.354260, 0.223320, -0.500320, 0.657350, -1.929840, -0.556910,
-0.951860, -0.606450, 0.283220, 0.719250, -2.131160, 0.290890, -0.278240, 0.629510, 1.875910, 0.533640,
0.527340, -1.496440, -0.794710, -0.294080, 0.826560, -0.968910, -0.520290, -0.908960, 1.120140, -0.398000,
-0.468070, 0.107610, -0.035460, -0.641590, -0.769140, 0.742120, -3.270010, -1.277790, 0.441630, -0.093270,
0.199690, 2.294040, -0.477380, -1.480070, 1.041870, 0.512480, 1.349210, 0.418970, 0.772290, 0.999480,
-0.182880, 0.110930, -1.216750, 0.807720, 2.219520, 1.555840, -0.280010, 0.467310, 0.249710, 0.158970,
0.140720, 0.165200, -0.972840, 5.053730, -0.834870, 1.420380, -0.503100, -0.681800, -0.998650, 1.214380,
0.890090, 0.706030, 0.874270, -1.600150, 2.288570, 0.166540, 0.248800, -0.602070, -1.139990, 0.618270,
0.013260, -0.393370, -5.738170, -1.368510, -1.389150, -1.555270, -1.377240, -0.615910, -0.804130, -2.327930,
-0.562150, -1.811950, -0.497670, -0.647530, -0.260230, -1.198500, -1.522210, -0.722350, -0.745930, -1.272760,
-1.230200, -0.932990, -1.573180, -0.407810, 0.297840, -1.079530, 0.311450, -0.569390, -2.281280,
0.423660, 1.239250, 1.008230, 0.204140, -0.883820, -1.507840, 0.863360, 0.086290, 0.074170, 0.769140,
-0.204740, 0.359170, -0.253290, -0.154960, 1.233340, 2.208010, 1.751610, -1.800360, -3.039980, 1.900020,
4.066300, -0.763860, 1.137280, 1.469750, 1.062920, -0.217330, -1.256390, 0.309890, -1.409160, 1.747960,
-0.802560, 1.940840, -0.128590, 0.048150, 0.673630, -0.400390, 1.218880, 0.204500, -0.723460, 0.989410,
-0.578150, -2.473280, 2.788080, -0.592350, -0.956090, 0.478680, -0.686420, 0.100400, -2.337000, 0.233340,
-1.619420, -1.726850, -0.706890, -0.717250, -1.341680, -2.274180, -0.751310, 0.995040, 1.145960, 0.348200,
-0.096050, 0.651870, 1.575110, -1.498440, 1.237740, -0.017490, -0.891550, 0.149300, 1.252470, -2.600660,
-0.632790, -0.446650, 1.220610, -0.791660, -1.309480, 0.154710, 0.896130, -0.715740, -0.178280, 0.945890,
0.486170, -0.958710, -1.524660, 0.461130, 1.491400, 1.189330, -0.088580, -1.203210, 1.854640, -0.677080,
0.096790, 0.164080, 1.058590, -0.901410, -1.286230, 1.685100, 1.258760, 0.113640, -0.023020, -1.700080,
-0.541530, 1.079120, 2.073870, 0.184020, 2.549510, 0.319510, 1.365160, 1.695190, 0.647310, 1.473580,
-0.886520, 0.294770, 0.879270, 0.319890, 0.724800, 1.627620, -0.745180, -0.538060, 2.094310, -2.004200,
0.057800, 1.094810, -0.977660, 0.377370, -2.339850, 0.215950, -0.551020, 0.047860, -1.136360, -1.008060,
-1.184190, -0.233660, -3.465700, 0.413610, 2.091850, -1.243090, 0.452140, -0.983660, 0.518670, 0.012390,
0.713640, -1.500720, -0.210680, 0.704240, 0.899400, -0.759190, -1.947060, -2.330060, -0.957050, 0.695370,
1.789760, 1.291450, 0.003480, 1.092410, 1.550220, -2.915670, 0.714700, 2.591150, 0.162110, 0.516690,
1.005210, -0.415820, -1.075460, -0.188250, -0.749240, -0.390270, -0.776410, 0.323120, -0.461660, -0.449020,
1.049490, 4.720080, -0.637810, -0.469770, -0.830120, 0.894770, 1.829240, -0.179500, -3.329950, -0.169530,
0.766530, 0.165520, -5.290830, 2.112200, 0.047720, 0.259960, 0.364320, 1.328070, 0.957750, 1.128330,
0.255620, -0.964020, -0.335290, 0.613550, -0.346380, -0.891600, 0.232210, 2.101410, -0.315230, 0.659290,
0.518860, -0.612810, -1.695520, 0.832490, -0.428230, 0.018270, 0.156560, -0.164080, -1.453740, 1.019810,
1.014640, -0.593670, 0.506760, 0.300020, -0.942920, 0.436350, -0.525870, 3.731780, -1.997170, 0.217300,
-0.223190, 0.597400, -0.599460, -0.530420, 0.019270, -1.706290, -0.764830, 1.032670, -0.822850, -0.259980,
-0.171020, -1.797200, -2.160510, 0.850610, -0.721190, -1.599630, 0.025990, 0.818820, -0.514490, -0.943840,
0.442450, -0.677980, 1.333290, 1.441050, 0.539000, 0.566310, 0.904170, -0.615800, -0.580340, -1.050810,
0.281680, -0.974320, 0.313830, 1.872960, -0.912590, -0.451870, 0.185020, -0.344400, -0.798150, 0.150790,
2.268460, 0.689180, 1.970810, 0.173470, 0.083430, 2.591810, -0.706200, 0.991720, -0.683430, -0.834430,
-0.287060, 0.206480, 0.194850, -0.181160, -0.926820, -1.266000, 0.956940, -0.318230, -0.066090, -0.935040,
-0.106780, -0.807210, 0.166700, 0.910210, -0.462000, 0.846550, 0.043010, 0.668710, -0.385580, -0.911560,
0.586760, -0.715760, -0.547630, 0.228340, -0.930800, 0.436950, -0.561430, 0.346660, 0.581640,
0.505340, -0.610230, -0.224060, 1.828410, 0.206960, -0.029010, -0.386180, 0.837270, -0.493090, 1.055650,
0.610210, -0.658040, 0.478580, -0.103390, -0.358160, 0.028790, -0.932520, -1.137300, 1.166450, -0.336970,
2.496340, -0.745860, 3.017870, -0.960280, -0.632700, 0.651090, -0.408850, 0.340690, -0.596560, -0.839340,
-0.542780, 0.547070, -0.766700, -1.809300, -0.928700, 0.338730, -2.551060, -1.290260, 0.754040, -2.063250,
-0.418320, -2.676850, -1.710710, 1.493900, 0.832310, 1.204810, 0.623520, -0.570370, -0.513730, -0.121900,
0.005460, -0.402590, -1.096040, -1.073420, 0.483060, -0.967020, -1.848470, 0.035490, 1.098390, 0.461490,
-0.475800, 0.362420, -1.168210, -0.947140, -0.604300, -0.848280, 1.715480, 0.452070, 0.266290, 0.022370,
-1.707700, -0.299950, 0.171010, -0.398820, 0.184110, 0.140710, 0.061830, -0.709630, -0.231570, 0.727440,
-0.195810, -1.709950, -0.219480, -0.656990, -0.083890, -2.974870, -0.006130, -1.114180, -0.764430, -0.127740,
1.131320, 4.409290, 3.483330, 2.597010, 0.101170, 0.867910, 0.228270, 0.214860, 0.315190, 1.063700,
1.490460, 0.277780, 0.505000, -1.004670, -1.241010, 1.135690, 0.844390, -1.285090, -1.005080, 0.031970,
-0.847270, 1.122290, 5.192020, -0.066330, -0.623000, -0.157220, -0.004510, 0.875430, 2.934000, 0.333790,
0.613240, -0.477750, 0.459190, 0.537120, 0.427540, 0.934280, 0.762470, -1.010930, -3.293600, -0.370220,
0.844910, 0.894790, -0.805610, 1.443800, -0.783950, -2.445620, -0.515440, 0.787610, 0.631570, 0.994070,
0.340720, -0.171560, -0.069800, 0.244720, -1.790170, 0.638640, 0.076610, 0.485290, 0.482820, -0.177440,
-0.427350, -0.803280, 0.347680, 1.119160, 0.639270, 0.087550, 0.160430, -0.715170, -0.222170, 2.215780,
0.603750, -1.120540, -3.775290, -3.288920, 0.458020, 0.035420, -1.454430, 0.973630, -1.423010, -2.239750,
0.533000, -2.714010, 0.917410, 0.628960, -0.680700, -0.608460, -0.584130, 0.280920, -3.404670, -0.074400,
1.512680, 1.254410, -0.347280, 0.286970, 0.337000, 0.895600, 1.037640, 1.421630, 0.485750, 1.395030,
0.451680, 0.663100, 2.314810, -0.213270, 1.167630, 0.168420, -2.292830, -0.793520, 0.667600, -0.395220,
-0.662190, 0.580850, -0.881400, 1.625430, 2.492870, -0.300930, 2.092140, 0.034880, -0.715400, 0.678570,
0.163000, -0.824440, -1.008990, -1.572100, -1.778490, -2.035930, -0.241220, 0.569530, 0.518860, 0.319720,
0.112700, 1.063720, -0.983340, -1.761790, 0.617170, 0.845320, 1.211320, 1.110370, -0.390920, 1.300250,
-0.574470, 0.241030, -0.081640, 0.292960, -0.815120, -1.235680, 0.861400, -0.291110, 0.244190, 0.083410,
-0.843940, 0.167960, -0.567610, 0.976540, -0.805070, -2.239880, 0.468820, 0.740980, -0.468100, 0.219540,
4.376870, -0.243220, 3.797150, -8.691780, 0.672660, -0.824070, -0.493630, -0.150380, -1.263260, 0.531000,
-0.562760, -0.928890, 0.997540, -0.533450, -0.132470, 0.506350, 0.503720, 0.612030, 0.298530, -0.492050,
0.181220, 0.906090, 0.443920, 0.010420, 1.261990, 0.956620, 0.565800, 0.377840, 1.125260, 0.100320,
-0.420380, 0.287110, -0.627390, 0.496090, 0.564000, 0.952130, -0.164630, 0.477560, 0.485210, -0.129010,
0.526800, 0.604670, 0.488100, 0.975380, 0.770780, 0.778460, -0.365690, -0.166000, 1.495570,
-1.331700, 2.398780, 0.149670, 0.020690, -1.016650, -0.672270, -0.198690, -2.953410, -1.113600, 0.634470,
-0.059920, -0.050750, 0.813400, -0.540390, -0.753500, -1.024380, 0.864990, -0.698190, -0.285990, 0.767040,
0.611200, -0.763540, 0.733040, 0.584560, 1.713970, 1.370240, 0.811160, 0.360810, 1.782770, -0.849730,
-0.283320, -0.362370, 0.856490, -0.339060, -0.004920, -1.035170, -0.200110, -0.175920, 0.250010, -0.058680,
0.236030, -0.844720, 0.771670, -0.973980, 1.936080, 0.050700, -0.519220, -0.208190, -0.580300, -0.042000,
-0.090430, -0.306660, 0.107000, -0.616640, 0.612360, 0.031500, 1.028570, 0.316120, 0.902730, -0.913250,
1.367260, 0.649940, 0.481710, 0.629620, 1.221150, 1.218220, 0.847960, -0.517620, 1.175370, 1.137450,
-0.723210, -0.541230, -1.046750, 1.634390, 0.032520, -0.668920, 0.090850, 0.966960, -1.301680, 0.746690,
0.256200, 0.560020, 0.357730, -0.055870, -1.438490, 1.797440, -0.157970, 1.600680, -0.281670, 0.599760,
-0.885360, -0.914760, 0.215340, 0.520650, -0.900050, 1.094680, -0.591470, 0.419180, 0.056370, 0.148990,
0.151110, 0.009420, -0.192840, -0.528690, -0.593130, 0.429300, -0.230980, -0.736480, 0.823580, 0.661260,
-0.536540, 1.070040, 1.111260, 1.141800, -0.904200, -0.647380, 0.495370, 0.292420, 0.788080, -0.277420,
-0.696770, -1.199990, 0.024790, 0.718750, 0.440750, -1.247080, 0.515340, 0.846690, 1.017240, -0.658560,
-1.873230, -0.974770, 1.009930, -0.257780, 0.707510, 2.656130, 0.624540, 0.444300, 0.284730, -0.158470,
-0.041630, 2.308200, 1.120730, -0.244910, -0.477350, -0.496700, 1.545750, 0.976310, -0.535290, -0.005720,
0.147310, 0.702540, 0.698900, 0.011270, 0.544770, 1.785650, -0.457530, -2.267650, 0.432050, -1.386780,
-0.465030, -0.584030, -0.775950, 0.762790, -0.724090, 0.604990, -2.623290, 0.528390, 0.685360, -2.423450,
-1.410540, -0.937860, 0.212900, 0.914260, 0.360380, 0.310240, 0.510820, 0.330550, 0.935290, 1.001930,
-0.522290, 0.540830, 0.600120, -0.980320, -0.474330, 0.584680, 0.716070, -0.687180, 0.595810, 0.149270,
0.197320, -0.633090, -0.391100, -0.614910, 0.784050, -0.763640, 0.594380, -0.915020, 0.570550, 3.835160,
0.733090, 0.724470, -1.390810, 0.825960, -0.311370, 0.091660, -1.269530, -0.209110, 1.537270, -1.448760,
-0.304860, -0.458300, -0.465890, -0.319160, -0.088680, -0.120370, -0.165400, -1.649280, -0.632250, -0.833460,
-1.032500, -0.072790, -0.519480, -0.215990, 1.862830, -1.001140, -0.264180, 0.244380, -0.091000, -1.017030,
-1.056780, 0.481110, 0.569670, -2.128090, 0.639560, 0.471260, -0.010280, 0.479490, -1.067500, -0.411150,
-0.762410, -0.074700, -0.225690, -0.134930, 0.975440, 0.448730, 0.794250, -0.559740, -0.146030, -0.197210,
0.055500, -0.867510, -0.329170, -0.077780, -0.841790, 0.439250, -0.583040, -1.801770, -0.410090, 0.509060,
0.786020, 0.478110, -3.488690, -1.732430, 3.130670, -0.457150, -0.216160, -0.396800, 0.250140, -0.007650,
0.116510, -0.604850, -0.400680, 0.571780, -1.322520, -0.038540, -0.215190, -0.538270, -0.672980, 0.466310,
1.157110, -0.307110, -0.540770, -1.184610, -0.895720, 0.713210, -0.072880, 0.722600, -0.038230, 0.451000,
-1.135020, -1.244970, 0.141270, 0.478880, -0.776710, -0.045420, -1.064820, -1.058100, 0.116870,
-0.871150, -0.839800, -0.657230, -1.156600, 0.745880, -1.191840, -0.477270, -0.483520, 2.394540, 0.418260,
-1.291730, -0.053820, -0.271970, 2.911230, -0.414650, -0.437110, 0.336570, -0.185010, -1.094510, -1.123450,
2.628310, 0.109550, -0.060620, 0.850760, 1.258610, 0.640390, -0.727340, 0.177550, 0.677390, -0.200530,
2.030750, 0.574770, 0.017820, -0.176910, -0.982230, -0.126370, -1.711680, 2.138010, -0.062050, -1.459720,
0.794030, -2.972880, -0.505850, 0.886110, -0.901480, 0.300150, 0.458220, 0.793660, -1.412200, -1.134180,
-1.032540, 1.155240, -1.749220, 1.371880, 2.405610, 1.501520, 1.013290, -0.454800, 0.342890, 0.847630,
0.296390, -0.330580, 0.434420, -0.274890, -1.352420, 0.484760, 0.794250, 0.192500, 0.170560, 0.094010,
0.912250, 0.746640, 0.795750, 3.428210, 0.743810, 0.270480, 1.251800, 0.072430, 0.366040, 1.907360,
-0.877920, 0.404370, 0.200470, -1.197010, -0.182710, -0.094510, 0.402030, -1.099100, -0.101600, 0.480140,
-0.226080, -0.081150, -0.258310, -0.431890, 0.090440, -0.179220, -0.892700, -0.122710, -1.821260, 0.418730,
-1.065350, 0.626770, -0.872250, -0.688680, -0.100490, 0.504870, -1.376130, 1.337090, 0.729820, 0.540090,
0.566170, -1.206870, 0.943690, -0.337260, 0.925600, -1.525050, -1.259640, -1.775250, 1.236790, -1.193030,
-2.627400, 2.320000, -0.275050, -3.920980, -2.880980, 1.583420, 2.189160, 3.190390, -0.948220, 0.500310,
0.722960, 2.127500, -2.087130, 1.818540, 1.970950, -0.012980, 2.247490, 0.253090, -0.728300, 1.455170,
-1.898490, 1.086140, -0.240270, -0.336690, 0.325120, 0.171300, -1.395100, -2.224920, 0.760250, 0.164480,
0.379940, -3.196510, -1.180170, -0.725860, -0.484600, -1.651850, 0.565110, 1.140340, 0.232510, 0.860950,
2.789000, -1.256540, -4.627150, 1.709050, 1.469940, 1.864020, 0.092490, 0.161470, -2.105430, -0.136990,
-0.579980, 0.710760, 0.902110, 0.940620, -3.586780, 1.101340, -0.142130, 0.026120, -1.603590, 0.487610,
-0.330790, -0.774310, 1.268740, 1.378290, 0.477020, -5.339700, 2.020000, 1.058230, -0.255520, -0.491650,
-0.455030, -1.508730, -0.726270, -0.245350, -0.634330, 1.657710, -0.544430, -0.300690, -0.376230, -0.949990,
1.860870, 0.651370, -0.677140, -0.894920, 0.645140, 0.597410, 0.938450, -1.112490, 0.784320, -0.899270,
-0.199460, -0.682100, -2.036220, 0.720670, 2.017750, 0.429760, -1.889130, 0.564640, 0.980620, 1.372240,
-0.230900, -1.026060, 0.241260, -0.976230, -1.784150, 0.960960, -0.513920, 0.214640, -0.282740, 0.307200,
0.824440, -1.582080, 0.093430, -0.338470, 0.719840, -0.264700, 0.356100, -1.362880, -0.909120, 0.230200,
0.657540, -0.739560, 1.560340, 0.650860, 0.327030, 0.434710, 1.369840, 1.349180, 0.784940, 0.815040,
0.824540, -0.619060, 0.434140, -5.742840, 0.622550, -0.821980, -0.491660, -1.106710, -1.307650, 0.350750,
-0.673700, -0.397250, 3.350610, 1.059300, -0.471660, -0.867020, -0.645910, 0.069570, -0.567180, 0.474880,
0.042970, -0.119490, -0.170020, -0.839490, 0.745960, -0.903290, -0.784110, -0.101430, 0.768620, -0.904680,
0.350170, 0.604380, -1.693850, 0.270510, 0.593970, -0.532030, 0.376160, 0.892280, -0.798480, 0.561360,
0.239530, -0.293050, 0.070240, 0.971670, 0.038290, 0.425730, 0.772110, 0.541990, 0.498570,
0.694500, 0.202180, -0.092330, -0.496820, -0.249840, -1.801300, 0.531410, -1.705840, 1.413820, 0.625620,
-0.168160, 0.239710, -1.104710, 1.096080, 0.369790, 0.121990, 0.810920, 1.575040, 0.191960, 1.584340,
-0.527370, -0.369400, -0.042360, 0.435440, -1.294240, -1.527080, -0.203670, -1.742790, 0.070740, 1.949750,
-0.775380, -0.163410, 0.625940, 1.680340, 0.008000, 0.529940, 1.444460, -0.642670, 1.658800, 0.639950,
-0.998050, 1.342100, 1.765140, -1.390400, 1.805060, -0.762820, 0.500200, -0.792040, -1.502780, 0.086990,
-0.025310, 0.504030, 1.191100, 0.207070, 0.091150, -1.760940, 0.453960, -0.550060, 0.440790, 0.817110,
1.244160, 0.032660, -2.081000, -0.435720, 1.423120, 0.075950, 0.048570, 1.142160, -0.391200, -1.065900,
0.007630, -1.597310, -0.925480, 1.415070, -0.203140, -0.391350, -0.992480, 0.136060, -0.130390, 0.436550,
-1.450350, 0.999430, 2.797470, 0.727790, 0.535290, 1.781890, -0.466520, -1.631370, -2.236650, -1.001910,
0.453940, 1.163460, -0.506310, 0.740900, -0.288780, -0.725540, 0.223890, 0.474550, 0.299850, 1.173060,
0.419800, -0.576290, -0.183230, -0.687010, 1.365040, -1.377520, -0.547200, 0.701260, 1.442900, -0.013160,
-1.438950, 0.303560, 0.935910, 0.011750, -0.802970, -1.687130, -2.507570, -0.962640, 1.856450, 0.155080,
-2.528450, 1.931000, -2.610520, -1.718810, -4.410750, -0.021630, -0.124220, 1.874150, -1.651100, 1.541050,
0.969090, 0.334430, -2.975050, 0.662270, 0.855280, -4.993130, -0.220230, 1.843530, 0.431010, -3.064840,
0.539010, -0.974960, -0.480560, 0.335830, 0.499470, -0.266560, -0.002960, -0.348180, 1.126820, -0.000070,
0.625230, -0.306220, -0.299450, 1.048130, -0.277640, -0.107360, 0.380770, 1.346660, -0.823110, 0.633110,
-0.208210, -1.070650, -1.593600, -1.057140, 1.312180, -0.620050, 1.555280, -0.467390, 0.301170, -1.536870,
-1.054240, 0.899250, 0.879790, 0.953370, 0.057300, -1.137060, 0.459050, 0.848870, -0.895450, 0.004720,
-0.331040, 1.179160, -0.934950, -0.185380, 0.061610, -0.861290, -1.478250, 1.491470, 0.060910, -0.942910,
-0.250660, 1.551710, -0.113340, -0.764090, -0.795050, -0.397370, 0.706190, -0.816780, -0.096500, 0.879200,
-0.199390, -2.294790, 1.416410, 0.005980, -0.851050, -0.441700, -1.795440, -0.811490, -0.124330, -1.808040,
0.543000, 0.346500, -1.647080, 0.523940, -2.035070, -0.144550, -0.423350, -0.784480, 1.566380, -1.939130,
0.429500, -0.731760, -0.519200, 0.889240, 0.593320, -0.810310, 0.299260, -0.087620, 0.879510, 0.568790,
0.543600, -1.198220, 0.267740, 1.788670, 1.149940, 1.212620, -0.476490, -0.393120, -0.392470, -0.414280,
0.286800, 1.164050, 0.008280, -0.430160, 0.298490, 0.035610, 0.045240, 0.019750, 1.087510, 1.177010,
0.038810, -0.126520, 0.960540, 0.754070, -0.206970, -0.306960, -0.305880, 0.866190, 0.769910, -0.439240,
1.749070, 0.655570, 3.141100, 1.149810, 0.395490, 1.068620, 0.788820, -1.205670, -0.126140, -0.513000,
0.660540, 0.790650, -0.677890, -0.305790, 0.283320, 0.773020, 0.941610, -0.123970, 0.115510, -0.460950,
-0.930040, 0.019680, -1.606820, 0.651670, 0.070050, 0.923430, 0.077260, -0.893990, -0.386970, 0.569620,
-0.193190, -0.843580, 0.278440, -0.016120, 0.427730, 0.279740, -0.949100, 0.915710, -0.922710,
1.533530, -0.548340, -0.014020, 0.158500, -0.041360, 1.214170, 0.237100, 0.014700, -0.756940, -0.002230,
-0.520300, 0.907150, -1.370630, 0.821640, -0.611090, -0.593290, 0.903340, -0.139550, -0.701960, -0.646210,
-0.000400, -0.817390, 0.439230, -1.051980, -2.540800, -0.339280, 0.973870, -0.205280, -0.506940, -0.186850,
-0.857660, -1.707980, -0.749270, -0.235740, 0.014280, -1.763780, 0.936000, 1.046030, 0.212850, -1.116520,
-0.305870, -1.702100, -0.649270, -1.020910, 1.251840, -0.209600, -0.884950, -0.212870, -0.761830, 0.579000,
-0.711460, -0.175910, 0.568880, 0.734180, -0.769860, -0.556480, 1.038920, 0.118830, 0.170830, 2.149790,
-0.758570, 0.667850, -0.470690, -0.616220, -1.099930, 0.170420, 0.818990, 0.580660, -0.317300, 0.219660,
0.111150, 0.194810, -0.599500, 0.419900, -0.553080, 0.582940, -1.371250, -0.687170, -0.433690, -0.019230,
0.254910, 0.411850, -0.971930, -0.395170, -0.136360, 0.253680, 0.020100, -0.688760, 0.006300, -0.912250,
0.274300, -0.680890, -0.418760, 1.145320, 0.456170, 0.640500, 0.149490, -0.009600, 0.587200, -0.989880,
1.474200, 0.170140, -1.009370, 0.807450, -0.322580, -0.032140, 0.663080, 1.582100, -0.196700, -2.128120,
-0.663300, -0.279550, -1.087250, -4.194460, 0.492470, 3.228930, 1.152610, 2.887020, -1.256070, 0.215240,
1.253990, -5.520760, 0.844700, 6.488750, 2.859020, -1.153920, -0.890390, -1.172240, 0.848400, 3.852690,
-1.234770, -1.412180, 2.332010, -1.065960, -1.875040, 1.134220, -2.212260, -0.238250, -1.769580, 1.164970,
-1.207990, 2.116980, -0.304140, 1.363070, 0.169610, 0.139680, -0.547280, -0.832940, -0.378920, 0.040040,
0.119300, 0.387520, -0.516330, 0.141210, 0.265870, 0.139810, -0.014510, 0.104790, 0.400370, -0.514230,
1.522030, 0.764910, 1.176840, 0.403710, 0.618490, 0.938480, 0.697640, -0.197380, 0.332500, 1.155390,
1.466010, -0.467400, 0.587110, 0.467110, 1.993450, -0.397160, -0.428110, -0.186700, 0.967880, -0.156460,
-0.026280, -0.666850, -1.124510, -2.556640, 2.052560, -0.514370, -0.794350, 0.308340, 2.571420, 0.228060,
0.613510, -0.122000, 0.177500, 1.437530, 0.734250, -0.391550, -0.650250, 0.853890, -0.977180, -0.983690,
-1.392520, 0.870910, -1.432210, -1.824490, -0.316370, -0.445510, 0.472720, -0.310450, 0.234510, 0.643420,
0.107140, -0.756040, 0.717650, 1.354610, 0.130670, -0.813060, -0.017280, -0.398370, 0.287110, 0.576440,
0.220030, -1.010740, -0.691080, 0.246150, 0.129930, -1.154460, -1.670650, -0.706450, 0.933800, 0.028430,
-0.733300, 1.791360, 0.531600, -1.432530, 1.430490, 0.715630, -0.341000, -0.939260, -1.011910, 0.515060,
-0.410880, 0.329760, -0.646680, 1.079730, 0.027230, -0.256360, -0.554130, 0.433450, 0.845210, -2.723830,
0.451030, -1.096090, 0.455850, 0.365620, 0.076250, -0.436850, -1.160410, 0.383970, 1.105980, -0.240260,
1.170310, -0.532220, -3.799820, -0.451890, 0.162660, -0.234430, -0.695450, -1.186740, -0.173480, 0.823630,
0.969940, 0.120600, 0.172380, -0.922120, -0.290460, 0.763240, 0.507230, 0.020880, 0.947480, 0.262770,
0.477910, 0.394100, 1.539650, 0.962170, 0.688770, -0.695240, 0.653970, -0.882340, 0.533840, -0.319300,
-0.703500, 0.215310, -0.819170, 0.826210, -0.238690, -0.031470, 0.858480, 0.995970, -0.075220,
0.503930, 2.583990, 1.296670, 0.051880, 1.411200, -2.772230, -3.317560, -0.579380, 0.660900, 2.038370,
-0.807610, -1.310450, -0.439780, 0.503610, 3.121840, 1.037940, -1.002880, 1.351280, -1.071200, 0.780010,
14.246270, -0.784690, 0.808710, -0.117860, 0.585950, 3.437640, 1.391590, 0.227120, 2.137560, -0.387440,
0.408140, 9.124530, 3.736300, -2.145260, -0.761500, -0.773250, 1.465790, -0.519690, 0.626680, 2.193030,
-0.857280, -0.831160, 0.202320, 1.527470, -1.574020, -0.023020, -0.492480, -0.675310, -2.660630, 0.883750,
-0.971240, -1.219110, 1.274140, -0.323600, 1.751080, -1.289170, 0.314110, 1.326820, -0.148300, 0.840970,
0.635250, -0.662510, -0.283840, -1.231130, 1.275760, -0.130990, 0.920540, -0.034200, 2.414370, 0.166030,
0.280840, -1.895140, -1.187890, 0.850410, 0.031360, 2.380810, 1.765350, 0.380780, -0.792120, 0.731030,
-0.354830, 0.565860, -1.455050, 1.430970, -0.029520, -0.836430, -3.201180, 0.175330, 0.736570, 0.597410,
1.223470, -0.187620, 0.874060, 0.618490, -1.970300, 0.578910, -0.536180, 1.664290, -1.805460, 1.305990,
1.557530, 0.177650, -1.147260, -1.213920, -6.278460, 0.239150, 2.425110, -0.814930, -0.808450, 0.915960,
-0.666690, 0.930710, -0.651030, -2.262900, 0.242510, -1.867010, 2.124140, 0.255870, 0.526910, -0.139590,
-1.000220, 1.319070, 0.254970, 0.150350, 1.515160, 1.427890, -0.120700, 0.061720, 3.383660, -1.590520,
-2.937830, 2.103500, -0.389370, 0.833690, -0.892990, 0.270170, -0.453190, 1.916230, -1.177300, 3.983730,
-4.866490, -0.620810, 0.395870, 0.812270, -0.722640, -0.166120, -1.217450, 0.411410, 0.706350, -0.440260,
0.834190, 1.001980, 0.028960, 0.856530, 0.518770, -1.230770, 0.658260, 1.085010, 1.092330, 0.530920,
-2.336570, -0.160800, 0.471940, -0.724740, 1.222240, -0.612290, -1.956210, 0.367970, -0.285580, -0.212900,
0.945420, -0.351000, -0.366950, -0.064330, 0.264170, -1.105860, 2.620320, 0.461710, -0.438120, -0.623480,
-0.482300, 2.302960, -1.285150, 0.189120, -0.364630, 2.082660, 0.372510, 0.496170, 0.672450, 0.693100,
-1.192210, 5.211920, -1.378510, 0.437900, -0.535040, -0.797820, -0.776670, 0.458450, 0.048750, -0.169750,
0.516210, -0.445630, 0.973180, 0.307340, 1.606950, -0.275820, 0.339270, 0.838650, 1.175600, -0.316030,
0.276330, 0.309620, 0.859390, -0.440670, -1.368890, 0.163850, -2.510440, -1.151890, 0.585630, -0.376590,
-0.479170, -1.102270, -1.227570, -0.114350, 0.520450, 1.017280, 1.066640, 0.685130, 0.742500, -0.619510,
0.007590, 0.711090, -0.850190, -0.573460, 1.618900, -1.136370, -0.048660, 0.854790, 0.400350, -1.521390,
-0.926780, -1.820260, 2.181620, 0.900270, 0.684810, -1.176600, -3.580470, -0.553240, -2.738010, -2.370570,
0.485900, -1.045750, 2.574300, -3.342830, -0.840500, 0.179180, 1.747390, 1.149790, 0.854870, 1.412930,
-0.867140, -1.182400, -0.271860, 1.816030, -0.009150, -0.886040, 0.424610, 2.081280, -0.034720, 0.613990,
0.871910, -0.056000, 0.778300, -0.910140, -0.647510, -3.731930, 0.381210, -0.248170, -0.607660, -1.576860,
-1.009580, 0.616200, -0.015310, -0.825930, -0.849230, -0.532280, 0.356000, -0.009200, -0.408620, 0.538150,
0.493150, -0.683480, -1.202530, -0.564850, -0.370610, 1.024670, 0.642780, 0.406080, 0.516240,
0.109600, -0.345970, -1.072130, 1.001780, 0.433490, 0.210320, -1.118320, 0.669980, -0.251510, -1.000340,
-0.013600, -0.764760, -1.843420, 1.014730, 0.582850, 0.670460, -0.816910, -0.402320, -0.238170, -0.727140,
-0.109500, -0.120880, 0.592190, 0.505610, -0.368890, -0.093220, 1.123520, -0.106440, 1.180780, -1.131930,
0.984560, 0.089470, 0.371810, 0.222630, -0.197910, -0.632480, 0.973100, 0.296430, -0.004280, -0.793540,
-1.651270, 1.118130, -0.078100, -0.443580, -1.572950, 0.576000, -0.570590, 0.174370, -0.672570, -0.945210,
0.021230, -0.141300, -0.035030, 1.063720, 0.704880, -4.108430, 0.404300, -0.382960, -0.415440, 2.131640,
0.293540, 1.776020, 0.346480, -2.440700, -0.475850, 0.020940, -0.500560, 0.376410, 0.876070, -1.333390,
0.158640, 1.242290, -1.731000, -0.404820, 1.428330, 0.427170, 0.647410, -1.424170, 0.002320, 0.157160,
-0.823570, 1.340160, 0.178120, 0.170480, -0.380100, 0.958440, -0.990200, -0.223880, -0.130990, 2.549980,
0.564200, -0.389060, 1.117240, -1.336360, 0.541850, 0.690660, -0.061790, -0.069550, 0.014710, 0.363570,
-0.654080, -0.836750, -1.236600, 0.507000, -0.614340, 0.696690, -0.661200, 0.441100, 0.222050, -0.099960,
-1.211030, -1.736150, 0.327530, -1.085260, 0.576860, 0.204990, -0.312860, 0.525650, -1.268190, 0.761480,
0.238020, 0.772400, 0.352700, -1.250530, -2.488910, 0.236170, 0.982250, 1.760150, -0.733010, 0.692600,
1.624480, -1.073080, -4.641100, -0.381100, -0.530450, -11.369340, -0.574080, -0.496420, -0.743380, 0.644100,
0.555220, 1.421320, -0.061400, -0.522560, 1.631950, 0.603960, -0.793920, -1.749340, 0.186810, 1.152680,
-0.839850, 0.616480, -0.781570, 0.276890, -0.189880, -0.012070, 0.356020, -0.523560, 0.199140, 0.326050,
-0.093740, 1.002880, 0.586060, 0.983100, 0.716500, 0.900410, 1.101610, -0.324210, 1.039530, 1.066790,
0.003230, 0.513820, -0.094240, 0.064970, 1.813070, -0.239350, -0.428270, -0.619040, -0.300320, 0.356380,
0.906910, 1.306180, -2.208130, -0.028060, 1.098730, -1.280030, 0.810470, 0.013340, 0.273520, 0.590520,
0.526490, 1.112990, -0.061040, -0.156500, -0.386560, -0.909320, 1.191270, -0.488330, 1.146850, 2.228780,
0.477970, -1.132910, -0.542520, -1.686290, -1.163020, 0.046270, -0.410350, 2.794500, 0.000410, -0.367960,
-0.906550, -1.132140, -0.947130, -0.824580, 0.524370, -0.985530, -1.216200, -0.002960, -0.062350, 0.956340,
0.814630, 1.301050, 0.245670, -1.711920, -0.693760, 1.371930, -1.194370, -0.299570, 0.576690, -0.976710,
1.429750, 0.669410, -0.688610, 0.403250, 0.333710, -0.555130, -0.090270, 0.581580, -0.998450, 0.133460,
0.957220, 1.398600, -0.244580, 0.627530, -0.152090, 0.250480, -0.258190, -1.083130, 1.239170, -0.485870,
1.921240, -0.893540, -1.495460, -0.115510, -2.723520, 0.364940, 0.021170, -0.022900, 0.940630, -0.027170,
0.846790, -0.435750, 0.878840, -0.097260, -0.695800, 0.947260, -1.368790, -0.284770, 0.484910, 0.423890,
0.343480, 0.404570, 2.143590, -0.411560, 0.027820, 0.287230, 0.355390, -0.451190, -0.016280, 0.568840,
-0.436600, 0.908860, 0.708740, 0.212630, 0.094730, -0.156060, 0.343010, -0.732370, 0.122850, -0.392610,
0.856920, 0.645850, -0.739560, 0.378020, 0.613560, 0.350660, -0.127350, -0.489090, 0.043760,
-0.261950, -0.783980, -1.187180, -0.307300, -0.770900, 0.066680, -1.258530, -1.019870, 0.423350, -0.708380,
-0.123160, -0.193990, -0.768990, -1.109480, -0.137330, -0.469230, 1.479720, 1.422930, -0.302590, 0.654600,
-1.675080, 0.345350, -1.290680, -0.523690, 0.678280, -0.038670, 1.764540, 0.325220, 0.734490, -0.419220,
0.853670, 0.458430, 1.784540, -0.575800, -1.243330, 0.099930, 0.841660, 0.351180, 0.074640, 0.234140,
1.028250, 1.065970, 0.049300, 0.020110, 0.305500, -0.403430, 0.428450, -0.502330, -0.040580, 0.762630,
-1.643800, -0.044810, 1.221820, -1.002430, 0.669440, -0.037930, -0.104310, -0.305710, -0.956320, -0.057610,
0.237310, 0.251140, -2.290420, 0.130400, 1.588330, 0.037770, 0.444820, 0.149860, -1.014410, 1.105190,
-0.000070, -0.091410, -1.184170, -1.345970, 0.684760, -0.590130, 0.276530, -1.006530, -1.153630, -0.945940,
0.059900, -0.857800, 1.153190, 1.505370, 0.388880, -0.225450, -0.512670, 3.024010, 1.074300, -3.252110,
-0.503450, -0.859480, 0.836780, 0.689150, 0.658770, -1.364210, -0.145120, 1.348210, 1.424830, 0.951010,
1.237230, 0.396110, 0.582580, -0.154930, 0.625520, 0.304320, -1.073020, 0.356120, 0.732550, -0.004040,
0.488280, 0.437130, -0.841300, -0.199680, 0.072120, 0.836240, -0.734160, 1.817340, -4.837150, 4.448770,
1.031220, -0.322010, 1.409380, 1.120780, 1.244180, -0.450980, -1.688290, -1.405300, -0.955100, 1.376150,
0.293550, 0.146900, 0.401250, 0.343040, -1.342860, 3.177810, -1.660040, -1.024800, 1.079450, 2.061980,
-0.291200, 0.082620, -0.240220, 0.464330, -1.298320, -0.805530, 0.800040, -0.402970, -0.561000, -0.285660,
-0.288390, 0.226070, -0.682670, -0.009010, 0.016050, 0.229810, -0.597010, -0.580140, -1.454220, -0.058700,
-0.974520, 0.697130, -0.172160, -0.763990, -0.466090, 0.659840, -0.495880, 0.943720, 1.525840, 0.212740,
0.760850, 0.000040, 0.240540, 0.854940, 4.115550, 1.536780, 0.008050, 0.623230, -0.124950, 0.388660,
-0.941930, -0.985870, 0.262020, -0.350170, 0.393900, 1.465260, -0.573660, -0.321570, -1.217650, 1.238770,
-1.147770, -1.020260, 0.665530, -0.409660, -1.408470, 1.023890, -1.429270, 1.628220, -1.181860, -1.095170,
-0.957410, 1.888400, 0.152910, 1.426570, 0.767760, 0.763590, -0.292890, -0.172870, 0.129160, 0.776280,
-1.022030, 1.699120, -0.197090, -0.306000, 0.879570, -0.966240, 2.680400, 0.738320, 0.324360, -0.269460,
-0.831270, -0.882220, 0.138110, 0.106330, 0.609490, -2.115290, -0.539290, 0.703550, -0.046940, -0.936790,
-1.641910, 0.531780, -0.241290, -1.394380, 0.900100, 0.030590, -0.200810, 0.543180, -0.989990, 1.102600,
0.519640, 0.990650, -0.309140, -1.797550, -1.332740, -0.622460, 0.158860, -0.335940, -1.362210, 0.358240,
-1.439570, 0.788980, -0.421930, 31.676920, -0.034520, 0.089350, 1.852400, -0.175910, 0.558100, -0.017200,
1.941000, -1.112630, -0.714210, -1.117410, 1.677190, 1.540080, 1.077510, -0.236120, 0.154540, 0.044170,
2.496830, 1.420360, 1.602650, 1.895070, 0.754300, 0.949290, 0.273190, 0.527320, 0.287580, 0.652390,
1.174600, 1.753670, 0.399760, 0.920570, -2.167350, 0.568140, 1.206510, 1.520320, 1.606080, 0.747450,
1.620830, -1.206610, 1.324870, 0.271320, 2.373200, 1.852470, 2.052180, 0.145380, 0.980760,
-1.267390, -0.101290, -1.430390, -0.784930, -0.371670, 0.851300, 2.314110, 0.808690, 0.912160, 0.244960,
0.583070, 1.892050, -0.139300, -0.567860, -0.062780, 0.194770, 1.321880, -0.141220, 2.548280, 2.271380,
-0.670390, -1.114240, 0.756050, 0.232430, 2.034250, 1.434390, -0.885840, -0.443380, 0.753480, 0.967970,
0.168950, 1.306370, 0.475230, 0.298440, -0.144160, 6.040210, 1.191780, 0.396860, -0.014430, 0.549260,
1.445160, 0.663970, 0.447450, 0.285310, -0.156270, -1.073250, 1.001450, 0.774030, 0.053410, 0.436860,
-1.412440, 2.394850, 0.115400, -0.901180, 0.349790, 1.082690, -1.169370, -0.857650, 0.243590, 1.520690,
1.240870, -2.688210, 0.330830, -1.193300, 0.343860, 0.235940, -1.044250, -1.672210, 0.922220, 0.261560,
2.367190, 0.960530, 0.642460, 0.820640, 1.236180, 0.733710, 1.763060, -0.855560, 0.192250, -0.525190,
0.828820, 0.108210, 1.713240, -0.168240, -0.759340, -0.130470, -0.194880, -0.659240, -1.277920, 0.398850,
0.040360, -2.419830, -1.226610, 0.432260, 0.873250, 2.497390, -0.547510, 0.484740, 1.243170, 0.146020,
0.692040, 0.248880, -1.204170, 1.125560, 1.426690, -3.118530, -0.617250, -0.632940, -0.019820, -0.607310,
-0.221720, 0.312330, -1.172100, 0.465730, 11.237500, 2.077020, -0.663860, 1.285590, -1.553520, 1.569260,
0.236310, -0.852690, -0.599340, 0.080420, -0.108270, 0.085500, 0.109540, 0.416410, -1.332420, 1.974790,
0.690880, -1.882430, 0.564210, -1.434750, -0.198830, -1.233350, -0.495140, 0.027510, 1.290200, 1.818020,
0.466000, -1.366420, 0.973020, 1.278620, -2.479040, -0.399110, -0.525140, -0.038900, -0.709990, -0.685800,
-0.363120, -0.053910, 0.526260, 0.454330, 0.366670, -0.200340, 0.829980, 0.099360, -0.685350, 0.420480,
1.346680, -0.191390, -0.280190, -0.932550, -1.313080, 0.030800, 0.252610, 1.187770, -0.581420, 0.477880,
0.943030, 0.907980, 2.014500, -0.396320, 0.574980, -0.029770, 1.138450, 0.448400, 0.577200, 0.856420,
0.242230, 0.231950, 0.073890, -0.222530, -0.658170, 2.036510, 1.163750, 0.758590, -1.057790, -0.606860,
0.687350, 0.452200, 0.117990, 0.687310, -0.387740, 0.586400, 0.044340, 3.119700, 0.810180, 0.486120,
0.421210, -0.535200, 1.108690, -0.314420, 0.427720, -0.561690, 0.497840, 1.588250, 2.968920, 2.462800,
-0.334850, -0.835910, 1.870300, -0.803160, 1.048060, -0.448380, 1.707010, 0.109230, -1.069370, -0.822770,
2.136690, -0.475080, -2.296870, 0.543680, 2.564990, -0.547310, 1.018930, 0.915260, -1.868000, 0.403820,
0.774740, 0.887140, 0.143300, -0.173380, -0.274330, 0.511890, 0.337860, -0.597330, -0.330520, 0.374270,
-0.416370, 1.025590, 1.491830, -1.571110, -1.049490, 0.754580, 0.511530, -0.404550, 1.337600, 0.616330,
-1.234100, 0.406430, -1.493450, -1.538140, -0.354590, 1.592660, -0.374510, 0.671140, -0.229960, 1.607010,
0.878190, 1.668080, -2.760220, -0.128770, 1.279450, 2.703670, 0.841290, -0.773950, 0.146090, 0.750260,
-0.466860, 0.157820, 1.430770, -0.359820, 0.539680, 1.298070, -0.869150, 1.083150, -0.704840, 1.535290,
0.861560, 0.856010, 0.593190, -1.022110, -0.323400, 0.176540, 0.530580, 0.463810, 1.122030, 0.149970,
-0.739920, 0.308510, -0.515300, -0.736920, 0.797680, 0.484750, 1.030020, 0.330550, 1.064220,
0.906340, -0.839260, 1.026100, 0.297700, 0.707310, -0.914360, -0.796650, -0.840400, 0.287740, 1.044120,
-0.499260, -0.774150, -0.374520, -0.896250, 1.000490, 0.001260, 0.399100, 1.307800, 2.202700, 0.099340,
0.471970, -0.186580, -0.799230, -1.064970, -0.168620, -0.210690, 0.234170, -0.132500, -0.371170, -0.445530,
0.595310, 0.250140, -0.038470, 0.526130, -0.914840, -0.635480, -0.217980, -0.380230, 2.496720, 1.433100,
1.579550, 0.615880, 0.478610, -0.866050, 1.441800, 0.073360, -0.640770, 0.347420, 2.698760, -0.290250,
-0.127730, -0.021360, -0.558540, 0.924730, 1.570750, -0.096400, -0.255840, 0.839660, 0.193430, -2.420840,
-1.864430, -0.021090, 1.183830, 0.469280, 0.615180, -0.018770, 0.475540, -0.075850, -1.356370, 0.170650,
0.076120, -0.346970, 2.587530, 2.096790, -0.611890, -0.182330, 1.332290, 0.993120, 0.796350, 1.978950,
-0.244690, 0.150160, -1.857410, -1.349170, -0.795560, -2.069900, -1.749510, 0.558100, -0.873290, -0.828540,
-0.040330, -0.469000, 0.279030, -0.291220, 1.283670, 1.601200, 0.534460, -1.161290, 0.095780, 0.322490,
-0.621780, -0.645100, -0.755030, -0.119740, -3.920010, 1.841680, -0.335730, -1.516860, 0.157770, 0.685300,
-1.105760, 0.552300, -0.306940, -1.325330, 1.279070, 0.113730, 0.810690, -2.344470, -0.769580, 3.093760,
-0.104510, -3.951970, 1.223680, 2.655090, 5.076650, -0.239250, 0.680320, -2.094140, 1.212900, 0.423920,
0.028580, -0.234240, 10.135780, -0.503390, -0.379910, 13.262050, 0.911850, 0.360430, 0.649370, 0.542730,
0.105940, 0.617750, -1.272510, -0.968260, -0.017560, 0.114230, 0.356180, -0.163350, -0.918940, 0.350080,
-0.763870, -0.545400, 0.261000, -0.338520, -0.453060, 0.679630, -0.210690, 0.291610, 0.647800, 0.988620,
-0.083500, -1.042540, -0.661600, -0.600440, -0.855580, 1.286080, 2.905510, 0.251880, -0.665680, 0.782840,
-0.282580, -0.875360, -0.204510, 0.883940, -0.941950, -0.556660, -0.649530, -1.627380, 2.634990, -0.595960,
-0.386710, -0.671550, 2.336850, 0.455890, -0.450930, -0.158940, 2.592020, -2.767100, 0.052460, 0.854170,
0.155680, -0.607320, 1.326460, 2.661700, 0.945290, 1.341060, -1.025080, 0.788950, -1.176510, 0.951120,
-0.709760, 3.147590, 0.704890, -0.175810, 0.240180, 0.071670, 0.339190, 1.159550, -1.771800, 1.306750,
-1.533290, -1.482630, 0.702250, 0.192680, 0.126950, 0.215790, 0.983300, -0.863100, 0.631980, -0.550910,
-0.912370, -0.345980, 0.253810, 1.294740, 1.376100, -0.526180, -0.495610, -1.128000, 1.318230, -1.106670,
-1.129060, 0.337670, -0.458420, -0.818990, -0.163610, 0.903220, 0.104950, 0.305320, -1.193960, 0.581230,
-0.078810, -0.429130, -0.378770, -1.635330, 0.496890, 1.783680, -0.129300, -0.089210, -0.444700, 0.212100,
-5.082900, 0.203410, 1.274890, 3.962160, -0.608800, -0.274300, 0.286450, -0.685900, -0.006250, 0.131120,
0.335020, -0.643040, -0.464830, -1.123070, 1.248400, -1.432420, -0.812210, 0.105070, 0.137880, -0.678740,
1.197970, -0.820530, -1.336520, 0.892860, 0.818470, -1.590650, 0.955400, 0.168380, 0.494370, 0.385980,
0.284710, 0.327840, 2.037250, -0.483410, 0.408320, 0.933580, 0.563370, 0.004230, -0.694870, 0.870200,
-0.675250, -0.520950, -0.349560, 0.909460, 0.362190, 0.383280, -0.797330, 0.248830, 0.071060,
-0.633870, -0.386000, -0.072810, 0.776060, 0.802490, -0.101790, -0.787480, 0.369860, -0.747580, 0.094860,
1.028160, -0.522450, 1.456840, -0.143050, 1.369320, -0.400100, -0.697280, -0.325920, 2.437330, -1.281880,
-1.512060, 1.376520, -2.450620, -0.865570, -0.524720, -0.810450, 0.152930, 0.042270, -0.199930, 1.423720,
1.088070, 0.557270, -0.470000, -0.650970, -3.009080, -0.456900, -0.997780, 1.005590, 1.314200, 0.098920,
-1.323090, -1.377920, 1.023560, -2.296510, -0.730070, -2.614760, 0.069340, 1.060790, -1.056250, -0.265880,
0.530370, -0.442960, -1.692290, -0.255180, -0.102500, -0.329450, -0.540790, 0.733960, 0.042210, -0.429770,
-0.152210, 1.257130, 1.507040, -1.056230, 1.179270, 0.360250, 0.086510, 0.607800, -0.192620, 1.294050,
-1.292570, -0.729810, 0.267370, 2.406410, -1.263830, 0.755850, -1.085790, 0.964910, 1.003060, 1.030180,
1.206520, 2.055380, 1.421980, 1.754490, 0.238230, 0.193630, 1.009910, -2.120730, 0.487770, -1.854610,
-0.557110, -0.882590, -1.290470, -0.214300, -1.908830, 0.614820, 0.275490, 0.300080, -0.891700, 0.862780,
-1.392510, -3.291490, 0.066800, -0.078460, -0.593170, 0.552450, 0.188260, -0.071750, -0.337670, -0.162070,
0.455150, -0.868000, -1.891840, 1.017090, -0.329850, 0.490940, 0.671050, -0.411050, -0.381820, 0.447510,
0.166340, -0.798970, -0.777350, 0.200980, 0.902310, 1.914760, -0.703240, 0.253630, 0.845030, -0.536990,
-2.036230, -0.741210, 1.396620, 0.143070, -0.169400, -0.318780, 0.465900, -1.409030, 0.994540, 0.971800,
-0.258090, -1.876260, -0.215990, -0.672320, -0.051630, -0.503970, -0.056620, -1.343060, 3.172630, -0.214540,
1.042600, 0.793400, 0.372130, 0.640200, 1.188700, 0.794830, -0.902670, 1.400560, -2.614650, 0.140980,
-1.012590, 2.301860, 0.515050, -0.363390, 0.300680, 1.721420, 0.886580, -0.313020, 1.004900, 0.196870,
1.027460, -0.866810, -1.701590, 0.246760, 0.931210, 0.813130, -0.245800, 0.475810, 1.056250, -0.615470,
-2.237590, -0.180270, -0.637830, -2.202350, -0.446330, 0.558940, -1.392780, 0.307900, -0.773920, -0.064960,
-0.352240, 1.831040, -1.585620, -0.337580, 1.927120, 2.138920, 0.760520, -0.311360, 0.394390, 1.019630,
0.932530, 0.202970, -0.263290, -0.244810, -2.778440, 0.613200, -1.773010, 0.156610, 0.298030, 1.241580,
-0.470070, -2.582040, -0.552340, 0.961940, -0.644410, 1.009070, 1.131840, -1.138280, -1.058080, -0.303730,
-2.606650, 0.746120, 0.907570, -0.365170, 0.750680, -1.298130, -0.740790, -2.354430, -0.701640, -1.102580,
2.154920, 1.739560, -0.366080, 0.355860, -0.711560, 1.067640, 0.713220, 1.200000, 1.477900, 0.024370,
1.293820, -1.057620, -4.051770, 2.068510, 1.698270, -0.442750, 0.036080, 2.030840, -0.681410, -0.150920,
-4.927070, -0.194530, 0.412230, -0.310990, -0.661280, -0.375600, 0.699770, -1.100380, -0.612120, 0.337850,
0.492870, 0.214730, -0.991250, -2.637060, 2.827770, -0.178770, 0.472970, -0.317730, 0.260720, -0.294520,
-0.906850, -1.620100, 0.025250, -0.040760, -0.297920, -0.500790, 0.021200, -1.279390, -1.156170, 0.016610,
-0.499260, 0.454550, -2.710220, 0.133350, -0.016500, -1.199030, -0.179180, -0.517710, -0.586110, 0.052490,
0.379450, -1.398000, -1.570100, -1.162650, 0.461290, 0.442070, 0.191480, 2.394220, -0.661380,
1.179340, 0.523210, 0.864670, 1.142670, 0.274680, 0.341470, -0.674090, -0.661700, -0.565490, 0.067240,
0.372560, 1.245250, -0.815820, 0.645860, -1.091860, -0.519860, 0.172350, -1.155150, -0.930890, 0.363770,
1.382890, -0.273910, -0.314900, -0.278510, -0.344490, -1.342470, 0.904600, -0.459200, -1.372050, 0.852280,
-1.699900, -0.578410, -2.069790, -0.899930, -1.074190, 0.089060, -0.521140, -0.793820, 1.289900, 0.152660,
-0.886260, 0.540800, -0.786540, -1.820160, -0.047180, 0.236780, -0.237820, -0.350170, -0.817270, -0.815080,
-0.312550, 0.300290, -0.721780, 1.018400, 0.358770, -1.235910, 1.068920, -0.597840, 1.105840, -0.313710,
0.028380, -0.649070, -0.184960, -0.925380, 0.364510, -0.375070, -0.740770, -0.870080, 1.017070, 0.590900,
0.206610, 0.209450, -0.328420, 0.556210, -0.116670, 0.283620, -0.442680, 0.565900, -0.131600, 0.498010,
-0.607210, -0.045080, -0.591930, 1.685590, -1.229890, -0.464620, -0.410930, -1.517660, -0.889700, -0.338800,
-0.773890, 3.126840, 0.414580, -0.324320, -1.938280, -1.233190, -1.643520, 0.325180, 1.855810, 0.420600,
-0.257520, -2.111230, 0.647110, -0.205980, -0.822920, -0.322320, 0.158640, 1.444290, -1.204160, 0.616120,
-0.064790, -0.212380, -0.795470, -0.479650, 0.823430, 1.190740, 2.301160, -1.329250, -0.947730, 0.535090,
0.301540, -0.707990, -1.894390, -0.088810, -0.805740, 0.747120, -0.749060, 0.320520, 2.607220, 0.017890,
-0.766280, 0.023670, 2.452560, -1.222390, -0.944360, 8.021720, 0.296090, -1.377310, -0.543280, 0.885970,
0.198340, 0.659050, -0.744580, -0.193010, -0.578090, -0.160170, 0.039720, -1.842250, 0.616140, 0.293480,
-0.055260, -0.596110, -1.003440, 0.713350, 0.208260, 0.530560, 0.031650, -1.386990, -0.197630, 2.066090,
-0.288170, -0.557360, 0.929990, -0.751710, -0.505450, 1.045720, -0.536300, 0.487260, 1.851390, 0.093040,
-0.643520, -0.262070, 0.511940, -0.671680, 0.432220, -0.096590, -1.161300, 0.041200, 0.836050, -0.209400,
-0.799420, -1.037490, 0.049600, -2.195880, -0.378040, 1.446800, -1.533470, 1.828680, 0.649710, 0.331030,
-0.178800, -0.374420, -0.392720, 0.523450, 1.635140, 0.308050, 0.103650, -0.776210, 0.778350, 0.237800,
-0.092390, 0.463340, -0.436750, -0.797170, -0.411910, -0.545850, -0.504620, -0.843170, -0.663230, 0.336290,
0.972580, 1.865470, -0.696410, -1.997720, -0.018550, -0.145590, 1.389380, 1.116450, 1.413220, 0.839840,
-0.465460, 0.021210, -0.211160, 0.731620, 0.018620, 0.799370, 0.875600, -0.154000, -0.736310, -0.296250,
-0.190720, 0.464590, -0.185540, -0.324690, 0.376500, -1.426260, 1.379690, 0.235240, 1.555690, 0.589530,
-0.085690, -0.779030, 0.189180, -0.794230, 0.427410, 0.129940, 0.577180, 0.232630, 0.322440, 0.202690,
-2.907570, -0.595500, -0.624740, -0.339930, 0.037520, 0.104280, 0.199410, -1.600530, -0.172680, 0.977300,
0.131870, -1.228480, -0.947720, -6.011900, 0.056450, -0.397450, -0.565080, -0.100320, -0.167050, -0.786730,
-0.259670, 0.075720, -3.252630, -0.372510, -0.801920, -3.010290, -1.691420, -1.187340, -1.170110, -0.750900,
1.827740, -0.894030, -1.704300, -0.373550, -0.874990, -0.748310, 0.028480, -0.152620, -1.731010, -1.747140,
-0.871000, -0.959350, -0.716540, -0.769570, -0.561500, -0.463270, -1.039840, 0.115250, -1.454830,
-0.379750, 1.114980, -0.445320, 0.139220, -1.198170, -0.661160, -0.655470, -1.094850, 0.548870, 1.275200,
-1.038230, -0.230300, 1.442070, 0.491770, -3.208340, -0.999310, 1.102870, 1.520270, -0.292550, 0.497340,
6.122980, 0.090350, 1.226670, -0.806800, -0.408490, -0.892580, -0.507340, -0.424930, -0.803500, 0.000700,
-1.740860, -2.012100, -0.623400, 0.564820, -0.748990, -0.683410, 1.052140, 0.345750, 1.162060, 1.190100,
0.532220, -0.812320, -0.754400, -0.125700, 0.468050, 2.993650, -0.119920, -1.019340, -1.889910, 0.410490,
0.541120, -0.211240, -1.712600, 1.061990, -0.445070, -0.880760, 0.870700, -0.280400, -0.034420, -1.229720,
0.020530, -0.116460, -1.300920, -2.683530, -0.253390, -0.382210, 0.120150, 0.011550, 0.985210, -0.710640,
0.300440, -0.771930, 1.057630, -0.947680, -0.923480, -0.249310, -1.520120, 1.030010, -0.478470, 0.932210,
0.528170, -0.863830, 2.323220, -0.681610, 1.264890, -0.429600, -0.901710, 0.302630, 1.498540, -0.191350,
0.553260, 0.452840, -0.615520, -1.148290, 1.903970, 0.061080, 0.180670, -0.562940, 0.505890, 0.474730,
-0.459780, 0.452440, 0.284350, 1.185900, 1.030460, 0.735330, -0.388490, -0.900410, -2.079780, 0.293170,
-0.637310, 0.813440, 1.401000, -0.086450, 1.063450, -3.267730, -1.117270, -2.540360, 4.037980, -1.418640,
-1.105380, 1.551610, 0.804990, -2.614300, -2.983000, 0.914800, 1.598980, 1.169480, 0.456400, 1.158180,
2.352160, 0.215740, -3.578720, -0.292110, 1.838210, -5.926770, -0.525630, 1.711970, -0.135880, -0.305750,
-0.012480, 1.245760, -1.017100, -0.053940, 0.025900, -0.822770, -1.069190, -0.722770, -0.539080, -0.055200,
0.442750, 1.516360, -2.209890, -0.820080, 0.864370, -1.361550, 0.462680, 0.090030, -0.305510, -0.130560,
-1.244230, -1.295660, -0.910880, 1.044990, -0.741400, -0.448040, -0.182330, -0.395330, -1.129190, -0.357510,
-1.506260, 2.996390, -0.166540, -0.361950, -1.232780, -1.901530, -1.122500, -0.066880, -2.203480, -1.317920,
-0.816840, 1.013050, -0.890070, 1.777250, 0.131010, -0.452330, -0.072390, 1.226860, 1.612210, 1.087480,
0.819180, -0.976010, 0.075400, 1.268840, 0.013550, -0.371780, 0.608670, 1.060210, 0.313710, -1.144280,
-1.201930, -1.107480, 0.296640, -0.304060, -0.488610, -0.426610, 3.261050, 0.016600, -2.179480, 0.308870,
-1.410330, 0.315400, 1.101190, -0.885530, 1.333690, 1.325610, -1.564430, -0.484640, -0.392550, -0.109050,
0.714790, -0.007130, 0.713460, -0.866360, -3.092790, 0.085890, -0.417530, 0.106440, -0.749970, 0.932180,
-0.063570, 2.211550, 0.046510, -0.881180, -1.157800, -0.847150, -0.122150, 0.278140, -0.722340, -0.789350,
0.099660, -1.265400, 0.896750, -0.466570, -0.476950, -1.874740, -0.829430, -0.593570, 0.139940, -1.236880,
-0.098730, -1.590280, 0.897080, -6.105630, 0.299470, -0.450110, -0.771530, -0.151260, -0.728990, 1.590010,
-1.096230, -1.022090, -0.228090, 0.454950, -0.510230, -1.204330, 0.682960, 1.329560, -0.797790, 0.736430,
-0.000500, 0.455410, 0.041470, -0.665160, -0.135410, 0.011610, -0.367700, -0.219660, -0.609950, -0.538480,
-1.086230, 0.224000, -0.574320, 0.270150, 0.436200, -0.599070, 0.515420, 0.409160, 0.563090, -0.584490,
0.804820, -0.600270, -0.522430, 0.289010, 0.294690, -0.233470, -1.583980, -0.898250, 0.430790,
0.816780, -0.147560, -0.362540, 2.227110, -0.941720, 0.281320, 0.344990, 0.177370, 0.585400, -0.968050,
0.044260, -0.416380, -0.718260, 0.722590, 0.861130, -0.350770, 0.532160, 0.522550, -0.842950, 0.076320,
0.422440, 0.278480, 0.866930, 0.532100, 0.529000, -0.875260, -0.261140, -0.772630, 0.137290, 0.520470,
-0.750610, -0.566800, -0.823020, -0.693030, -0.748250, 0.310220, -0.510950, 0.237190, 0.739960, -0.135340,
0.387040, 0.608870, 0.620150, 0.210160, 0.796370, 0.598450, 0.970450, -0.049280, -0.362740, -0.836720,
-0.135820, 0.802140, -0.479940, -0.384750, 0.590590, 0.303770, -0.651430, 0.310260, 0.841570, -0.312110,

0.027250, 0.854380, -0.235340, 1.162480, 0.502970, 0.414370, 2.046220, -0.687850, 0.510780, -0.040350,
-0.328520, 0.471160, 0.560900, 0.125390, 0.062090, -0.082700, -0.906120, -0.155350, 0.542780, 0.816200,
0.436720, -0.838780, 0.611650, -0.721720, -1.591500, -0.818440, -0.200470, -0.125590, 0.244800, -0.727400,
-0.930040, -0.663070, -0.791520, -1.007250, -0.988930, -1.969820, -0.468890, 0.185880, -0.815280, 0.981570,
-0.300080, -0.457780, -0.338070, -0.107290, 0.010900, -0.775720, 2.810000, -0.592970, -0.981480, -0.663240,
0.628670, -0.537100, -0.542320, 0.284040, -0.791320, -0.502360, 0.651950, 0.628030, -0.824900, 0.793730,

-0.877780, 0.254960, -0.107570, -1.101210, -0.972710, 0.865930, 0.893280, 0.134150, 0.524670, 0.283400,
0.147080, 0.208590, -0.673290, -1.016560, -0.281830, -0.301740, 0.032040, -0.783080, -1.195360, 0.635460,
0.490670, 0.450980, -1.210180, -0.377790, 0.020900, 0.510330, -0.544750, -0.767870, 0.147060, 0.107950,
-0.980390, -0.061250, -0.032730, 0.124200, 0.184150, -0.805040, -0.054120, 0.876580, -0.726420, 0.384920,
-0.953200, 0.929740, -0.948510, 0.101550, -0.421590, -0.169630, -0.283260, 0.484550, 0.845050, -0.533100,
0.289300, 0.798560, 0.309380, -0.283710, -0.501060, -0.303090, 0.709160, -0.084850, 0.163110, -0.856210,

-0.157060, -0.411390, -0.942780, 2.572660, 0.654840, 0.750260, -0.771020, 0.055980, 0.251740, -0.402670,
0.031330, 0.930590, -0.635010, -0.656940, -0.767470, 0.008740, 2.353020, -0.309530, 0.709220, 0.790590,
-0.261900, -0.387200, 0.932570, 0.032330, 0.913660, 0.281540, -0.571640, 0.833010, -0.578260, 0.099780,
-0.575470, -0.538800, 0.977310, -0.095260, -0.742210, 1.287780, 0.782280, 0.850490, 0.770160, 1.508060,
-0.650570, 0.854590, 0.655860, 0.022480, -0.655590, 0.919150, -0.858710, 0.224890, -0.224290, -0.558040,
0.783580, 0.325920, 0.886380, -0.441120, -1.314940, 0.728430, 0.248250, -0.570860, 0.060950, 0.706910,

0.231670, 0.503690, -1.021350, 0.753290, -0.932110, -0.903010, -0.119440, -0.468220, -0.852330, 0.264340,
0.616280, -0.500790, -0.874070, -0.277170, -0.645760, -0.260120, -0.411990, -0.354240, -0.206490, -0.401660,
0.119030, -0.744560, 0.374380, -0.705170, 0.790300, 0.581840, -0.374300, -0.818780, -0.786660, -1.080200,
0.455150, 0.705400, 0.161080, 0.642300, 0.575310, -0.181580, 0.435220, -0.489990, 0.228380, -1.460680,
0.168900, -0.224630, 1.217740, 0.129500, -0.326560, -0.433060, -1.170270, -0.334840, -0.950190, 1.372760,
-0.105460, 0.393630, -0.491320, -0.580570, 0.592630, 0.022160, -0.046280, 0.827090, 0.127180, -0.518690,

-5.145990, -7.413380, -1.454790, -6.999200, -5.394860, 1.284710, -4.936610, 5.930830, -0.178050, -1.412890,
0.014140, 1.424300, 2.876960, -0.630540, -2.570720, 1.476790, 0.863190, 6.081080, -1.197360, 7.294770,
-1.775930, -4.319470, -0.662070, -1.850120, -1.403770, -5.423740, 1.399230, -2.265440, 0.493590, -1.231260,
-1.733530, -1.414280, -2.290650, -0.332120, 2.081750, -2.025600, 4.137640, -1.627270, 0.106720, 6.343650,
3.020510, -0.555520, -17.574440, 0.157110, -0.713880, 3.433130, -23.932940, -0.096120, 3.333690, 12.031800,
-0.043920, -2.295440, -6.300450, -0.371350, -0.625830, -0.066690, -0.498400, -0.182210, 0.830070, -0.501150,

0.348200, -0.236780, -0.704790, 0.896540, -0.187520, -0.310200, 0.825150, -0.515190, 0.739910, -0.667150,
0.124580, -0.137620, 0.842660, -0.578900, 0.049370, 0.094120, 0.921140, -0.739740, 0.123210, -0.172640,
-0.168330, -0.230520, 0.966550, 0.351650, -1.009360, -0.827850, 0.605020, -0.055530, -1.107180, 0.908670,
-0.297590, -0.919990, -0.137510, -0.447300, 0.328910, 0.592920, -0.149540, 0.062620, 0.104200, -1.018450,
0.646590, -0.691870, -0.867570, -0.320530, 0.361760, 0.193770, 1.084870, -0.636610, 0.770480, -0.524020,
0.274170, -0.482130, 0.453540, -0.652820, -0.290480, -0.575830, -2.043720, 0.043820, -0.963290, 0.955330,

0.779080, -0.166070, -0.647250, -0.342560, 0.269600, 0.190230, 0.210920, -0.689320, 0.352390, -0.135930,
-0.418600, 0.098050, -0.130300, 0.841350, 0.687330, 0.736920, -0.196170, -0.846450, -0.097810, -0.269870,
0.204870, 0.207510, -0.982250, 0.211050, -0.475500, 0.504130, -0.690140, 0.327870, 0.200060, 0.449520,
0.588790, -0.543490, -0.795200, 0.940840, -0.869710, 0.667440, -0.346040, 0.111130, -0.372590, -0.738460,
0.466510, -0.521030, 0.554050, 0.769090, 0.109420, -0.906820, -0.129560, 0.508940, -0.714010, -0.882190,
-0.486010, 0.024730, -0.835620, -0.951990, 0.238280, -0.044320, 0.642590, 0.259330, 0.378130, 0.331000,

-0.812270, -0.943730, 0.240760, 2.861760, 0.174340, 0.801320, -0.941030, -0.778960, 0.035980, 0.033310,
0.669700, -0.478800, -0.831750, 0.844240, -0.260790, 0.457560, -0.075410, 0.689460, -0.086740, 0.059300,
-0.573380, -0.390410, 0.430450, 0.050700, -0.681780, 0.219290, -0.271550, -0.526010, -0.046310, 0.003580,
-0.435130, 0.467610, -0.274040, -0.193220, 0.045630, 1.761910, 0.779020, -0.976340, 0.746920, -0.295650,
-1.032420, 0.277940, -0.775030, -0.196290, -0.095540, -0.586770, 3.973190, 0.242400, 0.841270, -0.428030,
-0.148170, -0.833980, 0.225870, -0.940030, 0.087430, 0.775130, 0.808090, -0.874460, -0.498650, -0.928420,

-0.806260, -0.003220, -0.763650, 1.618050, -0.287430, 0.149750, 1.599540, -0.361870, 0.453100, 0.513550,
0.327780, -2.064940, 0.454590, 0.057920, -1.320370, -0.592280, -1.204640, -0.245090, 0.271050, -0.518600,
0.039720, 0.597960, -0.716680, -0.021930, 0.061980, 0.752890, -0.081450, 1.122370, 0.778050, 0.734580,
0.670520, 0.052560, 0.687130, -1.024820, -1.514680, 0.767730, 0.854010, -0.627770, 0.645600, -0.121470,
-0.974090, -0.942750, 0.692120, 0.381100, 0.371210, -0.273420, -46.948841, 0.381880, -1.696640, 1.664490,
-0.112060, -4.599170, 0.170800, 0.280530, 0.775060, 0.512040, 0.996130, -1.025750, -0.146980, -0.996370,

0.147000, -0.468150, 0.731730, 0.393340, 0.765400, 0.103370, 0.593980, -0.624470, -0.490720, -0.942120,
0.910070, 0.942090, -0.735140, 0.335070, 0.974770, -0.614400, -0.341630, -0.309680, 0.676240, 0.868320,
0.992200, 0.068460, -0.875840, -0.733640, 0.580340, 0.623580, -0.527250, -0.224000, -0.373860, 0.569180,
-0.934700, -0.591650, -0.052240, 0.998940, 0.536780, -0.669210, -0.115640, 0.414540, 0.445620, 0.957070,
-0.835710, -0.875890, -0.312790, 0.096790, 0.481590, -0.552270, -0.174870, -0.411490, -0.171960, 0.324970,
-0.931580, 0.025080, 0.514310, -0.735610, 0.314670, -0.023890, -0.021680, -0.368220, -0.845660, -0.759930,

0.611950, -0.657260, 0.253130, 0.151090, 0.051180, -0.848240, 0.427810, 0.749540, 0.104660, 0.416190,
0.633610, 0.476290, 0.029440, 1.016790, 0.859780, -0.663400, 0.826600, 0.006320, -0.475150, -0.594690,
-0.267230, -0.248710, -0.855020, -0.587970, 0.388710, 0.336230, 0.952510, -0.387200, -0.701570, -0.290540,
0.410970, -0.312730, -1.073310, 0.614380, -0.493760, 0.513360, -0.611760, -0.969860, -0.816090, 0.659840,
0.426560, -0.355800, -0.372220, -0.190500, -0.563370, -0.825300, 1.082970, 0.355160, -0.472770, 0.328720,
-0.216670, 0.631920, -0.022330, -0.506760, 0.983990, -0.762460, 0.002130, 0.992190, -0.495050, 0.319010,

-0.080130, -0.644930, 0.199440, -1.434270, -0.247660, 0.670550, -1.233020, -0.530140, 0.939020, -0.092230,
-0.553680, -0.085430, -1.272600, 0.264870, 0.151710, -0.766850, 0.244740, 0.662140, 0.060220, -0.460260,
-0.277070, 0.388060, -0.534760, 0.159730, -1.713300, -0.942600, -0.787640, -0.399000, -1.377820, -0.188710,
0.293870, -0.809260, 1.207540, -0.615270, 0.000190, 1.318020, -0.224360, 0.323250, 0.706620, -0.369950,
0.996500, 0.863140, 0.438110, -0.098210, -0.686360, -0.472800, 0.651840, -0.710600, 0.025190, 0.078120,
0.447350, -0.183890, -0.128940, 0.805580, -0.092360, 0.020080, 0.450730, 0.040220, -0.154560, -0.228520,

-0.253120, 0.036610, 0.595390, 5.411150, -0.743390, 0.318970, 0.770560, 0.349440, -0.175750, -0.950160,
-0.178400, -0.955580, -0.603810, -0.156960, 0.524640, -0.965860, 0.234580, -0.015560, -0.115130, -1.057810,
-0.077910, -0.061460, -0.121530, 0.734130, -0.453520, 0.294110, -0.846740, 0.850790, -0.812820, -0.931630,
0.895180, 0.041490, 0.272980, -0.280480, -0.826540, 0.034790, 0.023520, 0.137140, -0.751790, -0.466910,
-0.666700, 0.654950, -0.047650, 0.406070, -0.042160, -0.572080, 1.307400, 0.332160, 0.751460, 0.809630,
0.777870, -0.047540, 0.422800, 0.691550, 0.137370, 0.454150, 0.396920, -0.771570, 0.552300, 0.718990,

0.399100, -0.207880, 0.518060, 4.736700, -0.883970, -0.853890, -0.473080, -0.949880, -0.573110, -0.636000,
0.734450, 0.658140, -0.650100, 0.094580, 0.262760, 0.854460, 0.697590, 0.087140, 0.312450, 0.258230,
0.505230, -0.876060, 0.256390, 0.032780, -0.253150, -0.329100, -0.715460, 0.131030, 0.065480, 0.320850,
0.995490, 0.660110, 0.271010, -0.629040, 0.096560, -0.248030, 0.354740, -0.966600, 0.023140, 0.806950,
-0.441420, 0.775510, -0.152540, 0.485010, 0.047190, -0.427480, 0.857220, -0.885350, -0.808670, 0.909080,
0.308830, -0.196530, -0.809730, 0.373910, 0.670270, 0.605400, -0.403300, 0.645980, 0.416450, 0.072510,

-0.119250, 0.872110, -0.883960, -0.250260, 0.506060, 0.129390, 0.492450, 0.660870, 0.935510, -0.577060,
1.078800, 0.384910, 0.918800, 0.524870, 0.386960, 0.592420, -0.436820, -0.310510, 0.423280, -0.011000,
-0.584740, 0.585640, -0.023760, -0.965050, -0.178760, -1.026650, 0.453040, -0.904060, -0.310950, 0.439330,
-0.522120, -0.887940, -0.641510, -0.906280, -0.966470, 0.243570, -1.031600, -0.401230, 0.608460, 0.432820,
0.791680, 0.638710, -0.222650, 0.447670, 0.855350, 0.438450, 1.255820, 0.522090, 0.905940, 0.644980,
-0.689610, 0.544340, -0.099080, -0.393010, -0.220560, -0.543330, -0.810600, 0.032680, 0.218860, -0.038260,

0.823070, 0.332270, -0.588510, -1.746230, 0.789590, 0.645050, 0.048970, -1.521050, 0.028900, -1.092300,
-0.996280, -1.361700, 0.906660, -4.954970, 1.686060, 3.291450, -1.289720, -0.188520, -1.772450, -0.356610,
-0.810120, 1.195700, -0.941370, 0.664290, 0.647880, -2.708420, 0.079360, -0.942900, -0.052320, 0.916680,
-1.391160, -0.412570, 0.275960, -0.986920, -0.641170, -4.880510, -0.267160, 0.217570, 0.039890, -30.273331,
-0.663830, -1.176390, -0.255580, -0.615250, -1.517330, 1.607050, -0.726480, -0.277090, 0.657980, 1.214940,
-0.294730, -1.487400, -1.647630, -1.313590, -3.679500, 0.626010, 1.829790, -0.268840, -0.030730, 0.251430,

-0.030920, -0.743020, -0.855370, 0.656700, -0.799730, -0.075100, -0.270690, 0.082480, 0.919060, -0.429850,
0.293990, -0.871760, 0.706460, -1.573670, 0.863070, -0.506780, 0.000860, -0.461630, -0.781350, -0.350440,
-0.666170, 0.076600, 0.668420, -0.207060, -0.111080, 0.371720, -0.172540, -1.021000, 0.325150, -0.303730,
0.131200, -0.001800, 0.739570, 0.503240, -0.666620, 0.292150, 0.827800, -0.890780, 0.508960, 0.441200,
0.556940, 0.554070, -0.255010, 0.574370, -0.711110, -0.318100, 1.060220, -0.321110, 0.498520, -0.220350,
0.696190, 0.807650, 1.018480, -0.474450, -0.083220, 0.867280, -0.730210, 0.565920, 0.554820, 0.722320,

0.275020, -0.143220, -0.492700, -0.034570, 0.883780, 0.335870, 0.829790, -0.994380, 0.035790, -1.005520,
0.841850, 0.922170, -0.622000, -0.074640, -0.277890, 0.201360, -0.411500, -0.092640, -0.490630, -0.572110,
-0.165710, -0.305880, -1.126450, -0.009580, 0.094180, 0.873050, 0.990210, 0.912140, -0.924360, -0.550490,
0.124110, 0.562350, 0.698490, 0.041820, 1.268600, 0.450350, -0.438010, -0.027710, 0.974860, 0.582100,
0.194520, -0.507120, 0.280610, 0.897810, -0.888670, 0.951810, 2.170610, -0.707110, -0.232080, -0.699560,
0.235350, 0.999220, 0.496120, -0.954320, -0.822340, -0.276400, -0.502790, -0.340780, 0.636710, -0.677390,

-0.108130, 0.805480, 0.583780, 0.225560, 0.822530, -0.428160, 0.381050, -0.890760, 1.581400, 0.765450,
0.182640, -1.193250, 0.223630, -0.279360, 0.704990, -0.822610, 1.087410, -1.112500, 0.294770, -0.689150,
0.178700, -1.035010, -0.726500, 1.046070, -0.436500, 0.418860, -0.881080, -0.463120, 2.048300, 0.441280,
-0.058470, -1.086150, -3.245170, -0.467380, -12.558270, -0.461220, 0.063520, -0.619960, 0.517960, 0.010160,
-0.458600, -0.120540, 0.740570, -0.978590, -0.812330, 0.764960, 1.727900, -0.466330, -0.516020, 0.437050,
-0.715630, 0.661320, -0.236360, 0.774330, 0.684750, -0.898500, -0.092560, -0.970240, 1.230980, 0.688860,

-0.815620, 0.215930, -0.861630, 0.505270, -0.227240, 1.852760, 3.822100, -0.885370, 11.174270, 0.587090,
1.053180, -0.235880, 0.617010, 0.304490, 1.999920, 0.723520, 0.933810, 5.562150, 0.780260, 5.838990,
-1.009360, 0.530620, -0.916720, 0.893170, 0.801180, 0.216320, 0.263740, 0.097640, 2.223030, 14.876820,
0.686300, 1.017380, 0.025530, 0.842390, 0.175880, 149.922043, -0.171650, 0.401070, 0.777450, -0.005040,
0.557490, 0.536920, -0.445230, 0.891700, -0.162380, -0.293430, -12.086670, 0.808680, -0.221110, 1.089880,
-0.981480, -0.909200, 0.722360, 0.687790, 0.709090, -0.102560, 0.449580, -0.017720, 0.952990, 0.841480,

0.475860, 0.326030, 0.519330, 0.444340, -0.429720, 0.598650, 0.396520, -0.778460, -0.560300, 0.435680,
0.312190, 0.150230, 0.066820, -0.369010, -0.852370, 0.970790, -0.135250, -0.730250, -0.439650, -0.016620,
-0.808330, 0.208660, 0.119650, 0.767110, -0.778630, -1.021500, -0.213330, 1.043370, 0.372480, -0.922460,
-0.245910, 0.419780, 0.830670, 0.055030, -0.424310, -0.154840, -0.484070, -0.504130, -0.937710, -1.020220,
0.138150, -0.143450, 0.606790, 0.653260, 0.201930, 0.446050, -0.062830, -0.499400, 0.386910, -0.603080,
0.099980, -0.102720, -0.283130, 0.412950, -0.493390, -0.223170, 0.115310, 0.930140, 0.615530, -0.251180,

0.932370, 0.497520, 0.881330, -5.257710, -1.247100, -0.156950, 0.547270, -0.712500, -0.396380, -0.965380,
0.036700, 0.454150, -0.551050, 1.453090, -0.529860, 0.954100, 0.153320, -0.787020, -0.961680, 0.395480,
-0.158210, 0.665220, -0.656600, -0.333650, -0.047610, 0.917690, -0.369890, -0.503280, 0.382850, 0.960360,
-0.400340, -0.337800, 0.745280, -0.610140, 0.178380, 0.373420, 0.374870, -0.590510, 0.827990, -1.124430,
-0.397780, 0.878920, 0.736310, -0.350900, -0.435020, 0.040050, -0.330190, 0.257520, -0.154070, 1.917870,
0.513580, 0.946880, -0.914110, -0.421630, -0.683920, 0.074780, -0.564260, -0.098060, 0.417030, -0.885360,

0.531630, -0.564540, 0.059410, -0.988090, -0.375960, 0.311510, 0.511040, 0.748340, -0.248360, -0.400820,
0.577590, -0.341990, 0.246910, -0.115550, -0.491570, 0.640970, 0.244470, -0.066080, -0.032300, 0.038730,
-0.889910, -0.021610, 0.049680, -0.734910, 0.928090, 0.684420, 0.706330, -0.133110, 1.558360, -0.350950,
-0.399180, -0.743570, 0.048640, -0.291280, 1.045180, -0.022190, -0.117940, 0.710580, -0.072600, -0.796860,
-0.943340, 0.818510, -0.830300, -0.498710, 0.326400, -0.173610, -0.756090, -0.180140, 0.150140, -0.678010,
0.468270, -0.197490, -0.031980, 0.208140, 0.692510, -0.149160, 0.872570, -0.013050, 0.633400, -0.043100,

-0.434240, -0.354810, -0.719600, -1.086010, -0.802470, -0.342160, -0.179570, -0.810560, -0.722780, -0.434880,
-0.962470, 1.020350, -0.715280, -0.615060, -0.655420, 0.888840, 0.184880, -0.656320, -0.769760, -0.285490,
0.192940, 0.057500, 0.934350, 0.204410, 0.019260, 0.107510, -1.005590, -0.614080, 0.501890, 0.169440,
-0.062930, 0.437630, 0.123100, 0.173970, 0.470290, -0.066710, -0.632150, 0.004650, -0.805280, -0.704310,
-0.021050, 0.267450, 0.714880, 0.082130, 0.113320, 0.399290, 0.123370, 0.247810, -0.981140, -0.815390,
0.097540, 0.922030, -0.013500, 0.708980, 0.601480, -0.880270, 0.595360, 0.207690, -0.727380, -0.200990,

-0.792920, 0.838570, -0.844290, -1.744860, -0.646410, 0.735870, -3.166270, -0.689800, 0.264500, 0.482370,
2.065480, -0.297250, -0.836740, 0.040130, -0.460750, -0.093370, -0.596470, 0.464030, 1.672500, 4.923890,
-0.131580, 0.749510, -0.468010, 0.477970, 0.549600, -0.378610, -0.367710, -1.109290, -0.374640, 1.552840,
-0.084610, 0.769030, 0.481070, 0.510640, -0.029640, -4.030260, 0.699610, -0.316920, -0.911300, -2.711790,
0.553280, 0.966770, 0.029700, 0.040920, -0.229470, 0.880110, 2.699660, -0.220130, 1.134610, -1.970040,
0.219680, 0.801400, -0.353840, 0.482390, -0.622210, 0.036790, -3.388540, 0.843910, 0.787350, 0.983140,

-0.487060, 0.176910, -0.555790, -1.119090, 0.825510, -1.008740, -1.304190, 0.207640, 0.034340, -0.426370,
-0.145260, 0.279720, -0.566160, 0.947590, 0.959010, 0.742570, 0.136890, 0.028760, 0.208880, -0.734900,
0.930130, 0.932870, 0.229970, -0.887220, -0.594180, -0.826940, 0.399090, -0.102230, 0.899750, -0.963460,
0.444860, 0.507630, 0.056970, 0.630820, 0.452390, -0.204040, -0.397160, -0.602460, -0.788300, -0.106820,
0.456370, -0.431370, -0.562660, -0.104420, 0.060570, 0.895310, 0.153590, -0.251610, -0.253570, -0.302310,
-0.308300, 0.997310, -0.052540, 0.213550, 0.030260, -0.357340, 1.046600, -0.894350, 0.531840, -0.352070,

-0.474670, -0.045410, -0.799950, -0.990540, -0.399290, 0.106040, 0.866110, 0.782010, 0.461970, -0.975820,
-0.258320, 0.905400, 0.167530, 0.514340, 0.544170, -0.119850, 0.682950, -0.572440, -0.145080, 0.039690,
-0.472370, 0.803580, 0.355320, 0.740640, -0.162950, 0.766520, -0.391090, 0.129680, -0.375190, -0.555770,
-0.661570, -1.028270, -0.824480, -0.039710, 0.007040, 0.017140, -0.010650, 0.775310, 0.527960, -0.664270,
0.614470, 0.734870, 0.206610, -0.028480, 0.315520, -0.729860, -0.320600, -0.758520, -0.665270, 0.284600,
0.385700, 0.717110, -0.758220, -0.080600, 0.158730, 0.710790, -0.443310, 0.232300, 0.583970, 0.194730,

-0.743820, 0.943420, 0.341170, -4.178250, 0.604810, -1.703690, -0.590880, 0.198440, 0.108200, -0.804900,
-0.931860, 0.694380, -0.095050, -0.496210, -0.202770, -0.611800, -0.735620, -0.700590, -0.737130, -1.258670,
0.053440, -0.643080, 0.910470, -0.567900, -0.617580, -0.627430, 0.538400, -0.750800, -0.032830, 0.861550,
-0.907350, -0.157230, -0.298140, -0.748360, 1.743650, -0.774850, 0.304800, 0.835630, 0.878480, -0.159240,
0.314080, 0.026960, 0.792150, 0.807010, 0.376970, 0.340240, -2.136550, -0.038050, -0.477260, 0.118130,
-0.219600, 0.619700, 0.202140, 0.195300, -0.990680, -0.645150, -0.281920, 0.341750, -0.225850, -0.006650,

0.954410, 0.998750, -0.143610, -1.046210, -0.367760, -0.802400, -0.025200, 0.894230, 0.082810, -1.508370,
-1.021480, 0.961050, -0.158510, 0.588520, -0.244030, 0.057040, 0.887850, 2.501050, -0.845080, 5.497340,
0.685170, -0.403840, -0.772670, -1.163730, 0.740990, -0.141810, 0.311910, -0.503200, -2.438840, -0.394670,
-0.109100, -0.649160, -0.068200, -0.830370, -0.750210, -0.251750, -0.485500, -0.751630, 0.607760, 0.538070,
1.219710, 0.100280, 1.730020, 1.034650, 0.099910, -0.057970, 9.337870, 0.379200, 0.579490, -1.297690,
0.748350, -0.307680, 0.520780, 0.723790, -0.349140, -0.217500, 0.491880, 0.068270, -0.988200, 0.690640,

-0.955120, -0.970940, -0.713690, -0.059490, 0.766580, -0.419260, -0.699070, -0.717460, -0.980810, 0.774120,
0.349520, 0.369350, -0.494960, -0.034160, -0.486760, 0.764120, -0.231870, -0.323960, -0.397030, 0.925350,
-0.123460, 0.560620, 0.253710, 0.352240, 0.835200, -0.159720, 0.748710, 0.502140, 0.282480, -0.263350,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.262650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.232250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.128280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.098150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, 0.966930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.156840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.493170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, -0.688390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.868100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, 0.684350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, -0.033010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.177340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.323210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.161970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.008120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, -0.689530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.323420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.223140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, -0.084100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.998590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, -0.085680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, 0.599690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.312000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.828560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.489310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.435930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.076360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, 0.657040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.035570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, -0.718070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, 0.747370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.512260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, 0.619130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.453030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.120320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, -0.137440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.248620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, -0.900250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.535050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, -0.564860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.252000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, -0.820120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, 0.765730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.675860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.099220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, 0.056260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.036520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, 0.696990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, -0.636860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.003100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.311930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.370000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.939720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, 0.013130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.535230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, 0.210710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.074890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, -0.397480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, 0.781980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, -0.086210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, -0.651360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, 0.731620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, -0.798920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.883490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, -0.350310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.364420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.006600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.944790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, -0.291770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.853360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, 0.243340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.554650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, -0.804290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.066570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.126840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, -0.876070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.177880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.892870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.475530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.294000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, 0.672600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.126910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.431680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, -0.091460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.267330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.048510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.225230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.831370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, -0.034570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.313100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, 0.840510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.185090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.301490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, 0.232880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.114990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.916450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.481500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.325050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.825610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.470540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, -0.781560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.699890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.717980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, 0.316040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.968220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.959160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.078830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.174340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, -0.972390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, -0.082200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.410640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.919140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, -0.654890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.002140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.564360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, 0.007070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.091870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.699390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.899060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, -0.961550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.233130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, -0.841570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, -0.527340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.372170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.981620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.289220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, 0.186520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.939230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.219270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.289890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.537130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.073020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.275390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, 0.536920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, 0.560220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.508490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.651200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.292030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.548720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.506800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.323160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.853780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.525450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.269870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.880570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, 0.198500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, -0.900910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.730710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.697490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, 0.831020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.360880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, 0.199200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.819840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.943330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.034940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.071650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, -0.750220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.348990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.279220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.750440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.523840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.993920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, 0.103060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.502430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, 0.597010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.556940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.415850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, -0.950770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, -0.577540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, 0.817260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, 0.138200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.281220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.372140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, -0.013570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.921120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.766120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, 0.253550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.912540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.008660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, 0.517920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.909990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.319470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, 0.953140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.696280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, 0.662670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.408680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.096640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.665140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, 0.356080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.564070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.238150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.100460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.603600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.178790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.000210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, -0.886560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, 0.744770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, -0.913150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.020770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.210570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.049850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, 0.532240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.043990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.776720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.961340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.954640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.684500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.892260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.129760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.134430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.824020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.667150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.124030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.269750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.812740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, 0.251720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.686970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, 0.278660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, -0.994580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, -0.842590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, 0.680600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.646690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.792860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, 0.202630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.999390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.798080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.102140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, 0.455320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.231120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.738410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, 0.458320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.089080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.310760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.037060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.769570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.384600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.023420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.020020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.649480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.514970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, -0.769010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.858410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.930500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, -0.537640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.544540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.729510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.604280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, -0.094950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.660720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, -0.235040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, -0.211130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, -0.248830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.578100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.229370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.002460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.280970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, 0.979690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, -0.761820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.853580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.978390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.876940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, 0.421530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.499300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.316910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.576610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, -0.678440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, 0.953430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.156260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, 0.795970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, 1.171580, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -0.573970, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.782840, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, -1.621040, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, -0.269760, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -0.894840, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.332760, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, 0.264410, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.853240, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, 0.965910, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.053350, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, -0.504710, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.527820, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, 0.165890, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, 0.923970, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -1.357030, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.729330, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 0.496870, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, 0.246540, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, 0.641550, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 0.576580, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.057400, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.927340, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, 0.345190, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, 0.111680, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, -0.276660, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.689430, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.055500, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.670430, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, -0.952510, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, 0.277540, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, -0.904210, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.022250, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.079930, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -0.947330, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, -1.255470, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.928180, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, -0.448920, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -0.282600, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.863850, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, 0.797480, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, 0.978380, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -0.145330, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, -0.419120, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.017560, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, 0.749360, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, 0.488620, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.278010, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, -0.938420, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -0.671890, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, 0.180410, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, -0.545460, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, -0.359270, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, 0.192800, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.400660, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, 0.186760, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.828640, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, 0.371840, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, 0.468910, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, 0.947210, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, -0.314770, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
1.42732, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.05034, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.11319, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
0.00002, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
0.33023, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
0.00839, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
0.08705, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
0.42024, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
1.12566, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
1.39849, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.30271, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
0.39840, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
0.96059, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
0.19192, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
1.33610, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
0.00016, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
0.09690, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
1.40633, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
0.89168, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
0.44141, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
1.00691, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
1.25158, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
0.31060, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
0.48870, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.42322, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
0.11885, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
1.33844, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.02952, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.26520, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
1.05555, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
1.27231, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
0.01395, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
0.11320, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
1.30376, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
0.01095, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
0.00069, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
0.15484, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
0.75408, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
0.00136, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
0.00931, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.06512, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
1.28788, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.18828, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
0.83155, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
0.85253, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
1.03931, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
0.02516, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
1.37481, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
0.01382, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
0.01813, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
1.42857, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.16304, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
0.04301, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
1.06709, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.06092, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
1.42509, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
0.46769, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
0.82130, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
0.04463, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
1.42466, 0.500000, 2,
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
