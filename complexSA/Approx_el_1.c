/*********************************************************
  Pfam_el_1_new10new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:12:23 2004
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
0.395340, 0.750900, 0.127270, 0.390740, -0.408540, -1.313090, -1.573280, -0.934850, -0.062660, -1.010990,
-0.126250, -1.049560, -0.444850, -0.213170, 0.044250, -1.047110, 0.934810, -0.836520, 0.112570, 0.900040,
-0.615520, 0.474930, 0.804190, -0.100490, 0.912330, 0.150990, -1.933300, 1.810620, -0.262950, -1.604620,
0.732950, 0.003970, 0.907880, 0.020780, 0.176260, -0.339890, 0.899350, 0.084380, -1.101430, -1.080340,
0.551240, 0.393800, 1.005040, -0.005750, -1.373690, 0.107990, -1.398270, -2.379680, -3.260020, 0.127400,
-1.476870, 0.051230, -0.704460, 0.658430, 1.687150, -5.826690, 0.034390, 0.447560, -1.032460, 0.261620,
-0.068860, -1.636190, 1.177000, -1.259620, 0.495300, 0.479910, 0.312270, -0.607850, -0.428250, 0.309030,
-0.247000, 0.171890, -1.835590, -0.142060, 0.437670, -0.035130, -1.712360, -0.926510, -0.621980, 0.535150,
0.433430, -1.729700, 1.381860, -0.286170, 0.316750, 0.553220, -0.564220, -1.000220, -0.489990, 1.637400,
0.031950, 0.452230, 2.642460, -0.318450, -0.536030, -0.007260, 0.617670, -0.809940, -0.391630, -1.639780,
-1.029620, -1.883500, -1.046030, 2.655380, 1.168560, 1.599880, -0.879220, -1.222490, 1.176160, -1.398020,
0.823430, 0.386130, 1.766340, 0.151450, -1.531270, 0.471220, -0.165230, -0.381000, 0.443370, -0.653130,
-0.820370, 0.847650, -1.188980, 0.724140, -0.848860, 0.425990, 0.329820, -0.202500, 0.519620, 0.627680,
-0.116500, -0.118040, -0.469970, -0.811750, -0.583190, -2.063680, -0.243970, -0.722450, -1.206790, 1.063810,
-0.931960, -1.062820, -0.950280, -0.354900, 1.167080, -0.910850, -1.456780, -1.183240, 0.712780, 0.163750,
-0.480810, 0.511320, -0.622310, 0.096380, -0.454290, -0.897910, -0.468360, -0.277870, -0.470190, -0.294390,
-0.160040, -0.038260, -0.625710, -0.710900, 0.343070, 0.551360, -1.492130, -0.193200, -1.622350, -1.927280,
-0.690390, 0.222770, 0.325250, 0.629670, -0.348470, -0.483260, 1.143650, 1.519690, -1.240080, -0.873980,
0.711310, -0.007440, -0.510770, 0.543830, 0.626190, 0.527900, -1.139610, -1.568500, 0.566420, -0.404640,
-0.720020, 2.501790, 1.144140, -1.629000, 1.302550, -0.576200, 0.258850, 0.339670, 3.129050, -0.376680,
1.060370, -3.173620, 1.608910, -0.519190, 0.426020, -1.651780, 0.371800, 0.483040, 0.037460, 1.379790,
1.550230, -0.031860, 0.608620, -0.085490, -0.916330, 0.225640, -0.437890, -0.619180, -0.536390, -0.918200,
-0.068650, -0.426840, 1.406380, -1.044070, -0.253140, -0.962980, -0.122790, -1.461390, -0.511370, -0.581630,
-0.057490, 0.684610, 0.042700, -0.733920, 1.440140, 0.527500, -0.631520, 0.132660, -1.057020, 0.031220,
0.579230, -0.635010, -1.108570, 1.683230, -0.040370, -0.303790, -0.854540, -1.609280, 0.773560, -0.143540,
-0.085830, 0.276380, -0.551360, -1.948200, 1.149370, 0.174100, 0.058820, 0.100980, -0.484130, 1.713070,
3.675570, 0.143640, 0.452030, 2.628740, 0.553170, 0.919680, 0.250420, 0.120950, -1.341940, -0.728420,
-0.994530, -1.416800, 0.365370, -1.521140, -1.215040, -0.026620, -0.342510, -0.186200, -1.079690, 0.170520,
-0.368370, -0.139390, 0.095990, -1.350720, -0.741200, 0.623760, -1.565550, -0.859410, 0.511280, -0.890620,
-0.682750, -0.304890, 4.752620, -0.243720, -0.681190, 0.399030, -0.092870, 0.122260, -0.572420,
-1.597830, -0.205810, 0.630340, -0.502960, -1.322130, -2.486310, -0.000390, 0.310330, -1.198020, -0.338150,
1.596960, -3.471180, 0.920980, 0.897240, 0.470150, 0.342090, -0.556090, -0.743660, 0.274780, 1.299190,
-2.398080, 0.793920, -1.174640, -0.081410, -0.656360, 2.298550, 0.427430, 1.723080, 0.628600, 0.073840,
1.549510, 4.192190, 6.870680, 0.438660, 0.587990, 0.421570, 0.642660, 2.866290, -0.228030, 0.732060,
3.669700, 3.466270, -0.756520, 0.780300, -1.055540, -1.095420, 1.106640, -0.668470, -1.089480, 1.665680,
0.047130, -0.816020, -2.733610, 0.343860, 1.734240, 0.562590, 0.483170, 0.983310, 1.388060, -0.903910,
1.178870, 0.686700, 0.217220, -0.495240, -0.702040, -0.749740, -0.278300, -0.483650, -3.407660, 0.732020,
0.063520, 0.125230, -1.393600, 0.347080, -1.264230, 0.723300, -1.067630, 1.021210, 1.551230, -0.604680,
-0.686860, 2.112530, -0.119940, -1.289970, -0.957200, -0.196820, -0.920530, -0.484910, -0.084910, -2.170510,
0.828880, 0.304410, 0.660110, 1.433040, 1.505500, -0.158040, 3.711690, -0.044700, 1.808920, 2.678740,
2.672830, 3.528610, 0.859660, -0.575100, 0.495980, 0.174040, -0.369800, 0.506710, 2.372170, 0.350980,
1.057780, 1.352840, -0.178100, 0.634390, -0.346600, 1.702720, 0.722860, -0.505790, -2.018360, 0.304360,
0.997020, -0.364580, -1.495800, 1.147570, -1.066820, 0.156910, -0.312550, -1.460340, 2.338040, -1.430040,
-1.421690, 0.129510, 0.037190, 1.045950, -1.292920, 2.047470, -0.713270, -0.026580, 2.659850, -2.106850,
-0.050690, -1.532760, -0.233300, -1.249450, -0.322880, 0.409430, 2.996810, 1.819950, 0.474340, 0.888080,
-0.246210, 0.711280, -1.689640, 0.102260, -1.371370, 2.292350, 0.931470, 0.054910, -0.325660, -1.067700,
-1.665680, -1.158190, 1.446910, 2.069400, 0.901870, 0.391310, 0.504220, -0.568460, 1.077390, 0.536380,
-1.589480, -0.477520, 0.786910, -0.636140, -1.390860, -1.385480, 1.681050, 0.522180, 1.613900, 0.201720,
-0.264270, -0.665290, 2.138000, -1.196530, 2.500830, 1.422360, 1.001590, 0.021920, 1.627670, -1.083900,
-2.116290, -0.095920, 0.858970, 1.226720, -1.489270, 2.422070, 0.032080, -0.712640, 0.060200, 0.347180,
1.146030, 3.032870, -0.133340, 0.421030, 0.812160, -0.067000, -0.873420, 0.104850, 0.948870, 1.012590,
-1.628830, 1.020760, -0.973010, 0.484430, 1.141240, -0.057560, 1.180390, -0.677230, -1.605130, -0.526100,
1.822060, 0.331480, 0.793110, -0.504000, 0.875670, 0.306600, 2.512160, -0.585650, -0.700100, -1.704060,
-0.287610, 1.149740, 1.113600, -1.424820, 0.192050, -0.024050, -0.544190, 0.821060, -0.903210, -0.384810,
-0.967890, 0.999860, 0.715380, -1.350820, 1.121570, -0.170360, -1.330730, -0.362000, -0.269710, -0.245150,
-1.738230, -0.125740, -0.707910, 0.668010, -0.711860, -0.098290, 0.369170, 1.551910, -0.028600, -0.840050,
0.714260, -0.075530, -0.153140, -0.702130, 0.415720, 1.010860, -1.219400, -0.812490, -0.200030, -1.096840,
0.905690, 0.433790, -0.067630, -0.970990, -0.369210, -0.435950, -0.847900, 0.948320, 0.446400, -0.352570,
0.156650, -0.896720, -0.592610, 2.501660, 1.120180, -0.408290, 1.108600, -1.618660, 0.045310, 0.112600,
-0.192990, -0.319020, -0.085180, -0.778600, 0.274160, 0.274450, -0.131790, -0.918870, 0.485280,
-1.752060, -3.396610, 0.597760, -0.186420, 0.078340, -1.392340, 0.961680, -0.476290, -0.228210, 0.640460,
-0.933870, 0.363430, -0.045380, 1.576090, -2.392180, -0.610050, -0.815330, 0.324570, -0.964290, -0.462300,
0.785750, -0.842540, -0.088360, -0.489370, 1.387360, -0.364340, -0.812330, 0.683000, -0.054020, -0.271640,
0.680390, -0.444190, -0.216390, -0.559040, 0.026220, 0.188290, -0.004070, 1.226820, 0.905790, 1.245040,
-2.305640, -0.205200, -3.936530, 1.156910, 0.383860, 0.436670, -2.063440, -2.214550, 0.389820, -1.706580,
-1.428410, 0.386250, 0.427230, 2.767710, -0.603980, 0.188940, 0.636130, -0.581870, -1.408580, 0.320890,
0.274990, -1.128540, 0.588400, 0.325220, 0.022770, -0.344190, 0.056890, 1.401780, 0.375410, 0.249750,
1.090200, 0.644400, 0.009370, 1.505030, 1.803970, -0.554050, 0.089360, -0.441990, -0.161750, -0.585040,
-0.218890, -0.932210, 0.243960, 0.657680, -0.093310, -1.927630, -0.613400, 0.191860, 0.034070, -0.168070,
-0.279030, -1.807430, -1.321130, 0.282310, -1.608070, -0.348290, -0.196670, 0.461840, 0.457340, -1.498370,
-0.157840, 0.109490, 0.050760, 1.280850, 0.690200, -0.093260, -0.424260, 1.139120, 0.043460, 1.077190,
0.265900, -0.206310, 1.009840, 1.110590, 0.852430, 0.280470, 0.338860, 0.782340, 0.614770, 1.385790,
0.309170, -0.343540, -0.403420, -1.986450, -2.742980, 2.500660, -1.724080, 0.163720, 0.434760, 0.352560,
0.762390, 1.539590, -2.188900, -0.020590, -0.854460, 0.593410, 0.125990, 0.441480, 0.244160, -0.331210,
0.176030, 0.552310, 0.282040, -0.010190, -0.620520, 1.858050, 1.227030, -0.104040, -0.935550, -0.265610,
-1.326590, -0.125140, 0.729110, 0.143720, -1.345200, 0.673840, 0.880260, -0.187740, 1.302350, 0.647830,
-0.862570, -0.250010, -0.859280, -0.132450, 0.989420, 0.841150, -0.655610, 1.715000, -0.275440, 0.002580,
-0.444400, -0.283150, -0.161140, -2.160270, -0.120740, 0.110210, 2.428710, 0.942070, -0.792930, 0.696720,
0.349420, -0.550570, 1.009380, 0.719040, -0.236960, -1.549530, -0.569060, 0.036270, 0.693640, 0.048880,
2.002250, 1.423680, -0.274690, 0.144930, -2.383530, 2.187610, -0.002630, -0.480070, -0.477430, 0.173680,
0.823340, 0.892370, 0.810880, -0.383520, -1.991860, -0.305200, 0.270430, 0.407530, 1.473980, -0.049530,
-0.130800, -0.195840, -0.596900, 0.969390, 0.067710, 0.028050, -0.753230, 0.585670, -1.317600, 1.599060,
0.750210, 0.495910, -0.393120, -1.236300, 0.634560, -1.253520, -0.176330, 0.985360, 1.008110, -1.528050,
0.492820, 0.573030, -0.778180, 0.563030, -0.607850, 0.662810, -0.289860, 1.123380, -0.409280, -0.540090,
-1.872090, -0.317090, 0.054270, -0.217810, 1.539760, 0.020040, 0.878960, -0.339680, -0.474620, -0.484940,
-2.527970, -0.985970, 0.409210, -9.372960, 3.329650, 0.394750, -2.504820, -1.160630, -1.764330, -0.332120,
0.991890, -0.776670, -2.733740, -1.291330, 2.564010, 2.367060, -1.545090, -0.838650, -4.446860, -2.775010,
-2.010310, -5.850790, -2.910590, -3.015450, -0.711240, -1.772870, -2.017410, -0.639460, -2.413080, -1.455740,
-1.397440, -11.096060, -1.426780, -0.382270, -3.133400, -3.870450, -2.026580, -0.965280, -1.914800, -3.790810,
-1.919680, -1.477480, -0.534380, -2.468090, -2.772500, -2.514750, -1.701620, 1.120730, -2.123810,
0.662040, 0.285130, 0.074370, -0.598440, 0.927810, -0.775570, -0.211790, 1.978350, 1.052080, 0.596090,
1.035590, -0.165480, 1.386400, -1.201400, -0.477360, 0.733930, -0.203130, 0.086930, -0.402390, 1.059410,
1.607000, 0.036510, 0.892070, -0.099140, -3.331000, -0.896780, 0.814490, -0.576720, -0.955100, 0.944150,
1.138140, 0.332190, -1.234370, -0.226160, 1.387030, 1.131920, 1.622240, 0.236080, 0.147550, 1.108430,
-0.521070, 0.724470, -0.357050, 0.947810, -0.186350, 0.460750, -0.066660, 0.787540, 0.125120, -0.209930,
1.052160, -0.154390, 0.439680, -0.211000, -0.105420, 0.106670, 0.448150, -0.345720, 0.866570, 0.559560,
0.817350, 0.790200, -0.748610, 0.421210, 0.678570, 1.285110, -0.078130, -0.239250, 1.002780, -0.312360,
0.792390, 0.417450, 0.746100, 0.719580, -0.685930, 0.028660, -1.214880, -0.152470, -0.055030, -0.806110,
0.574850, -0.814210, 0.322520, 0.968630, -1.463290, 1.298560, 1.863710, 1.998410, -0.903520, 1.260190,
0.655050, 0.464420, -0.166480, 0.186620, -0.399630, 0.916940, -0.131960, -0.841800, 0.450370, -0.175820,
0.613710, 0.424270, -0.895080, 0.583690, 0.797940, -0.215720, -0.140450, 1.314610, 0.020680, 0.513870,
-0.232540, 0.126840, -0.628020, -1.097940, 1.200910, -4.122800, -1.663640, -2.462560, 8.758340, -2.780660,
0.067650, 3.408070, 1.138120, -1.961610, -1.876930, 0.665360, 0.542290, 0.644990, -0.296960, -1.281910,
0.262650, -0.072170, 0.353940, -1.983740, -0.015300, -0.121170, -0.564600, 1.089010, 0.968230, 0.064610,
1.008460, 3.928280, 1.022990, -0.583940, -0.014200, -0.177360, -0.193990, -0.945880, 0.370180, 2.205890,
0.635530, -1.825920, 0.134580, 0.502900, 1.189120, -0.871780, 1.588600, 1.465820, 1.427110, -0.603080,
2.781810, -1.173180, -2.732290, 0.298890, 1.440890, 0.121470, -0.051430, -1.113260, 0.010970, -0.265980,
-0.152250, -0.515730, -0.862590, -1.802030, -0.748490, -0.170250, -0.925100, -0.898230, -0.298800, -0.808010,
-0.913210, 0.743500, -1.074770, 0.071440, -1.029510, -0.606230, -0.785350, 1.080480, -0.403150, 0.061180,
0.698820, 0.097630, -0.154500, 0.105410, 0.171310, -1.113420, -0.038150, -0.391760, 0.042840, 0.591750,
-0.310550, 0.964460, -0.350280, -0.276610, 0.583900, -0.674480, 0.936410, 1.479010, 0.043620, -0.734580,
1.122220, -1.268900, 0.657850, -0.372430, -0.371400, 0.261930, -1.830660, -0.309270, 1.896160, -1.466230,
1.188850, -0.614200, 0.545140, 0.334070, -1.241080, 1.293240, 0.467230, -1.385170, 0.725760, 0.204980,
0.046480, -0.454320, -0.064480, -0.470170, -0.742430, -0.049150, 0.036410, 0.156580, -0.178300, 0.644320,
-0.913620, 0.014390, -0.024690, 0.623570, 0.229040, -1.378960, 0.626030, 1.264640, -0.040660, 0.885670,
1.283330, 0.825630, 0.010330, -6.464210, -0.763560, -1.696800, -0.495170, 0.761140, -0.018850, 0.365800,
-0.532200, -0.156740, 0.010640, 1.692750, 0.952090, 0.014270, -1.449260, -0.479030, -0.785880, -1.511360,
-0.560490, -6.018170, -1.423340, -3.526750, -0.228850, -1.233990, -4.556220, -1.245350, -2.170970, -8.005820,
-1.215490, 4.841630, -1.339620, -2.636490, -0.811250, -1.169540, -1.337170, -0.121970, -0.246230, -2.445530,
-5.774390, -1.084150, 5.157660, -2.325050, -0.076760, -1.941090, -0.770420, -0.235710, -0.057920,
-0.277380, 0.620350, -0.942300, -0.661510, -0.430500, -1.292050, 0.618670, -0.271070, -1.061590, -1.536000,
1.159800, 0.928150, 0.104170, 0.279840, -1.150910, -0.351620, 1.427380, 0.773960, 0.435520, 1.122160,
0.770800, -0.262740, 1.058500, 0.989460, -0.913460, -0.416960, 0.429090, -0.428450, -0.763910, -0.014060,
0.063650, -1.035620, -0.887450, 0.051240, 0.746340, -0.081990, -0.098510, 1.164850, 1.958310, -2.237470,
0.464900, 0.535550, -1.296490, 0.221430, 0.128810, -0.561830, 0.466400, -0.663620, 0.324260, 0.245610,
-1.049190, -0.567470, -1.137760, 0.027310, -0.093600, -0.125220, -0.348360, -0.958900, -0.997150, -0.957360,
1.135290, -0.762210, 0.253090, -1.037250, -0.113040, -0.068250, 2.844550, -0.708730, 0.549640, -1.256020,
-0.108010, 0.046270, -0.060980, -1.285410, -0.243060, -0.688370, -0.903990, 0.165340, 0.526810, -0.591090,
-1.025190, -1.405990, 1.075310, -0.642400, -0.065520, -1.369010, -0.494120, -1.736560, -0.355400, 1.605750,
-0.641110, 2.629680, 0.569070, -1.227820, -0.555930, -0.701330, -0.182410, -0.926110, -0.533180, 1.519390,
-0.937210, 0.169520, 1.842090, -0.207430, 0.349820, -0.631000, 0.946100, 1.124470, -0.818960, 0.756430,
0.103680, 0.757030, 2.115640, 2.527130, -0.118790, -1.890590, -1.435310, -1.433030, 5.378240, -2.890030,
-0.183650, 1.930710, -1.247520, -4.221520, -2.265160, 2.597030, 2.323490, 0.783700, -1.511870, 0.417510,
2.540870, 1.001870, -8.621610, 2.358050, 2.276630, -6.288380, 1.445000, 1.852760, 0.736110, 1.926750,
1.639240, 0.294880, 1.531760, 1.872910, -0.382890, 2.738670, -0.571420, 2.293070, -2.486450, -0.486650,
0.018900, -1.899010, 0.387070, -0.679600, -0.349330, 0.491200, -2.641630, -1.617900, 1.090670, 0.682620,
1.061940, -2.593130, -3.284840, -1.430420, -0.474890, -0.127490, 0.388300, -0.362600, -0.697560, 0.031460,
0.251720, 0.470910, 0.766520, -0.585860, -0.236510, -1.093810, 0.703370, 1.041880, -0.996340, 0.197490,
1.074280, 2.720820, -0.029380, 2.830570, -0.314080, -1.688230, -0.740370, -0.236710, 0.355200, -0.985970,
-1.032070, -0.742720, -1.352510, -1.152570, 0.210130, -0.099810, -0.970650, -1.587490, -0.060970, 0.101840,
1.009960, -1.336290, 0.468480, -0.379670, -1.193910, 0.594390, 0.770330, -0.183730, -0.564810, -1.643410,
0.909930, 0.549070, 1.064870, -0.943290, -0.059710, 2.685620, -0.311800, 0.812140, -0.790410, -0.060130,
0.012590, 1.207210, -0.682630, 0.405630, 1.685320, -0.411930, 0.842080, 0.973780, -0.007570, 0.382260,
0.677300, 0.167640, 0.665550, 0.993780, 0.207980, -1.523690, -1.858310, -0.324950, -2.153690, 0.586090,
-1.246320, 1.039960, 1.159500, -1.819520, -1.904120, -0.600720, -1.354810, 0.328910, 0.673050, 0.250910,
1.467480, 0.166940, -0.227560, 9.600110, 0.196580, -1.139610, 0.245500, -0.650760, 0.210830, -0.837880,
0.066420, -1.266010, 10.164060, 0.824540, -1.345360, 1.265070, 0.170590, 0.344320, -0.370630, 0.070210,
0.461730, -1.379180, -0.224380, -0.187340, -0.755010, 0.393160, 0.319290, 0.237820, 0.863170, -0.850070,
-0.662850, 0.979840, -0.828040, -0.642950, -0.537840, 0.472310, 0.866180, 0.868650, 0.333300, -0.605960,
0.796450, -0.651070, 0.850260, -0.161540, -0.774760, 2.627670, -0.133820, 0.492270, 0.638240,
-0.256060, 0.612510, 0.633300, -1.415200, 1.591710, -0.090060, 0.508340, -0.161200, 0.263730, -0.997130,
-0.196070, -0.542130, -0.670040, -1.591100, -0.124550, -0.575780, 0.456500, 0.864230, -0.394480, -0.752850,
-3.768760, 0.853380, -0.547570, -1.172110, -0.080950, 1.906780, -0.135500, -1.015940, -3.864740, 1.202100,
1.416750, -0.205150, -0.549640, 1.186570, 0.235930, -0.578760, -0.830310, -1.014000, 0.833890, 0.208970,
1.200400, -0.215430, 0.795260, -1.311980, 0.059000, -1.094920, 0.514960, -0.525060, 0.067480, -0.600140,
-0.086100, 0.025570, -0.735030, 0.185480, 0.631800, 2.373280, 1.315490, 0.477490, 0.981230, 0.176750,
-1.614480, 1.397660, 0.267200, 1.812530, 0.580170, 0.571260, -1.228370, 1.431320, 0.278310, 0.428940,
-0.584040, 0.473250, 0.802010, 0.683490, 0.006120, 0.996620, 0.715520, 0.253670, -0.384680, -1.376410,
-0.140370, -0.555960, -0.842830, -0.725210, -2.359790, -0.420450, 1.658590, 0.297160, 0.930170, -1.394070,
-0.295040, 0.292190, -0.942150, 0.838740, -0.577080, 0.873400, -0.041570, 0.344780, 0.556610, 0.984550,
-1.494410, 0.057840, -0.472270, 0.295190, -1.084650, -2.624550, -0.710280, 0.312760, -1.054370, -0.608930,
2.034060, 0.399010, -2.941630, 1.192320, -0.886140, 2.123690, 2.808460, -2.719060, -1.966860, 5.546740,
-0.998220, -3.316380, 1.456280, 1.177820, 3.529230, -0.824540, -0.381700, -1.070560, 1.847570, 0.412450,
-0.553250, 0.318000, 18.825171, 0.546190, -2.077620, 15.090200, 4.528810, -0.726530, 0.221620, -0.801720,
-0.403450, -0.260330, -2.118390, 1.249200, 1.386860, -2.704160, 0.785850, -0.704520, 0.614010, 0.860710,
-1.236850, 0.490990, -0.899240, -1.105550, 0.528020, 0.748360, 0.485400, 0.036240, -0.963910, -0.418410,
-0.096410, -0.813530, 0.104550, 1.519270, -0.177820, 0.608890, -0.116030, -0.495250, -0.063000, 0.024810,
0.348180, -1.977400, -0.620870, -0.786740, -0.572300, 0.657410, -0.323970, -0.650910, 0.423890, 0.613020,
-0.713380, -0.831190, 2.085900, -0.240230, -0.323140, 1.082860, 0.738530, 0.022110, -1.001630, -2.043670,
0.285650, 0.279290, 0.827460, -0.000270, 1.027570, 0.336090, -0.750540, -1.382100, -0.796020, 0.100860,
0.684140, 1.490980, -0.447730, 1.120260, 0.465950, -0.299830, -0.870340, -0.781860, -1.481820, 0.316480,
-0.227760, 1.365260, -1.206410, -0.042800, 0.925780, 0.339880, 0.341920, -1.231720, 0.953460, 0.612800,
-0.417280, 0.664530, -0.540140, 1.001130, 1.828900, -1.622720, 0.577200, 0.517960, 2.363280, -1.680780,
0.130970, 0.732220, 0.559340, -0.309450, -0.632390, 1.063440, 0.356840, 0.298820, 0.050290, 1.667560,
-0.859180, 1.480340, -0.168950, -1.018320, 1.361390, 0.327530, 0.442240, -0.327990, 0.845960, -0.790650,
-3.470210, 1.106800, -0.710820, 6.889510, 0.117240, -0.630250, 0.741790, 0.134640, -0.445890, 0.443770,
0.578980, -0.575860, 2.212900, -1.406540, 0.000560, -3.159210, -0.805470, 1.511170, 0.329680, 0.852090,
0.135090, 0.098490, 0.335510, -0.242840, 1.956540, -1.027050, -0.741700, -0.840100, 0.732780, 4.846980,
-0.070410, -5.247040, -0.299340, 0.655620, 0.556600, -0.951230, 0.817590, 0.402000, 0.009710, 0.912130,
0.546120, 0.409460, -0.398640, 1.012890, 0.817950, 0.363110, -0.678660, -0.023670, 0.358560,
-0.462620, -1.819030, 1.260210, -0.783770, -1.175620, -0.633370, -0.862760, 0.317770, 1.175740, -1.414620,
-0.690870, -0.016830, 1.564610, 1.613770, 0.084120, -0.725580, 0.012860, -1.578260, 0.025100, 1.335330,
1.195520, -0.103870, 2.771420, -0.763550, 0.004550, -0.664870, -0.673330, -2.094150, -0.266220, 0.119420,
-0.346520, 0.465780, -0.714820, 1.340780, 0.158590, -0.442540, 0.897930, -0.662940, 0.445380, 0.600940,
-0.149470, -0.709590, 0.871330, 2.609680, -0.065120, 0.479000, -2.614330, -1.817500, -1.636040, -1.961570,
-0.515980, 0.391520, 0.004120, -1.124100, -2.382370, -2.631270, -0.246680, -1.406460, -0.698600, -0.381120,
-1.018070, -0.242520, 0.346660, -1.289660, 1.722010, 0.987500, 1.702080, 2.596440, 0.306020, -2.430810,
-2.172080, 0.467740, 0.792130, -0.646720, -2.385910, 0.350950, 0.813080, -0.941780, -0.257340, 1.278910,
1.301510, 0.011240, 2.379830, -0.417220, 1.292340, 0.648780, -0.941180, -0.844890, 0.701210, 1.326060,
0.013060, 0.972080, -0.988130, -0.107470, -0.880170, -0.483320, 1.105000, 0.759240, 0.250540, 1.017890,
0.412100, 0.234690, -0.218010, -0.100590, 0.746010, 2.027400, -0.110860, 0.108160, 0.096330, -0.351330,
1.185020, 0.035990, 2.830180, -0.790700, 1.623380, -0.476490, -0.158760, -1.287360, 4.963950, 4.504000,
0.013670, 3.184130, -1.838660, -4.750740, -4.141980, 0.154530, 1.137190, -0.054700, -0.458810, 0.091270,
-0.141850, 2.881660, -5.139950, 1.568840, 1.800890, -1.721510, -0.134120, 1.862480, 0.735840, 2.321720,
-1.799870, -0.374010, 0.137910, 0.417010, -0.560960, -0.944420, -0.711370, -1.246600, 1.301660, 1.254260,
-0.514300, -0.569510, 0.209450, -0.830770, 0.137110, -3.147600, -0.675930, 0.197950, 0.230740, -0.829250,
2.208480, 1.727670, -0.590670, 0.382620, 0.581920, 0.114130, -0.248090, 2.230300, -0.610570, 1.073060,
-0.784630, 2.715350, 0.844060, 0.647990, -0.521400, -0.135780, 2.327750, -1.485100, 0.572740, 0.293550,
0.370560, 1.242520, -0.217380, 1.709900, 0.606840, -0.495610, 0.083420, 2.045580, -0.384890, -1.083870,
1.332340, 1.302690, 1.274240, -0.327630, -0.381290, -1.644580, 2.030070, 0.858640, 0.430490, 0.208150,
0.142640, -1.505860, 0.161960, 0.387060, -0.329980, -0.598210, 2.882240, 0.346410, 0.377770, -0.376860,
1.015850, -1.141420, -0.457310, 1.888740, 1.148960, 0.833500, 1.394950, -0.019280, -0.777850, 0.990760,
0.479930, 0.709100, 0.523180, 0.755650, -1.535250, 1.273000, 2.076720, 0.794850, -0.608030, 1.148670,
0.000970, -0.170310, -2.247570, 2.236640, -1.030350, 0.309150, -0.199380, -1.876090, -0.908670, 0.647470,
0.637830, 1.374260, 0.611500, 0.171260, 0.890230, -0.635640, 0.564000, -0.552540, -0.363950, 0.018830,
3.313950, -0.748690, 0.200790, -0.080070, -0.064620, -0.638050, 0.567660, 1.024420, -0.050720, 0.455400,
-1.297010, 0.105720, 1.786040, -0.320730, -0.245360, -0.129740, -0.182470, 0.105460, 0.550500, 0.534550,
-0.813140, -0.954420, 0.346200, 0.601810, -0.536460, 0.282840, 0.099060, -0.625830, -0.161530, -3.903600,
-0.844940, -0.533190, 0.313020, -0.470510, 0.247660, 0.053460, -0.977460, 0.241010, 0.513530, -0.432230,
-0.071610, -0.226680, -0.977020, -0.584840, -0.838580, -0.367550, 0.162110, -0.351010, -0.874970,
0.281590, -0.619250, 0.059420, 0.876880, -0.519750, 0.737170, 1.446440, -0.253210, 0.714120, 0.501500,
0.059740, -0.293980, -0.459420, 0.601370, -0.974240, 0.240230, -1.565000, -0.123780, 1.310890, 0.008510,
1.329530, -0.781350, 2.084560, 0.782720, -0.856690, -1.032940, 0.445900, 0.437770, -0.683520, -0.542990,
0.236400, 1.378990, -1.226060, -0.322640, 1.059820, -0.346970, 0.515970, -0.906560, -0.677400, -0.539190,
0.187450, -0.910830, 0.089590, 0.542900, -0.430430, 0.995400, 0.953230, 0.087760, -1.335970, -1.137040,
-0.489910, 0.345890, 0.357200, 1.122040, 1.281110, -0.305270, -0.425510, -0.018360, 0.309160, 0.149500,
-0.035000, -0.543570, -0.824400, -2.729970, -0.763650, -0.484630, 0.222960, 0.087670, 2.385420, -0.947590,
0.077670, -0.850830, 0.792410, 0.476810, 0.815280, -0.837820, -0.594070, 0.255230, 2.897010, 0.427660,
1.176220, -1.718660, 1.454240, 0.687530, -1.007080, 1.389880, 0.587560, 1.065430, 0.298810, 0.089290,
-0.671890, -0.235450, 0.105640, -0.696070, -0.694770, -0.486120, -0.540270, -1.175710, -1.819300, -0.422370,
0.149390, 0.123550, -0.207770, 0.294290, -0.511420, -0.563630, -0.621480, -0.356690, -1.661440, 0.045480,
0.131830, -0.592210, 1.271330, 0.943920, 1.206700, -0.243400, -1.795980, -0.036120, 0.547880, 0.958870,
-2.141550, 1.566020, -1.664490, -0.438580, -2.437940, 1.164540, 2.093460, 1.576050, -0.766640, 0.574060,
1.977200, 1.055500, -1.371110, 1.713380, -0.039600, -1.301980, -0.404080, 3.710480, -0.915190, 0.174300,
0.397910, 0.845360, -0.364860, -0.139780, -0.397440, -0.625530, -0.533160, -0.482350, 0.276560, -1.183690,
-0.654380, 1.104010, -1.624560, 0.148600, -0.968770, 0.229920, -1.195520, 1.303340, 0.119630, -0.855710,
-0.342440, -0.536600, -0.959460, -0.922880, 1.171300, 0.777280, -1.140800, -1.253640, -0.674590, -1.399690,
1.258410, 1.081620, -0.387020, -0.108330, -1.235320, -0.895910, -0.329140, 0.491960, -1.160930, 0.772290,
-0.150890, -0.151780, -0.472950, 2.038850, -1.721500, -0.779810, -0.131730, 1.308390, -0.590270, -0.460890,
-0.148680, 0.687700, 1.003550, -1.239550, -0.876230, -0.935310, 0.211800, -0.598590, 0.542980, 1.803380,
-0.838230, -1.742960, -0.729130, 0.246490, 0.122770, 2.507440, 1.431220, 0.844910, 1.096090, 0.553290,
0.279210, 1.121590, 0.691260, -0.177760, -0.533850, -0.470400, -1.700180, 0.041340, 0.750020, -1.180910,
0.249230, -0.742360, -0.033020, -1.808910, -2.243700, 1.422620, 0.337940, 1.162560, -1.321930, 2.990790,
-1.010300, -1.614940, -0.642800, 0.463260, 0.461760, -1.188050, -1.627820, 1.396890, -0.372720, -0.469060,
0.473380, -0.921670, -0.095060, -1.199170, -0.988780, 0.362360, 0.018800, -0.514850, 0.807390, -1.427800,
0.817930, -0.576570, 0.278730, 6.215220, -0.386220, -0.606860, -0.266210, -0.312400, -0.970220, 1.995710,
1.519040, 0.446550, 1.377650, 0.653160, -1.300060, -1.298760, 0.246630, -0.719300, -0.199390, -0.366880,
0.505390, -0.707420, -0.500340, -0.321420, 0.779440, 0.506280, 0.140840, -1.051520, 0.944560, 0.658690,
0.454690, -0.218350, 0.197820, -0.605200, 2.049330, -0.838090, 0.022060, 0.861500, 0.612670, 0.017770,
0.659660, -0.336700, 1.609770, 0.547670, -0.506570, 0.224950, -0.207190, 0.277190, 0.759600,
2.852290, -0.260250, -1.154590, 0.292960, -1.201710, 0.659460, -0.145180, -0.637500, -0.393980, -1.651340,
-0.460390, 0.448500, 1.150870, -0.562170, 1.369400, 0.635970, 2.366900, 0.604270, 3.557210, 0.076560,
0.802760, -0.522210, -0.625020, 1.345110, 0.022150, 0.219890, 1.289350, 0.174660, 0.449910, 1.277550,
0.111920, 0.718790, -1.878180, 0.217450, -0.175700, 0.903710, 1.468400, 0.698270, 0.169660, 0.669430,
1.840260, -1.018030, -0.409260, 1.570250, 0.731740, -0.642720, 1.807800, -1.655630, 1.312150, -0.664830,
-0.164170, 1.376390, -0.040680, -0.777470, -0.056360, -0.884000, 1.183870, 3.926780, 0.031410, -0.921890,
0.904670, 1.264890, 0.717530, -2.226650, 2.640720, 1.075380, -0.635720, 0.095280, -0.683180, -0.359500,
-1.020240, -0.800550, 0.863100, -0.130700, -0.870390, -0.865980, 0.568700, -0.543930, -1.523210, 0.583420,
0.567130, -0.566690, -0.518880, -0.369090, -0.560820, 1.100550, -0.522900, 1.204970, 0.185880, -1.102760,
-0.413080, -2.017010, -1.038870, 1.282110, -0.650980, 0.914060, 1.111460, 0.888070, 0.037730, 0.490670,
-0.580480, -0.255000, -4.153830, 0.912770, 0.144010, 2.018160, 1.086740, -1.365790, -0.239930, 0.105230,
-0.073450, -1.035240, -2.475250, -0.693340, -0.927640, 1.685200, 0.746570, 2.288210, -0.563370, 1.386750,
-2.984220, -0.687560, 0.024330, 2.087330, 6.089800, -3.807630, -0.401740, -0.338250, 1.709170, 7.592760,
3.105030, -3.197140, 3.367430, -2.228120, -2.098990, -0.059720, -1.881980, -2.035490, 1.985000, 0.146850,
-0.640000, 0.518500, 1.161770, 0.077320, -0.883800, -1.928340, -0.586520, -0.579640, -0.475130, 1.511770,
0.355450, 0.687420, 0.829410, -0.248270, -0.967500, 0.326720, -0.432970, 0.211660, -0.799010, -0.006130,
-0.532510, -2.588260, -0.126650, -0.405720, -0.668820, -0.662870, -2.153380, 0.252390, -0.222760, -0.980330,
-3.157830, 2.003840, 0.073280, 3.243590, 0.582710, 0.022690, 6.236920, -0.333190, -0.050340, 0.436880,
1.113720, -1.326400, 1.221940, -0.679230, 0.207570, -0.153280, -2.805060, -0.120900, 0.356070, 0.197350,
0.377360, -0.959250, -2.363350, -2.411550, 0.732340, 1.170820, 1.032090, -0.334690, -0.297360, -0.736540,
1.004470, 1.020070, -0.766130, 0.514600, 0.086500, 0.354700, 0.161890, -0.238850, 0.258290, -1.398690,
1.078810, -2.220670, -1.402810, 0.489800, 2.558200, -1.629820, -4.815270, 1.179560, 1.712060, 2.294040,
-2.818220, -0.304950, 0.567280, 1.701980, -1.453460, 0.126570, 0.969260, 0.280870, 1.214520, 0.390530,
-0.687620, 1.231380, 0.642340, 0.580870, -0.959750, -2.693770, -1.070010, 1.000910, -0.322930, 1.133960,
0.245500, 1.445880, 0.700500, -0.417980, -0.077600, 0.545770, -0.456330, 1.697270, 1.001400, 0.992530,
-1.573210, 0.261570, 0.190270, 0.431290, -0.242340, -0.133640, -0.208590, -0.079260, 0.773960, -0.781280,
1.093330, -1.137780, -2.114500, 1.301520, -0.835840, 0.808340, 0.673200, -1.496710, 1.549630, 0.246990,
0.605650, 1.310470, -0.563760, -0.104280, 0.598730, -0.727690, -0.630360, 0.019530, -0.073620, 5.375390,
0.948860, 0.569120, -0.438150, 0.485230, -0.936340, 0.511610, -0.978850, -0.594390, -0.402680, 0.278170,
-0.551470, 0.032530, 0.494190, -0.632410, 0.698710, 0.954640, -0.446530, -0.214520, 0.392600,
-0.544380, -0.421280, -0.436860, 0.848780, -0.082310, 0.437950, 0.020630, 0.076620, 0.280210, 0.901130,
0.622730, -0.975750, 0.154620, -0.037160, -0.363320, -0.906180, 2.670050, 0.743850, 0.317870, -1.570840,
1.268270, 0.247630, 2.082790, 0.323370, -1.925920, 0.526850, 1.874000, -1.362640, -1.745790, -0.788560,
0.223630, -1.028870, -0.590690, 0.299340, 0.366380, -0.203000, 0.048090, 0.114010, 0.935860, 0.535500,
-1.781080, -0.418000, 1.278620, 0.473440, 3.204550, 1.682900, -0.569140, -0.167410, 1.002210, 1.362930,
0.996400, -1.444010, -0.450120, 0.233720, -0.994610, -0.655630, 0.878210, -0.198380, 0.737150, -1.217580,
-1.131620, 0.823910, 0.907180, -0.325630, 0.431900, 0.526560, -0.750360, -0.528410, 0.804990, 0.597430,
-0.571930, -0.374210, 1.357070, -0.059660, 1.562060, 0.269100, -2.388590, -0.580010, -0.069050, -1.040600,
-1.670580, 0.394380, -0.936050, -0.729290, 0.613930, 1.984400, 0.917690, 3.094610, 0.604180, -0.576470,
-0.591390, 1.427980, 0.138480, -0.894230, 0.273960, 1.375590, 0.599290, -0.544210, 0.930790, -1.822290,
0.681810, 0.383450, 0.277500, -0.153180, 0.183210, -0.158170, 0.310560, 1.272640, 2.082790, 0.279350,
0.330790, -0.984350, 0.791890, 1.039850, 0.510210, -1.269870, -1.378420, -3.557550, 0.459220, -2.560780,
1.428660, -1.081950, 0.026790, -0.790750, -2.417580, 0.965600, 0.201060, 0.741570, -5.084340, -0.243970,
-1.076630, -0.919220, -3.580920, 1.313570, -2.545310, -1.524250, 0.379420, -0.670500, 0.950820, -1.157450,
-0.991450, 0.506500, 1.321300, -0.416890, 0.752200, -0.967460, -0.241780, -0.964950, -0.928820, 0.339370,
-1.294270, 0.676840, -0.025940, -0.554210, 0.769620, 0.334060, -0.784230, 0.517320, 0.731400, -0.482000,
2.193900, 1.552370, -0.119720, 0.046290, 2.503170, 0.627990, 0.733610, 0.547680, -1.477200, 0.943380,
1.214140, -1.086810, 0.038290, 0.866120, -1.424090, 1.433010, -1.049460, 0.833320, -0.213210, -0.502600,
-0.810500, 0.575690, 0.203720, 0.368800, 1.741690, 0.920150, 0.596080, -0.387020, 0.605900, -1.003630,
0.677660, -0.211460, -0.662640, -0.684840, 0.242020, -0.359000, 0.159140, 1.654180, -0.574910, 1.148990,
-1.109260, -0.034190, 0.309820, -0.996860, 1.317880, -0.847310, 1.097760, 1.034920, -2.298490, -1.438260,
-0.264000, 0.172810, -2.762730, -1.067150, 0.050900, -0.619950, 0.174090, 0.969820, -0.256100, 0.432190,
-1.012350, 0.249140, -0.464000, -0.359930, 0.571040, 3.279640, -0.780430, -0.651430, -3.297700, -0.629330,
-0.270300, -3.322070, -0.432340, 0.354800, -0.883850, -0.234830, -1.779690, -1.900570, 1.384930, -1.743190,
0.121580, 0.699700, 0.827950, 0.148890, -1.224690, 0.295450, 0.135020, -1.501160, -0.405230, -0.461810,
1.793720, -0.885460, 3.457210, -13.524790, -0.626500, -5.155080, -1.016860, -0.878030, -0.498620, -1.115520,
-0.985240, 0.870210, 2.227460, 1.142590, -3.125000, 3.189610, -0.943990, -0.519610, -1.595120, 0.170130,
-0.043250, 0.230640, -1.014270, 0.314920, -0.826980, 0.320070, -0.202920, -0.705240, -0.441290, -0.038610,
0.853990, 1.976870, -1.181680, -0.889640, 2.149820, -0.626000, 0.652720, 0.625710, 0.036960, 0.270070,
-0.300540, -0.982350, 1.939590, -0.864160, 0.012090, -0.158890, -0.608430, -0.135030, 0.027780,
0.591080, 0.514560, 1.029150, 0.860130, 0.035180, -0.696130, -0.626440, 0.072320, -0.539250, -0.495830,
0.773410, -0.070520, 1.695350, -0.857530, -0.433650, 0.520280, -0.611220, 0.648140, 0.536810, 0.421650,
0.611810, 0.759800, 0.894250, 0.483740, -0.734320, -1.091420, 1.000950, -0.586280, 0.388950, 0.851510,
-0.161520, 0.268860, -1.594890, -0.096890, -1.690790, -0.491190, -1.317310, -0.922050, -1.992950, -0.319070,
0.641120, -1.189210, 0.262360, 0.932310, 0.323380, 0.933640, -0.304480, -0.102110, 0.286010, -0.107640,
1.641720, 0.966630, 0.621500, 0.366020, 0.204850, 0.605390, -0.974190, 0.629570, 1.021390, -0.530180,
-1.115710, 0.303700, -0.427540, -0.522850, 0.385500, 1.038190, 0.685360, -0.560020, 1.476560, -0.002870,
0.176460, -3.326490, 0.891930, 1.828410, -1.708760, -0.060200, 0.391720, -0.327500, -0.278260, 0.745840,
-0.233060, 0.838460, 1.403750, 0.850550, -1.546910, -0.280690, 0.847880, 2.258340, -0.779300, -0.841470,
0.253190, 1.106500, -0.134080, 0.336000, -0.399670, 1.369610, 1.256280, 0.147770, -0.064750, -1.098270,
1.012030, -0.698560, 0.583200, 0.246690, 0.164840, -0.536510, 0.732280, -2.065920, 0.139560, 0.779060,
-0.018740, -0.180090, 1.112620, -0.539530, -0.557300, 0.519520, 0.671450, -0.044530, 1.441700, -0.765030,
-1.154640, 1.495490, 1.076590, 0.146160, 1.539930, 0.062390, 0.588840, 1.092720, -0.450270, 0.241240,
0.483790, -0.015470, -0.906910, 0.661370, -0.438160, 0.586220, -0.735990, 0.473460, 0.202300, -0.440790,
0.623530, 0.102520, 0.017210, 0.057180, 0.710900, 0.746630, 0.447490, -1.326630, 0.288450, -1.500610,
0.331280, 1.846840, 1.311060, 0.762880, -0.420230, -0.451600, 1.078590, -0.521060, -0.170580, -0.980510,
-0.600500, -0.424110, 0.647620, 0.172580, 0.452120, 0.049580, 0.490230, -0.210190, -1.241700, -0.620490,
-0.230330, -0.847890, 0.346030, -0.249060, -0.083870, 1.764570, 1.216030, 0.267670, 3.186590, -0.298710,
0.730480, 1.617010, -0.183510, -1.663540, 1.708850, 0.002160, -2.411220, -0.055280, -0.608890, -0.157860,
-1.227820, 0.963570, 0.513200, -0.466430, 0.702200, -0.257280, 1.129390, 0.309610, 0.527870, 0.535150,
1.036960, 0.406620, 1.028180, -0.543740, -0.045210, -0.637260, -1.163610, -1.563800, 0.149270, 0.068760,
-1.506100, -0.027860, 0.200610, 0.228810, 1.308320, -0.769400, -0.453140, 0.515750, 1.385220, 0.815050,
1.789500, 1.776320, -0.701370, 0.450240, 2.361690, -0.002950, 0.309910, -0.953610, 0.319980, -0.363320,
0.286770, -1.559630, 0.170000, 0.326830, 1.208730, 0.002410, 0.586310, -0.237980, -0.436190, -0.795620,
-0.505760, 1.700760, -0.773740, 0.084270, -1.087580, -0.383380, 1.107850, -0.926520, -1.352000, -1.104620,
-2.085960, -0.559290, -0.368690, 7.008040, -0.347240, 1.865860, 0.027010, 0.872240, -1.029690, 4.321500,
1.209250, -0.199050, -0.222370, -0.002300, 2.283200, -2.323970, 0.277180, -0.556610, -1.146950, -1.076840,
-1.130570, -9.059620, -2.418470, -2.320100, -0.325840, -1.438610, -2.763410, -3.451370, -1.749930, 1.208650,
-0.812390, -5.230080, -0.341130, -0.286650, 5.017280, -1.921500, -1.318240, 0.054410, -0.443650, -3.163340,
-2.198540, 0.255290, -3.433850, -2.157940, -2.211150, -2.309650, -0.729070, -3.739590, -1.866130,
2.171430, 0.393530, 0.415970, -0.436310, 1.637940, 1.057590, -0.222440, 1.808240, -1.253560, -0.073640,
0.779180, 0.603760, 1.444870, -0.176170, -0.626800, -1.261410, -0.893440, 0.611240, 1.704770, 2.890770,
-0.872930, -0.422620, -0.720590, 0.217570, -0.182230, -0.731480, 1.359900, 1.716380, 0.954100, -1.392800,
-0.521090, 0.222010, 1.201920, 0.073000, 3.605550, -1.850370, 0.573020, 0.870750, -1.848430, 0.463140,
0.830430, 2.023200, 0.186030, -0.489380, -0.335340, 0.640500, 1.864970, -1.316570, 1.864100, -1.164290,
0.154720, 0.294390, -1.334210, 1.529170, 1.781590, -0.515000, -0.015310, 0.041030, 1.076290, -1.043730,
-1.398840, -3.129170, -0.051680, 1.417530, 1.481440, -0.207100, 2.341020, 0.424930, -0.049140, 0.944720,
0.056640, -0.542600, -0.177930, -1.524690, 0.333850, 0.454550, -0.038600, -0.514250, 0.685150, -2.993530,
2.246210, -1.060660, 0.951010, 3.133170, 1.193760, -2.378810, -0.952630, -0.628010, -3.089120, 0.975620,
0.410730, 0.183440, 0.543440, 1.829670, 0.252340, -1.137620, 0.669170, 0.694740, 1.120890, -0.363330,
0.018230, -0.032840, -1.915010, -1.535770, -0.848650, 0.242030, 1.480430, 0.692700, -1.909340, 0.909160,
1.164640, 0.207630, 0.140720, 0.635990, 0.711460, 0.857510, 1.957880, 0.047750, -0.723890, 2.027800,
1.025570, -1.908360, -0.553680, 0.714300, 0.465350, -0.813100, -0.498440, -0.737350, 1.158830, -0.502400,
1.019510, -0.911580, -0.215740, -1.257150, -2.306150, 6.048280, -0.357660, -0.124440, -1.299050, 0.445030,
-0.457580, 1.198900, 0.587420, -1.597550, 0.014880, 0.678220, -0.950500, -0.396610, -1.434840, 1.375720,
-0.496790, 1.095810, -1.718460, 0.271880, -0.407190, -1.481140, -0.806500, -2.544540, 0.076470, 0.387940,
-0.268250, 1.880990, 4.362400, -0.212540, -0.377280, -0.324820, 1.610860, -1.017680, 4.153580, 3.122220,
1.923110, -2.633630, 0.647960, -0.169950, 2.575070, 0.242600, -1.260090, 0.228620, 0.927890, -0.632870,
0.702400, 0.876770, -2.169370, 0.038350, -0.087990, 2.630140, 1.874290, -0.979500, -0.742340, -1.502560,
-0.670280, 0.523120, 1.602180, 3.777800, 0.148970, -4.145860, -0.768300, 1.893100, 1.715600, -2.906450,
-0.885700, 3.021840, -6.745710, -3.058830, 0.155760, -2.853970, -0.519560, -2.122150, 0.983830, 0.267960,
-1.361450, 1.552230, 0.591680, 0.066500, 0.094940, 0.851360, 0.370950, 1.839510, -0.196030, -0.568640,
-0.548430, 0.359990, 0.107610, 0.544670, 0.005580, 1.248320, 3.321060, 0.469680, 1.132320, -0.568430,
1.073870, -1.256830, -0.665250, -1.162810, -1.359630, 0.908170, -0.477080, 0.090710, 0.826870, -0.542940,
0.596320, -0.149180, 0.445020, -6.257970, 0.548070, 0.455540, 0.087340, 0.734160, 0.766830, -0.418690,
-1.010680, 0.353120, 2.161390, 0.138940, 0.119110, 1.341870, -0.904300, -1.692960, 1.078670, 0.764900,
-0.192320, 0.246850, -2.380070, -1.312380, 1.008090, 0.512110, -0.107190, -0.426240, 0.525670, 0.928200,
-0.642510, -0.674610, -0.696980, -0.481030, -0.543530, 0.520230, 0.775550, -0.196800, -0.608480, 6.953680,
-0.100810, -0.461400, -0.087550, 0.854770, -0.735340, -0.984680, -0.716150, 0.693190, -0.882250, -0.154350,
0.427300, -0.517920, -4.665970, 0.055720, 0.525020, 0.457560, -0.045480, -0.281930, -0.816500,
1.745460, 0.470500, 0.399600, 0.436680, 1.671770, 0.342970, 1.162210, -2.130760, 0.274640, 0.269640,
0.006880, -0.925370, 0.130540, -0.707040, 0.744940, 1.158500, -0.458650, 0.780900, 1.654440, -0.814910,
-0.655390, -0.593210, 1.136740, 0.125900, -0.043410, -1.804170, 0.611170, -0.001070, 0.005830, -1.051830,
-0.275400, -0.810740, -0.370800, 1.272120, 0.545480, 0.546020, 0.324890, 0.543240, -0.674550, -0.694890,
-0.726150, 0.905960, 1.764590, -0.430360, 0.320260, 0.073520, -0.725170, -1.120110, -0.904850, 1.248970,
-1.105970, 0.283010, 0.353850, 1.579670, -0.260270, 0.022730, 1.062910, 0.334370, -0.610640, -1.589800,
-0.862860, 0.645980, 1.281890, -0.547080, 0.114230, -0.629280, 0.045020, -0.626110, 0.348360, -1.732590,
-0.918580, -0.647690, 0.015940, -0.555380, -0.569140, -0.092680, -2.368420, -1.386870, 0.690540, 1.266870,
0.234190, -0.579310, -0.339450, -0.309240, 1.224730, 0.897420, -1.724810, 0.191240, 0.351270, 0.750790,
-0.722240, 0.325100, -2.064000, 2.143750, -0.369940, 0.115560, 2.366050, -0.476340, 0.588170, -1.504410,
-0.121190, -0.563170, 0.894440, -0.410010, -0.942980, -0.084640, 0.026580, 0.593700, 3.036950, 1.483820,
-0.231560, 0.185980, 0.700550, -1.721160, -0.547810, 0.834390, -1.403750, -0.168450, 0.430940, -1.453350,
0.032210, -1.098640, -1.019550, 0.691300, 0.013190, -0.332530, -0.882800, -0.414530, -0.310690, 0.027460,
-1.710320, 1.096130, -3.248660, 0.262980, 0.182860, -1.332510, 0.000200, -0.738160, -0.137890, -0.410520,
-0.834480, 1.047960, 0.296550, -0.224830, 0.967440, 0.876280, 1.475440, -0.023310, -0.695350, -0.263720,
0.047610, 0.671230, 0.459890, -0.494060, 0.141710, 0.119500, -0.174890, -0.701140, -0.476160, 0.199130,
0.398680, 0.844110, 0.318320, -0.634360, -1.788830, 1.008430, 0.758940, 2.132320, 0.212220, 0.839260,
0.023160, -0.949070, -0.457290, -1.064330, 0.199830, -1.142990, -0.112620, -2.296370, -0.492750, -2.763050,
0.701350, 0.118590, 0.476320, -1.155110, 0.508510, 1.162010, -0.012200, 0.145220, 0.557660, -0.975400,
0.743950, -0.851360, 0.012220, -0.235540, -0.345530, -0.104000, -0.569110, 0.430010, 0.366160, -3.324250,
-0.860270, 0.343440, -0.834670, 0.145200, -1.088620, -2.243520, -0.674930, 0.353320, -0.540330, 0.489560,
0.126750, 1.010490, -0.087840, 0.127670, 0.965010, 1.990440, -0.312800, -0.488400, 0.365060, -0.552640,
1.522630, -0.088820, 0.500550, 0.133310, 0.235270, 1.973350, 1.357820, -0.301070, -0.958730, -0.215490,
-0.929790, 1.908690, -0.295640, -0.828420, -0.264020, -0.438110, 0.198610, -0.445840, 0.553940, 0.162570,
0.966880, -1.018660, 0.021710, 1.954630, -0.365350, 1.349960, 0.246350, -0.453420, 0.304730, 0.380620,
-1.153020, -1.123130, 1.192000, -10.120450, 0.388290, -2.341540, -0.566910, -0.070030, 1.373530, 0.330940,
2.424160, 1.337500, 0.349690, 0.100800, 0.528770, -1.165520, 0.549620, 0.022770, 1.057010, -0.948710,
-3.362310, -3.528400, -3.038550, -0.827970, -4.845300, -0.470390, -1.669250, -7.305600, -1.230800, 4.630180,
-2.624550, -0.735190, -4.606720, -9.644330, 2.746690, -1.802930, -3.333470, -1.463040, -2.193480, -1.028910,
-0.363910, -2.391380, 3.240290, -1.587620, 0.092200, -1.078830, -3.250650, -0.541620, -0.638370,
-0.797750, -0.647880, 0.556650, 0.940290, 0.819210, -0.534140, 1.399060, -3.244940, 0.897330, 2.664400,
1.401320, 0.904460, 0.769020, 0.240430, 1.416290, -1.095340, 0.651380, 0.964830, 0.638180, 0.132460,
0.573790, -0.307960, -1.545610, -0.413200, -0.712090, 0.240560, 0.414610, 0.735130, -0.404930, 0.279210,
0.432210, 0.274320, 0.179120, -0.623090, 0.401360, 0.175180, -2.804070, 0.344530, 1.477650, -0.433920,
0.377880, -1.020930, -0.399940, 1.036570, -0.680310, -0.516760, -0.568710, 0.687520, 0.772310, 1.450030,
1.788930, -0.703890, 0.183000, -2.073550, -0.019860, -1.284870, 0.043280, -0.686740, 0.782970, -0.690990,
0.181690, -0.417770, 0.636970, 1.204530, 0.980520, -0.057630, -0.547290, 0.963930, 0.392250, -0.327490,
0.776880, 1.007470, -0.987110, 0.317520, 0.783170, 1.394930, 1.127220, 0.333310, -0.826210, -1.057570,
0.814750, 0.864850, 1.158140, 0.172180, 0.493450, -0.489470, 0.171760, 0.347650, -0.480120, 1.220020,
0.757850, 0.513410, 0.357080, 0.432070, 0.800500, 0.809300, -0.067750, -0.666630, 0.866090, -0.427470,
1.104470, -1.630620, 0.591310, -0.589300, 0.564910, -0.044180, -2.028040, -0.160620, 0.613410, 0.720350,
0.035460, 1.509100, 0.986820, 0.210030, -0.581690, 2.994390, -0.187380, 1.593960, -2.802530, 4.319360,
0.464670, -8.801390, -0.561430, 5.835000, 3.220280, -2.320550, -0.639140, -1.730450, 3.001090, 1.008820,
-1.003140, -0.216130, 8.646000, -0.641430, -1.098650, 0.515070, -0.934370, -0.542320, 0.786420, 0.031270,
-0.114000, -3.151470, 0.450540, -0.514750, -0.075520, 0.741860, 0.051910, -0.107600, 1.064680, -0.395930,
0.419150, 2.380580, 0.798870, 1.210170, -0.098100, 0.340990, -0.318520, -0.742920, 1.182260, 0.003180,
-0.100920, -1.143410, 1.740410, -1.739490, -3.804610, -0.501480, -0.379210, -0.678670, 1.956870, -4.676910,
-2.218760, 0.760990, 1.328780, -0.465200, -0.640590, -0.801810, -0.614500, -0.458880, 0.240440, 0.709250,
1.719950, 0.167220, 2.564360, -0.574410, -3.574470, 1.045490, -2.004080, 2.009580, -0.481890, -0.729770,
0.382120, -0.705300, -2.032300, -1.211680, 0.680020, 0.236210, -0.350350, 0.665500, 2.376250, 2.131900,
-0.980500, -0.376320, -0.215620, -1.081360, 0.208550, 2.639230, 0.656820, -0.467630, 0.987380, 0.280430,
-0.525960, 0.099640, 2.274600, 0.111300, 0.957380, 1.017410, 2.498060, -0.966840, 0.041550, 1.040050,
-1.500760, -1.202500, 0.059060, 0.030880, 1.177520, -1.784730, -0.082240, 0.766770, -0.828340, 0.900600,
-1.228650, -1.241210, 0.607430, 0.449020, 0.075330, 1.335840, 0.754290, 0.862220, 1.132690, 0.145390,
0.364690, -1.899440, 0.586270, -1.086690, -0.701060, -0.480330, -0.917920, -1.832150, -1.728120, 0.124910,
-0.842370, -0.449510, 0.296800, 22.478149, -0.051470, 0.991280, -0.205840, -0.816430, 0.350030, 0.230280,
-0.385260, 0.465940, -7.679520, -0.199140, 0.488370, 0.471210, 0.214560, -0.845310, 1.360190, -0.867140,
-0.114660, 0.638430, 1.312440, 0.892270, 0.429270, -0.273140, -0.356040, -0.504220, -0.542860, 0.086270,
0.940340, 0.353890, 0.746890, 0.581550, -0.703110, -0.720760, -0.662080, -0.063390, -0.981420, -0.403170,
-0.430850, -0.197650, -0.262210, 0.749710, -0.344540, -1.423010, -0.533490, -0.399210, 0.891220,
0.142550, -0.222430, 1.066070, -0.798890, 0.706630, -0.585190, -1.123950, -0.147030, -1.277720, -0.006530,
0.586290, -1.045710, 2.111280, -2.303410, 0.365370, -0.457330, -0.492220, 2.007870, -0.137260, 0.415130,
-0.151470, 0.828400, -0.922660, -0.020490, 0.263940, -0.092750, -0.317490, -0.393860, -0.080770, 0.610610,
-1.684620, -0.097290, 3.578610, -3.364140, 0.414240, 0.109830, 0.799880, 0.046910, -2.861350, -1.460290,
2.707370, 0.020460, 1.400000, -0.754240, 0.728330, -0.333700, -0.503850, -0.019050, -0.338170, 0.366060,
0.620560, 0.701030, 0.598800, -1.411930, 0.776970, 0.093790, 0.280810, 0.001540, -1.615910, -0.842360,
0.077870, 1.427210, -0.600850, 2.176370, -0.084020, 0.097910, 0.063220, -0.887880, 0.476060, 1.550470,
0.579140, -1.383510, 0.658660, -1.424180, 0.045000, -0.388740, -1.873140, 2.587500, -0.479060, 0.851380,
-0.662110, -0.086160, -1.243250, -0.117630, 1.036190, 0.556200, 1.429770, -0.984430, 0.385020, -0.332570,
0.214310, 0.370130, -1.069590, 2.167350, 1.555360, -1.175070, 0.420950, 0.383640, 1.513090, -0.121230,
0.051790, -0.350270, -0.119830, -0.243910, -0.483950, 0.215010, 0.261060, -1.217410, -0.703930, 1.666860,
0.324920, -0.882260, -1.841180, -0.402400, -0.933580, 2.960340, 11.306750, -0.239240, -0.650910, 1.617380,
0.936860, -1.491310, -0.020980, 1.967160, 2.375200, 0.058950, 0.194060, -0.652930, 1.772480, 0.013120,
-3.473360, -0.822680, 3.618120, 0.083690, -1.437630, 14.158090, 1.073260, -0.003140, 0.051550, -0.770310,
0.141670, -2.002750, -2.311060, -0.421420, 0.024090, -0.312940, 2.031280, 2.444060, -1.166300, 0.982220,
-1.183200, 0.086750, -0.690550, -0.310200, -0.571700, -0.180610, 0.413290, 0.929560, -2.195050, -0.708100,
-0.437780, 0.138630, 3.401730, -0.245910, -2.477410, 0.785900, 0.037910, 0.228170, 0.548470, -0.304210,
1.168170, -0.486740, 0.964820, -1.008700, 1.112550, -0.845360, 0.165720, -0.151960, 2.958250, -1.202650,
0.412700, -0.178940, 1.920620, 1.613360, -0.049470, 1.937720, 0.290770, -1.184250, 1.320530, 1.625890,
0.009070, 0.774230, 0.604900, 0.197200, 0.249360, 0.499440, 0.416870, 0.278280, 1.956010, 0.197510,
-0.970740, 2.067240, 1.807450, -1.266810, 0.445210, -0.884580, -0.874860, -0.021670, -0.401590, 0.944190,
0.652300, 1.833150, 2.195110, 0.206050, 0.123350, 0.544750, 1.089370, 1.268840, 0.631100, -1.134480,
1.907360, -0.773890, 0.309530, 0.735460, -1.882550, 1.014660, -0.817310, 0.317120, -0.096060, 0.471960,
-0.594070, 0.530840, 0.383700, 1.174140, -0.554660, 0.071900, 0.725390, 0.203790, 1.391640, 2.229870,
1.806380, -0.518190, 0.030860, -0.840860, -1.075210, 0.211040, 0.217690, 0.536950, -2.626570, -2.186340,
0.343280, -0.573430, -0.903800, -0.618610, 0.711720, 0.377950, -0.332360, -0.878760, -0.506420, 0.901070,
0.245520, -0.555970, -3.107950, 1.179690, -0.225800, -0.495260, 0.486920, 0.954660, -0.500550, 0.739140,
0.061200, -0.770200, -0.210880, -0.249890, 0.596320, -0.662830, -0.518580, -0.260990, -0.799000, 2.657690,
0.286910, -1.632000, -0.180850, -0.459100, -0.071460, -0.862060, 1.224470, -1.174460, -0.861800, 0.640870,
-0.539180, 0.203620, -3.403640, -0.232820, 0.608100, 0.332180, 0.848760, 0.841550, -0.351360,
1.265710, 0.768000, -0.539590, 0.606810, 0.387390, -0.425130, 0.357800, -1.466880, 0.260860, -0.467410,
1.673190, 1.141090, -0.317800, 0.352420, 0.099960, 0.388380, 1.596940, 0.193690, -0.940490, 0.249680,
-0.654550, 1.178750, 0.302540, -0.212540, -0.204950, -0.221710, 0.169040, 1.083610, -0.010620, -0.456610,
0.585930, -0.396830, 0.051780, 0.161920, 0.688230, -1.680990, -0.330380, 0.820650, -0.324860, -2.173280,
-0.160570, 0.260030, -0.791520, -0.773880, 0.280400, -2.957820, -1.017540, -0.201510, 0.349620, 1.371380,
0.312000, -0.820730, 0.790540, 1.359910, -1.027770, 0.359690, -0.287510, 0.294610, 0.084960, -2.547380,
0.761490, -0.071280, 0.240300, 0.652110, 0.755600, -0.006400, 0.611290, -2.337920, -1.484430, -1.271920,
0.999790, -0.182560, 0.516410, 0.328970, 1.620060, -0.298260, -1.663490, 0.659990, 0.834820, -0.180170,
-0.639130, -0.678500, -0.027770, -1.021200, -0.159600, -0.252850, -0.884420, -0.340160, 0.429570, 1.198490,
-1.073440, 0.508190, 0.760600, 1.680200, 0.752430, 0.599350, 1.559490, -0.738940, -0.063730, 0.956740,
-0.193340, 1.359790, 0.206830, -0.710610, 0.399870, -0.069620, 0.186650, 1.369020, 0.117380, -0.583470,
-0.228240, -0.121090, 0.625330, -0.155460, -1.359570, 0.510100, -0.209950, -1.794360, 3.571150, -1.785620,
0.298180, 0.428110, -1.435560, 0.949140, -1.601320, 0.566640, 0.395710, 0.189820, 0.383410, -0.172280,
-1.730530, 0.300340, -0.018960, -0.690690, -1.180050, 0.102600, -1.000000, -1.151480, 0.020740, -0.700390,
0.734160, 1.246610, 1.303370, -0.371210, -0.100770, 0.770100, 0.763980, 1.829640, -1.109200, 0.989210,
0.237840, 0.473620, -0.183480, 0.546900, -1.175450, 1.619630, 0.359360, 1.012790, 0.705210, 0.351790,
-0.374610, -0.612780, 0.222360, -0.117860, 0.503300, 0.376750, 0.314670, 0.778740, -0.796450, -0.642440,
0.192680, 1.790610, 0.430160, 0.092860, -0.079400, 1.334850, 0.231840, 1.748260, 0.376330, -0.022850,
-2.154240, -0.467220, 0.454000, -0.365740, 0.364080, -0.073980, -0.874320, -0.013590, 0.870480, -0.243240,
-0.289290, -1.153500, -0.625330, 0.960890, 1.291450, 0.685700, 0.262810, -0.346260, 0.538070, -0.700000,
-0.088240, -0.991840, -0.291440, 0.693860, -0.434340, 1.168340, -1.262990, 0.791980, 0.779520, -0.690270,
0.294850, 0.496910, -0.832600, -0.325610, 0.565680, -0.196400, 0.073500, 0.597200, -0.079210, 0.504840,
1.032860, 0.677450, -0.101890, 0.533330, 0.290820, -0.374360, -0.982420, 0.366640, -0.584330, 1.196360,
-0.686080, -0.088600, 0.220400, -1.091450, -0.067040, 0.493230, 0.291690, 0.654230, 0.629460, -0.663920,
0.345130, -0.215720, -0.454980, 0.186080, 0.541290, 1.253740, 0.049110, -0.071600, 0.241410, -0.251130,
-0.608170, 1.049220, 1.048680, -10.515250, -0.423780, 1.114750, -0.307750, 0.953560, -1.001050, -1.647600,
-0.774240, -3.099110, 0.915710, -0.531050, 1.290080, 1.761740, -1.406710, 0.947340, 0.599030, -0.349280,
-1.082260, -5.418520, -0.824580, -2.136250, -0.478150, -0.279290, -3.750930, -2.240270, -0.447450, -2.089760,
-1.222830, 0.078090, -2.697180, -1.504670, 1.885130, -1.257860, -1.433280, -0.467410, -0.682680, -1.463860,
-0.907720, -0.945530, 0.678640, -0.893030, -1.363270, -0.086180, -2.446050, -0.710430, -0.837680,
1.021710, 0.762360, 0.586470, 1.848830, -0.005640, 1.041570, -0.991730, -0.123550, -0.334300, 0.536780,
1.902150, 1.196410, 0.683640, 0.565530, 0.714500, 0.195380, -0.969320, -2.850650, 0.459460, -0.122320,
-0.490350, -1.028720, 0.187580, 0.974930, -1.278110, -1.421770, 1.746850, -1.320140, -0.319180, 0.120360,
-0.416580, 1.058750, -2.032500, -0.084690, -0.910360, 0.393050, 0.012290, -0.050500, -1.626720, -0.098530,
-1.120750, 1.491370, -1.443150, -0.173820, -0.544880, 0.152030, -1.507970, 0.672760, -0.016910, -0.344090,
0.792080, 0.299880, -1.492710, -0.365510, -1.671900, -0.686830, -0.548500, -1.175140, -0.105750, 0.449100,
0.277350, -0.467110, -0.316410, -0.653660, -0.405560, 0.072800, -1.266700, 2.682670, -0.419220, 0.668100,
-0.550190, -0.090050, 0.317360, -0.568090, -0.455570, -0.611340, 1.438120, 0.068410, 2.176710, -1.454460,
0.710960, 0.607360, -1.271140, -0.412550, 0.255230, -1.443120, 0.673980, -1.224530, -0.821680, -1.419380,
1.509930, 1.070700, -0.355130, -1.108370, 0.075300, 0.590000, -0.339980, -1.319570, -0.751170, -0.931660,
-0.441550, 0.435170, -0.747920, -1.703860, 0.876840, -1.536460, -0.418580, -0.828440, 0.749500, 1.508610,
0.186550, 0.104570, -0.836460, 0.608300, 0.860890, -0.517870, -3.042260, -0.250620, -3.689840, -1.157420,
-2.098500, 0.713520, -2.764690, -1.369820, -1.877160, 0.623200, 3.248860, 1.174560, -3.350790, 0.728130,
1.700610, 1.070940, -2.889570, 1.618480, 0.352150, -1.649320, 0.218500, 1.305780, 0.004550, 0.640180,
0.518580, -0.728740, 0.170520, 0.525190, -0.008050, 1.766610, -0.282630, -1.130290, -0.169760, 0.738930,
0.147930, -0.557080, -0.453360, -0.022280, 0.467930, 1.926630, -0.165740, 0.136840, -0.700800, 0.189490,
0.122490, 0.260620, -1.419790, 2.326710, -0.051290, 0.118540, -0.245310, 0.504360, 0.140450, 0.779520,
0.983040, -0.534910, -0.822800, 1.022250, 0.899470, -0.673510, 1.499770, 1.129830, 0.959450, -0.572730,
0.525180, 0.681350, -0.760480, -0.050110, 0.097060, -1.615170, 1.055400, -1.573580, -1.221940, 0.137390,
1.447170, -2.017970, 1.060620, 0.077090, 0.325250, -0.581350, 0.905650, 0.692970, 1.124470, 0.949040,
1.295510, -0.576740, 1.270840, 1.717400, -1.029260, -1.671640, 1.571960, -0.089180, -0.139440, 0.971450,
0.212200, 0.051610, 2.525800, -0.442190, -0.517080, 0.231190, 0.151070, -0.545480, -0.279380, 1.296750,
3.169290, 0.818840, 0.482120, -0.323480, -0.605740, 3.029380, 0.336900, 0.350430, -0.270400, 0.589770,
-0.342420, 0.636940, 0.678530, 3.957160, 1.170400, 1.075230, 0.170050, 0.724750, 0.676700, 0.523790,
-0.209240, -0.245970, 0.165480, 1.611940, 1.000330, 0.785550, -1.899930, 1.132100, -0.700950, -1.424190,
0.197930, -1.048250, -0.645070, 9.620180, 0.473380, -1.180350, 0.340160, 1.728310, 1.050300, -0.174720,
0.664060, -0.456970, 2.343120, 1.041790, 0.751890, 1.043280, -0.206490, -0.606680, 0.250210, 0.009400,
-0.232690, -2.197650, 0.329940, -0.038340, 0.395110, -0.802840, -0.087490, 0.846810, 0.755730, -0.752690,
-0.681100, -2.682820, -0.437930, -0.802430, 0.672470, 0.164090, 0.483660, 0.931080, -0.438450, -0.687310,
-0.883550, 0.327700, -0.398970, -0.925430, 0.758650, -0.913480, -0.156330, 0.162320, -0.472280,
0.557550, 2.260780, -0.120990, -0.965440, -1.569820, -1.176390, 0.936240, 0.921210, -1.416390, 1.467650,
0.190870, 1.331010, -0.455730, -4.713870, 1.204500, 0.315620, 2.321500, -1.763980, 0.058250, -0.692700,
-1.692550, 0.086300, 0.889560, 0.151540, 0.593180, 1.161950, 0.602080, 0.289910, -0.505370, -1.335310,
0.491550, 2.164900, 2.670010, 0.449470, 0.784380, -0.955970, 1.383350, -0.593770, -0.566390, 0.724780,
3.545920, 1.179030, 1.218070, -0.341540, -0.449930, -3.861780, -2.478450, -0.772890, 0.549910, 0.210700,
0.512880, 0.122880, 1.603540, -0.040030, -0.745310, 0.505350, 0.531380, -1.364640, -0.606240, -0.042260,
1.579710, -1.278870, -0.267070, 0.404270, 0.934130, -0.224040, -1.077550, -0.923540, -2.952060, -1.316730,
1.024190, -0.215660, -0.216150, -0.131040, 1.280650, -0.721940, -0.752640, 1.048350, 0.107550, -0.538570,
0.394730, 0.191260, 1.082510, 1.277530, -1.080700, 0.025750, 1.712050, 0.744310, 0.277270, 0.504460,
0.811820, -0.221130, -2.703180, 2.737490, -1.517190, 2.217170, 0.132240, 1.919390, 1.677230, -1.225390,
0.316620, 0.050170, -3.072950, 0.185620, 1.048800, 1.026240, -1.081120, -0.362140, -1.626780, 1.667400,
-1.967940, 0.512680, -2.171610, 0.068830, -1.210570, -0.009650, 1.098120, -0.759150, -3.785570, 1.049440,
0.841780, -0.875480, -0.500230, 0.680260, 1.040770, 0.346610, 0.097810, -1.881550, 2.931330, -1.016400,
-1.546780, -1.972580, 3.727860, 0.182590, -0.591920, 6.697660, 1.229340, -1.998470, -0.145210, 2.550630,
1.454720, 0.684010, 1.505440, 2.048710, -2.614810, 0.201510, 1.713140, 2.719230, -1.012170, 0.478890,
1.196840, 5.530650, 2.115290, -1.026390, -0.762630, 3.075230, 1.029950, -0.068790, 0.126970, 1.097010,
-3.616720, -0.462370, 2.396810, 0.193590, 0.380810, 0.382130, -0.618060, 0.541330, 0.574830, 0.319430,
-0.750030, -1.148600, 1.018120, 0.476200, -1.952040, -0.399650, 0.523480, -0.903970, 1.009480, -0.177910,
-0.740140, -0.872020, -0.408920, -0.208460, 0.868620, 1.967520, 3.649470, -0.519960, 1.431420, -0.567460,
-0.559730, 1.254830, 0.891120, -1.352230, 0.004990, 1.262400, -0.063800, 0.374530, -1.239890, 0.914340,
-0.027450, 0.945520, -0.717810, 0.764710, 0.369530, 2.740290, -2.226410, 1.996460, 4.106910, 0.105060,
0.350950, -2.491460, 0.473330, 0.177660, 0.115450, 2.510030, 2.840850, 0.033580, -0.468570, -0.390730,
-1.147670, -0.039390, -0.372710, -1.946350, 2.929990, -0.951870, -2.258120, 0.752710, -1.037650, -1.171010,
-1.666540, 0.239110, 1.344090, 0.926410, -0.668060, -0.683210, -1.219520, 0.953480, 0.616820, -1.288720,
1.371870, 1.359420, -1.438540, -0.751670, -1.522680, -2.265390, -0.512070, 1.122960, 0.470400, -2.466300,
-0.293450, 0.720620, -0.201030, 6.237470, -0.669030, 0.436460, 0.994860, 0.819090, -0.057800, -3.408240,
-0.126180, -0.524500, 0.763160, -0.831520, -0.183410, 1.673690, 0.250730, -0.318780, 0.762510, -1.091510,
0.500660, 4.761450, 1.222070, -0.706270, 0.941310, -0.563590, 0.196350, -0.410600, 0.456160, 4.673030,
-0.828550, -0.137290, 0.503270, 0.731690, 2.167470, -0.122960, 0.551970, -0.728000, 0.290190, -0.483480,
1.001060, 1.680450, -1.641390, -0.927440, 0.813130, -0.430130, 0.863960, 0.809940, -0.090690,
0.142090, 1.136120, 1.562750, 0.839690, 0.539660, 0.732040, -2.091590, 1.283670, 1.649850, -1.298450,
-0.752650, 0.258780, 1.518120, 0.151800, -0.340830, 1.531480, 0.573270, 1.388100, -0.388290, -0.348950,
1.522350, -1.362700, 2.181170, -0.759570, 1.222660, -0.174830, -0.303120, -0.095820, -0.092040, 0.039180,
1.084870, -0.612060, -0.868450, -1.240120, -1.800950, 0.885830, -0.464500, 1.001380, -1.158810, 0.766170,
-0.819360, -0.271490, -0.715930, 2.334610, 0.742910, 0.162210, 0.689360, -0.526510, 1.320660, 1.699530,
0.532510, 0.965340, 1.576240, 0.412510, 1.172700, 0.649120, -0.367330, 1.327940, 0.463500, 2.667030,
-0.792560, -1.167840, -1.633500, -0.776720, -0.912390, 1.205820, 0.690090, 1.266210, 2.325920, -0.930750,
0.233310, 1.025240, -1.011270, 0.559350, -1.515510, 0.610420, -0.113210, 0.045360, -0.003570, 0.563230,
-0.216990, 1.654200, -0.387350, 0.839030, 1.100270, 0.625070, 0.432050, -0.691400, -1.169060, 2.111650,
-1.385650, 0.284470, -0.293040, 0.377730, -0.208740, 2.192250, -0.564510, 0.557830, 0.437570, -0.062120,
1.099650, 1.334950, 1.132500, -0.193190, 0.365650, -0.707460, 1.057420, -0.270990, -1.833820, 0.331220,
1.300300, -1.386450, 1.438800, -1.772350, 3.331660, -0.164650, -1.715120, -0.358720, -0.670390, 0.040390,
-2.039580, -4.599480, -0.695050, 0.804910, -1.390240, -0.437120, 1.039310, 0.703850, -0.823560, 0.364260,
1.319180, -0.143360, -0.903270, -0.143590, 1.389790, -1.284780, -0.526610, 1.177130, 0.018040, 1.980920,
-0.063200, 2.209550, -0.619300, -0.377200, 0.776430, -0.314820, -1.623670, -0.889220, -2.094770, 2.160720,
1.117410, 0.115800, -1.439390, 0.874400, 1.083280, -1.443530, 0.087770, -0.095860, 0.974990, 1.191900,
1.566190, 1.567260, 1.412570, 0.907350, 1.119340, 0.473360, -1.249000, 0.502640, 1.307140, 3.508490,
0.241570, -0.327470, 0.433870, 0.819590, 0.632320, 1.840410, 0.304430, -1.418950, 0.521540, -1.387020,
0.211840, -0.022970, -4.198850, 0.154050, 1.205820, -0.733390, 0.382190, -0.213060, 0.572310, 1.236740,
0.354330, 2.363360, -0.503540, 0.484090, -0.535100, -1.217670, -0.302780, 1.740410, 0.558610, -0.409790,
-1.550330, 0.922860, -1.834500, -1.723120, 3.506000, 0.111940, -1.625330, -1.371900, -1.166300, 0.103470,
0.607160, 0.692210, -1.148970, 1.309390, 0.936530, -0.018320, 1.575370, -0.177110, 0.482900, 1.152790,
0.887550, 0.868670, 1.874090, 0.648550, -0.162680, 2.967220, 0.335670, 0.541310, -1.553650, -0.097500,
0.625590, -1.239950, 0.914830, 1.947030, -1.442770, 0.679500, -0.315140, 0.769140, -0.947090, -0.450070,
0.306770, 0.656570, 1.773470, 0.309330, -0.568340, -0.675000, -0.012510, -2.230840, -0.219520, -1.348380,
0.440280, 0.646270, 1.765250, 2.819770, 0.770550, 1.090600, 0.022820, -0.390520, -0.750580, 0.316020,
2.009500, 0.782620, -0.206860, 0.871420, -2.986840, 0.373820, 0.166760, 0.578610, 0.392280, -2.549390,
-1.094530, -1.169710, -4.223060, -0.458980, -0.675020, 0.585050, -1.010770, -1.692180, -0.263460, -1.045840,
-0.785470, -5.483600, -1.545010, -1.485120, -1.344180, -0.393240, 0.092980, 0.606630, 0.381520, -1.303170,
0.212230, -0.820940, -0.302530, -1.646270, -0.173490, -0.228180, -1.370390, -0.169580, -0.698190,
0.796960, -0.390570, -0.313920, -0.035150, 2.669680, 0.724380, 1.900970, 1.688460, 1.286060, 0.803780,
-0.546930, 1.189130, -1.808730, 0.023820, -0.542940, -0.471080, -1.101930, -0.320890, 1.503290, -0.492010,
-0.762650, 0.595330, -0.676700, -0.464700, -0.701010, 0.093060, 1.000180, 0.052390, 0.867850, 0.808820,
-0.661460, 0.584170, 1.983790, 2.073640, -0.078070, 1.951570, 0.100780, 1.076740, 1.021070, 0.571030,
0.430050, 0.640810, 0.113540, -0.236380, 1.378680, 1.126870, 3.162470, 0.239170, 0.305500, -0.103080,
1.456950, 1.980450, 1.858240, -0.111960, 2.073710, -0.194600, 0.690970, 0.366260, 0.204150, -1.001540,
-1.006780, -0.458680, -1.338610, 1.906870, -0.761950, -0.887180, 1.300360, -2.590230, 0.400940, -1.254820,
0.600900, 2.315760, 0.096180, 2.483010, 0.976460, 0.312720, 0.407050, 0.103040, 3.418610, 0.030650,
1.408620, 0.949650, -1.019120, -2.059750, 1.233000, 1.256160, 1.253530, -0.804380, 0.184940, 1.895640,
-2.192870, -0.583300, 0.783000, 0.084670, 0.615310, 0.133430, 0.403800, 1.187940, 0.676280, 7.299620,
0.934420, -0.200420, 0.513530, -0.590460, 0.949490, -0.843410, 0.351830, 0.126440, 0.965690, -0.676170,
0.495110, 1.073810, 0.589880, -0.441230, 1.458770, 1.360140, 0.090650, 1.463880, -2.440150, 3.212060,
1.391650, 0.776090, 2.474820, -0.217050, 0.750760, -0.461220, 0.347530, 1.966230, -1.050420, 0.204690,
1.205940, -0.135780, -1.784600, 0.068510, 0.870910, -0.735260, -1.051090, 0.379360, -1.137810, 6.335470,
-0.103880, -0.055780, 0.855140, 0.322760, 0.506960, 1.092430, -0.150860, 0.579030, -2.584990, 1.015780,
1.408210, 1.742980, 1.378650, 1.754610, -0.134630, -0.894300, 0.438450, 0.333730, 0.446410, 0.587140,
0.068390, 0.972460, 0.247910, 2.275330, 1.754820, 2.099440, 1.987390, 1.019130, 3.300470, 2.147670,
2.687250, -0.226270, -0.879840, -0.173610, 0.685280, 0.749350, 0.949430, 0.298600, 1.842210, -1.527920,
1.362290, -1.780930, -1.422060, -0.877630, 1.699770, -0.445190, -0.453060, 0.048100, 0.807570, -2.779060,
0.759320, 1.846040, -1.259450, 1.759810, 0.948260, 1.443900, -0.954710, 2.354130, -0.389020, 0.429940,
-0.755340, 0.634690, -0.259970, -0.935340, -0.732150, -0.675380, 1.175960, 2.085600, -0.732710, 1.868120,
-0.548240, -0.197740, 1.575690, -0.654820, -0.155860, 0.193510, 0.846870, -1.325760, -0.013480, -0.470270,
0.106110, 1.199300, 0.212340, 3.655880, 0.562890, 0.113650, -2.058660, -0.713950, -0.662390, -0.240510,
0.871400, -0.744400, 0.346220, 0.607240, -0.175590, -0.135630, 1.794230, 0.238480, 0.333780, 0.184850,
0.225440, -0.043300, -2.245350, 0.599640, -0.528520, 1.133810, 0.598350, 1.176030, 0.439230, -0.831010,
1.236900, -0.154550, 1.010580, -1.768550, -0.029480, -3.674600, -0.660760, 0.109630, -0.572970, 0.659480,
2.217760, -0.051740, -1.234990, 1.240570, -1.916900, 0.898360, -0.082400, 0.707470, -0.333360, 0.523280,
-0.454990, 0.514940, 0.455950, 0.772340, 0.032920, -1.794870, -0.624540, -0.315850, 0.493650, 1.501300,
-0.553930, -1.834460, -0.164420, 0.246990, 0.694590, -0.725910, 0.962250, 0.883730, -0.632640, -0.816330,
0.741390, 0.555460, 5.095020, -0.102800, -0.158800, 0.892810, 0.375850, 0.417310, 0.817940,
-1.571180, 0.666540, 0.765390, -0.113510, -0.265800, -0.517450, -1.812630, 0.728500, -0.189020, 0.050870,
1.514910, 3.212870, 2.564040, -1.123240, -1.183160, 2.052550, 0.046660, -0.106380, -0.258700, 0.812090,
1.514920, -0.066150, 0.584670, -1.225590, -0.986410, 1.050230, 0.871000, -0.249070, 0.704390, -0.664110,
-0.986120, -0.718120, -0.603230, -0.126340, 0.159160, -0.844380, -0.749610, -0.362280, 1.194260, 1.298830,
0.056660, -1.318660, 1.501650, 0.517990, 0.378430, 0.312890, 0.316250, -0.892650, 1.261150, 0.018240,
0.508320, 0.603950, 0.720120, -0.261180, 0.818930, 0.799270, 0.564630, 6.681860, 0.030920, 1.001430,
0.057300, 2.647740, 1.857950, -0.796430, 1.095480, -1.263160, 1.157350, 0.686390, 0.131420, -0.831170,
-1.320770, -0.189000, -0.362320, -0.349420, -1.263190, -0.117640, -1.436540, -0.781370, -0.107280, 0.373040,
1.066730, -2.858130, -0.156490, 0.077620, -0.070400, 2.519450, 1.336890, 0.340160, 0.403930, 10.607220,
0.548290, 1.645780, -0.924230, -0.506050, 0.211250, 0.426770, 0.813700, 0.153360, 1.075640, 0.212270,
-0.339720, 0.052090, -1.236350, 0.264230, -0.138320, 0.193570, 0.531480, 0.577310, -0.845850, 0.221560,
-1.737660, -0.301240, 0.524330, 0.701160, -1.337370, -1.773460, 1.454040, 0.682190, 1.158450, -0.041990,
0.898320, 0.666450, 1.211630, -1.527390, -0.611470, -1.185630, -0.929850, -0.340090, -0.771370, 0.263040,
1.506570, -0.353410, -0.634160, 0.148440, 1.648250, 0.382040, -0.215630, 0.245480, 1.262280, 0.680530,
-0.952900, -0.552990, -1.007030, 2.842620, 0.558420, -1.168420, -0.040910, -0.767430, 0.251280, 1.057370,
-0.997520, 0.885690, -0.952510, -0.441500, -1.000270, -0.420770, -0.705550, -0.323080, 0.174890, -0.460180,
4.625480, 0.255530, 1.262610, -0.533940, 0.013530, 0.147680, 0.367100, 0.307590, 0.130890, 0.116320,
3.216130, -0.129660, -1.544530, 0.320070, 0.855940, 0.534150, 0.359010, -0.204750, 0.288130, 0.958600,
0.163060, 2.627750, 0.323080, -2.006110, 0.668520, -0.300480, 0.677760, 0.615720, 1.823840, 0.825890,
-0.334470, 0.960890, 0.999720, -0.429840, -0.175010, 1.060000, -0.677080, 0.927170, 0.253920, -1.329670,
-0.379450, 0.153610, 0.096730, -0.294070, 0.371720, 0.147490, 0.016580, -0.505560, -0.445740, 0.598300,
-0.692810, 0.652780, -1.122670, -0.486800, 0.000160, 0.134040, 0.146000, 0.019920, 0.159600, -0.682430,
0.645460, 2.313320, -0.301910, -1.073250, -0.656900, -0.915820, -0.359450, -0.919040, -1.135640, 2.410060,
0.184860, -1.447060, 0.316190, -0.215990, 0.438170, 1.124600, 0.134500, 0.913730, 1.992850, -0.641120,
0.845980, -0.926350, 1.570150, 0.880270, 0.230590, -0.133990, -0.087490, -0.932120, -0.150360, 0.016630,
0.872590, -0.532090, 0.250450, 8.933170, 2.072250, 0.814720, -1.548150, -0.890500, -1.794170, 0.649800,
1.099180, 1.471410, 3.103140, 0.199680, 1.362480, 2.347560, 0.912010, -3.611910, -0.102540, -1.153910,
0.062540, -0.708490, 2.121080, -1.650350, -0.467750, -0.830090, -1.315000, -1.160730, -1.331150, -0.573530,
-1.123280, 3.646180, -0.379050, -0.690680, 2.014630, -1.129490, -1.172720, 0.348920, -0.385370, 0.896080,
-0.142830, -0.960410, 4.043680, -1.281000, 0.026840, 0.184440, 0.238560, 0.240420, 0.268010,
1.227180, 0.000330, 0.096230, 0.324520, 0.638280, -0.504420, -0.531080, 0.055170, 1.480120, -0.129620,
0.459640, -0.371140, 0.620170, -0.195690, 0.766850, -0.564660, 2.056040, 0.093710, -1.262980, -1.303420,
2.367830, 0.032350, -1.177040, -0.367670, 0.695240, -1.038620, 0.058790, -0.904300, -0.209070, 0.828970,
0.153360, 0.129960, -0.281060, 0.670550, -0.709770, -1.555560, 0.725180, 0.681900, -0.149850, -0.316700,
-0.151860, -0.995500, 0.773740, -1.321800, -1.248900, -0.217230, -0.829260, -0.754910, -1.046870, 0.559110,
0.227190, -0.570930, 0.575140, -0.305040, -0.730890, -0.660560, -0.415560, -0.021390, -0.095250, -0.138690,
-0.087300, 0.842820, 0.295880, -1.642760, -0.316180, -0.250920, 1.787190, -1.051800, 0.386390, -0.196640,
-0.825600, 0.478580, 0.780890, -2.034800, 0.755950, 0.959070, 0.355150, -0.497470, -0.527090, -0.877270,
-0.091530, 0.556330, 0.692980, 2.587530, -0.503200, 0.423850, -2.331710, -0.392880, -0.965290, -0.109800,
-0.541970, 0.106100, -0.145810, 0.073420, -0.809010, 0.341360, -3.065200, -0.582790, -1.269970, 0.615430,
-1.979170, 0.152870, -0.552150, 0.334520, 1.493890, 0.128820, -0.495480, -0.438020, 0.557470, -1.025990,
-0.612730, -0.592390, 2.652280, -0.602040, 0.574930, 0.220310, -0.470870, 0.290410, 2.916310, 3.321480,
-0.571890, -0.106450, -1.444740, -17.159849, -9.861950, 1.065430, 0.256060, 1.169620, -3.445790, 1.502930,
0.979960, -0.323660, -10.710140, 1.104960, 0.493570, -0.839340, 0.744970, 1.104140, 0.103810, 0.406970,
-0.952280, -1.199190, 1.670860, -1.345520, -1.633800, 0.493570, -0.491700, 1.325870, 0.818650, -0.682040,
0.867880, -0.503140, -0.370840, -0.758320, 0.063730, -1.351710, -0.448800, -0.002600, -0.315580, 0.024360,
-0.412340, -0.021720, 0.720540, 1.719220, 2.832470, -0.109670, -1.559810, -1.103140, -1.688490, -0.498060,
-1.960950, 0.347200, 0.985240, -0.420260, -0.907060, -0.261420, -0.505100, 1.336680, -3.200030, 0.762040,
0.543670, -0.076330, 1.200940, 0.659180, -1.310640, -1.064720, -1.531630, 0.692680, 0.600030, 0.488680,
0.738410, -0.595470, 0.165680, 0.211220, 0.703430, -1.548550, -0.666700, -0.835520, 0.285990, 1.614570,
-0.574760, -5.144550, 1.463000, -0.860680, 1.319920, 0.388980, -0.628650, -0.499360, -1.260030, 0.782300,
0.204670, -0.640650, -0.205240, -1.117390, 0.904980, 0.370360, -0.535640, -0.335340, 0.773490, 1.144610,
0.286270, -0.170820, -1.186160, -1.021730, 1.152980, 2.779500, 0.694160, -0.642180, -2.732210, -0.785630,
0.919980, 0.806050, -0.902640, -0.633620, -0.444770, 0.089070, 0.554330, 0.255420, -0.201670, 0.734690,
-1.192920, 0.605310, 0.445410, 1.865830, -0.907300, -0.713810, -0.869360, -1.730680, -0.922270, 0.662190,
1.740270, -0.741180, 0.593270, 0.201470, 0.353250, 0.409300, -0.336260, -0.737200, 0.164390, -0.003900,
0.722280, -0.869990, 1.351920, 1.309260, -0.458490, -1.572420, -1.219470, 1.609920, 0.329080, -0.099850,
-0.836770, -0.981100, 0.741270, -0.370580, 0.401490, 0.350470, 0.847900, 0.759400, 0.474010, -3.172070,
0.008060, 0.949070, -0.161620, -0.606640, 0.978820, 0.976860, -0.393030, -0.674940, 0.568380, 0.955610,
-0.231040, -0.211010, -2.428080, -0.513760, -0.145130, 0.846400, -0.413060, 0.396050, 1.057350,
-1.365670, -1.432860, 0.514960, 0.611260, 0.522980, -0.161650, 0.351550, -0.973490, -0.524330, 0.401320,
0.458190, -0.033850, 0.321760, 0.088660, -0.795390, 1.520460, -0.366420, 0.234520, -1.189560, -0.614340,
1.231260, 0.742280, -0.931740, -1.636260, 0.987270, 1.018120, 0.655960, -0.466370, 0.832860, -0.490520,
-2.070300, 0.679340, -1.529280, -0.696850, 0.008560, 0.296450, -0.848700, 0.989510, -0.311590, -0.046780,
0.708110, -0.307160, -0.332100, 0.144630, 0.228850, 0.106690, 0.036340, -2.697480, 0.303370, 0.351530,
-0.343520, -1.202300, 0.776570, -0.221650, -0.719310, 0.467800, 0.333620, -0.711940, -0.140690, -1.688480,
-0.188840, -0.184920, 0.096090, -0.613200, -1.251110, -0.584230, 1.605470, 2.408030, 0.137680, -1.315300,
-1.836520, 0.338960, -0.786430, 0.744270, -0.379850, 0.230530, -0.195790, 0.817960, 2.263210, -0.148840,
1.064590, -0.390800, -0.237890, -0.847880, 0.046740, -0.104360, -0.993140, 0.460590, 1.012390, -1.395260,
0.214630, -1.409640, -0.139970, -0.539570, -0.720130, 1.144230, 0.658110, -1.155510, -0.619270, 0.384460,
-0.092560, 0.814340, 0.009620, 4.507660, -0.055280, -1.534290, 0.493770, -0.750080, 0.066650, 0.201670,
0.460970, -0.139750, -0.804900, -0.284200, -3.238650, 0.893520, 0.081880, 0.282850, 0.458600, -0.114900,
-0.134620, -1.460320, -2.029470, 0.180690, 0.196090, -1.622510, -0.031890, -0.066900, 0.622680, -1.445370,
-1.597220, 0.103450, 1.599020, -0.585180, -1.547490, 1.798000, -0.994800, -0.473810, 0.308390, -0.330360,
0.956150, -0.616420, 1.518340, 0.614930, 0.653980, -0.927400, -0.598040, -0.070100, 0.802060, 0.512980,
-0.040600, -0.302460, -0.437080, 1.475460, -1.470880, 1.047080, 0.319990, 0.156910, 1.495080, -0.302890,
-0.660540, -0.251390, 1.089320, -0.811610, -0.294870, 1.026850, -0.988600, 1.420280, -1.421360, -0.099150,
-0.355380, 0.783920, -0.498140, -1.123460, 0.705660, 0.750200, -0.723000, 0.223630, 1.459690, -0.764250,
0.204280, 1.680670, -0.037540, 0.749470, -1.130880, 0.965260, -0.605170, -1.601060, -0.283940, 0.214340,
0.192880, -0.880150, -1.347820, -0.213180, 1.003170, -1.664710, 0.744500, -0.379340, -0.227750, -0.048190,
0.094610, 1.248210, -0.947750, 0.123740, 1.024360, 1.711510, 0.527640, -0.038500, 0.272590, -0.670760,
-0.740110, 0.181400, 0.358550, -0.500390, -0.130400, 1.321370, -0.587010, -0.490540, 0.803970, -1.556710,
-0.330860, -1.057150, 0.631600, 0.292800, 1.603250, -0.267190, -0.043820, 1.244050, -0.688860, 1.506580,
-1.044990, 0.388700, -0.493450, 2.304330, -0.399730, -1.146960, 0.204600, 0.790860, -0.918430, -0.703350,
-0.292120, 0.044970, -0.072790, 0.790080, 0.409220, -1.792030, -0.379870, 1.094690, 1.641820, -1.670550,
-0.414400, -0.658880, 0.333880, -8.672560, -0.304390, 3.478950, -0.975040, -0.110430, -0.374630, 1.708910,
-1.281190, -0.259510, -1.585360, 0.240510, 2.713170, -2.230550, 0.167220, -0.399150, -0.628960, -0.581970,
-0.040510, -1.385270, 1.017930, -0.364810, -0.690810, -0.748220, -1.182690, -0.852910, -0.807380, -0.005360,
-0.255980, -5.707190, 0.363340, -0.639360, -1.497360, -0.158580, -1.208410, -2.127920, -0.468560, -0.989070,
-0.557450, -0.772990, -2.187040, -0.862280, 0.172300, -0.603860, -0.299000, -0.971220, -0.984770,
-0.664710, 0.871780, 0.598670, -0.230920, 0.535740, -0.824970, 1.796970, -0.790280, 0.587870, 0.375000,
-0.279570, 0.897950, 0.955990, 3.277200, 0.251400, -0.712550, 1.165420, 0.452080, -0.636150, 0.174180,
2.298120, 0.225970, -0.948120, 0.963810, 0.565010, 0.815410, -0.593040, 0.408460, 0.691840, 1.165130,
1.557480, 2.822900, -1.356290, 2.141370, 0.122820, 0.032840, 1.726400, 0.253610, 0.629560, 0.091810,
-0.978310, 0.674880, -0.641280, 0.014090, -3.071660, -0.145630, 1.102280, 0.012820, -0.017680, -1.179560,
0.746640, 0.471070, -0.668210, -0.143420, -0.051130, 0.581910, 0.529470, -1.804660, 0.671370, 0.163390,
0.151010, 0.779910, 0.132090, 0.784020, -1.713650, -0.026090, -1.727290, -0.840690, 0.116070, 0.104350,
1.231030, -0.451660, 0.088380, 1.034800, -0.405730, 1.010370, 0.563640, 1.363990, 1.638420, 1.054420,
-0.654740, -0.477150, 1.014660, 0.385640, 1.579260, -0.590430, 0.310810, 0.807840, 0.067860, 1.439160,
0.860010, -0.205290, 0.593890, 0.410680, 0.492210, 0.113360, 0.887920, -1.327950, 0.384960, 0.231410,
-0.851280, 0.801300, -2.608560, 0.677140, 0.086320, 0.072870, -1.274020, 0.810730, -1.312070, 0.458340,
-1.208680, 1.444920, 1.031520, 1.334360, -1.073940, 0.751430, 0.797800, -0.751550, 2.712250, -0.562620,
-0.622120, 1.239270, -0.152930, 0.123480, -1.134730, -0.536780, 0.215840, -0.101410, 0.310670, 0.499120,
1.039620, -0.842560, 0.874020, 1.062380, -0.817530, 0.058360, 0.361160, -0.611660, -0.721470, -0.331680,
-0.341160, -0.496230, 0.182600, 1.274240, -0.615810, -1.008480, -1.261760, -0.442150, 0.987040, -0.586760,
0.627350, -0.361700, 0.595330, 0.216000, -0.530860, -0.417350, 0.899580, 0.130170, -0.947980, 1.033830,
-0.320690, 0.627820, -1.744240, 0.122160, 0.314780, 1.084520, 0.778650, 1.407510, -2.216430, -0.593740,
0.056790, 0.207370, 1.083110, 0.077700, 0.388160, 0.118820, -0.299110, 0.094710, 0.127610, 0.352240,
-0.587770, 1.077690, -0.250980, -0.675960, 0.535250, -0.480060, -0.155400, 1.065700, 0.001270, -0.544450,
-2.209740, -1.714510, -0.089330, -0.359560, 0.154500, -0.883500, 0.414910, -1.184840, -0.305410, -0.873500,
0.298680, -0.565930, -0.564900, 0.684160, 0.251130, -1.452650, -0.912710, 0.263280, -2.473690, -1.274050,
0.496270, -1.059040, 0.845010, -0.359760, 0.808460, 0.431440, 0.472950, 0.088590, -0.373930, 0.564650,
0.979040, -0.147330, 1.171300, 1.816610, -0.381670, 0.912650, 0.819470, -0.167520, 0.091390, 1.039470,
0.260540, -0.998760, -0.024290, 0.320250, 0.473610, -0.597440, 0.647420, -0.205370, 0.521570, -0.997290,
0.808690, 1.191800, 0.716350, -0.109710, 0.607880, -0.544710, -0.754910, 0.565850, 0.000450, -0.145210,
0.514160, -0.324820, -0.107610, -6.017100, -0.665810, -0.719380, -0.121210, 0.498010, -0.722720, 2.549640,
1.269990, 0.226740, 1.271760, 1.166890, 0.309690, 2.591830, -0.500120, 1.008320, -0.062820, 0.659910,
-0.546310, -3.308410, -2.033900, -1.357950, -2.471300, -1.179900, -0.002220, -0.051740, -1.582790, -3.122210,
-1.604940, 0.621070, -0.976400, -0.622440, 0.503520, -1.280910, -0.938860, -1.135740, -0.228790, -0.692830,
-1.981750, -0.035180, 0.243380, -1.380790, -0.385150, -0.375920, -0.340920, -0.453270, -1.849420,
-0.692750, 0.540140, -0.322820, 0.771490, 0.387270, -0.951680, -0.743720, -0.486130, 0.060890, 0.719140,
0.710680, -0.379080, -0.356860, 1.591530, -0.344600, -0.794000, -1.645760, -1.842800, 0.245030, 0.276240,
-0.381840, -0.519690, 0.746790, -1.320100, -0.474330, 1.257270, -1.251160, -1.027580, -0.857380, 1.573630,
0.947680, -0.738110, 0.259210, -1.653940, 0.793880, -1.228450, 0.774900, 0.565380, -1.347380, 0.772550,
-0.263170, 1.738110, -0.275690, 1.034220, 0.385010, 0.456490, 0.453650, -0.887020, -0.433880, 0.401710,
-0.048720, 0.350010, 0.492300, 1.160240, -0.915620, 2.648980, -0.514900, 0.160180, -0.721930, -0.867470,
1.111520, -0.790760, -0.027240, 0.252700, 1.033270, 0.224130, 1.117570, -1.471760, 1.041390, -1.762590,
0.543630, -0.622630, 1.077720, 0.563850, 0.445020, -0.517730, -1.023000, 0.444000, 1.105600, -0.297380,
1.749140, -0.336020, 1.089300, 0.145950, 2.516140, 0.250010, 1.027240, 0.539190, -0.152560, 1.296960,
0.396250, 1.325900, -0.365240, 0.097100, 0.454410, -0.484550, 1.037990, -0.817880, -0.699340, 0.267520,
-0.115420, 0.709680, 0.212060, -0.513400, -0.988040, -0.263710, -0.169320, -0.078650, -0.732800, -0.257020,
0.723450, -0.285270, 0.780900, 0.459840, -1.647290, -0.364170, -0.498800, 0.265810, 3.267460, -0.638930,
-1.451670, 0.501450, -0.889250, -1.057440, -5.148600, -0.750310, 1.525770, 0.821860, -1.218550, -0.494540,
2.637640, 1.351370, 0.164350, -0.735320, 1.526150, 0.519640, 2.491510, 2.401410, -0.538430, 0.901670,
0.069050, 1.251230, -0.384090, -1.076870, 1.074130, 0.670310, -0.645290, -0.434610, 0.045220, 0.844210,
1.876190, -0.248560, -0.280460, -1.316260, -0.390710, 0.492140, 0.654350, 0.324160, 0.362840, 0.239990,
-0.333730, 1.299790, -0.547450, -0.822830, 0.180570, -0.210860, 2.850200, -1.624470, 0.672080, 2.062500,
-1.624420, -0.206880, -0.525970, 0.006150, 0.113810, -1.396380, -0.867060, -0.159600, 1.178320, -0.047260,
-0.535610, 0.980720, 0.392190, 0.552530, 1.240350, 0.182640, 0.557450, 2.457820, -0.473150, 0.423040,
0.790740, -0.601650, 1.348890, -0.339530, -0.821280, 1.256950, -1.421700, -0.029690, -1.304100, -0.812390,
-0.827890, 0.344450, -0.257210, -0.599240, 1.769090, -0.156640, -0.451630, -0.227800, -0.715990, -0.932630,
-0.271950, 3.279300, 0.288950, -0.450050, -1.728520, 1.875860, -1.136070, 1.132460, 1.421870, 0.741410,
-0.779260, -0.546140, 0.803850, 1.648080, -1.090830, 0.916030, 0.861900, 1.869910, 0.854820, 0.434860,
0.025390, -1.186960, -0.061850, 0.777260, 0.251270, -1.334500, 0.727400, 0.285050, 0.700930, -0.732940,
1.929110, 1.176590, 0.557230, 0.097670, -1.392350, 0.115680, 0.302220, 0.091080, -0.308920, 0.222430,
1.680320, -0.671120, 1.037100, -2.806410, -0.285700, 0.553670, 0.991300, -1.672550, -0.294280, -3.349880,
-2.033690, 0.968600, 0.724820, 1.937910, -1.799050, 3.579300, -1.100800, 0.146890, -0.387310, -0.397580,
0.012800, -1.689070, -0.524310, -1.981300, 0.271420, -0.700720, 0.426740, -1.020890, 0.354040, -0.347040,
-0.709800, -1.044140, 0.498650, -0.839290, 0.343040, 0.029040, 0.816910, 0.154650, 0.542660, -0.768390,
-0.904440, -0.414950, 2.420310, -0.910850, 0.738390, 0.606070, -0.371310, 0.982940, -0.533290,
0.640790, -0.369400, 0.164830, 0.809180, 2.072940, 0.181770, -3.146440, 1.169290, -0.014910, 0.494790,
-0.394660, 1.012310, 0.937620, 4.290800, -0.652510, 0.840540, -0.542550, -0.571570, 0.004470, -0.666650,
-0.914960, -0.371030, 0.150840, 0.569280, 0.060620, -0.654550, -0.207660, -0.358280, 0.458150, 2.036170,
0.430750, 0.031750, -0.058970, 0.768640, -0.268500, -0.420290, -0.103200, 0.629310, 0.124880, 0.362240,
-0.460560, -0.260120, 0.541080, 0.084910, -0.858210, -0.624730, -2.072020, 1.267220, 0.534030, 0.718480,
-0.137960, 0.137040, -0.094250, 0.241080, -2.936440, -3.207440, -0.571130, -1.646810, 0.192860, -0.730710,
-1.390080, 1.149670, -0.656870, -0.809830, -0.180490, -1.243130, 1.467110, -0.130980, -0.009350, 0.100940,
-0.874320, -0.849500, -0.981820, -0.375010, 0.015850, -0.415910, 0.480360, 0.443060, 0.280560, 0.729970,
-0.284740, -1.622630, 0.214780, -0.626860, -1.214560, 0.669470, -0.511580, 1.054420, 0.357190, -1.259710,
0.604820, 0.648980, 0.596410, 0.875700, -0.501960, 0.258720, 0.644530, -0.399320, -0.446920, -0.157280,
-0.665540, 0.461900, -0.599970, -0.419040, -0.206620, 0.762460, -0.700170, -0.218730, -0.186480, -0.818600,
0.796410, 0.517310, -1.748950, 0.738180, 0.506410, 1.842220, 0.199440, 3.558050, 0.591360, 3.445750,
0.777770, -2.713620, 1.533360, 7.446130, 5.499060, 0.073140, 4.030290, 1.547000, 2.807660, -0.750720,
2.395680, 0.345500, 13.067840, -0.537740, 0.556800, 20.236660, 0.583820, -1.275990, -0.371230, 1.514030,
-0.153300, 0.129000, -1.483790, -1.256760, -0.261740, 0.498140, -0.682490, -0.427470, 0.948560, -0.084250,
-1.243650, -0.482350, 0.010340, -1.146460, -0.335510, 0.587210, 0.220740, -0.522580, 0.435230, -0.768930,
0.932280, 0.343250, -0.178020, -0.178070, 0.774680, 1.294710, 1.633710, 0.149000, -0.365190, 1.496910,
1.196230, -1.660830, -0.215260, -0.591820, 0.331110, 0.035860, -0.314260, 0.620590, -0.915840, -0.140770,
-1.420940, -0.149230, -0.520970, -1.527260, 0.261360, 1.755220, 0.517360, 0.589170, 0.443990, 2.226430,
2.428180, 0.242320, -0.453170, 0.940490, -0.181640, -0.507550, -0.380720, 1.529410, 0.311870, -0.816390,
-2.145240, -0.494150, -0.280730, -1.037360, -0.651250, -0.763090, 0.431230, -0.009930, 0.296070, 1.017740,
-2.141590, -0.296310, -0.734790, -0.392550, 1.652700, 1.199490, -1.338960, -1.061190, -0.524260, -1.393780,
-0.249160, 1.419160, 0.168550, -0.797780, 1.591750, -0.351400, 0.414820, 0.960770, -1.249430, -0.253190,
-0.011390, -0.529860, 0.416170, -1.778130, 0.740130, 0.416640, -0.501220, 0.486800, -0.600680, 0.177950,
0.481500, 1.218200, 1.057290, -0.909700, -0.299470, 1.084500, -0.701060, -0.672370, -1.421830, -0.135420,
-0.319590, 1.293300, -2.186960, 7.747360, -0.697110, -0.509430, 0.240880, -0.411510, -0.581900, -0.802480,
1.141600, 0.112230, -1.574570, -1.451610, 0.978210, 0.793460, -0.009920, -0.097940, -0.535420, -0.973250,
-0.694490, 0.434330, 0.868280, -0.208010, 0.962890, 0.076900, -0.155980, -0.687380, 0.829600, 2.018590,
0.846900, 1.619940, -0.095530, 0.931010, -0.003100, 0.578720, 0.945670, 0.299150, -0.433800, -0.060700,
0.474160, -0.058540, 0.011760, 0.180080, 0.662220, -1.369210, -0.877620, 0.221370, -0.346930,
0.123420, 0.695820, -0.040880, 0.924890, -2.705290, -0.034610, -0.706910, 0.840580, -0.502000, -1.122520,
-0.583110, 0.448570, 0.616970, -0.242920, 0.325080, 0.350810, -0.063430, -0.415920, 0.999660, 0.017230,
0.057960, -1.868850, -0.316440, -1.574150, 0.066830, -0.063870, 0.551580, -0.007850, 0.430280, -3.810930,
0.309380, 0.638270, -0.898430, -1.035710, -0.544550, 0.215730, 1.430870, -0.600420, 0.975770, -1.814400,
-1.096990, -1.522710, 0.140880, 2.849200, -0.049600, 0.883760, -0.345550, -0.272300, -0.281290, 0.294520,
-0.272710, 2.329010, -0.875920, 0.458530, 0.106010, -0.570640, -0.844950, 0.057000, 0.664600, 0.317430,
0.324470, -1.517020, -0.052700, -2.196830, 1.171960, 0.429450, 1.533050, 0.119430, 0.835470, 0.155310,
0.088520, 0.156590, 0.668830, 0.927910, 0.141260, -0.902850, 0.372270, 0.361240, 1.817960, -1.797340,
-1.167070, 1.569800, 0.800940, 1.511010, -1.323580, -0.728320, 0.507710, 0.056460, -0.713580, 0.690290,
-0.828170, -0.517650, 1.035950, 0.096980, 0.649310, -0.102460, 1.103790, -0.479350, -0.326790, 0.361420,
-0.095820, 0.513260, -0.740410, -1.018680, 0.013970, 0.467580, -0.666100, -2.599050, -0.066230, 0.031940,
-2.087690, -0.173920, 1.762450, -1.622660, -0.363180, 0.216950, -2.033450, 2.674100, 0.111190, 0.309920,
-0.007150, 0.673780, 0.797480, 1.537000, -0.067120, 1.005360, 0.796210, 0.823870, -1.869650, -0.224650,
-0.134600, 0.925410, -0.363890, -0.536880, 0.057320, -11.628460, -0.425700, 0.633530, 0.481800, -0.537160,
0.468730, -0.820150, -0.128520, -0.983720, 1.029510, 2.571390, -0.030300, 1.001870, 0.769750, -1.367200,
-0.024720, -0.453090, -0.477830, -0.123820, 0.424300, -0.723930, 0.522160, 0.774370, 0.736970, -0.787260,
0.185710, -1.019150, -0.206770, 0.219520, 1.054240, -2.085630, -0.643660, 0.777780, -0.440730, -1.215830,
0.912350, 0.152320, 0.084640, -0.419420, -0.861810, 1.036190, -0.318930, 1.154130, -2.593540, 1.306210,
1.753610, 1.672790, 0.312670, -0.686610, -1.458140, -2.309940, 0.980720, 1.889710, -0.556180, -0.790040,
-0.344750, 0.512180, -2.481090, 0.620510, -0.580840, 1.306880, -0.805410, -1.884020, -0.008840, 0.082840,
0.170700, 0.071100, 0.605800, -0.343930, 0.330680, -0.228120, 1.111190, -3.027480, -0.694090, -1.259780,
0.961370, 2.182700, -1.965030, -0.061250, 0.563500, 0.072180, -3.427830, 0.847520, -0.507670, 0.059260,
-1.065710, -0.220640, -0.456200, 0.876190, -2.165740, -0.280830, 1.150820, 0.028110, -0.745730, -1.047440,
0.123760, 0.572640, -0.141730, 3.529680, -1.398860, -0.388590, -0.762460, -1.257550, -0.029510, 1.345460,
-0.864420, -1.487170, 1.482780, -0.807990, 0.374380, -0.511000, -0.714810, 1.376890, -0.616350, 0.828880,
-0.133620, -0.231360, 0.295130, -5.609990, 1.229210, -1.863650, -0.396410, 1.282170, -0.391610, 1.239660,
4.230140, 1.124180, 2.460870, 0.658880, 0.459850, 0.233580, -0.612840, 0.202470, -0.795610, -0.496840,
-1.405460, -1.592180, -0.884030, 0.348080, -1.710330, 0.193150, 0.056210, -0.944440, -0.049730, -2.685660,
-1.340830, -0.762120, 0.396050, -0.892880, -3.428380, 0.132070, -1.967170, -0.820690, 0.170130, -0.612430,
-1.154660, -1.343940, 2.882250, 0.358340, -0.340090, 0.277890, -0.671930, 0.439140, -1.233020,
0.213680, -0.117600, -0.081780, -1.869800, 0.847480, 0.100630, -0.023990, -0.289550, 0.854880, -0.203680,
-0.608260, 0.152790, 0.406450, -3.037940, -1.052510, 0.445980, -0.731490, 0.177730, 1.362220, -0.640720,
0.425840, -0.099410, -1.549720, 0.485980, 0.058860, -0.379650, -0.614580, -0.314210, -1.261290, -0.519740,
1.031440, 0.190290, -0.107740, 1.518380, -0.195290, -2.072850, 0.540230, 1.088930, 1.424830, -1.746280,
-0.158810, 0.153530, 0.247810, -0.624610, 0.383200, 0.057730, -0.304070, -0.728270, 0.008600, 0.273270,
0.379470, 0.774930, 0.475510, -0.698760, 1.149580, -0.139280, 0.171780, -0.449900, 0.445120, -0.884180,
1.024520, 0.650380, -0.202200, -0.551300, -2.184970, -0.161920, 0.334950, -3.336870, -0.026910, -0.637060,
0.818140, 0.736970, 0.241650, 1.098570, 0.221100, 0.728370, -1.618690, -0.673510, -1.230260, -0.824650,
1.208460, -0.287890, -0.594880, 0.912390, -1.862450, 0.338600, -0.905200, -0.813130, -0.304560, -0.616250,
0.158240, -1.122310, -1.441200, 0.116110, 0.430460, 1.059040, 0.077640, -0.107900, 1.749040, 0.481880,
-1.003040, 1.349080, -1.115470, -0.684350, -2.287820, 0.083340, -0.896670, -2.249740, 0.021650, -0.333120,
-0.250660, -0.473880, -1.152100, -0.836380, 0.398810, 0.973080, 1.373060, 1.587720, 0.559890, 0.088150,
0.656070, -2.539130, -1.408890, 1.178080, 4.459920, -0.152520, -1.962740, 1.635470, 1.251230, 1.151910,
-1.709060, -1.664830, 2.375800, -0.391480, -2.091270, 0.628500, -1.242240, -1.533470, 0.434610, 0.002320,
1.335140, 1.227830, 0.169370, 0.425080, 0.335160, -0.662650, 0.297220, 0.037050, 1.277260, 0.349840,
0.103950, 0.390650, -0.796800, -0.517830, 0.621200, -0.985270, 0.652190, -0.076590, 1.288400, 0.207170,
-0.132570, 0.145370, 0.906550, -0.472980, 0.184800, -0.508060, 0.151600, -0.165280, -1.159720, -0.646400,
0.868370, -1.107040, 0.107500, -0.062920, 0.642030, -0.137010, -1.491950, -0.293200, 0.573760, 1.113160,
-0.855060, 0.138630, -0.091370, -0.215990, 0.352150, -0.839050, -0.241840, -0.969170, 0.395870, -1.542240,
0.686170, 0.226930, 1.316840, 0.476650, -0.153200, -0.652170, -0.647410, 0.721120, 0.147380, 0.286180,
0.107950, -0.352760, -0.643180, -1.344840, -0.128500, -0.746350, -0.640180, -1.562780, 1.272830, -0.262760,
-0.587790, 0.753530, -0.199300, 0.062980, 0.171390, 1.029150, 0.657750, 0.747550, -1.435780, -0.273130,
-1.084570, -0.836900, 0.462620, -0.628790, -0.608870, -0.484860, -0.525410, 0.005300, -0.231640, 0.544230,
-1.217630, 0.049580, -0.274650, -0.354800, 0.321420, -0.613400, -1.341080, -1.479940, -0.831570, -0.038990,
0.143040, 0.056070, 0.310680, -1.629980, 0.987360, 1.673190, 0.930570, 0.611930, -0.894290, -0.134730,
-1.067840, 1.197060, 0.922180, 2.290700, -0.997490, -0.439220, -0.479150, 0.985030, 0.840310, -0.899650,
-0.927750, 0.024730, -1.347570, -2.277940, 1.254330, -0.513370, 0.107870, 0.211640, -0.707640, 0.787000,
-0.232900, 0.211260, -0.216130, 0.747330, 0.118410, -1.054940, -1.243100, -0.044900, -0.518640, -2.672850,
-0.901090, 0.738100, -0.487820, -1.138840, -1.006790, 0.706820, 0.095640, 0.257460, -0.002620, 0.301300,
-0.360370, -0.556050, -2.495850, -0.514300, 0.033390, -0.850620, 0.355500, -0.152810, -0.692750,
1.885780, 0.717560, 0.821630, -0.031820, -0.504930, -0.388380, -1.343650, 0.315690, -0.371160, -1.241370,
-2.068910, -0.728650, -1.084300, -0.174680, -0.665440, 1.751670, -1.255150, -0.871660, 0.991070, 0.443990,
2.346320, -0.066440, 0.534200, 0.744210, 0.947490, -0.184780, -0.081540, 1.640390, -2.327750, -0.226010,
0.110360, -0.793660, -0.071960, -0.455370, -0.239520, -0.566060, 0.568740, 1.612080, -1.681470, -0.143550,
-3.256310, -1.569260, 0.266520, 1.309770, -0.332490, 1.971180, -1.103210, -0.034400, -1.210140, -1.198800,
-1.461650, 1.425110, 0.044210, 0.040250, -0.077440, -2.273730, 3.892560, 0.345570, 1.243950, 3.398070,
0.764250, 1.076670, 0.009750, -3.479830, 0.057730, 1.069420, 2.828670, -3.243180, 0.212730, -1.980740,
0.304280, -0.198330, 1.395050, 0.076530, 0.696930, -0.583840, 0.514900, -0.712910, 0.343170, 0.566980,
-0.185170, 0.261890, 0.584770, -0.167740, 1.468610, -0.014120, -2.127470, -3.664650, 3.175120, 0.695880,
0.663920, -0.359120, 0.726210, -0.535970, 0.255200, 0.776890, 0.659350, -0.901630, -0.226200, -0.476370,
0.497050, -0.730100, -1.073110, -0.520220, 0.762350, -0.560090, 0.416830, 0.304030, 0.125170, -0.735100,
-0.696260, -0.198500, 3.873750, 1.070810, -0.335020, 0.121760, -2.481680, -1.521010, -0.790140, -1.125400,
-1.077360, 2.593980, -0.078600, -0.575060, -3.045960, 1.625570, -0.301820, 0.076860, -3.242840, 3.607990,
0.864950, 0.092970, -3.487400, 0.100010, 0.555390, -31.682440, 0.137120, 0.817530, -1.558640, 1.318140,
-2.099190, 3.943420, -1.069770, -1.370110, 0.897550, -0.648760, -0.045620, -1.253210, 0.260670, 0.913880,
-2.163400, -2.700830, 0.569550, -0.538880, -0.596010, -0.227860, 0.829200, -0.985560, 3.345130, -0.023120,
-0.226570, -1.089520, -1.969110, -0.121230, 1.787010, -0.258930, -1.053150, -0.650210, -5.361650, -1.583830,
-0.198130, 0.723430, -0.147520, 0.719620, 0.060530, -0.179580, 1.184220, 0.454990, 1.348540, 0.515360,
-0.343820, 4.850850, -1.256240, 0.804940, 0.407010, -0.668770, -0.436090, 2.326510, 0.153350, 1.048600,
-1.012840, -1.625660, 1.673960, 0.024520, -1.859370, 0.772100, 1.075670, -0.344120, 0.357750, 0.119190,
1.089970, -1.792990, 1.710620, 1.316440, 0.392730, -0.865870, -0.559810, -1.849090, -1.207730, -0.175460,
-0.042060, -1.447550, 0.746990, 1.038430, 0.024410, -0.117770, -1.876100, 0.395560, 0.236900, -0.706730,
0.890330, -0.493950, -1.305790, 0.490240, -2.332520, -0.040590, -0.008750, 4.042030, 1.087400, 1.448610,
0.378100, 0.013630, 1.044160, -0.476880, -0.502260, 0.497400, 0.628300, -0.624720, -1.668240, 0.234020,
-1.163870, 1.205900, -0.633000, 2.169860, -0.743290, 0.336620, 0.076410, -0.919220, -0.417680, -0.435960,
3.575910, 0.496160, 0.625370, -1.021880, -0.278490, -0.546000, 0.636880, -0.931520, 0.248130, -0.533320,
0.206110, 1.682720, 0.480430, 1.348720, 0.323400, 0.650650, -0.547010, 0.105100, -0.759500, 0.963120,
0.500530, -1.106420, -0.380500, -1.367070, -0.847650, -0.256300, -0.388070, -0.881110, 0.752040, -2.160530,
-0.063640, -0.688120, -0.052000, -0.569910, 0.816940, 0.267860, -0.244580, 1.191360, -0.594850, -0.452090,
0.099660, 0.738570, 1.095430, 0.434030, -0.187090, -0.045710, -0.044100, -0.808970, -0.861910,
-1.425540, 0.545080, -0.245950, -0.160840, 1.393960, -0.909400, -0.249800, 0.695670, 0.379650, 0.567400,
0.931270, -0.721320, 1.179970, 0.217270, 0.142580, -2.464600, 1.969610, 0.410030, -0.563290, 2.261190,
-1.296850, 0.493430, -0.516480, -2.381530, -0.869930, -3.207380, 0.142410, -0.826350, 0.234740, -0.880330,
-0.348310, 0.290520, -1.545210, -0.966360, 1.841270, 0.153710, -0.223070, -1.028690, -1.639050, 1.363230,
-2.448290, 0.908120, -2.071920, -0.585050, 0.644290, -0.997950, -0.477040, 1.779640, 1.490760, 0.341740,
1.393120, 1.281360, 0.144170, 1.082330, -0.404560, 2.785680, -1.608900, 0.150890, 0.466630, 0.428440,
1.149910, -2.078340, -1.129370, -0.782600, -1.172690, -2.011100, 0.523020, -0.921490, -1.049210, -1.393200,
-1.069300, -0.454320, -6.009850, -0.920440, -0.397640, 2.844640, 0.330020, 0.748970, 0.246960, 1.256470,
1.519200, -0.114590, 1.112660, 0.338890, -0.383310, 0.190690, 0.644470, -1.531890, 1.435760, -0.241710,
-0.531160, -2.553260, 0.638690, 1.554920, 0.796220, 1.111980, -0.107220, 0.643460, -2.785070, 0.321620,
0.838780, -0.503260, 0.710880, -0.326170, 0.675840, -0.622600, -2.412670, -0.886000, 0.481110, 1.776820,
0.563910, 0.372470, -1.301660, -0.905100, -1.638130, 1.803370, 0.235200, 0.108490, -2.896800, -0.091690,
0.637000, -0.047210, 0.962810, -0.234030, 2.080580, 0.104260, -1.250780, -0.295170, 0.869610, 1.909950,
-0.833140, 0.104200, -0.773070, -0.241250, -1.886490, -1.721310, -0.879580, 0.567520, 0.245390, 0.634770,
-1.604950, 1.710460, -5.180730, -0.555830, -0.263030, 0.255870, -2.291850, -1.821830, 0.815770, 2.060580,
1.296410, 1.975880, 1.681890, -0.455420, 0.040910, -3.349520, -0.549230, 0.454480, -1.414210, -2.319010,
1.333540, 0.428200, -0.037560, -0.435980, 0.562750, 1.324820, 0.580070, 1.629480, 0.019110, -0.313710,
0.329600, 0.482520, -0.385130, 1.382530, 1.032720, 0.800000, 0.707940, -0.513540, 0.991000, -1.310170,
-1.091760, -1.332090, -0.206670, -1.620510, 0.619310, 10.248400, 1.479800, 0.646510, -0.370090, 1.289250,
2.397880, 0.832740, 2.005690, 0.873110, -0.023710, 0.346390, -0.653670, 0.994560, 0.645350, -1.211440,
-0.895660, -5.568240, -0.404840, -4.121510, -0.515770, 0.384670, -9.327330, 0.753440, 0.973360, -1.330500,
-0.907050, 1.182630, 1.406950, -0.005830, 2.212150, 0.347770, 3.164360, 0.452900, 0.438240, 0.346450,
0.373560, 0.454110, 0.012680, -1.321290, 1.153840, -1.323330, -0.132990, -0.398370, -0.632030, -0.879210,
-0.958780, 0.694560, 0.196490, 0.065160, 0.324010, -0.173340, -1.689140, 2.128470, 0.114020, -0.799810,
-0.704780, 0.649040, 0.405940, -0.432300, 0.211280, -1.301670, 0.919340, 1.037360, -1.503420, 0.788780,
-1.386650, -3.047920, 0.229900, -1.956470, -0.101170, 0.613610, 0.964170, 0.943950, -0.533680, 0.171000,
2.130900, 0.482520, 0.911570, -0.651250, 2.220510, 0.734730, 0.137300, -0.524620, 0.714530, -0.200350,
0.314690, -1.507950, 0.189120, -1.197440, 0.555990, -0.263740, -0.164700, 0.524430, -1.869710, 1.014500,
-0.048540, 2.072460, 0.416310, 0.209350, -1.155010, -0.736660, -1.067460, -0.606900, 0.831790, 0.983410,
-0.228040, -0.699890, -0.713980, -0.669850, 0.430940, -0.819100, 1.751460, -0.937550, 0.977800,
4.621060, -1.951520, -4.370100, 177.324921, -1.095870, -0.667880, 1.484970, -3.073480, -2.162780, 0.261600,
-0.776200, 0.177800, 7.168790, -1.505890, -1.130440, 1099.206421, -2.237570, -1.651000, -2.544830, -0.088790,
1.475840, -3.146890, -1.963770, 49.718281, -0.955920, -0.864420, -2.652690, -1.109470, -3.591190, -2.183780,
-0.445370, 1.264650, 0.628620, 0.546460, 0.231760, 0.998630, -0.052590, -0.164300, 8.368600, 0.390700,
-0.003840, -0.372780, -1.967060, 0.867830, 1.830420, 1.931020, -0.187110, 2.095110, 1.169780, 0.514080,
0.430620, 1.513960, 0.596370, 1.735390, 1.294590, 0.340840, 1.340330, 17.055321, 0.345200, -0.223550,

-0.368930, -0.371250, 0.643830, -0.389820, -0.481790, -0.805090, -0.537950, 0.842020, 0.006890, -0.303400,
-3.942480, -0.495880, 0.109550, -0.396260, 0.136850, -903.996826, 0.164880, 0.134690, 0.028680, 0.530320,
0.572060, 0.076470, -37.502850, 1.127540, 1.006470, 0.658130, -0.509260, -0.415400, -0.299320, -0.298860,
-0.491660, -2.143070, -0.791170, -0.065270, -0.778760, -0.368640, -0.113730, 3.220160, 3.248630, 0.097970,
-0.013590, 0.439870, 1.210630, -0.797960, -0.103370, 0.578530, -0.570880, -0.721110, 0.904900, -0.702490,
-0.681420, -0.515200, -0.947150, -0.811640, -0.745960, -0.154630, 0.201030, 0.923920, -0.287830, -0.414110,

-0.467210, 0.095150, -0.082090, 0.042640, 0.306060, 0.691040, -0.971290, -0.315010, 0.179190, -0.239820,
0.139180, 0.483870, 1.246230, -0.698300, -0.041920, 1.920710, -0.135910, -0.324440, 0.766920, -0.652190,
0.035320, 0.435420, 34.516479, 0.588080, -0.246390, 0.163860, 0.808880, 0.438820, 0.454910, 0.525860,
0.796940, 59.721272, 0.166940, -0.556940, 0.318250, 0.623590, 0.326970, 0.194250, -2.882220, 0.751480,
-0.483360, 0.462660, 0.413550, 0.515930, -0.121310, -0.111200, 0.558340, 0.086450, -0.636520, 0.738120,
0.226820, -0.647180, -0.026930, -0.425990, -0.584720, 0.174760, 0.345750, 1.071800, -0.306110, 0.621340,

0.961280, 0.130870, 0.019190, -0.741090, 0.447370, 0.135500, 0.144970, 0.879660, 0.210160, 1.064650,
-0.077970, 0.386030, -0.281820, 0.562110, -0.712240, 1.178720, 0.743100, -0.824050, 0.163470, -0.043820,
-0.375640, -0.192370, 0.263270, -0.395640, -0.823360, 0.265710, -0.044140, -0.266930, -0.466760, 0.096600,
0.575000, 1.624300, 0.524910, -0.374890, 0.539150, -0.156270, -0.966410, 0.209980, -0.100990, 0.202610,
0.355050, 0.979580, 0.269270, -0.420430, -0.562430, -0.646260, -0.357170, -0.098860, -0.331680, 0.561350,
0.354220, -0.454050, -0.418830, -0.604750, 0.934850, -0.544880, 0.569030, -0.068200, 0.758390, 0.256720,

0.441250, 0.839930, 0.816940, -1.288640, 0.255790, -0.656290, -0.758620, -0.437100, 0.662540, -0.991580,
-0.467910, -0.860650, -1.097160, 0.138690, -0.153540, -0.868900, 0.589240, -0.132400, 0.173120, -0.991610,
-0.133530, -0.466780, -0.321990, 0.626490, -0.654900, 0.282320, 0.179030, 0.340230, 0.033730, 0.448040,
0.573520, 0.725590, -0.200880, 0.443120, -0.435050, 0.919480, -0.352650, 0.500100, 0.341260, -0.840140,
-0.938140, -0.080540, -0.638270, -0.280810, -0.980760, -0.003290, 0.932560, 0.965530, 0.277090, 0.612400,
0.519850, 0.503690, 0.243180, -0.028600, 0.577110, -0.468090, -0.097790, -0.870580, 0.606190, 0.065580,

-0.507340, 0.851550, -0.915130, 4.249280, 1.235790, -0.720340, 0.289280, 0.790740, 0.829630, 0.659840,
-1.122530, 0.292470, 0.990990, -0.467920, -0.477570, 1.579010, -0.407950, 0.284540, -0.481270, 0.072930,
-0.985680, 0.200110, 0.435500, 0.407720, -0.048050, 0.295990, -0.861550, 0.478820, 1.353150, 0.001150,
0.277000, 1.306760, -0.751290, -0.725930, -0.279780, -0.131820, -0.163440, 0.192290, -0.223740, 0.785350,
-0.738420, -0.435300, 0.140610, 0.841740, 0.971200, 0.601930, -0.337050, -0.642320, -0.743940, 0.611830,
0.216440, -0.060390, 0.855550, 0.793050, 0.023500, 0.004190, 0.831800, 0.526350, -0.310470, -0.204800,

-0.873860, -0.714760, -0.779390, 0.621670, 0.559340, -0.618480, 0.481770, -0.459650, -0.413400, -0.619850,
0.691730, -0.233700, 1.256030, 1.277200, 0.796170, 2.162900, -0.200470, 0.746070, 0.042970, 0.205900,
-0.723760, -0.807470, -0.006670, 2.314300, 0.027290, 0.300870, 1.627320, -0.025660, 0.014810, -0.644230,
0.648330, 0.048630, 0.438940, -0.771330, 0.324850, -0.861050, 0.683650, 0.461900, -0.505640, 0.896880,
-1.589160, -0.579060, -0.891150, 0.811580, 0.606460, 0.077430, -0.094460, 0.149400, -0.184710, -0.010090,
0.676980, 0.977300, 0.335490, -0.163350, 0.020890, 0.354200, -0.502710, 0.503760, 0.692360, 1.061600,

0.280400, 0.419550, 0.798710, -0.005860, -124.195297, 0.330510, -47.616840, 0.423460, -0.944510, 0.338610,
0.913230, -0.249800, 0.677780, -0.182310, -0.654630, 1.531070, 1.539510, -0.607030, 0.741490, 0.789450,
0.825550, -1.304970, -0.266110, 0.459680, 0.638060, 0.180300, 0.147090, 0.293510, -0.423000, -0.247610,
0.676600, -0.859500, -0.782700, 0.684500, -0.966470, 0.039100, 0.830830, -0.407220, -2.205910, -0.068600,
0.986920, -0.650150, 0.892660, -0.281120, -0.873040, 0.526060, -0.226420, 0.577050, 0.821110, 0.061350,
-0.920940, -0.172860, -0.026280, 4.190210, -0.651710, -0.540870, -0.596060, -0.013190, 0.168990, -0.222150,

0.867800, -0.501990, 0.903370, -0.613490, 0.674860, 0.302180, 0.086110, -0.953090, 0.876210, -0.135230,
0.693980, -0.988220, 0.854100, -0.600970, -0.567530, 1.021260, -0.046030, -0.032380, 0.764900, 0.095850,
0.064870, 0.548870, -1.153690, 1.055650, 0.397650, -0.810340, 0.871110, -0.772660, 0.625890, -0.608790,
-0.715200, 0.102230, 0.604960, 0.594560, -0.574660, 0.315390, -0.178390, 0.761110, 0.121510, 0.183330,
-0.301200, -0.439040, -0.288660, -0.649400, -0.565640, 0.205830, -0.309830, 0.935660, 0.072880, 0.192100,
0.140130, -0.312550, 0.821130, 0.612550, -0.427070, 0.670610, 0.020680, 0.182160, -0.976420, -0.360960,

0.471490, -0.537250, -0.353000, -0.651810, 0.472820, -0.586400, 0.382670, -0.719330, -0.253720, 0.338120,
-3.507710, -0.804700, 1.052890, -0.446160, -0.789010, -1.001730, -0.594530, -0.670690, -0.283240, 0.198720,
0.311080, -0.287250, 1.039080, 0.518280, -1.109660, 0.627250, -0.503890, 0.955580, 0.755270, -0.016650,
0.472960, 0.117670, 0.938620, -0.887300, -0.027390, -0.278720, 0.970480, -0.438750, 0.155910, 0.589990,
0.235600, -0.310670, 0.174350, -0.928900, 0.479360, 0.347490, 0.350160, -0.807790, -0.808620, -0.656890,
-0.245530, 0.590730, -0.070610, -0.950260, -0.907270, 0.928000, -0.655750, -0.717850, 0.481490, 0.536910,

-0.591040, -0.085740, 1.200430, 1.038080, 0.051030, 0.826540, -0.927380, -0.581220, -0.457050, 0.570750,
0.137390, -0.080980, 0.167200, -0.059050, -0.284720, -0.050750, -0.637560, -0.351910, -0.345370, 0.366190,
0.072740, -0.279020, 0.004160, 0.486470, 0.877160, 0.059980, -0.708170, 0.932120, -0.172760, 0.915730,
0.342940, 0.260920, -0.001610, -0.824810, 0.760790, 0.157770, 0.664370, 0.927370, 0.012560, 0.181720,
0.409220, -0.629850, -0.499760, 0.565770, -0.249700, -0.388320, 0.000640, -0.976820, 0.667200, -0.507640,
-0.837010, -0.128470, -0.147380, -0.899750, 0.005610, -0.590750, -0.447340, 0.373490, -0.156450, -0.678200,

0.246960, -0.133010, 0.194530, -3.463260, -4.330650, -1.432000, 1.709340, 0.852450, -0.724710, 2.641210,
0.888820, -1.085910, -1.742610, -1.229690, -2.421620, 3.207420, 2.412730, 0.962100, 1.024130, 0.161690,
0.571240, -2.251750, -0.262430, 0.909420, 0.772200, 0.591810, 0.549720, 0.328370, -0.073670, 1.294300,
-0.825230, 0.253360, 1.081450, 1.262860, 0.689890, 0.464300, -0.507370, 0.165760, 2.932860, 1.168750,
-0.272110, -0.950550, 0.562640, 0.156410, 0.224730, 0.186300, -0.308230, 0.141380, -0.170520, -0.227790,
0.587430, 0.320610, 0.756610, -0.192800, 1.011770, -0.095380, -0.534560, -0.816380, 0.138420, -0.001670,

0.769450, -0.220570, -0.586830, 1.945060, -0.666620, 0.023910, 0.486430, -0.544100, -1.038260, 1.004710,
0.753700, -0.302850, 0.140580, 0.163010, 0.483260, 0.866280, 1.600460, 0.009170, 1.102040, 0.060630,
-0.344760, -0.869900, 0.509710, -0.963620, 0.000270, 0.263240, -0.630400, -0.154130, 0.591620, -1.031690,
-0.474880, 0.271940, 0.383090, 0.775520, -0.385540, -0.257700, 0.054880, -0.630680, -0.548500, 0.965400,
0.667270, 0.271280, 0.010520, -0.606530, -0.180340, -0.841690, -0.727190, 0.489700, -0.729400, 0.963110,
0.587320, -0.846650, -0.126920, 0.470530, -0.170530, 0.202610, 0.669410, -4.583780, -0.709710, -8.815030,

0.271950, 0.059230, -1.462360, -0.767770, -0.639290, 0.841200, 0.500130, 0.008880, 0.254220, -0.392220,
-0.685110, -0.009860, 0.872020, -0.932030, -0.775480, -0.267000, 0.470780, 0.865930, -0.058610, 0.730640,
-0.851900, -0.961020, 1.594380, 0.883740, -0.543850, -0.743210, 0.665040, -0.447030, -0.240620, -0.225220,
0.488550, -0.467130, 0.768840, 0.565680, -0.080790, 0.259360, 0.563800, -0.259040, 0.727250, 0.573980,
0.218840, 0.832040, -0.319830, -0.006760, 0.701790, -0.634940, -0.250930, 0.770770, 0.590630, -0.562780,
0.231000, -0.216170, -0.188740, 0.575210, -0.738360, -0.976560, 0.375640, 1.255810, 0.413900, 0.324550,

0.124540, 0.453270, -0.249980, -0.115400, 0.175500, 0.428200, 0.132120, -0.457070, -0.625920, -0.519640,
-1.273340, -0.482300, 0.507240, -0.336930, -0.631430, 0.114790, 0.916270, -0.119800, 0.455320, 0.855900,
0.720930, 0.225840, -0.971200, 0.688400, 0.085450, -0.288890, 0.655700, -0.607220, -0.053290, 0.623860,
-0.537200, -0.454400, 0.921700, -0.797030, 0.527520, 0.650150, 0.038860, -0.280010, 0.410920, 0.561610,
-0.754580, -0.014310, -0.656820, -0.810340, 0.401170, -0.231960, -0.056220, 0.799610, 0.311510, -0.438070,
-0.473310, 0.428210, -0.855870, 0.400590, 0.738300, -0.173300, 0.409950, -0.170930, -0.266320, 0.103250,

1.053070, 0.270700, 0.008500, -0.258900, 0.663390, -0.581160, -0.234270, 0.005740, 0.780290, -0.288950,
-1.230260, -0.648060, -1.263730, 0.660500, -0.242650, 0.400270, 0.908570, 0.699560, -0.725350, -0.520820,
-0.544640, 0.828780, -0.094970, 0.062540, -0.919870, -0.336320, 0.267990, 0.407170, 0.186520, 0.565480,
0.320590, 0.681640, 0.076500, 0.180990, 0.872290, -0.923580, -0.466950, 0.067430, 0.388630, 0.154760,
-0.704540, -0.819900, -0.328150, 0.095800, -0.677660, 0.159390, 0.499420, 0.025290, 1.009080, 0.227230,
0.785740, 0.786460, 0.836850, 0.646110, -0.754250, 0.755850, -0.984330, 0.066960, 0.177690, 0.075370,

0.161620, -0.928430, -1.765010, -1.045570, -0.812240, -0.062030, 0.046390, 0.737790, -0.236810, 0.607440,
0.326420, 0.014990, -0.057520, -0.759490, 0.163450, -0.879280, 0.734760, -0.872300, 0.917640, 0.894570,
0.357860, 1.359930, -0.875590, 1.081980, 0.509810, 0.045520, 0.713300, -0.631200, 0.532440, 0.264300,
-0.567780, -0.579880, 0.242080, 0.903340, -0.664560, 0.510570, 0.967350, 0.907890, -0.303660, -0.138870,
-0.293140, -0.490580, 0.606420, -0.856370, 0.706940, 0.546110, -0.106600, -0.122010, -0.580130, 0.503450,
0.732080, -0.699660, 0.058130, 0.570570, 0.805720, -0.666640, -0.195280, -0.255260, 0.761510, 0.587530,

0.129650, -0.731690, -0.473380, -1.285790, 0.189710, 0.911760, 0.562620, 0.829550, 0.051270, 0.668790,
-0.538050, 0.123320, 1.033730, -0.511080, 0.698370, 0.746810, -0.999070, 0.326580, -0.743390, -0.040690,
-0.526300, -0.088730, -0.334960, 0.447100, 0.864160, -0.916340, 0.121650, 0.838520, 0.547160, -0.583350,
-0.212370, 2.627280, 0.718530, -0.543570, -0.123210, 0.058660, -0.087910, 0.199840, 0.349900, 0.011740,
-0.794130, 0.306420, -0.588840, -0.165150, 0.935630, 0.971820, 0.884400, -0.199770, 0.529620, -0.213880,
-0.515710, 0.209370, 0.816650, -0.538560, -0.520170, -0.173210, -0.724080, -1.408610, -0.976320, -0.414400,

0.301530, -0.093980, -0.740230, 1.116440, 0.234940, -0.222050, -0.150270, 0.663290, 0.801050, -0.095960,
-1.187530, 0.578230, 1.071040, -0.883860, 0.577500, -0.102370, -0.307220, 0.766270, 0.689290, 0.384500,
0.643500, -0.800910, -0.803950, 0.027820, 0.963130, -0.644350, 0.825730, -0.418780, 0.963730, -0.251350,
0.071780, 2.681270, 0.881700, -0.144940, 0.159590, -0.616020, -0.463480, -0.334420, 0.641010, -0.455270,
0.061190, 0.366940, 0.196990, -0.785860, 0.004110, 0.781010, -0.563640, 0.069080, 0.965250, 0.591710,
-0.634410, 0.357490, -0.266130, -0.754310, -0.830780, -0.501980, 0.024930, 0.743250, 0.345510, 0.675390,

0.146020, -0.167640, 2.519170, -1.285180, 0.531860, 0.919650, 0.862060, -0.830660, -0.048080, 0.609720,
8.936640, -0.995770, 1.330690, -0.999750, 0.475890, 0.443490, 1.943260, 0.531750, 0.671060, -0.592380,
0.769510, -0.714540, 1.559450, -0.886210, 0.752340, -0.482120, -0.576270, -0.335770, -0.759180, -0.176650,
-0.295840, -0.260340, -0.787880, 0.438810, 0.350550, 0.119060, 0.187070, -0.574780, -0.109410, 0.486030,
0.783180, 0.174550, 1.062600, 0.625240, 0.560100, -0.847110, 0.282120, -0.695400, 0.725180, 0.684030,
0.015420, 0.045940, -0.014100, 1.395300, 0.053030, -0.144980, 0.428430, -2.187700, 0.820930, 0.213230,

-0.539940, -0.178340, 0.229380, 1.212710, -1.131740, -0.013500, -0.193900, -0.066190, 0.107110, -0.638770,
0.202450, -0.148950, -0.025310, 0.758280, -0.906280, 0.229680, -0.042280, 0.292290, 0.840670, 0.545990,
0.118960, -0.624170, 0.414110, 0.654510, 0.739380, 0.462250, -0.882240, -0.607350, -0.656190, 0.831280,
0.872810, -0.235120, -0.882680, 0.225070, -0.833680, 0.946300, -0.687860, 0.621210, 0.298570, 0.182880,
-0.154950, -0.394000, 0.050760, 0.961210, -0.932000, 0.609510, -0.338870, 0.394010, 0.506010, 0.406950,
0.778070, 0.645020, -0.534900, -0.487730, 0.410400, -0.972640, -0.974360, 0.659190, -0.419720, -0.637610,

-0.297080, 0.207820, -0.416730, 0.346520, -1.331160, -0.986220, 0.777890, 0.575240, -0.958120, -0.487800,
0.982240, -0.643870, -0.672170, -0.547110, 0.858420, 0.905710, -0.765000, -0.429100, -0.099450, -1.113600,
-0.172130, 0.843330, 0.592300, -0.533420, 0.560450, -0.559050, 0.486930, -0.713600, -0.933330, -0.196660,
0.467540, -0.085550, 0.649450, 0.443180, -0.514300, 0.616060, -0.148710, -0.238730, 0.852870, -0.373180,
-0.830640, 0.449870, -0.635050, 0.794970, -0.923540, 0.530020, 0.589270, 0.119410, 0.687660, -0.662340,
-0.589960, -0.146770, -0.341220, -1.486190, -0.276170, -0.664830, -0.367770, -0.441670, -0.023250, 0.388960,

0.331400, 0.870520, 0.571220, 0.720220, 0.813120, 0.908150, 0.975870, -0.327360, 0.147950, -0.859900,
0.400370, -0.537460, 0.191000, -0.373390, 0.316210, -1.130180, -0.770060, -0.835930, 0.673880, 0.280600,
-0.596070, 0.477000, 1.315280, -0.388050, -0.148820, 0.446210, -0.484890, 0.583760, -0.364640, -0.333980,
-0.126210, 0.045200, -0.954150, -0.713670, 0.886700, 0.066180, -0.602380, 0.438340, -0.575740, 0.507020,
0.750470, 0.916500, 0.524490, 0.124510, -0.314680, 0.720710, 0.266230, -0.221950, -0.922160, -0.280570,
0.489580, 0.433190, 0.613570, 1.082320, -0.381280, -0.420210, -0.401870, 0.146090, 0.950650, 0.323680,

-0.911360, 0.273560, -0.043370, -0.768890, 0.682110, 0.259580, -0.560550, 0.097130, -0.993290, -0.347080,
0.974950, -0.510190, -1.561210, 0.143820, 0.890300, -0.011200, 0.449980, 0.862300, -0.717680, -0.942710,
0.094220, -0.101210, -0.968770, 0.271510, 0.180080, -0.670740, 0.669310, 0.440850, 0.076520, -0.309810,
-0.071820, -0.188160, 0.920780, -0.931380, 0.502580, 0.213000, -0.656570, 0.523970, -0.965000, 0.358530,
-0.770580, -0.988200, 0.013740, -0.390420, 0.183340, 0.480990, -0.871080, 0.374540, 0.297210, -0.781700,
0.901200, -0.059550, -0.082990, 0.582540, -0.447340, 0.377250, 0.284830, -0.451580, -0.380920, -0.466030,

0.819880, -0.973780, 0.857960, -0.825360, -0.353570, -0.241180, 0.178680, -0.074080, 0.944470, -0.233370,
1.048420, 0.445580, -0.470440, 0.017610, 0.075860, -0.143550, -0.869030, 0.385590, -0.589910, -0.441530,
0.142810, 1.080240, -0.502560, -0.042320, -0.710820, 0.720840, -0.888240, 0.421560, 0.439170, 1.080500,
-0.112410, 0.015430, 0.152080, 0.699500, -0.450490, 0.667290, -0.427780, -0.499950, 0.753890, 0.405520,
-0.825850, 0.560670, 0.478260, 0.611430, -0.353720, 0.142190, -0.826250, 0.730270, 0.940320, -0.845670,
-0.482010, -0.743120, -0.038530, 0.624670, 0.539730, 0.224390, -0.952760, 0.342820, 0.943890, 0.198210,

-0.379460, 0.227810, 0.253400, -0.330230, -0.368330, 0.012090, 0.183470, -0.148490, 0.942630, 0.219290,
-0.419770, -0.621190, -1.020170, 0.228340, 0.167420, 0.833310, 1.015910, 0.024450, -0.175290, 0.350770,
0.220120, 0.460040, -0.618610, 0.019730, 0.118040, -0.305750, -0.162200, 0.483030, -0.088060, -0.288050,
-0.086650, -0.511120, -0.336950, -0.813890, 0.899060, 0.667810, 0.390610, 0.821260, -0.133990, -0.397470,
-0.625470, -0.003760, -0.850410, -0.098880, 0.304670, -0.880860, -0.006260, 0.408580, -0.709570, -0.449670,
0.139790, 0.418860, 0.112420, 0.186160, 0.975570, -0.298230, 0.716100, -0.825030, 0.166670, 0.833350,

0.482260, -0.618730, -0.810220, -0.864360, -0.764520, 0.467940, -0.769300, -0.127050, 0.434440, -0.614540,
-0.593160, 0.962980, 1.016040, 0.948270, 0.113200, 0.407250, -0.601750, 0.731350, 0.174840, 0.803570,
-0.670990, -0.370190, -0.049460, -0.818970, -0.341200, -0.308150, 0.882430, -0.686520, 0.565830, -0.104590,
-0.768040, -0.158490, 0.216280, -0.541300, -0.926890, -0.841530, 0.412040, -0.997580, -0.624340, 0.930550,
-0.885890, 0.395450, -0.812970, 0.632030, 0.819530, 0.129820, 0.906950, -0.501440, 0.924870, 0.400870,
0.177550, 0.941160, -0.274090, -0.227480, 0.599750, -0.056110, -0.698790, -0.419830, -0.347250, 0.914370,

0.535610, -0.874830, -0.336790, 0.908190, -0.483170, -0.934390, -42.557171, 0.494810, 0.681140, -0.937270,
-11.850510, -0.105290, -1394.420776, -0.103480, 0.876670, -23.952921, -0.143060, 0.056510, 0.866270, -0.363070,
-0.693420, 0.586110, -0.400830, -3.553930, -0.933420, -0.274030, -0.464460, 0.602750, 1.265940, 0.659340,
-0.097540, 0.008820, 0.488690, -0.692280, -0.878180, -0.042700, -0.312770, 0.541410, -0.341390, -0.431560,
-0.868960, 0.395010, -13.576220, 0.253410, -0.742280, 0.125500, -0.712770, -0.150320, 0.462910, -0.615110,
-0.256120, -0.583890, -0.756920, 0.144220, 0.768190, 0.580360, 0.348550, 0.074680, -0.801720, 3.010520,

-1.138850, 0.669350, -0.805160, -1.908880, 0.192640, 0.456280, 0.254800, 0.723080, 0.883760, -0.892040,
-1.522050, 0.039480, -0.769530, -0.062210, 0.118040, -1.092480, -0.533210, -0.202910, -0.072810, -0.288250,
-1.000350, -0.492140, 1.270090, 0.456620, -0.546200, 0.691220, 0.413870, -0.231130, -0.345800, 0.682520,
0.872200, 0.155640, 0.060070, -0.399010, 0.970540, -0.315610, 0.371800, 0.483630, 0.000410, 0.216790,
-0.999860, -0.312150, 0.199790, 0.912980, 0.613100, 0.810240, -0.269120, 0.388720, -0.968050, -0.151980,
0.434050, -1.572320, 0.940310, -0.731940, -0.947550, 0.690090, -0.492580, -2.269160, -0.655160, -0.885730,

0.558370, -0.086890, -0.540340, 1.017620, 0.239650, -0.626880, 0.490870, 0.717110, -0.930880, -0.142440,
-2.586670, -0.108820, 1.327840, -0.913770, -0.373880, -0.578630, -0.710450, -0.700020, -0.677430, -0.867680,
-0.804320, -0.600500, -0.121410, 0.097400, -0.250900, -0.373720, 0.892570, 0.970000, -0.324830, 0.504220,
0.164360, 0.581110, 0.634620, -0.862650, 0.512040, -0.361900, -0.441080, 0.001790, 0.641530, -0.319090,
-0.406390, -0.804140, 0.065830, 0.500600, -0.117670, -0.715910, 0.843380, -0.071830, 0.152710, -0.147420,
0.822270, -0.635110, 0.362420, -1.627520, -0.765270, 0.267720, -0.347600, -0.836590, -0.633040, 0.026770,

0.256730, 0.627770, -0.219680, -0.423190, 0.805490, -0.707000, -0.997960, -0.229630, -0.710850, -0.951800,
0.792120, 0.274270, -0.144250, 0.817990, -0.977810, -0.552080, -0.708560, -0.879670, -0.580850, 0.629870,
-0.580910, -0.739410, 0.286070, 0.544320, 0.694830, 0.064630, 0.601200, -0.613990, 0.340440, -0.761140,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, -0.621030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, -0.119770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.435930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, 0.194800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.737700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, -0.813780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, -0.133960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.852870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, 0.866800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.634090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.468630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, -0.652310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, 0.161580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, -0.778180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.360820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.007850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.592730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, -0.171250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.284970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, -0.398470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.686000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.000580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.292170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.230070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.026000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.125690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, 0.512350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.543850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, 0.292790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.999430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.680930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, 0.549080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.621880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.819160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.669230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.012450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, -0.382920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.027250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, 0.147080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.891740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, -0.481550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.067950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.590290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.414360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, 0.815480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.002370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, 0.392060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.187200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.536190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.221880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, 0.373300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, 0.296660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, 0.553690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.192720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, -0.319910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.127820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, -0.241930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.861650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.540100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.806410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.723890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.338740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.922520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, -0.154140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.255650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, -0.492710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.805270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, 0.011530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.295740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, 0.919150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.505450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.580450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.788070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, 0.638800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.504200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.612290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.711030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, -0.833730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, -0.014010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, -0.638070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.273950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.970190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.087420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.992490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.925010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.791040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.419920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, 0.167180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.789690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.690160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.095280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.818080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, 0.578650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.136670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, 0.106520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, 0.102440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.592550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, -0.054360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, -0.099160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.165370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.854050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.440170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, -0.007610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.294190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, -0.834330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.353100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.207910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, -0.168230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.321520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.771220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.700180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, 0.601710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.167770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, 0.256410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.360740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.239070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, -0.470260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.148080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.205420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, 0.242780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, -0.840880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.834010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.480530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, -0.768660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.778260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, -0.262960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, 0.520070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.160910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, 0.998520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, -0.529230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, 0.570890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.611350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.877390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.147850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, -0.300890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, -0.728570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.468910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.207230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, 0.448680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, 0.075790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.789190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, 0.380470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.124060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.664380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.520050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.123680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.005460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.291740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, 0.071480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.472270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, -0.066420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.315620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, -0.177540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, -0.667080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.784640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, -0.119820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, 0.883930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.439290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, 0.902160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, 0.741590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, 0.987090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, -0.086130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.633090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, 0.702100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, -0.281250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, -0.625400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.354110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.758850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.966800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.064150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.506220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, 0.684180, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, -0.143410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.633350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.352720, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.516580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.994350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, 0.646360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, -0.931780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.477550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.960160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, 0.553320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.670490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, 0.229870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.960980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, -0.412570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.567530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, 0.144040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, -0.957380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, 0.664100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, -0.741310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, 0.010860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, 0.672140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, -0.185440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, 0.987970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.798940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.864840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.781580, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.580210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, 0.005910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.223170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.166880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.211810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, -0.922480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, -0.553670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.467030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, -0.964170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.292530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, 0.345670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.528270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, 0.646680, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, 0.262640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, 0.921100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, -0.149240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, -0.627610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.418400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.469730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.792570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.133430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.391530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.049200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, 0.333970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, -0.374640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.983870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, -0.235560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, 0.689450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.452830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.192610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.177500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, 0.133440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.540330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.702340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.464400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.378630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.717160, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.177900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.110690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.977290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.131700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, -0.593610, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, -0.282770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.326810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.167080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, -0.609150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.807210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, 0.949240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.680910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, 0.335430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, -0.587910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.165460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, 0.951860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.416460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.314550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, 0.470890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.416480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.011960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, -0.019120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.355210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, 0.232940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, -0.544980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.848830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, -0.843820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.147520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.502400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, 0.342860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, 0.667980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, -0.375420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, 0.186900, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, -0.198660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, -1.222320, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -0.627320, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.359680, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, -0.558040, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, 0.306290, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, 0.028550, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.143310, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.632000, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, 0.227150, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.801900, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -1.778890, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.366020, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -1.674090, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, -0.357840, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, 0.154290, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -1.412570, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.526790, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 0.037980, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -0.708340, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, -0.413480, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, -0.726330, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, -0.250510, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, 0.331420, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.966970, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, -0.580560, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, -0.501490, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, 0.099350, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.476060, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.654610, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.005110, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, 0.432490, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, 0.559110, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.026240, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, -0.635910, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -0.183990, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, 0.858250, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.465550, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, -0.165820, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, -0.489250, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, 0.716660, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, -0.027810, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, -0.133940, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, -0.922620, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.293320, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, 0.381380, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -0.259180, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, 0.052320, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.955870, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, 0.504330, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, 0.357180, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, 0.910750, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, -0.893640, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 0.582690, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, -0.422840, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.644670, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.643730, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.831120, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, 0.230630, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, -0.882070, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, 0.805550, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.909020, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (con11) */
0.30023, 0.500000, 2,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (con12) */
0.14831, 0.500000, 2,
       &Sources[10802] ,
       &Weights[10802] ,
      },
    { /* unit 333 (con13) */
0.30022, 0.500000, 2,
       &Sources[10804] ,
       &Weights[10804] ,
      },
    { /* unit 334 (con14) */
0.00810, 0.500000, 2,
       &Sources[10806] ,
       &Weights[10806] ,
      },
    { /* unit 335 (con15) */
1.09863, 0.500000, 2,
       &Sources[10808] ,
       &Weights[10808] ,
      },
    { /* unit 336 (con16) */
0.33876, 0.500000, 2,
       &Sources[10810] ,
       &Weights[10810] ,
      },
    { /* unit 337 (con17) */
0.17480, 0.500000, 2,
       &Sources[10812] ,
       &Weights[10812] ,
      },
    { /* unit 338 (con18) */
1.12593, 0.500000, 2,
       &Sources[10814] ,
       &Weights[10814] ,
      },
    { /* unit 339 (con19) */
0.00533, 0.500000, 2,
       &Sources[10816] ,
       &Weights[10816] ,
      },
    { /* unit 340 (con110) */
0.85234, 0.500000, 2,
       &Sources[10818] ,
       &Weights[10818] ,
      },
    { /* unit 341 (con111) */
0.00000, 0.500000, 2,
       &Sources[10820] ,
       &Weights[10820] ,
      },
    { /* unit 342 (con112) */
0.39020, 0.500000, 2,
       &Sources[10822] ,
       &Weights[10822] ,
      },
    { /* unit 343 (con113) */
0.00000, 0.500000, 2,
       &Sources[10824] ,
       &Weights[10824] ,
      },
    { /* unit 344 (con114) */
1.33800, 0.500000, 2,
       &Sources[10826] ,
       &Weights[10826] ,
      },
    { /* unit 345 (con115) */
0.42024, 0.500000, 2,
       &Sources[10828] ,
       &Weights[10828] ,
      },
    { /* unit 346 (con116) */
0.00000, 0.500000, 2,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 347 (con117) */
1.03556, 0.500000, 2,
       &Sources[10832] ,
       &Weights[10832] ,
      },
    { /* unit 348 (con118) */
1.12821, 0.500000, 2,
       &Sources[10834] ,
       &Weights[10834] ,
      },
    { /* unit 349 (con119) */
0.30843, 0.500000, 2,
       &Sources[10836] ,
       &Weights[10836] ,
      },
    { /* unit 350 (con120) */
1.32723, 0.500000, 2,
       &Sources[10838] ,
       &Weights[10838] ,
      },
    { /* unit 351 (con121) */
0.30035, 0.500000, 2,
       &Sources[10840] ,
       &Weights[10840] ,
      },
    { /* unit 352 (con122) */
1.04140, 0.500000, 2,
       &Sources[10842] ,
       &Weights[10842] ,
      },
    { /* unit 353 (con123) */
0.91144, 0.500000, 2,
       &Sources[10844] ,
       &Weights[10844] ,
      },
    { /* unit 354 (con124) */
0.00013, 0.500000, 2,
       &Sources[10846] ,
       &Weights[10846] ,
      },
    { /* unit 355 (con125) */
1.09839, 0.500000, 2,
       &Sources[10848] ,
       &Weights[10848] ,
      },
    { /* unit 356 (con126) */
1.05520, 0.500000, 2,
       &Sources[10850] ,
       &Weights[10850] ,
      },
    { /* unit 357 (con127) */
0.30904, 0.500000, 2,
       &Sources[10852] ,
       &Weights[10852] ,
      },
    { /* unit 358 (con128) */
0.07394, 0.500000, 2,
       &Sources[10854] ,
       &Weights[10854] ,
      },
    { /* unit 359 (con129) */
0.00145, 0.500000, 2,
       &Sources[10856] ,
       &Weights[10856] ,
      },
    { /* unit 360 (con130) */
0.89014, 0.500000, 2,
       &Sources[10858] ,
       &Weights[10858] ,
      },
    { /* unit 361 (con21) */
1.37303, 0.500000, 2,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 362 (con22) */
0.00014, 0.500000, 2,
       &Sources[10862] ,
       &Weights[10862] ,
      },
    { /* unit 363 (con23) */
1.42553, 0.500000, 2,
       &Sources[10864] ,
       &Weights[10864] ,
      },
    { /* unit 364 (con24) */
1.27216, 0.500000, 2,
       &Sources[10866] ,
       &Weights[10866] ,
      },
    { /* unit 365 (con25) */
1.25899, 0.500000, 2,
       &Sources[10868] ,
       &Weights[10868] ,
      },
    { /* unit 366 (con26) */
1.12484, 0.500000, 2,
       &Sources[10870] ,
       &Weights[10870] ,
      },
    { /* unit 367 (con27) */
1.42377, 0.500000, 2,
       &Sources[10872] ,
       &Weights[10872] ,
      },
    { /* unit 368 (con28) */
0.28982, 0.500000, 2,
       &Sources[10874] ,
       &Weights[10874] ,
      },
    { /* unit 369 (con29) */
0.15701, 0.500000, 2,
       &Sources[10876] ,
       &Weights[10876] ,
      },
    { /* unit 370 (con210) */
0.08805, 0.500000, 2,
       &Sources[10878] ,
       &Weights[10878] ,
      },
    { /* unit 371 (con211) */
0.26719, 0.500000, 2,
       &Sources[10880] ,
       &Weights[10880] ,
      },
    { /* unit 372 (con212) */
1.37170, 0.500000, 2,
       &Sources[10882] ,
       &Weights[10882] ,
      },
    { /* unit 373 (con213) */
0.03685, 0.500000, 2,
       &Sources[10884] ,
       &Weights[10884] ,
      },
    { /* unit 374 (con214) */
1.34647, 0.500000, 2,
       &Sources[10886] ,
       &Weights[10886] ,
      },
    { /* unit 375 (con215) */
0.91501, 0.500000, 2,
       &Sources[10888] ,
       &Weights[10888] ,
      },
    { /* unit 376 (con216) */
1.36527, 0.500000, 2,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 377 (con217) */
1.40689, 0.500000, 2,
       &Sources[10892] ,
       &Weights[10892] ,
      },
    { /* unit 378 (con218) */
1.23688, 0.500000, 2,
       &Sources[10894] ,
       &Weights[10894] ,
      },
    { /* unit 379 (con219) */
0.87628, 0.500000, 2,
       &Sources[10896] ,
       &Weights[10896] ,
      },
    { /* unit 380 (con220) */
1.41994, 0.500000, 2,
       &Sources[10898] ,
       &Weights[10898] ,
      },
    { /* unit 381 (con221) */
1.08979, 0.500000, 2,
       &Sources[10900] ,
       &Weights[10900] ,
      },
    { /* unit 382 (con222) */
0.12728, 0.500000, 2,
       &Sources[10902] ,
       &Weights[10902] ,
      },
    { /* unit 383 (con223) */
1.06496, 0.500000, 2,
       &Sources[10904] ,
       &Weights[10904] ,
      },
    { /* unit 384 (con224) */
0.11825, 0.500000, 2,
       &Sources[10906] ,
       &Weights[10906] ,
      },
    { /* unit 385 (con225) */
0.67534, 0.500000, 2,
       &Sources[10908] ,
       &Weights[10908] ,
      },
    { /* unit 386 (con226) */
1.15460, 0.500000, 2,
       &Sources[10910] ,
       &Weights[10910] ,
      },
    { /* unit 387 (con227) */
0.73267, 0.500000, 2,
       &Sources[10912] ,
       &Weights[10912] ,
      },
    { /* unit 388 (con228) */
0.00764, 0.500000, 2,
       &Sources[10914] ,
       &Weights[10914] ,
      },
    { /* unit 389 (con229) */
1.15765, 0.500000, 2,
       &Sources[10916] ,
       &Weights[10916] ,
      },
    { /* unit 390 (con230) */
0.08915, 0.500000, 2,
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
