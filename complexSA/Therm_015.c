/*********************************************************
  Pfam_el_015new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:08:50 2004
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
  static UnitType Units[410];
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
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10,
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20,
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30,
Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40,
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50,
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60,
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70,
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80,
Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90,
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100,
Units + 101, Units + 102, Units + 103, Units + 104, Units + 105, Units + 106, Units + 107, Units + 108, Units + 109, Units + 110,
Units + 111, Units + 112, Units + 113, Units + 114, Units + 115, Units + 116, Units + 117, Units + 118, Units + 119, Units + 120,
Units + 121, Units + 122, Units + 123, Units + 124, Units + 125, Units + 126, Units + 127, Units + 128, Units + 129, Units + 130,
Units + 131, Units + 132, Units + 133, Units + 134, Units + 135, Units + 136, Units + 137, Units + 138, Units + 139, Units + 140,
Units + 141, Units + 142, Units + 143, Units + 144, Units + 145, Units + 146, Units + 147, Units + 148, Units + 149, Units + 150,
Units + 151, Units + 152, Units + 153, Units + 154, Units + 155, Units + 156, Units + 157, Units + 158, Units + 159, Units + 160,
Units + 161, Units + 162, Units + 163, Units + 164, Units + 165, Units + 166, Units + 167, Units + 168, Units + 169, Units + 170,
Units + 171, Units + 172, Units + 173, Units + 174, Units + 175, Units + 176, Units + 177, Units + 178, Units + 179, Units + 180,
Units + 181, Units + 182, Units + 183, Units + 184, Units + 185, Units + 186, Units + 187, Units + 188, Units + 189, Units + 190,
Units + 191, Units + 192, Units + 193, Units + 194, Units + 195, Units + 196, Units + 197, Units + 198, Units + 199, Units + 200,
Units + 201, Units + 202, Units + 203, Units + 204, Units + 205, Units + 206, Units + 207, Units + 208, Units + 209, Units + 210,
Units + 211, Units + 212, Units + 213, Units + 214, Units + 215, Units + 216, Units + 217, Units + 218, Units + 219, Units + 220,
Units + 221, Units + 222, Units + 223, Units + 224, Units + 225, Units + 226, Units + 227, Units + 228, Units + 229, Units + 230,
Units + 231, Units + 232, Units + 233, Units + 234, Units + 235, Units + 236, Units + 237, Units + 238, Units + 239, Units + 240,
Units + 241, Units + 242, Units + 243, Units + 244, Units + 245, Units + 246, Units + 247, Units + 248, Units + 249, Units + 250,
Units + 251, Units + 252, Units + 253, Units + 254, Units + 255, Units + 256, Units + 257, Units + 258, Units + 259, Units + 260,
Units + 261, Units + 262, Units + 263, Units + 264, Units + 265, Units + 266, Units + 267, Units + 268, Units + 269, Units + 350,
Units + 351, Units + 352, Units + 353, Units + 354, Units + 355, Units + 356, Units + 357, Units + 358, Units + 359, Units + 360,
Units + 361, Units + 362, Units + 363, Units + 364, Units + 365, Units + 366, Units + 367, Units + 368, Units + 369, Units + 370,
Units + 371, Units + 372, Units + 373, Units + 374, Units + 375, Units + 376, Units + 377, Units + 378, Units + 379,
Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 270, Units + 271, Units + 272, Units + 273, Units + 274, Units + 275, Units + 276, Units + 277, Units + 278, Units + 279,
Units + 280, Units + 281, Units + 282, Units + 283, Units + 284, Units + 285, Units + 286, Units + 287, Units + 288, Units + 289,
Units + 290, Units + 291, Units + 292, Units + 293, Units + 294, Units + 295, Units + 296, Units + 297, Units + 298, Units + 299,
Units + 380, Units + 381, Units + 382, Units + 383, Units + 384, Units + 385, Units + 386, Units + 387, Units + 388, Units + 389,
Units + 390, Units + 391, Units + 392, Units + 393, Units + 394, Units + 395, Units + 396, Units + 397, Units + 398, Units + 399,
Units + 400, Units + 401, Units + 402, Units + 403, Units + 404, Units + 405, Units + 406, Units + 407, Units + 408, Units + 409,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 300, Units + 301, Units + 302, Units + 303, Units + 304, Units + 305, Units + 306, Units + 307, Units + 308, Units + 309,
Units + 310, Units + 311, Units + 312, Units + 313, Units + 314, Units + 315, Units + 316, Units + 317, Units + 318, Units + 319,
Units + 320, Units + 321, Units + 322, Units + 323, Units + 324, Units + 325, Units + 326, Units + 327, Units + 328, Units + 329,

Units + 270, Units + 350,
Units + 271, Units + 351,
Units + 272, Units + 352,
Units + 273, Units + 353,
Units + 274, Units + 354,
Units + 275, Units + 355,
Units + 276, Units + 356,
Units + 277, Units + 357,
Units + 278, Units + 358,
Units + 279, Units + 359,
Units + 280, Units + 360,
Units + 281, Units + 361,
Units + 282, Units + 362,
Units + 283, Units + 363,
Units + 284, Units + 364,
Units + 285, Units + 365,
Units + 286, Units + 366,
Units + 287, Units + 367,
Units + 288, Units + 368,
Units + 289, Units + 369,
Units + 290, Units + 370,
Units + 291, Units + 371,
Units + 292, Units + 372,
Units + 293, Units + 373,
Units + 294, Units + 374,
Units + 295, Units + 375,
Units + 296, Units + 376,
Units + 297, Units + 377,
Units + 298, Units + 378,
Units + 299, Units + 379,
Units + 300, Units + 380,
Units + 301, Units + 381,
Units + 302, Units + 382,
Units + 303, Units + 383,
Units + 304, Units + 384,
Units + 305, Units + 385,
Units + 306, Units + 386,
Units + 307, Units + 387,
Units + 308, Units + 388,
Units + 309, Units + 389,
Units + 310, Units + 390,
Units + 311, Units + 391,
Units + 312, Units + 392,
Units + 313, Units + 393,
Units + 314, Units + 394,
Units + 315, Units + 395,
Units + 316, Units + 396,
Units + 317, Units + 397,
Units + 318, Units + 398,
Units + 319, Units + 399,
Units + 320, Units + 400,
Units + 321, Units + 401,
Units + 322, Units + 402,
Units + 323, Units + 403,
Units + 324, Units + 404,
Units + 325, Units + 405,
Units + 326, Units + 406,
Units + 327, Units + 407,
Units + 328, Units + 408,
Units + 329, Units + 409,

  };

  /* Weigths definition section */
  static float Weights[] =  {
1.550070, 0.987240, -0.261150, 0.682930, 0.792180, -0.649760, 0.224690, -0.597410, 1.314020, -0.437370,
1.172430, -1.557850, -0.368310, -2.218100, 0.376230, 0.317350, 0.162110, -0.814650, 0.345630, 0.320900,
-0.162030, -0.837180, 1.360450, -0.387430, -0.739750, -1.644350, 0.930290, -0.839780, -0.114910, -0.820440,
0.719480, -0.815860, -0.839710, -0.838430, 0.560860, -0.123850, -0.472440, -0.702340, -1.348610, 0.696040,
0.252410, 0.022070, 0.560170, 1.493050, 0.460090, -2.176420, 1.004520, -0.803980, 0.034170, -0.173270,
-0.253660, 0.555900, 0.692950, 1.163150, 0.104200, -0.119280, 0.605110, -0.987490, -0.670170, -0.880380,
-0.020300, -0.113820, -0.040850, 0.712050, 1.244380, -1.340370, 0.605280, 0.180760, 2.457210, 0.416370,
-0.370090, 1.392860, 0.297190, 1.151030, 0.006130, 0.168020, -1.591860, 0.090390, 0.488760, 0.651690,
0.287600, -0.732010, 0.239600, 0.407550, 0.279460, 0.443900, 0.604230, 0.155000, -0.702670, 1.021680,
-0.692950, -0.588860, -0.592830, -1.103040, 1.565270, -0.179750, 1.875030, 1.176500, 0.685900, -0.152550,
-0.405780, 2.621340, 0.138900, 0.390010, -0.380120, -1.252150, 0.089950, -0.281240, -2.420730, -0.362070,
-0.258890, -0.889710, 3.953080, -0.951090, 0.526940, -1.314660, -3.157060, 0.409860, 0.279080, -2.992080,
1.705480, 3.165600, -1.623860, -2.299280, -1.695230, 1.288040, 0.304840, 0.210770, -4.159180, -0.000420,
-3.339440, -0.427070, -4.559050, -0.571780, -0.963580, -9.047310, -1.939580, 2.318890, 0.754620, 0.737290,
0.217610, -0.127320, 1.111480, 1.613820, 1.413850, 0.987210, 2.210880, 0.338280, -0.012710, -0.704160,
0.143950, -0.736470, 1.149970, -0.498140, 0.646220, 1.400800, -0.337120, 0.583120, 0.569440, -0.889570,
3.384460, 1.291740, 1.315450, 1.119600, -1.051030, 0.884740, -0.311650, 1.125290, -1.078620, 0.185000,
-1.205690, -0.152290, 0.481940, -1.300960, -0.698540, -1.389560, 0.086620, -1.634110, -0.651110, -0.610730,
-0.369890, 0.567510, -1.251340, -1.098360, 2.224580, 0.599170, -0.308620, -0.386080, 0.765550, -1.663000,
-0.291800, -0.796560, -0.769480, 1.541200, -0.035760, 0.465640, 0.623310, 0.426900, 0.171740, 0.074800,
0.579250, -0.692540, -0.297680, -2.283630, -0.374440, 0.221000, -0.498740, -1.495450, 0.736000, -0.438470,
0.777130, -1.537540, -0.014280, 0.736890, 0.340810, 1.450240, 0.988030, -0.601200, -0.826120, -0.586100,
1.213660, 0.657570, -0.248930, 1.064420, 0.132920, 1.014110, -1.521730, -0.162150, 0.310620, 0.698090,
1.175320, 0.498070, 0.779820, -0.686950, -0.319770, 1.512010, 0.188600, -0.980660, 0.349830, 0.380340,
0.170250, -1.794940, 0.329330, 0.365790, -0.830800, 1.147730, 0.012790, -0.470840, -0.476840, 0.049720,
0.373260, -0.874990, 2.263010, 1.649510, -0.188560, 1.814490, -1.432410, 0.921320, -0.114210, -1.647710,
-1.190360, 0.589990, 0.779380, -0.257440, -0.526760, -1.187940, -0.886420, -0.816390, -0.843930, 0.217820,
-0.170470, -0.441200, -0.343390, -0.574760, -2.008990, -1.135380, -2.286470, -0.989540, 0.224820, -1.229510,
-1.573390, -0.459790, 0.444710, 0.105860, 0.549020, -0.740740, -0.226680, -0.448270, 0.014880, -0.853080,
-0.813800, -1.205830, -0.891480, 3.834700, -1.043240, -1.033350, -0.088440, -0.329990, -1.058350,
0.794570, -0.158810, -1.292050, 0.986340, 0.043300, 0.863010, -0.266040, -0.528900, 0.892950, -1.498590,
1.116130, 0.041450, -1.044960, 3.650030, -0.763590, 0.022220, 0.339100, -0.707100, 0.097230, 0.726850,
-1.117610, 0.104770, -0.517250, 0.706050, 1.005650, 2.828600, -2.864510, -0.404080, -0.977910, 1.778850,
1.241350, -0.325210, 0.117930, -0.594470, 0.312550, 2.748350, -0.285190, 0.285690, -0.336380, 1.407690,
0.495520, 2.480430, 0.684980, 1.684870, 0.481060, -0.483150, -1.068990, -2.163860, 0.314060, -2.730200,
0.193280, -0.902490, 0.409870, -0.092780, 2.355590, -2.566620, 0.855900, 2.700850, 1.758930, 0.549300,
-0.286830, -0.041110, -0.382800, -3.618060, -0.846370, 2.339120, -0.445880, 0.830140, 2.426040, -0.961980,
0.794520, 2.171530, -0.275460, 0.881910, 1.659470, -1.530460, 1.087500, 1.039400, 1.181380, -0.664000,
-1.128060, -0.714170, 1.800800, -0.338980, -1.906980, -1.667420, 0.217450, 1.556460, 0.057840, 0.553110,
0.545030, 0.078550, -0.430830, 1.182640, -0.238490, -0.749620, 0.202020, 1.272130, 2.249920, -0.070390,
-0.050180, 2.582970, -2.999730, -0.448060, -1.230090, 1.403170, -1.237690, 1.261270, -1.063450, 1.134620,
0.100760, 0.496640, 0.983760, -0.762150, 1.469080, 0.642070, -1.501010, 0.214800, -0.019850, 1.349870,
-0.249330, 0.803900, -0.666780, 1.866110, 0.454160, -0.173330, -0.066630, 2.001120, 1.422980, 0.386950,
1.951080, -0.535330, 0.935950, 0.396510, -0.453360, -0.065750, -0.150470, 4.971960, -1.593670, 0.426400,
0.180270, 0.302580, -0.330270, 0.479510, 0.343920, 2.288350, -2.421420, 1.233010, 0.837870, -0.690970,
-0.859880, -1.626590, -2.458680, 1.237120, -0.073260, -2.207090, -1.383930, -0.568770, 0.640390, 1.720030,
2.860060, -2.209630, -0.138240, -0.007760, -0.255370, -0.726380, 0.052230, 0.669050, 0.895230, -1.173380,
0.724740, 4.155410, -0.597570, 2.885230, -0.511710, -0.158770, 0.781540, -0.007970, 1.094710, 0.452120,
0.179940, -1.437780, -1.050870, 2.106450, -0.420920, -1.862070, -0.585800, 1.351920, 1.240650, -2.478230,
-0.397100, 1.104340, 0.682280, 0.483040, -0.965350, -1.183110, 0.259180, 0.717360, -0.241380, -0.978700,
-0.469680, -1.134140, 0.249760, -0.855160, 1.222440, -0.073400, 0.057170, -3.081320, 0.623720, 0.502000,
0.672810, 0.842500, -0.562130, -0.980840, 0.259090, 1.235040, 0.030640, -0.597490, 1.301340, 0.203560,
1.268360, -0.302190, 0.601500, -0.873300, -0.613240, -0.457840, 0.266920, 2.204800, 0.803070, 5.508660,
0.486060, -0.020870, 0.093870, 1.802910, -2.008830, 0.904390, 0.822060, -1.284910, -0.477820, -1.320920,
0.740220, -1.450170, -0.965760, -0.197730, -0.383680, -0.932200, 0.231940, -0.837070, 0.174250, 2.451070,
-0.511420, 0.551750, 1.167280, -0.131030, -0.046250, 0.137000, 0.465750, -1.027010, -0.038020, 0.223140,
4.343190, -0.026300, 1.792480, 0.063870, 0.777450, 0.029860, -0.490210, -1.150690, -0.197990, -0.365230,
-0.094830, -0.561310, 0.806580, 1.214030, 0.352630, 0.674150, -0.096740, 0.247150, 0.817870, 0.748430,
0.074980, 0.874180, 0.562970, -0.543880, -0.013380, -0.129170, -0.316970, -0.238630, 0.113120, -0.063690,
-0.571730, -0.582500, -0.628750, -1.912360, -0.711580, -0.626150, -0.288710, 0.328900, 0.336830,
-0.713120, -0.850180, -0.590780, 0.519890, 0.018610, -2.422640, -0.353160, 0.524760, -0.172450, 1.154630,
-1.025050, -0.188940, 1.639390, -0.633210, 0.140690, -1.005350, -0.512750, 0.040000, 0.561740, -0.936100,
1.158410, 2.244790, -1.307630, 0.837800, -0.562000, 1.390290, 0.199970, -0.416350, 0.180330, 0.624480,
-1.493130, -0.478540, 0.168360, -0.978360, -1.516900, 1.035480, -1.069060, 0.099400, -2.214480, -0.398020,
-0.821240, -0.756130, 0.731750, 1.606430, -0.723000, -2.102890, 0.881440, -0.358500, 0.570150, 0.938570,
0.365270, 0.236300, 0.060020, -2.506790, -0.209630, -0.264350, 1.137890, 0.444060, 0.529800, -1.129400,
0.846010, -1.123470, 0.480710, -0.059210, 0.388000, 0.135060, -0.210470, -0.556000, 0.518230, 0.788040,
-0.750850, 0.273850, -1.202330, -0.417380, 0.574520, 1.240740, -0.120430, 1.149860, -0.495420, 0.403280,
1.009980, -0.009510, -0.832950, 0.757530, -0.305570, 0.801100, -0.415780, 1.340770, -0.847670, -3.465550,
-0.487810, 0.051230, 0.164730, 1.616030, -0.767760, -0.574140, 0.073700, 0.223310, 2.892830, -0.877450,
-0.000660, 0.066190, -0.789680, -2.290470, -0.205860, 0.731380, 0.077290, -0.207360, -0.258170, 0.421990,
-3.405150, -0.989160, 1.136740, 0.795090, 0.869380, 1.427480, 1.115570, 2.252240, 1.071860, 0.366560,
0.086200, 0.929710, -1.484050, 0.086070, 0.658550, 0.423970, 0.407690, -3.415300, -0.373040, -0.687960,
-1.061280, 0.585110, 3.151340, -1.115120, -0.807370, 7.785320, -2.749620, -1.135470, 0.398190, -2.885810,
-0.281310, 0.789560, 1.027950, -1.530640, -0.030780, 2.272610, 0.410120, 1.169540, -0.414000, 0.778110,
-1.687290, -1.661180, -0.743160, 0.525060, 1.726890, -1.971700, -0.574190, -1.359140, 0.832910, -0.648220,
0.430610, 0.817820, -0.326330, 1.635050, -0.637020, -0.936210, -0.118950, 0.521710, 0.487570, -1.774790,
-0.572220, 0.906450, -0.706420, 0.638550, -0.851950, -0.594290, 0.569130, -0.951370, 0.320820, -0.019290,
-1.342320, -3.183300, 0.406030, 0.439890, 0.388400, 1.756480, -0.554500, 0.638160, 0.723840, -0.213540,
0.408720, -0.363690, -1.052240, -1.297680, -1.334980, 0.871210, -0.018530, -0.165170, 0.823940, -0.556810,
0.717640, 0.809670, -2.057040, -0.130050, -0.853870, -0.153990, 1.447010, 0.718700, 0.917750, -0.198750,
0.309480, 0.685670, -0.037960, -0.333170, -0.256000, -0.401280, 1.128060, -0.801920, -1.274720, 0.886980,
-0.386190, 0.044860, -2.218620, -0.487790, 1.000620, -0.164390, 0.674340, 0.569650, 0.915830, -0.057940,
0.128600, 1.138840, -0.589140, 1.144050, 0.001690, 0.855870, 1.065740, -1.348750, -0.079160, 0.644500,
0.389320, 1.965340, 0.748150, -1.217690, 1.640460, 0.229010, 1.724120, -0.310900, -0.694560, 0.033220,
-0.538440, 0.595660, 1.206260, -17.426060, -0.028870, -1.422740, 0.413280, 0.584250, 0.056610, -2.818610,
-0.077420, -0.462890, -0.490160, 0.747870, 3.611250, 0.231310, -0.992620, -0.830750, 0.167490, -0.008230,
-0.129100, -0.448580, 0.510560, -1.452030, -1.333970, -0.326390, -1.529210, -1.775590, -1.675030, -1.083960,
-0.985060, 0.420490, -1.842750, -1.129820, -0.871390, 0.365980, -0.542760, -0.493830, -0.202580, -1.352260,
0.014750, -1.963270, -1.823980, -1.295440, -1.523430, -1.226520, -1.722740, -1.198970, -0.668210,
0.864590, -0.811340, -0.034380, -0.051220, -0.686840, 0.256160, 1.125190, 0.538150, -0.824740, 0.275450,
0.268720, 0.957550, -0.815840, 0.875130, 0.906680, -1.961690, -0.768430, 0.467350, 1.660140, -0.954470,
-1.882950, -0.678500, 0.551490, 0.242100, -0.153010, 0.276210, -0.185850, -1.362630, -0.164480, -0.243940,
0.959440, -1.161000, -0.105880, -0.122730, 0.332660, -0.811780, -0.385980, -0.386320, -0.146170, -0.984760,
1.330530, -1.106100, -2.000820, 0.084800, 1.185250, 0.550640, 0.812400, 0.086570, 0.741690, -0.080680,
-1.288000, -0.905530, -0.909490, 0.052370, 2.785500, 1.237130, -0.251340, -0.485450, -0.799970, 0.326440,
0.549480, 0.695640, -1.566530, -0.924260, 0.104090, -0.169480, 0.378910, 3.830800, 0.672790, 0.755640,
0.602100, 0.140220, -3.814040, -0.158030, 0.863640, 0.708090, 0.838660, 0.999720, -0.304090, -0.209230,
-0.368930, 0.245260, -0.444180, 0.522050, -0.230590, -0.196810, 0.122100, -0.505320, 0.792220, -0.772170,
-0.157470, -1.317110, -1.302840, -3.329030, 0.580220, 0.043000, -1.475090, 0.829000, -0.440450, 0.042610,
0.054640, -0.021700, 0.244930, 0.451250, -0.408080, -0.217280, -0.518470, 0.081200, 0.245430, 1.060310,
0.528010, -0.052610, -1.424590, 1.048570, -0.431550, 0.243680, 0.046280, -0.150010, 0.940580, 2.815990,
2.508980, -1.406350, 0.985310, 2.607460, 2.305320, -0.174210, -0.167410, -0.911980, -9.689070, -0.220920,
-1.997590, -1.263150, 4.967700, 2.380730, -0.623800, 13.367460, 0.574670, 0.992420, 1.109930, -0.325990,
-0.478600, 0.432990, -0.017990, -0.013170, -1.038730, -0.713840, -1.077310, 0.965470, 0.090510, -0.712440,
-0.471190, 1.178920, 0.015450, 0.202910, -0.982690, 0.090950, -1.020140, -0.080750, -2.550960, 1.214080,
0.452720, 0.265950, -0.303960, 1.168390, 0.626650, -0.544510, 0.074290, -0.523960, 0.479190, 0.062030,
-2.704300, 0.168510, 0.468730, -0.140440, 0.876170, 0.563560, 0.169860, -0.255640, -0.379510, 0.099590,
0.352420, -3.593260, -0.373350, -0.889760, -0.356380, 0.311150, -0.311810, -0.927710, -0.617590, -0.243340,
-0.948760, 0.269420, -0.019290, 2.021810, -1.116670, -0.760320, -1.325590, 0.117010, -0.697100, -0.337420,
-0.679520, 1.552600, 1.119310, 0.350980, 0.475660, 1.427320, -0.993380, -0.807640, 0.175090, -0.622170,
1.514010, -1.092810, -0.789120, -0.282540, -0.010310, -0.330280, 0.579340, -0.370430, -0.056120, -0.174370,
-0.152440, 0.094150, 0.249460, -1.734490, 0.214920, -2.098400, 1.098740, -0.004020, 1.008760, 0.871470,
-0.776870, 0.276080, 0.598590, -1.262180, 0.908070, 0.793810, 0.307850, 0.689530, 1.568480, -0.039970,
0.178720, -0.694320, -1.027240, 1.018070, -0.184430, 1.192990, -1.118680, 0.733430, -0.378990, 2.279510,
-3.579830, 0.879690, -1.089610, -0.849670, -0.081730, 0.467550, -0.020980, -0.436240, -0.282910, -3.700990,
1.478230, -1.099050, -1.801390, -0.735510, -0.663500, 0.990680, -0.427770, 0.079110, -0.727590, 0.089100,
-0.456620, -0.918680, -0.864650, 0.020220, -1.128000, 0.112590, -0.652350, -0.780070, -0.570400, -1.161470,
-0.049470, 0.195740, -4.269030, -0.410490, -0.931620, -0.231110, -0.796550, -1.172500, -0.929410, -1.072480,
-1.017600, 0.166710, 0.493280, -0.239270, 0.414620, 0.527570, -0.821370, -1.006670, -0.580860,
-0.417120, 1.106020, 1.100460, -1.982230, 0.364350, -0.820780, 2.180790, 0.426480, -0.609850, -0.840360,
2.067060, -0.728250, 0.686040, -0.359370, 0.555660, -1.052950, 0.369230, 0.650480, 1.050780, 0.270520,
-2.776390, 1.001940, -3.433480, 0.334230, 0.688230, 0.295780, 0.200210, 0.016790, 2.387200, 0.283460,
-1.750900, 2.022290, -0.252130, -0.072100, 1.437530, 0.901220, 0.713230, 0.212200, 1.297710, 1.527850,
0.340560, 2.036600, 1.825090, -2.385710, -1.322450, -1.456320, -0.608660, 1.038420, -0.439500, 0.190440,
1.184540, -1.020480, 0.670100, 0.464050, -0.613060, 0.530140, -0.558260, -1.188290, 0.534230, 0.743940,
-0.524700, 0.908380, 0.405580, 0.715630, 0.626500, 1.121250, 1.086540, -0.650820, -0.981360, 3.248500,
-0.818240, 0.369580, 0.875040, -0.403070, -1.017180, -0.043220, 0.313400, 1.412130, 0.248000, -2.227460,
1.222370, -1.212990, -1.284130, 0.816840, -0.751130, -1.296140, 0.783960, -0.019450, 0.030890, -2.692410,
0.947050, 1.317670, 0.425000, 0.875720, -0.117870, 0.734990, 1.834180, -0.518050, 0.622770, -0.373200,
1.565020, 0.746490, -0.505690, 0.535180, 0.037500, 1.309250, -0.310690, -0.094630, -0.789150, 0.791430,
2.029960, -0.103040, -1.268710, 0.629340, 0.162400, 0.780440, 3.429760, 0.969130, -3.520910, -1.070710,
0.593190, 0.513100, -1.767080, -0.037150, 0.540370, -1.004990, 0.102330, -0.540160, 5.165680, 0.309080,
0.332640, -1.089990, 0.370070, 0.268960, 0.206770, 0.627290, -0.658360, -4.686850, 0.425000, -0.343770,
-0.762970, -1.226150, -0.101670, -0.154940, 1.019740, -0.981780, 0.982430, 0.613510, 0.751690, -0.101660,
-0.122780, 0.940600, 0.150550, 1.495370, -0.003490, 2.017630, 2.939360, 0.255050, 0.226570, -1.751210,
-1.402550, 1.492540, -0.139590, -0.680310, -1.020380, -1.958810, -1.393400, -0.134660, -0.134190, 1.711440,
-1.429530, 1.225090, 0.955650, 0.046960, 4.734630, -1.128500, 0.236030, 0.303530, -1.954940, 0.352620,
0.151530, -1.735820, 0.598420, 0.359540, -1.218550, 2.151390, -2.601110, -0.590280, -0.004980, -0.831670,
0.384800, -0.345730, -1.639050, 0.928400, -0.196890, -0.027800, 1.488740, 1.200900, -0.954210, 0.929710,
-0.427800, 0.384550, -0.890810, 1.577480, -0.257280, -0.362400, -1.175930, -1.307620, 2.225410, 0.838780,
0.124670, -2.033020, 0.011080, -0.032020, -0.458260, 0.041340, -0.057300, -0.214200, 2.243280, 1.017320,
0.819120, 0.916210, -0.440750, 1.001580, 0.932910, -0.239780, 0.880460, 0.041370, 0.257740, -2.082550,
-0.037610, 0.436320, 0.519480, 1.303570, -0.611860, 1.560300, 0.052050, -0.956620, -0.072930, 0.533760,
1.103620, -0.897010, 1.575020, -1.597890, -0.613580, -0.643930, 1.480090, -0.059040, -0.265680, 0.361290,
-3.227310, -0.911780, -1.127040, 0.357090, 0.789430, 2.474350, 0.677190, 4.288660, 0.557960, 0.733170,
-0.678820, 0.853710, -0.731860, -0.422180, -0.748640, 0.540630, 1.130020, 0.381000, 0.275090, 0.305700,
-0.233110, 0.048290, -0.830130, -0.089830, -0.705010, -0.673680, 0.744140, -0.732770, 0.295100, -1.045030,
-1.491260, -0.120550, -0.447640, -0.442640, -0.340810, -0.171790, -0.598690, -1.131060, -0.731270, -1.344590,
-0.715150, -0.229330, 0.187290, 10.487330, 0.697000, 0.715700, 0.925350, -0.588280, 0.756840,
-0.607510, -1.366000, -0.656020, 0.290700, 0.051510, 0.959750, -1.148180, -0.703200, 0.217620, -0.085460,
0.441140, -0.798880, -0.691440, -1.395480, 0.759680, 0.608260, -0.333400, -1.038730, -1.141750, -0.656530,
0.863290, -1.756660, 0.524530, -0.375280, 0.454830, -0.719350, -0.106850, 0.554440, -1.473570, -0.461880,
1.218860, -0.779590, 0.240050, -0.825720, -0.559890, -1.183300, -0.231700, -0.065270, 1.448040, -0.472470,
0.277120, -1.318370, -0.515170, 0.783660, 1.039370, 0.743540, -0.492510, -1.672010, 0.733000, 0.359730,
0.376200, -0.859740, -0.775330, -1.102130, 0.454630, -0.271400, 0.190040, -0.855510, -0.344660, 0.199210,
-0.306420, 0.195610, 0.824120, 0.388770, -0.868590, -0.074200, -0.139340, 2.095210, 0.006300, -0.571010,
0.086090, -2.137550, -0.335920, 1.577280, 0.025870, -0.246500, 0.270890, 0.371250, -1.423430, 0.263720,
-1.543610, 1.357770, 0.087090, 0.851870, -0.279970, -0.629820, -1.294190, 1.159790, -0.091330, 1.265580,
-0.056440, 0.395300, -0.176000, -0.264120, -1.516720, 1.391600, -0.734510, -0.577970, 0.807910, -0.630130,
-1.119000, 0.772270, -2.346460, -0.398500, -1.123740, 1.620560, -0.821870, 0.208030, 0.482170, 0.776500,
-1.141390, -0.209840, 1.020390, -0.689220, 0.076990, 0.498690, -0.559120, 0.362690, 5.867440, 0.308560,
0.262490, -0.839120, -0.490330, 0.029910, -0.728540, 0.065100, 0.434580, -0.541920, 2.060670, 0.726080,
0.202660, -0.562430, -0.079720, 0.875300, -0.068160, -0.409020, -0.813320, -0.919780, 1.257360, -10.818730,
1.145060, 0.869120, 0.140100, 1.538900, 0.236800, -0.032800, 0.393540, 1.817120, 2.354110, 0.962610,
0.243760, 0.120780, 0.072580, -0.187370, 0.571880, 1.579080, 0.979980, 0.528370, 0.127240, -1.028700,
-2.472450, -0.844330, 0.477020, -0.559760, -1.359470, 0.890500, -0.175600, -0.313370, 0.546750, -0.738820,
-0.480640, -2.254240, 0.160310, 0.693640, 1.568280, -0.578150, 0.408200, -0.424660, 1.131980, -0.462910,
-0.460600, -0.292020, -1.558750, -1.487760, 1.375210, 2.260560, -0.355260, -0.740130, -0.529010, 1.074770,
0.232090, 0.399240, -2.343080, -2.873060, 0.389060, 0.674190, -0.502950, 0.692350, 1.585280, -0.194750,
0.304540, 0.366010, -0.719300, -0.870180, -0.860470, 0.349240, -0.692050, 0.560490, -2.362550, -1.822730,
-1.996120, -0.028700, -0.136030, 1.073040, 0.912500, 0.162760, -2.223790, 0.371860, -0.142560, -0.128350,
-0.937010, -0.581430, -1.209820, -1.525260, 0.295240, -0.832280, 0.406540, 0.294490, 1.731010, 0.996250,
0.405500, -1.276050, -0.529750, -0.286610, 0.385730, -0.622470, -0.491080, 2.813260, 1.036670, -0.625550,
-1.704060, 0.829340, -1.334130, -0.272620, -0.232770, 1.210870, -0.797440, -0.494430, 0.749440, 0.427510,
0.130260, 0.905150, 1.163130, 2.406500, -0.392820, 3.881220, -0.463180, 0.467030, -0.725030, 0.150130,
-3.031940, -0.125370, -0.622210, -2.423730, 2.677140, -1.363660, -1.465940, -3.457990, -2.569500, -0.183330,
0.084730, -0.718070, -0.822360, 0.149250, -1.282550, -1.319330, 0.318740, -0.243420, -0.793050, -0.299330,
-1.495130, 0.005460, -3.297420, -0.577750, 0.381040, -0.982230, -0.731990, -1.989010, -0.514610, -0.733950,
-0.291310, -0.474600, -1.471970, 1.146920, -1.177610, 0.412420, -0.278660, -1.388360, -0.872700,
0.642300, -1.108170, -2.554650, 0.240600, 0.017370, 2.307730, 0.071530, 0.322390, -0.231550, -0.479020,
-1.259570, 0.381850, -0.471650, -1.085760, 0.591910, 0.934070, -0.275280, 1.504600, 0.263070, -0.581080,
-1.938310, -0.881280, 0.479460, -0.535100, 0.622200, -0.046870, -0.489210, -0.946670, 0.515730, 2.242730,
-0.463930, 2.170880, 1.419420, -2.344410, -0.345360, 1.390150, -1.541040, -0.070010, -0.579670, -1.035760,
-2.242530, 0.719440, 0.727920, -0.748520, 1.188870, 0.074260, 1.099480, 1.123570, 0.704570, -1.999950,
-0.443730, 0.591120, 0.787250, 0.684670, 0.427660, 0.533440, -1.442180, 0.267360, 0.836040, 0.812570,
-0.765730, -1.250680, -0.953490, 1.149570, 1.343090, 0.530010, 0.250750, -0.820330, 0.505400, -0.377590,
1.280300, -1.030490, 0.284180, 2.161400, 1.046790, 0.256220, -0.116040, -0.327220, 1.464900, 0.308730,
0.916040, 0.807530, -0.487130, 0.240990, -0.138790, -1.763240, -0.229440, -1.427700, -0.064370, 1.041710,
-0.414400, -2.577020, -0.661390, -0.331640, 0.005760, -2.204930, 1.427240, -0.135640, 0.411810, -1.160340,
-0.118500, 0.250340, 0.438150, -0.766040, 1.218120, 2.161340, 0.485390, -1.942050, -0.654980, 0.361160,
-0.380170, 0.001800, 1.343550, 0.982260, -0.106690, 0.387540, -1.732270, 0.323410, -1.126570, 0.908160,
-0.909280, 0.877760, 0.231800, 1.493360, -1.875160, 0.456980, 0.534000, 0.405950, -1.858390, 1.727680,
5.469800, 1.102450, -4.553010, 3.260240, 1.570220, -4.646870, -0.242200, -1.662130, 0.682120, 0.115260,
-0.871760, 2.523490, 1.025740, 1.482620, 1.208760, -0.123470, -0.006200, -0.093720, -0.793480, 0.132450,
0.789560, -1.604550, 0.582980, -0.814050, 1.266260, 1.228990, 1.339900, -0.560450, -0.742260, -0.922490,
-3.561780, -0.298760, -5.176170, 0.707330, -0.817510, -0.561310, 1.573710, 0.186200, -1.431180, 1.494220,
0.032350, 0.636180, 0.495290, 0.442620, 2.032710, 0.999670, 0.092480, 0.506290, -1.992290, 0.046890,
0.509610, -0.820590, -0.488570, 0.070910, 1.018630, 1.290100, 1.378470, -1.036910, -0.464770, 1.672680,
0.677490, 1.005280, -0.557360, -2.987220, -2.328650, 0.099210, -1.540510, -0.220310, -0.277420, 1.156250,
1.056110, -0.858210, -0.040110, 0.754460, -0.518240, -0.427260, 0.270760, 0.482080, -1.425770, 0.674150,
-0.420540, 1.010020, 0.385610, -0.416100, 0.591090, -1.074340, -1.727280, -0.469410, -1.402490, 1.982380,
-0.907910, -0.070850, -0.304600, -1.855330, -0.128100, 1.221390, -0.780510, -0.388170, 0.183460, -0.589910,
0.646980, 1.313900, -1.170790, -0.110060, -0.250140, 1.597710, -0.593010, -0.371210, 2.151500, 1.668530,
0.116890, -0.502150, -0.682130, 1.369130, -1.253190, 0.603860, -0.234270, -0.186030, 0.601350, 0.464580,
1.130420, -0.412190, -0.333530, 2.291670, -0.556690, -1.422840, -0.263920, -2.848060, -1.597850, 2.716760,
1.190290, 0.581170, 0.608140, -0.077940, -0.062500, 0.094440, 0.682450, 0.745270, 0.119220, 0.875080,
0.296410, 1.184870, -0.431390, 1.235960, 1.872920, 0.890320, -0.597270, 0.214400, -0.225750, 0.508770,
1.631990, 0.879520, -0.828420, 1.527600, 1.076940, -0.006280, 0.394890, 0.957740, 0.573960, -0.168130,
-0.266610, 0.609390, 1.528180, 7.296480, 1.008220, -0.091900, 1.368010, 1.283480, 0.634820,
0.353200, -0.744700, 0.476100, 0.072330, 0.748780, -0.332620, -1.665860, 0.117150, 1.035560, 1.663590,
0.307540, -0.037930, 0.050370, -0.671280, 0.557780, -0.510090, 0.073000, -0.239910, -1.571530, 1.178910,
-1.123920, 3.419630, -1.864910, 1.035210, -0.794110, -1.027830, 0.214710, 1.506420, 0.944560, 1.444460,
-0.851700, 3.236050, 3.218810, 0.653820, 1.167410, -0.157020, -1.731050, 0.417000, 1.309970, -0.639860,
1.596230, -0.296250, 1.415200, 0.309210, -0.690100, -0.333690, -0.680880, 1.381790, 0.254080, 0.253890,
0.246770, -0.841530, -0.656400, 0.477660, 1.711550, 1.336420, 0.720960, 0.331870, -0.834050, 1.002610,
-1.117270, -2.562900, -1.879310, 1.768800, 0.339970, -0.076460, -0.759890, -0.814690, -0.100600, 0.039020,
0.944680, 0.007850, -0.079020, 0.267020, -0.398750, 0.285230, -0.200580, -2.322130, -0.697190, -1.899070,
-0.329640, -1.560250, 1.337160, -1.058330, -0.965860, -1.257330, 1.838070, 0.352040, -0.216340, -1.641950,
-0.448590, -0.618640, 0.909800, 3.719290, 1.505940, -0.722530, -0.198640, 0.445990, -1.763210, 0.214400,
0.635340, -1.051200, -1.778650, 0.640800, 0.081220, 2.026180, 0.051840, -1.523650, -1.043980, 2.375200,
-0.338940, -1.561320, 0.372880, 1.614450, 0.553980, 0.519420, 0.676850, 1.267990, -1.070870, 2.177940,
-0.028890, -0.851150, 2.487430, 0.690170, 2.671850, -1.418930, -2.408790, 0.044220, -0.064380, 1.246040,
0.367470, -1.808380, -0.191750, -0.841190, 0.268680, 9.054940, -0.569730, 1.867110, 0.145680, 0.859050,
-1.460370, -0.841270, 0.233680, 0.284030, -0.696400, 1.095670, 0.668680, 4.086260, 1.382290, -1.250000,
-0.848620, -0.627130, -1.028520, -2.607870, -0.542970, -0.474430, -2.226170, -1.888170, -0.443190, 0.356170,
1.134610, -0.374010, -0.050810, -0.470860, -0.142250, 0.828270, 1.624180, -0.030570, 0.168190, 0.174480,
-0.036820, -3.641600, -0.056340, 0.764130, -0.729350, -2.689920, 0.560060, 0.532540, 0.950370, 0.694230,
-0.387430, -0.860240, 0.202700, -0.971560, 0.730050, 3.568320, 1.308630, -0.760690, 1.346370, 1.187370,
-1.260730, 0.735750, -0.283580, 2.924490, 0.164780, -1.158340, 0.093470, 1.551230, -2.621390, -0.541350,
-0.346690, 2.143370, -3.266320, -1.197420, 0.617120, -1.336350, -0.068990, 1.804290, 0.860970, -0.146620,
-1.409620, -0.866650, -0.503380, -0.926890, 0.636230, -0.119630, 0.700120, 0.283350, 0.248880, -0.435450,
-3.437880, -0.185170, 0.016740, 0.010500, 0.331700, 0.165190, 0.636780, -0.159470, 0.761070, -1.241620,
0.523620, 0.441420, -0.895290, 0.132460, -0.764290, 1.678380, -1.830420, 2.337770, 1.416130, -0.480770,
-0.414000, 0.756710, -0.832260, -1.940900, 0.275430, -0.253600, -0.672550, -0.438440, 1.613250, 0.140030,
-0.466680, 0.799540, -0.420720, -0.540940, -0.890310, 0.592640, 0.142540, -0.082310, -0.386680, -0.750070,
-0.080610, 0.835510, 0.165160, -0.940640, 2.583550, 0.721680, 0.304920, 0.033460, -0.384590, 0.725600,
0.356430, 0.808930, 1.321600, 1.483850, 1.163090, 0.930220, 0.135750, -0.609710, -0.862540, -0.057140,
-2.432520, 0.527880, -2.547850, 0.680790, 1.317310, -0.528130, 0.549960, 0.217810, 0.450150, 0.444480,
0.680840, 0.062900, 1.025380, 0.380110, -0.671190, 0.841640, -0.291710, 0.573600, -0.291560,
0.176940, 0.797810, 0.522120, -0.063380, 0.621230, 1.339740, -1.182100, -0.302710, 2.010020, 0.550030,
-0.116000, 0.582620, 0.281170, 3.433940, -0.754240, -0.029000, 1.399230, 0.164330, -0.226080, 0.574410,
0.577610, 0.178740, -0.853580, 1.031230, -0.857750, -1.643770, 0.142530, 0.598780, 0.326960, 1.041610,
0.113490, -0.211890, 1.739490, 3.134220, 1.899800, 1.410400, 0.805120, -0.166580, 1.120190, 0.802920,
-0.834810, -0.997930, 0.918680, 0.214790, -1.868720, -0.803780, 1.013960, -0.487370, -0.668230, 0.093450,
0.060330, -1.888280, -0.083270, -0.512510, 0.317570, -2.201390, 0.456400, -0.192070, 0.316980, -0.309200,
0.529450, 2.180150, -1.055930, 0.377100, -0.399050, 1.606330, -1.949270, 0.059380, -1.522650, 0.474970,
-0.382980, 2.625860, 1.276020, 1.466130, -0.148660, 0.845450, 1.068270, -2.419090, 1.013350, 1.574710,
-0.288580, 1.105700, 1.268550, 0.738920, 0.258660, -1.115350, -1.226430, -0.587520, 0.336930, 0.240160,
0.050590, -0.457100, 1.140610, -0.138390, -0.313140, 1.670930, 0.264870, -0.085840, -1.169160, -1.520280,
-0.583600, 0.286820, 0.252160, 0.020750, 0.127300, -1.515710, -1.151260, -0.463900, 0.745330, -1.200590,
0.432800, 0.047870, 0.084880, 1.314420, 0.313100, 1.108310, -1.096000, -0.743140, 2.115600, 0.846680,
0.033860, -1.088900, 0.646730, -0.341700, -1.043660, -0.479100, 1.725650, -1.193570, -0.977160, 0.337190,
0.690060, 0.472880, -1.211040, 0.518270, 0.282590, -1.673950, 0.742370, 0.260500, 0.489040, 0.371660,
0.464680, -0.550780, -0.599790, -2.316890, 0.813430, -0.163240, -1.447390, -0.163330, -0.209390, 0.341030,
-2.405260, 1.855200, -1.177430, 1.374810, 2.745650, -1.421670, 0.951450, -0.236100, -0.015210, 0.039060,
0.536330, 0.585040, -4.933780, -1.234490, -0.701200, -1.624920, 1.071230, -2.228460, -0.560190, 0.297560,
1.409900, -0.050700, -0.748640, -0.397840, -2.056880, -0.482700, -0.772610, -0.886900, 1.255540, -0.139780,
1.161590, 0.799100, 0.492590, 0.567740, -0.346040, -0.960570, -0.490840, 2.236230, 1.207660, -0.366540,
0.524190, 0.842040, 0.753700, -0.377170, -2.986860, 0.663780, -0.310570, 1.526530, -0.187540, -1.170720,
-1.354680, 1.217470, -1.191460, 0.723980, -1.206790, 1.487420, -0.669520, 1.638870, -0.014670, -0.616690,
0.146020, 1.090130, 0.548530, 2.659550, -0.093830, -2.372700, -0.894040, -1.174090, -1.060280, 0.510690,
-1.763080, -0.411810, 1.459780, 1.698700, -0.514710, 1.709610, 2.154320, -0.372470, 0.200870, 1.286590,
-0.632360, -0.714730, -0.013240, 2.063990, 0.168760, -0.736950, 1.050220, 1.160910, -0.486430, -0.874720,
-0.266180, -0.326330, 3.212780, 0.580570, -0.088820, -1.389400, -1.322770, 1.219760, 0.893890, 0.554890,
0.016350, 1.101580, 0.446220, -5.773920, -0.855320, -0.782440, 0.280590, 0.592900, -0.482960, -0.168900,
0.506820, -0.125040, 2.927800, -1.419170, -0.007180, 0.182900, -0.695510, -0.386660, 0.517120, -0.127790,
-0.564550, -0.508660, 0.651610, -0.457250, 0.352080, -0.385260, 0.864240, 0.316000, -0.776790, 0.601440,
0.539590, -0.251590, -0.702500, 0.403440, -0.442290, -0.637790, -0.441760, 0.167420, 0.755330, 0.178380,
0.313440, 0.941310, -0.661680, 1.059770, 0.884710, -0.900650, 0.796690, 0.104540, 0.397970,
0.333710, -1.697090, 0.375390, 1.051370, 0.404300, 0.768500, -2.555310, 0.753200, 0.608430, 0.196150,
2.054790, -2.062340, 2.037250, 0.561100, -0.373010, 0.823850, -0.545920, -0.000260, 0.594170, -1.716370,
-1.016490, 0.167280, 0.819680, 1.017970, 0.256690, 0.332950, 2.617970, -0.770150, -1.881670, 0.437170,
1.468100, -1.170460, 1.171780, -0.129150, 0.213290, 0.561110, 0.990460, 1.610200, 1.015960, 0.766710,
0.450610, -0.245500, 2.302360, 0.218920, -0.278470, -1.454380, -0.269090, 0.289360, -0.240400, 1.271250,
-0.432470, -0.797000, 1.438850, -0.737810, 0.070170, 0.069160, 1.977190, 1.668260, 1.123530, 2.004510,
0.228780, 0.553410, -0.684610, -0.494430, 0.734850, 1.292500, -1.803430, 1.198390, 0.214850, 1.223240,
-0.528660, 1.421800, 1.495720, -0.378480, 1.507490, -0.557920, 0.181390, 1.177320, -2.539410, -0.066970,
-1.771540, 2.707400, 0.913230, 0.192670, 1.112520, 0.518170, 0.913140, 1.407030, 1.449280, -1.054490,
0.627180, -1.301790, 0.054420, 1.533410, -0.940270, 1.666050, 1.126370, 0.780840, 0.123220, -0.471760,
-0.150010, -0.065960, -3.893380, -1.154810, 0.541490, -0.805610, 0.032590, 0.199250, -0.482970, -0.882450,
-0.275640, 0.034410, -0.116690, 0.671750, -0.988650, 3.274330, 3.081010, -1.161370, -0.651300, -0.323040,
0.774480, -2.400790, -2.860680, 1.195660, 2.082170, -0.994790, -2.390930, 1.480940, 2.916740, 0.921380,
0.032090, -1.474700, 0.945030, -0.929160, -4.246660, 1.530010, 0.047620, 2.865260, 0.068480, 1.274660,
-0.531770, -0.384120, -1.985140, 0.311050, 0.566980, -3.417210, -0.070830, -0.663540, 0.309180, 1.020260,
0.705050, 2.268110, -0.842450, 1.120160, -1.790930, -0.571640, 1.006420, 1.651530, 0.435050, 0.453710,
0.210250, -0.519080, 2.645240, -3.366000, -0.881260, -0.734640, -0.910850, 0.228630, 0.015430, -2.255490,
-0.489900, -1.784370, 0.379730, 0.717960, 1.922660, 2.690160, -1.071980, -0.139750, 0.895310, -0.109750,
-0.389280, -1.217780, 0.391600, -1.221940, 1.645270, 0.767470, 0.409920, 0.123270, -0.150220, 1.619610,
-1.550010, 0.305280, 0.390280, 1.994480, -1.126440, -0.159050, -1.704650, 2.499050, 1.159520, -0.440710,
1.757410, -0.056630, 0.162790, -0.430360, -0.013880, -1.018380, -2.671860, -0.333970, 1.033430, -0.722110,
-1.004890, 0.345650, 0.770370, 0.658870, 1.981450, -0.946790, -0.250570, -2.047560, -0.063610, -0.250070,
1.976230, 2.086860, -1.841620, 0.362240, -0.452790, 1.093560, 0.569990, 0.865350, 0.078860, -0.107440,
0.011570, 1.283700, 1.903990, -1.592860, -0.477760, 0.678830, -0.772700, -0.635200, -0.855080, -0.179080,
-0.369790, 0.820170, 1.586410, 1.463580, -1.872340, -0.931830, 1.366440, 0.529320, -0.759220, 1.430460,
-2.319800, -0.191860, -0.699780, 3.379390, -1.205430, -1.331130, 0.597310, -2.306390, 1.430080, 3.022890,
-2.108950, 0.975980, -2.833610, -1.211370, -0.633230, -2.099780, 0.543160, 0.739230, 1.155000, -0.051270,
-0.251160, 0.631280, 2.101420, 0.599340, 0.564270, 0.994310, -0.132620, 0.617570, -0.798510, -0.892950,
-0.123910, 3.095490, 0.426730, 1.187110, -0.066770, 0.886710, -0.285630, -0.125420, 0.692040, -0.880760,
-0.261500, 0.637430, 0.538630, 8.196020, 0.520430, 0.018030, -0.397350, -0.664760, 0.106010,
1.525130, 0.638080, -0.931480, -1.310400, -0.962910, -0.928010, 0.913460, 0.110970, -0.189940, -0.565900,
-1.220830, -0.410510, -1.555580, 0.463420, -1.427240, 0.116470, 0.391770, -0.901110, -1.889670, -1.842060,
1.788940, -0.480520, 3.336870, 1.118620, 0.205380, -0.693000, -0.270270, 1.635260, 0.162940, -1.622680,
-1.354120, 0.028380, -0.153810, 1.468100, -0.608560, -0.741460, 0.996450, -0.781170, -0.975550, -0.218750,
-0.772080, -1.693550, -1.023080, 2.372000, -1.310180, -0.368930, 1.373380, -1.847520, 0.136240, -0.314480,
-1.268120, 0.173490, -1.968900, -0.060190, -0.970940, -2.149070, 1.293510, -0.711930, 0.373490, 0.265660,
-0.091410, 0.331240, -0.106580, -3.853630, -1.366570, 1.106810, 0.353970, -0.261810, -0.745980, 0.420650,
-0.228000, -1.454600, -1.493800, -2.456380, -0.169520, 0.786600, 0.134370, -2.423090, 0.077750, 1.030120,
0.215000, -0.405860, 0.503010, 0.026490, 1.020500, 0.019320, -1.306520, -0.547850, -1.074850, 0.486900,
1.020270, 0.649600, 0.813070, 1.010180, 0.119160, -0.996490, -1.115960, 0.066140, -0.670160, 2.101330,
-0.852120, 1.061060, -1.603840, -0.232140, -0.299360, 0.849360, -0.153370, -0.136720, 1.714410, -0.427680,
-2.749090, -0.401710, 1.846860, -0.689580, -0.829030, -0.637020, -1.198140, 2.205810, 0.545280, -3.294890,
-0.764540, 3.873430, -2.938420, 0.104440, -7.924350, -0.530960, 1.646720, -1.296750, -0.408530, 1.286010,
-0.049210, -1.378030, -6.320210, -0.086810, 0.362300, -8.710380, -0.098770, 5.160510, -1.947780, 0.657510,
-2.395410, -0.005850, 0.935090, 1.409060, -0.881490, 0.799660, -2.188630, 0.005380, -0.208710, -0.863540,
0.518060, -1.252450, -2.156330, 0.711760, -0.329440, -0.772050, -1.894180, 0.610610, 0.119970, 0.584380,
-0.748080, -0.593600, -0.330410, 0.761540, 1.193840, 0.479570, 0.307650, -0.668370, 0.198760, 2.542440,
-4.612900, 2.632890, -0.130530, 0.922450, 2.613800, -2.040280, -0.738610, 0.587850, -0.177810, -1.989870,
-0.939040, -0.628490, -2.478910, 0.775320, 1.007650, -0.440830, -0.566750, 0.125210, -0.596130, 1.877570,
-1.097980, 0.748390, 1.036270, -0.669390, -0.555630, -2.618800, -1.444060, 1.138180, 0.190480, 1.029470,
-1.751010, -0.428530, 0.065670, -0.133900, 0.912480, -0.179470, 3.029750, 0.874840, 0.169650, 0.581580,
-0.842280, 0.662770, 1.406850, -0.628510, 0.616610, -1.762340, -0.207230, -0.805760, 1.933470, -0.823620,
0.374310, 0.566220, -0.566050, 0.964080, -4.183060, -1.385530, 0.756850, -1.452040, -0.072950, -0.861020,
0.507610, -1.100390, 1.484510, -1.502460, -1.308160, -1.289920, 0.857840, -0.186580, 0.018090, -1.668470,
1.042470, 1.085500, -0.294790, 3.351650, -0.608920, 0.086150, 1.185950, -0.181300, 0.143650, 0.936780,
2.821080, 2.038300, -0.378460, -6.002540, -0.717500, -0.534060, 0.761650, -1.214500, 0.043020, 1.466480,
-0.638710, -0.579280, 1.008090, 1.657730, 0.138210, -0.898750, 0.061790, 1.306810, 1.457510, 0.199950,
0.821800, -0.778010, 0.844620, -0.545100, -1.516340, 0.034820, 0.588000, -0.283490, -0.236100, -0.975820,
0.145170, -0.838670, 1.440850, -0.160580, -0.919740, -1.117080, 0.301260, -0.541760, 0.316360, -0.030790,
-0.464480, 0.103110, 1.000140, -8.556590, -0.810360, -0.739440, -0.115110, 0.514620, 1.326570,
0.239030, 0.272010, -0.473400, 0.739950, -0.510510, -0.450740, 0.371520, 0.205290, 0.340190, -0.552810,
-2.104530, 0.223040, -0.436910, 0.878820, 0.901640, -0.302890, -0.367000, -0.569390, 1.736140, 0.635410,
1.077820, -0.426280, 0.531300, 0.148310, 1.414240, 1.039970, -0.201920, 0.003840, -0.149160, -0.387560,
0.080830, 1.653420, -0.171330, -0.247450, 1.545460, 0.502710, 0.538070, 0.279640, -0.958670, 0.838420,
-0.745250, -0.987030, -1.603760, -1.543420, -0.622380, -0.122360, 0.272240, 1.219600, 0.555010, 0.105540,
-0.314340, 0.337130, 0.709300, 0.238440, 1.831860, 0.311920, 0.255420, -1.911940, 1.993270, 0.636040,
1.072250, 0.992820, -0.480140, 0.639790, 1.261800, -0.878800, 0.097560, -0.814050, 0.562550, 1.832220,
1.271360, -0.312740, -0.244930, 0.514680, 0.325050, -1.574610, 0.116730, 1.238710, -0.655790, 0.475020,
0.167270, -0.278610, -0.428950, -0.302060, 0.968870, -0.203520, 0.813120, -0.142660, -0.242720, 0.651590,
-0.897080, -1.137600, 1.409390, -0.633470, -0.337910, -1.120680, -0.657880, -0.050210, 0.918230, 0.350920,
0.781370, -1.171030, 1.050760, -0.716540, 0.537290, 0.090630, -0.141730, -0.414350, -1.563140, -0.503360,
-0.497360, -0.123330, 2.399600, -0.934600, -0.354160, -0.242430, -0.552120, 0.889040, 2.681910, 0.406020,
0.176210, 0.037000, -0.641910, -0.701130, -0.600220, 0.430630, -0.401730, -2.337950, -1.758630, -0.537550,
-1.081870, 0.314100, -0.302740, -0.454930, 0.254690, -3.655250, -0.683010, 3.370050, 0.198890, -3.796040,
-0.154420, 0.486480, 1.954470, 1.192580, -0.617500, 0.128990, -0.996860, 0.231480, 1.508360, -0.482360,
0.449110, -0.414420, -0.365860, 1.909740, 0.911500, -0.387210, -0.240360, -0.190150, 0.764120, 1.195110,
0.796050, -2.401060, -1.513000, -0.365800, 3.707890, 0.372910, 0.503610, -0.801260, -1.647110, -1.985480,
-0.008960, -0.878410, -0.357530, -0.179780, -1.858640, -1.012760, 0.742090, 1.281560, -0.309130, 0.431480,
0.990300, 0.099280, -0.388810, -0.445280, -0.495220, 0.039850, -1.370650, 1.578080, -0.230020, 0.141920,
-0.704000, 0.412670, -1.512260, -0.029590, 0.908540, 0.530530, -0.771650, -1.469870, -0.368450, 0.598470,
-0.039940, -1.581830, 0.584600, -0.051990, 0.832560, 0.620830, 1.256000, 0.539700, -0.368270, 0.288900,
0.819960, -0.135290, -1.398770, -0.039240, 0.333440, 1.881970, -0.488710, 1.472680, 1.231200, -1.715040,
-0.549450, -1.673480, 0.644470, -0.535630, -0.366030, 1.743780, 1.492990, -3.066900, 0.358840, 0.428810,
-1.229190, -1.746900, 0.440080, -0.504070, 1.795850, 1.290180, -0.882300, 0.594890, -0.742440, 1.139550,
0.190300, -0.026940, -1.289530, -1.239690, -0.992410, 0.519060, -2.279030, -0.896640, -0.220970, 0.575290,
0.047280, -0.089580, 0.194460, -1.352600, -0.352370, -0.582780, -0.118720, -0.683420, -0.667800, 4.077810,
0.178970, 0.570260, 1.269870, 1.461820, -0.158220, -0.867740, -0.722420, -1.071790, -1.117880, -1.383800,
-0.888420, -0.675680, -0.516710, -1.722890, -1.125790, -0.826590, -1.274500, -0.494090, 0.356050, -0.879010,
-0.763030, 0.060630, -1.231900, -0.894120, -0.229920, -1.378940, -0.328920, 1.697430, -0.802930, 0.758720,
-0.850440, -2.399170, -0.319600, -13.514520, -1.650560, -1.111240, -0.670640, 0.439910, -1.189120,
1.643710, -0.367030, 0.706740, -0.812210, -0.550810, 1.921760, 1.562050, 1.071620, -0.266860, -0.813400,
0.511830, -0.126800, -0.414560, -1.447090, 0.965380, 0.119480, 1.088520, -0.041150, 0.254200, 1.521530,
-0.664000, -0.042170, -0.491460, 0.118010, 2.073670, 1.046960, -0.598650, -0.153760, 0.156070, 0.904170,
0.280980, -0.050190, -2.065520, -0.908830, -1.372500, -0.953030, -0.514730, 0.788770, -1.757400, 0.131110,
1.178650, 0.366990, -0.721430, -0.777910, -0.228510, -0.486070, 0.605150, 0.660890, 1.130290, -0.093520,
0.769080, 1.596270, 0.551870, -0.852570, -0.467660, 1.282880, 1.206340, 0.249190, 0.003250, -0.482340,
0.707620, -1.653090, -1.076180, -0.784640, -1.074140, 0.212890, 0.755500, -1.180150, -0.269990, 2.252740,
1.449130, -0.443170, -0.896490, -0.318280, 2.615770, 0.706680, -1.313380, 0.456970, -1.190520, -0.563830,
0.001850, -0.680480, 0.914280, -0.591920, 0.417880, -1.349380, -0.732710, -0.524470, -1.247530, -0.200630,
-0.690030, 0.750960, 1.082390, 2.051260, 0.306790, -3.018260, -0.195800, -0.085330, 1.520870, -0.162500,
1.329000, -2.134890, 0.238290, -1.395870, 0.123520, -1.070290, 0.480260, -1.592840, 0.134200, -1.018520,
-0.476030, 0.102550, -0.240660, -1.792020, 1.125910, 0.788850, 0.281030, 2.999030, -5.717720, 0.171050,
-0.163740, -2.532470, -0.249730, 3.190160, 6.843890, -1.430710, -2.979600, -0.798780, 2.753360, 1.013900,
0.616320, -4.792860, 1.577380, -0.187990, -3.011760, -0.390710, 3.633210, 1.189630, 0.028900, 1.635940,
-1.349130, 0.859290, 0.447660, -0.873590, 0.842440, 0.198690, 0.607390, 0.684430, -0.734430, -0.514160,
0.046130, 0.769680, 0.533870, -0.278890, 0.441240, -0.975250, 0.046200, -0.744990, -1.189770, -2.460090,
0.208610, 1.500660, 2.291980, -0.405320, -0.491890, -0.310350, 1.183550, -0.385200, 0.747630, 1.367620,
-0.733120, -1.304390, 0.053760, 0.237560, 0.380570, -1.067220, -0.988150, 0.683010, 0.689970, -0.271280,
0.064890, -1.136380, 0.075480, 0.690600, 0.376340, 2.124560, 0.894370, -0.502170, -0.354670, 0.608540,
-0.431950, -0.465740, -0.574860, -0.558470, 0.219950, -0.291540, 0.220730, 0.825340, 1.125710, -0.536930,
-0.299490, -1.783050, -2.324450, 0.803310, 0.269750, -0.844230, -0.554270, -2.030140, 0.428690, 0.199190,
-3.186580, 0.191310, 1.035560, 0.750150, 0.672300, 0.159260, -0.486140, 2.112620, 0.799660, -0.541830,
1.052580, -0.155850, -0.447640, 0.974100, 0.354610, -1.090700, -2.729070, -1.073740, -1.212900, 0.365860,
-0.662570, 0.741660, 0.151120, 0.282400, 0.503460, 2.278570, 0.475760, -0.304410, -0.084830, 0.306820,
-0.384070, 0.382910, 1.988690, -0.232180, -0.281630, -0.933720, -0.272130, -1.081490, 0.631960, -1.399240,
-1.352680, 0.124930, 1.284320, -4.219710, 0.982370, 2.194070, 0.329930, -0.445860, 0.651570, 0.551280,
-0.279240, 0.680420, -2.229540, 0.492210, 1.212810, 0.788020, 0.200630, 0.275800, -0.271130, 1.021650,
0.124710, 0.335710, -0.595680, 0.809850, -1.062530, 0.842330, 0.387590, 0.241240, 0.615900, 1.776610,
-0.394660, 1.207100, -0.999460, -0.004600, -0.822420, 0.683680, -0.848390, -1.316080, -0.688460, -1.434970,
0.001070, -0.110440, -0.952950, -0.307610, -0.122230, -0.045110, -0.720750, 0.741700, 0.731050,
0.191380, -0.107000, -0.579400, 0.591020, -0.207790, -1.735670, 1.448630, 0.208930, -0.016340, 0.358350,
-0.777480, 0.719090, 1.464410, 1.694610, 0.530120, -0.189850, -0.898640, 0.336350, 1.220430, 1.482510,
2.291380, -0.688630, -0.893730, 2.858730, 1.291440, -1.116460, 0.661970, -0.869380, 0.557740, 0.104910,
1.685710, 1.325550, 0.476470, -0.980280, 2.512900, 0.837410, 3.056580, 0.363170, -0.199260, -0.121430,
1.769610, 0.558820, 0.077670, 0.175840, -2.173730, 0.717050, -0.589520, 1.058540, 0.553220, 0.000670,
0.160870, 1.036300, -1.124350, 0.141290, 0.656380, -0.426870, -1.339710, 0.676980, -0.782210, 0.325250,
0.983610, -0.345060, -0.138650, 0.192610, -1.200130, 0.299610, -0.855390, -1.266560, -0.532490, 1.435110,
2.670090, 0.010370, -0.429820, -0.241450, -0.068230, -0.337780, -0.295230, -1.261610, -0.514370, -1.265160,
-2.199080, -0.817190, 0.630520, 2.989190, 1.465930, -0.181150, -0.028620, -3.246020, 1.644960, 0.453380,
-0.751630, -0.103590, 1.090770, 1.003330, -0.023590, 0.908500, -0.252200, -1.632630, -0.490540, -0.821580,
1.182260, 0.975550, -1.022150, -0.292080, 0.593200, 1.810920, 0.107380, -0.438510, -0.402440, 0.239040,
1.139800, -0.244340, 0.798780, 0.395040, -0.265660, -0.122070, -0.712150, -0.440010, 1.646340, -0.117280,
-0.006170, -0.690840, -0.606360, -2.879570, -0.038210, 0.974150, 0.289930, -1.827630, 1.171740, -0.775120,
-0.915080, -1.532120, -2.039310, 0.060840, -0.050700, -1.398670, 0.213660, 1.661050, -0.330460, -0.544940,
0.149260, 0.523860, -0.438750, 0.020480, 1.097410, -0.553710, -1.107370, -2.197130, -0.810500, 1.018270,
-0.782820, -1.015550, -0.595890, -0.302260, 0.161270, -2.048730, 0.571590, 1.698920, -0.706600, 0.858330,
0.034290, -0.632040, -3.625630, 0.698680, 0.292210, 0.030600, -1.315930, -0.592260, -0.311640, -1.476300,
-0.736000, -0.067030, -0.103330, 1.077710, 1.378600, -0.000050, -0.364610, 0.292690, -2.709000, 0.236390,
0.112290, -0.624000, -0.086320, 0.470980, -0.368900, 0.292710, -2.376530, 1.643220, -0.253220, -1.461390,
0.811250, 0.200430, 0.108510, -0.488860, -0.163340, -3.096790, 0.671830, -2.578560, 2.192890, -0.352570,
0.720420, -1.914770, -1.389720, 0.792680, 1.152220, -1.009570, -0.292870, -1.583740, 0.840670, 1.579510,
0.154020, -1.713740, -0.685760, 0.997260, -1.220480, -0.733870, -1.567240, 0.360670, 0.426890, -0.527430,
1.923700, 0.407330, 0.236760, 1.650650, -4.446650, 0.946580, 1.496670, 0.292500, -1.323820, -0.504230,
4.317370, 0.426260, -2.574890, 0.448110, -0.730870, -0.698100, 0.990250, -1.616420, -0.955320, 0.148880,
-1.727460, 0.604950, 1.651410, -0.985390, -0.307010, -0.277770, -1.598000, -0.376460, -0.405190, 0.035990,
0.837030, 0.987920, 0.499870, -16.320490, 0.826760, 0.978740, 0.247230, 0.384140, -1.989980, 1.691290,
1.126680, 0.055620, 1.181300, 1.003950, -1.078960, 32.825409, -2.449120, 0.137430, -0.948240, -0.106230,
0.348460, -1.481830, -0.379840, -0.483340, -0.494540, -1.419390, -1.499680, -1.170950, 0.424010, 0.687930,
0.359010, 0.014870, -1.200390, -0.181310, -0.291750, -0.421470, -1.126790, -0.482880, -0.539180, -0.474820,
-0.435680, -1.171290, 0.095500, -1.491820, 0.334190, -1.472460, -0.808680, 0.291230, -1.052410,
-1.472730, -1.433560, 1.330690, 0.593060, -3.178700, -0.365000, -1.438750, 1.871580, 1.871820, 0.412760,
1.193200, 0.883270, -0.108550, 2.485690, -0.311610, -0.587580, -0.335750, -1.267530, -0.920900, 1.395060,
0.567770, -0.483080, -0.438060, -0.230010, 0.281550, 0.900700, -1.887040, 0.718440, -1.114670, 0.129350,
2.035130, 0.091460, 1.079500, -1.566590, -1.593510, -1.783160, 2.605330, -0.425120, 1.629230, -1.363960,
0.661030, 0.598460, 0.413090, 2.385080, 0.059240, 1.765680, 0.031540, 0.797830, -0.127440, 0.336590,
1.121060, 0.138820, -0.100020, 0.565500, -0.010790, -0.050970, -0.674940, -0.292960, 0.919240, 1.502260,
0.046280, 0.065280, -0.933380, -0.442630, 1.224030, 1.749130, 0.423230, -0.371810, 0.821220, -0.537690,
3.033580, -1.832550, 1.067840, 0.898760, -0.287120, -1.705950, 1.162480, 0.361510, 1.430050, -0.204530,
2.148350, 0.767390, 2.978910, 0.113170, 0.431570, -1.265290, -0.597260, 0.789390, -0.835120, 1.863060,
-1.417330, 0.651120, 1.503740, 0.276470, 0.086220, 0.606890, -0.090850, -0.342690, -1.417620, 1.929360,
1.102270, -0.026310, -0.640970, 0.294110, -0.040090, 0.902620, 1.296170, 0.965170, 0.977620, 0.914370,
0.859650, -1.475670, 1.066190, -0.627570, 0.368010, -1.360560, 0.571010, -1.240580, 3.061890, -1.297220,
-0.555650, 1.538310, -0.144730, -2.157950, -5.896810, -0.034110, -0.527050, 1.587510, -1.432290, 0.037460,
4.239670, -0.254890, -4.415640, 0.164550, 1.095270, 0.865380, 0.952110, 3.825050, 0.132110, 1.796040,
-0.647350, 0.211470, -0.353040, 0.664450, -0.575340, -0.400710, 0.444430, -0.072230, 2.514460, 2.269940,
-1.381230, -0.329920, 0.046930, -1.390660, -0.469070, -1.175160, -2.811430, -0.036840, -0.162990, 0.718260,
3.755850, 0.934600, -0.333430, 1.692830, -1.556720, 0.083610, 0.480490, -1.256070, -0.205760, 0.014350,
0.812100, 2.012440, 1.535150, -1.948450, -1.034370, 0.872520, 1.905680, 0.296910, -0.517170, 0.176640,
-0.950030, 0.310360, -0.481870, 1.552450, 1.499480, -1.763440, 0.320980, -0.239760, -0.852330, -0.159530,
-1.316560, -1.161930, -0.905930, -0.844420, 1.178590, 2.261070, -2.450910, 1.392400, 0.991550, -1.146900,
1.347100, -0.604000, -0.029820, 0.367870, -0.260580, 0.737710, 1.664860, 1.512650, 1.100240, 0.165460,
1.973010, 0.996680, 1.206360, 0.327200, 0.839720, -0.619290, 0.071800, 0.524650, 1.817000, 2.939390,
0.693650, -2.681710, 0.511130, 0.247680, -0.249250, 1.773570, 1.779790, -0.082630, 0.870420, 0.699110,
-0.880140, 0.531310, 0.508970, 0.059750, 0.662510, -0.478230, -0.250770, 1.936220, 0.906770, 1.038460,
1.910190, 0.136130, -0.402430, 0.084550, 2.001530, -0.598790, -0.629630, -0.055890, 0.838260, 0.350970,
0.976760, -0.488730, -1.358880, 14.636410, -0.569440, -0.212630, 0.348930, -0.073250, -0.700650, 2.174550,
2.125970, 0.115340, 1.490660, -0.426450, -0.905810, 2.369600, -0.067020, -1.398090, -0.136660, -0.710810,
0.623830, -0.802260, 0.915880, 0.206810, 0.201270, 0.363130, -0.273350, -1.287920, 0.170320, -2.093580,
-0.322410, -0.528300, 0.724960, -0.488530, -0.218520, -0.873730, -0.704930, 0.368920, -0.710020, -0.097920,
-0.401520, -0.862280, -0.435800, -13.879780, 0.184990, 0.063810, 0.495040, 0.383860, -0.298720,
0.582370, 1.509120, 0.107290, -1.103050, -1.946900, -0.977350, 1.993980, -0.092420, 0.950460, -1.990950,
-1.429420, -1.197620, -0.641440, 1.687110, 1.226450, -0.760930, 0.063770, -2.235100, -1.401770, 1.907470,
1.366000, -0.705550, -0.904930, -1.549270, -0.342190, -1.045510, 0.641370, -0.967540, 2.746810, 0.702390,
-1.658240, -0.934810, -2.672630, 0.094470, 2.728980, -1.636720, -0.733180, -0.839120, -0.400870, 0.249230,
-3.841780, 0.334930, -0.569060, 0.926110, -0.057500, 1.641540, -2.440550, 0.598090, 1.415360, 0.410460,
-0.503550, 0.062800, -1.021240, 2.226920, -2.431530, -3.198480, 0.185120, 1.903170, 0.126350, -1.244700,
-0.238930, -0.252680, -0.354450, -0.897300, 1.322910, -1.250890, 0.077450, 0.822490, 1.071240, -0.245460,
-2.858650, -1.362260, 0.091870, -0.059760, -0.560000, 0.877110, -0.979820, -1.745520, -0.520870, -0.869000,
0.474480, 0.053760, 3.344300, -2.147060, -1.461070, 0.007440, -4.664650, -0.189430, 0.877970, 1.204520,
-0.117860, 0.760620, -1.969260, -3.232530, -1.424630, 3.149770, 0.048980, -0.967020, -1.533370, -0.060440,
-4.184230, -1.978680, -1.207120, -0.929740, 0.963040, -0.823870, 0.341960, -0.915010, 0.194560, -4.947120,
-0.370120, 0.629580, -0.778950, -1.105530, 0.333270, -2.979860, -3.223850, -2.483720, 2.768290, -0.618720,
-1.874190, 2.924040, 2.471710, -0.484720, -0.641670, -2.237500, -0.162000, 1.117220, -0.064700, -0.170320,
-3.517450, -0.104680, -3.948630, 0.431110, 0.727890, -6.183720, 1.348870, 4.650670, -0.945280, -0.964380,
-1.721940, -0.272120, -0.434350, 0.888590, 0.447270, 0.828200, -0.328130, 0.882560, -1.139220, -0.027580,
0.157570, -0.322920, 0.736400, 1.073010, -0.700830, -0.493160, -0.478780, -0.211160, -2.542440, -0.231530,
2.147860, 1.455300, -0.336420, 0.877950, 0.693720, 0.041710, 0.924690, 1.352290, -0.677880, -1.925550,
-1.223790, 0.603080, 2.426610, 1.987270, -1.333290, -1.081290, 0.748560, 0.036010, -0.409210, 0.469780,
-0.613200, -0.388450, -0.134610, 2.704270, -0.725750, -1.887900, -0.960390, 0.434170, 0.482610, -1.068810,
-1.199650, 0.055020, -0.825860, -1.608410, 0.706010, 0.129190, -3.389990, -0.384230, 0.431380, -0.148580,
0.276990, -3.667120, 1.133520, 0.031430, 0.513610, -0.247640, 0.512600, 2.999110, -0.603480, 0.814200,
-0.663140, 0.122490, -0.617170, 1.039650, 0.567830, 0.516920, -2.477840, 1.221140, -0.673420, 0.568700,
3.855680, 0.933870, 0.772310, 0.242310, -0.519660, 0.199620, 2.297280, -1.085380, -1.121840, 0.930290,
2.388510, -1.197750, 0.614810, 0.879940, 1.220940, 0.016420, -0.401630, -0.549330, -0.110910, 0.072780,
-0.267660, -0.273740, -0.103100, 0.637580, 0.439560, 1.580890, -0.777750, 0.051130, 1.867770, 1.046900,
1.048520, -0.663190, 1.449350, 3.421410, -0.259650, 0.467620, -0.827460, -0.472370, -0.788820, 0.884990,
3.507240, 1.247150, 1.629860, 0.173790, -1.195960, 0.538120, -1.205720, -1.160490, -1.390500, -0.720430,
0.878890, -4.803860, -4.321730, -2.312870, -1.716770, 0.374270, 0.073170, -0.732560, -0.298360, 0.071910,
-1.901180, -1.875080, 1.251040, 0.225340, 0.451510, -0.795320, -0.807280, 1.466300, -0.613870, 0.351030,
0.018860, 0.365220, -0.548000, 3.839070, -0.575720, 0.748530, 0.707360, 0.938220, -0.691440,
1.709400, -0.464370, -0.809020, -0.982630, 1.527550, -0.266440, -0.064020, -1.219280, -1.767880, 1.857090,
1.267350, -0.331490, -0.501080, -0.252730, 0.195230, 3.082710, -2.015680, 0.451140, -0.157690, 0.301410,
-1.026830, 0.031840, -0.505590, 0.209430, -0.653720, 0.180220, -1.003650, 0.576650, -0.110760, 0.690560,
1.706830, 0.483920, 2.147010, -0.837080, 0.171100, 1.119730, 1.011000, -0.633900, 0.982190, 0.711070,
1.594500, -0.100230, 1.511220, -1.372170, -0.895360, -0.677460, 1.788330, 1.249860, 0.466680, -0.359540,
0.404450, -0.927360, -0.408460, 0.343910, 0.340010, 2.387060, -0.805130, -0.312690, 2.185520, -1.140920,
-0.618450, -0.838010, 0.757550, 1.989250, -1.318690, 1.937060, -0.770350, 0.073220, 0.070370, -0.761900,
-0.410810, 2.699180, 0.220940, 1.162080, 0.011020, 0.800460, 0.278260, 0.763440, 1.996950, -1.695110,
0.999080, 0.578630, -0.524120, 0.047550, 0.243260, 0.314260, -1.076160, 0.387790, -0.305950, 0.810240,
-1.715650, -1.097970, -0.290890, 0.359670, 3.109750, -0.574570, 0.869670, 0.278920, -1.028310, 0.457120,
1.921650, 1.170720, 0.309000, 0.012650, -0.077130, -0.384450, 0.297490, -0.267120, -1.107270, 1.772480,
-1.365160, -0.599920, -0.700820, -0.128670, 0.694640, 3.343110, 4.226270, 3.184740, -1.526800, 5.884720,
-0.013310, -0.882860, 2.386730, 2.693670, 4.013560, -2.169070, -3.802110, -4.653120, 4.081870, -0.396640,
-3.286490, -1.366660, 5.826710, -2.324060, -1.598880, 8.681730, 0.447140, 1.162220, 0.267780, -1.034980,
0.124290, -0.691900, 0.791020, -0.365450, -0.801310, 1.912650, 1.259610, 0.221610, -0.097370, 0.085760,
1.308270, 1.258510, 1.747020, -1.593890, 1.197550, 3.096200, -0.174740, 1.249400, 0.207930, -1.650630,
0.179350, 0.484440, 0.474700, -0.945690, -1.938430, 1.438320, -0.556200, 1.889600, -0.402490, -0.720200,
2.362430, -0.771840, 0.707790, -0.175590, -0.561150, 0.795180, -1.623460, -0.252070, 0.229830, 0.206670,
-0.584190, -0.028680, -0.171180, 0.226250, 0.781970, -0.741070, 0.613740, -0.793920, 0.398050, 0.255870,
2.343620, 0.708610, 0.430960, 1.631890, -0.102750, -0.430820, 0.161730, 0.630240, 2.092130, -0.399060,
0.907830, 1.918440, 0.658310, 0.923570, -1.149540, 0.138520, 0.305440, 0.646770, -1.535340, 0.787580,
1.029130, 0.013690, -0.698050, 0.829100, -0.130890, 0.979650, 1.295700, 0.743830, 1.210750, 0.054000,
-0.845590, -0.569530, -0.500140, 1.982570, 2.450930, 0.164030, 0.967760, 1.257100, 1.864150, -0.752000,
-0.103520, 0.985550, 0.878730, -0.043560, -0.139430, -0.695490, 0.352740, 0.169970, 1.573180, -1.282870,
0.329120, -0.447020, 1.149470, -0.439820, 0.834170, -1.694430, -0.819450, 0.524920, 1.172080, 1.593490,
-1.162810, -0.394450, 0.267440, 0.322330, -0.814560, 1.834360, 0.555890, 1.618390, 0.472680, 1.473350,
1.499570, -1.333630, 1.146630, -0.805630, 0.246070, 1.019130, 1.948210, 0.125320, 2.148670, -1.375500,
-0.442210, 1.986360, 0.374340, 0.748430, -0.659360, -0.309040, 0.773650, 0.299180, -0.891930, -0.577900,
-0.382080, 0.187410, 0.988490, -0.245780, 0.873790, -0.257100, 0.171380, -1.333520, -0.417250, -0.156600,
0.414070, -0.726910, -0.869110, -1.457210, 0.295590, 0.810300, -0.015320, 1.576600, -1.022530,
0.114910, 2.145600, -0.589900, -0.847080, -0.292120, 0.508320, 0.026710, -1.216530, 0.165430, 0.300570,
0.832650, 1.119450, -1.550200, 0.377300, -0.299250, 0.933630, 0.899760, -0.756100, -1.795510, 0.976230,
-0.524440, 0.663870, 0.805080, -1.628600, 1.890630, 0.299230, 0.914250, -0.370610, 2.290130, 1.102300,
-0.336740, 1.202700, 1.955720, 0.305570, 1.939120, 1.151630, -0.827030, -0.270710, 1.105720, 0.909250,
1.341790, 0.492060, -0.978260, -0.979030, 0.755400, 0.684580, 0.457760, -0.058770, 1.541990, -0.481830,
-1.698250, -1.170530, -0.135440, 1.371790, -0.999580, 0.473730, 0.067530, -0.480690, 0.697170, -1.478730,
1.079310, -0.450680, -1.106380, 1.848760, -0.459470, -1.228530, -1.082210, 0.863850, 0.981710, -1.648510,
-0.561730, 0.541780, 0.655510, 0.401000, -1.063510, -0.049300, -0.111080, 0.326620, -0.011990, -2.092470,
0.555190, -0.267800, 0.333910, -0.834380, -1.901810, -0.972400, -0.330900, 0.344040, -0.715450, -1.787000,
1.123250, -1.793990, -1.211780, 0.696970, 2.352850, 1.136040, -1.252810, 0.239980, 0.396530, 0.007280,
0.201260, -0.788060, -0.860940, 0.879710, 1.613210, 0.214730, 1.032030, -0.780430, -0.407140, -0.057430,
3.005210, -0.961820, -0.926460, 0.149730, -0.410560, 0.927910, 1.615040, 1.177560, -0.679990, -2.116760,
1.165850, -1.537510, 0.716300, 1.773110, 1.265530, -1.655380, -2.001090, -0.337120, 2.669600, -2.098220,
-3.849010, -0.312010, 1.475370, -1.510210, -1.677220, 7.351140, -0.054350, 0.478390, -0.526980, 0.401190,
0.641340, 0.943800, 1.216170, 1.101360, 1.121750, -1.332880, -0.234180, -0.804290, -0.288900, -0.327740,
0.968030, -0.633150, -0.159610, -1.097610, 0.635180, 1.461050, -1.565140, 0.619800, -0.470490, -0.240360,
0.492540, -1.288700, -0.465870, 0.650200, -1.427820, 0.590380, 0.496230, -0.698510, -1.575430, 0.437930,
-1.019360, -0.212130, 0.254140, 0.647560, -0.721100, -1.113340, 0.318510, -0.171910, 0.966360, -0.513240,
-0.547890, 0.361910, 0.970170, 0.715000, -0.404660, 0.694240, -0.239290, -0.914750, 1.024750, 0.591060,
-0.648880, 0.787590, 0.773030, 0.240060, 0.836180, -0.577180, -0.087380, 1.103360, -0.437760, -0.185090,
0.292240, -0.523910, -1.313800, -0.688100, 0.866950, 0.216790, 1.042390, -0.047380, -1.146200, 1.345280,
0.917720, -0.088140, -0.175770, -2.625410, 0.333720, -0.227990, 1.118200, -0.177160, -0.429650, -0.593210,
-0.681440, -0.243610, 0.839930, -0.459580, 0.155690, -1.272870, 1.064940, 1.125700, 1.685800, 0.980760,
0.281520, -0.346960, 0.830420, -0.521130, -0.176630, -0.332770, -0.625540, -0.829440, -0.452100, 0.409210,
0.949300, 0.403890, -1.657540, 0.785660, -0.511590, -1.693480, 0.207730, -0.160170, -0.545060, 0.738080,
-0.167760, 0.172810, -0.241760, 3.350170, 0.230230, 2.002080, -0.592450, -0.609310, -0.679920, -0.067770,
-1.127230, -0.678670, -4.399450, -1.933460, 0.782800, -0.778330, -1.078380, 0.448840, 0.695020, -0.690650,
0.096470, -1.315700, 0.374850, 0.481430, 0.225480, -1.364940, 0.095930, -0.591960, -0.464860, -0.701340,
-0.268940, -0.143930, -2.507190, -0.201690, -1.307170, -0.297820, -1.451340, -1.507220, -0.853360, -0.998820,
-1.261370, -1.265520, -0.707430, 0.371140, -0.895640, -0.860880, -0.886280, -1.215100, 0.027380,
-1.046140, 0.070180, 0.123050, 0.052240, -0.711070, 0.687660, 0.135240, 0.896960, 0.584220, -0.000070,
-0.564340, 1.195230, -0.545830, 0.223530, -0.487140, -0.281770, -0.490930, 0.499640, -0.562610, 0.031460,
2.383710, 0.191820, -1.216080, 0.275120, -0.087440, 0.437630, -0.674220, 0.143140, 0.215480, -0.165110,
0.444150, 0.747270, -3.560750, -0.524080, -0.837640, -0.601230, -0.250490, 1.210390, -0.475170, 0.432980,
-0.838020, -1.228510, -0.166770, 2.283250, -0.021320, 1.827370, 0.707600, -0.355760, -2.258930, -0.559960,
2.175550, -0.165430, -0.248960, 1.167620, 0.005210, 0.194620, 0.920100, 1.331190, 0.433520, 1.066060,
-0.406090, 0.635630, 0.978820, 1.922700, 0.436010, -0.437290, -0.681560, -0.060420, 0.285190, 0.005880,
-1.660930, -0.041920, -0.598670, -0.830070, -0.420570, 0.788140, -2.105500, -0.240490, 0.918030, -0.372800,
-0.222340, -0.712710, 0.281390, -0.294770, 0.091870, 0.955070, 1.798290, -0.119120, -1.358750, 1.890320,
0.565970, 0.202970, 0.428480, -1.140830, 0.879120, 0.259250, -1.604420, 0.084340, 0.055570, -0.285050,
0.763060, -0.169030, -0.755210, 0.191830, 0.184940, 1.116440, 0.480230, -0.343010, 2.824700, 1.533110,
0.328830, 0.341260, -0.238240, -0.143600, 0.790030, -1.452190, -2.880540, -1.001680, 4.840590, -4.538000,
1.037220, 2.002090, -1.889580, 0.086770, 0.189260, -0.373400, 2.727060, -1.526710, -1.262030, -2.514610,
-3.135700, 1.122430, -4.410800, 0.303670, 0.105360, -4.428290, -4.077010, 3.054440, -0.412350, -1.725440,
-0.552120, 1.570820, -0.749340, -0.355970, 1.751910, -0.674530, -2.297220, 1.137230, 0.738890, -0.524650,
-0.379550, 3.129190, 0.450560, -0.146570, 1.678580, -0.169060, 1.096650, 0.640350, -2.248270, -2.363480,
0.345280, -0.990950, -0.888720, -1.095870, 4.998820, -0.757680, 0.758660, -0.303380, -2.378400, -0.856550,
0.381340, 0.418520, -1.041150, -0.683170, -0.755470, -0.233480, -0.778950, 0.081670, 0.649960, 0.626450,
-0.314670, -0.414380, -0.813510, 2.608240, -0.713280, -2.437060, 1.569770, 1.124460, 1.143050, 1.592210,
-0.902150, -0.367120, 0.216360, -1.339490, -0.366440, -0.503210, -0.240880, -0.487060, 0.808390, 0.479060,
-0.137680, -3.125470, 1.594240, -0.508890, -0.146850, -0.516560, -0.192600, -0.677200, -0.638220, -0.526440,
2.485030, -0.835060, -0.463660, 0.448290, 2.398110, -0.794250, -2.213400, -1.658340, 0.657330, -0.365090,
2.154990, 0.822800, -1.284280, 0.841890, -0.046620, 1.089940, -0.191260, -1.499310, 0.126180, 2.711930,
1.222190, -1.096450, -0.061140, -0.110800, -0.925720, -0.795760, -0.546930, -0.092590, -0.617300, 0.624790,
-1.434680, -0.979790, -0.416160, 0.926820, -0.402000, 0.673240, -0.621640, -0.520800, 0.836520, -0.395640,
0.512650, -1.359110, 0.414200, -11.596250, -0.200160, -2.458400, -0.792200, 0.403730, -1.046250, 2.827170,
-0.692510, 0.243220, -0.788070, 0.733980, -0.639590, 0.278460, -0.133870, 0.753750, 0.476060, -2.658470,
0.805950, -1.257250, -2.130250, -0.123050, -3.562760, -1.037070, -1.828250, -0.819970, -0.089150, -0.320730,
1.283630, -0.808030, 0.204170, 0.102690, 0.436430, -1.474700, -0.409210, 0.655370, -1.068170, 0.384770,
-1.097660, -1.109500, 0.479050, -1.487360, 0.173990, -4.171780, -0.859120, -0.881500, -0.089490,
1.310180, 0.448490, 1.807950, 0.221590, 0.192040, 0.002960, -0.676990, 0.690960, 0.469720, -0.627370,
0.140460, 0.209300, 0.583630, 0.470860, 0.248670, 0.275630, 0.849710, 0.261180, -0.000900, 0.849070,
0.020500, 1.104660, 0.828470, -0.647340, 0.904130, -0.613170, -0.658760, -1.296990, 0.506520, 1.002690,
1.605300, 3.421970, -1.698080, 0.482320, 0.450550, 0.642230, 1.517160, 0.112620, -1.026200, -0.073060,
0.150850, 1.277060, 1.529010, 0.385500, -0.532220, -0.000070, -0.667320, 1.162640, 0.770120, 0.284500,
0.509810, -1.607080, 0.629650, -0.136620, -0.445780, 0.335450, 0.187050, 0.317690, -1.618570, -0.296890,
-0.209580, 1.642740, 0.021080, 1.042640, -0.524570, -0.815450, 0.669090, 0.564560, -0.283660, -2.076650,
1.070470, -1.464430, 1.289170, 1.312760, -1.850440, -1.206270, -1.660830, 1.889540, 2.962400, -0.381240,
-0.435940, -1.918210, 0.126930, -0.291860, 1.325510, 0.466620, -0.959940, -0.243880, 1.399550, 1.358490,
1.219130, -0.626280, 0.596180, -0.023760, 1.120410, -1.389840, -0.763560, -0.888740, 0.834150, -0.218470,
-0.612760, 0.655840, 0.794310, -1.055130, 0.198130, 0.087460, 0.508110, 2.105710, 0.320370, -0.440290,
0.054920, -0.308090, -0.428700, -0.727530, 0.656280, -14.461300, -1.198120, -3.426420, 6.681580, -3.605470,
1.226570, 4.893780, 1.736800, -8.123880, -8.889100, 0.283780, 1.010670, 2.232130, -0.990310, -3.007200,
4.274570, 1.811090, -1.370460, 0.118690, -0.758790, 4.912130, 1.852240, 0.389130, -0.936350, -0.813120,
2.609330, -2.077720, 0.538590, 1.645440, -0.361070, 1.005900, 0.173520, 1.384080, -1.026520, 0.243580,
0.610960, -1.428040, -0.589600, -1.597840, 0.366070, -1.106260, -1.268440, -0.138370, -2.360030, 0.985750,
0.587400, 1.682210, -1.876990, 0.142420, 0.246640, -1.401130, 0.685100, 0.583530, 0.215660, 0.556990,
-1.565950, 1.509270, -0.885080, -1.414590, -0.859680, 0.417220, 0.441930, 0.573890, -2.229320, 1.057890,
-0.217400, -0.084720, -0.358650, -0.426580, 0.003420, -1.281930, -0.657900, -1.508040, -2.218980, 1.028180,
0.654340, -0.060270, -1.653150, -0.003250, -0.866420, -1.033750, -0.500600, 0.195380, 0.170770, -1.431920,
2.010630, -0.704650, 0.348110, 1.333120, 0.805880, -0.564150, -0.663760, -0.818600, -0.889540, -1.100420,
0.995250, -1.573410, 0.675790, -1.307540, -1.279710, 0.699790, -0.498240, -0.358120, -0.833370, 0.160310,
0.198100, 2.300550, 0.425760, 0.764630, -1.529870, 1.006960, 0.344520, 0.956230, -0.242330, 0.060350,
-0.444590, 0.163030, 0.258950, -0.031680, 0.500130, 0.089930, -0.194350, -1.010480, 0.329800, 0.091720,
-1.329530, 0.508190, 0.088660, -0.027610, 1.234010, -0.882190, 0.541880, 0.107860, -1.351680, 0.337800,
0.285410, 1.378560, 0.193170, 16.134541, 0.852700, -0.908850, 0.206390, -0.984540, 0.407130, 3.497950,
-0.290020, -0.963550, 7.236040, 2.284150, 0.950850, 2.162380, -0.774260, -0.058780, -0.521170, -1.019050,
-0.308700, -0.998430, -0.614240, -0.655450, 1.600070, -0.269220, -1.093510, -0.376030, 0.479530, -1.503940,
-0.816230, 0.550580, -0.975960, 0.695830, 0.240600, -1.057330, -0.910320, -2.192230, 0.291330, 0.111610,
-1.234680, -1.009620, 0.280770, -1.218570, -0.163160, -1.195260, 0.035830, 0.713210, -2.041340,
-0.678680, 0.313230, -0.571940, 0.358540, -1.093390, -0.267670, -0.762360, -0.109910, 0.662980, 1.342080,
0.897050, -0.057500, 0.633910, 1.343860, -0.657130, -0.559120, 0.197860, -0.582620, 0.579850, -0.390440,
1.700980, -0.583890, 1.788740, 0.668790, -0.260870, -1.259820, 0.956240, -0.580200, 0.016700, -0.170180,
-0.216210, 0.446530, -1.212270, 0.014820, 0.366500, -0.416090, -0.597310, -0.189410, 1.026630, -1.605380,
-1.564620, -0.436690, 0.795140, 0.179250, 0.546100, 2.436000, -0.835120, -0.159610, -1.212970, 0.418010,
0.233750, -1.943360, -0.406250, 0.370430, 0.418030, 0.656290, 0.704470, -0.802180, 0.603840, 2.263330,
-0.857790, -0.102640, 2.445350, -0.555890, -0.511410, -0.055080, 1.064890, 0.133620, 1.703260, -0.855920,
-0.516300, -0.645140, 0.875810, -0.705250, -1.590080, 0.772530, -0.860250, 1.118630, -0.221760, 0.979220,
-0.610020, -0.134730, 1.148520, 0.516890, -0.386710, 0.816870, -0.020730, 1.111310, -0.523880, 2.321720,
0.863750, 1.577980, 0.114880, 0.114260, -0.310990, 0.183750, 2.777030, -0.757000, 0.080360, -0.692530,
1.118800, -0.018580, 1.607820, 0.558650, 1.178480, 1.451170, 1.230070, 0.783230, -0.228400, -1.725850,
0.578280, -0.676140, 2.012610, -0.258240, -2.134800, -0.142380, -2.907830, -0.985620, 3.392320, -7.325960,
0.951750, 2.199530, -1.557460, -2.302690, -3.834100, -0.845700, -0.460490, -2.375470, 0.306160, -0.160300,
-4.411960, -0.857100, -6.809710, -1.034020, 0.456140, -8.143860, -2.531030, 3.452150, -0.965790, 0.331700,
0.376180, -0.145890, 1.653860, 0.420060, 0.361700, 1.174380, -1.360650, -0.613270, 1.051970, -0.607020,
1.012160, -0.598120, 0.825610, 0.596020, 0.981420, -0.400580, -0.966000, 0.058040, -1.434630, -0.519440,
-0.410820, 0.774870, -1.966040, -1.219280, 0.164360, -2.269460, 0.372460, 0.068160, -1.153930, -1.361120,
-0.200240, -0.425380, -0.738210, 0.716170, 0.581080, -0.849240, -0.784160, 0.958230, -0.769340, -0.991700,
-1.237970, 1.088890, -1.598110, 3.527180, -0.545620, -0.158420, -1.259980, 1.278680, -0.656920, -0.461670,
-0.075650, -0.801220, -0.615210, 1.365770, -1.995020, -2.217770, 0.821500, -0.948990, 0.266010, -0.378780,
1.153930, -0.599300, 1.263110, -0.880380, 0.388860, 0.481830, 1.659580, 0.694030, -0.112110, -1.486560,
-0.077340, 0.089480, -0.565790, -0.698000, -0.529670, 0.372640, -0.987720, 0.650270, 1.021370, 0.092560,
-0.358270, -0.535530, 0.698450, -0.268020, -3.398220, -0.933950, 1.443470, -1.927850, -1.352680, -0.029980,
-0.767750, -0.884140, 0.176500, 1.467640, -0.591360, -1.497000, 0.260120, -0.312940, -0.223500, -0.550570,
0.200300, -0.534490, -0.812770, 0.681230, -0.926160, 0.715620, -0.284690, -1.492430, -0.451960, 1.367190,
3.233530, -0.618030, 0.604010, 6.421860, 0.085800, -1.088150, -0.453180, 0.047950, -0.766630, -0.436910,
-1.973720, 0.741510, -0.838630, 0.514160, -1.744940, -0.313750, 0.318190, 1.391870, -1.110260, -0.099480,
-1.308830, -1.520350, -2.159120, -0.244700, -3.738160, -0.993370, -0.431490, -0.325490, -0.783060, 0.318330,
-0.945600, -0.569220, -0.247280, -0.419520, 2.024140, -1.058450, -1.032740, 0.481400, 0.220930, 0.647110,
-0.734800, 0.012550, 0.222080, 4.217500, -0.611340, -1.176370, -0.401070, -0.667210, 0.022600,
-0.260740, -0.149760, -1.209940, -0.672270, 1.331210, 0.792130, 0.244630, 0.789250, -0.781610, 0.494560,
1.202590, 0.468550, -2.413750, 0.925330, 1.268680, -0.270850, 0.201910, -0.945940, 0.039180, -0.081450,
1.035520, 0.759580, 0.797150, -3.225070, 0.373450, -0.387290, 0.307890, 1.208500, -0.707300, -2.330080,
-0.130000, -0.370970, 0.480500, 1.577720, 0.057570, -1.181410, 0.146710, 0.825500, 0.553770, 1.194850,
-0.048710, -1.529870, -0.865470, -0.603720, -0.078770, -1.083450, -0.473110, 0.018880, 0.334620, 0.516710,
-0.684330, -0.814610, 0.148550, -0.294150, -0.555180, 0.155610, -0.710890, -0.217350, -0.185130, 1.119870,
1.388660, -0.333450, -0.858270, -2.128630, -0.556560, -0.775050, 1.056050, 0.735350, -1.027860, -0.873090,
-0.044870, 1.216320, 0.463360, 0.139920, -0.770100, -0.282390, -1.196630, 1.614880, -0.303900, -1.047910,
1.245890, 0.401040, 0.524440, -1.752450, 0.506470, -0.284960, -0.870540, -0.020490, -0.336050, 0.194490,
-0.316560, -1.203310, 1.654670, -0.394390, 0.124840, 0.465330, -0.110640, 0.126760, 0.160490, -0.297080,
0.619520, 0.386210, -0.906950, -1.971730, -0.386460, 1.764580, 1.479790, 0.503120, -0.544480, -1.325500,
2.433580, -1.735220, 0.417310, 2.333850, 0.035810, 0.722940, -5.240100, 2.188060, 2.547100, -2.848820,
1.701310, 4.602240, -0.257020, -9.059720, -17.209490, -1.043780, -0.664590, -0.388370, -1.265660, 0.098260,
0.263430, -0.186850, -13.117140, 2.302400, 3.382260, -0.791910, -11.275710, 3.957270, 1.091400, 0.408990,
-0.807890, -0.728950, -3.260500, 0.221990, -2.567090, 0.669480, 0.220840, -0.318130, -4.472180, 0.979650,
-0.375810, -0.770120, 0.883400, 1.891170, 0.491620, -0.573780, -1.795720, 0.628210, 1.135640, -0.351200,
-0.437820, -0.196610, 0.106570, -0.534460, 1.566430, -0.604420, 0.629580, 0.018050, -2.124400, -0.712750,
0.175910, 0.293860, 0.140190, -0.124320, 0.152580, -1.176780, 0.598690, -1.498440, -0.825310, -0.256370,
0.920740, 0.066110, -0.388370, 1.094930, 1.534540, 0.256270, -0.353920, -0.081290, -0.423750, -1.630240,
-0.199870, 1.970940, -1.170820, 0.462150, 0.091790, 0.315960, 1.722120, -0.177430, 0.849910, -0.621750,
-0.257850, 1.195160, 1.146930, 1.456940, -0.788470, -1.210110, -0.707960, 0.382780, -1.075690, -0.977970,
1.366410, 0.604510, 0.276840, -2.417110, -0.571800, 1.776330, 1.496970, -0.735560, -1.650250, 1.317870,
0.791010, 0.788540, 0.673480, -0.106890, -0.116030, 1.125180, 0.591350, 0.014520, 0.825830, 0.274330,
-0.570250, 1.208040, -0.987590, 0.447130, -0.624160, 0.781710, 0.268800, -0.047640, 1.093540, 0.588900,
-0.447810, 0.033320, 0.461490, 1.348270, 0.157170, 0.557360, -0.699570, 0.258430, 0.699390, -0.790760,
-0.032700, -0.427850, -1.135050, -22.351070, -0.267840, 0.112620, -0.222760, 0.392440, -0.842600, -0.826680,
-2.437280, 0.942760, 0.944130, 9.006160, -0.891650, -0.957370, -0.103730, -1.575040, -0.297310, 0.441360,
-0.024530, -1.274210, -0.502680, -0.781750, -0.953760, -0.089870, -0.089040, 1.069310, -0.504770, 0.568740,
0.225210, -0.483270, -1.006970, -0.080120, -0.234260, 0.326340, -0.444070, -0.735060, -0.646530, 0.332990,
0.730650, 0.573290, 0.470640, -0.539380, 0.263560, 0.390680, 0.403070, -0.378220, 0.466370,
0.581580, -1.030920, 2.507830, 1.050000, -0.463500, 0.646830, -0.824390, 0.342940, -0.409670, -2.035710,
0.106440, 0.059770, -0.312470, -0.960260, -0.468500, -0.441030, -0.017180, -1.404730, -0.568310, -0.450970,
0.735350, -0.141270, 1.285290, 0.924490, -0.003020, -0.400930, 1.106040, -0.665750, 2.417600, -1.854010,
0.429610, -1.847170, -1.798740, 0.619760, 0.161460, 0.236640, 0.038590, -0.581920, 1.256880, -0.644280,
-1.563890, 0.667360, 0.500210, -0.589550, -1.374660, 1.237820, -0.543810, 1.678440, -0.704370, 0.941640,
-0.592750, -0.781920, 0.945360, -0.888620, -0.097300, 0.814460, -1.331250, 0.843120, -0.203210, 0.155500,
-1.063880, 0.375520, -0.250080, -2.168950, -0.182240, -0.729630, 0.496450, 4.188410, 0.444530, -0.833880,
-1.419680, 0.254640, -0.976840, -0.537820, -0.090260, -0.433270, 0.467780, -1.033370, 1.645170, -0.558440,
0.020260, 0.101760, -2.748580, -0.157820, 0.183180, 0.074260, 0.717490, -1.521280, 1.186610, 0.490130,
-0.032120, 1.321180, -1.024450, -0.310940, -1.764050, -0.518140, -1.803950, -1.006950, -0.443400, -0.690310,
0.965060, -0.224570, 1.329490, -1.269910, 1.290380, -0.357900, 0.878310, 1.419130, 2.258110, -0.389890,
-0.395390, 0.082540, 0.332710, 0.090830, 0.295600, -0.951800, -0.527020, -0.649470, 2.295290, -0.367370,
-0.451700, 0.995320, 0.900290, -0.538390, -1.453450, 0.339130, -0.267600, -0.126140, -0.854520, -0.115750,
0.790220, 1.134440, -2.643690, -0.000250, 1.877950, -4.750090, 0.348350, 5.318740, 0.502520, 0.266060,
0.164610, 1.147170, 0.377060, -1.707550, -0.703640, 0.016910, 0.405380, 1.274020, 1.229780, -0.287970,
0.862930, -0.706040, -1.584280, -0.312220, -0.653630, -1.086190, -1.469580, -0.571820, 2.833840, 0.605240,
1.850720, 0.944790, -1.488200, 1.705900, -0.126030, -1.606760, -0.764470, 0.027580, 1.331180, 1.599910,
-1.304270, -0.392240, -0.302660, 1.134920, 1.627880, -0.188060, 0.744550, 0.969030, -0.192950, -0.313750,
-0.111660, 0.864400, -1.186920, 0.792430, -0.416920, -0.829550, -1.297390, 1.097230, -0.118140, 0.334540,
-0.906040, 0.541810, 1.153900, -1.058090, 1.228000, 0.957040, 0.099670, 0.287370, 0.550940, 1.090130,
-2.117990, -1.184930, 0.680770, 1.343760, -0.244420, 0.584960, 0.678870, -0.028090, -0.062480, 1.084130,
0.497270, 1.327480, 0.267920, 0.892830, -1.131170, -1.157520, -1.010540, 0.862530, -0.335340, 0.119120,
2.027140, 2.580620, -1.219930, 0.541010, -0.970380, -0.153230, 0.333660, -0.087250, -2.930400, 2.970370,
0.712400, 0.269040, -1.239380, 0.728830, 1.463610, -0.756410, -1.509150, 0.503240, -0.795770, -0.438690,
-0.504870, 1.694560, 0.290830, 0.116970, -0.980430, -1.229160, -0.082640, -1.761980, -0.550570, -1.956460,
2.809070, -1.478460, -1.311990, 14.174480, 0.093490, 0.072440, -0.286980, 0.186020, -0.657790, 0.831060,
-0.133680, 0.470390, 1.239230, -0.766550, -2.137380, -0.269340, -0.988600, 0.558230, 0.057360, 0.192950,
-0.297780, 0.169790, 0.112620, -1.019120, -1.987510, -0.806700, -0.814020, 0.664690, -0.531430, -0.381880,
0.312730, -1.506030, -0.522400, 0.769280, -0.870380, -0.439270, 0.140310, 0.421320, 0.082710, -0.850820,
-0.264750, -0.258970, 0.294260, -7.030880, -0.833140, 0.552720, 0.584170, 0.010480, 0.972970,
0.736070, 0.749500, -1.067660, 0.569640, -0.758600, 0.435230, 0.528810, 0.034360, -0.708930, 0.674600,
0.543820, 1.617280, -0.963660, -0.728720, 1.468840, -1.782810, -0.043770, 0.618240, 1.805130, -1.581960,
-1.043350, -1.388000, 2.124700, 0.677000, 0.408590, -0.060530, 0.309360, -0.257110, 0.693930, 0.203910,
-1.014070, 1.017890, -0.057480, -1.241970, 0.155840, 0.196210, 1.097930, -0.672220, 0.253390, 0.754360,
1.016340, -0.323530, 0.000460, 0.859940, -0.256580, 0.133760, 0.180130, -1.125010, -0.036030, 2.185740,
-0.773660, 1.011140, -2.663770, 0.632390, 2.377210, 0.282910, 1.417620, 0.171880, -1.207000, -2.989390,
-0.809400, -0.127640, -0.630590, -1.117450, -2.137000, -2.028810, -0.593170, -2.103810, 0.164890, -0.071720,
-1.999950, -0.681070, -2.816530, -2.138640, -0.142440, 1.648670, 1.483120, -1.313790, -1.121040, 1.126470,
-1.235430, -0.143690, -1.442580, 0.803990, 0.527490, 0.576120, 2.953970, -0.057620, 1.782980, -0.666100,
0.972020, 1.620260, -0.739610, -0.501000, 0.653030, -0.473650, 0.414460, 0.696990, -0.690630, 0.376790,
-0.745050, 0.663500, -0.939200, 2.509410, 0.423150, 1.710260, -2.866380, -2.135130, -0.784920, 0.265320,
-2.027800, -2.356280, -0.196880, 1.420200, 1.147730, -0.136270, 0.309790, -1.130070, -5.425470, 4.876940,
0.458170, -1.196670, -0.766710, 0.472340, -0.558570, 0.161290, -1.237410, -0.739950, -1.422240, 0.544510,
3.215440, -1.397650, 1.048390, 0.075040, -1.935540, 1.198010, 0.600590, 6.737170, -1.395150, 3.135340,
-0.346350, 1.729200, -0.857310, 1.339460, -0.675820, -0.536140, -2.317970, 0.966340, 0.671000, 1.789010,
0.303580, 0.057790, -1.964100, -0.564340, 0.224790, -0.193810, -1.511720, 1.607740, 0.985410, 1.554850,
4.827880, -1.844180, -2.774730, -0.260170, 0.239470, -0.527030, 1.202570, -4.125530, -0.892030, -0.381560,
3.351800, -0.573310, -3.124320, 0.009830, -0.774940, -2.426680, 1.143680, -0.465880, -1.251200, -0.957890,
-0.978470, -0.789500, 0.554640, -0.052790, -0.429070, 0.548720, 0.146350, 0.326130, -0.515970, -0.928590,
0.749410, -1.490650, 0.560440, 0.372280, 1.107390, 0.017130, -1.709440, 0.337700, -0.641510, -0.991530,
0.443740, 0.446510, -1.382810, -3.257730, -0.295680, 0.055240, 2.475010, 2.334660, -1.201340, 0.293400,
0.240680, -1.427190, 0.262370, -1.944680, -2.158150, 0.172260, 0.272430, 0.619580, -2.410080, -1.362760,
-1.059330, -0.140800, 0.219020, -0.439050, 1.938240, -0.843190, -0.755280, 0.888080, -1.263880, 1.110950,
0.544750, -4.624370, -2.748980, 0.689140, -0.272880, -0.054860, 0.247930, -1.406570, -0.472280, 0.405510,
0.769910, 1.930110, 0.520750, -0.912810, -1.635940, -0.393920, -0.266790, -0.052570, 1.493100, 0.600440,
-0.744860, -1.912790, 2.663520, 1.170000, 0.546320, -0.881230, 0.717600, 2.498620, 0.192210, -0.820790,
0.194410, -0.356740, -0.107780, -0.617800, 0.458450, 1.897800, 0.078130, -0.862310, -1.246980, -1.536550,
0.519470, -0.777120, 1.121640, 0.446160, 2.533740, 0.025120, 0.147320, -0.503520, -0.094200, -0.410520,
-1.152100, 0.346970, 0.817050, -0.040410, 0.242010, 0.396800, -0.394960, 0.637940, 0.079630, 0.892020,
0.657370, -0.757850, -0.398370, -1.467200, 0.870010, -0.320870, -0.147200, -0.558320, 0.837610,
1.345590, 0.810080, 0.345730, 1.149780, -2.094080, -1.446150, 0.727560, -0.441350, -0.807500, 0.494590,
-0.779160, -1.397330, 1.791360, 0.035470, 0.409090, -0.146770, 0.516480, -0.658020, -0.030400, 0.129490,
0.549790, -0.381650, -0.253100, 0.298460, -0.162540, 0.143660, 0.360850, -1.239290, -0.465850, 0.522600,
-0.405160, 1.348280, 1.656360, -0.213560, 0.913810, 2.521480, 1.883490, 2.651130, 0.339220, 0.471560,
-0.528500, 0.621020, 1.941520, 0.272200, 1.269920, -0.337420, 1.195030, 1.437250, 0.386670, -0.414350,
-1.340390, -0.547170, -0.485280, -0.597680, -0.263550, 0.713100, 0.177500, 1.204810, 1.412670, -0.296820,
-2.608860, 1.777800, 1.775040, 1.402040, -0.638210, -0.907430, -0.341270, -1.647210, -0.248220, 0.736930,
1.765900, 1.397210, 0.214770, -0.089830, 0.083060, 0.738860, -1.976810, 0.073840, -0.162230, 0.484800,
0.024650, -0.258370, -0.800870, 0.530110, -0.441090, 0.596670, -0.114220, 0.726610, 0.383300, -0.611890,
0.285590, 0.659060, -0.323000, -0.856220, 0.198720, -0.331870, 0.943730, 0.487360, -0.756430, -1.480160,
0.170830, -0.221750, 0.107240, -0.421280, 2.088790, 2.272310, -1.321200, 0.841690, 1.146720, 0.839730,
0.269370, 1.629220, -0.419210, 2.938800, -1.628850, -0.178370, -1.533300, -0.732860, -0.587700, -0.214000,
-0.162390, 0.070760, -0.842570, 0.660900, 1.105050, 0.541750, 0.918950, 0.363270, -0.714690, 1.468610,
-0.454730, -0.240310, 1.400180, 0.356320, -0.277320, -1.005520, -0.396580, -2.138530, 0.110010, 2.365480,
0.085260, 0.133960, 1.249440, 0.528350, -0.307450, 0.856690, -1.032300, -0.531600, 1.746230, 2.383150,
0.621770, -0.937490, -0.893140, -0.109640, -0.014930, 0.723750, -0.535720, 0.132230, -0.603530, -1.063000,
-1.486070, -0.397920, 0.766690, -1.951900, 0.164700, 0.795390, -0.102080, -0.651330, 0.666360, 1.136250,
1.880560, 1.184710, -1.148400, 1.451700, -1.652060, 0.338480, -0.017630, 0.121370, -0.250780, 0.663540,
2.527130, -0.346000, 0.187160, -0.923490, 1.068370, 1.687870, -1.106890, 0.488970, -0.990220, -0.317630,
0.194840, -0.701200, -0.425980, -0.776980, 2.206090, 1.818050, -0.628740, 0.573450, -0.460250, 1.159250,
0.993550, 1.338690, -0.469480, -0.137670, -0.498590, -0.647070, -0.603490, 0.268460, -1.062750, -1.329390,
0.204930, -0.310190, 1.388710, -0.882040, 1.209080, 0.463640, -1.605820, -4.049470, 1.299950, 0.412490,
0.512440, -0.558990, -0.335230, 0.112020, 0.685750, 0.764800, 0.287110, -0.377430, 0.399040, -0.873210,
-0.703440, -0.207060, 0.672560, 0.882250, -1.443900, -1.080110, 0.302080, -1.503380, 0.738100, 0.107720,
1.091880, -2.384400, 1.623630, 2.875870, -0.368390, 1.514430, 0.716040, 0.805970, 0.190170, 1.532590,
-0.354660, 0.424280, -1.142180, -4.935980, 0.319630, 0.087070, -0.026520, 1.802680, -1.018620, 2.446230,
0.594580, 0.987550, -0.111110, -1.123150, 2.181450, 1.509660, 0.575040, 2.790860, 1.608530, 0.813940,
-1.677020, -2.421660, -0.860720, -1.800800, -0.671130, -1.990310, -1.142340, -1.969180, -2.951960, -0.408440,
1.177860, -0.649610, -0.535850, -3.737370, -4.828250, -2.036180, -4.513850, 1.039370, -3.685840, -2.095740,
-2.925630, -35.413780, -17.228411, -0.585290, -6.689250, -0.590390, -1.040500, -17.320089, -3.605950,
1.270830, -0.394640, -1.439510, 0.528670, -0.059810, 0.851800, 0.558830, -0.691290, 0.497870, -0.437130,
0.857970, 0.725650, 0.982990, 0.608790, 1.751960, -0.494740, 1.112670, 0.516360, 1.589000, 0.683060,
-2.850840, 0.764120, 0.211320, -0.086160, 1.352060, -2.275710, 1.034870, -1.847920, -0.363530, 2.691860,
-1.699100, -0.896340, -0.687030, 1.189780, 0.683410, 1.425900, -0.160190, -1.390960, 0.213080, 0.837960,
-0.386520, -0.660370, 0.371500, -2.831280, 1.151600, 0.539200, 2.899750, -1.199480, 0.494320, -0.536910,
1.050720, 0.148560, -0.645550, -1.753160, 0.299650, -2.716560, -0.463560, -2.969500, -0.802620, -1.807220,
0.772790, 2.465560, 0.332760, 0.472360, 1.400040, -1.395720, -0.306440, -0.565430, -0.009570, 0.046120,
2.062130, -2.164610, 0.747910, -1.086620, 0.507500, 0.061900, -2.154150, -0.474400, -3.496340, 0.421850,
-0.483540, -0.000270, 3.572360, 1.835300, 0.353760, -1.990530, 0.401280, 1.388170, 0.692740, -0.489120,
1.632000, 1.042180, -0.430660, -0.503320, -3.931760, 0.206250, -3.436630, -1.039890, 0.186580, -2.311470,
-1.351250, -3.072020, -1.060600, 1.722960, 0.903050, -0.847780, -2.503500, 0.748010, 0.890920, -5.009220,
0.055570, 0.618400, 0.460710, -1.139150, 0.544090, -1.125550, 0.779520, -0.140030, -1.292190, -2.363520,
-0.021520, 0.622050, -6.104370, 0.677340, 1.520000, -0.268050, 0.290650, -0.785100, 0.674800, 0.087330,
-0.879130, -4.939850, 0.899610, -3.498110, -1.890940, 2.161920, 0.620450, 2.197460, 4.726190, 1.665360,
0.096450, 0.352090, 1.330620, -0.173520, 0.170950, -0.143340, -1.019000, -1.455180, -0.627560, -1.318630,
-1.413630, 1.424470, -0.041250, -1.235850, -0.854600, 1.443240, 0.849950, 0.006570, 0.758920, -1.444420,
0.172330, -0.468180, -0.278400, -2.586580, -0.224410, 0.756920, 0.539430, -0.432540, -0.622850, 0.437320,
-1.821700, 2.122740, -1.295050, 0.728090, 1.016520, 0.397100, -0.188210, -1.675330, -1.638080, -1.212150,
-0.293790, -1.726650, 0.378080, 0.286910, -0.984000, 1.516590, 0.205690, -0.539600, 0.699440, 0.289420,
-0.478450, -2.630540, -0.640880, -0.957080, 0.554850, 0.562620, -0.973910, 0.425330, -1.417130, -0.448480,
0.215820, 0.359110, 3.253340, 0.533230, -2.313040, 0.142770, 0.653620, 0.635140, 0.519280, -1.142500,
2.271950, 1.325320, -0.500270, 1.260540, -1.519970, -0.995990, 0.169000, 0.127430, 1.073390, -1.351820,
-1.072350, -0.280310, -0.069470, 0.408130, 1.024520, -0.057430, 0.583240, 1.437520, -0.237400, 0.487700,
-0.531380, 0.488040, 1.352900, 0.137470, 0.204830, 0.261380, 0.622690, -0.251050, 0.640550, -0.399380,
0.043070, -3.258400, 0.627850, -0.061100, 0.347050, 0.107010, -0.467560, 0.501350, -0.288390, -0.021770,
-3.007730, 2.216210, -0.101630, 1.444070, 0.235080, -0.986540, -1.227110, -0.914630, 0.236930, 0.628090,
-1.232460, -0.268010, -0.555420, -0.524560, 0.967580, -0.596030, -0.400720, 1.272660, 1.523030, -0.334430,
0.398010, 0.594640, -3.669740, 0.112780, 1.348630, -0.923800, -0.452600, 1.008360, -0.449090, -0.851620,
0.710630, -0.550150, 0.457490, -0.327800, 0.303940, -0.193770, 0.335280, 0.482370, 0.776510, -0.253930,
0.560590, -0.459880, -0.542000, -0.781550, -0.045000, -0.637760, -0.600190, 0.793410, -0.775310,
-1.757700, -0.676960, 1.115620, 1.370530, 0.350520, 0.201090, 0.588800, 0.546600, -0.698420, 1.573260,
0.707970, 0.399550, 0.955180, -0.173000, -0.523970, -0.184290, 0.546970, 1.014730, 0.413160, 0.080150,
-0.322580, 0.878890, 0.433440, -0.257950, -0.879860, -0.202860, 2.369520, -0.487710, -0.953740, 0.433940,
1.190060, 1.589410, -1.113090, 0.431690, 0.459640, 0.987020, 0.523720, 0.516730, 0.737730, 0.142550,
-0.216650, -0.611690, 1.792600, -0.208260, 0.643940, 1.135960, 0.334690, -0.357210, 0.336120, -0.085970,
-0.841620, 0.302070, 0.349070, -0.489800, -0.529800, -0.146910, -0.023960, -1.428380, 1.201630, 0.553830,
0.310290, -1.068810, 0.869370, 0.079050, 2.116520, -0.471020, 0.092400, 0.884820, -0.310740, 0.031720,
0.441930, 1.193950, 0.617070, -0.788190, -0.205010, 0.943360, 0.305400, -1.002180, 1.464210, -0.845250,
0.588360, 0.352800, -0.190390, 0.722500, 1.377230, 0.292340, -1.445260, 0.036990, 0.198460, 0.108260,
-0.794430, -0.756620, 0.503990, -0.667400, -0.643610, -0.096840, -0.403800, -0.127990, 0.227300, 0.721310,
-0.213300, 0.690430, 0.196410, 0.796300, 0.743590, 0.236340, 1.249630, -0.266900, -0.495570, 2.230390,
0.124140, 1.543040, 1.041680, -1.037520, 2.172880, 1.024180, 0.163040, -0.296340, -5.278920, -2.915170,
-2.333440, -1.536190, 0.109050, -0.251990, -1.629350, 0.679420, -0.258070, 0.232590, -5.080030, -0.649290,
0.235280, 1.637440, -2.360270, 0.873050, 0.072460, -3.704500, 0.049740, 2.383250, 0.888920, -0.534870,
-1.874370, 1.223240, 0.214800, 0.384570, 1.163570, 0.883130, -0.551540, -0.003530, -3.431170, -1.527690,
0.674720, 0.410780, 0.031140, -0.883630, 0.455850, 0.978230, 1.095690, -0.571830, -0.343770, 0.726260,
-0.600620, -1.098120, 0.728010, 0.316800, -0.148690, 1.943770, 0.158380, -0.709790, 0.483950, -0.486680,
-1.196210, 0.165590, 0.285150, 1.183090, 0.144730, 0.679390, -0.138370, 0.626720, -0.622360, -2.649690,
0.641190, 1.618340, -0.046700, -0.339350, -0.858760, -0.611860, -0.019190, 0.536630, 1.138710, 1.060810,
-0.827100, 0.786940, -0.542270, -0.990110, 0.340450, 0.110020, 1.648810, -0.531690, 0.415330, -0.173460,
0.500970, -0.701330, -0.969590, 1.157030, 0.077540, -0.930740, -0.253470, 0.200720, 0.865780, 0.620460,
-0.185920, 0.465230, -0.272760, 0.459170, 1.083660, -0.584470, 3.357160, 1.082990, 0.958020, 0.578330,
1.905660, -0.421900, 1.028580, -0.517950, -0.860850, 1.369180, -0.428920, 0.681430, 0.143740, -0.757050,
0.365390, 0.305280, 1.967020, 1.131200, -0.575600, 0.116470, 0.306460, 0.742470, -0.005230, 0.155730,
-0.112660, 0.817110, 0.315380, 1.911160, -0.648420, -0.793960, 0.380960, -1.683250, 0.407690, 0.491510,
2.318330, -0.614160, 0.342640, 8.223580, -0.834150, -2.070560, -0.039700, -1.581850, -0.602390, -1.146430,
-0.377800, -0.412770, 6.359800, 0.501470, -0.491910, -1.192610, -0.398200, 0.897160, 1.283620, -0.306340,
-0.526940, -2.377620, -0.561800, -0.210810, -1.418720, -0.126120, -0.751190, 0.418930, -0.823810, -1.510850,
-0.070300, 0.808550, -2.470900, 0.856340, 0.232510, -0.900320, -0.213430, 0.888880, 0.383160, -0.518520,
-0.918600, -0.813900, -0.749070, -0.470000, 0.914740, 0.252270, -0.651030, -0.342820, -0.137130,
0.704950, -0.558270, -0.341530, -0.652650, 0.928590, 0.449680, -0.994080, -3.221370, -1.586100, -0.864890,
1.217230, 0.410440, 0.621960, 0.415610, 0.303100, 1.006130, -0.584730, -0.765920, -0.134500, 1.137800,
0.941310, -1.703270, 0.057100, 0.978450, 0.889960, 0.090710, 0.852500, 0.029140, -0.850940, 1.645390,
1.150160, 0.473130, -0.622610, -0.175570, -0.015000, 0.131820, 0.596520, 0.892640, 0.315800, -1.052080,
-1.206190, -0.041310, 0.047720, -0.929380, 0.420380, 0.077690, -0.185050, -0.229290, -1.317710, -1.685320,
0.493720, 1.213380, 0.199020, 0.048140, 0.456050, 0.650080, 0.729590, -0.022050, 0.487940, 0.024870,
0.860220, -0.099250, 1.585500, -1.001210, -0.032630, 0.349510, -0.636990, 2.100790, -0.593140, -1.976630,
0.366680, -0.139080, -2.155950, 0.241440, 0.431170, 0.719300, -3.373160, -1.649080, 0.142060, 0.774870,
-0.885490, 0.114360, 1.023610, 1.049610, 1.483840, 1.687670, 0.082140, -0.407720, -0.873790, 0.692600,
0.972560, 1.774150, 0.413730, 0.709470, -0.494340, 0.004290, -0.372220, -3.028450, 0.815230, -1.030660,
0.355740, -0.816470, 1.419820, -0.585610, 0.706360, -1.561140, 0.108480, 0.894240, -0.606700, -0.415410,
-0.601290, 0.278560, 1.002910, 1.756510, 1.048240, -1.044970, -1.147020, -0.913800, 1.168450, -1.136050,
-0.026480, 1.599220, -2.010320, -2.892260, -2.493690, 0.600410, 0.410730, 1.847680, -2.174580, -1.712000,
0.301220, -1.194310, -7.542360, 0.527030, 0.386070, -5.153870, 0.001520, 0.384620, 0.344910, 1.094960,
0.652680, 0.825690, -0.298680, 0.157090, -0.111250, -3.622880, 0.848830, -1.247780, -1.163190, -0.143170,
1.071460, -1.102440, -0.762520, -0.561440, 0.508840, -0.475940, -0.243510, 0.721760, -0.644810, -1.262450,
0.907380, 1.765120, 0.953640, -0.914570, -2.968000, 1.270010, 0.253370, 1.848490, -2.448210, -0.172700,
-1.104060, -0.947790, -0.077610, 0.932980, -0.352770, 0.044940, 1.657880, 1.580370, 2.114650, -0.449420,
1.515180, 0.477960, -1.423510, 0.916550, 0.593130, 0.124800, 0.275600, 0.013900, -0.110630, 0.233270,
1.261250, -1.302480, 0.446290, 1.457950, 0.939610, 0.467390, -0.030510, 1.378580, 0.689240, 0.155410,
3.576440, 0.029740, -1.114650, 1.077460, 0.208270, 0.126430, -0.088390, 0.987420, -0.052790, 1.155590,
-0.591730, -0.366670, -1.063770, 1.017250, 0.322030, -0.417390, -1.519810, -0.306000, 0.697800, 0.312870,
0.914900, -0.033200, -0.956570, -0.663480, -0.919540, -0.374720, 0.626920, 0.177710, -2.427770, -0.247200,
-0.439200, -0.144240, -1.614680, 0.075660, 0.174090, -0.617290, -0.214810, -0.065490, -0.605470, -0.435800,
0.900750, 0.625750, 0.251100, 0.450890, 2.149840, 0.092180, -0.460960, -1.323220, -1.021840, 0.534970,
-0.004100, 0.110220, -0.431720, -39.596100, 0.417890, -0.744910, -0.874480, 1.315610, -0.175400, -0.501700,
0.524730, -0.837680, 3.688080, 0.977530, -1.029720, -1.043200, -0.073460, 1.368570, -1.600770, 0.169480,
0.419260, -3.007270, 0.900950, -0.111450, 0.106850, 0.044900, 0.615750, 0.527440, -0.668030, 0.237930,
1.787830, 0.055400, 1.835920, 1.254190, -0.080040, -0.537840, 0.998590, -0.718840, 0.301110, 0.809880,
-0.240330, 0.688350, 0.679870, -0.449310, -0.041930, -0.235730, -0.119200, 1.493540, -0.272200,
0.006520, 0.546500, -1.191640, 0.033130, 1.026820, -1.252520, 0.291080, -0.121440, 0.681090, 0.096210,
-0.109580, -0.800550, -0.114440, 1.524030, -0.244550, 0.837410, 0.210550, -1.409190, -1.297430, 0.205240,
3.864930, 0.482760, -0.437450, -1.256480, -1.884290, -0.550270, -0.001120, 0.130550, 0.017330, 0.754990,
0.041770, -0.196300, -0.492730, -1.548310, -1.377400, -0.383490, 1.283310, 1.803690, -0.933130, -0.092450,
0.293860, -0.325270, 0.338550, 1.179450, 0.826240, 2.610800, 1.416200, 0.660730, -0.288410, 0.432100,
-0.142660, 0.028700, -0.589510, 1.101460, 0.847330, -1.998810, -2.175010, 1.404870, -0.572150, -0.194250,
0.556280, 0.114650, -0.395070, -1.830290, -0.098920, 0.055480, 2.840960, -0.631200, 1.607760, -0.555100,
0.183400, 1.639080, 1.509340, 0.840230, -0.716320, -1.017330, 0.328820, 0.677910, -0.536600, -1.078900,
-0.802970, 0.809060, -1.535860, -1.259240, 0.025910, -0.680620, 0.921350, 0.487870, -0.216740, 1.549260,
-0.277870, -0.167500, -0.264160, -1.123740, 0.490650, 1.140650, -1.610400, 0.901010, -1.217710, 0.959500,
0.266290, 1.458100, 0.686630, -0.360410, 0.293090, 1.983270, -0.011080, 0.199350, -0.390590, -0.272540,
0.129490, 0.719030, 0.879340, 0.729570, -0.198530, -1.771910, -4.765290, 1.946940, -1.901040, -2.044960,
-1.860730, 1.394290, 0.775940, -2.858680, -3.116800, 0.992840, 0.904490, 0.944320, -4.409090, -1.173470,
1.880040, 0.839390, -8.081930, 0.837110, 0.894510, -11.973140, -5.572600, 7.730200, -1.089450, -0.998610,
-0.535860, -0.160420, 1.449650, 0.290030, -0.523610, 0.530310, -1.405340, -1.012520, 0.090650, -0.597700,
-1.684670, -0.577550, -1.783810, -1.297390, 0.102640, -2.094710, 0.033980, 0.520070, 0.805620, 0.152250,
3.268090, 0.297580, -0.962450, 0.152230, 2.023340, 0.197360, -0.934600, 2.061250, -0.220900, 0.363710,
-0.881350, 1.499630, 1.020540, 0.651400, -0.141890, -0.831570, 1.368550, 0.139780, -1.219650, 1.107670,
0.690020, -0.320210, 0.157320, -0.161490, -2.646530, 0.476950, -0.490910, 1.118960, -1.465660, 0.427650,
0.324060, 1.177810, -0.363400, -1.375620, -1.843240, 1.276880, 1.546940, 0.092010, -2.621590, 0.220520,
-0.047100, 0.260990, 0.655190, 0.726940, 2.343030, 0.315750, 1.530270, -0.583420, -3.467190, -1.484790,
0.879630, -1.525860, -0.996360, -1.337190, -1.514270, 0.055270, -0.888220, -1.408700, 0.726800, 0.686110,
1.120100, -1.393590, -0.277750, 0.007020, -0.768120, -0.245970, 1.833190, 0.398950, 1.341300, 0.406810,
-1.382490, -0.401730, 0.290370, -0.409540, -1.641840, 0.807780, -1.139140, -0.614920, -0.116790, -1.360900,
0.095340, -0.826170, -0.115360, 0.713100, -0.204480, -1.900650, 0.843220, -0.586790, 1.558030, 1.248610,
2.197080, -1.650190, 1.060540, -0.592510, 0.130610, -0.881490, 0.052500, 1.446330, 0.124920, -0.798860,
-0.216050, 0.904390, 0.382230, 2.034500, 0.087290, 0.923600, 0.961630, 0.367670, -0.947450, -0.411320,
0.008750, -0.472340, -0.023560, 0.587880, -0.543000, -0.427220, -0.436450, 0.555920, -0.679620, 0.157030,
0.695390, -0.369060, -0.517820, -0.325000, 0.035040, -0.041890, 0.912090, 0.579630, 0.456690, 0.874940,
-0.588790, 0.494310, -0.874240, 0.220570, -0.496420, 0.185970, -0.584300, -0.642490, 0.710650,
-0.550330, 0.347750, 0.907990, -0.159240, -0.424560, -0.404060, 0.176250, 1.337030, 0.816400, 0.906130,
1.039860, -1.037110, 0.430450, -0.078840, -0.009260, -0.000310, 0.420070, 0.450300, -0.004350, -0.601610,
0.167250, -0.340130, 0.408570, 0.106770, 0.724830, 0.741820, 0.275610, 0.202760, -0.932350, 0.099500,
0.005780, -0.358170, 0.172370, 0.548330, -1.821090, 0.354990, -0.314990, 0.471360, 2.067930, 1.296590,
0.612470, -0.114780, 0.168890, -0.927030, -0.173020, 0.189270, -0.165290, 0.765820, -1.146060, 0.387130,
-0.607110, 0.134030, -0.127550, 0.413820, -0.942700, 0.462090, 1.735030, 0.492830, -0.235800, 2.129330,
1.176510, -1.556110, -0.021470, -0.895840, 0.521270, 0.569560, -0.082030, 0.120400, -0.507100, -0.423020,
-0.589180, -0.130390, 0.366090, -0.171500, -0.757170, -0.500730, 1.917050, 0.386450, 1.474780, 0.537250,
-0.014150, 0.906460, -0.714960, 0.036640, 0.353530, 1.945520, 0.828700, -0.996160, -0.012090, -0.572010,
0.027170, -0.288980, 1.861130, -0.236220, -0.377710, 0.085410, -0.150780, -0.958150, -0.939740, 0.347930,
0.644790, -0.529640, 0.058420, -1.064400, 0.417820, 1.182760, -0.555530, -0.221150, 0.883670, 1.604770,
-0.187280, -0.361710, -0.288330, 0.816760, 0.824150, -1.047230, -2.387400, -0.126800, 1.596330, -0.578240,
0.375300, 0.579390, 0.616980, 0.054420, -1.602010, 0.226050, 2.335430, 0.879510, -0.046640, 0.758560,
0.024180, 0.259890, -1.835720, 0.202430, 0.820440, -0.523310, 0.306970, 1.458600, 0.358310, 0.219020,
-1.216190, -0.573450, -0.510910, -1.843900, 0.550020, 0.025820, -2.275360, -0.886370, -0.060400, -0.475000,
-0.422960, 0.284730, 0.821440, -0.258390, -1.598820, -0.189440, 0.234120, 1.437440, -0.297220, 1.311960,
0.987040, 0.895910, -0.775440, 0.038440, 0.755330, 0.734100, -1.545450, 0.008190, -0.185040, -0.449340,
1.752840, -1.096840, -0.165030, 0.623380, 0.592720, -1.234530, 0.381240, -0.255840, -1.206170, -0.454130,
0.170560, 0.352190, 0.466040, 0.333850, -0.626190, -0.165140, 0.009450, 1.280910, -0.806300, 0.717250,
0.477420, -0.121860, -1.835080, 1.638070, -0.331210, -1.040610, 0.297860, 0.954640, 0.827460, 0.600970,
-0.342000, -1.502090, -0.722740, 0.471810, 0.485830, -2.125740, -0.717950, -0.249400, -1.031120, -1.312150,
0.105990, -0.051750, 1.290550, -0.409820, -0.357790, 0.873650, -0.747840, 1.969620, 0.121300, 0.074140,
0.534000, -0.207070, -0.898990, 0.057020, 0.865190, -0.164920, 0.299470, -0.954030, 0.392140, 0.251860,
0.198670, -0.704420, -0.901800, 1.224620, 0.865320, 0.135690, 0.615250, -0.314230, 0.175770, 0.134110,
-0.246870, -0.946890, -0.012560, 0.729210, -0.247770, 0.646740, 0.997370, 0.083300, 0.116940, 1.272020,
0.117600, 0.418330, 0.126750, -0.289630, 0.280550, -0.433050, 0.340920, 0.236030, 0.257060, 1.087140,
-0.833990, 2.336300, 1.759140, 1.746230, -0.000450, -2.018270, 0.577750, -0.648980, -0.017700, -0.889390,
-0.100280, 0.012330, 0.130980, -0.825850, 0.127060, -0.763900, -0.405570, 0.469820, -0.710690, -0.064860,
0.870540, 0.831440, 0.675700, 0.308230, 0.649840, -0.530880, 0.574610, 1.141990, -0.313360, -0.430600,
-0.309500, -0.449920, 0.503170, 1.064090, -0.651050, 0.335350, 0.011080, 1.060170, 0.585150,
-0.603570, -1.015400, 1.147410, 0.623780, -0.029320, 0.409150, 0.590080, 0.749860, 0.300190, 0.129140,
-0.489270, -0.221340, 0.286690, -1.141380, -0.454540, -0.385500, -0.458710, -0.299250, -0.008710, 0.605590,
-1.400470, 0.116650, -1.724400, -0.444490, -1.224100, -0.587560, 0.338540, -0.763490, -0.181450, 0.512090,
-0.935770, -0.530010, 0.804470, -0.069840, -0.583880, 0.114140, -0.712620, -0.673100, -0.374460, 0.431850,
0.067020, -0.507480, 0.876050, -0.809610, -0.505920, 0.521290, -0.050780, -0.144730, 0.496920, 0.697110,
-0.847470, 0.201800, 0.703740, -0.037420, -0.254570, 0.171880, 0.072830, 0.219010, 0.011430, 1.365620,

-0.621320, -0.601300, 0.338830, 1.289300, 0.398720, -0.167860, 0.188460, 0.766400, -1.156130, 0.605540,
1.238200, -0.617160, 0.957940, 1.456990, -0.302510, 1.685540, -1.130410, 0.393330, -0.547580, -0.367530,
-0.282140, 0.039470, -0.618550, 2.313040, -2.650000, -0.125030, 0.705270, 0.129390, -1.416470, -1.424250,
0.705880, 0.501310, -0.118840, -0.435120, -0.704010, 0.820930, 0.030120, -0.378450, -0.064610, -0.701760,
1.019540, -0.125340, -1.998330, 3.134460, -2.274470, 1.183810, 0.159040, -0.611490, -0.728960, -0.624200,
0.879810, 1.241760, 1.026140, 0.455060, 0.856090, 0.403460, -0.787240, 0.877680, -1.544260, 31.174351,

0.698550, -0.162570, -1.114850, 0.122310, -0.625690, -0.289560, 0.819000, -0.019270, 0.139110, -0.819580,
-0.208360, 0.462360, -0.574630, 0.886220, 0.516760, 0.238650, -0.962440, -0.176900, -0.416790, 0.986430,
0.628890, -0.662760, 0.769890, 0.182130, 0.760950, 0.035580, 1.012840, 0.222080, 1.020790, 0.088690,
0.002150, 0.353570, 0.578780, 0.035170, 0.756670, 0.279060, -0.492310, 1.008790, 0.340290, -0.346040,
0.986250, 0.727000, 0.069570, 0.382880, 2.667950, 0.196470, 1.113330, -0.796290, 0.345010, 0.510710,
-0.838800, 0.145970, -0.633870, 0.305060, -0.567710, -0.437040, 0.884240, -0.953330, 0.129690, 0.101150,

-0.335890, 0.821550, 0.282690, 0.633160, 0.437450, 0.195500, -0.049900, 0.191240, 0.121180, 1.611960,
-0.553360, -0.565510, 0.948140, -0.342570, -0.160890, -0.548670, 0.770910, 0.528810, -0.682150, 0.099970,
-1.118830, -0.650880, 0.483560, 0.121470, -2.769470, 1.820190, 0.071580, -0.709080, 0.694500, 0.277840,
1.056170, 0.950290, 0.254630, 0.721300, -1.403040, 0.722170, -1.548150, -0.941730, -0.767290, -0.988050,
0.547370, 0.366640, -2.293070, -0.296000, 3.361300, 0.757770, -4.984500, -0.538210, 3.891910, 1.565340,
0.413360, 0.225330, -0.584320, -0.892700, 1.065690, -0.107570, 0.332450, 0.151410, 1.018110, 10.760740,

-0.736650, 0.528640, -0.234160, 0.956460, -0.111150, -0.156170, -0.288780, 0.083490, -0.047430, -1.300530,
-0.191230, -0.271740, 0.766740, -0.097120, -0.333560, -1.149760, 0.602150, -0.175720, -0.648010, 0.175840,
-1.214510, -0.287490, -0.182610, -0.004620, -2.685680, -0.454730, 0.157990, -0.302680, -0.705740, -0.297790,
1.729520, 0.859560, -0.582440, -0.826530, -0.685390, -0.467920, 0.195500, -0.070310, -0.353490, -0.766500,
0.311290, -0.028220, 0.488740, -0.122560, 2.355610, 1.621010, 0.887810, -0.569240, 1.586820, 0.632220,
0.503820, 0.496560, -0.196980, 0.734410, -0.602430, -1.063090, -0.049610, -0.234460, 0.295540, 1.189950,

-0.257130, -0.608370, 0.359690, 0.127370, 1.198160, 1.248450, -0.285190, -0.256340, -0.796480, -0.094820,
-1.432480, -0.800650, 0.318840, -0.253140, -0.902030, -1.230060, -1.000040, 0.913560, -0.812910, -0.291840,
0.205940, -1.472160, -1.174190, -0.891000, -0.716820, 0.028370, -0.305100, -0.287620, -0.287880, -0.672520,
1.009030, 0.415580, -0.316190, -0.544210, 0.335390, -1.367490, -0.056480, 0.806940, -0.771660, -0.761900,
0.032360, -0.070790, -1.086460, -0.547090, 4.649290, 0.851860, 0.572770, 0.460740, 1.322580, 0.030210,
0.130850, -0.602430, 0.919850, -0.599610, 0.066980, -0.515540, -0.182860, 0.638510, -0.025840, 3.141230,

-1.613440, 0.040880, 0.766290, 0.676630, 0.016470, 0.012310, -0.584530, 0.448420, -0.304080, 0.069750,
-0.531260, -0.489360, -0.990420, -0.231240, -1.646790, 0.099020, 0.315100, 0.710560, -2.029480, -1.869630,
0.094590, -0.897670, -0.596940, 0.335850, 0.204230, -0.030300, -1.200060, -0.501570, -0.089680, -0.958280,
0.196830, -0.878630, 0.696890, 0.242160, 0.113210, 0.726050, -0.288290, -1.118440, 0.098200, -1.131360,
0.517960, -0.066130, -0.334670, 0.727600, 3.792100, -0.999180, -0.206660, 0.671800, 0.340580, 0.004940,
-0.751860, 0.440630, 0.285490, -0.788250, 0.417550, 0.098140, 0.630170, 0.074440, -0.070270, 1.181670,

0.425760, -0.704570, 0.256070, 0.552320, 0.120080, -0.261260, 0.427870, 0.725100, 0.279410, -0.171760,
1.702940, 0.223870, 0.249730, 0.945680, -1.161960, -0.029240, -0.269000, -0.667880, 0.054560, -1.488780,
1.717440, -0.206370, -1.132540, -0.176340, 1.593360, 0.254330, 0.853780, -0.344730, 0.223100, -0.647240,
0.225560, -0.507500, 0.384950, -0.877920, -0.379930, 1.043320, -0.072050, 1.103220, -0.561530, 0.689480,
-0.763180, 0.068700, -0.304810, -0.115810, -6.337780, 0.519260, -4.941640, -0.253460, 0.270610, -1.270150,
-0.843810, 1.854450, 0.029580, -0.967830, 0.750450, -0.707120, 0.034390, -0.418780, -1.020800, -0.133260,

-1.081000, 0.506210, 1.735880, 3.397180, 0.945460, -0.041610, 0.363520, 0.870780, 0.425910, 1.385870,
0.272920, -0.441600, 0.499790, -0.387330, -0.360050, 0.452120, -0.753510, 0.125960, -1.171500, -0.922380,
-1.374670, -0.446160, -0.591390, 0.521950, 2.802340, 1.592570, 0.732440, 0.050460, -0.478920, -0.194560,
0.959620, 0.505420, 0.128940, -0.214780, -0.211060, 1.445440, -0.378540, 0.232640, 0.627140, -0.500730,
-0.395300, 0.607400, -1.027710, -0.716780, 1.753490, -0.865610, -1.222690, 0.561760, 18.058090, -0.904970,
0.887360, 0.630310, -0.540340, -0.376180, 0.750610, 0.087180, 0.707130, 0.156740, 0.290030, 8.950610,

0.808910, -0.450530, -0.514450, -0.817100, -0.531220, -1.008440, 0.952360, -0.003130, 1.035160, -1.067230,
0.631010, 0.139340, -0.615810, 0.751130, 0.800000, 0.992660, -0.654030, -0.472260, 0.422300, 1.975620,
-0.715470, -0.042090, 0.793950, -0.106140, -0.470320, -0.904360, 0.247270, 0.241600, 0.606980, 0.832100,
0.298600, 0.562010, -0.068230, 0.286840, 0.058630, 0.105030, -0.723300, 0.004190, -0.616000, 0.974120,
0.501840, -0.037060, -0.035400, 0.656960, -1.816190, -0.858770, 0.030800, -0.016560, -1.331320, -0.336740,
0.377960, -0.772110, -0.090350, 0.939040, -0.117330, 0.921270, 0.517900, -0.078610, 0.513480, -1.345960,

0.350000, 0.164000, -0.085190, 0.319530, -0.299240, -0.263800, -0.155980, -0.307170, 0.169910, -0.028440,
-0.144640, -0.682810, 0.532070, -0.167110, -0.277930, -0.199340, 0.624790, 0.150130, -0.455170, -0.023210,
-0.399900, 0.172770, 0.389240, -0.080760, -1.035330, 0.005120, 0.072440, -0.174510, 0.635480, -0.028690,
0.009610, -0.003660, -0.569430, 0.399840, -0.045530, -1.232750, -0.043530, -0.198610, 0.330070, 0.700640,
0.375490, -0.412350, -0.635810, 0.093320, -1.196030, 0.128210, -0.412520, -0.696330, 1.110680, 1.339720,
0.357790, 0.205140, 0.097420, 0.832640, 0.397720, -0.597400, 0.488420, -0.502670, 1.995250, -0.471990,

0.953700, 0.325500, -0.312150, -0.338910, -0.673020, -0.958260, 0.361570, 0.470730, 0.859840, 0.016910,
1.345120, 1.272610, -0.396630, -0.022620, -0.126650, 1.018920, 0.033240, -0.288160, 1.086310, 0.868440,
-0.304600, 1.045630, -0.337510, 1.032730, 2.119230, 0.108680, 0.745530, 0.790690, 1.331540, 0.063390,
-0.756510, 0.842370, -0.150930, -0.636030, 0.484780, 0.117210, -0.770530, 0.754090, -0.103990, 0.585220,
0.173840, -0.360580, -0.372620, 0.813950, 1.542620, 0.331370, 0.102510, -0.525380, -1.592140, 0.869920,
0.170880, 0.177530, -0.748030, -0.754970, 0.389320, -0.621040, -0.282460, -0.061020, -0.739340, -1.085510,

0.999790, 0.384770, 0.466820, -0.761730, -0.752550, 0.215880, -0.711690, -0.156850, 0.842640, 0.728960,
-0.783620, 0.747000, -0.856020, 0.373390, 0.676110, -0.846120, -0.235150, -0.282590, 0.482280, -0.064940,
0.089040, 0.341240, 0.138280, 0.901170, 3.601730, 0.356840, 0.160170, 0.159360, 0.455420, 0.719280,
-0.570250, -0.262290, 0.680370, -0.265730, 0.968160, 0.141180, -0.028670, 0.256790, -0.252270, 0.287200,
-0.014970, -0.136680, 0.389230, -0.205690, 3.872830, 0.526700, 0.844560, -0.698300, -0.757570, 0.209020,
-0.715810, -0.263960, 0.137000, -0.086950, -0.764340, -0.971430, 0.681830, -0.261710, 0.644470, -1.769300,

0.407880, 0.176260, -0.135460, -1.238660, -0.730380, -0.225330, -0.666230, -1.476270, -0.155470, -0.276400,
0.065770, 0.802150, -1.538670, 0.631920, -0.312370, 0.204700, 0.319130, -1.197340, 0.316760, 0.871940,
1.424420, 0.147370, 0.050930, -1.695830, 2.618430, 0.682190, -0.054450, -0.296990, -0.567890, 1.131340,
-0.484720, -1.084660, -0.933960, 0.717990, 0.491630, -1.862340, -0.845210, -0.096560, -1.113620, -0.881320,
0.563500, 0.536730, 0.257110, -0.222670, -2.840830, 0.356260, -1.211010, 0.006870, -1.967420, -0.217090,
0.855920, -0.011330, 0.882330, 0.734490, 0.688190, 0.030040, -0.202900, -0.908430, -0.332460, -7.148350,

-0.323920, -1.235470, 0.596340, 0.446300, -0.888170, -0.752690, -0.682370, 0.345840, -0.071590, 0.977770,
-0.724350, 0.040110, 0.027470, 0.507360, -0.841220, -0.592240, 1.647970, 0.683330, 1.684180, -0.341390,
1.512940, -0.630310, 0.004260, -0.452380, 0.963180, -0.748740, -3.696910, -0.612960, 0.432050, -0.465750,
-1.009520, -0.109100, -0.919820, -0.137020, 0.646320, -2.087870, 0.622500, -1.984040, 0.241080, 0.502760,
-0.822670, -1.039630, 0.448300, -0.003070, -2.484610, 0.437840, 0.494440, 0.381280, -0.520230, -1.069290,
0.673640, 0.007640, -0.552030, -0.575930, -0.561770, -0.453200, 0.352320, 0.692630, -0.106030, 0.553740,

0.505550, -0.232160, -1.140290, -0.118400, -0.246540, 0.116890, 0.868470, 0.378790, -0.268220, -0.437640,
-0.256080, 0.297250, -0.519880, 0.559540, 0.621030, 0.168540, -0.961410, -0.134900, -0.511480, 0.718370,
0.786630, -0.603540, 1.016700, 0.030090, 0.240010, 0.366640, 0.718830, 0.029910, 0.739630, -0.221410,
0.488150, -0.824780, 1.052350, 1.008650, 0.582740, 0.408060, -0.167690, 1.066410, 0.054580, -0.561370,
-0.011400, -0.163930, 0.771700, 0.557360, 0.583470, -0.667390, 1.889130, -0.500240, 0.564300, -0.118280,
-0.218800, 0.165330, 0.167400, -0.030160, -0.449360, 0.009630, -0.459380, 0.806820, 0.499280, -2.562050,

-0.067140, -0.118320, -0.258470, -0.240310, 0.409900, 0.756760, -2.055190, -1.390190, -0.446690, 0.783240,
-0.132690, -0.570450, 0.408590, -0.818130, -0.339230, -0.888640, 0.284760, 0.631980, 0.011590, -3.554370,
1.575060, -0.334410, -0.624490, -0.226100, 0.435520, 1.081470, 0.772090, -0.321850, -0.641880, -0.914020,
0.192260, 0.603290, 0.611600, 0.171600, -0.036300, -0.482480, 0.750470, -0.393080, 0.012470, -0.888060,
0.676010, -0.320020, 0.395730, -0.986060, 0.368170, 0.236430, -0.370910, 0.023470, -0.632360, 0.551270,
0.699490, 0.154550, -0.140010, -0.211990, -0.515920, -0.666960, -1.065650, -0.788110, 0.440640, -5.014910,

0.434420, 0.943750, -0.307720, -0.503890, -0.666410, -1.133140, 0.777970, 0.835200, 1.983030, 0.399540,
-0.124690, -0.032580, 0.209980, -0.401420, 2.470430, 0.503940, 3.630070, -1.196360, 2.655090, 0.728730,
-0.018520, 2.245490, -1.893810, -0.118430, -2.270440, 0.221240, 0.737710, -0.121800, 1.300460, -0.082610,
-0.201300, 0.820530, -0.526100, 0.266000, -0.437620, -0.169060, 0.701160, 3.296850, -0.753090, 0.901260,
-0.364510, 0.552200, -0.412850, 0.900560, 4.024710, 0.185990, 7.117270, 0.832510, -1.974520, -0.568360,
-0.793150, 0.516820, -0.138820, -0.693210, -0.409870, 0.090320, 1.007680, 0.590450, -0.246740, -2.735750,

0.101940, -0.371340, -1.703830, -0.844100, -0.294310, 0.112750, 0.022250, -0.301700, 0.113690, 0.780830,
-0.290300, -1.762730, 0.041420, -0.340620, 0.188140, 0.006860, -0.473630, -0.013640, -1.131420, -0.098280,
0.326680, -0.054570, -0.986780, -1.717040, -0.924340, -2.037900, -0.130720, -0.698430, -0.730930, -0.080680,
0.894910, 0.047430, -0.422310, 0.244620, 0.171770, -0.297720, -0.631270, -0.058590, -0.059060, 0.174660,
-0.407600, -0.373140, -0.909720, 0.498230, 0.648760, -0.610610, 2.756800, 0.418110, 0.849840, -0.373810,
0.590570, -0.023740, -0.945950, -1.048880, 0.131330, 0.880190, 0.720240, -0.373870, -0.560730, -1.429840,

-1.499370, -0.012960, 1.087510, 1.481090, -0.345190, -0.203450, -0.468830, -0.042720, -0.053000, -0.709900,
-0.284170, -0.653250, 0.027280, 0.155790, -0.518150, -0.683550, 0.531930, 0.535460, -1.442280, -1.234990,
-0.218440, -0.615060, 0.200770, -0.086380, -0.646460, 0.159650, -0.409010, -0.448530, -0.848490, 0.472410,
-0.340620, 0.593670, 0.534370, 0.479130, 0.781020, -0.234030, 0.792800, 0.121570, -0.025890, 0.672870,
1.121160, -0.130760, 0.151780, 0.108620, -0.759680, 0.162630, -1.037940, -0.505510, 0.017010, -0.322470,
-0.490510, -0.449240, -0.137970, -0.247700, -0.776920, -0.446170, -0.520810, 0.697950, 0.636550, 0.305750,

0.256640, 0.360520, -0.262920, -0.521540, -0.457800, -0.543390, -0.203270, -0.407400, 0.538130, -0.306410,
0.651640, 0.623420, -0.438030, 0.103150, -0.103770, 0.314780, 0.421270, -0.044470, 0.316950, -0.198210,
0.134900, 0.357830, 0.044470, 0.449020, 0.773330, -0.217410, -0.007310, 0.140530, 0.301700, -0.452790,
0.078530, 0.283110, -0.229950, 0.175360, -0.474480, 0.104960, 0.079750, -0.189410, -0.552870, -0.100020,
0.609330, 0.274050, -0.093160, 0.178700, 1.151510, -0.406640, 0.087210, -0.959420, -0.285700, 0.109110,
-0.026650, 0.878570, 0.670490, 0.797000, 0.462590, 0.604690, 0.419990, -0.257900, -0.327360, -1.870330,

-0.111790, -0.494160, -0.623920, -0.892350, -0.001000, -0.100910, 0.674640, -0.959920, 0.194900, -0.827100,
0.814970, 0.803490, 0.186330, 1.361710, -0.178990, -0.018890, 0.755870, 0.762400, 1.250900, 0.070840,
1.437970, 0.692990, 0.388660, -0.866620, 1.136660, -0.118580, 0.133140, 0.026460, 0.534510, -0.616380,
-0.033420, 0.630220, 0.141240, 0.460100, 0.136570, -2.273320, 0.200860, 2.563990, -0.865670, -0.281920,
-0.443240, -0.724590, -0.517410, 0.083230, -3.276530, 0.282470, -3.421450, -0.429390, -0.367520, -0.233270,
0.686130, 0.833130, -0.890600, -0.292310, 0.449460, 0.676000, -0.512950, -0.291590, -0.143480, -36.021439,

-0.889500, -0.377260, 1.096890, 1.232320, 0.306150, -0.220500, -0.575520, 0.632170, -1.166640, 1.112160,
0.828090, -0.373600, 0.329060, 1.975020, 0.228340, 1.136880, -0.746180, 0.752090, -0.612920, -0.742420,
-0.247540, 0.382080, -0.606480, 1.913850, -0.972460, 0.435480, 0.974570, 0.524320, -1.608040, 0.118610,
0.234020, -0.026330, -1.479150, 0.374790, -0.384510, -0.826200, -0.493270, -0.436250, 0.485990, 0.062990,
-0.808590, 1.201860, -2.326590, 0.794490, -1.673820, 3.700630, 2.451510, 0.672520, 0.471910, 0.731460,
-0.199870, 0.912220, -0.231480, -0.395760, 0.147210, -0.271230, 1.085530, 0.149550, -0.830790, 118.900909,

0.203750, -0.024620, 0.749500, -0.200800, 1.150070, 0.103480, -0.186990, 1.785410, -0.004350, 0.785730,
0.190220, 0.409820, -0.325000, -0.792570, 0.446710, -1.215120, 1.609350, 0.929190, 0.329450, 0.067340,
0.557710, 0.845430, -0.155620, 0.539150, -0.256530, 1.833710, 0.159780, -0.462780, 0.716050, -0.038590,
0.245380, 0.822290, -0.191370, 0.593210, 0.546200, -0.553300, 0.226800, 1.031290, -0.744350, -0.086460,
-0.391460, 0.167820, 0.526260, 1.501030, -0.290840, -0.091390, -0.832520, -0.425320, 0.421400, 0.294460,
0.257380, 1.254900, -0.547770, -0.445580, -0.521930, 0.609360, -0.332140, 0.548550, 0.119060, -1.994180,

-0.866790, 0.802180, 8.041760, 2.239130, 1.002770, -0.269720, -0.598630, 1.510680, -0.233640, 1.363980,
-0.607140, -0.276550, 2.023090, 0.006250, 0.209790, -0.022350, -0.503160, -0.276790, -0.975230, -0.321690,
-1.179520, 0.954600, -0.438900, -0.155470, -2.582140, 2.097990, 0.498290, -0.294090, -0.221590, -0.502140,
1.072820, 0.646870, -0.492960, 0.769540, -1.046030, 4.991270, -0.589850, -0.540930, 0.650540, -0.481010,
-0.332540, 0.840190, -0.718610, 0.762340, -0.143150, 0.316960, 1.102940, -0.828300, 2.581350, 1.077020,
0.259390, -0.492290, -0.173830, 0.214480, 0.428880, 0.236530, 0.596640, 0.347080, -0.045060, -3.462510,

-1.486710, 0.754620, 2.962170, 2.770230, 1.134660, 0.145360, 0.424690, 0.847810, 0.720740, 1.302760,
-0.211290, -0.729950, 0.980070, -0.513130, -0.268650, -0.055160, 0.039040, 0.962230, -0.814500, 0.010980,
-0.833670, -0.213680, -0.348830, 0.320180, -3.961600, 0.915390, 0.120140, 0.577690, -0.062120, 0.233970,
0.109570, 0.636340, 0.630750, 0.420500, -0.365960, -1.405940, 0.276820, -0.233210, 0.788030, -0.813650,
0.607300, -0.330850, -0.839130, -0.211220, 1.319950, -0.596360, -1.222280, 0.090920, 0.781640, -1.116620,
-0.796430, 0.012480, -0.060220, 0.939430, 0.209200, -0.198880, -0.424240, 0.626350, -0.948730, 27.935431,

1.562720, -0.507820, 0.497370, -0.988100, -0.695080, -3.149830, 0.615000, -0.243310, -0.418710, 0.009770,
0.277450, 1.692590, 0.767710, 1.693060, 0.495980, 1.043120, 1.977990, 0.336490, -3.340050, 8.204500,
-2.125220, 4.299950, -3.495270, 0.571160, -3.620040, -0.765980, 20.630590, 1.373380, -2.686450, -0.089100,
0.531260, 0.219160, 1.303740, -0.453270, 4.625680, -3.474880, 0.012040, -0.247820, 0.913490, 0.608670,
-0.181820, -0.126210, -0.358120, 4.697600, 29.306110, -0.486720, -1.218430, 1.163260, -0.578570, -0.251430,
1.197400, 0.170490, -0.131800, -0.339450, 0.141900, -0.363070, 1.033030, 1.281400, 5.009630, -6.882800,

0.396280, -0.720920, -0.485030, -0.431710, 0.711090, 0.278620, 0.564160, -0.352290, -0.600750, -0.497400,
0.919370, 37.478920, 0.217430, 0.280720, 0.981980, 0.966360, 0.619940, 0.178920, 0.038110, -0.556850,
0.066370, -0.384030, 0.738120, -0.418800, 56.678310, 2.078650, -0.165340, -0.293010, 0.536920, -0.748830,
-0.862950, -0.239020, -0.840390, 0.955080, -0.253260, 0.352380, -0.891520, -0.339570, 0.531840, 0.566810,
0.712260, 0.357170, -0.222970, -0.113000, 2.915580, -0.240350, 0.380210, 0.252670, 10.338010, -0.560280,
-0.426720, 0.393750, 0.642590, 0.199370, -0.196430, 0.616650, -0.622200, 0.825600, -0.756150, -1.791270,

-0.608050, 0.408670, 0.006680, -0.371280, -0.199510, -0.211140, -0.526910, -0.460720, -0.068510, 0.402150,
-0.278650, -0.558780, 0.424330, -0.640690, -0.066750, 0.704130, 0.557670, 0.528130, -0.332020, -1.007390,
-0.014270, 1.741460, 0.211690, 0.932730, -1.097630, 0.870600, -0.989940, 0.443590, 0.562280, -0.641730,
-0.490160, 0.052850, -0.174110, -0.789320, 0.764150, 0.682780, 0.711390, 0.517240, 0.101180, 0.329330,
-0.131110, 0.681780, -0.274340, -0.614640, 1.192960, -0.276360, 0.593640, 0.234220, -0.877850, 0.015770,
-0.226970, -0.687470, 0.011340, 0.086420, -0.452630, -0.927980, -0.767030, -0.905900, 0.576130, 0.326590,

-0.197240, -1.557590, -3.872500, 0.081170, 1.044540, 1.151170, 0.992350, -0.708270, 0.482820, -0.994890,
0.179770, -0.802810, -0.857510, -0.541640, -0.395520, -0.409000, -2.812400, 0.043270, -1.420870, -0.480540,
-0.168890, -1.961380, -1.777530, -0.831550, -2.113500, -1.508800, 0.150820, 0.385970, -0.481130, -1.057640,
0.814010, -0.021950, 0.667110, 0.333540, -0.170520, 0.895070, -0.576850, 0.299740, 0.490410, -1.046110,
0.786950, -0.256670, -0.680480, 0.348280, 2.232300, 0.343460, 0.751010, 0.709790, -0.169000, 0.336230,
-0.688400, 0.277380, 0.332680, 0.060540, 0.193770, -0.987240, -0.832250, -0.308470, 0.152490, 0.979360,

-0.194220, -0.083410, 0.838040, 0.174050, 1.117200, -2.438570, -0.136320, 0.166670, -0.505650, 0.183040,
0.257820, 0.795990, 1.670450, 0.514900, 0.001770, 0.764970, 0.330380, 0.579670, -2.010570, 0.641710,
-0.032520, -0.142750, 1.026900, 0.380970, 1.067300, 0.317960, 1.021730, -0.411920, -1.037910, -9.830740,

-0.392660, -0.085090, 1.471050, 0.983750, 1.311180, -2.329280, -0.774510, 0.343680, 0.632090, -0.433470,
0.150700, 0.704830, 1.698540, 1.294420, 0.619760, 0.042640, -0.312510, -0.038390, -1.962110, 0.262430,
0.073660, -0.277470, 0.873150, 0.635670, 0.497110, -0.059310, 0.703660, -0.034590, -0.749250, -10.025670,

-0.890240, 0.649620, 0.864470, 0.050190, 0.993080, -1.839050, -0.567080, 0.662290, -0.064390, -0.176770,
0.972410, 1.080050, 2.142560, 0.964070, 0.414990, 0.145530, -0.760420, 0.200560, -1.756680, 0.270970,
-0.557530, 0.093130, 0.723270, 0.454080, 0.263690, -0.208720, 0.977030, 0.080910, -0.802570, -9.660960,

-0.905090, -0.104180, 1.051300, 0.226610, 0.946900, -1.449920, -1.068450, 0.768880, 0.768950, -0.354910,
0.299320, 0.980000, 2.091230, 0.732160, 0.753080, -0.041420, -1.117950, 0.913570, -1.586890, 0.614020,
0.165550, -0.128240, 0.262810, 0.111490, -0.585400, 0.179730, 0.545390, 0.843270, -0.817860, -9.098920,

-0.690230, 0.946490, 0.781570, 0.350560, 1.072820, -0.892600, -0.723820, 1.197000, 0.743490, 0.415690,
1.000890, 1.115270, 1.685120, 1.065010, 0.644500, 0.161970, -1.147030, 0.944690, -2.140230, 0.221550,
0.430700, -0.028910, 0.117390, -0.638720, -0.872980, -0.960280, 0.258700, -0.700480, -0.369870, -9.763430,

-0.578820, 0.217610, 0.830670, -0.189250, 0.650210, -0.791440, -0.273430, 0.757470, 0.566920, 0.635310,
0.543700, 1.360420, 1.399020, 1.303440, -0.113170, 0.276480, -1.117800, -0.483690, -1.208290, 0.538540,
0.247990, 0.308290, -0.699530, 0.724770, 0.862090, 0.390930, 0.240780, -0.747610, -0.249020, -9.627290,

-0.635910, 0.454830, 1.410610, -0.644600, 0.657210, -1.474880, 0.163590, 0.927740, 0.702850, 0.426680,
0.520610, 0.516940, 1.496860, 0.946630, -0.267210, -0.583860, -1.255070, 0.092530, -1.992370, -0.641560,
-0.238400, 0.300630, 0.114500, 0.543920, -0.804150, 0.413080, 1.064750, -0.809860, -0.499420, -9.385810,

-0.621510, 0.433660, 0.628340, 0.310430, 0.446040, -0.617120, -0.236550, 0.779710, -0.813280, 0.886830,
-0.834180, 1.084830, 1.279610, 1.053630, -0.463240, 0.317760, -1.250980, 1.040390, -1.092680, 0.345090,
0.206210, 0.387240, -0.061150, -0.686260, 0.740420, -0.050750, 0.346720, -0.711420, -0.103330, -10.528390,

-0.815180, -0.697450, 0.536180, -0.504830, 0.469080, -0.695790, -0.518430, 0.871310, 0.244040, 0.587030,
-0.082910, 0.790920, 1.123150, 1.092630, -0.645430, 0.224070, -1.489800, -0.233320, -1.521770, 0.120590,
0.352150, 0.254100, -0.627120, 0.981160, 1.076950, -0.395790, 0.691400, -0.587620, -0.314200, -9.712980,

-0.749850, -0.251270, 0.169070, 0.475040, 0.343510, -0.445260, -0.460370, 0.864840, -0.803030, 0.723810,
-1.017160, 0.782400, 1.163300, 0.869940, -0.840880, 0.598470, -1.583190, 0.907050, -1.377420, 0.041390,
0.626040, 0.338500, 0.779430, -0.185100, -0.281660, -0.932040, 0.046840, 0.231690, -0.213360, -10.979060,

-0.945690, -0.134320, 0.764660, -0.124980, 0.364090, -1.069940, 0.080920, 0.865100, 0.368420, 0.775250,
-0.349830, 0.489470, 1.225310, 0.838120, -1.449750, -0.169290, -1.394990, 0.893940, -1.781590, -0.709450,
-0.525400, 0.500400, -0.243220, 0.547710, -0.585030, 0.572770, -0.019030, 0.368420, -0.424140, -10.523810,

-0.854510, -0.835840, 0.369620, -0.649470, 0.176310, -0.974950, -0.129800, 0.903920, 0.418830, 0.369970,
0.904190, 0.447070, 1.147230, 0.894110, -1.642200, 0.203110, -1.717670, 1.010730, -1.560880, -0.762870,
-0.104540, 0.425000, 0.419960, -0.469280, 1.032400, -0.137780, -0.614890, -0.524120, -0.551420, -10.465810,

-0.906670, 1.145420, -0.250040, -0.201940, 0.185060, -0.535380, -0.416830, 0.909710, -0.094190, 0.673230,
0.749560, 0.752540, 1.218450, 1.043360, -1.706730, 0.583440, -1.612280, -0.629690, -1.386280, -0.504030,
-0.004020, 0.422140, -0.645640, -0.437810, -0.674930, 1.083900, -0.983340, 0.564320, -0.571820, -10.337020,

-0.836140, 0.812150, 0.862420, -0.655790, -0.268230, -0.688050, -0.659870, 0.932480, -0.666230, 0.115460,
-0.845900, 0.111280, 0.898910, 0.762960, -1.947660, -0.360690, -2.058540, 0.334260, -1.179690, -0.593660,
0.766080, 0.245500, -0.624160, 1.080490, -0.091280, 0.274300, 0.043520, -0.359850, -0.494190, -9.543840,

-1.000860, 0.916270, -0.040310, 0.245880, -0.197060, -0.429500, -0.327240, 0.941860, -0.122150, 1.014800,
-0.053590, 0.703460, 1.016440, 1.001160, -2.310430, 0.239080, -1.482680, 0.571370, -1.004560, -0.548320,
-0.522680, 0.530770, -0.757630, -0.414820, 0.633390, -0.951310, -0.083980, -0.222880, -0.502270, -9.974680,

-0.928020, -0.386230, 0.027770, 0.152160, -0.501750, -0.703450, -0.738670, 0.890720, 0.667300, -0.054280,
0.067770, 0.530150, 0.809330, 0.890090, -2.398690, 0.272680, -2.158700, 0.114660, -0.693730, -0.536420,
-0.073050, 0.512850, -0.163920, 0.612940, -0.831780, -0.735350, 1.026250, -0.891840, -0.607810, -8.618700,

-0.604750, -0.926150, 0.045800, -0.353260, -0.710570, -0.795630, -0.469810, 1.079820, -0.454790, 0.871270,
0.293990, -0.055210, 0.745540, 0.890040, -2.587210, 0.168640, -1.530830, -0.615520, -1.179000, -0.716760,
0.658850, 0.508990, -0.136800, -0.379280, 0.319380, -0.315340, 0.533750, 0.465590, -0.609590, -9.146250,

-0.823900, -0.723720, 0.816590, -0.790160, -0.733400, -0.804670, -0.567670, 0.741260, 0.375400, -0.167300,
0.365590, 0.229540, 0.498950, 0.926910, -2.545020, -0.623670, -1.980270, 0.909500, -0.503180, -0.901110,
-0.292360, 0.573860, 0.387110, 0.690420, -0.190320, -0.562750, -0.443090, 0.889010, -0.670270, -7.730450,

-0.651210, -0.818210, 0.253890, -0.113310, -1.028750, -0.270860, -0.926090, 0.589260, -1.151410, -0.298440,
-0.631190, 0.551570, 0.318680, 0.885840, -2.368990, -0.186300, -1.703040, -0.467860, -0.138390, -0.624740,
0.635150, 0.616780, 0.515710, 0.278420, -0.737040, 0.366420, 0.556070, -0.004170, -0.768890, -6.842540,

-0.434380, -0.080420, -0.104620, -0.272190, -1.327420, -0.835860, -0.740350, 0.622760, -0.704360, 0.766080,
-0.506610, 0.114670, 0.399940, 0.926420, -2.275500, -0.102510, -1.288620, -0.202160, -0.491090, -0.696650,
-0.054320, 0.825150, -0.683810, 0.334100, -0.954100, 0.736530, 0.628580, 0.269330, -0.726440, -5.302020,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
  static UnitType Units[410] =
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
      0.0, 0.417050, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, 0.350230, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, -0.743560, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, -0.032960, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, -0.925190, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -1.076310, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.685350, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, -0.368890, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, -0.749160, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.626040, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, -0.243420, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, -1.826690, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.222030, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, -0.747130, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, 1.033410, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, -0.183550, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, 0.421040, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, 0.346920, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, -0.610060, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, 0.035540, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, 0.265970, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.461070, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, -0.282270, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.775720, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, -3.007900, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, 0.815960, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, -0.378610, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, -0.197970, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, 0.011770, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.694690, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.147150, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, 0.622770, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, 0.043820, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, 0.953770, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, 0.440010, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, 0.498460, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 0.876040, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, 0.226500, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, 0.990060, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -0.926690, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, 0.693810, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, 0.883700, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, 0.003730, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, -0.272170, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -1.147240, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, -0.406690, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, -0.615370, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, 0.091480, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, 0.043110, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -0.521950, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, -0.791250, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 0.871510, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 0.412340, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, 0.438610, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, -0.300960, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, 0.329400, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.552890, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, 0.775340, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, 0.814670, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.251690, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, -0.067490, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out2) */
      0.0, -0.218280, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out3) */
      0.0, -0.323940, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out4) */
      0.0, -0.584630, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out5) */
      0.0, 0.258390, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out6) */
      0.0, -0.951600, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out7) */
      0.0, 0.177490, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out8) */
      0.0, 0.169920, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (out9) */
      0.0, 0.420550, 30,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (out10) */
      0.0, 0.619510, 30,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 340 (out11) */
      0.0, -0.544540, 30,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 341 (out12) */
      0.0, 0.056660, 30,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 342 (out13) */
      0.0, -0.065310, 30,
       &Sources[11130] ,
       &Weights[11130] ,
      },
    { /* unit 343 (out14) */
      0.0, 0.599280, 30,
       &Sources[11160] ,
       &Weights[11160] ,
      },
    { /* unit 344 (out15) */
      0.0, -0.272820, 30,
       &Sources[11190] ,
       &Weights[11190] ,
      },
    { /* unit 345 (out16) */
      0.0, 0.392430, 30,
       &Sources[11220] ,
       &Weights[11220] ,
      },
    { /* unit 346 (out17) */
      0.0, 0.239060, 30,
       &Sources[11250] ,
       &Weights[11250] ,
      },
    { /* unit 347 (out18) */
      0.0, -0.926350, 30,
       &Sources[11280] ,
       &Weights[11280] ,
      },
    { /* unit 348 (out19) */
      0.0, 0.856100, 30,
       &Sources[11310] ,
       &Weights[11310] ,
      },
    { /* unit 349 (out20) */
      0.0, -0.399700, 30,
       &Sources[11340] ,
       &Weights[11340] ,
      },
    { /* unit 350 (con11) */
1.00916, 0.500000, 2,
       &Sources[11370] ,
       &Weights[11370] ,
      },
    { /* unit 351 (con12) */
0.42967, 0.500000, 2,
       &Sources[11372] ,
       &Weights[11372] ,
      },
    { /* unit 352 (con13) */
0.02940, 0.500000, 2,
       &Sources[11374] ,
       &Weights[11374] ,
      },
    { /* unit 353 (con14) */
0.32994, 0.500000, 2,
       &Sources[11376] ,
       &Weights[11376] ,
      },
    { /* unit 354 (con15) */
0.00592, 0.500000, 2,
       &Sources[11378] ,
       &Weights[11378] ,
      },
    { /* unit 355 (con16) */
0.00485, 0.500000, 2,
       &Sources[11380] ,
       &Weights[11380] ,
      },
    { /* unit 356 (con17) */
0.07284, 0.500000, 2,
       &Sources[11382] ,
       &Weights[11382] ,
      },
    { /* unit 357 (con18) */
1.39643, 0.500000, 2,
       &Sources[11384] ,
       &Weights[11384] ,
      },
    { /* unit 358 (con19) */
0.03027, 0.500000, 2,
       &Sources[11386] ,
       &Weights[11386] ,
      },
    { /* unit 359 (con110) */
0.09180, 0.500000, 2,
       &Sources[11388] ,
       &Weights[11388] ,
      },
    { /* unit 360 (con111) */
1.09833, 0.500000, 2,
       &Sources[11390] ,
       &Weights[11390] ,
      },
    { /* unit 361 (con112) */
0.00991, 0.500000, 2,
       &Sources[11392] ,
       &Weights[11392] ,
      },
    { /* unit 362 (con113) */
1.30246, 0.500000, 2,
       &Sources[11394] ,
       &Weights[11394] ,
      },
    { /* unit 363 (con114) */
0.00001, 0.500000, 2,
       &Sources[11396] ,
       &Weights[11396] ,
      },
    { /* unit 364 (con115) */
1.09839, 0.500000, 2,
       &Sources[11398] ,
       &Weights[11398] ,
      },
    { /* unit 365 (con116) */
0.00155, 0.500000, 2,
       &Sources[11400] ,
       &Weights[11400] ,
      },
    { /* unit 366 (con117) */
0.33984, 0.500000, 2,
       &Sources[11402] ,
       &Weights[11402] ,
      },
    { /* unit 367 (con118) */
0.00483, 0.500000, 2,
       &Sources[11404] ,
       &Weights[11404] ,
      },
    { /* unit 368 (con119) */
0.00124, 0.500000, 2,
       &Sources[11406] ,
       &Weights[11406] ,
      },
    { /* unit 369 (con120) */
0.09840, 0.500000, 2,
       &Sources[11408] ,
       &Weights[11408] ,
      },
    { /* unit 370 (con121) */
0.09058, 0.500000, 2,
       &Sources[11410] ,
       &Weights[11410] ,
      },
    { /* unit 371 (con122) */
1.00988, 0.500000, 2,
       &Sources[11412] ,
       &Weights[11412] ,
      },
    { /* unit 372 (con123) */
0.10518, 0.500000, 2,
       &Sources[11414] ,
       &Weights[11414] ,
      },
    { /* unit 373 (con124) */
1.42047, 0.500000, 2,
       &Sources[11416] ,
       &Weights[11416] ,
      },
    { /* unit 374 (con125) */
0.00000, 0.500000, 2,
       &Sources[11418] ,
       &Weights[11418] ,
      },
    { /* unit 375 (con126) */
1.02434, 0.500000, 2,
       &Sources[11420] ,
       &Weights[11420] ,
      },
    { /* unit 376 (con127) */
1.00869, 0.500000, 2,
       &Sources[11422] ,
       &Weights[11422] ,
      },
    { /* unit 377 (con128) */
1.09033, 0.500000, 2,
       &Sources[11424] ,
       &Weights[11424] ,
      },
    { /* unit 378 (con129) */
1.00833, 0.500000, 2,
       &Sources[11426] ,
       &Weights[11426] ,
      },
    { /* unit 379 (con130) */
1.41662, 0.500000, 2,
       &Sources[11428] ,
       &Weights[11428] ,
      },
    { /* unit 380 (con21) */
0.19403, 0.500000, 2,
       &Sources[11430] ,
       &Weights[11430] ,
      },
    { /* unit 381 (con22) */
1.42645, 0.500000, 2,
       &Sources[11432] ,
       &Weights[11432] ,
      },
    { /* unit 382 (con23) */
1.08825, 0.500000, 2,
       &Sources[11434] ,
       &Weights[11434] ,
      },
    { /* unit 383 (con24) */
1.38185, 0.500000, 2,
       &Sources[11436] ,
       &Weights[11436] ,
      },
    { /* unit 384 (con25) */
0.30880, 0.500000, 2,
       &Sources[11438] ,
       &Weights[11438] ,
      },
    { /* unit 385 (con26) */
0.01352, 0.500000, 2,
       &Sources[11440] ,
       &Weights[11440] ,
      },
    { /* unit 386 (con27) */
0.15915, 0.500000, 2,
       &Sources[11442] ,
       &Weights[11442] ,
      },
    { /* unit 387 (con28) */
0.00567, 0.500000, 2,
       &Sources[11444] ,
       &Weights[11444] ,
      },
    { /* unit 388 (con29) */
1.42343, 0.500000, 2,
       &Sources[11446] ,
       &Weights[11446] ,
      },
    { /* unit 389 (con210) */
1.37880, 0.500000, 2,
       &Sources[11448] ,
       &Weights[11448] ,
      },
    { /* unit 390 (con211) */
1.41272, 0.500000, 2,
       &Sources[11450] ,
       &Weights[11450] ,
      },
    { /* unit 391 (con212) */
1.22911, 0.500000, 2,
       &Sources[11452] ,
       &Weights[11452] ,
      },
    { /* unit 392 (con213) */
0.60707, 0.500000, 2,
       &Sources[11454] ,
       &Weights[11454] ,
      },
    { /* unit 393 (con214) */
0.03400, 0.500000, 2,
       &Sources[11456] ,
       &Weights[11456] ,
      },
    { /* unit 394 (con215) */
0.01033, 0.500000, 2,
       &Sources[11458] ,
       &Weights[11458] ,
      },
    { /* unit 395 (con216) */
0.84116, 0.500000, 2,
       &Sources[11460] ,
       &Weights[11460] ,
      },
    { /* unit 396 (con217) */
0.01390, 0.500000, 2,
       &Sources[11462] ,
       &Weights[11462] ,
      },
    { /* unit 397 (con218) */
1.42794, 0.500000, 2,
       &Sources[11464] ,
       &Weights[11464] ,
      },
    { /* unit 398 (con219) */
0.00784, 0.500000, 2,
       &Sources[11466] ,
       &Weights[11466] ,
      },
    { /* unit 399 (con220) */
0.36517, 0.500000, 2,
       &Sources[11468] ,
       &Weights[11468] ,
      },
    { /* unit 400 (con221) */
1.27435, 0.500000, 2,
       &Sources[11470] ,
       &Weights[11470] ,
      },
    { /* unit 401 (con222) */
0.12079, 0.500000, 2,
       &Sources[11472] ,
       &Weights[11472] ,
      },
    { /* unit 402 (con223) */
1.42365, 0.500000, 2,
       &Sources[11474] ,
       &Weights[11474] ,
      },
    { /* unit 403 (con224) */
1.41765, 0.500000, 2,
       &Sources[11476] ,
       &Weights[11476] ,
      },
    { /* unit 404 (con225) */
1.42629, 0.500000, 2,
       &Sources[11478] ,
       &Weights[11478] ,
      },
    { /* unit 405 (con226) */
1.39893, 0.500000, 2,
       &Sources[11480] ,
       &Weights[11480] ,
      },
    { /* unit 406 (con227) */
1.42856, 0.500000, 2,
       &Sources[11482] ,
       &Weights[11482] ,
      },
    { /* unit 407 (con228) */
1.41271, 0.500000, 2,
       &Sources[11484] ,
       &Weights[11484] ,
      },
    { /* unit 408 (con229) */
0.36354, 0.500000, 2,
       &Sources[11486] ,
       &Weights[11486] ,
      },
    { /* unit 409 (con230) */
0.00140, 0.500000, 2,
       &Sources[11488] ,
       &Weights[11488] ,
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

  static pUnit Output1[20] = {Units + 330, Units + 331, Units + 332, Units + 333, Units + 334, Units + 335, Units + 336, Units + 337, Units + 338, Units + 339, Units + 340, Units + 341, Units + 342, Units + 343, Units + 344, Units + 345, Units + 346, Units + 347, Units + 348, Units + 349}; /* members */

  static pUnit Special1[1] = {Units + 350}; /* members */

  static pUnit Special2[1] = {Units + 351}; /* members */

  static pUnit Special3[1] = {Units + 352}; /* members */

  static pUnit Special4[1] = {Units + 353}; /* members */

  static pUnit Special5[1] = {Units + 354}; /* members */

  static pUnit Special6[1] = {Units + 355}; /* members */

  static pUnit Special7[1] = {Units + 356}; /* members */

  static pUnit Special8[1] = {Units + 357}; /* members */

  static pUnit Special9[1] = {Units + 358}; /* members */

  static pUnit Special10[1] = {Units + 359}; /* members */

  static pUnit Special11[1] = {Units + 360}; /* members */

  static pUnit Special12[1] = {Units + 361}; /* members */

  static pUnit Special13[1] = {Units + 362}; /* members */

  static pUnit Special14[1] = {Units + 363}; /* members */

  static pUnit Special15[1] = {Units + 364}; /* members */

  static pUnit Special16[1] = {Units + 365}; /* members */

  static pUnit Special17[1] = {Units + 366}; /* members */

  static pUnit Special18[1] = {Units + 367}; /* members */

  static pUnit Special19[1] = {Units + 368}; /* members */

  static pUnit Special20[1] = {Units + 369}; /* members */

  static pUnit Special21[1] = {Units + 370}; /* members */

  static pUnit Special22[1] = {Units + 371}; /* members */

  static pUnit Special23[1] = {Units + 372}; /* members */

  static pUnit Special24[1] = {Units + 373}; /* members */

  static pUnit Special25[1] = {Units + 374}; /* members */

  static pUnit Special26[1] = {Units + 375}; /* members */

  static pUnit Special27[1] = {Units + 376}; /* members */

  static pUnit Special28[1] = {Units + 377}; /* members */

  static pUnit Special29[1] = {Units + 378}; /* members */

  static pUnit Special30[1] = {Units + 379}; /* members */

  static pUnit Special31[1] = {Units + 380}; /* members */

  static pUnit Special32[1] = {Units + 381}; /* members */

  static pUnit Special33[1] = {Units + 382}; /* members */

  static pUnit Special34[1] = {Units + 383}; /* members */

  static pUnit Special35[1] = {Units + 384}; /* members */

  static pUnit Special36[1] = {Units + 385}; /* members */

  static pUnit Special37[1] = {Units + 386}; /* members */

  static pUnit Special38[1] = {Units + 387}; /* members */

  static pUnit Special39[1] = {Units + 388}; /* members */

  static pUnit Special40[1] = {Units + 389}; /* members */

  static pUnit Special41[1] = {Units + 390}; /* members */

  static pUnit Special42[1] = {Units + 391}; /* members */

  static pUnit Special43[1] = {Units + 392}; /* members */

  static pUnit Special44[1] = {Units + 393}; /* members */

  static pUnit Special45[1] = {Units + 394}; /* members */

  static pUnit Special46[1] = {Units + 395}; /* members */

  static pUnit Special47[1] = {Units + 396}; /* members */

  static pUnit Special48[1] = {Units + 397}; /* members */

  static pUnit Special49[1] = {Units + 398}; /* members */

  static pUnit Special50[1] = {Units + 399}; /* members */

  static pUnit Special51[1] = {Units + 400}; /* members */

  static pUnit Special52[1] = {Units + 401}; /* members */

  static pUnit Special53[1] = {Units + 402}; /* members */

  static pUnit Special54[1] = {Units + 403}; /* members */

  static pUnit Special55[1] = {Units + 404}; /* members */

  static pUnit Special56[1] = {Units + 405}; /* members */

  static pUnit Special57[1] = {Units + 406}; /* members */

  static pUnit Special58[1] = {Units + 407}; /* members */

  static pUnit Special59[1] = {Units + 408}; /* members */

  static pUnit Special60[1] = {Units + 409}; /* members */

  static int Output[20] = {330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349};

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

  for (member = 0; member < 20; member++) {
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

  for(member = 0; member < 20; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}
