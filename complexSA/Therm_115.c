/*********************************************************
  Pfam_el_115new390.c
  --------------------------------------------------------
  generated at Tue Aug  3 11:10:55 2004
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
0.160460, 0.562230, 2.792360, -1.794670, -0.059920, 0.262400, -0.634850, 1.501000, -1.057690, -0.376030,
-0.882650, 0.827450, 0.101370, 0.453950, -0.170170, -0.616580, 0.258910, 0.053040, -0.585090, 0.165810,
0.543810, 0.463240, 1.059790, -0.478470, -0.837760, -0.199570, 0.903100, 0.830640, -1.489960, 0.208730,
0.472690, 1.180270, 0.424520, -1.745340, -0.607990, 0.712620, -0.864840, -1.428910, -0.228730, -0.532530,
-0.411080, 1.131480, 0.296050, -1.084050, -1.377670, -0.235490, 0.680210, -0.807010, -2.012730, -0.658040,
-1.683500, -1.486690, 0.170040, -0.679600, -0.232330, -0.846600, -0.310660, -0.463000, 1.165190, -1.335210,
-1.475080, 1.527190, 1.926300, -1.098990, 0.375930, 0.816230, -0.080900, -2.178030, 0.047330, 0.601450,
-0.861290, 1.226520, 0.226190, 0.082920, -0.784610, 0.186930, 2.988280, -0.377950, 2.314080, 0.874970,
-0.454110, 1.111820, -0.876650, 0.164150, 1.836070, -0.328610, 0.083610, 1.222080, -1.035950, -1.053650,
-0.163700, -0.533050, 0.192760, -0.380790, 0.416680, -0.184780, 0.296070, 0.232280, 0.858830, 1.471930,
-0.186560, 1.664230, 0.184680, 0.100320, 0.570370, 0.117380, -0.509020, 0.030840, 1.400700, 0.599330,
-0.585980, 1.198220, 0.484510, 0.957390, -0.118340, -0.857880, -0.216620, -1.081400, 2.058560, -2.232120,
-2.210900, 2.391700, -3.879830, -0.825830, -1.154740, 0.272690, 2.561710, 0.795440, -1.422150, -0.551510,
1.151970, 3.053150, -2.751540, 3.215250, 3.058540, 2.030230, 1.271170, -0.241350, -0.812220, -0.498900,
-1.236100, -1.061690, -1.594040, -2.315820, -0.270220, -0.067420, -2.040450, 0.567730, 0.632130, 0.680550,
0.052940, -1.715970, -1.573670, 0.194910, -0.704390, -1.092660, 0.867980, 1.108540, 0.111780, 1.272370,
-0.598910, 1.233820, -1.909750, 0.923350, -0.407030, 0.569310, -0.008310, 0.446250, -0.725340, 0.080540,
-0.128140, 1.032310, 0.729050, -0.109680, -0.088010, -0.626690, 0.345060, 0.439640, 2.309970, 0.494090,
0.697930, 1.016160, 1.557840, 0.813100, -1.707370, -0.536220, 0.283900, 0.103700, 0.093050, -0.872820,
0.071640, 1.041000, -1.080040, 2.105650, 1.548310, 0.374150, 0.053690, 0.901840, 0.633770, -0.277160,
1.652030, 1.109170, 1.614730, -0.195280, 0.749950, 2.740020, 0.461680, -0.498310, 0.874410, 1.226820,
-1.380120, 0.072420, -1.704870, -0.050980, -1.690690, 0.506360, -1.570580, 1.916930, 0.329350, 0.535680,
1.831350, 0.388300, -0.415120, 1.362860, -0.820330, 2.740970, 1.994230, -0.519960, -0.275850, 0.887510,
0.676820, -1.107600, 2.103720, 0.461710, 1.043010, -0.679670, -1.812830, -0.322950, -0.966350, 2.078160,
0.632340, 1.516980, 0.831770, 1.798170, -0.442550, -0.252360, 0.138090, 0.944810, 0.562160, 0.460500,
1.134150, -0.854910, 1.111080, 3.689350, 0.878480, -0.091770, 0.710980, 1.897520, -0.658740, 1.075280,
6.795460, 0.274730, 4.982240, 0.944790, -0.920770, 1.739810, -0.548570, -0.839350, 0.884280, 0.511220,
-0.080800, -0.376930, 0.603320, 0.551090, -0.824370, -0.834620, -0.367970, 0.685040, 0.114060, 0.681360,
-0.725700, 0.632470, 0.240000, 0.742190, -0.518710, 0.566590, 0.572640, -0.190700, 0.288530, 0.673320,
1.076910, -0.014190, 0.298920, -0.991130, -0.417810, -1.336910, -0.852760, 0.127610, 0.009850,
-0.978510, -0.008390, 0.814240, -0.069880, 1.385580, 0.766710, -0.116010, 0.744060, -0.389280, 1.434170,
-1.593300, -0.146470, -0.128430, -1.614140, -1.774650, 1.629760, -0.938340, -0.688750, -0.453580, -1.337260,
0.424600, 1.269320, 0.223160, 0.001330, -0.340660, -1.782170, -0.478830, 0.487990, -0.365990, -1.320550,
0.852840, -0.839640, -0.968080, -0.577730, 0.644510, -0.808190, 0.147140, -0.449110, 0.152920, -1.261810,
-0.020890, 1.374530, 1.351800, 2.026440, -0.625170, -0.331110, 0.710070, 0.599540, -0.537990, -0.448750,
-0.124710, 0.232760, -0.788670, -0.538320, -0.967590, 0.553490, 1.581140, -0.631970, -0.671580, 0.298300,
0.359360, 0.195770, 0.210150, -0.129220, -0.133210, -0.121270, -1.029400, 0.976170, 0.555980, 0.452450,
0.664210, -0.630910, -0.542190, 0.153000, -0.491490, 0.787890, 0.321740, -1.855380, 0.073760, -1.476060,
-0.473360, -1.171670, -0.335470, -0.778140, -0.202840, -0.220640, 0.546160, -0.134820, -0.686250, 2.326110,
-0.568810, 0.121620, -1.185020, 2.639610, 0.087950, -0.922470, 1.212230, 0.963210, -0.517820, 0.673790,
-0.612420, 0.644950, -1.838850, 0.205700, -0.302940, 0.621120, -0.248110, 0.579180, 0.331680, 0.233850,
0.835580, -0.036410, 2.400000, -0.759670, -1.580410, 0.098330, 0.991450, 1.349040, -1.404660, 0.795600,
1.724390, -0.191150, -1.130260, 0.510080, -0.760570, -0.227840, -1.052560, -0.177650, 2.393560, 0.651790,
-0.951630, -1.042580, 0.314210, -0.731020, -0.596820, -5.189690, -0.972550, -1.610180, -1.398280, -0.067620,
-1.993040, -1.143000, -0.586850, 1.583130, -0.180770, -0.011100, 2.306800, -0.426290, -1.210890, 0.313400,
0.435540, 1.286780, -0.335320, -2.554020, 1.001220, 0.510230, 0.669740, -0.950600, 0.555600, 0.531190,
-0.418160, -0.072960, -0.469730, -0.141380, -1.232040, 1.982590, -0.036400, -0.143070, 0.514840, 1.370800,
0.306330, 0.799820, -1.077460, 1.083110, -0.594160, 1.038780, 0.036620, -0.163420, 0.040850, -0.996560,
-1.211040, 0.084980, -0.339830, -0.674950, -0.109220, -0.322320, 0.709360, 0.262730, 0.284590, 0.349510,
-0.441630, -0.938310, 0.584110, 0.572520, -0.245620, 0.384420, -2.756950, -0.239730, -0.460170, -0.999140,
-1.279080, -0.040110, -1.399310, -1.946360, 1.122720, 1.043000, 0.509770, 0.641920, -0.222000, -0.507890,
-0.493720, -0.563400, 1.045410, -0.641090, -1.444930, -2.037500, -0.711820, -0.122120, 0.363190, -0.644560,
0.898380, -1.107490, 1.039200, 0.714190, 0.230560, 0.547650, 0.389570, -1.158920, -1.354140, 0.295740,
-1.218370, 2.584230, 1.543200, -0.135920, 0.093940, -0.374460, -1.396380, -0.914860, 0.154510, -0.478960,
-1.703380, 0.807620, 0.742140, 2.378120, -1.446500, 0.625040, 0.852240, -0.479230, 0.885470, -0.011260,
0.615260, 0.904130, -0.517630, -31.105690, -1.031300, 0.725430, -0.415280, -2.476850, -0.498990, 1.082550,
-0.207500, -0.667390, -1.521880, -2.842600, -1.215330, -0.896110, -0.057510, -1.190600, -0.506830, -0.747390,
0.783670, -0.822350, 0.406360, 0.585900, -0.635850, -0.077020, -0.843140, -0.141890, 0.487490, 0.309930,
1.005580, -0.087820, -0.750520, 0.947170, -0.577540, -0.091260, 1.247420, -0.118150, 0.027430, -0.190050,
-2.576370, -0.892980, -0.169480, 0.584350, 0.337560, -0.880940, -0.932820, -0.771380, -0.523370,
1.750180, -1.128330, -0.603780, 0.246670, -0.653780, -0.792680, -0.245770, -0.056090, 0.585000, 0.895500,
-1.277370, 0.842510, -0.613960, 1.220020, 0.117060, 0.754380, -0.771880, 0.655820, -0.768230, 0.768320,
0.943090, 0.263990, 0.785260, 0.423180, -1.123920, 0.051540, 0.737580, -2.851660, -0.220220, -0.048990,
1.176270, 1.529040, 2.131870, -1.006810, -0.777060, 1.049020, -0.247770, 0.535400, 1.317700, 1.555230,
0.919070, 1.129480, -0.126500, 1.994580, 0.350530, 2.369550, -0.580870, -0.653180, -0.323420, -0.968140,
0.933230, 1.634800, -0.462490, -0.367920, -0.976700, -0.440890, 1.563950, 2.450690, -0.737650, 0.925370,
-1.419630, -1.598450, 0.346290, -1.966430, 0.720370, 0.693180, 0.970360, 1.605930, 3.172910, 1.270730,
-0.327480, 2.624440, 2.212770, 2.292510, -0.731100, -0.151540, 0.356880, -0.846680, 3.030630, 1.052650,
0.618020, 1.192330, -1.826470, 3.535380, -0.179820, 1.386820, -0.279400, -0.499710, -0.595170, 3.547090,
0.569660, 0.457560, -0.057830, -0.445250, 0.330800, 0.085930, -0.304020, -0.163870, -0.582880, -2.965140,
1.334050, -0.429340, -1.262760, -1.042160, -1.126590, -0.386600, -1.415650, -0.460380, -0.025270, -0.824910,
0.167420, -0.188670, 2.212920, 0.151670, -1.116660, 0.570400, -9.092980, -0.769120, -0.480760, 0.294960,
-0.339830, -1.217870, 3.911850, 0.099550, 0.021220, -0.034340, -2.257160, -1.573220, -5.926390, 0.628650,
1.012990, 0.722390, -1.605560, 0.808790, 1.138400, -12.185710, 0.290140, 7.208710, -2.706670, -1.416090,
0.227060, -0.269170, -0.243420, -2.545320, -0.815040, -1.799010, -2.563400, -1.404400, -1.764870, 1.113580,
-1.445230, -1.142290, -1.154140, -0.206370, 1.107840, -0.650390, -0.113950, 1.252940, -0.346820, 0.724130,
5.014150, -0.857750, -2.773770, -0.417470, 0.643240, 1.489430, -1.172180, -0.430090, -1.734680, -0.733910,
0.087300, 1.038630, -1.110440, -0.169600, -0.968760, -0.338550, 1.779240, 0.858910, -1.054480, -0.587800,
0.249480, -0.308400, -0.468760, -0.690000, 0.732890, 0.989760, 0.168890, 0.369960, -0.711230, -1.201030,
-0.604520, -1.042970, -0.545860, -1.663000, -1.152710, -0.492560, -0.394410, 0.407480, 1.368630, -0.597010,
1.474790, -0.988060, 1.009370, 1.364200, -0.426570, 1.508540, 1.519210, -0.766360, 0.757310, -0.197640,
1.259980, -0.799940, -0.832030, 0.386280, -1.491060, -1.378510, -2.075290, 0.325220, 2.686200, 0.630880,
3.658980, -0.172300, -0.062750, -0.671330, -1.271950, 0.376290, -0.570480, -2.073400, 0.618570, -0.337440,
0.117900, -0.028030, -1.116000, 1.090140, 1.199490, 0.679050, 2.384760, -0.178900, -1.869070, 0.160060,
-0.532000, 0.740930, 0.279820, 1.759110, -1.449480, 1.128010, 0.327830, -1.254910, -0.603600, 0.007870,
1.021370, -0.852670, 1.355280, -2.022080, 0.288900, -1.509590, 1.020430, -0.339270, 0.682730, -0.036170,
0.877660, 0.875770, 3.406370, -0.969720, 0.984570, 2.551120, 0.466730, -1.082580, -0.815590, -0.753040,
-0.150840, -0.114990, 0.089560, 0.676470, 0.444530, 0.127460, 0.544400, -1.171480, -0.754150, -0.627700,
0.621740, 0.398130, 0.577180, -0.214240, 0.150100, -0.299720, 0.414520, -0.730790, -0.326600, -0.513310,
0.540660, 0.545120, -1.108090, 0.316600, -1.138150, -0.674950, 0.681680, -1.121470, -1.195180,
0.191410, 0.752550, 0.342510, 0.188780, 1.180790, -0.064830, 0.598700, 0.604930, -0.519470, -0.251220,
-0.217970, 0.945050, -0.784680, -1.779950, 1.759930, -0.588880, -1.208090, 0.932410, 1.073120, -1.062670,
-0.893060, -0.139890, -0.738540, -0.394310, -0.785870, 0.074490, -0.007500, -0.594570, -0.660370, -0.569320,
-0.294540, -0.122000, 0.882500, -0.096350, 0.673350, -0.759710, -0.984460, 0.695020, 0.856950, 0.062740,
0.937890, 0.025410, -1.026190, 0.332590, 0.568520, -2.478320, 0.615650, 0.262960, -0.836590, -0.802650,
1.790290, 0.938280, -0.837560, 1.483670, 0.228370, 0.701750, 1.493890, -0.726440, 0.899010, -0.294990,
-3.886610, -0.856810, -0.233250, 1.014370, -2.024500, 0.673880, -4.088750, 0.133630, -0.147730, -0.530700,
0.602960, 0.898280, 0.752890, 0.802490, -0.406560, 2.466770, 1.581820, 1.042020, 1.446260, -0.541140,
2.802900, 1.047060, 0.691920, 0.828400, 0.400840, -0.081440, 0.529140, 0.709460, -1.872520, -2.868040,
-1.041850, -0.480230, 0.651790, -0.196600, 2.469410, 1.348990, -0.738670, 0.623420, 1.229150, -0.441070,
0.609970, 0.304750, -0.868140, 2.755600, -0.169610, -0.657980, -0.202730, -0.042160, -0.379330, 0.590200,
0.325610, 0.049950, -5.879040, -0.412770, 1.021170, -0.206830, 1.865830, 0.121520, -2.329950, 4.438680,
-0.757620, -3.405180, 0.943190, 0.693700, 3.399220, 0.323070, -1.265080, -0.661960, 1.236760, -0.868530,
-0.623600, -0.655590, 12.255220, 0.490570, -0.030390, 13.208190, 5.671470, -2.064870, -0.333740, -0.249850,
-0.117400, 1.619220, -0.810770, 0.692770, -0.623820, 0.532760, 2.086850, 0.115450, -0.535160, -0.431880,
-0.789220, -0.316900, 0.664450, -0.323760, -1.596300, -0.471010, 1.957240, -0.665980, -0.657250, 2.002000,
1.300370, -0.716760, 0.945330, 1.505040, -0.732730, 2.505460, 0.193020, -0.377410, 0.698460, 2.313440,
1.524950, 0.573640, -0.714560, 2.287830, -1.570720, -0.723290, -0.868360, 0.608540, 0.608890, 0.444510,
-0.532260, -2.122310, 0.669290, -0.672470, 0.628480, 1.708410, 0.756340, 0.210330, 0.606050, 0.389850,
1.557530, -1.853850, -0.469670, 1.234900, 2.714960, -0.844830, -1.283780, -0.143230, 0.072760, 0.757080,
1.936980, -0.508610, -0.589160, 0.018830, -0.189250, 1.431100, -0.496990, -0.802730, -0.169290, -0.388840,
1.922800, 1.487050, 0.722160, -1.398430, -0.493170, 0.212840, 0.998380, -0.115580, 1.942130, 0.210340,
0.503410, -2.012230, 0.952230, 0.375240, 0.937360, 0.254950, -0.495150, -0.365990, -0.126450, -0.582940,
1.013330, -0.446610, 1.458210, -0.537300, 1.436920, -0.055710, 0.393230, 0.853060, -0.366400, 0.147850,
-0.710450, 1.626240, -1.418630, -2.070010, 1.285460, -0.825250, -0.024880, -0.091210, -0.322940, 0.307190,
-0.887910, -0.244960, -0.783560, 10.217480, -0.073030, -0.337970, 0.507020, 0.627440, 2.461490, -0.860190,
1.677320, -1.097940, 0.538620, -0.582640, 0.295480, -1.527680, 0.519310, -1.030590, 1.157130, -0.225590,
-0.019900, 0.939700, -0.641340, -0.328900, 1.004230, 0.929410, -0.007700, -0.280830, -0.060500, 0.341720,
0.912020, 0.644450, -0.302510, 2.303410, 0.326030, 1.021730, -0.207960, -0.529680, 0.997010, -0.714820,
-0.675800, -0.189650, 0.274240, -0.371470, 1.044040, 0.416980, 0.822400, -0.461330, 1.192820,
0.848670, -1.506090, -1.648670, 0.188590, 0.003320, 0.047960, 0.082620, 0.780710, 0.679110, 0.973750,
-0.804410, -0.362240, 0.824380, -2.002830, -0.096680, -0.733970, -0.471610, -0.342320, -0.270580, 0.435970,
-0.804080, 0.088250, -1.265730, 0.613210, -1.179230, -0.543470, -1.868190, 0.632840, 0.988850, 0.586760,
-0.248090, -0.733810, -0.448030, 1.004350, 0.135650, -0.009560, 1.812050, -0.752240, -0.138840, -0.301010,
1.345490, 0.515200, -0.706740, 0.741530, -1.143630, -0.214280, 0.125680, 0.490830, 0.160280, -0.040310,
-0.114170, 0.700630, -0.746720, 0.291430, -0.187150, 1.018940, -0.202360, -0.469020, -0.323430, 0.657270,
-0.103280, 0.947210, -0.269980, -1.128520, 0.051610, -0.026370, -0.164030, -0.481750, 0.080270, 3.395710,
0.399050, 0.392930, 0.870270, 2.099830, -0.088400, 2.585450, 0.140910, 0.666410, 1.145940, -0.474840,
-0.842720, -0.330400, 0.140560, 1.621700, -0.078490, -0.234630, -1.204500, 0.649390, 1.199970, -3.192140,
-1.074470, -0.230950, 0.360940, 0.538620, 0.383400, -2.057420, -1.417150, 0.476510, -0.193740, -0.316920,
-0.146590, -0.224130, 1.375170, 1.123660, -0.327910, -0.160490, 1.022950, 0.101270, 0.721030, -0.020570,
0.053730, 1.153180, -0.730920, -0.687970, -0.904480, 1.484680, 1.120440, -0.902400, 0.161130, 2.868120,
1.216500, -1.025020, -1.408820, -0.664400, 3.081470, -1.600960, 0.311470, -0.416540, 1.333530, 0.050060,
0.979160, 0.549570, 2.390610, -0.506960, -0.777580, 0.852670, 1.519560, -5.003640, -0.859580, 0.883910,
-0.682710, 0.360200, -0.491570, -2.255540, -0.011580, 0.804590, -0.935900, -0.842080, -2.826790, -2.469920,
3.067270, 2.173520, 0.498010, 0.698980, 0.338810, 1.883020, 0.483820, -0.535710, -1.314450, 0.785470,
-0.650720, -1.147180, 1.684800, 1.182730, 0.368450, -1.502050, 1.831110, -0.179440, -0.997900, 0.187440,
0.168270, 0.591100, 1.787500, 0.222570, 0.029780, -0.219800, 0.652860, -0.999530, 0.825990, 0.163830,
-1.441910, -1.319620, 2.517850, -0.361960, 0.689790, 1.495330, 0.928860, -0.794210, -1.623110, -0.685290,
0.426960, -0.211680, -2.040550, 0.180640, -0.734730, 0.339960, 0.847790, 0.941590, -1.658930, 0.400990,
-0.482890, 0.895930, -0.643910, -2.168670, -0.296610, 0.009830, -0.559380, -2.909580, -0.051310, -1.532100,
1.680230, 0.168110, -0.779280, -0.176020, 1.433930, 0.513900, -0.785590, 2.029270, -0.208890, -0.239390,
-0.625750, -0.307730, -0.687770, 0.558910, 0.381570, -1.108760, -0.117630, -0.143010, -1.076650, -0.871210,
-0.418720, -0.470240, -0.265210, 0.060350, 0.357910, 1.344660, 0.406940, 0.287800, -1.954230, -0.736890,
0.518540, 0.737580, 1.447400, 0.304170, 0.505750, -0.496820, 0.332000, 2.570090, -1.346110, 0.530790,
-1.002430, 0.552810, -1.013870, -4.816440, 0.806870, -0.620170, -0.017870, 1.479050, -0.048500, 1.629400,
-1.082620, 1.163430, -1.298360, 0.082310, -0.777750, -1.097590, 1.344960, 0.918160, 0.726920, 0.026930,
-0.618790, 0.382180, 0.321260, -0.573290, 0.727020, -0.005580, -0.288280, -0.143710, 0.518320, 0.730390,
-0.698920, -0.866900, -0.933980, 0.972680, -0.518020, -0.612050, -0.209820, 0.020850, -0.855380, 1.511640,
-0.642090, 0.131970, 0.693280, -0.593100, 0.483950, 0.969980, 1.057120, -0.052240, 0.626620,
0.323940, -1.592560, 0.563390, -2.620500, 1.236800, 1.005380, -0.033360, -1.037060, 0.387840, -0.474030,
-0.098190, -0.702030, -1.077370, 0.214190, 0.180970, -0.239140, 1.434260, -0.640260, -1.020390, 0.764380,
1.017740, 1.293390, -0.685920, 0.054220, 0.338270, 0.516130, -0.137110, -3.300200, -0.329410, 0.229040,
-0.694880, 0.358420, 1.524090, 1.714370, -0.133450, -0.999440, -0.724120, -0.516080, -0.503710, 0.001810,
2.274730, -1.215460, -2.596190, 0.422860, 1.648900, 2.969490, 0.234420, 0.169500, -0.049770, -1.218530,
-0.170280, -0.616220, 1.376490, -1.368080, -0.819560, 0.027150, -0.134420, -0.560410, -0.294440, -1.327580,
0.017560, -1.146400, -1.179370, 2.721660, -0.320330, -0.418410, 1.066750, 1.664680, 1.689160, 1.037720,
-0.811440, -1.854960, -1.716740, -0.244700, 1.371740, 0.159380, 0.154370, 0.250740, -0.493540, -0.796080,
-0.407240, 0.526910, 0.537800, -0.572070, -1.495370, 0.812460, 1.107400, 0.251060, -0.667130, 0.604050,
0.304170, 0.510470, 1.593690, -0.333200, -0.831210, -0.112680, -1.665530, 0.895950, -0.130110, 1.257230,
0.593630, -0.963730, 0.318880, -1.085840, -1.789310, -1.679700, -1.162430, 0.982510, -0.645960, -0.136650,
-2.074150, 1.455940, -1.237220, -0.667420, 0.643230, 0.868500, 2.373450, -1.248820, 0.315220, 1.053950,
-0.248510, -1.482480, 1.695640, 2.160400, 1.957960, 0.799430, 0.349330, 0.006290, -0.303240, 0.220330,
-0.083700, 0.278990, 7.513990, 1.745350, -0.107060, 12.960740, -1.291310, 0.204740, -0.300210, 0.889270,
0.189490, -0.990230, 1.711530, 0.767060, -0.292720, 1.344190, 1.862240, 0.364320, 0.829290, 1.030360,
-0.529430, -1.124310, 0.615580, -0.336260, -1.442930, -0.830040, -1.435980, 0.487180, -0.274670, 3.420820,
-1.334440, -0.953610, -0.346320, 1.178330, -0.237590, 0.131940, -0.257860, -0.809080, -0.474110, -0.059530,
-0.362000, -0.148410, -0.661960, -0.085080, 0.689710, 0.521820, 1.611080, 0.996760, 1.978470, -0.252910,
-1.331440, -4.050110, 1.704030, -1.604910, 0.859130, -0.174570, 1.014910, -3.099350, -1.041240, 0.493560,
-0.496630, 1.117330, 0.369950, 0.023590, 0.075730, 0.599390, -0.402830, -0.404060, -1.102660, -1.160400,
-2.923480, 0.594650, 0.547240, -0.131120, 0.285160, 3.733820, -0.580770, -0.786380, -0.344770, -2.482070,
-1.742580, 0.789750, 0.099190, -0.680080, -0.092540, -0.538830, 1.704670, -0.647300, -1.205080, -0.235140,
0.354510, -0.475950, -0.164470, -0.181540, 1.837880, 0.150120, 0.635250, -0.368430, 1.264740, -0.437970,
-1.573080, -0.137350, 1.499340, -0.239960, 0.078630, 0.262580, 0.086850, 1.343610, -0.288420, 0.619560,
-1.113940, 1.246610, -1.639150, -1.097050, 0.462280, -1.088030, -0.927590, -1.110150, 0.246130, -0.109740,
-2.294500, 0.340590, -1.420980, -22.327820, 0.070630, 1.370450, -0.448380, 0.061500, 0.280610, -1.523340,
0.600500, 0.087320, -1.839650, 0.798480, 0.051950, -0.575290, -0.240680, -0.775460, -0.215430, 0.480160,
-1.051740, -0.773420, -0.743820, -0.184350, -0.759370, -0.509280, -0.004960, -0.282600, 0.594030, -0.322220,
0.245390, 1.005780, -0.930250, 0.473800, -0.087490, 0.234230, -0.383940, -0.272420, -0.015020, -3.037100,
-1.050810, 0.816490, 0.301280, -0.358170, 0.285840, -0.471550, -0.672430, 0.641630, -0.150140,
0.379160, -0.047370, 0.488380, -1.351850, -0.183550, 1.692490, -0.630970, -0.511820, 0.726130, 0.721910,
-0.458960, 1.173810, 0.928900, -0.807950, 0.394410, 0.226960, 0.088910, -0.721520, 2.137730, 0.716550,
-1.606700, 0.184440, -0.567670, -0.383390, -0.082640, -0.281230, 0.504970, -0.128440, 1.404710, 0.088340,
-0.614330, -0.111560, 0.622770, 0.360000, 0.991230, -0.125350, 1.012020, 0.536800, -0.218710, 1.041560,
1.251060, -0.180220, -0.148750, -0.861710, -0.751130, -0.332360, 1.694810, -0.206470, 0.050890, 0.110040,
-0.157870, 0.747940, -1.810790, -0.733010, 0.610640, 1.286290, 0.435510, -0.333830, 0.160900, 0.511910,
0.124920, 0.344050, -1.679160, -1.158660, -0.813730, 0.126960, 0.363250, 0.283070, -0.298750, 0.314720,
0.913220, -0.954940, -0.433990, -0.234480, 1.312420, 1.170460, -0.020410, -1.381410, 1.076150, -0.711890,
-0.631840, -0.621330, 0.013690, -0.036280, -1.129540, 0.175210, -0.670160, -0.701190, -0.004390, -1.945460,
0.576710, -0.703450, 0.223930, -0.242790, -0.515760, -0.639950, -0.088630, 0.054930, -0.722200, 0.333280,
-0.904530, 0.348510, -0.402410, -0.667760, -1.681140, 0.593970, -0.949690, 2.375060, -1.367220, -1.616900,
-1.252450, 2.542270, 0.532510, 0.082300, 0.821010, 0.670410, -0.527560, 6.040380, -5.503790, 5.533050,
0.322840, -3.523020, 3.229190, 0.523880, 6.473250, 0.906140, -2.175820, -0.773830, 0.425230, 1.894070,
0.747030, -3.188140, 2.219230, -1.168960, -0.839880, 4.794480, 3.834150, 2.198070, -0.432490, 0.788370,
1.405650, 1.929760, 0.692810, -1.169880, -0.261500, -2.468380, 0.061390, -0.034690, 0.119220, -1.320760,
-0.569720, -0.184260, -0.555800, 0.431260, -0.264880, -1.021060, 0.051840, 0.343090, -0.870100, -1.789980,
0.571010, -0.094890, 0.307680, -0.646350, -1.446420, -0.792630, 0.054370, 0.347420, -0.259610, -0.438460,
-0.517930, -0.209990, -0.177160, 1.162750, -0.236460, 0.224720, 1.049700, 1.679380, 0.019090, -1.333780,
0.446180, -0.974330, -0.835540, 0.923180, 0.735170, 1.525730, 0.281960, -1.570070, -1.022760, -0.589980,
-0.375770, -1.102250, 1.124810, 0.526560, -0.084260, 0.575300, 1.420770, 0.405170, 0.106610, -1.238290,
-0.647670, -0.661540, -1.168440, -0.342670, 0.121220, -0.352910, 0.421590, 0.476850, 0.495510, -0.418810,
-0.295910, 0.498320, -1.335750, -0.256670, 0.196200, 1.043940, 1.384800, 0.266500, -0.922440, 0.411990,
0.239400, 1.133970, -0.993310, -2.270030, 0.889050, -0.837430, 1.674770, 0.835160, 1.399570, -0.155800,
-0.865300, 0.719690, 0.090560, 0.306910, 0.710710, -1.618730, -0.713170, -0.657660, 0.298510, 0.069290,
-0.297220, -1.593280, 0.515590, 0.461320, 0.039100, 0.254570, -0.180970, 0.151070, -0.101140, 0.466100,
0.022490, 0.691930, -0.702750, 7.277780, -0.041560, 0.602750, 0.064720, 0.111040, -0.317750, -0.684660,
3.007000, 0.605380, -0.639030, 1.801190, 0.266020, 1.381710, 0.481800, -0.282840, 0.017700, -0.874160,
0.964700, 0.706940, 0.735170, 0.871770, -0.223160, -0.521780, 0.412690, -0.411870, 0.955280, 0.332980,
1.044580, 0.348750, 0.696610, -0.902050, 1.614600, 0.415100, -0.510010, 0.769600, 1.012070, -1.042410,
0.274360, 0.623230, -0.874260, 1.352010, 1.145150, 0.664490, -0.565980, 0.534020, 0.286450,
1.497110, 0.789390, 0.133360, 1.382540, 0.626220, -1.576860, 0.574360, 0.648940, 0.968800, -2.091600,
-0.984620, -0.456190, -0.860380, -0.250150, -1.089280, 0.637450, -0.428760, -0.775310, -1.820230, -1.060340,
3.877550, -0.902990, 0.465780, 0.369300, -2.197100, 0.100100, -1.587590, 1.344430, -1.318040, -0.271020,
-0.218710, 1.407550, 0.230390, -1.218800, 0.227960, 0.166580, 0.731010, 0.210400, -2.196160, 0.134460,
0.101070, -0.127880, -1.078250, 1.228960, 0.048490, 1.425710, 1.340130, 1.828890, -1.726440, -0.559330,
-0.151740, 0.665110, 1.175580, 1.442600, -0.109680, 0.748310, -0.514500, 0.171880, 0.664590, 2.006430,
-0.346510, -0.710900, -1.371370, -0.439470, -0.494980, -0.815180, -0.333850, 0.852720, 1.973500, -1.028940,
0.575300, 1.342660, 2.029470, -0.575170, -0.379790, 0.728780, 0.325670, -0.197810, 1.475270, -1.335950,
0.229270, -1.751460, 0.320580, -2.601560, 1.758670, 1.344000, -0.447980, -0.373440, 0.052570, 1.216510,
-0.223260, 0.212990, 1.423550, -1.816970, 0.427770, -0.653690, -0.424020, 0.470580, -0.614180, 2.276640,
0.730960, 0.819640, 0.254670, 0.283710, 0.083120, 0.572180, 0.687040, 1.011450, -0.659330, -0.069380,
-1.249280, -0.869770, 1.103310, 0.303680, 1.835680, 1.183200, -1.683680, -2.638570, 1.554800, -1.449950,
0.751960, 3.418390, 1.105670, -1.801270, -2.279470, 1.144360, 1.001450, 0.397970, -1.696600, 0.074950,
-1.191850, -0.240140, -5.134080, 0.096360, 0.628750, -2.153800, -2.813040, 4.587260, -1.606530, 2.999690,
-1.355240, -0.214850, -0.368450, 0.067300, -0.703410, 1.445440, -1.956300, -2.261270, -0.151640, -2.192410,
-0.186440, -1.536620, -1.245220, -0.160700, 0.686800, -1.381930, -0.944610, -0.128380, -0.177290, 0.608340,
2.336010, 0.098000, -3.614150, 1.073150, 1.833610, -1.373700, -0.322110, 0.034520, -1.633840, -1.162920,
1.763660, 1.319230, -0.307900, -0.218830, -0.077570, 1.300070, -0.962720, -1.429470, 0.277450, 0.245800,
-0.490260, 0.109490, -1.405840, 1.184230, 1.460690, -0.934420, -0.397060, 0.507910, 0.947180, 1.305080,
-0.667050, -0.214050, 1.747250, 1.567230, 0.443120, -0.337840, -0.821220, 0.166420, 0.865540, -1.027280,
-1.083510, -0.525280, 0.078450, -0.070000, 0.808580, 0.652930, 3.216990, -0.992790, -0.165140, 0.438910,
2.203940, 0.427250, 1.033590, 1.478180, 0.849410, 0.751880, -1.431420, -0.609570, 0.026200, 0.145490,
-0.145000, -0.765750, 0.224940, 0.523490, -2.131770, -0.167560, 1.256220, 1.122650, 0.360830, -0.195020,
1.075500, -0.660010, -0.075660, -1.021660, 0.041660, -1.110560, 0.554760, 0.737690, 0.145900, -0.363480,
0.179900, 1.144510, 1.770830, 0.184810, -1.482820, -0.827690, -0.232050, 0.339240, -1.179430, 0.049400,
1.735520, 0.842070, 1.213690, -0.441900, -0.529780, -0.913420, 0.016560, 0.964870, -1.947260, 1.051340,
0.462070, 0.593580, 1.828880, 1.282910, -1.177480, 1.010300, -1.131610, -0.285550, 0.568220, 0.087480,
0.206700, 0.172320, 0.762910, -0.526270, -0.816730, 0.817740, -0.302850, -0.920490, -0.895390, 0.739700,
-0.942520, -0.223440, 0.338290, -0.944460, -0.045510, 0.352860, -1.352380, -0.093470, -0.037950, -0.836620,
0.270410, 0.851990, 0.017950, 0.263700, 0.870760, -0.307830, -0.145820, 0.877910, 0.546220,
0.341720, -0.255490, -0.846590, -0.804710, 0.418600, -0.783200, 0.077670, 0.307880, -1.211960, 0.452010,
0.114710, -0.687190, -0.962200, -0.561780, -0.839020, -0.334340, 2.330400, 1.137910, -0.389850, -2.515460,
-1.297450, -0.895190, -1.727560, -0.724940, 1.537770, -0.558400, -0.346940, 0.583320, -0.650280, -1.070560,
-0.664570, 0.900030, 0.902330, 0.475450, -0.525520, 1.270860, -1.855720, -0.567170, -1.045600, -0.334770,
1.486500, -0.306450, 1.397650, -1.729900, -1.781820, -3.111850, -0.375940, -0.500430, 0.275650, 1.558280,
0.820320, 0.249690, -0.120700, 2.493000, 0.448770, -2.246950, -1.676090, -0.903800, 1.863780, -0.059600,
0.790580, 0.660180, 0.786620, 0.201830, -0.876960, 0.503490, -0.253040, -0.217110, -0.321950, 0.010250,
0.452430, -0.356390, -1.523490, -0.704510, 0.261360, -0.673930, 1.811470, 0.757460, -2.122000, -1.340820,
0.261830, -0.145150, -0.423460, 1.186600, 0.775020, -0.824340, -0.892340, 0.997390, -0.319690, -0.492400,
-0.404450, -1.134620, 0.165460, 2.300880, 0.978390, -0.616730, 1.356910, 1.690320, 1.500930, 1.306330,
0.170290, 0.910370, -1.296550, -0.689660, -0.249660, -0.365230, 0.603400, 0.144100, 1.720160, -0.110260,
0.887730, -0.678730, -1.868680, 0.060070, 0.898350, 0.811380, 3.354120, 1.047840, -1.643980, 1.721020,
0.230050, -2.643190, 0.314340, 2.035840, -0.637350, -1.964710, -1.271260, 0.128670, 0.656060, 3.436880,
0.873260, -2.362810, 0.801190, -0.160810, -1.368290, 4.849830, 2.108280, -0.027220, -0.382840, 1.314900,
-1.742090, -2.794470, 1.697010, 0.537550, -0.696450, -1.557110, 1.030890, 1.836410, 0.473790, 2.633610,
-0.462240, 0.504590, 0.263220, 1.940060, -1.326910, 0.982060, -2.464420, 0.242960, 0.599780, 1.484940,
0.116100, 2.257190, 3.354430, -3.060180, -1.277030, 0.232560, 0.713470, -1.633710, 2.349150, -0.105920,
0.725690, 0.305560, 0.760130, 0.444660, 0.903530, 0.307790, 1.665050, -0.532590, 0.224000, 1.047220,
0.872100, -0.778030, 0.585220, -0.797860, 0.322010, 1.154790, -0.457580, -2.058910, -0.137610, 0.539420,
0.144600, 1.652300, 0.234570, -0.280690, -0.623070, 0.298470, 1.048050, -0.191770, -0.557230, 0.077980,
-1.249520, 0.844320, -1.709980, -0.157050, -0.232840, 0.940810, -0.563970, 2.002110, 0.305360, 1.293770,
0.444250, 0.002480, -0.271050, -0.495230, -1.003680, -0.224300, 0.860700, -1.395040, 1.727580, 1.636480,
-0.305910, 1.365380, -2.166760, -0.083740, 1.308400, 0.074630, 0.023800, 1.413050, 1.182940, 0.313520,
-1.362470, 1.448540, 0.434640, -2.787610, 0.525700, 1.237030, 0.363500, 0.322890, -0.339820, 0.051900,
0.695140, 0.485520, -1.742430, 0.777270, 1.571360, 1.495120, 0.939250, 0.544370, -0.121890, 0.078580,
-0.274590, 1.632630, -1.330000, 31.636370, -0.119060, 1.514720, 0.726730, 0.823310, 1.412710, 0.912700,
1.292130, -0.477940, 0.292710, -1.186190, 0.626760, -0.703060, 0.241180, -1.093810, -0.507460, 1.161000,
0.168990, 1.316140, 1.202430, 0.728130, -0.476580, -0.180250, -0.326820, 0.209080, -0.034790, 0.830620,
0.866840, 0.221170, 0.747930, -0.506520, 0.215170, 0.285370, 0.101200, 0.727460, 1.297100, 0.121680,
-0.352780, -0.121800, 0.573260, 0.585980, 0.977100, 0.461600, 1.147150, 0.247220, -0.328350,
-0.449860, -1.568050, -1.760520, -0.074310, -1.317540, -0.173500, 0.125240, 0.267320, -2.538320, -0.167270,
-0.881680, 0.609820, -1.321100, -2.122090, -1.200130, -1.492220, -0.473110, 0.277000, 0.613260, 1.032990,
-2.763220, -0.057160, 1.084490, -0.181420, -0.226500, 0.118770, -0.542010, 0.905530, 0.039960, 0.341290,
1.217090, -0.584740, 2.126230, 1.082800, -0.264670, 0.612260, 0.426610, 0.719850, 2.203270, -0.920170,
2.691680, 0.972380, 0.635810, -0.155680, 0.620950, 1.085520, 1.374510, 0.817410, 0.293370, 1.076100,
0.970900, 0.947660, -0.519900, 0.358060, -0.300500, 1.157800, -0.574470, -0.471140, 0.748890, -0.890870,
0.274560, -1.652340, -0.465640, 1.606420, -0.846980, 1.926630, 0.419290, 0.217480, -0.309400, 0.199560,
1.795530, 0.638350, -0.175880, -0.371950, -0.357760, -0.679080, -3.303780, 0.823730, 0.382800, -1.620850,
-0.126790, 0.970710, -2.298680, 0.628980, -0.848870, 0.189490, 0.899660, -0.438710, 0.665580, -1.074090,
0.835700, 1.139920, -1.404860, -0.763680, -0.597020, 0.146870, -0.473210, 0.713710, 0.591320, 1.190000,
-1.844220, 0.094620, -1.922540, 0.214280, 0.132620, 0.477130, -0.071080, -0.111210, -1.325030, -0.850230,
0.282880, -0.334150, -0.097540, 0.174020, -0.748720, 0.584030, 1.435340, 0.225960, -1.309310, 1.764960,
-0.083070, -0.385140, 2.162470, 0.152040, 2.338320, -1.119660, 0.851580, -0.752720, -0.372740, 0.524270,
0.680330, 2.092260, 6.549260, -0.288150, 0.862130, 9.395890, 1.012560, -4.066390, 0.513130, 0.546030,
0.823210, 0.127610, -1.054240, 0.307200, 0.919180, -1.390830, 0.499800, 1.297740, 1.176820, -0.574150,
-0.333450, 0.053140, -0.487490, -0.519010, 2.026670, -0.034030, 0.641590, 0.447410, 0.495130, 0.513690,
1.143800, 0.489870, -0.794930, 0.010220, 0.268490, -0.266200, -0.468730, -0.659460, 0.273180, 0.860280,
-0.661130, -0.550890, -0.303780, 0.283190, 1.637360, 0.526870, -1.553490, -2.109240, -0.347520, 2.390110,
1.373470, -0.661320, 1.299960, -1.294880, -0.868730, -1.908800, 1.413190, -0.456110, 0.819970, -0.540180,
1.132100, 0.849230, -0.765420, 1.285340, -0.707290, 0.398970, -0.080650, 0.487620, -0.066400, -0.387440,
0.019770, 2.791400, -0.908430, -0.272410, 2.206630, 2.040150, -0.576220, 1.281220, 1.151750, 1.000950,
1.098100, 0.328550, 0.315400, 0.380180, -0.535390, -0.273840, 0.268250, -1.281630, -1.370720, 0.497000,
-0.409700, -0.229490, -0.505060, 0.398650, -2.706820, -0.452320, -0.243290, 0.017670, 0.795350, 0.972890,
-0.810710, 0.052950, 0.695230, 1.038000, 0.110480, -1.481800, -0.329460, -0.209270, 0.733860, 0.662460,
-1.345200, -0.849330, -0.776170, -0.644230, 0.715320, -0.409040, 0.263620, 0.437240, -0.248760, 3.148490,
-1.501990, 0.204550, 0.541840, -0.714900, -1.348380, 0.970530, 0.479390, 0.442710, -0.239540, -0.841450,
1.385380, -0.553610, -1.497640, -2.261380, 2.804220, -0.904830, -0.795340, 0.038330, 0.256130, 0.262790,
0.699160, 0.220790, -1.059580, -0.211150, -0.751520, -0.922900, -0.047360, 0.021120, -0.329170, -0.447390,
-0.420250, -0.505200, -0.924740, -0.759750, 0.455850, 0.513490, 0.633900, -0.279770, -0.877680, 0.177640,
0.597130, 0.185180, -1.243370, -1.041920, -0.780860, 0.502890, -1.244290, 0.194260, 0.538600,
1.170410, 1.764910, 0.380990, -0.268000, -2.196150, 0.056990, -0.285350, -0.257140, -0.276210, -1.722150,
-0.183060, -0.006050, -0.576500, -2.722660, 0.477920, -1.791620, -0.685610, -0.805350, -0.406460, -0.761250,
-1.434930, 1.447100, 0.316350, 0.045770, 0.636730, -0.983880, 0.351000, -0.327100, 0.602710, -0.705450,
-0.296970, -0.948720, 1.007970, 0.261330, 0.179090, 0.566770, 0.487420, 0.562190, -1.670180, 0.027900,
-1.133100, -1.151460, -0.059940, 0.443570, 0.741630, 2.074850, -0.089200, -0.467010, 0.788110, -0.316680,
-1.736000, -2.470070, -0.804070, -1.676700, -0.477340, -0.561530, 0.687640, -0.672330, -1.345840, 0.044220,
0.010050, -1.380350, 0.733510, -1.067310, 1.398650, -0.842200, 0.938580, -0.884430, 0.792420, 0.726400,
0.251700, -1.726370, -0.007880, -0.536770, 0.839770, 0.533580, 0.941950, -0.733360, 0.665480, -0.685910,
0.695130, 0.495080, 1.579270, -1.157270, 0.585770, -0.397080, -1.025460, -0.414940, 2.257820, -3.188920,
-0.721760, 1.630500, 0.326930, 2.785540, 0.790580, 0.012300, -0.606980, 2.585240, -0.531740, -0.488430,
-1.110850, -1.226970, -0.510070, 0.063720, 0.107950, 0.518320, 1.179290, -1.118920, -1.192360, 1.606870,
-0.105290, 1.218020, -0.287420, -0.169670, 0.557050, 0.007920, -0.113210, 1.713850, -3.502370, -0.773580,
0.862060, 0.062540, 0.491650, 1.908970, 1.822190, -1.171870, -3.416990, 0.140270, 1.786660, 3.069270,
0.086020, -1.973180, 0.707750, -2.508620, -1.879950, -0.390980, -1.352140, -1.374340, -0.139570, 1.060590,
-1.740480, -0.952540, 0.076940, -0.801090, 0.976820, -0.190290, -0.310020, 0.199230, -0.182900, 0.970220,
-1.230880, 1.360670, -0.006260, -2.427040, -0.013620, -1.214680, -0.447090, -1.253180, 0.903930, 0.322740,
-1.130940, 2.170610, 2.985800, -0.797760, -4.045730, 0.410210, 1.073550, 1.574060, -0.085930, 0.738250,
-0.226510, -1.279600, 0.945450, 0.286160, 3.627880, 0.466350, 0.962430, -0.279010, 1.982580, -0.582210,
0.182720, -2.003530, -0.204240, -3.147820, 1.245870, 4.705570, 0.804490, -0.291330, 1.492660, 0.746260,
-1.543260, 0.076630, 1.791150, 0.662100, -0.151820, -1.209720, -1.676540, 0.602930, -0.116340, -1.177180,
-2.159630, 1.178420, -0.156140, -1.366600, 0.502400, -1.289150, -0.106060, 1.626390, 2.707020, 0.567750,
1.889430, 0.347140, -0.425550, -0.782340, 1.743680, -0.131600, 0.559200, 1.177550, -1.227020, 2.906640,
-0.645520, -0.250510, -2.969920, 0.561760, 1.856960, 0.308700, -0.794600, 0.293940, -0.065420, 0.152590,
-0.459580, 1.953830, -1.085740, -0.626840, 0.017180, 0.200830, -0.975260, 1.721850, -0.775250, 1.152160,
-0.188100, 0.440450, 0.316400, -0.187830, 1.418610, -0.602130, -0.159910, -1.343590, 0.889150, -1.054700,
-1.490220, -0.946810, 1.931810, 1.253020, 0.334700, 2.142120, -0.109590, -2.135370, 0.023740, -0.309880,
0.790360, 0.334840, -1.513470, -1.960290, 1.433330, -1.813690, 0.815380, 0.136070, 0.349270, 0.144920,
0.294660, -0.760030, 0.141800, 1.487920, 0.887590, 0.702390, 0.066310, 0.988500, 0.594310, -0.125720,
0.805890, -1.603680, 1.032400, 0.804260, -1.887410, 0.794070, -0.769200, 1.286280, 1.171690, 0.171660,
1.047020, 0.959870, 0.794710, 0.421760, 0.821980, 1.298810, 0.665820, 0.748290, 1.155710,
0.446040, -0.239930, 0.897430, 0.285180, -0.987520, 0.044630, -0.581440, -0.405440, -0.460770, -0.153530,
-0.435150, 0.636950, 1.667360, -1.237510, -0.839930, -0.923060, -0.984780, 0.418180, 0.099060, 1.261210,
-0.829810, -0.576510, -0.478440, -1.125010, -0.269050, -1.499160, -0.311230, 2.015800, -1.022430, 1.200530,
-0.130420, -1.378680, -0.089200, 0.273520, 1.064200, -0.069650, 0.403650, -0.193520, -1.914950, -1.620540,
-0.782570, 0.096790, -0.150840, -0.855670, -0.113760, 1.242510, -0.401460, 0.203370, 0.552800, 0.204600,
0.102940, -0.447260, -0.055670, -0.634410, -1.113120, -0.404560, 0.429130, -0.469600, -0.394130, -0.091730,
0.007430, -0.252570, -0.394630, -1.172510, -0.924460, -0.862130, 1.843850, 0.822310, -0.258820, 0.468730,
-0.438500, -0.461530, -1.712860, -0.355460, 0.126040, -0.424100, 1.135170, -0.610160, 0.516170, -0.169850,
-0.970430, -1.171380, 1.085780, -1.827170, 2.172340, 0.379990, 1.037890, -1.253130, 0.955430, -0.036700,
-0.314410, 0.357680, 0.669080, 1.035600, -1.337060, -1.455170, -1.269150, 0.466590, -0.467860, -0.179360,
0.555390, 0.249380, -0.217700, -1.490440, -1.131020, -0.410980, -0.450540, 0.654420, -1.307440, -0.878370,
0.935270, 0.625810, 1.970750, -0.357130, 1.801210, 0.047890, 1.801860, -1.283930, -0.383040, 0.141510,
-0.095200, 0.294220, 1.914510, 1.218040, -0.656450, 0.297100, -0.219870, 0.138870, -0.017080, 1.113950,
1.105230, -0.576300, -0.787270, 0.473660, 1.322200, -1.232650, 0.074550, 2.645000, 0.540970, 2.745720,
-0.812410, -0.842850, -0.558490, -1.177230, 0.137490, 0.605670, 0.679630, -0.254120, -2.692330, 0.068120,
-1.027970, 3.919070, -0.024070, -0.589910, 1.115970, -1.700480, -0.985510, 0.354550, 0.568950, 0.741790,
-1.149760, 0.956300, -1.008460, -0.051490, 0.853420, 0.412970, 1.321200, -0.899890, -1.259500, 1.107570,
0.136900, -0.526460, 0.708770, 1.162880, 2.364740, -0.180120, 1.760620, -0.844530, 0.818090, 0.285690,
1.655890, -1.604460, 1.304360, -1.340760, 1.616260, 0.195620, 0.213550, -0.458120, 1.363570, 1.060690,
0.075650, 0.175250, 1.094320, 0.636820, -0.963130, -0.204660, -0.661940, 1.117580, 1.200040, 1.335870,
-0.177760, -0.474880, 0.669230, -0.847570, 0.332590, 0.143760, -1.171510, -1.544930, -0.895250, 0.699080,
0.466950, 0.134130, -1.233680, 0.571920, -1.918880, -0.445610, -1.181750, 1.355120, -0.325830, 0.857350,
-0.905800, -0.569610, 0.920990, -0.752530, 0.661010, 0.260640, -1.425780, -1.720780, 0.458810, -0.038970,
0.658210, -1.433100, 0.875710, -0.379750, 1.027600, 0.263160, 1.248150, -0.668490, 0.322840, 0.267650,
0.528950, 1.856530, -0.857270, -0.155080, 1.287470, 0.711420, 0.198310, 1.663600, 0.335050, 0.346790,
-0.924890, 1.443200, -2.186300, 9.710580, -0.113950, -0.843240, -0.270800, -0.022360, 0.774180, 1.795690,
-0.571360, 0.128380, 1.199640, -0.096560, -0.898980, 0.440180, 0.651100, -0.706860, -0.906900, -0.552680,
2.239660, 0.274690, 0.114570, 2.218270, 1.314760, 0.568450, -0.423440, -0.156670, 0.253490, -0.113700,
1.064850, 0.746910, -0.122340, 3.105340, 0.424270, 1.270620, 0.006570, -0.349640, 2.541090, 1.486400,
0.777160, 0.821410, -0.168080, 0.246200, 0.039820, 1.189450, 0.478120, 0.331500, 1.079630,
0.646550, 1.105160, -1.241440, 1.427480, -1.151630, 1.872220, -0.234370, 2.348320, 0.174510, 1.161610,
-1.052490, 1.622470, 0.314380, 0.740900, 0.754470, 0.587760, -0.693890, 1.645980, 1.406000, 0.204730,
-2.472670, 0.135890, -2.665790, 2.320520, 1.325590, 1.718930, -0.738170, 1.326560, -0.757320, 1.255590,
-0.500610, -0.287160, -0.820990, 0.830460, -2.271410, 0.515330, 2.994610, -0.756700, 0.823650, -0.046030,
1.361100, 1.270800, -0.598730, -0.567390, 0.040380, -0.182760, 1.504330, 0.601660, 1.585100, -0.936570,
1.029340, -0.255260, 2.124330, 0.289660, 0.502140, 0.904640, -0.576580, 1.172570, 0.180720, 1.609550,
0.688820, -0.750340, -0.353990, 0.283840, 0.698740, -0.697950, -1.323090, -0.750010, -0.170760, 0.685350,
1.645590, -1.234730, -0.576530, -0.868410, 0.160920, 0.384950, 0.800300, -0.186480, -1.034250, -0.521020,
1.079810, 0.279700, 0.860040, 0.566420, 1.024420, -0.357850, -1.637680, -0.846060, 0.366230, -0.731230,
-0.033180, -0.478060, 0.730350, -0.216800, 0.133500, -1.966560, 0.403040, 0.243530, -0.131170, -0.726150,
1.254880, 0.185050, -0.457530, 0.125610, 1.284360, 1.605100, -0.671330, -1.834060, -0.186640, -0.705220,
-0.285120, 0.349790, 5.130310, 0.401480, 0.888620, 0.465050, -0.192980, 0.697920, 1.068100, 0.549310,
-0.646300, 1.553110, 2.541950, -0.585550, -0.293380, -0.277860, 0.617450, -2.970440, 0.557320, -0.645520,
-0.659870, 0.486600, -1.604390, 0.766210, 0.471770, -0.636520, 0.719480, 2.089930, -1.786810, -0.220950,
0.442840, -0.635710, -0.567950, 1.714240, 1.355320, 0.449040, -0.734430, -1.031070, 0.045510, -0.689520,
-0.380130, 0.596610, -1.491400, 1.142880, -1.328470, -1.032940, -0.313560, -0.139380, -3.720100, -0.540390,
-0.807570, -2.985200, -0.278310, -2.209000, -0.383070, 0.796800, 1.701790, 1.495690, -0.338610, -0.122590,
-0.449040, -1.141190, -0.611060, -0.087250, 0.758680, 1.387170, -0.598110, -1.028670, -1.385580, -1.181520,
0.907100, -1.693800, 1.785670, 0.548030, -1.075540, -0.554170, -0.109070, 1.766720, 0.636120, 0.341430,
-1.013420, 1.136800, 0.021450, 1.952040, -0.400900, -1.168970, -0.270840, 0.453350, 0.608860, 0.790470,
0.239050, 0.261740, -0.887490, -0.053120, -3.058550, 0.718510, -0.340680, 1.470010, 0.760980, -0.356380,
1.731190, 0.865790, 0.239400, -1.018560, 0.299440, 0.357540, 0.085940, 1.363260, -0.998420, 1.565290,
-0.333230, -0.849960, 2.173280, -0.233790, -0.801120, -1.864290, -1.651180, -0.690870, 0.596230, 0.854220,
1.832300, 1.696140, 1.303230, -0.455870, 0.158850, -0.448930, 0.114830, 3.687700, -0.562640, -1.446440,
2.459110, -0.459050, 1.361830, 0.502530, 0.608750, -0.177280, -1.210080, -3.652520, 0.581420, 0.992990,
-2.783590, -0.852790, -4.994280, -1.298500, 1.107110, 1.479660, 0.666350, 1.359530, -0.699570, 3.199610,
0.988980, -0.056620, -0.430830, 1.594530, -0.280160, -0.813200, -0.236040, -1.263620, 1.429920, -0.919250,
-0.074670, 0.286710, 0.062510, 0.583610, 0.711970, -0.814200, 0.597860, -1.079000, -0.413040, 0.351150,
-0.359110, 0.471100, -0.454620, -2.538500, 0.789160, 0.496290, -1.263650, -0.297830, -0.564770, 2.941740,
-2.148570, -1.012430, -0.077040, -0.196150, 0.631850, -0.941410, 0.079060, -1.155350, -0.369440,
1.927510, 0.166080, -0.987770, -0.506420, 0.062540, -0.235800, -1.063850, 1.666530, 0.848870, -0.128140,
-0.180630, 0.666940, 0.823500, -1.582280, 0.447260, -0.556090, -1.341930, 0.427080, 0.638000, 1.746280,
-0.312910, 0.895910, -1.650860, 1.467500, -1.311400, -0.009220, -0.585200, 0.016350, 0.106640, -0.324230,
1.208360, -1.348300, -1.802920, 1.550890, -0.688980, -0.001290, -0.090900, 0.280960, 0.542010, 1.293000,
1.100360, -0.696690, 0.052010, -1.283330, 3.231980, -0.495270, 0.579580, -0.700940, -1.007980, -1.827980,
-1.848850, -0.979750, -1.038230, -0.899060, -0.774770, -0.070440, 2.822430, 1.750230, -0.028690, -1.083720,
-0.707880, -0.822460, 0.893490, 0.197430, 0.243850, -0.376660, -0.293260, -0.759760, 0.344970, -2.678530,
-0.026860, 1.427110, -0.657240, 1.130590, 0.207100, -0.517500, -0.417870, 0.933560, -0.964780, 1.535450,
1.109130, -0.928390, -0.826940, -0.449350, 0.614800, 0.264780, -0.995950, -0.021470, -0.542410, -0.991510,
0.315510, 0.058640, -2.840670, -1.467120, -0.205080, 0.252690, 1.169630, -0.938120, 0.106990, -1.825820,
-0.431230, 0.182110, 0.269790, 1.540350, 0.933300, -0.432700, 0.548990, -0.421950, 0.520020, -0.573260,
-0.217270, 1.621310, -2.406790, 0.743710, 1.500750, 0.055060, -0.501510, 0.584470, 0.337560, 1.864310,
0.840830, 0.358050, 1.676200, 0.148100, 1.360810, 0.583110, -0.031930, -1.034330, 7.091600, -0.311320,
-0.766670, -0.412460, 3.813100, -0.085440, -1.129300, 3.070140, -1.451410, -1.005790, 1.017790, 0.248470,
0.137610, 1.197630, 1.117130, 0.041900, 0.904150, 0.538400, 2.299710, 0.086980, 0.904110, -0.267350,
1.461380, 1.123620, 1.188140, 2.561000, 0.454400, 2.286440, -1.150530, -0.855810, -0.466550, 0.416050,
0.884950, -0.673770, 0.061060, 1.769130, -0.622560, 0.215570, 0.540840, 1.514860, 0.518480, -0.268800,
2.215690, -1.934520, 1.092860, -1.257370, 0.303210, 2.413810, 1.924040, -0.945690, 0.996030, -1.614730,
1.167820, 0.019710, -0.299460, 0.192150, 0.184700, 0.750400, -0.696440, -0.112930, -1.052750, -1.162620,
-0.516830, 0.042350, 2.162430, -0.209000, -0.454570, -1.571230, 1.940160, 0.305940, 1.636790, 0.152960,
-0.911750, 2.301170, 0.697000, 0.817060, -0.338320, 2.126320, -0.516190, 1.582760, 1.333990, -0.213270,
0.451670, -2.137550, -0.763930, 0.665780, 0.236040, -0.314380, 0.335170, -0.127080, 0.362080, 0.145000,
0.549860, 1.677000, -0.243690, -0.569080, 0.820120, -1.042660, -0.977670, 1.733780, -0.548290, -0.789140,
1.210960, -0.508570, 0.339460, 0.327020, 0.302940, -0.342140, 0.015980, -0.688780, 1.193510, -0.028180,
2.044070, -0.431780, 1.104500, 0.402240, -1.531540, -0.826810, -0.606970, -0.012890, -0.381870, -0.405570,
-0.160420, -0.806090, -0.036770, -1.956380, 0.318490, 0.239460, 0.564920, 1.717880, -1.272440, -1.546410,
-2.885830, -0.547910, 1.176130, 1.876320, -0.578590, -1.541780, -0.480570, 1.025090, 1.516270, 0.822480,
-0.549650, 0.353060, 0.953740, -0.666090, -0.717040, -0.362090, 0.839190, -0.115120, 0.547570, 0.098110,
0.656100, 0.156380, -0.613760, 2.531030, 0.359200, 0.877770, 0.043810, -0.024050, -0.525900, 0.236120,
2.184130, -0.460510, -0.195490, 1.223680, 0.004890, -0.201400, 0.775920, -0.601190, -0.759510,
1.688250, 0.257550, 0.458500, -0.779460, 2.013090, 0.471960, 0.529330, -0.760010, -1.300530, -1.485360,
-1.120290, 1.002670, -0.577760, -0.482740, -0.047430, -0.158350, 0.428020, -0.086780, -0.263900, 1.555900,
-0.076930, 1.312090, -1.052900, 0.998340, -0.217050, 0.570230, -0.247870, -0.266850, 1.048310, 0.593060,
0.575970, 0.433510, -0.908340, 0.970300, 0.457340, 1.252450, 0.123720, -0.769290, -0.416150, 2.594880,
-0.334210, 0.030730, -0.441430, -0.827900, -3.225840, 0.324900, -1.008290, 0.673600, -1.259780, -0.508940,
-1.695760, 0.387030, 0.304930, 0.272550, 0.440580, 0.179200, 0.035250, -0.454750, -0.049440, 0.726550,
0.628090, 0.280330, -0.312200, -0.010570, -2.143300, 1.072330, 0.106560, -0.139890, 0.460350, -0.750740,
0.174830, 0.383850, -0.510620, 1.781950, -0.685260, 0.365200, -0.218520, 1.180080, 2.280570, 0.798670,
-1.004420, 0.476000, -0.482650, 1.412610, 1.042640, 0.356230, 0.737040, 0.357530, -0.180440, -0.453100,
1.661120, -0.901050, 0.179500, -0.356330, 0.860770, -0.295930, 0.573660, 0.910310, 0.878030, 0.501990,
0.493240, 0.555830, -0.416950, -0.408550, 0.949400, -1.165840, 0.656770, 0.194540, 0.388200, 1.712590,
-0.575020, 0.799010, -0.204230, 0.238340, -0.481950, 0.267500, -0.421050, 0.084180, 0.493710, 0.364090,
-0.258400, -0.267880, -0.297110, -0.194560, 1.322530, -1.835200, -1.710520, 0.040010, 0.511440, -0.869620,
1.863610, -1.097380, -0.028770, -0.090990, -0.403470, -0.729130, 0.498480, 0.226480, -0.234760, -0.339660,
1.234250, -0.602190, 0.656540, -1.029790, 0.195960, -0.064340, -0.201900, -0.253710, -0.437740, 0.557590,
0.600930, 0.749740, 0.674980, 1.151650, 1.357010, 2.406730, -0.125850, 0.840490, -0.972600, 0.179040,
-0.399690, -0.056850, -1.011100, 0.592760, 0.752760, 0.620320, -1.145370, 0.697630, -1.634860, 1.145530,
2.901140, -0.276290, 1.966980, -0.476760, -1.375310, -0.583170, -0.029970, -0.535220, 0.902110, 0.073040,
-0.906690, -0.699240, 2.063910, -1.380060, 0.416500, -0.633630, -0.525370, 1.417020, 0.846000, -1.282930,
-1.031290, 0.318840, -1.302640, 0.061870, 0.054750, -0.156880, 0.336330, -0.325240, 0.124450, 0.196290,
0.324320, 0.917520, -0.992430, -0.375420, -0.497750, -0.364510, 0.353810, 1.196240, -1.158180, -0.588590,
-0.515550, -0.343640, 0.362090, 0.907220, 1.680090, 0.245890, -0.973990, -1.256270, 0.461680, 1.003730,
0.673290, 1.283820, -1.049710, 0.687000, -0.331650, 1.276640, 1.037080, -0.760760, 0.657730, -0.355550,
-0.134300, -0.781140, -0.173310, 0.213780, 0.044780, 0.488960, -0.521600, -1.794160, -0.110350, 1.009410,
1.098330, -1.170020, 0.152910, 0.511290, 1.576220, -0.369940, -0.695100, 0.813630, 0.141640, 1.748030,
0.624110, 0.339980, -0.376980, 2.993460, -0.965720, -0.519640, 0.107410, 2.180510, 0.497960, 1.692190,
-0.631670, 0.286410, 3.514870, 1.291050, 1.888320, 2.653980, 1.153660, 1.855630, 1.274940, -1.122660,
-2.522460, -0.384610, -1.534010, -0.399040, -1.628840, 0.023630, -0.376040, -0.109540, -1.002920, -0.610010,
-1.245850, -1.167310, -0.757850, -0.620770, -2.078200, -0.092070, -0.505630, 0.240230, -1.063990, -6.155750,
-5.240970, -1.832250, -0.444680, -2.555730, -1.287460, -1.157290, -2.894540, -0.049760, -0.976070,
0.482730, -1.123890, 0.777970, -1.391020, -0.129300, -0.843160, 0.005390, 0.439720, -0.899180, -0.562990,
-0.907300, -0.113540, 0.481220, 1.731800, -2.411480, 0.760070, 1.044010, 0.025620, -0.589900, -0.071110,
0.993910, 0.604700, -0.143720, 1.240170, -1.668860, 1.016720, -0.076970, -0.318830, 0.347660, 0.334630,
0.912740, 0.817660, -0.345940, -0.329880, -0.319350, -0.622770, 2.422770, -0.097410, 2.061120, -0.563510,
-0.297870, -0.166740, 0.579460, -0.224690, 0.904600, 0.273440, 0.225020, 0.541130, -0.072990, 0.173910,
-0.737350, -0.686470, -0.685450, -1.972380, -1.546850, -0.978440, 0.140890, 0.131270, -0.017900, -0.417740,
-1.408620, -0.204440, 0.129910, 0.214330, 1.709030, 0.480210, 0.285260, -1.405460, -0.308370, 0.887540,
-1.481180, -0.683240, 0.092070, -0.226000, -1.359540, 0.923710, 2.108530, -0.895180, 0.818460, -0.704200,
-0.489480, -1.635380, 0.946860, 0.181990, 1.291530, 0.314980, -0.412420, -1.051190, -0.630090, 0.119410,
0.065810, -0.933150, -0.185380, 0.558090, -2.395260, -0.334580, -0.501960, 2.112470, -0.766660, -0.127780,
-0.276750, 1.005570, -0.206160, -0.226350, -0.955540, 0.665300, -1.753620, 0.247810, 0.653910, 1.581020,
1.106090, -1.611800, 0.605010, 0.770460, 0.593640, -16.538000, -1.248670, 0.670730, 0.789760, -0.456900,
-0.988580, 1.160490, -11.519100, -14.078750, -1.521870, -1.899470, 0.267490, 1.491900, -1.433690, -0.863550,
1.417720, -0.549390, -3.866350, -1.282190, -0.703390, -4.780500, -0.814560, 2.762640, -0.309900, 0.891490,
1.747890, 0.751700, -0.503090, -0.210010, -1.321960, -0.020270, -1.221460, -0.922860, 0.242390, 1.347310,
1.962960, -0.081370, -0.007040, 1.515920, 0.380440, -1.255360, -0.855810, -3.225400, 0.147910, 0.672940,
0.118630, 0.183230, -0.309110, 0.332840, 0.327420, -1.210920, 0.478660, 1.523230, 1.162220, 0.734450,
1.125080, 2.291900, -1.288290, -0.240950, 0.734480, -0.512280, -0.659170, 0.425320, -1.035590, 0.290500,
-0.520220, -0.275230, -1.072530, 0.443820, 1.206240, -0.510030, 2.092460, -0.126640, -0.759670, -0.351010,
-1.181310, -0.506540, -0.469030, -0.727100, 0.518780, -1.676930, 0.866770, -1.729720, -1.213100, 0.765670,
-0.225480, -1.263840, 0.878410, 0.477910, -0.819750, 1.442740, -1.161660, 0.551720, -0.213550, 0.152270,
-0.152190, -1.066800, -1.170080, -0.712500, -0.112380, 2.606520, -1.187920, -1.042110, -1.104440, 0.371080,
0.763090, 0.154570, -0.452520, 0.434580, -3.726060, 0.638830, 1.483600, -0.224240, -0.232280, 0.944110,
0.295300, 1.323340, -1.025010, 2.500170, -0.939000, 0.218440, -1.138060, 0.543810, 0.661710, -0.196960,
-0.488980, -0.504380, 1.855760, 0.881610, -0.878300, 1.519470, 0.063030, 0.716720, 1.570430, 1.532280,
-0.285130, 0.091960, -0.155580, 4.056830, -0.330840, -0.490030, -1.022220, 0.129730, -0.412740, 1.354240,
0.547490, 0.089430, 1.887180, 4.414530, 0.940640, -0.316440, -1.228500, -0.986050, -0.948750, -1.360060,
0.795560, -0.090470, -0.616920, -1.063650, 0.553420, 0.598650, 0.344350, -0.987220, -1.010110, -0.424480,
-0.505800, -0.315190, -0.611570, 2.611380, -1.655040, 0.271390, -0.017080, 0.148710, 0.528610, 0.390700,
-0.697080, -0.396770, -1.073090, 0.082140, -1.045880, -0.984980, -0.374430, -0.138460, -0.735200,
0.417890, -0.707320, 0.134200, -0.412590, -0.586620, 1.278080, -1.579480, 0.606760, 1.507390, 0.027890,
-0.065530, 1.058320, 0.566240, 1.543080, 0.046630, 0.302940, -0.296780, -0.148560, 0.413650, -0.741750,
0.886120, 1.432850, 0.823290, 0.951010, -0.044800, 1.277210, -0.215070, -0.335330, 0.480610, -1.065370,
0.509650, 0.981160, -0.216290, -1.935970, -2.014150, 0.465920, 2.697650, -0.739190, 0.089220, 1.359940,
-0.103600, -0.648570, -0.188690, -0.045750, 0.138040, 1.171740, 0.443590, -0.007220, -0.056740, -0.278800,
1.236370, 1.813220, -1.061730, 0.912820, 1.451820, -1.323640, -1.981200, -0.055770, 1.072030, 0.022790,
0.775590, 1.016610, 0.063890, 0.819050, 0.195080, -0.943530, 0.944430, -0.223700, 0.596950, 0.490590,
-0.263420, -0.817350, 0.266910, 0.043430, -0.037020, -1.448550, -2.441380, 1.427540, 0.576540, 0.354320,
-1.548840, 0.566930, 0.771300, 2.218540, 1.249410, 0.331210, 2.966000, -0.977520, 0.863820, 1.193020,
-2.007640, -0.612040, 0.136270, -0.072440, 0.577150, 0.328810, -0.742720, -0.308050, 0.061220, 0.511890,
1.198840, 1.863140, -0.751790, -0.116380, 1.563510, 0.459190, 0.474750, -0.044840, 0.078040, 0.757580,
0.977710, 1.056640, 1.129450, 0.600680, -0.696070, -1.102870, -2.379050, 0.919290, 2.291150, -2.245400,
-0.268110, 2.158900, -2.655910, -3.089950, -2.854940, -0.248410, 0.351650, 0.674160, 0.320050, -1.336890,
0.544710, 0.247800, -2.049840, 2.605670, 1.319970, -2.636910, 0.880500, 0.619880, -0.903660, 0.165290,
-0.725400, 1.110580, 0.393550, -0.058650, 1.137080, -0.568910, -0.892660, -0.348980, 1.244570, 0.245860,
1.209570, -1.376980, 0.328300, 1.053400, 0.225150, 1.161560, 0.239830, 0.942790, 0.573130, -1.166100,
0.188840, -1.729740, -0.488060, 1.921200, 1.090410, 1.711010, -1.954640, 0.960710, -0.394590, -2.150460,
0.441560, -0.850550, 0.096270, 0.519150, -1.402060, 1.290690, 0.752760, 1.108830, -0.479760, -0.526110,
1.186910, 0.923040, 1.063520, -0.021070, -1.028130, -0.634900, 0.932600, -0.819710, -0.065570, -0.617540,
1.321990, -0.069670, -0.646460, 0.019080, 1.077760, 0.883670, 0.059740, -1.027090, 0.905840, -1.290300,
-0.161840, -2.590500, 1.775800, 1.985620, 0.218580, -0.868380, -0.766580, 0.860140, -0.362040, -2.459570,
0.836780, 0.019300, -1.017490, -0.149970, -0.367270, -1.622580, 0.407580, -0.397230, 0.788900, -0.002140,
1.538330, -1.598220, -1.218110, 1.115590, 0.436350, 3.752990, 1.460580, -0.130900, -0.456370, 0.493170,
0.433520, -0.877150, -1.185370, 1.875610, -0.125690, -0.427020, -1.543660, 0.952910, -1.179270, -0.122620,
-3.274770, 0.269400, 0.153320, -2.714070, -0.318910, 0.503540, -0.176880, 0.202160, 0.318840, -0.279710,
-0.834080, 0.366550, -0.052370, -5.587750, 0.439110, -0.738220, 0.058560, -0.467030, -0.802400, 1.280860,
-0.025600, -0.431490, 3.123940, 2.955190, 0.373240, -0.800180, 0.774790, 1.715650, -0.066260, 0.405090,
1.114330, 0.985470, -0.177870, -0.945660, -0.301940, -0.307030, -0.290620, 0.117560, -1.159480, -0.740330,
0.369080, 0.779410, -0.689430, -0.783190, -0.619580, -0.000740, -0.767220, -0.466380, 0.434870, -1.000750,
-1.349010, -0.167980, 0.783350, 0.412810, 0.412390, 0.310310, 0.911420, -0.213310, -0.763000,
-0.349960, -1.917600, 0.171100, -1.234450, -0.751000, 0.608810, 0.199590, 0.235010, -1.105550, 0.221510,
-1.300640, -1.738660, -0.057260, 0.541410, -0.073440, -0.004870, 0.252400, -0.349370, -0.054980, -4.073720,
-0.659510, 2.093540, 0.522000, -0.380700, 0.756920, 0.070710, 0.290430, 1.426220, 0.331810, -0.201110,
-1.041540, 0.105780, 0.578640, -0.721020, -0.325070, -0.625130, -1.533650, 0.523510, -0.946070, 0.012270,
-0.230570, 1.710280, -2.034550, -0.231610, -0.200480, 1.771560, -0.919410, -1.292080, -0.186500, 0.399360,
0.578920, 0.639530, -0.785710, -0.396280, 0.800550, -0.706830, -1.529410, 1.236530, -1.659000, -0.621250,
-0.979300, 1.234440, 0.091960, -0.410220, -1.752960, -1.417430, -0.338890, 0.913340, 1.547560, -0.754460,
-0.227050, 0.170190, -0.754930, -0.378030, 0.867480, 0.322720, -0.143370, 0.513890, -0.577590, 1.180910,
-0.777770, 0.266290, -0.633160, -0.192620, -0.627170, 2.332500, -0.075150, 0.935350, 0.821220, 0.018240,
0.113850, -1.413650, -1.604320, 0.784110, 0.536540, 1.605010, -0.063880, 1.162990, -0.312550, -0.492880,
0.838440, -0.326850, -1.246250, -1.007810, -0.362070, -1.349510, -0.656210, 0.784310, 0.550210, 0.116330,
0.262030, 0.894740, 0.264580, -0.376030, -1.063270, 2.115580, 2.327310, 1.347030, -0.994910, 0.558780,
0.954160, -1.384890, -0.259520, 1.804780, 3.731650, -0.235900, -1.079870, -0.575770, 2.317560, -1.012870,
-2.903940, -0.846940, 3.445200, -1.742970, -0.356870, 7.463340, 0.105570, -1.023950, -0.593450, -0.895070,
-0.311780, -2.108020, -0.713750, -1.513420, -0.545540, 0.419170, -1.633910, -0.784360, 0.794720, 0.719610,
0.067090, 1.273290, -0.923080, -0.368860, 1.896190, -1.468630, -0.042550, -1.121360, -1.597680, 0.427840,
-1.484700, -0.729750, 1.403840, 0.006820, -0.859950, 3.198010, 0.583470, -0.430930, 2.100660, -1.057820,
-1.025450, -0.090670, -1.781700, 0.612120, 0.582510, -1.027100, -0.934360, -1.645310, -1.846920, -0.550190,
0.517640, 0.179120, 0.120600, -1.141870, 0.294880, 0.204740, 2.391280, -2.274070, 0.216960, 1.417050,
-0.109720, -0.977240, 0.209710, 0.529740, -0.031750, -1.379660, -0.555780, 0.208630, 0.917910, 0.553920,
0.945460, 1.178450, -0.023100, -0.698850, -0.321500, -0.384360, -0.978990, 0.855540, -1.108920, -1.298100,
0.618670, -1.347790, -0.791590, -0.956990, 1.399720, -1.220950, -0.798490, -0.803020, -2.313390, -0.572860,
-1.023680, -0.448090, 0.387700, -0.220920, -0.659160, -1.530370, -0.535020, 0.169060, -0.608920, 0.790020,
-0.269870, 1.261280, 0.751030, 1.346770, -0.943440, -1.605400, 0.701990, 0.663410, 0.257520, -0.210010,
-1.455200, -0.844500, -0.732360, -0.118580, 0.760940, 1.953320, 0.292800, 1.050940, -0.173880, 1.255010,
-2.373400, 0.924180, 0.602060, 2.508700, -0.005530, 0.455650, 0.888320, 1.480990, 0.366720, 1.297240,
-0.488110, -1.838750, -2.032220, -0.207600, 1.719170, -2.992730, 0.096640, -0.013250, -1.028090, 0.614160,
-0.747710, -0.145270, -1.086330, 0.238270, 0.618880, 0.350180, -0.459610, 0.597420, -0.714910, -1.094840,
-0.032150, -0.446980, -0.321680, -0.110080, -0.719500, -0.606340, 0.842420, -0.900060, 0.029940, -0.419070,
-1.202530, -0.594600, 0.801620, -0.075900, -0.693010, -0.070940, -0.390080, -0.063940, -0.066670,
0.578140, -1.163720, -1.253020, -0.482440, 0.469230, 0.145810, 0.454060, -0.734510, 0.655940, -1.111500,
0.656240, -0.610700, 0.910070, 0.150650, -0.814920, -0.612110, -0.181930, 1.656560, -0.935690, -0.613570,
0.261450, 2.556810, 0.818360, -0.312010, -0.790560, -1.576970, -1.066310, 0.373760, -0.509800, -0.025210,
1.038480, -1.614100, -0.979260, -0.401760, -0.026420, 0.788930, 0.546700, -0.033910, -1.000350, -1.303230,
-2.313810, 0.613070, 1.260520, 1.224820, -0.782110, 0.647500, 0.830540, 0.324330, -0.419490, -1.490410,
0.966020, -0.478970, 1.710580, -1.024960, -0.830670, -0.697950, -1.212480, 1.100860, 0.520350, -0.653340,
-0.438450, -0.778480, 0.318530, 0.716420, 0.242580, 0.862900, -0.532750, 1.709540, -0.250980, 0.508900,
-0.066350, -1.140070, 1.059990, 0.099590, -0.035870, -1.403800, -2.064160, -0.723650, -1.673750, 0.382770,
0.602040, 1.388660, -0.713450, 0.926370, 1.085610, -0.594620, 1.440120, 0.182280, 0.044120, 0.131980,
0.199850, -0.454250, -0.981740, 0.198870, -1.771460, 2.004210, -0.442810, -0.274120, -0.777050, -0.678130,
-1.950600, -0.497120, -0.247200, 0.362260, 0.381500, -1.355480, -0.394720, 0.694520, 0.316270, -1.047730,
-0.294930, 0.931870, 1.492460, 0.809600, -0.624410, -0.732630, -0.753700, -1.371680, 1.011370, 0.586670,
-0.648340, 0.527140, 0.086830, -2.467790, -2.588960, 1.761210, 1.534610, 2.004580, -2.476190, 4.066780,
0.623390, 2.752200, -6.106070, -0.061750, 1.815360, -8.689670, -1.534880, -0.283310, 0.488490, -0.434800,
0.310640, -0.546370, -0.476660, 2.348850, -0.029520, 0.725270, 0.876770, -0.865970, -0.165930, -0.473110,
0.247490, 2.705440, 1.304480, -0.819750, 1.342060, 0.530570, -0.177320, 0.148110, 0.003920, -0.251290,
0.086480, -0.545680, -0.080130, -1.732110, 0.726310, 0.144900, -0.422770, 0.659190, -2.119490, 0.149550,
-1.006200, -0.778250, 0.850680, 0.994740, 0.813340, -0.537600, -0.114450, -0.350620, -4.965280, 0.191700,
1.676740, -0.308740, 0.545190, -0.518920, 0.509440, -1.259240, -3.278650, 0.748170, 0.863270, 0.272990,
0.500710, -0.612500, -0.971160, -1.880440, 0.195320, 0.283480, -0.426010, -0.296310, 1.037060, 1.296350,
-0.911600, -2.876920, 1.641380, -0.493330, 0.439690, -0.408250, 0.181860, -0.207170, 0.357810, -1.047890,
1.562560, 1.983520, -0.308450, 0.505310, -1.542980, 1.066710, 1.333740, -0.210700, 0.620320, 2.168160,
2.010630, -0.575670, -0.935330, 2.030720, -2.334970, -0.931080, 0.584940, -0.647250, -0.938590, -0.535920,
-1.325150, -0.214110, -0.364410, -0.299820, 0.227520, -1.446720, -1.344990, -1.362930, 0.286390, 0.664660,
0.492900, -1.143160, -0.774400, 0.632070, 2.245520, -0.893850, -1.193440, 0.651660, 0.481920, -0.350330,
1.123090, 0.485150, 0.937540, -0.918620, -0.527200, -0.691990, 0.551390, -0.115530, -1.064450, 0.645170,
0.086270, -0.558140, 2.760460, 1.925810, -1.901530, 0.085820, 0.927400, -0.705620, -0.847580, -0.851470,
0.698860, 0.556910, -0.677910, 0.914830, 1.549340, -0.411990, 0.816060, -0.927950, -0.423640, -0.909080,
0.454730, -0.615010, -0.412000, -0.126890, -0.407290, 0.227370, -0.462820, 0.016040, 0.459990, 0.193350,
-0.281230, 0.474950, -0.755250, 0.367560, 0.911850, -0.585200, 1.007280, -0.277880, 0.809920,
0.342210, 0.105570, -0.164670, 1.084610, -0.325610, -0.047390, -1.357210, -0.633860, -0.974820, -0.049670,
-0.356810, 0.890150, 0.963880, -1.169960, -0.350030, 0.291770, -0.080530, 1.319530, -0.390790, 0.537370,
1.057990, 0.903570, -0.419210, 0.080570, -1.929890, 1.093790, -0.601350, 0.399120, -0.620860, 0.936940,
-0.448020, 0.289020, -0.115650, 0.079110, -1.047080, 0.544760, -0.269990, 0.081380, 0.004490, 0.099480,
0.925650, 1.435690, -0.590860, -0.832810, -0.201730, -1.227080, -0.393160, 0.503960, 1.134310, 1.038450,
0.000870, 0.172880, 2.134810, -1.902060, -1.846820, 1.785900, -0.178540, -0.168160, -1.122700, 1.363590,
0.693130, 0.686500, -0.052720, 0.100750, 0.402980, 0.039040, 0.580180, -0.143360, 0.983230, 0.076110,
0.161620, 0.256560, -0.236250, -0.570150, 0.166970, -1.544800, 0.375610, 0.338100, -1.482930, -0.689910,
0.254310, 0.188720, -1.398300, 0.328250, -1.712200, -0.178260, 0.136660, 0.991830, -1.121280, -0.778960,
-0.788520, 0.561140, -0.034610, 1.413760, 1.138150, 0.636900, 1.057110, 1.730130, 0.032030, -0.537400,
-0.196540, 0.444940, -0.930290, 0.806550, 0.125280, 0.884680, -0.258340, 0.020390, -1.272360, -0.940350,
0.876490, 0.302410, -0.571970, 0.254340, 0.536400, 0.351420, 1.322540, -0.982060, 0.472830, -1.972830,
0.460180, -1.420050, -3.196220, -0.018970, 1.811570, -2.147750, -0.564080, -0.851500, 1.544730, 0.533880,
-1.284820, -1.391010, 2.228070, -2.048920, -0.177780, 6.285940, -0.311500, -0.529490, 1.167290, -1.612890,
0.699000, -0.749520, 0.724340, 1.382520, 0.802100, 0.649070, 0.947630, -1.054970, -0.698630, 0.124530,
0.129660, 1.043040, 0.289500, 0.784130, -0.981140, 0.052320, 1.243960, 0.576090, -0.806610, -0.473760,
-0.526930, -1.047150, 1.915820, -1.287210, -0.255700, -1.080260, 1.779140, 0.838340, -1.446970, -0.693870,
-1.143790, -0.305430, 1.470990, -0.554450, 0.279370, 1.043110, 0.452830, 0.360680, 0.817890, -0.861880,
-0.664160, -1.007070, -0.320570, 0.196880, -0.860340, 2.821940, -0.399080, -0.113410, 1.744410, -0.219250,
-1.262010, -0.143860, -0.487170, -0.598720, -0.641810, 0.111920, 0.026450, 2.032250, 0.108470, 2.079270,
0.448810, 0.247330, 1.068040, -0.043640, -1.043850, 0.560690, 0.099330, -1.520840, 0.006420, 0.758680,
-2.233310, -0.630270, 0.091580, 0.893850, -0.448660, -0.468830, -0.397540, -0.984960, 1.080950, -0.350240,
0.136900, -0.776810, 0.345420, -0.257410, 1.277490, -1.047800, 0.276410, -0.576150, 0.530580, -0.171770,
-0.335950, 0.965090, 0.170530, -0.457120, 0.220770, 0.169660, 1.043310, 0.355720, -0.448480, 0.349200,
-1.245150, 0.957800, 1.046590, 0.329620, 0.462240, -0.762190, -0.440240, 0.957660, 0.873770, -1.335060,
-2.220030, 1.344980, 0.196380, -0.378130, 0.060060, 2.170230, 0.657010, 1.148210, -0.029280, 1.451600,
-0.474690, -0.420630, -0.931410, -1.864640, 1.554540, -3.188780, -0.662100, -0.971190, 0.018360, -0.860930,
0.006610, -1.215880, -0.537910, -0.098900, 0.229190, 0.219790, -0.560900, -0.326830, 0.307610, -0.799840,
-0.729090, -1.409030, -0.146680, -0.634020, 0.262530, -1.287810, 0.175040, -0.820750, -0.939710, -0.585660,
0.314870, -0.716730, -0.292010, -0.455460, -0.911540, 0.299050, -0.638320, -1.329750, 0.327080,
0.810440, 0.204070, -0.470980, 0.304980, -0.462300, 0.228040, -0.591930, 0.594200, 0.693820, 0.356970,
-0.649950, 0.680870, -0.109500, -1.574360, 0.370380, -1.150600, 0.842830, 1.179490, 0.943540, -0.479500,
0.291670, -0.990270, -0.476880, 1.098240, 0.141110, -0.068880, -1.440730, -0.052600, -0.270350, -1.086500,
-0.926560, -0.195630, -0.157110, 2.522780, -1.222410, -0.730480, -0.146360, -0.110020, -0.139050, 0.025180,
1.133470, -2.388430, -0.140640, 0.094420, 0.362340, 1.404690, 0.994600, 0.025030, -1.017110, -1.094730,
0.895440, 0.903040, 0.883480, -0.055900, 1.588670, -0.029780, 0.252860, -0.976810, 1.117250, 0.569360,
0.126030, 0.274750, 0.807030, 0.403230, 0.883520, -0.344430, -0.094090, 0.341120, 1.358690, 0.196560,
1.399090, 0.761280, -0.078450, -0.667630, -2.292470, 1.180240, -0.166350, 0.492450, -0.887430, -0.822230,
-2.810050, 0.678240, -0.454290, 0.810940, 0.560510, -0.688710, -0.401910, -2.217560, 0.414250, 1.672530,
-0.425900, 1.022330, 1.185770, -0.184150, 0.534150, -0.075540, -0.658460, -0.285160, 0.639410, 0.306790,
-0.419080, 1.140050, 0.054220, 0.760640, 0.451210, 0.433140, 0.354330, 1.046950, 1.613510, 1.344780,
0.415390, 0.585400, -0.503010, -1.180420, -0.596160, -0.204870, 1.116270, -0.862050, 3.899160, -1.751620,
1.367100, 1.188510, 0.150940, -0.757950, -1.868770, 1.880770, 0.957950, -0.830430, -0.625050, -0.577700,
-0.151020, 0.323350, -0.265340, -0.152160, -0.075910, -2.182450, -1.922060, 0.668210, 0.046070, -2.143430,
-0.521180, 1.638920, 1.077730, -0.375930, 0.209160, -1.753640, -0.531240, 0.115450, 0.881940, -1.162870,
-0.051960, -0.211830, 0.852580, 0.299730, 0.227250, 0.036320, 0.619670, 2.078510, -0.681290, 0.632630,
0.895660, 2.127160, -0.938280, 0.228270, 0.934470, 0.366730, -1.176220, -1.318210, -2.759120, -1.405510,
0.012350, 1.321860, -0.741180, 0.733930, -0.236500, -2.797500, -0.752970, -0.061590, -0.258560, 1.975220,
0.110500, 0.903420, -1.005380, -0.363810, 1.131190, -0.089020, 0.341050, 1.022390, 0.218520, -2.304960,
1.103990, 0.052410, -0.958540, -0.655460, 0.322590, 0.379810, 0.571380, -1.306890, 0.193550, 0.383060,
0.537330, -0.439760, -0.213860, -0.272460, 0.828360, 0.339150, -0.645310, 0.225000, 1.086250, 0.299130,
0.101500, -0.495480, -0.441030, 0.397710, 0.558720, 0.623900, -0.276010, 0.731120, 0.202640, 1.236760,
0.817910, 0.771150, -0.276060, -0.508790, -0.607840, 1.532320, 0.698510, -2.045810, 1.008410, -0.576430,
-0.374650, -0.591840, 0.043850, -0.654970, 1.277740, -0.595970, -0.153000, 0.179600, -1.356050, -0.347980,
-2.360990, 0.051610, 0.383500, -0.358830, 1.223480, -1.862500, 0.728380, 0.153460, -0.458230, -0.799840,
1.428320, -0.269080, 0.682210, -1.254860, 0.264210, 0.045960, -0.612650, 0.140510, -1.274100, 7.309820,
1.022290, 0.619950, 1.451050, 1.439660, -0.402790, -1.866740, -0.942800, -0.288800, -0.053430, -0.866900,
-1.344380, -1.092730, -0.687610, -1.625270, -1.692890, -0.656660, -0.970870, 0.029140, -0.846310, -1.139080,
0.545350, -1.432260, 0.015250, -2.801710, -0.957790, 0.242570, -2.131060, 0.446130, -4.608190, -0.485020,
0.040950, -1.111390, -1.856240, 0.537610, 0.083900, 0.235380, -0.232930, 0.019580, 0.736730,
0.570420, 0.225680, -0.567740, -0.476560, -1.560200, -0.401140, -0.068450, 0.072580, 0.704060, -0.086460,
-0.284820, -0.062790, -0.583390, -0.509070, 0.879880, -0.501170, -0.113140, -0.387550, 0.586780, -0.110450,
0.271550, 0.827110, 1.072900, -1.042910, -0.550700, -1.481400, 0.939100, -1.418780, 1.039750, 0.747870,
0.123530, -0.510250, -1.038390, 0.032060, -0.636740, 0.315410, -0.952370, 0.861760, 0.183100, -0.092900,
0.400630, -0.076930, 0.699250, -0.052240, 1.372810, 1.875420, -0.802420, -0.457080, -0.372580, 0.440810,
-0.320370, 2.057760, -0.306680, 0.597040, -0.645900, -0.375360, 0.145720, 0.083050, -0.473890, -0.172740,
-1.692460, -1.278150, -0.131730, 0.039600, 0.331860, 2.631920, 0.767030, -0.922740, 0.727810, -1.418600,
0.658800, 0.962670, -0.809280, 0.739280, 1.494480, -1.251120, -0.853630, 0.062680, 1.508240, -0.455440,
-0.242920, 0.484820, 0.428730, 0.436220, -2.320510, 1.390600, -0.560880, -0.595070, -1.154640, 1.202810,
0.230080, 2.179070, 0.799460, -0.290270, 0.537680, -0.832200, 0.217480, -0.552810, -0.257460, 1.547920,
-0.637690, 0.389600, 0.999930, -0.008420, -1.714290, -0.216070, 0.242280, 1.748740, 1.243770, -0.599840,
-0.647460, 0.537770, 1.024420, 0.066690, 1.383910, 0.173490, -2.075310, -2.028850, -0.906700, -0.875760,
-0.922450, 0.770300, -1.240080, -1.366920, -2.471810, -1.652920, -0.414240, -0.267670, 3.293820, 1.495080,
0.795530, 0.175980, -2.094850, -1.080850, -0.552460, -1.140490, -2.122870, 2.455560, -1.189920, -0.978700,
-2.002030, 0.433880, -1.203660, -0.321820, 1.025570, 0.771560, -0.971650, -1.072520, 0.776370, 0.033230,
0.691660, 0.703430, -0.293960, 0.389710, -0.674340, -2.151550, -1.418200, -0.262360, 0.344720, -0.499290,
4.167830, 0.719990, 0.842550, 0.615190, -1.834410, 0.944560, 2.884140, -0.816910, 1.470840, -0.129740,
-1.142240, 0.805200, 1.328230, 0.418110, -0.868510, -0.241570, 0.844150, 0.180750, 0.409220, -1.754990,
-0.271800, 1.047690, -0.530510, 0.054180, -0.579890, -0.973760, 1.010480, -0.304450, -2.307330, 0.013240,
-0.844810, 1.226080, -0.757930, -1.554120, -1.555720, -0.107360, 0.426090, 0.754740, -0.723020, -0.608200,
0.143940, -0.484540, 0.192860, -1.235380, -0.804770, 0.881290, 2.761930, 0.205830, 0.111810, -1.004130,
0.414900, 0.158380, 0.109250, -1.118240, 0.658150, 0.686150, 1.063420, 0.102630, -1.258260, 0.115570,
0.139820, 1.541430, -0.527920, 0.425950, -0.313560, -0.276990, 0.447460, 0.048470, 1.216140, 2.186590,
1.087760, 0.119500, 0.337370, 1.804390, -0.903850, -0.486360, -0.852540, -0.438160, -0.160010, 0.348930,
-0.733870, -0.302070, -1.028250, -0.777920, 0.248430, -0.291210, -0.475340, -0.785010, 0.340070, 0.281250,
1.903860, -0.940430, 0.209400, 1.047780, -0.684450, -0.120340, 0.339260, 0.535820, -0.888850, -0.545640,
2.026900, -0.033060, 1.203640, -0.321620, -1.529640, -0.435270, -0.083530, 2.161940, -0.072250, -0.319230,
-0.503650, 0.065480, 0.636510, -0.228020, 0.478910, 0.724040, -0.562110, 0.995890, 1.054490, 0.145760,
0.648540, -0.251920, 0.125620, -2.637650, 1.014090, 0.337870, 1.019240, 0.251220, 0.724970, -0.133390,
0.992160, 0.993610, -0.026480, -0.619840, 0.646550, 0.770150, -0.064210, -0.093880, 1.410420,
1.516940, 0.328490, 1.295870, 0.103290, -0.005800, 0.291000, -0.083430, 0.323810, -0.672970, -0.244800,
0.513640, -0.686440, 0.446280, 0.084890, -0.139980, 0.505330, 0.120470, -0.838710, 1.008300, -0.216520,
-1.316220, -0.909250, -2.827880, 1.085900, -0.746340, 1.012970, 0.592140, 0.736720, -0.971620, 1.424320,
-0.384190, -1.191740, 2.394970, -0.180580, 0.705790, -0.704860, 0.266150, 0.291990, -0.292310, 0.866730,
1.528260, 0.670130, -0.625930, -2.429940, -0.938530, -0.334330, 0.536740, -0.814970, -1.346760, -0.483930,
0.687890, 0.918710, 1.955600, -1.027650, 0.403210, 0.696030, -0.912930, 1.263370, 0.444450, -1.250660,
0.363340, -0.749860, -0.652980, -0.684000, -0.568370, -0.314080, 1.277430, -0.608130, -1.735270, 0.131940,
0.627690, -0.132760, 1.120080, 0.190090, -0.117080, -1.861720, -0.786440, -1.296450, -0.320180, 0.862690,
-1.910950, -0.527860, -1.137330, -0.466790, 0.130450, -1.016350, 2.201170, -0.994760, -0.734770, -0.690010,
0.888700, -0.668290, 1.646930, 2.197230, 1.459730, -0.394100, 0.045910, 0.877990, 1.402240, -0.400940,
0.177360, 0.094110, -1.028740, 0.994070, -0.656790, -0.428410, -1.390370, -0.586450, -0.939800, -0.595110,
0.577420, 0.975580, -2.579130, -0.996630, 0.740790, 2.248600, 1.264330, 1.202820, -5.300860, 2.894470,
-1.798950, -1.107760, -0.634230, 2.840540, 0.667670, -0.607180, -1.571330, 2.423320, -1.472520, 0.863970,
0.832370, -1.140360, 3.284880, 0.235480, -2.820580, 6.839250, -0.541160, -3.482720, 1.238530, 0.714580,
0.032460, 0.363530, -2.547460, -0.878370, -0.311100, -0.641940, -0.049250, -0.146270, 0.141230, 0.138820,
-0.806380, 1.722420, -0.886890, 0.073240, 0.022280, 0.633120, -0.249660, 0.064140, 0.398540, 0.254310,
-0.916110, -0.620870, 0.575140, 0.693800, -1.990890, 2.935190, -0.461730, -0.778180, 0.202500, -1.034660,
0.883680, 0.467000, -0.978410, 0.605110, 1.230050, 0.311680, -1.043340, 0.535460, 0.034820, 0.695970,
-0.454000, -0.356860, 0.556540, -1.901480, 0.175130, 0.367880, -0.639650, -0.538170, 0.277510, 0.139850,
-1.003860, 0.768240, -0.924040, -0.341990, -0.773480, 0.357580, -0.577370, 0.901120, -0.546540, -0.395790,
0.806070, 1.122010, -0.622430, -0.117310, 0.697400, -0.332820, -0.054870, 0.407150, 0.442840, 1.746100,
-2.619240, 1.108790, 1.539140, -0.606390, 0.318120, -0.782530, 0.692060, 3.496650, 0.062470, -0.816470,
0.367090, -0.763450, 2.285490, -2.084380, 0.982680, -0.988010, -0.502980, 0.001670, -0.742100, -1.380550,
1.235270, -0.982840, 0.741660, -0.008880, 1.220290, 0.046820, -0.682620, 1.320210, 0.889860, -1.148350,
-0.868760, 0.786510, 1.176710, -2.291770, -1.486020, -1.782070, 0.750700, -0.365610, -1.556910, 0.815100,
-0.683220, 1.177850, -1.908000, 0.881630, 0.092080, 0.455190, 1.149240, 0.598440, -0.025390, -0.578380,
0.456570, -0.074450, 0.386850, 0.269960, 1.008220, 0.383450, -0.180100, 0.022480, 0.511270, -0.399870,
0.655300, -0.734340, 1.273870, 0.558600, 0.691960, -0.297350, 0.380480, 0.842870, 1.788620, 0.806940,
1.196190, 0.273510, 1.145600, -4.267400, 0.776080, 1.276040, 1.404050, 0.202820, 0.353270, 0.927720,
-0.505490, 0.791780, 0.607260, 0.497210, 0.920380, 0.284840, 1.254940, 1.308720, 0.589430,
0.097980, 0.881260, 2.254930, -0.949400, -0.157230, 0.393710, 0.413930, -0.287240, -0.975040, 1.361960,
-0.006990, 1.615210, 3.074780, -2.113390, -0.759840, 2.039410, 1.138910, 1.887020, 1.620920, -0.279940,
-4.716730, -0.173360, -2.361280, -2.150140, 1.215630, -0.950750, 0.906680, -0.992880, -0.252190, 0.400730,
-0.382930, -0.468000, -1.500060, -1.434960, -0.420610, 1.107570, -0.771290, 0.957090, -1.169410, -0.507950,
0.297840, 0.200980, 1.560960, -0.433820, -0.256180, -0.433370, 0.385570, -1.202520, 1.159820, -0.094320,
0.549760, -0.572560, 0.070580, -1.079920, -0.226860, 1.738880, 2.156630, -0.747050, 0.099820, -0.117680,
-0.349480, -0.770320, -0.739280, 1.142580, 0.054650, 3.013860, -0.034350, -1.260800, -0.119390, 0.303450,
0.153260, 0.844140, -0.435760, 1.169910, 0.936510, -0.331910, 1.340490, 1.147210, 0.476600, -1.579570,
0.541920, 0.596760, 0.740830, 0.125890, 0.487680, 0.553810, 0.267440, -0.879060, 0.050600, -0.834280,
0.284570, -1.477410, -1.229980, 2.815720, -3.578590, 1.187220, 0.432070, 0.616150, 1.551940, 0.140850,
-1.068670, -0.742170, -1.903910, 0.371110, -1.788850, 0.386550, -0.153410, -0.933980, 1.444560, 0.405580,
0.654230, 0.424070, -2.040740, 1.151630, -1.745710, -0.120430, 1.450600, -0.314090, -2.163200, 0.602600,
-0.143220, -1.427740, 3.566880, 1.091400, 2.830210, 2.074590, -1.738900, -1.003270, 1.501500, -2.669390,
-2.670990, -0.810770, 3.640620, -0.532370, 0.489620, 7.169960, -0.772630, -4.404120, -1.243750, -4.139730,
0.677710, 0.302710, -0.711260, -0.371630, 1.730140, -2.208480, 0.220970, -0.071130, -1.006660, -0.843480,
-0.602120, 1.160220, 0.704830, 1.722880, 1.167740, 1.577740, -1.786930, 1.257790, 0.614900, -0.752690,
-1.460210, 1.193900, 0.047120, 0.462640, -3.811040, 0.403830, -0.192840, -1.103590, -1.122760, -0.129230,
-1.133820, 0.824450, 1.151670, -0.621110, 3.163730, 0.117470, -1.594620, -1.709910, -0.445790, 0.744760,
2.343880, 0.324640, 1.787640, -0.067390, -0.232790, 1.158050, -1.229080, -1.371690, 0.718040, -0.874750,
1.003230, 0.646180, 0.950910, -0.619570, 0.936560, 0.427650, -1.151960, 0.112670, 2.221650, -0.686700,
0.089030, 0.823310, -1.172450, -0.025230, 0.163030, 1.013950, 0.219900, -0.042980, 2.293460, -1.354070,
1.384110, -0.150490, 0.000250, 0.501850, -1.101930, -0.131040, 1.915170, 0.498580, 0.576210, 0.909830,
-1.487830, 0.738360, -0.565610, 0.363930, 1.871770, 0.868220, -1.260620, -0.147150, 2.965090, -2.903640,
0.370170, 1.613760, 0.621720, -0.834200, 0.000350, 0.420110, -3.019620, -0.801180, 0.299470, 1.069640,
0.660170, 1.240800, -0.344990, -1.640560, 0.710490, 0.756330, -0.473730, -0.185760, 0.079500, 0.971620,
-3.072800, 0.580020, -0.147530, 1.024710, -0.025390, 0.890030, 0.045440, -0.366380, -0.214950, -2.113960,
-0.187000, -0.372130, -3.803880, -1.748020, 1.025270, 0.785370, -0.153820, 1.568300, -0.392850, 0.259700,
0.449160, -0.205960, -0.291870, -0.405630, 0.295000, 0.480450, -0.155890, 0.179360, -1.068420, 0.071040,
0.654200, -0.193880, -0.100510, -4.191710, -1.204760, -0.092050, -0.425310, 0.672400, -0.574520, -0.183230,
0.506140, -0.857120, -0.621460, 0.095820, 0.302850, -0.181710, -0.257690, 0.100080, -0.126510,
0.679950, 0.011830, -0.185090, 1.073570, 1.158490, 0.807580, 1.503950, 0.235600, 0.528550, -0.216920,
0.476290, 0.651820, -0.219090, 0.783490, -0.406180, -0.123750, -0.076770, 0.176590, -1.365610, 0.152380,
-2.376020, 0.119590, 1.498670, -0.380200, -0.979840, -0.761890, -0.390100, 0.826420, -1.414710, -0.730880,
-0.346910, 1.050850, -1.629140, -0.821320, -0.323580, -0.805250, 2.244100, 0.786360, 0.834450, 0.737490,
-0.715810, 0.576800, -0.015120, 0.537790, 0.379260, 0.177100, 0.028900, 0.266000, 0.171340, -1.364400,
-0.343850, 0.716870, -1.189990, 0.592920, 1.297360, -0.787680, 0.899370, -0.997590, -0.305940, 2.732320,
0.599410, 0.286760, -2.039660, -1.505450, 0.649800, -0.934800, 0.153610, -1.403280, -0.472920, -1.194440,
-0.858230, 0.670640, -1.841080, 0.512980, 3.971240, -0.505980, -1.257710, -0.548140, 0.758140, 0.860170,
1.447720, 0.482100, 3.193370, -0.698610, -1.198990, -1.362620, 0.974200, 0.356540, -0.022090, 2.535920,
-0.154970, 0.308240, 0.346470, -0.639980, -0.568670, 0.191620, 0.881610, 0.330000, -1.351880, -0.696990,
-0.593830, 0.384660, -0.622940, 0.356900, -0.550740, 1.315090, -2.066130, 0.128790, -0.271310, 0.998020,
-0.705130, 0.206910, 0.598340, -1.244440, 1.929600, -0.399800, -2.993260, 0.652740, 0.074110, 0.487400,
-0.917630, 0.352980, 0.143160, 0.229350, -1.444190, -0.128270, -0.056000, -0.029760, -4.963110, 0.203840,
1.228740, 0.940680, -1.745030, 1.082400, 0.768420, -1.055420, 1.008240, 6.688130, 1.624560, 2.716520,
-0.553270, 0.631220, 0.590470, -0.245000, 1.337980, 2.104300, -1.786850, -1.882280, 0.398090, 0.234630,
0.356590, -0.787810, -1.203440, 2.785350, 0.031690, 0.581420, -2.564040, -0.217460, 0.000420, 0.430520,
1.490740, -0.685150, -0.785730, 0.786090, 0.261070, 0.523980, 3.068100, 1.279040, 0.860310, 1.203150,
-0.449600, 0.008460, -0.201170, -0.205310, -0.600480, -0.230810, 1.557390, 1.814580, 1.171850, -1.448830,
2.862790, 1.754910, 0.079070, 3.040480, -2.218270, 0.041040, -1.692560, 0.052200, -0.115620, 1.331690,
1.728650, 0.787410, 0.437080, -3.123480, 0.949840, 0.962020, 0.339730, 2.027810, -0.493930, 4.301760,
0.273780, 0.294340, 0.409470, 1.235500, 0.015440, 2.349730, -1.726610, 0.272060, 1.016730, -1.076210,
-1.457280, 0.307860, 2.171500, -1.259500, 0.989770, -2.172160, 1.653680, 3.256400, 1.023140, 0.776800,
-0.351500, 0.167670, -0.307480, 0.903780, 0.733440, -0.396400, 0.138140, -0.259470, -1.113040, 2.800480,
0.252990, -1.665350, 0.752920, -0.795670, 0.753710, 0.390950, -1.207880, -0.386660, 0.311240, -1.614610,
-0.294140, 0.758260, 0.803300, 1.238640, -2.003610, -0.091780, 0.381600, 0.096880, 0.254490, 3.340960,
0.205230, -1.317180, -0.909460, 0.459340, 3.812010, -0.990830, 1.117460, 0.160450, 0.204500, -0.961750,
2.355480, 0.780090, -0.377050, 0.991760, -2.157400, 0.604300, -0.178140, 0.564150, 0.212580, -0.352780,
1.258790, 0.285030, 0.816020, 0.164330, 1.016880, 0.096420, 0.077290, 0.951380, 1.170090, 1.073870,
-0.529440, 0.883970, -0.342820, -0.962470, -0.264960, 0.902430, -0.425560, -0.701320, -0.559230, -2.034430,
0.457780, 0.121020, 0.231980, 0.743670, 0.059490, 0.272310, -0.750190, 0.179350, -0.200030,
0.498110, -0.560060, 0.962890, 0.986970, 0.348820, 1.377070, -0.304210, 1.305680, 1.005870, -0.702050,
0.624920, -1.055950, 0.999880, 0.639630, -0.277830, 0.810610, -0.582630, -0.640380, 1.060200, -0.147560,
-0.756610, 0.843910, 0.024910, 2.195220, 0.443380, 1.387120, 0.483730, 0.255270, 0.502460, 1.846650,
1.325630, 0.846850, -2.781390, 0.892740, -0.556510, 0.642060, -0.517430, -0.297530, 0.429590, 1.439350,
-0.422710, -0.277130, 1.010930, -0.964160, 0.876900, 0.753200, 1.897600, 1.083870, -0.729690, -0.437220,
0.463030, -1.008260, -0.284370, -0.543020, 0.874440, 3.010000, -1.187150, -0.170950, -2.533520, 0.127210,
-0.908210, 0.741500, 0.270270, 0.026830, -2.479580, -1.255270, 0.066260, 1.542990, -0.578770, 0.246420,
0.125330, 0.353550, 0.042480, -0.435770, -1.299640, 0.005700, 1.754980, 1.015910, 0.050430, 0.246570,
1.018890, 1.790820, -0.037320, 2.856080, 0.418990, 0.294800, -0.721920, -1.809470, 0.626780, 0.181270,
1.582020, 1.454850, -0.365350, -0.907440, 0.393290, -0.173140, -1.972690, -0.624540, -0.038990, -0.264280,
-0.865000, 0.842420, 2.579990, 0.027480, -1.338060, 0.260780, -0.335820, 0.550390, -1.720930, 0.079020,
0.044490, 0.675190, -0.209160, 0.330830, 0.921140, -0.657240, -1.988440, -0.255590, -4.136920, -0.869170,
-5.231920, 2.721360, -0.544640, -3.802830, -3.453880, 3.565910, 5.044510, 3.365180, -6.132390, 0.690400,
10.616310, 1.956310, -0.732050, 13.599030, 1.095690, -0.111200, 5.043100, 3.542590, 1.277220, -0.383600,
0.316660, -0.180910, 0.759960, 1.629850, -2.631720, 0.134210, 0.405860, -0.567930, 0.368250, 0.190240,
-0.170300, -1.716710, 0.540310, -0.088450, -0.374850, 0.803620, -0.321570, 1.997860, 0.749870, -0.641450,
0.675980, 0.135700, -1.295480, -2.250490, -0.260480, 1.371790, -0.651450, 0.347700, -0.234870, -0.935860,
-0.023380, -0.139300, -0.770050, -0.647200, -2.132180, 1.300020, -0.618650, -0.485020, -0.102190, 0.438000,
1.412810, 0.181770, -2.147480, 0.699190, 0.695670, -0.449630, -0.500540, -2.304720, 1.466210, 0.850830,
0.932700, -0.987440, -0.343740, -0.435890, 0.235890, 0.337840, 0.368560, -0.551790, -1.176720, 1.120420,
-1.322330, -0.396860, 1.437110, 0.140600, -0.968000, 1.211560, -0.028630, 2.523510, 1.507160, 0.583320,
-0.641660, 0.286450, 0.079110, -0.901820, -1.239760, -0.745070, -0.184240, -0.900060, 0.149280, 0.060830,
-0.612330, 1.664720, -0.079640, -1.872220, 0.197560, 0.478450, -0.571200, -0.732710, -1.151760, 0.474850,
-0.600130, 2.076840, -1.278250, 0.588900, -0.085160, -0.951790, -2.335070, 1.222270, -0.207720, 1.784960,
1.726710, -0.536550, 2.692450, -0.338070, 0.853040, 0.317030, -0.327000, 2.008750, -1.390530, 0.323030,
-0.669740, 1.137980, 0.390320, -1.516940, 0.714530, -1.402670, 0.054000, 0.514010, -0.941190, -0.331460,
0.906180, -1.095530, 15.892400, 0.009170, -0.739400, -0.479890, -0.229760, 0.256240, 0.621980, -0.480930,
0.163520, 0.128540, -0.524450, 0.589250, 0.577000, -0.478250, 0.614320, -0.031370, -0.668920, -1.027760,
-0.679410, 0.511120, 0.260540, -0.512960, -0.349530, -0.698260, 0.452280, -0.649480, 0.596570, 1.256620,
-0.290480, 0.296010, -0.523120, -0.900910, 0.236510, -0.502190, -0.850530, -0.572830, -0.433220,
0.157640, -0.060410, 1.106930, -0.362970, -0.230770, -0.209080, -0.284900, 0.991210, -0.376190, 1.075070,
0.708780, 0.482190, 0.148750, 0.295280, 0.702630, -1.441500, 0.360240, -0.192610, 1.138410, -1.147920,
-0.540860, -0.633960, -0.636680, -1.118340, 0.870540, -0.304560, 0.627740, 0.789660, -0.352630, -0.618410,
1.492060, -1.242780, 0.715640, 1.188560, 0.462030, 2.197160, -1.858710, 0.826820, -0.819650, -2.262720,
0.450840, 1.192960, 0.259320, 0.347020, 0.028440, -1.332570, 1.628570, -1.446140, 0.947990, -1.639080,
0.920020, -0.579630, -0.389060, -0.329580, -1.052740, 0.321610, -0.659290, 0.909940, -1.906730, -0.950510,
-0.018520, 1.213070, 0.244190, -0.550200, -0.816300, 0.475550, -1.368100, 1.090140, -1.120010, -1.800270,
0.983020, -0.350440, 1.187190, 0.510920, -0.918760, -0.034840, -0.679610, -0.659530, 2.895530, 0.711570,
1.258310, -0.625310, 0.491610, -0.075510, 0.007750, -0.341310, 1.122600, -1.294470, 1.366960, 1.253640,
2.000930, 0.653470, 0.204100, 2.422890, -0.221280, 0.289500, -0.835960, -0.202370, -2.579100, -0.689370,
0.348830, 0.444430, 0.800620, -0.214820, 0.746910, 0.058080, 0.730720, 0.297330, -0.728140, 0.984700,
1.093010, -0.198930, 2.235510, 1.787670, -0.338220, -5.250770, -0.841950, 1.651860, 3.991380, -6.040690,
0.409440, 5.398030, 0.626370, -10.367960, -10.817550, 1.989900, -0.426980, 1.393860, -0.111160, -2.013830,
1.702800, 0.550750, -2.715460, -0.819790, 2.159170, 1.881470, 2.381340, 1.513810, -0.509170, 0.196060,
-1.440310, -2.254980, 1.438300, -0.199830, -0.909170, 1.236350, 0.035990, 1.378970, -0.999190, 0.597740,
0.736190, -0.881560, -0.357050, 0.016720, 0.491390, 1.640190, 0.260960, 0.457680, 0.888800, -0.322590,
0.475510, -0.646530, -1.521250, -0.342080, 0.034580, -0.291110, -0.443140, -0.033080, -0.916920, -0.871630,
-0.719700, 1.188090, -0.674500, 0.335060, 0.212400, 0.027190, -0.484220, 0.391370, -1.678040, -0.518990,
0.269460, -0.133050, 0.013670, 0.098930, -0.390130, -1.110050, -0.898110, 0.153020, -1.273480, 1.810760,
-0.622540, -1.418820, -0.889330, 0.630510, -1.428070, -0.213490, -1.916710, 0.418520, 1.094160, -0.179200,
-0.088660, -0.595880, 2.608680, -0.118150, 0.408480, -0.880050, 2.284920, -0.509520, -1.305680, -1.533010,
1.308640, 1.238620, 0.383980, -0.237280, -0.345030, 1.028860, 0.796920, 0.722470, -0.072770, -0.104420,
0.072920, 0.937960, 0.306190, 0.078590, -0.359160, 0.738400, 1.605790, 0.107800, 0.330060, -0.653740,
-1.055770, 0.750480, -0.550310, 2.535480, 1.064850, -0.687400, 0.161220, 0.309880, 1.236070, 0.007950,
-0.136300, -0.472490, 0.434580, 1.558940, 1.069030, -0.572480, -0.724100, -1.222910, 0.764600, 2.197290,
0.954290, -0.740540, -0.376010, -10.034300, 0.211700, -0.873440, 0.552720, 0.008810, 0.687300, 1.260170,
-0.567030, 0.103310, 5.742410, 4.010230, -0.861780, 1.523770, -0.831270, 0.951520, 0.106340, -0.116780,
0.750870, -0.342150, -0.554320, 0.694050, 0.309340, -0.662030, 0.531120, -0.312340, 0.116740, -0.209250,
-0.837520, -1.081690, 0.674920, 4.413250, 0.411500, 0.207430, 0.747260, -0.008380, 0.158760, 0.072380,
-0.316400, 0.036460, -0.415490, 0.046230, -0.711270, -1.644330, 0.106800, -0.714110, -0.754340,
-0.240980, -1.322090, 1.081360, 1.953250, 0.120290, 2.453220, 0.620860, 1.733430, 0.203620, 1.107250,
0.305140, -0.034350, -0.224500, 2.295970, -0.766380, -0.144700, 0.695640, -0.587930, -2.232380, -0.128400,
0.087340, -0.552730, 3.151080, 0.784320, -0.037680, 0.188680, 1.303580, -1.504290, -0.110430, -0.409060,
-0.368530, 0.345710, -0.537990, -0.103930, 0.481860, -0.101130, -1.719470, -0.693360, 0.217230, -1.296630,
-1.711250, 0.058530, -0.334250, 0.611900, -0.406480, 1.726220, -0.505640, -0.145180, -1.684810, 0.445530,
-0.240300, 1.573060, -0.854730, 0.734510, -0.428110, -0.759270, 0.639560, 0.195120, -0.860690, -2.171490,
-2.264620, 1.704360, -0.315410, 0.887270, 0.887490, 0.708990, -0.724900, -1.101160, -0.343740, -1.219250,
-0.118780, -0.161380, -0.327010, -1.623980, 0.143990, 0.374330, 0.209690, -0.447470, 0.229530, -0.163790,
-0.261070, 0.511830, 1.324990, -0.965120, 0.455120, 0.478490, -0.883990, 0.077750, 2.024710, -0.922200,
-0.119090, 0.234760, -0.490290, -0.018120, 0.087640, 0.098540, 1.144090, -0.226870, 1.291590, 0.033360,
0.309240, -0.588260, 0.252920, 1.197620, 0.363750, -0.300220, 0.321840, 3.092840, -0.052700, -0.075330,
-0.058910, -1.034340, -0.603100, -0.557380, 0.056400, -1.254490, -16.023260, -5.319860, 0.749930, -5.201340,
-2.996210, 3.109550, -3.366060, 1.942780, -5.432250, 2.634140, 2.956760, 2.917450, 0.212600, 0.304730,
8.519670, 1.341430, -9.871270, 2.221950, 2.459450, -3.836850, -1.460040, 1.064230, -1.568620, -2.593730,
-1.122840, 0.006650, 1.483240, -1.380780, 0.239200, -0.148350, -0.184000, -1.777430, -0.357340, -0.134110,
-0.264730, 0.207140, -0.779800, 0.901990, 0.025890, -0.605860, 0.552980, 0.806190, 0.313990, 2.482680,
-0.564220, 0.453460, 0.162040, 1.594840, -0.340820, 0.059780, 0.611160, 0.672250, 0.632990, 1.542060,
0.189250, 2.012260, 0.687080, 0.654320, -0.652020, 0.112010, 1.608670, 0.741670, 1.835700, 0.493140,
-0.350470, 0.295370, 0.000390, -0.327670, 1.017610, 0.367890, -3.865580, -0.042090, -0.107860, -0.060330,
-0.419950, -0.040980, 0.154990, 0.498570, 0.644270, -0.094470, 0.453940, 0.610680, 0.516170, 3.511710,
-0.398490, -0.190390, 1.187410, -0.914790, -0.118210, -1.570600, -0.146760, -0.062680, 0.706760, -0.226410,
0.509180, -0.201880, -0.623360, -0.307040, 1.065210, -0.128860, -0.782870, 1.450250, 0.593460, -0.001470,
0.059820, 1.291230, 1.717920, 0.128360, -1.068150, -0.022100, -1.068120, -0.094070, -1.140310, -0.156610,
1.143610, -0.856980, -0.333970, 1.470690, -0.260670, -1.373200, -0.153700, -1.015520, -1.286240, 0.229090,
0.254770, -1.197920, 0.558480, 1.430660, -0.852480, 0.343280, -0.026960, -0.874930, 0.178010, 0.090070,
1.086910, -0.457230, -1.090970, -5.453950, -0.088560, 1.168090, -0.151300, 0.949900, 0.263510, 0.155040,
-1.037480, -0.001710, 2.085660, -1.996820, -1.818110, -0.091480, -0.287390, -0.683390, -2.132680, 0.196220,
-0.520950, -0.606120, 0.492180, 0.593100, 3.142850, 0.170660, 1.177210, -0.433450, 0.508110, 1.114400,
0.855570, -0.499300, -0.437970, 0.013960, -0.470990, -0.708840, -0.332390, 0.332080, 0.506610, 1.934910,
0.325410, 0.476660, 0.030080, 0.144970, -1.016450, -0.690820, 0.745560, 1.063360, 1.150890,
0.715620, 0.916940, 0.537380, -1.965600, 0.342110, 0.664340, 2.094100, 0.769440, 0.551310, 0.756320,
0.014740, 1.021450, 0.256550, -1.224530, 0.334440, -0.289980, -0.669190, -0.241400, -0.282410, 0.895480,
-1.296710, -1.815060, -1.470190, 0.119760, 0.538880, 0.191280, -0.070210, 1.462160, 0.763720, -0.543340,
-0.344280, -0.487020, 0.820870, -0.537440, 0.195660, 0.252470, 0.292190, -0.542010, 0.797130, -1.837040,
1.651510, -0.431520, 0.708010, 0.398610, -0.690720, 0.314890, 0.605780, -0.305820, 1.085650, -1.124030,
0.262090, 1.165240, 2.074310, -0.923600, 1.018740, 1.210770, 0.203510, -1.435700, 0.759370, 0.920680,
2.356360, 0.145080, -0.608580, 0.511770, -0.390020, -2.048620, 1.924340, -1.220960, -0.480630, 0.742090,
0.853820, -0.293670, 0.346510, 0.177850, 1.178930, 0.870490, 1.282850, 2.668420, -0.699640, -1.909640,
-0.422200, -0.231730, 0.273950, -0.484400, -1.146200, -1.364970, -0.236870, -0.744730, 0.008930, -0.691240,
0.184890, 0.147680, 1.021920, 0.553190, -0.995160, -0.157910, 1.850430, 0.256650, 0.611570, 0.702320,
0.971820, -1.857700, -0.146560, 0.535110, 0.207050, -0.661900, -0.221080, 0.060970, -0.909780, -0.602410,
1.325680, 0.176570, -0.726130, -0.975550, -3.064490, 3.822800, 2.646090, 5.161640, -1.332860, -0.509440,
1.739060, 1.411010, 0.197660, 1.517920, 5.521240, -1.885970, -0.630150, -2.377500, 1.391490, 0.921440,
-1.806420, 0.136450, 4.628100, -0.725850, -1.729090, 2.075330, -1.687690, -3.810660, 0.579230, 0.014950,
1.128900, -2.291960, 2.282260, 0.064500, 0.135480, -0.041920, 0.970930, -0.034150, -0.681450, 1.873590,
2.313760, -0.995390, 1.142930, -1.370140, -1.341760, 1.969440, 1.061470, 0.721430, -0.815400, 0.450190,
-3.546050, 1.263540, -0.885040, 0.341310, 0.119810, 0.184230, -1.374420, 0.794850, 2.103390, -1.085600,
1.238570, -0.455420, 0.817160, -0.418420, -0.378950, 1.580310, 0.281280, 0.100190, 0.476590, 1.445870,
1.066380, -0.116770, 0.083690, -0.541130, -0.363510, -0.310000, 0.218320, 1.281620, -0.149940, 0.165050,
-0.302960, -0.065390, -0.666590, -0.756280, 1.002710, -1.401410, 0.671260, -1.358330, 0.805080, 0.380820,
1.289480, -1.164070, 0.993940, 0.541490, -3.464120, 1.310680, -2.622020, -0.868030, -0.068780, 0.833440,
-2.335810, 0.572940, 0.073780, 0.362000, -0.544290, 2.539280, 0.290780, 1.592310, 0.118960, 0.533240,
0.297160, 0.115690, 0.623560, 0.623310, -0.788020, -1.387910, 0.015430, 0.861490, -0.711570, 0.111270,
-0.340560, -0.481170, 1.524030, 1.156480, -0.184620, 0.223010, -2.012640, 0.544420, -0.385290, 0.203370,
-0.438420, 1.337930, -0.530360, -0.304070, -1.137720, 0.215710, 1.079940, 0.444350, 0.275340, 0.195200,
1.157300, 0.447970, -1.107180, -2.240730, -0.274510, -0.068460, 0.577710, -0.661450, -1.590600, 0.950480,
-0.503180, -0.442340, -1.282370, -1.812100, 0.817850, 0.017420, -0.449760, 0.622420, 1.392230, -0.630120,
1.223260, 0.088630, -0.457840, 0.729550, -0.760660, 0.735310, -0.441930, -0.786760, 0.135500, -0.233550,
0.490370, 0.146700, -0.743230, 2.033760, -1.448350, 0.569570, 0.897500, 0.778460, -0.065330, -0.028020,
-0.727420, 0.568360, 0.350210, 0.522150, -0.163450, 0.539490, -0.292630, 0.994540, -0.758440,
-0.134340, 0.505150, 0.908010, 0.705700, -0.045440, 1.082910, -0.374160, -1.467390, -0.395950, -0.856240,
0.035320, 0.647930, 0.749210, -1.101590, 0.497860, 0.956750, -0.920500, 1.014650, 0.840030, -0.076270,
-0.108030, -0.334550, -0.147880, -0.363650, -0.375200, 0.442370, 0.269850, 2.262940, 0.731790, -0.044100,
-0.023270, 0.164330, 0.601660, -1.619800, 0.347630, 1.254210, 0.827940, -1.455120, -0.711110, -0.563910,
0.789270, 1.463220, 0.166320, -0.630690, 0.774220, -0.057220, -0.035550, -1.467030, -0.196660, -0.044650,
-0.163970, 0.203260, 1.104510, 0.164010, -0.317360, 1.596800, -1.212770, -0.637740, -2.889530, -0.192080,
1.186830, -1.147410, -1.292620, 0.672430, 1.429280, -1.285930, 0.786420, 0.022230, 0.055090, -2.124390,
-3.582580, 0.510420, -1.797050, 0.516640, -0.610060, -0.619150, 1.839690, -0.361530, -1.303530, 0.696670,
-2.053760, -1.091290, 0.526910, -1.868370, 1.038350, -0.238150, 0.651380, -1.655480, 0.413780, -2.870410,
-0.076370, -0.013300, 0.450400, -1.893560, 0.179600, 0.788730, -3.257050, -0.355700, -0.445840, -1.254860,
-0.760170, -1.303400, 1.052360, -0.890180, -1.754850, -0.034150, -2.621650, -0.339010, 0.627500, 0.344830,
-0.975940, 0.426440, -0.760640, 1.098650, 4.816690, 0.823370, 1.668600, -0.143210, -1.887530, 1.973730,
0.729550, -1.115140, 0.542610, -1.800400, 2.500200, -0.814660, -0.886420, -0.288430, -6.686440, -1.490970,
2.460270, 1.361250, 4.340280, 0.169470, -0.685670, 5.535180, 2.787870, 5.090160, -0.824420, -0.652520,
-0.055200, 0.274970, -0.946940, -1.682200, -1.984400, -3.237330, -0.825730, 0.107120, -0.453470, -0.666730,
-0.460660, 0.200900, -2.108660, -1.969250, -0.767250, 0.384270, -2.422450, -0.204770, 0.822470, 0.116480,
3.216140, -0.660760, -1.601880, 1.325070, 2.863470, 0.257910, -0.787080, 0.825630, -0.014270, 1.383350,
0.155140, 0.157010, -0.310340, 0.521210, -4.234500, -0.487380, -0.253540, -0.041450, -0.743650, 0.582280,
-0.116160, -0.513950, 0.763080, 2.378630, 1.006160, -2.804060, 0.967260, 1.028660, -0.048470, 0.597760,
-1.905090, -0.303070, 1.229670, 2.428200, 0.962680, -0.385970, -2.027960, 0.990900, -0.021060, -1.330760,
-1.721410, 1.681500, 0.370240, 0.488900, -0.840240, 0.241440, 2.419700, 1.302150, -0.188690, 0.328760,
-1.562840, 1.750270, -1.667820, 0.582410, -1.853490, 1.779930, -0.107280, 1.214000, 0.331720, -0.122110,
-5.607950, -1.009610, -0.109740, -0.098160, 2.476380, -0.191490, -3.504900, -0.900510, 2.037250, 0.361000,
1.076730, -0.596700, -0.674600, 1.851690, -0.923600, -0.759180, 0.219830, -1.021420, -0.790010, 1.889170,
-2.032590, -1.234480, -0.173040, 0.050100, 0.190190, 0.952310, 0.195570, -0.388390, 1.934060, 0.392440,
-1.891900, 0.964770, -0.400830, -4.162580, -0.493680, -1.257190, -0.509420, 0.321600, 0.705270, -1.986200,
0.905150, -1.765190, -0.851630, 0.439480, 0.837090, 3.643370, -0.304100, 0.653570, -0.678780, 0.424890,
1.173800, 0.987480, -0.457380, -0.412730, -1.662610, 0.722330, -0.358590, -0.143440, -0.094200, -0.266850,
0.399870, -1.434690, -0.470440, -0.663850, 1.167320, 1.006890, 1.469190, -0.298510, -0.065270, -1.531160,
-0.266350, -0.171560, -0.905200, 0.907400, -1.346290, -0.808900, 0.465700, -0.707810, -0.959750,
-0.132980, 0.016790, 0.468920, 0.071090, -0.036380, 0.630640, 0.794950, -0.234710, 0.424260, 0.380040,
-1.027470, -0.251610, -0.054030, -0.203400, -0.414300, -1.054950, -0.635210, 0.237510, -0.474620, -0.541970,
-1.028490, -0.956510, -0.313820, -0.494330, 0.316220, -0.092790, -0.995180, -0.224220, 0.863100, 1.469900,
-0.311360, 0.484430, 0.104590, -0.014500, -0.584770, -0.230910, 0.435840, -0.632960, 2.619580, -0.068720,
1.269970, -0.564020, -0.512420, -0.890140, 0.463500, 0.748820, -0.096560, -0.454650, 1.849740, -0.138620,
0.089570, -0.252200, 1.344540, -1.601550, 0.297780, 0.365040, -0.258000, 0.902820, -0.437970, -0.754180,

1.631470, 1.292300, -0.185710, 0.514890, -0.402260, 0.456240, 1.216550, -0.746010, -1.148220, 1.320080,
-1.483690, -0.582140, 0.556160, -0.175400, 1.328100, -0.379220, -0.194340, -0.703700, -0.585750, -0.989500,
-0.669210, 0.338660, -0.660940, -0.901950, 0.844600, 0.127130, -1.150640, -0.438720, 0.496020, 0.178990,
0.263770, -0.794970, -0.167030, -1.133170, 1.709330, 1.528750, 0.166040, -0.212240, -1.731580, 0.257310,
-0.130040, -3.317390, -0.611610, -0.732670, 0.718100, 0.836050, -0.482290, 0.074440, -1.058600, 0.318350,
-0.267420, -0.679080, 0.072400, -0.803190, 0.264190, 0.161780, -3.680990, 2.725120, 0.307030, -1.855830,

0.514090, -0.623040, 0.050310, 0.764470, 0.345550, 0.546220, 0.151080, -0.119880, 0.464630, 0.231160,
-0.006970, 0.042720, -0.653760, 0.231670, -0.504730, -0.193530, -0.544260, 0.640900, 0.022530, -0.118480,
-0.750150, -0.870930, 0.600150, -0.302320, -0.246610, -0.431810, -0.168810, -0.319910, -0.325100, 0.295830,
-0.317760, -1.262520, -0.371620, 0.817470, -2.196320, 0.532070, -0.463470, 0.518500, 8.843840, 0.198270,
0.002010, -1.966630, 0.804500, -0.454480, 0.352640, -0.763400, -0.358960, 0.298150, 0.035160, 0.769900,
0.997490, -0.679410, 0.337820, 2.471200, 0.525150, -0.679680, -1.406710, 0.208580, 0.695750, -0.148810,

-3.568120, -0.437460, 0.028060, 0.433780, -0.072440, 1.271010, -0.570210, 0.469650, -1.086610, 0.128320,
-0.188870, 0.571290, 1.097380, 0.616460, -64.906883, -0.362500, 0.575500, 0.101560, 0.467840, -0.108510,
2.257740, 3.006410, -0.931870, 0.893840, 0.067100, 2.055620, -55.256939, -0.486510, -1.045880, -0.917820,
-0.853500, 3.694970, 0.748010, -1.739300, -28.342770, -0.267570, 0.503410, -5.176510, 1.255130, 1.359930,
0.568310, 0.535530, -1.316530, -0.396240, 0.108860, 1.603290, -1.465770, -1.884720, -1.594220, -1.671910,
-0.424800, -0.743820, -0.491170, 2.145500, 0.058130, -0.828040, 1.844660, 3.893470, -0.294730, -1.558840,

0.566250, -249.057022, -1.531200, -0.145290, 1.004600, 0.613170, 0.117890, -16.635811, -0.556830, 0.371670,
-2.398760, -1.498770, -1.055660, -0.791840, -146.721130, 2.947540, 0.091720, 0.538890, -3.333590, 3.094420,
-0.114980, 1.408690, 0.431530, 1.604560, 0.488670, 0.684790, -0.581300, -0.698810, 0.308180, 1.286560,
-0.757650, -0.705000, -0.777220, 6.014750, -731.047913, 5.094600, -1.340240, -0.022310, -0.438600, 1.915040,
-0.924800, -0.271230, -0.392260, -0.802500, 0.337310, 0.382670, -0.357360, -3.475620, -0.257690, -0.135650,
-0.618720, -0.759930, -0.733380, 5.159320, -0.386910, 0.616360, -6.800080, 2.799260, -0.164130, 3.530500,

-0.061260, -0.404250, 0.618710, -0.906250, -0.160620, 0.308700, -1.183860, 1.007610, -0.930200, 0.128380,
-3.337100, -0.426430, 0.247550, -0.140740, 0.343170, -0.263770, 0.989900, 0.503170, -0.033400, -1.555130,
1.150250, -0.236860, -1.094430, 0.155260, -0.844120, -0.971320, 0.860940, 0.095740, -0.211240, -0.215720,
0.911880, 0.103640, 0.937610, 1.850200, -0.624560, 0.746240, -0.797140, 1.989240, -0.476360, 2.957870,
-0.823200, 0.086460, 0.390480, 0.246200, -0.382380, -0.582940, -0.481730, -0.770990, 0.574940, -0.028360,
0.566150, 0.987650, 0.073860, 0.190250, 0.149220, 0.258630, 2.050150, -11.521020, -0.681740, -0.169240,

39.820400, 40.079571, 39.503922, 0.559880, 39.893650, -0.193910, 40.014679, 39.098412, 39.201351, 39.952919,
39.539021, 38.901409, 39.246040, 39.344299, 40.075840, 39.838570, 39.373589, 39.199600, 39.818588, 0.321580,
39.723042, 39.586399, 39.403339, 0.730140, 39.127670, 39.032711, 38.336590, 39.170479, 39.488682, 38.686409,
38.503510, 39.799992, 39.801559, 40.279320, 39.025532, 38.414478, 39.314980, 38.459469, -13.368740, 39.283859,
39.521271, 39.452400, 39.585701, 38.760399, 39.064892, 38.518169, 39.539360, 14.576030, 38.926949, 39.414841,
40.259209, 39.163990, 40.086060, 39.786510, 39.299160, 13.447480, 38.422138, 0.314160, 39.583858, 14.035990,

-0.256480, -0.657040, -0.674360, 0.642540, -0.386100, -0.778310, 0.115370, -0.436510, -0.413870, -0.152640,
0.438870, 0.726800, 0.880240, -0.294780, -0.350460, 0.269550, 0.145720, 1.417570, -0.093200, -0.574140,
0.462640, 0.523630, -0.955530, 0.478320, -0.054240, -0.178570, -0.703250, -0.442570, 0.890000, 0.023240,
-0.497010, -0.075190, 0.856840, -2.275470, 3.144900, 0.584350, -0.026720, 1.745570, -1.468220, 0.512810,
-0.355110, -0.618140, -0.585000, -0.200500, -0.485300, -1.051700, -0.353650, 0.544210, -43.977310, 0.042790,
-0.140310, -0.415240, -0.881640, -0.398760, -0.658550, 0.686920, 0.638230, -0.777730, -0.826110, -24.077971,

-0.215870, 0.834380, -1.693220, -0.372770, 0.842580, 0.747100, -1.972910, -2.177000, -0.934420, 0.568360,
-0.194640, -0.245010, -0.452610, -0.041180, -2.332310, -3.542280, -0.164930, -0.369480, 1.149250, -0.942810,
-0.144500, -1.566010, 0.165510, 0.931340, -0.701350, -0.688680, -1.549420, 1.405670, 0.086140, -3.385750,
0.273170, -0.687070, 0.099950, -1.467920, 2.304720, 0.406360, -0.306630, -2.812120, 0.384240, 0.337390,
0.201440, -0.643470, 0.129280, -0.431240, 0.793820, -0.095890, -0.713300, 1.039360, -2.889580, -0.427160,
0.830160, -0.871880, -0.648330, 0.338200, 0.339890, 0.320340, -0.378140, 0.511210, -0.676320, -0.170000,

0.458800, 0.188300, -1.120440, -0.718560, 0.790990, -2.630960, -2.295790, 0.042150, 0.299620, 0.047650,
0.277240, -0.726220, -5.810540, 0.622640, -3.038260, -0.454580, 1.439180, 0.438410, 0.276600, 1.484180,
-2.075690, 0.393970, 0.689070, -0.488600, -1.462280, -0.924280, -1.220870, 1.190550, 0.288330, -0.153790,
0.055930, 0.700270, -0.627660, -1.837860, -14.618850, 1.487970, 0.366520, -4.153190, -1.339430, 0.422410,
0.643340, -0.738950, -0.114290, 0.764860, -0.400890, 0.524120, -0.284200, -0.321880, -0.341150, -0.750080,
-1.062170, 0.140060, -0.683410, -6.694660, -0.506520, -0.825640, 0.514800, 0.397840, -0.360460, 3.146890,

-0.231810, 0.767940, -0.215960, 1.097660, 0.021430, 0.025770, 0.779090, -0.200490, -0.255820, 0.222740,
0.057340, 0.207770, -0.893730, -0.010670, -0.833110, -0.611310, 0.655620, -0.111470, -0.712960, -0.395400,
0.104480, 0.520910, 0.290400, 0.268620, 0.128350, -0.406210, -0.148260, -0.458040, -0.765110, 0.013070,
-0.000580, -0.288720, 0.070210, -0.814910, -2.064730, -1.632260, -0.233640, -0.601840, -2.752610, 0.983940,
-0.233680, -1.890680, -0.652960, 1.064350, 1.799990, -0.388680, -0.708700, 0.482700, -1.705430, -0.295960,
-0.763800, 0.616420, 0.939540, -3.060740, 3.070240, 0.903380, -1.176860, 0.684210, 0.665390, 0.036720,

0.964940, 0.060600, 0.450290, -1.275200, -0.329020, 0.177190, -0.252840, 0.126380, -0.379720, -0.069980,
0.448360, -0.021250, 0.766150, 0.053670, 1.818100, -1.097000, 0.179270, 2.421780, 0.668520, -0.888020,
-0.463940, 0.712630, 0.524370, -1.020630, -2.365260, -0.260700, -1.387850, 0.768060, -1.197090, 0.317040,
-0.819640, -0.734640, -0.708790, -1.206840, -4.680720, 0.854790, 0.719720, 0.674770, -0.452440, -1.624500,
-0.611730, -0.029250, -0.772310, -0.889880, -0.671520, -0.598290, 0.472600, 0.410700, 1.579160, 0.270500,
-0.004530, -0.475990, -0.467380, 4.309130, -0.530120, -0.320570, 0.507500, -1.656730, -0.312020, -3.622670,

-0.218300, 0.598960, -0.234730, 0.557720, 0.878160, 0.231930, 0.477450, -0.866390, 0.142530, 0.588620,
0.935630, -0.703820, 0.165660, 0.377350, -1.176870, 0.635590, -0.298360, -0.114760, -0.501060, 0.042890,
0.577750, 0.089260, 1.004740, 0.390040, -0.866270, 0.843840, -0.381250, -0.199000, -0.491100, 0.574470,
0.734250, -0.559560, -0.533120, -0.922320, -1.094530, 0.167740, -0.317920, -0.204150, -0.151780, 0.156000,
0.599630, 0.194730, -0.845610, -0.421730, 0.936670, 0.061910, -0.619640, -0.226770, 0.147460, 0.398760,
0.018730, -0.323940, -0.929290, -2.128200, 0.991210, -0.688520, 1.526310, -0.315480, -0.690770, -0.225410,

0.510430, 1.029120, 0.342370, 0.805490, -0.519930, 0.443830, 0.907830, 0.437140, 0.379430, -0.359040,
0.139900, 0.908880, 0.809580, 0.206960, 0.096880, 0.385080, -0.160810, -0.156980, 0.447800, 0.281730,
0.336600, -0.044220, 0.096490, -0.193960, 1.039430, 0.879810, 0.308690, 0.255130, -0.345440, 0.827620,
-0.345850, -2.111190, -0.314300, 2.096620, -1.151280, 0.915860, -0.753230, 0.992480, 3.725500, 4.523020,
-0.129340, -1.038340, -0.638630, 1.088020, 0.714800, 0.173400, -0.245350, 0.207640, 1.832760, -0.734210,
-0.724400, 0.774530, 0.464390, 0.350190, -0.654600, 0.397130, -0.573960, 0.863950, -0.258780, 1.933600,

-0.855210, -0.825290, -0.651010, 0.573490, 0.694380, 0.224340, -0.646480, 0.057010, 0.901740, 0.878950,
-0.897430, -1.130680, -0.296040, 0.943770, -0.892180, -1.640920, -1.004110, 0.910640, -0.139320, 0.363450,
-1.017220, -1.034990, -0.194700, 0.755070, 0.450910, -0.186980, -0.894780, 0.109550, 0.126750, 0.745420,
0.866770, -0.329230, -0.700180, 0.241800, -0.732510, -0.493350, -0.314930, 0.383390, 1.073940, 0.143320,
0.528140, -0.531460, 0.864430, 0.417470, -0.083750, 0.186350, 0.034290, -0.663800, -0.538250, 0.840040,
-0.432850, -0.586630, 0.257960, -0.214020, 0.858130, 0.256260, -0.041040, 1.604150, -0.236780, -0.138320,

0.324390, -0.485160, -0.836470, 0.015390, -0.777550, 0.429490, -2.303470, 0.528390, -0.336350, -0.097990,
0.602630, 0.968030, -1.560650, 1.047010, 2.409130, 0.799620, 0.405470, -0.282170, 0.348180, -1.131970,
-1.609940, 0.603100, -0.037740, -0.640270, -0.943750, 1.364630, 0.520300, 1.149140, 0.011570, 0.819550,
-0.260740, 1.749810, -0.487240, 1.167840, 1.977370, -0.214340, 0.677110, 0.089840, -0.850980, -1.074050,
-0.476480, 1.684710, 0.293530, -0.919030, -0.172780, 1.683640, 0.727920, -0.504110, 1.657910, -0.912990,
-0.859580, 0.236520, -0.210210, -1.509370, -0.781940, -0.624180, 1.195220, 0.598460, -0.919080, 4.310580,

0.895960, 0.526710, -0.972810, 0.577700, -0.339090, -0.111490, 0.049750, 0.088670, -0.959230, 0.058050,
-0.829750, -0.632910, -0.135260, 0.628190, 1.279240, -0.859370, 0.970420, -0.346130, 0.410320, -0.085990,
0.753970, -0.477680, -1.015520, -0.450690, 0.034950, 0.055220, 0.990560, 0.276430, -0.199900, 0.478050,
-0.833470, 1.907970, 0.772780, -3.450260, 4.154970, -0.691830, 0.171160, 0.317380, -0.860040, -3.588280,
-1.002060, -0.792980, -0.043900, 0.671520, 0.424120, -0.282550, -0.038210, -0.392210, 0.004310, -0.254270,
-0.343720, 0.815150, -0.197820, -3.879430, 0.347900, 0.209080, -0.443990, -0.306790, -0.046230, 0.274790,

-0.240370, 0.099880, 0.399850, -1.196850, -0.916060, 0.119940, -0.130670, -0.814630, -0.597850, -2.096490,
0.379320, 0.405810, -0.100340, -0.793490, -0.393700, 0.121760, 0.175990, -0.478530, -0.480930, -0.955970,
1.089810, 0.633210, -1.546650, -0.472080, 0.896350, -0.926270, -0.159970, -0.344530, 0.992980, 0.316110,
-0.999500, -0.663860, 0.042030, 1.715850, 2.296920, 0.075210, -0.748930, -0.132680, -5.718050, -4.371440,
1.007720, 1.997820, -0.389580, 0.967960, -1.105570, 0.021440, 0.515280, 0.405410, -0.248860, 0.694910,
-0.601920, -0.162410, 0.804720, 4.008280, -0.996770, 0.839240, 1.029840, -2.082350, 0.682560, -0.367010,

-0.227540, -0.404740, -0.294390, 0.119750, -0.154190, -0.575260, 1.052130, 1.155380, -1.033230, 0.849220,
0.004960, -1.352010, 0.049390, 0.517260, 0.061750, -1.240960, -0.288280, 0.327910, -1.666790, -0.604680,
0.035020, -1.601410, -1.080340, -0.052880, -0.267220, 0.143610, -0.065050, -0.654160, -0.419810, 0.992990,
-0.704000, 2.380580, -0.225690, 0.869060, 2.064100, 0.937200, 0.458230, -6.596970, -6.088290, 1.055740,
-0.283370, -2.578250, -0.345350, -0.120490, 0.215050, 0.257500, 0.748180, -0.744720, 0.240810, 0.107010,
0.197690, -1.066680, 0.740760, 2.990220, -0.114140, -0.563500, 1.453940, -1.993500, -0.074720, 1.310700,

0.446040, 0.102940, 0.474740, -0.520240, -0.942320, -0.749310, 0.088510, 1.274320, -0.972710, -0.125640,
0.291880, 0.700110, 0.344210, -0.428990, 1.211700, 1.765260, 0.429580, -0.609240, 0.824300, -0.719020,
0.308730, 0.878590, 0.829340, -0.734950, 0.653220, 2.400890, 0.995320, -0.273360, -0.574540, 0.827550,
0.783940, -0.142620, -0.483600, 0.742980, 0.900840, -0.159450, -0.890450, 1.005060, -0.481370, -0.687440,
0.560290, 0.141300, -0.219400, 0.817940, -0.472850, 0.659820, 1.000820, 1.200160, -0.770720, 0.769350,
0.087950, -0.643230, -0.017030, 0.835730, 0.402710, -0.551590, 0.890230, -0.949910, 0.415840, -0.612770,

0.981510, 0.468880, -0.328740, 0.164520, 0.109200, 0.468830, -0.904650, 1.369670, 0.249630, 0.808880,
-0.414630, -0.478750, 0.233470, 1.305050, 0.705910, 0.122290, -0.369550, -0.163330, -0.393300, 1.104460,
0.480170, -0.283480, 0.285190, 0.582720, -0.093190, 1.154750, 0.267170, 1.368110, -0.826400, 0.289130,
1.001290, 0.115560, 0.499920, 2.955890, -2.039270, -0.135320, -0.118870, -0.279100, -3.069570, -0.569800,
-0.107080, 0.173000, 0.332280, -0.527070, 0.011350, 0.699690, 0.769010, -0.432630, 0.929480, -0.173590,
0.621960, 0.282690, 0.680790, 0.226980, 0.300600, 0.422930, -0.631360, -0.644880, -0.492300, 1.816830,

0.669630, 1.598860, 2.959160, -0.292790, -0.178990, -0.529460, 0.688590, 1.273550, -0.695450, -0.318190,
0.539960, 0.728670, 0.056710, -0.024950, -0.290010, 0.088370, -0.328130, -1.080130, 0.746630, -0.518870,
1.768170, 0.722980, 0.119380, 0.264700, 0.888620, 1.980960, 0.767410, -0.901810, 0.255300, 5.889250,
0.693280, -3.000480, 0.029870, 1.227740, -2.770470, -0.747110, 0.329330, 3.035430, -3.706590, -0.041510,
-0.361910, 0.258230, 0.649640, -0.745360, -0.467270, -1.594390, -0.081230, 0.764610, 1.567380, -0.787190,
0.569080, 0.121480, 0.141660, -4.501420, -0.640340, 0.520560, 252.095886, 3.234240, 0.757620, -2.370950,

0.127940, 0.073100, 0.717130, -0.535050, 0.079570, 0.300330, 0.619340, 0.867490, 0.643350, -0.360490,
-0.477230, 0.255490, 0.512680, -0.720130, 0.802520, 0.227790, 0.737820, -0.606960, 0.736330, -0.127350,
-0.479570, 0.923260, -0.321950, -0.230560, 0.653800, 0.446990, 0.490870, -0.012270, -0.539610, 0.633320,
-0.277050, 0.008650, -0.192800, -0.772620, 0.444280, 0.274290, -0.488480, -0.224410, -0.582980, -0.618310,
-0.006270, 1.204030, 0.081720, -0.455160, 0.902400, 0.862390, 0.770030, 0.060270, 0.205000, -0.316500,
-0.581450, -0.674650, -0.714780, -0.316820, -0.521360, 0.566240, -1.113760, 0.868480, 1.057850, -0.329100,

-1.375620, 0.570880, 0.419920, 0.520890, 0.170290, -0.596040, 0.928730, -0.072560, 0.343370, 0.390900,
-0.564870, -0.023790, 0.453950, -0.996660, -0.085770, -0.471150, 1.571500, 0.188770, 0.493190, -0.356780,
0.333880, -1.134680, -0.253790, 0.488180, -0.389250, -2.736960, -144.081650, -0.217160, -0.506150, -1.134950,
0.561560, -0.112520, 0.740720, -0.843690, -634.336548, -1.607550, -0.839950, -0.447900, -0.913000, 2.627890,
-0.768740, 0.743350, -0.138940, 0.034040, -0.003210, -5.332690, -0.457730, 0.025780, 2.538260, -0.882820,
-0.022310, -0.528780, 0.779240, -0.719070, -1.013120, 1.101310, 0.268040, -1.042650, -0.952430, -3.202920,

-0.167610, -0.736410, -0.751330, 0.231270, -0.353290, 0.548880, 0.173040, -0.402800, -0.274730, -0.627640,
0.662390, 0.136550, -0.696280, 0.100580, -0.747560, -0.292870, -0.432300, 0.843070, -0.393460, 0.514720,
-0.130800, 0.017770, -0.301170, 0.425560, -0.959030, -0.645110, -1.601380, -0.506480, 0.090050, 0.490950,
0.943350, -0.444570, 0.864310, -0.180310, 2.019530, -0.586550, 0.452470, 0.811730, -0.201260, 2.059350,
0.524530, 0.392510, 0.449480, -0.374600, 0.123870, 0.251460, 0.061140, -0.186640, 0.358020, -0.890460,
-0.773330, -0.608840, 0.361180, 0.851120, -1.022450, 0.052430, 0.026150, 0.822840, -0.269910, 0.037080,

-0.754600, 1.617520, -0.260820, -0.200530, -0.665260, -2.065160, -0.521770, 0.737940, -0.327630, -0.911590,
-1.015270, 0.992890, -0.121080, 0.140170, -0.331420, -0.752810, -0.199940, -0.554160, 0.520270, -0.482700,
1.024100, 0.760940, -0.864140, -0.526220, -0.204050, -1.496480, -0.058620, -0.431100, 0.226280, -0.208950,
1.486740, 0.780970, 0.456120, 1.480770, 2.208510, -0.448250, -0.225330, -0.041700, -3.123390, 0.202690,
0.849980, 1.095450, -1.363040, 1.181860, 0.387680, -0.769540, 0.619470, 1.389450, -0.083130, 0.229670,
-0.596560, -0.042810, 0.053900, 0.367520, -0.487590, 1.165010, 1.632180, -0.197290, -0.194840, 0.121230,

-77.167671, 0.580150, -0.232590, -0.556390, -0.411760, -1.688200, 0.311660, 0.466270, 0.165810, -0.086710,
0.101190, 1.251850, -0.815580, -0.988440, 1.794170, -1.423180, -164.709000, -1.265110, -0.578010, -0.545920,
1.154000, -0.637280, -0.797850, 0.342720, -0.087070, -1.958650, 1.572930, -3.378940, -0.165980, -6.756290,
0.529300, -0.589170, 0.588670, -1.543390, 3.206350, -0.853670, -0.502380, -0.056760, 0.805730, 2.096160,
0.075000, 0.641810, -0.994710, 0.084670, -0.748800, 1.580420, -0.050930, 0.291680, 0.112110, -0.301000,
0.425410, 0.539040, -0.015310, 0.594240, 0.872710, -0.380230, -2.038950, -0.898860, 0.416630, 2.856950,

-0.198360, 1.905280, 3.259540, -0.588080, 1.166400, -0.676210, -1.571080, -0.595330, 0.367040, 1.036540,
-1.187980, 0.125750, 0.507730, 0.322700, -0.744300, 0.009380, 0.179200, 0.720890, -0.190100, -11.039280,
-128.490677, -0.217040, -0.404310, -0.988030, -3.282260, 0.915960, -0.306500, 1.046700, 0.497310, -0.735470,
0.270640, -6.160500, -0.256150, 0.913960, -395.087036, -0.536970, 0.771750, -3.278950, 2.797810, -2.003400,
-0.776910, 1.058250, -0.636720, -0.904550, 0.087670, 0.701270, -0.311350, -1.068990, 0.120020, -0.946430,
-0.615720, -0.701990, -1.079370, -0.233220, 0.279910, 0.937110, -4.762760, 0.871030, 0.884540, -4.511380,

0.540850, -0.183140, 0.140740, -0.684010, -0.204640, -0.661920, -0.552380, 0.444880, -0.805090, 0.025720,
-0.057470, 0.703140, 0.292800, -0.610560, 0.568770, 1.439470, 0.370890, -0.306110, 0.604720, -1.073040,
0.327820, 0.870560, -0.137050, -0.798610, -0.227240, 1.866170, 0.512660, -0.437130, -0.052630, 0.409520,
0.848600, 0.435700, -0.054900, 0.413980, 0.072060, 0.086790, -0.572590, 0.293810, -1.417780, -0.593970,
0.401330, 0.135270, 0.831070, 0.287860, 0.009650, 0.512770, 0.853530, 1.622350, 0.490200, 0.752780,
0.190420, 0.390260, -0.459710, 0.681320, -0.570080, 0.045610, -0.200280, -0.211600, 0.278150, -1.067060,

0.047760, 0.450480, 0.210160, -0.947590, 0.142310, 0.230990, 0.408410, -0.741050, -0.454900, 1.031380,
0.447020, 0.300370, -0.053000, -0.251160, -0.388150, -0.855270, -0.181210, -0.654930, -0.512560, -0.251460,
-0.996150, -0.731080, 0.513060, -0.205080, 0.058020, -0.098850, 0.034270, 0.474470, -2.430860, 0.151350,
1.112610, 0.016210, -0.338930, 0.780390, 0.050930, -1.012460, -0.333810, -1.871140, -0.617490, 2.882850,
-0.117180, -2.314760, 0.200470, 0.524640, 0.134300, 1.163650, -0.082060, 0.838260, 0.131280, -0.302090,
0.466230, -0.959310, -0.902920, -4.018040, 0.641680, 0.357070, 0.810800, -4.460670, -0.967490, -0.899020,

-0.287290, 2.302830, 0.680120, 1.400280, 0.342500, 0.786390, 0.309660, -0.467580, -6.490610, -0.528400,
1.014300, -0.043710, -0.613120, 0.741860, -0.663310, -0.120560, -0.145530, 0.906540, 7.520510, 0.906630,
1.235930, -0.343340, 0.995830, 1.537780, -0.173370, 0.322130, 1.597100, -3.615400, -0.322920, 3.863720,

-0.059520, 2.824290, 0.179780, 1.348440, 0.911710, 0.898050, 0.651910, 0.350870, -5.953300, -0.788790,
0.762580, 0.062420, 0.281020, 0.100820, -0.122210, 0.415810, 0.463510, 1.337340, 5.303390, 0.436930,
0.276420, -0.032060, 1.355890, 1.397980, -0.420130, 0.095200, 1.883540, -3.777420, 0.764920, 3.207570,

-0.001580, 2.605990, 0.330330, 1.207790, 1.156330, 1.666870, 0.752020, 0.619280, -5.464250, -0.664250,
-0.173860, 0.655790, -0.217000, 0.483180, -0.553230, 0.573710, -0.104900, 1.076950, 3.634010, 0.550220,
-0.010990, 0.797890, 1.002520, 1.325270, -0.516700, 0.134720, 1.163910, -3.631890, 0.380740, 2.989560,

-0.002330, 1.934740, 0.030100, 0.918950, 1.632500, 2.181650, 0.761960, 1.174650, -5.395190, -1.200500,
-0.195160, 1.439880, 0.709480, 0.331170, -0.165330, 0.673420, 0.773350, 1.308450, 2.014050, 1.164600,
-0.242670, 0.394410, 1.160750, 1.687510, -0.152060, 0.255540, 1.468120, -3.561080, 0.339700, 2.486800,

0.305670, 1.499960, 0.782620, 1.318640, 1.995140, 1.657500, 0.251980, 1.038370, -5.390710, -1.233580,
0.642780, 1.598830, 0.190440, 0.648310, -0.335110, 1.180840, 0.715500, 1.219360, 1.421860, 0.739520,
-0.801890, 0.278680, 1.047440, 1.567230, -0.715840, 0.608770, 1.244060, -3.796560, 0.451320, 2.633290,

0.326260, 1.611330, -0.024940, 1.360710, 2.588800, 1.244870, -0.071190, 0.879030, -5.192150, -1.656570,
0.159920, 1.644990, -0.566450, -0.172170, -0.444660, 0.823930, 0.896070, 0.599970, 0.876800, 1.087420,
-0.639570, 1.092220, 0.706570, 1.899820, -0.301310, 0.461780, 1.528800, -3.406180, 0.237710, 2.639880,

0.084480, 1.533510, 0.539360, 1.408640, 2.997290, 1.692800, 0.844800, 0.902380, -5.294050, -1.845080,
0.040290, 1.323470, -0.038270, -0.979910, -0.874550, 1.083190, 0.315920, 0.988430, 0.776920, 0.888990,
-0.265640, 0.600680, 0.774370, 1.724430, -0.661390, 0.440580, 1.553380, -3.592920, 0.055500, 2.423180,

0.290420, 1.243230, -0.520320, 1.459770, 2.692580, 1.859520, 0.970230, 0.972740, -5.219670, -1.851770,
0.652600, 1.488950, -0.259010, 0.368240, -0.864560, 1.117920, 0.161900, 0.646540, 0.530080, 0.599720,
-0.347570, 0.416820, 0.369700, 1.419860, -0.795670, 0.304870, 1.912870, -3.326980, 0.384600, 2.503380,

0.105150, 1.206130, 0.005420, 1.562370, 2.195590, 1.555700, 0.261840, 0.859010, -4.957810, -1.799010,
-0.551400, 1.210210, -0.181920, 0.430010, -0.633600, 0.961390, 0.481300, 0.865870, 0.163990, 0.409000,
0.348390, 0.333550, 0.660690, 1.679010, -0.674520, 0.483540, 2.176610, -3.226570, 0.552230, 2.667870,

0.000890, 1.199870, 0.006770, 1.385890, 1.811780, 1.734840, 0.649510, 0.340870, -5.090870, -2.085540,
0.568970, 1.195300, -0.457700, 0.230870, -0.930850, 1.163530, -0.093020, 0.741790, 0.102900, 0.205430,
0.014780, 0.620130, 0.222270, 1.538170, -1.071890, 0.421170, 1.675160, -3.303000, 0.462210, 2.721780,

0.046760, 1.074200, -0.114270, 1.406310, 1.726070, 1.614250, 0.637210, 0.833130, -4.776090, -2.010070,
0.324950, 1.251230, -0.404330, 0.068730, -1.128520, 1.049110, -0.000160, 0.710460, -0.169230, 0.939800,
-0.124760, -0.138380, 0.080470, 1.522230, -1.063850, 0.476780, 1.809400, -3.205080, -0.412080, 2.667430,

-0.519020, 1.019460, -0.228450, 1.029340, 1.567740, 1.695660, -0.435990, 0.882940, -4.736630, -2.162970,
0.691270, 1.098320, -0.194090, 0.561650, -0.627280, 0.958130, 0.079670, 0.905910, -0.364620, 0.681770,
-0.115920, -0.687180, 0.355700, 1.809680, -0.848480, 0.411720, 1.989640, -2.938850, 0.137270, 2.394200,

-0.720690, 1.100960, 0.037660, 1.128110, 1.209450, 1.562050, 0.819810, 0.679930, -4.319440, -2.069420,
-0.689600, 1.042150, -0.339570, 0.562590, -0.556440, 0.785530, 0.216600, 0.831950, -0.687820, 0.949700,
-0.887570, 0.649460, 0.380010, 1.696140, -0.660110, 0.521430, 2.045180, -2.702160, -0.174280, 2.358250,

-0.656360, 0.810130, 0.204300, 1.043460, 1.075110, 1.470360, -0.242070, 1.219890, -3.974340, -2.068460,
0.011970, 0.950800, -0.314270, 0.497530, -0.693620, 0.676310, 0.299630, 0.909900, -0.730130, 0.810600,
0.113320, -0.330260, 0.500490, 1.912770, -0.824960, 0.563360, 2.068350, -2.608960, -0.122200, 1.931220,

-0.304340, 0.665920, 0.094290, 1.059450, 0.962630, 1.265020, 0.279370, 1.069290, -4.512630, -1.944340,
-0.139100, 0.822330, -0.447260, -0.163860, -1.009560, 0.742400, 0.297350, 0.802050, -0.952530, 0.168830,
-0.025150, -0.589560, 0.309800, 1.459030, -1.162740, 0.695100, 1.618260, -2.206100, 0.051290, 1.804740,

-0.641750, 0.673070, -0.350040, 0.772020, 1.013800, 1.124810, -0.857840, 1.286780, -4.309520, -2.106160,
0.266560, 0.868800, -0.703670, 0.632260, -0.794580, 0.536860, 0.190410, 0.656650, -0.831310, -0.435750,
-0.344240, 0.325800, 0.220780, 1.338940, -1.015820, 0.543870, 1.590410, -2.356660, 0.784330, 1.608660,

-0.473340, 0.315050, -0.496820, 0.597890, 1.043090, 1.140730, -0.088990, 1.724810, -3.309650, -2.181440,
-0.194410, 0.699730, -0.605930, -0.687400, -0.644760, 0.447220, 0.331740, 0.681920, -1.274620, 0.794810,
0.144800, -0.130000, -0.011480, 2.129860, -0.875140, 0.452990, 1.544310, -2.092420, 0.476650, 0.967710,

-0.592830, 0.344940, -0.606820, 0.643320, 1.133330, 0.965300, 0.296490, 1.383270, -3.621390, -2.074500,
-0.289160, 0.725370, -1.037480, -0.222320, -0.815850, 0.277310, 0.319820, 0.424770, -1.147880, 0.438530,
-0.937640, 0.550620, -0.522230, 1.658020, -0.935290, 0.375170, 1.217390, -2.008110, 0.647850, 0.864280,

-0.591330, 0.152390, -0.575040, 0.660590, 0.905960, 1.029260, 0.023790, 1.471760, -3.540720, -1.853350,
-0.187320, 0.763640, -0.970660, 0.764730, -0.704960, 0.213980, 0.467790, 0.531670, -1.117080, 0.405410,
-0.749690, -0.556510, -0.833570, 1.669420, -1.011940, 0.396100, 1.080110, -1.543650, 0.801200, 0.178230,

-0.898890, 0.024340, 0.138520, 0.577140, 0.915620, 0.858060, 0.123180, 2.527680, -2.086780, -1.487140,
-0.761290, 0.563280, -0.497320, -0.824730, -0.558950, 0.116540, 0.691480, 0.706770, -0.782380, 0.850410,
0.313110, -0.586860, 0.267270, 1.321930, -0.984000, 0.773930, 0.769210, -1.319280, -0.459060, -0.763810,

1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
1.000000, 0.300000,
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
      0.0, 0.453290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 2 (inp2) */
      0.0, 0.647470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 3 (inp3) */
      0.0, -0.085390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 4 (inp4) */
      0.0, -0.179790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 5 (inp5) */
      0.0, -0.060200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 6 (inp6) */
      0.0, 0.226590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 7 (inp7) */
      0.0, 0.090950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 8 (inp8) */
      0.0, 0.518400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 9 (inp9) */
      0.0, -0.577270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 10 (inp10) */
      0.0, -0.177780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 11 (inp11) */
      0.0, 0.676800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 12 (inp12) */
      0.0, 0.073860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 13 (inp13) */
      0.0, -0.968090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 14 (inp14) */
      0.0, 0.806020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 15 (inp15) */
      0.0, 0.857140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 16 (inp16) */
      0.0, 0.219870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 17 (inp17) */
      0.0, 0.611270, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 18 (inp18) */
      0.0, 0.914810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 19 (inp19) */
      0.0, 0.126880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 20 (inp20) */
      0.0, 0.169090, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 21 (inp21) */
      0.0, 0.386810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 22 (inp22) */
      0.0, -0.098040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 23 (inp23) */
      0.0, -0.610500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 24 (inp24) */
      0.0, 0.782290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 25 (inp25) */
      0.0, 0.936790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 26 (inp26) */
      0.0, 0.113570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 27 (inp27) */
      0.0, -0.055200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 28 (inp28) */
      0.0, -0.934300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 29 (inp29) */
      0.0, -0.148400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 30 (inp30) */
      0.0, 0.895240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 31 (inp31) */
      0.0, -0.447930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 32 (inp32) */
      0.0, -0.550930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 33 (inp33) */
      0.0, -0.148020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 34 (inp34) */
      0.0, 0.798440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 35 (inp35) */
      0.0, 0.725060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 36 (inp36) */
      0.0, 0.848100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 37 (inp37) */
      0.0, 0.923010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 38 (inp38) */
      0.0, 0.912800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 39 (inp39) */
      0.0, -0.079040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 40 (inp40) */
      0.0, 0.803520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 41 (inp41) */
      0.0, 0.279000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 42 (inp42) */
      0.0, 0.900480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 43 (inp43) */
      0.0, -0.315010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 44 (inp44) */
      0.0, -0.024700, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 45 (inp45) */
      0.0, -0.770390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 46 (inp46) */
      0.0, -0.855350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 47 (inp47) */
      0.0, -0.319030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 48 (inp48) */
      0.0, -0.244970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 49 (inp49) */
      0.0, 0.769360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 50 (inp50) */
      0.0, 0.134350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 51 (inp51) */
      0.0, -0.827930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 52 (inp52) */
      0.0, -0.109230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 53 (inp53) */
      0.0, -0.073340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 54 (inp54) */
      0.0, -0.828820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 55 (inp55) */
      0.0, 0.427240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 56 (inp56) */
      0.0, -0.214230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 57 (inp57) */
      0.0, 0.521040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 58 (inp58) */
      0.0, 0.676630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 59 (inp59) */
      0.0, -0.048660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 60 (inp60) */
      0.0, 0.869190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 61 (inp61) */
      0.0, 0.392570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 62 (inp62) */
      0.0, -0.131370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 63 (inp63) */
      0.0, 0.821060, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 64 (inp64) */
      0.0, 0.322500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 65 (inp65) */
      0.0, 0.758200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 66 (inp66) */
      0.0, 0.025030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 67 (inp67) */
      0.0, 0.924400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 68 (inp68) */
      0.0, -0.001030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 69 (inp69) */
      0.0, 0.957830, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 70 (inp70) */
      0.0, -0.283100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 71 (inp71) */
      0.0, -0.062260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 72 (inp72) */
      0.0, 0.962970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 73 (inp73) */
      0.0, 0.289540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 74 (inp74) */
      0.0, -0.376800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 75 (inp75) */
      0.0, 0.538660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 76 (inp76) */
      0.0, 0.407810, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 77 (inp77) */
      0.0, 0.176750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 78 (inp78) */
      0.0, 0.276660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 79 (inp79) */
      0.0, 0.970330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 80 (inp80) */
      0.0, 0.339530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 81 (inp81) */
      0.0, -0.191080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 82 (inp82) */
      0.0, -0.627120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 83 (inp83) */
      0.0, 0.690490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 84 (inp84) */
      0.0, 0.235740, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 85 (inp85) */
      0.0, 0.368840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 86 (inp86) */
      0.0, 0.234250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 87 (inp87) */
      0.0, -0.282780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 88 (inp88) */
      0.0, -0.357600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 89 (inp89) */
      0.0, 0.687840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 90 (inp90) */
      0.0, 0.379730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 91 (inp91) */
      0.0, -0.591620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 92 (inp92) */
      0.0, 0.443380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 93 (inp93) */
      0.0, -0.188730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 94 (inp94) */
      0.0, -0.269530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 95 (inp95) */
      0.0, -0.017940, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 96 (inp96) */
      0.0, -0.746890, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 97 (inp97) */
      0.0, -0.367600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 98 (inp98) */
      0.0, 0.191390, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 99 (inp99) */
      0.0, 0.022030, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 100 (inp100) */
      0.0, 0.315260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 101 (inp101) */
      0.0, 0.055310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 102 (inp102) */
      0.0, -0.303990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 103 (inp103) */
      0.0, 0.653880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 104 (inp104) */
      0.0, -0.446280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 105 (inp105) */
      0.0, 0.637470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 106 (inp106) */
      0.0, 0.385790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 107 (inp107) */
      0.0, -0.119120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 108 (inp108) */
      0.0, 0.476520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 109 (inp109) */
      0.0, 0.369310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 110 (inp110) */
      0.0, 0.608920, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 111 (inp111) */
      0.0, 0.810820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 112 (inp112) */
      0.0, -0.219960, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 113 (inp113) */
      0.0, 0.169460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 114 (inp114) */
      0.0, -0.345010, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 115 (inp115) */
      0.0, 0.980300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 116 (inp116) */
      0.0, -0.611780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 117 (inp117) */
      0.0, 0.277290, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 118 (inp118) */
      0.0, -0.529220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 119 (inp119) */
      0.0, -0.295000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 120 (inp120) */
      0.0, -0.222400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 121 (inp121) */
      0.0, 0.444200, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 122 (inp122) */
      0.0, 0.504260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 123 (inp123) */
      0.0, 0.086380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 124 (inp124) */
      0.0, 0.620040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 125 (inp125) */
      0.0, -0.433330, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 126 (inp126) */
      0.0, 0.866670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 127 (inp127) */
      0.0, -0.062980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 128 (inp128) */
      0.0, 0.696550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 129 (inp129) */
      0.0, -0.960420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 130 (inp130) */
      0.0, 0.348450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 131 (inp131) */
      0.0, -0.880240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 132 (inp132) */
      0.0, 0.721150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 133 (inp133) */
      0.0, 0.980340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 134 (inp134) */
      0.0, -0.270590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 135 (inp135) */
      0.0, 0.517230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 136 (inp136) */
      0.0, 0.027130, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 137 (inp137) */
      0.0, 0.893250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 138 (inp138) */
      0.0, 0.137080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 139 (inp139) */
      0.0, -0.333170, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 140 (inp140) */
      0.0, -0.781590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 141 (inp141) */
      0.0, 0.087730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 142 (inp142) */
      0.0, -0.127500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 143 (inp143) */
      0.0, -0.162750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 144 (inp144) */
      0.0, -0.070020, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 145 (inp145) */
      0.0, 0.983690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 146 (inp146) */
      0.0, -0.323190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 147 (inp147) */
      0.0, 0.531150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 148 (inp148) */
      0.0, -0.831850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 149 (inp149) */
      0.0, -0.453840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 150 (inp150) */
      0.0, -0.513360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 151 (inp151) */
      0.0, 0.838730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 152 (inp152) */
      0.0, -0.444310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 153 (inp153) */
      0.0, 0.678320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 154 (inp154) */
      0.0, 0.544600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 155 (inp155) */
      0.0, 0.220690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 156 (inp156) */
      0.0, 0.771280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 157 (inp157) */
      0.0, -0.881800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 158 (inp158) */
      0.0, 0.613190, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 159 (inp159) */
      0.0, -0.132440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 160 (inp160) */
      0.0, -0.023910, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 161 (inp161) */
      0.0, -0.144280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 162 (inp162) */
      0.0, 0.896780, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 163 (inp163) */
      0.0, -0.813870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 164 (inp164) */
      0.0, -0.166710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 165 (inp165) */
      0.0, 0.402440, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 166 (inp166) */
      0.0, 0.113820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 167 (inp167) */
      0.0, 0.840460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 168 (inp168) */
      0.0, 0.464490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 169 (inp169) */
      0.0, 0.469230, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 170 (inp170) */
      0.0, -0.420750, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 171 (inp171) */
      0.0, -0.516930, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 172 (inp172) */
      0.0, -0.690500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 173 (inp173) */
      0.0, 0.264500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 174 (inp174) */
      0.0, 0.848980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 175 (inp175) */
      0.0, -0.573050, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 176 (inp176) */
      0.0, -0.834690, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 177 (inp177) */
      0.0, -0.782540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 178 (inp178) */
      0.0, -0.269480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 179 (inp179) */
      0.0, 0.325870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 180 (inp180) */
      0.0, -0.177590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 181 (inp181) */
      0.0, -0.578280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 182 (inp182) */
      0.0, -0.341460, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 183 (inp183) */
      0.0, -0.036410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 184 (inp184) */
      0.0, -0.316590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 185 (inp185) */
      0.0, -0.577260, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 186 (inp186) */
      0.0, 0.544670, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 187 (inp187) */
      0.0, 0.733210, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 188 (inp188) */
      0.0, -0.127820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 189 (inp189) */
      0.0, 0.539480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 190 (inp190) */
      0.0, -0.693510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 191 (inp191) */
      0.0, 0.768120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 192 (inp192) */
      0.0, -0.198560, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 193 (inp193) */
      0.0, -0.908470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 194 (inp194) */
      0.0, 0.022760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 195 (inp195) */
      0.0, -0.864500, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 196 (inp196) */
      0.0, 0.482450, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 197 (inp197) */
      0.0, -0.461220, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 198 (inp198) */
      0.0, 0.807320, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 199 (inp199) */
      0.0, -0.589570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 200 (inp200) */
      0.0, -0.601520, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 201 (inp201) */
      0.0, -0.558640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 202 (inp202) */
      0.0, -0.608880, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 203 (inp203) */
      0.0, 0.421540, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 204 (inp204) */
      0.0, 0.233000, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 205 (inp205) */
      0.0, 0.593980, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 206 (inp206) */
      0.0, 0.495080, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 207 (inp207) */
      0.0, 0.322790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 208 (inp208) */
      0.0, -0.303730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 209 (inp209) */
      0.0, -0.072870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 210 (inp210) */
      0.0, -0.597770, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 211 (inp211) */
      0.0, -0.553120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 212 (inp212) */
      0.0, -0.973040, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 213 (inp213) */
      0.0, -0.483550, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 214 (inp214) */
      0.0, 0.827100, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 215 (inp215) */
      0.0, 0.895970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 216 (inp216) */
      0.0, -0.800620, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 217 (inp217) */
      0.0, -0.015310, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 218 (inp218) */
      0.0, -0.041950, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 219 (inp219) */
      0.0, 0.508660, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 220 (inp220) */
      0.0, 0.524480, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 221 (inp221) */
      0.0, -0.125790, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 222 (inp222) */
      0.0, -0.767510, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 223 (inp223) */
      0.0, 0.908760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 224 (inp224) */
      0.0, -0.876590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 225 (inp225) */
      0.0, 0.333240, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 226 (inp226) */
      0.0, -0.591760, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 227 (inp227) */
      0.0, 0.711730, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 228 (inp228) */
      0.0, -0.053860, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 229 (inp229) */
      0.0, -0.710650, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 230 (inp230) */
      0.0, -0.678400, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 231 (inp231) */
      0.0, -0.222820, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 232 (inp232) */
      0.0, 0.720600, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 233 (inp233) */
      0.0, -0.261870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 234 (inp234) */
      0.0, 0.474970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 235 (inp235) */
      0.0, -0.491850, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 236 (inp236) */
      0.0, -0.091590, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 237 (inp237) */
      0.0, -0.115640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 238 (inp238) */
      0.0, -0.534140, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 239 (inp239) */
      0.0, 0.685800, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 240 (inp240) */
      0.0, 0.714990, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 241 (inp241) */
      0.0, 0.633970, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 242 (inp242) */
      0.0, 0.043430, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 243 (inp243) */
      0.0, 0.987250, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 244 (inp244) */
      0.0, 0.099870, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 245 (inp245) */
      0.0, 0.815350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 246 (inp246) */
      0.0, -0.861630, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 247 (inp247) */
      0.0, 0.177340, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 248 (inp248) */
      0.0, -0.950570, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 249 (inp249) */
      0.0, 0.943530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 250 (inp250) */
      0.0, 0.031380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 251 (inp251) */
      0.0, -0.274370, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 252 (inp252) */
      0.0, 0.941070, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 253 (inp253) */
      0.0, 0.234280, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 254 (inp254) */
      0.0, -0.526120, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 255 (inp255) */
      0.0, 0.227710, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 256 (inp256) */
      0.0, -0.675530, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 257 (inp257) */
      0.0, -0.199300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 258 (inp258) */
      0.0, 0.213640, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 259 (inp259) */
      0.0, -0.823360, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 260 (inp260) */
      0.0, 0.892150, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 261 (inp261) */
      0.0, 0.864380, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 262 (inp262) */
      0.0, -0.737350, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 263 (inp263) */
      0.0, -0.777410, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 264 (inp264) */
      0.0, 0.674490, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 265 (inp265) */
      0.0, -0.303420, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 266 (inp266) */
      0.0, -0.773300, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 267 (inp267) */
      0.0, -0.313840, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 268 (inp268) */
      0.0, -0.218470, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 269 (inp269) */
      0.0, -0.348110, 0,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 270 (hid11) */
      0.0, -1.019790, 299,
       &Sources[0] ,
       &Weights[0] ,
      },
    { /* unit 271 (hid12) */
      0.0, -0.021500, 299,
       &Sources[299] ,
       &Weights[299] ,
      },
    { /* unit 272 (hid13) */
      0.0, 0.318300, 299,
       &Sources[598] ,
       &Weights[598] ,
      },
    { /* unit 273 (hid14) */
      0.0, 0.686240, 299,
       &Sources[897] ,
       &Weights[897] ,
      },
    { /* unit 274 (hid15) */
      0.0, -0.856120, 299,
       &Sources[1196] ,
       &Weights[1196] ,
      },
    { /* unit 275 (hid16) */
      0.0, -0.278410, 299,
       &Sources[1495] ,
       &Weights[1495] ,
      },
    { /* unit 276 (hid17) */
      0.0, -0.212350, 299,
       &Sources[1794] ,
       &Weights[1794] ,
      },
    { /* unit 277 (hid18) */
      0.0, 0.834470, 299,
       &Sources[2093] ,
       &Weights[2093] ,
      },
    { /* unit 278 (hid19) */
      0.0, 0.654980, 299,
       &Sources[2392] ,
       &Weights[2392] ,
      },
    { /* unit 279 (hid110) */
      0.0, -0.035870, 299,
       &Sources[2691] ,
       &Weights[2691] ,
      },
    { /* unit 280 (hid111) */
      0.0, 0.582510, 299,
       &Sources[2990] ,
       &Weights[2990] ,
      },
    { /* unit 281 (hid112) */
      0.0, 0.632600, 299,
       &Sources[3289] ,
       &Weights[3289] ,
      },
    { /* unit 282 (hid113) */
      0.0, -0.305560, 299,
       &Sources[3588] ,
       &Weights[3588] ,
      },
    { /* unit 283 (hid114) */
      0.0, 0.395580, 299,
       &Sources[3887] ,
       &Weights[3887] ,
      },
    { /* unit 284 (hid115) */
      0.0, -0.837750, 299,
       &Sources[4186] ,
       &Weights[4186] ,
      },
    { /* unit 285 (hid116) */
      0.0, 0.694480, 299,
       &Sources[4485] ,
       &Weights[4485] ,
      },
    { /* unit 286 (hid117) */
      0.0, -0.862670, 299,
       &Sources[4784] ,
       &Weights[4784] ,
      },
    { /* unit 287 (hid118) */
      0.0, -0.064950, 299,
       &Sources[5083] ,
       &Weights[5083] ,
      },
    { /* unit 288 (hid119) */
      0.0, 0.626110, 299,
       &Sources[5382] ,
       &Weights[5382] ,
      },
    { /* unit 289 (hid120) */
      0.0, -0.897310, 299,
       &Sources[5681] ,
       &Weights[5681] ,
      },
    { /* unit 290 (hid121) */
      0.0, -0.473710, 299,
       &Sources[5980] ,
       &Weights[5980] ,
      },
    { /* unit 291 (hid122) */
      0.0, 0.200270, 299,
       &Sources[6279] ,
       &Weights[6279] ,
      },
    { /* unit 292 (hid123) */
      0.0, 1.393250, 299,
       &Sources[6578] ,
       &Weights[6578] ,
      },
    { /* unit 293 (hid124) */
      0.0, -0.627700, 299,
       &Sources[6877] ,
       &Weights[6877] ,
      },
    { /* unit 294 (hid125) */
      0.0, 0.369440, 299,
       &Sources[7176] ,
       &Weights[7176] ,
      },
    { /* unit 295 (hid126) */
      0.0, -0.344390, 299,
       &Sources[7475] ,
       &Weights[7475] ,
      },
    { /* unit 296 (hid127) */
      0.0, -0.769280, 299,
       &Sources[7774] ,
       &Weights[7774] ,
      },
    { /* unit 297 (hid128) */
      0.0, 0.628600, 299,
       &Sources[8073] ,
       &Weights[8073] ,
      },
    { /* unit 298 (hid129) */
      0.0, -0.778910, 299,
       &Sources[8372] ,
       &Weights[8372] ,
      },
    { /* unit 299 (hid130) */
      0.0, 0.858700, 299,
       &Sources[8671] ,
       &Weights[8671] ,
      },
    { /* unit 300 (hid21) */
      0.0, -0.732000, 60,
       &Sources[8970] ,
       &Weights[8970] ,
      },
    { /* unit 301 (hid22) */
      0.0, -0.732350, 60,
       &Sources[9030] ,
       &Weights[9030] ,
      },
    { /* unit 302 (hid23) */
      0.0, -0.250890, 60,
       &Sources[9090] ,
       &Weights[9090] ,
      },
    { /* unit 303 (hid24) */
      0.0, -0.491360, 60,
       &Sources[9150] ,
       &Weights[9150] ,
      },
    { /* unit 304 (hid25) */
      0.0, -1.444360, 60,
       &Sources[9210] ,
       &Weights[9210] ,
      },
    { /* unit 305 (hid26) */
      0.0, -0.781680, 60,
       &Sources[9270] ,
       &Weights[9270] ,
      },
    { /* unit 306 (hid27) */
      0.0, 39.076550, 60,
       &Sources[9330] ,
       &Weights[9330] ,
      },
    { /* unit 307 (hid28) */
      0.0, -0.352700, 60,
       &Sources[9390] ,
       &Weights[9390] ,
      },
    { /* unit 308 (hid29) */
      0.0, 0.035440, 60,
       &Sources[9450] ,
       &Weights[9450] ,
      },
    { /* unit 309 (hid210) */
      0.0, -1.027040, 60,
       &Sources[9510] ,
       &Weights[9510] ,
      },
    { /* unit 310 (hid211) */
      0.0, 0.683500, 60,
       &Sources[9570] ,
       &Weights[9570] ,
      },
    { /* unit 311 (hid212) */
      0.0, 0.827610, 60,
       &Sources[9630] ,
       &Weights[9630] ,
      },
    { /* unit 312 (hid213) */
      0.0, 0.992500, 60,
       &Sources[9690] ,
       &Weights[9690] ,
      },
    { /* unit 313 (hid214) */
      0.0, 0.151290, 60,
       &Sources[9750] ,
       &Weights[9750] ,
      },
    { /* unit 314 (hid215) */
      0.0, -0.928390, 60,
       &Sources[9810] ,
       &Weights[9810] ,
      },
    { /* unit 315 (hid216) */
      0.0, 0.008970, 60,
       &Sources[9870] ,
       &Weights[9870] ,
      },
    { /* unit 316 (hid217) */
      0.0, -1.034600, 60,
       &Sources[9930] ,
       &Weights[9930] ,
      },
    { /* unit 317 (hid218) */
      0.0, -0.657190, 60,
       &Sources[9990] ,
       &Weights[9990] ,
      },
    { /* unit 318 (hid219) */
      0.0, 0.397480, 60,
       &Sources[10050] ,
       &Weights[10050] ,
      },
    { /* unit 319 (hid220) */
      0.0, -0.245000, 60,
       &Sources[10110] ,
       &Weights[10110] ,
      },
    { /* unit 320 (hid221) */
      0.0, 0.011020, 60,
       &Sources[10170] ,
       &Weights[10170] ,
      },
    { /* unit 321 (hid222) */
      0.0, 0.895980, 60,
       &Sources[10230] ,
       &Weights[10230] ,
      },
    { /* unit 322 (hid223) */
      0.0, 1.116940, 60,
       &Sources[10290] ,
       &Weights[10290] ,
      },
    { /* unit 323 (hid224) */
      0.0, 0.716800, 60,
       &Sources[10350] ,
       &Weights[10350] ,
      },
    { /* unit 324 (hid225) */
      0.0, 0.622050, 60,
       &Sources[10410] ,
       &Weights[10410] ,
      },
    { /* unit 325 (hid226) */
      0.0, -0.473320, 60,
       &Sources[10470] ,
       &Weights[10470] ,
      },
    { /* unit 326 (hid227) */
      0.0, -0.897960, 60,
       &Sources[10530] ,
       &Weights[10530] ,
      },
    { /* unit 327 (hid228) */
      0.0, -0.983330, 60,
       &Sources[10590] ,
       &Weights[10590] ,
      },
    { /* unit 328 (hid229) */
      0.0, -0.156320, 60,
       &Sources[10650] ,
       &Weights[10650] ,
      },
    { /* unit 329 (hid230) */
      0.0, -0.929500, 60,
       &Sources[10710] ,
       &Weights[10710] ,
      },
    { /* unit 330 (out1) */
      0.0, 0.679270, 30,
       &Sources[10770] ,
       &Weights[10770] ,
      },
    { /* unit 331 (out2) */
      0.0, 0.017290, 30,
       &Sources[10800] ,
       &Weights[10800] ,
      },
    { /* unit 332 (out3) */
      0.0, 0.404350, 30,
       &Sources[10830] ,
       &Weights[10830] ,
      },
    { /* unit 333 (out4) */
      0.0, -0.627130, 30,
       &Sources[10860] ,
       &Weights[10860] ,
      },
    { /* unit 334 (out5) */
      0.0, -0.850810, 30,
       &Sources[10890] ,
       &Weights[10890] ,
      },
    { /* unit 335 (out6) */
      0.0, 0.692140, 30,
       &Sources[10920] ,
       &Weights[10920] ,
      },
    { /* unit 336 (out7) */
      0.0, 0.365850, 30,
       &Sources[10950] ,
       &Weights[10950] ,
      },
    { /* unit 337 (out8) */
      0.0, -0.505600, 30,
       &Sources[10980] ,
       &Weights[10980] ,
      },
    { /* unit 338 (out9) */
      0.0, -0.405980, 30,
       &Sources[11010] ,
       &Weights[11010] ,
      },
    { /* unit 339 (out10) */
      0.0, -0.839640, 30,
       &Sources[11040] ,
       &Weights[11040] ,
      },
    { /* unit 340 (out11) */
      0.0, 0.459400, 30,
       &Sources[11070] ,
       &Weights[11070] ,
      },
    { /* unit 341 (out12) */
      0.0, 0.464250, 30,
       &Sources[11100] ,
       &Weights[11100] ,
      },
    { /* unit 342 (out13) */
      0.0, -0.420010, 30,
       &Sources[11130] ,
       &Weights[11130] ,
      },
    { /* unit 343 (out14) */
      0.0, -0.360070, 30,
       &Sources[11160] ,
       &Weights[11160] ,
      },
    { /* unit 344 (out15) */
      0.0, 0.740450, 30,
       &Sources[11190] ,
       &Weights[11190] ,
      },
    { /* unit 345 (out16) */
      0.0, 0.428830, 30,
       &Sources[11220] ,
       &Weights[11220] ,
      },
    { /* unit 346 (out17) */
      0.0, 0.333880, 30,
       &Sources[11250] ,
       &Weights[11250] ,
      },
    { /* unit 347 (out18) */
      0.0, 0.711800, 30,
       &Sources[11280] ,
       &Weights[11280] ,
      },
    { /* unit 348 (out19) */
      0.0, 0.416880, 30,
       &Sources[11310] ,
       &Weights[11310] ,
      },
    { /* unit 349 (out20) */
      0.0, -0.113190, 30,
       &Sources[11340] ,
       &Weights[11340] ,
      },
    { /* unit 350 (con11) */
0.35189, 0.500000, 2,
       &Sources[11370] ,
       &Weights[11370] ,
      },
    { /* unit 351 (con12) */
0.09046, 0.500000, 2,
       &Sources[11372] ,
       &Weights[11372] ,
      },
    { /* unit 352 (con13) */
0.32955, 0.500000, 2,
       &Sources[11374] ,
       &Weights[11374] ,
      },
    { /* unit 353 (con14) */
1.31354, 0.500000, 2,
       &Sources[11376] ,
       &Weights[11376] ,
      },
    { /* unit 354 (con15) */
0.32243, 0.500000, 2,
       &Sources[11378] ,
       &Weights[11378] ,
      },
    { /* unit 355 (con16) */
1.33762, 0.500000, 2,
       &Sources[11380] ,
       &Weights[11380] ,
      },
    { /* unit 356 (con17) */
1.38992, 0.500000, 2,
       &Sources[11382] ,
       &Weights[11382] ,
      },
    { /* unit 357 (con18) */
1.09839, 0.500000, 2,
       &Sources[11384] ,
       &Weights[11384] ,
      },
    { /* unit 358 (con19) */
1.41108, 0.500000, 2,
       &Sources[11386] ,
       &Weights[11386] ,
      },
    { /* unit 359 (con110) */
0.11682, 0.500000, 2,
       &Sources[11388] ,
       &Weights[11388] ,
      },
    { /* unit 360 (con111) */
0.41963, 0.500000, 2,
       &Sources[11390] ,
       &Weights[11390] ,
      },
    { /* unit 361 (con112) */
1.40640, 0.500000, 2,
       &Sources[11392] ,
       &Weights[11392] ,
      },
    { /* unit 362 (con113) */
0.02011, 0.500000, 2,
       &Sources[11394] ,
       &Weights[11394] ,
      },
    { /* unit 363 (con114) */
0.71264, 0.500000, 2,
       &Sources[11396] ,
       &Weights[11396] ,
      },
    { /* unit 364 (con115) */
0.00000, 0.500000, 2,
       &Sources[11398] ,
       &Weights[11398] ,
      },
    { /* unit 365 (con116) */
1.12203, 0.500000, 2,
       &Sources[11400] ,
       &Weights[11400] ,
      },
    { /* unit 366 (con117) */
0.10401, 0.500000, 2,
       &Sources[11402] ,
       &Weights[11402] ,
      },
    { /* unit 367 (con118) */
0.11397, 0.500000, 2,
       &Sources[11404] ,
       &Weights[11404] ,
      },
    { /* unit 368 (con119) */
0.90593, 0.500000, 2,
       &Sources[11406] ,
       &Weights[11406] ,
      },
    { /* unit 369 (con120) */
0.00623, 0.500000, 2,
       &Sources[11408] ,
       &Weights[11408] ,
      },
    { /* unit 370 (con121) */
0.00018, 0.500000, 2,
       &Sources[11410] ,
       &Weights[11410] ,
      },
    { /* unit 371 (con122) */
1.18169, 0.500000, 2,
       &Sources[11412] ,
       &Weights[11412] ,
      },
    { /* unit 372 (con123) */
1.33803, 0.500000, 2,
       &Sources[11414] ,
       &Weights[11414] ,
      },
    { /* unit 373 (con124) */
0.26442, 0.500000, 2,
       &Sources[11416] ,
       &Weights[11416] ,
      },
    { /* unit 374 (con125) */
1.42774, 0.500000, 2,
       &Sources[11418] ,
       &Weights[11418] ,
      },
    { /* unit 375 (con126) */
1.33722, 0.500000, 2,
       &Sources[11420] ,
       &Weights[11420] ,
      },
    { /* unit 376 (con127) */
0.12223, 0.500000, 2,
       &Sources[11422] ,
       &Weights[11422] ,
      },
    { /* unit 377 (con128) */
1.12672, 0.500000, 2,
       &Sources[11424] ,
       &Weights[11424] ,
      },
    { /* unit 378 (con129) */
0.29980, 0.500000, 2,
       &Sources[11426] ,
       &Weights[11426] ,
      },
    { /* unit 379 (con130) */
1.42852, 0.500000, 2,
       &Sources[11428] ,
       &Weights[11428] ,
      },
    { /* unit 380 (con21) */
1.04908, 0.500000, 2,
       &Sources[11430] ,
       &Weights[11430] ,
      },
    { /* unit 381 (con22) */
0.10249, 0.500000, 2,
       &Sources[11432] ,
       &Weights[11432] ,
      },
    { /* unit 382 (con23) */
1.26727, 0.500000, 2,
       &Sources[11434] ,
       &Weights[11434] ,
      },
    { /* unit 383 (con24) */
0.15090, 0.500000, 2,
       &Sources[11436] ,
       &Weights[11436] ,
      },
    { /* unit 384 (con25) */
0.00009, 0.500000, 2,
       &Sources[11438] ,
       &Weights[11438] ,
      },
    { /* unit 385 (con26) */
0.01237, 0.500000, 2,
       &Sources[11440] ,
       &Weights[11440] ,
      },
    { /* unit 386 (con27) */
1.42857, 0.500000, 2,
       &Sources[11442] ,
       &Weights[11442] ,
      },
    { /* unit 387 (con28) */
0.00009, 0.500000, 2,
       &Sources[11444] ,
       &Weights[11444] ,
      },
    { /* unit 388 (con29) */
0.00001, 0.500000, 2,
       &Sources[11446] ,
       &Weights[11446] ,
      },
    { /* unit 389 (con210) */
0.00458, 0.500000, 2,
       &Sources[11448] ,
       &Weights[11448] ,
      },
    { /* unit 390 (con211) */
1.41760, 0.500000, 2,
       &Sources[11450] ,
       &Weights[11450] ,
      },
    { /* unit 391 (con212) */
0.00108, 0.500000, 2,
       &Sources[11452] ,
       &Weights[11452] ,
      },
    { /* unit 392 (con213) */
0.95464, 0.500000, 2,
       &Sources[11454] ,
       &Weights[11454] ,
      },
    { /* unit 393 (con214) */
1.42448, 0.500000, 2,
       &Sources[11456] ,
       &Weights[11456] ,
      },
    { /* unit 394 (con215) */
0.50629, 0.500000, 2,
       &Sources[11458] ,
       &Weights[11458] ,
      },
    { /* unit 395 (con216) */
0.27965, 0.500000, 2,
       &Sources[11460] ,
       &Weights[11460] ,
      },
    { /* unit 396 (con217) */
0.10393, 0.500000, 2,
       &Sources[11462] ,
       &Weights[11462] ,
      },
    { /* unit 397 (con218) */
0.12234, 0.500000, 2,
       &Sources[11464] ,
       &Weights[11464] ,
      },
    { /* unit 398 (con219) */
0.02425, 0.500000, 2,
       &Sources[11466] ,
       &Weights[11466] ,
      },
    { /* unit 399 (con220) */
1.42003, 0.500000, 2,
       &Sources[11468] ,
       &Weights[11468] ,
      },
    { /* unit 400 (con221) */
1.42352, 0.500000, 2,
       &Sources[11470] ,
       &Weights[11470] ,
      },
    { /* unit 401 (con222) */
1.42856, 0.500000, 2,
       &Sources[11472] ,
       &Weights[11472] ,
      },
    { /* unit 402 (con223) */
1.31282, 0.500000, 2,
       &Sources[11474] ,
       &Weights[11474] ,
      },
    { /* unit 403 (con224) */
0.00012, 0.500000, 2,
       &Sources[11476] ,
       &Weights[11476] ,
      },
    { /* unit 404 (con225) */
0.29151, 0.500000, 2,
       &Sources[11478] ,
       &Weights[11478] ,
      },
    { /* unit 405 (con226) */
0.24524, 0.500000, 2,
       &Sources[11480] ,
       &Weights[11480] ,
      },
    { /* unit 406 (con227) */
0.00000, 0.500000, 2,
       &Sources[11482] ,
       &Weights[11482] ,
      },
    { /* unit 407 (con228) */
0.00004, 0.500000, 2,
       &Sources[11484] ,
       &Weights[11484] ,
      },
    { /* unit 408 (con229) */
1.40730, 0.500000, 2,
       &Sources[11486] ,
       &Weights[11486] ,
      },
    { /* unit 409 (con230) */
0.01778, 0.500000, 2,
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
